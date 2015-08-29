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
#define YYLAST   1360

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  656
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1294

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
    1441,  1445,  1456,  1455,  1512,  1512,  1513,  1514,  1515,  1516,
    1517,  1518,  1519,  1520,  1521,  1522,  1523,  1524,  1525,  1525,
    1526,  1527,  1528,  1529,  1531,  1537,  1543,  1549,  1555,  1561,
    1567,  1573,  1579,  1585,  1591,  1598,  1604,  1610,  1616,  1625,
    1635,  1634,  1640,  1640,  1641,  1645,  1656,  1655,  1662,  1661,
    1666,  1666,  1667,  1671,  1675,  1681,  1681,  1682,  1682,  1682,
    1682,  1682,  1684,  1684,  1686,  1686,  1688,  1701,  1718,  1724,
    1734,  1733,  1775,  1775,  1776,  1777,  1778,  1779,  1780,  1781,
    1782,  1783,  1784,  1786,  1792,  1798,  1804,  1816,  1815,  1821,
    1821,  1822,  1826,  1830,  1834,  1838,  1842,  1846,  1850,  1854,
    1858,  1864,  1878,  1887,  1901,  1900,  1915,  1915,  1916,  1916,
    1916,  1916,  1918,  1924,  1930,  1940,  1942,  1942,  1943,  1943,
    1945,  1961,  1960,  1985,  1985,  1986,  1986,  1986,  1986,  1988,
    1994,  2014,  2013,  2019,  2019,  2020,  2024,  2028,  2032,  2036,
    2040,  2044,  2048,  2052,  2056,  2066,  2065,  2086,  2086,  2087,
    2087,  2087,  2089,  2096,  2095,  2101,  2101,  2102,  2106,  2110,
    2114,  2118,  2122,  2126,  2130,  2134,  2138,  2148,  2147,  2219,
    2219,  2220,  2221,  2222,  2223,  2224,  2225,  2226,  2227,  2228,
    2229,  2230,  2231,  2232,  2233,  2234,  2236,  2242,  2248,  2254,
    2267,  2280,  2286,  2292,  2296,  2303,  2302,  2307,  2307,  2308,
    2312,  2318,  2329,  2335,  2341,  2347,  2363,  2362,  2388,  2388,
    2389,  2389,  2389,  2391,  2411,  2421,  2420,  2447,  2447,  2448,
    2448,  2448,  2450,  2456,  2465,  2467,  2467,  2468,  2468,  2470,
    2488,  2487,  2510,  2510,  2511,  2511,  2511,  2513,  2519,  2528,
    2531,  2531,  2532,  2533,  2534,  2535,  2536,  2537,  2538,  2539,
    2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,  2549,
    2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,  2558,  2559,
    2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568,  2569,
    2570,  2571,  2572,  2573,  2574,  2575,  2576,  2577,  2580,  2585,
    2590,  2595,  2601,  2606,  2611,  2616,  2621,  2626,  2631,  2636,
    2641,  2646,  2651,  2656,  2661,  2666,  2671,  2677,  2682,  2687,
    2692,  2697,  2702,  2707,  2712,  2715,  2720,  2723,  2728,  2733,
    2738,  2743,  2748,  2753,  2758,  2763,  2768,  2773,  2778,  2783,
    2789,  2788,  2793,  2793,  2794,  2797,  2800,  2803,  2806,  2809,
    2812,  2815,  2818,  2821,  2824,  2827,  2830,  2833,  2836,  2839,
    2842,  2845,  2848,  2851,  2854,  2857,  2863,  2862,  2867,  2867,
    2868,  2871,  2874,  2877,  2880,  2883,  2886,  2889,  2892,  2895,
    2898,  2901,  2904,  2907,  2910,  2913,  2916,  2919,  2922,  2925,
    2930,  2935,  2940,  2949,  2952,  2952,  2953,  2954,  2955,  2956,
    2957,  2958,  2959,  2960,  2961,  2962,  2963,  2965,  2970,  2975,
    2980,  2985,  2990,  2995,  3000,  3005,  3010,  3018,  3021,  3021,
    3022,  3023,  3024,  3025,  3026,  3027,  3028,  3029,  3030,  3032,
    3038,  3044,  3050,  3056,  3065,  3080,  3086
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

#define YYPACT_NINF -742

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-742)))

