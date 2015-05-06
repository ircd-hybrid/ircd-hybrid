/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

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


#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_pseudo.h"
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
    nick,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    cert,
    rpass,
    spass,
    whois,
    class,
    target,
    prepend,
    command;

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
  dlink_node *node = NULL, *node_next = NULL;

  DLINK_FOREACH_SAFE(node, node_next, block_state.mask.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 190 "conf_parser.c" /* yacc.c:339  */

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
    DEFAULT_JOIN_FLOOD_COUNT = 279,
    DEFAULT_JOIN_FLOOD_TIME = 280,
    DEFAULT_MAX_CLIENTS = 281,
    DEFAULT_SPLIT_SERVER_COUNT = 282,
    DEFAULT_SPLIT_USER_COUNT = 283,
    DENY = 284,
    DESCRIPTION = 285,
    DIE = 286,
    DISABLE_AUTH = 287,
    DISABLE_FAKE_CHANNELS = 288,
    DISABLE_REMOTE_COMMANDS = 289,
    DLINE_MIN_CIDR = 290,
    DLINE_MIN_CIDR6 = 291,
    DOTS_IN_IDENT = 292,
    EMAIL = 293,
    ENCRYPTED = 294,
    EXCEED_LIMIT = 295,
    EXEMPT = 296,
    FAILED_OPER_NOTICE = 297,
    FLATTEN_LINKS = 298,
    GECOS = 299,
    GENERAL = 300,
    HIDDEN = 301,
    HIDDEN_NAME = 302,
    HIDE_CHANS = 303,
    HIDE_IDLE = 304,
    HIDE_IDLE_FROM_OPERS = 305,
    HIDE_SERVER_IPS = 306,
    HIDE_SERVERS = 307,
    HIDE_SERVICES = 308,
    HOST = 309,
    HUB = 310,
    HUB_MASK = 311,
    IGNORE_BOGUS_TS = 312,
    INVISIBLE_ON_CONNECT = 313,
    INVITE_CLIENT_COUNT = 314,
    INVITE_CLIENT_TIME = 315,
    IP = 316,
    IRCD_AUTH = 317,
    IRCD_FLAGS = 318,
    IRCD_SID = 319,
    KILL = 320,
    KILL_CHASE_TIME_LIMIT = 321,
    KLINE = 322,
    KLINE_EXEMPT = 323,
    KLINE_MIN_CIDR = 324,
    KLINE_MIN_CIDR6 = 325,
    KNOCK_CLIENT_COUNT = 326,
    KNOCK_CLIENT_TIME = 327,
    KNOCK_DELAY_CHANNEL = 328,
    LEAF_MASK = 329,
    LINKS_DELAY = 330,
    LISTEN = 331,
    MASK = 332,
    MAX_ACCEPT = 333,
    MAX_BANS = 334,
    MAX_CHANNELS = 335,
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
    SSL_DH_ELLIPTIC_CURVE = 408,
    SSL_DH_PARAM_FILE = 409,
    SSL_MESSAGE_DIGEST_ALGORITHM = 410,
    STATS_E_DISABLED = 411,
    STATS_I_OPER_ONLY = 412,
    STATS_K_OPER_ONLY = 413,
    STATS_M_OPER_ONLY = 414,
    STATS_O_OPER_ONLY = 415,
    STATS_P_OPER_ONLY = 416,
    STATS_U_OPER_ONLY = 417,
    T_ALL = 418,
    T_BOTS = 419,
    T_CALLERID = 420,
    T_CCONN = 421,
    T_COMMAND = 422,
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
    T_NCHANGE = 437,
    T_NONONREG = 438,
    T_OPME = 439,
    T_PREPEND = 440,
    T_PSEUDO = 441,
    T_RECVQ = 442,
    T_REJ = 443,
    T_RESTART = 444,
    T_SERVER = 445,
    T_SERVICE = 446,
    T_SERVNOTICE = 447,
    T_SET = 448,
    T_SHARED = 449,
    T_SIZE = 450,
    T_SKILL = 451,
    T_SOFTCALLERID = 452,
    T_SPY = 453,
    T_SSL = 454,
    T_SSL_CIPHER_LIST = 455,
    T_TARGET = 456,
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
    TS_MAX_DELTA = 471,
    TS_WARN_DELTA = 472,
    TWODOTS = 473,
    TYPE = 474,
    UNKLINE = 475,
    USE_LOGGING = 476,
    USER = 477,
    VHOST = 478,
    VHOST6 = 479,
    WARN_NO_CONNECT_BLOCK = 480,
    WHOIS = 481,
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
#define DEFAULT_JOIN_FLOOD_COUNT 279
#define DEFAULT_JOIN_FLOOD_TIME 280
#define DEFAULT_MAX_CLIENTS 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DLINE_MIN_CIDR 290
#define DLINE_MIN_CIDR6 291
#define DOTS_IN_IDENT 292
#define EMAIL 293
#define ENCRYPTED 294
#define EXCEED_LIMIT 295
#define EXEMPT 296
#define FAILED_OPER_NOTICE 297
#define FLATTEN_LINKS 298
#define GECOS 299
#define GENERAL 300
#define HIDDEN 301
#define HIDDEN_NAME 302
#define HIDE_CHANS 303
#define HIDE_IDLE 304
#define HIDE_IDLE_FROM_OPERS 305
#define HIDE_SERVER_IPS 306
#define HIDE_SERVERS 307
#define HIDE_SERVICES 308
#define HOST 309
#define HUB 310
#define HUB_MASK 311
#define IGNORE_BOGUS_TS 312
#define INVISIBLE_ON_CONNECT 313
#define INVITE_CLIENT_COUNT 314
#define INVITE_CLIENT_TIME 315
#define IP 316
#define IRCD_AUTH 317
#define IRCD_FLAGS 318
#define IRCD_SID 319
#define KILL 320
#define KILL_CHASE_TIME_LIMIT 321
#define KLINE 322
#define KLINE_EXEMPT 323
#define KLINE_MIN_CIDR 324
#define KLINE_MIN_CIDR6 325
#define KNOCK_CLIENT_COUNT 326
#define KNOCK_CLIENT_TIME 327
#define KNOCK_DELAY_CHANNEL 328
#define LEAF_MASK 329
#define LINKS_DELAY 330
#define LISTEN 331
#define MASK 332
#define MAX_ACCEPT 333
#define MAX_BANS 334
#define MAX_CHANNELS 335
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
#define SSL_DH_ELLIPTIC_CURVE 408
#define SSL_DH_PARAM_FILE 409
#define SSL_MESSAGE_DIGEST_ALGORITHM 410
#define STATS_E_DISABLED 411
#define STATS_I_OPER_ONLY 412
#define STATS_K_OPER_ONLY 413
#define STATS_M_OPER_ONLY 414
#define STATS_O_OPER_ONLY 415
#define STATS_P_OPER_ONLY 416
#define STATS_U_OPER_ONLY 417
#define T_ALL 418
#define T_BOTS 419
#define T_CALLERID 420
#define T_CCONN 421
#define T_COMMAND 422
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
#define T_NCHANGE 437
#define T_NONONREG 438
#define T_OPME 439
#define T_PREPEND 440
#define T_PSEUDO 441
#define T_RECVQ 442
#define T_REJ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_SSL 454
#define T_SSL_CIPHER_LIST 455
#define T_TARGET 456
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
#define TS_MAX_DELTA 471
#define TS_WARN_DELTA 472
#define TWODOTS 473
#define TYPE 474
#define UNKLINE 475
#define USE_LOGGING 476
#define USER 477
#define VHOST 478
#define VHOST6 479
#define WARN_NO_CONNECT_BLOCK 480
#define WHOIS 481
#define XLINE 482

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 689 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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
#define YYLAST   1249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  663
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1312

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
       0,   383,   383,   384,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   401,   402,
     403,   404,   405,   406,   407,   408,   409,   410,   414,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   425,   425,
     426,   427,   428,   429,   436,   439,   439,   440,   440,   440,
     442,   448,   455,   457,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   478,   518,   576,   605,   613,   627,   655,
     670,   685,   695,   709,   718,   746,   774,   799,   821,   843,
     852,   854,   854,   855,   856,   857,   858,   860,   869,   878,
     891,   890,   908,   908,   909,   909,   909,   911,   917,   927,
     926,   945,   945,   946,   946,   946,   946,   946,   948,   954,
     960,   966,   987,   988,   988,   990,   990,   991,   993,  1000,
    1000,  1013,  1014,  1016,  1016,  1017,  1017,  1019,  1027,  1030,
    1036,  1035,  1041,  1041,  1042,  1046,  1050,  1054,  1058,  1062,
    1066,  1070,  1081,  1080,  1169,  1169,  1170,  1171,  1172,  1173,
    1174,  1175,  1176,  1177,  1178,  1179,  1180,  1181,  1183,  1189,
    1195,  1201,  1207,  1218,  1224,  1230,  1241,  1248,  1247,  1253,
    1253,  1254,  1258,  1262,  1266,  1270,  1274,  1278,  1282,  1286,
    1290,  1294,  1298,  1302,  1306,  1310,  1314,  1318,  1322,  1326,
    1330,  1334,  1338,  1345,  1344,  1350,  1350,  1351,  1355,  1359,
    1363,  1367,  1371,  1375,  1379,  1383,  1387,  1391,  1395,  1399,
    1403,  1407,  1411,  1415,  1419,  1423,  1427,  1431,  1435,  1439,
    1450,  1449,  1511,  1511,  1512,  1513,  1514,  1515,  1516,  1517,
    1518,  1519,  1520,  1521,  1522,  1523,  1524,  1524,  1525,  1526,
    1527,  1528,  1530,  1536,  1542,  1548,  1554,  1560,  1566,  1572,
    1578,  1584,  1590,  1597,  1603,  1609,  1615,  1624,  1634,  1633,
    1639,  1639,  1640,  1644,  1655,  1654,  1661,  1660,  1665,  1665,
    1666,  1670,  1674,  1680,  1680,  1681,  1681,  1681,  1681,  1681,
    1683,  1683,  1685,  1685,  1687,  1700,  1717,  1723,  1733,  1732,
    1774,  1774,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,
    1783,  1785,  1791,  1797,  1803,  1815,  1814,  1820,  1820,  1821,
    1825,  1829,  1833,  1837,  1841,  1845,  1849,  1853,  1859,  1873,
    1882,  1896,  1895,  1910,  1910,  1911,  1911,  1911,  1911,  1913,
    1919,  1925,  1935,  1937,  1937,  1938,  1938,  1940,  1956,  1955,
    1980,  1980,  1981,  1981,  1981,  1981,  1983,  1989,  2009,  2008,
    2014,  2014,  2015,  2019,  2023,  2027,  2031,  2035,  2039,  2043,
    2047,  2051,  2061,  2060,  2081,  2081,  2082,  2082,  2082,  2084,
    2091,  2090,  2096,  2096,  2097,  2101,  2105,  2109,  2113,  2117,
    2121,  2125,  2129,  2133,  2143,  2142,  2214,  2214,  2215,  2216,
    2217,  2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,  2226,
    2227,  2228,  2229,  2231,  2237,  2243,  2249,  2262,  2275,  2281,
    2287,  2291,  2298,  2297,  2302,  2302,  2303,  2307,  2313,  2324,
    2330,  2336,  2342,  2358,  2357,  2383,  2383,  2384,  2384,  2384,
    2386,  2406,  2416,  2415,  2442,  2442,  2443,  2443,  2443,  2445,
    2451,  2460,  2462,  2462,  2463,  2463,  2465,  2483,  2482,  2505,
    2505,  2506,  2506,  2506,  2508,  2514,  2523,  2526,  2526,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,
    2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,
    2568,  2569,  2570,  2571,  2572,  2573,  2576,  2581,  2586,  2591,
    2597,  2602,  2607,  2612,  2617,  2622,  2627,  2632,  2637,  2642,
    2647,  2652,  2657,  2662,  2667,  2673,  2678,  2683,  2688,  2693,
    2698,  2703,  2708,  2711,  2716,  2719,  2724,  2729,  2734,  2739,
    2744,  2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,  2790,
    2789,  2794,  2794,  2795,  2798,  2801,  2804,  2807,  2810,  2813,
    2816,  2819,  2822,  2825,  2828,  2831,  2834,  2837,  2840,  2843,
    2846,  2849,  2852,  2855,  2858,  2864,  2863,  2868,  2868,  2869,
    2872,  2875,  2878,  2881,  2884,  2887,  2890,  2893,  2896,  2899,
    2902,  2905,  2908,  2911,  2914,  2917,  2920,  2923,  2926,  2931,
    2936,  2941,  2950,  2953,  2953,  2954,  2955,  2956,  2957,  2958,
    2959,  2960,  2961,  2962,  2963,  2964,  2965,  2966,  2967,  2968,
    2970,  2975,  2980,  2985,  2990,  2995,  3000,  3005,  3010,  3015,
    3020,  3025,  3030,  3035,  3043,  3046,  3046,  3047,  3048,  3049,
    3050,  3051,  3052,  3053,  3054,  3055,  3057,  3063,  3069,  3075,
    3081,  3090,  3105,  3111
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
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR",
  "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT",
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
  "SSL_CONNECTION_REQUIRED", "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE",
  "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS",
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TKLINE_EXPIRE_NOTICES", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "';'", "'}'", "'{'", "'='",
  "','", "':'", "$accept", "conf", "conf_item", "timespec_", "timespec",
  "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@2", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@3", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@4", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_rsa_public_key_file",
  "oper_ssl_certificate_fingerprint", "oper_ssl_connection_required",
  "oper_class", "oper_umodes", "$@6", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@7", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@8", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@9", "class_flags_items", "class_flags_item",
  "listen_entry", "$@10", "listen_flags", "$@11", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@12", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@13", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@14",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@21",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@22", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@23",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@24",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_away_count",
  "general_away_time", "general_max_watch", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_invisible_on_connect",
  "general_warn_no_connect_block", "general_stats_e_disabled",
  "general_stats_m_oper_only", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_u_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_ping_cookie",
  "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
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

#define YYPACT_NINF -1036

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1036)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1036,   646, -1036,  -193,  -226,  -211, -1036, -1036, -1036,  -206,
   -1036,  -177, -1036, -1036, -1036,  -163, -1036, -1036, -1036,  -149,
    -139, -1036,  -128, -1036,  -104, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,   311,   884,  -102,   -96,   -69,    17,   -68,   439,   -60,
     -58,   -57,   199,   -49,   -18,   -17,   351,   547,     0,    24,
      12,    44,    34,   -89,   -47,   -42,    64,    10, -1036, -1036,
   -1036, -1036, -1036,    77,    78,    79,    86,    89,    91,    96,
     108,   113,   114,   120,   127,   135,   138,   226, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   675,   518,    11, -1036,   152,    32, -1036,
   -1036,    19, -1036,   156,   159,   160,   164,   169,   170,   174,
     175,   176,   177,   179,   181,   182,   183,   186,   188,   191,
     196,   197,   198,   200,   203,   204,   206,   210, -1036,   211,
   -1036,   212,   213,   216,   220,   225,   227,   229,   233,   236,
     241,   246,   248,   249,   251,   253,   254,   257,   260,     7,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,   360,    22,    26,
      43,   261,   262,    14, -1036, -1036, -1036,    27,   318,    30,
   -1036,   263,   264,   267,   269,   271,   272,   273,   275,     4,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,    56,
     287,   291,   294,   296,   300,   303,   305,   307,   308,   312,
     316,   322,   327,   329,   330,   332,   334,   124, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,    85,    97,   335,    67,
   -1036, -1036, -1036,    61,   195, -1036,   336,    40, -1036, -1036,
      53, -1036,   244,   259,   297,   202, -1036,   441,   460,   461,
     462,   331,   463,   460,   467,   460,   460,   468,   470,   368,
     369,   240, -1036,   356,   355,   357,   358, -1036,   359,   362,
     363,   372,   373,   376,   377,   378,   381,   382,   384,   386,
     388,    94, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     392,   390,   391,   393,   394,   395,   397, -1036,   398,   399,
     400,   401,   403,   405,   408,   192, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,   411,   413,    74, -1036, -1036, -1036,   464,   429,
   -1036, -1036,   427,   428,    31, -1036, -1036, -1036,   452,   460,
     498,   460,   460,   456,   560,   459,   563,   564,   565,   466,
     472,   473,   460,   566,   570,   577,   578,   460,   580,   581,
     586,   587,   487,   474,   492,   475,   493,   460,   460,   496,
     499,   501,  -189,  -127,   502,   503,   504,   505,   601,   460,
     506,   460,   460,   508,   495, -1036,   497,   489,   490, -1036,
     509,   513,   514,   515,   519,   189, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   520,   521,    60, -1036,
   -1036, -1036,   500,   522,   523, -1036,   530, -1036,    36, -1036,
   -1036, -1036, -1036, -1036,   606,   607,   507, -1036,   534,   535,
     537,    33, -1036, -1036, -1036,   541,   545,   548, -1036,   549,
     550,   551,   552,   555, -1036,   556,   558,   237, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     573,   561,   562,   576,     5, -1036, -1036, -1036, -1036,   525,
     526,   538,   609,   554,   567,   583,   460,   584, -1036, -1036,
     625,   611,   593,   686,   703,   709,   696,   697,   699,   700,
     701,   705,   710,   711,   712,   715,   716,   598, -1036,   617,
     615, -1036,    82, -1036, -1036, -1036, -1036,   638,   624, -1036,
     626,   629,   623,   628,   632,   634,    62, -1036, -1036, -1036,
   -1036, -1036,   744,   640, -1036,   641,   642, -1036,   647,    51,
   -1036, -1036, -1036, -1036,   643,   644,   649, -1036,   651,   375,
     652,   661,   664,   666,   669,   671,   674,   677,   679,   690,
     691,   692,   694, -1036, -1036,   795,   815,   460,   693,   817,
     819,   820,   460,   821,   822,   460,   808,   824,   825,   460,
     826,   826,   707, -1036, -1036,   813,  -109,   818,   727,   823,
     827,   714,   828,   829,   834,   831,   835,   836,   838,   719,
   -1036,   839,   842,   720, -1036,   721, -1036,   843,   844,   740,
   -1036,   741,   742,   743,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   762,
     763,   764,   765,   766,   767,   768,   718,   769,   633,   770,
     771,   772,   773,   774,   775,   776,   777,   778,   779,   780,
     781,   782,   783,   784,   785,   786,   787,   788,   789, -1036,
   -1036,   849,   807,   790,   896,   912,   899,   900,   901,   797,
   -1036,   903,   904,   800, -1036, -1036,   906,   907,   801,   923,
     805, -1036,   806,   809, -1036, -1036,   913,   915,   811, -1036,
   -1036,   917,   830,   804,   919,   920,   921,   922,   837,   816,
     926,   927,   832, -1036, -1036,   928,   929,   930,   833, -1036,
     840,   841,   845,   846,   847,   848,   850,   851, -1036,   852,
     853,   854,   855,   856,   857,   858,   859,   860,   861,   862,
     863,   864,   865,   866,   867,   868, -1036, -1036,   931,   869,
     870, -1036,   871, -1036,   151, -1036,   932,   933,   934,   935,
     873, -1036,   874, -1036, -1036,   936,   872,   939,   876, -1036,
   -1036, -1036, -1036, -1036,   460,   460,   460,   460,   460,   460,
     460, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   877,   878,   879,    16,
     880,   881,   882,   883,   885,   886,   887,   888,   889,   890,
     891,   205,   892,   893, -1036,   894,   895,   897,   898,   902,
     905,   908,    -5,   909,   910,   911,   914,   916,   918,   924,
   -1036,   925,   937, -1036, -1036,   938,   940, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   -91, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   -41, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     941,   942,   325,   943,   944,   945,   946,   947, -1036,   948,
     949, -1036,   950,   951,    68,   962,   814, -1036, -1036, -1036,
   -1036,   953,   954, -1036,   955,   956,   434,   957,   958,   959,
     960,   961,   678,   963,   964, -1036,   965,   966,   967, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,   968,   568, -1036, -1036,   969,
     970,   971, -1036,    73, -1036, -1036, -1036, -1036,   972,   975,
     976,   977, -1036, -1036,   978,   733,   979, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     -26, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   826,   826,   826, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   -23,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   718, -1036,   633, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,    55, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,   100, -1036,   989,   923,   980, -1036, -1036, -1036, -1036,
   -1036,   981, -1036,   982, -1036, -1036, -1036, -1036,   983, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     110, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   122,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,   128, -1036, -1036,
    1001,   -46,   986,   984, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     131, -1036, -1036, -1036,    16, -1036, -1036, -1036, -1036,    -5,
   -1036, -1036, -1036,   325, -1036,    68, -1036, -1036, -1036,   998,
     999,  1000, -1036,   434, -1036,   678, -1036,   568,   985,   990,
     991,   319, -1036, -1036,   733, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   136, -1036, -1036, -1036,
     319, -1036
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   394,   442,     0,
     457,     0,   298,   433,   274,     0,   100,   152,   331,     0,
       0,   372,     0,   109,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   628,
     616,   617,   618,   619,   620,   621,   615,   622,   623,   624,
     625,   626,   627,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   515,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,     0,
     559,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,   469,   470,   513,   514,   508,   509,   510,   511,   507,
     480,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     481,   482,   512,   486,   487,   488,   489,   485,   484,   490,
     498,   499,   491,   492,   493,   494,   483,   496,   505,   506,
     503,   504,   497,   495,   501,   502,   500,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     655,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     646,   647,   648,   649,   650,   653,   651,   652,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   346,     0,     0,   344,   345,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   613,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   237,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   235,   236,   238,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,   422,     0,     0,
       0,     0,     0,     0,     0,     0,   397,   398,   399,   400,
     401,   402,   403,   405,   404,   407,   411,   408,   409,   410,
     406,   448,     0,     0,     0,   445,   446,   447,     0,     0,
     452,   463,     0,     0,     0,   460,   461,   462,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   467,     0,     0,     0,   315,
       0,     0,     0,     0,     0,     0,   301,   302,   303,   304,
     309,   305,   306,   307,   308,   439,     0,     0,     0,   436,
     437,   438,     0,     0,     0,   276,     0,   286,     0,   284,
     285,   287,   288,    49,     0,     0,     0,    45,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,   203,     0,
       0,     0,     0,     0,   177,     0,     0,     0,   155,   156,
     157,   158,   159,   162,   163,   164,   165,   161,   160,   166,
       0,     0,     0,     0,     0,   334,   335,   336,   337,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   645,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   380,     0,   375,   376,   377,   127,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   115,
     114,   116,     0,     0,   343,     0,     0,   358,     0,     0,
     351,   352,   353,   354,     0,     0,     0,    90,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,   412,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     396,     0,     0,     0,   444,     0,   451,     0,     0,     0,
     459,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,     0,   435,   289,     0,     0,     0,     0,
       0,   283,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   338,     0,     0,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,   644,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   378,     0,     0,
       0,   374,     0,   122,     0,   117,     0,     0,     0,     0,
       0,   111,     0,   342,   355,     0,     0,     0,     0,   350,
      99,    98,    97,   642,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   643,   639,   638,   630,   631,   632,   633,
     634,   635,   637,   636,   640,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,     0,     0,   443,   456,     0,     0,   458,   528,   532,
     516,   517,   547,   519,   611,   556,   520,   521,   553,   527,
     526,   535,   525,   522,   523,   531,   530,   529,   554,   518,
     609,   610,   551,   595,   589,   605,   590,   591,   592,   600,
     608,   593,   602,   606,   596,   607,   597,   601,   594,   604,
     599,   598,   603,     0,   588,   552,   568,   569,   570,   563,
     581,   564,   565,   566,   576,   584,   567,   578,   582,   572,
     583,   573,   577,   571,   580,   575,   574,   579,     0,   562,
     548,   546,   549,   555,   550,   537,   544,   545,   542,   543,
     538,   539,   540,   541,   557,   558,   524,   534,   533,   536,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,   434,     0,     0,     0,   294,   290,   293,   275,    50,
      51,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   332,
     657,   656,   662,   660,   663,   658,   659,   661,    86,    81,
      89,    80,    87,    88,    79,    83,    82,    74,    73,    78,
      75,    77,    76,    84,    85,     0,     0,   373,   128,     0,
       0,     0,   140,     0,   132,   133,   135,   134,     0,     0,
       0,     0,   110,   347,     0,     0,     0,   349,    31,    32,
      33,    34,    35,    36,    37,   263,   264,   255,   273,   272,
       0,   271,   256,   258,   260,   267,   259,   257,   266,   252,
     265,   254,   253,    38,    38,    38,    40,    39,   261,   262,
     417,   420,   421,   431,   428,   414,   429,   426,   427,     0,
     425,   430,   413,   419,   416,   418,   432,   415,   449,   450,
     464,   465,   586,     0,   560,     0,   313,   314,   323,   320,
     321,   322,   327,   324,   325,   319,   326,     0,   318,   312,
     330,   329,   328,   311,   441,   440,   297,   296,   281,   282,
     280,     0,   279,     0,     0,     0,   107,   108,   176,   172,
     222,   210,   219,   208,   213,   228,   221,   226,   212,   215,
     223,   225,   229,   220,   227,   216,   218,   224,   214,   217,
       0,   206,   168,   170,   173,   174,   175,   186,   187,   188,
     181,   199,   182,   183,   184,   194,   202,   185,   196,   200,
     190,   201,   191,   195,   189,   198,   193,   192,   197,     0,
     180,   169,   171,   341,   339,   340,   379,   384,   390,   393,
     386,   392,   387,   391,   389,   385,   388,     0,   383,   136,
       0,     0,     0,     0,   131,   119,   118,   120,   121,   356,
     362,   368,   371,   364,   370,   365,   369,   367,   363,   366,
       0,   361,   357,   269,     0,    41,    42,    43,   423,     0,
     587,   561,   316,     0,   277,     0,   295,   292,   291,     0,
       0,     0,   204,     0,   178,     0,   381,     0,     0,     0,
       0,     0,   130,   359,     0,   270,   424,   317,   278,   209,
     207,   211,   205,   179,   382,   137,   139,   138,   150,   149,
     145,   147,   151,   148,   144,   146,     0,   143,   360,   141,
       0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1036, -1036, -1036,  -452,  -306, -1035,  -640, -1036, -1036,   987,
   -1036, -1036, -1036, -1036,   796, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   988, -1036, -1036, -1036, -1036, -1036,
   -1036,   569, -1036, -1036, -1036, -1036, -1036,   478, -1036, -1036,
   -1036, -1036, -1036, -1036,   875, -1036, -1036, -1036, -1036,    13,
   -1036, -1036, -1036, -1036, -1036,  -243, -1036, -1036, -1036,   595,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,  -204, -1036, -1036, -1036,  -201, -1036, -1036, -1036,
     736, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
    -123, -1036, -1036, -1036, -1036, -1036,  -133, -1036,   653, -1036,
   -1036, -1036,   -20, -1036, -1036, -1036, -1036, -1036,   670, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,  -120, -1036, -1036, -1036,
   -1036, -1036, -1036,   613, -1036, -1036, -1036, -1036, -1036,   952,
   -1036, -1036, -1036, -1036,   546, -1036, -1036, -1036, -1036, -1036,
    -144, -1036, -1036, -1036,   579, -1036, -1036, -1036, -1036,  -129,
   -1036, -1036, -1036,   792, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,  -110, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   672, -1036, -1036, -1036, -1036, -1036,
     760, -1036, -1036, -1036, -1036,  1037, -1036, -1036, -1036, -1036,
     794, -1036, -1036, -1036, -1036,   992, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
      35, -1036, -1036, -1036,    39, -1036, -1036, -1036, -1036, -1036,
    1059, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,   993, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   831,   832,  1096,  1097,    27,   223,   224,
     225,   226,    28,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,    29,    77,    78,    79,    80,    81,    30,    63,
     501,   502,   503,   504,    31,    70,   586,   587,   588,   589,
     590,   591,    32,   289,   290,   291,   292,   293,  1053,  1054,
    1055,  1056,  1057,  1232,  1306,  1307,    33,    64,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     759,  1209,  1210,   529,   753,  1180,  1181,    34,    53,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   628,  1080,
    1081,    35,    61,   487,   738,  1151,  1152,   488,   489,   490,
    1155,   996,   997,   491,   492,    36,    59,   465,   466,   467,
     468,   469,   470,   471,   723,  1137,  1138,   472,   473,   474,
      37,    65,   534,   535,   536,   537,   538,    38,   297,   298,
     299,    39,    72,   599,   600,   601,   602,   603,   816,  1250,
    1251,    40,    68,   572,   573,   574,   575,   799,  1227,  1228,
      41,    54,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   651,  1109,  1110,   386,   387,   388,   389,
     390,    42,    60,   478,   479,   480,   481,    43,    55,   394,
     395,   396,   397,    44,   118,   119,   120,    45,    57,   404,
     405,   406,   407,    46,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   435,   958,
     959,   213,   433,   933,   934,   214,   215,   216,    47,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,    48,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     862,   863,   610,  1107,    51,   230,   530,   615,   122,   617,
     618,    73,   391,   123,   124,   220,   125,   126,   116,    52,
     401,   127,   705,   475,    56,   287,   706,   482,   498,   128,
     129,   530,   401,   116,   498,    49,    50,   482,   231,   130,
      74,   295,   131,   132,   133,   295,   531,   232,    75,   134,
     233,   234,   595,    58,   595,   235,   236,   237,  1255,  1256,
    1257,   475,   861,   581,   135,   136,  1078,    62,   287,   866,
     867,   531,   392,   137,  1049,   391,   138,   139,   117,   238,
     483,    66,   532,   569,   707,   140,   569,   484,   708,   485,
     483,    67,   141,   117,   142,   323,   143,   484,   144,   485,
     145,   146,    69,   672,   499,   674,   675,   532,    76,   221,
     499,   324,   325,   147,  1148,   326,   685,   402,   148,   149,
     150,   690,   151,   152,   153,   249,    71,   154,   113,   402,
     533,   700,   701,   222,   114,   392,   393,  1122,   296,   301,
    1079,  1123,   296,   714,   403,   716,   717,   476,   486,   596,
     250,   596,  1049,   155,   251,   533,   403,   327,   486,  1279,
     582,   115,   121,   156,   157,   158,   159,   160,   161,   162,
     217,  1050,   218,   219,   328,   329,   330,   331,   332,   252,
     570,   227,   333,   570,   302,   476,   334,  1124,   253,   303,
     456,  1125,   335,   360,  1108,   361,   581,   362,  -129,   393,
     220,   500,  1253,   336,   337,  1258,  1254,   500,   457,  1259,
     254,   363,   228,   229,   255,   338,  1093,  1094,  1095,   163,
     164,   165,   256,   166,   167,   257,   258,    82,   458,   583,
     286,   364,   168,   547,   768,   580,   454,   339,   505,   305,
     777,  -129,   294,   496,   477,   288,   365,   584,   366,  1050,
      83,    84,   459,    85,    86,   367,   506,   259,  1149,    87,
     669,   399,   748,   585,   300,   740,   368,  1150,  1051,   593,
     597,   493,   597,   598,   260,   598,   507,   261,   262,   263,
     818,   340,   477,  1262,   549,    88,    89,  1263,   288,   733,
     369,   810,  1052,   582,   221,   304,   578,    90,    91,    92,
     508,   571,  1233,   663,   571,    93,    94,   460,   307,   308,
     309,   800,    73,   861,   370,   461,   462,   310,   222,   505,
     311,   848,   312,   642,   264,   576,   853,   313,  1264,   856,
      95,    96,  1265,   860,   371,   509,   463,   506,  1272,   314,
    1128,    74,  1273,   372,   315,   316,  1051,   265,   266,    75,
    1274,   317,   230,   567,  1275,   510,  1276,   507,   318,  1283,
    1277,   456,   583,  1284,  1309,  1129,   319,   604,  1310,   320,
    1052,   511,  1068,  1069,  1070,  1071,  1072,  1073,  1074,   457,
     584,   508,   605,   398,  1298,   231,  1299,   408,   512,   513,
     409,   410,   373,  1130,   232,   411,   585,   233,   234,   458,
     412,   413,   235,   236,   237,   414,   415,   416,   417,    76,
     418,   464,   419,   420,   421,   374,   509,   422,   729,   423,
     606,   659,   424,   459,  1131,  1132,   238,   425,   426,   427,
     607,   428,  1133,  1300,   429,   430,   510,   431,  1160,   514,
     122,   432,   434,   436,   437,   123,   124,   438,   125,   126,
    1301,   439,   511,   127,  1161,   321,   440,  1134,   441,   515,
     442,   128,   129,   516,   443,  1162,   762,   444,   623,   512,
     513,   130,   445,  1135,   131,   132,   133,   446,   460,   447,
     448,   134,   449,   609,   450,   451,   461,   462,   452,  1302,
    1303,   453,   494,   495,   539,   540,   135,   136,   541,  1163,
     542,  1164,   543,   544,   545,   137,   546,   463,   138,   139,
     824,   825,   826,   827,   828,   829,   830,   140,   550,   360,
     514,   361,   551,   362,   141,   552,   142,   553,   143,  1165,
     144,   554,   145,   146,   555,  1136,   556,   363,   557,   558,
     515,  1304,   613,   559,   516,   147,  1305,   560,   249,   608,
     148,   149,   150,   561,   151,   152,   153,   364,   562,   154,
     563,   564,  1166,   565,  1167,   566,   577,   592,   609,   611,
     612,   614,   365,   250,   366,   616,   619,   251,   620,   621,
     622,   367,   464,  1168,   624,   155,   625,   665,   626,   627,
     629,  1280,   368,   630,   631,   156,   157,   158,   159,   160,
     161,   162,   252,   632,   633,  1169,   673,   634,   635,   636,
    1170,   253,   637,   638,  1171,   639,   369,   640,  1172,   641,
     644,   645,   646,  1173,   647,   648,   649,  1174,   650,   652,
     653,   654,   655,   254,   656,  1217,   657,   255,  1175,   658,
     370,  1176,   661,  1177,   662,   256,     2,     3,   257,   258,
       4,   163,   164,   165,  1178,   166,   167,   666,   667,   668,
     371,  1179,     5,   671,   168,     6,     7,   676,   677,   372,
     678,   679,   680,   681,   686,     8,   323,   682,   687,   936,
     259,   937,   938,   683,   684,   688,   689,     9,   691,   692,
      10,    11,   324,   325,   693,   694,   326,   260,   695,  1218,
     261,   262,   263,   697,   699,   696,   698,   702,    12,   713,
     703,    13,   704,   709,   710,   711,   712,   715,   373,   718,
     721,   722,    14,   719,  1187,   720,  1188,  1189,   735,   742,
     743,  1219,   773,   779,   780,   744,   770,   771,   327,  1220,
     724,   374,    15,    16,   725,   726,   727,   264,  1221,   772,
     728,   731,   732,   736,   737,   328,   329,   330,   331,   332,
      17,   739,   745,   333,   913,   774,   746,   334,   747,   750,
     265,   266,  1222,   335,  1223,  1224,   751,    18,   775,   752,
     754,   755,   756,   757,   336,   337,   758,   760,  1225,   761,
      19,    20,   765,   766,   776,  1226,   338,   939,   940,   941,
    1240,   764,   942,   943,   781,   944,   945,   767,   946,   782,
     947,   783,   778,   948,    21,   949,   950,   784,   339,   785,
     786,   951,   787,   788,   789,   952,   796,    22,   790,   953,
     954,   955,    23,   791,   792,   793,   956,    24,   794,   795,
      25,   957,  1190,  1191,  1192,   797,   798,  1193,  1194,   802,
    1195,  1196,   803,  1197,   806,  1198,   804,   805,  1199,   807,
    1200,  1201,   340,   808,  1241,   809,  1202,   812,   813,   814,
    1203,   820,   821,   815,  1204,  1205,  1206,   822,   817,   823,
     833,  1207,   914,   915,   916,    82,  1208,   917,   918,   834,
     919,   920,   835,   921,   836,   922,  1242,   837,   923,   838,
     924,   925,   839,   846,  1243,   840,   926,   841,    83,    84,
     927,    85,    86,  1244,   928,   929,   930,    87,   842,   843,
     844,   931,   845,   847,   849,   850,   932,   851,   852,   854,
     855,   857,   858,   859,   861,   864,   865,  1245,   869,  1246,
    1247,   868,   875,    88,    89,   872,   870,   880,   883,   884,
     871,   873,   874,  1248,   876,    90,    91,    92,   877,   878,
    1249,   879,   881,    93,    94,   882,   885,   886,   887,   888,
     889,   890,   980,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,    95,    96,
     906,   907,   908,   909,   910,   911,   912,   935,   960,   961,
     962,   963,   964,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,   978,   979,   981,   983,
     984,   982,   985,   986,   987,   988,   989,   990,   991,   992,
     993,   995,   994,   998,   999,  1006,  1001,  1000,  1002,  1003,
    1004,  1005,  1007,  1008,  1009,  1010,  1154,  1012,  1011,  1013,
    1014,  1016,  1017,  1018,  1045,  1058,  1059,  1060,  1061,  1064,
    1015,  1019,  1066,   568,   811,   306,  1234,  1311,  1020,  1021,
     749,  1293,  1292,  1022,  1023,  1024,  1025,   643,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,  1043,  1044,  1266,  1047,  1048,
    1046,  1062,  1063,  1065,  1067,  1075,  1076,  1077,  1082,  1083,
    1084,  1085,   763,  1086,  1087,  1088,  1089,  1090,  1091,  1092,
    1098,  1099,  1100,  1101,  1278,  1102,  1103,  1289,  1290,  1291,
    1104,  1285,  1288,  1105,  1267,   730,  1106,  1111,  1112,  1113,
    1308,   741,  1114,  1287,  1115,   819,  1116,   769,  1294,  1286,
     734,   801,  1117,  1118,   664,   400,   322,     0,     0,     0,
    1261,   455,  1260,     0,   579,  1119,  1120,   660,  1121,  1126,
    1127,  1139,  1140,  1141,  1142,  1143,  1144,  1145,  1146,  1147,
    1153,  1156,  1157,  1158,  1159,  1182,  1183,  1184,  1185,  1186,
       0,  1211,  1212,  1213,  1214,  1215,  1216,  1229,   670,     0,
    1235,  1230,  1231,  1236,  1237,  1238,  1239,  1252,  1268,     0,
     497,     0,  1282,  1295,  1269,  1270,  1271,  1281,  1296,  1297,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   548,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   594
};

