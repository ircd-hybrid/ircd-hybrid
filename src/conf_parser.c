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
#include "id.h"
#include "log.h"
#include "client.h"	/* for UMODE_SERVNOTICE only */
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


#line 191 "conf_parser.c" /* yacc.c:339  */

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
    CLOSE = 275,
    CONNECT = 276,
    CONNECTFREQ = 277,
    CYCLE_ON_HOST_CHANGE = 278,
    DEFAULT_FLOODCOUNT = 279,
    DEFAULT_JOIN_FLOOD_COUNT = 280,
    DEFAULT_JOIN_FLOOD_TIME = 281,
    DEFAULT_MAX_CLIENTS = 282,
    DENY = 283,
    DESCRIPTION = 284,
    DIE = 285,
    DISABLE_AUTH = 286,
    DISABLE_FAKE_CHANNELS = 287,
    DISABLE_REMOTE_COMMANDS = 288,
    DLINE_MIN_CIDR = 289,
    DLINE_MIN_CIDR6 = 290,
    DOTS_IN_IDENT = 291,
    EMAIL = 292,
    ENCRYPTED = 293,
    EXCEED_LIMIT = 294,
    EXEMPT = 295,
    FAILED_OPER_NOTICE = 296,
    FLATTEN_LINKS = 297,
    FLATTEN_LINKS_DELAY = 298,
    FLATTEN_LINKS_FILE = 299,
    GECOS = 300,
    GENERAL = 301,
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
    JOIN = 321,
    KILL = 322,
    KILL_CHASE_TIME_LIMIT = 323,
    KLINE = 324,
    KLINE_EXEMPT = 325,
    KLINE_MIN_CIDR = 326,
    KLINE_MIN_CIDR6 = 327,
    KNOCK_CLIENT_COUNT = 328,
    KNOCK_CLIENT_TIME = 329,
    KNOCK_DELAY_CHANNEL = 330,
    LEAF_MASK = 331,
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
    NO_OPER_FLOOD = 360,
    NO_TILDE = 361,
    NUMBER = 362,
    NUMBER_PER_CIDR = 363,
    NUMBER_PER_IP = 364,
    OPER_ONLY_UMODES = 365,
    OPER_UMODES = 366,
    OPERATOR = 367,
    OPERS_BYPASS_CALLERID = 368,
    PACE_WAIT = 369,
    PACE_WAIT_SIMPLE = 370,
    PASSWORD = 371,
    PATH = 372,
    PING_COOKIE = 373,
    PING_TIME = 374,
    PORT = 375,
    QSTRING = 376,
    RANDOM_IDLE = 377,
    REASON = 378,
    REDIRPORT = 379,
    REDIRSERV = 380,
    REHASH = 381,
    REMOTE = 382,
    REMOTEBAN = 383,
    RESV = 384,
    RESV_EXEMPT = 385,
    RSA_PRIVATE_KEY_FILE = 386,
    SECONDS = 387,
    MINUTES = 388,
    HOURS = 389,
    DAYS = 390,
    WEEKS = 391,
    MONTHS = 392,
    YEARS = 393,
    SEND_PASSWORD = 394,
    SENDQ = 395,
    SERVERHIDE = 396,
    SERVERINFO = 397,
    SHORT_MOTD = 398,
    SPOOF = 399,
    SPOOF_NOTICE = 400,
    SQUIT = 401,
    SSL_CERTIFICATE_FILE = 402,
    SSL_CERTIFICATE_FINGERPRINT = 403,
    SSL_CONNECTION_REQUIRED = 404,
    SSL_DH_ELLIPTIC_CURVE = 405,
    SSL_DH_PARAM_FILE = 406,
    SSL_MESSAGE_DIGEST_ALGORITHM = 407,
    STATS_E_DISABLED = 408,
    STATS_I_OPER_ONLY = 409,
    STATS_K_OPER_ONLY = 410,
    STATS_M_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BOTS = 416,
    T_CALLERID = 417,
    T_CCONN = 418,
    T_COMMAND = 419,
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
    T_NCHANGE = 434,
    T_NONONREG = 435,
    T_OPME = 436,
    T_PREPEND = 437,
    T_PSEUDO = 438,
    T_RECVQ = 439,
    T_REJ = 440,
    T_RESTART = 441,
    T_SERVER = 442,
    T_SERVICE = 443,
    T_SERVNOTICE = 444,
    T_SET = 445,
    T_SHARED = 446,
    T_SIZE = 447,
    T_SKILL = 448,
    T_SOFTCALLERID = 449,
    T_SPY = 450,
    T_SSL = 451,
    T_SSL_CIPHER_LIST = 452,
    T_TARGET = 453,
    T_UMODES = 454,
    T_UNAUTH = 455,
    T_UNDLINE = 456,
    T_UNLIMITED = 457,
    T_UNRESV = 458,
    T_UNXLINE = 459,
    T_WALLOP = 460,
    T_WALLOPS = 461,
    T_WEBIRC = 462,
    TBOOL = 463,
    THROTTLE_COUNT = 464,
    THROTTLE_TIME = 465,
    TKLINE_EXPIRE_NOTICES = 466,
    TMASKED = 467,
    TS_MAX_DELTA = 468,
    TS_WARN_DELTA = 469,
    TWODOTS = 470,
    TYPE = 471,
    UNKLINE = 472,
    USE_LOGGING = 473,
    USER = 474,
    VHOST = 475,
    VHOST6 = 476,
    WARN_NO_CONNECT_BLOCK = 477,
    WHOIS = 478,
    XLINE = 479,
    XLINE_EXEMPT = 480
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
#define CLOSE 275
#define CONNECT 276
#define CONNECTFREQ 277
#define CYCLE_ON_HOST_CHANGE 278
#define DEFAULT_FLOODCOUNT 279
#define DEFAULT_JOIN_FLOOD_COUNT 280
#define DEFAULT_JOIN_FLOOD_TIME 281
#define DEFAULT_MAX_CLIENTS 282
#define DENY 283
#define DESCRIPTION 284
#define DIE 285
#define DISABLE_AUTH 286
#define DISABLE_FAKE_CHANNELS 287
#define DISABLE_REMOTE_COMMANDS 288
#define DLINE_MIN_CIDR 289
#define DLINE_MIN_CIDR6 290
#define DOTS_IN_IDENT 291
#define EMAIL 292
#define ENCRYPTED 293
#define EXCEED_LIMIT 294
#define EXEMPT 295
#define FAILED_OPER_NOTICE 296
#define FLATTEN_LINKS 297
#define FLATTEN_LINKS_DELAY 298
#define FLATTEN_LINKS_FILE 299
#define GECOS 300
#define GENERAL 301
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
#define JOIN 321
#define KILL 322
#define KILL_CHASE_TIME_LIMIT 323
#define KLINE 324
#define KLINE_EXEMPT 325
#define KLINE_MIN_CIDR 326
#define KLINE_MIN_CIDR6 327
#define KNOCK_CLIENT_COUNT 328
#define KNOCK_CLIENT_TIME 329
#define KNOCK_DELAY_CHANNEL 330
#define LEAF_MASK 331
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
#define NO_OPER_FLOOD 360
#define NO_TILDE 361
#define NUMBER 362
#define NUMBER_PER_CIDR 363
#define NUMBER_PER_IP 364
#define OPER_ONLY_UMODES 365
#define OPER_UMODES 366
#define OPERATOR 367
#define OPERS_BYPASS_CALLERID 368
#define PACE_WAIT 369
#define PACE_WAIT_SIMPLE 370
#define PASSWORD 371
#define PATH 372
#define PING_COOKIE 373
#define PING_TIME 374
#define PORT 375
#define QSTRING 376
#define RANDOM_IDLE 377
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RESV 384
#define RESV_EXEMPT 385
#define RSA_PRIVATE_KEY_FILE 386
#define SECONDS 387
#define MINUTES 388
#define HOURS 389
#define DAYS 390
#define WEEKS 391
#define MONTHS 392
#define YEARS 393
#define SEND_PASSWORD 394
#define SENDQ 395
#define SERVERHIDE 396
#define SERVERINFO 397
#define SHORT_MOTD 398
#define SPOOF 399
#define SPOOF_NOTICE 400
#define SQUIT 401
#define SSL_CERTIFICATE_FILE 402
#define SSL_CERTIFICATE_FINGERPRINT 403
#define SSL_CONNECTION_REQUIRED 404
#define SSL_DH_ELLIPTIC_CURVE 405
#define SSL_DH_PARAM_FILE 406
#define SSL_MESSAGE_DIGEST_ALGORITHM 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_M_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BOTS 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_COMMAND 419
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
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPME 436
#define T_PREPEND 437
#define T_PSEUDO 438
#define T_RECVQ 439
#define T_REJ 440
#define T_RESTART 441
#define T_SERVER 442
#define T_SERVICE 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_SKILL 448
#define T_SOFTCALLERID 449
#define T_SPY 450
#define T_SSL 451
#define T_SSL_CIPHER_LIST 452
#define T_TARGET 453
#define T_UMODES 454
#define T_UNAUTH 455
#define T_UNDLINE 456
#define T_UNLIMITED 457
#define T_UNRESV 458
#define T_UNXLINE 459
#define T_WALLOP 460
#define T_WALLOPS 461
#define T_WEBIRC 462
#define TBOOL 463
#define THROTTLE_COUNT 464
#define THROTTLE_TIME 465
#define TKLINE_EXPIRE_NOTICES 466
#define TMASKED 467
#define TS_MAX_DELTA 468
#define TS_WARN_DELTA 469
#define TWODOTS 470
#define TYPE 471
#define UNKLINE 472
#define USE_LOGGING 473
#define USER 474
#define VHOST 475
#define VHOST6 476
#define WARN_NO_CONNECT_BLOCK 477
#define WHOIS 478
#define XLINE 479
#define XLINE_EXEMPT 480

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 686 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 703 "conf_parser.c" /* yacc.c:358  */

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
#define YYLAST   1245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  659
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1297

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   480

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
       2,     2,     2,     2,   230,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   231,   226,
       2,   229,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   228,     2,   227,     2,     2,     2,     2,
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
     225
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   382,   382,   383,   386,   387,   388,   389,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   413,   413,
     414,   415,   416,   417,   418,   419,   420,   421,   424,   424,
     425,   426,   427,   428,   435,   438,   438,   439,   439,   439,
     441,   447,   454,   456,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   477,   517,   575,   604,   612,   626,   654,
     669,   684,   694,   708,   717,   745,   773,   798,   820,   842,
     851,   853,   853,   854,   855,   856,   857,   859,   868,   877,
     890,   889,   907,   907,   908,   908,   908,   910,   916,   926,
     925,   944,   944,   945,   945,   945,   945,   945,   947,   953,
     959,   965,   986,   987,   987,   989,   989,   990,   992,   999,
     999,  1012,  1013,  1015,  1015,  1016,  1016,  1018,  1026,  1029,
    1035,  1034,  1040,  1040,  1041,  1045,  1049,  1053,  1057,  1061,
    1065,  1069,  1080,  1079,  1141,  1141,  1142,  1143,  1144,  1145,
    1146,  1147,  1148,  1149,  1150,  1151,  1152,  1154,  1160,  1166,
    1172,  1178,  1189,  1195,  1206,  1213,  1212,  1218,  1218,  1219,
    1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,  1255,  1259,
    1263,  1267,  1271,  1275,  1279,  1283,  1287,  1291,  1295,  1299,
    1303,  1310,  1309,  1315,  1315,  1316,  1320,  1324,  1328,  1332,
    1336,  1340,  1344,  1348,  1352,  1356,  1360,  1364,  1368,  1372,
    1376,  1380,  1384,  1388,  1392,  1396,  1400,  1404,  1408,  1412,
    1416,  1420,  1424,  1435,  1434,  1491,  1491,  1492,  1493,  1494,
    1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,  1504,
    1504,  1505,  1506,  1507,  1508,  1510,  1516,  1522,  1528,  1534,
    1540,  1546,  1552,  1558,  1564,  1570,  1577,  1583,  1589,  1595,
    1604,  1614,  1613,  1619,  1619,  1620,  1624,  1635,  1634,  1641,
    1640,  1645,  1645,  1646,  1650,  1654,  1660,  1660,  1661,  1661,
    1661,  1661,  1661,  1663,  1663,  1665,  1665,  1667,  1680,  1697,
    1703,  1713,  1712,  1754,  1754,  1755,  1756,  1757,  1758,  1759,
    1760,  1761,  1762,  1763,  1765,  1771,  1777,  1783,  1795,  1794,
    1800,  1800,  1801,  1805,  1809,  1813,  1817,  1821,  1825,  1829,
    1833,  1837,  1843,  1857,  1866,  1880,  1879,  1894,  1894,  1895,
    1895,  1895,  1895,  1897,  1903,  1909,  1919,  1921,  1921,  1922,
    1922,  1924,  1940,  1939,  1964,  1964,  1965,  1965,  1965,  1965,
    1967,  1973,  1993,  1992,  1998,  1998,  1999,  2003,  2007,  2011,
    2015,  2019,  2023,  2027,  2031,  2035,  2045,  2044,  2065,  2065,
    2066,  2066,  2066,  2068,  2075,  2074,  2080,  2080,  2081,  2085,
    2089,  2093,  2097,  2101,  2105,  2109,  2113,  2117,  2127,  2126,
    2198,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,  2206,
    2207,  2208,  2209,  2210,  2211,  2212,  2213,  2215,  2221,  2227,
    2233,  2246,  2259,  2265,  2271,  2275,  2282,  2281,  2286,  2286,
    2287,  2291,  2297,  2308,  2314,  2320,  2326,  2342,  2341,  2367,
    2367,  2368,  2368,  2368,  2370,  2390,  2400,  2399,  2426,  2426,
    2427,  2427,  2427,  2429,  2435,  2444,  2446,  2446,  2447,  2447,
    2449,  2467,  2466,  2489,  2489,  2490,  2490,  2490,  2492,  2498,
    2507,  2510,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,
    2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,
    2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2559,
    2564,  2569,  2574,  2580,  2585,  2590,  2595,  2600,  2605,  2610,
    2615,  2620,  2625,  2630,  2635,  2640,  2645,  2650,  2656,  2661,
    2666,  2671,  2676,  2681,  2686,  2691,  2694,  2699,  2702,  2707,
    2712,  2717,  2722,  2727,  2732,  2737,  2742,  2747,  2752,  2757,
    2762,  2768,  2767,  2772,  2772,  2773,  2776,  2779,  2782,  2785,
    2788,  2791,  2794,  2797,  2800,  2803,  2806,  2809,  2812,  2815,
    2818,  2821,  2824,  2827,  2830,  2833,  2836,  2842,  2841,  2846,
    2846,  2847,  2850,  2853,  2856,  2859,  2862,  2865,  2868,  2871,
    2874,  2877,  2880,  2883,  2886,  2889,  2892,  2895,  2898,  2901,
    2904,  2909,  2914,  2919,  2928,  2931,  2931,  2932,  2933,  2934,
    2935,  2936,  2937,  2938,  2939,  2940,  2941,  2942,  2944,  2949,
    2954,  2959,  2964,  2969,  2974,  2979,  2984,  2989,  2997,  3000,
    3000,  3001,  3002,  3003,  3004,  3005,  3006,  3007,  3008,  3009,
    3010,  3012,  3018,  3034,  3043,  3049,  3055,  3061,  3070,  3076
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
  "CLOSE", "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE",
  "DEFAULT_FLOODCOUNT", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION",
  "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6",
  "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT",
  "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE",
  "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
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
  "oper_encrypted", "oper_ssl_certificate_fingerprint",
  "oper_ssl_connection_required", "oper_class", "oper_umodes", "$@6",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@7",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@8",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_channels",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
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
  "general_short_motd", "general_no_oper_flood", "general_dots_in_ident",
  "general_max_targets", "general_ping_cookie", "general_disable_auth",
  "general_throttle_count", "general_throttle_time", "general_oper_umodes",
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_bans",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_flatten_links_delay",
  "serverhide_flatten_links_file", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_hidden",
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
     475,   476,   477,   478,   479,   480,    59,   125,   123,    61,
      44,    58
};
# endif

