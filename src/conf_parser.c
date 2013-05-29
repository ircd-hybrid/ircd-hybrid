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
     FLATTEN_LINKS = 291,
     GECOS = 292,
     GENERAL = 293,
     GLINE = 294,
     GLINE_DURATION = 295,
     GLINE_ENABLE = 296,
     GLINE_EXEMPT = 297,
     GLINE_MIN_CIDR = 298,
     GLINE_MIN_CIDR6 = 299,
     GLINE_REQUEST_DURATION = 300,
     GLOBAL_KILL = 301,
     HAVENT_READ_CONF = 302,
     HIDDEN = 303,
     HIDDEN_NAME = 304,
     HIDE_IDLE_FROM_OPERS = 305,
     HIDE_SERVER_IPS = 306,
     HIDE_SERVERS = 307,
     HIDE_SERVICES = 308,
     HIDE_SPOOF_IPS = 309,
     HOST = 310,
     HUB = 311,
     HUB_MASK = 312,
     IGNORE_BOGUS_TS = 313,
     INVISIBLE_ON_CONNECT = 314,
     IP = 315,
     IRCD_AUTH = 316,
     IRCD_FLAGS = 317,
     IRCD_SID = 318,
     JOIN_FLOOD_COUNT = 319,
     JOIN_FLOOD_TIME = 320,
     KILL = 321,
     KILL_CHASE_TIME_LIMIT = 322,
     KLINE = 323,
     KLINE_EXEMPT = 324,
     KNOCK_DELAY = 325,
     KNOCK_DELAY_CHANNEL = 326,
     LEAF_MASK = 327,
     LINKS_DELAY = 328,
     LISTEN = 329,
     MASK = 330,
     MAX_ACCEPT = 331,
     MAX_BANS = 332,
     MAX_CHANS_PER_OPER = 333,
     MAX_CHANS_PER_USER = 334,
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
     NAME = 351,
     NEED_IDENT = 352,
     NEED_PASSWORD = 353,
     NETWORK_DESC = 354,
     NETWORK_NAME = 355,
     NICK = 356,
     NO_CREATE_ON_SPLIT = 357,
     NO_JOIN_ON_SPLIT = 358,
     NO_OPER_FLOOD = 359,
     NO_TILDE = 360,
     NUMBER = 361,
     NUMBER_PER_CIDR = 362,
     NUMBER_PER_IP = 363,
     OPER_ONLY_UMODES = 364,
     OPER_PASS_RESV = 365,
     OPER_UMODES = 366,
     OPERATOR = 367,
     OPERS_BYPASS_CALLERID = 368,
     PACE_WAIT = 369,
     PACE_WAIT_SIMPLE = 370,
     PASSWORD = 371,
     PATH = 372,
     PING_COOKIE = 373,
     PING_TIME = 374,
     PORT = 375,
     QSTRING = 376,
     RANDOM_IDLE = 377,
     REASON = 378,
     REDIRPORT = 379,
     REDIRSERV = 380,
     REHASH = 381,
     REMOTE = 382,
     REMOTEBAN = 383,
     RESV = 384,
     RESV_EXEMPT = 385,
     RSA_PRIVATE_KEY_FILE = 386,
     RSA_PUBLIC_KEY_FILE = 387,
     SECONDS = 388,
     MINUTES = 389,
     HOURS = 390,
     DAYS = 391,
     WEEKS = 392,
     MONTHS = 393,
     YEARS = 394,
     SEND_PASSWORD = 395,
     SENDQ = 396,
     SERVERHIDE = 397,
     SERVERINFO = 398,
     SHORT_MOTD = 399,
     SPOOF = 400,
     SPOOF_NOTICE = 401,
     SQUIT = 402,
     SSL_CERTIFICATE_FILE = 403,
     SSL_DH_PARAM_FILE = 404,
     STATS_E_DISABLED = 405,
     STATS_I_OPER_ONLY = 406,
     STATS_K_OPER_ONLY = 407,
     STATS_O_OPER_ONLY = 408,
     STATS_P_OPER_ONLY = 409,
     T_ALL = 410,
     T_BOTS = 411,
     T_CALLERID = 412,
     T_CCONN = 413,
     T_CCONN_FULL = 414,
     T_CLUSTER = 415,
     T_DEAF = 416,
     T_DEBUG = 417,
     T_DLINE = 418,
     T_EXTERNAL = 419,
     T_FARCONNECT = 420,
     T_FILE = 421,
     T_FULL = 422,
     T_GLOBOPS = 423,
     T_INVISIBLE = 424,
     T_IPV4 = 425,
     T_IPV6 = 426,
     T_LOCOPS = 427,
     T_LOG = 428,
     T_MAX_CLIENTS = 429,
     T_NCHANGE = 430,
     T_NONONREG = 431,
     T_OPERWALL = 432,
     T_RECVQ = 433,
     T_REJ = 434,
     T_RESTART = 435,
     T_SERVER = 436,
     T_SERVICE = 437,
     T_SERVICES_NAME = 438,
     T_SERVNOTICE = 439,
     T_SET = 440,
     T_SHARED = 441,
     T_SIZE = 442,
     T_SKILL = 443,
     T_SOFTCALLERID = 444,
     T_SPY = 445,
     T_SSL = 446,
     T_SSL_CIPHER_LIST = 447,
     T_SSL_CLIENT_METHOD = 448,
     T_SSL_SERVER_METHOD = 449,
     T_SSLV3 = 450,
     T_TLSV1 = 451,
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
     THROTTLE_TIME = 462,
     TKLINE_EXPIRE_NOTICES = 463,
     TMASKED = 464,
     TRUE_NO_OPER_FLOOD = 465,
     TS_MAX_DELTA = 466,
     TS_WARN_DELTA = 467,
     TWODOTS = 468,
     TYPE = 469,
     UNKLINE = 470,
     USE_EGD = 471,
     USE_LOGGING = 472,
     USER = 473,
     VHOST = 474,
     VHOST6 = 475,
     WARN_NO_NLINE = 476,
     XLINE = 477
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
#define FLATTEN_LINKS 291
#define GECOS 292
#define GENERAL 293
#define GLINE 294
#define GLINE_DURATION 295
#define GLINE_ENABLE 296
#define GLINE_EXEMPT 297
#define GLINE_MIN_CIDR 298
#define GLINE_MIN_CIDR6 299
#define GLINE_REQUEST_DURATION 300
#define GLOBAL_KILL 301
#define HAVENT_READ_CONF 302
#define HIDDEN 303
#define HIDDEN_NAME 304
#define HIDE_IDLE_FROM_OPERS 305
#define HIDE_SERVER_IPS 306
#define HIDE_SERVERS 307
#define HIDE_SERVICES 308
#define HIDE_SPOOF_IPS 309
#define HOST 310
#define HUB 311
#define HUB_MASK 312
#define IGNORE_BOGUS_TS 313
#define INVISIBLE_ON_CONNECT 314
#define IP 315
#define IRCD_AUTH 316
#define IRCD_FLAGS 317
#define IRCD_SID 318
#define JOIN_FLOOD_COUNT 319
#define JOIN_FLOOD_TIME 320
#define KILL 321
#define KILL_CHASE_TIME_LIMIT 322
#define KLINE 323
#define KLINE_EXEMPT 324
#define KNOCK_DELAY 325
#define KNOCK_DELAY_CHANNEL 326
#define LEAF_MASK 327
#define LINKS_DELAY 328
#define LISTEN 329
#define MASK 330
#define MAX_ACCEPT 331
#define MAX_BANS 332
#define MAX_CHANS_PER_OPER 333
#define MAX_CHANS_PER_USER 334
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
#define NAME 351
#define NEED_IDENT 352
#define NEED_PASSWORD 353
#define NETWORK_DESC 354
#define NETWORK_NAME 355
#define NICK 356
#define NO_CREATE_ON_SPLIT 357
#define NO_JOIN_ON_SPLIT 358
#define NO_OPER_FLOOD 359
#define NO_TILDE 360
#define NUMBER 361
#define NUMBER_PER_CIDR 362
#define NUMBER_PER_IP 363
#define OPER_ONLY_UMODES 364
#define OPER_PASS_RESV 365
#define OPER_UMODES 366
#define OPERATOR 367
#define OPERS_BYPASS_CALLERID 368
#define PACE_WAIT 369
#define PACE_WAIT_SIMPLE 370
#define PASSWORD 371
#define PATH 372
#define PING_COOKIE 373
#define PING_TIME 374
#define PORT 375
#define QSTRING 376
#define RANDOM_IDLE 377
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RESV 384
#define RESV_EXEMPT 385
#define RSA_PRIVATE_KEY_FILE 386
#define RSA_PUBLIC_KEY_FILE 387
#define SECONDS 388
#define MINUTES 389
#define HOURS 390
#define DAYS 391
#define WEEKS 392
#define MONTHS 393
#define YEARS 394
#define SEND_PASSWORD 395
#define SENDQ 396
#define SERVERHIDE 397
#define SERVERINFO 398
#define SHORT_MOTD 399
#define SPOOF 400
#define SPOOF_NOTICE 401
#define SQUIT 402
#define SSL_CERTIFICATE_FILE 403
#define SSL_DH_PARAM_FILE 404
#define STATS_E_DISABLED 405
#define STATS_I_OPER_ONLY 406
#define STATS_K_OPER_ONLY 407
#define STATS_O_OPER_ONLY 408
#define STATS_P_OPER_ONLY 409
#define T_ALL 410
#define T_BOTS 411
#define T_CALLERID 412
#define T_CCONN 413
#define T_CCONN_FULL 414
#define T_CLUSTER 415
#define T_DEAF 416
#define T_DEBUG 417
#define T_DLINE 418
#define T_EXTERNAL 419
#define T_FARCONNECT 420
#define T_FILE 421
#define T_FULL 422
#define T_GLOBOPS 423
#define T_INVISIBLE 424
#define T_IPV4 425
#define T_IPV6 426
#define T_LOCOPS 427
#define T_LOG 428
#define T_MAX_CLIENTS 429
#define T_NCHANGE 430
#define T_NONONREG 431
#define T_OPERWALL 432
#define T_RECVQ 433
#define T_REJ 434
#define T_RESTART 435
#define T_SERVER 436
#define T_SERVICE 437
#define T_SERVICES_NAME 438
#define T_SERVNOTICE 439
#define T_SET 440
#define T_SHARED 441
#define T_SIZE 442
#define T_SKILL 443
#define T_SOFTCALLERID 444
#define T_SPY 445
#define T_SSL 446
#define T_SSL_CIPHER_LIST 447
#define T_SSL_CLIENT_METHOD 448
#define T_SSL_SERVER_METHOD 449
#define T_SSLV3 450
#define T_TLSV1 451
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
#define THROTTLE_TIME 462
#define TKLINE_EXPIRE_NOTICES 463
#define TMASKED 464
#define TRUE_NO_OPER_FLOOD 465
#define TS_MAX_DELTA 466
#define TS_WARN_DELTA 467
#define TWODOTS 468
#define TYPE 469
#define UNKLINE 470
#define USE_EGD 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_NLINE 476
#define XLINE 477



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 674 "conf_parser.c"
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
#line 702 "conf_parser.c"

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
#define YYLAST   1204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  280
/* YYNRULES -- Number of rules.  */
#define YYNRULES  637
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1242

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   477

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   227,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   228,   223,
       2,   226,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,     2,   224,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222
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
     578,   580,   582,   584,   586,   588,   590,   592,   593,   600,
     603,   605,   607,   609,   611,   613,   615,   617,   619,   621,
     623,   625,   627,   629,   631,   633,   635,   637,   640,   645,
     650,   655,   660,   665,   670,   675,   680,   685,   690,   695,
     700,   705,   710,   715,   716,   722,   726,   728,   730,   732,
     733,   740,   741,   747,   751,   753,   755,   757,   759,   762,
     764,   766,   768,   770,   772,   775,   776,   782,   786,   788,
     790,   794,   799,   804,   805,   812,   815,   817,   819,   821,
     823,   825,   827,   829,   831,   833,   836,   841,   846,   851,
     856,   857,   863,   867,   869,   871,   873,   875,   877,   879,
     881,   883,   885,   887,   889,   894,   899,   904,   905,   912,
     915,   917,   919,   921,   923,   926,   931,   936,   941,   947,
     950,   952,   954,   956,   961,   962,   969,   972,   974,   976,
     978,   980,   983,   988,   993,   994,  1000,  1004,  1006,  1008,
    1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,  1026,  1027,
    1034,  1037,  1039,  1041,  1043,  1046,  1051,  1052,  1058,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1082,
    1084,  1085,  1092,  1095,  1097,  1099,  1101,  1103,  1105,  1107,
    1109,  1111,  1113,  1115,  1117,  1119,  1121,  1123,  1126,  1131,
    1136,  1141,  1146,  1151,  1156,  1161,  1166,  1167,  1173,  1177,
    1179,  1181,  1183,  1188,  1193,  1198,  1203,  1208,  1209,  1216,
    1219,  1221,  1223,  1225,  1227,  1232,  1237,  1238,  1245,  1248,
    1250,  1252,  1254,  1256,  1261,  1266,  1272,  1275,  1277,  1279,
    1281,  1286,  1287,  1294,  1297,  1299,  1301,  1303,  1305,  1310,
    1315,  1321,  1324,  1326,  1328,  1330,  1332,  1334,  1336,  1338,
    1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,
    1360,  1362,  1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,
    1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,
    1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,
    1420,  1422,  1424,  1429,  1434,  1439,  1444,  1449,  1454,  1459,
    1464,  1469,  1474,  1479,  1484,  1489,  1494,  1499,  1504,  1509,
    1514,  1519,  1524,  1529,  1534,  1539,  1544,  1549,  1554,  1559,
    1564,  1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,  1609,
    1614,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1650,  1656,
    1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,  1678,
    1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,  1698,
    1700,  1702,  1704,  1706,  1707,  1713,  1717,  1719,  1721,  1723,
    1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,  1743,
    1745,  1747,  1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,
    1768,  1773,  1778,  1784,  1787,  1789,  1791,  1793,  1795,  1797,
    1799,  1801,  1803,  1805,  1807,  1809,  1811,  1813,  1815,  1820,
    1825,  1830,  1835,  1840,  1845,  1850,  1855,  1860,  1865,  1870,
    1875,  1881,  1884,  1886,  1888,  1890,  1892,  1894,  1896,  1898,
    1900,  1902,  1907,  1912,  1917,  1922,  1927,  1932
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     230,     0,    -1,    -1,   230,   231,    -1,   265,    -1,   271,
      -1,   285,    -1,   484,    -1,   303,    -1,   326,    -1,   340,
      -1,   241,    -1,   499,    -1,   355,    -1,   362,    -1,   366,
      -1,   376,    -1,   385,    -1,   405,    -1,   411,    -1,   417,
      -1,   427,    -1,   421,    -1,   236,    -1,     1,   223,    -1,
       1,   224,    -1,    -1,   233,    -1,   106,   232,    -1,   106,
     133,   232,    -1,   106,   134,   232,    -1,   106,   135,   232,
      -1,   106,   136,   232,    -1,   106,   137,   232,    -1,   106,
     138,   232,    -1,   106,   139,   232,    -1,    -1,   235,    -1,
     106,   234,    -1,   106,     9,   234,    -1,   106,    10,   234,
      -1,   106,    11,   234,    -1,    95,   225,   237,   224,   223,
      -1,   237,   238,    -1,   238,    -1,   239,    -1,   240,    -1,
       1,   223,    -1,    94,   226,   121,   223,    -1,   117,   226,
     121,   223,    -1,   143,   225,   242,   224,   223,    -1,   242,
     243,    -1,   243,    -1,   254,    -1,   259,    -1,   264,    -1,
     256,    -1,   257,    -1,   258,    -1,   261,    -1,   262,    -1,
     263,    -1,   252,    -1,   251,    -1,   260,    -1,   255,    -1,
     250,    -1,   244,    -1,   245,    -1,   253,    -1,     1,   223,
      -1,   193,   226,   246,   223,    -1,   194,   226,   248,   223,
      -1,   246,   227,   247,    -1,   247,    -1,   195,    -1,   196,
      -1,   248,   227,   249,    -1,   249,    -1,   195,    -1,   196,
      -1,   148,   226,   121,   223,    -1,   131,   226,   121,   223,
      -1,   149,   226,   121,   223,    -1,   192,   226,   121,   223,
      -1,    96,   226,   121,   223,    -1,    63,   226,   121,   223,
      -1,    24,   226,   121,   223,    -1,   100,   226,   121,   223,
      -1,    99,   226,   121,   223,    -1,   219,   226,   121,   223,
      -1,   220,   226,   121,   223,    -1,   174,   226,   106,   223,
      -1,    85,   226,   106,   223,    -1,    89,   226,   106,   223,
      -1,    56,   226,   206,   223,    -1,     4,   225,   266,   224,
     223,    -1,   266,   267,    -1,   267,    -1,   268,    -1,   270,
      -1,   269,    -1,     1,   223,    -1,    96,   226,   121,   223,
      -1,    31,   226,   121,   223,    -1,    24,   226,   121,   223,
      -1,   173,   225,   272,   224,   223,    -1,   272,   273,    -1,
     273,    -1,   274,    -1,   275,    -1,     1,   223,    -1,   217,
     226,   206,   223,    -1,    -1,   276,   166,   225,   277,   224,
     223,    -1,   277,   278,    -1,   278,    -1,   279,    -1,   281,
      -1,   280,    -1,     1,   223,    -1,    96,   226,   121,   223,
      -1,   187,   226,   235,   223,    -1,   187,   226,   200,   223,
      -1,    -1,   214,   282,   226,   283,   223,    -1,   283,   227,
     284,    -1,   284,    -1,   218,    -1,   112,    -1,    39,    -1,
     163,    -1,    68,    -1,    66,    -1,   162,    -1,    -1,   112,
     286,   225,   287,   224,   223,    -1,   287,   288,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   295,    -1,   294,
      -1,   292,    -1,   293,    -1,   299,    -1,     1,   223,    -1,
      96,   226,   121,   223,    -1,   218,   226,   121,   223,    -1,
     116,   226,   121,   223,    -1,    32,   226,   206,   223,    -1,
     132,   226,   121,   223,    -1,    17,   226,   121,   223,    -1,
      -1,   197,   296,   226,   297,   223,    -1,   297,   227,   298,
      -1,   298,    -1,   156,    -1,   158,    -1,   159,    -1,   161,
      -1,   162,    -1,   167,    -1,    48,    -1,   188,    -1,   175,
      -1,   179,    -1,   198,    -1,   190,    -1,   164,    -1,   177,
      -1,   184,    -1,   169,    -1,   203,    -1,   189,    -1,   157,
      -1,   172,    -1,   176,    -1,   165,    -1,    -1,    62,   300,
     226,   301,   223,    -1,   301,   227,   302,    -1,   302,    -1,
      66,   228,   127,    -1,    66,    -1,    18,   228,   127,    -1,
      18,    -1,   147,   228,   127,    -1,   147,    -1,    68,    -1,
     215,    -1,   163,    -1,   199,    -1,   222,    -1,    39,    -1,
      25,    -1,   180,    -1,   126,    -1,     4,    -1,   177,    -1,
     168,    -1,   204,    -1,   172,    -1,   128,    -1,   185,    -1,
      94,    -1,    -1,    17,   304,   225,   305,   224,   223,    -1,
     305,   306,    -1,   306,    -1,   307,    -1,   317,    -1,   318,
      -1,   308,    -1,   319,    -1,   309,    -1,   310,    -1,   311,
      -1,   312,    -1,   313,    -1,   314,    -1,   315,    -1,   316,
      -1,   320,    -1,   321,    -1,   322,    -1,     1,   223,    -1,
      96,   226,   121,   223,    -1,   119,   226,   233,   223,    -1,
     108,   226,   106,   223,    -1,    19,   226,   233,   223,    -1,
      87,   226,   106,   223,    -1,    80,   226,   106,   223,    -1,
      83,   226,   106,   223,    -1,    81,   226,   106,   223,    -1,
     141,   226,   235,   223,    -1,   178,   226,   235,   223,    -1,
      15,   226,   106,   223,    -1,    16,   226,   106,   223,    -1,
     107,   226,   106,   223,    -1,    91,   226,   233,   223,    -1,
      82,   226,   233,   223,    -1,    -1,    62,   323,   226,   324,
     223,    -1,   324,   227,   325,    -1,   325,    -1,   122,    -1,
      50,    -1,    -1,    74,   327,   225,   332,   224,   223,    -1,
      -1,    62,   329,   226,   330,   223,    -1,   330,   227,   331,
      -1,   331,    -1,   191,    -1,    48,    -1,   181,    -1,   332,
     333,    -1,   333,    -1,   334,    -1,   328,    -1,   338,    -1,
     339,    -1,     1,   223,    -1,    -1,   120,   226,   336,   335,
     223,    -1,   336,   227,   337,    -1,   337,    -1,   106,    -1,
     106,   213,   106,    -1,    60,   226,   121,   223,    -1,    55,
     226,   121,   223,    -1,    -1,    61,   341,   225,   342,   224,
     223,    -1,   342,   343,    -1,   343,    -1,   344,    -1,   345,
      -1,   346,    -1,   348,    -1,   352,    -1,   353,    -1,   354,
      -1,   347,    -1,     1,   223,    -1,   218,   226,   121,   223,
      -1,   116,   226,   121,   223,    -1,    17,   226,   121,   223,
      -1,    32,   226,   206,   223,    -1,    -1,    62,   349,   226,
     350,   223,    -1,   350,   227,   351,    -1,   351,    -1,   146,
      -1,    33,    -1,    69,    -1,    97,    -1,    13,    -1,   105,
      -1,    42,    -1,   130,    -1,   205,    -1,    98,    -1,   145,
     226,   121,   223,    -1,   125,   226,   121,   223,    -1,   124,
     226,   106,   223,    -1,    -1,   129,   356,   225,   357,   224,
     223,    -1,   357,   358,    -1,   358,    -1,   359,    -1,   360,
      -1,   361,    -1,     1,   223,    -1,    75,   226,   121,   223,
      -1,   123,   226,   121,   223,    -1,    34,   226,   121,   223,
      -1,   182,   225,   363,   224,   223,    -1,   363,   364,    -1,
     364,    -1,   365,    -1,     1,    -1,    96,   226,   121,   223,
      -1,    -1,   186,   367,   225,   368,   224,   223,    -1,   368,
     369,    -1,   369,    -1,   370,    -1,   371,    -1,   372,    -1,
       1,   223,    -1,    96,   226,   121,   223,    -1,   218,   226,
     121,   223,    -1,    -1,   214,   373,   226,   374,   223,    -1,
     374,   227,   375,    -1,   375,    -1,    68,    -1,   215,    -1,
     163,    -1,   199,    -1,   222,    -1,   202,    -1,   129,    -1,
     201,    -1,   172,    -1,   155,    -1,    -1,   160,   377,   225,
     378,   224,   223,    -1,   378,   379,    -1,   379,    -1,   380,
      -1,   381,    -1,     1,   223,    -1,    96,   226,   121,   223,
      -1,    -1,   214,   382,   226,   383,   223,    -1,   383,   227,
     384,    -1,   384,    -1,    68,    -1,   215,    -1,   163,    -1,
     199,    -1,   222,    -1,   202,    -1,   129,    -1,   201,    -1,
     172,    -1,   155,    -1,    -1,    18,   386,   225,   387,   224,
     223,    -1,   387,   388,    -1,   388,    -1,   389,    -1,   390,
      -1,   391,    -1,   392,    -1,   393,    -1,   395,    -1,   394,
      -1,   404,    -1,   396,    -1,   401,    -1,   402,    -1,   403,
      -1,   400,    -1,     1,   223,    -1,    96,   226,   121,   223,
      -1,    55,   226,   121,   223,    -1,   219,   226,   121,   223,
      -1,   140,   226,   121,   223,    -1,     3,   226,   121,   223,
      -1,   120,   226,   106,   223,    -1,     5,   226,   170,   223,
      -1,     5,   226,   171,   223,    -1,    -1,    62,   397,   226,
     398,   223,    -1,   398,   227,   399,    -1,   399,    -1,     8,
      -1,   191,    -1,    32,   226,   206,   223,    -1,    57,   226,
     121,   223,    -1,    72,   226,   121,   223,    -1,    17,   226,
     121,   223,    -1,   192,   226,   121,   223,    -1,    -1,    66,
     406,   225,   407,   224,   223,    -1,   407,   408,    -1,   408,
      -1,   409,    -1,   410,    -1,     1,    -1,   218,   226,   121,
     223,    -1,   123,   226,   121,   223,    -1,    -1,    23,   412,
     225,   413,   224,   223,    -1,   413,   414,    -1,   414,    -1,
     415,    -1,   416,    -1,     1,    -1,    60,   226,   121,   223,
      -1,   123,   226,   121,   223,    -1,    34,   225,   418,   224,
     223,    -1,   418,   419,    -1,   419,    -1,   420,    -1,     1,
      -1,    60,   226,   121,   223,    -1,    -1,    37,   422,   225,
     423,   224,   223,    -1,   423,   424,    -1,   424,    -1,   425,
      -1,   426,    -1,     1,    -1,    96,   226,   121,   223,    -1,
     123,   226,   121,   223,    -1,    38,   225,   428,   224,   223,
      -1,   428,   429,    -1,   429,    -1,   438,    -1,   439,    -1,
     441,    -1,   442,    -1,   443,    -1,   444,    -1,   445,    -1,
     446,    -1,   447,    -1,   448,    -1,   437,    -1,   450,    -1,
     451,    -1,   465,    -1,   453,    -1,   455,    -1,   457,    -1,
     456,    -1,   460,    -1,   454,    -1,   461,    -1,   462,    -1,
     463,    -1,   464,    -1,   477,    -1,   466,    -1,   467,    -1,
     468,    -1,   473,    -1,   458,    -1,   459,    -1,   483,    -1,
     481,    -1,   482,    -1,   440,    -1,   472,    -1,   449,    -1,
     470,    -1,   471,    -1,   436,    -1,   431,    -1,   432,    -1,
     433,    -1,   434,    -1,   435,    -1,   452,    -1,   430,    -1,
     469,    -1,     1,    -1,    90,   226,   106,   223,    -1,    41,
     226,   206,   223,    -1,    40,   226,   233,   223,    -1,    45,
     226,   233,   223,    -1,    43,   226,   106,   223,    -1,    44,
     226,   106,   223,    -1,   208,   226,   206,   223,    -1,    67,
     226,   233,   223,    -1,    54,   226,   206,   223,    -1,    58,
     226,   206,   223,    -1,    28,   226,   206,   223,    -1,    35,
     226,   206,   223,    -1,     6,   226,   206,   223,    -1,    86,
     226,   233,   223,    -1,    84,   226,   106,   223,    -1,    76,
     226,   106,   223,    -1,     7,   226,   233,   223,    -1,   212,
     226,   233,   223,    -1,   211,   226,   233,   223,    -1,    47,
     226,   106,   223,    -1,    59,   226,   206,   223,    -1,   221,
     226,   206,   223,    -1,   150,   226,   206,   223,    -1,   153,
     226,   206,   223,    -1,   154,   226,   206,   223,    -1,   152,
     226,   206,   223,    -1,   152,   226,   209,   223,    -1,   151,
     226,   206,   223,    -1,   151,   226,   209,   223,    -1,   114,
     226,   233,   223,    -1,    12,   226,   233,   223,    -1,   113,
     226,   206,   223,    -1,   115,   226,   233,   223,    -1,   144,
     226,   206,   223,    -1,   104,   226,   206,   223,    -1,   210,
     226,   206,   223,    -1,   110,   226,   206,   223,    -1,    29,
     226,   106,   223,    -1,    88,   226,   106,   223,    -1,   216,
     226,   206,   223,    -1,    30,   226,   121,   223,    -1,   183,
     226,   121,   223,    -1,   118,   226,   206,   223,    -1,    26,
     226,   206,   223,    -1,   207,   226,   233,   223,    -1,    -1,
     111,   474,   226,   475,   223,    -1,   475,   227,   476,    -1,
     476,    -1,   156,    -1,   158,    -1,   159,    -1,   161,    -1,
     162,    -1,   167,    -1,    48,    -1,   188,    -1,   175,    -1,
     179,    -1,   198,    -1,   190,    -1,   164,    -1,   177,    -1,
     184,    -1,   169,    -1,   203,    -1,   189,    -1,   157,    -1,
     172,    -1,   176,    -1,   165,    -1,    -1,   109,   478,   226,
     479,   223,    -1,   479,   227,   480,    -1,   480,    -1,   156,
      -1,   158,    -1,   159,    -1,   161,    -1,   162,    -1,   167,
      -1,   188,    -1,    48,    -1,   175,    -1,   179,    -1,   198,
      -1,   190,    -1,   164,    -1,   177,    -1,   184,    -1,   169,
      -1,   203,    -1,   189,    -1,   157,    -1,   172,    -1,   176,
      -1,   165,    -1,    92,   226,   106,   223,    -1,    93,   226,
     106,   223,    -1,    20,   226,   106,   223,    -1,    14,   225,
     485,   224,   223,    -1,   485,   486,    -1,   486,    -1,   492,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    -1,   493,
      -1,   494,    -1,   495,    -1,   496,    -1,   497,    -1,   498,
      -1,   487,    -1,     1,    -1,    27,   226,   206,   223,    -1,
      70,   226,   233,   223,    -1,    71,   226,   233,   223,    -1,
      79,   226,   106,   223,    -1,    78,   226,   106,   223,    -1,
      77,   226,   106,   223,    -1,    22,   226,   106,   223,    -1,
      21,   226,   106,   223,    -1,   102,   226,   206,   223,    -1,
     103,   226,   206,   223,    -1,    64,   226,   106,   223,    -1,
      65,   226,   233,   223,    -1,   142,   225,   500,   224,   223,
      -1,   500,   501,    -1,   501,    -1,   502,    -1,   503,    -1,
     504,    -1,   506,    -1,   507,    -1,   505,    -1,   508,    -1,
       1,    -1,    36,   226,   206,   223,    -1,    52,   226,   206,
     223,    -1,    53,   226,   206,   223,    -1,    49,   226,   121,
     223,    -1,    73,   226,   233,   223,    -1,    48,   226,   206,
     223,    -1,    51,   226,   206,   223,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   364,   364,   365,   368,   369,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   387,   388,   389,   393,   393,   394,   398,
     402,   406,   410,   414,   418,   422,   428,   428,   429,   430,
     431,   432,   439,   442,   442,   443,   443,   443,   445,   451,
     458,   460,   460,   461,   461,   462,   462,   463,   463,   464,
     464,   465,   465,   466,   466,   467,   467,   468,   468,   469,
     470,   473,   474,   476,   476,   477,   483,   491,   491,   492,
     498,   506,   548,   607,   635,   643,   658,   673,   682,   696,
     705,   733,   763,   788,   810,   832,   841,   843,   843,   844,
     844,   845,   845,   847,   856,   865,   877,   878,   878,   880,
     880,   881,   883,   890,   890,   903,   904,   906,   906,   907,
     907,   909,   917,   920,   926,   925,   931,   931,   932,   936,
     940,   944,   948,   952,   956,   967,   966,  1043,  1043,  1044,
    1044,  1044,  1045,  1045,  1045,  1046,  1046,  1046,  1048,  1054,
    1060,  1066,  1077,  1083,  1090,  1089,  1095,  1095,  1096,  1100,
    1104,  1108,  1112,  1116,  1120,  1124,  1128,  1132,  1136,  1140,
    1144,  1148,  1152,  1156,  1160,  1164,  1168,  1172,  1176,  1180,
    1187,  1186,  1192,  1192,  1193,  1197,  1201,  1205,  1209,  1213,
    1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,
    1257,  1261,  1265,  1269,  1273,  1277,  1281,  1292,  1291,  1352,
    1352,  1353,  1354,  1354,  1355,  1356,  1357,  1358,  1359,  1360,
    1361,  1362,  1363,  1363,  1364,  1365,  1366,  1367,  1369,  1375,
    1381,  1387,  1393,  1399,  1405,  1411,  1417,  1423,  1430,  1436,
    1442,  1448,  1457,  1467,  1466,  1472,  1472,  1473,  1477,  1488,
    1487,  1494,  1493,  1498,  1498,  1499,  1503,  1507,  1513,  1513,
    1514,  1514,  1514,  1514,  1514,  1516,  1516,  1518,  1518,  1520,
    1534,  1554,  1560,  1570,  1569,  1611,  1611,  1612,  1612,  1612,
    1612,  1613,  1613,  1613,  1614,  1614,  1616,  1622,  1628,  1634,
    1646,  1645,  1651,  1651,  1652,  1656,  1660,  1664,  1668,  1672,
    1676,  1680,  1684,  1688,  1694,  1708,  1717,  1731,  1730,  1745,
    1745,  1746,  1746,  1746,  1746,  1748,  1754,  1760,  1770,  1772,
    1772,  1773,  1773,  1775,  1791,  1790,  1815,  1815,  1816,  1816,
    1816,  1816,  1818,  1824,  1844,  1843,  1849,  1849,  1850,  1854,
    1858,  1862,  1866,  1870,  1874,  1878,  1882,  1886,  1896,  1895,
    1916,  1916,  1917,  1917,  1917,  1919,  1926,  1925,  1931,  1931,
    1932,  1936,  1940,  1944,  1948,  1952,  1956,  1960,  1964,  1968,
    1978,  1977,  2043,  2043,  2044,  2044,  2044,  2045,  2045,  2046,
    2046,  2046,  2047,  2047,  2047,  2048,  2048,  2049,  2051,  2057,
    2063,  2069,  2082,  2095,  2101,  2105,  2114,  2113,  2118,  2118,
    2119,  2123,  2129,  2140,  2146,  2152,  2158,  2174,  2173,  2199,
    2199,  2200,  2200,  2200,  2202,  2222,  2232,  2231,  2258,  2258,
    2259,  2259,  2259,  2261,  2267,  2276,  2278,  2278,  2279,  2279,
    2281,  2299,  2298,  2321,  2321,  2322,  2322,  2322,  2324,  2330,
    2339,  2342,  2342,  2343,  2343,  2344,  2344,  2345,  2345,  2346,
    2346,  2347,  2347,  2348,  2349,  2350,  2350,  2351,  2351,  2352,
    2352,  2353,  2353,  2354,  2354,  2355,  2355,  2356,  2356,  2357,
    2357,  2358,  2358,  2359,  2359,  2360,  2360,  2361,  2362,  2362,
    2363,  2364,  2365,  2365,  2366,  2366,  2367,  2368,  2369,  2370,
    2370,  2371,  2374,  2379,  2385,  2391,  2397,  2402,  2407,  2412,
    2417,  2422,  2427,  2432,  2437,  2442,  2447,  2452,  2457,  2462,
    2467,  2473,  2484,  2489,  2494,  2499,  2504,  2509,  2512,  2517,
    2520,  2525,  2530,  2535,  2540,  2545,  2550,  2555,  2560,  2565,
    2570,  2575,  2580,  2589,  2598,  2603,  2608,  2614,  2613,  2618,
    2618,  2619,  2622,  2625,  2628,  2631,  2634,  2637,  2640,  2643,
    2646,  2649,  2652,  2655,  2658,  2661,  2664,  2667,  2670,  2673,
    2676,  2679,  2682,  2688,  2687,  2692,  2692,  2693,  2696,  2699,
    2702,  2705,  2708,  2711,  2714,  2717,  2720,  2723,  2726,  2729,
    2732,  2735,  2738,  2741,  2744,  2747,  2750,  2753,  2756,  2761,
    2766,  2771,  2780,  2783,  2783,  2784,  2785,  2785,  2786,  2786,
    2787,  2788,  2789,  2790,  2791,  2791,  2792,  2792,  2794,  2799,
    2804,  2809,  2814,  2819,  2824,  2829,  2834,  2839,  2844,  2849,
    2857,  2860,  2860,  2861,  2861,  2862,  2863,  2864,  2864,  2865,
    2866,  2868,  2874,  2880,  2886,  2895,  2909,  2915
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
  "FAILED_OPER_NOTICE", "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE",
  "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_MIN_CIDR",
  "GLINE_MIN_CIDR6", "GLINE_REQUEST_DURATION", "GLOBAL_KILL",
  "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_IDLE_FROM_OPERS",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SERVICES", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "IRCD_AUTH", "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT",
  "JOIN_FLOOD_TIME", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE",
  "KLINE_EXEMPT", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "MASK", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_LENGTH",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_TOPIC_LENGTH",
  "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE",
  "MODULE", "MODULES", "NAME", "NEED_IDENT", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NO_CREATE_ON_SPLIT",
  "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE", "NUMBER",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID", "PACE_WAIT",
  "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME",
  "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT", "REDIRSERV",
  "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_EXTERNAL", "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_NONONREG", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_RESTART",
  "T_SERVER", "T_SERVICE", "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET",
  "T_SHARED", "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
  "T_SSL_CIPHER_LIST", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "T_WALLOPS", "T_WEBIRC", "TBOOL",
  "THROTTLE_TIME", "TKLINE_EXPIRE_NOTICES", "TMASKED",
  "TRUE_NO_OPER_FLOOD", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "TYPE",
  "UNKLINE", "USE_EGD", "USE_LOGGING", "USER", "VHOST", "VHOST6",
  "WARN_NO_NLINE", "XLINE", "';'", "'}'", "'{'", "'='", "','", "':'",
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
     475,   476,   477,    59,   125,   123,    61,    44,    58
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
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     300,   299,   301,   301,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   304,   303,   305,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   323,   322,   324,   324,   325,   325,   327,
     326,   329,   328,   330,   330,   331,   331,   331,   332,   332,
     333,   333,   333,   333,   333,   335,   334,   336,   336,   337,
     337,   338,   339,   341,   340,   342,   342,   343,   343,   343,
     343,   343,   343,   343,   343,   343,   344,   345,   346,   347,
     349,   348,   350,   350,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   351,   352,   353,   354,   356,   355,   357,
     357,   358,   358,   358,   358,   359,   360,   361,   362,   363,
     363,   364,   364,   365,   367,   366,   368,   368,   369,   369,
     369,   369,   370,   371,   373,   372,   374,   374,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   377,   376,
     378,   378,   379,   379,   379,   380,   382,   381,   383,   383,
     384,   384,   384,   384,   384,   384,   384,   384,   384,   384,
     386,   385,   387,   387,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   389,   390,
     391,   392,   393,   394,   395,   395,   397,   396,   398,   398,
     399,   399,   400,   401,   402,   403,   404,   406,   405,   407,
     407,   408,   408,   408,   409,   410,   412,   411,   413,   413,
     414,   414,   414,   415,   416,   417,   418,   418,   419,   419,
     420,   422,   421,   423,   423,   424,   424,   424,   425,   426,
     427,   428,   428,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   429,   429,   429,   429,   429,   429,   429,   429,
     429,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   455,   456,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   474,   473,   475,
     475,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   478,   477,   479,   479,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   480,
     480,   480,   480,   480,   480,   480,   480,   480,   480,   481,
     482,   483,   484,   485,   485,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   500,   501,   501,   501,   501,   501,   501,   501,
     501,   502,   503,   504,   505,   506,   507,   508
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
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     0,
       6,     0,     5,     3,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     2,     0,     5,     3,     1,     1,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     2,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   207,   370,   416,     0,
     431,     0,   273,   407,   249,     0,   135,   307,     0,     0,
     348,     0,     0,   324,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     594,   606,   596,   597,   598,   599,   595,   600,   601,   602,
     603,   604,   605,     0,     0,     0,   429,     0,     0,   427,
     428,     0,   491,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     563,     0,   537,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   442,   489,   483,   484,   485,   486,   487,   482,
     453,   443,   444,   477,   445,   446,   447,   448,   449,   450,
     451,   452,   479,   454,   455,   488,   457,   462,   458,   460,
     459,   472,   473,   461,   463,   464,   465,   466,   456,   468,
     469,   470,   490,   480,   481,   478,   471,   467,   475,   476,
     474,     0,     0,     0,     0,     0,     0,     0,    44,    45,
      46,     0,     0,   630,     0,     0,     0,     0,     0,     0,
       0,     0,   622,   623,   624,   625,   628,   626,   627,   629,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    52,
      67,    68,    66,    63,    62,    69,    53,    65,    56,    57,
      58,    54,    64,    59,    60,    61,    55,     0,     0,     0,
       0,   108,   109,   110,     0,   322,     0,     0,   320,   321,
       0,   102,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
     211,   214,   216,   217,   218,   219,   220,   221,   222,   223,
     212,   213,   215,   224,   225,   226,     0,     0,     0,     0,
       0,     0,     0,   396,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,   378,   380,   379,   382,
     386,   383,   384,   385,   381,   422,     0,     0,     0,   419,
     420,   421,     0,     0,   426,   437,     0,     0,     0,   434,
     435,   436,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   441,     0,     0,     0,   290,     0,     0,     0,     0,
       0,     0,   276,   277,   278,   279,   284,   280,   281,   282,
     283,   413,     0,     0,     0,   410,   411,   412,     0,     0,
       0,   251,     0,   261,     0,   259,   260,   262,   263,    47,
       0,     0,     0,    43,     0,     0,     0,   180,     0,     0,
       0,   154,     0,     0,   138,   139,   140,   141,   144,   145,
     143,   142,   146,     0,     0,     0,     0,     0,   310,   311,
     312,   313,     0,     0,     0,     0,     0,     0,     0,     0,
     621,    70,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      51,     0,     0,   356,     0,   351,   352,   353,   111,     0,
       0,   107,     0,     0,     0,   319,     0,     0,   334,     0,
       0,   327,   328,   329,   330,     0,     0,     0,    96,     0,
       0,     0,     0,    26,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   227,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,   387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   372,     0,     0,
       0,   418,     0,   425,     0,     0,     0,   433,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   440,   285,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
       0,     0,     0,   409,   264,     0,     0,     0,     0,     0,
     258,     0,     0,    42,   147,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   137,   314,     0,     0,     0,     0,
     309,     0,     0,     0,     0,     0,     0,     0,   620,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,    50,   354,     0,     0,     0,   350,     0,   106,
       0,     0,   318,   331,     0,     0,     0,     0,   326,   105,
     104,   103,   615,   614,   608,   618,    26,    26,    26,    26,
      26,    26,    26,    28,    27,   619,   609,   610,   613,   612,
     611,   616,   617,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   371,     0,     0,   417,   430,
       0,     0,   432,   504,   508,   522,   591,   535,   502,   529,
     532,   503,   494,   493,   496,   497,   495,   511,   500,   501,
     512,   499,   507,   506,   505,   530,   492,   589,   590,   526,
     574,   567,   585,   568,   569,   570,   571,   579,   588,   572,
     582,   586,   575,   587,   580,   576,   581,   573,   584,   578,
     577,   583,     0,   566,   528,   547,   541,   559,   542,   543,
     544,   545,   553,   562,   546,   556,   560,   549,   561,   554,
     550,   555,   548,   558,   552,   551,   557,     0,   540,   523,
     521,   524,   534,   525,   514,   519,   520,   517,   518,   515,
     516,   533,   536,   498,   527,   510,   509,   531,   513,     0,
       0,     0,     0,     0,     0,     0,     0,   274,     0,     0,
     408,     0,     0,     0,   269,   265,   268,   250,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,   308,   631,   636,   634,   637,   632,   633,   635,
      87,    95,    86,    93,    94,    85,    89,    88,    82,    81,
      83,    92,    84,    71,     0,    72,     0,    90,    91,     0,
       0,   349,   112,     0,     0,     0,   124,     0,   116,   117,
     119,   118,   323,     0,     0,     0,   325,    29,    30,    31,
      32,    33,    34,    35,   238,   239,   231,   248,   247,     0,
     246,   233,   235,   242,   234,   232,   241,   228,   240,   230,
     229,    36,    36,    36,    38,    37,   236,   237,   392,   394,
     395,   405,   402,   389,   403,   400,   401,     0,   399,   404,
     388,   393,   391,   406,   390,   423,   424,   438,   439,   564,
       0,   538,     0,   288,   289,   298,   295,   300,   296,   297,
     303,   299,   301,   294,   302,     0,   293,   287,   306,   305,
     304,   286,   415,   414,   272,   271,   256,   257,   255,     0,
     254,     0,     0,     0,   153,   151,   199,   187,   196,   195,
     185,   190,   206,   198,   204,   189,   192,   201,   203,   200,
     197,   205,   193,   202,   191,   194,     0,   183,   148,   150,
     152,   164,   158,   176,   159,   160,   161,   162,   170,   179,
     163,   173,   177,   166,   178,   171,   167,   172,   165,   175,
     169,   168,   174,     0,   157,   149,   317,   315,   316,    73,
      77,   355,   360,   366,   369,   362,   368,   363,   367,   365,
     361,   364,     0,   359,   120,     0,     0,     0,     0,   115,
     332,   338,   344,   347,   340,   346,   341,   345,   343,   339,
     342,     0,   337,   333,   244,     0,    39,    40,    41,   397,
       0,   565,   539,   291,     0,   252,     0,   270,   267,   266,
       0,     0,     0,   181,     0,   155,     0,   357,     0,     0,
       0,     0,     0,   114,   335,     0,   245,   398,   292,   253,
     186,   184,   188,   182,   156,   358,   121,   123,   122,   130,
     133,   132,   129,   134,   131,   128,     0,   127,   336,   125,
       0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   783,   784,  1034,  1035,    25,   217,   218,
     219,   220,    26,   258,   259,   260,   261,   744,   745,   748,
     749,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   275,   276,    27,    71,    72,    73,
      74,    75,    28,   280,   281,   282,   283,   284,   997,   998,
     999,  1000,  1001,  1167,  1236,  1237,    29,    59,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   711,  1143,  1144,
     502,   707,  1116,  1117,    30,    49,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   587,  1019,  1020,    31,    57,   473,
     697,  1089,  1090,   474,   475,   476,  1093,   945,   946,   477,
     478,    32,    55,   451,   452,   453,   454,   455,   456,   457,
     682,  1075,  1076,   458,   459,   460,    33,    60,   507,   508,
     509,   510,   511,    34,   287,   288,   289,    35,    66,   560,
     561,   562,   563,   564,   765,  1181,  1182,    36,    63,   544,
     545,   546,   547,   755,  1162,  1163,    37,    50,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   609,  1047,
    1048,   370,   371,   372,   373,   374,    38,    56,   464,   465,
     466,   467,    39,    51,   378,   379,   380,   381,    40,   108,
     109,   110,    41,    53,   388,   389,   390,   391,    42,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   421,   907,   908,   207,   419,
     882,   883,   208,   209,   210,    43,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      44,   231,   232,   233,   234,   235,   236,   237,   238,   239
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -984
static const yytype_int16 yypact[] =
{
    -984,   578,  -984,  -190,  -219,  -210,  -984,  -984,  -984,  -169,
    -984,  -156,  -984,  -984,  -984,  -148,  -984,  -984,  -127,  -106,
    -984,   -85,   -61,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,   330,   852,   -33,
     -19,   -14,    37,    -2,   364,    39,    42,    44,    82,    59,
      67,   500,   339,    70,    30,    16,    71,   -71,     5,    49,
      57,    20,  -984,  -984,  -984,  -984,  -984,    63,    77,    84,
      87,    97,   101,   103,   106,   107,   109,   111,   113,   241,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   618,   466,    18,  -984,   115,    26,  -984,
    -984,    62,  -984,   116,   119,   121,   122,   123,   124,   125,
     129,   130,   131,   132,   133,   134,   136,   138,   141,   142,
     146,   149,   151,   152,   157,   159,   160,   161,   162,   163,
    -984,   165,  -984,   180,   184,   186,   187,   188,   189,   190,
     191,   193,   195,   199,   203,   204,   206,   207,   208,   210,
     211,    17,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,   365,    81,    25,    93,   215,   216,     6,  -984,  -984,
    -984,   495,    58,  -984,   217,   218,   220,   225,   227,   229,
     232,   273,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
     158,   234,   235,   236,   237,   238,   246,   250,   258,   259,
     260,   265,   266,   268,   269,   274,   276,   277,    66,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,    88,   281,   280,
      29,  -984,  -984,  -984,   168,  -984,   285,    53,  -984,  -984,
       8,  -984,   279,   282,   378,   296,  -984,   201,   414,   316,
     418,   420,   420,   420,   423,   424,   433,   334,   335,   319,
    -984,   322,   320,   324,   328,  -984,   329,   337,   338,   340,
     344,   351,   355,   358,   361,   367,   368,   376,   174,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   333,   377,   379,   382,
     384,   388,   391,  -984,   394,   397,   399,   402,   403,   404,
     177,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   405,   409,    13,  -984,
    -984,  -984,   439,   342,  -984,  -984,   410,   416,    24,  -984,
    -984,  -984,   401,   420,   420,   537,   440,   442,   541,   528,
     444,   420,   445,   547,   548,   420,   549,   453,   454,   456,
     420,   558,   559,   420,   560,   561,   563,   566,   468,   449,
     470,   451,   472,   420,   420,   473,   475,   476,   -32,     7,
     477,   480,   567,   420,   483,   487,   420,   420,   488,   490,
     479,  -984,   485,   484,   486,  -984,   489,   491,   493,   496,
     497,   155,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   498,   501,   112,  -984,  -984,  -984,   505,   503,
     504,  -984,   506,  -984,    19,  -984,  -984,  -984,  -984,  -984,
     582,   590,   512,  -984,   513,   514,   516,  -984,   517,   518,
     519,  -984,   520,   156,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   525,   523,   524,   526,    21,  -984,  -984,
    -984,  -984,   510,   533,   597,   550,   551,   552,   420,   530,
    -984,  -984,   634,   555,   641,   657,   663,   651,   654,   656,
     659,   661,   662,   673,   666,  -154,   -78,   668,   669,   568,
    -984,   569,   574,  -984,    52,  -984,  -984,  -984,  -984,   588,
     572,  -984,   576,   681,   580,  -984,   581,   579,  -984,   583,
      90,  -984,  -984,  -984,  -984,   585,   587,   595,  -984,   598,
     601,   603,   605,   765,   606,   608,   613,   615,   616,   617,
     620,   621,  -984,  -984,   700,   705,   420,   619,   707,   726,
     420,   735,   753,   420,   742,   758,   760,   420,   761,   761,
     652,  -984,  -984,   755,    50,   757,   674,   771,   772,   671,
     773,   774,   799,   785,   786,   787,   686,  -984,   789,   790,
     689,  -984,   690,  -984,   793,   794,   695,  -984,   696,   697,
     698,   701,   702,   703,   704,   709,   710,   711,   712,   713,
     714,   715,   716,   717,   718,   719,   720,   721,   722,   723,
     724,   725,   727,   728,   729,   609,   730,   658,   733,   734,
     736,   737,   738,   739,   740,   741,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   754,   756,  -984,  -984,
     807,   759,   732,   828,   870,   857,   859,   860,   762,  -984,
     861,   862,   763,  -984,  -984,   863,   866,   764,   882,   766,
    -984,   768,   769,  -984,  -984,   872,   788,   770,   874,   876,
     877,   775,   878,   777,  -984,  -984,   881,   883,   884,   780,
    -984,   783,   784,   791,   792,   795,   796,   797,  -984,   798,
     800,   801,   802,   803,   804,   805,   806,   808,   809,   810,
     811,   812,  -984,  -984,  -195,  -984,  -984,  -984,  -188,  -984,
     813,   814,  -984,  -984,   887,   815,   816,  -984,   817,  -984,
      64,   819,  -984,  -984,   888,   818,   889,   820,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   420,   420,   420,   420,
     420,   420,   420,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   822,   823,   824,   -34,   825,   826,   827,
     829,   830,   831,   832,   833,   834,   835,     2,   836,   837,
    -984,   838,   839,   840,   841,   842,   843,   844,     0,   845,
     846,   847,   848,   849,   850,  -984,   851,   853,  -984,  -984,
     854,   855,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -187,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -157,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   856,
     858,   492,   864,   865,   867,   868,   869,  -984,   871,   873,
    -984,   875,   879,   -38,   880,   885,  -984,  -984,  -984,  -984,
     886,   890,   441,   891,   892,   893,   693,   894,  -984,   895,
     896,   897,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -154,  -984,   -78,  -984,  -984,   898,
     469,  -984,  -984,   899,   900,   901,  -984,   114,  -984,  -984,
    -984,  -984,  -984,   902,   532,   905,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -155,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,   761,   761,   761,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,   -81,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
     609,  -984,   658,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,   -73,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   -64,
    -984,   906,   882,   907,  -984,  -984,  -984,   903,  -984,  -984,
     904,  -984,  -984,  -984,  -984,   908,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   -44,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,   -25,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   -22,  -984,  -984,   909,  -101,   911,   910,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,   -20,  -984,  -984,  -984,   -34,  -984,  -984,  -984,  -984,
       0,  -984,  -984,  -984,   492,  -984,   -38,  -984,  -984,  -984,
     924,   948,   953,  -984,   441,  -984,   693,  -984,   469,   912,
     915,   916,   381,  -984,  -984,   532,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,   -15,  -984,  -984,  -984,
     381,  -984
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -984,  -984,  -984,   108,  -299,  -983,  -598,  -984,  -984,   821,
    -984,  -984,  -984,  -984,   913,  -984,  -984,  -984,    27,  -984,
      31,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   942,  -984,
    -984,  -984,  -984,  -984,   914,  -984,  -984,  -984,  -984,    85,
    -984,  -984,  -984,  -984,  -984,  -224,  -984,  -984,  -984,   529,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -123,
    -984,  -984,  -984,  -120,  -984,  -984,  -984,   767,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -100,  -984,  -984,  -984,
    -984,  -984,  -110,  -984,   623,  -984,  -984,  -984,    -3,  -984,
    -984,  -984,  -984,  -984,   648,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   -94,  -984,  -984,  -984,  -984,  -984,  -984,   594,
    -984,  -984,  -984,  -984,  -984,   917,  -984,  -984,  -984,  -984,
     543,  -984,  -984,  -984,  -984,  -984,  -111,  -984,  -984,  -984,
     562,  -984,  -984,  -984,  -984,  -103,  -984,  -984,  -984,   781,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
     -83,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,   644,
    -984,  -984,  -984,  -984,  -984,   776,  -984,  -984,  -984,  -984,
    1002,  -984,  -984,  -984,  -984,   778,  -984,  -984,  -984,  -984,
     950,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,    61,  -984,  -984,
    -984,    69,  -984,  -984,  -984,  -984,  -984,  1035,  -984,  -984,
    -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,  -984,
    -984,  -984,   918,  -984,  -984,  -984,  -984,  -984,  -984,  -984
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     808,   809,   574,   575,   576,   807,    47,   214,  1045,   556,
    1086,  1031,  1032,  1033,   375,    48,  1017,   285,   112,   375,
     468,    67,   503,   113,   114,   385,   468,   106,   983,   115,
     278,   278,   984,    45,    46,   985,  1059,   116,   106,   986,
    1060,   742,   743,   117,    68,   118,   119,   120,  1186,  1187,
    1188,    69,   121,   541,   285,   504,    52,   122,   123,   503,
     124,   125,   126,   385,   127,   993,  1061,   240,  1184,    54,
    1062,   128,  1185,   376,   469,   129,   130,    58,   376,   470,
     469,   471,   461,   214,   131,   470,   107,   471,  1018,   541,
     241,   556,   504,   132,   629,   630,   505,   107,    61,  1210,
     215,   133,   637,   134,   557,   135,   641,   136,   807,   137,
     138,   646,   286,   461,   649,   993,    70,   746,   747,    62,
     386,   139,   242,   216,   659,   660,   140,   141,   142,   243,
     143,   144,   145,   505,   671,   146,   377,   674,   675,   472,
      64,   377,  1189,  1087,   506,   472,  1190,   387,   542,   286,
    1193,   244,   291,  1088,  1194,   245,   442,   484,   386,  1195,
     994,   147,   246,  1196,    65,   247,   248,   148,   149,   150,
     151,   152,   443,   485,   664,   311,   215,   665,   346,  1203,
     347,   506,   348,  1204,   542,   387,   557,   444,   486,   312,
     313,  1046,   103,   314,   349,  -113,  -113,   249,  1205,   216,
     153,  1207,  1206,  1214,   462,  1208,   104,  1215,  1239,   350,
     994,   105,  1240,   666,   250,   251,   667,   445,   487,   727,
     812,   813,   558,   111,   154,   155,   559,   156,   157,   158,
     482,   292,   351,   159,   352,   462,   315,   620,   160,   353,
     252,   440,    76,   699,   295,   719,   279,   279,   626,   354,
     383,   995,   488,   550,   316,   317,   318,   319,   253,   254,
     255,   320,    77,    78,   211,   321,   543,   212,    79,   213,
     322,   446,   489,   355,   223,   293,   756,   554,   996,   447,
     448,   323,   324,   294,   221,   256,   257,   795,   490,   297,
     539,   799,   222,   325,   802,   277,   290,   356,   806,   463,
     449,   995,   543,   298,   558,    80,    81,   569,   559,   224,
     299,    82,    83,   300,   767,   326,   479,   357,    84,    85,
      86,   225,   226,   301,   227,   228,   229,   302,   996,   303,
     463,    67,   304,   305,   552,   306,   692,   307,  1168,   308,
     240,   382,   392,    87,    88,   393,   230,   394,   395,   396,
     397,   398,   327,   491,    68,   399,   400,   401,   402,   403,
     404,    69,   405,   241,   406,   112,   442,   407,   408,   358,
     113,   114,   409,   450,   492,   410,   115,   411,   412,   688,
     713,   521,   443,   413,   116,   414,   415,   416,   417,   418,
     117,   420,   118,   119,   120,   242,   359,   444,   600,   121,
     565,   616,   243,   566,   122,   123,   422,   124,   125,   126,
     423,   127,   424,   425,   426,   427,   428,   429,   128,   430,
    1229,   431,   129,   130,   244,   432,    70,   445,   245,   433,
     434,   131,   435,   436,   437,   246,   438,   439,   247,   248,
     132,   480,   481,   512,   513,  1096,   514,  1230,   133,  1231,
     134,   515,   135,   516,   136,   517,   137,   138,   518,  1097,
     522,   523,   524,   525,   526,   309,  1098,   346,   139,   347,
     249,   348,   527,   140,   141,   142,   528,   143,   144,   145,
    1099,   446,   146,   349,   529,   530,   531,   250,   251,   447,
     448,   532,   533,  1232,   534,   535,   484,   519,   350,   567,
     536,   223,   537,   538,   548,  1065,   549,  1100,   147,  1101,
     449,   553,   485,   252,   148,   149,   150,   151,   152,   568,
     570,   351,   571,   352,   572,  1066,   573,   486,   353,   577,
     578,   253,   254,   255,  1067,  1102,   224,  1152,   354,   579,
     580,   581,   582,  1233,  1234,   583,   584,   153,   225,   226,
     585,   227,   228,   229,   586,   588,   602,   487,   256,   257,
     622,  1068,   355,   589,   590,   623,   591,  1103,  1211,  1104,
     592,   154,   155,   230,   156,   157,   158,   593,     2,     3,
     159,   594,     4,   450,   595,   160,   356,   596,  1105,  1069,
    1070,   488,     5,   597,   598,     6,     7,  1071,  1153,  1235,
    1171,     8,   599,   603,  1106,   604,   357,   628,   605,  1107,
     606,   489,     9,  1108,   607,    10,    11,   608,  1109,   311,
     610,  1110,  1072,   611,  1154,   612,  1111,   490,   613,   614,
     615,   618,  1155,   312,   313,   619,   624,   314,  1073,    12,
    1112,  1156,   625,   631,    13,  1113,   632,   634,   633,   635,
     636,   638,    14,   639,   640,   642,  1114,   860,   358,   643,
     644,  1172,   645,  1115,   647,   648,   650,   651,  1157,   652,
    1158,  1159,   653,    15,   654,   655,   656,   657,   658,   661,
     315,   662,   663,   668,  1160,   359,   669,  1173,   670,   672,
      16,  1161,   491,   673,   676,  1174,   677,  1074,   316,   317,
     318,   319,   678,   701,  1175,   320,   885,    17,   679,   321,
     680,   702,   681,   492,   322,   683,   721,   684,   723,   685,
      18,    19,   686,   687,   690,   323,   324,   691,   694,   695,
     696,  1176,   698,  1177,  1178,   703,   704,   325,    20,   722,
     705,  1121,   706,   708,   709,   710,   712,  1179,   715,   716,
     717,    21,   718,   728,  1180,   729,   724,   725,   726,   326,
      22,   730,   731,   732,    23,   861,   862,   863,   864,   733,
     865,   866,   734,   867,   868,   735,   869,   736,   870,   740,
     737,   871,   738,   739,   872,   873,   874,   741,   875,   750,
     751,   752,   753,   876,   758,   759,   327,   877,   878,   879,
     754,   760,   761,   762,   763,   764,   793,   880,   769,   766,
     770,   794,   881,   797,   886,   887,   888,   889,   771,   890,
     891,   772,   892,   893,   773,   894,   774,   895,   775,   785,
     896,   786,   798,   897,   898,   899,   787,   900,   788,   789,
     790,   800,   901,   791,   792,   796,   902,   903,   904,  1122,
    1123,  1124,  1125,    76,  1126,  1127,   905,  1128,  1129,   801,
    1130,   906,  1131,   803,   804,  1132,   805,   807,  1133,  1134,
    1135,   573,  1136,    77,    78,   810,   811,  1137,   814,    79,
     815,  1138,  1139,  1140,  1007,  1008,  1009,  1010,  1011,  1012,
    1013,  1141,   816,   817,   819,   820,  1142,   818,   776,   777,
     778,   779,   780,   781,   782,   821,   822,   823,   824,   825,
     826,   827,   828,   829,   830,   831,    80,    81,   832,   833,
     834,   835,    82,    83,   836,   837,   838,   839,   929,    84,
      85,    86,   840,   841,   842,   843,   844,   845,   846,   847,
     848,   849,   850,   851,   852,   853,   854,   855,   856,   932,
     857,   858,   859,   884,    87,    88,   909,   910,   931,   911,
     912,   913,   914,   915,   916,   930,   917,   918,   919,   920,
     921,   922,   923,   924,   925,   926,   933,   927,   934,   928,
     935,   936,   938,   939,   941,   937,   940,   942,   944,   947,
     943,   948,   949,   950,   951,   953,   952,   954,   955,   957,
     958,   956,   959,   962,   960,   961,   963,   964,   989,  1003,
    1005,  1149,  1197,   296,   965,   966,  1241,  1150,   967,   968,
     969,   970,   714,   971,   972,   973,   974,   975,   976,   977,
    1209,   978,   979,   980,   981,   982,   987,   988,   483,   991,
     992,   990,  1002,  1006,  1004,  1014,  1015,  1016,  1021,  1022,
    1023,  1220,  1024,  1025,  1026,  1027,  1028,  1029,  1030,  1036,
    1037,  1038,  1039,  1040,  1041,  1042,  1043,  1044,  1049,  1050,
    1051,  1052,  1053,  1054,  1055,  1221,  1056,  1057,  1058,  1063,
    1222,  1064,  1169,  1224,  1223,  1216,  1219,  1077,  1078,  1198,
    1079,  1080,  1081,  1091,  1082,   601,  1083,   700,  1084,   689,
    1218,   720,  1085,   768,  1238,  1225,   757,  1217,   693,  1094,
     384,   441,  1092,  1095,  1118,  1119,  1120,  1145,  1146,  1147,
    1148,  1151,  1164,  1192,   310,  1170,  1165,  1166,  1183,  1191,
    1199,  1200,  1201,  1213,     0,  1226,  1202,  1212,  1227,  1228,
       0,   617,     0,     0,     0,     0,     0,     0,     0,   520,
       0,     0,     0,     0,   621,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   627,     0,     0,     0,
       0,   540,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   551,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   555
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-984)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     598,   599,   301,   302,   303,   106,   225,     1,     8,     1,
      48,     9,    10,    11,     1,   225,    50,     1,     1,     1,
       1,     1,     1,     6,     7,     1,     1,     1,   223,    12,
       1,     1,   227,   223,   224,   223,   223,    20,     1,   227,
     227,   195,   196,    26,    24,    28,    29,    30,  1031,  1032,
    1033,    31,    35,     1,     1,    34,   225,    40,    41,     1,
      43,    44,    45,     1,    47,     1,   223,     1,   223,   225,
     227,    54,   227,    60,    55,    58,    59,   225,    60,    60,
      55,    62,     1,     1,    67,    60,    60,    62,   122,     1,
      24,     1,    34,    76,   393,   394,    75,    60,   225,   200,
      94,    84,   401,    86,    96,    88,   405,    90,   106,    92,
      93,   410,    96,     1,   413,     1,    96,   195,   196,   225,
      96,   104,    56,   117,   423,   424,   109,   110,   111,    63,
     113,   114,   115,    75,   433,   118,   123,   436,   437,   120,
     225,   123,   223,   181,   123,   120,   227,   123,    96,    96,
     223,    85,   223,   191,   227,    89,     1,     1,    96,   223,
      96,   144,    96,   227,   225,    99,   100,   150,   151,   152,
     153,   154,    17,    17,   206,     1,    94,   209,     1,   223,
       3,   123,     5,   227,    96,   123,    96,    32,    32,    15,
      16,   191,   225,    19,    17,   166,   166,   131,   223,   117,
     183,   223,   227,   223,   123,   227,   225,   227,   223,    32,
      96,   225,   227,   206,   148,   149,   209,    62,    62,   518,
     170,   171,   214,   225,   207,   208,   218,   210,   211,   212,
     224,   226,    55,   216,    57,   123,    62,   224,   221,    62,
     174,   224,     1,   224,   224,   224,   217,   217,   224,    72,
     224,   187,    96,   224,    80,    81,    82,    83,   192,   193,
     194,    87,    21,    22,   225,    91,   214,   225,    27,   225,
      96,   116,   116,    96,     1,   226,   224,   224,   214,   124,
     125,   107,   108,   226,   225,   219,   220,   586,   132,   226,
     224,   590,   225,   119,   593,   225,   225,   120,   597,   218,
     145,   187,   214,   226,   214,    64,    65,   106,   218,    36,
     226,    70,    71,   226,   224,   141,   223,   140,    77,    78,
      79,    48,    49,   226,    51,    52,    53,   226,   214,   226,
     218,     1,   226,   226,   166,   226,   224,   226,   224,   226,
       1,   226,   226,   102,   103,   226,    73,   226,   226,   226,
     226,   226,   178,   197,    24,   226,   226,   226,   226,   226,
     226,    31,   226,    24,   226,     1,     1,   226,   226,   192,
       6,     7,   226,   218,   218,   226,    12,   226,   226,   224,
     224,   223,    17,   226,    20,   226,   226,   226,   226,   226,
      26,   226,    28,    29,    30,    56,   219,    32,   224,    35,
     121,   224,    63,   121,    40,    41,   226,    43,    44,    45,
     226,    47,   226,   226,   226,   226,   226,   226,    54,   226,
      39,   226,    58,    59,    85,   226,    96,    62,    89,   226,
     226,    67,   226,   226,   226,    96,   226,   226,    99,   100,
      76,   226,   226,   226,   226,     4,   226,    66,    84,    68,
      86,   226,    88,   226,    90,   226,    92,    93,   226,    18,
     226,   226,   226,   226,   226,   224,    25,     1,   104,     3,
     131,     5,   226,   109,   110,   111,   226,   113,   114,   115,
      39,   116,   118,    17,   226,   226,   226,   148,   149,   124,
     125,   226,   226,   112,   226,   226,     1,   224,    32,   121,
     226,     1,   226,   226,   223,    13,   226,    66,   144,    68,
     145,   226,    17,   174,   150,   151,   152,   153,   154,   223,
     106,    55,   206,    57,   106,    33,   106,    32,    62,   106,
     106,   192,   193,   194,    42,    94,    36,    68,    72,   106,
     206,   206,   223,   162,   163,   223,   226,   183,    48,    49,
     226,    51,    52,    53,   226,   226,   223,    62,   219,   220,
     121,    69,    96,   226,   226,   223,   226,   126,  1166,   128,
     226,   207,   208,    73,   210,   211,   212,   226,     0,     1,
     216,   226,     4,   218,   226,   221,   120,   226,   147,    97,
      98,    96,    14,   226,   226,    17,    18,   105,   129,   218,
      68,    23,   226,   226,   163,   226,   140,   206,   226,   168,
     226,   116,    34,   172,   226,    37,    38,   226,   177,     1,
     226,   180,   130,   226,   155,   226,   185,   132,   226,   226,
     226,   226,   163,    15,    16,   226,   226,    19,   146,    61,
     199,   172,   226,   106,    66,   204,   206,   106,   206,   121,
     206,   206,    74,   106,   106,   106,   215,    48,   192,   206,
     206,   129,   206,   222,   106,   106,   106,   106,   199,   106,
     201,   202,   106,    95,   206,   226,   206,   226,   206,   206,
      62,   206,   206,   206,   215,   219,   206,   155,   121,   206,
     112,   222,   197,   206,   206,   163,   206,   205,    80,    81,
      82,    83,   223,   121,   172,    87,    48,   129,   223,    91,
     226,   121,   226,   218,    96,   226,   206,   226,   121,   226,
     142,   143,   226,   226,   226,   107,   108,   226,   223,   226,
     226,   199,   226,   201,   202,   223,   223,   119,   160,   206,
     226,    48,   226,   226,   226,   226,   226,   215,   223,   226,
     226,   173,   226,   223,   222,   121,   206,   206,   206,   141,
     182,   206,   121,   106,   186,   156,   157,   158,   159,   106,
     161,   162,   121,   164,   165,   121,   167,   121,   169,   106,
     121,   172,   121,   121,   175,   176,   177,   121,   179,   121,
     121,   223,   223,   184,   206,   223,   178,   188,   189,   190,
     226,   225,   121,   223,   223,   226,   106,   198,   223,   226,
     223,   106,   203,   106,   156,   157,   158,   159,   223,   161,
     162,   223,   164,   165,   223,   167,   223,   169,   223,   223,
     172,   223,   106,   175,   176,   177,   223,   179,   223,   223,
     223,   106,   184,   223,   223,   226,   188,   189,   190,   156,
     157,   158,   159,     1,   161,   162,   198,   164,   165,   106,
     167,   203,   169,   121,   106,   172,   106,   106,   175,   176,
     177,   106,   179,    21,    22,   223,   121,   184,   121,    27,
     206,   188,   189,   190,   776,   777,   778,   779,   780,   781,
     782,   198,   121,   121,   121,   121,   203,   226,   133,   134,
     135,   136,   137,   138,   139,   106,   121,   121,   121,   223,
     121,   121,   223,   223,   121,   121,    64,    65,   223,   223,
     223,   223,    70,    71,   223,   223,   223,   223,   121,    77,
      78,    79,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   121,
     223,   223,   223,   223,   102,   103,   223,   223,   226,   223,
     223,   223,   223,   223,   223,   206,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   106,   223,   121,   223,
     121,   121,   121,   121,   121,   223,   223,   121,   106,   223,
     226,   223,   223,   121,   206,   121,   226,   121,   121,   121,
     223,   226,   121,   223,   121,   121,   223,   223,   121,   121,
     121,   984,   106,    71,   223,   223,  1240,   986,   223,   223,
     223,   223,   493,   223,   223,   223,   223,   223,   223,   223,
     121,   223,   223,   223,   223,   223,   223,   223,   217,   223,
     223,   226,   223,   223,   226,   223,   223,   223,   223,   223,
     223,   127,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   127,   223,   223,   223,   223,
     127,   223,   997,  1206,  1204,  1185,  1196,   223,   223,  1092,
     223,   223,   223,   213,   223,   328,   223,   474,   223,   451,
    1194,   507,   223,   560,  1215,  1208,   544,  1190,   464,   223,
     108,   161,   227,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,  1062,    89,   223,   226,   226,   223,  1060,
     223,   228,   228,   223,    -1,   223,   228,   226,   223,   223,
      -1,   360,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   231,
      -1,    -1,    -1,    -1,   378,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   388,    -1,    -1,    -1,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   280,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   287
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   230,     0,     1,     4,    14,    17,    18,    23,    34,
      37,    38,    61,    66,    74,    95,   112,   129,   142,   143,
     160,   173,   182,   186,   231,   236,   241,   265,   271,   285,
     303,   326,   340,   355,   362,   366,   376,   385,   405,   411,
     417,   421,   427,   484,   499,   223,   224,   225,   225,   304,
     386,   412,   225,   422,   225,   341,   406,   327,   225,   286,
     356,   225,   225,   377,   225,   225,   367,     1,    24,    31,
      96,   266,   267,   268,   269,   270,     1,    21,    22,    27,
      64,    65,    70,    71,    77,    78,    79,   102,   103,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   225,   225,   225,     1,    60,   418,   419,
     420,   225,     1,     6,     7,    12,    20,    26,    28,    29,
      30,    35,    40,    41,    43,    44,    45,    47,    54,    58,
      59,    67,    76,    84,    86,    88,    90,    92,    93,   104,
     109,   110,   111,   113,   114,   115,   118,   144,   150,   151,
     152,   153,   154,   183,   207,   208,   210,   211,   212,   216,
     221,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   477,   481,   482,
     483,   225,   225,   225,     1,    94,   117,   237,   238,   239,
     240,   225,   225,     1,    36,    48,    49,    51,    52,    53,
      73,   500,   501,   502,   503,   504,   505,   506,   507,   508,
       1,    24,    56,    63,    85,    89,    96,    99,   100,   131,
     148,   149,   174,   192,   193,   194,   219,   220,   242,   243,
     244,   245,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   225,     1,   217,
     272,   273,   274,   275,   276,     1,    96,   363,   364,   365,
     225,   223,   226,   226,   226,   224,   267,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   224,
     486,     1,    15,    16,    19,    62,    80,    81,    82,    83,
      87,    91,    96,   107,   108,   119,   141,   178,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,     1,     3,     5,    17,
      32,    55,    57,    62,    72,    96,   120,   140,   192,   219,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     400,   401,   402,   403,   404,     1,    60,   123,   413,   414,
     415,   416,   226,   224,   419,     1,    96,   123,   423,   424,
     425,   426,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   478,
     226,   474,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     224,   429,     1,    17,    32,    62,   116,   124,   125,   145,
     218,   342,   343,   344,   345,   346,   347,   348,   352,   353,
     354,     1,   123,   218,   407,   408,   409,   410,     1,    55,
      60,    62,   120,   328,   332,   333,   334,   338,   339,   223,
     226,   226,   224,   238,     1,    17,    32,    62,    96,   116,
     132,   197,   218,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   299,     1,    34,    75,   123,   357,   358,   359,
     360,   361,   226,   226,   226,   226,   226,   226,   226,   224,
     501,   223,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   224,
     243,     1,    96,   214,   378,   379,   380,   381,   223,   226,
     224,   273,   166,   226,   224,   364,     1,    96,   214,   218,
     368,   369,   370,   371,   372,   121,   121,   121,   223,   106,
     106,   206,   106,   106,   233,   233,   233,   106,   106,   106,
     206,   206,   223,   223,   226,   226,   226,   323,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     224,   306,   223,   226,   226,   226,   226,   226,   226,   397,
     226,   226,   226,   226,   226,   226,   224,   388,   226,   226,
     224,   414,   121,   223,   226,   226,   224,   424,   206,   233,
     233,   106,   206,   206,   106,   121,   206,   233,   206,   106,
     106,   233,   106,   206,   206,   206,   233,   106,   106,   233,
     106,   106,   106,   106,   206,   226,   206,   226,   206,   233,
     233,   206,   206,   206,   206,   209,   206,   209,   206,   206,
     121,   233,   206,   206,   233,   233,   206,   206,   223,   223,
     226,   226,   349,   226,   226,   226,   226,   226,   224,   343,
     226,   226,   224,   408,   223,   226,   226,   329,   226,   224,
     333,   121,   121,   223,   223,   226,   226,   300,   226,   226,
     226,   296,   226,   224,   288,   223,   226,   226,   226,   224,
     358,   206,   206,   121,   206,   206,   206,   233,   223,   121,
     206,   121,   106,   106,   121,   121,   121,   121,   121,   121,
     106,   121,   195,   196,   246,   247,   195,   196,   248,   249,
     121,   121,   223,   223,   226,   382,   224,   379,   206,   223,
     225,   121,   223,   223,   226,   373,   226,   224,   369,   223,
     223,   223,   223,   223,   223,   223,   133,   134,   135,   136,
     137,   138,   139,   232,   233,   223,   223,   223,   223,   223,
     223,   223,   223,   106,   106,   233,   226,   106,   106,   233,
     106,   106,   233,   121,   106,   106,   233,   106,   235,   235,
     223,   121,   170,   171,   121,   206,   121,   121,   226,   121,
     121,   106,   121,   121,   121,   223,   121,   121,   223,   223,
     121,   121,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
      48,   156,   157,   158,   159,   161,   162,   164,   165,   167,
     169,   172,   175,   176,   177,   179,   184,   188,   189,   190,
     198,   203,   479,   480,   223,    48,   156,   157,   158,   159,
     161,   162,   164,   165,   167,   169,   172,   175,   176,   177,
     179,   184,   188,   189,   190,   198,   203,   475,   476,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   121,
     206,   226,   121,   106,   121,   121,   121,   223,   121,   121,
     223,   121,   121,   226,   106,   336,   337,   223,   223,   223,
     121,   206,   226,   121,   121,   121,   226,   121,   223,   121,
     121,   121,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   227,   223,   227,   223,   223,   121,
     226,   223,   223,     1,    96,   187,   214,   277,   278,   279,
     280,   281,   223,   121,   226,   121,   223,   232,   232,   232,
     232,   232,   232,   232,   223,   223,   223,    50,   122,   324,
     325,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,     9,    10,    11,   234,   235,   223,   223,   223,   223,
     223,   223,   223,   223,   223,     8,   191,   398,   399,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     227,   223,   227,   223,   223,    13,    33,    42,    69,    97,
      98,   105,   130,   146,   205,   350,   351,   223,   223,   223,
     223,   223,   223,   223,   223,   223,    48,   181,   191,   330,
     331,   213,   227,   335,   223,   223,     4,    18,    25,    39,
      66,    68,    94,   126,   128,   147,   163,   168,   172,   177,
     180,   185,   199,   204,   215,   222,   301,   302,   223,   223,
     223,    48,   156,   157,   158,   159,   161,   162,   164,   165,
     167,   169,   172,   175,   176,   177,   179,   184,   188,   189,
     190,   198,   203,   297,   298,   223,   223,   223,   223,   247,
     249,   223,    68,   129,   155,   163,   172,   199,   201,   202,
     215,   222,   383,   384,   223,   226,   226,   282,   224,   278,
     223,    68,   129,   155,   163,   172,   199,   201,   202,   215,
     222,   374,   375,   223,   223,   227,   234,   234,   234,   223,
     227,   480,   476,   223,   227,   223,   227,   106,   337,   223,
     228,   228,   228,   223,   227,   223,   227,   223,   227,   121,
     200,   235,   226,   223,   223,   227,   325,   399,   351,   331,
     127,   127,   127,   302,   298,   384,   223,   223,   223,    39,
      66,    68,   112,   162,   163,   218,   283,   284,   375,   223,
     227,   284
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
#line 393 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 407 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 415 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 419 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 423 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 428 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 431 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 478 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 484 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1787 of yacc.c  */
#line 493 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 499 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 507 "conf_parser.y"
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
#line 549 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  BIO *file = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

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
#endif
}
    break;

  case 83:
/* Line 1787 of yacc.c  */
#line 608 "conf_parser.y"
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
#line 636 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1787 of yacc.c  */
#line 644 "conf_parser.y"
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
#line 659 "conf_parser.y"
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
#line 674 "conf_parser.y"
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
#line 683 "conf_parser.y"
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
#line 697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 706 "conf_parser.y"
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
#line 734 "conf_parser.y"
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
#line 764 "conf_parser.y"
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
#line 789 "conf_parser.y"
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
#line 811 "conf_parser.y"
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
#line 833 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 894 "conf_parser.y"
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
#line 910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 918 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 921 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1787 of yacc.c  */
#line 941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1787 of yacc.c  */
#line 967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 136:
/* Line 1787 of yacc.c  */
#line 974 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

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
#line 1049 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 149:
/* Line 1787 of yacc.c  */
#line 1055 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 150:
/* Line 1787 of yacc.c  */
#line 1061 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 151:
/* Line 1787 of yacc.c  */
#line 1067 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1078 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1090 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1113 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1177 "conf_parser.y"
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
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1292 "conf_parser.y"
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

  case 208:
/* Line 1787 of yacc.c  */
#line 1304 "conf_parser.y"
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

  case 228:
/* Line 1787 of yacc.c  */
#line 1370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1787 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 237:
/* Line 1787 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
/* Line 1787 of yacc.c  */
#line 1431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1443 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1474 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1494 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1500 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1504 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 1508 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1516 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1521 "conf_parser.y"
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

  case 270:
/* Line 1787 of yacc.c  */
#line 1535 "conf_parser.y"
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

  case 271:
/* Line 1787 of yacc.c  */
#line 1555 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1561 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1570 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1574 "conf_parser.y"
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
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1617 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1623 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 288:
/* Line 1787 of yacc.c  */
#line 1629 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 289:
/* Line 1787 of yacc.c  */
#line 1635 "conf_parser.y"
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

  case 290:
/* Line 1787 of yacc.c  */
#line 1646 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1653 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 295:
/* Line 1787 of yacc.c  */
#line 1657 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 296:
/* Line 1787 of yacc.c  */
#line 1661 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1665 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1669 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1673 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1681 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1685 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 303:
/* Line 1787 of yacc.c  */
#line 1689 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 1695 "conf_parser.y"
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

  case 305:
/* Line 1787 of yacc.c  */
#line 1709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 1718 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1731 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1738 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1749 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1755 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1761 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (valid_servname(yylval.string))
  {
    struct MaskItem *conf = conf_make(CONF_SERVICE);
    conf->name = xstrdup(yylval.string);
  }
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1791 "conf_parser.y"
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

  case 325:
/* Line 1787 of yacc.c  */
#line 1802 "conf_parser.y"
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

  case 332:
/* Line 1787 of yacc.c  */
#line 1819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1825 "conf_parser.y"
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

  case 334:
/* Line 1787 of yacc.c  */
#line 1844 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1863 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 1879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 1887 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 1896 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 1905 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 363:
/* Line 1787 of yacc.c  */
#line 1945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 364:
/* Line 1787 of yacc.c  */
#line 1949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 1957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 1961 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 1965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 1969 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 1978 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 1986 "conf_parser.y"
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

  case 388:
/* Line 1787 of yacc.c  */
#line 2052 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 389:
/* Line 1787 of yacc.c  */
#line 2058 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 390:
/* Line 1787 of yacc.c  */
#line 2064 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2070 "conf_parser.y"
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

  case 392:
/* Line 1787 of yacc.c  */
#line 2083 "conf_parser.y"
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

  case 393:
/* Line 1787 of yacc.c  */
#line 2096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 394:
/* Line 1787 of yacc.c  */
#line 2102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 395:
/* Line 1787 of yacc.c  */
#line 2106 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 396:
/* Line 1787 of yacc.c  */
#line 2114 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2120 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2130 "conf_parser.y"
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

  case 403:
/* Line 1787 of yacc.c  */
#line 2141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 2159 "conf_parser.y"
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

  case 407:
/* Line 1787 of yacc.c  */
#line 2174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2178 "conf_parser.y"
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

  case 414:
/* Line 1787 of yacc.c  */
#line 2203 "conf_parser.y"
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
#line 2223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2236 "conf_parser.y"
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
#line 2262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 424:
/* Line 1787 of yacc.c  */
#line 2268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2282 "conf_parser.y"
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
#line 2299 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2303 "conf_parser.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 2325 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 2331 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2375 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2380 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2386 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2392 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2398 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2403 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2408 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2413 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2418 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2423 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2428 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2433 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2443 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2448 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2453 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2458 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2463 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2468 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2474 "conf_parser.y"
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

  case 512:
/* Line 1787 of yacc.c  */
#line 2485 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2490 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2495 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2500 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2505 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2510 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2513 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2518 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2521 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2526 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2531 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2536 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2541 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2546 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2551 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2556 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2561 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2566 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2571 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2576 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2581 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2623 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2626 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2641 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2647 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2677 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2754 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2845 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2850 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 2875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 634:
/* Line 1787 of yacc.c  */
#line 2887 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
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

  case 636:
/* Line 1787 of yacc.c  */
#line 2910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6750 "conf_parser.c"
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


