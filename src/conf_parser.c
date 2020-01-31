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
    SPOOF_NOTICE = 404,
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
    TMASKED = 473,
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
#define SPOOF_NOTICE 404
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
#define TMASKED 473
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
#define YYLAST   1337

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  294
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1317

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
    1247,  1251,  1255,  1266,  1265,  1322,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,  1334,  1335,
    1336,  1337,  1338,  1340,  1346,  1352,  1358,  1364,  1370,  1376,
    1382,  1388,  1395,  1401,  1407,  1413,  1422,  1432,  1431,  1437,
    1437,  1438,  1442,  1453,  1452,  1459,  1458,  1463,  1463,  1464,
    1468,  1472,  1478,  1478,  1479,  1479,  1479,  1479,  1479,  1481,
    1481,  1483,  1483,  1485,  1498,  1515,  1521,  1532,  1531,  1578,
    1578,  1579,  1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,
    1589,  1595,  1601,  1607,  1619,  1618,  1624,  1624,  1625,  1629,
    1633,  1637,  1641,  1645,  1649,  1653,  1657,  1661,  1667,  1681,
    1690,  1704,  1703,  1718,  1718,  1719,  1719,  1719,  1719,  1721,
    1727,  1733,  1743,  1745,  1745,  1746,  1746,  1748,  1765,  1764,
    1787,  1787,  1788,  1788,  1788,  1788,  1790,  1796,  1816,  1815,
    1821,  1821,  1822,  1826,  1830,  1834,  1838,  1842,  1846,  1850,
    1854,  1858,  1869,  1868,  1887,  1887,  1888,  1888,  1888,  1890,
    1897,  1896,  1902,  1902,  1903,  1907,  1911,  1915,  1919,  1923,
    1927,  1931,  1935,  1939,  1950,  1949,  2027,  2027,  2028,  2029,
    2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,  2039,
    2040,  2041,  2042,  2043,  2045,  2051,  2057,  2063,  2069,  2082,
    2095,  2101,  2107,  2111,  2118,  2117,  2122,  2122,  2123,  2127,
    2133,  2144,  2150,  2156,  2162,  2178,  2177,  2201,  2201,  2202,
    2202,  2202,  2204,  2224,  2235,  2234,  2259,  2259,  2260,  2260,
    2260,  2262,  2268,  2278,  2280,  2280,  2281,  2281,  2283,  2301,
    2300,  2321,  2321,  2322,  2322,  2322,  2324,  2330,  2340,  2342,
    2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,  2351,
    2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2360,  2361,
    2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2370,  2371,
    2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,  2381,
    2382,  2383,  2384,  2385,  2386,  2387,  2388,  2391,  2396,  2401,
    2406,  2411,  2416,  2421,  2426,  2431,  2436,  2441,  2446,  2451,
    2456,  2461,  2466,  2471,  2476,  2481,  2486,  2491,  2496,  2501,
    2506,  2511,  2516,  2519,  2524,  2527,  2532,  2537,  2542,  2547,
    2552,  2557,  2562,  2567,  2572,  2577,  2582,  2587,  2593,  2592,
    2597,  2597,  2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,
    2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,
    2652,  2655,  2658,  2661,  2664,  2670,  2669,  2674,  2674,  2675,
    2678,  2681,  2684,  2687,  2690,  2693,  2696,  2699,  2702,  2705,
    2708,  2711,  2714,  2717,  2720,  2723,  2726,  2729,  2732,  2735,
    2740,  2745,  2750,  2755,  2764,  2766,  2766,  2767,  2768,  2769,
    2770,  2771,  2772,  2773,  2774,  2775,  2776,  2777,  2778,  2779,
    2780,  2781,  2782,  2784,  2789,  2794,  2799,  2804,  2809,  2814,
    2819,  2824,  2829,  2834,  2839,  2844,  2849,  2854,  2863,  2865,
    2865,  2866,  2867,  2868,  2869,  2870,  2871,  2872,  2873,  2874,
    2875,  2877,  2883,  2899,  2908,  2914,  2920,  2926,  2935,  2941
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
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
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

