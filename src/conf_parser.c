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
    NETWORK_DESC = 362,
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
    T_TARGET = 451,
    T_TLS = 452,
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
    TIMEOUT = 465,
    TLS_CERTIFICATE_FILE = 466,
    TLS_CERTIFICATE_FINGERPRINT = 467,
    TLS_CIPHER_LIST = 468,
    TLS_CIPHER_SUITES = 469,
    TLS_CONNECTION_REQUIRED = 470,
    TLS_DH_PARAM_FILE = 471,
    TLS_MESSAGE_DIGEST_ALGORITHM = 472,
    TLS_SUPPORTED_GROUPS = 473,
    TS_MAX_DELTA = 474,
    TS_WARN_DELTA = 475,
    TWODOTS = 476,
    TYPE = 477,
    UNKLINE = 478,
    USE_LOGGING = 479,
    USER = 480,
    VHOST = 481,
    VHOST6 = 482,
    WARN_NO_CONNECT_BLOCK = 483,
    WHOIS = 484,
    WHOWAS_HISTORY_LENGTH = 485,
    XLINE = 486,
    XLINE_EXEMPT = 487
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
#define NETWORK_DESC 362
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
#define T_TARGET 451
#define T_TLS 452
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
#define TIMEOUT 465
#define TLS_CERTIFICATE_FILE 466
#define TLS_CERTIFICATE_FINGERPRINT 467
#define TLS_CIPHER_LIST 468
#define TLS_CIPHER_SUITES 469
#define TLS_CONNECTION_REQUIRED 470
#define TLS_DH_PARAM_FILE 471
#define TLS_MESSAGE_DIGEST_ALGORITHM 472
#define TLS_SUPPORTED_GROUPS 473
#define TS_MAX_DELTA 474
#define TS_WARN_DELTA 475
#define TWODOTS 476
#define TYPE 477
#define UNKLINE 478
#define USE_LOGGING 479
#define USER 480
#define VHOST 481
#define VHOST6 482
#define WARN_NO_CONNECT_BLOCK 483
#define WHOIS 484
#define WHOWAS_HISTORY_LENGTH 485
#define XLINE 486
#define XLINE_EXEMPT 487

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 133 "conf_parser.y" /* yacc.c:352  */

  int number;
  char *string;

#line 687 "conf_parser.c" /* yacc.c:352  */
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
#define YYLAST   1262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  668
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1314

