/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 28 "conf_parser.y" /* yacc.c:339  */


#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "conf_pseudo.h"
#include "event.h"
#include "id.h"
#include "log.h"
#include "client.h"	/* for UMODE_SERVNOTICE only */
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "server.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "user.h"
#include "motd.h"

#ifdef HAVE_LIBCRYPTO
#include <openssl/rsa.h>
#include <openssl/bio.h>
#include <openssl/pem.h>
#include <openssl/dh.h>
#endif

#include "rsa.h"

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
    max_perip,
    con_freq,
    min_idle,
    max_idle,
    max_total,
    max_global,
    max_local,
    max_ident,
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
    MyFree(node->data);
    dlinkDelete(node, &block_state.mask.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.leaf.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.leaf.list);
    free_dlink_node(node);
  }

  DLINK_FOREACH_SAFE(node, node_next, block_state.hub.list.head)
  {
    MyFree(node->data);
    dlinkDelete(node, &block_state.hub.list);
    free_dlink_node(node);
  }

  memset(&block_state, 0, sizeof(block_state));
}


#line 191 "conf_parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
    CONNECT = 275,
    CONNECTFREQ = 276,
    CYCLE_ON_HOST_CHANGE = 277,
    DEFAULT_FLOODCOUNT = 278,
    DEFAULT_JOIN_FLOOD_COUNT = 279,
    DEFAULT_JOIN_FLOOD_TIME = 280,
    DEFAULT_MAX_CLIENTS = 281,
    DENY = 282,
    DESCRIPTION = 283,
    DIE = 284,
    DISABLE_AUTH = 285,
    DISABLE_FAKE_CHANNELS = 286,
    DISABLE_REMOTE_COMMANDS = 287,
    DLINE_MIN_CIDR = 288,
    DLINE_MIN_CIDR6 = 289,
    DOTS_IN_IDENT = 290,
    EMAIL = 291,
    ENCRYPTED = 292,
    EXCEED_LIMIT = 293,
    EXEMPT = 294,
    FAILED_OPER_NOTICE = 295,
    FLATTEN_LINKS = 296,
    GECOS = 297,
    GENERAL = 298,
    HIDDEN = 299,
    HIDDEN_NAME = 300,
    HIDE_CHANS = 301,
    HIDE_IDLE = 302,
    HIDE_IDLE_FROM_OPERS = 303,
    HIDE_SERVER_IPS = 304,
    HIDE_SERVERS = 305,
    HIDE_SERVICES = 306,
    HOST = 307,
    HUB = 308,
    HUB_MASK = 309,
    IGNORE_BOGUS_TS = 310,
    INVISIBLE_ON_CONNECT = 311,
    INVITE_CLIENT_COUNT = 312,
    INVITE_CLIENT_TIME = 313,
    IP = 314,
    IRCD_AUTH = 315,
    IRCD_FLAGS = 316,
    IRCD_SID = 317,
    JOIN = 318,
    KILL = 319,
    KILL_CHASE_TIME_LIMIT = 320,
    KLINE = 321,
    KLINE_EXEMPT = 322,
    KLINE_MIN_CIDR = 323,
    KLINE_MIN_CIDR6 = 324,
    KNOCK_CLIENT_COUNT = 325,
    KNOCK_CLIENT_TIME = 326,
    KNOCK_DELAY_CHANNEL = 327,
    LEAF_MASK = 328,
    LINKS_DELAY = 329,
    LISTEN = 330,
    MASK = 331,
    MAX_ACCEPT = 332,
    MAX_BANS = 333,
    MAX_CHANNELS = 334,
    MAX_GLOBAL = 335,
    MAX_IDENT = 336,
    MAX_IDLE = 337,
    MAX_LOCAL = 338,
    MAX_NICK_CHANGES = 339,
    MAX_NICK_LENGTH = 340,
    MAX_NICK_TIME = 341,
    MAX_NUMBER = 342,
    MAX_TARGETS = 343,
    MAX_TOPIC_LENGTH = 344,
    MAX_WATCH = 345,
    MIN_IDLE = 346,
    MIN_NONWILDCARD = 347,
    MIN_NONWILDCARD_SIMPLE = 348,
    MODULE = 349,
    MODULES = 350,
    MOTD = 351,
    NAME = 352,
    NEED_IDENT = 353,
    NEED_PASSWORD = 354,
    NETWORK_DESC = 355,
    NETWORK_NAME = 356,
    NICK = 357,
    NO_OPER_FLOOD = 358,
    NO_TILDE = 359,
    NUMBER = 360,
    NUMBER_PER_CIDR = 361,
    NUMBER_PER_IP = 362,
    OPER_ONLY_UMODES = 363,
    OPER_UMODES = 364,
    OPERATOR = 365,
    OPERS_BYPASS_CALLERID = 366,
    PACE_WAIT = 367,
    PACE_WAIT_SIMPLE = 368,
    PASSWORD = 369,
    PATH = 370,
    PING_COOKIE = 371,
    PING_TIME = 372,
    PORT = 373,
    QSTRING = 374,
    RANDOM_IDLE = 375,
    REASON = 376,
    REDIRPORT = 377,
    REDIRSERV = 378,
    REHASH = 379,
    REMOTE = 380,
    REMOTEBAN = 381,
    RESV = 382,
    RESV_EXEMPT = 383,
    RSA_PRIVATE_KEY_FILE = 384,
    RSA_PUBLIC_KEY_FILE = 385,
    SECONDS = 386,
    MINUTES = 387,
    HOURS = 388,
    DAYS = 389,
    WEEKS = 390,
    MONTHS = 391,
    YEARS = 392,
    SEND_PASSWORD = 393,
    SENDQ = 394,
    SERVERHIDE = 395,
    SERVERINFO = 396,
    SHORT_MOTD = 397,
    SPOOF = 398,
    SPOOF_NOTICE = 399,
    SQUIT = 400,
    SSL_CERTIFICATE_FILE = 401,
    SSL_CERTIFICATE_FINGERPRINT = 402,
    SSL_CONNECTION_REQUIRED = 403,
    SSL_DH_ELLIPTIC_CURVE = 404,
    SSL_DH_PARAM_FILE = 405,
    SSL_MESSAGE_DIGEST_ALGORITHM = 406,
    STATS_E_DISABLED = 407,
    STATS_I_OPER_ONLY = 408,
    STATS_K_OPER_ONLY = 409,
    STATS_M_OPER_ONLY = 410,
    STATS_O_OPER_ONLY = 411,
    STATS_P_OPER_ONLY = 412,
    STATS_U_OPER_ONLY = 413,
    T_ALL = 414,
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
    T_SSL = 450,
    T_SSL_CIPHER_LIST = 451,
    T_TARGET = 452,
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
    TKLINE_EXPIRE_NOTICES = 465,
    TMASKED = 466,
    TS_MAX_DELTA = 467,
    TS_WARN_DELTA = 468,
    TWODOTS = 469,
    TYPE = 470,
    UNKLINE = 471,
    USE_LOGGING = 472,
    USER = 473,
    VHOST = 474,
    VHOST6 = 475,
    WARN_NO_CONNECT_BLOCK = 476,
    WHOIS = 477,
    XLINE = 478,
    XLINE_EXEMPT = 479
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
#define CONNECT 275
#define CONNECTFREQ 276
#define CYCLE_ON_HOST_CHANGE 277
#define DEFAULT_FLOODCOUNT 278
#define DEFAULT_JOIN_FLOOD_COUNT 279
#define DEFAULT_JOIN_FLOOD_TIME 280
#define DEFAULT_MAX_CLIENTS 281
#define DENY 282
#define DESCRIPTION 283
#define DIE 284
#define DISABLE_AUTH 285
#define DISABLE_FAKE_CHANNELS 286
#define DISABLE_REMOTE_COMMANDS 287
#define DLINE_MIN_CIDR 288
#define DLINE_MIN_CIDR6 289
#define DOTS_IN_IDENT 290
#define EMAIL 291
#define ENCRYPTED 292
#define EXCEED_LIMIT 293
#define EXEMPT 294
#define FAILED_OPER_NOTICE 295
#define FLATTEN_LINKS 296
#define GECOS 297
#define GENERAL 298
#define HIDDEN 299
#define HIDDEN_NAME 300
#define HIDE_CHANS 301
#define HIDE_IDLE 302
#define HIDE_IDLE_FROM_OPERS 303
#define HIDE_SERVER_IPS 304
#define HIDE_SERVERS 305
#define HIDE_SERVICES 306
#define HOST 307
#define HUB 308
#define HUB_MASK 309
#define IGNORE_BOGUS_TS 310
#define INVISIBLE_ON_CONNECT 311
#define INVITE_CLIENT_COUNT 312
#define INVITE_CLIENT_TIME 313
#define IP 314
#define IRCD_AUTH 315
#define IRCD_FLAGS 316
#define IRCD_SID 317
#define JOIN 318
#define KILL 319
#define KILL_CHASE_TIME_LIMIT 320
#define KLINE 321
#define KLINE_EXEMPT 322
#define KLINE_MIN_CIDR 323
#define KLINE_MIN_CIDR6 324
#define KNOCK_CLIENT_COUNT 325
#define KNOCK_CLIENT_TIME 326
#define KNOCK_DELAY_CHANNEL 327
#define LEAF_MASK 328
#define LINKS_DELAY 329
#define LISTEN 330
#define MASK 331
#define MAX_ACCEPT 332
#define MAX_BANS 333
#define MAX_CHANNELS 334
#define MAX_GLOBAL 335
#define MAX_IDENT 336
#define MAX_IDLE 337
#define MAX_LOCAL 338
#define MAX_NICK_CHANGES 339
#define MAX_NICK_LENGTH 340
#define MAX_NICK_TIME 341
#define MAX_NUMBER 342
#define MAX_TARGETS 343
#define MAX_TOPIC_LENGTH 344
#define MAX_WATCH 345
#define MIN_IDLE 346
#define MIN_NONWILDCARD 347
#define MIN_NONWILDCARD_SIMPLE 348
#define MODULE 349
#define MODULES 350
#define MOTD 351
#define NAME 352
#define NEED_IDENT 353
#define NEED_PASSWORD 354
#define NETWORK_DESC 355
#define NETWORK_NAME 356
#define NICK 357
#define NO_OPER_FLOOD 358
#define NO_TILDE 359
#define NUMBER 360
#define NUMBER_PER_CIDR 361
#define NUMBER_PER_IP 362
#define OPER_ONLY_UMODES 363
#define OPER_UMODES 364
#define OPERATOR 365
#define OPERS_BYPASS_CALLERID 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PORT 373
#define QSTRING 374
#define RANDOM_IDLE 375
#define REASON 376
#define REDIRPORT 377
#define REDIRSERV 378
#define REHASH 379
#define REMOTE 380
#define REMOTEBAN 381
#define RESV 382
#define RESV_EXEMPT 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SECONDS 386
#define MINUTES 387
#define HOURS 388
#define DAYS 389
#define WEEKS 390
#define MONTHS 391
#define YEARS 392
#define SEND_PASSWORD 393
#define SENDQ 394
#define SERVERHIDE 395
#define SERVERINFO 396
#define SHORT_MOTD 397
#define SPOOF 398
#define SPOOF_NOTICE 399
#define SQUIT 400
#define SSL_CERTIFICATE_FILE 401
#define SSL_CERTIFICATE_FINGERPRINT 402
#define SSL_CONNECTION_REQUIRED 403
#define SSL_DH_ELLIPTIC_CURVE 404
#define SSL_DH_PARAM_FILE 405
#define SSL_MESSAGE_DIGEST_ALGORITHM 406
#define STATS_E_DISABLED 407
#define STATS_I_OPER_ONLY 408
#define STATS_K_OPER_ONLY 409
#define STATS_M_OPER_ONLY 410
#define STATS_O_OPER_ONLY 411
#define STATS_P_OPER_ONLY 412
#define STATS_U_OPER_ONLY 413
#define T_ALL 414
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
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_TARGET 452
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
#define TKLINE_EXPIRE_NOTICES 465
#define TMASKED 466
#define TS_MAX_DELTA 467
#define TS_WARN_DELTA 468
#define TWODOTS 469
#define TYPE 470
#define UNKLINE 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_CONNECT_BLOCK 476
#define WHOIS 477
#define XLINE 478
#define XLINE_EXEMPT 479

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "conf_parser.y" /* yacc.c:355  */

  int number;
  char *string;