#define YYPACT_NINF -776

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-776)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -776,   698,  -776,  -197,  -209,  -193,  -776,  -776,  -776,  -168,
    -776,  -156,  -776,  -776,  -776,  -149,  -776,  -776,  -776,  -143,
    -133,  -776,  -128,  -776,  -109,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,   359,   773,  -104,   -78,   -72,    12,   -67,   441,   -65,
     -51,   -50,    27,   -44,   -25,   -24,   688,   536,   -20,    89,
     -19,    19,   -10,  -188,  -124,   -35,    -7,     5,  -776,  -776,
    -776,  -776,  -776,    -4,    21,    24,    33,    44,    49,    58,
      74,    75,    77,   288,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,   733,   640,    46,  -776,    79,
      14,  -776,  -776,    96,  -776,    83,    93,   104,   105,   111,
     112,   114,   115,   117,   118,   129,   130,   136,   137,   138,
     143,   145,   146,   147,   148,   149,   151,   152,   154,   155,
    -776,  -776,   156,   157,   160,   162,   166,   168,   169,   170,
     176,   177,   179,   183,   184,   188,   196,   206,   207,   209,
      57,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,   363,    30,   290,
      -2,   212,   215,    17,  -776,  -776,  -776,    11,   291,    43,
    -776,   217,   220,   223,   227,   228,   230,   231,   232,   233,
     284,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,    92,   234,   237,   238,   239,   240,   241,   242,   244,
     245,   252,   254,   255,   256,   260,   262,   265,   266,    55,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,    61,   178,
     269,     3,  -776,  -776,  -776,    85,   175,  -776,   272,    15,
    -776,  -776,    10,  -776,   294,   382,   383,   185,  -776,   398,
     401,   308,   411,   401,   412,   401,   401,   414,   415,   297,
    -776,   298,   299,   301,   303,  -776,   310,   311,   312,   318,
     319,   321,   324,   333,   335,   337,   338,   339,   341,   216,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,   345,   344,
     346,   347,   349,   350,   354,  -776,   356,   360,   362,   374,
     377,   378,   379,   182,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
     380,   385,    16,  -776,  -776,  -776,   490,   389,  -776,  -776,
     387,   390,    36,  -776,  -776,  -776,   410,   401,   513,   401,
     401,   413,   517,   417,   521,   522,   523,   423,   426,   428,
     401,   530,   533,   535,   539,   401,   540,   541,   549,   551,
     452,   432,   435,   457,   401,   401,   460,   461,   462,  -187,
    -186,   463,   464,   465,   466,   568,   401,   468,   401,   401,
     473,   458,  -776,   459,   467,   472,  -776,   474,   477,   478,
     479,   480,   226,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,   481,   482,    42,  -776,  -776,  -776,   489,
     484,   491,  -776,   493,  -776,    13,  -776,  -776,  -776,  -776,
    -776,   569,   570,   492,  -776,   497,   495,   496,     8,  -776,
    -776,  -776,   501,   499,   500,  -776,   508,   516,   518,   519,
    -776,   520,   524,    32,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,   526,   525,   529,   534,     9,
    -776,  -776,  -776,  -776,   538,   554,   401,   571,   556,   584,
     558,   559,   561,   546,  -776,  -776,   652,   655,   565,   656,
     671,   673,   660,   661,   662,   663,   664,   665,   666,   668,
     669,   670,   672,   566,  -776,   574,   572,  -776,   187,  -776,
    -776,  -776,  -776,   586,   576,  -776,   575,   578,   577,   579,
     590,   591,   189,  -776,  -776,  -776,  -776,  -776,   686,   587,
    -776,   595,   594,  -776,   596,    38,  -776,  -776,  -776,  -776,
     598,   602,   603,  -776,   604,   286,   605,   609,   610,   612,
     617,   618,   619,   624,   625,  -776,  -776,   748,   749,   401,
     628,   751,   752,   754,   401,   755,   757,   401,   744,   759,
     760,   401,   761,   761,   643,  -776,  -776,   750,  -122,   753,
     667,   756,   758,   641,   764,   771,   765,   775,   776,   778,
     781,   654,  -776,   782,   783,   679,  -776,   681,  -776,   787,
     788,   685,  -776,   687,   692,   693,   694,   696,   701,   704,
     707,   709,   711,   712,   714,   717,   718,   719,   720,   722,
     723,   724,   726,   727,   728,   732,   734,   735,   802,   721,
     740,   747,   763,   766,   767,   768,   772,   774,   777,   779,
     780,   784,   785,   786,   789,   790,   791,   792,   793,   794,
    -776,  -776,   838,   769,   649,   849,   805,   854,   857,   859,
     795,  -776,   862,   863,   796,  -776,  -776,   864,   865,   770,
     881,   797,  -776,   798,   799,  -776,  -776,   869,   880,   800,
    -776,  -776,   883,   801,   803,   887,   892,   893,   819,   804,
     907,   908,   808,  -776,  -776,   909,   910,   914,   810,  -776,
     811,   812,   813,   814,   815,   816,   817,   818,   820,  -776,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   832,   833,   834,   835,   836,   837,  -776,  -776,   924,
     839,   840,  -776,   841,  -776,    31,  -776,   943,   944,   948,
     949,   845,  -776,   846,  -776,  -776,   952,   847,   953,   851,
    -776,  -776,  -776,  -776,  -776,   401,   401,   401,   401,   401,
     401,   401,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,   852,   853,   855,   -28,   856,   858,   860,
     861,   866,   867,   868,   870,   871,   872,   873,   186,   874,
     875,  -776,   876,   877,   878,   879,   882,   884,   885,    -5,
     886,   888,   889,   890,   891,   894,   895,  -776,   896,   897,
    -776,  -776,   898,   899,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -190,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -185,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,   900,   901,   487,   902,
     903,   904,   905,   906,  -776,   911,   912,  -776,   913,   915,
     -23,   918,   850,  -776,  -776,  -776,  -776,   916,   917,  -776,
     919,   920,   476,   921,   922,   923,   925,   762,   926,   927,
    -776,   928,   929,   930,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,   931,   357,  -776,  -776,   932,   933,   934,  -776,    56,
    -776,  -776,  -776,  -776,   935,   938,   939,   940,  -776,  -776,
     941,   409,   942,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -180,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,   761,
     761,   761,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -178,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,   802,
    -776,   721,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -171,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -165,  -776,
     968,   881,   945,  -776,  -776,  -776,  -776,  -776,  -776,   946,
    -776,   947,   950,  -776,  -776,   951,  -776,  -776,  -776,   954,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -157,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -123,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -120,  -776,
    -776,   962,   -80,   955,   957,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,   -37,  -776,  -776,  -776,   -28,  -776,  -776,  -776,  -776,
      -5,  -776,  -776,  -776,   487,  -776,   -23,  -776,  -776,  -776,
     958,   959,   963,   960,   964,  -776,   476,  -776,   762,  -776,
     357,   961,   965,   966,   325,  -776,  -776,   409,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,   -34,  -776,  -776,  -776,   325,  -776
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   233,   398,   446,     0,
     461,     0,   301,   437,   277,     0,   100,   152,   335,     0,
       0,   376,     0,   109,     0,   352,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   627,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   626,   618,   619,   620,   621,
     622,   623,   617,   624,   625,     0,     0,     0,   459,     0,
       0,   457,   458,     0,   518,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     587,   561,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   472,   473,   474,   516,   517,   511,   512,   513,   514,
     510,   484,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   485,   486,   515,   490,   491,   492,   493,   489,   488,
     494,   501,   502,   495,   496,   497,   487,   499,   508,   509,
     506,   507,   500,   498,   504,   505,   503,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   640,   641,   642,   643,   644,   645,   646,   648,   647,
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    69,    66,    64,    70,    71,    65,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   124,   125,   126,     0,     0,   350,     0,     0,
     348,   349,     0,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,     0,     0,     0,     0,   271,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,   240,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   238,   239,   241,   251,   252,   253,     0,     0,
       0,     0,     0,     0,     0,   426,     0,     0,     0,     0,
       0,     0,     0,     0,   401,   402,   403,   404,   405,   406,
     407,   409,   408,   411,   415,   412,   413,   414,   410,   452,
       0,     0,     0,   449,   450,   451,     0,     0,   456,   467,
       0,     0,     0,   464,   465,   466,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   471,     0,     0,     0,   318,     0,     0,     0,
       0,     0,     0,   304,   305,   306,   307,   312,   308,   309,
     310,   311,   443,     0,     0,     0,   440,   441,   442,     0,
       0,     0,   279,     0,   289,     0,   287,   288,   290,   291,
      49,     0,     0,     0,    45,     0,     0,     0,     0,   103,
     104,   105,     0,     0,     0,   201,     0,     0,     0,     0,
     175,     0,     0,     0,   155,   156,   157,   158,   159,   162,
     163,   164,   161,   160,   165,     0,     0,     0,     0,     0,
     338,   339,   340,   341,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   639,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   384,     0,   379,
     380,   381,   127,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   115,   114,   116,     0,     0,
     347,     0,     0,   362,     0,     0,   355,   356,   357,   358,
       0,     0,     0,    90,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   614,   254,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   235,   416,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   400,     0,     0,     0,   448,     0,   455,     0,
       0,     0,   463,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,   313,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   303,     0,     0,     0,   439,   292,     0,     0,     0,
       0,     0,   286,     0,     0,    44,   106,     0,     0,     0,
     102,   166,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   342,     0,     0,     0,     0,   337,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   638,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,   382,     0,
       0,     0,   378,     0,   122,     0,   117,     0,     0,     0,
       0,     0,   111,     0,   346,   359,     0,     0,     0,     0,
     354,    99,    98,    97,   636,    28,    28,    28,    28,    28,
      28,    28,    30,    29,   637,   628,   629,   630,   631,   632,
     633,   635,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,   234,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   399,     0,     0,
     447,   460,     0,     0,   462,   531,   535,   519,   520,   550,
     522,   613,   558,   523,   524,   555,   530,   529,   538,   528,
     525,   526,   534,   533,   532,   556,   521,   611,   612,   554,
     597,   591,   607,   592,   593,   594,   602,   610,   595,   604,
     608,   598,   609,   599,   603,   596,   606,   601,   600,   605,
       0,   590,   570,   571,   572,   565,   583,   566,   567,   568,
     578,   586,   569,   580,   584,   574,   585,   575,   579,   573,
     582,   577,   576,   581,     0,   564,   551,   549,   552,   557,
     553,   540,   547,   548,   545,   546,   541,   542,   543,   544,
     559,   560,   527,   537,   536,   539,     0,     0,     0,     0,
       0,     0,     0,     0,   302,     0,     0,   438,     0,     0,
       0,   297,   293,   296,   278,    50,    51,     0,     0,   101,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   336,   654,   651,   652,   653,   658,
     657,   659,   655,   656,    86,    81,    89,    80,    87,    88,
      79,    83,    82,    74,    73,    78,    75,    77,    76,    84,
      85,     0,     0,   377,   128,     0,     0,     0,   140,     0,
     132,   133,   135,   134,     0,     0,     0,     0,   110,   351,
       0,     0,     0,   353,    31,    32,    33,    34,    35,    36,
      37,   266,   267,   258,   276,   275,     0,   274,   259,   261,
     263,   270,   262,   260,   269,   255,   268,   257,   256,    38,
      38,    38,    40,    39,   264,   265,   421,   424,   425,   435,
     432,   418,   433,   430,   431,     0,   429,   434,   417,   423,
     420,   422,   436,   419,   453,   454,   468,   469,   588,     0,
     562,     0,   316,   317,   327,   323,   324,   326,   331,   328,
     329,   322,   330,   325,     0,   321,   315,   334,   333,   332,
     314,   445,   444,   300,   299,   284,   285,   283,     0,   282,
       0,     0,     0,   107,   108,   174,   171,   220,   232,   208,
     217,     0,   206,   211,   226,     0,   219,   224,   230,   210,
     213,   221,   223,   227,   218,   225,   214,   231,   216,   222,
     212,   215,     0,   204,   167,   169,   172,   173,   184,   185,
     186,   179,   197,   180,   181,   182,   192,   200,   183,   194,
     198,   188,   199,   189,   193,   187,   196,   191,   190,   195,
       0,   178,   168,   170,   345,   343,   344,   383,   388,   394,
     397,   390,   396,   391,   395,   393,   389,   392,     0,   387,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     360,   366,   372,   375,   368,   374,   369,   373,   371,   367,
     370,     0,   365,   361,   272,     0,    41,    42,    43,   427,
       0,   589,   563,   319,     0,   280,     0,   298,   295,   294,
       0,     0,     0,     0,     0,   202,     0,   176,     0,   385,
       0,     0,     0,     0,     0,   130,   363,     0,   273,   428,
     320,   281,   207,   229,   205,   228,   209,   203,   177,   386,
     137,   139,   138,   150,   149,   145,   147,   151,   148,   144,
     146,     0,   143,   364,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -776,  -776,  -776,  -377,  -298,  -775,  -622,  -776,  -776,   937,
    -776,  -776,  -776,  -776,   635,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  1018,  -776,  -776,  -776,  -776,  -776,
    -776,   621,  -776,  -776,  -776,  -776,  -776,   547,  -776,  -776,
    -776,  -776,  -776,  -776,   936,  -776,  -776,  -776,  -776,    78,
    -776,  -776,  -776,  -776,  -776,  -189,  -776,  -776,  -776,   615,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -145,  -776,  -776,  -776,  -121,  -776,  -776,  -776,   807,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -101,
    -776,  -776,  -776,  -776,  -776,  -106,  -776,   684,  -776,  -776,
    -776,    29,  -776,  -776,  -776,  -776,  -776,   736,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -100,  -776,  -776,  -776,  -776,
    -776,  -776,   650,  -776,  -776,  -776,  -776,  -776,   956,  -776,
    -776,  -776,  -776,   585,  -776,  -776,  -776,  -776,  -776,   -95,
    -776,  -776,  -776,   616,  -776,  -776,  -776,  -776,   -87,  -776,
    -776,  -776,   842,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,   -64,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,   710,  -776,  -776,  -776,  -776,  -776,   843,
    -776,  -776,  -776,  -776,  1069,  -776,  -776,  -776,  -776,   806,
    -776,  -776,  -776,  -776,  1020,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,    88,  -776,
    -776,  -776,    87,  -776,  -776,  -776,  -776,  -776,  1097,  -776,
    -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776,   967,  -776,  -776,  -776,  -776,  -776,  -776,  -776,  -776,
    -776
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   812,   813,  1072,  1073,    27,   213,   214,
     215,   216,    28,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    29,    77,    78,    79,    80,    81,    30,    63,
     488,   489,   490,   491,    31,    70,   572,   573,   574,   575,
     576,   577,    32,   281,   282,   283,   284,   285,  1029,  1030,
    1031,  1032,  1033,  1213,  1291,  1292,    33,    64,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   739,
    1190,  1191,   514,   734,  1162,  1163,    34,    53,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   610,  1056,  1057,
      35,    61,   474,   719,  1128,  1129,   475,   476,   477,  1132,
     972,   973,   478,   479,    36,    59,   452,   453,   454,   455,
     456,   457,   458,   704,  1114,  1115,   459,   460,   461,    37,
      65,   519,   520,   521,   522,   523,    38,   289,   290,   291,
      39,    72,   585,   586,   587,   588,   589,   797,  1231,  1232,
      40,    68,   558,   559,   560,   561,   780,  1208,  1209,    41,
      54,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   633,  1085,  1086,   374,   375,   376,   377,   378,
      42,    60,   465,   466,   467,   468,    43,    55,   382,   383,
     384,   385,    44,   110,   111,   112,    45,    57,   392,   393,
     394,   395,    46,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   422,   934,   935,   203,
     421,   910,   911,   204,   205,   206,    47,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    48,
     230,   231,   232,   233,   234,   235,   236,   237,   238,   239,
     240
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     839,   840,   596,  1083,   279,   599,    73,   601,   602,   485,
     515,   581,   485,   108,   469,   108,   287,   379,   210,    51,
     287,   686,   688,  1054,  1125,   687,   689,   838,   210,    49,
      50,   462,  1025,   492,    74,    52,  1098,   389,   293,   581,
    1099,  1100,    75,   462,   515,  1101,  1234,   379,  1239,   516,
    1235,   493,  1240,   843,   844,  1243,   241,  1025,   114,  1244,
      56,  1245,   555,   115,   116,  1246,   117,   118,   470,  1255,
     494,   119,    58,  1256,   109,   471,   109,   472,   380,    62,
     120,   121,   242,   516,   243,    66,   486,   517,   122,   486,
     279,   123,   124,   125,  1055,    67,   495,   389,   126,   654,
      69,   656,   657,  1257,    76,   294,  1259,  1258,   380,   582,
    1260,   244,   667,   211,   288,   127,   128,   672,   288,    71,
     245,   517,  1262,   211,   105,   129,   681,   682,   130,   131,
    1026,   496,   518,   473,   212,   390,   132,   582,   695,   381,
     697,   698,   246,   133,   212,   134,   247,   135,   497,   136,
     106,   137,   138,   463,   248,  1026,   107,   249,   250,   391,
     556,   113,   139,   207,  1126,   463,   518,   140,   141,   381,
     142,   143,   144,  1127,  -129,   145,   567,   208,   209,   487,
     498,   499,   487,   348,   217,   349,   251,   350,   555,  1266,
     567,  1084,  1294,  1267,   295,   390,  1295,  1069,  1070,  1071,
     146,   351,   252,   218,   219,   253,   254,   255,   278,   286,
     147,   148,   149,   150,   151,   152,   153,   311,   292,   391,
     352,   280,   296,  1027,   480,   299,   583,   443,   752,   584,
     564,   500,   297,   312,   313,   729,   748,   353,   314,   354,
     721,   387,   579,   645,   483,   444,   355,  1028,  1027,   464,
     300,   501,   256,   301,   583,   502,   566,   584,   356,   742,
    -129,   464,   302,   651,   445,   799,   154,   155,   156,   714,
     157,   158,  1028,   303,   568,   257,   258,   557,   304,   159,
     315,   357,   553,  1214,   441,   220,   556,   305,   568,    82,
     446,   469,   492,   838,  1236,  1237,  1238,   316,   317,   318,
     319,   320,   358,   306,   307,   321,   308,   280,   386,   322,
     493,   825,   396,    83,    84,   323,   830,   221,   535,   833,
      85,   359,   397,   837,   324,   325,   222,   223,   224,   494,
     360,   225,   226,   398,   399,   326,   227,   228,   229,   569,
     400,   401,   447,   402,   403,   470,   404,   405,    86,    87,
     448,   449,   471,   569,   472,   495,   327,   570,   406,   407,
      73,    88,    89,    90,   443,   408,   409,   410,    91,    92,
     450,   570,   411,   571,   412,   413,   414,   415,   416,   361,
     417,   418,   444,   419,   420,   423,   424,   571,    74,   425,
     496,   426,  1283,   595,  1284,   427,    75,   428,   429,   430,
     328,   445,   362,   557,   562,   431,   432,   497,   433,   641,
     473,   593,   434,   435,   781,   590,   791,   436,   805,   806,
     807,   808,   809,   810,   811,   437,  1198,   446,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,   438,   439,  1285,   440,   498,
     499,   481,   114,   624,   482,   451,   524,   115,   116,   525,
     117,   118,   526,   710,  1286,   119,   527,   528,    76,   529,
     530,   531,   532,   536,   120,   121,   537,   538,   539,   540,
     541,   542,   122,   543,   544,   123,   124,   125,  1221,   447,
    1137,   545,   126,   546,   547,   548,  1199,   448,   449,   549,
     500,   550,  1287,  1288,   551,   552,  1138,  1139,   563,   127,
     128,   578,  1104,   591,   592,   594,  1140,   450,   595,   129,
     501,   533,   130,   131,   502,   309,   597,  1200,   598,   600,
     132,   603,   604,   605,   606,  1201,  1105,   133,   607,   134,
     608,   135,   609,   136,  1202,   137,   138,   241,  1222,   611,
     612,   613,  1141,  1142,  1289,  1143,   139,   614,   615,  1290,
     616,   140,   141,   617,   142,   143,   144,  1106,  1203,   145,
    1204,  1205,   618,   242,   619,   243,   620,   621,   622,  1223,
     623,   626,  1144,   627,  1206,   628,   629,  1224,   630,   631,
    1145,  1207,   451,   632,   146,   634,  1225,  1107,  1108,   635,
    1263,   636,   244,  1109,   147,   148,   149,   150,   151,   152,
     153,   245,  1146,   637,  1147,  1148,   638,   639,   640,   643,
    1226,   647,  1227,  1228,   644,   648,   649,  1110,   653,   650,
     655,   658,  1149,   246,   659,   660,  1229,   247,   661,   662,
     663,   664,  1111,  1230,   665,   248,   666,   668,   249,   250,
     669,   348,   670,   349,  1150,   350,   671,   673,   674,  1151,
     154,   155,   156,  1152,   157,   158,   675,  1153,   676,   351,
     677,   678,  1154,   159,   679,   680,  1155,   251,   683,   684,
     685,   690,   691,   692,   693,   694,   696,  1156,   352,  1157,
    1158,   699,  1159,   252,   700,   701,   253,   254,   255,   220,
     723,   724,   753,  1160,  1112,   353,   702,   354,     2,     3,
    1161,   703,     4,   705,   355,   755,   706,   707,   708,   709,
     712,   713,  1113,   717,     5,   716,   356,     6,   725,     7,
     718,   221,   720,   726,   727,   728,     8,   731,   732,   733,
     222,   223,   224,   256,   311,   225,   226,   735,     9,   357,
     227,   228,   229,    10,    11,   736,   750,   737,   738,   740,
     312,   313,   744,   741,   745,   314,   257,   258,   746,   760,
     358,    12,   751,   747,   754,    13,   756,   757,   912,   758,
     913,   914,   759,   762,    82,    14,   761,   763,   764,   359,
     765,   766,   767,   768,   769,   770,   771,   772,   360,   773,
     774,   775,   777,   776,   783,    15,    16,   315,    83,    84,
     778,   779,   784,   785,   786,    85,   787,   793,   788,  1168,
      17,  1169,  1170,   794,   316,   317,   318,   319,   320,   789,
     790,   795,   321,   796,   801,   798,   322,    18,   802,   803,
     804,   814,   323,    86,    87,   815,   816,   361,   817,    19,
      20,   324,   325,   818,   819,   820,    88,    89,    90,   890,
     821,   822,   326,    91,    92,   823,   824,   826,   827,   828,
     362,   829,   831,    21,   832,   834,   835,   836,   838,   841,
     849,   842,   852,   327,   845,   846,    22,   847,   958,   848,
     857,    23,   915,   916,   917,   850,    24,   918,   919,    25,
     920,   921,   851,   922,   554,   923,   853,   854,   924,   855,
     925,   926,   856,   858,   859,   860,   927,   861,   862,   863,
     928,   864,   960,   865,   929,   930,   931,   328,   866,   867,
     868,   932,   869,  1171,  1172,  1173,   933,   870,  1174,  1175,
     871,  1176,  1177,   872,  1178,   873,  1179,   874,   875,  1180,
     876,  1181,  1182,   877,   878,   879,   880,  1183,   881,   882,
     883,  1184,   884,   885,   886,  1185,  1186,  1187,   887,   956,
     888,   889,  1188,   891,   892,   893,   936,  1189,   894,   895,
     959,   896,   897,   937,   898,   961,   899,   957,   962,   900,
     963,   901,   902,   965,   966,   968,   969,   903,   971,   938,
     977,   904,   939,   940,   941,   905,   906,   907,   942,   970,
     943,   978,   908,   944,   980,   945,   946,   909,   983,   981,
     947,   948,   949,   984,   985,   950,   951,   952,   953,   954,
     955,   964,   967,   974,   975,   976,   979,   986,   988,   989,
     991,   992,   982,   987,   990,   993,   994,   995,   996,   997,
     998,   999,  1000,  1001,  1002,  1021,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1034,  1035,  1023,  1024,  1022,  1036,
    1037,  1038,  1039,  1040,  1042,  1247,  1041,  1043,  1051,  1052,
    1131,  1053,  1058,  1261,  1059,  1272,  1060,  1061,  1273,  1275,
    1274,  1276,  1062,  1063,  1064,   298,  1065,  1066,  1067,  1068,
    1074,  1075,  1076,  1077,  1078,  1079,  1296,  1215,  1080,   730,
    1081,  1082,  1087,  1278,  1088,  1089,  1090,  1091,   743,   792,
    1092,  1093,  1094,  1095,  1096,  1097,  1102,  1103,  1116,  1117,
    1118,  1119,  1120,  1130,  1268,  1277,   625,  1121,  1122,  1123,
    1271,  1124,  1133,  1134,  1270,  1135,  1136,  1164,  1165,  1166,
     484,  1167,  1192,  1193,  1194,  1195,  1196,  1197,  1210,   722,
    1248,  1216,  1211,  1212,  1217,  1218,  1219,  1220,  1233,   749,
     800,  1249,  1293,  1279,   782,   715,  1269,  1250,  1251,   388,
     442,  1252,  1253,  1265,  1264,  1254,  1241,  1280,   711,  1242,
     310,  1281,  1282,     0,     0,     0,     0,   534,   652,     0,
       0,     0,     0,     0,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   565,     0,     0,
       0,     0,     0,     0,     0,   646,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   580
};

