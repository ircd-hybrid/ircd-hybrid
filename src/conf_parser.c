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
     CYCLE_ON_HOST_CHANGE = 275,
     DEFAULT_FLOODCOUNT = 276,
     DEFAULT_SPLIT_SERVER_COUNT = 277,
     DEFAULT_SPLIT_USER_COUNT = 278,
     DENY = 279,
     DESCRIPTION = 280,
     DIE = 281,
     DISABLE_AUTH = 282,
     DISABLE_FAKE_CHANNELS = 283,
     DISABLE_REMOTE_COMMANDS = 284,
     DOTS_IN_IDENT = 285,
     EGDPOOL_PATH = 286,
     EMAIL = 287,
     ENCRYPTED = 288,
     EXCEED_LIMIT = 289,
     EXEMPT = 290,
     FAILED_OPER_NOTICE = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_MIN_CIDR = 299,
     GLINE_MIN_CIDR6 = 300,
     GLINE_REQUEST_DURATION = 301,
     GLOBAL_KILL = 302,
     HAVENT_READ_CONF = 303,
     HIDDEN = 304,
     HIDDEN_NAME = 305,
     HIDE_IDLE_FROM_OPERS = 306,
     HIDE_SERVER_IPS = 307,
     HIDE_SERVERS = 308,
     HIDE_SERVICES = 309,
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     IRCD_AUTH = 317,
     IRCD_FLAGS = 318,
     IRCD_SID = 319,
     JOIN_FLOOD_COUNT = 320,
     JOIN_FLOOD_TIME = 321,
     KILL = 322,
     KILL_CHASE_TIME_LIMIT = 323,
     KLINE = 324,
     KLINE_EXEMPT = 325,
     KNOCK_DELAY = 326,
     KNOCK_DELAY_CHANNEL = 327,
     LEAF_MASK = 328,
     LINKS_DELAY = 329,
     LISTEN = 330,
     MASK = 331,
     MAX_ACCEPT = 332,
     MAX_BANS = 333,
     MAX_CHANS_PER_OPER = 334,
     MAX_CHANS_PER_USER = 335,
     MAX_GLOBAL = 336,
     MAX_IDENT = 337,
     MAX_IDLE = 338,
     MAX_LOCAL = 339,
     MAX_NICK_CHANGES = 340,
     MAX_NICK_LENGTH = 341,
     MAX_NICK_TIME = 342,
     MAX_NUMBER = 343,
     MAX_TARGETS = 344,
     MAX_TOPIC_LENGTH = 345,
     MAX_WATCH = 346,
     MIN_IDLE = 347,
     MIN_NONWILDCARD = 348,
     MIN_NONWILDCARD_SIMPLE = 349,
     MODULE = 350,
     MODULES = 351,
     MOTD = 352,
     NAME = 353,
     NEED_IDENT = 354,
     NEED_PASSWORD = 355,
     NETWORK_DESC = 356,
     NETWORK_NAME = 357,
     NICK = 358,
     NO_CREATE_ON_SPLIT = 359,
     NO_JOIN_ON_SPLIT = 360,
     NO_OPER_FLOOD = 361,
     NO_TILDE = 362,
     NUMBER = 363,
     NUMBER_PER_CIDR = 364,
     NUMBER_PER_IP = 365,
     OPER_ONLY_UMODES = 366,
     OPER_PASS_RESV = 367,
     OPER_UMODES = 368,
     OPERATOR = 369,
     OPERS_BYPASS_CALLERID = 370,
     PACE_WAIT = 371,
     PACE_WAIT_SIMPLE = 372,
     PASSWORD = 373,
     PATH = 374,
     PING_COOKIE = 375,
     PING_TIME = 376,
     PORT = 377,
     QSTRING = 378,
     RANDOM_IDLE = 379,
     REASON = 380,
     REDIRPORT = 381,
     REDIRSERV = 382,
     REHASH = 383,
     REMOTE = 384,
     REMOTEBAN = 385,
     RESV = 386,
     RESV_EXEMPT = 387,
     RSA_PRIVATE_KEY_FILE = 388,
     RSA_PUBLIC_KEY_FILE = 389,
     SECONDS = 390,
     MINUTES = 391,
     HOURS = 392,
     DAYS = 393,
     WEEKS = 394,
     MONTHS = 395,
     YEARS = 396,
     SEND_PASSWORD = 397,
     SENDQ = 398,
     SERVERHIDE = 399,
     SERVERINFO = 400,
     SHORT_MOTD = 401,
     SPOOF = 402,
     SPOOF_NOTICE = 403,
     SQUIT = 404,
     SSL_CERTIFICATE_FILE = 405,
     SSL_CERTIFICATE_FINGERPRINT = 406,
     SSL_CONNECTION_REQUIRED = 407,
     SSL_DH_PARAM_FILE = 408,
     STATS_E_DISABLED = 409,
     STATS_I_OPER_ONLY = 410,
     STATS_K_OPER_ONLY = 411,
     STATS_O_OPER_ONLY = 412,
     STATS_P_OPER_ONLY = 413,
     STATS_U_OPER_ONLY = 414,
     T_ALL = 415,
     T_BOTS = 416,
     T_CALLERID = 417,
     T_CCONN = 418,
     T_CLUSTER = 419,
     T_DEAF = 420,
     T_DEBUG = 421,
     T_DLINE = 422,
     T_EXTERNAL = 423,
     T_FARCONNECT = 424,
     T_FILE = 425,
     T_FULL = 426,
     T_GLOBOPS = 427,
     T_INVISIBLE = 428,
     T_IPV4 = 429,
     T_IPV6 = 430,
     T_LOCOPS = 431,
     T_LOG = 432,
     T_MAX_CLIENTS = 433,
     T_NCHANGE = 434,
     T_NONONREG = 435,
     T_OPERWALL = 436,
     T_RECVQ = 437,
     T_REJ = 438,
     T_RESTART = 439,
     T_SERVER = 440,
     T_SERVICE = 441,
     T_SERVICES_NAME = 442,
     T_SERVNOTICE = 443,
     T_SET = 444,
     T_SHARED = 445,
     T_SIZE = 446,
     T_SKILL = 447,
     T_SOFTCALLERID = 448,
     T_SPY = 449,
     T_SSL = 450,
     T_SSL_CIPHER_LIST = 451,
     T_SSL_CLIENT_METHOD = 452,
     T_SSL_SERVER_METHOD = 453,
     T_SSLV3 = 454,
     T_TLSV1 = 455,
     T_UMODES = 456,
     T_UNAUTH = 457,
     T_UNDLINE = 458,
     T_UNLIMITED = 459,
     T_UNRESV = 460,
     T_UNXLINE = 461,
     T_WALLOP = 462,
     T_WALLOPS = 463,
     T_WEBIRC = 464,
     TBOOL = 465,
     THROTTLE_TIME = 466,
     TKLINE_EXPIRE_NOTICES = 467,
     TMASKED = 468,
     TRUE_NO_OPER_FLOOD = 469,
     TS_MAX_DELTA = 470,
     TS_WARN_DELTA = 471,
     TWODOTS = 472,
     TYPE = 473,
     UNKLINE = 474,
     USE_EGD = 475,
     USE_LOGGING = 476,
     USER = 477,
     VHOST = 478,
     VHOST6 = 479,
     WARN_NO_NLINE = 480,
     XLINE = 481
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
#define CYCLE_ON_HOST_CHANGE 275
#define DEFAULT_FLOODCOUNT 276
#define DEFAULT_SPLIT_SERVER_COUNT 277
#define DEFAULT_SPLIT_USER_COUNT 278
#define DENY 279
#define DESCRIPTION 280
#define DIE 281
#define DISABLE_AUTH 282
#define DISABLE_FAKE_CHANNELS 283
#define DISABLE_REMOTE_COMMANDS 284
#define DOTS_IN_IDENT 285
#define EGDPOOL_PATH 286
#define EMAIL 287
#define ENCRYPTED 288
#define EXCEED_LIMIT 289
#define EXEMPT 290
#define FAILED_OPER_NOTICE 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_MIN_CIDR 299
#define GLINE_MIN_CIDR6 300
#define GLINE_REQUEST_DURATION 301
#define GLOBAL_KILL 302
#define HAVENT_READ_CONF 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define IRCD_AUTH 317
#define IRCD_FLAGS 318
#define IRCD_SID 319
#define JOIN_FLOOD_COUNT 320
#define JOIN_FLOOD_TIME 321
#define KILL 322
#define KILL_CHASE_TIME_LIMIT 323
#define KLINE 324
#define KLINE_EXEMPT 325
#define KNOCK_DELAY 326
#define KNOCK_DELAY_CHANNEL 327
#define LEAF_MASK 328
#define LINKS_DELAY 329
#define LISTEN 330
#define MASK 331
#define MAX_ACCEPT 332
#define MAX_BANS 333
#define MAX_CHANS_PER_OPER 334
#define MAX_CHANS_PER_USER 335
#define MAX_GLOBAL 336
#define MAX_IDENT 337
#define MAX_IDLE 338
#define MAX_LOCAL 339
#define MAX_NICK_CHANGES 340
#define MAX_NICK_LENGTH 341
#define MAX_NICK_TIME 342
#define MAX_NUMBER 343
#define MAX_TARGETS 344
#define MAX_TOPIC_LENGTH 345
#define MAX_WATCH 346
#define MIN_IDLE 347
#define MIN_NONWILDCARD 348
#define MIN_NONWILDCARD_SIMPLE 349
#define MODULE 350
#define MODULES 351
#define MOTD 352
#define NAME 353
#define NEED_IDENT 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NO_CREATE_ON_SPLIT 359
#define NO_JOIN_ON_SPLIT 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP 365
#define OPER_ONLY_UMODES 366
#define OPER_PASS_RESV 367
#define OPER_UMODES 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PORT 377
#define QSTRING 378
#define RANDOM_IDLE 379
#define REASON 380
#define REDIRPORT 381
#define REDIRSERV 382
#define REHASH 383
#define REMOTE 384
#define REMOTEBAN 385
#define RESV 386
#define RESV_EXEMPT 387
#define RSA_PRIVATE_KEY_FILE 388
#define RSA_PUBLIC_KEY_FILE 389
#define SECONDS 390
#define MINUTES 391
#define HOURS 392
#define DAYS 393
#define WEEKS 394
#define MONTHS 395
#define YEARS 396
#define SEND_PASSWORD 397
#define SENDQ 398
#define SERVERHIDE 399
#define SERVERINFO 400
#define SHORT_MOTD 401
#define SPOOF 402
#define SPOOF_NOTICE 403
#define SQUIT 404
#define SSL_CERTIFICATE_FILE 405
#define SSL_CERTIFICATE_FINGERPRINT 406
#define SSL_CONNECTION_REQUIRED 407
#define SSL_DH_PARAM_FILE 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BOTS 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_CLUSTER 419
#define T_DEAF 420
#define T_DEBUG 421
#define T_DLINE 422
#define T_EXTERNAL 423
#define T_FARCONNECT 424
#define T_FILE 425
#define T_FULL 426
#define T_GLOBOPS 427
#define T_INVISIBLE 428
#define T_IPV4 429
#define T_IPV6 430
#define T_LOCOPS 431
#define T_LOG 432
#define T_MAX_CLIENTS 433
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPERWALL 436
#define T_RECVQ 437
#define T_REJ 438
#define T_RESTART 439
#define T_SERVER 440
#define T_SERVICE 441
#define T_SERVICES_NAME 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_SKILL 447
#define T_SOFTCALLERID 448
#define T_SPY 449
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_SSL_CLIENT_METHOD 452
#define T_SSL_SERVER_METHOD 453
#define T_SSLV3 454
#define T_TLSV1 455
#define T_UMODES 456
#define T_UNAUTH 457
#define T_UNDLINE 458
#define T_UNLIMITED 459
#define T_UNRESV 460
#define T_UNXLINE 461
#define T_WALLOP 462
#define T_WALLOPS 463
#define T_WEBIRC 464
#define TBOOL 465
#define THROTTLE_TIME 466
#define TKLINE_EXPIRE_NOTICES 467
#define TMASKED 468
#define TRUE_NO_OPER_FLOOD 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_EGD 475
#define USE_LOGGING 476
#define USER 477
#define VHOST 478
#define VHOST6 479
#define WARN_NO_NLINE 480
#define XLINE 481



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 140 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 684 "conf_parser.c"
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
#line 712 "conf_parser.c"

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
#define YYLAST   1274

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  654
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1285

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   481

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   231,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   232,   227,
       2,   230,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,     2,   228,     2,     2,     2,     2,
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
     225,   226
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
    1461,  1463,  1465,  1467,  1469,  1471,  1473,  1475,  1477,  1482,
    1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,  1527,  1532,
    1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,  1577,  1582,
    1587,  1592,  1597,  1602,  1607,  1612,  1617,  1622,  1627,  1632,
    1637,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1677,  1682,
    1687,  1692,  1697,  1702,  1707,  1708,  1714,  1718,  1720,  1722,
    1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,
    1744,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1760,  1762,
    1763,  1769,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,
    1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,  1805,  1807,
    1809,  1811,  1813,  1815,  1817,  1822,  1827,  1832,  1838,  1841,
    1843,  1845,  1847,  1849,  1851,  1853,  1855,  1857,  1859,  1861,
    1863,  1865,  1867,  1869,  1874,  1879,  1884,  1889,  1894,  1899,
    1904,  1909,  1914,  1919,  1924,  1929,  1935,  1938,  1940,  1942,
    1944,  1946,  1948,  1950,  1952,  1954,  1956,  1958,  1963,  1968,
    1973,  1978,  1983,  1988,  1993
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,    -1,   234,   235,    -1,   269,    -1,   281,
      -1,   295,    -1,   498,    -1,   315,    -1,   338,    -1,   352,
      -1,   245,    -1,   513,    -1,   367,    -1,   374,    -1,   378,
      -1,   388,    -1,   397,    -1,   418,    -1,   424,    -1,   430,
      -1,   440,    -1,   434,    -1,   240,    -1,   275,    -1,     1,
     227,    -1,     1,   228,    -1,    -1,   237,    -1,   108,   236,
      -1,   108,   135,   236,    -1,   108,   136,   236,    -1,   108,
     137,   236,    -1,   108,   138,   236,    -1,   108,   139,   236,
      -1,   108,   140,   236,    -1,   108,   141,   236,    -1,    -1,
     239,    -1,   108,   238,    -1,   108,     9,   238,    -1,   108,
      10,   238,    -1,   108,    11,   238,    -1,    96,   229,   241,
     228,   227,    -1,   241,   242,    -1,   242,    -1,   243,    -1,
     244,    -1,     1,   227,    -1,    95,   230,   123,   227,    -1,
     119,   230,   123,   227,    -1,   145,   229,   246,   228,   227,
      -1,   246,   247,    -1,   247,    -1,   258,    -1,   263,    -1,
     268,    -1,   260,    -1,   261,    -1,   262,    -1,   265,    -1,
     266,    -1,   267,    -1,   256,    -1,   255,    -1,   264,    -1,
     259,    -1,   254,    -1,   248,    -1,   249,    -1,   257,    -1,
       1,   227,    -1,   197,   230,   250,   227,    -1,   198,   230,
     252,   227,    -1,   250,   231,   251,    -1,   251,    -1,   199,
      -1,   200,    -1,   252,   231,   253,    -1,   253,    -1,   199,
      -1,   200,    -1,   150,   230,   123,   227,    -1,   133,   230,
     123,   227,    -1,   153,   230,   123,   227,    -1,   196,   230,
     123,   227,    -1,    98,   230,   123,   227,    -1,    64,   230,
     123,   227,    -1,    25,   230,   123,   227,    -1,   102,   230,
     123,   227,    -1,   101,   230,   123,   227,    -1,   223,   230,
     123,   227,    -1,   224,   230,   123,   227,    -1,   178,   230,
     108,   227,    -1,    86,   230,   108,   227,    -1,    90,   230,
     108,   227,    -1,    57,   230,   210,   227,    -1,     4,   229,
     270,   228,   227,    -1,   270,   271,    -1,   271,    -1,   272,
      -1,   274,    -1,   273,    -1,     1,   227,    -1,    98,   230,
     123,   227,    -1,    32,   230,   123,   227,    -1,    25,   230,
     123,   227,    -1,    -1,    97,   276,   229,   277,   228,   227,
      -1,   277,   278,    -1,   278,    -1,   279,    -1,   280,    -1,
       1,   227,    -1,    76,   230,   123,   227,    -1,   170,   230,
     123,   227,    -1,   177,   229,   282,   228,   227,    -1,   282,
     283,    -1,   283,    -1,   284,    -1,   285,    -1,     1,   227,
      -1,   221,   230,   210,   227,    -1,    -1,   286,   170,   229,
     287,   228,   227,    -1,   287,   288,    -1,   288,    -1,   289,
      -1,   291,    -1,   290,    -1,     1,   227,    -1,    98,   230,
     123,   227,    -1,   191,   230,   239,   227,    -1,   191,   230,
     204,   227,    -1,    -1,   218,   292,   230,   293,   227,    -1,
     293,   231,   294,    -1,   294,    -1,   222,    -1,   114,    -1,
      40,    -1,   167,    -1,    69,    -1,    67,    -1,   166,    -1,
      -1,   114,   296,   229,   297,   228,   227,    -1,   297,   298,
      -1,   298,    -1,   299,    -1,   300,    -1,   301,    -1,   307,
      -1,   306,    -1,   302,    -1,   303,    -1,   304,    -1,   305,
      -1,   311,    -1,     1,   227,    -1,    98,   230,   123,   227,
      -1,   222,   230,   123,   227,    -1,   118,   230,   123,   227,
      -1,    33,   230,   210,   227,    -1,   134,   230,   123,   227,
      -1,   151,   230,   123,   227,    -1,   152,   230,   210,   227,
      -1,    17,   230,   123,   227,    -1,    -1,   201,   308,   230,
     309,   227,    -1,   309,   231,   310,    -1,   310,    -1,   161,
      -1,   163,    -1,   165,    -1,   166,    -1,   171,    -1,    49,
      -1,   192,    -1,   179,    -1,   183,    -1,   202,    -1,   194,
      -1,   168,    -1,   181,    -1,   188,    -1,   173,    -1,   207,
      -1,   193,    -1,   162,    -1,   176,    -1,   180,    -1,   169,
      -1,    -1,    63,   312,   230,   313,   227,    -1,   313,   231,
     314,    -1,   314,    -1,    67,   232,   129,    -1,    67,    -1,
      18,   232,   129,    -1,    18,    -1,   149,   232,   129,    -1,
     149,    -1,    69,    -1,   219,    -1,   167,    -1,   203,    -1,
     226,    -1,    40,    -1,    26,    -1,   184,    -1,   128,    -1,
       4,    -1,   181,    -1,   172,    -1,   208,    -1,   176,    -1,
     130,    -1,   189,    -1,    95,    -1,    -1,    17,   316,   229,
     317,   228,   227,    -1,   317,   318,    -1,   318,    -1,   319,
      -1,   329,    -1,   330,    -1,   320,    -1,   331,    -1,   321,
      -1,   322,    -1,   323,    -1,   324,    -1,   325,    -1,   326,
      -1,   327,    -1,   328,    -1,   332,    -1,   333,    -1,   334,
      -1,     1,   227,    -1,    98,   230,   123,   227,    -1,   121,
     230,   237,   227,    -1,   110,   230,   108,   227,    -1,    19,
     230,   237,   227,    -1,    88,   230,   108,   227,    -1,    81,
     230,   108,   227,    -1,    84,   230,   108,   227,    -1,    82,
     230,   108,   227,    -1,   143,   230,   239,   227,    -1,   182,
     230,   239,   227,    -1,    15,   230,   108,   227,    -1,    16,
     230,   108,   227,    -1,   109,   230,   108,   227,    -1,    92,
     230,   237,   227,    -1,    83,   230,   237,   227,    -1,    -1,
      63,   335,   230,   336,   227,    -1,   336,   231,   337,    -1,
     337,    -1,   124,    -1,    51,    -1,    -1,    75,   339,   229,
     344,   228,   227,    -1,    -1,    63,   341,   230,   342,   227,
      -1,   342,   231,   343,    -1,   343,    -1,   195,    -1,    49,
      -1,   185,    -1,   344,   345,    -1,   345,    -1,   346,    -1,
     340,    -1,   350,    -1,   351,    -1,     1,   227,    -1,    -1,
     122,   230,   348,   347,   227,    -1,   348,   231,   349,    -1,
     349,    -1,   108,    -1,   108,   217,   108,    -1,    61,   230,
     123,   227,    -1,    56,   230,   123,   227,    -1,    -1,    62,
     353,   229,   354,   228,   227,    -1,   354,   355,    -1,   355,
      -1,   356,    -1,   357,    -1,   358,    -1,   360,    -1,   364,
      -1,   365,    -1,   366,    -1,   359,    -1,     1,   227,    -1,
     222,   230,   123,   227,    -1,   118,   230,   123,   227,    -1,
      17,   230,   123,   227,    -1,    33,   230,   210,   227,    -1,
      -1,    63,   361,   230,   362,   227,    -1,   362,   231,   363,
      -1,   363,    -1,   148,    -1,    34,    -1,    70,    -1,    99,
      -1,    13,    -1,   107,    -1,    43,    -1,   132,    -1,   209,
      -1,   100,    -1,   147,   230,   123,   227,    -1,   127,   230,
     123,   227,    -1,   126,   230,   108,   227,    -1,    -1,   131,
     368,   229,   369,   228,   227,    -1,   369,   370,    -1,   370,
      -1,   371,    -1,   372,    -1,   373,    -1,     1,   227,    -1,
      76,   230,   123,   227,    -1,   125,   230,   123,   227,    -1,
      35,   230,   123,   227,    -1,   186,   229,   375,   228,   227,
      -1,   375,   376,    -1,   376,    -1,   377,    -1,     1,    -1,
      98,   230,   123,   227,    -1,    -1,   190,   379,   229,   380,
     228,   227,    -1,   380,   381,    -1,   381,    -1,   382,    -1,
     383,    -1,   384,    -1,     1,   227,    -1,    98,   230,   123,
     227,    -1,   222,   230,   123,   227,    -1,    -1,   218,   385,
     230,   386,   227,    -1,   386,   231,   387,    -1,   387,    -1,
      69,    -1,   219,    -1,   167,    -1,   203,    -1,   226,    -1,
     206,    -1,   131,    -1,   205,    -1,   176,    -1,   160,    -1,
      -1,   164,   389,   229,   390,   228,   227,    -1,   390,   391,
      -1,   391,    -1,   392,    -1,   393,    -1,     1,   227,    -1,
      98,   230,   123,   227,    -1,    -1,   218,   394,   230,   395,
     227,    -1,   395,   231,   396,    -1,   396,    -1,    69,    -1,
     219,    -1,   167,    -1,   203,    -1,   226,    -1,   206,    -1,
     131,    -1,   205,    -1,   176,    -1,   160,    -1,    -1,    18,
     398,   229,   399,   228,   227,    -1,   399,   400,    -1,   400,
      -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,   405,
      -1,   406,    -1,   408,    -1,   407,    -1,   417,    -1,   409,
      -1,   414,    -1,   415,    -1,   416,    -1,   413,    -1,     1,
     227,    -1,    98,   230,   123,   227,    -1,    56,   230,   123,
     227,    -1,   223,   230,   123,   227,    -1,   142,   230,   123,
     227,    -1,     3,   230,   123,   227,    -1,   151,   230,   123,
     227,    -1,   122,   230,   108,   227,    -1,     5,   230,   174,
     227,    -1,     5,   230,   175,   227,    -1,    -1,    63,   410,
     230,   411,   227,    -1,   411,   231,   412,    -1,   412,    -1,
       8,    -1,   195,    -1,    33,   230,   210,   227,    -1,    58,
     230,   123,   227,    -1,    73,   230,   123,   227,    -1,    17,
     230,   123,   227,    -1,   196,   230,   123,   227,    -1,    -1,
      67,   419,   229,   420,   228,   227,    -1,   420,   421,    -1,
     421,    -1,   422,    -1,   423,    -1,     1,    -1,   222,   230,
     123,   227,    -1,   125,   230,   123,   227,    -1,    -1,    24,
     425,   229,   426,   228,   227,    -1,   426,   427,    -1,   427,
      -1,   428,    -1,   429,    -1,     1,    -1,    61,   230,   123,
     227,    -1,   125,   230,   123,   227,    -1,    35,   229,   431,
     228,   227,    -1,   431,   432,    -1,   432,    -1,   433,    -1,
       1,    -1,    61,   230,   123,   227,    -1,    -1,    38,   435,
     229,   436,   228,   227,    -1,   436,   437,    -1,   437,    -1,
     438,    -1,   439,    -1,     1,    -1,    98,   230,   123,   227,
      -1,   125,   230,   123,   227,    -1,    39,   229,   441,   228,
     227,    -1,   441,   442,    -1,   442,    -1,   452,    -1,   453,
      -1,   454,    -1,   455,    -1,   456,    -1,   457,    -1,   458,
      -1,   459,    -1,   460,    -1,   461,    -1,   451,    -1,   463,
      -1,   464,    -1,   479,    -1,   466,    -1,   469,    -1,   471,
      -1,   470,    -1,   474,    -1,   467,    -1,   468,    -1,   475,
      -1,   476,    -1,   477,    -1,   478,    -1,   491,    -1,   480,
      -1,   481,    -1,   482,    -1,   487,    -1,   472,    -1,   473,
      -1,   497,    -1,   495,    -1,   496,    -1,   486,    -1,   462,
      -1,   484,    -1,   485,    -1,   450,    -1,   445,    -1,   446,
      -1,   447,    -1,   448,    -1,   449,    -1,   465,    -1,   443,
      -1,   483,    -1,   444,    -1,     1,    -1,    91,   230,   108,
     227,    -1,    20,   230,   210,   227,    -1,    42,   230,   210,
     227,    -1,    41,   230,   237,   227,    -1,    46,   230,   237,
     227,    -1,    44,   230,   108,   227,    -1,    45,   230,   108,
     227,    -1,   212,   230,   210,   227,    -1,    68,   230,   237,
     227,    -1,    55,   230,   210,   227,    -1,    59,   230,   210,
     227,    -1,    36,   230,   210,   227,    -1,     6,   230,   210,
     227,    -1,    87,   230,   237,   227,    -1,    85,   230,   108,
     227,    -1,    77,   230,   108,   227,    -1,     7,   230,   237,
     227,    -1,   216,   230,   237,   227,    -1,   215,   230,   237,
     227,    -1,    48,   230,   108,   227,    -1,    60,   230,   210,
     227,    -1,   225,   230,   210,   227,    -1,   154,   230,   210,
     227,    -1,   157,   230,   210,   227,    -1,   158,   230,   210,
     227,    -1,   159,   230,   210,   227,    -1,   156,   230,   210,
     227,    -1,   156,   230,   213,   227,    -1,   155,   230,   210,
     227,    -1,   155,   230,   213,   227,    -1,   116,   230,   237,
     227,    -1,    12,   230,   237,   227,    -1,   115,   230,   210,
     227,    -1,   117,   230,   237,   227,    -1,   146,   230,   210,
     227,    -1,   106,   230,   210,   227,    -1,   214,   230,   210,
     227,    -1,   112,   230,   210,   227,    -1,    30,   230,   108,
     227,    -1,    89,   230,   108,   227,    -1,   220,   230,   210,
     227,    -1,    31,   230,   123,   227,    -1,   187,   230,   123,
     227,    -1,   120,   230,   210,   227,    -1,    27,   230,   210,
     227,    -1,   211,   230,   237,   227,    -1,    -1,   113,   488,
     230,   489,   227,    -1,   489,   231,   490,    -1,   490,    -1,
     161,    -1,   163,    -1,   165,    -1,   166,    -1,   171,    -1,
      49,    -1,   192,    -1,   179,    -1,   183,    -1,   202,    -1,
     194,    -1,   168,    -1,   181,    -1,   188,    -1,   173,    -1,
     207,    -1,   193,    -1,   162,    -1,   176,    -1,   180,    -1,
     169,    -1,    -1,   111,   492,   230,   493,   227,    -1,   493,
     231,   494,    -1,   494,    -1,   161,    -1,   163,    -1,   165,
      -1,   166,    -1,   171,    -1,   192,    -1,    49,    -1,   179,
      -1,   183,    -1,   202,    -1,   194,    -1,   168,    -1,   181,
      -1,   188,    -1,   173,    -1,   207,    -1,   193,    -1,   162,
      -1,   176,    -1,   180,    -1,   169,    -1,    93,   230,   108,
     227,    -1,    94,   230,   108,   227,    -1,    21,   230,   108,
     227,    -1,    14,   229,   499,   228,   227,    -1,   499,   500,
      -1,   500,    -1,   506,    -1,   502,    -1,   503,    -1,   504,
      -1,   505,    -1,   507,    -1,   508,    -1,   509,    -1,   510,
      -1,   511,    -1,   512,    -1,   501,    -1,     1,    -1,    28,
     230,   210,   227,    -1,    71,   230,   237,   227,    -1,    72,
     230,   237,   227,    -1,    80,   230,   108,   227,    -1,    79,
     230,   108,   227,    -1,    78,   230,   108,   227,    -1,    23,
     230,   108,   227,    -1,    22,   230,   108,   227,    -1,   104,
     230,   210,   227,    -1,   105,   230,   210,   227,    -1,    65,
     230,   108,   227,    -1,    66,   230,   237,   227,    -1,   144,
     229,   514,   228,   227,    -1,   514,   515,    -1,   515,    -1,
     516,    -1,   517,    -1,   518,    -1,   519,    -1,   521,    -1,
     522,    -1,   520,    -1,   523,    -1,     1,    -1,    37,   230,
     210,   227,    -1,    29,   230,   210,   227,    -1,    53,   230,
     210,   227,    -1,    54,   230,   210,   227,    -1,    50,   230,
     123,   227,    -1,    74,   230,   237,   227,    -1,    49,   230,
     210,   227,    -1,    52,   230,   210,   227,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   370,   370,   371,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     390,   391,   392,   393,   394,   395,   396,   400,   400,   401,
     405,   409,   413,   417,   421,   425,   429,   435,   435,   436,
     437,   438,   439,   446,   449,   449,   450,   450,   450,   452,
     458,   465,   467,   467,   468,   468,   469,   469,   470,   470,
     471,   471,   472,   472,   473,   473,   474,   474,   475,   475,
     476,   477,   480,   481,   483,   483,   484,   490,   498,   498,
     499,   505,   513,   555,   614,   642,   650,   665,   680,   689,
     703,   712,   740,   770,   795,   817,   839,   848,   850,   850,
     851,   851,   852,   852,   854,   863,   872,   885,   884,   902,
     902,   903,   903,   903,   905,   911,   920,   921,   921,   923,
     923,   924,   926,   933,   933,   946,   947,   949,   949,   950,
     950,   952,   960,   963,   969,   968,   974,   974,   975,   979,
     983,   987,   991,   995,   999,  1010,  1009,  1089,  1089,  1090,
    1090,  1090,  1091,  1091,  1091,  1092,  1092,  1093,  1094,  1094,
    1096,  1102,  1108,  1114,  1125,  1131,  1137,  1148,  1155,  1154,
    1160,  1160,  1161,  1165,  1169,  1173,  1177,  1181,  1185,  1189,
    1193,  1197,  1201,  1205,  1209,  1213,  1217,  1221,  1225,  1229,
    1233,  1237,  1241,  1248,  1247,  1253,  1253,  1254,  1258,  1262,
    1266,  1270,  1274,  1278,  1282,  1286,  1290,  1294,  1298,  1302,
    1306,  1310,  1314,  1318,  1322,  1326,  1330,  1334,  1338,  1342,
    1353,  1352,  1413,  1413,  1414,  1415,  1415,  1416,  1417,  1418,
    1419,  1420,  1421,  1422,  1423,  1424,  1424,  1425,  1426,  1427,
    1428,  1430,  1436,  1442,  1448,  1454,  1460,  1466,  1472,  1478,
    1484,  1491,  1497,  1503,  1509,  1518,  1528,  1527,  1533,  1533,
    1534,  1538,  1549,  1548,  1555,  1554,  1559,  1559,  1560,  1564,
    1568,  1574,  1574,  1575,  1575,  1575,  1575,  1575,  1577,  1577,
    1579,  1579,  1581,  1595,  1615,  1621,  1631,  1630,  1672,  1672,
    1673,  1673,  1673,  1673,  1674,  1674,  1674,  1675,  1675,  1677,
    1683,  1689,  1695,  1707,  1706,  1712,  1712,  1713,  1717,  1721,
    1725,  1729,  1733,  1737,  1741,  1745,  1749,  1755,  1769,  1778,
    1792,  1791,  1806,  1806,  1807,  1807,  1807,  1807,  1809,  1815,
    1821,  1831,  1833,  1833,  1834,  1834,  1836,  1852,  1851,  1876,
    1876,  1877,  1877,  1877,  1877,  1879,  1885,  1905,  1904,  1910,
    1910,  1911,  1915,  1919,  1923,  1927,  1931,  1935,  1939,  1943,
    1947,  1957,  1956,  1977,  1977,  1978,  1978,  1978,  1980,  1987,
    1986,  1992,  1992,  1993,  1997,  2001,  2005,  2009,  2013,  2017,
    2021,  2025,  2029,  2039,  2038,  2109,  2109,  2110,  2110,  2110,
    2111,  2111,  2112,  2113,  2113,  2113,  2114,  2114,  2114,  2115,
    2115,  2116,  2118,  2124,  2130,  2136,  2149,  2162,  2168,  2174,
    2178,  2187,  2186,  2191,  2191,  2192,  2196,  2202,  2213,  2219,
    2225,  2231,  2247,  2246,  2272,  2272,  2273,  2273,  2273,  2275,
    2295,  2305,  2304,  2331,  2331,  2332,  2332,  2332,  2334,  2340,
    2349,  2351,  2351,  2352,  2352,  2354,  2372,  2371,  2394,  2394,
    2395,  2395,  2395,  2397,  2403,  2412,  2415,  2415,  2416,  2416,
    2417,  2417,  2418,  2418,  2419,  2419,  2420,  2420,  2421,  2422,
    2423,  2423,  2424,  2424,  2425,  2425,  2426,  2426,  2427,  2428,
    2428,  2429,  2429,  2430,  2430,  2431,  2431,  2432,  2432,  2433,
    2433,  2434,  2434,  2435,  2435,  2436,  2437,  2438,  2438,  2439,
    2439,  2440,  2441,  2442,  2443,  2443,  2444,  2445,  2448,  2453,
    2459,  2465,  2471,  2477,  2482,  2487,  2492,  2497,  2502,  2507,
    2512,  2517,  2522,  2527,  2532,  2537,  2542,  2548,  2559,  2564,
    2569,  2574,  2579,  2584,  2589,  2592,  2597,  2600,  2605,  2610,
    2615,  2620,  2625,  2630,  2635,  2640,  2645,  2650,  2655,  2660,
    2669,  2678,  2683,  2688,  2694,  2693,  2698,  2698,  2699,  2702,
    2705,  2708,  2711,  2714,  2717,  2720,  2723,  2726,  2729,  2732,
    2735,  2738,  2741,  2744,  2747,  2750,  2753,  2756,  2759,  2765,
    2764,  2769,  2769,  2770,  2773,  2776,  2779,  2782,  2785,  2788,
    2791,  2794,  2797,  2800,  2803,  2806,  2809,  2812,  2815,  2818,
    2821,  2824,  2827,  2830,  2835,  2840,  2845,  2854,  2857,  2857,
    2858,  2859,  2859,  2860,  2860,  2861,  2862,  2863,  2864,  2865,
    2865,  2866,  2866,  2868,  2873,  2878,  2883,  2888,  2893,  2898,
    2903,  2908,  2913,  2918,  2923,  2931,  2934,  2934,  2935,  2935,
    2936,  2937,  2938,  2939,  2939,  2940,  2941,  2943,  2949,  2955,
    2961,  2967,  2976,  2990,  2996
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
  "CONNECTFREQ", "CYCLE_ON_HOST_CHANGE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "EGDPOOL_PATH", "EMAIL",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLINE_REQUEST_DURATION", "GLOBAL_KILL", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_IDLE_FROM_OPERS", "HIDE_SERVER_IPS", "HIDE_SERVERS",
  "HIDE_SERVICES", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "IRCD_AUTH",
  "IRCD_FLAGS", "IRCD_SID", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "MASK",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_IDLE", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_TOPIC_LENGTH", "MAX_WATCH", "MIN_IDLE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "MOTD", "NAME",
  "NEED_IDENT", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPER_ONLY_UMODES",
  "OPER_PASS_RESV", "OPER_UMODES", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PORT", "QSTRING", "RANDOM_IDLE", "REASON", "REDIRPORT",
  "REDIRSERV", "REHASH", "REMOTE", "REMOTEBAN", "RESV", "RESV_EXEMPT",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS", "SEND_PASSWORD", "SENDQ",
  "SERVERHIDE", "SERVERINFO", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "SQUIT", "SSL_CERTIFICATE_FILE", "SSL_CERTIFICATE_FINGERPRINT",
  "SSL_CONNECTION_REQUIRED", "SSL_DH_PARAM_FILE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "STATS_U_OPER_ONLY", "T_ALL", "T_BOTS",
  "T_CALLERID", "T_CCONN", "T_CLUSTER", "T_DEAF", "T_DEBUG", "T_DLINE",
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
  "general_cycle_on_host_change", "general_gline_enable",
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
  "general_stats_u_oper_only", "general_stats_k_oper_only",
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
     475,   476,   477,   478,   479,   480,   481,    59,   125,   123,
      61,    44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   233,   234,   234,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   236,   236,   237,
     237,   237,   237,   237,   237,   237,   237,   238,   238,   239,
     239,   239,   239,   240,   241,   241,   242,   242,   242,   243,
     244,   245,   246,   246,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   248,   249,   250,   250,   251,   251,   252,   252,
     253,   253,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   270,
     271,   271,   271,   271,   272,   273,   274,   276,   275,   277,
     277,   278,   278,   278,   279,   280,   281,   282,   282,   283,
     283,   283,   284,   286,   285,   287,   287,   288,   288,   288,
     288,   289,   290,   290,   292,   291,   293,   293,   294,   294,
     294,   294,   294,   294,   294,   296,   295,   297,   297,   298,
     298,   298,   298,   298,   298,   298,   298,   298,   298,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   308,   307,
     309,   309,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   312,   311,   313,   313,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     316,   315,   317,   317,   318,   318,   318,   318,   318,   318,
     318,   318,   318,   318,   318,   318,   318,   318,   318,   318,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   335,   334,   336,   336,
     337,   337,   339,   338,   341,   340,   342,   342,   343,   343,
     343,   344,   344,   345,   345,   345,   345,   345,   347,   346,
     348,   348,   349,   349,   350,   351,   353,   352,   354,   354,
     355,   355,   355,   355,   355,   355,   355,   355,   355,   356,
     357,   358,   359,   361,   360,   362,   362,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   364,   365,   366,
     368,   367,   369,   369,   370,   370,   370,   370,   371,   372,
     373,   374,   375,   375,   376,   376,   377,   379,   378,   380,
     380,   381,   381,   381,   381,   382,   383,   385,   384,   386,
     386,   387,   387,   387,   387,   387,   387,   387,   387,   387,
     387,   389,   388,   390,   390,   391,   391,   391,   392,   394,
     393,   395,   395,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   398,   397,   399,   399,   400,   400,   400,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     408,   410,   409,   411,   411,   412,   412,   413,   414,   415,
     416,   417,   419,   418,   420,   420,   421,   421,   421,   422,
     423,   425,   424,   426,   426,   427,   427,   427,   428,   429,
     430,   431,   431,   432,   432,   433,   435,   434,   436,   436,
     437,   437,   437,   438,   439,   440,   441,   441,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   442,   442,
     442,   442,   442,   442,   442,   442,   442,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   469,   470,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   488,   487,   489,   489,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   492,
     491,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   495,   496,   497,   498,   499,   499,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   514,   515,   515,
     515,   515,   515,   515,   515,   515,   515,   516,   517,   518,
     519,   520,   521,   522,   523
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   622,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   609,   621,   611,   612,   613,   614,   610,
     615,   616,   617,   618,   619,   620,     0,     0,     0,   444,
       0,     0,   442,   443,     0,   507,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   579,     0,   554,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   457,   504,   506,   498,
     499,   500,   501,   502,   497,   468,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   494,   469,   470,   503,
     472,   477,   478,   473,   475,   474,   488,   489,   476,   479,
     480,   481,   482,   471,   484,   485,   486,   505,   495,   496,
     493,   487,   483,   491,   492,   490,     0,     0,     0,     0,
       0,     0,     0,    45,    46,    47,     0,     0,     0,   646,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   637,
     638,   639,   640,   641,   644,   642,   643,   645,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    53,    68,    69,
      67,    64,    63,    70,    54,    66,    57,    58,    59,    55,
      65,    60,    61,    62,    56,     0,     0,     0,     0,   118,
     119,   120,     0,   335,     0,     0,   333,   334,     0,   103,
       0,     0,     0,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   608,     0,
       0,     0,     0,   256,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   223,   224,   227,
     229,   230,   231,   232,   233,   234,   235,   236,   225,   226,
     228,   237,   238,   239,     0,     0,     0,     0,     0,     0,
       0,   411,     0,     0,     0,     0,     0,     0,     0,     0,
     386,   387,   388,   389,   390,   391,   392,   394,   393,   396,
     400,   397,   398,   399,   395,   437,     0,     0,     0,   434,
     435,   436,     0,     0,   441,   452,     0,     0,     0,   449,
     450,   451,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   456,     0,     0,     0,   303,     0,     0,     0,
       0,     0,     0,   289,   290,   291,   292,   297,   293,   294,
     295,   296,   428,     0,     0,     0,   425,   426,   427,     0,
       0,     0,   264,     0,   274,     0,   272,   273,   275,   276,
      48,     0,     0,     0,    44,     0,     0,     0,     0,   110,
     111,   112,     0,     0,     0,   193,     0,     0,     0,     0,
       0,   168,     0,     0,   148,   149,   150,   151,   154,   155,
     156,   157,   153,   152,   158,     0,     0,     0,     0,     0,
     323,   324,   325,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   636,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    52,     0,     0,   369,     0,   364,   365,
     366,   121,     0,     0,   117,     0,     0,     0,   332,     0,
       0,   347,     0,     0,   340,   341,   342,   343,     0,     0,
       0,    97,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,   607,   240,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   222,   401,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   385,     0,     0,     0,   433,     0,   440,     0,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,   298,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   288,     0,     0,     0,   424,   277,
       0,     0,     0,     0,     0,   271,     0,     0,    43,   113,
       0,     0,     0,   109,   159,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   147,   327,     0,     0,
       0,     0,   322,     0,     0,     0,     0,     0,     0,     0,
       0,   635,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    76,    77,     0,    75,    80,
      81,     0,    79,     0,     0,    51,   367,     0,     0,     0,
     363,     0,   116,     0,     0,   331,   344,     0,     0,     0,
       0,   339,   106,   105,   104,   630,   629,   623,   633,    27,
      27,    27,    27,    27,    27,    27,    29,    28,   634,   624,
     625,   628,   627,   626,   631,   632,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,     0,     0,   221,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   384,
       0,     0,   432,   445,     0,     0,   447,   520,   524,   539,
     509,   606,   552,   546,   549,   519,   511,   510,   513,   514,
     512,   527,   517,   518,   528,   516,   523,   522,   521,   547,
     508,   604,   605,   543,   589,   583,   600,   584,   585,   586,
     594,   603,   587,   597,   601,   590,   602,   595,   591,   596,
     588,   599,   593,   592,   598,     0,   582,   545,   563,   558,
     575,   559,   560,   561,   569,   578,   562,   572,   576,   565,
     577,   570,   566,   571,   564,   574,   568,   567,   573,     0,
     557,   540,   538,   541,   551,   542,   530,   536,   537,   534,
     535,   531,   532,   533,   550,   553,   515,   544,   526,   525,
     548,   529,     0,     0,     0,     0,     0,     0,     0,     0,
     287,     0,     0,   423,     0,     0,     0,   282,   278,   281,
     263,    49,    50,     0,     0,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,     0,     0,     0,
     321,   648,   647,   653,   651,   654,   649,   650,   652,    88,
      96,    87,    94,    95,    86,    90,    89,    83,    82,    84,
      93,    85,    72,     0,    73,     0,    91,    92,     0,     0,
     362,   122,     0,     0,     0,   134,     0,   126,   127,   129,
     128,   336,     0,     0,     0,   338,    30,    31,    32,    33,
      34,    35,    36,   251,   252,   244,   261,   260,     0,   259,
     246,   248,   255,   247,   245,   254,   241,   253,   243,   242,
      37,    37,    37,    39,    38,   249,   250,   406,   409,   410,
     420,   417,   403,   418,   415,   416,     0,   414,   419,   402,
     408,   405,   407,   421,   404,   438,   439,   453,   454,   580,
       0,   555,     0,   301,   302,   311,   308,   313,   309,   310,
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
      41,    42,   412,     0,   581,   556,   304,     0,   265,     0,
     283,   280,   279,     0,     0,     0,   194,     0,   169,     0,
     370,     0,     0,     0,     0,     0,   124,   348,     0,   258,
     413,   305,   266,   199,   197,   201,   195,   170,   371,   131,
     133,   132,   140,   143,   142,   139,   144,   141,   138,     0,
     137,   349,   135,     0,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   816,   817,  1073,  1074,    26,   222,   223,
     224,   225,    27,   266,   267,   268,   269,   777,   778,   781,
     782,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,    28,    74,    75,    76,
      77,    78,    29,    61,   498,   499,   500,   501,    30,   288,
     289,   290,   291,   292,  1036,  1037,  1038,  1039,  1040,  1210,
    1279,  1280,    31,    62,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   743,  1186,  1187,   524,   737,
    1158,  1159,    32,    51,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
     352,   353,   610,  1058,  1059,    33,    59,   484,   722,  1129,
    1130,   485,   486,   487,  1133,   978,   979,   488,   489,    34,
      57,   462,   463,   464,   465,   466,   467,   468,   707,  1115,
    1116,   469,   470,   471,    35,    63,   529,   530,   531,   532,
     533,    36,   295,   296,   297,    37,    69,   583,   584,   585,
     586,   587,   798,  1224,  1225,    38,    66,   567,   568,   569,
     570,   788,  1205,  1206,    39,    52,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   632,  1086,  1087,
     380,   381,   382,   383,   384,    40,    58,   475,   476,   477,
     478,    41,    53,   388,   389,   390,   391,    42,   111,   112,
     113,    43,    55,   398,   399,   400,   401,    44,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   431,   939,   940,   212,   429,
     915,   916,   213,   214,   215,    45,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      46,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -755
