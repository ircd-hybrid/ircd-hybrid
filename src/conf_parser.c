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
    T_SSL = 449,
    T_TARGET = 450,
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
    TMASKED = 472,
    TS_MAX_DELTA = 473,
    TS_WARN_DELTA = 474,
    TWODOTS = 475,
    TYPE = 476,
    UNKLINE = 477,
    USE_LOGGING = 478,
    USER = 479,
    VHOST = 480,
    VHOST6 = 481,
    WARN_NO_CONNECT_BLOCK = 482,
    WHOIS = 483,
    WHOWAS_HISTORY_LENGTH = 484,
    XLINE = 485,
    XLINE_EXEMPT = 486
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
#define T_SSL 449
#define T_TARGET 450
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
#define TMASKED 472
#define TS_MAX_DELTA 473
#define TS_WARN_DELTA 474
#define TWODOTS 475
#define TYPE 476
#define UNKLINE 477
#define USE_LOGGING 478
#define USER 479
#define VHOST 480
#define VHOST6 481
#define WARN_NO_CONNECT_BLOCK 482
#define WHOIS 483
#define WHOWAS_HISTORY_LENGTH 484
#define XLINE 485
#define XLINE_EXEMPT 486

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 133 "conf_parser.y" /* yacc.c:352  */

  int number;
  char *string;

#line 685 "conf_parser.c" /* yacc.c:352  */
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
#define YYLAST   1238

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  293
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1312

