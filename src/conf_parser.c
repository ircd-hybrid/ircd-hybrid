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
#line 143 "conf_parser.y" /* yacc.c:355  */

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
#define YYLAST   1227

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  289
/* YYNRULES -- Number of rules.  */
#define YYNRULES  653
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1278

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
       0,   373,   373,   374,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   403,   403,   404,
     408,   412,   416,   420,   424,   428,   432,   438,   438,   439,
     440,   441,   442,   449,   452,   452,   453,   453,   453,   455,
     461,   468,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   474,   475,   475,   476,   476,   477,   477,   478,   478,
     479,   480,   483,   484,   486,   486,   487,   493,   501,   501,
     502,   508,   516,   558,   616,   645,   653,   668,   683,   692,
     706,   715,   743,   773,   798,   820,   842,   851,   853,   853,
     854,   854,   855,   855,   857,   866,   875,   888,   887,   905,
     905,   906,   906,   906,   908,   914,   923,   924,   924,   926,
     926,   927,   929,   936,   936,   949,   950,   952,   952,   953,
     953,   955,   963,   966,   972,   971,   977,   977,   978,   982,
     986,   990,   994,   998,  1002,  1006,  1010,  1021,  1020,  1106,
    1106,  1107,  1107,  1107,  1108,  1108,  1108,  1109,  1109,  1110,
    1111,  1111,  1113,  1119,  1125,  1131,  1142,  1148,  1154,  1165,
    1172,  1171,  1177,  1177,  1178,  1182,  1186,  1190,  1194,  1198,
    1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1242,  1246,  1250,  1254,  1258,  1265,  1264,  1270,  1270,  1271,
    1275,  1279,  1283,  1287,  1291,  1295,  1299,  1303,  1307,  1311,
    1315,  1319,  1323,  1327,  1331,  1335,  1339,  1343,  1347,  1351,
    1355,  1359,  1363,  1374,  1373,  1434,  1434,  1435,  1436,  1436,
    1437,  1438,  1439,  1440,  1441,  1442,  1443,  1444,  1445,  1445,
    1446,  1447,  1448,  1449,  1451,  1457,  1463,  1469,  1475,  1481,
    1487,  1493,  1499,  1505,  1512,  1518,  1524,  1530,  1539,  1549,
    1548,  1554,  1554,  1555,  1559,  1570,  1569,  1576,  1575,  1580,
    1580,  1581,  1585,  1589,  1595,  1595,  1596,  1596,  1596,  1596,
    1596,  1598,  1598,  1600,  1600,  1602,  1616,  1636,  1642,  1652,
    1651,  1693,  1693,  1694,  1694,  1694,  1694,  1695,  1695,  1695,
    1696,  1696,  1698,  1704,  1710,  1716,  1728,  1727,  1733,  1733,
    1734,  1738,  1742,  1746,  1750,  1754,  1758,  1762,  1766,  1770,
    1776,  1790,  1799,  1813,  1812,  1827,  1827,  1828,  1828,  1828,
    1828,  1830,  1836,  1842,  1852,  1854,  1854,  1855,  1855,  1857,
    1873,  1872,  1897,  1897,  1898,  1898,  1898,  1898,  1900,  1906,
    1926,  1925,  1931,  1931,  1932,  1936,  1940,  1944,  1948,  1952,
    1956,  1960,  1964,  1968,  1978,  1977,  1998,  1998,  1999,  1999,
    1999,  2001,  2008,  2007,  2013,  2013,  2014,  2018,  2022,  2026,
    2030,  2034,  2038,  2042,  2046,  2050,  2060,  2059,  2131,  2131,
    2132,  2132,  2132,  2133,  2133,  2134,  2135,  2135,  2135,  2136,
    2136,  2136,  2137,  2137,  2138,  2140,  2146,  2152,  2158,  2171,
    2184,  2190,  2196,  2200,  2209,  2208,  2213,  2213,  2214,  2218,
    2224,  2235,  2241,  2247,  2253,  2269,  2268,  2294,  2294,  2295,
    2295,  2295,  2297,  2317,  2327,  2326,  2353,  2353,  2354,  2354,
    2354,  2356,  2362,  2371,  2373,  2373,  2374,  2374,  2376,  2394,
    2393,  2416,  2416,  2417,  2417,  2417,  2419,  2425,  2434,  2437,
    2437,  2438,  2438,  2439,  2439,  2440,  2440,  2441,  2441,  2442,
    2442,  2443,  2444,  2445,  2445,  2446,  2446,  2447,  2447,  2448,
    2448,  2449,  2450,  2450,  2451,  2451,  2452,  2452,  2453,  2453,
    2454,  2454,  2455,  2455,  2456,  2456,  2457,  2458,  2459,  2459,
    2460,  2460,  2461,  2462,  2463,  2464,  2464,  2465,  2466,  2469,
    2474,  2480,  2486,  2492,  2498,  2503,  2508,  2513,  2518,  2523,
    2528,  2533,  2538,  2543,  2548,  2553,  2558,  2563,  2569,  2580,
    2585,  2590,  2595,  2600,  2605,  2610,  2613,  2618,  2621,  2626,
    2631,  2636,  2641,  2646,  2651,  2656,  2661,  2666,  2671,  2676,
    2685,  2690,  2695,  2701,  2700,  2705,  2705,  2706,  2709,  2712,
    2715,  2718,  2721,  2724,  2727,  2730,  2733,  2736,  2739,  2742,
    2745,  2748,  2751,  2754,  2757,  2760,  2763,  2766,  2772,  2771,
    2776,  2776,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,
    2801,  2804,  2807,  2810,  2813,  2816,  2819,  2822,  2825,  2828,
    2831,  2834,  2837,  2842,  2847,  2852,  2861,  2864,  2864,  2865,
    2866,  2866,  2867,  2867,  2868,  2869,  2870,  2871,  2872,  2872,
    2873,  2873,  2875,  2880,  2885,  2890,  2895,  2900,  2905,  2910,
    2915,  2920,  2925,  2930,  2938,  2941,  2941,  2942,  2942,  2943,
    2944,  2945,  2946,  2946,  2947,  2948,  2950,  2956,  2962,  2968,
    2974,  2983,  2997,  3003
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
  "general_services_name", "general_ping_cookie", "general_disable_auth",
  "general_throttle_time", "general_oper_umodes", "$@24", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@25", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_knock_delay",
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

#define YYPACT_NINF -792

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-792)))

