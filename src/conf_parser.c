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
     REASON = 378,
     REDIRPORT = 379,
     REDIRSERV = 380,
     REHASH = 381,
     REMOTE = 382,
     REMOTEBAN = 383,
     RSA_PRIVATE_KEY_FILE = 384,
     RSA_PUBLIC_KEY_FILE = 385,
     SSL_CERTIFICATE_FILE = 386,
     SSL_DH_PARAM_FILE = 387,
     T_SSL_CLIENT_METHOD = 388,
     T_SSL_SERVER_METHOD = 389,
     T_SSLV3 = 390,
     T_TLSV1 = 391,
     RESV = 392,
     RESV_EXEMPT = 393,
     SECONDS = 394,
     MINUTES = 395,
     HOURS = 396,
     DAYS = 397,
     WEEKS = 398,
     MONTHS = 399,
     YEARS = 400,
     SENDQ = 401,
     SEND_PASSWORD = 402,
     SERVERHIDE = 403,
     SERVERINFO = 404,
     SQUIT = 405,
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
     T_FARCONNECT = 435,
     T_FULL = 436,
     T_INVISIBLE = 437,
     T_IPV4 = 438,
     T_IPV6 = 439,
     T_LOCOPS = 440,
     T_MAX_CLIENTS = 441,
     T_NCHANGE = 442,
     T_NONONREG = 443,
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
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SSL_CERTIFICATE_FILE 386
#define SSL_DH_PARAM_FILE 387
#define T_SSL_CLIENT_METHOD 388
#define T_SSL_SERVER_METHOD 389
#define T_SSLV3 390
#define T_TLSV1 391
#define RESV 392
#define RESV_EXEMPT 393
#define SECONDS 394
#define MINUTES 395
#define HOURS 396
#define DAYS 397
#define WEEKS 398
#define MONTHS 399
#define YEARS 400
#define SENDQ 401
#define SEND_PASSWORD 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define SQUIT 405
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
#define T_FARCONNECT 435
#define T_FULL 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_MAX_CLIENTS 441
#define T_NCHANGE 442
#define T_NONONREG 443
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
#define YYLAST   1181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  635
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1240

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
       2,     2,     2,     2,     2,     2,     2,     2,   227,   222,
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
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   528,   534,   538,   540,   544,   546,   550,   552,   556,
     558,   560,   562,   564,   566,   568,   570,   572,   574,   576,
     578,   580,   582,   584,   586,   588,   589,   596,   599,   601,
     603,   605,   607,   609,   611,   613,   615,   617,   619,   621,
     623,   625,   627,   629,   631,   633,   636,   641,   646,   651,
     656,   661,   666,   671,   676,   681,   686,   691,   696,   701,
     706,   711,   712,   718,   722,   724,   726,   728,   729,   736,
     737,   743,   747,   749,   751,   753,   755,   758,   760,   762,
     764,   766,   768,   771,   772,   778,   782,   784,   786,   790,
     795,   800,   801,   808,   811,   813,   815,   817,   819,   821,
     823,   825,   827,   829,   832,   837,   842,   847,   852,   853,
     859,   863,   865,   867,   869,   871,   873,   875,   877,   879,
     881,   883,   885,   890,   895,   900,   901,   908,   911,   913,
     915,   917,   919,   922,   927,   932,   937,   943,   946,   948,
     950,   952,   957,   958,   965,   968,   970,   972,   974,   976,
     979,   984,   989,   990,   996,  1000,  1002,  1004,  1006,  1008,
    1010,  1012,  1014,  1016,  1018,  1020,  1022,  1023,  1030,  1033,
    1035,  1037,  1039,  1042,  1047,  1048,  1054,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1081,
    1088,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,
    1109,  1111,  1113,  1115,  1117,  1119,  1122,  1127,  1132,  1137,
    1142,  1147,  1152,  1157,  1162,  1163,  1169,  1173,  1175,  1177,
    1179,  1184,  1189,  1194,  1199,  1204,  1205,  1212,  1215,  1217,
    1219,  1221,  1223,  1228,  1233,  1234,  1241,  1244,  1246,  1248,
    1250,  1252,  1257,  1262,  1268,  1271,  1273,  1275,  1277,  1282,
    1283,  1290,  1293,  1295,  1297,  1299,  1301,  1306,  1311,  1317,
    1320,  1322,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,
    1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,
    1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,
    1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,
    1420,  1425,  1430,  1435,  1440,  1445,  1450,  1455,  1460,  1465,
    1470,  1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,  1515,
    1520,  1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,  1565,
    1570,  1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,  1615,
    1620,  1625,  1630,  1635,  1640,  1645,  1646,  1652,  1656,  1658,
    1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,  1678,
    1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,
    1700,  1702,  1703,  1709,  1713,  1715,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,
    1745,  1747,  1749,  1751,  1753,  1755,  1757,  1759,  1764,  1769,
    1774,  1780,  1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,
    1799,  1801,  1803,  1805,  1807,  1809,  1811,  1816,  1821,  1826,
    1831,  1836,  1841,  1846,  1851,  1856,  1861,  1866,  1871,  1877,
    1880,  1882,  1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,
    1903,  1908,  1913,  1918,  1923,  1928
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     229,     0,    -1,    -1,   229,   230,    -1,   264,    -1,   270,
      -1,   284,    -1,   483,    -1,   302,    -1,   325,    -1,   339,
      -1,   240,    -1,   498,    -1,   354,    -1,   361,    -1,   365,
      -1,   375,    -1,   384,    -1,   404,    -1,   410,    -1,   416,
      -1,   426,    -1,   420,    -1,   235,    -1,     1,   222,    -1,
       1,   223,    -1,    -1,   232,    -1,   105,   231,    -1,   105,
     139,   231,    -1,   105,   140,   231,    -1,   105,   141,   231,
      -1,   105,   142,   231,    -1,   105,   143,   231,    -1,   105,
     144,   231,    -1,   105,   145,   231,    -1,    -1,   234,    -1,
     105,   233,    -1,   105,     9,   233,    -1,   105,    10,   233,
      -1,   105,    11,   233,    -1,    95,   224,   236,   223,   222,
      -1,   236,   237,    -1,   237,    -1,   238,    -1,   239,    -1,
       1,   222,    -1,    94,   225,   122,   222,    -1,   118,   225,
     122,   222,    -1,   149,   224,   241,   223,   222,    -1,   241,
     242,    -1,   242,    -1,   253,    -1,   258,    -1,   263,    -1,
     255,    -1,   256,    -1,   257,    -1,   260,    -1,   261,    -1,
     262,    -1,   251,    -1,   250,    -1,   259,    -1,   254,    -1,
     249,    -1,   243,    -1,   244,    -1,   252,    -1,     1,   222,
      -1,   133,   225,   245,   222,    -1,   134,   225,   247,   222,
      -1,   245,   226,   246,    -1,   246,    -1,   135,    -1,   136,
      -1,   247,   226,   248,    -1,   248,    -1,   135,    -1,   136,
      -1,   131,   225,   122,   222,    -1,   129,   225,   122,   222,
      -1,   132,   225,   122,   222,    -1,   175,   225,   122,   222,
      -1,    96,   225,   122,   222,    -1,   151,   225,   122,   222,
      -1,    24,   225,   122,   222,    -1,    99,   225,   122,   222,
      -1,    98,   225,   122,   222,    -1,   216,   225,   122,   222,
      -1,   217,   225,   122,   222,    -1,   186,   225,   105,   222,
      -1,    82,   225,   105,   222,    -1,    86,   225,   105,   222,
      -1,    58,   225,   164,   222,    -1,     4,   224,   265,   223,
     222,    -1,   265,   266,    -1,   266,    -1,   267,    -1,   269,
      -1,   268,    -1,     1,   222,    -1,    96,   225,   122,   222,
      -1,    31,   225,   122,   222,    -1,    24,   225,   122,   222,
      -1,    72,   224,   271,   223,   222,    -1,   271,   272,    -1,
     272,    -1,   273,    -1,   274,    -1,     1,   222,    -1,   215,
     225,   164,   222,    -1,    -1,   275,   221,   224,   276,   223,
     222,    -1,   276,   277,    -1,   277,    -1,   278,    -1,   280,
      -1,   279,    -1,     1,   222,    -1,    96,   225,   122,   222,
      -1,   220,   225,   234,   222,    -1,   220,   225,   201,   222,
      -1,    -1,   155,   281,   225,   282,   222,    -1,   282,   226,
     283,    -1,   283,    -1,   213,    -1,   108,    -1,    40,    -1,
     178,    -1,    65,    -1,    63,    -1,   177,    -1,    -1,   108,
     285,   224,   286,   223,   222,    -1,   286,   287,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   294,    -1,   293,
      -1,   291,    -1,   292,    -1,   298,    -1,     1,   222,    -1,
      96,   225,   122,   222,    -1,   213,   225,   122,   222,    -1,
     117,   225,   122,   222,    -1,    32,   225,   164,   222,    -1,
     130,   225,   122,   222,    -1,    17,   225,   122,   222,    -1,
      -1,   198,   295,   225,   296,   222,    -1,   296,   226,   297,
      -1,   297,    -1,   170,    -1,   173,    -1,   174,    -1,   176,
      -1,   177,    -1,   181,    -1,    51,    -1,   195,    -1,   187,
      -1,   191,    -1,   199,    -1,   196,    -1,   179,    -1,   189,
      -1,   193,    -1,   182,    -1,   205,    -1,   171,    -1,   172,
      -1,   185,    -1,   188,    -1,   180,    -1,    -1,    36,   299,
     225,   300,   222,    -1,   300,   226,   301,    -1,   301,    -1,
      63,   227,   127,    -1,    63,    -1,    18,   227,   127,    -1,
      18,    -1,   150,   227,   127,    -1,   150,    -1,    65,    -1,
     212,    -1,   178,    -1,   200,    -1,   218,    -1,    40,    -1,
      25,    -1,   207,    -1,   126,    -1,     4,    -1,   189,    -1,
     204,    -1,   128,    -1,   194,    -1,    94,    -1,    -1,    17,
     303,   224,   304,   223,   222,    -1,   304,   305,    -1,   305,
      -1,   306,    -1,   316,    -1,   317,    -1,   307,    -1,   318,
      -1,   308,    -1,   309,    -1,   310,    -1,   311,    -1,   312,
      -1,   313,    -1,   314,    -1,   315,    -1,   319,    -1,   320,
      -1,   321,    -1,     1,   222,    -1,    96,   225,   122,   222,
      -1,   120,   225,   232,   222,    -1,   107,   225,   105,   222,
      -1,    19,   225,   232,   222,    -1,    84,   225,   105,   222,
      -1,    78,   225,   105,   222,    -1,    80,   225,   105,   222,
      -1,    79,   225,   105,   222,    -1,   146,   225,   234,   222,
      -1,   190,   225,   234,   222,    -1,    15,   225,   105,   222,
      -1,    16,   225,   105,   222,    -1,   106,   225,   105,   222,
      -1,    90,   225,   232,   222,    -1,    91,   225,   232,   222,
      -1,    -1,    36,   322,   225,   323,   222,    -1,   323,   226,
     324,    -1,   324,    -1,    92,    -1,    93,    -1,    -1,    71,
     326,   224,   331,   223,   222,    -1,    -1,    36,   328,   225,
     329,   222,    -1,   329,   226,   330,    -1,   330,    -1,   197,
      -1,    51,    -1,   192,    -1,   331,   332,    -1,   332,    -1,
     333,    -1,   327,    -1,   337,    -1,   338,    -1,     1,   222,
      -1,    -1,   121,   225,   335,   334,   222,    -1,   335,   226,
     336,    -1,   336,    -1,   105,    -1,   105,   168,   105,    -1,
      62,   225,   122,   222,    -1,    57,   225,   122,   222,    -1,
      -1,    48,   340,   224,   341,   223,   222,    -1,   341,   342,
      -1,   342,    -1,   343,    -1,   344,    -1,   345,    -1,   347,
      -1,   351,    -1,   352,    -1,   353,    -1,   346,    -1,     1,
     222,    -1,   213,   225,   122,   222,    -1,   117,   225,   122,
     222,    -1,    17,   225,   122,   222,    -1,    32,   225,   164,
     222,    -1,    -1,    36,   348,   225,   349,   222,    -1,   349,
     226,   350,    -1,   350,    -1,   158,    -1,    33,    -1,    66,
      -1,    49,    -1,    13,    -1,   104,    -1,    43,    -1,   138,
      -1,   206,    -1,    97,    -1,   157,   225,   122,   222,    -1,
     125,   225,   122,   222,    -1,   124,   225,   105,   222,    -1,
      -1,   137,   355,   224,   356,   223,   222,    -1,   356,   357,
      -1,   357,    -1,   358,    -1,   359,    -1,   360,    -1,     1,
     222,    -1,    73,   225,   122,   222,    -1,   123,   225,   122,
     222,    -1,    34,   225,   122,   222,    -1,   208,   224,   362,
     223,   222,    -1,   362,   363,    -1,   363,    -1,   364,    -1,
       1,    -1,    96,   225,   122,   222,    -1,    -1,   153,   366,
     224,   367,   223,   222,    -1,   367,   368,    -1,   368,    -1,
     369,    -1,   370,    -1,   371,    -1,     1,   222,    -1,    96,
     225,   122,   222,    -1,   213,   225,   122,   222,    -1,    -1,
     155,   372,   225,   373,   222,    -1,   373,   226,   374,    -1,
     374,    -1,    65,    -1,   212,    -1,   178,    -1,   200,    -1,
     218,    -1,   203,    -1,   137,    -1,   202,    -1,   185,    -1,
     169,    -1,    -1,   154,   376,   224,   377,   223,   222,    -1,
     377,   378,    -1,   378,    -1,   379,    -1,   380,    -1,     1,
     222,    -1,    96,   225,   122,   222,    -1,    -1,   155,   381,
     225,   382,   222,    -1,   382,   226,   383,    -1,   383,    -1,
      65,    -1,   212,    -1,   178,    -1,   200,    -1,   218,    -1,
     203,    -1,   137,    -1,   202,    -1,   185,    -1,   169,    -1,
      -1,    18,   385,   224,   386,   223,   222,    -1,   386,   387,
      -1,   387,    -1,   388,    -1,   389,    -1,   390,    -1,   391,
      -1,   392,    -1,   394,    -1,   393,    -1,   403,    -1,   395,
      -1,   400,    -1,   401,    -1,   402,    -1,   399,    -1,     1,
     222,    -1,    96,   225,   122,   222,    -1,    57,   225,   122,
     222,    -1,   216,   225,   122,   222,    -1,   147,   225,   122,
     222,    -1,     3,   225,   122,   222,    -1,   121,   225,   105,
     222,    -1,     5,   225,   183,   222,    -1,     5,   225,   184,
     222,    -1,    -1,    36,   396,   225,   397,   222,    -1,   397,
     226,   398,    -1,   398,    -1,     8,    -1,   197,    -1,    32,
     225,   164,   222,    -1,    59,   225,   122,   222,    -1,    69,
     225,   122,   222,    -1,    17,   225,   122,   222,    -1,   175,
     225,   122,   222,    -1,    -1,    63,   405,   224,   406,   223,
     222,    -1,   406,   407,    -1,   407,    -1,   408,    -1,   409,
      -1,     1,    -1,   213,   225,   122,   222,    -1,   123,   225,
     122,   222,    -1,    -1,    23,   411,   224,   412,   223,   222,
      -1,   412,   413,    -1,   413,    -1,   414,    -1,   415,    -1,
       1,    -1,    62,   225,   122,   222,    -1,   123,   225,   122,
     222,    -1,    34,   224,   417,   223,   222,    -1,   417,   418,
      -1,   418,    -1,   419,    -1,     1,    -1,    62,   225,   122,
     222,    -1,    -1,    38,   421,   224,   422,   223,   222,    -1,
     422,   423,    -1,   423,    -1,   424,    -1,   425,    -1,     1,
      -1,    96,   225,   122,   222,    -1,   123,   225,   122,   222,
      -1,    39,   224,   427,   223,   222,    -1,   427,   428,    -1,
     428,    -1,   437,    -1,   438,    -1,   440,    -1,   441,    -1,
     442,    -1,   443,    -1,   444,    -1,   445,    -1,   446,    -1,
     447,    -1,   436,    -1,   449,    -1,   450,    -1,   464,    -1,
     452,    -1,   454,    -1,   456,    -1,   455,    -1,   459,    -1,
     453,    -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,
     476,    -1,   465,    -1,   466,    -1,   467,    -1,   472,    -1,
     457,    -1,   458,    -1,   482,    -1,   480,    -1,   481,    -1,
     439,    -1,   471,    -1,   448,    -1,   469,    -1,   470,    -1,
     435,    -1,   430,    -1,   431,    -1,   432,    -1,   433,    -1,
     434,    -1,   451,    -1,   429,    -1,   468,    -1,     1,    -1,
      87,   225,   105,   222,    -1,    42,   225,   164,   222,    -1,
      41,   225,   232,   222,    -1,    44,   225,   232,   222,    -1,
      45,   225,   105,   222,    -1,    46,   225,   105,   222,    -1,
     152,   225,   164,   222,    -1,    64,   225,   232,   222,    -1,
      56,   225,   164,   222,    -1,    60,   225,   164,   222,    -1,
      28,   225,   164,   222,    -1,    35,   225,   164,   222,    -1,
       6,   225,   164,   222,    -1,    83,   225,   232,   222,    -1,
      81,   225,   105,   222,    -1,    74,   225,   105,   222,    -1,
       7,   225,   232,   222,    -1,   167,   225,   232,   222,    -1,
     166,   225,   232,   222,    -1,    50,   225,   105,   222,    -1,
      61,   225,   164,   222,    -1,   219,   225,   164,   222,    -1,
     159,   225,   164,   222,    -1,   162,   225,   164,   222,    -1,
     163,   225,   164,   222,    -1,   161,   225,   164,   222,    -1,
     161,   225,   165,   222,    -1,   160,   225,   164,   222,    -1,
     160,   225,   165,   222,    -1,   115,   225,   232,   222,    -1,
      12,   225,   232,   222,    -1,   109,   225,   164,   222,    -1,
     116,   225,   232,   222,    -1,   156,   225,   164,   222,    -1,
     103,   225,   164,   222,    -1,   211,   225,   164,   222,    -1,
     111,   225,   164,   222,    -1,    29,   225,   105,   222,    -1,
      85,   225,   105,   222,    -1,   214,   225,   164,   222,    -1,
      30,   225,   122,   222,    -1,   209,   225,   122,   222,    -1,
     119,   225,   164,   222,    -1,    26,   225,   164,   222,    -1,
     210,   225,   232,   222,    -1,    -1,   112,   473,   225,   474,
     222,    -1,   474,   226,   475,    -1,   475,    -1,   170,    -1,
     173,    -1,   174,    -1,   176,    -1,   177,    -1,   181,    -1,
      51,    -1,   195,    -1,   187,    -1,   191,    -1,   199,    -1,
     196,    -1,   179,    -1,   189,    -1,   193,    -1,   182,    -1,
     205,    -1,   171,    -1,   172,    -1,   185,    -1,   188,    -1,
     180,    -1,    -1,   110,   477,   225,   478,   222,    -1,   478,
     226,   479,    -1,   479,    -1,   170,    -1,   173,    -1,   174,
      -1,   176,    -1,   177,    -1,   181,    -1,   195,    -1,    51,
      -1,   187,    -1,   191,    -1,   199,    -1,   196,    -1,   179,
      -1,   189,    -1,   193,    -1,   182,    -1,   205,    -1,   171,
      -1,   172,    -1,   185,    -1,   188,    -1,   180,    -1,    88,
     225,   105,   222,    -1,    89,   225,   105,   222,    -1,    20,
     225,   105,   222,    -1,    14,   224,   484,   223,   222,    -1,
     484,   485,    -1,   485,    -1,   491,    -1,   487,    -1,   488,
      -1,   489,    -1,   490,    -1,   492,    -1,   493,    -1,   494,
      -1,   495,    -1,   496,    -1,   497,    -1,   486,    -1,     1,
      -1,    27,   225,   164,   222,    -1,    67,   225,   232,   222,
      -1,    68,   225,   232,   222,    -1,    77,   225,   105,   222,
      -1,    76,   225,   105,   222,    -1,    75,   225,   105,   222,
      -1,    22,   225,   105,   222,    -1,    21,   225,   105,   222,
      -1,   101,   225,   164,   222,    -1,   102,   225,   164,   222,
      -1,   113,   225,   105,   222,    -1,   114,   225,   232,   222,
      -1,   148,   224,   499,   223,   222,    -1,   499,   500,    -1,
     500,    -1,   501,    -1,   502,    -1,   503,    -1,   505,    -1,
     506,    -1,   504,    -1,   507,    -1,     1,    -1,    37,   225,
     164,   222,    -1,    54,   225,   164,   222,    -1,    55,   225,
     164,   222,    -1,    52,   225,   122,   222,    -1,    70,   225,
     232,   222,    -1,    51,   225,   164,   222,    -1,    53,   225,
     164,   222,    -1
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
    1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,  1179,
    1186,  1185,  1191,  1191,  1192,  1196,  1200,  1204,  1208,  1212,
    1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,
    1256,  1260,  1264,  1268,  1272,  1283,  1282,  1343,  1343,  1344,
    1345,  1345,  1346,  1347,  1348,  1349,  1350,  1351,  1352,  1353,
    1354,  1354,  1355,  1356,  1357,  1358,  1360,  1366,  1372,  1378,
    1384,  1390,  1396,  1402,  1408,  1414,  1421,  1427,  1433,  1439,
    1448,  1458,  1457,  1463,  1463,  1464,  1468,  1479,  1478,  1485,
    1484,  1489,  1489,  1490,  1494,  1498,  1504,  1504,  1505,  1505,
    1505,  1505,  1505,  1507,  1507,  1509,  1509,  1511,  1525,  1545,
    1551,  1561,  1560,  1602,  1602,  1603,  1603,  1603,  1603,  1604,
    1604,  1604,  1605,  1605,  1607,  1613,  1619,  1625,  1637,  1636,
    1642,  1642,  1643,  1647,  1651,  1655,  1659,  1663,  1667,  1671,
    1675,  1679,  1685,  1699,  1708,  1722,  1721,  1736,  1736,  1737,
    1737,  1737,  1737,  1739,  1745,  1751,  1761,  1763,  1763,  1764,
    1764,  1766,  1782,  1781,  1806,  1806,  1807,  1807,  1807,  1807,
    1809,  1815,  1835,  1834,  1840,  1840,  1841,  1845,  1849,  1853,
    1857,  1861,  1865,  1869,  1873,  1877,  1887,  1886,  1907,  1907,
    1908,  1908,  1908,  1910,  1917,  1916,  1922,  1922,  1923,  1927,
    1931,  1935,  1939,  1943,  1947,  1951,  1955,  1959,  1969,  1968,
    2034,  2034,  2035,  2035,  2035,  2036,  2036,  2037,  2037,  2037,
    2038,  2038,  2038,  2039,  2039,  2040,  2042,  2048,  2054,  2060,
    2073,  2086,  2092,  2096,  2105,  2104,  2109,  2109,  2110,  2114,
    2120,  2131,  2137,  2143,  2149,  2165,  2164,  2190,  2190,  2191,
    2191,  2191,  2193,  2213,  2223,  2222,  2249,  2249,  2250,  2250,
    2250,  2252,  2258,  2267,  2269,  2269,  2270,  2270,  2272,  2290,
    2289,  2312,  2312,  2313,  2313,  2313,  2315,  2321,  2330,  2333,
    2333,  2334,  2334,  2335,  2335,  2336,  2336,  2337,  2337,  2338,
    2338,  2339,  2340,  2341,  2341,  2342,  2342,  2343,  2343,  2344,
    2344,  2345,  2345,  2346,  2346,  2347,  2347,  2348,  2348,  2349,
    2349,  2350,  2350,  2351,  2351,  2352,  2353,  2353,  2354,  2355,
    2356,  2356,  2357,  2357,  2358,  2359,  2360,  2361,  2361,  2362,
    2365,  2370,  2376,  2382,  2388,  2393,  2398,  2403,  2408,  2413,
    2418,  2423,  2428,  2433,  2438,  2443,  2448,  2453,  2458,  2464,
    2475,  2480,  2485,  2490,  2495,  2500,  2503,  2508,  2511,  2516,
    2521,  2526,  2531,  2536,  2541,  2546,  2551,  2556,  2561,  2566,
    2571,  2580,  2589,  2594,  2599,  2605,  2604,  2609,  2609,  2610,
    2613,  2616,  2619,  2622,  2625,  2628,  2631,  2634,  2637,  2640,
    2643,  2646,  2649,  2652,  2655,  2658,  2661,  2664,  2667,  2670,
    2673,  2679,  2678,  2683,  2683,  2684,  2687,  2690,  2693,  2696,
    2699,  2702,  2705,  2708,  2711,  2714,  2717,  2720,  2723,  2726,
    2729,  2732,  2735,  2738,  2741,  2744,  2747,  2752,  2757,  2762,
    2771,  2774,  2774,  2775,  2776,  2776,  2777,  2777,  2778,  2779,
    2780,  2781,  2782,  2782,  2783,  2783,  2785,  2790,  2795,  2800,
    2805,  2810,  2815,  2820,  2825,  2830,  2835,  2840,  2848,  2851,
    2851,  2852,  2852,  2853,  2854,  2855,  2855,  2856,  2857,  2859,
    2865,  2871,  2877,  2886,  2900,  2906
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
  "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "REASON", "REDIRPORT", "REDIRSERV", "REHASH",
  "REMOTE", "REMOTEBAN", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD",
  "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "SQUIT",
  "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE",
  "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA",
  "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FARCONNECT", "T_FULL", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE", "T_NONONREG",
  "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SET",
  "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNDLINE",
  "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS", "T_WALLOP",
  "T_WEBIRC", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TRUE_NO_OPER_FLOOD", "UNKLINE", "USER", "USE_EGD", "USE_LOGGING",
  "VHOST", "VHOST6", "XLINE", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'",
  "'}'", "'{'", "'='", "','", "':'", "$accept", "conf", "conf_item",
  "timespec_", "timespec", "sizespec_", "sizespec", "modules_entry",
  "modules_items", "modules_item", "modules_module", "modules_path",
  "serverinfo_entry", "serverinfo_items", "serverinfo_item",
  "serverinfo_ssl_client_method", "serverinfo_ssl_server_method",
  "client_method_types", "client_method_type_item", "server_method_types",
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
     475,   476,    59,   125,   123,    61,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   235,   236,   236,   237,   237,   237,   238,   239,
     240,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   244,   245,   245,   246,   246,   247,   247,   248,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   265,   266,
     266,   266,   266,   267,   268,   269,   270,   271,   271,   272,
     272,   272,   273,   275,   274,   276,   276,   277,   277,   277,
     277,   278,   279,   279,   281,   280,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   285,   284,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   289,
     290,   291,   292,   293,   295,   294,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     299,   298,   300,   300,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   303,   302,   304,   304,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   322,   321,   323,   323,   324,   324,   326,   325,   328,
     327,   329,   329,   330,   330,   330,   331,   331,   332,   332,
     332,   332,   332,   334,   333,   335,   335,   336,   336,   337,
     338,   340,   339,   341,   341,   342,   342,   342,   342,   342,
     342,   342,   342,   342,   343,   344,   345,   346,   348,   347,
     349,   349,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   351,   352,   353,   355,   354,   356,   356,   357,
     357,   357,   357,   358,   359,   360,   361,   362,   362,   363,
     363,   364,   366,   365,   367,   367,   368,   368,   368,   368,
     369,   370,   372,   371,   373,   373,   374,   374,   374,   374,
     374,   374,   374,   374,   374,   374,   376,   375,   377,   377,
     378,   378,   378,   379,   381,   380,   382,   382,   383,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   385,   384,
     386,   386,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   388,   389,   390,   391,
     392,   393,   394,   394,   396,   395,   397,   397,   398,   398,
     399,   400,   401,   402,   403,   405,   404,   406,   406,   407,
     407,   407,   408,   409,   411,   410,   412,   412,   413,   413,
     413,   414,   415,   416,   417,   417,   418,   418,   419,   421,
     420,   422,   422,   423,   423,   423,   424,   425,   426,   427,
     427,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   454,   455,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   473,   472,   474,   474,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   477,   476,   478,   478,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   480,   481,   482,
     483,   484,   484,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     499,   500,   500,   500,   500,   500,   500,   500,   500,   501,
     502,   503,   504,   505,   506,   507
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     0,     6,     0,
       5,     3,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   205,   368,   414,     0,
     429,     0,   271,   405,   247,     0,     0,   135,   305,     0,
       0,   322,   346,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     592,   604,   594,   595,   596,   597,   593,   598,   599,   600,
     601,   602,   603,     0,     0,     0,   427,     0,     0,   425,
     426,     0,   489,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   561,     0,   535,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   440,   487,   481,   482,   483,   484,   485,   480,
     451,   441,   442,   475,   443,   444,   445,   446,   447,   448,
     449,   450,   477,   452,   453,   486,   455,   460,   456,   458,
     457,   470,   471,   459,   461,   462,   463,   464,   454,   466,
     467,   468,   488,   478,   479,   476,   469,   465,   473,   474,
     472,     0,     0,     0,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,    44,    45,    46,     0,     0,
     628,     0,     0,     0,     0,     0,     0,     0,     0,   620,
     621,   622,   623,   626,   624,   625,   627,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    67,    68,    66,
      63,    62,    69,    53,    65,    56,    57,    58,    54,    64,
      59,    60,    61,    55,     0,     0,   320,     0,     0,   318,
     319,   102,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     591,     0,     0,     0,     0,   241,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   208,
     209,   212,   214,   215,   216,   217,   218,   219,   220,   221,
     210,   211,   213,   222,   223,   224,     0,     0,     0,     0,
       0,   394,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   371,   372,   373,   374,   375,   376,   378,   377,   380,
     384,   381,   382,   383,   379,   420,     0,     0,     0,   417,
     418,   419,     0,     0,   424,   435,     0,     0,     0,   432,
     433,   434,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   439,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,   274,   275,   276,   277,   282,   278,   279,   280,
     281,   411,     0,     0,     0,   408,   409,   410,     0,   249,
       0,     0,     0,   259,     0,   257,   258,   260,   261,   111,
       0,     0,   107,     0,    47,     0,     0,     0,    43,     0,
       0,     0,   180,     0,     0,     0,   154,     0,     0,   138,
     139,   140,   141,   144,   145,   143,   142,   146,     0,     0,
       0,     0,     0,   308,   309,   310,   311,     0,     0,     0,
       0,     0,     0,     0,     0,   619,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,   332,     0,
       0,   325,   326,   327,   328,     0,     0,   354,     0,   349,
     350,   351,     0,     0,   317,     0,     0,     0,    96,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   225,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   207,   385,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   370,     0,     0,
       0,   416,     0,   423,     0,     0,     0,   431,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   438,   283,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   273,
       0,     0,     0,   407,   262,     0,     0,     0,     0,     0,
     256,     0,   106,     0,     0,     0,    42,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   312,     0,
       0,     0,     0,   307,     0,     0,     0,     0,     0,     0,
       0,   618,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   329,     0,     0,     0,
       0,   324,   352,     0,     0,     0,   348,     0,   316,   105,
     104,   103,   613,   612,   606,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   607,   608,   611,   610,   609,   614,
     615,   616,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
     206,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   369,     0,     0,   415,   428,
       0,     0,   430,   502,   506,   520,   589,   533,   500,   527,
     530,   501,   492,   491,   493,   494,   495,   509,   498,   499,
     510,   497,   505,   504,   503,   528,   490,   587,   588,   524,
     521,   572,   565,   582,   583,   566,   567,   568,   569,   577,
     586,   570,   580,   584,   573,   585,   578,   574,   579,   571,
     576,   575,   581,     0,   564,   526,   545,   539,   556,   557,
     540,   541,   542,   543,   551,   560,   544,   554,   558,   547,
     559,   552,   548,   553,   546,   550,   549,   555,     0,   538,
     519,   522,   532,   496,   523,   512,   517,   518,   515,   516,
     513,   514,   508,   507,   531,   534,   525,   529,   511,     0,
       0,     0,     0,     0,     0,     0,     0,   272,     0,     0,
     406,     0,     0,     0,   267,   263,   266,   248,   112,     0,
       0,   124,     0,     0,   116,   117,   119,   118,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,   306,   629,   634,   632,   635,   630,   631,   633,
      87,    95,    93,    94,    85,    89,    88,    82,    81,    83,
      71,     0,    72,     0,    86,    84,    92,    90,    91,     0,
       0,     0,   323,     0,     0,   347,   321,    29,    30,    31,
      32,    33,    34,    35,   236,   237,   229,   245,   246,     0,
     244,   231,   233,   232,   230,   239,   240,   226,   238,   228,
     227,    36,    36,    36,    38,    37,   234,   235,   390,   392,
     393,   403,   400,   398,   399,     0,   397,   387,   401,   402,
     386,   391,   389,   404,   388,   421,   422,   436,   437,   562,
       0,   536,     0,   286,   287,   296,   293,   298,   295,   294,
     301,   297,   299,   292,   300,     0,   291,   285,   304,   303,
     302,   284,   413,   412,   254,   255,   253,     0,   252,   270,
     269,     0,     0,     0,   120,     0,     0,     0,     0,   115,
     153,   151,   199,   187,   196,   195,   185,   190,   204,   198,
     202,   189,   192,   200,   203,   193,   201,   197,   191,   194,
       0,   183,   148,   150,   152,   164,   158,   175,   176,   159,
     160,   161,   162,   170,   179,   163,   173,   177,   166,   178,
     171,   167,   172,   165,   169,   168,   174,     0,   157,   149,
     315,   313,   314,    73,    77,   330,   336,   342,   345,   338,
     344,   339,   343,   341,   337,   340,     0,   335,   331,   353,
     358,   364,   367,   360,   366,   361,   365,   363,   359,   362,
       0,   357,   242,     0,    39,    40,    41,   395,     0,   563,
     537,   289,     0,   250,     0,   268,   265,   264,     0,     0,
       0,     0,   114,     0,     0,     0,   181,     0,   155,     0,
     333,     0,   355,     0,   243,   396,   290,   251,   121,   130,
     133,   132,   129,   134,   131,   128,     0,   127,   123,   122,
     186,   184,   188,   182,   156,   334,   356,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   782,   783,  1034,  1035,    25,   224,   225,
     226,   227,    26,   265,   266,   267,   268,   744,   745,   748,
     749,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,    27,    71,    72,    73,
      74,    75,    28,   216,   217,   218,   219,   220,   953,   954,
     955,   956,   957,  1096,  1226,  1227,    29,    60,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   714,  1147,  1148,
     507,   710,  1120,  1121,    30,    49,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   587,  1019,  1020,    31,    57,   473,
     695,  1087,  1088,   474,   475,   476,  1093,   945,   946,   477,
     478,    32,    55,   451,   452,   453,   454,   455,   456,   457,
     682,  1075,  1076,   458,   459,   460,    33,    61,   512,   513,
     514,   515,   516,    34,   288,   289,   290,    35,    64,   550,
     551,   552,   553,   554,   758,  1166,  1167,    36,    65,   558,
     559,   560,   561,   764,  1180,  1181,    37,    50,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   607,  1045,
    1046,   370,   371,   372,   373,   374,    38,    56,   464,   465,
     466,   467,    39,    51,   378,   379,   380,   381,    40,   108,
     109,   110,    41,    53,   388,   389,   390,   391,    42,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   422,   908,   909,   207,   420,
     883,   884,   208,   209,   210,    43,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      44,   238,   239,   240,   241,   242,   243,   244,   245,   246
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -743
static const yytype_int16 yypact[] =
{
    -743,   637,  -743,  -189,  -216,  -213,  -743,  -743,  -743,  -210,
    -743,  -200,  -743,  -743,  -743,  -193,  -163,  -743,  -743,  -151,
    -142,  -743,  -743,  -124,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   285,   877,  -105,
    -102,   -97,    44,   -94,   404,   -74,   -50,   -48,    46,     3,
     -38,   -28,   314,   450,    -1,    41,     6,  -158,   -93,   -26,
     -16,     8,  -743,  -743,  -743,  -743,  -743,    20,    23,    72,
      73,    80,    85,    95,    99,   100,   107,   118,   119,   281,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,   634,   521,    26,  -743,   122,    19,  -743,
    -743,     5,  -743,   125,   128,   135,   146,   147,   155,   163,
     164,   165,   166,   167,   168,   171,   172,   174,   175,   179,
     182,   183,   184,   187,   188,   189,   190,   194,   195,   198,
     201,  -743,   202,  -743,   203,   206,   211,   212,   213,   215,
     216,   217,   218,   219,   222,   227,   228,   230,   231,   232,
     233,   117,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   385,    11,    36,    30,   236,    28,  -743,  -743,  -743,
     121,   133,   238,   241,    90,  -743,  -743,  -743,   305,   130,
    -743,   242,   244,   245,   246,   247,   252,   255,    16,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   181,   256,   257,
     258,   259,   261,   263,   265,   269,   270,   271,   272,   273,
     275,   276,   280,   287,   292,    84,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,    17,    14,  -743,   296,    15,  -743,
    -743,  -743,   384,   403,   406,   307,  -743,   425,   426,   369,
     429,   429,   430,   432,   434,   376,   377,   438,   429,   322,
    -743,   325,   326,   329,   330,  -743,   333,   334,   336,   337,
     343,   344,   347,   349,   350,   351,   360,   363,   239,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   328,   364,   366,   367,
     370,  -743,   371,   372,   374,   375,   378,   379,   380,   381,
      18,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   382,   387,    45,  -743,
    -743,  -743,   480,   394,  -743,  -743,   396,   397,    89,  -743,
    -743,  -743,   455,   429,   429,   522,   464,   465,   525,   509,
     469,   429,   475,   429,   535,   538,   539,   481,   482,   483,
     429,   543,   547,   429,   552,   553,   554,   556,   498,   500,
     444,   510,   459,   429,   429,   524,   527,   528,   529,  -122,
    -113,   530,   534,   429,   429,   564,   429,   537,   540,   542,
     485,  -743,   489,   477,   478,  -743,   490,   491,   492,   495,
     496,   139,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   497,   501,    98,  -743,  -743,  -743,   505,  -743,
     503,   504,   506,  -743,    27,  -743,  -743,  -743,  -743,  -743,
     559,   511,  -743,   512,  -743,   612,   613,   516,  -743,   517,
     518,   519,  -743,   523,   526,   531,  -743,   532,    24,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   520,   536,
     541,   545,    21,  -743,  -743,  -743,  -743,   585,   586,   630,
     589,   591,   595,   429,   546,  -743,  -743,   638,   598,   660,
     662,   642,   649,   650,   653,   655,   656,   -19,    53,   657,
     661,   677,   666,   667,   562,  -743,   575,   580,  -743,   581,
      91,  -743,  -743,  -743,  -743,   578,   583,  -743,    64,  -743,
    -743,  -743,   690,   592,  -743,   594,   597,   600,  -743,   601,
     603,   604,   234,   606,   615,   620,   621,   627,   629,   631,
     635,   639,  -743,  -743,   715,   729,   429,   645,   751,   754,
     755,   757,   429,   429,   741,   768,   774,   429,   776,   776,
     663,  -743,  -743,   765,    88,   767,   728,   668,   773,   775,
     779,   780,   791,   781,   783,   784,   685,  -743,   786,   787,
     688,  -743,   689,  -743,   790,   792,   691,  -743,   693,   694,
     696,   697,   698,   699,   700,   701,   702,   703,   704,   705,
     706,   707,   708,   709,   710,   711,   712,   713,   714,   716,
     717,   718,   719,   720,   721,   724,   622,   725,   659,   726,
     727,   733,   734,   735,   736,   737,   738,   739,   740,   742,
     743,   744,   745,   746,   747,   748,   749,   750,  -743,  -743,
     795,   799,   752,   815,   845,   829,   851,   852,   753,  -743,
     854,   858,   759,  -743,  -743,   758,   860,   862,   880,   764,
    -743,   766,  -743,   178,   770,   771,  -743,  -743,   865,   825,
     769,   873,   874,   875,   777,   876,   778,  -743,  -743,   879,
     881,   882,   785,  -743,   788,   789,   793,   794,   796,   797,
     798,  -743,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,  -743,  -743,  -196,  -743,  -743,  -743,  -186,  -743,
     810,   811,   812,   813,   814,  -743,  -743,   883,   816,   884,
     817,  -743,  -743,   886,   818,   820,  -743,   822,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,   429,   429,   429,   429,   429,
     429,   429,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,   823,   824,   826,   200,   827,   828,   830,
     831,   832,   833,   834,   835,   836,   837,    48,   838,   839,
    -743,   840,   841,   842,   843,   844,    -3,   846,   847,   848,
     849,   850,   853,   855,   856,  -743,   857,   859,  -743,  -743,
     861,   863,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -178,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -160,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   864,
     866,   321,   867,   868,   869,   870,   871,  -743,   872,   878,
    -743,    -2,   885,   887,   899,   821,  -743,  -743,  -743,   888,
     889,  -743,   890,    37,  -743,  -743,  -743,  -743,  -743,  -743,
     891,   894,   569,   895,   896,   897,   695,   898,  -743,   900,
     901,   902,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   -19,  -743,    53,  -743,  -743,  -743,  -743,  -743,   903,
     408,   904,  -743,   905,   487,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -148,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,   776,   776,   776,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -146,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     622,  -743,   659,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -143,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   -71,  -743,  -743,
    -743,   907,   880,   906,  -743,   892,   908,   -92,   909,  -743,
    -743,  -743,  -743,   772,  -743,  -743,   782,  -743,  -743,  -743,
    -743,   910,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     -25,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,   -15,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   -12,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
      40,  -743,  -743,   200,  -743,  -743,  -743,  -743,    -3,  -743,
    -743,  -743,   321,  -743,    -2,  -743,  -743,  -743,   912,   298,
     913,   914,  -743,   911,   924,   946,  -743,   569,  -743,   695,
    -743,   408,  -743,   487,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,    59,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   298,  -743
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -743,  -743,  -743,   -98,  -298,  -742,  -598,  -743,  -743,   915,
    -743,  -743,  -743,  -743,   756,  -743,  -743,  -743,    22,  -743,
      47,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   966,  -743,
    -743,  -743,  -743,  -743,   916,  -743,  -743,  -743,  -743,   123,
    -743,  -743,  -743,  -743,  -743,  -221,  -743,  -743,  -743,   576,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -129,
    -743,  -743,  -743,  -125,  -743,  -743,  -743,   819,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,   -99,  -743,  -743,  -743,
    -743,  -743,  -107,  -743,   623,  -743,  -743,  -743,     4,  -743,
    -743,  -743,  -743,  -743,   644,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   -91,  -743,  -743,  -743,  -743,  -743,  -743,   587,
    -743,  -743,  -743,  -743,  -743,   893,  -743,  -743,  -743,  -743,
     548,  -743,  -743,  -743,  -743,  -743,  -109,  -743,  -743,  -743,
     550,  -743,  -743,  -743,  -743,  -110,  -743,  -743,  -743,   761,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
     -84,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,   641,
    -743,  -743,  -743,  -743,  -743,   760,  -743,  -743,  -743,  -743,
     998,  -743,  -743,  -743,  -743,   723,  -743,  -743,  -743,  -743,
     951,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,    67,  -743,  -743,
    -743,    70,  -743,  -743,  -743,  -743,  -743,  1051,  -743,  -743,
    -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,  -743,
    -743,  -743,   917,  -743,  -743,  -743,  -743,  -743,  -743,  -743
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     808,   809,   573,   574,   221,  1043,   385,   286,    47,    67,
     581,    48,   461,   807,    52,   555,   286,   230,   546,   346,
     106,   347,   508,   348,    54,   489,   990,   375,   468,   214,
     991,    58,    68,    45,    46,   349,   992,   468,   949,    69,
     993,   490,   665,   666,  1059,   106,   375,   214,  1060,  1084,
     350,   667,   668,   231,   351,   509,   491,  1031,  1032,  1033,
     492,    59,  1061,   469,   291,   555,  1062,   232,   233,   234,
     235,   236,   469,    62,  1182,   352,  1187,   353,  1183,  1191,
    1188,   107,    63,  1192,   470,   247,   237,   354,   376,   471,
     385,   221,   546,   470,   510,   629,   630,   222,   471,   461,
      66,   386,   287,   637,    70,   639,   107,   376,   248,  1200,
     556,   287,   646,   547,   355,   649,   742,   743,   112,   103,
     493,   223,   104,   113,   114,   659,   660,   105,   387,   115,
     111,   508,   292,   950,   462,   671,   672,   116,   674,   356,
     442,   494,   249,   117,   511,   118,   119,   120,   472,   377,
     211,  1193,   121,   807,   495,  1194,   443,   472,   122,   123,
     556,   124,   125,   126,   509,   357,   250,   127,   377,   557,
     251,   444,   548,   128,   212,   445,   213,   129,   130,   949,
     252,   131,   253,   254,   222,   386,   228,   547,   746,   747,
    1085,   132,   951,   358,  1044,  1086,   229,  1206,   133,   293,
     134,  1207,   135,   510,   136,   137,   138,  1208,   223,   294,
    1210,  1209,   387,   255,  1211,   256,   257,   258,   259,   557,
     139,   462,   496,   284,   463,   730,   140,   141,   142,   143,
     549,   295,   144,   145,   359,   260,   146,   497,   563,   524,
     311,   616,   383,   215,   722,   297,   548,   716,   298,  -113,
     699,   481,   479,   511,   312,   313,   446,   952,   314,   261,
    1098,   215,  1212,   447,   448,   285,  1213,  -113,   620,   147,
     262,   812,   813,   148,   950,   315,   149,   150,   151,   152,
     153,  1237,    76,   154,   155,  1238,    67,   765,   795,  1184,
    1185,  1186,  1017,  1018,   801,   802,   449,   299,   300,   806,
     263,   264,    77,    78,   549,   301,   489,   544,    79,    68,
     302,   463,   626,   487,   760,   230,    69,   316,   317,   318,
     303,   692,   490,   319,   304,   305,   156,   157,   158,   320,
     321,   159,   306,   951,  1065,   322,   160,   491,  1219,   572,
     440,   492,   483,   307,   308,   323,   324,   382,    80,    81,
     392,   231,   450,   393,  1066,   484,    82,    83,    84,   325,
     394,  1220,   688,  1221,  1067,   232,   233,   234,   235,   236,
    1068,   395,   396,   775,   776,   777,   778,   779,   780,   781,
     397,    70,    85,    86,   237,   326,   442,  1069,   398,   399,
     400,   401,   402,   403,    87,    88,   404,   405,   952,   406,
     407,   493,   443,   526,   408,   112,  1222,   409,   410,   411,
     113,   114,   412,   413,   414,   415,   115,   444,  1070,   416,
     417,   445,   494,   418,   116,  1071,   419,   421,   423,   327,
     117,   424,   118,   119,   120,   495,   425,   426,   427,   121,
     428,   429,   430,   431,   432,   122,   123,   433,   124,   125,
     126,   247,   434,   435,   127,   436,   437,   438,   439,  1072,
     128,   480,   600,   485,   129,   130,   486,   517,   131,   518,
     519,   520,   521,  1156,   248,  1223,  1224,   522,   132,  1073,
     523,   527,   528,   529,   530,   133,   531,   134,   532,   135,
     533,   136,   137,   138,   534,   535,   536,   537,   538,  1201,
     539,   540,   446,   496,   309,   541,   565,   139,   249,   447,
     448,  1225,   542,   140,   141,   142,   143,   543,   497,   144,
     145,   562,   346,   146,   347,   566,   348,  1074,   567,   568,
     569,   570,   250,   571,   572,   575,   251,   576,   349,   577,
     578,   579,   449,   580,   582,  1157,   252,   583,   253,   254,
     602,   584,  1170,   350,   585,   586,   147,   351,   588,   589,
     148,   590,   591,   149,   150,   151,   152,   153,   592,   593,
     154,   155,   594,  1102,   595,   596,   597,  1158,   352,   255,
     353,   256,   257,   258,   259,   598,  1159,  1103,   599,   603,
     354,   604,   605,  1160,  1104,   606,   608,   609,   450,   610,
     611,   260,   622,   612,   613,   614,   615,   618,  1161,  1105,
    1162,  1163,   619,   156,   157,   158,   623,   355,   159,   628,
    1164,   624,   625,   160,  1171,   261,  1165,   631,   632,   633,
     634,   635,  1106,   636,  1107,   311,   262,     2,     3,   638,
     640,     4,   356,   641,   642,   643,   644,   645,   647,   312,
     313,     5,   648,   314,     6,     7,  1172,   650,   651,   652,
       8,   653,   654,  1108,   655,  1173,   263,   264,   357,   656,
     315,     9,  1174,   861,   657,    10,    11,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,   658,    12,   673,  1175,   661,  1176,
    1177,   662,   663,   664,   669,  1109,   358,  1110,   670,  1178,
      13,   675,   680,   681,   676,  1179,   677,   678,    14,    15,
     886,   679,   316,   317,   318,   683,   684,   685,   319,  1111,
     686,   687,   690,   701,   320,   321,   691,   694,   696,   697,
     322,   698,    16,   702,   704,   705,   703,   359,   706,   707,
     323,   324,   718,   708,   709,    17,  1125,  1112,   711,   724,
     725,   712,   726,   727,   325,   728,   713,   715,  1113,   729,
     732,   719,   733,  1114,   736,   734,   720,   735,   731,  1115,
     721,   737,   738,  1116,    18,   739,  1117,   740,   741,   750,
     326,  1118,   752,   751,   755,    19,    20,  1119,   753,   754,
      21,    22,   862,   863,   864,   865,   866,   756,   867,   868,
     762,   869,   870,   871,   872,   757,   759,   873,   763,   874,
     875,   876,   767,   877,   768,   878,   769,   879,   880,   770,
     793,   881,   771,   772,   327,   773,   774,   882,   784,   887,
     888,   889,   890,   891,   794,   892,   893,   785,   894,   895,
     896,   897,   786,   787,   898,    23,   899,   900,   901,   788,
     902,   789,   903,   790,   904,   905,   797,   791,   906,   798,
     799,   792,   800,   803,   907,  1126,  1127,  1128,  1129,  1130,
     796,  1131,  1132,   804,  1133,  1134,  1135,  1136,    76,   805,
    1137,   807,  1138,  1139,  1140,   810,  1141,   811,  1142,   814,
    1143,  1144,   815,   816,  1145,   817,   821,   818,    77,    78,
    1146,   819,   820,   822,    79,   823,   824,   825,   826,   827,
     828,   829,   830,   832,   831,   833,   834,   929,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   850,   851,   852,   853,   932,   854,   855,
     856,   857,   858,   859,    80,    81,   860,   885,   910,   911,
     933,   934,    82,    83,    84,   912,   913,   914,   915,   916,
     917,   918,   919,   930,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   935,   936,   937,   938,   931,    85,    86,
     939,   940,   942,   941,   943,   944,   947,   960,   948,   961,
      87,    88,   958,   959,   962,   963,   964,   965,   967,  1203,
     968,   969,   966,   970,   971,   999,  1001,   972,  1003,  1204,
     973,   974,  1195,  1153,  1198,   975,   976,  1239,   977,   978,
     979,   545,   980,   981,   982,   983,   984,   985,   986,   987,
     988,   989,   994,   995,   996,   997,   998,   296,  1230,  1002,
    1154,  1000,  1005,  1004,  1006,  1014,  1015,  1092,  1016,  1021,
    1022,  1231,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1030,
    1036,  1037,  1038,  1039,  1040,  1041,  1042,  1091,  1047,  1048,
    1049,  1050,  1051,  1232,   717,  1052,  1099,  1053,  1054,  1055,
    1234,  1056,  1233,  1057,  1214,  1058,  1063,  1217,  1064,  1077,
    1078,  1079,  1080,  1081,  1082,   689,  1196,   700,   761,   723,
    1083,  1216,  1235,  1236,  1215,   693,   384,  1089,   766,  1090,
    1094,   627,   441,  1100,  1095,  1097,  1101,  1122,  1123,  1124,
    1149,   617,  1150,  1151,  1152,  1155,  1168,  1169,  1197,  1190,
    1189,  1202,   482,  1199,  1218,  1228,  1229,  1205,   621,   488,
     310,     0,     0,     0,     0,     0,     0,   601,     0,     0,
       0,     0,     0,     0,     0,   525,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   564
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-743)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     598,   599,   300,   301,     1,     8,     1,     1,   224,     1,
     308,   224,     1,   105,   224,     1,     1,     1,     1,     1,
       1,     3,     1,     5,   224,     1,   222,     1,     1,     1,
     226,   224,    24,   222,   223,    17,   222,     1,     1,    31,
     226,    17,   164,   165,   222,     1,     1,     1,   226,    51,
      32,   164,   165,    37,    36,    34,    32,     9,    10,    11,
      36,   224,   222,    36,   222,     1,   226,    51,    52,    53,
      54,    55,    36,   224,   222,    57,   222,    59,   226,   222,
     226,    62,   224,   226,    57,     1,    70,    69,    62,    62,
       1,     1,     1,    57,    73,   393,   394,    94,    62,     1,
     224,    96,    96,   401,    96,   403,    62,    62,    24,   201,
      96,    96,   410,    96,    96,   413,   135,   136,     1,   224,
      96,   118,   224,     6,     7,   423,   424,   224,   123,    12,
     224,     1,   225,    96,   123,   433,   434,    20,   436,   121,
       1,   117,    58,    26,   123,    28,    29,    30,   121,   123,
     224,   222,    35,   105,   130,   226,    17,   121,    41,    42,
      96,    44,    45,    46,    34,   147,    82,    50,   123,   155,
      86,    32,   155,    56,   224,    36,   224,    60,    61,     1,
      96,    64,    98,    99,    94,    96,   224,    96,   135,   136,
     192,    74,   155,   175,   197,   197,   224,   222,    81,   225,
      83,   226,    85,    73,    87,    88,    89,   222,   118,   225,
     222,   226,   123,   129,   226,   131,   132,   133,   134,   155,
     103,   123,   198,   224,   213,   523,   109,   110,   111,   112,
     213,   223,   115,   116,   216,   151,   119,   213,   223,   223,
       1,   223,   223,   215,   223,   225,   155,   223,   225,   221,
     223,   223,   222,   123,    15,    16,   117,   220,    19,   175,
     223,   215,   222,   124,   125,   224,   226,   221,   223,   152,
     186,   183,   184,   156,    96,    36,   159,   160,   161,   162,
     163,   222,     1,   166,   167,   226,     1,   223,   586,  1031,
    1032,  1033,    92,    93,   592,   593,   157,   225,   225,   597,
     216,   217,    21,    22,   213,   225,     1,   223,    27,    24,
     225,   213,   223,   223,   223,     1,    31,    78,    79,    80,
     225,   223,    17,    84,   225,   225,   209,   210,   211,    90,
      91,   214,   225,   155,    13,    96,   219,    32,    40,   105,
     223,    36,   221,   225,   225,   106,   107,   225,    67,    68,
     225,    37,   213,   225,    33,   222,    75,    76,    77,   120,
     225,    63,   223,    65,    43,    51,    52,    53,    54,    55,
      49,   225,   225,   139,   140,   141,   142,   143,   144,   145,
     225,    96,   101,   102,    70,   146,     1,    66,   225,   225,
     225,   225,   225,   225,   113,   114,   225,   225,   220,   225,
     225,    96,    17,   222,   225,     1,   108,   225,   225,   225,
       6,     7,   225,   225,   225,   225,    12,    32,    97,   225,
     225,    36,   117,   225,    20,   104,   225,   225,   225,   190,
      26,   225,    28,    29,    30,   130,   225,   225,   225,    35,
     225,   225,   225,   225,   225,    41,    42,   225,    44,    45,
      46,     1,   225,   225,    50,   225,   225,   225,   225,   138,
      56,   225,   223,   225,    60,    61,   225,   225,    64,   225,
     225,   225,   225,    65,    24,   177,   178,   225,    74,   158,
     225,   225,   225,   225,   225,    81,   225,    83,   225,    85,
     225,    87,    88,    89,   225,   225,   225,   225,   225,  1097,
     225,   225,   117,   198,   223,   225,   122,   103,    58,   124,
     125,   213,   225,   109,   110,   111,   112,   225,   213,   115,
     116,   225,     1,   119,     3,   122,     5,   206,   122,   222,
     105,   105,    82,   164,   105,   105,    86,   105,    17,   105,
     164,   164,   157,   105,   222,   137,    96,   222,    98,    99,
     222,   225,    65,    32,   225,   225,   152,    36,   225,   225,
     156,   225,   225,   159,   160,   161,   162,   163,   225,   225,
     166,   167,   225,     4,   225,   225,   225,   169,    57,   129,
      59,   131,   132,   133,   134,   225,   178,    18,   225,   225,
      69,   225,   225,   185,    25,   225,   225,   225,   213,   225,
     225,   151,   122,   225,   225,   225,   225,   225,   200,    40,
     202,   203,   225,   209,   210,   211,   222,    96,   214,   164,
     212,   225,   225,   219,   137,   175,   218,   105,   164,   164,
     105,   122,    63,   164,    65,     1,   186,     0,     1,   164,
     105,     4,   121,   105,   105,   164,   164,   164,   105,    15,
      16,    14,   105,    19,    17,    18,   169,   105,   105,   105,
      23,   105,   164,    94,   164,   178,   216,   217,   147,   225,
      36,    34,   185,    51,   164,    38,    39,   775,   776,   777,
     778,   779,   780,   781,   225,    48,   122,   200,   164,   202,
     203,   164,   164,   164,   164,   126,   175,   128,   164,   212,
      63,   164,   225,   225,   164,   218,   164,   222,    71,    72,
      51,   222,    78,    79,    80,   225,   225,   225,    84,   150,
     225,   225,   225,   164,    90,    91,   225,   222,   225,   225,
      96,   225,    95,   222,   122,   122,   224,   216,   222,   222,
     106,   107,   222,   225,   225,   108,    51,   178,   225,   164,
     164,   225,   122,   164,   120,   164,   225,   225,   189,   164,
     122,   225,   164,   194,   122,   105,   225,   105,   222,   200,
     225,   122,   122,   204,   137,   122,   207,   122,   122,   122,
     146,   212,   105,   122,   222,   148,   149,   218,   122,   122,
     153,   154,   170,   171,   172,   173,   174,   222,   176,   177,
     222,   179,   180,   181,   182,   225,   225,   185,   225,   187,
     188,   189,   122,   191,   222,   193,   222,   195,   196,   222,
     105,   199,   222,   222,   190,   222,   222,   205,   222,   170,
     171,   172,   173,   174,   105,   176,   177,   222,   179,   180,
     181,   182,   222,   222,   185,   208,   187,   188,   189,   222,
     191,   222,   193,   222,   195,   196,   105,   222,   199,   105,
     105,   222,   105,   122,   205,   170,   171,   172,   173,   174,
     225,   176,   177,   105,   179,   180,   181,   182,     1,   105,
     185,   105,   187,   188,   189,   222,   191,   122,   193,   122,
     195,   196,   164,   225,   199,   122,   105,   122,    21,    22,
     205,   122,   122,   122,    27,   122,   122,   222,   122,   122,
     222,   222,   122,   222,   122,   222,   222,   122,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   122,   222,   222,
     222,   222,   222,   222,    67,    68,   222,   222,   222,   222,
     105,   122,    75,    76,    77,   222,   222,   222,   222,   222,
     222,   222,   222,   164,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   122,   122,   222,   122,   225,   101,   102,
     122,   222,   122,   225,   122,   105,   222,   122,   222,   164,
     113,   114,   222,   222,   225,   122,   122,   122,   122,   227,
     222,   122,   225,   122,   122,   122,   122,   222,   122,   227,
     222,   222,   105,   991,   122,   222,   222,  1238,   222,   222,
     222,   265,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,    71,   127,   222,
     993,   225,   222,   225,   222,   222,   222,   226,   222,   222,
     222,   127,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   168,   222,   222,
     222,   222,   222,   127,   498,   222,   953,   222,   222,   222,
    1209,   222,  1207,   222,  1183,   222,   222,  1194,   222,   222,
     222,   222,   222,   222,   222,   451,  1092,   474,   550,   512,
     222,  1192,  1211,  1213,  1188,   464,   108,   222,   558,   222,
     222,   388,   161,   222,   225,   225,   222,   222,   222,   222,
     222,   360,   222,   222,   222,   222,   222,   222,   222,  1062,
    1060,   222,   216,   225,   222,   222,   222,   227,   378,   224,
      89,    -1,    -1,    -1,    -1,    -1,    -1,   328,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   238,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   288
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   229,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    63,    71,    72,    95,   108,   137,   148,
     149,   153,   154,   208,   230,   235,   240,   264,   270,   284,
     302,   325,   339,   354,   361,   365,   375,   384,   404,   410,
     416,   420,   426,   483,   498,   222,   223,   224,   224,   303,
     385,   411,   224,   421,   224,   340,   405,   326,   224,   224,
     285,   355,   224,   224,   366,   376,   224,     1,    24,    31,
      96,   265,   266,   267,   268,   269,     1,    21,    22,    27,
      67,    68,    75,    76,    77,   101,   102,   113,   114,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   224,   224,   224,     1,    62,   417,   418,
     419,   224,     1,     6,     7,    12,    20,    26,    28,    29,
      30,    35,    41,    42,    44,    45,    46,    50,    56,    60,
      61,    64,    74,    81,    83,    85,    87,    88,    89,   103,
     109,   110,   111,   112,   115,   116,   119,   152,   156,   159,
     160,   161,   162,   163,   166,   167,   209,   210,   211,   214,
     219,   427,   428,   429,   430,   431,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   476,   480,   481,
     482,   224,   224,   224,     1,   215,   271,   272,   273,   274,
     275,     1,    94,   118,   236,   237,   238,   239,   224,   224,
       1,    37,    51,    52,    53,    54,    55,    70,   499,   500,
     501,   502,   503,   504,   505,   506,   507,     1,    24,    58,
      82,    86,    96,    98,    99,   129,   131,   132,   133,   134,
     151,   175,   186,   216,   217,   241,   242,   243,   244,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   224,   224,     1,    96,   362,   363,
     364,   222,   225,   225,   225,   223,   266,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   223,
     485,     1,    15,    16,    19,    36,    78,    79,    80,    84,
      90,    91,    96,   106,   107,   120,   146,   190,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,     1,     3,     5,    17,
      32,    36,    57,    59,    69,    96,   121,   147,   175,   216,
     386,   387,   388,   389,   390,   391,   392,   393,   394,   395,
     399,   400,   401,   402,   403,     1,    62,   123,   412,   413,
     414,   415,   225,   223,   418,     1,    96,   123,   422,   423,
     424,   425,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     477,   225,   473,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     223,   428,     1,    17,    32,    36,   117,   124,   125,   157,
     213,   341,   342,   343,   344,   345,   346,   347,   351,   352,
     353,     1,   123,   213,   406,   407,   408,   409,     1,    36,
      57,    62,   121,   327,   331,   332,   333,   337,   338,   222,
     225,   223,   272,   221,   222,   225,   225,   223,   237,     1,
      17,    32,    36,    96,   117,   130,   198,   213,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   298,     1,    34,
      73,   123,   356,   357,   358,   359,   360,   225,   225,   225,
     225,   225,   225,   225,   223,   500,   222,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   223,   242,     1,    96,   155,   213,
     367,   368,   369,   370,   371,     1,    96,   155,   377,   378,
     379,   380,   225,   223,   363,   122,   122,   122,   222,   105,
     105,   164,   105,   232,   232,   105,   105,   105,   164,   164,
     105,   232,   222,   222,   225,   225,   225,   322,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     223,   305,   222,   225,   225,   225,   225,   396,   225,   225,
     225,   225,   225,   225,   225,   225,   223,   387,   225,   225,
     223,   413,   122,   222,   225,   225,   223,   423,   164,   232,
     232,   105,   164,   164,   105,   122,   164,   232,   164,   232,
     105,   105,   105,   164,   164,   164,   232,   105,   105,   232,
     105,   105,   105,   105,   164,   164,   225,   164,   225,   232,
     232,   164,   164,   164,   164,   164,   165,   164,   165,   164,
     164,   232,   232,   122,   232,   164,   164,   164,   222,   222,
     225,   225,   348,   225,   225,   225,   225,   225,   223,   342,
     225,   225,   223,   407,   222,   328,   225,   225,   225,   223,
     332,   164,   222,   224,   122,   122,   222,   222,   225,   225,
     299,   225,   225,   225,   295,   225,   223,   287,   222,   225,
     225,   225,   223,   357,   164,   164,   122,   164,   164,   164,
     232,   222,   122,   164,   105,   105,   122,   122,   122,   122,
     122,   122,   135,   136,   245,   246,   135,   136,   247,   248,
     122,   122,   105,   122,   122,   222,   222,   225,   372,   225,
     223,   368,   222,   225,   381,   223,   378,   122,   222,   222,
     222,   222,   222,   222,   222,   139,   140,   141,   142,   143,
     144,   145,   231,   232,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   105,   105,   232,   225,   105,   105,   105,
     105,   232,   232,   122,   105,   105,   232,   105,   234,   234,
     222,   122,   183,   184,   122,   164,   225,   122,   122,   122,
     122,   105,   122,   122,   122,   222,   122,   122,   222,   222,
     122,   122,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,    51,   170,   171,   172,   173,   174,   176,   177,   179,
     180,   181,   182,   185,   187,   188,   189,   191,   193,   195,
     196,   199,   205,   478,   479,   222,    51,   170,   171,   172,
     173,   174,   176,   177,   179,   180,   181,   182,   185,   187,
     188,   189,   191,   193,   195,   196,   199,   205,   474,   475,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   122,
     164,   225,   122,   105,   122,   122,   122,   222,   122,   122,
     222,   225,   122,   122,   105,   335,   336,   222,   222,     1,
      96,   155,   220,   276,   277,   278,   279,   280,   222,   222,
     122,   164,   225,   122,   122,   122,   225,   122,   222,   122,
     122,   122,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   226,   222,   226,   222,   222,   222,   222,   222,   122,
     225,   122,   222,   122,   225,   222,   222,   231,   231,   231,
     231,   231,   231,   231,   222,   222,   222,    92,    93,   323,
     324,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,     9,    10,    11,   233,   234,   222,   222,   222,   222,
     222,   222,   222,     8,   197,   397,   398,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     226,   222,   226,   222,   222,    13,    33,    43,    49,    66,
      97,   104,   138,   158,   206,   349,   350,   222,   222,   222,
     222,   222,   222,   222,    51,   192,   197,   329,   330,   222,
     222,   168,   226,   334,   222,   225,   281,   225,   223,   277,
     222,   222,     4,    18,    25,    40,    63,    65,    94,   126,
     128,   150,   178,   189,   194,   200,   204,   207,   212,   218,
     300,   301,   222,   222,   222,    51,   170,   171,   172,   173,
     174,   176,   177,   179,   180,   181,   182,   185,   187,   188,
     189,   191,   193,   195,   196,   199,   205,   296,   297,   222,
     222,   222,   222,   246,   248,   222,    65,   137,   169,   178,
     185,   200,   202,   203,   212,   218,   373,   374,   222,   222,
      65,   137,   169,   178,   185,   200,   202,   203,   212,   218,
     382,   383,   222,   226,   233,   233,   233,   222,   226,   479,
     475,   222,   226,   222,   226,   105,   336,   222,   122,   225,
     201,   234,   222,   227,   227,   227,   222,   226,   222,   226,
     222,   226,   222,   226,   324,   398,   350,   330,   222,    40,
      63,    65,   108,   177,   178,   213,   282,   283,   222,   222,
     127,   127,   127,   301,   297,   374,   383,   222,   226,   283
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
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1283 "conf_parser.y"
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

  case 206:
/* Line 1787 of yacc.c  */
#line 1295 "conf_parser.y"
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

  case 226:
/* Line 1787 of yacc.c  */
#line 1361 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1367 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1373 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1379 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1385 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1391 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1397 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1403 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1409 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1415 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1422 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1428 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 1434 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 1440 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1465 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1479 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1485 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1491 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1495 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1499 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 263:
/* Line 1787 of yacc.c  */
#line 1507 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1512 "conf_parser.y"
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

  case 268:
/* Line 1787 of yacc.c  */
#line 1526 "conf_parser.y"
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

  case 269:
/* Line 1787 of yacc.c  */
#line 1546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1552 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 1561 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1565 "conf_parser.y"
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

  case 284:
/* Line 1787 of yacc.c  */
#line 1608 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1614 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1626 "conf_parser.y"
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

  case 288:
/* Line 1787 of yacc.c  */
#line 1637 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1644 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1648 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1660 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1664 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1668 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1672 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1680 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1686 "conf_parser.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 1709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 1722 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 1729 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1740 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1752 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1767 "conf_parser.y"
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

  case 322:
/* Line 1787 of yacc.c  */
#line 1782 "conf_parser.y"
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

  case 323:
/* Line 1787 of yacc.c  */
#line 1793 "conf_parser.y"
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

  case 330:
/* Line 1787 of yacc.c  */
#line 1810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 331:
/* Line 1787 of yacc.c  */
#line 1816 "conf_parser.y"
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

  case 332:
/* Line 1787 of yacc.c  */
#line 1835 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1870 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1874 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 1878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1887 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 1896 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 1948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 1956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 1960 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 1969 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 1977 "conf_parser.y"
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

  case 386:
/* Line 1787 of yacc.c  */
#line 2043 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 387:
/* Line 1787 of yacc.c  */
#line 2049 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 388:
/* Line 1787 of yacc.c  */
#line 2055 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2061 "conf_parser.y"
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

  case 390:
/* Line 1787 of yacc.c  */
#line 2074 "conf_parser.y"
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

  case 391:
/* Line 1787 of yacc.c  */
#line 2087 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 392:
/* Line 1787 of yacc.c  */
#line 2093 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 393:
/* Line 1787 of yacc.c  */
#line 2097 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 2105 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2121 "conf_parser.y"
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

  case 401:
/* Line 1787 of yacc.c  */
#line 2132 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2138 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2150 "conf_parser.y"
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

  case 405:
/* Line 1787 of yacc.c  */
#line 2165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 2169 "conf_parser.y"
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

  case 412:
/* Line 1787 of yacc.c  */
#line 2194 "conf_parser.y"
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

  case 413:
/* Line 1787 of yacc.c  */
#line 2214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2227 "conf_parser.y"
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

  case 421:
/* Line 1787 of yacc.c  */
#line 2253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 422:
/* Line 1787 of yacc.c  */
#line 2259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2273 "conf_parser.y"
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

  case 429:
/* Line 1787 of yacc.c  */
#line 2290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2294 "conf_parser.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 2316 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 2322 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2366 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2371 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2377 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2383 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2389 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2394 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2399 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2409 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2414 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2419 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2424 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2429 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2434 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2439 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2444 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2449 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2454 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2465 "conf_parser.y"
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

  case 510:
/* Line 1787 of yacc.c  */
#line 2476 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2481 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2486 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2491 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2496 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2501 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2504 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2509 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2512 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2517 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2522 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2527 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2532 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2537 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2542 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2547 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2581 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2611 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2617 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2623 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2626 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2641 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2647 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2753 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2758 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2763 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 2821 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 2826 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 2836 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 2860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 2887 "conf_parser.y"
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

  case 634:
/* Line 1787 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6722 "conf_parser.c"
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


