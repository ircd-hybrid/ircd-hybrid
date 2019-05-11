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


#line 183 "conf_parser.c" /* yacc.c:337  */
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
    WHOWAS_HISTORY_LENGTH = 482,
    XLINE = 483,
    XLINE_EXEMPT = 484
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
#define WHOWAS_HISTORY_LENGTH 482
#define XLINE 483
#define XLINE_EXEMPT 484

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:352  */

  int number;
  char *string;

#line 689 "conf_parser.c" /* yacc.c:352  */
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
#define YYLAST   1348

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  236
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  663
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1302

#define YYUNDEFTOK  2
#define YYMAXUTOK   484

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
       2,     2,     2,     2,   234,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   235,   230,
       2,   233,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,     2,   231,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   374,   374,   375,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   405,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   416,   416,
     417,   418,   419,   420,   427,   429,   429,   430,   430,   430,
     432,   438,   448,   450,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   469,   478,   487,   496,   505,   514,   523,   538,   553,
     563,   577,   586,   609,   632,   655,   665,   667,   667,   668,
     669,   670,   671,   673,   682,   691,   705,   704,   722,   722,
     723,   723,   723,   725,   731,   742,   741,   760,   760,   761,
     761,   761,   761,   761,   763,   769,   775,   781,   803,   804,
     804,   806,   806,   807,   809,   816,   816,   829,   830,   832,
     832,   833,   833,   835,   843,   846,   852,   851,   857,   857,
     858,   862,   866,   870,   874,   878,   882,   886,   897,   896,
     959,   959,   960,   961,   962,   963,   964,   965,   966,   967,
     968,   969,   970,   972,   978,   984,   990,   996,  1007,  1013,
    1024,  1031,  1030,  1036,  1036,  1037,  1041,  1045,  1049,  1053,
    1057,  1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,  1093,
    1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1132,  1131,
    1137,  1137,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,
    1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,  1206,
    1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,  1246,
    1250,  1261,  1260,  1317,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,
    1333,  1335,  1341,  1347,  1353,  1359,  1365,  1371,  1377,  1383,
    1390,  1396,  1402,  1408,  1417,  1427,  1426,  1432,  1432,  1433,
    1437,  1448,  1447,  1454,  1453,  1458,  1458,  1459,  1463,  1467,
    1473,  1473,  1474,  1474,  1474,  1474,  1474,  1476,  1476,  1478,
    1478,  1480,  1493,  1510,  1516,  1527,  1526,  1573,  1573,  1574,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1584,  1590,
    1596,  1602,  1614,  1613,  1619,  1619,  1620,  1624,  1628,  1632,
    1636,  1640,  1644,  1648,  1652,  1656,  1662,  1676,  1685,  1699,
    1698,  1713,  1713,  1714,  1714,  1714,  1714,  1716,  1722,  1728,
    1738,  1740,  1740,  1741,  1741,  1743,  1760,  1759,  1782,  1782,
    1783,  1783,  1783,  1783,  1785,  1791,  1811,  1810,  1816,  1816,
    1817,  1821,  1825,  1829,  1833,  1837,  1841,  1845,  1849,  1853,
    1864,  1863,  1882,  1882,  1883,  1883,  1883,  1885,  1892,  1891,
    1897,  1897,  1898,  1902,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1934,  1945,  1944,  2020,  2020,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,
    2035,  2037,  2043,  2049,  2055,  2068,  2081,  2087,  2093,  2097,
    2104,  2103,  2108,  2108,  2109,  2113,  2119,  2130,  2136,  2142,
    2148,  2164,  2163,  2187,  2187,  2188,  2188,  2188,  2190,  2210,
    2221,  2220,  2245,  2245,  2246,  2246,  2246,  2248,  2254,  2264,
    2266,  2266,  2267,  2267,  2269,  2287,  2286,  2307,  2307,  2308,
    2308,  2308,  2310,  2316,  2326,  2328,  2328,  2329,  2330,  2331,
    2332,  2333,  2334,  2335,  2336,  2337,  2338,  2339,  2340,  2341,
    2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2360,  2361,
    2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,
    2372,  2373,  2374,  2377,  2382,  2387,  2392,  2397,  2402,  2407,
    2412,  2417,  2422,  2427,  2432,  2437,  2442,  2447,  2452,  2457,
    2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2505,
    2510,  2513,  2518,  2523,  2528,  2533,  2538,  2543,  2548,  2553,
    2558,  2563,  2568,  2573,  2579,  2578,  2583,  2583,  2584,  2587,
    2590,  2593,  2596,  2599,  2602,  2605,  2608,  2611,  2614,  2617,
    2620,  2623,  2626,  2629,  2632,  2635,  2638,  2641,  2644,  2647,
    2650,  2656,  2655,  2660,  2660,  2661,  2664,  2667,  2670,  2673,
    2676,  2679,  2682,  2685,  2688,  2691,  2694,  2697,  2700,  2703,
    2706,  2709,  2712,  2715,  2718,  2721,  2726,  2731,  2736,  2741,
    2750,  2752,  2752,  2753,  2754,  2755,  2756,  2757,  2758,  2759,
    2760,  2761,  2762,  2763,  2764,  2765,  2766,  2767,  2769,  2774,
    2779,  2784,  2789,  2794,  2799,  2804,  2809,  2814,  2819,  2824,
    2829,  2834,  2843,  2845,  2845,  2846,  2847,  2848,  2849,  2850,
    2851,  2852,  2853,  2854,  2855,  2857,  2863,  2879,  2888,  2894,
    2900,  2906,  2915,  2921
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
  "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE",
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
  "connect_host", "connect_bind", "connect_send_password",
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
      59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -740

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-740)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -740,   634,  -740,  -140,  -211,  -205,  -740,  -740,  -740,  -197,
    -740,  -195,  -740,  -740,  -740,  -181,  -740,  -740,  -740,  -176,
    -144,  -740,  -125,  -740,  -111,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,    23,   911,   -99,   -88,   -83,    21,   -77,   401,   -70,
     -69,   -55,   183,   -50,   -38,   -17,   538,   506,    -5,    18,
      55,    17,    56,  -188,   -24,    64,    68,    51,  -740,  -740,
    -740,  -740,  -740,    69,    75,    78,    79,    84,    89,    92,
     102,   103,   106,   107,   109,   111,   112,   243,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   630,   566,    22,  -740,   121,    28,  -740,
    -740,    19,  -740,   123,   125,   127,   128,   129,   130,   131,
     135,   137,   139,   144,   146,   147,   158,   159,   160,   168,
     170,   172,   176,   179,   180,   181,   185,   186,  -740,  -740,
     187,   188,   189,   195,   197,   199,   201,   206,   207,   208,
     209,   210,   212,   218,   219,   220,   221,   223,    40,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   330,    15,   308,   148,   226,
     227,    11,  -740,  -740,  -740,    35,   328,   309,  -740,   229,
     230,   231,   234,   237,   238,   249,   251,   252,    24,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   166,
     253,   254,   255,   257,   259,   263,   266,   267,   268,   270,
     271,   272,   273,   276,   279,   145,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,    65,   283,   287,    47,  -740,  -740,  -740,   119,
       3,  -740,   288,    42,  -740,  -740,     7,  -740,   282,   399,
     400,   296,  -740,   246,   420,   318,   423,   420,   420,   420,
     424,   420,   420,   426,   428,   429,   431,   312,  -740,   313,
     311,   315,   316,  -740,   320,   322,   332,   333,   337,   342,
     343,   345,   346,   347,   358,   150,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   321,   363,   364,   365,   367,   369,   375,  -740,
     376,   379,   380,   387,   388,   389,   394,   173,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   397,   406,    54,  -740,  -740,  -740,
     422,   402,  -740,  -740,   409,   410,    59,  -740,  -740,  -740,
     417,   420,   532,   420,   420,   432,   537,   420,   437,   542,
     545,   548,   446,   450,   420,   555,   556,   557,   567,   420,
     568,   569,   570,   571,   473,   454,   455,   479,   420,   420,
     482,   483,   486,  -130,     9,   487,   489,   490,   491,   596,
     420,   420,   420,   494,   600,   480,  -740,   481,   485,   493,
    -740,   499,   510,   511,   514,   515,   224,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   517,   518,    61,
    -740,  -740,  -740,   492,   520,   521,  -740,   522,  -740,    27,
    -740,  -740,  -740,  -740,  -740,   588,   589,   509,  -740,   526,
     524,   525,    44,  -740,  -740,  -740,   529,   527,   528,  -740,
     530,   531,   541,   543,  -740,   544,   547,   247,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   535,
     549,   550,   554,    16,  -740,  -740,  -740,  -740,   507,   508,
     420,   599,   512,   638,   558,   576,   577,   551,  -740,  -740,
     681,   667,   581,   670,   687,   688,   671,   674,   675,   676,
     677,   678,   680,   685,   689,   575,  -740,   580,   590,  -740,
     122,  -740,  -740,  -740,  -740,   615,   598,  -740,   601,   602,
     604,   608,   610,   611,     2,  -740,  -740,  -740,  -740,  -740,
     707,   605,  -740,   616,   621,  -740,   622,    58,  -740,  -740,
    -740,  -740,   617,   618,   619,  -740,   628,   248,   631,   633,
     635,   636,   642,   643,   644,   646,   647,   648,   651,   652,
     656,  -740,  -740,   759,   762,   420,   654,   779,   420,   780,
     420,   770,   789,   792,   794,   420,   796,   796,   683,  -740,
    -740,   782,   -84,   784,   702,   793,   797,   693,   798,   803,
     807,   804,   808,   809,   810,   701,  -740,   812,   815,   710,
    -740,   711,  -740,   818,   819,   715,  -740,   716,   717,   718,
     719,   720,   721,   722,   724,   727,   728,   729,   730,   731,
     732,   733,   734,   735,   736,   737,   739,   740,   741,   747,
     749,   750,   726,   641,   751,   752,   753,   754,   755,   756,
     760,   761,   763,   767,   769,   771,   772,   773,   774,   775,
     776,   777,   778,   781,  -740,  -740,   854,   706,   783,   868,
     891,   885,   886,   888,   785,  -740,   889,   890,   787,  -740,
    -740,   894,   895,   788,   913,   790,  -740,   795,   799,  -740,
    -740,   899,   900,   800,  -740,  -740,   902,   816,   801,   903,
     907,   908,   821,   802,   912,   914,   811,  -740,  -740,   915,
     916,   918,   813,  -740,   814,   817,   820,   822,   823,   824,
     825,   826,   827,  -740,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,   842,  -740,
    -740,   921,   843,   844,  -740,   845,  -740,    12,  -740,   922,
     924,   925,   927,   847,  -740,   848,  -740,  -740,   949,   846,
     956,   851,  -740,  -740,  -740,  -740,  -740,   420,   420,   420,
     420,   420,   420,   420,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   852,
     853,   855,   -27,   856,   857,   858,   859,   860,   861,   862,
     863,   864,    20,   865,   866,  -740,   867,   869,   870,   871,
     872,   873,   874,     6,   875,   876,   877,   878,   879,   880,
     881,  -740,   882,   883,  -740,  -740,   884,   887,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -219,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -200,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   892,   893,   408,   896,   897,   898,   901,   904,
    -740,   905,   906,  -740,   909,   910,   -10,   919,   850,  -740,
    -740,  -740,  -740,   917,   920,  -740,   923,   926,   396,   928,
     929,   930,   931,   686,   932,   933,  -740,   934,   935,   936,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   937,   564,  -740,  -740,   938,
     939,   940,  -740,   163,  -740,  -740,  -740,  -740,   941,   944,
     945,   946,  -740,  -740,   947,   748,   948,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -190,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   796,   796,   796,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -163,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   726,  -740,   641,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -124,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     -65,  -740,   989,   913,   950,  -740,  -740,  -740,  -740,  -740,
    -740,   951,  -740,   952,   953,  -740,  -740,   954,   955,  -740,
    -740,   957,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   -51,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   -39,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   -23,  -740,  -740,   991,   -71,   958,   963,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   -16,  -740,  -740,  -740,   -27,  -740,
    -740,  -740,  -740,     6,  -740,  -740,  -740,   408,  -740,   -10,
    -740,  -740,  -740,   986,   987,   988,   992,   990,   995,  -740,
     396,  -740,   686,  -740,   564,   964,   965,   966,   614,  -740,
    -740,   748,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   -14,  -740,  -740,  -740,
     614,  -740
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   231,   392,   440,     0,
     455,     0,   295,   431,   271,     0,    96,   148,   329,     0,
       0,   370,     0,   105,     0,   346,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      91,    90,   627,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   612,   626,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   613,
     614,   624,   625,     0,     0,     0,   453,     0,     0,   451,
     452,     0,   512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,   554,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   466,
     467,   468,   510,   474,   511,   505,   506,   507,   508,   478,
     469,   470,   471,   472,   473,   475,   476,   477,   479,   480,
     509,   484,   485,   486,   487,   483,   482,   488,   495,   496,
     489,   490,   491,   481,   493,   503,   504,   501,   502,   494,
     492,   499,   500,   497,   498,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,     0,   654,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   644,
     645,   646,   647,   648,   649,   650,   652,   651,   653,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    54,    67,    65,    63,
      68,    69,    64,    55,    66,    57,    58,    59,    60,    61,
      62,    56,     0,     0,     0,     0,   120,   121,   122,     0,
       0,   344,     0,     0,   342,   343,     0,    92,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   238,   240,
     241,   242,   243,   244,   245,   246,   236,   237,   239,   247,
     248,   249,     0,     0,     0,     0,     0,     0,     0,   420,
       0,     0,     0,     0,     0,     0,     0,     0,   395,   396,
     397,   398,   399,   400,   401,   403,   402,   405,   409,   406,
     407,   408,   404,   446,     0,     0,     0,   443,   444,   445,
       0,     0,   450,   461,     0,     0,     0,   458,   459,   460,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   465,     0,     0,     0,
     312,     0,     0,     0,     0,     0,     0,   298,   299,   300,
     301,   306,   302,   303,   304,   305,   437,     0,     0,     0,
     434,   435,   436,     0,     0,     0,   273,     0,   283,     0,
     281,   282,   284,   285,    49,     0,     0,     0,    45,     0,
       0,     0,     0,    99,   100,   101,     0,     0,     0,   198,
       0,     0,     0,     0,   171,     0,     0,     0,   151,   152,
     153,   154,   155,   158,   159,   160,   157,   156,   161,     0,
       0,     0,     0,     0,   332,   333,   334,   335,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   643,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    53,     0,     0,   378,
       0,   373,   374,   375,   123,     0,     0,   119,     0,     0,
       0,     0,     0,     0,     0,   108,   109,   111,   110,   112,
       0,     0,   341,     0,     0,   356,     0,     0,   349,   350,
     351,   352,     0,     0,     0,    86,     0,    28,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     410,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   394,     0,     0,     0,
     442,     0,   449,     0,     0,     0,   457,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   464,   307,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   297,     0,     0,     0,   433,
     286,     0,     0,     0,     0,     0,   280,     0,     0,    44,
     102,     0,     0,     0,    98,   162,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   150,   336,     0,
       0,     0,     0,   331,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   642,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
     376,     0,     0,     0,   372,     0,   118,     0,   113,     0,
       0,     0,     0,     0,   107,     0,   340,   353,     0,     0,
       0,     0,   348,    95,    94,    93,   640,    28,    28,    28,
      28,    28,    28,    28,    30,    29,   641,   628,   629,   630,
     631,   632,   633,   634,   635,   638,   639,   636,   637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   393,     0,     0,   441,   454,     0,     0,   456,   524,
     528,   513,   514,   543,   517,   608,   609,   551,   518,   519,
     548,   523,   531,   522,   520,   521,   527,   526,   525,   549,
     515,   606,   607,   547,   605,   591,   585,   601,   586,   587,
     588,   596,   604,   589,   598,   602,   592,   603,   593,   597,
     590,   600,   595,   594,   599,     0,   584,   580,   563,   564,
     565,   558,   576,   559,   560,   561,   571,   579,   562,   573,
     577,   567,   578,   568,   572,   566,   575,   570,   569,   574,
       0,   557,   544,   542,   545,   550,   546,   533,   540,   541,
     538,   539,   534,   535,   536,   537,   552,   553,   530,   529,
     532,   516,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     0,     0,   432,     0,     0,     0,   291,   287,   290,
     272,    50,    51,     0,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,     0,     0,
     330,   658,   655,   656,   657,   662,   661,   663,   659,   660,
      82,    79,    85,    78,    83,    84,    77,    81,    80,    72,
      71,    76,    73,    75,    74,     0,     0,   371,   124,     0,
       0,     0,   136,     0,   128,   129,   131,   130,     0,     0,
       0,     0,   106,   345,     0,     0,     0,   347,    31,    32,
      33,    34,    35,    36,    37,   260,   261,   255,   270,   269,
       0,   268,   256,   264,   257,   263,   251,   262,   254,   253,
     252,    38,    38,    38,    40,    39,   258,   259,   415,   418,
     419,   429,   426,   412,   427,   424,   425,     0,   423,   428,
     411,   417,   414,   416,   413,   430,   447,   448,   462,   463,
     582,     0,   555,     0,   310,   311,   321,   317,   318,   320,
     325,   322,   323,   316,   324,   319,     0,   315,   309,   328,
     327,   326,   308,   439,   438,   294,   293,   278,   279,   277,
       0,   276,     0,     0,     0,   103,   104,   170,   167,   218,
     230,   205,   214,     0,   203,   208,   224,     0,   217,   222,
     228,   207,   210,   219,   221,   225,   215,   223,   211,   229,
     213,   220,   209,   212,     0,   201,   163,   165,   168,   169,
     197,   180,   181,   182,   175,   193,   176,   177,   178,   188,
     196,   179,   190,   194,   184,   195,   185,   189,   183,   192,
     187,   186,   191,     0,   174,   164,   166,   339,   337,   338,
     377,   382,   388,   391,   384,   390,   385,   389,   387,   383,
     386,     0,   381,   132,     0,     0,     0,     0,   127,   115,
     114,   116,   117,   354,   360,   366,   369,   362,   368,   363,
     367,   365,   361,   364,     0,   359,   355,   266,     0,    41,
      42,    43,   421,     0,   583,   556,   313,     0,   274,     0,
     292,   289,   288,     0,     0,     0,     0,     0,     0,   199,
       0,   172,     0,   379,     0,     0,     0,     0,     0,   126,
     357,     0,   267,   422,   314,   275,   204,   227,   202,   226,
     216,   206,   200,   173,   380,   133,   135,   134,   146,   145,
     141,   143,   147,   144,   140,   142,     0,   139,   358,   137,
       0,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -740,  -740,  -740,  -139,  -302,  -739,  -626,  -740,  -740,   960,
    -740,  -740,  -740,  -740,   942,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  1044,  -740,  -740,  -740,  -740,  -740,  -740,   637,
    -740,  -740,  -740,  -740,  -740,   463,  -740,  -740,  -740,  -740,
    -740,  -740,   943,  -740,  -740,  -740,  -740,    97,  -740,  -740,
    -740,  -740,  -740,  -168,  -740,  -740,  -740,   626,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -121,
    -740,  -740,  -740,  -122,  -740,  -740,  -740,   849,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   -96,  -740,  -740,  -740,  -740,
    -740,  -106,  -740,   665,  -740,  -740,  -740,    13,  -740,  -740,
    -740,  -740,  -740,   692,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -102,  -740,  -740,  -740,  -740,  -740,  -740,   629,  -740,
    -740,  -740,  -740,  -740,   959,  -740,  -740,  -740,  -740,   562,
    -740,  -740,  -740,  -740,  -740,  -120,  -740,  -740,  -740,   594,
    -740,  -740,  -740,  -740,  -109,  -740,  -740,  -740,   961,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     -86,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,   700,
    -740,  -740,  -740,  -740,  -740,   962,  -740,  -740,  -740,  -740,
    1052,  -740,  -740,  -740,  -740,   786,  -740,  -740,  -740,  -740,
    1011,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,    80,  -740,  -740,  -740,    96,  -740,  -740,
    -740,  -740,  -740,  -740,  1088,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   967,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   814,   815,  1074,  1075,    27,   221,   222,
     223,   224,    28,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
      29,    77,    78,    79,    80,    81,    30,    63,   492,   493,
     494,   495,    31,    70,   574,   575,   576,   577,   578,   579,
      32,   285,   286,   287,   288,   289,  1033,  1034,  1035,  1036,
    1037,  1216,  1296,  1297,    33,    64,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   743,  1193,  1194,
     518,   738,  1164,  1165,    34,    53,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   616,  1060,  1061,    35,    61,   478,   723,
    1130,  1131,   479,   480,   481,  1134,   978,   979,   482,   483,
      36,    59,   456,   457,   458,   459,   460,   461,   462,   708,
    1116,  1117,   463,   464,   465,    37,    65,   523,   524,   525,
     526,   527,    38,   293,   294,   295,    39,    72,   587,   588,
     589,   590,   591,   799,  1234,  1235,    40,    68,   560,   561,
     562,   563,   782,  1211,  1212,    41,    54,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   637,  1087,
    1088,   378,   379,   380,   381,   382,    42,    60,   469,   470,
     471,   472,    43,    55,   386,   387,   388,   389,    44,   118,
     119,   120,    45,    57,   396,   397,   398,   399,    46,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   426,   940,   941,   210,   425,   915,   916,   211,   212,
     213,   214,    47,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,    48,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     843,   844,   598,   569,   569,   601,   602,   603,   583,   605,
     606,  1100,   218,  1029,  1085,  1101,   466,   519,   291,   283,
     393,    51,   116,   383,    73,   228,  1058,    52,   473,   116,
    1102,  1071,  1072,  1073,  1103,    56,   489,    58,   842,  1127,
    1237,   122,   297,   291,  1238,   489,   123,   124,   283,   125,
     126,    62,    73,    74,   127,   383,    66,   520,   229,   583,
     393,    75,   466,   128,   129,   130,   557,  1242,   230,   231,
     232,  1243,   131,   233,   234,   132,   133,   134,   235,   236,
     237,    74,   690,   135,   474,   691,   117,   384,    67,    75,
      49,    50,   475,   117,   476,   847,   848,   521,  1059,   658,
     136,   660,   661,   570,   570,   664,  1246,    69,   584,   219,
    1247,   137,   671,  1030,   138,   139,   490,   676,   292,   384,
     394,    71,   140,   557,    76,   490,   685,   686,   141,   842,
     142,   220,   143,   113,   144,  1266,   145,   146,   699,   700,
     701,   467,   522,   292,   114,   395,   249,   147,   385,   115,
     477,   319,    76,   148,   149,   121,   150,   151,   152,   584,
     394,   153,   215,   216,  1029,  1248,   558,   320,   321,  1249,
     571,   571,   322,   250,   352,   251,   353,   217,   354,  1259,
     385,  1128,   225,  1260,   218,   395,   154,   467,   572,   572,
    1129,  1261,   355,  -125,   226,  1262,   155,   156,   157,   158,
     159,   160,   161,   252,   573,   573,  1086,  1263,  1031,   298,
     491,  1264,   356,   253,  1270,   227,  1299,   323,  1271,   491,
    1300,   692,  -125,   558,   693,   447,   585,   282,   756,   586,
     357,  1032,   358,   793,   254,   324,   325,   468,   255,   284,
     359,   326,   487,   448,    82,   327,   256,   752,   496,   257,
     258,   328,   360,   162,   163,   537,   164,   165,   725,   391,
     329,   330,   331,   449,  1030,   166,   497,   167,   284,    83,
      84,   445,   332,   581,   361,   733,    85,   585,   566,   259,
     586,   219,   301,   468,   559,   649,   498,   290,   296,   801,
     655,   450,   718,   333,   568,   260,   362,   299,   261,   262,
     263,   300,   303,   220,    86,    87,    88,    89,   304,   473,
     519,   305,   306,   831,   499,   363,   834,   307,   836,    90,
      91,    92,   308,   841,   364,   309,    93,    94,    95,   496,
      96,   447,  1239,  1240,  1241,   310,   311,   365,   334,   312,
     313,   559,   314,   451,   315,   316,   264,   497,   500,   448,
     520,   452,   453,   783,   390,   596,   400,   597,   401,  1031,
     402,   403,   404,   405,   406,   474,   501,   498,   407,   449,
     408,   454,   409,   475,   366,   476,   555,   410,   484,   411,
     412,   628,  1032,   807,   808,   809,   810,   811,   812,   813,
     521,   413,   414,   415,  1217,   499,   539,   450,   502,   503,
    1139,   416,   122,   417,   645,   418,   592,   123,   124,   419,
     125,   126,   420,   421,   422,   127,  1140,  1141,   423,   424,
     427,   428,   429,  1106,   128,   129,   130,  1142,   430,   500,
     431,   477,   432,   131,   433,   522,   132,   133,   134,   434,
     435,   436,   437,   438,   135,   439,   455,   501,  1107,   451,
     504,   440,   441,   442,   443,   714,   444,   452,   453,   485,
     486,   136,   528,   529,   530,  1143,  1144,   531,  1145,   505,
     532,   533,   137,   506,   317,   138,   139,   454,   746,   502,
     503,  1108,   534,   140,   535,   536,   540,   541,   542,   141,
     543,   142,   544,   143,  1146,   144,   545,   145,   146,   546,
     547,   548,  1147,   549,   550,   551,   552,   249,   147,   553,
    1109,  1110,   554,   564,   148,   149,  1111,   150,   151,   152,
     565,   580,   153,   593,   594,  1148,   595,  1149,  1150,   597,
     599,   504,   600,   604,   250,   607,   251,   608,   609,   228,
     610,  1112,   611,   612,   613,  1151,   651,   154,   614,   615,
     505,   630,   455,   617,   506,   618,  1113,   155,   156,   157,
     158,   159,   160,   161,   252,   619,   620,   352,  1152,   353,
     621,   354,   229,  1153,   253,   622,   623,  1154,   624,   625,
     626,  1155,   230,   231,   232,   355,  1156,   233,   234,  1267,
    1157,   627,   235,   236,   237,   254,   631,   632,   633,   255,
     634,  1158,   635,  1159,  1160,   356,  1161,   256,   636,   638,
     257,   258,   639,   640,   162,   163,  1162,   164,   165,  1114,
     641,   642,   643,   357,  1163,   358,   166,   644,   167,   657,
     647,   319,   652,   359,     2,     3,  1201,  1115,     4,   648,
     259,   659,   653,   654,   662,   360,   663,   320,   321,   665,
       5,   666,   322,     6,   667,     7,   260,   668,   669,   261,
     262,   263,   670,     8,   672,   673,   674,   361,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,     9,   675,   677,   678,   679,
     680,    10,    11,   917,  1288,   681,  1289,   682,   683,   362,
     918,   684,   919,   920,   687,   688,  1202,   323,   689,   694,
      12,   695,   696,   697,    13,   698,   702,   264,   363,   703,
     704,   705,   727,   728,    14,   324,   325,   364,   706,   754,
     755,   326,   720,   757,   758,   327,   707,  1203,  1170,  1290,
     365,   328,   709,    15,    16,  1171,  1204,  1172,  1173,   729,
     329,   330,   331,   710,   711,  1205,  1291,   712,   713,    17,
     716,   717,   332,   721,   722,   724,   730,   731,   732,   735,
     736,   737,   759,   739,   740,   748,    18,   366,   894,  1206,
     760,  1207,  1208,   333,   741,   895,   742,   744,    19,    20,
     745,   763,   749,   750,  1209,  1292,  1293,   751,   761,   762,
     764,   765,  1210,   766,   767,   770,   768,   769,   771,   772,
     773,   774,   775,    21,   776,   779,   921,   922,   923,   777,
     780,   924,   925,   778,   926,   927,    22,   928,   334,   929,
    1224,    23,   930,   781,   931,   932,    24,   785,   786,    25,
     933,   795,   788,   787,   934,   796,  1294,   789,   935,   936,
     937,   790,  1295,   791,   792,   938,   797,   803,   804,   805,
     939,  1174,  1175,  1176,   798,   800,  1177,  1178,   806,  1179,
    1180,   816,  1181,   817,  1182,   818,   819,  1183,   829,  1184,
    1185,   830,   820,   821,   822,  1186,   823,   824,   825,  1187,
    1225,   826,   827,  1188,  1189,  1190,   828,   832,   833,   835,
    1191,   896,   897,   898,   837,  1192,   899,   900,   838,   901,
     902,   839,   903,   840,   904,   842,   846,   905,   849,   906,
     907,  1226,    82,   845,   850,   908,   856,   851,   963,   909,
    1227,   852,   854,   910,   911,   912,   853,   855,   857,  1228,
     913,   861,   858,   859,   860,   914,   862,    83,    84,   863,
     864,   865,   866,   867,    85,   868,   869,   870,   871,   872,
     873,   874,   875,  1229,   876,  1230,  1231,   877,   878,   879,
     880,   881,   882,   883,   884,   885,   886,   887,  1232,   888,
     889,   890,    86,    87,    88,    89,  1233,   891,   962,   892,
     893,   942,   943,   944,   945,   946,   947,    90,    91,    92,
     948,   949,   965,   950,    93,    94,    95,   951,    96,   952,
     966,   953,   954,   955,   956,   957,   958,   959,   960,   967,
     968,   961,   969,   971,   972,   970,   964,   973,   974,   975,
     980,   976,   977,   983,   984,   981,   986,   989,   987,   982,
     985,   990,   991,   992,   988,   993,   994,   794,   995,   997,
     998,   996,   999,  1000,  1001,  1025,  1038,  1002,  1039,  1040,
    1003,  1041,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1044,  1027,  1028,  1026,  1042,  1043,  1045,
    1046,  1047,  1055,  1056,  1133,  1057,  1062,  1063,  1064,  1065,
    1066,  1067,  1068,  1069,  1070,  1076,  1077,  1078,  1250,  1079,
    1080,  1081,  1082,  1083,  1084,  1089,  1090,  1091,  1092,  1093,
    1094,  1095,  1096,  1097,  1098,  1265,  1276,  1099,  1278,  1277,
    1280,   302,  1104,  1105,  1279,  1281,  1118,  1119,  1120,   734,
    1218,  1121,  1301,   747,  1122,  1123,  1124,  1132,  1282,  1125,
    1126,  1283,  1272,  1275,   726,  1274,  1251,  1135,   715,   802,
    1136,  1298,   753,  1137,   784,  1284,  1138,  1273,  1166,  1167,
    1168,  1169,  1195,  1196,  1197,  1198,  1199,  1200,  1213,   719,
     392,  1219,  1214,  1215,  1220,  1221,  1222,  1223,  1236,   446,
    1252,   488,   656,  1245,   629,   318,  1253,  1254,  1255,  1256,
    1257,  1268,  1258,  1269,  1285,  1286,  1287,  1244,     0,     0,
       0,     0,     0,     0,     0,   538,     0,   556,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   567,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   582,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   646,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   650
};

