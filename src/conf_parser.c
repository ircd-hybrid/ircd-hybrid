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
    T_BIND = 418,
    T_BOTS = 419,
    T_CALLERID = 420,
    T_CCONN = 421,
    T_COMMAND = 422,
    T_CLUSTER = 423,
    T_DEAF = 424,
    T_DEBUG = 425,
    T_DLINE = 426,
    T_EXTERNAL = 427,
    T_FARCONNECT = 428,
    T_FILE = 429,
    T_FULL = 430,
    T_GLOBOPS = 431,
    T_INVISIBLE = 432,
    T_IPV4 = 433,
    T_IPV6 = 434,
    T_LOCOPS = 435,
    T_LOG = 436,
    T_NCHANGE = 437,
    T_NONONREG = 438,
    T_OPME = 439,
    T_PREPEND = 440,
    T_PSEUDO = 441,
    T_RECVQ = 442,
    T_REJ = 443,
    T_RESTART = 444,
    T_SERVER = 445,
    T_SERVICE = 446,
    T_SERVNOTICE = 447,
    T_SET = 448,
    T_SHARED = 449,
    T_SIZE = 450,
    T_SKILL = 451,
    T_SOFTCALLERID = 452,
    T_SPY = 453,
    T_SSL = 454,
    T_SSL_CIPHER_LIST = 455,
    T_TARGET = 456,
    T_UMODES = 457,
    T_UNAUTH = 458,
    T_UNDLINE = 459,
    T_UNLIMITED = 460,
    T_UNRESV = 461,
    T_UNXLINE = 462,
    T_WALLOP = 463,
    T_WALLOPS = 464,
    T_WEBIRC = 465,
    TBOOL = 466,
    THROTTLE_COUNT = 467,
    THROTTLE_TIME = 468,
    TKLINE_EXPIRE_NOTICES = 469,
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
#define T_BIND 418
#define T_BOTS 419
#define T_CALLERID 420
#define T_CCONN 421
#define T_COMMAND 422
#define T_CLUSTER 423
#define T_DEAF 424
#define T_DEBUG 425
#define T_DLINE 426
#define T_EXTERNAL 427
#define T_FARCONNECT 428
#define T_FILE 429
#define T_FULL 430
#define T_GLOBOPS 431
#define T_INVISIBLE 432
#define T_IPV4 433
#define T_IPV6 434
#define T_LOCOPS 435
#define T_LOG 436
#define T_NCHANGE 437
#define T_NONONREG 438
#define T_OPME 439
#define T_PREPEND 440
#define T_PSEUDO 441
#define T_RECVQ 442
#define T_REJ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_SSL 454
#define T_SSL_CIPHER_LIST 455
#define T_TARGET 456
#define T_UMODES 457
#define T_UNAUTH 458
#define T_UNDLINE 459
#define T_UNLIMITED 460
#define T_UNRESV 461
#define T_UNXLINE 462
#define T_WALLOP 463
#define T_WALLOPS 464
#define T_WEBIRC 465
#define TBOOL 466
#define THROTTLE_COUNT 467
#define THROTTLE_TIME 468
#define TKLINE_EXPIRE_NOTICES 469
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
#define YYLAST   1249

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  236
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  662
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1304

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
    1097,  1101,  1105,  1109,  1113,  1117,  1121,  1128,  1127,  1133,
    1133,  1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,
    1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,  1206,
    1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,  1246,
    1257,  1256,  1313,  1313,  1314,  1315,  1316,  1317,  1318,  1319,
    1320,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1331,  1337,  1343,  1349,  1355,  1361,  1367,  1373,  1379,  1386,
    1392,  1398,  1404,  1413,  1423,  1422,  1428,  1428,  1429,  1433,
    1444,  1443,  1450,  1449,  1454,  1454,  1455,  1459,  1463,  1469,
    1469,  1470,  1470,  1470,  1470,  1470,  1472,  1472,  1474,  1474,
    1476,  1489,  1506,  1512,  1523,  1522,  1569,  1569,  1570,  1571,
    1572,  1573,  1574,  1575,  1576,  1577,  1578,  1580,  1586,  1592,
    1598,  1610,  1609,  1615,  1615,  1616,  1620,  1624,  1628,  1632,
    1636,  1640,  1644,  1648,  1652,  1658,  1672,  1681,  1695,  1694,
    1709,  1709,  1710,  1710,  1710,  1710,  1712,  1718,  1724,  1734,
    1736,  1736,  1737,  1737,  1739,  1756,  1755,  1778,  1778,  1779,
    1779,  1779,  1779,  1781,  1787,  1807,  1806,  1812,  1812,  1813,
    1817,  1821,  1825,  1829,  1833,  1837,  1841,  1845,  1849,  1860,
    1859,  1878,  1878,  1879,  1879,  1879,  1881,  1888,  1887,  1893,
    1893,  1894,  1898,  1902,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1941,  1940,  2017,  2017,  2018,  2019,  2020,  2021,  2022,
    2023,  2024,  2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,
    2034,  2040,  2046,  2052,  2065,  2078,  2084,  2090,  2094,  2101,
    2100,  2105,  2105,  2106,  2110,  2116,  2127,  2133,  2139,  2145,
    2161,  2160,  2184,  2184,  2185,  2185,  2185,  2187,  2207,  2218,
    2217,  2242,  2242,  2243,  2243,  2243,  2245,  2251,  2261,  2263,
    2263,  2264,  2264,  2266,  2284,  2283,  2304,  2304,  2305,  2305,
    2305,  2307,  2313,  2323,  2325,  2325,  2326,  2327,  2328,  2329,
    2330,  2331,  2332,  2333,  2334,  2335,  2336,  2337,  2338,  2339,
    2340,  2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,
    2350,  2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,
    2360,  2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,
    2370,  2371,  2372,  2375,  2380,  2385,  2390,  2395,  2400,  2405,
    2410,  2415,  2420,  2425,  2430,  2435,  2440,  2445,  2450,  2455,
    2460,  2465,  2470,  2475,  2480,  2485,  2490,  2495,  2500,  2505,
    2508,  2513,  2516,  2521,  2526,  2531,  2536,  2541,  2546,  2551,
    2556,  2561,  2566,  2571,  2576,  2582,  2581,  2586,  2586,  2587,
    2590,  2593,  2596,  2599,  2602,  2605,  2608,  2611,  2614,  2617,
    2620,  2623,  2626,  2629,  2632,  2635,  2638,  2641,  2644,  2647,
    2650,  2656,  2655,  2660,  2660,  2661,  2664,  2667,  2670,  2673,
    2676,  2679,  2682,  2685,  2688,  2691,  2694,  2697,  2700,  2703,
    2706,  2709,  2712,  2715,  2718,  2723,  2728,  2733,  2738,  2747,
    2749,  2749,  2750,  2751,  2752,  2753,  2754,  2755,  2756,  2757,
    2758,  2759,  2760,  2761,  2762,  2763,  2764,  2766,  2771,  2776,
    2781,  2786,  2791,  2796,  2801,  2806,  2811,  2816,  2821,  2826,
    2831,  2840,  2842,  2842,  2843,  2844,  2845,  2846,  2847,  2848,
    2849,  2850,  2851,  2852,  2854,  2860,  2876,  2885,  2891,  2897,
    2903,  2912,  2918
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
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BIND", "T_BOTS",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
      59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -882

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-882)))

