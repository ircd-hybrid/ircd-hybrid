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
    THROTTLE_COUNT = 467,
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
#define THROTTLE_COUNT 467
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
#line 147 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 686 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 701 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1298

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
       0,   379,   379,   380,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   409,   409,   410,
     411,   412,   413,   414,   415,   416,   417,   420,   420,   421,
     422,   423,   424,   431,   434,   434,   435,   435,   435,   437,
     443,   450,   452,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   473,   515,   573,   601,   609,   623,   651,   666,
     681,   690,   704,   713,   741,   771,   796,   818,   840,   849,
     851,   851,   852,   853,   854,   855,   857,   866,   875,   888,
     887,   905,   905,   906,   906,   906,   908,   914,   923,   924,
     924,   926,   926,   927,   929,   936,   936,   949,   950,   952,
     952,   953,   953,   955,   963,   966,   972,   971,   977,   977,
     978,   982,   986,   990,   994,   998,  1002,  1006,  1010,  1021,
    1020,  1100,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1110,  1111,  1113,  1119,  1125,  1131,  1142,  1148,
    1154,  1165,  1172,  1171,  1177,  1177,  1178,  1182,  1186,  1190,
    1194,  1198,  1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,
    1234,  1238,  1242,  1246,  1250,  1254,  1258,  1262,  1269,  1268,
    1274,  1274,  1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,
    1307,  1311,  1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,
    1347,  1351,  1355,  1359,  1363,  1374,  1373,  1435,  1435,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1446,
    1447,  1448,  1448,  1449,  1450,  1451,  1452,  1454,  1460,  1466,
    1472,  1478,  1484,  1490,  1496,  1502,  1508,  1514,  1521,  1527,
    1533,  1539,  1548,  1558,  1557,  1563,  1563,  1564,  1568,  1579,
    1578,  1585,  1584,  1589,  1589,  1590,  1594,  1598,  1604,  1604,
    1605,  1605,  1605,  1605,  1605,  1607,  1607,  1609,  1609,  1611,
    1625,  1643,  1649,  1659,  1658,  1700,  1700,  1701,  1702,  1703,
    1704,  1705,  1706,  1707,  1708,  1709,  1711,  1717,  1723,  1729,
    1741,  1740,  1746,  1746,  1747,  1751,  1755,  1759,  1763,  1767,
    1771,  1775,  1779,  1783,  1789,  1803,  1812,  1826,  1825,  1840,
    1840,  1841,  1841,  1841,  1841,  1843,  1849,  1855,  1865,  1867,
    1867,  1868,  1868,  1870,  1886,  1885,  1910,  1910,  1911,  1911,
    1911,  1911,  1913,  1919,  1939,  1938,  1944,  1944,  1945,  1949,
    1953,  1957,  1961,  1965,  1969,  1973,  1977,  1981,  1991,  1990,
    2011,  2011,  2012,  2012,  2012,  2014,  2021,  2020,  2026,  2026,
    2027,  2031,  2035,  2039,  2043,  2047,  2051,  2055,  2059,  2063,
    2073,  2072,  2144,  2144,  2145,  2146,  2147,  2148,  2149,  2150,
    2151,  2152,  2153,  2154,  2155,  2156,  2157,  2158,  2159,  2161,
    2167,  2173,  2179,  2192,  2205,  2211,  2217,  2221,  2230,  2229,
    2234,  2234,  2235,  2239,  2245,  2256,  2262,  2268,  2274,  2290,
    2289,  2315,  2315,  2316,  2316,  2316,  2318,  2338,  2348,  2347,
    2374,  2374,  2375,  2375,  2375,  2377,  2383,  2392,  2394,  2394,
    2395,  2395,  2397,  2415,  2414,  2437,  2437,  2438,  2438,  2438,
    2440,  2446,  2455,  2458,  2458,  2459,  2460,  2461,  2462,  2463,
    2464,  2465,  2466,  2467,  2468,  2469,  2470,  2471,  2472,  2473,
    2474,  2475,  2476,  2477,  2478,  2479,  2480,  2481,  2482,  2483,
    2484,  2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,
    2494,  2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,
    2504,  2505,  2506,  2507,  2508,  2509,  2512,  2517,  2523,  2529,
    2535,  2541,  2546,  2551,  2556,  2561,  2566,  2571,  2576,  2581,
    2586,  2591,  2596,  2601,  2606,  2612,  2623,  2628,  2633,  2638,
    2643,  2648,  2653,  2656,  2661,  2664,  2669,  2674,  2679,  2684,
    2689,  2694,  2699,  2704,  2709,  2714,  2719,  2724,  2733,  2742,
    2747,  2752,  2757,  2763,  2762,  2767,  2767,  2768,  2771,  2774,
    2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,  2801,  2804,
    2807,  2810,  2813,  2816,  2819,  2822,  2825,  2828,  2831,  2837,
    2836,  2841,  2841,  2842,  2845,  2848,  2851,  2854,  2857,  2860,
    2863,  2866,  2869,  2872,  2875,  2878,  2881,  2884,  2887,  2890,
    2893,  2896,  2899,  2904,  2909,  2914,  2923,  2926,  2926,  2927,
    2928,  2929,  2930,  2931,  2932,  2933,  2934,  2935,  2936,  2937,
    2938,  2939,  2940,  2941,  2943,  2948,  2953,  2958,  2963,  2968,
    2973,  2978,  2983,  2988,  2993,  2998,  3003,  3008,  3016,  3019,
    3019,  3020,  3021,  3022,  3023,  3024,  3025,  3026,  3027,  3028,
    3030,  3036,  3042,  3048,  3054,  3063,  3078,  3084
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,    59,
     125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -701

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-701)))

