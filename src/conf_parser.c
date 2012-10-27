/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.6"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */

/* Line 336 of yacc.c  */
#line 25 "conf_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "conf.h"
#include "event.h"
#include "log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "sprintf_irc.h"
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

int yylex(void);

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE];
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];
static char lfile[IRCD_BUFSIZE];
static unsigned int ltype = 0;
static unsigned int lsize = 0;
static char *resv_reason = NULL;
static char *listener_address = NULL;

struct CollectItem
{
  dlink_node node;
  char *name;
  char *user;
  char *host;
  char *passwd;
  int  port;
  int  flags;
#ifdef HAVE_LIBCRYPTO
  char *rsa_public_key_file;
  RSA *rsa_public_key;
#endif
};

static void
free_collect_item(struct CollectItem *item)
{
  MyFree(item->name);
  MyFree(item->user);
  MyFree(item->host);
  MyFree(item->passwd);
#ifdef HAVE_LIBCRYPTO
  MyFree(item->rsa_public_key_file);
#endif
  MyFree(item);
}



/* Line 336 of yacc.c  */
#line 155 "conf_parser.c"

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
#ifndef YY_Y_TAB_H
# define YY_Y_TAB_H
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
     ACTION = 259,
     ADMIN = 260,
     AFTYPE = 261,
     T_ALLOW = 262,
     ANTI_NICK_FLOOD = 263,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 264,
     AUTOCONN = 265,
     T_BLOCK = 266,
     BURST_AWAY = 267,
     BYTES = 268,
     KBYTES = 269,
     MBYTES = 270,
     GBYTES = 271,
     TBYTES = 272,
     CALLER_ID_WAIT = 273,
     CAN_FLOOD = 274,
     CHANNEL = 275,
     CIDR_BITLEN_IPV4 = 276,
     CIDR_BITLEN_IPV6 = 277,
     CLASS = 278,
     CONNECT = 279,
     CONNECTFREQ = 280,
     DEFAULT_FLOODCOUNT = 281,
     DEFAULT_SPLIT_SERVER_COUNT = 282,
     DEFAULT_SPLIT_USER_COUNT = 283,
     DENY = 284,
     DESCRIPTION = 285,
     DIE = 286,
     DISABLE_AUTH = 287,
     DISABLE_FAKE_CHANNELS = 288,
     DISABLE_HIDDEN = 289,
     DISABLE_LOCAL_CHANNELS = 290,
     DISABLE_REMOTE_COMMANDS = 291,
     DOTS_IN_IDENT = 292,
     DURATION = 293,
     EGDPOOL_PATH = 294,
     EMAIL = 295,
     ENABLE = 296,
     ENCRYPTED = 297,
     EXCEED_LIMIT = 298,
     EXEMPT = 299,
     FAILED_OPER_NOTICE = 300,
     IRCD_FLAGS = 301,
     FLATTEN_LINKS = 302,
     GECOS = 303,
     GENERAL = 304,
     GLINE = 305,
     GLINE_DURATION = 306,
     GLINE_ENABLE = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
     GLINE_REQUEST_DURATION = 310,
     GLINE_MIN_CIDR = 311,
     GLINE_MIN_CIDR6 = 312,
     GLOBAL_KILL = 313,
     IRCD_AUTH = 314,
     NEED_IDENT = 315,
     HAVENT_READ_CONF = 316,
     HIDDEN = 317,
     HIDDEN_NAME = 318,
     HIDE_SERVER_IPS = 319,
     HIDE_SERVERS = 320,
     HIDE_SPOOF_IPS = 321,
     HOST = 322,
     HUB = 323,
     HUB_MASK = 324,
     IGNORE_BOGUS_TS = 325,
     INVISIBLE_ON_CONNECT = 326,
     IP = 327,
     KILL = 328,
     KILL_CHASE_TIME_LIMIT = 329,
     KLINE = 330,
     KLINE_EXEMPT = 331,
     KLINE_REASON = 332,
     KLINE_WITH_REASON = 333,
     KNOCK_DELAY = 334,
     KNOCK_DELAY_CHANNEL = 335,
     LEAF_MASK = 336,
     LINKS_DELAY = 337,
     LISTEN = 338,
     T_LOG = 339,
     MAX_ACCEPT = 340,
     MAX_BANS = 341,
     MAX_CHANS_PER_OPER = 342,
     MAX_CHANS_PER_USER = 343,
     MAX_GLOBAL = 344,
     MAX_IDENT = 345,
     MAX_LOCAL = 346,
     MAX_NICK_CHANGES = 347,
     MAX_NICK_TIME = 348,
     MAX_NUMBER = 349,
     MAX_TARGETS = 350,
     MAX_WATCH = 351,
     MESSAGE_LOCALE = 352,
     MIN_NONWILDCARD = 353,
     MIN_NONWILDCARD_SIMPLE = 354,
     MODULE = 355,
     MODULES = 356,
     NAME = 357,
     NEED_PASSWORD = 358,
     NETWORK_DESC = 359,
     NETWORK_NAME = 360,
     NICK = 361,
     NICK_CHANGES = 362,
     NO_CREATE_ON_SPLIT = 363,
     NO_JOIN_ON_SPLIT = 364,
     NO_OPER_FLOOD = 365,
     NO_TILDE = 366,
     NUMBER = 367,
     NUMBER_PER_IDENT = 368,
     NUMBER_PER_CIDR = 369,
     NUMBER_PER_IP = 370,
     NUMBER_PER_IP_GLOBAL = 371,
     OPERATOR = 372,
     OPERS_BYPASS_CALLERID = 373,
     OPER_ONLY_UMODES = 374,
     OPER_PASS_RESV = 375,
     OPER_SPY_T = 376,
     OPER_UMODES = 377,
     JOIN_FLOOD_COUNT = 378,
     JOIN_FLOOD_TIME = 379,
     PACE_WAIT = 380,
     PACE_WAIT_SIMPLE = 381,
     PASSWORD = 382,
     PATH = 383,
     PING_COOKIE = 384,
     PING_TIME = 385,
     PING_WARNING = 386,
     PORT = 387,
     QSTRING = 388,
     QUIET_ON_BAN = 389,
     REASON = 390,
     REDIRPORT = 391,
     REDIRSERV = 392,
     REGEX_T = 393,
     REHASH = 394,
     TREJECT_HOLD_TIME = 395,
     REMOTE = 396,
     REMOTEBAN = 397,
     RESTRICT_CHANNELS = 398,
     RESTRICTED = 399,
     RSA_PRIVATE_KEY_FILE = 400,
     RSA_PUBLIC_KEY_FILE = 401,
     SSL_CERTIFICATE_FILE = 402,
     SSL_DH_PARAM_FILE = 403,
     T_SSL_CLIENT_METHOD = 404,
     T_SSL_SERVER_METHOD = 405,
     T_SSLV3 = 406,
     T_TLSV1 = 407,
     RESV = 408,
     RESV_EXEMPT = 409,
     SECONDS = 410,
     MINUTES = 411,
     HOURS = 412,
     DAYS = 413,
     WEEKS = 414,
     SENDQ = 415,
     SEND_PASSWORD = 416,
     SERVERHIDE = 417,
     SERVERINFO = 418,
     IRCD_SID = 419,
     TKLINE_EXPIRE_NOTICES = 420,
     T_SHARED = 421,
     T_CLUSTER = 422,
     TYPE = 423,
     SHORT_MOTD = 424,
     SILENT = 425,
     SPOOF = 426,
     SPOOF_NOTICE = 427,
     STATS_E_DISABLED = 428,
     STATS_I_OPER_ONLY = 429,
     STATS_K_OPER_ONLY = 430,
     STATS_O_OPER_ONLY = 431,
     STATS_P_OPER_ONLY = 432,
     TBOOL = 433,
     TMASKED = 434,
     T_REJECT = 435,
     TS_MAX_DELTA = 436,
     TS_WARN_DELTA = 437,
     TWODOTS = 438,
     T_ALL = 439,
     T_BOTS = 440,
     T_SOFTCALLERID = 441,
     T_CALLERID = 442,
     T_CCONN = 443,
     T_CCONN_FULL = 444,
     T_SSL_CIPHER_LIST = 445,
     T_CLIENT_FLOOD = 446,
     T_DEAF = 447,
     T_DEBUG = 448,
     T_DLINE = 449,
     T_DRONE = 450,
     T_EXTERNAL = 451,
     T_FULL = 452,
     T_INVISIBLE = 453,
     T_IPV4 = 454,
     T_IPV6 = 455,
     T_LOCOPS = 456,
     T_MAX_CLIENTS = 457,
     T_NCHANGE = 458,
     T_OPERWALL = 459,
     T_REJ = 460,
     T_SERVER = 461,
     T_SERVNOTICE = 462,
     T_SET = 463,
     T_SKILL = 464,
     T_SPY = 465,
     T_SSL = 466,
     T_UMODES = 467,
     T_UNAUTH = 468,
     T_UNDLINE = 469,
     T_UNLIMITED = 470,
     T_UNRESV = 471,
     T_UNXLINE = 472,
     T_GLOBOPS = 473,
     T_WALLOP = 474,
     T_RESTART = 475,
     T_SERVICE = 476,
     T_SERVICES_NAME = 477,
     THROTTLE_TIME = 478,
     TOPICBURST = 479,
     TRUE_NO_OPER_FLOOD = 480,
     TKLINE = 481,
     TXLINE = 482,
     TRESV = 483,
     UNKLINE = 484,
     USER = 485,
     USE_EGD = 486,
     USE_EXCEPT = 487,
     USE_INVEX = 488,
     USE_KNOCK = 489,
     USE_LOGGING = 490,
     USE_WHOIS_ACTUALLY = 491,
     VHOST = 492,
     VHOST6 = 493,
     XLINE = 494,
     WARN = 495,
     WARN_NO_NLINE = 496,
     T_SIZE = 497,
     T_FILE = 498
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ACTION 259
#define ADMIN 260
#define AFTYPE 261
#define T_ALLOW 262
#define ANTI_NICK_FLOOD 263
#define ANTI_SPAM_EXIT_MESSAGE_TIME 264
#define AUTOCONN 265
#define T_BLOCK 266
#define BURST_AWAY 267
#define BYTES 268
#define KBYTES 269
#define MBYTES 270
#define GBYTES 271
#define TBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CLASS 278
#define CONNECT 279
#define CONNECTFREQ 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_HIDDEN 289
#define DISABLE_LOCAL_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DOTS_IN_IDENT 292
#define DURATION 293
#define EGDPOOL_PATH 294
#define EMAIL 295
#define ENABLE 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define FAILED_OPER_NOTICE 300
#define IRCD_FLAGS 301
#define FLATTEN_LINKS 302
#define GECOS 303
#define GENERAL 304
#define GLINE 305
#define GLINE_DURATION 306
#define GLINE_ENABLE 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
#define GLINE_REQUEST_DURATION 310
#define GLINE_MIN_CIDR 311
#define GLINE_MIN_CIDR6 312
#define GLOBAL_KILL 313
#define IRCD_AUTH 314
#define NEED_IDENT 315
#define HAVENT_READ_CONF 316
#define HIDDEN 317
#define HIDDEN_NAME 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SPOOF_IPS 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define IGNORE_BOGUS_TS 325
#define INVISIBLE_ON_CONNECT 326
#define IP 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_REASON 332
#define KLINE_WITH_REASON 333
#define KNOCK_DELAY 334
#define KNOCK_DELAY_CHANNEL 335
#define LEAF_MASK 336
#define LINKS_DELAY 337
#define LISTEN 338
#define T_LOG 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_CHANS_PER_OPER 342
#define MAX_CHANS_PER_USER 343
#define MAX_GLOBAL 344
#define MAX_IDENT 345
#define MAX_LOCAL 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_WATCH 351
#define MESSAGE_LOCALE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define NAME 357
#define NEED_PASSWORD 358
#define NETWORK_DESC 359
#define NETWORK_NAME 360
#define NICK 361
#define NICK_CHANGES 362
#define NO_CREATE_ON_SPLIT 363
#define NO_JOIN_ON_SPLIT 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER 367
#define NUMBER_PER_IDENT 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define NUMBER_PER_IP_GLOBAL 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define OPER_ONLY_UMODES 374
#define OPER_PASS_RESV 375
#define OPER_SPY_T 376
#define OPER_UMODES 377
#define JOIN_FLOOD_COUNT 378
#define JOIN_FLOOD_TIME 379
#define PACE_WAIT 380
#define PACE_WAIT_SIMPLE 381
#define PASSWORD 382
#define PATH 383
#define PING_COOKIE 384
#define PING_TIME 385
#define PING_WARNING 386
#define PORT 387
#define QSTRING 388
#define QUIET_ON_BAN 389
#define REASON 390
#define REDIRPORT 391
#define REDIRSERV 392
#define REGEX_T 393
#define REHASH 394
#define TREJECT_HOLD_TIME 395
#define REMOTE 396
#define REMOTEBAN 397
#define RESTRICT_CHANNELS 398
#define RESTRICTED 399
#define RSA_PRIVATE_KEY_FILE 400
#define RSA_PUBLIC_KEY_FILE 401
#define SSL_CERTIFICATE_FILE 402
#define SSL_DH_PARAM_FILE 403
#define T_SSL_CLIENT_METHOD 404
#define T_SSL_SERVER_METHOD 405
#define T_SSLV3 406
#define T_TLSV1 407
#define RESV 408
#define RESV_EXEMPT 409
#define SECONDS 410
#define MINUTES 411
#define HOURS 412
#define DAYS 413
#define WEEKS 414
#define SENDQ 415
#define SEND_PASSWORD 416
#define SERVERHIDE 417
#define SERVERINFO 418
#define IRCD_SID 419
#define TKLINE_EXPIRE_NOTICES 420
#define T_SHARED 421
#define T_CLUSTER 422
#define TYPE 423
#define SHORT_MOTD 424
#define SILENT 425
#define SPOOF 426
#define SPOOF_NOTICE 427
#define STATS_E_DISABLED 428
#define STATS_I_OPER_ONLY 429
#define STATS_K_OPER_ONLY 430
#define STATS_O_OPER_ONLY 431
#define STATS_P_OPER_ONLY 432
#define TBOOL 433
#define TMASKED 434
#define T_REJECT 435
#define TS_MAX_DELTA 436
#define TS_WARN_DELTA 437
#define TWODOTS 438
#define T_ALL 439
#define T_BOTS 440
#define T_SOFTCALLERID 441
#define T_CALLERID 442
#define T_CCONN 443
#define T_CCONN_FULL 444
#define T_SSL_CIPHER_LIST 445
#define T_CLIENT_FLOOD 446
#define T_DEAF 447
#define T_DEBUG 448
#define T_DLINE 449
#define T_DRONE 450
#define T_EXTERNAL 451
#define T_FULL 452
#define T_INVISIBLE 453
#define T_IPV4 454
#define T_IPV6 455
#define T_LOCOPS 456
#define T_MAX_CLIENTS 457
#define T_NCHANGE 458
#define T_OPERWALL 459
#define T_REJ 460
#define T_SERVER 461
#define T_SERVNOTICE 462
#define T_SET 463
#define T_SKILL 464
#define T_SPY 465
#define T_SSL 466
#define T_UMODES 467
#define T_UNAUTH 468
#define T_UNDLINE 469
#define T_UNLIMITED 470
#define T_UNRESV 471
#define T_UNXLINE 472
#define T_GLOBOPS 473
#define T_WALLOP 474
#define T_RESTART 475
#define T_SERVICE 476
#define T_SERVICES_NAME 477
#define THROTTLE_TIME 478
#define TOPICBURST 479
#define TRUE_NO_OPER_FLOOD 480
#define TKLINE 481
#define TXLINE 482
#define TRESV 483
#define UNKLINE 484
#define USER 485
#define USE_EGD 486
#define USE_EXCEPT 487
#define USE_INVEX 488
#define USE_KNOCK 489
#define USE_LOGGING 490
#define USE_WHOIS_ACTUALLY 491
#define VHOST 492
#define VHOST6 493
#define XLINE 494
#define WARN 495
#define WARN_NO_NLINE 496
#define T_SIZE 497
#define T_FILE 498



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 350 of yacc.c  */
#line 692 "conf_parser.c"
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

