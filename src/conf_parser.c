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
#define YYLAST   1328

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  290
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1292

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
    1064,  1068,  1079,  1078,  1140,  1140,  1141,  1142,  1143,  1144,
    1145,  1146,  1147,  1148,  1149,  1150,  1151,  1153,  1159,  1165,
    1171,  1177,  1188,  1194,  1205,  1212,  1211,  1217,  1217,  1218,
    1222,  1226,  1230,  1234,  1238,  1242,  1246,  1250,  1254,  1258,
    1262,  1266,  1270,  1274,  1278,  1282,  1286,  1290,  1294,  1298,
    1302,  1309,  1308,  1314,  1314,  1315,  1319,  1323,  1327,  1331,
    1335,  1339,  1343,  1347,  1351,  1355,  1359,  1363,  1367,  1371,
    1375,  1379,  1383,  1387,  1391,  1395,  1399,  1403,  1407,  1411,
    1415,  1419,  1423,  1434,  1433,  1490,  1490,  1491,  1492,  1493,
    1494,  1495,  1496,  1497,  1498,  1499,  1500,  1501,  1502,  1503,
    1503,  1504,  1505,  1506,  1507,  1509,  1515,  1521,  1527,  1533,
    1539,  1545,  1551,  1557,  1563,  1569,  1576,  1582,  1588,  1594,
    1603,  1613,  1612,  1618,  1618,  1619,  1623,  1634,  1633,  1640,
    1639,  1644,  1644,  1645,  1649,  1653,  1659,  1659,  1660,  1660,
    1660,  1660,  1660,  1662,  1662,  1664,  1664,  1666,  1679,  1696,
    1702,  1712,  1711,  1753,  1753,  1754,  1755,  1756,  1757,  1758,
    1759,  1760,  1761,  1762,  1764,  1770,  1776,  1782,  1794,  1793,
    1799,  1799,  1800,  1804,  1808,  1812,  1816,  1820,  1824,  1828,
    1832,  1836,  1842,  1856,  1865,  1879,  1878,  1893,  1893,  1894,
    1894,  1894,  1894,  1896,  1902,  1908,  1918,  1920,  1920,  1921,
    1921,  1923,  1939,  1938,  1963,  1963,  1964,  1964,  1964,  1964,
    1966,  1972,  1992,  1991,  1997,  1997,  1998,  2002,  2006,  2010,
    2014,  2018,  2022,  2026,  2030,  2034,  2044,  2043,  2064,  2064,
    2065,  2065,  2065,  2067,  2074,  2073,  2079,  2079,  2080,  2084,
    2088,  2092,  2096,  2100,  2104,  2108,  2112,  2116,  2126,  2125,
    2197,  2197,  2198,  2199,  2200,  2201,  2202,  2203,  2204,  2205,
    2206,  2207,  2208,  2209,  2210,  2211,  2212,  2214,  2220,  2226,
    2232,  2245,  2258,  2264,  2270,  2274,  2281,  2280,  2285,  2285,
    2286,  2290,  2296,  2307,  2313,  2319,  2325,  2341,  2340,  2366,
    2366,  2367,  2367,  2367,  2369,  2389,  2399,  2398,  2425,  2425,
    2426,  2426,  2426,  2428,  2434,  2443,  2445,  2445,  2446,  2446,
    2448,  2466,  2465,  2488,  2488,  2489,  2489,  2489,  2491,  2497,
    2506,  2509,  2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,
    2517,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,
    2527,  2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,  2536,
    2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,
    2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2558,
    2563,  2568,  2573,  2579,  2584,  2589,  2594,  2599,  2604,  2609,
    2614,  2619,  2624,  2629,  2634,  2639,  2644,  2649,  2655,  2660,
    2665,  2670,  2675,  2680,  2685,  2690,  2693,  2698,  2701,  2706,
    2711,  2716,  2721,  2726,  2731,  2736,  2741,  2746,  2751,  2756,
    2761,  2767,  2766,  2771,  2771,  2772,  2775,  2778,  2781,  2784,
    2787,  2790,  2793,  2796,  2799,  2802,  2805,  2808,  2811,  2814,
    2817,  2820,  2823,  2826,  2829,  2832,  2835,  2841,  2840,  2845,
    2845,  2846,  2849,  2852,  2855,  2858,  2861,  2864,  2867,  2870,
    2873,  2876,  2879,  2882,  2885,  2888,  2891,  2894,  2897,  2900,
    2903,  2908,  2913,  2918,  2927,  2930,  2930,  2931,  2932,  2933,
    2934,  2935,  2936,  2937,  2938,  2939,  2940,  2941,  2943,  2948,
    2953,  2958,  2963,  2968,  2973,  2978,  2983,  2988,  2996,  2999,
    2999,  3000,  3001,  3002,  3003,  3004,  3005,  3006,  3007,  3008,
    3010,  3016,  3022,  3028,  3034,  3043,  3058,  3064
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
   -1036,   662, -1036,  -208,  -204,  -186, -1036, -1036, -1036,  -184,
   -1036,  -171, -1036, -1036, -1036,  -170, -1036, -1036, -1036,  -168,
    -163, -1036,  -153, -1036,  -140, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,     9,   580,  -129,  -113,  -104,    31,   -94,   413,   -78,
     -72,   -70,    23,   -57,   -41,   -40,   724,   411,   -32,    91,
     -23,    10,   -18,   -15,    -6,    35,    46,     5, -1036, -1036,
   -1036, -1036, -1036,    49,    66,    70,    81,    86,    88,    96,
      98,   106,   127,   233, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,   699,   537,    25, -1036,   128,
      21, -1036, -1036,    32, -1036,   130,   131,   133,   134,   135,
     136,   138,   139,   145,   146,   147,   149,   152,   154,   155,
     157,   160,   161,   162,   163,   165,   166,   167,   169,   172,
   -1036, -1036,   173,   174,   176,   182,   187,   188,   189,   201,
     203,   204,   205,   207,   211,   213,   222,   223,   224,   225,
      59, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,   319,    38,   292,
     117,   227,   228,    15, -1036, -1036, -1036,    27,   298,    36,
   -1036,   229,   230,   232,   235,   236,   238,   239,   240,     3,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   125,
     243,   244,   247,   249,   250,   252,   257,   259,   260,   264,
     265,   266,   275,   277,   280,   282,   283,    34, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   177,   153,   286,    18,
   -1036, -1036, -1036,    79,   190, -1036,   287,    13, -1036, -1036,
     150, -1036,   285,   288,   289,   193, -1036,   324,   355,   279,
     412,   355,   415,   355,   355,   418,   422,   304, -1036,   306,
     307,   311,   315, -1036,   316,   318,   321,   322,   323,   325,
     326,   330,   331,   335,   345,   346,   349,   144, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   327,   350,   354,   358,
     359,   361,   363, -1036,   367,   370,   372,   373,   374,   375,
     376,   202, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   380,   382,
      20, -1036, -1036, -1036,   427,   388, -1036, -1036,   390,   399,
     180, -1036, -1036, -1036,   409,   355,   426,   355,   355,   421,
     477,   425,   523,   531,   536,   436,   437,   439,   355,   541,
     542,   544,   549,   355,   551,   555,   558,   559,   460,   442,
     445,   470,   355,   355,   472,   473,   475,  -167,  -149,   481,
     482,   484,   494,   581,   355,   496,   355,   355,   511,   495,
   -1036,   497,   491,   498, -1036,   500,   501,   502,   503,   504,
     158, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,   506,   507,    71, -1036, -1036, -1036,   512,   508,   513,
   -1036,   516, -1036,    24, -1036, -1036, -1036, -1036, -1036,   619,
     625,   521, -1036,   522,   524,   525,    19, -1036, -1036, -1036,
     529,   527,   532, -1036,   534,   535,   539,   540, -1036,   550,
     556,   181, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   547,   557,   564,   565,    12, -1036, -1036,
   -1036, -1036,   570,   587,   588,   629,   589,   591,   593,   355,
     576, -1036, -1036,   659,   684,   598,   688,   703,   704,   691,
     692,   693,   694,   696,   698,   700,   701,   702,   705,   708,
     590, -1036,   594,   595, -1036,   104, -1036, -1036, -1036, -1036,
     617,   604, -1036,   603,   606,   605,   607,   608,   609,    11,
   -1036, -1036, -1036, -1036, -1036,   712,   615, -1036,   616,   614,
   -1036,   618,    69, -1036, -1036, -1036, -1036,   620,   622,   623,
   -1036,   626,   562,   628,   633,   634,   637,   640,   642,   644,
     645,   647, -1036, -1036,   728,   737,   355,   648,   744,   748,
     769,   355,   771,   772,   355,   760,   775,   778,   355,   779,
     779,   661, -1036, -1036,   770,  -124,   773,   685,   776,   777,
     663,   780,   784,   789,   785,   788,   791,   793,   673, -1036,
     795,   796,   697, -1036,   706, -1036,   798,   801,   707, -1036,
     711,   713,   714,   716,   721,   727,   729,   731,   732,   734,
     738,   739,   740,   742,   743,   746,   747,   752,   753,   754,
     755,   757,   758,   759,   762,   782,   695,   763,   764,   765,
     766,   767,   768,   774,   781,   783,   786,   787,   790,   792,
     794,   797,   799,   800,   802,   803,   804, -1036, -1036,   806,
     717,   709,   807,   817,   808,   810,   829,   805, -1036,   842,
     849,   809, -1036, -1036,   853,   865,   811,   888,   812, -1036,
     813,   815, -1036, -1036,   875,   876,   816, -1036, -1036,   877,
     814,   818,   878,   880,   881,   819,   820,   882,   883,   822,
   -1036, -1036,   884,   885,   887,   824, -1036,   825,   826,   827,
     828,   830,   831,   832,   833, -1036,   834,   835,   836,   837,
     838,   839,   840,   841,   843,   844,   845,   846,   847,   848,
     850,   851,   852, -1036, -1036,   889,   854,   855, -1036,   856,
   -1036,     8, -1036,   890,   893,   894,   896,   858, -1036,   859,
   -1036, -1036,   898,   857,   900,   861, -1036, -1036, -1036, -1036,
   -1036,   355,   355,   355,   355,   355,   355,   355, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,   862,
     863,   864,    -2,   866,   867,   868,   869,   870,   871,   872,
     873,   874,   879,   886,   320,   891,   892, -1036,   895,   897,
     899,   901,   902,   903,   904,    -5,   905,   906,   907,   908,
     909,   910,   911, -1036,   912,   913, -1036, -1036,   914,   915,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,  -158, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
    -150, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036,   916,   917,   480,   918,   919,   920,   921,   922,
   -1036,   923,   924, -1036,   925,   926,   -30,   821,   143, -1036,
   -1036, -1036, -1036,   927,   928, -1036,   929,   930,   469,   931,
     932,   933,   934,   741,   935,   936, -1036,   937,   938,   939,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   940,   417, -1036, -1036,
     941,   942,   943, -1036,   120, -1036, -1036, -1036, -1036,   944,
     947,   948,   949, -1036, -1036,   950,   548,   951, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,   -50, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   779,   779,   779, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
     -31, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   782, -1036,   695, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,    41,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,    61, -1036,   961,   888,   952, -1036, -1036,
   -1036, -1036, -1036, -1036,   860, -1036,   953,   954, -1036, -1036,
     955, -1036, -1036, -1036,   956, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036,    78, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,   112, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   114, -1036, -1036,   958,   -79,   959,   957,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   119, -1036, -1036, -1036,
      -2, -1036, -1036, -1036, -1036,    -5, -1036, -1036, -1036,   480,
   -1036,   -30, -1036, -1036, -1036,   974,   946,   975,   977,   976,
   -1036,   469, -1036,   741, -1036,   417,   963,   964,   965,   258,
   -1036, -1036,   548, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036,   122, -1036, -1036, -1036,
     258, -1036
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
     649,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     640,   641,   642,   643,   644,   647,   645,   646,   648,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   350,     0,     0,   348,   349,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   615,     0,
       0,     0,     0,   271,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     240,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     238,   239,   241,   251,   252,   253,     0,     0,     0,     0,
       0,     0,     0,   426,     0,     0,     0,     0,     0,     0,
       0,     0,   401,   402,   403,   404,   405,   406,   407,   409,
     408,   411,   415,   412,   413,   414,   410,   452,     0,     0,
       0,   449,   450,   451,     0,     0,   456,   467,     0,     0,
       0,   464,   465,   466,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     471,     0,     0,     0,   318,     0,     0,     0,     0,     0,
       0,   304,   305,   306,   307,   312,   308,   309,   310,   311,
     443,     0,     0,     0,   440,   441,   442,     0,     0,     0,
     279,     0,   289,     0,   287,   288,   290,   291,    49,     0,
       0,     0,    45,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,   201,     0,     0,     0,     0,   175,     0,
       0,     0,   155,   156,   157,   158,   159,   162,   163,   164,
     161,   160,   165,     0,     0,     0,     0,     0,   338,   339,
     340,   341,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   639,    72,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,   384,     0,   379,   380,   381,   127,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     112,   113,   115,   114,   116,     0,     0,   347,     0,     0,
     362,     0,     0,   355,   356,   357,   358,     0,     0,     0,
      90,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   614,   254,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   235,   416,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   400,
       0,     0,     0,   448,     0,   455,     0,     0,     0,   463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   470,   313,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   303,     0,
       0,     0,   439,   292,     0,     0,     0,     0,     0,   286,
       0,     0,    44,   106,     0,     0,     0,   102,   166,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     154,   342,     0,     0,     0,     0,   337,     0,     0,     0,
       0,     0,     0,     0,     0,   638,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,   382,     0,     0,     0,   378,     0,
     122,     0,   117,     0,     0,     0,     0,     0,   111,     0,
     346,   359,     0,     0,     0,     0,   354,    99,    98,    97,
     636,    28,    28,    28,    28,    28,    28,    28,    30,    29,
     637,   628,   629,   630,   631,   632,   633,   635,   634,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   399,     0,     0,   447,   460,     0,     0,
     462,   531,   535,   519,   520,   550,   522,   613,   558,   523,
     524,   555,   530,   529,   538,   528,   525,   526,   534,   533,
     532,   556,   521,   611,   612,   554,   597,   591,   607,   592,
     593,   594,   602,   610,   595,   604,   608,   598,   609,   599,
     603,   596,   606,   601,   600,   605,     0,   590,   570,   571,
     572,   565,   583,   566,   567,   568,   578,   586,   569,   580,
     584,   574,   585,   575,   579,   573,   582,   577,   576,   581,
       0,   564,   551,   549,   552,   557,   553,   540,   547,   548,
     545,   546,   541,   542,   543,   544,   559,   560,   527,   537,
     536,   539,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,   438,     0,     0,     0,   297,   293,   296,
     278,    50,    51,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,     0,
     336,   651,   650,   656,   654,   657,   652,   653,   655,    86,
      81,    89,    80,    87,    88,    79,    83,    82,    74,    73,
      78,    75,    77,    76,    84,    85,     0,     0,   377,   128,
       0,     0,     0,   140,     0,   132,   133,   135,   134,     0,
       0,     0,     0,   110,   351,     0,     0,     0,   353,    31,
      32,    33,    34,    35,    36,    37,   266,   267,   258,   276,
     275,     0,   274,   259,   261,   263,   270,   262,   260,   269,
     255,   268,   257,   256,    38,    38,    38,    40,    39,   264,
     265,   421,   424,   425,   435,   432,   418,   433,   430,   431,
       0,   429,   434,   417,   423,   420,   422,   436,   419,   453,
     454,   468,   469,   588,     0,   562,     0,   316,   317,   327,
     323,   324,   326,   331,   328,   329,   322,   330,   325,     0,
     321,   315,   334,   333,   332,   314,   445,   444,   300,   299,
     284,   285,   283,     0,   282,     0,     0,     0,   107,   108,
     174,   171,   220,   232,   208,   217,     0,   206,   211,   226,
       0,   219,   224,   230,   210,   213,   221,   223,   227,   218,
     225,   214,   231,   216,   222,   212,   215,     0,   204,   167,
     169,   172,   173,   184,   185,   186,   179,   197,   180,   181,
     182,   192,   200,   183,   194,   198,   188,   199,   189,   193,
     187,   196,   191,   190,   195,     0,   178,   168,   170,   345,
     343,   344,   383,   388,   394,   397,   390,   396,   391,   395,
     393,   389,   392,     0,   387,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   360,   366,   372,   375,   368,
     374,   369,   373,   371,   367,   370,     0,   365,   361,   272,
       0,    41,    42,    43,   427,     0,   589,   563,   319,     0,
     280,     0,   298,   295,   294,     0,     0,     0,     0,     0,
     202,     0,   176,     0,   385,     0,     0,     0,     0,     0,
     130,   363,     0,   273,   428,   320,   281,   207,   229,   205,
     228,   209,   203,   177,   386,   137,   139,   138,   150,   149,
     145,   147,   151,   148,   144,   146,     0,   143,   364,   141,
       0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1036, -1036, -1036,   -93,  -296, -1035,  -619, -1036, -1036,   823,
   -1036, -1036, -1036, -1036,   945, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,   966, -1036, -1036, -1036, -1036, -1036,
   -1036,   545, -1036, -1036, -1036, -1036, -1036,   454, -1036, -1036,
   -1036, -1036, -1036, -1036,   960, -1036, -1036, -1036, -1036,    30,
   -1036, -1036, -1036, -1036, -1036,  -258, -1036, -1036, -1036,   543,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,  -220, -1036, -1036, -1036,  -209, -1036, -1036, -1036,   718,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,  -151,
   -1036, -1036, -1036, -1036, -1036,  -138, -1036,   635, -1036, -1036,
   -1036,   -20, -1036, -1036, -1036, -1036, -1036,   657, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036,  -130, -1036, -1036, -1036, -1036,
   -1036, -1036,   596, -1036, -1036, -1036, -1036, -1036,   962, -1036,
   -1036, -1036, -1036,   528, -1036, -1036, -1036, -1036, -1036,  -148,
   -1036, -1036, -1036,   560, -1036, -1036, -1036, -1036,  -143, -1036,
   -1036, -1036,   967, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036,  -117, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036,   656, -1036, -1036, -1036, -1036, -1036,   745,
   -1036, -1036, -1036, -1036,  1011, -1036, -1036, -1036, -1036,   733,
   -1036, -1036, -1036, -1036,  1007, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,    72, -1036,
   -1036, -1036,    84, -1036, -1036, -1036, -1036, -1036,  1086, -1036,
   -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036,
   -1036,   968, -1036, -1036, -1036, -1036, -1036, -1036, -1036, -1036
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   808,   809,  1067,  1068,    27,   213,   214,
     215,   216,    28,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,    29,    77,    78,    79,    80,    81,    30,    63,
     486,   487,   488,   489,    31,    70,   569,   570,   571,   572,
     573,   574,    32,   279,   280,   281,   282,   283,  1024,  1025,
    1026,  1027,  1028,  1208,  1286,  1287,    33,    64,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   736,
    1185,  1186,   512,   731,  1157,  1158,    34,    53,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   607,  1051,  1052,
      35,    61,   472,   716,  1123,  1124,   473,   474,   475,  1127,
     968,   969,   476,   477,    36,    59,   450,   451,   452,   453,
     454,   455,   456,   701,  1109,  1110,   457,   458,   459,    37,
      65,   517,   518,   519,   520,   521,    38,   287,   288,   289,
      39,    72,   582,   583,   584,   585,   586,   793,  1226,  1227,
      40,    68,   555,   556,   557,   558,   776,  1203,  1204,    41,
      54,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   630,  1080,  1081,   372,   373,   374,   375,   376,
      42,    60,   463,   464,   465,   466,    43,    55,   380,   381,
     382,   383,    44,   110,   111,   112,    45,    57,   390,   391,
     392,   393,    46,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   420,   930,   931,   203,
     419,   906,   907,   204,   205,   206,    47,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    48,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     835,   836,   593,  1078,   220,   596,    73,   598,   599,  1020,
      73,   285,   564,   513,   285,  1120,   210,    49,    50,   277,
     483,   377,   108,    51,   210,   467,   377,   834,   483,  1231,
    1232,  1233,   108,   387,    74,   239,   221,   513,    74,   460,
     683,    52,    75,    56,   684,   222,    75,  1049,   223,   224,
     839,   840,   514,   225,   226,   227,    58,    62,   685,    66,
     114,   240,   686,   241,    67,   115,   116,  1093,   117,   118,
     578,  1094,   460,   119,    69,  1095,   514,   468,   228,  1096,
     378,   109,   120,   121,   469,   378,   470,    71,   242,   515,
     122,   109,   277,   123,   124,   125,   484,   243,   105,   651,
     126,   653,   654,    76,   484,   552,  1021,    76,   286,   565,
     211,   286,   664,   515,   106,   127,   128,   669,   211,  1050,
     244,  1020,  1257,   107,   245,   129,   678,   679,   130,   131,
     388,   212,   246,   113,   516,   247,   248,   132,   692,   212,
     694,   695,   379,   471,   133,   309,   134,   379,   135,   207,
     136,   578,   137,   138,   389,   208,  1121,   209,   516,   441,
     461,   310,   311,   139,   249,  1122,   312,   579,   140,   141,
     217,   142,   143,   144,   566,  1229,   145,   442,   552,  1230,
     250,   387,   490,   251,   252,   253,   218,   219,  -129,   485,
    1079,   564,   567,   461,  1234,   276,   443,   485,  1235,  1022,
     491,   146,   553,   346,   284,   347,   313,   348,   568,   290,
     291,   147,   148,   149,   150,   151,   152,   153,  1021,   492,
     444,   349,   292,  1023,   314,   315,   316,   317,   318,   530,
     254,   295,   319,   754,    82,   278,   320,   787,   745,   576,
     350,   481,   321,   493,   561,   726,   642,   385,   579,   563,
     718,   322,   323,   255,   256,   351,   462,   352,    83,    84,
     550,  -129,   324,   293,   353,    85,  1238,   154,   155,   156,
    1239,   157,   158,   445,   294,   553,   354,   297,   388,   494,
     159,   446,   447,   325,   580,   439,  1240,   581,   565,   462,
    1241,    86,    87,   467,   298,   795,   495,   711,   299,   490,
     355,   448,   389,  1250,    88,    89,    90,  1251,   278,   300,
     821,  1022,    91,    92,   301,   826,   302,   491,   829,   554,
     441,   356,   833,  1278,   303,  1279,   304,   326,   496,   497,
     777,  1064,  1065,  1066,   305,  1023,   492,  1252,   442,  1254,
     357,  1253,   478,  1255,  1261,   468,  1209,  1289,  1262,   358,
     532,  1290,   469,   566,   470,   306,   384,   443,   394,   395,
     493,   396,   397,   398,   399,   580,   400,   401,   581,  1280,
     621,   567,  1126,   402,   403,   404,   449,   405,   559,   498,
     406,   444,   407,   408,   707,   409,  1281,   568,   410,   411,
     412,   413,   554,   414,   415,   416,   494,   417,   359,   499,
     418,   421,   422,   500,   423,   587,   648,   739,   588,   589,
     424,   471,   239,   495,   114,   425,   426,   427,   590,   115,
     116,   360,   117,   118,  1282,  1283,   834,   119,   638,   428,
     591,   429,   430,   431,   445,   432,   120,   121,   240,   433,
     241,   434,   446,   447,   122,   496,   497,   123,   124,   125,
     435,   436,   437,   438,   126,   479,   480,   522,   523,   307,
     524,   592,   448,   525,   526,   242,   527,   528,   529,   127,
     128,   533,   534,  1132,   243,   535,  1284,   536,   537,   129,
     538,  1285,   130,   131,  1193,   539,   594,   540,   541,  1133,
    1134,   132,   542,   543,   544,  1099,   498,   244,   133,  1135,
     134,   245,   135,   545,   136,   546,   137,   138,   547,   246,
     548,   549,   247,   248,   560,   575,   499,   139,   595,  1100,
     500,   597,   140,   141,   600,   142,   143,   144,   601,   602,
     145,   603,   652,  1136,  1137,   604,  1138,   449,   346,   605,
     347,   249,   348,   606,   608,  1194,   609,   644,  1101,   610,
     611,   612,   623,   613,   614,   146,   349,   250,   615,   616,
     251,   252,   253,   617,  1139,   147,   148,   149,   150,   151,
     152,   153,  1140,   618,   619,   350,  1195,   620,   624,  1102,
    1103,    82,   625,   656,  1196,  1104,   626,   627,  1258,   628,
     351,   629,   352,  1197,  1141,   631,  1142,  1143,   632,   353,
     633,   634,   635,   636,   637,    83,    84,   254,   640,  1105,
     641,   354,    85,   645,  1144,  1216,   650,  1198,   646,  1199,
    1200,   154,   155,   156,  1106,   157,   158,   647,   655,   658,
     255,   256,   657,  1201,   159,   355,  1145,   659,    86,    87,
    1202,  1146,   660,   661,   662,  1147,   663,   665,   666,  1148,
     667,    88,    89,    90,  1149,   668,   356,   670,  1150,    91,
      92,   671,     2,     3,   672,   673,     4,   674,   592,  1151,
     675,  1152,  1153,   676,  1154,   357,  1217,   677,     5,   680,
     681,     6,   682,     7,   358,  1155,  1107,   691,   687,   688,
       8,   689,  1156,   801,   802,   803,   804,   805,   806,   807,
     309,   690,     9,   693,  1108,    10,    11,  1218,  1039,  1040,
    1041,  1042,  1043,  1044,  1045,  1219,   310,   311,   696,   699,
     697,   312,   698,    12,  1220,   220,   700,    13,   702,   703,
     704,   705,   706,   359,   709,   710,   714,   713,    14,   720,
     908,   715,   909,   910,   717,   721,   722,   723,  1221,   750,
    1222,  1223,   724,   725,   728,   729,   360,   221,    15,    16,
     730,   313,   732,   733,  1224,   756,   222,   734,   735,   223,
     224,  1225,   741,    17,   225,   226,   227,   747,   737,   314,
     315,   316,   317,   318,   738,   742,  1163,   319,  1164,  1165,
      18,   320,   743,   744,   748,   749,   751,   321,   752,   228,
     753,   755,    19,    20,   757,   758,   322,   323,   759,   760,
     761,   762,   763,   764,   765,   773,   766,   324,   767,   774,
     768,   769,   770,   775,   779,   771,    21,   886,   772,   780,
     781,   782,   789,   783,   819,   784,   785,   786,   325,    22,
     790,   791,   792,   820,    23,   797,   794,   798,   799,    24,
     823,   800,    25,   810,   824,   911,   912,   913,   811,   812,
     914,   915,   813,   916,   917,   814,   918,   815,   919,   816,
     817,   920,   818,   921,   922,   825,   822,   827,   828,   923,
     830,   831,   326,   924,   832,   834,   837,   925,   926,   927,
     838,   845,   842,   841,   928,   848,   843,   844,   853,   929,
     846,  1166,  1167,  1168,   847,   849,  1169,  1170,   850,  1171,
    1172,   851,  1173,   852,  1174,   854,   855,  1175,   858,  1176,
    1177,   859,   856,   956,   953,  1178,   952,   955,   957,  1179,
     958,   857,   860,  1180,  1181,  1182,   861,   954,   862,   863,
    1183,   864,   887,   888,   889,  1184,   865,   890,   891,   959,
     892,   893,   866,   894,   867,   895,   868,   869,   896,   870,
     897,   898,   961,   871,   872,   873,   899,   874,   875,   962,
     900,   876,   877,   964,   901,   902,   903,   878,   879,   880,
     881,   904,   882,   883,   884,   965,   905,   885,   932,   933,
     934,   935,   936,   937,   967,   973,   974,   976,   979,   938,
     980,   981,   984,   985,   987,   988,   939,   989,   940,  1016,
    1029,   941,   942,  1030,  1031,   943,  1032,   944,  1035,   945,
    1037,   977,   946,   788,   947,   948,   982,   949,   950,   951,
     960,   727,  1291,  1273,   963,  1125,   482,   970,   971,   966,
     972,   975,  1272,   296,   740,   622,   978,   986,   983,   990,
     991,   992,   993,   994,  1210,   995,   996,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1242,  1007,  1008,
    1009,  1010,  1011,  1012,  1268,  1013,  1014,  1015,  1256,  1263,
    1018,  1019,  1017,  1033,  1034,  1036,  1038,  1046,  1047,  1048,
    1245,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1267,  1269,  1271,  1266,  1062,  1270,  1243,   708,   719,  1265,
     796,  1063,  1274,   746,  1288,   778,  1069,  1070,  1264,   712,
    1071,   386,  1072,   649,  1073,   643,  1074,  1075,  1076,  1077,
    1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,  1090,  1091,
    1092,  1097,  1098,  1111,  1112,  1113,  1114,  1115,  1116,  1117,
    1118,  1119,  1128,  1129,  1130,  1131,  1159,  1160,  1161,  1162,
    1187,  1188,  1189,  1190,  1191,  1192,  1205,   440,  1237,  1211,
    1206,  1207,  1212,  1213,  1214,  1215,  1228,  1244,  1236,   308,
       0,     0,  1260,  1246,  1247,  1248,  1249,  1259,  1275,  1276,
    1277,     0,     0,     0,     0,     0,     0,   531,     0,     0,
       0,     0,   551,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   562,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   577,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   639
};

