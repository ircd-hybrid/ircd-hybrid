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
     SSL_CERTIFICATE_FINGERPRINT = 405,
     SSL_CONNECTION_REQUIRED = 406,
     SSL_DH_PARAM_FILE = 407,
     STATS_E_DISABLED = 408,
     STATS_I_OPER_ONLY = 409,
     STATS_K_OPER_ONLY = 410,
     STATS_O_OPER_ONLY = 411,
     STATS_P_OPER_ONLY = 412,
     T_ALL = 413,
     T_BOTS = 414,
     T_CALLERID = 415,
     T_CCONN = 416,
     T_CLUSTER = 417,
     T_DEAF = 418,
     T_DEBUG = 419,
     T_DLINE = 420,
     T_EXTERNAL = 421,
     T_FARCONNECT = 422,
     T_FILE = 423,
     T_FULL = 424,
     T_GLOBOPS = 425,
     T_INVISIBLE = 426,
     T_IPV4 = 427,
     T_IPV6 = 428,
     T_LOCOPS = 429,
     T_LOG = 430,
     T_MAX_CLIENTS = 431,
     T_NCHANGE = 432,
     T_NONONREG = 433,
     T_OPERWALL = 434,
     T_RECVQ = 435,
     T_REJ = 436,
     T_RESTART = 437,
     T_SERVER = 438,
     T_SERVICE = 439,
     T_SERVICES_NAME = 440,
     T_SERVNOTICE = 441,
     T_SET = 442,
     T_SHARED = 443,
     T_SIZE = 444,
     T_SKILL = 445,
     T_SOFTCALLERID = 446,
     T_SPY = 447,
     T_SSL = 448,
     T_SSL_CIPHER_LIST = 449,
     T_SSL_CLIENT_METHOD = 450,
     T_SSL_SERVER_METHOD = 451,
     T_SSLV3 = 452,
     T_TLSV1 = 453,
     T_UMODES = 454,
     T_UNAUTH = 455,
     T_UNDLINE = 456,
     T_UNLIMITED = 457,
     T_UNRESV = 458,
     T_UNXLINE = 459,
     T_WALLOP = 460,
     T_WALLOPS = 461,
     T_WEBIRC = 462,
     TBOOL = 463,
     THROTTLE_TIME = 464,
     TKLINE_EXPIRE_NOTICES = 465,
     TMASKED = 466,
     TRUE_NO_OPER_FLOOD = 467,
     TS_MAX_DELTA = 468,
     TS_WARN_DELTA = 469,
     TWODOTS = 470,
     TYPE = 471,
     UNKLINE = 472,
     USE_EGD = 473,
     USE_LOGGING = 474,
     USER = 475,
     VHOST = 476,
     VHOST6 = 477,
     WARN_NO_NLINE = 478,
     XLINE = 479
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
#define SSL_CERTIFICATE_FINGERPRINT 405
#define SSL_CONNECTION_REQUIRED 406
#define SSL_DH_PARAM_FILE 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_O_OPER_ONLY 411
#define STATS_P_OPER_ONLY 412
#define T_ALL 413
#define T_BOTS 414
#define T_CALLERID 415
#define T_CCONN 416
#define T_CLUSTER 417
#define T_DEAF 418
#define T_DEBUG 419
#define T_DLINE 420
#define T_EXTERNAL 421
#define T_FARCONNECT 422
#define T_FILE 423
#define T_FULL 424
#define T_GLOBOPS 425
#define T_INVISIBLE 426
#define T_IPV4 427
#define T_IPV6 428
#define T_LOCOPS 429
#define T_LOG 430
#define T_MAX_CLIENTS 431
#define T_NCHANGE 432
#define T_NONONREG 433
#define T_OPERWALL 434
#define T_RECVQ 435
#define T_REJ 436
#define T_RESTART 437
#define T_SERVER 438
#define T_SERVICE 439
#define T_SERVICES_NAME 440
#define T_SERVNOTICE 441
#define T_SET 442
#define T_SHARED 443
#define T_SIZE 444
#define T_SKILL 445
#define T_SOFTCALLERID 446
#define T_SPY 447
#define T_SSL 448
#define T_SSL_CIPHER_LIST 449
#define T_SSL_CLIENT_METHOD 450
#define T_SSL_SERVER_METHOD 451
#define T_SSLV3 452
#define T_TLSV1 453
#define T_UMODES 454
#define T_UNAUTH 455
#define T_UNDLINE 456
#define T_UNLIMITED 457
#define T_UNRESV 458
#define T_UNXLINE 459
#define T_WALLOP 460
#define T_WALLOPS 461
#define T_WEBIRC 462
#define TBOOL 463
#define THROTTLE_TIME 464
#define TKLINE_EXPIRE_NOTICES 465
#define TMASKED 466
#define TRUE_NO_OPER_FLOOD 467
#define TS_MAX_DELTA 468
#define TS_WARN_DELTA 469
#define TWODOTS 470
#define TYPE 471
#define UNKLINE 472
#define USE_EGD 473
#define USE_LOGGING 474
#define USER 475
#define VHOST 476
#define VHOST6 477
#define WARN_NO_NLINE 478
#define XLINE 479



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 140 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 680 "conf_parser.c"
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
#line 708 "conf_parser.c"

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
#define YYLAST   1223

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  231
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  289
/* YYNRULES -- Number of rules.  */
#define YYNRULES  650
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
     455,   457,   459,   461,   463,   465,   467,   469,   471,   473,
     476,   481,   486,   491,   496,   501,   506,   511,   516,   517,
     523,   527,   529,   531,   533,   535,   537,   539,   541,   543,
     545,   547,   549,   551,   553,   555,   557,   559,   561,   563,
     565,   567,   569,   571,   572,   578,   582,   584,   588,   590,
     594,   596,   600,   602,   604,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   624,   626,   628,   630,   632,   634,
     636,   637,   644,   647,   649,   651,   653,   655,   657,   659,
     661,   663,   665,   667,   669,   671,   673,   675,   677,   679,
     681,   684,   689,   694,   699,   704,   709,   714,   719,   724,
     729,   734,   739,   744,   749,   754,   759,   760,   766,   770,
     772,   774,   776,   777,   784,   785,   791,   795,   797,   799,
     801,   803,   806,   808,   810,   812,   814,   816,   819,   820,
     826,   830,   832,   834,   838,   843,   848,   849,   856,   859,
     861,   863,   865,   867,   869,   871,   873,   875,   877,   880,
     885,   890,   895,   900,   901,   907,   911,   913,   915,   917,
     919,   921,   923,   925,   927,   929,   931,   933,   938,   943,
     948,   949,   956,   959,   961,   963,   965,   967,   970,   975,
     980,   985,   991,   994,   996,   998,  1000,  1005,  1006,  1013,
    1016,  1018,  1020,  1022,  1024,  1027,  1032,  1037,  1038,  1044,
    1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,  1066,
    1068,  1070,  1071,  1078,  1081,  1083,  1085,  1087,  1090,  1095,
    1096,  1102,  1106,  1108,  1110,  1112,  1114,  1116,  1118,  1120,
    1122,  1124,  1126,  1128,  1129,  1136,  1139,  1141,  1143,  1145,
    1147,  1149,  1151,  1153,  1155,  1157,  1159,  1161,  1163,  1165,
    1167,  1169,  1172,  1177,  1182,  1187,  1192,  1197,  1202,  1207,
    1212,  1217,  1218,  1224,  1228,  1230,  1232,  1234,  1239,  1244,
    1249,  1254,  1259,  1260,  1267,  1270,  1272,  1274,  1276,  1278,
    1283,  1288,  1289,  1296,  1299,  1301,  1303,  1305,  1307,  1312,
    1317,  1323,  1326,  1328,  1330,  1332,  1337,  1338,  1345,  1348,
    1350,  1352,  1354,  1356,  1361,  1366,  1372,  1375,  1377,  1379,
    1381,  1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,  1419,
    1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,
    1441,  1443,  1445,  1447,  1449,  1451,  1453,  1455,  1457,  1459,
    1461,  1463,  1465,  1467,  1469,  1471,  1473,  1478,  1483,  1488,
    1493,  1498,  1503,  1508,  1513,  1518,  1523,  1528,  1533,  1538,
    1543,  1548,  1553,  1558,  1563,  1568,  1573,  1578,  1583,  1588,
    1593,  1598,  1603,  1608,  1613,  1618,  1623,  1628,  1633,  1638,
    1643,  1648,  1653,  1658,  1663,  1668,  1673,  1678,  1683,  1688,
    1693,  1694,  1700,  1704,  1706,  1708,  1710,  1712,  1714,  1716,
    1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,
    1738,  1740,  1742,  1744,  1746,  1748,  1749,  1755,  1759,  1761,
    1763,  1765,  1767,  1769,  1771,  1773,  1775,  1777,  1779,  1781,
    1783,  1785,  1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,
    1803,  1808,  1813,  1818,  1824,  1827,  1829,  1831,  1833,  1835,
    1837,  1839,  1841,  1843,  1845,  1847,  1849,  1851,  1853,  1855,
    1860,  1865,  1870,  1875,  1880,  1885,  1890,  1895,  1900,  1905,
    1910,  1915,  1921,  1924,  1926,  1928,  1930,  1932,  1934,  1936,
    1938,  1940,  1942,  1944,  1949,  1954,  1959,  1964,  1969,  1974,
    1979
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     232,     0,    -1,    -1,   232,   233,    -1,   267,    -1,   279,
      -1,   293,    -1,   494,    -1,   313,    -1,   336,    -1,   350,
      -1,   243,    -1,   509,    -1,   365,    -1,   372,    -1,   376,
      -1,   386,    -1,   395,    -1,   416,    -1,   422,    -1,   428,
      -1,   438,    -1,   432,    -1,   238,    -1,   273,    -1,     1,
     225,    -1,     1,   226,    -1,    -1,   235,    -1,   107,   234,
      -1,   107,   134,   234,    -1,   107,   135,   234,    -1,   107,
     136,   234,    -1,   107,   137,   234,    -1,   107,   138,   234,
      -1,   107,   139,   234,    -1,   107,   140,   234,    -1,    -1,
     237,    -1,   107,   236,    -1,   107,     9,   236,    -1,   107,
      10,   236,    -1,   107,    11,   236,    -1,    95,   227,   239,
     226,   225,    -1,   239,   240,    -1,   240,    -1,   241,    -1,
     242,    -1,     1,   225,    -1,    94,   228,   122,   225,    -1,
     118,   228,   122,   225,    -1,   144,   227,   244,   226,   225,
      -1,   244,   245,    -1,   245,    -1,   256,    -1,   261,    -1,
     266,    -1,   258,    -1,   259,    -1,   260,    -1,   263,    -1,
     264,    -1,   265,    -1,   254,    -1,   253,    -1,   262,    -1,
     257,    -1,   252,    -1,   246,    -1,   247,    -1,   255,    -1,
       1,   225,    -1,   195,   228,   248,   225,    -1,   196,   228,
     250,   225,    -1,   248,   229,   249,    -1,   249,    -1,   197,
      -1,   198,    -1,   250,   229,   251,    -1,   251,    -1,   197,
      -1,   198,    -1,   149,   228,   122,   225,    -1,   132,   228,
     122,   225,    -1,   152,   228,   122,   225,    -1,   194,   228,
     122,   225,    -1,    97,   228,   122,   225,    -1,    63,   228,
     122,   225,    -1,    24,   228,   122,   225,    -1,   101,   228,
     122,   225,    -1,   100,   228,   122,   225,    -1,   221,   228,
     122,   225,    -1,   222,   228,   122,   225,    -1,   176,   228,
     107,   225,    -1,    85,   228,   107,   225,    -1,    89,   228,
     107,   225,    -1,    56,   228,   208,   225,    -1,     4,   227,
     268,   226,   225,    -1,   268,   269,    -1,   269,    -1,   270,
      -1,   272,    -1,   271,    -1,     1,   225,    -1,    97,   228,
     122,   225,    -1,    31,   228,   122,   225,    -1,    24,   228,
     122,   225,    -1,    -1,    96,   274,   227,   275,   226,   225,
      -1,   275,   276,    -1,   276,    -1,   277,    -1,   278,    -1,
       1,   225,    -1,    75,   228,   122,   225,    -1,   168,   228,
     122,   225,    -1,   175,   227,   280,   226,   225,    -1,   280,
     281,    -1,   281,    -1,   282,    -1,   283,    -1,     1,   225,
      -1,   219,   228,   208,   225,    -1,    -1,   284,   168,   227,
     285,   226,   225,    -1,   285,   286,    -1,   286,    -1,   287,
      -1,   289,    -1,   288,    -1,     1,   225,    -1,    97,   228,
     122,   225,    -1,   189,   228,   237,   225,    -1,   189,   228,
     202,   225,    -1,    -1,   216,   290,   228,   291,   225,    -1,
     291,   229,   292,    -1,   292,    -1,   220,    -1,   113,    -1,
      39,    -1,   165,    -1,    68,    -1,    66,    -1,   164,    -1,
      -1,   113,   294,   227,   295,   226,   225,    -1,   295,   296,
      -1,   296,    -1,   297,    -1,   298,    -1,   299,    -1,   305,
      -1,   304,    -1,   300,    -1,   301,    -1,   302,    -1,   303,
      -1,   309,    -1,     1,   225,    -1,    97,   228,   122,   225,
      -1,   220,   228,   122,   225,    -1,   117,   228,   122,   225,
      -1,    32,   228,   208,   225,    -1,   133,   228,   122,   225,
      -1,   150,   228,   122,   225,    -1,   151,   228,   208,   225,
      -1,    17,   228,   122,   225,    -1,    -1,   199,   306,   228,
     307,   225,    -1,   307,   229,   308,    -1,   308,    -1,   159,
      -1,   161,    -1,   163,    -1,   164,    -1,   169,    -1,    48,
      -1,   190,    -1,   177,    -1,   181,    -1,   200,    -1,   192,
      -1,   166,    -1,   179,    -1,   186,    -1,   171,    -1,   205,
      -1,   191,    -1,   160,    -1,   174,    -1,   178,    -1,   167,
      -1,    -1,    62,   310,   228,   311,   225,    -1,   311,   229,
     312,    -1,   312,    -1,    66,   230,   128,    -1,    66,    -1,
      18,   230,   128,    -1,    18,    -1,   148,   230,   128,    -1,
     148,    -1,    68,    -1,   217,    -1,   165,    -1,   201,    -1,
     224,    -1,    39,    -1,    25,    -1,   182,    -1,   127,    -1,
       4,    -1,   179,    -1,   170,    -1,   206,    -1,   174,    -1,
     129,    -1,   187,    -1,    94,    -1,    -1,    17,   314,   227,
     315,   226,   225,    -1,   315,   316,    -1,   316,    -1,   317,
      -1,   327,    -1,   328,    -1,   318,    -1,   329,    -1,   319,
      -1,   320,    -1,   321,    -1,   322,    -1,   323,    -1,   324,
      -1,   325,    -1,   326,    -1,   330,    -1,   331,    -1,   332,
      -1,     1,   225,    -1,    97,   228,   122,   225,    -1,   120,
     228,   235,   225,    -1,   109,   228,   107,   225,    -1,    19,
     228,   235,   225,    -1,    87,   228,   107,   225,    -1,    80,
     228,   107,   225,    -1,    83,   228,   107,   225,    -1,    81,
     228,   107,   225,    -1,   142,   228,   237,   225,    -1,   180,
     228,   237,   225,    -1,    15,   228,   107,   225,    -1,    16,
     228,   107,   225,    -1,   108,   228,   107,   225,    -1,    91,
     228,   235,   225,    -1,    82,   228,   235,   225,    -1,    -1,
      62,   333,   228,   334,   225,    -1,   334,   229,   335,    -1,
     335,    -1,   123,    -1,    50,    -1,    -1,    74,   337,   227,
     342,   226,   225,    -1,    -1,    62,   339,   228,   340,   225,
      -1,   340,   229,   341,    -1,   341,    -1,   193,    -1,    48,
      -1,   183,    -1,   342,   343,    -1,   343,    -1,   344,    -1,
     338,    -1,   348,    -1,   349,    -1,     1,   225,    -1,    -1,
     121,   228,   346,   345,   225,    -1,   346,   229,   347,    -1,
     347,    -1,   107,    -1,   107,   215,   107,    -1,    60,   228,
     122,   225,    -1,    55,   228,   122,   225,    -1,    -1,    61,
     351,   227,   352,   226,   225,    -1,   352,   353,    -1,   353,
      -1,   354,    -1,   355,    -1,   356,    -1,   358,    -1,   362,
      -1,   363,    -1,   364,    -1,   357,    -1,     1,   225,    -1,
     220,   228,   122,   225,    -1,   117,   228,   122,   225,    -1,
      17,   228,   122,   225,    -1,    32,   228,   208,   225,    -1,
      -1,    62,   359,   228,   360,   225,    -1,   360,   229,   361,
      -1,   361,    -1,   147,    -1,    33,    -1,    69,    -1,    98,
      -1,    13,    -1,   106,    -1,    42,    -1,   131,    -1,   207,
      -1,    99,    -1,   146,   228,   122,   225,    -1,   126,   228,
     122,   225,    -1,   125,   228,   107,   225,    -1,    -1,   130,
     366,   227,   367,   226,   225,    -1,   367,   368,    -1,   368,
      -1,   369,    -1,   370,    -1,   371,    -1,     1,   225,    -1,
      75,   228,   122,   225,    -1,   124,   228,   122,   225,    -1,
      34,   228,   122,   225,    -1,   184,   227,   373,   226,   225,
      -1,   373,   374,    -1,   374,    -1,   375,    -1,     1,    -1,
      97,   228,   122,   225,    -1,    -1,   188,   377,   227,   378,
     226,   225,    -1,   378,   379,    -1,   379,    -1,   380,    -1,
     381,    -1,   382,    -1,     1,   225,    -1,    97,   228,   122,
     225,    -1,   220,   228,   122,   225,    -1,    -1,   216,   383,
     228,   384,   225,    -1,   384,   229,   385,    -1,   385,    -1,
      68,    -1,   217,    -1,   165,    -1,   201,    -1,   224,    -1,
     204,    -1,   130,    -1,   203,    -1,   174,    -1,   158,    -1,
      -1,   162,   387,   227,   388,   226,   225,    -1,   388,   389,
      -1,   389,    -1,   390,    -1,   391,    -1,     1,   225,    -1,
      97,   228,   122,   225,    -1,    -1,   216,   392,   228,   393,
     225,    -1,   393,   229,   394,    -1,   394,    -1,    68,    -1,
     217,    -1,   165,    -1,   201,    -1,   224,    -1,   204,    -1,
     130,    -1,   203,    -1,   174,    -1,   158,    -1,    -1,    18,
     396,   227,   397,   226,   225,    -1,   397,   398,    -1,   398,
      -1,   399,    -1,   400,    -1,   401,    -1,   402,    -1,   403,
      -1,   404,    -1,   406,    -1,   405,    -1,   415,    -1,   407,
      -1,   412,    -1,   413,    -1,   414,    -1,   411,    -1,     1,
     225,    -1,    97,   228,   122,   225,    -1,    55,   228,   122,
     225,    -1,   221,   228,   122,   225,    -1,   141,   228,   122,
     225,    -1,     3,   228,   122,   225,    -1,   150,   228,   122,
     225,    -1,   121,   228,   107,   225,    -1,     5,   228,   172,
     225,    -1,     5,   228,   173,   225,    -1,    -1,    62,   408,
     228,   409,   225,    -1,   409,   229,   410,    -1,   410,    -1,
       8,    -1,   193,    -1,    32,   228,   208,   225,    -1,    57,
     228,   122,   225,    -1,    72,   228,   122,   225,    -1,    17,
     228,   122,   225,    -1,   194,   228,   122,   225,    -1,    -1,
      66,   417,   227,   418,   226,   225,    -1,   418,   419,    -1,
     419,    -1,   420,    -1,   421,    -1,     1,    -1,   220,   228,
     122,   225,    -1,   124,   228,   122,   225,    -1,    -1,    23,
     423,   227,   424,   226,   225,    -1,   424,   425,    -1,   425,
      -1,   426,    -1,   427,    -1,     1,    -1,    60,   228,   122,
     225,    -1,   124,   228,   122,   225,    -1,    34,   227,   429,
     226,   225,    -1,   429,   430,    -1,   430,    -1,   431,    -1,
       1,    -1,    60,   228,   122,   225,    -1,    -1,    37,   433,
     227,   434,   226,   225,    -1,   434,   435,    -1,   435,    -1,
     436,    -1,   437,    -1,     1,    -1,    97,   228,   122,   225,
      -1,   124,   228,   122,   225,    -1,    38,   227,   439,   226,
     225,    -1,   439,   440,    -1,   440,    -1,   449,    -1,   450,
      -1,   451,    -1,   452,    -1,   453,    -1,   454,    -1,   455,
      -1,   456,    -1,   457,    -1,   458,    -1,   448,    -1,   460,
      -1,   461,    -1,   475,    -1,   463,    -1,   465,    -1,   467,
      -1,   466,    -1,   470,    -1,   464,    -1,   471,    -1,   472,
      -1,   473,    -1,   474,    -1,   487,    -1,   476,    -1,   477,
      -1,   478,    -1,   483,    -1,   468,    -1,   469,    -1,   493,
      -1,   491,    -1,   492,    -1,   482,    -1,   459,    -1,   480,
      -1,   481,    -1,   447,    -1,   442,    -1,   443,    -1,   444,
      -1,   445,    -1,   446,    -1,   462,    -1,   441,    -1,   479,
      -1,     1,    -1,    90,   228,   107,   225,    -1,    41,   228,
     208,   225,    -1,    40,   228,   235,   225,    -1,    45,   228,
     235,   225,    -1,    43,   228,   107,   225,    -1,    44,   228,
     107,   225,    -1,   210,   228,   208,   225,    -1,    67,   228,
     235,   225,    -1,    54,   228,   208,   225,    -1,    58,   228,
     208,   225,    -1,    35,   228,   208,   225,    -1,     6,   228,
     208,   225,    -1,    86,   228,   235,   225,    -1,    84,   228,
     107,   225,    -1,    76,   228,   107,   225,    -1,     7,   228,
     235,   225,    -1,   214,   228,   235,   225,    -1,   213,   228,
     235,   225,    -1,    47,   228,   107,   225,    -1,    59,   228,
     208,   225,    -1,   223,   228,   208,   225,    -1,   153,   228,
     208,   225,    -1,   156,   228,   208,   225,    -1,   157,   228,
     208,   225,    -1,   155,   228,   208,   225,    -1,   155,   228,
     211,   225,    -1,   154,   228,   208,   225,    -1,   154,   228,
     211,   225,    -1,   115,   228,   235,   225,    -1,    12,   228,
     235,   225,    -1,   114,   228,   208,   225,    -1,   116,   228,
     235,   225,    -1,   145,   228,   208,   225,    -1,   105,   228,
     208,   225,    -1,   212,   228,   208,   225,    -1,   111,   228,
     208,   225,    -1,    29,   228,   107,   225,    -1,    88,   228,
     107,   225,    -1,   218,   228,   208,   225,    -1,    30,   228,
     122,   225,    -1,   185,   228,   122,   225,    -1,   119,   228,
     208,   225,    -1,    26,   228,   208,   225,    -1,   209,   228,
     235,   225,    -1,    -1,   112,   484,   228,   485,   225,    -1,
     485,   229,   486,    -1,   486,    -1,   159,    -1,   161,    -1,
     163,    -1,   164,    -1,   169,    -1,    48,    -1,   190,    -1,
     177,    -1,   181,    -1,   200,    -1,   192,    -1,   166,    -1,
     179,    -1,   186,    -1,   171,    -1,   205,    -1,   191,    -1,
     160,    -1,   174,    -1,   178,    -1,   167,    -1,    -1,   110,
     488,   228,   489,   225,    -1,   489,   229,   490,    -1,   490,
      -1,   159,    -1,   161,    -1,   163,    -1,   164,    -1,   169,
      -1,   190,    -1,    48,    -1,   177,    -1,   181,    -1,   200,
      -1,   192,    -1,   166,    -1,   179,    -1,   186,    -1,   171,
      -1,   205,    -1,   191,    -1,   160,    -1,   174,    -1,   178,
      -1,   167,    -1,    92,   228,   107,   225,    -1,    93,   228,
     107,   225,    -1,    20,   228,   107,   225,    -1,    14,   227,
     495,   226,   225,    -1,   495,   496,    -1,   496,    -1,   502,
      -1,   498,    -1,   499,    -1,   500,    -1,   501,    -1,   503,
      -1,   504,    -1,   505,    -1,   506,    -1,   507,    -1,   508,
      -1,   497,    -1,     1,    -1,    27,   228,   208,   225,    -1,
      70,   228,   235,   225,    -1,    71,   228,   235,   225,    -1,
      79,   228,   107,   225,    -1,    78,   228,   107,   225,    -1,
      77,   228,   107,   225,    -1,    22,   228,   107,   225,    -1,
      21,   228,   107,   225,    -1,   103,   228,   208,   225,    -1,
     104,   228,   208,   225,    -1,    64,   228,   107,   225,    -1,
      65,   228,   235,   225,    -1,   143,   227,   510,   226,   225,
      -1,   510,   511,    -1,   511,    -1,   512,    -1,   513,    -1,
     514,    -1,   515,    -1,   517,    -1,   518,    -1,   516,    -1,
     519,    -1,     1,    -1,    36,   228,   208,   225,    -1,    28,
     228,   208,   225,    -1,    52,   228,   208,   225,    -1,    53,
     228,   208,   225,    -1,    49,   228,   122,   225,    -1,    73,
     228,   235,   225,    -1,    48,   228,   208,   225,    -1,    51,
     228,   208,   225,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   368,   368,   369,   372,   373,   374,   375,   376,   377,
     378,   379,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   398,   398,   399,
     403,   407,   411,   415,   419,   423,   427,   433,   433,   434,
     435,   436,   437,   444,   447,   447,   448,   448,   448,   450,
     456,   463,   465,   465,   466,   466,   467,   467,   468,   468,
     469,   469,   470,   470,   471,   471,   472,   472,   473,   473,
     474,   475,   478,   479,   481,   481,   482,   488,   496,   496,
     497,   503,   511,   553,   612,   640,   648,   663,   678,   687,
     701,   710,   738,   768,   793,   815,   837,   846,   848,   848,
     849,   849,   850,   850,   852,   861,   870,   883,   882,   900,
     900,   901,   901,   901,   903,   909,   918,   919,   919,   921,
     921,   922,   924,   931,   931,   944,   945,   947,   947,   948,
     948,   950,   958,   961,   967,   966,   972,   972,   973,   977,
     981,   985,   989,   993,   997,  1008,  1007,  1087,  1087,  1088,
    1088,  1088,  1089,  1089,  1089,  1090,  1090,  1091,  1092,  1092,
    1094,  1100,  1106,  1112,  1123,  1129,  1135,  1146,  1153,  1152,
    1158,  1158,  1159,  1163,  1167,  1171,  1175,  1179,  1183,  1187,
    1191,  1195,  1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,
    1231,  1235,  1239,  1246,  1245,  1251,  1251,  1252,  1256,  1260,
    1264,  1268,  1272,  1276,  1280,  1284,  1288,  1292,  1296,  1300,
    1304,  1308,  1312,  1316,  1320,  1324,  1328,  1332,  1336,  1340,
    1351,  1350,  1411,  1411,  1412,  1413,  1413,  1414,  1415,  1416,
    1417,  1418,  1419,  1420,  1421,  1422,  1422,  1423,  1424,  1425,
    1426,  1428,  1434,  1440,  1446,  1452,  1458,  1464,  1470,  1476,
    1482,  1489,  1495,  1501,  1507,  1516,  1526,  1525,  1531,  1531,
    1532,  1536,  1547,  1546,  1553,  1552,  1557,  1557,  1558,  1562,
    1566,  1572,  1572,  1573,  1573,  1573,  1573,  1573,  1575,  1575,
    1577,  1577,  1579,  1593,  1613,  1619,  1629,  1628,  1670,  1670,
    1671,  1671,  1671,  1671,  1672,  1672,  1672,  1673,  1673,  1675,
    1681,  1687,  1693,  1705,  1704,  1710,  1710,  1711,  1715,  1719,
    1723,  1727,  1731,  1735,  1739,  1743,  1747,  1753,  1767,  1776,
    1790,  1789,  1804,  1804,  1805,  1805,  1805,  1805,  1807,  1813,
    1819,  1829,  1831,  1831,  1832,  1832,  1834,  1850,  1849,  1874,
    1874,  1875,  1875,  1875,  1875,  1877,  1883,  1903,  1902,  1908,
    1908,  1909,  1913,  1917,  1921,  1925,  1929,  1933,  1937,  1941,
    1945,  1955,  1954,  1975,  1975,  1976,  1976,  1976,  1978,  1985,
    1984,  1990,  1990,  1991,  1995,  1999,  2003,  2007,  2011,  2015,
    2019,  2023,  2027,  2037,  2036,  2106,  2106,  2107,  2107,  2107,
    2108,  2108,  2109,  2110,  2110,  2110,  2111,  2111,  2111,  2112,
    2112,  2113,  2115,  2121,  2127,  2133,  2146,  2159,  2165,  2171,
    2175,  2184,  2183,  2188,  2188,  2189,  2193,  2199,  2210,  2216,
    2222,  2228,  2244,  2243,  2269,  2269,  2270,  2270,  2270,  2272,
    2292,  2302,  2301,  2328,  2328,  2329,  2329,  2329,  2331,  2337,
    2346,  2348,  2348,  2349,  2349,  2351,  2369,  2368,  2391,  2391,
    2392,  2392,  2392,  2394,  2400,  2409,  2412,  2412,  2413,  2413,
    2414,  2414,  2415,  2415,  2416,  2416,  2417,  2417,  2418,  2419,
    2420,  2420,  2421,  2421,  2422,  2422,  2423,  2423,  2424,  2424,
    2425,  2425,  2426,  2426,  2427,  2427,  2428,  2428,  2429,  2429,
    2430,  2430,  2431,  2431,  2432,  2433,  2434,  2434,  2435,  2435,
    2436,  2437,  2438,  2439,  2439,  2440,  2443,  2448,  2454,  2460,
    2466,  2471,  2476,  2481,  2486,  2491,  2496,  2501,  2506,  2511,
    2516,  2521,  2526,  2531,  2537,  2548,  2553,  2558,  2563,  2568,
    2573,  2576,  2581,  2584,  2589,  2594,  2599,  2604,  2609,  2614,
    2619,  2624,  2629,  2634,  2639,  2644,  2653,  2662,  2667,  2672,
    2678,  2677,  2682,  2682,  2683,  2686,  2689,  2692,  2695,  2698,
    2701,  2704,  2707,  2710,  2713,  2716,  2719,  2722,  2725,  2728,
    2731,  2734,  2737,  2740,  2743,  2749,  2748,  2753,  2753,  2754,
    2757,  2760,  2763,  2766,  2769,  2772,  2775,  2778,  2781,  2784,
    2787,  2790,  2793,  2796,  2799,  2802,  2805,  2808,  2811,  2814,
    2819,  2824,  2829,  2838,  2841,  2841,  2842,  2843,  2843,  2844,
    2844,  2845,  2846,  2847,  2848,  2849,  2849,  2850,  2850,  2852,
    2857,  2862,  2867,  2872,  2877,  2882,  2887,  2892,  2897,  2902,
    2907,  2915,  2918,  2918,  2919,  2919,  2920,  2921,  2922,  2923,
    2923,  2924,  2925,  2927,  2933,  2939,  2945,  2951,  2960,  2974,
    2980
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
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_PARAM_FILE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "T_ALL", "T_BOTS", "T_CALLERID", "T_CCONN",
  "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FARCONNECT", "T_FILE", "T_FULL", "T_GLOBOPS", "T_INVISIBLE", "T_IPV4",
  "T_IPV6", "T_LOCOPS", "T_LOG", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_NONONREG", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_RESTART", "T_SERVER",
  "T_SERVICE", "T_SERVICES_NAME", "T_SERVNOTICE", "T_SET", "T_SHARED",
  "T_SIZE", "T_SKILL", "T_SOFTCALLERID", "T_SPY", "T_SSL",
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
  "oper_encrypted", "oper_rsa_public_key_file",
  "oper_ssl_certificate_fingerprint", "oper_ssl_connection_required",
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
  "connect_accept_password", "connect_ssl_certificate_fingerprint",
  "connect_port", "connect_aftype", "connect_flags", "$@20",
  "connect_flags_items", "connect_flags_item", "connect_encrypted",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_ssl_cipher_list", "kill_entry", "$@21", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@22",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@23",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_havent_read_conf",
  "general_invisible_on_connect", "general_warn_no_nline",
  "general_stats_e_disabled", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_dots_in_ident", "general_max_targets",
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@24", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@25", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels", "channel_knock_delay",
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
     475,   476,   477,   478,   479,    59,   125,   123,    61,    44,
      58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   231,   232,   232,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   234,   235,
     235,   235,   235,   235,   235,   235,   235,   236,   236,   237,
     237,   237,   237,   238,   239,   239,   240,   240,   240,   241,
     242,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   246,   247,   248,   248,   249,   249,   250,   250,
     251,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   268,   268,
     269,   269,   269,   269,   270,   271,   272,   274,   273,   275,
     275,   276,   276,   276,   277,   278,   279,   280,   280,   281,
     281,   281,   282,   284,   283,   285,   285,   286,   286,   286,
     286,   287,   288,   288,   290,   289,   291,   291,   292,   292,
     292,   292,   292,   292,   292,   294,   293,   295,   295,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   306,   305,
     307,   307,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   310,   309,   311,   311,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     314,   313,   315,   315,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   317,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   333,   332,   334,   334,
     335,   335,   337,   336,   339,   338,   340,   340,   341,   341,
     341,   342,   342,   343,   343,   343,   343,   343,   345,   344,
     346,   346,   347,   347,   348,   349,   351,   350,   352,   352,
     353,   353,   353,   353,   353,   353,   353,   353,   353,   354,
     355,   356,   357,   359,   358,   360,   360,   361,   361,   361,
     361,   361,   361,   361,   361,   361,   361,   362,   363,   364,
     366,   365,   367,   367,   368,   368,   368,   368,   369,   370,
     371,   372,   373,   373,   374,   374,   375,   377,   376,   378,
     378,   379,   379,   379,   379,   380,   381,   383,   382,   384,
     384,   385,   385,   385,   385,   385,   385,   385,   385,   385,
     385,   387,   386,   388,   388,   389,   389,   389,   390,   392,
     391,   393,   393,   394,   394,   394,   394,   394,   394,   394,
     394,   394,   394,   396,   395,   397,   397,   398,   398,   398,
     398,   398,   398,   398,   398,   398,   398,   398,   398,   398,
     398,   398,   399,   400,   401,   402,   403,   404,   405,   406,
     406,   408,   407,   409,   409,   410,   410,   411,   412,   413,
     414,   415,   417,   416,   418,   418,   419,   419,   419,   420,
     421,   423,   422,   424,   424,   425,   425,   425,   426,   427,
     428,   429,   429,   430,   430,   431,   433,   432,   434,   434,
     435,   435,   435,   436,   437,   438,   439,   439,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   465,   466,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     484,   483,   485,   485,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   486,   486,   486,   486,   486,
     486,   486,   486,   486,   486,   488,   487,   489,   489,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     491,   492,   493,   494,   495,   495,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   510,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   512,   513,   514,   515,   516,   517,   518,
     519
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     0,     5,
       3,     1,     1,     3,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   220,   383,   431,     0,
     446,     0,   286,   422,   262,     0,   107,   145,   320,     0,
       0,   361,     0,     0,   337,     3,    23,    11,     4,    24,
       5,     6,     8,     9,    10,    13,    14,    15,    16,    17,
      18,    19,    20,    22,    21,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    99,   100,   102,   101,   618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   605,   617,   607,   608,   609,   610,   606,
     611,   612,   613,   614,   615,   616,     0,     0,     0,   444,
       0,     0,   442,   443,     0,   505,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   575,     0,   550,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   503,   497,   498,   499,   500,
     501,   496,   468,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   493,   469,   470,   502,   472,   477,   473,
     475,   474,   487,   488,   476,   478,   479,   480,   481,   471,
     483,   484,   485,   504,   494,   495,   492,   486,   482,   490,
     491,   489,     0,     0,     0,     0,     0,     0,     0,    45,
      46,    47,     0,     0,     0,   642,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   633,   634,   635,   636,   637,
     640,   638,   639,   641,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    53,    68,    69,    67,    64,    63,    70,
      54,    66,    57,    58,    59,    55,    65,    60,    61,    62,
      56,     0,     0,     0,     0,   118,   119,   120,     0,   335,
       0,     0,   333,   334,     0,   103,     0,     0,     0,     0,
      98,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,     0,     0,     0,     0,   256,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   223,   224,   227,   229,   230,   231,   232,
     233,   234,   235,   236,   225,   226,   228,   237,   238,   239,
       0,     0,     0,     0,     0,     0,     0,   411,     0,     0,
       0,     0,     0,     0,     0,     0,   386,   387,   388,   389,
     390,   391,   392,   394,   393,   396,   400,   397,   398,   399,
     395,   437,     0,     0,     0,   434,   435,   436,     0,     0,
     441,   452,     0,     0,     0,   449,   450,   451,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   456,     0,     0,     0,
     303,     0,     0,     0,     0,     0,     0,   289,   290,   291,
     292,   297,   293,   294,   295,   296,   428,     0,     0,     0,
     425,   426,   427,     0,     0,     0,   264,     0,   274,     0,
     272,   273,   275,   276,    48,     0,     0,     0,    44,     0,
       0,     0,     0,   110,   111,   112,     0,     0,     0,   193,
       0,     0,     0,     0,     0,   168,     0,     0,   148,   149,
     150,   151,   154,   155,   156,   157,   153,   152,   158,     0,
       0,     0,     0,     0,   323,   324,   325,   326,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   632,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,     0,     0,
     369,     0,   364,   365,   366,   121,     0,     0,   117,     0,
       0,     0,   332,     0,     0,   347,     0,     0,   340,   341,
     342,   343,     0,     0,     0,    97,     0,     0,     0,     0,
      27,     0,     0,     0,     0,     0,     0,     0,     0,   603,
     240,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   222,   401,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   385,     0,     0,     0,   433,
       0,   440,     0,     0,     0,   448,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   455,   298,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   288,     0,     0,     0,
     424,   277,     0,     0,     0,     0,     0,   271,     0,     0,
      43,   113,     0,     0,     0,   109,   159,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   147,   327,
       0,     0,     0,     0,   322,     0,     0,     0,     0,     0,
       0,     0,     0,   631,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,     0,
      75,    80,    81,     0,    79,     0,     0,    51,   367,     0,
       0,     0,   363,     0,   116,     0,     0,   331,   344,     0,
       0,     0,     0,   339,   106,   105,   104,   626,   625,   619,
     629,    27,    27,    27,    27,    27,    27,    27,    29,    28,
     630,   620,   621,   624,   623,   622,   627,   628,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,     0,   221,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   384,     0,     0,   432,   445,     0,     0,   447,   517,
     521,   535,   602,   548,   542,   545,   516,   508,   507,   510,
     511,   509,   524,   514,   515,   525,   513,   520,   519,   518,
     543,   506,   600,   601,   539,   585,   579,   596,   580,   581,
     582,   590,   599,   583,   593,   597,   586,   598,   591,   587,
     592,   584,   595,   589,   588,   594,     0,   578,   541,   559,
     554,   571,   555,   556,   557,   565,   574,   558,   568,   572,
     561,   573,   566,   562,   567,   560,   570,   564,   563,   569,
       0,   553,   536,   534,   537,   547,   538,   527,   532,   533,
     530,   531,   528,   529,   546,   549,   512,   540,   523,   522,
     544,   526,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,   423,     0,     0,     0,   282,   278,   281,
     263,    49,    50,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     321,   644,   643,   649,   647,   650,   645,   646,   648,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     362,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   336,     0,     0,     0,   338,    30,    31,    32,    33,
      34,    35,    36,   251,   252,   244,   261,   260,     0,   259,
     246,   248,   255,   247,   245,   254,   241,   253,   243,   242,
      37,    37,    37,    39,    38,   249,   250,   406,   409,   410,
     420,   417,   403,   418,   415,   416,     0,   414,   419,   402,
     408,   405,   407,   421,   404,   438,   439,   453,   454,   576,
       0,   551,     0,   301,   302,   311,   308,   313,   309,   310,
     316,   312,   314,   307,   315,     0,   306,   300,   319,   318,
     317,   299,   430,   429,   285,   284,   269,   270,   268,     0,
     267,     0,     0,     0,   114,   115,   167,   163,   212,   200,
     209,   208,   198,   203,   219,   211,   217,   202,   205,   214,
     216,   213,   210,   218,   206,   215,   204,   207,     0,   196,
     160,   162,   164,   165,   166,   177,   172,   189,   173,   174,
     175,   183,   192,   176,   186,   190,   179,   191,   184,   180,
     185,   178,   188,   182,   181,   187,     0,   171,   161,   330,
     328,   329,    74,    78,   368,   373,   379,   382,   375,   381,
     376,   380,   378,   374,   377,     0,   372,   130,     0,     0,
       0,     0,   125,   345,   351,   357,   360,   353,   359,   354,
     358,   356,   352,   355,     0,   350,   346,   257,     0,    40,
      41,    42,   412,     0,   577,   552,   304,     0,   265,     0,
     283,   280,   279,     0,     0,     0,   194,     0,   169,     0,
     370,     0,     0,     0,     0,     0,   124,   348,     0,   258,
     413,   305,   266,   199,   197,   201,   195,   170,   371,   131,
     133,   132,   140,   143,   142,   139,   144,   141,   138,     0,
     137,   349,   135,     0,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   808,   809,  1063,  1064,    26,   218,   219,
     220,   221,    27,   262,   263,   264,   265,   769,   770,   773,
     774,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,    28,    74,    75,    76,
      77,    78,    29,    61,   492,   493,   494,   495,    30,   284,
     285,   286,   287,   288,  1026,  1027,  1028,  1029,  1030,  1200,
    1269,  1270,    31,    62,   507,   508,   509,   510,   511,   512,
     513,   514,   515,   516,   517,   735,  1176,  1177,   518,   729,
    1148,  1149,    32,    51,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   604,  1048,  1049,    33,    59,   478,   714,  1119,
    1120,   479,   480,   481,  1123,   968,   969,   482,   483,    34,
      57,   456,   457,   458,   459,   460,   461,   462,   699,  1105,
    1106,   463,   464,   465,    35,    63,   523,   524,   525,   526,
     527,    36,   291,   292,   293,    37,    69,   577,   578,   579,
     580,   581,   790,  1214,  1215,    38,    66,   561,   562,   563,
     564,   780,  1195,  1196,    39,    52,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   626,  1076,  1077,
     376,   377,   378,   379,   380,    40,    58,   469,   470,   471,
     472,    41,    53,   384,   385,   386,   387,    42,   111,   112,
     113,    43,    55,   394,   395,   396,   397,    44,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   426,   930,   931,   208,   424,   906,   907,
     209,   210,   211,    45,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,    46,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1050