static const yytype_int16 yycheck[] =
{
     640,   641,   308,     8,   230,     1,     1,   313,     1,   315,
     316,     1,     1,     6,     7,     1,     9,    10,     1,   230,
       1,    14,   211,     1,   230,     1,   215,     1,     1,    22,
      23,     1,     1,     1,     1,   228,   229,     1,    34,    32,
      30,     1,    35,    36,    37,     1,    41,    43,    38,    42,
      46,    47,     1,   230,     1,    51,    52,    53,  1093,  1094,
    1095,     1,   108,     1,    57,    58,    50,   230,     1,   178,
     179,    41,    61,    66,     1,     1,    69,    70,    61,    75,
      54,   230,    77,     1,   211,    78,     1,    61,   215,    63,
      54,   230,    85,    61,    87,     1,    89,    61,    91,    63,
      93,    94,   230,   409,    77,   411,   412,    77,    98,    95,
      77,    17,    18,   106,    46,    21,   422,    98,   111,   112,
     113,   427,   115,   116,   117,     1,   230,   120,   230,    98,
     125,   437,   438,   119,   230,    61,   125,   228,    98,   228,
     124,   232,    98,   449,   125,   451,   452,   125,   122,    98,
      26,    98,     1,   146,    30,   125,   125,    63,   122,   205,
      98,   230,   230,   156,   157,   158,   159,   160,   161,   162,
     230,    98,   230,   230,    80,    81,    82,    83,    84,    55,
      98,   230,    88,    98,   231,   125,    92,   228,    64,   231,
       1,   232,    98,     1,   199,     3,     1,     5,   174,   125,
       1,   174,   228,   109,   110,   228,   232,   174,    19,   232,
      86,    19,   230,   230,    90,   121,    11,    12,    13,   212,
     213,   214,    98,   216,   217,   101,   102,     1,    39,   167,
     230,    39,   225,   229,   229,   174,   229,   143,     1,   229,
     546,   174,   230,   229,   222,   221,    54,   185,    56,    98,
      24,    25,    63,    27,    28,    63,    19,   133,   190,    33,
     229,   229,   229,   201,   230,   229,    74,   199,   195,   229,
     219,   228,   219,   222,   150,   222,    39,   153,   154,   155,
     229,   187,   222,   228,   228,    59,    60,   232,   221,   229,
      98,   229,   219,    98,    95,   231,   229,    71,    72,    73,
      63,   219,   229,   229,   219,    79,    80,   118,   231,   231,
     231,   229,     1,   108,   122,   126,   127,   231,   119,     1,
     231,   627,   231,   229,   200,   228,   632,   231,   228,   635,
     104,   105,   232,   639,   142,    98,   147,    19,   228,   231,
      15,    30,   232,   151,   231,   231,   195,   223,   224,    38,
     228,   231,     1,   229,   232,   118,   228,    39,   231,   228,
     232,     1,   167,   232,   228,    40,   231,   123,   232,   231,
     219,   134,   824,   825,   826,   827,   828,   829,   830,    19,
     185,    63,   123,   231,    65,    34,    67,   231,   151,   152,
     231,   231,   200,    68,    43,   231,   201,    46,    47,    39,
     231,   231,    51,    52,    53,   231,   231,   231,   231,    98,
     231,   222,   231,   231,   231,   223,    98,   231,   229,   231,
     123,   229,   231,    63,    99,   100,    75,   231,   231,   231,
     228,   231,   107,   114,   231,   231,   118,   231,     4,   202,
       1,   231,   231,   231,   231,     6,     7,   231,     9,    10,
     131,   231,   134,    14,    20,   229,   231,   132,   231,   222,
     231,    22,    23,   226,   231,    31,   229,   231,   228,   151,
     152,    32,   231,   148,    35,    36,    37,   231,   118,   231,
     231,    42,   231,   108,   231,   231,   126,   127,   231,   170,
     171,   231,   231,   231,   231,   231,    57,    58,   231,    65,
     231,    67,   231,   231,   231,    66,   231,   147,    69,    70,
     135,   136,   137,   138,   139,   140,   141,    78,   231,     1,
     202,     3,   231,     5,    85,   231,    87,   231,    89,    95,
      91,   231,    93,    94,   231,   210,   231,    19,   231,   231,
     222,   222,   211,   231,   226,   106,   227,   231,     1,   108,
     111,   112,   113,   231,   115,   116,   117,    39,   231,   120,
     231,   231,   128,   231,   130,   231,   231,   231,   108,   108,
     108,   108,    54,    26,    56,   108,   108,    30,   108,   211,
     211,    63,   222,   149,   228,   146,   231,   123,   231,   231,
     231,  1231,    74,   231,   231,   156,   157,   158,   159,   160,
     161,   162,    55,   231,   231,   171,   108,   231,   231,   231,
     176,    64,   231,   231,   180,   231,    98,   231,   184,   231,
     228,   231,   231,   189,   231,   231,   231,   193,   231,   231,
     231,   231,   231,    86,   231,    67,   231,    90,   204,   231,
     122,   207,   231,   209,   231,    98,     0,     1,   101,   102,
       4,   212,   213,   214,   220,   216,   217,   228,   231,   231,
     142,   227,    16,   211,   225,    19,    20,   211,   108,   151,
     211,   108,   108,   108,   108,    29,     1,   211,   108,    46,
     133,    48,    49,   211,   211,   108,   108,    41,   108,   108,
      44,    45,    17,    18,   108,   108,    21,   150,   211,   131,
     153,   154,   155,   211,   211,   231,   231,   211,    62,   108,
     211,    65,   211,   211,   211,   211,   211,   211,   200,   211,
     231,   231,    76,   228,    46,   228,    48,    49,   228,   123,
     123,   163,   123,   108,   123,   228,   211,   211,    63,   171,
     231,   223,    96,    97,   231,   231,   231,   200,   180,   211,
     231,   231,   231,   231,   231,    80,    81,    82,    83,    84,
     114,   231,   228,    88,    46,   211,   231,    92,   231,   228,
     223,   224,   204,    98,   206,   207,   231,   131,   211,   231,
     231,   231,   231,   231,   109,   110,   231,   231,   220,   231,
     144,   145,   231,   231,   211,   227,   121,   164,   165,   166,
      67,   228,   169,   170,   211,   172,   173,   231,   175,   123,
     177,   108,   228,   180,   168,   182,   183,   108,   143,   123,
     123,   188,   123,   123,   123,   192,   228,   181,   123,   196,
     197,   198,   186,   123,   123,   123,   203,   191,   123,   123,
     194,   208,   164,   165,   166,   228,   231,   169,   170,   211,
     172,   173,   228,   175,   231,   177,   230,   228,   180,   231,
     182,   183,   187,   231,   131,   231,   188,   123,   228,   228,
     192,   228,   228,   231,   196,   197,   198,   228,   231,   228,
     228,   203,   164,   165,   166,     1,   208,   169,   170,   228,
     172,   173,   228,   175,   228,   177,   163,   228,   180,   228,
     182,   183,   228,   108,   171,   228,   188,   228,    24,    25,
     192,    27,    28,   180,   196,   197,   198,    33,   228,   228,
     228,   203,   228,   108,   231,   108,   208,   108,   108,   108,
     108,   123,   108,   108,   108,   228,   123,   204,   211,   206,
     207,   123,   108,    59,    60,   231,   123,   228,   228,   228,
     123,   123,   123,   220,   123,    71,    72,    73,   123,   123,
     227,   123,   123,    79,    80,   123,   123,   123,   228,   228,
     228,   228,   123,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   104,   105,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   211,   123,
     108,   231,   123,   123,   123,   228,   123,   123,   228,   123,
     123,   108,   231,   228,   228,   231,   123,   228,   123,   228,
     123,   211,   123,   123,   123,   123,   232,   231,   211,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     228,   228,   123,   267,   586,    77,  1053,  1310,   228,   228,
     501,  1275,  1273,   228,   228,   228,   228,   341,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   108,   228,   228,
     231,   228,   228,   231,   228,   228,   228,   228,   228,   228,
     228,   228,   517,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   123,   228,   228,   129,   129,   129,
     228,  1254,  1265,   228,  1154,   465,   228,   228,   228,   228,
    1284,   488,   228,  1263,   228,   599,   228,   534,  1277,  1259,
     478,   572,   228,   228,   394,   118,    97,    -1,    -1,    -1,
    1125,   169,  1123,    -1,   289,   228,   228,   375,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     218,   228,   228,   228,   228,   228,   228,   228,   228,   228,
      -1,   228,   228,   228,   228,   228,   228,   228,   404,    -1,
     228,   231,   231,   228,   228,   228,   228,   228,   228,    -1,
     223,    -1,   228,   228,   233,   233,   233,   231,   228,   228,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   239,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   297
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   235,     0,     1,     4,    16,    19,    20,    29,    41,
      44,    45,    62,    65,    76,    96,    97,   114,   131,   144,
     145,   168,   181,   186,   191,   194,   236,   241,   246,   266,
     272,   278,   286,   300,   321,   345,   359,   374,   381,   385,
     395,   404,   425,   431,   437,   441,   447,   502,   519,   228,
     229,   230,   230,   322,   405,   432,   230,   442,   230,   360,
     426,   346,   230,   273,   301,   375,   230,   230,   396,   230,
     279,   230,   386,     1,    30,    38,    98,   267,   268,   269,
     270,   271,     1,    24,    25,    27,    28,    33,    59,    60,
      71,    72,    73,    79,    80,   104,   105,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   230,   230,   230,     1,    61,   438,   439,
     440,   230,     1,     6,     7,     9,    10,    14,    22,    23,
      32,    35,    36,    37,    42,    57,    58,    66,    69,    70,
      78,    85,    87,    89,    91,    93,    94,   106,   111,   112,
     113,   115,   116,   117,   120,   146,   156,   157,   158,   159,
     160,   161,   162,   212,   213,   214,   216,   217,   225,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   495,   499,   500,   501,   230,   230,   230,
       1,    95,   119,   242,   243,   244,   245,   230,   230,   230,
       1,    34,    43,    46,    47,    51,    52,    53,    75,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,     1,
      26,    30,    55,    64,    86,    90,    98,   101,   102,   133,
     150,   153,   154,   155,   200,   223,   224,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   230,     1,   221,   287,
     288,   289,   290,   291,   230,     1,    98,   382,   383,   384,
     230,   228,   231,   231,   231,   229,   268,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   229,   504,     1,    17,    18,    21,    63,    80,    81,
      82,    83,    84,    88,    92,    98,   109,   110,   121,   143,
     187,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
       1,     3,     5,    19,    39,    54,    56,    63,    74,    98,
     122,   142,   151,   200,   223,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   415,   416,   420,   421,   422,   423,
     424,     1,    61,   125,   433,   434,   435,   436,   231,   229,
     439,     1,    98,   125,   443,   444,   445,   446,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   496,   231,   492,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   229,   449,     1,    19,    39,    63,
     118,   126,   127,   147,   222,   361,   362,   363,   364,   365,
     366,   367,   371,   372,   373,     1,   125,   222,   427,   428,
     429,   430,     1,    54,    61,    63,   122,   347,   351,   352,
     353,   357,   358,   228,   231,   231,   229,   243,     1,    77,
     174,   274,   275,   276,   277,     1,    19,    39,    63,    98,
     118,   134,   151,   152,   202,   222,   226,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   317,
       1,    41,    77,   125,   376,   377,   378,   379,   380,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   521,   228,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   229,   248,     1,
      98,   219,   397,   398,   399,   400,   228,   231,   229,   288,
     174,     1,    98,   167,   185,   201,   280,   281,   282,   283,
     284,   285,   231,   229,   383,     1,    98,   219,   222,   387,
     388,   389,   390,   391,   123,   123,   123,   228,   108,   108,
     238,   108,   108,   211,   108,   238,   108,   238,   238,   108,
     108,   211,   211,   228,   228,   231,   231,   231,   342,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   229,   324,   228,   231,   231,   231,   231,   231,
     231,   417,   231,   231,   231,   231,   231,   231,   231,   229,
     407,   231,   231,   229,   434,   123,   228,   231,   231,   229,
     444,   211,   238,   108,   238,   238,   211,   108,   211,   108,
     108,   108,   211,   211,   211,   238,   108,   108,   108,   108,
     238,   108,   108,   108,   108,   211,   231,   211,   231,   211,
     238,   238,   211,   211,   211,   211,   215,   211,   215,   211,
     211,   211,   211,   108,   238,   211,   238,   238,   211,   228,
     228,   231,   231,   368,   231,   231,   231,   231,   231,   229,
     362,   231,   231,   229,   428,   228,   231,   231,   348,   231,
     229,   352,   123,   123,   228,   228,   231,   231,   229,   275,
     228,   231,   231,   318,   231,   231,   231,   231,   231,   314,
     231,   231,   229,   303,   228,   231,   231,   231,   229,   377,
     211,   211,   211,   123,   211,   211,   211,   238,   228,   108,
     123,   211,   123,   108,   108,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   228,   228,   231,   401,
     229,   398,   211,   228,   230,   228,   231,   231,   231,   231,
     229,   281,   123,   228,   228,   231,   392,   231,   229,   388,
     228,   228,   228,   228,   135,   136,   137,   138,   139,   140,
     141,   237,   238,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   108,   108,   238,   231,
     108,   108,   108,   238,   108,   108,   238,   123,   108,   108,
     238,   108,   240,   240,   228,   123,   178,   179,   123,   211,
     123,   123,   231,   123,   123,   108,   123,   123,   123,   123,
     228,   123,   123,   228,   228,   123,   123,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,    46,   164,   165,   166,   169,   170,   172,
     173,   175,   177,   180,   182,   183,   188,   192,   196,   197,
     198,   203,   208,   497,   498,   228,    46,    48,    49,   164,
     165,   166,   169,   170,   172,   173,   175,   177,   180,   182,
     183,   188,   192,   196,   197,   198,   203,   208,   493,   494,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     123,   211,   231,   123,   108,   123,   123,   123,   228,   123,
     123,   228,   123,   123,   231,   108,   355,   356,   228,   228,
     228,   123,   123,   228,   123,   211,   231,   123,   123,   123,
     123,   211,   231,   123,   123,   228,   123,   123,   123,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   123,   231,   228,   228,     1,
      98,   195,   219,   292,   293,   294,   295,   296,   123,   123,
     123,   123,   228,   228,   123,   231,   123,   228,   237,   237,
     237,   237,   237,   237,   237,   228,   228,   228,    50,   124,
     343,   344,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,    11,    12,    13,   239,   240,   228,   228,
     228,   228,   228,   228,   228,   228,   228,     8,   199,   418,
     419,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   232,   228,   232,   228,   228,    15,    40,
      68,    99,   100,   107,   132,   148,   210,   369,   370,   228,
     228,   228,   228,   228,   228,   228,   228,   228,    46,   190,
     199,   349,   350,   218,   232,   354,   228,   228,   228,   228,
       4,    20,    31,    65,    67,    95,   128,   130,   149,   171,
     176,   180,   184,   189,   193,   204,   207,   209,   220,   227,
     319,   320,   228,   228,   228,   228,   228,    46,    48,    49,
     164,   165,   166,   169,   170,   172,   173,   175,   177,   180,
     182,   183,   188,   192,   196,   197,   198,   203,   208,   315,
     316,   228,   228,   228,   228,   228,   228,    67,   131,   163,
     171,   180,   204,   206,   207,   220,   227,   402,   403,   228,
     231,   231,   297,   229,   293,   228,   228,   228,   228,   228,
      67,   131,   163,   171,   180,   204,   206,   207,   220,   227,
     393,   394,   228,   228,   232,   239,   239,   239,   228,   232,
     498,   494,   228,   232,   228,   232,   108,   356,   228,   233,
     233,   233,   228,   232,   228,   232,   228,   232,   123,   205,
     240,   231,   228,   228,   232,   344,   419,   370,   350,   129,
     129,   129,   320,   316,   403,   228,   228,   228,    65,    67,
     114,   131,   170,   171,   222,   227,   298,   299,   394,   228,
     232,   299
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   234,   235,   235,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   237,   237,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   240,   241,   242,   242,   243,   243,   243,
     244,   245,   246,   247,   247,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   267,   268,   268,   268,   268,   269,   270,   271,
     273,   272,   274,   274,   275,   275,   275,   276,   277,   279,
     278,   280,   280,   281,   281,   281,   281,   281,   282,   283,
     284,   285,   286,   287,   287,   288,   288,   288,   289,   291,
     290,   292,   292,   293,   293,   293,   293,   294,   295,   295,
     297,   296,   298,   298,   299,   299,   299,   299,   299,   299,
     299,   299,   301,   300,   302,   302,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   314,   313,   315,
     315,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   318,   317,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     322,   321,   323,   323,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   342,   341,
     343,   343,   344,   344,   346,   345,   348,   347,   349,   349,
     350,   350,   350,   351,   351,   352,   352,   352,   352,   352,
     354,   353,   355,   355,   356,   356,   357,   358,   360,   359,
     361,   361,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   364,   365,   366,   368,   367,   369,   369,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   371,   372,
     373,   375,   374,   376,   376,   377,   377,   377,   377,   378,
     379,   380,   381,   382,   382,   383,   383,   384,   386,   385,
     387,   387,   388,   388,   388,   388,   389,   390,   392,   391,
     393,   393,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   396,   395,   397,   397,   398,   398,   398,   399,
     401,   400,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   405,   404,   406,   406,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   415,   417,   416,   418,   418,   419,   419,   420,   421,
     422,   423,   424,   426,   425,   427,   427,   428,   428,   428,
     429,   430,   432,   431,   433,   433,   434,   434,   434,   435,
     436,   437,   438,   438,   439,   439,   440,   442,   441,   443,
     443,   444,   444,   444,   445,   446,   447,   448,   448,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   476,   477,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   492,
     491,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   496,   495,   497,   497,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   499,
     500,   501,   502,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   520,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   522,   523,   524,   525,
     526,   527,   528,   529
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       2,     3,     3,     3,     3,     3,     3,     3,     0,     1,
       2,     3,     3,     3,     5,     2,     1,     1,     1,     2,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     2,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     2,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
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
        case 28:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 479 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if (!ConfigServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.server_ctx, yylval.string) <= 0 ||
        SSL_CTX_use_certificate_chain_file(ConfigServerInfo.client_ctx, yylval.string) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.server_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ConfigServerInfo.client_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ConfigServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ConfigServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
#line 2994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 519 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (ConfigServerInfo.rsa_private_key)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;
  }

  if (ConfigServerInfo.rsa_private_key_file)
  {
    MyFree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = NULL;
  }

  ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);

  if ((file = BIO_new_file(yylval.string, "r")) == NULL)
  {
    conf_error_report("File open failed, ignoring");
    break;
  }

  ConfigServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (ConfigServerInfo.rsa_private_key == NULL)
  {
    conf_error_report("Couldn't extract key, ignoring");
    break;
  }

  if (!RSA_check_key(ConfigServerInfo.rsa_private_key))
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Invalid key, ignoring");
    break;
  }

  if (RSA_size(ConfigServerInfo.rsa_private_key) < 128)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Ignoring serverinfo::rsa_private_key_file -- need at least a 1024 bit key size");
  }