#define YYTABLE_NINF -126

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -882,   697,  -882,   -68,  -216,  -203,  -882,  -882,  -882,  -200,
    -882,  -191,  -882,  -882,  -882,  -189,  -882,  -882,  -882,  -180,
    -172,  -882,  -163,  -882,  -144,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,    29,   957,  -134,  -128,  -123,    23,  -107,   423,   -86,
     -63,   -49,    91,   -41,   -23,   -20,   408,   519,   -18,    44,
     -17,    13,    -6,  -158,  -151,   -56,    -5,    16,  -882,  -882,
    -882,  -882,  -882,    54,    57,    64,    66,    79,    92,    93,
      94,   101,   107,   112,   113,   123,   130,   219,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,   733,   624,    27,  -882,   131,    32,  -882,
    -882,    19,  -882,   133,   134,   135,   137,   138,   143,   144,
     146,   147,   149,   151,   155,   156,   157,   158,   159,   160,
     165,   166,   167,   168,   170,   173,   174,   175,  -882,  -882,
     177,   178,   179,   181,   183,   184,   186,   188,   190,   194,
     195,   201,   203,   206,   207,   210,   211,   231,   233,    41,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,   467,    14,   319,
      46,   234,   236,    52,  -882,  -882,  -882,    30,   320,    80,
    -882,   240,   242,   243,   244,   245,   246,   247,   248,   250,
     299,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,    83,   251,   252,   254,   255,   256,   257,   259,   261,
     262,   265,   268,   275,   276,   278,   280,    78,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,    48,   285,   284,     2,  -882,  -882,
    -882,   111,   164,  -882,   288,    43,  -882,  -882,     3,  -882,
     192,   274,   308,   295,  -882,   394,   397,   315,   419,   397,
     397,   397,   420,   397,   397,   424,   429,   433,   436,   318,
    -882,   321,   312,   317,   322,  -882,   323,   324,   325,   326,
     329,   330,   331,   332,   334,   336,   337,   150,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   343,   342,   344,   354,   356,   357,
     359,  -882,   362,   363,   365,   366,   368,   369,   370,   272,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,   371,   372,    25,  -882,
    -882,  -882,   430,   379,  -882,  -882,   377,   382,    55,  -882,
    -882,  -882,   401,   397,   508,   397,   397,   406,   510,   397,
     409,   513,   516,   518,   417,   421,   397,   530,   533,   534,
     536,   397,   537,   538,   539,   541,   444,   431,   432,   455,
     397,   397,   456,   464,   465,  -188,  -154,   466,   470,   473,
     474,   562,   397,   475,   397,   397,   480,   570,   463,  -882,
     469,   461,   462,  -882,   471,   481,   482,   484,   487,   269,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     488,   489,    62,  -882,  -882,  -882,   476,   492,   494,  -882,
     495,  -882,    67,  -882,  -882,  -882,  -882,  -882,   577,   585,
     499,  -882,   500,   502,   504,    10,  -882,  -882,  -882,   506,
     507,   509,  -882,   512,   514,   515,   520,  -882,   521,   523,
     223,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,   511,   524,   525,   526,    17,  -882,  -882,  -882,
    -882,   528,   549,   397,   609,   550,   610,   553,   556,   558,
     542,  -882,  -882,   641,   629,   564,   650,   669,   670,   656,
     657,   658,   659,   660,   661,   662,   663,   665,   559,  -882,
     560,   565,  -882,    20,  -882,  -882,  -882,  -882,   580,   563,
    -882,   568,   567,   569,   571,   572,   573,     7,  -882,  -882,
    -882,  -882,  -882,   678,   578,  -882,   579,   574,  -882,   581,
      85,  -882,  -882,  -882,  -882,   589,   590,   591,  -882,   592,
     522,   595,   596,   599,   600,   601,   602,   604,   605,   607,
     615,   616,   617,   618,  -882,  -882,   684,   702,   397,   622,
     741,   397,   742,   397,   728,   748,   749,   750,   397,   751,
     751,   631,  -882,  -882,   739,    28,   740,   653,   743,   744,
     635,   746,   747,   763,   753,   754,   756,   757,   642,  -882,
     758,   759,   643,  -882,   644,  -882,   764,   771,   666,  -882,
     668,   671,   674,   675,   676,   677,   679,   680,   681,   683,
     685,   689,   691,   692,   694,   695,   696,   703,   706,   709,
     711,   713,   714,   716,   719,   805,   720,   721,   722,   724,
     725,   726,   729,   730,   734,   735,   736,   737,   761,   762,
     766,   768,   769,   770,   774,   775,   776,   777,  -882,  -882,
     791,   688,   699,   804,   842,   849,   853,   856,   779,  -882,
     858,   863,   780,  -882,  -882,   866,   871,   778,   887,   782,
    -882,   784,   785,  -882,  -882,   893,   898,   792,  -882,  -882,
     900,   813,   793,   902,   904,   905,   818,   797,   908,   912,
     806,  -882,  -882,   914,   915,   919,   814,  -882,   815,   816,
     817,   819,   820,   821,   822,   823,   824,  -882,   825,   826,
     827,   828,   829,   830,   831,   832,   833,   834,   835,   836,
     837,   838,   839,  -882,  -882,   925,   840,   841,  -882,   844,
    -882,    24,  -882,   947,   949,   952,   953,   847,  -882,   848,
    -882,  -882,   956,   850,   958,   852,  -882,  -882,  -882,  -882,
    -882,   397,   397,   397,   397,   397,   397,   397,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,   854,   855,   857,   -39,   859,   860,   861,
     862,   864,   865,   867,   868,   869,    82,   870,   872,  -882,
     873,   874,   875,   876,   877,   878,   879,     4,   880,   881,
     882,   883,   884,   885,   886,  -882,   888,   889,  -882,  -882,
     890,   891,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -160,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -159,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,   892,   894,   459,   895,   896,
     897,   899,   901,  -882,   903,   906,  -882,   907,   909,   -26,
     910,   846,  -882,  -882,  -882,  -882,   911,   913,  -882,   916,
     917,   503,   918,   920,   921,   922,   765,   923,   924,  -882,
     926,   927,   928,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   929,   198,
    -882,  -882,   930,   931,   932,  -882,    18,  -882,  -882,  -882,
    -882,   933,   936,   937,   938,  -882,  -882,   939,   632,   940,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -150,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   751,   751,   751,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     -55,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,   805,  -882,   720,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   -13,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,    76,  -882,   978,   887,   941,  -882,  -882,
    -882,  -882,  -882,  -882,   942,  -882,   943,   944,  -882,  -882,
     945,   946,  -882,  -882,   948,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,    88,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,   102,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,   121,  -882,  -882,   965,   -46,   951,   955,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,   127,  -882,  -882,  -882,
     -39,  -882,  -882,  -882,  -882,     4,  -882,  -882,  -882,   459,
    -882,   -26,  -882,  -882,  -882,   964,   970,   967,   986,   994,
    1001,  -882,   503,  -882,   765,  -882,   198,   959,   960,   961,
     483,  -882,  -882,   632,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   128,  -882,
    -882,  -882,   483,  -882
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   391,   439,     0,
     454,     0,   294,   430,   270,     0,    96,   148,   328,     0,
       0,   369,     0,   105,     0,   345,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    88,    89,
      91,    90,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   611,   625,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   612,
     613,   623,   624,     0,     0,     0,   452,     0,     0,   450,
     451,     0,   512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   581,   555,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     465,   466,   467,   510,   473,   511,   505,   506,   507,   508,
     504,   477,   468,   469,   470,   471,   472,   474,   475,   476,
     478,   479,   509,   483,   484,   485,   486,   482,   481,   487,
     494,   495,   488,   489,   490,   480,   492,   502,   503,   500,
     501,   493,   491,   498,   499,   496,   497,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     653,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   643,   644,   645,   646,   647,   648,   649,   651,   650,
     652,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    67,
      65,    63,    68,    69,    64,    55,    66,    57,    58,    59,
      60,    61,    62,    56,     0,     0,     0,     0,   120,   121,
     122,     0,     0,   343,     0,     0,   341,   342,     0,    92,
       0,     0,     0,     0,    87,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     610,     0,     0,     0,     0,   264,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,   234,
     237,   239,   240,   241,   242,   243,   244,   245,   235,   236,
     238,   246,   247,   248,     0,     0,     0,     0,     0,     0,
       0,   419,     0,     0,     0,     0,     0,     0,     0,     0,
     394,   395,   396,   397,   398,   399,   400,   402,   401,   404,
     408,   405,   406,   407,   403,   445,     0,     0,     0,   442,
     443,   444,     0,     0,   449,   460,     0,     0,     0,   457,
     458,   459,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   464,
       0,     0,     0,   311,     0,     0,     0,     0,     0,     0,
     297,   298,   299,   300,   305,   301,   302,   303,   304,   436,
       0,     0,     0,   433,   434,   435,     0,     0,     0,   272,
       0,   282,     0,   280,   281,   283,   284,    49,     0,     0,
       0,    45,     0,     0,     0,     0,    99,   100,   101,     0,
       0,     0,   197,     0,     0,     0,     0,   171,     0,     0,
       0,   151,   152,   153,   154,   155,   158,   159,   160,   157,
     156,   161,     0,     0,     0,     0,     0,   331,   332,   333,
     334,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   642,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,     0,   377,     0,   372,   373,   374,   123,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,   108,   109,
     111,   110,   112,     0,     0,   340,     0,     0,   355,     0,
       0,   348,   349,   350,   351,     0,     0,     0,    86,     0,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   609,   249,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   232,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   393,
       0,     0,     0,   441,     0,   448,     0,     0,     0,   456,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   463,   306,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   296,
       0,     0,     0,   432,   285,     0,     0,     0,     0,     0,
     279,     0,     0,    44,   102,     0,     0,     0,    98,   162,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   150,   335,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   641,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,   375,     0,     0,     0,   371,     0,
     118,     0,   113,     0,     0,     0,     0,     0,   107,     0,
     339,   352,     0,     0,     0,     0,   347,    95,    94,    93,
     639,    28,    28,    28,    28,    28,    28,    28,    30,    29,
     640,   627,   628,   629,   630,   631,   632,   633,   634,   637,
     638,   635,   636,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   392,     0,     0,   440,   453,
       0,     0,   455,   525,   529,   513,   514,   544,   517,   607,
     608,   552,   518,   519,   549,   524,   532,   523,   520,   521,
     528,   527,   526,   550,   515,   605,   606,   548,   591,   585,
     601,   586,   587,   588,   596,   604,   589,   598,   602,   592,
     603,   593,   597,   590,   600,   595,   594,   599,     0,   584,
     564,   565,   566,   559,   577,   560,   561,   562,   572,   580,
     563,   574,   578,   568,   579,   569,   573,   567,   576,   571,
     570,   575,     0,   558,   545,   543,   546,   551,   547,   534,
     541,   542,   539,   540,   535,   536,   537,   538,   553,   554,
     522,   531,   530,   533,   516,     0,     0,     0,     0,     0,
       0,     0,     0,   295,     0,     0,   431,     0,     0,     0,
     290,   286,   289,   271,    50,    51,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   149,
       0,     0,     0,   329,   657,   654,   655,   656,   661,   660,
     662,   658,   659,    82,    79,    85,    78,    83,    84,    77,
      81,    80,    72,    71,    76,    73,    75,    74,     0,     0,
     370,   124,     0,     0,     0,   136,     0,   128,   129,   131,
     130,     0,     0,     0,     0,   106,   344,     0,     0,     0,
     346,    31,    32,    33,    34,    35,    36,    37,   259,   260,
     254,   269,   268,     0,   267,   255,   263,   256,   262,   250,
     261,   253,   252,   251,    38,    38,    38,    40,    39,   257,
     258,   414,   417,   418,   428,   425,   411,   426,   423,   424,
       0,   422,   427,   410,   416,   413,   415,   412,   429,   446,
     447,   461,   462,   582,     0,   556,     0,   309,   310,   320,
     316,   317,   319,   324,   321,   322,   315,   323,   318,     0,
     314,   308,   327,   326,   325,   307,   438,   437,   293,   292,
     277,   278,   276,     0,   275,     0,     0,     0,   103,   104,
     170,   167,   217,   229,   204,   213,     0,   202,   207,   223,
       0,   216,   221,   227,   206,   209,   218,   220,   224,   214,
     222,   210,   228,   212,   219,   208,   211,     0,   200,   163,
     165,   168,   169,   180,   181,   182,   175,   193,   176,   177,
     178,   188,   196,   179,   190,   194,   184,   195,   185,   189,
     183,   192,   187,   186,   191,     0,   174,   164,   166,   338,
     336,   337,   376,   381,   387,   390,   383,   389,   384,   388,
     386,   382,   385,     0,   380,   132,     0,     0,     0,     0,
     127,   115,   114,   116,   117,   353,   359,   365,   368,   361,
     367,   362,   366,   364,   360,   363,     0,   358,   354,   265,
       0,    41,    42,    43,   420,     0,   583,   557,   312,     0,
     273,     0,   291,   288,   287,     0,     0,     0,     0,     0,
       0,   198,     0,   172,     0,   378,     0,     0,     0,     0,
       0,   126,   356,     0,   266,   421,   313,   274,   203,   226,
     201,   225,   215,   205,   199,   173,   379,   133,   135,   134,
     146,   145,   141,   143,   147,   144,   140,   142,     0,   139,
     357,   137,     0,   138
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -882,  -882,  -882,  -777,  -304,  -881,  -629,  -882,  -882,   950,
    -882,  -882,  -882,  -882,   934,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  1055,  -882,  -882,  -882,  -882,  -882,  -882,   639,
    -882,  -882,  -882,  -882,  -882,   561,  -882,  -882,  -882,  -882,
    -882,  -882,   935,  -882,  -882,  -882,  -882,    99,  -882,  -882,
    -882,  -882,  -882,  -162,  -882,  -882,  -882,   634,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -122,
    -882,  -882,  -882,  -117,  -882,  -882,  -882,   812,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,   -85,  -882,  -882,  -882,  -882,
    -882,   -90,  -882,   690,  -882,  -882,  -882,    26,  -882,  -882,
    -882,  -882,  -882,   715,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,   -74,  -882,  -882,  -882,  -882,  -882,  -882,   667,  -882,
    -882,  -882,  -882,  -882,   954,  -882,  -882,  -882,  -882,   586,
    -882,  -882,  -882,  -882,  -882,   -91,  -882,  -882,  -882,   623,
    -882,  -882,  -882,  -882,   -79,  -882,  -882,  -882,   843,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
     -57,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,   723,
    -882,  -882,  -882,  -882,  -882,   808,  -882,  -882,  -882,  -882,
    1074,  -882,  -882,  -882,  -882,   796,  -882,  -882,  -882,  -882,
    1028,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,    96,  -882,  -882,  -882,    95,  -882,
    -882,  -882,  -882,  -882,  -882,  1101,  -882,  -882,  -882,  -882,
    -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882,   963,  -882,  -882,  -882,  -882,  -882,  -882,  -882,
    -882,  -882
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   818,   819,  1077,  1078,    27,   223,   224,
     225,   226,    28,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   280,   281,   282,   283,
      29,    77,    78,    79,    80,    81,    30,    63,   495,   496,
     497,   498,    31,    70,   577,   578,   579,   580,   581,   582,
      32,   287,   288,   289,   290,   291,  1036,  1037,  1038,  1039,
    1040,  1218,  1298,  1299,    33,    64,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   747,  1195,  1196,
     521,   742,  1167,  1168,    34,    53,   337,   338,   339,   340,
     341,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   619,  1063,  1064,    35,    61,   481,   727,
    1133,  1134,   482,   483,   484,  1137,   981,   982,   485,   486,
      36,    59,   459,   460,   461,   462,   463,   464,   465,   712,
    1119,  1120,   466,   467,   468,    37,    65,   526,   527,   528,
     529,   530,    38,   295,   296,   297,    39,    72,   590,   591,
     592,   593,   594,   803,  1236,  1237,    40,    68,   563,   564,
     565,   566,   786,  1213,  1214,    41,    54,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   640,  1090,
    1091,   380,   381,   382,   383,   384,    42,    60,   472,   473,
     474,   475,    43,    55,   388,   389,   390,   391,    44,   118,
     119,   120,    45,    57,   398,   399,   400,   401,    46,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   428,   942,   943,   212,   427,   918,   919,   213,
     214,   215,   216,    47,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
      48,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     847,   848,   601,   285,   586,   604,   605,   606,   572,   608,
     609,   492,  1088,  1061,   293,   469,    51,    73,   522,  1032,
     395,   560,  1130,   693,   116,  1032,   385,   694,   385,    52,
      73,   492,    56,   116,  1051,  1052,  1053,  1054,  1055,  1056,
    1057,    58,   122,    62,   293,   285,    74,   123,   124,   560,
     125,   126,    66,   220,    75,   127,   395,   695,   523,    74,
      67,   696,   846,   469,   128,   129,   130,    75,   476,    69,
    1103,  1105,   299,   131,  1104,  1106,   132,   133,   134,   251,
    1239,   522,   300,   135,  1240,  1062,   586,   117,    71,   386,
     493,   386,   220,  1074,  1075,  1076,   117,   524,   113,   661,
     136,   663,   664,   587,   114,   667,   252,   573,   253,   115,
     493,   137,   674,   294,   138,   139,    76,   679,  1033,   396,
     561,   523,   140,   477,  1033,   121,   688,   689,   141,    76,
     142,   478,   143,   479,   144,   254,   145,   146,   702,   470,
     704,   705,   525,   294,   397,   255,   217,   147,   561,   221,
     387,   321,   387,   148,   149,   396,   150,   151,   152,  1268,
     524,   153,    49,    50,  1131,   572,   256,   322,   323,   218,
     257,   222,   324,  1132,   574,  1244,  -125,   301,   258,  1245,
     397,   259,   260,   219,   494,   587,   154,   470,   221,   480,
     846,   227,   575,  1241,  1242,  1243,   155,   156,   157,   158,
     159,   160,   161,  1089,   494,   525,   851,   852,   576,   228,
     222,   261,   229,  1034,   284,   292,   325,  1248,  -125,  1034,
      82,  1249,   588,   286,   499,   589,   298,   262,   302,   760,
     263,   264,   265,   569,   326,   327,   471,  1035,   797,   562,
     328,   737,   500,  1035,   329,    83,    84,   303,   756,  1219,
     330,   787,    85,   162,   163,   164,   652,   165,   166,   331,
     332,   333,   501,   393,   573,   286,   167,   562,   168,  1203,
     450,   334,   448,   354,   584,   355,   487,   356,   266,    86,
      87,    88,    89,   490,   471,   571,   658,   305,   451,   502,
     306,   357,   335,   722,    90,    91,    92,   307,   729,   308,
     230,    93,    94,    95,   588,    96,  1250,   589,   452,   558,
    1251,   358,   309,   542,   835,   595,   805,   838,  1261,   840,
     476,   499,  1262,   503,   845,   310,   311,   312,   359,  1204,
     360,   574,  1263,   231,   313,   453,  1264,   336,   361,   500,
     314,   504,   232,   233,   234,   315,   316,   235,   236,   575,
     362,  1265,   237,   238,   239,  1266,   317,  1272,  1301,   501,
    1205,  1273,  1302,   318,   392,   576,   402,   403,   404,  1206,
     405,   406,   363,   505,   506,   477,   407,   408,  1207,   409,
     410,   631,   411,   478,   412,   479,   502,   454,   413,   414,
     415,   416,   417,   418,   364,   455,   456,   596,   419,   420,
     421,   422,  1208,   423,  1209,  1210,   424,   425,   426,   230,
     429,   430,   431,   365,   432,   457,   433,   434,  1211,   435,
     503,   436,   366,   437,   122,   507,  1212,   438,   439,   123,
     124,   597,   125,   126,   440,   367,   441,   127,   504,   442,
     443,   480,   231,   444,   445,   508,   128,   129,   130,   509,
     319,   232,   233,   234,   750,   131,   235,   236,   132,   133,
     134,   237,   238,   239,   446,   135,   447,   488,   450,   489,
     505,   506,   368,   531,  1109,   532,   533,   534,   535,   536,
     537,   538,   136,   539,   543,   544,   451,   545,   546,   547,
     548,   458,   549,   137,   550,   551,   138,   139,   552,  1110,
     718,   553,   599,   648,   140,   600,   452,  1142,   554,   555,
     141,   556,   142,   557,   143,   567,   144,   568,   145,   146,
     251,   583,   507,  1143,  1144,   598,   602,   603,   607,   147,
     540,  1111,   610,   453,  1145,   148,   149,   611,   150,   151,
     152,   612,   508,   153,   613,   616,   509,   252,   614,   253,
     617,   615,  1290,   654,  1291,   618,   620,   621,   622,   623,
    1112,  1113,   624,   625,   626,   627,  1114,   628,   154,   629,
     630,  1146,  1147,   633,  1148,   634,   254,   635,   155,   156,
     157,   158,   159,   160,   161,   454,   255,   636,  1269,   637,
     638,  1115,   639,   455,   456,   641,   642,  1292,   643,   644,
    1149,   645,   646,   647,   650,   651,  1116,   256,  1150,   655,
     656,   257,   660,   457,  1293,   657,   662,   665,   666,   258,
     668,   669,   259,   260,   670,   354,   671,   355,   672,   356,
     600,  1151,   673,  1152,  1153,   162,   163,   164,   675,   165,
     166,   676,   677,   357,   678,   680,   681,   682,   167,   683,
     168,  1154,   261,  1294,  1295,   684,   811,   812,   813,   814,
     815,   816,   817,   358,   685,   686,   687,   690,   262,  1117,
     701,   263,   264,   265,  1155,   691,   692,   697,   707,  1156,
     359,   698,   360,  1157,   699,   700,   703,  1158,  1118,   458,
     361,   706,  1159,   708,   710,   711,  1160,     2,     3,   709,
     731,     4,   362,  1226,   713,  1296,   724,  1161,   732,  1162,
    1163,  1297,  1164,     5,   714,   715,     6,   716,     7,   266,
     717,   720,   721,  1165,   363,   725,     8,   726,   728,   733,
     734,  1166,   761,   763,   321,   735,   739,   736,     9,   758,
     740,   752,   741,    10,    11,   743,   364,   744,   745,   768,
     322,   323,   769,   746,   748,   324,   749,   753,   754,   755,
     759,   762,    12,  1227,   764,   365,    13,   765,   920,   766,
     921,   922,   767,   771,   366,   770,    14,   772,   773,   774,
     775,   776,   777,   778,   779,   780,   781,   367,   782,   783,
     784,   789,   833,   790,  1228,    15,    16,   792,   785,   325,
     791,   799,   793,  1229,   794,   795,   796,   802,   800,   801,
     834,    17,  1230,  1173,   804,  1174,  1175,   326,   327,   807,
     808,   809,   810,   328,   368,   820,   821,   329,    18,   822,
     823,   824,   825,   330,   826,   827,  1231,   828,  1232,  1233,
      19,    20,   331,   332,   333,   829,   830,   831,   832,   837,
     839,   841,  1234,   898,   334,   836,   842,   843,   844,   846,
    1235,   849,   850,   853,   854,    21,   855,   856,   857,   858,
     859,   860,   865,   868,   869,   335,   861,   862,    22,   863,
     864,   866,   867,    23,   923,   924,   925,   870,    24,   926,
     927,    25,   928,   929,   871,   930,   872,   931,   873,   966,
     932,   874,   933,   934,   875,   876,   877,   878,   935,   879,
     880,   881,   936,   882,   965,   883,   937,   938,   939,   884,
     336,   885,   886,   940,   887,   888,   889,   968,   941,  1176,
    1177,  1178,   967,   890,  1179,  1180,   891,  1181,  1182,   892,
    1183,   893,  1184,   894,   895,  1185,   896,  1186,  1187,   897,
     969,   944,   945,  1188,   946,   947,   948,  1189,    82,   949,
     950,  1190,  1191,  1192,   951,   952,   953,   954,  1193,   899,
     900,   901,   970,  1194,   902,   903,   971,   904,   905,   972,
     906,   974,   907,    83,    84,   908,   975,   909,   910,   977,
      85,   955,   956,   911,   978,   980,   957,   912,   958,   959,
     960,   913,   914,   915,   961,   962,   963,   964,   916,   973,
     976,   979,   983,   917,   984,   985,   986,    86,    87,    88,
      89,   987,   988,   989,   990,   992,   991,   993,   994,   995,
     996,   997,    90,    91,    92,   998,   999,  1000,  1001,    93,
      94,    95,  1002,    96,  1003,  1004,  1005,  1006,  1028,  1007,
    1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,
    1018,  1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,
    1041,  1030,  1042,  1029,  1031,  1043,  1044,  1045,  1046,  1047,
    1136,  1049,  1050,  1048,  1058,  1059,  1252,  1060,  1267,  1065,
    1066,  1067,  1068,  1278,  1069,  1070,  1280,  1071,  1072,  1073,
    1079,  1279,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,
    1092,  1093,  1094,  1095,  1096,  1097,  1098,  1281,  1099,  1100,
    1101,  1102,  1107,  1282,  1108,  1121,  1122,  1123,  1135,  1124,
    1283,  1125,   304,  1126,   738,  1220,  1127,  1128,   798,  1129,
    1303,  1138,  1285,  1139,   751,  1284,  1140,  1141,  1169,   632,
    1170,  1171,  1172,  1197,  1198,  1274,  1199,  1200,  1201,  1202,
    1215,  1277,  1253,  1221,  1216,  1217,  1222,  1223,  1224,  1225,
    1238,  1254,   730,   491,   719,  1276,   806,  1255,  1256,  1257,
    1258,  1259,  1300,  1260,  1270,  1271,   788,  1286,  1275,  1287,
    1288,  1289,   394,   757,   659,   723,   653,   449,   320,  1246,
       0,   559,  1247,   541,     0,     0,     0,     0,     0,     0,
       0,     0,   649,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   570,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   585
};