#line 684 "conf_parser.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 701 "conf_parser.c" /* yacc.c:358  */

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
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
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
#  define YYSIZE_T unsigned int
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

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   1346

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  658
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1296

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   229,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   230,   225,
       2,   228,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   227,     2,   226,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   381,   381,   382,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   412,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   423,   423,
     424,   425,   426,   427,   434,   437,   437,   438,   438,   438,
     440,   446,   453,   455,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   476,   516,   574,   603,   611,   625,   653,
     668,   683,   693,   707,   716,   744,   772,   797,   819,   841,
     850,   852,   852,   853,   854,   855,   856,   858,   867,   876,
     889,   888,   906,   906,   907,   907,   907,   909,   915,   925,
     924,   943,   943,   944,   944,   944,   944,   944,   946,   952,
     958,   964,   985,   986,   986,   988,   988,   989,   991,   998,
     998,  1011,  1012,  1014,  1014,  1015,  1015,  1017,  1025,  1028,
    1034,  1033,  1039,  1039,  1040,  1044,  1048,  1052,  1056,  1060,
    1064,  1068,  1079,  1078,  1167,  1167,  1168,  1169,  1170,  1171,
    1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1181,  1187,
    1193,  1199,  1205,  1216,  1222,  1228,  1239,  1246,  1245,  1251,
    1251,  1252,  1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,
    1288,  1292,  1296,  1300,  1304,  1308,  1312,  1316,  1320,  1324,
    1328,  1332,  1336,  1343,  1342,  1348,  1348,  1349,  1353,  1357,
    1361,  1365,  1369,  1373,  1377,  1381,  1385,  1389,  1393,  1397,
    1401,  1405,  1409,  1413,  1417,  1421,  1425,  1429,  1433,  1437,
    1441,  1445,  1449,  1453,  1464,  1463,  1520,  1520,  1521,  1522,
    1523,  1524,  1525,  1526,  1527,  1528,  1529,  1530,  1531,  1532,
    1533,  1533,  1534,  1535,  1536,  1537,  1539,  1545,  1551,  1557,
    1563,  1569,  1575,  1581,  1587,  1593,  1599,  1606,  1612,  1618,
    1624,  1633,  1643,  1642,  1648,  1648,  1649,  1653,  1664,  1663,
    1670,  1669,  1674,  1674,  1675,  1679,  1683,  1689,  1689,  1690,
    1690,  1690,  1690,  1690,  1692,  1692,  1694,  1694,  1696,  1709,
    1726,  1732,  1742,  1741,  1783,  1783,  1784,  1785,  1786,  1787,
    1788,  1789,  1790,  1791,  1792,  1794,  1800,  1806,  1812,  1824,
    1823,  1829,  1829,  1830,  1834,  1838,  1842,  1846,  1850,  1854,
    1858,  1862,  1866,  1872,  1886,  1895,  1909,  1908,  1923,  1923,
    1924,  1924,  1924,  1924,  1926,  1932,  1938,  1948,  1950,  1950,
    1951,  1951,  1953,  1969,  1968,  1993,  1993,  1994,  1994,  1994,
    1994,  1996,  2002,  2022,  2021,  2027,  2027,  2028,  2032,  2036,
    2040,  2044,  2048,  2052,  2056,  2060,  2064,  2074,  2073,  2094,
    2094,  2095,  2095,  2095,  2097,  2104,  2103,  2109,  2109,  2110,
    2114,  2118,  2122,  2126,  2130,  2134,  2138,  2142,  2146,  2156,
    2155,  2227,  2227,  2228,  2229,  2230,  2231,  2232,  2233,  2234,
    2235,  2236,  2237,  2238,  2239,  2240,  2241,  2242,  2244,  2250,
    2256,  2262,  2275,  2288,  2294,  2300,  2304,  2311,  2310,  2315,
    2315,  2316,  2320,  2326,  2337,  2343,  2349,  2355,  2371,  2370,
    2396,  2396,  2397,  2397,  2397,  2399,  2419,  2429,  2428,  2455,
    2455,  2456,  2456,  2456,  2458,  2464,  2473,  2475,  2475,  2476,
    2476,  2478,  2496,  2495,  2518,  2518,  2519,  2519,  2519,  2521,
    2527,  2536,  2539,  2539,  2540,  2541,  2542,  2543,  2544,  2545,
    2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,
    2556,  2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,
    2566,  2567,  2568,  2569,  2570,  2571,  2572,  2573,  2574,  2575,
    2576,  2577,  2578,  2579,  2580,  2581,  2582,  2583,  2584,  2585,
    2588,  2593,  2598,  2603,  2609,  2614,  2619,  2624,  2629,  2634,
    2639,  2644,  2649,  2654,  2659,  2664,  2669,  2674,  2679,  2685,
    2690,  2695,  2700,  2705,  2710,  2715,  2720,  2723,  2728,  2731,
    2736,  2741,  2746,  2751,  2756,  2761,  2766,  2771,  2776,  2781,
    2786,  2791,  2797,  2796,  2801,  2801,  2802,  2805,  2808,  2811,
    2814,  2817,  2820,  2823,  2826,  2829,  2832,  2835,  2838,  2841,
    2844,  2847,  2850,  2853,  2856,  2859,  2862,  2865,  2871,  2870,
    2875,  2875,  2876,  2879,  2882,  2885,  2888,  2891,  2894,  2897,
    2900,  2903,  2906,  2909,  2912,  2915,  2918,  2921,  2924,  2927,
    2930,  2933,  2938,  2943,  2948,  2957,  2960,  2960,  2961,  2962,
    2963,  2964,  2965,  2966,  2967,  2968,  2969,  2970,  2971,  2973,
    2978,  2983,  2988,  2993,  2998,  3003,  3008,  3013,  3018,  3026,
    3029,  3029,  3030,  3031,  3032,  3033,  3034,  3035,  3036,  3037,
    3038,  3040,  3046,  3052,  3058,  3064,  3073,  3088,  3094
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
  "CONNECT", "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DLINE_MIN_CIDR",
  "DLINE_MIN_CIDR6", "DOTS_IN_IDENT", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT",
  "EXEMPT", "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "HIDDEN", "HIDDEN_NAME", "HIDE_CHANS", "HIDE_IDLE",
  "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS",
  "INVISIBLE_ON_CONNECT", "INVITE_CLIENT_COUNT", "INVITE_CLIENT_TIME",
  "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_MIN_CIDR",
  "KLINE_MIN_CIDR6", "KNOCK_CLIENT_COUNT", "KNOCK_CLIENT_TIME",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANNELS", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_ELLIPTIC_CURVE", "SSL_DH_PARAM_FILE",
  "SSL_MESSAGE_DIGEST_ALGORITHM", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
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
  "WARN_NO_CONNECT_BLOCK", "WHOIS", "XLINE", "XLINE_EXEMPT", "';'", "'}'",
  "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_ssl_message_digest_algorithm",
  "serverinfo_ssl_dh_elliptic_curve", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_default_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "pseudo_entry", "$@2", "pseudo_items",
  "pseudo_item", "pseudo_command", "pseudo_name", "pseudo_prepend",
  "pseudo_target", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@3", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@4", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_rsa_public_key_file",
  "oper_ssl_certificate_fingerprint", "oper_ssl_connection_required",
  "oper_class", "oper_umodes", "$@6", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@7", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@8", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip",
  "class_connectfreq", "class_max_channels", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@9", "class_flags_items", "class_flags_item",
  "listen_entry", "$@10", "listen_flags", "$@11", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@12", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@13", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@14",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
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
  "general_away_time", "general_max_watch", "general_cycle_on_host_change",
  "general_dline_min_cidr", "general_dline_min_cidr6",
  "general_kline_min_cidr", "general_kline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
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
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_invite_client_count",
  "channel_invite_client_time", "channel_knock_client_count",
  "channel_knock_client_time", "channel_knock_delay_channel",
  "channel_max_channels", "channel_max_bans",
  "channel_default_join_flood_count", "channel_default_join_flood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_disable_remote_commands",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
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
     475,   476,   477,   478,   479,    59,   125,   123,    61,    44,
      58
};
# endif