#endif /* !YY_Y_TAB_H  */

/* Copy the second part of user declarations.  */


/* Line 353 of yacc.c  */
#line 721 "conf_parser.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
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
#define YYLAST   1259

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  249
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  647
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1275

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   498

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   248,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   244,
       2,   247,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   246,     2,   245,     2,     2,     2,     2,
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
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238,   239,   240,   241,   242,   243
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    80,    82,    85,    89,    93,
      97,   103,   106,   108,   110,   112,   115,   120,   125,   131,
     134,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   169,   174,   179,
     183,   185,   187,   189,   193,   195,   197,   199,   204,   209,
     214,   219,   224,   229,   234,   239,   244,   249,   254,   259,
     264,   270,   273,   275,   277,   279,   281,   284,   289,   294,
     299,   305,   308,   310,   312,   314,   317,   322,   323,   330,
     333,   335,   337,   339,   341,   344,   349,   354,   359,   360,
     366,   370,   372,   374,   376,   378,   380,   382,   384,   386,
     387,   394,   397,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   418,   423,   428,   433,   438,   443,   448,   449,
     455,   459,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   502,   508,   512,   514,   516,   518,   520,
     522,   524,   526,   528,   530,   532,   534,   536,   538,   540,
     542,   544,   546,   548,   550,   552,   553,   560,   563,   565,
     567,   569,   571,   573,   575,   577,   579,   581,   583,   585,
     587,   589,   591,   594,   599,   604,   609,   614,   619,   624,
     629,   634,   639,   644,   649,   654,   659,   660,   667,   668,
     674,   678,   680,   682,   684,   686,   689,   691,   693,   695,
     697,   699,   702,   703,   709,   713,   715,   717,   721,   726,
     731,   732,   739,   742,   744,   746,   748,   750,   752,   754,
     756,   758,   760,   763,   768,   773,   778,   783,   784,   790,
     794,   796,   798,   800,   802,   804,   806,   808,   810,   812,
     814,   819,   824,   829,   830,   837,   840,   842,   844,   846,
     848,   851,   856,   861,   866,   872,   875,   877,   879,   881,
     886,   887,   894,   897,   899,   901,   903,   905,   908,   913,
     918,   919,   925,   929,   931,   933,   935,   937,   939,   941,
     943,   945,   947,   949,   951,   952,   959,   962,   964,   966,
     968,   971,   976,   977,   983,   987,   989,   991,   993,   995,
     997,   999,  1001,  1003,  1005,  1007,  1009,  1010,  1017,  1020,
    1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
    1042,  1044,  1046,  1048,  1051,  1056,  1061,  1066,  1071,  1076,
    1081,  1086,  1091,  1092,  1098,  1102,  1104,  1106,  1108,  1110,
    1112,  1117,  1122,  1127,  1132,  1137,  1138,  1145,  1146,  1152,
    1156,  1158,  1160,  1163,  1165,  1167,  1169,  1171,  1173,  1178,
    1183,  1184,  1191,  1194,  1196,  1198,  1200,  1202,  1207,  1212,
    1218,  1221,  1223,  1225,  1227,  1232,  1233,  1240,  1241,  1247,
    1251,  1253,  1255,  1258,  1260,  1262,  1264,  1266,  1268,  1273,
    1278,  1284,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,
    1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,
    1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,
    1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,
    1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1399,  1404,
    1409,  1414,  1419,  1424,  1429,  1434,  1439,  1444,  1449,  1454,
    1459,  1464,  1469,  1474,  1479,  1484,  1489,  1494,  1499,  1504,
    1509,  1514,  1519,  1524,  1529,  1534,  1539,  1544,  1549,  1554,
    1559,  1564,  1569,  1574,  1579,  1584,  1589,  1594,  1599,  1604,
    1609,  1614,  1619,  1624,  1629,  1634,  1639,  1644,  1649,  1650,
    1656,  1660,  1662,  1664,  1666,  1668,  1670,  1672,  1674,  1676,
    1678,  1680,  1682,  1684,  1686,  1688,  1690,  1692,  1694,  1696,
    1698,  1700,  1702,  1703,  1709,  1713,  1715,  1717,  1719,  1721,
    1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,  1739,  1741,
    1743,  1745,  1747,  1749,  1751,  1753,  1755,  1760,  1765,  1770,
    1775,  1781,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1818,
    1820,  1822,  1824,  1829,  1834,  1839,  1844,  1849,  1854,  1859,
    1864,  1869,  1874,  1879,  1884,  1889,  1894,  1899,  1904,  1909,
    1914,  1920,  1923,  1925,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1941,  1946,  1951,  1956,  1961,  1966,  1971
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     250,     0,    -1,    -1,   250,   251,    -1,   283,    -1,   289,
      -1,   303,    -1,   510,    -1,   321,    -1,   338,    -1,   352,
      -1,   261,    -1,   531,    -1,   367,    -1,   374,    -1,   378,
      -1,   388,    -1,   397,    -1,   417,    -1,   427,    -1,   433,
      -1,   447,    -1,   437,    -1,   256,    -1,     1,   244,    -1,
       1,   245,    -1,    -1,   253,    -1,   112,   252,    -1,   112,
     155,   252,    -1,   112,   156,   252,    -1,   112,   157,   252,
      -1,   112,   158,   252,    -1,   112,   159,   252,    -1,    -1,
     255,    -1,   112,   254,    -1,   112,    13,   254,    -1,   112,
      14,   254,    -1,   112,    15,   254,    -1,   101,   246,   257,
     245,   244,    -1,   257,   258,    -1,   258,    -1,   259,    -1,
     260,    -1,     1,   244,    -1,   100,   247,   133,   244,    -1,
     128,   247,   133,   244,    -1,   163,   246,   262,   245,   244,
      -1,   262,   263,    -1,   263,    -1,   274,    -1,   279,    -1,
     282,    -1,   276,    -1,   277,    -1,   278,    -1,   281,    -1,
     272,    -1,   271,    -1,   280,    -1,   275,    -1,   270,    -1,
     264,    -1,   265,    -1,   273,    -1,     1,   244,    -1,   149,
     247,   266,   244,    -1,   150,   247,   268,   244,    -1,   266,
     248,   267,    -1,   267,    -1,   151,    -1,   152,    -1,   268,
     248,   269,    -1,   269,    -1,   151,    -1,   152,    -1,   147,
     247,   133,   244,    -1,   145,   247,   133,   244,    -1,   148,
     247,   133,   244,    -1,   190,   247,   133,   244,    -1,   102,
     247,   133,   244,    -1,   164,   247,   133,   244,    -1,    30,
     247,   133,   244,    -1,   105,   247,   133,   244,    -1,   104,
     247,   133,   244,    -1,   237,   247,   133,   244,    -1,   238,
     247,   133,   244,    -1,   202,   247,   112,   244,    -1,    68,
     247,   178,   244,    -1,     5,   246,   284,   245,   244,    -1,
     284,   285,    -1,   285,    -1,   286,    -1,   288,    -1,   287,
      -1,     1,   244,    -1,   102,   247,   133,   244,    -1,    40,
     247,   133,   244,    -1,    30,   247,   133,   244,    -1,    84,
     246,   290,   245,   244,    -1,   290,   291,    -1,   291,    -1,
     292,    -1,   293,    -1,     1,   244,    -1,   235,   247,   178,
     244,    -1,    -1,   294,   243,   246,   295,   245,   244,    -1,
     295,   296,    -1,   296,    -1,   297,    -1,   299,    -1,   298,
      -1,     1,   244,    -1,   102,   247,   133,   244,    -1,   242,
     247,   255,   244,    -1,   242,   247,   215,   244,    -1,    -1,
     168,   300,   247,   301,   244,    -1,   301,   248,   302,    -1,
     302,    -1,   230,    -1,   117,    -1,    50,    -1,   194,    -1,
      75,    -1,    73,    -1,   193,    -1,    -1,   117,   304,   246,
     305,   245,   244,    -1,   305,   306,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,   313,    -1,   312,    -1,   310,
      -1,   311,    -1,   317,    -1,     1,   244,    -1,   102,   247,
     133,   244,    -1,   230,   247,   133,   244,    -1,   127,   247,
     133,   244,    -1,    42,   247,   178,   244,    -1,   146,   247,
     133,   244,    -1,    23,   247,   133,   244,    -1,    -1,   212,
     314,   247,   315,   244,    -1,   315,   248,   316,    -1,   316,
      -1,   185,    -1,   188,    -1,   189,    -1,   192,    -1,   193,
      -1,   197,    -1,    62,    -1,   209,    -1,   203,    -1,   205,
      -1,   213,    -1,   210,    -1,   196,    -1,   204,    -1,   207,
      -1,   198,    -1,   219,    -1,   186,    -1,   187,    -1,   201,
      -1,    -1,    46,   318,   247,   319,   244,    -1,   319,   248,
     320,    -1,   320,    -1,    58,    -1,   141,    -1,    75,    -1,
     229,    -1,   194,    -1,   214,    -1,   239,    -1,    50,    -1,
      31,    -1,   220,    -1,   139,    -1,     5,    -1,   107,    -1,
     204,    -1,   218,    -1,   121,    -1,   142,    -1,   208,    -1,
     100,    -1,    -1,    23,   322,   246,   323,   245,   244,    -1,
     323,   324,    -1,   324,    -1,   325,    -1,   335,    -1,   336,
      -1,   326,    -1,   327,    -1,   337,    -1,   328,    -1,   329,
      -1,   330,    -1,   331,    -1,   332,    -1,   333,    -1,   334,
      -1,     1,   244,    -1,   102,   247,   133,   244,    -1,   130,
     247,   253,   244,    -1,   131,   247,   253,   244,    -1,   115,
     247,   112,   244,    -1,    25,   247,   253,   244,    -1,    94,
     247,   112,   244,    -1,    89,   247,   112,   244,    -1,    91,
     247,   112,   244,    -1,    90,   247,   112,   244,    -1,   160,
     247,   255,   244,    -1,    21,   247,   112,   244,    -1,    22,
     247,   112,   244,    -1,   114,   247,   112,   244,    -1,    -1,
      83,   339,   246,   344,   245,   244,    -1,    -1,    46,   341,
     247,   342,   244,    -1,   342,   248,   343,    -1,   343,    -1,
     211,    -1,    62,    -1,   206,    -1,   344,   345,    -1,   345,
      -1,   346,    -1,   340,    -1,   350,    -1,   351,    -1,     1,
     244,    -1,    -1,   132,   247,   348,   347,   244,    -1,   348,
     248,   349,    -1,   349,    -1,   112,    -1,   112,   183,   112,
      -1,    72,   247,   133,   244,    -1,    67,   247,   133,   244,
      -1,    -1,    59,   353,   246,   354,   245,   244,    -1,   354,
     355,    -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,
     360,    -1,   364,    -1,   365,    -1,   366,    -1,   359,    -1,
       1,   244,    -1,   230,   247,   133,   244,    -1,   127,   247,
     133,   244,    -1,    23,   247,   133,   244,    -1,    42,   247,
     178,   244,    -1,    -1,    46,   361,   247,   362,   244,    -1,
     362,   248,   363,    -1,   363,    -1,   172,    -1,    43,    -1,
      76,    -1,    60,    -1,    19,    -1,   111,    -1,    53,    -1,
     154,    -1,   103,    -1,   171,   247,   133,   244,    -1,   137,
     247,   133,   244,    -1,   136,   247,   112,   244,    -1,    -1,
     153,   368,   246,   369,   245,   244,    -1,   369,   370,    -1,
     370,    -1,   371,    -1,   372,    -1,   373,    -1,     1,   244,
      -1,   135,   247,   133,   244,    -1,    20,   247,   133,   244,
      -1,   106,   247,   133,   244,    -1,   221,   246,   375,   245,
     244,    -1,   375,   376,    -1,   376,    -1,   377,    -1,     1,
      -1,   102,   247,   133,   244,    -1,    -1,   166,   379,   246,
     380,   245,   244,    -1,   380,   381,    -1,   381,    -1,   382,
      -1,   383,    -1,   384,    -1,     1,   244,    -1,   102,   247,
     133,   244,    -1,   230,   247,   133,   244,    -1,    -1,   168,
     385,   247,   386,   244,    -1,   386,   248,   387,    -1,   387,
      -1,    75,    -1,   229,    -1,   194,    -1,   214,    -1,   239,
      -1,   217,    -1,   153,    -1,   216,    -1,   201,    -1,   184,
      -1,    -1,   167,   389,   246,   390,   245,   244,    -1,   390,
     391,    -1,   391,    -1,   392,    -1,   393,    -1,     1,   244,
      -1,   102,   247,   133,   244,    -1,    -1,   168,   394,   247,
     395,   244,    -1,   395,   248,   396,    -1,   396,    -1,    75,
      -1,   229,    -1,   194,    -1,   214,    -1,   239,    -1,   217,
      -1,   153,    -1,   216,    -1,   201,    -1,   184,    -1,    -1,
      24,   398,   246,   399,   245,   244,    -1,   399,   400,    -1,
     400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     405,    -1,   407,    -1,   406,    -1,   416,    -1,   408,    -1,
     413,    -1,   414,    -1,   415,    -1,   412,    -1,     1,   244,
      -1,   102,   247,   133,   244,    -1,    67,   247,   133,   244,
      -1,   237,   247,   133,   244,    -1,   161,   247,   133,   244,
      -1,     3,   247,   133,   244,    -1,   132,   247,   112,   244,
      -1,     6,   247,   199,   244,    -1,     6,   247,   200,   244,
      -1,    -1,    46,   409,   247,   410,   244,    -1,   410,   248,
     411,    -1,   411,    -1,    10,    -1,    12,    -1,   224,    -1,
     211,    -1,    42,   247,   178,   244,    -1,    69,   247,   133,
     244,    -1,    81,   247,   133,   244,    -1,    23,   247,   133,
     244,    -1,   190,   247,   133,   244,    -1,    -1,    73,   418,
     246,   423,   245,   244,    -1,    -1,   168,   420,   247,   421,
     244,    -1,   421,   248,   422,    -1,   422,    -1,   138,    -1,
     423,   424,    -1,   424,    -1,   425,    -1,   426,    -1,   419,
      -1,     1,    -1,   230,   247,   133,   244,    -1,   135,   247,
     133,   244,    -1,    -1,    29,   428,   246,   429,   245,   244,
      -1,   429,   430,    -1,   430,    -1,   431,    -1,   432,    -1,
       1,    -1,    72,   247,   133,   244,    -1,   135,   247,   133,
     244,    -1,    44,   246,   434,   245,   244,    -1,   434,   435,
      -1,   435,    -1,   436,    -1,     1,    -1,    72,   247,   133,
     244,    -1,    -1,    48,   438,   246,   443,   245,   244,    -1,
      -1,   168,   440,   247,   441,   244,    -1,   441,   248,   442,
      -1,   442,    -1,   138,    -1,   443,   444,    -1,   444,    -1,
     445,    -1,   446,    -1,   439,    -1,     1,    -1,   102,   247,
     133,   244,    -1,   135,   247,   133,   244,    -1,    49,   246,
     448,   245,   244,    -1,   448,   449,    -1,   449,    -1,   460,
      -1,   461,    -1,   463,    -1,   464,    -1,   465,    -1,   466,
      -1,   467,    -1,   468,    -1,   469,    -1,   470,    -1,   459,
      -1,   472,    -1,   473,    -1,   474,    -1,   475,    -1,   490,
      -1,   477,    -1,   479,    -1,   481,    -1,   480,    -1,   484,
      -1,   478,    -1,   485,    -1,   486,    -1,   487,    -1,   488,
      -1,   489,    -1,   502,    -1,   491,    -1,   492,    -1,   493,
      -1,   498,    -1,   482,    -1,   483,    -1,   508,    -1,   506,
      -1,   507,    -1,   462,    -1,   509,    -1,   497,    -1,   471,
      -1,   495,    -1,   496,    -1,   458,    -1,   451,    -1,   452,
      -1,   453,    -1,   454,    -1,   455,    -1,   456,    -1,   457,
      -1,   476,    -1,   450,    -1,   494,    -1,     1,    -1,    96,
     247,   112,   244,    -1,    52,   247,   178,   244,    -1,    51,
     247,   253,   244,    -1,    55,   247,   253,   244,    -1,    56,
     247,   112,   244,    -1,    57,   247,   112,   244,    -1,   236,
     247,   178,   244,    -1,   140,   247,   253,   244,    -1,   165,
     247,   178,   244,    -1,    74,   247,   253,   244,    -1,    66,
     247,   178,   244,    -1,    70,   247,   178,   244,    -1,    36,
     247,   178,   244,    -1,    45,   247,   178,   244,    -1,     8,
     247,   178,   244,    -1,    93,   247,   253,   244,    -1,    92,
     247,   112,   244,    -1,    85,   247,   112,   244,    -1,     9,
     247,   253,   244,    -1,   182,   247,   253,   244,    -1,   181,
     247,   253,   244,    -1,    61,   247,   112,   244,    -1,    78,
     247,   178,   244,    -1,    77,   247,   133,   244,    -1,    71,
     247,   178,   244,    -1,   241,   247,   178,   244,    -1,   173,
     247,   178,   244,    -1,   176,   247,   178,   244,    -1,   177,
     247,   178,   244,    -1,   175,   247,   178,   244,    -1,   175,
     247,   179,   244,    -1,   174,   247,   178,   244,    -1,   174,
     247,   179,   244,    -1,   125,   247,   253,   244,    -1,    18,
     247,   253,   244,    -1,   118,   247,   178,   244,    -1,   126,
     247,   253,   244,    -1,   169,   247,   178,   244,    -1,   110,
     247,   178,   244,    -1,   225,   247,   178,   244,    -1,   120,
     247,   178,   244,    -1,    97,   247,   133,   244,    -1,    37,
     247,   112,   244,    -1,    95,   247,   112,   244,    -1,   231,
     247,   178,   244,    -1,    39,   247,   133,   244,    -1,   222,
     247,   133,   244,    -1,   129,   247,   178,   244,    -1,    32,
     247,   178,   244,    -1,   223,   247,   253,   244,    -1,    -1,
     122,   499,   247,   500,   244,    -1,   500,   248,   501,    -1,
     501,    -1,   185,    -1,   188,    -1,   189,    -1,   192,    -1,
     193,    -1,   197,    -1,    62,    -1,   209,    -1,   203,    -1,
     205,    -1,   213,    -1,   210,    -1,   196,    -1,   204,    -1,
     207,    -1,   198,    -1,   219,    -1,   186,    -1,   187,    -1,
     201,    -1,    -1,   119,   503,   247,   504,   244,    -1,   504,
     248,   505,    -1,   505,    -1,   185,    -1,   188,    -1,   189,
      -1,   192,    -1,   193,    -1,   197,    -1,   209,    -1,    62,
      -1,   203,    -1,   205,    -1,   213,    -1,   210,    -1,   196,
      -1,   204,    -1,   207,    -1,   198,    -1,   219,    -1,   186,
      -1,   187,    -1,   201,    -1,    98,   247,   112,   244,    -1,
      99,   247,   112,   244,    -1,    26,   247,   112,   244,    -1,
     191,   247,   255,   244,    -1,    20,   246,   511,   245,   244,
      -1,   511,   512,    -1,   512,    -1,   515,    -1,   516,    -1,
     517,    -1,   518,    -1,   524,    -1,   519,    -1,   520,    -1,
     521,    -1,   522,    -1,   523,    -1,   525,    -1,   526,    -1,
     527,    -1,   514,    -1,   528,    -1,   529,    -1,   530,    -1,
     513,    -1,     1,    -1,    33,   247,   178,   244,    -1,   143,
     247,   178,   244,    -1,    35,   247,   178,   244,    -1,   232,
     247,   178,   244,    -1,   233,   247,   178,   244,    -1,   234,
     247,   178,   244,    -1,    79,   247,   253,   244,    -1,    80,
     247,   253,   244,    -1,    88,   247,   112,   244,    -1,    87,
     247,   112,   244,    -1,   134,   247,   178,   244,    -1,    86,
     247,   112,   244,    -1,    28,   247,   112,   244,    -1,    27,
     247,   112,   244,    -1,   108,   247,   178,   244,    -1,   109,
     247,   178,   244,    -1,   123,   247,   112,   244,    -1,   124,
     247,   253,   244,    -1,   162,   246,   532,   245,   244,    -1,
     532,   533,    -1,   533,    -1,   534,    -1,   535,    -1,   537,
      -1,   539,    -1,   538,    -1,   536,    -1,   540,    -1,     1,
      -1,    47,   247,   178,   244,    -1,    65,   247,   178,   244,
      -1,    63,   247,   133,   244,    -1,    82,   247,   253,   244,
      -1,    62,   247,   178,   244,    -1,    34,   247,   178,   244,
      -1,    64,   247,   178,   244,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   357,   357,   358,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   386,   386,   387,   391,
     395,   399,   403,   407,   413,   413,   414,   415,   416,   417,
     424,   427,   427,   428,   428,   428,   430,   436,   443,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   450,
     450,   451,   451,   452,   452,   453,   454,   457,   458,   460,
     460,   461,   467,   475,   475,   476,   482,   490,   529,   588,
     616,   624,   639,   654,   663,   677,   686,   714,   744,   767,
     776,   778,   778,   779,   779,   780,   780,   782,   791,   800,
     812,   813,   813,   815,   815,   816,   818,   825,   825,   835,
     836,   838,   838,   839,   839,   841,   846,   849,   855,   854,
     860,   860,   861,   865,   869,   873,   877,   881,   885,   896,
     895,   993,   993,   994,   994,   994,   995,   995,   995,   996,
     996,   996,   998,  1007,  1044,  1056,  1067,  1109,  1119,  1118,
    1124,  1124,  1125,  1129,  1133,  1137,  1141,  1145,  1149,  1153,
    1157,  1161,  1165,  1169,  1173,  1177,  1181,  1185,  1189,  1193,
    1197,  1201,  1208,  1207,  1213,  1213,  1214,  1218,  1222,  1226,
    1230,  1234,  1238,  1242,  1246,  1250,  1254,  1258,  1262,  1266,
    1270,  1274,  1278,  1282,  1286,  1297,  1296,  1346,  1346,  1347,
    1348,  1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,
    1357,  1358,  1359,  1361,  1370,  1376,  1382,  1388,  1394,  1400,
    1406,  1412,  1418,  1424,  1430,  1436,  1446,  1445,  1462,  1461,
    1466,  1466,  1467,  1471,  1475,  1483,  1483,  1484,  1484,  1484,
    1484,  1484,  1486,  1486,  1488,  1488,  1490,  1504,  1524,  1533,
    1546,  1545,  1614,  1614,  1615,  1615,  1615,  1615,  1616,  1616,
    1616,  1617,  1617,  1619,  1654,  1667,  1676,  1688,  1687,  1691,
    1691,  1692,  1696,  1700,  1704,  1708,  1712,  1716,  1720,  1724,
    1731,  1750,  1760,  1774,  1773,  1789,  1789,  1790,  1790,  1790,
    1790,  1792,  1801,  1816,  1829,  1831,  1831,  1832,  1832,  1834,
    1850,  1849,  1865,  1865,  1866,  1866,  1866,  1866,  1868,  1877,
    1900,  1899,  1905,  1905,  1906,  1910,  1914,  1918,  1922,  1926,
    1930,  1934,  1938,  1942,  1952,  1951,  1968,  1968,  1969,  1969,
    1969,  1971,  1978,  1977,  1983,  1983,  1984,  1988,  1992,  1996,
    2000,  2004,  2008,  2012,  2016,  2020,  2030,  2029,  2080,  2080,
    2081,  2081,  2081,  2082,  2082,  2083,  2083,  2083,  2084,  2084,
    2084,  2085,  2085,  2086,  2088,  2097,  2106,  2132,  2150,  2168,
    2174,  2178,  2187,  2186,  2190,  2190,  2191,  2195,  2199,  2203,
    2209,  2220,  2231,  2242,  2251,  2270,  2269,  2335,  2334,  2338,
    2338,  2339,  2345,  2345,  2346,  2346,  2346,  2346,  2348,  2367,
    2377,  2376,  2401,  2401,  2402,  2402,  2402,  2404,  2410,  2419,
    2421,  2421,  2422,  2422,  2424,  2443,  2442,  2490,  2489,  2493,
    2493,  2494,  2500,  2500,  2501,  2501,  2501,  2501,  2503,  2509,
    2518,  2521,  2521,  2522,  2522,  2523,  2523,  2524,  2524,  2525,
    2525,  2526,  2526,  2527,  2527,  2528,  2528,  2529,  2529,  2530,
    2530,  2531,  2531,  2532,  2532,  2533,  2533,  2534,  2534,  2535,
    2536,  2536,  2537,  2537,  2538,  2538,  2539,  2539,  2540,  2540,
    2541,  2542,  2543,  2543,  2544,  2545,  2546,  2546,  2547,  2547,
    2548,  2549,  2549,  2550,  2550,  2551,  2551,  2552,  2555,  2560,
    2566,  2572,  2578,  2583,  2588,  2593,  2598,  2603,  2608,  2613,
    2618,  2623,  2628,  2633,  2638,  2643,  2648,  2653,  2658,  2664,
    2675,  2680,  2689,  2694,  2699,  2704,  2709,  2714,  2717,  2722,
    2725,  2730,  2735,  2740,  2745,  2750,  2755,  2760,  2765,  2770,
    2781,  2786,  2791,  2796,  2805,  2814,  2819,  2824,  2830,  2829,
    2834,  2834,  2835,  2838,  2841,  2844,  2847,  2850,  2853,  2856,
    2859,  2862,  2865,  2868,  2871,  2874,  2877,  2880,  2883,  2886,
    2889,  2892,  2898,  2897,  2902,  2902,  2903,  2906,  2909,  2912,
    2915,  2918,  2921,  2924,  2927,  2930,  2933,  2936,  2939,  2942,
    2945,  2948,  2951,  2954,  2957,  2960,  2965,  2970,  2975,  2980,
    2989,  2992,  2992,  2993,  2993,  2994,  2994,  2994,  2995,  2995,
    2996,  2996,  2997,  2997,  2998,  2999,  2999,  3000,  3001,  3001,
    3002,  3002,  3004,  3009,  3014,  3019,  3024,  3029,  3034,  3039,
    3044,  3049,  3054,  3059,  3064,  3069,  3074,  3079,  3084,  3089,
    3097,  3100,  3100,  3101,  3101,  3102,  3103,  3104,  3104,  3105,
    3106,  3108,  3114,  3120,  3129,  3143,  3149,  3155
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BYTES", "KBYTES", "MBYTES",
  "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CHANNEL",
  "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CLASS", "CONNECT",
  "CONNECTFREQ", "DEFAULT_FLOODCOUNT", "DEFAULT_SPLIT_SERVER_COUNT",
  "DEFAULT_SPLIT_USER_COUNT", "DENY", "DESCRIPTION", "DIE", "DISABLE_AUTH",
  "DISABLE_FAKE_CHANNELS", "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS",
  "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH",
  "EMAIL", "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT",
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_TIME",
  "GLINE_REQUEST_DURATION", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_NAME", "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS",
  "HOST", "HUB", "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT",
  "IP", "KILL", "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT",
  "KLINE_REASON", "KLINE_WITH_REASON", "KNOCK_DELAY",
  "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER",
  "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES",
  "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS", "MAX_WATCH",
  "MESSAGE_LOCALE", "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE",
  "MODULES", "NAME", "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME",
  "NICK", "NICK_CHANGES", "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT",
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_IDENT",
  "NUMBER_PER_CIDR", "NUMBER_PER_IP", "NUMBER_PER_IP_GLOBAL", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON",
  "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH", "TREJECT_HOLD_TIME",
  "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS", "RESTRICTED",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVER", "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL",
  "T_UMODES", "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV",
  "T_UNXLINE", "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD",
  "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT",
  "USE_INVEX", "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST",
  "VHOST6", "XLINE", "WARN", "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'",
  "'}'", "'{'", "'='", "','", "$accept", "conf", "conf_item", "timespec_",
  "timespec", "sizespec_", "sizespec", "modules_entry", "modules_items",
  "modules_item", "modules_module", "modules_path", "serverinfo_entry",
  "serverinfo_items", "serverinfo_item", "serverinfo_ssl_client_method",
  "serverinfo_ssl_server_method", "client_method_types",
  "client_method_type_item", "server_method_types",
  "server_method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_ssl_dh_param_file",
  "serverinfo_ssl_cipher_list", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_use_logging",
  "logging_file_entry", "$@1", "logging_file_items", "logging_file_item",
  "logging_file_name", "logging_file_size", "logging_file_type", "$@2",
  "logging_file_type_items", "logging_file_type_item", "oper_entry", "$@3",
  "oper_items", "oper_item", "oper_name", "oper_user", "oper_password",
  "oper_encrypted", "oper_rsa_public_key_file", "oper_class",
  "oper_umodes", "$@4", "oper_umodes_items", "oper_umodes_item",
  "oper_flags", "$@5", "oper_flags_items", "oper_flags_item",
  "class_entry", "$@6", "class_items", "class_item", "class_name",
  "class_ping_time", "class_ping_warning", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@7", "listen_flags", "$@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@11", "auth_flags_items", "auth_flags_item", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "resv_entry", "$@12", "resv_items",
  "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "service_entry", "service_items", "service_item", "service_name",
  "shared_entry", "$@13", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "$@14", "shared_types", "shared_type_item",
  "cluster_entry", "$@15", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@16", "cluster_types", "cluster_type_item",
  "connect_entry", "$@17", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@18", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@19",
  "kill_type", "$@20", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@21",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@22",
  "gecos_flags", "$@23", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_enable", "general_gline_duration",
  "general_gline_request_duration", "general_gline_min_cidr",
  "general_gline_min_cidr6", "general_use_whois_actually",
  "general_reject_hold_time", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_kline_with_reason",
  "general_kline_reason", "general_invisible_on_connect",
  "general_warn_no_nline", "general_stats_e_disabled",
  "general_stats_o_oper_only", "general_stats_P_oper_only",
  "general_stats_k_oper_only", "general_stats_i_oper_only",
  "general_pace_wait", "general_caller_id_wait",
  "general_opers_bypass_callerid", "general_pace_wait_simple",
  "general_short_motd", "general_no_oper_flood",
  "general_true_no_oper_flood", "general_oper_pass_resv",
  "general_message_locale", "general_dots_in_ident", "general_max_targets",
  "general_use_egd", "general_egdpool_path", "general_services_name",
  "general_ping_cookie", "general_disable_auth", "general_throttle_time",
  "general_oper_umodes", "$@24", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@25", "umode_items", "umode_item",
  "general_min_nonwildcard", "general_min_nonwildcard_simple",
  "general_default_floodcount", "general_client_flood", "channel_entry",
  "channel_items", "channel_item", "channel_disable_fake_channels",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_max_chans_per_oper",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
  "serverhide_disable_hidden", "serverhide_hide_server_ips", YY_NULL
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   249,   250,   250,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   251,   252,   252,   253,   253,
     253,   253,   253,   253,   254,   254,   255,   255,   255,   255,
     256,   257,   257,   258,   258,   258,   259,   260,   261,   262,
     262,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   264,   265,   266,
     266,   267,   267,   268,   268,   269,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   284,   285,   285,   285,   285,   286,   287,   288,
     289,   290,   290,   291,   291,   291,   292,   294,   293,   295,
     295,   296,   296,   296,   296,   297,   298,   298,   300,   299,
     301,   301,   302,   302,   302,   302,   302,   302,   302,   304,
     303,   305,   305,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   307,   308,   309,   310,   311,   312,   314,   313,
     315,   315,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   318,   317,   319,   319,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   322,   321,   323,   323,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,   339,   338,   341,   340,
     342,   342,   343,   343,   343,   344,   344,   345,   345,   345,
     345,   345,   347,   346,   348,   348,   349,   349,   350,   351,
     353,   352,   354,   354,   355,   355,   355,   355,   355,   355,
     355,   355,   355,   356,   357,   358,   359,   361,   360,   362,
     362,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     364,   365,   366,   368,   367,   369,   369,   370,   370,   370,
     370,   371,   372,   373,   374,   375,   375,   376,   376,   377,
     379,   378,   380,   380,   381,   381,   381,   381,   382,   383,
     385,   384,   386,   386,   387,   387,   387,   387,   387,   387,
     387,   387,   387,   387,   389,   388,   390,   390,   391,   391,
     391,   392,   394,   393,   395,   395,   396,   396,   396,   396,
     396,   396,   396,   396,   396,   396,   398,   397,   399,   399,
     400,   400,   400,   400,   400,   400,   400,   400,   400,   400,
     400,   400,   400,   400,   401,   402,   403,   404,   405,   406,
     407,   407,   409,   408,   410,   410,   411,   411,   411,   411,
     412,   413,   414,   415,   416,   418,   417,   420,   419,   421,
     421,   422,   423,   423,   424,   424,   424,   424,   425,   426,
     428,   427,   429,   429,   430,   430,   430,   431,   432,   433,
     434,   434,   435,   435,   436,   438,   437,   440,   439,   441,
     441,   442,   443,   443,   444,   444,   444,   444,   445,   446,
     447,   448,   448,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   449,   449,
     449,   449,   449,   449,   449,   449,   449,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   479,   480,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   499,   498,
     500,   500,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   501,   501,   501,   501,   501,   501,   501,   501,
     501,   501,   503,   502,   504,   504,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   505,   505,   505,   505,
     505,   505,   505,   505,   505,   505,   506,   507,   508,   509,
     510,   511,   511,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   512,   512,   512,   512,   512,   512,   512,   512,
     512,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   532,   533,   533,   533,   533,   533,   533,   533,
     533,   534,   535,   536,   537,   538,   539,   540
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     0,     1,     2,     3,     3,     3,
       5,     2,     1,     1,     1,     2,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     3,
       1,     1,     1,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     2,     4,     0,     6,     2,
       1,     1,     1,     1,     2,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     6,     0,     5,
       3,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     2,     0,     5,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     6,     2,     1,     1,     1,
       2,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     0,     6,     0,     5,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     0,     5,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   346,   400,     0,
     415,     0,   250,   385,   226,     0,     0,   129,   283,     0,
       0,   300,   324,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   611,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   592,   610,   606,   593,
     594,   595,   596,   598,   599,   600,   601,   602,   597,   603,
     604,   605,   607,   608,   609,     0,     0,     0,   413,     0,
       0,   411,   412,     0,   487,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,     0,   538,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   485,   477,   478,   479,   480,   481,   482,   483,   476,
     443,   433,   434,   470,   435,   436,   437,   438,   439,   440,
     441,   442,   473,   444,   445,   446,   447,   484,   449,   454,
     450,   452,   451,   465,   466,   453,   455,   456,   457,   458,
     459,   448,   461,   462,   463,   486,   474,   475,   472,   464,
     460,   468,   469,   467,   471,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,   640,     0,     0,     0,     0,     0,
       0,     0,     0,   632,   633,   634,   638,   635,   637,   636,
     639,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   298,     0,     0,   296,
     297,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   591,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   198,   199,   202,   203,   205,   206,   207,   208,
     209,   210,   211,   200,   201,   204,     0,     0,     0,     0,
       0,   372,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   349,   350,   351,   352,   353,   354,   356,   355,   358,
     362,   359,   360,   361,   357,   406,     0,     0,     0,   403,
     404,   405,     0,     0,   410,   427,     0,     0,   417,   426,
       0,   423,   424,   425,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   431,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
     253,   254,   255,   256,   261,   257,   258,   259,   260,   397,
       0,   387,     0,   396,     0,   393,   394,   395,     0,   228,
       0,     0,     0,   238,     0,   236,   237,   239,   240,   105,
       0,     0,   101,     0,    45,     0,     0,     0,    41,     0,
       0,     0,   172,     0,     0,     0,   148,     0,     0,   132,
     133,   134,   135,   138,   139,   137,   136,   140,     0,     0,
       0,     0,     0,   286,   287,   288,   289,     0,     0,     0,
       0,     0,     0,     0,     0,   631,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   310,     0,     0,   303,
     304,   305,   306,     0,     0,   332,     0,   327,   328,   329,
       0,     0,   295,     0,     0,     0,    90,     0,     0,     0,
       0,    26,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   590,   212,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   363,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   348,     0,
       0,     0,   402,     0,   409,     0,     0,     0,     0,   422,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,     0,   430,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,   392,   241,     0,     0,     0,     0,     0,
     235,     0,   100,     0,     0,     0,    40,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   290,     0,
       0,     0,     0,   285,     0,     0,     0,     0,     0,     0,
       0,   630,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,    70,    75,    76,     0,    74,     0,     0,
       0,     0,     0,    48,   307,     0,     0,     0,     0,   302,
     330,     0,     0,     0,   326,     0,   294,    99,    98,    97,
     625,   624,   612,   614,    26,    26,    26,    26,    26,    28,
      27,   618,   619,   623,   621,   620,   626,   627,   628,   629,
     622,   613,   615,   616,   617,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,   401,   414,     0,     0,
       0,   416,   502,   506,   522,   588,   536,   500,   530,   533,
     501,   490,   489,   491,   492,   493,   509,   498,   499,   512,
     497,   511,   510,   505,   504,   503,   531,   488,   529,   586,
     587,   526,   523,   573,   566,   583,   584,   567,   568,   569,
     570,   578,   571,   581,   585,   574,   579,   575,   580,   572,
     577,   576,   582,     0,   565,   528,   548,   542,   559,   560,
     543,   544,   545,   546,   554,   547,   557,   561,   550,   555,
     551,   556,   549,   553,   552,   558,     0,   541,   521,   524,
     535,   495,   496,   525,   514,   519,   520,   517,   518,   515,
     516,   508,   507,    34,    34,    34,    36,    35,   589,   534,
     537,   527,   532,   494,   513,     0,     0,     0,     0,     0,
       0,     0,     0,   251,     0,     0,     0,   386,     0,     0,
       0,   246,   242,   245,   227,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   284,
     646,   641,   645,   643,   647,   642,   644,    83,    89,    81,
      85,    84,    78,    77,    79,    67,     0,    68,     0,    82,
      80,    88,    86,    87,     0,     0,     0,   301,     0,     0,
     325,   299,    29,    30,    31,    32,    33,   223,   224,   217,
     219,   221,   220,   218,   213,   225,   216,   214,   215,   222,
     368,   370,   371,   383,   380,   376,   377,   379,   378,     0,
     375,   365,   381,   382,   364,   369,   367,   384,   366,   407,
     408,   428,   429,   421,     0,   420,   563,     0,   539,     0,
      37,    38,    39,   265,   266,   275,   272,   277,   274,   273,
     279,   276,   278,   271,     0,   270,   264,   282,   281,   280,
     263,   399,   391,     0,   390,   398,   233,   234,   232,     0,
     231,   249,   248,     0,     0,     0,   114,     0,     0,     0,
       0,   109,   147,   145,   187,   184,   183,   176,   178,   194,
     188,   191,   186,   177,   192,   180,   189,   193,   181,   190,
     185,   179,   182,     0,   175,   142,   144,   146,   158,   152,
     169,   170,   153,   154,   155,   156,   164,   157,   167,   171,
     160,   165,   161,   166,   159,   163,   162,   168,     0,   151,
     143,   292,   293,   291,    69,    73,   308,   314,   320,   323,
     316,   322,   317,   321,   319,   315,   318,     0,   313,   309,
     331,   336,   342,   345,   338,   344,   339,   343,   341,   337,
     340,     0,   335,   373,     0,   418,     0,   564,   540,   268,
       0,   388,     0,   229,     0,   247,   244,   243,     0,     0,
       0,     0,   108,   173,     0,   149,     0,   311,     0,   333,
       0,   374,   419,   269,   389,   230,   115,   124,   127,   126,
     123,   128,   125,   122,     0,   121,   117,   116,   174,   150,
     312,   334,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   819,   820,   966,   967,    25,   248,   249,
     250,   251,    26,   287,   288,   289,   290,   782,   783,   786,
     787,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,    27,    71,    72,    73,    74,    75,
      28,   240,   241,   242,   243,   244,  1000,  1001,  1002,  1003,
    1004,  1138,  1264,  1265,    29,    60,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   754,  1188,  1189,   537,   750,
    1163,  1164,    30,    49,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   365,    31,
      57,   503,   735,  1129,  1130,   504,   505,   506,  1135,   992,
     993,   507,   508,    32,    55,   479,   480,   481,   482,   483,
     484,   485,   721,  1114,  1115,   486,   487,   488,    33,    61,
     542,   543,   544,   545,   546,    34,   308,   309,   310,    35,
      64,   578,   579,   580,   581,   582,   796,  1207,  1208,    36,
      65,   586,   587,   588,   589,   802,  1221,  1222,    37,    50,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     638,  1079,  1080,   390,   391,   392,   393,   394,    38,    56,
     493,   730,  1123,  1124,   494,   495,   496,   497,    39,    51,
     398,   399,   400,   401,    40,   120,   121,   122,    41,    53,
     409,   657,  1094,  1095,   410,   411,   412,   413,    42,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     447,   946,   947,   230,   445,   923,   924,   231,   232,   233,
     234,    43,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,    44,   262,   263,   264,   265,   266,   267,   268,
     269,   270
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -784
static const yytype_int16 yypact[] =
{
    -784,   688,  -784,  -234,  -225,  -219,  -784,  -784,  -784,  -217,
    -784,  -206,  -784,  -784,  -784,  -204,  -201,  -784,  -784,  -198,
    -196,  -784,  -784,  -193,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,   106,   597,  -186,
    -171,  -169,    15,  -158,   378,  -152,  -144,  -123,     3,    60,
    -113,   -96,   663,   431,   -84,   -68,    22,   -55,   -50,   -45,
     -36,    19,  -784,  -784,  -784,  -784,  -784,   -18,   -13,    26,
      28,    33,    37,    44,    50,    70,    81,    84,    86,    87,
      89,    92,    93,    94,    96,    11,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,   755,   459,    13,  -784,    97,
      29,  -784,  -784,    24,  -784,    99,   100,   101,   103,   108,
     112,   115,   116,   119,   120,   124,   128,   130,   131,   133,
     136,   137,   138,   147,   152,   153,   154,   156,   158,   159,
     162,   169,   171,   173,   175,   177,  -784,   178,  -784,   179,
     184,   190,   193,   194,   195,   196,   198,   199,   200,   203,
     204,   206,   207,   210,   212,   217,   219,   220,   221,   129,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,   516,    63,   270,    91,   222,
      17,  -784,  -784,  -784,   110,   164,   225,   231,    73,  -784,
    -784,  -784,   483,    88,  -784,   232,   234,   236,   238,   239,
     242,   243,    18,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,   247,   245,   246,   248,   255,   261,   263,   264,   266,
     268,   272,   274,   275,   276,   277,   280,   174,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,     2,     4,  -784,   283,    56,  -784,
    -784,  -784,   240,   288,   361,   287,  -784,   402,   420,   356,
     359,   426,   426,   429,   430,   432,   367,   370,   437,   426,
     372,   386,   388,   389,   390,   328,  -784,   330,   323,   335,
     336,   337,   339,   341,   342,   345,   347,   349,   350,   352,
     355,   267,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,   331,   357,   358,   360,
     364,  -784,   365,   366,   369,   376,   379,   380,   384,   387,
     326,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,   391,   392,    21,  -784,
    -784,  -784,   444,   362,  -784,  -784,   394,   395,  -784,  -784,
      14,  -784,  -784,  -784,   439,   426,   426,   496,   466,   467,
     525,   513,   469,   426,   477,   426,   547,   548,   549,   484,
     487,   488,   426,   534,   492,   559,   560,   426,   562,   563,
     546,   568,   569,   508,   512,   447,   520,   453,   426,   426,
     523,   426,   524,   526,   529,   104,   107,   536,   538,   426,
     426,   579,   570,   426,   544,   552,   556,   561,   480,  -784,
     494,   504,   505,  -784,   506,   510,   511,   517,   518,     5,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
     521,  -784,   522,  -784,    42,  -784,  -784,  -784,   497,  -784,
     527,   528,   531,  -784,    12,  -784,  -784,  -784,  -784,  -784,
     577,   499,  -784,   514,  -784,   629,   630,   539,  -784,   540,
     541,   543,  -784,   545,   550,   551,  -784,   553,    69,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,   542,   554,
     555,   566,    16,  -784,  -784,  -784,  -784,   589,   592,   595,
     652,   613,   617,   426,   564,  -784,  -784,   666,   618,   670,
     673,   674,   676,   677,   679,   144,   161,   681,   682,   705,
     685,   687,   575,  -784,   578,   574,  -784,   576,    85,  -784,
    -784,  -784,  -784,   580,   581,  -784,    62,  -784,  -784,  -784,
     692,   582,  -784,   583,   588,   590,  -784,   591,   593,   594,
     596,   233,   598,   599,   603,   604,   608,   609,   612,   614,
     615,   616,   619,   620,   621,   622,  -784,  -784,   721,   724,
     426,   727,   749,   750,   756,   734,   764,   765,   426,   426,
     579,   636,  -784,  -784,   748,   126,   759,   710,   647,   767,
     768,   769,   770,   785,   771,   773,   774,   654,  -784,   775,
     783,   675,  -784,   680,  -784,   787,   792,   684,   683,  -784,
     689,   693,   701,   704,   709,   712,   716,   718,   722,   726,
     728,   730,   731,   732,   733,   735,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   745,   746,   747,   751,   752,
     753,   686,   757,   725,   758,   760,   761,   762,   763,   766,
     772,   776,   777,   778,   779,   780,   781,   782,   784,    41,
     786,   788,   789,   790,   791,   793,   794,  -784,  -784,   803,
     800,   702,   821,   853,   835,   836,   838,   795,  -784,   859,
     796,   860,   797,  -784,  -784,   798,   861,   865,   887,   802,
    -784,   804,  -784,    23,   805,   806,  -784,  -784,   867,   825,
     807,   875,   876,   878,   808,   879,   809,  -784,  -784,   880,
     881,   882,   812,  -784,   813,   814,   815,   816,   817,   818,
     819,  -784,   820,   822,   823,   824,   826,   827,   828,   829,
    -784,  -784,  -207,  -784,  -784,  -784,  -182,  -784,   830,   831,
     832,   833,   834,  -784,  -784,   884,   837,   885,   839,  -784,
    -784,   886,   840,   841,  -784,   842,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,   426,   426,   426,   426,   426,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,   844,   845,   846,   847,   848,
     849,   850,   851,   852,   854,   855,   856,   857,  -784,   858,
     862,   863,   864,   866,    66,   868,   869,   870,   871,   872,
     873,   874,   877,  -784,   883,   888,  -784,  -784,   889,   890,
     891,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -177,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -176,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,   579,   579,   579,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,   892,   893,   639,   894,   895,
     896,   897,   898,  -784,   899,   902,   900,  -784,   -54,   901,
     903,   914,   799,  -784,  -784,  -784,   904,   905,  -784,   906,
      25,  -784,  -784,  -784,  -784,  -784,  -784,   907,   910,   515,
     911,   912,   913,   754,   915,  -784,   916,   917,   918,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,   144,  -784,   161,  -784,
    -784,  -784,  -784,  -784,   919,   434,   920,  -784,   921,   565,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -175,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -135,  -784,  -784,   686,  -784,   725,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -130,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,   -81,  -784,  -784,  -784,  -784,  -784,   -65,
    -784,  -784,  -784,   924,   887,   922,  -784,   909,   923,  -105,
     925,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,   -39,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,   -32,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,   -31,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,    -8,  -784,  -784,    66,  -784,   891,  -784,  -784,  -784,
     639,  -784,   902,  -784,   -54,  -784,  -784,  -784,   927,   363,
     928,   929,  -784,  -784,   515,  -784,   754,  -784,   434,  -784,
     565,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,    -7,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,   363,  -784
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -784,  -784,  -784,  -783,  -320,  -745,  -461,  -784,  -784,   926,
    -784,  -784,  -784,  -784,   843,  -784,  -784,  -784,    -9,  -784,
       6,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,   960,  -784,  -784,  -784,
    -784,  -784,   811,  -784,  -784,  -784,  -784,    52,  -784,  -784,
    -784,  -784,  -784,  -208,  -784,  -784,  -784,   600,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -167,  -784,  -784,
    -784,  -164,  -784,  -784,  -784,   908,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -165,  -784,   601,  -784,  -784,  -784,
     -53,  -784,  -784,  -784,  -784,  -784,   624,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -148,  -784,  -784,  -784,  -784,  -784,
    -784,   567,  -784,  -784,  -784,  -784,  -784,   930,  -784,  -784,
    -784,  -784,   533,  -784,  -784,  -784,  -784,  -784,  -129,  -784,
    -784,  -784,   537,  -784,  -784,  -784,  -784,  -146,  -784,  -784,
    -784,   801,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -104,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -110,  -784,   631,  -784,  -784,  -784,  -784,
    -784,   810,  -784,  -784,  -784,  -784,  1004,  -784,  -784,  -784,
    -784,  -784,  -784,  -100,  -784,   719,  -784,  -784,  -784,  -784,
     952,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,    36,  -784,  -784,  -784,    49,  -784,  -784,  -784,
    -784,  -784,  -784,  1054,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,  -784,
    -784,  -784,  -784,  -784,   931,  -784,  -784,  -784,  -784,  -784,
    -784,  -784
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     710,   602,   603,   574,   238,   583,   470,   709,  1126,   610,
      45,    46,    76,   498,   395,   405,   118,   538,   238,   254,
      67,    47,   395,   306,   996,   405,   996,    48,   471,    52,
     118,  1052,  1053,  1054,  1055,  1056,   539,  1035,    77,    78,
      54,  1036,    58,   489,    79,    59,    80,   472,    62,    68,
      63,   473,   255,    66,   963,   964,   965,   306,   499,    69,
     115,   245,  1037,   583,   489,   256,  1038,  1096,  1098,  1223,
     519,  1097,  1099,  1224,   245,   116,  1075,   117,  1076,   500,
     257,   258,   259,   260,   501,   396,   574,   119,   123,   538,
      81,    82,   520,   396,   235,   661,   662,    83,    84,    85,
     261,   119,   236,   669,   575,   671,   584,    67,   539,  1225,
    1240,   521,   678,  1226,  1229,   522,   406,   683,  1230,    86,
      87,    70,   540,   237,   307,   997,   406,   997,   694,   695,
     124,   697,   474,   252,    88,    89,    68,   125,   126,   707,
     708,   475,   476,   712,   502,    90,    69,   127,   397,   407,
     253,   541,  1127,   709,    91,   128,   397,  1128,   307,   407,
     246,   129,   304,  1231,   584,   130,   131,  1232,   132,   847,
     576,   523,   585,   246,   133,   271,   477,   490,   305,  1233,
     134,   135,   408,  1234,   136,   137,   138,   575,   247,   311,
     139,   998,   408,   998,   540,   140,   524,   312,   490,   141,
     142,   247,   313,   143,   272,  1243,   144,   145,    70,  1244,
     491,   314,  1245,  1247,   146,   525,  1246,  1248,  1100,  1101,
    1102,   147,   148,   541,   149,   150,   151,   152,   153,   317,
     585,   491,   577,   770,   318,   478,  1249,  1272,   239,   154,
    1250,  1273,   273,    92,    93,    94,  -107,   155,   156,   157,
     727,   158,   239,   576,   159,   160,   335,   739,   161,   658,
    -107,   762,   511,   554,   315,   999,   651,   999,   337,   162,
    1140,   498,   492,   319,   403,   320,   274,  1077,   275,   276,
     321,   526,   701,   702,   322,   703,   704,   732,   338,   339,
    1078,   323,   340,   492,   163,   780,   781,   324,   164,   527,
     837,   591,   165,   166,   167,   168,   169,   803,   845,   846,
     170,   171,   784,   785,   756,   577,   499,   325,   517,   277,
     172,   278,   279,   280,   281,   850,   851,   366,   326,   367,
     798,   327,   368,   328,   329,   509,   330,   500,   282,   331,
     332,   333,   501,   334,   402,   601,   414,   415,   416,   369,
     417,   173,   174,   513,   175,   418,   341,   342,   343,   419,
     176,   344,   420,   421,   283,   177,   422,   423,   370,   345,
     178,   424,   371,   593,   468,   425,   284,   426,   427,   124,
     428,   346,   347,   429,   430,   431,   125,   126,   814,   815,
     816,   817,   818,   372,   432,   373,   127,   348,   349,   433,
     434,   435,   502,   436,   128,   437,   438,   374,   514,   439,
     129,   285,   286,  1257,   130,   131,   440,   132,   441,   572,
     442,   594,   443,   133,   444,   446,   448,   350,   375,   134,
     135,   449,   271,   136,   137,   138,  1258,   450,  1259,   139,
     451,   452,   453,   454,   140,   455,   456,   457,   141,   142,
     458,   459,   143,   460,   461,   144,   145,   462,   376,   463,
     366,   272,   367,   146,   464,   368,   465,   466,   467,   510,
     147,   148,   515,   149,   150,   151,   152,   153,   516,   547,
    1260,   548,   369,   549,   519,   550,   551,   377,   154,   552,
     553,   556,   557,   558,   595,   559,   155,   156,   157,   273,
     158,   370,   560,   159,   160,   371,   520,   161,   561,  1197,
     562,   563,   631,   564,   597,   565,   378,   470,   162,   566,
    1144,   567,   568,   569,   570,   521,   372,   571,   373,   522,
     590,   596,   598,   274,   599,   275,   276,   600,   601,   471,
     374,   604,   605,   163,   606,   607,  1145,   164,   608,   609,
     611,   165,   166,   167,   168,   169,  1261,  1262,   472,   170,
     171,   375,   473,   379,   612,  1146,   613,   614,   615,   172,
     618,   647,   616,  1147,   617,   633,   277,   653,   278,   279,
     280,   281,   619,   620,   621,   523,   622,  1198,   623,   624,
    1148,   376,   625,  1263,   626,   282,   627,   628,    76,   629,
     173,   174,   630,   175,   634,   635,   654,   636,   663,   176,
     524,   637,   639,   640,   177,  1149,   641,   660,  1199,   178,
     377,   283,  1150,   642,    77,    78,   643,   644,  1200,   525,
      79,   645,    80,   284,   646,  1201,  1151,   666,   649,   650,
    1211,   655,   656,   474,   664,   665,   667,   668,  1202,   378,
    1203,  1204,   475,   476,  1152,   670,  1153,  1154,  1105,   672,
     673,   674,   675,  1205,   254,   676,   677,   679,   285,   286,
     680,   681,   682,  1206,   684,   685,    81,    82,  1241,   686,
     687,   688,  1106,    83,    84,    85,   689,   477,     2,     3,
     690,   709,  1107,     4,   691,   526,   379,   255,   692,  1108,
     693,   696,   698,   711,   699,    86,    87,   700,     5,  1155,
     256,     6,     7,   527,   705,  1109,   706,     8,  1212,  1156,
      88,    89,   713,  1157,   717,   257,   258,   259,   260,  1158,
     714,    90,     9,  1159,   715,  1160,    10,    11,   718,   716,
      91,   734,  1110,   742,  1161,   261,   478,    12,   903,  1213,
    1111,   719,   720,   722,  1162,   741,   337,   723,   724,  1214,
     743,    13,   744,   745,   725,   726,  1215,   764,   729,   731,
     765,    14,    15,   766,   736,   737,   338,   339,   738,  1216,
     340,  1217,  1218,   746,   747,   767,   758,   926,   748,    16,
     749,   768,   751,  1112,  1219,   769,   773,   752,   753,   772,
     755,   759,   760,   774,  1220,    17,   775,   776,   771,   777,
     778,  1113,   779,   761,   788,   789,  1168,   790,   791,   793,
     792,   795,   794,   797,   800,   805,   806,   807,   801,    92,
      93,    94,   808,   835,   809,   810,   836,   811,   812,   838,
     813,    18,   821,   822,   341,   342,   343,   823,   824,   344,
      19,    20,   825,   826,    21,    22,   827,   345,   828,   829,
     830,   839,   840,   831,   832,   833,   834,   842,   841,   346,
     347,   904,   905,   906,   907,   908,   843,   844,   909,   910,
     848,   849,   911,   912,   913,   348,   349,   914,   853,   915,
     916,   917,   852,   918,   854,   919,   920,   859,   863,   921,
     855,   856,   857,   858,   860,   922,   861,   862,   864,    23,
     927,   928,   929,   930,   931,   350,   865,   932,   933,   866,
     868,   934,   935,   936,   867,   869,   937,   871,   938,   939,
     940,   870,   941,   872,   942,   943,   975,   873,   944,  1169,
    1170,  1171,  1172,  1173,   945,   874,  1174,  1175,   875,   977,
    1176,  1177,  1178,   876,   978,  1179,   877,  1180,  1181,  1182,
     878,  1183,   879,  1184,  1185,   979,   880,  1186,   980,   981,
     881,   982,   882,  1187,   883,   884,   885,   886,   976,   887,
     888,   889,   890,   891,   892,   893,   894,   895,   896,   897,
     898,   899,   984,   986,   989,   900,   901,   902,   990,   991,
    1007,   925,   948,  1008,   949,   950,   951,   952,  1010,  1011,
     953,  1012,  1014,  1016,  1017,  1018,   954,  1044,  1046,  1048,
     955,   956,   957,   958,   959,   960,   961,  1194,   962,  1093,
     968,   316,   969,   970,   971,   972,  1235,   973,   974,   983,
    1122,   987,  1238,   985,  1195,   988,   994,  1134,   995,  1005,
    1006,   512,  1141,  1015,  1009,  1013,  1019,  1020,  1021,  1022,
    1023,  1024,  1025,  1026,  1027,  1274,  1028,  1029,  1030,  1255,
    1031,  1032,  1033,  1034,  1039,  1040,  1041,  1042,  1043,  1269,
    1268,  1236,  1253,  1047,  1045,  1050,  1051,  1049,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1133,  1066,  1067,
    1068,  1069,  1070,   728,  1271,   740,  1071,  1072,  1073,   763,
    1074,   799,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1270,
    1251,  1088,  1254,   804,   404,   733,  1252,  1089,   757,   659,
     573,   469,  1090,  1091,  1092,  1228,  1103,  1104,  1116,  1117,
    1118,  1119,  1120,  1121,  1125,  1131,  1227,  1132,  1136,   336,
       0,  1142,  1137,  1139,  1143,  1165,  1166,  1167,     0,  1190,
    1191,  1192,  1193,  1196,  1209,  1210,  1237,     0,     0,  1242,
    1239,  1256,  1266,  1267,   518,     0,     0,     0,     0,     0,
       0,   648,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   652,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   592,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   632
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-784))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     461,   321,   322,     1,     1,     1,     1,   112,    62,   329,
     244,   245,     1,     1,     1,     1,     1,     1,     1,     1,
       1,   246,     1,     1,     1,     1,     1,   246,    23,   246,
       1,   814,   815,   816,   817,   818,    20,   244,    27,    28,
     246,   248,   246,     1,    33,   246,    35,    42,   246,    30,
     246,    46,    34,   246,    13,    14,    15,     1,    46,    40,
     246,     1,   244,     1,     1,    47,   248,   244,   244,   244,
       1,   248,   248,   248,     1,   246,    10,   246,    12,    67,
      62,    63,    64,    65,    72,    72,     1,    72,   246,     1,
      79,    80,    23,    72,   246,   415,   416,    86,    87,    88,
      82,    72,   246,   423,   102,   425,   102,     1,    20,   244,
     215,    42,   432,   248,   244,    46,   102,   437,   248,   108,
     109,   102,   106,   246,   102,   102,   102,   102,   448,   449,
       1,   451,   127,   246,   123,   124,    30,     8,     9,   459,
     460,   136,   137,   463,   132,   134,    40,    18,   135,   135,
     246,   135,   206,   112,   143,    26,   135,   211,   102,   135,
     100,    32,   246,   244,   102,    36,    37,   248,    39,   630,
     168,   102,   168,   100,    45,     1,   171,   135,   246,   244,
      51,    52,   168,   248,    55,    56,    57,   102,   128,   244,
      61,   168,   168,   168,   106,    66,   127,   247,   135,    70,
      71,   128,   247,    74,    30,   244,    77,    78,   102,   248,
     168,   247,   244,   244,    85,   146,   248,   248,   963,   964,
     965,    92,    93,   135,    95,    96,    97,    98,    99,   247,
     168,   168,   230,   553,   247,   230,   244,   244,   235,   110,
     248,   248,    68,   232,   233,   234,   243,   118,   119,   120,
     245,   122,   235,   168,   125,   126,   245,   245,   129,   245,
     243,   245,   245,   245,   245,   242,   245,   242,     1,   140,
     245,     1,   230,   247,   245,   247,   102,   211,   104,   105,
     247,   212,   178,   179,   247,   178,   179,   245,    21,    22,
     224,   247,    25,   230,   165,   151,   152,   247,   169,   230,
     620,   245,   173,   174,   175,   176,   177,   245,   628,   629,
     181,   182,   151,   152,   245,   230,    46,   247,   245,   145,
     191,   147,   148,   149,   150,   199,   200,     1,   247,     3,
     245,   247,     6,   247,   247,   244,   247,    67,   164,   247,
     247,   247,    72,   247,   247,   112,   247,   247,   247,    23,
     247,   222,   223,   243,   225,   247,    89,    90,    91,   247,
     231,    94,   247,   247,   190,   236,   247,   247,    42,   102,
     241,   247,    46,   133,   245,   247,   202,   247,   247,     1,
     247,   114,   115,   247,   247,   247,     8,     9,   155,   156,
     157,   158,   159,    67,   247,    69,    18,   130,   131,   247,
     247,   247,   132,   247,    26,   247,   247,    81,   244,   247,
      32,   237,   238,    50,    36,    37,   247,    39,   247,   245,
     247,   133,   247,    45,   247,   247,   247,   160,   102,    51,
      52,   247,     1,    55,    56,    57,    73,   247,    75,    61,
     247,   247,   247,   247,    66,   247,   247,   247,    70,    71,
     247,   247,    74,   247,   247,    77,    78,   247,   132,   247,
       1,    30,     3,    85,   247,     6,   247,   247,   247,   247,
      92,    93,   247,    95,    96,    97,    98,    99,   247,   247,
     117,   247,    23,   247,     1,   247,   247,   161,   110,   247,
     247,   244,   247,   247,   133,   247,   118,   119,   120,    68,
     122,    42,   247,   125,   126,    46,    23,   129,   247,    75,
     247,   247,   245,   247,   112,   247,   190,     1,   140,   247,
       5,   247,   247,   247,   247,    42,    67,   247,    69,    46,
     247,   244,   112,   102,   178,   104,   105,   178,   112,    23,
      81,   112,   112,   165,   112,   178,    31,   169,   178,   112,
     178,   173,   174,   175,   176,   177,   193,   194,    42,   181,
     182,   102,    46,   237,   178,    50,   178,   178,   178,   191,
     247,   245,   244,    58,   244,   244,   145,   133,   147,   148,
     149,   150,   247,   247,   247,   102,   247,   153,   247,   247,
      75,   132,   247,   230,   247,   164,   247,   247,     1,   247,
     222,   223,   247,   225,   247,   247,   244,   247,   112,   231,
     127,   247,   247,   247,   236,   100,   247,   178,   184,   241,
     161,   190,   107,   247,    27,    28,   247,   247,   194,   146,
      33,   247,    35,   202,   247,   201,   121,   112,   247,   247,
      75,   247,   247,   127,   178,   178,   133,   178,   214,   190,
     216,   217,   136,   137,   139,   178,   141,   142,    19,   112,
     112,   112,   178,   229,     1,   178,   178,   133,   237,   238,
     178,   112,   112,   239,   112,   112,    79,    80,  1139,   133,
     112,   112,    43,    86,    87,    88,   178,   171,     0,     1,
     178,   112,    53,     5,   247,   212,   237,    34,   178,    60,
     247,   178,   178,   133,   178,   108,   109,   178,    20,   194,
      47,    23,    24,   230,   178,    76,   178,    29,   153,   204,
     123,   124,   178,   208,   244,    62,    63,    64,    65,   214,
     178,   134,    44,   218,   178,   220,    48,    49,   244,   178,
     143,   244,   103,   244,   229,    82,   230,    59,    62,   184,
     111,   247,   247,   247,   239,   178,     1,   247,   247,   194,
     246,    73,   133,   133,   247,   247,   201,   178,   247,   247,
     178,    83,    84,   178,   247,   247,    21,    22,   247,   214,
      25,   216,   217,   244,   244,   133,   244,    62,   247,   101,
     247,   178,   247,   154,   229,   178,   178,   247,   247,   133,
     247,   247,   247,   133,   239,   117,   133,   133,   244,   133,
     133,   172,   133,   247,   133,   133,    62,   112,   133,   244,
     133,   247,   244,   247,   244,   133,   244,   244,   247,   232,
     233,   234,   244,   112,   244,   244,   112,   244,   244,   112,
     244,   153,   244,   244,    89,    90,    91,   244,   244,    94,
     162,   163,   244,   244,   166,   167,   244,   102,   244,   244,
     244,   112,   112,   244,   244,   244,   244,   133,   112,   114,
     115,   185,   186,   187,   188,   189,   112,   112,   192,   193,
     244,   133,   196,   197,   198,   130,   131,   201,   178,   203,
     204,   205,   133,   207,   247,   209,   210,   112,   244,   213,
     133,   133,   133,   133,   133,   219,   133,   133,   133,   221,
     185,   186,   187,   188,   189,   160,   133,   192,   193,   244,
     133,   196,   197,   198,   244,   133,   201,   244,   203,   204,
     205,   247,   207,   244,   209,   210,   133,   244,   213,   185,
     186,   187,   188,   189,   219,   244,   192,   193,   244,   247,
     196,   197,   198,   244,   133,   201,   244,   203,   204,   205,
     244,   207,   244,   209,   210,   112,   244,   213,   133,   133,
     244,   133,   244,   219,   244,   244,   244,   244,   178,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   133,   133,   133,   244,   244,   244,   133,   112,
     133,   244,   244,   178,   244,   244,   244,   244,   133,   133,
     244,   133,   133,   133,   133,   133,   244,   133,   133,   133,
     244,   244,   244,   244,   244,   244,   244,  1036,   244,   138,
     244,    71,   244,   244,   244,   244,   112,   244,   244,   244,
     138,   244,   133,   247,  1038,   247,   244,   248,   244,   244,
     244,   240,  1000,   244,   247,   247,   244,   244,   244,   244,
     244,   244,   244,   244,   244,  1273,   244,   244,   244,  1234,
     244,   244,   244,   244,   244,   244,   244,   244,   244,  1246,
    1244,  1134,  1230,   244,   247,   244,   244,   247,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   183,   244,   244,
     244,   244,   244,   479,  1250,   504,   244,   244,   244,   542,
     244,   578,   244,   244,   244,   244,   244,   244,   244,  1248,
    1224,   244,  1232,   586,   120,   494,  1226,   244,   528,   410,
     287,   179,   244,   244,   244,  1099,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,  1097,   244,   244,    95,
      -1,   244,   247,   247,   244,   244,   244,   244,    -1,   244,
     244,   244,   244,   244,   244,   244,   244,    -1,    -1,   244,
     247,   244,   244,   244,   248,    -1,    -1,    -1,    -1,    -1,
      -1,   380,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   262,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   398,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   308,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   351
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   250,     0,     1,     5,    20,    23,    24,    29,    44,
      48,    49,    59,    73,    83,    84,   101,   117,   153,   162,
     163,   166,   167,   221,   251,   256,   261,   283,   289,   303,
     321,   338,   352,   367,   374,   378,   388,   397,   417,   427,
     433,   437,   447,   510,   531,   244,   245,   246,   246,   322,
     398,   428,   246,   438,   246,   353,   418,   339,   246,   246,
     304,   368,   246,   246,   379,   389,   246,     1,    30,    40,
     102,   284,   285,   286,   287,   288,     1,    27,    28,    33,
      35,    79,    80,    86,    87,    88,   108,   109,   123,   124,
     134,   143,   232,   233,   234,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   246,   246,   246,     1,    72,
     434,   435,   436,   246,     1,     8,     9,    18,    26,    32,
      36,    37,    39,    45,    51,    52,    55,    56,    57,    61,
      66,    70,    71,    74,    77,    78,    85,    92,    93,    95,
      96,    97,    98,    99,   110,   118,   119,   120,   122,   125,
     126,   129,   140,   165,   169,   173,   174,   175,   176,   177,
     181,   182,   191,   222,   223,   225,   231,   236,   241,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     502,   506,   507,   508,   509,   246,   246,   246,     1,   235,
     290,   291,   292,   293,   294,     1,   100,   128,   257,   258,
     259,   260,   246,   246,     1,    34,    47,    62,    63,    64,
      65,    82,   532,   533,   534,   535,   536,   537,   538,   539,
     540,     1,    30,    68,   102,   104,   105,   145,   147,   148,
     149,   150,   164,   190,   202,   237,   238,   262,   263,   264,
     265,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   246,   246,     1,   102,   375,   376,
     377,   244,   247,   247,   247,   245,   285,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   245,   512,     1,    21,    22,
      25,    89,    90,    91,    94,   102,   114,   115,   130,   131,
     160,   323,   324,   325,   326,   327,   328,   329,   330,   331,
     332,   333,   334,   335,   336,   337,     1,     3,     6,    23,
      42,    46,    67,    69,    81,   102,   132,   161,   190,   237,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   408,
     412,   413,   414,   415,   416,     1,    72,   135,   429,   430,
     431,   432,   247,   245,   435,     1,   102,   135,   168,   439,
     443,   444,   445,   446,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   503,   247,   499,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   245,   449,
       1,    23,    42,    46,   127,   136,   137,   171,   230,   354,
     355,   356,   357,   358,   359,   360,   364,   365,   366,     1,
     135,   168,   230,   419,   423,   424,   425,   426,     1,    46,
      67,    72,   132,   340,   344,   345,   346,   350,   351,   244,
     247,   245,   291,   243,   244,   247,   247,   245,   258,     1,
      23,    42,    46,   102,   127,   146,   212,   230,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   317,     1,    20,
     106,   135,   369,   370,   371,   372,   373,   247,   247,   247,
     247,   247,   247,   247,   245,   533,   244,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   245,   263,     1,   102,   168,   230,   380,   381,
     382,   383,   384,     1,   102,   168,   390,   391,   392,   393,
     247,   245,   376,   133,   133,   133,   244,   112,   112,   178,
     178,   112,   253,   253,   112,   112,   112,   178,   178,   112,
     253,   178,   178,   178,   178,   178,   244,   244,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   245,   324,   244,   247,   247,   247,   247,   409,   247,
     247,   247,   247,   247,   247,   247,   247,   245,   400,   247,
     247,   245,   430,   133,   244,   247,   247,   440,   245,   444,
     178,   253,   253,   112,   178,   178,   112,   133,   178,   253,
     178,   253,   112,   112,   112,   178,   178,   178,   253,   133,
     178,   112,   112,   253,   112,   112,   133,   112,   112,   178,
     178,   247,   178,   247,   253,   253,   178,   253,   178,   178,
     178,   178,   179,   178,   179,   178,   178,   253,   253,   112,
     255,   133,   253,   178,   178,   178,   178,   244,   244,   247,
     247,   361,   247,   247,   247,   247,   247,   245,   355,   247,
     420,   247,   245,   424,   244,   341,   247,   247,   247,   245,
     345,   178,   244,   246,   133,   133,   244,   244,   247,   247,
     318,   247,   247,   247,   314,   247,   245,   306,   244,   247,
     247,   247,   245,   370,   178,   178,   178,   133,   178,   178,
     253,   244,   133,   178,   133,   133,   133,   133,   133,   133,
     151,   152,   266,   267,   151,   152,   268,   269,   133,   133,
     112,   133,   133,   244,   244,   247,   385,   247,   245,   381,
     244,   247,   394,   245,   391,   133,   244,   244,   244,   244,
     244,   244,   244,   244,   155,   156,   157,   158,   159,   252,
     253,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   112,   112,   253,   112,   112,
     112,   112,   133,   112,   112,   253,   253,   255,   244,   133,
     199,   200,   133,   178,   247,   133,   133,   133,   133,   112,
     133,   133,   133,   244,   133,   133,   244,   244,   133,   133,
     247,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,    62,   185,   186,   187,   188,   189,   192,
     193,   196,   197,   198,   201,   203,   204,   205,   207,   209,
     210,   213,   219,   504,   505,   244,    62,   185,   186,   187,
     188,   189,   192,   193,   196,   197,   198,   201,   203,   204,
     205,   207,   209,   210,   213,   219,   500,   501,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,    13,    14,    15,   254,   255,   244,   244,
     244,   244,   244,   244,   244,   133,   178,   247,   133,   112,
     133,   133,   133,   244,   133,   247,   133,   244,   247,   133,
     133,   112,   348,   349,   244,   244,     1,   102,   168,   242,
     295,   296,   297,   298,   299,   244,   244,   133,   178,   247,
     133,   133,   133,   247,   133,   244,   133,   133,   133,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   248,   244,   248,   244,
     244,   244,   244,   244,   133,   247,   133,   244,   133,   247,
     244,   244,   252,   252,   252,   252,   252,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,    10,    12,   211,   224,   410,
     411,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   138,   441,   442,   244,   248,   244,   248,
     254,   254,   254,   244,   244,    19,    43,    53,    60,    76,
     103,   111,   154,   172,   362,   363,   244,   244,   244,   244,
     244,   244,   138,   421,   422,   244,    62,   206,   211,   342,
     343,   244,   244,   183,   248,   347,   244,   247,   300,   247,
     245,   296,   244,   244,     5,    31,    50,    58,    75,   100,
     107,   121,   139,   141,   142,   194,   204,   208,   214,   218,
     220,   229,   239,   319,   320,   244,   244,   244,    62,   185,
     186,   187,   188,   189,   192,   193,   196,   197,   198,   201,
     203,   204,   205,   207,   209,   210,   213,   219,   315,   316,
     244,   244,   244,   244,   267,   269,   244,    75,   153,   184,
     194,   201,   214,   216,   217,   229,   239,   386,   387,   244,
     244,    75,   153,   184,   194,   201,   214,   216,   217,   229,
     239,   395,   396,   244,   248,   244,   248,   505,   501,   244,
     248,   244,   248,   244,   248,   112,   349,   244,   133,   247,
     215,   255,   244,   244,   248,   244,   248,   244,   248,   244,
     248,   411,   442,   363,   422,   343,   244,    50,    73,    75,
     117,   193,   194,   230,   301,   302,   244,   244,   320,   316,
     387,   396,   244,   248,   302
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


