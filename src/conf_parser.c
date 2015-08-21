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
    CONNECT = 275,
    CONNECTFREQ = 276,
    CYCLE_ON_HOST_CHANGE = 277,
    DEFAULT_FLOODCOUNT = 278,
    DEFAULT_JOIN_FLOOD_COUNT = 279,
    DEFAULT_JOIN_FLOOD_TIME = 280,
    DEFAULT_MAX_CLIENTS = 281,
    DENY = 282,
    DESCRIPTION = 283,
    DIE = 284,
    DISABLE_AUTH = 285,
    DISABLE_FAKE_CHANNELS = 286,
    DISABLE_REMOTE_COMMANDS = 287,
    DLINE_MIN_CIDR = 288,
    DLINE_MIN_CIDR6 = 289,
    DOTS_IN_IDENT = 290,
    EMAIL = 291,
    ENCRYPTED = 292,
    EXCEED_LIMIT = 293,
    EXEMPT = 294,
    FAILED_OPER_NOTICE = 295,
    FLATTEN_LINKS = 296,
    GECOS = 297,
    GENERAL = 298,
    HIDDEN = 299,
    HIDDEN_NAME = 300,
    HIDE_CHANS = 301,
    HIDE_IDLE = 302,
    HIDE_IDLE_FROM_OPERS = 303,
    HIDE_SERVER_IPS = 304,
    HIDE_SERVERS = 305,
    HIDE_SERVICES = 306,
    HOST = 307,
    HUB = 308,
    HUB_MASK = 309,
    IGNORE_BOGUS_TS = 310,
    INVISIBLE_ON_CONNECT = 311,
    INVITE_CLIENT_COUNT = 312,
    INVITE_CLIENT_TIME = 313,
    IP = 314,
    IRCD_AUTH = 315,
    IRCD_FLAGS = 316,
    IRCD_SID = 317,
    KILL = 318,
    KILL_CHASE_TIME_LIMIT = 319,
    KLINE = 320,
    KLINE_EXEMPT = 321,
    KLINE_MIN_CIDR = 322,
    KLINE_MIN_CIDR6 = 323,
    KNOCK_CLIENT_COUNT = 324,
    KNOCK_CLIENT_TIME = 325,
    KNOCK_DELAY_CHANNEL = 326,
    LEAF_MASK = 327,
    LINKS_DELAY = 328,
    LISTEN = 329,
    MASK = 330,
    MAX_ACCEPT = 331,
    MAX_BANS = 332,
    MAX_CHANNELS = 333,
    MAX_GLOBAL = 334,
    MAX_IDENT = 335,
    MAX_IDLE = 336,
    MAX_LOCAL = 337,
    MAX_NICK_CHANGES = 338,
    MAX_NICK_LENGTH = 339,
    MAX_NICK_TIME = 340,
    MAX_NUMBER = 341,
    MAX_TARGETS = 342,
    MAX_TOPIC_LENGTH = 343,
    MAX_WATCH = 344,
    MIN_IDLE = 345,
    MIN_NONWILDCARD = 346,
    MIN_NONWILDCARD_SIMPLE = 347,
    MODULE = 348,
    MODULES = 349,
    MOTD = 350,
    NAME = 351,
    NEED_IDENT = 352,
    NEED_PASSWORD = 353,
    NETWORK_DESC = 354,
    NETWORK_NAME = 355,
    NICK = 356,
    NO_OPER_FLOOD = 357,
    NO_TILDE = 358,
    NUMBER = 359,
    NUMBER_PER_CIDR = 360,
    NUMBER_PER_IP = 361,
    OPER_ONLY_UMODES = 362,
    OPER_PASS_RESV = 363,
    OPER_UMODES = 364,
    OPERATOR = 365,
    OPERS_BYPASS_CALLERID = 366,
    PACE_WAIT = 367,
    PACE_WAIT_SIMPLE = 368,
    PASSWORD = 369,
    PATH = 370,
    PING_COOKIE = 371,
    PING_TIME = 372,
    PORT = 373,
    QSTRING = 374,
    RANDOM_IDLE = 375,
    REASON = 376,
    REDIRPORT = 377,
    REDIRSERV = 378,
    REHASH = 379,
    REMOTE = 380,
    REMOTEBAN = 381,
    RESV = 382,
    RESV_EXEMPT = 383,
    RSA_PRIVATE_KEY_FILE = 384,
    RSA_PUBLIC_KEY_FILE = 385,
    SECONDS = 386,
    MINUTES = 387,
    HOURS = 388,
    DAYS = 389,
    WEEKS = 390,
    MONTHS = 391,
    YEARS = 392,
    SEND_PASSWORD = 393,
    SENDQ = 394,
    SERVERHIDE = 395,
    SERVERINFO = 396,
    SHORT_MOTD = 397,
    SPOOF = 398,
    SPOOF_NOTICE = 399,
    SQUIT = 400,
    SSL_CERTIFICATE_FILE = 401,
    SSL_CERTIFICATE_FINGERPRINT = 402,
    SSL_CONNECTION_REQUIRED = 403,
    SSL_DH_ELLIPTIC_CURVE = 404,
    SSL_DH_PARAM_FILE = 405,
    SSL_MESSAGE_DIGEST_ALGORITHM = 406,
    STATS_E_DISABLED = 407,
    STATS_I_OPER_ONLY = 408,
    STATS_K_OPER_ONLY = 409,
    STATS_M_OPER_ONLY = 410,
    STATS_O_OPER_ONLY = 411,
    STATS_P_OPER_ONLY = 412,
    STATS_U_OPER_ONLY = 413,
    T_ALL = 414,
    T_BOTS = 415,
    T_CALLERID = 416,
    T_CCONN = 417,
    T_COMMAND = 418,
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
    T_NCHANGE = 433,
    T_NONONREG = 434,
    T_OPME = 435,
    T_PREPEND = 436,
    T_PSEUDO = 437,
    T_RECVQ = 438,
    T_REJ = 439,
    T_RESTART = 440,
    T_SERVER = 441,
    T_SERVICE = 442,
    T_SERVNOTICE = 443,
    T_SET = 444,
    T_SHARED = 445,
    T_SIZE = 446,
    T_SKILL = 447,
    T_SOFTCALLERID = 448,
    T_SPY = 449,
    T_SSL = 450,
    T_SSL_CIPHER_LIST = 451,
    T_TARGET = 452,
    T_UMODES = 453,
    T_UNAUTH = 454,
    T_UNDLINE = 455,
    T_UNLIMITED = 456,
    T_UNRESV = 457,
    T_UNXLINE = 458,
    T_WALLOP = 459,
    T_WALLOPS = 460,
    T_WEBIRC = 461,
    TBOOL = 462,
    THROTTLE_COUNT = 463,
    THROTTLE_TIME = 464,
    TKLINE_EXPIRE_NOTICES = 465,
    TMASKED = 466,
    TS_MAX_DELTA = 467,
    TS_WARN_DELTA = 468,
    TWODOTS = 469,
    TYPE = 470,
    UNKLINE = 471,
    USE_LOGGING = 472,
    USER = 473,
    VHOST = 474,
    VHOST6 = 475,
    WARN_NO_CONNECT_BLOCK = 476,
    WHOIS = 477,
    XLINE = 478,
    XLINE_EXEMPT = 479
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
#define DENY 282
#define DESCRIPTION 283
#define DIE 284
#define DISABLE_AUTH 285
#define DISABLE_FAKE_CHANNELS 286
#define DISABLE_REMOTE_COMMANDS 287
#define DLINE_MIN_CIDR 288
#define DLINE_MIN_CIDR6 289
#define DOTS_IN_IDENT 290
#define EMAIL 291
#define ENCRYPTED 292
#define EXCEED_LIMIT 293
#define EXEMPT 294
#define FAILED_OPER_NOTICE 295
#define FLATTEN_LINKS 296
#define GECOS 297
#define GENERAL 298
#define HIDDEN 299
#define HIDDEN_NAME 300
#define HIDE_CHANS 301
#define HIDE_IDLE 302
#define HIDE_IDLE_FROM_OPERS 303
#define HIDE_SERVER_IPS 304
#define HIDE_SERVERS 305
#define HIDE_SERVICES 306
#define HOST 307
#define HUB 308
#define HUB_MASK 309
#define IGNORE_BOGUS_TS 310
#define INVISIBLE_ON_CONNECT 311
#define INVITE_CLIENT_COUNT 312
#define INVITE_CLIENT_TIME 313
#define IP 314
#define IRCD_AUTH 315
#define IRCD_FLAGS 316
#define IRCD_SID 317
#define KILL 318
#define KILL_CHASE_TIME_LIMIT 319
#define KLINE 320
#define KLINE_EXEMPT 321
#define KLINE_MIN_CIDR 322
#define KLINE_MIN_CIDR6 323
#define KNOCK_CLIENT_COUNT 324
#define KNOCK_CLIENT_TIME 325
#define KNOCK_DELAY_CHANNEL 326
#define LEAF_MASK 327
#define LINKS_DELAY 328
#define LISTEN 329
#define MASK 330
#define MAX_ACCEPT 331
#define MAX_BANS 332
#define MAX_CHANNELS 333
#define MAX_GLOBAL 334
#define MAX_IDENT 335
#define MAX_IDLE 336
#define MAX_LOCAL 337
#define MAX_NICK_CHANGES 338
#define MAX_NICK_LENGTH 339
#define MAX_NICK_TIME 340
#define MAX_NUMBER 341
#define MAX_TARGETS 342
#define MAX_TOPIC_LENGTH 343
#define MAX_WATCH 344
#define MIN_IDLE 345
#define MIN_NONWILDCARD 346
#define MIN_NONWILDCARD_SIMPLE 347
#define MODULE 348
#define MODULES 349
#define MOTD 350
#define NAME 351
#define NEED_IDENT 352
#define NEED_PASSWORD 353
#define NETWORK_DESC 354
#define NETWORK_NAME 355
#define NICK 356
#define NO_OPER_FLOOD 357
#define NO_TILDE 358
#define NUMBER 359
#define NUMBER_PER_CIDR 360
#define NUMBER_PER_IP 361
#define OPER_ONLY_UMODES 362
#define OPER_PASS_RESV 363
#define OPER_UMODES 364
#define OPERATOR 365
#define OPERS_BYPASS_CALLERID 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PORT 373
#define QSTRING 374
#define RANDOM_IDLE 375
#define REASON 376
#define REDIRPORT 377
#define REDIRSERV 378
#define REHASH 379
#define REMOTE 380
#define REMOTEBAN 381
#define RESV 382
#define RESV_EXEMPT 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SECONDS 386
#define MINUTES 387
#define HOURS 388
#define DAYS 389
#define WEEKS 390
#define MONTHS 391
#define YEARS 392
#define SEND_PASSWORD 393
#define SENDQ 394
#define SERVERHIDE 395
#define SERVERINFO 396
#define SHORT_MOTD 397
#define SPOOF 398
#define SPOOF_NOTICE 399
#define SQUIT 400
#define SSL_CERTIFICATE_FILE 401
#define SSL_CERTIFICATE_FINGERPRINT 402
#define SSL_CONNECTION_REQUIRED 403
#define SSL_DH_ELLIPTIC_CURVE 404
#define SSL_DH_PARAM_FILE 405
#define SSL_MESSAGE_DIGEST_ALGORITHM 406
#define STATS_E_DISABLED 407
#define STATS_I_OPER_ONLY 408
#define STATS_K_OPER_ONLY 409
#define STATS_M_OPER_ONLY 410
#define STATS_O_OPER_ONLY 411
#define STATS_P_OPER_ONLY 412
#define STATS_U_OPER_ONLY 413
#define T_ALL 414
#define T_BOTS 415
#define T_CALLERID 416
#define T_CCONN 417
#define T_COMMAND 418
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
#define T_NCHANGE 433
#define T_NONONREG 434
#define T_OPME 435
#define T_PREPEND 436
#define T_PSEUDO 437
#define T_RECVQ 438
#define T_REJ 439
#define T_RESTART 440
#define T_SERVER 441
#define T_SERVICE 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_SKILL 447
#define T_SOFTCALLERID 448
#define T_SPY 449
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_TARGET 452
#define T_UMODES 453
#define T_UNAUTH 454
#define T_UNDLINE 455
#define T_UNLIMITED 456
#define T_UNRESV 457
#define T_UNXLINE 458
#define T_WALLOP 459
#define T_WALLOPS 460
#define T_WEBIRC 461
#define TBOOL 462
#define THROTTLE_COUNT 463
#define THROTTLE_TIME 464
#define TKLINE_EXPIRE_NOTICES 465
#define TMASKED 466
#define TS_MAX_DELTA 467
#define TS_WARN_DELTA 468
#define TWODOTS 469
#define TYPE 470
#define UNKLINE 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_CONNECT_BLOCK 476
#define WHOIS 477
#define XLINE 478
#define XLINE_EXEMPT 479

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 684 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
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
#define YYLAST   1347

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  656
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1293

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

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
       2,     2,     2,     2,   229,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   230,   225,
       2,   228,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   227,     2,   226,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   381,   381,   382,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   412,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   423,   423,
     424,   425,   426,   427,   434,   437,   437,   438,   438,   438,
     440,   446,   453,   455,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   476,   516,   574,   603,   611,   625,   653,
     668,   683,   693,   707,   716,   744,   772,   797,   819,   841,
     850,   852,   852,   853,   854,   855,   856,   858,   867,   876,
     889,   888,   906,   906,   907,   907,   907,   909,   915,   925,
     924,   943,   943,   944,   944,   944,   944,   944,   946,   952,
     958,   964,   985,   986,   986,   988,   988,   989,   991,   998,
     998,  1011,  1012,  1014,  1014,  1015,  1015,  1017,  1025,  1028,
    1034,  1033,  1039,  1039,  1040,  1044,  1048,  1052,  1056,  1060,
    1064,  1068,  1079,  1078,  1167,  1167,  1168,  1169,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1181,  1187,
    1193,  1199,  1205,  1216,  1222,  1228,  1239,  1246,  1245,  1251,
    1251,  1252,  1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,
    1288,  1292,  1296,  1300,  1304,  1308,  1312,  1316,  1320,  1324,
    1328,  1332,  1336,  1343,  1342,  1348,  1348,  1349,  1353,  1357,
    1361,  1365,  1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,
    1401,  1405,  1409,  1413,  1417,  1421,  1425,  1429,  1433,  1437,
    1448,  1447,  1504,  1504,  1505,  1506,  1507,  1508,  1509,  1510,
    1511,  1512,  1513,  1514,  1515,  1516,  1517,  1517,  1518,  1519,
    1520,  1521,  1523,  1529,  1535,  1541,  1547,  1553,  1559,  1565,
    1571,  1577,  1583,  1590,  1596,  1602,  1608,  1617,  1627,  1626,
    1632,  1632,  1633,  1637,  1648,  1647,  1654,  1653,  1658,  1658,
    1659,  1663,  1667,  1673,  1673,  1674,  1674,  1674,  1674,  1674,
    1676,  1676,  1678,  1678,  1680,  1693,  1710,  1716,  1726,  1725,
    1767,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1775,
    1776,  1778,  1784,  1790,  1796,  1808,  1807,  1813,  1813,  1814,
    1818,  1822,  1826,  1830,  1834,  1838,  1842,  1846,  1850,  1856,
    1870,  1879,  1893,  1892,  1907,  1907,  1908,  1908,  1908,  1908,
    1910,  1916,  1922,  1932,  1934,  1934,  1935,  1935,  1937,  1953,
    1952,  1977,  1977,  1978,  1978,  1978,  1978,  1980,  1986,  2006,
    2005,  2011,  2011,  2012,  2016,  2020,  2024,  2028,  2032,  2036,
    2040,  2044,  2048,  2058,  2057,  2078,  2078,  2079,  2079,  2079,
    2081,  2088,  2087,  2093,  2093,  2094,  2098,  2102,  2106,  2110,
    2114,  2118,  2122,  2126,  2130,  2140,  2139,  2211,  2211,  2212,
    2213,  2214,  2215,  2216,  2217,  2218,  2219,  2220,  2221,  2222,
    2223,  2224,  2225,  2226,  2228,  2234,  2240,  2246,  2259,  2272,
    2278,  2284,  2288,  2295,  2294,  2299,  2299,  2300,  2304,  2310,
    2321,  2327,  2333,  2339,  2355,  2354,  2380,  2380,  2381,  2381,
    2381,  2383,  2403,  2413,  2412,  2439,  2439,  2440,  2440,  2440,
    2442,  2448,  2457,  2459,  2459,  2460,  2460,  2462,  2480,  2479,
    2502,  2502,  2503,  2503,  2503,  2505,  2511,  2520,  2523,  2523,
    2524,  2525,  2526,  2527,  2528,  2529,  2530,  2531,  2532,  2533,
    2534,  2535,  2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,
    2544,  2545,  2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,
    2554,  2555,  2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,
    2564,  2565,  2566,  2567,  2568,  2569,  2570,  2573,  2578,  2583,
    2588,  2594,  2599,  2604,  2609,  2614,  2619,  2624,  2629,  2634,
    2639,  2644,  2649,  2654,  2659,  2664,  2670,  2675,  2680,  2685,
    2690,  2695,  2700,  2705,  2708,  2713,  2716,  2721,  2726,  2731,
    2736,  2741,  2746,  2751,  2756,  2761,  2766,  2771,  2776,  2781,
    2787,  2786,  2791,  2791,  2792,  2795,  2798,  2801,  2804,  2807,
    2810,  2813,  2816,  2819,  2822,  2825,  2828,  2831,  2834,  2837,
    2840,  2843,  2846,  2849,  2852,  2855,  2861,  2860,  2865,  2865,
    2866,  2869,  2872,  2875,  2878,  2881,  2884,  2887,  2890,  2893,
    2896,  2899,  2902,  2905,  2908,  2911,  2914,  2917,  2920,  2923,
    2928,  2933,  2938,  2947,  2950,  2950,  2951,  2952,  2953,  2954,
    2955,  2956,  2957,  2958,  2959,  2960,  2961,  2963,  2968,  2973,
    2978,  2983,  2988,  2993,  2998,  3003,  3008,  3016,  3019,  3019,
    3020,  3021,  3022,  3023,  3024,  3025,  3026,  3027,  3028,  3030,
    3036,  3042,  3048,  3054,  3063,  3078,  3084
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
  "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
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
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE",
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
     475,   476,   477,   478,   479,    59,   125,   123,    61,    44,
      58
};
# endif