static const yytype_int16 yycheck[] =
{
     619,   620,   298,     8,     1,   301,     1,   303,   304,     1,
       1,     1,     1,     1,     1,    45,     1,   225,   226,     1,
       1,     1,     1,   227,     1,     1,     1,   106,     1,  1064,
    1065,  1066,     1,     1,    29,     1,    33,     1,    29,     1,
     207,   227,    37,   227,   211,    42,    37,    49,    45,    46,
     174,   175,    40,    50,    51,    52,   227,   227,   207,   227,
       1,    27,   211,    29,   227,     6,     7,   225,     9,    10,
       1,   229,     1,    14,   227,   225,    40,    53,    75,   229,
      60,    60,    23,    24,    60,    60,    62,   227,    54,    77,
      31,    60,     1,    34,    35,    36,    77,    63,   227,   395,
      41,   397,   398,    98,    77,     1,    98,    98,    98,    98,
      95,    98,   408,    77,   227,    56,    57,   413,    95,   121,
      86,     1,   201,   227,    90,    66,   422,   423,    69,    70,
      98,   116,    98,   227,   122,   101,   102,    78,   434,   116,
     436,   437,   122,   119,    85,     1,    87,   122,    89,   227,
      91,     1,    93,    94,   122,   227,   186,   227,   122,     1,
     122,    17,    18,   104,   130,   195,    22,    98,   109,   110,
     227,   112,   113,   114,   163,   225,   117,    19,     1,   229,
     146,     1,     1,   149,   150,   151,   227,   227,   170,   170,
     195,     1,   181,   122,   225,   227,    38,   170,   229,   191,
      19,   142,    98,     1,   227,     3,    62,     5,   197,   227,
     225,   152,   153,   154,   155,   156,   157,   158,    98,    38,
      62,    19,   228,   215,    80,    81,    82,    83,    84,   226,
     196,   226,    88,   529,     1,   217,    92,   226,   226,   226,
      38,   226,    98,    62,   226,   226,   226,   226,    98,   170,
     226,   107,   108,   219,   220,    53,   218,    55,    25,    26,
     226,   170,   118,   228,    62,    32,   225,   208,   209,   210,
     229,   212,   213,   115,   228,    98,    74,   228,    98,    98,
     221,   123,   124,   139,   215,   226,   225,   218,    98,   218,
     229,    58,    59,     1,   228,   226,   115,   226,   228,     1,
      98,   143,   122,   225,    71,    72,    73,   229,   217,   228,
     606,   191,    79,    80,   228,   611,   228,    19,   614,   215,
       1,   119,   618,    65,   228,    67,   228,   183,   147,   148,
     226,    11,    12,    13,   228,   215,    38,   225,    19,   225,
     138,   229,   225,   229,   225,    53,   226,   225,   229,   147,
     225,   229,    60,   163,    62,   228,   228,    38,   228,   228,
      62,   228,   228,   228,   228,   215,   228,   228,   218,   111,
     226,   181,   229,   228,   228,   228,   218,   228,   225,   198,
     228,    62,   228,   228,   226,   228,   128,   197,   228,   228,
     228,   228,   215,   228,   228,   228,    98,   228,   196,   218,
     228,   228,   228,   222,   228,   120,   226,   226,   120,   120,
     228,   119,     1,   115,     1,   228,   228,   228,   225,     6,
       7,   219,     9,    10,   166,   167,   106,    14,   226,   228,
     106,   228,   228,   228,   115,   228,    23,    24,    27,   228,
      29,   228,   123,   124,    31,   147,   148,    34,    35,    36,
     228,   228,   228,   228,    41,   228,   228,   228,   228,   226,
     228,   106,   143,   228,   228,    54,   228,   228,   228,    56,
      57,   228,   228,     4,    63,   228,   218,   228,   228,    66,
     228,   223,    69,    70,    67,   228,   207,   228,   228,    20,
      21,    78,   228,   228,   228,    15,   198,    86,    85,    30,
      87,    90,    89,   228,    91,   228,    93,    94,   228,    98,
     228,   228,   101,   102,   228,   228,   218,   104,   106,    39,
     222,   106,   109,   110,   106,   112,   113,   114,   106,   225,
     117,   225,   106,    64,    65,   228,    67,   218,     1,   228,
       3,   130,     5,   228,   228,   128,   228,   120,    68,   228,
     228,   228,   225,   228,   228,   142,    19,   146,   228,   228,
     149,   150,   151,   228,    95,   152,   153,   154,   155,   156,
     157,   158,   103,   228,   228,    38,   159,   228,   228,    99,
     100,     1,   228,   106,   167,   105,   228,   228,  1207,   228,
      53,   228,    55,   176,   125,   228,   127,   128,   228,    62,
     228,   228,   228,   228,   228,    25,    26,   196,   228,   129,
     228,    74,    32,   225,   145,    67,   207,   200,   228,   202,
     203,   208,   209,   210,   144,   212,   213,   228,   207,   106,
     219,   220,   207,   216,   221,    98,   167,   106,    58,    59,
     223,   172,   106,   207,   207,   176,   207,   106,   106,   180,
     106,    71,    72,    73,   185,   106,   119,   106,   189,    79,
      80,   106,     0,     1,   106,   106,     4,   207,   106,   200,
     228,   202,   203,   228,   205,   138,   128,   207,    16,   207,
     207,    19,   207,    21,   147,   216,   206,   106,   207,   207,
      28,   207,   223,   131,   132,   133,   134,   135,   136,   137,
       1,   207,    40,   207,   224,    43,    44,   159,   801,   802,
     803,   804,   805,   806,   807,   167,    17,    18,   207,   228,
     225,    22,   225,    61,   176,     1,   228,    65,   228,   228,
     228,   228,   228,   196,   228,   228,   228,   225,    76,   120,
      45,   228,    47,    48,   228,   120,   225,   225,   200,   120,
     202,   203,   228,   228,   225,   228,   219,    33,    96,    97,
     228,    62,   228,   228,   216,   106,    42,   228,   228,    45,
      46,   223,   225,   111,    50,    51,    52,   207,   228,    80,
      81,    82,    83,    84,   228,   228,    45,    88,    47,    48,
     128,    92,   228,   228,   207,   207,   207,    98,   207,    75,
     207,   225,   140,   141,   120,   207,   107,   108,   120,   106,
     106,   120,   120,   120,   120,   225,   120,   118,   120,   225,
     120,   120,   120,   228,   207,   120,   164,    45,   120,   225,
     227,   225,   120,   228,   106,   228,   228,   228,   139,   177,
     225,   225,   228,   106,   182,   225,   228,   225,   225,   187,
     106,   225,   190,   225,   106,   160,   161,   162,   225,   225,
     165,   166,   225,   168,   169,   225,   171,   225,   173,   225,
     225,   176,   225,   178,   179,   106,   228,   106,   106,   184,
     120,   106,   183,   188,   106,   106,   225,   192,   193,   194,
     120,   228,   207,   120,   199,   106,   120,   120,   225,   204,
     120,   160,   161,   162,   120,   120,   165,   166,   120,   168,
     169,   120,   171,   120,   173,   120,   120,   176,   120,   178,
     179,   120,   225,   106,   207,   184,   120,   120,   120,   188,
     120,   225,   225,   192,   193,   194,   225,   228,   225,   225,
     199,   225,   160,   161,   162,   204,   225,   165,   166,   120,
     168,   169,   225,   171,   225,   173,   225,   225,   176,   225,
     178,   179,   120,   225,   225,   225,   184,   225,   225,   120,
     188,   225,   225,   120,   192,   193,   194,   225,   225,   225,
     225,   199,   225,   225,   225,   120,   204,   225,   225,   225,
     225,   225,   225,   225,   106,   120,   120,   120,   120,   225,
     120,   120,   120,   120,   120,   120,   225,   120,   225,   120,
     120,   225,   225,   120,   120,   225,   120,   225,   120,   225,
     120,   207,   225,   569,   225,   225,   207,   225,   225,   225,
     225,   486,  1290,  1253,   225,   214,   213,   225,   225,   228,
     225,   225,  1251,    77,   501,   327,   228,   225,   228,   225,
     225,   225,   225,   225,  1024,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   106,   225,   225,
     225,   225,   225,   225,   128,   225,   225,   225,   120,  1230,
     225,   225,   228,   225,   225,   228,   225,   225,   225,   225,
     230,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     126,   126,   126,  1241,   225,   128,  1126,   450,   473,  1239,
     582,   225,  1255,   517,  1262,   555,   225,   225,  1235,   463,
     225,   110,   225,   390,   225,   380,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   160,  1096,   225,
     228,   228,   225,   225,   225,   225,   225,   225,  1094,    93,
      -1,    -1,   225,   230,   230,   230,   230,   228,   225,   225,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   229,    -1,    -1,
      -1,    -1,   257,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   287,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   361
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   232,     0,     1,     4,    16,    19,    21,    28,    40,
      43,    44,    61,    65,    76,    96,    97,   111,   128,   140,
     141,   164,   177,   182,   187,   190,   233,   238,   243,   263,
     269,   275,   283,   297,   317,   341,   355,   370,   377,   381,
     391,   400,   421,   427,   433,   437,   443,   497,   510,   225,
     226,   227,   227,   318,   401,   428,   227,   438,   227,   356,
     422,   342,   227,   270,   298,   371,   227,   227,   392,   227,
     276,   227,   382,     1,    29,    37,    98,   264,   265,   266,
     267,   268,     1,    25,    26,    32,    58,    59,    71,    72,
      73,    79,    80,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   227,   227,   227,     1,    60,
     434,   435,   436,   227,     1,     6,     7,     9,    10,    14,
      23,    24,    31,    34,    35,    36,    41,    56,    57,    66,
      69,    70,    78,    85,    87,    89,    91,    93,    94,   104,
     109,   110,   112,   113,   114,   117,   142,   152,   153,   154,
     155,   156,   157,   158,   208,   209,   210,   212,   213,   221,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   490,   494,   495,   496,   227,   227,   227,
       1,    95,   116,   239,   240,   241,   242,   227,   227,   227,
       1,    33,    42,    45,    46,    50,    51,    52,    75,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,     1,
      27,    29,    54,    63,    86,    90,    98,   101,   102,   130,
     146,   149,   150,   151,   196,   219,   220,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   227,     1,   217,   284,
     285,   286,   287,   288,   227,     1,    98,   378,   379,   380,
     227,   225,   228,   228,   228,   226,   265,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   499,     1,
      17,    18,    22,    62,    80,    81,    82,    83,    84,    88,
      92,    98,   107,   108,   118,   139,   183,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,     1,     3,     5,    19,
      38,    53,    55,    62,    74,    98,   119,   138,   147,   196,
     219,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   416,   417,   418,   419,   420,     1,    60,   122,
     429,   430,   431,   432,   228,   226,   435,     1,    98,   122,
     439,   440,   441,   442,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   491,
     487,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   226,
     445,     1,    19,    38,    62,   115,   123,   124,   143,   218,
     357,   358,   359,   360,   361,   362,   363,   367,   368,   369,
       1,   122,   218,   423,   424,   425,   426,     1,    53,    60,
      62,   119,   343,   347,   348,   349,   353,   354,   225,   228,
     228,   226,   240,     1,    77,   170,   271,   272,   273,   274,
       1,    19,    38,    62,    98,   115,   147,   148,   198,   218,
     222,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   313,     1,    40,    77,   122,   372,   373,   374,
     375,   376,   228,   228,   228,   228,   228,   228,   228,   228,
     226,   512,   225,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     226,   245,     1,    98,   215,   393,   394,   395,   396,   225,
     228,   226,   285,   170,     1,    98,   163,   181,   197,   277,
     278,   279,   280,   281,   282,   228,   226,   379,     1,    98,
     215,   218,   383,   384,   385,   386,   387,   120,   120,   120,
     225,   106,   106,   235,   207,   106,   235,   106,   235,   235,
     106,   106,   225,   225,   228,   228,   228,   338,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   226,   320,   225,   228,   228,   228,   228,   228,   228,
     413,   228,   228,   228,   228,   228,   228,   228,   226,   403,
     228,   228,   226,   430,   120,   225,   228,   228,   226,   440,
     207,   235,   106,   235,   235,   207,   106,   207,   106,   106,
     106,   207,   207,   207,   235,   106,   106,   106,   106,   235,
     106,   106,   106,   106,   207,   228,   228,   207,   235,   235,
     207,   207,   207,   207,   211,   207,   211,   207,   207,   207,
     207,   106,   235,   207,   235,   235,   207,   225,   225,   228,
     228,   364,   228,   228,   228,   228,   228,   226,   358,   228,
     228,   226,   424,   225,   228,   228,   344,   228,   226,   348,
     120,   120,   225,   225,   228,   228,   226,   272,   225,   228,
     228,   314,   228,   228,   228,   228,   310,   228,   228,   226,
     300,   225,   228,   228,   228,   226,   373,   207,   207,   207,
     120,   207,   207,   207,   235,   225,   106,   120,   207,   120,
     106,   106,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   225,   225,   228,   397,   226,   394,   207,
     225,   227,   225,   228,   228,   228,   228,   226,   278,   120,
     225,   225,   228,   388,   228,   226,   384,   225,   225,   225,
     225,   131,   132,   133,   134,   135,   136,   137,   234,   235,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   106,
     106,   235,   228,   106,   106,   106,   235,   106,   106,   235,
     120,   106,   106,   235,   106,   237,   237,   225,   120,   174,
     175,   120,   207,   120,   120,   228,   120,   120,   106,   120,
     120,   120,   120,   225,   120,   120,   225,   225,   120,   120,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,    45,   160,   161,   162,
     165,   166,   168,   169,   171,   173,   176,   178,   179,   184,
     188,   192,   193,   194,   199,   204,   492,   493,    45,    47,
      48,   160,   161,   162,   165,   166,   168,   169,   171,   173,
     176,   178,   179,   184,   188,   192,   193,   194,   199,   204,
     488,   489,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   120,   207,   228,   120,   106,   120,   120,   120,
     225,   120,   120,   225,   120,   120,   228,   106,   351,   352,
     225,   225,   225,   120,   120,   225,   120,   207,   228,   120,
     120,   120,   207,   228,   120,   120,   225,   120,   120,   120,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   120,   228,   225,   225,
       1,    98,   191,   215,   289,   290,   291,   292,   293,   120,
     120,   120,   120,   225,   225,   120,   228,   120,   225,   234,
     234,   234,   234,   234,   234,   234,   225,   225,   225,    49,
     121,   339,   340,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,    11,    12,    13,   236,   237,   225,
     225,   225,   225,   225,   225,   225,   225,   225,     8,   195,
     414,   415,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   229,   225,   229,   225,   225,    15,
      39,    68,    99,   100,   105,   129,   144,   206,   224,   365,
     366,   225,   225,   225,   225,   225,   225,   225,   225,   225,
      45,   186,   195,   345,   346,   214,   229,   350,   225,   225,
     225,   225,     4,    20,    21,    30,    64,    65,    67,    95,
     103,   125,   127,   128,   145,   167,   172,   176,   180,   185,
     189,   200,   202,   203,   205,   216,   223,   315,   316,   225,
     225,   225,   225,    45,    47,    48,   160,   161,   162,   165,
     166,   168,   169,   171,   173,   176,   178,   179,   184,   188,
     192,   193,   194,   199,   204,   311,   312,   225,   225,   225,
     225,   225,   225,    67,   128,   159,   167,   176,   200,   202,
     203,   216,   223,   398,   399,   225,   228,   228,   294,   226,
     290,   225,   225,   225,   225,   225,    67,   128,   159,   167,
     176,   200,   202,   203,   216,   223,   389,   390,   225,   225,
     229,   236,   236,   236,   225,   229,   493,   489,   225,   229,
     225,   229,   106,   352,   225,   230,   230,   230,   230,   230,
     225,   229,   225,   229,   225,   229,   120,   201,   237,   228,
     225,   225,   229,   340,   415,   366,   346,   126,   128,   126,
     128,   126,   316,   312,   399,   225,   225,   225,    65,    67,
     111,   128,   166,   167,   218,   223,   295,   296,   390,   225,
     229,   296
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
     300,   300,   300,   300,   300,   300,   300,   301,   302,   303,
     304,   305,   306,   307,   308,   310,   309,   311,   311,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   314,   313,   315,   315,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   318,   317,   319,   319,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   338,   337,   339,   339,   340,   340,   342,   341,   344,
     343,   345,   345,   346,   346,   346,   347,   347,   348,   348,
     348,   348,   348,   350,   349,   351,   351,   352,   352,   353,
     354,   356,   355,   357,   357,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   359,   360,   361,   362,   364,   363,
     365,   365,   366,   366,   366,   366,   366,   366,   366,   366,
     366,   366,   367,   368,   369,   371,   370,   372,   372,   373,
     373,   373,   373,   374,   375,   376,   377,   378,   378,   379,
     379,   380,   382,   381,   383,   383,   384,   384,   384,   384,
     385,   386,   388,   387,   389,   389,   390,   390,   390,   390,
     390,   390,   390,   390,   390,   390,   392,   391,   393,   393,
     394,   394,   394,   395,   397,   396,   398,   398,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   401,   400,
     402,   402,   403,   403,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   403,   403,   403,   404,   405,   406,
     407,   408,   409,   410,   411,   411,   413,   412,   414,   414,
     415,   415,   416,   417,   418,   419,   420,   422,   421,   423,
     423,   424,   424,   424,   425,   426,   428,   427,   429,   429,
     430,   430,   430,   431,   432,   433,   434,   434,   435,   435,
     436,   438,   437,   439,   439,   440,   440,   440,   441,   442,
     443,   444,   444,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   472,   473,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   487,   486,   488,   488,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   491,   490,   492,
     492,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   494,   495,   496,   497,   498,   498,   499,   499,   499,
     499,   499,   499,   499,   499,   499,   499,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     511,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     513,   514,   515,   516,   517,   518,   519,   520
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
        case 28:
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2945 "conf_parser.c" /* yacc.c:1646  */
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
#line 2988 "conf_parser.c" /* yacc.c:1646  */
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
#line 3049 "conf_parser.c" /* yacc.c:1646  */
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
#line 3081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 604 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3092 "conf_parser.c" /* yacc.c:1646  */
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
#line 3109 "conf_parser.c" /* yacc.c:1646  */
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
#line 3140 "conf_parser.c" /* yacc.c:1646  */
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
#line 3158 "conf_parser.c" /* yacc.c:1646  */
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
#line 3176 "conf_parser.c" /* yacc.c:1646  */
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
#line 3189 "conf_parser.c" /* yacc.c:1646  */
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
#line 3206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3218 "conf_parser.c" /* yacc.c:1646  */
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
#line 3249 "conf_parser.c" /* yacc.c:1646  */
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
#line 3280 "conf_parser.c" /* yacc.c:1646  */
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
#line 3308 "conf_parser.c" /* yacc.c:1646  */
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
#line 3333 "conf_parser.c" /* yacc.c:1646  */
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
#line 3358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3367 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3403 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3412 "conf_parser.c" /* yacc.c:1646  */
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
#line 3429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3447 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3456 "conf_parser.c" /* yacc.c:1646  */
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
#line 3474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3501 "conf_parser.c" /* yacc.c:1646  */
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
#line 3522 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3531 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3540 "conf_parser.c" /* yacc.c:1646  */
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
#line 3553 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3564 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3580 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3589 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3598 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3643 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3652 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3661 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3673 "conf_parser.c" /* yacc.c:1646  */
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
  }
}
#line 3731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1154 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1160 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1166 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1172 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1178 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1189 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1195 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1212 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3822 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1219 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1231 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3858 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1235 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1239 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3876 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1247 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1255 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1267 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3939 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3948 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1279 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1283 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3993 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4002 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1299 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4011 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1303 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4020 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 205:
#line 1316 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 206:
#line 1320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4047 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1324 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1328 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4065 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1332 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4074 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4083 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1340 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4092 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1348 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1352 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4119 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1356 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1360 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1364 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1368 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1372 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1376 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1380 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1384 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1388 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1392 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1396 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1400 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1404 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1408 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1416 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4263 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1424 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4281 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
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
#line 4298 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
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
#line 4346 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1510 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4355 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1516 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1534 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4391 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1546 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1552 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4436 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1577 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1583 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1589 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4473 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1595 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4485 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1613 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1620 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1624 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4533 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 279:
#line 1640 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4550 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1654 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4568 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 293:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1667 "conf_parser.y" /* yacc.c:1646  */
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
#line 4592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1680 "conf_parser.y" /* yacc.c:1646  */
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
#line 4612 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4621 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1703 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4630 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1712 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4639 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1716 "conf_parser.y" /* yacc.c:1646  */
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
#line 4680 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1765 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4689 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1771 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4698 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1777 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4707 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1783 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4721 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1794 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4730 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1801 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4739 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1809 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4766 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1817 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1821 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4784 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1825 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4793 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1829 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4802 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1833 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4811 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1837 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4820 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
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
#line 4837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1857 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4849 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1866 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1886 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4884 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1897 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1903 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4911 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1924 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1950 "conf_parser.y" /* yacc.c:1646  */
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
#line 4959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1967 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1973 "conf_parser.y" /* yacc.c:1646  */
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
#line 4990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 1992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 1999 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2003 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2007 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2015 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2019 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2027 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2031 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2044 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5103 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2068 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5127 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5145 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2085 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5154 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5163 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2093 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5172 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2097 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2101 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2105 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5199 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2109 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2113 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5217 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2117 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5226 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2126 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
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
#line 5306 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2215 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5315 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2221 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5324 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2227 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2233 "conf_parser.y" /* yacc.c:1646  */
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
#line 5349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2246 "conf_parser.y" /* yacc.c:1646  */
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
#line 5365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2259 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2271 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2275 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2291 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5427 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5441 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2308 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5450 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2314 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5459 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2320 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5468 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2326 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5482 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2341 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5491 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2345 "conf_parser.y" /* yacc.c:1646  */
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
#line 5516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2370 "conf_parser.y" /* yacc.c:1646  */
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
#line 5539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2399 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2403 "conf_parser.y" /* yacc.c:1646  */
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
#line 5583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2435 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2449 "conf_parser.y" /* yacc.c:1646  */
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
#line 5618 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2466 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5627 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2470 "conf_parser.y" /* yacc.c:1646  */
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
#line 5649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2492 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2498 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2559 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5675 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2564 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5683 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2569 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2580 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5708 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2585 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2590 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2595 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5732 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2600 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2605 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5748 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5756 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5780 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5788 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5796 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5804 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2656 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2661 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2666 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2671 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2676 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2681 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5869 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2694 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5893 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2699 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2702 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2707 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2712 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2717 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2722 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5941 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2727 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5957 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5965 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5973 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5989 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5997 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6005 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6013 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2773 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2776 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6029 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6037 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2785 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2788 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6061 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2791 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6069 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2794 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6085 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2800 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6101 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6109 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6117 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6133 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6141 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6149 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6157 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6181 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6189 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2841 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2847 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2850 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6213 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2853 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6221 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2856 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6229 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2859 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2862 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2865 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6253 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2868 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6261 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2874 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6277 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6285 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6293 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6301 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6309 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2889 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6333 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6341 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6349 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2904 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2909 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6381 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2954 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6405 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2959 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2964 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6421 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2969 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6429 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6445 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6461 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3017 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3023 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3035 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6509 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3044 "conf_parser.y" /* yacc.c:1646  */
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
#line 6527 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6536 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6545 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6549 "conf_parser.c" /* yacc.c:1646  */
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