#define YYTABLE_NINF -130

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -742,   647,  -742,  -214,  -221,  -218,  -742,  -742,  -742,  -204,
    -742,  -201,  -742,  -742,  -742,  -193,  -742,  -742,  -742,  -188,
    -187,  -742,  -175,  -742,  -169,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,   310,   881,  -161,  -156,  -147,    14,  -142,   418,  -132,
    -130,  -112,    37,   -56,   -44,   -41,   917,   553,   -20,   102,
     -18,    13,   -17,   -68,   -33,    -8,    -3,    47,  -742,  -742,
    -742,  -742,  -742,    -2,    31,    38,    57,    58,    65,    71,
     108,   109,   119,   212,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   644,   350,    15,  -742,   120,
      23,  -742,  -742,    24,  -742,   121,   130,   131,   133,   134,
     135,   137,   138,   140,   150,   151,   152,   153,   154,   155,
     158,   161,   162,   173,   181,   186,   187,   188,   190,   192,
    -742,  -742,   193,   202,   206,   207,   208,   211,   217,   218,
     222,   226,   227,   228,   229,   231,   232,   233,   235,   236,
      21,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   376,    28,   344,
      50,   237,   238,    41,  -742,  -742,  -742,    12,   296,   291,
    -742,   239,   241,   242,   243,   247,   250,   252,   253,    18,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,    93,
     254,   256,   257,   261,   263,   264,   265,   268,   272,   275,
     277,   281,   284,   285,   288,   289,   292,    19,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,    64,   127,   294,    48,
    -742,  -742,  -742,   164,   163,  -742,   297,    99,  -742,  -742,
     124,  -742,   312,   404,   405,   169,  -742,   286,   303,   321,
     430,   303,   431,   303,   303,   435,   437,   319,  -742,   320,
     322,   323,   324,  -742,   325,   327,   328,   329,   331,   333,
     335,   336,   337,   338,   339,   340,   349,   171,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,   357,   355,   356,   358,
     362,   363,   364,  -742,   367,   368,   369,   371,   372,   373,
     375,   203,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   377,   379,
      63,  -742,  -742,  -742,   428,   383,  -742,  -742,   381,   382,
      45,  -742,  -742,  -742,   341,   303,   444,   303,   303,   407,
     506,   410,   507,   514,   515,   414,   415,   416,   303,   519,
     520,   527,   528,   303,   529,   530,   532,   536,   439,   424,
     427,   449,   303,   303,   450,   452,   453,  -174,  -154,   457,
     462,   465,   466,   578,   303,   478,   303,   303,   480,   459,
    -742,   463,   464,   468,  -742,   469,   470,   473,   481,   482,
     180,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,   484,   485,    69,  -742,  -742,  -742,   483,   487,   490,
    -742,   491,  -742,    35,  -742,  -742,  -742,  -742,  -742,   572,
     574,   495,  -742,   496,   500,   501,    78,  -742,  -742,  -742,
     505,   504,   508,  -742,   509,   510,   511,   512,   516,  -742,
     517,   518,   166,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   522,   524,   525,   531,     2,
    -742,  -742,  -742,  -742,   499,   526,   541,   575,   548,   549,
     551,   303,   535,  -742,  -742,   629,   643,   556,   645,   660,
     661,   648,   649,   650,   651,   652,   656,   657,   658,   659,
     662,   663,   554,  -742,   555,   566,  -742,   117,  -742,  -742,
    -742,  -742,   589,   573,  -742,   577,   576,   571,   579,   581,
     582,   159,  -742,  -742,  -742,  -742,  -742,   686,   588,  -742,
     590,   586,  -742,   591,    83,  -742,  -742,  -742,  -742,   595,
     596,   597,  -742,   600,   544,   601,   608,   615,   617,   619,
     620,   622,   625,   626,  -742,  -742,   748,   750,   303,   628,
     752,   754,   755,   303,   756,   760,   303,   747,   763,   768,
     303,   772,   772,   655,  -742,  -742,   766,  -157,   771,   680,
     774,   776,   668,   778,   781,   786,   789,   791,   792,   794,
     690,  -742,   798,   800,   695,  -742,   696,  -742,   803,   804,
     699,  -742,   701,   704,   705,   706,   707,   708,   709,   711,
     712,   719,   720,   721,   722,   729,   730,   732,   739,   744,
     745,   746,   749,   751,   753,   757,   758,   710,   624,   759,
     761,   762,   764,   765,   767,   769,   770,   773,   775,   777,
     779,   780,   782,   783,   784,   785,   787,   788,   790,  -742,
    -742,   816,   743,   737,   853,   868,   856,   858,   860,   793,
    -742,   861,   862,   795,  -742,  -742,   866,   869,   796,   888,
     797,  -742,   801,   802,  -742,  -742,   877,   878,   805,  -742,
    -742,   880,   799,   806,   882,   884,   892,   895,   809,   807,
     898,   900,   808,  -742,  -742,   902,   904,   906,   811,  -742,
     812,   813,   814,   815,   817,   818,   819,   820,  -742,   821,
     822,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   833,   834,   835,   836,   837,  -742,  -742,   909,   838,
     839,  -742,   840,  -742,     9,  -742,   910,   912,   913,   922,
     842,  -742,   843,  -742,  -742,   944,   841,   951,   846,  -742,
    -742,  -742,  -742,  -742,   303,   303,   303,   303,   303,   303,
     303,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,   847,   848,   849,   -27,   850,   851,   852,   854,
     855,   857,   859,   863,   864,   865,   867,   295,   870,   871,
    -742,   872,   873,   874,   875,   876,   879,   883,    -4,   885,
     886,   887,   889,   890,   891,   893,  -742,   894,   896,  -742,
    -742,   897,   899,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   -86,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,   -79,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   901,   903,   434,   905,   907,
     908,   911,   914,  -742,   915,   916,  -742,   918,   919,    16,
     920,   921,  -742,  -742,  -742,  -742,   923,   924,  -742,   926,
     927,   413,   928,   929,   930,   931,   932,   670,   933,   934,
    -742,   935,   936,   937,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
     938,   725,  -742,  -742,   939,   940,   941,  -742,    90,  -742,
    -742,  -742,  -742,   942,   945,   946,   947,  -742,  -742,   948,
     740,   949,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   -78,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   772,   772,
     772,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,   -70,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   710,  -742,
     624,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,   -67,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   -32,  -742,   973,
     888,   950,  -742,  -742,  -742,  -742,  -742,   952,  -742,   953,
     954,  -742,  -742,   955,  -742,  -742,   956,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   -31,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,   -24,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   -13,  -742,  -742,   962,   -73,
     959,   963,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,    -6,  -742,
    -742,  -742,   -27,  -742,  -742,  -742,  -742,    -4,  -742,  -742,
    -742,   434,  -742,    16,  -742,  -742,  -742,   958,   960,   961,
     964,   968,  -742,   413,  -742,   670,  -742,   725,   965,   966,
     967,   477,  -742,  -742,   740,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,   106,  -742,
    -742,  -742,   477,  -742
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   232,   397,   445,     0,
     460,     0,   300,   436,   276,     0,   100,   152,   334,     0,
       0,   375,     0,   109,     0,   351,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    93,
      95,    94,   626,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   615,   625,   617,   618,   619,   620,
     621,   622,   616,   623,   624,     0,     0,     0,   458,     0,
       0,   456,   457,     0,   517,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     586,   560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   471,   472,   473,   515,   516,   510,   511,   512,   513,
     509,   483,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   484,   485,   514,   489,   490,   491,   492,   488,   487,
     493,   500,   501,   494,   495,   496,   486,   498,   507,   508,
     505,   506,   499,   497,   503,   504,   502,     0,     0,     0,
       0,     0,     0,     0,    46,    47,    48,     0,     0,     0,
     648,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     639,   640,   641,   642,   643,   646,   644,   645,   647,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    69,
      66,    64,    70,    71,    65,    55,    68,    58,    59,    60,
      56,    67,    61,    62,    63,    57,     0,     0,     0,     0,
     124,   125,   126,     0,     0,   349,     0,     0,   347,   348,
       0,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   614,     0,
       0,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   235,   236,
     239,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     237,   238,   240,   250,   251,   252,     0,     0,     0,     0,
       0,     0,     0,   425,     0,     0,     0,     0,     0,     0,
       0,     0,   400,   401,   402,   403,   404,   405,   406,   408,
     407,   410,   414,   411,   412,   413,   409,   451,     0,     0,
       0,   448,   449,   450,     0,     0,   455,   466,     0,     0,
       0,   463,   464,   465,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     470,     0,     0,     0,   317,     0,     0,     0,     0,     0,
       0,   303,   304,   305,   306,   311,   307,   308,   309,   310,
     442,     0,     0,     0,   439,   440,   441,     0,     0,     0,
     278,     0,   288,     0,   286,   287,   289,   290,    49,     0,
       0,     0,    45,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,   203,     0,     0,     0,     0,     0,   177,
       0,     0,     0,   155,   156,   157,   158,   159,   162,   163,
     164,   165,   161,   160,   166,     0,     0,     0,     0,     0,
     337,   338,   339,   340,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   638,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,     0,     0,   383,     0,   378,   379,
     380,   127,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   115,   114,   116,     0,     0,   346,
       0,     0,   361,     0,     0,   354,   355,   356,   357,     0,
       0,     0,    90,     0,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,   253,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   415,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   399,     0,     0,     0,   447,     0,   454,     0,     0,
       0,   462,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   469,
     312,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     302,     0,     0,     0,   438,   291,     0,     0,     0,     0,
       0,   285,     0,     0,    44,   106,     0,     0,     0,   102,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   154,   341,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,     0,     0,     0,   637,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   381,     0,     0,
       0,   377,     0,   122,     0,   117,     0,     0,     0,     0,
       0,   111,     0,   345,   358,     0,     0,     0,     0,   353,
      99,    98,    97,   635,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   636,   627,   628,   629,   630,   631,   632,
     634,   633,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   398,     0,     0,   446,
     459,     0,     0,   461,   530,   534,   518,   519,   549,   521,
     612,   557,   522,   523,   554,   529,   528,   537,   527,   524,
     525,   533,   532,   531,   555,   520,   610,   611,   553,   596,
     590,   606,   591,   592,   593,   601,   609,   594,   603,   607,
     597,   608,   598,   602,   595,   605,   600,   599,   604,     0,
     589,   569,   570,   571,   564,   582,   565,   566,   567,   577,
     585,   568,   579,   583,   573,   584,   574,   578,   572,   581,
     576,   575,   580,     0,   563,   550,   548,   551,   556,   552,
     539,   546,   547,   544,   545,   540,   541,   542,   543,   558,
     559,   526,   536,   535,   538,     0,     0,     0,     0,     0,
       0,     0,     0,   301,     0,     0,   437,     0,     0,     0,
     296,   292,   295,   277,    50,    51,     0,     0,   101,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,     0,     0,   335,   650,   649,   655,   653,   656,
     651,   652,   654,    86,    81,    89,    80,    87,    88,    79,
      83,    82,    74,    73,    78,    75,    77,    76,    84,    85,
       0,     0,   376,   128,     0,     0,     0,   140,     0,   132,
     133,   135,   134,     0,     0,     0,     0,   110,   350,     0,
       0,     0,   352,    31,    32,    33,    34,    35,    36,    37,
     265,   266,   257,   275,   274,     0,   273,   258,   260,   262,
     269,   261,   259,   268,   254,   267,   256,   255,    38,    38,
      38,    40,    39,   263,   264,   420,   423,   424,   434,   431,
     417,   432,   429,   430,     0,   428,   433,   416,   422,   419,
     421,   435,   418,   452,   453,   467,   468,   587,     0,   561,
       0,   315,   316,   326,   322,   323,   325,   330,   327,   328,
     321,   329,   324,     0,   320,   314,   333,   332,   331,   313,
     444,   443,   299,   298,   283,   284,   282,     0,   281,     0,
       0,     0,   107,   108,   176,   172,   222,   210,   219,     0,
     208,   213,   228,     0,   221,   226,   212,   215,   223,   225,
     229,   220,   227,   216,   218,   224,   214,   217,     0,   206,
     168,   170,   173,   174,   175,   186,   187,   188,   181,   199,
     182,   183,   184,   194,   202,   185,   196,   200,   190,   201,
     191,   195,   189,   198,   193,   192,   197,     0,   180,   169,
     171,   344,   342,   343,   382,   387,   393,   396,   389,   395,
     390,   394,   392,   388,   391,     0,   386,   136,     0,     0,
       0,     0,   131,   119,   118,   120,   121,   359,   365,   371,
     374,   367,   373,   368,   372,   370,   366,   369,     0,   364,
     360,   271,     0,    41,    42,    43,   426,     0,   588,   562,
     318,     0,   279,     0,   297,   294,   293,     0,     0,     0,
       0,     0,   204,     0,   178,     0,   384,     0,     0,     0,
       0,     0,   130,   362,     0,   272,   427,   319,   280,   209,
     231,   207,   230,   211,   205,   179,   385,   137,   139,   138,
     150,   149,   145,   147,   151,   148,   144,   146,     0,   143,
     363,   141,     0,   142
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -742,  -742,  -742,  -434,  -296,  -741,  -621,  -742,  -742,   925,
    -742,  -742,  -742,  -742,   845,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  1008,  -742,  -742,  -742,  -742,  -742,
    -742,   621,  -742,  -742,  -742,  -742,  -742,   523,  -742,  -742,
    -742,  -742,  -742,  -742,   844,  -742,  -742,  -742,  -742,    75,
    -742,  -742,  -742,  -742,  -742,  -186,  -742,  -742,  -742,   603,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -146,  -742,  -742,  -742,  -140,  -742,  -742,  -742,
     810,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -115,  -742,  -742,  -742,  -742,  -742,  -123,  -742,   654,  -742,
    -742,  -742,    -5,  -742,  -742,  -742,  -742,  -742,   679,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -110,  -742,  -742,  -742,
    -742,  -742,  -742,   616,  -742,  -742,  -742,  -742,  -742,   943,
    -742,  -742,  -742,  -742,   558,  -742,  -742,  -742,  -742,  -742,
    -119,  -742,  -742,  -742,   609,  -742,  -742,  -742,  -742,  -111,
    -742,  -742,  -742,   957,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,   -90,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,   702,  -742,  -742,  -742,  -742,  -742,
     969,  -742,  -742,  -742,  -742,  1066,  -742,  -742,  -742,  -742,
     970,  -742,  -742,  -742,  -742,  1017,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,    79,
    -742,  -742,  -742,    80,  -742,  -742,  -742,  -742,  -742,  1087,
    -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742,  -742,   971,  -742,  -742,  -742,  -742,  -742,  -742,  -742,
    -742
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
    1030,  1031,  1032,  1210,  1288,  1289,    33,    64,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     739,  1187,  1188,   514,   733,  1158,  1159,    34,    53,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   609,  1055,
    1056,    35,    61,   472,   718,  1127,  1128,   473,   474,   475,
    1131,   971,   972,   476,   477,    36,    59,   450,   451,   452,
     453,   454,   455,   456,   703,  1113,  1114,   457,   458,   459,
      37,    65,   519,   520,   521,   522,   523,    38,   287,   288,
     289,    39,    72,   584,   585,   586,   587,   588,   796,  1228,
    1229,    40,    68,   557,   558,   559,   560,   779,  1205,  1206,
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
     248,   388,   378,   518,   139,   580,   680,   681,  1259,   140,
     141,   211,   142,   143,   144,   211,   379,   145,   694,  1097,
     696,   697,   388,  1098,    76,   389,  1099,  1231,   249,   461,
    1100,  1232,   212,   471,   484,  1236,   212,   291,  1240,  1237,
     566,   555,  1241,   146,   566,   250,   389,   490,   251,   252,
     253,   217,   309,   147,   148,   149,   150,   151,   152,   153,
     581,   441,   485,   218,   379,   491,   219,  1025,   310,   311,
     461,  1083,   312,  1242,  1252,   292,   286,  1243,  1253,   442,
    1026,  1254,  1125,   492,   346,  1255,   347,   276,   348,   284,
     290,  1126,  1256,    82,   555,   254,  1257,   443,  -129,  1263,
     293,   581,   349,  1264,  1027,   294,   297,   493,   748,   154,
     155,   156,   313,   157,   158,   757,    83,    84,   255,   256,
     350,   444,   159,    85,   532,   552,   462,   439,   485,   385,
     314,   315,   316,   317,   318,   351,   567,   352,   319,   298,
     567,   720,   320,   494,   353,   278,   299,   481,   321,    86,
      87,   650,  -129,   295,   563,   478,   354,   322,   323,   556,
     495,  1026,    88,    89,    90,   300,   301,   462,   324,   644,
      91,    92,   515,   302,   445,   713,   496,   490,   582,   303,
     355,   583,   446,   447,   728,  1027,  1068,  1069,  1070,   798,
     325,    73,   824,   497,   498,   491,  1211,   829,   534,   278,
     832,   356,   568,   448,   836,   578,   568,  1233,  1234,  1235,
     516,  1291,   556,   492,   565,  1292,   304,   305,    74,   582,
     569,   357,   583,   780,   569,   467,    75,   306,   384,   394,
     358,   346,   561,   347,   326,   348,   570,   493,   395,   396,
     570,   397,   398,   399,   499,   400,   401,   517,   402,   349,
    1043,  1044,  1045,  1046,  1047,  1048,  1049,   441,   403,   404,
     405,   406,   407,   408,   500,   790,   409,   350,   501,   410,
     411,   593,   742,   494,   592,   442,   468,   623,   449,   359,
     837,   412,   351,   469,   352,   470,   709,    76,   594,   413,
     495,   353,   518,   443,   414,   415,   416,  1136,   417,   114,
     418,   421,   360,   354,   115,   116,   496,   117,   118,   640,
     422,   589,   119,  1137,   423,   424,   425,   444,   307,   426,
     120,   121,  1138,   497,   498,   427,   428,   355,   122,  1103,
     429,   123,   124,   125,   430,   431,   432,   433,   126,   434,
     435,   436,   471,   437,   438,   479,   480,   524,   356,   525,
     526,   527,  1104,   127,   128,   528,  1139,  1140,   529,  1141,
     530,   531,   535,   129,   536,   537,   130,   131,   357,   538,
     445,   539,   540,   541,   499,   132,   542,   358,   446,   447,
     543,  1105,   133,   544,   134,   545,   135,  1142,   136,   546,
     137,   138,   547,   548,   500,  1143,   549,   550,   501,   448,
     551,   139,   562,   590,   591,   577,   140,   141,   596,   142,
     143,   144,  1106,  1107,   145,   597,   599,  1144,  1108,  1145,
     602,  1280,   603,  1281,   604,   605,   359,   646,   652,   654,
     606,   607,   608,   610,   239,   611,   612,   613,  1146,   614,
     146,   615,  1109,   616,   617,   618,   619,   620,   621,   360,
     147,   148,   149,   150,   151,   152,   153,   622,  1110,   240,
    1147,   241,   625,   626,   627,  1148,   628,  1282,  1260,  1149,
     629,   630,   631,  1150,   449,   633,   634,   635,  1151,   636,
     637,   638,  1152,   639,  1283,   642,   242,   643,   647,   648,
     649,   658,   660,  1153,   657,   243,  1154,   659,  1155,   661,
     662,   663,   664,   665,   667,   668,   154,   155,   156,  1156,
     157,   158,   669,   670,   672,   673,  1157,   674,   244,   159,
    1111,   675,   245,  1284,  1285,   309,   676,     2,     3,   594,
     246,     4,   677,   247,   248,   678,   679,   682,  1112,   683,
     684,   310,   311,     5,   689,   312,     6,     7,   911,   690,
     912,   913,   691,   692,     8,   804,   805,   806,   807,   808,
     809,   810,   249,   693,   699,   695,     9,   698,   700,    10,
      11,   722,   701,   723,   753,  1286,   702,   704,   705,   250,
    1287,   706,   251,   252,   253,   313,   750,    12,   715,   707,
     708,    13,   711,   712,  1165,   716,  1166,  1167,   717,   719,
     724,   725,    14,   314,   315,   316,   317,   318,   726,   727,
     730,   319,   731,   751,   759,   320,   732,   734,   735,   736,
     737,   321,    15,    16,   738,   740,   741,   744,   752,   254,
     322,   323,   745,   746,   889,   754,   755,    17,   756,   747,
     758,   324,   760,   761,   762,   763,   764,   765,   766,   767,
     768,   769,   255,   256,    18,   770,   771,   772,   773,   776,
     777,   774,   775,   325,   914,   915,   916,    19,    20,   917,
     918,  1195,   919,   920,   778,   921,   782,   922,   783,   786,
     923,   785,   924,   925,   784,   792,  1218,   787,   926,   788,
     789,    21,   927,   793,   795,   794,   928,   929,   930,   797,
     800,   801,   802,   931,    22,   803,   813,   326,   932,    23,
    1168,  1169,  1170,   814,    24,  1171,  1172,    25,  1173,  1174,
     815,  1175,   816,  1176,   817,   818,  1177,   819,  1178,  1179,
     820,   821,  1196,   822,  1180,   823,   825,   826,  1181,   827,
     828,   830,  1182,  1183,  1184,   831,   833,  1219,   834,  1185,
     890,   891,   892,   835,  1186,   893,   894,   837,   895,   896,
     840,   897,    82,   898,  1197,   841,   899,   845,   900,   901,
     844,   851,  1198,   846,   902,   847,   848,   849,   903,  1220,
     850,  1199,   904,   905,   906,    83,    84,  1221,   852,   907,
     853,   854,    85,   855,   908,   856,  1222,   857,   220,   858,
     859,   860,   861,   862,   863,  1200,   864,  1201,  1202,   865,
     866,   867,   868,   869,   870,   955,   871,   872,    86,    87,
    1223,  1203,  1224,  1225,   873,   874,   875,   876,  1204,   221,
     956,    88,    89,    90,   877,   878,  1226,   879,   222,    91,
      92,   223,   224,  1227,   880,   957,   225,   226,   227,   881,
     882,   883,   958,   959,   884,   960,   885,   961,   886,   962,
     964,   965,   887,   888,   935,   967,   936,   937,   968,   938,
     939,   228,   940,   970,   941,   942,   976,   977,   943,   979,
     944,   982,   945,   983,   946,   947,   980,   948,   949,   950,
     951,   984,   952,   953,   985,   954,   986,   988,   963,   989,
     966,   991,   973,   992,   969,   993,   974,   975,  1020,  1033,
     978,  1034,  1035,   990,   981,   987,   994,   995,   996,   997,
     998,  1036,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,  1015,  1016,
    1017,  1018,  1019,  1039,  1022,  1023,  1021,  1037,  1038,  1040,
    1041,  1042,  1050,  1051,  1052,  1057,  1058,  1059,  1244,  1060,
    1061,  1258,  1062,  1269,  1063,   296,  1271,  1270,  1064,  1065,
    1066,  1272,  1067,  1273,   791,  1073,  1074,  1075,  1076,  1077,
    1078,  1079,   553,  1212,  1080,   743,  1293,   729,  1081,  1275,
    1086,  1087,  1088,  1274,  1089,  1090,  1091,  1265,  1092,  1093,
    1268,  1094,  1095,   564,  1096,  1245,  1101,   721,  1102,   710,
    1115,  1267,  1116,  1117,  1129,   749,  1118,   624,   482,  1119,
    1120,  1121,   799,  1122,  1123,  1290,  1276,  1266,  1132,  1133,
    1130,  1134,  1135,  1160,  1161,  1162,  1163,  1164,  1189,  1190,
    1191,  1192,  1193,  1194,  1207,   714,   781,  1213,  1208,  1209,
    1214,  1215,  1216,  1217,  1230,  1246,   386,   440,  1238,  1239,
     308,     0,  1247,  1248,  1249,  1250,  1251,  1261,  1262,     0,
    1277,  1278,  1279,     0,     0,     0,     0,     0,     0,     0,
     533,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     579,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   641,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   645,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     651
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
      78,    79,     1,   228,   114,   226,   130,     1,   215,   228,
      97,   218,   122,   123,   226,   215,    11,    12,    13,   226,
     139,     1,   608,   147,   148,    19,   226,   613,   225,   217,
     616,   118,   163,   143,   620,   226,   163,  1068,  1069,  1070,
      39,   225,   215,    37,   170,   229,   228,   228,    28,   215,
     181,   138,   218,   226,   181,     1,    36,   228,   228,   228,
     147,     1,   225,     3,   183,     5,   197,    61,   228,   228,
     197,   228,   228,   228,   198,   228,   228,    76,   228,    19,
     804,   805,   806,   807,   808,   809,   810,     1,   228,   228,
     228,   228,   228,   228,   218,   226,   228,    37,   222,   228,
     228,   105,   226,    97,   225,    19,    52,   226,   218,   196,
     105,   228,    52,    59,    54,    61,   226,    97,   105,   228,
     114,    61,   121,    37,   228,   228,   228,     4,   228,     1,
     228,   228,   219,    73,     6,     7,   130,     9,    10,   226,
     228,   119,    14,    20,   228,   228,   228,    61,   226,   228,
      22,    23,    29,   147,   148,   228,   228,    97,    30,    15,
     228,    33,    34,    35,   228,   228,   228,   228,    40,   228,
     228,   228,   118,   228,   228,   228,   228,   228,   118,   228,
     228,   228,    38,    55,    56,   228,    63,    64,   228,    66,
     228,   228,   228,    65,   228,   228,    68,    69,   138,   228,
     114,   228,   228,   228,   198,    77,   228,   147,   122,   123,
     228,    67,    84,   228,    86,   228,    88,    94,    90,   228,
      92,    93,   228,   228,   218,   102,   228,   228,   222,   143,
     228,   103,   228,   119,   119,   228,   108,   109,   207,   111,
     112,   113,    98,    99,   116,   105,   105,   124,   104,   126,
     105,    64,   105,    66,   225,   225,   196,   119,   207,   105,
     228,   228,   228,   228,     1,   228,   228,   228,   145,   228,
     142,   228,   128,   228,   228,   228,   228,   228,   228,   219,
     152,   153,   154,   155,   156,   157,   158,   228,   144,    26,
     167,    28,   225,   228,   228,   172,   228,   110,  1209,   176,
     228,   228,   228,   180,   218,   228,   228,   228,   185,   228,
     228,   228,   189,   228,   127,   228,    53,   228,   225,   228,
     228,   105,   105,   200,   207,    62,   203,   207,   205,   105,
     105,   207,   207,   207,   105,   105,   208,   209,   210,   216,
     212,   213,   105,   105,   105,   105,   223,   105,    85,   221,
     206,   105,    89,   166,   167,     1,   207,     0,     1,   105,
      97,     4,   228,   100,   101,   228,   207,   207,   224,   207,
     207,    17,    18,    16,   207,    21,    19,    20,    44,   207,
      46,    47,   207,   207,    27,   131,   132,   133,   134,   135,
     136,   137,   129,   105,   225,   207,    39,   207,   225,    42,
      43,   119,   228,   119,   119,   218,   228,   228,   228,   146,
     223,   228,   149,   150,   151,    61,   207,    60,   225,   228,
     228,    64,   228,   228,    44,   228,    46,    47,   228,   228,
     225,   225,    75,    79,    80,    81,    82,    83,   228,   228,
     225,    87,   228,   207,   105,    91,   228,   228,   228,   228,
     228,    97,    95,    96,   228,   228,   228,   225,   207,   196,
     106,   107,   228,   228,    44,   207,   207,   110,   207,   228,
     225,   117,   119,   207,   119,   105,   105,   119,   119,   119,
     119,   119,   219,   220,   127,   119,   119,   119,   119,   225,
     225,   119,   119,   139,   160,   161,   162,   140,   141,   165,
     166,    66,   168,   169,   228,   171,   207,   173,   225,   228,
     176,   225,   178,   179,   227,   119,    66,   228,   184,   228,
     228,   164,   188,   225,   228,   225,   192,   193,   194,   228,
     225,   225,   225,   199,   177,   225,   225,   183,   204,   182,
     160,   161,   162,   225,   187,   165,   166,   190,   168,   169,
     225,   171,   225,   173,   225,   225,   176,   225,   178,   179,
     225,   225,   127,   105,   184,   105,   228,   105,   188,   105,
     105,   105,   192,   193,   194,   105,   119,   127,   105,   199,
     160,   161,   162,   105,   204,   165,   166,   105,   168,   169,
     225,   171,     1,   173,   159,   119,   176,   207,   178,   179,
     119,   105,   167,   119,   184,   119,   228,   119,   188,   159,
     119,   176,   192,   193,   194,    24,    25,   167,   119,   199,
     119,   119,    31,   119,   204,   225,   176,   119,     1,   119,
     225,   225,   119,   119,   225,   200,   225,   202,   203,   225,
     225,   225,   225,   225,   225,   119,   225,   225,    57,    58,
     200,   216,   202,   203,   225,   225,   225,   225,   223,    32,
     207,    70,    71,    72,   225,   225,   216,   225,    41,    78,
      79,    44,    45,   223,   225,   228,    49,    50,    51,   225,
     225,   225,   119,   105,   225,   119,   225,   119,   225,   119,
     119,   119,   225,   225,   225,   119,   225,   225,   119,   225,
     225,    74,   225,   105,   225,   225,   119,   119,   225,   119,
     225,   119,   225,   119,   225,   225,   207,   225,   225,   225,
     225,   119,   225,   225,   119,   225,   207,   119,   225,   119,
     225,   119,   225,   119,   228,   119,   225,   225,   119,   119,
     225,   119,   119,   225,   228,   228,   225,   225,   225,   225,
     225,   119,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   119,   225,   225,   228,   225,   225,   228,
     119,   225,   225,   225,   225,   225,   225,   225,   105,   225,
     225,   119,   225,   125,   225,    77,   125,   127,   225,   225,
     225,   127,   225,   125,   571,   225,   225,   225,   225,   225,
     225,   225,   257,  1028,   225,   502,  1292,   486,   225,  1255,
     225,   225,   225,  1253,   225,   225,   225,  1232,   225,   225,
    1243,   225,   225,   279,   225,  1130,   225,   473,   225,   450,
     225,  1241,   225,   225,   214,   519,   225,   327,   213,   225,
     225,   225,   584,   225,   225,  1264,  1257,  1237,   225,   225,
     229,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   463,   557,   225,   228,   228,
     225,   225,   225,   225,   225,   225,   110,   160,  1098,  1100,
      93,    -1,   230,   230,   230,   230,   230,   228,   225,    -1,
     225,   225,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     287,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   361,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   380,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     390
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
      64,    66,    94,   102,   124,   126,   145,   167,   172,   176,
     180,   185,   189,   200,   203,   205,   216,   223,   316,   317,
     225,   225,   225,   225,   225,    44,    46,    47,   160,   161,
     162,   165,   166,   168,   169,   171,   173,   176,   178,   179,
     184,   188,   192,   193,   194,   199,   204,   312,   313,   225,
     225,   225,   225,   225,   225,    66,   127,   159,   167,   176,
     200,   202,   203,   216,   223,   399,   400,   225,   228,   228,
     294,   226,   290,   225,   225,   225,   225,   225,    66,   127,
     159,   167,   176,   200,   202,   203,   216,   223,   390,   391,
     225,   225,   229,   236,   236,   236,   225,   229,   494,   490,
     225,   229,   225,   229,   105,   353,   225,   230,   230,   230,
     230,   230,   225,   229,   225,   229,   225,   229,   119,   201,
     237,   228,   225,   225,   229,   341,   416,   367,   347,   125,
     127,   125,   127,   125,   317,   313,   400,   225,   225,   225,
      64,    66,   110,   127,   166,   167,   218,   223,   295,   296,
     391,   225,   229,   296
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
     317,   317,   319,   318,   320,   320,   321,   321,   321,   321,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,   321,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     339,   338,   340,   340,   341,   341,   343,   342,   345,   344,
     346,   346,   347,   347,   347,   348,   348,   349,   349,   349,
     349,   349,   351,   350,   352,   352,   353,   353,   354,   355,
     357,   356,   358,   358,   359,   359,   359,   359,   359,   359,
     359,   359,   359,   360,   361,   362,   363,   365,   364,   366,
     366,   367,   367,   367,   367,   367,   367,   367,   367,   367,
     367,   368,   369,   370,   372,   371,   373,   373,   374,   374,
     374,   374,   375,   376,   377,   378,   379,   379,   380,   380,
     381,   383,   382,   384,   384,   385,   385,   385,   385,   386,
     387,   389,   388,   390,   390,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   393,   392,   394,   394,   395,
     395,   395,   396,   398,   397,   399,   399,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   402,   401,   403,
     403,   404,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   404,   404,   404,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   412,   414,   413,   415,   415,   416,
     416,   417,   418,   419,   420,   421,   423,   422,   424,   424,
     425,   425,   425,   426,   427,   429,   428,   430,   430,   431,
     431,   431,   432,   433,   434,   435,   435,   436,   436,   437,
     439,   438,   440,   440,   441,   441,   441,   442,   443,   444,
     445,   445,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   446,   446,
     446,   446,   446,   446,   446,   446,   446,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   473,   474,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     488,   487,   489,   489,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   492,   491,   493,   493,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     495,   496,   497,   498,   499,   499,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   501,   502,   503,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   512,
     513,   513,   513,   513,   513,   513,   513,   513,   513,   514,
     515,   516,   517,   518,   519,   520,   521
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
       3,     3,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     2,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
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
#line 2859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 30:
#line 413 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2865 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 31:
#line 414 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2871 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 32:
#line 415 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 33:
#line 416 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2883 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 34:
#line 417 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2889 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 35:
#line 418 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 36:
#line 419 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2901 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 37:
#line 420 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2907 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 38:
#line 423 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = 0; }
#line 2913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 40:
#line 424 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2919 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 41:
#line 425 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2925 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 42:
#line 426 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 2931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 43:
#line 427 "conf_parser.y" /* yacc.c:1646  */
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 2937 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 50:
#line 441 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 2946 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 51:
#line 447 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 2955 "conf_parser.c" /* yacc.c:1646  */
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
#line 2998 "conf_parser.c" /* yacc.c:1646  */
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
#line 3059 "conf_parser.c" /* yacc.c:1646  */
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
#line 3091 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 76:
#line 604 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    SSL_CTX_set_cipher_list(ConfigServerInfo.server_ctx, yylval.string);
#endif
}
#line 3102 "conf_parser.c" /* yacc.c:1646  */
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
#line 3119 "conf_parser.c" /* yacc.c:1646  */
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
#line 3150 "conf_parser.c" /* yacc.c:1646  */
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
#line 3168 "conf_parser.c" /* yacc.c:1646  */
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
#line 3186 "conf_parser.c" /* yacc.c:1646  */
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
#line 3199 "conf_parser.c" /* yacc.c:1646  */
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
#line 3216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 83:
#line 708 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigServerInfo.network_desc);
  ConfigServerInfo.network_desc = xstrdup(yylval.string);
}
#line 3228 "conf_parser.c" /* yacc.c:1646  */
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
#line 3259 "conf_parser.c" /* yacc.c:1646  */
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
#line 3290 "conf_parser.c" /* yacc.c:1646  */
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
#line 3318 "conf_parser.c" /* yacc.c:1646  */
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
#line 3343 "conf_parser.c" /* yacc.c:1646  */
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
#line 3368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 89:
#line 842 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3377 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 97:
#line 859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3389 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 98:
#line 868 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 99:
#line 877 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3413 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 100:
#line 889 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3422 "conf_parser.c" /* yacc.c:1646  */
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
#line 3439 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 107:
#line 910 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 108:
#line 916 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3457 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 109:
#line 925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3466 "conf_parser.c" /* yacc.c:1646  */
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
#line 3484 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 118:
#line 947 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3493 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 119:
#line 953 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3502 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 120:
#line 959 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3511 "conf_parser.c" /* yacc.c:1646  */
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
#line 3532 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 128:
#line 992 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3541 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 129:
#line 998 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3550 "conf_parser.c" /* yacc.c:1646  */
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
#line 3563 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1018 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3574 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1026 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = (yyvsp[-1].number);
}
#line 3582 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1029 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.size.value = 0;
}
#line 3590 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1034 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3599 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3608 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3617 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3626 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3635 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3644 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1061 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3653 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1065 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3662 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1069 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3671 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1079 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3683 "conf_parser.c" /* yacc.c:1646  */
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
#line 3768 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1182 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3777 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1188 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3786 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1194 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3795 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1200 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3804 "conf_parser.c" /* yacc.c:1646  */
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
#line 3818 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1217 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3827 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1223 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3836 "conf_parser.c" /* yacc.c:1646  */
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
#line 3850 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1240 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3859 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1246 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1253 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
#line 3877 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1257 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3886 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1261 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3895 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1265 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1269 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
#line 3913 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1273 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3922 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1277 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3931 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3940 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1285 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3949 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1289 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3958 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3967 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
#line 3976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 193:
#line 1301 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3985 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 194:
#line 1305 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3994 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 195:
#line 1309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 4003 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 196:
#line 1313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 4012 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 197:
#line 1317 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 4021 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 198:
#line 1321 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 4030 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 199:
#line 1325 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 4039 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 200:
#line 1329 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 4048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 201:
#line 1333 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 4057 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 202:
#line 1337 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 4066 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 203:
#line 1343 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 4075 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 207:
#line 1350 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 4084 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 208:
#line 1354 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 4093 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 209:
#line 1358 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 4102 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 210:
#line 1362 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 4111 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 211:
#line 1366 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 212:
#line 1370 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4129 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 213:
#line 1374 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4138 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 214:
#line 1378 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4147 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 215:
#line 1382 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4156 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 216:
#line 1386 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4165 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 217:
#line 1390 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4174 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 218:
#line 1394 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4183 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 219:
#line 1398 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 220:
#line 1402 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4201 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 221:
#line 1406 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4210 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 222:
#line 1410 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4219 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 223:
#line 1414 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4228 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 224:
#line 1418 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4237 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 225:
#line 1422 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4246 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 226:
#line 1426 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4255 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 227:
#line 1430 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 228:
#line 1434 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4273 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 229:
#line 1438 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4282 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 230:
#line 1442 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4291 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 231:
#line 1446 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4300 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 232:
#line 1456 "conf_parser.y" /* yacc.c:1646  */
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
#line 4317 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 233:
#line 1468 "conf_parser.y" /* yacc.c:1646  */
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
#line 4365 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 254:
#line 1532 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4374 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 255:
#line 1538 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4383 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 256:
#line 1544 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[-1].number);
}
#line 4392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 257:
#line 1550 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4401 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 258:
#line 1556 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4410 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 259:
#line 1562 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4419 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 260:
#line 1568 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[-1].number);
}
#line 4428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 261:
#line 1574 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[-1].number);
}
#line 4437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 262:
#line 1580 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[-1].number);
}
#line 4446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 263:
#line 1586 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4455 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 264:
#line 1592 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4465 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 265:
#line 1599 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4474 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 266:
#line 1605 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4483 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 267:
#line 1611 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4492 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 268:
#line 1617 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4504 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 269:
#line 1626 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 270:
#line 1635 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4525 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 274:
#line 1642 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4534 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 275:
#line 1646 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4543 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 276:
#line 1656 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4552 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 278:
#line 1662 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value = 0;
}
#line 4560 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 282:
#line 1668 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
#line 4569 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 283:
#line 1672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4578 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 284:
#line 1676 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4587 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 292:
#line 1684 "conf_parser.y" /* yacc.c:1646  */
    { block_state.flags.value = 0; }
