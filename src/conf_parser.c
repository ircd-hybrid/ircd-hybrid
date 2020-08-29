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
    DENY = 285,
    DESCRIPTION = 286,
    DIE = 287,
    DISABLE_AUTH = 288,
    DISABLE_FAKE_CHANNELS = 289,
    DISABLE_REMOTE_COMMANDS = 290,
    DLINE_MIN_CIDR = 291,
    DLINE_MIN_CIDR6 = 292,
    DOTS_IN_IDENT = 293,
    EMAIL = 294,
    ENABLE_EXTBANS = 295,
    ENCRYPTED = 296,
    EXCEED_LIMIT = 297,
    EXEMPT = 298,
    EXPIRATION = 299,
    FAILED_OPER_NOTICE = 300,
    FLATTEN_LINKS = 301,
    FLATTEN_LINKS_DELAY = 302,
    FLATTEN_LINKS_FILE = 303,
    GECOS = 304,
    GENERAL = 305,
    HIDDEN = 306,
    HIDDEN_NAME = 307,
    HIDE_CHANS = 308,
    HIDE_IDLE = 309,
    HIDE_IDLE_FROM_OPERS = 310,
    HIDE_SERVER_IPS = 311,
    HIDE_SERVERS = 312,
    HIDE_SERVICES = 313,
    HOST = 314,
    HUB = 315,
    HUB_MASK = 316,
    INVISIBLE_ON_CONNECT = 317,
    INVITE_CLIENT_COUNT = 318,
    INVITE_CLIENT_TIME = 319,
    INVITE_DELAY_CHANNEL = 320,
    INVITE_EXPIRE_TIME = 321,
    IP = 322,
    IRCD_AUTH = 323,
    IRCD_FLAGS = 324,
    IRCD_SID = 325,
    JOIN = 326,
    KILL = 327,
    KILL_CHASE_TIME_LIMIT = 328,
    KLINE = 329,
    KLINE_EXEMPT = 330,
    KLINE_MIN_CIDR = 331,
    KLINE_MIN_CIDR6 = 332,
    KNOCK_CLIENT_COUNT = 333,
    KNOCK_CLIENT_TIME = 334,
    KNOCK_DELAY_CHANNEL = 335,
    LEAF_MASK = 336,
    LISTEN = 337,
    MASK = 338,
    MAX_ACCEPT = 339,
    MAX_BANS = 340,
    MAX_BANS_LARGE = 341,
    MAX_CHANNELS = 342,
    MAX_IDLE = 343,
    MAX_INVITES = 344,
    MAX_NICK_CHANGES = 345,
    MAX_NICK_LENGTH = 346,
    MAX_NICK_TIME = 347,
    MAX_NUMBER = 348,
    MAX_TARGETS = 349,
    MAX_TOPIC_LENGTH = 350,
    MAX_WATCH = 351,
    MIN_IDLE = 352,
    MIN_NONWILDCARD = 353,
    MIN_NONWILDCARD_SIMPLE = 354,
    MODULE = 355,
    MODULES = 356,
    MOTD = 357,
    NAME = 358,
    NEED_IDENT = 359,
    NEED_PASSWORD = 360,
    NETWORK_DESC = 361,
    NETWORK_NAME = 362,
    NICK = 363,
    NO_OPER_FLOOD = 364,
    NO_TILDE = 365,
    NUMBER = 366,
    NUMBER_PER_CIDR = 367,
    NUMBER_PER_IP_GLOBAL = 368,
    NUMBER_PER_IP_LOCAL = 369,
    OPER_ONLY_UMODES = 370,
    OPER_UMODES = 371,
    OPERATOR = 372,
    OPERS_BYPASS_CALLERID = 373,
    PACE_WAIT = 374,
    PACE_WAIT_SIMPLE = 375,
    PASSWORD = 376,
    PATH = 377,
    PING_COOKIE = 378,
    PING_TIME = 379,
    PORT = 380,
    QSTRING = 381,
    RANDOM_IDLE = 382,
    REASON = 383,
    REDIRPORT = 384,
    REDIRSERV = 385,
    REHASH = 386,
    REMOTE = 387,
    REMOTEBAN = 388,
    RESV = 389,
    RESV_EXEMPT = 390,
    RSA_PRIVATE_KEY_FILE = 391,
    SECONDS = 392,
    MINUTES = 393,
    HOURS = 394,
    DAYS = 395,
    WEEKS = 396,
    MONTHS = 397,
    YEARS = 398,
    SEND_PASSWORD = 399,
    SENDQ = 400,
    SERVERHIDE = 401,
    SERVERINFO = 402,
    SHORT_MOTD = 403,
    SPOOF = 404,
    SQUIT = 405,
    STATS_E_DISABLED = 406,
    STATS_I_OPER_ONLY = 407,
    STATS_K_OPER_ONLY = 408,
    STATS_M_OPER_ONLY = 409,
    STATS_O_OPER_ONLY = 410,
    STATS_P_OPER_ONLY = 411,
    STATS_U_OPER_ONLY = 412,
    T_ALL = 413,
    T_BIND = 414,
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
    T_TARGET = 450,
    T_TLS = 451,
    T_UMODES = 452,
    T_UNAUTH = 453,
    T_UNDLINE = 454,
    T_UNLIMITED = 455,
    T_UNRESV = 456,
    T_UNXLINE = 457,
    T_WALLOP = 458,
    T_WALLOPS = 459,
    T_WEBIRC = 460,
    TBOOL = 461,
    THROTTLE_COUNT = 462,
    THROTTLE_TIME = 463,
    TIMEOUT = 464,
    TLS_CERTIFICATE_FILE = 465,
    TLS_CERTIFICATE_FINGERPRINT = 466,
    TLS_CIPHER_LIST = 467,
    TLS_CIPHER_SUITES = 468,
    TLS_CONNECTION_REQUIRED = 469,
    TLS_DH_PARAM_FILE = 470,
    TLS_MESSAGE_DIGEST_ALGORITHM = 471,
    TLS_SUPPORTED_GROUPS = 472,
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
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_REMOTE_COMMANDS 290
#define DLINE_MIN_CIDR 291
#define DLINE_MIN_CIDR6 292
#define DOTS_IN_IDENT 293
#define EMAIL 294
#define ENABLE_EXTBANS 295
#define ENCRYPTED 296
#define EXCEED_LIMIT 297
#define EXEMPT 298
#define EXPIRATION 299
#define FAILED_OPER_NOTICE 300
#define FLATTEN_LINKS 301
#define FLATTEN_LINKS_DELAY 302
#define FLATTEN_LINKS_FILE 303
#define GECOS 304
#define GENERAL 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_CHANS 308
#define HIDE_IDLE 309
#define HIDE_IDLE_FROM_OPERS 310
#define HIDE_SERVER_IPS 311
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HOST 314
#define HUB 315
#define HUB_MASK 316
#define INVISIBLE_ON_CONNECT 317
#define INVITE_CLIENT_COUNT 318
#define INVITE_CLIENT_TIME 319
#define INVITE_DELAY_CHANNEL 320
#define INVITE_EXPIRE_TIME 321
#define IP 322
#define IRCD_AUTH 323
#define IRCD_FLAGS 324
#define IRCD_SID 325
#define JOIN 326
#define KILL 327
#define KILL_CHASE_TIME_LIMIT 328
#define KLINE 329
#define KLINE_EXEMPT 330
#define KLINE_MIN_CIDR 331
#define KLINE_MIN_CIDR6 332
#define KNOCK_CLIENT_COUNT 333
#define KNOCK_CLIENT_TIME 334
#define KNOCK_DELAY_CHANNEL 335
#define LEAF_MASK 336
#define LISTEN 337
#define MASK 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_BANS_LARGE 341
#define MAX_CHANNELS 342
#define MAX_IDLE 343
#define MAX_INVITES 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_LENGTH 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_TOPIC_LENGTH 350
#define MAX_WATCH 351
#define MIN_IDLE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define MOTD 357
#define NAME 358
#define NEED_IDENT 359
#define NEED_PASSWORD 360
#define NETWORK_DESC 361
#define NETWORK_NAME 362
#define NICK 363
#define NO_OPER_FLOOD 364
#define NO_TILDE 365
#define NUMBER 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP_GLOBAL 368
#define NUMBER_PER_IP_LOCAL 369
#define OPER_ONLY_UMODES 370
#define OPER_UMODES 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define PACE_WAIT 374
#define PACE_WAIT_SIMPLE 375
#define PASSWORD 376
#define PATH 377
#define PING_COOKIE 378
#define PING_TIME 379
#define PORT 380
#define QSTRING 381
#define RANDOM_IDLE 382
#define REASON 383
#define REDIRPORT 384
#define REDIRSERV 385
#define REHASH 386
#define REMOTE 387
#define REMOTEBAN 388
#define RESV 389
#define RESV_EXEMPT 390
#define RSA_PRIVATE_KEY_FILE 391
#define SECONDS 392
#define MINUTES 393
#define HOURS 394
#define DAYS 395
#define WEEKS 396
#define MONTHS 397
#define YEARS 398
#define SEND_PASSWORD 399
#define SENDQ 400
#define SERVERHIDE 401
#define SERVERINFO 402
#define SHORT_MOTD 403
#define SPOOF 404
#define SQUIT 405
#define STATS_E_DISABLED 406
#define STATS_I_OPER_ONLY 407
#define STATS_K_OPER_ONLY 408
#define STATS_M_OPER_ONLY 409
#define STATS_O_OPER_ONLY 410
#define STATS_P_OPER_ONLY 411
#define STATS_U_OPER_ONLY 412
#define T_ALL 413
#define T_BIND 414
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
#define T_TARGET 450
#define T_TLS 451
#define T_UMODES 452
#define T_UNAUTH 453
#define T_UNDLINE 454
#define T_UNLIMITED 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_WALLOP 458
#define T_WALLOPS 459
#define T_WEBIRC 460
#define TBOOL 461
#define THROTTLE_COUNT 462
#define THROTTLE_TIME 463
#define TIMEOUT 464
#define TLS_CERTIFICATE_FILE 465
#define TLS_CERTIFICATE_FINGERPRINT 466
#define TLS_CIPHER_LIST 467
#define TLS_CIPHER_SUITES 468
#define TLS_CONNECTION_REQUIRED 469
#define TLS_DH_PARAM_FILE 470
#define TLS_MESSAGE_DIGEST_ALGORITHM 471
#define TLS_SUPPORTED_GROUPS 472
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
#define YYLAST   1266

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  667
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1313

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
    1246,  1250,  1254,  1265,  1264,  1320,  1320,  1321,  1322,  1323,
    1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1336,  1338,  1344,  1350,  1356,  1362,  1368,  1374,
    1380,  1386,  1393,  1399,  1405,  1411,  1420,  1430,  1429,  1435,
    1435,  1436,  1440,  1451,  1450,  1457,  1456,  1461,  1461,  1462,
    1466,  1470,  1474,  1480,  1480,  1481,  1481,  1481,  1481,  1481,
    1483,  1483,  1485,  1485,  1487,  1500,  1517,  1523,  1534,  1533,
    1580,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,
    1589,  1591,  1597,  1603,  1609,  1621,  1620,  1626,  1626,  1627,
    1631,  1635,  1639,  1643,  1647,  1651,  1655,  1659,  1665,  1679,
    1688,  1702,  1701,  1716,  1716,  1717,  1717,  1717,  1717,  1719,
    1725,  1731,  1741,  1743,  1743,  1744,  1744,  1746,  1763,  1762,
    1785,  1785,  1786,  1786,  1786,  1786,  1788,  1794,  1814,  1813,
    1819,  1819,  1820,  1824,  1828,  1832,  1836,  1840,  1844,  1848,
    1852,  1856,  1867,  1866,  1885,  1885,  1886,  1886,  1886,  1888,
    1895,  1894,  1900,  1900,  1901,  1905,  1909,  1913,  1917,  1921,
    1925,  1929,  1933,  1937,  1948,  1947,  2025,  2025,  2026,  2027,
    2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,
    2038,  2039,  2040,  2041,  2043,  2049,  2055,  2061,  2067,  2080,
    2093,  2099,  2105,  2109,  2116,  2115,  2120,  2120,  2121,  2125,
    2131,  2142,  2148,  2154,  2160,  2176,  2175,  2199,  2199,  2200,
    2200,  2200,  2202,  2222,  2233,  2232,  2257,  2257,  2258,  2258,
    2258,  2260,  2266,  2276,  2278,  2278,  2279,  2279,  2281,  2299,
    2298,  2319,  2319,  2320,  2320,  2320,  2322,  2328,  2338,  2340,
    2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,
    2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,
    2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,
    2380,  2381,  2382,  2383,  2384,  2385,  2386,  2389,  2394,  2399,
    2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,  2449,
    2454,  2459,  2464,  2469,  2474,  2479,  2484,  2489,  2494,  2499,
    2504,  2509,  2514,  2519,  2524,  2529,  2534,  2539,  2544,  2549,
    2554,  2559,  2564,  2569,  2574,  2579,  2585,  2584,  2589,  2589,
    2590,  2593,  2596,  2599,  2602,  2605,  2608,  2611,  2614,  2617,
    2620,  2623,  2626,  2629,  2632,  2635,  2638,  2641,  2644,  2647,
    2650,  2653,  2656,  2662,  2661,  2666,  2666,  2667,  2670,  2673,
    2676,  2679,  2682,  2685,  2688,  2691,  2694,  2697,  2700,  2703,
    2706,  2709,  2712,  2715,  2718,  2721,  2724,  2727,  2732,  2737,
    2742,  2747,  2756,  2758,  2758,  2759,  2760,  2761,  2762,  2763,
    2764,  2765,  2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,
    2774,  2776,  2781,  2786,  2791,  2796,  2801,  2806,  2811,  2816,
    2821,  2826,  2831,  2836,  2841,  2846,  2855,  2857,  2857,  2858,
    2859,  2860,  2861,  2862,  2863,  2864,  2865,  2866,  2867,  2869,
    2875,  2891,  2900,  2906,  2912,  2918,  2927,  2933
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -1048

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1048)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
   -1048,   678, -1048,  -148,  -218,  -197, -1048, -1048, -1048,  -191,
   -1048,  -172, -1048, -1048, -1048,  -165, -1048, -1048, -1048,  -147,
    -115, -1048,  -107, -1048,   -82, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   216,   925,   -72,   -66,   -65,    23,   -63,   441,   -60,
     -57,   -47,    26,   -46,   -21,   -16,   564,   365,   -15,     2,
     -14,    21,    -1,   -26,    36,    50,    59,    13, -1048, -1048,
   -1048, -1048, -1048,    64,    66,    69,    79,    80,    82,    85,
      87,    89,    92,    94,    96,   103,   107,   109,   201, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,   623,   544,    16, -1048,   110,
      44, -1048, -1048,    63, -1048,   117,   119,   122,   123,   124,
     129,   130,   138,   139,   140,   141,   144,   145,   147,   148,
     149,   150,   154,   162,   164,   168,   169,   170,   171,   173,
   -1048, -1048,   176,   177,   180,   182,   183,   185,   186,   187,
     188,   191,   194,   198,   203,   204,   205,   208,   210,   214,
      41, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,   359,    48,    29,
     -25,   217,   219,    12, -1048, -1048, -1048,     8,   390,    17,
   -1048,   223,   226,   229,   234,   235,   238,   240,   241,   246,
      24, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,    70,   247,   248,   249,   250,   252,   255,   256,   257,
     270,   271,   275,   277,   278,   280,   281,   284,   120, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,    55,    78,   288,    11,
   -1048, -1048, -1048,    73,   200, -1048,   289,    67, -1048, -1048,
     127, -1048,   221,   290,   310,   295, -1048,   244,   398,   323,
     324,   423,   398,   398,   398,   425,   398,   398,   427,   430,
     431,   432,   312, -1048,   314,   313,   316,   317, -1048,   318,
     319,   320,   327,   331,   332,   333,   334,   335,   338,   341,
     274, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,   326,   344,   349,
     351,   353,   355,   367, -1048,   371,   372,   374,   382,   384,
     388,   392,   393,   181, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   394,   395,    25, -1048, -1048, -1048,   506,   403, -1048,
   -1048,   401,   402,    19, -1048, -1048, -1048,   433,   398,   527,
     398,   398,   436,   532,   398,   438,   534,   540,   550,   456,
     457,   398,   553,   554,   555,   560,   398,   562,   563,   566,
     570,   469,   448,   449,   481,   398,   398,   484,   485,   492,
     499,   501,   503,   507,   508,   509,   595,   398,   398,   398,
     511,   601,   486, -1048,   487,   488,   489, -1048,   490,   494,
     496,   498,   505,   220, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   510,   513,    45, -1048, -1048, -1048,
     502,   514,   516, -1048,   517, -1048,    30, -1048, -1048, -1048,
   -1048, -1048,   612,   617,   512, -1048,   522,   523,   524,    40,
   -1048, -1048, -1048,   525,   526,   528, -1048,   529,   530, -1048,
     531,   535,   537,   538,   213, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,   542,   541,   546,   547,
      18, -1048, -1048, -1048, -1048,   556,   561,   398,   643,   569,
     651,   577,   578,   579,   557, -1048, -1048,   675,   661,   582,
     664,   680,   681,   667,   668,   670,   671,   672,   673,   674,
     679,   683,   690,   585, -1048,   587,   588, -1048,     3, -1048,
   -1048, -1048, -1048,   608,   590, -1048,   567,   596,   592,   594,
     597,   598,     4, -1048, -1048, -1048, -1048, -1048,   705,   605,
   -1048,   606,   611, -1048,   616,    72, -1048, -1048, -1048, -1048,
     609,   615,   620, -1048,   626,   515,   630,   631,   637,   638,
     639,   641,   645,   646,   647,   652,   653,   658,   662,   665,
   -1048, -1048,   732,   763,   398,   640,   772,   398,   790,   398,
     776,   796,   797,   798,   398,   799,   799,   682, -1048, -1048,
     786,   -81,   787,   710,   791,   792,   687,   801,   803,   813,
     805,   807,   398,   808,   809,   704, -1048,   812,   814,   707,
   -1048,   711, -1048,   816,   818,   713, -1048,   715,   716,   717,
     718,   719,   722,   723,   724,   725,   726,   728,   729,   730,
     731,   736,   738,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   727,   642,   750,   751,   752,   753,   754,   761,
     762,   764,   766,   767,   769,   774,   775,   777,   781,   783,
     784,   785, -1048, -1048,   871,   802,   788,   876,   907,   893,
     894,   895,   793, -1048,   896,   898,   794, -1048, -1048,   901,
     902,   795,   918,   800, -1048,   804,   806, -1048, -1048,   905,
     908,   810, -1048, -1048,   909,   827,   811,   911,   913,   815,
     914,   835,   917,   919,   817, -1048, -1048,   921,   922,   926,
     819, -1048,   821,   822,   823,   824,   825,   826,   828,   829,
     830, -1048,   831,   832,   833,   834,   836,   837,   838,   839,
     840,   841,   842,   843,   844,   845,   846,   847, -1048, -1048,
     933,   848,   849, -1048,   850, -1048,   135, -1048,   941,   954,
     958,   959,   854, -1048,   855, -1048, -1048,   962,   856,   963,
     858, -1048, -1048, -1048, -1048, -1048,   398,   398,   398,   398,
     398,   398,   398, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,   860,
     861,   862,   -32,   863,   864,   865,   866,   867,   868,   869,
     870,   872,    27,   873,   874, -1048,   875,   877,   878,   879,
     880,   881,   882,     7,   883,   884,   885,   886,   887,   888,
     889,   890, -1048,   891,   892, -1048, -1048,   897,   899, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,  -204, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,  -203, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   900,   903,   297,   904,   906,   910,   912,   915, -1048,
     916,   920, -1048,   923,   924,   112,   929,   927, -1048, -1048,
   -1048, -1048,   928,   930, -1048,   932,   934,   500,   935,   936,
     688,   937,   938,   939,   940, -1048,   942,   943,   944, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,   945,   765, -1048, -1048,   946,
     947,   948, -1048,    62, -1048, -1048, -1048, -1048,   949,   952,
     953,   955, -1048, -1048,   956,   770,   957, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
    -179, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   799,   799,   799, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,  -178, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   727, -1048,   642, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,  -123, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   -53, -1048,   992,   918,   960, -1048, -1048, -1048, -1048,
   -1048, -1048,   961, -1048,   964,   965, -1048, -1048,   966,   967,
   -1048, -1048,   968, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,   -28, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   -27, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   -20, -1048, -1048,   982,   -90,   951,   974, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,    75, -1048, -1048, -1048,   -32,
   -1048, -1048, -1048, -1048,     7, -1048, -1048, -1048,   297, -1048,
     112, -1048, -1048, -1048,   993,   994,   995,   996,  1001,  1002,
   -1048,   500, -1048,   688, -1048,   765,   975,   976,   977,   296,
   -1048, -1048,   770, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048,    77, -1048, -1048,
   -1048,   296, -1048
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   233,   394,   444,     0,
     459,     0,   298,   435,   273,     0,    98,   150,   331,     0,
       0,   372,     0,   107,     0,   348,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   614,
     629,   628,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   615,   616,   626,   627,     0,     0,     0,   457,     0,
       0,   455,   456,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     583,   556,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   514,   478,   515,   509,   510,   511,
     512,   482,   473,   474,   475,   476,   477,   479,   480,   481,
     483,   484,   513,   488,   489,   490,   491,   487,   486,   492,
     499,   500,   493,   494,   495,   485,   497,   507,   508,   505,
     506,   498,   496,   503,   504,   501,   502,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   648,   649,   650,   651,   652,   653,   654,   656,   655,
     657,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   346,     0,     0,   344,   345,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   613,     0,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,   240,   242,   243,   244,   245,   246,   247,
     248,   238,   239,   241,   249,   250,   251,     0,     0,     0,
       0,     0,     0,     0,   424,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   397,   398,   399,   400,   401,   402,
     403,   404,   406,   405,   408,   412,   409,   410,   411,   407,
     450,     0,     0,     0,   447,   448,   449,     0,     0,   454,
     465,     0,     0,     0,   462,   463,   464,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   469,     0,     0,     0,   315,     0,     0,
       0,     0,     0,     0,   301,   302,   303,   304,   309,   305,
     306,   307,   308,   441,     0,     0,     0,   438,   439,   440,
       0,     0,     0,   275,     0,   286,     0,   284,   285,   287,
     288,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   200,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   334,   335,   336,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   647,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   380,     0,   375,
     376,   377,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     343,     0,     0,   358,     0,     0,   351,   352,   353,   354,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     612,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   396,     0,     0,     0,
     446,     0,   453,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   468,   310,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   300,     0,     0,     0,   437,   289,     0,
       0,     0,     0,     0,   283,     0,     0,    44,   104,     0,
       0,     0,   100,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   338,     0,     0,     0,
       0,   333,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   646,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   378,
       0,     0,     0,   374,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   342,   355,     0,     0,     0,
       0,   350,    97,    96,    95,   644,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   645,   632,   631,   633,   634,
     635,   636,   637,   638,   639,   642,   643,   640,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   395,     0,     0,   445,   458,     0,     0,   460,
     528,   532,   517,   518,   545,   521,   610,   611,   553,   522,
     523,   550,   527,   535,   526,   524,   525,   531,   530,   529,
     551,   519,   608,   609,   549,   607,   593,   587,   603,   588,
     589,   590,   598,   606,   591,   600,   604,   594,   605,   595,
     599,   592,   602,   597,   596,   601,     0,   586,   582,   565,
     566,   567,   560,   578,   561,   562,   563,   573,   581,   564,
     575,   579,   569,   580,   570,   574,   568,   577,   572,   571,
     576,     0,   559,   546,   544,   547,   552,   548,   537,   543,
     542,   538,   539,   540,   541,   554,   555,   534,   533,   536,
     520,     0,     0,     0,     0,     0,     0,     0,     0,   299,
       0,     0,   436,     0,     0,     0,   294,   290,   293,   274,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   332,
     662,   659,   660,   661,   666,   665,   667,   663,   664,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   373,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   347,     0,     0,     0,   349,    31,    32,
      33,    34,    35,    36,    37,   262,   263,   257,   272,   271,
       0,   270,   258,   266,   259,   265,   253,   264,   256,   255,
     254,    38,    38,    38,    40,    39,   260,   261,   419,   422,
     423,   433,   430,   415,   431,   428,   429,     0,   427,   432,
     414,   421,   418,   417,   416,   420,   434,   451,   452,   466,
     467,   584,     0,   557,     0,   313,   314,   323,   319,   320,
     322,   327,   324,   325,   326,   321,     0,   318,   312,   330,
     329,   328,   311,   443,   442,   297,   296,   282,   280,   281,
     279,     0,   278,     0,     0,     0,   105,   106,   172,   169,
     220,   232,   207,   216,     0,   205,   210,   226,     0,   219,
     224,   230,   209,   212,   221,   223,   227,   217,   225,   213,
     231,   215,   222,   211,   214,     0,   203,   165,   167,   199,
     182,   183,   184,   177,   195,   178,   179,   180,   190,   198,
     181,   192,   196,   186,   197,   187,   191,   185,   194,   189,
     188,   193,     0,   176,   170,   171,   166,   168,   341,   339,
     340,   379,   384,   390,   393,   386,   392,   387,   391,   389,
     385,   388,     0,   383,   134,     0,     0,     0,     0,   129,
     117,   116,   118,   119,   356,   362,   368,   371,   364,   370,
     365,   369,   367,   363,   366,     0,   361,   357,   268,     0,
      41,    42,    43,   425,     0,   585,   558,   316,     0,   276,
       0,   295,   292,   291,     0,     0,     0,     0,     0,     0,
     201,     0,   174,     0,   381,     0,     0,     0,     0,     0,
     128,   359,     0,   269,   426,   317,   277,   206,   229,   204,
     228,   218,   208,   202,   175,   382,   135,   137,   136,   148,
     147,   143,   145,   149,   146,   142,   144,     0,   141,   360,
     139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1048, -1048, -1048,  -322,  -306, -1047,  -635, -1048, -1048,   931,
   -1048, -1048, -1048, -1048,   950, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048,  1049, -1048, -1048, -1048, -1048, -1048, -1048,
     545, -1048, -1048, -1048, -1048, -1048,   558, -1048, -1048, -1048,
   -1048, -1048, -1048,   852, -1048, -1048, -1048, -1048,   100, -1048,
   -1048, -1048, -1048, -1048,  -174, -1048, -1048, -1048,   625, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
    -128, -1048, -1048, -1048,  -125, -1048, -1048, -1048,   851, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048,   -99, -1048, -1048, -1048,
   -1048, -1048,  -109, -1048,   693, -1048, -1048, -1048,     9, -1048,
   -1048, -1048, -1048, -1048,   694, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,  -100, -1048, -1048, -1048, -1048, -1048, -1048,   629,
   -1048, -1048, -1048, -1048, -1048,   969, -1048, -1048, -1048, -1048,
     599, -1048, -1048, -1048, -1048, -1048,  -121, -1048, -1048, -1048,
     622, -1048, -1048, -1048, -1048,  -110, -1048, -1048, -1048,   820,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048,   -74, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048,   697, -1048, -1048, -1048, -1048, -1048,   853, -1048, -1048,
   -1048, -1048,  1075, -1048, -1048, -1048, -1048,   857, -1048, -1048,
   -1048, -1048,  1026, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048,    83, -1048, -1048, -1048,    88,
   -1048, -1048, -1048, -1048, -1048, -1048,  1101, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048,   970, -1048, -1048, -1048, -1048, -1048,
   -1048, -1048, -1048, -1048
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
    1046,  1047,  1227,  1307,  1308,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1202,
    1203,   525,   746,  1175,  1176,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1070,  1071,    35,    61,   485,
     731,  1141,  1142,   486,   487,   488,  1145,   987,   988,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1126,  1127,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1245,  1246,    40,    68,   568,
     569,   570,   571,   791,  1222,  1223,    41,    54,   373,   374,
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
     853,   854,   606,   287,   565,   577,   610,   611,   612,   496,
     614,   615,   287,   220,    73,  1095,    51,   390,   526,   526,
     400,   852,   295,  1068,   118,   230,   390,   220,  1111,  1113,
     480,   480,  1112,  1114,  1250,  1251,  1252,    52,  1081,  1082,
    1083,   496,   124,    56,    74,   118,   473,   125,   126,   473,
     127,   128,    75,  1248,  1253,   129,   565,  1249,  1254,   231,
     527,   527,    58,  1039,   400,   130,   131,   132,   295,    62,
     232,   233,   234,   591,   133,   235,   236,   134,   135,   136,
     237,   238,   239,   391,    49,    50,   137,    66,   481,   481,
     119,   497,   391,   857,   858,  1069,   482,   482,   483,   483,
     528,   528,   668,   138,   670,   671,   566,   578,   674,  1257,
    1277,   119,   221,  1258,   139,   681,    76,   140,   141,    67,
     686,   251,   401,   497,   296,   142,   221,    69,   591,   695,
     696,   143,  1137,   144,   222,   145,  1039,   146,   852,   147,
     148,   707,   708,   709,   392,   529,   529,   402,   222,   252,
     149,   253,    71,   392,   484,   484,   150,   151,   566,   152,
     153,   154,   115,  1138,   155,  1040,   401,   579,   116,   117,
     296,   123,  -127,   474,   217,   592,   474,   218,   498,  1259,
     254,  -127,   357,  1260,   358,   580,   359,   219,   227,   156,
     255,   402,   157,   158,   159,   160,   161,   162,   163,   581,
     360,   577,    82,  1096,  1270,  1272,   301,   491,  1271,  1273,
     498,   256,  1274,   228,   503,   257,  1275,    73,   229,   286,
     294,   454,   361,   258,   567,   288,   259,   260,    83,    84,
     592,   764,   504,   300,   288,    85,   792,   802,  1040,   455,
     362,    86,   363,   576,   574,   494,   305,    74,   164,   165,
     364,   760,   665,  1041,   505,    75,   261,   544,   659,   166,
     167,   456,   365,   733,    87,    88,    89,    90,   168,   475,
     169,   302,   475,   741,   452,   324,   567,   398,   726,    91,
      92,    93,   506,  1042,   366,   303,    94,    95,    96,   457,
      97,   325,   326,   593,   304,  1228,   594,   327,  1139,   307,
     589,   308,   546,   578,   309,   810,   367,  1281,  1140,  1310,
     572,  1282,  1117,  1311,   310,   311,   507,   312,   841,    76,
     313,   844,   314,   846,   315,   368,  1041,   316,   851,   317,
     262,   318,   263,   264,   508,   265,   266,   267,   319,  1118,
     369,   458,   320,   328,   321,   397,   869,   600,   593,   459,
     460,   594,   407,   563,   408,   604,  1042,   409,   410,   411,
     454,   329,   330,   579,   412,   413,   251,   331,  1299,   461,
    1300,   332,  1119,   414,   415,   416,   417,   333,   455,   418,
     419,   580,   420,   421,   422,   423,   334,   335,   336,   424,
     370,   503,   371,   372,   252,   581,   253,   425,   337,   426,
     456,  1120,  1121,   427,   428,   429,   430,  1122,   431,   504,
     509,   434,   435,  1301,   655,   436,   601,   437,   438,   338,
     439,   440,   441,   442,   510,   254,   443,   511,   457,   444,
    1302,   505,  1123,   445,   322,   255,   602,   512,   446,   447,
     448,   513,   124,   449,   462,   450,   754,   125,   126,   451,
     127,   128,   492,   722,   493,   129,   256,   339,   535,   506,
     257,   536,  1303,  1304,   537,   130,   131,   132,   258,   538,
     539,   259,   260,   540,   133,   541,   542,   134,   135,   136,
     458,   543,   547,   548,   549,   550,   137,   551,   459,   460,
     552,   553,   554,   507,  1058,  1059,  1060,  1061,  1062,  1063,
    1064,   261,  1124,   138,  1150,   555,   556,   637,   461,   605,
     557,   508,   558,   559,   139,   560,   561,   140,   141,   562,
    1305,  1151,  1152,   573,   588,   142,  1306,   603,  1125,   607,
     608,   143,  1153,   144,   609,   145,   613,   146,   616,   147,
     148,   617,   618,   619,   620,   357,   621,   358,   622,   359,
     149,   623,   624,   626,   627,   628,   150,   151,   639,   152,
     153,   154,   629,   360,   155,   230,   630,   631,   632,   633,
     634,  1154,  1155,   635,  1156,   262,   636,   263,   264,   640,
     265,   266,   267,   462,   641,   361,   642,   509,   643,   156,
     644,  1278,   157,   158,   159,   160,   161,   162,   163,   231,
    1157,   510,   645,   362,   511,   363,   647,   648,  1158,   649,
     232,   233,   234,   364,   512,   235,   236,   650,   513,   651,
     237,   238,   239,   652,   324,   365,   605,   653,   654,   657,
     658,  1159,   661,  1160,  1161,   662,   663,   664,   669,   667,
     325,   326,   672,   673,   675,   676,   327,   366,   164,   165,
    1162,   677,   816,   817,   818,   819,   820,   821,   822,   166,
     167,   678,   679,   680,   682,   683,   684,  1163,   168,   367,
     169,   685,  1164,   687,   688,   691,  1165,   689,     2,     3,
    1166,   690,     4,   692,   693,  1167,   928,   694,   368,  1168,
     697,   698,   328,   929,     5,   930,   931,     6,   699,  1169,
       7,  1170,  1171,   369,  1172,   700,   706,   701,     8,   702,
     329,   330,   711,   703,   704,   705,   331,   710,   712,   713,
     332,     9,  1173,   714,   715,   717,   333,    10,    11,   718,
    1174,   719,  1179,   720,   728,   334,   335,   336,   735,  1180,
     721,  1181,  1182,   736,   737,   724,    12,   337,   725,   729,
      13,   730,   732,   370,   738,   371,   372,   743,   739,   740,
      14,   744,   762,   745,   747,   748,   750,   763,   338,   765,
     751,   905,   752,   753,   756,   766,   757,   767,   906,    15,
      16,   758,   759,   768,   769,   770,   772,   773,   774,   771,
     775,   776,   777,   778,   779,    17,   780,   781,   782,   783,
     784,   796,   932,   933,   934,   785,   339,   935,   936,   786,
     937,   938,    18,   939,   794,   940,   787,   788,   941,   789,
     942,   943,   795,   790,    19,    20,   944,   798,   797,   799,
     945,   804,   800,   801,   946,   947,   948,   805,   806,  1212,
     949,   812,    21,   839,  1235,   950,   807,   813,  1183,  1184,
    1185,   809,   814,  1186,  1187,    22,  1188,  1189,   815,  1190,
      23,  1191,   825,   826,  1192,    24,  1193,  1194,    25,   827,
     828,   829,  1195,   830,   840,   842,  1196,   831,   832,   833,
    1197,  1198,  1199,   843,   834,   835,  1200,   907,   908,   909,
     836,  1201,   910,   911,   837,   912,   913,   838,   914,  1213,
     915,   845,   847,   916,  1236,   917,   918,   848,   849,   850,
     852,   919,   856,   859,   855,   920,   860,   861,   862,   921,
     922,   923,   863,  1214,   866,   924,    82,   864,  1237,   865,
     925,   867,  1215,   868,   870,   871,   872,  1238,   873,   875,
     874,  1216,   877,   876,   878,   879,  1239,   880,   881,   882,
     883,   884,    83,    84,   885,   886,   887,   888,   889,    85,
     890,   891,   892,   893,  1217,    86,  1218,  1219,   894,  1240,
     895,  1241,  1242,   896,   897,   898,   899,   900,   901,   902,
     903,   904,   953,   954,   955,   956,   957,  1220,    87,    88,
      89,    90,  1243,   958,   959,  1221,   960,   971,   961,   962,
    1244,   963,   974,    91,    92,    93,   964,   965,   972,   966,
      94,    95,    96,   967,    97,   968,   969,   970,   975,   976,
     977,   978,   980,   973,   981,   979,   982,   983,   984,   986,
     985,   992,   989,   996,   993,   995,   990,   998,   991,   999,
    1001,  1002,   994,  1003,   742,  1004,   997,  1006,  1007,  1005,
    1000,  1009,  1008,  1010,  1011,  1012,  1013,  1014,  1015,  1035,
    1016,  1017,  1018,  1019,  1020,  1021,  1022,  1048,  1023,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1049,  1037,  1038,  1036,  1050,  1051,  1052,  1053,  1054,  1056,
    1057,  1055,  1065,  1066,  1067,  1072,  1073,  1074,  1075,  1076,
    1077,  1078,  1079,  1261,  1080,  1086,  1087,  1088,  1276,  1089,
    1090,  1091,  1092,  1093,  1094,  1099,  1100,  1101,  1102,  1103,
    1104,  1105,  1106,  1107,  1108,  1287,   306,  1289,  1288,  1109,
    1290,  1110,  1115,  1291,  1292,  1116,  1128,  1312,  1129,   755,
     803,   575,  1130,  1229,  1131,  1294,  1293,  1132,  1133,  1143,
    1283,  1286,  1134,  1262,   495,  1135,  1136,   723,  1285,   761,
    1146,  1309,  1147,  1144,  1148,  1295,  1149,  1177,  1178,  1204,
    1205,  1206,  1207,   727,  1208,  1209,  1210,  1211,  1224,   734,
    1284,  1230,  1225,  1226,  1231,  1232,  1279,  1233,  1234,  1247,
     793,   638,  1263,   656,   811,   399,   453,  1256,  1264,   323,
    1255,  1265,  1266,  1267,  1268,  1269,  1280,  1296,  1297,  1298,
     545,     0,     0,     0,     0,     0,     0,     0,   564,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   660,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     666,     0,     0,     0,     0,     0,   590
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,     1,   312,   313,   314,     1,
     316,   317,     1,     1,     1,     8,   234,     1,     1,     1,
       1,   111,     1,    55,     1,     1,     1,     1,   232,   232,
       1,     1,   236,   236,  1081,  1082,  1083,   234,    11,    12,
      13,     1,     1,   234,    31,     1,     1,     6,     7,     1,
       9,    10,    39,   232,   232,    14,     1,   236,   236,    35,
      43,    43,   234,     1,     1,    24,    25,    26,     1,   234,
      46,    47,    48,     1,    33,    51,    52,    36,    37,    38,
      56,    57,    58,    67,   232,   233,    45,   234,    59,    59,
      67,    83,    67,   174,   175,   127,    67,    67,    69,    69,
      83,    83,   408,    62,   410,   411,   103,   103,   414,   232,
     200,    67,   100,   236,    73,   421,   103,    76,    77,   234,
     426,     1,   103,    83,   103,    84,   100,   234,     1,   435,
     436,    90,    20,    92,   122,    94,     1,    96,   111,    98,
      99,   447,   448,   449,   128,   128,   128,   128,   122,    29,
     109,    31,   234,   128,   125,   125,   115,   116,   103,   118,
     119,   120,   234,    51,   123,   103,   103,   163,   234,   234,
     103,   234,   170,   128,   234,   103,   128,   234,   170,   232,
      60,   170,     1,   236,     3,   181,     5,   234,   234,   148,
      70,   128,   151,   152,   153,   154,   155,   156,   157,   195,
      19,     1,     1,   196,   232,   232,   232,   232,   236,   236,
     170,    91,   232,   234,     1,    95,   236,     1,   234,   234,
     234,     1,    41,   103,   221,   223,   106,   107,    27,    28,
     103,   537,    19,   234,   223,    34,   233,   233,   103,    19,
      59,    40,    61,   170,   233,   233,   233,    31,   207,   208,
      69,   233,   233,   191,    41,    39,   136,   233,   233,   218,
     219,    41,    81,   233,    63,    64,    65,    66,   227,   224,
     229,   235,   224,   233,   233,     1,   221,   233,   233,    78,
      79,    80,    69,   221,   103,   235,    85,    86,    87,    69,
      89,    17,    18,   221,   235,   233,   224,    23,   186,   235,
     233,   235,   232,   103,   235,   233,   125,   232,   196,   232,
     232,   236,    15,   236,   235,   235,   103,   235,   624,   103,
     235,   627,   235,   629,   235,   144,   191,   235,   634,   235,
     210,   235,   212,   213,   121,   215,   216,   217,   235,    42,
     159,   121,   235,    69,   235,   235,   652,   126,   221,   129,
     130,   224,   235,   233,   235,   111,   221,   235,   235,   235,
       1,    87,    88,   163,   235,   235,     1,    93,    72,   149,
      74,    97,    75,   235,   235,   235,   235,   103,    19,   235,
     235,   181,   235,   235,   235,   235,   112,   113,   114,   235,
     209,     1,   211,   212,    29,   195,    31,   235,   124,   235,
      41,   104,   105,   235,   235,   235,   235,   110,   235,    19,
     197,   235,   235,   117,   233,   235,   126,   235,   235,   145,
     235,   235,   235,   235,   211,    60,   235,   214,    69,   235,
     134,    41,   135,   235,   233,    70,   126,   224,   235,   235,
     235,   228,     1,   235,   224,   235,   233,     6,     7,   235,
       9,    10,   235,   233,   235,    14,    91,   183,   235,    69,
      95,   235,   166,   167,   235,    24,    25,    26,   103,   235,
     235,   106,   107,   235,    33,   235,   235,    36,    37,    38,
     121,   235,   235,   235,   235,   235,    45,   235,   129,   130,
     235,   235,   235,   103,   816,   817,   818,   819,   820,   821,
     822,   136,   205,    62,     4,   235,   235,   233,   149,   111,
     235,   121,   235,   235,    73,   235,   235,    76,    77,   235,
     224,    21,    22,   235,   235,    84,   230,   232,   231,   206,
     206,    90,    32,    92,   111,    94,   111,    96,   111,    98,
      99,   111,   111,   111,   232,     1,   232,     3,   235,     5,
     109,   235,   235,   235,   235,   235,   115,   116,   232,   118,
     119,   120,   235,    19,   123,     1,   235,   235,   235,   235,
     235,    71,    72,   235,    74,   210,   235,   212,   213,   235,
     215,   216,   217,   224,   235,    41,   235,   197,   235,   148,
     235,  1226,   151,   152,   153,   154,   155,   156,   157,    35,
     100,   211,   235,    59,   214,    61,   235,   235,   108,   235,
      46,    47,    48,    69,   224,    51,    52,   235,   228,   235,
      56,    57,    58,   235,     1,    81,   111,   235,   235,   235,
     235,   131,   126,   133,   134,   232,   235,   235,   111,   206,
      17,    18,   206,   111,   206,   111,    23,   103,   207,   208,
     150,   111,   137,   138,   139,   140,   141,   142,   143,   218,
     219,   111,   206,   206,   111,   111,   111,   167,   227,   125,
     229,   111,   172,   111,   111,   206,   176,   111,     0,     1,
     180,   111,     4,   235,   235,   185,    44,   206,   144,   189,
     206,   206,    69,    51,    16,    53,    54,    19,   206,   199,
      22,   201,   202,   159,   204,   206,   111,   206,    30,   206,
      87,    88,   111,   206,   206,   206,    93,   206,   232,   232,
      97,    43,   222,   235,   235,   235,   103,    49,    50,   235,
     230,   235,    44,   235,   232,   112,   113,   114,   126,    51,
     235,    53,    54,   126,   232,   235,    68,   124,   235,   235,
      72,   235,   235,   209,   232,   211,   212,   232,   235,   235,
      82,   235,   206,   235,   235,   235,   235,   206,   145,   126,
     235,    44,   235,   235,   232,   206,   235,   126,    51,   101,
     102,   235,   235,   206,   206,   206,   111,   126,   206,   232,
     126,   111,   111,   126,   126,   117,   126,   126,   126,   126,
     126,   234,   160,   161,   162,   126,   183,   165,   166,   126,
     168,   169,   134,   171,   206,   173,   126,   232,   176,   232,
     178,   179,   232,   235,   146,   147,   184,   235,   232,   235,
     188,   126,   235,   235,   192,   193,   194,   232,   232,    74,
     198,   232,   164,   111,    74,   203,   235,   232,   160,   161,
     162,   235,   232,   165,   166,   177,   168,   169,   232,   171,
     182,   173,   232,   232,   176,   187,   178,   179,   190,   232,
     232,   232,   184,   232,   111,   235,   188,   232,   232,   232,
     192,   193,   194,   111,   232,   232,   198,   160,   161,   162,
     232,   203,   165,   166,   232,   168,   169,   232,   171,   134,
     173,   111,   126,   176,   134,   178,   179,   111,   111,   111,
     111,   184,   126,   126,   232,   188,   206,   126,   126,   192,
     193,   194,   235,   158,   111,   198,     1,   126,   158,   126,
     203,   126,   167,   126,   126,   126,   232,   167,   126,   232,
     126,   176,   126,   232,   126,   232,   176,   232,   232,   232,
     232,   232,    27,    28,   232,   232,   232,   232,   232,    34,
     232,   232,   232,   232,   199,    40,   201,   202,   232,   199,
     232,   201,   202,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   222,    63,    64,
      65,    66,   222,   232,   232,   230,   232,   126,   232,   232,
     230,   232,   126,    78,    79,    80,   232,   232,   206,   232,
      85,    86,    87,   232,    89,   232,   232,   232,   111,   126,
     126,   126,   126,   235,   126,   232,   232,   126,   126,   111,
     235,   126,   232,   206,   126,   126,   232,   126,   232,   126,
     126,   206,   232,   126,   499,   126,   235,   126,   126,   232,
     235,   232,   126,   232,   232,   232,   232,   232,   232,   126,
     232,   232,   232,   232,   232,   232,   232,   126,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     126,   232,   232,   235,   126,   126,   232,   232,   126,   126,
     232,   235,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   111,   232,   232,   232,   232,   126,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   132,    77,   132,   134,   232,
     134,   232,   232,   132,   132,   232,   232,  1311,   232,   514,
     582,   289,   232,  1043,   232,  1273,  1271,   232,   232,   220,
    1249,  1260,   232,  1144,   223,   232,   232,   463,  1258,   530,
     232,  1282,   232,   236,   232,  1275,   232,   232,   232,   232,
     232,   232,   232,   476,   232,   232,   232,   232,   232,   486,
    1254,   232,   235,   235,   232,   232,   235,   232,   232,   232,
     568,   340,   232,   373,   595,   120,   170,  1114,   237,    98,
    1112,   237,   237,   237,   237,   237,   232,   232,   232,   232,
     240,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   268,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     403,    -1,    -1,    -1,    -1,    -1,   297
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    16,    19,    22,    30,    43,
      49,    50,    68,    72,    82,   101,   102,   117,   134,   146,
     147,   164,   177,   182,   187,   190,   240,   245,   250,   269,
     275,   281,   289,   303,   323,   345,   359,   374,   381,   385,
     395,   404,   426,   432,   438,   442,   448,   502,   520,   232,
     233,   234,   234,   324,   405,   433,   234,   443,   234,   360,
     427,   346,   234,   276,   304,   375,   234,   234,   396,   234,
     282,   234,   386,     1,    31,    39,   103,   270,   271,   272,
     273,   274,     1,    27,    28,    34,    40,    63,    64,    65,
      66,    78,    79,    80,    85,    86,    87,    89,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   234,   234,   234,     1,    67,
     439,   440,   441,   234,     1,     6,     7,     9,    10,    14,
      24,    25,    26,    33,    36,    37,    38,    45,    62,    73,
      76,    77,    84,    90,    92,    94,    96,    98,    99,   109,
     115,   116,   118,   119,   120,   123,   148,   151,   152,   153,
     154,   155,   156,   157,   207,   208,   218,   219,   227,   229,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   494,   498,   499,   500,   501,   234,   234,   234,
       1,   100,   122,   246,   247,   248,   249,   234,   234,   234,
       1,    35,    46,    47,    48,    51,    52,    56,    57,    58,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,     1,    29,    31,    60,    70,    91,    95,   103,   106,
     107,   136,   210,   212,   213,   215,   216,   217,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   234,     1,   223,   290,
     291,   292,   293,   294,   234,     1,   103,   382,   383,   384,
     234,   232,   235,   235,   235,   233,   271,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   504,     1,    17,    18,    23,    69,    87,
      88,    93,    97,   103,   112,   113,   114,   124,   145,   183,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,     1,     3,     5,
      19,    41,    59,    61,    69,    81,   103,   125,   144,   159,
     209,   211,   212,   406,   407,   408,   409,   410,   411,   412,
     413,   414,   415,   416,   417,   421,   422,   423,   424,   425,
       1,    67,   128,   434,   435,   436,   437,   235,   233,   440,
       1,   103,   128,   444,   445,   446,   447,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   495,   491,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   233,   450,     1,    19,    41,    69,   121,   129,
     130,   149,   224,   361,   362,   363,   364,   365,   366,   367,
     371,   372,   373,     1,   128,   224,   428,   429,   430,   431,
       1,    59,    67,    69,   125,   347,   351,   352,   353,   357,
     358,   232,   235,   235,   233,   247,     1,    83,   170,   277,
     278,   279,   280,     1,    19,    41,    69,   103,   121,   197,
     211,   214,   224,   228,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   319,     1,    43,    83,   128,
     376,   377,   378,   379,   380,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   233,   522,   232,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   252,     1,   103,   221,   397,   398,
     399,   400,   232,   235,   233,   291,   170,     1,   103,   163,
     181,   195,   283,   284,   285,   286,   287,   288,   235,   233,
     383,     1,   103,   221,   224,   387,   388,   389,   390,   391,
     126,   126,   126,   232,   111,   111,   242,   206,   206,   111,
     242,   242,   242,   111,   242,   242,   111,   111,   111,   111,
     232,   232,   235,   235,   235,   342,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   233,   326,   232,
     235,   235,   235,   235,   235,   235,   418,   235,   235,   235,
     235,   235,   235,   235,   235,   233,   407,   235,   235,   233,
     435,   126,   232,   235,   235,   233,   445,   206,   242,   111,
     242,   242,   206,   111,   242,   206,   111,   111,   111,   206,
     206,   242,   111,   111,   111,   111,   242,   111,   111,   111,
     111,   206,   235,   235,   206,   242,   242,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   111,   242,   242,   242,
     206,   111,   232,   232,   235,   235,   368,   235,   235,   235,
     235,   235,   233,   362,   235,   235,   233,   429,   232,   235,
     235,   348,   235,   233,   352,   126,   126,   232,   232,   235,
     235,   233,   278,   232,   235,   235,   320,   235,   235,   316,
     235,   235,   235,   235,   233,   306,   232,   235,   235,   235,
     233,   377,   206,   206,   242,   126,   206,   126,   206,   206,
     206,   232,   111,   126,   206,   126,   111,   111,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   232,   232,
     235,   401,   233,   398,   206,   232,   234,   232,   235,   235,
     235,   235,   233,   284,   126,   232,   232,   235,   392,   235,
     233,   388,   232,   232,   232,   232,   137,   138,   139,   140,
     141,   142,   143,   241,   242,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   111,
     111,   242,   235,   111,   242,   111,   242,   126,   111,   111,
     111,   242,   111,   244,   244,   232,   126,   174,   175,   126,
     206,   126,   126,   235,   126,   126,   111,   126,   126,   242,
     126,   126,   232,   126,   126,   232,   232,   126,   126,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,    44,    51,   160,   161,   162,
     165,   166,   168,   169,   171,   173,   176,   178,   179,   184,
     188,   192,   193,   194,   198,   203,   496,   497,    44,    51,
      53,    54,   160,   161,   162,   165,   166,   168,   169,   171,
     173,   176,   178,   179,   184,   188,   192,   193,   194,   198,
     203,   492,   493,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   126,   206,   235,   126,   111,   126,   126,   126,   232,
     126,   126,   232,   126,   126,   235,   111,   355,   356,   232,
     232,   232,   126,   126,   232,   126,   206,   235,   126,   126,
     235,   126,   206,   126,   126,   232,   126,   126,   126,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   126,   235,   232,   232,     1,
     103,   191,   221,   295,   296,   297,   298,   299,   126,   126,
     126,   126,   232,   232,   126,   235,   126,   232,   241,   241,
     241,   241,   241,   241,   241,   232,   232,   232,    55,   127,
     343,   344,   232,   232,   232,   232,   232,   232,   232,   232,
     232,    11,    12,    13,   243,   244,   232,   232,   232,   232,
     232,   232,   232,   232,   232,     8,   196,   419,   420,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   236,   232,   236,   232,   232,    15,    42,    75,
     104,   105,   110,   135,   205,   231,   369,   370,   232,   232,
     232,   232,   232,   232,   232,   232,   232,    20,    51,   186,
     196,   349,   350,   220,   236,   354,   232,   232,   232,   232,
       4,    21,    22,    32,    71,    72,    74,   100,   108,   131,
     133,   134,   150,   167,   172,   176,   180,   185,   189,   199,
     201,   202,   204,   222,   230,   321,   322,   232,   232,    44,
      51,    53,    54,   160,   161,   162,   165,   166,   168,   169,
     171,   173,   176,   178,   179,   184,   188,   192,   193,   194,
     198,   203,   317,   318,   232,   232,   232,   232,   232,   232,
     232,   232,    74,   134,   158,   167,   176,   199,   201,   202,
     222,   230,   402,   403,   232,   235,   235,   300,   233,   296,
     232,   232,   232,   232,   232,    74,   134,   158,   167,   176,
     199,   201,   202,   222,   230,   393,   394,   232,   232,   236,
     243,   243,   243,   232,   236,   497,   493,   232,   236,   232,
     236,   111,   356,   232,   237,   237,   237,   237,   237,   237,
     232,   236,   232,   236,   232,   236,   126,   200,   244,   235,
     232,   232,   236,   344,   420,   370,   350,   132,   134,   132,
     134,   132,   132,   322,   318,   403,   232,   232,   232,    72,
      74,   117,   134,   166,   167,   224,   230,   301,   302,   394,
     232,   236,   302
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
     350,   350,   350,   351,   351,   352,   352,   352,   352,   352,
     354,   353,   355,   355,   356,   356,   357,   358,   360,   359,
     361,   361,   362,   362,   362,   362,   362,   362,   362,   362,
     362,   363,   364,   365,   366,   368,   367,   369,   369,   370,
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
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   491,   490,   492,   492,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   493,   493,
     493,   493,   493,   495,   494,   496,   496,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   497,   497,
     497,   497,   497,   497,   497,   497,   497,   497,   498,   499,
     500,   501,   502,   503,   503,   504,   504,   504,   504,   504,
     504,   504,   504,   504,   504,   504,   504,   504,   504,   504,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   521,   522,
     522,   522,   522,   522,   522,   522,   522,   522,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531
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
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
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
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
#line 2853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 427 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 433 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2949 "conf_parser.c" /* yacc.c:1652  */
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
#line 2961 "conf_parser.c" /* yacc.c:1652  */
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
#line 2973 "conf_parser.c" /* yacc.c:1652  */
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
#line 2985 "conf_parser.c" /* yacc.c:1652  */
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
#line 2997 "conf_parser.c" /* yacc.c:1652  */
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
#line 3009 "conf_parser.c" /* yacc.c:1652  */
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
#line 3021 "conf_parser.c" /* yacc.c:1652  */
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
#line 3033 "conf_parser.c" /* yacc.c:1652  */
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
#line 3051 "conf_parser.c" /* yacc.c:1652  */
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
#line 3069 "conf_parser.c" /* yacc.c:1652  */
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
#line 3082 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 82:
#line 568 "conf_parser.y" /* yacc.c:1652  */
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
#line 3099 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 582 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3111 "conf_parser.c" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "default_max_clients too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);

    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3137 "conf_parser.c" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_nick_length = NICKLEN;
  }
  else
    ConfigServerInfo.max_nick_length = (yyvsp[-1].number);
}
#line 3163 "conf_parser.c" /* yacc.c:1652  */
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
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);

    ConfigServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ConfigServerInfo.max_topic_length = (yyvsp[-1].number);
}
#line 3189 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 660 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3198 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 678 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3210 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 687 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3222 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 696 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3234 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 709 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3243 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 713 "conf_parser.y" /* yacc.c:1652  */
    {
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3260 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 730 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3269 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 736 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3278 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 746 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3287 "conf_parser.c" /* yacc.c:1652  */
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
#line 3305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 768 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3314 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 774 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 780 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3332 "conf_parser.c" /* yacc.c:1652  */
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
#line 3353 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 814 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3362 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3371 "conf_parser.c" /* yacc.c:1652  */
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
#line 3384 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 840 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 848 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3403 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 851 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3411 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 856 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3420 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3429 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3438 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3447 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3456 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 879 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3465 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 883 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3474 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 887 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3483 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3492 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3504 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 908 "conf_parser.y" /* yacc.c:1652  */
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
#line 3563 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 977 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3572 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 983 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3581 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 989 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3590 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 995 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3599 "conf_parser.c" /* yacc.c:1652  */
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
#line 3613 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1012 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3622 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1018 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 3636 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1029 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3645 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1035 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3654 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1042 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3663 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3672 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3681 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1054 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3690 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3699 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3708 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1066 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3717 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1070 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3726 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1074 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3735 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1078 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3744 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3753 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1086 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3762 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3771 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3780 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3789 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3798 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3807 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3816 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3825 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3834 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3843 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1126 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3852 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1130 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3861 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1136 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3870 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1147 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3888 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3897 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3906 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1159 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1163 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3924 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1167 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3942 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3951 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3960 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1183 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3969 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1187 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3978 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1191 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3987 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1195 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3996 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1199 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4005 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1203 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4014 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1207 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4023 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4032 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1215 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4041 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4050 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4059 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1227 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4068 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1231 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4077 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4086 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1239 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4095 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1243 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4104 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1247 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4113 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1251 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4122 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1255 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4131 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 1265 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4147 "conf_parser.c" /* yacc.c:1652  */
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
#line 4195 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1339 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4204 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1345 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4213 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1351 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4222 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1357 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4231 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1363 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4240 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1369 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4249 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1375 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4258 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1381 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4267 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1387 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4277 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1394 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4286 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1400 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4295 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1406 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4304 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1412 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1421 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4328 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1430 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4337 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1437 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4346 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1441 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4355 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1451 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4364 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1457 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4372 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1463 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4381 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1467 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4390 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1471 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4399 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 282:
#line 1475 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4408 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 290:
#line 1483 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4414 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1488 "conf_parser.y" /* yacc.c:1652  */
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
#line 4432 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1501 "conf_parser.y" /* yacc.c:1652  */
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
#line 4452 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1518 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4461 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1524 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4470 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1534 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4479 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 299:
#line 1538 "conf_parser.y" /* yacc.c:1652  */
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
#line 4525 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1592 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4534 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1598 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4543 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
#line 1604 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4552 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1610 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4566 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 315:
#line 1621 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1628 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4584 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1632 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4593 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1636 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4602 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1640 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4611 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1644 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4620 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1648 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4629 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1652 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4638 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1656 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4647 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1660 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4656 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1666 "conf_parser.y" /* yacc.c:1652  */
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
#line 4673 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1680 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4685 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1689 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4697 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1702 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4709 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 332:
#line 1709 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4720 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1720 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4729 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1726 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4738 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 341:
#line 1732 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1747 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4762 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1763 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4778 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 349:
#line 1774 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4793 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1789 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4802 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1795 "conf_parser.y" /* yacc.c:1652  */
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
#line 4824 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 358:
#line 1814 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4833 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1821 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4842 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1825 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4851 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1829 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4860 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1833 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4869 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1837 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4878 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1841 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4887 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1845 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4896 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1849 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4905 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1853 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4914 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1857 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4923 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4937 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 373:
#line 1876 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4950 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1889 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4959 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 380:
#line 1895 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4968 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4977 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1906 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4986 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1910 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4995 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1914 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5004 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1918 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5013 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1922 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5022 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1926 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5031 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1930 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5040 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1934 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5049 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1938 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5058 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
#line 1948 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5073 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 395:
#line 1958 "conf_parser.y" /* yacc.c:1652  */
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
#line 5144 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2044 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5153 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5162 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2056 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5171 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5180 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2068 "conf_parser.y" /* yacc.c:1652  */
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
#line 5196 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2081 "conf_parser.y" /* yacc.c:1652  */
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
#line 5212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5221 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2100 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5230 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5248 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2116 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5256 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5265 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2126 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5274 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2132 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5288 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5297 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2149 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5306 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5315 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2161 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5329 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2176 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5338 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 436:
#line 2180 "conf_parser.y" /* yacc.c:1652  */
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
#line 5361 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2203 "conf_parser.y" /* yacc.c:1652  */
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
#line 5384 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5393 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2233 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5402 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 445:
#line 2237 "conf_parser.y" /* yacc.c:1652  */
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
#line 5426 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2261 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5435 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 452:
#line 2267 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5444 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2282 "conf_parser.y" /* yacc.c:1652  */
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
#line 5461 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2299 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5470 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 460:
#line 2303 "conf_parser.y" /* yacc.c:1652  */
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
#line 5490 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2323 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5499 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 467:
#line 2329 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5508 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2390 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5516 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2395 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5524 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2400 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5532 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2405 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5540 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2410 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5548 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2415 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5556 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2420 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5564 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2425 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5572 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2430 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5580 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2435 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2440 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5596 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2445 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5604 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2450 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5612 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2455 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5620 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2460 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5628 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2465 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5636 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2470 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5644 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2475 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5652 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2480 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5660 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2485 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5668 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2490 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5676 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2495 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2500 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5692 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2505 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5700 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2510 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5708 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2515 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5716 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2520 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2525 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5732 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2530 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5740 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2535 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5748 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2540 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2545 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5764 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2550 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5772 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2555 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5780 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2560 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5788 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2565 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5796 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2570 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5804 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2575 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5812 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2580 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5820 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2585 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2591 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5836 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2594 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5844 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2597 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5852 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2600 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5860 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2603 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2606 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5876 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2609 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5884 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2612 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5892 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2615 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2618 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5908 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2621 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5916 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2624 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5924 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2627 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5932 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2630 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2633 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2636 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5956 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2639 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5964 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2642 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2645 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5980 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2648 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5988 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2651 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 5996 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2654 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6004 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2657 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6020 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2668 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6028 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2671 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6036 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2674 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2677 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6052 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2680 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6060 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2683 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6068 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2686 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6076 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2689 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2692 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6092 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2695 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6100 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2698 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6108 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2701 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6116 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2704 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6124 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2707 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6132 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2710 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6140 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2713 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6148 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2716 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6156 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2719 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6164 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2722 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6172 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2725 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6180 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2728 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6188 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2733 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6196 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2738 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6204 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2743 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2748 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6220 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2777 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6228 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2782 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2787 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6244 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2792 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6252 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2797 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6260 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2802 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6268 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2807 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6276 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2812 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6284 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2817 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6292 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2822 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6300 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2827 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2832 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2837 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6324 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2842 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 645:
#line 2847 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6340 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2870 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6349 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2876 "conf_parser.y" /* yacc.c:1652  */
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
#line 6368 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2892 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6380 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6389 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6398 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2913 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6407 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6419 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2928 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6428 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 667:
#line 2934 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6437 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6441 "conf_parser.c" /* yacc.c:1652  */
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