#define YYTABLE_NINF -124

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -792,   697,  -792,  -191,  -224,  -207,  -792,  -792,  -792,  -199,
    -792,  -185,  -792,  -792,  -792,  -178,  -792,  -792,  -792,  -147,
    -145,  -792,  -140,  -134,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   180,
     968,  -119,   -68,   -60,    14,   -53,   393,   -46,   -39,   -13,
      52,    -8,    -1,    20,   336,   443,    43,    39,    34,    69,
    -127,    16,    63,    71,     6,  -792,  -792,  -792,  -792,  -792,
      75,    84,    86,    94,    97,    98,    99,   100,   104,   106,
     112,   114,   274,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,   664,   521,    19,  -792,
     117,    12,  -792,  -792,    47,  -792,   118,   126,   136,   137,
     138,   139,   140,   141,   142,   144,   150,   152,   154,   162,
     165,   166,   167,   168,   173,   174,   176,   177,   181,   182,
     185,   186,  -792,   187,  -792,   188,   189,   191,   194,   195,
     196,   197,   198,   200,   201,   202,   203,   206,   210,   213,
     215,   216,   217,   107,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,   324,    25,    38,    90,   219,   224,    22,  -792,
    -792,  -792,    15,   557,    55,  -792,   225,   226,   227,   229,
     230,   233,   234,   235,     5,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,   116,   236,   237,   239,   242,   243,
     244,   245,   246,   247,   251,   253,   258,   260,   262,   263,
     264,   265,   153,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,    61,   156,   266,     9,  -792,  -792,  -792,    74,  -792,
     268,    40,  -792,  -792,    59,  -792,   159,   388,   389,   287,
    -792,   408,   409,   308,   411,   412,   412,   412,   413,   417,
     419,   318,   320,   304,  -792,   305,   310,   313,   325,  -792,
     326,   327,   329,   330,   331,   332,   335,   337,   338,   339,
     340,   341,   105,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     307,   343,   345,   348,   351,   352,   356,  -792,   357,   361,
     365,   367,   368,   370,   371,    60,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,   372,   373,    17,  -792,  -792,  -792,   483,   390,
    -792,  -792,   392,   394,    31,  -792,  -792,  -792,   416,   412,
     412,   420,   427,   421,   515,   424,   412,   425,   524,   530,
     412,   534,   435,   437,   439,   412,   542,   543,   412,   544,
     545,   546,   548,   447,   407,   448,   429,   450,   412,   412,
     452,   458,   460,  -186,  -161,   461,   464,   466,   559,   412,
     474,   477,   412,   412,   478,   462,  -792,   463,   455,   469,
    -792,   472,   476,   480,   482,   488,   275,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,   489,   490,    45,
    -792,  -792,  -792,   465,   492,   495,  -792,   496,  -792,     8,
    -792,  -792,  -792,  -792,  -792,   571,   573,   486,  -792,   501,
     499,   500,    87,  -792,  -792,  -792,   506,   504,   507,  -792,
     509,   511,   512,   513,   519,  -792,   520,   257,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   526,
     527,   531,   533,    10,  -792,  -792,  -792,  -792,   494,   541,
     550,   584,   555,   556,   558,   412,   551,  -792,  -792,   631,
     561,   652,   669,   672,   658,   659,   663,   665,   666,   673,
     679,   674,   110,   113,   675,   676,   565,  -792,   568,   572,
    -792,    24,  -792,  -792,  -792,  -792,   591,   576,  -792,   575,
     682,   579,  -792,   581,   580,  -792,   582,     7,  -792,  -792,
    -792,  -792,   586,   587,   588,  -792,   589,   590,   593,   594,
     475,   595,   596,   597,   598,   599,   604,   605,   606,  -792,
    -792,   701,   710,   412,   607,   726,   728,   412,   730,   731,
     412,   712,   732,   736,   412,   737,   737,   620,  -792,  -792,
     725,    33,   729,   639,   733,   734,   621,   735,   739,   745,
     740,   741,   742,   743,   628,  -792,   744,   746,   632,  -792,
     633,  -792,   747,   748,   641,  -792,   645,   646,   648,   649,
     650,   651,   653,   654,   655,   657,   667,   670,   677,   678,
     684,   685,   686,   687,   689,   690,   691,   695,   696,   698,
     699,   700,   727,   703,   770,   713,   715,   717,   718,   720,
     721,   738,   752,   753,   755,   756,   760,   762,   765,   767,
     768,   773,   774,   775,   776,  -792,  -792,   763,   681,   671,
     779,   771,   786,   801,   814,   777,  -792,   829,   831,   778,
    -792,  -792,   832,   833,   780,   791,   781,  -792,   782,   784,
    -792,  -792,   834,   836,   787,  -792,  -792,   837,   751,   783,
     852,   883,   892,   893,   807,   788,   896,   793,  -792,  -792,
     898,   899,   900,   797,  -792,   798,   799,   800,   802,   803,
     804,   808,   809,  -792,   810,   811,   815,   816,   817,   818,
     822,   823,   824,   825,   826,   827,   828,  -792,  -792,  -210,
    -792,  -792,  -792,  -198,  -792,   830,   835,  -792,  -792,   905,
     838,   839,  -792,   840,  -792,   108,   842,  -792,  -792,   909,
     841,   918,   843,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,   412,   412,   412,   412,   412,   412,   412,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   847,   848,
     849,   -32,   850,   851,   853,   854,   855,   856,   857,   858,
     859,   860,    57,   861,   862,  -792,   863,   864,   865,   866,
     867,   868,   869,     4,   870,   871,   872,   873,   874,   875,
     876,  -792,   877,   878,  -792,  -792,   879,   880,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -184,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -157,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,   881,   882,   529,   884,   885,   886,   887,   888,
    -792,   889,   890,  -792,   891,   894,   -21,   668,   895,  -792,
    -792,  -792,  -792,   897,   901,  -792,   902,   903,   497,   904,
     906,   907,   908,   910,   805,   911,  -792,   912,   913,   914,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,   110,  -792,   113,  -792,  -792,   915,   564,
    -792,  -792,   916,   917,   919,  -792,    13,  -792,  -792,  -792,
    -792,  -792,   921,   624,   923,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -155,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     737,   737,   737,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -146,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     727,  -792,   770,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -144,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -129,
    -792,   820,   791,   924,  -792,  -792,  -792,  -792,  -792,   920,
    -792,  -792,   922,  -792,  -792,  -792,  -792,   925,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   -54,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,   -36,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,    53,  -792,  -792,   933,
     -58,   926,   928,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,    58,  -792,  -792,  -792,   -32,
    -792,  -792,  -792,  -792,     4,  -792,  -792,  -792,   529,  -792,
     -21,  -792,  -792,  -792,   929,   930,   931,  -792,   497,  -792,
     805,  -792,   564,   932,   934,   935,   422,  -792,  -792,   624,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,    64,  -792,  -792,  -792,   422,  -792
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   621,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,   620,   610,   611,   612,   613,   609,
     614,   615,   616,   617,   618,   619,     0,     0,     0,   447,
       0,     0,   445,   446,     0,   508,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,     0,   553,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   460,   505,   507,   499,   500,   501,
     502,   503,   498,   471,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   495,   472,   473,   504,   475,   480,
     481,   476,   478,   477,   489,   490,   479,   482,   483,   484,
     485,   474,   487,   506,   496,   497,   494,   488,   486,   492,
     493,   491,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   645,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   636,   637,   638,   639,   640,
     643,   641,   642,   644,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   338,
       0,     0,   336,   337,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   607,     0,     0,     0,     0,   259,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   226,   227,   230,   232,   233,   234,   235,
     236,   237,   238,   239,   228,   229,   231,   240,   241,   242,
       0,     0,     0,     0,     0,     0,     0,   414,     0,     0,
       0,     0,     0,     0,     0,     0,   389,   390,   391,   392,
     393,   394,   395,   397,   396,   399,   403,   400,   401,   402,
     398,   440,     0,     0,     0,   437,   438,   439,     0,     0,
     444,   455,     0,     0,     0,   452,   453,   454,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   459,     0,     0,     0,
     306,     0,     0,     0,     0,     0,     0,   292,   293,   294,
     295,   300,   296,   297,   298,   299,   431,     0,     0,     0,
     428,   429,   430,     0,     0,     0,   267,     0,   277,     0,
     275,   276,   278,   279,    48,     0,     0,     0,    44,     0,
       0,     0,     0,   110,   111,   112,     0,     0,     0,   195,
       0,     0,     0,     0,     0,   170,     0,     0,   150,   151,
     152,   153,   156,   157,   158,   159,   155,   154,   160,     0,
       0,     0,     0,     0,   326,   327,   328,   329,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   635,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     372,     0,   367,   368,   369,   121,     0,     0,   117,     0,
       0,     0,   335,     0,     0,   350,     0,     0,   343,   344,
     345,   346,     0,     0,     0,    97,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,   606,
     243,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   225,   404,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   388,     0,     0,     0,   436,
       0,   443,     0,     0,     0,   451,     0,     0,     0,     0,
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
       0,     0,     0,   634,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      75,    80,    81,     0,    79,     0,     0,    51,   370,     0,
       0,     0,   366,     0,   116,     0,     0,   334,   347,     0,
       0,     0,     0,   342,   106,   105,   104,   629,   628,   622,
     632,    27,    27,    27,    27,    27,    27,    27,    29,    28,
     633,   623,   624,   627,   626,   625,   630,   631,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,   224,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,     0,     0,   435,   448,     0,     0,   450,   521,
     525,   540,   510,   605,   551,   547,   520,   512,   511,   514,
     515,   513,   528,   518,   519,   529,   517,   524,   523,   522,
     548,   509,   603,   604,   544,   588,   582,   599,   583,   584,
     585,   593,   602,   586,   596,   600,   589,   601,   594,   590,
     595,   587,   598,   592,   591,   597,     0,   581,   546,   562,
     557,   574,   558,   559,   560,   568,   577,   561,   571,   575,
     564,   576,   569,   565,   570,   563,   573,   567,   566,   572,
       0,   556,   541,   539,   542,   550,   543,   531,   537,   538,
     535,   536,   532,   533,   534,   549,   552,   516,   545,   527,
     526,   530,     0,     0,     0,     0,     0,     0,     0,     0,
     290,     0,     0,   426,     0,     0,     0,   285,   281,   284,
     266,    49,    50,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   148,     0,     0,     0,
     324,   647,   646,   652,   650,   653,   648,   649,   651,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     365,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   339,     0,     0,     0,   341,    30,    31,    32,    33,
      34,    35,    36,   254,   255,   247,   264,   263,     0,   262,
     249,   251,   258,   250,   248,   257,   244,   256,   246,   245,
      37,    37,    37,    39,    38,   252,   253,   409,   412,   413,
     423,   420,   406,   421,   418,   419,     0,   417,   422,   405,
     411,   408,   410,   424,   407,   441,   442,   456,   457,   579,
       0,   554,     0,   304,   305,   314,   311,   316,   312,   313,
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
      40,    41,    42,   415,     0,   580,   555,   307,     0,   268,
       0,   286,   283,   282,     0,     0,     0,   196,     0,   171,
       0,   373,     0,     0,     0,     0,     0,   124,   351,     0,
     261,   416,   308,   269,   201,   199,   203,   197,   172,   374,
     131,   133,   132,   140,   145,   144,   139,   142,   146,   143,
     138,   141,     0,   137,   352,   135,     0,   136
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -792,  -792,  -792,  -443,  -303,  -791,  -615,  -792,  -792,   845,
    -792,  -792,  -792,  -792,   927,  -792,  -792,  -792,    48,  -792,
      49,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   991,  -792,
    -792,  -792,  -792,  -792,  -792,   618,  -792,  -792,  -792,  -792,
     795,  -792,  -792,  -792,  -792,    93,  -792,  -792,  -792,  -792,
    -792,  -156,  -792,  -792,  -792,   615,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -117,  -792,  -792,
    -792,  -113,  -792,  -792,  -792,   812,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,   -92,  -792,  -792,  -792,  -792,  -792,
     -98,  -792,   688,  -792,  -792,  -792,    23,  -792,  -792,  -792,
    -792,  -792,   680,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     -82,  -792,  -792,  -792,  -792,  -792,  -792,   630,  -792,  -792,
    -792,  -792,  -792,   936,  -792,  -792,  -792,  -792,   583,  -792,
    -792,  -792,  -792,  -792,   -91,  -792,  -792,  -792,   602,  -792,
    -792,  -792,  -792,   -78,  -792,  -792,  -792,   806,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   -59,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,   704,  -792,
    -792,  -792,  -792,  -792,   785,  -792,  -792,  -792,  -792,  1055,
    -792,  -792,  -792,  -792,   789,  -792,  -792,  -792,  -792,  1005,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,    78,  -792,  -792,  -792,    82,
    -792,  -792,  -792,  -792,  -792,  1082,  -792,  -792,  -792,  -792,
    -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792,
     941,  -792,  -792,  -792,  -792,  -792,  -792,  -792,  -792
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   808,   809,  1063,  1064,    26,   218,   219,
     220,   221,    27,   262,   263,   264,   265,   769,   770,   773,
     774,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    28,    74,    75,    76,
      77,    78,    29,    61,   492,   493,   494,   495,    30,   284,
     285,   286,   287,   288,  1026,  1027,  1028,  1029,  1030,  1201,
    1272,  1273,    31,    62,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   735,  1177,  1178,   518,   729,
    1149,  1150,    32,    51,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   604,  1048,  1049,    33,    59,   478,   714,  1119,
    1120,   479,   480,   481,  1123,   968,   969,   482,   483,    34,
      57,   456,   457,   458,   459,   460,   461,   462,   699,  1105,
    1106,   463,   464,   465,    35,    63,   523,   524,   525,   526,
     527,    36,   291,   292,   293,    37,    69,   577,   578,   579,
     580,   581,   790,  1215,  1216,    38,    66,   561,   562,   563,
     564,   780,  1196,  1197,    39,    52,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   626,  1076,  1077,
     376,   377,   378,   379,   380,    40,    58,   469,   470,   471,
     472,    41,    53,   384,   385,   386,   387,    42,   111,   112,
     113,    43,    55,   394,   395,   396,   397,    44,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   426,   930,   931,   208,   424,   906,   907,
     209,   210,   211,    45,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    46,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     833,   834,   591,   592,   593,    49,   225,    70,   573,   473,
     282,   519,  1074,   109,  1022,   109,   489,  1012,   381,  1046,
     381,  1013,    50,   215,   681,   558,   466,   682,  1116,  1014,
      54,    71,   391,  1015,   226,   289,    47,    48,    72,   473,
     282,   289,   227,  1089,    56,   520,   466,  1090,   391,   683,
     832,    60,   684,   215,   228,   229,   519,   230,   231,   232,
     573,   350,   558,   351,   474,   352,  1060,  1061,  1062,   475,
    1091,   476,  1218,   110,  1092,   110,  1219,   353,   382,   233,
     382,  1223,    64,  1227,    65,  1224,   521,  1228,   489,    67,
     520,   490,  1047,   354,   474,    68,   647,   648,  1229,   475,
     295,   476,  1230,   654,    73,   574,   315,   658,   115,  1022,
     106,  1023,   663,   116,   117,   666,   355,   216,   356,   118,
     316,   317,   559,   357,   318,   676,   677,   119,   120,   392,
     477,   521,   290,   358,   121,   522,   689,   122,   290,   692,
     693,   217,   383,   123,   383,   392,  1244,   216,   124,   125,
     467,   126,   127,   128,   244,   129,   393,   574,   359,   559,
     477,   107,   130,   490,  1117,   832,   131,   132,   319,   108,
     467,   217,   393,  1237,  1118,   133,   114,  1238,   245,  -123,
     522,    70,   360,   212,   134,   491,   320,   321,   322,   323,
     213,  1239,   135,   324,   136,  1240,   137,   325,   138,  1075,
     139,   140,   361,   326,  1024,    71,  1023,   837,   838,  -123,
     246,   362,    72,   141,   327,   328,   214,   247,   142,   143,
     144,   222,   145,   146,   147,   575,   329,   148,   223,   576,
     283,  1025,   752,   536,   299,   792,   716,   567,   743,   248,
     389,  1202,   560,   249,   569,   638,   296,   468,   330,   224,
     487,   250,   781,   149,   251,   252,   363,   491,   496,   644,
     283,   150,   151,   152,   153,   154,   155,   468,   571,  1220,
    1221,  1222,   281,   709,   497,    79,   447,   575,    73,   560,
    1241,   576,   582,   364,  1242,  1248,   253,   331,   634,  1249,
     498,  1275,   448,   297,   156,  1276,    80,    81,   294,  1024,
     820,   298,    82,   254,   824,   301,   255,   827,   449,   767,
     768,   831,   771,   772,   302,   724,   303,   484,   157,   158,
     499,   159,   160,   161,   304,   447,  1025,   305,   306,   307,
     308,   256,   162,   617,   309,   445,   310,   225,   450,    83,
      84,   448,   311,   538,   312,    85,    86,   388,   398,   257,
     258,   259,    87,    88,    89,   500,   399,   449,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,   226,   400,   401,   402,   403,
     404,   405,   406,   227,   407,   501,   260,   261,    90,    91,
     408,   556,   409,   565,   410,   228,   229,   450,   230,   231,
     232,   502,   411,   451,   115,   412,   413,   414,   415,   116,
     117,   452,   453,   416,   417,   118,   418,   419,   503,   504,
     233,   420,   421,   119,   120,   422,   423,   425,   427,   428,
     121,   429,   454,   122,   430,   431,   432,   433,   434,   123,
     435,   436,   437,   438,   124,   125,   439,   126,   127,   128,
     440,   129,   451,   441,   244,   442,   443,   444,   130,   485,
     452,   453,   131,   132,   486,   528,   529,   530,   505,   531,
     532,   133,  1263,   533,   534,   535,   539,   540,   245,   541,
     134,   454,   542,   543,   544,   545,   546,   547,   135,   506,
     136,   548,   137,   549,   138,   737,   139,   140,   550,  1264,
     551,  1265,   552,   553,   554,   555,   566,   455,   570,   141,
     246,  1128,   313,   705,   142,   143,   144,   247,   145,   146,
     147,   583,   584,   148,   585,  1129,   586,   587,   588,   589,
     590,   594,   350,  1130,   351,   595,   352,   596,   597,   248,
     598,   599,   600,   249,   619,   650,  1266,  1131,   353,   149,
     601,   250,  1095,   602,   251,   252,   455,   150,   151,   152,
     153,   154,   155,  1267,   354,   603,   605,   606,   496,   607,
     608,   609,   610,  1096,  1132,   611,  1133,   612,   613,   614,
     615,   616,  1097,   620,   497,   621,   253,   355,   622,   356,
     156,   623,   624,   590,   357,  1245,   625,   627,  1268,  1269,
     498,   628,  1134,   254,   358,   629,   255,   630,   631,  1098,
     632,   633,   636,   637,   157,   158,   640,   159,   160,   161,
     801,   802,   803,   804,   805,   806,   807,   641,   162,   359,
     499,   256,   642,   652,   643,  1135,   646,  1136,  1099,  1100,
     649,   651,   656,  1186,   653,   655,  1101,   672,   657,   257,
     258,   259,   659,   360,  1270,   660,  1137,   661,  1271,   662,
     664,   665,   667,   668,   669,   500,   670,   671,   673,   674,
     675,  1102,   678,   361,  1138,   315,   260,   261,   679,  1139,
     680,   685,   362,  1140,   686,   501,   687,  1103,  1141,   316,
     317,  1142,   688,   318,   690,   697,  1143,   691,   694,   695,
     696,   502,   711,  1205,   718,  1187,   719,     2,     3,   698,
    1144,     4,   700,  1145,   745,  1146,   701,   748,   503,   504,
     702,     5,   703,   720,     6,     7,  1147,   363,   704,   707,
     708,     8,   712,  1148,  1188,   713,   715,   319,   721,   722,
     723,  1189,     9,   726,   727,    10,    11,   728,  1104,   730,
    1190,   731,   732,   733,   364,   320,   321,   322,   323,   734,
     736,   746,   324,   739,   754,  1206,   325,   740,   505,    12,
     747,   741,   326,   742,    13,   749,   750,  1191,   751,  1192,
    1193,   755,    14,   327,   328,   756,   885,   757,   753,   506,
     758,   759,   760,  1194,  1207,   329,   761,   765,   762,   763,
    1195,  1208,   777,    15,    16,   778,   764,   766,   775,   776,
    1209,   783,   779,   784,   785,   786,   787,   330,   788,   818,
     789,    17,   791,   794,   795,   796,   797,   798,   819,   909,
     799,   800,   810,   811,   812,   813,   814,  1210,    18,  1211,
    1212,   815,   816,   817,   822,   828,   823,   821,   825,   826,
     829,    19,    20,  1213,   830,   832,   331,   835,   836,   840,
    1214,   843,   839,   846,  1156,   851,   841,   842,   844,   854,
     855,    21,   845,   847,   848,   849,   850,   852,   858,   853,
     856,   857,   859,   860,    22,   861,   862,   863,   864,   956,
     865,   866,   867,    23,   868,  1121,   952,    24,   886,   887,
     888,   953,   889,   890,   869,   891,   892,   870,   893,   967,
     894,   954,   955,   895,   871,   872,   896,   897,   898,   957,
     899,   873,   874,   875,   876,   900,   877,   878,   879,   901,
     902,   903,   880,   881,   958,   882,   883,   884,  1231,   904,
     908,   910,   911,   912,   905,   913,   914,   959,   915,   916,
     932,   917,   933,   918,   934,   935,   919,   936,   937,   920,
     921,   922,   961,   923,   962,   964,   965,   973,   924,   974,
     976,   977,   925,   926,   927,   938,  1157,  1158,  1159,    79,
    1160,  1161,   928,  1162,  1163,   979,  1164,   929,  1165,   939,
     940,  1166,   941,   942,  1167,  1168,  1169,   943,  1170,   944,
      80,    81,   945,  1171,   946,   947,    82,  1172,  1173,  1174,
     948,   949,   950,   951,   960,   963,   980,  1175,   970,   971,
     966,   972,  1176,   978,   975,   981,   982,   983,   984,   985,
     986,   987,   988,   989,   990,   991,   992,   993,  1018,   994,
     995,   996,  1032,    83,    84,   997,   998,   999,  1000,    85,
      86,  1034,  1001,  1002,  1003,  1004,    87,    88,    89,  1005,
    1006,  1007,  1008,  1009,  1010,  1011,  1243,  1016,  1254,  1255,
    1256,  1183,  1017,   488,  1184,   300,  1020,  1021,  1019,  1031,
    1035,  1033,    90,    91,  1043,  1044,  1045,  1050,  1051,   568,
    1052,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1065,  1066,
    1067,  1068,  1069,  1070,  1071,  1072,  1073,  1078,  1079,  1080,
    1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1093,  1094,
     725,  1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1203,
    1277,  1115,   738,  1258,  1124,  1257,  1122,  1250,  1125,  1126,
    1127,  1151,  1253,  1152,  1153,  1154,   706,  1155,  1179,  1180,
    1181,  1182,  1185,  1198,   618,  1232,  1252,  1199,  1204,  1200,
    1217,  1233,  1234,   744,  1235,  1247,  1246,  1236,  1274,  1260,
     793,  1261,  1262,   782,  1259,  1251,   390,   717,   446,   639,
    1226,   635,  1225,   710,   314,   537,     0,     0,     0,     0,
       0,     0,     0,   645,     0,     0,     0,     0,     0,   557,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   572
};