#define YYPACT_NINF -724

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-724)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -724,   649,  -724,  -214,  -221,  -218,  -724,  -724,  -724,  -204,
    -724,  -201,  -724,  -724,  -724,  -193,  -724,  -724,  -724,  -188,
    -187,  -724,  -175,  -724,  -169,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   337,   883,  -161,  -156,  -147,    14,  -142,   418,  -132,
    -130,  -112,    37,   -56,   -44,   -41,   504,   555,   -20,   102,
     -18,    13,   -17,   -68,   -33,    -8,    -3,    47,  -724,  -724,
    -724,  -724,  -724,    -2,    31,    38,    57,    58,    65,    71,
      80,   108,   109,   212,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   646,   350,    15,  -724,   120,
      23,  -724,  -724,    24,  -724,   121,   130,   133,   134,   135,
     138,   139,   140,   142,   146,   147,   148,   149,   150,   152,
     153,   154,   155,   158,   167,   172,   173,   175,   177,   184,
    -724,  -724,   185,   186,   187,   188,   190,   217,   218,   221,
     222,   227,   228,   229,   231,   232,   241,   242,   243,   244,
      21,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,   370,    28,   378,
      50,   247,   250,    41,  -724,  -724,  -724,    12,   296,   333,
    -724,   252,   253,   254,   257,   262,   271,   272,   273,    18,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,    67,
     275,   281,   284,   289,   291,   294,   295,   297,   300,   304,
     305,   310,   313,   314,   315,   319,   322,    19,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,    64,    81,   323,    48,
    -724,  -724,  -724,   141,   163,  -724,   329,    99,  -724,  -724,
     124,  -724,   199,   233,   401,   169,  -724,   303,   419,   352,
     439,   419,   463,   419,   419,   472,   474,   357,  -724,   359,
     358,   366,   367,  -724,   368,   369,   371,   372,   373,   375,
     376,   377,   379,   381,   382,   383,   384,   171,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,   362,   386,   391,   392,
     393,   394,   395,  -724,   396,   397,   404,   405,   406,   407,
     409,   203,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   410,   414,
      63,  -724,  -724,  -724,   487,   416,  -724,  -724,   417,   423,
      45,  -724,  -724,  -724,   447,   419,   541,   419,   419,   450,
     553,   452,   556,   557,   561,   453,   464,   467,   419,   570,
     572,   573,   574,   419,   575,   576,   577,   578,   478,   458,
     459,   482,   419,   419,   483,   486,   488,  -174,  -154,   489,
     490,   491,   492,   589,   419,   493,   419,   419,   495,   485,
    -724,   496,   475,   480,  -724,   484,   494,   502,   503,   506,
     180,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,   507,   508,    69,  -724,  -724,  -724,   498,   510,   511,
    -724,   512,  -724,    35,  -724,  -724,  -724,  -724,  -724,   592,
     595,   516,  -724,   517,   518,   519,    78,  -724,  -724,  -724,
     523,   521,   522,  -724,   526,   527,   529,   530,   532,  -724,
     533,   534,   166,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   539,   537,   538,   540,     2,
    -724,  -724,  -724,  -724,   513,   525,   560,   596,   562,   563,
     564,   419,   547,  -724,  -724,   612,   654,   571,   658,   674,
     675,   662,   663,   664,   665,   677,   679,   681,   682,   684,
     687,   688,   584,  -724,   586,   587,  -724,   117,  -724,  -724,
    -724,  -724,   605,   591,  -724,   590,   597,   593,   599,   600,
     607,   159,  -724,  -724,  -724,  -724,  -724,   704,   617,  -724,
     619,   618,  -724,   621,    83,  -724,  -724,  -724,  -724,   622,
     627,   628,  -724,   630,   330,   632,   633,   634,   636,   637,
     638,   642,   643,   645,  -724,  -724,   719,   770,   419,   651,
     777,   782,   784,   419,   787,   788,   419,   776,   792,   793,
     419,   794,   794,   685,  -724,  -724,   783,  -157,   796,   705,
     798,   800,   692,   802,   803,   808,   804,   805,   806,   807,
     703,  -724,   812,   813,   708,  -724,   709,  -724,   816,   817,
     713,  -724,   714,   721,   722,   723,   724,   726,   731,   732,
     734,   735,   738,   739,   741,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   712,   626,   755,
     756,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     766,   767,   768,   769,   771,   772,   773,   774,   775,  -724,
    -724,   818,   795,   778,   833,   862,   876,   882,   884,   779,
    -724,   886,   888,   785,  -724,  -724,   889,   890,   786,   906,
     790,  -724,   791,   797,  -724,  -724,   893,   894,   799,  -724,
    -724,   898,   811,   801,   900,   901,   902,   904,   819,   809,
     908,   909,   810,  -724,  -724,   911,   912,   913,   814,  -724,
     815,   820,   821,   822,   823,   824,   825,   826,  -724,   827,
     828,   829,   830,   831,   832,   834,   835,   836,   837,   838,
     839,   840,   841,   842,   843,   844,  -724,  -724,   914,   845,
     846,  -724,   847,  -724,     9,  -724,   915,   917,   919,   922,
     849,  -724,   850,  -724,  -724,   923,   848,   924,   852,  -724,
    -724,  -724,  -724,  -724,   419,   419,   419,   419,   419,   419,
     419,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,   853,   854,   855,   -27,   856,   857,   858,   859,
     860,   861,   863,   864,   865,   866,   867,   316,   868,   869,
    -724,   870,   871,   872,   873,   874,   875,   877,    -4,   878,
     879,   880,   881,   885,   887,   891,  -724,   892,   895,  -724,
    -724,   896,   897,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   -86,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   -79,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   899,   903,   292,   905,   907,
     910,   916,   918,  -724,   920,   921,  -724,   925,   926,    16,
     928,   927,  -724,  -724,  -724,  -724,   929,   930,  -724,   932,
     933,   413,   934,   935,   936,   937,   938,   672,   939,   940,
    -724,   941,   942,   943,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
     944,   727,  -724,  -724,   945,   946,   947,  -724,    90,  -724,
    -724,  -724,  -724,   948,   951,   952,   953,  -724,  -724,   954,
     742,   955,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,   -78,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   794,   794,
     794,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,   -70,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   712,  -724,
     626,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,   -67,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,   -32,  -724,   965,
     906,   956,  -724,  -724,  -724,  -724,  -724,   957,  -724,   958,
     959,  -724,  -724,   960,  -724,  -724,  -724,   961,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
     -31,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,   -24,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,   -13,  -724,  -724,
     968,   -73,   964,   969,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
      -6,  -724,  -724,  -724,   -27,  -724,  -724,  -724,  -724,    -4,
    -724,  -724,  -724,   292,  -724,    16,  -724,  -724,  -724,   976,
     931,   982,   981,   984,  -724,   413,  -724,   672,  -724,   727,
     970,   971,   972,   425,  -724,  -724,   742,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
     106,  -724,  -724,  -724,   425,  -724
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   234,   399,   447,     0,
     462,     0,   302,   438,   278,     0,   100,   152,   336,     0,
       0,   377,     0,   109,     0,   353,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   628,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   617,   627,   619,   620,   621,   622,
     623,   624,   618,   625,   626,     0,     0,     0,   460,     0,
       0,   458,   459,     0,   519,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     588,   562,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   473,   474,   475,   517,   518,   512,   513,   514,   515,
     511,   485,   476,   477,   478,   479,   480,   481,   482,   483,
     484,   486,   487,   516,   491,   492,   493,   494,   490,   489,
     495,   502,   503,   496,   497,   498,   488,   500,   509,   510,
     507,   508,   501,   499,   505,   506,   504,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     650,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     641,   642,   643,   644,   645,   648,   646,   647,   649,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   351,     0,     0,   349,   350,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616,     0,
       0,     0,     0,   272,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   237,   238,
     241,   243,   244,   245,   246,   247,   248,   249,   250,   251,
     239,   240,   242,   252,   253,   254,     0,     0,     0,     0,
       0,     0,     0,   427,     0,     0,     0,     0,     0,     0,
       0,     0,   402,   403,   404,   405,   406,   407,   408,   410,
     409,   412,   416,   413,   414,   415,   411,   453,     0,     0,
       0,   450,   451,   452,     0,     0,   457,   468,     0,     0,
       0,   465,   466,   467,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     472,     0,     0,     0,   319,     0,     0,     0,     0,     0,
       0,   305,   306,   307,   308,   313,   309,   310,   311,   312,
     444,     0,     0,     0,   441,   442,   443,     0,     0,     0,
     280,     0,   290,     0,   288,   289,   291,   292,    49,     0,
       0,     0,    45,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,   203,     0,     0,     0,     0,     0,   177,
       0,     0,     0,   155,   156,   157,   158,   159,   162,   163,
     164,   165,   161,   160,   166,     0,     0,     0,     0,     0,
     339,   340,   341,   342,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   640,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,   385,     0,   380,   381,
     382,   127,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   115,   114,   116,     0,     0,   348,
       0,     0,   363,     0,     0,   356,   357,   358,   359,     0,
       0,     0,    90,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   255,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   417,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   401,     0,     0,     0,   449,     0,   456,     0,     0,
       0,   464,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   471,
     314,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     304,     0,     0,     0,   440,   293,     0,     0,     0,     0,
       0,   287,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   343,     0,     0,     0,     0,   338,
       0,     0,     0,     0,     0,     0,     0,     0,   639,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   383,     0,     0,
       0,   379,     0,   122,     0,   117,     0,     0,     0,     0,
       0,   111,     0,   347,   360,     0,     0,     0,     0,   355,
      99,    98,    97,   637,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   638,   629,   630,   631,   632,   633,   634,
     636,   635,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   400,     0,     0,   448,
     461,     0,     0,   463,   532,   536,   520,   521,   551,   523,
     614,   559,   524,   525,   556,   531,   530,   539,   529,   526,
     527,   535,   534,   533,   557,   522,   612,   613,   555,   598,
     592,   608,   593,   594,   595,   603,   611,   596,   605,   609,
     599,   610,   600,   604,   597,   607,   602,   601,   606,     0,
     591,   571,   572,   573,   566,   584,   567,   568,   569,   579,
     587,   570,   581,   585,   575,   586,   576,   580,   574,   583,
     578,   577,   582,     0,   565,   552,   550,   553,   558,   554,
     541,   548,   549,   546,   547,   542,   543,   544,   545,   560,
     561,   528,   538,   537,   540,     0,     0,     0,     0,     0,
       0,     0,     0,   303,     0,     0,   439,     0,     0,     0,
     298,   294,   297,   279,    50,    51,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   337,   652,   651,   657,   655,   658,
     653,   654,   656,    86,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    76,    84,    85,
       0,     0,   378,   128,     0,     0,     0,   140,     0,   132,
     133,   135,   134,     0,     0,     0,     0,   110,   352,     0,
       0,     0,   354,    31,    32,    33,    34,    35,    36,    37,
     267,   268,   259,   277,   276,     0,   275,   260,   262,   264,
     271,   263,   261,   270,   256,   269,   258,   257,    38,    38,
      38,    40,    39,   265,   266,   422,   425,   426,   436,   433,
     419,   434,   431,   432,     0,   430,   435,   418,   424,   421,
     423,   437,   420,   454,   455,   469,   470,   589,     0,   563,
       0,   317,   318,   328,   324,   325,   327,   332,   329,   330,
     323,   331,   326,     0,   322,   316,   335,   334,   333,   315,
     446,   445,   301,   300,   285,   286,   284,     0,   283,     0,
       0,     0,   107,   108,   176,   172,   222,   210,   219,     0,
     208,   213,   228,     0,   221,   226,   232,   212,   215,   223,
     225,   229,   220,   227,   216,   233,   218,   224,   214,   217,
       0,   206,   168,   170,   173,   174,   175,   186,   187,   188,
     181,   199,   182,   183,   184,   194,   202,   185,   196,   200,
     190,   201,   191,   195,   189,   198,   193,   192,   197,     0,
     180,   169,   171,   346,   344,   345,   384,   389,   395,   398,
     391,   397,   392,   396,   394,   390,   393,     0,   388,   136,
       0,     0,     0,     0,   131,   119,   118,   120,   121,   361,
     367,   373,   376,   369,   375,   370,   374,   372,   368,   371,
       0,   366,   362,   273,     0,    41,    42,    43,   428,     0,
     590,   564,   320,     0,   281,     0,   299,   296,   295,     0,
       0,     0,     0,     0,   204,     0,   178,     0,   386,     0,
       0,     0,     0,     0,   130,   364,     0,   274,   429,   321,
     282,   209,   231,   207,   230,   211,   205,   179,   387,   137,
     139,   138,   150,   149,   145,   147,   151,   148,   144,   146,
       0,   143,   365,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -724,  -724,  -724,  -243,  -296,  -723,  -621,  -724,  -724,   973,
    -724,  -724,  -724,  -724,   949,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,   967,  -724,  -724,  -724,  -724,  -724,
    -724,   625,  -724,  -724,  -724,  -724,  -724,   454,  -724,  -724,
    -724,  -724,  -724,  -724,   950,  -724,  -724,  -724,  -724,    85,
    -724,  -724,  -724,  -724,  -724,  -180,  -724,  -724,  -724,   613,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -139,  -724,  -724,  -724,  -136,  -724,  -724,  -724,
     962,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -111,  -724,  -724,  -724,  -724,  -724,  -120,  -724,   653,  -724,
    -724,  -724,    -1,  -724,  -724,  -724,  -724,  -724,   683,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -116,  -724,  -724,  -724,
    -724,  -724,  -724,   615,  -724,  -724,  -724,  -724,  -724,   851,
    -724,  -724,  -724,  -724,   552,  -724,  -724,  -724,  -724,  -724,
    -135,  -724,  -724,  -724,   580,  -724,  -724,  -724,  -724,  -119,
    -724,  -724,  -724,   963,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -100,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,   686,  -724,  -724,  -724,  -724,  -724,
     966,  -724,  -724,  -724,  -724,  1034,  -724,  -724,  -724,  -724,
     781,  -724,  -724,  -724,  -724,   987,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,    52,
    -724,  -724,  -724,    55,  -724,  -724,  -724,  -724,  -724,  1055,
    -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724,  -724,   974,  -724,  -724,  -724,  -724,  -724,  -724,  -724,
    -724
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   811,   812,  1071,  1072,    27,   213,   214,
     215,   216,    28,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,    29,    77,    78,    79,    80,    81,    30,    63,
     486,   487,   488,   489,    31,    70,   571,   572,   573,   574,
     575,   576,    32,   279,   280,   281,   282,   283,  1028,  1029,
    1030,  1031,  1032,  1212,  1290,  1291,    33,    64,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     739,  1189,  1190,   514,   733,  1160,  1161,    34,    53,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   609,  1055,
    1056,    35,    61,   472,   718,  1127,  1128,   473,   474,   475,
    1131,   971,   972,   476,   477,    36,    59,   450,   451,   452,
     453,   454,   455,   456,   703,  1113,  1114,   457,   458,   459,
      37,    65,   519,   520,   521,   522,   523,    38,   287,   288,
     289,    39,    72,   584,   585,   586,   587,   588,   796,  1230,
    1231,    40,    68,   557,   558,   559,   560,   779,  1207,  1208,
      41,    54,   361,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   632,  1084,  1085,   372,   373,   374,   375,
     376,    42,    60,   463,   464,   465,   466,    43,    55,   380,
     381,   382,   383,    44,   110,   111,   112,    45,    57,   390,
     391,   392,   393,    46,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   420,   933,   934,
     203,   419,   909,   910,   204,   205,   206,    47,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
      48,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     838,   839,   595,   515,  1082,   598,    51,   600,   601,    52,
    1024,    49,    50,   483,   285,   108,   377,   842,   843,   220,
     239,  1053,   114,    56,   108,   387,    58,   115,   116,   460,
     117,   118,   837,   685,    62,   119,   467,   686,   210,    66,
      67,   516,   210,   120,   121,   240,   387,   241,    73,   277,
     221,   122,    69,   687,   123,   124,   125,   688,    71,   222,
    1124,   126,   223,   224,   377,   554,   105,   225,   226,   227,
     460,   106,   242,   109,   378,    74,   127,   128,   517,   483,
     107,   243,   109,    75,   580,   113,   129,   468,   484,   130,
     131,  1024,   228,  1054,   469,   207,   470,   208,   132,   653,
     285,   655,   656,   277,   244,   133,  1025,   134,   245,   135,
     286,   136,   666,   137,   138,   209,   246,   671,   554,   247,
     248,   388,   378,   518,   139,   580,   680,   681,  1261,   140,
     141,   211,   142,   143,   144,   211,   379,   145,   694,  1097,
     696,   697,   388,  1098,    76,   389,  1099,  1233,   249,   461,
    1100,  1234,   212,   471,   484,  1238,   212,   291,  1242,  1239,
     566,   555,  1243,   146,   566,   250,   389,   490,   251,   252,
     253,   217,   309,   147,   148,   149,   150,   151,   152,   153,
     581,   441,   485,   218,   379,   491,   219,  1025,   310,   311,
     461,  1083,   312,  1244,  1254,   292,   286,  1245,  1255,   442,
    1026,  1256,  1125,   492,   346,  1257,   347,   276,   348,   284,
     290,  1126,  1258,    82,   555,   254,  1259,   443,  -129,  1265,
     293,   581,   349,  1266,  1027,   294,   297,   493,   748,   154,
     155,   156,   313,   157,   158,   757,    83,    84,   255,   256,
     350,   444,   159,    85,   532,   552,   462,   439,   485,   385,
     314,   315,   316,   317,   318,   351,   567,   352,   319,   298,
     567,   720,   320,   494,   353,   278,   299,   481,   321,    86,
      87,   650,  -129,   295,   563,   478,   354,   322,   323,   556,
     495,  1026,    88,    89,    90,   300,   301,   462,   324,   644,
      91,    92,   534,   302,   445,   713,   496,   490,   582,   303,
     355,   583,   446,   447,   728,  1027,   561,  1103,   304,   798,
     325,   565,   824,   497,   498,   491,  1213,   829,   589,   278,
     832,   356,   568,   448,   836,   578,   568,  1068,  1069,  1070,
    1104,  1293,   556,   492,   515,  1294,   305,   306,    73,   582,
     569,   357,   583,   780,   569,  1235,  1236,  1237,   384,   394,
     358,   346,   590,   347,   326,   348,   570,   493,   395,  1105,
     570,   396,   397,   398,   499,    74,   399,   400,   401,   349,
     402,   441,   516,    75,   403,   404,   405,   406,   407,   467,
     408,   409,   410,   411,   500,   790,   412,   350,   501,   442,
    1106,  1107,   742,   494,   592,   413,  1108,   623,   449,   359,
     414,   415,   351,   416,   352,   417,   709,   443,   593,   517,
     495,   353,   418,   421,   422,   423,   424,  1136,   425,   114,
    1109,   837,   360,   354,   115,   116,   496,   117,   118,   640,
     468,   444,   119,  1137,    76,   594,  1110,   469,   307,   470,
     120,   121,  1138,   497,   498,   426,   427,   355,   122,   428,
     429,   123,   124,   125,   518,   430,   431,   432,   126,   433,
     434,   804,   805,   806,   807,   808,   809,   810,   356,   435,
     436,   437,   438,   127,   128,   479,  1139,  1140,   480,  1141,
     524,   525,   526,   129,   445,   527,   130,   131,   357,  1282,
     528,  1283,   446,   447,   499,   132,   471,   358,  1111,   529,
     530,   531,   133,   535,   134,   220,   135,  1142,   136,   536,
     137,   138,   537,   448,   500,  1143,  1112,   538,   501,   539,
     591,   139,   540,   541,   594,   542,   140,   141,   543,   142,
     143,   144,   544,   545,   145,  1284,   221,  1144,   546,  1145,
    1146,   547,   548,   549,   597,   222,   359,   550,   223,   224,
     551,   562,  1285,   225,   226,   227,   239,   577,  1147,   596,
     146,  1043,  1044,  1045,  1046,  1047,  1048,  1049,   599,   360,
     147,   148,   149,   150,   151,   152,   153,   602,   228,   603,
    1148,   240,   604,   241,   605,  1149,   606,   625,   449,  1150,
    1262,  1286,  1287,  1151,   607,   608,   610,   611,  1152,   612,
     613,   614,  1153,   615,   616,   617,   646,   618,   242,   619,
     620,   621,   622,  1154,   626,  1155,  1156,   243,  1157,   627,
     628,   629,   630,   631,   633,   634,   154,   155,   156,  1158,
     157,   158,   635,   636,   637,   638,  1159,   639,   642,   159,
     244,   647,   643,  1288,   245,   648,   654,   309,  1289,     2,
       3,   649,   246,     4,   652,   247,   248,   657,   658,   659,
     663,   660,   661,   310,   311,     5,   662,   312,     6,     7,
     911,   664,   912,   913,   665,   667,     8,   668,   669,   670,
     672,   673,   674,   675,   249,   676,   677,   678,     9,   679,
     682,    10,    11,   683,   693,   684,   689,   690,   691,   692,
     695,   250,   698,   701,   251,   252,   253,   313,   702,    12,
     699,   722,   704,    13,   723,   753,  1167,   759,  1168,  1169,
     750,   700,   705,   715,    14,   314,   315,   316,   317,   318,
     706,   707,   751,   319,   708,   711,   712,   320,   716,   717,
     719,   724,   725,   321,    15,    16,   726,   727,   730,   731,
     732,   254,   322,   323,   734,   735,   889,   736,   737,    17,
     738,   740,   741,   324,   744,   745,   746,   752,   747,   754,
     755,   756,   758,   760,   255,   256,    18,   762,   761,   763,
     764,   765,   766,   767,   768,   325,   914,   915,   916,    19,
      20,   917,   918,  1197,   919,   920,   769,   921,   770,   922,
     771,   772,   923,   773,   924,   925,   774,   775,  1220,   776,
     926,   777,   782,    21,   927,   778,   783,   784,   928,   929,
     930,   786,   785,   792,   822,   931,    22,   787,   788,   326,
     932,    23,  1170,  1171,  1172,   789,    24,  1173,  1174,    25,
    1175,  1176,   793,  1177,   794,  1178,   795,   800,  1179,   797,
    1180,  1181,   801,   802,  1198,   803,  1182,   813,   814,   815,
    1183,   816,   817,   818,  1184,  1185,  1186,   819,   820,  1221,
     821,  1187,   890,   891,   892,   823,  1188,   893,   894,   825,
     895,   896,   826,   897,    82,   898,  1199,   827,   899,   828,
     900,   901,   830,   831,  1200,   833,   902,   834,   835,   837,
     903,  1222,   841,  1201,   904,   905,   906,    83,    84,  1223,
     840,   907,   845,   851,    85,   844,   908,   846,  1224,   847,
     848,   849,   850,   852,   853,   854,   855,  1202,   856,  1203,
    1204,   857,   858,   859,   860,   861,   862,   955,   863,   864,
      86,    87,  1225,  1205,  1226,  1227,   865,   866,   867,   868,
    1206,   869,   958,    88,    89,    90,   870,   871,  1228,   872,
     873,    91,    92,   874,   875,  1229,   876,   959,   877,   878,
     879,   880,   881,   882,   883,   884,   885,   886,   887,   888,
     935,   936,   937,   938,   939,   940,   941,   942,   943,   944,
     945,   946,   947,   948,   949,   960,   950,   951,   952,   953,
     954,   961,   956,   962,   963,   964,   957,   965,   967,   968,
     966,   970,   976,   977,   969,   973,   974,   979,   980,   982,
     983,   984,   975,   985,   978,   791,   986,   988,   989,   981,
     991,   992,   993,  1020,  1033,   990,  1034,   987,  1035,   994,
     995,  1036,  1039,  1041,   296,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1272,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,
    1246,  1022,  1023,  1021,  1037,  1038,  1040,  1042,  1050,  1051,
    1052,  1057,  1058,  1059,  1060,  1061,  1062,  1260,  1063,  1064,
    1065,  1066,  1067,  1073,  1074,  1075,  1076,  1077,  1078,  1079,
    1080,  1271,  1081,  1086,  1087,  1088,  1089,  1273,  1274,  1275,
    1090,   729,  1091,  1214,  1295,   743,  1092,  1093,  1277,  1276,
    1094,  1095,  1096,  1267,  1101,  1270,   721,  1269,  1102,  1247,
    1115,  1292,  1116,   710,   749,  1117,   799,   781,   579,  1268,
    1278,  1118,  1129,  1119,   386,  1120,  1121,   440,   308,   714,
    1122,  1123,  1241,  1240,  1132,  1133,  1130,  1134,  1135,  1162,
    1163,  1164,  1165,  1166,  1191,  1192,  1193,  1194,  1195,  1196,
    1209,   651,     0,  1215,  1210,  1211,  1216,  1217,  1218,  1219,
    1232,  1248,     0,     0,     0,     0,   482,  1249,  1250,  1251,
    1252,  1253,  1263,     0,  1264,  1279,  1280,  1281,     0,     0,
       0,     0,     0,   533,     0,     0,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   624,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   641,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   645
};

