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
#line 25 "conf_parser.y" /* yacc.c:339  */


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
#include "s_serv.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"
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
  struct {
    dlink_list list;
  } mask,
    leaf,
    hub;

  struct {
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

  struct {
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


#line 181 "conf_parser.c" /* yacc.c:339  */

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
    HIDE_IDLE_FROM_OPERS = 306,
    HIDE_SERVER_IPS = 307,
    HIDE_SERVERS = 308,
    HIDE_SERVICES = 309,
    HIDE_SPOOF_IPS = 310,
    HOST = 311,
    HUB = 312,
    HUB_MASK = 313,
    IGNORE_BOGUS_TS = 314,
    INVISIBLE_ON_CONNECT = 315,
    IP = 316,
    IRCD_AUTH = 317,
    IRCD_FLAGS = 318,
    IRCD_SID = 319,
    JOIN_FLOOD_COUNT = 320,
    JOIN_FLOOD_TIME = 321,
    KILL = 322,
    KILL_CHASE_TIME_LIMIT = 323,
    KLINE = 324,
    KLINE_EXEMPT = 325,
    KNOCK_DELAY = 326,
    KNOCK_DELAY_CHANNEL = 327,
    LEAF_MASK = 328,
    LINKS_DELAY = 329,
    LISTEN = 330,
    MASK = 331,
    MAX_ACCEPT = 332,
    MAX_BANS = 333,
    MAX_CHANS_PER_OPER = 334,
    MAX_CHANS_PER_USER = 335,
    MAX_GLOBAL = 336,
    MAX_IDENT = 337,
    MAX_IDLE = 338,
    MAX_LOCAL = 339,
    MAX_NICK_CHANGES = 340,
    MAX_NICK_LENGTH = 341,
    MAX_NICK_TIME = 342,
    MAX_NUMBER = 343,
    MAX_TARGETS = 344,
    MAX_TOPIC_LENGTH = 345,
    MAX_WATCH = 346,
    MIN_IDLE = 347,
    MIN_NONWILDCARD = 348,
    MIN_NONWILDCARD_SIMPLE = 349,
    MODULE = 350,
    MODULES = 351,
    MOTD = 352,
    NAME = 353,
    NEED_IDENT = 354,
    NEED_PASSWORD = 355,
    NETWORK_DESC = 356,
    NETWORK_NAME = 357,
    NICK = 358,
    NO_CREATE_ON_SPLIT = 359,
    NO_JOIN_ON_SPLIT = 360,
    NO_OPER_FLOOD = 361,
    NO_TILDE = 362,
    NUMBER = 363,
    NUMBER_PER_CIDR = 364,
    NUMBER_PER_IP = 365,
    OPER_ONLY_UMODES = 366,
    OPER_PASS_RESV = 367,
    OPER_UMODES = 368,
    OPERATOR = 369,
    OPERS_BYPASS_CALLERID = 370,
    PACE_WAIT = 371,
    PACE_WAIT_SIMPLE = 372,
    PASSWORD = 373,
    PATH = 374,
    PING_COOKIE = 375,
    PING_TIME = 376,
    PORT = 377,
    QSTRING = 378,
    RANDOM_IDLE = 379,
    REASON = 380,
    REDIRPORT = 381,
    REDIRSERV = 382,
    REHASH = 383,
    REMOTE = 384,
    REMOTEBAN = 385,
    RESV = 386,
    RESV_EXEMPT = 387,
    RSA_PRIVATE_KEY_FILE = 388,
    RSA_PUBLIC_KEY_FILE = 389,
    SECONDS = 390,
    MINUTES = 391,
    HOURS = 392,
    DAYS = 393,
    WEEKS = 394,
    MONTHS = 395,
    YEARS = 396,
    SEND_PASSWORD = 397,
    SENDQ = 398,
    SERVERHIDE = 399,
    SERVERINFO = 400,
    SHORT_MOTD = 401,
    SPOOF = 402,
    SPOOF_NOTICE = 403,
    SQUIT = 404,
    SSL_CERTIFICATE_FILE = 405,
    SSL_CERTIFICATE_FINGERPRINT = 406,
    SSL_CONNECTION_REQUIRED = 407,
    SSL_DH_PARAM_FILE = 408,
    STATS_E_DISABLED = 409,
    STATS_I_OPER_ONLY = 410,
    STATS_K_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BOTS = 416,
    T_CALLERID = 417,
    T_CCONN = 418,
    T_CLUSTER = 419,
    T_DEAF = 420,
    T_DEBUG = 421,
    T_DLINE = 422,
    T_EXTERNAL = 423,
    T_FARCONNECT = 424,
    T_FILE = 425,
    T_FULL = 426,
    T_GLOBOPS = 427,
    T_INVISIBLE = 428,
    T_IPV4 = 429,
    T_IPV6 = 430,
    T_LOCOPS = 431,
    T_LOG = 432,
    T_MAX_CLIENTS = 433,
    T_NCHANGE = 434,
    T_NONONREG = 435,
    T_OPERWALL = 436,
    T_RECVQ = 437,
    T_REJ = 438,
    T_RESTART = 439,
    T_SERVER = 440,
    T_SERVICE = 441,
    T_SERVICES_NAME = 442,
    T_SERVNOTICE = 443,
    T_SET = 444,
    T_SHARED = 445,
    T_SIZE = 446,
    T_SKILL = 447,
    T_SOFTCALLERID = 448,
    T_SPY = 449,
    T_SSL = 450,
    T_SSL_CIPHER_LIST = 451,
    T_SSL_CLIENT_METHOD = 452,
    T_SSL_SERVER_METHOD = 453,
    T_SSLV3 = 454,
    T_TLSV1 = 455,
    T_UMODES = 456,
    T_UNAUTH = 457,
    T_UNDLINE = 458,
    T_UNLIMITED = 459,
    T_UNRESV = 460,
    T_UNXLINE = 461,
    T_WALLOP = 462,
    T_WALLOPS = 463,
    T_WEBIRC = 464,
    TBOOL = 465,
    THROTTLE_TIME = 466,
    TKLINE_EXPIRE_NOTICES = 467,
    TMASKED = 468,
    TRUE_NO_OPER_FLOOD = 469,
    TS_MAX_DELTA = 470,
    TS_WARN_DELTA = 471,
    TWODOTS = 472,
    TYPE = 473,
    UNKLINE = 474,
    USE_EGD = 475,
    USE_LOGGING = 476,
    USER = 477,
    VHOST = 478,
    VHOST6 = 479,
    WARN_NO_NLINE = 480,
    XLINE = 481
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
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define IRCD_AUTH 317
#define IRCD_FLAGS 318
#define IRCD_SID 319
#define JOIN_FLOOD_COUNT 320
#define JOIN_FLOOD_TIME 321
#define KILL 322
#define KILL_CHASE_TIME_LIMIT 323
#define KLINE 324
#define KLINE_EXEMPT 325
#define KNOCK_DELAY 326
#define KNOCK_DELAY_CHANNEL 327
#define LEAF_MASK 328
#define LINKS_DELAY 329
#define LISTEN 330
#define MASK 331
#define MAX_ACCEPT 332
#define MAX_BANS 333
#define MAX_CHANS_PER_OPER 334
#define MAX_CHANS_PER_USER 335
#define MAX_GLOBAL 336
#define MAX_IDENT 337
#define MAX_IDLE 338
#define MAX_LOCAL 339
#define MAX_NICK_CHANGES 340
#define MAX_NICK_LENGTH 341
#define MAX_NICK_TIME 342
#define MAX_NUMBER 343
#define MAX_TARGETS 344
#define MAX_TOPIC_LENGTH 345
#define MAX_WATCH 346
#define MIN_IDLE 347
#define MIN_NONWILDCARD 348
#define MIN_NONWILDCARD_SIMPLE 349
#define MODULE 350
#define MODULES 351
#define MOTD 352
#define NAME 353
#define NEED_IDENT 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NO_CREATE_ON_SPLIT 359
#define NO_JOIN_ON_SPLIT 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP 365
#define OPER_ONLY_UMODES 366
#define OPER_PASS_RESV 367
#define OPER_UMODES 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PORT 377
#define QSTRING 378
#define RANDOM_IDLE 379
#define REASON 380
#define REDIRPORT 381
#define REDIRSERV 382
#define REHASH 383
#define REMOTE 384
#define REMOTEBAN 385
#define RESV 386
#define RESV_EXEMPT 387
#define RSA_PRIVATE_KEY_FILE 388
#define RSA_PUBLIC_KEY_FILE 389
#define SECONDS 390
#define MINUTES 391
#define HOURS 392
#define DAYS 393
#define WEEKS 394
#define MONTHS 395
#define YEARS 396
#define SEND_PASSWORD 397
#define SENDQ 398
#define SERVERHIDE 399
#define SERVERINFO 400
#define SHORT_MOTD 401
#define SPOOF 402
#define SPOOF_NOTICE 403
#define SQUIT 404
#define SSL_CERTIFICATE_FILE 405
#define SSL_CERTIFICATE_FINGERPRINT 406
#define SSL_CONNECTION_REQUIRED 407
#define SSL_DH_PARAM_FILE 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BOTS 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_CLUSTER 419
#define T_DEAF 420
#define T_DEBUG 421
#define T_DLINE 422
#define T_EXTERNAL 423
#define T_FARCONNECT 424
#define T_FILE 425
#define T_FULL 426
#define T_GLOBOPS 427
#define T_INVISIBLE 428
#define T_IPV4 429
#define T_IPV6 430
#define T_LOCOPS 431
#define T_LOG 432
#define T_MAX_CLIENTS 433
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPERWALL 436
#define T_RECVQ 437
#define T_REJ 438
#define T_RESTART 439
#define T_SERVER 440
#define T_SERVICE 441
#define T_SERVICES_NAME 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_SKILL 447
#define T_SOFTCALLERID 448
#define T_SPY 449
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_SSL_CLIENT_METHOD 452
#define T_SSL_SERVER_METHOD 453
#define T_SSLV3 454
#define T_TLSV1 455
#define T_UMODES 456
#define T_UNAUTH 457
#define T_UNDLINE 458
#define T_UNLIMITED 459
#define T_UNRESV 460
#define T_UNXLINE 461
#define T_WALLOP 462
#define T_WALLOPS 463
#define T_WEBIRC 464
#define TBOOL 465
#define THROTTLE_TIME 466
#define TKLINE_EXPIRE_NOTICES 467
#define TMASKED 468
#define TRUE_NO_OPER_FLOOD 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_EGD 475
#define USE_LOGGING 476
#define USER 477
#define VHOST 478
#define VHOST6 479
#define WARN_NO_NLINE 480
#define XLINE 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 140 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 678 "conf_parser.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 693 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1233

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1288

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

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
       2,     2,     2,     2,   231,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   232,   227,
       2,   230,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,     2,   228,     2,     2,     2,     2,
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
     225,   226
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   370,   370,   371,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   400,   400,   401,
     405,   409,   413,   417,   421,   425,   429,   435,   435,   436,
     437,   438,   439,   446,   449,   449,   450,   450,   450,   452,
     458,   465,   467,   467,   468,   468,   469,   469,   470,   470,
     471,   471,   472,   472,   473,   473,   474,   474,   475,   475,
     476,   477,   480,   481,   483,   483,   484,   490,   498,   498,
     499,   505,   513,   555,   613,   641,   649,   664,   679,   688,
     702,   711,   739,   769,   794,   816,   838,   847,   849,   849,
     850,   850,   851,   851,   853,   862,   871,   884,   883,   901,
     901,   902,   902,   902,   904,   910,   919,   920,   920,   922,
     922,   923,   925,   932,   932,   945,   946,   948,   948,   949,
     949,   951,   959,   962,   968,   967,   973,   973,   974,   978,
     982,   986,   990,   994,   998,  1002,  1006,  1017,  1016,  1096,
    1096,  1097,  1097,  1097,  1098,  1098,  1098,  1099,  1099,  1100,
    1101,  1101,  1103,  1109,  1115,  1121,  1132,  1138,  1144,  1155,
    1162,  1161,  1167,  1167,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1196,  1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,
    1232,  1236,  1240,  1244,  1248,  1255,  1254,  1260,  1260,  1261,
    1265,  1269,  1273,  1277,  1281,  1285,  1289,  1293,  1297,  1301,
    1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,  1337,  1341,
    1345,  1349,  1353,  1364,  1363,  1424,  1424,  1425,  1426,  1426,
    1427,  1428,  1429,  1430,  1431,  1432,  1433,  1434,  1435,  1435,
    1436,  1437,  1438,  1439,  1441,  1447,  1453,  1459,  1465,  1471,
    1477,  1483,  1489,  1495,  1502,  1508,  1514,  1520,  1529,  1539,
    1538,  1544,  1544,  1545,  1549,  1560,  1559,  1566,  1565,  1570,
    1570,  1571,  1575,  1579,  1585,  1585,  1586,  1586,  1586,  1586,
    1586,  1588,  1588,  1590,  1590,  1592,  1606,  1626,  1632,  1642,
    1641,  1683,  1683,  1684,  1684,  1684,  1684,  1685,  1685,  1685,
    1686,  1686,  1688,  1694,  1700,  1706,  1718,  1717,  1723,  1723,
    1724,  1728,  1732,  1736,  1740,  1744,  1748,  1752,  1756,  1760,
    1766,  1780,  1789,  1803,  1802,  1817,  1817,  1818,  1818,  1818,
    1818,  1820,  1826,  1832,  1842,  1844,  1844,  1845,  1845,  1847,
    1863,  1862,  1887,  1887,  1888,  1888,  1888,  1888,  1890,  1896,
    1916,  1915,  1921,  1921,  1922,  1926,  1930,  1934,  1938,  1942,
    1946,  1950,  1954,  1958,  1968,  1967,  1988,  1988,  1989,  1989,
    1989,  1991,  1998,  1997,  2003,  2003,  2004,  2008,  2012,  2016,
    2020,  2024,  2028,  2032,  2036,  2040,  2050,  2049,  2121,  2121,
    2122,  2122,  2122,  2123,  2123,  2124,  2125,  2125,  2125,  2126,
    2126,  2126,  2127,  2127,  2128,  2130,  2136,  2142,  2148,  2161,
    2174,  2180,  2186,  2190,  2199,  2198,  2203,  2203,  2204,  2208,
    2214,  2225,  2231,  2237,  2243,  2259,  2258,  2284,  2284,  2285,
    2285,  2285,  2287,  2307,  2317,  2316,  2343,  2343,  2344,  2344,
    2344,  2346,  2352,  2361,  2363,  2363,  2364,  2364,  2366,  2384,
    2383,  2406,  2406,  2407,  2407,  2407,  2409,  2415,  2424,  2427,
    2427,  2428,  2428,  2429,  2429,  2430,  2430,  2431,  2431,  2432,
    2432,  2433,  2434,  2435,  2435,  2436,  2436,  2437,  2437,  2438,
    2438,  2439,  2440,  2440,  2441,  2441,  2442,  2442,  2443,  2443,
    2444,  2444,  2445,  2445,  2446,  2446,  2447,  2447,  2448,  2449,
    2450,  2450,  2451,  2451,  2452,  2453,  2454,  2455,  2455,  2456,
    2457,  2460,  2465,  2471,  2477,  2483,  2489,  2494,  2499,  2504,
    2509,  2514,  2519,  2524,  2529,  2534,  2539,  2544,  2549,  2554,
    2560,  2571,  2576,  2581,  2586,  2591,  2596,  2601,  2604,  2609,
    2612,  2617,  2622,  2627,  2632,  2637,  2642,  2647,  2652,  2657,
    2662,  2667,  2672,  2681,  2690,  2695,  2700,  2706,  2705,  2710,
    2710,  2711,  2714,  2717,  2720,  2723,  2726,  2729,  2732,  2735,
    2738,  2741,  2744,  2747,  2750,  2753,  2756,  2759,  2762,  2765,
    2768,  2771,  2777,  2776,  2781,  2781,  2782,  2785,  2788,  2791,
    2794,  2797,  2800,  2803,  2806,  2809,  2812,  2815,  2818,  2821,
    2824,  2827,  2830,  2833,  2836,  2839,  2842,  2847,  2852,  2857,
    2866,  2869,  2869,  2870,  2871,  2871,  2872,  2872,  2873,  2874,
    2875,  2876,  2877,  2877,  2878,  2878,  2880,  2885,  2890,  2895,
    2900,  2905,  2910,  2915,  2920,  2925,  2930,  2935,  2943,  2946,
    2946,  2947,  2947,  2948,  2949,  2950,  2951,  2951,  2952,  2953,
    2955,  2961,  2967,  2973,  2979,  2988,  3002,  3008
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
  "HIDDEN_NAME", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "IRCD_AUTH",
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
  "WARN_NO_NLINE", "XLINE", "';'", "'}'", "'{'", "'='", "','", "':'",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_client_method",
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
  "general_warn_no_nline", "general_stats_e_disabled",
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
     475,   476,   477,   478,   479,   480,   481,    59,   125,   123,
      61,    44,    58
};
# endif

#define YYPACT_NINF -755

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-755)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -755,   717,  -755,  -198,  -223,  -208,  -755,  -755,  -755,  -186,
    -755,  -184,  -755,  -755,  -755,  -179,  -755,  -755,  -755,  -168,
    -154,  -755,  -146,  -123,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   282,
     963,   -84,   -59,   -46,   130,   -45,   414,   -39,   -26,   -19,
      79,   -18,   -11,    21,   503,   408,    40,    39,    53,    41,
     -14,    -1,    64,    66,     7,  -755,  -755,  -755,  -755,  -755,
      81,    82,    96,   100,   102,   104,   105,   117,   119,   121,
     127,   128,    13,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   723,   577,    61,  -755,
     131,    10,  -755,  -755,    36,  -755,   132,   133,   135,   139,
     141,   142,   143,   144,   146,   148,   151,   153,   157,   158,
     160,   162,   164,   165,   166,   168,   170,   180,   182,   183,
     187,   188,   189,  -755,   192,  -755,   193,   195,   197,   199,
     200,   201,   202,   206,   207,   208,   209,   212,   213,   216,
     217,   219,   221,   222,   223,   108,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   353,     8,   292,    29,
     227,   231,    24,  -755,  -755,  -755,    22,   546,    47,  -755,
     236,   237,   240,   246,   248,   251,   253,   254,    15,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,    60,   255,
     257,   259,   260,   262,   263,   265,   266,   272,   288,   291,
     294,   303,   305,   306,   307,   308,     9,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,     4,    65,   309,    19,  -755,
    -755,  -755,   155,  -755,   313,    23,  -755,  -755,    62,  -755,
     215,   352,   365,   270,  -755,   252,   436,   335,   438,   440,
     440,   440,   443,   451,   454,   355,   356,   340,  -755,   347,
     346,   351,   354,  -755,   357,   358,   360,   362,   366,   367,
     368,   369,   370,   372,   373,   377,   258,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,   381,   382,   383,   384,   385,   386,
     387,  -755,   388,   390,   391,   392,   393,   394,   397,   326,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   406,   407,    69,  -755,
    -755,  -755,   460,   411,  -755,  -755,   412,   413,    48,  -755,
    -755,  -755,   375,   440,   440,   401,   487,   431,   537,   523,
     437,   440,   439,   540,   543,   440,   547,   446,   447,   448,
     440,   551,   552,   440,   553,   554,   555,   557,   456,   441,
     457,   442,   458,   440,   440,   459,   464,   466,    58,    95,
     467,   468,   469,   558,   440,   472,   473,   440,   440,   474,
     475,   461,  -755,   462,   463,   465,  -755,   471,   476,   477,
     479,   480,   163,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,   481,   482,    50,  -755,  -755,  -755,   489,
     484,   490,  -755,   492,  -755,    25,  -755,  -755,  -755,  -755,
    -755,   563,   564,   496,  -755,   498,   499,   506,    18,  -755,
    -755,  -755,   510,   515,   516,  -755,   518,   519,   527,   528,
     529,  -755,   531,    14,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,   513,   532,   533,   534,    11,
    -755,  -755,  -755,  -755,   493,   494,   544,   567,   556,   559,
     560,   440,   526,  -755,  -755,   569,   561,   571,   562,   594,
     603,   642,   644,   649,   651,   652,   668,   654,   -99,   -42,
     655,   657,   566,  -755,   568,   572,  -755,    73,  -755,  -755,
    -755,  -755,   573,   570,  -755,   565,   658,   574,  -755,   581,
     579,  -755,   582,    27,  -755,  -755,  -755,  -755,   589,   590,
     591,  -755,   592,   593,   595,   596,   267,   597,   598,   599,
     600,   601,   602,   607,   608,  -755,  -755,   674,   677,   440,
     606,   680,   683,   440,   690,   691,   440,   707,   729,   732,
     440,   733,   733,   615,  -755,  -755,   720,   129,   728,   646,
     731,   735,   629,   745,   746,   762,   748,   750,   751,   752,
     653,  -755,   756,   759,   656,  -755,   660,  -755,   761,   765,
     662,  -755,   663,   665,   666,   669,   670,   671,   672,   675,
     679,   687,   692,   694,   695,   697,   698,   704,   705,   706,
     710,   711,   715,   716,   719,   721,   730,   738,   740,   684,
     741,   747,   749,   753,   754,   760,   763,   766,   767,   771,
     772,   773,   774,   775,   776,   777,   778,   779,   780,   781,
     782,   783,   784,  -755,  -755,   788,   685,   714,   794,   793,
     811,   824,   827,   785,  -755,   837,   839,   786,  -755,  -755,
     854,   856,   787,   796,   789,  -755,   791,   792,  -755,  -755,
     866,   873,   795,  -755,  -755,   891,   805,   797,   897,   898,
     900,   901,   815,   800,   903,   804,  -755,  -755,   909,   910,
     913,   810,  -755,   812,   813,   817,   818,   819,   820,   821,
     822,  -755,   823,   825,   826,   828,   829,   830,   831,   832,
     833,   834,   835,   836,   838,  -755,  -755,  -209,  -755,  -755,
    -755,  -189,  -755,   842,   843,  -755,  -755,   915,   841,   845,
    -755,   846,  -755,    26,   847,  -755,  -755,   928,   848,   931,
     849,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   440,
     440,   440,   440,   440,   440,   440,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   850,   852,   853,   -34,
     855,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     289,   867,   868,  -755,   869,   870,   871,   872,   874,   875,
     876,     5,   877,   878,   879,   880,   881,   882,   883,  -755,
     884,   885,  -755,  -755,   886,   887,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -174,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -172,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   888,   889,   245,   890,   892,   893,   894,   895,
    -755,   896,   899,  -755,   902,   904,   -16,   907,   844,  -755,
    -755,  -755,  -755,   905,   906,  -755,   908,   911,   524,   912,
     914,   916,   917,   918,   790,   919,  -755,   920,   921,   922,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,   -99,  -755,   -42,  -755,  -755,   923,   584,
    -755,  -755,   924,   851,   925,  -755,    57,  -755,  -755,  -755,
    -755,  -755,   926,   769,   927,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -171,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     733,   733,   733,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -155,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     684,  -755,   747,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,   -50,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -49,
    -755,   956,   796,   929,  -755,  -755,  -755,  -755,  -755,   930,
    -755,  -755,   932,  -755,  -755,  -755,  -755,   933,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -23,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,   -15,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,     0,  -755,  -755,   943,
    -101,   936,   934,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,    30,  -755,  -755,  -755,   -34,
    -755,  -755,  -755,  -755,     5,  -755,  -755,  -755,   245,  -755,
     -16,  -755,  -755,  -755,   954,   964,   971,  -755,   524,  -755,
     790,  -755,   584,   940,   941,   942,   297,  -755,  -755,   769,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,    55,  -755,  -755,  -755,   297,  -755
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   625,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   624,   614,   615,   616,   617,   613,
     618,   619,   620,   621,   622,   623,     0,     0,     0,   447,
       0,     0,   445,   446,     0,   510,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   582,     0,   557,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   460,   507,   509,   501,
     502,   503,   504,   505,   500,   471,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   497,   472,   473,   506,
     475,   480,   481,   476,   478,   477,   491,   492,   479,   482,
     483,   484,   485,   474,   487,   488,   489,   508,   498,   499,
     496,   490,   486,   494,   495,   493,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,   649,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   640,
     641,   642,   643,   644,   647,   645,   646,   648,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    68,    69,
      67,    64,    63,    70,    54,    66,    57,    58,    59,    55,
      65,    60,    61,    62,    56,     0,     0,     0,     0,   118,
     119,   120,     0,   338,     0,     0,   336,   337,     0,   103,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,     0,
       0,     0,     0,   259,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   226,   227,   230,
     232,   233,   234,   235,   236,   237,   238,   239,   228,   229,
     231,   240,   241,   242,     0,     0,     0,     0,     0,     0,
       0,   414,     0,     0,     0,     0,     0,     0,     0,     0,
     389,   390,   391,   392,   393,   394,   395,   397,   396,   399,
     403,   400,   401,   402,   398,   440,     0,     0,     0,   437,
     438,   439,     0,     0,   444,   455,     0,     0,     0,   452,
     453,   454,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   459,     0,     0,     0,   306,     0,     0,     0,
       0,     0,     0,   292,   293,   294,   295,   300,   296,   297,
     298,   299,   431,     0,     0,     0,   428,   429,   430,     0,
       0,     0,   267,     0,   277,     0,   275,   276,   278,   279,
      48,     0,     0,     0,    44,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   195,     0,     0,     0,     0,
       0,   170,     0,     0,   150,   151,   152,   153,   156,   157,
     158,   159,   155,   154,   160,     0,     0,     0,     0,     0,
     326,   327,   328,   329,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   639,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   372,     0,   367,   368,
     369,   121,     0,     0,   117,     0,     0,     0,   335,     0,
       0,   350,     0,     0,   343,   344,   345,   346,     0,     0,
       0,    97,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,   610,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   404,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   388,     0,     0,     0,   436,     0,   443,     0,     0,
       0,   451,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   458,   301,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   291,     0,     0,     0,   427,   280,
       0,     0,     0,     0,     0,   274,     0,     0,    43,   113,
       0,     0,     0,   109,   161,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   330,     0,     0,
       0,     0,   325,     0,     0,     0,     0,     0,     0,     0,
       0,   638,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,    75,    80,
      81,     0,    79,     0,     0,    51,   370,     0,     0,     0,
     366,     0,   116,     0,     0,   334,   347,     0,     0,     0,
       0,   342,   106,   105,   104,   633,   632,   626,   636,    27,
      27,    27,    27,    27,    27,    27,    29,    28,   637,   627,
     628,   631,   630,   629,   634,   635,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   387,
       0,     0,   435,   448,     0,     0,   450,   523,   527,   542,
     512,   609,   555,   549,   552,   522,   514,   513,   516,   517,
     515,   530,   520,   521,   531,   519,   526,   525,   524,   550,
     511,   607,   608,   546,   592,   586,   603,   587,   588,   589,
     597,   606,   590,   600,   604,   593,   605,   598,   594,   599,
     591,   602,   596,   595,   601,     0,   585,   548,   566,   561,
     578,   562,   563,   564,   572,   581,   565,   575,   579,   568,
     580,   573,   569,   574,   567,   577,   571,   570,   576,     0,
     560,   543,   541,   544,   554,   545,   533,   539,   540,   537,
     538,   534,   535,   536,   553,   556,   518,   547,   529,   528,
     551,   532,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   426,     0,     0,     0,   285,   281,   284,
     266,    49,    50,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
     324,   651,   650,   656,   654,   657,   652,   653,   655,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     365,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   339,     0,     0,     0,   341,    30,    31,    32,    33,
      34,    35,    36,   254,   255,   247,   264,   263,     0,   262,
     249,   251,   258,   250,   248,   257,   244,   256,   246,   245,
      37,    37,    37,    39,    38,   252,   253,   409,   412,   413,
     423,   420,   406,   421,   418,   419,     0,   417,   422,   405,
     411,   408,   410,   424,   407,   441,   442,   456,   457,   583,
       0,   558,     0,   304,   305,   314,   311,   316,   312,   313,
     319,   315,   317,   310,   318,     0,   309,   303,   322,   321,
     320,   302,   433,   432,   288,   287,   272,   273,   271,     0,
     270,     0,     0,     0,   114,   115,   169,   165,   215,   202,
     212,   211,   200,   205,   222,   214,   220,   204,   207,   217,
     219,   216,   213,   221,   208,   210,   218,   206,   209,     0,
     198,   162,   164,   166,   167,   168,   179,   174,   191,   175,
     176,   177,   185,   194,   178,   188,   192,   181,   193,   186,
     182,   187,   180,   190,   184,   183,   189,     0,   173,   163,
     333,   331,   332,    74,    78,   371,   376,   382,   385,   378,
     384,   379,   383,   381,   377,   380,     0,   375,   130,     0,
       0,     0,     0,   125,   348,   354,   360,   363,   356,   362,
     357,   361,   359,   355,   358,     0,   353,   349,   260,     0,
      40,    41,    42,   415,     0,   584,   559,   307,     0,   268,
       0,   286,   283,   282,     0,     0,     0,   196,     0,   171,
       0,   373,     0,     0,     0,     0,     0,   124,   351,     0,
     261,   416,   308,   269,   201,   199,   203,   197,   172,   374,
     131,   133,   132,   140,   145,   144,   139,   142,   146,   143,
     138,   141,     0,   137,   352,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -755,  -755,  -755,  -298,  -307,  -754,  -621,  -755,  -755,   935,
    -755,  -755,  -755,  -755,   619,  -755,  -755,  -755,   107,  -755,
      93,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  1051,  -755,
    -755,  -755,  -755,  -755,  -755,   630,  -755,  -755,  -755,  -755,
     937,  -755,  -755,  -755,  -755,    91,  -755,  -755,  -755,  -755,
    -755,  -152,  -755,  -755,  -755,   623,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -113,  -755,  -755,
    -755,  -108,  -755,  -755,  -755,   806,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,   -77,  -755,  -755,  -755,  -755,  -755,
     -82,  -755,   678,  -755,  -755,  -755,    28,  -755,  -755,  -755,
    -755,  -755,   708,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     -79,  -755,  -755,  -755,  -755,  -755,  -755,   643,  -755,  -755,
    -755,  -755,  -755,   938,  -755,  -755,  -755,  -755,   588,  -755,
    -755,  -755,  -755,  -755,   -86,  -755,  -755,  -755,   609,  -755,
    -755,  -755,  -755,   -78,  -755,  -755,  -755,   808,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -56,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   700,  -755,
    -755,  -755,  -755,  -755,   798,  -755,  -755,  -755,  -755,  1068,
    -755,  -755,  -755,  -755,   799,  -755,  -755,  -755,  -755,  1015,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,    80,  -755,  -755,
    -755,    83,  -755,  -755,  -755,  -755,  -755,  1089,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   946,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   816,   817,  1073,  1074,    26,   222,   223,
     224,   225,    27,   266,   267,   268,   269,   777,   778,   781,
     782,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,    28,    74,    75,    76,
      77,    78,    29,    61,   498,   499,   500,   501,    30,   288,
     289,   290,   291,   292,  1036,  1037,  1038,  1039,  1040,  1211,
    1282,  1283,    31,    62,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   743,  1187,  1188,   524,   737,
    1159,  1160,    32,    51,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   610,  1058,  1059,    33,    59,   484,   722,  1129,
    1130,   485,   486,   487,  1133,   978,   979,   488,   489,    34,
      57,   462,   463,   464,   465,   466,   467,   468,   707,  1115,
    1116,   469,   470,   471,    35,    63,   529,   530,   531,   532,
     533,    36,   295,   296,   297,    37,    69,   583,   584,   585,
     586,   587,   798,  1225,  1226,    38,    66,   567,   568,   569,
     570,   788,  1206,  1207,    39,    52,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   632,  1086,  1087,
     380,   381,   382,   383,   384,    40,    58,   475,   476,   477,
     478,    41,    53,   388,   389,   390,   391,    42,   111,   112,
     113,    43,    55,   398,   399,   400,   401,    44,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   431,   939,   940,   212,   429,
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
     841,   842,   597,   598,   599,   564,    49,   840,    70,   472,
     248,   109,   525,  1084,    79,   502,   229,  1056,  1022,   495,
     286,    50,  1023,   495,   293,   219,   479,  1032,   579,    47,
      48,   503,    71,  1126,   249,    80,    81,   395,  1024,    72,
     286,    82,  1025,    54,   230,    56,   526,   504,   525,   395,
      60,   472,   231,  1099,   293,  1101,  1228,  1100,  1032,  1102,
    1229,    64,   385,   579,   232,   233,   250,   234,   235,   236,
     385,   110,  1233,   251,   564,    65,  1234,   505,    83,    84,
     219,   480,   526,    67,    85,    86,   481,   527,   482,   237,
    1057,    87,    88,    89,   496,   252,   653,   654,   496,   253,
     775,   776,   565,  1254,   661,    73,    68,   254,   665,   115,
     255,   256,   506,   670,   116,   117,   673,    90,    91,   220,
     118,   294,   386,   527,  1033,   580,   683,   684,   119,   120,
     386,   109,   507,   473,   396,   121,   528,   696,   122,   123,
     699,   700,   257,   221,   124,   106,   396,   483,   508,   125,
     126,   294,   127,   128,   129,  1033,   130,   779,   780,   258,
     580,   397,   259,   131,   453,   509,   510,   132,   133,  1127,
     107,   565,   528,   397,   220,   473,   134,  1237,  1239,  1128,
     454,  1238,  1240,   108,   114,   135,   387,   260,   497,  -123,
     216,   110,   497,   136,   387,   137,   455,   138,   221,   139,
    1085,   140,   141,   217,  1247,   261,   262,   263,  1248,  -123,
     218,   226,  1249,   299,   142,   511,  1250,  1034,   227,   143,
     144,   145,   566,   146,   147,   148,   456,  1251,   149,   300,
     474,  1252,   264,   265,   760,   303,   512,   562,   393,   751,
     287,   317,   745,   542,  1035,   581,   732,   573,  1034,   582,
     228,   577,   493,   724,   150,   800,   490,  1258,  1105,   319,
     287,  1259,   151,   152,   153,   154,   155,   156,   688,   285,
     298,   689,   474,   320,   321,  1035,   650,   322,   717,  1106,
     581,   457,  1285,    70,   582,  1212,  1286,   544,  1107,   458,
     459,   566,   571,   479,   301,   157,   302,   644,  1070,  1071,
    1072,   789,   828,   845,   846,   690,   832,    71,   691,   835,
     460,   305,   306,   839,    72,  1108,  1230,  1231,  1232,   158,
     159,   323,   160,   161,   162,   575,   307,   354,   163,   355,
     308,   356,   309,   164,   310,   311,   451,  1273,   588,   324,
     325,   326,   327,   357,  1109,  1110,   328,   312,   480,   313,
     329,   314,  1111,   481,   453,   482,   330,   315,   316,   358,
     592,   392,   402,   403,  1274,   404,  1275,   331,   332,   405,
     454,   406,   407,   408,   409,   596,   410,  1112,   411,   333,
      73,   412,   359,   413,   360,   461,   455,   414,   415,   361,
     416,   713,   417,  1113,   418,   419,   420,   840,   421,   362,
     422,   334,   809,   810,   811,   812,   813,   814,   815,   248,
     423,  1276,   424,   425,   483,   115,   456,   426,   427,   428,
     116,   117,   430,   432,   363,   433,   118,   434,  1277,   435,
     436,   437,   438,   249,   119,   120,   439,   440,   441,   442,
     335,   121,   443,   444,   122,   123,   445,   446,   364,   447,
     124,   448,   449,   450,  1114,   125,   126,   491,   127,   128,
     129,   492,   130,  1278,  1279,   250,   534,   535,   365,   131,
     536,   457,   251,   132,   133,   589,   537,   366,   538,   458,
     459,   539,   134,   540,   541,   545,   623,   546,   590,   547,
     548,   135,   549,   550,   252,   551,   552,   591,   253,   136,
     460,   137,   553,   138,   229,   139,   254,   140,   141,   255,
     256,  1046,  1047,  1048,  1049,  1050,  1051,  1052,   554,  1280,
     142,   555,   367,  1281,   556,   143,   144,   145,  1138,   146,
     147,   148,   230,   557,   149,   558,   559,   560,   561,   572,
     231,   257,  1139,   576,   593,   594,   595,   502,   596,   368,
    1140,   600,   232,   233,   640,   234,   235,   236,   258,   601,
     150,   259,   602,   503,  1141,   603,   604,   605,   151,   152,
     153,   154,   155,   156,   606,   461,   607,   237,   354,   504,
     355,   608,   356,   646,   609,   652,   260,   611,   612,  1255,
     613,  1142,   614,  1143,   357,   656,   615,   616,   617,   618,
     619,   157,   620,   621,   261,   262,   263,   622,   625,   505,
     358,   655,   626,   627,   628,   629,   630,   631,   633,  1144,
     634,   635,   636,   637,   638,   158,   159,   639,   160,   161,
     162,   264,   265,   359,   163,   360,   642,   643,   647,   164,
     361,   657,   648,   649,   506,   658,   659,   660,   663,   662,
     362,   664,  1145,  1196,  1146,   666,   667,   668,   669,   671,
     672,   674,   675,   676,   507,   677,   678,   680,   682,   685,
     765,   679,   681,  1147,   686,   363,   687,   692,   693,   694,
     508,   695,   697,   698,   701,   702,   726,   727,   703,   704,
     756,  1148,   762,   705,   764,   706,  1149,   509,   510,   364,
    1150,   708,   766,   753,   754,  1151,   709,   710,  1152,   711,
     712,   715,   716,  1153,   720,  1197,   719,     2,     3,   365,
     721,     4,   723,   728,   319,   729,   767,  1154,   366,   730,
    1155,     5,  1156,   894,     6,     7,   731,   734,   320,   321,
     747,     8,   322,  1157,  1198,   735,   736,   511,   738,   739,
    1158,  1199,     9,   761,   755,    10,    11,   740,   741,   742,
    1200,   744,   748,   749,   750,   768,   757,   769,   512,   758,
     759,   763,   770,   367,   771,   772,   773,   774,   783,    12,
     784,   794,   826,   791,    13,   827,   323,  1201,   830,  1202,
    1203,   831,    14,   785,   793,   786,   918,   792,   833,   834,
     368,   795,   787,  1204,   324,   325,   326,   327,   796,   797,
    1205,   328,   799,    15,    16,   329,   802,   803,   804,   805,
     806,   330,   807,   808,   818,   819,   820,   821,   822,   823,
     836,    17,   331,   332,   824,   825,   829,   837,  1215,  1166,
     838,   840,   843,   844,   333,   895,   896,   897,    18,   898,
     899,   847,   900,   901,   849,   902,   848,   903,   850,   851,
     904,    19,    20,   905,   906,   907,   334,   908,   852,   853,
     854,   855,   909,   856,   857,   858,   910,   911,   912,   860,
     859,    21,   861,   862,   864,   563,   913,   863,   865,   866,
     867,   914,   868,   869,    22,   963,   870,   871,   872,   873,
    1216,   966,   874,    23,   977,   335,   875,    24,   919,   920,
     921,   962,   922,   923,   876,   924,   925,   965,   926,   877,
     927,   878,   879,   928,   880,   881,   929,   930,   931,  1217,
     932,   882,   883,   884,   967,   933,  1218,   885,   886,   934,
     935,   936,   887,   888,   964,  1219,   889,   968,   890,   937,
     969,  1167,  1168,  1169,   938,  1170,  1171,   891,  1172,  1173,
     971,  1174,   972,  1175,    79,   892,  1176,   893,   917,  1177,
    1178,  1179,  1220,  1180,  1221,  1222,   941,   974,  1181,   975,
     942,   943,  1182,  1183,  1184,    80,    81,   944,  1223,   983,
     945,    82,  1185,   946,   947,  1224,   984,  1186,   948,   949,
     950,   951,   952,   953,   954,   955,   956,   957,   958,   959,
     960,   961,   970,   973,   986,   987,   980,   976,   981,   982,
     989,   990,   985,   991,   992,   993,   995,   988,    83,    84,
     994,   996,   997,   998,    85,    86,   999,  1000,  1028,  1001,
    1002,    87,    88,    89,  1003,  1004,  1005,  1006,  1007,  1008,
    1009,  1042,  1010,  1011,  1044,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1241,  1021,  1253,    90,    91,  1026,
    1027,  1029,  1030,  1031,  1041,  1132,  1045,  1053,  1043,  1054,
    1055,  1209,  1060,  1264,  1061,  1062,  1063,  1064,  1065,  1066,
    1067,  1068,  1069,  1265,  1075,  1076,  1077,  1078,  1079,  1080,
    1266,  1081,  1082,  1083,  1088,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1103,  1104,  1117,  1194,  1118,
    1119,  1120,  1121,  1122,  1131,   304,  1123,  1213,   733,  1124,
    1193,  1125,  1134,  1135,  1287,  1136,   746,  1268,  1137,  1161,
    1267,  1162,   624,  1163,  1164,  1165,  1189,  1190,  1191,  1192,
    1195,  1208,  1260,  1214,  1227,  1210,  1243,   494,  1263,  1262,
    1242,  1257,  1244,   725,  1245,  1246,  1256,  1270,  1271,  1272,
     714,   801,   752,  1284,  1269,   718,   790,   641,  1261,   394,
     452,   318,  1236,  1235,   543,     0,   645,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   651,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,     0,     0,
       0,     0,     0,   578
};

