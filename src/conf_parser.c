/* A Bison parser, made by GNU Bison 3.2.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.2.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "conf_parser.y" /* yacc.c:338  */


#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "parse.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_cluster.h"
#include "conf_gecos.h"
#include "conf_pseudo.h"
#include "conf_resv.h"
#include "conf_service.h"
#include "conf_shared.h"
#include "event.h"
#include "id.h"
#include "log.h"
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "server.h"
#include "hostmask.h"
#include "listener.h"
#include "user.h"
#include "motd.h"

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
    max_perip_local,
    max_perip_global,
    con_freq,
    min_idle,
    max_idle,
    max_total,
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
    xfree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    xfree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    xfree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 182 "conf_parser.c" /* yacc.c:338  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
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
    DEFAULT_FLOODTIME = 280,
    DEFAULT_JOIN_FLOOD_COUNT = 281,
    DEFAULT_JOIN_FLOOD_TIME = 282,
    DEFAULT_MAX_CLIENTS = 283,
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
    FLATTEN_LINKS_DELAY = 299,
    FLATTEN_LINKS_FILE = 300,
    GECOS = 301,
    GENERAL = 302,
    HIDDEN = 303,
    HIDDEN_NAME = 304,
    HIDE_CHANS = 305,
    HIDE_IDLE = 306,
    HIDE_IDLE_FROM_OPERS = 307,
    HIDE_SERVER_IPS = 308,
    HIDE_SERVERS = 309,
    HIDE_SERVICES = 310,
    HOST = 311,
    HUB = 312,
    HUB_MASK = 313,
    INVISIBLE_ON_CONNECT = 314,
    INVITE_CLIENT_COUNT = 315,
    INVITE_CLIENT_TIME = 316,
    INVITE_DELAY_CHANNEL = 317,
    INVITE_EXPIRE_TIME = 318,
    IP = 319,
    IRCD_AUTH = 320,
    IRCD_FLAGS = 321,
    IRCD_SID = 322,
    JOIN = 323,
    KILL = 324,
    KILL_CHASE_TIME_LIMIT = 325,
    KLINE = 326,
    KLINE_EXEMPT = 327,
    KLINE_MIN_CIDR = 328,
    KLINE_MIN_CIDR6 = 329,
    KNOCK_CLIENT_COUNT = 330,
    KNOCK_CLIENT_TIME = 331,
    KNOCK_DELAY_CHANNEL = 332,
    LEAF_MASK = 333,
    LISTEN = 334,
    MASK = 335,
    MAX_ACCEPT = 336,
    MAX_BANS = 337,
    MAX_BANS_LARGE = 338,
    MAX_CHANNELS = 339,
    MAX_IDLE = 340,
    MAX_INVITES = 341,
    MAX_NICK_CHANGES = 342,
    MAX_NICK_LENGTH = 343,
    MAX_NICK_TIME = 344,
    MAX_NUMBER = 345,
    MAX_TARGETS = 346,
    MAX_TOPIC_LENGTH = 347,
    MAX_WATCH = 348,
    MIN_IDLE = 349,
    MIN_NONWILDCARD = 350,
    MIN_NONWILDCARD_SIMPLE = 351,
    MODULE = 352,
    MODULES = 353,
    MOTD = 354,
    NAME = 355,
    NEED_IDENT = 356,
    NEED_PASSWORD = 357,
    NETWORK_DESC = 358,
    NETWORK_NAME = 359,
    NICK = 360,
    NO_OPER_FLOOD = 361,
    NO_TILDE = 362,
    NUMBER = 363,
    NUMBER_PER_CIDR = 364,
    NUMBER_PER_IP_GLOBAL = 365,
    NUMBER_PER_IP_LOCAL = 366,
    OPER_ONLY_UMODES = 367,
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
    SECONDS = 389,
    MINUTES = 390,
    HOURS = 391,
    DAYS = 392,
    WEEKS = 393,
    MONTHS = 394,
    YEARS = 395,
    SEND_PASSWORD = 396,
    SENDQ = 397,
    SERVERHIDE = 398,
    SERVERINFO = 399,
    SHORT_MOTD = 400,
    SPOOF = 401,
    SPOOF_NOTICE = 402,
    SQUIT = 403,
    SSL_CERTIFICATE_FILE = 404,
    SSL_CERTIFICATE_FINGERPRINT = 405,
    SSL_CONNECTION_REQUIRED = 406,
    SSL_DH_ELLIPTIC_CURVE = 407,
    SSL_DH_PARAM_FILE = 408,
    SSL_MESSAGE_DIGEST_ALGORITHM = 409,
    STATS_E_DISABLED = 410,
    STATS_I_OPER_ONLY = 411,
    STATS_K_OPER_ONLY = 412,
    STATS_M_OPER_ONLY = 413,
    STATS_O_OPER_ONLY = 414,
    STATS_P_OPER_ONLY = 415,
    STATS_U_OPER_ONLY = 416,
    T_ALL = 417,
    T_BOTS = 418,
    T_CALLERID = 419,
    T_CCONN = 420,
    T_COMMAND = 421,
    T_CLUSTER = 422,
    T_DEAF = 423,
    T_DEBUG = 424,
    T_DLINE = 425,
    T_EXTERNAL = 426,
    T_FARCONNECT = 427,
    T_FILE = 428,
    T_FULL = 429,
    T_GLOBOPS = 430,
    T_INVISIBLE = 431,
    T_IPV4 = 432,
    T_IPV6 = 433,
    T_LOCOPS = 434,
    T_LOG = 435,
    T_NCHANGE = 436,
    T_NONONREG = 437,
    T_OPME = 438,
    T_PREPEND = 439,
    T_PSEUDO = 440,
    T_RECVQ = 441,
    T_REJ = 442,
    T_RESTART = 443,
    T_SERVER = 444,
    T_SERVICE = 445,
    T_SERVNOTICE = 446,
    T_SET = 447,
    T_SHARED = 448,
    T_SIZE = 449,
    T_SKILL = 450,
    T_SOFTCALLERID = 451,
    T_SPY = 452,
    T_SSL = 453,
    T_SSL_CIPHER_LIST = 454,
    T_TARGET = 455,
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
    THROTTLE_COUNT = 466,
    THROTTLE_TIME = 467,
    TKLINE_EXPIRE_NOTICES = 468,
    TMASKED = 469,
    TS_MAX_DELTA = 470,
    TS_WARN_DELTA = 471,
    TWODOTS = 472,
    TYPE = 473,
    UNKLINE = 474,
    USE_LOGGING = 475,
    USER = 476,
    VHOST = 477,
    VHOST6 = 478,
    WARN_NO_CONNECT_BLOCK = 479,
    WHOIS = 480,
    WHOWAS_HISTORY_LENGTH = 481,
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
#define CLOSE 275
#define CONNECT 276
#define CONNECTFREQ 277
#define CYCLE_ON_HOST_CHANGE 278
#define DEFAULT_FLOODCOUNT 279
#define DEFAULT_FLOODTIME 280
#define DEFAULT_JOIN_FLOOD_COUNT 281
#define DEFAULT_JOIN_FLOOD_TIME 282
#define DEFAULT_MAX_CLIENTS 283
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
#define FLATTEN_LINKS_DELAY 299
#define FLATTEN_LINKS_FILE 300
#define GECOS 301
#define GENERAL 302
#define HIDDEN 303
#define HIDDEN_NAME 304
#define HIDE_CHANS 305
#define HIDE_IDLE 306
#define HIDE_IDLE_FROM_OPERS 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SERVICES 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define INVISIBLE_ON_CONNECT 314
#define INVITE_CLIENT_COUNT 315
#define INVITE_CLIENT_TIME 316
#define INVITE_DELAY_CHANNEL 317
#define INVITE_EXPIRE_TIME 318
#define IP 319
#define IRCD_AUTH 320
#define IRCD_FLAGS 321
#define IRCD_SID 322
#define JOIN 323
#define KILL 324
#define KILL_CHASE_TIME_LIMIT 325
#define KLINE 326
#define KLINE_EXEMPT 327
#define KLINE_MIN_CIDR 328
#define KLINE_MIN_CIDR6 329
#define KNOCK_CLIENT_COUNT 330
#define KNOCK_CLIENT_TIME 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LISTEN 334
#define MASK 335
#define MAX_ACCEPT 336
#define MAX_BANS 337
#define MAX_BANS_LARGE 338
#define MAX_CHANNELS 339
#define MAX_IDLE 340
#define MAX_INVITES 341
#define MAX_NICK_CHANGES 342
#define MAX_NICK_LENGTH 343
#define MAX_NICK_TIME 344
#define MAX_NUMBER 345
#define MAX_TARGETS 346
#define MAX_TOPIC_LENGTH 347
#define MAX_WATCH 348
#define MIN_IDLE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define MOTD 354
#define NAME 355
#define NEED_IDENT 356
#define NEED_PASSWORD 357
#define NETWORK_DESC 358
#define NETWORK_NAME 359
#define NICK 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP_GLOBAL 365
#define NUMBER_PER_IP_LOCAL 366
#define OPER_ONLY_UMODES 367
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
#define SECONDS 389
#define MINUTES 390
#define HOURS 391
#define DAYS 392
#define WEEKS 393
#define MONTHS 394
#define YEARS 395
#define SEND_PASSWORD 396
#define SENDQ 397
#define SERVERHIDE 398
#define SERVERINFO 399
#define SHORT_MOTD 400
#define SPOOF 401
#define SPOOF_NOTICE 402
#define SQUIT 403
#define SSL_CERTIFICATE_FILE 404
#define SSL_CERTIFICATE_FINGERPRINT 405
#define SSL_CONNECTION_REQUIRED 406
#define SSL_DH_ELLIPTIC_CURVE 407
#define SSL_DH_PARAM_FILE 408
#define SSL_MESSAGE_DIGEST_ALGORITHM 409
#define STATS_E_DISABLED 410
#define STATS_I_OPER_ONLY 411
#define STATS_K_OPER_ONLY 412
#define STATS_M_OPER_ONLY 413
#define STATS_O_OPER_ONLY 414
#define STATS_P_OPER_ONLY 415
#define STATS_U_OPER_ONLY 416
#define T_ALL 417
#define T_BOTS 418
#define T_CALLERID 419
#define T_CCONN 420
#define T_COMMAND 421
#define T_CLUSTER 422
#define T_DEAF 423
#define T_DEBUG 424
#define T_DLINE 425
#define T_EXTERNAL 426
#define T_FARCONNECT 427
#define T_FILE 428
#define T_FULL 429
#define T_GLOBOPS 430
#define T_INVISIBLE 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_LOG 435
#define T_NCHANGE 436
#define T_NONONREG 437
#define T_OPME 438
#define T_PREPEND 439
#define T_PSEUDO 440
#define T_RECVQ 441
#define T_REJ 442
#define T_RESTART 443
#define T_SERVER 444
#define T_SERVICE 445
#define T_SERVNOTICE 446
#define T_SET 447
#define T_SHARED 448
#define T_SIZE 449
#define T_SKILL 450
#define T_SOFTCALLERID 451
#define T_SPY 452
#define T_SSL 453
#define T_SSL_CIPHER_LIST 454
#define T_TARGET 455
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
#define THROTTLE_COUNT 466
#define THROTTLE_TIME 467
#define TKLINE_EXPIRE_NOTICES 468
#define TMASKED 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_LOGGING 475
#define USER 476
#define VHOST 477
#define VHOST6 478
#define WARN_NO_CONNECT_BLOCK 479
#define WHOIS 480
#define WHOWAS_HISTORY_LENGTH 481
#define XLINE 482
#define XLINE_EXEMPT 483

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:353  */

  int number;
  char *string;

