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
    cert,
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
#line 183 "conf_parser.c"

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
     T_CLUSTER = 415,
     T_DEAF = 416,
     T_DEBUG = 417,
     T_DLINE = 418,
     T_EXTERNAL = 419,
     T_FARCONNECT = 420,
     T_FILE = 421,
     T_FINGERPRINT = 422,
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
#define T_CLUSTER 415
#define T_DEAF 416
#define T_DEBUG 417
#define T_DLINE 418
#define T_EXTERNAL 419
#define T_FARCONNECT 420
#define T_FILE 421
#define T_FINGERPRINT 422
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
#line 140 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 678 "conf_parser.c"
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
#line 706 "conf_parser.c"

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
#define YYLAST   1221

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  288
/* YYNRULES -- Number of rules.  */
#define YYNRULES  648
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1270

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
     455,   457,   459,   461,   463,   465,   467,   469,   471,   474,
     479,   484,   489,   494,   499,   504,   509,   510,   516,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   554,   556,   558,   560,
     562,   564,   565,   571,   575,   577,   581,   583,   587,   589,
     593,   595,   597,   599,   601,   603,   605,   607,   609,   611,
     613,   615,   617,   619,   621,   623,   625,   627,   629,   630,
     637,   640,   642,   644,   646,   648,   650,   652,   654,   656,
     658,   660,   662,   664,   666,   668,   670,   672,   674,   677,
     682,   687,   692,   697,   702,   707,   712,   717,   722,   727,
     732,   737,   742,   747,   752,   753,   759,   763,   765,   767,
     769,   770,   777,   778,   784,   788,   790,   792,   794,   796,
     799,   801,   803,   805,   807,   809,   812,   813,   819,   823,
     825,   827,   831,   836,   841,   842,   849,   852,   854,   856,
     858,   860,   862,   864,   866,   868,   870,   873,   878,   883,
     888,   893,   894,   900,   904,   906,   908,   910,   912,   914,
     916,   918,   920,   922,   924,   926,   931,   936,   941,   942,
     949,   952,   954,   956,   958,   960,   963,   968,   973,   978,
     984,   987,   989,   991,   993,   998,   999,  1006,  1009,  1011,
    1013,  1015,  1017,  1020,  1025,  1030,  1031,  1037,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1057,  1059,  1061,  1063,
    1064,  1071,  1074,  1076,  1078,  1080,  1083,  1088,  1089,  1095,
    1099,  1101,  1103,  1105,  1107,  1109,  1111,  1113,  1115,  1117,
    1119,  1121,  1122,  1129,  1132,  1134,  1136,  1138,  1140,  1142,
    1144,  1146,  1148,  1150,  1152,  1154,  1156,  1158,  1160,  1162,
    1165,  1170,  1175,  1180,  1185,  1190,  1195,  1200,  1205,  1210,
    1211,  1217,  1221,  1223,  1225,  1227,  1232,  1237,  1242,  1247,
    1252,  1253,  1260,  1263,  1265,  1267,  1269,  1271,  1276,  1281,
    1282,  1289,  1292,  1294,  1296,  1298,  1300,  1305,  1310,  1316,
    1319,  1321,  1323,  1325,  1330,  1331,  1338,  1341,  1343,  1345,
    1347,  1349,  1354,  1359,  1365,  1368,  1370,  1372,  1374,  1376,
    1378,  1380,  1382,  1384,  1386,  1388,  1390,  1392,  1394,  1396,
    1398,  1400,  1402,  1404,  1406,  1408,  1410,  1412,  1414,  1416,
    1418,  1420,  1422,  1424,  1426,  1428,  1430,  1432,  1434,  1436,
    1438,  1440,  1442,  1444,  1446,  1448,  1450,  1452,  1454,  1456,
    1458,  1460,  1462,  1464,  1466,  1471,  1476,  1481,  1486,  1491,
    1496,  1501,  1506,  1511,  1516,  1521,  1526,  1531,  1536,  1541,
    1546,  1551,  1556,  1561,  1566,  1571,  1576,  1581,  1586,  1591,
    1596,  1601,  1606,  1611,  1616,  1621,  1626,  1631,  1636,  1641,
    1646,  1651,  1656,  1661,  1666,  1671,  1676,  1681,  1686,  1687,
    1693,  1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,
    1715,  1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,
    1735,  1737,  1739,  1741,  1742,  1748,  1752,  1754,  1756,  1758,
    1760,  1762,  1764,  1766,  1768,  1770,  1772,  1774,  1776,  1778,
    1780,  1782,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1801,
    1806,  1811,  1817,  1820,  1822,  1824,  1826,  1828,  1830,  1832,
    1834,  1836,  1838,  1840,  1842,  1844,  1846,  1848,  1853,  1858,
    1863,  1868,  1873,  1878,  1883,  1888,  1893,  1898,  1903,  1908,
    1914,  1917,  1919,  1921,  1923,  1925,  1927,  1929,  1931,  1933,
    1935,  1937,  1942,  1947,  1952,  1957,  1962,  1967,  1972
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     231,     0,    -1,    -1,   231,   232,    -1,   266,    -1,   278,
      -1,   292,    -1,   492,    -1,   311,    -1,   334,    -1,   348,
      -1,   242,    -1,   507,    -1,   363,    -1,   370,    -1,   374,
      -1,   384,    -1,   393,    -1,   414,    -1,   420,    -1,   426,
      -1,   436,    -1,   430,    -1,   237,    -1,   272,    -1,     1,
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
       1,   224,    -1,    75,   227,   122,   224,    -1,   166,   227,
     122,   224,    -1,   174,   226,   279,   225,   224,    -1,   279,
     280,    -1,   280,    -1,   281,    -1,   282,    -1,     1,   224,
      -1,   218,   227,   207,   224,    -1,    -1,   283,   166,   226,
     284,   225,   224,    -1,   284,   285,    -1,   285,    -1,   286,
      -1,   288,    -1,   287,    -1,     1,   224,    -1,    97,   227,
     122,   224,    -1,   188,   227,   236,   224,    -1,   188,   227,
     201,   224,    -1,    -1,   215,   289,   227,   290,   224,    -1,
     290,   228,   291,    -1,   291,    -1,   219,    -1,   113,    -1,
      39,    -1,   163,    -1,    68,    -1,    66,    -1,   162,    -1,
      -1,   113,   293,   226,   294,   225,   224,    -1,   294,   295,
      -1,   295,    -1,   296,    -1,   297,    -1,   298,    -1,   303,
      -1,   302,    -1,   299,    -1,   300,    -1,   301,    -1,   307,
      -1,     1,   224,    -1,    97,   227,   122,   224,    -1,   219,
     227,   122,   224,    -1,   117,   227,   122,   224,    -1,    32,
     227,   207,   224,    -1,   133,   227,   122,   224,    -1,   167,
     227,   122,   224,    -1,    17,   227,   122,   224,    -1,    -1,
     198,   304,   227,   305,   224,    -1,   305,   228,   306,    -1,
     306,    -1,   157,    -1,   159,    -1,   161,    -1,   162,    -1,
     168,    -1,    48,    -1,   189,    -1,   176,    -1,   180,    -1,
     199,    -1,   191,    -1,   164,    -1,   178,    -1,   185,    -1,
     170,    -1,   204,    -1,   190,    -1,   158,    -1,   173,    -1,
     177,    -1,   165,    -1,    -1,    62,   308,   227,   309,   224,
      -1,   309,   228,   310,    -1,   310,    -1,    66,   229,   128,
      -1,    66,    -1,    18,   229,   128,    -1,    18,    -1,   148,
     229,   128,    -1,   148,    -1,    68,    -1,   216,    -1,   163,
      -1,   200,    -1,   223,    -1,    39,    -1,    25,    -1,   181,
      -1,   127,    -1,     4,    -1,   178,    -1,   169,    -1,   205,
      -1,   173,    -1,   129,    -1,   186,    -1,    94,    -1,    -1,
      17,   312,   226,   313,   225,   224,    -1,   313,   314,    -1,
     314,    -1,   315,    -1,   325,    -1,   326,    -1,   316,    -1,
     327,    -1,   317,    -1,   318,    -1,   319,    -1,   320,    -1,
     321,    -1,   322,    -1,   323,    -1,   324,    -1,   328,    -1,
     329,    -1,   330,    -1,     1,   224,    -1,    97,   227,   122,
     224,    -1,   120,   227,   234,   224,    -1,   109,   227,   107,
     224,    -1,    19,   227,   234,   224,    -1,    87,   227,   107,
     224,    -1,    80,   227,   107,   224,    -1,    83,   227,   107,
     224,    -1,    81,   227,   107,   224,    -1,   142,   227,   236,
     224,    -1,   179,   227,   236,   224,    -1,    15,   227,   107,
     224,    -1,    16,   227,   107,   224,    -1,   108,   227,   107,
     224,    -1,    91,   227,   234,   224,    -1,    82,   227,   234,
     224,    -1,    -1,    62,   331,   227,   332,   224,    -1,   332,
     228,   333,    -1,   333,    -1,   123,    -1,    50,    -1,    -1,
      74,   335,   226,   340,   225,   224,    -1,    -1,    62,   337,
     227,   338,   224,    -1,   338,   228,   339,    -1,   339,    -1,
     192,    -1,    48,    -1,   182,    -1,   340,   341,    -1,   341,
      -1,   342,    -1,   336,    -1,   346,    -1,   347,    -1,     1,
     224,    -1,    -1,   121,   227,   344,   343,   224,    -1,   344,
     228,   345,    -1,   345,    -1,   107,    -1,   107,   214,   107,
      -1,    60,   227,   122,   224,    -1,    55,   227,   122,   224,
      -1,    -1,    61,   349,   226,   350,   225,   224,    -1,   350,
     351,    -1,   351,    -1,   352,    -1,   353,    -1,   354,    -1,
     356,    -1,   360,    -1,   361,    -1,   362,    -1,   355,    -1,
       1,   224,    -1,   219,   227,   122,   224,    -1,   117,   227,
     122,   224,    -1,    17,   227,   122,   224,    -1,    32,   227,
     207,   224,    -1,    -1,    62,   357,   227,   358,   224,    -1,
     358,   228,   359,    -1,   359,    -1,   147,    -1,    33,    -1,
      69,    -1,    98,    -1,    13,    -1,   106,    -1,    42,    -1,
     131,    -1,   206,    -1,    99,    -1,   146,   227,   122,   224,
      -1,   126,   227,   122,   224,    -1,   125,   227,   107,   224,
      -1,    -1,   130,   364,   226,   365,   225,   224,    -1,   365,
     366,    -1,   366,    -1,   367,    -1,   368,    -1,   369,    -1,
       1,   224,    -1,    75,   227,   122,   224,    -1,   124,   227,
     122,   224,    -1,    34,   227,   122,   224,    -1,   183,   226,
     371,   225,   224,    -1,   371,   372,    -1,   372,    -1,   373,
      -1,     1,    -1,    97,   227,   122,   224,    -1,    -1,   187,
     375,   226,   376,   225,   224,    -1,   376,   377,    -1,   377,
      -1,   378,    -1,   379,    -1,   380,    -1,     1,   224,    -1,
      97,   227,   122,   224,    -1,   219,   227,   122,   224,    -1,
      -1,   215,   381,   227,   382,   224,    -1,   382,   228,   383,
      -1,   383,    -1,    68,    -1,   216,    -1,   163,    -1,   200,
      -1,   223,    -1,   203,    -1,   130,    -1,   202,    -1,   173,
      -1,   156,    -1,    -1,   160,   385,   226,   386,   225,   224,
      -1,   386,   387,    -1,   387,    -1,   388,    -1,   389,    -1,
       1,   224,    -1,    97,   227,   122,   224,    -1,    -1,   215,
     390,   227,   391,   224,    -1,   391,   228,   392,    -1,   392,
      -1,    68,    -1,   216,    -1,   163,    -1,   200,    -1,   223,
      -1,   203,    -1,   130,    -1,   202,    -1,   173,    -1,   156,
      -1,    -1,    18,   394,   226,   395,   225,   224,    -1,   395,
     396,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     400,    -1,   401,    -1,   402,    -1,   404,    -1,   403,    -1,
     413,    -1,   405,    -1,   410,    -1,   411,    -1,   412,    -1,
     409,    -1,     1,   224,    -1,    97,   227,   122,   224,    -1,
      55,   227,   122,   224,    -1,   220,   227,   122,   224,    -1,
     141,   227,   122,   224,    -1,     3,   227,   122,   224,    -1,
     167,   227,   122,   224,    -1,   121,   227,   107,   224,    -1,
       5,   227,   171,   224,    -1,     5,   227,   172,   224,    -1,
      -1,    62,   406,   227,   407,   224,    -1,   407,   228,   408,
      -1,   408,    -1,     8,    -1,   192,    -1,    32,   227,   207,
     224,    -1,    57,   227,   122,   224,    -1,    72,   227,   122,
     224,    -1,    17,   227,   122,   224,    -1,   193,   227,   122,
     224,    -1,    -1,    66,   415,   226,   416,   225,   224,    -1,
     416,   417,    -1,   417,    -1,   418,    -1,   419,    -1,     1,
      -1,   219,   227,   122,   224,    -1,   124,   227,   122,   224,
      -1,    -1,    23,   421,   226,   422,   225,   224,    -1,   422,
     423,    -1,   423,    -1,   424,    -1,   425,    -1,     1,    -1,
      60,   227,   122,   224,    -1,   124,   227,   122,   224,    -1,
      34,   226,   427,   225,   224,    -1,   427,   428,    -1,   428,
      -1,   429,    -1,     1,    -1,    60,   227,   122,   224,    -1,
      -1,    37,   431,   226,   432,   225,   224,    -1,   432,   433,
      -1,   433,    -1,   434,    -1,   435,    -1,     1,    -1,    97,
     227,   122,   224,    -1,   124,   227,   122,   224,    -1,    38,
     226,   437,   225,   224,    -1,   437,   438,    -1,   438,    -1,
     447,    -1,   448,    -1,   449,    -1,   450,    -1,   451,    -1,
     452,    -1,   453,    -1,   454,    -1,   455,    -1,   456,    -1,
     446,    -1,   458,    -1,   459,    -1,   473,    -1,   461,    -1,
     463,    -1,   465,    -1,   464,    -1,   468,    -1,   462,    -1,
     469,    -1,   470,    -1,   471,    -1,   472,    -1,   485,    -1,
     474,    -1,   475,    -1,   476,    -1,   481,    -1,   466,    -1,
     467,    -1,   491,    -1,   489,    -1,   490,    -1,   480,    -1,
     457,    -1,   478,    -1,   479,    -1,   445,    -1,   440,    -1,
     441,    -1,   442,    -1,   443,    -1,   444,    -1,   460,    -1,
     439,    -1,   477,    -1,     1,    -1,    90,   227,   107,   224,
      -1,    41,   227,   207,   224,    -1,    40,   227,   234,   224,
      -1,    45,   227,   234,   224,    -1,    43,   227,   107,   224,
      -1,    44,   227,   107,   224,    -1,   209,   227,   207,   224,
      -1,    67,   227,   234,   224,    -1,    54,   227,   207,   224,
      -1,    58,   227,   207,   224,    -1,    35,   227,   207,   224,
      -1,     6,   227,   207,   224,    -1,    86,   227,   234,   224,
      -1,    84,   227,   107,   224,    -1,    76,   227,   107,   224,
      -1,     7,   227,   234,   224,    -1,   213,   227,   234,   224,
      -1,   212,   227,   234,   224,    -1,    47,   227,   107,   224,
      -1,    59,   227,   207,   224,    -1,   222,   227,   207,   224,
      -1,   151,   227,   207,   224,    -1,   154,   227,   207,   224,
      -1,   155,   227,   207,   224,    -1,   153,   227,   207,   224,
      -1,   153,   227,   210,   224,    -1,   152,   227,   207,   224,
      -1,   152,   227,   210,   224,    -1,   115,   227,   234,   224,
      -1,    12,   227,   234,   224,    -1,   114,   227,   207,   224,
      -1,   116,   227,   234,   224,    -1,   145,   227,   207,   224,
      -1,   105,   227,   207,   224,    -1,   211,   227,   207,   224,
      -1,   111,   227,   207,   224,    -1,    29,   227,   107,   224,
      -1,    88,   227,   107,   224,    -1,   217,   227,   207,   224,
      -1,    30,   227,   122,   224,    -1,   184,   227,   122,   224,
      -1,   119,   227,   207,   224,    -1,    26,   227,   207,   224,
      -1,   208,   227,   234,   224,    -1,    -1,   112,   482,   227,
     483,   224,    -1,   483,   228,   484,    -1,   484,    -1,   157,
      -1,   159,    -1,   161,    -1,   162,    -1,   168,    -1,    48,
      -1,   189,    -1,   176,    -1,   180,    -1,   199,    -1,   191,
      -1,   164,    -1,   178,    -1,   185,    -1,   170,    -1,   204,
      -1,   190,    -1,   158,    -1,   173,    -1,   177,    -1,   165,
      -1,    -1,   110,   486,   227,   487,   224,    -1,   487,   228,
     488,    -1,   488,    -1,   157,    -1,   159,    -1,   161,    -1,
     162,    -1,   168,    -1,   189,    -1,    48,    -1,   176,    -1,
     180,    -1,   199,    -1,   191,    -1,   164,    -1,   178,    -1,
     185,    -1,   170,    -1,   204,    -1,   190,    -1,   158,    -1,
     173,    -1,   177,    -1,   165,    -1,    92,   227,   107,   224,
      -1,    93,   227,   107,   224,    -1,    20,   227,   107,   224,
      -1,    14,   226,   493,   225,   224,    -1,   493,   494,    -1,
     494,    -1,   500,    -1,   496,    -1,   497,    -1,   498,    -1,
     499,    -1,   501,    -1,   502,    -1,   503,    -1,   504,    -1,
     505,    -1,   506,    -1,   495,    -1,     1,    -1,    27,   227,
     207,   224,    -1,    70,   227,   234,   224,    -1,    71,   227,
     234,   224,    -1,    79,   227,   107,   224,    -1,    78,   227,
     107,   224,    -1,    77,   227,   107,   224,    -1,    22,   227,
     107,   224,    -1,    21,   227,   107,   224,    -1,   103,   227,
     207,   224,    -1,   104,   227,   207,   224,    -1,    64,   227,
     107,   224,    -1,    65,   227,   234,   224,    -1,   143,   226,
     508,   225,   224,    -1,   508,   509,    -1,   509,    -1,   510,
      -1,   511,    -1,   512,    -1,   513,    -1,   515,    -1,   516,
      -1,   514,    -1,   517,    -1,     1,    -1,    36,   227,   207,
     224,    -1,    28,   227,   207,   224,    -1,    52,   227,   207,
     224,    -1,    53,   227,   207,   224,    -1,    49,   227,   122,
     224,    -1,    73,   227,   234,   224,    -1,    48,   227,   207,
     224,    -1,    51,   227,   207,   224,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   367,   367,   368,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   383,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   397,   397,   398,
     402,   406,   410,   414,   418,   422,   426,   432,   432,   433,
     434,   435,   436,   443,   446,   446,   447,   447,   447,   449,
     455,   462,   464,   464,   465,   465,   466,   466,   467,   467,
     468,   468,   469,   469,   470,   470,   471,   471,   472,   472,
     473,   474,   477,   478,   480,   480,   481,   487,   495,   495,
     496,   502,   510,   552,   611,   639,   647,   662,   677,   686,
     700,   709,   737,   767,   792,   814,   836,   845,   847,   847,
     848,   848,   849,   849,   851,   860,   869,   882,   881,   899,
     899,   900,   900,   900,   902,   908,   917,   918,   918,   920,
     920,   921,   923,   930,   930,   943,   944,   946,   946,   947,
     947,   949,   957,   960,   966,   965,   971,   971,   972,   976,
     980,   984,   988,   992,   996,  1007,  1006,  1086,  1086,  1087,
    1087,  1087,  1088,  1088,  1088,  1089,  1089,  1090,  1090,  1092,
    1098,  1104,  1110,  1121,  1127,  1133,  1140,  1139,  1145,  1145,
    1146,  1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,
    1186,  1190,  1194,  1198,  1202,  1206,  1210,  1214,  1218,  1222,
    1226,  1233,  1232,  1238,  1238,  1239,  1243,  1247,  1251,  1255,
    1259,  1263,  1267,  1271,  1275,  1279,  1283,  1287,  1291,  1295,
    1299,  1303,  1307,  1311,  1315,  1319,  1323,  1327,  1338,  1337,
    1398,  1398,  1399,  1400,  1400,  1401,  1402,  1403,  1404,  1405,
    1406,  1407,  1408,  1409,  1409,  1410,  1411,  1412,  1413,  1415,
    1421,  1427,  1433,  1439,  1445,  1451,  1457,  1463,  1469,  1476,
    1482,  1488,  1494,  1503,  1513,  1512,  1518,  1518,  1519,  1523,
    1534,  1533,  1540,  1539,  1544,  1544,  1545,  1549,  1553,  1559,
    1559,  1560,  1560,  1560,  1560,  1560,  1562,  1562,  1564,  1564,
    1566,  1580,  1600,  1606,  1616,  1615,  1657,  1657,  1658,  1658,
    1658,  1658,  1659,  1659,  1659,  1660,  1660,  1662,  1668,  1674,
    1680,  1692,  1691,  1697,  1697,  1698,  1702,  1706,  1710,  1714,
    1718,  1722,  1726,  1730,  1734,  1740,  1754,  1763,  1777,  1776,
    1791,  1791,  1792,  1792,  1792,  1792,  1794,  1800,  1806,  1816,
    1818,  1818,  1819,  1819,  1821,  1837,  1836,  1861,  1861,  1862,
    1862,  1862,  1862,  1864,  1870,  1890,  1889,  1895,  1895,  1896,
    1900,  1904,  1908,  1912,  1916,  1920,  1924,  1928,  1932,  1942,
    1941,  1962,  1962,  1963,  1963,  1963,  1965,  1972,  1971,  1977,
    1977,  1978,  1982,  1986,  1990,  1994,  1998,  2002,  2006,  2010,
    2014,  2024,  2023,  2093,  2093,  2094,  2094,  2094,  2095,  2095,
    2095,  2096,  2096,  2096,  2097,  2097,  2097,  2098,  2098,  2099,
    2101,  2107,  2113,  2119,  2132,  2145,  2151,  2157,  2161,  2170,
    2169,  2174,  2174,  2175,  2179,  2185,  2196,  2202,  2208,  2214,
    2230,  2229,  2255,  2255,  2256,  2256,  2256,  2258,  2278,  2288,
    2287,  2314,  2314,  2315,  2315,  2315,  2317,  2323,  2332,  2334,
    2334,  2335,  2335,  2337,  2355,  2354,  2377,  2377,  2378,  2378,
    2378,  2380,  2386,  2395,  2398,  2398,  2399,  2399,  2400,  2400,
    2401,  2401,  2402,  2402,  2403,  2403,  2404,  2405,  2406,  2406,
    2407,  2407,  2408,  2408,  2409,  2409,  2410,  2410,  2411,  2411,
    2412,  2412,  2413,  2413,  2414,  2414,  2415,  2415,  2416,  2416,
    2417,  2417,  2418,  2419,  2420,  2420,  2421,  2421,  2422,  2423,
    2424,  2425,  2425,  2426,  2429,  2434,  2440,  2446,  2452,  2457,
    2462,  2467,  2472,  2477,  2482,  2487,  2492,  2497,  2502,  2507,
    2512,  2517,  2523,  2534,  2539,  2544,  2549,  2554,  2559,  2562,
    2567,  2570,  2575,  2580,  2585,  2590,  2595,  2600,  2605,  2610,
    2615,  2620,  2625,  2630,  2639,  2648,  2653,  2658,  2664,  2663,
    2668,  2668,  2669,  2672,  2675,  2678,  2681,  2684,  2687,  2690,
    2693,  2696,  2699,  2702,  2705,  2708,  2711,  2714,  2717,  2720,
    2723,  2726,  2729,  2735,  2734,  2739,  2739,  2740,  2743,  2746,
    2749,  2752,  2755,  2758,  2761,  2764,  2767,  2770,  2773,  2776,
    2779,  2782,  2785,  2788,  2791,  2794,  2797,  2800,  2805,  2810,
    2815,  2824,  2827,  2827,  2828,  2829,  2829,  2830,  2830,  2831,
    2832,  2833,  2834,  2835,  2835,  2836,  2836,  2838,  2843,  2848,
    2853,  2858,  2863,  2868,  2873,  2878,  2883,  2888,  2893,  2901,
    2904,  2904,  2905,  2905,  2906,  2907,  2908,  2909,  2909,  2910,
    2911,  2913,  2919,  2925,  2931,  2937,  2946,  2960,  2966
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
  "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FINGERPRINT", "T_FULL", "T_GLOBOPS",
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
  "oper_encrypted", "oper_rsa_public_key_file", "oper_fingerprint",
  "oper_class", "oper_umodes", "$@5", "oper_umodes_items",
  "oper_umodes_item", "oper_flags", "$@6", "oper_flags_items",
  "oper_flags_item", "class_entry", "$@7", "class_items", "class_item",
  "class_name", "class_ping_time", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq", "class_recvq",
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
  "connect_accept_password", "connect_fingerprint", "connect_port",
  "connect_aftype", "connect_flags", "$@20", "connect_flags_items",
  "connect_flags_item", "connect_encrypted", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_ssl_cipher_list",
  "kill_entry", "$@21", "kill_items", "kill_item", "kill_user",
  "kill_reason", "deny_entry", "$@22", "deny_items", "deny_item",
  "deny_ip", "deny_reason", "exempt_entry", "exempt_items", "exempt_item",
  "exempt_ip", "gecos_entry", "$@23", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_max_watch", "general_gline_enable",
  "general_gline_duration", "general_gline_request_duration",
  "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_hide_spoof_ips", "general_ignore_bogus_ts",
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
  "serverhide_disable_remote_commands", "serverhide_hide_servers",
  "serverhide_hide_services", "serverhide_hidden_name",
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
     295,   295,   295,   295,   295,   295,   295,   295,   295,   296,
     297,   298,   299,   300,   301,   302,   304,   303,   305,   305,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   308,   307,   309,   309,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   312,   311,
     313,   313,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   315,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   331,   330,   332,   332,   333,   333,
     335,   334,   337,   336,   338,   338,   339,   339,   339,   340,
     340,   341,   341,   341,   341,   341,   343,   342,   344,   344,
     345,   345,   346,   347,   349,   348,   350,   350,   351,   351,
     351,   351,   351,   351,   351,   351,   351,   352,   353,   354,
     355,   357,   356,   358,   358,   359,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   360,   361,   362,   364,   363,
     365,   365,   366,   366,   366,   366,   367,   368,   369,   370,
     371,   371,   372,   372,   373,   375,   374,   376,   376,   377,
     377,   377,   377,   378,   379,   381,   380,   382,   382,   383,
     383,   383,   383,   383,   383,   383,   383,   383,   383,   385,
     384,   386,   386,   387,   387,   387,   388,   390,   389,   391,
     391,   392,   392,   392,   392,   392,   392,   392,   392,   392,
     392,   394,   393,   395,   395,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     397,   398,   399,   400,   401,   402,   403,   404,   404,   406,
     405,   407,   407,   408,   408,   409,   410,   411,   412,   413,
     415,   414,   416,   416,   417,   417,   417,   418,   419,   421,
     420,   422,   422,   423,   423,   423,   424,   425,   426,   427,
     427,   428,   428,   429,   431,   430,   432,   432,   433,   433,
     433,   434,   435,   436,   437,   437,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   463,
     464,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   482,   481,
     483,   483,   484,   484,   484,   484,   484,   484,   484,   484,
     484,   484,   484,   484,   484,   484,   484,   484,   484,   484,
     484,   484,   484,   486,   485,   487,   487,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   489,   490,
     491,   492,   493,   493,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   508,   509,   509,   509,   509,   509,   509,   509,   509,
     509,   510,   511,   512,   513,   514,   515,   516,   517
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       0,     6,     0,     5,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     2,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     4,     4,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   218,   381,   429,     0,
     444,     0,   284,   420,   260,     0,   107,   145,   318,     0,
       0,   359,     0,     0,   335,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   603,   615,   605,   606,   607,   608,   604,
     609,   610,   611,   612,   613,   614,     0,     0,     0,   442,
       0,     0,   440,   441,     0,   503,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   573,     0,   548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   455,   501,   495,   496,   497,   498,
     499,   494,   466,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   491,   467,   468,   500,   470,   475,   471,
     473,   472,   485,   486,   474,   476,   477,   478,   479,   469,
     481,   482,   483,   502,   492,   493,   490,   484,   480,   488,
     489,   487,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   640,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   631,   632,   633,   634,   635,
     638,   636,   637,   639,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   333,
       0,     0,   331,   332,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   602,     0,     0,     0,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   221,   222,   225,   227,   228,   229,   230,
     231,   232,   233,   234,   223,   224,   226,   235,   236,   237,
       0,     0,     0,     0,     0,     0,     0,   409,     0,     0,
       0,     0,     0,     0,     0,     0,   384,   385,   386,   387,
     388,   389,   390,   392,   391,   394,   398,   395,   396,   397,
     393,   435,     0,     0,     0,   432,   433,   434,     0,     0,
     439,   450,     0,     0,     0,   447,   448,   449,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   454,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   287,   288,   289,
     290,   295,   291,   292,   293,   294,   426,     0,     0,     0,
     423,   424,   425,     0,     0,     0,   262,     0,   272,     0,
     270,   271,   273,   274,    48,     0,     0,     0,    44,     0,
       0,     0,     0,   110,   111,   112,     0,     0,     0,   191,
       0,     0,     0,     0,   166,     0,     0,   148,   149,   150,
     151,   154,   155,   156,   153,   152,   157,     0,     0,     0,
       0,     0,   321,   322,   323,   324,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   630,    71,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    52,     0,     0,   367,     0,
     362,   363,   364,   121,     0,     0,   117,     0,     0,     0,
     330,     0,     0,   345,     0,     0,   338,   339,   340,   341,
       0,     0,     0,    97,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,   601,   238,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   383,     0,     0,     0,   431,     0,   438,
       0,     0,     0,   446,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,   296,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   286,     0,     0,     0,   422,   275,
       0,     0,     0,     0,     0,   269,     0,     0,    43,   113,
       0,     0,     0,   109,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   147,   325,     0,     0,     0,
       0,   320,     0,     0,     0,     0,     0,     0,     0,     0,
     629,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    76,    77,     0,    75,    80,    81,
       0,    79,     0,     0,    51,   365,     0,     0,     0,   361,
       0,   116,     0,     0,   329,   342,     0,     0,     0,     0,
     337,   106,   105,   104,   624,   623,   617,   627,    27,    27,
      27,    27,    27,    27,    27,    29,    28,   628,   618,   619,
     622,   621,   620,   625,   626,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,     0,   219,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   382,     0,
       0,   430,   443,     0,     0,   445,   515,   519,   533,   600,
     546,   540,   543,   514,   506,   505,   508,   509,   507,   522,
     512,   513,   523,   511,   518,   517,   516,   541,   504,   598,
     599,   537,   583,   577,   594,   578,   579,   580,   588,   597,
     581,   591,   595,   584,   596,   589,   585,   590,   582,   593,
     587,   586,   592,     0,   576,   539,   557,   552,   569,   553,
     554,   555,   563,   572,   556,   566,   570,   559,   571,   564,
     560,   565,   558,   568,   562,   561,   567,     0,   551,   534,
     532,   535,   545,   536,   525,   530,   531,   528,   529,   526,
     527,   544,   547,   510,   538,   521,   520,   542,   524,     0,
       0,     0,     0,     0,     0,     0,     0,   285,     0,     0,
     421,     0,     0,     0,   280,   276,   279,   261,    49,    50,
       0,     0,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,   319,   642,   641,   647,
     645,   648,   643,   644,   646,    88,    96,    87,    94,    95,
      86,    90,    89,    83,    82,    84,    93,    85,    72,     0,
      73,     0,    91,    92,     0,     0,   360,   122,     0,     0,
       0,   134,     0,   126,   127,   129,   128,   334,     0,     0,
       0,   336,    30,    31,    32,    33,    34,    35,    36,   249,
     250,   242,   259,   258,     0,   257,   244,   246,   253,   245,
     243,   252,   239,   251,   241,   240,    37,    37,    37,    39,
      38,   247,   248,   404,   407,   408,   418,   415,   401,   416,
     413,   414,     0,   412,   417,   400,   406,   403,   405,   419,
     402,   436,   437,   451,   452,   574,     0,   549,     0,   299,
     300,   309,   306,   311,   307,   308,   314,   310,   312,   305,
     313,     0,   304,   298,   317,   316,   315,   297,   428,   427,
     283,   282,   267,   268,   266,     0,   265,     0,     0,     0,
     114,   115,   165,   162,   210,   198,   207,   206,   196,   201,
     217,   209,   215,   200,   203,   212,   214,   211,   208,   216,
     204,   213,   202,   205,     0,   194,   159,   161,   163,   164,
     175,   170,   187,   171,   172,   173,   181,   190,   174,   184,
     188,   177,   189,   182,   178,   183,   176,   186,   180,   179,
     185,     0,   169,   160,   328,   326,   327,    74,    78,   366,
     371,   377,   380,   373,   379,   374,   378,   376,   372,   375,
       0,   370,   130,     0,     0,     0,     0,   125,   343,   349,
     355,   358,   351,   357,   352,   356,   354,   350,   353,     0,
     348,   344,   255,     0,    40,    41,    42,   410,     0,   575,
     550,   302,     0,   263,     0,   281,   278,   277,     0,     0,
       0,   192,     0,   167,     0,   368,     0,     0,     0,     0,
       0,   124,   346,     0,   256,   411,   303,   264,   197,   195,
     199,   193,   168,   369,   131,   133,   132,   140,   143,   142,
     139,   144,   141,   138,     0,   137,   347,   135,     0,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   805,   806,  1059,  1060,    26,   218,   219,
     220,   221,    27,   262,   263,   264,   265,   766,   767,   770,
     771,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    28,    74,    75,    76,
      77,    78,    29,    61,   492,   493,   494,   495,    30,   284,
     285,   286,   287,   288,  1022,  1023,  1024,  1025,  1026,  1195,
    1264,  1265,    31,    62,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   732,  1171,  1172,   516,   727,  1144,
    1145,    32,    51,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   602,  1044,  1045,    33,    59,   478,   712,  1115,  1116,
     479,   480,   481,  1119,   965,   966,   482,   483,    34,    57,
     456,   457,   458,   459,   460,   461,   462,   697,  1101,  1102,
     463,   464,   465,    35,    63,   521,   522,   523,   524,   525,
      36,   291,   292,   293,    37,    69,   575,   576,   577,   578,
     579,   787,  1209,  1210,    38,    66,   559,   560,   561,   562,
     777,  1190,  1191,    39,    52,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   624,  1072,  1073,   376,
     377,   378,   379,   380,    40,    58,   469,   470,   471,   472,
      41,    53,   384,   385,   386,   387,    42,   111,   112,   113,
      43,    55,   394,   395,   396,   397,    44,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   426,   927,   928,   208,   424,   903,   904,   209,
     210,   211,    45,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,    46,   234,   235,
     236,   237,   238,   239,   240,   241,   242,   243
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -736
static const yytype_int16 yypact[] =
{
    -736,   630,  -736,  -163,  -195,  -186,  -736,  -736,  -736,  -184,
    -736,  -174,  -736,  -736,  -736,  -172,  -736,  -736,  -736,  -148,
    -145,  -736,  -143,  -138,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   311,
     925,  -125,   -92,   -71,    25,   -58,   424,   -53,   -50,   -38,
      49,   -22,   -20,     2,   622,   338,    27,     9,    26,    39,
    -131,   -16,    51,    70,     8,  -736,  -736,  -736,  -736,  -736,
      72,    74,    76,    80,    83,    98,   100,   103,   104,   110,
     116,   118,   325,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,   650,   352,   189,  -736,
     122,    15,  -736,  -736,    65,  -736,   123,   127,   129,   131,
     132,   133,   134,   136,   137,   139,   140,   141,   143,   144,
     148,   150,   151,   152,   153,   155,   156,   158,   159,   160,
     161,   164,  -736,   165,  -736,   166,   170,   171,   178,   183,
     185,   188,   190,   191,   192,   194,   199,   205,   206,   207,
     210,   213,   214,   107,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,   475,     6,   278,    48,   215,   216,    46,  -736,
    -736,  -736,    11,   489,    17,  -736,   218,   220,   221,   224,
     225,   228,   229,   230,     7,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,   124,   231,   233,   235,   236,   239,
     247,   248,   250,   252,   257,   258,   259,   262,   268,   269,
     270,   271,    21,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,    35,   281,   276,    18,  -736,  -736,  -736,   120,  -736,
     282,    62,  -736,  -736,     5,  -736,   291,   294,   380,   287,
    -736,   411,   413,   315,   417,   418,   418,   418,   419,   420,
     421,   323,   334,   322,  -736,   324,   320,   326,   327,  -736,
     330,   333,   335,   336,   337,   340,   341,   344,   346,   347,
     353,   356,   186,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
     328,   358,   360,   361,   362,   363,   364,  -736,   367,   370,
     371,   372,   375,   377,   383,   279,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,   384,   385,    22,  -736,  -736,  -736,   439,   389,
    -736,  -736,   387,   388,    20,  -736,  -736,  -736,   400,   418,
     418,   458,   410,   511,   497,   431,   418,   433,   513,   518,
     418,   519,   435,   436,   445,   418,   520,   521,   418,   548,
     552,   553,   554,   456,   450,   465,   453,   477,   418,   418,
     478,   481,   482,  -182,  -139,   483,   486,   560,   418,   490,
     491,   418,   418,   493,   494,   459,  -736,   479,   480,   484,
    -736,   495,   496,   500,   501,   502,    32,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,   507,   509,    45,
    -736,  -736,  -736,   485,   512,   515,  -736,   517,  -736,    10,
    -736,  -736,  -736,  -736,  -736,   580,   584,   514,  -736,   522,
     530,   534,    14,  -736,  -736,  -736,   524,   535,   536,  -736,
     537,   538,   539,   540,  -736,   541,    12,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,   545,   544,   549,
     550,     4,  -736,  -736,  -736,  -736,   503,   533,   565,   598,
     568,   571,   572,   418,   556,  -736,  -736,   599,   574,   602,
     638,   675,   661,   662,   663,   664,   665,   666,   682,   669,
     -98,    59,   672,   673,   573,  -736,   575,   569,  -736,    89,
    -736,  -736,  -736,  -736,   591,   576,  -736,   577,   679,   578,
    -736,   581,   582,  -736,   583,    19,  -736,  -736,  -736,  -736,
     587,   588,   596,  -736,   600,   604,   607,   608,   579,   612,
     614,   615,   616,   617,   619,   620,   621,  -736,  -736,   700,
     716,   418,   623,   719,   742,   418,   744,   746,   418,   686,
     747,   748,   418,   750,   750,   628,  -736,  -736,   751,   121,
     753,   660,   754,   758,   637,   760,   761,   763,   762,   765,
     766,   767,   648,  -736,   771,   773,   674,  -736,   684,  -736,
     774,   775,   688,  -736,   690,   692,   693,   695,   696,   703,
     704,   705,   707,   708,   709,   713,   715,   718,   721,   724,
     726,   727,   729,   731,   732,   733,   734,   735,   736,   739,
     657,   740,   701,   741,   743,   749,   752,   755,   756,   757,
     759,   764,   768,   769,   770,   776,   777,   781,   782,   783,
     784,   785,   786,  -736,  -736,   802,   678,   772,   821,   792,
     840,   844,   846,   787,  -736,   847,   848,   788,  -736,  -736,
     849,   850,   789,   867,   790,  -736,   791,   793,  -736,  -736,
     853,   855,   794,  -736,  -736,   856,   778,   795,   860,   862,
     864,   865,   796,   869,   797,  -736,  -736,   875,   876,   891,
     800,  -736,   801,   803,   806,   807,   808,   809,   810,   811,
    -736,   812,   813,   814,   815,   816,   817,   818,   819,   820,
     822,   823,   824,   825,  -736,  -736,  -194,  -736,  -736,  -736,
    -187,  -736,   826,   827,  -736,  -736,   897,   799,   828,  -736,
     829,  -736,    66,   830,  -736,  -736,   898,   831,   923,   832,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   418,   418,
     418,   418,   418,   418,   418,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   833,   835,   836,   -36,   837,
     838,   839,   841,   842,   843,   845,   851,   852,   854,   265,
     857,   858,  -736,   859,   861,   863,   866,   868,   870,   871,
      16,   872,   873,   874,   877,   878,   879,   880,  -736,   881,
     882,  -736,  -736,   883,   884,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -171,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -155,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   885,
     886,   275,   887,   888,   889,   890,   892,  -736,   893,   894,
    -736,   895,   896,     0,   901,   899,  -736,  -736,  -736,  -736,
     900,   902,  -736,   904,   905,   476,   906,   907,   908,   909,
     745,   910,  -736,   911,   912,   913,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -98,
    -736,    59,  -736,  -736,   914,   393,  -736,  -736,   915,   916,
     917,  -736,    75,  -736,  -736,  -736,  -736,  -736,   918,   738,
     921,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -133,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,   750,   750,   750,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -124,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,   657,  -736,   701,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -104,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,   -68,  -736,   948,   867,   922,
    -736,  -736,  -736,  -736,  -736,   919,  -736,  -736,   920,  -736,
    -736,  -736,  -736,   924,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,   -43,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,   -30,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
     -21,  -736,  -736,   942,   -90,   927,   926,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -15,
    -736,  -736,  -736,   -36,  -736,  -736,  -736,  -736,    16,  -736,
    -736,  -736,   275,  -736,     0,  -736,  -736,  -736,   940,   943,
     944,  -736,   476,  -736,   745,  -736,   393,   928,   931,   932,
     516,  -736,  -736,   738,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,    61,  -736,  -736,  -736,   516,  -736
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -736,  -736,  -736,   -48,  -303,  -735,  -613,  -736,  -736,   903,
    -736,  -736,  -736,  -736,   929,  -736,  -736,  -736,    64,  -736,
      63,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   996,  -736,
    -736,  -736,  -736,  -736,  -736,   585,  -736,  -736,  -736,  -736,
     804,  -736,  -736,  -736,  -736,    57,  -736,  -736,  -736,  -736,
    -736,  -188,  -736,  -736,  -736,   593,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -150,  -736,  -736,  -736,
    -146,  -736,  -736,  -736,   834,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -122,  -736,  -736,  -736,  -736,  -736,  -135,
    -736,   643,  -736,  -736,  -736,   -25,  -736,  -736,  -736,  -736,
    -736,   644,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -99,
    -736,  -736,  -736,  -736,  -736,  -736,   626,  -736,  -736,  -736,
    -736,  -736,   930,  -736,  -736,  -736,  -736,   566,  -736,  -736,
    -736,  -736,  -736,  -118,  -736,  -736,  -736,   592,  -736,  -736,
    -736,  -736,   -96,  -736,  -736,  -736,   798,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   -61,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,   689,  -736,  -736,
    -736,  -736,  -736,   780,  -736,  -736,  -736,  -736,  1048,  -736,
    -736,  -736,  -736,   779,  -736,  -736,  -736,  -736,   997,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,    73,  -736,  -736,  -736,    79,  -736,
    -736,  -736,  -736,  -736,  1070,  -736,  -736,  -736,  -736,  -736,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736,   933,
    -736,  -736,  -736,  -736,  -736,  -736,  -736,  -736
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
     830,   831,   589,   590,   591,   517,   571,   466,   225,    70,
     282,   473,   489,   496,  1042,   489,   109,   829,   517,   282,
     571,   391,   244,   381,  1070,   679,   109,   289,   680,   497,
    1008,    49,    71,   447,  1009,   226,   556,  1010,   518,    72,
      50,  1011,    54,   227,   498,   245,   466,   215,  1112,   448,
     215,   518,    56,  1085,    60,   228,   229,  1086,   230,   231,
     232,    47,    48,   289,   449,   474,   391,  1018,   681,  1087,
     475,   682,   476,  1088,   499,   110,  1018,   246,    64,   519,
     233,    65,   382,    67,   247,   110,   490,  1043,    68,   490,
     556,  1212,   519,   295,   450,  1213,   645,   646,   764,   765,
    1217,   106,   572,   652,  1218,    73,   248,   656,   115,   500,
     249,  1238,   661,   116,   117,   664,   572,   392,   250,   118,
    1221,   251,   252,   290,  1222,   674,   675,   119,   520,   501,
     467,   477,   557,   120,   107,   686,   121,   122,   689,   690,
     216,   520,   123,   216,   393,   502,   383,   124,   125,   451,
     126,   127,   128,   253,   129,   108,  1223,   452,   453,   290,
    1224,   130,   392,  1019,   217,   131,   132,   217,   114,   467,
     254,   255,  1019,   212,   133,  -123,   213,   491,   454,   503,
     491,  1231,  1113,   134,  -123,  1232,   557,   315,   214,   393,
     381,   135,  1114,   136,  1233,   137,   256,   138,  1234,   139,
     140,   316,   317,  1235,   222,   318,   223,  1236,  1071,  1242,
     504,   296,   141,  1243,   257,   258,   259,   142,   143,   144,
     573,   145,   146,   147,   574,   468,   148,   283,   224,   740,
     749,   505,   534,   299,   573,   714,   283,   734,   574,   722,
     389,   260,   261,   565,   789,   642,   554,   636,   319,   382,
     558,   455,   149,   281,  1020,   768,   769,   703,   150,   151,
     152,   153,   154,  1020,   468,   294,   320,   321,   322,   323,
     707,   487,   484,   324,  1056,  1057,  1058,   325,   297,   473,
     350,  1021,   351,   326,   352,  1267,   567,   569,  1091,  1268,
    1021,   155,   834,   835,   327,   328,   353,   298,   817,   301,
    1196,   302,   821,   303,   558,   824,   329,   304,  1092,   828,
     305,   354,    70,   383,   778,   156,   157,  1093,   158,   159,
     160,  1214,  1215,  1216,   161,   306,    79,   307,   330,   162,
     308,   309,   445,   474,   355,    71,   356,   310,   475,   244,
     476,   357,    72,   311,  1094,   312,    80,    81,   536,   388,
     398,   358,    82,   350,   399,   351,   400,   352,   401,   402,
     403,   404,   245,   405,   406,   331,   407,   408,   409,   353,
     410,   411,   829,  1095,  1096,   412,   359,   413,   414,   415,
     416,  1097,   417,   418,   354,   419,   420,   421,   422,    83,
      84,   423,   425,   427,   246,    85,    86,   428,   429,   477,
     360,   247,    87,    88,    89,   430,  1098,   355,    73,   356,
     431,   615,   432,   580,   357,   433,   581,   434,   435,   436,
     361,   437,  1099,   248,   358,   115,   438,   249,    90,    91,
     116,   117,   439,   440,   441,   250,   118,   442,   251,   252,
     443,   444,   485,   486,   119,   526,   362,   527,   528,   359,
     120,   529,   530,   121,   122,   531,   532,   533,   537,   123,
     538,  1180,   539,   540,   124,   125,   541,   126,   127,   128,
     253,   129,   363,   360,   542,   543,   447,   544,   130,   545,
    1124,  1100,   131,   132,   546,   547,   548,   254,   255,   549,
     496,   133,   448,   361,  1125,   550,   551,   552,   553,   364,
     134,  1126,   582,   564,   632,   563,   497,   449,   135,   568,
     136,   583,   137,   256,   138,  1127,   139,   140,   584,   362,
     585,   498,   586,  1181,   587,   588,   592,   593,   594,   141,
     595,   257,   258,   259,   142,   143,   144,   450,   145,   146,
     147,   596,  1128,   148,  1129,   363,   597,   599,   598,  1182,
     313,   499,   617,   600,   601,  1257,  1183,   603,   260,   261,
     604,   638,   605,   606,   607,   647,  1184,   608,   609,   149,
    1130,   610,   364,   611,   612,   150,   151,   152,   153,   154,
     613,  1239,  1258,   614,  1259,   618,   500,   619,   620,   621,
     622,   623,   451,  1185,   625,  1186,  1187,   626,   627,   628,
     452,   453,   629,  1131,   630,  1132,   501,   644,   155,  1188,
     631,   634,   635,   639,   640,   641,  1189,   648,   649,   650,
     654,   454,   502,   225,  1133,   655,   657,   662,   663,  1260,
       2,     3,   156,   157,     4,   158,   159,   160,   651,  1134,
     653,   161,   658,   659,     5,  1135,   162,     6,     7,  1136,
     226,   315,   660,     8,  1137,   665,   503,  1138,   227,   666,
     667,   668,  1139,   669,     9,   316,   317,    10,    11,   318,
     228,   229,   671,   230,   231,   232,  1140,   670,  1261,  1262,
     672,  1141,   685,   693,   673,   676,   588,   504,   677,   678,
     683,    12,  1142,   684,   455,   233,    13,   687,   688,  1143,
     691,   692,   716,   694,    14,   882,   717,   695,   505,   709,
     742,   696,   319,   798,   799,   800,   801,   802,   803,   804,
     745,   751,   698,   699,   753,    15,    16,   700,   701,   702,
     320,   321,   322,   323,   705,  1263,   706,   324,   718,   710,
     743,   325,   711,    17,   713,   754,   719,   326,   724,   906,
    1032,  1033,  1034,  1035,  1036,  1037,  1038,   720,   327,   328,
      18,   721,   725,   726,   728,   729,   730,   731,   733,   736,
     329,   737,   744,    19,    20,   746,   738,   739,   747,   748,
     750,   752,   755,   756,   757,   758,   759,   760,   761,   762,
      21,   763,   330,  1150,   772,   773,   776,   774,   780,   775,
     781,   783,   784,   782,    22,   785,  1199,   815,   825,   786,
     788,   791,   792,    23,   883,   884,   885,    24,   886,   887,
     793,   888,   889,   816,   794,   890,   819,   891,   795,   331,
     892,   796,   797,   893,   894,   895,   807,   896,   808,   809,
     810,   811,   897,   812,   813,   814,   898,   899,   900,   820,
     818,   822,   832,   823,   826,   827,   901,   829,   907,   908,
     909,   902,   910,   911,   840,   912,   913,   837,  1200,   914,
     843,   915,   848,   833,   916,   836,   838,   917,   918,   919,
     839,   920,   841,   842,   844,   950,   921,   845,   846,   847,
     922,   923,   924,   849,  1201,   850,   853,   854,   851,   953,
     925,  1202,  1151,  1152,  1153,   926,  1154,  1155,   852,  1156,
    1157,  1203,   855,  1158,   856,  1159,   857,   858,  1160,   859,
     860,  1161,  1162,  1163,   949,  1164,    79,   861,   862,   863,
    1165,   864,   865,   866,  1166,  1167,  1168,   867,  1204,   868,
    1205,  1206,   869,   952,  1169,   870,    80,    81,   871,  1170,
     872,   873,    82,   874,  1207,   875,   876,   877,   878,   879,
     880,  1208,   954,   881,   905,   929,   955,   930,   956,   958,
     959,   961,   962,   931,   964,   970,   932,   971,   973,   933,
     934,   935,   976,   936,   977,   974,   978,   979,   937,    83,
      84,   981,   938,   939,   940,    85,    86,   983,   984,   951,
     941,   942,    87,    88,    89,   943,   944,   945,   946,   947,
     948,   957,   960,   985,   967,   968,   963,   969,   972,  1014,
    1028,   982,   975,   980,   986,   987,  1015,   988,    90,    91,
     989,   990,   991,   992,   993,   994,   995,   996,   997,   998,
     999,  1000,  1001,  1002,  1003,  1030,  1004,  1005,  1006,  1007,
    1012,  1013,  1016,  1017,  1027,  1225,  1031,  1039,  1029,  1040,
    1041,  1046,  1047,  1048,  1237,  1049,  1050,  1051,  1248,  1052,
     300,  1249,  1250,  1177,  1178,  1053,  1054,   723,  1055,  1197,
    1269,  1061,  1062,  1063,  1252,  1064,  1251,  1065,   566,  1247,
    1066,  1244,  1067,  1226,  1068,  1069,  1074,  1075,  1076,   735,
     704,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,  1089,
    1090,  1103,  1104,  1105,  1106,  1117,  1107,  1108,  1109,  1110,
    1111,   488,   715,  1246,  1120,  1266,  1121,  1118,  1122,  1123,
    1146,  1147,  1148,  1149,  1173,  1174,  1175,  1176,  1179,  1192,
    1253,   790,  1198,  1193,  1194,  1211,  1227,   741,  1228,  1229,
    1241,   779,  1254,  1230,  1240,  1255,  1256,  1245,   708,   390,
     446,  1220,   314,   633,   637,  1219,   616,   535,     0,     0,
       0,     0,     0,   643,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-736)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     613,   614,   305,   306,   307,     1,     1,     1,     1,     1,
       1,     1,     1,     1,    50,     1,     1,   107,     1,     1,
       1,     1,     1,     1,     8,   207,     1,     1,   210,    17,
     224,   226,    24,     1,   228,    28,     1,   224,    34,    31,
     226,   228,   226,    36,    32,    24,     1,     1,    48,    17,
       1,    34,   226,   224,   226,    48,    49,   228,    51,    52,
      53,   224,   225,     1,    32,    55,     1,     1,   207,   224,
      60,   210,    62,   228,    62,    60,     1,    56,   226,    75,
      73,   226,    60,   226,    63,    60,    75,   123,   226,    75,
       1,   224,    75,   224,    62,   228,   399,   400,   196,   197,
     224,   226,    97,   406,   228,    97,    85,   410,     1,    97,
      89,   201,   415,     6,     7,   418,    97,    97,    97,    12,
     224,   100,   101,    97,   228,   428,   429,    20,   124,   117,
     124,   121,    97,    26,   226,   438,    29,    30,   441,   442,
      94,   124,    35,    94,   124,   133,   124,    40,    41,   117,
      43,    44,    45,   132,    47,   226,   224,   125,   126,    97,
     228,    54,    97,    97,   118,    58,    59,   118,   226,   124,
     149,   150,    97,   226,    67,   166,   226,   166,   146,   167,
     166,   224,   182,    76,   166,   228,    97,     1,   226,   124,
       1,    84,   192,    86,   224,    88,   175,    90,   228,    92,
      93,    15,    16,   224,   226,    19,   226,   228,   192,   224,
     198,   227,   105,   228,   193,   194,   195,   110,   111,   112,
     215,   114,   115,   116,   219,   219,   119,   218,   226,   225,
     533,   219,   225,   225,   215,   225,   218,   225,   219,   225,
     225,   220,   221,   225,   225,   225,   225,   225,    62,    60,
     215,   219,   145,   226,   188,   196,   197,   225,   151,   152,
     153,   154,   155,   188,   219,   226,    80,    81,    82,    83,
     225,   225,   224,    87,     9,    10,    11,    91,   227,     1,
       1,   215,     3,    97,     5,   224,   166,   225,    13,   228,
     215,   184,   171,   172,   108,   109,    17,   227,   601,   227,
     225,   227,   605,   227,   215,   608,   120,   227,    33,   612,
     227,    32,     1,   124,   225,   208,   209,    42,   211,   212,
     213,  1056,  1057,  1058,   217,   227,     1,   227,   142,   222,
     227,   227,   225,    55,    55,    24,    57,   227,    60,     1,
      62,    62,    31,   227,    69,   227,    21,    22,   224,   227,
     227,    72,    27,     1,   227,     3,   227,     5,   227,   227,
     227,   227,    24,   227,   227,   179,   227,   227,   227,    17,
     227,   227,   107,    98,    99,   227,    97,   227,   227,   227,
     227,   106,   227,   227,    32,   227,   227,   227,   227,    64,
      65,   227,   227,   227,    56,    70,    71,   227,   227,   121,
     121,    63,    77,    78,    79,   227,   131,    55,    97,    57,
     227,   225,   227,   122,    62,   227,   122,   227,   227,   227,
     141,   227,   147,    85,    72,     1,   227,    89,   103,   104,
       6,     7,   227,   227,   227,    97,    12,   227,   100,   101,
     227,   227,   227,   227,    20,   227,   167,   227,   227,    97,
      26,   227,   227,    29,    30,   227,   227,   227,   227,    35,
     227,    68,   227,   227,    40,    41,   227,    43,    44,    45,
     132,    47,   193,   121,   227,   227,     1,   227,    54,   227,
       4,   206,    58,    59,   227,   227,   227,   149,   150,   227,
       1,    67,    17,   141,    18,   227,   227,   227,   227,   220,
      76,    25,   122,   227,   225,   224,    17,    32,    84,   227,
      86,   224,    88,   175,    90,    39,    92,    93,   107,   167,
     107,    32,   207,   130,   107,   107,   107,   107,   107,   105,
     207,   193,   194,   195,   110,   111,   112,    62,   114,   115,
     116,   207,    66,   119,    68,   193,   224,   227,   224,   156,
     225,    62,   224,   227,   227,    39,   163,   227,   220,   221,
     227,   122,   227,   227,   227,   107,   173,   227,   227,   145,
      94,   227,   220,   227,   227,   151,   152,   153,   154,   155,
     227,  1194,    66,   227,    68,   227,    97,   227,   227,   227,
     227,   227,   117,   200,   227,   202,   203,   227,   227,   227,
     125,   126,   227,   127,   227,   129,   117,   207,   184,   216,
     227,   227,   227,   224,   227,   227,   223,   207,   107,   122,
     107,   146,   133,     1,   148,   107,   107,   107,   107,   113,
       0,     1,   208,   209,     4,   211,   212,   213,   207,   163,
     207,   217,   207,   207,    14,   169,   222,    17,    18,   173,
      28,     1,   207,    23,   178,   107,   167,   181,    36,   107,
     107,   107,   186,   207,    34,    15,    16,    37,    38,    19,
      48,    49,   207,    51,    52,    53,   200,   227,   162,   163,
     227,   205,   122,   224,   207,   207,   107,   198,   207,   207,
     207,    61,   216,   207,   219,    73,    66,   207,   207,   223,
     207,   207,   122,   224,    74,    48,   122,   227,   219,   224,
     207,   227,    62,   134,   135,   136,   137,   138,   139,   140,
     122,   122,   227,   227,   122,    95,    96,   227,   227,   227,
      80,    81,    82,    83,   227,   219,   227,    87,   224,   227,
     207,    91,   227,   113,   227,   107,   224,    97,   224,    48,
     798,   799,   800,   801,   802,   803,   804,   227,   108,   109,
     130,   227,   227,   227,   227,   227,   227,   227,   227,   224,
     120,   227,   207,   143,   144,   207,   227,   227,   207,   207,
     224,   207,   107,   122,   122,   122,   122,   122,   122,   107,
     160,   122,   142,    48,   122,   122,   227,   224,   207,   224,
     224,   122,   224,   226,   174,   224,    68,   107,   122,   227,
     227,   224,   224,   183,   157,   158,   159,   187,   161,   162,
     224,   164,   165,   107,   224,   168,   107,   170,   224,   179,
     173,   224,   224,   176,   177,   178,   224,   180,   224,   224,
     224,   224,   185,   224,   224,   224,   189,   190,   191,   107,
     227,   107,   224,   107,   107,   107,   199,   107,   157,   158,
     159,   204,   161,   162,   227,   164,   165,   207,   130,   168,
     107,   170,   224,   122,   173,   122,   122,   176,   177,   178,
     122,   180,   122,   122,   122,   207,   185,   122,   122,   122,
     189,   190,   191,   122,   156,   122,   122,   122,   224,   107,
     199,   163,   157,   158,   159,   204,   161,   162,   224,   164,
     165,   173,   224,   168,   224,   170,   224,   224,   173,   224,
     224,   176,   177,   178,   122,   180,     1,   224,   224,   224,
     185,   224,   224,   224,   189,   190,   191,   224,   200,   224,
     202,   203,   224,   122,   199,   224,    21,    22,   224,   204,
     224,   224,    27,   224,   216,   224,   224,   224,   224,   224,
     224,   223,   122,   224,   224,   224,   122,   224,   122,   122,
     122,   122,   122,   224,   107,   122,   224,   122,   122,   224,
     224,   224,   122,   224,   122,   207,   122,   122,   224,    64,
      65,   122,   224,   224,   224,    70,    71,   122,   122,   227,
     224,   224,    77,    78,    79,   224,   224,   224,   224,   224,
     224,   224,   224,   122,   224,   224,   227,   224,   224,   122,
     122,   224,   227,   227,   224,   224,   227,   224,   103,   104,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   122,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   107,   224,   224,   227,   224,
     224,   224,   224,   224,   122,   224,   224,   224,   128,   224,
      74,   128,   128,  1009,  1011,   224,   224,   492,   224,  1022,
    1268,   224,   224,   224,  1234,   224,  1232,   224,   284,  1224,
     224,  1213,   224,  1118,   224,   224,   224,   224,   224,   506,
     456,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   214,   224,   224,   224,   224,
     224,   218,   479,  1222,   224,  1243,   224,   228,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
    1236,   575,   224,   227,   227,   224,   224,   521,   229,   229,
     224,   559,   224,   229,   227,   224,   224,  1218,   469,   111,
     163,  1088,    92,   365,   384,  1086,   332,   234,    -1,    -1,
      -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   231,     0,     1,     4,    14,    17,    18,    23,    34,
      37,    38,    61,    66,    74,    95,    96,   113,   130,   143,
     144,   160,   174,   183,   187,   232,   237,   242,   266,   272,
     278,   292,   311,   334,   348,   363,   370,   374,   384,   393,
     414,   420,   426,   430,   436,   492,   507,   224,   225,   226,
     226,   312,   394,   421,   226,   431,   226,   349,   415,   335,
     226,   273,   293,   364,   226,   226,   385,   226,   226,   375,
       1,    24,    31,    97,   267,   268,   269,   270,   271,     1,
      21,    22,    27,    64,    65,    70,    71,    77,    78,    79,
     103,   104,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   226,   226,   226,     1,
      60,   427,   428,   429,   226,     1,     6,     7,    12,    20,
      26,    29,    30,    35,    40,    41,    43,    44,    45,    47,
      54,    58,    59,    67,    76,    84,    86,    88,    90,    92,
      93,   105,   110,   111,   112,   114,   115,   116,   119,   145,
     151,   152,   153,   154,   155,   184,   208,   209,   211,   212,
     213,   217,   222,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   485,   489,
     490,   491,   226,   226,   226,     1,    94,   118,   238,   239,
     240,   241,   226,   226,   226,     1,    28,    36,    48,    49,
      51,    52,    53,    73,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,     1,    24,    56,    63,    85,    89,
      97,   100,   101,   132,   149,   150,   175,   193,   194,   195,
     220,   221,   243,   244,   245,   246,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   226,     1,   218,   279,   280,   281,   282,   283,     1,
      97,   371,   372,   373,   226,   224,   227,   227,   227,   225,
     268,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   225,   494,     1,    15,    16,    19,    62,
      80,    81,    82,    83,    87,    91,    97,   108,   109,   120,
     142,   179,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       1,     3,     5,    17,    32,    55,    57,    62,    72,    97,
     121,   141,   167,   193,   220,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   405,   409,   410,   411,   412,
     413,     1,    60,   124,   422,   423,   424,   425,   227,   225,
     428,     1,    97,   124,   432,   433,   434,   435,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   486,   227,   482,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   225,   438,     1,    17,    32,
      62,   117,   125,   126,   146,   219,   350,   351,   352,   353,
     354,   355,   356,   360,   361,   362,     1,   124,   219,   416,
     417,   418,   419,     1,    55,    60,    62,   121,   336,   340,
     341,   342,   346,   347,   224,   227,   227,   225,   239,     1,
      75,   166,   274,   275,   276,   277,     1,    17,    32,    62,
      97,   117,   133,   167,   198,   219,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   307,     1,    34,    75,
     124,   365,   366,   367,   368,   369,   227,   227,   227,   227,
     227,   227,   227,   227,   225,   509,   224,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   225,   244,     1,    97,   215,   386,
     387,   388,   389,   224,   227,   225,   280,   166,   227,   225,
     372,     1,    97,   215,   219,   376,   377,   378,   379,   380,
     122,   122,   122,   224,   107,   107,   207,   107,   107,   234,
     234,   234,   107,   107,   107,   207,   207,   224,   224,   227,
     227,   227,   331,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   225,   314,   224,   227,   227,
     227,   227,   227,   227,   406,   227,   227,   227,   227,   227,
     227,   227,   225,   396,   227,   227,   225,   423,   122,   224,
     227,   227,   225,   433,   207,   234,   234,   107,   207,   107,
     122,   207,   234,   207,   107,   107,   234,   107,   207,   207,
     207,   234,   107,   107,   234,   107,   107,   107,   107,   207,
     227,   207,   227,   207,   234,   234,   207,   207,   207,   207,
     210,   207,   210,   207,   207,   122,   234,   207,   207,   234,
     234,   207,   207,   224,   224,   227,   227,   357,   227,   227,
     227,   227,   227,   225,   351,   227,   227,   225,   417,   224,
     227,   227,   337,   227,   225,   341,   122,   122,   224,   224,
     227,   227,   225,   275,   224,   227,   227,   308,   227,   227,
     227,   227,   304,   227,   225,   295,   224,   227,   227,   227,
     225,   366,   207,   207,   207,   122,   207,   207,   207,   234,
     224,   122,   207,   122,   107,   107,   122,   122,   122,   122,
     122,   122,   107,   122,   196,   197,   247,   248,   196,   197,
     249,   250,   122,   122,   224,   224,   227,   390,   225,   387,
     207,   224,   226,   122,   224,   224,   227,   381,   227,   225,
     377,   224,   224,   224,   224,   224,   224,   224,   134,   135,
     136,   137,   138,   139,   140,   233,   234,   224,   224,   224,
     224,   224,   224,   224,   224,   107,   107,   234,   227,   107,
     107,   234,   107,   107,   234,   122,   107,   107,   234,   107,
     236,   236,   224,   122,   171,   172,   122,   207,   122,   122,
     227,   122,   122,   107,   122,   122,   122,   122,   224,   122,
     122,   224,   224,   122,   122,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,    48,   157,   158,   159,   161,   162,   164,   165,
     168,   170,   173,   176,   177,   178,   180,   185,   189,   190,
     191,   199,   204,   487,   488,   224,    48,   157,   158,   159,
     161,   162,   164,   165,   168,   170,   173,   176,   177,   178,
     180,   185,   189,   190,   191,   199,   204,   483,   484,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   122,
     207,   227,   122,   107,   122,   122,   122,   224,   122,   122,
     224,   122,   122,   227,   107,   344,   345,   224,   224,   224,
     122,   122,   224,   122,   207,   227,   122,   122,   122,   122,
     227,   122,   224,   122,   122,   122,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   228,
     224,   228,   224,   224,   122,   227,   224,   224,     1,    97,
     188,   215,   284,   285,   286,   287,   288,   224,   122,   227,
     122,   224,   233,   233,   233,   233,   233,   233,   233,   224,
     224,   224,    50,   123,   332,   333,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,     9,    10,    11,   235,
     236,   224,   224,   224,   224,   224,   224,   224,   224,   224,
       8,   192,   407,   408,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   228,   224,   228,   224,
     224,    13,    33,    42,    69,    98,    99,   106,   131,   147,
     206,   358,   359,   224,   224,   224,   224,   224,   224,   224,
     224,   224,    48,   182,   192,   338,   339,   214,   228,   343,
     224,   224,   224,   224,     4,    18,    25,    39,    66,    68,
      94,   127,   129,   148,   163,   169,   173,   178,   181,   186,
     200,   205,   216,   223,   309,   310,   224,   224,   224,   224,
      48,   157,   158,   159,   161,   162,   164,   165,   168,   170,
     173,   176,   177,   178,   180,   185,   189,   190,   191,   199,
     204,   305,   306,   224,   224,   224,   224,   248,   250,   224,
      68,   130,   156,   163,   173,   200,   202,   203,   216,   223,
     391,   392,   224,   227,   227,   289,   225,   285,   224,    68,
     130,   156,   163,   173,   200,   202,   203,   216,   223,   382,
     383,   224,   224,   228,   235,   235,   235,   224,   228,   488,
     484,   224,   228,   224,   228,   107,   345,   224,   229,   229,
     229,   224,   228,   224,   228,   224,   228,   122,   201,   236,
     227,   224,   224,   228,   333,   408,   359,   339,   128,   128,
     128,   310,   306,   392,   224,   224,   224,    39,    66,    68,
     113,   162,   163,   219,   290,   291,   383,   224,   228,   291
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
#line 397 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 407 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 415 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 419 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 423 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 427 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 433 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 434 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 450 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 456 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 482 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 488 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 497 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 503 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 511 "conf_parser.y"
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
#line 553 "conf_parser.y"
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
#line 612 "conf_parser.y"
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
#line 640 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 648 "conf_parser.y"
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
#line 663 "conf_parser.y"
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
#line 678 "conf_parser.y"
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
#line 687 "conf_parser.y"
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
#line 701 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 710 "conf_parser.y"
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
#line 738 "conf_parser.y"
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
#line 768 "conf_parser.y"
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
#line 793 "conf_parser.y"
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
#line 815 "conf_parser.y"
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
#line 837 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 852 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 870 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 886 "conf_parser.y"
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
#line 903 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 934 "conf_parser.y"
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
#line 950 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 958 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 961 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 966 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 977 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 981 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1007 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1014 "conf_parser.y"
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

    conf         = conf_make(CONF_OPER);
    conf->name   = xstrdup(block_state.name.buf);
    conf->user   = xstrdup(block_state.user.buf);
    conf->host   = xstrdup(block_state.host.buf);

    if (block_state.cert.buf[0])
      conf->certfp = xstrdup(block_state.cert.buf);

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

  case 159:
/* Line 1787 of yacc.c  */
#line 1093 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1134 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1140 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1183 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1215 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1264 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1284 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1288 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1296 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1300 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1304 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1308 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1312 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1316 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1320 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1324 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1328 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1338 "conf_parser.y"
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

  case 219:
/* Line 1787 of yacc.c  */
#line 1350 "conf_parser.y"
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

  case 239:
/* Line 1787 of yacc.c  */
#line 1416 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 240:
/* Line 1787 of yacc.c  */
#line 1422 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
/* Line 1787 of yacc.c  */
#line 1428 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1434 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1440 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1464 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1477 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1483 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1489 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1495 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1504 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1513 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 258:
/* Line 1787 of yacc.c  */
#line 1520 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 259:
/* Line 1787 of yacc.c  */
#line 1524 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 1540 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 267:
/* Line 1787 of yacc.c  */
#line 1550 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1554 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1562 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1567 "conf_parser.y"
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

  case 281:
/* Line 1787 of yacc.c  */
#line 1581 "conf_parser.y"
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

  case 282:
/* Line 1787 of yacc.c  */
#line 1601 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1607 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1616 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1620 "conf_parser.y"
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

  case 297:
/* Line 1787 of yacc.c  */
#line 1663 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 298:
/* Line 1787 of yacc.c  */
#line 1669 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1675 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1681 "conf_parser.y"
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

  case 301:
/* Line 1787 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 305:
/* Line 1787 of yacc.c  */
#line 1699 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 306:
/* Line 1787 of yacc.c  */
#line 1703 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1707 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1711 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1715 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1719 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1723 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1727 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1731 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1735 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1741 "conf_parser.y"
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

  case 316:
/* Line 1787 of yacc.c  */
#line 1755 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1764 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1777 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1784 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1795 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1807 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1822 "conf_parser.y"
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

  case 335:
/* Line 1787 of yacc.c  */
#line 1837 "conf_parser.y"
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

  case 336:
/* Line 1787 of yacc.c  */
#line 1848 "conf_parser.y"
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

  case 343:
/* Line 1787 of yacc.c  */
#line 1865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1871 "conf_parser.y"
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

  case 345:
/* Line 1787 of yacc.c  */
#line 1890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 349:
/* Line 1787 of yacc.c  */
#line 1897 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 350:
/* Line 1787 of yacc.c  */
#line 1901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 1909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1921 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1929 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1951 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 1966 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 1979 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 1983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 1987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 1991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 1995 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 1999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2003 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2007 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2011 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2015 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2024 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2032 "conf_parser.y"
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

  case 400:
/* Line 1787 of yacc.c  */
#line 2102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2108 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 402:
/* Line 1787 of yacc.c  */
#line 2114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2120 "conf_parser.y"
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

  case 404:
/* Line 1787 of yacc.c  */
#line 2133 "conf_parser.y"
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

  case 405:
/* Line 1787 of yacc.c  */
#line 2146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 406:
/* Line 1787 of yacc.c  */
#line 2152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 407:
/* Line 1787 of yacc.c  */
#line 2158 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2162 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 2170 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 413:
/* Line 1787 of yacc.c  */
#line 2176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2186 "conf_parser.y"
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

  case 416:
/* Line 1787 of yacc.c  */
#line 2197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 418:
/* Line 1787 of yacc.c  */
#line 2209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 2215 "conf_parser.y"
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

  case 420:
/* Line 1787 of yacc.c  */
#line 2230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2234 "conf_parser.y"
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

  case 427:
/* Line 1787 of yacc.c  */
#line 2259 "conf_parser.y"
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

  case 428:
/* Line 1787 of yacc.c  */
#line 2279 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2288 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 430:
/* Line 1787 of yacc.c  */
#line 2292 "conf_parser.y"
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

  case 436:
/* Line 1787 of yacc.c  */
#line 2318 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 437:
/* Line 1787 of yacc.c  */
#line 2324 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 443:
/* Line 1787 of yacc.c  */
#line 2338 "conf_parser.y"
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

  case 444:
/* Line 1787 of yacc.c  */
#line 2355 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2359 "conf_parser.y"
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

  case 451:
/* Line 1787 of yacc.c  */
#line 2381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 452:
/* Line 1787 of yacc.c  */
#line 2387 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2430 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2447 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2453 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2458 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2463 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2468 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2473 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2478 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2483 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2488 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2493 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2498 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2508 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2513 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2524 "conf_parser.y"
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

  case 523:
/* Line 1787 of yacc.c  */
#line 2535 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2540 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2545 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2550 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2563 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2568 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2571 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2576 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2581 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2586 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2591 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2596 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2606 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2611 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2621 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2626 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2631 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2664 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2676 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2682 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2744 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2750 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2753 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2759 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2768 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2771 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 596:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 597:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 598:
/* Line 1787 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2854 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2859 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2874 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2894 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 641:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 642:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 644:
/* Line 1787 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 645:
/* Line 1787 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 646:
/* Line 1787 of yacc.c  */
#line 2947 "conf_parser.y"
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

  case 647:
/* Line 1787 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 648:
/* Line 1787 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6822 "conf_parser.c"
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