static const yytype_int16 yycheck[] =
{
     621,   622,   298,     1,     8,   301,   227,   303,   304,   227,
       1,   225,   226,     1,     1,     1,     1,   174,   175,     1,
       1,    48,     1,   227,     1,     1,   227,     6,     7,     1,
       9,    10,   105,   207,   227,    14,     1,   211,     1,   227,
     227,    39,     1,    22,    23,    26,     1,    28,     1,     1,
      32,    30,   227,   207,    33,    34,    35,   211,   227,    41,
      44,    40,    44,    45,     1,     1,   227,    49,    50,    51,
       1,   227,    53,    59,    59,    28,    55,    56,    76,     1,
     227,    62,    59,    36,     1,   227,    65,    52,    76,    68,
      69,     1,    74,   120,    59,   227,    61,   227,    77,   395,
       1,   397,   398,     1,    85,    84,    97,    86,    89,    88,
      97,    90,   408,    92,    93,   227,    97,   413,     1,   100,
     101,    97,    59,   121,   103,     1,   422,   423,   201,   108,
     109,    94,   111,   112,   113,    94,   121,   116,   434,   225,
     436,   437,    97,   229,    97,   121,   225,   225,   129,   121,
     229,   229,   115,   118,    76,   225,   115,   225,   225,   229,
       1,    97,   229,   142,     1,   146,   121,     1,   149,   150,
     151,   227,     1,   152,   153,   154,   155,   156,   157,   158,
      97,     1,   170,   227,   121,    19,   227,    97,    17,    18,
     121,   195,    21,   225,   225,   228,    97,   229,   229,    19,
     191,   225,   186,    37,     1,   229,     3,   227,     5,   227,
     227,   195,   225,     1,    97,   196,   229,    37,   170,   225,
     228,    97,    19,   229,   215,   228,   228,    61,   226,   208,
     209,   210,    61,   212,   213,   531,    24,    25,   219,   220,
      37,    61,   221,    31,   226,   226,   218,   226,   170,   226,
      79,    80,    81,    82,    83,    52,    97,    54,    87,   228,
      97,   226,    91,    97,    61,   217,   228,   226,    97,    57,
      58,   226,   170,   226,   226,   225,    73,   106,   107,   215,
     114,   191,    70,    71,    72,   228,   228,   218,   117,   226,
      78,    79,   225,   228,   114,   226,   130,     1,   215,   228,
      97,   218,   122,   123,   226,   215,   225,    15,   228,   226,
     139,   170,   608,   147,   148,    19,   226,   613,   119,   217,
     616,   118,   163,   143,   620,   226,   163,    11,    12,    13,
      38,   225,   215,    37,     1,   229,   228,   228,     1,   215,
     181,   138,   218,   226,   181,  1068,  1069,  1070,   228,   228,
     147,     1,   119,     3,   183,     5,   197,    61,   228,    67,
     197,   228,   228,   228,   198,    28,   228,   228,   228,    19,
     228,     1,    39,    36,   228,   228,   228,   228,   228,     1,
     228,   228,   228,   228,   218,   226,   228,    37,   222,    19,
      98,    99,   226,    97,   225,   228,   104,   226,   218,   196,
     228,   228,    52,   228,    54,   228,   226,    37,   105,    76,
     114,    61,   228,   228,   228,   228,   228,     4,   228,     1,
     128,   105,   219,    73,     6,     7,   130,     9,    10,   226,
      52,    61,    14,    20,    97,   105,   144,    59,   226,    61,
      22,    23,    29,   147,   148,   228,   228,    97,    30,   228,
     228,    33,    34,    35,   121,   228,   228,   228,    40,   228,
     228,   131,   132,   133,   134,   135,   136,   137,   118,   228,
     228,   228,   228,    55,    56,   228,    63,    64,   228,    66,
     228,   228,   228,    65,   114,   228,    68,    69,   138,    64,
     228,    66,   122,   123,   198,    77,   118,   147,   206,   228,
     228,   228,    84,   228,    86,     1,    88,    94,    90,   228,
      92,    93,   228,   143,   218,   102,   224,   228,   222,   228,
     119,   103,   228,   228,   105,   228,   108,   109,   228,   111,
     112,   113,   228,   228,   116,   110,    32,   124,   228,   126,
     127,   228,   228,   228,   105,    41,   196,   228,    44,    45,
     228,   228,   127,    49,    50,    51,     1,   228,   145,   207,
     142,   804,   805,   806,   807,   808,   809,   810,   105,   219,
     152,   153,   154,   155,   156,   157,   158,   105,    74,   105,
     167,    26,   225,    28,   225,   172,   228,   225,   218,   176,
    1211,   166,   167,   180,   228,   228,   228,   228,   185,   228,
     228,   228,   189,   228,   228,   228,   119,   228,    53,   228,
     228,   228,   228,   200,   228,   202,   203,    62,   205,   228,
     228,   228,   228,   228,   228,   228,   208,   209,   210,   216,
     212,   213,   228,   228,   228,   228,   223,   228,   228,   221,
      85,   225,   228,   218,    89,   228,   105,     1,   223,     0,
       1,   228,    97,     4,   207,   100,   101,   207,   105,   207,
     207,   105,   105,    17,    18,    16,   105,    21,    19,    20,
      44,   207,    46,    47,   207,   105,    27,   105,   105,   105,
     105,   105,   105,   105,   129,   207,   228,   228,    39,   207,
     207,    42,    43,   207,   105,   207,   207,   207,   207,   207,
     207,   146,   207,   228,   149,   150,   151,    61,   228,    60,
     225,   119,   228,    64,   119,   119,    44,   105,    46,    47,
     207,   225,   228,   225,    75,    79,    80,    81,    82,    83,
     228,   228,   207,    87,   228,   228,   228,    91,   228,   228,
     228,   225,   225,    97,    95,    96,   228,   228,   225,   228,
     228,   196,   106,   107,   228,   228,    44,   228,   228,   110,
     228,   228,   228,   117,   225,   228,   228,   207,   228,   207,
     207,   207,   225,   119,   219,   220,   127,   119,   207,   105,
     105,   119,   119,   119,   119,   139,   160,   161,   162,   140,
     141,   165,   166,    66,   168,   169,   119,   171,   119,   173,
     119,   119,   176,   119,   178,   179,   119,   119,    66,   225,
     184,   225,   207,   164,   188,   228,   225,   227,   192,   193,
     194,   228,   225,   119,   105,   199,   177,   228,   228,   183,
     204,   182,   160,   161,   162,   228,   187,   165,   166,   190,
     168,   169,   225,   171,   225,   173,   228,   225,   176,   228,
     178,   179,   225,   225,   127,   225,   184,   225,   225,   225,
     188,   225,   225,   225,   192,   193,   194,   225,   225,   127,
     225,   199,   160,   161,   162,   105,   204,   165,   166,   228,
     168,   169,   105,   171,     1,   173,   159,   105,   176,   105,
     178,   179,   105,   105,   167,   119,   184,   105,   105,   105,
     188,   159,   119,   176,   192,   193,   194,    24,    25,   167,
     225,   199,   207,   105,    31,   119,   204,   119,   176,   119,
     228,   119,   119,   119,   119,   119,   119,   200,   225,   202,
     203,   119,   119,   225,   225,   119,   119,   119,   225,   225,
      57,    58,   200,   216,   202,   203,   225,   225,   225,   225,
     223,   225,   119,    70,    71,    72,   225,   225,   216,   225,
     225,    78,    79,   225,   225,   223,   225,   105,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   119,   225,   225,   225,   225,
     225,   119,   207,   119,   225,   119,   228,   119,   119,   119,
     225,   105,   119,   119,   228,   225,   225,   119,   207,   119,
     119,   119,   225,   119,   225,   571,   207,   119,   119,   228,
     119,   119,   119,   119,   119,   225,   119,   228,   119,   225,
     225,   119,   119,   119,    77,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   127,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     105,   225,   225,   228,   225,   225,   228,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   119,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   125,   225,   225,   225,   225,   225,   125,   127,   125,
     225,   486,   225,  1028,  1294,   502,   225,   225,  1257,  1255,
     225,   225,   225,  1234,   225,  1245,   473,  1243,   225,  1130,
     225,  1266,   225,   450,   519,   225,   584,   557,   287,  1239,
    1259,   225,   214,   225,   110,   225,   225,   160,    93,   463,
     225,   225,  1100,  1098,   225,   225,   229,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   390,    -1,   225,   228,   228,   225,   225,   225,   225,
     225,   225,    -1,    -1,    -1,    -1,   213,   230,   230,   230,
     230,   230,   228,    -1,   225,   225,   225,   225,    -1,    -1,
      -1,    -1,    -1,   229,    -1,    -1,   257,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   279,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   327,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   361,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   380
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   232,     0,     1,     4,    16,    19,    20,    27,    39,
      42,    43,    60,    64,    75,    95,    96,   110,   127,   140,
     141,   164,   177,   182,   187,   190,   233,   238,   243,   263,
     269,   275,   283,   297,   318,   342,   356,   371,   378,   382,
     392,   401,   422,   428,   434,   438,   444,   498,   511,   225,
     226,   227,   227,   319,   402,   429,   227,   439,   227,   357,
     423,   343,   227,   270,   298,   372,   227,   227,   393,   227,
     276,   227,   383,     1,    28,    36,    97,   264,   265,   266,
     267,   268,     1,    24,    25,    31,    57,    58,    70,    71,
      72,    78,    79,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   227,   227,   227,     1,    59,
     435,   436,   437,   227,     1,     6,     7,     9,    10,    14,
      22,    23,    30,    33,    34,    35,    40,    55,    56,    65,
      68,    69,    77,    84,    86,    88,    90,    92,    93,   103,
     108,   109,   111,   112,   113,   116,   142,   152,   153,   154,
     155,   156,   157,   158,   208,   209,   210,   212,   213,   221,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   491,   495,   496,   497,   227,   227,   227,
       1,    94,   115,   239,   240,   241,   242,   227,   227,   227,
       1,    32,    41,    44,    45,    49,    50,    51,    74,   512,
     513,   514,   515,   516,   517,   518,   519,   520,   521,     1,
      26,    28,    53,    62,    85,    89,    97,   100,   101,   129,
     146,   149,   150,   151,   196,   219,   220,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   227,     1,   217,   284,
     285,   286,   287,   288,   227,     1,    97,   379,   380,   381,
     227,   225,   228,   228,   228,   226,   265,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   500,     1,
      17,    18,    21,    61,    79,    80,    81,    82,    83,    87,
      91,    97,   106,   107,   117,   139,   183,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,     1,     3,     5,    19,
      37,    52,    54,    61,    73,    97,   118,   138,   147,   196,
     219,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   417,   418,   419,   420,   421,     1,    59,   121,
     430,   431,   432,   433,   228,   226,   436,     1,    97,   121,
     440,   441,   442,   443,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   492,
     488,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   226,
     446,     1,    19,    37,    61,   114,   122,   123,   143,   218,
     358,   359,   360,   361,   362,   363,   364,   368,   369,   370,
       1,   121,   218,   424,   425,   426,   427,     1,    52,    59,
      61,   118,   344,   348,   349,   350,   354,   355,   225,   228,
     228,   226,   240,     1,    76,   170,   271,   272,   273,   274,
       1,    19,    37,    61,    97,   114,   130,   147,   148,   198,
     218,   222,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   314,     1,    39,    76,   121,   373,
     374,   375,   376,   377,   228,   228,   228,   228,   228,   228,
     228,   228,   226,   513,   225,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   226,   245,     1,    97,   215,   394,   395,   396,
     397,   225,   228,   226,   285,   170,     1,    97,   163,   181,
     197,   277,   278,   279,   280,   281,   282,   228,   226,   380,
       1,    97,   215,   218,   384,   385,   386,   387,   388,   119,
     119,   119,   225,   105,   105,   235,   207,   105,   235,   105,
     235,   235,   105,   105,   225,   225,   228,   228,   228,   339,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   226,   321,   225,   228,   228,   228,   228,
     228,   228,   414,   228,   228,   228,   228,   228,   228,   228,
     226,   404,   228,   228,   226,   431,   119,   225,   228,   228,
     226,   441,   207,   235,   105,   235,   235,   207,   105,   207,
     105,   105,   105,   207,   207,   207,   235,   105,   105,   105,
     105,   235,   105,   105,   105,   105,   207,   228,   228,   207,
     235,   235,   207,   207,   207,   207,   211,   207,   211,   207,
     207,   207,   207,   105,   235,   207,   235,   235,   207,   225,
     225,   228,   228,   365,   228,   228,   228,   228,   228,   226,
     359,   228,   228,   226,   425,   225,   228,   228,   345,   228,
     226,   349,   119,   119,   225,   225,   228,   228,   226,   272,
     225,   228,   228,   315,   228,   228,   228,   228,   228,   311,
     228,   228,   226,   300,   225,   228,   228,   228,   226,   374,
     207,   207,   207,   119,   207,   207,   207,   235,   225,   105,
     119,   207,   119,   105,   105,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   225,   225,   228,   398,
     226,   395,   207,   225,   227,   225,   228,   228,   228,   228,
     226,   278,   119,   225,   225,   228,   389,   228,   226,   385,
     225,   225,   225,   225,   131,   132,   133,   134,   135,   136,
     137,   234,   235,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   105,   105,   235,   228,   105,   105,   105,   235,
     105,   105,   235,   119,   105,   105,   235,   105,   237,   237,
     225,   119,   174,   175,   119,   207,   119,   119,   228,   119,
     119,   105,   119,   119,   119,   119,   225,   119,   119,   225,
     225,   119,   119,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,    44,
     160,   161,   162,   165,   166,   168,   169,   171,   173,   176,
     178,   179,   184,   188,   192,   193,   194,   199,   204,   493,
     494,    44,    46,    47,   160,   161,   162,   165,   166,   168,
     169,   171,   173,   176,   178,   179,   184,   188,   192,   193,
     194,   199,   204,   489,   490,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   119,   207,   228,   119,   105,
     119,   119,   119,   225,   119,   119,   225,   119,   119,   228,
     105,   352,   353,   225,   225,   225,   119,   119,   225,   119,
     207,   228,   119,   119,   119,   119,   207,   228,   119,   119,
     225,   119,   119,   119,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     119,   228,   225,   225,     1,    97,   191,   215,   289,   290,
     291,   292,   293,   119,   119,   119,   119,   225,   225,   119,
     228,   119,   225,   234,   234,   234,   234,   234,   234,   234,
     225,   225,   225,    48,   120,   340,   341,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,    11,    12,
      13,   236,   237,   225,   225,   225,   225,   225,   225,   225,
     225,   225,     8,   195,   415,   416,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   229,   225,
     229,   225,   225,    15,    38,    67,    98,    99,   104,   128,
     144,   206,   224,   366,   367,   225,   225,   225,   225,   225,
     225,   225,   225,   225,    44,   186,   195,   346,   347,   214,
     229,   351,   225,   225,   225,   225,     4,    20,    29,    63,
      64,    66,    94,   102,   124,   126,   127,   145,   167,   172,
     176,   180,   185,   189,   200,   202,   203,   205,   216,   223,
     316,   317,   225,   225,   225,   225,   225,    44,    46,    47,
     160,   161,   162,   165,   166,   168,   169,   171,   173,   176,
     178,   179,   184,   188,   192,   193,   194,   199,   204,   312,
     313,   225,   225,   225,   225,   225,   225,    66,   127,   159,
     167,   176,   200,   202,   203,   216,   223,   399,   400,   225,
     228,   228,   294,   226,   290,   225,   225,   225,   225,   225,
      66,   127,   159,   167,   176,   200,   202,   203,   216,   223,
     390,   391,   225,   225,   229,   236,   236,   236,   225,   229,
     494,   490,   225,   229,   225,   229,   105,   353,   225,   230,
     230,   230,   230,   230,   225,   229,   225,   229,   225,   229,
     119,   201,   237,   228,   225,   225,   229,   341,   416,   367,
     347,   125,   127,   125,   127,   125,   317,   313,   400,   225,
     225,   225,    64,    66,   110,   127,   166,   167,   218,   223,
     295,   296,   391,   225,   229,   296
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   231,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   234,   234,
     235,   235,   235,   235,   235,   235,   235,   235,   236,   236,
     237,   237,   237,   237,   238,   239,   239,   240,   240,   240,
     241,   242,   243,   244,   244,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   264,   265,   265,   265,   265,   266,   267,   268,
     270,   269,   271,   271,   272,   272,   272,   273,   274,   276,
     275,   277,   277,   278,   278,   278,   278,   278,   279,   280,
     281,   282,   283,   284,   284,   285,   285,   285,   286,   288,
     287,   289,   289,   290,   290,   290,   290,   291,   292,   292,
     294,   293,   295,   295,   296,   296,   296,   296,   296,   296,
     296,   296,   298,   297,   299,   299,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   311,   310,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   315,   314,   316,   316,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   319,   318,   320,   320,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   339,   338,   340,   340,   341,   341,   343,   342,
     345,   344,   346,   346,   347,   347,   347,   348,   348,   349,
     349,   349,   349,   349,   351,   350,   352,   352,   353,   353,
     354,   355,   357,   356,   358,   358,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   360,   361,   362,   363,   365,
     364,   366,   366,   367,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   368,   369,   370,   372,   371,   373,   373,
     374,   374,   374,   374,   375,   376,   377,   378,   379,   379,
     380,   380,   381,   383,   382,   384,   384,   385,   385,   385,
     385,   386,   387,   389,   388,   390,   390,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,   393,   392,   394,
     394,   395,   395,   395,   396,   398,   397,   399,   399,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   402,
     401,   403,   403,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   404,   404,   405,   406,
     407,   408,   409,   410,   411,   412,   412,   414,   413,   415,
     415,   416,   416,   417,   418,   419,   420,   421,   423,   422,
     424,   424,   425,   425,   425,   426,   427,   429,   428,   430,
     430,   431,   431,   431,   432,   433,   434,   435,   435,   436,
     436,   437,   439,   438,   440,   440,   441,   441,   441,   442,
     443,   444,   445,   445,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   473,   474,   474,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   488,   487,   489,   489,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   492,   491,
     493,   493,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   495,   496,   497,   498,   499,   499,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   512,   513,   513,   513,   513,   513,   513,   513,   513,
     513,   514,   515,   516,   517,   518,   519,   520,   521
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
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     2,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     2,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     1,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     5,     2,     1,
       1,     1,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     2,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
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
  unsigned long int yylno = yyrline[yyrule];
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
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
            /* Fall through.  */
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

  return yystpcpy (yyres, yystr) - yyres;
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
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
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
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

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
| yyreduce -- Do a reduction.  |
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
#line 412 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2861 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2867 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2879 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2885 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2897 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2915 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2933 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2951 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 73:
#line 477 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if (!ConfigServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_chain_file(ConfigServerInfo.server_ctx, yylval.string) <= 0 ||
        SSL_CTX_use_certificate_chain_file(ConfigServerInfo.client_ctx, yylval.string) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ConfigServerInfo.server_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ConfigServerInfo.client_ctx, ConfigServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ConfigServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ConfigServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
#line 2994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 74:
#line 517 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (ConfigServerInfo.rsa_private_key)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;
  }

  if (ConfigServerInfo.rsa_private_key_file)
  {
    MyFree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = NULL;
  }

  ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);

  if ((file = BIO_new_file(yylval.string, "r")) == NULL)
  {
    conf_error_report("File open failed, ignoring");
    break;
  }

  ConfigServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

  BIO_set_close(file, BIO_CLOSE);
  BIO_free(file);

  if (ConfigServerInfo.rsa_private_key == NULL)
  {
    conf_error_report("Couldn't extract key, ignoring");
    break;
  }

  if (!RSA_check_key(ConfigServerInfo.rsa_private_key))
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Invalid key, ignoring");
    break;
  }

  if (RSA_size(ConfigServerInfo.rsa_private_key) < 128)
  {
    RSA_free(ConfigServerInfo.rsa_private_key);
    ConfigServerInfo.rsa_private_key = NULL;

    conf_error_report("Ignoring serverinfo::rsa_private_key_file -- need at least a 1024 bit key size");
  }
