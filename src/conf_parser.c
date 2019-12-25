/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "conf_parser.y" /* yacc.c:337  */


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
    timeout,
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


#line 184 "conf_parser.c" /* yacc.c:337  */
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
    EXPIRATION = 297,
    FAILED_OPER_NOTICE = 298,
    FLATTEN_LINKS = 299,
    FLATTEN_LINKS_DELAY = 300,
    FLATTEN_LINKS_FILE = 301,
    GECOS = 302,
    GENERAL = 303,
    HIDDEN = 304,
    HIDDEN_NAME = 305,
    HIDE_CHANS = 306,
    HIDE_IDLE = 307,
    HIDE_IDLE_FROM_OPERS = 308,
    HIDE_SERVER_IPS = 309,
    HIDE_SERVERS = 310,
    HIDE_SERVICES = 311,
    HOST = 312,
    HUB = 313,
    HUB_MASK = 314,
    INVISIBLE_ON_CONNECT = 315,
    INVITE_CLIENT_COUNT = 316,
    INVITE_CLIENT_TIME = 317,
    INVITE_DELAY_CHANNEL = 318,
    INVITE_EXPIRE_TIME = 319,
    IP = 320,
    IRCD_AUTH = 321,
    IRCD_FLAGS = 322,
    IRCD_SID = 323,
    JOIN = 324,
    KILL = 325,
    KILL_CHASE_TIME_LIMIT = 326,
    KLINE = 327,
    KLINE_EXEMPT = 328,
    KLINE_MIN_CIDR = 329,
    KLINE_MIN_CIDR6 = 330,
    KNOCK_CLIENT_COUNT = 331,
    KNOCK_CLIENT_TIME = 332,
    KNOCK_DELAY_CHANNEL = 333,
    LEAF_MASK = 334,
    LISTEN = 335,
    MASK = 336,
    MAX_ACCEPT = 337,
    MAX_BANS = 338,
    MAX_BANS_LARGE = 339,
    MAX_CHANNELS = 340,
    MAX_IDLE = 341,
    MAX_INVITES = 342,
    MAX_NICK_CHANGES = 343,
    MAX_NICK_LENGTH = 344,
    MAX_NICK_TIME = 345,
    MAX_NUMBER = 346,
    MAX_TARGETS = 347,
    MAX_TOPIC_LENGTH = 348,
    MAX_WATCH = 349,
    MIN_IDLE = 350,
    MIN_NONWILDCARD = 351,
    MIN_NONWILDCARD_SIMPLE = 352,
    MODULE = 353,
    MODULES = 354,
    MOTD = 355,
    NAME = 356,
    NEED_IDENT = 357,
    NEED_PASSWORD = 358,
    NETWORK_DESC = 359,
    NETWORK_NAME = 360,
    NICK = 361,
    NO_OPER_FLOOD = 362,
    NO_TILDE = 363,
    NUMBER = 364,
    NUMBER_PER_CIDR = 365,
    NUMBER_PER_IP_GLOBAL = 366,
    NUMBER_PER_IP_LOCAL = 367,
    OPER_ONLY_UMODES = 368,
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
    T_BIND = 419,
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
    TIMEOUT = 470,
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
    WHOWAS_HISTORY_LENGTH = 483,
    XLINE = 484,
    XLINE_EXEMPT = 485
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
#define EXPIRATION 297
#define FAILED_OPER_NOTICE 298
#define FLATTEN_LINKS 299
#define FLATTEN_LINKS_DELAY 300
#define FLATTEN_LINKS_FILE 301
#define GECOS 302
#define GENERAL 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_CHANS 306
#define HIDE_IDLE 307
#define HIDE_IDLE_FROM_OPERS 308
#define HIDE_SERVER_IPS 309
#define HIDE_SERVERS 310
#define HIDE_SERVICES 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define INVISIBLE_ON_CONNECT 315
#define INVITE_CLIENT_COUNT 316
#define INVITE_CLIENT_TIME 317
#define INVITE_DELAY_CHANNEL 318
#define INVITE_EXPIRE_TIME 319
#define IP 320
#define IRCD_AUTH 321
#define IRCD_FLAGS 322
#define IRCD_SID 323
#define JOIN 324
#define KILL 325
#define KILL_CHASE_TIME_LIMIT 326
#define KLINE 327
#define KLINE_EXEMPT 328
#define KLINE_MIN_CIDR 329
#define KLINE_MIN_CIDR6 330
#define KNOCK_CLIENT_COUNT 331
#define KNOCK_CLIENT_TIME 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LISTEN 335
#define MASK 336
#define MAX_ACCEPT 337
#define MAX_BANS 338
#define MAX_BANS_LARGE 339
#define MAX_CHANNELS 340
#define MAX_IDLE 341
#define MAX_INVITES 342
#define MAX_NICK_CHANGES 343
#define MAX_NICK_LENGTH 344
#define MAX_NICK_TIME 345
#define MAX_NUMBER 346
#define MAX_TARGETS 347
#define MAX_TOPIC_LENGTH 348
#define MAX_WATCH 349
#define MIN_IDLE 350
#define MIN_NONWILDCARD 351
#define MIN_NONWILDCARD_SIMPLE 352
#define MODULE 353
#define MODULES 354
#define MOTD 355
#define NAME 356
#define NEED_IDENT 357
#define NEED_PASSWORD 358
#define NETWORK_DESC 359
#define NETWORK_NAME 360
#define NICK 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_CIDR 365
#define NUMBER_PER_IP_GLOBAL 366
#define NUMBER_PER_IP_LOCAL 367
#define OPER_ONLY_UMODES 368
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
#define T_BIND 419
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
#define TIMEOUT 470
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
#define WHOWAS_HISTORY_LENGTH 483
#define XLINE 484
#define XLINE_EXEMPT 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 142 "conf_parser.y" /* yacc.c:352  */

  int number;
  char *string;

#line 692 "conf_parser.c" /* yacc.c:352  */
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
#define YYLAST   1252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  665
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1307