static const yytype_int16 yycheck[] =
{
     621,   622,   309,   310,   311,     1,   229,   108,     1,     1,
       1,     1,     1,     8,     1,     1,     1,    51,   227,     1,
       1,   229,   231,     1,     1,     1,     1,     1,     1,   227,
     228,    17,    25,    49,    25,    22,    23,     1,   227,    32,
       1,    28,   231,   229,    29,   229,    35,    33,     1,     1,
     229,     1,    37,   227,     1,   227,   227,   231,     1,   231,
     231,   229,     1,     1,    49,    50,    57,    52,    53,    54,
       1,    61,   227,    64,     1,   229,   231,    63,    65,    66,
       1,    56,    35,   229,    71,    72,    61,    76,    63,    74,
     124,    78,    79,    80,    76,    86,   403,   404,    76,    90,
     199,   200,    98,   204,   411,    98,   229,    98,   415,     1,
     101,   102,    98,   420,     6,     7,   423,   104,   105,    95,
      12,    98,    61,    76,    98,    98,   433,   434,    20,    21,
      61,     1,   118,   125,    98,    27,   125,   444,    30,    31,
     447,   448,   133,   119,    36,   229,    98,   122,   134,    41,
      42,    98,    44,    45,    46,    98,    48,   199,   200,   150,
      98,   125,   153,    55,     1,   151,   152,    59,    60,   185,
     229,    98,   125,   125,    95,   125,    68,   227,   227,   195,
      17,   231,   231,   229,   229,    77,   125,   178,   170,   170,
     229,    61,   170,    85,   125,    87,    33,    89,   119,    91,
     195,    93,    94,   229,   227,   196,   197,   198,   231,   170,
     229,   229,   227,   227,   106,   201,   231,   191,   229,   111,
     112,   113,   218,   115,   116,   117,    63,   227,   120,   230,
     222,   231,   223,   224,   541,   228,   222,   228,   228,   228,
     221,   228,   228,   228,   218,   218,   228,   228,   191,   222,
     229,   228,   228,   228,   146,   228,   227,   227,    13,     1,
     221,   231,   154,   155,   156,   157,   158,   159,   210,   229,
     229,   213,   222,    15,    16,   218,   228,    19,   228,    34,
     218,   118,   227,     1,   222,   228,   231,   227,    43,   126,
     127,   218,   227,     1,   230,   187,   230,   228,     9,    10,
      11,   228,   609,   174,   175,   210,   613,    25,   213,   616,
     147,   230,   230,   620,    32,    70,  1070,  1071,  1072,   211,
     212,    63,   214,   215,   216,   170,   230,     1,   220,     3,
     230,     5,   230,   225,   230,   230,   228,    40,   123,    81,
      82,    83,    84,    17,    99,   100,    88,   230,    56,   230,
      92,   230,   107,    61,     1,    63,    98,   230,   230,    33,
     108,   230,   230,   230,    67,   230,    69,   109,   110,   230,
      17,   230,   230,   230,   230,   108,   230,   132,   230,   121,
      98,   230,    56,   230,    58,   222,    33,   230,   230,    63,
     230,   228,   230,   148,   230,   230,   230,   108,   230,    73,
     230,   143,   135,   136,   137,   138,   139,   140,   141,     1,
     230,   114,   230,   230,   122,     1,    63,   230,   230,   230,
       6,     7,   230,   230,    98,   230,    12,   230,   131,   230,
     230,   230,   230,    25,    20,    21,   230,   230,   230,   230,
     182,    27,   230,   230,    30,    31,   230,   230,   122,   230,
      36,   230,   230,   230,   209,    41,    42,   230,    44,    45,
      46,   230,    48,   166,   167,    57,   230,   230,   142,    55,
     230,   118,    64,    59,    60,   123,   230,   151,   230,   126,
     127,   230,    68,   230,   230,   230,   228,   230,   123,   230,
     230,    77,   230,   230,    86,   230,   230,   227,    90,    85,
     147,    87,   230,    89,     1,    91,    98,    93,    94,   101,
     102,   809,   810,   811,   812,   813,   814,   815,   230,   222,
     106,   230,   196,   226,   230,   111,   112,   113,     4,   115,
     116,   117,    29,   230,   120,   230,   230,   230,   230,   230,
      37,   133,    18,   230,   108,   210,   108,     1,   108,   223,
      26,   108,    49,    50,   228,    52,    53,    54,   150,   108,
     146,   153,   108,    17,    40,   210,   210,   227,   154,   155,
     156,   157,   158,   159,   227,   222,   230,    74,     1,    33,
       3,   230,     5,   123,   230,   210,   178,   230,   230,  1210,
     230,    67,   230,    69,    17,   108,   230,   230,   230,   230,
     230,   187,   230,   230,   196,   197,   198,   230,   227,    63,
      33,   210,   230,   230,   230,   230,   230,   230,   230,    95,
     230,   230,   230,   230,   230,   211,   212,   230,   214,   215,
     216,   223,   224,    56,   220,    58,   230,   230,   227,   225,
      63,   210,   230,   230,    98,   108,   123,   210,   108,   210,
      73,   108,   128,    69,   130,   108,   210,   210,   210,   108,
     108,   108,   108,   108,   118,   108,   210,   210,   210,   210,
     108,   230,   230,   149,   210,    98,   210,   210,   210,   210,
     134,   123,   210,   210,   210,   210,   123,   123,   227,   227,
     123,   167,   123,   230,   123,   230,   172,   151,   152,   122,
     176,   230,   108,   210,   210,   181,   230,   230,   184,   230,
     230,   230,   230,   189,   230,   131,   227,     0,     1,   142,
     230,     4,   230,   227,     1,   227,   123,   203,   151,   230,
     206,    14,   208,    49,    17,    18,   230,   227,    15,    16,
     227,    24,    19,   219,   160,   230,   230,   201,   230,   230,
     226,   167,    35,   227,   210,    38,    39,   230,   230,   230,
     176,   230,   230,   230,   230,   123,   210,   123,   222,   210,
     210,   210,   123,   196,   123,   123,   108,   123,   123,    62,
     123,   123,   108,   210,    67,   108,    63,   203,   108,   205,
     206,   108,    75,   227,   229,   227,    49,   227,   108,   108,
     223,   227,   230,   219,    81,    82,    83,    84,   227,   230,
     226,    88,   230,    96,    97,    92,   227,   227,   227,   227,
     227,    98,   227,   227,   227,   227,   227,   227,   227,   227,
     123,   114,   109,   110,   227,   227,   230,   108,    69,    49,
     108,   108,   227,   123,   121,   161,   162,   163,   131,   165,
     166,   123,   168,   169,   123,   171,   210,   173,   123,   230,
     176,   144,   145,   179,   180,   181,   143,   183,   123,   123,
     108,   123,   188,   123,   123,   123,   192,   193,   194,   123,
     227,   164,   123,   227,   123,   266,   202,   227,   123,   227,
     227,   207,   227,   227,   177,   210,   227,   227,   227,   227,
     131,   108,   227,   186,   108,   182,   227,   190,   161,   162,
     163,   123,   165,   166,   227,   168,   169,   123,   171,   227,
     173,   227,   227,   176,   227,   227,   179,   180,   181,   160,
     183,   227,   227,   227,   123,   188,   167,   227,   227,   192,
     193,   194,   227,   227,   230,   176,   227,   123,   227,   202,
     123,   161,   162,   163,   207,   165,   166,   227,   168,   169,
     123,   171,   123,   173,     1,   227,   176,   227,   227,   179,
     180,   181,   203,   183,   205,   206,   227,   123,   188,   123,
     227,   227,   192,   193,   194,    22,    23,   227,   219,   123,
     227,    28,   202,   227,   227,   226,   123,   207,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   123,   210,   227,   230,   227,   227,
     123,   123,   227,   123,   123,   210,   123,   230,    65,    66,
     230,   227,   123,   123,    71,    72,   123,   227,   123,   227,
     227,    78,    79,    80,   227,   227,   227,   227,   227,   227,
     227,   123,   227,   227,   123,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   108,   227,   123,   104,   105,   227,
     227,   230,   227,   227,   227,   231,   227,   227,   230,   227,
     227,   230,   227,   129,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   129,   227,   227,   227,   227,   227,   227,
     129,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,  1025,   227,
     227,   227,   227,   227,   217,    74,   227,  1036,   498,   227,
    1023,   227,   227,   227,  1286,   227,   513,  1250,   227,   227,
    1248,   227,   336,   227,   227,   227,   227,   227,   227,   227,
     227,   227,  1229,   227,   227,   230,   227,   222,  1240,  1238,
    1132,   227,   232,   485,   232,   232,   230,   227,   227,   227,
     462,   583,   529,  1259,  1252,   475,   567,   369,  1234,   111,
     165,    92,  1102,  1100,   238,    -1,   388,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   295
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   234,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    62,    67,    75,    96,    97,   114,   131,   144,
     145,   164,   177,   186,   190,   235,   240,   245,   269,   275,
     281,   295,   315,   338,   352,   367,   374,   378,   388,   397,
     418,   424,   430,   434,   440,   498,   513,   227,   228,   229,
     229,   316,   398,   425,   229,   435,   229,   353,   419,   339,
     229,   276,   296,   368,   229,   229,   389,   229,   229,   379,
       1,    25,    32,    98,   270,   271,   272,   273,   274,     1,
      22,    23,    28,    65,    66,    71,    72,    78,    79,    80,
     104,   105,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   229,   229,   229,     1,
      61,   431,   432,   433,   229,     1,     6,     7,    12,    20,
      21,    27,    30,    31,    36,    41,    42,    44,    45,    46,
      48,    55,    59,    60,    68,    77,    85,    87,    89,    91,
      93,    94,   106,   111,   112,   113,   115,   116,   117,   120,
     146,   154,   155,   156,   157,   158,   159,   187,   211,   212,
     214,   215,   216,   220,   225,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   491,   495,   496,   497,   229,   229,   229,     1,
      95,   119,   241,   242,   243,   244,   229,   229,   229,     1,
      29,    37,    49,    50,    52,    53,    54,    74,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,     1,    25,
      57,    64,    86,    90,    98,   101,   102,   133,   150,   153,
     178,   196,   197,   198,   223,   224,   246,   247,   248,   249,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   229,     1,   221,   282,   283,
     284,   285,   286,     1,    98,   375,   376,   377,   229,   227,
     230,   230,   230,   228,   271,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   228,   500,     1,
      15,    16,    19,    63,    81,    82,    83,    84,    88,    92,
      98,   109,   110,   121,   143,   182,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,     1,     3,     5,    17,    33,    56,
      58,    63,    73,    98,   122,   142,   151,   196,   223,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     413,   414,   415,   416,   417,     1,    61,   125,   426,   427,
     428,   429,   230,   228,   432,     1,    98,   125,   436,   437,
     438,   439,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   492,
     230,   488,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   228,   442,     1,    17,    33,    63,   118,   126,   127,
     147,   222,   354,   355,   356,   357,   358,   359,   360,   364,
     365,   366,     1,   125,   222,   420,   421,   422,   423,     1,
      56,    61,    63,   122,   340,   344,   345,   346,   350,   351,
     227,   230,   230,   228,   242,     1,    76,   170,   277,   278,
     279,   280,     1,    17,    33,    63,    98,   118,   134,   151,
     152,   201,   222,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   311,     1,    35,    76,   125,   369,
     370,   371,   372,   373,   230,   230,   230,   230,   230,   230,
     230,   230,   228,   515,   227,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   228,   247,     1,    98,   218,   390,   391,   392,
     393,   227,   230,   228,   283,   170,   230,   228,   376,     1,
      98,   218,   222,   380,   381,   382,   383,   384,   123,   123,
     123,   227,   108,   108,   210,   108,   108,   237,   237,   237,
     108,   108,   108,   210,   210,   227,   227,   230,   230,   230,
     335,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   228,   318,   227,   230,   230,   230,   230,
     230,   230,   410,   230,   230,   230,   230,   230,   230,   230,
     228,   400,   230,   230,   228,   427,   123,   227,   230,   230,
     228,   437,   210,   237,   237,   210,   108,   210,   108,   123,
     210,   237,   210,   108,   108,   237,   108,   210,   210,   210,
     237,   108,   108,   237,   108,   108,   108,   108,   210,   230,
     210,   230,   210,   237,   237,   210,   210,   210,   210,   213,
     210,   213,   210,   210,   210,   123,   237,   210,   210,   237,
     237,   210,   210,   227,   227,   230,   230,   361,   230,   230,
     230,   230,   230,   228,   355,   230,   230,   228,   421,   227,
     230,   230,   341,   230,   228,   345,   123,   123,   227,   227,
     230,   230,   228,   278,   227,   230,   230,   312,   230,   230,
     230,   230,   230,   308,   230,   228,   298,   227,   230,   230,
     230,   228,   370,   210,   210,   210,   123,   210,   210,   210,
     237,   227,   123,   210,   123,   108,   108,   123,   123,   123,
     123,   123,   123,   108,   123,   199,   200,   250,   251,   199,
     200,   252,   253,   123,   123,   227,   227,   230,   394,   228,
     391,   210,   227,   229,   123,   227,   227,   230,   385,   230,
     228,   381,   227,   227,   227,   227,   227,   227,   227,   135,
     136,   137,   138,   139,   140,   141,   236,   237,   227,   227,
     227,   227,   227,   227,   227,   227,   108,   108,   237,   230,
     108,   108,   237,   108,   108,   237,   123,   108,   108,   237,
     108,   239,   239,   227,   123,   174,   175,   123,   210,   123,
     123,   230,   123,   123,   108,   123,   123,   123,   123,   227,
     123,   123,   227,   227,   123,   123,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,    49,   161,   162,   163,   165,   166,
     168,   169,   171,   173,   176,   179,   180,   181,   183,   188,
     192,   193,   194,   202,   207,   493,   494,   227,    49,   161,
     162,   163,   165,   166,   168,   169,   171,   173,   176,   179,
     180,   181,   183,   188,   192,   193,   194,   202,   207,   489,
     490,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   123,   210,   230,   123,   108,   123,   123,   123,
     227,   123,   123,   227,   123,   123,   230,   108,   348,   349,
     227,   227,   227,   123,   123,   227,   123,   210,   230,   123,
     123,   123,   123,   210,   230,   123,   227,   123,   123,   123,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   231,   227,   231,   227,   227,   123,   230,
     227,   227,     1,    98,   191,   218,   287,   288,   289,   290,
     291,   227,   123,   230,   123,   227,   236,   236,   236,   236,
     236,   236,   236,   227,   227,   227,    51,   124,   336,   337,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
       9,    10,    11,   238,   239,   227,   227,   227,   227,   227,
     227,   227,   227,   227,     8,   195,   411,   412,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     231,   227,   231,   227,   227,    13,    34,    43,    70,    99,
     100,   107,   132,   148,   209,   362,   363,   227,   227,   227,
     227,   227,   227,   227,   227,   227,    49,   185,   195,   342,
     343,   217,   231,   347,   227,   227,   227,   227,     4,    18,
      26,    40,    67,    69,    95,   128,   130,   149,   167,   172,
     176,   181,   184,   189,   203,   206,   208,   219,   226,   313,
     314,   227,   227,   227,   227,   227,    49,   161,   162,   163,
     165,   166,   168,   169,   171,   173,   176,   179,   180,   181,
     183,   188,   192,   193,   194,   202,   207,   309,   310,   227,
     227,   227,   227,   251,   253,   227,    69,   131,   160,   167,
     176,   203,   205,   206,   219,   226,   395,   396,   227,   230,
     230,   292,   228,   288,   227,    69,   131,   160,   167,   176,
     203,   205,   206,   219,   226,   386,   387,   227,   227,   231,
     238,   238,   238,   227,   231,   494,   490,   227,   231,   227,
     231,   108,   349,   227,   232,   232,   232,   227,   231,   227,
     231,   227,   231,   123,   204,   239,   230,   227,   227,   231,
     337,   412,   363,   343,   129,   129,   129,   314,   310,   396,
     227,   227,   227,    40,    67,    69,   114,   131,   166,   167,
     222,   226,   293,   294,   387,   227,   231,   294
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   233,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   236,   236,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   238,   239,
     239,   239,   239,   240,   241,   241,   242,   242,   242,   243,
     244,   245,   246,   246,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   248,   249,   250,   250,   251,   251,   252,   252,
     253,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   270,
     271,   271,   271,   271,   272,   273,   274,   276,   275,   277,
     277,   278,   278,   278,   279,   280,   281,   282,   282,   283,
     283,   283,   284,   286,   285,   287,   287,   288,   288,   288,
     288,   289,   290,   290,   292,   291,   293,   293,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   296,   295,   297,
     297,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     308,   307,   309,   309,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   312,   311,   313,   313,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   316,   315,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   335,
     334,   336,   336,   337,   337,   339,   338,   341,   340,   342,
     342,   343,   343,   343,   344,   344,   345,   345,   345,   345,
     345,   347,   346,   348,   348,   349,   349,   350,   351,   353,
     352,   354,   354,   355,   355,   355,   355,   355,   355,   355,
     355,   355,   356,   357,   358,   359,   361,   360,   362,   362,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     364,   365,   366,   368,   367,   369,   369,   370,   370,   370,
     370,   371,   372,   373,   374,   375,   375,   376,   376,   377,
     379,   378,   380,   380,   381,   381,   381,   381,   382,   383,
     385,   384,   386,   386,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   389,   388,   390,   390,   391,   391,
     391,   392,   394,   393,   395,   395,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   398,   397,   399,   399,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   408,   410,   409,   411,   411,   412,   412,
     413,   414,   415,   416,   417,   419,   418,   420,   420,   421,
     421,   421,   422,   423,   425,   424,   426,   426,   427,   427,
     427,   428,   429,   430,   431,   431,   432,   432,   433,   435,
     434,   436,   436,   437,   437,   437,   438,   439,   440,   441,
     441,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   469,   470,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   488,   487,   489,
     489,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   492,   491,   493,   493,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   495,   496,   497,
     498,   499,   499,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     514,   515,   515,   515,   515,   515,   515,   515,   515,   515,
     516,   517,   518,   519,   520,   521,   522,   523
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
       1,     1,     1,     1,     1,     0,     5,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
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
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
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
#line 400 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 402 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
#line 2835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 406 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
#line 2843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 410 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
#line 2851 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
#line 2859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
#line 2875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    {
                        (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number);
                }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    {
                        (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number);
                }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 435 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 436 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 437 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 438 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 485 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 491 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 500 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 506 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 514 "conf_parser.y" /* yacc.c:1646  */
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
#line 3028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 556 "conf_parser.y" /* yacc.c:1646  */
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
#line 3089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 614 "conf_parser.y" /* yacc.c:1646  */
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
#line 3120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 642 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 650 "conf_parser.y" /* yacc.c:1646  */
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
#line 3149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 665 "conf_parser.y" /* yacc.c:1646  */
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
#line 3167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 680 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 689 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 703 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 712 "conf_parser.y" /* yacc.c:1646  */
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
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 740 "conf_parser.y" /* yacc.c:1646  */
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
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
#line 3272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 770 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ServerInfo.max_clients = (yyvsp[-1].number);
}
#line 3300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 795 "conf_parser.y" /* yacc.c:1646  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ServerInfo.max_nick_length = NICKLEN;
  }
  else
    ServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 817 "conf_parser.y" /* yacc.c:1646  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 872 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 884 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 888 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
#line 3421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 905 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 952 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 963 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1024 "conf_parser.y" /* yacc.c:1646  */
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
#line 3675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1104 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3702 "conf_parser.c" /* yacc.c:1646  */
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
#line 3716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1133 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3734 "conf_parser.c" /* yacc.c:1646  */
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
#line 3748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1156 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1169 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1177 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1193 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
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
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
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
#line 4249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1490 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1503 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1521 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1530 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1539 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1546 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1560 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1593 "conf_parser.y" /* yacc.c:1646  */
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
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1607 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1627 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1633 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
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
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1695 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1701 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1707 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 306:
#line 1718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1729 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1737 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1741 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1749 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1753 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1757 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1761 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1767 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
#line 4735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1781 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1790 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1803 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1874 "conf_parser.y" /* yacc.c:1646  */
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
#line 4857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1897 "conf_parser.y" /* yacc.c:1646  */
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
#line 4888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1927 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1935 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1943 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 1977 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 1998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2059 "conf_parser.y" /* yacc.c:1646  */
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
      assert(res != NULL);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 405:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2137 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 409:
#line 2162 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 410:
#line 2175 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2181 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2191 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2199 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2205 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2244 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
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
#line 5416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2288 "conf_parser.y" /* yacc.c:1646  */
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
#line 5439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2321 "conf_parser.y" /* yacc.c:1646  */
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
#line 5483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2347 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2367 "conf_parser.y" /* yacc.c:1646  */
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
#line 5518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2388 "conf_parser.y" /* yacc.c:1646  */
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
#line 5549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2461 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2472 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2478 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2490 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2495 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2500 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2505 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2525 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2530 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2535 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2540 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2545 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2550 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2572 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
#line 5754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.use_egd = yylval.number;
}
#line 5906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
#line 5954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5962 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5970 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2715 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 5978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 5986 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 5994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 6002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 6010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 6018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2736 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2751 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2766 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6130 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6274 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
#line 6346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6354 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
#line 6426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 2980 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
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
#line 6491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6513 "conf_parser.c" /* yacc.c:1646  */
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
