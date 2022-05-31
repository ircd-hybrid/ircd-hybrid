/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 28 "conf_parser.y"


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


#line 175 "conf_parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    BOT = 266,
    BYTES = 267,
    KBYTES = 268,
    MBYTES = 269,
    CALLER_ID_WAIT = 270,
    CAN_FLOOD = 271,
    CHANNEL = 272,
    CIDR_BITLEN_IPV4 = 273,
    CIDR_BITLEN_IPV6 = 274,
    CLASS = 275,
    CLIENT = 276,
    CLOSE = 277,
    CONNECT = 278,
    CONNECTFREQ = 279,
    CYCLE_ON_HOST_CHANGE = 280,
    DEFAULT_FLOODCOUNT = 281,
    DEFAULT_FLOODTIME = 282,
    DEFAULT_JOIN_FLOOD_COUNT = 283,
    DEFAULT_JOIN_FLOOD_TIME = 284,
    DEFAULT_MAX_CLIENTS = 285,
    DEFER = 286,
    DENY = 287,
    DESCRIPTION = 288,
    DIE = 289,
    DISABLE_AUTH = 290,
    DISABLE_FAKE_CHANNELS = 291,
    DISABLE_REMOTE_COMMANDS = 292,
    DLINE_MIN_CIDR = 293,
    DLINE_MIN_CIDR6 = 294,
    EMAIL = 295,
    ENABLE_ADMIN = 296,
    ENABLE_EXTBANS = 297,
    ENABLE_OWNER = 298,
    ENCRYPTED = 299,
    EXCEED_LIMIT = 300,
    EXEMPT = 301,
    EXPIRATION = 302,
    FAILED_OPER_NOTICE = 303,
    FLATTEN_LINKS = 304,
    FLATTEN_LINKS_DELAY = 305,
    FLATTEN_LINKS_FILE = 306,
    GECOS = 307,
    GENERAL = 308,
    HIDDEN = 309,
    HIDDEN_NAME = 310,
    HIDE_CHANS = 311,
    HIDE_IDLE = 312,
    HIDE_IDLE_FROM_OPERS = 313,
    HIDE_SERVER_IPS = 314,
    HIDE_SERVERS = 315,
    HIDE_SERVICES = 316,
    HOST = 317,
    HUB = 318,
    HUB_MASK = 319,
    INVISIBLE_ON_CONNECT = 320,
    INVITE_CLIENT_COUNT = 321,
    INVITE_CLIENT_TIME = 322,
    INVITE_DELAY_CHANNEL = 323,
    INVITE_EXPIRE_TIME = 324,
    IP = 325,
    IRCD_AUTH = 326,
    IRCD_FLAGS = 327,
    IRCD_SID = 328,
    JOIN = 329,
    KILL = 330,
    KILL_CHASE_TIME_LIMIT = 331,
    KLINE = 332,
    KLINE_EXEMPT = 333,
    KLINE_MIN_CIDR = 334,
    KLINE_MIN_CIDR6 = 335,
    KNOCK_CLIENT_COUNT = 336,
    KNOCK_CLIENT_TIME = 337,
    KNOCK_DELAY_CHANNEL = 338,
    LEAF_MASK = 339,
    LISTEN = 340,
    MASK = 341,
    MAX_ACCEPT = 342,
    MAX_BANS = 343,
    MAX_BANS_LARGE = 344,
    MAX_CHANNELS = 345,
    MAX_IDLE = 346,
    MAX_INVITES = 347,
    MAX_MONITOR = 348,
    MAX_NICK_CHANGES = 349,
    MAX_NICK_LENGTH = 350,
    MAX_NICK_TIME = 351,
    MAX_NUMBER = 352,
    MAX_TARGETS = 353,
    MAX_TOPIC_LENGTH = 354,
    MIN_IDLE = 355,
    MIN_NONWILDCARD = 356,
    MIN_NONWILDCARD_SIMPLE = 357,
    MODULE = 358,
    MODULES = 359,
    MOTD = 360,
    NAME = 361,
    NEED_IDENT = 362,
    NEED_PASSWORD = 363,
    NETWORK_DESCRIPTION = 364,
    NETWORK_NAME = 365,
    NICK = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP_GLOBAL = 370,
    NUMBER_PER_IP_LOCAL = 371,
    OPER_ONLY_UMODES = 372,
    OPER_UMODES = 373,
    OPERATOR = 374,
    OPERS_BYPASS_CALLERID = 375,
    PACE_WAIT = 376,
    PACE_WAIT_SIMPLE = 377,
    PASSWORD = 378,
    PATH = 379,
    PING_COOKIE = 380,
    PING_TIME = 381,
    PORT = 382,
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
    SPECIALS_IN_IDENT = 405,
    SPOOF = 406,
    SQUIT = 407,
    STATS_E_DISABLED = 408,
    STATS_I_OPER_ONLY = 409,
    STATS_K_OPER_ONLY = 410,
    STATS_M_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BIND = 416,
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
    T_FLOOD = 427,
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
    XLINE_EXEMPT = 486,
    QSTRING = 487,
    NUMBER = 488
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
#define BOT 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define CALLER_ID_WAIT 270
#define CAN_FLOOD 271
#define CHANNEL 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLIENT 276
#define CLOSE 277
#define CONNECT 278
#define CONNECTFREQ 279
#define CYCLE_ON_HOST_CHANGE 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_FLOODTIME 282
#define DEFAULT_JOIN_FLOOD_COUNT 283
#define DEFAULT_JOIN_FLOOD_TIME 284
#define DEFAULT_MAX_CLIENTS 285
#define DEFER 286
#define DENY 287
#define DESCRIPTION 288
#define DIE 289
#define DISABLE_AUTH 290
#define DISABLE_FAKE_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DLINE_MIN_CIDR 293
#define DLINE_MIN_CIDR6 294
#define EMAIL 295
#define ENABLE_ADMIN 296
#define ENABLE_EXTBANS 297
#define ENABLE_OWNER 298
#define ENCRYPTED 299
#define EXCEED_LIMIT 300
#define EXEMPT 301
#define EXPIRATION 302
#define FAILED_OPER_NOTICE 303
#define FLATTEN_LINKS 304
#define FLATTEN_LINKS_DELAY 305
#define FLATTEN_LINKS_FILE 306
#define GECOS 307
#define GENERAL 308
#define HIDDEN 309
#define HIDDEN_NAME 310
#define HIDE_CHANS 311
#define HIDE_IDLE 312
#define HIDE_IDLE_FROM_OPERS 313
#define HIDE_SERVER_IPS 314
#define HIDE_SERVERS 315
#define HIDE_SERVICES 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define INVISIBLE_ON_CONNECT 320
#define INVITE_CLIENT_COUNT 321
#define INVITE_CLIENT_TIME 322
#define INVITE_DELAY_CHANNEL 323
#define INVITE_EXPIRE_TIME 324
#define IP 325
#define IRCD_AUTH 326
#define IRCD_FLAGS 327
#define IRCD_SID 328
#define JOIN 329
#define KILL 330
#define KILL_CHASE_TIME_LIMIT 331
#define KLINE 332
#define KLINE_EXEMPT 333
#define KLINE_MIN_CIDR 334
#define KLINE_MIN_CIDR6 335
#define KNOCK_CLIENT_COUNT 336
#define KNOCK_CLIENT_TIME 337
#define KNOCK_DELAY_CHANNEL 338
#define LEAF_MASK 339
#define LISTEN 340
#define MASK 341
#define MAX_ACCEPT 342
#define MAX_BANS 343
#define MAX_BANS_LARGE 344
#define MAX_CHANNELS 345
#define MAX_IDLE 346
#define MAX_INVITES 347
#define MAX_MONITOR 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_LENGTH 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_TOPIC_LENGTH 354
#define MIN_IDLE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MODULE 358
#define MODULES 359
#define MOTD 360
#define NAME 361
#define NEED_IDENT 362
#define NEED_PASSWORD 363
#define NETWORK_DESCRIPTION 364
#define NETWORK_NAME 365
#define NICK 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP_GLOBAL 370
#define NUMBER_PER_IP_LOCAL 371
#define OPER_ONLY_UMODES 372
#define OPER_UMODES 373
#define OPERATOR 374
#define OPERS_BYPASS_CALLERID 375
#define PACE_WAIT 376
#define PACE_WAIT_SIMPLE 377
#define PASSWORD 378
#define PATH 379
#define PING_COOKIE 380
#define PING_TIME 381
#define PORT 382
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
#define SPECIALS_IN_IDENT 405
#define SPOOF 406
#define SQUIT 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_M_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BIND 416
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
#define T_FLOOD 427
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
#define QSTRING 487
#define NUMBER 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 698 "conf_parser.c"

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

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
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
#define YYLAST   1257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  240
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  295
/* YYNRULES -- Number of rules.  */
#define YYNRULES  669
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1320

