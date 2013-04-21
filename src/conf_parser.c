/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 25 "conf_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "conf_class.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h"
#include "hostmask.h"
#include "send.h"
#include "listener.h"
#include "resv.h"
#include "numeric.h"
#include "s_user.h"

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
  struct {
    dlink_list list;
  } mask,
    leaf,
    hub;

  struct {
    char buf[IRCD_BUFSIZE];
  } name,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    rpass,
    spass,
    class;

  struct {
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
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.mask.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.mask.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.leaf.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.leaf.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.hub.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.hub.list);
    free_dlink_node(ptr);
  }

  memset(&block_state, 0, sizeof(block_state));
}


/* Line 371 of yacc.c  */
#line 181 "conf_parser.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ADMIN = 259,
     AFTYPE = 260,
     ANTI_NICK_FLOOD = 261,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
     AUTOCONN = 263,
     BYTES = 264,
     KBYTES = 265,
     MBYTES = 266,
     CALLER_ID_WAIT = 267,
     CAN_FLOOD = 268,
     CHANNEL = 269,
     CIDR_BITLEN_IPV4 = 270,
     CIDR_BITLEN_IPV6 = 271,
     CLASS = 272,
     CONNECT = 273,
     CONNECTFREQ = 274,
     DEFAULT_FLOODCOUNT = 275,
     DEFAULT_SPLIT_SERVER_COUNT = 276,
     DEFAULT_SPLIT_USER_COUNT = 277,
     DENY = 278,
     DESCRIPTION = 279,
     DIE = 280,
     DISABLE_AUTH = 281,
     DISABLE_FAKE_CHANNELS = 282,
     DISABLE_REMOTE_COMMANDS = 283,
     DOTS_IN_IDENT = 284,
     EGDPOOL_PATH = 285,
     EMAIL = 286,
     ENCRYPTED = 287,
     EXCEED_LIMIT = 288,
     EXEMPT = 289,
     FAILED_OPER_NOTICE = 290,
     IRCD_FLAGS = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_REQUEST_DURATION = 299,
     GLINE_MIN_CIDR = 300,
     GLINE_MIN_CIDR6 = 301,
     GLOBAL_KILL = 302,
     IRCD_AUTH = 303,
     NEED_IDENT = 304,
     HAVENT_READ_CONF = 305,
     HIDDEN = 306,
     HIDDEN_NAME = 307,
     HIDE_SERVER_IPS = 308,
     HIDE_SERVERS = 309,
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     KILL = 317,
     KILL_CHASE_TIME_LIMIT = 318,
     KLINE = 319,
     KLINE_EXEMPT = 320,
     KNOCK_DELAY = 321,
     KNOCK_DELAY_CHANNEL = 322,
     LEAF_MASK = 323,
     LINKS_DELAY = 324,
     LISTEN = 325,
     T_LOG = 326,
     MAX_ACCEPT = 327,
     MAX_BANS = 328,
     MAX_CHANS_PER_OPER = 329,
     MAX_CHANS_PER_USER = 330,
     MAX_GLOBAL = 331,
     MAX_IDENT = 332,
     MAX_LOCAL = 333,
     MAX_NICK_CHANGES = 334,
     MAX_NICK_LENGTH = 335,
     MAX_NICK_TIME = 336,
     MAX_NUMBER = 337,
     MAX_TARGETS = 338,
     MAX_TOPIC_LENGTH = 339,
     MAX_WATCH = 340,
     MIN_NONWILDCARD = 341,
     MIN_NONWILDCARD_SIMPLE = 342,
     MIN_IDLE = 343,
     MAX_IDLE = 344,
     RANDOM_IDLE = 345,
     HIDE_IDLE_FROM_OPERS = 346,
     MODULE = 347,
     MODULES = 348,
     NAME = 349,
     NEED_PASSWORD = 350,
     NETWORK_DESC = 351,
     NETWORK_NAME = 352,
     NICK = 353,
     NICK_CHANGES = 354,
     NO_CREATE_ON_SPLIT = 355,
     NO_JOIN_ON_SPLIT = 356,
     NO_OPER_FLOOD = 357,
     NO_TILDE = 358,
     NUMBER = 359,
     NUMBER_PER_CIDR = 360,
     NUMBER_PER_IP = 361,
     OPERATOR = 362,
     OPERS_BYPASS_CALLERID = 363,
     OPER_ONLY_UMODES = 364,
     OPER_PASS_RESV = 365,
     OPER_SPY_T = 366,
     OPER_UMODES = 367,
     JOIN_FLOOD_COUNT = 368,
     JOIN_FLOOD_TIME = 369,
     PACE_WAIT = 370,
     PACE_WAIT_SIMPLE = 371,
     PASSWORD = 372,
     PATH = 373,
     PING_COOKIE = 374,
     PING_TIME = 375,
     PORT = 376,
     QSTRING = 377,
     QUIET_ON_BAN = 378,
     REASON = 379,
     REDIRPORT = 380,
     REDIRSERV = 381,
     REGEX_T = 382,
     REHASH = 383,
     REMOTE = 384,
     REMOTEBAN = 385,
     RESTRICT_CHANNELS = 386,
     RSA_PRIVATE_KEY_FILE = 387,
     RSA_PUBLIC_KEY_FILE = 388,
     SSL_CERTIFICATE_FILE = 389,
     SSL_DH_PARAM_FILE = 390,
     T_SSL_CLIENT_METHOD = 391,
     T_SSL_SERVER_METHOD = 392,
     T_SSLV3 = 393,
     T_TLSV1 = 394,
     RESV = 395,
     RESV_EXEMPT = 396,
     SECONDS = 397,
     MINUTES = 398,
     HOURS = 399,
     DAYS = 400,
     WEEKS = 401,
     MONTHS = 402,
     YEARS = 403,
     SENDQ = 404,
     SEND_PASSWORD = 405,
     SERVERHIDE = 406,
     SERVERINFO = 407,
     IRCD_SID = 408,
     TKLINE_EXPIRE_NOTICES = 409,
     T_SHARED = 410,
     T_CLUSTER = 411,
     TYPE = 412,
     SHORT_MOTD = 413,
     SPOOF = 414,
     SPOOF_NOTICE = 415,
     STATS_E_DISABLED = 416,
     STATS_I_OPER_ONLY = 417,
     STATS_K_OPER_ONLY = 418,
     STATS_O_OPER_ONLY = 419,
     STATS_P_OPER_ONLY = 420,
     TBOOL = 421,
     TMASKED = 422,
     TS_MAX_DELTA = 423,
     TS_WARN_DELTA = 424,
     TWODOTS = 425,
     T_ALL = 426,
     T_BOTS = 427,
     T_SOFTCALLERID = 428,
     T_CALLERID = 429,
     T_CCONN = 430,
     T_CCONN_FULL = 431,
     T_SSL_CIPHER_LIST = 432,
     T_DEAF = 433,
     T_DEBUG = 434,
     T_DLINE = 435,
     T_EXTERNAL = 436,
     T_FULL = 437,
     T_INVISIBLE = 438,
     T_IPV4 = 439,
     T_IPV6 = 440,
     T_LOCOPS = 441,
     T_MAX_CLIENTS = 442,
     T_NCHANGE = 443,
     T_OPERWALL = 444,
     T_RECVQ = 445,
     T_REJ = 446,
     T_SERVER = 447,
     T_SERVNOTICE = 448,
     T_SET = 449,
     T_SKILL = 450,
     T_SPY = 451,
     T_SSL = 452,
     T_UMODES = 453,
     T_UNAUTH = 454,
     T_UNDLINE = 455,
     T_UNLIMITED = 456,
     T_UNRESV = 457,
     T_UNXLINE = 458,
     T_GLOBOPS = 459,
     T_WALLOP = 460,
     T_WEBIRC = 461,
     T_RESTART = 462,
     T_SERVICE = 463,
     T_SERVICES_NAME = 464,
     THROTTLE_TIME = 465,
     TRUE_NO_OPER_FLOOD = 466,
     UNKLINE = 467,
     USER = 468,
     USE_EGD = 469,
     USE_LOGGING = 470,
     VHOST = 471,
     VHOST6 = 472,
     XLINE = 473,
     WARN_NO_NLINE = 474,
     T_SIZE = 475,
     T_FILE = 476
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define BYTES 264
#define KBYTES 265
#define MBYTES 266
#define CALLER_ID_WAIT 267
#define CAN_FLOOD 268
#define CHANNEL 269
#define CIDR_BITLEN_IPV4 270
#define CIDR_BITLEN_IPV6 271
#define CLASS 272
#define CONNECT 273
#define CONNECTFREQ 274
#define DEFAULT_FLOODCOUNT 275
#define DEFAULT_SPLIT_SERVER_COUNT 276
#define DEFAULT_SPLIT_USER_COUNT 277
#define DENY 278
#define DESCRIPTION 279
#define DIE 280
#define DISABLE_AUTH 281
#define DISABLE_FAKE_CHANNELS 282
#define DISABLE_REMOTE_COMMANDS 283
#define DOTS_IN_IDENT 284
#define EGDPOOL_PATH 285
#define EMAIL 286
#define ENCRYPTED 287
#define EXCEED_LIMIT 288
#define EXEMPT 289
#define FAILED_OPER_NOTICE 290
#define IRCD_FLAGS 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_REQUEST_DURATION 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLOBAL_KILL 302
#define IRCD_AUTH 303
#define NEED_IDENT 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define KILL 317
#define KILL_CHASE_TIME_LIMIT 318
#define KLINE 319
#define KLINE_EXEMPT 320
#define KNOCK_DELAY 321
#define KNOCK_DELAY_CHANNEL 322
#define LEAF_MASK 323
#define LINKS_DELAY 324
#define LISTEN 325
#define T_LOG 326
#define MAX_ACCEPT 327
#define MAX_BANS 328
#define MAX_CHANS_PER_OPER 329
#define MAX_CHANS_PER_USER 330
#define MAX_GLOBAL 331
#define MAX_IDENT 332
#define MAX_LOCAL 333
#define MAX_NICK_CHANGES 334
#define MAX_NICK_LENGTH 335
#define MAX_NICK_TIME 336
#define MAX_NUMBER 337
#define MAX_TARGETS 338
#define MAX_TOPIC_LENGTH 339
#define MAX_WATCH 340
#define MIN_NONWILDCARD 341
#define MIN_NONWILDCARD_SIMPLE 342
#define MIN_IDLE 343
#define MAX_IDLE 344
#define RANDOM_IDLE 345
#define HIDE_IDLE_FROM_OPERS 346
#define MODULE 347
#define MODULES 348
#define NAME 349
#define NEED_PASSWORD 350
#define NETWORK_DESC 351
#define NETWORK_NAME 352
#define NICK 353
#define NICK_CHANGES 354
#define NO_CREATE_ON_SPLIT 355
#define NO_JOIN_ON_SPLIT 356
#define NO_OPER_FLOOD 357
#define NO_TILDE 358
#define NUMBER 359
#define NUMBER_PER_CIDR 360
#define NUMBER_PER_IP 361
#define OPERATOR 362
#define OPERS_BYPASS_CALLERID 363
#define OPER_ONLY_UMODES 364
#define OPER_PASS_RESV 365
#define OPER_SPY_T 366
#define OPER_UMODES 367
#define JOIN_FLOOD_COUNT 368
#define JOIN_FLOOD_TIME 369
#define PACE_WAIT 370
#define PACE_WAIT_SIMPLE 371
#define PASSWORD 372
#define PATH 373
#define PING_COOKIE 374
#define PING_TIME 375
#define PORT 376
#define QSTRING 377
#define QUIET_ON_BAN 378
#define REASON 379
#define REDIRPORT 380
#define REDIRSERV 381
#define REGEX_T 382
#define REHASH 383
#define REMOTE 384
#define REMOTEBAN 385
#define RESTRICT_CHANNELS 386
#define RSA_PRIVATE_KEY_FILE 387
#define RSA_PUBLIC_KEY_FILE 388
#define SSL_CERTIFICATE_FILE 389
#define SSL_DH_PARAM_FILE 390
#define T_SSL_CLIENT_METHOD 391
#define T_SSL_SERVER_METHOD 392
#define T_SSLV3 393
#define T_TLSV1 394
#define RESV 395
#define RESV_EXEMPT 396
#define SECONDS 397
#define MINUTES 398
#define HOURS 399
#define DAYS 400
#define WEEKS 401
#define MONTHS 402
#define YEARS 403
#define SENDQ 404
#define SEND_PASSWORD 405
#define SERVERHIDE 406
#define SERVERINFO 407
#define IRCD_SID 408
#define TKLINE_EXPIRE_NOTICES 409
#define T_SHARED 410
#define T_CLUSTER 411
#define TYPE 412
#define SHORT_MOTD 413
#define SPOOF 414
#define SPOOF_NOTICE 415
#define STATS_E_DISABLED 416
#define STATS_I_OPER_ONLY 417
#define STATS_K_OPER_ONLY 418
#define STATS_O_OPER_ONLY 419
#define STATS_P_OPER_ONLY 420
#define TBOOL 421
#define TMASKED 422
#define TS_MAX_DELTA 423
#define TS_WARN_DELTA 424
#define TWODOTS 425
#define T_ALL 426
#define T_BOTS 427
#define T_SOFTCALLERID 428
#define T_CALLERID 429
#define T_CCONN 430
#define T_CCONN_FULL 431
#define T_SSL_CIPHER_LIST 432
#define T_DEAF 433
#define T_DEBUG 434
#define T_DLINE 435
#define T_EXTERNAL 436
#define T_FULL 437
#define T_INVISIBLE 438
#define T_IPV4 439
#define T_IPV6 440
#define T_LOCOPS 441
#define T_MAX_CLIENTS 442
#define T_NCHANGE 443
#define T_OPERWALL 444
#define T_RECVQ 445
#define T_REJ 446
#define T_SERVER 447
#define T_SERVNOTICE 448
#define T_SET 449
#define T_SKILL 450
#define T_SPY 451
#define T_SSL 452
#define T_UMODES 453
#define T_UNAUTH 454
#define T_UNDLINE 455
#define T_UNLIMITED 456
#define T_UNRESV 457
#define T_UNXLINE 458
#define T_GLOBOPS 459
#define T_WALLOP 460
#define T_WEBIRC 461
#define T_RESTART 462
#define T_SERVICE 463
#define T_SERVICES_NAME 464
#define THROTTLE_TIME 465
#define TRUE_NO_OPER_FLOOD 466
#define UNKLINE 467
#define USER 468
#define USE_EGD 469
#define USE_LOGGING 470
#define VHOST 471
#define VHOST6 472
#define XLINE 473
#define WARN_NO_NLINE 474
#define T_SIZE 475
#define T_FILE 476



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 672 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 700 "conf_parser.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  227
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  289
/* YYNRULES -- Number of rules.  */
#define YYNRULES  641
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1254

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   476

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   226,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   222,
       2,   225,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   224,     2,   223,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    83,    87,    88,    90,    93,
      97,   101,   105,   111,   114,   116,   118,   120,   123,   128,
     133,   139,   142,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   181,   186,   191,   195,   197,   199,   201,   205,   207,
     209,   211,   216,   221,   226,   231,   236,   241,   246,   251,
     256,   261,   266,   271,   276,   281,   286,   292,   295,   297,
     299,   301,   303,   306,   311,   316,   321,   327,   330,   332,
     334,   336,   339,   344,   345,   352,   355,   357,   359,   361,
     363,   366,   371,   376,   381,   382,   388,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   409,   416,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   440,   445,
     450,   455,   460,   465,   470,   471,   477,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   524,
     530,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   558,   560,   562,   564,   566,   568,   570,
     572,   574,   575,   582,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   622,   627,   632,   637,   642,   647,   652,   657,
     662,   667,   672,   677,   682,   687,   692,   697,   698,   704,
     708,   710,   712,   714,   715,   722,   723,   729,   733,   735,
     737,   739,   741,   744,   746,   748,   750,   752,   754,   757,
     758,   764,   768,   770,   772,   776,   781,   786,   787,   794,
     797,   799,   801,   803,   805,   807,   809,   811,   813,   815,
     818,   823,   828,   833,   838,   839,   845,   849,   851,   853,
     855,   857,   859,   861,   863,   865,   867,   869,   871,   876,
     881,   886,   887,   894,   897,   899,   901,   903,   905,   908,
     913,   918,   923,   929,   932,   934,   936,   938,   943,   944,
     951,   954,   956,   958,   960,   962,   965,   970,   975,   976,
     982,   986,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1009,  1016,  1019,  1021,  1023,  1025,  1028,
    1033,  1034,  1040,  1044,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1067,  1074,  1077,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1108,  1113,  1118,  1123,  1128,  1133,  1138,  1143,
    1148,  1149,  1155,  1159,  1161,  1163,  1165,  1170,  1175,  1180,
    1185,  1190,  1191,  1198,  1199,  1205,  1209,  1211,  1213,  1216,
    1218,  1220,  1222,  1224,  1226,  1231,  1236,  1237,  1244,  1247,
    1249,  1251,  1253,  1255,  1260,  1265,  1271,  1274,  1276,  1278,
    1280,  1285,  1286,  1293,  1294,  1300,  1304,  1306,  1308,  1311,
    1313,  1315,  1317,  1319,  1321,  1326,  1331,  1337,  1340,  1342,
    1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,
    1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,
    1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1445,
    1450,  1455,  1460,  1465,  1470,  1475,  1480,  1485,  1490,  1495,
    1500,  1505,  1510,  1515,  1520,  1525,  1530,  1535,  1540,  1545,
    1550,  1555,  1560,  1565,  1570,  1575,  1580,  1585,  1590,  1595,
    1600,  1605,  1610,  1615,  1620,  1625,  1630,  1635,  1640,  1645,
    1650,  1655,  1660,  1665,  1666,  1672,  1676,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1719,  1725,
    1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1776,  1781,  1786,  1792,  1795,  1797,  1799,  1801,
    1803,  1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,  1821,
    1823,  1825,  1827,  1832,  1837,  1842,  1847,  1852,  1857,  1862,
    1867,  1872,  1877,  1882,  1887,  1892,  1897,  1903,  1906,  1908,
    1910,  1912,  1914,  1916,  1918,  1920,  1922,  1927,  1932,  1937,
    1942,  1947
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     228,     0,    -1,    -1,   228,   229,    -1,   263,    -1,   269,
      -1,   283,    -1,   490,    -1,   301,    -1,   324,    -1,   338,
      -1,   239,    -1,   507,    -1,   353,    -1,   360,    -1,   364,
      -1,   374,    -1,   383,    -1,   403,    -1,   413,    -1,   419,
      -1,   433,    -1,   423,    -1,   234,    -1,     1,   222,    -1,
       1,   223,    -1,    -1,   231,    -1,   104,   230,    -1,   104,
     142,   230,    -1,   104,   143,   230,    -1,   104,   144,   230,
      -1,   104,   145,   230,    -1,   104,   146,   230,    -1,   104,
     147,   230,    -1,   104,   148,   230,    -1,    -1,   233,    -1,
     104,   232,    -1,   104,     9,   232,    -1,   104,    10,   232,
      -1,   104,    11,   232,    -1,    93,   224,   235,   223,   222,
      -1,   235,   236,    -1,   236,    -1,   237,    -1,   238,    -1,
       1,   222,    -1,    92,   225,   122,   222,    -1,   118,   225,
     122,   222,    -1,   152,   224,   240,   223,   222,    -1,   240,
     241,    -1,   241,    -1,   252,    -1,   257,    -1,   262,    -1,
     254,    -1,   255,    -1,   256,    -1,   259,    -1,   260,    -1,
     261,    -1,   250,    -1,   249,    -1,   258,    -1,   253,    -1,
     248,    -1,   242,    -1,   243,    -1,   251,    -1,     1,   222,
      -1,   136,   225,   244,   222,    -1,   137,   225,   246,   222,
      -1,   244,   226,   245,    -1,   245,    -1,   138,    -1,   139,
      -1,   246,   226,   247,    -1,   247,    -1,   138,    -1,   139,
      -1,   134,   225,   122,   222,    -1,   132,   225,   122,   222,
      -1,   135,   225,   122,   222,    -1,   177,   225,   122,   222,
      -1,    94,   225,   122,   222,    -1,   153,   225,   122,   222,
      -1,    24,   225,   122,   222,    -1,    97,   225,   122,   222,
      -1,    96,   225,   122,   222,    -1,   216,   225,   122,   222,
      -1,   217,   225,   122,   222,    -1,   187,   225,   104,   222,
      -1,    80,   225,   104,   222,    -1,    84,   225,   104,   222,
      -1,    57,   225,   166,   222,    -1,     4,   224,   264,   223,
     222,    -1,   264,   265,    -1,   265,    -1,   266,    -1,   268,
      -1,   267,    -1,     1,   222,    -1,    94,   225,   122,   222,
      -1,    31,   225,   122,   222,    -1,    24,   225,   122,   222,
      -1,    71,   224,   270,   223,   222,    -1,   270,   271,    -1,
     271,    -1,   272,    -1,   273,    -1,     1,   222,    -1,   215,
     225,   166,   222,    -1,    -1,   274,   221,   224,   275,   223,
     222,    -1,   275,   276,    -1,   276,    -1,   277,    -1,   279,
      -1,   278,    -1,     1,   222,    -1,    94,   225,   122,   222,
      -1,   220,   225,   233,   222,    -1,   220,   225,   201,   222,
      -1,    -1,   157,   280,   225,   281,   222,    -1,   281,   226,
     282,    -1,   282,    -1,   213,    -1,   107,    -1,    40,    -1,
     180,    -1,    64,    -1,    62,    -1,   179,    -1,    -1,   107,
     284,   224,   285,   223,   222,    -1,   285,   286,    -1,   286,
      -1,   287,    -1,   288,    -1,   289,    -1,   293,    -1,   292,
      -1,   290,    -1,   291,    -1,   297,    -1,     1,   222,    -1,
      94,   225,   122,   222,    -1,   213,   225,   122,   222,    -1,
     117,   225,   122,   222,    -1,    32,   225,   166,   222,    -1,
     133,   225,   122,   222,    -1,    17,   225,   122,   222,    -1,
      -1,   198,   294,   225,   295,   222,    -1,   295,   226,   296,
      -1,   296,    -1,   172,    -1,   175,    -1,   176,    -1,   178,
      -1,   179,    -1,   182,    -1,    51,    -1,   195,    -1,   188,
      -1,   191,    -1,   199,    -1,   196,    -1,   181,    -1,   189,
      -1,   193,    -1,   183,    -1,   205,    -1,   173,    -1,   174,
      -1,   186,    -1,    -1,    36,   298,   225,   299,   222,    -1,
     299,   226,   300,    -1,   300,    -1,    47,    -1,   129,    -1,
      64,    -1,   212,    -1,   180,    -1,   200,    -1,   218,    -1,
      40,    -1,    25,    -1,   207,    -1,   128,    -1,     4,    -1,
      99,    -1,   189,    -1,   204,    -1,   111,    -1,   130,    -1,
     194,    -1,    92,    -1,    -1,    17,   302,   224,   303,   223,
     222,    -1,   303,   304,    -1,   304,    -1,   305,    -1,   315,
      -1,   316,    -1,   306,    -1,   317,    -1,   307,    -1,   308,
      -1,   309,    -1,   310,    -1,   311,    -1,   312,    -1,   313,
      -1,   314,    -1,   318,    -1,   319,    -1,   320,    -1,     1,
     222,    -1,    94,   225,   122,   222,    -1,   120,   225,   231,
     222,    -1,   106,   225,   104,   222,    -1,    19,   225,   231,
     222,    -1,    82,   225,   104,   222,    -1,    76,   225,   104,
     222,    -1,    78,   225,   104,   222,    -1,    77,   225,   104,
     222,    -1,   149,   225,   233,   222,    -1,   190,   225,   233,
     222,    -1,    15,   225,   104,   222,    -1,    16,   225,   104,
     222,    -1,   105,   225,   104,   222,    -1,    88,   225,   231,
     222,    -1,    89,   225,   231,   222,    -1,    -1,    36,   321,
     225,   322,   222,    -1,   322,   226,   323,    -1,   323,    -1,
      90,    -1,    91,    -1,    -1,    70,   325,   224,   330,   223,
     222,    -1,    -1,    36,   327,   225,   328,   222,    -1,   328,
     226,   329,    -1,   329,    -1,   197,    -1,    51,    -1,   192,
      -1,   330,   331,    -1,   331,    -1,   332,    -1,   326,    -1,
     336,    -1,   337,    -1,     1,   222,    -1,    -1,   121,   225,
     334,   333,   222,    -1,   334,   226,   335,    -1,   335,    -1,
     104,    -1,   104,   170,   104,    -1,    61,   225,   122,   222,
      -1,    56,   225,   122,   222,    -1,    -1,    48,   339,   224,
     340,   223,   222,    -1,   340,   341,    -1,   341,    -1,   342,
      -1,   343,    -1,   344,    -1,   346,    -1,   350,    -1,   351,
      -1,   352,    -1,   345,    -1,     1,   222,    -1,   213,   225,
     122,   222,    -1,   117,   225,   122,   222,    -1,    17,   225,
     122,   222,    -1,    32,   225,   166,   222,    -1,    -1,    36,
     347,   225,   348,   222,    -1,   348,   226,   349,    -1,   349,
      -1,   160,    -1,    33,    -1,    65,    -1,    49,    -1,    13,
      -1,   103,    -1,    43,    -1,   141,    -1,   206,    -1,    95,
      -1,   159,   225,   122,   222,    -1,   126,   225,   122,   222,
      -1,   125,   225,   104,   222,    -1,    -1,   140,   354,   224,
     355,   223,   222,    -1,   355,   356,    -1,   356,    -1,   357,
      -1,   358,    -1,   359,    -1,     1,   222,    -1,   124,   225,
     122,   222,    -1,    14,   225,   122,   222,    -1,    98,   225,
     122,   222,    -1,   208,   224,   361,   223,   222,    -1,   361,
     362,    -1,   362,    -1,   363,    -1,     1,    -1,    94,   225,
     122,   222,    -1,    -1,   155,   365,   224,   366,   223,   222,
      -1,   366,   367,    -1,   367,    -1,   368,    -1,   369,    -1,
     370,    -1,     1,   222,    -1,    94,   225,   122,   222,    -1,
     213,   225,   122,   222,    -1,    -1,   157,   371,   225,   372,
     222,    -1,   372,   226,   373,    -1,   373,    -1,    64,    -1,
     212,    -1,   180,    -1,   200,    -1,   218,    -1,   203,    -1,
     140,    -1,   202,    -1,   186,    -1,   171,    -1,    -1,   156,
     375,   224,   376,   223,   222,    -1,   376,   377,    -1,   377,
      -1,   378,    -1,   379,    -1,     1,   222,    -1,    94,   225,
     122,   222,    -1,    -1,   157,   380,   225,   381,   222,    -1,
     381,   226,   382,    -1,   382,    -1,    64,    -1,   212,    -1,
     180,    -1,   200,    -1,   218,    -1,   203,    -1,   140,    -1,
     202,    -1,   186,    -1,   171,    -1,    -1,    18,   384,   224,
     385,   223,   222,    -1,   385,   386,    -1,   386,    -1,   387,
      -1,   388,    -1,   389,    -1,   390,    -1,   391,    -1,   393,
      -1,   392,    -1,   402,    -1,   394,    -1,   399,    -1,   400,
      -1,   401,    -1,   398,    -1,     1,   222,    -1,    94,   225,
     122,   222,    -1,    56,   225,   122,   222,    -1,   216,   225,
     122,   222,    -1,   150,   225,   122,   222,    -1,     3,   225,
     122,   222,    -1,   121,   225,   104,   222,    -1,     5,   225,
     184,   222,    -1,     5,   225,   185,   222,    -1,    -1,    36,
     395,   225,   396,   222,    -1,   396,   226,   397,    -1,   397,
      -1,     8,    -1,   197,    -1,    32,   225,   166,   222,    -1,
      58,   225,   122,   222,    -1,    68,   225,   122,   222,    -1,
      17,   225,   122,   222,    -1,   177,   225,   122,   222,    -1,
      -1,    62,   404,   224,   409,   223,   222,    -1,    -1,   157,
     406,   225,   407,   222,    -1,   407,   226,   408,    -1,   408,
      -1,   127,    -1,   409,   410,    -1,   410,    -1,   411,    -1,
     412,    -1,   405,    -1,     1,    -1,   213,   225,   122,   222,
      -1,   124,   225,   122,   222,    -1,    -1,    23,   414,   224,
     415,   223,   222,    -1,   415,   416,    -1,   416,    -1,   417,
      -1,   418,    -1,     1,    -1,    61,   225,   122,   222,    -1,
     124,   225,   122,   222,    -1,    34,   224,   420,   223,   222,
      -1,   420,   421,    -1,   421,    -1,   422,    -1,     1,    -1,
      61,   225,   122,   222,    -1,    -1,    38,   424,   224,   429,
     223,   222,    -1,    -1,   157,   426,   225,   427,   222,    -1,
     427,   226,   428,    -1,   428,    -1,   127,    -1,   429,   430,
      -1,   430,    -1,   431,    -1,   432,    -1,   425,    -1,     1,
      -1,    94,   225,   122,   222,    -1,   124,   225,   122,   222,
      -1,    39,   224,   434,   223,   222,    -1,   434,   435,    -1,
     435,    -1,   444,    -1,   445,    -1,   447,    -1,   448,    -1,
     449,    -1,   450,    -1,   451,    -1,   452,    -1,   453,    -1,
     454,    -1,   443,    -1,   456,    -1,   457,    -1,   471,    -1,
     459,    -1,   461,    -1,   463,    -1,   462,    -1,   466,    -1,
     460,    -1,   467,    -1,   468,    -1,   469,    -1,   470,    -1,
     483,    -1,   472,    -1,   473,    -1,   474,    -1,   479,    -1,
     464,    -1,   465,    -1,   489,    -1,   487,    -1,   488,    -1,
     446,    -1,   478,    -1,   455,    -1,   476,    -1,   477,    -1,
     442,    -1,   437,    -1,   438,    -1,   439,    -1,   440,    -1,
     441,    -1,   458,    -1,   436,    -1,   475,    -1,     1,    -1,
      85,   225,   104,   222,    -1,    42,   225,   166,   222,    -1,
      41,   225,   231,   222,    -1,    44,   225,   231,   222,    -1,
      45,   225,   104,   222,    -1,    46,   225,   104,   222,    -1,
     154,   225,   166,   222,    -1,    63,   225,   231,   222,    -1,
      55,   225,   166,   222,    -1,    59,   225,   166,   222,    -1,
      28,   225,   166,   222,    -1,    35,   225,   166,   222,    -1,
       6,   225,   166,   222,    -1,    81,   225,   231,   222,    -1,
      79,   225,   104,   222,    -1,    72,   225,   104,   222,    -1,
       7,   225,   231,   222,    -1,   169,   225,   231,   222,    -1,
     168,   225,   231,   222,    -1,    50,   225,   104,   222,    -1,
      60,   225,   166,   222,    -1,   219,   225,   166,   222,    -1,
     161,   225,   166,   222,    -1,   164,   225,   166,   222,    -1,
     165,   225,   166,   222,    -1,   163,   225,   166,   222,    -1,
     163,   225,   167,   222,    -1,   162,   225,   166,   222,    -1,
     162,   225,   167,   222,    -1,   115,   225,   231,   222,    -1,
      12,   225,   231,   222,    -1,   108,   225,   166,   222,    -1,
     116,   225,   231,   222,    -1,   158,   225,   166,   222,    -1,
     102,   225,   166,   222,    -1,   211,   225,   166,   222,    -1,
     110,   225,   166,   222,    -1,    29,   225,   104,   222,    -1,
      83,   225,   104,   222,    -1,   214,   225,   166,   222,    -1,
      30,   225,   122,   222,    -1,   209,   225,   122,   222,    -1,
     119,   225,   166,   222,    -1,    26,   225,   166,   222,    -1,
     210,   225,   231,   222,    -1,    -1,   112,   480,   225,   481,
     222,    -1,   481,   226,   482,    -1,   482,    -1,   172,    -1,
     175,    -1,   176,    -1,   178,    -1,   179,    -1,   182,    -1,
      51,    -1,   195,    -1,   188,    -1,   191,    -1,   199,    -1,
     196,    -1,   181,    -1,   189,    -1,   193,    -1,   183,    -1,
     205,    -1,   173,    -1,   174,    -1,   186,    -1,    -1,   109,
     484,   225,   485,   222,    -1,   485,   226,   486,    -1,   486,
      -1,   172,    -1,   175,    -1,   176,    -1,   178,    -1,   179,
      -1,   182,    -1,   195,    -1,    51,    -1,   188,    -1,   191,
      -1,   199,    -1,   196,    -1,   181,    -1,   189,    -1,   193,
      -1,   183,    -1,   205,    -1,   173,    -1,   174,    -1,   186,
      -1,    86,   225,   104,   222,    -1,    87,   225,   104,   222,
      -1,    20,   225,   104,   222,    -1,    14,   224,   491,   223,
     222,    -1,   491,   492,    -1,   492,    -1,   500,    -1,   495,
      -1,   496,    -1,   497,    -1,   498,    -1,   499,    -1,   501,
      -1,   502,    -1,   503,    -1,   494,    -1,   504,    -1,   505,
      -1,   506,    -1,   493,    -1,     1,    -1,    27,   225,   166,
     222,    -1,   131,   225,   166,   222,    -1,    66,   225,   231,
     222,    -1,    67,   225,   231,   222,    -1,    75,   225,   104,
     222,    -1,    74,   225,   104,   222,    -1,   123,   225,   166,
     222,    -1,    73,   225,   104,   222,    -1,    22,   225,   104,
     222,    -1,    21,   225,   104,   222,    -1,   100,   225,   166,
     222,    -1,   101,   225,   166,   222,    -1,   113,   225,   104,
     222,    -1,   114,   225,   231,   222,    -1,   151,   224,   508,
     223,   222,    -1,   508,   509,    -1,   509,    -1,   510,    -1,
     511,    -1,   513,    -1,   514,    -1,   512,    -1,   515,    -1,
       1,    -1,    37,   225,   166,   222,    -1,    54,   225,   166,
     222,    -1,    52,   225,   122,   222,    -1,    69,   225,   231,
     222,    -1,    51,   225,   166,   222,    -1,    53,   225,   166,
     222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   363,   363,   364,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   392,   392,   393,   397,
     401,   405,   409,   413,   417,   421,   427,   427,   428,   429,
     430,   431,   438,   441,   441,   442,   442,   442,   444,   450,
     457,   459,   459,   460,   460,   461,   461,   462,   462,   463,
     463,   464,   464,   465,   465,   466,   466,   467,   467,   468,
     469,   472,   473,   475,   475,   476,   482,   490,   490,   491,
     497,   505,   547,   606,   634,   642,   657,   672,   681,   695,
     704,   732,   762,   787,   809,   831,   840,   842,   842,   843,
     843,   844,   844,   846,   855,   864,   876,   877,   877,   879,
     879,   880,   882,   889,   889,   902,   903,   905,   905,   906,
     906,   908,   916,   919,   925,   924,   930,   930,   931,   935,
     939,   943,   947,   951,   955,   966,   965,  1042,  1042,  1043,
    1043,  1043,  1044,  1044,  1044,  1045,  1045,  1045,  1047,  1053,
    1059,  1065,  1076,  1082,  1089,  1088,  1094,  1094,  1095,  1099,
    1103,  1107,  1111,  1115,  1119,  1123,  1127,  1131,  1135,  1139,
    1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,  1178,  1177,
    1183,  1183,  1184,  1188,  1192,  1196,  1200,  1204,  1208,  1212,
    1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,
    1256,  1267,  1266,  1327,  1327,  1328,  1329,  1329,  1330,  1331,
    1332,  1333,  1334,  1335,  1336,  1337,  1338,  1338,  1339,  1340,
    1341,  1342,  1344,  1350,  1356,  1362,  1368,  1374,  1380,  1386,
    1392,  1398,  1405,  1411,  1417,  1423,  1432,  1442,  1441,  1447,
    1447,  1448,  1452,  1463,  1462,  1469,  1468,  1473,  1473,  1474,
    1478,  1482,  1488,  1488,  1489,  1489,  1489,  1489,  1489,  1491,
    1491,  1493,  1493,  1495,  1509,  1529,  1535,  1545,  1544,  1586,
    1586,  1587,  1587,  1587,  1587,  1588,  1588,  1588,  1589,  1589,
    1591,  1597,  1603,  1609,  1621,  1620,  1626,  1626,  1627,  1631,
    1635,  1639,  1643,  1647,  1651,  1655,  1659,  1663,  1669,  1683,
    1692,  1706,  1705,  1720,  1720,  1721,  1721,  1721,  1721,  1723,
    1729,  1735,  1744,  1746,  1746,  1747,  1747,  1749,  1765,  1764,
    1789,  1789,  1790,  1790,  1790,  1790,  1792,  1798,  1818,  1817,
    1823,  1823,  1824,  1828,  1832,  1836,  1840,  1844,  1848,  1852,
    1856,  1860,  1870,  1869,  1890,  1890,  1891,  1891,  1891,  1893,
    1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1934,  1938,  1942,  1952,  1951,  2017,  2017,  2018,  2018,
    2018,  2019,  2019,  2020,  2020,  2020,  2021,  2021,  2021,  2022,
    2022,  2023,  2025,  2031,  2037,  2043,  2056,  2069,  2075,  2079,
    2088,  2087,  2092,  2092,  2093,  2097,  2103,  2114,  2120,  2126,
    2132,  2148,  2147,  2210,  2209,  2215,  2215,  2216,  2222,  2222,
    2223,  2223,  2223,  2223,  2225,  2245,  2255,  2254,  2281,  2281,
    2282,  2282,  2282,  2284,  2290,  2299,  2301,  2301,  2302,  2302,
    2304,  2322,  2321,  2367,  2366,  2372,  2372,  2373,  2379,  2379,
    2380,  2380,  2380,  2380,  2382,  2388,  2397,  2400,  2400,  2401,
    2401,  2402,  2402,  2403,  2403,  2404,  2404,  2405,  2405,  2406,
    2407,  2408,  2408,  2409,  2409,  2410,  2410,  2411,  2411,  2412,
    2412,  2413,  2413,  2414,  2414,  2415,  2415,  2416,  2416,  2417,
    2417,  2418,  2418,  2419,  2420,  2420,  2421,  2422,  2423,  2423,
    2424,  2424,  2425,  2426,  2427,  2428,  2428,  2429,  2432,  2437,
    2443,  2449,  2455,  2460,  2465,  2470,  2475,  2480,  2485,  2490,
    2495,  2500,  2505,  2510,  2515,  2520,  2525,  2531,  2542,  2547,
    2552,  2557,  2562,  2567,  2570,  2575,  2578,  2583,  2588,  2593,
    2598,  2603,  2608,  2613,  2618,  2623,  2628,  2633,  2638,  2647,
    2656,  2661,  2666,  2672,  2671,  2676,  2676,  2677,  2680,  2683,
    2686,  2689,  2692,  2695,  2698,  2701,  2704,  2707,  2710,  2713,
    2716,  2719,  2722,  2725,  2728,  2731,  2734,  2740,  2739,  2744,
    2744,  2745,  2748,  2751,  2754,  2757,  2760,  2763,  2766,  2769,
    2772,  2775,  2778,  2781,  2784,  2787,  2790,  2793,  2796,  2799,
    2802,  2807,  2812,  2817,  2826,  2829,  2829,  2830,  2831,  2831,
    2832,  2832,  2833,  2833,  2834,  2835,  2835,  2836,  2837,  2837,
    2838,  2838,  2840,  2845,  2850,  2855,  2860,  2865,  2870,  2875,
    2880,  2885,  2890,  2895,  2900,  2905,  2913,  2916,  2916,  2917,
    2917,  2918,  2919,  2919,  2920,  2921,  2923,  2929,  2935,  2944,
    2958,  2964
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ADMIN", "AFTYPE",
  "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME", "AUTOCONN", "BYTES",
  "KBYTES", "MBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "EGDPOOL_PATH", "EMAIL", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT",
  "GLINE_REQUEST_DURATION", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY",
  "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER",
  "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MIN_IDLE", "MAX_IDLE", "RANDOM_IDLE",
  "HIDE_IDLE_FROM_OPERS", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT",
  "REDIRSERV", "REGEX_T", "REHASH", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD",
  "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_WEBIRC", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE",
  "USER", "USE_EGD", "USE_LOGGING", "VHOST", "VHOST6", "XLINE",
  "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@1", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@2", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@3", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@4",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@5",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@6",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@7", "class_flags_items", "class_flags_item",
  "listen_entry", "$@8", "listen_flags", "$@9", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@10", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@11", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@12",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@13", "resv_items", "resv_item",
  "resv_reason", "resv_channel", "resv_nick", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@14",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@15", "shared_types", "shared_type_item",
  "cluster_entry", "$@16", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@17", "cluster_types", "cluster_type_item",
  "connect_entry", "$@18", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@19", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@20",
  "kill_type", "$@21", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@22",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@23",
  "gecos_flags", "$@24", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_invisible_on_connect",
  "general_warn_no_nline", "general_stats_e_disabled",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_dots_in_ident", "general_max_targets", "general_use_egd",
  "general_egdpool_path", "general_services_name", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "$@25", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@26", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_hide_server_ips", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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
     475,   476,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   227,   228,   228,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   230,   230,   231,   231,
     231,   231,   231,   231,   231,   231,   232,   232,   233,   233,
     233,   233,   234,   235,   235,   236,   236,   236,   237,   238,
     239,   240,   240,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   242,   243,   244,   244,   245,   245,   246,   246,   247,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   264,   265,
     265,   265,   265,   266,   267,   268,   269,   270,   270,   271,
     271,   271,   272,   274,   273,   275,   275,   276,   276,   276,
     276,   277,   278,   278,   280,   279,   281,   281,   282,   282,
     282,   282,   282,   282,   282,   284,   283,   285,   285,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   287,   288,
     289,   290,   291,   292,   294,   293,   295,   295,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   298,   297,
     299,   299,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,   300,   300,   300,   300,   300,   300,   300,
     300,   302,   301,   303,   303,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   321,   320,   322,
     322,   323,   323,   325,   324,   327,   326,   328,   328,   329,
     329,   329,   330,   330,   331,   331,   331,   331,   331,   333,
     332,   334,   334,   335,   335,   336,   337,   339,   338,   340,
     340,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     342,   343,   344,   345,   347,   346,   348,   348,   349,   349,
     349,   349,   349,   349,   349,   349,   349,   349,   350,   351,
     352,   354,   353,   355,   355,   356,   356,   356,   356,   357,
     358,   359,   360,   361,   361,   362,   362,   363,   365,   364,
     366,   366,   367,   367,   367,   367,   368,   369,   371,   370,
     372,   372,   373,   373,   373,   373,   373,   373,   373,   373,
     373,   373,   375,   374,   376,   376,   377,   377,   377,   378,
     380,   379,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   384,   383,   385,   385,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   386,   387,   388,   389,   390,   391,   392,   393,   393,
     395,   394,   396,   396,   397,   397,   398,   399,   400,   401,
     402,   404,   403,   406,   405,   407,   407,   408,   409,   409,
     410,   410,   410,   410,   411,   412,   414,   413,   415,   415,
     416,   416,   416,   417,   418,   419,   420,   420,   421,   421,
     422,   424,   423,   426,   425,   427,   427,   428,   429,   429,
     430,   430,   430,   430,   431,   432,   433,   434,   434,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   461,   462,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   480,   479,   481,   481,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   484,   483,   485,
     485,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   487,   488,   489,   490,   491,   491,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   508,   509,
     509,   509,   509,   509,   509,   509,   510,   511,   512,   513,
     514,   515
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     0,     1,     2,     3,
       3,     3,     5,     2,     1,     1,     1,     2,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     2,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
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
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     4,     4,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   201,   364,   416,     0,
     431,     0,   267,   401,   243,     0,     0,   135,   301,     0,
       0,   318,   342,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   596,   610,   606,   598,   599,   600,   601,   602,
     597,   603,   604,   605,   607,   608,   609,     0,     0,     0,
     429,     0,     0,   427,   428,     0,   497,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   567,     0,   543,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,   495,   489,   490,
     491,   492,   493,   488,   459,   449,   450,   483,   451,   452,
     453,   454,   455,   456,   457,   458,   485,   460,   461,   494,
     463,   468,   464,   466,   465,   478,   479,   467,   469,   470,
     471,   472,   462,   474,   475,   476,   496,   486,   487,   484,
     477,   473,   481,   482,   480,     0,     0,     0,     0,     0,
       0,   108,   109,   110,     0,     0,     0,     0,     0,    44,
      45,    46,     0,     0,   635,     0,     0,     0,     0,     0,
       0,     0,   628,   629,   630,   633,   631,   632,   634,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    67,
      68,    66,    63,    62,    69,    53,    65,    56,    57,    58,
      54,    64,    59,    60,    61,    55,     0,     0,   316,     0,
       0,   314,   315,   102,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   595,     0,     0,     0,     0,   237,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   204,   205,   208,   210,   211,   212,   213,
     214,   215,   216,   217,   206,   207,   209,   218,   219,   220,
       0,     0,     0,     0,     0,   390,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   367,   368,   369,   370,   371,
     372,   374,   373,   376,   380,   377,   378,   379,   375,   422,
       0,     0,     0,   419,   420,   421,     0,     0,   426,   443,
       0,     0,   433,   442,     0,   439,   440,   441,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,     0,     0,
       0,   284,     0,     0,     0,     0,     0,     0,   270,   271,
     272,   273,   278,   274,   275,   276,   277,   413,     0,   403,
       0,   412,     0,   409,   410,   411,     0,   245,     0,     0,
       0,   255,     0,   253,   254,   256,   257,   111,     0,     0,
     107,     0,    47,     0,     0,     0,    43,     0,     0,     0,
     178,     0,     0,     0,   154,     0,     0,   138,   139,   140,
     141,   144,   145,   143,   142,   146,     0,     0,     0,     0,
       0,   304,   305,   306,   307,     0,     0,     0,     0,     0,
       0,     0,   627,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,   328,     0,     0,   321,   322,
     323,   324,     0,     0,   350,     0,   345,   346,   347,     0,
       0,   313,     0,     0,     0,    96,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   594,   221,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,   381,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   366,     0,     0,     0,
     418,     0,   425,     0,     0,     0,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   446,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,     0,   408,   258,     0,     0,     0,     0,
       0,   252,     0,   106,     0,     0,     0,    42,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   308,
       0,     0,     0,     0,   303,     0,     0,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   325,     0,     0,     0,
       0,   320,   348,     0,     0,     0,   344,     0,   312,   105,
     104,   103,   621,   620,   612,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   614,   615,   619,   617,   616,   622,
     623,   624,   625,   618,   613,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
       0,     0,   202,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   365,     0,     0,
     417,   430,     0,     0,     0,   432,   510,   514,   528,   593,
     541,   508,   535,   538,   509,   500,   499,   501,   502,   503,
     517,   506,   507,   518,   505,   513,   512,   511,   536,   498,
     591,   592,   532,   529,   578,   571,   588,   589,   572,   573,
     574,   575,   583,   576,   586,   590,   579,   584,   580,   585,
     577,   582,   581,   587,     0,   570,   534,   553,   547,   564,
     565,   548,   549,   550,   551,   559,   552,   562,   566,   555,
     560,   556,   561,   554,   558,   557,   563,     0,   546,   527,
     530,   540,   504,   531,   520,   525,   526,   523,   524,   521,
     522,   516,   515,   539,   542,   533,   537,   519,     0,     0,
       0,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     402,     0,     0,     0,   263,   259,   262,   244,   112,     0,
       0,   124,     0,     0,   116,   117,   119,   118,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,   302,   636,   640,   638,   641,   637,   639,    87,
      95,    93,    94,    85,    89,    88,    82,    81,    83,    71,
       0,    72,     0,    86,    84,    92,    90,    91,     0,     0,
       0,   319,     0,     0,   343,   317,    29,    30,    31,    32,
      33,    34,    35,   232,   233,   225,   241,   242,     0,   240,
     227,   229,   228,   226,   235,   236,   222,   234,   224,   223,
      36,    36,    36,    38,    37,   230,   231,   386,   388,   389,
     399,   396,   394,   395,     0,   393,   383,   397,   398,   382,
     387,   385,   400,   384,   423,   424,   444,   445,   437,     0,
     436,   568,     0,   544,     0,   282,   283,   292,   289,   294,
     291,   290,   297,   293,   295,   288,   296,     0,   287,   281,
     300,   299,   298,   280,   415,   407,     0,   406,   414,   250,
     251,   249,     0,   248,   266,   265,     0,     0,     0,   120,
       0,     0,     0,     0,   115,   153,   151,   193,   190,   189,
     182,   184,   200,   194,   197,   192,   183,   198,   186,   195,
     199,   187,   196,   191,   185,   188,     0,   181,   148,   150,
     152,   164,   158,   175,   176,   159,   160,   161,   162,   170,
     163,   173,   177,   166,   171,   167,   172,   165,   169,   168,
     174,     0,   157,   149,   310,   311,   309,    73,    77,   326,
     332,   338,   341,   334,   340,   335,   339,   337,   333,   336,
       0,   331,   327,   349,   354,   360,   363,   356,   362,   357,
     361,   359,   355,   358,     0,   353,   238,     0,    39,    40,
      41,   391,     0,   434,     0,   569,   545,   285,     0,   404,
       0,   246,     0,   264,   261,   260,     0,     0,     0,     0,
     114,   179,     0,   155,     0,   329,     0,   351,     0,   239,
     392,   435,   286,   405,   247,   121,   130,   133,   132,   129,
     134,   131,   128,     0,   127,   123,   122,   180,   156,   330,
     352,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   792,   793,  1043,  1044,    25,   228,   229,
     230,   231,    26,   267,   268,   269,   270,   754,   755,   758,
     759,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    27,    71,    72,    73,
      74,    75,    28,   220,   221,   222,   223,   224,   963,   964,
     965,   966,   967,  1111,  1243,  1244,    29,    60,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   725,  1161,  1162,
     515,   721,  1136,  1137,    30,    49,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   596,  1028,  1029,    31,    57,   481,
     706,  1102,  1103,   482,   483,   484,  1108,   955,   956,   485,
     486,    32,    55,   457,   458,   459,   460,   461,   462,   463,
     692,  1087,  1088,   464,   465,   466,    33,    61,   520,   521,
     522,   523,   524,    34,   290,   291,   292,    35,    64,   557,
     558,   559,   560,   561,   768,  1180,  1181,    36,    65,   565,
     566,   567,   568,   774,  1194,  1195,    37,    50,   364,   365,
     366,   367,   368,   369,   370,   371,   372,   373,   616,  1054,
    1055,   374,   375,   376,   377,   378,    38,    56,   471,   701,
    1096,  1097,   472,   473,   474,   475,    39,    51,   382,   383,
     384,   385,    40,   112,   113,   114,    41,    53,   393,   635,
    1069,  1070,   394,   395,   396,   397,    42,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   428,   917,   918,   211,   426,   894,   895,
     212,   213,   214,    43,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
      44,   241,   242,   243,   244,   245,   246,   247,   248
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -820
static const yytype_int16 yypact[] =
{
    -820,   585,  -820,  -131,  -219,  -213,  -820,  -820,  -820,  -202,
    -820,  -195,  -820,  -820,  -820,  -178,  -151,  -820,  -820,  -149,
    -146,  -820,  -820,  -130,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,    31,   836,  -121,
    -118,  -109,    27,   -83,   358,   -77,   -68,   -62,    63,   206,
     -59,   -42,   495,   405,   -37,   -11,    18,  -185,  -155,   -98,
      -9,    30,  -820,  -820,  -820,  -820,  -820,    41,    43,    45,
      56,    60,    67,    78,    80,    83,    88,   104,   107,   112,
     129,   151,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,   629,   423,    59,
    -820,   133,    19,  -820,  -820,    11,  -820,   138,   141,   142,
     143,   147,   148,   150,   155,   157,   158,   160,   165,   169,
     170,   171,   172,   180,   184,   185,   186,   187,   189,   190,
     194,   195,   198,   200,   202,  -820,   207,  -820,   208,   210,
     211,   217,   223,   224,   226,   227,   228,   229,   231,   232,
     233,   236,   239,   240,   244,   125,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,   321,   176,   295,    14,   250,
      76,  -820,  -820,  -820,   105,    23,   251,   253,    25,  -820,
    -820,  -820,   471,    65,  -820,   257,   258,   259,   262,   267,
     272,     5,  -820,  -820,  -820,  -820,  -820,  -820,  -820,    39,
     273,   275,   279,   281,   283,   284,   286,   288,   289,   290,
     293,   299,   300,   305,   306,   308,   310,   175,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,     7,    17,  -820,   318,
      40,  -820,  -820,  -820,   254,   309,   428,   128,  -820,   297,
     447,   386,   449,   449,   450,   452,   455,   394,   396,   459,
     449,   400,   404,   349,  -820,   356,   354,   355,   359,  -820,
     362,   365,   368,   369,   370,   371,   373,   376,   380,   381,
     382,   384,     8,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
     361,   385,   387,   389,   390,  -820,   391,   392,   393,   395,
     402,   403,   407,   409,   313,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
     411,   413,    20,  -820,  -820,  -820,   489,   419,  -820,  -820,
     417,   424,  -820,  -820,    24,  -820,  -820,  -820,   463,   449,
     449,   521,   486,   488,   553,   537,   494,   449,   497,   449,
     557,   562,   563,   502,   504,   506,   449,   570,   571,   449,
     572,   575,   576,   577,   516,   517,   460,   520,   462,   449,
     449,   524,   529,   530,   531,   -45,   174,   532,   533,   449,
     449,   578,   449,   536,   538,   544,   490,  -820,   492,   496,
     499,  -820,   508,   513,   514,   518,   522,    33,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,   523,  -820,
     525,  -820,    37,  -820,  -820,  -820,   493,  -820,   526,   527,
     528,  -820,    15,  -820,  -820,  -820,  -820,  -820,   547,   498,
    -820,   539,  -820,   594,   597,   500,  -820,   534,   541,   545,
    -820,   546,   551,   555,  -820,   558,    16,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,   535,   559,   561,   564,
      81,  -820,  -820,  -820,  -820,   579,   580,   620,   589,   607,
     449,   565,  -820,  -820,   666,   624,   688,   695,   684,   685,
     687,   690,   692,   694,    64,   204,   708,   712,   698,   713,
     718,   625,  -820,   626,   617,  -820,   619,    44,  -820,  -820,
    -820,  -820,   628,   627,  -820,    52,  -820,  -820,  -820,   731,
     632,  -820,   634,   637,   639,  -820,   640,   642,   643,   584,
     652,   653,   654,   655,   656,   657,   659,   662,   663,   664,
     665,  -820,  -820,   784,   785,   449,   668,   786,   787,   790,
     791,   449,   449,   774,   793,   795,   449,   796,   796,   679,
    -820,  -820,   782,   162,   783,   740,   682,   792,   794,   797,
     798,   804,   799,   800,   801,   691,  -820,   802,   803,   693,
    -820,   696,  -820,   805,   806,   701,   707,  -820,   709,   710,
     711,   716,   717,   719,   720,   721,   722,   723,   724,   725,
     726,   729,   730,   732,   733,   734,   735,   736,   738,   739,
     741,   742,   743,   744,   746,   747,   586,   748,   622,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   758,   759,
     760,   761,   762,   763,   764,   765,   766,   767,  -820,  -820,
     808,   768,   715,   813,   849,   840,   868,   869,   770,  -820,
     871,   769,   873,   775,  -820,  -820,   771,   876,   877,   896,
     779,  -820,   780,  -820,    29,   781,   788,  -820,  -820,   882,
     839,   789,   884,   885,   886,   807,   887,   809,  -820,  -820,
     889,   890,   891,   811,  -820,   812,   814,   815,   816,   817,
     818,  -820,   819,   820,   821,   822,   823,   824,   825,   826,
     827,   828,  -820,  -820,  -187,  -820,  -820,  -820,  -186,  -820,
     829,   830,   831,   832,   833,  -820,  -820,   893,   810,   894,
     834,  -820,  -820,   895,   835,   837,  -820,   841,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,   449,   449,   449,   449,   449,
     449,   449,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,   842,   843,   844,   270,   845,
     846,   847,   848,   850,   851,   852,   853,   854,   855,     4,
     856,   857,  -820,   858,   859,   860,   861,   862,    -4,   863,
     864,   865,   866,   867,   870,   872,   874,  -820,   875,   878,
    -820,  -820,   879,   880,   892,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -179,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -159,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,   881,   883,
     548,   888,   897,   898,   899,   900,  -820,   901,   902,   903,
    -820,    -2,   904,   905,   920,   686,  -820,  -820,  -820,   906,
     907,  -820,   908,    97,  -820,  -820,  -820,  -820,  -820,  -820,
     909,   912,   446,   913,   914,   915,   650,   916,  -820,   917,
     918,   919,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
      64,  -820,   204,  -820,  -820,  -820,  -820,  -820,   921,   491,
     922,  -820,   923,   680,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -154,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
     796,   796,   796,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -139,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -133,
    -820,  -820,   586,  -820,   622,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,   -26,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,    -7,  -820,  -820,  -820,
    -820,  -820,    36,  -820,  -820,  -820,   924,   896,   925,  -820,
     935,   926,   -97,   927,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,    51,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,    54,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
      93,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,    99,  -820,  -820,   270,  -820,  -820,
    -820,  -820,    -4,  -820,   892,  -820,  -820,  -820,   548,  -820,
     902,  -820,    -2,  -820,  -820,  -820,   928,   315,   930,   931,
    -820,  -820,   446,  -820,   650,  -820,   491,  -820,   680,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,   101,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,   315,  -820
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -820,  -820,  -820,    82,  -300,  -819,  -607,  -820,  -820,   689,
    -820,  -820,  -820,  -820,   910,  -820,  -820,  -820,    21,  -820,
      22,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,   947,  -820,
    -820,  -820,  -820,  -820,   838,  -820,  -820,  -820,  -820,    57,
    -820,  -820,  -820,  -820,  -820,  -230,  -820,  -820,  -820,   519,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -201,
    -820,  -820,  -820,  -196,  -820,  -820,  -820,   772,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -170,  -820,  -820,  -820,
    -820,  -820,  -182,  -820,   609,  -820,  -820,  -820,   -46,  -820,
    -820,  -820,  -820,  -820,   605,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -137,  -820,  -820,  -820,  -820,  -820,  -820,   573,
    -820,  -820,  -820,  -820,  -820,   911,  -820,  -820,  -820,  -820,
     542,  -820,  -820,  -820,  -820,  -820,  -128,  -820,  -820,  -820,
     543,  -820,  -820,  -820,  -820,  -122,  -820,  -820,  -820,   745,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -107,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -103,  -820,   641,  -820,  -820,  -820,  -820,  -820,   773,
    -820,  -820,  -820,  -820,   999,  -820,  -820,  -820,  -820,  -820,
    -820,   -92,  -820,   776,  -820,  -820,  -820,  -820,   949,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,    42,  -820,  -820,  -820,    46,
    -820,  -820,  -820,  -820,  -820,  1024,  -820,  -820,  -820,  -820,
    -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,  -820,
    -820,  -820,   932,  -820,  -820,  -820,  -820,  -820,  -820
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     820,   821,   580,   581,  1052,    47,   234,   819,   553,   315,
     588,    48,   389,  1040,  1041,  1042,   476,   497,   562,   288,
     110,   379,    52,   316,   317,   389,   225,   318,   110,    54,
     959,    67,    67,   498,   448,   999,  1001,   293,   467,  1000,
    1002,   288,   235,  1071,   319,   553,    58,  1072,   499,  1099,
     449,   477,   500,   562,    68,    68,   236,   237,   238,   239,
     379,    69,    69,  1073,   218,   450,   516,  1074,  1196,   451,
     294,   478,  1197,    59,   240,    62,   479,   218,    63,   517,
     111,   380,   516,  1201,   320,   321,   322,  1202,   111,  1203,
     323,    45,    46,  1204,    66,   517,   324,   325,   959,   639,
     640,   554,   326,   107,  1218,   390,   108,   647,   819,   649,
     501,   563,   289,   327,   328,   109,   656,   226,   390,   659,
     380,   675,   676,   960,    70,    70,   116,   295,   329,   669,
     670,   117,   118,   502,   289,   391,   480,   119,   554,   681,
     682,   115,   684,   227,   381,   120,   563,   215,   391,   503,
     452,   121,    76,   122,   123,   124,   216,   330,   453,   454,
     125,   468,   217,   518,   555,   232,   126,   127,   392,   128,
     129,   130,    77,    78,   564,   131,   249,   467,    79,   518,
     132,   392,   233,   381,   133,   134,   961,   286,   135,   519,
    1100,   960,   455,  1053,   469,  1101,  1207,   136,   331,   250,
    1208,   555,   752,   753,   137,   519,   138,   225,   139,   564,
     140,   141,   142,   287,   504,  1209,   296,    80,    81,  1210,
     556,  1198,  1199,  1200,    82,    83,    84,   143,   531,   505,
     740,   609,   251,   144,   145,   146,   487,   147,   710,   727,
     148,   149,   387,   629,   150,   492,   456,   636,   495,   962,
     470,    85,    86,   297,   961,   252,   698,   556,  1211,   253,
     703,   533,  1212,   570,    87,    88,   299,   770,   300,   254,
     301,   255,   256,  1221,    89,   775,  1223,  1222,   219,   151,
    1224,   302,    90,   152,  -113,   303,   153,   154,   155,   156,
     157,   219,   304,   158,   159,   807,   476,  -113,   226,   489,
     468,   813,   814,   305,   733,   306,   818,   257,   307,   258,
     259,   260,   261,   308,   350,  1225,   351,   962,   352,  1226,
    1113,  1227,   448,  1251,   227,  1228,   491,  1252,   262,   309,
     353,   477,   310,   469,   160,   161,   162,   311,   449,   163,
     677,   678,   756,   757,   164,   354,   824,   825,   446,   355,
     575,   478,   263,   450,   312,  1236,   479,   451,   386,   116,
    1026,  1027,   264,   398,   117,   118,   399,   400,   401,   356,
     119,   357,   402,   403,   313,   404,   572,  1237,   120,  1238,
     405,   358,   406,   407,   121,   408,   122,   123,   124,   470,
     409,   265,   266,   125,   410,   411,   412,   413,   551,   126,
     127,   576,   128,   129,   130,   414,   249,   359,   131,   415,
     416,   417,   418,   132,   419,   420,   480,   133,   134,   421,
     422,   135,  1239,   423,   350,   424,   351,   425,   352,   250,
     136,   573,   427,   429,   360,   430,   431,   137,   452,   138,
     353,   139,   432,   140,   141,   142,   453,   454,   433,   434,
    1117,   435,   436,   437,   438,   354,   439,   440,   441,   355,
     143,   442,   251,   361,   443,   444,   144,   145,   146,   445,
     147,  1118,   497,   148,   149,   488,   493,   150,   494,   356,
     455,   357,   525,   526,   527,   252,  1119,   528,   498,   253,
     362,   358,   529,  1120,  1240,  1241,   234,   530,   534,   254,
     535,   255,   256,   499,   536,  1219,   537,   500,   538,   539,
    1121,   540,   151,   541,   542,   543,   152,   359,   544,   153,
     154,   155,   156,   157,   545,   546,   158,   159,  1242,   363,
     547,   548,   235,   549,   456,   550,   625,   257,  1122,   258,
     259,   260,   261,   569,   360,  1123,   236,   237,   238,   239,
     574,   577,   578,   579,   582,  1170,   583,  1124,   262,   584,
     585,  1077,   586,   587,   240,   501,   589,   160,   161,   162,
     590,   591,   163,   361,  1125,  1126,  1127,   164,   592,   593,
     594,  1078,   263,   611,   595,     2,     3,   597,   502,     4,
     598,  1079,   264,   599,   600,   601,   602,  1080,   603,     5,
     362,   604,     6,     7,   503,   605,   606,   607,     8,   608,
     612,   631,   613,  1081,   614,   615,   617,   618,   619,     9,
     620,   265,   266,    10,    11,   641,  1128,   621,   622,   638,
     315,  1171,   623,    12,   624,  1129,   627,   874,   628,   363,
    1130,   632,   633,  1082,   316,   317,  1131,    13,   318,   634,
    1132,  1083,   642,  1133,   643,    14,    15,   644,  1134,   645,
     646,   650,  1172,   648,  1135,   319,   651,   652,   653,   504,
     654,  1173,   655,   897,   657,   658,   660,  1174,    16,   661,
     662,   663,   664,   665,   505,   666,   667,   668,   579,  1084,
     671,  1175,    17,  1176,  1177,   672,   673,   674,   679,   680,
     683,  1141,   685,  1178,   686,   320,   321,   322,  1085,  1179,
     687,   323,   688,   712,   689,   705,   715,   324,   325,   716,
     713,   690,   717,   326,   691,    18,   785,   786,   787,   788,
     789,   790,   791,   693,   327,   328,    19,    20,   694,   695,
      21,    22,   737,   696,  1184,   735,   736,   697,   700,   329,
     702,   707,   708,   709,  1086,   738,   718,   729,   875,   876,
     877,   878,   879,   714,   880,   881,   719,   882,   883,   884,
     720,   722,   885,   739,   886,   887,   723,   888,   330,   889,
     724,   890,   891,   726,   730,   892,   731,   741,   742,   732,
     743,   893,   744,    23,   898,   899,   900,   901,   902,   745,
     903,   904,   762,   905,   906,   907,   746,   747,   908,   748,
     909,   910,   749,   911,   750,   912,   751,   913,   914,   331,
    1185,   915,  1142,  1143,  1144,  1145,  1146,   916,  1147,  1148,
     760,  1149,  1150,  1151,   761,   763,  1152,    76,  1153,  1154,
     764,  1155,   767,  1156,   769,  1157,  1158,   765,   766,  1159,
     772,  1186,   773,   777,   778,  1160,   779,    77,    78,   780,
    1187,   781,   782,    79,   783,   784,  1188,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,   794,   795,   796,   797,   798,   799,
    1189,   800,  1190,  1191,   801,   802,   803,   804,   805,   806,
     809,   810,  1192,   808,   811,   812,   815,   816,  1193,   817,
     819,   822,    80,    81,   823,   826,   827,   828,   833,    82,
      83,    84,  1107,   837,   829,   840,   830,   496,   841,   831,
     832,   834,   835,   836,   838,   839,   844,   842,   843,   845,
     938,   846,   847,   848,   939,   941,    85,    86,   849,   850,
     940,   851,   852,   853,   854,   855,   856,   857,   858,    87,
      88,   859,   860,   942,   861,   862,   863,   864,   865,    89,
     866,   867,   943,   868,   869,   870,   871,    90,   872,   873,
     896,   919,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   929,   930,   931,   932,   933,   934,   935,   936,   937,
     944,   945,   946,   947,   948,   949,   951,   950,   952,   953,
     954,   957,   958,   968,   970,   971,   973,   974,   975,   977,
     969,   979,   980,   981,   972,  1008,  1010,  1012,   298,  1068,
    1114,  1167,  1253,  1248,  1168,   728,  1247,  1229,  1213,  1095,
    1234,   978,   976,   982,   983,  1009,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,  1003,  1004,  1005,  1006,  1007,  1011,  1216,   490,  1014,
    1013,  1214,   699,  1015,  1023,  1024,  1025,  1030,  1031,  1032,
    1033,  1232,  1034,  1035,  1036,  1037,  1038,  1039,  1045,  1046,
    1047,  1048,  1049,  1050,  1051,  1056,  1057,  1058,  1059,  1060,
    1106,   711,  1061,   734,  1062,  1230,  1063,  1064,  1249,   771,
    1065,  1066,  1067,  1075,   610,  1076,  1250,  1233,   776,   626,
    1089,   388,  1231,   704,   447,   314,  1206,     0,  1205,  1090,
    1091,  1092,  1093,  1094,     0,  1098,  1104,  1105,  1109,     0,
       0,  1115,  1110,  1112,  1116,  1138,  1139,  1140,  1163,  1164,
    1165,  1166,     0,  1169,  1182,  1183,     0,  1215,     0,  1220,
    1235,  1217,  1245,  1246,     0,   630,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     637,     0,     0,   532,     0,     0,     0,   552,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-820)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     607,   608,   302,   303,     8,   224,     1,   104,     1,     1,
     310,   224,     1,     9,    10,    11,     1,     1,     1,     1,
       1,     1,   224,    15,    16,     1,     1,    19,     1,   224,
       1,     1,     1,    17,     1,   222,   222,   222,     1,   226,
     226,     1,    37,   222,    36,     1,   224,   226,    32,    51,
      17,    36,    36,     1,    24,    24,    51,    52,    53,    54,
       1,    31,    31,   222,     1,    32,     1,   226,   222,    36,
     225,    56,   226,   224,    69,   224,    61,     1,   224,    14,
      61,    61,     1,   222,    76,    77,    78,   226,    61,   222,
      82,   222,   223,   226,   224,    14,    88,    89,     1,   399,
     400,    94,    94,   224,   201,    94,   224,   407,   104,   409,
      94,    94,    94,   105,   106,   224,   416,    92,    94,   419,
      61,   166,   167,    94,    94,    94,     1,   225,   120,   429,
     430,     6,     7,   117,    94,   124,   121,    12,    94,   439,
     440,   224,   442,   118,   124,    20,    94,   224,   124,   133,
     117,    26,     1,    28,    29,    30,   224,   149,   125,   126,
      35,   124,   224,    98,   157,   224,    41,    42,   157,    44,
      45,    46,    21,    22,   157,    50,     1,     1,    27,    98,
      55,   157,   224,   124,    59,    60,   157,   224,    63,   124,
     192,    94,   159,   197,   157,   197,   222,    72,   190,    24,
     226,   157,   138,   139,    79,   124,    81,     1,    83,   157,
      85,    86,    87,   224,   198,   222,   225,    66,    67,   226,
     213,  1040,  1041,  1042,    73,    74,    75,   102,   223,   213,
     530,   223,    57,   108,   109,   110,   222,   112,   223,   223,
     115,   116,   223,   223,   119,   222,   213,   223,   223,   220,
     213,   100,   101,   223,   157,    80,   223,   213,   222,    84,
     223,   222,   226,   223,   113,   114,   225,   223,   225,    94,
     225,    96,    97,   222,   123,   223,   222,   226,   215,   154,
     226,   225,   131,   158,   221,   225,   161,   162,   163,   164,
     165,   215,   225,   168,   169,   595,     1,   221,    92,   223,
     124,   601,   602,   225,   223,   225,   606,   132,   225,   134,
     135,   136,   137,   225,     1,   222,     3,   220,     5,   226,
     223,   222,     1,   222,   118,   226,   221,   226,   153,   225,
      17,    36,   225,   157,   209,   210,   211,   225,    17,   214,
     166,   167,   138,   139,   219,    32,   184,   185,   223,    36,
     222,    56,   177,    32,   225,    40,    61,    36,   225,     1,
      90,    91,   187,   225,     6,     7,   225,   225,   225,    56,
      12,    58,   225,   225,   223,   225,   122,    62,    20,    64,
     225,    68,   225,   225,    26,   225,    28,    29,    30,   213,
     225,   216,   217,    35,   225,   225,   225,   225,   223,    41,
      42,   104,    44,    45,    46,   225,     1,    94,    50,   225,
     225,   225,   225,    55,   225,   225,   121,    59,    60,   225,
     225,    63,   107,   225,     1,   225,     3,   225,     5,    24,
      72,   122,   225,   225,   121,   225,   225,    79,   117,    81,
      17,    83,   225,    85,    86,    87,   125,   126,   225,   225,
       4,   225,   225,   225,   225,    32,   225,   225,   225,    36,
     102,   225,    57,   150,   225,   225,   108,   109,   110,   225,
     112,    25,     1,   115,   116,   225,   225,   119,   225,    56,
     159,    58,   225,   225,   225,    80,    40,   225,    17,    84,
     177,    68,   225,    47,   179,   180,     1,   225,   225,    94,
     225,    96,    97,    32,   225,  1112,   225,    36,   225,   225,
      64,   225,   154,   225,   225,   225,   158,    94,   225,   161,
     162,   163,   164,   165,   225,   225,   168,   169,   213,   216,
     225,   225,    37,   225,   213,   225,   223,   132,    92,   134,
     135,   136,   137,   225,   121,    99,    51,    52,    53,    54,
     122,   104,   166,   104,   104,    64,   104,   111,   153,   104,
     166,    13,   166,   104,    69,    94,   166,   209,   210,   211,
     166,   222,   214,   150,   128,   129,   130,   219,   222,   225,
     225,    33,   177,   222,   225,     0,     1,   225,   117,     4,
     225,    43,   187,   225,   225,   225,   225,    49,   225,    14,
     177,   225,    17,    18,   133,   225,   225,   225,    23,   225,
     225,   122,   225,    65,   225,   225,   225,   225,   225,    34,
     225,   216,   217,    38,    39,   104,   180,   225,   225,   166,
       1,   140,   225,    48,   225,   189,   225,    51,   225,   216,
     194,   222,   225,    95,    15,    16,   200,    62,    19,   225,
     204,   103,   166,   207,   166,    70,    71,   104,   212,   122,
     166,   104,   171,   166,   218,    36,   104,   104,   166,   198,
     166,   180,   166,    51,   104,   104,   104,   186,    93,   104,
     104,   104,   166,   166,   213,   225,   166,   225,   104,   141,
     166,   200,   107,   202,   203,   166,   166,   166,   166,   166,
     122,    51,   166,   212,   166,    76,    77,    78,   160,   218,
     166,    82,   222,   166,   222,   222,   122,    88,    89,   122,
     222,   225,   222,    94,   225,   140,   142,   143,   144,   145,
     146,   147,   148,   225,   105,   106,   151,   152,   225,   225,
     155,   156,   122,   225,    64,   166,   166,   225,   225,   120,
     225,   225,   225,   225,   206,   166,   222,   222,   172,   173,
     174,   175,   176,   224,   178,   179,   225,   181,   182,   183,
     225,   225,   186,   166,   188,   189,   225,   191,   149,   193,
     225,   195,   196,   225,   225,   199,   225,   222,   122,   225,
     166,   205,   104,   208,   172,   173,   174,   175,   176,   104,
     178,   179,   104,   181,   182,   183,   122,   122,   186,   122,
     188,   189,   122,   191,   122,   193,   122,   195,   196,   190,
     140,   199,   172,   173,   174,   175,   176,   205,   178,   179,
     122,   181,   182,   183,   122,   122,   186,     1,   188,   189,
     122,   191,   225,   193,   225,   195,   196,   222,   222,   199,
     222,   171,   225,   122,   222,   205,   222,    21,    22,   222,
     180,   222,   222,    27,   222,   222,   186,   785,   786,   787,
     788,   789,   790,   791,   222,   222,   222,   222,   222,   222,
     200,   222,   202,   203,   222,   222,   222,   222,   104,   104,
     104,   104,   212,   225,   104,   104,   122,   104,   218,   104,
     104,   222,    66,    67,   122,   122,   166,   225,   104,    73,
      74,    75,   226,   222,   122,   222,   122,   228,   222,   122,
     122,   122,   122,   122,   122,   122,   225,   122,   122,   222,
     122,   222,   222,   222,   166,   122,   100,   101,   222,   222,
     225,   222,   222,   222,   222,   222,   222,   222,   222,   113,
     114,   222,   222,   104,   222,   222,   222,   222,   222,   123,
     222,   222,   122,   222,   222,   222,   222,   131,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     122,   122,   222,   122,   225,   122,   225,   222,   122,   122,
     104,   222,   222,   222,   122,   166,   122,   122,   122,   122,
     222,   122,   122,   122,   225,   122,   122,   122,    71,   127,
     963,  1000,  1252,  1224,  1002,   506,  1222,  1197,   104,   127,
    1212,   222,   225,   222,   222,   225,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   122,   220,   222,
     225,  1107,   457,   222,   222,   222,   222,   222,   222,   222,
     222,  1208,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     170,   482,   222,   520,   222,  1202,   222,   222,  1226,   557,
     222,   222,   222,   222,   332,   222,  1228,  1210,   565,   364,
     222,   112,  1204,   472,   165,    91,  1074,    -1,  1072,   222,
     222,   222,   222,   222,    -1,   222,   222,   222,   222,    -1,
      -1,   222,   225,   225,   222,   222,   222,   222,   222,   222,
     222,   222,    -1,   222,   222,   222,    -1,   222,    -1,   222,
     222,   225,   222,   222,    -1,   382,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     394,    -1,    -1,   241,    -1,    -1,    -1,   267,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   290
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   228,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    93,   107,   140,   151,
     152,   155,   156,   208,   229,   234,   239,   263,   269,   283,
     301,   324,   338,   353,   360,   364,   374,   383,   403,   413,
     419,   423,   433,   490,   507,   222,   223,   224,   224,   302,
     384,   414,   224,   424,   224,   339,   404,   325,   224,   224,
     284,   354,   224,   224,   365,   375,   224,     1,    24,    31,
      94,   264,   265,   266,   267,   268,     1,    21,    22,    27,
      66,    67,    73,    74,    75,   100,   101,   113,   114,   123,
     131,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   224,   224,   224,
       1,    61,   420,   421,   422,   224,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    81,    83,
      85,    86,    87,   102,   108,   109,   110,   112,   115,   116,
     119,   154,   158,   161,   162,   163,   164,   165,   168,   169,
     209,   210,   211,   214,   219,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   483,   487,   488,   489,   224,   224,   224,     1,   215,
     270,   271,   272,   273,   274,     1,    92,   118,   235,   236,
     237,   238,   224,   224,     1,    37,    51,    52,    53,    54,
      69,   508,   509,   510,   511,   512,   513,   514,   515,     1,
      24,    57,    80,    84,    94,    96,    97,   132,   134,   135,
     136,   137,   153,   177,   187,   216,   217,   240,   241,   242,
     243,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   224,   224,     1,    94,
     361,   362,   363,   222,   225,   225,   225,   223,   265,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   223,   492,     1,    15,    16,    19,    36,
      76,    77,    78,    82,    88,    89,    94,   105,   106,   120,
     149,   190,   303,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
       1,     3,     5,    17,    32,    36,    56,    58,    68,    94,
     121,   150,   177,   216,   385,   386,   387,   388,   389,   390,
     391,   392,   393,   394,   398,   399,   400,   401,   402,     1,
      61,   124,   415,   416,   417,   418,   225,   223,   421,     1,
      94,   124,   157,   425,   429,   430,   431,   432,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   484,   225,   480,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   223,   435,     1,    17,
      32,    36,   117,   125,   126,   159,   213,   340,   341,   342,
     343,   344,   345,   346,   350,   351,   352,     1,   124,   157,
     213,   405,   409,   410,   411,   412,     1,    36,    56,    61,
     121,   326,   330,   331,   332,   336,   337,   222,   225,   223,
     271,   221,   222,   225,   225,   223,   236,     1,    17,    32,
      36,    94,   117,   133,   198,   213,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   297,     1,    14,    98,   124,
     355,   356,   357,   358,   359,   225,   225,   225,   225,   225,
     225,   223,   509,   222,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   223,   241,     1,    94,   157,   213,   366,   367,   368,
     369,   370,     1,    94,   157,   376,   377,   378,   379,   225,
     223,   362,   122,   122,   122,   222,   104,   104,   166,   104,
     231,   231,   104,   104,   104,   166,   166,   104,   231,   166,
     166,   222,   222,   225,   225,   225,   321,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   223,
     304,   222,   225,   225,   225,   225,   395,   225,   225,   225,
     225,   225,   225,   225,   225,   223,   386,   225,   225,   223,
     416,   122,   222,   225,   225,   426,   223,   430,   166,   231,
     231,   104,   166,   166,   104,   122,   166,   231,   166,   231,
     104,   104,   104,   166,   166,   166,   231,   104,   104,   231,
     104,   104,   104,   104,   166,   166,   225,   166,   225,   231,
     231,   166,   166,   166,   166,   166,   167,   166,   167,   166,
     166,   231,   231,   122,   231,   166,   166,   166,   222,   222,
     225,   225,   347,   225,   225,   225,   225,   225,   223,   341,
     225,   406,   225,   223,   410,   222,   327,   225,   225,   225,
     223,   331,   166,   222,   224,   122,   122,   222,   222,   225,
     225,   298,   225,   225,   225,   294,   225,   223,   286,   222,
     225,   225,   225,   223,   356,   166,   166,   122,   166,   166,
     231,   222,   122,   166,   104,   104,   122,   122,   122,   122,
     122,   122,   138,   139,   244,   245,   138,   139,   246,   247,
     122,   122,   104,   122,   122,   222,   222,   225,   371,   225,
     223,   367,   222,   225,   380,   223,   377,   122,   222,   222,
     222,   222,   222,   222,   222,   142,   143,   144,   145,   146,
     147,   148,   230,   231,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   104,   104,   231,   225,   104,
     104,   104,   104,   231,   231,   122,   104,   104,   231,   104,
     233,   233,   222,   122,   184,   185,   122,   166,   225,   122,
     122,   122,   122,   104,   122,   122,   122,   222,   122,   122,
     222,   222,   122,   122,   225,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,    51,   172,   173,   174,   175,   176,
     178,   179,   181,   182,   183,   186,   188,   189,   191,   193,
     195,   196,   199,   205,   485,   486,   222,    51,   172,   173,
     174,   175,   176,   178,   179,   181,   182,   183,   186,   188,
     189,   191,   193,   195,   196,   199,   205,   481,   482,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   122,   166,
     225,   122,   104,   122,   122,   122,   222,   122,   225,   122,
     222,   225,   122,   122,   104,   334,   335,   222,   222,     1,
      94,   157,   220,   275,   276,   277,   278,   279,   222,   222,
     122,   166,   225,   122,   122,   122,   225,   122,   222,   122,
     122,   122,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     226,   222,   226,   222,   222,   222,   222,   222,   122,   225,
     122,   222,   122,   225,   222,   222,   230,   230,   230,   230,
     230,   230,   230,   222,   222,   222,    90,    91,   322,   323,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
       9,    10,    11,   232,   233,   222,   222,   222,   222,   222,
     222,   222,     8,   197,   396,   397,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   127,   427,
     428,   222,   226,   222,   226,   222,   222,    13,    33,    43,
      49,    65,    95,   103,   141,   160,   206,   348,   349,   222,
     222,   222,   222,   222,   222,   127,   407,   408,   222,    51,
     192,   197,   328,   329,   222,   222,   170,   226,   333,   222,
     225,   280,   225,   223,   276,   222,   222,     4,    25,    40,
      47,    64,    92,    99,   111,   128,   129,   130,   180,   189,
     194,   200,   204,   207,   212,   218,   299,   300,   222,   222,
     222,    51,   172,   173,   174,   175,   176,   178,   179,   181,
     182,   183,   186,   188,   189,   191,   193,   195,   196,   199,
     205,   295,   296,   222,   222,   222,   222,   245,   247,   222,
      64,   140,   171,   180,   186,   200,   202,   203,   212,   218,
     372,   373,   222,   222,    64,   140,   171,   180,   186,   200,
     202,   203,   212,   218,   381,   382,   222,   226,   232,   232,
     232,   222,   226,   222,   226,   486,   482,   222,   226,   222,
     226,   222,   226,   104,   335,   222,   122,   225,   201,   233,
     222,   222,   226,   222,   226,   222,   226,   222,   226,   323,
     397,   428,   349,   408,   329,   222,    40,    62,    64,   107,
     179,   180,   213,   281,   282,   222,   222,   300,   296,   373,
     382,   222,   226,   282
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 26:
/* Line 1787 of yacc.c  */
#line 392 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 394 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 398 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 402 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 406 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 414 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 418 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 422 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 427 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 428 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 431 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 477 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 483 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 492 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 498 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 506 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not open/read certificate file");
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      report_crypto_errors();
      conf_error_report("Could not read RSA private key");
      break;
    }
  }
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 548 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 1)
  {
    BIO *file;

    if (ServerInfo.rsa_private_key)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;
    }

    if (ServerInfo.rsa_private_key_file)
    {
      MyFree(ServerInfo.rsa_private_key_file);
      ServerInfo.rsa_private_key_file = NULL;
    }

    ServerInfo.rsa_private_key_file = xstrdup(yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      conf_error_report("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      conf_error_report("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 607 "conf_parser.y"
    {
/* TBD - XXX: error reporting */
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
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
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 635 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 643 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ServerInfo.name = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 658 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ServerInfo.sid = xstrdup(yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 673 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 88:
/* Line 1787 of yacc.c  */
#line 682 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    ServerInfo.network_desc = xstrdup(yylval.string);
  }
}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 705 "conf_parser.y"
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
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 733 "conf_parser.y"
    {
#ifdef IPV6
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
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 763 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    conf_error_report(buf);
    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
}
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < 9)
  {
    conf_error_report("max_nick_length too low, setting to 9");
    ServerInfo.max_nick_length = 9;
  }
  else if ((yyvsp[(3) - (4)].number) > NICKLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
    conf_error_report(buf);
    ServerInfo.max_nick_length = NICKLEN;
  }
  else
    ServerInfo.max_nick_length = (yyvsp[(3) - (4)].number);
}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < 80)
  {
    conf_error_report("max_topic_length too low, setting to 80");
    ServerInfo.max_topic_length = 80;
  }
  else if ((yyvsp[(3) - (4)].number) > TOPICLEN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
    conf_error_report(buf);
    ServerInfo.max_topic_length = TOPICLEN;
  }
  else
    ServerInfo.max_topic_length = (yyvsp[(3) - (4)].number);
}
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 832 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 847 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    AdminInfo.name = xstrdup(yylval.string);
  }
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 856 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    AdminInfo.email = xstrdup(yylval.string);
  }
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    AdminInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 889 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 917 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 920 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 966 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 973 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!(block_state.file.buf[0] ||
        block_state.rpass.buf[0]))
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_OPER);
    conf->name  = xstrdup(block_state.name.buf);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

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
        conf_error_report("Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        conf_error_report("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");

      conf->rsa_public_key = pkey;
      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1048 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1054 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1060 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1066 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1077 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1089 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1100 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1104 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1108 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1112 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1116 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1120 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1132 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1140 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_N;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1267 "conf_parser.y"
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
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1279 "conf_parser.y"
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

  if (block_state.min_idle.value > block_state.max_idle.value)
  {
    block_state.min_idle.value = 0;
    block_state.max_idle.value = 0;
    block_state.flags.value &= ~CLASS_FLAGS_FAKE_IDLE;
  }

  class->flags = block_state.flags.value;
  class->min_idle = block_state.min_idle.value;
  class->max_idle = block_state.max_idle.value;

  if (class->number_per_cidr && block_state.number_per_cidr.value)
    if ((class->cidr_bitlen_ipv4 && block_state.cidr_bitlen_ipv4.value) ||
        (class->cidr_bitlen_ipv6 && block_state.cidr_bitlen_ipv6.value))
      if ((class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value) ||
          (class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value))
        rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1345 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1351 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1357 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1375 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1387 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1393 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1399 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1463 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1475 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1479 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1483 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1491 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1496 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1510 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1530 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1536 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1545 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1549 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(collapse(block_state.user.buf));
    conf->host  = xstrdup(collapse(block_state.host.buf));

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->passwd = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1592 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1598 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1604 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1610 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1621 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1628 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1632 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1636 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1640 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1644 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1648 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1660 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1664 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1670 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1684 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1706 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1713 "conf_parser.y"
    {
  if (IsChanPrefix(block_state.name.buf[0]))
    create_channel_resv(block_state.name.buf, block_state.rpass.buf);
  else if (block_state.name.buf[0])
    create_nick_resv(block_state.name.buf, block_state.rpass.buf);
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1730 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1736 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1750 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      struct MaskItem *conf = conf_make(CONF_SERVICE);
      conf->name = xstrdup(yylval.string);
    }
  }
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1765 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->user = xstrdup(block_state.host.buf);
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1793 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1799 "conf_parser.y"
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
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 1825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1833 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 1837 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1841 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1845 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1849 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1870 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1879 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 1894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 1900 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 1943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 1952 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1960 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!(block_state.rpass.buf[0] ||
        block_state.spass.buf[0]))
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
      assert(res != NULL);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2026 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2032 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2038 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2044 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2057 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    conf_error_report("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    conf_error_report("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 2070 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 2076 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2080 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 2088 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 2094 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 2098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 2104 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 2115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2133 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2152 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;


  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_user = NULL;
    void *exp_host = NULL;
    const char *errptr = NULL;
 
    if (!(exp_user = ircd_pcre_compile(block_state.user.buf, &errptr)) ||
        !(exp_host = ircd_pcre_compile(block_state.host.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RKLINE);
    conf->regexuser = exp_user;
    conf->regexhost = exp_host;

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
#else
    ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
    break;
#endif
  }
  else
  {
    conf = conf_make(CONF_KLINE);

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_KLINE, conf);
  }
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 2217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2226 "conf_parser.y"
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
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2259 "conf_parser.y"
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
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2285 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 2291 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2305 "conf_parser.y"
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
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2322 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2326 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_p = NULL;
    const char *errptr = NULL;

    if (!(exp_p = ircd_pcre_compile(block_state.name.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RXLINE);
    conf->regexuser = exp_p;
#else
    conf_error_report("Failed to add regular expression based X-Line: no PCRE support");
    break;
#endif
  }
  else
    conf = conf_make(CONF_XLINE);

  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 2367 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 2374 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 444:
/* Line 1787 of yacc.c  */
#line 2383 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2389 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2433 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2444 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2450 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2456 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2461 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2466 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2471 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2476 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2481 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2486 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2491 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2496 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2501 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2506 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2511 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2516 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2521 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2526 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2532 "conf_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(LOG_TYPE_IRCD, "You haven't read your config file properly.");
    ilog(LOG_TYPE_IRCD, "There is a line in the example conf that will kill your server if not removed.");
    ilog(LOG_TYPE_IRCD, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2543 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2548 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2553 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2558 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2563 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2568 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2571 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2576 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2579 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2584 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2657 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2667 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2672 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2681 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2684 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2687 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2702 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2708 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2711 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2723 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2749 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2752 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2758 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2761 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2764 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2773 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2776 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2779 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2782 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2785 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2794 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2797 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2803 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2808 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2818 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 2851 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 636:
/* Line 1787 of yacc.c  */
#line 2924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 2930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 638:
/* Line 1787 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 639:
/* Line 1787 of yacc.c  */
#line 2945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (((yyvsp[(3) - (4)].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[(3) - (4)].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 640:
/* Line 1787 of yacc.c  */
#line 2959 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 2965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6777 "conf_parser.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