#define YYTABLE_NINF -116

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -701,   711,  -701,  -160,  -221,  -214,  -701,  -701,  -701,  -192,
    -701,  -168,  -701,  -701,  -701,  -138,  -701,  -701,  -701,  -136,
    -107,  -701,  -105,  -102,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,   185,
     999,   -99,   -97,   -76,    10,   -70,   406,   -62,   -56,   -43,
      73,   -34,   -32,   -31,   344,   452,   -29,    27,    14,   -16,
    -187,    -5,    -4,    32,    13,  -701,  -701,  -701,  -701,  -701,
      38,    48,    68,    78,    87,    99,   100,   102,   103,   106,
     107,   109,   110,   112,     2,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
     751,   598,    39,  -701,   114,    19,  -701,  -701,    63,  -701,
     118,   119,   121,   140,   142,   143,   145,   148,   153,   154,
     155,   157,   158,   160,   163,   164,   169,   172,   174,   176,
     177,   178,   179,   182,   184,   187,   188,  -701,   189,  -701,
     190,   192,   193,   197,   198,   199,   200,   202,   206,   207,
     209,   211,   213,   214,   217,   223,   226,   227,   229,   230,
      61,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,   335,    12,   253,   -40,   232,   237,    28,  -701,
    -701,  -701,    18,   439,   138,  -701,   238,   242,   243,   244,
     255,   257,   260,   262,     4,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,    40,   264,   266,   268,   270,   273,
     275,   276,   277,   278,   280,   281,   283,   286,   292,   296,
     297,   300,   139,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,    26,    86,   301,     7,  -701,  -701,  -701,   131,  -701,
     302,    36,  -701,  -701,    11,  -701,   124,   251,   290,   306,
    -701,   259,   293,   325,   361,   425,   428,   425,   431,   425,
     425,   432,   433,   336,   337,   320,  -701,   321,   319,   328,
     330,  -701,   331,   332,   333,   340,   341,   342,   343,   346,
     347,   348,   349,   350,   351,   241,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,   323,   355,   356,   358,   359,   364,
     365,  -701,   368,   370,   372,   373,   375,   381,   382,   289,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,   384,   385,    31,  -701,
    -701,  -701,   449,   392,  -701,  -701,   393,   394,    33,  -701,
    -701,  -701,   416,   425,   425,   419,   520,   423,   523,   510,
     429,   425,   435,   527,   530,   425,   531,   438,   440,   441,
     425,   538,   542,   425,   543,   545,   547,   548,   450,   430,
     453,   436,   456,   425,   425,   459,   460,   461,  -189,  -180,
     462,   463,   464,   552,   568,   425,   470,   471,   425,   425,
     472,   473,   458,  -701,   465,   457,   469,  -701,   476,   477,
     478,   481,   482,   173,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,   484,   486,    75,  -701,  -701,  -701,
     467,   487,   489,  -701,   491,  -701,    22,  -701,  -701,  -701,
    -701,  -701,   558,   561,   468,  -701,   474,   494,   495,    17,
    -701,  -701,  -701,   475,   498,   500,  -701,   501,   504,   505,
     506,   507,  -701,   508,   146,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,   514,   516,   519,   522,
      55,  -701,  -701,  -701,  -701,   479,   534,   546,   565,   549,
     550,   551,   425,   529,  -701,  -701,   578,   553,   615,   644,
     647,   636,   638,   641,   642,   645,   646,   648,   649,   659,
     651,   652,   653,   554,  -701,   555,   557,  -701,    51,  -701,
    -701,  -701,  -701,   563,   566,  -701,   559,   654,   567,  -701,
     569,   560,  -701,   562,    35,  -701,  -701,  -701,  -701,   571,
     572,   574,  -701,   575,   577,   579,   580,   218,   581,   584,
     585,   586,   587,   588,   590,   591,   592,   593,  -701,  -701,
     685,   695,   425,   600,   713,   721,   722,   425,   728,   730,
     425,   717,   733,   737,   425,   738,   738,   622,  -701,  -701,
     725,  -131,   727,   650,   729,   731,   623,   735,   740,   745,
     741,   742,   743,   744,   634,  -701,   746,   747,   643,  -701,
     655,  -701,   748,   750,   656,  -701,   657,   658,   660,   661,
     662,   663,   664,   666,   667,   670,   671,   672,   680,   683,
     687,   688,   690,   691,   694,   696,   697,   698,   699,   701,
     702,   703,   707,   817,   708,   736,   712,   714,   716,   720,
     723,   726,   734,   739,   752,   754,   764,   766,   769,   772,
     775,   778,   780,   782,   783,   784,   788,   789,  -701,  -701,
     753,   668,   682,   755,   771,   761,   813,   815,   790,  -701,
     830,   833,   794,  -701,  -701,   835,   839,   776,   857,   795,
    -701,   797,   800,  -701,  -701,   843,   844,   803,  -701,  -701,
     846,   763,   801,   848,   852,   853,   907,   825,   805,   908,
     809,  -701,  -701,   912,   913,   914,   814,  -701,   818,   819,
     820,   821,   822,   826,   827,   828,  -701,   829,   831,   832,
     836,   837,   838,   841,   842,   849,   850,   851,   855,   856,
     858,   859,   860,   861,  -701,  -701,   915,   812,   862,  -701,
     863,  -701,    93,   864,  -701,  -701,   919,   840,   926,   865,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,   425,   425,
     425,   425,   425,   425,   425,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,   866,   867,   868,
      -9,   869,   870,   871,   872,   873,   874,   875,   876,   877,
     880,   881,    37,   882,   883,  -701,   884,   885,   886,   887,
     888,   889,   890,     1,   891,   892,   893,   894,   895,   896,
     897,  -701,   898,   899,  -701,  -701,   900,   901,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -178,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -172,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,   902,   903,   595,   904,   905,
     906,   909,   910,  -701,   911,   916,  -701,   917,   918,   -33,
     845,   920,  -701,  -701,  -701,  -701,   921,   922,  -701,   923,
     925,   513,   927,   928,   929,   930,   931,   779,   932,  -701,
     933,   934,   935,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,   936,
     620,  -701,  -701,   937,   854,   938,  -701,    42,  -701,  -701,
    -701,  -701,  -701,   939,   824,   940,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -108,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,   738,   738,   738,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,   -63,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,   817,  -701,   736,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,   -42,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,   -24,  -701,   942,   857,   943,  -701,  -701,  -701,  -701,
    -701,   847,  -701,  -701,   941,  -701,  -701,  -701,  -701,   944,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
     -21,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,   -15,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,   -13,  -701,  -701,   946,
     -91,   945,   947,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,    53,  -701,  -701,  -701,    -9,
    -701,  -701,  -701,  -701,     1,  -701,  -701,  -701,   595,  -701,
     -33,  -701,  -701,  -701,  1003,  1004,  1008,  -701,   513,  -701,
     779,  -701,   620,   950,   951,   952,   420,  -701,  -701,   824,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,    83,  -701,  -701,  -701,   420,  -701
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
       0,     0,     0,     0,     0,     0,     0,   579,     0,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   454,   502,   504,   496,   497,   498,   499,   500,   495,
     465,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   492,   466,   467,   501,   469,   474,   475,   470,   472,
     471,   485,   486,   473,   476,   477,   478,   479,   468,   481,
     482,   483,   503,   493,   494,   490,   491,   484,   480,   488,
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
       0,   381,     0,     0,   429,   442,     0,     0,   444,   518,
     522,   537,   507,   605,   550,   544,   547,   517,   509,   508,
     511,   512,   510,   525,   515,   516,   526,   514,   521,   520,
     519,   545,   506,   603,   604,   541,   589,   583,   599,   584,
     585,   586,   594,   602,   587,   596,   600,   590,   601,   591,
     595,   588,   598,   593,   592,   597,     0,   582,   543,   562,
     563,   564,   557,   575,   558,   559,   560,   570,   578,   561,
     572,   576,   566,   577,   567,   571,   565,   574,   569,   568,
     573,     0,   556,   538,   536,   539,   549,   540,   528,   534,
     535,   532,   533,   529,   530,   531,   548,   551,   552,   513,
     542,   524,   523,   546,   527,     0,     0,     0,     0,     0,
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
    -701,  -701,  -701,  -339,  -313,  -700,  -635,  -701,  -701,   954,
    -701,  -701,  -701,  -701,   606,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,   985,  -701,  -701,  -701,  -701,  -701,
    -701,   633,  -701,  -701,  -701,  -701,   879,  -701,  -701,  -701,
    -701,    30,  -701,  -701,  -701,  -701,  -701,  -153,  -701,  -701,
    -701,   624,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -116,  -701,  -701,  -701,  -109,  -701,  -701,
    -701,   810,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,   -72,  -701,  -701,  -701,  -701,  -701,   -79,  -701,   678,
    -701,  -701,  -701,    41,  -701,  -701,  -701,  -701,  -701,   710,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,   -64,  -701,  -701,
    -701,  -701,  -701,  -701,   665,  -701,  -701,  -701,  -701,  -701,
     924,  -701,  -701,  -701,  -701,   594,  -701,  -701,  -701,  -701,
    -701,   -83,  -701,  -701,  -701,   609,  -701,  -701,  -701,  -701,
     -73,  -701,  -701,  -701,   811,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,   -53,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,   706,  -701,  -701,  -701,  -701,
    -701,   796,  -701,  -701,  -701,  -701,  1078,  -701,  -701,  -701,
    -701,   787,  -701,  -701,  -701,  -701,  1026,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,    84,  -701,  -701,  -701,    85,
    -701,  -701,  -701,  -701,  -701,  1105,  -701,  -701,  -701,  -701,
    -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701,  -701,   956,  -701,  -701,  -701,  -701,  -701,  -701,  -701,
    -701
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
     215,   216,   217,   441,   951,   952,   218,   439,   926,   927,
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
     853,   854,   608,    79,   610,   235,   612,   613,   292,  1096,
      49,   113,   590,   483,    70,   299,  1138,    50,   506,   506,
     113,   852,   702,   490,    80,    81,   703,   575,   292,   225,
      82,   704,   395,   236,   405,   705,   590,   299,    71,    54,
     395,   237,   305,  1043,  1067,    72,  1082,  1083,  1084,   857,
     858,  1111,   575,   238,   239,  1112,   536,  1113,   240,   241,
     242,  1114,   119,    56,   405,    83,    84,   120,   121,    47,
      48,    85,    86,   122,   225,   114,   483,    87,    88,    89,
     491,   123,   124,   243,   114,    90,    91,   492,   125,   493,
     537,   126,   127,    60,  1043,    64,   396,   128,   507,   507,
     667,   668,   129,   130,   396,   131,   132,   133,   675,   134,
      92,    93,   679,   591,  1264,    73,   300,   684,   135,  1068,
     687,  1238,   136,   137,    65,  1239,    67,   226,   576,    68,
     697,   698,   110,   138,   111,   406,   538,   591,   300,   536,
     254,   484,   711,   139,  1044,   714,   715,   513,   494,   852,
     140,   227,   141,   576,   142,   112,   143,  1139,   144,   145,
     397,   118,   407,   514,   255,   406,  1243,  1140,   397,   222,
    1244,   146,   226,   537,   464,   223,   147,   148,   149,   515,
     150,   151,   152,  -115,   539,   153,    70,  1247,   224,   501,
     465,  1248,   407,   508,   508,  1044,   227,   232,   256,   233,
     234,  1097,   291,  -115,   484,  1249,   466,   257,  1257,  1250,
      71,   154,  1258,   516,  1259,   304,  1261,    72,  1260,   538,
    1262,   155,   156,   157,   158,   159,   160,   306,   307,   258,
     293,   592,   325,   259,   553,   593,   485,   584,  1045,   775,
     467,   260,   327,   309,   261,   262,   577,   747,   517,   403,
     293,   599,   739,   161,   490,   592,   328,   329,   504,   593,
     330,   658,  1046,   664,   308,   809,   588,   539,   518,   555,
     311,   577,  1222,   162,   163,   164,   263,   165,   166,   167,
     312,   798,  1268,   168,   519,   766,  1269,    73,   169,  1045,
     364,   462,   365,   264,   366,   468,   265,   266,   267,   485,
     313,   520,   521,   469,   470,   732,   367,   586,   331,   839,
     314,   491,  1295,  1046,   844,   582,  1296,   847,   492,   315,
     493,   851,   368,   268,   471,   332,   333,   334,   335,   336,
     607,   316,   317,   337,   318,   319,   464,   338,   320,   321,
     269,   322,   323,   339,   324,   235,   402,   369,   522,   370,
     412,   413,   465,   414,   340,   341,   371,   818,   819,   820,
     821,   822,   823,   824,   270,   271,   342,   372,   466,   573,
     523,   603,   415,   236,   416,   417,   760,   418,   600,   494,
     419,   237,  1240,  1241,  1242,   420,   421,   422,   343,   423,
     424,   373,   425,   238,   239,   426,   427,   472,   240,   241,
     242,   428,   467,   728,   429,   604,   430,   119,   431,   432,
     433,   434,   120,   121,   435,   374,   436,   601,   122,   437,
     438,   440,   442,   243,   443,   444,   123,   124,   344,   445,
     446,   447,   448,   125,   449,   375,   126,   127,   450,   451,
     513,   452,   128,   453,   376,   454,   455,   129,   130,   456,
     131,   132,   133,   254,   134,   457,   514,   468,   458,   459,
    1283,   460,   461,   135,   502,   469,   470,   136,   137,   503,
     545,   637,   515,   606,   546,   547,   548,   255,   138,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,   471,   549,   139,   550,
     377,  1284,   551,  1285,   552,   140,   556,   141,   557,   142,
     558,   143,   559,   144,   145,   560,   516,   561,   562,   563,
     564,   256,   565,   566,   378,   567,   146,  1150,   568,   654,
     257,   147,   148,   149,   569,   150,   151,   152,   570,   571,
     153,  1151,   572,   583,   587,   602,   605,   607,  1286,  1152,
     609,   517,   258,   611,   614,   615,   259,   616,   617,   618,
     619,   620,   639,  1153,   260,  1287,   154,   261,   262,   472,
     621,   518,   622,   624,   625,   626,   155,   156,   157,   158,
     159,   160,   627,   628,   629,   630,   660,   519,   631,   632,
     633,   634,   635,   636,  1154,  1265,  1155,   640,   641,   263,
     642,   643,  1288,  1289,   520,   521,   644,   645,   161,   364,
     647,   365,   648,   366,   649,   650,   264,   651,  1117,   265,
     266,   267,  1156,   652,   653,   367,   656,   657,   162,   163,
     164,   661,   165,   166,   167,   662,   663,   666,   168,  1118,
     669,   368,   670,   169,   671,   672,   268,   673,  1119,   677,
     674,   522,   678,   680,  1290,  1157,   676,  1158,  1291,   681,
     685,   682,   683,   269,   686,   688,   369,   689,   370,   690,
     691,   692,   693,   523,   694,   371,  1159,   696,   695,  1120,
     699,   700,   701,   706,   707,   708,   372,   270,   271,   709,
     710,   712,   713,   716,   717,   741,  1160,   718,   742,   720,
     768,  1161,   771,  1206,   719,  1162,   734,   743,  1121,  1122,
     373,   721,  1163,   744,   749,   777,  1123,  1164,   723,   724,
     725,     2,     3,   726,   727,     4,   730,  1165,   731,   735,
    1166,   736,  1167,   738,   374,     5,   745,   746,     6,     7,
     750,  1124,   751,   753,  1168,     8,   754,   755,   756,   757,
     759,  1169,   779,   762,   375,   769,     9,  1125,   763,    10,
      11,   764,   327,   376,   765,  1207,   780,   770,   776,   781,
     772,   773,   774,   782,   778,   783,   328,   329,   784,   785,
     330,   790,   786,   787,   800,   788,   789,    12,   791,   792,
     793,   803,    13,   794,   795,   929,  1208,   930,   931,   796,
     802,    14,   806,  1209,   808,   801,   804,   837,   805,   377,
     811,   812,  1210,   813,   814,  1126,   815,   838,   816,   817,
     827,    15,    16,   828,   829,   830,   831,   832,   331,   833,
     834,   835,   836,   378,  1211,   841,  1212,  1213,  1177,    17,
    1178,  1179,   840,   842,   843,   332,   333,   334,   335,   336,
     845,  1214,   846,   337,   848,   849,    18,   338,  1215,   850,
     852,   855,   856,   339,   859,   863,   861,   866,   862,    19,
      20,   860,   864,   871,   340,   341,   906,   865,   867,   868,
     869,   870,   874,   872,   873,   876,   342,   877,   574,   976,
     975,    21,   978,   979,   875,   878,   879,   880,   980,   881,
     882,   883,   884,   885,    22,   886,   887,  1225,   343,   888,
     889,   890,    23,   932,   933,   934,    24,   935,   936,   891,
     937,   938,   892,   939,   977,   940,   893,   894,   941,   895,
     896,   942,   943,   897,   944,   898,   899,   900,   901,   945,
     902,   903,   904,   946,   947,   948,   905,   928,   344,   949,
     981,   953,   982,   954,   950,   955,  1180,  1181,  1182,   956,
    1183,  1184,   957,  1185,  1186,   958,  1187,   984,  1188,  1226,
     985,  1189,   987,   959,  1190,  1191,   988,  1192,   960,   990,
     996,   997,  1193,   999,  1000,  1002,  1194,  1195,  1196,  1003,
    1004,   961,  1197,   962,   907,   908,   909,  1198,   910,   911,
    1227,   912,   913,   963,   914,   964,   915,  1228,   965,   916,
      79,   966,   917,   918,   967,   919,  1229,   968,   989,   969,
     920,   970,   971,   972,   921,   922,   923,   973,   974,   983,
     924,    80,    81,   986,   993,   925,   994,    82,  1230,   995,
    1231,  1232,   998,  1001,  1005,  1008,  1006,  1007,  1009,  1010,
    1011,  1012,  1039,  1013,  1040,  1233,  1053,  1014,  1015,  1016,
    1017,  1018,  1234,  1055,  1251,  1019,  1020,  1021,  1022,   310,
    1023,  1024,    83,    84,  1143,  1025,  1026,  1027,    85,    86,
    1028,  1029,  1054,  1263,    87,    88,    89,  1223,  1030,  1031,
    1032,  1254,    90,    91,  1033,  1034,  1219,  1035,  1036,  1037,
    1038,  1041,  1042,  1052,  1056,  1064,  1065,  1066,  1071,  1072,
    1073,  1074,  1075,  1076,  1077,  1078,  1079,    92,    93,  1080,
    1081,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,
    1110,  1115,  1116,  1129,  1130,  1131,  1274,  1275,  1132,  1133,
    1134,  1276,   748,  1297,  1278,  1135,  1136,  1137,   761,  1277,
    1146,  1147,  1148,  1144,  1149,   638,  1172,  1173,  1174,  1175,
    1176,  1201,  1202,  1203,  1204,  1205,  1218,  1270,  1224,  1237,
    1220,  1273,  1253,   585,   740,  1255,  1267,  1266,  1256,  1280,
    1281,  1282,   505,   729,  1272,  1252,  1294,   799,   810,  1279,
     655,  1271,   733,   404,   659,   665,   463,  1245,  1246,   326,
     554,     0,     0,     0,     0,   767,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   589
};