#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (YYID (N))                                                     \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (YYID (0))
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])



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
  switch (yytype)
    {
      default:
	break;
    }
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
  YYSIZE_T yysize1;
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
                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

  switch (yytype)
    {

      default:
	break;
    }
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  *++yyvsp = yylval;

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

/* Line 1788 of yacc.c  */
#line 386 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1788 of yacc.c  */
#line 388 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1788 of yacc.c  */
#line 392 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1788 of yacc.c  */
#line 396 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1788 of yacc.c  */
#line 400 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1788 of yacc.c  */
#line 404 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1788 of yacc.c  */
#line 408 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1788 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1788 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1788 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1788 of yacc.c  */
#line 416 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1788 of yacc.c  */
#line 417 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1788 of yacc.c  */
#line 431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:

/* Line 1788 of yacc.c  */
#line 437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:

/* Line 1788 of yacc.c  */
#line 462 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:

/* Line 1788 of yacc.c  */
#line 468 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:

/* Line 1788 of yacc.c  */
#line 477 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:

/* Line 1788 of yacc.c  */
#line 483 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:

/* Line 1788 of yacc.c  */
#line 491 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
}
    break;

  case 78:

/* Line 1788 of yacc.c  */
#line 530 "conf_parser.y"
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

    DupString(ServerInfo.rsa_private_key_file, yylval.string);

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
    {
      yyerror("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      yyerror("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      yyerror("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 79:

/* Line 1788 of yacc.c  */
#line 589 "conf_parser.y"
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
          ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 80:

/* Line 1788 of yacc.c  */
#line 617 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:

/* Line 1788 of yacc.c  */
#line 625 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 82:

/* Line 1788 of yacc.c  */
#line 640 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 83:

/* Line 1788 of yacc.c  */
#line 655 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:

/* Line 1788 of yacc.c  */
#line 664 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 85:

/* Line 1788 of yacc.c  */
#line 678 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:

/* Line 1788 of yacc.c  */
#line 687 "conf_parser.y"
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

  case 87:

/* Line 1788 of yacc.c  */
#line 715 "conf_parser.y"
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

  case 88:

/* Line 1788 of yacc.c  */
#line 745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    recalc_fdlimit(NULL);

    if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 89:

/* Line 1788 of yacc.c  */
#line 768 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:

/* Line 1788 of yacc.c  */
#line 783 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:

/* Line 1788 of yacc.c  */
#line 792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:

/* Line 1788 of yacc.c  */
#line 801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:

/* Line 1788 of yacc.c  */
#line 819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:

/* Line 1788 of yacc.c  */
#line 825 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:

/* Line 1788 of yacc.c  */
#line 830 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:

/* Line 1788 of yacc.c  */
#line 842 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:

/* Line 1788 of yacc.c  */
#line 847 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:

/* Line 1788 of yacc.c  */
#line 850 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:

/* Line 1788 of yacc.c  */
#line 855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:

/* Line 1788 of yacc.c  */
#line 862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:

/* Line 1788 of yacc.c  */
#line 866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:

/* Line 1788 of yacc.c  */
#line 870 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:

/* Line 1788 of yacc.c  */
#line 874 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:

/* Line 1788 of yacc.c  */
#line 878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:

/* Line 1788 of yacc.c  */
#line 882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:

/* Line 1788 of yacc.c  */
#line 886 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:

/* Line 1788 of yacc.c  */
#line 896 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(OPER_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    SetConfEncrypted(yy_aconf); /* Yes, the default is encrypted */
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 130:

/* Line 1788 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;
    dlink_node *ptr;
    dlink_node *next_ptr;

    conf_add_class_to_conf(yy_conf, class_name);

    /* Now, make sure there is a copy of the "base" given oper
     * block in each of the collected copies
     */

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = make_conf_item(OPER_TYPE);
      new_aconf = (struct AccessItem *)map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_aconf->user, yy_tmp->user);
      else
	DupString(new_aconf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_aconf->host, yy_tmp->host);
      else
	DupString(new_aconf->host, "*");

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->addr,
                                     &new_aconf->bits);

      conf_add_class_to_conf(new_conf, class_name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->port = yy_aconf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_aconf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_aconf->rsa_public_key_file,
		  yy_aconf->rsa_public_key_file);

        file = BIO_new_file(yy_aconf->rsa_public_key_file, "r");
        new_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_aconf->rsa_public_key)
	  && yy_tmp->host)