#endif
}
#line 3055 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 75:
#line 575 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file = BIO_new_file(yylval.string, "r");

    if (file)
    {
      DH *dh = PEM_read_bio_DHparams(file, NULL, NULL, NULL);

      BIO_free(file);

      if (dh)
      {
        if (DH_size(dh) < 128)
          conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ConfigServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
    else
      conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- could not open/read Diffie-Hellman parameter file");
  }
#endif
}
#line 3087 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 604 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 77:
#line 612 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    if ((ConfigServerInfo.message_digest_algorithm = EVP_get_digestbyname(yylval.string)) == NULL)
    {
      ConfigServerInfo.message_digest_algorithm = EVP_sha256();
      conf_error_report("Ignoring serverinfo::ssl_message_digest_algorithm -- unknown message digest algorithm");
    }
  }
#endif
}
#line 3115 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 78:
#line 626 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
#if OPENSSL_VERSION_NUMBER >= 0x009080FFL && !defined(OPENSSL_NO_ECDH)
  int nid = 0;
  EC_KEY *key = NULL;

  if (conf_parser_ctx.pass == 2)
  {
    if ((nid = OBJ_sn2nid(yylval.string)) == 0)
    {
        conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- unknown curve name");
        break;
    }

    if ((key = EC_KEY_new_by_curve_name(nid)) == NULL)
    {
      conf_error_report("Ignoring serverinfo::ssl_dh_elliptic_curve -- could not create curve");
      break;
    }

    SSL_CTX_set_tmp_ecdh(ConfigServerInfo.server_ctx, key);
    EC_KEY_free(key);
}
#endif
#endif
}
#line 3146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 79:
#line 654 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ConfigServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
#line 3164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 80:
#line 669 "conf_parser.y" /* yacc.c:1646  */
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ConfigServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ConfigServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
#line 3182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 81:
#line 684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3195 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 82:
#line 694 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')))
      *p = '\0';

    MyFree(ConfigServerInfo.network_name);
    ConfigServerInfo.network_name = xstrdup(yylval.string);
  }
}
#line 3212 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 84:
#line 717 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
#line 3255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 85:
#line 745 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res);

      memcpy(&ConfigServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ConfigServerInfo.ip6.ss.ss_family = res->ai_family;
      ConfigServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ConfigServerInfo.specific_ipv6_vhost = 1;
    }
  }
}
#line 3286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 86:
#line 773 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE] = "";

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ConfigServerInfo.default_max_clients = MAXCLIENTS_MAX;
  }
  else
    ConfigServerInfo.default_max_clients = (yyvsp[-1].number);
}
#line 3314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 87:
#line 798 "conf_parser.y" /* yacc.c:1646  */
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
#line 3339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 88:
#line 820 "conf_parser.y" /* yacc.c:1646  */
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
#line 3364 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3373 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3385 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3409 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3418 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 101:
#line 893 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3435 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3444 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3453 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 110:
#line 929 "conf_parser.y" /* yacc.c:1646  */
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
#line 3480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 121:
#line 965 "conf_parser.y" /* yacc.c:1646  */
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
#line 3528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3537 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1002 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3559 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3570 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3586 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3595 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3604 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3613 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3622 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3667 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3679 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1086 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!block_state.file.buf[0] &&
      !block_state.rpass.buf[0])
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf         = conf_make(CONF_OPER);
    conf->name   = xstrdup(block_state.name.buf);
    conf->user   = xstrdup(block_state.user.buf);
    conf->host   = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    if (block_state.whois.buf[0])
      conf->whois = xstrdup(block_state.whois.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);