#define YYPACT_NINF -689

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-689)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -689,   632,  -689,  -172,  -202,  -200,  -689,  -689,  -689,  -189,
    -689,  -187,  -689,  -689,  -689,  -176,  -689,  -689,  -689,  -167,
    -158,  -689,  -156,  -689,  -130,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,    14,   898,  -127,  -104,   -90,     5,   -76,   393,   -70,
     -46,   -33,   221,   -28,   -27,   -19,   488,   491,   -18,    48,
     -13,    71,   -10,  -190,     1,    35,    36,    60,  -689,  -689,
    -689,  -689,  -689,    44,    45,    56,    57,    76,    77,    98,
     101,   103,   109,   270,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,   699,   606,    15,  -689,   110,
      16,  -689,  -689,   201,  -689,   115,   116,   121,   123,   124,
     131,   134,   135,   137,   139,   141,   143,   145,   148,   150,
     160,   163,   165,   168,   169,   177,   178,   182,   185,   193,
    -689,   194,  -689,   196,   197,   203,   204,   209,   228,   234,
     235,   236,   237,   238,   240,   243,   244,   247,   249,   253,
     255,    22,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,   316,
      38,   322,    -1,   258,   259,    33,  -689,  -689,  -689,    18,
     305,    19,  -689,   260,   262,   269,   271,   280,   282,   283,
     284,   225,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,    87,   290,   293,   296,   298,   300,   303,   308,   313,
     314,   324,   326,   327,   329,   330,   331,   332,   341,    20,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,    10,   167,
     342,     2,  -689,  -689,  -689,    91,   359,  -689,   343,    67,
    -689,  -689,   164,  -689,   453,   454,   458,   353,  -689,   325,
     476,   374,   478,   476,   479,   476,   476,   480,   481,   361,
    -689,   364,   365,   366,   368,  -689,   369,   370,   371,   372,
     376,   380,   382,   384,   385,   387,   388,   390,   391,   172,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,   367,   395,
     396,   399,   400,   401,   403,  -689,   406,   410,   416,   417,
     418,   419,   421,   149,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
     426,   428,    11,  -689,  -689,  -689,   502,   432,  -689,  -689,
     433,   434,    64,  -689,  -689,  -689,   456,   476,   560,   476,
     476,   461,   561,   462,   566,   568,   572,   470,   472,   473,
     476,   577,   578,   579,   580,   476,   581,   582,   584,   585,
     483,   463,   486,   466,   489,   476,   476,   490,   492,   494,
    -197,  -185,   496,   497,   498,   500,   594,   476,   501,   476,
     476,   511,   484,  -689,   503,   493,   495,  -689,   504,   505,
     506,   507,   508,    84,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,   509,   510,    23,  -689,  -689,  -689,
     514,   512,   513,  -689,   515,  -689,    94,  -689,  -689,  -689,
    -689,  -689,   600,   603,   520,  -689,   521,   519,   522,    12,
    -689,  -689,  -689,   523,   528,   529,  -689,   530,   533,   534,
     535,   536,  -689,   537,   538,   186,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,   524,   539,
     540,   541,    83,  -689,  -689,  -689,  -689,   518,   544,   563,
     610,   564,   567,   569,   476,   557,  -689,  -689,   626,   612,
     576,   665,   682,   683,   669,   671,   672,   674,   675,   678,
     679,   680,   681,   684,   687,   583,  -689,   586,   573,  -689,
      66,  -689,  -689,  -689,  -689,   605,   588,  -689,   590,   593,
     592,   595,   598,   599,   183,  -689,  -689,  -689,  -689,  -689,
     691,   596,  -689,   607,   614,  -689,   615,    65,  -689,  -689,
    -689,  -689,   620,   624,   628,  -689,   629,   310,   630,   633,
     634,   638,   640,   641,   650,   653,   655,  -689,  -689,   727,
     731,   476,   657,   736,   753,   779,   476,   784,   785,   476,
     771,   787,   789,   476,   790,   790,   670,  -689,  -689,   778,
     -83,   786,   696,   792,   796,   676,   799,   801,   794,   806,
     809,   811,   812,   709,  -689,   814,   816,   712,  -689,   713,
    -689,   820,   824,   719,  -689,   720,   721,   723,   724,   725,
     726,   728,   729,   732,   733,   734,   735,   737,   738,   739,
     740,   741,   745,   746,   747,   749,   752,   754,   755,   756,
     748,   757,   668,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   770,   772,   773,   774,   775,
     776,   777,   780,  -689,  -689,   842,   797,   750,   854,   802,
     877,   884,   887,   782,  -689,   889,   890,   788,  -689,  -689,
     891,   892,   791,   908,   793,  -689,   795,   798,  -689,  -689,
     895,   896,   800,  -689,  -689,   897,   810,   803,   902,   903,
     905,   907,   821,   804,   910,   911,   808,  -689,  -689,   915,
     916,   917,   813,  -689,   815,   817,   818,   819,   822,   823,
     825,   826,  -689,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   843,   844,
    -689,  -689,   918,   845,   846,  -689,   847,  -689,   117,  -689,
     920,   922,   926,   927,   849,  -689,   850,  -689,  -689,   930,
     848,   948,   852,  -689,  -689,  -689,  -689,  -689,   476,   476,
     476,   476,   476,   476,   476,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,   853,   855,   856,   -39,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   184,   868,   869,  -689,   870,   871,   872,   873,   874,
     875,   876,    -4,   878,   879,   880,   881,   882,   883,   885,
    -689,   886,   888,  -689,  -689,   893,   894,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -192,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -182,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
     899,   900,   292,   901,   904,   906,   909,   912,  -689,   913,
     914,  -689,   919,   921,    -3,   928,   923,  -689,  -689,  -689,
    -689,   924,   925,  -689,   929,   931,   450,   932,   933,   934,
     935,   936,   708,   937,   938,  -689,   939,   940,   941,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,   942,   291,  -689,  -689,   943,
     851,   944,  -689,    29,  -689,  -689,  -689,  -689,   945,   946,
     949,   950,  -689,  -689,   951,   648,   952,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -166,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,   790,   790,   790,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -149,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,   748,  -689,   668,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -146,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,   -82,  -689,   966,   908,   953,  -689,  -689,  -689,
    -689,  -689,   181,  -689,   954,  -689,  -689,  -689,  -689,   955,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,   -14,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
      74,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,    90,  -689,
    -689,   983,   -86,   958,   956,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,   125,  -689,  -689,  -689,   -39,  -689,  -689,  -689,  -689,
      -4,  -689,  -689,  -689,   292,  -689,    -3,  -689,  -689,  -689,
     984,   987,   989,  -689,   450,  -689,   708,  -689,   291,   957,
     962,   963,   307,  -689,  -689,   648,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,   132,  -689,  -689,
    -689,   307,  -689
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
      95,    94,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   625,   617,   618,   619,   620,
     621,   622,   616,   623,   624,     0,     0,     0,   456,     0,
       0,   454,   455,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,     0,   560,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   470,   471,   514,   515,   509,   510,   511,
     512,   508,   481,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   482,   483,   513,   487,   488,   489,   490,   486,
     485,   491,   499,   500,   492,   493,   494,   495,   484,   497,
     506,   507,   504,   505,   498,   496,   502,   503,   501,     0,
       0,     0,     0,     0,     0,     0,    46,    47,    48,     0,
       0,     0,   648,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   639,   640,   641,   642,   643,   646,   644,   645,
     647,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    69,    66,    64,    70,    71,    65,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   124,   125,   126,     0,     0,   347,     0,     0,
     345,   346,     0,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,     0,     0,     0,     0,   268,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,   234,   237,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   235,   236,   238,   248,   249,   250,     0,     0,
       0,     0,     0,     0,     0,   423,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   400,   401,   402,   403,
     404,   406,   405,   408,   412,   409,   410,   411,   407,   449,
       0,     0,     0,   446,   447,   448,     0,     0,   453,   464,
       0,     0,     0,   461,   462,   463,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,     0,     0,     0,   315,     0,     0,
       0,     0,     0,     0,   301,   302,   303,   304,   309,   305,
     306,   307,   308,   440,     0,     0,     0,   437,   438,   439,
       0,     0,     0,   276,     0,   286,     0,   284,   285,   287,
     288,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     103,   104,   105,     0,     0,     0,   203,     0,     0,     0,
       0,     0,   177,     0,     0,     0,   155,   156,   157,   158,
     159,   162,   163,   164,   165,   161,   160,   166,     0,     0,
       0,     0,     0,   335,   336,   337,   338,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   638,    72,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,   381,
       0,   376,   377,   378,   127,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   112,   113,   115,   114,   116,
       0,     0,   344,     0,     0,   359,     0,     0,   352,   353,
     354,   355,     0,     0,     0,    90,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   613,   251,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   232,   413,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,     0,     0,     0,   445,     0,
     452,     0,     0,     0,   460,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   467,   310,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,   436,   289,
       0,     0,     0,     0,     0,   283,     0,     0,    44,   106,
       0,     0,     0,   102,   167,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   339,     0,
       0,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,   637,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   379,     0,     0,     0,   375,     0,   122,     0,   117,
       0,     0,     0,     0,     0,   111,     0,   343,   356,     0,
       0,     0,     0,   351,    99,    98,    97,   635,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   636,   627,   628,
     629,   630,   631,   632,   634,   633,     0,     0,     0,     0,
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
     650,   649,   655,   653,   656,   651,   652,   654,    86,    81,
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
    -689,  -689,  -689,  -246,  -298,  -688,  -624,  -689,  -689,   964,
    -689,  -689,  -689,  -689,   947,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  1038,  -689,  -689,  -689,  -689,  -689,
    -689,   627,  -689,  -689,  -689,  -689,  -689,   543,  -689,  -689,
    -689,  -689,  -689,  -689,   959,  -689,  -689,  -689,  -689,    -6,
    -689,  -689,  -689,  -689,  -689,  -171,  -689,  -689,  -689,   616,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -134,  -689,  -689,  -689,  -131,  -689,  -689,  -689,
     807,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -108,  -689,  -689,  -689,  -689,  -689,  -118,  -689,   654,  -689,
    -689,  -689,    -2,  -689,  -689,  -689,  -689,  -689,   688,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -112,  -689,  -689,  -689,
    -689,  -689,  -689,   613,  -689,  -689,  -689,  -689,  -689,   960,
    -689,  -689,  -689,  -689,   553,  -689,  -689,  -689,  -689,  -689,
    -122,  -689,  -689,  -689,   587,  -689,  -689,  -689,  -689,  -113,
    -689,  -689,  -689,   961,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,   -92,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,   685,  -689,  -689,  -689,  -689,  -689,
     965,  -689,  -689,  -689,  -689,  1043,  -689,  -689,  -689,  -689,
     781,  -689,  -689,  -689,  -689,   994,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
      75,  -689,  -689,  -689,    80,  -689,  -689,  -689,  -689,  -689,
    1076,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689,  -689,   967,  -689,  -689,  -689,  -689,  -689,  -689,
    -689,  -689
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   815,   816,  1076,  1077,    27,   215,   216,
     217,   218,    28,   259,   260,   261,   262,   263,   264,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,    29,    77,    78,    79,    80,    81,    30,    63,
     489,   490,   491,   492,    31,    70,   574,   575,   576,   577,
     578,   579,    32,   281,   282,   283,   284,   285,  1033,  1034,
    1035,  1036,  1037,  1213,  1287,  1288,    33,    64,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     743,  1190,  1191,   517,   737,  1161,  1162,    34,    53,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   612,  1060,
    1061,    35,    61,   475,   722,  1132,  1133,   476,   477,   478,
    1136,   976,   977,   479,   480,    36,    59,   453,   454,   455,
     456,   457,   458,   459,   707,  1118,  1119,   460,   461,   462,
      37,    65,   522,   523,   524,   525,   526,    38,   289,   290,
     291,    39,    72,   587,   588,   589,   590,   591,   800,  1231,
    1232,    40,    68,   560,   561,   562,   563,   783,  1208,  1209,
      41,    54,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   635,  1089,  1090,   374,   375,   376,   377,
     378,    42,    60,   466,   467,   468,   469,    43,    55,   382,
     383,   384,   385,    44,   110,   111,   112,    45,    57,   392,
     393,   394,   395,    46,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   423,   938,
     939,   205,   421,   913,   914,   206,   207,   208,    47,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    48,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     842,   843,   598,   279,  1087,   601,   108,   603,   604,  1058,
     689,   557,   379,   486,   690,    73,   379,   108,   841,   486,
     518,   241,   691,   114,   463,    51,   692,    52,   115,   116,
    1029,   117,   118,  1102,   212,   293,   119,  1103,    56,   463,
      58,  1129,    74,  1104,   120,   121,   242,  1105,   243,   279,
      75,    62,   122,    49,    50,   123,   124,   125,   519,  1234,
      66,    73,   126,  1235,   109,   389,   583,   557,   287,    67,
     380,    69,   287,   244,   380,   109,  1239,   127,   128,  1243,
    1240,  1059,   245,  1244,   518,   444,   129,   487,    74,   130,
     131,   846,   847,   487,   520,   470,    75,    71,   132,   656,
     105,   658,   659,   445,   246,   133,   558,   134,   247,   135,
      76,   136,   669,   137,   138,  1260,   248,   674,  1029,   249,
     250,   446,   519,   106,   139,  1030,   213,   684,   685,   140,
     141,   142,   381,   143,   144,   145,   381,   107,   146,   698,
     521,   700,   701,  1245,   464,   447,   471,  1246,   214,   251,
     348,   113,   349,   472,   350,   473,    76,   209,   520,   464,
     390,   584,   558,   288,   147,   583,   252,   288,   351,   253,
     254,   255,  -129,   311,   148,   149,   150,   151,   152,   153,
     154,   210,   488,  1130,   569,   391,   352,   493,   488,   312,
     313,  1088,  1131,   314,   211,  1073,  1074,  1075,   448,   219,
     220,   353,   389,   354,   521,   494,   449,   450,   221,   278,
     355,  1253,   474,  1030,   286,  1254,   256,   292,  -129,   280,
    1031,   356,   212,   495,   481,   559,   222,   451,   566,   294,
     155,   156,   157,   315,   158,   159,   761,   647,   732,   257,
     258,   465,   387,   160,  1032,   357,   555,   496,   442,   717,
     316,   317,   318,   319,   320,  1214,   465,   223,   321,   484,
     584,   568,   322,   295,   296,   280,   224,   358,   323,   225,
     226,    82,   299,   300,   227,   228,   229,   324,   325,   570,
     585,   559,   497,   586,   301,   302,   297,   359,   841,   326,
     653,   802,   784,   581,    83,    84,   360,   390,   230,  1255,
     498,    85,   452,  1256,   303,   304,   493,  1108,  1031,   752,
     713,   327,   537,   828,   213,  1257,   499,   444,   833,  1258,
     724,   836,   391,   470,   494,   840,   305,    86,    87,   306,
    1109,   307,  1032,   500,   501,   445,   214,   308,   386,    88,
      89,    90,   495,   396,   397,   361,   571,    91,    92,   398,
    1264,   399,   400,   446,  1265,   328,  1198,  1290,  1110,   401,
     569,  1291,   402,   403,   572,   404,   496,   405,   362,   406,
    1279,   407,  1280,   408,   471,   643,   409,   447,   410,   585,
     573,   472,   586,   473,   502,  1236,  1237,  1238,   411,  1111,
    1112,   412,   564,   413,   114,  1113,   414,   415,   626,   115,
     116,   497,   117,   118,   503,   416,   417,   119,   504,   794,
     418,  1250,   746,   419,   597,   120,   121,  1281,  1199,   498,
    1114,   420,   422,   122,   424,   425,   123,   124,   125,   596,
     448,   426,   427,   126,  1282,   499,  1115,   428,   449,   450,
     474,   808,   809,   810,   811,   812,   813,   814,   127,   128,
    1200,   535,   500,   501,  1141,   570,   429,   129,  1201,   451,
     130,   131,   430,   431,   432,   433,   434,  1202,   435,   132,
    1142,   436,   437,  1283,  1284,   438,   133,   439,   134,  1143,
     135,   440,   136,   441,   137,   138,   482,   483,   527,   222,
     528,  1203,   241,  1204,  1205,   139,   309,   529,  1116,   530,
     140,   141,   142,   502,   143,   144,   145,  1206,   531,   146,
     532,   533,   534,  1144,  1207,  1145,  1117,   242,   538,   243,
     223,   539,   571,   503,   540,  1285,   541,   504,   542,   224,
    1286,   543,   225,   226,   452,   147,   544,   227,   228,   229,
     572,   545,   546,  1146,   244,   148,   149,   150,   151,   152,
     153,   154,   547,   245,   548,   549,   573,   550,   551,   552,
     553,   230,  1048,  1049,  1050,  1051,  1052,  1053,  1054,   554,
     565,   580,   592,   593,  1147,   246,  1148,   594,   595,   247,
     597,   599,   600,   602,   605,   606,   607,   248,  1261,   608,
     249,   250,   628,   609,   610,  1149,   611,   613,   614,   615,
     616,   155,   156,   157,   617,   158,   159,   348,   618,   349,
     619,   350,   620,   621,   160,   622,   623,  1150,   624,   625,
     251,   649,  1151,   629,   630,   351,  1152,   631,   632,   633,
    1153,   634,     2,     3,   636,  1154,     4,   252,   637,  1155,
     253,   254,   255,   352,   638,   639,   640,   641,     5,   642,
    1156,     6,     7,  1157,   645,  1158,   646,   650,   353,     8,
     354,   651,   652,   655,   657,   661,  1159,   355,   660,   662,
     663,     9,   664,  1160,    10,    11,   665,   666,   356,   667,
     668,   670,   671,   672,   673,   675,   676,   256,   677,   678,
     679,   680,    12,   681,   682,    13,   683,   686,   697,   687,
     311,   688,   357,   693,   694,   695,    14,   696,   699,   703,
     257,   258,   916,  1221,   917,   918,   312,   313,   702,   726,
     314,   705,   727,   706,   358,   754,    15,    16,   704,   757,
     763,   764,   708,   709,   710,   711,   712,   715,   716,   719,
     720,   721,    17,   723,   359,   728,   729,   730,   734,   748,
     731,   755,  1168,   360,  1169,  1170,   735,   736,   738,    18,
     315,   739,   740,   741,   742,   744,   745,   749,   750,   751,
     756,   758,    19,    20,   759,  1222,   760,   316,   317,   318,
     319,   320,   762,   765,   766,   321,   767,   768,   769,   322,
     770,   771,   893,   772,   773,   323,    21,   774,   775,   776,
     777,   782,   361,   778,   324,   325,   779,  1223,   780,    22,
     796,   781,   786,   787,    23,  1224,   326,   788,   789,    24,
     790,   797,    25,   791,  1225,   362,   792,   793,   919,   920,
     921,   826,   798,   922,   923,   827,   924,   925,   327,   926,
     830,   927,   799,   801,   928,   804,   929,   930,  1226,   805,
    1227,  1228,   931,   806,   807,   817,   932,   831,   818,   819,
     933,   934,   935,   820,  1229,   821,   822,   936,  1171,  1172,
    1173,  1230,   937,  1174,  1175,   823,  1176,  1177,   824,  1178,
     825,  1179,   328,   832,  1180,   829,  1181,  1182,   834,   835,
     837,   838,  1183,   839,   841,   844,  1184,   845,   855,    82,
    1185,  1186,  1187,   849,   852,   848,   964,  1188,   894,   895,
     896,   850,  1189,   897,   898,   851,   899,   900,   853,   901,
     854,   902,    83,    84,   903,   856,   904,   905,   857,    85,
     858,   859,   906,   861,   860,   862,   907,   863,   864,   865,
     908,   909,   910,   866,   867,   868,   869,   911,   870,   871,
     872,   873,   912,   874,   875,    86,    87,   876,   877,   878,
     879,   960,   880,   881,   882,   883,   884,    88,    89,    90,
     885,   886,   887,   963,   888,    91,    92,   889,   962,   890,
     891,   892,   915,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   950,   951,   952,   965,   953,   954,   955,
     956,   957,   958,   966,   961,   959,   967,   968,   969,   970,
     972,   973,   975,   971,   981,   982,   984,   985,   978,   974,
     979,   987,   988,   980,   989,   983,   990,  1215,   991,   993,
     994,   986,   992,   995,   996,   997,   998,  1025,   999,  1038,
    1000,  1039,  1001,  1002,  1003,  1040,  1041,  1004,  1005,  1044,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1046,  1023,  1024,
    1247,  1027,  1028,  1026,  1042,  1043,  1045,  1047,  1055,  1211,
    1056,  1057,  1062,  1063,  1064,  1065,  1066,  1067,  1068,  1069,
    1070,  1071,  1072,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1259,  1091,  1092,  1093,  1094,  1095,  1096,  1270,
    1097,  1098,  1271,  1099,  1272,   298,   733,   795,  1100,  1101,
    1292,   747,  1274,  1273,  1106,  1107,  1120,  1266,  1269,  1121,
     725,  1122,  1268,  1248,  1123,   753,   627,  1124,  1125,  1126,
     803,   714,  1134,  1289,  1127,  1275,  1128,   785,  1267,  1137,
    1138,   718,  1135,   388,  1139,   443,  1140,  1163,  1164,  1165,
    1166,  1167,  1192,  1193,  1194,  1195,  1196,  1197,  1210,   310,
    1216,  1217,  1212,   654,  1218,  1219,  1220,  1233,  1249,   485,
    1242,  1263,  1276,  1241,  1251,  1252,  1262,  1277,  1278,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   536,     0,
       0,     0,     0,     0,     0,     0,   556,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     567,     0,     0,     0,     0,     0,     0,     0,     0,   582,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   644,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   648
};

