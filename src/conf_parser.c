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
    XLINE = 482,
    XLINE_EXEMPT = 483
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
#define XLINE_EXEMPT 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 691 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 708 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1381

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  296
/* YYNRULES -- Number of rules.  */
#define YYNRULES  664
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1313

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
       0,   384,   384,   385,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   415,   415,
     416,   417,   418,   419,   420,   421,   422,   423,   426,   426,
     427,   428,   429,   430,   437,   440,   440,   441,   441,   441,
     443,   449,   456,   458,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   479,   519,   577,   606,   614,   628,   656,
     671,   686,   696,   710,   719,   747,   775,   800,   822,   844,
     853,   855,   855,   856,   857,   858,   859,   861,   870,   879,
     892,   891,   909,   909,   910,   910,   910,   912,   918,   928,
     927,   946,   946,   947,   947,   947,   947,   947,   949,   955,
     961,   967,   988,   989,   989,   991,   991,   992,   994,  1001,
    1001,  1014,  1015,  1017,  1017,  1018,  1018,  1020,  1028,  1031,
    1037,  1036,  1042,  1042,  1043,  1047,  1051,  1055,  1059,  1063,
    1067,  1071,  1082,  1081,  1170,  1170,  1171,  1172,  1173,  1174,
    1175,  1176,  1177,  1178,  1179,  1180,  1181,  1182,  1184,  1190,
    1196,  1202,  1208,  1219,  1225,  1231,  1242,  1249,  1248,  1254,
    1254,  1255,  1259,  1263,  1267,  1271,  1275,  1279,  1283,  1287,
    1291,  1295,  1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,
    1331,  1335,  1339,  1346,  1345,  1351,  1351,  1352,  1356,  1360,
    1364,  1368,  1372,  1376,  1380,  1384,  1388,  1392,  1396,  1400,
    1404,  1408,  1412,  1416,  1420,  1424,  1428,  1432,  1436,  1440,
    1451,  1450,  1512,  1512,  1513,  1514,  1515,  1516,  1517,  1518,
    1519,  1520,  1521,  1522,  1523,  1524,  1525,  1525,  1526,  1527,
    1528,  1529,  1531,  1537,  1543,  1549,  1555,  1561,  1567,  1573,
    1579,  1585,  1591,  1598,  1604,  1610,  1616,  1625,  1635,  1634,
    1640,  1640,  1641,  1645,  1656,  1655,  1662,  1661,  1666,  1666,
    1667,  1671,  1675,  1681,  1681,  1682,  1682,  1682,  1682,  1682,
    1684,  1684,  1686,  1686,  1688,  1701,  1718,  1724,  1734,  1733,
    1775,  1775,  1776,  1777,  1778,  1779,  1780,  1781,  1782,  1783,
    1784,  1786,  1792,  1798,  1804,  1816,  1815,  1821,  1821,  1822,
    1826,  1830,  1834,  1838,  1842,  1846,  1850,  1854,  1858,  1864,
    1878,  1887,  1901,  1900,  1915,  1915,  1916,  1916,  1916,  1916,
    1918,  1924,  1930,  1940,  1942,  1942,  1943,  1943,  1945,  1961,
    1960,  1985,  1985,  1986,  1986,  1986,  1986,  1988,  1994,  2014,
    2013,  2019,  2019,  2020,  2024,  2028,  2032,  2036,  2040,  2044,
    2048,  2052,  2056,  2066,  2065,  2086,  2086,  2087,  2087,  2087,
    2089,  2096,  2095,  2101,  2101,  2102,  2106,  2110,  2114,  2118,
    2122,  2126,  2130,  2134,  2138,  2148,  2147,  2219,  2219,  2220,
    2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,  2229,  2230,
    2231,  2232,  2233,  2234,  2236,  2242,  2248,  2254,  2267,  2280,
    2286,  2292,  2296,  2303,  2302,  2307,  2307,  2308,  2312,  2318,
    2329,  2335,  2341,  2347,  2363,  2362,  2388,  2388,  2389,  2389,
    2389,  2391,  2411,  2421,  2420,  2447,  2447,  2448,  2448,  2448,
    2450,  2456,  2465,  2467,  2467,  2468,  2468,  2470,  2488,  2487,
    2510,  2510,  2511,  2511,  2511,  2513,  2519,  2528,  2531,  2531,
    2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,
    2542,  2543,  2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,
    2552,  2553,  2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,
    2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,  2570,  2571,
    2572,  2573,  2574,  2575,  2576,  2577,  2578,  2581,  2586,  2591,
    2596,  2602,  2607,  2612,  2617,  2622,  2627,  2632,  2637,  2642,
    2647,  2652,  2657,  2662,  2667,  2672,  2678,  2683,  2688,  2693,
    2698,  2703,  2708,  2713,  2716,  2721,  2724,  2729,  2734,  2739,
    2744,  2749,  2754,  2759,  2764,  2769,  2774,  2779,  2784,  2789,
    2795,  2794,  2799,  2799,  2800,  2803,  2806,  2809,  2812,  2815,
    2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,  2842,  2845,
    2848,  2851,  2854,  2857,  2860,  2863,  2869,  2868,  2873,  2873,
    2874,  2877,  2880,  2883,  2886,  2889,  2892,  2895,  2898,  2901,
    2904,  2907,  2910,  2913,  2916,  2919,  2922,  2925,  2928,  2931,
    2936,  2941,  2946,  2955,  2958,  2958,  2959,  2960,  2961,  2962,
    2963,  2964,  2965,  2966,  2967,  2968,  2969,  2970,  2971,  2972,
    2973,  2975,  2980,  2985,  2990,  2995,  3000,  3005,  3010,  3015,
    3020,  3025,  3030,  3035,  3040,  3048,  3051,  3051,  3052,  3053,
    3054,  3055,  3056,  3057,  3058,  3059,  3060,  3062,  3068,  3074,
    3080,  3086,  3095,  3110,  3116
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,    59,
     125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -739

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-739)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -739,   690,  -739,  -204,  -227,  -225,  -739,  -739,  -739,  -212,
    -739,  -183,  -739,  -739,  -739,  -172,  -739,  -739,  -739,  -171,
    -159,  -739,  -145,  -739,  -142,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,   322,   939,  -134,  -105,   -70,    21,   -69,   390,   -61,
     -55,   -49,    40,   -47,   -34,   -31,   669,   530,   -28,   106,
     -23,    11,   -15,   -14,     6,    27,    52,    31,  -739,  -739,
    -739,  -739,  -739,    54,    62,    90,    96,   103,   114,   117,
     118,   121,   131,   132,   144,   145,   148,   171,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,   680,   523,    14,  -739,   152,    69,  -739,
    -739,    19,  -739,   153,   155,   156,   157,   161,   162,   175,
     176,   177,   179,   182,   183,   184,   185,   186,   187,   189,
     191,   192,   196,   199,   201,   202,   203,   204,  -739,   207,
    -739,   208,   209,   210,   211,   213,   218,   220,   222,   223,
     226,   230,   233,   234,   239,   241,   246,   248,   250,     7,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,   343,    26,   329,
     -11,   253,   254,    39,  -739,  -739,  -739,    33,   312,    22,
    -739,   255,   260,   261,   263,   265,   266,   268,   272,     4,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,    -2,
     276,   277,   279,   280,   281,   283,   285,   286,   287,   288,
     289,   290,   291,   293,   295,   298,   300,   124,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,    10,    44,   305,    67,
    -739,  -739,  -739,   137,   173,  -739,   308,    89,  -739,  -739,
      17,  -739,   215,   282,   353,    76,  -739,   206,   433,   435,
     437,   342,   446,   433,   447,   433,   433,   449,   450,   348,
     350,   174,  -739,   335,   341,   346,   349,  -739,   352,   355,
     356,   357,   358,   359,   363,   367,   368,   369,   373,   377,
     378,   172,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
     345,   379,   380,   381,   382,   386,   387,  -739,   391,   394,
     395,   397,   398,   402,   403,   244,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,   404,   405,    32,  -739,  -739,  -739,   457,   393,
    -739,  -739,   406,   408,    80,  -739,  -739,  -739,   371,   433,
     533,   433,   433,   432,   538,   436,   541,   542,   543,   442,
     443,   444,   433,   548,   550,   551,   552,   433,   554,   556,
     559,   563,   481,   441,   482,   455,   485,   433,   433,   488,
     489,   491,  -187,  -180,   494,   496,   497,   500,   605,   433,
     503,   433,   433,   506,   495,  -739,   498,   486,   493,  -739,
     501,   504,   505,   507,   508,    65,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,   509,   510,    86,  -739,
    -739,  -739,   499,   513,   515,  -739,   516,  -739,    79,  -739,
    -739,  -739,  -739,  -739,   603,   606,   520,  -739,   521,   519,
     524,    35,  -739,  -739,  -739,   528,   526,   527,  -739,   539,
     544,   545,   547,   549,  -739,   553,   560,   227,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
     536,   561,   565,   566,    61,  -739,  -739,  -739,  -739,   562,
     564,   569,   609,   571,   572,   573,   433,   577,  -739,  -739,
     666,   615,   580,   665,   701,   703,   691,   692,   693,   694,
     696,   697,   702,   706,   707,   708,   709,   595,  -739,   607,
     608,  -739,    87,  -739,  -739,  -739,  -739,   626,   610,  -739,
     612,   616,   614,   617,   618,   619,   135,  -739,  -739,  -739,
    -739,  -739,   718,   623,  -739,   624,   622,  -739,   625,    82,
    -739,  -739,  -739,  -739,   627,   631,   632,  -739,   633,   431,
     634,   635,   636,   637,   639,   640,   641,   643,   644,   645,
     646,   648,   649,  -739,  -739,   736,   739,   433,   647,   740,
     747,   751,   433,   772,   774,   433,   760,   780,   781,   433,
     784,   784,   668,  -739,  -739,   776,  -133,   777,   684,   779,
     782,   675,   785,   787,   803,   789,   791,   792,   793,   704,
    -739,   797,   798,   712,  -739,   714,  -739,   799,   800,   719,
    -739,   720,   722,   723,   724,   727,   728,   732,   733,   742,
     744,   745,   746,   748,   749,   754,   755,   756,   757,   758,
     759,   761,   763,   764,   765,   767,   762,   768,   630,   771,
     778,   786,   788,   794,   795,   796,   801,   802,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   816,  -739,
    -739,   824,   725,   698,   845,   817,   846,   853,   857,   818,
    -739,   866,   868,   819,  -739,  -739,   878,   880,   773,   896,
     820,  -739,   821,   822,  -739,  -739,   883,   885,   823,  -739,
    -739,   886,   815,   790,   890,   891,   893,   897,   835,   825,
     898,   904,   826,  -739,  -739,   905,   906,   909,   827,  -739,
     829,   830,   831,   832,   833,   834,   836,   837,  -739,   838,
     839,   840,   841,   842,   843,   844,   847,   848,   849,   850,
     851,   852,   854,   855,   856,   858,  -739,  -739,   930,   859,
     860,  -739,   861,  -739,    77,  -739,   931,   941,   951,   952,
     863,  -739,   864,  -739,  -739,   959,   862,   963,   867,  -739,
    -739,  -739,  -739,  -739,   433,   433,   433,   433,   433,   433,
     433,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,   869,   870,   871,   -13,
     872,   873,   874,   875,   876,   877,   879,   881,   882,   884,
     887,    41,   888,   889,  -739,   892,   894,   895,   899,   900,
     901,   902,    -5,   903,   907,   908,   910,   911,   912,   913,
    -739,   914,   915,  -739,  -739,   916,   917,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -162,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -138,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
     918,   919,   476,   920,   921,   922,   923,   924,  -739,   925,
     926,  -739,   927,   928,    68,   940,   929,  -739,  -739,  -739,
    -739,   932,   934,  -739,   935,   936,   468,   937,   938,   942,
     943,   944,   721,   945,   946,  -739,   947,   948,   949,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,   950,   462,  -739,  -739,   953,
     865,   954,  -739,    73,  -739,  -739,  -739,  -739,   955,   956,
     958,   960,  -739,  -739,   961,   775,   962,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
     -92,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,   784,   784,   784,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,   -81,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,   762,  -739,   630,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,   -73,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,   -52,  -739,   980,   896,   964,  -739,  -739,  -739,
    -739,  -739,   965,  -739,   966,  -739,  -739,  -739,  -739,   967,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,   -27,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
     -16,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,    56,  -739,
    -739,   972,   -50,   970,   968,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,   108,  -739,  -739,  -739,   -13,  -739,  -739,  -739,  -739,
      -5,  -739,  -739,  -739,   476,  -739,    68,  -739,  -739,  -739,
     978,   983,   985,  -739,   468,  -739,   721,  -739,   462,   969,
     974,   975,   267,  -739,  -739,   775,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,   110,  -739,  -739,
    -739,   267,  -739
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   395,   443,     0,
     458,     0,   298,   434,   274,     0,   100,   152,   332,     0,
       0,   373,     0,   109,     0,   349,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   615,   629,
     617,   618,   619,   620,   621,   622,   616,   623,   624,   625,
     626,   627,   628,     0,     0,     0,   456,     0,     0,   454,
     455,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   586,     0,
     560,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,   470,   471,   514,   515,   509,   510,   511,   512,   508,
     481,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     482,   483,   513,   487,   488,   489,   490,   486,   485,   491,
     499,   500,   492,   493,   494,   495,   484,   497,   506,   507,
     504,   505,   498,   496,   502,   503,   501,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     647,   648,   649,   650,   651,   654,   652,   653,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   347,     0,     0,   345,   346,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,     0,     0,     0,     0,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,   234,   237,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   235,   236,   238,   248,   249,   250,
       0,     0,     0,     0,     0,     0,     0,   423,     0,     0,
       0,     0,     0,     0,     0,     0,   398,   399,   400,   401,
     402,   403,   404,   406,   405,   408,   412,   409,   410,   411,
     407,   449,     0,     0,     0,   446,   447,   448,     0,     0,
     453,   464,     0,     0,     0,   461,   462,   463,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,     0,     0,     0,   315,
       0,     0,     0,     0,     0,     0,   301,   302,   303,   304,
     309,   305,   306,   307,   308,   440,     0,     0,     0,   437,
     438,   439,     0,     0,     0,   276,     0,   286,     0,   284,
     285,   287,   288,    49,     0,     0,     0,    45,     0,     0,
       0,     0,   103,   104,   105,     0,     0,     0,   203,     0,
       0,     0,     0,     0,   177,     0,     0,     0,   155,   156,
     157,   158,   159,   162,   163,   164,   165,   161,   160,   166,
       0,     0,     0,     0,     0,   335,   336,   337,   338,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   646,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   381,     0,   376,   377,   378,   127,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   115,
     114,   116,     0,     0,   344,     0,     0,   359,     0,     0,
     352,   353,   354,   355,     0,     0,     0,    90,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,   251,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   232,   413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     397,     0,     0,     0,   445,     0,   452,     0,     0,     0,
     460,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
     310,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     300,     0,     0,     0,   436,   289,     0,     0,     0,     0,
       0,   283,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   339,     0,     0,     0,     0,   334,
       0,     0,     0,     0,     0,     0,     0,     0,   645,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   379,     0,     0,
       0,   375,     0,   122,     0,   117,     0,     0,     0,     0,
       0,   111,     0,   343,   356,     0,     0,     0,     0,   351,
      99,    98,    97,   643,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   644,   640,   639,   631,   632,   633,   634,
     635,   636,   638,   637,   641,   642,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,   231,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     396,     0,     0,   444,   457,     0,     0,   459,   529,   533,
     517,   518,   548,   520,   612,   557,   521,   522,   554,   528,
     527,   536,   526,   523,   524,   532,   531,   530,   555,   519,
     610,   611,   552,   596,   590,   606,   591,   592,   593,   601,
     609,   594,   603,   607,   597,   608,   598,   602,   595,   605,
     600,   599,   604,     0,   589,   553,   569,   570,   571,   564,
     582,   565,   566,   567,   577,   585,   568,   579,   583,   573,
     584,   574,   578,   572,   581,   576,   575,   580,     0,   563,
     549,   547,   550,   556,   551,   538,   545,   546,   543,   544,
     539,   540,   541,   542,   558,   559,   525,   535,   534,   537,
       0,     0,     0,     0,     0,     0,     0,     0,   299,     0,
       0,   435,     0,     0,     0,   294,   290,   293,   275,    50,
      51,     0,     0,   101,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   153,     0,     0,     0,   333,
     658,   657,   663,   661,   664,   659,   660,   662,    86,    81,
      89,    80,    87,    88,    79,    83,    82,    74,    73,    78,
      75,    77,    76,    84,    85,     0,     0,   374,   128,     0,
       0,     0,   140,     0,   132,   133,   135,   134,     0,     0,
       0,     0,   110,   348,     0,     0,     0,   350,    31,    32,
      33,    34,    35,    36,    37,   263,   264,   255,   273,   272,
       0,   271,   256,   258,   260,   267,   259,   257,   266,   252,
     265,   254,   253,    38,    38,    38,    40,    39,   261,   262,
     418,   421,   422,   432,   429,   415,   430,   427,   428,     0,
     426,   431,   414,   420,   417,   419,   433,   416,   450,   451,
     465,   466,   587,     0,   561,     0,   313,   314,   324,   320,
     321,   323,   328,   325,   326,   319,   327,   322,     0,   318,
     312,   331,   330,   329,   311,   442,   441,   297,   296,   281,
     282,   280,     0,   279,     0,     0,     0,   107,   108,   176,
     172,   222,   210,   219,   208,   213,   228,   221,   226,   212,
     215,   223,   225,   229,   220,   227,   216,   218,   224,   214,
     217,     0,   206,   168,   170,   173,   174,   175,   186,   187,
     188,   181,   199,   182,   183,   184,   194,   202,   185,   196,
     200,   190,   201,   191,   195,   189,   198,   193,   192,   197,
       0,   180,   169,   171,   342,   340,   341,   380,   385,   391,
     394,   387,   393,   388,   392,   390,   386,   389,     0,   384,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     357,   363,   369,   372,   365,   371,   366,   370,   368,   364,
     367,     0,   362,   358,   269,     0,    41,    42,    43,   424,
       0,   588,   562,   316,     0,   277,     0,   295,   292,   291,
       0,     0,     0,   204,     0,   178,     0,   382,     0,     0,
       0,     0,     0,   130,   360,     0,   270,   425,   317,   278,
     209,   207,   211,   205,   179,   383,   137,   139,   138,   150,
     149,   145,   147,   151,   148,   144,   146,     0,   143,   361,
     141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -739,  -739,  -739,  -457,  -306,  -738,  -640,  -739,  -739,   957,
    -739,  -739,  -739,  -739,   971,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  1032,  -739,  -739,  -739,  -739,  -739,
    -739,   621,  -739,  -739,  -739,  -739,  -739,   529,  -739,  -739,
    -739,  -739,  -739,  -739,   933,  -739,  -739,  -739,  -739,    66,
    -739,  -739,  -739,  -739,  -739,  -191,  -739,  -739,  -739,   642,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -151,  -739,  -739,  -739,  -148,  -739,  -739,  -739,
     828,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -128,  -739,  -739,  -739,  -739,  -739,  -132,  -739,   650,  -739,
    -739,  -739,   -22,  -739,  -739,  -739,  -739,  -739,   670,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -104,  -739,  -739,  -739,
    -739,  -739,  -739,   654,  -739,  -739,  -739,  -739,  -739,   973,
    -739,  -739,  -739,  -739,   582,  -739,  -739,  -739,  -739,  -739,
    -117,  -739,  -739,  -739,   598,  -739,  -739,  -739,  -739,   -95,
    -739,  -739,  -739,   976,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,   -68,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,   716,  -739,  -739,  -739,  -739,  -739,
     814,  -739,  -739,  -739,  -739,  1077,  -739,  -739,  -739,  -739,
     977,  -739,  -739,  -739,  -739,  1027,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
      81,  -739,  -739,  -739,    84,  -739,  -739,  -739,  -739,  -739,
    1108,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739,  -739,   979,  -739,  -739,
    -739,  -739,  -739,  -739,  -739,  -739
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
    1055,  1056,  1057,  1233,  1307,  1308,    33,    64,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     759,  1210,  1211,   529,   753,  1181,  1182,    34,    53,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   628,  1080,
    1081,    35,    61,   487,   738,  1152,  1153,   488,   489,   490,
    1156,   996,   997,   491,   492,    36,    59,   465,   466,   467,
     468,   469,   470,   471,   723,  1138,  1139,   472,   473,   474,
      37,    65,   534,   535,   536,   537,   538,    38,   297,   298,
     299,    39,    72,   599,   600,   601,   602,   603,   816,  1251,
    1252,    40,    68,   572,   573,   574,   575,   799,  1228,  1229,
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
     862,   863,   610,  1107,    51,   230,    52,   615,   122,   617,
     618,   569,   295,   123,   124,   391,   125,   126,   595,    56,
     401,   127,   116,   530,   705,    49,    50,   475,   706,   128,
     129,   707,    73,   391,   498,   708,   498,  1078,   231,   130,
     220,   220,   131,   132,   133,   866,   867,   232,    58,   134,
     233,   234,  1093,  1094,  1095,   235,   236,   237,   861,    62,
      66,    74,   530,   531,   135,   136,   456,  1122,   287,    75,
     116,  1123,    67,   137,  1049,   392,   138,   139,  1049,   238,
     482,   401,   117,   595,   457,   140,    69,   475,   569,    71,
     295,  1124,   141,   392,   142,  1125,   143,   113,   144,   532,
     145,   146,   531,   672,   458,   674,   675,   287,   570,   296,
     499,  1079,   499,   147,  1149,   596,   685,   402,   148,   149,
     150,   690,   151,   152,   153,   249,   114,   154,   459,    76,
     117,   700,   701,   483,   221,   221,   581,  1254,   532,   393,
     484,  1255,   485,   714,   403,   716,   717,   533,  1259,   861,
     250,   476,  1260,   155,   251,  1280,  1263,   393,   222,   222,
    1264,   115,   121,   156,   157,   158,   159,   160,   161,   162,
     217,  1050,    82,   323,   581,  1050,   218,  1265,   402,   252,
     596,  1266,   219,   460,   227,   570,   533,   296,   253,   324,
     325,   461,   462,   326,  1108,    83,    84,   228,    85,    86,
     229,   486,  1273,   286,    87,   403,  1274,   500,   294,   500,
     254,   476,   463,  1275,   255,   301,   300,  1276,   493,   163,
     164,   165,   256,   166,   167,   257,   258,   549,   505,   571,
      88,    89,   168,   582,   547,   327,   597,   454,   302,   598,
     777,  -129,    90,    91,    92,   360,   506,   361,   477,   362,
      93,    94,   328,   329,   330,   331,   332,   259,  1150,   303,
     333,   305,   663,   363,   334,   748,   507,  1151,  1051,   496,
     335,   582,  1051,   576,   260,    95,    96,   261,   262,   263,
    -129,   336,   337,   364,   304,  1277,   307,   464,   288,  1278,
     508,   768,  1052,   338,   308,   729,  1052,   578,   365,   399,
     366,   597,   583,  1234,   598,   607,   571,   367,   477,   740,
     669,   580,   818,   505,   608,   339,   733,   800,   368,   593,
     584,   848,   309,    73,   264,   509,   853,   288,   310,   856,
     482,   506,  1299,   860,  1300,   311,   585,  1284,   604,  1310,
     583,  1285,   369,  1311,   456,   510,   312,   265,   266,   313,
     314,   507,    74,   315,   567,  1256,  1257,  1258,   584,   340,
      75,   511,   457,   316,   317,   810,   370,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,   585,   508,   318,   319,   512,   513,
     320,  1301,   458,   483,   398,   408,   371,   409,   410,   411,
     484,   122,   485,   412,   413,   372,   123,   124,  1302,   125,
     126,   321,   642,   623,   127,   605,   459,   414,   415,   416,
     509,   417,   128,   129,   418,   419,   420,   421,   422,   423,
      76,   424,   130,   425,   426,   131,   132,   133,   427,   514,
     510,   428,   134,   429,   430,   431,   432,  1303,  1304,   434,
     436,   437,   438,   439,   373,   440,   511,   135,   136,   515,
     441,   486,   442,   516,   443,   444,   137,   762,   445,   138,
     139,   460,   446,   512,   513,   447,   448,   374,   140,   461,
     462,   449,  1161,   450,   659,   141,   606,   142,   451,   143,
     452,   144,   453,   145,   146,   494,   495,   539,  1162,  1305,
     463,  1128,   540,   541,  1306,   542,   147,   543,   544,  1163,
     545,   148,   149,   150,   546,   151,   152,   153,   550,   551,
     154,   552,   553,   554,   514,   555,  1129,   556,   557,   558,
     559,   560,   561,   562,   360,   563,   361,   564,   362,  1218,
     565,   249,   566,  1164,   515,  1165,   155,   577,   516,   609,
     592,   609,   363,   611,  1130,   612,   156,   157,   158,   159,
     160,   161,   162,   613,   614,   616,   250,   619,   620,   621,
     251,   622,   364,  1166,   624,   464,   824,   825,   826,   827,
     828,   829,   830,   625,   644,  1131,  1132,   365,   626,   366,
     665,   627,   671,  1133,   629,   252,   367,   630,   631,   632,
     633,   634,  1281,  1219,   253,   635,  1167,   368,  1168,   636,
     637,   638,   163,   164,   165,   639,   166,   167,  1134,   640,
     641,   645,   646,   647,   648,   168,   254,  1169,   649,   650,
     255,   369,   666,   652,  1135,  1220,   653,   654,   256,   655,
     656,   257,   258,  1221,   657,   658,   661,   662,   667,  1170,
     668,   673,  1222,   676,  1171,   370,   677,   678,  1172,   679,
     680,   681,  1173,   682,   683,   684,   686,  1174,   687,   688,
     689,  1175,   691,   259,   692,   371,  1223,   693,  1224,  1225,
     230,   694,  1176,   696,   372,  1177,   936,  1178,   937,   938,
     260,   323,  1226,   261,   262,   263,  1136,   698,  1179,  1227,
       2,     3,   695,   697,     4,  1180,   699,   324,   325,   702,
     703,   326,   704,   231,  1137,   709,     5,   710,   711,     6,
       7,   712,   232,   713,   715,   233,   234,   718,   721,     8,
     235,   236,   237,   373,   719,   722,   742,   720,   735,   743,
     264,     9,   773,   724,    10,    11,   725,   726,   780,   727,
     728,   731,   732,   327,   238,   736,   374,   737,   739,   744,
     745,   746,    12,   265,   266,    13,   747,   750,   751,   752,
     328,   329,   330,   331,   332,   764,    14,  1188,   333,  1189,
    1190,   754,   334,   770,   779,   771,   755,   756,   335,   757,
     772,   758,   774,   775,   776,   760,    15,    16,   782,   336,
     337,   781,   761,   765,   939,   940,   941,   766,   767,   942,
     943,   338,   944,   945,    17,   946,   778,   947,   913,   783,
     948,   784,   949,   950,   785,   786,   787,   788,   951,   789,
     790,    18,   952,   339,   796,   791,   953,   954,   955,   792,
     793,   794,   795,   956,    19,    20,   797,   802,   957,   803,
     798,   812,  1241,   804,   846,   805,   806,   847,   850,   807,
     808,   809,   813,   814,   815,   851,   820,   817,    21,   852,
     821,   822,   823,   833,   834,   835,   836,   340,   837,   838,
     839,    22,   840,   841,   842,   843,    23,   844,   845,   849,
     854,    24,   855,   857,    25,  1191,  1192,  1193,   858,   859,
    1194,  1195,   861,  1196,  1197,   869,  1198,   864,  1199,   865,
     868,  1200,   870,  1201,  1202,   871,  1242,   872,   873,  1203,
     874,   875,   876,  1204,   877,   878,   879,  1205,  1206,  1207,
     881,   882,   885,   886,  1208,   984,   914,   915,   916,  1209,
     982,   917,   918,   880,   919,   920,   981,   921,  1243,   922,
      82,   883,   923,   884,   924,   925,  1244,   980,   887,   888,
     926,   889,   890,   891,   927,  1245,   892,   893,   928,   929,
     930,   894,   895,    83,    84,   931,    85,    86,   983,   985,
     932,   896,    87,   897,   898,   899,   986,   900,   901,  1246,
     987,  1247,  1248,   902,   903,   904,   905,   906,   907,   989,
     908,   990,   909,   910,   911,  1249,   912,   935,    88,    89,
     960,   992,  1250,   993,   995,   994,  1001,   961,  1002,  1004,
      90,    91,    92,  1007,  1008,   962,  1009,   963,    93,    94,
    1010,  1013,  1006,   964,   965,   966,  1005,  1014,  1016,  1017,
     967,   968,  1018,   969,   970,   971,   972,   973,   974,   975,
     976,   977,   978,    95,    96,   979,  1011,   988,   991,   998,
     999,  1000,  1003,  1045,  1058,  1015,  1019,  1012,  1020,  1021,
    1022,  1023,  1024,  1025,  1059,  1026,  1027,  1028,  1029,  1030,
    1031,  1032,  1033,  1034,  1060,  1061,  1035,  1036,  1037,  1038,
    1039,  1040,  1064,  1041,  1042,  1043,  1066,  1044,  1267,  1047,
    1048,  1046,  1062,  1063,  1065,  1279,  1067,  1231,  1075,  1076,
    1077,  1082,  1083,  1084,  1085,  1086,  1087,  1290,  1088,   306,
    1089,  1090,  1291,  1091,  1292,   811,  1092,  1098,  1099,  1235,
    1312,  1100,   749,  1101,  1102,  1294,  1293,  1286,  1103,  1104,
    1105,  1106,  1111,  1268,  1289,   730,  1112,  1113,   741,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1121,  1126,  1127,  1140,
    1141,  1142,  1143,  1144,  1145,  1146,  1147,  1148,  1154,   763,
    1288,  1157,  1155,  1158,  1159,  1160,  1183,  1184,  1309,   643,
     801,  1185,  1186,  1187,  1212,  1213,  1214,  1215,  1216,  1217,
     497,   819,  1230,  1295,  1236,  1237,  1232,  1238,   769,  1239,
    1240,  1253,  1287,  1269,   734,   400,   455,  1283,  1296,  1270,
    1271,  1272,  1282,  1297,  1298,   322,  1262,  1261,   664,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   548,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   568,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   660,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   670
};