#line 686 "conf_parser.c" /* yacc.c:353  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  666
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1314

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   483

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

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
       0,   373,   373,   374,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   399,   400,   404,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   415,   415,
     416,   417,   418,   419,   426,   428,   428,   429,   429,   429,
     431,   437,   447,   449,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   470,   479,   488,   497,   506,   515,   524,
     539,   554,   564,   578,   587,   615,   643,   665,   687,   709,
     719,   721,   721,   722,   723,   724,   725,   727,   736,   745,
     759,   758,   776,   776,   777,   777,   777,   779,   785,   796,
     795,   814,   814,   815,   815,   815,   815,   815,   817,   823,
     829,   835,   857,   858,   858,   860,   860,   861,   863,   870,
     870,   883,   884,   886,   886,   887,   887,   889,   897,   900,
     906,   905,   911,   911,   912,   916,   920,   924,   928,   932,
     936,   940,   951,   950,  1011,  1011,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1024,  1030,  1036,
    1042,  1048,  1059,  1065,  1076,  1083,  1082,  1088,  1088,  1089,
    1093,  1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,
    1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1180,  1179,  1185,  1185,  1186,  1190,  1194,  1198,  1202,
    1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,
    1246,  1250,  1254,  1258,  1262,  1266,  1270,  1274,  1278,  1282,
    1286,  1290,  1294,  1298,  1309,  1308,  1366,  1366,  1367,  1368,
    1369,  1370,  1371,  1372,  1373,  1374,  1375,  1376,  1377,  1378,
    1379,  1380,  1381,  1382,  1384,  1390,  1396,  1402,  1408,  1414,
    1420,  1426,  1432,  1439,  1445,  1451,  1457,  1466,  1476,  1475,
    1481,  1481,  1482,  1486,  1497,  1496,  1503,  1502,  1507,  1507,
    1508,  1512,  1516,  1522,  1522,  1523,  1523,  1523,  1523,  1523,
    1525,  1525,  1527,  1527,  1529,  1542,  1559,  1565,  1576,  1575,
    1621,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1632,  1638,  1644,  1650,  1662,  1661,  1667,  1667,  1668,
    1672,  1676,  1680,  1684,  1688,  1692,  1696,  1700,  1704,  1710,
    1724,  1733,  1747,  1746,  1761,  1761,  1762,  1762,  1762,  1762,
    1764,  1770,  1776,  1786,  1788,  1788,  1789,  1789,  1791,  1808,
    1807,  1830,  1830,  1831,  1831,  1831,  1831,  1833,  1839,  1859,
    1858,  1864,  1864,  1865,  1869,  1873,  1877,  1881,  1885,  1889,
    1893,  1897,  1901,  1912,  1911,  1930,  1930,  1931,  1931,  1931,
    1933,  1940,  1939,  1945,  1945,  1946,  1950,  1954,  1958,  1962,
    1966,  1970,  1974,  1978,  1982,  1993,  1992,  2064,  2064,  2065,
    2066,  2067,  2068,  2069,  2070,  2071,  2072,  2073,  2074,  2075,
    2076,  2077,  2078,  2079,  2081,  2087,  2093,  2099,  2112,  2125,
    2131,  2137,  2141,  2148,  2147,  2152,  2152,  2153,  2157,  2163,
    2174,  2180,  2186,  2192,  2208,  2207,  2233,  2233,  2234,  2234,
    2234,  2236,  2256,  2267,  2266,  2293,  2293,  2294,  2294,  2294,
    2296,  2302,  2312,  2314,  2314,  2315,  2315,  2317,  2335,  2334,
    2355,  2355,  2356,  2356,  2356,  2358,  2364,  2374,  2376,  2376,
    2377,  2378,  2379,  2380,  2381,  2382,  2383,  2384,  2385,  2386,
    2387,  2388,  2389,  2390,  2391,  2392,  2393,  2394,  2395,  2396,
    2397,  2398,  2399,  2400,  2401,  2402,  2403,  2404,  2405,  2406,
    2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,  2415,  2416,
    2417,  2418,  2419,  2420,  2421,  2422,  2423,  2426,  2431,  2436,
    2441,  2446,  2452,  2457,  2462,  2467,  2472,  2477,  2482,  2487,
    2492,  2497,  2502,  2507,  2512,  2517,  2523,  2528,  2533,  2538,
    2543,  2548,  2553,  2558,  2561,  2566,  2569,  2574,  2579,  2584,
    2589,  2594,  2599,  2604,  2609,  2614,  2619,  2624,  2629,  2635,
    2634,  2639,  2639,  2640,  2643,  2646,  2649,  2652,  2655,  2658,
    2661,  2664,  2667,  2670,  2673,  2676,  2679,  2682,  2685,  2688,
    2691,  2694,  2697,  2700,  2703,  2709,  2708,  2713,  2713,  2714,
    2717,  2720,  2723,  2726,  2729,  2732,  2735,  2738,  2741,  2744,
    2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,  2771,  2776,
    2781,  2786,  2791,  2800,  2802,  2802,  2803,  2804,  2805,  2806,
    2807,  2808,  2809,  2810,  2811,  2812,  2813,  2814,  2815,  2816,
    2817,  2819,  2824,  2829,  2834,  2839,  2844,  2849,  2854,  2859,
    2864,  2869,  2874,  2879,  2884,  2893,  2895,  2895,  2896,  2897,
    2898,  2899,  2900,  2901,  2902,  2903,  2904,  2905,  2907,  2913,
    2929,  2938,  2944,  2950,  2956,  2965,  2971
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
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION",
  "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6",
  "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "FLATTEN_LINKS_DELAY",
  "FLATTEN_LINKS_FILE", "GECOS", "GENERAL", "HIDDEN", "HIDDEN_NAME",
  "HIDE_CHANS", "HIDE_IDLE", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "INVITE_DELAY_CHANNEL", "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT",
  "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6",
  "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL",
  "LEAF_MASK", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_BANS_LARGE", "MAX_CHANNELS", "MAX_IDLE", "MAX_INVITES",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD",
  "NAME", "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO",
  "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE", "SQUIT", "SSL_CERTIFICATE_FILE",
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept",
  "conf", "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
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
  "class_number_per_ip_local", "class_number_per_ip_global",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_sendq", "class_recvq", "class_cidr_bitlen_ipv4",
  "class_cidr_bitlen_ipv6", "class_number_per_cidr", "class_min_idle",
  "class_max_idle", "class_flags", "$@9", "class_flags_items",
  "class_flags_item", "listen_entry", "$@10", "listen_flags", "$@11",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@12", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@13", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@14", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@15", "resv_items",
  "resv_item", "resv_mask", "resv_reason", "resv_exempt", "service_entry",
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
  "general_away_time", "general_max_watch",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_invisible_on_connect", "general_warn_no_connect_block",
  "general_stats_e_disabled", "general_stats_m_oper_only",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_u_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_dots_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels",
  "channel_invite_client_count", "channel_invite_client_time",
  "channel_invite_delay_channel", "channel_invite_expire_time",
  "channel_knock_client_count", "channel_knock_client_time",
  "channel_knock_delay_channel", "channel_max_channels",
  "channel_max_invites", "channel_max_bans", "channel_max_bans_large",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,    59,
     125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -893

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-893)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -893,   726,  -893,  -186,  -215,  -195,  -893,  -893,  -893,  -190,
    -893,  -185,  -893,  -893,  -893,  -171,  -893,  -893,  -893,  -163,
    -157,  -893,  -151,  -893,  -138,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,    24,   755,  -136,  -133,  -113,    11,  -111,   397,  -110,
     -98,   -88,    12,   -87,   -72,   -71,   818,   430,   -66,     2,
     -59,    29,   -57,   -52,   -48,   -27,   -19,     7,  -893,  -893,
    -893,  -893,  -893,    26,    47,    54,    77,    83,    97,   104,
     106,   110,   112,   114,   116,   118,   120,   213,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,   668,   561,    21,  -893,   121,    20,  -893,
    -893,    39,  -893,   122,   123,   124,   126,   128,   129,   130,
     132,   133,   134,   136,   138,   139,   140,   142,   145,   146,
     148,   150,   152,   153,   155,   156,   158,   159,  -893,  -893,
     160,   161,   164,   165,   167,   168,   170,   176,   177,   181,
     183,   185,   186,   192,   193,   195,   196,   198,   203,    41,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,   350,    90,   283,
     -34,   204,   205,    52,  -893,  -893,  -893,    10,   344,   332,
    -893,   206,   208,   209,   215,   216,   217,   220,   221,   222,
     269,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,   -11,   227,   229,   231,   232,   233,   234,   237,   240,
     241,   242,   243,   247,   248,   249,   250,   251,   253,    78,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,    87,    14,
     259,    18,  -893,  -893,  -893,   246,    23,  -893,   270,    55,
    -893,  -893,   109,  -893,   171,   218,   322,   272,  -893,   396,
     398,   295,   399,   398,   398,   398,   403,   398,   398,   407,
     408,   412,   416,   296,  -893,   297,   300,   303,   304,  -893,
     307,   308,   309,   311,   314,   315,   317,   318,   319,   327,
     328,   151,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,   298,   329,
     335,   338,   340,   341,   342,  -893,   343,   345,   346,   349,
     355,   357,   358,   301,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
     359,   361,    25,  -893,  -893,  -893,   405,   365,  -893,  -893,
     363,   364,    51,  -893,  -893,  -893,   387,   398,   421,   398,
     398,   388,   493,   398,   392,   495,   496,   507,   414,   415,
     398,   518,   520,   522,   523,   398,   524,   525,   526,   527,
     427,   406,   409,   436,   398,   398,   439,   440,   444,  -187,
    -182,   445,   447,   448,   449,   552,   398,   452,   398,   398,
     456,   559,   450,  -893,   453,   446,   457,  -893,   459,   461,
     463,   465,   466,   268,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,   467,   469,    38,  -893,  -893,  -893,
     455,   471,   472,  -893,   474,  -893,     3,  -893,  -893,  -893,
    -893,  -893,   545,   554,   478,  -893,   479,   480,   482,    33,
    -893,  -893,  -893,   481,   483,   484,  -893,   485,   489,   492,
     497,  -893,   499,   501,   225,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,   506,   505,   508,   509,
      17,  -893,  -893,  -893,  -893,   528,   529,   398,   558,   533,
     565,   538,   539,   540,   530,  -893,  -893,   620,   628,   547,
     642,   638,   658,   646,   648,   651,   652,   657,   661,   663,
     664,   667,   669,   671,   567,  -893,   568,   566,  -893,    80,
    -893,  -893,  -893,  -893,   589,   571,  -893,   570,   574,   572,
     575,   579,   580,    19,  -893,  -893,  -893,  -893,  -893,   690,
     585,  -893,   591,   590,  -893,   595,    62,  -893,  -893,  -893,
    -893,   592,   594,   604,  -893,   605,   536,   606,   607,   614,
     615,   616,   618,   619,   622,   624,   626,   627,   629,   630,
    -893,  -893,   741,   752,   398,   632,   757,   398,   760,   398,
     751,   767,   771,   772,   398,   775,   775,   659,  -893,  -893,
     763,   -74,   768,   680,   773,   774,   666,   776,   778,   794,
     780,   782,   784,   789,   684,  -893,   791,   795,   688,  -893,
     695,  -893,   802,   805,   702,  -893,   704,   706,   707,   709,
     712,   714,   715,   717,   718,   719,   721,   722,   723,   727,
     728,   729,   730,   735,   739,   742,   744,   746,   747,   749,
     753,   798,   713,   754,   759,   761,   762,   769,   770,   785,
     786,   787,   788,   790,   792,   793,   796,   797,   799,   800,
     801,   803,   804,   806,  -893,  -893,   819,   777,   764,   858,
     876,   863,   869,   874,   807,  -893,   878,   879,   808,  -893,
    -893,   880,   881,   781,   910,   809,  -893,   810,   811,  -893,
    -893,   897,   900,   812,  -893,  -893,   901,   817,   813,   908,
     911,   919,   833,   814,   921,   924,   820,  -893,  -893,   925,
     927,   928,   823,  -893,   824,   825,   826,   827,   828,   829,
     830,   831,   832,  -893,   834,   835,   836,   837,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847,   848,   849,
     850,  -893,  -893,   939,   851,   852,  -893,   853,  -893,    16,
    -893,   957,   961,   962,   963,   859,  -893,   860,  -893,  -893,
     964,   861,   967,   862,  -893,  -893,  -893,  -893,  -893,   398,
     398,   398,   398,   398,   398,   398,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,   865,   866,   867,   -37,   868,   870,   871,   872,   873,
     875,   877,   882,   883,    59,   884,   885,  -893,   886,   887,
     888,   889,   890,   891,   892,     6,   893,   894,   895,   896,
     898,   899,   902,  -893,   903,   904,  -893,  -893,   905,   906,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -200,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -198,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,   907,   909,   504,   912,   913,   914,   915,
     916,  -893,   917,   918,  -893,   920,   922,   -10,   923,   926,
    -893,  -893,  -893,  -893,   929,   931,  -893,   932,   933,   517,
     934,   935,   936,   937,   758,   938,   940,  -893,   941,   942,
     943,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,   944,   437,
    -893,  -893,   945,   946,   947,  -893,    48,  -893,  -893,  -893,
    -893,   948,   951,   952,   953,  -893,  -893,   954,   623,   955,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -172,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,   775,   775,   775,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -147,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,   798,  -893,   713,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -137,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,   -21,  -893,   984,   910,   956,  -893,  -893,
    -893,  -893,  -893,  -893,   864,  -893,   958,   959,  -893,  -893,
     960,   965,  -893,  -893,   966,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,   -13,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,    -8,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,    -5,  -893,  -893,   980,   -14,   969,   968,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,    99,  -893,  -893,  -893,
     -37,  -893,  -893,  -893,  -893,     6,  -893,  -893,  -893,   504,
    -893,   -10,  -893,  -893,  -893,   976,   977,   978,   979,   997,
    1000,  -893,   517,  -893,   758,  -893,   437,   973,   974,   975,
     549,  -893,  -893,   623,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,   102,  -893,
    -893,  -893,   549,  -893
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   395,   443,     0,
     458,     0,   298,   434,   274,     0,   100,   152,   332,     0,
       0,   373,     0,   109,     0,   349,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   615,   629,
     618,   619,   620,   621,   622,   623,   624,   625,   626,   616,
     617,   627,   628,     0,     0,     0,   456,     0,     0,   454,
     455,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   559,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,   470,   471,   514,   477,   515,   509,   510,   511,   512,
     508,   481,   472,   473,   474,   475,   476,   478,   479,   480,
     482,   483,   513,   487,   488,   489,   490,   486,   485,   491,
     498,   499,   492,   493,   494,   484,   496,   506,   507,   504,
     505,   497,   495,   502,   503,   500,   501,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647,   648,   649,   650,   651,   652,   653,   655,   654,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      54,    69,    66,    64,    70,    71,    65,    55,    68,    58,
      59,    60,    56,    67,    61,    62,    63,    57,     0,     0,
       0,     0,   124,   125,   126,     0,     0,   347,     0,     0,
     345,   346,     0,    96,     0,     0,     0,     0,    91,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   614,     0,     0,     0,     0,   268,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,   238,   241,   243,   244,   245,   246,   247,
     248,   249,   239,   240,   242,   250,   251,   252,     0,     0,
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
     103,   104,   105,     0,     0,     0,   201,     0,     0,     0,
       0,   175,     0,     0,     0,   155,   156,   157,   158,   159,
     162,   163,   164,   161,   160,   165,     0,     0,     0,     0,
       0,   335,   336,   337,   338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   646,    72,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,     0,     0,   381,     0,
     376,   377,   378,   127,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   115,   114,   116,     0,
       0,   344,     0,     0,   359,     0,     0,   352,   353,   354,
     355,     0,     0,     0,    90,     0,    28,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   253,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   397,     0,     0,     0,   445,
       0,   452,     0,     0,     0,   460,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   310,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   300,     0,     0,     0,   436,
     289,     0,     0,     0,     0,     0,   283,     0,     0,    44,
     106,     0,     0,     0,   102,   166,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   154,   339,     0,
       0,     0,     0,   334,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   645,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,   379,     0,     0,     0,   375,     0,   122,     0,
     117,     0,     0,     0,     0,     0,   111,     0,   343,   356,
       0,     0,     0,     0,   351,    99,    98,    97,   643,    28,
      28,    28,    28,    28,    28,    28,    30,    29,   644,   631,
     632,   633,   634,   635,   636,   637,   638,   641,   642,   639,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   396,     0,     0,   444,   457,     0,     0,
     459,   529,   533,   517,   518,   548,   521,   611,   612,   556,
     522,   523,   553,   528,   536,   527,   524,   525,   532,   531,
     530,   554,   519,   609,   610,   552,   595,   589,   605,   590,
     591,   592,   600,   608,   593,   602,   606,   596,   607,   597,
     601,   594,   604,   599,   598,   603,     0,   588,   568,   569,
     570,   563,   581,   564,   565,   566,   576,   584,   567,   578,
     582,   572,   583,   573,   577,   571,   580,   575,   574,   579,
       0,   562,   549,   547,   550,   555,   551,   538,   545,   546,
     543,   544,   539,   540,   541,   542,   557,   558,   526,   535,
     534,   537,   520,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,   435,     0,     0,     0,   294,   290,
     293,   275,    50,    51,     0,     0,   101,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   153,     0,     0,
       0,   333,   661,   658,   659,   660,   665,   664,   666,   662,
     663,    86,    81,    89,    80,    87,    88,    79,    83,    82,
      74,    73,    78,    75,    77,    76,    84,    85,     0,     0,
     374,   128,     0,     0,     0,   140,     0,   132,   133,   135,
     134,     0,     0,     0,     0,   110,   348,     0,     0,     0,
     350,    31,    32,    33,    34,    35,    36,    37,   263,   264,
     258,   273,   272,     0,   271,   259,   267,   260,   266,   254,
     265,   257,   256,   255,    38,    38,    38,    40,    39,   261,
     262,   418,   421,   422,   432,   429,   415,   430,   427,   428,
       0,   426,   431,   414,   420,   417,   419,   433,   416,   450,
     451,   465,   466,   586,     0,   560,     0,   313,   314,   324,
     320,   321,   323,   328,   325,   326,   319,   327,   322,     0,
     318,   312,   331,   330,   329,   311,   442,   441,   297,   296,
     281,   282,   280,     0,   279,     0,     0,     0,   107,   108,
     174,   171,   221,   233,   208,   217,     0,   206,   211,   227,
       0,   220,   225,   231,   210,   213,   222,   224,   228,   218,
     226,   214,   232,   216,   223,   212,   215,     0,   204,   167,
     169,   172,   173,   184,   185,   186,   179,   197,   180,   181,
     182,   192,   200,   183,   194,   198,   188,   199,   189,   193,
     187,   196,   191,   190,   195,     0,   178,   168,   170,   342,
     340,   341,   380,   385,   391,   394,   387,   393,   388,   392,
     390,   386,   389,     0,   384,   136,     0,     0,     0,     0,
     131,   119,   118,   120,   121,   357,   363,   369,   372,   365,
     371,   366,   370,   368,   364,   367,     0,   362,   358,   269,
       0,    41,    42,    43,   424,     0,   587,   561,   316,     0,
     277,     0,   295,   292,   291,     0,     0,     0,     0,     0,
       0,   202,     0,   176,     0,   382,     0,     0,     0,     0,
       0,   130,   360,     0,   270,   425,   317,   278,   207,   230,
     205,   229,   219,   209,   203,   177,   383,   137,   139,   138,
     150,   149,   145,   147,   151,   148,   144,   146,     0,   143,
     361,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -893,  -893,  -893,   187,  -308,  -892,  -635,  -893,  -893,   930,
    -893,  -893,  -893,  -893,   949,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  1032,  -893,  -893,  -893,  -893,  -893,
    -893,   631,  -893,  -893,  -893,  -893,  -893,   556,  -893,  -893,
    -893,  -893,  -893,  -893,   857,  -893,  -893,  -893,  -893,    91,
    -893,  -893,  -893,  -893,  -893,  -162,  -893,  -893,  -893,   640,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -122,  -893,  -893,  -893,  -117,  -893,  -893,  -893,   815,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,   -93,  -893,  -893,
    -893,  -893,  -893,   -86,  -893,   682,  -893,  -893,  -893,    30,
    -893,  -893,  -893,  -893,  -893,   724,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,   -73,  -893,  -893,  -893,  -893,  -893,  -893,
     660,  -893,  -893,  -893,  -893,  -893,   950,  -893,  -893,  -893,
    -893,   593,  -893,  -893,  -893,  -893,  -893,   -95,  -893,  -893,
    -893,   636,  -893,  -893,  -893,  -893,   -85,  -893,  -893,  -893,
     822,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,   -49,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,   720,  -893,  -893,  -893,  -893,  -893,   816,  -893,  -893,
    -893,  -893,  1080,  -893,  -893,  -893,  -893,   821,  -893,  -893,
    -893,  -893,  1038,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,    93,  -893,  -893,  -893,
      96,  -893,  -893,  -893,  -893,  -893,  -893,  1114,  -893,  -893,
    -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893,   972,  -893,  -893,  -893,  -893,  -893,
    -893,  -893,  -893,  -893
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   826,   827,  1087,  1088,    27,   223,   224,
     225,   226,    28,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,    29,    77,    78,    79,    80,    81,    30,    63,
     499,   500,   501,   502,    31,    70,   583,   584,   585,   586,
     587,   588,    32,   291,   292,   293,   294,   295,  1046,  1047,
    1048,  1049,  1050,  1228,  1308,  1309,    33,    64,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   753,
    1205,  1206,   525,   748,  1177,  1178,    34,    53,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   625,  1073,  1074,    35,    61,
     485,   733,  1143,  1144,   486,   487,   488,  1147,   989,   990,
     489,   490,    36,    59,   463,   464,   465,   466,   467,   468,
     469,   718,  1129,  1130,   470,   471,   472,    37,    65,   530,
     531,   532,   533,   534,    38,   299,   300,   301,    39,    72,
     596,   597,   598,   599,   600,   811,  1246,  1247,    40,    68,
     569,   570,   571,   572,   794,  1223,  1224,    41,    54,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     646,  1100,  1101,   384,   385,   386,   387,   388,    42,    60,
     476,   477,   478,   479,    43,    55,   392,   393,   394,   395,
      44,   118,   119,   120,    45,    57,   402,   403,   404,   405,
      46,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   432,   950,   951,   212,   431,   926,
     927,   213,   214,   215,   216,    47,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,    48,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     855,   856,   607,   289,   480,   610,   611,   612,    73,   614,
     615,   496,   116,   220,  1098,  1071,    51,  1042,   526,   289,
     578,   116,   389,   699,   578,    73,   389,   700,   701,  1113,
     297,  1115,   702,  1114,   496,  1116,    52,    74,  1140,   473,
     399,    56,   122,    49,    50,    75,    58,   123,   124,  1042,
     125,   126,   399,   220,    74,   127,   297,  1249,   527,   481,
      62,  1250,    75,   592,   128,   129,   130,   482,    66,   483,
    1084,  1085,  1086,   131,    67,   117,   132,   133,   134,   251,
      69,   566,  1254,   135,   117,   390,  1255,  1072,   566,   390,
     497,   473,  1258,    71,   854,   113,  1259,   528,   114,   667,
     136,   669,   670,   859,   860,   673,   252,    76,   253,   221,
     592,   137,   680,   497,   138,   139,  1043,   685,   115,   579,
     121,   217,   140,   579,    76,   484,   694,   695,   141,   298,
     142,   222,   143,   218,   144,   254,   145,   146,   708,   400,
     710,   711,   529,   219,   227,   255,   391,   147,  1043,   221,
     391,   400,   325,   148,   149,   298,   150,   151,   152,   228,
     229,   153,   593,   474,   401,   288,   256,   854,   326,   327,
     257,   222,   296,   328,   302,  -129,   401,   303,   258,  1141,
     567,   259,   260,   498,   304,   580,   154,   567,  1142,   580,
    1278,  -129,  1251,  1252,  1253,   491,   155,   156,   157,   158,
     159,   160,   161,   581,  1099,   305,   498,   581,  1260,   593,
    1044,   261,  1261,   306,    82,   474,  1271,   329,   546,   582,
    1272,  1273,   290,   582,  1275,  1274,   503,   262,  1276,   766,
     263,   264,   265,   735,  1045,   330,   331,   307,   290,    83,
      84,   332,  1044,   573,   504,   333,    85,   762,   575,   805,
     397,   334,   162,   163,   164,   658,   165,   166,   309,   475,
     335,   336,   337,   743,   505,   167,  1045,   168,   728,   454,
     230,   452,   338,    86,    87,    88,    89,   266,  1229,   310,
     594,   664,   494,   595,   480,   590,   311,   455,    90,    91,
      92,   506,   813,   339,   601,    93,    94,    95,   568,    96,
     267,   268,   358,   231,   359,   568,   360,   456,   564,   312,
     795,   475,   232,   233,   234,   313,   843,   235,   236,   846,
     361,   848,   237,   238,   239,   507,   853,   594,  1282,   314,
     595,  1311,  1283,   526,   457,  1312,   315,   340,   316,   481,
     362,   602,   317,   508,   318,   503,   319,   482,   320,   483,
     321,   454,   322,   396,   406,   407,   408,   363,   409,   364,
     410,   411,   412,   504,   413,   414,   415,   365,   416,   455,
     417,   418,   419,   527,   420,   509,   510,   421,   422,   366,
     423,   637,   424,   505,   425,   426,   458,   427,   428,   456,
     429,   430,   433,   434,   459,   460,   435,   436,   122,   437,
     438,   367,   439,   123,   124,   484,   125,   126,   440,   441,
     506,   127,   528,   442,   461,   443,   457,   444,   445,   577,
     128,   129,   130,   368,   446,   447,   511,   448,   449,   131,
     450,   251,   132,   133,   134,   451,   492,   493,   535,   135,
     536,   537,   369,   323,   507,   603,   512,   538,   539,   540,
     513,   370,   541,   542,   543,   756,   136,   529,   252,   547,
     253,   548,   508,   549,   550,   551,   552,   137,   458,   553,
     138,   139,   554,   555,   556,   557,   459,   460,   140,   558,
     559,   560,   561,   562,   141,   563,   142,   254,   143,   462,
     144,   574,   145,   146,   509,   510,   461,   255,   724,   544,
     371,   604,   589,   147,   605,   608,   606,   609,  1213,   148,
     149,   613,   150,   151,   152,   616,   617,   153,   256,  1119,
     618,  1152,   257,   372,   619,   620,   621,   639,   660,   668,
     258,   654,   622,   259,   260,   623,   624,  1153,  1154,   626,
     627,   628,   154,   629,  1120,   511,   630,   631,  1155,   632,
     633,   634,   155,   156,   157,   158,   159,   160,   161,   635,
     636,   640,   358,   261,   359,   512,   360,   641,  1214,   513,
     642,   462,   643,   644,   645,   647,  1121,   648,   649,   262,
     361,   650,   263,   264,   265,  1156,  1157,   651,  1158,   652,
     653,   656,  1279,   657,   661,   662,   663,   666,   671,  1215,
     362,   672,   674,   675,   676,  1122,  1123,  1216,   162,   163,
     164,  1124,   165,   166,  1159,   677,  1217,   363,  1300,   364,
    1301,   167,  1160,   168,   678,   679,   681,   365,   682,   266,
     683,   684,   686,   687,   688,   689,  1125,   690,   691,   366,
    1218,   692,  1219,  1220,   606,  1161,   693,  1162,  1163,   696,
     697,  1126,   267,   268,   698,   703,  1221,   704,   705,   706,
     707,   367,   709,  1302,  1222,  1164,   712,   713,   737,   325,
     819,   820,   821,   822,   823,   824,   825,   738,   716,   714,
    1303,   767,   715,   368,   730,   326,   327,  1165,   769,   717,
     328,   719,  1166,   720,  1236,   721,  1167,   722,   723,   726,
    1168,   727,   369,   731,   732,  1169,   734,   739,   740,  1170,
     745,   370,   741,  1127,   742,   746,   747,   749,  1304,  1305,
    1171,   750,  1172,  1173,   751,  1174,     2,     3,   774,   752,
       4,   754,  1128,   755,   329,   758,  1175,   759,   764,   765,
     760,   761,     5,   768,  1176,     6,   778,     7,   770,   771,
     772,   775,   330,   331,  1237,     8,    82,   776,   332,   773,
     371,   928,   333,   929,   930,   777,   779,     9,   334,   780,
    1306,   781,    10,    11,   782,   783,  1307,   335,   336,   337,
     784,    83,    84,   372,   785,  1238,   786,   787,    85,   338,
     788,    12,   789,  1239,   790,    13,   791,   792,   793,   797,
     798,   799,  1240,   800,   801,    14,  1183,   802,  1184,  1185,
     339,   803,   804,   807,   808,    86,    87,    88,    89,   230,
     809,   815,   810,   816,    15,    16,  1241,   812,  1242,  1243,
      90,    91,    92,   817,   818,   828,   829,    93,    94,    95,
      17,    96,  1244,   830,   831,   832,   906,   833,   834,   841,
    1245,   835,   231,   836,   340,   837,   838,    18,   839,   840,
     842,   232,   233,   234,   844,   845,   235,   236,   847,    19,
      20,   237,   238,   239,   849,   850,   931,   932,   933,   851,
     852,   934,   935,   854,   936,   937,   858,   938,   857,   939,
     862,   861,   940,    21,   941,   942,   863,   864,   865,   866,
     943,   867,   868,   869,   944,   870,    22,   871,   945,   946,
     947,    23,   872,   873,   874,   948,    24,   876,   875,    25,
     949,  1186,  1187,  1188,   877,   878,  1189,  1190,   879,  1191,
    1192,   880,  1193,   881,  1194,   882,   883,  1195,   884,  1196,
    1197,   885,   973,   886,   887,  1198,   888,   889,   890,  1199,
     891,   892,   893,  1200,  1201,  1202,   894,   895,   896,   897,
    1203,   907,   908,   909,   898,  1204,   910,   911,   899,   912,
     913,   900,   914,   901,   915,   902,   903,   916,   904,   917,
     918,   976,   905,   952,   977,   919,   978,   974,   953,   920,
     954,   955,   979,   921,   922,   923,   975,   980,   956,   957,
     924,   982,   983,   985,   986,   925,  1061,  1062,  1063,  1064,
    1065,  1066,  1067,   987,   958,   959,   960,   961,   988,   962,
     994,   963,   964,   995,   997,   965,   966,   998,   967,   968,
     969,  1000,   970,   971,  1001,   972,   981,   984,   991,   992,
     993,   996,  1002,  1003,  1005,   999,  1004,  1006,  1008,  1007,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,
    1019,  1020,  1038,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1051,  1040,  1041,  1039,  1052,  1053,  1054,  1057,  1055,  1056,
    1059,  1060,  1262,  1058,  1068,  1069,  1070,  1075,  1265,  1076,
    1077,  1078,  1079,  1277,  1080,  1288,  1081,  1290,  1289,   308,
    1291,  1082,  1083,  1089,  1090,  1091,  1092,  1093,  1094,  1095,
    1096,  1097,  1102,  1103,  1104,  1105,  1292,  1106,  1107,  1293,
     744,  1108,  1109,  1110,  1111,  1112,  1117,  1230,  1118,   806,
    1145,  1131,  1132,  1133,  1134,  1135,  1136,  1137,   576,  1138,
    1313,  1139,  1295,   495,   757,  1294,   638,  1284,  1148,  1146,
    1149,  1150,  1151,  1179,  1180,  1181,  1182,  1207,   736,  1208,
    1209,  1210,  1211,  1212,  1225,  1287,  1263,  1231,  1226,  1227,
    1232,  1233,  1234,  1235,  1248,  1264,  1286,   725,  1310,   814,
     763,  1296,  1266,  1267,  1268,   655,   729,  1281,   398,  1269,
    1270,  1280,  1297,  1298,  1299,   796,  1285,   453,   659,  1257,
    1256,   324,   545,     0,     0,     0,     0,     0,   565,     0,
       0,     0,     0,   665,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   591
};