#define YYUNDEFTOK  2
#define YYMAXUTOK   486

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
       2,     2,     2,     2,   236,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   237,   232,
       2,   235,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,     2,   233,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   368,   368,   369,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   395,   399,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   410,   410,
     411,   412,   413,   414,   421,   423,   423,   424,   424,   424,
     426,   432,   442,   444,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   464,   473,   482,   491,   500,   509,   518,   527,
     542,   557,   567,   581,   590,   613,   636,   659,   669,   671,
     671,   672,   673,   674,   675,   677,   686,   695,   709,   708,
     726,   726,   727,   727,   727,   729,   735,   746,   745,   764,
     764,   765,   765,   765,   765,   765,   767,   773,   779,   785,
     807,   808,   808,   810,   810,   811,   813,   820,   820,   833,
     834,   836,   836,   837,   837,   839,   847,   850,   856,   855,
     861,   861,   862,   866,   870,   874,   878,   882,   886,   890,
     901,   900,   963,   963,   964,   965,   966,   967,   968,   969,
     970,   971,   972,   973,   974,   976,   982,   988,   994,  1000,
    1011,  1017,  1028,  1035,  1034,  1040,  1040,  1041,  1045,  1049,
    1053,  1057,  1061,  1065,  1069,  1073,  1077,  1081,  1085,  1089,
    1093,  1097,  1101,  1105,  1109,  1113,  1117,  1121,  1125,  1129,
    1136,  1135,  1141,  1141,  1142,  1146,  1150,  1154,  1158,  1162,
    1166,  1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,
    1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,
    1246,  1250,  1254,  1265,  1264,  1321,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1339,  1345,  1351,  1357,  1363,  1369,  1375,
    1381,  1387,  1394,  1400,  1406,  1412,  1421,  1431,  1430,  1436,
    1436,  1437,  1441,  1452,  1451,  1458,  1457,  1462,  1462,  1463,
    1467,  1471,  1477,  1477,  1478,  1478,  1478,  1478,  1478,  1480,
    1480,  1482,  1482,  1484,  1497,  1514,  1520,  1531,  1530,  1577,
    1577,  1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,
    1588,  1594,  1600,  1606,  1618,  1617,  1623,  1623,  1624,  1628,
    1632,  1636,  1640,  1644,  1648,  1652,  1656,  1660,  1666,  1680,
    1689,  1703,  1702,  1717,  1717,  1718,  1718,  1718,  1718,  1720,
    1726,  1732,  1742,  1744,  1744,  1745,  1745,  1747,  1764,  1763,
    1786,  1786,  1787,  1787,  1787,  1787,  1789,  1795,  1815,  1814,
    1820,  1820,  1821,  1825,  1829,  1833,  1837,  1841,  1845,  1849,
    1853,  1857,  1868,  1867,  1886,  1886,  1887,  1887,  1887,  1889,
    1896,  1895,  1901,  1901,  1902,  1906,  1910,  1914,  1918,  1922,
    1926,  1930,  1934,  1938,  1949,  1948,  2026,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2041,  2042,  2044,  2050,  2056,  2062,  2068,  2081,
    2094,  2100,  2106,  2110,  2117,  2116,  2121,  2121,  2122,  2126,
    2132,  2143,  2149,  2155,  2161,  2177,  2176,  2200,  2200,  2201,
    2201,  2201,  2203,  2223,  2234,  2233,  2258,  2258,  2259,  2259,
    2259,  2261,  2267,  2277,  2279,  2279,  2280,  2280,  2282,  2300,
    2299,  2320,  2320,  2321,  2321,  2321,  2323,  2329,  2339,  2341,
    2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,
    2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2360,
    2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2370,
    2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  2384,  2385,  2386,  2387,  2390,  2395,  2400,
    2405,  2410,  2415,  2420,  2425,  2430,  2435,  2440,  2445,  2450,
    2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,  2500,
    2505,  2510,  2515,  2518,  2523,  2526,  2531,  2536,  2541,  2546,
    2551,  2556,  2561,  2566,  2571,  2576,  2581,  2586,  2592,  2591,
    2596,  2596,  2597,  2600,  2603,  2606,  2609,  2612,  2615,  2618,
    2621,  2624,  2627,  2630,  2633,  2636,  2639,  2642,  2645,  2648,
    2651,  2654,  2657,  2660,  2663,  2669,  2668,  2673,  2673,  2674,
    2677,  2680,  2683,  2686,  2689,  2692,  2695,  2698,  2701,  2704,
    2707,  2710,  2713,  2716,  2719,  2722,  2725,  2728,  2731,  2734,
    2739,  2744,  2749,  2754,  2763,  2765,  2765,  2766,  2767,  2768,
    2769,  2770,  2771,  2772,  2773,  2774,  2775,  2776,  2777,  2778,
    2779,  2780,  2782,  2787,  2792,  2797,  2802,  2807,  2812,  2817,
    2822,  2827,  2832,  2837,  2842,  2847,  2856,  2858,  2858,  2859,
    2860,  2861,  2862,  2863,  2864,  2865,  2866,  2867,  2868,  2870,
    2876,  2892,  2901,  2907,  2913,  2919,  2928,  2934
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
  "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY",
  "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_BOTS", "T_CALLERID",
  "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_NCHANGE",
  "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ", "T_REJ",
  "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_TARGET", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_COUNT", "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES",
  "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE",
  "USE_LOGGING", "USER", "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK",
  "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -907

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-907)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -907,   652,  -907,  -169,  -211,  -197,  -907,  -907,  -907,  -195,
    -907,  -190,  -907,  -907,  -907,  -176,  -907,  -907,  -907,  -173,
    -165,  -907,  -148,  -907,  -134,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,   324,   959,  -125,   -97,   -88,    23,   -77,   384,   -70,
     -67,   -57,    28,   -43,   -29,   -27,   640,   571,   -12,     2,
      -6,    21,     5,  -141,    47,    55,    73,    17,  -907,  -907,
    -907,  -907,  -907,    74,    77,    78,    82,    83,    85,    92,
      95,    97,   100,   104,   106,   107,   108,   296,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,   707,   503,    25,  -907,   110,    33,  -907,
    -907,   169,  -907,   112,   113,   116,   121,   126,   128,   131,
     132,   134,   135,   136,   141,   143,   147,   151,   152,   154,
     157,   160,   168,   175,   176,   179,   182,   187,  -907,  -907,
     189,   193,   195,   196,   200,   201,   202,   204,   207,   210,
     212,   213,   214,   215,   218,   219,   221,   222,    42,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,   404,    56,   339,  -138,   225,
     226,    13,  -907,  -907,  -907,   105,   345,   287,  -907,   228,
     230,   232,   235,   238,   240,   247,   248,   250,    26,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,    10,
     251,   252,   253,   254,   255,   257,   258,   260,   261,   264,
     268,   272,   274,   275,   276,   277,   122,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,    11,    75,   280,    31,  -907,  -907,
    -907,    68,   119,  -907,   281,    61,  -907,  -907,    72,  -907,
     163,   241,   278,   145,  -907,   290,   331,   236,   412,   331,
     331,   331,   415,   331,   331,   416,   417,   424,   434,   313,
    -907,   315,   314,   317,   318,  -907,   321,   322,   326,   328,
     329,   330,   332,   333,   336,   340,   341,   167,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,   316,   343,   346,   348,   349,   350,
     352,  -907,   353,   354,   358,   360,   361,   363,   365,   370,
     142,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,   371,   372,
      40,  -907,  -907,  -907,   426,   334,  -907,  -907,   373,   374,
      53,  -907,  -907,  -907,   369,   331,   501,   331,   331,   407,
     507,   331,   413,   508,   511,   512,   419,   420,   331,   513,
     521,   522,   524,   331,   525,   526,   528,   529,   435,   408,
     409,   442,   331,   331,   445,   449,   450,  -189,  -172,   452,
     453,   454,   457,   554,   331,   331,   331,   460,   557,   437,
    -907,   447,   432,   456,  -907,   462,   463,   466,   467,   468,
     164,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,   469,   471,    52,  -907,  -907,  -907,   451,   472,   474,
    -907,   475,  -907,    30,  -907,  -907,  -907,  -907,  -907,   553,
     556,   455,  -907,   483,   481,   482,     3,  -907,  -907,  -907,
     487,   485,   486,  -907,   488,   492,  -907,   493,   495,   496,
     499,   205,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,   505,   510,   514,   515,    18,  -907,  -907,
    -907,  -907,   477,   541,   331,   564,   542,   568,   543,   555,
     558,   530,  -907,  -907,   655,   637,   560,   642,   659,   660,
     646,   647,   648,   649,   651,   653,   654,   665,   670,   671,
     544,  -907,   547,   565,  -907,    34,  -907,  -907,  -907,  -907,
     594,   569,  -907,   570,   573,   572,   574,   575,   576,     7,
    -907,  -907,  -907,  -907,  -907,   679,   580,  -907,   581,   579,
    -907,   586,    14,  -907,  -907,  -907,  -907,   584,   590,   591,
    -907,   592,   603,   593,   598,   599,   600,   602,   604,   605,
     607,   608,   610,   614,   615,   621,  -907,  -907,   697,   717,
     331,   622,   726,   331,   749,   331,   736,   754,   755,   756,
     331,   757,   757,   636,  -907,  -907,   746,   130,   748,   668,
     750,   758,   643,   759,   760,   770,   761,   763,   331,   764,
     766,   661,  -907,   767,   768,   662,  -907,   663,  -907,   772,
     773,   669,  -907,   673,   676,   678,   680,   681,   686,   687,
     688,   689,   691,   692,   693,   695,   696,   701,   702,   703,
     712,   715,   719,   720,   725,   727,   730,   732,   778,   684,
     734,   735,   741,   742,   744,   745,   747,   762,   769,   771,
     774,   775,   776,   777,   779,   780,   782,   784,   785,   786,
    -907,  -907,   844,   675,   667,   854,   873,   863,   864,   865,
     792,  -907,   866,   867,   793,  -907,  -907,   869,   872,   765,
     890,   794,  -907,   796,   798,  -907,  -907,   878,   880,   799,
    -907,  -907,   886,   810,   803,   905,   908,   804,   909,   829,
     916,   917,   813,  -907,  -907,   923,   924,   925,   818,  -907,
     819,   820,   821,   822,   823,   824,   825,   826,   827,  -907,
     828,   830,   831,   832,   833,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   845,  -907,  -907,   937,   846,
     847,  -907,   848,  -907,    20,  -907,   952,   954,   958,   960,
     851,  -907,   853,  -907,  -907,   962,   852,   964,   857,  -907,
    -907,  -907,  -907,  -907,   331,   331,   331,   331,   331,   331,
     331,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,   858,   859,   860,   -42,
     861,   862,   868,   870,   871,   874,   875,   876,   877,   206,
     879,   881,  -907,   882,   883,   884,   885,   887,   888,   889,
      22,   891,   892,   893,   894,   895,   896,   897,   898,  -907,
     899,   900,  -907,  -907,   901,   902,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -219,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -196,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
     903,   904,   411,   906,   907,   910,   911,   912,  -907,   913,
     914,  -907,   915,   918,    19,   920,   919,  -907,  -907,  -907,
    -907,   921,   922,  -907,   926,   927,   448,   928,   929,   739,
     930,   931,   932,   933,  -907,   934,   935,   936,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,   938,   783,  -907,  -907,   939,   940,
     941,  -907,    24,  -907,  -907,  -907,  -907,   942,   945,   946,
     947,  -907,  -907,   948,   797,   949,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -194,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
     757,   757,   757,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -186,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,   778,  -907,   684,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -143,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -140,  -907,   986,   890,   950,  -907,  -907,  -907,  -907,  -907,
    -907,   951,  -907,   953,   955,  -907,  -907,   956,   957,  -907,
    -907,   961,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -105,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,   -24,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,    -3,  -907,  -907,   972,   -89,   965,   963,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,    66,  -907,  -907,  -907,   -42,  -907,
    -907,  -907,  -907,    22,  -907,  -907,  -907,   411,  -907,    19,
    -907,  -907,  -907,   967,   966,   969,   973,   971,   974,  -907,
     448,  -907,   739,  -907,   783,   970,   975,   976,   362,  -907,
    -907,   797,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,    69,  -907,  -907,  -907,
     362,  -907
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   233,   394,   444,     0,
     459,     0,   297,   435,   273,     0,    98,   150,   331,     0,
       0,   372,     0,   107,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,   630,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   617,
     618,   628,   629,     0,     0,     0,   457,     0,     0,   455,
     456,     0,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   585,   558,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   470,
     471,   472,   514,   478,   515,   509,   510,   511,   512,   482,
     473,   474,   475,   476,   477,   479,   480,   481,   483,   484,
     513,   488,   489,   490,   491,   487,   486,   492,   499,   500,
     493,   494,   495,   485,   497,   507,   508,   505,   506,   498,
     496,   503,   504,   501,   502,     0,     0,     0,     0,     0,
       0,     0,    46,    47,    48,     0,     0,     0,   658,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   648,
     649,   650,   651,   652,   653,   654,   656,   655,   657,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    54,    67,    65,
      63,    68,    69,    70,    64,    55,    66,    57,    58,    59,
      60,    61,    62,    56,     0,     0,     0,     0,   122,   123,
     124,     0,     0,   346,     0,     0,   344,   345,     0,    94,
       0,     0,     0,     0,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,     0,     0,     0,     0,   267,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
     240,   242,   243,   244,   245,   246,   247,   248,   238,   239,
     241,   249,   250,   251,     0,     0,     0,     0,     0,     0,
       0,   424,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   397,   398,   399,   400,   401,   402,   403,   404,   406,
     405,   408,   412,   409,   410,   411,   407,   450,     0,     0,
       0,   447,   448,   449,     0,     0,   454,   465,     0,     0,
       0,   462,   463,   464,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     469,     0,     0,     0,   314,     0,     0,     0,     0,     0,
       0,   300,   301,   302,   303,   308,   304,   305,   306,   307,
     441,     0,     0,     0,   438,   439,   440,     0,     0,     0,
     275,     0,   285,     0,   283,   284,   286,   287,    49,     0,
       0,     0,    45,     0,     0,     0,     0,   101,   102,   103,
       0,     0,     0,   200,     0,     0,   173,     0,     0,     0,
       0,     0,   153,   154,   155,   156,   157,   160,   161,   162,
     159,   158,   163,     0,     0,     0,     0,     0,   334,   335,
     336,   337,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   647,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    53,     0,     0,   380,     0,   375,   376,   377,   125,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
     110,   111,   113,   112,   114,     0,     0,   343,     0,     0,
     358,     0,     0,   351,   352,   353,   354,     0,     0,     0,
      88,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,   252,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,   413,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,     0,     0,     0,   446,     0,   453,     0,
       0,     0,   461,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     468,   309,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   299,     0,     0,     0,   437,   288,     0,     0,     0,
       0,     0,   282,     0,     0,    44,   104,     0,     0,     0,
     100,   164,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   152,   338,     0,     0,     0,     0,   333,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   378,     0,     0,
       0,   374,     0,   120,     0,   115,     0,     0,     0,     0,
       0,   109,     0,   342,   355,     0,     0,     0,     0,   350,
      97,    96,    95,   644,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   645,   632,   633,   634,   635,   636,   637,
     638,   639,   642,   643,   640,   641,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,   234,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
       0,     0,   445,   458,     0,     0,   460,   528,   532,   517,
     518,   547,   521,   612,   613,   555,   522,   523,   552,   527,
     535,   526,   524,   525,   531,   530,   529,   553,   519,   610,
     611,   551,   609,   595,   589,   605,   590,   591,   592,   600,
     608,   593,   602,   606,   596,   607,   597,   601,   594,   604,
     599,   598,   603,     0,   588,   584,   567,   568,   569,   562,
     580,   563,   564,   565,   575,   583,   566,   577,   581,   571,
     582,   572,   576,   570,   579,   574,   573,   578,     0,   561,
     548,   546,   549,   554,   550,   537,   544,   545,   542,   543,
     538,   539,   540,   541,   556,   557,   534,   533,   536,   520,
       0,     0,     0,     0,     0,     0,     0,     0,   298,     0,
       0,   436,     0,     0,     0,   293,   289,   292,   274,    50,
      51,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   151,     0,     0,     0,   332,   662,
     659,   660,   661,   666,   665,   667,   663,   664,    84,    81,
      87,    80,    85,    86,    79,    83,    82,    73,    72,    75,
      76,    74,    77,    78,     0,     0,   373,   126,     0,     0,
       0,   138,     0,   130,   131,   133,   132,     0,     0,     0,
       0,   108,   347,     0,     0,     0,   349,    31,    32,    33,
      34,    35,    36,    37,   262,   263,   257,   272,   271,     0,
     270,   258,   266,   259,   265,   253,   264,   256,   255,   254,
      38,    38,    38,    40,    39,   260,   261,   419,   422,   423,
     433,   430,   415,   431,   428,   429,     0,   427,   432,   414,
     421,   418,   417,   416,   420,   434,   451,   452,   466,   467,
     586,     0,   559,     0,   312,   313,   323,   319,   320,   322,
     327,   324,   325,   318,   326,   321,     0,   317,   311,   330,
     329,   328,   310,   443,   442,   296,   295,   280,   281,   279,
       0,   278,     0,     0,     0,   105,   106,   172,   169,   220,
     232,   207,   216,     0,   205,   210,   226,     0,   219,   224,
     230,   209,   212,   221,   223,   227,   217,   225,   213,   231,
     215,   222,   211,   214,     0,   203,   165,   167,   199,   182,
     183,   184,   177,   195,   178,   179,   180,   190,   198,   181,
     192,   196,   186,   197,   187,   191,   185,   194,   189,   188,
     193,     0,   176,   170,   171,   166,   168,   341,   339,   340,
     379,   384,   390,   393,   386,   392,   387,   391,   389,   385,
     388,     0,   383,   134,     0,     0,     0,     0,   129,   117,
     116,   118,   119,   356,   362,   368,   371,   364,   370,   365,
     369,   367,   363,   366,     0,   361,   357,   268,     0,    41,
      42,    43,   425,     0,   587,   560,   315,     0,   276,     0,
     294,   291,   290,     0,     0,     0,     0,     0,     0,   201,
       0,   174,     0,   381,     0,     0,     0,     0,     0,   128,
     359,     0,   269,   426,   316,   277,   206,   229,   204,   228,
     218,   208,   202,   175,   382,   135,   137,   136,   148,   147,
     143,   145,   149,   146,   142,   144,     0,   141,   360,   139,
       0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -907,  -907,  -907,   -61,  -304,  -906,  -631,  -907,  -907,   968,
    -907,  -907,  -907,  -907,   856,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  1033,  -907,  -907,  -907,  -907,  -907,  -907,
     616,  -907,  -907,  -907,  -907,  -907,   539,  -907,  -907,  -907,
    -907,  -907,  -907,   850,  -907,  -907,  -907,  -907,    99,  -907,
    -907,  -907,  -907,  -907,  -162,  -907,  -907,  -907,   638,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -121,  -907,  -907,  -907,  -118,  -907,  -907,  -907,   849,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,   -92,  -907,  -907,  -907,
    -907,  -907,  -102,  -907,   690,  -907,  -907,  -907,    29,  -907,
    -907,  -907,  -907,  -907,   709,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,   -74,  -907,  -907,  -907,  -907,  -907,  -907,   657,
    -907,  -907,  -907,  -907,  -907,   943,  -907,  -907,  -907,  -907,
     595,  -907,  -907,  -907,  -907,  -907,   -96,  -907,  -907,  -907,
     626,  -907,  -907,  -907,  -907,   -78,  -907,  -907,  -907,   855,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,   -56,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,   728,  -907,  -907,  -907,  -907,  -907,   809,  -907,  -907,
    -907,  -907,  1085,  -907,  -907,  -907,  -907,   805,  -907,  -907,
    -907,  -907,  1036,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,    93,  -907,  -907,  -907,    98,
    -907,  -907,  -907,  -907,  -907,  -907,  1113,  -907,  -907,  -907,
    -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907,   977,  -907,  -907,  -907,  -907,  -907,  -907,
    -907,  -907,  -907
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   821,   822,  1083,  1084,    27,   221,   222,
     223,   224,    28,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,    29,    77,    78,    79,    80,    81,    30,    63,   496,
     497,   498,   499,    31,    70,   579,   580,   581,   582,   583,
     584,    32,   287,   288,   289,   290,   291,  1042,  1043,  1044,
    1045,  1046,  1226,  1306,  1307,    33,    64,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   747,  1201,
    1202,   522,   744,  1174,  1175,    34,    53,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   621,  1069,  1070,    35,    61,   482,
     729,  1140,  1141,   483,   484,   485,  1144,   986,   987,   486,
     487,    36,    59,   460,   461,   462,   463,   464,   465,   466,
     714,  1126,  1127,   467,   468,   469,    37,    65,   527,   528,
     529,   530,   531,    38,   295,   296,   297,    39,    72,   592,
     593,   594,   595,   596,   806,  1244,  1245,    40,    68,   565,
     566,   567,   568,   789,  1221,  1222,    41,    54,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     642,  1096,  1097,   382,   383,   384,   385,   386,    42,    60,
     473,   474,   475,   476,    43,    55,   390,   391,   392,   393,
      44,   118,   119,   120,    45,    57,   400,   401,   402,   403,
      46,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   430,   948,   949,   210,   429,   923,   924,
     211,   212,   213,   214,    47,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,    48,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   247,   248
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     850,   851,   603,   285,   493,   606,   607,   608,   574,   610,
     611,  1067,   562,  1110,   218,   588,   696,  1111,    73,   523,
     849,  1038,   293,    51,   116,  1038,   387,   228,   697,   218,
    1094,   477,   285,   698,   116,   562,  1112,    52,  1247,    56,
    1113,   387,  1248,   122,    58,   699,  1252,    74,   123,   124,
    1253,   125,   126,   470,   397,    75,   127,   470,    62,   524,
     229,    66,   293,    49,    50,   128,   129,   130,  1137,    67,
     230,   231,   232,   588,   131,   233,   234,   132,   133,   134,
     235,   236,   237,  1068,   494,   135,    69,   478,   117,  1256,
     388,   299,  1258,  1257,   488,   479,  1259,   480,   117,   525,
      71,   664,   136,   666,   667,   388,   493,   670,   575,   113,
    1276,   219,   563,   137,   677,   589,   138,   139,    76,   682,
     574,  1039,   294,   249,   140,  1039,   219,  1269,   691,   692,
     141,  1270,   142,   220,   143,   563,   144,   114,   145,   146,
     705,   706,   707,   354,   526,   355,   115,   356,   220,   147,
     250,   389,   251,   481,   398,   148,   149,   121,   150,   151,
     152,   357,   294,   153,   215,   451,   389,   216,   321,   576,
     397,  -127,   495,   589,  1249,  1250,  1251,   217,   471,   399,
     252,   358,   471,   452,   322,   323,   494,   577,   154,   324,
     253,   225,   155,   156,   157,   158,   159,   160,   161,   359,
    -127,   360,   578,   453,  1138,   226,   500,   227,  1271,   361,
    1040,   254,  1272,  1139,  1040,   255,  1095,  1080,  1081,  1082,
     575,   362,   284,   256,   501,   286,   257,   258,   292,  1273,
     762,   454,   564,  1274,   325,   590,   739,   573,   591,   298,
     800,  1041,   543,   363,   502,  1041,   491,   808,   162,   163,
     303,   758,   326,   327,   286,   564,   259,  1227,   328,   541,
     164,   165,   329,   731,   571,   364,   395,   790,   330,   166,
     398,   167,   503,   655,   495,   449,   472,   331,   332,   333,
     472,   576,   300,   455,   365,   724,   661,   597,   523,   334,
     301,   456,   457,   590,   586,   399,   591,    82,  1280,   577,
     366,  1309,  1281,   854,   855,  1310,   504,   569,   302,   305,
     335,   458,   306,   307,   578,   849,   838,   308,   309,   841,
     310,   843,    83,    84,   505,    73,   848,   311,   524,    85,
     312,   260,   313,   261,   262,   314,   263,   264,   265,   315,
     477,   316,   317,   318,   866,   394,   500,   404,   405,   336,
     367,   406,   368,   369,    74,   560,   407,    86,    87,    88,
      89,   408,    75,   409,   501,   598,   410,   411,   525,   412,
     413,   414,    90,    91,    92,   651,   415,   600,   416,    93,
      94,    95,   417,    96,   502,   122,   418,   419,   459,   420,
     123,   124,   421,   125,   126,   422,   478,   720,   127,   601,
     633,   506,   599,   423,   479,   451,   480,   128,   129,   130,
     424,   425,   503,   526,   426,   507,   131,   427,   508,   132,
     133,   134,   428,   452,   431,    76,  1116,   135,   432,   509,
     433,   434,  1298,   510,  1299,   435,   436,   437,   752,   438,
     602,   604,   439,   453,   136,   440,   504,   441,   442,   443,
     444,  1117,  1149,   445,   446,   137,   447,   448,   138,   139,
     489,   490,   481,   532,   505,   533,   140,   534,  1150,  1151,
     535,   454,   141,   536,   142,   537,   143,  1300,   144,  1152,
     145,   146,   538,   539,  1118,   540,   544,   545,   546,   547,
     548,   147,   549,   550,  1301,   551,   552,   148,   149,   553,
     150,   151,   152,   554,   354,   153,   355,   555,   356,   556,
     557,   558,   559,  1119,  1120,   570,   585,  1153,  1154,  1121,
    1155,   605,   357,   455,   609,   612,   613,  1302,  1303,   319,
     154,   456,   457,   614,   155,   156,   157,   158,   159,   160,
     161,   506,   358,   615,  1122,   616,  1156,   617,   635,   618,
     657,   458,   619,   620,  1157,   507,   622,   623,   508,  1123,
     359,   624,   360,   625,   626,   627,   658,   628,   629,   509,
     361,   630,   249,   510,   663,   631,   632,  1158,   636,  1159,
    1160,   637,   362,   638,   639,   640,  1304,   641,   643,   644,
     162,   163,  1305,   645,  1277,   646,   647,  1161,   648,   250,
     649,   251,   164,   165,   363,   650,   653,   654,   659,   660,
     665,   166,   668,   167,  1162,  1124,   669,   672,   671,  1163,
     673,   674,   678,  1164,   675,   676,   364,  1165,   459,   252,
     679,   680,  1166,   681,   683,   684,  1167,   685,   686,   253,
     687,   228,  1125,   688,   689,   365,  1168,   690,  1169,  1170,
     693,  1171,     2,     3,   694,   695,     4,   700,   701,   702,
     254,   366,   703,   704,   255,   708,   709,   712,     5,   710,
    1172,     6,   256,     7,   229,   257,   258,   733,  1173,   711,
     734,     8,   760,   726,   230,   231,   232,   735,   763,   233,
     234,   713,   765,     9,   235,   236,   237,   715,   716,    10,
      11,   717,   718,   719,   722,   259,   723,   727,   321,   728,
     730,   367,   602,   368,   369,   736,   737,   738,    12,   741,
     742,   743,    13,   745,   322,   323,   925,   746,   748,   324,
     749,   750,    14,   926,   751,   927,   928,   754,   814,   815,
     816,   817,   818,   819,   820,   755,   761,   764,   766,   756,
     757,    15,    16,  1057,  1058,  1059,  1060,  1061,  1062,  1063,
     767,   771,   769,   768,   770,   772,   773,    17,   774,   775,
     776,   777,   778,   779,   325,   780,   786,   781,   782,   787,
     260,  1178,   261,   262,    18,   263,   264,   265,  1179,   783,
    1180,  1181,   326,   327,   784,   785,    19,    20,   328,   792,
     788,   793,   329,   802,   794,   795,   836,   796,   330,   797,
     798,   799,   803,   804,   805,    21,   810,   331,   332,   333,
     902,   807,   811,   812,   813,   823,   837,   903,    22,   334,
     824,   825,   826,    23,   827,   840,   828,   829,    24,   830,
     831,    25,   832,   929,   930,   931,   833,   834,   932,   933,
     335,   934,   935,   835,   936,  1211,   937,   839,   842,   938,
     844,   939,   940,   845,   846,   847,   849,   941,   852,  1234,
     853,   942,   856,   857,   858,   943,   944,   945,   860,   863,
     971,   946,   859,   861,   862,   864,   947,   865,   867,   336,
     868,   870,   871,   869,   872,   873,   874,   875,  1182,  1183,
    1184,   876,   972,  1185,  1186,   877,  1187,  1188,   878,  1189,
     879,  1190,   880,   881,  1191,  1212,  1192,  1193,   882,   883,
     884,   885,  1194,   886,   887,   888,  1195,   889,   890,  1235,
    1196,  1197,  1198,   891,   892,   893,  1199,   904,   905,   906,
    1213,  1200,   907,   908,   894,   909,   910,   895,   911,  1214,
     912,   896,   897,   913,  1236,   914,   915,   898,  1215,   899,
      82,   916,   900,  1237,   901,   917,   950,   951,   970,   918,
     919,   920,  1238,   952,   953,   921,   954,   955,   973,   956,
     922,  1216,   974,  1217,  1218,    83,    84,   975,   976,   977,
     979,   980,    85,   982,   957,  1239,   983,  1240,  1241,   985,
     984,   958,   991,   959,   992,  1219,   960,   961,   962,   963,
     994,   964,   965,  1220,   966,   995,   967,   968,   969,  1242,
      86,    87,    88,    89,   978,   981,   988,  1243,   989,   997,
     990,   993,   998,  1000,  1001,    90,    91,    92,   996,   999,
    1002,  1003,    93,    94,    95,  1004,    96,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1034,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,
    1027,  1028,  1029,  1030,  1031,  1032,  1047,  1033,  1048,  1036,
    1037,  1035,  1049,  1051,  1050,  1052,  1053,  1054,  1055,  1056,
    1064,  1065,  1066,  1071,  1072,  1260,  1275,  1286,  1287,  1288,
    1073,  1290,  1074,  1075,  1291,  1289,  1076,  1077,  1078,  1079,
     304,  1085,   740,  1086,  1087,  1088,  1089,  1090,   801,  1091,
    1092,  1093,   561,  1098,  1099,  1100,  1101,  1102,  1103,  1104,
    1105,  1106,  1107,  1108,  1109,  1114,  1115,   572,  1128,  1129,
    1142,  1228,  1130,  1131,  1132,  1133,  1134,  1135,  1311,   753,
    1136,  1293,  1292,  1145,  1146,  1143,  1282,  1285,  1147,  1148,
    1176,  1177,  1203,  1204,  1205,  1206,  1207,  1208,  1209,   721,
    1210,  1223,  1261,   732,  1229,  1224,  1225,  1230,  1231,  1232,
    1233,  1246,  1262,  1284,   759,  1308,   634,   809,  1263,   492,
    1264,   791,  1265,  1266,  1267,  1279,  1294,  1283,  1268,   656,
    1278,   725,  1295,   396,   450,   662,  1255,  1296,  1297,  1254,
     320,     0,     0,     0,     0,   542,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   652,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   587
};