static const yytype_int16 yycheck[] =
{
     629,   630,   306,     1,     1,   309,   310,   311,     1,   313,
     314,     1,     8,    52,     1,     1,   232,     1,     1,     1,
       1,     1,    48,   211,     1,     1,     1,   215,     1,   232,
       1,     1,   232,     1,   811,   812,   813,   814,   815,   816,
     817,   232,     1,   232,     1,     1,    30,     6,     7,     1,
       9,    10,   232,     1,    38,    14,     1,   211,    41,    30,
     232,   215,   108,     1,    23,    24,    25,    38,     1,   232,
     230,   230,   230,    32,   234,   234,    35,    36,    37,     1,
     230,     1,   233,    42,   234,   124,     1,    64,   232,    64,
      80,    64,     1,    11,    12,    13,    64,    80,   232,   403,
      59,   405,   406,   100,   232,   409,    28,   100,    30,   232,
      80,    70,   416,   100,    73,    74,   100,   421,   100,   100,
     100,    41,    81,    56,   100,   232,   430,   431,    87,   100,
      89,    64,    91,    66,    93,    57,    95,    96,   442,   125,
     444,   445,   125,   100,   125,    67,   232,   106,   100,    97,
     125,     1,   125,   112,   113,   100,   115,   116,   117,   205,
      80,   120,   230,   231,   190,     1,    88,    17,    18,   232,
      92,   119,    22,   199,   167,   230,   174,   233,   100,   234,
     125,   103,   104,   232,   174,   100,   145,   125,    97,   122,
     108,   232,   185,  1074,  1075,  1076,   155,   156,   157,   158,
     159,   160,   161,   199,   174,   125,   178,   179,   201,   232,
     119,   133,   232,   195,   232,   232,    66,   230,   174,   195,
       1,   234,   219,   221,     1,   222,   232,   149,   233,   533,
     152,   153,   154,   231,    84,    85,   222,   219,   231,   219,
      90,   231,    19,   219,    94,    26,    27,   231,   231,   231,
     100,   231,    33,   212,   213,   214,   231,   216,   217,   109,
     110,   111,    39,   231,   100,   221,   225,   219,   227,    71,
       1,   121,   231,     1,   231,     3,   230,     5,   200,    60,
      61,    62,    63,   231,   222,   174,   231,   233,    19,    66,
     233,    19,   142,   231,    75,    76,    77,   233,   231,   233,
       1,    82,    83,    84,   219,    86,   230,   222,    39,   231,
     234,    39,   233,   230,   618,   123,   231,   621,   230,   623,
       1,     1,   234,   100,   628,   233,   233,   233,    56,   131,
      58,   167,   230,    34,   233,    66,   234,   187,    66,    19,
     233,   118,    43,    44,    45,   233,   233,    48,    49,   185,
      78,   230,    53,    54,    55,   234,   233,   230,   230,    39,
     162,   234,   234,   233,   233,   201,   233,   233,   233,   171,
     233,   233,   100,   150,   151,    56,   233,   233,   180,   233,
     233,   231,   233,    64,   233,    66,    66,   118,   233,   233,
     233,   233,   233,   233,   122,   126,   127,   123,   233,   233,
     233,   233,   204,   233,   206,   207,   233,   233,   233,     1,
     233,   233,   233,   141,   233,   146,   233,   233,   220,   233,
     100,   233,   150,   233,     1,   202,   228,   233,   233,     6,
       7,   123,     9,    10,   233,   163,   233,    14,   118,   233,
     233,   122,    34,   233,   233,   222,    23,    24,    25,   226,
     231,    43,    44,    45,   231,    32,    48,    49,    35,    36,
      37,    53,    54,    55,   233,    42,   233,   233,     1,   233,
     150,   151,   200,   233,    15,   233,   233,   233,   233,   233,
     233,   233,    59,   233,   233,   233,    19,   233,   233,   233,
     233,   222,   233,    70,   233,   233,    73,    74,   233,    40,
     231,   233,   108,   231,    81,   108,    39,     4,   233,   233,
      87,   233,    89,   233,    91,   230,    93,   233,    95,    96,
       1,   233,   202,    20,    21,   230,   211,   108,   108,   106,
     231,    72,   108,    66,    31,   112,   113,   108,   115,   116,
     117,   108,   222,   120,   108,   233,   226,    28,   230,    30,
     233,   230,    69,   123,    71,   233,   233,   233,   233,   233,
     101,   102,   233,   233,   233,   233,   107,   233,   145,   233,
     233,    68,    69,   230,    71,   233,    57,   233,   155,   156,
     157,   158,   159,   160,   161,   118,    67,   233,  1217,   233,
     233,   132,   233,   126,   127,   233,   233,   114,   233,   233,
      97,   233,   233,   233,   233,   233,   147,    88,   105,   230,
     233,    92,   211,   146,   131,   233,   108,   211,   108,   100,
     211,   108,   103,   104,   108,     1,   108,     3,   211,     5,
     108,   128,   211,   130,   131,   212,   213,   214,   108,   216,
     217,   108,   108,    19,   108,   108,   108,   108,   225,   108,
     227,   148,   133,   170,   171,   211,   134,   135,   136,   137,
     138,   139,   140,    39,   233,   233,   211,   211,   149,   210,
     108,   152,   153,   154,   171,   211,   211,   211,   108,   176,
      56,   211,    58,   180,   211,   211,   211,   184,   229,   222,
      66,   211,   189,   230,   233,   233,   193,     0,     1,   230,
     123,     4,    78,    71,   233,   222,   230,   204,   123,   206,
     207,   228,   209,    16,   233,   233,    19,   233,    21,   200,
     233,   233,   233,   220,   100,   233,    29,   233,   233,   230,
     230,   228,   123,   123,     1,   233,   230,   233,    41,   211,
     233,   230,   233,    46,    47,   233,   122,   233,   233,   108,
      17,    18,   123,   233,   233,    22,   233,   233,   233,   233,
     211,   211,    65,   131,   211,   141,    69,   211,    48,   211,
      50,    51,   230,   123,   150,   211,    79,   108,   108,   123,
     123,   123,   123,   123,   123,   123,   123,   163,   123,   230,
     230,   211,   108,   230,   162,    98,    99,   230,   233,    66,
     232,   123,   233,   171,   233,   233,   233,   233,   230,   230,
     108,   114,   180,    48,   233,    50,    51,    84,    85,   230,
     230,   230,   230,    90,   200,   230,   230,    94,   131,   230,
     230,   230,   230,   100,   230,   230,   204,   230,   206,   207,
     143,   144,   109,   110,   111,   230,   230,   230,   230,   108,
     108,   123,   220,    48,   121,   233,   108,   108,   108,   108,
     228,   230,   123,   123,   211,   168,   123,   123,   233,   123,
     123,   108,   230,   230,   230,   142,   123,   123,   181,   123,
     123,   123,   123,   186,   164,   165,   166,   123,   191,   169,
     170,   194,   172,   173,   123,   175,   230,   177,   230,   211,
     180,   230,   182,   183,   230,   230,   230,   230,   188,   230,
     230,   230,   192,   230,   123,   230,   196,   197,   198,   230,
     187,   230,   230,   203,   230,   230,   230,   123,   208,   164,
     165,   166,   233,   230,   169,   170,   230,   172,   173,   230,
     175,   230,   177,   230,   230,   180,   230,   182,   183,   230,
     108,   230,   230,   188,   230,   230,   230,   192,     1,   230,
     230,   196,   197,   198,   230,   230,   230,   230,   203,   164,
     165,   166,   123,   208,   169,   170,   123,   172,   173,   123,
     175,   123,   177,    26,    27,   180,   123,   182,   183,   123,
      33,   230,   230,   188,   123,   108,   230,   192,   230,   230,
     230,   196,   197,   198,   230,   230,   230,   230,   203,   230,
     230,   233,   230,   208,   230,   230,   123,    60,    61,    62,
      63,   123,   230,   123,   211,   123,   233,   123,   123,   211,
     233,   123,    75,    76,    77,   123,   230,   123,   123,    82,
      83,    84,   123,    86,   230,   230,   230,   230,   123,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     123,   230,   123,   233,   230,   123,   123,   230,   230,   123,
     234,   123,   230,   233,   230,   230,   108,   230,   123,   230,
     230,   230,   230,   129,   230,   230,   129,   230,   230,   230,
     230,   131,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   131,   230,   230,
     230,   230,   230,   129,   230,   230,   230,   230,   218,   230,
     129,   230,    77,   230,   495,  1036,   230,   230,   577,   230,
    1302,   230,  1264,   230,   510,  1262,   230,   230,   230,   337,
     230,   230,   230,   230,   230,  1240,   230,   230,   230,   230,
     230,  1251,  1136,   230,   233,   233,   230,   230,   230,   230,
     230,   230,   482,   223,   459,  1249,   590,   235,   235,   235,
     235,   235,  1273,   235,   233,   230,   563,  1266,  1245,   230,
     230,   230,   118,   526,   398,   472,   388,   169,    97,  1104,
      -1,   267,  1106,   240,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   369,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   237,     0,     1,     4,    16,    19,    21,    29,    41,
      46,    47,    65,    69,    79,    98,    99,   114,   131,   143,
     144,   168,   181,   186,   191,   194,   238,   243,   248,   266,
     272,   278,   286,   300,   320,   342,   356,   371,   378,   382,
     392,   401,   422,   428,   434,   438,   444,   499,   516,   230,
     231,   232,   232,   321,   402,   429,   232,   439,   232,   357,
     423,   343,   232,   273,   301,   372,   232,   232,   393,   232,
     279,   232,   383,     1,    30,    38,   100,   267,   268,   269,
     270,   271,     1,    26,    27,    33,    60,    61,    62,    63,
      75,    76,    77,    82,    83,    84,    86,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   232,   232,   232,     1,    64,   435,   436,
     437,   232,     1,     6,     7,     9,    10,    14,    23,    24,
      25,    32,    35,    36,    37,    42,    59,    70,    73,    74,
      81,    87,    89,    91,    93,    95,    96,   106,   112,   113,
     115,   116,   117,   120,   145,   155,   156,   157,   158,   159,
     160,   161,   212,   213,   214,   216,   217,   225,   227,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   491,   495,   496,   497,   498,   232,   232,   232,
       1,    97,   119,   244,   245,   246,   247,   232,   232,   232,
       1,    34,    43,    44,    45,    48,    49,    53,    54,    55,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,     1,    28,    30,    57,    67,    88,    92,   100,   103,
     104,   133,   149,   152,   153,   154,   200,   249,   250,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   232,     1,   221,   287,   288,   289,
     290,   291,   232,     1,   100,   379,   380,   381,   232,   230,
     233,   233,   233,   231,   268,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   231,
     501,     1,    17,    18,    22,    66,    84,    85,    90,    94,
     100,   109,   110,   111,   121,   142,   187,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,     1,     3,     5,    19,    39,    56,
      58,    66,    78,   100,   122,   141,   150,   163,   200,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     417,   418,   419,   420,   421,     1,    64,   125,   430,   431,
     432,   433,   233,   231,   436,     1,   100,   125,   440,   441,
     442,   443,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   492,   488,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   231,   446,
       1,    19,    39,    66,   118,   126,   127,   146,   222,   358,
     359,   360,   361,   362,   363,   364,   368,   369,   370,     1,
     125,   222,   424,   425,   426,   427,     1,    56,    64,    66,
     122,   344,   348,   349,   350,   354,   355,   230,   233,   233,
     231,   245,     1,    80,   174,   274,   275,   276,   277,     1,
      19,    39,    66,   100,   118,   150,   151,   202,   222,   226,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   316,     1,    41,    80,   125,   373,   374,   375,   376,
     377,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     231,   518,   230,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   231,   250,
       1,   100,   219,   394,   395,   396,   397,   230,   233,   231,
     288,   174,     1,   100,   167,   185,   201,   280,   281,   282,
     283,   284,   285,   233,   231,   380,     1,   100,   219,   222,
     384,   385,   386,   387,   388,   123,   123,   123,   230,   108,
     108,   240,   211,   108,   240,   240,   240,   108,   240,   240,
     108,   108,   108,   108,   230,   230,   233,   233,   233,   339,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   231,   323,   230,   233,   233,   233,   233,   233,   233,
     414,   233,   233,   233,   233,   233,   233,   233,   231,   404,
     233,   233,   231,   431,   123,   230,   233,   233,   231,   441,
     211,   240,   108,   240,   240,   211,   108,   240,   211,   108,
     108,   108,   211,   211,   240,   108,   108,   108,   108,   240,
     108,   108,   108,   108,   211,   233,   233,   211,   240,   240,
     211,   211,   211,   211,   215,   211,   215,   211,   211,   211,
     211,   108,   240,   211,   240,   240,   211,   108,   230,   230,
     233,   233,   365,   233,   233,   233,   233,   233,   231,   359,
     233,   233,   231,   425,   230,   233,   233,   345,   233,   231,
     349,   123,   123,   230,   230,   233,   233,   231,   275,   230,
     233,   233,   317,   233,   233,   233,   233,   313,   233,   233,
     231,   303,   230,   233,   233,   233,   231,   374,   211,   211,
     240,   123,   211,   123,   211,   211,   211,   230,   108,   123,
     211,   123,   108,   108,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   230,   230,   233,   398,   231,   395,   211,
     230,   232,   230,   233,   233,   233,   233,   231,   281,   123,
     230,   230,   233,   389,   233,   231,   385,   230,   230,   230,
     230,   134,   135,   136,   137,   138,   139,   140,   239,   240,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   108,   108,   240,   233,   108,   240,   108,
     240,   123,   108,   108,   108,   240,   108,   242,   242,   230,
     123,   178,   179,   123,   211,   123,   123,   233,   123,   123,
     108,   123,   123,   123,   123,   230,   123,   123,   230,   230,
     123,   123,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,    48,   164,
     165,   166,   169,   170,   172,   173,   175,   177,   180,   182,
     183,   188,   192,   196,   197,   198,   203,   208,   493,   494,
      48,    50,    51,   164,   165,   166,   169,   170,   172,   173,
     175,   177,   180,   182,   183,   188,   192,   196,   197,   198,
     203,   208,   489,   490,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   123,   211,   233,   123,   108,
     123,   123,   123,   230,   123,   123,   230,   123,   123,   233,
     108,   352,   353,   230,   230,   230,   123,   123,   230,   123,
     211,   233,   123,   123,   123,   211,   233,   123,   123,   230,
     123,   123,   123,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   123,   233,
     230,   230,     1,   100,   195,   219,   292,   293,   294,   295,
     296,   123,   123,   123,   123,   230,   230,   123,   233,   123,
     230,   239,   239,   239,   239,   239,   239,   239,   230,   230,
     230,    52,   124,   340,   341,   230,   230,   230,   230,   230,
     230,   230,   230,   230,    11,    12,    13,   241,   242,   230,
     230,   230,   230,   230,   230,   230,   230,   230,     8,   199,
     415,   416,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   234,   230,   234,   230,   230,    15,
      40,    72,   101,   102,   107,   132,   147,   210,   229,   366,
     367,   230,   230,   230,   230,   230,   230,   230,   230,   230,
      48,   190,   199,   346,   347,   218,   234,   351,   230,   230,
     230,   230,     4,    20,    21,    31,    68,    69,    71,    97,
     105,   128,   130,   131,   148,   171,   176,   180,   184,   189,
     193,   204,   206,   207,   209,   220,   228,   318,   319,   230,
     230,   230,   230,    48,    50,    51,   164,   165,   166,   169,
     170,   172,   173,   175,   177,   180,   182,   183,   188,   192,
     196,   197,   198,   203,   208,   314,   315,   230,   230,   230,
     230,   230,   230,    71,   131,   162,   171,   180,   204,   206,
     207,   220,   228,   399,   400,   230,   233,   233,   297,   231,
     293,   230,   230,   230,   230,   230,    71,   131,   162,   171,
     180,   204,   206,   207,   220,   228,   390,   391,   230,   230,
     234,   241,   241,   241,   230,   234,   494,   490,   230,   234,
     230,   234,   108,   353,   230,   235,   235,   235,   235,   235,
     235,   230,   234,   230,   234,   230,   234,   123,   205,   242,
     233,   230,   230,   234,   341,   416,   367,   347,   129,   131,
     129,   131,   129,   129,   319,   315,   400,   230,   230,   230,
      69,    71,   114,   131,   170,   171,   222,   228,   298,   299,
     391,   230,   234,   299
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
     315,   315,   315,   315,   315,   315,   315,   317,   316,   318,
     318,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     321,   320,   322,   322,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     324,   325,   326,   327,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   339,   338,   340,   340,   341,   341,
     343,   342,   345,   344,   346,   346,   347,   347,   347,   348,
     348,   349,   349,   349,   349,   349,   351,   350,   352,   352,
     353,   353,   354,   355,   357,   356,   358,   358,   359,   359,
     359,   359,   359,   359,   359,   359,   359,   360,   361,   362,
     363,   365,   364,   366,   366,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   368,   369,   370,   372,   371,
     373,   373,   374,   374,   374,   374,   375,   376,   377,   378,
     379,   379,   380,   380,   381,   383,   382,   384,   384,   385,
     385,   385,   385,   386,   387,   389,   388,   390,   390,   391,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   393,
     392,   394,   394,   395,   395,   395,   396,   398,   397,   399,
     399,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   402,   401,   403,   403,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   412,   414,
     413,   415,   415,   416,   416,   417,   418,   419,   420,   421,
     423,   422,   424,   424,   425,   425,   425,   426,   427,   429,
     428,   430,   430,   431,   431,   431,   432,   433,   434,   435,
     435,   436,   436,   437,   439,   438,   440,   440,   441,   441,
     441,   442,   443,   444,   445,   445,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     473,   474,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   488,   487,   489,   489,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   492,   491,   493,   493,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   495,   496,   497,   498,   499,
     500,   500,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   517,   518,   518,   518,   518,   518,   518,
     518,   518,   518,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527
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
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       0,     6,     0,     5,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     2,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     4,     4,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2850 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2856 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2862 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 408 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2868 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 409 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2874 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2880 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2886 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2892 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2898 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 416 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2904 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 417 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2910 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 418 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2916 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 419 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2922 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 420 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2928 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 433 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2937 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 439 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2946 "conf_parser.c" /* yacc.c:1652  */
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
#line 2958 "conf_parser.c" /* yacc.c:1652  */
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
#line 2970 "conf_parser.c" /* yacc.c:1652  */
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
#line 2982 "conf_parser.c" /* yacc.c:1652  */
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
#line 2994 "conf_parser.c" /* yacc.c:1652  */
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
#line 3006 "conf_parser.c" /* yacc.c:1652  */
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
#line 3018 "conf_parser.c" /* yacc.c:1652  */
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
#line 3036 "conf_parser.c" /* yacc.c:1652  */
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
#line 3054 "conf_parser.c" /* yacc.c:1652  */
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
#line 3067 "conf_parser.c" /* yacc.c:1652  */
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
#line 3084 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 81:
#line 578 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3096 "conf_parser.c" /* yacc.c:1652  */
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
#line 3122 "conf_parser.c" /* yacc.c:1652  */
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
#line 3148 "conf_parser.c" /* yacc.c:1652  */
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
#line 3174 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 85:
#line 656 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3183 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 93:
#line 674 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3195 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 94:
#line 683 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3207 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 692 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3219 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 705 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3228 "conf_parser.c" /* yacc.c:1652  */
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
#line 3245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 103:
#line 726 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 104:
#line 732 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 742 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3272 "conf_parser.c" /* yacc.c:1652  */
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
#line 3290 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 114:
#line 764 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 115:
#line 770 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3308 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 776 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3317 "conf_parser.c" /* yacc.c:1652  */
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
#line 3338 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 124:
#line 810 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3347 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 125:
#line 816 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3356 "conf_parser.c" /* yacc.c:1652  */
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
#line 3369 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 133:
#line 836 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3380 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 134:
#line 844 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3388 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 847 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3396 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 852 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3405 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 140:
#line 859 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3414 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 141:
#line 863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3423 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3432 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3441 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 879 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3459 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 883 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3468 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 887 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3477 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 897 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3489 "conf_parser.c" /* yacc.c:1652  */
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
#line 3548 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 163:
#line 973 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3557 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 164:
#line 979 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3566 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 985 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3575 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 991 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3584 "conf_parser.c" /* yacc.c:1652  */
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
#line 3598 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 1008 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3607 "conf_parser.c" /* yacc.c:1652  */
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
#line 3621 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1025 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3630 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 171:
#line 1031 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3639 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 175:
#line 1038 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3648 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 176:
#line 1042 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3657 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3666 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3675 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1054 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3684 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3693 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3702 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1066 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3711 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1070 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3720 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1074 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3729 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1078 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3738 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1086 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3756 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3765 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3774 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3783 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3792 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1128 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 201:
#line 1135 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 202:
#line 1139 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 203:
#line 1143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1147 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1159 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1163 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3918 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1167 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3936 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1183 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 3963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1187 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 3972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1191 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 3981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1195 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 3990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1199 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 3999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1203 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1207 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1215 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4044 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4053 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1227 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4062 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1231 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4071 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4080 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1239 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4089 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1243 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4098 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1247 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4107 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1257 "conf_parser.y" /* yacc.c:1652  */
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
#line 4124 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1269 "conf_parser.y" /* yacc.c:1652  */
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
#line 4172 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 250:
#line 1332 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4181 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 251:
#line 1338 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4190 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 252:
#line 1344 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4199 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1350 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4208 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1356 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4217 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1362 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4226 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1368 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4235 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1374 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4244 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1380 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1387 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1393 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4272 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1399 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4281 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1405 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4293 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1414 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1423 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4314 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 268:
#line 1430 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 269:
#line 1434 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4332 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 270:
#line 1444 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4341 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1450 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4349 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 276:
#line 1456 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4358 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 277:
#line 1460 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4367 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 278:
#line 1464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4376 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 286:
#line 1472 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4382 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 290:
#line 1477 "conf_parser.y" /* yacc.c:1652  */
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
#line 4400 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 291:
#line 1490 "conf_parser.y" /* yacc.c:1652  */
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
#line 4420 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 292:
#line 1507 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4429 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 293:
#line 1513 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4438 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 294:
#line 1523 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4447 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1527 "conf_parser.y" /* yacc.c:1652  */
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
#line 4493 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 307:
#line 1581 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4502 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 308:
#line 1587 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4511 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 309:
#line 1593 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4520 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1599 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4534 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1610 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4543 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 315:
#line 1617 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4552 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 316:
#line 1621 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4561 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 317:
#line 1625 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4570 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1629 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1633 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4588 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1637 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4597 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1641 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4606 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1645 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4615 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1649 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4624 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1653 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4633 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1659 "conf_parser.y" /* yacc.c:1652  */
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
#line 4650 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1673 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4662 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1682 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4674 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 328:
#line 1695 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4686 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1702 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4697 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 336:
#line 1713 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4706 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 337:
#line 1719 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4715 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 338:
#line 1725 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 344:
#line 1740 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4739 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 345:
#line 1756 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 346:
#line 1767 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4770 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 353:
#line 1782 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4779 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 354:
#line 1788 "conf_parser.y" /* yacc.c:1652  */
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
#line 4801 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 355:
#line 1807 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4810 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 359:
#line 1814 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 360:
#line 1818 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4828 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 361:
#line 1822 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4837 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1826 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4846 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1830 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4855 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1834 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4864 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1842 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4882 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1846 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1850 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4900 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1860 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 4914 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1869 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 4927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 376:
#line 1882 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4936 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 377:
#line 1888 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 381:
#line 1895 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 382:
#line 1899 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 4963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 383:
#line 1903 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 4972 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 4981 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 4990 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 4999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5008 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1923 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5017 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5026 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1931 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1941 "conf_parser.y" /* yacc.c:1652  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5049 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1950 "conf_parser.y" /* yacc.c:1652  */
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
      conf->bind->ss.ss_family = res->ai_family;
      conf->bind->ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5120 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 410:
#line 2035 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5129 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 411:
#line 2041 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5138 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 412:
#line 2047 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5147 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 413:
#line 2053 "conf_parser.y" /* yacc.c:1652  */
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
#line 5163 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2066 "conf_parser.y" /* yacc.c:1652  */
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
#line 5179 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2079 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5188 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2085 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5197 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2091 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5206 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 418:
#line 2095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5215 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 419:
#line 2101 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5223 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2107 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5232 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5241 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 425:
#line 2117 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5255 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 426:
#line 2128 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5264 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 427:
#line 2134 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5273 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2140 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5282 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2146 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5296 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 430:
#line 2161 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5305 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2165 "conf_parser.y" /* yacc.c:1652  */
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
#line 5328 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 437:
#line 2188 "conf_parser.y" /* yacc.c:1652  */
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
#line 5351 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 438:
#line 2208 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5360 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 439:
#line 2218 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5369 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 440:
#line 2222 "conf_parser.y" /* yacc.c:1652  */
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
#line 5393 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 446:
#line 2246 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5402 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 447:
#line 2252 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5411 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 453:
#line 2267 "conf_parser.y" /* yacc.c:1652  */
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
#line 5428 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 454:
#line 2284 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5437 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 455:
#line 2288 "conf_parser.y" /* yacc.c:1652  */
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
#line 5457 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 461:
#line 2308 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5466 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 462:
#line 2314 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5475 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 513:
#line 2376 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5483 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 514:
#line 2381 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5491 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 515:
#line 2386 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5499 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 516:
#line 2391 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5507 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2396 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5515 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2401 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5523 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2406 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5531 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2411 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5539 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2416 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5547 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2421 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5555 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2426 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5563 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2431 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5571 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2436 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2441 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5587 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2446 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5595 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2451 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5603 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2456 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5611 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2461 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5619 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2466 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5627 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2471 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5635 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2476 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5643 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2481 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5651 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2486 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5659 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2491 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5667 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2496 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5675 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2501 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5683 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2506 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5691 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2509 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5699 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2514 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5707 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2517 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5715 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2522 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5723 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2527 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5731 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2532 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5739 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2537 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2542 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2547 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5763 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2552 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5771 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2557 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5779 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2562 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5787 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2567 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5795 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2572 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5803 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2577 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5811 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2582 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 559:
#line 2588 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5827 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 560:
#line 2591 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5835 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 561:
#line 2594 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5843 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2597 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5851 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2600 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2603 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2606 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5875 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2609 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5883 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2612 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2615 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2618 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2621 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2624 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5923 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2627 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2630 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5939 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2633 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5947 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2636 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5955 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2639 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 5963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2642 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 5971 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2645 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 5979 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2648 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 5987 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2651 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 5995 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2656 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2662 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6011 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 586:
#line 2665 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6019 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 587:
#line 2668 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6027 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 588:
#line 2671 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2674 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6043 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2677 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6051 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2680 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6059 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2683 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6067 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2686 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6075 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2689 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6083 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2692 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6091 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2695 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6099 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2698 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6107 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2701 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6115 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2704 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6123 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2707 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6131 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2710 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6139 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2713 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6147 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2716 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6155 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2719 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6163 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2724 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6171 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2729 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6179 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2734 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6187 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2739 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6195 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 627:
#line 2767 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6203 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 628:
#line 2772 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6211 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 629:
#line 2777 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6219 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 630:
#line 2782 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6227 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 631:
#line 2787 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6235 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2792 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2797 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2802 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6259 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2807 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6267 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2812 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6275 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2817 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2822 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6291 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2827 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2832 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6307 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 654:
#line 2855 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6316 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 655:
#line 2861 "conf_parser.y" /* yacc.c:1652  */
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
#line 6335 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 656:
#line 2877 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6347 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 657:
#line 2886 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6356 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 658:
#line 2892 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6365 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2898 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6374 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 660:
#line 2904 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6386 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 661:
#line 2913 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6395 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6404 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6408 "conf_parser.c" /* yacc.c:1652  */
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
