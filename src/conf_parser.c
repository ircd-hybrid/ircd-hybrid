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
    CLIENT = 275,
    CLOSE = 276,
    CONNECT = 277,
    CONNECTFREQ = 278,
    CYCLE_ON_HOST_CHANGE = 279,
    DEFAULT_FLOODCOUNT = 280,
    DEFAULT_FLOODTIME = 281,
    DEFAULT_JOIN_FLOOD_COUNT = 282,
    DEFAULT_JOIN_FLOOD_TIME = 283,
    DEFAULT_MAX_CLIENTS = 284,
    DEFER = 285,
    DENY = 286,
    DESCRIPTION = 287,
    DIE = 288,
    DISABLE_AUTH = 289,
    DISABLE_FAKE_CHANNELS = 290,
    DISABLE_REMOTE_COMMANDS = 291,
    DLINE_MIN_CIDR = 292,
    DLINE_MIN_CIDR6 = 293,
    DOTS_IN_IDENT = 294,
    EMAIL = 295,
    ENABLE_EXTBANS = 296,
    ENCRYPTED = 297,
    EXCEED_LIMIT = 298,
    EXEMPT = 299,
    EXPIRATION = 300,
    FAILED_OPER_NOTICE = 301,
    FLATTEN_LINKS = 302,
    FLATTEN_LINKS_DELAY = 303,
    FLATTEN_LINKS_FILE = 304,
    GECOS = 305,
    GENERAL = 306,
    HIDDEN = 307,
    HIDDEN_NAME = 308,
    HIDE_CHANS = 309,
    HIDE_IDLE = 310,
    HIDE_IDLE_FROM_OPERS = 311,
    HIDE_SERVER_IPS = 312,
    HIDE_SERVERS = 313,
    HIDE_SERVICES = 314,
    HOST = 315,
    HUB = 316,
    HUB_MASK = 317,
    INVISIBLE_ON_CONNECT = 318,
    INVITE_CLIENT_COUNT = 319,
    INVITE_CLIENT_TIME = 320,
    INVITE_DELAY_CHANNEL = 321,
    INVITE_EXPIRE_TIME = 322,
    IP = 323,
    IRCD_AUTH = 324,
    IRCD_FLAGS = 325,
    IRCD_SID = 326,
    JOIN = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KLINE_MIN_CIDR = 332,
    KLINE_MIN_CIDR6 = 333,
    KNOCK_CLIENT_COUNT = 334,
    KNOCK_CLIENT_TIME = 335,
    KNOCK_DELAY_CHANNEL = 336,
    LEAF_MASK = 337,
    LISTEN = 338,
    MASK = 339,
    MAX_ACCEPT = 340,
    MAX_BANS = 341,
    MAX_BANS_LARGE = 342,
    MAX_CHANNELS = 343,
    MAX_IDLE = 344,
    MAX_INVITES = 345,
    MAX_NICK_CHANGES = 346,
    MAX_NICK_LENGTH = 347,
    MAX_NICK_TIME = 348,
    MAX_NUMBER = 349,
    MAX_TARGETS = 350,
    MAX_TOPIC_LENGTH = 351,
    MAX_WATCH = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESCRIPTION = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_OPER_FLOOD = 365,
    NO_TILDE = 366,
    NUMBER = 367,
    NUMBER_PER_CIDR = 368,
    NUMBER_PER_IP_GLOBAL = 369,
    NUMBER_PER_IP_LOCAL = 370,
    OPER_ONLY_UMODES = 371,
    OPER_UMODES = 372,
    OPERATOR = 373,
    OPERS_BYPASS_CALLERID = 374,
    PACE_WAIT = 375,
    PACE_WAIT_SIMPLE = 376,
    PASSWORD = 377,
    PATH = 378,
    PING_COOKIE = 379,
    PING_TIME = 380,
    PORT = 381,
    QSTRING = 382,
    RANDOM_IDLE = 383,
    REASON = 384,
    REDIRPORT = 385,
    REDIRSERV = 386,
    REHASH = 387,
    REMOTE = 388,
    REMOTEBAN = 389,
    RESV = 390,
    RESV_EXEMPT = 391,
    RSA_PRIVATE_KEY_FILE = 392,
    SECONDS = 393,
    MINUTES = 394,
    HOURS = 395,
    DAYS = 396,
    WEEKS = 397,
    MONTHS = 398,
    YEARS = 399,
    SEND_PASSWORD = 400,
    SENDQ = 401,
    SERVERHIDE = 402,
    SERVERINFO = 403,
    SHORT_MOTD = 404,
    SPOOF = 405,
    SQUIT = 406,
    STATS_E_DISABLED = 407,
    STATS_I_OPER_ONLY = 408,
    STATS_K_OPER_ONLY = 409,
    STATS_M_OPER_ONLY = 410,
    STATS_O_OPER_ONLY = 411,
    STATS_P_OPER_ONLY = 412,
    STATS_U_OPER_ONLY = 413,
    T_ALL = 414,
    T_BIND = 415,
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
    T_FLOOD = 426,
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
    T_TARGET = 450,
    T_TLS = 451,
    T_UMODES = 452,
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
#define CLIENT 275
#define CLOSE 276
#define CONNECT 277
#define CONNECTFREQ 278
#define CYCLE_ON_HOST_CHANGE 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_FLOODTIME 281
#define DEFAULT_JOIN_FLOOD_COUNT 282
#define DEFAULT_JOIN_FLOOD_TIME 283
#define DEFAULT_MAX_CLIENTS 284
#define DEFER 285
#define DENY 286
#define DESCRIPTION 287
#define DIE 288
#define DISABLE_AUTH 289
#define DISABLE_FAKE_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DLINE_MIN_CIDR 292
#define DLINE_MIN_CIDR6 293
#define DOTS_IN_IDENT 294
#define EMAIL 295
#define ENABLE_EXTBANS 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define EXPIRATION 300
#define FAILED_OPER_NOTICE 301
#define FLATTEN_LINKS 302
#define FLATTEN_LINKS_DELAY 303
#define FLATTEN_LINKS_FILE 304
#define GECOS 305
#define GENERAL 306
#define HIDDEN 307
#define HIDDEN_NAME 308
#define HIDE_CHANS 309
#define HIDE_IDLE 310
#define HIDE_IDLE_FROM_OPERS 311
#define HIDE_SERVER_IPS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define INVISIBLE_ON_CONNECT 318
#define INVITE_CLIENT_COUNT 319
#define INVITE_CLIENT_TIME 320
#define INVITE_DELAY_CHANNEL 321
#define INVITE_EXPIRE_TIME 322
#define IP 323
#define IRCD_AUTH 324
#define IRCD_FLAGS 325
#define IRCD_SID 326
#define JOIN 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_MIN_CIDR 332
#define KLINE_MIN_CIDR6 333
#define KNOCK_CLIENT_COUNT 334
#define KNOCK_CLIENT_TIME 335
#define KNOCK_DELAY_CHANNEL 336
#define LEAF_MASK 337
#define LISTEN 338
#define MASK 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_BANS_LARGE 342
#define MAX_CHANNELS 343
#define MAX_IDLE 344
#define MAX_INVITES 345
#define MAX_NICK_CHANGES 346
#define MAX_NICK_LENGTH 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_TOPIC_LENGTH 351
#define MAX_WATCH 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESCRIPTION 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER 367
#define NUMBER_PER_CIDR 368
#define NUMBER_PER_IP_GLOBAL 369
#define NUMBER_PER_IP_LOCAL 370
#define OPER_ONLY_UMODES 371
#define OPER_UMODES 372
#define OPERATOR 373
#define OPERS_BYPASS_CALLERID 374
#define PACE_WAIT 375
#define PACE_WAIT_SIMPLE 376
#define PASSWORD 377
#define PATH 378
#define PING_COOKIE 379
#define PING_TIME 380
#define PORT 381
#define QSTRING 382
#define RANDOM_IDLE 383
#define REASON 384
#define REDIRPORT 385
#define REDIRSERV 386
#define REHASH 387
#define REMOTE 388
#define REMOTEBAN 389
#define RESV 390
#define RESV_EXEMPT 391
#define RSA_PRIVATE_KEY_FILE 392
#define SECONDS 393
#define MINUTES 394
#define HOURS 395
#define DAYS 396
#define WEEKS 397
#define MONTHS 398
#define YEARS 399
#define SEND_PASSWORD 400
#define SENDQ 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define SHORT_MOTD 404
#define SPOOF 405
#define SQUIT 406
#define STATS_E_DISABLED 407
#define STATS_I_OPER_ONLY 408
#define STATS_K_OPER_ONLY 409
#define STATS_M_OPER_ONLY 410
#define STATS_O_OPER_ONLY 411
#define STATS_P_OPER_ONLY 412
#define STATS_U_OPER_ONLY 413
#define T_ALL 414
#define T_BIND 415
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
#define T_FLOOD 426
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
#define T_TARGET 450
#define T_TLS 451
#define T_UMODES 452
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
#define YYLAST   1377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  662
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1308

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
    1092,  1096,  1100,  1104,  1108,  1112,  1116,  1120,  1127,  1126,
    1132,  1132,  1133,  1137,  1141,  1145,  1149,  1153,  1157,  1161,
    1165,  1169,  1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,
    1205,  1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,
    1245,  1256,  1255,  1311,  1311,  1312,  1313,  1314,  1315,  1316,
    1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,  1326,
    1327,  1329,  1335,  1341,  1347,  1353,  1359,  1365,  1371,  1377,
    1384,  1390,  1396,  1402,  1411,  1421,  1420,  1426,  1426,  1427,
    1431,  1442,  1441,  1448,  1447,  1452,  1452,  1453,  1457,  1461,
    1465,  1469,  1475,  1475,  1476,  1476,  1476,  1476,  1476,  1478,
    1478,  1480,  1480,  1482,  1495,  1512,  1518,  1529,  1528,  1575,
    1575,  1576,  1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,
    1586,  1592,  1598,  1604,  1616,  1615,  1621,  1621,  1622,  1626,
    1630,  1634,  1638,  1642,  1646,  1650,  1654,  1660,  1674,  1683,
    1697,  1696,  1711,  1711,  1712,  1712,  1712,  1712,  1714,  1720,
    1726,  1736,  1738,  1738,  1739,  1739,  1741,  1758,  1757,  1780,
    1780,  1781,  1781,  1781,  1781,  1783,  1789,  1809,  1808,  1814,
    1814,  1815,  1819,  1823,  1827,  1831,  1835,  1839,  1843,  1847,
    1851,  1862,  1861,  1880,  1880,  1881,  1881,  1881,  1883,  1890,
    1889,  1895,  1895,  1896,  1900,  1904,  1908,  1912,  1916,  1920,
    1924,  1928,  1932,  1943,  1942,  2020,  2020,  2021,  2022,  2023,
    2024,  2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,
    2034,  2035,  2036,  2038,  2044,  2050,  2056,  2062,  2075,  2088,
    2094,  2100,  2104,  2111,  2110,  2115,  2115,  2116,  2120,  2126,
    2137,  2143,  2149,  2155,  2171,  2170,  2194,  2194,  2195,  2195,
    2195,  2197,  2217,  2228,  2227,  2252,  2252,  2253,  2253,  2253,
    2255,  2261,  2271,  2273,  2273,  2274,  2274,  2276,  2294,  2293,
    2314,  2314,  2315,  2315,  2315,  2317,  2323,  2333,  2335,  2335,
    2336,  2337,  2338,  2339,  2340,  2341,  2342,  2343,  2344,  2345,
    2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,  2354,  2355,
    2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,  2364,  2365,
    2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,  2374,  2375,
    2376,  2377,  2378,  2379,  2380,  2381,  2384,  2389,  2394,  2399,
    2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,  2449,
    2454,  2459,  2464,  2469,  2474,  2479,  2484,  2489,  2494,  2499,
    2504,  2509,  2514,  2519,  2524,  2529,  2534,  2539,  2544,  2549,
    2554,  2559,  2564,  2569,  2574,  2580,  2579,  2584,  2584,  2585,
    2588,  2591,  2594,  2597,  2600,  2603,  2606,  2609,  2612,  2615,
    2618,  2621,  2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,
    2651,  2650,  2655,  2655,  2656,  2659,  2662,  2665,  2668,  2671,
    2674,  2677,  2680,  2683,  2686,  2689,  2692,  2695,  2698,  2701,
    2704,  2707,  2710,  2715,  2720,  2725,  2730,  2739,  2741,  2741,
    2742,  2743,  2744,  2745,  2746,  2747,  2748,  2749,  2750,  2751,
    2752,  2753,  2754,  2755,  2756,  2757,  2759,  2764,  2769,  2774,
    2779,  2784,  2789,  2794,  2799,  2804,  2809,  2814,  2819,  2824,
    2829,  2838,  2840,  2840,  2841,  2842,  2843,  2844,  2845,  2846,
    2847,  2848,  2849,  2850,  2852,  2858,  2874,  2883,  2889,  2895,
    2901,  2910,  2916
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
  "CLIENT", "CLOSE", "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE",
  "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME", "DEFAULT_JOIN_FLOOD_COUNT",
  "DEFAULT_JOIN_FLOOD_TIME", "DEFAULT_MAX_CLIENTS", "DEFER", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
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
  "NETWORK_DESCRIPTION", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD",
  "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP_GLOBAL",
  "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES", "OPER_UMODES", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD",
  "PATH", "PING_COOKIE", "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE",
  "REASON", "REDIRPORT", "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN",
  "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SQUIT",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_CALLERID", "T_CCONN",
  "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FLOOD", "T_GLOBOPS", "T_INVISIBLE",
  "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE", "T_NONONREG",
  "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET", "T_SHARED", "T_SIZE",
  "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_TARGET", "T_TLS", "T_UMODES",
  "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "T_WALLOPS", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT", "THROTTLE_TIME",
  "TIMEOUT", "TLS_CERTIFICATE_FILE", "TLS_CERTIFICATE_FINGERPRINT",
  "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES", "TLS_CONNECTION_REQUIRED",
  "TLS_DH_PARAM_FILE", "TLS_MESSAGE_DIGEST_ALGORITHM",
  "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept",
  "conf", "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_tls_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_tls_dh_param_file",
  "serverinfo_tls_cipher_list", "serverinfo_tls_cipher_suites",
  "serverinfo_tls_message_digest_algorithm",
  "serverinfo_tls_supported_groups", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_description", "serverinfo_default_max_clients",
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