#define YYUNDEFTOK  2
#define YYMAXUTOK   487

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
       2,     2,     2,     2,   237,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   238,   233,
       2,   236,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   235,     2,   234,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   369,   369,   370,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   400,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   411,   411,
     412,   413,   414,   415,   422,   424,   424,   425,   425,   425,
     427,   433,   443,   445,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   465,   474,   483,   492,   501,   510,   519,   528,
     543,   558,   568,   582,   591,   614,   637,   660,   670,   672,
     672,   673,   674,   675,   676,   678,   687,   696,   710,   709,
     727,   727,   728,   728,   728,   730,   736,   747,   746,   765,
     765,   766,   766,   766,   766,   766,   768,   774,   780,   786,
     808,   809,   809,   811,   811,   812,   814,   821,   821,   834,
     835,   837,   837,   838,   838,   840,   848,   851,   857,   856,
     862,   862,   863,   867,   871,   875,   879,   883,   887,   891,
     902,   901,   964,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   977,   983,   989,   995,  1001,
    1012,  1018,  1029,  1036,  1035,  1041,  1041,  1042,  1046,  1050,
    1054,  1058,  1062,  1066,  1070,  1074,  1078,  1082,  1086,  1090,
    1094,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,
    1137,  1136,  1142,  1142,  1143,  1147,  1151,  1155,  1159,  1163,
    1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,  1199,  1203,
    1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,  1243,
    1247,  1251,  1255,  1266,  1265,  1321,  1321,  1322,  1323,  1324,
    1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,
    1335,  1336,  1337,  1339,  1345,  1351,  1357,  1363,  1369,  1375,
    1381,  1387,  1394,  1400,  1406,  1412,  1421,  1431,  1430,  1436,
    1436,  1437,  1441,  1452,  1451,  1458,  1457,  1462,  1462,  1463,
    1467,  1471,  1475,  1479,  1485,  1485,  1486,  1486,  1486,  1486,
    1486,  1488,  1488,  1490,  1490,  1492,  1505,  1522,  1528,  1539,
    1538,  1585,  1585,  1586,  1587,  1588,  1589,  1590,  1591,  1592,
    1593,  1594,  1596,  1602,  1608,  1614,  1626,  1625,  1631,  1631,
    1632,  1636,  1640,  1644,  1648,  1652,  1656,  1660,  1664,  1670,
    1684,  1693,  1707,  1706,  1721,  1721,  1722,  1722,  1722,  1722,
    1724,  1730,  1736,  1746,  1748,  1748,  1749,  1749,  1751,  1768,
    1767,  1790,  1790,  1791,  1791,  1791,  1791,  1793,  1799,  1819,
    1818,  1824,  1824,  1825,  1829,  1833,  1837,  1841,  1845,  1849,
    1853,  1857,  1861,  1872,  1871,  1890,  1890,  1891,  1891,  1891,
    1893,  1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,  1922,
    1926,  1930,  1934,  1938,  1942,  1953,  1952,  2030,  2030,  2031,
    2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,  2040,  2041,
    2042,  2043,  2044,  2045,  2046,  2048,  2054,  2060,  2066,  2072,
    2085,  2098,  2104,  2110,  2114,  2121,  2120,  2125,  2125,  2126,
    2130,  2136,  2147,  2153,  2159,  2165,  2181,  2180,  2204,  2204,
    2205,  2205,  2205,  2207,  2227,  2238,  2237,  2262,  2262,  2263,
    2263,  2263,  2265,  2271,  2281,  2283,  2283,  2284,  2284,  2286,
    2304,  2303,  2324,  2324,  2325,  2325,  2325,  2327,  2333,  2343,
    2345,  2345,  2346,  2347,  2348,  2349,  2350,  2351,  2352,  2353,
    2354,  2355,  2356,  2357,  2358,  2359,  2360,  2361,  2362,  2363,
    2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,  2372,  2373,
    2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,  2382,  2383,
    2384,  2385,  2386,  2387,  2388,  2389,  2390,  2391,  2394,  2399,
    2404,  2409,  2414,  2419,  2424,  2429,  2434,  2439,  2444,  2449,
    2454,  2459,  2464,  2469,  2474,  2479,  2484,  2489,  2494,  2499,
    2504,  2509,  2514,  2519,  2524,  2529,  2534,  2539,  2544,  2549,
    2554,  2559,  2564,  2569,  2574,  2579,  2584,  2590,  2589,  2594,
    2594,  2595,  2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,
    2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,
    2652,  2655,  2658,  2661,  2667,  2666,  2671,  2671,  2672,  2675,
    2678,  2681,  2684,  2687,  2690,  2693,  2696,  2699,  2702,  2705,
    2708,  2711,  2714,  2717,  2720,  2723,  2726,  2729,  2732,  2737,
    2742,  2747,  2752,  2761,  2763,  2763,  2764,  2765,  2766,  2767,
    2768,  2769,  2770,  2771,  2772,  2773,  2774,  2775,  2776,  2777,
    2778,  2779,  2781,  2786,  2791,  2796,  2801,  2806,  2811,  2816,
    2821,  2826,  2831,  2836,  2841,  2846,  2851,  2860,  2862,  2862,
    2863,  2864,  2865,  2866,  2867,  2868,  2869,  2870,  2871,  2872,
    2874,  2880,  2896,  2905,  2911,  2917,  2923,  2932,  2938
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
     485,   486,   487,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -798

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-798)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -798,   653,  -798,  -219,  -218,  -213,  -798,  -798,  -798,  -208,
    -798,  -203,  -798,  -798,  -798,  -198,  -798,  -798,  -798,  -196,
    -163,  -798,  -160,  -798,  -150,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   279,   924,  -134,  -109,  -103,    32,  -101,   356,   -88,
     -80,   -63,    35,   -60,   -57,   -55,   762,   534,   -36,    11,
     -26,    34,   -15,   -12,    63,    66,    73,     2,  -798,  -798,
    -798,  -798,  -798,    74,    76,    90,    94,    96,   104,   105,
     113,   114,   122,   123,   125,   133,   135,   136,     3,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,   592,   569,    97,  -798,   137,
      24,  -798,  -798,   216,  -798,   138,   140,   142,   149,   151,
     152,   153,   156,   160,   161,   162,   163,   164,   167,   168,
     170,   171,   174,   175,   176,   177,   178,   180,   184,   186,
    -798,  -798,   187,   188,   189,   190,   195,   204,   206,   207,
     208,   209,   212,   218,   222,   223,   224,   225,   226,   227,
      40,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,   451,    25,   463,
      30,   229,   232,    22,  -798,  -798,  -798,   118,   305,   231,
    -798,   235,   238,   252,   255,   258,   259,   260,   261,   264,
       4,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,    83,   265,   266,   271,   280,   283,   286,   288,   289,
     292,   296,   301,   302,   303,   304,   307,   308,   120,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,    72,   109,   309,    80,
    -798,  -798,  -798,   220,    47,  -798,   310,    20,  -798,  -798,
      70,  -798,   117,   379,   388,   146,  -798,   239,   429,    58,
     340,   436,   429,   429,   429,   438,   429,   429,   448,   449,
     450,   455,   336,  -798,   338,   341,   342,   343,  -798,   344,
     347,   351,   355,   360,   361,   364,   366,   368,   370,   372,
     183,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,   380,   376,   378,
     382,   385,   387,   391,  -798,   392,   396,   397,   398,   399,
     400,   401,   407,   143,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   408,   409,    42,  -798,  -798,  -798,   489,   413,  -798,
    -798,   411,   414,    79,  -798,  -798,  -798,   442,   429,   512,
     429,   429,   445,   543,   429,   452,   544,   546,   548,   454,
     456,   429,   552,   553,   554,   555,   429,   556,   558,   562,
     565,   471,   443,   446,   476,   429,   429,   478,   480,   481,
     482,   484,   485,   486,   487,   491,   587,   429,   429,   429,
     493,   590,   475,  -798,   477,   473,   479,  -798,   483,   488,
     496,   497,   498,    57,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,   499,   501,   110,  -798,  -798,  -798,
     490,   503,   504,  -798,   505,  -798,    27,  -798,  -798,  -798,
    -798,  -798,   584,   585,   492,  -798,   494,   506,   507,    93,
    -798,  -798,  -798,   511,   510,   513,  -798,   517,   518,  -798,
     521,   522,   523,   526,   203,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,   531,   529,   530,   532,
      44,  -798,  -798,  -798,  -798,   509,   566,   429,   586,   567,
     591,   568,   570,   571,   539,  -798,  -798,   608,   656,   573,
     657,   674,   675,   662,   663,   664,   665,   666,   668,   669,
     670,   677,   678,   574,  -798,   575,   576,  -798,    12,  -798,
    -798,  -798,  -798,   595,   580,  -798,   581,   589,   588,   594,
     596,   597,    59,  -798,  -798,  -798,  -798,  -798,   690,   601,
    -798,   602,   604,  -798,   611,     8,  -798,  -798,  -798,  -798,
     618,   621,   625,  -798,   627,   415,   629,   630,   631,   633,
     634,   635,   639,   640,   641,   646,   650,   655,   658,   660,
    -798,  -798,   711,   713,   429,   623,   774,   429,   778,   429,
     700,   784,   785,   786,   429,   787,   787,   672,  -798,  -798,
     775,    -6,   776,   694,   779,   780,   682,   795,   800,   799,
     802,   803,   429,   805,   808,   680,  -798,   810,   811,   707,
    -798,   708,  -798,   815,   817,   717,  -798,   722,   723,   724,
     727,   728,   729,   730,   731,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   745,   748,   749,   750,
     751,   752,   754,   676,   753,   759,   760,   761,   763,   764,
     765,   766,   768,   769,   773,   782,   783,   788,   789,   790,
     791,   792,  -798,  -798,   819,   806,   771,   860,   883,   882,
     890,   891,   793,  -798,   892,   893,   794,  -798,  -798,   901,
     902,   796,   918,   798,  -798,   801,   804,  -798,  -798,   906,
     908,   807,  -798,  -798,   909,   831,   809,   912,   914,   812,
     915,   836,   917,   919,   814,  -798,  -798,   922,   923,   925,
     818,  -798,   820,   821,   822,   823,   824,   825,   826,   827,
     828,  -798,   829,   830,   832,   833,   834,   835,   837,   838,
     839,   840,   841,   842,   843,   844,   845,   846,  -798,  -798,
     937,   847,   848,  -798,   849,  -798,   213,  -798,   942,   953,
     957,   958,   853,  -798,   854,  -798,  -798,   961,   855,   962,
     857,  -798,  -798,  -798,  -798,  -798,   429,   429,   429,   429,
     429,   429,   429,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,   859,
     861,   862,   -32,   863,   864,   865,   866,   867,   868,   869,
     870,   871,   155,   872,   873,  -798,   874,   875,   876,   877,
     878,   879,   880,    21,   881,   884,   885,   886,   887,   888,
     889,   894,  -798,   895,   896,  -798,  -798,   897,   898,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -217,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -178,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   899,   900,   393,   903,   904,   905,   907,   910,  -798,
     911,   913,  -798,   916,   920,   270,   921,   856,  -798,  -798,
    -798,  -798,   926,   927,  -798,   928,   929,   417,   930,   931,
     715,   932,   933,   934,   935,  -798,   936,   938,   939,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,   940,   626,  -798,  -798,   941,
     943,   944,  -798,    18,  -798,  -798,  -798,  -798,   945,   948,
     949,   950,  -798,  -798,   951,   777,   952,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -124,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   787,   787,   787,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,   -47,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   754,  -798,   676,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,   -18,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,    29,  -798,  1003,   918,   954,  -798,  -798,  -798,
    -798,  -798,  -798,   955,  -798,   956,   959,  -798,  -798,   960,
     963,  -798,  -798,   964,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,    46,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,    68,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,   106,  -798,  -798,   989,   -94,   967,   966,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,   115,  -798,  -798,  -798,
     -32,  -798,  -798,  -798,  -798,    21,  -798,  -798,  -798,   393,
    -798,   270,  -798,  -798,  -798,   990,   991,   992,   999,  1002,
    1006,  -798,   417,  -798,   715,  -798,   626,   971,   972,   973,
     311,  -798,  -798,   777,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,   131,  -798,
    -798,  -798,   311,  -798
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   233,   395,   445,     0,
     460,     0,   299,   436,   273,     0,    98,   150,   332,     0,
       0,   373,     0,   107,     0,   349,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   631,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
     630,   629,   618,   619,   620,   621,   622,   623,   624,   625,
     626,   616,   617,   627,   628,     0,     0,     0,   458,     0,
       0,   456,   457,     0,   517,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     584,   557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   473,   515,   479,   516,   510,   511,   512,
     513,   483,   474,   475,   476,   477,   478,   480,   481,   482,
     484,   485,   514,   489,   490,   491,   492,   488,   487,   493,
     500,   501,   494,   495,   496,   486,   498,   508,   509,   506,
     507,   499,   497,   504,   505,   502,   503,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   649,   650,   651,   652,   653,   654,   655,   657,   656,
     658,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   347,     0,     0,   345,   346,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   614,     0,     0,     0,     0,   267,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,   240,   242,   243,   244,   245,   246,   247,
     248,   238,   239,   241,   249,   250,   251,     0,     0,     0,
       0,     0,     0,     0,   425,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   398,   399,   400,   401,   402,   403,
     404,   405,   407,   406,   409,   413,   410,   411,   412,   408,
     451,     0,     0,     0,   448,   449,   450,     0,     0,   455,
     466,     0,     0,     0,   463,   464,   465,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   470,     0,     0,     0,   316,     0,     0,
       0,     0,     0,     0,   302,   303,   304,   305,   310,   306,
     307,   308,   309,   442,     0,     0,     0,   439,   440,   441,
       0,     0,     0,   275,     0,   287,     0,   285,   286,   288,
     289,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   200,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   335,   336,   337,   338,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   648,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   381,     0,   376,
     377,   378,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     344,     0,     0,   359,     0,     0,   352,   353,   354,   355,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     613,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   414,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   397,     0,     0,     0,
     447,     0,   454,     0,     0,     0,   462,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   469,   311,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,     0,   438,   290,     0,
       0,     0,     0,     0,   284,     0,     0,    44,   104,     0,
       0,     0,   100,   164,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   152,   339,     0,     0,     0,
       0,   334,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   647,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,   379,
       0,     0,     0,   375,     0,   120,     0,   115,     0,     0,
       0,     0,     0,   109,     0,   343,   356,     0,     0,     0,
       0,   351,    97,    96,    95,   645,    28,    28,    28,    28,
      28,    28,    28,    30,    29,   646,   633,   632,   634,   635,
     636,   637,   638,   639,   640,   643,   644,   641,   642,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   396,     0,     0,   446,   459,     0,     0,   461,
     529,   533,   518,   519,   546,   522,   611,   612,   554,   523,
     524,   551,   528,   536,   527,   525,   526,   532,   531,   530,
     552,   520,   609,   610,   550,   608,   594,   588,   604,   589,
     590,   591,   599,   607,   592,   601,   605,   595,   606,   596,
     600,   593,   603,   598,   597,   602,     0,   587,   583,   566,
     567,   568,   561,   579,   562,   563,   564,   574,   582,   565,
     576,   580,   570,   581,   571,   575,   569,   578,   573,   572,
     577,     0,   560,   547,   545,   548,   553,   549,   538,   544,
     543,   539,   540,   541,   542,   555,   556,   535,   534,   537,
     521,     0,     0,     0,     0,     0,     0,     0,     0,   300,
       0,     0,   437,     0,     0,     0,   295,   291,   294,   274,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   151,     0,     0,     0,   333,
     663,   660,   661,   662,   667,   666,   668,   664,   665,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   374,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   348,     0,     0,     0,   350,    31,    32,
      33,    34,    35,    36,    37,   262,   263,   257,   272,   271,
       0,   270,   258,   266,   259,   265,   253,   264,   256,   255,
     254,    38,    38,    38,    40,    39,   260,   261,   420,   423,
     424,   434,   431,   416,   432,   429,   430,     0,   428,   433,
     415,   422,   419,   418,   417,   421,   435,   452,   453,   467,
     468,   585,     0,   558,     0,   314,   315,   324,   320,   321,
     323,   328,   325,   326,   327,   322,     0,   319,   313,   331,
     330,   329,   312,   444,   443,   298,   297,   282,   283,   280,
     281,   279,     0,   278,     0,     0,     0,   105,   106,   172,
     169,   220,   232,   207,   216,     0,   205,   210,   226,     0,
     219,   224,   230,   209,   212,   221,   223,   227,   217,   225,
     213,   231,   215,   222,   211,   214,     0,   203,   165,   167,
     199,   182,   183,   184,   177,   195,   178,   179,   180,   190,
     198,   181,   192,   196,   186,   197,   187,   191,   185,   194,
     189,   188,   193,     0,   176,   170,   171,   166,   168,   342,
     340,   341,   380,   385,   391,   394,   387,   393,   388,   392,
     390,   386,   389,     0,   384,   134,     0,     0,     0,     0,
     129,   117,   116,   118,   119,   357,   363,   369,   372,   365,
     371,   366,   370,   368,   364,   367,     0,   362,   358,   268,
       0,    41,    42,    43,   426,     0,   586,   559,   317,     0,
     276,     0,   296,   293,   292,     0,     0,     0,     0,     0,
       0,   201,     0,   174,     0,   382,     0,     0,     0,     0,
       0,   128,   360,     0,   269,   427,   318,   277,   206,   229,
     204,   228,   218,   208,   202,   175,   383,   135,   137,   136,
     148,   147,   143,   145,   149,   146,   142,   144,     0,   141,
     361,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -798,  -798,  -798,  -335,  -306,  -797,  -635,  -798,  -798,   947,
    -798,  -798,  -798,  -798,   946,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  1047,  -798,  -798,  -798,  -798,  -798,  -798,
     642,  -798,  -798,  -798,  -798,  -798,   563,  -798,  -798,  -798,
    -798,  -798,  -798,   858,  -798,  -798,  -798,  -798,   107,  -798,
    -798,  -798,  -798,  -798,  -164,  -798,  -798,  -798,   637,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -122,  -798,  -798,  -798,  -118,  -798,  -798,  -798,   816,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,   -95,  -798,  -798,  -798,
    -798,  -798,  -104,  -798,   689,  -798,  -798,  -798,    13,  -798,
    -798,  -798,  -798,  -798,   714,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   -83,  -798,  -798,  -798,  -798,  -798,  -798,   659,
    -798,  -798,  -798,  -798,  -798,   965,  -798,  -798,  -798,  -798,
     593,  -798,  -798,  -798,  -798,  -798,   -97,  -798,  -798,  -798,
     622,  -798,  -798,  -798,  -798,   -85,  -798,  -798,  -798,   850,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,   -59,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,   716,  -798,  -798,  -798,  -798,  -798,   851,  -798,  -798,
    -798,  -798,  1075,  -798,  -798,  -798,  -798,   797,  -798,  -798,
    -798,  -798,  1037,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,    95,  -798,  -798,  -798,    98,
    -798,  -798,  -798,  -798,  -798,  -798,  1110,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798,   975,  -798,  -798,  -798,  -798,  -798,
    -798,  -798,  -798,  -798
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
    1046,  1047,  1228,  1308,  1309,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   749,  1203,
    1204,   525,   746,  1176,  1177,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1070,  1071,    35,    61,   485,
     731,  1142,  1143,   486,   487,   488,  1146,   987,   988,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     716,  1126,  1127,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   808,  1246,  1247,    40,    68,   568,
     569,   570,   571,   791,  1223,  1224,    41,    54,   373,   374,
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
     853,   854,   606,    73,    82,   230,   610,   611,   612,   591,
     614,   615,   287,   565,    49,    50,  1111,    51,   852,  1039,
    1112,   295,    52,   220,  1068,   118,   473,    56,   480,  1095,
      83,    84,    58,   118,    74,   295,   220,    62,    85,    66,
     231,   124,    75,   390,    86,   526,   125,   126,   577,   127,
     128,   232,   233,   234,   129,  1113,   235,   236,   454,  1114,
     577,   237,   238,   239,   130,   131,   132,    87,    88,    89,
      90,   591,    67,   565,   133,    69,   455,   134,   135,   136,
     400,   287,    91,    92,    93,    71,   137,   481,   527,    94,
      95,    96,   119,    97,   496,   482,  1069,   483,   390,   456,
     119,   115,   668,   138,   670,   671,    76,  1278,   674,  1249,
     391,   473,   592,  1250,   139,   681,   566,   140,   141,   496,
     686,   251,  1040,   221,   296,   142,   116,   457,   528,   695,
     696,   143,   117,   144,   123,   145,   221,   146,   296,   147,
     148,   707,   708,   709,   357,   222,   358,   217,   359,   252,
     149,   578,   253,   484,   474,   218,   150,   151,   222,   152,
     153,   154,   360,   578,   155,   391,  1081,  1082,  1083,   857,
     858,   392,   219,   529,   592,   227,   566,   497,   228,   458,
     229,   254,  -127,   401,   324,   361,  1254,   459,   460,   156,
    1255,   255,   157,   158,   159,   160,   161,   162,   163,   286,
     325,   326,   497,   362,   503,   363,   327,   461,   402,   294,
    1041,   579,   256,   364,  1039,  1258,   257,   400,  1096,  1259,
     300,   301,   504,   579,   258,   365,   392,   259,   260,   580,
     593,   764,   526,   594,   567,   288,   305,   322,   544,   474,
    1042,   580,   810,   581,   600,   505,   792,   366,   164,   165,
     475,  -127,  1229,   328,   589,   581,   494,   261,   398,   166,
     167,   733,  1260,   491,   498,   607,  1261,   852,   168,   367,
     169,   329,   330,   506,   452,   527,   659,   331,   760,  1271,
      73,   332,   462,  1272,  1251,  1252,  1253,   333,   368,   498,
    1137,   722,   593,   802,   567,   594,   334,   335,   336,   302,
    1138,  1273,   303,   369,   288,  1274,   503,   507,   337,   304,
     307,    74,   308,   665,   574,   528,   546,  1040,   841,    75,
     401,   844,  1139,   846,   504,   508,   309,   741,   851,   338,
     310,   262,   311,   263,   264,   475,   265,   266,   267,  1275,
     312,   313,   572,  1276,   726,   402,   869,   505,  1282,   314,
     315,   604,  1283,   370,   563,   371,   372,   124,   316,   317,
     529,   318,   125,   126,  1311,   127,   128,   339,  1312,   319,
     129,   320,   321,   397,   407,   506,   408,   655,   409,   603,
     130,   131,   132,    76,  1300,   410,  1301,   411,   412,   413,
     133,   576,   414,   134,   135,   136,   415,   416,   417,   418,
     419,   509,   137,   420,   421,  1041,   422,   423,  1117,   507,
     424,   425,   426,   427,   428,   510,   429,   637,   511,   138,
     430,  1151,   431,   434,   435,   436,   437,   508,   512,  1302,
     139,   438,   513,   140,   141,  1042,  1118,   754,  1152,  1153,
     439,   142,   440,   441,   442,   443,  1303,   143,   444,   144,
    1154,   145,   454,   146,   445,   147,   148,  1140,   446,   447,
     448,   449,   450,   451,   480,   492,   149,  1141,   493,  1119,
     455,   535,   150,   151,   536,   152,   153,   154,  1304,  1305,
     155,  1058,  1059,  1060,  1061,  1062,  1063,  1064,   537,  1155,
    1156,   538,  1157,   456,   539,   540,   541,   542,  1120,  1121,
     543,   547,   548,   509,  1122,   156,   601,   549,   157,   158,
     159,   160,   161,   162,   163,   602,   550,   510,  1158,   551,
     511,   457,   552,   481,   553,   554,  1159,   605,   555,  1123,
     512,   482,   556,   483,   513,   251,  1306,   557,   558,   559,
     560,   605,  1307,   561,   562,   573,   588,   608,   609,  1160,
     613,  1161,  1162,   816,   817,   818,   819,   820,   821,   822,
     616,   617,   618,   252,   164,   165,   253,   619,  1163,   620,
     357,   621,   358,   458,   359,   166,   167,   622,   623,   624,
     626,   459,   460,   627,   168,  1164,   169,   628,   360,   484,
    1165,   629,  1279,   324,  1166,   254,   630,   631,  1167,  1124,
     632,   461,   633,  1168,   634,   255,   635,  1169,   636,   325,
     326,   361,   640,   639,   641,   327,   661,  1170,   642,  1171,
    1172,   643,  1173,   644,   669,  1125,   256,   645,   647,   362,
     257,   363,   648,   649,   650,   651,   652,   653,   258,   364,
    1174,   259,   260,   654,   657,   658,   662,   663,  1175,   667,
     664,   365,   672,     2,     3,   673,   676,     4,   677,   675,
     678,   679,   328,   680,   682,   683,   684,   685,   687,     5,
     688,   261,     6,   366,   689,     7,   462,   690,   691,   692,
     329,   330,   693,   694,     8,   697,   331,   698,   699,   700,
     332,   701,   702,   703,   704,   367,   333,     9,   705,   706,
     710,  1213,   711,    10,    11,   334,   335,   336,   712,   714,
     713,   735,   736,   765,   368,   715,   762,   337,   767,   717,
     772,   928,    12,   728,   718,   737,    13,   738,   929,   369,
     930,   931,   719,   720,   721,   724,    14,   725,   338,   729,
     730,   732,   739,   740,   743,   262,   744,   263,   264,   745,
     265,   266,   267,   747,   748,    15,    16,   750,   751,   752,
    1180,  1214,   753,   230,   756,   757,   758,  1181,   759,  1182,
    1183,    17,   771,   763,   766,   768,   339,   769,   770,   370,
     774,   371,   372,   773,   775,  1215,   776,   777,    18,   778,
     779,   780,   781,   782,  1216,   783,   784,   785,   231,   905,
      19,    20,   794,  1217,   786,   787,   906,   788,   789,   232,
     233,   234,   790,   795,   235,   236,   796,   804,    21,   237,
     238,   239,   797,   839,   798,   840,  1218,   847,  1219,  1220,
     799,    22,   800,   801,   805,   806,    23,   932,   933,   934,
     807,    24,   935,   936,    25,   937,   938,   809,   939,  1221,
     940,   812,  1236,   941,   813,   942,   943,  1222,   814,   842,
     815,   944,   825,   826,   827,   945,   828,   829,   830,   946,
     947,   948,   831,   832,   833,   949,  1184,  1185,  1186,   834,
     950,  1187,  1188,   835,  1189,  1190,   843,  1191,   836,  1192,
     845,   837,  1193,   838,  1194,  1195,   848,   849,   850,   852,
    1196,   860,   856,   859,  1197,   855,   861,   862,  1198,  1199,
    1200,   866,  1237,   872,  1201,   907,   908,   909,   863,  1202,
     910,   911,   864,   912,   913,    82,   914,   865,   915,   867,
     868,   916,   870,   917,   918,   871,  1238,   873,   874,   919,
     875,   876,   877,   920,   878,  1239,   971,   921,   922,   923,
     879,    83,    84,   924,  1240,   880,   881,   882,   925,    85,
     883,   884,   885,   886,   887,    86,   888,   889,   890,   891,
     892,   893,   894,   895,   896,   897,   898,  1241,   899,  1242,
    1243,   900,   901,   902,   903,   904,   953,   974,    87,    88,
      89,    90,   954,   955,   956,   975,   957,   958,   959,   960,
    1244,   961,   962,    91,    92,    93,   963,   973,  1245,   976,
      94,    95,    96,   972,    97,   964,   965,   977,   978,   980,
     981,   966,   967,   968,   969,   970,   979,   982,   983,   984,
     986,   989,   985,   992,   990,   993,   995,   991,   996,   998,
     994,   999,  1001,  1002,  1003,   997,  1004,  1005,  1000,  1006,
    1007,  1009,  1008,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1020,  1035,  1021,  1022,  1023,  1024,  1048,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1049,  1037,  1038,  1036,  1050,  1051,  1052,  1053,  1054,  1056,
    1057,  1055,  1065,  1145,  1066,  1067,  1072,  1073,  1074,  1075,
    1076,  1077,  1078,  1079,  1080,  1086,  1087,  1088,  1089,  1090,
    1091,  1092,  1093,  1094,  1099,  1262,  1277,  1100,  1101,  1102,
    1103,  1104,  1105,  1288,   306,  1290,  1289,  1106,  1107,  1108,
    1109,  1110,  1115,  1116,  1291,  1292,  1128,  1129,  1130,  1293,
    1131,   742,  1144,  1132,  1133,   803,  1134,   575,  1313,  1135,
    1230,   755,  1295,  1136,  1294,  1284,   638,  1287,  1263,  1147,
    1148,  1149,  1150,  1178,  1179,  1205,  1206,  1207,  1208,  1209,
     495,  1210,  1211,  1212,  1225,   734,  1286,   723,  1231,  1226,
    1227,  1232,  1233,  1234,  1235,  1248,  1310,  1264,   811,   761,
     793,  1296,   727,  1265,  1266,   399,  1285,  1267,  1268,  1281,
     666,  1269,  1270,  1280,  1297,  1298,  1299,   453,   323,  1257,
    1256,     0,     0,     0,   564,   545,     0,     0,     0,     0,
       0,     0,     0,   656,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,     1,     1,   312,   313,   314,     1,
     316,   317,     1,     1,   233,   234,   233,   235,   112,     1,
     237,     1,   235,     1,    56,     1,     1,   235,     1,     8,
      27,    28,   235,     1,    32,     1,     1,   235,    35,   235,
      36,     1,    40,     1,    41,     1,     6,     7,     1,     9,
      10,    47,    48,    49,    14,   233,    52,    53,     1,   237,
       1,    57,    58,    59,    24,    25,    26,    64,    65,    66,
      67,     1,   235,     1,    34,   235,    19,    37,    38,    39,
       1,     1,    79,    80,    81,   235,    46,    60,    44,    86,
      87,    88,    68,    90,     1,    68,   128,    70,     1,    42,
      68,   235,   408,    63,   410,   411,   104,   201,   414,   233,
      68,     1,   104,   237,    74,   421,   104,    77,    78,     1,
     426,     1,   104,   101,   104,    85,   235,    70,    84,   435,
     436,    91,   235,    93,   235,    95,   101,    97,   104,    99,
     100,   447,   448,   449,     1,   123,     3,   235,     5,    29,
     110,   104,    32,   126,   129,   235,   116,   117,   123,   119,
     120,   121,    19,   104,   124,    68,    11,    12,    13,   175,
     176,   129,   235,   129,   104,   235,   104,    84,   235,   122,
     235,    61,   171,   104,     1,    42,   233,   130,   131,   149,
     237,    71,   152,   153,   154,   155,   156,   157,   158,   235,
      17,    18,    84,    60,     1,    62,    23,   150,   129,   235,
     192,   164,    92,    70,     1,   233,    96,     1,   197,   237,
     235,   233,    19,   164,   104,    82,   129,   107,   108,   182,
     222,   537,     1,   225,   222,   224,   234,   234,   234,   129,
     222,   182,   234,   196,   127,    42,   234,   104,   208,   209,
     225,   171,   234,    70,   234,   196,   234,   137,   234,   219,
     220,   234,   233,   233,   171,   207,   237,   112,   228,   126,
     230,    88,    89,    70,   234,    44,   234,    94,   234,   233,
       1,    98,   225,   237,  1081,  1082,  1083,   104,   145,   171,
      20,   234,   222,   234,   222,   225,   113,   114,   115,   236,
      30,   233,   236,   160,   224,   237,     1,   104,   125,   236,
     236,    32,   236,   234,   234,    84,   233,   104,   624,    40,
     104,   627,    52,   629,    19,   122,   236,   234,   634,   146,
     236,   211,   236,   213,   214,   225,   216,   217,   218,   233,
     236,   236,   233,   237,   234,   129,   652,    42,   233,   236,
     236,   112,   237,   210,   234,   212,   213,     1,   236,   236,
     129,   236,     6,     7,   233,     9,    10,   184,   237,   236,
      14,   236,   236,   236,   236,    70,   236,   234,   236,   233,
      24,    25,    26,   104,    73,   236,    75,   236,   236,   236,
      34,   171,   236,    37,    38,    39,   236,   236,   236,   236,
     236,   198,    46,   236,   236,   192,   236,   236,    15,   104,
     236,   236,   236,   236,   236,   212,   236,   234,   215,    63,
     236,     4,   236,   236,   236,   236,   236,   122,   225,   118,
      74,   236,   229,    77,    78,   222,    43,   234,    21,    22,
     236,    85,   236,   236,   236,   236,   135,    91,   236,    93,
      33,    95,     1,    97,   236,    99,   100,   187,   236,   236,
     236,   236,   236,   236,     1,   236,   110,   197,   236,    76,
      19,   236,   116,   117,   236,   119,   120,   121,   167,   168,
     124,   816,   817,   818,   819,   820,   821,   822,   236,    72,
      73,   236,    75,    42,   236,   236,   236,   236,   105,   106,
     236,   236,   236,   198,   111,   149,   127,   236,   152,   153,
     154,   155,   156,   157,   158,   127,   236,   212,   101,   236,
     215,    70,   236,    60,   236,   236,   109,   112,   236,   136,
     225,    68,   236,    70,   229,     1,   225,   236,   236,   236,
     236,   112,   231,   236,   236,   236,   236,   207,   112,   132,
     112,   134,   135,   138,   139,   140,   141,   142,   143,   144,
     112,   112,   112,    29,   208,   209,    32,   112,   151,   233,
       1,   233,     3,   122,     5,   219,   220,   236,   236,   236,
     236,   130,   131,   236,   228,   168,   230,   236,    19,   126,
     173,   236,  1227,     1,   177,    61,   236,   236,   181,   206,
     236,   150,   236,   186,   236,    71,   236,   190,   236,    17,
      18,    42,   236,   233,   236,    23,   127,   200,   236,   202,
     203,   236,   205,   236,   112,   232,    92,   236,   236,    60,
      96,    62,   236,   236,   236,   236,   236,   236,   104,    70,
     223,   107,   108,   236,   236,   236,   233,   236,   231,   207,
     236,    82,   207,     0,     1,   112,   112,     4,   112,   207,
     112,   207,    70,   207,   112,   112,   112,   112,   112,    16,
     112,   137,    19,   104,   112,    22,   225,   112,   207,   236,
      88,    89,   236,   207,    31,   207,    94,   207,   207,   207,
      98,   207,   207,   207,   207,   126,   104,    44,   207,   112,
     207,    75,   112,    50,    51,   113,   114,   115,   233,   236,
     233,   127,   127,   127,   145,   236,   207,   125,   127,   236,
     112,    45,    69,   233,   236,   233,    73,   233,    52,   160,
      54,    55,   236,   236,   236,   236,    83,   236,   146,   236,
     236,   236,   236,   236,   233,   211,   236,   213,   214,   236,
     216,   217,   218,   236,   236,   102,   103,   236,   236,   236,
      45,   135,   236,     1,   233,   236,   236,    52,   236,    54,
      55,   118,   233,   207,   207,   207,   184,   207,   207,   210,
     207,   212,   213,   127,   127,   159,   112,   112,   135,   127,
     127,   127,   127,   127,   168,   127,   127,   127,    36,    45,
     147,   148,   207,   177,   127,   127,    52,   233,   233,    47,
      48,    49,   236,   233,    52,    53,   235,   127,   165,    57,
      58,    59,   233,   112,   236,   112,   200,   127,   202,   203,
     236,   178,   236,   236,   233,   233,   183,   161,   162,   163,
     236,   188,   166,   167,   191,   169,   170,   236,   172,   223,
     174,   233,    75,   177,   233,   179,   180,   231,   233,   236,
     233,   185,   233,   233,   233,   189,   233,   233,   233,   193,
     194,   195,   233,   233,   233,   199,   161,   162,   163,   233,
     204,   166,   167,   233,   169,   170,   112,   172,   233,   174,
     112,   233,   177,   233,   179,   180,   112,   112,   112,   112,
     185,   207,   127,   127,   189,   233,   127,   127,   193,   194,
     195,   112,   135,   233,   199,   161,   162,   163,   236,   204,
     166,   167,   127,   169,   170,     1,   172,   127,   174,   127,
     127,   177,   127,   179,   180,   127,   159,   127,   127,   185,
     233,   233,   127,   189,   127,   168,   127,   193,   194,   195,
     233,    27,    28,   199,   177,   233,   233,   233,   204,    35,
     233,   233,   233,   233,   233,    41,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   200,   233,   202,
     203,   233,   233,   233,   233,   233,   233,   127,    64,    65,
      66,    67,   233,   233,   233,   112,   233,   233,   233,   233,
     223,   233,   233,    79,    80,    81,   233,   236,   231,   127,
      86,    87,    88,   207,    90,   233,   233,   127,   127,   127,
     127,   233,   233,   233,   233,   233,   233,   233,   127,   127,
     112,   233,   236,   127,   233,   127,   127,   233,   207,   127,
     233,   127,   127,   207,   127,   236,   127,   233,   236,   127,
     127,   233,   127,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   127,   233,   233,   233,   233,   127,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     127,   233,   233,   236,   127,   127,   233,   233,   127,   127,
     233,   236,   233,   237,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   112,   127,   233,   233,   233,
     233,   233,   233,   133,    77,   133,   135,   233,   233,   233,
     233,   233,   233,   233,   135,   133,   233,   233,   233,   133,
     233,   499,   221,   233,   233,   582,   233,   289,  1312,   233,
    1043,   514,  1274,   233,  1272,  1250,   340,  1261,  1145,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     223,   233,   233,   233,   233,   486,  1259,   463,   233,   236,
     236,   233,   233,   233,   233,   233,  1283,   233,   595,   530,
     568,  1276,   476,   238,   238,   120,  1255,   238,   238,   233,
     403,   238,   238,   236,   233,   233,   233,   170,    98,  1114,
    1112,    -1,    -1,    -1,   268,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   373,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   297
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   240,     0,     1,     4,    16,    19,    22,    31,    44,
      50,    51,    69,    73,    83,   102,   103,   118,   135,   147,
     148,   165,   178,   183,   188,   191,   241,   246,   251,   270,
     276,   282,   290,   304,   324,   346,   360,   375,   382,   386,
     396,   405,   427,   433,   439,   443,   449,   503,   521,   233,
     234,   235,   235,   325,   406,   434,   235,   444,   235,   361,
     428,   347,   235,   277,   305,   376,   235,   235,   397,   235,
     283,   235,   387,     1,    32,    40,   104,   271,   272,   273,
     274,   275,     1,    27,    28,    35,    41,    64,    65,    66,
      67,    79,    80,    81,    86,    87,    88,    90,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   235,   235,   235,     1,    68,
     440,   441,   442,   235,     1,     6,     7,     9,    10,    14,
      24,    25,    26,    34,    37,    38,    39,    46,    63,    74,
      77,    78,    85,    91,    93,    95,    97,    99,   100,   110,
     116,   117,   119,   120,   121,   124,   149,   152,   153,   154,
     155,   156,   157,   158,   208,   209,   219,   220,   228,   230,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   495,   499,   500,   501,   502,   235,   235,   235,
       1,   101,   123,   247,   248,   249,   250,   235,   235,   235,
       1,    36,    47,    48,    49,    52,    53,    57,    58,    59,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,     1,    29,    32,    61,    71,    92,    96,   104,   107,
     108,   137,   211,   213,   214,   216,   217,   218,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   235,     1,   224,   291,
     292,   293,   294,   295,   235,     1,   104,   383,   384,   385,
     235,   233,   236,   236,   236,   234,   272,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   234,   505,     1,    17,    18,    23,    70,    88,
      89,    94,    98,   104,   113,   114,   115,   125,   146,   184,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,     1,     3,     5,
      19,    42,    60,    62,    70,    82,   104,   126,   145,   160,
     210,   212,   213,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   422,   423,   424,   425,   426,
       1,    68,   129,   435,   436,   437,   438,   236,   234,   441,
       1,   104,   129,   445,   446,   447,   448,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   496,   492,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   234,   451,     1,    19,    42,    70,   122,   130,
     131,   150,   225,   362,   363,   364,   365,   366,   367,   368,
     372,   373,   374,     1,   129,   225,   429,   430,   431,   432,
       1,    60,    68,    70,   126,   348,   352,   353,   354,   358,
     359,   233,   236,   236,   234,   248,     1,    84,   171,   278,
     279,   280,   281,     1,    19,    42,    70,   104,   122,   198,
     212,   215,   225,   229,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   320,     1,    44,    84,   129,
     377,   378,   379,   380,   381,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   234,   523,   233,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   234,   253,     1,   104,   222,   398,   399,
     400,   401,   233,   236,   234,   292,   171,     1,   104,   164,
     182,   196,   284,   285,   286,   287,   288,   289,   236,   234,
     384,     1,   104,   222,   225,   388,   389,   390,   391,   392,
     127,   127,   127,   233,   112,   112,   243,   207,   207,   112,
     243,   243,   243,   112,   243,   243,   112,   112,   112,   112,
     233,   233,   236,   236,   236,   343,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   234,   327,   233,
     236,   236,   236,   236,   236,   236,   419,   236,   236,   236,
     236,   236,   236,   236,   236,   234,   408,   236,   236,   234,
     436,   127,   233,   236,   236,   234,   446,   207,   243,   112,
     243,   243,   207,   112,   243,   207,   112,   112,   112,   207,
     207,   243,   112,   112,   112,   112,   243,   112,   112,   112,
     112,   207,   236,   236,   207,   243,   243,   207,   207,   207,
     207,   207,   207,   207,   207,   207,   112,   243,   243,   243,
     207,   112,   233,   233,   236,   236,   369,   236,   236,   236,
     236,   236,   234,   363,   236,   236,   234,   430,   233,   236,
     236,   349,   236,   234,   353,   127,   127,   233,   233,   236,
     236,   234,   279,   233,   236,   236,   321,   236,   236,   317,
     236,   236,   236,   236,   234,   307,   233,   236,   236,   236,
     234,   378,   207,   207,   243,   127,   207,   127,   207,   207,
     207,   233,   112,   127,   207,   127,   112,   112,   127,   127,
     127,   127,   127,   127,   127,   127,   127,   127,   233,   233,
     236,   402,   234,   399,   207,   233,   235,   233,   236,   236,
     236,   236,   234,   285,   127,   233,   233,   236,   393,   236,
     234,   389,   233,   233,   233,   233,   138,   139,   140,   141,
     142,   143,   144,   242,   243,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   112,
     112,   243,   236,   112,   243,   112,   243,   127,   112,   112,
     112,   243,   112,   245,   245,   233,   127,   175,   176,   127,
     207,   127,   127,   236,   127,   127,   112,   127,   127,   243,
     127,   127,   233,   127,   127,   233,   233,   127,   127,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,    45,    52,   161,   162,   163,
     166,   167,   169,   170,   172,   174,   177,   179,   180,   185,
     189,   193,   194,   195,   199,   204,   497,   498,    45,    52,
      54,    55,   161,   162,   163,   166,   167,   169,   170,   172,
     174,   177,   179,   180,   185,   189,   193,   194,   195,   199,
     204,   493,   494,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   127,   207,   236,   127,   112,   127,   127,   127,   233,
     127,   127,   233,   127,   127,   236,   112,   356,   357,   233,
     233,   233,   127,   127,   233,   127,   207,   236,   127,   127,
     236,   127,   207,   127,   127,   233,   127,   127,   127,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   127,   236,   233,   233,     1,
     104,   192,   222,   296,   297,   298,   299,   300,   127,   127,
     127,   127,   233,   233,   127,   236,   127,   233,   242,   242,
     242,   242,   242,   242,   242,   233,   233,   233,    56,   128,
     344,   345,   233,   233,   233,   233,   233,   233,   233,   233,
     233,    11,    12,    13,   244,   245,   233,   233,   233,   233,
     233,   233,   233,   233,   233,     8,   197,   420,   421,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   237,   233,   237,   233,   233,    15,    43,    76,
     105,   106,   111,   136,   206,   232,   370,   371,   233,   233,
     233,   233,   233,   233,   233,   233,   233,    20,    30,    52,
     187,   197,   350,   351,   221,   237,   355,   233,   233,   233,
     233,     4,    21,    22,    33,    72,    73,    75,   101,   109,
     132,   134,   135,   151,   168,   173,   177,   181,   186,   190,
     200,   202,   203,   205,   223,   231,   322,   323,   233,   233,
      45,    52,    54,    55,   161,   162,   163,   166,   167,   169,
     170,   172,   174,   177,   179,   180,   185,   189,   193,   194,
     195,   199,   204,   318,   319,   233,   233,   233,   233,   233,
     233,   233,   233,    75,   135,   159,   168,   177,   200,   202,
     203,   223,   231,   403,   404,   233,   236,   236,   301,   234,
     297,   233,   233,   233,   233,   233,    75,   135,   159,   168,
     177,   200,   202,   203,   223,   231,   394,   395,   233,   233,
     237,   244,   244,   244,   233,   237,   498,   494,   233,   237,
     233,   237,   112,   357,   233,   238,   238,   238,   238,   238,
     238,   233,   237,   233,   237,   233,   237,   127,   201,   245,
     236,   233,   233,   237,   345,   421,   371,   351,   133,   135,
     133,   135,   133,   133,   323,   319,   404,   233,   233,   233,
      73,    75,   118,   135,   167,   168,   225,   231,   302,   303,
     395,   233,   237,   303
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   239,   240,   240,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   242,   242,
     243,   243,   243,   243,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   246,   247,   247,   248,   248,   248,
     249,   250,   251,   252,   252,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     271,   272,   272,   272,   272,   273,   274,   275,   277,   276,
     278,   278,   279,   279,   279,   280,   281,   283,   282,   284,
     284,   285,   285,   285,   285,   285,   286,   287,   288,   289,
     290,   291,   291,   292,   292,   292,   293,   295,   294,   296,
     296,   297,   297,   297,   297,   298,   299,   299,   301,   300,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     305,   304,   306,   306,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   317,   316,   318,   318,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     321,   320,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   325,   324,   326,   326,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   343,   342,   344,
     344,   345,   345,   347,   346,   349,   348,   350,   350,   351,
     351,   351,   351,   351,   352,   352,   353,   353,   353,   353,
     353,   355,   354,   356,   356,   357,   357,   358,   359,   361,
     360,   362,   362,   363,   363,   363,   363,   363,   363,   363,
     363,   363,   364,   365,   366,   367,   369,   368,   370,   370,
     371,   371,   371,   371,   371,   371,   371,   371,   371,   372,
     373,   374,   376,   375,   377,   377,   378,   378,   378,   378,
     379,   380,   381,   382,   383,   383,   384,   384,   385,   387,
     386,   388,   388,   389,   389,   389,   389,   390,   391,   393,
     392,   394,   394,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   397,   396,   398,   398,   399,   399,   399,
     400,   402,   401,   403,   403,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   406,   405,   407,   407,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   417,   419,   418,   420,   420,   421,
     421,   422,   423,   424,   425,   426,   428,   427,   429,   429,
     430,   430,   430,   431,   432,   434,   433,   435,   435,   436,
     436,   436,   437,   438,   439,   440,   440,   441,   441,   442,
     444,   443,   445,   445,   446,   446,   446,   447,   448,   449,
     450,   450,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   485,   486,   487,   488,   489,   490,   492,   491,   493,
     493,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   496,   495,   497,   497,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   499,
     500,   501,   502,   503,   504,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   522,
     523,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532
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
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     0,     5,     3,     1,     1,     3,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 408 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 415 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 428 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2942 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 434 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2951 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 466 "conf_parser.y" /* yacc.c:1652  */
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
#line 475 "conf_parser.y" /* yacc.c:1652  */
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
#line 484 "conf_parser.y" /* yacc.c:1652  */
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
#line 493 "conf_parser.y" /* yacc.c:1652  */
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
#line 502 "conf_parser.y" /* yacc.c:1652  */
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
#line 511 "conf_parser.y" /* yacc.c:1652  */
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
#line 520 "conf_parser.y" /* yacc.c:1652  */
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
#line 529 "conf_parser.y" /* yacc.c:1652  */
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
#line 544 "conf_parser.y" /* yacc.c:1652  */
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
#line 559 "conf_parser.y" /* yacc.c:1652  */
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
#line 569 "conf_parser.y" /* yacc.c:1652  */
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
#line 583 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3113 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 84:
#line 592 "conf_parser.y" /* yacc.c:1652  */
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
#line 615 "conf_parser.y" /* yacc.c:1652  */
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
#line 638 "conf_parser.y" /* yacc.c:1652  */
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
#line 661 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3200 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 679 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 688 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 697 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 710 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 99:
#line 714 "conf_parser.y" /* yacc.c:1652  */
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
#line 731 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 737 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3280 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 747 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3289 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 108:
#line 751 "conf_parser.y" /* yacc.c:1652  */
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
#line 769 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 775 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3325 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 781 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3334 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 119:
#line 787 "conf_parser.y" /* yacc.c:1652  */
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
#line 815 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3364 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 821 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3373 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 128:
#line 825 "conf_parser.y" /* yacc.c:1652  */
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
#line 841 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3397 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 849 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3405 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 852 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3413 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 857 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 864 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3431 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 868 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3440 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 872 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3449 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 876 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3458 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 880 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3467 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 884 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3476 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 888 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3485 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 892 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3494 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3506 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 151:
#line 909 "conf_parser.y" /* yacc.c:1652  */
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
#line 978 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3574 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 984 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 990 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3592 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 996 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 169:
#line 1002 "conf_parser.y" /* yacc.c:1652  */
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
#line 1013 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1019 "conf_parser.y" /* yacc.c:1652  */
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
#line 1030 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3647 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1036 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3656 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1043 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3665 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1047 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3674 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1051 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3683 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1055 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3692 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1059 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3701 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1063 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3710 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1067 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3719 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1071 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3728 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1075 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3737 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1079 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3746 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1083 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1087 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3764 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1091 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3782 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1099 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3791 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1103 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3800 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1107 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3809 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3818 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1115 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3827 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1119 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3836 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1123 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3845 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3854 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1131 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3863 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1137 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3872 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1144 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3881 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1148 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3890 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1152 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1156 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3908 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1160 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1164 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3926 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1168 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3935 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1172 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3944 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1176 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3953 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1180 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3962 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1184 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3971 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1188 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3980 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1192 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3989 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1196 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3998 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1200 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4007 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1204 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4016 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1208 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4025 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1212 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4034 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1216 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4043 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1220 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4052 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1224 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4061 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1228 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4070 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1232 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4079 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1236 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4088 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1240 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4097 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1244 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4106 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1248 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4115 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1252 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4124 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1256 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4133 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 1266 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4149 "conf_parser.c" /* yacc.c:1652  */
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
#line 4197 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1340 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4206 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1346 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1352 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4224 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1358 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4233 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1364 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4242 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1370 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4251 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1376 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4260 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1382 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4269 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1388 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4279 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1395 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4288 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1401 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4297 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1407 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4306 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1413 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4318 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1422 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4330 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1431 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4339 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1438 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4348 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1442 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4357 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1452 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4366 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1458 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4374 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4383 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1468 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4392 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1472 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 282:
#line 1476 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4410 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 283:
#line 1480 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4419 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 1488 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4425 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1493 "conf_parser.y" /* yacc.c:1652  */
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
#line 4443 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1506 "conf_parser.y" /* yacc.c:1652  */
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
#line 4463 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1523 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4472 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1529 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4481 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 299:
#line 1539 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4490 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 300:
#line 1543 "conf_parser.y" /* yacc.c:1652  */
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
#line 4536 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1597 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4545 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
#line 1603 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4554 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1609 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4563 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 315:
#line 1615 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4577 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 316:
#line 1626 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4586 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1633 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4595 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1637 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4604 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1641 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4613 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1645 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4622 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1649 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4631 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1653 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4640 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1657 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4649 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1661 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4658 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1665 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4667 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1671 "conf_parser.y" /* yacc.c:1652  */
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
#line 4684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1685 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4696 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1694 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4708 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 332:
#line 1707 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4720 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 333:
#line 1714 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4731 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1725 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4740 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 341:
#line 1731 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4749 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 342:
#line 1737 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4758 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1752 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 349:
#line 1768 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4789 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 350:
#line 1779 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4804 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1794 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4813 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 358:
#line 1800 "conf_parser.y" /* yacc.c:1652  */
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
#line 4835 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 359:
#line 1819 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4844 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1826 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1830 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4862 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1834 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4880 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1842 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4889 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1846 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4898 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1850 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1854 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4916 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1858 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1862 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4934 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 373:
#line 1872 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4948 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 374:
#line 1881 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4961 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 380:
#line 1894 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4970 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 381:
#line 1900 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4979 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4988 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4997 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5006 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5015 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1923 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5024 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5033 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1931 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5042 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5051 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1939 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5060 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
#line 1943 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5069 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 395:
#line 1953 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 396:
#line 1963 "conf_parser.y" /* yacc.c:1652  */
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
#line 5155 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2049 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5164 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2055 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5173 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2061 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5182 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2067 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5191 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2073 "conf_parser.y" /* yacc.c:1652  */
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
#line 5207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2086 "conf_parser.y" /* yacc.c:1652  */
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
#line 5223 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2099 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5232 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2105 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5241 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5250 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2115 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5259 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 425:
#line 2121 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5267 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5276 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2131 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5285 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2137 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2148 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2154 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2160 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5326 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2166 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5340 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 436:
#line 2181 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5349 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 437:
#line 2185 "conf_parser.y" /* yacc.c:1652  */
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
#line 5372 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2208 "conf_parser.y" /* yacc.c:1652  */
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
#line 5395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2228 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5404 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 445:
#line 2238 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5413 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 446:
#line 2242 "conf_parser.y" /* yacc.c:1652  */
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
#line 5437 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 452:
#line 2266 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5446 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 453:
#line 2272 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5455 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2287 "conf_parser.y" /* yacc.c:1652  */
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
#line 5472 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 460:
#line 2304 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5481 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 461:
#line 2308 "conf_parser.y" /* yacc.c:1652  */
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
#line 5501 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 467:
#line 2328 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5510 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 468:
#line 2334 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5519 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2395 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5527 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2400 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5535 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2405 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5543 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2410 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5551 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2415 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5559 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2420 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5567 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2425 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2430 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2435 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5591 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2440 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5599 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2445 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5607 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2450 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2455 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5623 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2460 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5631 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2465 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5639 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2470 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5647 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2475 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5655 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2480 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5663 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2485 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5671 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2490 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5679 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2495 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5687 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2500 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5695 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2505 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5703 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2510 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5711 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2515 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5719 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2520 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5727 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2525 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5735 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2530 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5743 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2535 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5751 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2540 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5759 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2545 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5767 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2550 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2555 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5783 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2560 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5791 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2565 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5799 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2570 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5807 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2575 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5815 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2580 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5823 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2585 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 557:
#line 2590 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5839 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2596 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5847 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2599 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2602 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5863 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2605 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5871 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2608 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2611 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5887 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2614 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2617 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2620 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5911 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2623 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5919 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2626 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2629 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5935 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2632 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5943 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2635 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5951 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2638 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5959 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2641 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2644 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5975 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2647 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5983 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2650 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5991 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2653 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2656 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6007 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2659 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6015 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6023 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 584:
#line 2667 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6031 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2673 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2676 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6047 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2679 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6055 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2682 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6063 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2685 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2688 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6079 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2691 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6087 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2694 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6095 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2697 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6103 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2700 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6111 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2703 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6119 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2706 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6127 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2709 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6135 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2712 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6143 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2715 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6151 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2718 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6159 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2721 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6167 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2724 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6175 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2727 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6183 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2730 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6191 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2733 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6199 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2738 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2743 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2748 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6223 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 612:
#line 2753 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6231 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2782 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2787 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6247 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2792 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6255 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2797 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2802 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2807 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6279 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2812 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6287 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2817 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6295 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2822 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6303 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2827 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6311 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2832 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6319 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2837 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6327 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2842 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6335 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 645:
#line 2847 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6343 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 646:
#line 2852 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6351 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6360 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2881 "conf_parser.y" /* yacc.c:1652  */
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
#line 6379 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6391 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2906 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6400 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2912 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6409 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2918 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6418 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2924 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6430 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 667:
#line 2933 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6439 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 668:
#line 2939 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6448 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6452 "conf_parser.c" /* yacc.c:1652  */
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