static const yytype_int16 yypact[] =
{
   -1050,   656, -1050,  -170,  -181,  -163, -1050, -1050, -1050,  -158,
   -1050,  -151, -1050, -1050, -1050,  -111, -1050, -1050, -1050,   -93,
     -87, -1050,   -69,   -58, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,    20,
     926,   -33,    -3,     0,    30,    11,   387,    39,    62,    74,
     197,    81,    82,    83,   685,   428,    87,    40,    60,    91,
    -176,    29,    43,    66,     8, -1050, -1050, -1050, -1050, -1050,
      94,    95,   109,   111,   112,   113,   115,   116,   117,   118,
     122,   123,     7, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,   683,   364,    35, -1050,
     124,    23, -1050, -1050,   200, -1050,   125,   127,   129,   130,
     132,   133,   135,   136,   138,   142,   143,   144,   145,   149,
     150,   151,   152,   155,   156,   157,   159,   161,   162,   164,
     172,   175, -1050,   176, -1050,   177,   181,   182,   183,   184,
     186,   187,   190,   192,   195,   205,   209,   210,   212,   215,
     216,   219,   220,   107, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,   449,    19,   287,   -47,   221,   223,     5, -1050,
   -1050, -1050,    16,   438,     6, -1050,   225,   228,   229,   230,
     231,   232,   236,   237,    14, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050,   110,   240,   244,   246,   248,   250,
     254,   258,   259,   260,   261,   267,   268,   279,   280,   281,
     282,   284,   180, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,    34,   173,   288,     9, -1050, -1050, -1050,   119, -1050,
     298,    44, -1050, -1050,    59, -1050,   214,   303,   393,   302,
   -1050,   423,   427,   328,   430,   431,   431,   431,   432,   439,
     441,   337,   342,   326, -1050,   327,   325,   333,   334, -1050,
     335,   336,   340,   341,   345,   350,   351,   353,   354,   355,
     358,   362,   105, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     331,   363,   365,   370,   374,   378,   379, -1050,   380,   381,
     383,   384,   397,   399,   400,   241, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,   401,   403,    22, -1050, -1050, -1050,   435,   396,
   -1050, -1050,   406,   408,    58, -1050, -1050, -1050,   346,   431,
     431,   458,   433,   463,   516,   434,   431,   437,   536,   539,
     431,   541,   443,   445,   446,   431,   548,   552,   431,   554,
     555,   556,   557,   459,   440,   464,   447,   468,   431,   431,
     469,   470,   472,  -189,  -178,   475,   477,   569,   431,   484,
     487,   431,   431,   488,   489,   476, -1050,   478,   479,   481,
   -1050,   482,   483,   486,   490,   491,   128, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,   492,   496,    79,
   -1050, -1050, -1050,   500,   498,   499, -1050,   501, -1050,   108,
   -1050, -1050, -1050, -1050, -1050,   578,   582,   503, -1050,   506,
     511,   512,    69, -1050, -1050, -1050,   517,   515,   518, -1050,
     519,   520,   522,   525,   526, -1050,   527,    56, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   531,
     529,   532,   540,     4, -1050, -1050, -1050, -1050,   497,   504,
     507,   584,   559,   563,   564,   431,   551, -1050, -1050,   586,
     565,   622,   672,   674,   661,   663,   665,   666,   667,   668,
     688,   675,  -123,  -105,   676,   679,   571, -1050,   577,   566,
   -1050,    25, -1050, -1050, -1050, -1050,   596,   580, -1050,   579,
     686,   585, -1050,   587,   581, -1050,   583,    52, -1050, -1050,
   -1050, -1050,   589,   590,   591, -1050,   592,   594,   599,   601,
     480,   602,   603,   604,   605,   607,   608,   609,   610, -1050,
   -1050,   700,   714,   431,   611,   731,   734,   431,   735,   738,
     431,   715,   742,   745,   431,   748,   748,   632, -1050, -1050,
     737,   -71,   740,   652,   747,   749,   639,   750,   752,   763,
     753,   754,   758,   759,   657, -1050,   761,   762,   660, -1050,
     670, -1050,   764,   766,   673, -1050,   677,   678,   680,   681,
     689,   690,   692,   693,   694,   698,   708,   712,   713,   716,
     720,   724,   725,   727,   729,   733,   736,   739,   741,   743,
     744,   746,   687,   751,   730,   755,   756,   757,   760,   767,
     768,   769,   770,   773,   774,   775,   776,   777,   781,   782,
     783,   784,   785,   786,   787, -1050, -1050,   778,   702,   684,
     791,   833,   837,   838,   840,   788, -1050,   841,   845,   789,
   -1050, -1050,   850,   851,   790,   867,   792, -1050,   794,   795,
   -1050, -1050,   853,   855,   796, -1050, -1050,   856,   771,   797,
     861,   862,   864,   865,   780,   798,   893,   799, -1050, -1050,
     894,   900,   901,   802, -1050,   803,   806,   807,   808,   809,
     810,   811,   812, -1050,   813,   814,   815,   816,   817,   818,
     819,   820,   821,   822,   823,   824,   825, -1050, -1050,  -211,
   -1050, -1050, -1050,  -182, -1050,   826,   827, -1050, -1050,   931,
     828,   829, -1050,   830, -1050,   170,   832, -1050, -1050,   936,
     831,   938,   836, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050,   431,   431,   431,   431,   431,   431,   431, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   839,   842,
     843,   -34,   844,   846,   847,   848,   849,   852,   854,   857,
     858,   859,   317,   860,   863, -1050,   866,   868,   869,   870,
     871,   872,   873,    17,   874,   875,   876,   877,   878,   879,
     880, -1050,   881,   882, -1050, -1050,   883,   884, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,  -177, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
    -171, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050,   885,   886,   534,   887,   888,   889,   890,   891,
   -1050,   892,   895, -1050,   896,   897,   -21,   903,   834, -1050,
   -1050, -1050, -1050,   898,   899, -1050,   902,   904,   465,   905,
     906,   907,   908,   909,   765,   910, -1050,   911,   912,   913,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050,  -123, -1050,  -105, -1050, -1050,   914,   558,
   -1050, -1050,   915,   916,   917, -1050,    67, -1050, -1050, -1050,
   -1050, -1050,   918,   619,   921, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,  -131, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     748,   748,   748, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,  -125, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     687, -1050,   730, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,   -50, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   -49,
   -1050,   955,   867,   922, -1050, -1050, -1050, -1050, -1050,   835,
   -1050, -1050,   919, -1050, -1050, -1050, -1050,   920, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   -20, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050,   -14, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,    -9, -1050, -1050,   944,   -70,
     923,   927, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050,    61, -1050, -1050, -1050,   -34, -1050,
   -1050, -1050, -1050,    17, -1050, -1050, -1050,   534, -1050,   -21,
   -1050, -1050, -1050,   942,   947,   948, -1050,   465, -1050,   765,
   -1050,   558,   928,   929,   930,   329, -1050, -1050,   619, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,    77,
   -1050, -1050, -1050,   329, -1050
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1050, -1050, -1050,  -283,  -303, -1049,  -615, -1050, -1050,   924,
   -1050, -1050, -1050, -1050,   925, -1050, -1050, -1050,   -24, -1050,
      63, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,  1006, -1050,
   -1050, -1050, -1050, -1050, -1050,   595, -1050, -1050, -1050, -1050,
     805, -1050, -1050, -1050, -1050,    55, -1050, -1050, -1050, -1050,
   -1050,  -187, -1050, -1050, -1050,   612, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050,  -149, -1050, -1050,
   -1050,  -145, -1050, -1050, -1050,   793, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050,   -92, -1050, -1050, -1050, -1050, -1050,
    -101, -1050,   662, -1050, -1050, -1050,    26, -1050, -1050, -1050,
   -1050, -1050,   701, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     -68, -1050, -1050, -1050, -1050, -1050, -1050,   633, -1050, -1050,
   -1050, -1050, -1050,   932, -1050, -1050, -1050, -1050,   588, -1050,
   -1050, -1050, -1050, -1050,   -90, -1050, -1050, -1050,   600, -1050,
   -1050, -1050, -1050,   -81, -1050, -1050, -1050,   801, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   -61,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,   695, -1050,
   -1050, -1050, -1050, -1050,   779, -1050, -1050, -1050, -1050,  1056,
   -1050, -1050, -1050, -1050,   800, -1050, -1050, -1050, -1050,  1005,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050,    78, -1050, -1050, -1050,    84,
   -1050, -1050, -1050, -1050, -1050,  1077, -1050, -1050, -1050, -1050,
   -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050,
     937, -1050, -1050, -1050, -1050, -1050, -1050, -1050, -1050
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
     833,   834,   591,   592,   593,   519,   215,   519,    79,    70,
     282,  1219,  1220,  1221,  1012,   225,  1046,   489,  1013,   681,
     466,    70,   682,   381,   109,  1074,   558,  1116,    80,    81,
     683,   109,    71,   684,    82,   558,   381,   832,   520,    72,
     520,   282,   226,  1014,    71,   289,    49,  1015,  1089,   295,
     227,    72,  1090,   573,  1091,    47,    48,   496,  1092,   391,
     573,   289,   228,   229,    50,   230,   231,   232,  1022,    54,
     489,    83,    84,   497,   767,   768,    56,    85,    86,   521,
     466,   521,   382,   110,    87,    88,    89,   233,   498,  1047,
     110,   490,   771,   772,  1217,   382,   647,   648,  1218,   216,
    1222,   837,   838,   654,  1223,    73,   315,   658,   115,   473,
      90,    91,   663,   116,   117,   666,    60,    73,   499,   118,
     316,   317,   559,   217,   318,   676,   677,   119,   522,   447,
     522,   559,  1243,   120,    64,   688,   121,   122,   691,   692,
      65,   290,   123,   467,   490,   448,   383,   124,   125,   574,
     126,   127,   128,   500,   129,   392,   574,   290,    67,   383,
     449,   130,  1117,   474,  1023,   131,   132,   319,   475,    68,
     476,  1022,  1118,   501,   133,  1226,  1228,  -123,   484,  1227,
    1229,   244,   393,   134,   491,   320,   321,   322,   323,   502,
     450,   135,   324,   136,   106,   137,   325,   138,   215,   139,
     140,   391,   326,   467,   245,  1236,   503,   504,  -123,  1237,
    1075,  1238,   141,   327,   328,  1239,  1240,   142,   143,   144,
    1241,   145,   146,   147,   107,   329,   148,   108,   283,   477,
     743,   487,   752,   313,   299,   567,   246,   491,   114,   468,
     536,   560,   350,   247,   351,   451,   352,   330,   638,   389,
     560,   781,   149,   452,   453,   505,  1024,   296,   353,   283,
     150,   151,   152,   153,   154,   248,   212,  1023,   575,   249,
     571,   297,   576,   354,   454,   575,   506,   250,   792,   576,
     251,   252,   737,  1025,   644,   331,  1247,   569,   473,   213,
    1248,   216,   155,  1201,   298,   724,   355,   392,   356,   468,
     820,   214,  1272,   357,   824,   709,  1273,   827,   222,   223,
     224,   831,   253,   358,   281,   217,   156,   157,   294,   158,
     159,   160,   301,   302,   393,   161,  1060,  1061,  1062,   254,
     162,   617,   255,   445,   716,   538,   582,   303,   359,   304,
     305,   306,   474,   307,   308,   309,   310,   475,   455,   476,
     311,   312,   388,   398,   705,   399,   256,   400,   401,  1024,
     402,   403,   360,   404,   405,   350,   406,   351,  1262,   352,
     407,   408,   409,   410,   257,   258,   259,   411,   412,   413,
     414,   353,   361,   415,   416,   417,  1025,   418,   115,   419,
     420,   362,   421,   116,   117,  1263,   354,  1264,   565,   118,
     422,   260,   261,   423,   425,   427,   556,   119,   477,   428,
     429,   430,   431,   120,   432,   433,   121,   122,   434,   355,
     435,   356,   123,   436,   832,   583,   357,   124,   125,   244,
     126,   127,   128,   437,   129,   363,   358,   438,   439,   496,
     440,   130,  1265,   441,   442,   131,   132,   443,   444,   485,
     447,   486,   245,   528,   133,   497,   529,   530,   531,   532,
     533,   359,   364,   134,   534,   535,   448,   634,   539,  1128,
     498,   135,   540,   136,   541,   137,   542,   138,   543,   139,
     140,   449,   544,  1129,   246,   360,   545,   546,   547,   548,
    1130,   247,   141,  1266,  1267,   549,   550,   142,   143,   144,
     499,   145,   146,   147,  1131,   361,   148,   551,   552,   553,
     554,   450,   555,   248,   362,   584,   566,   249,  1036,  1037,
    1038,  1039,  1040,  1041,  1042,   250,   570,   585,   251,   252,
     586,  1132,   149,  1133,   587,   500,   588,   589,   590,   594,
     150,   151,   152,   153,   154,   597,   595,  1095,   596,  1268,
     598,   599,   600,   601,   646,   501,   619,   640,   363,  1134,
     253,   602,   603,   605,   606,   649,   451,  1096,   607,   608,
     651,   502,   155,   609,   452,   453,  1097,   254,   610,   611,
     255,   612,   613,   614,  1244,   364,   615,   590,   503,   504,
     616,   620,  1135,   621,  1136,   454,   156,   157,   622,   158,
     159,   160,   623,  1098,   256,   161,   624,   625,   627,   628,
     162,   629,   630,  1137,   801,   802,   803,   804,   805,   806,
     807,   641,   257,   258,   259,   631,  1185,   632,   633,   636,
    1138,   637,  1099,  1100,   642,  1139,   643,   505,   652,  1140,
    1101,   650,   653,   656,  1141,   655,   657,  1142,   659,   260,
     261,   660,  1143,   661,   662,   664,     2,     3,   506,   665,
       4,   667,   668,   669,   670,  1102,  1144,   671,   672,   455,
       5,  1145,   673,     6,     7,   674,   675,   678,   679,     8,
     680,  1103,  1146,   685,   315,   686,   225,  1204,  1186,  1147,
       9,   687,   689,    10,    11,   690,   693,   694,   316,   317,
     718,   695,   318,   696,   719,   745,   748,   697,   754,   698,
     700,   701,   746,   226,   702,   747,  1187,    12,   703,   704,
     707,   227,    13,  1188,   708,   711,   712,   713,   720,   715,
      14,   721,  1189,   228,   229,   885,   230,   231,   232,   722,
     723,  1104,   726,   727,   756,   319,   728,   730,   731,  1205,
     732,    15,    16,   733,   734,   736,   739,   740,   233,  1190,
     741,  1191,  1192,   320,   321,   322,   323,   749,   742,    17,
     324,   750,   751,   755,   325,  1193,   753,  1206,   909,   757,
     326,   758,  1194,   759,  1207,   760,    18,   761,   762,   763,
     764,   327,   328,  1208,   779,   765,   777,   766,   775,    19,
      20,   776,   778,   329,   783,   784,   785,   818,   786,   789,
     787,   791,   788,  1155,   794,   795,   796,   797,    21,   798,
    1209,   819,  1210,  1211,   799,   330,   800,   810,   811,   812,
     813,    22,   814,   815,   816,   817,  1212,   828,   822,   821,
      23,   823,   825,  1213,    24,   826,   886,   887,   888,   829,
     889,   890,   830,   891,   892,   832,   893,   835,   894,   836,
     840,   895,   839,   331,   896,   897,   898,   843,   899,   841,
     846,   842,   844,   900,   845,   847,   848,   901,   902,   903,
     849,   850,   851,   852,   853,   854,   856,   904,   857,   910,
     911,   912,   905,   913,   914,   855,   915,   916,   858,   917,
     952,   918,   859,   860,   919,   861,   862,   920,   921,   922,
     953,   923,   954,   955,   863,   864,   924,   865,   866,   867,
     925,   926,   927,   868,  1156,  1157,  1158,    79,  1159,  1160,
     928,  1161,  1162,   869,  1163,   929,  1164,   870,   871,  1165,
     956,   872,  1166,  1167,  1168,   873,  1169,    80,    81,   874,
     875,  1170,   876,    82,   877,  1171,  1172,  1173,   878,   957,
     958,   879,   959,   961,   880,  1174,   881,   962,   882,   883,
    1175,   884,   964,   965,   967,   973,   908,   974,   976,   977,
     932,   933,   934,   979,   980,   935,   981,   982,   983,  1182,
      83,    84,   936,   937,   938,   939,    85,    86,   940,   941,
     942,   943,   944,    87,    88,    89,   945,   946,   947,   948,
     949,   950,   951,   960,   963,   985,   987,   970,   966,   971,
     972,   975,   988,   989,   986,   978,   984,   990,   991,    90,
      91,   992,   993,   994,   995,   996,   997,   998,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,
    1011,  1016,  1017,  1018,  1020,  1021,  1019,  1031,  1032,  1033,
    1034,  1035,  1230,  1122,  1043,  1233,  1242,  1044,  1045,  1050,
    1253,  1051,  1052,  1053,  1054,  1254,  1255,  1055,  1183,  1056,
     300,  1202,  1057,  1058,  1059,  1065,  1274,   725,  1066,   568,
    1257,  1067,  1256,  1068,  1069,  1070,  1071,  1072,  1073,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1093,  1094,  1107,  1108,  1109,  1110,  1111,  1112,  1121,   738,
    1113,  1114,  1115,  1124,  1125,   618,  1249,  1126,  1252,  1127,
    1150,  1151,  1152,  1153,  1154,  1178,  1179,  1180,  1181,  1184,
    1197,   717,   488,  1203,  1198,  1199,  1216,  1232,  1231,  1234,
    1235,  1245,  1246,  1259,  1260,  1261,   744,   706,  1271,  1251,
    1258,   782,  1250,   639,   710,   793,   635,   390,   446,   314,
    1225,   537,     0,     0,  1224,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   557,     0,     0,
       0,     0,     0,     0,   645,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   572
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1050)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     615,   616,   305,   306,   307,     1,     1,     1,     1,     1,
       1,  1060,  1061,  1062,   225,     1,    50,     1,   229,   208,
       1,     1,   211,     1,     1,     8,     1,    48,    21,    22,
     208,     1,    24,   211,    27,     1,     1,   107,    34,    31,
      34,     1,    28,   225,    24,     1,   227,   229,   225,   225,
      36,    31,   229,     1,   225,   225,   226,     1,   229,     1,
       1,     1,    48,    49,   227,    51,    52,    53,     1,   227,
       1,    64,    65,    17,   197,   198,   227,    70,    71,    75,
       1,    75,    60,    60,    77,    78,    79,    73,    32,   123,
      60,    75,   197,   198,   225,    60,   399,   400,   229,    94,
     225,   172,   173,   406,   229,    97,     1,   410,     1,     1,
     103,   104,   415,     6,     7,   418,   227,    97,    62,    12,
      15,    16,    97,   118,    19,   428,   429,    20,   124,     1,
     124,    97,   202,    26,   227,   438,    29,    30,   441,   442,
     227,    97,    35,   124,    75,    17,   124,    40,    41,    97,
      43,    44,    45,    97,    47,    97,    97,    97,   227,   124,
      32,    54,   183,    55,    97,    58,    59,    62,    60,   227,
      62,     1,   193,   117,    67,   225,   225,   168,   225,   229,
     229,     1,   124,    76,   168,    80,    81,    82,    83,   133,
      62,    84,    87,    86,   227,    88,    91,    90,     1,    92,
      93,     1,    97,   124,    24,   225,   150,   151,   168,   229,
     193,   225,   105,   108,   109,   229,   225,   110,   111,   112,
     229,   114,   115,   116,   227,   120,   119,   227,   219,   121,
     226,   226,   535,   226,   226,   226,    56,   168,   227,   220,
     226,   216,     1,    63,     3,   117,     5,   142,   226,   226,
     216,   226,   145,   125,   126,   199,   189,   228,    17,   219,
     153,   154,   155,   156,   157,    85,   227,    97,   216,    89,
     226,   228,   220,    32,   146,   216,   220,    97,   226,   220,
     100,   101,   226,   216,   226,   180,   225,   168,     1,   227,
     229,    94,   185,   226,   228,   226,    55,    97,    57,   220,
     603,   227,   225,    62,   607,   226,   229,   610,   227,   227,
     227,   614,   132,    72,   227,   118,   209,   210,   227,   212,
     213,   214,   228,   228,   124,   218,     9,    10,    11,   149,
     223,   226,   152,   226,   226,   225,   122,   228,    97,   228,
     228,   228,    55,   228,   228,   228,   228,    60,   220,    62,
     228,   228,   228,   228,   226,   228,   176,   228,   228,   189,
     228,   228,   121,   228,   228,     1,   228,     3,    39,     5,
     228,   228,   228,   228,   194,   195,   196,   228,   228,   228,
     228,    17,   141,   228,   228,   228,   216,   228,     1,   228,
     228,   150,   228,     6,     7,    66,    32,    68,   225,    12,
     228,   221,   222,   228,   228,   228,   226,    20,   121,   228,
     228,   228,   228,    26,   228,   228,    29,    30,   228,    55,
     228,    57,    35,   228,   107,   122,    62,    40,    41,     1,
      43,    44,    45,   228,    47,   194,    72,   228,   228,     1,
     228,    54,   113,   228,   228,    58,    59,   228,   228,   228,
       1,   228,    24,   228,    67,    17,   228,   228,   228,   228,
     228,    97,   221,    76,   228,   228,    17,   226,   228,     4,
      32,    84,   228,    86,   228,    88,   228,    90,   228,    92,
      93,    32,   228,    18,    56,   121,   228,   228,   228,   228,
      25,    63,   105,   164,   165,   228,   228,   110,   111,   112,
      62,   114,   115,   116,    39,   141,   119,   228,   228,   228,
     228,    62,   228,    85,   150,   122,   228,    89,   801,   802,
     803,   804,   805,   806,   807,    97,   228,   225,   100,   101,
     107,    66,   145,    68,   107,    97,   208,   107,   107,   107,
     153,   154,   155,   156,   157,   208,   107,    13,   107,   220,
     208,   225,   225,   228,   208,   117,   225,   122,   194,    94,
     132,   228,   228,   228,   228,   107,   117,    33,   228,   228,
     107,   133,   185,   228,   125,   126,    42,   149,   228,   228,
     152,   228,   228,   228,  1199,   221,   228,   107,   150,   151,
     228,   228,   127,   228,   129,   146,   209,   210,   228,   212,
     213,   214,   228,    69,   176,   218,   228,   228,   228,   228,
     223,   228,   228,   148,   134,   135,   136,   137,   138,   139,
     140,   225,   194,   195,   196,   228,    68,   228,   228,   228,
     165,   228,    98,    99,   228,   170,   228,   199,   122,   174,
     106,   208,   208,   107,   179,   208,   107,   182,   107,   221,
     222,   208,   187,   208,   208,   107,     0,     1,   220,   107,
       4,   107,   107,   107,   107,   131,   201,   208,   228,   220,
      14,   206,   208,    17,    18,   228,   208,   208,   208,    23,
     208,   147,   217,   208,     1,   208,     1,    68,   130,   224,
      34,   122,   208,    37,    38,   208,   208,   208,    15,    16,
     122,   225,    19,   225,   122,   208,   122,   228,   122,   228,
     228,   228,   208,    28,   228,   208,   158,    61,   228,   228,
     228,    36,    66,   165,   228,   225,   228,   228,   225,   228,
      74,   225,   174,    48,    49,    48,    51,    52,    53,   228,
     228,   207,   225,   228,   122,    62,   228,   228,   228,   130,
     228,    95,    96,   228,   228,   228,   225,   228,    73,   201,
     228,   203,   204,    80,    81,    82,    83,   208,   228,   113,
      87,   208,   208,   208,    91,   217,   225,   158,    48,   107,
      97,   107,   224,   122,   165,   122,   130,   122,   122,   122,
     122,   108,   109,   174,   228,   107,   225,   122,   122,   143,
     144,   122,   225,   120,   208,   225,   227,   107,   122,   228,
     225,   228,   225,    48,   225,   225,   225,   225,   162,   225,
     201,   107,   203,   204,   225,   142,   225,   225,   225,   225,
     225,   175,   225,   225,   225,   225,   217,   122,   107,   228,
     184,   107,   107,   224,   188,   107,   159,   160,   161,   107,
     163,   164,   107,   166,   167,   107,   169,   225,   171,   122,
     208,   174,   122,   180,   177,   178,   179,   228,   181,   122,
     107,   122,   122,   186,   122,   122,   122,   190,   191,   192,
     122,   122,   225,   122,   122,   225,   122,   200,   122,   159,
     160,   161,   205,   163,   164,   225,   166,   167,   225,   169,
     122,   171,   225,   225,   174,   225,   225,   177,   178,   179,
     208,   181,   228,   122,   225,   225,   186,   225,   225,   225,
     190,   191,   192,   225,   159,   160,   161,     1,   163,   164,
     200,   166,   167,   225,   169,   205,   171,   225,   225,   174,
     107,   225,   177,   178,   179,   225,   181,    21,    22,   225,
     225,   186,   225,    27,   225,   190,   191,   192,   225,   122,
     122,   225,   122,   122,   225,   200,   225,   122,   225,   225,
     205,   225,   122,   122,   107,   122,   225,   122,   122,   208,
     225,   225,   225,   122,   122,   225,   122,   122,   208,  1013,
      64,    65,   225,   225,   225,   225,    70,    71,   225,   225,
     225,   225,   225,    77,    78,    79,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   122,   122,   225,   228,   225,
     225,   225,   122,   122,   225,   228,   228,   225,   225,   103,
     104,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   122,   225,   225,   228,   225,   122,   228,
     122,   225,   107,   229,   225,   230,   122,   225,   225,   225,
     128,   225,   225,   225,   225,   128,   128,   225,  1015,   225,
      74,  1026,   225,   225,   225,   225,  1273,   492,   225,   284,
    1239,   225,  1237,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   215,   507,
     225,   225,   225,   225,   225,   332,  1218,   225,  1229,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   479,   218,   225,   228,   228,   225,   225,  1122,   230,
     230,   228,   225,   225,   225,   225,   523,   456,  1248,  1227,
    1241,   561,  1223,   384,   469,   577,   365,   111,   163,    92,
    1092,   234,    -1,    -1,  1090,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   262,    -1,    -1,
      -1,    -1,    -1,    -1,   394,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   232,     0,     1,     4,    14,    17,    18,    23,    34,
      37,    38,    61,    66,    74,    95,    96,   113,   130,   143,
     144,   162,   175,   184,   188,   233,   238,   243,   267,   273,
     279,   293,   313,   336,   350,   365,   372,   376,   386,   395,
     416,   422,   428,   432,   438,   494,   509,   225,   226,   227,
     227,   314,   396,   423,   227,   433,   227,   351,   417,   337,
     227,   274,   294,   366,   227,   227,   387,   227,   227,   377,
       1,    24,    31,    97,   268,   269,   270,   271,   272,     1,
      21,    22,    27,    64,    65,    70,    71,    77,    78,    79,
     103,   104,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   227,   227,   227,     1,
      60,   429,   430,   431,   227,     1,     6,     7,    12,    20,
      26,    29,    30,    35,    40,    41,    43,    44,    45,    47,
      54,    58,    59,    67,    76,    84,    86,    88,    90,    92,
      93,   105,   110,   111,   112,   114,   115,   116,   119,   145,
     153,   154,   155,   156,   157,   185,   209,   210,   212,   213,
     214,   218,   223,   439,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   487,   491,
     492,   493,   227,   227,   227,     1,    94,   118,   239,   240,
     241,   242,   227,   227,   227,     1,    28,    36,    48,    49,
      51,    52,    53,    73,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,     1,    24,    56,    63,    85,    89,
      97,   100,   101,   132,   149,   152,   176,   194,   195,   196,
     221,   222,   244,   245,   246,   247,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   264,   265,
     266,   227,     1,   219,   280,   281,   282,   283,   284,     1,
      97,   373,   374,   375,   227,   225,   228,   228,   228,   226,
     269,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   226,   496,     1,    15,    16,    19,    62,
      80,    81,    82,    83,    87,    91,    97,   108,   109,   120,
     142,   180,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
       1,     3,     5,    17,    32,    55,    57,    62,    72,    97,
     121,   141,   150,   194,   221,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   411,   412,   413,   414,
     415,     1,    60,   124,   424,   425,   426,   427,   228,   226,
     430,     1,    97,   124,   434,   435,   436,   437,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   488,   228,   484,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   226,   440,     1,    17,    32,
      62,   117,   125,   126,   146,   220,   352,   353,   354,   355,
     356,   357,   358,   362,   363,   364,     1,   124,   220,   418,
     419,   420,   421,     1,    55,    60,    62,   121,   338,   342,
     343,   344,   348,   349,   225,   228,   228,   226,   240,     1,
      75,   168,   275,   276,   277,   278,     1,    17,    32,    62,
      97,   117,   133,   150,   151,   199,   220,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   309,     1,
      34,    75,   124,   367,   368,   369,   370,   371,   228,   228,
     228,   228,   228,   228,   228,   228,   226,   511,   225,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   226,   245,     1,    97,
     216,   388,   389,   390,   391,   225,   228,   226,   281,   168,
     228,   226,   374,     1,    97,   216,   220,   378,   379,   380,
     381,   382,   122,   122,   122,   225,   107,   107,   208,   107,
     107,   235,   235,   235,   107,   107,   107,   208,   208,   225,
     225,   228,   228,   228,   333,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   316,   225,
     228,   228,   228,   228,   228,   228,   408,   228,   228,   228,
     228,   228,   228,   228,   226,   398,   228,   228,   226,   425,
     122,   225,   228,   228,   226,   435,   208,   235,   235,   107,
     208,   107,   122,   208,   235,   208,   107,   107,   235,   107,
     208,   208,   208,   235,   107,   107,   235,   107,   107,   107,
     107,   208,   228,   208,   228,   208,   235,   235,   208,   208,
     208,   208,   211,   208,   211,   208,   208,   122,   235,   208,
     208,   235,   235,   208,   208,   225,   225,   228,   228,   359,
     228,   228,   228,   228,   228,   226,   353,   228,   228,   226,
     419,   225,   228,   228,   339,   228,   226,   343,   122,   122,
     225,   225,   228,   228,   226,   276,   225,   228,   228,   310,
     228,   228,   228,   228,   228,   306,   228,   226,   296,   225,
     228,   228,   228,   226,   368,   208,   208,   208,   122,   208,
     208,   208,   235,   225,   122,   208,   122,   107,   107,   122,
     122,   122,   122,   122,   122,   107,   122,   197,   198,   248,
     249,   197,   198,   250,   251,   122,   122,   225,   225,   228,
     392,   226,   389,   208,   225,   227,   122,   225,   225,   228,
     383,   228,   226,   379,   225,   225,   225,   225,   225,   225,
     225,   134,   135,   136,   137,   138,   139,   140,   234,   235,
     225,   225,   225,   225,   225,   225,   225,   225,   107,   107,
     235,   228,   107,   107,   235,   107,   107,   235,   122,   107,
     107,   235,   107,   237,   237,   225,   122,   172,   173,   122,
     208,   122,   122,   228,   122,   122,   107,   122,   122,   122,
     122,   225,   122,   122,   225,   225,   122,   122,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,    48,   159,   160,   161,   163,
     164,   166,   167,   169,   171,   174,   177,   178,   179,   181,
     186,   190,   191,   192,   200,   205,   489,   490,   225,    48,
     159,   160,   161,   163,   164,   166,   167,   169,   171,   174,
     177,   178,   179,   181,   186,   190,   191,   192,   200,   205,
     485,   486,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   122,   208,   228,   122,   107,   122,   122,   122,
     225,   122,   122,   225,   122,   122,   228,   107,   346,   347,
     225,   225,   225,   122,   122,   225,   122,   208,   228,   122,
     122,   122,   122,   208,   228,   122,   225,   122,   122,   122,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   229,   225,   229,   225,   225,   122,   228,
     225,   225,     1,    97,   189,   216,   285,   286,   287,   288,
     289,   225,   122,   228,   122,   225,   234,   234,   234,   234,
     234,   234,   234,   225,   225,   225,    50,   123,   334,   335,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
       9,    10,    11,   236,   237,   225,   225,   225,   225,   225,
     225,   225,   225,   225,     8,   193,   409,   410,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     229,   225,   229,   225,   225,    13,    33,    42,    69,    98,
      99,   106,   131,   147,   207,   360,   361,   225,   225,   225,
     225,   225,   225,   225,   225,   225,    48,   183,   193,   340,
     341,   215,   229,   345,   225,   225,   225,   225,     4,    18,
      25,    39,    66,    68,    94,   127,   129,   148,   165,   170,
     174,   179,   182,   187,   201,   206,   217,   224,   311,   312,
     225,   225,   225,   225,   225,    48,   159,   160,   161,   163,
     164,   166,   167,   169,   171,   174,   177,   178,   179,   181,
     186,   190,   191,   192,   200,   205,   307,   308,   225,   225,
     225,   225,   249,   251,   225,    68,   130,   158,   165,   174,
     201,   203,   204,   217,   224,   393,   394,   225,   228,   228,
     290,   226,   286,   225,    68,   130,   158,   165,   174,   201,
     203,   204,   217,   224,   384,   385,   225,   225,   229,   236,
     236,   236,   225,   229,   490,   486,   225,   229,   225,   229,
     107,   347,   225,   230,   230,   230,   225,   229,   225,   229,
     225,   229,   122,   202,   237,   228,   225,   225,   229,   335,
     410,   361,   341,   128,   128,   128,   312,   308,   394,   225,
     225,   225,    39,    66,    68,   113,   164,   165,   220,   291,
     292,   385,   225,   229,   292
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
#line 398 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 400 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 404 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 412 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 416 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 420 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 424 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 428 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 433 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 434 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 437 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 457 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 483 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 489 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 498 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 504 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 512 "conf_parser.y"
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
#line 554 "conf_parser.y"
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
#line 613 "conf_parser.y"
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
#line 641 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 649 "conf_parser.y"
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
#line 664 "conf_parser.y"
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
#line 679 "conf_parser.y"
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
#line 688 "conf_parser.y"
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
#line 702 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 711 "conf_parser.y"
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
#line 739 "conf_parser.y"
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
#line 769 "conf_parser.y"
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
#line 794 "conf_parser.y"
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
#line 816 "conf_parser.y"
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
#line 838 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 887 "conf_parser.y"
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
#line 904 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 935 "conf_parser.y"
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
#line 951 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 959 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 962 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 974 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 978 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 982 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 986 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 990 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 994 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 998 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1015 "conf_parser.y"
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

  case 160:
/* Line 1787 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1113 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
  else
    block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1130 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (yylval.number)
    block_state.flags.value |= CONF_FLAGS_SSL;
  else
    block_state.flags.value &= ~CONF_FLAGS_SSL;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1269 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1273 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1281 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1285 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1289 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1293 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1297 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1301 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1309 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1313 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1317 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1321 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1325 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1329 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1333 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1337 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1341 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1351 "conf_parser.y"
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

  case 221:
/* Line 1787 of yacc.c  */
#line 1363 "conf_parser.y"
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

  case 241:
/* Line 1787 of yacc.c  */
#line 1429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1447 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1465 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1477 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1483 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1490 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1496 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1502 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1508 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1517 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1526 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1533 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1537 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 1547 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1553 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1559 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1563 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1567 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1575 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1580 "conf_parser.y"
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

  case 283:
/* Line 1787 of yacc.c  */
#line 1594 "conf_parser.y"
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

  case 284:
/* Line 1787 of yacc.c  */
#line 1614 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1629 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1633 "conf_parser.y"
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

  case 299:
/* Line 1787 of yacc.c  */
#line 1676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1682 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1688 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1694 "conf_parser.y"
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

  case 303:
/* Line 1787 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1728 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1732 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1736 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1740 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1744 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1748 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1754 "conf_parser.y"
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

  case 318:
/* Line 1787 of yacc.c  */
#line 1768 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1777 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1790 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1797 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1808 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 1814 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 1820 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1835 "conf_parser.y"
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

  case 337:
/* Line 1787 of yacc.c  */
#line 1850 "conf_parser.y"
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

  case 338:
/* Line 1787 of yacc.c  */
#line 1861 "conf_parser.y"
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

  case 345:
/* Line 1787 of yacc.c  */
#line 1878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1884 "conf_parser.y"
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

  case 347:
/* Line 1787 of yacc.c  */
#line 1903 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1946 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1955 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 362:
/* Line 1787 of yacc.c  */
#line 1964 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 1979 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2004 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2020 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2024 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2028 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2037 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2045 "conf_parser.y"
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

  case 402:
/* Line 1787 of yacc.c  */
#line 2116 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2134 "conf_parser.y"
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

  case 406:
/* Line 1787 of yacc.c  */
#line 2147 "conf_parser.y"
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

  case 407:
/* Line 1787 of yacc.c  */
#line 2160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2166 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 2172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2176 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2184 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2190 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2200 "conf_parser.y"
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

  case 418:
/* Line 1787 of yacc.c  */
#line 2211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 2217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 2223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2229 "conf_parser.y"
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

  case 422:
/* Line 1787 of yacc.c  */
#line 2244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2248 "conf_parser.y"
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

  case 429:
/* Line 1787 of yacc.c  */
#line 2273 "conf_parser.y"
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

  case 430:
/* Line 1787 of yacc.c  */
#line 2293 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2306 "conf_parser.y"
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

  case 438:
/* Line 1787 of yacc.c  */
#line 2332 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 2338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2352 "conf_parser.y"
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

  case 446:
/* Line 1787 of yacc.c  */
#line 2369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 2373 "conf_parser.y"
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

  case 453:
/* Line 1787 of yacc.c  */
#line 2395 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 2401 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2444 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2455 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2461 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2467 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2472 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2482 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2507 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2512 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2517 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2522 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2527 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2532 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2538 "conf_parser.y"
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

  case 525:
/* Line 1787 of yacc.c  */
#line 2549 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2554 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2559 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2564 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2569 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2574 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2684 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2687 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2702 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2708 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2711 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2723 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2735 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2738 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2744 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2749 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2758 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2761 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2764 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2767 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2773 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2776 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2779 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2782 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2785 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2791 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2794 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2797 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2803 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 596:
/* Line 1787 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 597:
/* Line 1787 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 598:
/* Line 1787 of yacc.c  */
#line 2812 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1787 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1787 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 2853 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2863 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 2893 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2898 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 2903 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 643:
/* Line 1787 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 644:
/* Line 1787 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
    break;

  case 645:
/* Line 1787 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 646:
/* Line 1787 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 647:
/* Line 1787 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 648:
/* Line 1787 of yacc.c  */
#line 2961 "conf_parser.y"
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

  case 649:
/* Line 1787 of yacc.c  */
#line 2975 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 650:
/* Line 1787 of yacc.c  */
#line 2981 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6849 "conf_parser.c"
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