#define YYPACT_NINF -851

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-851)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -851,   615,  -851,  -122,  -201,  -188,  -851,  -851,  -851,  -185,
    -851,  -178,  -851,  -851,  -851,  -175,  -851,  -851,  -851,  -160,
    -158,  -851,  -138,  -851,  -136,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,   355,   901,   -88,   -81,   -79,   123,   -67,   365,   -61,
     -58,   -27,   187,   -24,   -19,   -18,   783,   471,   -12,    20,
      -9,    15,    10,  -207,    49,    50,    52,     2,  -851,  -851,
    -851,  -851,  -851,    60,    66,    74,    80,    86,   100,   104,
     105,   106,   116,   117,   129,   130,   131,   133,     3,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,   621,   532,    26,  -851,   135,
      13,  -851,  -851,   176,  -851,   136,   142,   146,   151,   152,
     159,   160,   162,   163,   167,   172,   178,   179,   180,   181,
     182,   184,   185,   186,   189,   190,   192,   193,   195,   196,
    -851,  -851,   198,   201,   202,   204,   207,   210,   211,   212,
     213,   218,   221,   223,   232,   233,   234,   235,   236,   237,
      40,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   303,    70,   420,
      82,   239,   240,    35,  -851,  -851,  -851,    12,   318,   308,
    -851,   243,   244,   249,   253,   257,   258,   259,   260,   261,
       4,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,   118,   264,   267,   270,   273,   275,   276,   278,   279,
     290,   291,   295,   296,   300,   302,   304,   305,   115,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,   122,   153,   306,     8,
    -851,  -851,  -851,    83,    22,  -851,   309,    28,  -851,  -851,
     112,  -851,   372,   379,   389,   313,  -851,   437,   440,   356,
     357,   448,   440,   440,   440,   452,   440,   440,   453,   454,
     456,   457,   339,  -851,   342,   343,   346,   347,  -851,   351,
     353,   354,   369,   370,   371,   377,   378,   383,   384,   386,
     150,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   358,   387,   390,
     391,   393,   394,   396,  -851,   398,   399,   401,   406,   407,
     409,   411,   414,   199,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,   416,   418,    19,  -851,  -851,  -851,   463,   375,  -851,
    -851,   419,   422,    24,  -851,  -851,  -851,   408,   440,   511,
     440,   440,   444,   542,   440,   458,   545,   549,   550,   462,
     464,   440,   556,   558,   559,   560,   440,   562,   567,   569,
     581,   489,   461,   467,   497,   440,   440,   498,   500,   501,
     502,   503,   506,   507,   509,   515,   604,   440,   440,   440,
     517,   611,   493,  -851,   495,   494,   505,  -851,   510,   519,
     522,   523,   524,   231,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,   525,   526,    84,  -851,  -851,  -851,
     496,   527,   530,  -851,   531,  -851,   111,  -851,  -851,  -851,
    -851,  -851,   602,   605,   518,  -851,   520,   534,   535,    17,
    -851,  -851,  -851,   539,   537,   538,  -851,   540,   543,  -851,
     544,   547,   548,   551,    79,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,   555,   553,   557,   561,
     126,  -851,  -851,  -851,  -851,   536,   571,   440,   610,   583,
     639,   584,   585,   588,   563,  -851,  -851,   619,   669,   593,
     672,   688,   689,   676,   682,   685,   690,   695,   698,   699,
     700,   701,   707,   589,  -851,   612,   614,  -851,    58,  -851,
    -851,  -851,  -851,   640,   613,  -851,   582,   618,   616,   617,
     622,   623,   173,  -851,  -851,  -851,  -851,  -851,   719,   629,
    -851,   632,   631,  -851,   633,    59,  -851,  -851,  -851,  -851,
     642,   643,   644,  -851,   647,   415,   648,   649,   651,   652,
     653,   657,   660,   667,   674,   677,   679,   680,   683,   684,
    -851,  -851,   740,   741,   440,   636,   764,   440,   791,   440,
     786,   805,   806,   807,   440,   811,   811,   694,  -851,  -851,
     797,    96,   799,   722,   808,   810,   704,   812,   813,   820,
     814,   816,   440,   817,   818,   715,  -851,   821,   822,   716,
    -851,   720,  -851,   823,   825,   724,  -851,   725,   726,   727,
     729,   730,   732,   738,   739,   742,   743,   744,   745,   746,
     747,   748,   752,   753,   754,   755,   759,   761,   762,   763,
     765,   766,   728,   645,   767,   768,   769,   770,   771,   772,
     773,   774,   775,   776,   777,   778,   779,   780,   781,   782,
     784,   785,  -851,  -851,   826,   790,   737,   832,   852,   845,
     887,   890,   787,  -851,   892,   893,   792,  -851,  -851,   894,
     895,   793,   912,   794,  -851,   795,   798,  -851,  -851,   903,
     904,   801,  -851,  -851,   906,   829,   802,   908,   910,   804,
     913,   834,   914,   915,   815,  -851,  -851,   916,   917,   918,
     819,  -851,   824,   827,   828,   830,   831,   833,   835,   836,
     837,  -851,   838,   839,   840,   841,   842,   843,   844,   846,
     847,   848,   849,   850,   851,   853,   854,   855,  -851,  -851,
     920,   856,   857,  -851,   858,  -851,   121,  -851,   921,   922,
     924,   925,   860,  -851,   861,  -851,  -851,   926,   859,   927,
     863,  -851,  -851,  -851,  -851,  -851,   440,   440,   440,   440,
     440,   440,   440,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,   864,
     865,   866,   -28,   867,   868,   869,   870,   871,   872,   873,
     874,   875,   286,   876,   877,  -851,   878,   879,   880,   881,
     882,   883,   884,     9,   885,   886,   888,   889,   891,   896,
     897,   898,  -851,   899,   900,  -851,  -851,   902,   905,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -216,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -209,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   907,   909,   272,
     911,   919,   923,   928,   929,  -851,   930,   931,  -851,   932,
     933,   265,   809,   934,  -851,  -851,  -851,  -851,   935,   936,
    -851,   937,   939,   475,   940,   941,   693,   942,   943,   944,
     945,  -851,   946,   947,   948,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,   949,   554,  -851,  -851,   950,   951,   952,  -851,    42,
    -851,  -851,  -851,  -851,   953,   956,   957,   958,  -851,  -851,
     959,   733,   960,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -198,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   811,   811,   811,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -196,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,   728,  -851,
     645,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -159,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -143,  -851,
     964,   912,   961,  -851,  -851,  -851,  -851,  -851,  -851,   962,
    -851,   963,   965,  -851,  -851,   966,   967,  -851,  -851,   968,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -124,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   -97,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,   -66,  -851,  -851,
     938,  -100,   971,   969,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
     -51,  -851,  -851,  -851,   -28,  -851,  -851,  -851,  -851,     9,
    -851,  -851,  -851,   272,  -851,   265,  -851,  -851,  -851,   954,
     983,   988,   989,   990,   992,  -851,   475,  -851,   693,  -851,
     554,   975,   976,   977,   282,  -851,  -851,   733,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,   -23,  -851,  -851,  -851,   282,  -851
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   231,   393,   443,     0,
     458,     0,   297,   434,   271,     0,    98,   150,   330,     0,
       0,   371,     0,   107,     0,   347,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   625,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   609,
     624,   623,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   610,   611,   621,   622,     0,     0,     0,   456,     0,
       0,   454,   455,     0,   515,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     580,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,   470,   471,   513,   477,   514,   508,   509,   510,
     511,   481,   472,   473,   474,   475,   476,   478,   479,   480,
     482,   483,   512,   487,   488,   489,   490,   486,   485,   491,
     498,   499,   492,   493,   494,   484,   496,   506,   507,   504,
     505,   497,   495,   502,   503,   500,   501,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,   645,   646,   647,   648,   649,   651,   650,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   345,     0,     0,   343,   344,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   608,     0,     0,     0,     0,   265,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,   235,   238,   240,   241,   242,   243,   244,   245,
     246,   236,   237,   239,   247,   248,   249,     0,     0,     0,
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
       0,     0,     0,   273,     0,   285,     0,   283,   284,   286,
     287,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   198,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   333,   334,   335,   336,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   642,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   379,     0,   374,
     375,   376,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     342,     0,     0,   357,     0,     0,   350,   351,   352,   353,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   412,
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
       0,   641,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   377,
       0,     0,     0,   373,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   341,   354,     0,     0,     0,
       0,   349,    97,    96,    95,   639,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   640,   627,   626,   628,   629,
     630,   631,   632,   633,   634,   637,   638,   635,   636,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   232,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   394,     0,     0,   444,   457,     0,     0,   459,
     527,   531,   516,   517,   544,   520,   605,   606,   552,   521,
     522,   549,   526,   534,   525,   523,   524,   530,   529,   528,
     550,   518,   603,   604,   548,   602,   589,   598,   584,   585,
     586,   593,   601,   587,   595,   599,   590,   600,   591,   594,
     588,   597,   592,   596,     0,   583,   579,   563,   564,   565,
     575,   559,   560,   561,   570,   578,   562,   572,   576,   567,
     577,   568,   571,   566,   574,   569,   573,     0,   558,   545,
     543,   546,   551,   547,   536,   542,   541,   537,   538,   539,
     540,   553,   554,   533,   532,   535,   519,     0,     0,     0,
       0,     0,     0,     0,     0,   298,     0,     0,   435,     0,
       0,     0,   293,   289,   292,   272,    50,    51,     0,     0,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   151,     0,     0,     0,   331,   657,   654,   655,   656,
     661,   660,   662,   658,   659,    84,    81,    87,    80,    85,
      86,    79,    83,    82,    73,    72,    75,    76,    74,    77,
      78,     0,     0,   372,   126,     0,     0,     0,   138,     0,
     130,   131,   133,   132,     0,     0,     0,     0,   108,   346,
       0,     0,     0,   348,    31,    32,    33,    34,    35,    36,
      37,   260,   261,   255,   270,   269,     0,   268,   256,   264,
     257,   263,   251,   262,   254,   253,   252,    38,    38,    38,
      40,    39,   258,   259,   418,   421,   422,   432,   429,   414,
     430,   427,   428,     0,   426,   431,   413,   420,   417,   416,
     415,   419,   433,   450,   451,   465,   466,   581,     0,   556,
       0,   312,   313,   322,   318,   319,   321,   326,   323,   324,
     325,   320,     0,   317,   311,   329,   328,   327,   310,   442,
     441,   296,   295,   280,   281,   278,   279,   277,     0,   276,
       0,     0,     0,   105,   106,   172,   169,   218,   230,   205,
     214,     0,   203,   208,   224,     0,   217,   222,   228,   207,
     210,   219,   221,   225,   215,   223,   211,   229,   213,   220,
     209,   212,     0,   201,   165,   167,   197,   181,   182,   183,
     193,   177,   178,   179,   188,   196,   180,   190,   194,   185,
     195,   186,   189,   184,   192,   187,   191,     0,   176,   170,
     171,   166,   168,   340,   338,   339,   378,   383,   389,   392,
     385,   391,   386,   390,   388,   384,   387,     0,   382,   134,
       0,     0,     0,     0,   129,   117,   116,   118,   119,   355,
     361,   367,   370,   363,   369,   364,   368,   366,   362,   365,
       0,   360,   356,   266,     0,    41,    42,    43,   424,     0,
     582,   557,   315,     0,   274,     0,   294,   291,   290,     0,
       0,     0,     0,     0,     0,   199,     0,   174,     0,   380,
       0,     0,     0,     0,     0,   128,   358,     0,   267,   425,
     316,   275,   204,   227,   202,   226,   216,   206,   200,   175,
     381,   135,   137,   136,   148,   147,   143,   145,   149,   146,
     142,   144,     0,   141,   359,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -851,  -851,  -851,  -221,  -306,  -850,  -635,  -851,  -851,   970,
    -851,  -851,  -851,  -851,   788,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,   980,  -851,  -851,  -851,  -851,  -851,  -851,
     564,  -851,  -851,  -851,  -851,  -851,   478,  -851,  -851,  -851,
    -851,  -851,  -851,   862,  -851,  -851,  -851,  -851,    44,  -851,
    -851,  -851,  -851,  -851,  -180,  -851,  -851,  -851,   620,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -133,  -851,  -851,  -851,  -134,  -851,  -851,  -851,   803,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -107,  -851,  -851,  -851,
    -851,  -851,  -116,  -851,   655,  -851,  -851,  -851,     5,  -851,
    -851,  -851,  -851,  -851,   681,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -108,  -851,  -851,  -851,  -851,  -851,  -851,   625,
    -851,  -851,  -851,  -851,  -851,   955,  -851,  -851,  -851,  -851,
     552,  -851,  -851,  -851,  -851,  -851,  -129,  -851,  -851,  -851,
     590,  -851,  -851,  -851,  -851,  -121,  -851,  -851,  -851,   972,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,   -96,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,   706,  -851,  -851,  -851,  -851,  -851,   973,  -851,  -851,
    -851,  -851,  1032,  -851,  -851,  -851,  -851,   974,  -851,  -851,
    -851,  -851,   986,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,    47,  -851,  -851,  -851,    57,
    -851,  -851,  -851,  -851,  -851,  -851,  1085,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851,   978,  -851,  -851,  -851,  -851,  -851,
    -851,  -851,  -851,  -851
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   823,   824,  1080,  1081,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1039,  1040,  1041,
    1042,  1043,  1222,  1302,  1303,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1197,
    1198,   525,   746,  1172,  1173,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1066,  1067,    35,    61,   485,
     731,  1138,  1139,   486,   487,   488,  1142,   983,   984,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1122,  1123,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1240,  1241,    40,    68,   568,
     569,   570,   571,   791,  1217,  1218,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1093,  1094,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   433,   947,   948,   212,   432,   924,   925,
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
     853,   854,   606,    73,    82,   230,   610,   611,   612,   287,
     614,   615,   852,   496,   118,  1107,   295,  1091,   496,  1108,
     390,   287,  1109,   577,   301,   400,  1110,   390,  1064,   295,
      83,    84,    51,  1243,    74,  1248,   220,  1244,    85,  1249,
     231,   124,    75,  1035,    86,    52,   125,   126,    56,   127,
     128,   232,   233,   234,   129,    58,   235,   236,    62,   565,
     591,   237,   238,   239,   130,   131,   132,    87,    88,    89,
      90,   473,  1252,    66,   133,    67,  1253,   134,   135,   136,
     503,   119,    91,    92,    93,   473,   137,   391,  1254,    94,
      95,    96,  1255,    97,   391,    69,   497,    71,   504,  1272,
    1065,   497,   668,   138,   670,   671,    76,  1265,   674,    49,
      50,  1266,   480,   591,   139,   681,   251,   140,   141,   296,
     686,   505,  1035,   565,   118,   142,   578,   526,   401,   695,
     696,   143,   296,   144,  1267,   145,   221,   146,  1268,   147,
     148,   707,   708,   709,   252,   115,  1036,   253,   392,   506,
     149,   324,   116,   402,   117,   392,   150,   151,   222,   152,
     153,   154,   566,   592,   155,  1269,   123,   325,   326,  1270,
     527,   481,   217,   327,   577,   218,   254,   400,  -127,   482,
    1276,   483,   498,   507,  1277,   579,   255,   498,   220,   156,
    -127,   119,   157,   158,   159,   160,   161,   162,   163,   474,
     357,   508,   358,   580,   359,  1092,   219,   256,  1305,   227,
     528,   257,  1306,   474,   228,   229,   592,   581,   360,   258,
     328,   286,   259,   260,   294,  1036,   566,  1245,  1246,  1247,
     288,   764,   454,  1037,   305,   322,   544,   484,   329,   330,
     574,   361,   288,   300,   331,   398,   164,   165,   332,   741,
     455,   659,   261,   576,   333,   529,   665,   166,   167,   362,
     589,   363,  1038,   334,   335,   336,   168,   494,   169,   364,
     857,   858,   452,   456,  1223,   337,   509,   578,   567,   593,
     401,   365,   594,   302,   303,  1133,   304,  1113,   221,   510,
     792,   810,   511,   475,   307,  1134,   338,  1077,  1078,  1079,
     308,   457,   512,   366,   454,   402,   513,   475,   309,   526,
     222,   754,  1037,   491,   310,  1114,   726,  1135,   841,   503,
     311,   844,   455,   846,   262,   367,   263,   264,   851,   265,
     266,   267,   593,   339,   312,   594,   579,   504,   313,   314,
     315,  1038,   567,   733,   368,   456,   869,   563,  1115,   546,
     316,   317,   527,   458,   580,  1294,    73,  1295,   760,   369,
     505,   459,   460,   318,   319,   320,   124,   321,   581,   397,
     407,   125,   126,   457,   127,   128,   408,  1116,  1117,   129,
     409,   461,   637,  1118,   572,   410,   411,    74,   506,   130,
     131,   132,   528,   412,   413,    75,   414,   415,   852,   133,
    1296,   416,   134,   135,   136,   802,   417,   370,  1119,   371,
     372,   137,   418,   419,   420,   421,   422,  1297,   423,   424,
     425,   480,   507,   426,   427,   458,   428,   429,   138,   430,
     431,   655,   434,   459,   460,   435,   436,   529,   437,   139,
     508,   438,   140,   141,   439,   440,   441,   442,  1298,  1299,
     142,  1136,   443,   461,   462,   444,   143,   445,   144,    76,
     145,  1137,   146,   722,   147,   148,   446,   447,   448,   449,
     450,   451,   251,   492,   493,   149,  1120,   535,   536,  1147,
     481,   150,   151,   537,   152,   153,   154,   538,   482,   155,
     483,   539,   540,   541,   542,   543,  1148,  1149,   547,   600,
     252,   548,  1121,   253,   549,  1300,   601,   550,  1150,   551,
     552,  1301,   553,   554,   156,   509,   602,   157,   158,   159,
     160,   161,   162,   163,   555,   556,   462,   605,   510,   557,
     558,   511,   254,   357,   559,   358,   560,   359,   561,   562,
     573,   512,   255,   588,   603,   513,   484,  1151,  1152,   604,
    1153,   360,   605,   816,   817,   818,   819,   820,   821,   822,
     609,   607,   608,   256,   613,   616,   617,   257,   618,   619,
     620,   164,   165,   621,   361,   258,  1154,   622,   259,   260,
     623,   624,   166,   167,  1155,   626,  1273,   627,   628,   639,
     661,   168,   362,   169,   363,  1054,  1055,  1056,  1057,  1058,
    1059,  1060,   364,   629,   630,   631,   662,  1156,   261,  1157,
    1158,   632,   633,   667,   365,     2,     3,   634,   635,     4,
     636,   640,   324,   669,   641,   642,  1159,   643,   644,  1207,
     645,     5,   647,   648,     6,   649,   366,     7,   325,   326,
     650,   651,  1160,   652,   327,   653,     8,  1161,   654,   672,
     657,  1162,   658,   663,   673,  1163,   664,   676,   367,     9,
    1164,   677,   678,   675,  1165,    10,    11,   679,   682,   680,
     683,   684,   685,  1166,   687,  1167,  1168,   368,  1169,   688,
     262,   689,   263,   264,    12,   265,   266,   267,    13,  1208,
     926,   328,   369,   690,   691,   692,  1170,   927,    14,   928,
     929,   693,   694,   697,  1171,   698,   699,   700,   701,   329,
     330,   702,   703,  1209,   704,   331,   706,    15,    16,   332,
     705,  1210,   710,   711,   712,   333,   713,   728,   714,   735,
    1211,   772,   736,    17,   334,   335,   336,   765,  1176,   715,
     370,   762,   371,   372,   717,  1177,   337,  1178,  1179,   737,
      18,   738,  1212,   718,  1213,  1214,   719,   720,   721,   724,
     725,   729,    19,    20,   730,   732,   767,   338,   739,   740,
     743,   744,   745,   905,   747,  1215,   763,   748,   750,    21,
     906,   751,   752,  1216,   230,   753,   756,   757,   766,   768,
     769,   758,    22,   770,   771,   759,   773,    23,   774,   775,
     776,   777,    24,   778,   339,    25,   930,   931,  1230,   779,
     932,   933,   780,   934,   935,   796,   936,   781,   937,   231,
     788,   938,   782,   939,   940,   783,   784,   785,   786,   941,
     232,   233,   234,   942,   787,   235,   236,   943,   944,   945,
     237,   238,   239,   789,   795,   794,   804,   946,   790,   797,
     798,   799,   839,   840,  1180,  1181,   800,   801,  1182,  1183,
     805,  1184,  1185,   806,  1186,   807,  1187,   809,  1231,  1188,
     842,  1189,  1190,   812,   813,   814,   843,  1191,   815,   825,
     826,  1192,   827,   828,   829,  1193,  1194,  1195,   830,   907,
     908,   831,  1232,   909,   910,  1196,   911,   912,   832,   913,
    1233,   914,    82,   845,   915,   833,   916,   917,   834,  1234,
     835,   836,   918,   847,   837,   838,   919,   848,   849,   850,
     920,   921,   922,   852,   856,   855,   859,   860,    83,    84,
     923,  1235,   866,  1236,  1237,   861,    85,   862,   863,   864,
     865,   867,    86,   868,   870,   871,   872,   875,   873,   874,
     877,   876,   878,   967,  1238,   879,   880,   881,   882,   970,
     883,   884,  1239,   885,   971,    87,    88,    89,    90,   886,
     887,   969,   972,   888,   889,   890,   891,   892,   893,   894,
      91,    92,    93,   895,   896,   897,   898,    94,    95,    96,
     899,    97,   900,   901,   902,   968,   903,   904,   949,   950,
     951,   952,   953,   954,   955,   956,   957,   958,   959,   960,
     961,   962,   963,   964,   973,   965,   966,   974,   975,   976,
     977,   979,   980,   978,   982,   985,   986,   981,  1140,   987,
     988,   989,   990,   991,   992,   994,   993,   995,   996,   998,
     997,   999,  1000,  1002,  1003,  1004,  1001,  1031,  1044,  1045,
    1005,  1046,  1047,  1050,  1052,  1006,   564,   306,  1007,  1008,
     803,  1009,  1010,   742,  1011,  1271,  1012,  1013,  1014,  1015,
    1016,  1017,  1018,  1019,  1020,  1021,  1256,  1022,  1023,  1024,
    1025,  1026,  1027,  1224,  1028,  1029,  1030,  1282,  1033,  1034,
    1032,  1048,  1049,  1051,  1053,  1061,  1062,  1063,  1068,  1069,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1095,  1096,  1283,  1097,
    1098,  1284,  1099,  1286,  1285,  1287,  1307,  1100,  1101,  1102,
    1103,  1104,  1288,  1105,   755,  1289,  1106,  1278,  1111,  1281,
    1112,   734,  1124,   638,   723,  1280,  1257,   811,  1304,  1290,
    1125,   575,   399,  1279,  1126,   761,   453,  1251,   793,  1127,
    1128,  1129,  1130,  1131,  1132,  1250,  1143,  1144,  1145,  1141,
    1146,  1174,  1175,  1199,  1200,  1201,  1202,  1203,  1204,  1205,
    1206,  1219,   727,   323,  1225,  1220,  1221,  1226,  1227,  1228,
    1229,  1242,  1258,   495,     0,     0,     0,     0,  1259,  1260,
    1275,  1261,  1262,  1263,  1264,  1274,  1291,  1292,  1293,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   545,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   656,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   666
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,     1,   312,   313,   314,     1,
     316,   317,   112,     1,     1,   231,     1,     8,     1,   235,
       1,     1,   231,     1,   231,     1,   235,     1,    56,     1,
      27,    28,   233,   231,    32,   231,     1,   235,    35,   235,
      36,     1,    40,     1,    41,   233,     6,     7,   233,     9,
      10,    47,    48,    49,    14,   233,    52,    53,   233,     1,
       1,    57,    58,    59,    24,    25,    26,    64,    65,    66,
      67,     1,   231,   233,    34,   233,   235,    37,    38,    39,
       1,    68,    79,    80,    81,     1,    46,    68,   231,    86,
      87,    88,   235,    90,    68,   233,    84,   233,    19,   199,
     128,    84,   408,    63,   410,   411,   104,   231,   414,   231,
     232,   235,     1,     1,    74,   421,     1,    77,    78,   104,
     426,    42,     1,     1,     1,    85,   104,     1,   104,   435,
     436,    91,   104,    93,   231,    95,   101,    97,   235,    99,
     100,   447,   448,   449,    29,   233,   104,    32,   129,    70,
     110,     1,   233,   129,   233,   129,   116,   117,   123,   119,
     120,   121,   104,   104,   124,   231,   233,    17,    18,   235,
      44,    60,   233,    23,     1,   233,    61,     1,   170,    68,
     231,    70,   170,   104,   235,   163,    71,   170,     1,   149,
     170,    68,   152,   153,   154,   155,   156,   157,   158,   129,
       1,   122,     3,   181,     5,   196,   233,    92,   231,   233,
      84,    96,   235,   129,   233,   233,   104,   195,    19,   104,
      70,   233,   107,   108,   233,   104,   104,  1077,  1078,  1079,
     222,   537,     1,   191,   232,   232,   232,   126,    88,    89,
     232,    42,   222,   233,    94,   232,   206,   207,    98,   232,
      19,   232,   137,   170,   104,   129,   232,   217,   218,    60,
     232,    62,   220,   113,   114,   115,   226,   232,   228,    70,
     174,   175,   232,    42,   232,   125,   197,   104,   220,   220,
     104,    82,   223,   234,   234,    20,   234,    15,   101,   210,
     232,   232,   213,   223,   234,    30,   146,    11,    12,    13,
     234,    70,   223,   104,     1,   129,   227,   223,   234,     1,
     123,   232,   191,   231,   234,    43,   232,    52,   624,     1,
     234,   627,    19,   629,   209,   126,   211,   212,   634,   214,
     215,   216,   220,   183,   234,   223,   163,    19,   234,   234,
     234,   220,   220,   232,   145,    42,   652,   232,    76,   231,
     234,   234,    44,   122,   181,    73,     1,    75,   232,   160,
      42,   130,   131,   234,   234,   234,     1,   234,   195,   234,
     234,     6,     7,    70,     9,    10,   234,   105,   106,    14,
     234,   150,   232,   111,   231,   234,   234,    32,    70,    24,
      25,    26,    84,   234,   234,    40,   234,   234,   112,    34,
     118,   234,    37,    38,    39,   232,   234,   208,   136,   210,
     211,    46,   234,   234,   234,   234,   234,   135,   234,   234,
     234,     1,   104,   234,   234,   122,   234,   234,    63,   234,
     234,   232,   234,   130,   131,   234,   234,   129,   234,    74,
     122,   234,    77,    78,   234,   234,   234,   234,   166,   167,
      85,   186,   234,   150,   223,   234,    91,   234,    93,   104,
      95,   196,    97,   232,    99,   100,   234,   234,   234,   234,
     234,   234,     1,   234,   234,   110,   204,   234,   234,     4,
      60,   116,   117,   234,   119,   120,   121,   234,    68,   124,
      70,   234,   234,   234,   234,   234,    21,    22,   234,   127,
      29,   234,   230,    32,   234,   223,   127,   234,    33,   234,
     234,   229,   234,   234,   149,   197,   127,   152,   153,   154,
     155,   156,   157,   158,   234,   234,   223,   112,   210,   234,
     234,   213,    61,     1,   234,     3,   234,     5,   234,   234,
     234,   223,    71,   234,   231,   227,   126,    72,    73,   112,
      75,    19,   112,   138,   139,   140,   141,   142,   143,   144,
     112,   205,   205,    92,   112,   112,   112,    96,   112,   112,
     231,   206,   207,   231,    42,   104,   101,   234,   107,   108,
     234,   234,   217,   218,   109,   234,  1221,   234,   234,   231,
     127,   226,    60,   228,    62,   816,   817,   818,   819,   820,
     821,   822,    70,   234,   234,   234,   231,   132,   137,   134,
     135,   234,   234,   205,    82,     0,     1,   234,   234,     4,
     234,   234,     1,   112,   234,   234,   151,   234,   234,    75,
     234,    16,   234,   234,    19,   234,   104,    22,    17,    18,
     234,   234,   167,   234,    23,   234,    31,   172,   234,   205,
     234,   176,   234,   234,   112,   180,   234,   112,   126,    44,
     185,   112,   112,   205,   189,    50,    51,   205,   112,   205,
     112,   112,   112,   198,   112,   200,   201,   145,   203,   112,
     209,   112,   211,   212,    69,   214,   215,   216,    73,   135,
      45,    70,   160,   112,   205,   234,   221,    52,    83,    54,
      55,   234,   205,   205,   229,   205,   205,   205,   205,    88,
      89,   205,   205,   159,   205,    94,   112,   102,   103,    98,
     205,   167,   205,   112,   231,   104,   231,   231,   234,   127,
     176,   112,   127,   118,   113,   114,   115,   127,    45,   234,
     208,   205,   210,   211,   234,    52,   125,    54,    55,   231,
     135,   231,   198,   234,   200,   201,   234,   234,   234,   234,
     234,   234,   147,   148,   234,   234,   127,   146,   234,   234,
     231,   234,   234,    45,   234,   221,   205,   234,   234,   164,
      52,   234,   234,   229,     1,   234,   231,   234,   205,   205,
     205,   234,   177,   205,   231,   234,   127,   182,   205,   127,
     112,   112,   187,   127,   183,   190,   161,   162,    75,   127,
     165,   166,   127,   168,   169,   233,   171,   127,   173,    36,
     231,   176,   127,   178,   179,   127,   127,   127,   127,   184,
      47,    48,    49,   188,   127,    52,    53,   192,   193,   194,
      57,    58,    59,   231,   231,   205,   127,   202,   234,   231,
     234,   234,   112,   112,   161,   162,   234,   234,   165,   166,
     231,   168,   169,   231,   171,   234,   173,   234,   135,   176,
     234,   178,   179,   231,   231,   231,   112,   184,   231,   231,
     231,   188,   231,   231,   231,   192,   193,   194,   231,   161,
     162,   231,   159,   165,   166,   202,   168,   169,   231,   171,
     167,   173,     1,   112,   176,   231,   178,   179,   231,   176,
     231,   231,   184,   127,   231,   231,   188,   112,   112,   112,
     192,   193,   194,   112,   127,   231,   127,   205,    27,    28,
     202,   198,   112,   200,   201,   127,    35,   127,   234,   127,
     127,   127,    41,   127,   127,   127,   231,   231,   127,   127,
     127,   231,   127,   127,   221,   231,   231,   231,   231,   127,
     231,   231,   229,   231,   112,    64,    65,    66,    67,   231,
     231,   234,   127,   231,   231,   231,   231,   231,   231,   231,
      79,    80,    81,   231,   231,   231,   231,    86,    87,    88,
     231,    90,   231,   231,   231,   205,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   127,   231,   231,   127,   231,   127,
     127,   127,   127,   231,   112,   231,   231,   234,   219,   231,
     127,   127,   231,   127,   205,   127,   234,   127,   234,   205,
     127,   127,   127,   127,   127,   127,   231,   127,   127,   127,
     231,   127,   127,   127,   127,   231,   268,    77,   231,   231,
     582,   231,   231,   499,   231,   127,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   112,   231,   231,   231,
     231,   231,   231,  1039,   231,   231,   231,   133,   231,   231,
     234,   231,   231,   234,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   135,   231,
     231,   133,   231,   133,   135,   133,  1306,   231,   231,   231,
     231,   231,  1266,   231,   514,  1268,   231,  1244,   231,  1255,
     231,   486,   231,   340,   463,  1253,  1141,   595,  1277,  1270,
     231,   289,   120,  1249,   231,   530,   170,  1110,   568,   231,
     231,   231,   231,   231,   231,  1108,   231,   231,   231,   235,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   476,    98,   231,   234,   234,   231,   231,   231,
     231,   231,   231,   223,    -1,    -1,    -1,    -1,   236,   236,
     231,   236,   236,   236,   236,   234,   231,   231,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   240,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   403
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   238,     0,     1,     4,    16,    19,    22,    31,    44,
      50,    51,    69,    73,    83,   102,   103,   118,   135,   147,
     148,   164,   177,   182,   187,   190,   239,   244,   249,   268,
     274,   280,   288,   302,   322,   344,   358,   373,   380,   384,
     394,   403,   425,   431,   437,   441,   447,   501,   519,   231,
     232,   233,   233,   323,   404,   432,   233,   442,   233,   359,
     426,   345,   233,   275,   303,   374,   233,   233,   395,   233,
     281,   233,   385,     1,    32,    40,   104,   269,   270,   271,
     272,   273,     1,    27,    28,    35,    41,    64,    65,    66,
      67,    79,    80,    81,    86,    87,    88,    90,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   233,   233,   233,     1,    68,
     438,   439,   440,   233,     1,     6,     7,     9,    10,    14,
      24,    25,    26,    34,    37,    38,    39,    46,    63,    74,
      77,    78,    85,    91,    93,    95,    97,    99,   100,   110,
     116,   117,   119,   120,   121,   124,   149,   152,   153,   154,
     155,   156,   157,   158,   206,   207,   217,   218,   226,   228,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,   481,   482,   483,   484,   485,   486,   487,
     488,   489,   493,   497,   498,   499,   500,   233,   233,   233,
       1,   101,   123,   245,   246,   247,   248,   233,   233,   233,
       1,    36,    47,    48,    49,    52,    53,    57,    58,    59,
     520,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,     1,    29,    32,    61,    71,    92,    96,   104,   107,
     108,   137,   209,   211,   212,   214,   215,   216,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   233,     1,   222,   289,
     290,   291,   292,   293,   233,     1,   104,   381,   382,   383,
     233,   231,   234,   234,   234,   232,   270,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   503,     1,    17,    18,    23,    70,    88,
      89,    94,    98,   104,   113,   114,   115,   125,   146,   183,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,     1,     3,     5,
      19,    42,    60,    62,    70,    82,   104,   126,   145,   160,
     208,   210,   211,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   420,   421,   422,   423,   424,
       1,    68,   129,   433,   434,   435,   436,   234,   232,   439,
       1,   104,   129,   443,   444,   445,   446,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   494,   490,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   232,   449,     1,    19,    42,    70,   122,   130,
     131,   150,   223,   360,   361,   362,   363,   364,   365,   366,
     370,   371,   372,     1,   129,   223,   427,   428,   429,   430,
       1,    60,    68,    70,   126,   346,   350,   351,   352,   356,
     357,   231,   234,   234,   232,   246,     1,    84,   170,   276,
     277,   278,   279,     1,    19,    42,    70,   104,   122,   197,
     210,   213,   223,   227,   304,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   318,     1,    44,    84,   129,
     375,   376,   377,   378,   379,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   232,   521,   231,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   232,   251,     1,   104,   220,   396,   397,
     398,   399,   231,   234,   232,   290,   170,     1,   104,   163,
     181,   195,   282,   283,   284,   285,   286,   287,   234,   232,
     382,     1,   104,   220,   223,   386,   387,   388,   389,   390,
     127,   127,   127,   231,   112,   112,   241,   205,   205,   112,
     241,   241,   241,   112,   241,   241,   112,   112,   112,   112,
     231,   231,   234,   234,   234,   341,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   232,   325,   231,
     234,   234,   234,   234,   234,   234,   417,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   406,   234,   234,   232,
     434,   127,   231,   234,   234,   232,   444,   205,   241,   112,
     241,   241,   205,   112,   241,   205,   112,   112,   112,   205,
     205,   241,   112,   112,   112,   112,   241,   112,   112,   112,
     112,   205,   234,   234,   205,   241,   241,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   112,   241,   241,   241,
     205,   112,   231,   231,   234,   234,   367,   234,   234,   234,
     234,   234,   232,   361,   234,   234,   232,   428,   231,   234,
     234,   347,   234,   232,   351,   127,   127,   231,   231,   234,
     234,   232,   277,   231,   234,   234,   319,   234,   234,   315,
     234,   234,   234,   234,   232,   305,   231,   234,   234,   234,
     232,   376,   205,   205,   241,   127,   205,   127,   205,   205,
     205,   231,   112,   127,   205,   127,   112,   112,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   231,   231,
     234,   400,   232,   397,   205,   231,   233,   231,   234,   234,
     234,   234,   232,   283,   127,   231,   231,   234,   391,   234,
     232,   387,   231,   231,   231,   231,   138,   139,   140,   141,
     142,   143,   144,   240,   241,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   112,
     112,   241,   234,   112,   241,   112,   241,   127,   112,   112,
     112,   241,   112,   243,   243,   231,   127,   174,   175,   127,
     205,   127,   127,   234,   127,   127,   112,   127,   127,   241,
     127,   127,   231,   127,   127,   231,   231,   127,   127,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,    45,    52,   161,   162,   165,
     166,   168,   169,   171,   173,   176,   178,   179,   184,   188,
     192,   193,   194,   202,   495,   496,    45,    52,    54,    55,
     161,   162,   165,   166,   168,   169,   171,   173,   176,   178,
     179,   184,   188,   192,   193,   194,   202,   491,   492,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   127,   205,   234,
     127,   112,   127,   127,   127,   231,   127,   127,   231,   127,
     127,   234,   112,   354,   355,   231,   231,   231,   127,   127,
     231,   127,   205,   234,   127,   127,   234,   127,   205,   127,
     127,   231,   127,   127,   127,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   127,   234,   231,   231,     1,   104,   191,   220,   294,
     295,   296,   297,   298,   127,   127,   127,   127,   231,   231,
     127,   234,   127,   231,   240,   240,   240,   240,   240,   240,
     240,   231,   231,   231,    56,   128,   342,   343,   231,   231,
     231,   231,   231,   231,   231,   231,   231,    11,    12,    13,
     242,   243,   231,   231,   231,   231,   231,   231,   231,   231,
     231,     8,   196,   418,   419,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   235,   231,
     235,   231,   231,    15,    43,    76,   105,   106,   111,   136,
     204,   230,   368,   369,   231,   231,   231,   231,   231,   231,
     231,   231,   231,    20,    30,    52,   186,   196,   348,   349,
     219,   235,   353,   231,   231,   231,   231,     4,    21,    22,
      33,    72,    73,    75,   101,   109,   132,   134,   135,   151,
     167,   172,   176,   180,   185,   189,   198,   200,   201,   203,
     221,   229,   320,   321,   231,   231,    45,    52,    54,    55,
     161,   162,   165,   166,   168,   169,   171,   173,   176,   178,
     179,   184,   188,   192,   193,   194,   202,   316,   317,   231,
     231,   231,   231,   231,   231,   231,   231,    75,   135,   159,
     167,   176,   198,   200,   201,   221,   229,   401,   402,   231,
     234,   234,   299,   232,   295,   231,   231,   231,   231,   231,
      75,   135,   159,   167,   176,   198,   200,   201,   221,   229,
     392,   393,   231,   231,   235,   242,   242,   242,   231,   235,
     496,   492,   231,   235,   231,   235,   112,   355,   231,   236,
     236,   236,   236,   236,   236,   231,   235,   231,   235,   231,
     235,   127,   199,   243,   234,   231,   231,   235,   343,   419,
     369,   349,   133,   135,   133,   135,   133,   133,   321,   317,
     402,   231,   231,   231,    73,    75,   118,   135,   166,   167,
     223,   229,   300,   301,   393,   231,   235,   301
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
     317,   317,   317,   317,   317,   317,   317,   317,   319,   318,
     320,   320,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   323,   322,   324,   324,   325,   325,   325,   325,   325,
     325,   325,   325,   325,   325,   325,   325,   325,   325,   325,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   341,   340,   342,   342,   343,
     343,   345,   344,   347,   346,   348,   348,   349,   349,   349,
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
     494,   493,   495,   495,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   497,   498,   499,   500,   501,   502,   502,
     503,   503,   503,   503,   503,   503,   503,   503,   503,   503,
     503,   503,   503,   503,   503,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   520,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     0,     6,     0,     5,     3,     1,     1,     1,     1,
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
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4
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
#line 2870 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 399 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2876 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2888 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2894 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2906 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2912 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 409 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2924 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2930 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2936 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2942 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 426 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2957 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 432 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2966 "conf_parser.c" /* yacc.c:1652  */
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
#line 2978 "conf_parser.c" /* yacc.c:1652  */
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
#line 2990 "conf_parser.c" /* yacc.c:1652  */
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
#line 3002 "conf_parser.c" /* yacc.c:1652  */
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
#line 3014 "conf_parser.c" /* yacc.c:1652  */
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
#line 3026 "conf_parser.c" /* yacc.c:1652  */
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
#line 3038 "conf_parser.c" /* yacc.c:1652  */
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
#line 3050 "conf_parser.c" /* yacc.c:1652  */
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
#line 3068 "conf_parser.c" /* yacc.c:1652  */
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
#line 3086 "conf_parser.c" /* yacc.c:1652  */
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
#line 3099 "conf_parser.c" /* yacc.c:1652  */
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
#line 3116 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 581 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3128 "conf_parser.c" /* yacc.c:1652  */
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
#line 3154 "conf_parser.c" /* yacc.c:1652  */
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
#line 3180 "conf_parser.c" /* yacc.c:1652  */
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
#line 3206 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 659 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 677 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3227 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 686 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 695 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3251 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 708 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3260 "conf_parser.c" /* yacc.c:1652  */
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
#line 3277 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 729 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3286 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 735 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3295 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 745 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3304 "conf_parser.c" /* yacc.c:1652  */
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
#line 3322 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 767 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3331 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 773 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3340 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 779 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3349 "conf_parser.c" /* yacc.c:1652  */
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
#line 3370 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 813 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3379 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 819 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3388 "conf_parser.c" /* yacc.c:1652  */
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
#line 3401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 839 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3412 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 847 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3420 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 850 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3428 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 855 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3437 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 862 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3446 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 866 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3455 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 870 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3464 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 874 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3473 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 878 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3482 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 882 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3491 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 886 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3500 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3509 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 900 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3521 "conf_parser.c" /* yacc.c:1652  */
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
#line 3580 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 976 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3589 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 982 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3598 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 988 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3607 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 994 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3616 "conf_parser.c" /* yacc.c:1652  */
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
#line 3630 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1011 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3639 "conf_parser.c" /* yacc.c:1652  */
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
#line 3653 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1028 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3662 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1034 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3671 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1041 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3680 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1045 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3689 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1049 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3698 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1053 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 3707 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1057 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3716 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1061 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3725 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1065 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3734 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1069 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3743 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1073 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3752 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1077 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3761 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1081 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3770 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1085 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3779 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1089 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3788 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1093 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3797 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1097 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3806 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1101 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3815 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1105 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3824 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1109 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3833 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1113 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3842 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1117 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3851 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1121 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3860 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3869 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1134 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3878 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1138 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3887 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1142 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3896 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1146 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3905 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1150 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3914 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1154 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3923 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1158 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3932 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1162 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3941 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1166 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3950 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1170 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3959 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1174 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3968 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1178 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3977 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1182 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3986 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1186 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3995 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1190 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4004 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1194 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4013 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1198 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4022 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1202 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4031 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1206 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4040 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1210 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4049 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1214 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4058 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1218 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4067 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1222 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4076 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1226 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4085 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1230 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4094 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1234 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4103 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1238 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4112 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1242 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4121 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1246 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4130 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1256 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4146 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1267 "conf_parser.y" /* yacc.c:1652  */
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
#line 4194 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 1330 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4203 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 1336 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1342 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4221 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1348 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4230 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1354 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1360 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4248 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1366 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4257 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1372 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4266 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1378 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4276 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1385 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4285 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1391 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1397 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4303 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1403 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4315 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1412 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4327 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1421 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4336 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 1428 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4345 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 1432 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4354 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1442 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4363 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1448 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4371 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 1454 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4380 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 1458 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4389 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1462 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4398 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1466 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4407 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1470 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4416 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1478 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1483 "conf_parser.y" /* yacc.c:1652  */
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
#line 4440 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1496 "conf_parser.y" /* yacc.c:1652  */
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
#line 4460 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1513 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4469 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1519 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4478 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1529 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4487 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1533 "conf_parser.y" /* yacc.c:1652  */
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
#line 4533 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1587 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4542 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1593 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4551 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1599 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4560 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
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
#line 4574 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1616 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1623 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4592 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1627 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1631 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4610 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1635 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4619 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1639 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4628 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1643 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4637 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1647 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4646 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1651 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4655 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1655 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4664 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1661 "conf_parser.y" /* yacc.c:1652  */
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
#line 4681 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1675 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1684 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4705 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1697 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4717 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1704 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4728 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 338:
#line 1715 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4737 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1721 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4746 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1727 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 346:
#line 1742 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4770 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1758 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4786 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1769 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 355:
#line 1784 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1790 "conf_parser.y" /* yacc.c:1652  */
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
#line 4832 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1809 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4841 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 361:
#line 1816 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4850 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1824 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1828 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1832 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1836 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1840 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4904 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1844 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1848 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4922 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1852 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1862 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4958 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 378:
#line 1884 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4976 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 383:
#line 1897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4985 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4994 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1905 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1909 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1913 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1917 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5030 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1921 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1925 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5048 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1929 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5057 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1933 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5066 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1943 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5081 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
#line 1953 "conf_parser.y" /* yacc.c:1652  */
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
#line 5152 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 413:
#line 2039 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5161 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2045 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5170 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2051 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5179 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2057 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5188 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2063 "conf_parser.y" /* yacc.c:1652  */
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
#line 5204 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2076 "conf_parser.y" /* yacc.c:1652  */
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
#line 5220 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2089 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5229 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5238 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2101 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5247 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2105 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5256 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2111 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5264 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 427:
#line 2117 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5273 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2121 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5282 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5296 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2138 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2144 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5314 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2150 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2156 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5337 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5346 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2175 "conf_parser.y" /* yacc.c:1652  */
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
#line 5369 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 441:
#line 2198 "conf_parser.y" /* yacc.c:1652  */
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
#line 5392 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2218 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2228 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5410 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2232 "conf_parser.y" /* yacc.c:1652  */
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
#line 5434 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 450:
#line 2256 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5443 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2262 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5452 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 457:
#line 2277 "conf_parser.y" /* yacc.c:1652  */
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
#line 5469 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2294 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5478 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2298 "conf_parser.y" /* yacc.c:1652  */
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
#line 5498 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 465:
#line 2318 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5507 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2324 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5516 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 516:
#line 2385 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5524 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2390 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5532 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2395 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5540 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2400 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5548 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2405 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5556 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2410 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5564 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2415 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5572 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2420 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5580 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2425 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2430 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5596 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2435 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5604 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2440 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5612 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2445 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5620 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2450 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5628 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2455 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5636 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2460 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5644 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2465 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2470 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5660 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2475 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5668 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2480 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5676 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2485 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2490 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5692 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2495 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5700 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2500 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5708 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2505 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5716 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2510 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2515 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5732 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2520 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2525 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5748 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2530 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2535 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5764 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2540 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5772 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2545 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5780 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2550 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5788 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2555 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5796 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2560 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5804 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2565 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5812 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2570 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5820 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2575 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2580 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5836 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 559:
#line 2586 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5844 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2589 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5852 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2592 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5860 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2595 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 5868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2598 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5876 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2601 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5884 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2604 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5892 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2607 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2610 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5908 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2613 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5916 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2616 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5924 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2619 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5932 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2622 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2625 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2628 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5956 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2631 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5964 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2634 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2637 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5980 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2640 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 5988 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2643 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 5996 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2646 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6004 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2651 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 584:
#line 2657 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6020 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2660 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6028 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 586:
#line 2663 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6036 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2666 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2669 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6052 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2672 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6060 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2675 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6068 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2678 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6076 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2681 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2684 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6092 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2687 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6100 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2690 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6108 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2693 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6116 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2696 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6124 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2699 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6132 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2702 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6140 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2705 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6148 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2708 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6156 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2711 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6164 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2716 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6172 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2721 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6180 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2726 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6188 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2731 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6196 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 626:
#line 2760 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6204 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 627:
#line 2765 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 628:
#line 2770 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6220 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 629:
#line 2775 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6228 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 630:
#line 2780 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2785 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6244 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2790 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6252 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2795 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2800 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2805 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2810 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2815 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6292 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2820 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6300 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2825 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2830 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 654:
#line 2853 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6325 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 655:
#line 2859 "conf_parser.y" /* yacc.c:1652  */
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
#line 6344 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 656:
#line 2875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6356 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 657:
#line 2884 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 658:
#line 2890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6374 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2896 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6383 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6404 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2917 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6413 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6417 "conf_parser.c" /* yacc.c:1652  */
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
