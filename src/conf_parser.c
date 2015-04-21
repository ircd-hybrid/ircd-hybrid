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
    HAVENT_READ_CONF = 301,
    HIDDEN = 302,
    HIDDEN_NAME = 303,
    HIDE_CHANS = 304,
    HIDE_IDLE = 305,
    HIDE_IDLE_FROM_OPERS = 306,
    HIDE_SERVER_IPS = 307,
    HIDE_SERVERS = 308,
    HIDE_SERVICES = 309,
    HOST = 310,
    HUB = 311,
    HUB_MASK = 312,
    IGNORE_BOGUS_TS = 313,
    INVISIBLE_ON_CONNECT = 314,
    INVITE_CLIENT_COUNT = 315,
    INVITE_CLIENT_TIME = 316,
    IP = 317,
    IRCD_AUTH = 318,
    IRCD_FLAGS = 319,
    IRCD_SID = 320,
    KILL = 321,
    KILL_CHASE_TIME_LIMIT = 322,
    KLINE = 323,
    KLINE_EXEMPT = 324,
    KLINE_MIN_CIDR = 325,
    KLINE_MIN_CIDR6 = 326,
    KNOCK_CLIENT_COUNT = 327,
    KNOCK_CLIENT_TIME = 328,
    KNOCK_DELAY_CHANNEL = 329,
    LEAF_MASK = 330,
    LINKS_DELAY = 331,
    LISTEN = 332,
    MASK = 333,
    MAX_ACCEPT = 334,
    MAX_BANS = 335,
    MAX_CHANNELS = 336,
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
    SSL_DH_ELLIPTIC_CURVE = 409,
    SSL_DH_PARAM_FILE = 410,
    SSL_MESSAGE_DIGEST_ALGORITHM = 411,
    STATS_E_DISABLED = 412,
    STATS_I_OPER_ONLY = 413,
    STATS_K_OPER_ONLY = 414,
    STATS_M_OPER_ONLY = 415,
    STATS_O_OPER_ONLY = 416,
    STATS_P_OPER_ONLY = 417,
    STATS_U_OPER_ONLY = 418,
    T_ALL = 419,
    T_BOTS = 420,
    T_CALLERID = 421,
    T_CCONN = 422,
    T_COMMAND = 423,
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
    T_NCHANGE = 438,
    T_NONONREG = 439,
    T_OPME = 440,
    T_PREPEND = 441,
    T_PSEUDO = 442,
    T_RECVQ = 443,
    T_REJ = 444,
    T_RESTART = 445,
    T_SERVER = 446,
    T_SERVICE = 447,
    T_SERVNOTICE = 448,
    T_SET = 449,
    T_SHARED = 450,
    T_SIZE = 451,
    T_SKILL = 452,
    T_SOFTCALLERID = 453,
    T_SPY = 454,
    T_SSL = 455,
    T_SSL_CIPHER_LIST = 456,
    T_TARGET = 457,
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
    THROTTLE_COUNT = 468,
    THROTTLE_TIME = 469,
    TKLINE_EXPIRE_NOTICES = 470,
    TMASKED = 471,
    TS_MAX_DELTA = 472,
    TS_WARN_DELTA = 473,
    TWODOTS = 474,
    TYPE = 475,
    UNKLINE = 476,
    USE_LOGGING = 477,
    USER = 478,
    VHOST = 479,
    VHOST6 = 480,
    WARN_NO_CONNECT_BLOCK = 481,
    WHOIS = 482,
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
#define HAVENT_READ_CONF 301
#define HIDDEN 302
#define HIDDEN_NAME 303
#define HIDE_CHANS 304
#define HIDE_IDLE 305
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HOST 310
#define HUB 311
#define HUB_MASK 312
#define IGNORE_BOGUS_TS 313
#define INVISIBLE_ON_CONNECT 314
#define INVITE_CLIENT_COUNT 315
#define INVITE_CLIENT_TIME 316
#define IP 317
#define IRCD_AUTH 318
#define IRCD_FLAGS 319
#define IRCD_SID 320
#define KILL 321
#define KILL_CHASE_TIME_LIMIT 322
#define KLINE 323
#define KLINE_EXEMPT 324
#define KLINE_MIN_CIDR 325
#define KLINE_MIN_CIDR6 326
#define KNOCK_CLIENT_COUNT 327
#define KNOCK_CLIENT_TIME 328
#define KNOCK_DELAY_CHANNEL 329
#define LEAF_MASK 330
#define LINKS_DELAY 331
#define LISTEN 332
#define MASK 333
#define MAX_ACCEPT 334
#define MAX_BANS 335
#define MAX_CHANNELS 336
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
#define SSL_DH_ELLIPTIC_CURVE 409
#define SSL_DH_PARAM_FILE 410
#define SSL_MESSAGE_DIGEST_ALGORITHM 411
#define STATS_E_DISABLED 412
#define STATS_I_OPER_ONLY 413
#define STATS_K_OPER_ONLY 414
#define STATS_M_OPER_ONLY 415
#define STATS_O_OPER_ONLY 416
#define STATS_P_OPER_ONLY 417
#define STATS_U_OPER_ONLY 418
#define T_ALL 419
#define T_BOTS 420
#define T_CALLERID 421
#define T_CCONN 422
#define T_COMMAND 423
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
#define T_NCHANGE 438
#define T_NONONREG 439
#define T_OPME 440
#define T_PREPEND 441
#define T_PSEUDO 442
#define T_RECVQ 443
#define T_REJ 444
#define T_RESTART 445
#define T_SERVER 446
#define T_SERVICE 447
#define T_SERVNOTICE 448
#define T_SET 449
#define T_SHARED 450
#define T_SIZE 451
#define T_SKILL 452
#define T_SOFTCALLERID 453
#define T_SPY 454
#define T_SSL 455
#define T_SSL_CIPHER_LIST 456
#define T_TARGET 457
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
#define THROTTLE_COUNT 468
#define THROTTLE_TIME 469
#define TKLINE_EXPIRE_NOTICES 470
#define TMASKED 471
#define TS_MAX_DELTA 472
#define TS_WARN_DELTA 473
#define TWODOTS 474
#define TYPE 475
#define UNKLINE 476
#define USE_LOGGING 477
#define USER 478
#define VHOST 479
#define VHOST6 480
#define WARN_NO_CONNECT_BLOCK 481
#define WHOIS 482
#define XLINE 483

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
#define YYLAST   1288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  297
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1317

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
    1826,  1830,  1834,  1838,  1842,  1846,  1850,  1854,  1860,  1874,
    1883,  1897,  1896,  1911,  1911,  1912,  1912,  1912,  1912,  1914,
    1920,  1926,  1936,  1938,  1938,  1939,  1939,  1941,  1957,  1956,
    1981,  1981,  1982,  1982,  1982,  1982,  1984,  1990,  2010,  2009,
    2015,  2015,  2016,  2020,  2024,  2028,  2032,  2036,  2040,  2044,
    2048,  2052,  2062,  2061,  2082,  2082,  2083,  2083,  2083,  2085,
    2092,  2091,  2097,  2097,  2098,  2102,  2106,  2110,  2114,  2118,
    2122,  2126,  2130,  2134,  2144,  2143,  2215,  2215,  2216,  2217,
    2218,  2219,  2220,  2221,  2222,  2223,  2224,  2225,  2226,  2227,
    2228,  2229,  2230,  2232,  2238,  2244,  2250,  2263,  2276,  2282,
    2288,  2292,  2299,  2298,  2303,  2303,  2304,  2308,  2314,  2325,
    2331,  2337,  2343,  2359,  2358,  2384,  2384,  2385,  2385,  2385,
    2387,  2407,  2417,  2416,  2443,  2443,  2444,  2444,  2444,  2446,
    2452,  2461,  2463,  2463,  2464,  2464,  2466,  2484,  2483,  2506,
    2506,  2507,  2507,  2507,  2509,  2515,  2524,  2527,  2527,  2528,
    2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,
    2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,
    2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,  2558,
    2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568,
    2569,  2570,  2571,  2572,  2573,  2574,  2575,  2578,  2583,  2588,
    2593,  2599,  2604,  2609,  2614,  2619,  2624,  2629,  2634,  2639,
    2644,  2649,  2654,  2659,  2664,  2669,  2675,  2686,  2691,  2696,
    2701,  2706,  2711,  2716,  2721,  2724,  2729,  2732,  2737,  2742,
    2747,  2752,  2757,  2762,  2767,  2772,  2777,  2782,  2787,  2792,
    2797,  2803,  2802,  2807,  2807,  2808,  2811,  2814,  2817,  2820,
    2823,  2826,  2829,  2832,  2835,  2838,  2841,  2844,  2847,  2850,
    2853,  2856,  2859,  2862,  2865,  2868,  2871,  2877,  2876,  2881,
    2881,  2882,  2885,  2888,  2891,  2894,  2897,  2900,  2903,  2906,
    2909,  2912,  2915,  2918,  2921,  2924,  2927,  2930,  2933,  2936,
    2939,  2944,  2949,  2954,  2963,  2966,  2966,  2967,  2968,  2969,
    2970,  2971,  2972,  2973,  2974,  2975,  2976,  2977,  2978,  2979,
    2980,  2981,  2983,  2988,  2993,  2998,  3003,  3008,  3013,  3018,
    3023,  3028,  3033,  3038,  3043,  3048,  3056,  3059,  3059,  3060,
    3061,  3062,  3063,  3064,  3065,  3066,  3067,  3068,  3070,  3076,
    3082,  3088,  3094,  3103,  3118,  3124
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
  "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
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
  "general_ts_max_delta", "general_havent_read_conf",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_m_oper_only",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_oper_pass_resv",
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

