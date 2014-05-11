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
    HIDE_IDLE = 306,
    HIDE_IDLE_FROM_OPERS = 307,
    HIDE_SERVER_IPS = 308,
    HIDE_SERVERS = 309,
    HIDE_SERVICES = 310,
    HIDE_SPOOF_IPS = 311,
    HOST = 312,
    HUB = 313,
    HUB_MASK = 314,
    IGNORE_BOGUS_TS = 315,
    INVISIBLE_ON_CONNECT = 316,
    IP = 317,
    IRCD_AUTH = 318,
    IRCD_FLAGS = 319,
    IRCD_SID = 320,
    JOIN_FLOOD_COUNT = 321,
    JOIN_FLOOD_TIME = 322,
    KILL = 323,
    KILL_CHASE_TIME_LIMIT = 324,
    KLINE = 325,
    KLINE_EXEMPT = 326,
    KNOCK_DELAY = 327,
    KNOCK_DELAY_CHANNEL = 328,
    LEAF_MASK = 329,
    LINKS_DELAY = 330,
    LISTEN = 331,
    MASK = 332,
    MAX_ACCEPT = 333,
    MAX_BANS = 334,
    MAX_CHANS_PER_OPER = 335,
    MAX_CHANS_PER_USER = 336,
    MAX_GLOBAL = 337,
    MAX_IDENT = 338,
    MAX_IDLE = 339,
    MAX_LOCAL = 340,
    MAX_NICK_CHANGES = 341,
    MAX_NICK_LENGTH = 342,
    MAX_NICK_TIME = 343,
    MAX_NUMBER = 344,
    MAX_TARGETS = 345,
    MAX_TOPIC_LENGTH = 346,
    MAX_WATCH = 347,
    MIN_IDLE = 348,
    MIN_NONWILDCARD = 349,
    MIN_NONWILDCARD_SIMPLE = 350,
    MODULE = 351,
    MODULES = 352,
    MOTD = 353,
    NAME = 354,
    NEED_IDENT = 355,
    NEED_PASSWORD = 356,
    NETWORK_DESC = 357,
    NETWORK_NAME = 358,
    NICK = 359,
    NO_CREATE_ON_SPLIT = 360,
    NO_JOIN_ON_SPLIT = 361,
    NO_OPER_FLOOD = 362,
    NO_TILDE = 363,
    NUMBER = 364,
    NUMBER_PER_CIDR = 365,
    NUMBER_PER_IP = 366,
    OPER_ONLY_UMODES = 367,
    OPER_PASS_RESV = 368,
    OPER_UMODES = 369,
    OPERATOR = 370,
    OPERS_BYPASS_CALLERID = 371,
    PACE_WAIT = 372,
    PACE_WAIT_SIMPLE = 373,
    PASSWORD = 374,
    PATH = 375,
    PING_COOKIE = 376,
    PING_TIME = 377,
    PORT = 378,
    QSTRING = 379,
    RANDOM_IDLE = 380,
    REASON = 381,
    REDIRPORT = 382,
    REDIRSERV = 383,
    REHASH = 384,
    REMOTE = 385,
    REMOTEBAN = 386,
    RESV = 387,
    RESV_EXEMPT = 388,
    RSA_PRIVATE_KEY_FILE = 389,
    RSA_PUBLIC_KEY_FILE = 390,
    SECONDS = 391,
    MINUTES = 392,
    HOURS = 393,
    DAYS = 394,
    WEEKS = 395,
    MONTHS = 396,
    YEARS = 397,
    SEND_PASSWORD = 398,
    SENDQ = 399,
    SERVERHIDE = 400,
    SERVERINFO = 401,
    SHORT_MOTD = 402,
    SPOOF = 403,
    SPOOF_NOTICE = 404,
    SQUIT = 405,
    SSL_CERTIFICATE_FILE = 406,
    SSL_CERTIFICATE_FINGERPRINT = 407,
    SSL_CONNECTION_REQUIRED = 408,
    SSL_DH_PARAM_FILE = 409,
    STATS_E_DISABLED = 410,
    STATS_I_OPER_ONLY = 411,
    STATS_K_OPER_ONLY = 412,
    STATS_O_OPER_ONLY = 413,
    STATS_P_OPER_ONLY = 414,
    STATS_U_OPER_ONLY = 415,
    T_ALL = 416,
    T_BOTS = 417,
    T_CALLERID = 418,
    T_CCONN = 419,
    T_CLUSTER = 420,
    T_DEAF = 421,
    T_DEBUG = 422,
    T_DLINE = 423,
    T_EXTERNAL = 424,
    T_FARCONNECT = 425,
    T_FILE = 426,
    T_FULL = 427,
    T_GLOBOPS = 428,
    T_INVISIBLE = 429,
    T_IPV4 = 430,
    T_IPV6 = 431,
    T_LOCOPS = 432,
    T_LOG = 433,
    T_MAX_CLIENTS = 434,
    T_NCHANGE = 435,
    T_NONONREG = 436,
    T_OPERWALL = 437,
    T_RECVQ = 438,
    T_REJ = 439,
    T_RESTART = 440,
    T_SERVER = 441,
    T_SERVICE = 442,
    T_SERVICES_NAME = 443,
    T_SERVNOTICE = 444,
    T_SET = 445,
    T_SHARED = 446,
    T_SIZE = 447,
    T_SKILL = 448,
    T_SOFTCALLERID = 449,
    T_SPY = 450,
    T_SSL = 451,
    T_SSL_CIPHER_LIST = 452,
    T_SSL_CLIENT_METHOD = 453,
    T_SSL_SERVER_METHOD = 454,
    T_SSLV3 = 455,
    T_TLSV1 = 456,
    T_UMODES = 457,
    T_UNAUTH = 458,
    T_UNDLINE = 459,
    T_UNLIMITED = 460,
    T_UNRESV = 461,
    T_UNXLINE = 462,
    T_WALLOP = 463,
    T_WALLOPS = 464,
    T_WEBIRC = 465,
    TBOOL = 466,
    THROTTLE_TIME = 467,
    TKLINE_EXPIRE_NOTICES = 468,
    TMASKED = 469,
    TRUE_NO_OPER_FLOOD = 470,
    TS_MAX_DELTA = 471,
    TS_WARN_DELTA = 472,
    TWODOTS = 473,
    TYPE = 474,
    UNKLINE = 475,
    USE_EGD = 476,
    USE_LOGGING = 477,
    USER = 478,
    VHOST = 479,
    VHOST6 = 480,
    WARN_NO_CONNECT_BLOCK = 481,
    XLINE = 482
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
#define HIDE_IDLE 306
#define HIDE_IDLE_FROM_OPERS 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SERVICES 310
#define HIDE_SPOOF_IPS 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define IP 317
#define IRCD_AUTH 318
#define IRCD_FLAGS 319
#define IRCD_SID 320
#define JOIN_FLOOD_COUNT 321
#define JOIN_FLOOD_TIME 322
#define KILL 323
#define KILL_CHASE_TIME_LIMIT 324
#define KLINE 325
#define KLINE_EXEMPT 326
#define KNOCK_DELAY 327
#define KNOCK_DELAY_CHANNEL 328
#define LEAF_MASK 329
#define LINKS_DELAY 330
#define LISTEN 331
#define MASK 332
#define MAX_ACCEPT 333
#define MAX_BANS 334
#define MAX_CHANS_PER_OPER 335
#define MAX_CHANS_PER_USER 336
#define MAX_GLOBAL 337
#define MAX_IDENT 338
#define MAX_IDLE 339
#define MAX_LOCAL 340
#define MAX_NICK_CHANGES 341
#define MAX_NICK_LENGTH 342
#define MAX_NICK_TIME 343
#define MAX_NUMBER 344
#define MAX_TARGETS 345
#define MAX_TOPIC_LENGTH 346
#define MAX_WATCH 347
#define MIN_IDLE 348
#define MIN_NONWILDCARD 349
#define MIN_NONWILDCARD_SIMPLE 350
#define MODULE 351
#define MODULES 352
#define MOTD 353
#define NAME 354
#define NEED_IDENT 355
#define NEED_PASSWORD 356
#define NETWORK_DESC 357
#define NETWORK_NAME 358
#define NICK 359
#define NO_CREATE_ON_SPLIT 360
#define NO_JOIN_ON_SPLIT 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_CIDR 365
#define NUMBER_PER_IP 366
#define OPER_ONLY_UMODES 367
#define OPER_PASS_RESV 368
#define OPER_UMODES 369
#define OPERATOR 370
#define OPERS_BYPASS_CALLERID 371
#define PACE_WAIT 372
#define PACE_WAIT_SIMPLE 373
#define PASSWORD 374
#define PATH 375
#define PING_COOKIE 376
#define PING_TIME 377
#define PORT 378
#define QSTRING 379
#define RANDOM_IDLE 380
#define REASON 381
#define REDIRPORT 382
#define REDIRSERV 383
#define REHASH 384
#define REMOTE 385
#define REMOTEBAN 386
#define RESV 387
#define RESV_EXEMPT 388
#define RSA_PRIVATE_KEY_FILE 389
#define RSA_PUBLIC_KEY_FILE 390
#define SECONDS 391
#define MINUTES 392
#define HOURS 393
#define DAYS 394
#define WEEKS 395
#define MONTHS 396
#define YEARS 397
#define SEND_PASSWORD 398
#define SENDQ 399
#define SERVERHIDE 400
#define SERVERINFO 401
#define SHORT_MOTD 402
#define SPOOF 403
#define SPOOF_NOTICE 404
#define SQUIT 405
#define SSL_CERTIFICATE_FILE 406
#define SSL_CERTIFICATE_FINGERPRINT 407
#define SSL_CONNECTION_REQUIRED 408
#define SSL_DH_PARAM_FILE 409
#define STATS_E_DISABLED 410
#define STATS_I_OPER_ONLY 411
#define STATS_K_OPER_ONLY 412
#define STATS_O_OPER_ONLY 413
#define STATS_P_OPER_ONLY 414
#define STATS_U_OPER_ONLY 415
#define T_ALL 416
#define T_BOTS 417
#define T_CALLERID 418
#define T_CCONN 419
#define T_CLUSTER 420
#define T_DEAF 421
#define T_DEBUG 422
#define T_DLINE 423
#define T_EXTERNAL 424
#define T_FARCONNECT 425
#define T_FILE 426
#define T_FULL 427
#define T_GLOBOPS 428
#define T_INVISIBLE 429
#define T_IPV4 430
#define T_IPV6 431
#define T_LOCOPS 432
#define T_LOG 433
#define T_MAX_CLIENTS 434
#define T_NCHANGE 435
#define T_NONONREG 436
#define T_OPERWALL 437
#define T_RECVQ 438
#define T_REJ 439
#define T_RESTART 440
#define T_SERVER 441
#define T_SERVICE 442
#define T_SERVICES_NAME 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_SKILL 448
#define T_SOFTCALLERID 449
#define T_SPY 450
#define T_SSL 451
#define T_SSL_CIPHER_LIST 452
#define T_SSL_CLIENT_METHOD 453
#define T_SSL_SERVER_METHOD 454
#define T_SSLV3 455
#define T_TLSV1 456
#define T_UMODES 457
#define T_UNAUTH 458
#define T_UNDLINE 459
#define T_UNLIMITED 460
#define T_UNRESV 461
#define T_UNXLINE 462
#define T_WALLOP 463
#define T_WALLOPS 464
#define T_WEBIRC 465
#define TBOOL 466
#define THROTTLE_TIME 467
#define TKLINE_EXPIRE_NOTICES 468
#define TMASKED 469
#define TRUE_NO_OPER_FLOOD 470
#define TS_MAX_DELTA 471
#define TS_WARN_DELTA 472
#define TWODOTS 473
#define TYPE 474
#define UNKLINE 475
#define USE_EGD 476
#define USE_LOGGING 477
#define USER 478
#define VHOST 479
#define VHOST6 480
#define WARN_NO_CONNECT_BLOCK 481
#define XLINE 482

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 146 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 683 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 698 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1280

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1290

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   482

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
       2,     2,     2,     2,   232,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   233,   228,
       2,   231,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   230,     2,   229,     2,     2,     2,     2,
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
     225,   226,   227
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   377,   377,   378,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,   402,   403,   407,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   418,   418,   419,
     420,   421,   422,   429,   432,   432,   433,   433,   433,   435,
     441,   448,   450,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   471,   472,   474,   474,   475,   481,   489,   489,
     490,   496,   504,   546,   604,   632,   640,   655,   670,   679,
     693,   702,   730,   760,   785,   807,   829,   838,   840,   840,
     841,   842,   843,   844,   846,   855,   864,   877,   876,   894,
     894,   895,   895,   895,   897,   903,   912,   913,   913,   915,
     915,   916,   918,   925,   925,   938,   939,   941,   941,   942,
     942,   944,   952,   955,   961,   960,   966,   966,   967,   971,
     975,   979,   983,   987,   991,   995,   999,  1010,  1009,  1089,
    1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,  1098,
    1099,  1100,  1102,  1108,  1114,  1120,  1131,  1137,  1143,  1154,
    1161,  1160,  1166,  1166,  1167,  1171,  1175,  1179,  1183,  1187,
    1191,  1195,  1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,
    1231,  1235,  1239,  1243,  1247,  1251,  1258,  1257,  1263,  1263,
    1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,
    1304,  1308,  1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,
    1344,  1348,  1352,  1356,  1367,  1366,  1427,  1427,  1428,  1429,
    1430,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,  1439,
    1439,  1440,  1441,  1442,  1443,  1445,  1451,  1457,  1463,  1469,
    1475,  1481,  1487,  1493,  1499,  1506,  1512,  1518,  1524,  1533,
    1543,  1542,  1548,  1548,  1549,  1553,  1564,  1563,  1570,  1569,
    1574,  1574,  1575,  1579,  1583,  1589,  1589,  1590,  1590,  1590,
    1590,  1590,  1592,  1592,  1594,  1594,  1596,  1610,  1628,  1634,
    1644,  1643,  1685,  1685,  1686,  1687,  1688,  1689,  1690,  1691,
    1692,  1693,  1694,  1696,  1702,  1708,  1714,  1726,  1725,  1731,
    1731,  1732,  1736,  1740,  1744,  1748,  1752,  1756,  1760,  1764,
    1768,  1774,  1788,  1797,  1811,  1810,  1825,  1825,  1826,  1826,
    1826,  1826,  1828,  1834,  1840,  1850,  1852,  1852,  1853,  1853,
    1855,  1871,  1870,  1895,  1895,  1896,  1896,  1896,  1896,  1898,
    1904,  1924,  1923,  1929,  1929,  1930,  1934,  1938,  1942,  1946,
    1950,  1954,  1958,  1962,  1966,  1976,  1975,  1996,  1996,  1997,
    1997,  1997,  1999,  2006,  2005,  2011,  2011,  2012,  2016,  2020,
    2024,  2028,  2032,  2036,  2040,  2044,  2048,  2058,  2057,  2129,
    2129,  2130,  2131,  2132,  2133,  2134,  2135,  2136,  2137,  2138,
    2139,  2140,  2141,  2142,  2143,  2144,  2146,  2152,  2158,  2164,
    2177,  2190,  2196,  2202,  2206,  2215,  2214,  2219,  2219,  2220,
    2224,  2230,  2241,  2247,  2253,  2259,  2275,  2274,  2300,  2300,
    2301,  2301,  2301,  2303,  2323,  2333,  2332,  2359,  2359,  2360,
    2360,  2360,  2362,  2368,  2377,  2379,  2379,  2380,  2380,  2382,
    2400,  2399,  2422,  2422,  2423,  2423,  2423,  2425,  2431,  2440,
    2443,  2443,  2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,
    2452,  2453,  2454,  2455,  2456,  2457,  2458,  2459,  2460,  2461,
    2462,  2463,  2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,
    2472,  2473,  2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,
    2482,  2483,  2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,
    2492,  2493,  2496,  2501,  2507,  2513,  2519,  2525,  2530,  2535,
    2540,  2545,  2550,  2555,  2560,  2565,  2570,  2575,  2580,  2585,
    2590,  2596,  2607,  2612,  2617,  2622,  2627,  2632,  2637,  2640,
    2645,  2648,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,
    2693,  2698,  2703,  2708,  2717,  2726,  2731,  2736,  2742,  2741,
    2746,  2746,  2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,
    2771,  2774,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,
    2801,  2804,  2807,  2810,  2816,  2815,  2820,  2820,  2821,  2824,
    2827,  2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,
    2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,  2886,
    2891,  2896,  2905,  2908,  2908,  2909,  2910,  2911,  2912,  2913,
    2914,  2915,  2916,  2917,  2918,  2919,  2920,  2921,  2923,  2928,
    2933,  2938,  2943,  2948,  2953,  2958,  2963,  2968,  2973,  2978,
    2986,  2989,  2989,  2990,  2991,  2992,  2993,  2994,  2995,  2996,
    2997,  2998,  3000,  3006,  3012,  3018,  3024,  3033,  3047,  3053
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
  "HIDDEN_NAME", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HIDE_SPOOF_IPS", "HOST", "HUB",
  "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL",
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
     475,   476,   477,   478,   479,   480,   481,   482,    59,   125,
     123,    61,    44,    58
};
# endif