#define YYPACT_NINF -908

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-908)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -908,   702,  -908,  -196,  -205,  -190,  -908,  -908,  -908,  -185,
    -908,  -182,  -908,  -908,  -908,  -180,  -908,  -908,  -908,  -173,
    -153,  -908,  -152,  -908,  -145,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   347,   972,  -125,  -114,  -113,    26,  -103,   404,   -83,
     -70,   -30,   167,   -18,   -17,   -10,   551,   545,    -8,     2,
      32,    14,    33,  -138,    37,    38,    49,     4,  -908,  -908,
    -908,  -908,  -908,    61,    81,    88,    89,    90,    96,    99,
     100,   102,   104,   106,   107,   109,   113,   114,   144,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,   718,   573,   110,  -908,   115,
      18,  -908,  -908,   200,  -908,   117,   120,   122,   127,   128,
     130,   132,   143,   150,   152,   153,   155,   156,   157,   160,
     164,   170,   172,   176,   179,   181,   183,   184,   188,   189,
    -908,  -908,   190,   194,   195,   197,   201,   206,   210,   211,
     214,   215,   219,   220,   221,   222,   224,   230,   232,   233,
      42,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,   315,    40,   299,
    -135,   234,   235,    45,  -908,  -908,  -908,    30,   314,   270,
    -908,   236,   238,   239,   241,   242,   246,   247,   248,   249,
      13,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   -99,   250,   253,   258,   260,   262,   264,   267,   268,
     269,   272,   273,   274,   280,   281,   284,   291,    79,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,    86,   138,   293,    20,
    -908,  -908,  -908,   275,   209,  -908,   296,    25,  -908,  -908,
      84,  -908,   255,   329,   339,   301,  -908,   212,   425,   203,
     330,   427,   425,   425,   425,   432,   425,   425,   434,   435,
     438,   443,   321,  -908,   344,   326,   336,   346,  -908,   350,
     351,   352,   353,   355,   364,   367,   369,   374,   379,   380,
     218,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,   361,   383,   384,
     385,   386,   389,   390,  -908,   392,   393,   394,   401,   402,
     408,   409,   410,   279,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   412,   413,    22,  -908,  -908,  -908,   459,   366,  -908,
    -908,   416,   418,    24,  -908,  -908,  -908,   449,   425,   546,
     425,   425,   451,   548,   425,   464,   561,   562,   563,   468,
     470,   425,   568,   569,   571,   574,   425,   575,   577,   578,
     579,   486,   457,   458,   490,   425,   425,   492,   494,   495,
    -178,  -174,   498,   499,   501,   502,   600,   425,   425,   425,
     507,   605,   484,  -908,   487,   488,   489,  -908,   491,   493,
     503,   506,   509,   135,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,   511,   512,    35,  -908,  -908,  -908,
     497,   513,   516,  -908,   517,  -908,    23,  -908,  -908,  -908,
    -908,  -908,   597,   601,   504,  -908,   505,   518,   520,    12,
    -908,  -908,  -908,   526,   527,   528,  -908,   529,   530,  -908,
     531,   532,   534,   535,   173,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   539,   538,   540,   541,
      19,  -908,  -908,  -908,  -908,   522,   537,   425,   609,   572,
     621,   582,   585,   586,   542,  -908,  -908,   669,   656,   587,
     670,   684,   686,   672,   673,   674,   675,   676,   681,   682,
     683,   687,   688,   576,  -908,   583,   581,  -908,    56,  -908,
    -908,  -908,  -908,   613,   588,  -908,   580,   589,   590,   592,
     596,   602,    53,  -908,  -908,  -908,  -908,  -908,   698,   591,
    -908,   606,   604,  -908,   607,    17,  -908,  -908,  -908,  -908,
     611,   612,   616,  -908,   617,   428,   618,   619,   620,   622,
     623,   624,   625,   626,   627,   628,   630,   631,   632,   635,
    -908,  -908,   701,   715,   425,   610,   723,   425,   732,   425,
     729,   759,   760,   761,   425,   762,   762,   640,  -908,  -908,
     750,  -102,   751,   671,   753,   755,   645,   757,   758,   775,
     763,   765,   425,   766,   768,   653,  -908,   769,   770,   654,
    -908,   663,  -908,   779,   782,   667,  -908,   678,   679,   685,
     689,   690,   691,   693,   694,   695,   699,   700,   703,   704,
     705,   706,   708,   709,   710,   714,   721,   725,   726,   728,
     731,   733,   824,   737,   734,   736,   738,   741,   742,   746,
     747,   748,   771,   773,   774,   776,   777,   780,   781,   786,
     787,   788,   790,   791,  -908,  -908,   789,   711,   712,   794,
     799,   795,   809,   826,   792,  -908,   831,   840,   793,  -908,
    -908,   845,   858,   752,   881,   796,  -908,   797,   798,  -908,
    -908,   869,   871,   800,  -908,  -908,   876,   822,   802,   890,
     907,   803,   915,   835,   917,   918,   811,  -908,  -908,   920,
     921,   922,   815,  -908,   819,   820,   821,   828,   829,   830,
     832,   833,   834,  -908,   836,   837,   838,   839,   841,   842,
     843,   844,   846,   847,   848,   849,   850,   851,   852,   853,
    -908,  -908,   930,   823,   854,  -908,   855,  -908,    21,  -908,
     939,   943,   948,   953,   856,  -908,   857,  -908,  -908,   966,
     859,   967,   860,  -908,  -908,  -908,  -908,  -908,   425,   425,
     425,   425,   425,   425,   425,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   861,   863,   864,   -50,   865,   866,   867,   868,   870,
     872,   873,   874,   875,   363,   877,   878,  -908,   879,   880,
     882,   883,   884,   885,   886,     8,   887,   888,   889,   891,
     892,   893,   894,   895,  -908,   896,   897,  -908,  -908,   898,
     899,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -204,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -198,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,   900,   901,   358,   902,   903,
     904,   905,   906,  -908,   908,   909,  -908,   910,   911,   -33,
     919,   912,  -908,  -908,  -908,  -908,   913,   914,  -908,   923,
     924,   510,   925,   926,   784,   927,   928,   929,   931,  -908,
     932,   933,   934,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   935,
     348,  -908,  -908,   936,   916,   937,  -908,    11,  -908,  -908,
    -908,  -908,   938,   941,   942,   944,  -908,  -908,   945,   460,
     946,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -162,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,   762,   762,   762,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -140,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   824,  -908,   737,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -137,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -109,  -908,   992,   881,   947,
    -908,  -908,  -908,  -908,  -908,  -908,   949,  -908,   950,   951,
    -908,  -908,   952,   954,  -908,  -908,   955,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,   -46,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   -22,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   -13,  -908,  -908,   979,
    -101,   940,   958,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,    44,
    -908,  -908,  -908,   -50,  -908,  -908,  -908,  -908,     8,  -908,
    -908,  -908,   358,  -908,   -33,  -908,  -908,  -908,   978,   981,
    1014,   990,  1017,  1019,  -908,   510,  -908,   784,  -908,   348,
     961,   962,   963,   228,  -908,  -908,   460,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,    70,  -908,  -908,  -908,   228,  -908
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
      93,    92,   632,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   616,
     631,   630,   619,   620,   621,   622,   623,   624,   625,   626,
     627,   617,   618,   628,   629,     0,     0,     0,   457,     0,
       0,   455,   456,     0,   516,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   558,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   470,   471,   472,   514,   478,   515,   509,   510,   511,
     512,   482,   473,   474,   475,   476,   477,   479,   480,   481,
     483,   484,   513,   488,   489,   490,   491,   487,   486,   492,
     499,   500,   493,   494,   495,   485,   497,   507,   508,   505,
     506,   498,   496,   503,   504,   501,   502,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     660,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   650,   651,   652,   653,   654,   655,   656,   658,   657,
     659,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      67,    65,    63,    68,    69,    70,    64,    55,    66,    57,
      58,    59,    60,    61,    62,    56,     0,     0,     0,     0,
     122,   123,   124,     0,     0,   346,     0,     0,   344,   345,
       0,    94,     0,     0,     0,     0,    89,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   615,     0,     0,     0,     0,   267,     0,
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
       0,     0,     0,   469,     0,     0,     0,   314,     0,     0,
       0,     0,     0,     0,   300,   301,   302,   303,   308,   304,
     305,   306,   307,   441,     0,     0,     0,   438,   439,   440,
       0,     0,     0,   275,     0,   285,     0,   283,   284,   286,
     287,    49,     0,     0,     0,    45,     0,     0,     0,     0,
     101,   102,   103,     0,     0,     0,   200,     0,     0,   173,
       0,     0,     0,     0,     0,   153,   154,   155,   156,   157,
     160,   161,   162,   159,   158,   163,     0,     0,     0,     0,
       0,   334,   335,   336,   337,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   649,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,   380,     0,   375,
     376,   377,   125,     0,     0,   121,     0,     0,     0,     0,
       0,     0,     0,   110,   111,   113,   112,   114,     0,     0,
     343,     0,     0,   358,     0,     0,   351,   352,   353,   354,
       0,     0,     0,    88,     0,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     614,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   413,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   396,     0,     0,     0,
     446,     0,   453,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   468,   309,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   299,     0,     0,     0,   437,
     288,     0,     0,     0,     0,     0,   282,     0,     0,    44,
     104,     0,     0,     0,   100,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   152,   338,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   648,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,   378,     0,     0,     0,   374,     0,   120,     0,   115,
       0,     0,     0,     0,     0,   109,     0,   342,   355,     0,
       0,     0,     0,   350,    97,    96,    95,   646,    28,    28,
      28,    28,    28,    28,    28,    30,    29,   647,   634,   633,
     635,   636,   637,   638,   639,   640,   641,   644,   645,   642,
     643,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,   234,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   395,     0,     0,   445,   458,     0,
       0,   460,   528,   532,   517,   518,   547,   521,   612,   613,
     555,   522,   523,   552,   527,   535,   526,   524,   525,   531,
     530,   529,   553,   519,   610,   611,   551,   609,   595,   589,
     605,   590,   591,   592,   600,   608,   593,   602,   606,   596,
     607,   597,   601,   594,   604,   599,   598,   603,     0,   588,
     584,   567,   568,   569,   562,   580,   563,   564,   565,   575,
     583,   566,   577,   581,   571,   582,   572,   576,   570,   579,
     574,   573,   578,     0,   561,   548,   546,   549,   554,   550,
     537,   544,   545,   542,   543,   538,   539,   540,   541,   556,
     557,   534,   533,   536,   520,     0,     0,     0,     0,     0,
       0,     0,     0,   298,     0,     0,   436,     0,     0,     0,
     293,   289,   292,   274,    50,    51,     0,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   151,
       0,     0,     0,   332,   664,   661,   662,   663,   668,   667,
     669,   665,   666,    84,    81,    87,    80,    85,    86,    79,
      83,    82,    73,    72,    75,    76,    74,    77,    78,     0,
       0,   373,   126,     0,     0,     0,   138,     0,   130,   131,
     133,   132,     0,     0,     0,     0,   108,   347,     0,     0,
       0,   349,    31,    32,    33,    34,    35,    36,    37,   262,
     263,   257,   272,   271,     0,   270,   258,   266,   259,   265,
     253,   264,   256,   255,   254,    38,    38,    38,    40,    39,
     260,   261,   419,   422,   423,   433,   430,   415,   431,   428,
     429,     0,   427,   432,   414,   421,   418,   417,   416,   420,
     434,   451,   452,   466,   467,   586,     0,   559,     0,   312,
     313,   323,   319,   320,   322,   327,   324,   325,   318,   326,
     321,     0,   317,   311,   330,   329,   328,   310,   443,   442,
     296,   295,   280,   281,   279,     0,   278,     0,     0,     0,
     105,   106,   172,   169,   220,   232,   207,   216,     0,   205,
     210,   226,     0,   219,   224,   230,   209,   212,   221,   223,
     227,   217,   225,   213,   231,   215,   222,   211,   214,     0,
     203,   165,   167,   199,   182,   183,   184,   177,   195,   178,
     179,   180,   190,   198,   181,   192,   196,   186,   197,   187,
     191,   185,   194,   189,   188,   193,     0,   176,   170,   171,
     166,   168,   341,   339,   340,   379,   384,   390,   393,   386,
     392,   387,   391,   389,   385,   388,     0,   383,   134,     0,
       0,     0,     0,   129,   117,   116,   118,   119,   356,   362,
     368,   371,   364,   370,   365,   369,   367,   363,   366,     0,
     361,   357,   268,     0,    41,    42,    43,   425,     0,   587,
     560,   315,     0,   276,     0,   294,   291,   290,     0,     0,
       0,     0,     0,     0,   201,     0,   174,     0,   381,     0,
       0,     0,     0,     0,   128,   359,     0,   269,   426,   316,
     277,   206,   229,   204,   228,   218,   208,   202,   175,   382,
     135,   137,   136,   148,   147,   143,   145,   149,   146,   142,
     144,     0,   141,   360,   139,     0,   140
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -908,  -908,  -908,  -155,  -306,  -907,  -635,  -908,  -908,   959,
    -908,  -908,  -908,  -908,   956,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  1074,  -908,  -908,  -908,  -908,  -908,  -908,
     655,  -908,  -908,  -908,  -908,  -908,   599,  -908,  -908,  -908,
    -908,  -908,  -908,   957,  -908,  -908,  -908,  -908,   108,  -908,
    -908,  -908,  -908,  -908,  -143,  -908,  -908,  -908,   639,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -107,  -908,  -908,  -908,  -112,  -908,  -908,  -908,   862,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,   -69,  -908,  -908,  -908,
    -908,  -908,   -81,  -908,   713,  -908,  -908,  -908,    50,  -908,
    -908,  -908,  -908,  -908,   722,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,   -76,  -908,  -908,  -908,  -908,  -908,  -908,   677,
    -908,  -908,  -908,  -908,  -908,   960,  -908,  -908,  -908,  -908,
     608,  -908,  -908,  -908,  -908,  -908,   -89,  -908,  -908,  -908,
     633,  -908,  -908,  -908,  -908,   -79,  -908,  -908,  -908,   964,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,   -54,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,   730,  -908,  -908,  -908,  -908,  -908,   812,  -908,  -908,
    -908,  -908,  1088,  -908,  -908,  -908,  -908,   806,  -908,  -908,
    -908,  -908,  1040,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,    93,  -908,  -908,  -908,    97,
    -908,  -908,  -908,  -908,  -908,  -908,  1114,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908,   974,  -908,  -908,  -908,  -908,  -908,
    -908,  -908,  -908,  -908
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   825,   826,  1088,  1089,    27,   223,   224,
     225,   226,    28,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,    29,    77,    78,    79,    80,    81,    30,    63,   499,
     500,   501,   502,    31,    70,   582,   583,   584,   585,   586,
     587,    32,   289,   290,   291,   292,   293,  1047,  1048,  1049,
    1050,  1051,  1231,  1311,  1312,    33,    64,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   751,  1206,
    1207,   525,   748,  1179,  1180,    34,    53,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   625,  1074,  1075,    35,    61,   485,
     733,  1145,  1146,   486,   487,   488,  1149,   991,   992,   489,
     490,    36,    59,   463,   464,   465,   466,   467,   468,   469,
     718,  1131,  1132,   470,   471,   472,    37,    65,   530,   531,
     532,   533,   534,    38,   297,   298,   299,    39,    72,   595,
     596,   597,   598,   599,   810,  1249,  1250,    40,    68,   568,
     569,   570,   571,   793,  1226,  1227,    41,    54,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     646,  1101,  1102,   385,   386,   387,   388,   389,    42,    60,
     476,   477,   478,   479,    43,    55,   393,   394,   395,   396,
      44,   120,   121,   122,    45,    57,   403,   404,   405,   406,
      46,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   433,   953,   954,   212,   432,   928,   929,
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
     855,   856,   606,   287,  1072,    73,   610,   611,   612,   854,
     614,   615,  1043,   496,   230,   295,  1099,  1142,   591,   118,
     526,   287,  1043,   390,   480,   400,   295,   118,   700,  1115,
      51,   496,   702,  1116,    74,  1117,   473,    49,    50,  1118,
     701,   473,    75,   124,   703,    52,   220,   231,   125,   126,
      56,   127,   128,    58,   577,    62,   129,   565,   232,   233,
     234,   527,    66,   235,   236,   130,   131,   132,   237,   238,
     239,  1252,   859,   860,   133,  1253,  1073,   134,   135,   136,
     251,   481,    67,    69,   119,   591,   137,   565,   391,   482,
      71,   483,   119,  1257,   497,   301,  1261,  1258,   491,  1281,
    1262,   528,   668,   138,   670,   671,    76,   252,   674,   253,
     115,   390,   497,  1044,   139,   681,   296,   140,   141,   592,
     686,   116,   117,  1044,  1263,   142,   401,   296,  1264,   695,
     696,   143,   123,   144,   546,   145,   454,   146,   254,   147,
     148,   709,   710,   711,   221,    82,   529,   484,   255,   392,
     149,   402,   217,  1143,   455,   578,   150,   151,   566,   152,
     153,   154,   474,  1144,   155,   218,   222,   474,   220,   256,
      83,    84,  -127,   257,   503,   456,   391,    85,  1254,  1255,
    1256,   258,   498,    86,   259,   260,   592,  1274,   566,   156,
    -127,  1275,   504,   157,   158,   159,   160,   161,   162,   163,
     498,   400,  1045,   457,  1100,   219,    87,    88,    89,    90,
     577,  1276,  1045,   505,   261,  1277,   579,   227,   228,   324,
    1278,    91,    92,    93,  1279,   229,   288,   286,    94,    95,
      96,   766,    97,  1046,   580,   325,   326,   392,   305,   593,
     327,   506,   594,  1046,   288,  1232,   743,   544,   581,   164,
     165,   812,   398,   762,   574,   458,   659,   735,   665,   589,
     475,   166,   167,   459,   460,   475,   221,   294,   300,   728,
     168,   526,   169,   302,   303,   507,   452,  1285,   567,   494,
     357,  1286,   358,   461,   359,   304,   328,   804,   222,   262,
     794,   263,   264,   508,   265,   266,   267,   307,   360,  1303,
     480,  1304,   401,  1314,   329,   330,   593,  1315,   567,   594,
     331,   578,   527,   563,   332,   503,   454,   308,   843,   361,
     333,   846,   604,   848,   309,   310,   311,   402,   853,   334,
     335,   336,   312,   504,   455,   313,   314,   362,   315,   363,
     316,   337,   317,   318,  1305,   319,   871,   364,    73,   320,
     321,   397,   528,   407,   505,   456,   408,   481,   409,   365,
     462,  1306,   338,   410,   411,   482,   412,   483,   413,   724,
     509,   572,   579,  1121,  1085,  1086,  1087,    74,   322,   414,
     600,   366,   506,   457,   510,    75,   415,   511,   416,   417,
     580,   418,   419,   420,  1307,  1308,   421,   529,   512,  1122,
     422,   339,   513,   367,   581,   124,   423,   756,   424,   607,
     125,   126,   425,   127,   128,   426,   507,   427,   129,   428,
     429,  1216,   368,   484,   430,   431,   434,   130,   131,   132,
     435,   436,  1123,   437,   508,   458,   133,   438,   369,   134,
     135,   136,   439,   459,   460,   576,   440,   441,   137,    76,
     442,   443,   637,  1309,   601,   444,   445,   446,   447,  1310,
     448,  1124,  1125,   461,   602,   138,   449,  1126,   450,   451,
     492,   493,   535,   854,   536,   537,   139,   538,   539,   140,
     141,  1217,   540,   541,   542,   543,   547,   142,   370,   548,
     371,   372,  1127,   143,   549,   144,   550,   145,   551,   146,
     552,   147,   148,   553,   554,   555,  1218,  1128,   556,   557,
     558,   509,   149,   655,  1154,  1219,   559,   560,   150,   151,
     561,   152,   153,   154,  1220,   510,   155,   562,   511,   573,
    1155,  1156,   588,  1239,   603,   605,   608,   609,   605,   512,
     462,  1157,   613,   513,   616,   617,   251,  1221,   618,  1222,
    1223,   156,   230,   619,   620,   157,   158,   159,   160,   161,
     162,   163,   622,  1129,   818,   819,   820,   821,   822,   823,
     824,  1224,   623,   252,   357,   253,   358,   621,   359,  1225,
    1158,  1159,   624,  1160,   661,   231,   626,   627,   628,   629,
    1130,   630,   360,  1240,   639,  1282,   232,   233,   234,   662,
     631,   235,   236,   632,   254,   633,   237,   238,   239,  1161,
     634,   164,   165,   361,   255,   635,   636,  1162,  1241,   640,
     641,   642,   643,   166,   167,   644,   645,  1242,   647,   648,
     649,   362,   168,   363,   169,   256,  1243,   650,   651,   257,
    1163,   364,  1164,  1165,   652,   653,   654,   258,   657,   658,
     259,   260,   663,   365,   664,   667,   669,   672,   673,  1244,
    1166,  1245,  1246,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
     675,   676,   677,   678,   679,   366,   680,  1167,   682,   683,
     261,   684,  1168,  1247,   685,   687,  1169,   688,   689,   690,
    1170,  1248,   691,   692,   693,  1171,   694,   367,   697,  1172,
     698,   699,     2,     3,   704,   705,     4,   706,   707,  1173,
     708,  1174,  1175,   712,  1176,   713,   368,   714,     5,   324,
     715,     6,   737,     7,   716,   717,   738,   719,   764,   720,
     730,     8,   369,  1177,   767,   325,   326,   739,   740,   721,
     327,  1178,   722,   765,     9,   723,   769,   726,   727,   731,
      10,    11,   732,   734,   741,   262,   742,   263,   264,   745,
     265,   266,   267,   746,   747,   749,   750,   752,   753,    12,
     754,   755,   758,    13,   759,   773,   760,   761,   768,   774,
     930,   775,   370,    14,   371,   372,   328,   931,   770,   932,
     933,   771,   772,   776,   778,   777,   779,   780,   781,   782,
     783,   784,    15,    16,   329,   330,   785,   786,   787,   790,
     331,   841,   788,   789,   332,   798,   791,   792,    17,   796,
     333,   797,   799,   806,   807,   842,   800,  1183,   801,   334,
     335,   336,   802,   845,  1184,    18,  1185,  1186,   803,   808,
     809,   337,   847,   811,   814,   815,   844,    19,    20,   816,
     817,   827,   828,   829,   849,   830,   831,   832,   833,   834,
     835,   836,   338,   837,   838,   839,    21,   907,   840,   850,
     851,   852,   854,   857,   908,   858,   861,   862,   863,    22,
     864,   865,   866,   867,    23,   868,   874,   877,   869,    24,
     870,   872,    25,   873,   875,   876,   878,   934,   935,   936,
     881,   339,   937,   938,   879,   939,   940,   880,   941,   979,
     942,   882,   883,   943,   975,   944,   945,   976,   884,   978,
     980,   946,   885,   886,   887,   947,   888,   889,   890,   948,
     949,   950,   891,   892,   981,   951,   893,   894,   895,   896,
     952,   897,   898,   899,  1187,  1188,  1189,   900,   977,  1190,
    1191,   982,  1192,  1193,   901,  1194,   984,  1195,   902,   903,
    1196,   904,  1197,  1198,   905,   985,   906,   955,  1199,   956,
     987,   957,  1200,    82,   958,   959,  1201,  1202,  1203,   960,
     961,   962,  1204,   988,   909,   910,   911,  1205,   989,   912,
     913,   990,   914,   915,   996,   916,   997,   917,    83,    84,
     918,   999,   919,   920,   963,    85,   964,   965,   921,   966,
     967,    86,   922,   968,   969,  1002,   923,   924,   925,   970,
     971,   972,   926,   973,   974,   983,   986,   927,  1000,   993,
     994,   995,  1003,   998,    87,    88,    89,    90,  1001,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,    91,
      92,    93,  1014,  1015,  1016,  1039,    94,    95,    96,  1040,
      97,  1017,  1018,  1019,  1052,  1020,  1021,  1022,  1053,  1023,
    1024,  1025,  1026,  1054,  1027,  1028,  1029,  1030,  1055,  1031,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,  1041,  1042,  1056,
    1057,  1058,  1060,  1061,  1069,  1059,  1070,  1071,  1076,  1077,
    1078,  1079,  1265,  1080,  1280,  1081,  1082,  1083,  1084,  1291,
    1090,  1091,  1092,  1093,  1292,  1094,  1095,  1096,  1097,  1098,
    1103,  1104,  1105,  1294,  1106,  1107,  1108,  1109,  1110,  1111,
    1112,  1113,  1114,  1119,  1120,  1133,  1134,  1135,  1136,  1137,
    1147,  1138,  1139,  1140,  1141,  1293,  1150,  1151,  1295,  1148,
    1296,   306,  1229,   757,   744,  1233,  1152,  1153,  1181,  1182,
    1208,  1209,  1210,  1297,  1211,  1212,  1213,  1214,  1215,  1228,
    1298,  1234,  1316,  1230,  1235,  1236,  1283,  1237,  1238,  1251,
    1267,   805,   495,  1290,  1287,   725,  1289,  1268,  1269,  1270,
    1271,  1284,  1272,  1273,  1300,  1301,  1302,  1313,  1266,   736,
    1299,   795,   638,   813,  1288,   660,   729,   763,   399,   666,
     453,  1260,   323,  1259,   545,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   575,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   656
};

