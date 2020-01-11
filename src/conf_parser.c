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
    TLS_CIPHER_SUITES = 471,
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
#define TLS_CIPHER_SUITES 471
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
#define YYLAST   1333

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
  "TLS_CIPHER_SUITES", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "WHOWAS_HISTORY_LENGTH", "XLINE",
  "XLINE_EXEMPT", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept",
  "conf", "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_tls_cipher_suites",
  "serverinfo_ssl_message_digest_algorithm",
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
     485,   486,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF -783

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-783)))

#define YYTABLE_NINF -128

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -783,   708,  -783,  -133,  -221,  -200,  -783,  -783,  -783,  -196,
    -783,  -190,  -783,  -783,  -783,  -188,  -783,  -783,  -783,  -173,
    -171,  -783,  -161,  -783,  -150,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,   279,   954,  -144,  -141,  -114,    23,   -99,   388,   -89,
     -69,   -63,    91,   -51,   -38,   -37,   534,   542,   -20,     3,
     -14,    61,    -7,    35,  -199,    16,    31,     7,  -783,  -783,
    -783,  -783,  -783,    46,    48,    52,    60,    79,    85,    87,
      96,    97,    99,   100,   101,   106,   112,   160,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,   650,   647,    53,  -783,   114,    29,  -783,
    -783,    22,  -783,   115,   116,   118,   119,   127,   128,   130,
     132,   133,   135,   136,   137,   144,   146,   147,   148,   152,
     153,   156,   157,   161,   165,   169,   171,   172,  -783,  -783,
     174,   179,   181,   184,   186,   187,   191,   193,   194,   199,
     200,   210,   216,   219,   221,   225,   226,   229,    42,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,   414,    25,   309,    38,   230,
     231,    24,  -783,  -783,  -783,    34,   336,   304,  -783,   232,
     233,   234,   236,   237,   238,   239,   240,   244,    26,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,   178,
     248,   254,   255,   256,   258,   259,   261,   263,   264,   268,
     272,   273,   276,   277,   280,   282,   124,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,    10,   287,   288,    19,  -783,  -783,
    -783,   345,   175,  -783,   290,    32,  -783,  -783,   109,  -783,
     398,   402,   404,   297,  -783,   421,   422,   320,   427,   422,
     422,   422,   428,   422,   422,   429,   431,   442,   443,   321,
    -783,   322,   323,   324,   331,  -783,   332,   334,   338,   339,
     341,   342,   347,   350,   351,   357,   358,   217,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,   325,   360,   361,   362,   363,   368,
     369,  -783,   370,   373,   374,   376,   378,   379,   381,   384,
     285,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,   385,   391,
      21,  -783,  -783,  -783,   432,   396,  -783,  -783,   394,   397,
      49,  -783,  -783,  -783,   359,   422,   514,   422,   422,   425,
     524,   422,   433,   525,   530,   531,   437,   441,   422,   532,
     535,   546,   549,   422,   550,   552,   555,   560,   461,   440,
     445,   469,   422,   422,   470,   472,   476,  -198,  -170,   477,
     478,   479,   481,   585,   422,   422,   422,   487,   593,   473,
    -783,   475,   483,   484,  -783,   485,   486,   490,   495,   496,
     166,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,   497,   498,    82,  -783,  -783,  -783,   502,   503,   504,
    -783,   505,  -783,    30,  -783,  -783,  -783,  -783,  -783,   586,
     587,   510,  -783,   512,   511,   515,    15,  -783,  -783,  -783,
     520,   519,   528,  -783,   533,   536,   538,   540,  -783,   541,
     551,   145,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,   527,   556,   557,   559,    17,  -783,  -783,
    -783,  -783,   501,   516,   422,   592,   553,   598,   565,   575,
     578,   537,  -783,  -783,   638,   671,   584,   673,   690,   691,
     677,   678,   680,   681,   682,   685,   692,   693,   694,   695,
     582,  -783,   583,   589,  -783,    90,  -783,  -783,  -783,  -783,
     608,   590,  -783,   591,   594,   595,   596,   597,   599,   105,
    -783,  -783,  -783,  -783,  -783,   697,   601,  -783,   603,   602,
    -783,   604,    68,  -783,  -783,  -783,  -783,   609,   610,   612,
    -783,   613,   644,   614,   615,   617,   619,   622,   623,   624,
     625,   626,   627,   628,   629,   631,  -783,  -783,   718,   719,
     422,   630,   720,   422,   727,   422,   740,   757,   758,   759,
     422,   760,   760,   639,  -783,  -783,   746,     1,   748,   661,
     750,   751,   641,   754,   755,   774,   763,   768,   770,   773,
     422,   652,  -783,   777,   778,   674,  -783,   675,  -783,   781,
     785,   679,  -783,   683,   684,   686,   688,   689,   698,   701,
     704,   706,   709,   711,   714,   716,   717,   721,   724,   725,
     729,   730,   731,   732,   737,   741,   744,   756,   801,   715,
     764,   765,   769,   771,   772,   775,   776,   779,   780,   782,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
    -783,  -783,   786,   705,   687,   799,   816,   805,   823,   827,
     797,  -783,   828,   854,   802,  -783,  -783,   859,   862,   767,
     831,   803,  -783,   804,   808,  -783,  -783,   865,   867,   810,
    -783,  -783,   868,   783,   798,   869,   882,   885,   832,   811,
     889,   919,   813,  -783,  -783,   923,   924,   925,   818,  -783,
     819,   820,   821,   822,   824,   825,   826,   829,   830,  -783,
     833,   834,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,   847,   848,  -783,  -783,   931,   849,
     850,  -783,   851,  -783,    11,  -783,   935,   936,   939,   940,
     853,  -783,   855,  -783,  -783,   957,   856,   962,   857,  -783,
    -783,  -783,  -783,  -783,   422,   422,   422,   422,   422,   422,
     422,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,   858,   860,   861,   -36,
     863,   864,   866,   870,   871,   872,   873,   874,   875,    28,
     876,   877,  -783,   878,   879,   880,   881,   883,   884,   886,
      -5,   887,   888,   890,   891,   892,   893,   894,   895,  -783,
     896,   897,  -783,  -783,   898,   899,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -204,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -179,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
     900,   901,   344,   902,   903,   904,   905,   906,  -783,   907,
     908,  -783,   909,   910,   -34,   926,   852,  -783,  -783,  -783,
    -783,   911,   912,  -783,   913,   915,   493,   916,   917,   918,
     920,   761,   921,   922,  -783,   927,   928,   929,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,   930,   449,  -783,  -783,   932,   933,
     934,  -783,    20,  -783,  -783,  -783,  -783,   938,   941,   942,
     943,  -783,  -783,   944,   455,   945,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -177,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
     760,   760,   760,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -168,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,   801,  -783,   715,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -127,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -105,  -783,   985,   831,   946,  -783,  -783,  -783,  -783,  -783,
    -783,   914,  -783,   947,   948,  -783,  -783,   949,   950,  -783,
    -783,   951,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,   -64,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,   -62,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,   -59,  -783,  -783,   973,   -80,   937,   958,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,   -17,  -783,  -783,  -783,   -36,  -783,
    -783,  -783,  -783,    -5,  -783,  -783,  -783,   344,  -783,   -34,
    -783,  -783,  -783,   969,   968,   971,   982,   987,   991,  -783,
     493,  -783,   761,  -783,   449,   959,   960,   961,   286,  -783,
    -783,   455,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,    36,  -783,  -783,  -783,
     286,  -783
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
       0,     0,     0,   200,     0,     0,     0,     0,   173,     0,
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
      87,    80,    85,    86,    79,    83,    82,    73,    72,    78,
      74,    77,    75,    76,     0,     0,   373,   126,     0,     0,
       0,   138,     0,   130,   131,   133,   132,     0,     0,     0,
       0,   108,   347,     0,     0,     0,   349,    31,    32,    33,
      34,    35,    36,    37,   262,   263,   257,   272,   271,     0,
     270,   258,   266,   259,   265,   253,   264,   256,   255,   254,
      38,    38,    38,    40,    39,   260,   261,   419,   422,   423,
     433,   430,   415,   431,   428,   429,     0,   427,   432,   414,
     421,   418,   420,   417,   434,   416,   451,   452,   466,   467,
     586,     0,   559,     0,   312,   313,   323,   319,   320,   322,
     327,   324,   325,   318,   326,   321,     0,   317,   311,   330,
     329,   328,   310,   443,   442,   296,   295,   280,   281,   279,
       0,   278,     0,     0,     0,   105,   106,   172,   169,   220,
     232,   207,   216,     0,   205,   210,   226,     0,   219,   224,
     230,   209,   212,   221,   223,   227,   217,   225,   213,   231,
     215,   222,   211,   214,     0,   203,   165,   167,   170,   171,
     199,   182,   183,   184,   177,   195,   178,   179,   180,   190,
     198,   181,   192,   196,   186,   197,   187,   191,   185,   194,
     189,   188,   193,     0,   176,   166,   168,   341,   339,   340,
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
    -783,  -783,  -783,  -376,  -304,  -782,  -631,  -783,  -783,   974,
    -783,  -783,  -783,  -783,   952,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  1078,  -783,  -783,  -783,  -783,  -783,  -783,
     660,  -783,  -783,  -783,  -783,  -783,   579,  -783,  -783,  -783,
    -783,  -783,  -783,   953,  -783,  -783,  -783,  -783,   121,  -783,
    -783,  -783,  -783,  -783,  -153,  -783,  -783,  -783,   654,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -106,  -783,  -783,  -783,  -103,  -783,  -783,  -783,   955,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,   -77,  -783,  -783,  -783,
    -783,  -783,   -79,  -783,   696,  -783,  -783,  -783,    39,  -783,
    -783,  -783,  -783,  -783,   723,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,   -76,  -783,  -783,  -783,  -783,  -783,  -783,   662,
    -783,  -783,  -783,  -783,  -783,   956,  -783,  -783,  -783,  -783,
     605,  -783,  -783,  -783,  -783,  -783,   -87,  -783,  -783,  -783,
     633,  -783,  -783,  -783,  -783,   -78,  -783,  -783,  -783,   963,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,   -54,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,   728,  -783,  -783,  -783,  -783,  -783,   812,  -783,  -783,
    -783,  -783,  1082,  -783,  -783,  -783,  -783,   806,  -783,  -783,
    -783,  -783,  1035,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,    92,  -783,  -783,  -783,    93,
    -783,  -783,  -783,  -783,  -783,  -783,  1110,  -783,  -783,  -783,
    -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783,   970,  -783,  -783,  -783,  -783,  -783,  -783,
    -783,  -783,  -783
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
     514,   515,   516,   517,   518,   519,   520,   521,   749,  1203,
    1204,   522,   744,  1174,  1175,    34,    53,   337,   338,   339,
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
     850,   851,   603,  1094,   285,   606,   607,   608,    73,   610,
     611,   562,  1038,    51,   696,  1137,   493,  1067,   523,   697,
     285,  1038,   387,   397,   116,   218,   470,   228,  1110,   849,
     116,   477,  1111,   293,    52,   493,   300,    74,    56,  1080,
    1081,  1082,   698,   122,    58,    75,    62,   699,   123,   124,
     397,   125,   126,  1112,   387,  1247,   127,  1113,   524,  1248,
     229,    66,   293,    67,  1252,   128,   129,   130,  1253,   588,
     230,   231,   232,    69,   131,   233,   234,   132,   133,   134,
     235,   236,   237,   470,    71,   135,   388,   478,   117,  1068,
     113,   562,   218,   114,   117,   479,   494,   480,   525,    49,
      50,   664,   136,   666,   667,  1256,   574,   670,    76,  1257,
     588,   563,  1039,   137,   677,   494,   138,   139,   388,   682,
     115,  1039,   219,   398,   140,   249,  1276,  1258,   691,   692,
     141,  1259,   142,   294,   143,   121,   144,   849,   145,   146,
     705,   706,   707,   526,   220,   215,   500,   389,   399,   147,
     398,   471,   250,   481,   251,   148,   149,  1138,   150,   151,
     152,    82,   294,   153,   501,   216,  1139,   451,  1269,   589,
    1271,   217,  1270,  1273,  1272,   399,   574,  1274,  -127,   389,
     854,   855,   252,   225,   502,   452,    83,    84,   154,   219,
     495,   563,   253,    85,  -127,  1095,   226,   227,   155,   156,
     157,   158,   159,   160,   161,   453,   575,  1040,   471,   495,
     589,   220,   503,   254,   284,  1280,  1040,   255,   321,  1281,
     292,    86,    87,    88,    89,   256,   286,   298,   257,   258,
     762,   564,  1041,   454,   322,   323,    90,    91,    92,   324,
     303,  1041,   286,    93,    94,    95,   504,    96,   739,   472,
     758,   301,   571,  1227,   655,   162,   163,   491,   259,   541,
     164,   165,   395,   731,   505,   586,   302,   299,  1309,   166,
     488,   167,  1310,   576,   260,   449,   575,   261,   262,   263,
      73,   305,   661,   306,   325,   455,   354,   307,   355,   590,
     356,   577,   591,   456,   457,   308,   506,   507,  1249,  1250,
    1251,   808,   326,   327,   357,   523,   472,   578,   328,    74,
     477,   564,   329,   458,   309,   724,   838,    75,   330,   841,
     310,   843,   311,   790,   358,   264,   848,   331,   332,   333,
     590,   312,   313,   591,   314,   315,   316,   500,   800,   334,
     265,   317,   359,   576,   360,   524,   868,   318,   508,   394,
     404,   405,   361,   406,   407,   501,  1298,   560,  1299,  1116,
     335,   577,   408,   409,   362,   410,   478,   411,   412,   509,
     413,   414,   415,   510,   479,   502,   480,   578,   752,   416,
      76,   417,   418,   419,  1117,   525,   363,   420,   421,   122,
     459,   422,   423,   319,   123,   124,   424,   125,   126,   720,
     425,  1300,   127,   503,   426,   336,   427,   428,   364,   431,
     543,   128,   129,   130,   432,   451,   433,  1118,  1301,   434,
     131,   435,   436,   132,   133,   134,   437,   365,   438,   439,
     526,   135,   481,   452,   440,   441,   366,   504,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,   442,  1119,  1120,   136,   367,
     633,   443,  1121,   453,   444,   505,   445,  1302,  1303,   137,
     446,   447,   138,   139,   448,   489,   490,   532,   533,   534,
     140,   535,   536,   537,   538,   539,   141,  1122,   142,   540,
     143,   454,   144,   544,   145,   146,   368,   506,   507,   545,
     546,   547,  1123,   548,   549,   147,   550,  1149,   551,   552,
     369,   148,   149,   553,   150,   151,   152,   554,   555,   153,
    1304,   556,   557,  1150,  1151,   558,  1305,   559,   651,   569,
     573,  1211,   597,   570,  1152,   585,   598,  1234,   599,   600,
     601,   602,   604,   455,   154,   228,   605,   609,   612,   508,
     613,   456,   457,   249,   155,   156,   157,   158,   159,   160,
     161,   614,   615,   616,   617,  1124,   657,   635,   618,   619,
     509,   458,  1153,  1154,   510,  1155,   620,   622,   229,   623,
     250,   663,   251,   624,   625,  1125,   626,   627,   230,   231,
     232,  1212,   628,   233,   234,   629,   630,  1235,   235,   236,
     237,  1156,   631,   632,  1277,   636,   637,   638,   639,  1157,
     252,   162,   163,   640,   641,   643,   164,   165,   644,   645,
     253,   646,  1213,   647,   648,   166,   649,   167,  1236,   650,
     653,  1214,  1158,   665,  1159,  1160,   654,  1237,   658,   659,
    1215,   254,   660,   669,   672,   255,  1238,   668,   459,   673,
     674,   678,  1161,   256,   679,   671,   257,   258,   354,   675,
     355,   321,   356,   676,  1216,   680,  1217,  1218,   681,   683,
    1239,   684,  1240,  1241,   685,  1162,   357,   322,   323,   686,
    1163,  1219,   324,   687,  1164,   688,   259,  1242,  1165,  1220,
     689,   690,   693,  1166,   694,  1243,   358,  1167,   695,   700,
     701,   702,   260,   703,   704,   261,   262,   263,  1168,   708,
    1169,  1170,   709,  1171,   359,   710,   360,   711,     2,     3,
     733,   734,     4,   760,   361,  1172,   763,   325,   712,   713,
     715,   716,   765,  1173,     5,   717,   362,     6,   761,     7,
     718,   719,   722,   723,   726,   326,   327,     8,   727,   728,
     730,   328,   735,   264,   736,   329,   737,   770,   363,     9,
     738,   330,   741,   602,   742,    10,    11,   925,   265,   754,
     331,   332,   333,   743,   926,   764,   927,   928,   745,   769,
     364,   746,   334,   747,    12,   748,   750,   766,    13,   814,
     815,   816,   817,   818,   819,   820,   751,   767,    14,   365,
     768,   755,   756,   335,   757,   771,   772,   773,   366,   774,
     775,   776,   777,  1180,   778,   779,   780,    15,    16,   781,
    1181,   367,  1182,  1183,   786,   787,   782,   783,   784,   785,
     792,   802,   793,    17,   788,   794,   795,   836,   837,   840,
     796,   797,   798,   803,   799,   804,   842,   805,   336,   807,
      18,   810,   811,   902,   812,   813,   823,   824,   368,   825,
     903,   826,    19,    20,   827,   828,   829,   830,   831,   832,
     833,   834,   369,   835,   844,   839,   845,   846,   847,   849,
     853,   852,   856,   857,   858,   859,   860,    21,   861,   862,
     929,   930,   931,   863,   869,   932,   933,   864,   934,   935,
      22,   936,   865,   937,   866,    23,   938,   867,   939,   940,
      24,   870,   871,    25,   941,   874,   872,   873,   942,   875,
     970,   876,   943,   944,   945,   877,   878,   971,   879,   946,
     880,   881,   972,   973,   947,   974,  1184,  1185,  1186,   975,
     882,  1187,  1188,   883,  1189,  1190,   884,  1191,   885,  1192,
     985,   886,  1193,   887,  1194,  1195,   888,   976,   889,   890,
    1196,   977,   979,   891,  1197,    82,   892,   893,  1198,  1199,
    1200,   894,   895,   896,   897,  1201,   904,   905,   906,   898,
    1202,   907,   908,   899,   909,   910,   900,   911,   980,   912,
      83,    84,   913,   982,   914,   915,   983,    85,   901,   991,
     916,   992,   994,   997,   917,   995,   950,   951,   918,   919,
     920,   952,   984,   953,   954,   921,   998,   955,   956,   999,
     922,   957,   958,  1002,   959,    86,    87,    88,    89,   960,
     961,   962,   963,   964,   965,   966,   967,   968,   969,   978,
      90,    91,    92,   996,   981,   988,   989,    93,    94,    95,
     990,    96,   993,  1003,  1000,  1004,  1001,  1005,  1006,  1007,
    1008,  1009,  1010,  1011,  1012,  1034,  1013,  1014,  1015,  1047,
    1048,  1016,  1017,  1049,  1050,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,
    1033,  1053,  1036,  1037,  1035,  1051,  1055,  1052,  1143,  1056,
    1064,  1054,  1065,  1066,  1260,  1071,  1072,  1275,  1073,  1286,
    1287,  1288,  1074,  1075,  1076,  1077,  1078,  1079,  1085,  1086,
    1087,  1088,  1089,  1090,  1289,  1091,  1092,  1290,  1093,  1098,
    1099,  1291,  1100,  1101,  1102,  1103,  1104,  1105,  1106,  1107,
    1108,  1109,  1114,  1115,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1145,  1146,  1147,  1142,  1148,  1176,  1177,
    1178,  1263,  1179,  1205,  1206,   304,   740,  1311,   801,  1207,
    1208,  1209,  1210,  1228,  1223,   753,  1293,  1292,  1224,  1225,
    1229,  1282,  1278,  1230,  1231,  1232,  1233,  1246,  1262,   732,
    1285,  1284,  1261,   721,  1264,  1265,  1266,  1267,  1268,   759,
    1279,  1295,  1296,  1297,  1308,   492,  1294,   809,   791,  1283,
     396,   725,   656,   450,  1254,  1255,   662,   320,   542,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     572,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   634,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   652
};