#endif
}
#line 3055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 577 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
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
          SSL_CTX_set_tmp_dh(ConfigServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
    else
      conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }
#endif
}
#line 3087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 606 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 614 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if ((ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
    {
      ConfigServerInfo.message_digest_algorithm = EVP_sha256();
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }
#endif
}
#line 3115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 628 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2)
  {
    if ((nid = OBJ_sn2nid(yylval.string)) == 0)
    {
        conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- unknown curve name");
        break;
    }

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
    {
      conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- could not create curve");
      break;
    }

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 656 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
#line 3164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 671 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
#line 3182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 686 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 696 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    MyFree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 710 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 719 "conf_parser.y" /* yacc.c:1646  */
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

      memcpy(&ConfigServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 747 "conf_parser.y" /* yacc.c:1646  */
    {
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

      memcpy(&ConfigServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip6.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv6_vhost = 1;
    }
  }
}
#line 3286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 775 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 800 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ConfigServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[-1].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ConfigServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[-1].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 861 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 870 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 891 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 895 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 912 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 918 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 927 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.command.buf[0] ||
      !block_state.name.buf[0] ||
      !block_state.nick.buf[0] ||
      !block_state.host.buf[0])
    break;

  pseudo_register(block_state.name.buf, block_state.nick.buf, block_state.host.buf,
                  block_state.prepend.buf, block_state.command.buf);
}
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 949 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 955 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.nick.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.nick.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
#line 3528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 994 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1028 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1031 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1067 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1088 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

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

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
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

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

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
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1184 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1190 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1202 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1208 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1225 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1242 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1307 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1323 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1335 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1339 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1380 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1388 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1392 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1428 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1432 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1440 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1450 "conf_parser.y" /* yacc.c:1646  */
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
#line 4295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1462 "conf_parser.y" /* yacc.c:1646  */
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
#line 4348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1531 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1537 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1543 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1549 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1555 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1561 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1567 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1573 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1579 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1585 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1598 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1610 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1616 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1625 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1641 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1645 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4526 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1655 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1661 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1671 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1675 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1683 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1688 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif
    add_listener((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1701 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1718 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1724 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1737 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
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
#line 4682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1786 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1792 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1798 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1804 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1815 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1838 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1846 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1850 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1854 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
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
#line 4830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1874 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4842 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1883 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1903 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1920 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1941 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
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
#line 4952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1984 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1990 "conf_parser.y" /* yacc.c:1646  */
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
#line 4983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2009 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2040 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2070 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2091 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2098 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2122 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2126 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2130 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2134 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2152 "conf_parser.y" /* yacc.c:1646  */
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
#line 5299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2238 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
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
#line 5342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
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
#line 5358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2331 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2343 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5475 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2362 "conf_parser.y" /* yacc.c:1646  */
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
#line 5509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2387 "conf_parser.y" /* yacc.c:1646  */
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
#line 5532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2407 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2420 "conf_parser.y" /* yacc.c:1646  */
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
#line 5576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2452 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2466 "conf_parser.y" /* yacc.c:1646  */
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
#line 5611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2483 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2487 "conf_parser.y" /* yacc.c:1646  */
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
#line 5642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2509 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2515 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 516:
#line 2577 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5676 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2598 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2603 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2608 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5725 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2674 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2720 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2927 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2971 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2981 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2986 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3076 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3091 "conf_parser.y" /* yacc.c:1646  */
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
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3112 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6578 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6582 "conf_parser.c" /* yacc.c:1646  */
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
