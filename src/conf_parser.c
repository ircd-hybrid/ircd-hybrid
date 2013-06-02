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
#line 182 "conf_parser.c"

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
     MOTD = 351,
     NAME = 352,
     NEED_IDENT = 353,
     NEED_PASSWORD = 354,
     NETWORK_DESC = 355,
     NETWORK_NAME = 356,
     NICK = 357,
     NO_CREATE_ON_SPLIT = 358,
     NO_JOIN_ON_SPLIT = 359,
     NO_OPER_FLOOD = 360,
     NO_TILDE = 361,
     NUMBER = 362,
     NUMBER_PER_CIDR = 363,
     NUMBER_PER_IP = 364,
     OPER_ONLY_UMODES = 365,
     OPER_PASS_RESV = 366,
     OPER_UMODES = 367,
     OPERATOR = 368,
     OPERS_BYPASS_CALLERID = 369,
     PACE_WAIT = 370,
     PACE_WAIT_SIMPLE = 371,
     PASSWORD = 372,
     PATH = 373,
     PING_COOKIE = 374,
     PING_TIME = 375,
     PORT = 376,
     QSTRING = 377,
     RANDOM_IDLE = 378,
     REASON = 379,
     REDIRPORT = 380,
     REDIRSERV = 381,
     REHASH = 382,
     REMOTE = 383,
     REMOTEBAN = 384,
     RESV = 385,
     RESV_EXEMPT = 386,
     RSA_PRIVATE_KEY_FILE = 387,
     RSA_PUBLIC_KEY_FILE = 388,
     SECONDS = 389,
     MINUTES = 390,
     HOURS = 391,
     DAYS = 392,
     WEEKS = 393,
     MONTHS = 394,
     YEARS = 395,
     SEND_PASSWORD = 396,
     SENDQ = 397,
     SERVERHIDE = 398,
     SERVERINFO = 399,
     SHORT_MOTD = 400,
     SPOOF = 401,
     SPOOF_NOTICE = 402,
     SQUIT = 403,
     SSL_CERTIFICATE_FILE = 404,
     SSL_DH_PARAM_FILE = 405,
     STATS_E_DISABLED = 406,
     STATS_I_OPER_ONLY = 407,
     STATS_K_OPER_ONLY = 408,
     STATS_O_OPER_ONLY = 409,
     STATS_P_OPER_ONLY = 410,
     T_ALL = 411,
     T_BOTS = 412,
     T_CALLERID = 413,
     T_CCONN = 414,
     T_CCONN_FULL = 415,
     T_CLUSTER = 416,
     T_DEAF = 417,
     T_DEBUG = 418,
     T_DLINE = 419,
     T_EXTERNAL = 420,
     T_FARCONNECT = 421,
     T_FILE = 422,
     T_FULL = 423,
     T_GLOBOPS = 424,
     T_INVISIBLE = 425,
     T_IPV4 = 426,
     T_IPV6 = 427,
     T_LOCOPS = 428,
     T_LOG = 429,
     T_MAX_CLIENTS = 430,
     T_NCHANGE = 431,
     T_NONONREG = 432,
     T_OPERWALL = 433,
     T_RECVQ = 434,
     T_REJ = 435,
     T_RESTART = 436,
     T_SERVER = 437,
     T_SERVICE = 438,
     T_SERVICES_NAME = 439,
     T_SERVNOTICE = 440,
     T_SET = 441,
     T_SHARED = 442,
     T_SIZE = 443,
     T_SKILL = 444,
     T_SOFTCALLERID = 445,
     T_SPY = 446,
     T_SSL = 447,
     T_SSL_CIPHER_LIST = 448,
     T_SSL_CLIENT_METHOD = 449,
     T_SSL_SERVER_METHOD = 450,
     T_SSLV3 = 451,
     T_TLSV1 = 452,
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
     THROTTLE_TIME = 463,
     TKLINE_EXPIRE_NOTICES = 464,
     TMASKED = 465,
     TRUE_NO_OPER_FLOOD = 466,
     TS_MAX_DELTA = 467,
     TS_WARN_DELTA = 468,
     TWODOTS = 469,
     TYPE = 470,
     UNKLINE = 471,
     USE_EGD = 472,
     USE_LOGGING = 473,
     USER = 474,
     VHOST = 475,
     VHOST6 = 476,
     WARN_NO_NLINE = 477,
     XLINE = 478
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
#define MOTD 351
#define NAME 352
#define NEED_IDENT 353
#define NEED_PASSWORD 354
#define NETWORK_DESC 355
#define NETWORK_NAME 356
#define NICK 357
#define NO_CREATE_ON_SPLIT 358
#define NO_JOIN_ON_SPLIT 359
#define NO_OPER_FLOOD 360
#define NO_TILDE 361
#define NUMBER 362
#define NUMBER_PER_CIDR 363
#define NUMBER_PER_IP 364
#define OPER_ONLY_UMODES 365
#define OPER_PASS_RESV 366
#define OPER_UMODES 367
#define OPERATOR 368
#define OPERS_BYPASS_CALLERID 369
#define PACE_WAIT 370
#define PACE_WAIT_SIMPLE 371
#define PASSWORD 372
#define PATH 373
#define PING_COOKIE 374
#define PING_TIME 375
#define PORT 376
#define QSTRING 377
#define RANDOM_IDLE 378
#define REASON 379
#define REDIRPORT 380
#define REDIRSERV 381
#define REHASH 382
#define REMOTE 383
#define REMOTEBAN 384
#define RESV 385
#define RESV_EXEMPT 386
#define RSA_PRIVATE_KEY_FILE 387
#define RSA_PUBLIC_KEY_FILE 388
#define SECONDS 389
#define MINUTES 390
#define HOURS 391
#define DAYS 392
#define WEEKS 393
#define MONTHS 394
#define YEARS 395
#define SEND_PASSWORD 396
#define SENDQ 397
#define SERVERHIDE 398
#define SERVERINFO 399
#define SHORT_MOTD 400
#define SPOOF 401
#define SPOOF_NOTICE 402
#define SQUIT 403
#define SSL_CERTIFICATE_FILE 404
#define SSL_DH_PARAM_FILE 405
#define STATS_E_DISABLED 406
#define STATS_I_OPER_ONLY 407
#define STATS_K_OPER_ONLY 408
#define STATS_O_OPER_ONLY 409
#define STATS_P_OPER_ONLY 410
#define T_ALL 411
#define T_BOTS 412
#define T_CALLERID 413
#define T_CCONN 414
#define T_CCONN_FULL 415
#define T_CLUSTER 416
#define T_DEAF 417
#define T_DEBUG 418
#define T_DLINE 419
#define T_EXTERNAL 420
#define T_FARCONNECT 421
#define T_FILE 422
#define T_FULL 423
#define T_GLOBOPS 424
#define T_INVISIBLE 425
#define T_IPV4 426
#define T_IPV6 427
#define T_LOCOPS 428
#define T_LOG 429
#define T_MAX_CLIENTS 430
#define T_NCHANGE 431
#define T_NONONREG 432
#define T_OPERWALL 433
#define T_RECVQ 434
#define T_REJ 435
#define T_RESTART 436
#define T_SERVER 437
#define T_SERVICE 438
#define T_SERVICES_NAME 439
#define T_SERVNOTICE 440
#define T_SET 441
#define T_SHARED 442
#define T_SIZE 443
#define T_SKILL 444
#define T_SOFTCALLERID 445
#define T_SPY 446
#define T_SSL 447
#define T_SSL_CIPHER_LIST 448
#define T_SSL_CLIENT_METHOD 449
#define T_SSL_SERVER_METHOD 450
#define T_SSLV3 451
#define T_TLSV1 452
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
#define THROTTLE_TIME 463
#define TKLINE_EXPIRE_NOTICES 464
#define TMASKED 465
#define TRUE_NO_OPER_FLOOD 466
#define TS_MAX_DELTA 467
#define TS_WARN_DELTA 468
#define TWODOTS 469
#define TYPE 470
#define UNKLINE 471
#define USE_EGD 472
#define USE_LOGGING 473
#define USER 474
#define VHOST 475
#define VHOST6 476
#define WARN_NO_NLINE 477
#define XLINE 478



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 139 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 677 "conf_parser.c"
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
#line 705 "conf_parser.c"

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
#define YYLAST   1302

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  286
/* YYNRULES -- Number of rules.  */
#define YYNRULES  647
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1263

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
       2,     2,     2,     2,     2,     2,     2,     2,   229,   224,
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
      39,    41,    43,    45,    47,    49,    52,    55,    56,    58,
      61,    65,    69,    73,    77,    81,    85,    89,    90,    92,
      95,    99,   103,   107,   113,   116,   118,   120,   122,   125,
     130,   135,   141,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   180,   183,   188,   193,   197,   199,   201,   203,   207,
     209,   211,   213,   218,   223,   228,   233,   238,   243,   248,
     253,   258,   263,   268,   273,   278,   283,   288,   294,   297,
     299,   301,   303,   305,   308,   313,   318,   323,   324,   331,
     334,   336,   338,   340,   343,   348,   353,   359,   362,   364,
     366,   368,   371,   376,   377,   384,   387,   389,   391,   393,
     395,   398,   403,   408,   413,   414,   420,   424,   426,   428,
     430,   432,   434,   436,   438,   440,   441,   448,   451,   453,
     455,   457,   459,   461,   463,   465,   467,   469,   472,   477,
     482,   487,   492,   497,   502,   503,   509,   513,   515,   517,
     519,   521,   523,   525,   527,   529,   531,   533,   535,   537,
     539,   541,   543,   545,   547,   549,   551,   553,   555,   557,
     559,   560,   566,   570,   572,   576,   578,   582,   584,   588,
     590,   592,   594,   596,   598,   600,   602,   604,   606,   608,
     610,   612,   614,   616,   618,   620,   622,   624,   625,   632,
     635,   637,   639,   641,   643,   645,   647,   649,   651,   653,
     655,   657,   659,   661,   663,   665,   667,   669,   672,   677,
     682,   687,   692,   697,   702,   707,   712,   717,   722,   727,
     732,   737,   742,   747,   748,   754,   758,   760,   762,   764,
     765,   772,   773,   779,   783,   785,   787,   789,   791,   794,
     796,   798,   800,   802,   804,   807,   808,   814,   818,   820,
     822,   826,   831,   836,   837,   844,   847,   849,   851,   853,
     855,   857,   859,   861,   863,   865,   868,   873,   878,   883,
     888,   889,   895,   899,   901,   903,   905,   907,   909,   911,
     913,   915,   917,   919,   921,   926,   931,   936,   937,   944,
     947,   949,   951,   953,   955,   958,   963,   968,   973,   979,
     982,   984,   986,   988,   993,   994,  1001,  1004,  1006,  1008,
    1010,  1012,  1015,  1020,  1025,  1026,  1032,  1036,  1038,  1040,
    1042,  1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1059,
    1066,  1069,  1071,  1073,  1075,  1078,  1083,  1084,  1090,  1094,
    1096,  1098,  1100,  1102,  1104,  1106,  1108,  1110,  1112,  1114,
    1116,  1117,  1124,  1127,  1129,  1131,  1133,  1135,  1137,  1139,
    1141,  1143,  1145,  1147,  1149,  1151,  1153,  1155,  1158,  1163,
    1168,  1173,  1178,  1183,  1188,  1193,  1198,  1199,  1205,  1209,
    1211,  1213,  1215,  1220,  1225,  1230,  1235,  1240,  1241,  1248,
    1251,  1253,  1255,  1257,  1259,  1264,  1269,  1270,  1277,  1280,
    1282,  1284,  1286,  1288,  1293,  1298,  1304,  1307,  1309,  1311,
    1313,  1318,  1319,  1326,  1329,  1331,  1333,  1335,  1337,  1342,
    1347,  1353,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,
    1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,  1410,
    1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,  1430,
    1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,  1450,
    1452,  1454,  1456,  1461,  1466,  1471,  1476,  1481,  1486,  1491,
    1496,  1501,  1506,  1511,  1516,  1521,  1526,  1531,  1536,  1541,
    1546,  1551,  1556,  1561,  1566,  1571,  1576,  1581,  1586,  1591,
    1596,  1601,  1606,  1611,  1616,  1621,  1626,  1631,  1636,  1641,
    1646,  1651,  1656,  1661,  1666,  1671,  1676,  1681,  1682,  1688,
    1692,  1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,
    1712,  1714,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1730,
    1732,  1734,  1736,  1738,  1739,  1745,  1749,  1751,  1753,  1755,
    1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,  1775,
    1777,  1779,  1781,  1783,  1785,  1787,  1789,  1791,  1793,  1795,
    1800,  1805,  1810,  1816,  1819,  1821,  1823,  1825,  1827,  1829,
    1831,  1833,  1835,  1837,  1839,  1841,  1843,  1845,  1847,  1852,
    1857,  1862,  1867,  1872,  1877,  1882,  1887,  1892,  1897,  1902,
    1907,  1913,  1916,  1918,  1920,  1922,  1924,  1926,  1928,  1930,
    1932,  1934,  1939,  1944,  1949,  1954,  1959,  1964
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     231,     0,    -1,    -1,   231,   232,    -1,   266,    -1,   278,
      -1,   292,    -1,   491,    -1,   310,    -1,   333,    -1,   347,
      -1,   242,    -1,   506,    -1,   362,    -1,   369,    -1,   373,
      -1,   383,    -1,   392,    -1,   412,    -1,   418,    -1,   424,
      -1,   434,    -1,   428,    -1,   237,    -1,   272,    -1,     1,
     224,    -1,     1,   225,    -1,    -1,   234,    -1,   107,   233,
      -1,   107,   134,   233,    -1,   107,   135,   233,    -1,   107,
     136,   233,    -1,   107,   137,   233,    -1,   107,   138,   233,
      -1,   107,   139,   233,    -1,   107,   140,   233,    -1,    -1,
     236,    -1,   107,   235,    -1,   107,     9,   235,    -1,   107,
      10,   235,    -1,   107,    11,   235,    -1,    95,   226,   238,
     225,   224,    -1,   238,   239,    -1,   239,    -1,   240,    -1,
     241,    -1,     1,   224,    -1,    94,   227,   122,   224,    -1,
     118,   227,   122,   224,    -1,   144,   226,   243,   225,   224,
      -1,   243,   244,    -1,   244,    -1,   255,    -1,   260,    -1,
     265,    -1,   257,    -1,   258,    -1,   259,    -1,   262,    -1,
     263,    -1,   264,    -1,   253,    -1,   252,    -1,   261,    -1,
     256,    -1,   251,    -1,   245,    -1,   246,    -1,   254,    -1,
       1,   224,    -1,   194,   227,   247,   224,    -1,   195,   227,
     249,   224,    -1,   247,   228,   248,    -1,   248,    -1,   196,
      -1,   197,    -1,   249,   228,   250,    -1,   250,    -1,   196,
      -1,   197,    -1,   149,   227,   122,   224,    -1,   132,   227,
     122,   224,    -1,   150,   227,   122,   224,    -1,   193,   227,
     122,   224,    -1,    97,   227,   122,   224,    -1,    63,   227,
     122,   224,    -1,    24,   227,   122,   224,    -1,   101,   227,
     122,   224,    -1,   100,   227,   122,   224,    -1,   220,   227,
     122,   224,    -1,   221,   227,   122,   224,    -1,   175,   227,
     107,   224,    -1,    85,   227,   107,   224,    -1,    89,   227,
     107,   224,    -1,    56,   227,   207,   224,    -1,     4,   226,
     267,   225,   224,    -1,   267,   268,    -1,   268,    -1,   269,
      -1,   271,    -1,   270,    -1,     1,   224,    -1,    97,   227,
     122,   224,    -1,    31,   227,   122,   224,    -1,    24,   227,
     122,   224,    -1,    -1,    96,   273,   226,   274,   225,   224,
      -1,   274,   275,    -1,   275,    -1,   276,    -1,   277,    -1,
       1,   224,    -1,    75,   227,   122,   224,    -1,   167,   227,
     122,   224,    -1,   174,   226,   279,   225,   224,    -1,   279,
     280,    -1,   280,    -1,   281,    -1,   282,    -1,     1,   224,
      -1,   218,   227,   207,   224,    -1,    -1,   283,   167,   226,
     284,   225,   224,    -1,   284,   285,    -1,   285,    -1,   286,
      -1,   288,    -1,   287,    -1,     1,   224,    -1,    97,   227,
     122,   224,    -1,   188,   227,   236,   224,    -1,   188,   227,
     201,   224,    -1,    -1,   215,   289,   227,   290,   224,    -1,
     290,   228,   291,    -1,   291,    -1,   219,    -1,   113,    -1,
      39,    -1,   164,    -1,    68,    -1,    66,    -1,   163,    -1,
      -1,   113,   293,   226,   294,   225,   224,    -1,   294,   295,
      -1,   295,    -1,   296,    -1,   297,    -1,   298,    -1,   302,
      -1,   301,    -1,   299,    -1,   300,    -1,   306,    -1,     1,
     224,    -1,    97,   227,   122,   224,    -1,   219,   227,   122,
     224,    -1,   117,   227,   122,   224,    -1,    32,   227,   207,
     224,    -1,   133,   227,   122,   224,    -1,    17,   227,   122,
     224,    -1,    -1,   198,   303,   227,   304,   224,    -1,   304,
     228,   305,    -1,   305,    -1,   157,    -1,   159,    -1,   160,
      -1,   162,    -1,   163,    -1,   168,    -1,    48,    -1,   189,
      -1,   176,    -1,   180,    -1,   199,    -1,   191,    -1,   165,
      -1,   178,    -1,   185,    -1,   170,    -1,   204,    -1,   190,
      -1,   158,    -1,   173,    -1,   177,    -1,   166,    -1,    -1,
      62,   307,   227,   308,   224,    -1,   308,   228,   309,    -1,
     309,    -1,    66,   229,   128,    -1,    66,    -1,    18,   229,
     128,    -1,    18,    -1,   148,   229,   128,    -1,   148,    -1,
      68,    -1,   216,    -1,   164,    -1,   200,    -1,   223,    -1,
      39,    -1,    25,    -1,   181,    -1,   127,    -1,     4,    -1,
     178,    -1,   169,    -1,   205,    -1,   173,    -1,   129,    -1,
     186,    -1,    94,    -1,    -1,    17,   311,   226,   312,   225,
     224,    -1,   312,   313,    -1,   313,    -1,   314,    -1,   324,
      -1,   325,    -1,   315,    -1,   326,    -1,   316,    -1,   317,
      -1,   318,    -1,   319,    -1,   320,    -1,   321,    -1,   322,
      -1,   323,    -1,   327,    -1,   328,    -1,   329,    -1,     1,
     224,    -1,    97,   227,   122,   224,    -1,   120,   227,   234,
     224,    -1,   109,   227,   107,   224,    -1,    19,   227,   234,
     224,    -1,    87,   227,   107,   224,    -1,    80,   227,   107,
     224,    -1,    83,   227,   107,   224,    -1,    81,   227,   107,
     224,    -1,   142,   227,   236,   224,    -1,   179,   227,   236,
     224,    -1,    15,   227,   107,   224,    -1,    16,   227,   107,
     224,    -1,   108,   227,   107,   224,    -1,    91,   227,   234,
     224,    -1,    82,   227,   234,   224,    -1,    -1,    62,   330,
     227,   331,   224,    -1,   331,   228,   332,    -1,   332,    -1,
     123,    -1,    50,    -1,    -1,    74,   334,   226,   339,   225,
     224,    -1,    -1,    62,   336,   227,   337,   224,    -1,   337,
     228,   338,    -1,   338,    -1,   192,    -1,    48,    -1,   182,
      -1,   339,   340,    -1,   340,    -1,   341,    -1,   335,    -1,
     345,    -1,   346,    -1,     1,   224,    -1,    -1,   121,   227,
     343,   342,   224,    -1,   343,   228,   344,    -1,   344,    -1,
     107,    -1,   107,   214,   107,    -1,    60,   227,   122,   224,
      -1,    55,   227,   122,   224,    -1,    -1,    61,   348,   226,
     349,   225,   224,    -1,   349,   350,    -1,   350,    -1,   351,
      -1,   352,    -1,   353,    -1,   355,    -1,   359,    -1,   360,
      -1,   361,    -1,   354,    -1,     1,   224,    -1,   219,   227,
     122,   224,    -1,   117,   227,   122,   224,    -1,    17,   227,
     122,   224,    -1,    32,   227,   207,   224,    -1,    -1,    62,
     356,   227,   357,   224,    -1,   357,   228,   358,    -1,   358,
      -1,   147,    -1,    33,    -1,    69,    -1,    98,    -1,    13,
      -1,   106,    -1,    42,    -1,   131,    -1,   206,    -1,    99,
      -1,   146,   227,   122,   224,    -1,   126,   227,   122,   224,
      -1,   125,   227,   107,   224,    -1,    -1,   130,   363,   226,
     364,   225,   224,    -1,   364,   365,    -1,   365,    -1,   366,
      -1,   367,    -1,   368,    -1,     1,   224,    -1,    75,   227,
     122,   224,    -1,   124,   227,   122,   224,    -1,    34,   227,
     122,   224,    -1,   183,   226,   370,   225,   224,    -1,   370,
     371,    -1,   371,    -1,   372,    -1,     1,    -1,    97,   227,
     122,   224,    -1,    -1,   187,   374,   226,   375,   225,   224,
      -1,   375,   376,    -1,   376,    -1,   377,    -1,   378,    -1,
     379,    -1,     1,   224,    -1,    97,   227,   122,   224,    -1,
     219,   227,   122,   224,    -1,    -1,   215,   380,   227,   381,
     224,    -1,   381,   228,   382,    -1,   382,    -1,    68,    -1,
     216,    -1,   164,    -1,   200,    -1,   223,    -1,   203,    -1,
     130,    -1,   202,    -1,   173,    -1,   156,    -1,    -1,   161,
     384,   226,   385,   225,   224,    -1,   385,   386,    -1,   386,
      -1,   387,    -1,   388,    -1,     1,   224,    -1,    97,   227,
     122,   224,    -1,    -1,   215,   389,   227,   390,   224,    -1,
     390,   228,   391,    -1,   391,    -1,    68,    -1,   216,    -1,
     164,    -1,   200,    -1,   223,    -1,   203,    -1,   130,    -1,
     202,    -1,   173,    -1,   156,    -1,    -1,    18,   393,   226,
     394,   225,   224,    -1,   394,   395,    -1,   395,    -1,   396,
      -1,   397,    -1,   398,    -1,   399,    -1,   400,    -1,   402,
      -1,   401,    -1,   411,    -1,   403,    -1,   408,    -1,   409,
      -1,   410,    -1,   407,    -1,     1,   224,    -1,    97,   227,
     122,   224,    -1,    55,   227,   122,   224,    -1,   220,   227,
     122,   224,    -1,   141,   227,   122,   224,    -1,     3,   227,
     122,   224,    -1,   121,   227,   107,   224,    -1,     5,   227,
     171,   224,    -1,     5,   227,   172,   224,    -1,    -1,    62,
     404,   227,   405,   224,    -1,   405,   228,   406,    -1,   406,
      -1,     8,    -1,   192,    -1,    32,   227,   207,   224,    -1,
      57,   227,   122,   224,    -1,    72,   227,   122,   224,    -1,
      17,   227,   122,   224,    -1,   193,   227,   122,   224,    -1,
      -1,    66,   413,   226,   414,   225,   224,    -1,   414,   415,
      -1,   415,    -1,   416,    -1,   417,    -1,     1,    -1,   219,
     227,   122,   224,    -1,   124,   227,   122,   224,    -1,    -1,
      23,   419,   226,   420,   225,   224,    -1,   420,   421,    -1,
     421,    -1,   422,    -1,   423,    -1,     1,    -1,    60,   227,
     122,   224,    -1,   124,   227,   122,   224,    -1,    34,   226,
     425,   225,   224,    -1,   425,   426,    -1,   426,    -1,   427,
      -1,     1,    -1,    60,   227,   122,   224,    -1,    -1,    37,
     429,   226,   430,   225,   224,    -1,   430,   431,    -1,   431,
      -1,   432,    -1,   433,    -1,     1,    -1,    97,   227,   122,
     224,    -1,   124,   227,   122,   224,    -1,    38,   226,   435,
     225,   224,    -1,   435,   436,    -1,   436,    -1,   445,    -1,
     446,    -1,   448,    -1,   449,    -1,   450,    -1,   451,    -1,
     452,    -1,   453,    -1,   454,    -1,   455,    -1,   444,    -1,
     457,    -1,   458,    -1,   472,    -1,   460,    -1,   462,    -1,
     464,    -1,   463,    -1,   467,    -1,   461,    -1,   468,    -1,
     469,    -1,   470,    -1,   471,    -1,   484,    -1,   473,    -1,
     474,    -1,   475,    -1,   480,    -1,   465,    -1,   466,    -1,
     490,    -1,   488,    -1,   489,    -1,   447,    -1,   479,    -1,
     456,    -1,   477,    -1,   478,    -1,   443,    -1,   438,    -1,
     439,    -1,   440,    -1,   441,    -1,   442,    -1,   459,    -1,
     437,    -1,   476,    -1,     1,    -1,    90,   227,   107,   224,
      -1,    41,   227,   207,   224,    -1,    40,   227,   234,   224,
      -1,    45,   227,   234,   224,    -1,    43,   227,   107,   224,
      -1,    44,   227,   107,   224,    -1,   209,   227,   207,   224,
      -1,    67,   227,   234,   224,    -1,    54,   227,   207,   224,
      -1,    58,   227,   207,   224,    -1,    28,   227,   207,   224,
      -1,    35,   227,   207,   224,    -1,     6,   227,   207,   224,
      -1,    86,   227,   234,   224,    -1,    84,   227,   107,   224,
      -1,    76,   227,   107,   224,    -1,     7,   227,   234,   224,
      -1,   213,   227,   234,   224,    -1,   212,   227,   234,   224,
      -1,    47,   227,   107,   224,    -1,    59,   227,   207,   224,
      -1,   222,   227,   207,   224,    -1,   151,   227,   207,   224,
      -1,   154,   227,   207,   224,    -1,   155,   227,   207,   224,
      -1,   153,   227,   207,   224,    -1,   153,   227,   210,   224,
      -1,   152,   227,   207,   224,    -1,   152,   227,   210,   224,
      -1,   115,   227,   234,   224,    -1,    12,   227,   234,   224,
      -1,   114,   227,   207,   224,    -1,   116,   227,   234,   224,
      -1,   145,   227,   207,   224,    -1,   105,   227,   207,   224,
      -1,   211,   227,   207,   224,    -1,   111,   227,   207,   224,
      -1,    29,   227,   107,   224,    -1,    88,   227,   107,   224,
      -1,   217,   227,   207,   224,    -1,    30,   227,   122,   224,
      -1,   184,   227,   122,   224,    -1,   119,   227,   207,   224,
      -1,    26,   227,   207,   224,    -1,   208,   227,   234,   224,
      -1,    -1,   112,   481,   227,   482,   224,    -1,   482,   228,
     483,    -1,   483,    -1,   157,    -1,   159,    -1,   160,    -1,
     162,    -1,   163,    -1,   168,    -1,    48,    -1,   189,    -1,
     176,    -1,   180,    -1,   199,    -1,   191,    -1,   165,    -1,
     178,    -1,   185,    -1,   170,    -1,   204,    -1,   190,    -1,
     158,    -1,   173,    -1,   177,    -1,   166,    -1,    -1,   110,
     485,   227,   486,   224,    -1,   486,   228,   487,    -1,   487,
      -1,   157,    -1,   159,    -1,   160,    -1,   162,    -1,   163,
      -1,   168,    -1,   189,    -1,    48,    -1,   176,    -1,   180,
      -1,   199,    -1,   191,    -1,   165,    -1,   178,    -1,   185,
      -1,   170,    -1,   204,    -1,   190,    -1,   158,    -1,   173,
      -1,   177,    -1,   166,    -1,    92,   227,   107,   224,    -1,
      93,   227,   107,   224,    -1,    20,   227,   107,   224,    -1,
      14,   226,   492,   225,   224,    -1,   492,   493,    -1,   493,
      -1,   499,    -1,   495,    -1,   496,    -1,   497,    -1,   498,
      -1,   500,    -1,   501,    -1,   502,    -1,   503,    -1,   504,
      -1,   505,    -1,   494,    -1,     1,    -1,    27,   227,   207,
     224,    -1,    70,   227,   234,   224,    -1,    71,   227,   234,
     224,    -1,    79,   227,   107,   224,    -1,    78,   227,   107,
     224,    -1,    77,   227,   107,   224,    -1,    22,   227,   107,
     224,    -1,    21,   227,   107,   224,    -1,   103,   227,   207,
     224,    -1,   104,   227,   207,   224,    -1,    64,   227,   107,
     224,    -1,    65,   227,   234,   224,    -1,   143,   226,   507,
     225,   224,    -1,   507,   508,    -1,   508,    -1,   509,    -1,
     510,    -1,   511,    -1,   513,    -1,   514,    -1,   512,    -1,
     515,    -1,     1,    -1,    36,   227,   207,   224,    -1,    52,
     227,   207,   224,    -1,    53,   227,   207,   224,    -1,    49,
     227,   122,   224,    -1,    73,   227,   234,   224,    -1,    48,
     227,   207,   224,    -1,    51,   227,   207,   224,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   366,   366,   367,   370,   371,   372,   373,   374,   375,
     376,   377,   378,   379,   380,   381,   382,   383,   384,   385,
     386,   387,   388,   389,   390,   391,   392,   396,   396,   397,
     401,   405,   409,   413,   417,   421,   425,   431,   431,   432,
     433,   434,   435,   442,   445,   445,   446,   446,   446,   448,
     454,   461,   463,   463,   464,   464,   465,   465,   466,   466,
     467,   467,   468,   468,   469,   469,   470,   470,   471,   471,
     472,   473,   476,   477,   479,   479,   480,   486,   494,   494,
     495,   501,   509,   551,   610,   638,   646,   661,   676,   685,
     699,   708,   736,   766,   791,   813,   835,   844,   846,   846,
     847,   847,   848,   848,   850,   859,   868,   881,   880,   898,
     898,   899,   899,   899,   901,   907,   916,   917,   917,   919,
     919,   920,   922,   929,   929,   942,   943,   945,   945,   946,
     946,   948,   956,   959,   965,   964,   970,   970,   971,   975,
     979,   983,   987,   991,   995,  1006,  1005,  1082,  1082,  1083,
    1083,  1083,  1084,  1084,  1084,  1085,  1085,  1085,  1087,  1093,
    1099,  1105,  1116,  1122,  1129,  1128,  1134,  1134,  1135,  1139,
    1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,  1179,
    1183,  1187,  1191,  1195,  1199,  1203,  1207,  1211,  1215,  1219,
    1226,  1225,  1231,  1231,  1232,  1236,  1240,  1244,  1248,  1252,
    1256,  1260,  1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,
    1296,  1300,  1304,  1308,  1312,  1316,  1320,  1331,  1330,  1391,
    1391,  1392,  1393,  1393,  1394,  1395,  1396,  1397,  1398,  1399,
    1400,  1401,  1402,  1402,  1403,  1404,  1405,  1406,  1408,  1414,
    1420,  1426,  1432,  1438,  1444,  1450,  1456,  1462,  1469,  1475,
    1481,  1487,  1496,  1506,  1505,  1511,  1511,  1512,  1516,  1527,
    1526,  1533,  1532,  1537,  1537,  1538,  1542,  1546,  1552,  1552,
    1553,  1553,  1553,  1553,  1553,  1555,  1555,  1557,  1557,  1559,
    1573,  1593,  1599,  1609,  1608,  1650,  1650,  1651,  1651,  1651,
    1651,  1652,  1652,  1652,  1653,  1653,  1655,  1661,  1667,  1673,
    1685,  1684,  1690,  1690,  1691,  1695,  1699,  1703,  1707,  1711,
    1715,  1719,  1723,  1727,  1733,  1747,  1756,  1770,  1769,  1784,
    1784,  1785,  1785,  1785,  1785,  1787,  1793,  1799,  1809,  1811,
    1811,  1812,  1812,  1814,  1830,  1829,  1854,  1854,  1855,  1855,
    1855,  1855,  1857,  1863,  1883,  1882,  1888,  1888,  1889,  1893,
    1897,  1901,  1905,  1909,  1913,  1917,  1921,  1925,  1935,  1934,
    1955,  1955,  1956,  1956,  1956,  1958,  1965,  1964,  1970,  1970,
    1971,  1975,  1979,  1983,  1987,  1991,  1995,  1999,  2003,  2007,
    2017,  2016,  2082,  2082,  2083,  2083,  2083,  2084,  2084,  2085,
    2085,  2085,  2086,  2086,  2086,  2087,  2087,  2088,  2090,  2096,
    2102,  2108,  2121,  2134,  2140,  2144,  2153,  2152,  2157,  2157,
    2158,  2162,  2168,  2179,  2185,  2191,  2197,  2213,  2212,  2238,
    2238,  2239,  2239,  2239,  2241,  2261,  2271,  2270,  2297,  2297,
    2298,  2298,  2298,  2300,  2306,  2315,  2317,  2317,  2318,  2318,
    2320,  2338,  2337,  2360,  2360,  2361,  2361,  2361,  2363,  2369,
    2378,  2381,  2381,  2382,  2382,  2383,  2383,  2384,  2384,  2385,
    2385,  2386,  2386,  2387,  2388,  2389,  2389,  2390,  2390,  2391,
    2391,  2392,  2392,  2393,  2393,  2394,  2394,  2395,  2395,  2396,
    2396,  2397,  2397,  2398,  2398,  2399,  2399,  2400,  2401,  2401,
    2402,  2403,  2404,  2404,  2405,  2405,  2406,  2407,  2408,  2409,
    2409,  2410,  2413,  2418,  2424,  2430,  2436,  2441,  2446,  2451,
    2456,  2461,  2466,  2471,  2476,  2481,  2486,  2491,  2496,  2501,
    2506,  2512,  2523,  2528,  2533,  2538,  2543,  2548,  2551,  2556,
    2559,  2564,  2569,  2574,  2579,  2584,  2589,  2594,  2599,  2604,
    2609,  2614,  2619,  2628,  2637,  2642,  2647,  2653,  2652,  2657,
    2657,  2658,  2661,  2664,  2667,  2670,  2673,  2676,  2679,  2682,
    2685,  2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,  2712,
    2715,  2718,  2721,  2727,  2726,  2731,  2731,  2732,  2735,  2738,
    2741,  2744,  2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,
    2771,  2774,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2800,
    2805,  2810,  2819,  2822,  2822,  2823,  2824,  2824,  2825,  2825,
    2826,  2827,  2828,  2829,  2830,  2830,  2831,  2831,  2833,  2838,
    2843,  2848,  2853,  2858,  2863,  2868,  2873,  2878,  2883,  2888,
    2896,  2899,  2899,  2900,  2900,  2901,  2902,  2903,  2903,  2904,
    2905,  2907,  2913,  2919,  2925,  2934,  2948,  2954
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
  "MODULE", "MODULES", "MOTD", "NAME", "NEED_IDENT", "NEED_PASSWORD",
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
  "admin_description", "motd_entry", "$@1", "motd_items", "motd_item",
  "motd_mask", "motd_file", "logging_entry", "logging_items",
  "logging_item", "logging_use_logging", "logging_file_entry", "$@2",
  "logging_file_items", "logging_file_item", "logging_file_name",
  "logging_file_size", "logging_file_type", "$@3",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@4",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class",
  "oper_umodes", "$@5", "oper_umodes_items", "oper_umodes_item",
  "oper_flags", "$@6", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@7", "class_items", "class_item", "class_name",
  "class_ping_time", "class_number_per_ip", "class_connectfreq",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@8", "class_flags_items", "class_flags_item",
  "listen_entry", "$@9", "listen_flags", "$@10", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@11", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@12", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@13",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@14", "resv_items", "resv_item",
  "resv_mask", "resv_reason", "resv_exempt", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@15",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@16", "shared_types", "shared_type_item",
  "cluster_entry", "$@17", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@18", "cluster_types", "cluster_type_item",
  "connect_entry", "$@19", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@20", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@21",
  "kill_items", "kill_item", "kill_user", "kill_reason", "deny_entry",
  "$@22", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "$@23", "gecos_items", "gecos_item", "gecos_name",
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
  "$@24", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@25", "umode_items", "umode_item", "general_min_nonwildcard",
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
     475,   476,   477,   478,    59,   125,   123,    61,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   230,   231,   231,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   235,   236,
     236,   236,   236,   237,   238,   238,   239,   239,   239,   240,
     241,   242,   243,   243,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   245,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   267,
     268,   268,   268,   268,   269,   270,   271,   273,   272,   274,
     274,   275,   275,   275,   276,   277,   278,   279,   279,   280,
     280,   280,   281,   283,   282,   284,   284,   285,   285,   285,
     285,   286,   287,   287,   289,   288,   290,   290,   291,   291,
     291,   291,   291,   291,   291,   293,   292,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   296,   297,
     298,   299,   300,   301,   303,   302,   304,   304,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     307,   306,   308,   308,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   311,   310,   312,
     312,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   330,   329,   331,   331,   332,   332,   334,
     333,   336,   335,   337,   337,   338,   338,   338,   339,   339,
     340,   340,   340,   340,   340,   342,   341,   343,   343,   344,
     344,   345,   346,   348,   347,   349,   349,   350,   350,   350,
     350,   350,   350,   350,   350,   350,   351,   352,   353,   354,
     356,   355,   357,   357,   358,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   359,   360,   361,   363,   362,   364,
     364,   365,   365,   365,   365,   366,   367,   368,   369,   370,
     370,   371,   371,   372,   374,   373,   375,   375,   376,   376,
     376,   376,   377,   378,   380,   379,   381,   381,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   384,   383,
     385,   385,   386,   386,   386,   387,   389,   388,   390,   390,
     391,   391,   391,   391,   391,   391,   391,   391,   391,   391,
     393,   392,   394,   394,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   395,   395,   395,   395,   396,   397,
     398,   399,   400,   401,   402,   402,   404,   403,   405,   405,
     406,   406,   407,   408,   409,   410,   411,   413,   412,   414,
     414,   415,   415,   415,   416,   417,   419,   418,   420,   420,
     421,   421,   421,   422,   423,   424,   425,   425,   426,   426,
     427,   429,   428,   430,   430,   431,   431,   431,   432,   433,
     434,   435,   435,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   436,   436,   436,   436,   436,   436,   436,   436,
     436,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   462,   463,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   481,   480,   482,
     482,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   483,   483,   485,   484,   486,   486,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   487,   487,   487,   488,
     489,   490,   491,   492,   492,   493,   493,   493,   493,   493,
     493,   493,   493,   493,   493,   493,   493,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   507,   508,   508,   508,   508,   508,   508,   508,
     508,   509,   510,   511,   512,   513,   514,   515
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     1,     2,
       3,     3,     3,     3,     3,     3,     3,     0,     1,     2,
       3,     3,     3,     5,     2,     1,     1,     1,     2,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     3,     1,     1,     1,     3,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     2,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     2,     4,     4,     5,     2,     1,     1,
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
       2,     0,     1,     0,     0,     0,   217,   380,   426,     0,
     441,     0,   283,   417,   259,     0,   107,   145,   317,     0,
       0,   358,     0,     0,   334,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   617,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   604,   616,   606,   607,   608,   609,   605,
     610,   611,   612,   613,   614,   615,     0,     0,     0,   439,
       0,     0,   437,   438,     0,   501,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   573,     0,   547,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   452,   499,   493,   494,   495,
     496,   497,   492,   463,   453,   454,   487,   455,   456,   457,
     458,   459,   460,   461,   462,   489,   464,   465,   498,   467,
     472,   468,   470,   469,   482,   483,   471,   473,   474,   475,
     476,   466,   478,   479,   480,   500,   490,   491,   488,   481,
     477,   485,   486,   484,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,   640,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   633,   634,   635,
     638,   636,   637,   639,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   332,
       0,     0,   330,   331,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   603,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   224,   226,   227,   228,   229,
     230,   231,   232,   233,   222,   223,   225,   234,   235,   236,
       0,     0,     0,     0,     0,     0,     0,   406,     0,     0,
       0,     0,     0,     0,     0,   383,   384,   385,   386,   387,
     388,   390,   389,   392,   396,   393,   394,   395,   391,   432,
       0,     0,     0,   429,   430,   431,     0,     0,   436,   447,
       0,     0,     0,   444,   445,   446,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   451,     0,     0,     0,   300,
       0,     0,     0,     0,     0,     0,   286,   287,   288,   289,
     294,   290,   291,   292,   293,   423,     0,     0,     0,   420,
     421,   422,     0,     0,     0,   261,     0,   271,     0,   269,
     270,   272,   273,    48,     0,     0,     0,    44,     0,     0,
       0,     0,   110,   111,   112,     0,     0,     0,   190,     0,
       0,     0,   164,     0,     0,   148,   149,   150,   151,   154,
     155,   153,   152,   156,     0,     0,     0,     0,     0,   320,
     321,   322,   323,     0,     0,     0,     0,     0,     0,     0,
       0,   631,    71,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,     0,     0,   366,     0,   361,   362,   363,   121,
       0,     0,   117,     0,     0,     0,   329,     0,     0,   344,
       0,     0,   337,   338,   339,   340,     0,     0,     0,    97,
       0,     0,     0,     0,    27,     0,     0,     0,     0,     0,
       0,     0,     0,   602,   237,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   397,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   382,     0,
       0,     0,   428,     0,   435,     0,     0,     0,   443,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   450,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     285,     0,     0,     0,   419,   274,     0,     0,     0,     0,
       0,   268,     0,     0,    43,   113,     0,     0,     0,   109,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     147,   324,     0,     0,     0,     0,   319,     0,     0,     0,
       0,     0,     0,     0,   630,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    77,
       0,    75,    80,    81,     0,    79,     0,     0,    51,   364,
       0,     0,     0,   360,     0,   116,     0,     0,   328,   341,
       0,     0,     0,     0,   336,   106,   105,   104,   625,   624,
     618,   628,    27,    27,    27,    27,    27,    27,    27,    29,
      28,   629,   619,   620,   623,   622,   621,   626,   627,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,   218,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   381,     0,     0,   427,   440,     0,     0,   442,   514,
     518,   532,   601,   545,   512,   539,   542,   513,   504,   503,
     506,   507,   505,   521,   510,   511,   522,   509,   517,   516,
     515,   540,   502,   599,   600,   536,   584,   577,   595,   578,
     579,   580,   581,   589,   598,   582,   592,   596,   585,   597,
     590,   586,   591,   583,   594,   588,   587,   593,     0,   576,
     538,   557,   551,   569,   552,   553,   554,   555,   563,   572,
     556,   566,   570,   559,   571,   564,   560,   565,   558,   568,
     562,   561,   567,     0,   550,   533,   531,   534,   544,   535,
     524,   529,   530,   527,   528,   525,   526,   543,   546,   508,
     537,   520,   519,   541,   523,     0,     0,     0,     0,     0,
       0,     0,     0,   284,     0,     0,   418,     0,     0,     0,
     279,   275,   278,   260,    49,    50,     0,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,   146,     0,     0,
       0,   318,   641,   646,   644,   647,   642,   643,   645,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     359,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   333,     0,     0,     0,   335,    30,    31,    32,    33,
      34,    35,    36,   248,   249,   241,   258,   257,     0,   256,
     243,   245,   252,   244,   242,   251,   238,   250,   240,   239,
      37,    37,    37,    39,    38,   246,   247,   402,   404,   405,
     415,   412,   399,   413,   410,   411,     0,   409,   414,   398,
     403,   401,   416,   400,   433,   434,   448,   449,   574,     0,
     548,     0,   298,   299,   308,   305,   310,   306,   307,   313,
     309,   311,   304,   312,     0,   303,   297,   316,   315,   314,
     296,   425,   424,   282,   281,   266,   267,   265,     0,   264,
       0,     0,     0,   114,   115,   163,   161,   209,   197,   206,
     205,   195,   200,   216,   208,   214,   199,   202,   211,   213,
     210,   207,   215,   203,   212,   201,   204,     0,   193,   158,
     160,   162,   174,   168,   186,   169,   170,   171,   172,   180,
     189,   173,   183,   187,   176,   188,   181,   177,   182,   175,
     185,   179,   178,   184,     0,   167,   159,   327,   325,   326,
      74,    78,   365,   370,   376,   379,   372,   378,   373,   377,
     375,   371,   374,     0,   369,   130,     0,     0,     0,     0,
     125,   342,   348,   354,   357,   350,   356,   351,   355,   353,
     349,   352,     0,   347,   343,   254,     0,    40,    41,    42,
     407,     0,   575,   549,   301,     0,   262,     0,   280,   277,
     276,     0,     0,     0,   191,     0,   165,     0,   367,     0,
       0,     0,     0,     0,   124,   345,     0,   255,   408,   302,
     263,   196,   194,   198,   192,   166,   368,   131,   133,   132,
     140,   143,   142,   139,   144,   141,   138,     0,   137,   346,
     135,     0,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   799,   800,  1053,  1054,    26,   220,   221,
     222,   223,    27,   262,   263,   264,   265,   760,   761,   764,
     765,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    28,    74,    75,    76,
      77,    78,    29,    61,   491,   492,   493,   494,    30,   284,
     285,   286,   287,   288,  1016,  1017,  1018,  1019,  1020,  1188,
    1257,  1258,    31,    62,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   727,  1164,  1165,   513,   723,  1137,  1138,
      32,    51,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     598,  1038,  1039,    33,    59,   477,   708,  1108,  1109,   478,
     479,   480,  1112,   961,   962,   481,   482,    34,    57,   455,
     456,   457,   458,   459,   460,   461,   693,  1094,  1095,   462,
     463,   464,    35,    63,   518,   519,   520,   521,   522,    36,
     291,   292,   293,    37,    69,   571,   572,   573,   574,   575,
     781,  1202,  1203,    38,    66,   555,   556,   557,   558,   771,
    1183,  1184,    39,    52,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   620,  1066,  1067,   374,   375,   376,
     377,   378,    40,    58,   468,   469,   470,   471,    41,    53,
     382,   383,   384,   385,    42,   111,   112,   113,    43,    55,
     392,   393,   394,   395,    44,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   425,   923,   924,   210,   423,   898,   899,   211,   212,
     213,    45,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,    46,   235,   236,   237,
     238,   239,   240,   241,   242,   243
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1023
static const yytype_int16 yypact[] =
{
   -1023,   640, -1023,    87,  -219,  -211, -1023, -1023, -1023,  -191,
   -1023,  -185, -1023, -1023, -1023,  -180, -1023, -1023, -1023,  -149,
    -147, -1023,  -136,  -129, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,    13,
     909,  -111,  -104,   -96,    16,   -90,   373,   -70,   -67,   -45,
      48,   -40,   -26,   -24,   450,   444,   -10,   100,    20,    -8,
      34,    28,    41,    51,    19, -1023, -1023, -1023, -1023, -1023,
      62,    64,    76,    92,   113,   117,   127,   128,   129,   130,
     132,   133,     4, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,   607,   545,    44, -1023,
     143,    39, -1023, -1023,    46, -1023,   146,   148,   154,   159,
     160,   161,   162,   163,   165,   167,   168,   170,   173,   180,
     183,   184,   195,   196,   197,   198,   201,   202,   203,   207,
     208,   209,   210, -1023,   214, -1023,   215,   217,   223,   225,
     229,   231,   233,   235,   237,   243,   245,   246,   247,   249,
     250,   252,   253,   255,   120, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,   321,    58,    10,   158,   263,   264,
      15, -1023, -1023, -1023,     9,   535,   309, -1023,   268,   269,
     270,   279,   281,   282,   283,   244, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,   182,   284,   286,   288,   290,   292,
     293,   294,   295,   303,   304,   305,   307,   311,   312,   315,
     316,   320,    88, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023,    38,   230,   327,    61, -1023, -1023, -1023,   388, -1023,
     331,    65, -1023, -1023,   157, -1023,   349,   437,   439,   339,
   -1023,   457,   459,   362,   463,   464,   464,   464,   465,   467,
     468,   372,   376,   356, -1023,   364,   369,   371,   374, -1023,
     377,   378,   379,   382,   384,   386,   389,   391,   393,   394,
     397,   398,   179, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
     365,   400,   401,   402,   403,   404,   408, -1023,   409,   416,
     418,   419,   420,   421,    31, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
     422,   423,    59, -1023, -1023, -1023,   469,   375, -1023, -1023,
     424,   426,    21, -1023, -1023, -1023,   407,   464,   464,   508,
     448,   452,   526,   538,   454,   464,   455,   560,   563,   464,
     564,   466,   472,   473,   464,   565,   568,   464,   569,   574,
     575,   576,   477,   458,   484,   470,   485,   464,   464,   486,
     488,   492,  -146,   -87,   493,   495,   581,   464,   498,   500,
     464,   464,   501,   502,   487, -1023,   489,   483,   490, -1023,
     494,   496,   497,   499,   504,   190, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,   505,   507,    95, -1023,
   -1023, -1023,   513,   514,   515, -1023,   516, -1023,    18, -1023,
   -1023, -1023, -1023, -1023,   590,   598,   521, -1023,   522,   520,
     523,    23, -1023, -1023, -1023,   524,   528,   529, -1023,   530,
     531,   532, -1023,   533,   152, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,   527,   536,   537,   540,    17, -1023,
   -1023, -1023, -1023,   518,   567,   606,   570,   571,   572,   464,
     547, -1023, -1023,   618,   573,   650,   622,   666,   653,   654,
     659,   663,   665,   670,   686,   672,   150,   155,   673,   674,
     578, -1023,   579,   580, -1023,    32, -1023, -1023, -1023, -1023,
     591,   582, -1023,   583,   677,   584, -1023,   586,   585, -1023,
     589,     8, -1023, -1023, -1023, -1023,   593,   594,   595, -1023,
     596,   597,   600,   601,   227,   602,   608,   611,   614,   616,
     619,   621,   626, -1023, -1023,   693,   698,   464,   615,   706,
     708,   464,   715,   739,   464,   730,   746,   747,   464,   748,
     748,   633, -1023, -1023,   736,   177,   737,   656,   742,   743,
     639,   745,   756,   761,   759,   763,   764,   645, -1023,   766,
     767,   669, -1023,   676, -1023,   773,   774,   678, -1023,   692,
     696,   697,   699,   700,   704,   709,   711,   713,   717,   718,
     719,   720,   721,   722,   723,   725,   726,   727,   728,   731,
     732,   733,   734,   735,   738,   740,   671,   741,   714,   744,
     751,   752,   753,   754,   757,   758,   760,   765,   768,   769,
     770,   771,   772,   775,   776,   777,   778,   779,   780, -1023,
   -1023,   810,   690,   781,   832,   791,   838,   839,   841,   782,
   -1023,   844,   845,   783, -1023, -1023,   847,   848,   784,   794,
     785, -1023,   786,   790, -1023, -1023,   849,   850,   792, -1023,
   -1023,   861,   798,   788,   863,   868,   869,   793,   875,   795,
   -1023, -1023,   876,   895,   896,   797, -1023,   799,   800,   801,
     802,   803,   804,   805, -1023,   806,   807,   808,   809,   811,
     812,   813,   814,   815,   816,   817,   818,   819, -1023, -1023,
    -201, -1023, -1023, -1023,  -186, -1023,   820,   821, -1023, -1023,
     900,   822,   823, -1023,   824, -1023,   112,   826, -1023, -1023,
     912,   825,   924,   827, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023,   464,   464,   464,   464,   464,   464,   464, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   829,
     830,   831,   -38,   833,   834,   835,   836,   837,   840,   842,
     843,   846,   851,   314,   852,   853, -1023,   854,   855,   856,
     857,   858,   859,   860,     0,   862,   864,   865,   866,   867,
     870, -1023,   871,   872, -1023, -1023,   873,   874, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,  -157, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023,  -137, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023,   877,   878,   406,   879,   880,
     881,   882,   883, -1023,   884,   885, -1023,   886,   887,   -35,
     898,   655, -1023, -1023, -1023, -1023,   889,   890, -1023,   891,
     892,   387,   893,   894,   897,   749,   899, -1023,   901,   902,
     903, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023,   150, -1023,   155, -1023, -1023,   904,   566,
   -1023, -1023,   905,   906,   907, -1023,   153, -1023, -1023, -1023,
   -1023, -1023,   908,   588,   911, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   -53, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
     748,   748,   748, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,   -31, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   671,
   -1023,   714, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,   -25, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   -23, -1023,
     949,   794,   913, -1023, -1023, -1023, -1023, -1023,   910, -1023,
   -1023,   914, -1023, -1023, -1023, -1023,   915, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023,   -13, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023,    -7, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023,    78, -1023, -1023,   940,  -101,   918,   916,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023,   102, -1023, -1023, -1023,   -38, -1023, -1023, -1023,
   -1023,     0, -1023, -1023, -1023,   406, -1023,   -35, -1023, -1023,
   -1023,   935,   937,   941, -1023,   387, -1023,   749, -1023,   566,
     917,   922,   923,   330, -1023, -1023,   588, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023,   111, -1023, -1023,
   -1023,   330, -1023
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1023, -1023, -1023,  -740,  -303, -1022,  -609, -1023, -1023,   928,
   -1023, -1023, -1023, -1023,   888, -1023, -1023, -1023,    68, -1023,
      63, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   998, -1023,
   -1023, -1023, -1023, -1023, -1023,   609, -1023, -1023, -1023, -1023,
     789, -1023, -1023, -1023, -1023,    69, -1023, -1023, -1023, -1023,
   -1023,  -187, -1023, -1023, -1023,   620, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023,  -140, -1023, -1023, -1023,  -133,
   -1023, -1023, -1023,   787, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023,  -113, -1023, -1023, -1023, -1023, -1023,  -118, -1023,
     642, -1023, -1023, -1023,    11, -1023, -1023, -1023, -1023, -1023,
     675, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   -84, -1023,
   -1023, -1023, -1023, -1023, -1023,   624, -1023, -1023, -1023, -1023,
   -1023,   919, -1023, -1023, -1023, -1023,   587, -1023, -1023, -1023,
   -1023, -1023,  -100, -1023, -1023, -1023,   599, -1023, -1023, -1023,
   -1023,   -91, -1023, -1023, -1023,   796, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023,   -62, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023,   683, -1023, -1023, -1023, -1023,
   -1023,   920, -1023, -1023, -1023, -1023,  1041, -1023, -1023, -1023,
   -1023,   828, -1023, -1023, -1023, -1023,   989, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023,    74, -1023, -1023, -1023,    77, -1023, -1023,
   -1023, -1023, -1023,  1065, -1023, -1023, -1023, -1023, -1023, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023, -1023, -1023,   926, -1023,
   -1023, -1023, -1023, -1023, -1023, -1023
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
     824,   825,   585,   586,   587,    79,   823,    49,  1064,   567,
     488,   472,  1036,  1105,    70,    50,   217,   109,   514,   472,
      70,   289,   389,  1002,   488,    80,    81,  1003,  1207,  1208,
    1209,    82,   350,   552,   351,    54,   352,    71,  1004,   552,
     109,    56,  1005,    71,    72,   379,    60,   389,   353,   217,
      72,   515,  1026,  1027,  1028,  1029,  1030,  1031,  1032,   465,
     379,   675,   282,   354,   676,   473,   289,  1078,    83,    84,
     474,  1079,   475,   473,    85,    86,   110,    64,   474,    65,
     475,    87,    88,    89,   489,  1037,   355,  1080,   356,   244,
      67,  1081,   516,   357,   640,   641,   465,    68,   489,   110,
    1231,   282,   648,   358,   380,   568,   652,    90,    91,   218,
      73,   657,   245,  1012,   660,   106,    73,   290,   390,   380,
     677,   115,   107,   678,   670,   671,   116,   117,   359,   553,
     108,   476,   118,   219,   682,   553,   114,   685,   686,   476,
     119,   517,   218,   390,   246,   391,   120,  1106,   121,   122,
     123,   247,   360,   495,  1012,   124,   214,  1107,   567,   215,
     125,   126,   290,   127,   128,   129,   219,   130,   381,   496,
     391,  1205,   361,   248,   131,  1206,   490,   249,   132,   133,
     315,   216,   466,   381,   497,   250,   224,   134,   251,   252,
     490,   446,  1065,  1210,   316,   317,   135,  1211,   318,  1214,
     225,  1216,   226,  1215,   136,  1217,   137,   447,   138,  1013,
     139,  1224,   140,   141,   498,  1225,   281,  1226,   294,   466,
     253,  1227,   448,   569,   362,   142,   743,   570,  -123,   313,
     143,   144,   145,   783,   146,   147,   148,   254,   255,   149,
     486,   319,   735,   710,   299,   227,   637,   554,   718,   499,
    1013,   363,   449,   554,   568,   296,   627,   772,   295,   320,
     321,   322,   323,   256,   387,   150,   324,  -123,   297,   500,
     325,   151,   152,   153,   154,   155,   326,   467,   298,   283,
     228,   257,   258,   259,   631,   501,   561,   327,   328,   301,
     565,   302,   229,   230,   811,   231,   232,   233,   815,   329,
    1014,   818,  1228,   303,   156,   822,  1229,   450,   260,   261,
     514,    47,    48,   550,   467,   451,   452,   234,   283,   304,
     703,   330,   446,  1050,  1051,  1052,  1235,  1015,   157,   158,
    1236,   159,   160,   161,   584,  1260,   453,   162,   447,  1261,
     305,  1014,   163,   515,   306,   444,   758,   759,   828,   829,
     502,   762,   763,   448,   307,   308,   309,   310,   331,   311,
     312,   792,   793,   794,   795,   796,   797,   798,  1015,  1250,
     386,   503,   569,   396,   115,   397,   570,   729,  1189,   116,
     117,   398,   483,   449,   516,   118,   399,   400,   401,   402,
     403,  1117,   404,   119,   405,   406,  1251,   407,  1252,   120,
     408,   121,   122,   123,   611,  1118,   532,   409,   124,   454,
     410,   411,  1119,   125,   126,   699,   127,   128,   129,  1084,
     130,   823,   412,   413,   414,   415,  1120,   131,   416,   417,
     418,   132,   133,   517,   419,   420,   421,   422,   450,  1085,
     134,   424,   426,  1253,   427,   244,   451,   452,  1086,   135,
     428,   227,   429,  1121,   559,  1122,   430,   136,   431,   137,
     432,   138,   433,   139,   434,   140,   141,   453,   245,   530,
     435,   576,   436,   437,   438,  1087,   439,   440,   142,   441,
     442,  1123,   443,   143,   144,   145,   228,   146,   147,   148,
     484,   485,   149,  1254,  1255,   523,   524,   525,   229,   230,
     246,   231,   232,   233,  1088,  1089,   526,   247,   527,   528,
     529,   533,  1090,   534,  1124,   535,  1125,   536,   150,   537,
     538,   539,   540,   234,   151,   152,   153,   154,   155,   248,
     541,   542,   543,   249,   544,  1126,   495,  1091,   545,   546,
     454,   250,   547,   548,   251,   252,   350,   549,   351,  1256,
     352,  1127,   496,  1092,   560,   563,  1128,   156,   564,   577,
    1129,   578,   353,   579,   580,  1130,   581,   497,  1131,   582,
     583,   584,   588,  1132,   589,   590,   253,   354,  1232,   591,
     593,   157,   158,   592,   159,   160,   161,  1133,   594,   613,
     162,   633,  1134,   254,   255,   163,   595,   498,   596,   634,
     355,   597,   356,  1135,   599,   600,   601,   357,   315,   602,
    1136,   603,  1093,   604,   639,   642,   605,   358,   606,   256,
     607,   608,   316,   317,   609,   610,   318,   614,   615,   616,
     617,   618,   499,   645,  1173,   619,   621,   257,   258,   259,
       2,     3,   359,   622,     4,   623,   624,   625,   626,   629,
     630,   635,   500,   636,     5,   643,  1192,     6,     7,   644,
     646,   647,   649,     8,   260,   261,   360,   650,   501,   319,
     651,   653,   658,   654,     9,   659,   661,    10,    11,   655,
     656,   662,   663,   664,   665,   666,   361,   320,   321,   322,
     323,   667,   669,   672,   324,   673,  1174,   668,   325,   674,
     679,    12,   680,   681,   326,   683,    13,   684,   687,   688,
     691,   689,   712,   690,    14,   327,   328,   692,  1193,   876,
     713,   694,  1175,   695,   696,   737,   697,   329,   739,   748,
    1176,   698,   701,   502,   702,    15,    16,   705,   362,  1177,
     745,   706,   707,   709,  1194,   714,   715,   716,   720,   330,
     717,   731,  1195,    17,   503,   721,   722,   724,   725,   726,
     728,  1196,   901,   732,   733,   363,  1178,   734,  1179,  1180,
      18,   744,   747,   749,   738,   750,   751,   740,   741,   742,
     746,   752,  1181,    19,    20,   753,   331,   754,  1197,  1182,
    1198,  1199,   755,   756,   757,   766,   767,  1142,   774,   777,
     809,    21,   768,   769,  1200,   810,   775,   770,   778,   776,
     779,  1201,   780,   813,    22,   814,   782,   785,   786,   787,
     788,   789,   816,    23,   790,   791,   801,    24,   877,   878,
     879,   880,   802,   881,   882,   803,   883,   884,   804,   885,
     805,   886,   812,   806,   887,   807,   817,   888,   889,   890,
     808,   891,   819,   820,   821,   823,   892,   826,   827,   830,
     893,   894,   895,   831,   832,   833,   834,   835,   837,   841,
     896,   902,   903,   904,   905,   897,   906,   907,   836,   908,
     909,   838,   910,  1111,   911,   839,   840,   912,   842,   843,
     913,   914,   915,   844,   916,   846,   847,   946,   949,   917,
     845,   960,   848,   918,   919,   920,  1143,  1144,  1145,  1146,
      79,  1147,  1148,   921,  1149,  1150,   849,  1151,   922,  1152,
     850,   851,  1153,   852,   853,  1154,  1155,  1156,   854,  1157,
      80,    81,   945,   855,  1158,   856,    82,   857,  1159,  1160,
    1161,   858,   859,   860,   861,   862,   863,   864,  1162,   865,
     866,   867,   868,  1163,   948,   869,   870,   871,   872,   873,
     950,   951,   874,   952,   875,   900,   954,   955,   925,   957,
     958,   966,   967,    83,    84,   926,   927,   928,   929,    85,
      86,   930,   931,   969,   932,   972,    87,    88,    89,   933,
     973,   974,   934,   935,   936,   937,   938,   976,   978,   939,
     940,   941,   942,   943,   944,   970,   953,   956,   947,   963,
     964,   959,    90,    91,   965,   971,   968,   979,   980,   977,
     975,   981,  1008,   982,   983,   984,   985,   986,   987,   988,
     989,   990,   991,   992,  1022,   993,   994,   995,   996,   997,
     998,   999,  1000,  1001,  1006,  1007,  1024,  1010,  1011,  1009,
    1021,  1025,  1023,  1033,  1034,  1035,  1218,  1040,  1041,  1042,
    1043,  1044,  1230,  1241,  1045,  1242,  1046,  1047,  1171,  1243,
    1048,  1170,   300,   562,  1262,  1049,  1055,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1190,  1068,  1245,  1069,  1070,
    1071,  1072,  1244,  1237,  1073,  1074,  1075,  1076,  1077,  1240,
     719,  1082,  1083,  1096,  1097,  1098,  1099,  1100,  1101,  1102,
    1103,  1104,  1110,  1113,  1114,  1115,  1116,  1139,  1140,   612,
     711,  1141,  1219,  1166,   730,  1167,  1168,  1169,  1172,  1185,
     700,  1239,  1191,  1186,  1187,  1204,  1259,  1220,  1246,  1221,
    1234,  1247,   736,  1222,  1223,  1233,  1248,  1249,   487,  1238,
     551,   704,   388,   445,   773,  1213,  1212,   314,   784,     0,
     628,   531,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     566,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     638,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   632
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1023)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     609,   610,   305,   306,   307,     1,   107,   226,     8,     1,
       1,     1,    50,    48,     1,   226,     1,     1,     1,     1,
       1,     1,     1,   224,     1,    21,    22,   228,  1050,  1051,
    1052,    27,     1,     1,     3,   226,     5,    24,   224,     1,
       1,   226,   228,    24,    31,     1,   226,     1,    17,     1,
      31,    34,   792,   793,   794,   795,   796,   797,   798,     1,
       1,   207,     1,    32,   210,    55,     1,   224,    64,    65,
      60,   228,    62,    55,    70,    71,    60,   226,    60,   226,
      62,    77,    78,    79,    75,   123,    55,   224,    57,     1,
     226,   228,    75,    62,   397,   398,     1,   226,    75,    60,
     201,     1,   405,    72,    60,    97,   409,   103,   104,    94,
      97,   414,    24,     1,   417,   226,    97,    97,    97,    60,
     207,     1,   226,   210,   427,   428,     6,     7,    97,    97,
     226,   121,    12,   118,   437,    97,   226,   440,   441,   121,
      20,   124,    94,    97,    56,   124,    26,   182,    28,    29,
      30,    63,   121,     1,     1,    35,   226,   192,     1,   226,
      40,    41,    97,    43,    44,    45,   118,    47,   124,    17,
     124,   224,   141,    85,    54,   228,   167,    89,    58,    59,
       1,   226,   124,   124,    32,    97,   226,    67,   100,   101,
     167,     1,   192,   224,    15,    16,    76,   228,    19,   224,
     226,   224,   226,   228,    84,   228,    86,    17,    88,    97,
      90,   224,    92,    93,    62,   228,   226,   224,   226,   124,
     132,   228,    32,   215,   193,   105,   529,   219,   167,   225,
     110,   111,   112,   225,   114,   115,   116,   149,   150,   119,
     225,    62,   225,   225,   225,     1,   225,   215,   225,    97,
      97,   220,    62,   215,    97,   227,   225,   225,   224,    80,
      81,    82,    83,   175,   225,   145,    87,   167,   227,   117,
      91,   151,   152,   153,   154,   155,    97,   219,   227,   218,
      36,   193,   194,   195,   225,   133,   225,   108,   109,   227,
     225,   227,    48,    49,   597,    51,    52,    53,   601,   120,
     188,   604,   224,   227,   184,   608,   228,   117,   220,   221,
       1,   224,   225,   225,   219,   125,   126,    73,   218,   227,
     225,   142,     1,     9,    10,    11,   224,   215,   208,   209,
     228,   211,   212,   213,   107,   224,   146,   217,    17,   228,
     227,   188,   222,    34,   227,   225,   196,   197,   171,   172,
     198,   196,   197,    32,   227,   227,   227,   227,   179,   227,
     227,   134,   135,   136,   137,   138,   139,   140,   215,    39,
     227,   219,   215,   227,     1,   227,   219,   225,   225,     6,
       7,   227,   224,    62,    75,    12,   227,   227,   227,   227,
     227,     4,   227,    20,   227,   227,    66,   227,    68,    26,
     227,    28,    29,    30,   225,    18,   224,   227,    35,   219,
     227,   227,    25,    40,    41,   225,    43,    44,    45,    13,
      47,   107,   227,   227,   227,   227,    39,    54,   227,   227,
     227,    58,    59,   124,   227,   227,   227,   227,   117,    33,
      67,   227,   227,   113,   227,     1,   125,   126,    42,    76,
     227,     1,   227,    66,   224,    68,   227,    84,   227,    86,
     227,    88,   227,    90,   227,    92,    93,   146,    24,   225,
     227,   122,   227,   227,   227,    69,   227,   227,   105,   227,
     227,    94,   227,   110,   111,   112,    36,   114,   115,   116,
     227,   227,   119,   163,   164,   227,   227,   227,    48,    49,
      56,    51,    52,    53,    98,    99,   227,    63,   227,   227,
     227,   227,   106,   227,   127,   227,   129,   227,   145,   227,
     227,   227,   227,    73,   151,   152,   153,   154,   155,    85,
     227,   227,   227,    89,   227,   148,     1,   131,   227,   227,
     219,    97,   227,   227,   100,   101,     1,   227,     3,   219,
       5,   164,    17,   147,   227,   167,   169,   184,   227,   122,
     173,   122,    17,   224,   107,   178,   107,    32,   181,   207,
     107,   107,   107,   186,   107,   107,   132,    32,  1187,   207,
     224,   208,   209,   207,   211,   212,   213,   200,   224,   224,
     217,   122,   205,   149,   150,   222,   227,    62,   227,   224,
      55,   227,    57,   216,   227,   227,   227,    62,     1,   227,
     223,   227,   206,   227,   207,   107,   227,    72,   227,   175,
     227,   227,    15,    16,   227,   227,    19,   227,   227,   227,
     227,   227,    97,   107,    68,   227,   227,   193,   194,   195,
       0,     1,    97,   227,     4,   227,   227,   227,   227,   227,
     227,   227,   117,   227,    14,   207,    68,    17,    18,   207,
     122,   207,   207,    23,   220,   221,   121,   107,   133,    62,
     107,   107,   107,   207,    34,   107,   107,    37,    38,   207,
     207,   107,   107,   107,   207,   227,   141,    80,    81,    82,
      83,   207,   207,   207,    87,   207,   130,   227,    91,   207,
     207,    61,   207,   122,    97,   207,    66,   207,   207,   207,
     227,   224,   122,   224,    74,   108,   109,   227,   130,    48,
     122,   227,   156,   227,   227,   207,   227,   120,   122,   107,
     164,   227,   227,   198,   227,    95,    96,   224,   193,   173,
     122,   227,   227,   227,   156,   224,   224,   227,   224,   142,
     227,   224,   164,   113,   219,   227,   227,   227,   227,   227,
     227,   173,    48,   227,   227,   220,   200,   227,   202,   203,
     130,   224,   122,   107,   207,   122,   122,   207,   207,   207,
     207,   122,   216,   143,   144,   122,   179,   122,   200,   223,
     202,   203,   122,   107,   122,   122,   122,    48,   207,   122,
     107,   161,   224,   224,   216,   107,   224,   227,   224,   226,
     224,   223,   227,   107,   174,   107,   227,   224,   224,   224,
     224,   224,   107,   183,   224,   224,   224,   187,   157,   158,
     159,   160,   224,   162,   163,   224,   165,   166,   224,   168,
     224,   170,   227,   224,   173,   224,   107,   176,   177,   178,
     224,   180,   122,   107,   107,   107,   185,   224,   122,   122,
     189,   190,   191,   207,   122,   122,   227,   122,   107,   224,
     199,   157,   158,   159,   160,   204,   162,   163,   122,   165,
     166,   122,   168,   228,   170,   122,   122,   173,   122,   122,
     176,   177,   178,   224,   180,   122,   122,   207,   107,   185,
     224,   107,   224,   189,   190,   191,   157,   158,   159,   160,
       1,   162,   163,   199,   165,   166,   224,   168,   204,   170,
     224,   224,   173,   224,   224,   176,   177,   178,   224,   180,
      21,    22,   122,   224,   185,   224,    27,   224,   189,   190,
     191,   224,   224,   224,   224,   224,   224,   224,   199,   224,
     224,   224,   224,   204,   122,   224,   224,   224,   224,   224,
     122,   122,   224,   122,   224,   224,   122,   122,   224,   122,
     122,   122,   122,    64,    65,   224,   224,   224,   224,    70,
      71,   224,   224,   122,   224,   122,    77,    78,    79,   224,
     122,   122,   224,   224,   224,   224,   224,   122,   122,   224,
     224,   224,   224,   224,   224,   207,   224,   224,   227,   224,
     224,   227,   103,   104,   224,   227,   224,   122,   122,   224,
     227,   224,   122,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   122,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   122,   224,   224,   227,
     224,   224,   227,   224,   224,   224,   107,   224,   224,   224,
     224,   224,   122,   128,   224,   128,   224,   224,  1005,   128,
     224,  1003,    74,   284,  1261,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,  1016,   224,  1227,   224,   224,
     224,   224,  1225,  1206,   224,   224,   224,   224,   224,  1217,
     491,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   214,   224,   224,   224,   224,   224,   224,   332,
     478,   224,  1111,   224,   504,   224,   224,   224,   224,   224,
     455,  1215,   224,   227,   227,   224,  1236,   224,  1229,   229,
     224,   224,   518,   229,   229,   227,   224,   224,   220,  1211,
     262,   468,   111,   164,   555,  1081,  1079,    92,   571,    -1,
     364,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     392,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   382
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   231,     0,     1,     4,    14,    17,    18,    23,    34,
      37,    38,    61,    66,    74,    95,    96,   113,   130,   143,
     144,   161,   174,   183,   187,   232,   237,   242,   266,   272,
     278,   292,   310,   333,   347,   362,   369,   373,   383,   392,
     412,   418,   424,   428,   434,   491,   506,   224,   225,   226,
     226,   311,   393,   419,   226,   429,   226,   348,   413,   334,
     226,   273,   293,   363,   226,   226,   384,   226,   226,   374,
       1,    24,    31,    97,   267,   268,   269,   270,   271,     1,
      21,    22,    27,    64,    65,    70,    71,    77,    78,    79,
     103,   104,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   226,   226,   226,     1,
      60,   425,   426,   427,   226,     1,     6,     7,    12,    20,
      26,    28,    29,    30,    35,    40,    41,    43,    44,    45,
      47,    54,    58,    59,    67,    76,    84,    86,    88,    90,
      92,    93,   105,   110,   111,   112,   114,   115,   116,   119,
     145,   151,   152,   153,   154,   155,   184,   208,   209,   211,
     212,   213,   217,   222,   435,   436,   437,   438,   439,   440,
     441,   442,   443,   444,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,   480,
     484,   488,   489,   490,   226,   226,   226,     1,    94,   118,
     238,   239,   240,   241,   226,   226,   226,     1,    36,    48,
      49,    51,    52,    53,    73,   507,   508,   509,   510,   511,
     512,   513,   514,   515,     1,    24,    56,    63,    85,    89,
      97,   100,   101,   132,   149,   150,   175,   193,   194,   195,
     220,   221,   243,   244,   245,   246,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   226,     1,   218,   279,   280,   281,   282,   283,     1,
      97,   370,   371,   372,   226,   224,   227,   227,   227,   225,
     268,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   225,   493,     1,    15,    16,    19,    62,
      80,    81,    82,    83,    87,    91,    97,   108,   109,   120,
     142,   179,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
       1,     3,     5,    17,    32,    55,    57,    62,    72,    97,
     121,   141,   193,   220,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   407,   408,   409,   410,   411,     1,
      60,   124,   420,   421,   422,   423,   227,   225,   426,     1,
      97,   124,   430,   431,   432,   433,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   485,   227,   481,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   225,   436,     1,    17,    32,    62,
     117,   125,   126,   146,   219,   349,   350,   351,   352,   353,
     354,   355,   359,   360,   361,     1,   124,   219,   414,   415,
     416,   417,     1,    55,    60,    62,   121,   335,   339,   340,
     341,   345,   346,   224,   227,   227,   225,   239,     1,    75,
     167,   274,   275,   276,   277,     1,    17,    32,    62,    97,
     117,   133,   198,   219,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   306,     1,    34,    75,   124,   364,   365,
     366,   367,   368,   227,   227,   227,   227,   227,   227,   227,
     225,   508,   224,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     225,   244,     1,    97,   215,   385,   386,   387,   388,   224,
     227,   225,   280,   167,   227,   225,   371,     1,    97,   215,
     219,   375,   376,   377,   378,   379,   122,   122,   122,   224,
     107,   107,   207,   107,   107,   234,   234,   234,   107,   107,
     107,   207,   207,   224,   224,   227,   227,   227,   330,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   225,   313,   224,   227,   227,   227,   227,   227,   227,
     404,   227,   227,   227,   227,   227,   227,   225,   395,   227,
     227,   225,   421,   122,   224,   227,   227,   225,   431,   207,
     234,   234,   107,   207,   207,   107,   122,   207,   234,   207,
     107,   107,   234,   107,   207,   207,   207,   234,   107,   107,
     234,   107,   107,   107,   107,   207,   227,   207,   227,   207,
     234,   234,   207,   207,   207,   207,   210,   207,   210,   207,
     207,   122,   234,   207,   207,   234,   234,   207,   207,   224,
     224,   227,   227,   356,   227,   227,   227,   227,   227,   225,
     350,   227,   227,   225,   415,   224,   227,   227,   336,   227,
     225,   340,   122,   122,   224,   224,   227,   227,   225,   275,
     224,   227,   227,   307,   227,   227,   227,   303,   227,   225,
     295,   224,   227,   227,   227,   225,   365,   207,   207,   122,
     207,   207,   207,   234,   224,   122,   207,   122,   107,   107,
     122,   122,   122,   122,   122,   122,   107,   122,   196,   197,
     247,   248,   196,   197,   249,   250,   122,   122,   224,   224,
     227,   389,   225,   386,   207,   224,   226,   122,   224,   224,
     227,   380,   227,   225,   376,   224,   224,   224,   224,   224,
     224,   224,   134,   135,   136,   137,   138,   139,   140,   233,
     234,   224,   224,   224,   224,   224,   224,   224,   224,   107,
     107,   234,   227,   107,   107,   234,   107,   107,   234,   122,
     107,   107,   234,   107,   236,   236,   224,   122,   171,   172,
     122,   207,   122,   122,   227,   122,   122,   107,   122,   122,
     122,   224,   122,   122,   224,   224,   122,   122,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,    48,   157,   158,   159,
     160,   162,   163,   165,   166,   168,   170,   173,   176,   177,
     178,   180,   185,   189,   190,   191,   199,   204,   486,   487,
     224,    48,   157,   158,   159,   160,   162,   163,   165,   166,
     168,   170,   173,   176,   177,   178,   180,   185,   189,   190,
     191,   199,   204,   482,   483,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   122,   207,   227,   122,   107,
     122,   122,   122,   224,   122,   122,   224,   122,   122,   227,
     107,   343,   344,   224,   224,   224,   122,   122,   224,   122,
     207,   227,   122,   122,   122,   227,   122,   224,   122,   122,
     122,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   228,   224,   228,   224,   224,   122,   227,
     224,   224,     1,    97,   188,   215,   284,   285,   286,   287,
     288,   224,   122,   227,   122,   224,   233,   233,   233,   233,
     233,   233,   233,   224,   224,   224,    50,   123,   331,   332,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
       9,    10,    11,   235,   236,   224,   224,   224,   224,   224,
     224,   224,   224,   224,     8,   192,   405,   406,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   228,
     224,   228,   224,   224,    13,    33,    42,    69,    98,    99,
     106,   131,   147,   206,   357,   358,   224,   224,   224,   224,
     224,   224,   224,   224,   224,    48,   182,   192,   337,   338,
     214,   228,   342,   224,   224,   224,   224,     4,    18,    25,
      39,    66,    68,    94,   127,   129,   148,   164,   169,   173,
     178,   181,   186,   200,   205,   216,   223,   308,   309,   224,
     224,   224,    48,   157,   158,   159,   160,   162,   163,   165,
     166,   168,   170,   173,   176,   177,   178,   180,   185,   189,
     190,   191,   199,   204,   304,   305,   224,   224,   224,   224,
     248,   250,   224,    68,   130,   156,   164,   173,   200,   202,
     203,   216,   223,   390,   391,   224,   227,   227,   289,   225,
     285,   224,    68,   130,   156,   164,   173,   200,   202,   203,
     216,   223,   381,   382,   224,   224,   228,   235,   235,   235,
     224,   228,   487,   483,   224,   228,   224,   228,   107,   344,
     224,   229,   229,   229,   224,   228,   224,   228,   224,   228,
     122,   201,   236,   227,   224,   224,   228,   332,   406,   358,
     338,   128,   128,   128,   309,   305,   391,   224,   224,   224,
      39,    66,    68,   113,   163,   164,   219,   290,   291,   382,
     224,   228,   291
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
        case 27:
/* Line 1787 of yacc.c  */
#line 396 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 398 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 402 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 406 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 414 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 418 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 422 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 426 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 431 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 433 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 434 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 455 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 481 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 487 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 496 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 502 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 510 "conf_parser.y"
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

  case 83:
/* Line 1787 of yacc.c  */
#line 552 "conf_parser.y"
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

  case 84:
/* Line 1787 of yacc.c  */
#line 611 "conf_parser.y"
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

  case 85:
/* Line 1787 of yacc.c  */
#line 639 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 647 "conf_parser.y"
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

  case 87:
/* Line 1787 of yacc.c  */
#line 662 "conf_parser.y"
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

  case 88:
/* Line 1787 of yacc.c  */
#line 677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 89:
/* Line 1787 of yacc.c  */
#line 686 "conf_parser.y"
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

  case 90:
/* Line 1787 of yacc.c  */
#line 700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 709 "conf_parser.y"
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

  case 92:
/* Line 1787 of yacc.c  */
#line 737 "conf_parser.y"
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

  case 93:
/* Line 1787 of yacc.c  */
#line 767 "conf_parser.y"
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

  case 94:
/* Line 1787 of yacc.c  */
#line 792 "conf_parser.y"
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

  case 95:
/* Line 1787 of yacc.c  */
#line 814 "conf_parser.y"
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

  case 96:
/* Line 1787 of yacc.c  */
#line 836 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 885 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.file.buf[0])
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
    motd_add(ptr->data, block_state.file.buf);
}
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 929 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_set_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
    break;

  case 131:
/* Line 1787 of yacc.c  */
#line 949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 957 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 960 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1006 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1013 "conf_parser.y"
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

  case 158:
/* Line 1787 of yacc.c  */
#line 1088 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1094 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1100 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1106 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1140 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1281 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1285 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1289 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1293 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1297 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1301 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1309 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1313 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1317 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1321 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1331 "conf_parser.y"
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

  case 218:
/* Line 1787 of yacc.c  */
#line 1343 "conf_parser.y"
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

  case 238:
/* Line 1787 of yacc.c  */
#line 1409 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 239:
/* Line 1787 of yacc.c  */
#line 1415 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1421 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1427 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1457 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1463 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1482 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1506 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 257:
/* Line 1787 of yacc.c  */
#line 1513 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 1517 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1527 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1533 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 265:
/* Line 1787 of yacc.c  */
#line 1539 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1543 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1547 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1555 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1560 "conf_parser.y"
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

  case 280:
/* Line 1787 of yacc.c  */
#line 1574 "conf_parser.y"
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

  case 281:
/* Line 1787 of yacc.c  */
#line 1594 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1600 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1609 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1613 "conf_parser.y"
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

  case 296:
/* Line 1787 of yacc.c  */
#line 1656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 297:
/* Line 1787 of yacc.c  */
#line 1662 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1668 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1674 "conf_parser.y"
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

  case 300:
/* Line 1787 of yacc.c  */
#line 1685 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 304:
/* Line 1787 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1708 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1728 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1734 "conf_parser.y"
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

  case 315:
/* Line 1787 of yacc.c  */
#line 1748 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1757 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1770 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1777 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1794 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 333:
/* Line 1787 of yacc.c  */
#line 1815 "conf_parser.y"
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

  case 334:
/* Line 1787 of yacc.c  */
#line 1830 "conf_parser.y"
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

  case 335:
/* Line 1787 of yacc.c  */
#line 1841 "conf_parser.y"
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

  case 342:
/* Line 1787 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1864 "conf_parser.y"
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

  case 344:
/* Line 1787 of yacc.c  */
#line 1883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 1890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 1894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 1898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 1906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 1959 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 1965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 1976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 1984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2004 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2017 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2025 "conf_parser.y"
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

  case 398:
/* Line 1787 of yacc.c  */
#line 2091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 399:
/* Line 1787 of yacc.c  */
#line 2097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2109 "conf_parser.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 2122 "conf_parser.y"
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

  case 403:
/* Line 1787 of yacc.c  */
#line 2135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2145 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 2153 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 412:
/* Line 1787 of yacc.c  */
#line 2169 "conf_parser.y"
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

  case 413:
/* Line 1787 of yacc.c  */
#line 2180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2198 "conf_parser.y"
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

  case 417:
/* Line 1787 of yacc.c  */
#line 2213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2217 "conf_parser.y"
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

  case 424:
/* Line 1787 of yacc.c  */
#line 2242 "conf_parser.y"
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

  case 425:
/* Line 1787 of yacc.c  */
#line 2262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 426:
/* Line 1787 of yacc.c  */
#line 2271 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 427:
/* Line 1787 of yacc.c  */
#line 2275 "conf_parser.y"
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

  case 433:
/* Line 1787 of yacc.c  */
#line 2301 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 434:
/* Line 1787 of yacc.c  */
#line 2307 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 440:
/* Line 1787 of yacc.c  */
#line 2321 "conf_parser.y"
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

  case 441:
/* Line 1787 of yacc.c  */
#line 2338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 442:
/* Line 1787 of yacc.c  */
#line 2342 "conf_parser.y"
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

  case 448:
/* Line 1787 of yacc.c  */
#line 2364 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 449:
/* Line 1787 of yacc.c  */
#line 2370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2414 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2419 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2425 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2437 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2442 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2447 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2452 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2457 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2462 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2467 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2472 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2482 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2507 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2513 "conf_parser.y"
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

  case 522:
/* Line 1787 of yacc.c  */
#line 2524 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2529 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2534 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2539 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2544 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2549 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2643 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2674 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2677 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2686 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2689 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2748 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2754 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2763 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2766 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2769 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2775 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 596:
/* Line 1787 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 597:
/* Line 1787 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 598:
/* Line 1787 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2854 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2859 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2874 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 642:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 644:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 645:
/* Line 1787 of yacc.c  */
#line 2935 "conf_parser.y"
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

  case 646:
/* Line 1787 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 647:
/* Line 1787 of yacc.c  */
#line 2955 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6834 "conf_parser.c"
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