static const yytype_int16 yycheck[] =
{
     631,   632,   306,     8,     1,   309,   310,   311,     1,   313,
     314,     1,     1,   234,   212,    49,     1,    53,     1,   217,
       1,     1,     1,     1,     1,     1,     1,     1,   232,   109,
       1,     1,   236,     1,   234,     1,   235,    30,   234,    11,
      12,    13,   212,     1,   234,    38,   234,   217,     6,     7,
       1,     9,    10,   232,     1,   232,    14,   236,    41,   236,
      34,   234,     1,   234,   232,    23,    24,    25,   236,     1,
      44,    45,    46,   234,    32,    49,    50,    35,    36,    37,
      54,    55,    56,     1,   234,    43,    65,    57,    65,   125,
     234,     1,     1,   234,    65,    65,    81,    67,    81,   232,
     233,   405,    60,   407,   408,   232,     1,   411,   101,   236,
       1,   101,   101,    71,   418,    81,    74,    75,    65,   423,
     234,   101,    98,   101,    82,     1,   206,   232,   432,   433,
      88,   236,    90,   101,    92,   234,    94,   109,    96,    97,
     444,   445,   446,   126,   120,   234,     1,   126,   126,   107,
     101,   126,    28,   123,    30,   113,   114,   191,   116,   117,
     118,     1,   101,   121,    19,   234,   200,     1,   232,   101,
     232,   234,   236,   232,   236,   126,     1,   236,   175,   126,
     179,   180,    58,   234,    39,    19,    26,    27,   146,    98,
     175,   101,    68,    33,   175,   200,   234,   234,   156,   157,
     158,   159,   160,   161,   162,    39,   101,   196,   126,   175,
     101,   120,    67,    89,   234,   232,   196,    93,     1,   236,
     234,    61,    62,    63,    64,   101,   223,   234,   104,   105,
     534,   221,   221,    67,    17,    18,    76,    77,    78,    22,
     233,   221,   223,    83,    84,    85,   101,    87,   233,   224,
     233,   235,   233,   233,   233,   213,   214,   233,   134,   233,
     218,   219,   233,   233,   119,   233,   235,   232,   232,   227,
     232,   229,   236,   168,   150,   233,   101,   153,   154,   155,
       1,   235,   233,   235,    67,   119,     1,   235,     3,   221,
       5,   186,   224,   127,   128,   235,   151,   152,  1080,  1081,
    1082,   233,    85,    86,    19,     1,   224,   202,    91,    30,
       1,   221,    95,   147,   235,   233,   620,    38,   101,   623,
     235,   625,   235,   233,    39,   201,   630,   110,   111,   112,
     221,   235,   235,   224,   235,   235,   235,     1,   233,   122,
     216,   235,    57,   168,    59,    41,   650,   235,   203,   235,
     235,   235,    67,   235,   235,    19,    70,   233,    72,    15,
     143,   186,   235,   235,    79,   235,    57,   235,   235,   224,
     235,   235,   235,   228,    65,    39,    67,   202,   233,   235,
     101,   235,   235,   235,    40,    81,   101,   235,   235,     1,
     224,   235,   235,   233,     6,     7,   235,     9,    10,   233,
     235,   115,    14,    67,   235,   188,   235,   235,   123,   235,
     232,    23,    24,    25,   235,     1,   235,    73,   132,   235,
      32,   235,   235,    35,    36,    37,   235,   142,   235,   235,
     126,    43,   123,    19,   235,   235,   151,   101,   814,   815,
     816,   817,   818,   819,   820,   235,   102,   103,    60,   164,
     233,   235,   108,    39,   235,   119,   235,   171,   172,    71,
     235,   235,    74,    75,   235,   235,   235,   235,   235,   235,
      82,   235,   235,   235,   235,   235,    88,   133,    90,   235,
      92,    67,    94,   235,    96,    97,   201,   151,   152,   235,
     235,   235,   148,   235,   235,   107,   235,     4,   235,   235,
     215,   113,   114,   235,   116,   117,   118,   235,   235,   121,
     224,   235,   235,    20,    21,   235,   230,   235,   233,   232,
     175,    72,   124,   235,    31,   235,   124,    72,   124,   232,
     109,   109,   212,   119,   146,     1,   109,   109,   109,   203,
     109,   127,   128,     1,   156,   157,   158,   159,   160,   161,
     162,   109,   109,   232,   232,   211,   124,   232,   235,   235,
     224,   147,    69,    70,   228,    72,   235,   235,    34,   235,
      28,   212,    30,   235,   235,   231,   235,   235,    44,    45,
      46,   132,   235,    49,    50,   235,   235,   132,    54,    55,
      56,    98,   235,   235,  1225,   235,   235,   235,   235,   106,
      58,   213,   214,   235,   235,   235,   218,   219,   235,   235,
      68,   235,   163,   235,   235,   227,   235,   229,   163,   235,
     235,   172,   129,   109,   131,   132,   235,   172,   232,   235,
     181,    89,   235,   109,   109,    93,   181,   212,   224,   109,
     109,   109,   149,   101,   109,   212,   104,   105,     1,   212,
       3,     1,     5,   212,   205,   109,   207,   208,   109,   109,
     205,   109,   207,   208,   109,   172,    19,    17,    18,   109,
     177,   222,    22,   212,   181,   235,   134,   222,   185,   230,
     235,   212,   212,   190,   212,   230,    39,   194,   212,   212,
     212,   212,   150,   212,   109,   153,   154,   155,   205,   212,
     207,   208,   109,   210,    57,   232,    59,   232,     0,     1,
     124,   124,     4,   212,    67,   222,   124,    67,   235,   235,
     235,   235,   124,   230,    16,   235,    79,    19,   212,    21,
     235,   235,   235,   235,   232,    85,    86,    29,   235,   235,
     235,    91,   232,   201,   232,    95,   235,   109,   101,    41,
     235,   101,   232,   109,   235,    47,    48,    42,   216,   232,
     110,   111,   112,   235,    49,   212,    51,    52,   235,   232,
     123,   235,   122,   235,    66,   235,   235,   212,    70,   135,
     136,   137,   138,   139,   140,   141,   235,   212,    80,   142,
     212,   235,   235,   143,   235,   124,   212,   124,   151,   109,
     109,   124,   124,    42,   124,   124,   124,    99,   100,   124,
      49,   164,    51,    52,   232,   232,   124,   124,   124,   124,
     212,   124,   232,   115,   235,   234,   232,   109,   109,   109,
     235,   235,   235,   232,   235,   232,   109,   235,   188,   235,
     132,   232,   232,    42,   232,   232,   232,   232,   201,   232,
      49,   232,   144,   145,   232,   232,   232,   232,   232,   232,
     232,   232,   215,   232,   124,   235,   109,   109,   109,   109,
     124,   232,   124,   212,   124,   124,   235,   169,   124,   124,
     165,   166,   167,   109,   232,   170,   171,   124,   173,   174,
     182,   176,   124,   178,   124,   187,   181,   124,   183,   184,
     192,   124,   124,   195,   189,   124,   232,   232,   193,   124,
     124,   232,   197,   198,   199,   232,   232,   212,   232,   204,
     232,   232,   235,   124,   209,   109,   165,   166,   167,   124,
     232,   170,   171,   232,   173,   174,   232,   176,   232,   178,
     109,   232,   181,   232,   183,   184,   232,   124,   232,   232,
     189,   124,   124,   232,   193,     1,   232,   232,   197,   198,
     199,   232,   232,   232,   232,   204,   165,   166,   167,   232,
     209,   170,   171,   232,   173,   174,   232,   176,   124,   178,
      26,    27,   181,   124,   183,   184,   124,    33,   232,   124,
     189,   124,   124,   124,   193,   212,   232,   232,   197,   198,
     199,   232,   235,   232,   232,   204,   124,   232,   232,   124,
     209,   232,   232,   124,   232,    61,    62,    63,    64,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
      76,    77,    78,   235,   232,   232,   232,    83,    84,    85,
     232,    87,   232,   124,   212,   232,   235,   124,   124,   124,
     232,   232,   232,   232,   232,   124,   232,   232,   232,   124,
     124,   232,   232,   124,   124,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   124,   232,   232,   235,   232,   124,   232,   236,   232,
     232,   235,   232,   232,   109,   232,   232,   124,   232,   130,
     132,   130,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   132,   232,   232,   130,   232,   232,
     232,   130,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   220,   232,   232,   232,
     232,   237,   232,   232,   232,    77,   496,  1310,   579,   232,
     232,   232,   232,  1042,   232,   511,  1272,  1270,   235,   235,
     232,  1248,   235,   232,   232,   232,   232,   232,   232,   483,
    1259,  1257,  1143,   460,   237,   237,   237,   237,   237,   527,
     232,   232,   232,   232,  1281,   221,  1274,   592,   565,  1253,
     118,   473,   390,   168,  1111,  1113,   400,    97,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   266,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   295,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   370
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   239,     0,     1,     4,    16,    19,    21,    29,    41,
      47,    48,    66,    70,    80,    99,   100,   115,   132,   144,
     145,   169,   182,   187,   192,   195,   240,   245,   250,   269,
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
     116,   117,   118,   121,   146,   156,   157,   158,   159,   160,
     161,   162,   213,   214,   218,   219,   227,   229,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     494,   498,   499,   500,   501,   234,   234,   234,     1,    98,
     120,   246,   247,   248,   249,   234,   234,   234,     1,    34,
      44,    45,    46,    49,    50,    54,    55,    56,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,     1,
      28,    30,    58,    68,    89,    93,   101,   104,   105,   134,
     150,   153,   154,   155,   201,   216,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   234,     1,   223,   290,   291,   292,
     293,   294,   234,     1,   101,   382,   383,   384,   234,   232,
     235,   235,   235,   233,   271,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   233,
     504,     1,    17,    18,    22,    67,    85,    86,    91,    95,
     101,   110,   111,   112,   122,   143,   188,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,     1,     3,     5,    19,    39,    57,
      59,    67,    79,   101,   123,   142,   151,   164,   201,   215,
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
     235,   233,   247,     1,    81,   175,   277,   278,   279,   280,
       1,    19,    39,    67,   101,   119,   151,   152,   203,   224,
     228,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   319,     1,    41,    81,   126,   376,   377,   378,
     379,   380,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   521,   232,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     233,   252,     1,   101,   221,   397,   398,   399,   400,   232,
     235,   233,   291,   175,     1,   101,   168,   186,   202,   283,
     284,   285,   286,   287,   288,   235,   233,   383,     1,   101,
     221,   224,   387,   388,   389,   390,   391,   124,   124,   124,
     232,   109,   109,   242,   212,   109,   242,   242,   242,   109,
     242,   242,   109,   109,   109,   109,   232,   232,   235,   235,
     235,   342,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   233,   326,   232,   235,   235,   235,   235,
     235,   235,   418,   235,   235,   235,   235,   235,   235,   235,
     235,   233,   407,   235,   235,   233,   435,   124,   232,   235,
     235,   233,   445,   212,   242,   109,   242,   242,   212,   109,
     242,   212,   109,   109,   109,   212,   212,   242,   109,   109,
     109,   109,   242,   109,   109,   109,   109,   212,   235,   235,
     212,   242,   242,   212,   212,   212,   212,   217,   212,   217,
     212,   212,   212,   212,   109,   242,   242,   242,   212,   109,
     232,   232,   235,   235,   368,   235,   235,   235,   235,   235,
     233,   362,   235,   235,   233,   429,   232,   235,   235,   348,
     235,   233,   352,   124,   124,   232,   232,   235,   235,   233,
     278,   232,   235,   235,   320,   235,   235,   235,   235,   316,
     235,   235,   233,   306,   232,   235,   235,   235,   233,   377,
     212,   212,   242,   124,   212,   124,   212,   212,   212,   232,
     109,   124,   212,   124,   109,   109,   124,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   232,   232,   235,   401,
     233,   398,   212,   232,   234,   232,   235,   235,   235,   235,
     233,   284,   124,   232,   232,   235,   392,   235,   233,   388,
     232,   232,   232,   232,   135,   136,   137,   138,   139,   140,
     141,   241,   242,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   109,   109,   242,   235,
     109,   242,   109,   242,   124,   109,   109,   109,   242,   109,
     244,   244,   232,   124,   179,   180,   124,   212,   124,   124,
     235,   124,   124,   109,   124,   124,   124,   124,   242,   232,
     124,   124,   232,   232,   124,   124,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,    42,    49,   165,   166,   167,   170,   171,   173,
     174,   176,   178,   181,   183,   184,   189,   193,   197,   198,
     199,   204,   209,   496,   497,    42,    49,    51,    52,   165,
     166,   167,   170,   171,   173,   174,   176,   178,   181,   183,
     184,   189,   193,   197,   198,   199,   204,   209,   492,   493,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     124,   212,   235,   124,   109,   124,   124,   124,   232,   124,
     124,   232,   124,   124,   235,   109,   355,   356,   232,   232,
     232,   124,   124,   232,   124,   212,   235,   124,   124,   124,
     212,   235,   124,   124,   232,   124,   124,   124,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   124,   235,   232,   232,     1,   101,
     196,   221,   295,   296,   297,   298,   299,   124,   124,   124,
     124,   232,   232,   124,   235,   124,   232,   241,   241,   241,
     241,   241,   241,   241,   232,   232,   232,    53,   125,   343,
     344,   232,   232,   232,   232,   232,   232,   232,   232,   232,
      11,    12,    13,   243,   244,   232,   232,   232,   232,   232,
     232,   232,   232,   232,     8,   200,   419,   420,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   236,   232,   236,   232,   232,    15,    40,    73,   102,
     103,   108,   133,   148,   211,   231,   369,   370,   232,   232,
     232,   232,   232,   232,   232,   232,   232,    49,   191,   200,
     349,   350,   220,   236,   354,   232,   232,   232,   232,     4,
      20,    21,    31,    69,    70,    72,    98,   106,   129,   131,
     132,   149,   172,   177,   181,   185,   190,   194,   205,   207,
     208,   210,   222,   230,   321,   322,   232,   232,   232,   232,
      42,    49,    51,    52,   165,   166,   167,   170,   171,   173,
     174,   176,   178,   181,   183,   184,   189,   193,   197,   198,
     199,   204,   209,   317,   318,   232,   232,   232,   232,   232,
     232,    72,   132,   163,   172,   181,   205,   207,   208,   222,
     230,   402,   403,   232,   235,   235,   300,   233,   296,   232,
     232,   232,   232,   232,    72,   132,   163,   172,   181,   205,
     207,   208,   222,   230,   393,   394,   232,   232,   236,   243,
     243,   243,   232,   236,   497,   493,   232,   236,   232,   236,
     109,   356,   232,   237,   237,   237,   237,   237,   237,   232,
     236,   232,   236,   232,   236,   124,   206,   244,   235,   232,
     232,   236,   344,   420,   370,   350,   130,   132,   130,   132,
     130,   130,   322,   318,   403,   232,   232,   232,    70,    72,
     115,   132,   171,   172,   224,   230,   301,   302,   394,   232,
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
#line 2867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 30:
#line 400 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 31:
#line 401 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 32:
#line 402 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 33:
#line 403 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 34:
#line 404 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 35:
#line 405 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 36:
#line 406 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2909 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 37:
#line 407 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 38:
#line 410 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = 0; }
#line 2921 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 40:
#line 411 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 41:
#line 412 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 42:
#line 413 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2939 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 43:
#line 414 "conf_parser.y" /* yacc.c:1652  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2945 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 50:
#line 427 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2954 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 51:
#line 433 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 72:
#line 465 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_certificate_file);
    ConfigServerInfo.ssl_certificate_file = xstrdup(yylval.string);
  }
}
#line 2975 "conf_parser.c" /* yacc.c:1652  */
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
#line 2987 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 74:
#line 483 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_param_file);
    ConfigServerInfo.ssl_dh_param_file = xstrdup(yylval.string);
  }
}
#line 2999 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 75:
#line 492 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_cipher_list);
    ConfigServerInfo.ssl_cipher_list = xstrdup(yylval.string);
  }
}
#line 3011 "conf_parser.c" /* yacc.c:1652  */
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
#line 3023 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 77:
#line 510 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_message_digest_algorithm);
    ConfigServerInfo.ssl_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 78:
#line 519 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.ssl_dh_elliptic_curve);
    ConfigServerInfo.ssl_dh_elliptic_curve = xstrdup(yylval.string);
  }
}
#line 3047 "conf_parser.c" /* yacc.c:1652  */
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
#line 3065 "conf_parser.c" /* yacc.c:1652  */
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
#line 3083 "conf_parser.c" /* yacc.c:1652  */
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
#line 3096 "conf_parser.c" /* yacc.c:1652  */
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
#line 3113 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 83:
#line 582 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3125 "conf_parser.c" /* yacc.c:1652  */
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
#line 3151 "conf_parser.c" /* yacc.c:1652  */
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
#line 3177 "conf_parser.c" /* yacc.c:1652  */
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
#line 3203 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 87:
#line 660 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3212 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 95:
#line 678 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 96:
#line 687 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 97:
#line 696 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3248 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 98:
#line 709 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3257 "conf_parser.c" /* yacc.c:1652  */
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
#line 3274 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 105:
#line 730 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3283 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 106:
#line 736 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3292 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 107:
#line 746 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3301 "conf_parser.c" /* yacc.c:1652  */
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
#line 3319 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 116:
#line 768 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3328 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 117:
#line 774 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3337 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 118:
#line 780 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3346 "conf_parser.c" /* yacc.c:1652  */
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
#line 3367 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 126:
#line 814 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3376 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 127:
#line 820 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3385 "conf_parser.c" /* yacc.c:1652  */
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
#line 3398 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 135:
#line 840 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3409 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 136:
#line 848 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3417 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 137:
#line 851 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.size.value = 0;
}
#line 3425 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 138:
#line 856 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3434 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 142:
#line 863 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3443 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 143:
#line 867 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3452 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 144:
#line 871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3461 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 145:
#line 875 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3470 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 146:
#line 879 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3479 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 147:
#line 883 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3488 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 148:
#line 887 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3497 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 149:
#line 891 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3506 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 150:
#line 901 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3518 "conf_parser.c" /* yacc.c:1652  */
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
#line 3577 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 165:
#line 977 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3586 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 166:
#line 983 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3595 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 167:
#line 989 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3604 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 168:
#line 995 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3613 "conf_parser.c" /* yacc.c:1652  */
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
#line 3627 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 170:
#line 1012 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3636 "conf_parser.c" /* yacc.c:1652  */
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
#line 3650 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 172:
#line 1029 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3659 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 173:
#line 1035 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3668 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 177:
#line 1042 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3677 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 178:
#line 1046 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3686 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 179:
#line 1050 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3695 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 180:
#line 1054 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3704 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 181:
#line 1058 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3713 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 182:
#line 1062 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3722 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 183:
#line 1066 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3731 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 184:
#line 1070 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3740 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 185:
#line 1074 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3749 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 186:
#line 1078 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3758 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 187:
#line 1082 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3767 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 188:
#line 1086 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3776 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 189:
#line 1090 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3785 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 190:
#line 1094 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3794 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 191:
#line 1098 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3803 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 192:
#line 1102 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3812 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 193:
#line 1106 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3821 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 194:
#line 1110 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3830 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 195:
#line 1114 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3839 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 196:
#line 1118 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3848 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 197:
#line 1122 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3857 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 198:
#line 1126 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3866 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 199:
#line 1130 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3875 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 200:
#line 1136 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3884 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 204:
#line 1143 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3893 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 205:
#line 1147 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3902 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 206:
#line 1151 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3911 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 207:
#line 1155 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3920 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 208:
#line 1159 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 3929 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 209:
#line 1163 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 3938 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 210:
#line 1167 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 3947 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 211:
#line 1171 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 3956 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 212:
#line 1175 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 3965 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 213:
#line 1179 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 3974 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 214:
#line 1183 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 3983 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 215:
#line 1187 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 3992 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 216:
#line 1191 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4001 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 217:
#line 1195 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4010 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 218:
#line 1199 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4019 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 219:
#line 1203 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4028 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 220:
#line 1207 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4037 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 221:
#line 1211 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4046 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 222:
#line 1215 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4055 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 223:
#line 1219 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4064 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 224:
#line 1223 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4073 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 225:
#line 1227 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4082 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 226:
#line 1231 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4091 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 227:
#line 1235 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4100 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 228:
#line 1239 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4109 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 229:
#line 1243 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4118 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 230:
#line 1247 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4127 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 231:
#line 1251 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4136 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 232:
#line 1255 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4145 "conf_parser.c" /* yacc.c:1652  */
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
#line 4162 "conf_parser.c" /* yacc.c:1652  */
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
#line 4210 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 253:
#line 1340 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4219 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 254:
#line 1346 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4228 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 255:
#line 1352 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4237 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 256:
#line 1358 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4246 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 257:
#line 1364 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4255 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 258:
#line 1370 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4264 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 259:
#line 1376 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4273 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 260:
#line 1382 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4282 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 261:
#line 1388 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4292 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 262:
#line 1395 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4301 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 263:
#line 1401 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4310 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 264:
#line 1407 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 265:
#line 1413 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4331 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 266:
#line 1422 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4343 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 267:
#line 1431 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4352 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 271:
#line 1438 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4361 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 272:
#line 1442 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4370 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 273:
#line 1452 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4379 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 275:
#line 1458 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value = 0;
}
#line 4387 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 279:
#line 1464 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4396 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 280:
#line 1468 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4405 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 281:
#line 1472 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4414 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 289:
#line 1480 "conf_parser.y" /* yacc.c:1652  */
    { block_state.flags.value = 0; }