static const yytype_int16 yycheck[] =
{
     615,   616,   305,   306,   307,   229,     1,     1,     1,     1,
       1,     1,     8,     1,     1,     1,     1,   227,     1,    51,
       1,   231,   229,     1,   210,     1,     1,   213,    49,   227,
     229,    25,     1,   231,    29,     1,   227,   228,    32,     1,
       1,     1,    37,   227,   229,    35,     1,   231,     1,   210,
     108,   229,   213,     1,    49,    50,     1,    52,    53,    54,
       1,     1,     1,     3,    56,     5,     9,    10,    11,    61,
     227,    63,   227,    61,   231,    61,   231,    17,    61,    74,
      61,   227,   229,   227,   229,   231,    76,   231,     1,   229,
      35,    76,   124,    33,    56,   229,   399,   400,   227,    61,
     227,    63,   231,   406,    98,    98,     1,   410,     1,     1,
     229,    98,   415,     6,     7,   418,    56,    95,    58,    12,
      15,    16,    98,    63,    19,   428,   429,    20,    21,    98,
     122,    76,    98,    73,    27,   125,   439,    30,    98,   442,
     443,   119,   125,    36,   125,    98,   204,    95,    41,    42,
     125,    44,    45,    46,     1,    48,   125,    98,    98,    98,
     122,   229,    55,    76,   185,   108,    59,    60,    63,   229,
     125,   119,   125,   227,   195,    68,   229,   231,    25,   170,
     125,     1,   122,   229,    77,   170,    81,    82,    83,    84,
     229,   227,    85,    88,    87,   231,    89,    92,    91,   195,
      93,    94,   142,    98,   191,    25,    98,   174,   175,   170,
      57,   151,    32,   106,   109,   110,   229,    64,   111,   112,
     113,   229,   115,   116,   117,   218,   121,   120,   229,   222,
     221,   218,   535,   228,   228,   228,   228,   228,   228,    86,
     228,   228,   218,    90,   170,   228,   230,   222,   143,   229,
     228,    98,   228,   146,   101,   102,   196,   170,     1,   228,
     221,   154,   155,   156,   157,   158,   159,   222,   228,  1060,
    1061,  1062,   229,   228,    17,     1,     1,   218,    98,   218,
     227,   222,   123,   223,   231,   227,   133,   182,   228,   231,
      33,   227,    17,   230,   187,   231,    22,    23,   229,   191,
     603,   230,    28,   150,   607,   230,   153,   610,    33,   199,
     200,   614,   199,   200,   230,   228,   230,   227,   211,   212,
      63,   214,   215,   216,   230,     1,   218,   230,   230,   230,
     230,   178,   225,   228,   230,   228,   230,     1,    63,    65,
      66,    17,   230,   227,   230,    71,    72,   230,   230,   196,
     197,   198,    78,    79,    80,    98,   230,    33,   801,   802,
     803,   804,   805,   806,   807,    29,   230,   230,   230,   230,
     230,   230,   230,    37,   230,   118,   223,   224,   104,   105,
     230,   228,   230,   227,   230,    49,    50,    63,    52,    53,
      54,   134,   230,   118,     1,   230,   230,   230,   230,     6,
       7,   126,   127,   230,   230,    12,   230,   230,   151,   152,
      74,   230,   230,    20,    21,   230,   230,   230,   230,   230,
      27,   230,   147,    30,   230,   230,   230,   230,   230,    36,
     230,   230,   230,   230,    41,    42,   230,    44,    45,    46,
     230,    48,   118,   230,     1,   230,   230,   230,    55,   230,
     126,   127,    59,    60,   230,   230,   230,   230,   201,   230,
     230,    68,    40,   230,   230,   230,   230,   230,    25,   230,
      77,   147,   230,   230,   230,   230,   230,   230,    85,   222,
      87,   230,    89,   230,    91,   228,    93,    94,   230,    67,
     230,    69,   230,   230,   230,   230,   230,   222,   230,   106,
      57,     4,   228,   228,   111,   112,   113,    64,   115,   116,
     117,   123,   123,   120,   227,    18,   108,   108,   210,   108,
     108,   108,     1,    26,     3,   108,     5,   108,   210,    86,
     210,   227,   227,    90,   227,   108,   114,    40,    17,   146,
     230,    98,    13,   230,   101,   102,   222,   154,   155,   156,
     157,   158,   159,   131,    33,   230,   230,   230,     1,   230,
     230,   230,   230,    34,    67,   230,    69,   230,   230,   230,
     230,   230,    43,   230,    17,   230,   133,    56,   230,    58,
     187,   230,   230,   108,    63,  1200,   230,   230,   166,   167,
      33,   230,    95,   150,    73,   230,   153,   230,   230,    70,
     230,   230,   230,   230,   211,   212,   123,   214,   215,   216,
     135,   136,   137,   138,   139,   140,   141,   227,   225,    98,
      63,   178,   230,   108,   230,   128,   210,   130,    99,   100,
     210,   210,   108,    69,   210,   210,   107,   230,   108,   196,
     197,   198,   108,   122,   222,   210,   149,   210,   226,   210,
     108,   108,   108,   108,   108,    98,   108,   210,   210,   230,
     210,   132,   210,   142,   167,     1,   223,   224,   210,   172,
     210,   210,   151,   176,   210,   118,   210,   148,   181,    15,
      16,   184,   123,    19,   210,   230,   189,   210,   210,   227,
     227,   134,   227,    69,   123,   131,   123,     0,     1,   230,
     203,     4,   230,   206,   210,   208,   230,   123,   151,   152,
     230,    14,   230,   227,    17,    18,   219,   196,   230,   230,
     230,    24,   230,   226,   160,   230,   230,    63,   227,   230,
     230,   167,    35,   227,   230,    38,    39,   230,   209,   230,
     176,   230,   230,   230,   223,    81,    82,    83,    84,   230,
     230,   210,    88,   227,   123,   131,    92,   230,   201,    62,
     210,   230,    98,   230,    67,   210,   210,   203,   210,   205,
     206,   210,    75,   109,   110,   123,    49,   108,   227,   222,
     108,   123,   123,   219,   160,   121,   123,   108,   123,   123,
     226,   167,   227,    96,    97,   227,   123,   123,   123,   123,
     176,   210,   230,   227,   229,   123,   227,   143,   227,   108,
     230,   114,   230,   227,   227,   227,   227,   227,   108,    49,
     227,   227,   227,   227,   227,   227,   227,   203,   131,   205,
     206,   227,   227,   227,   108,   123,   108,   230,   108,   108,
     108,   144,   145,   219,   108,   108,   182,   227,   123,   210,
     226,   230,   123,   108,    49,   227,   123,   123,   123,   227,
     227,   164,   123,   123,   123,   123,   123,   123,   227,   123,
     123,   123,   227,   227,   177,   227,   227,   227,   227,   108,
     227,   227,   227,   186,   227,   217,   123,   190,   161,   162,
     163,   210,   165,   166,   227,   168,   169,   227,   171,   108,
     173,   230,   123,   176,   227,   227,   179,   180,   181,   123,
     183,   227,   227,   227,   227,   188,   227,   227,   227,   192,
     193,   194,   227,   227,   123,   227,   227,   227,   108,   202,
     227,   161,   162,   163,   207,   165,   166,   123,   168,   169,
     227,   171,   227,   173,   227,   227,   176,   227,   227,   179,
     180,   181,   123,   183,   123,   123,   123,   123,   188,   123,
     123,   210,   192,   193,   194,   227,   161,   162,   163,     1,
     165,   166,   202,   168,   169,   123,   171,   207,   173,   227,
     227,   176,   227,   227,   179,   180,   181,   227,   183,   227,
      22,    23,   227,   188,   227,   227,    28,   192,   193,   194,
     227,   227,   227,   227,   227,   227,   123,   202,   227,   227,
     230,   227,   207,   230,   227,   123,   123,   210,   230,   123,
     227,   123,   123,   123,   227,   227,   227,   227,   123,   227,
     227,   227,   123,    65,    66,   227,   227,   227,   227,    71,
      72,   123,   227,   227,   227,   227,    78,    79,    80,   227,
     227,   227,   227,   227,   227,   227,   123,   227,   129,   129,
     129,  1013,   227,   218,  1015,    74,   227,   227,   230,   227,
     227,   230,   104,   105,   227,   227,   227,   227,   227,   284,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     492,   227,   227,   227,   227,   227,   227,   227,   227,  1026,
    1276,   227,   507,  1240,   227,  1238,   231,  1219,   227,   227,
     227,   227,  1230,   227,   227,   227,   456,   227,   227,   227,
     227,   227,   227,   227,   332,  1122,  1228,   230,   227,   230,
     227,   227,   232,   523,   232,   227,   230,   232,  1249,   227,
     577,   227,   227,   561,  1242,  1224,   111,   479,   163,   384,
    1092,   365,  1090,   469,    92,   234,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,    -1,   262,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   291
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   234,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    62,    67,    75,    96,    97,   114,   131,   144,
     145,   164,   177,   186,   190,   235,   240,   245,   269,   275,
     281,   295,   315,   338,   352,   367,   374,   378,   388,   397,
     418,   424,   430,   434,   440,   496,   511,   227,   228,   229,
     229,   316,   398,   425,   229,   435,   229,   353,   419,   339,
     229,   276,   296,   368,   229,   229,   389,   229,   229,   379,
       1,    25,    32,    98,   270,   271,   272,   273,   274,     1,
      22,    23,    28,    65,    66,    71,    72,    78,    79,    80,
     104,   105,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   229,   229,   229,     1,
      61,   431,   432,   433,   229,     1,     6,     7,    12,    20,
      21,    27,    30,    36,    41,    42,    44,    45,    46,    48,
      55,    59,    60,    68,    77,    85,    87,    89,    91,    93,
      94,   106,   111,   112,   113,   115,   116,   117,   120,   146,
     154,   155,   156,   157,   158,   159,   187,   211,   212,   214,
     215,   216,   225,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   489,   493,
     494,   495,   229,   229,   229,     1,    95,   119,   241,   242,
     243,   244,   229,   229,   229,     1,    29,    37,    49,    50,
      52,    53,    54,    74,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,     1,    25,    57,    64,    86,    90,
      98,   101,   102,   133,   150,   153,   178,   196,   197,   198,
     223,   224,   246,   247,   248,   249,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   229,     1,   221,   282,   283,   284,   285,   286,     1,
      98,   375,   376,   377,   229,   227,   230,   230,   230,   228,
     271,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   228,   498,     1,    15,    16,    19,    63,
      81,    82,    83,    84,    88,    92,    98,   109,   110,   121,
     143,   182,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
       1,     3,     5,    17,    33,    56,    58,    63,    73,    98,
     122,   142,   151,   196,   223,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   413,   414,   415,   416,
     417,     1,    61,   125,   426,   427,   428,   429,   230,   228,
     432,     1,    98,   125,   436,   437,   438,   439,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   490,   230,   486,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   228,   442,     1,    17,    33,
      63,   118,   126,   127,   147,   222,   354,   355,   356,   357,
     358,   359,   360,   364,   365,   366,     1,   125,   222,   420,
     421,   422,   423,     1,    56,    61,    63,   122,   340,   344,
     345,   346,   350,   351,   227,   230,   230,   228,   242,     1,
      76,   170,   277,   278,   279,   280,     1,    17,    33,    63,
      98,   118,   134,   151,   152,   201,   222,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   306,   307,   311,     1,
      35,    76,   125,   369,   370,   371,   372,   373,   230,   230,
     230,   230,   230,   230,   230,   230,   228,   513,   227,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   228,   247,     1,    98,
     218,   390,   391,   392,   393,   227,   230,   228,   283,   170,
     230,   228,   376,     1,    98,   218,   222,   380,   381,   382,
     383,   384,   123,   123,   123,   227,   108,   108,   210,   108,
     108,   237,   237,   237,   108,   108,   108,   210,   210,   227,
     227,   230,   230,   230,   335,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   228,   318,   227,
     230,   230,   230,   230,   230,   230,   410,   230,   230,   230,
     230,   230,   230,   230,   228,   400,   230,   230,   228,   427,
     123,   227,   230,   230,   228,   437,   210,   237,   237,   210,
     108,   210,   108,   210,   237,   210,   108,   108,   237,   108,
     210,   210,   210,   237,   108,   108,   237,   108,   108,   108,
     108,   210,   230,   210,   230,   210,   237,   237,   210,   210,
     210,   210,   213,   210,   213,   210,   210,   210,   123,   237,
     210,   210,   237,   237,   210,   227,   227,   230,   230,   361,
     230,   230,   230,   230,   230,   228,   355,   230,   230,   228,
     421,   227,   230,   230,   341,   230,   228,   345,   123,   123,
     227,   227,   230,   230,   228,   278,   227,   230,   230,   312,
     230,   230,   230,   230,   230,   308,   230,   228,   298,   227,
     230,   230,   230,   228,   370,   210,   210,   210,   123,   210,
     210,   210,   237,   227,   123,   210,   123,   108,   108,   123,
     123,   123,   123,   123,   123,   108,   123,   199,   200,   250,
     251,   199,   200,   252,   253,   123,   123,   227,   227,   230,
     394,   228,   391,   210,   227,   229,   123,   227,   227,   230,
     385,   230,   228,   381,   227,   227,   227,   227,   227,   227,
     227,   135,   136,   137,   138,   139,   140,   141,   236,   237,
     227,   227,   227,   227,   227,   227,   227,   227,   108,   108,
     237,   230,   108,   108,   237,   108,   108,   237,   123,   108,
     108,   237,   108,   239,   239,   227,   123,   174,   175,   123,
     210,   123,   123,   230,   123,   123,   108,   123,   123,   123,
     123,   227,   123,   123,   227,   227,   123,   123,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,    49,   161,   162,   163,   165,
     166,   168,   169,   171,   173,   176,   179,   180,   181,   183,
     188,   192,   193,   194,   202,   207,   491,   492,   227,    49,
     161,   162,   163,   165,   166,   168,   169,   171,   173,   176,
     179,   180,   181,   183,   188,   192,   193,   194,   202,   207,
     487,   488,   227,   227,   227,   227,   227,   227,   227,   227,
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
     238,   238,   238,   227,   231,   492,   488,   227,   231,   227,
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
     442,   442,   442,   442,   442,   442,   442,   442,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   469,   470,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   486,   485,   487,   487,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   490,   489,
     491,   491,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   493,   494,   495,   496,   497,   497,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   512,   513,   513,   513,
     513,   513,   513,   513,   513,   513,   514,   515,   516,   517,
     518,   519,   520,   521
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 403 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 29:
#line 405 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
#line 2828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 409 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
#line 2836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
#line 2844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
#line 2852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
#line 2860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
#line 2868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    {
                        (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number);
                }