static const yytype_int16 yycheck[] =
{
     622,   623,   300,     8,     1,   303,     1,   305,   306,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,   228,
       1,   208,   208,    51,    47,   212,   212,   107,     1,   226,
     227,     1,     1,     1,    29,   228,   226,     1,   226,     1,
     230,   226,    37,     1,     1,   230,   226,     1,   226,    40,
     230,    19,   230,   175,   176,   226,     1,     1,     1,   230,
     228,   226,     1,     6,     7,   230,     9,    10,    55,   226,
      38,    14,   228,   230,    62,    62,    62,    64,    62,   228,
      23,    24,    27,    40,    29,   228,    78,    78,    31,    78,
       1,    34,    35,    36,   122,   228,    64,     1,    41,   397,
     228,   399,   400,   226,    99,   229,   226,   230,    62,    99,
     230,    56,   410,    96,    99,    58,    59,   415,    99,   228,
      65,    78,   202,    96,   228,    68,   424,   425,    71,    72,
      99,    99,   123,   120,   117,    99,    79,    99,   436,   123,
     438,   439,    87,    86,   117,    88,    91,    90,   116,    92,
     228,    94,    95,   123,    99,    99,   228,   102,   103,   123,
      99,   228,   105,   228,   187,   123,   123,   110,   111,   123,
     113,   114,   115,   196,   171,   118,     1,   228,   228,   171,
     148,   149,   171,     1,   228,     3,   131,     5,     1,   226,
       1,   196,   226,   230,   229,    99,   230,    11,    12,    13,
     143,    19,   147,   228,   228,   150,   151,   152,   228,   228,
     153,   154,   155,   156,   157,   158,   159,     1,   228,   123,
      38,   218,   229,   192,   226,   229,   216,     1,   526,   219,
     227,   199,   227,    17,    18,   227,   227,    55,    22,    57,
     227,   227,   227,   227,   227,    19,    64,   216,   192,   219,
     229,   219,   197,   229,   216,   223,   171,   219,    76,   227,
     171,   219,   229,   227,    38,   227,   209,   210,   211,   227,
     213,   214,   216,   229,    99,   220,   221,   216,   229,   222,
      64,    99,   227,   227,   227,     1,    99,   229,    99,     1,
      64,     1,     1,   107,  1069,  1070,  1071,    81,    82,    83,
      84,    85,   120,   229,   229,    89,   229,   218,   229,    93,
      19,   609,   229,    25,    26,    99,   614,    33,   226,   617,
      32,   139,   229,   621,   108,   109,    42,    43,    44,    38,
     148,    47,    48,   229,   229,   119,    52,    53,    54,   164,
     229,   229,   116,   229,   229,    55,   229,   229,    60,    61,
     124,   125,    62,   164,    64,    64,   140,   182,   229,   229,
       1,    73,    74,    75,     1,   229,   229,   229,    80,    81,
     144,   182,   229,   198,   229,   229,   229,   229,   229,   197,
     229,   229,    19,   229,   229,   229,   229,   198,    29,   229,
      99,   229,    67,   107,    69,   229,    37,   229,   229,   229,
     184,    38,   220,   216,   226,   229,   229,   116,   229,   227,
     120,   226,   229,   229,   227,   121,   227,   229,   132,   133,
     134,   135,   136,   137,   138,   229,    69,    64,   805,   806,
     807,   808,   809,   810,   811,   229,   229,   112,   229,   148,
     149,   229,     1,   227,   229,   219,   229,     6,     7,   229,
       9,    10,   229,   227,   129,    14,   229,   229,    99,   229,
     229,   229,   229,   229,    23,    24,   229,   229,   229,   229,
     229,   229,    31,   229,   229,    34,    35,    36,    69,   116,
       4,   229,    41,   229,   229,   229,   129,   124,   125,   229,
     199,   229,   167,   168,   229,   229,    20,    21,   229,    58,
      59,   229,    15,   121,   121,   107,    30,   144,   107,    68,
     219,   227,    71,    72,   223,   227,   208,   160,   107,   107,
      79,   107,   107,   226,   226,   168,    39,    86,   229,    88,
     229,    90,   229,    92,   177,    94,    95,     1,   129,   229,
     229,   229,    66,    67,   219,    69,   105,   229,   229,   224,
     229,   110,   111,   229,   113,   114,   115,    70,   201,   118,
     203,   204,   229,    27,   229,    29,   229,   229,   229,   160,
     229,   226,    96,   229,   217,   229,   229,   168,   229,   229,
     104,   224,   219,   229,   143,   229,   177,   100,   101,   229,
    1212,   229,    56,   106,   153,   154,   155,   156,   157,   158,
     159,    65,   126,   229,   128,   129,   229,   229,   229,   229,
     201,   121,   203,   204,   229,   226,   229,   130,   208,   229,
     107,   208,   146,    87,   107,   208,   217,    91,   107,   107,
     107,   208,   145,   224,   208,    99,   208,   107,   102,   103,
     107,     1,   107,     3,   168,     5,   107,   107,   107,   173,
     209,   210,   211,   177,   213,   214,   107,   181,   107,    19,
     208,   229,   186,   222,   229,   208,   190,   131,   208,   208,
     208,   208,   208,   208,   208,   107,   208,   201,    38,   203,
     204,   208,   206,   147,   226,   226,   150,   151,   152,     1,
     121,   121,   121,   217,   207,    55,   229,    57,     0,     1,
     224,   229,     4,   229,    64,   121,   229,   229,   229,   229,
     229,   229,   225,   229,    16,   226,    76,    19,   226,    21,
     229,    33,   229,   226,   229,   229,    28,   226,   229,   229,
      42,    43,    44,   197,     1,    47,    48,   229,    40,    99,
      52,    53,    54,    45,    46,   229,   208,   229,   229,   229,
      17,    18,   226,   229,   229,    22,   220,   221,   229,   107,
     120,    63,   208,   229,   208,    67,   208,   208,    47,   208,
      49,    50,   226,   208,     1,    77,   121,   121,   107,   139,
     107,   121,   121,   121,   121,   121,   121,   121,   148,   121,
     121,   121,   226,   121,   208,    97,    98,    64,    25,    26,
     226,   229,   226,   228,   226,    32,   229,   121,   229,    47,
     112,    49,    50,   226,    81,    82,    83,    84,    85,   229,
     229,   226,    89,   229,   226,   229,    93,   129,   226,   226,
     226,   226,    99,    60,    61,   226,   226,   197,   226,   141,
     142,   108,   109,   226,   226,   226,    73,    74,    75,    47,
     226,   226,   119,    80,    81,   107,   107,   229,   107,   107,
     220,   107,   107,   165,   107,   121,   107,   107,   107,   226,
     229,   121,   107,   140,   121,   208,   178,   121,   229,   121,
     226,   183,   161,   162,   163,   121,   188,   166,   167,   191,
     169,   170,   121,   172,   259,   174,   121,   121,   177,   121,
     179,   180,   121,   121,   121,   226,   185,   226,   121,   121,
     189,   226,   107,   226,   193,   194,   195,   184,   226,   226,
     226,   200,   226,   161,   162,   163,   205,   226,   166,   167,
     226,   169,   170,   226,   172,   226,   174,   226,   226,   177,
     226,   179,   180,   226,   226,   226,   226,   185,   226,   226,
     226,   189,   226,   226,   226,   193,   194,   195,   226,   121,
     226,   226,   200,   161,   162,   163,   226,   205,   166,   167,
     121,   169,   170,   226,   172,   121,   174,   208,   121,   177,
     121,   179,   180,   121,   121,   121,   121,   185,   107,   226,
     121,   189,   226,   226,   226,   193,   194,   195,   226,   229,
     226,   121,   200,   226,   121,   226,   226,   205,   121,   208,
     226,   226,   226,   121,   121,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   208,   121,   121,
     121,   121,   229,   229,   226,   121,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   121,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   121,   121,   226,   226,   229,   121,
     121,   226,   226,   121,   121,   107,   229,   226,   226,   226,
     230,   226,   226,   121,   226,   127,   226,   226,   129,   129,
     127,   127,   226,   226,   226,    77,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,  1295,  1029,   226,   488,
     226,   226,   226,  1258,   226,   226,   226,   226,   503,   572,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   215,  1235,  1256,   329,   226,   226,   226,
    1246,   226,   226,   226,  1244,   226,   226,   226,   226,   226,
     213,   226,   226,   226,   226,   226,   226,   226,   226,   475,
    1131,   226,   229,   229,   226,   226,   226,   226,   226,   519,
     585,   226,  1267,  1260,   558,   465,  1240,   231,   231,   110,
     160,   231,   231,   226,   229,   231,  1099,   226,   452,  1101,
      93,   226,   226,    -1,    -1,    -1,    -1,   230,   392,    -1,
      -1,    -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   281,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   382,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   289
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   233,     0,     1,     4,    16,    19,    21,    28,    40,
      45,    46,    63,    67,    77,    97,    98,   112,   129,   141,
     142,   165,   178,   183,   188,   191,   234,   239,   244,   264,
     270,   276,   284,   298,   318,   342,   356,   371,   378,   382,
     392,   401,   422,   428,   434,   438,   444,   498,   511,   226,
     227,   228,   228,   319,   402,   429,   228,   439,   228,   357,
     423,   343,   228,   271,   299,   372,   228,   228,   393,   228,
     277,   228,   383,     1,    29,    37,    99,   265,   266,   267,
     268,   269,     1,    25,    26,    32,    60,    61,    73,    74,
      75,    80,    81,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   228,   228,   228,     1,    62,
     435,   436,   437,   228,     1,     6,     7,     9,    10,    14,
      23,    24,    31,    34,    35,    36,    41,    58,    59,    68,
      71,    72,    79,    86,    88,    90,    92,    94,    95,   105,
     110,   111,   113,   114,   115,   118,   143,   153,   154,   155,
     156,   157,   158,   159,   209,   210,   211,   213,   214,   222,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   491,   495,   496,   497,   228,   228,   228,
       1,    96,   117,   240,   241,   242,   243,   228,   228,   228,
       1,    33,    42,    43,    44,    47,    48,    52,    53,    54,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,     1,    27,    29,    56,    65,    87,    91,    99,   102,
     103,   131,   147,   150,   151,   152,   197,   220,   221,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   228,     1,
     218,   285,   286,   287,   288,   289,   228,     1,    99,   379,
     380,   381,   228,   226,   229,   229,   229,   227,   266,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   227,
     500,     1,    17,    18,    22,    64,    81,    82,    83,    84,
      85,    89,    93,    99,   108,   109,   119,   140,   184,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,     1,     3,
       5,    19,    38,    55,    57,    64,    76,    99,   120,   139,
     148,   197,   220,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   417,   418,   419,   420,   421,     1,
      62,   123,   430,   431,   432,   433,   229,   227,   436,     1,
      99,   123,   440,   441,   442,   443,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   492,   488,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   227,   446,     1,    19,    38,    64,   116,   124,   125,
     144,   219,   358,   359,   360,   361,   362,   363,   364,   368,
     369,   370,     1,   123,   219,   424,   425,   426,   427,     1,
      55,    62,    64,   120,   344,   348,   349,   350,   354,   355,
     226,   229,   229,   227,   241,     1,    78,   171,   272,   273,
     274,   275,     1,    19,    38,    64,    99,   116,   148,   149,
     199,   219,   223,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,     1,    40,    78,   123,   373,
     374,   375,   376,   377,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   227,   513,   226,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   227,   246,     1,    99,   216,   394,   395,
     396,   397,   226,   229,   227,   286,   171,     1,    99,   164,
     182,   198,   278,   279,   280,   281,   282,   283,   229,   227,
     380,     1,    99,   216,   219,   384,   385,   386,   387,   388,
     121,   121,   121,   226,   107,   107,   236,   208,   107,   236,
     107,   236,   236,   107,   107,   226,   226,   229,   229,   229,
     339,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   227,   321,   226,   229,   229,   229,
     229,   229,   229,   414,   229,   229,   229,   229,   229,   229,
     229,   227,   404,   229,   229,   227,   431,   121,   226,   229,
     229,   227,   441,   208,   236,   107,   236,   236,   208,   107,
     208,   107,   107,   107,   208,   208,   208,   236,   107,   107,
     107,   107,   236,   107,   107,   107,   107,   208,   229,   229,
     208,   236,   236,   208,   208,   208,   208,   212,   208,   212,
     208,   208,   208,   208,   107,   236,   208,   236,   236,   208,
     226,   226,   229,   229,   365,   229,   229,   229,   229,   229,
     227,   359,   229,   229,   227,   425,   226,   229,   229,   345,
     229,   227,   349,   121,   121,   226,   226,   229,   229,   227,
     273,   226,   229,   229,   315,   229,   229,   229,   229,   311,
     229,   229,   227,   301,   226,   229,   229,   229,   227,   374,
     208,   208,   236,   121,   208,   121,   208,   208,   208,   226,
     107,   121,   208,   121,   107,   107,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   226,   226,   229,
     398,   227,   395,   208,   226,   228,   226,   229,   229,   229,
     229,   227,   279,   121,   226,   226,   229,   389,   229,   227,
     385,   226,   226,   226,   226,   132,   133,   134,   135,   136,
     137,   138,   235,   236,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   107,   107,   236,   229,   107,   107,   107,
     236,   107,   107,   236,   121,   107,   107,   236,   107,   238,
     238,   226,   121,   175,   176,   121,   208,   121,   121,   229,
     121,   121,   107,   121,   121,   121,   121,   226,   121,   121,
     226,   226,   121,   121,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
      47,   161,   162,   163,   166,   167,   169,   170,   172,   174,
     177,   179,   180,   185,   189,   193,   194,   195,   200,   205,
     493,   494,    47,    49,    50,   161,   162,   163,   166,   167,
     169,   170,   172,   174,   177,   179,   180,   185,   189,   193,
     194,   195,   200,   205,   489,   490,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   121,   208,   229,   121,
     107,   121,   121,   121,   226,   121,   121,   226,   121,   121,
     229,   107,   352,   353,   226,   226,   226,   121,   121,   226,
     121,   208,   229,   121,   121,   121,   208,   229,   121,   121,
     226,   121,   121,   121,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   121,   229,   226,   226,     1,    99,   192,   216,   290,
     291,   292,   293,   294,   121,   121,   121,   121,   226,   226,
     121,   229,   121,   226,   235,   235,   235,   235,   235,   235,
     235,   226,   226,   226,    51,   122,   340,   341,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,    11,
      12,    13,   237,   238,   226,   226,   226,   226,   226,   226,
     226,   226,   226,     8,   196,   415,   416,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   230,
     226,   230,   226,   226,    15,    39,    70,   100,   101,   106,
     130,   145,   207,   225,   366,   367,   226,   226,   226,   226,
     226,   226,   226,   226,   226,    47,   187,   196,   346,   347,
     215,   230,   351,   226,   226,   226,   226,     4,    20,    21,
      30,    66,    67,    69,    96,   104,   126,   128,   129,   146,
     168,   173,   177,   181,   186,   190,   201,   203,   204,   206,
     217,   224,   316,   317,   226,   226,   226,   226,    47,    49,
      50,   161,   162,   163,   166,   167,   169,   170,   172,   174,
     177,   179,   180,   185,   189,   193,   194,   195,   200,   205,
     312,   313,   226,   226,   226,   226,   226,   226,    69,   129,
     160,   168,   177,   201,   203,   204,   217,   224,   399,   400,
     226,   229,   229,   295,   227,   291,   226,   226,   226,   226,
     226,    69,   129,   160,   168,   177,   201,   203,   204,   217,
     224,   390,   391,   226,   226,   230,   237,   237,   237,   226,
     230,   494,   490,   226,   230,   226,   230,   107,   353,   226,
     231,   231,   231,   231,   231,   226,   230,   226,   230,   226,
     230,   121,   202,   238,   229,   226,   226,   230,   341,   416,
     367,   347,   127,   129,   127,   129,   127,   317,   313,   400,
     226,   226,   226,    67,    69,   112,   129,   167,   168,   219,
     224,   296,   297,   391,   226,   230,   297
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   232,   233,   233,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   235,   235,
     236,   236,   236,   236,   236,   236,   236,   236,   237,   237,
     238,   238,   238,   238,   239,   240,   240,   241,   241,   241,
     242,   243,   244,   245,   245,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   265,   266,   266,   266,   266,   267,   268,   269,
     271,   270,   272,   272,   273,   273,   273,   274,   275,   277,
     276,   278,   278,   279,   279,   279,   279,   279,   280,   281,
     282,   283,   284,   285,   285,   286,   286,   286,   287,   289,
     288,   290,   290,   291,   291,   291,   291,   292,   293,   293,
     295,   294,   296,   296,   297,   297,   297,   297,   297,   297,
     297,   297,   299,   298,   300,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   311,   310,   312,   312,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   315,   314,   316,   316,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   319,   318,   320,   320,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   322,   323,   324,   325,   326,
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
     446,   446,   446,   446,   446,   446,   446,   446,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   473,   474,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   488,   487,   489,   489,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   492,   491,   493,
     493,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   495,   496,   497,   498,   499,   499,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     512,   513,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522
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
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 478 "conf_parser.y" /* yacc.c:1646  */
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
#line 2979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 518 "conf_parser.y" /* yacc.c:1646  */
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
#line 3040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 576 "conf_parser.y" /* yacc.c:1646  */
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
#line 3072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 605 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 613 "conf_parser.y" /* yacc.c:1646  */
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
#line 3100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 627 "conf_parser.y" /* yacc.c:1646  */
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
#line 3131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 655 "conf_parser.y" /* yacc.c:1646  */
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
#line 3149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 670 "conf_parser.y" /* yacc.c:1646  */
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
#line 3167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 685 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 695 "conf_parser.y" /* yacc.c:1646  */
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
#line 3197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 709 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 718 "conf_parser.y" /* yacc.c:1646  */
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
#line 3240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 746 "conf_parser.y" /* yacc.c:1646  */
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
#line 3271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 774 "conf_parser.y" /* yacc.c:1646  */
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
#line 3299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 799 "conf_parser.y" /* yacc.c:1646  */
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
#line 3324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 821 "conf_parser.y" /* yacc.c:1646  */
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
#line 3349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3370 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3394 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 890 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 894 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 930 "conf_parser.y" /* yacc.c:1646  */
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
#line 3465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 966 "conf_parser.y" /* yacc.c:1646  */
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
#line 3513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3544 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1030 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1080 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3664 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1087 "conf_parser.y" /* yacc.c:1646  */
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
  }
}
#line 3722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1155 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1161 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1167 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1173 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1179 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1190 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1196 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1213 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1220 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1232 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1236 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1244 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1248 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1252 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1264 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1268 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1280 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1284 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1296 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1304 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1345 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1353 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1357 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1361 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1365 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1369 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1373 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1377 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1381 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1385 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1389 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1393 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1397 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1401 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1405 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1409 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1417 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1435 "conf_parser.y" /* yacc.c:1646  */
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
#line 4289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1447 "conf_parser.y" /* yacc.c:1646  */
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

  rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