static const yytype_int16 yycheck[] =
{
     635,   636,   308,     1,    54,     1,   312,   313,   314,   110,
     316,   317,     1,     1,     1,     1,     8,    50,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,   206,   233,
     235,     1,   206,   237,    30,   233,     1,   233,   234,   237,
     218,     1,    38,     1,   218,   235,     1,    34,     6,     7,
     235,     9,    10,   235,     1,   235,    14,     1,    45,    46,
      47,    42,   235,    50,    51,    23,    24,    25,    55,    56,
      57,   233,   174,   175,    32,   237,   126,    35,    36,    37,
       1,    58,   235,   235,    66,     1,    44,     1,    66,    66,
     235,    68,    66,   233,    82,   233,   233,   237,   233,   200,
     237,    82,   408,    61,   410,   411,   102,    28,   414,    30,
     235,     1,    82,   102,    72,   421,   102,    75,    76,   102,
     426,   235,   235,   102,   233,    83,   102,   102,   237,   435,
     436,    89,   235,    91,   233,    93,     1,    95,    59,    97,
      98,   447,   448,   449,    99,     1,   127,   124,    69,   127,
     108,   127,   235,   186,    19,   102,   114,   115,   102,   117,
     118,   119,   127,   196,   122,   235,   121,   127,     1,    90,
      26,    27,   170,    94,     1,    40,    66,    33,  1085,  1086,
    1087,   102,   170,    39,   105,   106,   102,   233,   102,   147,
     170,   237,    19,   151,   152,   153,   154,   155,   156,   157,
     170,     1,   191,    68,   196,   235,    62,    63,    64,    65,
       1,   233,   191,    40,   135,   237,   163,   235,   235,     1,
     233,    77,    78,    79,   237,   235,   224,   235,    84,    85,
      86,   537,    88,   222,   181,    17,    18,   127,   234,   222,
      22,    68,   225,   222,   224,   234,   234,   234,   195,   207,
     208,   234,   234,   234,   234,   120,   234,   234,   234,   234,
     225,   219,   220,   128,   129,   225,    99,   235,   235,   234,
     228,     1,   230,   236,   236,   102,   234,   233,   222,   234,
       1,   237,     3,   148,     5,   236,    68,   234,   121,   210,
     234,   212,   213,   120,   215,   216,   217,   236,    19,    71,
       1,    73,   102,   233,    86,    87,   222,   237,   222,   225,
      92,   102,    42,   234,    96,     1,     1,   236,   624,    40,
     102,   627,   110,   629,   236,   236,   236,   127,   634,   111,
     112,   113,   236,    19,    19,   236,   236,    58,   236,    60,
     236,   123,   236,   236,   116,   236,   652,    68,     1,   236,
     236,   236,    82,   236,    40,    40,   236,    58,   236,    80,
     225,   133,   144,   236,   236,    66,   236,    68,   236,   234,
     197,   233,   163,    15,    11,    12,    13,    30,   234,   236,
     125,   102,    68,    68,   211,    38,   236,   214,   236,   236,
     181,   236,   236,   236,   166,   167,   236,   127,   225,    41,
     236,   183,   229,   124,   195,     1,   236,   234,   236,   206,
       6,     7,   236,     9,    10,   236,   102,   236,    14,   236,
     236,    73,   143,   124,   236,   236,   236,    23,    24,    25,
     236,   236,    74,   236,   120,   120,    32,   236,   159,    35,
      36,    37,   236,   128,   129,   170,   236,   236,    44,   102,
     236,   236,   234,   225,   125,   236,   236,   236,   236,   231,
     236,   103,   104,   148,   125,    61,   236,   109,   236,   236,
     236,   236,   236,   110,   236,   236,    72,   236,   236,    75,
      76,   133,   236,   236,   236,   236,   236,    83,   209,   236,
     211,   212,   134,    89,   236,    91,   236,    93,   236,    95,
     236,    97,    98,   236,   236,   236,   158,   149,   236,   236,
     236,   197,   108,   234,     4,   167,   236,   236,   114,   115,
     236,   117,   118,   119,   176,   211,   122,   236,   214,   236,
      20,    21,   236,    73,   233,   110,   206,   110,   110,   225,
     225,    31,   110,   229,   110,   110,     1,   199,   110,   201,
     202,   147,     1,   110,   233,   151,   152,   153,   154,   155,
     156,   157,   236,   205,   136,   137,   138,   139,   140,   141,
     142,   223,   236,    28,     1,    30,     3,   233,     5,   231,
      70,    71,   236,    73,   125,    34,   236,   236,   236,   236,
     232,   236,    19,   133,   233,  1230,    45,    46,    47,   233,
     236,    50,    51,   236,    59,   236,    55,    56,    57,    99,
     236,   207,   208,    40,    69,   236,   236,   107,   158,   236,
     236,   236,   236,   219,   220,   236,   236,   167,   236,   236,
     236,    58,   228,    60,   230,    90,   176,   236,   236,    94,
     130,    68,   132,   133,   236,   236,   236,   102,   236,   236,
     105,   106,   236,    80,   236,   206,   110,   206,   110,   199,
     150,   201,   202,   818,   819,   820,   821,   822,   823,   824,
     206,   110,   110,   110,   206,   102,   206,   167,   110,   110,
     135,   110,   172,   223,   110,   110,   176,   110,   110,   110,
     180,   231,   206,   236,   236,   185,   206,   124,   206,   189,
     206,   206,     0,     1,   206,   206,     4,   206,   206,   199,
     110,   201,   202,   206,   204,   110,   143,   233,    16,     1,
     233,    19,   125,    21,   236,   236,   125,   236,   206,   236,
     233,    29,   159,   223,   125,    17,    18,   233,   233,   236,
      22,   231,   236,   206,    42,   236,   125,   236,   236,   236,
      48,    49,   236,   236,   236,   210,   236,   212,   213,   233,
     215,   216,   217,   236,   236,   236,   236,   236,   236,    67,
     236,   236,   233,    71,   236,   233,   236,   236,   206,   110,
      43,   125,   209,    81,   211,   212,    68,    50,   206,    52,
      53,   206,   206,   206,   110,   125,   110,   125,   125,   125,
     125,   125,   100,   101,    86,    87,   125,   125,   125,   233,
      92,   110,   125,   125,    96,   235,   233,   236,   116,   206,
     102,   233,   233,   125,   233,   110,   236,    43,   236,   111,
     112,   113,   236,   110,    50,   133,    52,    53,   236,   233,
     236,   123,   110,   236,   233,   233,   236,   145,   146,   233,
     233,   233,   233,   233,   125,   233,   233,   233,   233,   233,
     233,   233,   144,   233,   233,   233,   164,    43,   233,   110,
     110,   110,   110,   233,    50,   125,   125,   206,   125,   177,
     125,   236,   125,   125,   182,   110,   233,   233,   125,   187,
     125,   125,   190,   125,   125,   125,   233,   160,   161,   162,
     233,   183,   165,   166,   125,   168,   169,   125,   171,   110,
     173,   233,   233,   176,   125,   178,   179,   206,   233,   125,
     125,   184,   233,   233,   233,   188,   233,   233,   233,   192,
     193,   194,   233,   233,   125,   198,   233,   233,   233,   233,
     203,   233,   233,   233,   160,   161,   162,   233,   236,   165,
     166,   125,   168,   169,   233,   171,   125,   173,   233,   233,
     176,   233,   178,   179,   233,   125,   233,   233,   184,   233,
     125,   233,   188,     1,   233,   233,   192,   193,   194,   233,
     233,   233,   198,   125,   160,   161,   162,   203,   236,   165,
     166,   110,   168,   169,   125,   171,   125,   173,    26,    27,
     176,   125,   178,   179,   233,    33,   233,   233,   184,   233,
     233,    39,   188,   233,   233,   125,   192,   193,   194,   233,
     233,   233,   198,   233,   233,   233,   233,   203,   206,   233,
     233,   233,   125,   233,    62,    63,    64,    65,   236,   236,
     125,   206,   125,   125,   233,   125,   125,   125,   233,    77,
      78,    79,   233,   233,   233,   125,    84,    85,    86,   236,
      88,   233,   233,   233,   125,   233,   233,   233,   125,   233,
     233,   233,   233,   125,   233,   233,   233,   233,   125,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   125,   125,   233,   233,   236,   233,   233,   233,   233,
     233,   233,   110,   233,   125,   233,   233,   233,   233,   131,
     233,   233,   233,   233,   133,   233,   233,   233,   233,   233,
     233,   233,   233,   133,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     221,   233,   233,   233,   233,   131,   233,   233,   131,   237,
     131,    77,   236,   514,   499,  1047,   233,   233,   233,   233,
     233,   233,   233,  1275,   233,   233,   233,   233,   233,   233,
    1277,   233,  1315,   236,   233,   233,   236,   233,   233,   233,
     233,   582,   223,  1264,  1253,   463,  1262,   238,   238,   238,
     238,   233,   238,   238,   233,   233,   233,  1286,  1148,   486,
    1279,   568,   340,   595,  1258,   393,   476,   530,   120,   403,
     170,  1118,    98,  1116,   240,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   268,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   289,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   297,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   373
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   240,     0,     1,     4,    16,    19,    21,    29,    42,
      48,    49,    67,    71,    81,   100,   101,   116,   133,   145,
     146,   164,   177,   182,   187,   190,   241,   246,   251,   270,
     276,   282,   290,   304,   324,   346,   360,   375,   382,   386,
     396,   405,   427,   433,   439,   443,   449,   503,   521,   233,
     234,   235,   235,   325,   406,   434,   235,   444,   235,   361,
     428,   347,   235,   277,   305,   376,   235,   235,   397,   235,
     283,   235,   387,     1,    30,    38,   102,   271,   272,   273,
     274,   275,     1,    26,    27,    33,    39,    62,    63,    64,
      65,    77,    78,    79,    84,    85,    86,    88,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   235,   235,   235,     1,    66,
     440,   441,   442,   235,     1,     6,     7,     9,    10,    14,
      23,    24,    25,    32,    35,    36,    37,    44,    61,    72,
      75,    76,    83,    89,    91,    93,    95,    97,    98,   108,
     114,   115,   117,   118,   119,   122,   147,   151,   152,   153,
     154,   155,   156,   157,   207,   208,   219,   220,   228,   230,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   495,   499,   500,   501,   502,   235,   235,   235,
       1,    99,   121,   247,   248,   249,   250,   235,   235,   235,
       1,    34,    45,    46,    47,    50,    51,    55,    56,    57,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,     1,    28,    30,    59,    69,    90,    94,   102,   105,
     106,   135,   210,   212,   213,   215,   216,   217,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   235,     1,   224,   291,
     292,   293,   294,   295,   235,     1,   102,   383,   384,   385,
     235,   233,   236,   236,   236,   234,   272,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   234,   505,     1,    17,    18,    22,    68,    86,
      87,    92,    96,   102,   111,   112,   113,   123,   144,   183,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,     1,     3,     5,
      19,    40,    58,    60,    68,    80,   102,   124,   143,   159,
     209,   211,   212,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   422,   423,   424,   425,   426,
       1,    66,   127,   435,   436,   437,   438,   236,   234,   441,
       1,   102,   127,   445,   446,   447,   448,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   496,   492,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   234,   451,     1,    19,    40,    68,   120,   128,
     129,   148,   225,   362,   363,   364,   365,   366,   367,   368,
     372,   373,   374,     1,   127,   225,   429,   430,   431,   432,
       1,    58,    66,    68,   124,   348,   352,   353,   354,   358,
     359,   233,   236,   236,   234,   248,     1,    82,   170,   278,
     279,   280,   281,     1,    19,    40,    68,   102,   120,   197,
     211,   214,   225,   229,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   320,     1,    42,    82,   127,
     377,   378,   379,   380,   381,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   234,   523,   233,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   234,   253,     1,   102,   222,   398,   399,
     400,   401,   233,   236,   234,   292,   170,     1,   102,   163,
     181,   195,   284,   285,   286,   287,   288,   289,   236,   234,
     384,     1,   102,   222,   225,   388,   389,   390,   391,   392,
     125,   125,   125,   233,   110,   110,   243,   206,   206,   110,
     243,   243,   243,   110,   243,   243,   110,   110,   110,   110,
     233,   233,   236,   236,   236,   343,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   234,   327,   233,
     236,   236,   236,   236,   236,   236,   419,   236,   236,   236,
     236,   236,   236,   236,   236,   234,   408,   236,   236,   234,
     436,   125,   233,   236,   236,   234,   446,   206,   243,   110,
     243,   243,   206,   110,   243,   206,   110,   110,   110,   206,
     206,   243,   110,   110,   110,   110,   243,   110,   110,   110,
     110,   206,   236,   236,   206,   243,   243,   206,   206,   206,
     206,   218,   206,   218,   206,   206,   206,   206,   110,   243,
     243,   243,   206,   110,   233,   233,   236,   236,   369,   236,
     236,   236,   236,   236,   234,   363,   236,   236,   234,   430,
     233,   236,   236,   349,   236,   234,   353,   125,   125,   233,
     233,   236,   236,   234,   279,   233,   236,   236,   321,   236,
     236,   317,   236,   236,   236,   236,   234,   307,   233,   236,
     236,   236,   234,   378,   206,   206,   243,   125,   206,   125,
     206,   206,   206,   233,   110,   125,   206,   125,   110,   110,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     233,   233,   236,   402,   234,   399,   206,   233,   235,   233,
     236,   236,   236,   236,   234,   285,   125,   233,   233,   236,
     393,   236,   234,   389,   233,   233,   233,   233,   136,   137,
     138,   139,   140,   141,   142,   242,   243,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   110,   110,   243,   236,   110,   243,   110,   243,   125,
     110,   110,   110,   243,   110,   245,   245,   233,   125,   174,
     175,   125,   206,   125,   125,   236,   125,   125,   110,   125,
     125,   243,   125,   125,   233,   125,   125,   233,   233,   125,
     125,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,    43,    50,   160,
     161,   162,   165,   166,   168,   169,   171,   173,   176,   178,
     179,   184,   188,   192,   193,   194,   198,   203,   497,   498,
      43,    50,    52,    53,   160,   161,   162,   165,   166,   168,
     169,   171,   173,   176,   178,   179,   184,   188,   192,   193,
     194,   198,   203,   493,   494,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   125,   206,   236,   125,   110,
     125,   125,   125,   233,   125,   125,   233,   125,   125,   236,
     110,   356,   357,   233,   233,   233,   125,   125,   233,   125,
     206,   236,   125,   125,   236,   125,   206,   125,   125,   233,
     125,   125,   125,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   125,
     236,   233,   233,     1,   102,   191,   222,   296,   297,   298,
     299,   300,   125,   125,   125,   125,   233,   233,   125,   236,
     125,   233,   242,   242,   242,   242,   242,   242,   242,   233,
     233,   233,    54,   126,   344,   345,   233,   233,   233,   233,
     233,   233,   233,   233,   233,    11,    12,    13,   244,   245,
     233,   233,   233,   233,   233,   233,   233,   233,   233,     8,
     196,   420,   421,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   237,   233,   237,   233,
     233,    15,    41,    74,   103,   104,   109,   134,   149,   205,
     232,   370,   371,   233,   233,   233,   233,   233,   233,   233,
     233,   233,    50,   186,   196,   350,   351,   221,   237,   355,
     233,   233,   233,   233,     4,    20,    21,    31,    70,    71,
      73,    99,   107,   130,   132,   133,   150,   167,   172,   176,
     180,   185,   189,   199,   201,   202,   204,   223,   231,   322,
     323,   233,   233,    43,    50,    52,    53,   160,   161,   162,
     165,   166,   168,   169,   171,   173,   176,   178,   179,   184,
     188,   192,   193,   194,   198,   203,   318,   319,   233,   233,
     233,   233,   233,   233,   233,   233,    73,   133,   158,   167,
     176,   199,   201,   202,   223,   231,   403,   404,   233,   236,
     236,   301,   234,   297,   233,   233,   233,   233,   233,    73,
     133,   158,   167,   176,   199,   201,   202,   223,   231,   394,
     395,   233,   233,   237,   244,   244,   244,   233,   237,   498,
     494,   233,   237,   233,   237,   110,   357,   233,   238,   238,
     238,   238,   238,   238,   233,   237,   233,   237,   233,   237,
     125,   200,   245,   236,   233,   233,   237,   345,   421,   371,
     351,   131,   133,   131,   133,   131,   131,   323,   319,   404,
     233,   233,   233,    71,    73,   116,   133,   166,   167,   225,
     231,   302,   303,   395,   233,   237,   303
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
     351,   351,   352,   352,   353,   353,   353,   353,   353,   355,
     354,   356,   356,   357,   357,   358,   359,   361,   360,   362,
     362,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     364,   365,   366,   367,   369,   368,   370,   370,   371,   371,
     371,   371,   371,   371,   371,   371,   371,   371,   372,   373,
     374,   376,   375,   377,   377,   378,   378,   378,   378,   379,
     380,   381,   382,   383,   383,   384,   384,   385,   387,   386,
     388,   388,   389,   389,   389,   389,   390,   391,   393,   392,
     394,   394,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   397,   396,   398,   398,   399,   399,   399,   400,
     402,   401,   403,   403,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   406,   405,   407,   407,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   408,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   417,   419,   418,   420,   420,   421,   421,
     422,   423,   424,   425,   426,   428,   427,   429,   429,   430,
     430,   430,   431,   432,   434,   433,   435,   435,   436,   436,
     436,   437,   438,   439,   440,   440,   441,   441,   442,   444,
     443,   445,   445,   446,   446,   446,   447,   448,   449,   450,
     450,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   477,   478,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   492,   491,
     493,   493,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   496,   495,   497,   497,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     499,   500,   501,   502,   503,   504,   504,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,   522,
     522,   523,   523,   523,   523,   523,   523,   523,   523,   523,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4
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
#line 2869 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2875 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2881 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2887 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2893 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2905 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2911 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 408 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2923 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2929 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2935 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2941 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 415 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2947 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 428 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2956 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 434 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2965 "conf_parser.c" /* yacc.c:1652  */
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
#line 2977 "conf_parser.c" /* yacc.c:1652  */
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
#line 2989 "conf_parser.c" /* yacc.c:1652  */
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
#line 3001 "conf_parser.c" /* yacc.c:1652  */
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
#line 3013 "conf_parser.c" /* yacc.c:1652  */
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
#line 3025 "conf_parser.c" /* yacc.c:1652  */
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
#line 3037 "conf_parser.c" /* yacc.c:1652  */
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
#line 3049 "conf_parser.c" /* yacc.c:1652  */
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
#line 3067 "conf_parser.c" /* yacc.c:1652  */
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
#line 3085 "conf_parser.c" /* yacc.c:1652  */
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
#line 3098 "conf_parser.c" /* yacc.c:1652  */
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
#line 3115 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 583 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3127 "conf_parser.c" /* yacc.c:1652  */
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
#line 3153 "conf_parser.c" /* yacc.c:1652  */
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
#line 3179 "conf_parser.c" /* yacc.c:1652  */
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
#line 3205 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 661 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3214 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 679 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3226 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 688 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3238 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 697 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3250 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 710 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3259 "conf_parser.c" /* yacc.c:1652  */
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
#line 3276 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 731 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3285 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 737 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3294 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 747 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3303 "conf_parser.c" /* yacc.c:1652  */
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
#line 3321 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 769 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3330 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 775 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3339 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 781 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3348 "conf_parser.c" /* yacc.c:1652  */
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
#line 3369 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 815 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3378 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 821 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3387 "conf_parser.c" /* yacc.c:1652  */
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
#line 3400 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 841 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3411 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 849 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3419 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 852 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3427 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 857 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3436 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 864 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3445 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 868 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3454 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 872 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3463 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 876 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3472 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 880 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3481 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 884 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3490 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 888 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3499 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 892 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3508 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3520 "conf_parser.c" /* yacc.c:1652  */
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
#line 3579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 978 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 984 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 990 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3606 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 996 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3615 "conf_parser.c" /* yacc.c:1652  */
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
#line 3629 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1013 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3638 "conf_parser.c" /* yacc.c:1652  */
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
#line 3652 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1030 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3661 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1036 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3670 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1043 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3679 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1047 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3688 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1051 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3697 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1055 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3706 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1059 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3715 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1063 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1067 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3733 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1071 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3742 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1075 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3751 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1079 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3760 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1083 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3769 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1087 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3778 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1091 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3787 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3796 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1099 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3805 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1103 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3814 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1107 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3823 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3832 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1115 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3841 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1119 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3850 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1123 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1131 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1137 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1144 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1148 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3904 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1152 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1156 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3922 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1160 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1164 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1168 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3949 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1172 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3958 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1176 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1180 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3976 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1184 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3985 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1188 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3994 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1192 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1196 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1200 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1204 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4030 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1208 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1212 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4048 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1216 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4057 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1220 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4066 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1224 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4075 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1228 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1232 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4093 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1236 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4102 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1240 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4111 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1244 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4120 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1248 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4129 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1252 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4138 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1256 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4147 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 233:
#line 1266 "conf_parser.y" /* yacc.c:1652  */
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
#line 4164 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 234:
#line 1278 "conf_parser.y" /* yacc.c:1652  */
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
#line 4212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1341 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4221 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1347 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4230 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1353 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4239 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1359 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4248 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1365 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4257 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1371 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4266 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1377 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4275 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1383 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4284 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1389 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4294 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1396 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4303 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1402 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4312 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1408 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4321 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1414 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4333 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1423 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4345 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1432 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4354 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1439 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4363 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1443 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4372 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1453 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4381 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1459 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4389 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1465 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4398 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1469 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4407 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1473 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4416 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1481 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1486 "conf_parser.y" /* yacc.c:1652  */
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
#line 1499 "conf_parser.y" /* yacc.c:1652  */
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
#line 1516 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4469 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1522 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4478 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1532 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4487 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 298:
#line 1536 "conf_parser.y" /* yacc.c:1652  */
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
#line 1590 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4542 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1596 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4551 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1602 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4560 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 313:
#line 1608 "conf_parser.y" /* yacc.c:1652  */
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
#line 1619 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4583 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1626 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4592 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1630 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4601 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1634 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4610 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1638 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4619 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1642 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4628 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1646 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4637 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1650 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4646 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1654 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4655 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1658 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4664 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1662 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4673 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1668 "conf_parser.y" /* yacc.c:1652  */
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
#line 4690 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1682 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4702 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1691 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4714 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1704 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4726 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 332:
#line 1711 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4737 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1722 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4746 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1728 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 341:
#line 1734 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4764 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 347:
#line 1749 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4779 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 348:
#line 1765 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4795 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 349:
#line 1776 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1791 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 357:
#line 1797 "conf_parser.y" /* yacc.c:1652  */
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
#line 4841 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 358:
#line 1816 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4850 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1823 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1827 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1831 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1835 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1839 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4895 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1843 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4904 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1847 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4913 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1851 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4922 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1855 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1859 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4940 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 372:
#line 1869 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 373:
#line 1878 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4967 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4976 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 380:
#line 1897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4985 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1904 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4994 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1908 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1912 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5012 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1916 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1920 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5030 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1924 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5039 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1928 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5048 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1932 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5057 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1936 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5066 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1940 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5075 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 394:
#line 1950 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5090 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 395:
#line 1960 "conf_parser.y" /* yacc.c:1652  */
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
#line 5161 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5170 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2052 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5179 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5188 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2064 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5197 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2070 "conf_parser.y" /* yacc.c:1652  */
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
#line 5213 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2083 "conf_parser.y" /* yacc.c:1652  */
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
#line 5229 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2096 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5238 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5247 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2108 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5256 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2112 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5265 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2118 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5273 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2124 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5282 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2128 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5291 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2134 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2145 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5314 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2157 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2163 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5346 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2178 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5355 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 436:
#line 2182 "conf_parser.y" /* yacc.c:1652  */
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
#line 5378 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 442:
#line 2205 "conf_parser.y" /* yacc.c:1652  */
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
#line 5401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2225 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5410 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5419 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 445:
#line 2239 "conf_parser.y" /* yacc.c:1652  */
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
#line 5443 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2263 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5452 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 452:
#line 2269 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5461 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 458:
#line 2284 "conf_parser.y" /* yacc.c:1652  */
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
#line 5478 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2301 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5487 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 460:
#line 2305 "conf_parser.y" /* yacc.c:1652  */
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
#line 5507 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2325 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5516 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 467:
#line 2331 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5525 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2392 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5533 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2397 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5541 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2402 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5549 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2407 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5557 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2412 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5565 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2417 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5573 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2422 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5581 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2427 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5589 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2432 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2437 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5605 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2442 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5613 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2447 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5621 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2452 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5629 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2457 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5637 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2462 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5645 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2467 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5653 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2472 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5661 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2477 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5669 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2482 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5677 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2487 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5685 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2492 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2497 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5701 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2502 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5709 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2507 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5717 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2512 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5725 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2517 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2520 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5741 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2525 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5749 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2528 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5757 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2533 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5765 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2538 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5773 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2543 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5781 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2548 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5789 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2553 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5797 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2558 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5805 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2563 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5813 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2568 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2573 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5829 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2578 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2583 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5845 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 557:
#line 2588 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5853 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 558:
#line 2593 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5861 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2599 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5869 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2602 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5877 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2605 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2608 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5893 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2611 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5901 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2614 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2617 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5917 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2620 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5925 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2623 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2626 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5941 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2629 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5949 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2632 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5957 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2635 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5965 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2638 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5973 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2641 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2644 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5989 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2647 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5997 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2650 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6005 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2653 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6013 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2656 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6021 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2659 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6029 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6037 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 584:
#line 2665 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6045 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2670 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2676 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6061 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2679 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6069 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2682 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6077 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2685 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6085 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2688 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6093 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2691 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6101 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2694 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6109 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2697 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6117 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2700 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6125 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2703 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6133 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2706 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6141 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2709 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6149 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2712 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6157 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2715 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6165 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2718 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6173 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2721 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6181 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2724 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6189 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2727 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6197 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2730 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6205 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2733 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6213 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2736 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6221 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2741 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6229 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2746 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 612:
#line 2751 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 613:
#line 2756 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6253 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2785 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6261 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2790 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6269 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2795 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6277 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2800 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6285 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2805 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2810 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2815 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2820 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2825 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6325 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2830 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6333 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2835 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2840 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6349 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 645:
#line 2845 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6357 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 646:
#line 2850 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 647:
#line 2855 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6373 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2878 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6382 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2884 "conf_parser.y" /* yacc.c:1652  */
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
#line 6401 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2900 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6413 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2909 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6422 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 665:
#line 2915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6431 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2921 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6440 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 667:
#line 2927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6452 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 668:
#line 2936 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6461 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 669:
#line 2942 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6470 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6474 "conf_parser.c" /* yacc.c:1652  */
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