#define YYUNDEFTOK  2
#define YYMAXUTOK   488


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   238,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   239,   234,
       2,   237,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   236,     2,   235,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
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
     861,   865,   869,   873,   877,   881,   885,   889,   900,   899,
     962,   962,   963,   964,   965,   966,   967,   968,   969,   970,
     971,   972,   973,   975,   981,   987,   993,   999,  1010,  1016,
    1027,  1034,  1033,  1039,  1039,  1040,  1044,  1048,  1052,  1056,
    1060,  1064,  1068,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1100,  1104,  1108,  1112,  1116,  1120,  1124,  1131,  1130,  1136,
    1136,  1137,  1141,  1145,  1149,  1153,  1157,  1161,  1165,  1169,
    1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,  1209,
    1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,
    1260,  1259,  1315,  1315,  1316,  1317,  1318,  1319,  1320,  1321,
    1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,  1331,
    1333,  1339,  1345,  1351,  1357,  1363,  1369,  1375,  1381,  1388,
    1394,  1400,  1406,  1415,  1425,  1424,  1430,  1430,  1431,  1435,
    1446,  1445,  1452,  1451,  1456,  1456,  1457,  1461,  1465,  1469,
    1473,  1479,  1479,  1480,  1480,  1480,  1480,  1480,  1482,  1482,
    1484,  1484,  1486,  1499,  1516,  1522,  1533,  1532,  1579,  1579,
    1580,  1581,  1582,  1583,  1584,  1585,  1586,  1587,  1588,  1590,
    1596,  1602,  1608,  1620,  1619,  1625,  1625,  1626,  1630,  1634,
    1638,  1642,  1646,  1650,  1654,  1658,  1664,  1678,  1687,  1701,
    1700,  1715,  1715,  1716,  1716,  1716,  1716,  1718,  1724,  1730,
    1740,  1742,  1742,  1743,  1743,  1745,  1762,  1761,  1784,  1784,
    1785,  1785,  1785,  1785,  1787,  1793,  1813,  1812,  1818,  1818,
    1819,  1823,  1827,  1831,  1835,  1839,  1843,  1847,  1851,  1855,
    1866,  1865,  1884,  1884,  1885,  1885,  1885,  1887,  1894,  1893,
    1899,  1899,  1900,  1904,  1908,  1912,  1916,  1920,  1924,  1928,
    1932,  1936,  1947,  1946,  2024,  2024,  2025,  2026,  2027,  2028,
    2029,  2030,  2031,  2032,  2033,  2034,  2035,  2036,  2037,  2038,
    2039,  2040,  2042,  2048,  2054,  2060,  2066,  2079,  2092,  2098,
    2104,  2108,  2115,  2114,  2119,  2119,  2120,  2124,  2130,  2141,
    2147,  2153,  2159,  2175,  2174,  2198,  2198,  2199,  2199,  2199,
    2201,  2221,  2232,  2231,  2256,  2256,  2257,  2257,  2257,  2259,
    2265,  2275,  2277,  2277,  2278,  2278,  2280,  2298,  2297,  2318,
    2318,  2319,  2319,  2319,  2321,  2327,  2337,  2339,  2339,  2340,
    2341,  2342,  2343,  2344,  2345,  2346,  2347,  2348,  2349,  2350,
    2351,  2352,  2353,  2354,  2355,  2356,  2357,  2358,  2359,  2360,
    2361,  2362,  2363,  2364,  2365,  2366,  2367,  2368,  2369,  2370,
    2371,  2372,  2373,  2374,  2375,  2376,  2377,  2378,  2379,  2380,
    2381,  2382,  2383,  2384,  2385,  2388,  2393,  2398,  2403,  2408,
    2413,  2418,  2423,  2428,  2433,  2438,  2443,  2448,  2453,  2458,
    2463,  2468,  2473,  2478,  2483,  2488,  2493,  2498,  2503,  2508,
    2513,  2518,  2523,  2528,  2533,  2538,  2543,  2548,  2553,  2558,
    2563,  2568,  2573,  2578,  2584,  2583,  2588,  2588,  2589,  2592,
    2595,  2598,  2601,  2604,  2607,  2610,  2613,  2616,  2619,  2622,
    2625,  2628,  2631,  2634,  2637,  2640,  2643,  2646,  2649,  2652,
    2658,  2657,  2662,  2662,  2663,  2666,  2669,  2672,  2675,  2678,
    2681,  2684,  2687,  2690,  2693,  2696,  2699,  2702,  2705,  2708,
    2711,  2714,  2717,  2720,  2723,  2726,  2731,  2736,  2741,  2746,
    2755,  2757,  2757,  2758,  2759,  2760,  2761,  2762,  2763,  2764,
    2765,  2766,  2767,  2768,  2769,  2770,  2771,  2772,  2773,  2774,
    2775,  2777,  2782,  2788,  2794,  2799,  2804,  2809,  2814,  2819,
    2824,  2829,  2834,  2839,  2844,  2849,  2854,  2859,  2868,  2870,
    2870,  2871,  2872,  2873,  2874,  2875,  2876,  2877,  2878,  2879,
    2880,  2882,  2888,  2904,  2913,  2919,  2925,  2931,  2940,  2946
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN",
  "AWAY_COUNT", "AWAY_TIME", "BOT", "BYTES", "KBYTES", "MBYTES",
  "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL", "CIDR_BITLEN_IPV4",
  "CIDR_BITLEN_IPV6", "CLASS", "CLIENT", "CLOSE", "CONNECT", "CONNECTFREQ",
  "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT", "DEFAULT_FLOODTIME",
  "DEFAULT_JOIN_FLOOD_COUNT", "DEFAULT_JOIN_FLOOD_TIME",
  "DEFAULT_MAX_CLIENTS", "DEFER", "DENY", "DESCRIPTION", "DIE",
  "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DLINE_MIN_CIDR", "DLINE_MIN_CIDR6", "EMAIL", "ENABLE_ADMIN",
  "ENABLE_EXTBANS", "ENABLE_OWNER", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
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
  "MAX_IDLE", "MAX_INVITES", "MAX_MONITOR", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESCRIPTION", "NETWORK_NAME",
  "NICK", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP_GLOBAL", "NUMBER_PER_IP_LOCAL", "OPER_ONLY_UMODES",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT", "RSA_PRIVATE_KEY_FILE",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SEND_PASSWORD", "SENDQ", "SERVERHIDE", "SERVERINFO", "SHORT_MOTD",
  "SPECIALS_IN_IDENT", "SPOOF", "SQUIT", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_M_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL",
  "T_BIND", "T_CALLERID", "T_CCONN", "T_COMMAND", "T_CLUSTER", "T_DEAF",
  "T_DEBUG", "T_DLINE", "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FLOOD",
  "T_GLOBOPS", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG",
  "T_NCHANGE", "T_NONONREG", "T_OPME", "T_PREPEND", "T_PSEUDO", "T_RECVQ",
  "T_REJ", "T_RESTART", "T_SERVER", "T_SERVICE", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_TARGET",
  "T_TLS", "T_UMODES", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL", "THROTTLE_COUNT",
  "THROTTLE_TIME", "TIMEOUT", "TLS_CERTIFICATE_FILE",
  "TLS_CERTIFICATE_FINGERPRINT", "TLS_CIPHER_LIST", "TLS_CIPHER_SUITES",
  "TLS_CONNECTION_REQUIRED", "TLS_DH_PARAM_FILE",
  "TLS_MESSAGE_DIGEST_ALGORITHM", "TLS_SUPPORTED_GROUPS", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "TYPE", "UNKLINE", "USE_LOGGING", "USER",
  "VHOST", "VHOST6", "WARN_NO_CONNECT_BLOCK", "WHOIS",
  "WHOWAS_HISTORY_LENGTH", "XLINE", "XLINE_EXEMPT", "QSTRING", "NUMBER",
  "';'", "'}'", "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_tls_certificate_file", "serverinfo_rsa_private_key_file",
  "serverinfo_tls_dh_param_file", "serverinfo_tls_cipher_list",
  "serverinfo_tls_cipher_suites",
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
  "logging_file_type_item", "oper_entry", "$@5", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_whois",
  "oper_encrypted", "oper_tls_certificate_fingerprint",
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
  "general_away_count", "general_away_time", "general_max_monitor",
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
  "general_short_motd", "general_no_oper_flood",
  "general_specials_in_ident", "general_max_targets",
  "general_ping_cookie", "general_disable_auth", "general_throttle_count",
  "general_throttle_time", "general_oper_umodes", "$@25", "umode_oitems",
  "umode_oitem", "general_oper_only_umodes", "$@26", "umode_items",
  "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_default_floodtime", "channel_entry", "channel_items",
  "channel_item", "channel_enable_extbans", "channel_enable_owner",
  "channel_enable_admin", "channel_disable_fake_channels",
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
static const yytype_int16 yytoknum[] =
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
     485,   486,   487,   488,    59,   125,   123,    61,    44,    58
};
# endif