#ifdef HAVE_LIBCRYPTO
    if (block_state.file.buf[0])
    {
      BIO *file = NULL;
      RSA *pkey = NULL;

      if ((file = BIO_new_file(block_state.file.buf, "r")) == NULL)
      {
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key invalid; check key syntax");
      else
      {
        if (RSA_size(pkey) > 128)
          ilog(LOG_TYPE_IRCD, "Ignoring rsa_public_key_file -- key size must be 1024 or below");
        else
          conf->rsa_public_key = pkey;
      }

      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
#line 3764 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3782 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3800 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1206 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3814 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3832 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1229 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
#line 3846 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3855 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3873 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3891 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3900 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3909 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3927 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3954 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3963 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3972 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3981 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3999 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4017 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4026 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4035 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4044 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4053 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4071 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4089 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4098 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4107 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4116 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4125 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4143 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4161 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4170 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4179 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4188 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4197 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4215 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4233 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4242 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4251 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4260 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4269 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4287 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1450 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4305 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1454 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4314 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 234:
#line 1464 "conf_parser.y" /* yacc.c:1646  */
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
#line 4331 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 235:
#line 1476 "conf_parser.y" /* yacc.c:1646  */
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  MyFree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip = block_state.max_perip.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_global = block_state.max_global.value;
  class->max_local = block_state.max_local.value;
  class->max_ident = block_state.max_ident.value;
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

  rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
#line 4379 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1540 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4388 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1546 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4397 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1552 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1558 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4415 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1564 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1570 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4433 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1576 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1582 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1588 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1594 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1600 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4479 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1607 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4488 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1613 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4497 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1619 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4506 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1625 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4518 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 271:
#line 1634 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 272:
#line 1643 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4539 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1650 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4548 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 277:
#line 1654 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4557 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1664 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4566 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 280:
#line 1670 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4583 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 285:
#line 1680 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4592 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 286:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4601 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 294:
#line 1692 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4607 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1697 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif
    listener_add((yyvsp[0].number), block_state.addr.buf, block_state.flags.value);
  }
}
#line 4625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1710 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
#ifndef HAVE_LIBCRYPTO
    if (block_state.flags.value & LISTENER_SSL)
    {
      conf_error_report("SSL not available - port closed");
      break;
    }
