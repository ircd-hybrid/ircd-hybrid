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
     STATS_U_OPER_ONLY = 413,
     T_ALL = 414,
     T_BOTS = 415,
     T_CALLERID = 416,
     T_CCONN = 417,
     T_CLUSTER = 418,
     T_DEAF = 419,
     T_DEBUG = 420,
     T_DLINE = 421,
     T_EXTERNAL = 422,
     T_FARCONNECT = 423,
     T_FILE = 424,
     T_FULL = 425,
     T_GLOBOPS = 426,
     T_INVISIBLE = 427,
     T_IPV4 = 428,
     T_IPV6 = 429,
     T_LOCOPS = 430,
     T_LOG = 431,
     T_MAX_CLIENTS = 432,
     T_NCHANGE = 433,
     T_NONONREG = 434,
     T_OPERWALL = 435,
     T_RECVQ = 436,
     T_REJ = 437,
     T_RESTART = 438,
     T_SERVER = 439,
     T_SERVICE = 440,
     T_SERVICES_NAME = 441,
     T_SERVNOTICE = 442,
     T_SET = 443,
     T_SHARED = 444,
     T_SIZE = 445,
     T_SKILL = 446,
     T_SOFTCALLERID = 447,
     T_SPY = 448,
     T_SSL = 449,
     T_SSL_CIPHER_LIST = 450,
     T_SSL_CLIENT_METHOD = 451,
     T_SSL_SERVER_METHOD = 452,
     T_SSLV3 = 453,
     T_TLSV1 = 454,
     T_UMODES = 455,
     T_UNAUTH = 456,
     T_UNDLINE = 457,
     T_UNLIMITED = 458,
     T_UNRESV = 459,
     T_UNXLINE = 460,
     T_WALLOP = 461,
     T_WALLOPS = 462,
     T_WEBIRC = 463,
     TBOOL = 464,
     THROTTLE_TIME = 465,
     TKLINE_EXPIRE_NOTICES = 466,
     TMASKED = 467,
     TRUE_NO_OPER_FLOOD = 468,
     TS_MAX_DELTA = 469,
     TS_WARN_DELTA = 470,
     TWODOTS = 471,
     TYPE = 472,
     UNKLINE = 473,
     USE_EGD = 474,
     USE_LOGGING = 475,
     USER = 476,
     VHOST = 477,
     VHOST6 = 478,
     WARN_NO_NLINE = 479,
     XLINE = 480
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
#define STATS_U_OPER_ONLY 413
#define T_ALL 414
#define T_BOTS 415
#define T_CALLERID 416
#define T_CCONN 417
#define T_CLUSTER 418
#define T_DEAF 419
#define T_DEBUG 420
#define T_DLINE 421
#define T_EXTERNAL 422
#define T_FARCONNECT 423
#define T_FILE 424
#define T_FULL 425
#define T_GLOBOPS 426
#define T_INVISIBLE 427
#define T_IPV4 428
#define T_IPV6 429
#define T_LOCOPS 430
#define T_LOG 431
#define T_MAX_CLIENTS 432
#define T_NCHANGE 433
#define T_NONONREG 434
#define T_OPERWALL 435
#define T_RECVQ 436
#define T_REJ 437
#define T_RESTART 438
#define T_SERVER 439
#define T_SERVICE 440
#define T_SERVICES_NAME 441
#define T_SERVNOTICE 442
#define T_SET 443
#define T_SHARED 444
#define T_SIZE 445
#define T_SKILL 446
#define T_SOFTCALLERID 447
#define T_SPY 448
#define T_SSL 449
#define T_SSL_CIPHER_LIST 450
#define T_SSL_CLIENT_METHOD 451
#define T_SSL_SERVER_METHOD 452
#define T_SSLV3 453
#define T_TLSV1 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_WALLOP 461
#define T_WALLOPS 462
#define T_WEBIRC 463
#define TBOOL 464
#define THROTTLE_TIME 465
#define TKLINE_EXPIRE_NOTICES 466
#define TMASKED 467
#define TRUE_NO_OPER_FLOOD 468
#define TS_MAX_DELTA 469
#define TS_WARN_DELTA 470
#define TWODOTS 471
#define TYPE 472
#define UNKLINE 473
#define USE_EGD 474
#define USE_LOGGING 475
#define USER 476
#define VHOST 477
#define VHOST6 478
#define WARN_NO_NLINE 479
#define XLINE 480



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 140 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 682 "conf_parser.c"
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
#line 710 "conf_parser.c"

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
#define YYLAST   1239

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  290
/* YYNRULES -- Number of rules.  */
#define YYNRULES  652
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1280

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   480

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   230,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   231,   226,
       2,   229,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   228,     2,   227,     2,     2,     2,     2,
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
     225
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
    1461,  1463,  1465,  1467,  1469,  1471,  1473,  1475,  1480,  1485,
    1490,  1495,  1500,  1505,  1510,  1515,  1520,  1525,  1530,  1535,
    1540,  1545,  1550,  1555,  1560,  1565,  1570,  1575,  1580,  1585,
    1590,  1595,  1600,  1605,  1610,  1615,  1620,  1625,  1630,  1635,
    1640,  1645,  1650,  1655,  1660,  1665,  1670,  1675,  1680,  1685,
    1690,  1695,  1700,  1701,  1707,  1711,  1713,  1715,  1717,  1719,
    1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,
    1741,  1743,  1745,  1747,  1749,  1751,  1753,  1755,  1756,  1762,
    1766,  1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,  1784,
    1786,  1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,  1804,
    1806,  1808,  1810,  1815,  1820,  1825,  1831,  1834,  1836,  1838,
    1840,  1842,  1844,  1846,  1848,  1850,  1852,  1854,  1856,  1858,
    1860,  1862,  1867,  1872,  1877,  1882,  1887,  1892,  1897,  1902,
    1907,  1912,  1917,  1922,  1928,  1931,  1933,  1935,  1937,  1939,
    1941,  1943,  1945,  1947,  1949,  1951,  1956,  1961,  1966,  1971,
    1976,  1981,  1986
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     233,     0,    -1,    -1,   233,   234,    -1,   268,    -1,   280,
      -1,   294,    -1,   496,    -1,   314,    -1,   337,    -1,   351,
      -1,   244,    -1,   511,    -1,   366,    -1,   373,    -1,   377,
      -1,   387,    -1,   396,    -1,   417,    -1,   423,    -1,   429,
      -1,   439,    -1,   433,    -1,   239,    -1,   274,    -1,     1,
     226,    -1,     1,   227,    -1,    -1,   236,    -1,   107,   235,
      -1,   107,   134,   235,    -1,   107,   135,   235,    -1,   107,
     136,   235,    -1,   107,   137,   235,    -1,   107,   138,   235,
      -1,   107,   139,   235,    -1,   107,   140,   235,    -1,    -1,
     238,    -1,   107,   237,    -1,   107,     9,   237,    -1,   107,
      10,   237,    -1,   107,    11,   237,    -1,    95,   228,   240,
     227,   226,    -1,   240,   241,    -1,   241,    -1,   242,    -1,
     243,    -1,     1,   226,    -1,    94,   229,   122,   226,    -1,
     118,   229,   122,   226,    -1,   144,   228,   245,   227,   226,
      -1,   245,   246,    -1,   246,    -1,   257,    -1,   262,    -1,
     267,    -1,   259,    -1,   260,    -1,   261,    -1,   264,    -1,
     265,    -1,   266,    -1,   255,    -1,   254,    -1,   263,    -1,
     258,    -1,   253,    -1,   247,    -1,   248,    -1,   256,    -1,
       1,   226,    -1,   196,   229,   249,   226,    -1,   197,   229,
     251,   226,    -1,   249,   230,   250,    -1,   250,    -1,   198,
      -1,   199,    -1,   251,   230,   252,    -1,   252,    -1,   198,
      -1,   199,    -1,   149,   229,   122,   226,    -1,   132,   229,
     122,   226,    -1,   152,   229,   122,   226,    -1,   195,   229,
     122,   226,    -1,    97,   229,   122,   226,    -1,    63,   229,
     122,   226,    -1,    24,   229,   122,   226,    -1,   101,   229,
     122,   226,    -1,   100,   229,   122,   226,    -1,   222,   229,
     122,   226,    -1,   223,   229,   122,   226,    -1,   177,   229,
     107,   226,    -1,    85,   229,   107,   226,    -1,    89,   229,
     107,   226,    -1,    56,   229,   209,   226,    -1,     4,   228,
     269,   227,   226,    -1,   269,   270,    -1,   270,    -1,   271,
      -1,   273,    -1,   272,    -1,     1,   226,    -1,    97,   229,
     122,   226,    -1,    31,   229,   122,   226,    -1,    24,   229,
     122,   226,    -1,    -1,    96,   275,   228,   276,   227,   226,
      -1,   276,   277,    -1,   277,    -1,   278,    -1,   279,    -1,
       1,   226,    -1,    75,   229,   122,   226,    -1,   169,   229,
     122,   226,    -1,   176,   228,   281,   227,   226,    -1,   281,
     282,    -1,   282,    -1,   283,    -1,   284,    -1,     1,   226,
      -1,   220,   229,   209,   226,    -1,    -1,   285,   169,   228,
     286,   227,   226,    -1,   286,   287,    -1,   287,    -1,   288,
      -1,   290,    -1,   289,    -1,     1,   226,    -1,    97,   229,
     122,   226,    -1,   190,   229,   238,   226,    -1,   190,   229,
     203,   226,    -1,    -1,   217,   291,   229,   292,   226,    -1,
     292,   230,   293,    -1,   293,    -1,   221,    -1,   113,    -1,
      39,    -1,   166,    -1,    68,    -1,    66,    -1,   165,    -1,
      -1,   113,   295,   228,   296,   227,   226,    -1,   296,   297,
      -1,   297,    -1,   298,    -1,   299,    -1,   300,    -1,   306,
      -1,   305,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,   310,    -1,     1,   226,    -1,    97,   229,   122,   226,
      -1,   221,   229,   122,   226,    -1,   117,   229,   122,   226,
      -1,    32,   229,   209,   226,    -1,   133,   229,   122,   226,
      -1,   150,   229,   122,   226,    -1,   151,   229,   209,   226,
      -1,    17,   229,   122,   226,    -1,    -1,   200,   307,   229,
     308,   226,    -1,   308,   230,   309,    -1,   309,    -1,   160,
      -1,   162,    -1,   164,    -1,   165,    -1,   170,    -1,    48,
      -1,   191,    -1,   178,    -1,   182,    -1,   201,    -1,   193,
      -1,   167,    -1,   180,    -1,   187,    -1,   172,    -1,   206,
      -1,   192,    -1,   161,    -1,   175,    -1,   179,    -1,   168,
      -1,    -1,    62,   311,   229,   312,   226,    -1,   312,   230,
     313,    -1,   313,    -1,    66,   231,   128,    -1,    66,    -1,
      18,   231,   128,    -1,    18,    -1,   148,   231,   128,    -1,
     148,    -1,    68,    -1,   218,    -1,   166,    -1,   202,    -1,
     225,    -1,    39,    -1,    25,    -1,   183,    -1,   127,    -1,
       4,    -1,   180,    -1,   171,    -1,   207,    -1,   175,    -1,
     129,    -1,   188,    -1,    94,    -1,    -1,    17,   315,   228,
     316,   227,   226,    -1,   316,   317,    -1,   317,    -1,   318,
      -1,   328,    -1,   329,    -1,   319,    -1,   330,    -1,   320,
      -1,   321,    -1,   322,    -1,   323,    -1,   324,    -1,   325,
      -1,   326,    -1,   327,    -1,   331,    -1,   332,    -1,   333,
      -1,     1,   226,    -1,    97,   229,   122,   226,    -1,   120,
     229,   236,   226,    -1,   109,   229,   107,   226,    -1,    19,
     229,   236,   226,    -1,    87,   229,   107,   226,    -1,    80,
     229,   107,   226,    -1,    83,   229,   107,   226,    -1,    81,
     229,   107,   226,    -1,   142,   229,   238,   226,    -1,   181,
     229,   238,   226,    -1,    15,   229,   107,   226,    -1,    16,
     229,   107,   226,    -1,   108,   229,   107,   226,    -1,    91,
     229,   236,   226,    -1,    82,   229,   236,   226,    -1,    -1,
      62,   334,   229,   335,   226,    -1,   335,   230,   336,    -1,
     336,    -1,   123,    -1,    50,    -1,    -1,    74,   338,   228,
     343,   227,   226,    -1,    -1,    62,   340,   229,   341,   226,
      -1,   341,   230,   342,    -1,   342,    -1,   194,    -1,    48,
      -1,   184,    -1,   343,   344,    -1,   344,    -1,   345,    -1,
     339,    -1,   349,    -1,   350,    -1,     1,   226,    -1,    -1,
     121,   229,   347,   346,   226,    -1,   347,   230,   348,    -1,
     348,    -1,   107,    -1,   107,   216,   107,    -1,    60,   229,
     122,   226,    -1,    55,   229,   122,   226,    -1,    -1,    61,
     352,   228,   353,   227,   226,    -1,   353,   354,    -1,   354,
      -1,   355,    -1,   356,    -1,   357,    -1,   359,    -1,   363,
      -1,   364,    -1,   365,    -1,   358,    -1,     1,   226,    -1,
     221,   229,   122,   226,    -1,   117,   229,   122,   226,    -1,
      17,   229,   122,   226,    -1,    32,   229,   209,   226,    -1,
      -1,    62,   360,   229,   361,   226,    -1,   361,   230,   362,
      -1,   362,    -1,   147,    -1,    33,    -1,    69,    -1,    98,
      -1,    13,    -1,   106,    -1,    42,    -1,   131,    -1,   208,
      -1,    99,    -1,   146,   229,   122,   226,    -1,   126,   229,
     122,   226,    -1,   125,   229,   107,   226,    -1,    -1,   130,
     367,   228,   368,   227,   226,    -1,   368,   369,    -1,   369,
      -1,   370,    -1,   371,    -1,   372,    -1,     1,   226,    -1,
      75,   229,   122,   226,    -1,   124,   229,   122,   226,    -1,
      34,   229,   122,   226,    -1,   185,   228,   374,   227,   226,
      -1,   374,   375,    -1,   375,    -1,   376,    -1,     1,    -1,
      97,   229,   122,   226,    -1,    -1,   189,   378,   228,   379,
     227,   226,    -1,   379,   380,    -1,   380,    -1,   381,    -1,
     382,    -1,   383,    -1,     1,   226,    -1,    97,   229,   122,
     226,    -1,   221,   229,   122,   226,    -1,    -1,   217,   384,
     229,   385,   226,    -1,   385,   230,   386,    -1,   386,    -1,
      68,    -1,   218,    -1,   166,    -1,   202,    -1,   225,    -1,
     205,    -1,   130,    -1,   204,    -1,   175,    -1,   159,    -1,
      -1,   163,   388,   228,   389,   227,   226,    -1,   389,   390,
      -1,   390,    -1,   391,    -1,   392,    -1,     1,   226,    -1,
      97,   229,   122,   226,    -1,    -1,   217,   393,   229,   394,
     226,    -1,   394,   230,   395,    -1,   395,    -1,    68,    -1,
     218,    -1,   166,    -1,   202,    -1,   225,    -1,   205,    -1,
     130,    -1,   204,    -1,   175,    -1,   159,    -1,    -1,    18,
     397,   228,   398,   227,   226,    -1,   398,   399,    -1,   399,
      -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,
      -1,   405,    -1,   407,    -1,   406,    -1,   416,    -1,   408,
      -1,   413,    -1,   414,    -1,   415,    -1,   412,    -1,     1,
     226,    -1,    97,   229,   122,   226,    -1,    55,   229,   122,
     226,    -1,   222,   229,   122,   226,    -1,   141,   229,   122,
     226,    -1,     3,   229,   122,   226,    -1,   150,   229,   122,
     226,    -1,   121,   229,   107,   226,    -1,     5,   229,   173,
     226,    -1,     5,   229,   174,   226,    -1,    -1,    62,   409,
     229,   410,   226,    -1,   410,   230,   411,    -1,   411,    -1,
       8,    -1,   194,    -1,    32,   229,   209,   226,    -1,    57,
     229,   122,   226,    -1,    72,   229,   122,   226,    -1,    17,
     229,   122,   226,    -1,   195,   229,   122,   226,    -1,    -1,
      66,   418,   228,   419,   227,   226,    -1,   419,   420,    -1,
     420,    -1,   421,    -1,   422,    -1,     1,    -1,   221,   229,
     122,   226,    -1,   124,   229,   122,   226,    -1,    -1,    23,
     424,   228,   425,   227,   226,    -1,   425,   426,    -1,   426,
      -1,   427,    -1,   428,    -1,     1,    -1,    60,   229,   122,
     226,    -1,   124,   229,   122,   226,    -1,    34,   228,   430,
     227,   226,    -1,   430,   431,    -1,   431,    -1,   432,    -1,
       1,    -1,    60,   229,   122,   226,    -1,    -1,    37,   434,
     228,   435,   227,   226,    -1,   435,   436,    -1,   436,    -1,
     437,    -1,   438,    -1,     1,    -1,    97,   229,   122,   226,
      -1,   124,   229,   122,   226,    -1,    38,   228,   440,   227,
     226,    -1,   440,   441,    -1,   441,    -1,   450,    -1,   451,
      -1,   452,    -1,   453,    -1,   454,    -1,   455,    -1,   456,
      -1,   457,    -1,   458,    -1,   459,    -1,   449,    -1,   461,
      -1,   462,    -1,   477,    -1,   464,    -1,   467,    -1,   469,
      -1,   468,    -1,   472,    -1,   465,    -1,   466,    -1,   473,
      -1,   474,    -1,   475,    -1,   476,    -1,   489,    -1,   478,
      -1,   479,    -1,   480,    -1,   485,    -1,   470,    -1,   471,
      -1,   495,    -1,   493,    -1,   494,    -1,   484,    -1,   460,
      -1,   482,    -1,   483,    -1,   448,    -1,   443,    -1,   444,
      -1,   445,    -1,   446,    -1,   447,    -1,   463,    -1,   442,
      -1,   481,    -1,     1,    -1,    90,   229,   107,   226,    -1,
      41,   229,   209,   226,    -1,    40,   229,   236,   226,    -1,
      45,   229,   236,   226,    -1,    43,   229,   107,   226,    -1,
      44,   229,   107,   226,    -1,   211,   229,   209,   226,    -1,
      67,   229,   236,   226,    -1,    54,   229,   209,   226,    -1,
      58,   229,   209,   226,    -1,    35,   229,   209,   226,    -1,
       6,   229,   209,   226,    -1,    86,   229,   236,   226,    -1,
      84,   229,   107,   226,    -1,    76,   229,   107,   226,    -1,
       7,   229,   236,   226,    -1,   215,   229,   236,   226,    -1,
     214,   229,   236,   226,    -1,    47,   229,   107,   226,    -1,
      59,   229,   209,   226,    -1,   224,   229,   209,   226,    -1,
     153,   229,   209,   226,    -1,   156,   229,   209,   226,    -1,
     157,   229,   209,   226,    -1,   158,   229,   209,   226,    -1,
     155,   229,   209,   226,    -1,   155,   229,   212,   226,    -1,
     154,   229,   209,   226,    -1,   154,   229,   212,   226,    -1,
     115,   229,   236,   226,    -1,    12,   229,   236,   226,    -1,
     114,   229,   209,   226,    -1,   116,   229,   236,   226,    -1,
     145,   229,   209,   226,    -1,   105,   229,   209,   226,    -1,
     213,   229,   209,   226,    -1,   111,   229,   209,   226,    -1,
      29,   229,   107,   226,    -1,    88,   229,   107,   226,    -1,
     219,   229,   209,   226,    -1,    30,   229,   122,   226,    -1,
     186,   229,   122,   226,    -1,   119,   229,   209,   226,    -1,
      26,   229,   209,   226,    -1,   210,   229,   236,   226,    -1,
      -1,   112,   486,   229,   487,   226,    -1,   487,   230,   488,
      -1,   488,    -1,   160,    -1,   162,    -1,   164,    -1,   165,
      -1,   170,    -1,    48,    -1,   191,    -1,   178,    -1,   182,
      -1,   201,    -1,   193,    -1,   167,    -1,   180,    -1,   187,
      -1,   172,    -1,   206,    -1,   192,    -1,   161,    -1,   175,
      -1,   179,    -1,   168,    -1,    -1,   110,   490,   229,   491,
     226,    -1,   491,   230,   492,    -1,   492,    -1,   160,    -1,
     162,    -1,   164,    -1,   165,    -1,   170,    -1,   191,    -1,
      48,    -1,   178,    -1,   182,    -1,   201,    -1,   193,    -1,
     167,    -1,   180,    -1,   187,    -1,   172,    -1,   206,    -1,
     192,    -1,   161,    -1,   175,    -1,   179,    -1,   168,    -1,
      92,   229,   107,   226,    -1,    93,   229,   107,   226,    -1,
      20,   229,   107,   226,    -1,    14,   228,   497,   227,   226,
      -1,   497,   498,    -1,   498,    -1,   504,    -1,   500,    -1,
     501,    -1,   502,    -1,   503,    -1,   505,    -1,   506,    -1,
     507,    -1,   508,    -1,   509,    -1,   510,    -1,   499,    -1,
       1,    -1,    27,   229,   209,   226,    -1,    70,   229,   236,
     226,    -1,    71,   229,   236,   226,    -1,    79,   229,   107,
     226,    -1,    78,   229,   107,   226,    -1,    77,   229,   107,
     226,    -1,    22,   229,   107,   226,    -1,    21,   229,   107,
     226,    -1,   103,   229,   209,   226,    -1,   104,   229,   209,
     226,    -1,    64,   229,   107,   226,    -1,    65,   229,   236,
     226,    -1,   143,   228,   512,   227,   226,    -1,   512,   513,
      -1,   513,    -1,   514,    -1,   515,    -1,   516,    -1,   517,
      -1,   519,    -1,   520,    -1,   518,    -1,   521,    -1,     1,
      -1,    36,   229,   209,   226,    -1,    28,   229,   209,   226,
      -1,    52,   229,   209,   226,    -1,    53,   229,   209,   226,
      -1,    49,   229,   122,   226,    -1,    73,   229,   236,   226,
      -1,    48,   229,   209,   226,    -1,    51,   229,   209,   226,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   369,   369,   370,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   399,   399,   400,
     404,   408,   412,   416,   420,   424,   428,   434,   434,   435,
     436,   437,   438,   445,   448,   448,   449,   449,   449,   451,
     457,   464,   466,   466,   467,   467,   468,   468,   469,   469,
     470,   470,   471,   471,   472,   472,   473,   473,   474,   474,
     475,   476,   479,   480,   482,   482,   483,   489,   497,   497,
     498,   504,   512,   554,   613,   641,   649,   664,   679,   688,
     702,   711,   739,   769,   794,   816,   838,   847,   849,   849,
     850,   850,   851,   851,   853,   862,   871,   884,   883,   901,
     901,   902,   902,   902,   904,   910,   919,   920,   920,   922,
     922,   923,   925,   932,   932,   945,   946,   948,   948,   949,
     949,   951,   959,   962,   968,   967,   973,   973,   974,   978,
     982,   986,   990,   994,   998,  1009,  1008,  1088,  1088,  1089,
    1089,  1089,  1090,  1090,  1090,  1091,  1091,  1092,  1093,  1093,
    1095,  1101,  1107,  1113,  1124,  1130,  1136,  1147,  1154,  1153,
    1159,  1159,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1196,  1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,
    1232,  1236,  1240,  1247,  1246,  1252,  1252,  1253,  1257,  1261,
    1265,  1269,  1273,  1277,  1281,  1285,  1289,  1293,  1297,  1301,
    1305,  1309,  1313,  1317,  1321,  1325,  1329,  1333,  1337,  1341,
    1352,  1351,  1412,  1412,  1413,  1414,  1414,  1415,  1416,  1417,
    1418,  1419,  1420,  1421,  1422,  1423,  1423,  1424,  1425,  1426,
    1427,  1429,  1435,  1441,  1447,  1453,  1459,  1465,  1471,  1477,
    1483,  1490,  1496,  1502,  1508,  1517,  1527,  1526,  1532,  1532,
    1533,  1537,  1548,  1547,  1554,  1553,  1558,  1558,  1559,  1563,
    1567,  1573,  1573,  1574,  1574,  1574,  1574,  1574,  1576,  1576,
    1578,  1578,  1580,  1594,  1614,  1620,  1630,  1629,  1671,  1671,
    1672,  1672,  1672,  1672,  1673,  1673,  1673,  1674,  1674,  1676,
    1682,  1688,  1694,  1706,  1705,  1711,  1711,  1712,  1716,  1720,
    1724,  1728,  1732,  1736,  1740,  1744,  1748,  1754,  1768,  1777,
    1791,  1790,  1805,  1805,  1806,  1806,  1806,  1806,  1808,  1814,
    1820,  1830,  1832,  1832,  1833,  1833,  1835,  1851,  1850,  1875,
    1875,  1876,  1876,  1876,  1876,  1878,  1884,  1904,  1903,  1909,
    1909,  1910,  1914,  1918,  1922,  1926,  1930,  1934,  1938,  1942,
    1946,  1956,  1955,  1976,  1976,  1977,  1977,  1977,  1979,  1986,
    1985,  1991,  1991,  1992,  1996,  2000,  2004,  2008,  2012,  2016,
    2020,  2024,  2028,  2038,  2037,  2108,  2108,  2109,  2109,  2109,
    2110,  2110,  2111,  2112,  2112,  2112,  2113,  2113,  2113,  2114,
    2114,  2115,  2117,  2123,  2129,  2135,  2148,  2161,  2167,  2173,
    2177,  2186,  2185,  2190,  2190,  2191,  2195,  2201,  2212,  2218,
    2224,  2230,  2246,  2245,  2271,  2271,  2272,  2272,  2272,  2274,
    2294,  2304,  2303,  2330,  2330,  2331,  2331,  2331,  2333,  2339,
    2348,  2350,  2350,  2351,  2351,  2353,  2371,  2370,  2393,  2393,
    2394,  2394,  2394,  2396,  2402,  2411,  2414,  2414,  2415,  2415,
    2416,  2416,  2417,  2417,  2418,  2418,  2419,  2419,  2420,  2421,
    2422,  2422,  2423,  2423,  2424,  2424,  2425,  2425,  2426,  2427,
    2427,  2428,  2428,  2429,  2429,  2430,  2430,  2431,  2431,  2432,
    2432,  2433,  2433,  2434,  2434,  2435,  2436,  2437,  2437,  2438,
    2438,  2439,  2440,  2441,  2442,  2442,  2443,  2446,  2451,  2457,
    2463,  2469,  2474,  2479,  2484,  2489,  2494,  2499,  2504,  2509,
    2514,  2519,  2524,  2529,  2534,  2540,  2551,  2556,  2561,  2566,
    2571,  2576,  2581,  2584,  2589,  2592,  2597,  2602,  2607,  2612,
    2617,  2622,  2627,  2632,  2637,  2642,  2647,  2652,  2661,  2670,
    2675,  2680,  2686,  2685,  2690,  2690,  2691,  2694,  2697,  2700,
    2703,  2706,  2709,  2712,  2715,  2718,  2721,  2724,  2727,  2730,
    2733,  2736,  2739,  2742,  2745,  2748,  2751,  2757,  2756,  2761,
    2761,  2762,  2765,  2768,  2771,  2774,  2777,  2780,  2783,  2786,
    2789,  2792,  2795,  2798,  2801,  2804,  2807,  2810,  2813,  2816,
    2819,  2822,  2827,  2832,  2837,  2846,  2849,  2849,  2850,  2851,
    2851,  2852,  2852,  2853,  2854,  2855,  2856,  2857,  2857,  2858,
    2858,  2860,  2865,  2870,  2875,  2880,  2885,  2890,  2895,  2900,
    2905,  2910,  2915,  2923,  2926,  2926,  2927,  2927,  2928,  2929,
    2930,  2931,  2931,  2932,  2933,  2935,  2941,  2947,  2953,  2959,
    2968,  2982,  2988
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
  "general_stats_P_oper_only", "general_stats_u_oper_only",
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
     475,   476,   477,   478,   479,   480,    59,   125,   123,    61,
      44,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   232,   233,   233,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   235,   236,
     236,   236,   236,   236,   236,   236,   236,   237,   237,   238,
     238,   238,   238,   239,   240,   240,   241,   241,   241,   242,
     243,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   247,   248,   249,   249,   250,   250,   251,   251,
     252,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   269,
     270,   270,   270,   270,   271,   272,   273,   275,   274,   276,
     276,   277,   277,   277,   278,   279,   280,   281,   281,   282,
     282,   282,   283,   285,   284,   286,   286,   287,   287,   287,
     287,   288,   289,   289,   291,   290,   292,   292,   293,   293,
     293,   293,   293,   293,   293,   295,   294,   296,   296,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   307,   306,
     308,   308,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   309,   309,   309,   309,   309,   309,
     309,   309,   309,   311,   310,   312,   312,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     315,   314,   316,   316,   317,   317,   317,   317,   317,   317,
     317,   317,   317,   317,   317,   317,   317,   317,   317,   317,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   334,   333,   335,   335,
     336,   336,   338,   337,   340,   339,   341,   341,   342,   342,
     342,   343,   343,   344,   344,   344,   344,   344,   346,   345,
     347,   347,   348,   348,   349,   350,   352,   351,   353,   353,
     354,   354,   354,   354,   354,   354,   354,   354,   354,   355,
     356,   357,   358,   360,   359,   361,   361,   362,   362,   362,
     362,   362,   362,   362,   362,   362,   362,   363,   364,   365,
     367,   366,   368,   368,   369,   369,   369,   369,   370,   371,
     372,   373,   374,   374,   375,   375,   376,   378,   377,   379,
     379,   380,   380,   380,   380,   381,   382,   384,   383,   385,
     385,   386,   386,   386,   386,   386,   386,   386,   386,   386,
     386,   388,   387,   389,   389,   390,   390,   390,   391,   393,
     392,   394,   394,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   397,   396,   398,   398,   399,   399,   399,
     399,   399,   399,   399,   399,   399,   399,   399,   399,   399,
     399,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     407,   409,   408,   410,   410,   411,   411,   412,   413,   414,
     415,   416,   418,   417,   419,   419,   420,   420,   420,   421,
     422,   424,   423,   425,   425,   426,   426,   426,   427,   428,
     429,   430,   430,   431,   431,   432,   434,   433,   435,   435,
     436,   436,   436,   437,   438,   439,   440,   440,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   441,   441,   441,
     441,   441,   441,   441,   441,   441,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   467,   468,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   486,   485,   487,   487,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   490,   489,   491,
     491,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   493,   494,   495,   496,   497,   497,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   512,   513,   513,   513,   513,
     513,   513,   513,   513,   513,   514,   515,   516,   517,   518,
     519,   520,   521
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4
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
       0,     0,     0,     0,     0,    99,   100,   102,   101,   620,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   607,   619,   609,   610,   611,   612,   608,
     613,   614,   615,   616,   617,   618,     0,     0,     0,   444,
       0,     0,   442,   443,     0,   506,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   577,     0,   552,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   457,   504,   498,   499,   500,
     501,   502,   497,   468,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   494,   469,   470,   503,   472,   477,
     478,   473,   475,   474,   488,   489,   476,   479,   480,   481,
     482,   471,   484,   485,   486,   505,   495,   496,   493,   487,
     483,   491,   492,   490,     0,     0,     0,     0,     0,     0,
       0,    45,    46,    47,     0,     0,     0,   644,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   635,   636,   637,
     638,   639,   642,   640,   641,   643,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    53,    68,    69,    67,    64,
      63,    70,    54,    66,    57,    58,    59,    55,    65,    60,
      61,    62,    56,     0,     0,     0,     0,   118,   119,   120,
       0,   335,     0,     0,   333,   334,     0,   103,     0,     0,
       0,     0,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   606,     0,     0,     0,
       0,   256,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   227,   229,   230,
     231,   232,   233,   234,   235,   236,   225,   226,   228,   237,
     238,   239,     0,     0,     0,     0,     0,     0,     0,   411,
       0,     0,     0,     0,     0,     0,     0,     0,   386,   387,
     388,   389,   390,   391,   392,   394,   393,   396,   400,   397,
     398,   399,   395,   437,     0,     0,     0,   434,   435,   436,
       0,     0,   441,   452,     0,     0,     0,   449,   450,   451,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   456,
       0,     0,     0,   303,     0,     0,     0,     0,     0,     0,
     289,   290,   291,   292,   297,   293,   294,   295,   296,   428,
       0,     0,     0,   425,   426,   427,     0,     0,     0,   264,
       0,   274,     0,   272,   273,   275,   276,    48,     0,     0,
       0,    44,     0,     0,     0,     0,   110,   111,   112,     0,
       0,     0,   193,     0,     0,     0,     0,     0,   168,     0,
       0,   148,   149,   150,   151,   154,   155,   156,   157,   153,
     152,   158,     0,     0,     0,     0,     0,   323,   324,   325,
     326,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     634,    71,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,     0,     0,   369,     0,   364,   365,   366,   121,     0,
       0,   117,     0,     0,     0,   332,     0,     0,   347,     0,
       0,   340,   341,   342,   343,     0,     0,     0,    97,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,   605,   240,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   222,   401,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,   433,     0,   440,     0,     0,     0,   448,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   455,
     298,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     288,     0,     0,     0,   424,   277,     0,     0,     0,     0,
       0,   271,     0,     0,    43,   113,     0,     0,     0,   109,
     159,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,   327,     0,     0,     0,     0,   322,     0,
       0,     0,     0,     0,     0,     0,     0,   633,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    76,    77,     0,    75,    80,    81,     0,    79,     0,
       0,    51,   367,     0,     0,     0,   363,     0,   116,     0,
       0,   331,   344,     0,     0,     0,     0,   339,   106,   105,
     104,   628,   627,   621,   631,    27,    27,    27,    27,    27,
      27,    27,    29,    28,   632,   622,   623,   626,   625,   624,
     629,   630,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,   221,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   384,     0,     0,   432,   445,
       0,     0,   447,   518,   522,   537,   604,   550,   544,   547,
     517,   509,   508,   511,   512,   510,   525,   515,   516,   526,
     514,   521,   520,   519,   545,   507,   602,   603,   541,   587,
     581,   598,   582,   583,   584,   592,   601,   585,   595,   599,
     588,   600,   593,   589,   594,   586,   597,   591,   590,   596,
       0,   580,   543,   561,   556,   573,   557,   558,   559,   567,
     576,   560,   570,   574,   563,   575,   568,   564,   569,   562,
     572,   566,   565,   571,     0,   555,   538,   536,   539,   549,
     540,   528,   534,   535,   532,   533,   529,   530,   531,   548,
     551,   513,   542,   524,   523,   546,   527,     0,     0,     0,
       0,     0,     0,     0,     0,   287,     0,     0,   423,     0,
       0,     0,   282,   278,   281,   263,    49,    50,     0,     0,
     108,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   146,     0,     0,     0,   321,   646,   645,   651,   649,
     652,   647,   648,   650,    88,    96,    87,    94,    95,    86,
      90,    89,    83,    82,    84,    93,    85,    72,     0,    73,
       0,    91,    92,     0,     0,   362,   122,     0,     0,     0,
     134,     0,   126,   127,   129,   128,   336,     0,     0,     0,
     338,    30,    31,    32,    33,    34,    35,    36,   251,   252,
     244,   261,   260,     0,   259,   246,   248,   255,   247,   245,
     254,   241,   253,   243,   242,    37,    37,    37,    39,    38,
     249,   250,   406,   409,   410,   420,   417,   403,   418,   415,
     416,     0,   414,   419,   402,   408,   405,   407,   421,   404,
     438,   439,   453,   454,   578,     0,   553,     0,   301,   302,
     311,   308,   313,   309,   310,   316,   312,   314,   307,   315,
       0,   306,   300,   319,   318,   317,   299,   430,   429,   285,
     284,   269,   270,   268,     0,   267,     0,     0,     0,   114,
     115,   167,   163,   212,   200,   209,   208,   198,   203,   219,
     211,   217,   202,   205,   214,   216,   213,   210,   218,   206,
     215,   204,   207,     0,   196,   160,   162,   164,   165,   166,
     177,   172,   189,   173,   174,   175,   183,   192,   176,   186,
     190,   179,   191,   184,   180,   185,   178,   188,   182,   181,
     187,     0,   171,   161,   330,   328,   329,    74,    78,   368,
     373,   379,   382,   375,   381,   376,   380,   378,   374,   377,
       0,   372,   130,     0,     0,     0,     0,   125,   345,   351,
     357,   360,   353,   359,   354,   358,   356,   352,   355,     0,
     350,   346,   257,     0,    40,    41,    42,   412,     0,   579,
     554,   304,     0,   265,     0,   283,   280,   279,     0,     0,
       0,   194,     0,   169,     0,   370,     0,     0,     0,     0,
       0,   124,   348,     0,   258,   413,   305,   266,   199,   197,
     201,   195,   170,   371,   131,   133,   132,   140,   143,   142,
     139,   144,   141,   138,     0,   137,   349,   135,     0,   136
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   812,   813,  1068,  1069,    26,   220,   221,
     222,   223,    27,   264,   265,   266,   267,   773,   774,   777,
     778,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,    28,    74,    75,    76,
      77,    78,    29,    61,   495,   496,   497,   498,    30,   286,
     287,   288,   289,   290,  1031,  1032,  1033,  1034,  1035,  1205,
    1274,  1275,    31,    62,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   739,  1181,  1182,   521,   733,
    1153,  1154,    32,    51,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   607,  1053,  1054,    33,    59,   481,   718,  1124,
    1125,   482,   483,   484,  1128,   973,   974,   485,   486,    34,
      57,   459,   460,   461,   462,   463,   464,   465,   703,  1110,
    1111,   466,   467,   468,    35,    63,   526,   527,   528,   529,
     530,    36,   293,   294,   295,    37,    69,   580,   581,   582,
     583,   584,   794,  1219,  1220,    38,    66,   564,   565,   566,
     567,   784,  1200,  1201,    39,    52,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,   377,   629,  1081,  1082,
     378,   379,   380,   381,   382,    40,    58,   472,   473,   474,
     475,    41,    53,   386,   387,   388,   389,    42,   111,   112,
     113,    43,    55,   396,   397,   398,   399,    44,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   428,   934,   935,   210,   426,   910,
     911,   211,   212,   213,    45,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,    46,
     236,   237,   238,   239,   240,   241,   242,   243,   244,   245
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -894
static const yytype_int16 yypact[] =
{
    -894,   632,  -894,   -96,  -213,  -207,  -894,  -894,  -894,  -198,
    -894,  -184,  -894,  -894,  -894,  -174,  -894,  -894,  -894,  -130,
    -124,  -894,  -122,  -105,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,   275,
     874,   -91,   -82,   -74,    42,   -47,   344,   -22,   -12,    -9,
      91,     2,    28,    46,   651,   418,    56,    38,    80,    76,
      70,    61,    81,    84,    17,  -894,  -894,  -894,  -894,  -894,
     103,   105,   119,   123,   124,   125,   126,   128,   129,   130,
     131,   132,     7,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,   629,   479,    73,  -894,
     133,    16,  -894,  -894,    54,  -894,   136,   138,   139,   140,
     142,   151,   163,   164,   165,   167,   168,   170,   171,   172,
     176,   178,   181,   183,   185,   187,   188,   193,   195,   198,
     200,   202,  -894,   204,  -894,   206,   209,   212,   214,   215,
     216,   217,   218,   221,   223,   224,   228,   232,   233,   236,
     240,   241,   242,   244,   112,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,   447,    39,   254,    98,   248,   249,
      66,  -894,  -894,  -894,    92,   389,   179,  -894,   256,   258,
     259,   261,   262,   263,   264,   266,     9,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,   115,   276,   279,   281,
     283,   285,   287,   288,   291,   292,   294,   295,   296,   297,
     303,   306,   308,   309,   186,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,    12,   117,   314,    68,  -894,  -894,  -894,
     111,  -894,   315,    11,  -894,  -894,     4,  -894,   199,   255,
     293,   257,  -894,   397,   438,   337,   440,   442,   442,   442,
     445,   446,   449,   351,   352,   336,  -894,   339,   345,   348,
     349,  -894,   350,   353,   355,   356,   358,   362,   363,   365,
     367,   368,   372,   374,     8,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,   378,   376,   379,   380,   382,   383,   387,  -894,
     388,   392,   393,   394,   395,   398,   399,   245,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,   408,   409,    62,  -894,  -894,  -894,
     459,   413,  -894,  -894,   414,   422,    51,  -894,  -894,  -894,
     433,   442,   442,   546,   448,   547,   534,   450,   442,   451,
     551,   554,   442,   556,   458,   462,   463,   442,   566,   568,
     442,   569,   570,   573,   574,   473,   454,   475,   457,   480,
     442,   442,   481,   483,   485,  -153,   -19,   486,   487,   488,
     585,   442,   505,   506,   442,   442,   508,   509,   493,  -894,
     495,   494,   496,  -894,   507,   510,   511,   512,   513,    18,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
     514,   515,    52,  -894,  -894,  -894,   526,   528,   530,  -894,
     540,  -894,    13,  -894,  -894,  -894,  -894,  -894,   600,   633,
     537,  -894,   544,   543,   545,    25,  -894,  -894,  -894,   555,
     553,   557,  -894,   559,   560,   561,   562,   564,  -894,   565,
      32,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,   558,   571,   572,   575,    45,  -894,  -894,  -894,
    -894,   576,   588,   589,   658,   590,   593,   596,   442,   580,
    -894,  -894,   661,   598,   687,   581,   704,   691,   692,   693,
     694,   696,   697,   713,   700,   121,   148,   701,   702,   602,
    -894,   605,   607,  -894,    65,  -894,  -894,  -894,  -894,   625,
     612,  -894,   618,   726,   623,  -894,   624,   622,  -894,   630,
      64,  -894,  -894,  -894,  -894,   627,   628,   634,  -894,   635,
     638,   639,   641,   786,   642,   643,   644,   652,   655,   657,
     659,   660,  -894,  -894,   756,   781,   442,   668,   782,   791,
     442,   793,   795,   442,   784,   800,   801,   442,   802,   802,
     684,  -894,  -894,   789,    90,   790,   705,   794,   797,   686,
     805,   806,   810,   807,   808,   809,   811,   706,  -894,   812,
     813,   710,  -894,   711,  -894,   818,   819,   716,  -894,   717,
     720,   721,   722,   723,   724,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   742,
     743,   744,   745,   746,   747,   586,   748,   665,   749,   750,
     753,   754,   755,   757,   758,   759,   760,   761,   762,   763,
     764,   765,   766,   767,   768,   769,   770,   771,   772,  -894,
    -894,   860,   792,   773,   877,   893,   881,   882,   883,   780,
    -894,   885,   886,   783,  -894,  -894,   888,   889,   785,   905,
     787,  -894,   796,   798,  -894,  -894,   894,   895,   799,  -894,
    -894,   896,   814,   803,   897,   898,   899,   904,   820,   804,
     906,   815,  -894,  -894,   908,   909,   912,   816,  -894,   817,
     821,   822,   823,   824,   825,   826,   827,  -894,   828,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,  -894,  -894,  -219,  -894,  -894,  -894,  -210,  -894,   841,
     842,  -894,  -894,   913,   843,   844,  -894,   845,  -894,    30,
     847,  -894,  -894,   914,   846,   915,   848,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,   442,   442,   442,   442,   442,
     442,   442,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,   850,   851,   852,    95,   853,   854,   855,   856,
     857,   858,   859,   861,   862,   863,   319,   864,   865,  -894,
     866,   867,   868,   869,   870,   871,   872,    -2,   873,   875,
     876,   878,   879,   880,   884,  -894,   887,   890,  -894,  -894,
     891,   892,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -194,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -188,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,   900,   901,   500,
     902,   903,   907,   910,   911,  -894,   916,   917,  -894,   918,
     919,   -26,    78,   920,  -894,  -894,  -894,  -894,   921,   922,
    -894,   923,   925,   400,   926,   927,   928,   929,   930,   712,
     931,  -894,   932,   933,   934,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,   121,  -894,
     148,  -894,  -894,   935,   460,  -894,  -894,   936,   937,   938,
    -894,    24,  -894,  -894,  -894,  -894,  -894,   939,   637,   942,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -179,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,   802,   802,   802,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -143,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,   586,  -894,   665,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
     -35,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,   -27,  -894,   962,   905,   943,  -894,
    -894,  -894,  -894,  -894,   940,  -894,  -894,   941,  -894,  -894,
    -894,  -894,   944,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,   -18,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,   -15,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
      85,  -894,  -894,   924,    94,   945,   947,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,   107,
    -894,  -894,  -894,    95,  -894,  -894,  -894,  -894,    -2,  -894,
    -894,  -894,   500,  -894,   -26,  -894,  -894,  -894,   958,   972,
     975,  -894,   400,  -894,   712,  -894,   460,   950,   951,   952,
     310,  -894,  -894,   637,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,   114,  -894,  -894,  -894,   310,  -894
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -894,  -894,  -894,   -76,  -305,  -893,  -618,  -894,  -894,   959,
    -894,  -894,  -894,  -894,   751,  -894,  -894,  -894,    20,  -894,
      19,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,   953,  -894,
    -894,  -894,  -894,  -894,  -894,   549,  -894,  -894,  -894,  -894,
     849,  -894,  -894,  -894,  -894,    14,  -894,  -894,  -894,  -894,
    -894,  -238,  -894,  -894,  -894,   597,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -136,  -894,  -894,
    -894,  -133,  -894,  -894,  -894,   777,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -111,  -894,  -894,  -894,  -894,  -894,
    -120,  -894,   640,  -894,  -894,  -894,    -8,  -894,  -894,  -894,
    -894,  -894,   656,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -112,  -894,  -894,  -894,  -894,  -894,  -894,   595,  -894,  -894,
    -894,  -894,  -894,   946,  -894,  -894,  -894,  -894,   550,  -894,
    -894,  -894,  -894,  -894,  -129,  -894,  -894,  -894,   567,  -894,
    -894,  -894,  -894,  -123,  -894,  -894,  -894,   774,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -103,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,   662,  -894,
    -894,  -894,  -894,  -894,   752,  -894,  -894,  -894,  -894,  1021,
    -894,  -894,  -894,  -894,   788,  -894,  -894,  -894,  -894,   976,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,    49,  -894,  -894,  -894,
      44,  -894,  -894,  -894,  -894,  -894,  1071,  -894,  -894,  -894,
    -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894,
    -894,   949,  -894,  -894,  -894,  -894,  -894,  -894,  -894,  -894
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -124
static const yytype_int16 yytable[] =
{
     837,   838,   594,   595,   596,   576,  1079,  1017,    79,   317,
     227,  1018,   291,   561,   476,    49,  1019,   109,    70,   450,
    1020,    50,  1121,   318,   319,  1027,   492,   320,    80,    81,
      54,  1027,  1094,   499,    82,   451,  1095,   228,  1096,   284,
     469,    71,  1097,   109,    56,   229,   522,  1222,    72,   500,
     452,  1223,   393,   469,    60,   393,   684,   230,   231,   685,
     232,   233,   234,   383,   501,   576,   561,   217,   477,   284,
     321,    83,    84,   478,   383,   479,   110,    85,    86,   523,
     453,   291,   235,  1227,    87,    88,    89,  1228,   322,   323,
     324,   325,   217,   492,   502,   326,   650,   651,    64,   327,
     493,   577,   110,   657,    65,   328,    67,   661,   292,   562,
      90,    91,   666,   115,    73,   669,   329,   330,   116,   117,
     524,  1028,   384,    68,   118,   679,   680,  1028,   331,   503,
      47,    48,   119,   384,   480,   454,   692,   106,   120,   695,
     696,   121,   122,   455,   456,  1051,   107,   123,   394,   504,
     332,   394,   124,   125,   108,   126,   127,   128,  1122,   129,
     218,   577,   562,   470,   457,   505,   130,   493,  1123,   525,
     131,   132,  1224,  1225,  1226,   395,   470,   292,   395,   133,
     522,   114,   506,   507,   219,   218,   385,   246,   134,   333,
     686,  1231,  1080,   687,   494,  1232,   135,   385,   136,  1233,
     137,   836,   138,  1234,   139,   140,   214,  -123,  1241,   219,
     247,  1243,  1242,   523,  1029,  1244,   215,   141,  1052,   216,
    1029,   578,   142,   143,   144,   579,   145,   146,   147,   563,
     224,   148,   508,   756,   315,   620,   539,  -123,   574,   458,
     720,  1030,   248,   391,   301,   709,   352,  1030,   353,   249,
     354,  1206,   728,   509,   524,   476,   225,   149,   285,   741,
     471,   494,   355,   841,   842,   150,   151,   152,   153,   154,
     155,   250,   747,   471,   226,   251,    70,   356,   647,   713,
     572,   578,   563,   252,   283,   579,   253,   254,   285,   641,
     298,   796,   785,   490,  1126,   570,   297,  1248,   156,    71,
     357,   824,   358,   525,   296,   828,    72,   359,   831,   477,
     299,  1245,   835,   300,   478,  1246,   479,   360,   255,   771,
     772,   585,   157,   158,   487,   159,   160,   161,  1065,  1066,
    1067,   162,   303,  1252,   304,   256,   163,  1253,   257,   448,
    1277,   541,   361,   568,  1278,   115,   775,   776,   305,  1267,
     116,   117,   306,   307,   308,   309,   118,   310,   311,   312,
     313,   314,   390,   258,   119,   400,   362,   401,   402,   403,
     120,   404,    73,   121,   122,   480,  1268,   586,  1269,   123,
     405,   259,   260,   261,   124,   125,   363,   126,   127,   128,
     499,   129,   406,   407,   408,   364,   409,   410,   130,   411,
     412,   413,   131,   132,  1133,   414,   500,   415,   262,   263,
     416,   133,   417,   559,   418,   587,   419,   420,  1134,   246,
     134,   501,   421,  1270,   422,  1135,   836,   423,   135,   424,
     136,   425,   137,   427,   138,   429,   139,   140,   430,  1136,
     365,   431,   247,   432,   433,   434,   435,   436,   450,   141,
     437,   502,   438,   439,   142,   143,   144,   440,   145,   146,
     147,   441,   442,   148,   451,   443,  1137,   366,  1138,   444,
     445,   446,   637,   447,   248,  1271,  1272,   488,   489,   452,
     352,   249,   353,   588,   354,   531,   503,   532,   533,   149,
     534,   535,   536,   537,  1139,   538,   355,   150,   151,   152,
     153,   154,   155,   250,   589,   542,   504,   251,   543,   453,
     544,   356,   545,  1100,   546,   252,   547,   548,   253,   254,
     549,   550,   505,   551,   552,   553,   554,  1140,  1190,  1141,
     156,  1273,   555,  1101,   357,   556,   358,   557,   558,   506,
     507,   359,  1102,   569,   573,   590,   591,   592,  1142,   593,
     255,   360,   597,   598,   157,   158,   599,   159,   160,   161,
     600,   601,   602,   162,   454,   603,  1143,   256,   163,  1103,
     257,  1144,   455,   456,   604,  1145,   361,   605,   606,   608,
    1146,   643,   609,  1147,   610,   611,  1249,   612,  1148,   508,
    1191,   613,   614,   457,   615,   258,   616,   617,  1104,  1105,
     362,   618,  1149,   619,   622,   623,  1106,  1150,   624,   625,
     509,   626,   627,   259,   260,   261,   628,   630,  1151,  1192,
     363,   631,   632,   633,   634,  1152,  1193,   635,   636,   364,
     317,  1107,     2,     3,   889,  1194,     4,   639,   640,   644,
     262,   263,   649,   645,   318,   319,     5,  1108,   320,     6,
       7,   646,   227,   652,   654,     8,   655,   653,   659,   656,
     658,   660,  1195,   662,  1196,  1197,     9,   663,   458,    10,
      11,   664,   665,   667,   365,   668,   670,   671,  1198,   228,
     672,   673,   674,   675,   676,  1199,   677,   229,   761,   678,
     681,   321,   682,    12,   683,   688,   689,   690,    13,   230,
     231,   366,   232,   233,   234,  1209,    14,   691,  1109,   322,
     323,   324,   325,   913,   693,   694,   326,   697,   698,   699,
     327,   700,   722,   701,   235,   702,   328,    15,    16,  1041,
    1042,  1043,  1044,  1045,  1046,  1047,   704,   329,   330,   705,
     706,   707,   708,   711,   712,    17,   890,   891,   892,   331,
     893,   894,   715,   895,   896,   723,   897,   716,   898,   717,
    1160,   899,    18,   724,   900,   901,   902,  1210,   903,   719,
     725,   332,   726,   904,   727,    19,    20,   905,   906,   907,
     752,   730,   731,   758,   743,   749,   732,   908,   734,   735,
     736,   737,   909,   738,   740,    21,  1211,   750,   751,   753,
     744,   745,   754,  1212,   746,   755,   757,   759,    22,   760,
     333,   762,  1213,   763,   764,   765,   766,    23,   767,   768,
     769,    24,   770,   779,   780,   914,   915,   916,   781,   917,
     918,   782,   919,   920,   787,   921,   783,   922,   788,  1214,
     923,  1215,  1216,   924,   925,   926,   789,   927,   790,   791,
     792,   793,   928,   798,   799,  1217,   929,   930,   931,   795,
     800,   801,  1218,   822,   802,   803,   932,   804,   814,   815,
     816,   933,  1161,  1162,  1163,    79,  1164,  1165,   817,  1166,
    1167,   818,  1168,   819,  1169,   820,   821,  1170,   823,   826,
    1171,  1172,  1173,   593,  1174,    80,    81,   825,   827,  1175,
     829,    82,   830,  1176,  1177,  1178,   832,   833,   834,   836,
     839,   840,   843,  1179,   844,   847,   845,   850,  1180,   846,
     805,   806,   807,   808,   809,   810,   811,   848,   849,   851,
     852,   853,   855,   854,   856,   857,   858,   859,    83,    84,
     860,   861,   862,   863,    85,    86,   864,   865,   866,   867,
     868,    87,    88,    89,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   912,   936,   937,    90,    91,   938,
     939,   940,   957,   941,   942,   943,   944,   945,   946,   947,
     948,   949,   950,   951,   952,   953,   954,   955,   956,   960,
     961,   958,   959,   962,   963,   964,   965,   966,   967,   968,
     969,   970,   972,   975,   971,   560,   978,   979,   981,   984,
     985,   986,   976,   982,   977,   980,   987,   302,   990,   988,
     992,   993,   983,   989,   994,  1023,  1037,  1039,  1187,  1188,
    1279,   991,   995,   996,   729,  1207,  1247,   997,   998,   999,
    1000,  1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,
    1010,  1011,  1012,  1013,  1014,  1015,  1016,  1021,  1022,  1235,
    1025,  1026,  1024,  1036,  1040,  1038,  1048,  1049,  1050,  1055,
    1056,  1057,  1058,  1059,  1060,  1061,  1258,  1062,  1063,  1064,
    1070,  1071,  1072,  1073,  1074,  1075,  1076,  1077,  1078,  1083,
    1259,  1084,  1085,  1260,  1086,  1087,  1088,   742,  1262,  1261,
    1089,   621,  1254,  1090,  1257,   710,  1091,  1092,  1093,  1236,
    1256,   748,   721,  1263,  1276,  1255,  1098,  1099,  1112,  1113,
     797,   786,   392,  1114,   714,   571,  1115,  1116,   642,  1229,
     449,   638,  1117,  1118,  1119,  1120,  1230,  1129,  1130,  1131,
    1127,  1132,  1155,  1156,  1157,  1158,  1159,  1183,  1184,  1185,
    1186,  1189,  1202,   316,     0,  1208,  1203,  1204,  1221,  1237,
       0,  1238,  1239,  1251,  1250,  1240,  1264,  1265,  1266,   491,
       0,     0,     0,     0,   648,   540,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   575
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-894)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     618,   619,   307,   308,   309,     1,     8,   226,     1,     1,
       1,   230,     1,     1,     1,   228,   226,     1,     1,     1,
     230,   228,    48,    15,    16,     1,     1,    19,    21,    22,
     228,     1,   226,     1,    27,    17,   230,    28,   226,     1,
       1,    24,   230,     1,   228,    36,     1,   226,    31,    17,
      32,   230,     1,     1,   228,     1,   209,    48,    49,   212,
      51,    52,    53,     1,    32,     1,     1,     1,    55,     1,
      62,    64,    65,    60,     1,    62,    60,    70,    71,    34,
      62,     1,    73,   226,    77,    78,    79,   230,    80,    81,
      82,    83,     1,     1,    62,    87,   401,   402,   228,    91,
      75,    97,    60,   408,   228,    97,   228,   412,    97,    97,
     103,   104,   417,     1,    97,   420,   108,   109,     6,     7,
      75,    97,    60,   228,    12,   430,   431,    97,   120,    97,
     226,   227,    20,    60,   121,   117,   441,   228,    26,   444,
     445,    29,    30,   125,   126,    50,   228,    35,    97,   117,
     142,    97,    40,    41,   228,    43,    44,    45,   184,    47,
      94,    97,    97,   124,   146,   133,    54,    75,   194,   124,
      58,    59,  1065,  1066,  1067,   124,   124,    97,   124,    67,
       1,   228,   150,   151,   118,    94,   124,     1,    76,   181,
     209,   226,   194,   212,   169,   230,    84,   124,    86,   226,
      88,   107,    90,   230,    92,    93,   228,   169,   226,   118,
      24,   226,   230,    34,   190,   230,   228,   105,   123,   228,
     190,   217,   110,   111,   112,   221,   114,   115,   116,   217,
     228,   119,   200,   538,   227,   227,   227,   169,   227,   221,
     227,   217,    56,   227,   227,   227,     1,   217,     3,    63,
       5,   227,   227,   221,    75,     1,   228,   145,   220,   227,
     221,   169,    17,   173,   174,   153,   154,   155,   156,   157,
     158,    85,   227,   221,   228,    89,     1,    32,   227,   227,
     169,   217,   217,    97,   228,   221,   100,   101,   220,   227,
     229,   227,   227,   227,   216,   227,   226,   203,   186,    24,
      55,   606,    57,   124,   228,   610,    31,    62,   613,    55,
     229,   226,   617,   229,    60,   230,    62,    72,   132,   198,
     199,   122,   210,   211,   226,   213,   214,   215,     9,    10,
      11,   219,   229,   226,   229,   149,   224,   230,   152,   227,
     226,   226,    97,   226,   230,     1,   198,   199,   229,    39,
       6,     7,   229,   229,   229,   229,    12,   229,   229,   229,
     229,   229,   229,   177,    20,   229,   121,   229,   229,   229,
      26,   229,    97,    29,    30,   121,    66,   122,    68,    35,
     229,   195,   196,   197,    40,    41,   141,    43,    44,    45,
       1,    47,   229,   229,   229,   150,   229,   229,    54,   229,
     229,   229,    58,    59,     4,   229,    17,   229,   222,   223,
     229,    67,   229,   227,   229,   122,   229,   229,    18,     1,
      76,    32,   229,   113,   229,    25,   107,   229,    84,   229,
      86,   229,    88,   229,    90,   229,    92,    93,   229,    39,
     195,   229,    24,   229,   229,   229,   229,   229,     1,   105,
     229,    62,   229,   229,   110,   111,   112,   229,   114,   115,
     116,   229,   229,   119,    17,   229,    66,   222,    68,   229,
     229,   229,   227,   229,    56,   165,   166,   229,   229,    32,
       1,    63,     3,   226,     5,   229,    97,   229,   229,   145,
     229,   229,   229,   229,    94,   229,    17,   153,   154,   155,
     156,   157,   158,    85,   107,   229,   117,    89,   229,    62,
     229,    32,   229,    13,   229,    97,   229,   229,   100,   101,
     229,   229,   133,   229,   229,   229,   229,   127,    68,   129,
     186,   221,   229,    33,    55,   229,    57,   229,   229,   150,
     151,    62,    42,   229,   229,   107,   209,   107,   148,   107,
     132,    72,   107,   107,   210,   211,   107,   213,   214,   215,
     209,   209,   226,   219,   117,   226,   166,   149,   224,    69,
     152,   171,   125,   126,   229,   175,    97,   229,   229,   229,
     180,   122,   229,   183,   229,   229,  1204,   229,   188,   200,
     130,   229,   229,   146,   229,   177,   229,   229,    98,    99,
     121,   229,   202,   229,   226,   229,   106,   207,   229,   229,
     221,   229,   229,   195,   196,   197,   229,   229,   218,   159,
     141,   229,   229,   229,   229,   225,   166,   229,   229,   150,
       1,   131,     0,     1,    48,   175,     4,   229,   229,   226,
     222,   223,   209,   229,    15,    16,    14,   147,    19,    17,
      18,   229,     1,   107,   107,    23,   122,   209,   107,   209,
     209,   107,   202,   107,   204,   205,    34,   209,   221,    37,
      38,   209,   209,   107,   195,   107,   107,   107,   218,    28,
     107,   107,   209,   229,   209,   225,   229,    36,   107,   209,
     209,    62,   209,    61,   209,   209,   209,   209,    66,    48,
      49,   222,    51,    52,    53,    68,    74,   122,   208,    80,
      81,    82,    83,    48,   209,   209,    87,   209,   209,   226,
      91,   226,   122,   229,    73,   229,    97,    95,    96,   805,
     806,   807,   808,   809,   810,   811,   229,   108,   109,   229,
     229,   229,   229,   229,   229,   113,   160,   161,   162,   120,
     164,   165,   226,   167,   168,   122,   170,   229,   172,   229,
      48,   175,   130,   226,   178,   179,   180,   130,   182,   229,
     226,   142,   229,   187,   229,   143,   144,   191,   192,   193,
     122,   226,   229,   122,   226,   209,   229,   201,   229,   229,
     229,   229,   206,   229,   229,   163,   159,   209,   209,   209,
     229,   229,   209,   166,   229,   209,   226,   209,   176,   122,
     181,   107,   175,   122,   122,   122,   122,   185,   122,   122,
     107,   189,   122,   122,   122,   160,   161,   162,   226,   164,
     165,   226,   167,   168,   209,   170,   229,   172,   226,   202,
     175,   204,   205,   178,   179,   180,   228,   182,   122,   226,
     226,   229,   187,   226,   226,   218,   191,   192,   193,   229,
     226,   226,   225,   107,   226,   226,   201,   226,   226,   226,
     226,   206,   160,   161,   162,     1,   164,   165,   226,   167,
     168,   226,   170,   226,   172,   226,   226,   175,   107,   107,
     178,   179,   180,   107,   182,    21,    22,   229,   107,   187,
     107,    27,   107,   191,   192,   193,   122,   107,   107,   107,
     226,   122,   122,   201,   209,   229,   122,   107,   206,   122,
     134,   135,   136,   137,   138,   139,   140,   122,   122,   122,
     122,   122,   226,   122,   122,   122,   226,   226,    64,    65,
     122,   122,   226,   226,    70,    71,   226,   226,   226,   226,
     226,    77,    78,    79,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   103,   104,   226,
     226,   226,   122,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   122,
     107,   209,   229,   122,   122,   122,   226,   122,   122,   226,
     122,   122,   107,   226,   229,   264,   122,   122,   122,   122,
     122,   122,   226,   209,   226,   226,   122,    74,   122,   209,
     122,   122,   229,   229,   122,   122,   122,   122,  1018,  1020,
    1278,   226,   226,   226,   495,  1031,   122,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   107,
     226,   226,   229,   226,   226,   229,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   128,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     128,   226,   226,   128,   226,   226,   226,   510,  1244,  1242,
     226,   334,  1223,   226,  1234,   459,   226,   226,   226,  1127,
    1232,   526,   482,  1246,  1253,  1228,   226,   226,   226,   226,
     580,   564,   111,   226,   472,   286,   226,   226,   386,  1095,
     164,   367,   226,   226,   226,   226,  1097,   226,   226,   226,
     230,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,    92,    -1,   226,   229,   229,   226,   226,
      -1,   231,   231,   226,   229,   231,   226,   226,   226,   220,
      -1,    -1,    -1,    -1,   396,   236,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   293
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   233,     0,     1,     4,    14,    17,    18,    23,    34,
      37,    38,    61,    66,    74,    95,    96,   113,   130,   143,
     144,   163,   176,   185,   189,   234,   239,   244,   268,   274,
     280,   294,   314,   337,   351,   366,   373,   377,   387,   396,
     417,   423,   429,   433,   439,   496,   511,   226,   227,   228,
     228,   315,   397,   424,   228,   434,   228,   352,   418,   338,
     228,   275,   295,   367,   228,   228,   388,   228,   228,   378,
       1,    24,    31,    97,   269,   270,   271,   272,   273,     1,
      21,    22,    27,    64,    65,    70,    71,    77,    78,    79,
     103,   104,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   228,   228,   228,     1,
      60,   430,   431,   432,   228,     1,     6,     7,    12,    20,
      26,    29,    30,    35,    40,    41,    43,    44,    45,    47,
      54,    58,    59,    67,    76,    84,    86,    88,    90,    92,
      93,   105,   110,   111,   112,   114,   115,   116,   119,   145,
     153,   154,   155,   156,   157,   158,   186,   210,   211,   213,
     214,   215,   219,   224,   440,   441,   442,   443,   444,   445,
     446,   447,   448,   449,   450,   451,   452,   453,   454,   455,
     456,   457,   458,   459,   460,   461,   462,   463,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     489,   493,   494,   495,   228,   228,   228,     1,    94,   118,
     240,   241,   242,   243,   228,   228,   228,     1,    28,    36,
      48,    49,    51,    52,    53,    73,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,     1,    24,    56,    63,
      85,    89,    97,   100,   101,   132,   149,   152,   177,   195,
     196,   197,   222,   223,   245,   246,   247,   248,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   228,     1,   220,   281,   282,   283,   284,
     285,     1,    97,   374,   375,   376,   228,   226,   229,   229,
     229,   227,   270,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   227,   498,     1,    15,    16,
      19,    62,    80,    81,    82,    83,    87,    91,    97,   108,
     109,   120,   142,   181,   316,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,     1,     3,     5,    17,    32,    55,    57,    62,
      72,    97,   121,   141,   150,   195,   222,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   412,   413,
     414,   415,   416,     1,    60,   124,   425,   426,   427,   428,
     229,   227,   431,     1,    97,   124,   435,   436,   437,   438,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   490,   229,   486,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   227,   441,
       1,    17,    32,    62,   117,   125,   126,   146,   221,   353,
     354,   355,   356,   357,   358,   359,   363,   364,   365,     1,
     124,   221,   419,   420,   421,   422,     1,    55,    60,    62,
     121,   339,   343,   344,   345,   349,   350,   226,   229,   229,
     227,   241,     1,    75,   169,   276,   277,   278,   279,     1,
      17,    32,    62,    97,   117,   133,   150,   151,   200,   221,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   310,     1,    34,    75,   124,   368,   369,   370,   371,
     372,   229,   229,   229,   229,   229,   229,   229,   229,   227,
     513,   226,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   227,
     246,     1,    97,   217,   389,   390,   391,   392,   226,   229,
     227,   282,   169,   229,   227,   375,     1,    97,   217,   221,
     379,   380,   381,   382,   383,   122,   122,   122,   226,   107,
     107,   209,   107,   107,   236,   236,   236,   107,   107,   107,
     209,   209,   226,   226,   229,   229,   229,   334,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     227,   317,   226,   229,   229,   229,   229,   229,   229,   409,
     229,   229,   229,   229,   229,   229,   229,   227,   399,   229,
     229,   227,   426,   122,   226,   229,   229,   227,   436,   209,
     236,   236,   107,   209,   107,   122,   209,   236,   209,   107,
     107,   236,   107,   209,   209,   209,   236,   107,   107,   236,
     107,   107,   107,   107,   209,   229,   209,   229,   209,   236,
     236,   209,   209,   209,   209,   212,   209,   212,   209,   209,
     209,   122,   236,   209,   209,   236,   236,   209,   209,   226,
     226,   229,   229,   360,   229,   229,   229,   229,   229,   227,
     354,   229,   229,   227,   420,   226,   229,   229,   340,   229,
     227,   344,   122,   122,   226,   226,   229,   229,   227,   277,
     226,   229,   229,   311,   229,   229,   229,   229,   229,   307,
     229,   227,   297,   226,   229,   229,   229,   227,   369,   209,
     209,   209,   122,   209,   209,   209,   236,   226,   122,   209,
     122,   107,   107,   122,   122,   122,   122,   122,   122,   107,
     122,   198,   199,   249,   250,   198,   199,   251,   252,   122,
     122,   226,   226,   229,   393,   227,   390,   209,   226,   228,
     122,   226,   226,   229,   384,   229,   227,   380,   226,   226,
     226,   226,   226,   226,   226,   134,   135,   136,   137,   138,
     139,   140,   235,   236,   226,   226,   226,   226,   226,   226,
     226,   226,   107,   107,   236,   229,   107,   107,   236,   107,
     107,   236,   122,   107,   107,   236,   107,   238,   238,   226,
     122,   173,   174,   122,   209,   122,   122,   229,   122,   122,
     107,   122,   122,   122,   122,   226,   122,   122,   226,   226,
     122,   122,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,    48,
     160,   161,   162,   164,   165,   167,   168,   170,   172,   175,
     178,   179,   180,   182,   187,   191,   192,   193,   201,   206,
     491,   492,   226,    48,   160,   161,   162,   164,   165,   167,
     168,   170,   172,   175,   178,   179,   180,   182,   187,   191,
     192,   193,   201,   206,   487,   488,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   122,   209,   229,
     122,   107,   122,   122,   122,   226,   122,   122,   226,   122,
     122,   229,   107,   347,   348,   226,   226,   226,   122,   122,
     226,   122,   209,   229,   122,   122,   122,   122,   209,   229,
     122,   226,   122,   122,   122,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   230,   226,
     230,   226,   226,   122,   229,   226,   226,     1,    97,   190,
     217,   286,   287,   288,   289,   290,   226,   122,   229,   122,
     226,   235,   235,   235,   235,   235,   235,   235,   226,   226,
     226,    50,   123,   335,   336,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,     9,    10,    11,   237,   238,
     226,   226,   226,   226,   226,   226,   226,   226,   226,     8,
     194,   410,   411,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   230,   226,   230,   226,   226,
      13,    33,    42,    69,    98,    99,   106,   131,   147,   208,
     361,   362,   226,   226,   226,   226,   226,   226,   226,   226,
     226,    48,   184,   194,   341,   342,   216,   230,   346,   226,
     226,   226,   226,     4,    18,    25,    39,    66,    68,    94,
     127,   129,   148,   166,   171,   175,   180,   183,   188,   202,
     207,   218,   225,   312,   313,   226,   226,   226,   226,   226,
      48,   160,   161,   162,   164,   165,   167,   168,   170,   172,
     175,   178,   179,   180,   182,   187,   191,   192,   193,   201,
     206,   308,   309,   226,   226,   226,   226,   250,   252,   226,
      68,   130,   159,   166,   175,   202,   204,   205,   218,   225,
     394,   395,   226,   229,   229,   291,   227,   287,   226,    68,
     130,   159,   166,   175,   202,   204,   205,   218,   225,   385,
     386,   226,   226,   230,   237,   237,   237,   226,   230,   492,
     488,   226,   230,   226,   230,   107,   348,   226,   231,   231,
     231,   226,   230,   226,   230,   226,   230,   122,   203,   238,
     229,   226,   226,   230,   336,   411,   362,   342,   128,   128,
     128,   313,   309,   395,   226,   226,   226,    39,    66,    68,
     113,   165,   166,   221,   292,   293,   386,   226,   230,   293
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
#line 399 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 401 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 405 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 409 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 413 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 417 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 421 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 425 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 429 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 434 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 435 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 436 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 437 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 438 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 484 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 490 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 80:
/* Line 1787 of yacc.c  */
#line 499 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 505 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 82:
/* Line 1787 of yacc.c  */
#line 513 "conf_parser.y"
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
#line 555 "conf_parser.y"
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
#line 614 "conf_parser.y"
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
#line 642 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 650 "conf_parser.y"
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
#line 665 "conf_parser.y"
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
#line 680 "conf_parser.y"
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
#line 689 "conf_parser.y"
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
#line 703 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(ServerInfo.network_desc);
  ServerInfo.network_desc = xstrdup(yylval.string);
}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 712 "conf_parser.y"
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
#line 740 "conf_parser.y"
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
#line 770 "conf_parser.y"
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
#line 795 "conf_parser.y"
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
#line 817 "conf_parser.y"
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
#line 839 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.name);
  AdminInfo.name = xstrdup(yylval.string);
}
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 863 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.email);
  AdminInfo.email = xstrdup(yylval.string);
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  MyFree(AdminInfo.description);
  AdminInfo.description = xstrdup(yylval.string);
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 888 "conf_parser.y"
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
#line 905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 936 "conf_parser.y"
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
#line 952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 132:
/* Line 1787 of yacc.c  */
#line 960 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 133:
/* Line 1787 of yacc.c  */
#line 963 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 134:
/* Line 1787 of yacc.c  */
#line 968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 138:
/* Line 1787 of yacc.c  */
#line 975 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 139:
/* Line 1787 of yacc.c  */
#line 979 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 140:
/* Line 1787 of yacc.c  */
#line 983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 141:
/* Line 1787 of yacc.c  */
#line 987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 142:
/* Line 1787 of yacc.c  */
#line 991 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 995 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 144:
/* Line 1787 of yacc.c  */
#line 999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 145:
/* Line 1787 of yacc.c  */
#line 1009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 146:
/* Line 1787 of yacc.c  */
#line 1016 "conf_parser.y"
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
#line 1096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1108 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1114 "conf_parser.y"
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
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1137 "conf_parser.y"
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
#line 1148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1154 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 173:
/* Line 1787 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 174:
/* Line 1787 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 175:
/* Line 1787 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REGONLY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FARCONNECT;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 197:
/* Line 1787 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL_REMOTE;
}
    break;

  case 198:
/* Line 1787 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_KILL;
}
    break;

  case 199:
/* Line 1787 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT_REMOTE;
}
    break;

  case 200:
/* Line 1787 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_CONNECT;
}
    break;

  case 201:
/* Line 1787 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT_REMOTE;
}
    break;

  case 202:
/* Line 1787 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SQUIT;
}
    break;

  case 203:
/* Line 1787 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 204:
/* Line 1787 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 205:
/* Line 1787 of yacc.c  */
#line 1286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 206:
/* Line 1787 of yacc.c  */
#line 1290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 207:
/* Line 1787 of yacc.c  */
#line 1294 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 208:
/* Line 1787 of yacc.c  */
#line 1298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 209:
/* Line 1787 of yacc.c  */
#line 1302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 210:
/* Line 1787 of yacc.c  */
#line 1306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 211:
/* Line 1787 of yacc.c  */
#line 1310 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 212:
/* Line 1787 of yacc.c  */
#line 1314 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 213:
/* Line 1787 of yacc.c  */
#line 1318 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1322 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1326 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_WALLOPS;
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1330 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_LOCOPS;
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1334 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1342 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1352 "conf_parser.y"
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
#line 1364 "conf_parser.y"
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
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
/* Line 1787 of yacc.c  */
#line 1442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
/* Line 1787 of yacc.c  */
#line 1454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
/* Line 1787 of yacc.c  */
#line 1466 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1472 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1484 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1491 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 253:
/* Line 1787 of yacc.c  */
#line 1503 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 254:
/* Line 1787 of yacc.c  */
#line 1509 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.min_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 255:
/* Line 1787 of yacc.c  */
#line 1518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  block_state.max_idle.value = (yyvsp[(3) - (4)].number);
  block_state.flags.value |= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 256:
/* Line 1787 of yacc.c  */
#line 1527 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value &= CLASS_FLAGS_FAKE_IDLE;
}
    break;

  case 260:
/* Line 1787 of yacc.c  */
#line 1534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_RANDOM_IDLE;
}
    break;

  case 261:
/* Line 1787 of yacc.c  */
#line 1538 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.flags.value |= CLASS_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 262:
/* Line 1787 of yacc.c  */
#line 1548 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 264:
/* Line 1787 of yacc.c  */
#line 1554 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1560 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 269:
/* Line 1787 of yacc.c  */
#line 1564 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 270:
/* Line 1787 of yacc.c  */
#line 1568 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1576 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1581 "conf_parser.y"
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
#line 1595 "conf_parser.y"
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
#line 1615 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1621 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1630 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 287:
/* Line 1787 of yacc.c  */
#line 1634 "conf_parser.y"
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
#line 1677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 300:
/* Line 1787 of yacc.c  */
#line 1683 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1689 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 302:
/* Line 1787 of yacc.c  */
#line 1695 "conf_parser.y"
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
#line 1706 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= (CONF_FLAGS_ENCRYPTED | CONF_FLAGS_SPOOF_IP);
}
    break;

  case 307:
/* Line 1787 of yacc.c  */
#line 1713 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1717 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1721 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1725 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1729 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 312:
/* Line 1787 of yacc.c  */
#line 1733 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 313:
/* Line 1787 of yacc.c  */
#line 1737 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1741 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1749 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1755 "conf_parser.y"
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
#line 1769 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1778 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1791 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1798 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  create_resv(block_state.name.buf, block_state.rpass.buf, &block_state.mask.list);
}
    break;

  case 328:
/* Line 1787 of yacc.c  */
#line 1809 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 329:
/* Line 1787 of yacc.c  */
#line 1815 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 330:
/* Line 1787 of yacc.c  */
#line 1821 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1836 "conf_parser.y"
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
#line 1851 "conf_parser.y"
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
#line 1862 "conf_parser.y"
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
#line 1879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 1885 "conf_parser.y"
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
#line 1904 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 351:
/* Line 1787 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 352:
/* Line 1787 of yacc.c  */
#line 1915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 353:
/* Line 1787 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 354:
/* Line 1787 of yacc.c  */
#line 1923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 355:
/* Line 1787 of yacc.c  */
#line 1927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 356:
/* Line 1787 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 357:
/* Line 1787 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 358:
/* Line 1787 of yacc.c  */
#line 1939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 359:
/* Line 1787 of yacc.c  */
#line 1943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 360:
/* Line 1787 of yacc.c  */
#line 1947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 361:
/* Line 1787 of yacc.c  */
#line 1956 "conf_parser.y"
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
#line 1965 "conf_parser.y"
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
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 369:
/* Line 1787 of yacc.c  */
#line 1986 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 1993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 375:
/* Line 1787 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2013 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2017 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 381:
/* Line 1787 of yacc.c  */
#line 2025 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 382:
/* Line 1787 of yacc.c  */
#line 2029 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 383:
/* Line 1787 of yacc.c  */
#line 2038 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2046 "conf_parser.y"
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
#line 2118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 403:
/* Line 1787 of yacc.c  */
#line 2124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 404:
/* Line 1787 of yacc.c  */
#line 2130 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 405:
/* Line 1787 of yacc.c  */
#line 2136 "conf_parser.y"
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
#line 2149 "conf_parser.y"
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
#line 2162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.cert.buf, yylval.string, sizeof(block_state.cert.buf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 409:
/* Line 1787 of yacc.c  */
#line 2174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 410:
/* Line 1787 of yacc.c  */
#line 2178 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 411:
/* Line 1787 of yacc.c  */
#line 2186 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 415:
/* Line 1787 of yacc.c  */
#line 2192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 417:
/* Line 1787 of yacc.c  */
#line 2202 "conf_parser.y"
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
#line 2213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 419:
/* Line 1787 of yacc.c  */
#line 2219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 420:
/* Line 1787 of yacc.c  */
#line 2225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2231 "conf_parser.y"
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
#line 2246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 423:
/* Line 1787 of yacc.c  */
#line 2250 "conf_parser.y"
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
#line 2275 "conf_parser.y"
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
#line 2295 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 431:
/* Line 1787 of yacc.c  */
#line 2304 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 432:
/* Line 1787 of yacc.c  */
#line 2308 "conf_parser.y"
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
#line 2334 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 439:
/* Line 1787 of yacc.c  */
#line 2340 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 445:
/* Line 1787 of yacc.c  */
#line 2354 "conf_parser.y"
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
#line 2371 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 447:
/* Line 1787 of yacc.c  */
#line 2375 "conf_parser.y"
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
#line 2397 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 454:
/* Line 1787 of yacc.c  */
#line 2403 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2447 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2464 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2470 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2475 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2480 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2485 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2490 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2495 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2500 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2505 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2510 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2515 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2520 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2525 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2530 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2535 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2541 "conf_parser.y"
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

  case 526:
/* Line 1787 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.stats_u_oper_only = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2593 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2598 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2603 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2608 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 539:
/* Line 1787 of yacc.c  */
#line 2613 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:
/* Line 1787 of yacc.c  */
#line 2618 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2623 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2628 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2633 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2643 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2662 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2676 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2681 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2686 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 563:
/* Line 1787 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 564:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2728 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2743 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2749 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REGONLY;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2752 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FARCONNECT;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2763 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2766 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2769 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2775 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 590:
/* Line 1787 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 591:
/* Line 1787 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 592:
/* Line 1787 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 593:
/* Line 1787 of yacc.c  */
#line 2799 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 594:
/* Line 1787 of yacc.c  */
#line 2802 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 595:
/* Line 1787 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 596:
/* Line 1787 of yacc.c  */
#line 2808 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 597:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 598:
/* Line 1787 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 599:
/* Line 1787 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 600:
/* Line 1787 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REGONLY;
}
    break;

  case 601:
/* Line 1787 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_FARCONNECT;
}
    break;

  case 602:
/* Line 1787 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:
/* Line 1787 of yacc.c  */
#line 2833 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1787 of yacc.c  */
#line 2838 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 622:
/* Line 1787 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1787 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1787 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:
/* Line 1787 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 627:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 628:
/* Line 1787 of yacc.c  */
#line 2896 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 629:
/* Line 1787 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 645:
/* Line 1787 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 646:
/* Line 1787 of yacc.c  */
#line 2942 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_remote_commands = yylval.number;
}
    break;

  case 647:
/* Line 1787 of yacc.c  */
#line 2948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 648:
/* Line 1787 of yacc.c  */
#line 2954 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_services = yylval.number;
}
    break;

  case 649:
/* Line 1787 of yacc.c  */
#line 2960 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 650:
/* Line 1787 of yacc.c  */
#line 2969 "conf_parser.y"
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

  case 651:
/* Line 1787 of yacc.c  */
#line 2983 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 652:
/* Line 1787 of yacc.c  */
#line 2989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6865 "conf_parser.c"
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