#define YYPACT_NINF (-979)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -979,   878,  -979,  -230,  -201,  -196,  -979,  -979,  -979,  -194,
    -979,  -193,  -979,  -979,  -979,  -186,  -979,  -979,  -979,  -175,
    -154,  -979,  -152,  -979,  -151,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   339,  1004,  -149,  -139,  -137,    24,  -115,   409,  -113,
     -77,   -70,    17,   -57,   -56,   -50,   763,   542,   -47,   108,
     -41,    55,   -23,  -181,   -21,   -20,   -17,     5,  -979,  -979,
    -979,  -979,  -979,   -12,    -9,    -8,    -6,    -2,    47,    52,
      59,    61,    62,    64,    72,    76,    79,    81,    87,    96,
     155,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   895,
     654,    23,  -979,   102,    20,  -979,  -979,    13,  -979,   104,
     106,   115,   116,   119,   120,   125,   126,   128,   130,   131,
     132,   133,   137,   139,   140,   143,   144,   145,   152,   156,
     157,   158,   162,  -979,  -979,   163,   164,   165,   166,   167,
     170,   171,   174,   177,   180,   186,   193,   194,   195,   202,
     204,   213,   215,   217,    53,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   275,    35,   313,  -134,   218,   221,    14,  -979,  -979,
    -979,    48,   314,   292,  -979,   223,   224,   225,   226,   227,
     228,   240,   242,   246,    15,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,    60,   247,   249,   250,   253,
     255,   258,   260,   261,   263,   264,   271,   272,   276,   278,
     279,   281,    95,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
      71,   248,   283,    16,  -979,  -979,  -979,   280,   191,  -979,
     285,    30,  -979,  -979,    57,  -979,   160,   274,   287,   289,
    -979,   291,   302,   331,   334,   335,   346,   320,   302,   302,
     302,   321,   302,   302,   322,   323,   324,   327,   336,  -979,
     337,   340,   342,   343,  -979,   344,   345,   349,   351,   352,
     353,   354,   355,   357,   358,   359,   245,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,   364,   367,   369,   370,   371,   372,   373,
    -979,   374,   375,   377,   381,   382,   383,   388,   389,   282,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   392,   395,    19,
    -979,  -979,  -979,   402,   399,  -979,  -979,   398,   406,    21,
    -979,  -979,  -979,   440,   302,   341,   302,   302,   441,   350,
     302,   443,   417,   420,   448,   450,   302,   425,   432,   433,
     435,   438,   302,   439,   442,   447,   467,   444,   445,   470,
     302,   302,   479,   480,   455,   483,   484,   487,   488,   489,
     491,   493,   468,   302,   302,   302,   496,   471,   469,  -979,
     472,   473,   478,  -979,   482,   490,   492,   494,   497,   198,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
     498,   499,    38,  -979,  -979,  -979,   474,   500,   502,  -979,
     504,  -979,    33,  -979,  -979,  -979,  -979,  -979,   475,   485,
     508,  -979,   509,   507,   511,    22,  -979,  -979,  -979,   512,
     513,   514,  -979,   516,   519,  -979,   525,   526,   528,   529,
     214,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   515,   530,   532,   535,    40,  -979,  -979,  -979,
    -979,   518,   522,   302,   501,   524,   541,   539,   568,   571,
     544,  -979,  -979,   551,   554,   582,   557,   558,   561,   563,
     564,   565,   569,   572,   573,   577,   578,   579,   587,   586,
    -979,   591,   566,  -979,    31,  -979,  -979,  -979,  -979,   615,
     592,  -979,   365,   593,   594,   597,   600,   602,    18,  -979,
    -979,  -979,  -979,  -979,   598,   607,  -979,   608,   610,  -979,
     611,     6,  -979,  -979,  -979,  -979,   616,   618,   619,  -979,
     620,   407,   622,   623,   624,   628,   630,   633,   634,   636,
     637,   638,   639,   640,   641,   651,   653,   655,  -979,  -979,
     657,   659,   302,   612,   664,   302,   667,   302,   670,   671,
     672,   673,   302,   678,   678,   681,  -979,  -979,   680,  -148,
     684,   712,   688,   689,   685,   691,   693,   694,   696,   697,
     302,   700,   701,   692,  -979,   702,   703,   704,  -979,   705,
    -979,   708,   709,   710,  -979,   711,   713,   716,   717,   718,
     720,   721,   722,   723,   724,   725,   726,   727,   728,   730,
     731,   732,   734,   735,   736,   737,   738,   739,   740,   613,
     666,   741,   742,   743,   744,   745,   746,   747,   750,   753,
     754,   755,   756,   757,   759,   760,   762,   764,   765,   766,
    -979,  -979,   770,   797,   699,   772,   715,   774,   775,   776,
     778,  -979,   782,   783,   784,  -979,  -979,   785,   787,   706,
     789,   786,  -979,   790,   793,  -979,  -979,   791,   796,   795,
    -979,  -979,   798,   810,   794,   802,   803,   799,   805,   832,
     807,   812,   808,  -979,  -979,   816,   817,   818,   819,  -979,
     820,   821,   823,   824,   825,   826,   828,   829,   830,  -979,
     831,   833,   834,   840,   841,   842,   843,   844,   846,   847,
     848,   849,   850,   854,   855,   856,  -979,  -979,   859,   814,
     861,  -979,   863,  -979,    82,  -979,   866,   867,   868,   869,
     870,  -979,   871,  -979,  -979,   874,   815,   875,   876,  -979,
    -979,  -979,  -979,  -979,   302,   302,   302,   302,   302,   302,
     302,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   877,
     879,   880,   -55,   881,   882,   883,   884,   885,   886,   887,
     888,   889,    34,   890,   891,  -979,   892,   893,   894,   896,
     897,   898,   899,    29,   900,   901,   902,   903,   904,   905,
     906,   907,  -979,   908,   909,  -979,  -979,   910,   911,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -208,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -205,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   912,   913,   368,   914,   915,   916,   917,   918,  -979,
     919,   920,  -979,   921,   922,   269,   356,   606,  -979,  -979,
    -979,  -979,   923,   924,  -979,   925,   926,   510,   927,   928,
     714,   929,   930,   931,   932,  -979,   933,   934,   935,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   936,   401,  -979,  -979,   937,
     865,   872,  -979,    56,  -979,  -979,  -979,  -979,   938,   939,
     940,   941,  -979,  -979,   942,   462,   943,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -183,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   678,   678,   678,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -167,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   613,  -979,   666,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -157,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -136,  -979,   945,   789,   946,  -979,  -979,  -979,
    -979,  -979,  -979,   466,  -979,   698,   707,  -979,  -979,   864,
     873,  -979,  -979,   944,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,   -99,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   -81,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,   -62,  -979,  -979,   947,  -189,   948,   950,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   -53,  -979,  -979,  -979,   -55,
    -979,  -979,  -979,  -979,    29,  -979,  -979,  -979,   368,  -979,
     269,  -979,  -979,  -979,   588,   973,   614,   994,   809,  1048,
    -979,   510,  -979,   714,  -979,   401,   952,   953,   954,   229,
    -979,  -979,   462,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   955,  -979,  -979
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   230,   392,   442,     0,
     457,     0,   296,   433,   270,     0,    98,   148,   329,     0,
       0,   370,     0,   107,     0,   346,     3,    23,    11,     4,
      24,    25,     5,     6,     8,     9,    10,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    21,     7,    12,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    90,    91,
      93,    92,   630,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,   627,   628,   629,   626,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   613,   614,   624,   625,     0,
       0,     0,   455,     0,     0,   453,   454,     0,   514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   580,   554,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   468,   469,   470,   512,   476,
     513,   507,   508,   509,   510,   480,   471,   472,   473,   474,
     475,   477,   478,   479,   481,   482,   511,   486,   487,   488,
     489,   485,   484,   490,   497,   498,   491,   492,   493,   483,
     495,   505,   506,   503,   504,   496,   494,   501,   502,   499,
     500,     0,     0,     0,     0,     0,     0,     0,    46,    47,
      48,     0,     0,     0,   660,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   650,   651,   652,   653,   654,
     655,   656,   658,   657,   659,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    54,    67,    65,    63,    68,    69,    70,
      64,    55,    66,    57,    58,    59,    60,    61,    62,    56,
       0,     0,     0,     0,   122,   123,   124,     0,     0,   344,
       0,     0,   342,   343,     0,    94,     0,     0,     0,     0,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   611,
       0,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   233,   234,   237,
     239,   240,   241,   242,   243,   244,   245,   235,   236,   238,
     246,   247,   248,     0,     0,     0,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,   396,   397,   398,   399,   400,   401,   402,   404,   403,
     406,   410,   407,   408,   409,   405,   448,     0,     0,     0,
     445,   446,   447,     0,     0,   452,   463,     0,     0,     0,
     460,   461,   462,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
       0,     0,     0,   313,     0,     0,     0,     0,     0,     0,
     299,   300,   301,   302,   307,   303,   304,   305,   306,   439,
       0,     0,     0,   436,   437,   438,     0,     0,     0,   272,
       0,   284,     0,   282,   283,   285,   286,    49,     0,     0,
       0,    45,     0,     0,     0,     0,   101,   102,   103,     0,
       0,     0,   197,     0,     0,   171,     0,     0,     0,     0,
       0,   151,   152,   153,   154,   155,   158,   159,   160,   157,
     156,   161,     0,     0,     0,     0,     0,   332,   333,   334,
     335,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   649,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      53,     0,     0,   378,     0,   373,   374,   375,   125,     0,
       0,   121,     0,     0,     0,     0,     0,     0,     0,   110,
     111,   113,   112,   114,     0,     0,   341,     0,     0,   356,
       0,     0,   349,   350,   351,   352,     0,     0,     0,    88,
       0,    28,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   610,   249,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   232,   411,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   394,     0,     0,     0,   444,     0,
     451,     0,     0,     0,   459,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     466,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   298,     0,     0,     0,   435,   287,     0,     0,     0,
       0,     0,   281,     0,     0,    44,   104,     0,     0,     0,
     100,   162,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   150,   336,     0,     0,     0,     0,   331,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   648,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,   376,     0,     0,
       0,   372,     0,   120,     0,   115,     0,     0,     0,     0,
       0,   109,     0,   340,   353,     0,     0,     0,     0,   348,
      97,    96,    95,   646,    28,    28,    28,    28,    28,    28,
      28,    30,    29,   647,   634,   633,   631,   632,   635,   636,
     637,   638,   639,   640,   641,   644,   645,   642,   643,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,   231,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   393,     0,     0,   443,   456,     0,     0,   458,
     526,   530,   515,   516,   543,   519,   608,   609,   551,   520,
     521,   525,   533,   524,   522,   523,   529,   517,   528,   527,
     549,   606,   607,   547,   584,   605,   590,   591,   592,   601,
     585,   586,   587,   596,   604,   588,   598,   602,   593,   603,
     594,   597,   589,   600,   595,   599,     0,   583,   558,   579,
     563,   564,   565,   575,   559,   560,   561,   570,   578,   562,
     572,   576,   567,   577,   568,   571,   566,   574,   569,   573,
       0,   557,   544,   542,   545,   550,   546,   548,   535,   541,
     540,   536,   537,   538,   539,   552,   553,   532,   531,   534,
     518,     0,     0,     0,     0,     0,     0,     0,     0,   297,
       0,     0,   434,     0,     0,     0,   292,   288,   291,   271,
      50,    51,     0,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   149,     0,     0,     0,   330,
     664,   661,   662,   663,   668,   667,   669,   665,   666,    84,
      81,    87,    80,    85,    86,    79,    83,    82,    73,    72,
      75,    76,    74,    77,    78,     0,     0,   371,   126,     0,
       0,     0,   138,     0,   130,   131,   133,   132,     0,     0,
       0,     0,   108,   345,     0,     0,     0,   347,    31,    32,
      33,    34,    35,    36,    37,   259,   260,   254,   269,   268,
       0,   267,   255,   263,   256,   262,   250,   261,   253,   252,
     251,    38,    38,    38,    40,    39,   257,   258,   417,   420,
     421,   431,   428,   413,   429,   426,   427,     0,   425,   430,
     412,   419,   416,   415,   414,   418,   432,   449,   450,   464,
     465,   581,     0,   555,     0,   311,   312,   321,   317,   318,
     320,   325,   322,   323,   324,   319,     0,   316,   310,   328,
     327,   326,   309,   441,   440,   295,   294,   279,   280,   277,
     278,   276,     0,   275,     0,     0,     0,   105,   106,   170,
     167,   217,   229,   204,   213,     0,   202,   207,   223,     0,
     216,   221,   227,   206,   209,   218,   220,   224,   214,   222,
     210,   228,   212,   219,   208,   211,     0,   200,   163,   165,
     175,   196,   180,   181,   182,   192,   176,   177,   178,   187,
     195,   179,   189,   193,   184,   194,   185,   188,   183,   191,
     186,   190,     0,   174,   168,   169,   164,   166,   339,   337,
     338,   377,   382,   388,   391,   384,   390,   385,   389,   387,
     383,   386,     0,   381,   134,     0,     0,     0,     0,   129,
     117,   116,   118,   119,   354,   360,   366,   369,   362,   368,
     363,   367,   365,   361,   364,     0,   359,   355,   265,     0,
      41,    42,    43,   423,     0,   582,   556,   314,     0,   273,
       0,   293,   290,   289,     0,     0,     0,     0,     0,     0,
     198,     0,   172,     0,   379,     0,     0,     0,     0,     0,
     128,   357,     0,   266,   424,   315,   274,   203,   226,   201,
     225,   215,   205,   199,   173,   380,   135,   137,   136,   146,
     145,   141,   143,   147,   144,   140,   142,     0,   358,   139
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -979,  -979,  -979,  -357,  -310,  -978,  -643,  -979,  -979,   963,
    -979,  -979,  -979,  -979,   949,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  1105,  -979,  -979,  -979,  -979,  -979,  -979,
     686,  -979,  -979,  -979,  -979,  -979,   604,  -979,  -979,  -979,
    -979,  -979,  -979,   951,  -979,  -979,  -979,  -979,   141,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,   675,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,   -90,
    -979,  -979,  -979,   -85,  -979,  -979,  -979,   851,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   -61,  -979,  -979,  -979,  -979,
    -979,   -71,  -979,   719,  -979,  -979,  -979,    45,  -979,  -979,
    -979,  -979,  -979,   733,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   -67,  -979,  -979,  -979,  -979,  -979,  -979,   668,  -979,
    -979,  -979,  -979,  -979,   956,  -979,  -979,  -979,  -979,   605,
    -979,  -979,  -979,  -979,  -979,   -89,  -979,  -979,  -979,   631,
    -979,  -979,  -979,  -979,   -78,  -979,  -979,  -979,   835,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,   -54,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
     748,  -979,  -979,  -979,  -979,  -979,   813,  -979,  -979,  -979,
    -979,  1084,  -979,  -979,  -979,  -979,   800,  -979,  -979,  -979,
    -979,  1039,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,    91,  -979,  -979,  -979,    94,  -979,
    -979,  -979,  -979,  -979,  -979,  1117,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979,   974,  -979,  -979,  -979,  -979,
    -979,  -979,  -979,  -979,  -979
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    26,   831,   832,  1094,  1095,    27,   227,   228,
     229,   230,    28,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,    29,    77,    78,    79,    80,    81,    30,    63,   505,
     506,   507,   508,    31,    70,   588,   589,   590,   591,   592,
     593,    32,   293,   294,   295,   296,   297,  1053,  1054,  1055,
    1056,  1057,  1237,  1317,    33,    64,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   757,  1212,  1213,
     531,   754,  1186,  1187,    34,    53,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   633,  1080,  1081,    35,    61,   491,   739,
    1152,  1153,   492,   493,   494,  1156,   997,   998,   495,   496,
      36,    59,   469,   470,   471,   472,   473,   474,   475,   724,
    1136,  1137,   476,   477,   478,    37,    65,   536,   537,   538,
     539,   540,    38,   301,   302,   303,    39,    72,   601,   602,
     603,   604,   605,   816,  1255,  1256,    40,    68,   574,   575,
     576,   577,   799,  1232,  1233,    41,    54,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,   390,   654,
    1107,  1108,   391,   392,   393,   394,   395,    42,    60,   482,
     483,   484,   485,    43,    55,   399,   400,   401,   402,    44,
     124,   125,   126,    45,    57,   409,   410,   411,   412,    46,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,   438,   960,   961,   216,   437,   936,   937,   217,
     218,   219,   220,    47,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,    48,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     863,   864,   612,  1078,    49,    50,    73,   597,   618,   619,
     620,  1287,   622,   623,   406,   224,   234,   291,   224,   583,
     396,   122,   406,   502,   396,   122,  1121,   867,   868,  1123,
    1122,   299,   571,  1124,   486,    51,   479,  1105,    74,   479,
      52,   532,    56,    58,   862,    75,  1091,  1092,  1093,   502,
      62,  1258,   235,   305,   128,  1259,   299,  1049,   597,   129,
     130,    66,   131,   132,   236,   237,   238,  1263,   133,   239,
     240,  1264,   571,  1079,   241,   242,   243,  1267,   134,   135,
     136,  1268,    67,  1049,    69,    71,   533,   119,   137,   397,
     123,   138,   139,   397,   123,   487,   255,   120,  1269,   121,
     497,   140,  1270,   488,   676,   489,   678,   679,   503,   291,
     682,    76,   598,  1260,  1261,  1262,   688,   225,   141,   407,
     225,   127,   694,   221,   584,   256,   534,   407,   257,   142,
     702,   703,   143,   144,   503,  1280,   300,   572,   226,  1281,
     145,   226,   408,   715,   716,   717,   146,   147,   398,   148,
     408,   149,   398,  1282,   150,   151,    82,  1283,   258,   222,
     490,   300,  1050,   598,   480,   152,   223,   480,   259,   535,
     153,   154,  1284,   155,   156,   157,  1285,   572,   158,   231,
     232,  1291,   585,    83,    84,  1292,   233,  -127,  1050,   290,
     260,    85,   583,   504,   261,   298,    86,    87,    88,   460,
     586,   262,   159,   160,   263,   264,   161,   162,   163,   164,
     165,   166,   167,   304,   587,   509,   306,   307,   461,   504,
     308,    89,    90,    91,    92,   311,  1106,   599,   312,   313,
     600,   314,   265,   772,   510,   315,    93,    94,    95,   292,
     309,   818,   462,    96,    97,    98,   330,    99,  1051,   500,
     550,   580,   573,   810,   667,   404,   673,   749,   511,   481,
     168,   169,   481,   331,   332,   595,   800,   862,   741,   333,
     463,   170,   171,   734,  1051,   768,   460,  1052,   599,  -127,
     172,   600,   173,   363,   316,   364,   512,   365,   458,   317,
    1147,  1238,   573,   532,   552,   461,   318,   584,   319,   320,
    1148,   321,   366,  1052,  1309,   266,  1310,   267,   268,   322,
     269,   270,   271,   323,   486,   509,   324,   334,   325,   462,
     513,   464,   851,  1149,   326,   854,   367,   856,   465,   466,
     569,   292,   861,   327,   510,   335,   336,   514,   533,   403,
      73,   413,   337,   414,   368,   338,   369,   463,  1311,   467,
     879,   339,   415,   416,   370,   585,   417,   418,   511,   340,
     341,   342,   419,   420,  1312,   421,   371,   422,   423,   424,
     425,   343,    74,   586,   426,   487,   427,   428,   534,    75,
     429,   430,   431,   488,  1127,   489,   512,   587,   372,   432,
     328,   344,   606,   433,   434,   435,  1313,  1314,   464,   436,
     439,   440,   441,   442,   443,   465,   466,   444,   445,   373,
     128,   446,   515,  1128,   447,   129,   130,   448,   131,   132,
     513,   535,   468,   449,   133,   516,   467,   374,   517,   345,
     450,   451,   452,   730,   134,   135,   136,   514,   518,   453,
     490,   454,   519,   375,   137,    76,  1129,   138,   139,   762,
     455,   582,   456,  1315,   457,   498,  1150,   140,   499,  1316,
     541,   542,   543,   544,   545,   546,  1151,  1068,  1069,  1070,
    1071,  1072,  1073,  1074,   141,  1130,  1131,   547,  1222,   548,
     645,  1132,   578,   549,   553,   142,   554,   555,   143,   144,
     556,   376,   557,   377,   378,   558,   145,   559,   560,   468,
     561,   562,   146,   147,  1133,   148,   607,   149,   563,   564,
     150,   151,   515,   565,  1161,   566,   567,   663,   568,   608,
     579,   152,   594,   609,   610,   516,   153,   154,   517,   155,
     156,   157,  1162,  1163,   158,   611,  1223,   613,   518,  1245,
     614,   615,   519,   255,  1164,   824,   825,   826,   827,   828,
     829,   830,   616,   617,   621,   624,   625,   626,   159,   160,
     627,  1224,   161,   162,   163,   164,   165,   166,   167,  1225,
     628,   629,   256,  1134,   677,   257,  1154,   630,  1226,   631,
     632,   634,   635,   681,  1165,  1166,   636,  1167,   637,   638,
     639,   640,   641,  1288,   642,   643,   644,  1246,   647,  1135,
    1227,   804,  1228,  1229,   648,   258,   649,   650,   651,   652,
     653,   655,   656,  1168,   657,   259,   168,   169,   658,   659,
     660,  1169,  1247,  1230,   914,   661,   662,   170,   171,   665,
    1248,  1231,   666,   670,   669,   671,   172,   260,   173,  1249,
     611,   261,  1170,   672,  1171,  1172,   675,   680,   262,   683,
     684,   263,   264,   685,   686,   363,   687,   364,   689,   365,
     915,  1250,  1173,  1251,  1252,   690,   691,   916,   692,   917,
     918,   693,   695,   698,   366,   696,   701,   938,  1174,   265,
     697,   699,   700,  1175,  1253,   704,   705,  1176,   706,   707,
     708,  1177,  1254,   709,   710,   711,  1178,   712,   367,   713,
    1179,   714,   718,   720,   719,  1274,   721,   743,   736,  1180,
     722,  1181,  1182,   939,  1183,   723,   368,   744,   369,   725,
     940,  1297,   941,   942,   770,  1190,   370,   726,   771,   727,
     774,   728,  1184,   773,   729,   732,   733,   737,   371,   738,
    1185,   740,   745,   746,   747,   776,   751,  1299,   748,   764,
     752,   753,   266,   755,   267,   268,   756,   269,   270,   271,
     372,  1191,   758,   759,   234,   760,   761,   765,  1192,   766,
    1193,  1194,   767,   775,   777,   919,   920,   778,   779,   921,
     922,   373,   923,   924,   780,   925,   781,   926,   782,   783,
     927,   784,   928,   929,   785,   786,   787,   788,   930,   374,
     235,   789,   931,   798,   790,   791,   932,   933,   934,   792,
     793,   794,   236,   237,   238,   375,   935,   239,   240,   795,
     796,   802,   241,   242,   243,   797,   803,   805,   943,   944,
     812,   806,   945,   946,   807,   947,   948,   808,   949,   809,
     950,   813,   814,   951,  1155,   952,   953,   815,   817,   852,
     820,   954,   821,   822,   823,   955,   833,   834,   835,   956,
     957,   958,   836,   376,   837,   377,   378,   838,   839,   959,
     840,   841,   842,   843,   844,   845,  1195,  1196,     2,     3,
    1197,  1198,     4,  1199,  1200,   846,  1201,   847,  1202,   848,
     849,  1203,   850,  1204,  1205,     5,   330,   853,     6,  1206,
     855,     7,   857,  1207,   858,   859,   860,  1208,  1209,  1210,
       8,   862,   866,   331,   332,   865,   869,  1211,   870,   333,
     871,   872,   873,   874,     9,   875,   882,   876,   877,   878,
      10,    11,   880,   881,   883,   884,   983,  1275,   885,   886,
     887,   888,  1301,   995,   889,   890,  1276,   891,   985,    12,
     892,   893,   894,    13,   895,   896,   897,   898,   899,   900,
     901,   902,   903,    14,   904,   905,   906,   334,   907,   908,
     909,   910,   911,   912,   913,   962,   963,   964,   965,   966,
     967,   968,    15,    16,   969,   335,   336,   970,   971,   972,
     973,   974,   337,   975,   976,   338,   977,    17,   978,   979,
     980,   339,   981,   982,   984,    82,   986,   987,   988,   340,
     341,   342,   989,    18,   990,   991,  1006,   993,   992,   994,
     999,   343,   996,  1002,  1000,    19,    20,  1001,  1003,  1004,
    1005,  1007,    83,    84,  1008,  1009,  1010,  1011,  1012,  1013,
      85,   344,  1015,    21,  1014,    86,    87,    88,  1016,  1017,
    1018,  1046,  1065,  1019,  1020,  1021,    22,  1022,  1023,  1024,
    1025,    23,  1026,  1027,  1028,  1029,    24,  1030,  1031,    25,
      89,    90,    91,    92,  1032,  1033,  1034,  1035,  1036,   345,
    1037,  1038,  1039,  1040,  1041,    93,    94,    95,  1042,  1043,
    1044,  1045,    96,    97,    98,  1047,    99,  1048,  1058,  1059,
    1060,  1061,  1235,  1277,  1062,  1063,  1064,  1066,  1298,  1236,
    1067,  1075,  1278,  1076,  1077,  1082,  1083,  1084,  1085,  1086,
    1087,  1088,  1089,  1090,  1096,  1097,  1098,  1099,  1100,  1300,
    1101,  1102,  1103,  1104,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1119,  1120,  1125,  1126,  1138,  1139,
    1140,  1141,  1142,  1143,  1144,  1145,  1146,  1157,  1158,  1159,
    1160,  1188,  1189,  1214,  1215,  1216,  1217,  1218,  1219,  1220,
    1221,  1234,  1240,  1241,  1242,  1243,  1244,  1257,  1271,  1286,
    1273,  1302,   310,  1279,  1290,  1289,  1306,  1307,  1308,  1319,
     501,   750,   811,  1304,  1239,   763,  1303,   646,  1293,  1296,
    1272,  1295,   731,  1318,   769,   801,   819,  1305,   405,   674,
    1294,   742,   668,   459,   664,  1266,  1265,   329,   551,     0,
       0,   570,     0,     0,     0,     0,     0,     0,     0,     0,
     735,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   581,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   596
};

