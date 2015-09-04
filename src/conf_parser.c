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
    GECOS = 298,
    GENERAL = 299,
    HIDDEN = 300,
    HIDDEN_NAME = 301,
    HIDE_CHANS = 302,
    HIDE_IDLE = 303,
    HIDE_IDLE_FROM_OPERS = 304,
    HIDE_SERVER_IPS = 305,
    HIDE_SERVERS = 306,
    HIDE_SERVICES = 307,
    HOST = 308,
    HUB = 309,
    HUB_MASK = 310,
    IGNORE_BOGUS_TS = 311,
    INVISIBLE_ON_CONNECT = 312,
    INVITE_CLIENT_COUNT = 313,
    INVITE_CLIENT_TIME = 314,
    IP = 315,
    IRCD_AUTH = 316,
    IRCD_FLAGS = 317,
    IRCD_SID = 318,
    JOIN = 319,
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
    NO_OPER_FLOOD = 359,
    NO_TILDE = 360,
    NUMBER = 361,
    NUMBER_PER_CIDR = 362,
    NUMBER_PER_IP = 363,
    OPER_ONLY_UMODES = 364,
    OPER_UMODES = 365,
    OPERATOR = 366,
    OPERS_BYPASS_CALLERID = 367,
    PACE_WAIT = 368,
    PACE_WAIT_SIMPLE = 369,
    PASSWORD = 370,
    PATH = 371,
    PING_COOKIE = 372,
    PING_TIME = 373,
    PORT = 374,
    QSTRING = 375,
    RANDOM_IDLE = 376,
    REASON = 377,
    REDIRPORT = 378,
    REDIRSERV = 379,
    REHASH = 380,
    REMOTE = 381,
    REMOTEBAN = 382,
    RESV = 383,
    RESV_EXEMPT = 384,
    RSA_PRIVATE_KEY_FILE = 385,
    RSA_PUBLIC_KEY_FILE = 386,
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
#define GECOS 298
#define GENERAL 299
#define HIDDEN 300
#define HIDDEN_NAME 301
#define HIDE_CHANS 302
#define HIDE_IDLE 303
#define HIDE_IDLE_FROM_OPERS 304
#define HIDE_SERVER_IPS 305
#define HIDE_SERVERS 306
#define HIDE_SERVICES 307
#define HOST 308
#define HUB 309
#define HUB_MASK 310
#define IGNORE_BOGUS_TS 311
#define INVISIBLE_ON_CONNECT 312
#define INVITE_CLIENT_COUNT 313
#define INVITE_CLIENT_TIME 314
#define IP 315
#define IRCD_AUTH 316
#define IRCD_FLAGS 317
#define IRCD_SID 318
#define JOIN 319
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
#define NO_OPER_FLOOD 359
#define NO_TILDE 360
#define NUMBER 361
#define NUMBER_PER_CIDR 362
#define NUMBER_PER_IP 363
#define OPER_ONLY_UMODES 364
#define OPER_UMODES 365
#define OPERATOR 366
#define OPERS_BYPASS_CALLERID 367
#define PACE_WAIT 368
#define PACE_WAIT_SIMPLE 369
#define PASSWORD 370
#define PATH 371
#define PING_COOKIE 372
#define PING_TIME 373
#define PORT 374
#define QSTRING 375
#define RANDOM_IDLE 376
#define REASON 377
#define REDIRPORT 378
#define REDIRSERV 379
#define REHASH 380
#define REMOTE 381
#define REMOTEBAN 382
#define RESV 383
#define RESV_EXEMPT 384
#define RSA_PRIVATE_KEY_FILE 385
#define RSA_PUBLIC_KEY_FILE 386
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
#define YYLAST   1248

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
    1065,  1069,  1080,  1079,  1168,  1168,  1169,  1170,  1171,  1172,
    1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,  1182,  1188,
    1194,  1200,  1206,  1217,  1223,  1229,  1240,  1247,  1246,  1252,
    1252,  1253,  1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,
    1289,  1293,  1297,  1301,  1305,  1309,  1313,  1317,  1321,  1325,
    1329,  1333,  1337,  1344,  1343,  1349,  1349,  1350,  1354,  1358,
    1362,  1366,  1370,  1374,  1378,  1382,  1386,  1390,  1394,  1398,
    1402,  1406,  1410,  1414,  1418,  1422,  1426,  1430,  1434,  1438,
    1442,  1446,  1450,  1454,  1458,  1469,  1468,  1525,  1525,  1526,
    1527,  1528,  1529,  1530,  1531,  1532,  1533,  1534,  1535,  1536,
    1537,  1538,  1538,  1539,  1540,  1541,  1542,  1544,  1550,  1556,
    1562,  1568,  1574,  1580,  1586,  1592,  1598,  1604,  1611,  1617,
    1623,  1629,  1638,  1648,  1647,  1653,  1653,  1654,  1658,  1669,
    1668,  1675,  1674,  1679,  1679,  1680,  1684,  1688,  1694,  1694,
    1695,  1695,  1695,  1695,  1695,  1697,  1697,  1699,  1699,  1701,
    1714,  1731,  1737,  1747,  1746,  1788,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1797,  1799,  1805,  1811,  1817,
    1829,  1828,  1834,  1834,  1835,  1839,  1843,  1847,  1851,  1855,
    1859,  1863,  1867,  1871,  1877,  1891,  1900,  1914,  1913,  1928,
    1928,  1929,  1929,  1929,  1929,  1931,  1937,  1943,  1953,  1955,
    1955,  1956,  1956,  1958,  1974,  1973,  1998,  1998,  1999,  1999,
    1999,  1999,  2001,  2007,  2027,  2026,  2032,  2032,  2033,  2037,
    2041,  2045,  2049,  2053,  2057,  2061,  2065,  2069,  2079,  2078,
    2099,  2099,  2100,  2100,  2100,  2102,  2109,  2108,  2114,  2114,
    2115,  2119,  2123,  2127,  2131,  2135,  2139,  2143,  2147,  2151,
    2161,  2160,  2232,  2232,  2233,  2234,  2235,  2236,  2237,  2238,
    2239,  2240,  2241,  2242,  2243,  2244,  2245,  2246,  2247,  2249,
    2255,  2261,  2267,  2280,  2293,  2299,  2305,  2309,  2316,  2315,
    2320,  2320,  2321,  2325,  2331,  2342,  2348,  2354,  2360,  2376,
    2375,  2401,  2401,  2402,  2402,  2402,  2404,  2424,  2434,  2433,
    2460,  2460,  2461,  2461,  2461,  2463,  2469,  2478,  2480,  2480,
    2481,  2481,  2483,  2501,  2500,  2523,  2523,  2524,  2524,  2524,
    2526,  2532,  2541,  2544,  2544,  2545,  2546,  2547,  2548,  2549,
    2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,  2558,  2559,
    2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,
    2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,  2578,  2579,
    2580,  2581,  2582,  2583,  2584,  2585,  2586,  2587,  2588,  2589,
    2590,  2593,  2598,  2603,  2608,  2614,  2619,  2624,  2629,  2634,
    2639,  2644,  2649,  2654,  2659,  2664,  2669,  2674,  2679,  2684,
    2690,  2695,  2700,  2705,  2710,  2715,  2720,  2725,  2728,  2733,
    2736,  2741,  2746,  2751,  2756,  2761,  2766,  2771,  2776,  2781,
    2786,  2791,  2796,  2802,  2801,  2806,  2806,  2807,  2810,  2813,
    2816,  2819,  2822,  2825,  2828,  2831,  2834,  2837,  2840,  2843,
    2846,  2849,  2852,  2855,  2858,  2861,  2864,  2867,  2870,  2876,
    2875,  2880,  2880,  2881,  2884,  2887,  2890,  2893,  2896,  2899,
    2902,  2905,  2908,  2911,  2914,  2917,  2920,  2923,  2926,  2929,
    2932,  2935,  2938,  2943,  2948,  2953,  2962,  2965,  2965,  2966,
    2967,  2968,  2969,  2970,  2971,  2972,  2973,  2974,  2975,  2976,
    2978,  2983,  2988,  2993,  2998,  3003,  3008,  3013,  3018,  3023,
    3031,  3034,  3034,  3035,  3036,  3037,  3038,  3039,  3040,  3041,
    3042,  3043,  3045,  3051,  3057,  3063,  3069,  3078,  3093,  3099
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
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "GECOS", "GENERAL", "HIDDEN",
  "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB",
  "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE",
  "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPOOF", "SPOOF_NOTICE", "SQUIT", "SSL_CERTIFICATE_FILE",
  "SSL_CERTIFICATE_FINGERPRINT", "SSL_CONNECTION_REQUIRED",
  "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
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
     475,   476,   477,   478,   479,   480,    59,   125,   123,    61,
      44,    58
};
# endif