static const yytype_int16 yypact[] =
{
    -755,   716,  -755,  -198,  -223,  -208,  -755,  -755,  -755,  -186,
    -755,  -184,  -755,  -755,  -755,  -179,  -755,  -755,  -755,  -168,
    -154,  -755,  -146,  -123,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   282,
     923,   -84,   -59,   -46,   130,   -45,   414,   -39,   -26,   -19,
      79,   -18,   -11,    21,   503,   408,    40,    39,    53,    41,
     -14,    -1,    64,    66,     7,  -755,  -755,  -755,  -755,  -755,
      81,    82,    96,   100,   102,   104,   105,   117,   119,   121,
     127,   128,    13,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   706,   577,    61,  -755,
     131,    10,  -755,  -755,    36,  -755,   132,   133,   135,   139,
     141,   142,   143,   144,   146,   148,   151,   153,   157,   158,
     160,   162,   164,   165,   166,   168,   170,   180,   182,   183,
     187,   188,   189,  -755,   192,  -755,   193,   195,   197,   198,
     199,   200,   201,   202,   206,   207,   208,   209,   212,   213,
     216,   217,   219,   221,   222,   108,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   353,     8,   292,    29,
     223,   227,    24,  -755,  -755,  -755,    22,   546,    47,  -755,
     231,   236,   237,   240,   246,   248,   251,   253,    15,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,    60,   254,
     255,   257,   259,   260,   262,   263,   265,   266,   272,   288,
     291,   293,   294,   303,   305,   306,     9,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,     4,    65,   307,    19,  -755,
    -755,  -755,   155,  -755,   308,    23,  -755,  -755,    62,  -755,
     215,   352,   365,   270,  -755,   252,   431,   333,   436,   437,
     437,   437,   438,   440,   443,   349,   355,   335,  -755,   339,
     337,   344,   346,  -755,   351,   354,   357,   359,   360,   362,
     366,   367,   368,   369,   370,   372,   258,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,   356,   373,   377,   378,   381,   382,
     383,  -755,   384,   385,   386,   387,   388,   390,   391,   326,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   392,   393,    69,  -755,
    -755,  -755,   462,   397,  -755,  -755,   406,   407,    48,  -755,
    -755,  -755,   417,   437,   437,   428,   487,   432,   533,   520,
     435,   437,   439,   538,   539,   437,   540,   441,   445,   446,
     437,   545,   549,   437,   550,   551,   552,   553,   452,   433,
     455,   442,   456,   437,   437,   457,   458,   459,    58,    95,
     460,   461,   464,   554,   437,   466,   468,   437,   437,   469,
     471,   463,  -755,   465,   453,   454,  -755,   472,   473,   474,
     476,   480,   163,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,   481,   482,    50,  -755,  -755,  -755,   467,
     484,   485,  -755,   488,  -755,    25,  -755,  -755,  -755,  -755,
    -755,   559,   562,   496,  -755,   497,   499,   501,    18,  -755,
    -755,  -755,   508,   506,   507,  -755,   509,   511,   512,   514,
     515,  -755,   516,    14,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,   521,   519,   523,   526,    11,
    -755,  -755,  -755,  -755,   477,   478,   479,   563,   483,   528,
     547,   437,   531,  -755,  -755,   572,   555,   603,   651,   652,
     638,   639,   641,   643,   644,   647,   663,   649,   -99,   -42,
     653,   654,   548,  -755,   557,   544,  -755,    73,  -755,  -755,
    -755,  -755,   569,   558,  -755,   564,   657,   570,  -755,   574,
     556,  -755,   566,    27,  -755,  -755,  -755,  -755,   575,   576,
     578,  -755,   579,   580,   582,   583,   267,   584,   587,   590,
     591,   592,   593,   597,   605,  -755,  -755,   673,   674,   437,
     604,   734,   736,   437,   737,   738,   437,   727,   747,   749,
     437,   751,   751,   636,  -755,  -755,   750,   129,   752,   667,
     755,   758,   640,   762,   764,   781,   767,   769,   771,   775,
     672,  -755,   777,   778,   676,  -755,   677,  -755,   790,   793,
     693,  -755,   694,   696,   701,   704,   705,   708,   709,   710,
     714,   715,   717,   722,   723,   725,   728,   729,   730,   731,
     732,   733,   735,   739,   740,   741,   742,   743,   744,   660,
     745,   703,   748,   753,   754,   756,   757,   759,   760,   770,
     772,   773,   780,   782,   783,   784,   785,   788,   789,   791,
     792,   794,   795,  -755,  -755,   807,   763,   713,   810,   853,
     841,   842,   851,   796,  -755,   854,   855,   797,  -755,  -755,
     856,   859,   761,   868,   798,  -755,   799,   802,  -755,  -755,
     862,   873,   803,  -755,  -755,   875,   804,   774,   882,   885,
     894,   897,   821,   805,   909,   806,  -755,  -755,   911,   913,
     914,   811,  -755,   812,   813,   814,   815,   816,   817,   818,
     819,  -755,   820,   822,   823,   824,   825,   826,   827,   828,
     829,   830,   831,   832,   833,  -755,  -755,  -209,  -755,  -755,
    -755,  -189,  -755,   834,   835,  -755,  -755,   925,   836,   837,
    -755,   838,  -755,    26,   840,  -755,  -755,   940,   839,   945,
     843,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   437,
     437,   437,   437,   437,   437,   437,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   844,   845,   846,   -34,
     847,   848,   849,   850,   852,   857,   858,   860,   861,   863,
     289,   864,   865,  -755,   866,   867,   869,   870,   871,   872,
     874,     5,   876,   877,   878,   879,   880,   881,   883,  -755,
     884,   886,  -755,  -755,   887,   888,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -174,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -172,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   889,   890,   245,   891,   892,   893,   895,   896,
    -755,   898,   899,  -755,   900,   901,   -16,   904,   902,  -755,
    -755,  -755,  -755,   903,   905,  -755,   907,   908,   524,   910,
     912,   915,   916,   917,   746,   918,  -755,   919,   920,   921,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,   -99,  -755,   -42,  -755,  -755,   922,   632,
    -755,  -755,   924,   906,   926,  -755,    57,  -755,  -755,  -755,
    -755,  -755,   927,   787,   928,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -171,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     751,   751,   751,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -155,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     660,  -755,   703,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,   -50,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -49,
    -755,   970,   868,   930,  -755,  -755,  -755,  -755,  -755,   929,
    -755,  -755,   931,  -755,  -755,  -755,  -755,   932,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -23,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,   -15,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,     0,  -755,  -755,   957,  -101,
     935,   933,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,    30,  -755,  -755,  -755,   -34,  -755,
    -755,  -755,  -755,     5,  -755,  -755,  -755,   245,  -755,   -16,
    -755,  -755,  -755,   952,   953,   954,  -755,   524,  -755,   746,
    -755,   632,   939,   941,   942,   297,  -755,  -755,   787,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,    55,
    -755,  -755,  -755,   297,  -755
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -755,  -755,  -755,  -298,  -307,  -754,  -621,  -755,  -755,   936,
    -755,  -755,  -755,  -755,   934,  -755,  -755,  -755,    63,  -755,
      70,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  1015,  -755,
    -755,  -755,  -755,  -755,  -755,   602,  -755,  -755,  -755,  -755,
     937,  -755,  -755,  -755,  -755,    76,  -755,  -755,  -755,  -755,
    -755,  -181,  -755,  -755,  -755,   596,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -125,  -755,  -755,
    -755,  -118,  -755,  -755,  -755,   938,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,   -97,  -755,  -755,  -755,  -755,  -755,
     -98,  -755,   655,  -755,  -755,  -755,     6,  -755,  -755,  -755,
    -755,  -755,   688,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
     -85,  -755,  -755,  -755,  -755,  -755,  -755,   624,  -755,  -755,
    -755,  -755,  -755,   943,  -755,  -755,  -755,  -755,   588,  -755,
    -755,  -755,  -755,  -755,   -96,  -755,  -755,  -755,   600,  -755,
    -755,  -755,  -755,   -92,  -755,  -755,  -755,   801,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   -61,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,   698,  -755,
    -755,  -755,  -755,  -755,   786,  -755,  -755,  -755,  -755,  1064,
    -755,  -755,  -755,  -755,   779,  -755,  -755,  -755,  -755,  1011,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,    77,  -755,  -755,
    -755,    78,  -755,  -755,  -755,  -755,  -755,  1088,  -755,  -755,
    -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755,  -755,   944,  -755,  -755,  -755,  -755,  -755,  -755,  -755,
    -755
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
     841,   842,   597,   598,   599,   564,    49,   840,    70,   472,
     248,   109,   525,  1084,    79,   502,   229,  1056,  1022,   495,
     286,    50,  1023,   495,   293,   219,   479,  1032,   579,    47,
      48,   503,    71,  1126,   249,    80,    81,   395,  1024,    72,
     286,    82,  1025,    54,   230,    56,   526,   504,   525,   395,
      60,   472,   231,  1099,   293,  1101,  1227,  1100,  1032,  1102,
    1228,    64,   385,   579,   232,   233,   250,   234,   235,   236,
     385,   110,  1232,   251,   564,    65,  1233,   505,    83,    84,
     219,   480,   526,    67,    85,    86,   481,   527,   482,   237,
    1057,    87,    88,    89,   496,   252,   653,   654,   496,   253,
     775,   776,   565,  1253,   661,    73,    68,   254,   665,   115,
     255,   256,   506,   670,   116,   117,   673,    90,    91,   220,
     118,   294,   386,   527,  1033,   580,   683,   684,   119,   120,
     386,   109,   507,   473,   396,   121,   528,   696,   122,   123,
     699,   700,   257,   221,   124,   106,   396,   483,   508,   125,
     126,   294,   127,   128,   129,  1033,   130,   779,   780,   258,
     580,   397,   259,   131,   453,   509,   510,   132,   133,  1127,
     107,   565,   528,   397,   220,   473,   134,  1236,  1238,  1128,
     454,  1237,  1239,   108,   114,   135,   387,   260,   497,  -123,
     216,   110,   497,   136,   387,   137,   455,   138,   221,   139,
    1085,   140,   141,   217,  1246,   261,   262,   263,  1247,  -123,
     218,   226,  1248,   299,   142,   511,  1249,  1034,   227,   143,
     144,   145,   566,   146,   147,   148,   456,  1250,   149,   300,
     474,  1251,   264,   265,   760,   303,   512,   562,   393,   751,
     287,   317,   745,   542,  1035,   581,   732,   573,  1034,   582,
     228,   577,   493,   724,   150,   800,   490,  1257,  1105,   319,
     287,  1258,   151,   152,   153,   154,   155,   156,   688,   285,
     298,   689,   474,   320,   321,  1035,   650,   322,   717,  1106,
     581,   457,  1282,    70,   582,  1211,  1283,   544,  1107,   458,
     459,   566,   571,   479,   301,   157,   302,   644,  1070,  1071,
    1072,   789,   828,   845,   846,   690,   832,    71,   691,   835,
     460,   305,   306,   839,    72,  1108,  1229,  1230,  1231,   158,
     159,   323,   160,   161,   162,   575,   307,   354,   163,   355,
     308,   356,   309,   164,   310,   311,   451,  1272,   588,   324,
     325,   326,   327,   357,  1109,  1110,   328,   312,   480,   313,
     329,   314,  1111,   481,   453,   482,   330,   315,   316,   358,
     592,   392,   402,   403,  1273,   404,  1274,   331,   332,   405,
     454,   406,   407,   408,   409,   596,   410,  1112,   411,   333,
      73,   412,   359,   413,   360,   461,   455,   414,   415,   361,
     416,   713,   417,  1113,   418,   419,   420,   840,   421,   362,
     422,   334,   809,   810,   811,   812,   813,   814,   815,   248,
     423,  1275,   424,   425,   483,   115,   456,   426,   427,   428,
     116,   117,   430,   432,   363,   433,   118,   434,   435,   436,
     437,   438,   439,   249,   119,   120,   440,   441,   442,   443,
     335,   121,   444,   445,   122,   123,   446,   447,   364,   448,
     124,   449,   450,   491,  1114,   125,   126,   492,   127,   128,
     129,   534,   130,  1276,  1277,   250,   535,   536,   365,   131,
     537,   457,   251,   132,   133,   589,   538,   366,   539,   458,
     459,   540,   134,   541,   545,   546,   623,   547,   590,   548,
     549,   135,   550,   551,   252,   552,   553,   591,   253,   136,
     460,   137,   554,   138,   229,   139,   254,   140,   141,   255,
     256,  1046,  1047,  1048,  1049,  1050,  1051,  1052,   555,  1278,
     142,   556,   367,   557,   558,   143,   144,   145,  1138,   146,
     147,   148,   230,   559,   149,   560,   561,   572,   576,   593,
     231,   257,  1139,   594,   595,   596,   600,   502,   601,   368,
    1140,   602,   232,   233,   640,   234,   235,   236,   258,   603,
     150,   259,   605,   503,  1141,   604,   606,   607,   151,   152,
     153,   154,   155,   156,   608,   461,   609,   237,   354,   504,
     355,   611,   356,   625,   612,   646,   260,   613,  1254,   614,
     615,  1142,   616,  1143,   357,   656,   617,   618,   619,   620,
     621,   157,   622,   626,   261,   262,   263,   627,   628,   505,
     358,   629,   630,   631,   633,   634,   635,   636,   637,  1144,
     638,   639,   642,   643,   647,   158,   159,   652,   160,   161,
     162,   264,   265,   359,   163,   360,   648,   649,   655,   164,
     361,   658,   657,   659,   506,   660,   663,   664,   666,   662,
     362,   667,  1145,   671,  1146,   668,   669,   672,   674,   675,
     676,   677,   678,   679,   507,   680,   682,   685,   686,   687,
     692,   693,   681,  1147,   694,   363,   697,   695,   698,   701,
     508,   702,   726,   705,   706,   727,   756,   753,   754,   755,
     703,  1148,   704,   757,   719,   762,  1149,   509,   510,   364,
    1150,  1195,   708,   709,   710,  1151,   711,   319,  1152,   894,
     712,   715,   716,  1153,   720,   721,     2,     3,   723,   365,
       4,   320,   321,   728,   729,   322,   764,  1154,   366,   730,
       5,   731,  1155,     6,     7,   734,   735,   736,   758,   738,
       8,   739,   740,  1156,   741,   742,   744,   511,   747,   748,
    1157,     9,   918,   749,    10,    11,   750,   759,   761,   765,
     766,   767,   768,  1196,   769,   763,   770,   771,   512,   323,
     772,   773,   774,   367,   787,   785,   783,   784,    12,   791,
     794,   826,   827,    13,   786,   792,   797,   324,   325,   326,
     327,    14,  1197,   793,   328,  1165,   799,   795,   329,  1198,
     368,   796,   802,   803,   330,   804,   805,   806,  1199,   807,
     808,   818,    15,    16,   819,   331,   332,   820,   821,   822,
     823,   895,   896,   897,   824,   898,   899,   333,   900,   901,
      17,   902,   825,   903,   829,  1200,   904,  1201,  1202,   905,
     906,   907,   830,   908,   831,   833,   834,    18,   909,   334,
     836,  1203,   910,   911,   912,   837,  1214,   838,  1204,   840,
      19,    20,   913,   843,   919,   920,   921,   914,   922,   923,
     851,   924,   925,   844,   926,   847,   927,   848,   849,   928,
      21,   850,   929,   930,   931,   852,   932,   853,   335,   854,
     855,   933,   856,    22,   857,   934,   935,   936,   858,   859,
     860,   861,    23,   862,   863,   937,    24,  1166,  1167,  1168,
     938,  1169,  1170,   864,  1171,  1172,   865,  1173,  1215,  1174,
     866,   867,  1175,   868,    79,  1176,  1177,  1178,   869,  1179,
     962,   870,   871,   965,  1180,   872,   873,   874,  1181,  1182,
    1183,   875,   876,   964,   877,    80,    81,  1216,  1184,   878,
     879,    82,   880,  1185,  1217,   881,   882,   883,   884,   885,
     886,   966,   887,  1218,   967,   968,   888,   889,   890,   891,
     892,   893,   917,   963,   969,   941,   977,   971,   972,   974,
     942,   943,   975,   944,   945,   983,   946,   947,    83,    84,
    1219,   976,  1220,  1221,    85,    86,   984,   948,   986,   949,
     950,    87,    88,    89,   988,   989,  1222,   951,   990,   952,
     953,   954,   955,  1223,   987,   956,   957,   991,   958,   959,
     992,   960,   961,   970,   973,   980,   981,    90,    91,   982,
     985,   993,   995,   996,   997,   994,   998,   999,  1000,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1028,  1010,
    1011,  1012,  1013,  1014,  1015,  1016,  1017,  1018,  1019,  1020,
    1021,  1026,  1027,  1042,  1030,  1031,  1029,  1041,  1044,  1043,
    1045,  1053,  1054,  1055,  1060,  1061,  1062,  1063,  1240,  1064,
    1252,  1263,  1264,  1265,  1065,  1066,  1192,  1067,  1068,   304,
    1069,  1075,  1076,  1077,  1078,  1193,  1079,  1080,  1081,  1082,
     733,  1083,  1284,  1088,  1089,  1090,  1091,  1092,  1093,   746,
    1094,  1095,  1212,  1096,  1097,  1098,  1103,  1104,  1117,  1118,
    1119,  1131,  1120,  1121,  1267,  1122,  1123,  1124,  1125,  1266,
    1134,  1259,  1135,  1132,  1136,  1137,  1208,  1160,  1241,  1161,
     725,  1262,  1162,  1163,  1164,  1188,  1189,  1190,  1191,  1194,
     714,  1207,  1261,   752,  1213,  1226,  1209,  1242,   494,  1268,
    1256,  1243,  1281,  1244,  1245,  1255,  1269,   790,  1270,  1271,
     641,   801,  1260,   718,   645,   394,   452,   651,  1234,  1235,
     318,     0,   543,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     563,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   574,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   578,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   624
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-755)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     621,   622,   309,   310,   311,     1,   229,   108,     1,     1,
       1,     1,     1,     8,     1,     1,     1,    51,   227,     1,
       1,   229,   231,     1,     1,     1,     1,     1,     1,   227,
     228,    17,    25,    49,    25,    22,    23,     1,   227,    32,
       1,    28,   231,   229,    29,   229,    35,    33,     1,     1,
     229,     1,    37,   227,     1,   227,   227,   231,     1,   231,
     231,   229,     1,     1,    49,    50,    57,    52,    53,    54,
       1,    61,   227,    64,     1,   229,   231,    63,    65,    66,
       1,    56,    35,   229,    71,    72,    61,    76,    63,    74,
     124,    78,    79,    80,    76,    86,   403,   404,    76,    90,
     199,   200,    98,   204,   411,    98,   229,    98,   415,     1,
     101,   102,    98,   420,     6,     7,   423,   104,   105,    95,
      12,    98,    61,    76,    98,    98,   433,   434,    20,    21,
      61,     1,   118,   125,    98,    27,   125,   444,    30,    31,
     447,   448,   133,   119,    36,   229,    98,   122,   134,    41,
      42,    98,    44,    45,    46,    98,    48,   199,   200,   150,
      98,   125,   153,    55,     1,   151,   152,    59,    60,   185,
     229,    98,   125,   125,    95,   125,    68,   227,   227,   195,
      17,   231,   231,   229,   229,    77,   125,   178,   170,   170,
     229,    61,   170,    85,   125,    87,    33,    89,   119,    91,
     195,    93,    94,   229,   227,   196,   197,   198,   231,   170,
     229,   229,   227,   227,   106,   201,   231,   191,   229,   111,
     112,   113,   218,   115,   116,   117,    63,   227,   120,   230,
     222,   231,   223,   224,   541,   228,   222,   228,   228,   228,
     221,   228,   228,   228,   218,   218,   228,   228,   191,   222,
     229,   228,   228,   228,   146,   228,   227,   227,    13,     1,
     221,   231,   154,   155,   156,   157,   158,   159,   210,   229,
     229,   213,   222,    15,    16,   218,   228,    19,   228,    34,
     218,   118,   227,     1,   222,   228,   231,   227,    43,   126,
     127,   218,   227,     1,   230,   187,   230,   228,     9,    10,
      11,   228,   609,   174,   175,   210,   613,    25,   213,   616,
     147,   230,   230,   620,    32,    70,  1070,  1071,  1072,   211,
     212,    63,   214,   215,   216,   170,   230,     1,   220,     3,
     230,     5,   230,   225,   230,   230,   228,    40,   123,    81,
      82,    83,    84,    17,    99,   100,    88,   230,    56,   230,
      92,   230,   107,    61,     1,    63,    98,   230,   230,    33,
     108,   230,   230,   230,    67,   230,    69,   109,   110,   230,
      17,   230,   230,   230,   230,   108,   230,   132,   230,   121,
      98,   230,    56,   230,    58,   222,    33,   230,   230,    63,
     230,   228,   230,   148,   230,   230,   230,   108,   230,    73,
     230,   143,   135,   136,   137,   138,   139,   140,   141,     1,
     230,   114,   230,   230,   122,     1,    63,   230,   230,   230,
       6,     7,   230,   230,    98,   230,    12,   230,   230,   230,
     230,   230,   230,    25,    20,    21,   230,   230,   230,   230,
     182,    27,   230,   230,    30,    31,   230,   230,   122,   230,
      36,   230,   230,   230,   209,    41,    42,   230,    44,    45,
      46,   230,    48,   166,   167,    57,   230,   230,   142,    55,
     230,   118,    64,    59,    60,   123,   230,   151,   230,   126,
     127,   230,    68,   230,   230,   230,   228,   230,   123,   230,
     230,    77,   230,   230,    86,   230,   230,   227,    90,    85,
     147,    87,   230,    89,     1,    91,    98,    93,    94,   101,
     102,   809,   810,   811,   812,   813,   814,   815,   230,   222,
     106,   230,   196,   230,   230,   111,   112,   113,     4,   115,
     116,   117,    29,   230,   120,   230,   230,   230,   230,   108,
      37,   133,    18,   210,   108,   108,   108,     1,   108,   223,
      26,   108,    49,    50,   228,    52,    53,    54,   150,   210,
     146,   153,   227,    17,    40,   210,   227,   230,   154,   155,
     156,   157,   158,   159,   230,   222,   230,    74,     1,    33,
       3,   230,     5,   227,   230,   123,   178,   230,  1209,   230,
     230,    67,   230,    69,    17,   108,   230,   230,   230,   230,
     230,   187,   230,   230,   196,   197,   198,   230,   230,    63,
      33,   230,   230,   230,   230,   230,   230,   230,   230,    95,
     230,   230,   230,   230,   227,   211,   212,   210,   214,   215,
     216,   223,   224,    56,   220,    58,   230,   230,   210,   225,
      63,   108,   210,   123,    98,   210,   108,   108,   108,   210,
      73,   210,   128,   108,   130,   210,   210,   108,   108,   108,
     108,   108,   210,   230,   118,   210,   210,   210,   210,   210,
     210,   210,   230,   149,   210,    98,   210,   123,   210,   210,
     134,   210,   123,   230,   230,   123,   123,   210,   210,   210,
     227,   167,   227,   210,   227,   123,   172,   151,   152,   122,
     176,    69,   230,   230,   230,   181,   230,     1,   184,    49,
     230,   230,   230,   189,   230,   230,     0,     1,   230,   142,
       4,    15,    16,   227,   227,    19,   123,   203,   151,   230,
      14,   230,   208,    17,    18,   227,   230,   230,   210,   230,
      24,   230,   230,   219,   230,   230,   230,   201,   227,   230,
     226,    35,    49,   230,    38,    39,   230,   210,   227,   108,
     108,   123,   123,   131,   123,   210,   123,   123,   222,    63,
     123,   108,   123,   196,   230,   227,   123,   123,    62,   210,
     123,   108,   108,    67,   227,   227,   230,    81,    82,    83,
      84,    75,   160,   229,    88,    49,   230,   227,    92,   167,
     223,   227,   227,   227,    98,   227,   227,   227,   176,   227,
     227,   227,    96,    97,   227,   109,   110,   227,   227,   227,
     227,   161,   162,   163,   227,   165,   166,   121,   168,   169,
     114,   171,   227,   173,   230,   203,   176,   205,   206,   179,
     180,   181,   108,   183,   108,   108,   108,   131,   188,   143,
     123,   219,   192,   193,   194,   108,    69,   108,   226,   108,
     144,   145,   202,   227,   161,   162,   163,   207,   165,   166,
     230,   168,   169,   123,   171,   123,   173,   210,   123,   176,
     164,   123,   179,   180,   181,   123,   183,   123,   182,   108,
     123,   188,   123,   177,   123,   192,   193,   194,   123,   227,
     123,   123,   186,   227,   227,   202,   190,   161,   162,   163,
     207,   165,   166,   123,   168,   169,   123,   171,   131,   173,
     227,   227,   176,   227,     1,   179,   180,   181,   227,   183,
     123,   227,   227,   123,   188,   227,   227,   227,   192,   193,
     194,   227,   227,   230,   227,    22,    23,   160,   202,   227,
     227,    28,   227,   207,   167,   227,   227,   227,   227,   227,
     227,   108,   227,   176,   123,   123,   227,   227,   227,   227,
     227,   227,   227,   210,   123,   227,   108,   123,   123,   123,
     227,   227,   123,   227,   227,   123,   227,   227,    65,    66,
     203,   230,   205,   206,    71,    72,   123,   227,   123,   227,
     227,    78,    79,    80,   230,   123,   219,   227,   123,   227,
     227,   227,   227,   226,   210,   227,   227,   123,   227,   227,
     123,   227,   227,   227,   227,   227,   227,   104,   105,   227,
     227,   210,   123,   227,   123,   230,   123,   123,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   123,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   123,   227,   227,   230,   227,   123,   230,
     227,   227,   227,   227,   227,   227,   227,   227,   108,   227,
     123,   129,   129,   129,   227,   227,  1023,   227,   227,    74,
     227,   227,   227,   227,   227,  1025,   227,   227,   227,   227,
     498,   227,  1283,   227,   227,   227,   227,   227,   227,   513,
     227,   227,  1036,   227,   227,   227,   227,   227,   227,   227,
     227,   217,   227,   227,  1249,   227,   227,   227,   227,  1247,
     227,  1228,   227,   231,   227,   227,   230,   227,  1132,   227,
     485,  1239,   227,   227,   227,   227,   227,   227,   227,   227,
     462,   227,  1237,   529,   227,   227,   230,   227,   222,  1251,
     227,   232,  1258,   232,   232,   230,   227,   567,   227,   227,
     369,   583,  1233,   475,   388,   111,   165,   398,  1100,  1102,
      92,    -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     266,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   288,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   295,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   336
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   234,     0,     1,     4,    14,    17,    18,    24,    35,
      38,    39,    62,    67,    75,    96,    97,   114,   131,   144,
     145,   164,   177,   186,   190,   235,   240,   245,   269,   275,
     281,   295,   315,   338,   352,   367,   374,   378,   388,   397,
     418,   424,   430,   434,   440,   498,   513,   227,   228,   229,
     229,   316,   398,   425,   229,   435,   229,   353,   419,   339,
     229,   276,   296,   368,   229,   229,   389,   229,   229,   379,
       1,    25,    32,    98,   270,   271,   272,   273,   274,     1,
      22,    23,    28,    65,    66,    71,    72,    78,    79,    80,
     104,   105,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   229,   229,   229,     1,
      61,   431,   432,   433,   229,     1,     6,     7,    12,    20,
      21,    27,    30,    31,    36,    41,    42,    44,    45,    46,
      48,    55,    59,    60,    68,    77,    85,    87,    89,    91,
      93,    94,   106,   111,   112,   113,   115,   116,   117,   120,
     146,   154,   155,   156,   157,   158,   159,   187,   211,   212,
     214,   215,   216,   220,   225,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   491,   495,   496,   497,   229,   229,   229,     1,
      95,   119,   241,   242,   243,   244,   229,   229,   229,     1,
      29,    37,    49,    50,    52,    53,    54,    74,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,     1,    25,
      57,    64,    86,    90,    98,   101,   102,   133,   150,   153,
     178,   196,   197,   198,   223,   224,   246,   247,   248,   249,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   229,     1,   221,   282,   283,
     284,   285,   286,     1,    98,   375,   376,   377,   229,   227,
     230,   230,   230,   228,   271,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   228,   500,     1,
      15,    16,    19,    63,    81,    82,    83,    84,    88,    92,
      98,   109,   110,   121,   143,   182,   317,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,   333,   334,     1,     3,     5,    17,    33,    56,
      58,    63,    73,    98,   122,   142,   151,   196,   223,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   409,
     413,   414,   415,   416,   417,     1,    61,   125,   426,   427,
     428,   429,   230,   228,   432,     1,    98,   125,   436,   437,
     438,   439,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   492,
     230,   488,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   228,   442,     1,    17,    33,    63,   118,   126,   127,
     147,   222,   354,   355,   356,   357,   358,   359,   360,   364,
     365,   366,     1,   125,   222,   420,   421,   422,   423,     1,
      56,    61,    63,   122,   340,   344,   345,   346,   350,   351,
     227,   230,   230,   228,   242,     1,    76,   170,   277,   278,
     279,   280,     1,    17,    33,    63,    98,   118,   134,   151,
     152,   201,   222,   297,   298,   299,   300,   301,   302,   303,
     304,   305,   306,   307,   311,     1,    35,    76,   125,   369,
     370,   371,   372,   373,   230,   230,   230,   230,   230,   230,
     230,   230,   228,   515,   227,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   228,   247,     1,    98,   218,   390,   391,   392,
     393,   227,   230,   228,   283,   170,   230,   228,   376,     1,
      98,   218,   222,   380,   381,   382,   383,   384,   123,   123,
     123,   227,   108,   108,   210,   108,   108,   237,   237,   237,
     108,   108,   108,   210,   210,   227,   227,   230,   230,   230,
     335,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   228,   318,   227,   230,   230,   230,   230,
     230,   230,   410,   230,   230,   230,   230,   230,   230,   230,
     228,   400,   230,   230,   228,   427,   123,   227,   230,   230,
     228,   437,   210,   237,   237,   210,   108,   210,   108,   123,
     210,   237,   210,   108,   108,   237,   108,   210,   210,   210,
     237,   108,   108,   237,   108,   108,   108,   108,   210,   230,
     210,   230,   210,   237,   237,   210,   210,   210,   210,   213,
     210,   213,   210,   210,   210,   123,   237,   210,   210,   237,
     237,   210,   210,   227,   227,   230,   230,   361,   230,   230,
     230,   230,   230,   228,   355,   230,   230,   228,   421,   227,
     230,   230,   341,   230,   228,   345,   123,   123,   227,   227,
     230,   230,   228,   278,   227,   230,   230,   312,   230,   230,
     230,   230,   230,   308,   230,   228,   298,   227,   230,   230,
     230,   228,   370,   210,   210,   210,   123,   210,   210,   210,
     237,   227,   123,   210,   123,   108,   108,   123,   123,   123,
     123,   123,   123,   108,   123,   199,   200,   250,   251,   199,
     200,   252,   253,   123,   123,   227,   227,   230,   394,   228,
     391,   210,   227,   229,   123,   227,   227,   230,   385,   230,
     228,   381,   227,   227,   227,   227,   227,   227,   227,   135,
     136,   137,   138,   139,   140,   141,   236,   237,   227,   227,
     227,   227,   227,   227,   227,   227,   108,   108,   237,   230,
     108,   108,   237,   108,   108,   237,   123,   108,   108,   237,
     108,   239,   239,   227,   123,   174,   175,   123,   210,   123,
     123,   230,   123,   123,   108,   123,   123,   123,   123,   227,
     123,   123,   227,   227,   123,   123,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,    49,   161,   162,   163,   165,   166,
     168,   169,   171,   173,   176,   179,   180,   181,   183,   188,
     192,   193,   194,   202,   207,   493,   494,   227,    49,   161,
     162,   163,   165,   166,   168,   169,   171,   173,   176,   179,
     180,   181,   183,   188,   192,   193,   194,   202,   207,   489,
     490,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   123,   210,   230,   123,   108,   123,   123,   123,
     227,   123,   123,   227,   123,   123,   230,   108,   348,   349,
     227,   227,   227,   123,   123,   227,   123,   210,   230,   123,
     123,   123,   123,   210,   230,   123,   227,   123,   123,   123,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   231,   227,   231,   227,   227,   123,   230,
     227,   227,     1,    98,   191,   218,   287,   288,   289,   290,
     291,   227,   123,   230,   123,   227,   236,   236,   236,   236,
     236,   236,   236,   227,   227,   227,    51,   124,   336,   337,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
       9,    10,    11,   238,   239,   227,   227,   227,   227,   227,
     227,   227,   227,   227,     8,   195,   411,   412,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     231,   227,   231,   227,   227,    13,    34,    43,    70,    99,
     100,   107,   132,   148,   209,   362,   363,   227,   227,   227,
     227,   227,   227,   227,   227,   227,    49,   185,   195,   342,
     343,   217,   231,   347,   227,   227,   227,   227,     4,    18,
      26,    40,    67,    69,    95,   128,   130,   149,   167,   172,
     176,   181,   184,   189,   203,   208,   219,   226,   313,   314,
     227,   227,   227,   227,   227,    49,   161,   162,   163,   165,
     166,   168,   169,   171,   173,   176,   179,   180,   181,   183,
     188,   192,   193,   194,   202,   207,   309,   310,   227,   227,
     227,   227,   251,   253,   227,    69,   131,   160,   167,   176,
     203,   205,   206,   219,   226,   395,   396,   227,   230,   230,
     292,   228,   288,   227,    69,   131,   160,   167,   176,   203,
     205,   206,   219,   226,   386,   387,   227,   227,   231,   238,
     238,   238,   227,   231,   494,   490,   227,   231,   227,   231,
     108,   349,   227,   232,   232,   232,   227,   231,   227,   231,
     227,   231,   123,   204,   239,   230,   227,   227,   231,   337,
     412,   363,   343,   129,   129,   129,   314,   310,   396,   227,
     227,   227,    40,    67,    69,   114,   166,   167,   222,   293,
     294,   387,   227,   231,   294
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
#line 400 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 402 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 406 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 414 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 418 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 422 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 426 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 430 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 437 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 438 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 439 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 485 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 491 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 500 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 506 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 514 "conf_parser.y"
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
#line 556 "conf_parser.y"
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
#line 615 "conf_parser.y"
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
#line 643 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 651 "conf_parser.y"
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
#line 666 "conf_parser.y"
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
#line 681 "conf_parser.y"
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
#line 690 "conf_parser.y"
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
#line 704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 713 "conf_parser.y"
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
#line 741 "conf_parser.y"
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
#line 771 "conf_parser.y"
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
#line 796 "conf_parser.y"
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
#line 818 "conf_parser.y"
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
#line 840 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 885 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 889 "conf_parser.y"
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
#line 906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 912 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 937 "conf_parser.y"
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
#line 953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 961 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 964 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 969 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 1000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1010 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1017 "conf_parser.y"
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
#line 1097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1115 "conf_parser.y"
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
#line 1126 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1132 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1138 "conf_parser.y"
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
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1166 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1182 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1190 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1206 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1263 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1267 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1271 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1275 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1279 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1283 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1287 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1291 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1295 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1299 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1303 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1307 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1311 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1315 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1319 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1323 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1327 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1331 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1335 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1339 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1343 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1353 "conf_parser.y"
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
#line 1365 "conf_parser.y"
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
#line 1431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1443 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1455 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1461 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1473 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1479 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1485 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1492 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1498 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1504 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1510 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1519 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1528 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1535 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1539 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 1549 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1555 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1561 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1565 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1569 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1577 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1582 "conf_parser.y"
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
#line 1596 "conf_parser.y"
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
#line 1616 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1622 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1631 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1635 "conf_parser.y"
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
#line 1678 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1684 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1690 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1696 "conf_parser.y"
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
#line 1707 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1714 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1718 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1722 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1726 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1730 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1734 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1738 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1742 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1750 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1756 "conf_parser.y"
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
#line 1770 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1779 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 1816 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 1822 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1837 "conf_parser.y"
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
#line 1852 "conf_parser.y"
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
#line 1863 "conf_parser.y"
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
#line 1880 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1886 "conf_parser.y"
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
#line 1905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1912 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 1916 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1957 "conf_parser.y"
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
#line 1966 "conf_parser.y"
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
#line 1981 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 1987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 1994 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 1998 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 2002 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2006 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2010 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2014 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2018 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2022 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2026 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2039 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2047 "conf_parser.y"
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
#line 2119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2137 "conf_parser.y"
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
#line 2150 "conf_parser.y"
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
#line 2163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 2175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2179 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2187 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2203 "conf_parser.y"
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
#line 2214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 2220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 2226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2232 "conf_parser.y"
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
#line 2247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2251 "conf_parser.y"
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
#line 2276 "conf_parser.y"
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
#line 2296 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2309 "conf_parser.y"
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
#line 2335 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 2341 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2355 "conf_parser.y"
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
#line 2372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 2376 "conf_parser.y"
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
#line 2398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2449 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.cycle_on_host_change = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2466 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2472 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2478 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2483 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2488 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2493 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2498 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2508 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2513 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2518 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2523 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2528 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2533 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2538 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2543 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2549 "conf_parser.y"
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

  case 528:
/* Line 1787 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2593 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2598 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2606 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2611 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2621 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2626 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2631 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2636 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2641 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2646 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2651 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2661 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2679 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2684 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2689 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2730 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2754 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2771 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2783 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2786 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2807 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 596:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 597:
/* Line 1787 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 598:
/* Line 1787 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 601:
/* Line 1787 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 602:
/* Line 1787 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 603:
/* Line 1787 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 604:
/* Line 1787 of yacc.c  */
#line 2836 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1787 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2874 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2894 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 2909 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 2919 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 634:
/* Line 1787 of yacc.c  */
#line 2924 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 647:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 648:
/* Line 1787 of yacc.c  */
#line 2950 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
    break;

  case 649:
/* Line 1787 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 650:
/* Line 1787 of yacc.c  */
#line 2962 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 651:
/* Line 1787 of yacc.c  */
#line 2968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 652:
/* Line 1787 of yacc.c  */
#line 2977 "conf_parser.y"
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

  case 653:
/* Line 1787 of yacc.c  */
#line 2991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 654:
/* Line 1787 of yacc.c  */
#line 2997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6889 "conf_parser.c"
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