static const yytype_int16 yycheck[] =
{
     643,   644,   312,    58,   234,   235,     1,     1,   318,   319,
     320,   200,   322,   323,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,   234,   175,   176,   234,
     238,     1,     1,   238,     1,   236,     1,     8,    33,     1,
     236,     1,   236,   236,   233,    40,    12,    13,    14,     1,
     236,   234,    37,   234,     1,   238,     1,     1,     1,     6,
       7,   236,     9,    10,    49,    50,    51,   234,    15,    54,
      55,   238,     1,   128,    59,    60,    61,   234,    25,    26,
      27,   238,   236,     1,   236,   236,    46,   236,    35,    70,
      70,    38,    39,    70,    70,    62,     1,   236,   234,   236,
     234,    48,   238,    70,   414,    72,   416,   417,    86,     1,
     420,   106,   106,  1091,  1092,  1093,   426,   103,    65,   106,
     103,   236,   432,   236,   106,    30,    86,   106,    33,    76,
     440,   441,    79,    80,    86,   234,   106,   106,   124,   238,
      87,   124,   129,   453,   454,   455,    93,    94,   129,    96,
     129,    98,   129,   234,   101,   102,     1,   238,    63,   236,
     127,   106,   106,   106,   129,   112,   236,   129,    73,   129,
     117,   118,   234,   120,   121,   122,   238,   106,   125,   236,
     236,   234,   164,    28,    29,   238,   236,   171,   106,   236,
      95,    36,     1,   171,    99,   236,    41,    42,    43,     1,
     182,   106,   149,   150,   109,   110,   153,   154,   155,   156,
     157,   158,   159,   236,   196,     1,   237,   237,    20,   171,
     237,    66,    67,    68,    69,   237,   197,   221,   237,   237,
     224,   237,   137,   543,    20,   237,    81,    82,    83,   223,
     235,   235,    44,    88,    89,    90,     1,    92,   192,   235,
     235,   235,   221,   235,   235,   235,   235,   235,    44,   224,
     207,   208,   224,    18,    19,   235,   235,   233,   235,    24,
      72,   218,   219,   235,   192,   235,     1,   221,   221,   171,
     227,   224,   229,     1,   237,     3,    72,     5,   235,   237,
      21,   235,   221,     1,   234,    20,   237,   106,   237,   237,
      31,   237,    20,   221,    75,   210,    77,   212,   213,   237,
     215,   216,   217,   237,     1,     1,   237,    72,   237,    44,
     106,   123,   632,    54,   237,   635,    44,   637,   130,   131,
     235,   223,   642,   237,    20,    90,    91,   123,    46,   237,
       1,   237,    97,   237,    62,   100,    64,    72,   119,   151,
     660,   106,   237,   237,    72,   164,   237,   237,    44,   114,
     115,   116,   237,   237,   135,   237,    84,   237,   237,   237,
     237,   126,    33,   182,   237,    62,   237,   237,    86,    40,
     237,   237,   237,    70,    16,    72,    72,   196,   106,   237,
     235,   146,   232,   237,   237,   237,   167,   168,   123,   237,
     237,   237,   237,   237,   237,   130,   131,   237,   237,   127,
       1,   237,   198,    45,   237,     6,     7,   237,     9,    10,
     106,   129,   224,   237,    15,   211,   151,   145,   214,   184,
     237,   237,   237,   235,    25,    26,    27,   123,   224,   237,
     127,   237,   228,   161,    35,   106,    78,    38,    39,   235,
     237,   171,   237,   224,   237,   237,   187,    48,   237,   230,
     237,   237,   237,   237,   237,   237,   197,   824,   825,   826,
     827,   828,   829,   830,    65,   107,   108,   237,    77,   237,
     235,   113,   234,   237,   237,    76,   237,   237,    79,    80,
     237,   209,   237,   211,   212,   237,    87,   237,   237,   224,
     237,   237,    93,    94,   136,    96,   232,    98,   237,   237,
     101,   102,   198,   237,     4,   237,   237,   235,   237,   232,
     237,   112,   237,   234,   233,   211,   117,   118,   214,   120,
     121,   122,    22,    23,   125,   233,   135,   206,   224,    77,
     206,   206,   228,     1,    34,   138,   139,   140,   141,   142,
     143,   144,   206,   233,   233,   233,   233,   233,   149,   150,
     233,   160,   153,   154,   155,   156,   157,   158,   159,   168,
     234,   234,    30,   205,   233,    33,   220,   237,   177,   237,
     237,   237,   237,   233,    74,    75,   237,    77,   237,   237,
     237,   237,   237,  1236,   237,   237,   237,   135,   234,   231,
     199,   236,   201,   202,   237,    63,   237,   237,   237,   237,
     237,   237,   237,   103,   237,    73,   207,   208,   237,   237,
     237,   111,   160,   222,    11,   237,   237,   218,   219,   237,
     168,   230,   237,   234,   232,   237,   227,    95,   229,   177,
     233,    99,   132,   237,   134,   135,   206,   206,   106,   206,
     233,   109,   110,   233,   206,     1,   206,     3,   233,     5,
      47,   199,   152,   201,   202,   233,   233,    54,   233,    56,
      57,   233,   233,   206,    20,   233,   206,    11,   168,   137,
     233,   237,   237,   173,   222,   206,   206,   177,   233,   206,
     206,   181,   230,   206,   206,   206,   186,   206,    44,   206,
     190,   233,   206,   234,   233,   239,   234,   232,   234,   199,
     237,   201,   202,    47,   204,   237,    62,   232,    64,   237,
      54,   133,    56,    57,   206,    11,    72,   237,   206,   237,
     206,   237,   222,   232,   237,   237,   237,   237,    84,   237,
     230,   237,   234,   234,   237,   206,   234,   133,   237,   234,
     237,   237,   210,   237,   212,   213,   237,   215,   216,   217,
     106,    47,   237,   237,     1,   237,   237,   237,    54,   237,
      56,    57,   237,   232,   206,   162,   163,   206,   234,   166,
     167,   127,   169,   170,   233,   172,   232,   174,   206,   232,
     177,   233,   179,   180,   233,   232,   232,   232,   185,   145,
      37,   232,   189,   237,   232,   232,   193,   194,   195,   232,
     232,   232,    49,    50,    51,   161,   203,    54,    55,   232,
     234,   206,    59,    60,    61,   234,   234,   234,   162,   163,
     232,   237,   166,   167,   237,   169,   170,   237,   172,   237,
     174,   234,   234,   177,   238,   179,   180,   237,   237,   237,
     234,   185,   234,   234,   234,   189,   234,   234,   234,   193,
     194,   195,   234,   209,   234,   211,   212,   234,   234,   203,
     234,   234,   234,   234,   234,   234,   162,   163,     0,     1,
     166,   167,     4,   169,   170,   234,   172,   234,   174,   234,
     233,   177,   233,   179,   180,    17,     1,   233,    20,   185,
     233,    23,   232,   189,   233,   233,   233,   193,   194,   195,
      32,   233,   232,    18,    19,   234,   232,   203,   206,    24,
     232,   232,   237,   232,    46,   232,   234,   233,   232,   232,
      52,    53,   232,   232,   232,   232,   237,   239,   234,   234,
     232,   232,   133,   237,   234,   234,   239,   234,   233,    71,
     234,   234,   234,    75,   234,   234,   234,   234,   234,   234,
     234,   234,   234,    85,   234,   234,   234,    72,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   104,   105,   234,    90,    91,   234,   234,   234,
     234,   234,    97,   234,   234,   100,   234,   119,   234,   234,
     234,   106,   232,   206,   232,     1,   232,   232,   232,   114,
     115,   116,   234,   135,   232,   232,   206,   232,   234,   232,
     234,   126,   233,   232,   234,   147,   148,   234,   232,   234,
     232,   237,    28,    29,   232,   232,   237,   232,   206,   232,
      36,   146,   234,   165,   232,    41,    42,    43,   232,   232,
     232,   237,   237,   234,   234,   234,   178,   234,   234,   234,
     234,   183,   234,   234,   234,   234,   188,   234,   234,   191,
      66,    67,    68,    69,   234,   234,   234,   234,   234,   184,
     234,   234,   234,   234,   234,    81,    82,    83,   234,   234,
     234,   232,    88,    89,    90,   234,    92,   234,   232,   232,
     232,   232,   237,   239,   234,   234,   232,   232,   135,   237,
     234,   234,   239,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   135,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   233,   232,
     234,   133,    77,   239,   234,   237,   234,   234,   234,   234,
     227,   505,   588,  1283,  1053,   520,  1281,   346,  1259,  1270,
    1155,  1268,   469,  1292,   536,   574,   601,  1285,   124,   409,
    1264,   492,   399,   174,   379,  1124,  1122,   100,   244,    -1,
      -1,   272,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     482,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   293,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   241,     0,     1,     4,    17,    20,    23,    32,    46,
      52,    53,    71,    75,    85,   104,   105,   119,   135,   147,
     148,   165,   178,   183,   188,   191,   242,   247,   252,   271,
     277,   283,   291,   304,   324,   346,   360,   375,   382,   386,
     396,   405,   427,   433,   439,   443,   449,   503,   523,   234,
     235,   236,   236,   325,   406,   434,   236,   444,   236,   361,
     428,   347,   236,   278,   305,   376,   236,   236,   397,   236,
     284,   236,   387,     1,    33,    40,   106,   272,   273,   274,
     275,   276,     1,    28,    29,    36,    41,    42,    43,    66,
      67,    68,    69,    81,    82,    83,    88,    89,    90,    92,
     504,   505,   506,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   236,
     236,   236,     1,    70,   440,   441,   442,   236,     1,     6,
       7,     9,    10,    15,    25,    26,    27,    35,    38,    39,
      48,    65,    76,    79,    80,    87,    93,    94,    96,    98,
     101,   102,   112,   117,   118,   120,   121,   122,   125,   149,
     150,   153,   154,   155,   156,   157,   158,   159,   207,   208,
     218,   219,   227,   229,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   495,   499,   500,   501,
     502,   236,   236,   236,     1,   103,   124,   248,   249,   250,
     251,   236,   236,   236,     1,    37,    49,    50,    51,    54,
      55,    59,    60,    61,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,     1,    30,    33,    63,    73,
      95,    99,   106,   109,   110,   137,   210,   212,   213,   215,
     216,   217,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     236,     1,   223,   292,   293,   294,   295,   296,   236,     1,
     106,   383,   384,   385,   236,   234,   237,   237,   237,   235,
     273,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   235,   505,
       1,    18,    19,    24,    72,    90,    91,    97,   100,   106,
     114,   115,   116,   126,   146,   184,   326,   327,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,     1,     3,     5,    20,    44,    62,    64,
      72,    84,   106,   127,   145,   161,   209,   211,   212,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   422,   423,   424,   425,   426,     1,    70,   129,   435,
     436,   437,   438,   237,   235,   441,     1,   106,   129,   445,
     446,   447,   448,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   496,   492,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   235,   451,
       1,    20,    44,    72,   123,   130,   131,   151,   224,   362,
     363,   364,   365,   366,   367,   368,   372,   373,   374,     1,
     129,   224,   429,   430,   431,   432,     1,    62,    70,    72,
     127,   348,   352,   353,   354,   358,   359,   234,   237,   237,
     235,   249,     1,    86,   171,   279,   280,   281,   282,     1,
      20,    44,    72,   106,   123,   198,   211,   214,   224,   228,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   320,     1,    46,    86,   129,   377,   378,   379,   380,
     381,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     235,   525,   234,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   235,
     254,     1,   106,   221,   398,   399,   400,   401,   234,   237,
     235,   293,   171,     1,   106,   164,   182,   196,   285,   286,
     287,   288,   289,   290,   237,   235,   384,     1,   106,   221,
     224,   388,   389,   390,   391,   392,   232,   232,   232,   234,
     233,   233,   244,   206,   206,   206,   206,   233,   244,   244,
     244,   233,   244,   244,   233,   233,   233,   233,   234,   234,
     237,   237,   237,   343,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   235,   327,   234,   237,   237,
     237,   237,   237,   237,   419,   237,   237,   237,   237,   237,
     237,   237,   237,   235,   408,   237,   237,   235,   436,   232,
     234,   237,   237,   235,   446,   206,   244,   233,   244,   244,
     206,   233,   244,   206,   233,   233,   206,   206,   244,   233,
     233,   233,   233,   233,   244,   233,   233,   233,   206,   237,
     237,   206,   244,   244,   206,   206,   233,   206,   206,   206,
     206,   206,   206,   206,   233,   244,   244,   244,   206,   233,
     234,   234,   237,   237,   369,   237,   237,   237,   237,   237,
     235,   363,   237,   237,   235,   430,   234,   237,   237,   349,
     237,   235,   353,   232,   232,   234,   234,   237,   237,   235,
     280,   234,   237,   237,   321,   237,   237,   317,   237,   237,
     237,   237,   235,   307,   234,   237,   237,   237,   235,   378,
     206,   206,   244,   232,   206,   232,   206,   206,   206,   234,
     233,   232,   206,   232,   233,   233,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   234,   234,   237,   402,
     235,   399,   206,   234,   236,   234,   237,   237,   237,   237,
     235,   286,   232,   234,   234,   237,   393,   237,   235,   389,
     234,   234,   234,   234,   138,   139,   140,   141,   142,   143,
     144,   243,   244,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   233,
     233,   244,   237,   233,   244,   233,   244,   232,   233,   233,
     233,   244,   233,   246,   246,   234,   232,   175,   176,   232,
     206,   232,   232,   237,   232,   232,   233,   232,   232,   244,
     232,   232,   234,   232,   232,   234,   234,   232,   232,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,    11,    47,    54,    56,    57,   162,
     163,   166,   167,   169,   170,   172,   174,   177,   179,   180,
     185,   189,   193,   194,   195,   203,   497,   498,    11,    47,
      54,    56,    57,   162,   163,   166,   167,   169,   170,   172,
     174,   177,   179,   180,   185,   189,   193,   194,   195,   203,
     493,   494,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   232,   206,   237,   232,   233,   232,   232,   232,   234,
     232,   232,   234,   232,   232,   237,   233,   356,   357,   234,
     234,   234,   232,   232,   234,   232,   206,   237,   232,   232,
     237,   232,   206,   232,   232,   234,   232,   232,   232,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   232,   237,   234,   234,     1,
     106,   192,   221,   297,   298,   299,   300,   301,   232,   232,
     232,   232,   234,   234,   232,   237,   232,   234,   243,   243,
     243,   243,   243,   243,   243,   234,   234,   234,    58,   128,
     344,   345,   234,   234,   234,   234,   234,   234,   234,   234,
     234,    12,    13,    14,   245,   246,   234,   234,   234,   234,
     234,   234,   234,   234,   234,     8,   197,   420,   421,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   238,   234,   238,   234,   234,    16,    45,    78,
     107,   108,   113,   136,   205,   231,   370,   371,   234,   234,
     234,   234,   234,   234,   234,   234,   234,    21,    31,    54,
     187,   197,   350,   351,   220,   238,   355,   234,   234,   234,
     234,     4,    22,    23,    34,    74,    75,    77,   103,   111,
     132,   134,   135,   152,   168,   173,   177,   181,   186,   190,
     199,   201,   202,   204,   222,   230,   322,   323,   234,   234,
      11,    47,    54,    56,    57,   162,   163,   166,   167,   169,
     170,   172,   174,   177,   179,   180,   185,   189,   193,   194,
     195,   203,   318,   319,   234,   234,   234,   234,   234,   234,
     234,   234,    77,   135,   160,   168,   177,   199,   201,   202,
     222,   230,   403,   404,   234,   237,   237,   302,   235,   298,
     234,   234,   234,   234,   234,    77,   135,   160,   168,   177,
     199,   201,   202,   222,   230,   394,   395,   234,   234,   238,
     245,   245,   245,   234,   238,   498,   494,   234,   238,   234,
     238,   233,   357,   234,   239,   239,   239,   239,   239,   239,
     234,   238,   234,   238,   234,   238,   232,   200,   246,   237,
     234,   234,   238,   345,   421,   371,   351,   133,   135,   133,
     135,   133,   133,   323,   319,   404,   234,   234,   234,    75,
      77,   119,   135,   167,   168,   224,   230,   303,   395,   234
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   240,   241,   241,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   245,   245,
     246,   246,   246,   246,   247,   248,   248,   249,   249,   249,
     250,   251,   252,   253,   253,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     272,   273,   273,   273,   273,   274,   275,   276,   278,   277,
     279,   279,   280,   280,   280,   281,   282,   284,   283,   285,
     285,   286,   286,   286,   286,   286,   287,   288,   289,   290,
     291,   292,   292,   293,   293,   293,   294,   296,   295,   297,
     297,   298,   298,   298,   298,   299,   300,   300,   302,   301,
     303,   303,   303,   303,   303,   303,   303,   303,   305,   304,
     306,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   317,   316,   318,   318,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   321,   320,   322,
     322,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     325,   324,   326,   326,   327,   327,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   327,   327,   327,   327,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   343,   342,   344,   344,   345,   345,
     347,   346,   349,   348,   350,   350,   351,   351,   351,   351,
     351,   352,   352,   353,   353,   353,   353,   353,   355,   354,
     356,   356,   357,   357,   358,   359,   361,   360,   362,   362,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   364,
     365,   366,   367,   369,   368,   370,   370,   371,   371,   371,
     371,   371,   371,   371,   371,   371,   372,   373,   374,   376,
     375,   377,   377,   378,   378,   378,   378,   379,   380,   381,
     382,   383,   383,   384,   384,   385,   387,   386,   388,   388,
     389,   389,   389,   389,   390,   391,   393,   392,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     397,   396,   398,   398,   399,   399,   399,   400,   402,   401,
     403,   403,   404,   404,   404,   404,   404,   404,   404,   404,
     404,   404,   406,   405,   407,   407,   408,   408,   408,   408,
     408,   408,   408,   408,   408,   408,   408,   408,   408,   408,
     408,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   417,   419,   418,   420,   420,   421,   421,   422,   423,
     424,   425,   426,   428,   427,   429,   429,   430,   430,   430,
     431,   432,   434,   433,   435,   435,   436,   436,   436,   437,
     438,   439,   440,   440,   441,   441,   442,   444,   443,   445,
     445,   446,   446,   446,   447,   448,   449,   450,   450,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   451,   451,   451,   451,   451,
     451,   451,   451,   451,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   492,   491,   493,   493,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     496,   495,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   499,   500,   501,   502,
     503,   504,   504,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     524,   525,   525,   525,   525,   525,   525,   525,   525,   525,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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
       0,     6,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     0,     5,
       3,     1,     1,     3,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
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
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
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

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
#line 399 "conf_parser.y"
           { (yyval.number) = 0; }
#line 2950 "conf_parser.c"
    break;

  case 30:
#line 400 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 2956 "conf_parser.c"
    break;

  case 31:
#line 401 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 2962 "conf_parser.c"
    break;

  case 32:
#line 402 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number); }
#line 2968 "conf_parser.c"
    break;

  case 33:
#line 403 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number); }
#line 2974 "conf_parser.c"
    break;

  case 34:
#line 404 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number); }
#line 2980 "conf_parser.c"
    break;

  case 35:
#line 405 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number); }
#line 2986 "conf_parser.c"
    break;

  case 36:
#line 406 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[0].number); }
#line 2992 "conf_parser.c"
    break;

  case 37:
#line 407 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 365 + (yyvsp[0].number); }
#line 2998 "conf_parser.c"
    break;

  case 38:
#line 410 "conf_parser.y"
            { (yyval.number) = 0; }
#line 3004 "conf_parser.c"
    break;

  case 40:
#line 411 "conf_parser.y"
                             { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
#line 3010 "conf_parser.c"
    break;

  case 41:
#line 412 "conf_parser.y"
                                   { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
#line 3016 "conf_parser.c"
    break;

  case 42:
#line 413 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
#line 3022 "conf_parser.c"
    break;

  case 43:
#line 414 "conf_parser.y"
                                    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
#line 3028 "conf_parser.c"
    break;

  case 50:
#line 427 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
#line 3037 "conf_parser.c"
    break;

  case 51:
#line 433 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
#line 3046 "conf_parser.c"
    break;

  case 72:
#line 465 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_certificate_file);
    ConfigServerInfo.tls_certificate_file = xstrdup(yylval.string);
  }
}
#line 3058 "conf_parser.c"
    break;

  case 73:
#line 474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.rsa_private_key_file);
    ConfigServerInfo.rsa_private_key_file = xstrdup(yylval.string);
  }
}
#line 3070 "conf_parser.c"
    break;

  case 74:
#line 483 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_dh_param_file);
    ConfigServerInfo.tls_dh_param_file = xstrdup(yylval.string);
  }
}
#line 3082 "conf_parser.c"
    break;

  case 75:
#line 492 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_list);
    ConfigServerInfo.tls_cipher_list = xstrdup(yylval.string);
  }
}
#line 3094 "conf_parser.c"
    break;

  case 76:
#line 501 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_cipher_suites);
    ConfigServerInfo.tls_cipher_suites = xstrdup(yylval.string);
  }
}
#line 3106 "conf_parser.c"
    break;

  case 77:
#line 510 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_message_digest_algorithm);
    ConfigServerInfo.tls_message_digest_algorithm = xstrdup(yylval.string);
  }
}
#line 3118 "conf_parser.c"
    break;

  case 78:
#line 519 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.tls_supported_groups);
    ConfigServerInfo.tls_supported_groups = xstrdup(yylval.string);
  }
}
#line 3130 "conf_parser.c"
    break;

  case 79:
#line 528 "conf_parser.y"
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
#line 3148 "conf_parser.c"
    break;

  case 80:
#line 543 "conf_parser.y"
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
#line 3166 "conf_parser.c"
    break;

  case 81:
#line 558 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerInfo.description);
    ConfigServerInfo.description = xstrdup(yylval.string);
    strlcpy(me.info, ConfigServerInfo.description, sizeof(me.info));
  }
}
#line 3179 "conf_parser.c"
    break;

  case 82:
#line 568 "conf_parser.y"
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
#line 3196 "conf_parser.c"
    break;

  case 83:
#line 582 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigServerInfo.network_description);
  ConfigServerInfo.network_description = xstrdup(yylval.string);
}
#line 3208 "conf_parser.c"
    break;

  case 84:
#line 591 "conf_parser.y"
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
#line 3234 "conf_parser.c"
    break;

  case 85:
#line 614 "conf_parser.y"
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
#line 3260 "conf_parser.c"
    break;

  case 86:
#line 637 "conf_parser.y"
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
#line 3286 "conf_parser.c"
    break;

  case 87:
#line 660 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerInfo.hub = yylval.number;
}
#line 3295 "conf_parser.c"
    break;

  case 95:
#line 678 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.name);
  ConfigAdminInfo.name = xstrdup(yylval.string);
}
#line 3307 "conf_parser.c"
    break;

  case 96:
#line 687 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.email);
  ConfigAdminInfo.email = xstrdup(yylval.string);
}
#line 3319 "conf_parser.c"
    break;

  case 97:
#line 696 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  xfree(ConfigAdminInfo.description);
  ConfigAdminInfo.description = xstrdup(yylval.string);
}
#line 3331 "conf_parser.c"
    break;

  case 98:
#line 709 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3340 "conf_parser.c"
    break;

  case 99:
#line 713 "conf_parser.y"
{
  dlink_node *node;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(node, block_state.mask.list.head)
    motd_add(node->data, block_state.file.buf);
}
#line 3357 "conf_parser.c"
    break;

  case 105:
#line 730 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3366 "conf_parser.c"
    break;

  case 106:
#line 736 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3375 "conf_parser.c"
    break;

  case 107:
#line 746 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3384 "conf_parser.c"
    break;

  case 108:
#line 750 "conf_parser.y"
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
#line 3402 "conf_parser.c"
    break;

  case 116:
#line 768 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.command.buf, yylval.string, sizeof(block_state.command.buf));
}
#line 3411 "conf_parser.c"
    break;

  case 117:
#line 774 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3420 "conf_parser.c"
    break;

  case 118:
#line 780 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.prepend.buf, yylval.string, sizeof(block_state.prepend.buf));
}
#line 3429 "conf_parser.c"
    break;

  case 119:
#line 786 "conf_parser.y"
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
#line 3450 "conf_parser.c"
    break;

  case 126:
#line 814 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigLog.use_logging = yylval.number;
}
#line 3459 "conf_parser.c"
    break;

  case 127:
#line 820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 3468 "conf_parser.c"
    break;

  case 128:
#line 824 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
#line 3481 "conf_parser.c"
    break;

  case 135:
#line 840 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
#line 3492 "conf_parser.c"
    break;

  case 136:
#line 848 "conf_parser.y"
{
  block_state.size.value = (yyvsp[-1].number);
}
#line 3500 "conf_parser.c"
    break;

  case 137:
#line 851 "conf_parser.y"
{
  block_state.size.value = 0;
}
#line 3508 "conf_parser.c"
    break;

  case 138:
#line 856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
#line 3517 "conf_parser.c"
    break;

  case 140:
#line 862 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
#line 3526 "conf_parser.c"
    break;

  case 141:
#line 866 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
#line 3535 "conf_parser.c"
    break;

  case 142:
#line 870 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_XLINE;
}
#line 3544 "conf_parser.c"
    break;

  case 143:
#line 874 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_RESV;
}
#line 3553 "conf_parser.c"
    break;

  case 144:
#line 878 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
#line 3562 "conf_parser.c"
    break;

  case 145:
#line 882 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
#line 3571 "conf_parser.c"
    break;

  case 146:
#line 886 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
#line 3580 "conf_parser.c"
    break;

  case 147:
#line 890 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
#line 3589 "conf_parser.c"
    break;

  case 148:
#line 900 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
#line 3601 "conf_parser.c"
    break;

  case 149:
#line 907 "conf_parser.y"
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
#line 3660 "conf_parser.c"
    break;

  case 163:
#line 976 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 3669 "conf_parser.c"
    break;

  case 164:
#line 982 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 3678 "conf_parser.c"
    break;

  case 165:
#line 988 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 3687 "conf_parser.c"
    break;

  case 166:
#line 994 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.whois.buf, yylval.string, sizeof(block_state.whois.buf));
}
#line 3696 "conf_parser.c"
    break;

  case 167:
#line 1000 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
#line 3710 "conf_parser.c"
    break;

  case 168:
#line 1011 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 3719 "conf_parser.c"
    break;

  case 169:
#line 1017 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_TLS;
  else
    block_state.flags.value &= ~CONF_FLAGS_TLS;
}
#line 3733 "conf_parser.c"
    break;

  case 170:
#line 1028 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 3742 "conf_parser.c"
    break;

  case 171:
#line 1034 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
#line 3751 "conf_parser.c"
    break;

  case 175:
#line 1041 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOT;
}
#line 3760 "conf_parser.c"
    break;

  case 176:
#line 1045 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
#line 3769 "conf_parser.c"
    break;

  case 177:
#line 1049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
#line 3778 "conf_parser.c"
    break;

  case 178:
#line 1053 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
#line 3787 "conf_parser.c"
    break;

  case 179:
#line 1057 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FLOOD;
}
#line 3796 "conf_parser.c"
    break;

  case 180:
#line 1061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
#line 3805 "conf_parser.c"
    break;

  case 181:
#line 1065 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDECHANS;
}
#line 3814 "conf_parser.c"
    break;

  case 182:
#line 1069 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDEIDLE;
}
#line 3823 "conf_parser.c"
    break;

  case 183:
#line 1073 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
#line 3832 "conf_parser.c"
    break;

  case 184:
#line 1077 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
#line 3841 "conf_parser.c"
    break;

  case 185:
#line 1081 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
#line 3850 "conf_parser.c"
    break;

  case 186:
#line 1085 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
#line 3859 "conf_parser.c"
    break;

  case 187:
#line 1089 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
#line 3868 "conf_parser.c"
    break;

  case 188:
#line 1093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
#line 3877 "conf_parser.c"
    break;

  case 189:
#line 1097 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
#line 3886 "conf_parser.c"
    break;

  case 190:
#line 1101 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
#line 3895 "conf_parser.c"
    break;

  case 191:
#line 1105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
#line 3904 "conf_parser.c"
    break;

  case 192:
#line 1109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
#line 3913 "conf_parser.c"
    break;

  case 193:
#line 1113 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
#line 3922 "conf_parser.c"
    break;

  case 194:
#line 1117 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
#line 3931 "conf_parser.c"
    break;

  case 195:
#line 1121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
#line 3940 "conf_parser.c"
    break;

  case 196:
#line 1125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXPIRATION;
}
#line 3949 "conf_parser.c"
    break;

  case 197:
#line 1131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
#line 3958 "conf_parser.c"
    break;

  case 201:
#line 1138 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
#line 3967 "conf_parser.c"
    break;

  case 202:
#line 1142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
#line 3976 "conf_parser.c"
    break;

  case 203:
#line 1146 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
#line 3985 "conf_parser.c"
    break;

  case 204:
#line 1150 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
#line 3994 "conf_parser.c"
    break;

  case 205:
#line 1154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
#line 4003 "conf_parser.c"
    break;

  case 206:
#line 1158 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
#line 4012 "conf_parser.c"
    break;

  case 207:
#line 1162 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KLINE;
}
#line 4021 "conf_parser.c"
    break;

  case 208:
#line 1166 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
#line 4030 "conf_parser.c"
    break;

  case 209:
#line 1170 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
#line 4039 "conf_parser.c"
    break;

  case 210:
#line 1174 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
#line 4048 "conf_parser.c"
    break;

  case 211:
#line 1178 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_XLINE;
}
#line 4057 "conf_parser.c"
    break;

  case 212:
#line 1182 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNXLINE;
}
#line 4066 "conf_parser.c"
    break;

  case 213:
#line 1186 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
#line 4075 "conf_parser.c"
    break;

  case 214:
#line 1190 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
#line 4084 "conf_parser.c"
    break;

  case 215:
#line 1194 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH_REMOTE;
}
#line 4093 "conf_parser.c"
    break;

  case 216:
#line 1198 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
#line 4102 "conf_parser.c"
    break;

  case 217:
#line 1202 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
#line 4111 "conf_parser.c"
    break;

  case 218:
#line 1206 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
#line 4120 "conf_parser.c"
    break;

  case 219:
#line 1210 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
#line 4129 "conf_parser.c"
    break;

  case 220:
#line 1214 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
#line 4138 "conf_parser.c"
    break;

  case 221:
#line 1218 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
#line 4147 "conf_parser.c"
    break;

  case 222:
#line 1222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
#line 4156 "conf_parser.c"
    break;

  case 223:
#line 1226 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
#line 4165 "conf_parser.c"
    break;

  case 224:
#line 1230 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPME;
}
#line 4174 "conf_parser.c"
    break;

  case 225:
#line 1234 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_NICK_RESV;
}
#line 4183 "conf_parser.c"
    break;

  case 226:
#line 1238 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_JOIN_RESV;
}
#line 4192 "conf_parser.c"
    break;

  case 227:
#line 1242 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESV;
}
#line 4201 "conf_parser.c"
    break;

  case 228:
#line 1246 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNRESV;
}
#line 4210 "conf_parser.c"
    break;

  case 229:
#line 1250 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CLOSE;
}
#line 4219 "conf_parser.c"
    break;

  case 230:
#line 1260 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;
}
#line 4235 "conf_parser.c"
    break;

  case 231:
#line 1271 "conf_parser.y"
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
#line 4283 "conf_parser.c"
    break;

  case 250:
#line 1334 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4292 "conf_parser.c"
    break;

  case 251:
#line 1340 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[-1].number);
}
#line 4301 "conf_parser.c"
    break;

  case 252:
#line 1346 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_local.value = (yyvsp[-1].number);
}
#line 4310 "conf_parser.c"
    break;

  case 253:
#line 1352 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip_global.value = (yyvsp[-1].number);
}
#line 4319 "conf_parser.c"
    break;

  case 254:
#line 1358 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[-1].number);
}
#line 4328 "conf_parser.c"
    break;

  case 255:
#line 1364 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_channels.value = (yyvsp[-1].number);
}
#line 4337 "conf_parser.c"
    break;

  case 256:
#line 1370 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[-1].number);
}
#line 4346 "conf_parser.c"
    break;

  case 257:
#line 1376 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[-1].number);
}
#line 4355 "conf_parser.c"
    break;

  case 258:
#line 1382 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[-1].number) >= CLIENT_FLOOD_MIN && (yyvsp[-1].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[-1].number);
}
#line 4365 "conf_parser.c"
    break;

  case 259:
#line 1389 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[-1].number) > 32 ? 32 : (yyvsp[-1].number);
}
#line 4374 "conf_parser.c"
    break;

  case 260:
#line 1395 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[-1].number) > 128 ? 128 : (yyvsp[-1].number);
}
#line 4383 "conf_parser.c"
    break;

  case 261:
#line 1401 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[-1].number);
}
#line 4392 "conf_parser.c"
    break;

  case 262:
#line 1407 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4404 "conf_parser.c"
    break;

  case 263:
#line 1416 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[-1].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
#line 4416 "conf_parser.c"
    break;

  case 264:
#line 1425 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
#line 4425 "conf_parser.c"
    break;

  case 268:
#line 1432 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
#line 4434 "conf_parser.c"
    break;

  case 269:
#line 1436 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
#line 4443 "conf_parser.c"
    break;

  case 270:
#line 1446 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4452 "conf_parser.c"
    break;

  case 272:
#line 1452 "conf_parser.y"
{
  block_state.flags.value = 0;
}
#line 4460 "conf_parser.c"
    break;

  case 276:
#line 1458 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_TLS;
}
#line 4469 "conf_parser.c"
    break;

  case 277:
#line 1462 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
#line 4478 "conf_parser.c"
    break;

  case 278:
#line 1466 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
#line 4487 "conf_parser.c"
    break;

  case 279:
#line 1470 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_CLIENT;
}
#line 4496 "conf_parser.c"
    break;

  case 280:
#line 1474 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_DEFER;
}
#line 4505 "conf_parser.c"
    break;

  case 288:
#line 1482 "conf_parser.y"
                                 { block_state.flags.value = 0; }
#line 4511 "conf_parser.c"
    break;

  case 292:
#line 1487 "conf_parser.y"
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
#line 4529 "conf_parser.c"
    break;

  case 293:
#line 1500 "conf_parser.y"
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
#line 4549 "conf_parser.c"
    break;

  case 294:
#line 1517 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4558 "conf_parser.c"
    break;

  case 295:
#line 1523 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 4567 "conf_parser.c"
    break;

  case 296:
#line 1533 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 4576 "conf_parser.c"
    break;

  case 297:
#line 1537 "conf_parser.y"
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
#line 4622 "conf_parser.c"
    break;

  case 309:
#line 1591 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4631 "conf_parser.c"
    break;

  case 310:
#line 1597 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4640 "conf_parser.c"
    break;

  case 311:
#line 1603 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 4649 "conf_parser.c"
    break;

  case 312:
#line 1609 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 4663 "conf_parser.c"
    break;

  case 313:
#line 1620 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
#line 4672 "conf_parser.c"
    break;

  case 317:
#line 1627 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
#line 4681 "conf_parser.c"
    break;

  case 318:
#line 1631 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
#line 4690 "conf_parser.c"
    break;

  case 319:
#line 1635 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTXLINE;
}
#line 4699 "conf_parser.c"
    break;

  case 320:
#line 1639 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
#line 4708 "conf_parser.c"
    break;

  case 321:
#line 1643 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
#line 4717 "conf_parser.c"
    break;

  case 322:
#line 1647 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
#line 4726 "conf_parser.c"
    break;

  case 323:
#line 1651 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
#line 4735 "conf_parser.c"
    break;

  case 324:
#line 1655 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
#line 4744 "conf_parser.c"
    break;

  case 325:
#line 1659 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
#line 4753 "conf_parser.c"
    break;

  case 326:
#line 1665 "conf_parser.y"
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
#line 4770 "conf_parser.c"
    break;

  case 327:
#line 1679 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
#line 4782 "conf_parser.c"
    break;

  case 328:
#line 1688 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[-1].number);
}
#line 4794 "conf_parser.c"
    break;

  case 329:
#line 1701 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
#line 4806 "conf_parser.c"
    break;

  case 330:
#line 1708 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  resv_make(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
#line 4817 "conf_parser.c"
    break;

  case 337:
#line 1719 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4826 "conf_parser.c"
    break;

  case 338:
#line 1725 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 4835 "conf_parser.c"
    break;

  case 339:
#line 1731 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
#line 4844 "conf_parser.c"
    break;

  case 345:
#line 1746 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  if (server_valid_name(yylval.string) == true)
  {
    struct ServiceItem *service = service_make();
    service->name = xstrdup(yylval.string);
  }
}
#line 4859 "conf_parser.c"
    break;

  case 346:
#line 1762 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
#line 4875 "conf_parser.c"
    break;

  case 347:
#line 1773 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct SharedItem *shared = shared_make();
  shared->type = block_state.flags.value;
  shared->server = xstrdup(block_state.name.buf);
  shared->user = xstrdup(block_state.user.buf);
  shared->host = xstrdup(block_state.host.buf);
}
#line 4890 "conf_parser.c"
    break;

  case 354:
#line 1788 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 4899 "conf_parser.c"
    break;

  case 355:
#line 1794 "conf_parser.y"
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
#line 4921 "conf_parser.c"
    break;

  case 356:
#line 1813 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 4930 "conf_parser.c"
    break;

  case 360:
#line 1820 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
#line 4939 "conf_parser.c"
    break;

  case 361:
#line 1824 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
#line 4948 "conf_parser.c"
    break;

  case 362:
#line 1828 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
#line 4957 "conf_parser.c"
    break;

  case 363:
#line 1832 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
#line 4966 "conf_parser.c"
    break;

  case 364:
#line 1836 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
#line 4975 "conf_parser.c"
    break;

  case 365:
#line 1840 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
#line 4984 "conf_parser.c"
    break;

  case 366:
#line 1844 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
#line 4993 "conf_parser.c"
    break;

  case 367:
#line 1848 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
#line 5002 "conf_parser.c"
    break;

  case 368:
#line 1852 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
#line 5011 "conf_parser.c"
    break;

  case 369:
#line 1856 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
#line 5020 "conf_parser.c"
    break;

  case 370:
#line 1866 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = CLUSTER_ALL;
}
#line 5034 "conf_parser.c"
    break;

  case 371:
#line 1875 "conf_parser.y"
{
  if (conf_parser_ctx.pass != 2)
    break;

  struct ClusterItem *cluster = cluster_make();
  cluster->type = block_state.flags.value;
  cluster->server = xstrdup(block_state.name.buf);
}
#line 5047 "conf_parser.c"
    break;

  case 377:
#line 1888 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5056 "conf_parser.c"
    break;

  case 378:
#line 1894 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
#line 5065 "conf_parser.c"
    break;

  case 382:
#line 1901 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_KLINE;
}
#line 5074 "conf_parser.c"
    break;

  case 383:
#line 1905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNKLINE;
}
#line 5083 "conf_parser.c"
    break;

  case 384:
#line 1909 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_DLINE;
}
#line 5092 "conf_parser.c"
    break;

  case 385:
#line 1913 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNDLINE;
}
#line 5101 "conf_parser.c"
    break;

  case 386:
#line 1917 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_XLINE;
}
#line 5110 "conf_parser.c"
    break;

  case 387:
#line 1921 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNXLINE;
}
#line 5119 "conf_parser.c"
    break;

  case 388:
#line 1925 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_RESV;
}
#line 5128 "conf_parser.c"
    break;

  case 389:
#line 1929 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_UNRESV;
}
#line 5137 "conf_parser.c"
    break;

  case 390:
#line 1933 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CLUSTER_LOCOPS;
}
#line 5146 "conf_parser.c"
    break;

  case 391:
#line 1937 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = CLUSTER_ALL;
}
#line 5155 "conf_parser.c"
    break;

  case 392:
#line 1947 "conf_parser.y"
{

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.aftype.value = AF_INET;
  block_state.port.value = PORTNUM;
  block_state.timeout.value = CONNECTTIMEOUT;
}
#line 5170 "conf_parser.c"
    break;

  case 393:
#line 1957 "conf_parser.y"
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
#line 5241 "conf_parser.c"
    break;

  case 412:
#line 2043 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5250 "conf_parser.c"
    break;

  case 413:
#line 2049 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
#line 5259 "conf_parser.c"
    break;

  case 414:
#line 2055 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.timeout.value = (yyvsp[-1].number);
}
#line 5268 "conf_parser.c"
    break;

  case 415:
#line 2061 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
#line 5277 "conf_parser.c"
    break;

  case 416:
#line 2067 "conf_parser.y"
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
#line 5293 "conf_parser.c"
    break;

  case 417:
#line 2080 "conf_parser.y"
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
#line 5309 "conf_parser.c"
    break;

  case 418:
#line 2093 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
#line 5318 "conf_parser.c"
    break;

  case 419:
#line 2099 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[-1].number);
}
#line 5327 "conf_parser.c"
    break;

  case 420:
#line 2105 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
#line 5336 "conf_parser.c"
    break;

  case 421:
#line 2109 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
}
#line 5345 "conf_parser.c"
    break;

  case 422:
#line 2115 "conf_parser.y"
{
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
#line 5353 "conf_parser.c"
    break;

  case 426:
#line 2121 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
#line 5362 "conf_parser.c"
    break;

  case 427:
#line 2125 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_TLS;
}
#line 5371 "conf_parser.c"
    break;

  case 428:
#line 2131 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
#line 5385 "conf_parser.c"
    break;

  case 429:
#line 2142 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
#line 5394 "conf_parser.c"
    break;

  case 430:
#line 2148 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
#line 5403 "conf_parser.c"
    break;

  case 431:
#line 2154 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
#line 5412 "conf_parser.c"
    break;

  case 432:
#line 2160 "conf_parser.y"
{
#ifdef HAVE_TLS
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::tls_cipher_list -- no TLS support");
#endif
}
#line 5426 "conf_parser.c"
    break;

  case 433:
#line 2175 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5435 "conf_parser.c"
    break;

  case 434:
#line 2179 "conf_parser.y"
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
#line 5458 "conf_parser.c"
    break;

  case 440:
#line 2202 "conf_parser.y"
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
#line 5481 "conf_parser.c"
    break;

  case 441:
#line 2222 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5490 "conf_parser.c"
    break;

  case 442:
#line 2232 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5499 "conf_parser.c"
    break;

  case 443:
#line 2236 "conf_parser.y"
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
#line 5523 "conf_parser.c"
    break;

  case 449:
#line 2260 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
#line 5532 "conf_parser.c"
    break;

  case 450:
#line 2266 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5541 "conf_parser.c"
    break;

  case 456:
#line 2281 "conf_parser.y"
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
#line 5558 "conf_parser.c"
    break;

  case 457:
#line 2298 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
#line 5567 "conf_parser.c"
    break;

  case 458:
#line 2302 "conf_parser.y"
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
#line 5587 "conf_parser.c"
    break;

  case 464:
#line 2322 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
#line 5596 "conf_parser.c"
    break;

  case 465:
#line 2328 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
#line 5605 "conf_parser.c"
    break;

  case 515:
#line 2389 "conf_parser.y"
{
  ConfigGeneral.away_count = (yyvsp[-1].number);
}
#line 5613 "conf_parser.c"
    break;

  case 516:
#line 2394 "conf_parser.y"
{
  ConfigGeneral.away_time = (yyvsp[-1].number);
}
#line 5621 "conf_parser.c"
    break;

  case 517:
#line 2399 "conf_parser.y"
{
  ConfigGeneral.max_monitor = (yyvsp[-1].number);
}
#line 5629 "conf_parser.c"
    break;

  case 518:
#line 2404 "conf_parser.y"
{
  ConfigGeneral.whowas_history_length = (yyvsp[-1].number);
}
#line 5637 "conf_parser.c"
    break;

  case 519:
#line 2409 "conf_parser.y"
{
  ConfigGeneral.cycle_on_host_change = yylval.number;
}
#line 5645 "conf_parser.c"
    break;

  case 520:
#line 2414 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr = (yyvsp[-1].number);
}
#line 5653 "conf_parser.c"
    break;

  case 521:
#line 2419 "conf_parser.y"
{
  ConfigGeneral.dline_min_cidr6 = (yyvsp[-1].number);
}
#line 5661 "conf_parser.c"
    break;

  case 522:
#line 2424 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr = (yyvsp[-1].number);
}
#line 5669 "conf_parser.c"
    break;

  case 523:
#line 2429 "conf_parser.y"
{
  ConfigGeneral.kline_min_cidr6 = (yyvsp[-1].number);
}
#line 5677 "conf_parser.c"
    break;

  case 524:
#line 2434 "conf_parser.y"
{
  ConfigGeneral.kill_chase_time_limit = (yyvsp[-1].number);
}
#line 5685 "conf_parser.c"
    break;

  case 525:
#line 2439 "conf_parser.y"
{
  ConfigGeneral.failed_oper_notice = yylval.number;
}
#line 5693 "conf_parser.c"
    break;

  case 526:
#line 2444 "conf_parser.y"
{
  ConfigGeneral.anti_nick_flood = yylval.number;
}
#line 5701 "conf_parser.c"
    break;

  case 527:
#line 2449 "conf_parser.y"
{
  ConfigGeneral.max_nick_time = (yyvsp[-1].number);
}
#line 5709 "conf_parser.c"
    break;

  case 528:
#line 2454 "conf_parser.y"
{
  ConfigGeneral.max_nick_changes = (yyvsp[-1].number);
}
#line 5717 "conf_parser.c"
    break;

  case 529:
#line 2459 "conf_parser.y"
{
  ConfigGeneral.max_accept = (yyvsp[-1].number);
}
#line 5725 "conf_parser.c"
    break;

  case 530:
#line 2464 "conf_parser.y"
{
  ConfigGeneral.anti_spam_exit_message_time = (yyvsp[-1].number);
}
#line 5733 "conf_parser.c"
    break;

  case 531:
#line 2469 "conf_parser.y"
{
  ConfigGeneral.ts_warn_delta = (yyvsp[-1].number);
}
#line 5741 "conf_parser.c"
    break;

  case 532:
#line 2474 "conf_parser.y"
{
  ConfigGeneral.ts_max_delta = (yyvsp[-1].number);
}
#line 5749 "conf_parser.c"
    break;

  case 533:
#line 2479 "conf_parser.y"
{
  ConfigGeneral.invisible_on_connect = yylval.number;
}
#line 5757 "conf_parser.c"
    break;

  case 534:
#line 2484 "conf_parser.y"
{
  ConfigGeneral.warn_no_connect_block = yylval.number;
}
#line 5765 "conf_parser.c"
    break;

  case 535:
#line 2489 "conf_parser.y"
{
  ConfigGeneral.stats_e_disabled = yylval.number;
}
#line 5773 "conf_parser.c"
    break;

  case 536:
#line 2494 "conf_parser.y"
{
  ConfigGeneral.stats_m_oper_only = yylval.number;
}
#line 5781 "conf_parser.c"
    break;

  case 537:
#line 2499 "conf_parser.y"
{
  ConfigGeneral.stats_o_oper_only = yylval.number;
}
#line 5789 "conf_parser.c"
    break;

  case 538:
#line 2504 "conf_parser.y"
{
  ConfigGeneral.stats_P_oper_only = yylval.number;
}
#line 5797 "conf_parser.c"
    break;

  case 539:
#line 2509 "conf_parser.y"
{
  ConfigGeneral.stats_u_oper_only = yylval.number;
}
#line 5805 "conf_parser.c"
    break;

  case 540:
#line 2514 "conf_parser.y"
{
  ConfigGeneral.stats_k_oper_only = yylval.number;
}
#line 5813 "conf_parser.c"
    break;

  case 541:
#line 2519 "conf_parser.y"
{
  ConfigGeneral.stats_i_oper_only = yylval.number;
}
#line 5821 "conf_parser.c"
    break;

  case 542:
#line 2524 "conf_parser.y"
{
  ConfigGeneral.pace_wait = (yyvsp[-1].number);
}
#line 5829 "conf_parser.c"
    break;

  case 543:
#line 2529 "conf_parser.y"
{
  ConfigGeneral.caller_id_wait = (yyvsp[-1].number);
}
#line 5837 "conf_parser.c"
    break;

  case 544:
#line 2534 "conf_parser.y"
{
  ConfigGeneral.opers_bypass_callerid = yylval.number;
}
#line 5845 "conf_parser.c"
    break;

  case 545:
#line 2539 "conf_parser.y"
{
  ConfigGeneral.pace_wait_simple = (yyvsp[-1].number);
}
#line 5853 "conf_parser.c"
    break;

  case 546:
#line 2544 "conf_parser.y"
{
  ConfigGeneral.short_motd = yylval.number;
}
#line 5861 "conf_parser.c"
    break;

  case 547:
#line 2549 "conf_parser.y"
{
  ConfigGeneral.no_oper_flood = yylval.number;
}
#line 5869 "conf_parser.c"
    break;

  case 548:
#line 2554 "conf_parser.y"
{
  ConfigGeneral.specials_in_ident = (yyvsp[-1].number);
}
#line 5877 "conf_parser.c"
    break;

  case 549:
#line 2559 "conf_parser.y"
{
  ConfigGeneral.max_targets = (yyvsp[-1].number);
}
#line 5885 "conf_parser.c"
    break;

  case 550:
#line 2564 "conf_parser.y"
{
  ConfigGeneral.ping_cookie = yylval.number;
}
#line 5893 "conf_parser.c"
    break;

  case 551:
#line 2569 "conf_parser.y"
{
  ConfigGeneral.disable_auth = yylval.number;
}
#line 5901 "conf_parser.c"
    break;

  case 552:
#line 2574 "conf_parser.y"
{
  ConfigGeneral.throttle_count = (yyvsp[-1].number);
}
#line 5909 "conf_parser.c"
    break;

  case 553:
#line 2579 "conf_parser.y"
{
  ConfigGeneral.throttle_time = (yyvsp[-1].number);
}
#line 5917 "conf_parser.c"
    break;

  case 554:
#line 2584 "conf_parser.y"
{
  ConfigGeneral.oper_umodes = 0;
}
#line 5925 "conf_parser.c"
    break;

  case 558:
#line 2590 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_BOT;
}
#line 5933 "conf_parser.c"
    break;

  case 559:
#line 2593 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CCONN;
}
#line 5941 "conf_parser.c"
    break;

  case 560:
#line 2596 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEAF;
}
#line 5949 "conf_parser.c"
    break;

  case 561:
#line 2599 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_DEBUG;
}
#line 5957 "conf_parser.c"
    break;

  case 562:
#line 2602 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FLOOD;
}
#line 5965 "conf_parser.c"
    break;

  case 563:
#line 2605 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDDEN;
}
#line 5973 "conf_parser.c"
    break;

  case 564:
#line 2608 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDECHANS;
}
#line 5981 "conf_parser.c"
    break;

  case 565:
#line 2611 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_HIDEIDLE;
}
#line 5989 "conf_parser.c"
    break;

  case 566:
#line 2614 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SKILL;
}
#line 5997 "conf_parser.c"
    break;

  case 567:
#line 2617 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_NCHANGE;
}
#line 6005 "conf_parser.c"
    break;

  case 568:
#line 2620 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REJ;
}
#line 6013 "conf_parser.c"
    break;

  case 569:
#line 2623 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SPY;
}
#line 6021 "conf_parser.c"
    break;

  case 570:
#line 2626 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXTERNAL;
}
#line 6029 "conf_parser.c"
    break;

  case 571:
#line 2629 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SERVNOTICE;
}
#line 6037 "conf_parser.c"
    break;

  case 572:
#line 2632 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_INVISIBLE;
}
#line 6045 "conf_parser.c"
    break;

  case 573:
#line 2635 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_WALLOP;
}
#line 6053 "conf_parser.c"
    break;

  case 574:
#line 2638 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_SOFTCALLERID;
}
#line 6061 "conf_parser.c"
    break;

  case 575:
#line 2641 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_CALLERID;
}
#line 6069 "conf_parser.c"
    break;

  case 576:
#line 2644 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_LOCOPS;
}
#line 6077 "conf_parser.c"
    break;

  case 577:
#line 2647 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_REGONLY;
}
#line 6085 "conf_parser.c"
    break;

  case 578:
#line 2650 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_FARCONNECT;
}
#line 6093 "conf_parser.c"
    break;

  case 579:
#line 2653 "conf_parser.y"
{
  ConfigGeneral.oper_umodes |= UMODE_EXPIRATION;
}
#line 6101 "conf_parser.c"
    break;

  case 580:
#line 2658 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes = 0;
}
#line 6109 "conf_parser.c"
    break;

  case 584:
#line 2664 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_BOT;
}
#line 6117 "conf_parser.c"
    break;

  case 585:
#line 2667 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CCONN;
}
#line 6125 "conf_parser.c"
    break;

  case 586:
#line 2670 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEAF;
}
#line 6133 "conf_parser.c"
    break;

  case 587:
#line 2673 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_DEBUG;
}
#line 6141 "conf_parser.c"
    break;

  case 588:
#line 2676 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FLOOD;
}
#line 6149 "conf_parser.c"
    break;

  case 589:
#line 2679 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SKILL;
}
#line 6157 "conf_parser.c"
    break;

  case 590:
#line 2682 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDDEN;
}
#line 6165 "conf_parser.c"
    break;

  case 591:
#line 2685 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDECHANS;
}
#line 6173 "conf_parser.c"
    break;

  case 592:
#line 2688 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_HIDEIDLE;
}
#line 6181 "conf_parser.c"
    break;

  case 593:
#line 2691 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_NCHANGE;
}
#line 6189 "conf_parser.c"
    break;

  case 594:
#line 2694 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REJ;
}
#line 6197 "conf_parser.c"
    break;

  case 595:
#line 2697 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SPY;
}
#line 6205 "conf_parser.c"
    break;

  case 596:
#line 2700 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXTERNAL;
}
#line 6213 "conf_parser.c"
    break;

  case 597:
#line 2703 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SERVNOTICE;
}
#line 6221 "conf_parser.c"
    break;

  case 598:
#line 2706 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_INVISIBLE;
}
#line 6229 "conf_parser.c"
    break;

  case 599:
#line 2709 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_WALLOP;
}
#line 6237 "conf_parser.c"
    break;

  case 600:
#line 2712 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_SOFTCALLERID;
}
#line 6245 "conf_parser.c"
    break;

  case 601:
#line 2715 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_CALLERID;
}
#line 6253 "conf_parser.c"
    break;

  case 602:
#line 2718 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_LOCOPS;
}
#line 6261 "conf_parser.c"
    break;

  case 603:
#line 2721 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_REGONLY;
}
#line 6269 "conf_parser.c"
    break;

  case 604:
#line 2724 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_FARCONNECT;
}
#line 6277 "conf_parser.c"
    break;

  case 605:
#line 2727 "conf_parser.y"
{
  ConfigGeneral.oper_only_umodes |= UMODE_EXPIRATION;
}
#line 6285 "conf_parser.c"
    break;

  case 606:
#line 2732 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard = (yyvsp[-1].number);
}
#line 6293 "conf_parser.c"
    break;

  case 607:
#line 2737 "conf_parser.y"
{
  ConfigGeneral.min_nonwildcard_simple = (yyvsp[-1].number);
}
#line 6301 "conf_parser.c"
    break;

  case 608:
#line 2742 "conf_parser.y"
{
  ConfigGeneral.default_floodcount = (yyvsp[-1].number);
}
#line 6309 "conf_parser.c"
    break;

  case 609:
#line 2747 "conf_parser.y"
{
  ConfigGeneral.default_floodtime = (yyvsp[-1].number);
}
#line 6317 "conf_parser.c"
    break;

  case 631:
#line 2778 "conf_parser.y"
{
  ConfigChannel.enable_extbans = yylval.number;
}
#line 6325 "conf_parser.c"
    break;

  case 632:
#line 2783 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_owner = yylval.number;
}
#line 6334 "conf_parser.c"
    break;

  case 633:
#line 2789 "conf_parser.y"
{
  if (conf_parser_ctx.boot)
    ConfigChannel.enable_admin = yylval.number;
}
#line 6343 "conf_parser.c"
    break;

  case 634:
#line 2795 "conf_parser.y"
{
  ConfigChannel.disable_fake_channels = yylval.number;
}
#line 6351 "conf_parser.c"
    break;

  case 635:
#line 2800 "conf_parser.y"
{
  ConfigChannel.invite_client_count = (yyvsp[-1].number);
}
#line 6359 "conf_parser.c"
    break;

  case 636:
#line 2805 "conf_parser.y"
{
  ConfigChannel.invite_client_time = (yyvsp[-1].number);
}
#line 6367 "conf_parser.c"
    break;

  case 637:
#line 2810 "conf_parser.y"
{
  ConfigChannel.invite_delay_channel = (yyvsp[-1].number);
}
#line 6375 "conf_parser.c"
    break;

  case 638:
#line 2815 "conf_parser.y"
{
  ConfigChannel.invite_expire_time = (yyvsp[-1].number);
}
#line 6383 "conf_parser.c"
    break;

  case 639:
#line 2820 "conf_parser.y"
{
  ConfigChannel.knock_client_count = (yyvsp[-1].number);
}
#line 6391 "conf_parser.c"
    break;

  case 640:
#line 2825 "conf_parser.y"
{
  ConfigChannel.knock_client_time = (yyvsp[-1].number);
}
#line 6399 "conf_parser.c"
    break;

  case 641:
#line 2830 "conf_parser.y"
{
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
#line 6407 "conf_parser.c"
    break;

  case 642:
#line 2835 "conf_parser.y"
{
  ConfigChannel.max_channels = (yyvsp[-1].number);
}
#line 6415 "conf_parser.c"
    break;

  case 643:
#line 2840 "conf_parser.y"
{
  ConfigChannel.max_invites = (yyvsp[-1].number);
}
#line 6423 "conf_parser.c"
    break;

  case 644:
#line 2845 "conf_parser.y"
{
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
#line 6431 "conf_parser.c"
    break;

  case 645:
#line 2850 "conf_parser.y"
{
  ConfigChannel.max_bans_large = (yyvsp[-1].number);
}
#line 6439 "conf_parser.c"
    break;

  case 646:
#line 2855 "conf_parser.y"
{
  ConfigChannel.default_join_flood_count = yylval.number;
}
#line 6447 "conf_parser.c"
    break;

  case 647:
#line 2860 "conf_parser.y"
{
  ConfigChannel.default_join_flood_time = (yyvsp[-1].number);
}
#line 6455 "conf_parser.c"
    break;

  case 661:
#line 2883 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
#line 6464 "conf_parser.c"
    break;

  case 662:
#line 2889 "conf_parser.y"
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
#line 6483 "conf_parser.c"
    break;

  case 663:
#line 2905 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.flatten_links_file);
    ConfigServerHide.flatten_links_file = xstrdup(yylval.string);
  }
}
#line 6495 "conf_parser.c"
    break;

  case 664:
#line 2914 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
#line 6504 "conf_parser.c"
    break;

  case 665:
#line 2920 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
#line 6513 "conf_parser.c"
    break;

  case 666:
#line 2926 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
#line 6522 "conf_parser.c"
    break;

  case 667:
#line 2932 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
  {
    xfree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
#line 6534 "conf_parser.c"
    break;

  case 668:
#line 2941 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
#line 6543 "conf_parser.c"
    break;

  case 669:
#line 2947 "conf_parser.y"
{
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
#line 6552 "conf_parser.c"
    break;


#line 6556 "conf_parser.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
                  yystos[+*yyssp], yyvsp);
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