#define YYPACT_NINF -719

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-719)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -719,   673,  -719,  -160,  -224,  -212,  -719,  -719,  -719,  -206,
    -719,  -203,  -719,  -719,  -719,  -196,  -719,  -719,  -719,  -187,
    -171,  -719,  -164,  -719,  -155,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,   318,   918,  -148,  -143,  -141,     8,   -86,   403,   -77,
     -69,   -61,     2,   -39,   -26,   -23,   758,   536,   -20,    30,
     -15,    12,    24,  -178,   -33,    15,    33,    41,  -719,  -719,
    -719,  -719,  -719,    40,    45,    53,    56,    58,    86,    94,
      97,   116,   119,   192,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,   714,   530,    22,  -719,   125,
      14,  -719,  -719,   220,  -719,   127,   128,   129,   130,   131,
     132,   134,   136,   137,   138,   144,   146,   147,   148,   150,
     152,   154,   157,   159,   160,   161,   162,   164,   166,   168,
    -719,  -719,   170,   171,   174,   176,   178,   182,   186,   191,
     193,   195,   200,   201,   204,   212,   213,   214,   217,   218,
      20,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,   308,    38,   334,
      54,   219,   221,     5,  -719,  -719,  -719,    16,   287,   276,
    -719,   222,   225,   226,   227,   228,   229,   232,   233,   253,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,   108,
     234,   236,   237,   238,   239,   241,   242,   245,   246,   247,
     248,   249,   250,   254,   258,   260,   262,    18,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   122,   117,   266,    19,
    -719,  -719,  -719,   278,   210,  -719,   271,    52,  -719,  -719,
      37,  -719,   251,   301,   381,   277,  -719,   274,   396,   296,
     399,   396,   405,   396,   396,   408,   412,   283,  -719,   293,
     292,   294,   297,  -719,   299,   300,   303,   305,   309,   310,
     311,   315,   321,   322,   323,   324,   326,    74,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,   338,   337,   340,   342,
     343,   353,   355,  -719,   357,   358,   359,   360,   364,   365,
     366,   142,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,   367,   368,
      62,  -719,  -719,  -719,   402,   341,  -719,  -719,   369,   371,
      87,  -719,  -719,  -719,   339,   396,   495,   396,   396,   394,
     501,   400,   503,   505,   509,   410,   411,   413,   396,   514,
     517,   521,   524,   396,   525,   527,   529,   541,   428,   419,
     423,   445,   396,   396,   446,   448,   449,  -194,  -184,   450,
     452,   453,   454,   557,   396,   457,   396,   396,   459,   444,
    -719,   465,   443,   447,  -719,   451,   456,   464,   467,   468,
     187,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,   469,   470,    64,  -719,  -719,  -719,   474,   475,   476,
    -719,   477,  -719,     9,  -719,  -719,  -719,  -719,  -719,   555,
     587,   482,  -719,   483,   481,   485,    48,  -719,  -719,  -719,
     486,   489,   490,  -719,   492,   499,   500,   506,   508,  -719,
     511,   512,   145,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,   498,   513,   516,   519,   151,
    -719,  -719,  -719,  -719,   535,   544,   545,   631,   546,   547,
     550,   396,   538,  -719,  -719,   655,   642,   560,   651,   667,
     671,   658,   660,   661,   662,   663,   665,   668,   669,   670,
     672,   679,   561,  -719,   567,   576,  -719,   114,  -719,  -719,
    -719,  -719,   599,   585,  -719,   588,   591,   589,   590,   594,
     595,   102,  -719,  -719,  -719,  -719,  -719,   700,   600,  -719,
     601,   596,  -719,   602,    51,  -719,  -719,  -719,  -719,   603,
     604,   608,  -719,   609,   442,   610,   611,   616,   617,   620,
     623,   627,   633,   634,  -719,  -719,   722,   756,   396,   636,
     760,   762,   763,   396,   764,   769,   396,   754,   770,   771,
     396,   773,   773,   654,  -719,  -719,   761,   -81,   765,   674,
     766,   767,   666,   772,   780,   778,   782,   783,   785,   788,
     683,  -719,   790,   791,   687,  -719,   688,  -719,   795,   797,
     692,  -719,   697,   698,   699,   702,   707,   710,   713,   715,
     720,   723,   725,   726,   728,   729,   730,   732,   733,   734,
     738,   739,   740,   741,   743,   744,   745,   768,   678,   746,
     748,   749,   752,   753,   755,   757,   759,   774,   775,   776,
     777,   779,   781,   784,   786,   787,   789,   792,   793,  -719,
    -719,   806,   796,   751,   862,   878,   866,   867,   868,   794,
    -719,   872,   873,   798,  -719,  -719,   874,   875,   799,   890,
     800,  -719,   801,   803,  -719,  -719,   879,   886,   804,  -719,
    -719,   888,   808,   802,   889,   891,   894,   897,   813,   805,
     902,   903,   807,  -719,  -719,   905,   912,   915,   810,  -719,
     811,   812,   814,   815,   816,   817,   818,   819,  -719,   820,
     821,   822,   823,   824,   825,   826,   827,   828,   829,   830,
     831,   832,   833,   834,   835,   836,  -719,  -719,   919,   837,
     838,  -719,   839,  -719,   209,  -719,   943,   947,   948,   949,
     844,  -719,   845,  -719,  -719,   952,   846,   953,   848,  -719,
    -719,  -719,  -719,  -719,   396,   396,   396,   396,   396,   396,
     396,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,   850,   851,   852,   -37,   853,   854,   855,   856,
     857,   858,   859,   860,   861,   863,   864,    47,   865,   869,
    -719,   870,   871,   876,   877,   880,   881,   882,     3,   883,
     884,   885,   887,   892,   893,   895,  -719,   896,   898,  -719,
    -719,   899,   900,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -193,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -190,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,   901,   904,   425,   906,   907,
     908,   909,   910,  -719,   911,   913,  -719,   914,   916,   126,
     676,   917,  -719,  -719,  -719,  -719,   920,   922,  -719,   923,
     924,   478,   925,   926,   927,   928,   929,   727,   930,   931,
    -719,   932,   933,   934,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
     935,   543,  -719,  -719,   936,   937,   938,  -719,   105,  -719,
    -719,  -719,  -719,   939,   942,   944,   945,  -719,  -719,   946,
     562,   950,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -180,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,   773,   773,
     773,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -147,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,   768,  -719,
     678,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,   -32,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,    -4,  -719,   982,
     890,   951,  -719,  -719,  -719,  -719,  -719,  -719,   954,  -719,
     955,   956,  -719,  -719,   957,  -719,  -719,  -719,   958,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,    -3,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
      29,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,    66,  -719,
    -719,   972,   -71,   940,   964,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,   107,  -719,  -719,  -719,   -37,  -719,  -719,  -719,  -719,
       3,  -719,  -719,  -719,   425,  -719,   126,  -719,  -719,  -719,
     967,   966,   973,   970,   974,  -719,   478,  -719,   727,  -719,
     543,   965,   968,   969,   317,  -719,  -719,   562,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,   110,  -719,  -719,  -719,   317,  -719
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   235,   400,   448,     0,
     463,     0,   303,   439,   279,     0,   100,   152,   337,     0,
       0,   378,     0,   109,     0,   354,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   618,   628,   620,   621,   622,   623,
     624,   625,   619,   626,   627,     0,     0,     0,   461,     0,
       0,   459,   460,     0,   520,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,   563,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   474,   475,   476,   518,   519,   513,   514,   515,   516,
     512,   486,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   487,   488,   517,   492,   493,   494,   495,   491,   490,
     496,   503,   504,   497,   498,   499,   489,   501,   510,   511,
     508,   509,   502,   500,   506,   507,   505,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     651,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     642,   643,   644,   645,   646,   649,   647,   648,   650,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   352,     0,     0,   350,   351,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   617,     0,
       0,     0,     0,   273,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   238,   239,
     242,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     240,   241,   243,   253,   254,   255,     0,     0,     0,     0,
       0,     0,     0,   428,     0,     0,     0,     0,     0,     0,
       0,     0,   403,   404,   405,   406,   407,   408,   409,   411,
     410,   413,   417,   414,   415,   416,   412,   454,     0,     0,
       0,   451,   452,   453,     0,     0,   458,   469,     0,     0,
       0,   466,   467,   468,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     473,     0,     0,     0,   320,     0,     0,     0,     0,     0,
       0,   306,   307,   308,   309,   314,   310,   311,   312,   313,
     445,     0,     0,     0,   442,   443,   444,     0,     0,     0,
     281,     0,   291,     0,   289,   290,   292,   293,    49,     0,
       0,     0,    45,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,   203,     0,     0,     0,     0,     0,   177,
       0,     0,     0,   155,   156,   157,   158,   159,   162,   163,
     164,   165,   161,   160,   166,     0,     0,     0,     0,     0,
     340,   341,   342,   343,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   641,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,   386,     0,   381,   382,
     383,   127,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   115,   114,   116,     0,     0,   349,
       0,     0,   364,     0,     0,   357,   358,   359,   360,     0,
       0,     0,    90,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   616,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   237,   418,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   402,     0,     0,     0,   450,     0,   457,     0,     0,
       0,   465,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   472,
     315,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     305,     0,     0,     0,   441,   294,     0,     0,     0,     0,
       0,   288,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   344,     0,     0,     0,     0,   339,
       0,     0,     0,     0,     0,     0,     0,     0,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   384,     0,     0,
       0,   380,     0,   122,     0,   117,     0,     0,     0,     0,
       0,   111,     0,   348,   361,     0,     0,     0,     0,   356,
      99,    98,    97,   638,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   639,   630,   631,   632,   633,   634,   635,
     637,   636,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
     236,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   401,     0,     0,   449,
     462,     0,     0,   464,   533,   537,   521,   522,   552,   524,
     615,   560,   525,   526,   557,   532,   531,   540,   530,   527,
     528,   536,   535,   534,   558,   523,   613,   614,   556,   599,
     593,   609,   594,   595,   596,   604,   612,   597,   606,   610,
     600,   611,   601,   605,   598,   608,   603,   602,   607,     0,
     592,   572,   573,   574,   567,   585,   568,   569,   570,   580,
     588,   571,   582,   586,   576,   587,   577,   581,   575,   584,
     579,   578,   583,     0,   566,   553,   551,   554,   559,   555,
     542,   549,   550,   547,   548,   543,   544,   545,   546,   561,
     562,   529,   539,   538,   541,     0,     0,     0,     0,     0,
       0,     0,     0,   304,     0,     0,   440,     0,     0,     0,
     299,   295,   298,   280,    50,    51,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   338,   653,   652,   658,   656,   659,
     654,   655,   657,    86,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    76,    84,    85,
       0,     0,   379,   128,     0,     0,     0,   140,     0,   132,
     133,   135,   134,     0,     0,     0,     0,   110,   353,     0,
       0,     0,   355,    31,    32,    33,    34,    35,    36,    37,
     268,   269,   260,   278,   277,     0,   276,   261,   263,   265,
     272,   264,   262,   271,   257,   270,   259,   258,    38,    38,
      38,    40,    39,   266,   267,   423,   426,   427,   437,   434,
     420,   435,   432,   433,     0,   431,   436,   419,   425,   422,
     424,   438,   421,   455,   456,   470,   471,   590,     0,   564,
       0,   318,   319,   329,   325,   326,   328,   333,   330,   331,
     324,   332,   327,     0,   323,   317,   336,   335,   334,   316,
     447,   446,   302,   301,   286,   287,   285,     0,   284,     0,
       0,     0,   107,   108,   176,   172,   222,   234,   210,   219,
       0,   208,   213,   228,     0,   221,   226,   232,   212,   215,
     223,   225,   229,   220,   227,   216,   233,   218,   224,   214,
     217,     0,   206,   168,   170,   173,   174,   175,   186,   187,
     188,   181,   199,   182,   183,   184,   194,   202,   185,   196,
     200,   190,   201,   191,   195,   189,   198,   193,   192,   197,
       0,   180,   169,   171,   347,   345,   346,   385,   390,   396,
     399,   392,   398,   393,   397,   395,   391,   394,     0,   389,
     136,     0,     0,     0,     0,   131,   119,   118,   120,   121,
     362,   368,   374,   377,   370,   376,   371,   375,   373,   369,
     372,     0,   367,   363,   274,     0,    41,    42,    43,   429,
       0,   591,   565,   321,     0,   282,     0,   300,   297,   296,
       0,     0,     0,     0,     0,   204,     0,   178,     0,   387,
       0,     0,     0,     0,     0,   130,   365,     0,   275,   430,
     322,   283,   209,   231,   207,   230,   211,   205,   179,   388,
     137,   139,   138,   150,   149,   145,   147,   151,   148,   144,
     146,     0,   143,   366,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -719,  -719,  -719,  -165,  -296,  -718,  -621,  -719,  -719,   960,
    -719,  -719,  -719,  -719,   847,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  1024,  -719,  -719,  -719,  -719,  -719,
    -719,   619,  -719,  -719,  -719,  -719,  -719,   549,  -719,  -719,
    -719,  -719,  -719,  -719,   849,  -719,  -719,  -719,  -719,    84,
    -719,  -719,  -719,  -719,  -719,  -181,  -719,  -719,  -719,   613,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -142,  -719,  -719,  -719,  -139,  -719,  -719,  -719,
     921,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -112,  -719,  -719,  -719,  -719,  -719,  -117,  -719,   690,  -719,
    -719,  -719,     1,  -719,  -719,  -719,  -719,  -719,   691,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -106,  -719,  -719,  -719,
    -719,  -719,  -719,   624,  -719,  -719,  -719,  -719,  -719,   941,
    -719,  -719,  -719,  -719,   580,  -719,  -719,  -719,  -719,  -719,
    -123,  -719,  -719,  -719,   618,  -719,  -719,  -719,  -719,  -115,
    -719,  -719,  -719,   840,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,   -66,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,   716,  -719,  -719,  -719,  -719,  -719,
     841,  -719,  -719,  -719,  -719,  1068,  -719,  -719,  -719,  -719,
     809,  -719,  -719,  -719,  -719,  1020,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,    81,
    -719,  -719,  -719,    85,  -719,  -719,  -719,  -719,  -719,  1089,
    -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719,  -719,   963,  -719,  -719,  -719,  -719,  -719,  -719,  -719,
    -719
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   811,   812,  1071,  1072,    27,   213,   214,
     215,   216,    28,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,    29,    77,    78,    79,    80,    81,    30,    63,
     486,   487,   488,   489,    31,    70,   571,   572,   573,   574,
     575,   576,    32,   279,   280,   281,   282,   283,  1028,  1029,
    1030,  1031,  1032,  1213,  1291,  1292,    33,    64,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     739,  1190,  1191,   514,   733,  1161,  1162,    34,    53,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   609,  1055,
    1056,    35,    61,   472,   718,  1127,  1128,   473,   474,   475,
    1131,   971,   972,   476,   477,    36,    59,   450,   451,   452,
     453,   454,   455,   456,   703,  1113,  1114,   457,   458,   459,
      37,    65,   519,   520,   521,   522,   523,    38,   287,   288,
     289,    39,    72,   584,   585,   586,   587,   588,   796,  1231,
    1232,    40,    68,   557,   558,   559,   560,   779,  1208,  1209,
      41,    54,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   632,  1084,  1085,   372,   373,   374,   375,
     376,    42,    60,   463,   464,   465,   466,    43,    55,   380,
     381,   382,   383,    44,   110,   111,   112,    45,    57,   390,
     391,   392,   393,    46,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   420,   933,   934,
     203,   419,   909,   910,   204,   205,   206,    47,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     838,   839,   595,   210,    51,   598,   210,   600,   601,   108,
     467,  1082,  1053,   285,   685,   108,    52,   483,   686,   239,
     277,   114,    56,   377,   687,    58,   115,   116,   688,   117,
     118,   277,    62,  1097,   119,   837,  1099,  1098,   580,   460,
    1100,    66,    73,   120,   121,   240,  1234,   241,   291,   483,
    1235,   122,   580,   285,   123,   124,   125,    67,  1068,  1069,
    1070,   126,   468,   377,    69,   460,    49,    50,   109,   469,
      74,   470,   242,    71,   109,   309,   127,   128,    75,  1239,
     105,   243,   378,  1240,  1054,   106,   129,   107,   387,   130,
     131,   310,   311,   484,   842,   843,   312,   211,   132,   653,
     211,   655,   656,   566,   244,   133,  1024,   134,   245,   135,
     286,   136,   666,   137,   138,   554,   246,   671,   212,   247,
     248,   212,   378,   554,   139,   484,   680,   681,   471,   140,
     141,  1262,   142,   143,   144,   581,   313,   145,   694,    76,
     696,   697,   113,   346,   379,   347,   490,   348,   249,   581,
     286,   207,   515,   837,   314,   315,   316,   317,   318,   208,
     461,   349,   319,   146,   491,   250,   320,   209,   251,   252,
     253,  1124,   321,   147,   148,   149,   150,   151,   152,   153,
     350,   322,   323,   492,   379,   388,   461,   485,   441,   217,
    -129,   516,   324,    82,  1243,   351,   292,   352,  1244,  1083,
     567,  -129,   218,  1025,   353,   219,   442,   493,   276,   389,
    1024,   566,   555,   284,   325,   254,   354,    83,    84,   485,
     555,   387,  1245,  1255,    85,   443,  1246,  1256,   517,   154,
     155,   156,   481,   157,   158,   757,   720,   278,   255,   256,
     355,   385,   159,   494,   293,   552,   563,   439,   278,   444,
      86,    87,   290,   582,   220,  1257,   583,   462,   326,  1258,
     495,   356,   294,    88,    89,    90,   568,   582,   295,   297,
     583,    91,    92,   518,   298,   728,   496,   515,   798,   578,
     478,   357,   299,   462,   569,   300,   221,   301,   490,   644,
     358,   713,  1259,   497,   498,   222,  1260,  1026,   223,   224,
     570,   623,   445,   225,   226,   227,   491,  1025,   567,   441,
     446,   447,   824,  1125,   650,   302,   516,   829,   388,    73,
     832,  1027,  1126,   303,   836,   492,   304,   442,   228,   790,
     556,   448,  1214,  1266,   534,   467,  1294,  1267,   556,   359,
    1295,   780,   389,   561,   499,   305,   443,    74,   306,   493,
    1236,  1237,  1238,   517,   384,    75,   394,   395,   396,   397,
     398,   399,   360,   400,   500,   401,   402,   403,   501,   640,
     444,   589,   742,   404,   568,   405,   406,   407,   748,   408,
     593,   409,  1283,   410,  1284,   494,   411,   468,   412,   413,
     414,   415,   569,   416,   469,   417,   470,   418,   518,   421,
     422,  1026,   495,   423,   114,   424,   449,   425,   570,   115,
     116,   426,   117,   118,   709,   427,    76,   119,   496,   307,
     428,   590,   429,   445,   430,  1027,   120,   121,  1285,   431,
     432,   446,   447,   433,   122,   497,   498,   123,   124,   125,
    1103,   434,   435,   436,   126,  1286,   437,   438,   479,   565,
     480,   524,   448,   471,   525,   526,   527,   528,   529,   127,
     128,   530,   531,   535,  1104,   536,   537,   538,   539,   129,
     540,   541,   130,   131,   542,   543,   544,   545,   546,   547,
     532,   132,  1136,   548,  1287,  1288,   499,   549,   133,   550,
     134,   551,   135,  1105,   136,   562,   137,   138,  1137,  1138,
     577,   591,   594,   592,   596,   597,   500,   139,  1139,   604,
     501,   599,   140,   141,   602,   142,   143,   144,   603,   605,
     145,   606,   646,   607,  1106,  1107,   608,   449,   610,   611,
    1108,   346,   612,   347,   613,   348,  1289,   239,   614,   615,
     616,  1290,  1140,  1141,   617,  1142,   146,   652,   594,   349,
     618,   619,   620,   621,  1109,   622,   147,   148,   149,   150,
     151,   152,   153,   240,   625,   241,   626,   647,   350,   627,
    1110,   628,   629,  1143,   804,   805,   806,   807,   808,   809,
     810,  1144,   630,   351,   631,   352,   633,   634,   635,   636,
     242,  1263,   353,   637,   638,   639,   642,   643,   648,   243,
     649,   654,   657,  1145,   354,  1146,  1147,   658,   659,   660,
    1198,   661,   154,   155,   156,   662,   157,   158,   663,   664,
     667,   665,   244,   668,  1148,   159,   245,   669,   355,  1221,
     670,   672,  1111,   673,   246,   674,   676,   247,   248,  1043,
    1044,  1045,  1046,  1047,  1048,  1049,  1149,   675,   677,   356,
    1112,  1150,   678,   679,   682,  1151,   683,   684,   689,  1152,
     690,   691,   692,   693,  1153,   695,   249,   698,  1154,   357,
     699,  1199,   701,     2,     3,   722,   702,     4,   358,  1155,
     704,  1156,  1157,   250,  1158,   705,   251,   252,   253,     5,
    1222,   700,     6,   706,     7,  1159,   707,   708,   711,   712,
     715,     8,  1160,  1200,   716,   717,   719,   723,   724,   725,
     726,  1201,   730,     9,   727,   309,    10,    11,   731,   732,
    1202,   734,  1223,   911,   744,   912,   913,   359,   735,   736,
    1224,   310,   311,   254,    12,   737,   312,   738,    13,  1225,
     740,   741,   745,   750,  1203,   746,  1204,  1205,   747,    14,
     360,   753,   751,   752,   754,   755,   255,   256,   756,   220,
    1206,   759,   760,  1226,   758,  1227,  1228,  1207,   761,    15,
      16,   762,  1168,   763,  1169,  1170,   313,   764,   765,  1229,
     766,   767,   768,   769,    17,   770,  1230,   776,   771,   772,
     773,   221,   774,   777,   314,   315,   316,   317,   318,   775,
     222,    18,   319,   223,   224,   778,   320,   782,   225,   226,
     227,   783,   321,   889,    19,    20,   784,   785,   786,   787,
     792,   322,   323,   788,   789,   795,   793,   794,   822,   800,
     801,   797,   324,   228,   802,   803,   813,   814,    21,   914,
     915,   916,   815,   816,   917,   918,   817,   919,   920,   818,
     921,    22,   922,   819,   325,   923,    23,   924,   925,   820,
     821,    24,   823,   926,    25,   825,   826,   927,   827,   828,
     830,   928,   929,   930,   833,   831,   834,   835,   931,   837,
     840,   841,   845,   932,   851,   844,   846,   847,  1171,  1172,
    1173,  1129,   849,  1174,  1175,   848,  1176,  1177,   326,  1178,
     850,  1179,   852,   853,  1180,   854,  1181,  1182,   855,   856,
     857,   858,  1183,   859,   860,   861,  1184,   862,   863,    82,
    1185,  1186,  1187,   864,   865,   866,   955,  1188,   867,   890,
     891,   892,  1189,   868,   893,   894,   869,   895,   896,   870,
     897,   871,   898,    83,    84,   899,   872,   900,   901,   873,
      85,   874,   875,   902,   876,   877,   878,   903,   879,   880,
     881,   904,   905,   906,   882,   883,   884,   885,   907,   886,
     887,   888,   935,   908,   936,   937,    86,    87,   938,   939,
     957,   940,   958,   941,   959,   942,   960,   961,   962,    88,
      89,    90,   964,   965,   967,   968,   970,    91,    92,   976,
     943,   944,   945,   946,   956,   947,   977,   948,   979,   982,
     949,   983,   950,   951,   984,   952,   980,   985,   953,   954,
     963,   986,   988,   989,   966,   991,   973,   974,   969,   975,
     978,   981,   992,   990,   987,   993,   994,   995,   996,  1020,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1033,  1022,  1023,  1021,  1034,  1035,  1036,
    1037,  1038,  1039,  1041,  1042,  1040,  1050,  1051,  1052,  1057,
    1058,  1059,  1060,  1061,  1062,  1063,  1064,  1065,  1247,  1066,
    1067,  1073,  1261,  1272,  1273,  1074,  1075,  1076,  1275,  1274,
    1276,   296,  1077,  1078,   553,   729,  1079,  1080,  1081,  1086,
    1087,  1088,  1215,  1089,  1296,   743,  1278,  1277,  1090,  1091,
     791,  1092,  1093,  1268,  1094,  1095,  1096,  1101,   564,  1271,
    1102,  1248,  1115,  1116,  1117,  1118,  1119,  1120,  1270,  1121,
    1122,   710,  1123,   749,  1293,  1279,  1132,  1130,  1133,  1134,
    1135,  1163,  1164,  1165,  1166,  1167,  1192,  1193,  1194,  1195,
    1196,  1197,  1210,   721,   799,  1216,  1211,  1212,  1217,  1264,
    1218,  1219,  1220,   482,  1269,   781,  1233,  1249,   386,   714,
     440,  1242,   308,  1241,     0,  1250,  1251,  1252,  1253,  1254,
    1265,  1280,   533,     0,  1281,  1282,     0,     0,     0,   651,
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,     0,     0,   579,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   624
};