static const yytype_int16 yycheck[] =
{
     626,   627,   304,     1,     1,   307,   308,   309,     1,   311,
     312,   230,     1,     1,     8,   234,     1,     1,     1,     1,
       1,   232,     1,     1,     1,     1,    53,   232,     1,     1,
     230,    11,    12,    13,   234,   232,     1,   232,   109,    49,
     230,     1,   230,     1,   234,     1,     6,     7,     1,     9,
      10,   232,     1,    30,    14,     1,   232,    41,    34,     1,
       1,    38,     1,    23,    24,    25,     1,   230,    44,    45,
      46,   234,    32,    49,    50,    35,    36,    37,    54,    55,
      56,    30,   212,    43,    57,   215,    65,    65,   232,    38,
     230,   231,    65,    65,    67,   179,   180,    81,   125,   401,
      60,   403,   404,   101,   101,   407,   230,   232,   101,    98,
     234,    71,   414,   101,    74,    75,    81,   419,   101,    65,
     101,   232,    82,     1,   101,    81,   428,   429,    88,   109,
      90,   120,    92,   232,    94,   206,    96,    97,   440,   441,
     442,   126,   126,   101,   232,   126,     1,   107,   126,   232,
     123,     1,   101,   113,   114,   232,   116,   117,   118,   101,
     101,   121,   232,   232,     1,   230,   101,    17,    18,   234,
     168,   168,    22,    28,     1,    30,     3,   232,     5,   230,
     126,   191,   232,   234,     1,   126,   146,   126,   186,   186,
     200,   230,    19,   175,   232,   234,   156,   157,   158,   159,
     160,   161,   162,    58,   202,   202,   200,   230,   196,   233,
     175,   234,    39,    68,   230,   232,   230,    67,   234,   175,
     234,   212,   175,   101,   215,     1,   219,   232,   530,   222,
      57,   219,    59,   231,    89,    85,    86,   222,    93,   221,
      67,    91,   231,    19,     1,    95,   101,   231,     1,   104,
     105,   101,    79,   213,   214,   231,   216,   217,   231,   231,
     110,   111,   112,    39,   101,   225,    19,   227,   221,    26,
      27,   231,   122,   231,   101,   231,    33,   219,   231,   134,
     222,    98,   231,   222,   219,   231,    39,   232,   232,   231,
     231,    67,   231,   143,   175,   150,   123,   233,   153,   154,
     155,   233,   233,   120,    61,    62,    63,    64,   233,     1,
       1,   233,   233,   615,    67,   142,   618,   233,   620,    76,
      77,    78,   233,   625,   151,   233,    83,    84,    85,     1,
      87,     1,  1071,  1072,  1073,   233,   233,   164,   188,   233,
     233,   219,   233,   119,   233,   233,   201,    19,   101,    19,
      41,   127,   128,   231,   233,   109,   233,   109,   233,   196,
     233,   233,   233,   233,   233,    57,   119,    39,   233,    39,
     233,   147,   233,    65,   201,    67,   231,   233,   230,   233,
     233,   231,   219,   135,   136,   137,   138,   139,   140,   141,
      81,   233,   233,   233,   231,    67,   230,    67,   151,   152,
       4,   233,     1,   233,   231,   233,   124,     6,     7,   233,
       9,    10,   233,   233,   233,    14,    20,    21,   233,   233,
     233,   233,   233,    15,    23,    24,    25,    31,   233,   101,
     233,   123,   233,    32,   233,   126,    35,    36,    37,   233,
     233,   233,   233,   233,    43,   233,   222,   119,    40,   119,
     203,   233,   233,   233,   233,   231,   233,   127,   128,   233,
     233,    60,   233,   233,   233,    69,    70,   233,    72,   222,
     233,   233,    71,   226,   231,    74,    75,   147,   231,   151,
     152,    73,   233,    82,   233,   233,   233,   233,   233,    88,
     233,    90,   233,    92,    98,    94,   233,    96,    97,   233,
     233,   233,   106,   233,   233,   233,   233,     1,   107,   233,
     102,   103,   233,   230,   113,   114,   108,   116,   117,   118,
     233,   233,   121,   124,   124,   129,   230,   131,   132,   109,
     212,   203,   109,   109,    28,   109,    30,   109,   109,     1,
     109,   133,   230,   230,   233,   149,   124,   146,   233,   233,
     222,   230,   222,   233,   226,   233,   148,   156,   157,   158,
     159,   160,   161,   162,    58,   233,   233,     1,   172,     3,
     233,     5,    34,   177,    68,   233,   233,   181,   233,   233,
     233,   185,    44,    45,    46,    19,   190,    49,    50,  1215,
     194,   233,    54,    55,    56,    89,   233,   233,   233,    93,
     233,   205,   233,   207,   208,    39,   210,   101,   233,   233,
     104,   105,   233,   233,   213,   214,   220,   216,   217,   211,
     233,   233,   233,    57,   228,    59,   225,   233,   227,   212,
     233,     1,   230,    67,     0,     1,    72,   229,     4,   233,
     134,   109,   233,   233,   212,    79,   109,    17,    18,   212,
      16,   109,    22,    19,   109,    21,   150,   109,   212,   153,
     154,   155,   212,    29,   109,   109,   109,   101,   807,   808,
     809,   810,   811,   812,   813,    41,   109,   109,   109,   109,
     109,    47,    48,    42,    70,   212,    72,   233,   233,   123,
      49,   212,    51,    52,   212,   212,   132,    67,   212,   212,
      66,   212,   212,   212,    70,   109,   212,   201,   142,   109,
     230,   230,   124,   124,    80,    85,    86,   151,   233,   212,
     212,    91,   230,   124,   212,    95,   233,   163,    42,   115,
     164,   101,   233,    99,   100,    49,   172,    51,    52,   230,
     110,   111,   112,   233,   233,   181,   132,   233,   233,   115,
     233,   233,   122,   233,   233,   233,   230,   233,   233,   230,
     233,   233,   124,   233,   233,   230,   132,   201,    42,   205,
     212,   207,   208,   143,   233,    49,   233,   233,   144,   145,
     233,   230,   233,   233,   220,   171,   172,   233,   212,   212,
     109,   124,   228,   212,   124,   124,   109,   109,   124,   124,
     124,   124,   124,   169,   124,   230,   165,   166,   167,   124,
     230,   170,   171,   124,   173,   174,   182,   176,   188,   178,
      72,   187,   181,   233,   183,   184,   192,   212,   230,   195,
     189,   124,   230,   232,   193,   230,   222,   233,   197,   198,
     199,   233,   228,   233,   233,   204,   230,   230,   230,   230,
     209,   165,   166,   167,   233,   233,   170,   171,   230,   173,
     174,   230,   176,   230,   178,   230,   230,   181,   109,   183,
     184,   109,   230,   230,   230,   189,   230,   230,   230,   193,
     132,   230,   230,   197,   198,   199,   230,   233,   109,   109,
     204,   165,   166,   167,   124,   209,   170,   171,   109,   173,
     174,   109,   176,   109,   178,   109,   124,   181,   124,   183,
     184,   163,     1,   230,   212,   189,   109,   124,   212,   193,
     172,   124,   124,   197,   198,   199,   233,   124,   124,   181,
     204,   230,   124,   124,   124,   209,   124,    26,    27,   124,
     230,   230,   124,   124,    33,   230,   230,   230,   230,   230,
     230,   230,   230,   205,   230,   207,   208,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   220,   230,
     230,   230,    61,    62,    63,    64,   228,   230,   124,   230,
     230,   230,   230,   230,   230,   230,   230,    76,    77,    78,
     230,   230,   124,   230,    83,    84,    85,   230,    87,   230,
     109,   230,   230,   230,   230,   230,   230,   230,   230,   124,
     124,   230,   124,   124,   124,   230,   233,   230,   124,   124,
     230,   233,   109,   124,   124,   230,   124,   124,   212,   230,
     230,   124,   124,   212,   233,   233,   124,   574,   124,   124,
     124,   230,   124,   230,   230,   124,   124,   230,   124,   124,
     230,   124,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   124,   230,   230,   233,   230,   230,   233,
     124,   230,   230,   230,   234,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   109,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   124,   130,   230,   130,   132,
     130,    77,   230,   230,   132,   130,   230,   230,   230,   492,
    1033,   230,  1300,   507,   230,   230,   230,   218,  1260,   230,
     230,  1262,  1238,  1249,   479,  1247,  1133,   230,   456,   587,
     230,  1271,   523,   230,   560,  1264,   230,  1243,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   469,
     118,   230,   233,   233,   230,   230,   230,   230,   230,   168,
     230,   221,   396,  1103,   335,    97,   235,   235,   235,   235,
     235,   233,   235,   230,   230,   230,   230,  1101,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,   265,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   285,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   367,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   386
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   237,     0,     1,     4,    16,    19,    21,    29,    41,
      47,    48,    66,    70,    80,    99,   100,   115,   132,   144,
     145,   169,   182,   187,   192,   195,   238,   243,   248,   266,
     272,   278,   286,   300,   320,   342,   356,   371,   378,   382,
     392,   401,   422,   428,   434,   438,   444,   498,   515,   230,
     231,   232,   232,   321,   402,   429,   232,   439,   232,   357,
     423,   343,   232,   273,   301,   372,   232,   232,   393,   232,
     279,   232,   383,     1,    30,    38,   101,   267,   268,   269,
     270,   271,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    83,    84,    85,    87,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   232,   232,   232,     1,    65,   435,   436,
     437,   232,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    43,    60,    71,    74,    75,
      82,    88,    90,    92,    94,    96,    97,   107,   113,   114,
     116,   117,   118,   121,   146,   156,   157,   158,   159,   160,
     161,   162,   213,   214,   216,   217,   225,   227,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     490,   494,   495,   496,   497,   232,   232,   232,     1,    98,
     120,   244,   245,   246,   247,   232,   232,   232,     1,    34,
      44,    45,    46,    49,    50,    54,    55,    56,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,     1,
      28,    30,    58,    68,    89,    93,   101,   104,   105,   134,
     150,   153,   154,   155,   201,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   232,     1,   221,   287,   288,   289,   290,   291,
     232,     1,   101,   379,   380,   381,   232,   230,   233,   233,
     233,   231,   268,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   231,   500,     1,
      17,    18,    22,    67,    85,    86,    91,    95,   101,   110,
     111,   112,   122,   143,   188,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     337,   338,     1,     3,     5,    19,    39,    57,    59,    67,
      79,   101,   123,   142,   151,   164,   201,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   417,   418,
     419,   420,   421,     1,    65,   126,   430,   431,   432,   433,
     233,   231,   436,     1,   101,   126,   440,   441,   442,   443,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   491,   487,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   231,   446,     1,    19,    39,
      67,   119,   127,   128,   147,   222,   358,   359,   360,   361,
     362,   363,   364,   368,   369,   370,     1,   126,   222,   424,
     425,   426,   427,     1,    57,    65,    67,   123,   344,   348,
     349,   350,   354,   355,   230,   233,   233,   231,   245,     1,
      81,   175,   274,   275,   276,   277,     1,    19,    39,    67,
     101,   119,   151,   152,   203,   222,   226,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   316,     1,
      41,    81,   126,   373,   374,   375,   376,   377,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   231,   517,   230,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   231,   250,     1,   101,   219,
     394,   395,   396,   397,   230,   233,   231,   288,   175,     1,
     101,   168,   186,   202,   280,   281,   282,   283,   284,   285,
     233,   231,   380,     1,   101,   219,   222,   384,   385,   386,
     387,   388,   124,   124,   124,   230,   109,   109,   240,   212,
     109,   240,   240,   240,   109,   240,   240,   109,   109,   109,
     109,   230,   230,   233,   233,   233,   339,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   231,   323,
     230,   233,   233,   233,   233,   233,   233,   414,   233,   233,
     233,   233,   233,   233,   233,   231,   404,   233,   233,   231,
     431,   124,   230,   233,   233,   231,   441,   212,   240,   109,
     240,   240,   212,   109,   240,   212,   109,   109,   109,   212,
     212,   240,   109,   109,   109,   109,   240,   109,   109,   109,
     109,   212,   233,   233,   212,   240,   240,   212,   212,   212,
     212,   215,   212,   215,   212,   212,   212,   212,   109,   240,
     240,   240,   212,   109,   230,   230,   233,   233,   365,   233,
     233,   233,   233,   233,   231,   359,   233,   233,   231,   425,
     230,   233,   233,   345,   233,   231,   349,   124,   124,   230,
     230,   233,   233,   231,   275,   230,   233,   233,   317,   233,
     233,   233,   233,   313,   233,   233,   231,   303,   230,   233,
     233,   233,   231,   374,   212,   212,   240,   124,   212,   124,
     212,   212,   212,   230,   109,   124,   212,   124,   109,   109,
     124,   124,   124,   124,   124,   124,   124,   124,   124,   230,
     230,   233,   398,   231,   395,   212,   230,   232,   230,   233,
     233,   233,   233,   231,   281,   124,   230,   230,   233,   389,
     233,   231,   385,   230,   230,   230,   230,   135,   136,   137,
     138,   139,   140,   141,   239,   240,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   109,
     109,   240,   233,   109,   240,   109,   240,   124,   109,   109,
     109,   240,   109,   242,   242,   230,   124,   179,   180,   124,
     212,   124,   124,   233,   124,   124,   109,   124,   124,   124,
     124,   230,   124,   124,   230,   230,   124,   124,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,    42,    49,   165,   166,   167,   170,
     171,   173,   174,   176,   178,   181,   183,   184,   189,   193,
     197,   198,   199,   204,   209,   492,   493,    42,    49,    51,
      52,   165,   166,   167,   170,   171,   173,   174,   176,   178,
     181,   183,   184,   189,   193,   197,   198,   199,   204,   209,
     488,   489,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   124,   212,   233,   124,   109,   124,   124,   124,
     230,   124,   124,   230,   124,   124,   233,   109,   352,   353,
     230,   230,   230,   124,   124,   230,   124,   212,   233,   124,
     124,   124,   212,   233,   124,   124,   230,   124,   124,   124,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   124,   233,   230,   230,     1,
     101,   196,   219,   292,   293,   294,   295,   296,   124,   124,
     124,   124,   230,   230,   124,   233,   124,   230,   239,   239,
     239,   239,   239,   239,   239,   230,   230,   230,    53,   125,
     340,   341,   230,   230,   230,   230,   230,   230,   230,   230,
     230,    11,    12,    13,   241,   242,   230,   230,   230,   230,
     230,   230,   230,   230,   230,     8,   200,   415,   416,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   234,   230,   234,   230,   230,    15,    40,    73,   102,
     103,   108,   133,   148,   211,   229,   366,   367,   230,   230,
     230,   230,   230,   230,   230,   230,   230,    49,   191,   200,
     346,   347,   218,   234,   351,   230,   230,   230,   230,     4,
      20,    21,    31,    69,    70,    72,    98,   106,   129,   131,
     132,   149,   172,   177,   181,   185,   190,   194,   205,   207,
     208,   210,   220,   228,   318,   319,   230,   230,   230,   230,
      42,    49,    51,    52,   165,   166,   167,   170,   171,   173,
     174,   176,   178,   181,   183,   184,   189,   193,   197,   198,
     199,   204,   209,   314,   315,   230,   230,   230,   230,   230,
     230,    72,   132,   163,   172,   181,   205,   207,   208,   220,
     228,   399,   400,   230,   233,   233,   297,   231,   293,   230,
     230,   230,   230,   230,    72,   132,   163,   172,   181,   205,
     207,   208,   220,   228,   390,   391,   230,   230,   234,   241,
     241,   241,   230,   234,   493,   489,   230,   234,   230,   234,
     109,   353,   230,   235,   235,   235,   235,   235,   235,   230,
     234,   230,   234,   230,   234,   124,   206,   242,   233,   230,
     230,   234,   341,   416,   367,   347,   130,   132,   130,   132,
     130,   130,   319,   315,   400,   230,   230,   230,    70,    72,
     115,   132,   171,   172,   222,   228,   298,   299,   391,   230,
     234,   299
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   236,   237,   237,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   238,   239,   239,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   243,   244,   244,   245,   245,   245,
     246,   247,   248,   249,   249,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   267,   268,
     268,   268,   268,   269,   270,   271,   273,   272,   274,   274,
     275,   275,   275,   276,   277,   279,   278,   280,   280,   281,
     281,   281,   281,   281,   282,   283,   284,   285,   286,   287,
     287,   288,   288,   288,   289,   291,   290,   292,   292,   293,
     293,   293,   293,   294,   295,   295,   297,   296,   298,   298,
     299,   299,   299,   299,   299,   299,   299,   299,   301,   300,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   313,   312,   314,   314,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   317,   316,
     318,   318,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   321,   320,   322,   322,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   339,   338,   340,   340,   341,
     341,   343,   342,   345,   344,   346,   346,   347,   347,   347,
     348,   348,   349,   349,   349,   349,   349,   351,   350,   352,
     352,   353,   353,   354,   355,   357,   356,   358,   358,   359,
     359,   359,   359,   359,   359,   359,   359,   359,   360,   361,
     362,   363,   365,   364,   366,   366,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   368,   369,   370,   372,
     371,   373,   373,   374,   374,   374,   374,   375,   376,   377,
     378,   379,   379,   380,   380,   381,   383,   382,   384,   384,
     385,   385,   385,   385,   386,   387,   389,   388,   390,   390,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     393,   392,   394,   394,   395,   395,   395,   396,   398,   397,
     399,   399,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   402,   401,   403,   403,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   412,
     414,   413,   415,   415,   416,   416,   417,   418,   419,   420,
     421,   423,   422,   424,   424,   425,   425,   425,   426,   427,
     429,   428,   430,   430,   431,   431,   431,   432,   433,   434,
     435,   435,   436,   436,   437,   439,   438,   440,   440,   441,
     441,   441,   442,   443,   444,   445,   445,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   472,
     473,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   487,   486,   488,   488,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   491,   490,   492,   492,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   494,   495,   496,   497,
     498,   499,   499,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   516,   517,   517,   517,   517,   517,
     517,   517,   517,   517,   517,   518,   519,   520,   521,   522,
     523,   524,   525,   526
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
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
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
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2874 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2880 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 408 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 409 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2904 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 416 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2922 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 417 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 418 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2934 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 419 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 420 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2946 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 433 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2955 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 439 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2964 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 71:
#line 470 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2976 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 479 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2988 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 488 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3000 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 497 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 506 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3024 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 515 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3036 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 524 "conf_parser.y" /* yacc.c:1652  */
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
#line 3054 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 539 "conf_parser.y" /* yacc.c:1652  */
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
#line 3072 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 554 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3085 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 564 "conf_parser.y" /* yacc.c:1652  */
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
#line 3102 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 578 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3114 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 587 "conf_parser.y" /* yacc.c:1652  */
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
#line 3140 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 610 "conf_parser.y" /* yacc.c:1652  */
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
#line 3166 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 633 "conf_parser.y" /* yacc.c:1652  */
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
#line 3192 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 656 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3201 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 674 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3213 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 683 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3225 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 692 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 705 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3246 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 709 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 726 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3272 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 732 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 742 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3290 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 746 "conf_parser.y" /* yacc.c:1652  */
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
#line 3308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 764 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 770 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3326 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 776 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3335 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 782 "conf_parser.y" /* yacc.c:1652  */
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
#line 3356 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 124:
#line 810 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 125:
#line 816 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3374 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3387 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 133:
#line 836 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3398 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 134:
#line 844 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3406 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 847 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3414 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 852 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3423 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 140:
#line 859 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3432 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 141:
#line 863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3441 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3459 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3468 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 879 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3477 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 883 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3486 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 887 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3495 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3507 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 904 "conf_parser.y" /* yacc.c:1652  */
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
#line 3566 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 163:
#line 973 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 164:
#line 979 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3584 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 985 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3593 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 991 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3602 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 997 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3616 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1008 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3625 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1014 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3639 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1025 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3648 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1031 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3657 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1038 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3666 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 176:
#line 1042 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3675 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1054 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3702 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3711 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3720 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1066 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3729 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1070 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3738 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1074 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1078 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3765 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1086 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3774 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3783 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3792 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1126 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1132 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1139 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1147 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1159 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1163 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3936 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1167 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1183 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1187 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1191 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1195 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1199 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1203 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1207 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1215 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1227 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4080 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1231 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4089 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4098 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1239 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4107 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1243 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4116 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1247 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4125 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1251 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4134 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1261 "conf_parser.y" /* yacc.c:1652  */
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
#line 4151 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1273 "conf_parser.y" /* yacc.c:1652  */
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
#line 4199 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 1336 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4208 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 1342 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4217 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1348 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4226 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1354 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4235 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1360 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4244 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1366 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4253 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1372 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4262 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1378 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1384 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1391 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4290 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1397 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1403 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1409 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4320 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1418 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1427 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 1434 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4350 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 1438 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4359 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1448 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4368 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1454 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4376 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 1460 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4385 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 1464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4394 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1468 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4403 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 287:
#line 1476 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4409 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 1481 "conf_parser.y" /* yacc.c:1652  */
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
#line 4427 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 292:
#line 1494 "conf_parser.y" /* yacc.c:1652  */
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
#line 4447 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1511 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4456 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1517 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4465 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1527 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4474 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1531 "conf_parser.y" /* yacc.c:1652  */
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
#line 4520 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 308:
#line 1585 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4529 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 309:
#line 1591 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4538 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1597 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4547 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1603 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4561 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1614 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4570 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 316:
#line 1621 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 317:
#line 1625 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1629 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1633 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4606 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1637 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1641 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1645 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4633 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1649 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4642 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1653 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4651 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1657 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4660 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1663 "conf_parser.y" /* yacc.c:1652  */
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
#line 4677 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1677 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4689 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1686 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4701 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1699 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4713 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1706 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 337:
#line 1717 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4733 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 338:
#line 1723 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4742 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1729 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4751 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 345:
#line 1744 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4766 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 346:
#line 1760 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4782 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1771 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4797 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 354:
#line 1786 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4806 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 355:
#line 1792 "conf_parser.y" /* yacc.c:1652  */
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
#line 4828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1811 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 360:
#line 1818 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 361:
#line 1822 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1826 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1830 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1834 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1842 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1846 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1850 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1854 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1864 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4941 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1873 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 377:
#line 1886 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 378:
#line 1892 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 382:
#line 1899 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 383:
#line 1903 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1923 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1931 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1945 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5076 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1954 "conf_parser.y" /* yacc.c:1652  */
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
#line 5146 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 411:
#line 2038 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5155 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 412:
#line 2044 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5164 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 413:
#line 2050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5173 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2056 "conf_parser.y" /* yacc.c:1652  */
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
#line 5189 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2069 "conf_parser.y" /* yacc.c:1652  */
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
#line 5205 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5214 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2088 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5223 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5232 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5241 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2104 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5249 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5258 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 425:
#line 2114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5267 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 426:
#line 2120 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 427:
#line 2131 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5290 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2137 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2149 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5322 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2164 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5331 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2168 "conf_parser.y" /* yacc.c:1652  */
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
#line 5354 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 438:
#line 2191 "conf_parser.y" /* yacc.c:1652  */
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
#line 5377 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 439:
#line 2211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5386 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 440:
#line 2221 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 441:
#line 2225 "conf_parser.y" /* yacc.c:1652  */
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
#line 5419 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 447:
#line 2249 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5428 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 448:
#line 2255 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5437 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 454:
#line 2270 "conf_parser.y" /* yacc.c:1652  */
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
#line 5454 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 455:
#line 2287 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5463 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 456:
#line 2291 "conf_parser.y" /* yacc.c:1652  */
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
#line 5483 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 462:
#line 2311 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5492 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 463:
#line 2317 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5501 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 513:
#line 2378 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5509 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 514:
#line 2383 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5517 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 515:
#line 2388 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5525 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 516:
#line 2393 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5533 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2398 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5541 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2403 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5549 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2408 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5557 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2413 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5565 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2418 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5573 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2423 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2428 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5589 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2433 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2438 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5605 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2443 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5613 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2448 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5621 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2453 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5629 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2458 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5637 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2463 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5645 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2468 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5653 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2473 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5661 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2478 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5669 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2483 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5677 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2488 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5685 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2493 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2498 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5701 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2503 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5709 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2506 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5717 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2511 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5725 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2514 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5733 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2519 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2524 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2529 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5757 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2534 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5765 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2539 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2544 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5781 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2549 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5789 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2554 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5797 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2559 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5805 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2564 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5813 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2569 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2574 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2579 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 558:
#line 2585 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5845 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 559:
#line 2588 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2591 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5861 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2594 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5869 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2597 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2600 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2603 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5893 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2606 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5901 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2609 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2612 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2615 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2618 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2621 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5941 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2624 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5949 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2627 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5957 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2630 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5965 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2633 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5973 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2636 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2639 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5989 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2642 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5997 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2645 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6005 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2648 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6013 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2651 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2656 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6029 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6037 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 586:
#line 2665 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6045 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2668 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2671 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6061 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2674 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6069 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2677 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6077 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2680 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6085 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2683 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6093 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2686 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6101 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2689 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6109 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2692 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6117 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2695 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6125 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2698 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6133 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2701 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6141 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2704 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6149 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2707 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6157 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2710 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6165 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2713 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6173 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2716 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6181 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2719 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6189 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2722 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6197 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2727 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6205 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2732 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6213 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2737 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6221 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2742 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 628:
#line 2770 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 629:
#line 2775 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 630:
#line 2780 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2785 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6261 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2790 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6269 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2795 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2800 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2805 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2810 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2815 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2820 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2825 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2830 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6333 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2835 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 655:
#line 2858 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6350 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 656:
#line 2864 "conf_parser.y" /* yacc.c:1652  */
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
#line 6369 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 657:
#line 2880 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6381 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 658:
#line 2889 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6390 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2895 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6399 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6408 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6420 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2916 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6429 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2922 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6438 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6442 "conf_parser.c" /* yacc.c:1652  */
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