#define YYPACT_NINF -745

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-745)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -745,   655,  -745,  -139,  -227,  -212,  -745,  -745,  -745,  -209,
    -745,  -206,  -745,  -745,  -745,  -204,  -745,  -745,  -745,  -195,
    -185,  -745,  -169,  -745,  -162,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   374,   894,  -150,  -119,  -104,    11,   -90,   399,   -81,
     -76,   -73,   171,   -57,   -55,   -47,   449,   539,   -41,    32,
     -32,    17,   -16,   -12,    -1,    26,    33,    49,  -745,  -745,
    -745,  -745,  -745,    50,    65,    72,    78,    89,    91,    92,
      94,    99,   100,   106,   125,   126,   127,   235,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   661,   534,    14,  -745,   129,     2,  -745,
    -745,    87,  -745,   132,   133,   135,   136,   137,   142,   144,
     145,   150,   151,   152,   153,   154,   155,   158,   161,   164,
     165,   166,   167,   169,   170,   175,   178,   179,   182,  -745,
     183,  -745,   184,   185,   186,   187,   193,   196,   197,   201,
     207,   210,   212,   215,   216,   217,   221,   222,   228,   232,
       7,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   324,
      25,   317,    42,   236,   239,    22,  -745,  -745,  -745,   110,
     327,    74,  -745,   242,   249,   250,   258,   263,   266,   267,
     268,     4,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   119,   273,   275,   276,   277,   278,   282,   286,   287,
     290,   292,   294,   295,   297,   299,   300,   302,   304,     5,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,    82,   203,
     306,    27,  -745,  -745,  -745,   219,   176,  -745,   309,    39,
    -745,  -745,    97,  -745,   418,   419,   420,   316,  -745,   440,
     443,   446,   454,   352,   458,   443,   459,   443,   443,   461,
     462,   360,   362,   346,  -745,   347,   345,   349,   350,  -745,
     351,   353,   358,   364,   367,   368,   369,   370,   371,   375,
     376,   378,   379,   162,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   363,   383,   386,   387,   388,   390,   396,  -745,
     397,   402,   403,   407,   411,   414,   415,   237,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   421,   422,    23,  -745,  -745,  -745,
     463,   365,  -745,  -745,   426,   429,    36,  -745,  -745,  -745,
     366,   443,   470,   443,   443,   394,   522,   436,   541,   542,
     543,   452,   557,   456,   457,   443,   558,   561,   563,   572,
     443,   576,   578,   579,   588,   486,   469,   490,   471,   492,
     443,   443,   493,   494,   502,  -171,  -149,   503,   504,   505,
     507,   611,   443,   510,   443,   443,   511,   495,  -745,   497,
     496,   498,  -745,   499,   501,   506,   509,   515,    70,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   516,
     517,    47,  -745,  -745,  -745,   500,   519,   523,  -745,   524,
    -745,    81,  -745,  -745,  -745,  -745,  -745,   603,   615,   528,
    -745,   530,   529,   533,    53,  -745,  -745,  -745,   537,   535,
     536,  -745,   550,   552,   553,   554,   556,  -745,   559,   560,
     200,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   540,   562,   564,   565,    59,  -745,  -745,
    -745,  -745,   577,   581,   583,   638,   586,   587,   590,   443,
     544,  -745,  -745,   681,   679,   592,   682,   702,   705,   693,
     695,   697,   698,   703,   704,   706,   708,   709,   710,   712,
     600,  -745,   609,   612,  -745,    83,  -745,  -745,  -745,  -745,
     631,   616,  -745,   617,   626,   624,   627,   630,   632,   112,
    -745,  -745,  -745,  -745,  -745,   743,   637,  -745,   640,   641,
    -745,   643,    58,  -745,  -745,  -745,  -745,   648,   649,   650,
    -745,   652,   571,   653,   654,   658,   659,   660,   670,   673,
     675,   678,   680,   683,   684,   686,  -745,  -745,   763,   781,
     443,   685,   819,   820,   821,   443,   823,   824,   443,   810,
     826,   828,   443,   829,   829,   711,  -745,  -745,   815,   107,
     817,   730,   822,   827,   713,   832,   833,   834,   835,   836,
     837,   838,   715,  -745,   840,   841,   719,  -745,   723,  -745,
     845,   847,   724,  -745,   729,   744,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   762,   764,   765,   766,   767,   768,   769,   772,   773,
     727,   774,   642,   775,   776,   777,   778,   779,   780,   782,
     783,   784,   785,   786,   787,   788,   789,   790,   791,   792,
     793,   794,   795,  -745,  -745,   848,   798,   796,   868,   916,
     902,   903,   905,   801,  -745,   907,   908,   804,  -745,  -745,
     910,   911,   805,   927,   809,  -745,   811,   812,  -745,  -745,
     915,   918,   814,  -745,  -745,   920,   839,   813,   922,   923,
     924,   925,   842,   818,   928,   929,   830,  -745,  -745,   931,
     932,   933,   831,  -745,   843,   844,   846,   849,   850,   851,
     852,   853,  -745,   854,   855,   856,   857,   858,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   869,   870,   871,
    -745,  -745,   934,   872,   873,  -745,   874,  -745,    54,  -745,
     937,   938,   939,   940,   876,  -745,   877,  -745,  -745,   941,
     875,   942,   879,  -745,  -745,  -745,  -745,  -745,   443,   443,
     443,   443,   443,   443,   443,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     880,   881,   882,   -31,   883,   884,   885,   886,   887,   888,
     889,   890,   891,   892,   893,   181,   895,   896,  -745,   897,
     898,   899,   900,   901,   904,   906,     3,   909,   912,   913,
     914,   917,   919,   921,  -745,   926,   930,  -745,  -745,   935,
     936,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -161,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -103,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   943,   944,   355,   945,   946,
     947,   948,   949,  -745,   950,   951,  -745,   952,   953,   -13,
     878,   954,  -745,  -745,  -745,  -745,   955,   956,  -745,   957,
     959,   455,   960,   961,   962,   963,   964,   687,   965,   966,
    -745,   967,   968,   969,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     970,   416,  -745,  -745,   971,   972,   973,  -745,   109,  -745,
    -745,  -745,  -745,   974,   977,   978,   979,  -745,  -745,   980,
     742,   981,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   -58,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   829,   829,
     829,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   -38,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   727,  -745,
     642,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   -24,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,   -19,  -745,   958,   927,
     982,  -745,  -745,  -745,  -745,  -745,   983,  -745,   984,  -745,
    -745,  -745,  -745,   985,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   -17,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,    -6,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   104,  -745,  -745,   999,   -77,   988,   986,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   116,  -745,  -745,  -745,   -31,
    -745,  -745,  -745,  -745,     3,  -745,  -745,  -745,   355,  -745,
     -13,  -745,  -745,  -745,  1001,  1002,  1004,  -745,   455,  -745,
     687,  -745,   416,   987,   992,   993,   305,  -745,  -745,   742,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   118,  -745,  -745,  -745,   305,  -745
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
      95,    94,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   630,
     618,   619,   620,   621,   622,   623,   617,   624,   625,   626,
     627,   628,   629,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   587,
       0,   561,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   468,   469,   470,   514,   515,   509,   510,   511,   512,
     508,   480,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   505,   481,   482,   513,   486,   487,   488,   489,   485,
     484,   490,   498,   499,   491,   492,   493,   494,   483,   496,
     506,   507,   503,   504,   497,   495,   501,   502,   500,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   657,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   648,   649,   650,   651,   652,   655,   653,   654,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    69,    66,    64,    70,    71,    65,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   124,   125,   126,     0,     0,   346,     0,     0,
     344,   345,     0,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,     0,     0,     0,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   233,   234,   237,   239,   240,   241,
     242,   243,   244,   245,   246,   247,   235,   236,   238,   248,
     249,   250,     0,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,   397,   398,
     399,   400,   401,   402,   403,   405,   404,   407,   411,   408,
     409,   410,   406,   448,     0,     0,     0,   445,   446,   447,
       0,     0,   452,   463,     0,     0,     0,   460,   461,   462,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,     0,
       0,     0,   315,     0,     0,     0,     0,     0,     0,   301,
     302,   303,   304,   309,   305,   306,   307,   308,   439,     0,
       0,     0,   436,   437,   438,     0,     0,     0,   276,     0,
     286,     0,   284,   285,   287,   288,    49,     0,     0,     0,
      45,     0,     0,     0,     0,   103,   104,   105,     0,     0,
       0,   203,     0,     0,     0,     0,     0,   177,     0,     0,
       0,   155,   156,   157,   158,   159,   162,   163,   164,   165,
     161,   160,   166,     0,     0,     0,     0,     0,   334,   335,
     336,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,   380,     0,   375,   376,   377,   127,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   115,   114,   116,     0,     0,   343,     0,     0,
     358,     0,     0,   351,   352,   353,   354,     0,     0,     0,
      90,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   251,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   412,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   396,     0,     0,     0,   444,     0,   451,
       0,     0,     0,   459,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   466,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,   435,   289,
       0,     0,     0,     0,     0,   283,     0,     0,    44,   106,
       0,     0,     0,   102,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   338,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,   646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   378,     0,     0,     0,   374,     0,   122,     0,   117,
       0,     0,     0,     0,     0,   111,     0,   342,   355,     0,
       0,     0,     0,   350,    99,    98,    97,   644,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   645,   641,   640,
     632,   633,   634,   635,   636,   637,   639,   638,   642,   643,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   231,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,   443,   456,     0,
       0,   458,   529,   533,   517,   518,   549,   520,   613,   558,
     521,   522,   555,   528,   536,   527,   537,   526,   523,   524,
     532,   531,   530,   556,   519,   611,   612,   553,   597,   591,
     607,   592,   593,   594,   602,   610,   595,   604,   608,   598,
     609,   599,   603,   596,   606,   601,   600,   605,     0,   590,
     554,   570,   571,   572,   565,   583,   566,   567,   568,   578,
     586,   569,   580,   584,   574,   585,   575,   579,   573,   582,
     577,   576,   581,     0,   564,   550,   548,   551,   557,   552,
     539,   546,   547,   544,   545,   540,   541,   542,   543,   559,
     560,   525,   535,   534,   538,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,   434,     0,     0,     0,
     294,   290,   293,   275,    50,    51,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   332,   659,   658,   664,   662,   665,
     660,   661,   663,    86,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    76,    84,    85,
       0,     0,   373,   128,     0,     0,     0,   140,     0,   132,
     133,   135,   134,     0,     0,     0,     0,   110,   347,     0,
       0,     0,   349,    31,    32,    33,    34,    35,    36,    37,
     263,   264,   255,   273,   272,     0,   271,   256,   258,   260,
     267,   259,   257,   266,   252,   265,   254,   253,    38,    38,
      38,    40,    39,   261,   262,   417,   420,   421,   431,   428,
     414,   429,   426,   427,     0,   425,   430,   413,   419,   416,
     418,   432,   415,   449,   450,   464,   465,   588,     0,   562,
       0,   313,   314,   323,   320,   321,   322,   327,   324,   325,
     319,   326,     0,   318,   312,   330,   329,   328,   311,   441,
     440,   297,   296,   281,   282,   280,     0,   279,     0,     0,
       0,   107,   108,   176,   172,   222,   210,   219,   208,   213,
     228,   221,   226,   212,   215,   223,   225,   229,   220,   227,
     216,   218,   224,   214,   217,     0,   206,   168,   170,   173,
     174,   175,   186,   187,   188,   181,   199,   182,   183,   184,
     194,   202,   185,   196,   200,   190,   201,   191,   195,   189,
     198,   193,   192,   197,     0,   180,   169,   171,   341,   339,
     340,   379,   384,   390,   393,   386,   392,   387,   391,   389,
     385,   388,     0,   383,   136,     0,     0,     0,     0,   131,
     119,   118,   120,   121,   356,   362,   368,   371,   364,   370,
     365,   369,   367,   363,   366,     0,   361,   357,   269,     0,
      41,    42,    43,   423,     0,   589,   563,   316,     0,   277,
       0,   295,   292,   291,     0,     0,     0,   204,     0,   178,
       0,   381,     0,     0,     0,     0,     0,   130,   359,     0,
     270,   424,   317,   278,   209,   207,   211,   205,   179,   382,
     137,   139,   138,   150,   149,   145,   147,   151,   148,   144,
     146,     0,   143,   360,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -745,  -745,  -745,   -53,  -308,  -744,  -643,  -745,  -745,   976,
    -745,  -745,  -745,  -745,   799,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   994,  -745,  -745,  -745,  -745,  -745,
    -745,   566,  -745,  -745,  -745,  -745,  -745,   480,  -745,  -745,
    -745,  -745,  -745,  -745,   975,  -745,  -745,  -745,  -745,    16,
    -745,  -745,  -745,  -745,  -745,  -239,  -745,  -745,  -745,   619,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -203,  -745,  -745,  -745,  -177,  -745,  -745,  -745,
     797,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -123,  -745,  -745,  -745,  -745,  -745,  -133,  -745,   656,  -745,
    -745,  -745,   -15,  -745,  -745,  -745,  -745,  -745,   677,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -117,  -745,  -745,  -745,
    -745,  -745,  -745,   620,  -745,  -745,  -745,  -745,  -745,   989,
    -745,  -745,  -745,  -745,   547,  -745,  -745,  -745,  -745,  -745,
    -137,  -745,  -745,  -745,   585,  -745,  -745,  -745,  -745,  -129,
    -745,  -745,  -745,   806,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -110,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   688,  -745,  -745,  -745,  -745,  -745,
     770,  -745,  -745,  -745,  -745,  1038,  -745,  -745,  -745,  -745,
     807,  -745,  -745,  -745,  -745,   991,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,    28,  -745,  -745,  -745,    34,  -745,  -745,  -745,  -745,
    -745,  1066,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   990,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   835,   836,  1101,  1102,    27,   225,   226,
     227,   228,    28,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,    29,    77,    78,    79,    80,    81,    30,    63,
     504,   505,   506,   507,    31,    70,   589,   590,   591,   592,
     593,   594,    32,   291,   292,   293,   294,   295,  1058,  1059,
    1060,  1061,  1062,  1237,  1311,  1312,    33,    64,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     763,  1214,  1215,   532,   757,  1185,  1186,    34,    53,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   360,   361,   631,  1085,
    1086,    35,    61,   490,   742,  1156,  1157,   491,   492,   493,
    1160,  1001,  1002,   494,   495,    36,    59,   468,   469,   470,
     471,   472,   473,   474,   727,  1142,  1143,   475,   476,   477,
      37,    65,   537,   538,   539,   540,   541,    38,   299,   300,
     301,    39,    72,   602,   603,   604,   605,   606,   820,  1255,
    1256,    40,    68,   575,   576,   577,   578,   803,  1232,  1233,
      41,    54,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   654,  1114,  1115,   388,   389,   390,   391,
     392,    42,    60,   481,   482,   483,   484,    43,    55,   396,
     397,   398,   399,    44,   118,   119,   120,    45,    57,   406,
     407,   408,   409,    46,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   438,
     963,   964,   215,   436,   938,   939,   216,   217,   218,    47,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,    48,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     866,   867,   613,   116,    51,   232,   251,   618,   122,   620,
     621,  1112,   116,   123,   124,   393,   125,   126,   297,    52,
    1083,   127,    56,   222,   393,    58,   478,    62,   289,   128,
     129,   252,   865,   289,  1153,   253,    66,   403,   233,   130,
     297,   709,   131,   132,   133,   710,    67,   234,   478,   134,
      73,   235,   236,   135,   501,  1054,   237,   238,   239,   598,
     533,   254,    69,   711,   117,   136,   137,   712,  1127,    71,
     255,   459,  1128,   117,   138,   533,   394,   139,   140,    74,
     240,   113,   485,   572,   572,   394,   141,    75,   403,   460,
      49,    50,   256,   142,  1084,   143,   257,   144,   598,   145,
     534,   146,   147,   675,   258,   677,   678,   259,   260,   461,
    1054,   501,   114,   584,   148,   534,   298,   689,   223,   149,
     150,   151,   694,   152,   153,   154,  1129,   115,   155,  1284,
    1130,   502,   704,   705,   462,   404,   486,   535,   298,   261,
     395,   121,   224,   487,   718,   488,   720,   721,    76,   395,
     219,   479,   535,  1055,   156,   220,   262,   599,   221,   263,
     264,   265,   405,   325,   157,   158,   159,   160,   161,   162,
     163,  1258,   222,   479,   229,  1259,   230,   584,  1154,   326,
     327,   573,   573,   328,   231,   536,   404,  1155,   502,   463,
     288,  1263,  1098,  1099,  1100,  1264,   599,   464,   465,   296,
     536,   508,  -129,  1113,   489,  1267,   266,  -129,  1055,  1268,
    1269,   585,  1277,   405,  1270,   302,  1278,   303,   466,   509,
     164,   165,   166,  1279,   167,   168,   329,  1280,   503,   267,
     268,   304,   401,   169,   550,   570,    82,   457,   362,   510,
     363,   781,   364,   330,   331,   332,   333,   334,   480,   290,
    1056,   335,   499,   666,   290,   336,   365,   581,   305,    83,
      84,   337,    85,    86,   511,   306,   672,   223,    87,   596,
     480,   496,   338,   339,  1057,   585,   366,   737,   600,   307,
     586,   601,   309,   752,   340,   503,   870,   871,   822,   772,
     865,   224,   367,   467,   368,    88,    89,   310,   587,   512,
     733,   369,   574,   574,   311,  1056,   341,    90,    91,    92,
     312,   744,   370,   804,   588,    93,    94,   600,   485,   513,
     601,   313,   852,   314,   315,   459,   316,   857,   508,  1057,
     860,   317,   318,  1281,   864,   514,   371,  1282,   319,  1238,
      95,    96,   814,   460,   586,  1288,   509,  1314,   552,  1289,
     342,  1315,   515,   516,  1260,  1261,  1262,   320,   321,   322,
     372,   400,   587,   461,   410,   411,   510,   412,   413,   414,
    1133,  1303,   486,  1304,   415,    73,   416,   417,   588,   487,
     373,   488,   418,   419,   420,   421,   422,   423,   462,   374,
     424,   511,   645,   425,   583,  1134,   426,   427,   428,   429,
     122,   430,   431,   517,    74,   123,   124,   432,   125,   126,
     433,   434,    75,   127,   435,   437,   439,   440,   441,   442,
    1305,   128,   129,   518,  1135,   443,   512,   519,   444,   445,
     766,   130,   579,   446,   131,   132,   133,  1306,   375,   447,
     489,   134,   448,   463,   449,   135,   513,   450,   451,   452,
     232,   464,   465,   453,   454,  1136,  1137,   136,   137,  1165,
     455,   376,   514,  1138,   456,   323,   138,   662,   497,   139,
     140,   498,   466,    76,   542,  1166,  1307,  1308,   141,   515,
     516,   543,   544,   233,  1222,   142,  1167,   143,  1139,   144,
     545,   145,   234,   146,   147,   546,   235,   236,   547,   548,
     549,   237,   238,   239,  1140,   553,   148,   554,   555,   556,
     557,   149,   150,   151,   558,   152,   153,   154,   559,   560,
     155,  1168,   561,  1169,   562,   240,   563,   564,  1309,   565,
     517,   566,   567,  1310,   568,   362,   569,   363,   580,   364,
     251,   595,   607,   608,   609,   610,   156,   467,  1223,   611,
     518,  1170,   612,   365,   519,   614,   157,   158,   159,   160,
     161,   162,   163,   615,   616,   252,  1141,   617,   619,   253,
     622,   623,   624,   366,   625,   626,   627,   628,   674,   676,
    1224,   629,   630,   632,  1171,   633,  1172,   668,  1225,   367,
     634,   368,   647,  1285,   669,   254,   635,  1226,   369,   636,
     637,   638,   639,   640,   255,  1173,   679,   641,   642,   370,
     643,   644,   164,   165,   166,   648,   167,   168,   649,   650,
     651,  1227,   652,  1228,  1229,   169,   256,  1174,   653,   655,
     257,   680,  1175,   371,   656,   657,  1176,  1230,   258,   658,
    1177,   259,   260,   659,  1231,  1178,   660,   661,   681,  1179,
     682,   683,   684,   664,   665,     2,     3,   372,   670,     4,
    1180,   671,   325,  1181,   685,  1182,   686,   690,   687,   688,
     691,     5,   692,   261,     6,     7,  1183,   373,   326,   327,
     612,   693,   328,  1184,     8,   695,   374,   696,   697,   941,
     262,   942,   943,   263,   264,   265,     9,   698,   699,    10,
      11,   700,   701,   702,   703,   706,   707,   828,   829,   830,
     831,   832,   833,   834,   708,   713,   714,   715,    12,   716,
     717,    13,   719,   722,   723,   329,   724,   746,   725,   739,
     726,   728,    14,   729,  1192,   375,  1193,  1194,   730,   747,
     266,   731,   330,   331,   332,   333,   334,   732,   735,   736,
     335,   740,    15,    16,   336,   741,   743,   748,   376,   749,
     337,   750,   777,   267,   268,   751,   754,   755,   756,   768,
      17,   338,   339,   782,   918,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,   758,   340,   759,   760,   761,    18,   762,   774,
     783,   764,   765,   775,   769,   776,   770,   771,   778,   779,
      19,    20,   780,   784,   785,   341,   786,   944,   945,   946,
    1245,   787,   947,   948,   788,   949,   950,   789,   951,   790,
     952,   791,   792,   953,    21,   954,   955,   793,   794,   800,
     795,   956,   796,   797,   798,   957,   799,    22,   801,   958,
     959,   960,    23,   806,   802,   807,   961,    24,   808,   342,
      25,   962,  1195,  1196,  1197,   809,   810,  1198,  1199,   811,
    1200,  1201,   812,  1202,   813,  1203,   817,   816,  1204,   818,
    1205,  1206,   850,   819,  1246,   821,  1207,   824,   825,   826,
    1208,   827,   837,   838,  1209,  1210,  1211,   839,   840,   841,
     851,  1212,   919,   920,   921,    82,  1213,   922,   923,   842,
     924,   925,   843,   926,   844,   927,  1247,   845,   928,   846,
     929,   930,   847,   848,  1248,   849,   931,   853,    83,    84,
     932,    85,    86,  1249,   933,   934,   935,    87,   854,   855,
     856,   936,   858,   859,   861,   862,   937,   863,   865,   869,
     868,   872,   873,   879,   884,   876,   874,  1250,   887,  1251,
    1252,   875,   888,   891,    88,    89,   877,   878,   892,   880,
     881,   882,   883,  1253,   885,   886,    90,    91,    92,   889,
    1254,   890,   985,   893,    93,    94,   894,   895,   896,   897,
     898,   899,   900,   901,   902,   903,   904,   905,   906,   907,
     908,   909,   988,   910,   911,   912,   913,   914,   915,    95,
      96,   916,   917,   940,   965,   966,   967,   968,   969,   970,
     986,   971,   972,   973,   974,   975,   976,   977,   978,   979,
     980,   981,   982,   983,   984,   989,   990,   991,   987,   992,
     993,   994,   995,   996,   997,   998,  1000,   999,  1003,  1006,
    1004,  1005,  1007,  1008,  1009,  1011,  1012,  1013,  1014,  1015,
    1017,  1010,  1018,  1019,  1016,  1021,  1022,  1023,  1050,  1020,
    1024,  1063,  1064,  1065,  1066,  1069,  1071,  1271,   571,   815,
     753,   308,  1025,  1026,  1239,  1027,  1316,  1298,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1040,  1041,  1042,  1043,  1044,  1045,  1046,  1158,  1047,  1048,
    1049,  1297,  1052,  1053,  1051,  1067,  1068,  1070,  1072,  1080,
    1081,  1082,  1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1283,  1103,  1104,  1105,  1106,  1107,  1108,
    1109,  1294,  1295,  1110,  1296,  1111,  1290,  1293,  1116,   767,
     646,  1117,  1118,  1119,  1272,   734,  1120,   745,  1121,   823,
    1122,  1292,  1313,  1299,  1291,  1123,   402,   773,  1266,  1124,
     805,   458,  1265,   324,  1125,  1126,   667,     0,     0,   738,
       0,     0,  1131,  1132,  1144,  1145,  1146,  1147,  1148,  1149,
    1150,  1151,  1152,   663,  1161,  1162,  1163,  1159,  1164,  1187,
    1188,  1189,  1190,  1191,  1216,  1217,  1218,  1219,  1220,  1221,
    1234,   500,     0,  1240,  1235,  1236,  1241,  1242,  1243,  1244,
    1257,  1273,     0,   673,     0,  1287,  1300,  1274,  1275,  1276,
    1286,  1301,  1302,     0,     0,     0,     0,     0,     0,     0,
       0,   551,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   582,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   597
};