static const yytype_int16 yycheck[] =
{
     621,   622,   298,     1,   228,   301,     1,   303,   304,     1,
       1,     8,    49,     1,   208,     1,   228,     1,   212,     1,
       1,     1,   228,     1,   208,   228,     6,     7,   212,     9,
      10,     1,   228,   226,    14,   106,   226,   230,     1,     1,
     230,   228,     1,    23,    24,    27,   226,    29,   226,     1,
     230,    31,     1,     1,    34,    35,    36,   228,    11,    12,
      13,    41,    53,     1,   228,     1,   226,   227,    60,    60,
      29,    62,    54,   228,    60,     1,    56,    57,    37,   226,
     228,    63,    60,   230,   121,   228,    66,   228,     1,    69,
      70,    17,    18,    77,   175,   176,    22,    95,    78,   395,
      95,   397,   398,     1,    86,    85,     1,    87,    90,    89,
      98,    91,   408,    93,    94,     1,    98,   413,   116,   101,
     102,   116,    60,     1,   104,    77,   422,   423,   119,   109,
     110,   202,   112,   113,   114,    98,    62,   117,   434,    98,
     436,   437,   228,     1,   122,     3,     1,     5,   130,    98,
      98,   228,     1,   106,    80,    81,    82,    83,    84,   228,
     122,    19,    88,   143,    19,   147,    92,   228,   150,   151,
     152,    45,    98,   153,   154,   155,   156,   157,   158,   159,
      38,   107,   108,    38,   122,    98,   122,   171,     1,   228,
     171,    40,   118,     1,   226,    53,   229,    55,   230,   196,
      98,   171,   228,    98,    62,   228,    19,    62,   228,   122,
       1,     1,    98,   228,   140,   197,    74,    25,    26,   171,
      98,     1,   226,   226,    32,    38,   230,   230,    77,   209,
     210,   211,   227,   213,   214,   531,   227,   218,   220,   221,
      98,   227,   222,    98,   229,   227,   227,   227,   218,    62,
      58,    59,   228,   216,     1,   226,   219,   219,   184,   230,
     115,   119,   229,    71,    72,    73,   164,   216,   227,   229,
     219,    79,    80,   122,   229,   227,   131,     1,   227,   227,
     226,   139,   229,   219,   182,   229,    33,   229,     1,   227,
     148,   227,   226,   148,   149,    42,   230,   192,    45,    46,
     198,   227,   115,    50,    51,    52,    19,    98,    98,     1,
     123,   124,   608,   187,   227,   229,    40,   613,    98,     1,
     616,   216,   196,   229,   620,    38,   229,    19,    75,   227,
     216,   144,   227,   226,   226,     1,   226,   230,   216,   197,
     230,   227,   122,   226,   199,   229,    38,    29,   229,    62,
    1068,  1069,  1070,    77,   229,    37,   229,   229,   229,   229,
     229,   229,   220,   229,   219,   229,   229,   229,   223,   227,
      62,   120,   227,   229,   164,   229,   229,   229,   227,   229,
     106,   229,    65,   229,    67,    98,   229,    53,   229,   229,
     229,   229,   182,   229,    60,   229,    62,   229,   122,   229,
     229,   192,   115,   229,     1,   229,   219,   229,   198,     6,
       7,   229,     9,    10,   227,   229,    98,    14,   131,   227,
     229,   120,   229,   115,   229,   216,    23,    24,   111,   229,
     229,   123,   124,   229,    31,   148,   149,    34,    35,    36,
      15,   229,   229,   229,    41,   128,   229,   229,   229,   171,
     229,   229,   144,   119,   229,   229,   229,   229,   229,    56,
      57,   229,   229,   229,    39,   229,   229,   229,   229,    66,
     229,   229,    69,    70,   229,   229,   229,   229,   229,   229,
     227,    78,     4,   229,   167,   168,   199,   229,    85,   229,
      87,   229,    89,    68,    91,   229,    93,    94,    20,    21,
     229,   120,   106,   226,   208,   106,   219,   104,    30,   226,
     223,   106,   109,   110,   106,   112,   113,   114,   106,   226,
     117,   229,   120,   229,    99,   100,   229,   219,   229,   229,
     105,     1,   229,     3,   229,     5,   219,     1,   229,   229,
     229,   224,    64,    65,   229,    67,   143,   208,   106,    19,
     229,   229,   229,   229,   129,   229,   153,   154,   155,   156,
     157,   158,   159,    27,   226,    29,   229,   226,    38,   229,
     145,   229,   229,    95,   132,   133,   134,   135,   136,   137,
     138,   103,   229,    53,   229,    55,   229,   229,   229,   229,
      54,  1212,    62,   229,   229,   229,   229,   229,   229,    63,
     229,   106,   208,   125,    74,   127,   128,   106,   208,   106,
      67,   106,   209,   210,   211,   106,   213,   214,   208,   208,
     106,   208,    86,   106,   146,   222,    90,   106,    98,    67,
     106,   106,   207,   106,    98,   106,   208,   101,   102,   804,
     805,   806,   807,   808,   809,   810,   168,   106,   229,   119,
     225,   173,   229,   208,   208,   177,   208,   208,   208,   181,
     208,   208,   208,   106,   186,   208,   130,   208,   190,   139,
     226,   128,   229,     0,     1,   120,   229,     4,   148,   201,
     229,   203,   204,   147,   206,   229,   150,   151,   152,    16,
     128,   226,    19,   229,    21,   217,   229,   229,   229,   229,
     226,    28,   224,   160,   229,   229,   229,   120,   226,   226,
     229,   168,   226,    40,   229,     1,    43,    44,   229,   229,
     177,   229,   160,    45,   226,    47,    48,   197,   229,   229,
     168,    17,    18,   197,    61,   229,    22,   229,    65,   177,
     229,   229,   229,   208,   201,   229,   203,   204,   229,    76,
     220,   120,   208,   208,   208,   208,   220,   221,   208,     1,
     217,   106,   120,   201,   226,   203,   204,   224,   208,    96,
      97,   120,    45,   106,    47,    48,    62,   106,   120,   217,
     120,   120,   120,   120,   111,   120,   224,   226,   120,   120,
     120,    33,   120,   226,    80,    81,    82,    83,    84,   120,
      42,   128,    88,    45,    46,   229,    92,   208,    50,    51,
      52,   226,    98,    45,   141,   142,   228,   226,   229,   229,
     120,   107,   108,   229,   229,   229,   226,   226,   106,   226,
     226,   229,   118,    75,   226,   226,   226,   226,   165,   161,
     162,   163,   226,   226,   166,   167,   226,   169,   170,   226,
     172,   178,   174,   226,   140,   177,   183,   179,   180,   226,
     226,   188,   106,   185,   191,   229,   106,   189,   106,   106,
     106,   193,   194,   195,   120,   106,   106,   106,   200,   106,
     226,   120,   208,   205,   106,   120,   120,   120,   161,   162,
     163,   215,   120,   166,   167,   229,   169,   170,   184,   172,
     120,   174,   120,   120,   177,   120,   179,   180,   120,   226,
     120,   120,   185,   226,   226,   120,   189,   120,   226,     1,
     193,   194,   195,   226,   226,   226,   120,   200,   226,   161,
     162,   163,   205,   226,   166,   167,   226,   169,   170,   226,
     172,   226,   174,    25,    26,   177,   226,   179,   180,   226,
      32,   226,   226,   185,   226,   226,   226,   189,   226,   226,
     226,   193,   194,   195,   226,   226,   226,   226,   200,   226,
     226,   226,   226,   205,   226,   226,    58,    59,   226,   226,
     229,   226,   120,   226,   106,   226,   120,   120,   120,    71,
      72,    73,   120,   120,   120,   120,   106,    79,    80,   120,
     226,   226,   226,   226,   208,   226,   120,   226,   120,   120,
     226,   120,   226,   226,   120,   226,   208,   120,   226,   226,
     226,   208,   120,   120,   226,   120,   226,   226,   229,   226,
     226,   229,   120,   226,   229,   120,   226,   226,   226,   120,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   120,   226,   226,   229,   120,   120,   120,
     226,   226,   120,   120,   226,   229,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   106,   226,
     226,   226,   120,   126,   128,   226,   226,   226,   128,   126,
     126,    77,   226,   226,   257,   486,   226,   226,   226,   226,
     226,   226,  1028,   226,  1295,   502,  1258,  1256,   226,   226,
     571,   226,   226,  1235,   226,   226,   226,   226,   279,  1246,
     226,  1130,   226,   226,   226,   226,   226,   226,  1244,   226,
     226,   450,   226,   519,  1267,  1260,   226,   230,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   473,   584,   226,   229,   229,   226,   229,
     226,   226,   226,   213,  1240,   557,   226,   226,   110,   463,
     160,  1100,    93,  1098,    -1,   231,   231,   231,   231,   231,
     226,   226,   229,    -1,   226,   226,    -1,    -1,    -1,   390,
      -1,   361,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,   287,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   233,     0,     1,     4,    16,    19,    21,    28,    40,
      43,    44,    61,    65,    76,    96,    97,   111,   128,   141,
     142,   165,   178,   183,   188,   191,   234,   239,   244,   264,
     270,   276,   284,   298,   319,   343,   357,   372,   379,   383,
     393,   402,   423,   429,   435,   439,   445,   499,   512,   226,
     227,   228,   228,   320,   403,   430,   228,   440,   228,   358,
     424,   344,   228,   271,   299,   373,   228,   228,   394,   228,
     277,   228,   384,     1,    29,    37,    98,   265,   266,   267,
     268,   269,     1,    25,    26,    32,    58,    59,    71,    72,
      73,    79,    80,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   228,   228,   228,     1,    60,
     436,   437,   438,   228,     1,     6,     7,     9,    10,    14,
      23,    24,    31,    34,    35,    36,    41,    56,    57,    66,
      69,    70,    78,    85,    87,    89,    91,    93,    94,   104,
     109,   110,   112,   113,   114,   117,   143,   153,   154,   155,
     156,   157,   158,   159,   209,   210,   211,   213,   214,   222,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   492,   496,   497,   498,   228,   228,   228,
       1,    95,   116,   240,   241,   242,   243,   228,   228,   228,
       1,    33,    42,    45,    46,    50,    51,    52,    75,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,     1,
      27,    29,    54,    63,    86,    90,    98,   101,   102,   130,
     147,   150,   151,   152,   197,   220,   221,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   228,     1,   218,   285,
     286,   287,   288,   289,   228,     1,    98,   380,   381,   382,
     228,   226,   229,   229,   229,   227,   266,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   227,   501,     1,
      17,    18,    22,    62,    80,    81,    82,    83,    84,    88,
      92,    98,   107,   108,   118,   140,   184,   321,   322,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,     1,     3,     5,    19,
      38,    53,    55,    62,    74,    98,   119,   139,   148,   197,
     220,   404,   405,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   418,   419,   420,   421,   422,     1,    60,   122,
     431,   432,   433,   434,   229,   227,   437,     1,    98,   122,
     441,   442,   443,   444,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   493,
     489,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   227,
     447,     1,    19,    38,    62,   115,   123,   124,   144,   219,
     359,   360,   361,   362,   363,   364,   365,   369,   370,   371,
       1,   122,   219,   425,   426,   427,   428,     1,    53,    60,
      62,   119,   345,   349,   350,   351,   355,   356,   226,   229,
     229,   227,   241,     1,    77,   171,   272,   273,   274,   275,
       1,    19,    38,    62,    98,   115,   131,   148,   149,   199,
     219,   223,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   315,     1,    40,    77,   122,   374,
     375,   376,   377,   378,   229,   229,   229,   229,   229,   229,
     229,   229,   227,   514,   226,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   227,   246,     1,    98,   216,   395,   396,   397,
     398,   226,   229,   227,   286,   171,     1,    98,   164,   182,
     198,   278,   279,   280,   281,   282,   283,   229,   227,   381,
       1,    98,   216,   219,   385,   386,   387,   388,   389,   120,
     120,   120,   226,   106,   106,   236,   208,   106,   236,   106,
     236,   236,   106,   106,   226,   226,   229,   229,   229,   340,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   227,   322,   226,   229,   229,   229,   229,
     229,   229,   415,   229,   229,   229,   229,   229,   229,   229,
     227,   405,   229,   229,   227,   432,   120,   226,   229,   229,
     227,   442,   208,   236,   106,   236,   236,   208,   106,   208,
     106,   106,   106,   208,   208,   208,   236,   106,   106,   106,
     106,   236,   106,   106,   106,   106,   208,   229,   229,   208,
     236,   236,   208,   208,   208,   208,   212,   208,   212,   208,
     208,   208,   208,   106,   236,   208,   236,   236,   208,   226,
     226,   229,   229,   366,   229,   229,   229,   229,   229,   227,
     360,   229,   229,   227,   426,   226,   229,   229,   346,   229,
     227,   350,   120,   120,   226,   226,   229,   229,   227,   273,
     226,   229,   229,   316,   229,   229,   229,   229,   229,   312,
     229,   229,   227,   301,   226,   229,   229,   229,   227,   375,
     208,   208,   208,   120,   208,   208,   208,   236,   226,   106,
     120,   208,   120,   106,   106,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   226,   226,   229,   399,
     227,   396,   208,   226,   228,   226,   229,   229,   229,   229,
     227,   279,   120,   226,   226,   229,   390,   229,   227,   386,
     226,   226,   226,   226,   132,   133,   134,   135,   136,   137,
     138,   235,   236,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   106,   106,   236,   229,   106,   106,   106,   236,
     106,   106,   236,   120,   106,   106,   236,   106,   238,   238,
     226,   120,   175,   176,   120,   208,   120,   120,   229,   120,
     120,   106,   120,   120,   120,   120,   226,   120,   120,   226,
     226,   120,   120,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,    45,
     161,   162,   163,   166,   167,   169,   170,   172,   174,   177,
     179,   180,   185,   189,   193,   194,   195,   200,   205,   494,
     495,    45,    47,    48,   161,   162,   163,   166,   167,   169,
     170,   172,   174,   177,   179,   180,   185,   189,   193,   194,
     195,   200,   205,   490,   491,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   120,   208,   229,   120,   106,
     120,   120,   120,   226,   120,   120,   226,   120,   120,   229,
     106,   353,   354,   226,   226,   226,   120,   120,   226,   120,
     208,   229,   120,   120,   120,   120,   208,   229,   120,   120,
     226,   120,   120,   120,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     120,   229,   226,   226,     1,    98,   192,   216,   290,   291,
     292,   293,   294,   120,   120,   120,   120,   226,   226,   120,
     229,   120,   226,   235,   235,   235,   235,   235,   235,   235,
     226,   226,   226,    49,   121,   341,   342,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,    11,    12,
      13,   237,   238,   226,   226,   226,   226,   226,   226,   226,
     226,   226,     8,   196,   416,   417,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   230,   226,
     230,   226,   226,    15,    39,    68,    99,   100,   105,   129,
     145,   207,   225,   367,   368,   226,   226,   226,   226,   226,
     226,   226,   226,   226,    45,   187,   196,   347,   348,   215,
     230,   352,   226,   226,   226,   226,     4,    20,    21,    30,
      64,    65,    67,    95,   103,   125,   127,   128,   146,   168,
     173,   177,   181,   186,   190,   201,   203,   204,   206,   217,
     224,   317,   318,   226,   226,   226,   226,   226,    45,    47,
      48,   161,   162,   163,   166,   167,   169,   170,   172,   174,
     177,   179,   180,   185,   189,   193,   194,   195,   200,   205,
     313,   314,   226,   226,   226,   226,   226,   226,    67,   128,
     160,   168,   177,   201,   203,   204,   217,   224,   400,   401,
     226,   229,   229,   295,   227,   291,   226,   226,   226,   226,
     226,    67,   128,   160,   168,   177,   201,   203,   204,   217,
     224,   391,   392,   226,   226,   230,   237,   237,   237,   226,
     230,   495,   491,   226,   230,   226,   230,   106,   354,   226,
     231,   231,   231,   231,   231,   226,   230,   226,   230,   226,
     230,   120,   202,   238,   229,   226,   226,   230,   342,   417,
     368,   348,   126,   128,   126,   128,   126,   318,   314,   401,
     226,   226,   226,    65,    67,   111,   128,   167,   168,   219,
     224,   296,   297,   392,   226,   230,   297
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
     301,   301,   301,   301,   301,   301,   301,   301,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   312,   311,   313,
     313,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   316,   315,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   320,   319,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   340,   339,   341,   341,   342,   342,   344,
     343,   346,   345,   347,   347,   348,   348,   348,   349,   349,
     350,   350,   350,   350,   350,   352,   351,   353,   353,   354,
     354,   355,   356,   358,   357,   359,   359,   360,   360,   360,
     360,   360,   360,   360,   360,   360,   361,   362,   363,   364,
     366,   365,   367,   367,   368,   368,   368,   368,   368,   368,
     368,   368,   368,   368,   369,   370,   371,   373,   372,   374,
     374,   375,   375,   375,   375,   376,   377,   378,   379,   380,
     380,   381,   381,   382,   384,   383,   385,   385,   386,   386,
     386,   386,   387,   388,   390,   389,   391,   391,   392,   392,
     392,   392,   392,   392,   392,   392,   392,   392,   394,   393,
     395,   395,   396,   396,   396,   397,   399,   398,   400,   400,
     401,   401,   401,   401,   401,   401,   401,   401,   401,   401,
     403,   402,   404,   404,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   406,
     407,   408,   409,   410,   411,   412,   413,   413,   415,   414,
     416,   416,   417,   417,   418,   419,   420,   421,   422,   424,
     423,   425,   425,   426,   426,   426,   427,   428,   430,   429,
     431,   431,   432,   432,   432,   433,   434,   435,   436,   436,
     437,   437,   438,   440,   439,   441,   441,   442,   442,   442,
     443,   444,   445,   446,   446,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   474,   475,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   489,   488,   490,   490,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   493,
     492,   494,   494,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   496,   497,   498,   499,   500,   500,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   513,   514,   514,   514,   514,   514,   514,   514,
     514,   514,   515,   516,   517,   518,   519,   520,   521,   522
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
       3,     3,     1,     1,     1,     0,     6,     2,     1,     1,
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
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
        case 28:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2851 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2881 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 421 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2905 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 428 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 448 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2935 "conf_parser.c" /* yacc.c:1646  */
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
#line 2978 "conf_parser.c" /* yacc.c:1646  */
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
#line 3039 "conf_parser.c" /* yacc.c:1646  */
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
#line 3071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 605 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3082 "conf_parser.c" /* yacc.c:1646  */
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
#line 3099 "conf_parser.c" /* yacc.c:1646  */
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
#line 3130 "conf_parser.c" /* yacc.c:1646  */
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
#line 3148 "conf_parser.c" /* yacc.c:1646  */
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
#line 3166 "conf_parser.c" /* yacc.c:1646  */
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
#line 3179 "conf_parser.c" /* yacc.c:1646  */
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
#line 3196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 709 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3208 "conf_parser.c" /* yacc.c:1646  */
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
#line 3239 "conf_parser.c" /* yacc.c:1646  */
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
#line 3270 "conf_parser.c" /* yacc.c:1646  */
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
#line 3298 "conf_parser.c" /* yacc.c:1646  */
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
#line 3323 "conf_parser.c" /* yacc.c:1646  */
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
#line 3348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3369 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 869 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 878 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 890 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3402 "conf_parser.c" /* yacc.c:1646  */
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
#line 3419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 911 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 917 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 926 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3446 "conf_parser.c" /* yacc.c:1646  */
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
#line 3464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 948 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 960 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3491 "conf_parser.c" /* yacc.c:1646  */
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
#line 3512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 993 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3530 "conf_parser.c" /* yacc.c:1646  */
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
#line 3543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3554 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1027 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1030 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3579 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3588 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3597 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3606 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3615 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3624 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3633 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3642 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1080 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3663 "conf_parser.c" /* yacc.c:1646  */
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
#line 3748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1183 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1201 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1207 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1218 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1224 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3816 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1230 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1241 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1254 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3857 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1258 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3866 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1266 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1270 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1274 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1278 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1282 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1286 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3929 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1290 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3938 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3947 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1298 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3956 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1302 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1318 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4010 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4019 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4028 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1334 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1351 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4073 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1359 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4082 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1367 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4100 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1375 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1379 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1383 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1387 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1391 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1395 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1399 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1403 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1407 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1411 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1415 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1419 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1423 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1427 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4235 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1431 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4244 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1435 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1439 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1443 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4289 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1455 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4307 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1469 "conf_parser.y" /* yacc.c:1646  */
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
#line 4324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 236:
#line 1481 "conf_parser.y" /* yacc.c:1646  */
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
#line 4372 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1545 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1551 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1557 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1563 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1569 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4417 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1575 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4426 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1581 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1587 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1593 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1612 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4481 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1618 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4490 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1624 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4499 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1630 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4511 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1639 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 273:
#line 1648 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1655 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1659 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1669 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 281:
#line 1675 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1681 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1685 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4585 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 287:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4594 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 295:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4600 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
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
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1715 "conf_parser.y" /* yacc.c:1646  */
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
#line 4638 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1732 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4647 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4656 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1747 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4665 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 304:
#line 1751 "conf_parser.y" /* yacc.c:1646  */
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
#line 4706 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1800 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4715 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1806 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1812 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1818 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4747 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 320:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1836 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1840 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1844 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1848 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4792 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1852 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4801 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1856 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4810 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1860 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4819 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1864 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4828 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1872 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1878 "conf_parser.y" /* yacc.c:1646  */
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
#line 4863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1892 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4875 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1914 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4899 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 338:
#line 1921 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1932 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1938 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 347:
#line 1944 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1974 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 355:
#line 1985 "conf_parser.y" /* yacc.c:1646  */
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
#line 4985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2008 "conf_parser.y" /* yacc.c:1646  */
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
#line 5016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 364:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5025 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5034 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2038 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5043 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2042 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5052 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2050 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2054 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2062 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5097 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5106 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 379:
#line 2088 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5153 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 386:
#line 2109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5162 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2116 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5171 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2120 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5180 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2124 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2128 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2132 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2136 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2140 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5225 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2144 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5234 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2148 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5243 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2152 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5252 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2161 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5266 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 401:
#line 2170 "conf_parser.y" /* yacc.c:1646  */
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
#line 5332 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2250 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2256 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2262 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
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
#line 5375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
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
#line 5391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2294 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2300 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2306 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2310 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 428:
#line 2316 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2322 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2326 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5467 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5476 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2349 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2355 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2361 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5508 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5517 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 440:
#line 2380 "conf_parser.y" /* yacc.c:1646  */
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
#line 5542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2405 "conf_parser.y" /* yacc.c:1646  */
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
#line 5565 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 449:
#line 2438 "conf_parser.y" /* yacc.c:1646  */
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
#line 5609 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2464 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 456:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2484 "conf_parser.y" /* yacc.c:1646  */
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
#line 5644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2501 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 464:
#line 2505 "conf_parser.y" /* yacc.c:1646  */
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
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2527 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5684 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 471:
#line 2533 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5693 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5701 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2609 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5734 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5742 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5750 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5774 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5798 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5806 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5838 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2685 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5847 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5863 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5887 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2726 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5943 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5983 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5991 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6007 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6015 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6031 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 563:
#line 2802 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2808 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2811 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2814 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2817 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2820 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6079 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2823 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2826 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2829 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2832 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2835 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2838 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6135 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2844 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6159 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6167 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6175 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6207 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 589:
#line 2876 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2882 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6231 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2885 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6239 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2888 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6247 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2891 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2894 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2897 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6271 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2900 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6279 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2903 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2906 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6295 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6303 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2912 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6311 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2915 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6319 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2918 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6327 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2921 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6335 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2924 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2927 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6351 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2930 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6359 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2933 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6375 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6399 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 615:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6423 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6431 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6463 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6471 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 639:
#line 3024 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3046 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6496 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3052 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6505 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3058 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6514 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3064 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6523 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3070 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3079 "conf_parser.y" /* yacc.c:1646  */
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
#line 6553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3094 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6562 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 659:
#line 3100 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6571 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6575 "conf_parser.c" /* yacc.c:1646  */
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