static const yytype_int16 yycheck[] =
{
     640,   641,   308,     8,   231,     1,   231,   313,     1,   315,
     316,     1,     1,     6,     7,     1,     9,    10,     1,   231,
       1,    14,     1,     1,   211,   229,   230,     1,   215,    22,
      23,   211,     1,     1,     1,   215,     1,    50,    34,    32,
       1,     1,    35,    36,    37,   178,   179,    43,   231,    42,
      46,    47,    11,    12,    13,    51,    52,    53,   108,   231,
     231,    30,     1,    41,    57,    58,     1,   229,     1,    38,
       1,   233,   231,    66,     1,    61,    69,    70,     1,    75,
       1,     1,    61,     1,    19,    78,   231,     1,     1,   231,
       1,   229,    85,    61,    87,   233,    89,   231,    91,    77,
      93,    94,    41,   409,    39,   411,   412,     1,    98,    98,
      77,   124,    77,   106,    46,    98,   422,    98,   111,   112,
     113,   427,   115,   116,   117,     1,   231,   120,    63,    98,
      61,   437,   438,    54,    95,    95,     1,   229,    77,   125,
      61,   233,    63,   449,   125,   451,   452,   125,   229,   108,
      26,   125,   233,   146,    30,   205,   229,   125,   119,   119,
     233,   231,   231,   156,   157,   158,   159,   160,   161,   162,
     231,    98,     1,     1,     1,    98,   231,   229,    98,    55,
      98,   233,   231,   118,   231,    98,   125,    98,    64,    17,
      18,   126,   127,    21,   199,    24,    25,   231,    27,    28,
     231,   122,   229,   231,    33,   125,   233,   174,   231,   174,
      86,   125,   147,   229,    90,   229,   231,   233,   229,   212,
     213,   214,    98,   216,   217,   101,   102,   229,     1,   219,
      59,    60,   225,    98,   230,    63,   219,   230,   232,   222,
     546,   174,    71,    72,    73,     1,    19,     3,   222,     5,
      79,    80,    80,    81,    82,    83,    84,   133,   190,   232,
      88,   230,   230,    19,    92,   230,    39,   199,   195,   230,
      98,    98,   195,   229,   150,   104,   105,   153,   154,   155,
     174,   109,   110,    39,   232,   229,   232,   222,   221,   233,
      63,   230,   219,   121,   232,   230,   219,   230,    54,   230,
      56,   219,   167,   230,   222,   229,   219,    63,   222,   230,
     230,   174,   230,     1,   108,   143,   230,   230,    74,   230,
     185,   627,   232,     1,   200,    98,   632,   221,   232,   635,
       1,    19,    65,   639,    67,   232,   201,   229,   123,   229,
     167,   233,    98,   233,     1,   118,   232,   223,   224,   232,
     232,    39,    30,   232,   230,  1093,  1094,  1095,   185,   187,
      38,   134,    19,   232,   232,   230,   122,   824,   825,   826,
     827,   828,   829,   830,   201,    63,   232,   232,   151,   152,
     232,   114,    39,    54,   232,   232,   142,   232,   232,   232,
      61,     1,    63,   232,   232,   151,     6,     7,   131,     9,
      10,   230,   230,   229,    14,   123,    63,   232,   232,   232,
      98,   232,    22,    23,   232,   232,   232,   232,   232,   232,
      98,   232,    32,   232,   232,    35,    36,    37,   232,   202,
     118,   232,    42,   232,   232,   232,   232,   170,   171,   232,
     232,   232,   232,   232,   200,   232,   134,    57,    58,   222,
     232,   122,   232,   226,   232,   232,    66,   230,   232,    69,
      70,   118,   232,   151,   152,   232,   232,   223,    78,   126,
     127,   232,     4,   232,   230,    85,   123,    87,   232,    89,
     232,    91,   232,    93,    94,   232,   232,   232,    20,   222,
     147,    15,   232,   232,   227,   232,   106,   232,   232,    31,
     232,   111,   112,   113,   232,   115,   116,   117,   232,   232,
     120,   232,   232,   232,   202,   232,    40,   232,   232,   232,
     232,   232,   232,   232,     1,   232,     3,   232,     5,    67,
     232,     1,   232,    65,   222,    67,   146,   232,   226,   108,
     232,   108,    19,   108,    68,   108,   156,   157,   158,   159,
     160,   161,   162,   211,   108,   108,    26,   108,   108,   211,
      30,   211,    39,    95,   229,   222,   135,   136,   137,   138,
     139,   140,   141,   232,   229,    99,   100,    54,   232,    56,
     123,   232,   211,   107,   232,    55,    63,   232,   232,   232,
     232,   232,  1232,   131,    64,   232,   128,    74,   130,   232,
     232,   232,   212,   213,   214,   232,   216,   217,   132,   232,
     232,   232,   232,   232,   232,   225,    86,   149,   232,   232,
      90,    98,   229,   232,   148,   163,   232,   232,    98,   232,
     232,   101,   102,   171,   232,   232,   232,   232,   232,   171,
     232,   108,   180,   211,   176,   122,   108,   211,   180,   108,
     108,   108,   184,   211,   211,   211,   108,   189,   108,   108,
     108,   193,   108,   133,   108,   142,   204,   108,   206,   207,
       1,   108,   204,   232,   151,   207,    46,   209,    48,    49,
     150,     1,   220,   153,   154,   155,   210,   232,   220,   227,
       0,     1,   211,   211,     4,   227,   211,    17,    18,   211,
     211,    21,   211,    34,   228,   211,    16,   211,   211,    19,
      20,   211,    43,   108,   211,    46,    47,   211,   232,    29,
      51,    52,    53,   200,   229,   232,   123,   229,   229,   123,
     200,    41,   123,   232,    44,    45,   232,   232,   123,   232,
     232,   232,   232,    63,    75,   232,   223,   232,   232,   229,
     229,   232,    62,   223,   224,    65,   232,   229,   232,   232,
      80,    81,    82,    83,    84,   229,    76,    46,    88,    48,
      49,   232,    92,   211,   108,   211,   232,   232,    98,   232,
     211,   232,   211,   211,   211,   232,    96,    97,   123,   109,
     110,   211,   232,   232,   164,   165,   166,   232,   232,   169,
     170,   121,   172,   173,   114,   175,   229,   177,    46,   108,
     180,   108,   182,   183,   123,   123,   123,   123,   188,   123,
     123,   131,   192,   143,   229,   123,   196,   197,   198,   123,
     123,   123,   123,   203,   144,   145,   229,   211,   208,   229,
     232,   123,    67,   231,   108,   229,   232,   108,   108,   232,
     232,   232,   229,   229,   232,   108,   229,   232,   168,   108,
     229,   229,   229,   229,   229,   229,   229,   187,   229,   229,
     229,   181,   229,   229,   229,   229,   186,   229,   229,   232,
     108,   191,   108,   123,   194,   164,   165,   166,   108,   108,
     169,   170,   108,   172,   173,   211,   175,   229,   177,   123,
     123,   180,   123,   182,   183,   123,   131,   232,   123,   188,
     123,   108,   123,   192,   123,   123,   123,   196,   197,   198,
     123,   123,   123,   123,   203,   108,   164,   165,   166,   208,
     232,   169,   170,   229,   172,   173,   211,   175,   163,   177,
       1,   229,   180,   229,   182,   183,   171,   123,   229,   229,
     188,   229,   229,   229,   192,   180,   229,   229,   196,   197,
     198,   229,   229,    24,    25,   203,    27,    28,   123,   123,
     208,   229,    33,   229,   229,   229,   123,   229,   229,   204,
     123,   206,   207,   229,   229,   229,   229,   229,   229,   123,
     229,   123,   229,   229,   229,   220,   229,   229,    59,    60,
     229,   123,   227,   123,   108,   232,   123,   229,   123,   123,
      71,    72,    73,   123,   123,   229,   123,   229,    79,    80,
     123,   123,   232,   229,   229,   229,   211,   123,   123,   123,
     229,   229,   123,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   104,   105,   229,   211,   229,   229,   229,
     229,   229,   229,   123,   123,   229,   229,   232,   229,   229,
     229,   229,   229,   229,   123,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   123,   123,   229,   229,   229,   229,
     229,   229,   123,   229,   229,   229,   123,   229,   108,   229,
     229,   232,   229,   229,   232,   123,   229,   232,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   129,   229,    77,
     229,   229,   129,   229,   129,   586,   229,   229,   229,  1053,
    1311,   229,   501,   229,   229,  1276,  1274,  1255,   229,   229,
     229,   229,   229,  1155,  1266,   465,   229,   229,   488,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   218,   517,
    1264,   229,   233,   229,   229,   229,   229,   229,  1285,   341,
     572,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     223,   599,   229,  1278,   229,   229,   232,   229,   534,   229,
     229,   229,  1260,   229,   478,   118,   169,   229,   229,   234,
     234,   234,   232,   229,   229,    97,  1125,  1123,   394,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   239,    -1,
      -1,    -1,   289,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   267,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   375,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   404
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   236,     0,     1,     4,    16,    19,    20,    29,    41,
      44,    45,    62,    65,    76,    96,    97,   114,   131,   144,
     145,   168,   181,   186,   191,   194,   237,   242,   247,   267,
     273,   279,   287,   301,   322,   346,   360,   375,   382,   386,
     396,   405,   426,   432,   438,   442,   448,   503,   520,   229,
     230,   231,   231,   323,   406,   433,   231,   443,   231,   361,
     427,   347,   231,   274,   302,   376,   231,   231,   397,   231,
     280,   231,   387,     1,    30,    38,    98,   268,   269,   270,
     271,   272,     1,    24,    25,    27,    28,    33,    59,    60,
      71,    72,    73,    79,    80,   104,   105,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   231,   231,   231,     1,    61,   439,   440,
     441,   231,     1,     6,     7,     9,    10,    14,    22,    23,
      32,    35,    36,    37,    42,    57,    58,    66,    69,    70,
      78,    85,    87,    89,    91,    93,    94,   106,   111,   112,
     113,   115,   116,   117,   120,   146,   156,   157,   158,   159,
     160,   161,   162,   212,   213,   214,   216,   217,   225,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   496,   500,   501,   502,   231,   231,   231,
       1,    95,   119,   243,   244,   245,   246,   231,   231,   231,
       1,    34,    43,    46,    47,    51,    52,    53,    75,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,     1,
      26,    30,    55,    64,    86,    90,    98,   101,   102,   133,
     150,   153,   154,   155,   200,   223,   224,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   231,     1,   221,   288,
     289,   290,   291,   292,   231,     1,    98,   383,   384,   385,
     231,   229,   232,   232,   232,   230,   269,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   230,   505,     1,    17,    18,    21,    63,    80,    81,
      82,    83,    84,    88,    92,    98,   109,   110,   121,   143,
     187,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
       1,     3,     5,    19,    39,    54,    56,    63,    74,    98,
     122,   142,   151,   200,   223,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   421,   422,   423,   424,
     425,     1,    61,   125,   434,   435,   436,   437,   232,   230,
     440,     1,    98,   125,   444,   445,   446,   447,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   497,   232,   493,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   230,   450,     1,    19,    39,    63,
     118,   126,   127,   147,   222,   362,   363,   364,   365,   366,
     367,   368,   372,   373,   374,     1,   125,   222,   428,   429,
     430,   431,     1,    54,    61,    63,   122,   348,   352,   353,
     354,   358,   359,   229,   232,   232,   230,   244,     1,    77,
     174,   275,   276,   277,   278,     1,    19,    39,    63,    98,
     118,   134,   151,   152,   202,   222,   226,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   318,
       1,    41,    77,   125,   377,   378,   379,   380,   381,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   522,   229,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   249,     1,
      98,   219,   398,   399,   400,   401,   229,   232,   230,   289,
     174,     1,    98,   167,   185,   201,   281,   282,   283,   284,
     285,   286,   232,   230,   384,     1,    98,   219,   222,   388,
     389,   390,   391,   392,   123,   123,   123,   229,   108,   108,
     239,   108,   108,   211,   108,   239,   108,   239,   239,   108,
     108,   211,   211,   229,   229,   232,   232,   232,   343,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   230,   325,   229,   232,   232,   232,   232,   232,
     232,   418,   232,   232,   232,   232,   232,   232,   232,   230,
     408,   232,   232,   230,   435,   123,   229,   232,   232,   230,
     445,   211,   239,   108,   239,   239,   211,   108,   211,   108,
     108,   108,   211,   211,   211,   239,   108,   108,   108,   108,
     239,   108,   108,   108,   108,   211,   232,   211,   232,   211,
     239,   239,   211,   211,   211,   211,   215,   211,   215,   211,
     211,   211,   211,   108,   239,   211,   239,   239,   211,   229,
     229,   232,   232,   369,   232,   232,   232,   232,   232,   230,
     363,   232,   232,   230,   429,   229,   232,   232,   349,   232,
     230,   353,   123,   123,   229,   229,   232,   232,   230,   276,
     229,   232,   232,   319,   232,   232,   232,   232,   232,   315,
     232,   232,   230,   304,   229,   232,   232,   232,   230,   378,
     211,   211,   211,   123,   211,   211,   211,   239,   229,   108,
     123,   211,   123,   108,   108,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   229,   229,   232,   402,
     230,   399,   211,   229,   231,   229,   232,   232,   232,   232,
     230,   282,   123,   229,   229,   232,   393,   232,   230,   389,
     229,   229,   229,   229,   135,   136,   137,   138,   139,   140,
     141,   238,   239,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   108,   108,   239,   232,
     108,   108,   108,   239,   108,   108,   239,   123,   108,   108,
     239,   108,   241,   241,   229,   123,   178,   179,   123,   211,
     123,   123,   232,   123,   123,   108,   123,   123,   123,   123,
     229,   123,   123,   229,   229,   123,   123,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,    46,   164,   165,   166,   169,   170,   172,
     173,   175,   177,   180,   182,   183,   188,   192,   196,   197,
     198,   203,   208,   498,   499,   229,    46,    48,    49,   164,
     165,   166,   169,   170,   172,   173,   175,   177,   180,   182,
     183,   188,   192,   196,   197,   198,   203,   208,   494,   495,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     123,   211,   232,   123,   108,   123,   123,   123,   229,   123,
     123,   229,   123,   123,   232,   108,   356,   357,   229,   229,
     229,   123,   123,   229,   123,   211,   232,   123,   123,   123,
     123,   211,   232,   123,   123,   229,   123,   123,   123,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   123,   232,   229,   229,     1,
      98,   195,   219,   293,   294,   295,   296,   297,   123,   123,
     123,   123,   229,   229,   123,   232,   123,   229,   238,   238,
     238,   238,   238,   238,   238,   229,   229,   229,    50,   124,
     344,   345,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,    11,    12,    13,   240,   241,   229,   229,
     229,   229,   229,   229,   229,   229,   229,     8,   199,   419,
     420,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   233,   229,   233,   229,   229,    15,    40,
      68,    99,   100,   107,   132,   148,   210,   228,   370,   371,
     229,   229,   229,   229,   229,   229,   229,   229,   229,    46,
     190,   199,   350,   351,   218,   233,   355,   229,   229,   229,
     229,     4,    20,    31,    65,    67,    95,   128,   130,   149,
     171,   176,   180,   184,   189,   193,   204,   207,   209,   220,
     227,   320,   321,   229,   229,   229,   229,   229,    46,    48,
      49,   164,   165,   166,   169,   170,   172,   173,   175,   177,
     180,   182,   183,   188,   192,   196,   197,   198,   203,   208,
     316,   317,   229,   229,   229,   229,   229,   229,    67,   131,
     163,   171,   180,   204,   206,   207,   220,   227,   403,   404,
     229,   232,   232,   298,   230,   294,   229,   229,   229,   229,
     229,    67,   131,   163,   171,   180,   204,   206,   207,   220,
     227,   394,   395,   229,   229,   233,   240,   240,   240,   229,
     233,   499,   495,   229,   233,   229,   233,   108,   357,   229,
     234,   234,   234,   229,   233,   229,   233,   229,   233,   123,
     205,   241,   232,   229,   229,   233,   345,   420,   371,   351,
     129,   129,   129,   321,   317,   404,   229,   229,   229,    65,
      67,   114,   131,   170,   171,   222,   227,   299,   300,   395,
     229,   233,   300
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   235,   236,   236,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   242,   243,   243,   244,   244,   244,
     245,   246,   247,   248,   248,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   268,   269,   269,   269,   269,   270,   271,   272,
     274,   273,   275,   275,   276,   276,   276,   277,   278,   280,
     279,   281,   281,   282,   282,   282,   282,   282,   283,   284,
     285,   286,   287,   288,   288,   289,   289,   289,   290,   292,
     291,   293,   293,   294,   294,   294,   294,   295,   296,   296,
     298,   297,   299,   299,   300,   300,   300,   300,   300,   300,
     300,   300,   302,   301,   303,   303,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   315,   314,   316,
     316,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   319,   318,   320,   320,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     323,   322,   324,   324,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   343,   342,
     344,   344,   345,   345,   347,   346,   349,   348,   350,   350,
     351,   351,   351,   352,   352,   353,   353,   353,   353,   353,
     355,   354,   356,   356,   357,   357,   358,   359,   361,   360,
     362,   362,   363,   363,   363,   363,   363,   363,   363,   363,
     363,   364,   365,   366,   367,   369,   368,   370,   370,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   372,
     373,   374,   376,   375,   377,   377,   378,   378,   378,   378,
     379,   380,   381,   382,   383,   383,   384,   384,   385,   387,
     386,   388,   388,   389,   389,   389,   389,   390,   391,   393,
     392,   394,   394,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   397,   396,   398,   398,   399,   399,   399,
     400,   402,   401,   403,   403,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   406,   405,   407,   407,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   416,   418,   417,   419,   419,   420,   420,   421,
     422,   423,   424,   425,   427,   426,   428,   428,   429,   429,
     429,   430,   431,   433,   432,   434,   434,   435,   435,   435,
     436,   437,   438,   439,   439,   440,   440,   441,   443,   442,
     444,   444,   445,   445,   445,   446,   447,   448,   449,   449,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   477,   478,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     493,   492,   494,   494,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   497,   496,   498,   498,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   499,   499,
     500,   501,   502,   503,   504,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   521,   522,   522,
     522,   522,   522,   522,   522,   522,   522,   523,   524,   525,
     526,   527,   528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4
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
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 450 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 480 "conf_parser.y" /* yacc.c:1646  */
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
#line 3024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 520 "conf_parser.y" /* yacc.c:1646  */
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
#line 3085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 578 "conf_parser.y" /* yacc.c:1646  */
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
#line 3117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 607 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 615 "conf_parser.y" /* yacc.c:1646  */
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
#line 3145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 629 "conf_parser.y" /* yacc.c:1646  */
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
#line 3176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 657 "conf_parser.y" /* yacc.c:1646  */
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
#line 3194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 672 "conf_parser.y" /* yacc.c:1646  */
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
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 687 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 697 "conf_parser.y" /* yacc.c:1646  */
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
#line 3242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 720 "conf_parser.y" /* yacc.c:1646  */
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
#line 3285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 748 "conf_parser.y" /* yacc.c:1646  */
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
#line 3316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 776 "conf_parser.y" /* yacc.c:1646  */
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
#line 3344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 801 "conf_parser.y" /* yacc.c:1646  */
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
#line 3369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 823 "conf_parser.y" /* yacc.c:1646  */
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
#line 3394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 845 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 892 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 896 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 932 "conf_parser.y" /* yacc.c:1646  */
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
#line 3510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 968 "conf_parser.y" /* yacc.c:1646  */
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
#line 3558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1005 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1032 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3670 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1068 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3688 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3697 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1089 "conf_parser.y" /* yacc.c:1646  */
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
#line 3794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1209 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1381 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1389 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4290 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
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
#line 4325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1463 "conf_parser.y" /* yacc.c:1646  */
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
#line 4378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4556 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4573 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4591 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
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
#line 4624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
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
#line 4644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
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
#line 4712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4753 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
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
#line 4869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
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
#line 4991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1995 "conf_parser.y" /* yacc.c:1646  */
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
#line 5022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5049 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5058 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5121 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5177 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5186 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5249 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5258 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2148 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2157 "conf_parser.y" /* yacc.c:1646  */
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
#line 5338 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
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
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
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
#line 5397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2367 "conf_parser.y" /* yacc.c:1646  */
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
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2392 "conf_parser.y" /* yacc.c:1646  */
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
#line 5571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
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
#line 5615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2471 "conf_parser.y" /* yacc.c:1646  */
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
#line 5650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2492 "conf_parser.y" /* yacc.c:1646  */
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
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5690 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2582 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2587 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2592 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2603 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2608 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2613 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2618 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2623 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2628 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2633 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2638 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2643 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2648 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2653 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2658 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2663 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2668 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2673 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2679 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2684 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2689 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2704 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2735 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2740 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2745 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2750 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2755 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2760 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2765 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2770 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2775 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2790 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2864 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2932 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2942 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2947 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2981 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2986 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3016 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3021 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3026 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3036 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3063 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6551 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3096 "conf_parser.y" /* yacc.c:1646  */
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
#line 6599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6617 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6621 "conf_parser.c" /* yacc.c:1646  */
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
