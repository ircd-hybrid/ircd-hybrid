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
     T_WALLOPS = 461,
     T_WEBIRC = 462,
     T_RESTART = 463,
     T_SERVICE = 464,
     T_SERVICES_NAME = 465,
     THROTTLE_TIME = 466,
     TRUE_NO_OPER_FLOOD = 467,
     UNKLINE = 468,
     USER = 469,
     USE_EGD = 470,
     USE_LOGGING = 471,
     VHOST = 472,
     VHOST6 = 473,
     XLINE = 474,
     WARN_NO_NLINE = 475,
     T_SIZE = 476,
     T_FILE = 477
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
#define T_WALLOPS 461
#define T_WEBIRC 462
#define T_RESTART 463
#define T_SERVICE 464
#define T_SERVICES_NAME 465
#define THROTTLE_TIME 466
#define TRUE_NO_OPER_FLOOD 467
#define UNKLINE 468
#define USER 469
#define USE_EGD 470
#define USE_LOGGING 471
#define VHOST 472
#define VHOST6 473
#define XLINE 474
#define WARN_NO_NLINE 475
#define T_SIZE 476
#define T_FILE 477



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
#define YYLAST   1213

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
       1,   224,    -1,    -1,   233,    -1,   105,   232,    -1,   105,
     139,   232,    -1,   105,   140,   232,    -1,   105,   141,   232,
      -1,   105,   142,   232,    -1,   105,   143,   232,    -1,   105,
     144,   232,    -1,   105,   145,   232,    -1,    -1,   235,    -1,
     105,   234,    -1,   105,     9,   234,    -1,   105,    10,   234,
      -1,   105,    11,   234,    -1,    95,   225,   237,   224,   223,
      -1,   237,   238,    -1,   238,    -1,   239,    -1,   240,    -1,
       1,   223,    -1,    94,   226,   122,   223,    -1,   118,   226,
     122,   223,    -1,   149,   225,   242,   224,   223,    -1,   242,
     243,    -1,   243,    -1,   254,    -1,   259,    -1,   264,    -1,
     256,    -1,   257,    -1,   258,    -1,   261,    -1,   262,    -1,
     263,    -1,   252,    -1,   251,    -1,   260,    -1,   255,    -1,
     250,    -1,   244,    -1,   245,    -1,   253,    -1,     1,   223,
      -1,   133,   226,   246,   223,    -1,   134,   226,   248,   223,
      -1,   246,   227,   247,    -1,   247,    -1,   135,    -1,   136,
      -1,   248,   227,   249,    -1,   249,    -1,   135,    -1,   136,
      -1,   131,   226,   122,   223,    -1,   129,   226,   122,   223,
      -1,   132,   226,   122,   223,    -1,   175,   226,   122,   223,
      -1,    96,   226,   122,   223,    -1,   151,   226,   122,   223,
      -1,    24,   226,   122,   223,    -1,    99,   226,   122,   223,
      -1,    98,   226,   122,   223,    -1,   217,   226,   122,   223,
      -1,   218,   226,   122,   223,    -1,   186,   226,   105,   223,
      -1,    82,   226,   105,   223,    -1,    86,   226,   105,   223,
      -1,    58,   226,   164,   223,    -1,     4,   225,   266,   224,
     223,    -1,   266,   267,    -1,   267,    -1,   268,    -1,   270,
      -1,   269,    -1,     1,   223,    -1,    96,   226,   122,   223,
      -1,    31,   226,   122,   223,    -1,    24,   226,   122,   223,
      -1,    72,   225,   272,   224,   223,    -1,   272,   273,    -1,
     273,    -1,   274,    -1,   275,    -1,     1,   223,    -1,   216,
     226,   164,   223,    -1,    -1,   276,   222,   225,   277,   224,
     223,    -1,   277,   278,    -1,   278,    -1,   279,    -1,   281,
      -1,   280,    -1,     1,   223,    -1,    96,   226,   122,   223,
      -1,   221,   226,   235,   223,    -1,   221,   226,   201,   223,
      -1,    -1,   155,   282,   226,   283,   223,    -1,   283,   227,
     284,    -1,   284,    -1,   214,    -1,   108,    -1,    40,    -1,
     178,    -1,    65,    -1,    63,    -1,   177,    -1,    -1,   108,
     286,   225,   287,   224,   223,    -1,   287,   288,    -1,   288,
      -1,   289,    -1,   290,    -1,   291,    -1,   295,    -1,   294,
      -1,   292,    -1,   293,    -1,   299,    -1,     1,   223,    -1,
      96,   226,   122,   223,    -1,   214,   226,   122,   223,    -1,
     117,   226,   122,   223,    -1,    32,   226,   164,   223,    -1,
     130,   226,   122,   223,    -1,    17,   226,   122,   223,    -1,
      -1,   198,   296,   226,   297,   223,    -1,   297,   227,   298,
      -1,   298,    -1,   170,    -1,   173,    -1,   174,    -1,   176,
      -1,   177,    -1,   181,    -1,    51,    -1,   195,    -1,   187,
      -1,   191,    -1,   199,    -1,   196,    -1,   179,    -1,   189,
      -1,   193,    -1,   182,    -1,   205,    -1,   171,    -1,   172,
      -1,   185,    -1,   188,    -1,   180,    -1,    -1,    36,   300,
     226,   301,   223,    -1,   301,   227,   302,    -1,   302,    -1,
      63,   228,   127,    -1,    63,    -1,    18,   228,   127,    -1,
      18,    -1,   150,   228,   127,    -1,   150,    -1,    65,    -1,
     213,    -1,   178,    -1,   200,    -1,   219,    -1,    40,    -1,
      25,    -1,   208,    -1,   126,    -1,     4,    -1,   189,    -1,
     204,    -1,   206,    -1,   185,    -1,   128,    -1,   194,    -1,
      94,    -1,    -1,    17,   304,   225,   305,   224,   223,    -1,
     305,   306,    -1,   306,    -1,   307,    -1,   317,    -1,   318,
      -1,   308,    -1,   319,    -1,   309,    -1,   310,    -1,   311,
      -1,   312,    -1,   313,    -1,   314,    -1,   315,    -1,   316,
      -1,   320,    -1,   321,    -1,   322,    -1,     1,   223,    -1,
      96,   226,   122,   223,    -1,   120,   226,   233,   223,    -1,
     107,   226,   105,   223,    -1,    19,   226,   233,   223,    -1,
      84,   226,   105,   223,    -1,    78,   226,   105,   223,    -1,
      80,   226,   105,   223,    -1,    79,   226,   105,   223,    -1,
     146,   226,   235,   223,    -1,   190,   226,   235,   223,    -1,
      15,   226,   105,   223,    -1,    16,   226,   105,   223,    -1,
     106,   226,   105,   223,    -1,    90,   226,   233,   223,    -1,
      91,   226,   233,   223,    -1,    -1,    36,   323,   226,   324,
     223,    -1,   324,   227,   325,    -1,   325,    -1,    92,    -1,
      93,    -1,    -1,    71,   327,   225,   332,   224,   223,    -1,
      -1,    36,   329,   226,   330,   223,    -1,   330,   227,   331,
      -1,   331,    -1,   197,    -1,    51,    -1,   192,    -1,   332,
     333,    -1,   333,    -1,   334,    -1,   328,    -1,   338,    -1,
     339,    -1,     1,   223,    -1,    -1,   121,   226,   336,   335,
     223,    -1,   336,   227,   337,    -1,   337,    -1,   105,    -1,
     105,   168,   105,    -1,    62,   226,   122,   223,    -1,    57,
     226,   122,   223,    -1,    -1,    48,   341,   225,   342,   224,
     223,    -1,   342,   343,    -1,   343,    -1,   344,    -1,   345,
      -1,   346,    -1,   348,    -1,   352,    -1,   353,    -1,   354,
      -1,   347,    -1,     1,   223,    -1,   214,   226,   122,   223,
      -1,   117,   226,   122,   223,    -1,    17,   226,   122,   223,
      -1,    32,   226,   164,   223,    -1,    -1,    36,   349,   226,
     350,   223,    -1,   350,   227,   351,    -1,   351,    -1,   158,
      -1,    33,    -1,    66,    -1,    49,    -1,    13,    -1,   104,
      -1,    43,    -1,   138,    -1,   207,    -1,    97,    -1,   157,
     226,   122,   223,    -1,   125,   226,   122,   223,    -1,   124,
     226,   105,   223,    -1,    -1,   137,   356,   225,   357,   224,
     223,    -1,   357,   358,    -1,   358,    -1,   359,    -1,   360,
      -1,   361,    -1,     1,   223,    -1,    73,   226,   122,   223,
      -1,   123,   226,   122,   223,    -1,    34,   226,   122,   223,
      -1,   209,   225,   363,   224,   223,    -1,   363,   364,    -1,
     364,    -1,   365,    -1,     1,    -1,    96,   226,   122,   223,
      -1,    -1,   153,   367,   225,   368,   224,   223,    -1,   368,
     369,    -1,   369,    -1,   370,    -1,   371,    -1,   372,    -1,
       1,   223,    -1,    96,   226,   122,   223,    -1,   214,   226,
     122,   223,    -1,    -1,   155,   373,   226,   374,   223,    -1,
     374,   227,   375,    -1,   375,    -1,    65,    -1,   213,    -1,
     178,    -1,   200,    -1,   219,    -1,   203,    -1,   137,    -1,
     202,    -1,   185,    -1,   169,    -1,    -1,   154,   377,   225,
     378,   224,   223,    -1,   378,   379,    -1,   379,    -1,   380,
      -1,   381,    -1,     1,   223,    -1,    96,   226,   122,   223,
      -1,    -1,   155,   382,   226,   383,   223,    -1,   383,   227,
     384,    -1,   384,    -1,    65,    -1,   213,    -1,   178,    -1,
     200,    -1,   219,    -1,   203,    -1,   137,    -1,   202,    -1,
     185,    -1,   169,    -1,    -1,    18,   386,   225,   387,   224,
     223,    -1,   387,   388,    -1,   388,    -1,   389,    -1,   390,
      -1,   391,    -1,   392,    -1,   393,    -1,   395,    -1,   394,
      -1,   404,    -1,   396,    -1,   401,    -1,   402,    -1,   403,
      -1,   400,    -1,     1,   223,    -1,    96,   226,   122,   223,
      -1,    57,   226,   122,   223,    -1,   217,   226,   122,   223,
      -1,   147,   226,   122,   223,    -1,     3,   226,   122,   223,
      -1,   121,   226,   105,   223,    -1,     5,   226,   183,   223,
      -1,     5,   226,   184,   223,    -1,    -1,    36,   397,   226,
     398,   223,    -1,   398,   227,   399,    -1,   399,    -1,     8,
      -1,   197,    -1,    32,   226,   164,   223,    -1,    59,   226,
     122,   223,    -1,    69,   226,   122,   223,    -1,    17,   226,
     122,   223,    -1,   175,   226,   122,   223,    -1,    -1,    63,
     406,   225,   407,   224,   223,    -1,   407,   408,    -1,   408,
      -1,   409,    -1,   410,    -1,     1,    -1,   214,   226,   122,
     223,    -1,   123,   226,   122,   223,    -1,    -1,    23,   412,
     225,   413,   224,   223,    -1,   413,   414,    -1,   414,    -1,
     415,    -1,   416,    -1,     1,    -1,    62,   226,   122,   223,
      -1,   123,   226,   122,   223,    -1,    34,   225,   418,   224,
     223,    -1,   418,   419,    -1,   419,    -1,   420,    -1,     1,
      -1,    62,   226,   122,   223,    -1,    -1,    38,   422,   225,
     423,   224,   223,    -1,   423,   424,    -1,   424,    -1,   425,
      -1,   426,    -1,     1,    -1,    96,   226,   122,   223,    -1,
     123,   226,   122,   223,    -1,    39,   225,   428,   224,   223,
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
     469,    -1,     1,    -1,    87,   226,   105,   223,    -1,    42,
     226,   164,   223,    -1,    41,   226,   233,   223,    -1,    44,
     226,   233,   223,    -1,    45,   226,   105,   223,    -1,    46,
     226,   105,   223,    -1,   152,   226,   164,   223,    -1,    64,
     226,   233,   223,    -1,    56,   226,   164,   223,    -1,    60,
     226,   164,   223,    -1,    28,   226,   164,   223,    -1,    35,
     226,   164,   223,    -1,     6,   226,   164,   223,    -1,    83,
     226,   233,   223,    -1,    81,   226,   105,   223,    -1,    74,
     226,   105,   223,    -1,     7,   226,   233,   223,    -1,   167,
     226,   233,   223,    -1,   166,   226,   233,   223,    -1,    50,
     226,   105,   223,    -1,    61,   226,   164,   223,    -1,   220,
     226,   164,   223,    -1,   159,   226,   164,   223,    -1,   162,
     226,   164,   223,    -1,   163,   226,   164,   223,    -1,   161,
     226,   164,   223,    -1,   161,   226,   165,   223,    -1,   160,
     226,   164,   223,    -1,   160,   226,   165,   223,    -1,   115,
     226,   233,   223,    -1,    12,   226,   233,   223,    -1,   109,
     226,   164,   223,    -1,   116,   226,   233,   223,    -1,   156,
     226,   164,   223,    -1,   103,   226,   164,   223,    -1,   212,
     226,   164,   223,    -1,   111,   226,   164,   223,    -1,    29,
     226,   105,   223,    -1,    85,   226,   105,   223,    -1,   215,
     226,   164,   223,    -1,    30,   226,   122,   223,    -1,   210,
     226,   122,   223,    -1,   119,   226,   164,   223,    -1,    26,
     226,   164,   223,    -1,   211,   226,   233,   223,    -1,    -1,
     112,   474,   226,   475,   223,    -1,   475,   227,   476,    -1,
     476,    -1,   170,    -1,   173,    -1,   174,    -1,   176,    -1,
     177,    -1,   181,    -1,    51,    -1,   195,    -1,   187,    -1,
     191,    -1,   199,    -1,   196,    -1,   179,    -1,   189,    -1,
     193,    -1,   182,    -1,   205,    -1,   171,    -1,   172,    -1,
     185,    -1,   188,    -1,   180,    -1,    -1,   110,   478,   226,
     479,   223,    -1,   479,   227,   480,    -1,   480,    -1,   170,
      -1,   173,    -1,   174,    -1,   176,    -1,   177,    -1,   181,
      -1,   195,    -1,    51,    -1,   187,    -1,   191,    -1,   199,
      -1,   196,    -1,   179,    -1,   189,    -1,   193,    -1,   182,
      -1,   205,    -1,   171,    -1,   172,    -1,   185,    -1,   188,
      -1,   180,    -1,    88,   226,   105,   223,    -1,    89,   226,
     105,   223,    -1,    20,   226,   105,   223,    -1,    14,   225,
     485,   224,   223,    -1,   485,   486,    -1,   486,    -1,   492,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    -1,   493,
      -1,   494,    -1,   495,    -1,   496,    -1,   497,    -1,   498,
      -1,   487,    -1,     1,    -1,    27,   226,   164,   223,    -1,
      67,   226,   233,   223,    -1,    68,   226,   233,   223,    -1,
      77,   226,   105,   223,    -1,    76,   226,   105,   223,    -1,
      75,   226,   105,   223,    -1,    22,   226,   105,   223,    -1,
      21,   226,   105,   223,    -1,   101,   226,   164,   223,    -1,
     102,   226,   164,   223,    -1,   113,   226,   105,   223,    -1,
     114,   226,   233,   223,    -1,   148,   225,   500,   224,   223,
      -1,   500,   501,    -1,   501,    -1,   502,    -1,   503,    -1,
     504,    -1,   506,    -1,   507,    -1,   505,    -1,   508,    -1,
       1,    -1,    37,   226,   164,   223,    -1,    54,   226,   164,
     223,    -1,    55,   226,   164,   223,    -1,    52,   226,   122,
     223,    -1,    70,   226,   233,   223,    -1,    51,   226,   164,
     223,    -1,    53,   226,   164,   223,    -1
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
  "T_WALLOPS", "T_WEBIRC", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE", "USER", "USE_EGD",
  "USE_LOGGING", "VHOST", "VHOST6", "XLINE", "WARN_NO_NLINE", "T_SIZE",
  "T_FILE", "';'", "'}'", "'{'", "'='", "','", "':'", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
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
     431,     0,   273,   407,   249,     0,     0,   135,   307,     0,
       0,   324,   348,     0,     3,    23,    11,     4,     5,     6,
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
       0,   563,     0,   537,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   442,   489,   483,   484,   485,   486,   487,   482,
     453,   443,   444,   477,   445,   446,   447,   448,   449,   450,
     451,   452,   479,   454,   455,   488,   457,   462,   458,   460,
     459,   472,   473,   461,   463,   464,   465,   466,   456,   468,
     469,   470,   490,   480,   481,   478,   471,   467,   475,   476,
     474,     0,     0,     0,     0,     0,     0,   108,   109,   110,
       0,     0,     0,     0,     0,    44,    45,    46,     0,     0,
     630,     0,     0,     0,     0,     0,     0,     0,     0,   622,
     623,   624,   625,   628,   626,   627,   629,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    67,    68,    66,
      63,    62,    69,    53,    65,    56,    57,    58,    54,    64,
      59,    60,    61,    55,     0,     0,   322,     0,     0,   320,
     321,   102,     0,     0,     0,     0,    97,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     593,     0,     0,     0,     0,   243,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   210,
     211,   214,   216,   217,   218,   219,   220,   221,   222,   223,
     212,   213,   215,   224,   225,   226,     0,     0,     0,     0,
       0,   396,     0,     0,     0,     0,     0,     0,     0,     0,
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
     283,   413,     0,     0,     0,   410,   411,   412,     0,   251,
       0,     0,     0,   261,     0,   259,   260,   262,   263,   111,
       0,     0,   107,     0,    47,     0,     0,     0,    43,     0,
       0,     0,   180,     0,     0,     0,   154,     0,     0,   138,
     139,   140,   141,   144,   145,   143,   142,   146,     0,     0,
       0,     0,     0,   310,   311,   312,   313,     0,     0,     0,
       0,     0,     0,     0,     0,   621,    70,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    51,     0,     0,   334,     0,
       0,   327,   328,   329,   330,     0,     0,   356,     0,   351,
     352,   353,     0,     0,   319,     0,     0,     0,    96,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
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
     258,     0,   106,     0,     0,     0,    42,   147,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   137,   314,     0,
       0,     0,     0,   309,     0,     0,     0,     0,     0,     0,
       0,   620,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   331,     0,     0,     0,
       0,   326,   354,     0,     0,     0,   350,     0,   318,   105,
     104,   103,   615,   614,   608,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   609,   610,   613,   612,   611,   616,
     617,   618,   619,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
     208,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   371,     0,     0,   417,   430,
       0,     0,   432,   504,   508,   522,   591,   535,   502,   529,
     532,   503,   494,   493,   495,   496,   497,   511,   500,   501,
     512,   499,   507,   506,   505,   530,   492,   589,   590,   526,
     523,   574,   567,   584,   585,   568,   569,   570,   571,   579,
     588,   572,   582,   586,   575,   587,   580,   576,   581,   573,
     578,   577,   583,     0,   566,   528,   547,   541,   558,   559,
     542,   543,   544,   545,   553,   562,   546,   556,   560,   549,
     561,   554,   550,   555,   548,   552,   551,   557,     0,   540,
     521,   524,   534,   498,   525,   514,   519,   520,   517,   518,
     515,   516,   510,   509,   533,   536,   527,   531,   513,     0,
       0,     0,     0,     0,     0,     0,     0,   274,     0,     0,
     408,     0,     0,     0,   269,   265,   268,   250,   112,     0,
       0,   124,     0,     0,   116,   117,   119,   118,    48,    49,
       0,     0,     0,     0,     0,     0,     0,     0,   136,     0,
       0,     0,   308,   631,   636,   634,   637,   632,   633,   635,
      87,    95,    93,    94,    85,    89,    88,    82,    81,    83,
      71,     0,    72,     0,    86,    84,    92,    90,    91,     0,
       0,     0,   325,     0,     0,   349,   323,    29,    30,    31,
      32,    33,    34,    35,   238,   239,   231,   247,   248,     0,
     246,   233,   235,   234,   232,   241,   242,   228,   240,   230,
     229,    36,    36,    36,    38,    37,   236,   237,   392,   394,
     395,   405,   402,   400,   401,     0,   399,   389,   403,   404,
     388,   393,   391,   406,   390,   423,   424,   438,   439,   564,
       0,   538,     0,   288,   289,   298,   295,   300,   297,   296,
     303,   299,   301,   294,   302,     0,   293,   287,   306,   305,
     304,   286,   415,   414,   256,   257,   255,     0,   254,   272,
     271,     0,     0,     0,   120,     0,     0,     0,     0,   115,
     153,   151,   199,   187,   196,   195,   185,   190,   206,   198,
     204,   189,   192,   203,   200,   205,   193,   201,   202,   197,
     191,   194,     0,   183,   148,   150,   152,   164,   158,   175,
     176,   159,   160,   161,   162,   170,   179,   163,   173,   177,
     166,   178,   171,   167,   172,   165,   169,   168,   174,     0,
     157,   149,   317,   315,   316,    73,    77,   332,   338,   344,
     347,   340,   346,   341,   345,   343,   339,   342,     0,   337,
     333,   355,   360,   366,   369,   362,   368,   363,   367,   365,
     361,   364,     0,   359,   244,     0,    39,    40,    41,   397,
       0,   565,   539,   291,     0,   252,     0,   270,   267,   266,
       0,     0,     0,     0,   114,     0,     0,     0,   181,     0,
     155,     0,   335,     0,   357,     0,   245,   398,   292,   253,
     121,   130,   133,   132,   129,   134,   131,   128,     0,   127,
     123,   122,   186,   184,   188,   182,   156,   336,   358,   125,
       0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   782,   783,  1034,  1035,    25,   224,   225,
     226,   227,    26,   265,   266,   267,   268,   744,   745,   748,
     749,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   281,   282,   283,    27,    71,    72,    73,
      74,    75,    28,   216,   217,   218,   219,   220,   953,   954,
     955,   956,   957,  1096,  1228,  1229,    29,    60,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   714,  1149,  1150,
     507,   710,  1122,  1123,    30,    49,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   587,  1019,  1020,    31,    57,   473,
     695,  1087,  1088,   474,   475,   476,  1093,   945,   946,   477,
     478,    32,    55,   451,   452,   453,   454,   455,   456,   457,
     682,  1075,  1076,   458,   459,   460,    33,    61,   512,   513,
     514,   515,   516,    34,   288,   289,   290,    35,    64,   550,
     551,   552,   553,   554,   758,  1168,  1169,    36,    65,   558,
     559,   560,   561,   764,  1182,  1183,    37,    50,   360,   361,
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
#define YYPACT_NINF -933
static const yytype_int16 yypact[] =
{
    -933,   657,  -933,  -183,  -218,  -213,  -933,  -933,  -933,  -202,
    -933,  -197,  -933,  -933,  -933,  -194,  -191,  -933,  -933,  -161,
    -159,  -933,  -933,  -142,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,   330,   900,  -134,
    -114,  -106,    19,  -104,   409,   -95,   -92,   -84,    46,     4,
     -81,   -75,   318,   376,   -60,   -46,    75,  -137,   -19,   -14,
      -7,    24,  -933,  -933,  -933,  -933,  -933,    40,    41,    60,
      74,    81,    89,    90,    92,    94,    96,   100,   104,   290,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,   666,   531,    28,  -933,   112,    16,  -933,
    -933,    78,  -933,   113,   116,   118,   119,   122,   124,   125,
     127,   130,   133,   149,   152,   153,   154,   157,   158,   160,
     161,   163,   164,   167,   168,   169,   170,   171,   175,   179,
     181,  -933,   182,  -933,   183,   185,   186,   187,   191,   192,
     194,   196,   197,   198,   199,   201,   202,   204,   205,   206,
     207,   117,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,   332,    49,    35,   120,   210,    23,  -933,  -933,  -933,
      76,   217,   215,   216,    37,  -933,  -933,  -933,   289,    34,
    -933,   219,   221,   222,   226,   234,   235,   237,     7,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,   220,   238,   240,
     241,   242,   250,   251,   252,   253,   258,   259,   260,   265,
     267,   269,   274,   275,   276,    84,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,    68,    21,  -933,   278,    36,  -933,
    -933,  -933,   360,   384,   389,   292,  -933,   208,   293,   349,
     411,   411,   412,   417,   421,   365,   366,   426,   411,   310,
    -933,   312,   313,   314,   315,  -933,   316,   317,   319,   321,
     323,   324,   338,   340,   347,   348,   351,   352,   256,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,   356,   354,   355,   357,
     359,  -933,   361,   363,   369,   370,   371,   372,   373,   377,
      13,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,   378,   379,    25,  -933,
    -933,  -933,   416,   368,  -933,  -933,   381,   383,    72,  -933,
    -933,  -933,   438,   411,   411,   505,   447,   448,   509,   493,
     453,   411,   454,   411,   523,   525,   526,   468,   469,   470,
     411,   530,   532,   411,   533,   535,   536,   538,   480,   482,
     422,   485,   425,   411,   411,   489,   490,   491,   492,   -71,
     -51,   495,   496,   411,   411,   540,   411,   499,   500,   501,
     443,  -933,   445,   446,   450,  -933,   457,   458,   460,   461,
     462,   257,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,   463,   464,    73,  -933,  -933,  -933,   456,  -933,
     466,   467,   472,  -933,    18,  -933,  -933,  -933,  -933,  -933,
     537,   476,  -933,   475,  -933,   551,   581,   484,  -933,   486,
     488,   498,  -933,   504,   507,   508,  -933,   510,    10,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   487,   511,
     514,   515,    31,  -933,  -933,  -933,  -933,   548,   552,   593,
     553,   554,   557,   411,   503,  -933,  -933,   613,   578,   638,
     642,   627,   629,   631,   633,   636,   637,    86,   115,   639,
     644,   655,   645,   646,   541,  -933,   555,   545,  -933,   549,
      32,  -933,  -933,  -933,  -933,   556,   550,  -933,    14,  -933,
    -933,  -933,   652,   558,  -933,   559,   560,   561,  -933,   566,
     567,   568,   791,   569,   570,   572,   574,   576,   577,   579,
     580,   584,  -933,  -933,   672,   691,   411,   575,   703,   704,
     713,   716,   411,   411,   705,   721,   724,   411,   728,   728,
     612,  -933,  -933,   715,    69,   719,   676,   617,   722,   723,
     725,   727,   741,   729,   730,   731,   632,  -933,   732,   735,
     640,  -933,   648,  -933,   750,   752,   659,  -933,   662,   663,
     679,   681,   685,   687,   689,   692,   693,   695,   696,   697,
     701,   702,   706,   714,   717,   720,   726,   733,   734,   736,
     737,   738,   739,   740,   742,   743,   643,   746,   688,   747,
     748,   749,   751,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   765,   766,   767,   768,   769,  -933,  -933,
     804,   686,   654,   806,   773,   816,   817,   819,   770,  -933,
     820,   822,   771,  -933,  -933,   772,   823,   824,   842,   774,
    -933,   776,  -933,    88,   777,   780,  -933,  -933,   826,   786,
     778,   829,   830,   831,   779,   832,   783,  -933,  -933,   833,
     836,   851,   784,  -933,   785,   787,   788,   789,   792,   793,
     794,  -933,   795,   796,   797,   798,   799,   800,   801,   802,
     803,   805,  -933,  -933,  -214,  -933,  -933,  -933,  -184,  -933,
     807,   808,   809,   810,   811,  -933,  -933,   873,   812,   874,
     813,  -933,  -933,   887,   814,   818,  -933,   821,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,   411,   411,   411,   411,   411,
     411,   411,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,   825,   827,   828,   172,   834,   835,   837,
     838,   839,   840,   841,   843,   844,   845,   294,   846,   847,
    -933,   848,   849,   850,   852,   853,    -4,   854,   855,   856,
     857,   858,   859,   860,   861,  -933,   862,   863,  -933,  -933,
     864,   865,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -171,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -170,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   866,
     867,   573,   868,   869,   870,   871,   872,  -933,   875,   876,
    -933,     0,   877,   878,   879,   815,  -933,  -933,  -933,   880,
     881,  -933,   882,    20,  -933,  -933,  -933,  -933,  -933,  -933,
     883,   886,   519,   888,   889,   890,   718,   891,  -933,   892,
     893,   894,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,    86,  -933,   115,  -933,  -933,  -933,  -933,  -933,   895,
     423,   896,  -933,   897,   585,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -160,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,   728,   728,   728,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -139,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
     643,  -933,   688,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,   -74,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,   -38,  -933,  -933,
    -933,   922,   842,   898,  -933,   907,   884,   -99,   899,  -933,
    -933,  -933,  -933,   901,  -933,  -933,   902,  -933,  -933,  -933,
    -933,   903,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,   -33,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   -24,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   -13,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,    58,  -933,  -933,   172,  -933,  -933,  -933,  -933,
      -4,  -933,  -933,  -933,   573,  -933,     0,  -933,  -933,  -933,
     904,   146,   905,   909,  -933,   908,   910,   912,  -933,   519,
    -933,   718,  -933,   423,  -933,   585,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,    87,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
     146,  -933
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -933,  -933,  -933,  -223,  -298,  -932,  -598,  -933,  -933,   911,
    -933,  -933,  -933,  -933,   699,  -933,  -933,  -933,    52,  -933,
      53,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   974,  -933,
    -933,  -933,  -933,  -933,   917,  -933,  -933,  -933,  -933,    99,
    -933,  -933,  -933,  -933,  -933,  -187,  -933,  -933,  -933,   598,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -162,
    -933,  -933,  -933,  -155,  -933,  -933,  -933,   885,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -130,  -933,  -933,  -933,
    -933,  -933,  -140,  -933,   591,  -933,  -933,  -933,   -18,  -933,
    -933,  -933,  -933,  -933,   608,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,   -97,  -933,  -933,  -933,  -933,  -933,  -933,   590,
    -933,  -933,  -933,  -933,  -933,   906,  -933,  -933,  -933,  -933,
     586,  -933,  -933,  -933,  -933,  -933,  -109,  -933,  -933,  -933,
     547,  -933,  -933,  -933,  -933,   -91,  -933,  -933,  -933,   781,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
     -67,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,   661,
    -933,  -933,  -933,  -933,  -933,   775,  -933,  -933,  -933,  -933,
    1018,  -933,  -933,  -933,  -933,   754,  -933,  -933,  -933,  -933,
     973,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,    77,  -933,  -933,
    -933,    80,  -933,  -933,  -933,  -933,  -933,  1048,  -933,  -933,
    -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,  -933,
    -933,  -933,   913,  -933,  -933,  -933,  -933,  -933,  -933,  -933
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     808,   809,   573,   574,  1043,   221,   807,    47,   230,   990,
     581,   489,    48,   991,   346,   555,   347,   106,   348,   468,
     106,   949,   555,    52,   214,    67,   375,   490,    54,   375,
     349,    58,   508,   546,    59,   508,   468,   286,   221,   992,
      45,    46,   491,   993,   231,   350,   492,   214,    68,   351,
     461,  1084,  1059,  1061,   469,    69,  1060,  1062,   232,   233,
     234,   235,   236,  1184,    62,   509,    63,  1185,   509,   546,
     352,   469,   353,   385,   461,   470,   286,   237,   107,   385,
     471,   107,   354,    66,  1189,   247,   291,   376,  1190,   949,
     376,   103,   470,   665,   666,   629,   630,   471,   222,  1186,
    1187,  1188,  1202,   637,   510,   639,   493,   510,   248,   355,
     556,   104,   646,   667,   668,   649,   950,   556,   112,   105,
      70,   111,   223,   113,   114,   659,   660,   494,   547,   115,
     211,   222,   287,   212,   356,   671,   672,   116,   674,   472,
     495,   213,   249,   117,   228,   118,   119,   120,   377,  1193,
     229,   377,   121,  1194,   511,   223,   472,   511,   122,   123,
     357,   124,   125,   126,   547,   284,   250,   127,   386,   557,
     251,   287,   462,   128,   386,   951,   557,   129,   130,   285,
     252,   131,   253,   254,   950,  1195,  1221,   548,   358,  1196,
    1208,   132,  1085,  1044,  1209,   387,   462,  1086,   133,  1210,
     134,   387,   135,  1211,   136,   137,   138,   292,   496,  1222,
    1212,  1223,   293,   255,  1213,   256,   257,   258,   259,   294,
     139,   742,   743,   548,   497,   730,   140,   141,   142,   143,
     359,   524,   144,   145,   716,   260,   146,   616,   765,   215,
     383,   952,   699,   951,  1098,  -113,   549,   481,   295,   620,
     746,   747,   812,   813,  1224,   722,   760,   311,   442,   261,
     563,   487,   215,   463,  1017,  1018,   297,   298,  -113,   147,
     262,   312,   313,   148,   443,   314,   149,   150,   151,   152,
     153,  1214,   549,   154,   155,  1215,   299,   463,   795,   444,
     489,    76,   315,   445,   801,   802,   626,   692,   483,   806,
     300,   263,   264,  1031,  1032,  1033,   490,   301,   544,   952,
    1239,    77,    78,   569,  1240,   302,   303,    79,   304,   230,
     305,   491,   306,  1225,  1226,   492,   307,   156,   157,   158,
     308,    67,   159,   442,   316,   317,   318,   160,   382,   392,
     319,   440,   393,   479,   394,   395,   320,   321,   396,   443,
     397,   398,   322,   399,    68,   231,   400,    80,    81,   401,
    1227,    69,   323,   324,   444,    82,    83,    84,   445,   232,
     233,   234,   235,   236,   446,   402,   325,   247,   403,   404,
     405,   447,   448,   406,   407,   493,   408,   409,   237,   410,
     411,    85,    86,   412,   413,   414,   415,   416,   570,   807,
     248,   417,   326,    87,    88,   418,   494,   419,   421,   423,
     112,   424,   425,   426,   449,   113,   114,   427,   428,   495,
     429,   115,   430,   431,   432,   433,    70,   434,   435,   116,
     436,   437,   438,   439,   249,   117,   480,   118,   119,   120,
     484,   485,   486,   526,   121,   517,   327,   518,   519,   446,
     122,   123,   520,   124,   125,   126,   447,   448,   250,   127,
     521,   522,   251,   523,   527,   128,   528,   529,   530,   129,
     130,   450,   252,   131,   253,   254,   531,   532,   533,   534,
     600,   688,   565,   132,   535,   536,   537,   496,  1158,   449,
     133,   538,   134,   539,   135,   540,   136,   137,   138,  1203,
     541,   542,   543,   497,   562,   255,   566,   256,   257,   258,
     259,   567,   139,   571,   309,   568,   572,   575,   140,   141,
     142,   143,   576,  1102,   144,   145,   577,   260,   146,   578,
     579,   580,   346,   582,   347,   583,   348,  1103,   622,   584,
     585,   586,   588,   589,  1104,   590,   450,   591,   349,   592,
     593,   261,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1105,
    1159,   147,   262,   350,   594,   148,   595,   351,   149,   150,
     151,   152,   153,   596,   597,   154,   155,   598,   599,   602,
     603,   604,  1106,   605,  1107,   606,  1065,   608,   352,   609,
     353,   623,  1160,   263,   264,   610,   611,   612,   613,   614,
     354,  1161,   628,   615,   618,   619,  1066,   624,  1162,   625,
     631,   632,   633,  1108,   634,   635,  1067,   636,   638,   156,
     157,   158,  1068,  1163,   159,  1164,  1165,   355,   640,   160,
     641,   642,   643,   644,   645,   647,  1166,   648,   650,  1069,
     651,   652,  1167,   653,   654,  1109,   655,  1110,   656,   657,
    1172,   658,   356,   661,   662,   663,   664,     2,     3,   669,
     670,     4,   673,   675,   676,   677,   678,   311,   679,  1111,
    1070,     5,   680,   704,     6,     7,   681,  1071,   357,   694,
       8,   312,   313,   683,   684,   314,   685,   686,   687,   690,
     691,     9,   696,   697,   861,    10,    11,  1112,   698,   702,
     703,   701,   315,   705,  1113,    12,   358,   706,  1114,   707,
     718,  1072,   724,  1115,   708,   726,   725,   727,   728,  1116,
      13,   729,  1173,  1117,   709,  1118,   731,  1119,    14,    15,
     711,  1073,  1120,   712,   713,   732,   715,   719,  1121,   886,
     720,   721,   733,   734,   316,   317,   318,   735,   359,   736,
     319,   737,    16,   738,  1174,   739,   320,   321,   740,   741,
     752,   750,   322,  1175,   755,    17,   751,   753,   754,  1127,
    1176,   757,   323,   324,   767,   759,   763,   793,   756,   762,
    1074,   768,   769,   770,   771,  1177,   325,  1178,  1179,   772,
     773,   774,   784,   785,    18,   786,   794,   787,  1180,   788,
     789,   796,   790,   791,  1181,    19,    20,   792,   797,   798,
      21,    22,   326,   862,   863,   864,   865,   866,   799,   867,
     868,   800,   869,   870,   871,   872,   804,   803,   873,   805,
     874,   875,   876,   807,   877,   810,   878,   811,   879,   880,
     815,   814,   881,   816,   817,   818,   821,   819,   882,   820,
     930,   822,   823,   824,   826,   825,   327,   827,   887,   888,
     889,   890,   891,   828,   892,   893,    23,   894,   895,   896,
     897,   829,   830,   898,   831,   899,   900,   901,   933,   902,
     931,   903,   832,   904,   905,   833,   834,   906,  1128,  1129,
    1130,  1131,  1132,   907,  1133,  1134,   572,  1135,  1136,  1137,
    1138,    76,   835,  1139,   836,  1140,  1141,  1142,   837,  1143,
     838,  1144,   839,  1145,  1146,   840,   841,  1147,   842,   843,
     844,    77,    78,  1148,   845,   846,   929,    79,   932,   847,
     775,   776,   777,   778,   779,   780,   781,   848,   934,   935,
     849,   936,   938,   850,   939,   942,   943,   944,   960,   851,
     961,   963,   964,   965,   967,   969,   852,   853,   970,   854,
     855,   856,   857,   858,   545,   859,   860,    80,    81,   885,
     910,   911,   912,   971,   913,    82,    83,    84,   914,   915,
     916,   917,   918,   919,   920,   921,   922,   923,   924,   925,
     926,   927,   928,   937,   940,   999,  1001,   947,   941,   948,
     958,    85,    86,   959,   962,   966,   968,   972,   973,  1003,
     974,   975,   976,    87,    88,   977,   978,   979,   980,   981,
     982,   983,   984,   985,   986,   987,   988,  1197,   989,  1200,
     994,   995,   996,   997,   998,  1232,  1002,  1233,  1000,  1234,
    1004,  1005,  1092,  1155,  1006,   296,  1156,  1091,  1014,  1236,
    1015,  1016,  1099,  1241,  1235,  1216,  1219,  1021,  1022,   689,
    1023,  1024,  1025,  1026,  1027,   700,  1028,  1029,  1030,  1036,
    1037,  1038,  1039,  1040,  1198,  1041,  1042,  1047,  1048,  1049,
    1050,  1051,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  1063,
    1064,  1077,  1078,  1079,  1080,  1081,   717,  1218,  1082,  1083,
    1089,  1090,   723,  1094,  1237,   766,  1100,  1095,  1097,  1101,
    1201,  1124,  1125,  1126,  1151,  1152,  1153,  1154,  1157,  1170,
    1171,  1199,  1204,  1217,  1238,   693,   384,  1220,  1230,  1205,
    1206,  1207,  1231,   482,   441,   488,   761,   310,     0,  1192,
    1191,   617,   627,     0,     0,     0,     0,     0,     0,     0,
       0,   525,     0,   621,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   564,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   601
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-933)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     598,   599,   300,   301,     8,     1,   105,   225,     1,   223,
     308,     1,   225,   227,     1,     1,     3,     1,     5,     1,
       1,     1,     1,   225,     1,     1,     1,    17,   225,     1,
      17,   225,     1,     1,   225,     1,     1,     1,     1,   223,
     223,   224,    32,   227,    37,    32,    36,     1,    24,    36,
       1,    51,   223,   223,    36,    31,   227,   227,    51,    52,
      53,    54,    55,   223,   225,    34,   225,   227,    34,     1,
      57,    36,    59,     1,     1,    57,     1,    70,    62,     1,
      62,    62,    69,   225,   223,     1,   223,    62,   227,     1,
      62,   225,    57,   164,   165,   393,   394,    62,    94,  1031,
    1032,  1033,   201,   401,    73,   403,    96,    73,    24,    96,
      96,   225,   410,   164,   165,   413,    96,    96,     1,   225,
      96,   225,   118,     6,     7,   423,   424,   117,    96,    12,
     225,    94,    96,   225,   121,   433,   434,    20,   436,   121,
     130,   225,    58,    26,   225,    28,    29,    30,   123,   223,
     225,   123,    35,   227,   123,   118,   121,   123,    41,    42,
     147,    44,    45,    46,    96,   225,    82,    50,    96,   155,
      86,    96,   123,    56,    96,   155,   155,    60,    61,   225,
      96,    64,    98,    99,    96,   223,    40,   155,   175,   227,
     223,    74,   192,   197,   227,   123,   123,   197,    81,   223,
      83,   123,    85,   227,    87,    88,    89,   226,   198,    63,
     223,    65,   226,   129,   227,   131,   132,   133,   134,   226,
     103,   135,   136,   155,   214,   523,   109,   110,   111,   112,
     217,   224,   115,   116,   224,   151,   119,   224,   224,   216,
     224,   221,   224,   155,   224,   222,   214,   224,   224,   224,
     135,   136,   183,   184,   108,   224,   224,     1,     1,   175,
     224,   224,   216,   214,    92,    93,   226,   226,   222,   152,
     186,    15,    16,   156,    17,    19,   159,   160,   161,   162,
     163,   223,   214,   166,   167,   227,   226,   214,   586,    32,
       1,     1,    36,    36,   592,   593,   224,   224,   222,   597,
     226,   217,   218,     9,    10,    11,    17,   226,   224,   221,
     223,    21,    22,   105,   227,   226,   226,    27,   226,     1,
     226,    32,   226,   177,   178,    36,   226,   210,   211,   212,
     226,     1,   215,     1,    78,    79,    80,   220,   226,   226,
      84,   224,   226,   223,   226,   226,    90,    91,   226,    17,
     226,   226,    96,   226,    24,    37,   226,    67,    68,   226,
     214,    31,   106,   107,    32,    75,    76,    77,    36,    51,
      52,    53,    54,    55,   117,   226,   120,     1,   226,   226,
     226,   124,   125,   226,   226,    96,   226,   226,    70,   226,
     226,   101,   102,   226,   226,   226,   226,   226,   105,   105,
      24,   226,   146,   113,   114,   226,   117,   226,   226,   226,
       1,   226,   226,   226,   157,     6,     7,   226,   226,   130,
     226,    12,   226,   226,   226,   226,    96,   226,   226,    20,
     226,   226,   226,   226,    58,    26,   226,    28,    29,    30,
     223,   226,   226,   223,    35,   226,   190,   226,   226,   117,
      41,    42,   226,    44,    45,    46,   124,   125,    82,    50,
     226,   226,    86,   226,   226,    56,   226,   226,   226,    60,
      61,   214,    96,    64,    98,    99,   226,   226,   226,   226,
     224,   224,   122,    74,   226,   226,   226,   198,    65,   157,
      81,   226,    83,   226,    85,   226,    87,    88,    89,  1097,
     226,   226,   226,   214,   226,   129,   122,   131,   132,   133,
     134,   122,   103,   164,   224,   223,   105,   105,   109,   110,
     111,   112,   105,     4,   115,   116,   105,   151,   119,   164,
     164,   105,     1,   223,     3,   223,     5,    18,   122,   226,
     226,   226,   226,   226,    25,   226,   214,   226,    17,   226,
     226,   175,   775,   776,   777,   778,   779,   780,   781,    40,
     137,   152,   186,    32,   226,   156,   226,    36,   159,   160,
     161,   162,   163,   226,   226,   166,   167,   226,   226,   223,
     226,   226,    63,   226,    65,   226,    13,   226,    57,   226,
      59,   223,   169,   217,   218,   226,   226,   226,   226,   226,
      69,   178,   164,   226,   226,   226,    33,   226,   185,   226,
     105,   164,   164,    94,   105,   122,    43,   164,   164,   210,
     211,   212,    49,   200,   215,   202,   203,    96,   105,   220,
     105,   105,   164,   164,   164,   105,   213,   105,   105,    66,
     105,   105,   219,   105,   164,   126,   164,   128,   226,   164,
      65,   226,   121,   164,   164,   164,   164,     0,     1,   164,
     164,     4,   122,   164,   164,   164,   223,     1,   223,   150,
      97,    14,   226,   122,    17,    18,   226,   104,   147,   223,
      23,    15,    16,   226,   226,    19,   226,   226,   226,   226,
     226,    34,   226,   226,    51,    38,    39,   178,   226,   223,
     225,   164,    36,   122,   185,    48,   175,   223,   189,   223,
     223,   138,   164,   194,   226,   122,   164,   164,   164,   200,
      63,   164,   137,   204,   226,   206,   223,   208,    71,    72,
     226,   158,   213,   226,   226,   122,   226,   226,   219,    51,
     226,   226,   164,   105,    78,    79,    80,   105,   217,   122,
      84,   122,    95,   122,   169,   122,    90,    91,   122,   122,
     105,   122,    96,   178,   223,   108,   122,   122,   122,    51,
     185,   226,   106,   107,   122,   226,   226,   105,   223,   223,
     207,   223,   223,   223,   223,   200,   120,   202,   203,   223,
     223,   223,   223,   223,   137,   223,   105,   223,   213,   223,
     223,   226,   223,   223,   219,   148,   149,   223,   105,   105,
     153,   154,   146,   170,   171,   172,   173,   174,   105,   176,
     177,   105,   179,   180,   181,   182,   105,   122,   185,   105,
     187,   188,   189,   105,   191,   223,   193,   122,   195,   196,
     164,   122,   199,   226,   122,   122,   105,   122,   205,   122,
     164,   122,   122,   122,   122,   223,   190,   122,   170,   171,
     172,   173,   174,   223,   176,   177,   209,   179,   180,   181,
     182,   223,   122,   185,   122,   187,   188,   189,   105,   191,
     226,   193,   223,   195,   196,   223,   223,   199,   170,   171,
     172,   173,   174,   205,   176,   177,   105,   179,   180,   181,
     182,     1,   223,   185,   223,   187,   188,   189,   223,   191,
     223,   193,   223,   195,   196,   223,   223,   199,   223,   223,
     223,    21,    22,   205,   223,   223,   122,    27,   122,   223,
     139,   140,   141,   142,   143,   144,   145,   223,   122,   122,
     223,   122,   122,   223,   122,   122,   122,   105,   122,   223,
     164,   122,   122,   122,   122,   122,   223,   223,   122,   223,
     223,   223,   223,   223,   265,   223,   223,    67,    68,   223,
     223,   223,   223,   122,   223,    75,    76,    77,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   122,   122,   223,   226,   223,
     223,   101,   102,   223,   226,   226,   223,   223,   223,   122,
     223,   223,   223,   113,   114,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   105,   223,   122,
     223,   223,   223,   223,   223,   127,   223,   127,   226,   127,
     226,   223,   227,   991,   223,    71,   993,   168,   223,  1211,
     223,   223,   953,  1240,  1209,  1185,  1196,   223,   223,   451,
     223,   223,   223,   223,   223,   474,   223,   223,   223,   223,
     223,   223,   223,   223,  1092,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   498,  1194,   223,   223,
     223,   223,   512,   223,  1213,   558,   223,   226,   226,   223,
     226,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,  1190,  1215,   464,   108,   223,   223,   228,
     228,   228,   223,   216,   161,   224,   550,    89,    -1,  1062,
    1060,   360,   388,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   238,    -1,   378,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   328
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   230,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    63,    71,    72,    95,   108,   137,   148,
     149,   153,   154,   209,   231,   236,   241,   265,   271,   285,
     303,   326,   340,   355,   362,   366,   376,   385,   405,   411,
     417,   421,   427,   484,   499,   223,   224,   225,   225,   304,
     386,   412,   225,   422,   225,   341,   406,   327,   225,   225,
     286,   356,   225,   225,   367,   377,   225,     1,    24,    31,
      96,   266,   267,   268,   269,   270,     1,    21,    22,    27,
      67,    68,    75,    76,    77,   101,   102,   113,   114,   485,
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   225,   225,   225,     1,    62,   418,   419,
     420,   225,     1,     6,     7,    12,    20,    26,    28,    29,
      30,    35,    41,    42,    44,    45,    46,    50,    56,    60,
      61,    64,    74,    81,    83,    85,    87,    88,    89,   103,
     109,   110,   111,   112,   115,   116,   119,   152,   156,   159,
     160,   161,   162,   163,   166,   167,   210,   211,   212,   215,
     220,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   477,   481,   482,
     483,   225,   225,   225,     1,   216,   272,   273,   274,   275,
     276,     1,    94,   118,   237,   238,   239,   240,   225,   225,
       1,    37,    51,    52,    53,    54,    55,    70,   500,   501,
     502,   503,   504,   505,   506,   507,   508,     1,    24,    58,
      82,    86,    96,    98,    99,   129,   131,   132,   133,   134,
     151,   175,   186,   217,   218,   242,   243,   244,   245,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   225,   225,     1,    96,   363,   364,
     365,   223,   226,   226,   226,   224,   267,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   224,
     486,     1,    15,    16,    19,    36,    78,    79,    80,    84,
      90,    91,    96,   106,   107,   120,   146,   190,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,   321,   322,     1,     3,     5,    17,
      32,    36,    57,    59,    69,    96,   121,   147,   175,   217,
     387,   388,   389,   390,   391,   392,   393,   394,   395,   396,
     400,   401,   402,   403,   404,     1,    62,   123,   413,   414,
     415,   416,   226,   224,   419,     1,    96,   123,   423,   424,
     425,   426,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     478,   226,   474,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     224,   429,     1,    17,    32,    36,   117,   124,   125,   157,
     214,   342,   343,   344,   345,   346,   347,   348,   352,   353,
     354,     1,   123,   214,   407,   408,   409,   410,     1,    36,
      57,    62,   121,   328,   332,   333,   334,   338,   339,   223,
     226,   224,   273,   222,   223,   226,   226,   224,   238,     1,
      17,    32,    36,    96,   117,   130,   198,   214,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   299,     1,    34,
      73,   123,   357,   358,   359,   360,   361,   226,   226,   226,
     226,   226,   226,   226,   224,   501,   223,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   224,   243,     1,    96,   155,   214,
     368,   369,   370,   371,   372,     1,    96,   155,   378,   379,
     380,   381,   226,   224,   364,   122,   122,   122,   223,   105,
     105,   164,   105,   233,   233,   105,   105,   105,   164,   164,
     105,   233,   223,   223,   226,   226,   226,   323,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     224,   306,   223,   226,   226,   226,   226,   397,   226,   226,
     226,   226,   226,   226,   226,   226,   224,   388,   226,   226,
     224,   414,   122,   223,   226,   226,   224,   424,   164,   233,
     233,   105,   164,   164,   105,   122,   164,   233,   164,   233,
     105,   105,   105,   164,   164,   164,   233,   105,   105,   233,
     105,   105,   105,   105,   164,   164,   226,   164,   226,   233,
     233,   164,   164,   164,   164,   164,   165,   164,   165,   164,
     164,   233,   233,   122,   233,   164,   164,   164,   223,   223,
     226,   226,   349,   226,   226,   226,   226,   226,   224,   343,
     226,   226,   224,   408,   223,   329,   226,   226,   226,   224,
     333,   164,   223,   225,   122,   122,   223,   223,   226,   226,
     300,   226,   226,   226,   296,   226,   224,   288,   223,   226,
     226,   226,   224,   358,   164,   164,   122,   164,   164,   164,
     233,   223,   122,   164,   105,   105,   122,   122,   122,   122,
     122,   122,   135,   136,   246,   247,   135,   136,   248,   249,
     122,   122,   105,   122,   122,   223,   223,   226,   373,   226,
     224,   369,   223,   226,   382,   224,   379,   122,   223,   223,
     223,   223,   223,   223,   223,   139,   140,   141,   142,   143,
     144,   145,   232,   233,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   105,   105,   233,   226,   105,   105,   105,
     105,   233,   233,   122,   105,   105,   233,   105,   235,   235,
     223,   122,   183,   184,   122,   164,   226,   122,   122,   122,
     122,   105,   122,   122,   122,   223,   122,   122,   223,   223,
     122,   122,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,    51,   170,   171,   172,   173,   174,   176,   177,   179,
     180,   181,   182,   185,   187,   188,   189,   191,   193,   195,
     196,   199,   205,   479,   480,   223,    51,   170,   171,   172,
     173,   174,   176,   177,   179,   180,   181,   182,   185,   187,
     188,   189,   191,   193,   195,   196,   199,   205,   475,   476,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   122,
     164,   226,   122,   105,   122,   122,   122,   223,   122,   122,
     223,   226,   122,   122,   105,   336,   337,   223,   223,     1,
      96,   155,   221,   277,   278,   279,   280,   281,   223,   223,
     122,   164,   226,   122,   122,   122,   226,   122,   223,   122,
     122,   122,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   227,   223,   227,   223,   223,   223,   223,   223,   122,
     226,   122,   223,   122,   226,   223,   223,   232,   232,   232,
     232,   232,   232,   232,   223,   223,   223,    92,    93,   324,
     325,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,     9,    10,    11,   234,   235,   223,   223,   223,   223,
     223,   223,   223,     8,   197,   398,   399,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     227,   223,   227,   223,   223,    13,    33,    43,    49,    66,
      97,   104,   138,   158,   207,   350,   351,   223,   223,   223,
     223,   223,   223,   223,    51,   192,   197,   330,   331,   223,
     223,   168,   227,   335,   223,   226,   282,   226,   224,   278,
     223,   223,     4,    18,    25,    40,    63,    65,    94,   126,
     128,   150,   178,   185,   189,   194,   200,   204,   206,   208,
     213,   219,   301,   302,   223,   223,   223,    51,   170,   171,
     172,   173,   174,   176,   177,   179,   180,   181,   182,   185,
     187,   188,   189,   191,   193,   195,   196,   199,   205,   297,
     298,   223,   223,   223,   223,   247,   249,   223,    65,   137,
     169,   178,   185,   200,   202,   203,   213,   219,   374,   375,
     223,   223,    65,   137,   169,   178,   185,   200,   202,   203,
     213,   219,   383,   384,   223,   227,   234,   234,   234,   223,
     227,   480,   476,   223,   227,   223,   227,   105,   337,   223,
     122,   226,   201,   235,   223,   228,   228,   228,   223,   227,
     223,   227,   223,   227,   223,   227,   325,   399,   351,   331,
     223,    40,    63,    65,   108,   177,   178,   214,   283,   284,
     223,   223,   127,   127,   127,   302,   298,   375,   384,   223,
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
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    ServerInfo.network_desc = xstrdup(yylval.string);
  }
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
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    AdminInfo.name = xstrdup(yylval.string);
  }
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 857 "conf_parser.y"
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
#line 866 "conf_parser.y"
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
#line 6752 "conf_parser.c"
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