static const yytype_int16 yycheck[] =
{
     631,   632,   306,     1,     1,   309,   310,   311,     1,   313,
     314,    53,     1,   232,     1,     1,   205,   236,     1,     1,
     109,     1,     1,   234,     1,     1,     1,     1,   217,     1,
       8,     1,     1,   205,     1,     1,   232,   234,   232,   234,
     236,     1,   236,     1,   234,   217,   232,    30,     6,     7,
     236,     9,    10,     1,     1,    38,    14,     1,   234,    41,
      34,   234,     1,   232,   233,    23,    24,    25,    49,   234,
      44,    45,    46,     1,    32,    49,    50,    35,    36,    37,
      54,    55,    56,   125,    81,    43,   234,    57,    65,   232,
      65,   232,   232,   236,   232,    65,   236,    67,    65,    81,
     234,   405,    60,   407,   408,    65,     1,   411,   101,   234,
     199,    98,   101,    71,   418,   101,    74,    75,   101,   423,
       1,   101,   101,     1,    82,   101,    98,   232,   432,   433,
      88,   236,    90,   120,    92,   101,    94,   234,    96,    97,
     444,   445,   446,     1,   126,     3,   234,     5,   120,   107,
      28,   126,    30,   123,   101,   113,   114,   234,   116,   117,
     118,    19,   101,   121,   234,     1,   126,   234,     1,   162,
       1,   169,   169,   101,  1080,  1081,  1082,   234,   126,   126,
      58,    39,   126,    19,    17,    18,    81,   180,   146,    22,
      68,   234,   150,   151,   152,   153,   154,   155,   156,    57,
     169,    59,   195,    39,   185,   234,     1,   234,   232,    67,
     190,    89,   236,   194,   190,    93,   194,    11,    12,    13,
     101,    79,   234,   101,    19,   223,   104,   105,   234,   232,
     534,    67,   221,   236,    67,   221,   233,   169,   224,   234,
     233,   221,   232,   101,    39,   221,   233,   233,   206,   207,
     233,   233,    85,    86,   223,   221,   134,   233,    91,   233,
     218,   219,    95,   233,   233,   123,   233,   233,   101,   227,
     101,   229,    67,   233,   169,   233,   224,   110,   111,   112,
     224,   162,   235,   119,   142,   233,   233,   124,     1,   122,
     235,   127,   128,   221,   233,   126,   224,     1,   232,   180,
     158,   232,   236,   173,   174,   236,   101,   232,   235,   235,
     143,   147,   235,   235,   195,   109,   620,   235,   235,   623,
     235,   625,    26,    27,   119,     1,   630,   235,    41,    33,
     235,   209,   235,   211,   212,   235,   214,   215,   216,   235,
       1,   235,   235,   235,   648,   235,     1,   235,   235,   182,
     208,   235,   210,   211,    30,   233,   235,    61,    62,    63,
      64,   235,    38,   235,    19,   124,   235,   235,    81,   235,
     235,   235,    76,    77,    78,   233,   235,   232,   235,    83,
      84,    85,   235,    87,    39,     1,   235,   235,   224,   235,
       6,     7,   235,     9,    10,   235,    57,   233,    14,   109,
     233,   196,   124,   235,    65,     1,    67,    23,    24,    25,
     235,   235,    67,   126,   235,   210,    32,   235,   213,    35,
      36,    37,   235,    19,   235,   101,    15,    43,   235,   224,
     235,   235,    70,   228,    72,   235,   235,   235,   233,   235,
     109,   205,   235,    39,    60,   235,   101,   235,   235,   235,
     235,    40,     4,   235,   235,    71,   235,   235,    74,    75,
     235,   235,   123,   235,   119,   235,    82,   235,    20,    21,
     235,    67,    88,   235,    90,   235,    92,   115,    94,    31,
      96,    97,   235,   235,    73,   235,   235,   235,   235,   235,
     235,   107,   235,   235,   132,   235,   235,   113,   114,   235,
     116,   117,   118,   235,     1,   121,     3,   235,     5,   235,
     235,   235,   235,   102,   103,   235,   235,    69,    70,   108,
      72,   109,    19,   119,   109,   109,   109,   165,   166,   233,
     146,   127,   128,   109,   150,   151,   152,   153,   154,   155,
     156,   196,    39,   109,   133,   232,    98,   232,   232,   235,
     124,   147,   235,   235,   106,   210,   235,   235,   213,   148,
      57,   235,    59,   235,   235,   235,   232,   235,   235,   224,
      67,   235,     1,   228,   205,   235,   235,   129,   235,   131,
     132,   235,    79,   235,   235,   235,   224,   235,   235,   235,
     206,   207,   230,   235,  1225,   235,   235,   149,   235,    28,
     235,    30,   218,   219,   101,   235,   235,   235,   235,   235,
     109,   227,   205,   229,   166,   204,   109,   109,   205,   171,
     109,   109,   109,   175,   205,   205,   123,   179,   224,    58,
     109,   109,   184,   109,   109,   109,   188,   109,   109,    68,
     205,     1,   231,   235,   235,   142,   198,   205,   200,   201,
     205,   203,     0,     1,   205,   205,     4,   205,   205,   205,
      89,   158,   205,   109,    93,   205,   109,   235,    16,   232,
     222,    19,   101,    21,    34,   104,   105,   124,   230,   232,
     124,    29,   205,   232,    44,    45,    46,   232,   124,    49,
      50,   235,   124,    41,    54,    55,    56,   235,   235,    47,
      48,   235,   235,   235,   235,   134,   235,   235,     1,   235,
     235,   208,   109,   210,   211,   232,   235,   235,    66,   232,
     235,   235,    70,   235,    17,    18,    42,   235,   235,    22,
     235,   235,    80,    49,   235,    51,    52,   232,   135,   136,
     137,   138,   139,   140,   141,   235,   205,   205,   205,   235,
     235,    99,   100,   814,   815,   816,   817,   818,   819,   820,
     205,   124,   232,   205,   109,   205,   124,   115,   109,   109,
     124,   124,   124,   124,    67,   124,   232,   124,   124,   232,
     209,    42,   211,   212,   132,   214,   215,   216,    49,   124,
      51,    52,    85,    86,   124,   124,   144,   145,    91,   205,
     235,   232,    95,   124,   234,   232,   109,   235,   101,   235,
     235,   235,   232,   232,   235,   163,   232,   110,   111,   112,
      42,   235,   232,   232,   232,   232,   109,    49,   176,   122,
     232,   232,   232,   181,   232,   109,   232,   232,   186,   232,
     232,   189,   232,   159,   160,   161,   232,   232,   164,   165,
     143,   167,   168,   232,   170,    72,   172,   235,   109,   175,
     124,   177,   178,   109,   109,   109,   109,   183,   232,    72,
     124,   187,   124,   205,   124,   191,   192,   193,   235,   109,
     205,   197,   124,   124,   124,   124,   202,   124,   124,   182,
     124,   124,   124,   232,   232,   232,   124,   124,   159,   160,
     161,   232,   235,   164,   165,   232,   167,   168,   232,   170,
     232,   172,   232,   232,   175,   132,   177,   178,   232,   232,
     232,   232,   183,   232,   232,   232,   187,   232,   232,   132,
     191,   192,   193,   232,   232,   232,   197,   159,   160,   161,
     157,   202,   164,   165,   232,   167,   168,   232,   170,   166,
     172,   232,   232,   175,   157,   177,   178,   232,   175,   232,
       1,   183,   232,   166,   232,   187,   232,   232,   124,   191,
     192,   193,   175,   232,   232,   197,   232,   232,   124,   232,
     202,   198,   109,   200,   201,    26,    27,   124,   124,   124,
     124,   124,    33,   124,   232,   198,   124,   200,   201,   109,
     235,   232,   124,   232,   124,   222,   232,   232,   232,   232,
     124,   232,   232,   230,   232,   205,   232,   232,   232,   222,
      61,    62,    63,    64,   232,   232,   232,   230,   232,   124,
     232,   232,   124,   124,   205,    76,    77,    78,   235,   235,
     124,   124,    83,    84,    85,   232,    87,   124,   124,   124,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   124,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   124,   232,   124,   232,
     232,   235,   124,   232,   124,   232,   124,   235,   124,   232,
     232,   232,   232,   232,   232,   109,   124,   130,   132,   130,
     232,   130,   232,   232,   130,   132,   232,   232,   232,   232,
      77,   232,   496,   232,   232,   232,   232,   232,   579,   232,
     232,   232,   266,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   287,   232,   232,
     220,  1042,   232,   232,   232,   232,   232,   232,  1310,   511,
     232,  1272,  1270,   232,   232,   236,  1248,  1259,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   460,
     232,   232,  1143,   483,   232,   235,   235,   232,   232,   232,
     232,   232,   232,  1257,   527,  1281,   337,   592,   237,   221,
     237,   565,   237,   237,   237,   232,  1274,  1253,   237,   390,
     235,   473,   232,   118,   168,   400,  1113,   232,   232,  1111,
      97,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    16,    19,    21,    29,    41,
      47,    48,    66,    70,    80,    99,   100,   115,   132,   144,
     145,   163,   176,   181,   186,   189,   240,   245,   250,   269,
     275,   281,   289,   303,   323,   345,   359,   374,   381,   385,
     395,   404,   426,   432,   438,   442,   448,   502,   519,   232,
     233,   234,   234,   324,   405,   433,   234,   443,   234,   360,
     427,   346,   234,   276,   304,   375,   234,   234,   396,   234,
     282,   234,   386,     1,    30,    38,   101,   270,   271,   272,
     273,   274,     1,    26,    27,    33,    61,    62,    63,    64,
      76,    77,    78,    83,    84,    85,    87,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   234,   234,   234,     1,    65,   439,   440,
     441,   234,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    43,    60,    71,    74,    75,
      82,    88,    90,    92,    94,    96,    97,   107,   113,   114,
     116,   117,   118,   121,   146,   150,   151,   152,   153,   154,
     155,   156,   206,   207,   218,   219,   227,   229,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     494,   498,   499,   500,   501,   234,   234,   234,     1,    98,
     120,   246,   247,   248,   249,   234,   234,   234,     1,    34,
      44,    45,    46,    49,    50,    54,    55,    56,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,     1,
      28,    30,    58,    68,    89,    93,   101,   104,   105,   134,
     209,   211,   212,   214,   215,   216,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   234,     1,   223,   290,   291,   292,
     293,   294,   234,     1,   101,   382,   383,   384,   234,   232,
     235,   235,   235,   233,   271,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   233,
     504,     1,    17,    18,    22,    67,    85,    86,    91,    95,
     101,   110,   111,   112,   122,   143,   182,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     1,     3,     5,    19,    39,    57,
      59,    67,    79,   101,   123,   142,   158,   208,   210,   211,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   421,   422,   423,   424,   425,     1,    65,   126,
     434,   435,   436,   437,   235,   233,   440,     1,   101,   126,
     444,   445,   446,   447,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   495,
     491,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   233,
     450,     1,    19,    39,    67,   119,   127,   128,   147,   224,
     361,   362,   363,   364,   365,   366,   367,   371,   372,   373,
       1,   126,   224,   428,   429,   430,   431,     1,    57,    65,
      67,   123,   347,   351,   352,   353,   357,   358,   232,   235,
     235,   233,   247,     1,    81,   169,   277,   278,   279,   280,
       1,    19,    39,    67,   101,   119,   196,   210,   213,   224,
     228,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   319,     1,    41,    81,   126,   376,   377,   378,
     379,   380,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   521,   232,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     233,   252,     1,   101,   221,   397,   398,   399,   400,   232,
     235,   233,   291,   169,     1,   101,   162,   180,   195,   283,
     284,   285,   286,   287,   288,   235,   233,   383,     1,   101,
     221,   224,   387,   388,   389,   390,   391,   124,   124,   124,
     232,   109,   109,   242,   205,   109,   242,   242,   242,   109,
     242,   242,   109,   109,   109,   109,   232,   232,   235,   235,
     235,   342,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   326,   232,   235,   235,   235,   235,
     235,   235,   418,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   407,   235,   235,   233,   435,   124,   232,   235,
     235,   233,   445,   205,   242,   109,   242,   242,   205,   109,
     242,   205,   109,   109,   109,   205,   205,   242,   109,   109,
     109,   109,   242,   109,   109,   109,   109,   205,   235,   235,
     205,   242,   242,   205,   205,   205,   205,   217,   205,   217,
     205,   205,   205,   205,   109,   242,   242,   242,   205,   109,
     232,   232,   235,   235,   368,   235,   235,   235,   235,   235,
     233,   362,   235,   235,   233,   429,   232,   235,   235,   348,
     235,   233,   352,   124,   124,   232,   232,   235,   235,   233,
     278,   232,   235,   235,   320,   235,   235,   316,   235,   235,
     235,   235,   233,   306,   232,   235,   235,   235,   233,   377,
     205,   205,   242,   124,   205,   124,   205,   205,   205,   232,
     109,   124,   205,   124,   109,   109,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   232,   232,   235,   401,
     233,   398,   205,   232,   234,   232,   235,   235,   235,   235,
     233,   284,   124,   232,   232,   235,   392,   235,   233,   388,
     232,   232,   232,   232,   135,   136,   137,   138,   139,   140,
     141,   241,   242,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   109,   109,   242,   235,
     109,   242,   109,   242,   124,   109,   109,   109,   242,   109,
     244,   244,   232,   124,   173,   174,   124,   205,   124,   124,
     235,   124,   124,   109,   124,   124,   242,   124,   124,   232,
     124,   124,   232,   232,   124,   124,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,    42,    49,   159,   160,   161,   164,   165,   167,
     168,   170,   172,   175,   177,   178,   183,   187,   191,   192,
     193,   197,   202,   496,   497,    42,    49,    51,    52,   159,
     160,   161,   164,   165,   167,   168,   170,   172,   175,   177,
     178,   183,   187,   191,   192,   193,   197,   202,   492,   493,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     124,   205,   235,   124,   109,   124,   124,   124,   232,   124,
     124,   232,   124,   124,   235,   109,   355,   356,   232,   232,
     232,   124,   124,   232,   124,   205,   235,   124,   124,   235,
     124,   205,   124,   124,   232,   124,   124,   124,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   124,   235,   232,   232,     1,   101,
     190,   221,   295,   296,   297,   298,   299,   124,   124,   124,
     124,   232,   232,   124,   235,   124,   232,   241,   241,   241,
     241,   241,   241,   241,   232,   232,   232,    53,   125,   343,
     344,   232,   232,   232,   232,   232,   232,   232,   232,   232,
      11,    12,    13,   243,   244,   232,   232,   232,   232,   232,
     232,   232,   232,   232,     8,   194,   419,   420,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   236,   232,   236,   232,   232,    15,    40,    73,   102,
     103,   108,   133,   148,   204,   231,   369,   370,   232,   232,
     232,   232,   232,   232,   232,   232,   232,    49,   185,   194,
     349,   350,   220,   236,   354,   232,   232,   232,   232,     4,
      20,    21,    31,    69,    70,    72,    98,   106,   129,   131,
     132,   149,   166,   171,   175,   179,   184,   188,   198,   200,
     201,   203,   222,   230,   321,   322,   232,   232,    42,    49,
      51,    52,   159,   160,   161,   164,   165,   167,   168,   170,
     172,   175,   177,   178,   183,   187,   191,   192,   193,   197,
     202,   317,   318,   232,   232,   232,   232,   232,   232,   232,
     232,    72,   132,   157,   166,   175,   198,   200,   201,   222,
     230,   402,   403,   232,   235,   235,   300,   233,   296,   232,
     232,   232,   232,   232,    72,   132,   157,   166,   175,   198,
     200,   201,   222,   230,   393,   394,   232,   232,   236,   243,
     243,   243,   232,   236,   497,   493,   232,   236,   232,   236,
     109,   356,   232,   237,   237,   237,   237,   237,   237,   232,
     236,   232,   236,   232,   236,   124,   199,   244,   235,   232,
     232,   236,   344,   420,   370,   350,   130,   132,   130,   132,
     130,   130,   322,   318,   403,   232,   232,   232,    70,    72,
     115,   132,   165,   166,   224,   230,   301,   302,   394,   232,
     236,   302
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   238,   239,   239,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   245,   246,   246,   247,   247,   247,
     248,   249,   250,   251,   251,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     270,   271,   271,   271,   271,   272,   273,   274,   276,   275,
     277,   277,   278,   278,   278,   279,   280,   282,   281,   283,
     283,   284,   284,   284,   284,   284,   285,   286,   287,   288,
     289,   290,   290,   291,   291,   291,   292,   294,   293,   295,
     295,   296,   296,   296,   296,   297,   298,   298,   300,   299,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   302,
     304,   303,   305,   305,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   316,   315,   317,   317,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     320,   319,   321,   321,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   324,   323,   325,   325,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   342,   341,   343,
     343,   344,   344,   346,   345,   348,   347,   349,   349,   350,
     350,   350,   351,   351,   352,   352,   352,   352,   352,   354,
     353,   355,   355,   356,   356,   357,   358,   360,   359,   361,
     361,   362,   362,   362,   362,   362,   362,   362,   362,   362,
     363,   364,   365,   366,   368,   367,   369,   369,   370,   370,
     370,   370,   370,   370,   370,   370,   370,   370,   371,   372,
     373,   375,   374,   376,   376,   377,   377,   377,   377,   378,
     379,   380,   381,   382,   382,   383,   383,   384,   386,   385,
     387,   387,   388,   388,   388,   388,   389,   390,   392,   391,
     393,   393,   394,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   396,   395,   397,   397,   398,   398,   398,   399,
     401,   400,   402,   402,   403,   403,   403,   403,   403,   403,
     403,   403,   403,   403,   405,   404,   406,   406,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   416,   418,   417,   419,   419,   420,   420,
     421,   422,   423,   424,   425,   427,   426,   428,   428,   429,
     429,   429,   430,   431,   433,   432,   434,   434,   435,   435,
     435,   436,   437,   438,   439,   439,   440,   440,   441,   443,
     442,   444,   444,   445,   445,   445,   446,   447,   448,   449,
     449,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   450,   450,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   476,   477,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   491,   490,
     492,   492,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   495,   494,   496,   496,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     498,   499,   500,   501,   502,   503,   503,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   520,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     2,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
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
#line 399 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2847 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2901 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 427 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2934 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 433 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2943 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 465 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 2955 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 73:
#line 474 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 2967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 483 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2979 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 492 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 2991 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 76:
#line 501 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 510 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3015 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 519 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3027 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 79:
#line 528 "conf_parser.y" /* yacc.c:1652  */
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
#line 3045 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 80:
#line 543 "conf_parser.y" /* yacc.c:1652  */
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
#line 3063 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 558 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3076 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 568 "conf_parser.y" /* yacc.c:1652  */
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
#line 3093 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 582 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3105 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 591 "conf_parser.y" /* yacc.c:1652  */
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
#line 3131 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 614 "conf_parser.y" /* yacc.c:1652  */
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
#line 3157 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 86:
#line 637 "conf_parser.y" /* yacc.c:1652  */
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
#line 3183 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 660 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3192 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 678 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3204 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 687 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3216 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 696 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3228 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 709 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 713 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 730 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 736 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3272 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 746 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 750 "conf_parser.y" /* yacc.c:1652  */
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
#line 3299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 768 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 774 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 780 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3326 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 786 "conf_parser.y" /* yacc.c:1652  */
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
#line 3347 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 814 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3356 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 128:
#line 824 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3378 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 840 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3389 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 848 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3397 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 851 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3405 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 856 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3414 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3423 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3432 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3441 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 879 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3459 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 883 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3468 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 887 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3477 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3486 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3498 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 908 "conf_parser.y" /* yacc.c:1652  */
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
#line 3557 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 977 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3566 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 983 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 989 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3584 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 995 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3593 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1001 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3607 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1012 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3616 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1018 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3630 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1029 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3639 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1035 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3648 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1042 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3657 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3666 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3675 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1054 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3702 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1066 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3711 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1070 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3720 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1074 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3729 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1078 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3738 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1086 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3765 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3774 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3783 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3792 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1126 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1130 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1136 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1147 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1159 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1163 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1167 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3936 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1183 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1187 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1191 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1195 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1199 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 3999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1203 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1207 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1215 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1227 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1231 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4080 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1239 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4089 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1243 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4098 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1247 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4107 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1251 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4116 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1255 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4125 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 1265 "conf_parser.y" /* yacc.c:1652  */
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
#line 4142 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 234:
#line 1277 "conf_parser.y" /* yacc.c:1652  */
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
#line 4190 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1340 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4199 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1346 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4208 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1352 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4217 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1358 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4226 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1364 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4235 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1370 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4244 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1376 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4253 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1382 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4262 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1388 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4272 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1395 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1401 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4290 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1407 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1413 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4311 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1422 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1431 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1438 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1442 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4350 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1452 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4359 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1458 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4367 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4376 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1468 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4385 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1472 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4394 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1480 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4400 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1485 "conf_parser.y" /* yacc.c:1652  */
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
#line 4418 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1498 "conf_parser.y" /* yacc.c:1652  */
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
#line 4438 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1515 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4447 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1521 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4456 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1531 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4465 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1535 "conf_parser.y" /* yacc.c:1652  */
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
#line 4511 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1589 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4520 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1595 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4529 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1601 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4538 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
#line 1607 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4552 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1618 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4561 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1625 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4570 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1629 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1633 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1637 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1641 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4606 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1645 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1649 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1653 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4633 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1657 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4642 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1661 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4651 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1667 "conf_parser.y" /* yacc.c:1652  */
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
#line 4668 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1681 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4680 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1690 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4692 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1703 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4704 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 332:
#line 1710 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4715 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1721 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1727 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4733 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 341:
#line 1733 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4742 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1748 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4757 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1764 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 349:
#line 1775 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4788 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1790 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4797 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1796 "conf_parser.y" /* yacc.c:1652  */
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
#line 4819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 358:
#line 1815 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1822 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1826 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1830 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1834 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1842 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1846 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1850 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1854 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1858 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1868 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4932 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 373:
#line 1877 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 380:
#line 1896 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1903 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 4999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1923 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1931 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1939 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
#line 1949 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5068 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 395:
#line 1959 "conf_parser.y" /* yacc.c:1652  */
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
#line 5139 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2045 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5148 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2051 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5157 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2057 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5166 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2063 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5175 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2069 "conf_parser.y" /* yacc.c:1652  */
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
#line 5191 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2082 "conf_parser.y" /* yacc.c:1652  */
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
#line 5207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5216 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2101 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5225 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2107 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5234 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5243 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2117 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5251 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2123 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5260 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5269 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2133 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5283 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2144 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5292 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2150 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5301 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2156 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5310 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2162 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5324 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2177 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5333 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 436:
#line 2181 "conf_parser.y" /* yacc.c:1652  */
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
#line 5356 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2204 "conf_parser.y" /* yacc.c:1652  */
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
#line 5379 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2224 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5388 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2234 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5397 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 445:
#line 2238 "conf_parser.y" /* yacc.c:1652  */
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
#line 5421 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2262 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5430 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 452:
#line 2268 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5439 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2283 "conf_parser.y" /* yacc.c:1652  */
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
#line 5456 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2300 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5465 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 460:
#line 2304 "conf_parser.y" /* yacc.c:1652  */
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
#line 5485 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2324 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5494 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 467:
#line 2330 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5503 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2391 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5511 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2396 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5519 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2401 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5527 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2406 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5535 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2411 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5543 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2416 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5551 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2421 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5559 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2426 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5567 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2431 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2436 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2441 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5591 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2446 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5599 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2451 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5607 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2456 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2461 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5623 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2466 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5631 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2471 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5639 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2476 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5647 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2481 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5655 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2486 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5663 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2491 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5671 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2496 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5679 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2501 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5687 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2506 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5695 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2511 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5703 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2516 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5711 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2519 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5719 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2524 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5727 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2527 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5735 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2532 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5743 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2537 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5751 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2542 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5759 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2547 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5767 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2552 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2557 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5783 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2562 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5791 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2567 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5799 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2572 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5807 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2577 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5815 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2582 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5823 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 557:
#line 2587 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 558:
#line 2592 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5839 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2598 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5847 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2601 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2604 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5863 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2607 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2610 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2613 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5887 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2616 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2619 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2622 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5911 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2625 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5919 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2628 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2631 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5935 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2634 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5943 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2637 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5951 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2640 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5959 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2643 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2646 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5975 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2649 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5983 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2652 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5991 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2655 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2658 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6007 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2661 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6015 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 584:
#line 2664 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6023 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2669 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6031 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2675 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2678 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6047 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2681 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6055 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2684 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6063 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2687 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2690 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6079 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2693 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6087 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2696 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6095 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2699 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6103 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2702 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6111 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2705 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6119 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2708 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6127 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2711 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6135 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2714 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6143 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2717 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6151 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2720 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6159 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2723 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6167 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2726 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6175 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2729 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6183 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2732 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6191 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2735 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6199 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2740 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2745 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 612:
#line 2750 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6223 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 613:
#line 2755 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6231 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2783 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2788 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6247 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2793 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6255 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2798 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2803 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2808 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6279 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2813 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6287 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2818 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6295 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2823 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2828 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6311 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2833 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6319 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2838 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6327 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2843 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6335 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 645:
#line 2848 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6343 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6352 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2877 "conf_parser.y" /* yacc.c:1652  */
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
#line 6371 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2893 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6383 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6392 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2908 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2914 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6410 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2920 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2929 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6431 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 667:
#line 2935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6440 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6444 "conf_parser.c" /* yacc.c:1652  */
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