#line 2876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 433 "conf_parser.y" /* yacc.c:1646  */
    {
                        (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number);
                }
#line 2884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 438 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 39:
#line 439 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 440 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 442 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 49:
#line 456 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 462 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 488 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 494 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 503 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
#line 2965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 509 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
#line 2976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 517 "conf_parser.y" /* yacc.c:1646  */
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
#line 3021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 559 "conf_parser.y" /* yacc.c:1646  */
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
#line 3082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 617 "conf_parser.y" /* yacc.c:1646  */
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
#line 3114 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 646 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
#line 3125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 654 "conf_parser.y" /* yacc.c:1646  */
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
#line 3143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 669 "conf_parser.y" /* yacc.c:1646  */
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
#line 3161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
#line 3173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 693 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      *p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 90:
#line 707 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3202 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 91:
#line 716 "conf_parser.y" /* yacc.c:1646  */
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
#line 3233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 92:
#line 744 "conf_parser.y" /* yacc.c:1646  */
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
#line 3266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 93:
#line 774 "conf_parser.y" /* yacc.c:1646  */
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
#line 3294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 94:
#line 799 "conf_parser.y" /* yacc.c:1646  */
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
#line 3319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 95:
#line 821 "conf_parser.y" /* yacc.c:1646  */
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
#line 3344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 96:
#line 843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
#line 3353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 104:
#line 858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
#line 3365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 105:
#line 867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
#line 3377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 106:
#line 876 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
#line 3389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
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
#line 3415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 114:
#line 909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 115:
#line 915 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 122:
#line 930 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
#line 3442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 123:
#line 936 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 124:
#line 940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 131:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 132:
#line 964 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 133:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 134:
#line 972 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 979 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 983 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 987 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
#line 3527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 141:
#line 991 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 142:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3545 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 143:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
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
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- Key invalid; check key syntax");
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
#line 3675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1132 "conf_parser.y" /* yacc.c:1646  */
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
#line 1143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1149 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
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
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1187 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1199 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1211 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
#line 3883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 204:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
#line 4027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
#line 4081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
#line 4126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
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
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
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
#line 4249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 244:
#line 1452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 245:
#line 1458 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 246:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 247:
#line 1470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 248:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 249:
#line 1482 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 250:
#line 1488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 251:
#line 1494 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4321 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1500 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4330 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1513 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1519 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1525 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1560 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1582 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1590 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1598 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1603 "conf_parser.y" /* yacc.c:1646  */
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
#line 1617 "conf_parser.y" /* yacc.c:1646  */
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
#line 1637 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 288:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 289:
#line 1652 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
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
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1699 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1705 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 305:
#line 1717 "conf_parser.y" /* yacc.c:1646  */
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
#line 1728 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 310:
#line 1735 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1739 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1743 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4655 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1747 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1751 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1755 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1759 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
#line 4691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1763 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1767 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1771 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4718 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
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
#line 1791 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1800 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1820 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
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
#line 1873 "conf_parser.y" /* yacc.c:1646  */
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
#line 1884 "conf_parser.y" /* yacc.c:1646  */
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
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1907 "conf_parser.y" /* yacc.c:1646  */
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
#line 1926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1937 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1945 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4969 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1965 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 1978 "conf_parser.y" /* yacc.c:1646  */
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
#line 1987 "conf_parser.y" /* yacc.c:1646  */
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
#line 2002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2060 "conf_parser.y" /* yacc.c:1646  */
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
#line 2069 "conf_parser.y" /* yacc.c:1646  */
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
#line 2141 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 406:
#line 2147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 407:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 408:
#line 2159 "conf_parser.y" /* yacc.c:1646  */
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
#line 2172 "conf_parser.y" /* yacc.c:1646  */
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
#line 2185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 411:
#line 2191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 412:
#line 2197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2201 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
#line 5301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2209 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2225 "conf_parser.y" /* yacc.c:1646  */
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
#line 2236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2254 "conf_parser.y" /* yacc.c:1646  */
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
#line 2269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2273 "conf_parser.y" /* yacc.c:1646  */
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
#line 2298 "conf_parser.y" /* yacc.c:1646  */
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
#line 2318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2331 "conf_parser.y" /* yacc.c:1646  */
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
#line 2357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2377 "conf_parser.y" /* yacc.c:1646  */
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
#line 2394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2398 "conf_parser.y" /* yacc.c:1646  */
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
#line 2420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 509:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_watch = (yyvsp[-1].number);
}
#line 5575 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 510:
#line 2475 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
#line 5584 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 511:
#line 2481 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
#line 5593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 512:
#line 2487 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
#line 5602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 513:
#line 2493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[-1].number);
}
#line 5611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 514:
#line 2499 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
#line 5619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 515:
#line 2504 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2509 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
#line 5635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2519 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2524 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2529 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2534 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2539 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number);
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2544 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2549 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2554 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2570 "conf_parser.y" /* yacc.c:1646  */
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

  case 529:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
#line 5754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
#line 5762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2614 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2619 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
#line 5818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
#line 5826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
#line 5834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
#line 5842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
#line 5850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.short_motd = yylval.number;
}
#line 5858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
#line 5866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
#line 5874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
#line 5882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
#line 5890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
#line 5898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.throttle_time = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes = 0;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2707 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2710 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2719 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2731 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2746 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2761 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2781 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 622:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 623:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 624:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 625:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 626:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[-1].number);
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  GlobalSetOptions.joinfloodtime = (yyvsp[-1].number);
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 646:
#line 2951 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 647:
#line 2957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 648:
#line 2963 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 2975 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
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
#line 6471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 2998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6489 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6493 "conf_parser.c" /* yacc.c:1646  */
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