#define YYPACT_NINF -861

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-861)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -861,   707,  -861,  -198,  -215,  -167,  -861,  -861,  -861,  -153,
    -861,  -142,  -861,  -861,  -861,  -132,  -861,  -861,  -861,  -130,
    -124,  -861,  -113,   -75,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   367,
     955,   -72,   -65,   -51,    13,   -35,   404,   -33,   -29,   -26,
      26,   -22,     1,    30,   698,   450,    32,    39,    33,    52,
    -189,  -110,    -4,     9,    20,  -861,  -861,  -861,  -861,  -861,
      49,    58,    70,    77,    84,    85,    87,    88,    95,    96,
     100,   102,   277,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   697,   539,    41,  -861,
     109,    18,  -861,  -861,    46,  -861,   110,   116,   120,   122,
     123,   124,   128,   129,   130,   131,   132,   138,   140,   144,
     146,   147,   149,   150,   154,   155,   156,   164,   165,   166,
     167,   169,   170,  -861,   171,  -861,   173,   175,   176,   177,
     181,   186,   187,   188,   191,   197,   199,   201,   210,   212,
     216,   223,   224,   226,   230,   108,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   420,     5,   310,   -37,
     231,   232,    16,  -861,  -861,  -861,    12,   274,    66,  -861,
     238,   239,   240,   246,   247,   249,   250,   254,     6,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,    69,   255,
     256,   257,   258,   260,   262,   270,   272,   273,   276,   278,
     288,   292,   293,   296,   298,   299,     8,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,    67,   111,   300,    28,  -861,
    -861,  -861,   121,  -861,   301,    24,  -861,  -861,    91,  -861,
     114,   174,   266,   211,  -861,   294,   335,    45,   393,   396,
     396,   396,   425,   426,   429,   332,   334,   318,  -861,   326,
     324,   327,   336,  -861,   339,   340,   342,   343,   344,   345,
     346,   348,   350,   351,   352,   354,   159,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,   329,   355,   356,   357,   358,   362,
     363,  -861,   364,   366,   369,   371,   376,   377,   378,   271,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   379,   380,    22,  -861,
    -861,  -861,   441,   338,  -861,  -861,   381,   383,    25,  -861,
    -861,  -861,   407,   396,   396,   411,   506,   412,   515,   502,
     417,   396,   421,   522,   525,   396,   527,   431,   433,   434,
     396,   528,   537,   396,   541,   542,   543,   544,   443,   424,
     447,   428,   452,   396,   396,   454,   455,   465,  -121,  -109,
     466,   468,   470,   560,   396,   474,   475,   396,   396,   477,
     479,   473,  -861,   476,   430,   462,  -861,   463,   471,   478,
     484,   487,    61,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   489,   491,    50,  -861,  -861,  -861,   482,
     492,   495,  -861,   497,  -861,     7,  -861,  -861,  -861,  -861,
    -861,   572,   582,   501,  -861,   511,   503,   507,    10,  -861,
    -861,  -861,   512,   513,   518,  -861,   519,   533,   534,   536,
     538,  -861,   540,   213,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   546,   545,   547,   553,    56,
    -861,  -861,  -861,  -861,   530,   532,   551,   644,   561,   566,
     574,   396,   563,  -861,  -861,   669,   583,   671,   688,   689,
     675,   676,   677,   678,   679,   682,   700,   686,   -30,   -16,
     687,   690,   584,  -861,   585,   594,  -861,   117,  -861,  -861,
    -861,  -861,   604,   599,  -861,   603,   705,   609,  -861,   612,
     611,  -861,   613,    64,  -861,  -861,  -861,  -861,   617,   618,
     622,  -861,   623,   626,   627,   628,   531,   630,   631,   632,
     633,   635,   636,   637,   638,  -861,  -861,   758,   759,   396,
     639,   760,   762,   396,   764,   765,   396,   751,   767,   768,
     396,   769,   769,   651,  -861,  -861,   757,   119,   763,   672,
     766,   771,   653,   772,   773,   777,   775,   779,   782,   785,
     660,  -861,   787,   789,   661,  -861,   663,  -861,   790,   792,
     664,  -861,   665,   693,   695,   696,   701,   702,   706,   708,
     709,   710,   711,   712,   714,   721,   724,   726,   729,   731,
     732,   736,   739,   740,   741,   743,   744,   745,   752,   654,
     753,   738,   754,   770,   774,   776,   778,   780,   783,   784,
     786,   788,   791,   795,   796,   797,   798,   801,   802,   803,
     804,   805,   809,  -861,  -861,   793,   715,   694,   811,   819,
     842,   855,   861,   810,  -861,   862,   863,   812,  -861,  -861,
     864,   866,   761,   882,   813,  -861,   814,   815,  -861,  -861,
     869,   870,   816,  -861,  -861,   871,   794,   808,   872,   873,
     875,   876,   799,   817,   877,   818,  -861,  -861,   879,   883,
     885,   821,  -861,   822,   823,   824,   825,   826,   827,   828,
     829,  -861,   830,   831,   834,   835,   836,   837,   838,   839,
     840,   841,   843,   844,   845,  -861,  -861,  -212,  -861,  -861,
    -861,  -210,  -861,   846,   847,  -861,  -861,   889,   848,   849,
    -861,   850,  -861,   172,   852,  -861,  -861,   891,   851,   893,
     853,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   396,
     396,   396,   396,   396,   396,   396,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   856,   857,   858,   -40,
     859,   860,   865,   867,   868,   874,   878,   880,   881,   884,
     208,   886,   887,  -861,   888,   890,   892,   894,   895,   896,
     897,    -3,   898,   899,   900,   901,   902,   903,   904,  -861,
     905,   906,  -861,  -861,   907,   908,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -204,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -196,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   909,   910,   556,   911,   912,   913,   914,
     915,  -861,   916,   917,  -861,   918,   919,   -39,   800,   650,
    -861,  -861,  -861,  -861,   920,   921,  -861,   922,   923,   510,
     924,   925,   926,   927,   928,   781,   929,  -861,   930,   931,
     932,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,   -30,  -861,   -16,  -861,  -861,   933,
     252,  -861,  -861,   934,   935,   936,  -861,   160,  -861,  -861,
    -861,  -861,  -861,   937,   306,   940,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -191,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,   769,   769,   769,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -184,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,   654,  -861,   738,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -182,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -179,  -861,   938,   882,   941,  -861,  -861,  -861,  -861,  -861,
     939,  -861,  -861,   942,  -861,  -861,  -861,  -861,   943,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -174,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -158,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -156,  -861,
    -861,   946,   -71,   947,   945,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -149,  -861,  -861,
    -861,   -40,  -861,  -861,  -861,  -861,    -3,  -861,  -861,  -861,
     556,  -861,   -39,  -861,  -861,  -861,   953,   959,   960,  -861,
     510,  -861,   781,  -861,   252,   949,   951,   952,   565,  -861,
    -861,   306,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -146,  -861,  -861,  -861,   565,  -861
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   224,   387,   435,     0,
     450,     0,   290,   426,   266,     0,   107,   147,   324,     0,
       0,   365,     0,     0,   341,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   627,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   614,   626,   616,   617,   618,   619,   615,
     620,   621,   622,   623,   624,   625,     0,     0,     0,   448,
       0,     0,   446,   447,     0,   511,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   584,     0,   558,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   461,   508,   510,   502,
     503,   504,   505,   506,   501,   472,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   498,   473,   474,   507,
     476,   481,   482,   477,   479,   478,   492,   493,   480,   483,
     484,   485,   486,   475,   488,   489,   490,   509,   499,   500,
     497,   491,   487,   495,   496,   494,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,   651,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   642,
     643,   644,   645,   646,   649,   647,   648,   650,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    68,    69,
      67,    64,    63,    70,    54,    66,    57,    58,    59,    55,
      65,    60,    61,    62,    56,     0,     0,     0,     0,   118,
     119,   120,     0,   339,     0,     0,   337,   338,     0,   103,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,     0,
       0,     0,     0,   260,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   227,   228,   231,
     233,   234,   235,   236,   237,   238,   239,   240,   229,   230,
     232,   241,   242,   243,     0,     0,     0,     0,     0,     0,
       0,   415,     0,     0,     0,     0,     0,     0,     0,     0,
     390,   391,   392,   393,   394,   395,   396,   398,   397,   400,
     404,   401,   402,   403,   399,   441,     0,     0,     0,   438,
     439,   440,     0,     0,   445,   456,     0,     0,     0,   453,
     454,   455,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   460,     0,     0,     0,   307,     0,     0,     0,
       0,     0,     0,   293,   294,   295,   296,   301,   297,   298,
     299,   300,   432,     0,     0,     0,   429,   430,   431,     0,
       0,     0,   268,     0,   278,     0,   276,   277,   279,   280,
      48,     0,     0,     0,    44,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   196,     0,     0,     0,     0,
       0,   170,     0,     0,   150,   151,   152,   153,   156,   157,
     158,   159,   155,   154,   160,     0,     0,     0,     0,     0,
     327,   328,   329,   330,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   373,     0,   368,   369,
     370,   121,     0,     0,   117,     0,     0,     0,   336,     0,
       0,   351,     0,     0,   344,   345,   346,   347,     0,     0,
       0,    97,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,   612,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   226,   405,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   389,     0,     0,     0,   437,     0,   444,     0,     0,
       0,   452,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,   302,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   292,     0,     0,     0,   428,   281,
       0,     0,     0,     0,     0,   275,     0,     0,    43,   113,
       0,     0,     0,   109,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   331,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,     0,     0,
       0,   640,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,    75,    80,
      81,     0,    79,     0,     0,    51,   371,     0,     0,     0,
     367,     0,   116,     0,     0,   335,   348,     0,     0,     0,
       0,   343,   106,   105,   104,   635,   634,   628,   638,    27,
      27,    27,    27,    27,    27,    27,    29,    28,   639,   629,
     630,   633,   632,   631,   636,   637,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   388,
       0,     0,   436,   449,     0,     0,   451,   524,   528,   543,
     513,   611,   556,   550,   553,   523,   515,   514,   517,   518,
     516,   531,   521,   522,   532,   520,   527,   526,   525,   551,
     512,   609,   610,   547,   594,   588,   605,   589,   590,   591,
     599,   608,   592,   602,   606,   595,   607,   600,   596,   601,
     593,   604,   598,   597,   603,     0,   587,   549,   567,   568,
     562,   580,   563,   564,   565,   574,   583,   566,   577,   581,
     570,   582,   575,   571,   576,   569,   579,   573,   572,   578,
       0,   561,   544,   542,   545,   555,   546,   534,   540,   541,
     538,   539,   535,   536,   537,   554,   557,   519,   548,   530,
     529,   552,   533,     0,     0,     0,     0,     0,     0,     0,
       0,   291,     0,     0,   427,     0,     0,     0,   286,   282,
     285,   267,    49,    50,     0,     0,   108,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
       0,   325,   653,   652,   658,   656,   659,   654,   655,   657,
      88,    96,    87,    94,    95,    86,    90,    89,    83,    82,
      84,    93,    85,    72,     0,    73,     0,    91,    92,     0,
       0,   366,   122,     0,     0,     0,   134,     0,   126,   127,
     129,   128,   340,     0,     0,     0,   342,    30,    31,    32,
      33,    34,    35,    36,   255,   256,   248,   265,   264,     0,
     263,   250,   252,   259,   251,   249,   258,   245,   257,   247,
     246,    37,    37,    37,    39,    38,   253,   254,   410,   413,
     414,   424,   421,   407,   422,   419,   420,     0,   418,   423,
     406,   412,   409,   411,   425,   408,   442,   443,   457,   458,
     585,     0,   559,     0,   305,   306,   315,   312,   317,   313,
     314,   320,   316,   318,   311,   319,     0,   310,   304,   323,
     322,   321,   303,   434,   433,   289,   288,   273,   274,   272,
       0,   271,     0,     0,     0,   114,   115,   169,   165,   216,
     203,   213,   212,   201,   206,   223,   215,   221,   205,   208,
     218,   220,   217,   214,   222,   209,   211,   219,   207,   210,
       0,   199,   162,   164,   166,   167,   168,   179,   180,   174,
     192,   175,   176,   177,   186,   195,   178,   189,   193,   182,
     194,   187,   183,   188,   181,   191,   185,   184,   190,     0,
     173,   163,   334,   332,   333,    74,    78,   372,   377,   383,
     386,   379,   385,   380,   384,   382,   378,   381,     0,   376,
     130,     0,     0,     0,     0,   125,   349,   355,   361,   364,
     357,   363,   358,   362,   360,   356,   359,     0,   354,   350,
     261,     0,    40,    41,    42,   416,     0,   586,   560,   308,
       0,   269,     0,   287,   284,   283,     0,     0,     0,   197,
       0,   171,     0,   374,     0,     0,     0,     0,     0,   124,
     352,     0,   262,   417,   309,   270,   202,   200,   204,   198,
     172,   375,   131,   133,   132,   140,   145,   144,   139,   142,
     146,   143,   138,   141,     0,   137,   353,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -861,  -861,  -861,   -55,  -307,  -860,  -621,  -861,  -861,   854,
    -861,  -861,  -861,  -861,   832,  -861,  -861,  -861,    21,  -861,
      -6,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  1017,  -861,
    -861,  -861,  -861,  -861,  -861,   596,  -861,  -861,  -861,  -861,
     833,  -861,  -861,  -861,  -861,    55,  -861,  -861,  -861,  -861,
    -861,  -188,  -861,  -861,  -861,   586,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -155,  -861,  -861,
    -861,  -147,  -861,  -861,  -861,   944,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -127,  -861,  -861,  -861,  -861,  -861,
    -141,  -861,   620,  -861,  -861,  -861,   -23,  -861,  -861,  -861,
    -861,  -861,   645,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -129,  -861,  -861,  -861,  -861,  -861,  -861,   588,  -861,  -861,
    -861,  -861,  -861,   948,  -861,  -861,  -861,  -861,   580,  -861,
    -861,  -861,  -861,  -861,  -148,  -861,  -861,  -861,   552,  -861,
    -861,  -861,  -861,   -90,  -861,  -861,  -861,   820,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   -66,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   699,  -861,
    -861,  -861,  -861,  -861,   806,  -861,  -861,  -861,  -861,  1060,
    -861,  -861,  -861,  -861,   807,  -861,  -861,  -861,  -861,  1016,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,    79,  -861,  -861,
    -861,    82,  -861,  -861,  -861,  -861,  -861,  1092,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,   950,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   816,   817,  1074,  1075,    26,   222,   223,
     224,   225,    27,   266,   267,   268,   269,   777,   778,   781,
     782,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,    28,    74,    75,    76,
      77,    78,    29,    61,   498,   499,   500,   501,    30,   288,
     289,   290,   291,   292,  1037,  1038,  1039,  1040,  1041,  1213,
    1284,  1285,    31,    62,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   743,  1189,  1190,   524,   737,
    1160,  1161,    32,    51,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   610,  1059,  1060,    33,    59,   484,   722,  1130,
    1131,   485,   486,   487,  1134,   979,   980,   488,   489,    34,
      57,   462,   463,   464,   465,   466,   467,   468,   707,  1116,
    1117,   469,   470,   471,    35,    63,   529,   530,   531,   532,
     533,    36,   295,   296,   297,    37,    69,   583,   584,   585,
     586,   587,   798,  1227,  1228,    38,    66,   567,   568,   569,
     570,   788,  1208,  1209,    39,    52,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   632,  1087,  1088,
     380,   381,   382,   383,   384,    40,    58,   475,   476,   477,
     478,    41,    53,   388,   389,   390,   391,    42,   111,   112,
     113,    43,    55,   398,   399,   400,   401,    44,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   431,   940,   941,   212,   429,
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
     841,   842,   597,   598,   599,  1085,   472,   229,   479,   248,
    1127,   495,  1057,   495,   109,    49,  1023,   219,  1025,   109,
    1024,    70,  1026,   385,  1100,   293,   395,   219,  1101,   286,
      47,    48,  1102,   249,   293,   230,  1103,  1230,   840,   299,
     286,  1231,   385,   231,  1235,    71,  1239,   395,  1236,  1241,
    1240,   472,    72,  1242,  1249,   232,   233,   525,  1250,   234,
     235,   236,   453,    50,   480,   579,   250,   525,   564,   481,
    1251,   482,  1253,   251,  1252,   110,  1254,    54,   454,  1260,
     110,   237,  1287,  1261,   386,  1058,  1288,   496,    56,   496,
     688,   526,   579,   689,   455,   252,   653,   654,    60,   253,
      64,   526,   690,   386,   661,   691,    65,   254,   665,   115,
     255,   256,   220,   670,   116,   117,   673,    67,   564,    73,
     118,   300,   220,   294,   396,   456,   683,   684,   119,   120,
     483,   473,   294,   527,  1256,   121,   221,   696,   122,   123,
     699,   700,   257,   527,   124,   396,   221,  1128,   387,   125,
     126,   397,   127,   128,   129,    68,   130,  1129,   106,   258,
     319,  1033,   259,   580,   131,   107,   565,   387,   132,   133,
     775,   776,   397,  1033,   320,   321,   473,   134,   322,   108,
     457,   497,   528,   497,   779,   780,   135,   260,   458,   459,
     580,   490,   528,  1086,   136,   114,   137,   216,   138,  -123,
     139,   217,   140,   141,   218,   261,   262,   263,   226,   460,
    -123,  1232,  1233,  1234,   502,   142,   565,  1071,  1072,  1073,
     143,   144,   145,   323,   146,   147,   148,   301,   474,   149,
     503,   227,   264,   265,   760,   542,   724,   562,   588,   732,
     302,   324,   325,   326,   327,   493,   504,   393,   328,   303,
     287,   644,   329,   577,   650,   150,   594,   573,   330,  1034,
     228,   287,   285,   151,   152,   153,   154,   155,   156,   331,
     332,  1034,   354,   474,   355,   502,   356,   505,    79,   717,
     305,   333,   298,   581,   461,   751,   566,   582,   357,   306,
     713,   503,   575,   800,   845,   846,   157,   544,   589,    80,
      81,   307,   828,   334,   358,    82,   832,   504,   308,   835,
     581,   479,   506,   839,   582,   309,   310,   840,   311,   312,
     158,   159,  1198,   160,   161,   162,   313,   314,   359,   163,
     360,   315,   507,   316,   164,   361,   566,   451,   505,   571,
     392,   402,   335,    83,    84,   362,   789,   403,   508,    85,
      86,   404,  1035,   405,   406,   407,    87,    88,    89,   408,
     409,   410,   411,   412,  1035,   509,   510,   480,    70,   413,
     363,   414,   481,   506,   482,   415,  1217,   416,   417,  1036,
     418,   419,    90,    91,  1199,   420,   421,   422,   623,  1214,
     590,  1036,    71,   507,   364,   423,   424,   425,   426,    72,
     427,   428,   430,   592,   432,   115,   433,   434,   435,   508,
     116,   117,   436,  1200,   365,   511,   118,   437,   438,   439,
    1201,   453,   440,   366,   119,   120,   509,   510,   441,  1202,
     442,   121,   443,   483,   122,   123,   512,   454,  1218,   591,
     124,   444,   745,   445,   593,   125,   126,   446,   127,   128,
     129,   248,   130,   455,   447,   448,  1203,   449,  1204,  1205,
     131,   450,   491,   492,   132,   133,    73,  1219,   367,   534,
     535,   536,  1206,   134,  1220,   249,   511,   537,   538,  1207,
     539,   540,   135,  1221,   456,   541,   545,   546,   547,   548,
     136,   549,   137,   550,   138,   368,   139,   512,   140,   141,
     640,   551,   595,   552,   553,   596,   317,   554,   250,   555,
    1222,   142,  1223,  1224,  1139,   251,   143,   144,   145,   556,
     146,   147,   148,   557,   558,   149,  1225,   559,  1140,   560,
     561,   572,   576,  1226,   600,   601,  1141,   252,   602,   457,
     354,   253,   355,   603,   356,   604,   605,   458,   459,   254,
    1142,   150,   255,   256,   606,   607,   357,   625,   608,   151,
     152,   153,   154,   155,   156,   646,   647,   609,   460,  1106,
     611,   612,   358,   613,   614,   615,   616,   617,  1143,   618,
    1144,   619,   620,   621,   257,   622,   626,   627,   628,   629,
    1107,  1257,   157,   630,   631,   633,   359,   634,   360,  1108,
     635,   258,   636,   361,   259,  1275,  1145,   637,   638,   639,
     642,   643,   648,   362,   649,   656,   158,   159,   652,   160,
     161,   162,   655,   657,   658,   163,   659,  1109,   660,   260,
     164,   663,   662,  1276,   664,  1277,   666,   671,   363,  1146,
     596,  1147,   667,   461,   668,   669,   672,   261,   262,   263,
     674,   675,   676,   677,   678,   679,  1110,  1111,   680,   681,
    1148,   705,   364,   682,  1112,   685,   686,   809,   810,   811,
     812,   813,   814,   815,   264,   265,   687,   692,  1149,   693,
    1278,   694,   365,  1150,   695,   697,   698,  1151,   701,  1113,
     702,   366,  1152,   706,   708,  1153,   726,  1279,   319,   229,
    1154,   703,   709,   894,   704,  1114,   727,     2,     3,   710,
     719,     4,   320,   321,  1155,   711,   322,  1156,   712,  1157,
     715,     5,   716,   720,     6,     7,   721,   230,   723,   728,
    1158,     8,  1280,  1281,   730,   231,   367,  1159,   731,   729,
     734,   753,     9,   754,   735,    10,    11,   232,   233,   736,
     738,   234,   235,   236,  1047,  1048,  1049,  1050,  1051,  1052,
    1053,   323,   755,   368,   739,   740,  1115,   741,   756,   742,
      12,   744,   757,   237,   747,    13,   748,   758,   749,   324,
     325,   326,   327,    14,   750,   759,   328,   918,  1282,   919,
     329,   761,  1283,   762,   763,   764,   330,   765,   766,   767,
     768,   769,   770,   771,    15,    16,   772,   331,   332,   773,
     774,   783,   785,   786,   784,   791,   895,   896,   897,   333,
     898,   899,    17,   900,   901,   787,   902,   792,   903,   794,
    1167,   904,  1168,   793,   905,   906,   907,   795,   908,    18,
     796,   334,   797,   909,   799,   802,   803,   910,   911,   912,
     804,   805,    19,    20,   806,   807,   808,   913,   818,   819,
     820,   821,   914,   822,   823,   824,   825,   826,   827,   830,
     829,   831,    21,   833,   834,   836,   837,   838,   840,   843,
     335,   844,  1133,   848,   851,    22,   854,   847,   859,   862,
     849,   863,   866,   867,    23,   850,   852,   853,    24,   855,
     920,   921,   922,   856,   923,   924,   857,   925,   926,   858,
     927,   860,   928,   861,   864,   929,   865,   963,   930,   931,
     932,   868,   933,   869,   870,   965,   964,   934,   967,   871,
     872,   935,   936,   937,   873,   966,   874,   875,   876,   877,
     878,   938,   879,  1169,  1170,  1171,   939,  1172,  1173,   880,
    1174,  1175,   881,  1176,   882,  1177,    79,   883,  1178,   884,
     885,  1179,  1180,  1181,   886,  1182,   968,   887,   888,   889,
    1183,   890,   891,   892,  1184,  1185,  1186,    80,    81,   969,
     893,   917,   942,    82,  1187,   970,   972,   973,   975,  1188,
     976,   978,   977,   984,   985,   987,   990,   991,   943,   992,
     993,   996,   944,   998,   945,   988,   946,   999,   947,  1000,
     994,   948,   949,  1029,   950,  1043,   951,  1045,  1132,   952,
    1196,    83,    84,   953,   954,   955,   956,    85,    86,   957,
     958,   959,   960,   961,    87,    88,    89,   962,   971,   989,
     974,   981,   982,   983,   986,  1195,   997,  1243,   995,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
      90,    91,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1255,  1020,  1021,  1022,  1027,  1028,   494,  1031,  1032,  1030,
    1042,  1046,  1044,  1266,  1054,  1055,  1056,  1061,  1062,  1267,
    1268,   304,  1215,  1063,   733,  1064,  1065,  1270,   563,   746,
    1289,  1265,  1066,  1269,  1262,   725,  1067,   714,  1068,  1069,
    1244,  1264,  1070,  1286,  1076,  1077,  1078,   752,  1079,   790,
    1080,   574,  1081,  1082,  1083,  1084,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1096,  1097,  1098,  1099,  1104,  1105,  1118,
    1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1135,  1136,
    1137,  1138,  1162,  1163,  1164,  1165,  1166,  1191,  1192,  1193,
    1194,  1197,  1210,   801,  1271,  1216,  1211,  1212,  1229,  1245,
    1263,   394,  1246,  1259,   718,  1247,  1248,  1272,  1258,  1273,
    1274,   452,  1238,  1237,   318,     0,     0,     0,   543,   641,
       0,     0,     0,     0,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   651,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   578,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     624
};