#define YYUNDEFTOK  2
#define YYMAXUTOK   485

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   235,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   236,   231,
       2,   234,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,     2,   232,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   376,   376,   377,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     396,   397,   398,   399,   400,   401,   402,   403,   407,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   418,   418,
     419,   420,   421,   422,   429,   431,   431,   432,   432,   432,
     434,   440,   450,   452,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   471,   480,   489,   498,   507,   516,   525,   540,   555,
     565,   579,   588,   611,   634,   657,   667,   669,   669,   670,
     671,   672,   673,   675,   684,   693,   707,   706,   724,   724,
     725,   725,   725,   727,   733,   744,   743,   762,   762,   763,
     763,   763,   763,   763,   765,   771,   777,   783,   805,   806,
     806,   808,   808,   809,   811,   818,   818,   831,   832,   834,
     834,   835,   835,   837,   845,   848,   854,   853,   859,   859,
     860,   864,   868,   872,   876,   880,   884,   888,   899,   898,
     961,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   974,   980,   986,   992,   998,  1009,  1015,
    1026,  1033,  1032,  1038,  1038,  1039,  1043,  1047,  1051,  1055,
    1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,  1091,  1095,
    1099,  1103,  1107,  1111,  1115,  1119,  1123,  1127,  1134,  1133,
    1139,  1139,  1140,  1144,  1148,  1152,  1156,  1160,  1164,  1168,
    1172,  1176,  1180,  1184,  1188,  1192,  1196,  1200,  1204,  1208,
    1212,  1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,
    1252,  1263,  1262,  1319,  1319,  1320,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1337,  1343,  1349,  1355,  1361,  1367,  1373,  1379,  1385,
    1392,  1398,  1404,  1410,  1419,  1429,  1428,  1434,  1434,  1435,
    1439,  1450,  1449,  1456,  1455,  1460,  1460,  1461,  1465,  1469,
    1475,  1475,  1476,  1476,  1476,  1476,  1476,  1478,  1478,  1480,
    1480,  1482,  1495,  1512,  1518,  1529,  1528,  1575,  1575,  1576,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1586,  1592,
    1598,  1604,  1616,  1615,  1621,  1621,  1622,  1626,  1630,  1634,
    1638,  1642,  1646,  1650,  1654,  1658,  1664,  1678,  1687,  1701,
    1700,  1715,  1715,  1716,  1716,  1716,  1716,  1718,  1724,  1730,
    1740,  1742,  1742,  1743,  1743,  1745,  1762,  1761,  1784,  1784,
    1785,  1785,  1785,  1785,  1787,  1793,  1813,  1812,  1818,  1818,
    1819,  1823,  1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,
    1866,  1865,  1884,  1884,  1885,  1885,  1885,  1887,  1894,  1893,
    1899,  1899,  1900,  1904,  1908,  1912,  1916,  1920,  1924,  1928,
    1932,  1936,  1947,  1946,  2024,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2042,  2048,  2054,  2060,  2066,  2079,  2092,  2098,
    2104,  2108,  2115,  2114,  2119,  2119,  2120,  2124,  2130,  2141,
    2147,  2153,  2159,  2175,  2174,  2198,  2198,  2199,  2199,  2199,
    2201,  2221,  2232,  2231,  2256,  2256,  2257,  2257,  2257,  2259,
    2265,  2275,  2277,  2277,  2278,  2278,  2280,  2298,  2297,  2318,
    2318,  2319,  2319,  2319,  2321,  2327,  2337,  2339,  2339,  2340,
    2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,
    2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2360,
    2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2370,
    2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  2384,  2385,  2388,  2393,  2398,  2403,  2408,
    2413,  2418,  2423,  2428,  2433,  2438,  2443,  2448,  2453,  2458,
    2463,  2468,  2473,  2478,  2483,  2488,  2493,  2498,  2503,  2508,
    2513,  2516,  2521,  2524,  2529,  2534,  2539,  2544,  2549,  2554,
    2559,  2564,  2569,  2574,  2579,  2584,  2590,  2589,  2594,  2594,
    2595,  2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,  2622,
    2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,  2652,
    2655,  2658,  2661,  2667,  2666,  2671,  2671,  2672,  2675,  2678,
    2681,  2684,  2687,  2690,  2693,  2696,  2699,  2702,  2705,  2708,
    2711,  2714,  2717,  2720,  2723,  2726,  2729,  2732,  2737,  2742,
    2747,  2752,  2761,  2763,  2763,  2764,  2765,  2766,  2767,  2768,
    2769,  2770,  2771,  2772,  2773,  2774,  2775,  2776,  2777,  2778,
    2780,  2785,  2790,  2795,  2800,  2805,  2810,  2815,  2820,  2825,
    2830,  2835,  2840,  2845,  2854,  2856,  2856,  2857,  2858,  2859,
    2860,  2861,  2862,  2863,  2864,  2865,  2866,  2868,  2874,  2890,
    2899,  2905,  2911,  2917,  2926,  2932
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
  "EXPIRATION", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
  "FLATTEN_LINKS_DELAY", "FLATTEN_LINKS_FILE", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "INVISIBLE_ON_CONNECT",
  "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME", "INVITE_DELAY_CHANNEL",
  "INVITE_EXPIRE_TIME", "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID",
  "JOIN", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_MIN_CIDR", "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT",
  "KNOCK_CLIENT_TIME", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LISTEN",
  "MASK", "MAX_ACCEPT", "MAX_BANS", "MAX_BANS_LARGE", "MAX_CHANNELS",
  "MAX_IDLE", "MAX_INVITES", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
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
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG",
  "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE",
  "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS",
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT",
  "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE",
  "USE_LOGGING", "USER", "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK",
  "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_default_max_clients",
  "serverinfo_max_nick_length", "serverinfo_max_topic_length",
  "serverinfo_hub", "admin_entry", "admin_items", "admin_item",
  "admin_name", "admin_email", "admin_description", "motd_entry", "$@1",
  "motd_items", "motd_item", "motd_mask", "motd_file", "pseudo_entry",
  "$@2", "pseudo_items", "pseudo_item", "pseudo_command", "pseudo_name",
  "pseudo_prepend", "pseudo_target", "logging_entry", "logging_items",
  "logging_item", "logging_use_logging", "logging_file_entry", "$@3",
  "logging_file_items", "logging_file_item", "logging_file_name",
  "logging_file_size", "logging_file_type", "$@4",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@5",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_whois", "oper_encrypted", "oper_ssl_certificate_fingerprint",
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
  "connect_host", "connect_timeout", "connect_bind",
  "connect_send_password", "connect_accept_password",
  "connect_ssl_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@21", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@22",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@23", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@24", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_away_count", "general_away_time", "general_max_watch",
  "general_whowas_history_length", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_kill_chase_time_limit", "general_failed_oper_notice",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -868

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-868)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -868,   655,  -868,  -141,  -211,  -206,  -868,  -868,  -868,  -197,
    -868,  -194,  -868,  -868,  -868,  -192,  -868,  -868,  -868,  -189,
    -163,  -868,  -137,  -868,  -115,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   364,   879,  -112,   -72,   -71,    15,   -69,   353,   -50,
     -49,   -15,    37,   -12,   -11,   -10,   575,   544,    -7,    54,
      -5,    10,    49,  -169,  -161,    38,    60,     7,  -868,  -868,
    -868,  -868,  -868,    62,    64,    69,    73,    75,    77,    79,
      80,    83,    99,   100,   101,   102,   106,   266,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,   651,   549,    19,  -868,   107,    34,  -868,
    -868,    93,  -868,   118,   121,   122,   123,   124,   127,   130,
     137,   141,   146,   153,   159,   163,   165,   167,   170,   172,
     173,   174,   175,   176,   180,   181,   183,   184,  -868,  -868,
     186,   187,   188,   189,   191,   196,   197,   199,   200,   202,
     204,   210,   214,   221,   222,   223,   224,   225,    42,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,   373,   149,   338,    52,   228,
     229,     2,  -868,  -868,  -868,   151,   372,    28,  -868,   238,
     241,   242,   243,   253,   254,   255,   256,   260,   136,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,   139,
     261,   262,   263,   270,   272,   273,   274,   282,   283,   284,
     285,   287,   288,   291,   293,   147,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,    24,   150,   294,    31,  -868,  -868,  -868,   354,
     230,  -868,   296,    46,  -868,  -868,    67,  -868,   408,   409,
     410,   304,  -868,   427,   429,   328,   432,   429,   429,   429,
     435,   429,   429,   437,   438,   439,   440,   311,  -868,   320,
     319,   323,   324,  -868,   325,   326,   329,   335,   339,   344,
     346,   349,   350,   351,   355,   194,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   356,   357,   359,   360,   363,   366,   369,  -868,
     370,   377,   379,   381,   383,   388,   392,   398,   168,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,   400,   401,    18,  -868,
    -868,  -868,   466,   367,  -868,  -868,   402,   405,    25,  -868,
    -868,  -868,   365,   429,   498,   429,   429,   430,   535,   429,
     434,   538,   542,   551,   441,   446,   429,   552,   554,   556,
     557,   429,   558,   561,   566,   568,   468,   447,   448,   473,
     429,   429,   475,   478,   480,  -195,  -188,   481,   483,   489,
     499,   603,   429,   429,   429,   502,   606,   485,  -868,   488,
     490,   492,  -868,   494,   497,   500,   504,   505,   219,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,   506,
     507,    41,  -868,  -868,  -868,   491,   509,   510,  -868,   513,
    -868,    30,  -868,  -868,  -868,  -868,  -868,   599,   608,   518,
    -868,   520,   519,   522,    39,  -868,  -868,  -868,   527,   525,
     531,  -868,   534,   537,   540,   541,  -868,   543,   545,    14,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   547,   546,   548,   550,    17,  -868,  -868,  -868,  -868,
     521,   560,   429,   645,   564,   657,   571,   573,   574,   565,
    -868,  -868,   679,   665,   579,   673,   689,   692,   681,   685,
     688,   693,   695,   698,   699,   701,   703,   597,  -868,   598,
     582,  -868,    45,  -868,  -868,  -868,  -868,   619,   601,  -868,
     600,   607,   623,   624,   626,   629,    11,  -868,  -868,  -868,
    -868,  -868,   716,   622,  -868,   633,   631,  -868,   632,    22,
    -868,  -868,  -868,  -868,   638,   639,   641,  -868,   642,   343,
     643,   647,   648,   650,   659,   662,   666,   667,   669,   672,
     677,   682,   683,  -868,  -868,   759,   800,   429,   676,   809,
     429,   810,   429,   796,   812,   814,   815,   429,   816,   816,
     702,  -868,  -868,   802,   -74,   805,   720,   811,   813,   700,
     821,   822,   827,   823,   824,   825,   826,   429,   707,  -868,
     829,   830,   708,  -868,   727,  -868,   835,   836,   730,  -868,
     734,   736,   737,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   751,   752,   753,   754,
     755,   756,   757,   758,   760,   718,   637,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,   773,
     774,   775,   776,   777,   778,   779,   780,  -868,  -868,   866,
     801,   717,   888,   905,   891,   892,   893,   787,  -868,   895,
     896,   790,  -868,  -868,   898,   899,   791,   915,   795,  -868,
     797,   798,  -868,  -868,   903,   906,   803,  -868,  -868,   907,
     820,   799,   911,   912,   913,   828,   804,   917,   918,   808,
    -868,  -868,   919,   920,   921,   817,  -868,   818,   819,   831,
     832,   833,   834,   837,   838,   839,  -868,   840,   841,   842,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
     853,   854,  -868,  -868,   922,   855,   856,  -868,   857,  -868,
      88,  -868,   923,   927,   928,   929,   859,  -868,   860,  -868,
    -868,   930,   858,   931,   862,  -868,  -868,  -868,  -868,  -868,
     429,   429,   429,   429,   429,   429,   429,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   863,   864,   865,   -39,   867,   868,   869,   870,
     871,   872,   873,   874,   875,   310,   876,   877,  -868,   878,
     880,   881,   882,   883,   884,   885,    -4,   886,   887,   889,
     890,   894,   897,   900,   901,  -868,   902,   904,  -868,  -868,
     908,   909,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -201,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -181,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,   910,   914,   453,   916,
     924,   925,   926,   932,  -868,   933,   934,  -868,   935,   936,
      33,   939,   937,  -868,  -868,  -868,  -868,   938,   940,  -868,
     942,   943,   433,   944,   945,   946,   947,   678,   948,   949,
    -868,   950,   951,   952,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,   953,
     585,  -868,  -868,   954,   955,   956,  -868,    92,  -868,  -868,
    -868,  -868,   957,   960,   961,   962,  -868,  -868,   963,   723,
     964,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -174,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,   816,   816,   816,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -172,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,   718,  -868,   637,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -171,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -160,  -868,   958,   915,   965,
    -868,  -868,  -868,  -868,  -868,  -868,   861,  -868,   966,   967,
    -868,  -868,   968,   969,  -868,  -868,   970,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -159,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -143,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -104,  -868,  -868,   986,
     -96,   973,   977,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,   -59,
    -868,  -868,  -868,   -39,  -868,  -868,  -868,  -868,    -4,  -868,
    -868,  -868,   453,  -868,    33,  -868,  -868,  -868,   989,   990,
     993,   992,   996,   997,  -868,   433,  -868,   678,  -868,   585,
     978,   979,   980,   314,  -868,  -868,   723,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   -57,  -868,  -868,  -868,   314,  -868
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   231,   392,   442,     0,
     457,     0,   295,   433,   271,     0,    96,   148,   329,     0,
       0,   370,     0,   105,     0,   346,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      91,    90,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,   628,
     617,   618,   619,   620,   621,   622,   623,   624,   625,   615,
     616,   626,   627,     0,     0,     0,   455,     0,     0,   453,
     454,     0,   514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   583,   556,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   468,
     469,   470,   512,   476,   513,   507,   508,   509,   510,   480,
     471,   472,   473,   474,   475,   477,   478,   479,   481,   482,
     511,   486,   487,   488,   489,   485,   484,   490,   497,   498,
     491,   492,   493,   483,   495,   505,   506,   503,   504,   496,
     494,   501,   502,   499,   500,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,     0,   656,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   646,
     647,   648,   649,   650,   651,   652,   654,   653,   655,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    67,    65,    63,
      68,    69,    64,    55,    66,    57,    58,    59,    60,    61,
      62,    56,     0,     0,     0,     0,   120,   121,   122,     0,
       0,   344,     0,     0,   342,   343,     0,    92,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   238,   240,
     241,   242,   243,   244,   245,   246,   236,   237,   239,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
     396,   397,   398,   399,   400,   401,   402,   404,   403,   406,
     410,   407,   408,   409,   405,   448,     0,     0,     0,   445,
     446,   447,     0,     0,   452,   463,     0,     0,     0,   460,
     461,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   467,     0,
       0,     0,   312,     0,     0,     0,     0,     0,     0,   298,
     299,   300,   301,   306,   302,   303,   304,   305,   439,     0,
       0,     0,   436,   437,   438,     0,     0,     0,   273,     0,
     283,     0,   281,   282,   284,   285,    49,     0,     0,     0,
      45,     0,     0,     0,     0,    99,   100,   101,     0,     0,
       0,   198,     0,     0,     0,     0,   171,     0,     0,     0,
     151,   152,   153,   154,   155,   158,   159,   160,   157,   156,
     161,     0,     0,     0,     0,     0,   332,   333,   334,   335,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     645,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    53,     0,
       0,   378,     0,   373,   374,   375,   123,     0,     0,   119,
       0,     0,     0,     0,     0,     0,     0,   108,   109,   111,
     110,   112,     0,     0,   341,     0,     0,   356,     0,     0,
     349,   350,   351,   352,     0,     0,     0,    86,     0,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   411,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,     0,   444,     0,   451,     0,     0,     0,   459,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   466,   307,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   297,     0,
       0,     0,   435,   286,     0,     0,     0,     0,     0,   280,
       0,     0,    44,   102,     0,     0,     0,    98,   162,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     150,   336,     0,     0,     0,     0,   331,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   644,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,   376,     0,     0,     0,   372,     0,   118,
       0,   113,     0,     0,     0,     0,     0,   107,     0,   340,
     353,     0,     0,     0,     0,   348,    95,    94,    93,   642,
      28,    28,    28,    28,    28,    28,    28,    30,    29,   643,
     630,   631,   632,   633,   634,   635,   636,   637,   640,   641,
     638,   639,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,   232,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   393,     0,     0,   443,   456,
       0,     0,   458,   526,   530,   515,   516,   545,   519,   610,
     611,   553,   520,   521,   550,   525,   533,   524,   522,   523,
     529,   528,   527,   551,   517,   608,   609,   549,   607,   593,
     587,   603,   588,   589,   590,   598,   606,   591,   600,   604,
     594,   605,   595,   599,   592,   602,   597,   596,   601,     0,
     586,   582,   565,   566,   567,   560,   578,   561,   562,   563,
     573,   581,   564,   575,   579,   569,   580,   570,   574,   568,
     577,   572,   571,   576,     0,   559,   546,   544,   547,   552,
     548,   535,   542,   543,   540,   541,   536,   537,   538,   539,
     554,   555,   532,   531,   534,   518,     0,     0,     0,     0,
       0,     0,     0,     0,   296,     0,     0,   434,     0,     0,
       0,   291,   287,   290,   272,    50,    51,     0,     0,    97,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     149,     0,     0,     0,   330,   660,   657,   658,   659,   664,
     663,   665,   661,   662,    82,    79,    85,    78,    83,    84,
      77,    81,    80,    72,    71,    76,    73,    75,    74,     0,
       0,   371,   124,     0,     0,     0,   136,     0,   128,   129,
     131,   130,     0,     0,     0,     0,   106,   345,     0,     0,
       0,   347,    31,    32,    33,    34,    35,    36,    37,   260,
     261,   255,   270,   269,     0,   268,   256,   264,   257,   263,
     251,   262,   254,   253,   252,    38,    38,    38,    40,    39,
     258,   259,   417,   420,   421,   431,   428,   413,   429,   426,
     427,     0,   425,   430,   412,   419,   416,   418,   415,   432,
     414,   449,   450,   464,   465,   584,     0,   557,     0,   310,
     311,   321,   317,   318,   320,   325,   322,   323,   316,   324,
     319,     0,   315,   309,   328,   327,   326,   308,   441,   440,
     294,   293,   278,   279,   277,     0,   276,     0,     0,     0,
     103,   104,   170,   167,   218,   230,   205,   214,     0,   203,
     208,   224,     0,   217,   222,   228,   207,   210,   219,   221,
     225,   215,   223,   211,   229,   213,   220,   209,   212,     0,
     201,   163,   165,   168,   169,   197,   180,   181,   182,   175,
     193,   176,   177,   178,   188,   196,   179,   190,   194,   184,
     195,   185,   189,   183,   192,   187,   186,   191,     0,   174,
     164,   166,   339,   337,   338,   377,   382,   388,   391,   384,
     390,   385,   389,   387,   383,   386,     0,   381,   132,     0,
       0,     0,     0,   127,   115,   114,   116,   117,   354,   360,
     366,   369,   362,   368,   363,   367,   365,   361,   364,     0,
     359,   355,   266,     0,    41,    42,    43,   423,     0,   585,
     558,   313,     0,   274,     0,   292,   289,   288,     0,     0,
       0,     0,     0,     0,   199,     0,   172,     0,   379,     0,
       0,     0,     0,     0,   126,   357,     0,   267,   424,   314,
     275,   204,   227,   202,   226,   216,   206,   200,   173,   380,
     133,   135,   134,   146,   145,   141,   143,   147,   144,   140,
     142,     0,   139,   358,   137,     0,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -868,  -868,  -868,  -106,  -302,  -867,  -628,  -868,  -868,   941,
    -868,  -868,  -868,  -868,   792,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   981,  -868,  -868,  -868,  -868,  -868,  -868,   562,
    -868,  -868,  -868,  -868,  -868,   484,  -868,  -868,  -868,  -868,
    -868,  -868,   781,  -868,  -868,  -868,  -868,    97,  -868,  -868,
    -868,  -868,  -868,  -246,  -868,  -868,  -868,   577,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -138,
    -868,  -868,  -868,  -204,  -868,  -868,  -868,   807,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -113,  -868,  -868,  -868,  -868,
    -868,  -118,  -868,   656,  -868,  -868,  -868,     0,  -868,  -868,
    -868,  -868,  -868,   686,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -109,  -868,  -868,  -868,  -868,  -868,  -868,   621,  -868,
    -868,  -868,  -868,  -868,   959,  -868,  -868,  -868,  -868,   559,
    -868,  -868,  -868,  -868,  -868,  -127,  -868,  -868,  -868,   588,
    -868,  -868,  -868,  -868,  -117,  -868,  -868,  -868,   783,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,   -95,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
     690,  -868,  -868,  -868,  -868,  -868,   782,  -868,  -868,  -868,
    -868,  1036,  -868,  -868,  -868,  -868,   788,  -868,  -868,  -868,
    -868,   991,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,    89,  -868,  -868,  -868,    81,  -868,
    -868,  -868,  -868,  -868,  -868,  1063,  -868,  -868,  -868,  -868,
    -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868,   974,  -868,  -868,  -868,  -868,  -868,  -868,  -868,
    -868,  -868
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   817,   818,  1078,  1079,    27,   221,   222,
     223,   224,    28,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      29,    77,    78,    79,    80,    81,    30,    63,   494,   495,
     496,   497,    31,    70,   576,   577,   578,   579,   580,   581,
      32,   285,   286,   287,   288,   289,  1037,  1038,  1039,  1040,
    1041,  1221,  1301,  1302,    33,    64,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   746,  1198,  1199,
     520,   741,  1169,  1170,    34,    53,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   618,  1064,  1065,    35,    61,   480,   726,
    1135,  1136,   481,   482,   483,  1139,   982,   983,   484,   485,
      36,    59,   458,   459,   460,   461,   462,   463,   464,   711,
    1121,  1122,   465,   466,   467,    37,    65,   525,   526,   527,
     528,   529,    38,   293,   294,   295,    39,    72,   589,   590,
     591,   592,   593,   802,  1239,  1240,    40,    68,   562,   563,
     564,   565,   785,  1216,  1217,    41,    54,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   378,   379,   639,
    1091,  1092,   380,   381,   382,   383,   384,    42,    60,   471,
     472,   473,   474,    43,    55,   388,   389,   390,   391,    44,
     118,   119,   120,    45,    57,   398,   399,   400,   401,    46,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   428,   944,   945,   210,   427,   919,   920,   211,
     212,   213,   214,    47,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      48,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     846,   847,   600,   218,  1089,   603,   604,   605,    73,   607,
     608,   291,   571,   845,  1062,   498,   116,   693,   521,   385,
     385,   694,    51,   585,   695,   559,   395,    52,   696,   521,
    1105,   475,   283,   499,  1106,   116,    56,    74,   218,    58,
     491,    62,   468,   122,    66,    75,   559,   291,   123,   124,
    1107,   125,   126,   500,  1108,   283,   127,  1242,   522,  1247,
    1251,  1243,   297,  1248,  1252,   128,   129,   130,   585,   522,
      67,  1253,  1264,   298,   131,  1254,  1265,   132,   133,   134,
     117,   501,  1132,   386,   386,   135,  1063,   476,  1266,  1033,
      49,    50,  1267,  1033,   395,   477,    69,   478,   523,   117,
     219,   661,   136,   663,   664,   850,   851,   667,    76,   523,
    1271,   292,   572,   137,   674,   502,   138,   139,    71,   679,
     492,   113,   220,   586,   140,   560,   396,  1268,   688,   689,
     141,  1269,   142,   503,   143,   219,   144,   228,   145,   146,
     702,   703,   704,   524,   387,   387,   560,   292,   249,   147,
     468,   397,   491,   479,   524,   148,   149,   220,   150,   151,
     152,   114,   115,   153,   121,   504,   505,   469,   586,   352,
     229,   353,  1275,   354,  1304,   250,  1276,   251,  1305,   573,
     230,   231,   232,   215,   216,   233,   234,   355,   154,  1034,
     235,   236,   237,  1034,   396,   319,  1090,   574,   155,   156,
     157,   158,   159,   160,   161,   252,  -125,   356,  1244,  1245,
    1246,   320,   321,   575,   493,   253,   322,   506,   217,   397,
     449,   225,   226,   227,  1133,   357,   282,   358,   290,  -125,
     759,   571,   492,  1134,   489,   359,   254,   507,   450,   301,
     255,   508,   587,   796,   561,   588,   749,   360,   256,   755,
     652,   257,   258,   284,   804,   162,   163,   658,   451,   164,
     165,   323,   728,   568,   470,   561,   393,    82,   166,   361,
     167,   736,   299,   721,   447,   469,   284,   786,   583,   324,
     325,   259,   296,   486,  1035,   326,   452,   587,  1035,   327,
     588,   362,    83,    84,   300,   328,   303,   260,   304,    85,
     261,   262,   263,   305,   329,   330,   331,   306,  1036,   307,
     363,   308,  1036,   309,   310,   834,   332,   311,   837,   364,
     839,  1075,  1076,  1077,  1222,   844,   493,    86,    87,    88,
      89,   572,   365,   312,   313,   314,   315,   333,   453,   475,
     316,   392,    90,    91,    92,   864,   454,   455,   264,    93,
      94,    95,   402,    96,   122,   403,   404,   405,   406,   123,
     124,   407,   125,   126,   408,    73,   456,   127,   539,   366,
     541,   409,   470,   498,   449,   410,   128,   129,   130,   557,
     411,   566,   334,   367,  1293,   131,  1294,   412,   132,   133,
     134,   499,   450,   413,    74,   476,   135,   414,   573,   415,
     648,   416,    75,   477,   417,   478,   418,   419,   420,   421,
     422,   500,   451,   136,   423,   424,   574,   425,   426,   845,
     429,   430,   431,   432,   137,   433,   630,   138,   139,  1295,
     434,   435,   575,   436,   437,   140,   438,  1144,   439,   501,
     452,   141,   457,   142,   440,   143,  1296,   144,   441,   145,
     146,   717,   599,  1145,  1146,   442,   443,   444,   445,   446,
     147,   479,   487,   488,  1147,    76,   148,   149,  1111,   150,
     151,   152,   530,   502,   153,   531,   532,   533,   810,   811,
     812,   813,   814,   815,   816,  1297,  1298,   534,   535,   536,
     537,   503,   453,  1112,   538,   542,   543,   544,   317,   154,
     454,   455,  1148,  1149,   545,  1150,   546,   547,   548,   155,
     156,   157,   158,   159,   160,   161,   549,   550,   551,   552,
     456,   553,   554,   504,   505,   555,  1113,   556,   567,   570,
     582,  1151,   594,   595,   596,   597,   598,  1299,   599,  1152,
     601,   602,   613,  1300,   606,   249,   609,   610,   611,   612,
     352,   614,   353,   615,   354,  1114,  1115,   616,   617,   619,
     620,  1116,  1153,   621,  1154,  1155,   162,   163,   355,   622,
     164,   165,   250,   623,   251,   506,   228,   660,   624,   166,
     625,   167,  1156,   626,   627,   628,  1117,   632,   356,   629,
     654,   633,  1272,   634,   635,   507,   457,   636,   655,   508,
     637,  1118,   252,   638,   640,  1157,   357,   662,   358,   229,
    1158,   641,   253,   642,  1159,   643,   359,   644,  1160,   230,
     231,   232,   645,  1161,   233,   234,   646,  1162,   360,   235,
     236,   237,   647,   254,   650,   651,   656,   255,  1163,   657,
    1164,  1165,   665,  1166,   666,   256,   668,   669,   257,   258,
     361,   670,   319,   672,  1167,     2,     3,  1206,   673,     4,
     671,   675,  1168,   676,  1119,   677,   678,   680,   320,   321,
     681,     5,   362,   322,     6,   682,     7,   683,   259,   921,
     684,   685,   686,  1120,     8,   687,   922,   690,   923,   924,
     691,   363,   692,   697,   260,   698,     9,   261,   262,   263,
     364,   699,    10,    11,  1052,  1053,  1054,  1055,  1056,  1057,
    1058,   700,   701,   365,   705,   706,   707,  1207,   323,   708,
    1175,    12,   723,   730,   709,    13,   710,  1176,   712,  1177,
    1178,   713,   731,   757,   714,    14,   324,   325,   715,   716,
     719,   720,   326,   724,   725,   264,   327,   727,  1208,   732,
     366,   733,   328,   734,    15,    16,   735,  1209,   738,   739,
     898,   329,   330,   331,   367,   740,  1210,   899,   742,   760,
      17,   743,   758,   332,   744,   745,   761,   747,   751,   748,
     752,   762,   753,   763,   754,   764,   765,    18,   767,   768,
    1211,   769,  1212,  1213,   333,  1229,   766,   770,   771,    19,
      20,   772,   925,   926,   927,   773,  1214,   928,   929,   774,
     930,   931,   775,   932,  1215,   933,   784,   776,   934,   777,
     935,   936,   778,   779,    21,   780,   937,   781,   782,   783,
     938,   788,   789,   790,   939,   940,   941,    22,   791,   334,
     798,   942,    23,  1179,  1180,  1181,   943,    24,  1182,  1183,
      25,  1184,  1185,   799,  1186,  1230,  1187,   792,   793,  1188,
     794,  1189,  1190,   795,   800,   801,   803,  1191,   832,   806,
     807,  1192,   808,   809,   819,  1193,  1194,  1195,   820,   821,
      82,   822,  1196,   900,   901,   902,  1231,  1197,   903,   904,
     823,   905,   906,   824,   907,  1232,   908,   825,   826,   909,
     827,   910,   911,   828,  1233,    83,    84,   912,   829,   833,
     835,   913,    85,   830,   831,   914,   915,   916,   836,   838,
     840,   841,   917,   842,   843,   845,   849,   918,  1234,   852,
    1235,  1236,   853,   848,   856,   854,   859,   855,   865,   868,
      86,    87,    88,    89,  1237,   857,   858,   860,   861,   862,
     863,   968,  1238,   866,   867,    90,    91,    92,   869,   870,
     871,   872,    93,    94,    95,   873,    96,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   890,   891,   892,   893,   894,   895,   896,
     966,   897,   946,   947,   948,   949,   950,   951,   952,   953,
     954,   955,   956,   957,   958,   959,   960,   961,   962,   963,
     964,   965,   969,   967,   970,   971,   972,   973,   974,   975,
     976,   977,   978,   979,   981,   980,   984,   987,   985,   986,
     988,   990,   991,   992,   989,   993,   994,   995,   997,  1000,
     996,   998,   999,  1001,  1002,  1003,  1029,  1042,  1004,  1005,
    1006,  1043,  1044,  1045,  1048,  1050,   737,   558,   302,  1306,
     797,  1287,  1007,  1008,  1009,  1010,   569,  1255,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,   750,  1031,  1032,  1030,
    1046,  1047,  1049,  1051,  1059,  1060,  1061,  1258,  1066,  1067,
    1068,  1069,  1070,  1071,  1072,  1073,  1074,  1080,  1081,  1082,
    1270,  1083,  1084,  1085,  1086,  1087,  1088,  1093,  1094,  1281,
    1095,  1096,  1282,  1283,  1284,  1097,  1285,  1286,  1098,  1288,
    1277,  1099,  1100,  1101,  1223,  1102,  1280,   729,  1256,  1103,
    1104,  1109,   631,  1279,   718,  1110,   756,  1123,   805,  1303,
     787,   649,  1289,  1278,   394,  1124,  1125,  1126,  1137,   448,
     318,   722,   490,  1127,  1128,  1129,  1130,  1131,     0,  1140,
     653,  1141,  1138,  1142,  1143,  1171,  1172,  1173,  1174,  1200,
    1201,  1202,  1203,  1204,  1205,  1218,   659,  1249,  1224,  1219,
    1220,  1225,  1226,  1227,  1228,  1241,  1257,  1250,     0,     0,
       0,     0,  1259,  1260,  1261,  1262,  1263,  1273,  1274,  1290,
    1291,  1292,   540,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   584
};