static const yytype_int16 yycheck[] =
{
     635,   636,   315,     1,   317,     1,   319,   320,     1,     8,
     231,     1,     1,     1,     1,     1,    49,   231,     1,     1,
       1,   112,   211,     1,    22,    23,   215,     1,     1,     1,
      28,   211,     1,    29,     1,   215,     1,     1,    25,   231,
       1,    37,   229,     1,    53,    32,     9,    10,    11,   180,
     181,   229,     1,    49,    50,   233,     1,   229,    54,    55,
      56,   233,     1,   231,     1,    63,    64,     6,     7,   229,
     230,    69,    70,    12,     1,    65,     1,    75,    76,    77,
      58,    20,    21,    79,    65,    83,    84,    65,    27,    67,
      35,    30,    31,   231,     1,   231,    65,    36,    81,    81,
     413,   414,    41,    42,    65,    44,    45,    46,   421,    48,
     108,   109,   425,   102,   205,   102,   102,   430,    57,   128,
     433,   229,    61,    62,   231,   233,   231,    99,   102,   231,
     443,   444,   231,    72,   231,   102,    81,   102,   102,     1,
       1,   129,   455,    82,   102,   458,   459,     1,   126,   112,
      89,   123,    91,   102,    93,   231,    95,   190,    97,    98,
     129,   231,   129,    17,    25,   102,   229,   200,   129,   231,
     233,   110,    99,    35,     1,   231,   115,   116,   117,    33,
     119,   120,   121,   176,   129,   124,     1,   229,   231,   229,
      17,   233,   129,   176,   176,   102,   123,   231,    59,   231,
     231,   200,   231,   176,   129,   229,    33,    68,   229,   233,
      25,   150,   233,    67,   229,   231,   229,    32,   233,    81,
     233,   160,   161,   162,   163,   164,   165,   232,   232,    90,
     223,   220,   230,    94,   230,   224,   224,   230,   196,   552,
      67,   102,     1,   230,   105,   106,   220,   230,   102,   230,
     223,   127,   230,   192,     1,   220,    15,    16,   230,   224,
      19,   230,   220,   230,   232,   230,   230,   129,   122,   229,
     232,   220,   230,   212,   213,   214,   137,   216,   217,   218,
     232,   230,   229,   222,   138,   230,   233,   102,   227,   196,
       1,   230,     3,   154,     5,   122,   157,   158,   159,   224,
     232,   155,   156,   130,   131,   230,    17,   176,    67,   622,
     232,    58,   229,   220,   627,   229,   233,   630,    65,   232,
      67,   634,    33,   184,   151,    84,    85,    86,    87,    88,
     112,   232,   232,    92,   232,   232,     1,    96,   232,   232,
     201,   232,   232,   102,   232,     1,   232,    58,   202,    60,
     232,   232,    17,   232,   113,   114,    67,   139,   140,   141,
     142,   143,   144,   145,   225,   226,   125,    78,    33,   230,
     224,   112,   232,    29,   232,   232,   230,   232,   127,   126,
     232,    37,  1082,  1083,  1084,   232,   232,   232,   147,   232,
     232,   102,   232,    49,    50,   232,   232,   224,    54,    55,
      56,   232,    67,   230,   232,   112,   232,     1,   232,   232,
     232,   232,     6,     7,   232,   126,   232,   127,    12,   232,
     232,   232,   232,    79,   232,   232,    20,    21,   187,   232,
     232,   232,   232,    27,   232,   146,    30,    31,   232,   232,
       1,   232,    36,   232,   155,   232,   232,    41,    42,   232,
      44,    45,    46,     1,    48,   232,    17,   122,   232,   232,
      40,   232,   232,    57,   232,   130,   131,    61,    62,   232,
     232,   230,    33,   112,   232,   232,   232,    25,    72,   818,
     819,   820,   821,   822,   823,   824,   151,   232,    82,   232,
     201,    71,   232,    73,   232,    89,   232,    91,   232,    93,
     232,    95,   232,    97,    98,   232,    67,   232,   232,   232,
     232,    59,   232,   232,   225,   232,   110,     4,   232,   230,
      68,   115,   116,   117,   232,   119,   120,   121,   232,   232,
     124,    18,   232,   232,   232,   229,   211,   112,   118,    26,
     112,   102,    90,   112,   112,   112,    94,   211,   211,   229,
     229,   232,   229,    40,   102,   135,   150,   105,   106,   224,
     232,   122,   232,   232,   232,   232,   160,   161,   162,   163,
     164,   165,   232,   232,   232,   232,   127,   138,   232,   232,
     232,   232,   232,   232,    71,  1220,    73,   232,   232,   137,
     232,   232,   172,   173,   155,   156,   232,   232,   192,     1,
     232,     3,   232,     5,   232,   232,   154,   232,    13,   157,
     158,   159,    99,   232,   232,    17,   232,   232,   212,   213,
     214,   229,   216,   217,   218,   232,   232,   211,   222,    34,
     211,    33,   112,   227,   211,   112,   184,   127,    43,   112,
     211,   202,   112,   112,   224,   132,   211,   134,   228,   211,
     112,   211,   211,   201,   112,   112,    58,   112,    60,   112,
     112,   211,   232,   224,   211,    67,   153,   211,   232,    74,
     211,   211,   211,   211,   211,   211,    78,   225,   226,   127,
     112,   211,   211,   211,   211,   127,   173,   229,   127,   232,
     211,   178,   127,    73,   229,   182,   229,   229,   103,   104,
     102,   232,   189,   229,   229,   127,   111,   194,   232,   232,
     232,     0,     1,   232,   232,     4,   232,   204,   232,   232,
     207,   232,   209,   232,   126,    14,   232,   232,    17,    18,
     232,   136,   232,   232,   221,    24,   232,   232,   232,   232,
     232,   228,   127,   229,   146,   211,    35,   152,   232,    38,
      39,   232,     1,   155,   232,   135,   112,   211,   229,   112,
     211,   211,   211,   127,   211,   127,    15,    16,   127,   127,
      19,   112,   127,   127,   211,   127,   127,    66,   127,   127,
     127,   127,    71,   229,   229,    49,   166,    51,    52,   232,
     231,    80,   232,   173,   232,   229,   229,   112,   229,   201,
     229,   229,   182,   229,   229,   210,   229,   112,   229,   229,
     229,   100,   101,   229,   229,   229,   229,   229,    67,   229,
     229,   229,   229,   225,   204,   112,   206,   207,    49,   118,
      51,    52,   232,   112,   112,    84,    85,    86,    87,    88,
     112,   221,   112,    92,   127,   112,   135,    96,   228,   112,
     112,   229,   127,   102,   127,   232,   127,   112,   127,   148,
     149,   211,   127,   229,   113,   114,    49,   127,   127,   127,
     127,   127,   229,   127,   127,   127,   125,   127,   272,   211,
     127,   170,   127,   112,   229,   229,   229,   229,   127,   229,
     229,   229,   229,   229,   183,   229,   229,    73,   147,   229,
     229,   229,   191,   167,   168,   169,   195,   171,   172,   229,
     174,   175,   229,   177,   232,   179,   229,   229,   182,   229,
     229,   185,   186,   229,   188,   229,   229,   229,   229,   193,
     229,   229,   229,   197,   198,   199,   229,   229,   187,   203,
     127,   229,   127,   229,   208,   229,   167,   168,   169,   229,
     171,   172,   229,   174,   175,   229,   177,   127,   179,   135,
     127,   182,   127,   229,   185,   186,   127,   188,   229,   112,
     127,   127,   193,   127,   211,   127,   197,   198,   199,   127,
     127,   229,   203,   229,   167,   168,   169,   208,   171,   172,
     166,   174,   175,   229,   177,   229,   179,   173,   229,   182,
       1,   229,   185,   186,   229,   188,   182,   229,   232,   229,
     193,   229,   229,   229,   197,   198,   199,   229,   229,   229,
     203,    22,    23,   229,   229,   208,   229,    28,   204,   229,
     206,   207,   229,   232,   127,   127,   211,   232,   229,   127,
     127,   127,   127,   229,   232,   221,   127,   229,   229,   229,
     229,   229,   228,   127,   112,   229,   229,   229,   229,    74,
     229,   229,    63,    64,   219,   229,   229,   229,    69,    70,
     229,   229,   232,   127,    75,    76,    77,  1047,   229,   229,
     229,   234,    83,    84,   229,   229,   232,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   108,   109,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   133,   133,   229,   229,
     229,   133,   509,  1296,  1260,   229,   229,   229,   524,  1258,
     229,   229,   229,   233,   229,   345,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,  1239,   229,   229,
     232,  1250,   229,   294,   496,   234,   229,   232,   234,   229,
     229,   229,   228,   473,  1248,  1144,  1269,   578,   594,  1262,
     379,  1244,   486,   115,   398,   408,   170,  1112,  1114,    94,
     244,    -1,    -1,    -1,    -1,   540,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   301
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   236,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    66,    71,    80,   100,   101,   118,   135,   148,
     149,   170,   183,   191,   195,   237,   242,   247,   267,   273,
     279,   293,   313,   337,   351,   366,   373,   377,   387,   396,
     417,   423,   429,   433,   439,   498,   515,   229,   230,   231,
     231,   314,   397,   424,   231,   434,   231,   352,   418,   338,
     231,   274,   294,   367,   231,   231,   388,   231,   231,   378,
       1,    25,    32,   102,   268,   269,   270,   271,   272,     1,
      22,    23,    28,    63,    64,    69,    70,    75,    76,    77,
      83,    84,   108,   109,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     231,   231,   231,     1,    65,   430,   431,   432,   231,     1,
       6,     7,    12,    20,    21,    27,    30,    31,    36,    41,
      42,    44,    45,    46,    48,    57,    61,    62,    72,    82,
      89,    91,    93,    95,    97,    98,   110,   115,   116,   117,
     119,   120,   121,   124,   150,   160,   161,   162,   163,   164,
     165,   192,   212,   213,   214,   216,   217,   218,   222,   227,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   491,   495,
     496,   497,   231,   231,   231,     1,    99,   123,   243,   244,
     245,   246,   231,   231,   231,     1,    29,    37,    49,    50,
      54,    55,    56,    79,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,     1,    25,    59,    68,    90,    94,
     102,   105,   106,   137,   154,   157,   158,   159,   184,   201,
     225,   226,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   231,     1,   223,   280,   281,   282,   283,   284,     1,
     102,   374,   375,   376,   231,   229,   232,   232,   232,   230,
     269,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   230,   500,     1,    15,    16,
      19,    67,    84,    85,    86,    87,    88,    92,    96,   102,
     113,   114,   125,   147,   187,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,     1,     3,     5,    17,    33,    58,
      60,    67,    78,   102,   126,   146,   155,   201,   225,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     412,   413,   414,   415,   416,     1,    65,   129,   425,   426,
     427,   428,   232,   230,   431,     1,   102,   129,   435,   436,
     437,   438,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   492,
     232,   488,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   230,   441,     1,    17,    33,    67,   122,   130,
     131,   151,   224,   353,   354,   355,   356,   357,   358,   359,
     363,   364,   365,     1,   129,   224,   419,   420,   421,   422,
       1,    58,    65,    67,   126,   339,   343,   344,   345,   349,
     350,   229,   232,   232,   230,   244,     1,    81,   176,   275,
     276,   277,   278,     1,    17,    33,    67,   102,   122,   138,
     155,   156,   202,   224,   295,   296,   297,   298,   299,   300,
     301,   302,   303,   304,   305,   309,     1,    35,    81,   129,
     368,   369,   370,   371,   372,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   517,   229,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   249,     1,   102,   220,   389,   390,
     391,   392,   229,   232,   230,   281,   176,   232,   230,   375,
       1,   102,   220,   224,   379,   380,   381,   382,   383,   127,
     127,   127,   229,   112,   112,   211,   112,   112,   239,   112,
     239,   112,   239,   239,   112,   112,   211,   211,   229,   229,
     232,   232,   232,   334,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   316,   229,
     232,   232,   232,   232,   232,   232,   409,   232,   232,   232,
     232,   232,   232,   232,   230,   399,   232,   232,   230,   426,
     127,   229,   232,   232,   230,   436,   211,   239,   239,   211,
     112,   211,   112,   127,   211,   239,   211,   112,   112,   239,
     112,   211,   211,   211,   239,   112,   112,   239,   112,   112,
     112,   112,   211,   232,   211,   232,   211,   239,   239,   211,
     211,   211,   211,   215,   211,   215,   211,   211,   211,   127,
     112,   239,   211,   211,   239,   239,   211,   211,   229,   229,
     232,   232,   360,   232,   232,   232,   232,   232,   230,   354,
     232,   232,   230,   420,   229,   232,   232,   340,   232,   230,
     344,   127,   127,   229,   229,   232,   232,   230,   276,   229,
     232,   232,   310,   232,   232,   232,   232,   232,   306,   232,
     230,   296,   229,   232,   232,   232,   230,   369,   211,   211,
     211,   127,   211,   211,   211,   239,   229,   127,   211,   127,
     112,   112,   127,   127,   127,   127,   127,   127,   127,   127,
     112,   127,   127,   127,   229,   229,   232,   393,   230,   390,
     211,   229,   231,   127,   229,   229,   232,   384,   232,   230,
     380,   229,   229,   229,   229,   229,   229,   229,   139,   140,
     141,   142,   143,   144,   145,   238,   239,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   112,   112,   239,
     232,   112,   112,   112,   239,   112,   112,   239,   127,   112,
     112,   239,   112,   241,   241,   229,   127,   180,   181,   127,
     211,   127,   127,   232,   127,   127,   112,   127,   127,   127,
     127,   229,   127,   127,   229,   229,   127,   127,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    49,   167,   168,   169,
     171,   172,   174,   175,   177,   179,   182,   185,   186,   188,
     193,   197,   198,   199,   203,   208,   493,   494,   229,    49,
      51,    52,   167,   168,   169,   171,   172,   174,   175,   177,
     179,   182,   185,   186,   188,   193,   197,   198,   199,   203,
     208,   489,   490,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   127,   211,   232,   127,   112,
     127,   127,   127,   229,   127,   127,   229,   127,   127,   232,
     112,   347,   348,   229,   229,   229,   127,   127,   229,   127,
     211,   232,   127,   127,   127,   127,   211,   232,   127,   229,
     127,   127,   127,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   127,
     232,   229,   229,     1,   102,   196,   220,   285,   286,   287,
     288,   289,   229,   127,   232,   127,   229,   238,   238,   238,
     238,   238,   238,   238,   229,   229,   229,    53,   128,   335,
     336,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,     9,    10,    11,   240,   241,   229,   229,   229,
     229,   229,   229,   229,   229,   229,     8,   200,   410,   411,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   233,   229,   233,   229,   229,    13,    34,    43,
      74,   103,   104,   111,   136,   152,   210,   361,   362,   229,
     229,   229,   229,   229,   229,   229,   229,   229,    49,   190,
     200,   341,   342,   219,   233,   346,   229,   229,   229,   229,
       4,    18,    26,    40,    71,    73,    99,   132,   134,   153,
     173,   178,   182,   189,   194,   204,   207,   209,   221,   228,
     311,   312,   229,   229,   229,   229,   229,    49,    51,    52,
     167,   168,   169,   171,   172,   174,   175,   177,   179,   182,
     185,   186,   188,   193,   197,   198,   199,   203,   208,   307,
     308,   229,   229,   229,   229,   229,    73,   135,   166,   173,
     182,   204,   206,   207,   221,   228,   394,   395,   229,   232,
     232,   290,   230,   286,   229,    73,   135,   166,   173,   182,
     204,   206,   207,   221,   228,   385,   386,   229,   229,   233,
     240,   240,   240,   229,   233,   494,   490,   229,   233,   229,
     233,   112,   348,   229,   234,   234,   234,   229,   233,   229,
     233,   229,   233,   127,   205,   241,   232,   229,   229,   233,
     336,   411,   362,   342,   133,   133,   133,   312,   308,   395,
     229,   229,   229,    40,    71,    73,   118,   135,   172,   173,
     224,   228,   291,   292,   386,   229,   233,   292
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
     249,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   268,   269,   269,   269,   269,   270,   271,   272,   274,
     273,   275,   275,   276,   276,   276,   277,   278,   279,   280,
     280,   281,   281,   281,   282,   284,   283,   285,   285,   286,
     286,   286,   286,   287,   288,   288,   290,   289,   291,   291,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   294,
     293,   295,   295,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   306,   305,   307,   307,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   310,   309,
     311,   311,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   314,   313,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   334,   333,   335,   335,   336,   336,   338,
     337,   340,   339,   341,   341,   342,   342,   342,   343,   343,
     344,   344,   344,   344,   344,   346,   345,   347,   347,   348,
     348,   349,   350,   352,   351,   353,   353,   354,   354,   354,
     354,   354,   354,   354,   354,   354,   355,   356,   357,   358,
     360,   359,   361,   361,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   363,   364,   365,   367,   366,   368,
     368,   369,   369,   369,   369,   370,   371,   372,   373,   374,
     374,   375,   375,   376,   378,   377,   379,   379,   380,   380,
     380,   380,   381,   382,   384,   383,   385,   385,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   388,   387,
     389,   389,   390,   390,   390,   391,   393,   392,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     397,   396,   398,   398,   399,   399,   399,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   407,   409,   408,
     410,   410,   411,   411,   412,   413,   414,   415,   416,   418,
     417,   419,   419,   420,   420,   420,   421,   422,   424,   423,
     425,   425,   426,   426,   426,   427,   428,   429,   430,   430,
     431,   431,   432,   434,   433,   435,   435,   436,   436,   436,
     437,   438,   439,   440,   440,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   468,   469,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   488,   487,   489,   489,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   492,
     491,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   495,   496,   497,   498,   499,   499,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     516,   517,   517,   517,   517,   517,   517,   517,   517,   517,
     518,   519,   520,   521,   522,   523,   524,   525
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
#line 409 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 411 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 72:
#line 474 "conf_parser.y" /* yacc.c:1646  */
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
#line 2978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 516 "conf_parser.y" /* yacc.c:1646  */
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
#line 3039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 574 "conf_parser.y" /* yacc.c:1646  */
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
#line 3070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 602 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 610 "conf_parser.y" /* yacc.c:1646  */
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
#line 3098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 624 "conf_parser.y" /* yacc.c:1646  */
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
#line 3129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 652 "conf_parser.y" /* yacc.c:1646  */
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

  case 79:
#line 667 "conf_parser.y" /* yacc.c:1646  */
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

  case 80:
#line 682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 691 "conf_parser.y" /* yacc.c:1646  */
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
#line 3194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 705 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 714 "conf_parser.y" /* yacc.c:1646  */
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

  case 84:
#line 742 "conf_parser.y" /* yacc.c:1646  */
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

  case 85:
#line 772 "conf_parser.y" /* yacc.c:1646  */
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

  case 86:
#line 797 "conf_parser.y" /* yacc.c:1646  */
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

  case 87:
#line 819 "conf_parser.y" /* yacc.c:1646  */
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

  case 88:
#line 841 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 892 "conf_parser.y" /* yacc.c:1646  */
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

  case 106:
#line 909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 915 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 116:
#line 940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 964 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 125:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 126:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 135:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
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

  case 154:
#line 1114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1132 "conf_parser.y" /* yacc.c:1646  */
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

  case 158:
#line 1143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
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

  case 161:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
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
#line 4195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
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
#line 4248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 237:
#line 1455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4257 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 238:
#line 1461 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 239:
#line 1467 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 240:
#line 1473 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 241:
#line 1479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 242:
#line 1485 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 243:
#line 1491 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1497 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1503 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4329 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1565 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1595 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1607 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1612 "conf_parser.y" /* yacc.c:1646  */
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

  case 280:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
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

  case 281:
#line 1644 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
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

  case 296:
#line 1712 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1724 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
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

  case 300:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1748 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1752 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1756 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 307:
#line 1760 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 308:
#line 1764 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 309:
#line 1768 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1776 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1780 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1790 "conf_parser.y" /* yacc.c:1646  */
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

  case 315:
#line 1804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
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

  case 334:
#line 1886 "conf_parser.y" /* yacc.c:1646  */
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

  case 335:
#line 1897 "conf_parser.y" /* yacc.c:1646  */
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

  case 342:
#line 1914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1920 "conf_parser.y" /* yacc.c:1646  */
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

  case 344:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1958 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1966 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1970 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1982 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
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

  case 365:
#line 2015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2073 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
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

  case 399:
#line 2162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2168 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2174 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 402:
#line 2180 "conf_parser.y" /* yacc.c:1646  */
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

  case 403:
#line 2193 "conf_parser.y" /* yacc.c:1646  */
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

  case 404:
#line 2206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2222 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2230 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2246 "conf_parser.y" /* yacc.c:1646  */
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

  case 415:
#line 2257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
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

  case 419:
#line 2290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2294 "conf_parser.y" /* yacc.c:1646  */
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

  case 426:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
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

  case 427:
#line 2339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2352 "conf_parser.y" /* yacc.c:1646  */
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

  case 435:
#line 2378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2398 "conf_parser.y" /* yacc.c:1646  */
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

  case 443:
#line 2415 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2419 "conf_parser.y" /* yacc.c:1646  */
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

  case 450:
#line 2441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 506:
#line 2513 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 507:
#line 2518 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 508:
#line 2524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2536 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2542 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2547 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2552 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2557 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2562 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5657 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2567 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2572 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
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

  case 526:
#line 2624 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2629 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_connect_block = yylval.number;
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2634 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2639 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2644 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2649 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2654 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2690 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2705 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2720 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_count = (yyvsp[-1].number);
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDECHANS;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3064 "conf_parser.y" /* yacc.c:1646  */
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
#line 6522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6540 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6544 "conf_parser.c" /* yacc.c:1646  */
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