#line 4593 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 296:
#line 1689 "conf_parser.y" /* yacc.c:1646  */
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
#line 4611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 297:
#line 1702 "conf_parser.y" /* yacc.c:1646  */
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
#line 4631 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 298:
#line 1719 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4640 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 299:
#line 1725 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4649 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 300:
#line 1734 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4658 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 301:
#line 1738 "conf_parser.y" /* yacc.c:1646  */
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
#line 4699 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 313:
#line 1787 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4708 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 314:
#line 1793 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4717 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 315:
#line 1799 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4726 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 316:
#line 1805 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4740 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 317:
#line 1816 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4749 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 321:
#line 1823 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
#line 4758 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 322:
#line 1827 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 323:
#line 1831 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4776 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 324:
#line 1835 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4785 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 325:
#line 1839 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4794 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 326:
#line 1843 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4803 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 327:
#line 1847 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4812 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 328:
#line 1851 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4821 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 329:
#line 1855 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4830 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 330:
#line 1859 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4839 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 331:
#line 1865 "conf_parser.y" /* yacc.c:1646  */
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
#line 4856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 332:
#line 1879 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4868 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 333:
#line 1888 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 334:
#line 1901 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4892 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 335:
#line 1908 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4903 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 342:
#line 1919 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 343:
#line 1925 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4921 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 344:
#line 1931 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4930 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 350:
#line 1946 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
#line 4945 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 351:
#line 1961 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4961 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 352:
#line 1972 "conf_parser.y" /* yacc.c:1646  */
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
#line 4978 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 359:
#line 1989 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4987 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 360:
#line 1995 "conf_parser.y" /* yacc.c:1646  */
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
#line 5009 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 361:
#line 2014 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5018 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 365:
#line 2021 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5027 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 366:
#line 2025 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5036 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 367:
#line 2029 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5045 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 368:
#line 2033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5054 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 369:
#line 2037 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5063 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 370:
#line 2041 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 371:
#line 2045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5081 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 372:
#line 2049 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5090 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 373:
#line 2053 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5099 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 374:
#line 2057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5108 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 375:
#line 2066 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 5122 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 376:
#line 2075 "conf_parser.y" /* yacc.c:1646  */
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
#line 5137 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 382:
#line 2090 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5146 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 383:
#line 2096 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5155 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 387:
#line 2103 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 5164 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 388:
#line 2107 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 5173 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 389:
#line 2111 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 5182 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 390:
#line 2115 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 5191 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 391:
#line 2119 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 5200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 392:
#line 2123 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 5209 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 393:
#line 2127 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 5218 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 394:
#line 2131 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5227 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 395:
#line 2135 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5236 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 396:
#line 2139 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5245 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 397:
#line 2148 "conf_parser.y" /* yacc.c:1646  */
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
}
#line 5259 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 398:
#line 2157 "conf_parser.y" /* yacc.c:1646  */
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
#line 5325 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 416:
#line 2237 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5334 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 417:
#line 2243 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5343 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 418:
#line 2249 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 419:
#line 2255 "conf_parser.y" /* yacc.c:1646  */
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
#line 5368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 420:
#line 2268 "conf_parser.y" /* yacc.c:1646  */
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
#line 5384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 421:
#line 2281 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5393 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 422:
#line 2287 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5402 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 423:
#line 2293 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5411 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 424:
#line 2297 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5420 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 425:
#line 2303 "conf_parser.y" /* yacc.c:1646  */
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5428 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 429:
#line 2309 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5437 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 430:
#line 2313 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
#line 5446 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 431:
#line 2319 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5460 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 432:
#line 2330 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5469 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 433:
#line 2336 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5478 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 434:
#line 2342 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5487 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 435:
#line 2348 "conf_parser.y" /* yacc.c:1646  */
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
#line 5501 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 436:
#line 2363 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5510 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 437:
#line 2367 "conf_parser.y" /* yacc.c:1646  */
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
#line 5535 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 443:
#line 2392 "conf_parser.y" /* yacc.c:1646  */
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
#line 5558 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 444:
#line 2412 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5567 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 445:
#line 2421 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5576 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 446:
#line 2425 "conf_parser.y" /* yacc.c:1646  */
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
#line 5602 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 452:
#line 2451 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5611 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 453:
#line 2457 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5620 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 459:
#line 2471 "conf_parser.y" /* yacc.c:1646  */
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
#line 5637 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 460:
#line 2488 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5646 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 461:
#line 2492 "conf_parser.y" /* yacc.c:1646  */
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
#line 5668 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 467:
#line 2514 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5677 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 468:
#line 2520 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5686 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 518:
#line 2581 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5694 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 519:
#line 2586 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5702 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 520:
#line 2591 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_watch = (yyvsp[-1].number);
}
#line 5710 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 521:
#line 2596 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5719 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 522:
#line 2602 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5727 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 523:
#line 2607 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5735 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 524:
#line 2612 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5743 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 525:
#line 2617 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5751 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 526:
#line 2622 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.tkline_expire_notices = yylval.number;
}
#line 5759 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 527:
#line 2627 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5767 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 528:
#line 2632 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ignore_bogus_ts = yylval.number;
}
#line 5775 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 529:
#line 2637 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5783 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 530:
#line 2642 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5791 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 531:
#line 2647 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5799 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 532:
#line 2652 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5807 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 533:
#line 2657 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5815 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 534:
#line 2662 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5823 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 535:
#line 2667 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5831 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 536:
#line 2672 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5840 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 537:
#line 2678 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5848 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 538:
#line 2683 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5856 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 539:
#line 2688 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5864 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 540:
#line 2693 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5872 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 541:
#line 2698 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5880 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 542:
#line 2703 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5888 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 543:
#line 2708 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5896 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 544:
#line 2713 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 2 * yylval.number;
}
#line 5904 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 545:
#line 2716 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_k_oper_only = 1;
}
#line 5912 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 546:
#line 2721 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 2 * yylval.number;
}
#line 5920 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 547:
#line 2724 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.stats_i_oper_only = 1;
}
#line 5928 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 548:
#line 2729 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5936 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 549:
#line 2734 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5944 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 550:
#line 2739 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5952 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 551:
#line 2744 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5960 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 552:
#line 2749 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.short_motd = yylval.number;
}
#line 5968 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 553:
#line 2754 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5976 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 554:
#line 2759 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.dots_in_ident = (yyvsp[-1].number);
}
#line 5984 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 555:
#line 2764 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5992 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 556:
#line 2769 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 6000 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 557:
#line 2774 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.disable_auth = yylval.number;
}
#line 6008 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 558:
#line 2779 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 6016 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 559:
#line 2784 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 6024 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 560:
#line 2789 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes = 0;
}
#line 6032 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 564:
#line 2795 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_BOTS;
}
#line 6040 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 565:
#line 2798 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 6048 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 566:
#line 2801 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 6056 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 567:
#line 2804 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 6064 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 568:
#line 2807 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FULL;
}
#line 6072 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 569:
#line 2810 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 6080 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 570:
#line 2813 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 6088 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 571:
#line 2816 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 6096 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 572:
#line 2819 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 6104 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 573:
#line 2822 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6112 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 574:
#line 2825 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6120 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 575:
#line 2828 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_UNAUTH;
}
#line 6128 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 576:
#line 2831 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6136 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 577:
#line 2834 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6144 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 578:
#line 2837 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6152 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 579:
#line 2840 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6160 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 580:
#line 2843 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6168 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 581:
#line 2846 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6176 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 582:
#line 2849 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6184 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 583:
#line 2852 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6192 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 584:
#line 2855 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6200 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 585:
#line 2858 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6208 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 586:
#line 2863 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6216 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 590:
#line 2869 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_BOTS;
}
#line 6224 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 591:
#line 2872 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6232 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 592:
#line 2875 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6240 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 593:
#line 2878 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6248 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 594:
#line 2881 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FULL;
}
#line 6256 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 595:
#line 2884 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6264 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 596:
#line 2887 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6272 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 597:
#line 2890 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6280 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 598:
#line 2893 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6288 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 599:
#line 2896 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_UNAUTH;
}
#line 6296 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 600:
#line 2899 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6304 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 601:
#line 2902 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6312 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 602:
#line 2905 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6320 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 603:
#line 2908 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6328 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 604:
#line 2911 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6336 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 605:
#line 2914 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6344 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 606:
#line 2917 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6352 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 607:
#line 2920 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6360 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 608:
#line 2923 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6368 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 609:
#line 2926 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6376 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 610:
#line 2931 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6384 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 611:
#line 2936 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6392 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 612:
#line 2941 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6400 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 627:
#line 2966 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6408 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 628:
#line 2971 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6416 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 629:
#line 2976 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6424 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 630:
#line 2981 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6432 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 631:
#line 2986 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6440 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 632:
#line 2991 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6448 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 633:
#line 2996 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6456 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 634:
#line 3001 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6464 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 635:
#line 3006 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6472 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 636:
#line 3011 "conf_parser.y" /* yacc.c:1646  */
    {
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6480 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 649:
#line 3033 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6489 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 650:
#line 3039 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6498 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 651:
#line 3045 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6507 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 652:
#line 3051 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6516 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 653:
#line 3057 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6528 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 654:
#line 3066 "conf_parser.y" /* yacc.c:1646  */
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
#line 6546 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 655:
#line 3081 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6555 "conf_parser.c" /* yacc.c:1646  */
    break;

  case 656:
#line 3087 "conf_parser.y" /* yacc.c:1646  */
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6564 "conf_parser.c" /* yacc.c:1646  */
    break;


#line 6568 "conf_parser.c" /* yacc.c:1646  */
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