#line 4337 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1511 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1517 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1523 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1529 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1535 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1541 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1547 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1553 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1559 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1565 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1571 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1590 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1614 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1621 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1625 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1641 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1647 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1655 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1663 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
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
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1681 "conf_parser.y" /* yacc.c:1646  */
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
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4603 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1698 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1704 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1713 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1717 "conf_parser.y" /* yacc.c:1646  */
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
#line 4671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1766 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4680 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1772 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1778 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1784 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4712 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1795 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1802 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1810 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1814 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1822 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1826 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1830 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1834 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1838 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
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
#line 4828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1858 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1898 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1904 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1940 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1951 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_SHARED);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);
}
#line 4950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1968 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
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
#line 4981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2000 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2004 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2012 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2016 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2020 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2024 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2028 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2032 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2036 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2086 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2098 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2102 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2106 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2110 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2114 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2118 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2136 "conf_parser.y" /* yacc.c:1646  */
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
#line 5297 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2216 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2222 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2228 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2234 "conf_parser.y" /* yacc.c:1646  */
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
#line 5340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
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
#line 5356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2272 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2282 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2288 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2292 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2315 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2327 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2346 "conf_parser.y" /* yacc.c:1646  */
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
#line 5507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
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
#line 5530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2391 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2404 "conf_parser.y" /* yacc.c:1646  */
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
#line 5574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2436 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2450 "conf_parser.y" /* yacc.c:1646  */
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
#line 5609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2467 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2471 "conf_parser.y" /* yacc.c:1646  */
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
#line 5640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2493 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2499 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2560 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5666 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2565 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5674 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2570 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2601 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2606 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2611 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2616 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2621 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2626 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5771 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2631 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5779 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2636 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5787 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2641 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2646 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2651 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5836 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2677 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5852 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2682 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5860 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2687 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2692 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2695 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2700 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5908 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2718 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2723 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5932 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2728 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2733 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2738 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2743 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2748 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2753 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5980 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2758 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2763 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5996 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2768 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6004 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2780 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2783 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2786 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6076 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6124 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6132 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6140 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6148 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6204 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6220 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6268 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6276 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6284 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6292 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6308 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6316 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6356 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2945 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2950 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2955 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6396 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2960 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6404 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2965 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6412 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2970 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2975 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2980 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2985 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2990 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6452 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[-1].number) > 0)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_add(&event_write_links_file, NULL);
    }
    else
     event_delete(&event_write_links_file);

    ConfigServerHide.flatten_links_delay = (yyvsp[-1].number);
  }
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3056 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6519 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3071 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6540 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3077 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6549 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6553 "conf_parser.c" /* yacc.c:1646  */
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
