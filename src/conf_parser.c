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
     NO_CREATE_ON_SPLIT = 356,
     NO_JOIN_ON_SPLIT = 357,
     NO_OPER_FLOOD = 358,
     NO_TILDE = 359,
     NUMBER = 360,
     NUMBER_PER_CIDR = 361,
     NUMBER_PER_IP = 362,
     OPERATOR = 363,
     OPERS_BYPASS_CALLERID = 364,
     OPER_ONLY_UMODES = 365,
     OPER_PASS_RESV = 366,
     OPER_SPY_T = 367,
     OPER_UMODES = 368,
     JOIN_FLOOD_COUNT = 369,
     JOIN_FLOOD_TIME = 370,
     PACE_WAIT = 371,
     PACE_WAIT_SIMPLE = 372,
     PASSWORD = 373,
     PATH = 374,
     PING_COOKIE = 375,
     PING_TIME = 376,
     PORT = 377,
     QSTRING = 378,
     REASON = 379,
     REDIRPORT = 380,
     REDIRSERV = 381,
     REHASH = 382,
     REMOTE = 383,
     REMOTEBAN = 384,
     RSA_PRIVATE_KEY_FILE = 385,
     RSA_PUBLIC_KEY_FILE = 386,
     SSL_CERTIFICATE_FILE = 387,
     SSL_DH_PARAM_FILE = 388,
     T_SSL_CLIENT_METHOD = 389,
     T_SSL_SERVER_METHOD = 390,
     T_SSLV3 = 391,
     T_TLSV1 = 392,
     RESV = 393,
     RESV_EXEMPT = 394,
     SECONDS = 395,
     MINUTES = 396,
     HOURS = 397,
     DAYS = 398,
     WEEKS = 399,
     MONTHS = 400,
     YEARS = 401,
     SENDQ = 402,
     SEND_PASSWORD = 403,
     SERVERHIDE = 404,
     SERVERINFO = 405,
     IRCD_SID = 406,
     TKLINE_EXPIRE_NOTICES = 407,
     T_SHARED = 408,
     T_CLUSTER = 409,
     TYPE = 410,
     SHORT_MOTD = 411,
     SPOOF = 412,
     SPOOF_NOTICE = 413,
     STATS_E_DISABLED = 414,
     STATS_I_OPER_ONLY = 415,
     STATS_K_OPER_ONLY = 416,
     STATS_O_OPER_ONLY = 417,
     STATS_P_OPER_ONLY = 418,
     TBOOL = 419,
     TMASKED = 420,
     TS_MAX_DELTA = 421,
     TS_WARN_DELTA = 422,
     TWODOTS = 423,
     T_ALL = 424,
     T_BOTS = 425,
     T_SOFTCALLERID = 426,
     T_CALLERID = 427,
     T_CCONN = 428,
     T_CCONN_FULL = 429,
     T_SSL_CIPHER_LIST = 430,
     T_DEAF = 431,
     T_DEBUG = 432,
     T_DLINE = 433,
     T_EXTERNAL = 434,
     T_FULL = 435,
     T_INVISIBLE = 436,
     T_IPV4 = 437,
     T_IPV6 = 438,
     T_LOCOPS = 439,
     T_MAX_CLIENTS = 440,
     T_NCHANGE = 441,
     T_NONONREG = 442,
     T_OPERWALL = 443,
     T_RECVQ = 444,
     T_REJ = 445,
     T_SERVER = 446,
     T_SERVNOTICE = 447,
     T_SET = 448,
     T_SKILL = 449,
     T_SPY = 450,
     T_SSL = 451,
     T_UMODES = 452,
     T_UNAUTH = 453,
     T_UNDLINE = 454,
     T_UNLIMITED = 455,
     T_UNRESV = 456,
     T_UNXLINE = 457,
     T_GLOBOPS = 458,
     T_WALLOP = 459,
     T_WEBIRC = 460,
     T_RESTART = 461,
     T_SERVICE = 462,
     T_SERVICES_NAME = 463,
     THROTTLE_TIME = 464,
     TRUE_NO_OPER_FLOOD = 465,
     UNKLINE = 466,
     USER = 467,
     USE_EGD = 468,
     USE_LOGGING = 469,
     VHOST = 470,
     VHOST6 = 471,
     XLINE = 472,
     WARN_NO_NLINE = 473,
     T_SIZE = 474,
     T_FILE = 475
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
#define NO_CREATE_ON_SPLIT 356
#define NO_JOIN_ON_SPLIT 357
#define NO_OPER_FLOOD 358
#define NO_TILDE 359
#define NUMBER 360
#define NUMBER_PER_CIDR 361
#define NUMBER_PER_IP 362
#define OPERATOR 363
#define OPERS_BYPASS_CALLERID 364
#define OPER_ONLY_UMODES 365
#define OPER_PASS_RESV 366
#define OPER_SPY_T 367
#define OPER_UMODES 368
#define JOIN_FLOOD_COUNT 369
#define JOIN_FLOOD_TIME 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PORT 377
#define QSTRING 378
#define REASON 379
#define REDIRPORT 380
#define REDIRSERV 381
#define REHASH 382
#define REMOTE 383
#define REMOTEBAN 384
#define RSA_PRIVATE_KEY_FILE 385
#define RSA_PUBLIC_KEY_FILE 386
#define SSL_CERTIFICATE_FILE 387
#define SSL_DH_PARAM_FILE 388
#define T_SSL_CLIENT_METHOD 389
#define T_SSL_SERVER_METHOD 390
#define T_SSLV3 391
#define T_TLSV1 392
#define RESV 393
#define RESV_EXEMPT 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define MONTHS 400
#define YEARS 401
#define SENDQ 402
#define SEND_PASSWORD 403
#define SERVERHIDE 404
#define SERVERINFO 405
#define IRCD_SID 406
#define TKLINE_EXPIRE_NOTICES 407
#define T_SHARED 408
#define T_CLUSTER 409
#define TYPE 410
#define SHORT_MOTD 411
#define SPOOF 412
#define SPOOF_NOTICE 413
#define STATS_E_DISABLED 414
#define STATS_I_OPER_ONLY 415
#define STATS_K_OPER_ONLY 416
#define STATS_O_OPER_ONLY 417
#define STATS_P_OPER_ONLY 418
#define TBOOL 419
#define TMASKED 420
#define TS_MAX_DELTA 421
#define TS_WARN_DELTA 422
#define TWODOTS 423
#define T_ALL 424
#define T_BOTS 425
#define T_SOFTCALLERID 426
#define T_CALLERID 427
#define T_CCONN 428
#define T_CCONN_FULL 429
#define T_SSL_CIPHER_LIST 430
#define T_DEAF 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_EXTERNAL 434
#define T_FULL 435
#define T_INVISIBLE 436
#define T_IPV4 437
#define T_IPV6 438
#define T_LOCOPS 439
#define T_MAX_CLIENTS 440
#define T_NCHANGE 441
#define T_NONONREG 442
#define T_OPERWALL 443
#define T_RECVQ 444
#define T_REJ 445
#define T_SERVER 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SKILL 449
#define T_SPY 450
#define T_SSL 451
#define T_UMODES 452
#define T_UNAUTH 453
#define T_UNDLINE 454
#define T_UNLIMITED 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_GLOBOPS 458
#define T_WALLOP 459
#define T_WEBIRC 460
#define T_RESTART 461
#define T_SERVICE 462
#define T_SERVICES_NAME 463
#define THROTTLE_TIME 464
#define TRUE_NO_OPER_FLOOD 465
#define UNKLINE 466
#define USER 467
#define USE_EGD 468
#define USE_LOGGING 469
#define VHOST 470
#define VHOST6 471
#define XLINE 472
#define WARN_NO_NLINE 473
#define T_SIZE 474
#define T_FILE 475



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 670 "conf_parser.c"
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
#line 698 "conf_parser.c"

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
#define YYLAST   1177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  226
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  628
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1230

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   475

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   225,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   221,
       2,   224,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   223,     2,   222,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220
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
    1185,  1190,  1191,  1198,  1201,  1203,  1205,  1207,  1209,  1214,
    1219,  1220,  1227,  1230,  1232,  1234,  1236,  1238,  1243,  1248,
    1254,  1257,  1259,  1261,  1263,  1268,  1269,  1276,  1279,  1281,
    1283,  1285,  1287,  1292,  1297,  1303,  1306,  1308,  1310,  1312,
    1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,  1332,
    1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,  1352,
    1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,  1372,
    1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,
    1394,  1396,  1398,  1400,  1402,  1404,  1406,  1411,  1416,  1421,
    1426,  1431,  1436,  1441,  1446,  1451,  1456,  1461,  1466,  1471,
    1476,  1481,  1486,  1491,  1496,  1501,  1506,  1511,  1516,  1521,
    1526,  1531,  1536,  1541,  1546,  1551,  1556,  1561,  1566,  1571,
    1576,  1581,  1586,  1591,  1596,  1601,  1606,  1611,  1616,  1621,
    1626,  1631,  1632,  1638,  1642,  1644,  1646,  1648,  1650,  1652,
    1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,  1672,
    1674,  1676,  1678,  1680,  1682,  1684,  1685,  1691,  1695,  1697,
    1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,  1717,
    1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,
    1739,  1744,  1749,  1754,  1760,  1763,  1765,  1767,  1769,  1771,
    1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,
    1796,  1801,  1806,  1811,  1816,  1821,  1826,  1831,  1836,  1841,
    1846,  1851,  1857,  1860,  1862,  1864,  1866,  1868,  1870,  1872,
    1874,  1876,  1878,  1883,  1888,  1893,  1898,  1903,  1908
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     227,     0,    -1,    -1,   227,   228,    -1,   262,    -1,   268,
      -1,   282,    -1,   481,    -1,   300,    -1,   323,    -1,   337,
      -1,   238,    -1,   496,    -1,   352,    -1,   359,    -1,   363,
      -1,   373,    -1,   382,    -1,   402,    -1,   408,    -1,   414,
      -1,   424,    -1,   418,    -1,   233,    -1,     1,   221,    -1,
       1,   222,    -1,    -1,   230,    -1,   105,   229,    -1,   105,
     140,   229,    -1,   105,   141,   229,    -1,   105,   142,   229,
      -1,   105,   143,   229,    -1,   105,   144,   229,    -1,   105,
     145,   229,    -1,   105,   146,   229,    -1,    -1,   232,    -1,
     105,   231,    -1,   105,     9,   231,    -1,   105,    10,   231,
      -1,   105,    11,   231,    -1,    95,   223,   234,   222,   221,
      -1,   234,   235,    -1,   235,    -1,   236,    -1,   237,    -1,
       1,   221,    -1,    94,   224,   123,   221,    -1,   119,   224,
     123,   221,    -1,   150,   223,   239,   222,   221,    -1,   239,
     240,    -1,   240,    -1,   251,    -1,   256,    -1,   261,    -1,
     253,    -1,   254,    -1,   255,    -1,   258,    -1,   259,    -1,
     260,    -1,   249,    -1,   248,    -1,   257,    -1,   252,    -1,
     247,    -1,   241,    -1,   242,    -1,   250,    -1,     1,   221,
      -1,   134,   224,   243,   221,    -1,   135,   224,   245,   221,
      -1,   243,   225,   244,    -1,   244,    -1,   136,    -1,   137,
      -1,   245,   225,   246,    -1,   246,    -1,   136,    -1,   137,
      -1,   132,   224,   123,   221,    -1,   130,   224,   123,   221,
      -1,   133,   224,   123,   221,    -1,   175,   224,   123,   221,
      -1,    96,   224,   123,   221,    -1,   151,   224,   123,   221,
      -1,    24,   224,   123,   221,    -1,    99,   224,   123,   221,
      -1,    98,   224,   123,   221,    -1,   215,   224,   123,   221,
      -1,   216,   224,   123,   221,    -1,   185,   224,   105,   221,
      -1,    82,   224,   105,   221,    -1,    86,   224,   105,   221,
      -1,    58,   224,   164,   221,    -1,     4,   223,   263,   222,
     221,    -1,   263,   264,    -1,   264,    -1,   265,    -1,   267,
      -1,   266,    -1,     1,   221,    -1,    96,   224,   123,   221,
      -1,    31,   224,   123,   221,    -1,    24,   224,   123,   221,
      -1,    72,   223,   269,   222,   221,    -1,   269,   270,    -1,
     270,    -1,   271,    -1,   272,    -1,     1,   221,    -1,   214,
     224,   164,   221,    -1,    -1,   273,   220,   223,   274,   222,
     221,    -1,   274,   275,    -1,   275,    -1,   276,    -1,   278,
      -1,   277,    -1,     1,   221,    -1,    96,   224,   123,   221,
      -1,   219,   224,   232,   221,    -1,   219,   224,   200,   221,
      -1,    -1,   155,   279,   224,   280,   221,    -1,   280,   225,
     281,    -1,   281,    -1,   212,    -1,   108,    -1,    40,    -1,
     178,    -1,    65,    -1,    63,    -1,   177,    -1,    -1,   108,
     283,   223,   284,   222,   221,    -1,   284,   285,    -1,   285,
      -1,   286,    -1,   287,    -1,   288,    -1,   292,    -1,   291,
      -1,   289,    -1,   290,    -1,   296,    -1,     1,   221,    -1,
      96,   224,   123,   221,    -1,   212,   224,   123,   221,    -1,
     118,   224,   123,   221,    -1,    32,   224,   164,   221,    -1,
     131,   224,   123,   221,    -1,    17,   224,   123,   221,    -1,
      -1,   197,   293,   224,   294,   221,    -1,   294,   225,   295,
      -1,   295,    -1,   170,    -1,   173,    -1,   174,    -1,   176,
      -1,   177,    -1,   180,    -1,    51,    -1,   194,    -1,   186,
      -1,   190,    -1,   198,    -1,   195,    -1,   179,    -1,   188,
      -1,   192,    -1,   181,    -1,   204,    -1,   171,    -1,   172,
      -1,   184,    -1,   187,    -1,    -1,    36,   297,   224,   298,
     221,    -1,   298,   225,   299,    -1,   299,    -1,    47,    -1,
     128,    -1,    65,    -1,   211,    -1,   178,    -1,   199,    -1,
     217,    -1,    40,    -1,    25,    -1,   206,    -1,   127,    -1,
       4,    -1,   188,    -1,   203,    -1,   112,    -1,   129,    -1,
     193,    -1,    94,    -1,    -1,    17,   301,   223,   302,   222,
     221,    -1,   302,   303,    -1,   303,    -1,   304,    -1,   314,
      -1,   315,    -1,   305,    -1,   316,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,   312,
      -1,   313,    -1,   317,    -1,   318,    -1,   319,    -1,     1,
     221,    -1,    96,   224,   123,   221,    -1,   121,   224,   230,
     221,    -1,   107,   224,   105,   221,    -1,    19,   224,   230,
     221,    -1,    84,   224,   105,   221,    -1,    78,   224,   105,
     221,    -1,    80,   224,   105,   221,    -1,    79,   224,   105,
     221,    -1,   147,   224,   232,   221,    -1,   189,   224,   232,
     221,    -1,    15,   224,   105,   221,    -1,    16,   224,   105,
     221,    -1,   106,   224,   105,   221,    -1,    90,   224,   230,
     221,    -1,    91,   224,   230,   221,    -1,    -1,    36,   320,
     224,   321,   221,    -1,   321,   225,   322,    -1,   322,    -1,
      92,    -1,    93,    -1,    -1,    71,   324,   223,   329,   222,
     221,    -1,    -1,    36,   326,   224,   327,   221,    -1,   327,
     225,   328,    -1,   328,    -1,   196,    -1,    51,    -1,   191,
      -1,   329,   330,    -1,   330,    -1,   331,    -1,   325,    -1,
     335,    -1,   336,    -1,     1,   221,    -1,    -1,   122,   224,
     333,   332,   221,    -1,   333,   225,   334,    -1,   334,    -1,
     105,    -1,   105,   168,   105,    -1,    62,   224,   123,   221,
      -1,    57,   224,   123,   221,    -1,    -1,    48,   338,   223,
     339,   222,   221,    -1,   339,   340,    -1,   340,    -1,   341,
      -1,   342,    -1,   343,    -1,   345,    -1,   349,    -1,   350,
      -1,   351,    -1,   344,    -1,     1,   221,    -1,   212,   224,
     123,   221,    -1,   118,   224,   123,   221,    -1,    17,   224,
     123,   221,    -1,    32,   224,   164,   221,    -1,    -1,    36,
     346,   224,   347,   221,    -1,   347,   225,   348,    -1,   348,
      -1,   158,    -1,    33,    -1,    66,    -1,    49,    -1,    13,
      -1,   104,    -1,    43,    -1,   139,    -1,   205,    -1,    97,
      -1,   157,   224,   123,   221,    -1,   126,   224,   123,   221,
      -1,   125,   224,   105,   221,    -1,    -1,   138,   353,   223,
     354,   222,   221,    -1,   354,   355,    -1,   355,    -1,   356,
      -1,   357,    -1,   358,    -1,     1,   221,    -1,    73,   224,
     123,   221,    -1,   124,   224,   123,   221,    -1,    34,   224,
     123,   221,    -1,   207,   223,   360,   222,   221,    -1,   360,
     361,    -1,   361,    -1,   362,    -1,     1,    -1,    96,   224,
     123,   221,    -1,    -1,   153,   364,   223,   365,   222,   221,
      -1,   365,   366,    -1,   366,    -1,   367,    -1,   368,    -1,
     369,    -1,     1,   221,    -1,    96,   224,   123,   221,    -1,
     212,   224,   123,   221,    -1,    -1,   155,   370,   224,   371,
     221,    -1,   371,   225,   372,    -1,   372,    -1,    65,    -1,
     211,    -1,   178,    -1,   199,    -1,   217,    -1,   202,    -1,
     138,    -1,   201,    -1,   184,    -1,   169,    -1,    -1,   154,
     374,   223,   375,   222,   221,    -1,   375,   376,    -1,   376,
      -1,   377,    -1,   378,    -1,     1,   221,    -1,    96,   224,
     123,   221,    -1,    -1,   155,   379,   224,   380,   221,    -1,
     380,   225,   381,    -1,   381,    -1,    65,    -1,   211,    -1,
     178,    -1,   199,    -1,   217,    -1,   202,    -1,   138,    -1,
     201,    -1,   184,    -1,   169,    -1,    -1,    18,   383,   223,
     384,   222,   221,    -1,   384,   385,    -1,   385,    -1,   386,
      -1,   387,    -1,   388,    -1,   389,    -1,   390,    -1,   392,
      -1,   391,    -1,   401,    -1,   393,    -1,   398,    -1,   399,
      -1,   400,    -1,   397,    -1,     1,   221,    -1,    96,   224,
     123,   221,    -1,    57,   224,   123,   221,    -1,   215,   224,
     123,   221,    -1,   148,   224,   123,   221,    -1,     3,   224,
     123,   221,    -1,   122,   224,   105,   221,    -1,     5,   224,
     182,   221,    -1,     5,   224,   183,   221,    -1,    -1,    36,
     394,   224,   395,   221,    -1,   395,   225,   396,    -1,   396,
      -1,     8,    -1,   196,    -1,    32,   224,   164,   221,    -1,
      59,   224,   123,   221,    -1,    69,   224,   123,   221,    -1,
      17,   224,   123,   221,    -1,   175,   224,   123,   221,    -1,
      -1,    63,   403,   223,   404,   222,   221,    -1,   404,   405,
      -1,   405,    -1,   406,    -1,   407,    -1,     1,    -1,   212,
     224,   123,   221,    -1,   124,   224,   123,   221,    -1,    -1,
      23,   409,   223,   410,   222,   221,    -1,   410,   411,    -1,
     411,    -1,   412,    -1,   413,    -1,     1,    -1,    62,   224,
     123,   221,    -1,   124,   224,   123,   221,    -1,    34,   223,
     415,   222,   221,    -1,   415,   416,    -1,   416,    -1,   417,
      -1,     1,    -1,    62,   224,   123,   221,    -1,    -1,    38,
     419,   223,   420,   222,   221,    -1,   420,   421,    -1,   421,
      -1,   422,    -1,   423,    -1,     1,    -1,    96,   224,   123,
     221,    -1,   124,   224,   123,   221,    -1,    39,   223,   425,
     222,   221,    -1,   425,   426,    -1,   426,    -1,   435,    -1,
     436,    -1,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     442,    -1,   443,    -1,   444,    -1,   445,    -1,   434,    -1,
     447,    -1,   448,    -1,   462,    -1,   450,    -1,   452,    -1,
     454,    -1,   453,    -1,   457,    -1,   451,    -1,   458,    -1,
     459,    -1,   460,    -1,   461,    -1,   474,    -1,   463,    -1,
     464,    -1,   465,    -1,   470,    -1,   455,    -1,   456,    -1,
     480,    -1,   478,    -1,   479,    -1,   437,    -1,   469,    -1,
     446,    -1,   467,    -1,   468,    -1,   433,    -1,   428,    -1,
     429,    -1,   430,    -1,   431,    -1,   432,    -1,   449,    -1,
     427,    -1,   466,    -1,     1,    -1,    87,   224,   105,   221,
      -1,    42,   224,   164,   221,    -1,    41,   224,   230,   221,
      -1,    44,   224,   230,   221,    -1,    45,   224,   105,   221,
      -1,    46,   224,   105,   221,    -1,   152,   224,   164,   221,
      -1,    64,   224,   230,   221,    -1,    56,   224,   164,   221,
      -1,    60,   224,   164,   221,    -1,    28,   224,   164,   221,
      -1,    35,   224,   164,   221,    -1,     6,   224,   164,   221,
      -1,    83,   224,   230,   221,    -1,    81,   224,   105,   221,
      -1,    74,   224,   105,   221,    -1,     7,   224,   230,   221,
      -1,   167,   224,   230,   221,    -1,   166,   224,   230,   221,
      -1,    50,   224,   105,   221,    -1,    61,   224,   164,   221,
      -1,   218,   224,   164,   221,    -1,   159,   224,   164,   221,
      -1,   162,   224,   164,   221,    -1,   163,   224,   164,   221,
      -1,   161,   224,   164,   221,    -1,   161,   224,   165,   221,
      -1,   160,   224,   164,   221,    -1,   160,   224,   165,   221,
      -1,   116,   224,   230,   221,    -1,    12,   224,   230,   221,
      -1,   109,   224,   164,   221,    -1,   117,   224,   230,   221,
      -1,   156,   224,   164,   221,    -1,   103,   224,   164,   221,
      -1,   210,   224,   164,   221,    -1,   111,   224,   164,   221,
      -1,    29,   224,   105,   221,    -1,    85,   224,   105,   221,
      -1,   213,   224,   164,   221,    -1,    30,   224,   123,   221,
      -1,   208,   224,   123,   221,    -1,   120,   224,   164,   221,
      -1,    26,   224,   164,   221,    -1,   209,   224,   230,   221,
      -1,    -1,   113,   471,   224,   472,   221,    -1,   472,   225,
     473,    -1,   473,    -1,   170,    -1,   173,    -1,   174,    -1,
     176,    -1,   177,    -1,   180,    -1,    51,    -1,   194,    -1,
     186,    -1,   190,    -1,   198,    -1,   195,    -1,   179,    -1,
     188,    -1,   192,    -1,   181,    -1,   204,    -1,   171,    -1,
     172,    -1,   184,    -1,    -1,   110,   475,   224,   476,   221,
      -1,   476,   225,   477,    -1,   477,    -1,   170,    -1,   173,
      -1,   174,    -1,   176,    -1,   177,    -1,   180,    -1,   194,
      -1,    51,    -1,   186,    -1,   190,    -1,   198,    -1,   195,
      -1,   179,    -1,   188,    -1,   192,    -1,   181,    -1,   204,
      -1,   171,    -1,   172,    -1,   184,    -1,   187,    -1,    88,
     224,   105,   221,    -1,    89,   224,   105,   221,    -1,    20,
     224,   105,   221,    -1,    14,   223,   482,   222,   221,    -1,
     482,   483,    -1,   483,    -1,   489,    -1,   485,    -1,   486,
      -1,   487,    -1,   488,    -1,   490,    -1,   491,    -1,   492,
      -1,   493,    -1,   494,    -1,   495,    -1,   484,    -1,     1,
      -1,    27,   224,   164,   221,    -1,    67,   224,   230,   221,
      -1,    68,   224,   230,   221,    -1,    77,   224,   105,   221,
      -1,    76,   224,   105,   221,    -1,    75,   224,   105,   221,
      -1,    22,   224,   105,   221,    -1,    21,   224,   105,   221,
      -1,   101,   224,   164,   221,    -1,   102,   224,   164,   221,
      -1,   114,   224,   105,   221,    -1,   115,   224,   230,   221,
      -1,   149,   223,   497,   222,   221,    -1,   497,   498,    -1,
     498,    -1,   499,    -1,   500,    -1,   501,    -1,   503,    -1,
     504,    -1,   502,    -1,   505,    -1,     1,    -1,    37,   224,
     164,   221,    -1,    54,   224,   164,   221,    -1,    55,   224,
     164,   221,    -1,    52,   224,   123,   221,    -1,    70,   224,
     230,   221,    -1,    51,   224,   164,   221,    -1,    53,   224,
     164,   221,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   362,   362,   363,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   378,   379,   380,   381,
     382,   383,   384,   385,   386,   387,   391,   391,   392,   396,
     400,   404,   408,   412,   416,   420,   426,   426,   427,   428,
     429,   430,   437,   440,   440,   441,   441,   441,   443,   449,
     456,   458,   458,   459,   459,   460,   460,   461,   461,   462,
     462,   463,   463,   464,   464,   465,   465,   466,   466,   467,
     468,   471,   472,   474,   474,   475,   481,   489,   489,   490,
     496,   504,   546,   605,   633,   641,   656,   671,   680,   694,
     703,   731,   761,   786,   808,   830,   839,   841,   841,   842,
     842,   843,   843,   845,   854,   863,   875,   876,   876,   878,
     878,   879,   881,   888,   888,   901,   902,   904,   904,   905,
     905,   907,   915,   918,   924,   923,   929,   929,   930,   934,
     938,   942,   946,   950,   954,   965,   964,  1041,  1041,  1042,
    1042,  1042,  1043,  1043,  1043,  1044,  1044,  1044,  1046,  1052,
    1058,  1064,  1075,  1081,  1088,  1087,  1093,  1093,  1094,  1098,
    1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,  1134,  1138,
    1142,  1146,  1150,  1154,  1158,  1162,  1166,  1170,  1174,  1181,
    1180,  1186,  1186,  1187,  1191,  1195,  1199,  1203,  1207,  1211,
    1215,  1219,  1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,
    1255,  1266,  1265,  1326,  1326,  1327,  1328,  1328,  1329,  1330,
    1331,  1332,  1333,  1334,  1335,  1336,  1337,  1337,  1338,  1339,
    1340,  1341,  1343,  1349,  1355,  1361,  1367,  1373,  1379,  1385,
    1391,  1397,  1404,  1410,  1416,  1422,  1431,  1441,  1440,  1446,
    1446,  1447,  1451,  1462,  1461,  1468,  1467,  1472,  1472,  1473,
    1477,  1481,  1487,  1487,  1488,  1488,  1488,  1488,  1488,  1490,
    1490,  1492,  1492,  1494,  1508,  1528,  1534,  1544,  1543,  1585,
    1585,  1586,  1586,  1586,  1586,  1587,  1587,  1587,  1588,  1588,
    1590,  1596,  1602,  1608,  1620,  1619,  1625,  1625,  1626,  1630,
    1634,  1638,  1642,  1646,  1650,  1654,  1658,  1662,  1668,  1682,
    1691,  1705,  1704,  1719,  1719,  1720,  1720,  1720,  1720,  1722,
    1728,  1734,  1744,  1746,  1746,  1747,  1747,  1749,  1765,  1764,
    1789,  1789,  1790,  1790,  1790,  1790,  1792,  1798,  1818,  1817,
    1823,  1823,  1824,  1828,  1832,  1836,  1840,  1844,  1848,  1852,
    1856,  1860,  1870,  1869,  1890,  1890,  1891,  1891,  1891,  1893,
    1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1934,  1938,  1942,  1952,  1951,  2017,  2017,  2018,  2018,
    2018,  2019,  2019,  2020,  2020,  2020,  2021,  2021,  2021,  2022,
    2022,  2023,  2025,  2031,  2037,  2043,  2056,  2069,  2075,  2079,
    2088,  2087,  2092,  2092,  2093,  2097,  2103,  2114,  2120,  2126,
    2132,  2148,  2147,  2173,  2173,  2174,  2174,  2174,  2176,  2196,
    2206,  2205,  2232,  2232,  2233,  2233,  2233,  2235,  2241,  2250,
    2252,  2252,  2253,  2253,  2255,  2273,  2272,  2295,  2295,  2296,
    2296,  2296,  2298,  2304,  2313,  2316,  2316,  2317,  2317,  2318,
    2318,  2319,  2319,  2320,  2320,  2321,  2321,  2322,  2323,  2324,
    2324,  2325,  2325,  2326,  2326,  2327,  2327,  2328,  2328,  2329,
    2329,  2330,  2330,  2331,  2331,  2332,  2332,  2333,  2333,  2334,
    2334,  2335,  2336,  2336,  2337,  2338,  2339,  2339,  2340,  2340,
    2341,  2342,  2343,  2344,  2344,  2345,  2348,  2353,  2359,  2365,
    2371,  2376,  2381,  2386,  2391,  2396,  2401,  2406,  2411,  2416,
    2421,  2426,  2431,  2436,  2441,  2447,  2458,  2463,  2468,  2473,
    2478,  2483,  2486,  2491,  2494,  2499,  2504,  2509,  2514,  2519,
    2524,  2529,  2534,  2539,  2544,  2549,  2554,  2563,  2572,  2577,
    2582,  2588,  2587,  2592,  2592,  2593,  2596,  2599,  2602,  2605,
    2608,  2611,  2614,  2617,  2620,  2623,  2626,  2629,  2632,  2635,
    2638,  2641,  2644,  2647,  2650,  2656,  2655,  2660,  2660,  2661,
    2664,  2667,  2670,  2673,  2676,  2679,  2682,  2685,  2688,  2691,
    2694,  2697,  2700,  2703,  2706,  2709,  2712,  2715,  2718,  2721,
    2726,  2731,  2736,  2745,  2748,  2748,  2749,  2750,  2750,  2751,
    2751,  2752,  2753,  2754,  2755,  2756,  2756,  2757,  2757,  2759,
    2764,  2769,  2774,  2779,  2784,  2789,  2794,  2799,  2804,  2809,
    2814,  2822,  2825,  2825,  2826,  2826,  2827,  2828,  2829,  2829,
    2830,  2831,  2833,  2839,  2845,  2851,  2860,  2874,  2880
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
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE",
  "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1",
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "MONTHS", "YEARS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO",
  "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE",
  "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS",
  "T_MAX_CLIENTS", "T_NCHANGE", "T_NONONREG", "T_OPERWALL", "T_RECVQ",
  "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_GLOBOPS", "T_WALLOP", "T_WEBIRC", "T_RESTART",
  "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD",
  "UNKLINE", "USER", "USE_EGD", "USE_LOGGING", "VHOST", "VHOST6", "XLINE",
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
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@21", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@22", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
  "general_max_watch", "general_gline_enable", "general_gline_duration",
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
  "$@23", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@24", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_max_chans_per_oper", "channel_max_bans",
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
     475,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   226,   227,   227,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   229,   229,   230,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   232,
     232,   232,   233,   234,   234,   235,   235,   235,   236,   237,
     238,   239,   239,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   241,   242,   243,   243,   244,   244,   245,   245,   246,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   263,   264,
     264,   264,   264,   265,   266,   267,   268,   269,   269,   270,
     270,   270,   271,   273,   272,   274,   274,   275,   275,   275,
     275,   276,   277,   277,   279,   278,   280,   280,   281,   281,
     281,   281,   281,   281,   281,   283,   282,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   286,   287,
     288,   289,   290,   291,   293,   292,   294,   294,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   301,   300,   302,   302,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   320,   319,   321,
     321,   322,   322,   324,   323,   326,   325,   327,   327,   328,
     328,   328,   329,   329,   330,   330,   330,   330,   330,   332,
     331,   333,   333,   334,   334,   335,   336,   338,   337,   339,
     339,   340,   340,   340,   340,   340,   340,   340,   340,   340,
     341,   342,   343,   344,   346,   345,   347,   347,   348,   348,
     348,   348,   348,   348,   348,   348,   348,   348,   349,   350,
     351,   353,   352,   354,   354,   355,   355,   355,   355,   356,
     357,   358,   359,   360,   360,   361,   361,   362,   364,   363,
     365,   365,   366,   366,   366,   366,   367,   368,   370,   369,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   374,   373,   375,   375,   376,   376,   376,   377,
     379,   378,   380,   380,   381,   381,   381,   381,   381,   381,
     381,   381,   381,   381,   383,   382,   384,   384,   385,   385,
     385,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   385,   386,   387,   388,   389,   390,   391,   392,   392,
     394,   393,   395,   395,   396,   396,   397,   398,   399,   400,
     401,   403,   402,   404,   404,   405,   405,   405,   406,   407,
     409,   408,   410,   410,   411,   411,   411,   412,   413,   414,
     415,   415,   416,   416,   417,   419,   418,   420,   420,   421,
     421,   421,   422,   423,   424,   425,   425,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   426,   426,   426,   426,
     426,   426,   426,   426,   426,   426,   427,   428,   429,   430,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   452,   453,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   471,   470,   472,   472,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   475,   474,   476,   476,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     478,   479,   480,   481,   482,   482,   483,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   497,   498,   498,   498,   498,   498,   498,
     498,   498,   499,   500,   501,   502,   503,   504,   505
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
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   201,   364,   410,     0,
     425,     0,   267,   401,   243,     0,     0,   135,   301,     0,
       0,   318,   342,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   598,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     585,   597,   587,   588,   589,   590,   586,   591,   592,   593,
     594,   595,   596,     0,     0,     0,   423,     0,     0,   421,
     422,     0,   485,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,     0,   531,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   436,   483,   477,   478,   479,   480,   481,   476,
     447,   437,   438,   471,   439,   440,   441,   442,   443,   444,
     445,   446,   473,   448,   449,   482,   451,   456,   452,   454,
     453,   466,   467,   455,   457,   458,   459,   460,   450,   462,
     463,   464,   484,   474,   475,   472,   465,   461,   469,   470,
     468,     0,     0,     0,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,    44,    45,    46,     0,     0,
     621,     0,     0,     0,     0,     0,     0,     0,     0,   613,
     614,   615,   616,   619,   617,   618,   620,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    67,    68,    66,
      63,    62,    69,    53,    65,    56,    57,    58,    54,    64,
      59,    60,    61,    55,     0,     0,   316,     0,     0,   314,
     315,   102,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     584,     0,     0,     0,     0,   237,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   204,
     205,   208,   210,   211,   212,   213,   214,   215,   216,   217,
     206,   207,   209,   218,   219,   220,     0,     0,     0,     0,
       0,   390,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   367,   368,   369,   370,   371,   372,   374,   373,   376,
     380,   377,   378,   379,   375,   416,     0,     0,     0,   413,
     414,   415,     0,     0,   420,   431,     0,     0,     0,   428,
     429,   430,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   435,     0,     0,     0,   284,     0,     0,     0,     0,
       0,     0,   270,   271,   272,   273,   278,   274,   275,   276,
     277,   407,     0,     0,     0,   404,   405,   406,     0,   245,
       0,     0,     0,   255,     0,   253,   254,   256,   257,   111,
       0,     0,   107,     0,    47,     0,     0,     0,    43,     0,
       0,     0,   179,     0,     0,     0,   154,     0,     0,   138,
     139,   140,   141,   144,   145,   143,   142,   146,     0,     0,
       0,     0,     0,   304,   305,   306,   307,     0,     0,     0,
       0,     0,     0,     0,     0,   612,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,   328,     0,
       0,   321,   322,   323,   324,     0,     0,   350,     0,   345,
     346,   347,     0,     0,   313,     0,     0,     0,    96,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   583,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   203,   381,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   366,     0,     0,
       0,   412,     0,   419,     0,     0,     0,   427,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   434,   279,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   269,
       0,     0,     0,   403,   258,     0,     0,     0,     0,     0,
     252,     0,   106,     0,     0,     0,    42,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   308,     0,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
       0,   611,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   325,     0,     0,     0,
       0,   320,   348,     0,     0,     0,   344,     0,   312,   105,
     104,   103,   606,   605,   599,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   600,   601,   604,   603,   602,   607,
     608,   609,   610,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   365,     0,     0,   411,   424,
       0,     0,   426,   498,   502,   516,   582,   529,   496,   523,
     526,   497,   488,   487,   489,   490,   491,   505,   494,   495,
     506,   493,   501,   500,   499,   524,   486,   580,   581,   520,
     517,   566,   559,   576,   577,   560,   561,   562,   563,   571,
     564,   574,   578,   567,   579,   572,   568,   573,   565,   570,
     569,   575,     0,   558,   522,   541,   535,   552,   553,   536,
     537,   538,   539,   547,   540,   550,   554,   543,   548,   544,
     549,   542,   546,   545,   551,     0,   534,   515,   518,   528,
     492,   519,   508,   513,   514,   511,   512,   509,   510,   504,
     503,   527,   530,   521,   525,   507,     0,     0,     0,     0,
       0,     0,     0,     0,   268,     0,     0,   402,     0,     0,
       0,   263,   259,   262,   244,   112,     0,     0,   124,     0,
       0,   116,   117,   119,   118,    48,    49,     0,     0,     0,
       0,     0,     0,     0,     0,   136,     0,     0,     0,   302,
     622,   627,   625,   628,   623,   624,   626,    87,    95,    93,
      94,    85,    89,    88,    82,    81,    83,    71,     0,    72,
       0,    86,    84,    92,    90,    91,     0,     0,     0,   319,
       0,     0,   343,   317,    29,    30,    31,    32,    33,    34,
      35,   232,   233,   225,   241,   242,     0,   240,   227,   229,
     228,   226,   235,   236,   222,   234,   224,   223,    36,    36,
      36,    38,    37,   230,   231,   386,   388,   389,   399,   396,
     394,   395,     0,   393,   383,   397,   398,   382,   387,   385,
     400,   384,   417,   418,   432,   433,   556,     0,   532,     0,
     282,   283,   292,   289,   294,   291,   290,   297,   293,   295,
     288,   296,     0,   287,   281,   300,   299,   298,   280,   409,
     408,   250,   251,   249,     0,   248,   266,   265,     0,     0,
       0,   120,     0,     0,     0,     0,   115,   153,   151,   194,
     191,   190,   183,   185,   200,   197,   193,   184,   198,   187,
     195,   199,   188,   196,   192,   186,   189,     0,   182,   148,
     150,   152,   164,   158,   175,   176,   159,   160,   161,   162,
     170,   163,   173,   177,   166,   178,   171,   167,   172,   165,
     169,   168,   174,     0,   157,   149,   311,   309,   310,    73,
      77,   326,   332,   338,   341,   334,   340,   335,   339,   337,
     333,   336,     0,   331,   327,   349,   354,   360,   363,   356,
     362,   357,   361,   359,   355,   358,     0,   353,   238,     0,
      39,    40,    41,   391,     0,   557,   533,   285,     0,   246,
       0,   264,   261,   260,     0,     0,     0,     0,   114,   180,
       0,   155,     0,   329,     0,   351,     0,   239,   392,   286,
     247,   121,   130,   133,   132,   129,   134,   131,   128,     0,
     127,   123,   122,   181,   156,   330,   352,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   782,   783,  1031,  1032,    25,   224,   225,
     226,   227,    26,   265,   266,   267,   268,   744,   745,   748,
     749,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,    27,    71,    72,    73,
      74,    75,    28,   216,   217,   218,   219,   220,   950,   951,
     952,   953,   954,  1093,  1219,  1220,    29,    60,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   714,  1143,  1144,
     507,   710,  1117,  1118,    30,    49,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   587,  1016,  1017,    31,    57,   473,
     695,  1084,  1085,   474,   475,   476,  1090,   942,   943,   477,
     478,    32,    55,   451,   452,   453,   454,   455,   456,   457,
     682,  1072,  1073,   458,   459,   460,    33,    61,   512,   513,
     514,   515,   516,    34,   288,   289,   290,    35,    64,   550,
     551,   552,   553,   554,   758,  1162,  1163,    36,    65,   558,
     559,   560,   561,   764,  1176,  1177,    37,    50,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   607,  1042,
    1043,   370,   371,   372,   373,   374,    38,    56,   464,   465,
     466,   467,    39,    51,   378,   379,   380,   381,    40,   108,
     109,   110,    41,    53,   388,   389,   390,   391,    42,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   422,   905,   906,   207,   420,
     882,   883,   208,   209,   210,    43,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      44,   238,   239,   240,   241,   242,   243,   244,   245,   246
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -910
static const yytype_int16 yypact[] =
{
    -910,   603,  -910,  -199,  -218,  -216,  -910,  -910,  -910,  -192,
    -910,  -189,  -910,  -910,  -910,  -151,  -149,  -910,  -910,  -137,
    -130,  -910,  -910,  -125,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   366,   848,  -113,
     -68,   -54,    11,   -41,   331,   -33,   -22,    -9,    61,    57,
      -7,    -1,   679,   370,     1,    21,     8,   -99,    -5,    22,
      47,    18,  -910,  -910,  -910,  -910,  -910,    63,    79,    80,
      83,    90,    91,    92,    93,    94,    95,    97,    98,   191,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   629,   506,    29,  -910,    99,    35,  -910,
    -910,   107,  -910,   104,   105,   109,   112,   118,   128,   129,
     131,   134,   138,   139,   144,   146,   150,   154,   155,   156,
     158,   159,   161,   162,   164,   169,   172,   174,   176,   177,
     178,  -910,   180,  -910,   182,   183,   184,   185,   187,   193,
     197,   198,   201,   202,   203,   207,   208,   209,   213,   215,
     219,   117,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,   444,    51,   288,    64,   222,    27,  -910,  -910,  -910,
     120,   194,   225,   231,    60,  -910,  -910,  -910,   498,   330,
    -910,   233,   235,   239,   240,   241,   243,   247,    14,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   217,   248,   249,
     250,   251,   253,   254,   255,   257,   258,   260,   261,   262,
     264,   271,   277,   282,   284,   214,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,    17,    13,  -910,   289,    43,  -910,
    -910,  -910,   218,   347,   389,   293,  -910,   147,   411,   353,
     413,   413,   414,   415,   417,   360,   363,   423,   413,   308,
    -910,   312,   311,   313,   319,  -910,   322,   323,   324,   328,
     329,   332,   334,   335,   336,   340,   344,   349,    10,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   315,   350,   352,   354,
     356,  -910,   357,   358,   359,   364,   367,   368,   369,   371,
      75,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   372,   374,    40,  -910,
    -910,  -910,   431,   379,  -910,  -910,   382,   384,    69,  -910,
    -910,  -910,   407,   413,   413,   472,   445,   446,   513,   488,
     455,   413,   459,   413,   519,   520,   522,   467,   468,   469,
     413,   529,   530,   413,   531,   533,   534,   535,   479,   482,
     426,   483,   428,   413,   413,   489,   491,   494,   495,  -117,
    -101,   496,   497,   413,   413,   539,   413,   500,   503,   504,
     448,  -910,   449,   447,   453,  -910,   458,   461,   463,   465,
     466,    23,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   470,   473,    86,  -910,  -910,  -910,   451,  -910,
     475,   476,   477,  -910,    20,  -910,  -910,  -910,  -910,  -910,
     515,   462,  -910,   480,  -910,   569,   570,   484,  -910,   493,
     502,   505,  -910,   514,   516,   521,  -910,   524,   238,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   501,   527,
     542,   543,    26,  -910,  -910,  -910,  -910,   540,   548,   583,
     553,   554,   563,   413,   507,  -910,  -910,   614,   575,   637,
     638,   621,   623,   631,   632,   650,   657,    48,    59,   658,
     660,   653,   666,   668,   566,  -910,   573,   571,  -910,   574,
      31,  -910,  -910,  -910,  -910,   576,   577,  -910,    34,  -910,
    -910,  -910,   676,   579,  -910,   582,   592,   596,  -910,   605,
     607,   610,   619,   611,   625,   626,   634,   636,   640,   642,
     643,   644,  -910,  -910,   699,   719,   413,   618,   748,   762,
     766,   767,   413,   413,   750,   769,   771,   413,   772,   772,
     659,  -910,  -910,   755,   119,   756,   718,   670,   773,   774,
     775,   777,   787,   778,   779,   780,   674,  -910,   781,   782,
     685,  -910,   686,  -910,   785,   786,   689,  -910,   690,   691,
     692,   693,   696,   697,   698,   700,   701,   705,   706,   707,
     708,   709,   710,   711,   712,   713,   714,   715,   716,   717,
     720,   721,   722,   723,   724,   725,   598,   726,   664,   727,
     730,   731,   732,   733,   734,   735,   736,   737,   738,   739,
     740,   743,   744,   745,   746,   747,   749,   751,  -910,  -910,
     797,   776,   752,   816,   864,   850,   851,   852,   757,  -910,
     854,   856,   759,  -910,  -910,   758,   858,   860,   866,   763,
    -910,   764,  -910,   165,   765,   768,  -910,  -910,   865,   823,
     770,   867,   868,   869,   783,   870,   784,  -910,  -910,   872,
     873,   874,   788,  -910,   789,   790,   791,   792,   793,   794,
     795,  -910,   796,   798,   799,   800,   801,   802,   803,   804,
     805,   806,  -910,  -910,  -217,  -910,  -910,  -910,  -208,  -910,
     807,   808,   809,   810,   811,  -910,  -910,   875,   812,   876,
     813,  -910,  -910,   877,   814,   818,  -910,   819,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,   413,   413,   413,   413,   413,
     413,   413,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   820,   821,   822,   116,   824,   825,   826,
     827,   828,   829,   830,   831,   832,   833,    28,   834,   835,
    -910,   836,   837,   838,   839,   840,    -2,   841,   842,   843,
     844,   845,   846,   847,   849,  -910,   853,   855,  -910,  -910,
     857,   859,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -205,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -171,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,   861,   862,   518,   863,
     871,   878,   879,   880,  -910,   881,   882,  -910,    -8,   883,
     884,   901,   885,  -910,  -910,  -910,   886,   887,  -910,   888,
      32,  -910,  -910,  -910,  -910,  -910,  -910,   892,   893,   485,
     894,   895,   896,   635,   897,  -910,   898,   899,   900,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,    48,  -910,
      59,  -910,  -910,  -910,  -910,  -910,   902,   388,   903,  -910,
     904,   682,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -168,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   772,   772,
     772,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -150,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   598,  -910,   664,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -142,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -140,  -910,  -910,  -910,   913,   866,
     905,  -910,   910,   906,   -60,   907,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,   -65,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,   -51,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   -14,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,    -4,  -910,  -910,   116,
    -910,  -910,  -910,  -910,    -2,  -910,  -910,  -910,   518,  -910,
      -8,  -910,  -910,  -910,   908,   246,   911,   912,  -910,  -910,
     485,  -910,   635,  -910,   388,  -910,   682,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,    39,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   246,  -910
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -910,  -910,  -910,   110,  -298,  -909,  -598,  -910,  -910,   914,
    -910,  -910,  -910,  -910,   741,  -910,  -910,  -910,    15,  -910,
      12,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   930,  -910,
    -910,  -910,  -910,  -910,   890,  -910,  -910,  -910,  -910,    54,
    -910,  -910,  -910,  -910,  -910,  -220,  -910,  -910,  -910,   537,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -165,
    -910,  -910,  -910,  -156,  -910,  -910,  -910,   753,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -108,  -910,  -910,  -910,
    -910,  -910,  -118,  -910,   599,  -910,  -910,  -910,   -12,  -910,
    -910,  -910,  -910,  -910,   624,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -109,  -910,  -910,  -910,  -910,  -910,  -910,   578,
    -910,  -910,  -910,  -910,  -910,   889,  -910,  -910,  -910,  -910,
     536,  -910,  -910,  -910,  -910,  -910,  -119,  -910,  -910,  -910,
     538,  -910,  -910,  -910,  -910,  -115,  -910,  -910,  -910,   728,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
     -97,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,   630,
    -910,  -910,  -910,  -910,  -910,   761,  -910,  -910,  -910,  -910,
     981,  -910,  -910,  -910,  -910,   754,  -910,  -910,  -910,  -910,
     932,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,    36,  -910,  -910,
    -910,    41,  -910,  -910,  -910,  -910,  -910,  1008,  -910,  -910,
    -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,  -910,
    -910,  -910,   909,  -910,  -910,  -910,  -910,  -910,  -910,  -910
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     808,   809,   573,   574,   987,    47,  1040,    48,   988,   286,
     581,   311,   106,   989,   555,   230,  1056,   990,   546,    67,
    1057,   468,    45,    46,   442,   312,   313,   508,   214,   314,
     375,    52,   546,   946,    54,   555,   106,  1028,  1029,  1030,
     443,   375,    68,  1081,   286,   807,   315,   665,   666,    69,
    1058,   231,   461,  1178,  1059,   444,   469,  1179,   221,   445,
     509,   221,   214,   667,   668,   232,   233,   234,   235,   236,
     385,  1183,    58,   107,    59,  1184,   346,   470,   347,  1187,
     348,  1189,   471,  1188,   237,  1190,    62,   461,   316,   317,
     318,   376,   349,    63,   319,   629,   630,   107,    66,   510,
     320,   321,   376,   637,   287,   639,   322,   350,   385,   556,
     103,   351,   646,   547,    70,   649,   323,   324,   112,  1180,
    1181,  1182,   291,   113,   114,   659,   660,   547,   947,   115,
     556,   325,   352,   807,   353,   671,   672,   116,   674,   287,
    1196,   446,   472,   117,   354,   118,   119,   120,   447,   448,
     511,   222,   121,   377,   222,   104,  1199,   326,   122,   123,
    1200,   124,   125,   126,   377,   386,   946,   127,   557,   105,
    1201,   355,   548,   128,  1202,   462,   223,   129,   130,   223,
     449,   131,   111,  1082,   742,   743,   548,   948,  1083,   557,
     211,   132,    76,   387,  1041,   746,   747,   356,   133,   327,
     134,   212,   135,   386,   136,   137,   138,  1203,  1014,  1015,
     462,  1204,    77,    78,   213,   247,   228,  1205,    79,   292,
     139,  1206,   229,   357,   284,   730,   140,   141,   142,   549,
     143,   387,   600,   144,   145,   450,   524,   146,   248,   489,
     295,   215,   699,   549,   285,   688,   293,  -113,   722,   481,
     358,   949,   569,   760,  1095,   490,   765,   383,    80,    81,
    1227,   947,   620,   463,  1228,   563,    82,    83,    84,   147,
     491,   294,   249,   148,   492,   215,   149,   150,   151,   152,
     153,  -113,   487,   154,   155,   479,  1212,   297,   795,   468,
     359,   626,    85,    86,   801,   802,   250,   616,   463,   806,
     251,   812,   813,   298,   299,    87,    88,   300,   692,  1213,
     252,  1214,   253,   254,   301,   302,   303,   304,   305,   306,
     948,   307,   308,   382,   469,   156,   157,   158,   392,   393,
     159,   508,   112,   394,   493,   160,   395,   113,   114,   440,
     483,   565,   396,   115,   255,   470,   256,   257,   258,   259,
     471,   116,   397,   398,  1215,   399,   494,   117,   400,   118,
     119,   120,   401,   402,   509,   260,   121,    67,   403,   495,
     404,   247,   122,   123,   405,   124,   125,   126,   406,   407,
     408,   127,   409,   410,   949,   411,   412,   128,   413,   261,
      68,   129,   130,   414,   248,   131,   415,    69,   416,   262,
     417,   418,   419,   510,   421,   132,   423,   424,   425,   426,
     472,   427,   133,   309,   134,   484,   135,   428,   136,   137,
     138,   429,   430,  1216,  1217,   431,   432,   433,   249,   263,
     264,   434,   435,   436,   139,   496,   544,   437,   526,   438,
     140,   141,   142,   439,   143,   442,   480,   144,   145,   485,
     497,   146,   250,  1152,   511,   486,   251,   517,  1218,   518,
     716,   443,    70,   519,   520,   521,   252,   522,   253,   254,
     566,   523,   527,   528,   529,   530,   444,   531,   532,   533,
     445,   534,   535,   147,   536,   537,   538,   148,   539,  1099,
     149,   150,   151,   152,   153,   540,  1197,   154,   155,   489,
     255,   541,   256,   257,   258,   259,   542,   346,   543,   347,
    1100,   348,   567,   562,   568,   490,   570,   571,   572,   575,
     576,   260,   577,   349,   578,  1101,  1153,   579,   580,   582,
     491,  1062,  1102,   583,   492,   584,   602,   585,   350,   156,
     157,   158,   351,   586,   159,   261,   588,   589,   590,   160,
    1103,  1063,   591,   592,   622,   262,   593,  1154,   594,   595,
     596,  1064,   446,   352,   597,   353,  1155,  1065,   598,   447,
     448,   628,  1156,   599,   603,   354,   604,   631,   605,  1104,
     606,   608,   609,   610,  1066,   263,   264,  1157,   611,  1158,
    1159,   612,   613,   614,   493,   615,   618,  1105,   619,  1160,
     623,   449,   355,     2,     3,  1161,   624,     4,   625,   632,
     633,   635,  1106,  1107,  1108,  1067,   494,     5,   634,   636,
       6,     7,  1068,   638,   640,   641,     8,   642,   356,   495,
     311,   643,   644,   645,   647,   648,   650,     9,   651,   652,
     653,    10,    11,   654,   312,   313,   655,   657,   314,   861,
     656,    12,   658,   661,   357,   662,   450,  1069,   663,   664,
     669,   670,   673,  1109,   675,   315,    13,   676,   677,   678,
     679,   680,   694,  1110,    14,    15,  1070,   681,  1111,   701,
     230,   358,   683,   702,  1112,   684,  1122,   685,  1113,   686,
     687,  1114,   704,   705,   690,   496,  1115,   691,    16,   696,
     697,   698,  1116,   703,   724,   706,   726,   316,   317,   318,
     497,    17,   725,   319,   707,   885,   231,   727,   728,   320,
     321,   359,   718,  1071,   572,   322,   708,   729,   731,   709,
     232,   233,   234,   235,   236,   323,   324,   732,   711,   733,
     712,    18,   734,   735,   736,   713,   737,  1166,   715,   237,
     325,   719,    19,    20,   738,   739,    21,    22,   752,   775,
     776,   777,   778,   779,   780,   781,   720,   721,   862,   863,
     864,   865,   866,   740,   867,   868,   326,   869,   870,   871,
     741,   750,   872,   751,   873,   874,   875,   755,   876,   753,
     877,   754,   878,   879,   756,   757,   880,   762,   759,   767,
     768,   763,   881,   769,   793,  1123,  1124,  1125,  1126,  1127,
      23,  1128,  1129,   770,  1130,  1131,  1132,   771,   327,  1133,
    1167,  1134,  1135,  1136,   794,  1137,   772,  1138,   773,  1139,
    1140,   774,   784,  1141,   886,   887,   888,   889,   890,  1142,
     891,   892,   796,   893,   894,   895,   785,   786,   896,    76,
     897,  1168,   898,   797,   899,   787,   900,   788,   901,   902,
    1169,   789,   903,   790,   791,   792,  1170,   798,   904,    77,
      78,   799,   800,   803,   804,    79,   805,   807,   811,   814,
     810,  1171,   815,  1172,  1173,  1004,  1005,  1006,  1007,  1008,
    1009,  1010,   821,  1174,   816,   825,   817,   818,   819,  1175,
     820,   822,   823,   824,   826,   827,   828,   829,   830,   831,
     832,   833,   834,   835,   836,    80,    81,   837,   838,   839,
     926,   840,   841,    82,    83,    84,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   929,
     927,   855,   856,   857,   858,   859,   860,   884,   907,    85,
      86,   908,   909,   910,   911,   912,   913,   914,   915,   916,
     917,   918,    87,    88,   919,   920,   921,   922,   923,   930,
     924,   941,   925,   931,   932,   933,   928,   935,   934,   936,
     937,   939,   938,   940,   944,   945,   955,   958,   957,   956,
     960,   961,   962,   964,   959,   966,   967,   968,   996,   998,
    1000,   296,  1150,  1149,  1096,   965,   545,   963,  1229,   969,
     970,   971,   972,   973,   974,   975,   976,   977,  1191,   978,
     979,   980,   981,   982,   983,   984,   985,   986,   991,   992,
     993,   994,   995,  1194,   999,   717,   997,  1224,  1001,  1002,
    1003,  1011,  1012,  1013,  1223,  1018,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1044,  1045,  1046,  1047,  1048,  1049,  1050,  1088,
    1051,  1207,  1210,   700,  1052,   689,  1053,  1192,  1054,  1209,
    1055,   601,  1060,  1061,  1074,  1225,   761,  1208,   617,   384,
     723,  1226,  1075,   441,   693,  1186,   766,   310,  1185,  1076,
    1077,  1078,  1079,  1080,  1086,  1087,   482,  1091,     0,     0,
    1089,  1092,  1094,  1097,  1098,  1119,  1120,  1121,  1145,  1146,
    1147,  1148,     0,  1151,  1164,  1165,  1193,     0,  1198,  1211,
    1195,     0,  1221,  1222,     0,     0,     0,     0,   488,   621,
       0,     0,   627,     0,     0,     0,     0,   525,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   564
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-910)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     598,   599,   300,   301,   221,   223,     8,   223,   225,     1,
     308,     1,     1,   221,     1,     1,   221,   225,     1,     1,
     225,     1,   221,   222,     1,    15,    16,     1,     1,    19,
       1,   223,     1,     1,   223,     1,     1,     9,    10,    11,
      17,     1,    24,    51,     1,   105,    36,   164,   165,    31,
     221,    37,     1,   221,   225,    32,    36,   225,     1,    36,
      34,     1,     1,   164,   165,    51,    52,    53,    54,    55,
       1,   221,   223,    62,   223,   225,     1,    57,     3,   221,
       5,   221,    62,   225,    70,   225,   223,     1,    78,    79,
      80,    62,    17,   223,    84,   393,   394,    62,   223,    73,
      90,    91,    62,   401,    96,   403,    96,    32,     1,    96,
     223,    36,   410,    96,    96,   413,   106,   107,     1,  1028,
    1029,  1030,   221,     6,     7,   423,   424,    96,    96,    12,
      96,   121,    57,   105,    59,   433,   434,    20,   436,    96,
     200,   118,   122,    26,    69,    28,    29,    30,   125,   126,
     124,    94,    35,   124,    94,   223,   221,   147,    41,    42,
     225,    44,    45,    46,   124,    96,     1,    50,   155,   223,
     221,    96,   155,    56,   225,   124,   119,    60,    61,   119,
     157,    64,   223,   191,   136,   137,   155,   155,   196,   155,
     223,    74,     1,   124,   196,   136,   137,   122,    81,   189,
      83,   223,    85,    96,    87,    88,    89,   221,    92,    93,
     124,   225,    21,    22,   223,     1,   223,   221,    27,   224,
     103,   225,   223,   148,   223,   523,   109,   110,   111,   212,
     113,   124,   222,   116,   117,   212,   222,   120,    24,     1,
     222,   214,   222,   212,   223,   222,   224,   220,   222,   222,
     175,   219,   105,   222,   222,    17,   222,   222,    67,    68,
     221,    96,   222,   212,   225,   222,    75,    76,    77,   152,
      32,   224,    58,   156,    36,   214,   159,   160,   161,   162,
     163,   220,   222,   166,   167,   221,    40,   224,   586,     1,
     215,   222,   101,   102,   592,   593,    82,   222,   212,   597,
      86,   182,   183,   224,   224,   114,   115,   224,   222,    63,
      96,    65,    98,    99,   224,   224,   224,   224,   224,   224,
     155,   224,   224,   224,    36,   208,   209,   210,   224,   224,
     213,     1,     1,   224,    96,   218,   224,     6,     7,   222,
     220,   123,   224,    12,   130,    57,   132,   133,   134,   135,
      62,    20,   224,   224,   108,   224,   118,    26,   224,    28,
      29,    30,   224,   224,    34,   151,    35,     1,   224,   131,
     224,     1,    41,    42,   224,    44,    45,    46,   224,   224,
     224,    50,   224,   224,   219,   224,   224,    56,   224,   175,
      24,    60,    61,   224,    24,    64,   224,    31,   224,   185,
     224,   224,   224,    73,   224,    74,   224,   224,   224,   224,
     122,   224,    81,   222,    83,   221,    85,   224,    87,    88,
      89,   224,   224,   177,   178,   224,   224,   224,    58,   215,
     216,   224,   224,   224,   103,   197,   222,   224,   221,   224,
     109,   110,   111,   224,   113,     1,   224,   116,   117,   224,
     212,   120,    82,    65,   124,   224,    86,   224,   212,   224,
     222,    17,    96,   224,   224,   224,    96,   224,    98,    99,
     123,   224,   224,   224,   224,   224,    32,   224,   224,   224,
      36,   224,   224,   152,   224,   224,   224,   156,   224,     4,
     159,   160,   161,   162,   163,   224,  1094,   166,   167,     1,
     130,   224,   132,   133,   134,   135,   224,     1,   224,     3,
      25,     5,   123,   224,   221,    17,   105,   164,   105,   105,
     105,   151,   105,    17,   164,    40,   138,   164,   105,   221,
      32,    13,    47,   221,    36,   224,   221,   224,    32,   208,
     209,   210,    36,   224,   213,   175,   224,   224,   224,   218,
      65,    33,   224,   224,   123,   185,   224,   169,   224,   224,
     224,    43,   118,    57,   224,    59,   178,    49,   224,   125,
     126,   164,   184,   224,   224,    69,   224,   105,   224,    94,
     224,   224,   224,   224,    66,   215,   216,   199,   224,   201,
     202,   224,   224,   224,    96,   224,   224,   112,   224,   211,
     221,   157,    96,     0,     1,   217,   224,     4,   224,   164,
     164,   123,   127,   128,   129,    97,   118,    14,   105,   164,
      17,    18,   104,   164,   105,   105,    23,   105,   122,   131,
       1,   164,   164,   164,   105,   105,   105,    34,   105,   105,
     105,    38,    39,   164,    15,    16,   164,   164,    19,    51,
     224,    48,   224,   164,   148,   164,   212,   139,   164,   164,
     164,   164,   123,   178,   164,    36,    63,   164,   164,   221,
     221,   224,   221,   188,    71,    72,   158,   224,   193,   164,
       1,   175,   224,   221,   199,   224,    51,   224,   203,   224,
     224,   206,   123,   123,   224,   197,   211,   224,    95,   224,
     224,   224,   217,   223,   164,   221,   123,    78,    79,    80,
     212,   108,   164,    84,   221,    51,    37,   164,   164,    90,
      91,   215,   221,   205,   105,    96,   224,   164,   221,   224,
      51,    52,    53,    54,    55,   106,   107,   123,   224,   164,
     224,   138,   105,   105,   123,   224,   123,    65,   224,    70,
     121,   224,   149,   150,   123,   123,   153,   154,   105,   140,
     141,   142,   143,   144,   145,   146,   224,   224,   170,   171,
     172,   173,   174,   123,   176,   177,   147,   179,   180,   181,
     123,   123,   184,   123,   186,   187,   188,   221,   190,   123,
     192,   123,   194,   195,   221,   224,   198,   221,   224,   123,
     221,   224,   204,   221,   105,   170,   171,   172,   173,   174,
     207,   176,   177,   221,   179,   180,   181,   221,   189,   184,
     138,   186,   187,   188,   105,   190,   221,   192,   221,   194,
     195,   221,   221,   198,   170,   171,   172,   173,   174,   204,
     176,   177,   224,   179,   180,   181,   221,   221,   184,     1,
     186,   169,   188,   105,   190,   221,   192,   221,   194,   195,
     178,   221,   198,   221,   221,   221,   184,   105,   204,    21,
      22,   105,   105,   123,   105,    27,   105,   105,   123,   123,
     221,   199,   164,   201,   202,   775,   776,   777,   778,   779,
     780,   781,   105,   211,   224,   221,   123,   123,   123,   217,
     123,   123,   123,   123,   123,   123,   221,   221,   123,   123,
     221,   221,   221,   221,   221,    67,    68,   221,   221,   221,
     123,   221,   221,    75,    76,    77,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   123,
     164,   221,   221,   221,   221,   221,   221,   221,   221,   101,
     102,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   114,   115,   221,   221,   221,   221,   221,   105,
     221,   105,   221,   123,   123,   123,   224,   123,   221,   123,
     221,   123,   224,   123,   221,   221,   221,   164,   123,   221,
     123,   123,   123,   123,   224,   123,   123,   123,   123,   123,
     123,    71,   990,   988,   950,   221,   265,   224,  1228,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   105,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   123,   221,   498,   224,  1202,   224,   221,
     221,   221,   221,   221,  1200,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   168,
     221,  1179,  1190,   474,   221,   451,   221,  1089,   221,  1188,
     221,   328,   221,   221,   221,  1204,   550,  1184,   360,   108,
     512,  1206,   221,   161,   464,  1059,   558,    89,  1057,   221,
     221,   221,   221,   221,   221,   221,   216,   221,    -1,    -1,
     225,   224,   224,   221,   221,   221,   221,   221,   221,   221,
     221,   221,    -1,   221,   221,   221,   221,    -1,   221,   221,
     224,    -1,   221,   221,    -1,    -1,    -1,    -1,   224,   378,
      -1,    -1,   388,    -1,    -1,    -1,    -1,   238,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   288
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   227,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    63,    71,    72,    95,   108,   138,   149,
     150,   153,   154,   207,   228,   233,   238,   262,   268,   282,
     300,   323,   337,   352,   359,   363,   373,   382,   402,   408,
     414,   418,   424,   481,   496,   221,   222,   223,   223,   301,
     383,   409,   223,   419,   223,   338,   403,   324,   223,   223,
     283,   353,   223,   223,   364,   374,   223,     1,    24,    31,
      96,   263,   264,   265,   266,   267,     1,    21,    22,    27,
      67,    68,    75,    76,    77,   101,   102,   114,   115,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   223,   223,   223,     1,    62,   415,   416,
     417,   223,     1,     6,     7,    12,    20,    26,    28,    29,
      30,    35,    41,    42,    44,    45,    46,    50,    56,    60,
      61,    64,    74,    81,    83,    85,    87,    88,    89,   103,
     109,   110,   111,   113,   116,   117,   120,   152,   156,   159,
     160,   161,   162,   163,   166,   167,   208,   209,   210,   213,
     218,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   474,   478,   479,
     480,   223,   223,   223,     1,   214,   269,   270,   271,   272,
     273,     1,    94,   119,   234,   235,   236,   237,   223,   223,
       1,    37,    51,    52,    53,    54,    55,    70,   497,   498,
     499,   500,   501,   502,   503,   504,   505,     1,    24,    58,
      82,    86,    96,    98,    99,   130,   132,   133,   134,   135,
     151,   175,   185,   215,   216,   239,   240,   241,   242,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   223,   223,     1,    96,   360,   361,
     362,   221,   224,   224,   224,   222,   264,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   222,
     483,     1,    15,    16,    19,    36,    78,    79,    80,    84,
      90,    91,    96,   106,   107,   121,   147,   189,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,   316,   317,   318,   319,     1,     3,     5,    17,
      32,    36,    57,    59,    69,    96,   122,   148,   175,   215,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     397,   398,   399,   400,   401,     1,    62,   124,   410,   411,
     412,   413,   224,   222,   416,     1,    96,   124,   420,   421,
     422,   423,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     475,   224,   471,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     222,   426,     1,    17,    32,    36,   118,   125,   126,   157,
     212,   339,   340,   341,   342,   343,   344,   345,   349,   350,
     351,     1,   124,   212,   404,   405,   406,   407,     1,    36,
      57,    62,   122,   325,   329,   330,   331,   335,   336,   221,
     224,   222,   270,   220,   221,   224,   224,   222,   235,     1,
      17,    32,    36,    96,   118,   131,   197,   212,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   296,     1,    34,
      73,   124,   354,   355,   356,   357,   358,   224,   224,   224,
     224,   224,   224,   224,   222,   498,   221,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   222,   240,     1,    96,   155,   212,
     365,   366,   367,   368,   369,     1,    96,   155,   375,   376,
     377,   378,   224,   222,   361,   123,   123,   123,   221,   105,
     105,   164,   105,   230,   230,   105,   105,   105,   164,   164,
     105,   230,   221,   221,   224,   224,   224,   320,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     222,   303,   221,   224,   224,   224,   224,   394,   224,   224,
     224,   224,   224,   224,   224,   224,   222,   385,   224,   224,
     222,   411,   123,   221,   224,   224,   222,   421,   164,   230,
     230,   105,   164,   164,   105,   123,   164,   230,   164,   230,
     105,   105,   105,   164,   164,   164,   230,   105,   105,   230,
     105,   105,   105,   105,   164,   164,   224,   164,   224,   230,
     230,   164,   164,   164,   164,   164,   165,   164,   165,   164,
     164,   230,   230,   123,   230,   164,   164,   164,   221,   221,
     224,   224,   346,   224,   224,   224,   224,   224,   222,   340,
     224,   224,   222,   405,   221,   326,   224,   224,   224,   222,
     330,   164,   221,   223,   123,   123,   221,   221,   224,   224,
     297,   224,   224,   224,   293,   224,   222,   285,   221,   224,
     224,   224,   222,   355,   164,   164,   123,   164,   164,   164,
     230,   221,   123,   164,   105,   105,   123,   123,   123,   123,
     123,   123,   136,   137,   243,   244,   136,   137,   245,   246,
     123,   123,   105,   123,   123,   221,   221,   224,   370,   224,
     222,   366,   221,   224,   379,   222,   376,   123,   221,   221,
     221,   221,   221,   221,   221,   140,   141,   142,   143,   144,
     145,   146,   229,   230,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   105,   105,   230,   224,   105,   105,   105,
     105,   230,   230,   123,   105,   105,   230,   105,   232,   232,
     221,   123,   182,   183,   123,   164,   224,   123,   123,   123,
     123,   105,   123,   123,   123,   221,   123,   123,   221,   221,
     123,   123,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,    51,   170,   171,   172,   173,   174,   176,   177,   179,
     180,   181,   184,   186,   187,   188,   190,   192,   194,   195,
     198,   204,   476,   477,   221,    51,   170,   171,   172,   173,
     174,   176,   177,   179,   180,   181,   184,   186,   188,   190,
     192,   194,   195,   198,   204,   472,   473,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   123,   164,   224,   123,
     105,   123,   123,   123,   221,   123,   123,   221,   224,   123,
     123,   105,   333,   334,   221,   221,     1,    96,   155,   219,
     274,   275,   276,   277,   278,   221,   221,   123,   164,   224,
     123,   123,   123,   224,   123,   221,   123,   123,   123,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   225,   221,
     225,   221,   221,   221,   221,   221,   123,   224,   123,   221,
     123,   224,   221,   221,   229,   229,   229,   229,   229,   229,
     229,   221,   221,   221,    92,    93,   321,   322,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,     9,    10,
      11,   231,   232,   221,   221,   221,   221,   221,   221,   221,
       8,   196,   395,   396,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   225,   221,   225,
     221,   221,    13,    33,    43,    49,    66,    97,   104,   139,
     158,   205,   347,   348,   221,   221,   221,   221,   221,   221,
     221,    51,   191,   196,   327,   328,   221,   221,   168,   225,
     332,   221,   224,   279,   224,   222,   275,   221,   221,     4,
      25,    40,    47,    65,    94,   112,   127,   128,   129,   178,
     188,   193,   199,   203,   206,   211,   217,   298,   299,   221,
     221,   221,    51,   170,   171,   172,   173,   174,   176,   177,
     179,   180,   181,   184,   186,   187,   188,   190,   192,   194,
     195,   198,   204,   294,   295,   221,   221,   221,   221,   244,
     246,   221,    65,   138,   169,   178,   184,   199,   201,   202,
     211,   217,   371,   372,   221,   221,    65,   138,   169,   178,
     184,   199,   201,   202,   211,   217,   380,   381,   221,   225,
     231,   231,   231,   221,   225,   477,   473,   221,   225,   221,
     225,   105,   334,   221,   123,   224,   200,   232,   221,   221,
     225,   221,   225,   221,   225,   221,   225,   322,   396,   348,
     328,   221,    40,    63,    65,   108,   177,   178,   212,   280,
     281,   221,   221,   299,   295,   372,   381,   221,   225,   281
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
#line 391 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 393 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 397 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 401 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 405 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 409 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 413 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 417 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 421 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 426 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 427 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 428 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 444 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 450 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 476 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 482 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 491 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 497 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 505 "conf_parser.y"
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
#line 547 "conf_parser.y"
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
#line 606 "conf_parser.y"
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
#line 634 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 642 "conf_parser.y"
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
#line 657 "conf_parser.y"
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
#line 672 "conf_parser.y"
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
#line 681 "conf_parser.y"
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
#line 695 "conf_parser.y"
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
#line 704 "conf_parser.y"
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
#line 732 "conf_parser.y"
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
#line 762 "conf_parser.y"
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
#line 787 "conf_parser.y"
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
#line 809 "conf_parser.y"
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
#line 831 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 846 "conf_parser.y"
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
#line 855 "conf_parser.y"
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
#line 864 "conf_parser.y"
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
#line 882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 888 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 892 "conf_parser.y"
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
#line 908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 916 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 919 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 951 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 955 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 972 "conf_parser.y"
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
#line 1047 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1053 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1059 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1065 "conf_parser.y"
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
#line 1076 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1082 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1088 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1266 "conf_parser.y"
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
#line 1278 "conf_parser.y"
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
#line 1344 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1350 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1356 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1362 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1368 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1374 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1380 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1386 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1392 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1411 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1423 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1462 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1468 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1482 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1490 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1495 "conf_parser.y"
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
#line 1509 "conf_parser.y"
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
#line 1529 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1535 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1544 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1548 "conf_parser.y"
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
      conf->name = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1591 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1597 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1603 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
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
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1627 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1631 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 290:
/* Line 1787 of yacc.c  */
#line 1635 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1639 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1643 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1647 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1651 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1655 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1659 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1663 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1669 "conf_parser.y"
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
#line 1683 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1723 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1729 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1735 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
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
  conf->host = xstrdup(block_state.host.buf);
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

  conf = conf_make(CONF_KLINE);
  conf->user = xstrdup(block_state.user.buf);
  conf->host = xstrdup(block_state.host.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
  add_conf_by_address(CONF_KLINE, conf);
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2177 "conf_parser.y"
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

  case 409:
/* Line 1787 of yacc.c  */
#line 2197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2210 "conf_parser.y"
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

  case 417:
/* Line 1787 of yacc.c  */
#line 2236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 2256 "conf_parser.y"
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

  case 425:
/* Line 1787 of yacc.c  */
#line 2273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 2277 "conf_parser.y"
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
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2299 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 433:
/* Line 1787 of yacc.c  */
#line 2305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 486:
/* Line 1787 of yacc.c  */
#line 2349 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 2354 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2360 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2372 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2377 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2382 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2387 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2392 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2397 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2402 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2407 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2412 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2417 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2422 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2427 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2432 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2437 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2448 "conf_parser.y"
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

  case 506:
/* Line 1787 of yacc.c  */
#line 2459 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2464 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2469 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2474 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2479 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2484 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2495 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2500 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2505 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2510 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2515 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2520 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2525 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2530 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2535 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2540 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2545 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2550 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2564 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2573 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2578 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2583 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2588 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2597 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2603 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2606 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2612 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2618 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2621 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2633 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2636 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2642 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2651 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2677 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2686 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2689 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1787 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1787 of yacc.c  */
#line 2775 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1787 of yacc.c  */
#line 2785 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1787 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
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

  case 627:
/* Line 1787 of yacc.c  */
#line 2875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6649 "conf_parser.c"
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