#line 4420 "conf_parser.c" /* yacc.c:1652  */
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
#line 4438 "conf_parser.c" /* yacc.c:1652  */
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
#line 4458 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 295:
#line 1515 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4467 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 296:
#line 1521 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4476 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 297:
#line 1531 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4485 "conf_parser.c" /* yacc.c:1652  */
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
#line 4531 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 310:
#line 1589 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4540 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 311:
#line 1595 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4549 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 312:
#line 1601 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4558 "conf_parser.c" /* yacc.c:1652  */
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
#line 4572 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 314:
#line 1618 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4581 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 318:
#line 1625 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4590 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 319:
#line 1629 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4599 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 320:
#line 1633 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4608 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 321:
#line 1637 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4617 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 322:
#line 1641 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4626 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 323:
#line 1645 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4635 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 324:
#line 1649 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4644 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 325:
#line 1653 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4653 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 326:
#line 1657 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4662 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 327:
#line 1661 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4671 "conf_parser.c" /* yacc.c:1652  */
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
#line 4688 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 329:
#line 1681 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4700 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 330:
#line 1690 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4712 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 331:
#line 1703 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4724 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 332:
#line 1710 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4735 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 339:
#line 1721 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4744 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 340:
#line 1727 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4753 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 341:
#line 1733 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4762 "conf_parser.c" /* yacc.c:1652  */
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
#line 4777 "conf_parser.c" /* yacc.c:1652  */
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
#line 4793 "conf_parser.c" /* yacc.c:1652  */
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
#line 4808 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 356:
#line 1790 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4817 "conf_parser.c" /* yacc.c:1652  */
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
#line 4839 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 358:
#line 1815 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4848 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 362:
#line 1822 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4857 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 363:
#line 1826 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4866 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 364:
#line 1830 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4875 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 365:
#line 1834 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4884 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 366:
#line 1838 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4893 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 367:
#line 1842 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4902 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 368:
#line 1846 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4911 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 369:
#line 1850 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 4920 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 370:
#line 1854 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 4929 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 371:
#line 1858 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 4938 "conf_parser.c" /* yacc.c:1652  */
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
#line 4952 "conf_parser.c" /* yacc.c:1652  */
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
#line 4965 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 379:
#line 1890 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4974 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 380:
#line 1896 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4983 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 384:
#line 1903 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 4992 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 385:
#line 1907 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5001 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 386:
#line 1911 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5010 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 387:
#line 1915 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5019 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 388:
#line 1919 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5028 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 389:
#line 1923 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5037 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 390:
#line 1927 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5046 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 391:
#line 1931 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5055 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 392:
#line 1935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5064 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 393:
#line 1939 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5073 "conf_parser.c" /* yacc.c:1652  */
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
#line 5088 "conf_parser.c" /* yacc.c:1652  */
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
#line 5159 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 414:
#line 2045 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5168 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 415:
#line 2051 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5177 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 416:
#line 2057 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5186 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 417:
#line 2063 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5195 "conf_parser.c" /* yacc.c:1652  */
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
#line 5211 "conf_parser.c" /* yacc.c:1652  */
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
#line 5227 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 420:
#line 2095 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5236 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 421:
#line 2101 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5245 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 422:
#line 2107 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5254 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 423:
#line 2111 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5263 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 424:
#line 2117 "conf_parser.y" /* yacc.c:1652  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5271 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 428:
#line 2123 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5280 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 429:
#line 2127 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5289 "conf_parser.c" /* yacc.c:1652  */
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
#line 5303 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 431:
#line 2144 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5312 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 432:
#line 2150 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5321 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 433:
#line 2156 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5330 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 434:
#line 2162 "conf_parser.y" /* yacc.c:1652  */
    {
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no TLS support");
#endif
}
#line 5344 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 435:
#line 2177 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5353 "conf_parser.c" /* yacc.c:1652  */
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
#line 5376 "conf_parser.c" /* yacc.c:1652  */
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
#line 5399 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 443:
#line 2224 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5408 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 444:
#line 2234 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5417 "conf_parser.c" /* yacc.c:1652  */
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
#line 5441 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 451:
#line 2262 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5450 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 452:
#line 2268 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5459 "conf_parser.c" /* yacc.c:1652  */
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
#line 5476 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 459:
#line 2300 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5485 "conf_parser.c" /* yacc.c:1652  */
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
#line 5505 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 466:
#line 2324 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5514 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 467:
#line 2330 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5523 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 517:
#line 2391 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5531 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 518:
#line 2396 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5539 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 519:
#line 2401 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5547 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 520:
#line 2406 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5555 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 521:
#line 2411 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5563 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 522:
#line 2416 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5571 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 523:
#line 2421 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5579 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 524:
#line 2426 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5587 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 525:
#line 2431 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5595 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 526:
#line 2436 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5603 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 527:
#line 2441 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5611 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 528:
#line 2446 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5619 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 529:
#line 2451 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5627 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 530:
#line 2456 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5635 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 531:
#line 2461 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5643 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 532:
#line 2466 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5651 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 533:
#line 2471 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5659 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 534:
#line 2476 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5667 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 535:
#line 2481 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5675 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 536:
#line 2486 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5683 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 537:
#line 2491 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5691 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 538:
#line 2496 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5699 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 539:
#line 2501 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5707 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 540:
#line 2506 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5715 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 541:
#line 2511 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5723 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 542:
#line 2516 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5731 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 543:
#line 2519 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5739 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 544:
#line 2524 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5747 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 545:
#line 2527 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5755 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 546:
#line 2532 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5763 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 547:
#line 2537 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5771 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 548:
#line 2542 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5779 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 549:
#line 2547 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5787 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 550:
#line 2552 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5795 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 551:
#line 2557 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5803 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 552:
#line 2562 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5811 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 553:
#line 2567 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5819 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 554:
#line 2572 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5827 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 555:
#line 2577 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5835 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 556:
#line 2582 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5843 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 557:
#line 2587 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5851 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 558:
#line 2592 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 5859 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 562:
#line 2598 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 5867 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 563:
#line 2601 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5875 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 564:
#line 2604 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5883 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 565:
#line 2607 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5891 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 566:
#line 2610 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 5899 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 567:
#line 2613 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5907 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 568:
#line 2616 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5915 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 569:
#line 2619 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5923 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 570:
#line 2622 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5931 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 571:
#line 2625 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 5939 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 572:
#line 2628 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 5947 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 573:
#line 2631 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 5955 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 574:
#line 2634 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 5963 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 575:
#line 2637 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 5971 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 576:
#line 2640 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 5979 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 577:
#line 2643 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 5987 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 578:
#line 2646 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 5995 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 579:
#line 2649 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6003 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 580:
#line 2652 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6011 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 581:
#line 2655 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6019 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 582:
#line 2658 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6027 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 583:
#line 2661 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6035 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 584:
#line 2664 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6043 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 585:
#line 2669 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6051 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 589:
#line 2675 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6059 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 590:
#line 2678 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6067 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 591:
#line 2681 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6075 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 592:
#line 2684 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6083 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 593:
#line 2687 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6091 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 594:
#line 2690 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6099 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 595:
#line 2693 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6107 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 596:
#line 2696 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6115 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 597:
#line 2699 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6123 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 598:
#line 2702 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6131 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 599:
#line 2705 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6139 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 600:
#line 2708 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6147 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 601:
#line 2711 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6155 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 602:
#line 2714 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6163 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 603:
#line 2717 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6171 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 604:
#line 2720 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6179 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 605:
#line 2723 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6187 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 606:
#line 2726 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6195 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 607:
#line 2729 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6203 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 608:
#line 2732 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6211 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 609:
#line 2735 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6219 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 610:
#line 2740 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6227 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 611:
#line 2745 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6235 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 612:
#line 2750 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6243 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 613:
#line 2755 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6251 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 632:
#line 2783 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6259 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 633:
#line 2788 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6267 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 634:
#line 2793 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6275 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 635:
#line 2798 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6283 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 636:
#line 2803 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6291 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 637:
#line 2808 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6299 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 638:
#line 2813 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6307 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 639:
#line 2818 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6315 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 640:
#line 2823 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6323 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 641:
#line 2828 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6331 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 642:
#line 2833 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6339 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 643:
#line 2838 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6347 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 644:
#line 2843 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6355 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 645:
#line 2848 "conf_parser.y" /* yacc.c:1652  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6363 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 659:
#line 2871 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6372 "conf_parser.c" /* yacc.c:1652  */
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
#line 6391 "conf_parser.c" /* yacc.c:1652  */
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
#line 6403 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 662:
#line 2902 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6412 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 663:
#line 2908 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6421 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 664:
#line 2914 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6430 "conf_parser.c" /* yacc.c:1652  */
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
#line 6442 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 666:
#line 2929 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6451 "conf_parser.c" /* yacc.c:1652  */
    break;

  case 667:
#line 2935 "conf_parser.y" /* yacc.c:1652  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6460 "conf_parser.c" /* yacc.c:1652  */
    break;


#line 6464 "conf_parser.c" /* yacc.c:1652  */
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
