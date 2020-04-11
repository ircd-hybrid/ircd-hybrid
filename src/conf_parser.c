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
  dlink_node *node, *node_next;
  dlink_list *tab[] = { &block_state.mask.list,
                        &block_state.leaf.list, &block_state.hub.list, NULL };

  for (dlink_list **list = tab; *list; ++list)
  {
    DLINK_FOREACH_SAFE(node, node_next, (*list)->head)
    {
      xfree(node->data);
      dlinkDelete(node, *list);
      free_dlink_node(node);
    }
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 175 "conf_parser.c" /* yacc.c:337  */
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
    ENABLE_EXTBANS = 294,
    ENCRYPTED = 295,
    EXCEED_LIMIT = 296,
    EXEMPT = 297,
    EXPIRATION = 298,
    FAILED_OPER_NOTICE = 299,
    FLATTEN_LINKS = 300,
    FLATTEN_LINKS_DELAY = 301,
    FLATTEN_LINKS_FILE = 302,
    GECOS = 303,
    GENERAL = 304,
    HIDDEN = 305,
    HIDDEN_NAME = 306,
    HIDE_CHANS = 307,
    HIDE_IDLE = 308,
    HIDE_IDLE_FROM_OPERS = 309,
    HIDE_SERVER_IPS = 310,
    HIDE_SERVERS = 311,
    HIDE_SERVICES = 312,
    HOST = 313,
    HUB = 314,
    HUB_MASK = 315,
    INVISIBLE_ON_CONNECT = 316,
    INVITE_CLIENT_COUNT = 317,
    INVITE_CLIENT_TIME = 318,
    INVITE_DELAY_CHANNEL = 319,
    INVITE_EXPIRE_TIME = 320,
    IP = 321,
    IRCD_AUTH = 322,
    IRCD_FLAGS = 323,
    IRCD_SID = 324,
    JOIN = 325,
    KILL = 326,
    KILL_CHASE_TIME_LIMIT = 327,
    KLINE = 328,
    KLINE_EXEMPT = 329,
    KLINE_MIN_CIDR = 330,
    KLINE_MIN_CIDR6 = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LISTEN = 336,
    MASK = 337,
    MAX_ACCEPT = 338,
    MAX_BANS = 339,
    MAX_BANS_LARGE = 340,
    MAX_CHANNELS = 341,
    MAX_IDLE = 342,
    MAX_INVITES = 343,
    MAX_NICK_CHANGES = 344,
    MAX_NICK_LENGTH = 345,
    MAX_NICK_TIME = 346,
    MAX_NUMBER = 347,
    MAX_TARGETS = 348,
    MAX_TOPIC_LENGTH = 349,
    MAX_WATCH = 350,
    MIN_IDLE = 351,
    MIN_NONWILDCARD = 352,
    MIN_NONWILDCARD_SIMPLE = 353,
    MODULE = 354,
    MODULES = 355,
    MOTD = 356,
    NAME = 357,
    NEED_IDENT = 358,
    NEED_PASSWORD = 359,
    NETWORK_DESC = 360,
    NETWORK_NAME = 361,
    NICK = 362,
    NO_OPER_FLOOD = 363,
    NO_TILDE = 364,
    NUMBER = 365,
    NUMBER_PER_CIDR = 366,
    NUMBER_PER_IP_GLOBAL = 367,
    NUMBER_PER_IP_LOCAL = 368,
    OPER_ONLY_UMODES = 369,
    OPER_UMODES = 370,
    OPERATOR = 371,
    OPERS_BYPASS_CALLERID = 372,
    PACE_WAIT = 373,
    PACE_WAIT_SIMPLE = 374,
    PASSWORD = 375,
    PATH = 376,
    PING_COOKIE = 377,
    PING_TIME = 378,
    PORT = 379,
    QSTRING = 380,
    RANDOM_IDLE = 381,
    REASON = 382,
    REDIRPORT = 383,
    REDIRSERV = 384,
    REHASH = 385,
    REMOTE = 386,
    REMOTEBAN = 387,
    RESV = 388,
    RESV_EXEMPT = 389,
    RSA_PRIVATE_KEY_FILE = 390,
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
    SQUIT = 404,
    STATS_E_DISABLED = 405,
    STATS_I_OPER_ONLY = 406,
    STATS_K_OPER_ONLY = 407,
    STATS_M_OPER_ONLY = 408,
    STATS_O_OPER_ONLY = 409,
    STATS_P_OPER_ONLY = 410,
    STATS_U_OPER_ONLY = 411,
    T_ALL = 412,
    T_BIND = 413,
    T_BOTS = 414,
    T_CALLERID = 415,
    T_CCONN = 416,
    T_COMMAND = 417,
    T_CLUSTER = 418,
    T_DEAF = 419,
    T_DEBUG = 420,
    T_DLINE = 421,
    T_EXTERNAL = 422,
    T_FARCONNECT = 423,
    T_FILE = 424,
    T_FULL = 425,
    T_GLOBOPS = 426,
    T_INVISIBLE = 427,
    T_IPV4 = 428,
    T_IPV6 = 429,
    T_LOCOPS = 430,
    T_LOG = 431,
    T_NCHANGE = 432,
    T_NONONREG = 433,
    T_OPME = 434,
    T_PREPEND = 435,
    T_PSEUDO = 436,
    T_RECVQ = 437,
    T_REJ = 438,
    T_RESTART = 439,
    T_SERVER = 440,
    T_SERVICE = 441,
    T_SERVNOTICE = 442,
    T_SET = 443,
    T_SHARED = 444,
    T_SIZE = 445,
    T_SKILL = 446,
    T_SOFTCALLERID = 447,
    T_SPY = 448,
    T_TARGET = 449,
    T_TLS = 450,
    T_UMODES = 451,
    T_UNAUTH = 452,
    T_UNDLINE = 453,
    T_UNLIMITED = 454,
    T_UNRESV = 455,
    T_UNXLINE = 456,
    T_WALLOP = 457,
    T_WALLOPS = 458,
    T_WEBIRC = 459,
    TBOOL = 460,
    THROTTLE_COUNT = 461,
    THROTTLE_TIME = 462,
    TIMEOUT = 463,
    TLS_CERTIFICATE_FILE = 464,
    TLS_CERTIFICATE_FINGERPRINT = 465,
    TLS_CIPHER_LIST = 466,
    TLS_CIPHER_SUITES = 467,
    TLS_CONNECTION_REQUIRED = 468,
    TLS_DH_PARAM_FILE = 469,
    TLS_MESSAGE_DIGEST_ALGORITHM = 470,
    TLS_SUPPORTED_GROUPS = 471,
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
#define ENABLE_EXTBANS 294
#define ENCRYPTED 295
#define EXCEED_LIMIT 296
#define EXEMPT 297
#define EXPIRATION 298
#define FAILED_OPER_NOTICE 299
#define FLATTEN_LINKS 300
#define FLATTEN_LINKS_DELAY 301
#define FLATTEN_LINKS_FILE 302
#define GECOS 303
#define GENERAL 304
#define HIDDEN 305
#define HIDDEN_NAME 306
#define HIDE_CHANS 307
#define HIDE_IDLE 308
#define HIDE_IDLE_FROM_OPERS 309
#define HIDE_SERVER_IPS 310
#define HIDE_SERVERS 311
#define HIDE_SERVICES 312
#define HOST 313
#define HUB 314
#define HUB_MASK 315
#define INVISIBLE_ON_CONNECT 316
#define INVITE_CLIENT_COUNT 317
#define INVITE_CLIENT_TIME 318
#define INVITE_DELAY_CHANNEL 319
#define INVITE_EXPIRE_TIME 320
#define IP 321
#define IRCD_AUTH 322
#define IRCD_FLAGS 323
#define IRCD_SID 324
#define JOIN 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_MIN_CIDR 330
#define KLINE_MIN_CIDR6 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LISTEN 336
#define MASK 337
#define MAX_ACCEPT 338
#define MAX_BANS 339
#define MAX_BANS_LARGE 340
#define MAX_CHANNELS 341
#define MAX_IDLE 342
#define MAX_INVITES 343
#define MAX_NICK_CHANGES 344
#define MAX_NICK_LENGTH 345
#define MAX_NICK_TIME 346
#define MAX_NUMBER 347
#define MAX_TARGETS 348
#define MAX_TOPIC_LENGTH 349
#define MAX_WATCH 350
#define MIN_IDLE 351
#define MIN_NONWILDCARD 352
#define MIN_NONWILDCARD_SIMPLE 353
#define MODULE 354
#define MODULES 355
#define MOTD 356
#define NAME 357
#define NEED_IDENT 358
#define NEED_PASSWORD 359
#define NETWORK_DESC 360
#define NETWORK_NAME 361
#define NICK 362
#define NO_OPER_FLOOD 363
#define NO_TILDE 364
#define NUMBER 365
#define NUMBER_PER_CIDR 366
#define NUMBER_PER_IP_GLOBAL 367
#define NUMBER_PER_IP_LOCAL 368
#define OPER_ONLY_UMODES 369
#define OPER_UMODES 370
#define OPERATOR 371
#define OPERS_BYPASS_CALLERID 372
#define PACE_WAIT 373
#define PACE_WAIT_SIMPLE 374
#define PASSWORD 375
#define PATH 376
#define PING_COOKIE 377
#define PING_TIME 378
#define PORT 379
#define QSTRING 380
#define RANDOM_IDLE 381
#define REASON 382
#define REDIRPORT 383
#define REDIRSERV 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESV 388
#define RESV_EXEMPT 389
#define RSA_PRIVATE_KEY_FILE 390
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
#define SQUIT 404
#define STATS_E_DISABLED 405
#define STATS_I_OPER_ONLY 406
#define STATS_K_OPER_ONLY 407
#define STATS_M_OPER_ONLY 408
#define STATS_O_OPER_ONLY 409
#define STATS_P_OPER_ONLY 410
#define STATS_U_OPER_ONLY 411
#define T_ALL 412
#define T_BIND 413
#define T_BOTS 414
#define T_CALLERID 415
#define T_CCONN 416
#define T_COMMAND 417
#define T_CLUSTER 418
#define T_DEAF 419
#define T_DEBUG 420
#define T_DLINE 421
#define T_EXTERNAL 422
#define T_FARCONNECT 423
#define T_FILE 424
#define T_FULL 425
#define T_GLOBOPS 426
#define T_INVISIBLE 427
#define T_IPV4 428
#define T_IPV6 429
#define T_LOCOPS 430
#define T_LOG 431
#define T_NCHANGE 432
#define T_NONONREG 433
#define T_OPME 434
#define T_PREPEND 435
#define T_PSEUDO 436
#define T_RECVQ 437
#define T_REJ 438
#define T_RESTART 439
#define T_SERVER 440
#define T_SERVICE 441
#define T_SERVNOTICE 442
#define T_SET 443
#define T_SHARED 444
#define T_SIZE 445
#define T_SKILL 446
#define T_SOFTCALLERID 447
#define T_SPY 448
#define T_TARGET 449
#define T_TLS 450
#define T_UMODES 451
#define T_UNAUTH 452
#define T_UNDLINE 453
#define T_UNLIMITED 454
#define T_UNRESV 455
#define T_UNXLINE 456
#define T_WALLOP 457
#define T_WALLOPS 458
#define T_WEBIRC 459
#define TBOOL 460
#define THROTTLE_COUNT 461
#define THROTTLE_TIME 462
#define TIMEOUT 463
#define TLS_CERTIFICATE_FILE 464
#define TLS_CERTIFICATE_FINGERPRINT 465
#define TLS_CIPHER_LIST 466
#define TLS_CIPHER_SUITES 467
#define TLS_CONNECTION_REQUIRED 468
#define TLS_DH_PARAM_FILE 469
#define TLS_MESSAGE_DIGEST_ALGORITHM 470
#define TLS_SUPPORTED_GROUPS 471
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
#line 133 "conf_parser.y" /* yacc.c:352  */

  int number;
  char *string;

#line 683 "conf_parser.c" /* yacc.c:352  */
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
#define YYLAST   1284

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  666
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1312

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
       0,   367,   367,   368,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   398,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   409,   409,
     410,   411,   412,   413,   420,   422,   422,   423,   423,   423,
     425,   431,   441,   443,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   463,   472,   481,   490,   499,   508,   517,   526,
     541,   556,   566,   580,   589,   612,   635,   658,   668,   670,
     670,   671,   672,   673,   674,   676,   685,   694,   708,   707,
     725,   725,   726,   726,   726,   728,   734,   745,   744,   763,
     763,   764,   764,   764,   764,   764,   766,   772,   778,   784,
     806,   807,   807,   809,   809,   810,   812,   819,   819,   832,
     833,   835,   835,   836,   836,   838,   846,   849,   855,   854,
     860,   860,   861,   865,   869,   873,   877,   881,   885,   889,
     900,   899,   962,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   971,   972,   973,   975,   981,   987,   993,   999,
    1010,  1016,  1027,  1034,  1033,  1039,  1039,  1040,  1044,  1048,
    1052,  1056,  1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,
    1092,  1096,  1100,  1104,  1108,  1112,  1116,  1120,  1124,  1128,
    1135,  1134,  1140,  1140,  1141,  1145,  1149,  1153,  1157,  1161,
    1165,  1169,  1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,
    1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,
    1245,  1249,  1253,  1264,  1263,  1320,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1338,  1344,  1350,  1356,  1362,  1368,  1374,
    1380,  1386,  1393,  1399,  1405,  1411,  1420,  1430,  1429,  1435,
    1435,  1436,  1440,  1451,  1450,  1457,  1456,  1461,  1461,  1462,
    1466,  1470,  1476,  1476,  1477,  1477,  1477,  1477,  1477,  1479,
    1479,  1481,  1481,  1483,  1496,  1513,  1519,  1530,  1529,  1576,
    1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,
    1587,  1593,  1599,  1605,  1617,  1616,  1622,  1622,  1623,  1627,
    1631,  1635,  1639,  1643,  1647,  1651,  1655,  1661,  1675,  1684,
    1698,  1697,  1712,  1712,  1713,  1713,  1713,  1713,  1715,  1721,
    1727,  1737,  1739,  1739,  1740,  1740,  1742,  1759,  1758,  1781,
    1781,  1782,  1782,  1782,  1782,  1784,  1790,  1810,  1809,  1815,
    1815,  1816,  1820,  1824,  1828,  1832,  1836,  1840,  1844,  1848,
    1852,  1863,  1862,  1881,  1881,  1882,  1882,  1882,  1884,  1891,
    1890,  1896,  1896,  1897,  1901,  1905,  1909,  1913,  1917,  1921,
    1925,  1929,  1933,  1944,  1943,  2021,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,
    2035,  2036,  2037,  2039,  2045,  2051,  2057,  2063,  2076,  2089,
    2095,  2101,  2105,  2112,  2111,  2116,  2116,  2117,  2121,  2127,
    2138,  2144,  2150,  2156,  2172,  2171,  2195,  2195,  2196,  2196,
    2196,  2198,  2218,  2229,  2228,  2253,  2253,  2254,  2254,  2254,
    2256,  2262,  2272,  2274,  2274,  2275,  2275,  2277,  2295,  2294,
    2315,  2315,  2316,  2316,  2316,  2318,  2324,  2334,  2336,  2336,
    2337,  2338,  2339,  2340,  2341,  2342,  2343,  2344,  2345,  2346,
    2347,  2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355,  2356,
    2357,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,  2366,
    2367,  2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,  2376,
    2377,  2378,  2379,  2380,  2381,  2382,  2385,  2390,  2395,  2400,
    2405,  2410,  2415,  2420,  2425,  2430,  2435,  2440,  2445,  2450,
    2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,  2500,
    2505,  2510,  2515,  2520,  2525,  2530,  2535,  2540,  2545,  2550,
    2555,  2560,  2565,  2570,  2575,  2581,  2580,  2585,  2585,  2586,
    2589,  2592,  2595,  2598,  2601,  2604,  2607,  2610,  2613,  2616,
    2619,  2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,
    2649,  2652,  2658,  2657,  2662,  2662,  2663,  2666,  2669,  2672,
    2675,  2678,  2681,  2684,  2687,  2690,  2693,  2696,  2699,  2702,
    2705,  2708,  2711,  2714,  2717,  2720,  2723,  2728,  2733,  2738,
    2743,  2752,  2754,  2754,  2755,  2756,  2757,  2758,  2759,  2760,
    2761,  2762,  2763,  2764,  2765,  2766,  2767,  2768,  2769,  2770,
    2772,  2777,  2782,  2787,  2792,  2797,  2802,  2807,  2812,  2817,
    2822,  2827,  2832,  2837,  2842,  2851,  2853,  2853,  2854,  2855,
    2856,  2857,  2858,  2859,  2860,  2861,  2862,  2863,  2865,  2871,
    2887,  2896,  2902,  2908,  2914,  2923,  2929
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
  "DOTS_IN_IDENT", "EMAIL", "ENABLE_EXTBANS", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "EXPIRATION", "FAILED_OPER_NOTICE", "FLATTEN_LINKS",
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
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SQUIT",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_BOTS", "T_CALLERID",
  "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE",
  "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_TARGET",
  "T_TLS", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES",
  "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "';'", "'}'", "'{'",
  "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_tls_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_tls_dh_param_file",
  "serverinfo_tls_cipher_list", "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
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
  "oper_whois", "oper_encrypted", "oper_tls_certificate_fingerprint",
  "oper_tls_connection_required", "oper_class", "oper_umodes", "$@6",
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
  "connect_tls_certificate_fingerprint", "connect_port", "connect_aftype",
  "connect_flags", "$@21", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_tls_cipher_list", "kill_entry", "$@22",
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
  "channel_item", "channel_enable_extbans",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_invite_delay_channel",
  "channel_invite_expire_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_invites", "channel_max_bans",
  "channel_max_bans_large", "channel_default_join_flood_count",
  "channel_default_join_flood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_flatten_links_delay", "serverhide_flatten_links_file",
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
  "serverhide_hidden", "serverhide_hide_server_ips", YY_NULLPTR
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

#define YYPACT_NINF -1038

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1038)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1038,   648, -1038,  -104,  -216,  -203, -1038, -1038, -1038,  -198,
   -1038,  -195, -1038, -1038, -1038,  -180, -1038, -1038, -1038,  -178,
    -171, -1038,  -158, -1038,  -144, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,     4,   940,  -137,  -120,   -89,    18,   -82,   381,   -51,
     -43,   -31,   178,   -28,   -17,   -16,   686,   556,    33,     3,
      36,     8,    40,     7,    10,    50,    51,    60, -1038, -1038,
   -1038, -1038, -1038,    53,    64,    69,    81,    82,    88,    93,
     100,   102,   105,   110,   119,   120,   121,   127,   144, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   615,   542,    28, -1038,   130,
      26, -1038, -1038,    72, -1038,   132,   141,   143,   146,   149,
     150,   151,   155,   159,   162,   163,   165,   169,   173,   175,
     176,   181,   185,   190,   194,   195,   197,   198,   199,   200,
   -1038, -1038,   202,   203,   204,   205,   207,   211,   213,   215,
     217,   220,   221,   224,   226,   227,   231,   233,   234,   235,
      42, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   362,    38,   274,
     147,   237,   241,     2, -1038, -1038, -1038,    96,   346,   225,
   -1038,   243,   247,   249,   250,   252,   258,   259,   260,   263,
      13, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   228,   268,   270,   271,   272,   280,   282,   283,   284,
     285,   286,   287,   289,   290,   291,   292,   293,    79, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,    86,   298,   296,    11,
   -1038, -1038, -1038,   131,   246, -1038,   304,   111, -1038, -1038,
      56, -1038,   355,   383,   386,   308, -1038,   302,   430,   339,
     341,   440,   430,   430,   430,   441,   430,   430,   443,   444,
     445,   448,   321, -1038,   329,   328,   330,   331, -1038,   332,
     333,   334,   336,   337,   342,   343,   344,   345,   347,   349,
     218, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,   358,   359,   360,
     361,   363,   367,   369, -1038,   370,   371,   372,   377,   378,
     380,   384,   385,   277, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   389,   390,    19, -1038, -1038, -1038,   438,   365, -1038,
   -1038,   393,   394,    20, -1038, -1038, -1038,   375,   430,   482,
     430,   430,   415,   519,   430,   426,   524,   525,   526,   433,
     434,   430,   531,   537,   541,   543,   430,   544,   545,   546,
     547,   454,   431,   436,   455,   430,   430,   463,   467,   468,
     469,   470,   471,   473,   474,   475,   571,   430,   430,   430,
     477,   574,   457, -1038,   458,   452,   459, -1038,   461,   464,
     465,   472,   476,   135, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   478,   479,    49, -1038, -1038, -1038,
     485,   484,   488, -1038,   491, -1038,    25, -1038, -1038, -1038,
   -1038, -1038,   567,   578,   499, -1038,   503,   501,   505,    70,
   -1038, -1038, -1038,   509,   510,   511, -1038,   512,   513, -1038,
     517,   521,   522,   523,    14, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   527,   528,   529,   535,
      39, -1038, -1038, -1038, -1038,   500,   504,   430,   579,   555,
     583,   569,   572,   575,   530, -1038, -1038,   669,   657,   580,
     658,   674,   676,   663,   664,   665,   666,   667,   670,   673,
     675,   677,   678,   568, -1038,   570,   573, -1038,   118, -1038,
   -1038, -1038, -1038,   599,   577, -1038,   576,   582,   581,   584,
     586,   589,    24, -1038, -1038, -1038, -1038, -1038,   681,   585,
   -1038,   594,   592, -1038,   593,    30, -1038, -1038, -1038, -1038,
     597,   602,   609, -1038,   613,   852,   614,   616,   620,   622,
     624,   625,   626,   629,   630,   634,   635,   636,   638,   639,
   -1038, -1038,   700,   704,   430,   618,   707,   430,   761,   430,
     747,   764,   765,   766,   430,   767,   767,   647, -1038, -1038,
     754,    -6,   755,   680,   756,   769,   652,   771,   772,   779,
     774,   777,   430,   778,   780,   661, -1038,   782,   783,   682,
   -1038,   687, -1038,   784,   787,   693, -1038,   697,   702,   705,
     711,   713,   715,   716,   717,   719,   720,   725,   726,   727,
     729,   732,   734,   737,   738,   739,   740,   741,   743,   744,
     745,   746,   762,   671,   749,   750,   751,   752,   768,   770,
     775,   781,   785,   789,   790,   791,   792,   796,   798,   799,
     800,   801, -1038, -1038,   806,   699,   683,   810,   828,   853,
     860,   870,   802, -1038,   871,   872,   803, -1038, -1038,   873,
     875,   776,   898,   804, -1038,   805,   807, -1038, -1038,   884,
     886,   808, -1038, -1038,   888,   706,   809,   889,   912,   811,
     915,   836,   917,   919,   815, -1038, -1038,   922,   923,   924,
     819, -1038,   820,   821,   822,   823,   824,   825,   826,   827,
     829, -1038,   830,   831,   832,   833,   834,   835,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   846, -1038, -1038,
     934,   847,   848, -1038,   849, -1038,    99, -1038,   942,   953,
     957,   958,   854, -1038,   855, -1038, -1038,   959,   856,   962,
     857, -1038, -1038, -1038, -1038, -1038,   430,   430,   430,   430,
     430,   430,   430, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,   858,
     861,   862,   -38,   863,   864,   865,   866,   867,   868,   869,
     874,   876,   313,   877,   878, -1038,   879,   880,   881,   882,
     883,   885,   887,     5,   890,   891,   892,   893,   894,   895,
     896,   897, -1038,   899,   900, -1038, -1038,   901,   902, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,  -207, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,  -199, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   903,   904,   318,   905,   906,   907,   908,   909, -1038,
     910,   911, -1038,   913,   914,   -32,   927,   916, -1038, -1038,
   -1038, -1038,   918,   921, -1038,   925,   926,   442,   928,   929,
     723,   930,   931,   932,   933, -1038,   935,   936,   937, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,   938,   621, -1038, -1038,   939,
     920,   941, -1038,    22, -1038, -1038, -1038, -1038,   943,   945,
     946,   947, -1038, -1038,   948,   786,   949, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
    -194, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   767,   767,   767, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038,  -159, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   762, -1038,   671, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,  -136, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
     -44, -1038,   981,   898,   950, -1038, -1038, -1038, -1038, -1038,
   -1038,   951, -1038,   952,   954, -1038, -1038,   955,   956, -1038,
   -1038,   960, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   -20, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,    66, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,    77, -1038, -1038,   976,   -88,   961,   963, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,    78, -1038, -1038, -1038,   -38, -1038,
   -1038, -1038, -1038,     5, -1038, -1038, -1038,   318, -1038,   -32,
   -1038, -1038, -1038,   971,   970,   973,   982,   975,   986, -1038,
     442, -1038,   723, -1038,   621,   966,   967,   968,   278, -1038,
   -1038,   786, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   125, -1038, -1038, -1038,
     278, -1038
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   233,   393,   443,     0,
     458,     0,   297,   434,   273,     0,    98,   150,   330,     0,
       0,   371,     0,   107,     0,   347,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   629,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     628,   627,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   614,   615,   625,   626,     0,     0,     0,   456,     0,
       0,   454,   455,     0,   515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     582,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   470,   471,   513,   477,   514,   508,   509,   510,
     511,   481,   472,   473,   474,   475,   476,   478,   479,   480,
     482,   483,   512,   487,   488,   489,   490,   486,   485,   491,
     498,   499,   492,   493,   494,   484,   496,   506,   507,   504,
     505,   497,   495,   502,   503,   500,   501,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647,   648,   649,   650,   651,   652,   653,   655,   654,
     656,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   345,     0,     0,   343,   344,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   612,     0,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,   240,   242,   243,   244,   245,   246,   247,
     248,   238,   239,   241,   249,   250,   251,     0,     0,     0,
       0,     0,     0,     0,   423,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,   397,   398,   399,   400,   401,
     402,   403,   405,   404,   407,   411,   408,   409,   410,   406,
     449,     0,     0,     0,   446,   447,   448,     0,     0,   453,
     464,     0,     0,     0,   461,   462,   463,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   468,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   300,   301,   302,   303,   308,   304,
     305,   306,   307,   440,     0,     0,     0,   437,   438,   439,
       0,     0,     0,   275,     0,   285,     0,   283,   284,   286,
     287,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   200,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   333,   334,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   646,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   379,     0,   374,
     375,   376,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     342,     0,     0,   357,     0,     0,   350,   351,   352,   353,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     611,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   412,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   395,     0,     0,     0,
     445,     0,   452,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   467,   309,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   299,     0,     0,     0,   436,   288,     0,
       0,     0,     0,     0,   282,     0,     0,    44,   104,     0,
       0,     0,   100,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   337,     0,     0,     0,
       0,   332,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   645,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   377,
       0,     0,     0,   373,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   341,   354,     0,     0,     0,
       0,   349,    97,    96,    95,   643,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   644,   631,   630,   632,   633,
     634,   635,   636,   637,   638,   641,   642,   639,   640,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   444,   457,     0,     0,   459,
     527,   531,   516,   517,   544,   520,   609,   610,   552,   521,
     522,   549,   526,   534,   525,   523,   524,   530,   529,   528,
     550,   518,   607,   608,   548,   606,   592,   586,   602,   587,
     588,   589,   597,   605,   590,   599,   603,   593,   604,   594,
     598,   591,   601,   596,   595,   600,     0,   585,   581,   564,
     565,   566,   559,   577,   560,   561,   562,   572,   580,   563,
     574,   578,   568,   579,   569,   573,   567,   576,   571,   570,
     575,     0,   558,   545,   543,   546,   551,   547,   536,   542,
     541,   537,   538,   539,   540,   553,   554,   533,   532,   535,
     519,     0,     0,     0,     0,     0,     0,     0,     0,   298,
       0,     0,   435,     0,     0,     0,   293,   289,   292,   274,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   331,
     661,   658,   659,   660,   665,   664,   666,   662,   663,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   372,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   346,     0,     0,     0,   348,    31,    32,
      33,    34,    35,    36,    37,   262,   263,   257,   272,   271,
       0,   270,   258,   266,   259,   265,   253,   264,   256,   255,
     254,    38,    38,    38,    40,    39,   260,   261,   418,   421,
     422,   432,   429,   414,   430,   427,   428,     0,   426,   431,
     413,   420,   417,   416,   415,   419,   433,   450,   451,   465,
     466,   583,     0,   556,     0,   312,   313,   322,   318,   319,
     321,   326,   323,   324,   325,   320,     0,   317,   311,   329,
     328,   327,   310,   442,   441,   296,   295,   280,   281,   279,
       0,   278,     0,     0,     0,   105,   106,   172,   169,   220,
     232,   207,   216,     0,   205,   210,   226,     0,   219,   224,
     230,   209,   212,   221,   223,   227,   217,   225,   213,   231,
     215,   222,   211,   214,     0,   203,   165,   167,   199,   182,
     183,   184,   177,   195,   178,   179,   180,   190,   198,   181,
     192,   196,   186,   197,   187,   191,   185,   194,   189,   188,
     193,     0,   176,   170,   171,   166,   168,   340,   338,   339,
     378,   383,   389,   392,   385,   391,   386,   390,   388,   384,
     387,     0,   382,   134,     0,     0,     0,     0,   129,   117,
     116,   118,   119,   355,   361,   367,   370,   363,   369,   364,
     368,   366,   362,   365,     0,   360,   356,   268,     0,    41,
      42,    43,   424,     0,   584,   557,   315,     0,   276,     0,
     294,   291,   290,     0,     0,     0,     0,     0,     0,   201,
       0,   174,     0,   380,     0,     0,     0,     0,     0,   128,
     358,     0,   269,   425,   316,   277,   206,   229,   204,   228,
     218,   208,   202,   175,   381,   135,   137,   136,   148,   147,
     143,   145,   149,   146,   142,   144,     0,   141,   359,   139,
       0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1038, -1038, -1038,  -448,  -306, -1037,  -635, -1038, -1038,   977,
   -1038, -1038, -1038, -1038,   851, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038,  1043, -1038, -1038, -1038, -1038, -1038, -1038,
     644, -1038, -1038, -1038, -1038, -1038,   565, -1038, -1038, -1038,
   -1038, -1038, -1038,   859, -1038, -1038, -1038, -1038,   107, -1038,
   -1038, -1038, -1038, -1038,  -181, -1038, -1038, -1038,   641, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
    -119, -1038, -1038, -1038,  -112, -1038, -1038, -1038,   944, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038,   -83, -1038, -1038, -1038,
   -1038, -1038,   -87, -1038,   685, -1038, -1038, -1038,    41, -1038,
   -1038, -1038, -1038, -1038,   710, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   -75, -1038, -1038, -1038, -1038, -1038, -1038,   653,
   -1038, -1038, -1038, -1038, -1038,   964, -1038, -1038, -1038, -1038,
     590, -1038, -1038, -1038, -1038, -1038,   -95, -1038, -1038, -1038,
     633, -1038, -1038, -1038, -1038,   -85, -1038, -1038, -1038,   850,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038,   -60, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038,   728, -1038, -1038, -1038, -1038, -1038,   812, -1038, -1038,
   -1038, -1038,  1082, -1038, -1038, -1038, -1038,   813, -1038, -1038,
   -1038, -1038,  1033, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038,    92, -1038, -1038, -1038,    95,
   -1038, -1038, -1038, -1038, -1038, -1038,  1110, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038,   969, -1038, -1038, -1038, -1038, -1038,
   -1038, -1038, -1038, -1038
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   823,   824,  1084,  1085,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1043,  1044,  1045,
    1046,  1047,  1226,  1306,  1307,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1201,
    1202,   525,   746,  1174,  1175,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1070,  1071,    35,    61,   485,
     731,  1140,  1141,   486,   487,   488,  1144,   987,   988,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1126,  1127,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1244,  1245,    40,    68,   568,
     569,   570,   571,   791,  1221,  1222,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1097,  1098,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   433,   951,   952,   212,   432,   926,   927,
     213,   214,   215,   216,    47,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    48,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     853,   854,   606,   220,   287,    73,   610,   611,   612,   295,
     614,   615,   287,  1095,   230,   503,  1068,    51,  1137,   118,
     390,   400,   852,  1039,  1111,   577,   480,   118,  1112,   390,
      52,   591,  1113,   504,    74,    56,  1114,  1247,    58,   473,
     526,  1248,    75,   124,  1249,  1250,  1251,   231,   125,   126,
     473,   127,   128,    62,   505,    66,   129,   591,   232,   233,
     234,    73,    67,   235,   236,   130,   131,   132,   237,   238,
     239,   496,  1252,   400,   133,    69,  1253,   134,   135,   136,
     251,   527,   506,   481,   119,   391,   137,   565,  1069,    71,
      74,   482,   119,   483,   391,  1256,   115,   496,    75,  1257,
    1039,   221,   668,   138,   670,   671,    76,   252,   674,   253,
     296,  1276,   295,   116,   139,   681,   507,   140,   141,   565,
     686,   528,   401,   222,  1040,   142,   578,    49,    50,   695,
     696,   143,   592,   144,   508,   145,   454,   146,   254,   147,
     148,   707,   708,   709,   117,    82,   392,   402,   255,   484,
     149,   123,   497,  1138,   455,   392,   150,   151,   592,   152,
     153,   154,    76,  1139,   155,   474,   529,   857,   858,   256,
      83,    84,  -127,   257,   401,   456,   474,    85,   497,   220,
    -127,   258,   217,    86,   259,   260,   579,  1258,   566,   156,
     218,  1259,   157,   158,   159,   160,   161,   162,   163,   402,
    1096,  1040,   219,   457,   580,   227,    87,    88,    89,    90,
     509,  1269,  1041,   296,   261,  1270,   228,   229,   581,   324,
     566,    91,    92,    93,   510,   288,   526,   511,    94,    95,
      96,   764,    97,   288,   494,   325,   326,   512,   301,   498,
     327,   513,  1042,   574,   302,   544,   754,   577,   164,   165,
     593,   659,   665,   594,  1227,   458,   802,   733,   398,   166,
     167,   475,   810,   459,   460,   498,   286,   527,   168,   294,
     169,   760,   475,   300,   452,   480,   593,   221,   357,   594,
     358,   726,   359,   461,   303,   304,   328,   307,   262,  1041,
     263,   264,   305,   265,   266,   267,   360,  1271,   308,   222,
     576,  1272,   741,   309,   329,   330,   567,   528,  1273,  1280,
     331,   563,  1274,  1281,   332,   310,   311,   361,   841,  1042,
     333,   844,   312,   846,  1081,  1082,  1083,   313,   851,   334,
     335,   336,   481,  1117,   314,   362,   315,   363,   567,   316,
     482,   337,   483,   589,   317,   364,   869,   503,   578,  1298,
     792,  1299,   529,   318,   319,   320,  1309,   365,   462,  1118,
    1310,   321,   338,   454,   397,   504,   407,   722,  1058,  1059,
    1060,  1061,  1062,  1063,  1064,   408,   322,   409,   491,   366,
     410,   455,   124,   411,   412,   413,   505,   125,   126,   414,
     127,   128,  1119,   415,  1300,   129,   416,   417,   484,   418,
     339,   367,   456,   419,   130,   131,   132,   420,   579,   421,
     422,  1301,   604,   133,   506,   423,   134,   135,   136,   424,
     368,  1120,  1121,   852,   425,   137,   580,  1122,   426,   427,
     457,   428,   429,   430,   431,   369,   434,   435,   436,   437,
     581,   438,   138,  1302,  1303,   439,  1149,   440,   507,   441,
     637,   442,  1123,   139,   443,   444,   140,   141,   445,   546,
     446,   447,  1150,  1151,   142,   448,   508,   449,   450,   451,
     143,   492,   144,  1152,   145,   493,   146,   535,   147,   148,
     600,   536,   458,   537,   538,   370,   539,   371,   372,   149,
     459,   460,   540,   541,   542,   150,   151,   543,   152,   153,
     154,  1304,   547,   155,   548,   549,   550,  1305,   601,   655,
     461,   602,  1153,  1154,   551,  1155,   552,   553,   554,   555,
     556,   557,  1124,   558,   559,   560,   561,   562,   156,   572,
     573,   157,   158,   159,   160,   161,   162,   163,   588,   603,
     605,  1156,   509,   357,   607,   358,   608,   359,  1125,  1157,
     609,   613,   620,   616,   617,   618,   510,   251,   619,   511,
     621,   360,   622,   661,   623,   624,   626,   627,   628,   512,
     629,   630,  1158,   513,  1159,  1160,   631,   632,   633,   634,
     667,   635,   361,   636,   252,   462,   253,   164,   165,   639,
    1277,  1161,   669,   640,   641,   642,   662,   643,   166,   167,
     362,   644,   363,   645,   647,   648,   649,   168,  1162,   169,
     364,   650,   651,  1163,   652,   254,   324,  1164,   653,   654,
     672,  1165,   365,   657,   658,   255,  1166,   663,   664,   673,
    1167,   675,   325,   326,   676,   677,   678,   327,   679,   680,
    1168,   682,  1169,  1170,   366,  1171,   256,   683,     2,     3,
     257,   684,     4,   685,   687,   688,   689,   690,   258,   691,
     694,   259,   260,  1172,     5,   692,   367,     6,   697,     7,
     693,  1173,   698,   699,   700,   701,   702,     8,   703,   704,
     705,   706,   710,   328,   711,   368,   714,   230,   712,   713,
       9,   261,   735,   715,  1211,   717,    10,    11,   718,   719,
     369,   329,   330,   736,   765,   762,   720,   331,   767,   763,
     721,   332,   724,   725,   928,    12,   728,   333,   729,    13,
     231,   929,   730,   930,   931,   732,   334,   335,   336,    14,
     737,   232,   233,   234,   738,   739,   235,   236,   337,   740,
     743,   237,   238,   239,   744,   745,   747,   748,    15,    16,
     370,   750,   371,   372,  1212,   751,   752,   753,   756,   338,
     766,   771,   757,   758,    17,   262,  1178,   263,   264,   759,
     265,   266,   267,  1179,   768,  1180,  1181,   769,  1213,   772,
     770,    18,   773,   775,   776,   774,   777,  1214,   778,   779,
     780,   781,   782,    19,    20,   783,  1215,   339,   784,   788,
     785,   789,   786,   787,   794,   905,   804,   790,   795,   796,
     839,    21,   906,   797,   840,   798,   805,   843,   799,  1216,
     800,  1217,  1218,   801,    22,   806,   807,   809,   812,    23,
     932,   933,   934,   813,    24,   935,   936,    25,   937,   938,
     814,   939,  1219,   940,   815,   825,   941,   826,   942,   943,
    1220,   827,   842,   828,   944,   829,   830,   831,   945,  1234,
     832,   833,   946,   947,   948,   834,   835,   836,   949,   837,
     838,   845,   847,   950,   848,   849,   850,   852,   855,   856,
     859,   861,  1182,  1183,  1184,   860,   863,  1185,  1186,   866,
    1187,  1188,   872,  1189,   862,  1190,   864,   865,  1191,   867,
    1192,  1193,   868,   870,   972,   871,  1194,   873,   874,   877,
    1195,   996,   878,   875,  1196,  1197,  1198,   973,   876,  1235,
    1199,   907,   908,   909,   879,  1200,   910,   911,   880,   912,
     913,   971,   914,   881,   915,   974,   882,   916,   975,   917,
     918,    82,   883,  1236,   884,   919,   885,   886,   887,   920,
     888,   889,  1237,   921,   922,   923,   890,   891,   892,   924,
     893,  1238,   605,   894,   925,   895,    83,    84,   896,   897,
     898,   899,   900,    85,   901,   902,   903,   904,   976,    86,
     953,   954,   955,   956,  1239,   977,  1240,  1241,   816,   817,
     818,   819,   820,   821,   822,   978,   980,   981,   983,   957,
     984,   958,    87,    88,    89,    90,   959,  1242,   986,   992,
     985,   993,   960,   995,   998,  1243,   961,    91,    92,    93,
     962,   963,   964,   965,    94,    95,    96,   966,    97,   967,
     968,   969,   970,   979,   982,   989,   990,   999,   991,   994,
    1001,  1002,  1003,   997,  1004,  1000,  1005,  1006,  1007,  1008,
    1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1035,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1048,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,  1049,  1037,
    1038,  1036,  1050,  1051,  1054,  1052,  1053,  1056,  1057,  1065,
    1055,  1260,  1066,  1067,  1072,  1073,  1074,  1075,  1076,  1077,
    1078,  1275,  1286,  1287,  1288,  1079,  1290,  1080,  1086,  1087,
    1088,  1089,  1090,  1091,  1092,  1289,  1093,  1291,  1094,   564,
     306,  1099,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1311,
    1107,  1108,  1109,  1110,  1115,  1116,  1128,  1129,  1130,  1131,
    1132,  1133,  1134,   742,  1135,  1136,  1142,   803,   575,  1145,
    1228,  1143,  1146,  1293,  1224,   755,  1147,  1148,  1292,  1176,
    1177,  1203,  1204,  1205,  1206,  1282,  1207,  1208,  1209,  1210,
    1223,   734,  1285,   723,  1229,  1225,  1230,  1231,  1232,  1233,
    1246,  1262,  1284,   761,  1261,   811,  1308,  1263,  1264,  1294,
    1265,  1266,  1267,  1283,  1279,  1278,  1268,  1295,  1296,  1297,
     495,   793,   399,   453,   727,   660,  1255,  1254,   323,   545,
       0,     0,     0,     0,     0,     0,   666,     0,     0,     0,
       0,     0,     0,   656,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   590,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   638
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,     1,   312,   313,   314,     1,
     316,   317,     1,     8,     1,     1,    54,   233,    50,     1,
       1,     1,   110,     1,   231,     1,     1,     1,   235,     1,
     233,     1,   231,    19,    30,   233,   235,   231,   233,     1,
       1,   235,    38,     1,  1081,  1082,  1083,    34,     6,     7,
       1,     9,    10,   233,    40,   233,    14,     1,    45,    46,
      47,     1,   233,    50,    51,    23,    24,    25,    55,    56,
      57,     1,   231,     1,    32,   233,   235,    35,    36,    37,
       1,    42,    68,    58,    66,    66,    44,     1,   126,   233,
      30,    66,    66,    68,    66,   231,   233,     1,    38,   235,
       1,    99,   408,    61,   410,   411,   102,    28,   414,    30,
     102,   199,     1,   233,    72,   421,   102,    75,    76,     1,
     426,    82,   102,   121,   102,    83,   102,   231,   232,   435,
     436,    89,   102,    91,   120,    93,     1,    95,    59,    97,
      98,   447,   448,   449,   233,     1,   127,   127,    69,   124,
     108,   233,    82,   185,    19,   127,   114,   115,   102,   117,
     118,   119,   102,   195,   122,   127,   127,   173,   174,    90,
      26,    27,   169,    94,   102,    40,   127,    33,    82,     1,
     169,   102,   233,    39,   105,   106,   162,   231,   102,   147,
     233,   235,   150,   151,   152,   153,   154,   155,   156,   127,
     195,   102,   233,    68,   180,   233,    62,    63,    64,    65,
     196,   231,   190,   102,   135,   235,   233,   233,   194,     1,
     102,    77,    78,    79,   210,   222,     1,   213,    84,    85,
      86,   537,    88,   222,   232,    17,    18,   223,   231,   169,
      22,   227,   220,   232,   234,   232,   232,     1,   206,   207,
     220,   232,   232,   223,   232,   120,   232,   232,   232,   217,
     218,   223,   232,   128,   129,   169,   233,    42,   226,   233,
     228,   232,   223,   233,   232,     1,   220,    99,     1,   223,
       3,   232,     5,   148,   234,   234,    68,   234,   209,   190,
     211,   212,   232,   214,   215,   216,    19,   231,   234,   121,
     169,   235,   232,   234,    86,    87,   220,    82,   231,   231,
      92,   232,   235,   235,    96,   234,   234,    40,   624,   220,
     102,   627,   234,   629,    11,    12,    13,   234,   634,   111,
     112,   113,    58,    15,   234,    58,   234,    60,   220,   234,
      66,   123,    68,   232,   234,    68,   652,     1,   102,    71,
     232,    73,   127,   234,   234,   234,   231,    80,   223,    41,
     235,   234,   144,     1,   234,    19,   234,   232,   816,   817,
     818,   819,   820,   821,   822,   234,   232,   234,   231,   102,
     234,    19,     1,   234,   234,   234,    40,     6,     7,   234,
       9,    10,    74,   234,   116,    14,   234,   234,   124,   234,
     182,   124,    40,   234,    23,    24,    25,   234,   162,   234,
     234,   133,   110,    32,    68,   234,    35,    36,    37,   234,
     143,   103,   104,   110,   234,    44,   180,   109,   234,   234,
      68,   234,   234,   234,   234,   158,   234,   234,   234,   234,
     194,   234,    61,   165,   166,   234,     4,   234,   102,   234,
     232,   234,   134,    72,   234,   234,    75,    76,   234,   231,
     234,   234,    20,    21,    83,   234,   120,   234,   234,   234,
      89,   234,    91,    31,    93,   234,    95,   234,    97,    98,
     125,   234,   120,   234,   234,   208,   234,   210,   211,   108,
     128,   129,   234,   234,   234,   114,   115,   234,   117,   118,
     119,   223,   234,   122,   234,   234,   234,   229,   125,   232,
     148,   125,    70,    71,   234,    73,   234,   234,   234,   234,
     234,   234,   204,   234,   234,   234,   234,   234,   147,   231,
     234,   150,   151,   152,   153,   154,   155,   156,   234,   231,
     110,    99,   196,     1,   205,     3,   205,     5,   230,   107,
     110,   110,   231,   110,   110,   110,   210,     1,   110,   213,
     231,    19,   234,   125,   234,   234,   234,   234,   234,   223,
     234,   234,   130,   227,   132,   133,   234,   234,   234,   234,
     205,   234,    40,   234,    28,   223,    30,   206,   207,   231,
    1225,   149,   110,   234,   234,   234,   231,   234,   217,   218,
      58,   234,    60,   234,   234,   234,   234,   226,   166,   228,
      68,   234,   234,   171,   234,    59,     1,   175,   234,   234,
     205,   179,    80,   234,   234,    69,   184,   234,   234,   110,
     188,   205,    17,    18,   110,   110,   110,    22,   205,   205,
     198,   110,   200,   201,   102,   203,    90,   110,     0,     1,
      94,   110,     4,   110,   110,   110,   110,   110,   102,   205,
     205,   105,   106,   221,    16,   234,   124,    19,   205,    21,
     234,   229,   205,   205,   205,   205,   205,    29,   205,   205,
     205,   110,   205,    68,   110,   143,   234,     1,   231,   231,
      42,   135,   125,   234,    73,   234,    48,    49,   234,   234,
     158,    86,    87,   125,   125,   205,   234,    92,   125,   205,
     234,    96,   234,   234,    43,    67,   231,   102,   234,    71,
      34,    50,   234,    52,    53,   234,   111,   112,   113,    81,
     231,    45,    46,    47,   231,   234,    50,    51,   123,   234,
     231,    55,    56,    57,   234,   234,   234,   234,   100,   101,
     208,   234,   210,   211,   133,   234,   234,   234,   231,   144,
     205,   231,   234,   234,   116,   209,    43,   211,   212,   234,
     214,   215,   216,    50,   205,    52,    53,   205,   157,   110,
     205,   133,   125,   125,   110,   205,   110,   166,   125,   125,
     125,   125,   125,   145,   146,   125,   175,   182,   125,   231,
     125,   231,   125,   125,   205,    43,   125,   234,   231,   233,
     110,   163,    50,   231,   110,   234,   231,   110,   234,   198,
     234,   200,   201,   234,   176,   231,   234,   234,   231,   181,
     159,   160,   161,   231,   186,   164,   165,   189,   167,   168,
     231,   170,   221,   172,   231,   231,   175,   231,   177,   178,
     229,   231,   234,   231,   183,   231,   231,   231,   187,    73,
     231,   231,   191,   192,   193,   231,   231,   231,   197,   231,
     231,   110,   125,   202,   110,   110,   110,   110,   231,   125,
     125,   125,   159,   160,   161,   205,   234,   164,   165,   110,
     167,   168,   231,   170,   125,   172,   125,   125,   175,   125,
     177,   178,   125,   125,   205,   125,   183,   125,   125,   125,
     187,   205,   125,   231,   191,   192,   193,   234,   231,   133,
     197,   159,   160,   161,   231,   202,   164,   165,   231,   167,
     168,   125,   170,   231,   172,   125,   231,   175,   110,   177,
     178,     1,   231,   157,   231,   183,   231,   231,   231,   187,
     231,   231,   166,   191,   192,   193,   231,   231,   231,   197,
     231,   175,   110,   231,   202,   231,    26,    27,   231,   231,
     231,   231,   231,    33,   231,   231,   231,   231,   125,    39,
     231,   231,   231,   231,   198,   125,   200,   201,   136,   137,
     138,   139,   140,   141,   142,   125,   125,   125,   125,   231,
     125,   231,    62,    63,    64,    65,   231,   221,   110,   125,
     234,   125,   231,   125,   125,   229,   231,    77,    78,    79,
     231,   231,   231,   231,    84,    85,    86,   231,    88,   231,
     231,   231,   231,   231,   231,   231,   231,   125,   231,   231,
     125,   205,   125,   234,   125,   234,   231,   125,   125,   125,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   125,
     231,   231,   231,   231,   231,   231,   231,   125,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   125,   231,
     231,   234,   125,   125,   125,   231,   231,   125,   231,   231,
     234,   110,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   125,   131,   133,   131,   231,   131,   231,   231,   231,
     231,   231,   231,   231,   231,   133,   231,   131,   231,   268,
      77,   231,   231,   231,   231,   231,   231,   231,   231,  1310,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   499,   231,   231,   219,   582,   289,   231,
    1043,   235,   231,  1272,   234,   514,   231,   231,  1270,   231,
     231,   231,   231,   231,   231,  1248,   231,   231,   231,   231,
     231,   486,  1259,   463,   231,   234,   231,   231,   231,   231,
     231,   231,  1257,   530,  1143,   595,  1281,   236,   236,  1274,
     236,   236,   236,  1253,   231,   234,   236,   231,   231,   231,
     223,   568,   120,   170,   476,   393,  1114,  1112,    98,   240,
      -1,    -1,    -1,    -1,    -1,    -1,   403,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   340
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    21,    29,    42,
      48,    49,    67,    71,    81,   100,   101,   116,   133,   145,
     146,   163,   176,   181,   186,   189,   239,   244,   249,   268,
     274,   280,   288,   302,   322,   344,   358,   373,   380,   384,
     394,   403,   425,   431,   437,   441,   447,   501,   519,   231,
     232,   233,   233,   323,   404,   432,   233,   442,   233,   359,
     426,   345,   233,   275,   303,   374,   233,   233,   395,   233,
     281,   233,   385,     1,    30,    38,   102,   269,   270,   271,
     272,   273,     1,    26,    27,    33,    39,    62,    63,    64,
      65,    77,    78,    79,    84,    85,    86,    88,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   233,   233,   233,     1,    66,
     438,   439,   440,   233,     1,     6,     7,     9,    10,    14,
      23,    24,    25,    32,    35,    36,    37,    44,    61,    72,
      75,    76,    83,    89,    91,    93,    95,    97,    98,   108,
     114,   115,   117,   118,   119,   122,   147,   150,   151,   152,
     153,   154,   155,   156,   206,   207,   217,   218,   226,   228,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   493,   497,   498,   499,   500,   233,   233,   233,
       1,    99,   121,   245,   246,   247,   248,   233,   233,   233,
       1,    34,    45,    46,    47,    50,    51,    55,    56,    57,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,     1,    28,    30,    59,    69,    90,    94,   102,   105,
     106,   135,   209,   211,   212,   214,   215,   216,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   233,     1,   222,   289,
     290,   291,   292,   293,   233,     1,   102,   381,   382,   383,
     233,   231,   234,   234,   234,   232,   270,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   503,     1,    17,    18,    22,    68,    86,
      87,    92,    96,   102,   111,   112,   113,   123,   144,   182,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,     1,     3,     5,
      19,    40,    58,    60,    68,    80,   102,   124,   143,   158,
     208,   210,   211,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   420,   421,   422,   423,   424,
       1,    66,   127,   433,   434,   435,   436,   234,   232,   439,
       1,   102,   127,   443,   444,   445,   446,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   494,   490,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   449,     1,    19,    40,    68,   120,   128,
     129,   148,   223,   360,   361,   362,   363,   364,   365,   366,
     370,   371,   372,     1,   127,   223,   427,   428,   429,   430,
       1,    58,    66,    68,   124,   346,   350,   351,   352,   356,
     357,   231,   234,   234,   232,   246,     1,    82,   169,   276,
     277,   278,   279,     1,    19,    40,    68,   102,   120,   196,
     210,   213,   223,   227,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   318,     1,    42,    82,   127,
     375,   376,   377,   378,   379,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   232,   521,   231,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   251,     1,   102,   220,   396,   397,
     398,   399,   231,   234,   232,   290,   169,     1,   102,   162,
     180,   194,   282,   283,   284,   285,   286,   287,   234,   232,
     382,     1,   102,   220,   223,   386,   387,   388,   389,   390,
     125,   125,   125,   231,   110,   110,   241,   205,   205,   110,
     241,   241,   241,   110,   241,   241,   110,   110,   110,   110,
     231,   231,   234,   234,   234,   341,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   325,   231,
     234,   234,   234,   234,   234,   234,   417,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   406,   234,   234,   232,
     434,   125,   231,   234,   234,   232,   444,   205,   241,   110,
     241,   241,   205,   110,   241,   205,   110,   110,   110,   205,
     205,   241,   110,   110,   110,   110,   241,   110,   110,   110,
     110,   205,   234,   234,   205,   241,   241,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   110,   241,   241,   241,
     205,   110,   231,   231,   234,   234,   367,   234,   234,   234,
     234,   234,   232,   361,   234,   234,   232,   428,   231,   234,
     234,   347,   234,   232,   351,   125,   125,   231,   231,   234,
     234,   232,   277,   231,   234,   234,   319,   234,   234,   315,
     234,   234,   234,   234,   232,   305,   231,   234,   234,   234,
     232,   376,   205,   205,   241,   125,   205,   125,   205,   205,
     205,   231,   110,   125,   205,   125,   110,   110,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   231,   231,
     234,   400,   232,   397,   205,   231,   233,   231,   234,   234,
     234,   234,   232,   283,   125,   231,   231,   234,   391,   234,
     232,   387,   231,   231,   231,   231,   136,   137,   138,   139,
     140,   141,   142,   240,   241,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   110,
     110,   241,   234,   110,   241,   110,   241,   125,   110,   110,
     110,   241,   110,   243,   243,   231,   125,   173,   174,   125,
     205,   125,   125,   234,   125,   125,   110,   125,   125,   241,
     125,   125,   231,   125,   125,   231,   231,   125,   125,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,    43,    50,   159,   160,   161,
     164,   165,   167,   168,   170,   172,   175,   177,   178,   183,
     187,   191,   192,   193,   197,   202,   495,   496,    43,    50,
      52,    53,   159,   160,   161,   164,   165,   167,   168,   170,
     172,   175,   177,   178,   183,   187,   191,   192,   193,   197,
     202,   491,   492,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   125,   205,   234,   125,   110,   125,   125,   125,   231,
     125,   125,   231,   125,   125,   234,   110,   354,   355,   231,
     231,   231,   125,   125,   231,   125,   205,   234,   125,   125,
     234,   125,   205,   125,   125,   231,   125,   125,   125,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   125,   234,   231,   231,     1,
     102,   190,   220,   294,   295,   296,   297,   298,   125,   125,
     125,   125,   231,   231,   125,   234,   125,   231,   240,   240,
     240,   240,   240,   240,   240,   231,   231,   231,    54,   126,
     342,   343,   231,   231,   231,   231,   231,   231,   231,   231,
     231,    11,    12,    13,   242,   243,   231,   231,   231,   231,
     231,   231,   231,   231,   231,     8,   195,   418,   419,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   235,   231,   235,   231,   231,    15,    41,    74,
     103,   104,   109,   134,   204,   230,   368,   369,   231,   231,
     231,   231,   231,   231,   231,   231,   231,    50,   185,   195,
     348,   349,   219,   235,   353,   231,   231,   231,   231,     4,
      20,    21,    31,    70,    71,    73,    99,   107,   130,   132,
     133,   149,   166,   171,   175,   179,   184,   188,   198,   200,
     201,   203,   221,   229,   320,   321,   231,   231,    43,    50,
      52,    53,   159,   160,   161,   164,   165,   167,   168,   170,
     172,   175,   177,   178,   183,   187,   191,   192,   193,   197,
     202,   316,   317,   231,   231,   231,   231,   231,   231,   231,
     231,    73,   133,   157,   166,   175,   198,   200,   201,   221,
     229,   401,   402,   231,   234,   234,   299,   232,   295,   231,
     231,   231,   231,   231,    73,   133,   157,   166,   175,   198,
     200,   201,   221,   229,   392,   393,   231,   231,   235,   242,
     242,   242,   231,   235,   496,   492,   231,   235,   231,   235,
     110,   355,   231,   236,   236,   236,   236,   236,   236,   231,
     235,   231,   235,   231,   235,   125,   199,   243,   234,   231,
     231,   235,   343,   419,   369,   349,   131,   133,   131,   133,
     131,   131,   321,   317,   402,   231,   231,   231,    71,    73,
     116,   133,   165,   166,   223,   229,   300,   301,   393,   231,
     235,   301
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
     251,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   269,
     269,   270,   270,   270,   270,   271,   272,   273,   275,   274,
     276,   276,   277,   277,   277,   278,   279,   281,   280,   282,
     282,   283,   283,   283,   283,   283,   284,   285,   286,   287,
     288,   289,   289,   290,   290,   290,   291,   293,   292,   294,
     294,   295,   295,   295,   295,   296,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     303,   302,   304,   304,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   315,   314,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     319,   318,   320,   320,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   323,   322,   324,   324,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   341,   340,   342,
     342,   343,   343,   345,   344,   347,   346,   348,   348,   349,
     349,   349,   350,   350,   351,   351,   351,   351,   351,   353,
     352,   354,   354,   355,   355,   356,   357,   359,   358,   360,
     360,   361,   361,   361,   361,   361,   361,   361,   361,   361,
     362,   363,   364,   365,   367,   366,   368,   368,   369,   369,
     369,   369,   369,   369,   369,   369,   369,   370,   371,   372,
     374,   373,   375,   375,   376,   376,   376,   376,   377,   378,
     379,   380,   381,   381,   382,   382,   383,   385,   384,   386,
     386,   387,   387,   387,   387,   388,   389,   391,   390,   392,
     392,   393,   393,   393,   393,   393,   393,   393,   393,   393,
     393,   395,   394,   396,   396,   397,   397,   397,   398,   400,
     399,   401,   401,   402,   402,   402,   402,   402,   402,   402,
     402,   402,   402,   404,   403,   405,   405,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   406,
     406,   406,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   415,   417,   416,   418,   418,   419,   419,   420,
     421,   422,   423,   424,   426,   425,   427,   427,   428,   428,
     428,   429,   430,   432,   431,   433,   433,   434,   434,   434,
     435,   436,   437,   438,   438,   439,   439,   440,   442,   441,
     443,   443,   444,   444,   444,   445,   446,   447,   448,   448,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   490,   489,   491,   491,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   494,   493,   495,   495,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   497,   498,   499,
     500,   501,   502,   502,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   520,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530
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
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     2,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     0,     6,     0,     5,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     2,     0,
       5,     3,     1,     1,     3,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 398 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 399 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 409 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 426 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2942 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 432 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2951 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 2963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 473 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2975 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 482 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2987 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 491 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 2999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 500 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3011 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 509 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3023 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 518 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 527 "conf_parser.y" /* yacc.c:1652  */
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
#line 3053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 542 "conf_parser.y" /* yacc.c:1652  */
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
#line 3071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 557 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 567 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p = strchr(yylval.string, ' ');

    if (p)
      *p = '\0';

    xfree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3101 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 581 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3113 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 590 "conf_parser.y" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);

    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3139 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 613 "conf_parser.y" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3165 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 636 "conf_parser.y" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3191 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 659 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3200 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 677 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 686 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 695 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 708 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 712 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3262 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 729 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 735 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3280 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 745 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3289 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 749 "conf_parser.y" /* yacc.c:1652  */
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
#line 3307 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 767 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 773 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3325 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 779 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3334 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 785 "conf_parser.y" /* yacc.c:1652  */
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
#line 3355 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 813 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3364 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 819 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3373 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 128:
#line 823 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3386 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 839 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3397 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 847 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3405 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 850 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3413 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 855 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 862 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3431 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 866 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3440 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 870 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3449 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 874 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3458 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 878 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3467 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 882 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3476 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 886 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3485 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3494 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 900 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3506 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 907 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node;

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
#line 3565 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 976 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3574 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 982 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 988 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3592 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 994 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1000 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1011 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1017 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 3638 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1028 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3647 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1034 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3656 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1041 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3665 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1045 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3674 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1049 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3683 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1053 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3692 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1057 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3701 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1061 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3710 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1065 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3719 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1069 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3728 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1073 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3737 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1077 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3746 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1081 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1085 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3764 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1089 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1093 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3782 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1097 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3791 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1101 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3800 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1105 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3809 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1109 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3818 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1113 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3827 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1117 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3836 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1121 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3845 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1125 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3854 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1129 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3863 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1135 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3872 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1142 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3881 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1146 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3890 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1150 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1154 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3908 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1158 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1162 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3926 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1166 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3935 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1170 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3944 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1174 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3953 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1178 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3962 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1182 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3971 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1186 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3980 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1190 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3989 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1194 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3998 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1198 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4007 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1202 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4016 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1206 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4025 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1210 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4034 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1214 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4043 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1218 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4052 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1222 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4061 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1226 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4070 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1230 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4079 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1234 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4088 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1238 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4097 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1242 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4106 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1246 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4115 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1250 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4124 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1254 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4133 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 1264 "conf_parser.y" /* yacc.c:1652  */
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
#line 4150 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 234:
#line 1276 "conf_parser.y" /* yacc.c:1652  */
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
#line 4198 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1339 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1345 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4216 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1351 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4225 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1357 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4234 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1363 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4243 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1369 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4252 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1375 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4261 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1381 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4270 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1387 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4280 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1394 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4289 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1400 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4298 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1406 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4307 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1412 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4319 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1421 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4331 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1430 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4340 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1437 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4349 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1441 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4358 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1451 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4367 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1457 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4375 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1463 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4384 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1467 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4393 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1471 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4402 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1479 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4408 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1484 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4426 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1497 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_TLS
    if (block_state.flags.value & LISTENER_TLS)
    {
      conf_error_report("TLS not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4446 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1514 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4455 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1520 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4464 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1530 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4473 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1534 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node;

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
    conf->port = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
#line 4519 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1588 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4528 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1594 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4537 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1600 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4546 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
#line 1606 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4560 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1617 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4569 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1624 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4578 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1628 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4587 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1632 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4596 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1636 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4605 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1640 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4614 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1644 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4623 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1648 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4632 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1652 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4641 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1656 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4650 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1662 "conf_parser.y" /* yacc.c:1652  */
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
#line 4667 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1676 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4679 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1685 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4691 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1698 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4703 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1705 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4714 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 338:
#line 1716 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4723 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1722 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4732 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1728 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4741 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 346:
#line 1743 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1759 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4772 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1770 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4787 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 355:
#line 1785 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4796 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1791 "conf_parser.y" /* yacc.c:1652  */
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
#line 4818 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1810 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4827 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 361:
#line 1817 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4836 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1821 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4845 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1825 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4854 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1829 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4863 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1833 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4872 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1837 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4881 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1841 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4890 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1845 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1849 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4908 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1853 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1872 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4944 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 378:
#line 1885 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4953 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4962 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 383:
#line 1898 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4971 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4980 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1906 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4989 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1910 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 4998 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1914 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5007 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1918 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5016 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1922 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5025 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1926 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5034 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1930 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5043 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1934 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5052 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1944 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5067 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
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
  conf_dns_lookup(conf);
}
#line 5138 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 413:
#line 2040 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5147 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5156 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2052 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5165 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5174 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2064 "conf_parser.y" /* yacc.c:1652  */
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
#line 5190 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2077 "conf_parser.y" /* yacc.c:1652  */
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
#line 5206 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2096 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5224 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5233 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5242 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2112 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5250 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 427:
#line 2118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5259 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5268 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2128 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5282 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2139 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5291 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2145 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5300 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5309 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2157 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2172 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2176 "conf_parser.y" /* yacc.c:1652  */
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
#line 5355 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 441:
#line 2199 "conf_parser.y" /* yacc.c:1652  */
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
#line 5378 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5387 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2229 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5396 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2233 "conf_parser.y" /* yacc.c:1652  */
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
#line 5420 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 450:
#line 2257 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5429 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2263 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5438 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 457:
#line 2278 "conf_parser.y" /* yacc.c:1652  */
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
#line 5455 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2295 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5464 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2299 "conf_parser.y" /* yacc.c:1652  */
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
#line 5484 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 465:
#line 2319 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5493 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2325 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5502 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 516:
#line 2386 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5510 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2391 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5518 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2396 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5526 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2401 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5534 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2406 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5542 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2411 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5550 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2416 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5558 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2421 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5566 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2426 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5574 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2431 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5582 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2436 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5590 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2441 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5598 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2446 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5606 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2451 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5614 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2456 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5622 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2461 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5630 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2466 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5638 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2471 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5646 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2476 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5654 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2481 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5662 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2486 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5670 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2491 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5678 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2496 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5686 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2501 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5694 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2506 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5702 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2511 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5710 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2516 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5718 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2521 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5726 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2526 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5734 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2531 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5742 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2536 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5750 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2541 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5758 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2546 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5766 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2551 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5774 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2556 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5782 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2561 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5790 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2566 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5798 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2571 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5806 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2576 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5814 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2581 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5822 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 559:
#line 2587 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5830 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2590 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5838 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2593 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2596 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5854 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2599 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5862 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2602 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5870 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2605 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5878 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2608 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2611 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5894 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2614 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5902 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2617 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5910 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2620 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2623 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5926 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2626 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5934 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2629 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5942 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2632 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5950 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2635 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5958 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2638 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5966 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2641 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5974 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2644 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5982 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2647 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 5990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2650 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 5998 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2653 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6006 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2658 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6014 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 586:
#line 2664 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6022 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2667 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6030 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2670 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6038 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2673 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6046 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2676 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6054 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2679 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2682 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6070 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2685 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6078 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2688 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6086 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2691 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6094 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2694 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6102 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2697 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6110 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2700 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6118 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2703 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6126 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2706 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6134 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2709 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6142 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2712 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6150 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2715 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6158 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2718 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6166 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2721 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6174 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2724 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6182 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2729 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6190 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2734 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6198 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2739 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6206 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2744 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6214 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 630:
#line 2773 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6222 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2778 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6230 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2783 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6238 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2788 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6246 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2793 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2798 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6262 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2803 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6270 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2808 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6278 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2813 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6286 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2818 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6294 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2823 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6302 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2828 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6310 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2833 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6318 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2838 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6326 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2843 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6334 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 658:
#line 2866 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6343 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2872 "conf_parser.y" /* yacc.c:1652  */
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
#line 6362 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2888 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6374 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6383 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2903 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6392 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2909 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6413 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2924 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2930 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6431 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6435 "conf_parser.c" /* yacc.c:1652  */
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