static const yytype_int16 yycheck[] =
{
     624,   625,   300,     1,     8,   303,     1,   305,   306,    48,
     207,     1,     1,     1,   211,     1,     1,     1,   104,     1,
       1,     1,   207,     1,     1,   227,   211,   227,     6,     7,
       1,     9,    10,   225,     1,   225,    14,   229,   227,     1,
     227,    44,    28,   225,    22,    23,    26,   229,    28,     1,
      36,   227,    30,   225,   226,    33,    34,    35,    39,   225,
     227,     1,    40,   229,    59,     1,     1,     1,     1,   227,
      59,   227,     1,    53,    59,    59,   225,    55,    56,   225,
     229,   120,    62,   229,     1,     1,    64,    75,    28,    67,
      68,   174,   175,    75,    75,     1,    36,   227,    76,   397,
     227,   399,   400,    19,    84,    83,    96,    85,    88,    87,
      96,    89,   410,    91,    92,   201,    96,   415,     1,    99,
     100,    37,    39,   227,   102,    96,    93,   425,   426,   107,
     108,   109,   121,   111,   112,   113,   121,   227,   116,   437,
     121,   439,   440,   225,   121,    61,    52,   229,   115,   129,
       1,   227,     3,    59,     5,    61,    96,   227,    75,   121,
      96,    96,    96,    96,   142,     1,   146,    96,    19,   149,
     150,   151,   170,     1,   152,   153,   154,   155,   156,   157,
     158,   227,   170,   186,     1,   121,    37,     1,   170,    17,
      18,   195,   195,    21,   227,    11,    12,    13,   114,   227,
     227,    52,     1,    54,   121,    19,   122,   123,   227,   227,
      61,   225,   118,    96,   227,   229,   196,   227,   170,   217,
     191,    72,     1,    37,   225,   215,     1,   143,   226,   228,
     208,   209,   210,    61,   212,   213,   534,   226,   226,   219,
     220,   218,   226,   221,   215,    96,   226,    61,   226,   226,
      78,    79,    80,    81,    82,   226,   218,    32,    86,   226,
      96,   170,    90,   228,   228,   217,    41,   118,    96,    44,
      45,     1,   228,   228,    49,    50,    51,   105,   106,    96,
     215,   215,    96,   218,   228,   228,   226,   138,   104,   117,
     226,   226,   226,   226,    24,    25,   147,    96,    73,   225,
     114,    31,   218,   229,   228,   228,     1,    15,   191,   226,
     226,   139,   225,   611,    93,   225,   130,     1,   616,   229,
     226,   619,   121,     1,    19,   623,   228,    57,    58,   228,
      38,   228,   215,   147,   148,    19,   115,   228,   228,    69,
      70,    71,    37,   228,   228,   196,   163,    77,    78,   228,
     225,   228,   228,    37,   229,   183,    65,   225,    66,   228,
       1,   229,   228,   228,   181,   228,    61,   228,   219,   228,
      63,   228,    65,   228,    52,   226,   228,    61,   228,   215,
     197,    59,   218,    61,   198,  1073,  1074,  1075,   228,    97,
      98,   228,   225,   228,     1,   103,   228,   228,   226,     6,
       7,    96,     9,    10,   218,   228,   228,    14,   222,   226,
     228,   230,   226,   228,   104,    22,    23,   110,   127,   114,
     128,   228,   228,    30,   228,   228,    33,    34,    35,   104,
     114,   228,   228,    40,   127,   130,   144,   228,   122,   123,
     118,   131,   132,   133,   134,   135,   136,   137,    55,    56,
     159,   226,   147,   148,     4,    96,   228,    64,   167,   143,
      67,    68,   228,   228,   228,   228,   228,   176,   228,    76,
      20,   228,   228,   166,   167,   228,    83,   228,    85,    29,
      87,   228,    89,   228,    91,    92,   228,   228,   228,     1,
     228,   200,     1,   202,   203,   102,   226,   228,   206,   228,
     107,   108,   109,   198,   111,   112,   113,   216,   228,   116,
     228,   228,   228,    63,   223,    65,   224,    26,   228,    28,
      32,   228,   163,   218,   228,   218,   228,   222,   228,    41,
     223,   228,    44,    45,   218,   142,   228,    49,    50,    51,
     181,   228,   228,    93,    53,   152,   153,   154,   155,   156,
     157,   158,   228,    62,   228,   228,   197,   228,   228,   228,
     228,    73,   808,   809,   810,   811,   812,   813,   814,   228,
     228,   228,   119,   119,   124,    84,   126,   119,   225,    88,
     104,   207,   104,   104,   104,   104,   225,    96,  1212,   225,
      99,   100,   225,   228,   228,   145,   228,   228,   228,   228,
     228,   208,   209,   210,   228,   212,   213,     1,   228,     3,
     228,     5,   228,   228,   221,   228,   228,   167,   228,   228,
     129,   119,   172,   228,   228,    19,   176,   228,   228,   228,
     180,   228,     0,     1,   228,   185,     4,   146,   228,   189,
     149,   150,   151,    37,   228,   228,   228,   228,    16,   228,
     200,    19,    20,   203,   228,   205,   228,   225,    52,    27,
      54,   228,   228,   207,   104,   104,   216,    61,   207,   207,
     104,    39,   104,   223,    42,    43,   104,   207,    72,   207,
     207,   104,   104,   104,   104,   104,   104,   196,   104,   104,
     207,   228,    60,   207,   228,    63,   207,   207,   104,   207,
       1,   207,    96,   207,   207,   207,    74,   207,   207,   225,
     219,   220,    44,    65,    46,    47,    17,    18,   207,   119,
      21,   228,   119,   228,   118,   207,    94,    95,   225,   119,
     104,   119,   228,   228,   228,   228,   228,   228,   228,   225,
     228,   228,   110,   228,   138,   225,   225,   228,   225,   225,
     228,   207,    44,   147,    46,    47,   228,   228,   228,   127,
      61,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     207,   207,   140,   141,   207,   127,   207,    78,    79,    80,
      81,    82,   225,   207,   119,    86,   104,   104,   119,    90,
     119,   119,    44,   119,   119,    96,   164,   119,   119,   119,
     119,   228,   196,   119,   105,   106,   119,   159,   225,   177,
     119,   225,   207,   225,   182,   167,   117,   227,   225,   187,
     228,   225,   190,   228,   176,   219,   228,   228,   160,   161,
     162,   104,   225,   165,   166,   104,   168,   169,   139,   171,
     104,   173,   228,   228,   176,   225,   178,   179,   200,   225,
     202,   203,   184,   225,   225,   225,   188,   104,   225,   225,
     192,   193,   194,   225,   216,   225,   225,   199,   160,   161,
     162,   223,   204,   165,   166,   225,   168,   169,   225,   171,
     225,   173,   183,   104,   176,   228,   178,   179,   104,   104,
     119,   104,   184,   104,   104,   225,   188,   119,   104,     1,
     192,   193,   194,   207,   228,   119,   104,   199,   160,   161,
     162,   119,   204,   165,   166,   119,   168,   169,   119,   171,
     119,   173,    24,    25,   176,   119,   178,   179,   119,    31,
     119,   119,   184,   119,   225,   119,   188,   225,   225,   119,
     192,   193,   194,   119,   225,   225,   225,   199,   225,   225,
     225,   225,   204,   225,   225,    57,    58,   225,   225,   225,
     225,   119,   225,   225,   225,   225,   225,    69,    70,    71,
     225,   225,   225,   119,   225,    77,    78,   225,   228,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   119,   225,   225,   225,
     225,   225,   225,   119,   207,   225,   119,   225,   119,   119,
     119,   119,   104,   225,   119,   119,   119,   207,   225,   228,
     225,   119,   119,   225,   119,   225,   119,  1033,   207,   119,
     119,   228,   228,   225,   119,   119,   119,   119,   225,   119,
     225,   119,   225,   225,   225,   119,   119,   225,   225,   119,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   119,   225,   225,
     104,   225,   225,   228,   225,   225,   228,   225,   225,   228,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   119,   225,   225,   225,   225,   225,   225,   125,
     225,   225,   125,   225,   125,    77,   489,   574,   225,   225,
    1291,   505,  1256,  1254,   225,   225,   225,  1235,  1246,   225,
     476,   225,  1244,  1135,   225,   522,   329,   225,   225,   225,
     587,   453,   214,  1265,   225,  1258,   225,   560,  1240,   225,
     225,   466,   229,   110,   225,   161,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,    93,
     225,   225,   228,   392,   225,   225,   225,   225,   225,   215,
    1105,   225,   225,  1103,   230,   230,   228,   225,   225,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     281,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   289,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   363,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   382
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   232,     0,     1,     4,    16,    19,    20,    27,    39,
      42,    43,    60,    63,    74,    94,    95,   110,   127,   140,
     141,   164,   177,   182,   187,   190,   233,   238,   243,   263,
     269,   275,   283,   297,   318,   342,   356,   371,   378,   382,
     392,   401,   422,   428,   434,   438,   444,   499,   512,   225,
     226,   227,   227,   319,   402,   429,   227,   439,   227,   357,
     423,   343,   227,   270,   298,   372,   227,   227,   393,   227,
     276,   227,   383,     1,    28,    36,    96,   264,   265,   266,
     267,   268,     1,    24,    25,    31,    57,    58,    69,    70,
      71,    77,    78,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   227,   227,   227,     1,    59,
     435,   436,   437,   227,     1,     6,     7,     9,    10,    14,
      22,    23,    30,    33,    34,    35,    40,    55,    56,    64,
      67,    68,    76,    83,    85,    87,    89,    91,    92,   102,
     107,   108,   109,   111,   112,   113,   116,   142,   152,   153,
     154,   155,   156,   157,   158,   208,   209,   210,   212,   213,
     221,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   492,   496,   497,   498,   227,
     227,   227,     1,    93,   115,   239,   240,   241,   242,   227,
     227,   227,     1,    32,    41,    44,    45,    49,    50,    51,
      73,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,     1,    26,    28,    53,    62,    84,    88,    96,    99,
     100,   129,   146,   149,   150,   151,   196,   219,   220,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   227,     1,
     217,   284,   285,   286,   287,   288,   227,     1,    96,   379,
     380,   381,   227,   225,   228,   228,   228,   226,   265,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   226,
     501,     1,    17,    18,    21,    61,    78,    79,    80,    81,
      82,    86,    90,    96,   105,   106,   117,   139,   183,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,     1,     3,
       5,    19,    37,    52,    54,    61,    72,    96,   118,   138,
     147,   196,   219,   403,   404,   405,   406,   407,   408,   409,
     410,   411,   412,   413,   417,   418,   419,   420,   421,     1,
      59,   121,   430,   431,   432,   433,   228,   226,   436,     1,
      96,   121,   440,   441,   442,   443,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   493,   228,   489,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   226,   446,     1,    19,    37,    61,   114,   122,
     123,   143,   218,   358,   359,   360,   361,   362,   363,   364,
     368,   369,   370,     1,   121,   218,   424,   425,   426,   427,
       1,    52,    59,    61,   118,   344,   348,   349,   350,   354,
     355,   225,   228,   228,   226,   240,     1,    75,   170,   271,
     272,   273,   274,     1,    19,    37,    61,    96,   114,   130,
     147,   148,   198,   218,   222,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   314,     1,    39,
      75,   121,   373,   374,   375,   376,   377,   228,   228,   228,
     228,   228,   228,   228,   228,   226,   514,   225,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   226,   245,     1,    96,   215,
     394,   395,   396,   397,   225,   228,   226,   285,   170,     1,
      96,   163,   181,   197,   277,   278,   279,   280,   281,   282,
     228,   226,   380,     1,    96,   215,   218,   384,   385,   386,
     387,   388,   119,   119,   119,   225,   104,   104,   235,   207,
     104,   235,   104,   235,   235,   104,   104,   225,   225,   228,
     228,   228,   339,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   226,   321,   225,   228,
     228,   228,   228,   228,   228,   414,   228,   228,   228,   228,
     228,   228,   228,   226,   404,   228,   228,   226,   431,   119,
     225,   228,   228,   226,   441,   207,   235,   104,   235,   235,
     207,   104,   207,   104,   104,   104,   207,   207,   207,   235,
     104,   104,   104,   104,   235,   104,   104,   104,   104,   207,
     228,   207,   228,   207,   235,   235,   207,   207,   207,   207,
     211,   207,   211,   207,   207,   207,   207,   104,   235,   207,
     235,   235,   207,   225,   225,   228,   228,   365,   228,   228,
     228,   228,   228,   226,   359,   228,   228,   226,   425,   225,
     228,   228,   345,   228,   226,   349,   119,   119,   225,   225,
     228,   228,   226,   272,   225,   228,   228,   315,   228,   228,
     228,   228,   228,   311,   228,   228,   226,   300,   225,   228,
     228,   228,   226,   374,   207,   207,   207,   119,   207,   207,
     207,   235,   225,   104,   119,   207,   119,   104,   104,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     225,   225,   228,   398,   226,   395,   207,   225,   227,   225,
     228,   228,   228,   228,   226,   278,   119,   225,   225,   228,
     389,   228,   226,   385,   225,   225,   225,   225,   131,   132,
     133,   134,   135,   136,   137,   234,   235,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   104,   104,   235,   228,
     104,   104,   104,   235,   104,   104,   235,   119,   104,   104,
     235,   104,   237,   237,   225,   119,   174,   175,   119,   207,
     119,   119,   228,   119,   119,   104,   119,   119,   119,   119,
     225,   119,   119,   225,   225,   119,   119,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,    44,   160,   161,   162,   165,   166,   168,
     169,   171,   173,   176,   178,   179,   184,   188,   192,   193,
     194,   199,   204,   494,   495,   225,    44,    46,    47,   160,
     161,   162,   165,   166,   168,   169,   171,   173,   176,   178,
     179,   184,   188,   192,   193,   194,   199,   204,   490,   491,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     119,   207,   228,   119,   104,   119,   119,   119,   225,   119,
     119,   225,   119,   119,   228,   104,   352,   353,   225,   225,
     225,   119,   119,   225,   119,   207,   228,   119,   119,   119,
     119,   207,   228,   119,   119,   225,   119,   119,   119,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   119,   228,   225,   225,     1,
      96,   191,   215,   289,   290,   291,   292,   293,   119,   119,
     119,   119,   225,   225,   119,   228,   119,   225,   234,   234,
     234,   234,   234,   234,   234,   225,   225,   225,    48,   120,
     340,   341,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,    11,    12,    13,   236,   237,   225,   225,
     225,   225,   225,   225,   225,   225,   225,     8,   195,   415,
     416,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   229,   225,   229,   225,   225,    15,    38,
      66,    97,    98,   103,   128,   144,   206,   224,   366,   367,
     225,   225,   225,   225,   225,   225,   225,   225,   225,    44,
     186,   195,   346,   347,   214,   229,   351,   225,   225,   225,
     225,     4,    20,    29,    63,    65,    93,   124,   126,   145,
     167,   172,   176,   180,   185,   189,   200,   203,   205,   216,
     223,   316,   317,   225,   225,   225,   225,   225,    44,    46,
      47,   160,   161,   162,   165,   166,   168,   169,   171,   173,
     176,   178,   179,   184,   188,   192,   193,   194,   199,   204,
     312,   313,   225,   225,   225,   225,   225,   225,    65,   127,
     159,   167,   176,   200,   202,   203,   216,   223,   399,   400,
     225,   228,   228,   294,   226,   290,   225,   225,   225,   225,
     225,    65,   127,   159,   167,   176,   200,   202,   203,   216,
     223,   390,   391,   225,   225,   229,   236,   236,   236,   225,
     229,   495,   491,   225,   229,   225,   229,   104,   353,   225,
     230,   230,   230,   225,   229,   225,   229,   225,   229,   119,
     201,   237,   228,   225,   225,   229,   341,   416,   367,   347,
     125,   125,   125,   317,   313,   400,   225,   225,   225,    63,
      65,   110,   127,   166,   167,   218,   223,   295,   296,   391,
     225,   229,   296
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   231,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   238,   239,   239,   240,   240,   240,
     241,   242,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   264,   265,   265,   265,   265,   266,   267,   268,
     270,   269,   271,   271,   272,   272,   272,   273,   274,   276,
     275,   277,   277,   278,   278,   278,   278,   278,   279,   280,
     281,   282,   283,   284,   284,   285,   285,   285,   286,   288,
     287,   289,   289,   290,   290,   290,   290,   291,   292,   292,
     294,   293,   295,   295,   296,   296,   296,   296,   296,   296,
     296,   296,   298,   297,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   311,   310,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   315,   314,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     319,   318,   320,   320,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   339,   338,
     340,   340,   341,   341,   343,   342,   345,   344,   346,   346,
     347,   347,   347,   348,   348,   349,   349,   349,   349,   349,
     351,   350,   352,   352,   353,   353,   354,   355,   357,   356,
     358,   358,   359,   359,   359,   359,   359,   359,   359,   359,
     359,   360,   361,   362,   363,   365,   364,   366,   366,   367,
     367,   367,   367,   367,   367,   367,   367,   367,   367,   368,
     369,   370,   372,   371,   373,   373,   374,   374,   374,   374,
     375,   376,   377,   378,   379,   379,   380,   380,   381,   383,
     382,   384,   384,   385,   385,   385,   385,   386,   387,   389,
     388,   390,   390,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   393,   392,   394,   394,   395,   395,   395,
     396,   398,   397,   399,   399,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   400,   402,   401,   403,   403,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   412,   414,   413,   415,   415,   416,   416,   417,
     418,   419,   420,   421,   423,   422,   424,   424,   425,   425,
     425,   426,   427,   429,   428,   430,   430,   431,   431,   431,
     432,   433,   434,   435,   435,   436,   436,   437,   439,   438,
     440,   440,   441,   441,   441,   442,   443,   444,   445,   445,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   473,   474,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     489,   488,   490,   490,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   493,   492,   494,   494,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     496,   497,   498,   499,   500,   500,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   513,
     514,   514,   514,   514,   514,   514,   514,   514,   514,   515,
     516,   517,   518,   519,   520,   521,   522
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4
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
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 477 "conf_parser.y" /* yacc.c:1646  */
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
#line 2995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "conf_parser.y" /* yacc.c:1646  */
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
#line 3056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 575 "conf_parser.y" /* yacc.c:1646  */
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
#line 3088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 604 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 612 "conf_parser.y" /* yacc.c:1646  */
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
#line 3116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 626 "conf_parser.y" /* yacc.c:1646  */
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
#line 3147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 654 "conf_parser.y" /* yacc.c:1646  */
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
#line 3165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 669 "conf_parser.y" /* yacc.c:1646  */
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
#line 3183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 694 "conf_parser.y" /* yacc.c:1646  */
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
#line 3213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 717 "conf_parser.y" /* yacc.c:1646  */
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
#line 3256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 745 "conf_parser.y" /* yacc.c:1646  */
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
#line 3287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 773 "conf_parser.y" /* yacc.c:1646  */
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
#line 3315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 798 "conf_parser.y" /* yacc.c:1646  */
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
#line 3340 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 820 "conf_parser.y" /* yacc.c:1646  */
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
#line 3365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3386 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 893 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 929 "conf_parser.y" /* yacc.c:1646  */
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
#line 3481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 965 "conf_parser.y" /* yacc.c:1646  */
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
#line 3529 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3538 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3547 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3571 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3579 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3596 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3605 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3614 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3623 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3632 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3641 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3650 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3659 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3680 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1086 "conf_parser.y" /* yacc.c:1646  */
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
#line 3765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3824 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3833 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3874 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3964 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1448 "conf_parser.y" /* yacc.c:1646  */
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
#line 4296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1460 "conf_parser.y" /* yacc.c:1646  */
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
#line 4344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 252:
#line 1524 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4353 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 253:
#line 1530 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4362 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1536 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1542 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4380 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1548 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1554 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1560 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1566 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1572 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1578 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1584 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1591 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1597 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1603 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1609 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4495 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1627 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4513 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1638 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1654 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1660 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1664 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 290:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
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
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1694 "conf_parser.y" /* yacc.c:1646  */
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
#line 4610 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1711 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4619 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4628 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1726 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1730 "conf_parser.y" /* yacc.c:1646  */
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
#line 4678 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 311:
#line 1779 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4687 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 312:
#line 1785 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4696 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1791 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4705 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1797 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1808 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4728 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1815 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4737 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1819 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4755 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4809 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1857 "conf_parser.y" /* yacc.c:1646  */
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
#line 4835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1871 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1880 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1893 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1900 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 340:
#line 1911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 341:
#line 1917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1923 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 348:
#line 1938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4924 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 349:
#line 1953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1964 "conf_parser.y" /* yacc.c:1646  */
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
#line 4957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 357:
#line 1981 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 358:
#line 1987 "conf_parser.y" /* yacc.c:1646  */
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
#line 4988 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 2006 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2013 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5033 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5042 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5060 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2067 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 380:
#line 2082 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 381:
#line 2088 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2099 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2140 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2149 "conf_parser.y" /* yacc.c:1646  */
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
#line 5304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 414:
#line 2229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5313 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 415:
#line 2235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5322 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2247 "conf_parser.y" /* yacc.c:1646  */
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
#line 5347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2260 "conf_parser.y" /* yacc.c:1646  */
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
#line 5363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2295 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2311 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5466 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2340 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2359 "conf_parser.y" /* yacc.c:1646  */
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
#line 5514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 441:
#line 2384 "conf_parser.y" /* yacc.c:1646  */
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
#line 5537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 442:
#line 2404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2413 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2417 "conf_parser.y" /* yacc.c:1646  */
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
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 450:
#line 2443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 451:
#line 2449 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 457:
#line 2463 "conf_parser.y" /* yacc.c:1646  */
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
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 458:
#line 2480 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2484 "conf_parser.y" /* yacc.c:1646  */
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
#line 5647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 465:
#line 2506 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 466:
#line 2512 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 517:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5673 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2579 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5681 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2584 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5714 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5738 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5746 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5762 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5770 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5778 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5843 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5851 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2709 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2714 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5923 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5955 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_pass_resv = yylval.number;
}
#line 5963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5971 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5979 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5995 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2793 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2796 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2799 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6051 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2805 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6067 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6123 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6131 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6139 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2861 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6203 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2867 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6211 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2870 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2873 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2879 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6267 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6275 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6283 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6299 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6323 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6347 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6363 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2929 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6371 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6387 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6395 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6443 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3043 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3055 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
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
#line 6533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6551 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6555 "conf_parser.c" /* yacc.c:1646  */
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