static const yytype_int16 yycheck[] =
{
     635,   636,   310,     1,     1,   313,   314,   315,     1,   317,
     318,     1,     1,     1,     8,    52,   231,     1,     1,     1,
       1,     1,     1,   210,     1,     1,     1,   214,   210,   229,
       1,   229,   214,   233,     1,   233,   231,    30,    48,     1,
       1,   231,     1,   229,   230,    38,   231,     6,     7,     1,
       9,    10,     1,     1,    30,    14,     1,   229,    41,    56,
     231,   233,    38,     1,    23,    24,    25,    64,   231,    66,
      11,    12,    13,    32,   231,    64,    35,    36,    37,     1,
     231,     1,   229,    42,    64,    64,   233,   124,     1,    64,
      80,     1,   229,   231,   108,   231,   233,    80,   231,   407,
      59,   409,   410,   177,   178,   413,    28,   100,    30,    97,
       1,    70,   420,    80,    73,    74,   100,   425,   231,   100,
     231,   231,    81,   100,   100,   122,   434,   435,    87,   100,
      89,   119,    91,   231,    93,    57,    95,    96,   446,   100,
     448,   449,   125,   231,   231,    67,   125,   106,   100,    97,
     125,   100,     1,   112,   113,   100,   115,   116,   117,   231,
     231,   120,   100,   125,   125,   231,    88,   108,    17,    18,
      92,   119,   231,    22,   231,   173,   125,   229,   100,   189,
     100,   103,   104,   173,   232,   166,   145,   100,   198,   166,
     204,   173,  1084,  1085,  1086,   229,   155,   156,   157,   158,
     159,   160,   161,   184,   198,   232,   173,   184,   229,   100,
     194,   133,   233,   232,     1,   125,   229,    66,   229,   200,
     233,   229,   220,   200,   229,   233,     1,   149,   233,   537,
     152,   153,   154,   230,   218,    84,    85,   230,   220,    26,
      27,    90,   194,   229,    19,    94,    33,   230,   230,   230,
     230,   100,   211,   212,   213,   230,   215,   216,   232,   221,
     109,   110,   111,   230,    39,   224,   218,   226,   230,     1,
       1,   230,   121,    60,    61,    62,    63,   199,   230,   232,
     218,   230,   230,   221,     1,   230,   232,    19,    75,    76,
      77,    66,   230,   142,   123,    82,    83,    84,   218,    86,
     222,   223,     1,    34,     3,   218,     5,    39,   230,   232,
     230,   221,    43,    44,    45,   232,   624,    48,    49,   627,
      19,   629,    53,    54,    55,   100,   634,   218,   229,   232,
     221,   229,   233,     1,    66,   233,   232,   186,   232,    56,
      39,   123,   232,   118,   232,     1,   232,    64,   232,    66,
     232,     1,   232,   232,   232,   232,   232,    56,   232,    58,
     232,   232,   232,    19,   232,   232,   232,    66,   232,    19,
     232,   232,   232,    41,   232,   150,   151,   232,   232,    78,
     232,   230,   232,    39,   232,   232,   118,   232,   232,    39,
     232,   232,   232,   232,   126,   127,   232,   232,     1,   232,
     232,   100,   232,     6,     7,   122,     9,    10,   232,   232,
      66,    14,    80,   232,   146,   232,    66,   232,   232,   173,
      23,    24,    25,   122,   232,   232,   201,   232,   232,    32,
     232,     1,    35,    36,    37,   232,   232,   232,   232,    42,
     232,   232,   141,   230,   100,   123,   221,   232,   232,   232,
     225,   150,   232,   232,   232,   230,    59,   125,    28,   232,
      30,   232,   118,   232,   232,   232,   232,    70,   118,   232,
      73,    74,   232,   232,   232,   232,   126,   127,    81,   232,
     232,   232,   232,   232,    87,   232,    89,    57,    91,   221,
      93,   232,    95,    96,   150,   151,   146,    67,   230,   230,
     199,   229,   232,   106,   108,   210,   108,   108,    71,   112,
     113,   108,   115,   116,   117,   108,   108,   120,    88,    15,
     108,     4,    92,   222,   108,   229,   229,   229,   123,   108,
     100,   230,   232,   103,   104,   232,   232,    20,    21,   232,
     232,   232,   145,   232,    40,   201,   232,   232,    31,   232,
     232,   232,   155,   156,   157,   158,   159,   160,   161,   232,
     232,   232,     1,   133,     3,   221,     5,   232,   131,   225,
     232,   221,   232,   232,   232,   232,    72,   232,   232,   149,
      19,   232,   152,   153,   154,    68,    69,   232,    71,   232,
     232,   232,  1227,   232,   229,   232,   232,   210,   210,   162,
      39,   108,   210,   108,   108,   101,   102,   170,   211,   212,
     213,   107,   215,   216,    97,   108,   179,    56,    69,    58,
      71,   224,   105,   226,   210,   210,   108,    66,   108,   199,
     108,   108,   108,   108,   108,   108,   132,   210,   232,    78,
     203,   232,   205,   206,   108,   128,   210,   130,   131,   210,
     210,   147,   222,   223,   210,   210,   219,   210,   210,   210,
     108,   100,   210,   114,   227,   148,   210,   108,   123,     1,
     134,   135,   136,   137,   138,   139,   140,   123,   232,   229,
     131,   123,   229,   122,   229,    17,    18,   170,   123,   232,
      22,   232,   175,   232,    71,   232,   179,   232,   232,   232,
     183,   232,   141,   232,   232,   188,   232,   229,   229,   192,
     229,   150,   232,   209,   232,   232,   232,   232,   169,   170,
     203,   232,   205,   206,   232,   208,     0,     1,   108,   232,
       4,   232,   228,   232,    66,   229,   219,   232,   210,   210,
     232,   232,    16,   210,   227,    19,   108,    21,   210,   210,
     210,   123,    84,    85,   131,    29,     1,   210,    90,   229,
     199,    48,    94,    50,    51,   123,   108,    41,   100,   123,
     221,   123,    46,    47,   123,   123,   227,   109,   110,   111,
     123,    26,    27,   222,   123,   162,   123,   123,    33,   121,
     123,    65,   123,   170,   123,    69,   229,   229,   232,   210,
     229,   231,   179,   229,   232,    79,    48,   232,    50,    51,
     142,   232,   232,   123,   229,    60,    61,    62,    63,     1,
     229,   229,   232,   229,    98,    99,   203,   232,   205,   206,
      75,    76,    77,   229,   229,   229,   229,    82,    83,    84,
     114,    86,   219,   229,   229,   229,    48,   229,   229,   108,
     227,   229,    34,   229,   186,   229,   229,   131,   229,   229,
     108,    43,    44,    45,   232,   108,    48,    49,   108,   143,
     144,    53,    54,    55,   123,   108,   163,   164,   165,   108,
     108,   168,   169,   108,   171,   172,   123,   174,   229,   176,
     210,   123,   179,   167,   181,   182,   123,   123,   232,   123,
     187,   123,   108,   123,   191,   123,   180,   123,   195,   196,
     197,   185,   123,   229,   123,   202,   190,   229,   123,   193,
     207,   163,   164,   165,   229,   123,   168,   169,   123,   171,
     172,   229,   174,   229,   176,   229,   229,   179,   229,   181,
     182,   229,   123,   229,   229,   187,   229,   229,   229,   191,
     229,   229,   229,   195,   196,   197,   229,   229,   229,   229,
     202,   163,   164,   165,   229,   207,   168,   169,   229,   171,
     172,   229,   174,   229,   176,   229,   229,   179,   229,   181,
     182,   123,   229,   229,   108,   187,   123,   210,   229,   191,
     229,   229,   123,   195,   196,   197,   232,   123,   229,   229,
     202,   123,   123,   123,   123,   207,   819,   820,   821,   822,
     823,   824,   825,   232,   229,   229,   229,   229,   108,   229,
     123,   229,   229,   123,   123,   229,   229,   210,   229,   229,
     229,   123,   229,   229,   123,   229,   229,   229,   229,   229,
     229,   229,   123,   210,   123,   232,   232,   123,   123,   229,
     123,   123,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   123,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     123,   229,   229,   232,   123,   123,   123,   123,   229,   229,
     123,   229,   108,   232,   229,   229,   229,   229,   234,   229,
     229,   229,   229,   123,   229,   129,   229,   129,   131,    77,
     131,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   129,   229,   229,   129,
     499,   229,   229,   229,   229,   229,   229,  1046,   229,   583,
     217,   229,   229,   229,   229,   229,   229,   229,   291,   229,
    1312,   229,  1274,   223,   514,  1272,   341,  1250,   229,   233,
     229,   229,   229,   229,   229,   229,   229,   229,   486,   229,
     229,   229,   229,   229,   229,  1261,  1146,   229,   232,   232,
     229,   229,   229,   229,   229,   229,  1259,   463,  1283,   596,
     530,  1276,   234,   234,   234,   373,   476,   229,   118,   234,
     234,   232,   229,   229,   229,   569,  1255,   169,   392,  1116,
    1114,    97,   240,    -1,    -1,    -1,    -1,    -1,   269,    -1,
      -1,    -1,    -1,   402,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   236,     0,     1,     4,    16,    19,    21,    29,    41,
      46,    47,    65,    69,    79,    98,    99,   114,   131,   143,
     144,   167,   180,   185,   190,   193,   237,   242,   247,   267,
     273,   279,   287,   301,   321,   343,   357,   372,   379,   383,
     393,   402,   423,   429,   435,   439,   445,   500,   517,   229,
     230,   231,   231,   322,   403,   430,   231,   440,   231,   358,
     424,   344,   231,   274,   302,   373,   231,   231,   394,   231,
     280,   231,   384,     1,    30,    38,   100,   268,   269,   270,
     271,   272,     1,    26,    27,    33,    60,    61,    62,    63,
      75,    76,    77,    82,    83,    84,    86,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   231,   231,   231,     1,    64,   436,   437,
     438,   231,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    42,    59,    70,    73,    74,
      81,    87,    89,    91,    93,    95,    96,   106,   112,   113,
     115,   116,   117,   120,   145,   155,   156,   157,   158,   159,
     160,   161,   211,   212,   213,   215,   216,   224,   226,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   492,   496,   497,   498,   499,   231,   231,   231,
       1,    97,   119,   243,   244,   245,   246,   231,   231,   231,
       1,    34,    43,    44,    45,    48,    49,    53,    54,    55,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,     1,    28,    30,    57,    67,    88,    92,   100,   103,
     104,   133,   149,   152,   153,   154,   199,   222,   223,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   231,     1,
     220,   288,   289,   290,   291,   292,   231,     1,   100,   380,
     381,   382,   231,   229,   232,   232,   232,   230,   269,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   230,   502,     1,    17,    18,    22,    66,
      84,    85,    90,    94,   100,   109,   110,   111,   121,   142,
     186,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,     1,     3,
       5,    19,    39,    56,    58,    66,    78,   100,   122,   141,
     150,   199,   222,   404,   405,   406,   407,   408,   409,   410,
     411,   412,   413,   414,   418,   419,   420,   421,   422,     1,
      64,   125,   431,   432,   433,   434,   232,   230,   437,     1,
     100,   125,   441,   442,   443,   444,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   493,   489,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   230,   447,     1,    19,    39,    66,   118,   126,
     127,   146,   221,   359,   360,   361,   362,   363,   364,   365,
     369,   370,   371,     1,   125,   221,   425,   426,   427,   428,
       1,    56,    64,    66,   122,   345,   349,   350,   351,   355,
     356,   229,   232,   232,   230,   244,     1,    80,   173,   275,
     276,   277,   278,     1,    19,    39,    66,   100,   118,   150,
     151,   201,   221,   225,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   317,     1,    41,    80,   125,
     374,   375,   376,   377,   378,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   230,   519,   229,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   230,   249,     1,   100,   218,   395,
     396,   397,   398,   229,   232,   230,   289,   173,     1,   100,
     166,   184,   200,   281,   282,   283,   284,   285,   286,   232,
     230,   381,     1,   100,   218,   221,   385,   386,   387,   388,
     389,   123,   123,   123,   229,   108,   108,   239,   210,   108,
     239,   239,   239,   108,   239,   239,   108,   108,   108,   108,
     229,   229,   232,   232,   232,   340,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   230,   324,   229,
     232,   232,   232,   232,   232,   232,   415,   232,   232,   232,
     232,   232,   232,   232,   230,   405,   232,   232,   230,   432,
     123,   229,   232,   232,   230,   442,   210,   239,   108,   239,
     239,   210,   108,   239,   210,   108,   108,   108,   210,   210,
     239,   108,   108,   108,   108,   239,   108,   108,   108,   108,
     210,   232,   232,   210,   239,   239,   210,   210,   210,   210,
     214,   210,   214,   210,   210,   210,   210,   108,   239,   210,
     239,   239,   210,   108,   229,   229,   232,   232,   366,   232,
     232,   232,   232,   232,   230,   360,   232,   232,   230,   426,
     229,   232,   232,   346,   232,   230,   350,   123,   123,   229,
     229,   232,   232,   230,   276,   229,   232,   232,   318,   232,
     232,   232,   232,   314,   232,   232,   230,   304,   229,   232,
     232,   232,   230,   375,   210,   210,   239,   123,   210,   123,
     210,   210,   210,   229,   108,   123,   210,   123,   108,   108,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   229,   229,   232,   399,   230,   396,   210,   229,   231,
     229,   232,   232,   232,   232,   230,   282,   123,   229,   229,
     232,   390,   232,   230,   386,   229,   229,   229,   229,   134,
     135,   136,   137,   138,   139,   140,   238,   239,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   108,   108,   239,   232,   108,   239,   108,   239,   123,
     108,   108,   108,   239,   108,   241,   241,   229,   123,   177,
     178,   123,   210,   123,   123,   232,   123,   123,   108,   123,
     123,   123,   123,   229,   123,   123,   229,   229,   123,   123,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    48,   163,   164,   165,
     168,   169,   171,   172,   174,   176,   179,   181,   182,   187,
     191,   195,   196,   197,   202,   207,   494,   495,    48,    50,
      51,   163,   164,   165,   168,   169,   171,   172,   174,   176,
     179,   181,   182,   187,   191,   195,   196,   197,   202,   207,
     490,   491,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   123,   210,   232,   123,   108,   123,   123,
     123,   229,   123,   123,   229,   123,   123,   232,   108,   353,
     354,   229,   229,   229,   123,   123,   229,   123,   210,   232,
     123,   123,   123,   210,   232,   123,   123,   229,   123,   123,
     123,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   123,   232,
     229,   229,     1,   100,   194,   218,   293,   294,   295,   296,
     297,   123,   123,   123,   123,   229,   229,   123,   232,   123,
     229,   238,   238,   238,   238,   238,   238,   238,   229,   229,
     229,    52,   124,   341,   342,   229,   229,   229,   229,   229,
     229,   229,   229,   229,    11,    12,    13,   240,   241,   229,
     229,   229,   229,   229,   229,   229,   229,   229,     8,   198,
     416,   417,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   233,   229,   233,   229,   229,    15,
      40,    72,   101,   102,   107,   132,   147,   209,   228,   367,
     368,   229,   229,   229,   229,   229,   229,   229,   229,   229,
      48,   189,   198,   347,   348,   217,   233,   352,   229,   229,
     229,   229,     4,    20,    21,    31,    68,    69,    71,    97,
     105,   128,   130,   131,   148,   170,   175,   179,   183,   188,
     192,   203,   205,   206,   208,   219,   227,   319,   320,   229,
     229,   229,   229,    48,    50,    51,   163,   164,   165,   168,
     169,   171,   172,   174,   176,   179,   181,   182,   187,   191,
     195,   196,   197,   202,   207,   315,   316,   229,   229,   229,
     229,   229,   229,    71,   131,   162,   170,   179,   203,   205,
     206,   219,   227,   400,   401,   229,   232,   232,   298,   230,
     294,   229,   229,   229,   229,   229,    71,   131,   162,   170,
     179,   203,   205,   206,   219,   227,   391,   392,   229,   229,
     233,   240,   240,   240,   229,   233,   495,   491,   229,   233,
     229,   233,   108,   354,   229,   234,   234,   234,   234,   234,
     234,   229,   233,   229,   233,   229,   233,   123,   204,   241,
     232,   229,   229,   233,   342,   417,   368,   348,   129,   131,
     129,   131,   129,   129,   320,   316,   401,   229,   229,   229,
      69,    71,   114,   131,   169,   170,   221,   227,   299,   300,
     392,   229,   233,   300
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
     304,   304,   304,   304,   304,   304,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   314,   313,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   318,   317,   319,   319,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   322,   321,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,   335,   336,   337,   338,   340,   339,
     341,   341,   342,   342,   344,   343,   346,   345,   347,   347,
     348,   348,   348,   349,   349,   350,   350,   350,   350,   350,
     352,   351,   353,   353,   354,   354,   355,   356,   358,   357,
     359,   359,   360,   360,   360,   360,   360,   360,   360,   360,
     360,   361,   362,   363,   364,   366,   365,   367,   367,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   368,   369,
     370,   371,   373,   372,   374,   374,   375,   375,   375,   375,
     376,   377,   378,   379,   380,   380,   381,   381,   382,   384,
     383,   385,   385,   386,   386,   386,   386,   387,   388,   390,
     389,   391,   391,   392,   392,   392,   392,   392,   392,   392,
     392,   392,   392,   394,   393,   395,   395,   396,   396,   396,
     397,   399,   398,   400,   400,   401,   401,   401,   401,   401,
     401,   401,   401,   401,   401,   403,   402,   404,   404,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   413,   415,   414,   416,   416,   417,   417,   418,
     419,   420,   421,   422,   424,   423,   425,   425,   426,   426,
     426,   427,   428,   430,   429,   431,   431,   432,   432,   432,
     433,   434,   435,   436,   436,   437,   437,   438,   440,   439,
     441,   441,   442,   442,   442,   443,   444,   445,   446,   446,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   447,   447,   447,
     447,   447,   447,   447,   447,   447,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   474,   475,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   489,
     488,   490,   490,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   493,   492,   494,   494,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   496,
     497,   498,   499,   500,   501,   501,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   518,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
    default: /* Avoid compiler warnings. */
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
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

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
                  (unsigned long) yystacksize));

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
#line 404 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = 0; }
#line 2842 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 30:
#line 405 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2848 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 31:
#line 406 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2854 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 32:
#line 407 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2860 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 33:
#line 408 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2866 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 34:
#line 409 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2872 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 35:
#line 410 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2878 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 36:
#line 411 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2884 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 37:
#line 412 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2890 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 38:
#line 415 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = 0; }
#line 2896 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 40:
#line 416 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2902 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 41:
#line 417 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2908 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 42:
#line 418 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2914 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 43:
#line 419 "conf_parser.y" /* yacc.c:1645  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2920 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 50:
#line 432 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2929 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 51:
#line 438 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2938 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 73:
#line 471 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2950 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 74:
#line 480 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2962 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 75:
#line 489 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2974 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 76:
#line 498 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 2986 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 77:
#line 507 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 2998 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 78:
#line 516 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3010 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 79:
#line 525 "conf_parser.y" /* yacc.c:1645  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (server_valid_name(yylval.string) == true)
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3028 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 80:
#line 540 "conf_parser.y" /* yacc.c:1645  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(EXIT_FAILURE);
    }
  }
}
#line 3046 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 81:
#line 555 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3059 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 82:
#line 565 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    xfree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3076 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 83:
#line 579 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3088 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 84:
#line 588 "conf_parser.y" /* yacc.c:1645  */
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
#line 3119 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 85:
#line 616 "conf_parser.y" /* yacc.c:1645  */
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
#line 3150 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 86:
#line 644 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < 1)
  {
    conf_error_report("default_max_clients too low, setting to 1");
    ConfigServerInfo.default_max_clients = 1;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3175 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 87:
#line 666 "conf_parser.y" /* yacc.c:1645  */
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
#line 3200 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 88:
#line 688 "conf_parser.y" /* yacc.c:1645  */
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
#line 3225 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 89:
#line 710 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3234 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 97:
#line 728 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3246 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 98:
#line 737 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3258 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 99:
#line 746 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3270 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 100:
#line 759 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3279 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 101:
#line 763 "conf_parser.y" /* yacc.c:1645  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3296 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 107:
#line 780 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3305 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 108:
#line 786 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3314 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 109:
#line 796 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3323 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 110:
#line 800 "conf_parser.y" /* yacc.c:1645  */
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
#line 3341 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 118:
#line 818 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3350 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 119:
#line 824 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3359 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 120:
#line 830 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3368 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 121:
#line 836 "conf_parser.y" /* yacc.c:1645  */
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
#line 3389 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 128:
#line 864 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3398 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 129:
#line 870 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3407 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 130:
#line 874 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3420 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 137:
#line 890 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3431 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 138:
#line 898 "conf_parser.y" /* yacc.c:1645  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3439 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 139:
#line 901 "conf_parser.y" /* yacc.c:1645  */
    {
  block_state.size.value = 0;
}
#line 3447 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 140:
#line 906 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3456 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 144:
#line 913 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3465 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 145:
#line 917 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3474 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 146:
#line 921 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3483 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 147:
#line 925 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3492 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 148:
#line 929 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3501 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 149:
#line 933 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3510 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 150:
#line 937 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3519 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 151:
#line 941 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3528 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 152:
#line 951 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3540 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 153:
#line 958 "conf_parser.y" /* yacc.c:1645  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (!block_state.rpass.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
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
#line 3597 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 167:
#line 1025 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3606 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 168:
#line 1031 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3615 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 169:
#line 1037 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3624 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 170:
#line 1043 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3633 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 171:
#line 1049 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3647 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 172:
#line 1060 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3656 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 173:
#line 1066 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3670 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 174:
#line 1077 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3679 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 175:
#line 1083 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3688 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 179:
#line 1090 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3697 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 180:
#line 1094 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3706 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 181:
#line 1098 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3715 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 182:
#line 1102 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3724 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 183:
#line 1106 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3733 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 184:
#line 1110 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3742 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 185:
#line 1114 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3751 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 186:
#line 1118 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3760 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 187:
#line 1122 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3769 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 188:
#line 1126 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3778 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 189:
#line 1130 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3787 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 190:
#line 1134 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3796 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 191:
#line 1138 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3805 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 192:
#line 1142 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3814 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 193:
#line 1146 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3823 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 194:
#line 1150 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3832 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 195:
#line 1154 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3841 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 196:
#line 1158 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3850 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 197:
#line 1162 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3859 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 198:
#line 1166 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3868 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 199:
#line 1170 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3877 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 200:
#line 1174 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3886 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 201:
#line 1180 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3895 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 205:
#line 1187 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3904 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 206:
#line 1191 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3913 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 207:
#line 1195 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3922 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 208:
#line 1199 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3931 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 209:
#line 1203 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3940 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 210:
#line 1207 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3949 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 211:
#line 1211 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3958 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 212:
#line 1215 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3967 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 213:
#line 1219 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3976 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 214:
#line 1223 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3985 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 215:
#line 1227 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3994 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 216:
#line 1231 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4003 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 217:
#line 1235 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4012 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 218:
#line 1239 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4021 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 219:
#line 1243 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4030 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 220:
#line 1247 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4039 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 221:
#line 1251 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4048 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 222:
#line 1255 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4057 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 223:
#line 1259 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4066 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 224:
#line 1263 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4075 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 225:
#line 1267 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4084 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 226:
#line 1271 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4093 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 227:
#line 1275 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4102 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 228:
#line 1279 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4111 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 229:
#line 1283 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4120 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 230:
#line 1287 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4129 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 231:
#line 1291 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4138 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 232:
#line 1295 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4147 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 233:
#line 1299 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4156 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 234:
#line 1309 "conf_parser.y" /* yacc.c:1645  */
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
#line 4173 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 235:
#line 1321 "conf_parser.y" /* yacc.c:1645  */
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, false)))
    class = class_make();

  class->active = 1;
  xfree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip_local = block_state.max_perip_local.value;
  class->max_perip_global = block_state.max_perip_global.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
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

  int diff = (class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
              class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(class);
}
#line 4222 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 254:
#line 1385 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4231 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 255:
#line 1391 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4240 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 256:
#line 1397 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4249 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 257:
#line 1403 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4258 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 258:
#line 1409 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4267 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 259:
#line 1415 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4276 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 260:
#line 1421 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4285 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 261:
#line 1427 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 262:
#line 1433 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4304 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 263:
#line 1440 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4313 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 264:
#line 1446 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4322 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 265:
#line 1452 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4331 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 266:
#line 1458 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4343 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 267:
#line 1467 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4355 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 268:
#line 1476 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4364 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 272:
#line 1483 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4373 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 273:
#line 1487 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4382 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 274:
#line 1497 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4391 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 276:
#line 1503 "conf_parser.y" /* yacc.c:1645  */
    {
  block_state.flags.value = 0;
}
#line 4399 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 280:
#line 1509 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4408 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 281:
#line 1513 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4417 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 282:
#line 1517 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4426 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 290:
#line 1525 "conf_parser.y" /* yacc.c:1645  */
    { block_state.flags.value = 0; }
