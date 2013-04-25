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
     HIDE_SERVICES = 310,
     HIDE_SPOOF_IPS = 311,
     HOST = 312,
     HUB = 313,
     HUB_MASK = 314,
     IGNORE_BOGUS_TS = 315,
     INVISIBLE_ON_CONNECT = 316,
     IP = 317,
     KILL = 318,
     KILL_CHASE_TIME_LIMIT = 319,
     KLINE = 320,
     KLINE_EXEMPT = 321,
     KNOCK_DELAY = 322,
     KNOCK_DELAY_CHANNEL = 323,
     LEAF_MASK = 324,
     LINKS_DELAY = 325,
     LISTEN = 326,
     T_LOG = 327,
     MASK = 328,
     MAX_ACCEPT = 329,
     MAX_BANS = 330,
     MAX_CHANS_PER_OPER = 331,
     MAX_CHANS_PER_USER = 332,
     MAX_GLOBAL = 333,
     MAX_IDENT = 334,
     MAX_LOCAL = 335,
     MAX_NICK_CHANGES = 336,
     MAX_NICK_LENGTH = 337,
     MAX_NICK_TIME = 338,
     MAX_NUMBER = 339,
     MAX_TARGETS = 340,
     MAX_TOPIC_LENGTH = 341,
     MAX_WATCH = 342,
     MIN_NONWILDCARD = 343,
     MIN_NONWILDCARD_SIMPLE = 344,
     MIN_IDLE = 345,
     MAX_IDLE = 346,
     RANDOM_IDLE = 347,
     HIDE_IDLE_FROM_OPERS = 348,
     MODULE = 349,
     MODULES = 350,
     NAME = 351,
     NEED_PASSWORD = 352,
     NETWORK_DESC = 353,
     NETWORK_NAME = 354,
     NICK = 355,
     NICK_CHANGES = 356,
     NO_CREATE_ON_SPLIT = 357,
     NO_JOIN_ON_SPLIT = 358,
     NO_OPER_FLOOD = 359,
     NO_TILDE = 360,
     NUMBER = 361,
     NUMBER_PER_CIDR = 362,
     NUMBER_PER_IP = 363,
     OPERATOR = 364,
     OPERS_BYPASS_CALLERID = 365,
     OPER_ONLY_UMODES = 366,
     OPER_PASS_RESV = 367,
     OPER_SPY_T = 368,
     OPER_UMODES = 369,
     JOIN_FLOOD_COUNT = 370,
     JOIN_FLOOD_TIME = 371,
     PACE_WAIT = 372,
     PACE_WAIT_SIMPLE = 373,
     PASSWORD = 374,
     PATH = 375,
     PING_COOKIE = 376,
     PING_TIME = 377,
     PORT = 378,
     QSTRING = 379,
     QUIET_ON_BAN = 380,
     REASON = 381,
     REDIRPORT = 382,
     REDIRSERV = 383,
     REGEX_T = 384,
     REHASH = 385,
     REMOTE = 386,
     REMOTEBAN = 387,
     RSA_PRIVATE_KEY_FILE = 388,
     RSA_PUBLIC_KEY_FILE = 389,
     SSL_CERTIFICATE_FILE = 390,
     SSL_DH_PARAM_FILE = 391,
     T_SSL_CLIENT_METHOD = 392,
     T_SSL_SERVER_METHOD = 393,
     T_SSLV3 = 394,
     T_TLSV1 = 395,
     RESV = 396,
     RESV_EXEMPT = 397,
     SECONDS = 398,
     MINUTES = 399,
     HOURS = 400,
     DAYS = 401,
     WEEKS = 402,
     MONTHS = 403,
     YEARS = 404,
     SENDQ = 405,
     SEND_PASSWORD = 406,
     SERVERHIDE = 407,
     SERVERINFO = 408,
     IRCD_SID = 409,
     TKLINE_EXPIRE_NOTICES = 410,
     T_SHARED = 411,
     T_CLUSTER = 412,
     TYPE = 413,
     SHORT_MOTD = 414,
     SPOOF = 415,
     SPOOF_NOTICE = 416,
     STATS_E_DISABLED = 417,
     STATS_I_OPER_ONLY = 418,
     STATS_K_OPER_ONLY = 419,
     STATS_O_OPER_ONLY = 420,
     STATS_P_OPER_ONLY = 421,
     TBOOL = 422,
     TMASKED = 423,
     TS_MAX_DELTA = 424,
     TS_WARN_DELTA = 425,
     TWODOTS = 426,
     T_ALL = 427,
     T_BOTS = 428,
     T_SOFTCALLERID = 429,
     T_CALLERID = 430,
     T_CCONN = 431,
     T_CCONN_FULL = 432,
     T_SSL_CIPHER_LIST = 433,
     T_DEAF = 434,
     T_DEBUG = 435,
     T_DLINE = 436,
     T_EXTERNAL = 437,
     T_FULL = 438,
     T_INVISIBLE = 439,
     T_IPV4 = 440,
     T_IPV6 = 441,
     T_LOCOPS = 442,
     T_MAX_CLIENTS = 443,
     T_NCHANGE = 444,
     T_NONONREG = 445,
     T_OPERWALL = 446,
     T_RECVQ = 447,
     T_REJ = 448,
     T_SERVER = 449,
     T_SERVNOTICE = 450,
     T_SET = 451,
     T_SKILL = 452,
     T_SPY = 453,
     T_SSL = 454,
     T_UMODES = 455,
     T_UNAUTH = 456,
     T_UNDLINE = 457,
     T_UNLIMITED = 458,
     T_UNRESV = 459,
     T_UNXLINE = 460,
     T_GLOBOPS = 461,
     T_WALLOP = 462,
     T_WEBIRC = 463,
     T_RESTART = 464,
     T_SERVICE = 465,
     T_SERVICES_NAME = 466,
     THROTTLE_TIME = 467,
     TRUE_NO_OPER_FLOOD = 468,
     UNKLINE = 469,
     USER = 470,
     USE_EGD = 471,
     USE_LOGGING = 472,
     VHOST = 473,
     VHOST6 = 474,
     XLINE = 475,
     WARN_NO_NLINE = 476,
     T_SIZE = 477,
     T_FILE = 478
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
#define HIDE_SERVICES 310
#define HIDE_SPOOF_IPS 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define IP 317
#define KILL 318
#define KILL_CHASE_TIME_LIMIT 319
#define KLINE 320
#define KLINE_EXEMPT 321
#define KNOCK_DELAY 322
#define KNOCK_DELAY_CHANNEL 323
#define LEAF_MASK 324
#define LINKS_DELAY 325
#define LISTEN 326
#define T_LOG 327
#define MASK 328
#define MAX_ACCEPT 329
#define MAX_BANS 330
#define MAX_CHANS_PER_OPER 331
#define MAX_CHANS_PER_USER 332
#define MAX_GLOBAL 333
#define MAX_IDENT 334
#define MAX_LOCAL 335
#define MAX_NICK_CHANGES 336
#define MAX_NICK_LENGTH 337
#define MAX_NICK_TIME 338
#define MAX_NUMBER 339
#define MAX_TARGETS 340
#define MAX_TOPIC_LENGTH 341
#define MAX_WATCH 342
#define MIN_NONWILDCARD 343
#define MIN_NONWILDCARD_SIMPLE 344
#define MIN_IDLE 345
#define MAX_IDLE 346
#define RANDOM_IDLE 347
#define HIDE_IDLE_FROM_OPERS 348
#define MODULE 349
#define MODULES 350
#define NAME 351
#define NEED_PASSWORD 352
#define NETWORK_DESC 353
#define NETWORK_NAME 354
#define NICK 355
#define NICK_CHANGES 356
#define NO_CREATE_ON_SPLIT 357
#define NO_JOIN_ON_SPLIT 358
#define NO_OPER_FLOOD 359
#define NO_TILDE 360
#define NUMBER 361
#define NUMBER_PER_CIDR 362
#define NUMBER_PER_IP 363
#define OPERATOR 364
#define OPERS_BYPASS_CALLERID 365
#define OPER_ONLY_UMODES 366
#define OPER_PASS_RESV 367
#define OPER_SPY_T 368
#define OPER_UMODES 369
#define JOIN_FLOOD_COUNT 370
#define JOIN_FLOOD_TIME 371
#define PACE_WAIT 372
#define PACE_WAIT_SIMPLE 373
#define PASSWORD 374
#define PATH 375
#define PING_COOKIE 376
#define PING_TIME 377
#define PORT 378
#define QSTRING 379
#define QUIET_ON_BAN 380
#define REASON 381
#define REDIRPORT 382
#define REDIRSERV 383
#define REGEX_T 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RSA_PRIVATE_KEY_FILE 388
#define RSA_PUBLIC_KEY_FILE 389
#define SSL_CERTIFICATE_FILE 390
#define SSL_DH_PARAM_FILE 391
#define T_SSL_CLIENT_METHOD 392
#define T_SSL_SERVER_METHOD 393
#define T_SSLV3 394
#define T_TLSV1 395
#define RESV 396
#define RESV_EXEMPT 397
#define SECONDS 398
#define MINUTES 399
#define HOURS 400
#define DAYS 401
#define WEEKS 402
#define MONTHS 403
#define YEARS 404
#define SENDQ 405
#define SEND_PASSWORD 406
#define SERVERHIDE 407
#define SERVERINFO 408
#define IRCD_SID 409
#define TKLINE_EXPIRE_NOTICES 410
#define T_SHARED 411
#define T_CLUSTER 412
#define TYPE 413
#define SHORT_MOTD 414
#define SPOOF 415
#define SPOOF_NOTICE 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define TBOOL 422
#define TMASKED 423
#define TS_MAX_DELTA 424
#define TS_WARN_DELTA 425
#define TWODOTS 426
#define T_ALL 427
#define T_BOTS 428
#define T_SOFTCALLERID 429
#define T_CALLERID 430
#define T_CCONN 431
#define T_CCONN_FULL 432
#define T_SSL_CIPHER_LIST 433
#define T_DEAF 434
#define T_DEBUG 435
#define T_DLINE 436
#define T_EXTERNAL 437
#define T_FULL 438
#define T_INVISIBLE 439
#define T_IPV4 440
#define T_IPV6 441
#define T_LOCOPS 442
#define T_MAX_CLIENTS 443
#define T_NCHANGE 444
#define T_NONONREG 445
#define T_OPERWALL 446
#define T_RECVQ 447
#define T_REJ 448
#define T_SERVER 449
#define T_SERVNOTICE 450
#define T_SET 451
#define T_SKILL 452
#define T_SPY 453
#define T_SSL 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_GLOBOPS 461
#define T_WALLOP 462
#define T_WEBIRC 463
#define T_RESTART 464
#define T_SERVICE 465
#define T_SERVICES_NAME 466
#define THROTTLE_TIME 467
#define TRUE_NO_OPER_FLOOD 468
#define UNKLINE 469
#define USER 470
#define USE_EGD 471
#define USE_LOGGING 472
#define VHOST 473
#define VHOST6 474
#define XLINE 475
#define WARN_NO_NLINE 476
#define T_SIZE 477
#define T_FILE 478



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 676 "conf_parser.c"
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
#line 704 "conf_parser.c"

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
#define YYLAST   1293

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  289
/* YYNRULES -- Number of rules.  */
#define YYNRULES  643
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   478

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   228,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   224,
       2,   227,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   226,     2,   225,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223
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
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     526,   532,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   558,   560,   562,   564,   566,   568,   570,
     572,   574,   576,   577,   584,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   621,   624,   629,   634,   639,   644,   649,   654,
     659,   664,   669,   674,   679,   684,   689,   694,   699,   700,
     706,   710,   712,   714,   716,   717,   724,   725,   731,   735,
     737,   739,   741,   743,   746,   748,   750,   752,   754,   756,
     759,   760,   766,   770,   772,   774,   778,   783,   788,   789,
     796,   799,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   820,   825,   830,   835,   840,   841,   847,   851,   853,
     855,   857,   859,   861,   863,   865,   867,   869,   871,   873,
     878,   883,   888,   889,   896,   899,   901,   903,   905,   907,
     910,   915,   920,   925,   931,   934,   936,   938,   940,   945,
     946,   953,   956,   958,   960,   962,   964,   967,   972,   977,
     978,   984,   988,   990,   992,   994,   996,   998,  1000,  1002,
    1004,  1006,  1008,  1010,  1011,  1018,  1021,  1023,  1025,  1027,
    1030,  1035,  1036,  1042,  1046,  1048,  1050,  1052,  1054,  1056,
    1058,  1060,  1062,  1064,  1066,  1068,  1069,  1076,  1079,  1081,
    1083,  1085,  1087,  1089,  1091,  1093,  1095,  1097,  1099,  1101,
    1103,  1105,  1107,  1110,  1115,  1120,  1125,  1130,  1135,  1140,
    1145,  1150,  1151,  1157,  1161,  1163,  1165,  1167,  1172,  1177,
    1182,  1187,  1192,  1193,  1200,  1201,  1207,  1211,  1213,  1215,
    1218,  1220,  1222,  1224,  1226,  1228,  1233,  1238,  1239,  1246,
    1249,  1251,  1253,  1255,  1257,  1262,  1267,  1273,  1276,  1278,
    1280,  1282,  1287,  1288,  1295,  1296,  1302,  1306,  1308,  1310,
    1313,  1315,  1317,  1319,  1321,  1323,  1328,  1333,  1339,  1342,
    1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,
    1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,
    1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,
    1447,  1452,  1457,  1462,  1467,  1472,  1477,  1482,  1487,  1492,
    1497,  1502,  1507,  1512,  1517,  1522,  1527,  1532,  1537,  1542,
    1547,  1552,  1557,  1562,  1567,  1572,  1577,  1582,  1587,  1592,
    1597,  1602,  1607,  1612,  1617,  1622,  1627,  1632,  1637,  1642,
    1647,  1652,  1657,  1662,  1667,  1668,  1674,  1678,  1680,  1682,
    1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,  1700,  1702,
    1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,  1720,  1721,
    1727,  1731,  1733,  1735,  1737,  1739,  1741,  1743,  1745,  1747,
    1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1767,
    1769,  1771,  1773,  1775,  1780,  1785,  1790,  1796,  1799,  1801,
    1803,  1805,  1807,  1809,  1811,  1813,  1815,  1817,  1819,  1821,
    1823,  1825,  1827,  1829,  1834,  1839,  1844,  1849,  1854,  1859,
    1864,  1869,  1874,  1879,  1884,  1889,  1894,  1900,  1903,  1905,
    1907,  1909,  1911,  1913,  1915,  1917,  1919,  1921,  1926,  1931,
    1936,  1941,  1946,  1951
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     230,     0,    -1,    -1,   230,   231,    -1,   265,    -1,   271,
      -1,   285,    -1,   492,    -1,   303,    -1,   326,    -1,   340,
      -1,   241,    -1,   508,    -1,   355,    -1,   362,    -1,   366,
      -1,   376,    -1,   385,    -1,   405,    -1,   415,    -1,   421,
      -1,   435,    -1,   425,    -1,   236,    -1,     1,   224,    -1,
       1,   225,    -1,    -1,   233,    -1,   106,   232,    -1,   106,
     143,   232,    -1,   106,   144,   232,    -1,   106,   145,   232,
      -1,   106,   146,   232,    -1,   106,   147,   232,    -1,   106,
     148,   232,    -1,   106,   149,   232,    -1,    -1,   235,    -1,
     106,   234,    -1,   106,     9,   234,    -1,   106,    10,   234,
      -1,   106,    11,   234,    -1,    95,   226,   237,   225,   224,
      -1,   237,   238,    -1,   238,    -1,   239,    -1,   240,    -1,
       1,   224,    -1,    94,   227,   124,   224,    -1,   120,   227,
     124,   224,    -1,   153,   226,   242,   225,   224,    -1,   242,
     243,    -1,   243,    -1,   254,    -1,   259,    -1,   264,    -1,
     256,    -1,   257,    -1,   258,    -1,   261,    -1,   262,    -1,
     263,    -1,   252,    -1,   251,    -1,   260,    -1,   255,    -1,
     250,    -1,   244,    -1,   245,    -1,   253,    -1,     1,   224,
      -1,   137,   227,   246,   224,    -1,   138,   227,   248,   224,
      -1,   246,   228,   247,    -1,   247,    -1,   139,    -1,   140,
      -1,   248,   228,   249,    -1,   249,    -1,   139,    -1,   140,
      -1,   135,   227,   124,   224,    -1,   133,   227,   124,   224,
      -1,   136,   227,   124,   224,    -1,   178,   227,   124,   224,
      -1,    96,   227,   124,   224,    -1,   154,   227,   124,   224,
      -1,    24,   227,   124,   224,    -1,    99,   227,   124,   224,
      -1,    98,   227,   124,   224,    -1,   218,   227,   124,   224,
      -1,   219,   227,   124,   224,    -1,   188,   227,   106,   224,
      -1,    82,   227,   106,   224,    -1,    86,   227,   106,   224,
      -1,    58,   227,   167,   224,    -1,     4,   226,   266,   225,
     224,    -1,   266,   267,    -1,   267,    -1,   268,    -1,   270,
      -1,   269,    -1,     1,   224,    -1,    96,   227,   124,   224,
      -1,    31,   227,   124,   224,    -1,    24,   227,   124,   224,
      -1,    72,   226,   272,   225,   224,    -1,   272,   273,    -1,
     273,    -1,   274,    -1,   275,    -1,     1,   224,    -1,   217,
     227,   167,   224,    -1,    -1,   276,   223,   226,   277,   225,
     224,    -1,   277,   278,    -1,   278,    -1,   279,    -1,   281,
      -1,   280,    -1,     1,   224,    -1,    96,   227,   124,   224,
      -1,   222,   227,   235,   224,    -1,   222,   227,   203,   224,
      -1,    -1,   158,   282,   227,   283,   224,    -1,   283,   228,
     284,    -1,   284,    -1,   215,    -1,   109,    -1,    40,    -1,
     181,    -1,    65,    -1,    63,    -1,   180,    -1,    -1,   109,
     286,   226,   287,   225,   224,    -1,   287,   288,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   295,    -1,   294,
      -1,   292,    -1,   293,    -1,   299,    -1,     1,   224,    -1,
      96,   227,   124,   224,    -1,   215,   227,   124,   224,    -1,
     119,   227,   124,   224,    -1,    32,   227,   167,   224,    -1,
     134,   227,   124,   224,    -1,    17,   227,   124,   224,    -1,
      -1,   200,   296,   227,   297,   224,    -1,   297,   228,   298,
      -1,   298,    -1,   173,    -1,   176,    -1,   177,    -1,   179,
      -1,   180,    -1,   183,    -1,    51,    -1,   197,    -1,   189,
      -1,   193,    -1,   201,    -1,   198,    -1,   182,    -1,   191,
      -1,   195,    -1,   184,    -1,   207,    -1,   174,    -1,   175,
      -1,   187,    -1,   190,    -1,    -1,    36,   300,   227,   301,
     224,    -1,   301,   228,   302,    -1,   302,    -1,    47,    -1,
     131,    -1,    65,    -1,   214,    -1,   181,    -1,   202,    -1,
     220,    -1,    40,    -1,    25,    -1,   209,    -1,   130,    -1,
       4,    -1,   101,    -1,   191,    -1,   206,    -1,   113,    -1,
     132,    -1,   196,    -1,    94,    -1,    -1,    17,   304,   226,
     305,   225,   224,    -1,   305,   306,    -1,   306,    -1,   307,
      -1,   317,    -1,   318,    -1,   308,    -1,   319,    -1,   309,
      -1,   310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,
      -1,   315,    -1,   316,    -1,   320,    -1,   321,    -1,   322,
      -1,     1,   224,    -1,    96,   227,   124,   224,    -1,   122,
     227,   233,   224,    -1,   108,   227,   106,   224,    -1,    19,
     227,   233,   224,    -1,    84,   227,   106,   224,    -1,    78,
     227,   106,   224,    -1,    80,   227,   106,   224,    -1,    79,
     227,   106,   224,    -1,   150,   227,   235,   224,    -1,   192,
     227,   235,   224,    -1,    15,   227,   106,   224,    -1,    16,
     227,   106,   224,    -1,   107,   227,   106,   224,    -1,    90,
     227,   233,   224,    -1,    91,   227,   233,   224,    -1,    -1,
      36,   323,   227,   324,   224,    -1,   324,   228,   325,    -1,
     325,    -1,    92,    -1,    93,    -1,    -1,    71,   327,   226,
     332,   225,   224,    -1,    -1,    36,   329,   227,   330,   224,
      -1,   330,   228,   331,    -1,   331,    -1,   199,    -1,    51,
      -1,   194,    -1,   332,   333,    -1,   333,    -1,   334,    -1,
     328,    -1,   338,    -1,   339,    -1,     1,   224,    -1,    -1,
     123,   227,   336,   335,   224,    -1,   336,   228,   337,    -1,
     337,    -1,   106,    -1,   106,   171,   106,    -1,    62,   227,
     124,   224,    -1,    57,   227,   124,   224,    -1,    -1,    48,
     341,   226,   342,   225,   224,    -1,   342,   343,    -1,   343,
      -1,   344,    -1,   345,    -1,   346,    -1,   348,    -1,   352,
      -1,   353,    -1,   354,    -1,   347,    -1,     1,   224,    -1,
     215,   227,   124,   224,    -1,   119,   227,   124,   224,    -1,
      17,   227,   124,   224,    -1,    32,   227,   167,   224,    -1,
      -1,    36,   349,   227,   350,   224,    -1,   350,   228,   351,
      -1,   351,    -1,   161,    -1,    33,    -1,    66,    -1,    49,
      -1,    13,    -1,   105,    -1,    43,    -1,   142,    -1,   208,
      -1,    97,    -1,   160,   227,   124,   224,    -1,   128,   227,
     124,   224,    -1,   127,   227,   106,   224,    -1,    -1,   141,
     356,   226,   357,   225,   224,    -1,   357,   358,    -1,   358,
      -1,   359,    -1,   360,    -1,   361,    -1,     1,   224,    -1,
      73,   227,   124,   224,    -1,   126,   227,   124,   224,    -1,
      34,   227,   124,   224,    -1,   210,   226,   363,   225,   224,
      -1,   363,   364,    -1,   364,    -1,   365,    -1,     1,    -1,
      96,   227,   124,   224,    -1,    -1,   156,   367,   226,   368,
     225,   224,    -1,   368,   369,    -1,   369,    -1,   370,    -1,
     371,    -1,   372,    -1,     1,   224,    -1,    96,   227,   124,
     224,    -1,   215,   227,   124,   224,    -1,    -1,   158,   373,
     227,   374,   224,    -1,   374,   228,   375,    -1,   375,    -1,
      65,    -1,   214,    -1,   181,    -1,   202,    -1,   220,    -1,
     205,    -1,   141,    -1,   204,    -1,   187,    -1,   172,    -1,
      -1,   157,   377,   226,   378,   225,   224,    -1,   378,   379,
      -1,   379,    -1,   380,    -1,   381,    -1,     1,   224,    -1,
      96,   227,   124,   224,    -1,    -1,   158,   382,   227,   383,
     224,    -1,   383,   228,   384,    -1,   384,    -1,    65,    -1,
     214,    -1,   181,    -1,   202,    -1,   220,    -1,   205,    -1,
     141,    -1,   204,    -1,   187,    -1,   172,    -1,    -1,    18,
     386,   226,   387,   225,   224,    -1,   387,   388,    -1,   388,
      -1,   389,    -1,   390,    -1,   391,    -1,   392,    -1,   393,
      -1,   395,    -1,   394,    -1,   404,    -1,   396,    -1,   401,
      -1,   402,    -1,   403,    -1,   400,    -1,     1,   224,    -1,
      96,   227,   124,   224,    -1,    57,   227,   124,   224,    -1,
     218,   227,   124,   224,    -1,   151,   227,   124,   224,    -1,
       3,   227,   124,   224,    -1,   123,   227,   106,   224,    -1,
       5,   227,   185,   224,    -1,     5,   227,   186,   224,    -1,
      -1,    36,   397,   227,   398,   224,    -1,   398,   228,   399,
      -1,   399,    -1,     8,    -1,   199,    -1,    32,   227,   167,
     224,    -1,    59,   227,   124,   224,    -1,    69,   227,   124,
     224,    -1,    17,   227,   124,   224,    -1,   178,   227,   124,
     224,    -1,    -1,    63,   406,   226,   411,   225,   224,    -1,
      -1,   158,   408,   227,   409,   224,    -1,   409,   228,   410,
      -1,   410,    -1,   129,    -1,   411,   412,    -1,   412,    -1,
     413,    -1,   414,    -1,   407,    -1,     1,    -1,   215,   227,
     124,   224,    -1,   126,   227,   124,   224,    -1,    -1,    23,
     416,   226,   417,   225,   224,    -1,   417,   418,    -1,   418,
      -1,   419,    -1,   420,    -1,     1,    -1,    62,   227,   124,
     224,    -1,   126,   227,   124,   224,    -1,    34,   226,   422,
     225,   224,    -1,   422,   423,    -1,   423,    -1,   424,    -1,
       1,    -1,    62,   227,   124,   224,    -1,    -1,    38,   426,
     226,   431,   225,   224,    -1,    -1,   158,   428,   227,   429,
     224,    -1,   429,   228,   430,    -1,   430,    -1,   129,    -1,
     431,   432,    -1,   432,    -1,   433,    -1,   434,    -1,   427,
      -1,     1,    -1,    96,   227,   124,   224,    -1,   126,   227,
     124,   224,    -1,    39,   226,   436,   225,   224,    -1,   436,
     437,    -1,   437,    -1,   446,    -1,   447,    -1,   449,    -1,
     450,    -1,   451,    -1,   452,    -1,   453,    -1,   454,    -1,
     455,    -1,   456,    -1,   445,    -1,   458,    -1,   459,    -1,
     473,    -1,   461,    -1,   463,    -1,   465,    -1,   464,    -1,
     468,    -1,   462,    -1,   469,    -1,   470,    -1,   471,    -1,
     472,    -1,   485,    -1,   474,    -1,   475,    -1,   476,    -1,
     481,    -1,   466,    -1,   467,    -1,   491,    -1,   489,    -1,
     490,    -1,   448,    -1,   480,    -1,   457,    -1,   478,    -1,
     479,    -1,   444,    -1,   439,    -1,   440,    -1,   441,    -1,
     442,    -1,   443,    -1,   460,    -1,   438,    -1,   477,    -1,
       1,    -1,    87,   227,   106,   224,    -1,    42,   227,   167,
     224,    -1,    41,   227,   233,   224,    -1,    44,   227,   233,
     224,    -1,    45,   227,   106,   224,    -1,    46,   227,   106,
     224,    -1,   155,   227,   167,   224,    -1,    64,   227,   233,
     224,    -1,    56,   227,   167,   224,    -1,    60,   227,   167,
     224,    -1,    28,   227,   167,   224,    -1,    35,   227,   167,
     224,    -1,     6,   227,   167,   224,    -1,    83,   227,   233,
     224,    -1,    81,   227,   106,   224,    -1,    74,   227,   106,
     224,    -1,     7,   227,   233,   224,    -1,   170,   227,   233,
     224,    -1,   169,   227,   233,   224,    -1,    50,   227,   106,
     224,    -1,    61,   227,   167,   224,    -1,   221,   227,   167,
     224,    -1,   162,   227,   167,   224,    -1,   165,   227,   167,
     224,    -1,   166,   227,   167,   224,    -1,   164,   227,   167,
     224,    -1,   164,   227,   168,   224,    -1,   163,   227,   167,
     224,    -1,   163,   227,   168,   224,    -1,   117,   227,   233,
     224,    -1,    12,   227,   233,   224,    -1,   110,   227,   167,
     224,    -1,   118,   227,   233,   224,    -1,   159,   227,   167,
     224,    -1,   104,   227,   167,   224,    -1,   213,   227,   167,
     224,    -1,   112,   227,   167,   224,    -1,    29,   227,   106,
     224,    -1,    85,   227,   106,   224,    -1,   216,   227,   167,
     224,    -1,    30,   227,   124,   224,    -1,   211,   227,   124,
     224,    -1,   121,   227,   167,   224,    -1,    26,   227,   167,
     224,    -1,   212,   227,   233,   224,    -1,    -1,   114,   482,
     227,   483,   224,    -1,   483,   228,   484,    -1,   484,    -1,
     173,    -1,   176,    -1,   177,    -1,   179,    -1,   180,    -1,
     183,    -1,    51,    -1,   197,    -1,   189,    -1,   193,    -1,
     201,    -1,   198,    -1,   182,    -1,   191,    -1,   195,    -1,
     184,    -1,   207,    -1,   174,    -1,   175,    -1,   187,    -1,
      -1,   111,   486,   227,   487,   224,    -1,   487,   228,   488,
      -1,   488,    -1,   173,    -1,   176,    -1,   177,    -1,   179,
      -1,   180,    -1,   183,    -1,   197,    -1,    51,    -1,   189,
      -1,   193,    -1,   201,    -1,   198,    -1,   182,    -1,   191,
      -1,   195,    -1,   184,    -1,   207,    -1,   174,    -1,   175,
      -1,   187,    -1,   190,    -1,    88,   227,   106,   224,    -1,
      89,   227,   106,   224,    -1,    20,   227,   106,   224,    -1,
      14,   226,   493,   225,   224,    -1,   493,   494,    -1,   494,
      -1,   501,    -1,   496,    -1,   497,    -1,   498,    -1,   499,
      -1,   500,    -1,   502,    -1,   503,    -1,   504,    -1,   505,
      -1,   506,    -1,   507,    -1,   495,    -1,     1,    -1,    27,
     227,   167,   224,    -1,    67,   227,   233,   224,    -1,    68,
     227,   233,   224,    -1,    77,   227,   106,   224,    -1,    76,
     227,   106,   224,    -1,   125,   227,   167,   224,    -1,    75,
     227,   106,   224,    -1,    22,   227,   106,   224,    -1,    21,
     227,   106,   224,    -1,   102,   227,   167,   224,    -1,   103,
     227,   167,   224,    -1,   115,   227,   106,   224,    -1,   116,
     227,   233,   224,    -1,   152,   226,   509,   225,   224,    -1,
     509,   510,    -1,   510,    -1,   511,    -1,   512,    -1,   513,
      -1,   515,    -1,   516,    -1,   514,    -1,   517,    -1,     1,
      -1,    37,   227,   167,   224,    -1,    54,   227,   167,   224,
      -1,    55,   227,   167,   224,    -1,    52,   227,   124,   224,
      -1,    70,   227,   233,   224,    -1,    51,   227,   167,   224,
      -1,    53,   227,   167,   224,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   365,   365,   366,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   394,   394,   395,   399,
     403,   407,   411,   415,   419,   423,   429,   429,   430,   431,
     432,   433,   440,   443,   443,   444,   444,   444,   446,   452,
     459,   461,   461,   462,   462,   463,   463,   464,   464,   465,
     465,   466,   466,   467,   467,   468,   468,   469,   469,   470,
     471,   474,   475,   477,   477,   478,   484,   492,   492,   493,
     499,   507,   549,   608,   636,   644,   659,   674,   683,   697,
     706,   734,   764,   789,   811,   833,   842,   844,   844,   845,
     845,   846,   846,   848,   857,   866,   878,   879,   879,   881,
     881,   882,   884,   891,   891,   904,   905,   907,   907,   908,
     908,   910,   918,   921,   927,   926,   932,   932,   933,   937,
     941,   945,   949,   953,   957,   968,   967,  1044,  1044,  1045,
    1045,  1045,  1046,  1046,  1046,  1047,  1047,  1047,  1049,  1055,
    1061,  1067,  1078,  1084,  1091,  1090,  1096,  1096,  1097,  1101,
    1105,  1109,  1113,  1117,  1121,  1125,  1129,  1133,  1137,  1141,
    1145,  1149,  1153,  1157,  1161,  1165,  1169,  1173,  1177,  1184,
    1183,  1189,  1189,  1190,  1194,  1198,  1202,  1206,  1210,  1214,
    1218,  1222,  1226,  1230,  1234,  1238,  1242,  1246,  1250,  1254,
    1258,  1262,  1273,  1272,  1333,  1333,  1334,  1335,  1335,  1336,
    1337,  1338,  1339,  1340,  1341,  1342,  1343,  1344,  1344,  1345,
    1346,  1347,  1348,  1350,  1356,  1362,  1368,  1374,  1380,  1386,
    1392,  1398,  1404,  1411,  1417,  1423,  1429,  1438,  1448,  1447,
    1453,  1453,  1454,  1458,  1469,  1468,  1475,  1474,  1479,  1479,
    1480,  1484,  1488,  1494,  1494,  1495,  1495,  1495,  1495,  1495,
    1497,  1497,  1499,  1499,  1501,  1515,  1535,  1541,  1551,  1550,
    1592,  1592,  1593,  1593,  1593,  1593,  1594,  1594,  1594,  1595,
    1595,  1597,  1603,  1609,  1615,  1627,  1626,  1632,  1632,  1633,
    1637,  1641,  1645,  1649,  1653,  1657,  1661,  1665,  1669,  1675,
    1689,  1698,  1712,  1711,  1726,  1726,  1727,  1727,  1727,  1727,
    1729,  1735,  1741,  1751,  1753,  1753,  1754,  1754,  1756,  1772,
    1771,  1796,  1796,  1797,  1797,  1797,  1797,  1799,  1805,  1825,
    1824,  1830,  1830,  1831,  1835,  1839,  1843,  1847,  1851,  1855,
    1859,  1863,  1867,  1877,  1876,  1897,  1897,  1898,  1898,  1898,
    1900,  1907,  1906,  1912,  1912,  1913,  1917,  1921,  1925,  1929,
    1933,  1937,  1941,  1945,  1949,  1959,  1958,  2024,  2024,  2025,
    2025,  2025,  2026,  2026,  2027,  2027,  2027,  2028,  2028,  2028,
    2029,  2029,  2030,  2032,  2038,  2044,  2050,  2063,  2076,  2082,
    2086,  2095,  2094,  2099,  2099,  2100,  2104,  2110,  2121,  2127,
    2133,  2139,  2155,  2154,  2217,  2216,  2222,  2222,  2223,  2229,
    2229,  2230,  2230,  2230,  2230,  2232,  2252,  2262,  2261,  2288,
    2288,  2289,  2289,  2289,  2291,  2297,  2306,  2308,  2308,  2309,
    2309,  2311,  2329,  2328,  2374,  2373,  2379,  2379,  2380,  2386,
    2386,  2387,  2387,  2387,  2387,  2389,  2395,  2404,  2407,  2407,
    2408,  2408,  2409,  2409,  2410,  2410,  2411,  2411,  2412,  2412,
    2413,  2414,  2415,  2415,  2416,  2416,  2417,  2417,  2418,  2418,
    2419,  2419,  2420,  2420,  2421,  2421,  2422,  2422,  2423,  2423,
    2424,  2424,  2425,  2425,  2426,  2427,  2427,  2428,  2429,  2430,
    2430,  2431,  2431,  2432,  2433,  2434,  2435,  2435,  2436,  2439,
    2444,  2450,  2456,  2462,  2467,  2472,  2477,  2482,  2487,  2492,
    2497,  2502,  2507,  2512,  2517,  2522,  2527,  2532,  2538,  2549,
    2554,  2559,  2564,  2569,  2574,  2577,  2582,  2585,  2590,  2595,
    2600,  2605,  2610,  2615,  2620,  2625,  2630,  2635,  2640,  2645,
    2654,  2663,  2668,  2673,  2679,  2678,  2683,  2683,  2684,  2687,
    2690,  2693,  2696,  2699,  2702,  2705,  2708,  2711,  2714,  2717,
    2720,  2723,  2726,  2729,  2732,  2735,  2738,  2741,  2747,  2746,
    2751,  2751,  2752,  2755,  2758,  2761,  2764,  2767,  2770,  2773,
    2776,  2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,  2803,
    2806,  2809,  2812,  2817,  2822,  2827,  2836,  2839,  2839,  2840,
    2841,  2841,  2842,  2842,  2843,  2843,  2844,  2845,  2846,  2847,
    2847,  2848,  2848,  2850,  2855,  2860,  2865,  2870,  2875,  2880,
    2885,  2890,  2895,  2900,  2905,  2910,  2918,  2921,  2921,  2922,
    2922,  2923,  2924,  2925,  2925,  2926,  2927,  2929,  2935,  2941,
    2947,  2956,  2970,  2976
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
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES",
  "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS",
  "INVISIBLE_ON_CONNECT", "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE",
  "KLINE_EXEMPT", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MIN_IDLE", "MAX_IDLE",
  "RANDOM_IDLE", "HIDE_IDLE_FROM_OPERS", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT",
  "REDIRSERV", "REGEX_T", "REHASH", "REMOTE", "REMOTEBAN",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_NONONREG", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
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
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
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
  "channel_disable_fake_channels", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_max_chans_per_oper", "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hide_services",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
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
     475,   476,   477,   478,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   229,   230,   230,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   232,   232,   233,   233,
     233,   233,   233,   233,   233,   233,   234,   234,   235,   235,
     235,   235,   236,   237,   237,   238,   238,   238,   239,   240,
     241,   242,   242,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   244,   245,   246,   246,   247,   247,   248,   248,   249,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   266,   267,
     267,   267,   267,   268,   269,   270,   271,   272,   272,   273,
     273,   273,   274,   276,   275,   277,   277,   278,   278,   278,
     278,   279,   280,   280,   282,   281,   283,   283,   284,   284,
     284,   284,   284,   284,   284,   286,   285,   287,   287,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   289,   290,
     291,   292,   293,   294,   296,   295,   297,   297,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   300,
     299,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   304,   303,   305,   305,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   323,   322,
     324,   324,   325,   325,   327,   326,   329,   328,   330,   330,
     331,   331,   331,   332,   332,   333,   333,   333,   333,   333,
     335,   334,   336,   336,   337,   337,   338,   339,   341,   340,
     342,   342,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   344,   345,   346,   347,   349,   348,   350,   350,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   352,
     353,   354,   356,   355,   357,   357,   358,   358,   358,   358,
     359,   360,   361,   362,   363,   363,   364,   364,   365,   367,
     366,   368,   368,   369,   369,   369,   369,   370,   371,   373,
     372,   374,   374,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   377,   376,   378,   378,   379,   379,   379,
     380,   382,   381,   383,   383,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   386,   385,   387,   387,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   389,   390,   391,   392,   393,   394,   395,
     395,   397,   396,   398,   398,   399,   399,   400,   401,   402,
     403,   404,   406,   405,   408,   407,   409,   409,   410,   411,
     411,   412,   412,   412,   412,   413,   414,   416,   415,   417,
     417,   418,   418,   418,   419,   420,   421,   422,   422,   423,
     423,   424,   426,   425,   428,   427,   429,   429,   430,   431,
     431,   432,   432,   432,   432,   433,   434,   435,   436,   436,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   463,   464,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   482,   481,   483,   483,   484,   484,
     484,   484,   484,   484,   484,   484,   484,   484,   484,   484,
     484,   484,   484,   484,   484,   484,   484,   484,   486,   485,
     487,   487,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   489,   490,   491,   492,   493,   493,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   509,   510,
     510,   510,   510,   510,   510,   510,   510,   511,   512,   513,
     514,   515,   516,   517
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     0,     6,     0,     5,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2,
       0,     5,     3,     1,     1,     3,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   202,   365,   417,     0,
     432,     0,   268,   402,   244,     0,     0,   135,   302,     0,
       0,   319,   343,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   612,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   598,   611,   600,   601,   602,   603,   604,   599,   605,
     606,   607,   608,   609,   610,     0,     0,     0,   430,     0,
       0,   428,   429,     0,   498,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   568,     0,   544,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,   496,   490,   491,   492,   493,
     494,   489,   460,   450,   451,   484,   452,   453,   454,   455,
     456,   457,   458,   459,   486,   461,   462,   495,   464,   469,
     465,   467,   466,   479,   480,   468,   470,   471,   472,   473,
     463,   475,   476,   477,   497,   487,   488,   485,   478,   474,
     482,   483,   481,     0,     0,     0,     0,     0,     0,   108,
     109,   110,     0,     0,     0,     0,     0,    44,    45,    46,
       0,     0,   636,     0,     0,     0,     0,     0,     0,     0,
       0,   628,   629,   630,   631,   634,   632,   633,   635,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    67,
      68,    66,    63,    62,    69,    53,    65,    56,    57,    58,
      54,    64,    59,    60,    61,    55,     0,     0,   317,     0,
       0,   315,   316,   102,     0,     0,     0,     0,    97,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   597,     0,     0,     0,     0,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   205,   206,   209,   211,   212,   213,   214,   215,
     216,   217,   218,   207,   208,   210,   219,   220,   221,     0,
       0,     0,     0,     0,   391,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   368,   369,   370,   371,   372,   373,
     375,   374,   377,   381,   378,   379,   380,   376,   423,     0,
       0,     0,   420,   421,   422,     0,     0,   427,   444,     0,
       0,   434,   443,     0,   440,   441,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,     0,     0,     0,
     285,     0,     0,     0,     0,     0,     0,   271,   272,   273,
     274,   279,   275,   276,   277,   278,   414,     0,   404,     0,
     413,     0,   410,   411,   412,     0,   246,     0,     0,     0,
     256,     0,   254,   255,   257,   258,   111,     0,     0,   107,
       0,    47,     0,     0,     0,    43,     0,     0,     0,   179,
       0,     0,     0,   154,     0,     0,   138,   139,   140,   141,
     144,   145,   143,   142,   146,     0,     0,     0,     0,     0,
     305,   306,   307,   308,     0,     0,     0,     0,     0,     0,
       0,     0,   627,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    51,     0,     0,   329,     0,     0,   322,   323,
     324,   325,     0,     0,   351,     0,   346,   347,   348,     0,
       0,   314,     0,     0,     0,    96,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     596,   222,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     382,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   367,     0,     0,     0,   419,
       0,   426,     0,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   447,   280,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   270,     0,
       0,     0,     0,   409,   259,     0,     0,     0,     0,     0,
     253,     0,   106,     0,     0,     0,    42,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   309,     0,
       0,     0,     0,   304,     0,     0,     0,     0,     0,     0,
       0,   626,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   326,     0,     0,     0,
       0,   321,   349,     0,     0,     0,   345,     0,   313,   105,
     104,   103,   621,   620,   613,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   614,   615,   619,   617,   616,   622,
     623,   624,   625,   618,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,     0,
       0,   203,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   366,     0,     0,   418,
     431,     0,     0,     0,   433,   511,   515,   529,   595,   542,
     509,   536,   539,   510,   501,   500,   502,   503,   504,   518,
     507,   508,   519,   506,   514,   513,   512,   537,   499,   593,
     594,   533,   530,   579,   572,   589,   590,   573,   574,   575,
     576,   584,   577,   587,   591,   580,   592,   585,   581,   586,
     578,   583,   582,   588,     0,   571,   535,   554,   548,   565,
     566,   549,   550,   551,   552,   560,   553,   563,   567,   556,
     561,   557,   562,   555,   559,   558,   564,     0,   547,   528,
     531,   541,   505,   532,   521,   526,   527,   524,   525,   522,
     523,   517,   516,   540,   543,   534,   538,   520,     0,     0,
       0,     0,     0,     0,     0,     0,   269,     0,     0,     0,
     403,     0,     0,     0,   264,   260,   263,   245,   112,     0,
       0,   124,     0,     0,   116,   117,   119,   118,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,   303,   637,   642,   640,   643,   638,   639,   641,
      87,    95,    93,    94,    85,    89,    88,    82,    81,    83,
      71,     0,    72,     0,    86,    84,    92,    90,    91,     0,
       0,     0,   320,     0,     0,   344,   318,    29,    30,    31,
      32,    33,    34,    35,   233,   234,   226,   242,   243,     0,
     241,   228,   230,   229,   227,   236,   237,   223,   235,   225,
     224,    36,    36,    36,    38,    37,   231,   232,   387,   389,
     390,   400,   397,   395,   396,     0,   394,   384,   398,   399,
     383,   388,   386,   401,   385,   424,   425,   445,   446,   438,
       0,   437,   569,     0,   545,     0,   283,   284,   293,   290,
     295,   292,   291,   298,   294,   296,   289,   297,     0,   288,
     282,   301,   300,   299,   281,   416,   408,     0,   407,   415,
     251,   252,   250,     0,   249,   267,   266,     0,     0,     0,
     120,     0,     0,     0,     0,   115,   153,   151,   194,   191,
     190,   183,   185,   201,   195,   198,   193,   184,   199,   187,
     196,   200,   188,   197,   192,   186,   189,     0,   182,   148,
     150,   152,   164,   158,   175,   176,   159,   160,   161,   162,
     170,   163,   173,   177,   166,   178,   171,   167,   172,   165,
     169,   168,   174,     0,   157,   149,   312,   310,   311,    73,
      77,   327,   333,   339,   342,   335,   341,   336,   340,   338,
     334,   337,     0,   332,   328,   350,   355,   361,   364,   357,
     363,   358,   362,   360,   356,   359,     0,   354,   239,     0,
      39,    40,    41,   392,     0,   435,     0,   570,   546,   286,
       0,   405,     0,   247,     0,   265,   262,   261,     0,     0,
       0,     0,   114,   180,     0,   155,     0,   330,     0,   352,
       0,   240,   393,   436,   287,   406,   248,   121,   130,   133,
     132,   129,   134,   131,   128,     0,   127,   123,   122,   181,
     156,   331,   353,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   792,   793,  1044,  1045,    25,   226,   227,
     228,   229,    26,   267,   268,   269,   270,   754,   755,   758,
     759,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,    27,    71,    72,    73,
      74,    75,    28,   218,   219,   220,   221,   222,   963,   964,
     965,   966,   967,  1112,  1245,  1246,    29,    60,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   724,  1163,  1164,
     514,   720,  1137,  1138,    30,    49,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   595,  1029,  1030,    31,    57,   480,
     705,  1103,  1104,   481,   482,   483,  1109,   955,   956,   484,
     485,    32,    55,   456,   457,   458,   459,   460,   461,   462,
     691,  1088,  1089,   463,   464,   465,    33,    61,   519,   520,
     521,   522,   523,    34,   290,   291,   292,    35,    64,   557,
     558,   559,   560,   561,   768,  1182,  1183,    36,    65,   565,
     566,   567,   568,   774,  1196,  1197,    37,    50,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   615,  1055,
    1056,   373,   374,   375,   376,   377,    38,    56,   470,   700,
    1097,  1098,   471,   472,   473,   474,    39,    51,   381,   382,
     383,   384,    40,   110,   111,   112,    41,    53,   392,   634,
    1070,  1071,   393,   394,   395,   396,    42,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   427,   917,   918,   209,   425,   894,   895,
     210,   211,   212,    43,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    44,
     240,   241,   242,   243,   244,   245,   246,   247,   248
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -985
static const yytype_int16 yypact[] =
{
    -985,   599,  -985,  -196,  -221,  -213,  -985,  -985,  -985,  -188,
    -985,  -185,  -985,  -985,  -985,  -182,  -141,  -985,  -985,  -132,
    -119,  -985,  -985,  -112,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,   348,   839,  -104,
     -99,   -91,    31,   -84,   347,   -75,   -59,   -56,    72,   266,
     -37,    -9,   425,   389,    -1,    45,    15,  -191,   -44,    37,
      56,    16,  -985,  -985,  -985,  -985,  -985,    75,    77,    85,
     120,   124,   125,   131,   135,   136,   144,   154,   156,   157,
     241,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,   565,   529,    26,  -985,   158,
      13,  -985,  -985,    17,  -985,   160,   169,   171,   173,   175,
     177,   178,   179,   183,   185,   188,   189,   191,   192,   193,
     195,   196,   197,   198,   200,   204,   206,   211,   213,   215,
     216,   218,   219,  -985,   226,  -985,   228,   229,   233,   236,
     242,   243,   245,   247,   254,   257,   259,   262,   265,   270,
     273,   274,   276,    36,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,   363,    62,   271,    57,   277,    20,  -985,
    -985,  -985,    67,   105,   278,   281,    51,  -985,  -985,  -985,
     333,    82,  -985,   288,   291,   292,   294,   301,   302,   304,
     269,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   116,
     318,   320,   322,   324,   325,   326,   329,   335,   337,   342,
     343,   344,   345,   346,   349,   352,   355,    78,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,    38,     8,  -985,   356,
      53,  -985,  -985,  -985,   162,   246,   369,   225,  -985,   390,
     392,   132,   468,   468,   481,   491,   496,   283,   418,   499,
     468,   439,   385,  -985,   386,   387,   388,   391,  -985,   394,
     397,   399,   400,   401,   402,   403,   404,   405,   407,   408,
     412,   143,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   395,
     419,   421,   423,   426,  -985,   427,   430,   431,   432,   436,
     437,   438,   440,   223,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   441,
     442,     6,  -985,  -985,  -985,   488,   451,  -985,  -985,   449,
     450,  -985,  -985,    35,  -985,  -985,  -985,   511,   468,   468,
     573,   515,   518,   580,   564,   522,   468,   523,   468,   586,
     589,   590,   530,   531,   533,   468,   596,   598,   468,   603,
     604,   605,   607,   538,   547,   490,   551,   493,   468,   468,
     554,   555,   556,   558,  -117,     5,   559,   560,   468,   468,
     608,   468,   561,   562,   566,   507,  -985,   512,   514,   516,
    -985,   517,   519,   521,   526,   527,    59,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,   536,  -985,   539,
    -985,    54,  -985,  -985,  -985,   513,  -985,   543,   544,   546,
    -985,    10,  -985,  -985,  -985,  -985,  -985,   567,   525,  -985,
     524,  -985,   614,   615,   553,  -985,   557,   552,   563,  -985,
     568,   574,   577,  -985,   581,    73,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,   569,   588,   592,   595,    11,
    -985,  -985,  -985,  -985,   575,   578,   660,   618,   620,   621,
     468,   570,  -985,  -985,   665,   624,   711,   717,   709,   713,
     714,   720,   722,   724,   -70,    64,   728,   730,   749,   732,
     734,   638,  -985,   639,   637,  -985,   640,    60,  -985,  -985,
    -985,  -985,   641,   642,  -985,    86,  -985,  -985,  -985,   744,
     646,  -985,   647,   649,   653,  -985,   654,   655,   656,   393,
     657,   658,   659,   661,   662,   663,   664,   667,   668,   669,
    -985,  -985,   770,   783,   468,   671,   788,   789,   790,   791,
     468,   468,   775,   794,   795,   468,   796,   796,   679,  -985,
    -985,   780,    24,   781,   741,   682,   786,   787,   793,   797,
     806,   798,   799,   800,   689,  -985,   801,   802,   694,  -985,
     695,  -985,   803,   804,   693,   705,  -985,   706,   707,   708,
     710,   712,   715,   716,   719,   721,   723,   725,   726,   727,
     729,   733,   735,   736,   737,   738,   739,   742,   743,   745,
     746,   747,   748,   750,   751,   585,   752,   652,   753,   754,
     755,   756,   757,   758,   759,   760,   761,   762,   763,   764,
     765,   766,   767,   768,   769,   771,   772,  -985,  -985,   809,
     777,   731,   811,   831,   814,   822,   824,   773,  -985,   828,
     774,   832,   776,  -985,  -985,   778,   841,   844,   867,   779,
    -985,   782,  -985,     7,   784,   785,  -985,  -985,   870,   835,
     792,   874,   875,   880,   805,   883,   807,  -985,  -985,   886,
     887,   888,   810,  -985,   812,   813,   815,   816,   817,   818,
     819,  -985,   820,   821,   823,   825,   826,   827,   829,   830,
     833,   834,  -985,  -985,  -209,  -985,  -985,  -985,  -202,  -985,
     836,   837,   838,   840,   842,  -985,  -985,   889,   808,   890,
     843,  -985,  -985,   891,   845,   846,  -985,   847,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,   468,   468,   468,   468,   468,
     468,   468,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,   849,   850,   851,   222,   852,   853,
     854,   855,   856,   857,   858,   859,   860,   861,    14,   862,
     863,  -985,   864,   865,   866,   868,   869,    -2,   871,   872,
     873,   876,   877,   878,   879,   881,  -985,   882,   884,  -985,
    -985,   885,   892,   893,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -194,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -193,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   894,   895,
     312,   896,   897,   898,   899,   900,  -985,   901,   904,   902,
    -985,   -31,   903,   905,   920,   906,  -985,  -985,  -985,   907,
     908,  -985,   909,    88,  -985,  -985,  -985,  -985,  -985,  -985,
     913,   914,   510,   915,   916,   917,   623,   918,  -985,   919,
     921,   922,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,   -70,  -985,    64,  -985,  -985,  -985,  -985,  -985,   923,
     479,   924,  -985,   925,   670,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -175,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,   796,   796,   796,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,   -98,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
     -43,  -985,  -985,   585,  -985,   652,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   -34,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,    30,  -985,  -985,
    -985,  -985,  -985,    63,  -985,  -985,  -985,   910,   867,   926,
    -985,   928,   927,  -102,   929,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,   102,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,   103,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,   108,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,   113,  -985,  -985,   222,
    -985,  -985,  -985,  -985,    -2,  -985,   893,  -985,  -985,  -985,
     312,  -985,   904,  -985,   -31,  -985,  -985,  -985,   931,   374,
     932,   933,  -985,  -985,   510,  -985,   623,  -985,   479,  -985,
     670,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,   114,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,   374,  -985
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -985,  -985,  -985,  -195,  -300,  -984,  -606,  -985,  -985,   934,
    -985,  -985,  -985,  -985,   848,  -985,  -985,  -985,    19,  -985,
      18,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,   946,  -985,
    -985,  -985,  -985,  -985,   912,  -985,  -985,  -985,  -985,    55,
    -985,  -985,  -985,  -985,  -985,  -231,  -985,  -985,  -985,   520,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -200,
    -985,  -985,  -985,  -197,  -985,  -985,  -985,   697,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -170,  -985,  -985,  -985,
    -985,  -985,  -190,  -985,   549,  -985,  -985,  -985,   -62,  -985,
    -985,  -985,  -985,  -985,   582,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -162,  -985,  -985,  -985,  -985,  -985,  -985,   537,
    -985,  -985,  -985,  -985,  -985,   911,  -985,  -985,  -985,  -985,
     498,  -985,  -985,  -985,  -985,  -985,  -169,  -985,  -985,  -985,
     500,  -985,  -985,  -985,  -985,  -167,  -985,  -985,  -985,   930,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -136,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -143,  -985,   627,  -985,  -985,  -985,  -985,  -985,   718,
    -985,  -985,  -985,  -985,   984,  -985,  -985,  -985,  -985,  -985,
    -985,   -96,  -985,   740,  -985,  -985,  -985,  -985,   941,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,    32,  -985,  -985,  -985,    39,
    -985,  -985,  -985,  -985,  -985,  1021,  -985,  -985,  -985,  -985,
    -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,  -985,
    -985,   935,  -985,  -985,  -985,  -985,  -985,  -985,  -985
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     819,   820,   580,   581,   818,    47,  1053,   378,   959,   562,
     588,   475,   515,    48,   108,  1000,   288,    67,   388,  1001,
    1100,   216,  1002,  1041,  1042,  1043,  1003,   378,    45,    46,
    1072,  1074,   108,   293,  1073,  1075,   388,   114,    52,   553,
      68,    54,   115,   116,    58,   516,   476,    69,   117,  1198,
     674,   675,   223,  1199,   288,   466,   118,  1200,  1201,  1202,
     447,   553,   119,   466,   120,   121,   122,   477,   379,   752,
     753,   123,   478,   216,   496,   109,   448,   124,   125,   249,
     126,   127,   128,   515,   517,    59,   129,   562,   379,   959,
     497,   449,   130,   109,    62,   450,   131,   132,   638,   639,
     133,  1220,   250,   960,   563,   498,   646,    63,   648,   499,
     134,   289,    70,   389,    66,   655,   516,   135,   658,   136,
     818,   137,   105,   138,   139,   140,  1203,   106,   668,   669,
    1204,   389,   380,   479,   554,   107,   251,   518,   680,   681,
     141,   683,   113,   390,   314,   224,   142,   143,   144,   289,
     145,   213,   380,   146,   147,   517,   554,   148,   315,   316,
     252,   390,   317,  1101,   253,   961,   564,   214,  1102,   500,
     215,   225,   676,   677,   254,   391,   255,   256,   451,   318,
     467,  1205,   563,   294,   960,  1206,   452,   453,   467,   230,
    1209,   149,   501,   391,  1210,   150,   555,  1054,   151,   152,
     153,   154,   155,   756,   757,   156,   157,   502,   518,   823,
     824,   257,   468,   258,   259,   260,   261,   231,   555,   454,
     468,   319,   320,   321,   349,   286,   350,   322,   351,   962,
     740,   628,   262,   323,   324,   709,   732,   217,   386,   325,
     352,   297,    76,  -113,   564,   488,   961,   158,   159,   160,
     326,   327,   161,   556,  1211,   353,   263,   162,  1212,   354,
     635,   445,    77,    78,   295,   328,   264,   223,    79,   469,
     232,   287,   475,   503,   455,   556,   494,   469,   570,   702,
     355,   486,   356,   296,   697,   770,   572,  1213,   504,   217,
     490,  1214,   357,   329,   806,  -113,   265,   266,   726,   578,
     812,   813,   299,   551,   300,   817,   233,   476,    80,    81,
     962,   775,   301,  1114,  1027,  1028,    82,    83,    84,   358,
     234,   235,   236,   237,   238,  1078,  1223,  1225,   477,   491,
    1224,  1226,  1227,   478,   496,   330,  1228,  1229,  1253,   239,
     533,  1230,  1254,    85,    86,  1079,   359,   302,   114,    67,
     497,   303,   304,   115,   116,  1080,    87,    88,   305,   117,
     224,  1081,   306,   307,   447,   498,    89,   118,   608,   499,
     573,   308,    68,   119,   360,   120,   121,   122,  1082,    69,
     448,   309,   123,   310,   311,   385,   225,   397,   124,   125,
     249,   126,   127,   128,   479,   449,   398,   129,   399,   450,
     400,   361,   401,   130,   402,   403,   404,   131,   132,  1083,
     405,   133,   406,   250,  1238,   407,   408,  1084,   409,   410,
     411,   134,   412,   413,   414,   415,   232,   416,   135,   500,
     136,   417,   137,   418,   138,   139,   140,  1239,   419,  1240,
     420,   362,   421,   422,    70,   423,   424,   251,   624,   575,
     585,   141,   501,   426,  1085,   428,   429,   142,   143,   144,
     430,   145,   233,   431,   146,   147,   312,   502,   148,   432,
     433,   252,   434,  1086,   435,   253,   234,   235,   236,   237,
     238,   436,   451,  1241,   437,   254,   438,   255,   256,   439,
     452,   453,   440,   574,   531,   239,   576,   441,   577,   579,
     442,   443,   149,   444,   487,   492,   150,  1221,   493,   151,
     152,   153,   154,   155,  1118,   524,   156,   157,   525,   526,
    1087,   527,   257,   454,   258,   259,   260,   261,   528,   529,
     349,   530,   350,   503,   351,  1119,   785,   786,   787,   788,
     789,   790,   791,   262,  1172,   534,   352,   535,   504,   536,
    1120,   537,   538,   539,  1242,  1243,   540,  1121,   158,   159,
     160,   353,   541,   161,   542,   354,   314,   263,   162,   543,
     544,   545,   546,   547,   579,  1122,   548,   264,   455,   549,
     315,   316,   550,   569,   317,   586,   355,   582,   356,  1244,
    1017,  1018,  1019,  1020,  1021,  1022,  1023,   583,   357,     2,
       3,   318,   584,     4,  1123,   587,   589,   265,   266,   590,
     591,  1124,   630,     5,   592,   593,     6,     7,   594,   610,
    1173,   596,     8,  1125,   597,   358,   598,   599,   600,   601,
     602,   603,   604,     9,   605,   606,   873,    10,    11,   607,
    1126,  1127,  1128,   319,   320,   321,   611,    12,   612,   322,
     613,  1174,   359,   614,   616,   323,   324,   617,   618,   619,
    1175,   325,    13,   620,   621,   622,  1176,   623,   626,   627,
      14,    15,   326,   327,  1142,   631,   632,   633,   637,   640,
     360,  1177,   641,  1178,  1179,   642,   643,   328,   644,   645,
     647,  1129,   649,  1180,    16,   650,   651,   652,   653,  1181,
     654,  1130,   656,   897,   657,   663,  1131,   361,    17,   659,
     660,   661,  1132,   662,   664,   329,  1133,   665,   666,  1134,
     667,   670,   671,   672,  1135,   673,   678,   679,   684,   685,
    1136,   687,   682,   686,   711,  1186,   688,   704,   714,   715,
      18,   689,   734,   690,   692,   735,   693,   362,   694,   712,
     713,    19,    20,   695,   696,    21,    22,   330,   874,   875,
     876,   877,   878,   699,   879,   880,   701,   881,   882,   883,
     706,   707,   884,   708,   885,   886,   887,   716,   888,   718,
     889,   717,   890,   891,   736,   737,   892,   738,   739,   742,
     719,   743,   893,   728,   741,   721,  1143,  1144,  1145,  1146,
    1147,   722,  1148,  1149,   723,  1150,  1151,  1152,   725,    23,
    1153,  1187,  1154,  1155,  1156,   729,  1157,   744,  1158,   730,
    1159,  1160,   731,   745,  1161,   898,   899,   900,   901,   902,
    1162,   903,   904,   746,   905,   906,   907,   747,   748,   908,
      76,   909,  1188,   910,   749,   911,   750,   912,   751,   913,
     914,  1189,   760,   915,   761,   762,   763,  1190,   764,   916,
      77,    78,   765,   766,   767,   772,    79,   769,   777,   773,
     778,   779,  1191,   780,  1192,  1193,   804,   781,   782,   783,
     784,   794,   795,   796,  1194,   797,   798,   799,   800,   805,
    1195,   801,   802,   803,   808,   809,   810,   811,   807,   814,
     815,   816,   818,   821,   822,   825,    80,    81,   826,   827,
     828,   829,   832,   836,    82,    83,    84,   830,   839,   840,
     843,   831,   833,   834,   835,   837,   838,   841,   842,   844,
     845,   846,   847,   938,   848,   941,   849,   942,   943,   850,
     851,    85,    86,   852,   939,   853,   944,   854,   945,   855,
     856,   857,   947,   858,    87,    88,   949,   859,   940,   860,
     861,   862,   863,   864,    89,   952,   865,   866,   953,   867,
     868,   869,   870,   954,   871,   872,   896,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   929,   930,   931,
     932,   933,   934,   935,   970,   936,   937,   946,   973,   974,
     950,   948,   971,   957,   975,   951,   958,   977,   968,   969,
     979,   980,   981,  1009,  1011,  1013,  1215,   298,  1115,   972,
    1169,  1170,  1069,  1255,  1236,   727,  1250,  1249,   609,  1231,
     710,   978,   976,  1096,   982,  1010,   983,   984,   698,   985,
     986,   987,   988,   989,   990,   991,  1216,   992,  1234,   993,
     994,   995,  1218,   996,   997,   771,   733,   998,   999,  1251,
    1004,  1005,  1006,  1252,  1007,   776,  1008,  1012,  1232,  1235,
    1015,  1016,  1014,  1024,  1025,  1026,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1046,  1047,  1048,  1049,
    1050,  1107,  1051,  1052,   387,  1057,  1058,  1059,   703,   629,
    1060,  1061,  1062,  1063,   446,  1064,  1065,  1208,  1066,  1067,
    1233,   313,  1207,     0,     0,   552,  1068,     0,  1076,  1077,
    1090,  1091,  1092,  1093,  1094,  1095,  1099,  1105,     0,  1106,
     489,  1110,     0,   636,  1108,  1111,  1113,  1116,  1117,  1139,
    1140,  1141,  1165,  1166,     0,  1167,  1168,  1171,  1184,  1185,
    1217,     0,     0,  1222,  1219,  1237,  1247,  1248,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   532,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   571,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   625
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-985)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     606,   607,   302,   303,   106,   226,     8,     1,     1,     1,
     310,     1,     1,   226,     1,   224,     1,     1,     1,   228,
      51,     1,   224,     9,    10,    11,   228,     1,   224,   225,
     224,   224,     1,   224,   228,   228,     1,     1,   226,     1,
      24,   226,     6,     7,   226,    34,    36,    31,    12,   224,
     167,   168,     1,   228,     1,     1,    20,  1041,  1042,  1043,
       1,     1,    26,     1,    28,    29,    30,    57,    62,   139,
     140,    35,    62,     1,     1,    62,    17,    41,    42,     1,
      44,    45,    46,     1,    73,   226,    50,     1,    62,     1,
      17,    32,    56,    62,   226,    36,    60,    61,   398,   399,
      64,   203,    24,    96,    96,    32,   406,   226,   408,    36,
      74,    96,    96,    96,   226,   415,    34,    81,   418,    83,
     106,    85,   226,    87,    88,    89,   224,   226,   428,   429,
     228,    96,   126,   123,    96,   226,    58,   126,   438,   439,
     104,   441,   226,   126,     1,    94,   110,   111,   112,    96,
     114,   226,   126,   117,   118,    73,    96,   121,    15,    16,
      82,   126,    19,   194,    86,   158,   158,   226,   199,    96,
     226,   120,   167,   168,    96,   158,    98,    99,   119,    36,
     126,   224,    96,   227,    96,   228,   127,   128,   126,   226,
     224,   155,   119,   158,   228,   159,   158,   199,   162,   163,
     164,   165,   166,   139,   140,   169,   170,   134,   126,   185,
     186,   133,   158,   135,   136,   137,   138,   226,   158,   160,
     158,    78,    79,    80,     1,   226,     3,    84,     5,   222,
     530,   225,   154,    90,    91,   225,   225,   217,   225,    96,
      17,   225,     1,   223,   158,   225,   158,   211,   212,   213,
     107,   108,   216,   215,   224,    32,   178,   221,   228,    36,
     225,   225,    21,    22,   227,   122,   188,     1,    27,   215,
       1,   226,     1,   200,   215,   215,   225,   215,   225,   225,
      57,   224,    59,   227,   225,   225,   124,   224,   215,   217,
     223,   228,    69,   150,   594,   223,   218,   219,   225,   167,
     600,   601,   227,   225,   227,   605,    37,    36,    67,    68,
     222,   225,   227,   225,    92,    93,    75,    76,    77,    96,
      51,    52,    53,    54,    55,    13,   224,   224,    57,   224,
     228,   228,   224,    62,     1,   192,   228,   224,   224,    70,
     224,   228,   228,   102,   103,    33,   123,   227,     1,     1,
      17,   227,   227,     6,     7,    43,   115,   116,   227,    12,
      94,    49,   227,   227,     1,    32,   125,    20,   225,    36,
     124,   227,    24,    26,   151,    28,    29,    30,    66,    31,
      17,   227,    35,   227,   227,   227,   120,   227,    41,    42,
       1,    44,    45,    46,   123,    32,   227,    50,   227,    36,
     227,   178,   227,    56,   227,   227,   227,    60,    61,    97,
     227,    64,   227,    24,    40,   227,   227,   105,   227,   227,
     227,    74,   227,   227,   227,   227,     1,   227,    81,    96,
      83,   227,    85,   227,    87,    88,    89,    63,   227,    65,
     227,   218,   227,   227,    96,   227,   227,    58,   225,   224,
     167,   104,   119,   227,   142,   227,   227,   110,   111,   112,
     227,   114,    37,   227,   117,   118,   225,   134,   121,   227,
     227,    82,   227,   161,   227,    86,    51,    52,    53,    54,
      55,   227,   119,   109,   227,    96,   227,    98,    99,   227,
     127,   128,   227,   124,   225,    70,   106,   227,   106,   106,
     227,   227,   155,   227,   227,   227,   159,  1113,   227,   162,
     163,   164,   165,   166,     4,   227,   169,   170,   227,   227,
     208,   227,   133,   160,   135,   136,   137,   138,   227,   227,
       1,   227,     3,   200,     5,    25,   143,   144,   145,   146,
     147,   148,   149,   154,    65,   227,    17,   227,   215,   227,
      40,   227,   227,   227,   180,   181,   227,    47,   211,   212,
     213,    32,   227,   216,   227,    36,     1,   178,   221,   227,
     227,   227,   227,   227,   106,    65,   227,   188,   215,   227,
      15,    16,   227,   227,    19,   167,    57,   106,    59,   215,
     785,   786,   787,   788,   789,   790,   791,   106,    69,     0,
       1,    36,   106,     4,    94,   106,   167,   218,   219,   224,
     224,   101,   124,    14,   227,   227,    17,    18,   227,   224,
     141,   227,    23,   113,   227,    96,   227,   227,   227,   227,
     227,   227,   227,    34,   227,   227,    51,    38,    39,   227,
     130,   131,   132,    78,    79,    80,   227,    48,   227,    84,
     227,   172,   123,   227,   227,    90,    91,   227,   227,   227,
     181,    96,    63,   227,   227,   227,   187,   227,   227,   227,
      71,    72,   107,   108,    51,   224,   227,   227,   167,   106,
     151,   202,   167,   204,   205,   167,   106,   122,   124,   167,
     167,   181,   106,   214,    95,   106,   106,   167,   167,   220,
     167,   191,   106,    51,   106,   167,   196,   178,   109,   106,
     106,   106,   202,   106,   167,   150,   206,   227,   167,   209,
     227,   167,   167,   167,   214,   167,   167,   167,   167,   167,
     220,   224,   124,   167,   167,    65,   224,   224,   124,   124,
     141,   227,   167,   227,   227,   167,   227,   218,   227,   224,
     226,   152,   153,   227,   227,   156,   157,   192,   173,   174,
     175,   176,   177,   227,   179,   180,   227,   182,   183,   184,
     227,   227,   187,   227,   189,   190,   191,   224,   193,   227,
     195,   224,   197,   198,   124,   167,   201,   167,   167,   124,
     227,   167,   207,   224,   224,   227,   173,   174,   175,   176,
     177,   227,   179,   180,   227,   182,   183,   184,   227,   210,
     187,   141,   189,   190,   191,   227,   193,   106,   195,   227,
     197,   198,   227,   106,   201,   173,   174,   175,   176,   177,
     207,   179,   180,   124,   182,   183,   184,   124,   124,   187,
       1,   189,   172,   191,   124,   193,   124,   195,   124,   197,
     198,   181,   124,   201,   124,   106,   124,   187,   124,   207,
      21,    22,   224,   224,   227,   224,    27,   227,   124,   227,
     224,   224,   202,   224,   204,   205,   106,   224,   224,   224,
     224,   224,   224,   224,   214,   224,   224,   224,   224,   106,
     220,   224,   224,   224,   106,   106,   106,   106,   227,   124,
     106,   106,   106,   224,   124,   124,    67,    68,   167,   227,
     124,   124,   106,   224,    75,    76,    77,   124,   224,   224,
     227,   124,   124,   124,   124,   124,   124,   124,   124,   224,
     224,   224,   224,   124,   224,   124,   224,   106,   124,   224,
     224,   102,   103,   224,   167,   224,   124,   224,   124,   224,
     224,   224,   124,   224,   115,   116,   124,   224,   227,   224,
     224,   224,   224,   224,   125,   124,   224,   224,   124,   224,
     224,   224,   224,   106,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   124,   224,   224,   224,   124,   124,
     224,   227,   167,   224,   124,   227,   224,   124,   224,   224,
     124,   124,   124,   124,   124,   124,   106,    71,   963,   227,
    1001,  1003,   129,  1254,  1214,   505,  1226,  1224,   331,  1199,
     481,   224,   227,   129,   224,   227,   224,   224,   456,   224,
     224,   224,   224,   224,   224,   224,  1108,   224,  1210,   224,
     224,   224,   124,   224,   224,   557,   519,   224,   224,  1228,
     224,   224,   224,  1230,   224,   565,   224,   224,  1204,  1212,
     224,   224,   227,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   171,   224,   224,   110,   224,   224,   224,   471,   381,
     224,   224,   224,   224,   163,   224,   224,  1075,   224,   224,
    1206,    90,  1073,    -1,    -1,   267,   224,    -1,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,    -1,   224,
     218,   224,    -1,   393,   228,   227,   227,   224,   224,   224,
     224,   224,   224,   224,    -1,   224,   224,   224,   224,   224,
     224,    -1,    -1,   224,   227,   224,   224,   224,    -1,    -1,
     226,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   240,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   290,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   363
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   230,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    63,    71,    72,    95,   109,   141,   152,
     153,   156,   157,   210,   231,   236,   241,   265,   271,   285,
     303,   326,   340,   355,   362,   366,   376,   385,   405,   415,
     421,   425,   435,   492,   508,   224,   225,   226,   226,   304,
     386,   416,   226,   426,   226,   341,   406,   327,   226,   226,
     286,   356,   226,   226,   367,   377,   226,     1,    24,    31,
      96,   266,   267,   268,   269,   270,     1,    21,    22,    27,
      67,    68,    75,    76,    77,   102,   103,   115,   116,   125,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   226,   226,   226,     1,    62,
     422,   423,   424,   226,     1,     6,     7,    12,    20,    26,
      28,    29,    30,    35,    41,    42,    44,    45,    46,    50,
      56,    60,    61,    64,    74,    81,    83,    85,    87,    88,
      89,   104,   110,   111,   112,   114,   117,   118,   121,   155,
     159,   162,   163,   164,   165,   166,   169,   170,   211,   212,
     213,   216,   221,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   485,
     489,   490,   491,   226,   226,   226,     1,   217,   272,   273,
     274,   275,   276,     1,    94,   120,   237,   238,   239,   240,
     226,   226,     1,    37,    51,    52,    53,    54,    55,    70,
     509,   510,   511,   512,   513,   514,   515,   516,   517,     1,
      24,    58,    82,    86,    96,    98,    99,   133,   135,   136,
     137,   138,   154,   178,   188,   218,   219,   242,   243,   244,
     245,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   226,   226,     1,    96,
     363,   364,   365,   224,   227,   227,   227,   225,   267,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   225,   494,     1,    15,    16,    19,    36,    78,
      79,    80,    84,    90,    91,    96,   107,   108,   122,   150,
     192,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,     1,
       3,     5,    17,    32,    36,    57,    59,    69,    96,   123,
     151,   178,   218,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   400,   401,   402,   403,   404,     1,    62,
     126,   417,   418,   419,   420,   227,   225,   423,     1,    96,
     126,   158,   427,   431,   432,   433,   434,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   486,   227,   482,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   225,   437,     1,    17,    32,
      36,   119,   127,   128,   160,   215,   342,   343,   344,   345,
     346,   347,   348,   352,   353,   354,     1,   126,   158,   215,
     407,   411,   412,   413,   414,     1,    36,    57,    62,   123,
     328,   332,   333,   334,   338,   339,   224,   227,   225,   273,
     223,   224,   227,   227,   225,   238,     1,    17,    32,    36,
      96,   119,   134,   200,   215,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   299,     1,    34,    73,   126,   357,
     358,   359,   360,   361,   227,   227,   227,   227,   227,   227,
     227,   225,   510,   224,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   225,   243,     1,    96,   158,   215,   368,   369,   370,
     371,   372,     1,    96,   158,   378,   379,   380,   381,   227,
     225,   364,   124,   124,   124,   224,   106,   106,   167,   106,
     233,   233,   106,   106,   106,   167,   167,   106,   233,   167,
     224,   224,   227,   227,   227,   323,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   225,   306,
     224,   227,   227,   227,   227,   397,   227,   227,   227,   227,
     227,   227,   227,   227,   225,   388,   227,   227,   225,   418,
     124,   224,   227,   227,   428,   225,   432,   167,   233,   233,
     106,   167,   167,   106,   124,   167,   233,   167,   233,   106,
     106,   106,   167,   167,   167,   233,   106,   106,   233,   106,
     106,   106,   106,   167,   167,   227,   167,   227,   233,   233,
     167,   167,   167,   167,   167,   168,   167,   168,   167,   167,
     233,   233,   124,   233,   167,   167,   167,   224,   224,   227,
     227,   349,   227,   227,   227,   227,   227,   225,   343,   227,
     408,   227,   225,   412,   224,   329,   227,   227,   227,   225,
     333,   167,   224,   226,   124,   124,   224,   224,   227,   227,
     300,   227,   227,   227,   296,   227,   225,   288,   224,   227,
     227,   227,   225,   358,   167,   167,   124,   167,   167,   167,
     233,   224,   124,   167,   106,   106,   124,   124,   124,   124,
     124,   124,   139,   140,   246,   247,   139,   140,   248,   249,
     124,   124,   106,   124,   124,   224,   224,   227,   373,   227,
     225,   369,   224,   227,   382,   225,   379,   124,   224,   224,
     224,   224,   224,   224,   224,   143,   144,   145,   146,   147,
     148,   149,   232,   233,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   106,   106,   233,   227,   106,   106,
     106,   106,   233,   233,   124,   106,   106,   233,   106,   235,
     235,   224,   124,   185,   186,   124,   167,   227,   124,   124,
     124,   124,   106,   124,   124,   124,   224,   124,   124,   224,
     224,   124,   124,   227,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,    51,   173,   174,   175,   176,   177,   179,
     180,   182,   183,   184,   187,   189,   190,   191,   193,   195,
     197,   198,   201,   207,   487,   488,   224,    51,   173,   174,
     175,   176,   177,   179,   180,   182,   183,   184,   187,   189,
     191,   193,   195,   197,   198,   201,   207,   483,   484,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   124,   167,
     227,   124,   106,   124,   124,   124,   224,   124,   227,   124,
     224,   227,   124,   124,   106,   336,   337,   224,   224,     1,
      96,   158,   222,   277,   278,   279,   280,   281,   224,   224,
     124,   167,   227,   124,   124,   124,   227,   124,   224,   124,
     124,   124,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   228,   224,   228,   224,   224,   224,   224,   224,   124,
     227,   124,   224,   124,   227,   224,   224,   232,   232,   232,
     232,   232,   232,   232,   224,   224,   224,    92,    93,   324,
     325,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,     9,    10,    11,   234,   235,   224,   224,   224,   224,
     224,   224,   224,     8,   199,   398,   399,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   129,
     429,   430,   224,   228,   224,   228,   224,   224,    13,    33,
      43,    49,    66,    97,   105,   142,   161,   208,   350,   351,
     224,   224,   224,   224,   224,   224,   129,   409,   410,   224,
      51,   194,   199,   330,   331,   224,   224,   171,   228,   335,
     224,   227,   282,   227,   225,   278,   224,   224,     4,    25,
      40,    47,    65,    94,   101,   113,   130,   131,   132,   181,
     191,   196,   202,   206,   209,   214,   220,   301,   302,   224,
     224,   224,    51,   173,   174,   175,   176,   177,   179,   180,
     182,   183,   184,   187,   189,   190,   191,   193,   195,   197,
     198,   201,   207,   297,   298,   224,   224,   224,   224,   247,
     249,   224,    65,   141,   172,   181,   187,   202,   204,   205,
     214,   220,   374,   375,   224,   224,    65,   141,   172,   181,
     187,   202,   204,   205,   214,   220,   383,   384,   224,   228,
     234,   234,   234,   224,   228,   224,   228,   488,   484,   224,
     228,   224,   228,   224,   228,   106,   337,   224,   124,   227,
     203,   235,   224,   224,   228,   224,   228,   224,   228,   224,
     228,   325,   399,   430,   351,   410,   331,   224,    40,    63,
      65,   109,   180,   181,   215,   283,   284,   224,   224,   302,
     298,   375,   384,   224,   228,   284
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
#line 394 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 396 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 400 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 404 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 412 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 416 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 420 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 424 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 431 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 433 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 447 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 479 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 485 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 494 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 500 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 508 "conf_parser.y"
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
#line 550 "conf_parser.y"
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
#line 609 "conf_parser.y"
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
#line 637 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 645 "conf_parser.y"
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
#line 660 "conf_parser.y"
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
#line 675 "conf_parser.y"
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
#line 684 "conf_parser.y"
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
#line 698 "conf_parser.y"
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
#line 707 "conf_parser.y"
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
#line 735 "conf_parser.y"
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
#line 765 "conf_parser.y"
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
#line 790 "conf_parser.y"
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
#line 812 "conf_parser.y"
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
#line 834 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 849 "conf_parser.y"
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
#line 858 "conf_parser.y"
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
#line 867 "conf_parser.y"
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
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 891 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 895 "conf_parser.y"
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
#line 911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 919 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 922 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 946 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 950 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 954 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 958 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 975 "conf_parser.y"
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
#line 1050 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1056 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1062 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1068 "conf_parser.y"
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
#line 1079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1085 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1106 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1110 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1126 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1130 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1134 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1138 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1150 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1154 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1158 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1166 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1174 "conf_parser.y"
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
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1215 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1239 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_N;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1243 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1263 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
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

  case 203:
/* Line 1787 of yacc.c  */
#line 1285 "conf_parser.y"
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

  case 223:
/* Line 1787 of yacc.c  */
#line 1351 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1357 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1375 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1387 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1393 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1399 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1455 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1475 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1481 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1485 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1489 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1497 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1502 "conf_parser.y"
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

  case 265:
/* Line 1787 of yacc.c  */
#line 1516 "conf_parser.y"
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
#line 1542 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1551 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1555 "conf_parser.y"
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

  case 281:
/* Line 1787 of yacc.c  */
#line 1598 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1604 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1610 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1616 "conf_parser.y"
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

  case 285:
/* Line 1787 of yacc.c  */
#line 1627 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1634 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1638 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1642 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1646 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1650 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1658 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1662 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1666 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1670 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1676 "conf_parser.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 1690 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1699 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 1719 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
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
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1742 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1757 "conf_parser.y"
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

  case 319:
/* Line 1787 of yacc.c  */
#line 1772 "conf_parser.y"
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

  case 320:
/* Line 1787 of yacc.c  */
#line 1783 "conf_parser.y"
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

  case 327:
/* Line 1787 of yacc.c  */
#line 1800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1806 "conf_parser.y"
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

  case 329:
/* Line 1787 of yacc.c  */
#line 1825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1832 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1836 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 335:
/* Line 1787 of yacc.c  */
#line 1840 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1844 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1852 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1856 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1868 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1877 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1886 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 1901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 1946 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 1950 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1959 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 1967 "conf_parser.y"
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

  case 383:
/* Line 1787 of yacc.c  */
#line 2033 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2039 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 385:
/* Line 1787 of yacc.c  */
#line 2045 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2051 "conf_parser.y"
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

  case 387:
/* Line 1787 of yacc.c  */
#line 2064 "conf_parser.y"
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

  case 388:
/* Line 1787 of yacc.c  */
#line 2077 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 2087 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2095 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 2101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 2105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 397:
/* Line 1787 of yacc.c  */
#line 2111 "conf_parser.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 2122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2134 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2140 "conf_parser.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 2155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2159 "conf_parser.y"
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

  case 404:
/* Line 1787 of yacc.c  */
#line 2217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2233 "conf_parser.y"
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

  case 416:
/* Line 1787 of yacc.c  */
#line 2253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2266 "conf_parser.y"
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

  case 424:
/* Line 1787 of yacc.c  */
#line 2292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 425:
/* Line 1787 of yacc.c  */
#line 2298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2312 "conf_parser.y"
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

  case 432:
/* Line 1787 of yacc.c  */
#line 2329 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 2333 "conf_parser.y"
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

  case 434:
/* Line 1787 of yacc.c  */
#line 2374 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 438:
/* Line 1787 of yacc.c  */
#line 2381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 446:
/* Line 1787 of yacc.c  */
#line 2396 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2440 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2457 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2463 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2468 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2473 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2478 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2483 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2488 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2493 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2498 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2508 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2513 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2518 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2523 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2528 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2533 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2539 "conf_parser.y"
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

  case 519:
/* Line 1787 of yacc.c  */
#line 2550 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2578 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2583 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2586 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2591 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2596 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2606 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2611 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2621 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2626 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2631 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2636 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2641 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2646 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2655 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2664 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2669 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2753 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2759 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2768 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2771 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2807 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2818 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 2851 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 2930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 638:
/* Line 1787 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 639:
/* Line 1787 of yacc.c  */
#line 2942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 640:
/* Line 1787 of yacc.c  */
#line 2948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 2957 "conf_parser.y"
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

  case 642:
/* Line 1787 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 2977 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6816 "conf_parser.c"
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