#endif

    for (int i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      listener_add(i, block_state.addr.buf, block_state.flags.value);
  }
}
#line 4645 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1727 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4654 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1733 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4663 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 302:
#line 1742 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4672 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 303:
#line 1746 "conf_parser.y" /* yacc.c:1646  */
    {
  dlink_node *node = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = node->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

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
#line 4713 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1795 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4722 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1801 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4731 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1807 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 318:
#line 1813 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4754 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 319:
#line 1824 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4763 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4772 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4790 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4808 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4817 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4826 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4835 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1863 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4844 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1867 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4853 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1873 "conf_parser.y" /* yacc.c:1646  */
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
#line 4870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1887 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4882 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1896 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 336:
#line 1909 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4906 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 337:
#line 1916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4917 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1927 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 345:
#line 1933 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4935 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 346:
#line 1939 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1954 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4959 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 353:
#line 1969 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4975 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 354:
#line 1980 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);
}
#line 4992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 1997 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5001 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 362:
#line 2003 "conf_parser.y" /* yacc.c:1646  */
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
#line 5023 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 363:
#line 2022 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5041 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5050 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5059 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5068 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5077 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5095 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5113 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 377:
#line 2074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 378:
#line 2083 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5151 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 384:
#line 2098 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 385:
#line 2104 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5169 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5178 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5187 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5196 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5205 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5223 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5241 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2143 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5250 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2147 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 399:
#line 2156 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 400:
#line 2165 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!block_state.rpass.buf[0] ||
      !block_state.spass.buf[0])
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  conf = conf_make(CONF_SERVER);
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
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", block_state.bind.buf);
    else
    {
      assert(res);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
#line 5339 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2245 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5348 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2251 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5357 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2263 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
#line 5382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2276 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[-1].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[-1].string), ' '))
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5407 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2295 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5425 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 426:
#line 2305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5434 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 427:
#line 2311 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5442 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5451 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2327 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2338 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2344 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2356 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5515 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 438:
#line 2371 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5524 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 439:
#line 2375 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;

  conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
#line 5549 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2400 "conf_parser.y" /* yacc.c:1646  */
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
#line 5572 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2420 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5581 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 447:
#line 2429 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 448:
#line 2433 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
#line 5616 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 454:
#line 2459 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5625 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 455:
#line 2465 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5634 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2479 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
#line 5651 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 462:
#line 2496 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5660 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 463:
#line 2500 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  conf = conf_make(CONF_XLINE);
  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
#line 5682 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 469:
#line 2522 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5691 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 470:
#line 2528 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5700 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2589 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5708 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2594 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5716 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2599 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5724 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2604 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5733 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2610 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2615 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2620 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5757 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2625 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5765 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2630 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5773 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2635 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5781 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2640 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5789 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2645 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5797 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2650 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5805 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2655 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5813 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2660 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2665 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2670 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5837 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2675 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5845 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2680 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5854 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2686 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5862 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2691 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5870 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2696 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5878 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2701 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2706 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5894 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2711 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5902 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5910 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5918 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5926 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5934 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2732 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5942 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2737 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5950 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2742 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2747 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5966 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2752 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5974 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2757 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5982 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2762 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5990 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2767 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5998 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2772 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 6006 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2777 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6014 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2782 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6022 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2787 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 561:
#line 2792 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6038 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 562:
#line 2797 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6046 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2803 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2806 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6062 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2809 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6070 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2812 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6078 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2815 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6086 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2818 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6094 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2821 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2824 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6110 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2827 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6118 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2830 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6126 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2833 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6134 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2836 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6142 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2839 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6150 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2842 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6158 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2845 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6166 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2848 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2851 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2854 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6190 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2857 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6198 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2860 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6206 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6214 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 587:
#line 2866 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6222 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 588:
#line 2871 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6230 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2877 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6238 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2880 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2883 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6254 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2886 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6262 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2889 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6270 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2892 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6278 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2895 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6286 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2898 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6294 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2901 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6302 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2904 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6310 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2907 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6318 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2910 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6326 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2913 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2916 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6342 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2919 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6350 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2922 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6358 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2925 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6366 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2928 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6382 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2934 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6390 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2939 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6398 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 613:
#line 2944 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6406 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 614:
#line 2949 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6414 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2974 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6422 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2979 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6430 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2984 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6438 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2989 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2994 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6454 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 2999 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6462 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3004 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6470 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3009 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 637:
#line 3014 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6486 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 638:
#line 3019 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6494 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6503 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3047 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6512 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6521 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3059 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6530 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6542 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3074 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      event_write_links_file.when = (yyvsp[-1].number);
      event_addish(&event_write_links_file, NULL);
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
#line 6560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 657:
#line 3089 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 658:
#line 3095 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6578 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6582 "conf_parser.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