#line 4432 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 294:
#line 1530 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4450 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 295:
#line 1543 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4470 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 296:
#line 1560 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4479 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 297:
#line 1566 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4488 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 298:
#line 1576 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4497 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 299:
#line 1580 "conf_parser.y" /* yacc.c:1645  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;
    char *s = node->data;

    if (EmptyString(s))
      continue;

    nuh.nuhmask  = s;
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
#line 4542 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 311:
#line 1633 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4551 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 312:
#line 1639 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4560 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 313:
#line 1645 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4569 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 314:
#line 1651 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4583 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 315:
#line 1662 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4592 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 319:
#line 1669 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4601 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 320:
#line 1673 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4610 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 321:
#line 1677 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4619 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 322:
#line 1681 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4628 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 323:
#line 1685 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4637 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 324:
#line 1689 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4646 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 325:
#line 1693 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4655 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 326:
#line 1697 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4664 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 327:
#line 1701 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4673 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 328:
#line 1705 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4682 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 329:
#line 1711 "conf_parser.y" /* yacc.c:1645  */
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
#line 4699 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 330:
#line 1725 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4711 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 331:
#line 1734 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4723 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 332:
#line 1747 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4735 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 333:
#line 1754 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4746 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 340:
#line 1765 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4755 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 341:
#line 1771 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4764 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 342:
#line 1777 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4773 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 348:
#line 1792 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4788 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 349:
#line 1808 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4804 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 350:
#line 1819 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4819 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 357:
#line 1834 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4828 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 358:
#line 1840 "conf_parser.y" /* yacc.c:1645  */
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
#line 4850 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 359:
#line 1859 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4859 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 363:
#line 1866 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4868 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 364:
#line 1870 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4877 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 365:
#line 1874 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4886 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 366:
#line 1878 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4895 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 367:
#line 1882 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4904 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 368:
#line 1886 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4913 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 369:
#line 1890 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4922 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 370:
#line 1894 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4931 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 371:
#line 1898 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4940 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 372:
#line 1902 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4949 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 373:
#line 1912 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4963 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 374:
#line 1921 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4976 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 380:
#line 1934 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4985 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 381:
#line 1940 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4994 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 385:
#line 1947 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5003 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 386:
#line 1951 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5012 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 387:
#line 1955 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5021 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 388:
#line 1959 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5030 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 389:
#line 1963 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5039 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 390:
#line 1967 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5048 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 391:
#line 1971 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5057 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 392:
#line 1975 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5066 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 393:
#line 1979 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5075 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 394:
#line 1983 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5084 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 395:
#line 1993 "conf_parser.y" /* yacc.c:1645  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5098 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 396:
#line 2002 "conf_parser.y" /* yacc.c:1645  */
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
#line 5164 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 414:
#line 2082 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5173 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 415:
#line 2088 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5182 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 416:
#line 2094 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5191 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 417:
#line 2100 "conf_parser.y" /* yacc.c:1645  */
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
#line 5207 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 418:
#line 2113 "conf_parser.y" /* yacc.c:1645  */
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
#line 5223 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 419:
#line 2126 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5232 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 420:
#line 2132 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5241 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 421:
#line 2138 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5250 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 422:
#line 2142 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5259 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 423:
#line 2148 "conf_parser.y" /* yacc.c:1645  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5267 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 427:
#line 2154 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5276 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 428:
#line 2158 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5285 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 429:
#line 2164 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5299 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 430:
#line 2175 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5308 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 431:
#line 2181 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5317 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 432:
#line 2187 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5326 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 433:
#line 2193 "conf_parser.y" /* yacc.c:1645  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5340 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 434:
#line 2208 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5349 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 435:
#line 2212 "conf_parser.y" /* yacc.c:1645  */
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
#line 5374 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 441:
#line 2237 "conf_parser.y" /* yacc.c:1645  */
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
#line 5397 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 442:
#line 2257 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5406 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 443:
#line 2267 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5415 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 444:
#line 2271 "conf_parser.y" /* yacc.c:1645  */
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
#line 5441 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 450:
#line 2297 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5450 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 451:
#line 2303 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5459 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 457:
#line 2318 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (*yylval.string && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5476 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 458:
#line 2335 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5485 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 459:
#line 2339 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  struct GecosItem *gecos = gecos_make();
  gecos->mask = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    gecos->reason = xstrdup(block_state.rpass.buf);
  else
    gecos->reason = xstrdup(CONF_NOREASON);
}
#line 5505 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 465:
#line 2359 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5514 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 466:
#line 2365 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5523 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 517:
#line 2427 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5531 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 518:
#line 2432 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5539 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 519:
#line 2437 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5547 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 520:
#line 2442 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5555 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 521:
#line 2447 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5564 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 522:
#line 2453 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5572 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 523:
#line 2458 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5580 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 524:
#line 2463 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5588 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 525:
#line 2468 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5596 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 526:
#line 2473 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5604 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 527:
#line 2478 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 528:
#line 2483 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5620 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 529:
#line 2488 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5628 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 530:
#line 2493 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5636 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 531:
#line 2498 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5644 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 532:
#line 2503 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 533:
#line 2508 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 534:
#line 2513 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5668 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 535:
#line 2518 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 536:
#line 2524 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5685 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 537:
#line 2529 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 538:
#line 2534 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5701 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 539:
#line 2539 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5709 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 540:
#line 2544 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5717 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 541:
#line 2549 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5725 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 542:
#line 2554 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 543:
#line 2559 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5741 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 544:
#line 2562 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5749 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 545:
#line 2567 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5757 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 546:
#line 2570 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5765 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 547:
#line 2575 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5773 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 548:
#line 2580 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5781 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 549:
#line 2585 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5789 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 550:
#line 2590 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5797 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 551:
#line 2595 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5805 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 552:
#line 2600 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5813 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 553:
#line 2605 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 554:
#line 2610 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 555:
#line 2615 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5837 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 556:
#line 2620 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5845 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 557:
#line 2625 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5853 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 558:
#line 2630 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5861 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 559:
#line 2635 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5869 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 563:
#line 2641 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5877 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 564:
#line 2644 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5885 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 565:
#line 2647 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5893 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 566:
#line 2650 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5901 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 567:
#line 2653 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5909 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 568:
#line 2656 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5917 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 569:
#line 2659 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5925 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 570:
#line 2662 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5933 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 571:
#line 2665 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5941 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 572:
#line 2668 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5949 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 573:
#line 2671 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5957 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 574:
#line 2674 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5965 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 575:
#line 2677 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5973 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 576:
#line 2680 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5981 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 577:
#line 2683 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5989 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 578:
#line 2686 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5997 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 579:
#line 2689 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6005 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 580:
#line 2692 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6013 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 581:
#line 2695 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6021 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 582:
#line 2698 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6029 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 583:
#line 2701 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6037 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 584:
#line 2704 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6045 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 585:
#line 2709 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6053 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 589:
#line 2715 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6061 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 590:
#line 2718 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6069 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 591:
#line 2721 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6077 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 592:
#line 2724 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6085 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 593:
#line 2727 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6093 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 594:
#line 2730 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6101 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 595:
#line 2733 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6109 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 596:
#line 2736 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6117 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 597:
#line 2739 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6125 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 598:
#line 2742 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6133 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 599:
#line 2745 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6141 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 600:
#line 2748 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6149 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 601:
#line 2751 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6157 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 602:
#line 2754 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6165 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 603:
#line 2757 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6173 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 604:
#line 2760 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6181 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 605:
#line 2763 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6189 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 606:
#line 2766 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6197 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 607:
#line 2769 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6205 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 608:
#line 2772 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6213 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 609:
#line 2777 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 610:
#line 2782 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 611:
#line 2787 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6237 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 612:
#line 2792 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6245 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 631:
#line 2820 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6253 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 632:
#line 2825 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 633:
#line 2830 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6269 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 634:
#line 2835 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 635:
#line 2840 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 636:
#line 2845 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 637:
#line 2850 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 638:
#line 2855 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 639:
#line 2860 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 640:
#line 2865 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 641:
#line 2870 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6333 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 642:
#line 2875 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6341 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 643:
#line 2880 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6349 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 644:
#line 2885 "conf_parser.y" /* yacc.c:1645  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6357 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 658:
#line 2908 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6366 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 659:
#line 2914 "conf_parser.y" /* yacc.c:1645  */
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
#line 6385 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 660:
#line 2930 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6397 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 661:
#line 2939 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6406 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 662:
#line 2945 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6415 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 663:
#line 2951 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6424 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 664:
#line 2957 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6436 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 665:
#line 2966 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6445 "conf_parser.c" /* yacc.c:1645  */
    break;

  case 666:
#line 2972 "conf_parser.y" /* yacc.c:1645  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6454 "conf_parser.c" /* yacc.c:1645  */
    break;


#line 6458 "conf_parser.c" /* yacc.c:1645  */
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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