static const yytype_int16 yycheck[] =
{
     628,   629,   304,     1,     8,   307,   308,   309,     1,   311,
     312,     1,     1,   109,    53,     1,     1,   212,     1,     1,
       1,   216,   233,     1,   212,     1,     1,   233,   216,     1,
     231,     1,     1,    19,   235,     1,   233,    30,     1,   233,
       1,   233,     1,     1,   233,    38,     1,     1,     6,     7,
     231,     9,    10,    39,   235,     1,    14,   231,    41,   231,
     231,   235,   231,   235,   235,    23,    24,    25,     1,    41,
     233,   231,   231,   234,    32,   235,   235,    35,    36,    37,
      65,    67,    49,    65,    65,    43,   125,    57,   231,     1,
     231,   232,   235,     1,     1,    65,   233,    67,    81,    65,
      98,   403,    60,   405,   406,   179,   180,   409,   101,    81,
     206,   101,   101,    71,   416,   101,    74,    75,   233,   421,
      81,   233,   120,   101,    82,   101,   101,   231,   430,   431,
      88,   235,    90,   119,    92,    98,    94,     1,    96,    97,
     442,   443,   444,   126,   126,   126,   101,   101,     1,   107,
       1,   126,     1,   123,   126,   113,   114,   120,   116,   117,
     118,   233,   233,   121,   233,   151,   152,   126,   101,     1,
      34,     3,   231,     5,   231,    28,   235,    30,   235,   168,
      44,    45,    46,   233,   233,    49,    50,    19,   146,   101,
      54,    55,    56,   101,   101,     1,   200,   186,   156,   157,
     158,   159,   160,   161,   162,    58,   175,    39,  1075,  1076,
    1077,    17,    18,   202,   175,    68,    22,   203,   233,   126,
       1,   233,   233,   233,   191,    57,   233,    59,   233,   175,
     532,     1,    81,   200,   232,    67,    89,   223,    19,   232,
      93,   227,   220,   232,   220,   223,   232,    79,   101,   232,
     232,   104,   105,   222,   232,   213,   214,   232,    39,   217,
     218,    67,   232,   232,   223,   220,   232,     1,   226,   101,
     228,   232,   234,   232,   232,   126,   222,   232,   232,    85,
      86,   134,   233,   231,   196,    91,    67,   220,   196,    95,
     223,   123,    26,    27,   234,   101,   234,   150,   234,    33,
     153,   154,   155,   234,   110,   111,   112,   234,   220,   234,
     142,   234,   220,   234,   234,   617,   122,   234,   620,   151,
     622,    11,    12,    13,   232,   627,   175,    61,    62,    63,
      64,   101,   164,   234,   234,   234,   234,   143,   119,     1,
     234,   234,    76,    77,    78,   647,   127,   128,   201,    83,
      84,    85,   234,    87,     1,   234,   234,   234,   234,     6,
       7,   234,     9,    10,   234,     1,   147,    14,   232,   201,
     231,   234,   223,     1,     1,   234,    23,    24,    25,   232,
     234,   231,   188,   215,    70,    32,    72,   234,    35,    36,
      37,    19,    19,   234,    30,    57,    43,   234,   168,   234,
     232,   234,    38,    65,   234,    67,   234,   234,   234,   234,
     234,    39,    39,    60,   234,   234,   186,   234,   234,   109,
     234,   234,   234,   234,    71,   234,   232,    74,    75,   115,
     234,   234,   202,   234,   234,    82,   234,     4,   234,    67,
      67,    88,   223,    90,   234,    92,   132,    94,   234,    96,
      97,   232,   109,    20,    21,   234,   234,   234,   234,   234,
     107,   123,   234,   234,    31,   101,   113,   114,    15,   116,
     117,   118,   234,   101,   121,   234,   234,   234,   135,   136,
     137,   138,   139,   140,   141,   171,   172,   234,   234,   234,
     234,   119,   119,    40,   234,   234,   234,   234,   232,   146,
     127,   128,    69,    70,   234,    72,   234,   234,   234,   156,
     157,   158,   159,   160,   161,   162,   234,   234,   234,   234,
     147,   234,   234,   151,   152,   234,    73,   234,   234,   175,
     234,    98,   124,   124,   124,   231,   109,   223,   109,   106,
     212,   109,   231,   229,   109,     1,   109,   109,   109,   109,
       1,   231,     3,   234,     5,   102,   103,   234,   234,   234,
     234,   108,   129,   234,   131,   132,   213,   214,    19,   234,
     217,   218,    28,   234,    30,   203,     1,   212,   234,   226,
     234,   228,   149,   234,   234,   234,   133,   231,    39,   234,
     124,   234,  1220,   234,   234,   223,   223,   234,   231,   227,
     234,   148,    58,   234,   234,   172,    57,   109,    59,    34,
     177,   234,    68,   234,   181,   234,    67,   234,   185,    44,
      45,    46,   234,   190,    49,    50,   234,   194,    79,    54,
      55,    56,   234,    89,   234,   234,   234,    93,   205,   234,
     207,   208,   212,   210,   109,   101,   212,   109,   104,   105,
     101,   109,     1,   212,   221,     0,     1,    72,   212,     4,
     109,   109,   229,   109,   211,   109,   109,   109,    17,    18,
     109,    16,   123,    22,    19,   109,    21,   109,   134,    42,
     212,   234,   234,   230,    29,   212,    49,   212,    51,    52,
     212,   142,   212,   212,   150,   212,    41,   153,   154,   155,
     151,   212,    47,    48,   810,   811,   812,   813,   814,   815,
     816,   212,   109,   164,   212,   109,   231,   132,    67,   231,
      42,    66,   231,   124,   234,    70,   234,    49,   234,    51,
      52,   234,   124,   212,   234,    80,    85,    86,   234,   234,
     234,   234,    91,   234,   234,   201,    95,   234,   163,   231,
     201,   231,   101,   234,    99,   100,   234,   172,   231,   234,
      42,   110,   111,   112,   215,   234,   181,    49,   234,   124,
     115,   234,   212,   122,   234,   234,   212,   234,   231,   234,
     234,   124,   234,   212,   234,   212,   212,   132,   109,   124,
     205,   212,   207,   208,   143,    72,   231,   124,   109,   144,
     145,   109,   165,   166,   167,   124,   221,   170,   171,   124,
     173,   174,   124,   176,   229,   178,   234,   124,   181,   124,
     183,   184,   124,   124,   169,   124,   189,   124,   231,   231,
     193,   212,   231,   233,   197,   198,   199,   182,   231,   188,
     124,   204,   187,   165,   166,   167,   209,   192,   170,   171,
     195,   173,   174,   231,   176,   132,   178,   234,   234,   181,
     234,   183,   184,   234,   231,   234,   234,   189,   109,   231,
     231,   193,   231,   231,   231,   197,   198,   199,   231,   231,
       1,   231,   204,   165,   166,   167,   163,   209,   170,   171,
     231,   173,   174,   231,   176,   172,   178,   231,   231,   181,
     231,   183,   184,   231,   181,    26,    27,   189,   231,   109,
     234,   193,    33,   231,   231,   197,   198,   199,   109,   109,
     124,   109,   204,   109,   109,   109,   124,   209,   205,   124,
     207,   208,   212,   231,   234,   124,   109,   124,   231,   231,
      61,    62,    63,    64,   221,   124,   124,   124,   124,   124,
     124,   234,   229,   124,   124,    76,    77,    78,   231,   124,
     124,   231,    83,    84,    85,   231,    87,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     124,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   124,   212,   109,   124,   124,   124,   231,   124,
     124,   231,   124,   124,   109,   234,   231,   124,   231,   231,
     124,   124,   212,   234,   231,   124,   124,   124,   234,   231,
     212,   124,   124,   124,   124,   124,   124,   124,   231,   231,
     231,   124,   124,   124,   124,   124,   494,   265,    77,  1305,
     576,  1265,   231,   231,   231,   231,   285,   109,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   509,   231,   231,   234,
     231,   231,   234,   231,   231,   231,   231,   236,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     124,   231,   231,   231,   231,   231,   231,   231,   231,   130,
     231,   231,   132,   130,   132,   231,   130,   130,   231,  1267,
    1243,   231,   231,   231,  1037,   231,  1254,   481,  1138,   231,
     231,   231,   335,  1252,   458,   231,   525,   231,   589,  1276,
     562,   368,  1269,  1248,   118,   231,   231,   231,   219,   168,
      97,   471,   221,   231,   231,   231,   231,   231,    -1,   231,
     388,   231,   235,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   398,  1106,   231,   234,
     234,   231,   231,   231,   231,   231,   231,  1108,    -1,    -1,
      -1,    -1,   236,   236,   236,   236,   236,   234,   231,   231,
     231,   231,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   293
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    21,    29,    41,
      47,    48,    66,    70,    80,    99,   100,   115,   132,   144,
     145,   169,   182,   187,   192,   195,   239,   244,   249,   267,
     273,   279,   287,   301,   321,   343,   357,   372,   379,   383,
     393,   402,   424,   430,   436,   440,   446,   500,   517,   231,
     232,   233,   233,   322,   403,   431,   233,   441,   233,   358,
     425,   344,   233,   274,   302,   373,   233,   233,   394,   233,
     280,   233,   384,     1,    30,    38,   101,   268,   269,   270,
     271,   272,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    83,    84,    85,    87,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   233,   233,   233,     1,    65,   437,   438,
     439,   233,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    43,    60,    71,    74,    75,
      82,    88,    90,    92,    94,    96,    97,   107,   113,   114,
     116,   117,   118,   121,   146,   156,   157,   158,   159,   160,
     161,   162,   213,   214,   217,   218,   226,   228,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     492,   496,   497,   498,   499,   233,   233,   233,     1,    98,
     120,   245,   246,   247,   248,   233,   233,   233,     1,    34,
      44,    45,    46,    49,    50,    54,    55,    56,   518,   519,
     520,   521,   522,   523,   524,   525,   526,   527,   528,     1,
      28,    30,    58,    68,    89,    93,   101,   104,   105,   134,
     150,   153,   154,   155,   201,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   233,     1,   222,   288,   289,   290,   291,   292,
     233,     1,   101,   380,   381,   382,   233,   231,   234,   234,
     234,   232,   269,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   502,     1,
      17,    18,    22,    67,    85,    86,    91,    95,   101,   110,
     111,   112,   122,   143,   188,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,     1,     3,     5,    19,    39,    57,    59,    67,
      79,   101,   123,   142,   151,   164,   201,   215,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     419,   420,   421,   422,   423,     1,    65,   126,   432,   433,
     434,   435,   234,   232,   438,     1,   101,   126,   442,   443,
     444,   445,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   493,   489,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   448,     1,
      19,    39,    67,   119,   127,   128,   147,   223,   359,   360,
     361,   362,   363,   364,   365,   369,   370,   371,     1,   126,
     223,   426,   427,   428,   429,     1,    57,    65,    67,   123,
     345,   349,   350,   351,   355,   356,   231,   234,   234,   232,
     246,     1,    81,   175,   275,   276,   277,   278,     1,    19,
      39,    67,   101,   119,   151,   152,   203,   223,   227,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     317,     1,    41,    81,   126,   374,   375,   376,   377,   378,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   232,
     519,   231,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   251,     1,
     101,   220,   395,   396,   397,   398,   231,   234,   232,   289,
     175,     1,   101,   168,   186,   202,   281,   282,   283,   284,
     285,   286,   234,   232,   381,     1,   101,   220,   223,   385,
     386,   387,   388,   389,   124,   124,   124,   231,   109,   109,
     241,   212,   109,   241,   241,   241,   109,   241,   241,   109,
     109,   109,   109,   231,   231,   234,   234,   234,   340,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     232,   324,   231,   234,   234,   234,   234,   234,   234,   416,
     234,   234,   234,   234,   234,   234,   234,   234,   232,   405,
     234,   234,   232,   433,   124,   231,   234,   234,   232,   443,
     212,   241,   109,   241,   241,   212,   109,   241,   212,   109,
     109,   109,   212,   212,   241,   109,   109,   109,   109,   241,
     109,   109,   109,   109,   212,   234,   234,   212,   241,   241,
     212,   212,   212,   212,   216,   212,   216,   212,   212,   212,
     212,   109,   241,   241,   241,   212,   109,   231,   231,   234,
     234,   366,   234,   234,   234,   234,   234,   232,   360,   234,
     234,   232,   427,   231,   234,   234,   346,   234,   232,   350,
     124,   124,   231,   231,   234,   234,   232,   276,   231,   234,
     234,   318,   234,   234,   234,   234,   314,   234,   234,   232,
     304,   231,   234,   234,   234,   232,   375,   212,   212,   241,
     124,   212,   124,   212,   212,   212,   231,   109,   124,   212,
     124,   109,   109,   124,   124,   124,   124,   124,   124,   124,
     124,   124,   231,   231,   234,   399,   232,   396,   212,   231,
     233,   231,   234,   234,   234,   234,   232,   282,   124,   231,
     231,   234,   390,   234,   232,   386,   231,   231,   231,   231,
     135,   136,   137,   138,   139,   140,   141,   240,   241,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   109,   109,   241,   234,   109,   241,   109,   241,
     124,   109,   109,   109,   241,   109,   243,   243,   231,   124,
     179,   180,   124,   212,   124,   124,   234,   124,   124,   109,
     124,   124,   124,   124,   241,   231,   124,   124,   231,   231,
     124,   124,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,    42,    49,
     165,   166,   167,   170,   171,   173,   174,   176,   178,   181,
     183,   184,   189,   193,   197,   198,   199,   204,   209,   494,
     495,    42,    49,    51,    52,   165,   166,   167,   170,   171,
     173,   174,   176,   178,   181,   183,   184,   189,   193,   197,
     198,   199,   204,   209,   490,   491,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   124,   212,   234,   124,
     109,   124,   124,   124,   231,   124,   124,   231,   124,   124,
     234,   109,   353,   354,   231,   231,   231,   124,   124,   231,
     124,   212,   234,   124,   124,   124,   212,   234,   124,   124,
     231,   124,   124,   124,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   124,
     234,   231,   231,     1,   101,   196,   220,   293,   294,   295,
     296,   297,   124,   124,   124,   124,   231,   231,   124,   234,
     124,   231,   240,   240,   240,   240,   240,   240,   240,   231,
     231,   231,    53,   125,   341,   342,   231,   231,   231,   231,
     231,   231,   231,   231,   231,    11,    12,    13,   242,   243,
     231,   231,   231,   231,   231,   231,   231,   231,   231,     8,
     200,   417,   418,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   235,   231,   235,   231,
     231,    15,    40,    73,   102,   103,   108,   133,   148,   211,
     230,   367,   368,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    49,   191,   200,   347,   348,   219,   235,   352,
     231,   231,   231,   231,     4,    20,    21,    31,    69,    70,
      72,    98,   106,   129,   131,   132,   149,   172,   177,   181,
     185,   190,   194,   205,   207,   208,   210,   221,   229,   319,
     320,   231,   231,   231,   231,    42,    49,    51,    52,   165,
     166,   167,   170,   171,   173,   174,   176,   178,   181,   183,
     184,   189,   193,   197,   198,   199,   204,   209,   315,   316,
     231,   231,   231,   231,   231,   231,    72,   132,   163,   172,
     181,   205,   207,   208,   221,   229,   400,   401,   231,   234,
     234,   298,   232,   294,   231,   231,   231,   231,   231,    72,
     132,   163,   172,   181,   205,   207,   208,   221,   229,   391,
     392,   231,   231,   235,   242,   242,   242,   231,   235,   495,
     491,   231,   235,   231,   235,   109,   354,   231,   236,   236,
     236,   236,   236,   236,   231,   235,   231,   235,   231,   235,
     124,   206,   243,   234,   231,   231,   235,   342,   418,   368,
     348,   130,   132,   130,   132,   130,   130,   320,   316,   401,
     231,   231,   231,    70,    72,   115,   132,   171,   172,   223,
     229,   299,   300,   392,   231,   235,   300
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   237,   238,   238,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   243,   243,   244,   245,   245,   246,   246,   246,
     247,   248,   249,   250,   250,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   268,   269,
     269,   269,   269,   270,   271,   272,   274,   273,   275,   275,
     276,   276,   276,   277,   278,   280,   279,   281,   281,   282,
     282,   282,   282,   282,   283,   284,   285,   286,   287,   288,
     288,   289,   289,   289,   290,   292,   291,   293,   293,   294,
     294,   294,   294,   295,   296,   296,   298,   297,   299,   299,
     300,   300,   300,   300,   300,   300,   300,   300,   302,   301,
     303,   303,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   314,   313,   315,   315,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   318,   317,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   322,   321,   323,   323,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   340,   339,   341,   341,   342,
     342,   344,   343,   346,   345,   347,   347,   348,   348,   348,
     349,   349,   350,   350,   350,   350,   350,   352,   351,   353,
     353,   354,   354,   355,   356,   358,   357,   359,   359,   360,
     360,   360,   360,   360,   360,   360,   360,   360,   361,   362,
     363,   364,   366,   365,   367,   367,   368,   368,   368,   368,
     368,   368,   368,   368,   368,   368,   369,   370,   371,   373,
     372,   374,   374,   375,   375,   375,   375,   376,   377,   378,
     379,   380,   380,   381,   381,   382,   384,   383,   385,   385,
     386,   386,   386,   386,   387,   388,   390,   389,   391,   391,
     392,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     394,   393,   395,   395,   396,   396,   396,   397,   399,   398,
     400,   400,   401,   401,   401,   401,   401,   401,   401,   401,
     401,   401,   403,   402,   404,   404,   405,   405,   405,   405,
     405,   405,   405,   405,   405,   405,   405,   405,   405,   405,
     405,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   414,   416,   415,   417,   417,   418,   418,   419,   420,
     421,   422,   423,   425,   424,   426,   426,   427,   427,   427,
     428,   429,   431,   430,   432,   432,   433,   433,   433,   434,
     435,   436,   437,   437,   438,   438,   439,   441,   440,   442,
     442,   443,   443,   443,   444,   445,   446,   447,   447,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   448,   448,   448,   448,   448,
     448,   448,   448,   448,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   474,   475,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   489,   488,   490,   490,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   491,   491,   491,   491,   491,   491,   491,
     491,   491,   491,   493,   492,   494,   494,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   495,   495,   495,   496,   497,
     498,   499,   500,   501,   501,   502,   502,   502,   502,   502,
     502,   502,   502,   502,   502,   502,   502,   502,   502,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   518,   519,   519,   519,
     519,   519,   519,   519,   519,   519,   519,   520,   521,   522,
     523,   524,   525,   526,   527,   528
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
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     2,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     2,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     0,     6,     0,     5,     3,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     2,     0,     5,     3,
       1,     1,     3,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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

#define YYBACKUP(Token, Value)                                    \
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
            else
              goto append;

          append:
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
| yyreduce -- do a reduction.  |
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
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 408 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 409 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 415 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 418 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 419 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 420 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 421 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 422 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 435 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 441 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2949 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 472 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2961 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 481 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2973 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 490 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2985 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 499 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 2997 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 508 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3009 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 517 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 526 "conf_parser.y" /* yacc.c:1652  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.name == NULL)
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
#line 3039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 541 "conf_parser.y" /* yacc.c:1652  */
    {
  /* This isn't rehashable */
  if (conf_parser_ctx.pass == 2 && ConfigServerInfo.sid == NULL)
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
#line 3057 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 556 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3070 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 566 "conf_parser.y" /* yacc.c:1652  */
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
#line 3087 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 580 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3099 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 589 "conf_parser.y" /* yacc.c:1652  */
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
#line 3125 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 612 "conf_parser.y" /* yacc.c:1652  */
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
#line 3151 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 635 "conf_parser.y" /* yacc.c:1652  */
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
#line 3177 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 658 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3186 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 676 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3198 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 685 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3210 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 694 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3222 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 707 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3231 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 711 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3248 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 728 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3257 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 734 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3266 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 744 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3275 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 748 "conf_parser.y" /* yacc.c:1652  */
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
#line 3293 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 766 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3302 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 772 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3311 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 778 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3320 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 784 "conf_parser.y" /* yacc.c:1652  */
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
#line 3341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 124:
#line 812 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3350 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 125:
#line 818 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3359 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 822 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3372 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 133:
#line 838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3383 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 134:
#line 846 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3391 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 849 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3399 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 854 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3408 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 140:
#line 861 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3417 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 141:
#line 865 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3426 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 869 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3435 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 873 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3444 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 877 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3453 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 881 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3462 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 885 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3471 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 889 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3480 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 899 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3492 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 906 "conf_parser.y" /* yacc.c:1652  */
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

    struct MaskItem *conf = conf_make(CONF_OPER);
    conf->addr = xcalloc(sizeof(*conf->addr));
    conf->name = xstrdup(block_state.name.buf);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);
  }
}
#line 3551 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 163:
#line 975 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3560 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 164:
#line 981 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3569 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 987 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3578 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 993 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3587 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 999 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1010 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3610 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1016 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1027 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3633 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1033 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3642 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1040 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3651 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 176:
#line 1044 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3660 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1048 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3669 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1052 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3678 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1056 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3687 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1060 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3696 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1064 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3705 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1068 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3714 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1072 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3723 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1076 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3732 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1080 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3741 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1084 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3750 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1088 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3759 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1092 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3768 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1096 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3777 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1100 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3786 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1104 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3795 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1108 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3804 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1112 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3813 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1116 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3822 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1120 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3831 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1124 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3840 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1128 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3849 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1134 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3858 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1141 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1145 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3876 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1149 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1153 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3894 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1157 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1161 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3912 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1165 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3921 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1169 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3930 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1173 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3939 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1177 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1181 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3957 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1185 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3966 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1189 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3975 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1193 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3984 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1197 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 3993 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1201 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4002 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1205 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4011 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1209 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4020 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1213 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4029 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1217 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4038 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1221 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4047 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1225 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4056 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1229 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4065 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1233 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4074 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1237 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4083 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1241 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4092 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1245 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4101 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1249 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4110 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1253 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4119 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1263 "conf_parser.y" /* yacc.c:1652  */
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
#line 4136 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1275 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  struct ClassItem *class = class_find(block_state.class.buf, false);
  if (class == NULL)
    class = class_make();

  class->active = true;
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

  bool diff = (class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value ||
               class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value);
  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;

  if (diff)
    class_ip_limit_rebuild(class);
}
#line 4184 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 1338 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4193 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 1344 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4202 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1350 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4211 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1356 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4220 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1362 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4229 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1368 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4238 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1374 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4247 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1380 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4256 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1386 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4266 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1393 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4275 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1399 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1405 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4293 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1411 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1420 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1429 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4326 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 1436 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4335 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 1440 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4344 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1450 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4353 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1456 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4361 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 1462 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4370 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 1466 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4379 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1470 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4388 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 287:
#line 1478 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4394 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 1483 "conf_parser.y" /* yacc.c:1652  */
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
#line 4412 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 292:
#line 1496 "conf_parser.y" /* yacc.c:1652  */
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
#line 4432 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1513 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4441 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1519 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1529 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4459 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1533 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
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

    struct MaskItem *conf = conf_make(CONF_CLIENT);
    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

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
#line 4505 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 308:
#line 1587 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4514 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 309:
#line 1593 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4523 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1599 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4532 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1605 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4546 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1616 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4555 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 316:
#line 1623 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4564 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 317:
#line 1627 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4573 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1631 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4582 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1635 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4591 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1639 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4600 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1643 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4609 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1647 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4618 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1651 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4627 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1655 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4636 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1659 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4645 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1665 "conf_parser.y" /* yacc.c:1652  */
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
#line 4662 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1679 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4674 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1688 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4686 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1701 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4698 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1708 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4709 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 337:
#line 1719 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4718 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 338:
#line 1725 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4727 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1731 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4736 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 345:
#line 1746 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4751 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 346:
#line 1762 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4767 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1773 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4782 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 354:
#line 1788 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4791 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 355:
#line 1794 "conf_parser.y" /* yacc.c:1652  */
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
#line 4813 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1813 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4822 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 360:
#line 1820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4831 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 361:
#line 1824 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4840 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1828 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4849 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1832 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4858 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1836 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1840 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4876 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1844 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1848 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4894 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1852 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1856 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4912 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1866 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4926 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4939 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 377:
#line 1888 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 378:
#line 1894 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4957 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 382:
#line 1901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4966 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 383:
#line 1905 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4975 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1909 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4984 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1913 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 4993 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1917 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5002 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1921 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5011 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1925 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5020 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1929 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5029 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1933 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5038 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1937 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5047 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1947 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1957 "conf_parser.y" /* yacc.c:1652  */
    {
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (server_valid_name(block_state.name.buf) == false)
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  struct MaskItem *conf = conf_make(CONF_SERVER);
  conf->addr = xcalloc(sizeof(*conf->addr));
  conf->port = block_state.port.value;
  conf->timeout = block_state.timeout.value;
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
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server bind(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      conf->bind = xcalloc(sizeof(*conf->bind));

      memcpy(conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5133 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 412:
#line 2043 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5142 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 413:
#line 2049 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5151 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2055 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5160 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2061 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5169 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2067 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5185 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2080 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (*yylval.string == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr(yylval.string, ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5201 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2093 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5210 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2099 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5219 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2105 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5228 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2109 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2115 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 426:
#line 2121 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 427:
#line 2125 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2131 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5277 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2142 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5286 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2148 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5295 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2154 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5304 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2160 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5318 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5327 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  struct MaskItem *conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5350 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 440:
#line 2202 "conf_parser.y" /* yacc.c:1652  */
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
#line 5373 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 441:
#line 2222 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5382 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2232 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5391 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2236 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    struct MaskItem *conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5415 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 449:
#line 2260 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5424 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 450:
#line 2266 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5433 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 456:
#line 2281 "conf_parser.y" /* yacc.c:1652  */
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
#line 5450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 457:
#line 2298 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5459 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2302 "conf_parser.y" /* yacc.c:1652  */
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
#line 5479 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 464:
#line 2322 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5488 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 465:
#line 2328 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5497 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 515:
#line 2389 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5505 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 516:
#line 2394 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5513 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2399 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5521 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2404 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5529 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2409 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5537 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2414 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5545 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2419 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5553 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2424 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5561 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2429 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5569 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2434 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5577 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2439 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5585 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2444 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5593 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2449 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2454 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5609 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2459 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5617 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2464 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5625 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2469 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5633 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2474 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5641 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2479 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5649 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2484 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5657 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2489 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5665 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2494 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5673 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2499 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5681 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2504 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5689 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2509 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5697 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2514 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5705 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2517 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5713 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2522 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5721 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2525 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5729 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2530 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5737 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2535 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5745 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2540 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5753 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2545 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5761 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2550 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5769 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2555 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5777 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2560 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5785 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2565 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5793 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2570 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2575 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5809 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2580 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5817 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2585 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5825 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2590 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5833 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2596 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5841 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2599 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5849 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2602 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5857 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2605 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5865 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2608 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2611 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5881 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2614 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5889 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2617 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5897 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2620 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5905 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2623 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2626 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5921 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2629 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5929 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2632 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5937 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2635 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2638 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5953 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2641 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5961 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2644 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5969 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2647 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5977 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2650 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5985 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2653 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5993 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2656 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6001 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2659 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6009 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2667 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6025 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2673 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6033 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2676 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6041 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2679 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6049 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2682 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6057 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2685 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6065 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2688 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6073 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2691 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6081 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2694 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6089 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2697 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6097 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2700 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6105 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2703 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6113 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2706 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6121 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2709 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6129 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2712 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6137 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2715 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6145 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2718 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6153 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2721 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6161 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2724 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6169 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2727 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6177 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2730 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6185 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2733 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6193 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2738 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6201 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2743 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6209 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2748 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6217 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2753 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6225 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 630:
#line 2781 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6233 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2786 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6241 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2791 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6249 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2796 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6257 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2801 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6265 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2806 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6273 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2811 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2816 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6289 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2821 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6297 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2826 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2831 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6313 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2836 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6321 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2841 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6329 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2846 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6337 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 657:
#line 2869 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6346 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 658:
#line 2875 "conf_parser.y" /* yacc.c:1652  */
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
#line 6365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6377 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2900 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6386 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2906 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2912 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6404 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2918 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6416 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6425 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2933 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6434 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6438 "conf_parser.c" /* yacc.c:1652  */
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