static const yytype_int16 yycheck[] =
{
     621,   622,   309,   310,   311,     8,     1,     1,     1,     1,
      49,     1,    52,     1,     1,   230,   228,     1,   228,     1,
     232,     1,   232,     1,   228,     1,     1,     1,   232,     1,
     228,   229,   228,    25,     1,    29,   232,   228,   109,   228,
       1,   232,     1,    37,   228,    25,   228,     1,   232,   228,
     232,     1,    32,   232,   228,    49,    50,     1,   232,    53,
      54,    55,     1,   230,    57,     1,    58,     1,     1,    62,
     228,    64,   228,    65,   232,    62,   232,   230,    17,   228,
      62,    75,   228,   232,    62,   125,   232,    77,   230,    77,
     211,    35,     1,   214,    33,    87,   403,   404,   230,    91,
     230,    35,   211,    62,   411,   214,   230,    99,   415,     1,
     102,   103,    96,   420,     6,     7,   423,   230,     1,    99,
      12,   231,    96,    99,    99,    64,   433,   434,    20,    21,
     123,   126,    99,    77,   205,    27,   120,   444,    30,    31,
     447,   448,   134,    77,    36,    99,   120,   186,   126,    41,
      42,   126,    44,    45,    46,   230,    48,   196,   230,   151,
       1,     1,   154,    99,    56,   230,    99,   126,    60,    61,
     200,   201,   126,     1,    15,    16,   126,    69,    19,   230,
     119,   171,   126,   171,   200,   201,    78,   179,   127,   128,
      99,   228,   126,   196,    86,   230,    88,   230,    90,   171,
      92,   230,    94,    95,   230,   197,   198,   199,   230,   148,
     171,  1071,  1072,  1073,     1,   107,    99,     9,    10,    11,
     112,   113,   114,    64,   116,   117,   118,   231,   223,   121,
      17,   230,   224,   225,   541,   229,   229,   229,   124,   229,
     231,    82,    83,    84,    85,   229,    33,   229,    89,   229,
     222,   229,    93,   229,   229,   147,   211,   229,    99,    99,
     230,   222,   230,   155,   156,   157,   158,   159,   160,   110,
     111,    99,     1,   223,     3,     1,     5,    64,     1,   229,
     231,   122,   230,   219,   223,   229,   219,   223,    17,   231,
     229,    17,   171,   229,   175,   176,   188,   228,   124,    22,
      23,   231,   609,   144,    33,    28,   613,    33,   231,   616,
     219,     1,    99,   620,   223,   231,   231,   109,   231,   231,
     212,   213,    70,   215,   216,   217,   231,   231,    57,   221,
      59,   231,   119,   231,   226,    64,   219,   229,    64,   228,
     231,   231,   183,    66,    67,    74,   229,   231,   135,    72,
      73,   231,   192,   231,   231,   231,    79,    80,    81,   231,
     231,   231,   231,   231,   192,   152,   153,    57,     1,   231,
      99,   231,    62,    99,    64,   231,    70,   231,   231,   219,
     231,   231,   105,   106,   132,   231,   231,   231,   229,   229,
     124,   219,    25,   119,   123,   231,   231,   231,   231,    32,
     231,   231,   231,   109,   231,     1,   231,   231,   231,   135,
       6,     7,   231,   161,   143,   202,    12,   231,   231,   231,
     168,     1,   231,   152,    20,    21,   152,   153,   231,   177,
     231,    27,   231,   123,    30,    31,   223,    17,   132,   228,
      36,   231,   229,   231,   109,    41,    42,   231,    44,    45,
      46,     1,    48,    33,   231,   231,   204,   231,   206,   207,
      56,   231,   231,   231,    60,    61,    99,   161,   197,   231,
     231,   231,   220,    69,   168,    25,   202,   231,   231,   227,
     231,   231,    78,   177,    64,   231,   231,   231,   231,   231,
      86,   231,    88,   231,    90,   224,    92,   223,    94,    95,
     229,   231,   109,   231,   231,   109,   229,   231,    58,   231,
     204,   107,   206,   207,     4,    65,   112,   113,   114,   231,
     116,   117,   118,   231,   231,   121,   220,   231,    18,   231,
     231,   231,   231,   227,   109,   109,    26,    87,   109,   119,
       1,    91,     3,   211,     5,   211,   228,   127,   128,    99,
      40,   147,   102,   103,   228,   231,    17,   228,   231,   155,
     156,   157,   158,   159,   160,   124,   228,   231,   148,    13,
     231,   231,    33,   231,   231,   231,   231,   231,    68,   231,
      70,   231,   231,   231,   134,   231,   231,   231,   231,   231,
      34,  1212,   188,   231,   231,   231,    57,   231,    59,    43,
     231,   151,   231,    64,   154,    40,    96,   231,   231,   231,
     231,   231,   231,    74,   231,   109,   212,   213,   211,   215,
     216,   217,   211,   211,   109,   221,   124,    71,   211,   179,
     226,   109,   211,    68,   109,    70,   109,   109,    99,   129,
     109,   131,   211,   223,   211,   211,   109,   197,   198,   199,
     109,   109,   109,   109,   211,   231,   100,   101,   211,   231,
     150,   231,   123,   211,   108,   211,   211,   136,   137,   138,
     139,   140,   141,   142,   224,   225,   211,   211,   168,   211,
     115,   211,   143,   173,   124,   211,   211,   177,   211,   133,
     211,   152,   182,   231,   231,   185,   124,   132,     1,     1,
     190,   228,   231,    49,   228,   149,   124,     0,     1,   231,
     228,     4,    15,    16,   204,   231,    19,   207,   231,   209,
     231,    14,   231,   231,    17,    18,   231,    29,   231,   228,
     220,    24,   167,   168,   231,    37,   197,   227,   231,   228,
     228,   211,    35,   211,   231,    38,    39,    49,    50,   231,
     231,    53,    54,    55,   809,   810,   811,   812,   813,   814,
     815,    64,   211,   224,   231,   231,   210,   231,   124,   231,
      63,   231,   211,    75,   228,    68,   231,   211,   231,    82,
      83,    84,    85,    76,   231,   211,    89,    49,   223,    51,
      93,   228,   227,   124,   211,   124,    99,   109,   109,   124,
     124,   124,   124,   124,    97,    98,   124,   110,   111,   109,
     124,   124,   228,   228,   124,   211,   162,   163,   164,   122,
     166,   167,   115,   169,   170,   231,   172,   228,   174,   124,
      49,   177,    51,   230,   180,   181,   182,   228,   184,   132,
     228,   144,   231,   189,   231,   228,   228,   193,   194,   195,
     228,   228,   145,   146,   228,   228,   228,   203,   228,   228,
     228,   228,   208,   228,   228,   228,   228,   109,   109,   109,
     231,   109,   165,   109,   109,   124,   109,   109,   109,   228,
     183,   124,   232,   211,   231,   178,   109,   124,   228,   228,
     124,   228,   228,   228,   187,   124,   124,   124,   191,   124,
     162,   163,   164,   124,   166,   167,   124,   169,   170,   124,
     172,   124,   174,   124,   124,   177,   124,   124,   180,   181,
     182,   228,   184,   228,   228,   231,   211,   189,   109,   228,
     228,   193,   194,   195,   228,   124,   228,   228,   228,   228,
     228,   203,   228,   162,   163,   164,   208,   166,   167,   228,
     169,   170,   228,   172,   228,   174,     1,   228,   177,   228,
     228,   180,   181,   182,   228,   184,   124,   228,   228,   228,
     189,   228,   228,   228,   193,   194,   195,    22,    23,   124,
     228,   228,   228,    28,   203,   124,   124,   124,   124,   208,
     124,   109,   231,   124,   124,   124,   124,   124,   228,   124,
     124,   124,   228,   124,   228,   211,   228,   124,   228,   124,
     211,   228,   228,   124,   228,   124,   228,   124,   218,   228,
    1026,    66,    67,   228,   228,   228,   228,    72,    73,   228,
     228,   228,   228,   228,    79,    80,    81,   228,   228,   231,
     228,   228,   228,   228,   228,  1024,   228,   109,   231,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     105,   106,   228,   228,   228,   228,   228,   228,   228,   228,
     124,   228,   228,   228,   228,   228,   222,   228,   228,   231,
     228,   228,   231,   130,   228,   228,   228,   228,   228,   130,
     130,    74,  1037,   228,   498,   228,   228,  1252,   266,   513,
    1288,  1242,   228,  1250,  1231,   485,   228,   462,   228,   228,
    1133,  1240,   228,  1261,   228,   228,   228,   529,   228,   567,
     228,   288,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   583,  1254,   228,   231,   231,   228,   228,
    1236,   111,   233,   228,   475,   233,   233,   228,   231,   228,
     228,   165,  1103,  1101,    92,    -1,    -1,    -1,   238,   369,
      -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     336
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   235,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    63,    68,    76,    97,    98,   115,   132,   145,
     146,   165,   178,   187,   191,   236,   241,   246,   270,   276,
     282,   296,   316,   339,   353,   368,   375,   379,   389,   398,
     419,   425,   431,   435,   441,   499,   514,   228,   229,   230,
     230,   317,   399,   426,   230,   436,   230,   354,   420,   340,
     230,   277,   297,   369,   230,   230,   390,   230,   230,   380,
       1,    25,    32,    99,   271,   272,   273,   274,   275,     1,
      22,    23,    28,    66,    67,    72,    73,    79,    80,    81,
     105,   106,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   230,   230,   230,     1,
      62,   432,   433,   434,   230,     1,     6,     7,    12,    20,
      21,    27,    30,    31,    36,    41,    42,    44,    45,    46,
      48,    56,    60,    61,    69,    78,    86,    88,    90,    92,
      94,    95,   107,   112,   113,   114,   116,   117,   118,   121,
     147,   155,   156,   157,   158,   159,   160,   188,   212,   213,
     215,   216,   217,   221,   226,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   492,   496,   497,   498,   230,   230,   230,     1,
      96,   120,   242,   243,   244,   245,   230,   230,   230,     1,
      29,    37,    49,    50,    53,    54,    55,    75,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,     1,    25,
      58,    65,    87,    91,    99,   102,   103,   134,   151,   154,
     179,   197,   198,   199,   224,   225,   247,   248,   249,   250,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   230,     1,   222,   283,   284,
     285,   286,   287,     1,    99,   376,   377,   378,   230,   228,
     231,   231,   231,   229,   272,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   501,     1,
      15,    16,    19,    64,    82,    83,    84,    85,    89,    93,
      99,   110,   111,   122,   144,   183,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,     1,     3,     5,    17,    33,    57,
      59,    64,    74,    99,   123,   143,   152,   197,   224,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     414,   415,   416,   417,   418,     1,    62,   126,   427,   428,
     429,   430,   231,   229,   433,     1,    99,   126,   437,   438,
     439,   440,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   493,
     231,   489,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   229,   443,     1,    17,    33,    64,   119,   127,   128,
     148,   223,   355,   356,   357,   358,   359,   360,   361,   365,
     366,   367,     1,   126,   223,   421,   422,   423,   424,     1,
      57,    62,    64,   123,   341,   345,   346,   347,   351,   352,
     228,   231,   231,   229,   243,     1,    77,   171,   278,   279,
     280,   281,     1,    17,    33,    64,    99,   119,   135,   152,
     153,   202,   223,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   312,     1,    35,    77,   126,   370,
     371,   372,   373,   374,   231,   231,   231,   231,   231,   231,
     231,   231,   229,   516,   228,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   229,   248,     1,    99,   219,   391,   392,   393,
     394,   228,   231,   229,   284,   171,   231,   229,   377,     1,
      99,   219,   223,   381,   382,   383,   384,   385,   124,   124,
     124,   228,   109,   109,   211,   109,   109,   238,   238,   238,
     109,   109,   109,   211,   211,   228,   228,   231,   231,   231,
     336,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   229,   319,   228,   231,   231,   231,   231,
     231,   231,   411,   231,   231,   231,   231,   231,   231,   231,
     229,   401,   231,   231,   229,   428,   124,   228,   231,   231,
     229,   438,   211,   238,   238,   211,   109,   211,   109,   124,
     211,   238,   211,   109,   109,   238,   109,   211,   211,   211,
     238,   109,   109,   238,   109,   109,   109,   109,   211,   231,
     211,   231,   211,   238,   238,   211,   211,   211,   211,   214,
     211,   214,   211,   211,   211,   124,   238,   211,   211,   238,
     238,   211,   211,   228,   228,   231,   231,   362,   231,   231,
     231,   231,   231,   229,   356,   231,   231,   229,   422,   228,
     231,   231,   342,   231,   229,   346,   124,   124,   228,   228,
     231,   231,   229,   279,   228,   231,   231,   313,   231,   231,
     231,   231,   231,   309,   231,   229,   299,   228,   231,   231,
     231,   229,   371,   211,   211,   211,   124,   211,   211,   211,
     238,   228,   124,   211,   124,   109,   109,   124,   124,   124,
     124,   124,   124,   109,   124,   200,   201,   251,   252,   200,
     201,   253,   254,   124,   124,   228,   228,   231,   395,   229,
     392,   211,   228,   230,   124,   228,   228,   231,   386,   231,
     229,   382,   228,   228,   228,   228,   228,   228,   228,   136,
     137,   138,   139,   140,   141,   142,   237,   238,   228,   228,
     228,   228,   228,   228,   228,   228,   109,   109,   238,   231,
     109,   109,   238,   109,   109,   238,   124,   109,   109,   238,
     109,   240,   240,   228,   124,   175,   176,   124,   211,   124,
     124,   231,   124,   124,   109,   124,   124,   124,   124,   228,
     124,   124,   228,   228,   124,   124,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,    49,   162,   163,   164,   166,   167,
     169,   170,   172,   174,   177,   180,   181,   182,   184,   189,
     193,   194,   195,   203,   208,   494,   495,   228,    49,    51,
     162,   163,   164,   166,   167,   169,   170,   172,   174,   177,
     180,   181,   182,   184,   189,   193,   194,   195,   203,   208,
     490,   491,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   124,   211,   231,   124,   109,   124,   124,
     124,   228,   124,   124,   228,   124,   124,   231,   109,   349,
     350,   228,   228,   228,   124,   124,   228,   124,   211,   231,
     124,   124,   124,   124,   211,   231,   124,   228,   124,   124,
     124,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   232,   228,   232,   228,   228,   124,
     231,   228,   228,     1,    99,   192,   219,   288,   289,   290,
     291,   292,   228,   124,   231,   124,   228,   237,   237,   237,
     237,   237,   237,   237,   228,   228,   228,    52,   125,   337,
     338,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,     9,    10,    11,   239,   240,   228,   228,   228,   228,
     228,   228,   228,   228,   228,     8,   196,   412,   413,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   232,   228,   232,   228,   228,    13,    34,    43,    71,
     100,   101,   108,   133,   149,   210,   363,   364,   228,   228,
     228,   228,   228,   228,   228,   228,   228,    49,   186,   196,
     343,   344,   218,   232,   348,   228,   228,   228,   228,     4,
      18,    26,    40,    68,    70,    96,   129,   131,   150,   168,
     173,   177,   182,   185,   190,   204,   207,   209,   220,   227,
     314,   315,   228,   228,   228,   228,   228,    49,    51,   162,
     163,   164,   166,   167,   169,   170,   172,   174,   177,   180,
     181,   182,   184,   189,   193,   194,   195,   203,   208,   310,
     311,   228,   228,   228,   228,   252,   254,   228,    70,   132,
     161,   168,   177,   204,   206,   207,   220,   227,   396,   397,
     228,   231,   231,   293,   229,   289,   228,    70,   132,   161,
     168,   177,   204,   206,   207,   220,   227,   387,   388,   228,
     228,   232,   239,   239,   239,   228,   232,   495,   491,   228,
     232,   228,   232,   109,   350,   228,   233,   233,   233,   228,
     232,   228,   232,   228,   232,   124,   205,   240,   231,   228,
     228,   232,   338,   413,   364,   344,   130,   130,   130,   315,
     311,   397,   228,   228,   228,    40,    68,    70,   115,   132,
     167,   168,   223,   227,   294,   295,   388,   228,   232,   295
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   234,   235,   235,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   238,   238,   238,   238,   238,   238,   239,   239,   240,
     240,   240,   240,   241,   242,   242,   243,   243,   243,   244,
     245,   246,   247,   247,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   249,   250,   251,   251,   252,   252,   253,   253,
     254,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   271,
     272,   272,   272,   272,   273,   274,   275,   277,   276,   278,
     278,   279,   279,   279,   280,   281,   282,   283,   283,   284,
     284,   284,   285,   287,   286,   288,   288,   289,   289,   289,
     289,   290,   291,   291,   293,   292,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   297,   296,   298,
     298,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     309,   308,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   313,   312,   314,   314,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   317,   316,   318,   318,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     336,   335,   337,   337,   338,   338,   340,   339,   342,   341,
     343,   343,   344,   344,   344,   345,   345,   346,   346,   346,
     346,   346,   348,   347,   349,   349,   350,   350,   351,   352,
     354,   353,   355,   355,   356,   356,   356,   356,   356,   356,
     356,   356,   356,   357,   358,   359,   360,   362,   361,   363,
     363,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   365,   366,   367,   369,   368,   370,   370,   371,   371,
     371,   371,   372,   373,   374,   375,   376,   376,   377,   377,
     378,   380,   379,   381,   381,   382,   382,   382,   382,   383,
     384,   386,   385,   387,   387,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   390,   389,   391,   391,   392,
     392,   392,   393,   395,   394,   396,   396,   397,   397,   397,
     397,   397,   397,   397,   397,   397,   397,   399,   398,   400,
     400,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   409,   411,   410,   412,   412,   413,
     413,   414,   415,   416,   417,   418,   420,   419,   421,   421,
     422,   422,   422,   423,   424,   426,   425,   427,   427,   428,
     428,   428,   429,   430,   431,   432,   432,   433,   433,   434,
     436,   435,   437,   437,   438,   438,   438,   439,   440,   441,
     442,   442,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   443,   443,   443,   443,   443,   443,   443,   443,
     443,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   470,
     471,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   489,   488,
     490,   490,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   493,   492,   494,   494,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     497,   498,   499,   500,   500,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   515,   516,   516,   516,   516,   516,   516,   516,
     516,   516,   517,   518,   519,   520,   521,   522,   523,   524
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
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
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
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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
#line 407 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 408 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 476 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 482 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 491 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 497 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 505 "conf_parser.y" /* yacc.c:1646  */
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
#line 3027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 547 "conf_parser.y" /* yacc.c:1646  */
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
#line 3088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 605 "conf_parser.y" /* yacc.c:1646  */
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
#line 3119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 633 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 641 "conf_parser.y" /* yacc.c:1646  */
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
#line 3148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 656 "conf_parser.y" /* yacc.c:1646  */
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
#line 3166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 671 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 680 "conf_parser.y" /* yacc.c:1646  */
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
#line 3195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 703 "conf_parser.y" /* yacc.c:1646  */
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
#line 3238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 731 "conf_parser.y" /* yacc.c:1646  */
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
#line 3271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 761 "conf_parser.y" /* yacc.c:1646  */
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
#line 3299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 786 "conf_parser.y" /* yacc.c:1646  */
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
#line 3324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 808 "conf_parser.y" /* yacc.c:1646  */
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
#line 3349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 865 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 881 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 929 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 988 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 996 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3577 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1017 "conf_parser.y" /* yacc.c:1646  */
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
#line 3674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3692 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1121 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1138 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1176 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1180 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1192 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1204 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
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
#line 4205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
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
#line 4257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1458 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1507 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
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
#line 4495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
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
#line 4516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1629 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1644 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 291:
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
#line 4584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1703 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1709 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
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
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1737 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1769 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
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
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1789 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1811 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1841 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
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
#line 4830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
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
#line 4846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
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
#line 4863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1899 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
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
#line 4894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1976 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
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
#line 5210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
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
#line 5253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
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
#line 5269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2207 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
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
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
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
#line 5388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
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
#line 5422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
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
#line 5445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
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
#line 5489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
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
#line 5524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
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
#line 5555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2497 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2502 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2508 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2526 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2531 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2541 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2546 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2551 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2556 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2566 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2571 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2576 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2608 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2641 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2646 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2659 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2664 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2669 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6458 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3034 "conf_parser.y" /* yacc.c:1646  */
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
#line 6505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6523 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6527 "conf_parser.c" /* yacc.c:1646  */
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