#else
      if (yy_tmp->name && yy_tmp->passwd && yy_tmp->host)
#endif
      {
        conf_add_class_to_conf(new_conf, class_name);
	if (yy_tmp->name != NULL)
	  DupString(new_conf->name, yy_tmp->name);
      }

      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    yy_conf = NULL;
    yy_aconf = NULL;


    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 142:

/* Line 1788 of yacc.c  */
#line 999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:

/* Line 1788 of yacc.c  */
#line 1008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->addr,
                                    &yy_aconf->bits);
    }
    else
    {
      struct CollectItem *yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 144:

/* Line 1788 of yacc.c  */
#line 1045 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 145:

/* Line 1788 of yacc.c  */
#line 1057 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 146:

/* Line 1788 of yacc.c  */
#line 1068 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file;

    if (yy_aconf->rsa_public_key != NULL)
    {
      RSA_free(yy_aconf->rsa_public_key);
      yy_aconf->rsa_public_key = NULL;
    }

    if (yy_aconf->rsa_public_key_file != NULL)
    {
      MyFree(yy_aconf->rsa_public_key_file);
      yy_aconf->rsa_public_key_file = NULL;
    }

    DupString(yy_aconf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = (RSA *)PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_aconf->rsa_public_key == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);
  }
#endif /* HAVE_LIBCRYPTO */
}
    break;

  case 147:

/* Line 1788 of yacc.c  */
#line 1110 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:

/* Line 1788 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:

/* Line 1788 of yacc.c  */
#line 1126 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:

/* Line 1788 of yacc.c  */
#line 1130 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:

/* Line 1788 of yacc.c  */
#line 1134 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:

/* Line 1788 of yacc.c  */
#line 1138 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:

/* Line 1788 of yacc.c  */
#line 1142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:

/* Line 1788 of yacc.c  */
#line 1146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:

/* Line 1788 of yacc.c  */
#line 1150 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:

/* Line 1788 of yacc.c  */
#line 1154 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:

/* Line 1788 of yacc.c  */
#line 1158 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:

/* Line 1788 of yacc.c  */
#line 1162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:

/* Line 1788 of yacc.c  */
#line 1166 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:

/* Line 1788 of yacc.c  */
#line 1170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:

/* Line 1788 of yacc.c  */
#line 1174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:

/* Line 1788 of yacc.c  */
#line 1178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:

/* Line 1788 of yacc.c  */
#line 1182 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:

/* Line 1788 of yacc.c  */
#line 1186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:

/* Line 1788 of yacc.c  */
#line 1190 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:

/* Line 1788 of yacc.c  */
#line 1194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:

/* Line 1788 of yacc.c  */
#line 1198 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:

/* Line 1788 of yacc.c  */
#line 1202 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:

/* Line 1788 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:

/* Line 1788 of yacc.c  */
#line 1215 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:

/* Line 1788 of yacc.c  */
#line 1219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:

/* Line 1788 of yacc.c  */
#line 1223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:

/* Line 1788 of yacc.c  */
#line 1227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:

/* Line 1788 of yacc.c  */
#line 1231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:

/* Line 1788 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:

/* Line 1788 of yacc.c  */
#line 1239 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:

/* Line 1788 of yacc.c  */
#line 1243 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:

/* Line 1788 of yacc.c  */
#line 1247 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:

/* Line 1788 of yacc.c  */
#line 1251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:

/* Line 1788 of yacc.c  */
#line 1255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:

/* Line 1788 of yacc.c  */
#line 1259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:

/* Line 1788 of yacc.c  */
#line 1263 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:

/* Line 1788 of yacc.c  */
#line 1267 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:

/* Line 1788 of yacc.c  */
#line 1271 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:

/* Line 1788 of yacc.c  */
#line 1275 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:

/* Line 1788 of yacc.c  */
#line 1279 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:

/* Line 1788 of yacc.c  */
#line 1283 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:

/* Line 1788 of yacc.c  */
#line 1287 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:

/* Line 1788 of yacc.c  */
#line 1297 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:

/* Line 1788 of yacc.c  */
#line 1304 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, NULL, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        int user_count = 0;

        rebuild_cidr_class(cconf, yy_class);

        class = map_to_conf(cconf);

        user_count = class->curr_user_count;
        memcpy(class, yy_class, sizeof(*class));
        class->curr_user_count = user_count;
        class->active = 1;

        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
        yy_class->active = 1;
      }
    }

    yy_class_name = NULL;
  }
}
    break;

  case 213:

/* Line 1788 of yacc.c  */
#line 1362 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:

/* Line 1788 of yacc.c  */
#line 1371 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1788 of yacc.c  */
#line 1377 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1788 of yacc.c  */
#line 1383 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1788 of yacc.c  */
#line 1389 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1788 of yacc.c  */
#line 1395 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1788 of yacc.c  */
#line 1401 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1788 of yacc.c  */
#line 1407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1788 of yacc.c  */
#line 1413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1788 of yacc.c  */
#line 1419 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1788 of yacc.c  */
#line 1425 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1788 of yacc.c  */
#line 1431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1788 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1788 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:

/* Line 1788 of yacc.c  */
#line 1453 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:

/* Line 1788 of yacc.c  */
#line 1462 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:

/* Line 1788 of yacc.c  */
#line 1468 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:

/* Line 1788 of yacc.c  */
#line 1472 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:

/* Line 1788 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:

/* Line 1788 of yacc.c  */
#line 1486 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:

/* Line 1788 of yacc.c  */
#line 1491 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), listener_address, listener_flags);
  }
}
    break;

  case 247:

/* Line 1788 of yacc.c  */
#line 1505 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, listener_address, listener_flags);
  }
}
    break;

  case 248:

/* Line 1788 of yacc.c  */
#line 1525 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:

/* Line 1788 of yacc.c  */
#line 1534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:

/* Line 1788 of yacc.c  */
#line 1546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLIENT_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 251:

/* Line 1788 of yacc.c  */
#line 1558 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_aconf->user && yy_aconf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_aconf);
    }
    else
      delete_conf_item(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      new_conf = make_conf_item(CLIENT_TYPE);
      new_aconf = map_to_conf(new_conf);

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_aconf->passwd != NULL)
        DupString(new_aconf->passwd, yy_aconf->passwd);

      new_aconf->flags = yy_aconf->flags;
      new_aconf->port  = yy_aconf->port;

      DupString(new_aconf->user, yy_tmp->user);
      collapse(new_aconf->user);

      DupString(new_aconf->host, yy_tmp->host);
      collapse(new_aconf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_aconf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 263:

/* Line 1788 of yacc.c  */
#line 1620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    if (yy_aconf->user == NULL)
    {
      DupString(yy_aconf->user, userbuf);
      DupString(yy_aconf->host, hostbuf);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));

      DupString(yy_tmp->user, userbuf);
      DupString(yy_tmp->host, hostbuf);

      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 264:

/* Line 1788 of yacc.c  */
#line 1655 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 265:

/* Line 1788 of yacc.c  */
#line 1668 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:

/* Line 1788 of yacc.c  */
#line 1677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 267:

/* Line 1788 of yacc.c  */
#line 1688 "conf_parser.y"
    {
}
    break;

  case 271:

/* Line 1788 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:

/* Line 1788 of yacc.c  */
#line 1697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:

/* Line 1788 of yacc.c  */
#line 1701 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:

/* Line 1788 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:

/* Line 1788 of yacc.c  */
#line 1709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:

/* Line 1788 of yacc.c  */
#line 1713 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:

/* Line 1788 of yacc.c  */
#line 1717 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:

/* Line 1788 of yacc.c  */
#line 1721 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:

/* Line 1788 of yacc.c  */
#line 1725 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:

/* Line 1788 of yacc.c  */
#line 1732 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 281:

/* Line 1788 of yacc.c  */
#line 1751 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 282:

/* Line 1788 of yacc.c  */
#line 1761 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:

/* Line 1788 of yacc.c  */
#line 1774 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:

/* Line 1788 of yacc.c  */
#line 1781 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:

/* Line 1788 of yacc.c  */
#line 1793 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:

/* Line 1788 of yacc.c  */
#line 1802 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = "No reason";

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
}
    break;

  case 293:

/* Line 1788 of yacc.c  */
#line 1817 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:

/* Line 1788 of yacc.c  */
#line 1835 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      yy_conf = make_conf_item(SERVICE_TYPE);
      DupString(yy_conf->name, yylval.string);
    }
  }
}
    break;

  case 300:

/* Line 1788 of yacc.c  */
#line 1850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 301:

/* Line 1788 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:

/* Line 1788 of yacc.c  */
#line 1869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:

/* Line 1788 of yacc.c  */
#line 1878 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);

    DupString(yy_match_item->user, userbuf);
    DupString(yy_match_item->host, hostbuf);
  }
}
    break;

  case 310:

/* Line 1788 of yacc.c  */
#line 1900 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:

/* Line 1788 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:

/* Line 1788 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:

/* Line 1788 of yacc.c  */
#line 1915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:

/* Line 1788 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:

/* Line 1788 of yacc.c  */
#line 1923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1788 of yacc.c  */
#line 1927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:

/* Line 1788 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:

/* Line 1788 of yacc.c  */
#line 1935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:

/* Line 1788 of yacc.c  */
#line 1939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:

/* Line 1788 of yacc.c  */
#line 1943 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:

/* Line 1788 of yacc.c  */
#line 1952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:

/* Line 1788 of yacc.c  */
#line 1959 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 331:

/* Line 1788 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:

/* Line 1788 of yacc.c  */
#line 1978 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:

/* Line 1788 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:

/* Line 1788 of yacc.c  */
#line 1989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:

/* Line 1788 of yacc.c  */
#line 1993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:

/* Line 1788 of yacc.c  */
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:

/* Line 1788 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:

/* Line 1788 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:

/* Line 1788 of yacc.c  */
#line 2009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:

/* Line 1788 of yacc.c  */
#line 2013 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:

/* Line 1788 of yacc.c  */
#line 2017 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:

/* Line 1788 of yacc.c  */
#line 2021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:

/* Line 1788 of yacc.c  */
#line 2030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = map_to_conf(yy_conf);

    /* defaults */
    yy_aconf->port = PORTNUM;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 347:

/* Line 1788 of yacc.c  */
#line 2045 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_aconf->host && yy_aconf->passwd && yy_aconf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
        delete_conf_item(yy_conf);
    }
    else
    {
      if (yy_conf->name != NULL)
      {
        if (yy_aconf->host == NULL)
          yyerror("Ignoring connect block -- missing host");
        else if (!yy_aconf->passwd || !yy_aconf->spasswd)
          yyerror("Ignoring connect block -- missing password");
      }

      /* XXX
       * This fixes a try_connections() core (caused by invalid class_ptr
       * pointers) reported by metalrock. That's an ugly fix, but there
       * is currently no better way. The entire config subsystem needs an
       * rewrite ASAP. make_conf_item() shouldn't really add things onto
       * a doubly linked list immediately without any sanity checks!  -Michael
       */
      delete_conf_item(yy_conf);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 364:

/* Line 1788 of yacc.c  */
#line 2089 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:

/* Line 1788 of yacc.c  */
#line 2098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:

/* Line 1788 of yacc.c  */
#line 2107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

      memcpy(&yy_aconf->bind, res->ai_addr, res->ai_addrlen);
      yy_aconf->bind.ss.ss_family = res->ai_family;
      yy_aconf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 367:

/* Line 1788 of yacc.c  */
#line 2133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
}
    break;

  case 368:

/* Line 1788 of yacc.c  */
#line 2151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
}
    break;

  case 369:

/* Line 1788 of yacc.c  */
#line 2169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:

/* Line 1788 of yacc.c  */
#line 2175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:

/* Line 1788 of yacc.c  */
#line 2179 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:

/* Line 1788 of yacc.c  */
#line 2187 "conf_parser.y"
    {
}
    break;

  case 376:

/* Line 1788 of yacc.c  */
#line 2192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:

/* Line 1788 of yacc.c  */
#line 2196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:

/* Line 1788 of yacc.c  */
#line 2200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:

/* Line 1788 of yacc.c  */
#line 2204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:

/* Line 1788 of yacc.c  */
#line 2210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 381:

/* Line 1788 of yacc.c  */
#line 2221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 382:

/* Line 1788 of yacc.c  */
#line 2232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 383:

/* Line 1788 of yacc.c  */
#line 2243 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:

/* Line 1788 of yacc.c  */
#line 2252 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->cipher_list);
    DupString(yy_aconf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 385:

/* Line 1788 of yacc.c  */
#line 2270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:

/* Line 1788 of yacc.c  */
#line 2277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_user = NULL;
        void *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
               errptr);
          break;
        }

        yy_aconf = map_to_conf(make_conf_item(RKLINE_TYPE));
        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
        break;
#endif
      }
      else
      {
        find_and_delete_temporary(userbuf, hostbuf, CONF_KLINE);

        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KLINE, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 387:

/* Line 1788 of yacc.c  */
#line 2335 "conf_parser.y"
    {
}
    break;

  case 391:

/* Line 1788 of yacc.c  */
#line 2340 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:

/* Line 1788 of yacc.c  */
#line 2349 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = userbuf;
    nuh.hostptr  = hostbuf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(userbuf);
    nuh.hostsize = sizeof(hostbuf);

    split_nuh(&nuh);
  }
}
    break;

  case 399:

/* Line 1788 of yacc.c  */
#line 2368 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:

/* Line 1788 of yacc.c  */
#line 2377 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:

/* Line 1788 of yacc.c  */
#line 2381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      find_and_delete_temporary(NULL, hostbuf, CONF_DLINE);

      yy_aconf = map_to_conf(make_conf_item(DLINE_TYPE));
      DupString(yy_aconf->host, hostbuf);

      if (reasonbuf[0])
        DupString(yy_aconf->reason, reasonbuf);
      else
        DupString(yy_aconf->reason, "No reason");
      add_conf_by_address(CONF_DLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}
    break;

  case 407:

/* Line 1788 of yacc.c  */
#line 2405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:

/* Line 1788 of yacc.c  */
#line 2411 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:

/* Line 1788 of yacc.c  */
#line 2425 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_aconf = map_to_conf(make_conf_item(EXEMPTDLINE_TYPE));
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}
    break;

  case 415:

/* Line 1788 of yacc.c  */
#line 2443 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:

/* Line 1788 of yacc.c  */
#line 2450 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
#ifdef HAVE_LIBPCRE
        void *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: no PCRE support");
        break;
#endif
      }
      else
        yy_conf = make_conf_item(XLINE_TYPE);

      yy_match_item = map_to_conf(yy_conf);
      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_match_item->reason, reasonbuf);
      else
        DupString(yy_match_item->reason, "No reason");
    }
  }
}
    break;

  case 417:

/* Line 1788 of yacc.c  */
#line 2490 "conf_parser.y"
    {
}
    break;

  case 421:

/* Line 1788 of yacc.c  */
#line 2495 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:

/* Line 1788 of yacc.c  */
#line 2504 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:

/* Line 1788 of yacc.c  */
#line 2510 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 488:

/* Line 1788 of yacc.c  */
#line 2556 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:

/* Line 1788 of yacc.c  */
#line 2561 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 490:

/* Line 1788 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:

/* Line 1788 of yacc.c  */
#line 2573 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1788 of yacc.c  */
#line 2579 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:

/* Line 1788 of yacc.c  */
#line 2584 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:

/* Line 1788 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 495:

/* Line 1788 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 496:

/* Line 1788 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 497:

/* Line 1788 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:

/* Line 1788 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 499:

/* Line 1788 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 500:

/* Line 1788 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 501:

/* Line 1788 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 502:

/* Line 1788 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 503:

/* Line 1788 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 504:

/* Line 1788 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1788 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1788 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:

/* Line 1788 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:

/* Line 1788 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:

/* Line 1788 of yacc.c  */
#line 2665 "conf_parser.y"
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

/* Line 1788 of yacc.c  */
#line 2676 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 511:

/* Line 1788 of yacc.c  */
#line 2681 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 512:

/* Line 1788 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 513:

/* Line 1788 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 514:

/* Line 1788 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 515:

/* Line 1788 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 516:

/* Line 1788 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 517:

/* Line 1788 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 518:

/* Line 1788 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 519:

/* Line 1788 of yacc.c  */
#line 2723 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 520:

/* Line 1788 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 521:

/* Line 1788 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1788 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:

/* Line 1788 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 524:

/* Line 1788 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1788 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 526:

/* Line 1788 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 527:

/* Line 1788 of yacc.c  */
#line 2761 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 528:

/* Line 1788 of yacc.c  */
#line 2766 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 529:

/* Line 1788 of yacc.c  */
#line 2771 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 530:

/* Line 1788 of yacc.c  */
#line 2782 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:

/* Line 1788 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:

/* Line 1788 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 533:

/* Line 1788 of yacc.c  */
#line 2797 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 534:

/* Line 1788 of yacc.c  */
#line 2806 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 535:

/* Line 1788 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 536:

/* Line 1788 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 537:

/* Line 1788 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 538:

/* Line 1788 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 542:

/* Line 1788 of yacc.c  */
#line 2836 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 543:

/* Line 1788 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 544:

/* Line 1788 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 545:

/* Line 1788 of yacc.c  */
#line 2845 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 546:

/* Line 1788 of yacc.c  */
#line 2848 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 547:

/* Line 1788 of yacc.c  */
#line 2851 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 548:

/* Line 1788 of yacc.c  */
#line 2854 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 549:

/* Line 1788 of yacc.c  */
#line 2857 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 550:

/* Line 1788 of yacc.c  */
#line 2860 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 551:

/* Line 1788 of yacc.c  */
#line 2863 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 552:

/* Line 1788 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 553:

/* Line 1788 of yacc.c  */
#line 2869 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 554:

/* Line 1788 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 555:

/* Line 1788 of yacc.c  */
#line 2875 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 556:

/* Line 1788 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 557:

/* Line 1788 of yacc.c  */
#line 2881 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 558:

/* Line 1788 of yacc.c  */
#line 2884 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 559:

/* Line 1788 of yacc.c  */
#line 2887 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 560:

/* Line 1788 of yacc.c  */
#line 2890 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 561:

/* Line 1788 of yacc.c  */
#line 2893 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 562:

/* Line 1788 of yacc.c  */
#line 2898 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 566:

/* Line 1788 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 567:

/* Line 1788 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 568:

/* Line 1788 of yacc.c  */
#line 2910 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 569:

/* Line 1788 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 570:

/* Line 1788 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 571:

/* Line 1788 of yacc.c  */
#line 2919 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 572:

/* Line 1788 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 573:

/* Line 1788 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 574:

/* Line 1788 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 575:

/* Line 1788 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 576:

/* Line 1788 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 577:

/* Line 1788 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 578:

/* Line 1788 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 579:

/* Line 1788 of yacc.c  */
#line 2943 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 580:

/* Line 1788 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 581:

/* Line 1788 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 582:

/* Line 1788 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 583:

/* Line 1788 of yacc.c  */
#line 2955 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 584:

/* Line 1788 of yacc.c  */
#line 2958 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 585:

/* Line 1788 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 586:

/* Line 1788 of yacc.c  */
#line 2966 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:

/* Line 1788 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:

/* Line 1788 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:

/* Line 1788 of yacc.c  */
#line 2981 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:

/* Line 1788 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 613:

/* Line 1788 of yacc.c  */
#line 3010 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 614:

/* Line 1788 of yacc.c  */
#line 3015 "conf_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 615:

/* Line 1788 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 616:

/* Line 1788 of yacc.c  */
#line 3025 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 617:

/* Line 1788 of yacc.c  */
#line 3030 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 618:

/* Line 1788 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:

/* Line 1788 of yacc.c  */
#line 3040 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:

/* Line 1788 of yacc.c  */
#line 3045 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:

/* Line 1788 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:

/* Line 1788 of yacc.c  */
#line 3055 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 623:

/* Line 1788 of yacc.c  */
#line 3060 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:

/* Line 1788 of yacc.c  */
#line 3065 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:

/* Line 1788 of yacc.c  */
#line 3070 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:

/* Line 1788 of yacc.c  */
#line 3075 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 627:

/* Line 1788 of yacc.c  */
#line 3080 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 628:

/* Line 1788 of yacc.c  */
#line 3085 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 629:

/* Line 1788 of yacc.c  */
#line 3090 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 641:

/* Line 1788 of yacc.c  */
#line 3109 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 642:

/* Line 1788 of yacc.c  */
#line 3115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 643:

/* Line 1788 of yacc.c  */
#line 3121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 644:

/* Line 1788 of yacc.c  */
#line 3130 "conf_parser.y"
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

  case 645:

/* Line 1788 of yacc.c  */
#line 3144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 646:

/* Line 1788 of yacc.c  */
#line 3150 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 647:

/* Line 1788 of yacc.c  */
#line 3156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1788 of yacc.c  */
#line 7394 "conf_parser.c"
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

  *++yyvsp = yylval;


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