static const yytype_int16 yycheck[] =
{
     643,   644,   310,     1,   231,     1,     1,   315,     1,   317,
     318,     8,     1,     6,     7,     1,     9,    10,     1,   231,
      51,    14,   231,     1,     1,   231,     1,   231,     1,    22,
      23,    26,   109,     1,    47,    30,   231,     1,    34,    32,
       1,   212,    35,    36,    37,   216,   231,    43,     1,    42,
       1,    47,    48,    46,     1,     1,    52,    53,    54,     1,
       1,    56,   231,   212,    62,    58,    59,   216,   229,   231,
      65,     1,   233,    62,    67,     1,    62,    70,    71,    30,
      76,   231,     1,     1,     1,    62,    79,    38,     1,    19,
     229,   230,    87,    86,   125,    88,    91,    90,     1,    92,
      41,    94,    95,   411,    99,   413,   414,   102,   103,    39,
       1,     1,   231,     1,   107,    41,    99,   425,    96,   112,
     113,   114,   430,   116,   117,   118,   229,   231,   121,   206,
     233,    78,   440,   441,    64,    99,    55,    78,    99,   134,
     126,   231,   120,    62,   452,    64,   454,   455,    99,   126,
     231,   126,    78,    99,   147,   231,   151,    99,   231,   154,
     155,   156,   126,     1,   157,   158,   159,   160,   161,   162,
     163,   229,     1,   126,   231,   233,   231,     1,   191,    17,
      18,    99,    99,    21,   231,   126,    99,   200,    78,   119,
     231,   229,    11,    12,    13,   233,    99,   127,   128,   231,
     126,     1,   175,   200,   123,   229,   201,   175,    99,   233,
     229,    99,   229,   126,   233,   231,   233,   229,   148,    19,
     213,   214,   215,   229,   217,   218,    64,   233,   175,   224,
     225,   232,   230,   226,   230,   230,     1,   230,     1,    39,
       3,   549,     5,    81,    82,    83,    84,    85,   223,   222,
     196,    89,   230,   230,   222,    93,    19,   230,   232,    24,
      25,    99,    27,    28,    64,   232,   230,    96,    33,   230,
     223,   229,   110,   111,   220,    99,    39,   230,   220,   230,
     168,   223,   232,   230,   122,   175,   179,   180,   230,   230,
     109,   120,    55,   223,    57,    60,    61,   232,   186,    99,
     230,    64,   220,   220,   232,   196,   144,    72,    73,    74,
     232,   230,    75,   230,   202,    80,    81,   220,     1,   119,
     223,   232,   630,   232,   232,     1,   232,   635,     1,   220,
     638,   232,   232,   229,   642,   135,    99,   233,   232,   230,
     105,   106,   230,    19,   168,   229,    19,   229,   229,   233,
     188,   233,   152,   153,  1098,  1099,  1100,   232,   232,   232,
     123,   232,   186,    39,   232,   232,    39,   232,   232,   232,
      15,    66,    55,    68,   232,     1,   232,   232,   202,    62,
     143,    64,   232,   232,   232,   232,   232,   232,    64,   152,
     232,    64,   230,   232,   175,    40,   232,   232,   232,   232,
       1,   232,   232,   203,    30,     6,     7,   232,     9,    10,
     232,   232,    38,    14,   232,   232,   232,   232,   232,   232,
     115,    22,    23,   223,    69,   232,    99,   227,   232,   232,
     230,    32,   229,   232,    35,    36,    37,   132,   201,   232,
     123,    42,   232,   119,   232,    46,   119,   232,   232,   232,
       1,   127,   128,   232,   232,   100,   101,    58,    59,     4,
     232,   224,   135,   108,   232,   230,    67,   230,   232,    70,
      71,   232,   148,    99,   232,    20,   171,   172,    79,   152,
     153,   232,   232,    34,    68,    86,    31,    88,   133,    90,
     232,    92,    43,    94,    95,   232,    47,    48,   232,   232,
     232,    52,    53,    54,   149,   232,   107,   232,   232,   232,
     232,   112,   113,   114,   232,   116,   117,   118,   232,   232,
     121,    66,   232,    68,   232,    76,   232,   232,   223,   232,
     203,   232,   232,   228,   232,     1,   232,     3,   232,     5,
       1,   232,   124,   124,   124,   229,   147,   223,   132,   109,
     223,    96,   109,    19,   227,   109,   157,   158,   159,   160,
     161,   162,   163,   109,   212,    26,   211,   109,   109,    30,
     109,   109,   212,    39,   212,   229,   229,   232,   212,   109,
     164,   232,   232,   232,   129,   232,   131,   124,   172,    55,
     232,    57,   229,  1236,   229,    56,   232,   181,    64,   232,
     232,   232,   232,   232,    65,   150,   212,   232,   232,    75,
     232,   232,   213,   214,   215,   232,   217,   218,   232,   232,
     232,   205,   232,   207,   208,   226,    87,   172,   232,   232,
      91,   109,   177,    99,   232,   232,   181,   221,    99,   232,
     185,   102,   103,   232,   228,   190,   232,   232,   212,   194,
     109,   109,   109,   232,   232,     0,     1,   123,   232,     4,
     205,   232,     1,   208,   212,   210,   109,   109,   212,   212,
     109,    16,   109,   134,    19,    20,   221,   143,    17,    18,
     109,   109,    21,   228,    29,   109,   152,   109,   109,    47,
     151,    49,    50,   154,   155,   156,    41,   109,   212,    44,
      45,   232,   212,   232,   212,   212,   212,   136,   137,   138,
     139,   140,   141,   142,   212,   212,   212,   212,    63,   212,
     109,    66,   212,   212,   229,    64,   229,   124,   232,   229,
     232,   232,    77,   232,    47,   201,    49,    50,   232,   124,
     201,   232,    81,    82,    83,    84,    85,   232,   232,   232,
      89,   232,    97,    98,    93,   232,   232,   229,   224,   229,
      99,   232,   124,   224,   225,   232,   229,   232,   232,   229,
     115,   110,   111,   229,    47,   828,   829,   830,   831,   832,
     833,   834,   232,   122,   232,   232,   232,   132,   232,   212,
     109,   232,   232,   212,   232,   212,   232,   232,   212,   212,
     145,   146,   212,   124,   212,   144,   124,   165,   166,   167,
      68,   109,   170,   171,   109,   173,   174,   124,   176,   124,
     178,   124,   124,   181,   169,   183,   184,   124,   124,   229,
     124,   189,   124,   124,   124,   193,   124,   182,   229,   197,
     198,   199,   187,   212,   232,   229,   204,   192,   231,   188,
     195,   209,   165,   166,   167,   229,   232,   170,   171,   232,
     173,   174,   232,   176,   232,   178,   229,   124,   181,   229,
     183,   184,   109,   232,   132,   232,   189,   229,   229,   229,
     193,   229,   229,   229,   197,   198,   199,   229,   229,   229,
     109,   204,   165,   166,   167,     1,   209,   170,   171,   229,
     173,   174,   229,   176,   229,   178,   164,   229,   181,   229,
     183,   184,   229,   229,   172,   229,   189,   232,    24,    25,
     193,    27,    28,   181,   197,   198,   199,    33,   109,   109,
     109,   204,   109,   109,   124,   109,   209,   109,   109,   124,
     229,   124,   212,   109,   229,   232,   124,   205,   229,   207,
     208,   124,   229,   229,    60,    61,   124,   124,   229,   124,
     124,   124,   124,   221,   124,   124,    72,    73,    74,   124,
     228,   124,   124,   229,    80,    81,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   124,   229,   229,   229,   229,   229,   229,   105,
     106,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     212,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   109,   124,   124,   232,   124,
     229,   124,   124,   229,   124,   124,   109,   232,   229,   124,
     229,   229,   124,   229,   124,   232,   124,   124,   124,   124,
     232,   212,   124,   124,   212,   124,   124,   124,   124,   229,
     229,   124,   124,   124,   124,   124,   124,   109,   269,   589,
     504,    77,   229,   229,  1058,   229,  1315,  1280,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   219,   229,   229,
     229,  1278,   229,   229,   232,   229,   229,   232,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   124,   229,   229,   229,   229,   229,   229,
     229,   130,   130,   229,   130,   229,  1259,  1270,   229,   520,
     343,   229,   229,   229,  1159,   468,   229,   491,   229,   602,
     229,  1268,  1289,  1282,  1264,   229,   118,   537,  1130,   229,
     575,   170,  1128,    97,   229,   229,   396,    -1,    -1,   481,
      -1,    -1,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   377,   229,   229,   229,   233,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   225,    -1,   229,   232,   232,   229,   229,   229,   229,
     229,   229,    -1,   406,    -1,   229,   229,   234,   234,   234,
     232,   229,   229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   241,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   236,     0,     1,     4,    16,    19,    20,    29,    41,
      44,    45,    63,    66,    77,    97,    98,   115,   132,   145,
     146,   169,   182,   187,   192,   195,   237,   242,   247,   267,
     273,   279,   287,   301,   322,   346,   360,   375,   382,   386,
     396,   405,   426,   432,   438,   442,   448,   504,   521,   229,
     230,   231,   231,   323,   406,   433,   231,   443,   231,   361,
     427,   347,   231,   274,   302,   376,   231,   231,   397,   231,
     280,   231,   387,     1,    30,    38,    99,   268,   269,   270,
     271,   272,     1,    24,    25,    27,    28,    33,    60,    61,
      72,    73,    74,    80,    81,   105,   106,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   231,   231,   231,     1,    62,   439,   440,
     441,   231,     1,     6,     7,     9,    10,    14,    22,    23,
      32,    35,    36,    37,    42,    46,    58,    59,    67,    70,
      71,    79,    86,    88,    90,    92,    94,    95,   107,   112,
     113,   114,   116,   117,   118,   121,   147,   157,   158,   159,
     160,   161,   162,   163,   213,   214,   215,   217,   218,   226,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   497,   501,   502,   503,   231,
     231,   231,     1,    96,   120,   243,   244,   245,   246,   231,
     231,   231,     1,    34,    43,    47,    48,    52,    53,    54,
      76,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,     1,    26,    30,    56,    65,    87,    91,    99,   102,
     103,   134,   151,   154,   155,   156,   201,   224,   225,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   231,     1,
     222,   288,   289,   290,   291,   292,   231,     1,    99,   383,
     384,   385,   231,   229,   232,   232,   232,   230,   269,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   506,     1,    17,    18,    21,    64,
      81,    82,    83,    84,    85,    89,    93,    99,   110,   111,
     122,   144,   188,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,     1,     3,     5,    19,    39,    55,    57,    64,
      75,    99,   123,   143,   152,   201,   224,   407,   408,   409,
     410,   411,   412,   413,   414,   415,   416,   417,   421,   422,
     423,   424,   425,     1,    62,   126,   434,   435,   436,   437,
     232,   230,   440,     1,    99,   126,   444,   445,   446,   447,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   498,   232,   494,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   450,     1,
      19,    39,    64,   119,   127,   128,   148,   223,   362,   363,
     364,   365,   366,   367,   368,   372,   373,   374,     1,   126,
     223,   428,   429,   430,   431,     1,    55,    62,    64,   123,
     348,   352,   353,   354,   358,   359,   229,   232,   232,   230,
     244,     1,    78,   175,   275,   276,   277,   278,     1,    19,
      39,    64,    99,   119,   135,   152,   153,   203,   223,   227,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   318,     1,    41,    78,   126,   377,   378,   379,
     380,   381,   232,   232,   232,   232,   232,   232,   232,   232,
     230,   523,   229,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     230,   249,     1,    99,   220,   398,   399,   400,   401,   229,
     232,   230,   289,   175,     1,    99,   168,   186,   202,   281,
     282,   283,   284,   285,   286,   232,   230,   384,     1,    99,
     220,   223,   388,   389,   390,   391,   392,   124,   124,   124,
     229,   109,   109,   239,   109,   109,   212,   109,   239,   109,
     239,   239,   109,   109,   212,   212,   229,   229,   232,   232,
     232,   343,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   230,   325,   229,   232,   232,
     232,   232,   232,   232,   418,   232,   232,   232,   232,   232,
     232,   232,   230,   408,   232,   232,   230,   435,   124,   229,
     232,   232,   230,   445,   212,   239,   109,   239,   239,   212,
     109,   212,   109,   109,   109,   212,   109,   212,   212,   239,
     109,   109,   109,   109,   239,   109,   109,   109,   109,   212,
     232,   212,   232,   212,   239,   239,   212,   212,   212,   212,
     216,   212,   216,   212,   212,   212,   212,   109,   239,   212,
     239,   239,   212,   229,   229,   232,   232,   369,   232,   232,
     232,   232,   232,   230,   363,   232,   232,   230,   429,   229,
     232,   232,   349,   232,   230,   353,   124,   124,   229,   229,
     232,   232,   230,   276,   229,   232,   232,   319,   232,   232,
     232,   232,   232,   315,   232,   232,   230,   304,   229,   232,
     232,   232,   230,   378,   212,   212,   212,   124,   212,   212,
     212,   239,   229,   109,   124,   212,   124,   109,   109,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   124,
     229,   229,   232,   402,   230,   399,   212,   229,   231,   229,
     232,   232,   232,   232,   230,   282,   124,   229,   229,   232,
     393,   232,   230,   389,   229,   229,   229,   229,   136,   137,
     138,   139,   140,   141,   142,   238,   239,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     109,   109,   239,   232,   109,   109,   109,   239,   109,   109,
     239,   124,   109,   109,   239,   109,   241,   241,   229,   124,
     179,   180,   124,   212,   124,   124,   232,   124,   124,   109,
     124,   124,   124,   124,   229,   124,   124,   229,   229,   124,
     124,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,    47,   165,
     166,   167,   170,   171,   173,   174,   176,   178,   181,   183,
     184,   189,   193,   197,   198,   199,   204,   209,   499,   500,
     229,    47,    49,    50,   165,   166,   167,   170,   171,   173,
     174,   176,   178,   181,   183,   184,   189,   193,   197,   198,
     199,   204,   209,   495,   496,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   124,   212,   232,   124,   109,
     124,   124,   124,   229,   124,   124,   229,   124,   124,   232,
     109,   356,   357,   229,   229,   229,   124,   124,   229,   124,
     212,   232,   124,   124,   124,   124,   212,   232,   124,   124,
     229,   124,   124,   124,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     124,   232,   229,   229,     1,    99,   196,   220,   293,   294,
     295,   296,   297,   124,   124,   124,   124,   229,   229,   124,
     232,   124,   229,   238,   238,   238,   238,   238,   238,   238,
     229,   229,   229,    51,   125,   344,   345,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,    11,    12,
      13,   240,   241,   229,   229,   229,   229,   229,   229,   229,
     229,   229,     8,   200,   419,   420,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   233,   229,
     233,   229,   229,    15,    40,    69,   100,   101,   108,   133,
     149,   211,   370,   371,   229,   229,   229,   229,   229,   229,
     229,   229,   229,    47,   191,   200,   350,   351,   219,   233,
     355,   229,   229,   229,   229,     4,    20,    31,    66,    68,
      96,   129,   131,   150,   172,   177,   181,   185,   190,   194,
     205,   208,   210,   221,   228,   320,   321,   229,   229,   229,
     229,   229,    47,    49,    50,   165,   166,   167,   170,   171,
     173,   174,   176,   178,   181,   183,   184,   189,   193,   197,
     198,   199,   204,   209,   316,   317,   229,   229,   229,   229,
     229,   229,    68,   132,   164,   172,   181,   205,   207,   208,
     221,   228,   403,   404,   229,   232,   232,   298,   230,   294,
     229,   229,   229,   229,   229,    68,   132,   164,   172,   181,
     205,   207,   208,   221,   228,   394,   395,   229,   229,   233,
     240,   240,   240,   229,   233,   500,   496,   229,   233,   229,
     233,   109,   357,   229,   234,   234,   234,   229,   233,   229,
     233,   229,   233,   124,   206,   241,   232,   229,   229,   233,
     345,   420,   371,   351,   130,   130,   130,   321,   317,   404,
     229,   229,   229,    66,    68,   115,   132,   171,   172,   223,
     228,   299,   300,   395,   229,   233,   300
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
     371,   371,   371,   371,   371,   371,   371,   371,   372,   373,
     374,   376,   375,   377,   377,   378,   378,   378,   378,   379,
     380,   381,   382,   383,   383,   384,   384,   385,   387,   386,
     388,   388,   389,   389,   389,   389,   390,   391,   393,   392,
     394,   394,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   397,   396,   398,   398,   399,   399,   399,   400,
     402,   401,   403,   403,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   406,   405,   407,   407,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   416,   418,   417,   419,   419,   420,   420,   421,   422,
     423,   424,   425,   427,   426,   428,   428,   429,   429,   429,
     430,   431,   433,   432,   434,   434,   435,   435,   435,   436,
     437,   438,   439,   439,   440,   440,   441,   443,   442,   444,
     444,   445,   445,   445,   446,   447,   448,   449,   449,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   478,   479,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   494,   493,   495,   495,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   498,   497,   499,
     499,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   501,   502,   503,   504,   505,   505,   506,   506,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   506,
     506,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   522,   523,
     523,   523,   523,   523,   523,   523,   523,   523,   524,   525,
     526,   527,   528,   529,   530,   531
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
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
        case 28:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2890 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 422 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2914 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 429 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 430 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 444 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2953 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 450 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2962 "conf_parser.c" /* yacc.c:1646  */
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
#line 3005 "conf_parser.c" /* yacc.c:1646  */
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
#line 3066 "conf_parser.c" /* yacc.c:1646  */
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
#line 3098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 607 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3109 "conf_parser.c" /* yacc.c:1646  */
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
#line 3126 "conf_parser.c" /* yacc.c:1646  */
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
#line 3157 "conf_parser.c" /* yacc.c:1646  */
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
#line 3175 "conf_parser.c" /* yacc.c:1646  */
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
#line 3193 "conf_parser.c" /* yacc.c:1646  */
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
#line 3206 "conf_parser.c" /* yacc.c:1646  */
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
#line 3223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3235 "conf_parser.c" /* yacc.c:1646  */
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
#line 3266 "conf_parser.c" /* yacc.c:1646  */
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
#line 3297 "conf_parser.c" /* yacc.c:1646  */
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
#line 3325 "conf_parser.c" /* yacc.c:1646  */
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
#line 3350 "conf_parser.c" /* yacc.c:1646  */
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
#line 3375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 845 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 862 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 892 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3429 "conf_parser.c" /* yacc.c:1646  */
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
#line 3446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 913 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 928 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3473 "conf_parser.c" /* yacc.c:1646  */
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
#line 3491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 950 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3500 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 956 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 962 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3518 "conf_parser.c" /* yacc.c:1646  */
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
#line 3539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 995 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1001 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3557 "conf_parser.c" /* yacc.c:1646  */
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
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1032 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1048 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1060 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1068 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3669 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1072 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3690 "conf_parser.c" /* yacc.c:1646  */
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
#line 3775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1185 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1191 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1197 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1203 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3811 "conf_parser.c" /* yacc.c:1646  */
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
#line 3825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3834 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1226 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3843 "conf_parser.c" /* yacc.c:1646  */
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
#line 3857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 4001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1312 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1346 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1381 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1389 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1433 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1437 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4289 "conf_parser.c" /* yacc.c:1646  */
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
#line 4306 "conf_parser.c" /* yacc.c:1646  */
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
#line 4359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4449 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4477 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4587 "conf_parser.c" /* yacc.c:1646  */
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
#line 4605 "conf_parser.c" /* yacc.c:1646  */
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
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4652 "conf_parser.c" /* yacc.c:1646  */
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
#line 4693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4711 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4720 "conf_parser.c" /* yacc.c:1646  */
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
#line 4734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4761 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1861 "conf_parser.y" /* yacc.c:1646  */
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
#line 4841 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1875 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1884 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1897 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 339:
#line 1915 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1921 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1927 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1942 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1957 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
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
#line 4963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 356:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1991 "conf_parser.y" /* yacc.c:1646  */
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
#line 4994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 2010 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2071 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2086 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2092 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5185 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5194 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2144 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2153 "conf_parser.y" /* yacc.c:1646  */
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
#line 5310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 413:
#line 2233 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2251 "conf_parser.y" /* yacc.c:1646  */
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
#line 5353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2264 "conf_parser.y" /* yacc.c:1646  */
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
#line 5369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5378 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2299 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2344 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
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
#line 5520 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2388 "conf_parser.y" /* yacc.c:1646  */
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
#line 5543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5561 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
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
#line 5587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2453 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2467 "conf_parser.y" /* yacc.c:1646  */
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
#line 5622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2484 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2488 "conf_parser.y" /* yacc.c:1646  */
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
#line 5653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2516 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5695 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5704 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5720 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5736 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5744 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5752 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5760 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (((yyvsp[-1].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
#line 5839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2697 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2702 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2707 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2725 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2730 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 5983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2778 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2889 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2904 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2937 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2940 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 640:
#line 3024 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
#line 6479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 641:
#line 3029 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
#line 6487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 642:
#line 3034 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
#line 6495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 643:
#line 3039 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 644:
#line 3044 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 645:
#line 3049 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3077 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 660:
#line 3083 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 661:
#line 3089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 662:
#line 3095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 663:
#line 3104 "conf_parser.y" /* yacc.c:1646  */
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
#line 6585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 664:
#line 3119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 665:
#line 3125 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6603 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6607 "conf_parser.c" /* yacc.c:1646  */
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
