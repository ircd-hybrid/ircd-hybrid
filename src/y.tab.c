/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     BURST_TOPICWHO = 268,
     BYTES = 269,
     KBYTES = 270,
     MBYTES = 271,
     GBYTES = 272,
     TBYTES = 273,
     CALLER_ID_WAIT = 274,
     CAN_FLOOD = 275,
     CAN_IDLE = 276,
     CHANNEL = 277,
     CIDR_BITLEN_IPV4 = 278,
     CIDR_BITLEN_IPV6 = 279,
     CIPHER_PREFERENCE = 280,
     CLASS = 281,
     COMPRESSED = 282,
     COMPRESSION_LEVEL = 283,
     CONNECT = 284,
     CONNECTFREQ = 285,
     CRYPTLINK = 286,
     DEFAULT_CIPHER_PREFERENCE = 287,
     DEFAULT_FLOODCOUNT = 288,
     DEFAULT_SPLIT_SERVER_COUNT = 289,
     DEFAULT_SPLIT_USER_COUNT = 290,
     DENY = 291,
     DESCRIPTION = 292,
     DIE = 293,
     DISABLE_AUTH = 294,
     DISABLE_FAKE_CHANNELS = 295,
     DISABLE_HIDDEN = 296,
     DISABLE_LOCAL_CHANNELS = 297,
     DISABLE_REMOTE_COMMANDS = 298,
     DOT_IN_IP6_ADDR = 299,
     DOTS_IN_IDENT = 300,
     DURATION = 301,
     EGDPOOL_PATH = 302,
     EMAIL = 303,
     ENABLE = 304,
     ENCRYPTED = 305,
     EXCEED_LIMIT = 306,
     EXEMPT = 307,
     FAILED_OPER_NOTICE = 308,
     FAKENAME = 309,
     IRCD_FLAGS = 310,
     FLATTEN_LINKS = 311,
     FFAILED_OPERLOG = 312,
     FKILLLOG = 313,
     FKLINELOG = 314,
     FGLINELOG = 315,
     FIOERRLOG = 316,
     FOPERLOG = 317,
     FOPERSPYLOG = 318,
     FUSERLOG = 319,
     GECOS = 320,
     GENERAL = 321,
     GLINE = 322,
     GLINES = 323,
     GLINE_EXEMPT = 324,
     GLINE_LOG = 325,
     GLINE_TIME = 326,
     GLINE_MIN_CIDR = 327,
     GLINE_MIN_CIDR6 = 328,
     GLOBAL_KILL = 329,
     IRCD_AUTH = 330,
     NEED_IDENT = 331,
     HAVENT_READ_CONF = 332,
     HIDDEN = 333,
     HIDDEN_ADMIN = 334,
     HIDDEN_NAME = 335,
     HIDDEN_OPER = 336,
     HIDE_SERVER_IPS = 337,
     HIDE_SERVERS = 338,
     HIDE_SPOOF_IPS = 339,
     HOST = 340,
     HUB = 341,
     HUB_MASK = 342,
     IDLETIME = 343,
     IGNORE_BOGUS_TS = 344,
     INVISIBLE_ON_CONNECT = 345,
     IP = 346,
     KILL = 347,
     KILL_CHASE_TIME_LIMIT = 348,
     KLINE = 349,
     KLINE_EXEMPT = 350,
     KLINE_REASON = 351,
     KLINE_WITH_REASON = 352,
     KNOCK_DELAY = 353,
     KNOCK_DELAY_CHANNEL = 354,
     LAZYLINK = 355,
     LEAF_MASK = 356,
     LINKS_DELAY = 357,
     LISTEN = 358,
     T_LOG = 359,
     LOGGING = 360,
     LOG_LEVEL = 361,
     MAX_ACCEPT = 362,
     MAX_BANS = 363,
     MAX_CHANS_PER_USER = 364,
     MAX_GLOBAL = 365,
     MAX_IDENT = 366,
     MAX_LOCAL = 367,
     MAX_NICK_CHANGES = 368,
     MAX_NICK_TIME = 369,
     MAX_NUMBER = 370,
     MAX_TARGETS = 371,
     MESSAGE_LOCALE = 372,
     MIN_NONWILDCARD = 373,
     MIN_NONWILDCARD_SIMPLE = 374,
     MODULE = 375,
     MODULES = 376,
     NAME = 377,
     NEED_PASSWORD = 378,
     NETWORK_DESC = 379,
     NETWORK_NAME = 380,
     NICK = 381,
     NICK_CHANGES = 382,
     NO_CREATE_ON_SPLIT = 383,
     NO_JOIN_ON_SPLIT = 384,
     NO_OPER_FLOOD = 385,
     NO_TILDE = 386,
     NOT = 387,
     NUMBER = 388,
     NUMBER_PER_IDENT = 389,
     NUMBER_PER_CIDR = 390,
     NUMBER_PER_IP = 391,
     NUMBER_PER_IP_GLOBAL = 392,
     OPERATOR = 393,
     OPERS_BYPASS_CALLERID = 394,
     OPER_LOG = 395,
     OPER_ONLY_UMODES = 396,
     OPER_PASS_RESV = 397,
     OPER_SPY_T = 398,
     OPER_UMODES = 399,
     JOIN_FLOOD_COUNT = 400,
     JOIN_FLOOD_TIME = 401,
     PACE_WAIT = 402,
     PACE_WAIT_SIMPLE = 403,
     PASSWORD = 404,
     PATH = 405,
     PING_COOKIE = 406,
     PING_TIME = 407,
     PING_WARNING = 408,
     PORT = 409,
     QSTRING = 410,
     QUIET_ON_BAN = 411,
     REASON = 412,
     REDIRPORT = 413,
     REDIRSERV = 414,
     REGEX_T = 415,
     REHASH = 416,
     TREJECT_HOLD_TIME = 417,
     REMOTE = 418,
     REMOTEBAN = 419,
     RESTRICT_CHANNELS = 420,
     RESTRICTED = 421,
     RSA_PRIVATE_KEY_FILE = 422,
     RSA_PUBLIC_KEY_FILE = 423,
     SSL_CERTIFICATE_FILE = 424,
     RESV = 425,
     RESV_EXEMPT = 426,
     SECONDS = 427,
     MINUTES = 428,
     HOURS = 429,
     DAYS = 430,
     WEEKS = 431,
     SENDQ = 432,
     SEND_PASSWORD = 433,
     SERVERHIDE = 434,
     SERVERINFO = 435,
     SERVLINK_PATH = 436,
     IRCD_SID = 437,
     TKLINE_EXPIRE_NOTICES = 438,
     T_SHARED = 439,
     T_CLUSTER = 440,
     TYPE = 441,
     SHORT_MOTD = 442,
     SILENT = 443,
     SPOOF = 444,
     SPOOF_NOTICE = 445,
     STATS_E_DISABLED = 446,
     STATS_I_OPER_ONLY = 447,
     STATS_K_OPER_ONLY = 448,
     STATS_O_OPER_ONLY = 449,
     STATS_P_OPER_ONLY = 450,
     TBOOL = 451,
     TMASKED = 452,
     T_REJECT = 453,
     TS_MAX_DELTA = 454,
     TS_WARN_DELTA = 455,
     TWODOTS = 456,
     T_ALL = 457,
     T_BOTS = 458,
     T_SOFTCALLERID = 459,
     T_CALLERID = 460,
     T_CCONN = 461,
     T_CLIENT_FLOOD = 462,
     T_DEAF = 463,
     T_DEBUG = 464,
     T_DRONE = 465,
     T_EXTERNAL = 466,
     T_FULL = 467,
     T_INVISIBLE = 468,
     T_IPV4 = 469,
     T_IPV6 = 470,
     T_LOCOPS = 471,
     T_LOGPATH = 472,
     T_L_CRIT = 473,
     T_L_DEBUG = 474,
     T_L_ERROR = 475,
     T_L_INFO = 476,
     T_L_NOTICE = 477,
     T_L_TRACE = 478,
     T_L_WARN = 479,
     T_MAX_CLIENTS = 480,
     T_NCHANGE = 481,
     T_OPERWALL = 482,
     T_REJ = 483,
     T_SERVNOTICE = 484,
     T_SKILL = 485,
     T_SPY = 486,
     T_SSL = 487,
     T_UMODES = 488,
     T_UNAUTH = 489,
     T_UNRESV = 490,
     T_UNXLINE = 491,
     T_WALLOP = 492,
     THROTTLE_TIME = 493,
     TOPICBURST = 494,
     TRUE_NO_OPER_FLOOD = 495,
     TKLINE = 496,
     TXLINE = 497,
     TRESV = 498,
     UNKLINE = 499,
     USER = 500,
     USE_EGD = 501,
     USE_EXCEPT = 502,
     USE_INVEX = 503,
     USE_KNOCK = 504,
     USE_LOGGING = 505,
     USE_WHOIS_ACTUALLY = 506,
     VHOST = 507,
     VHOST6 = 508,
     XLINE = 509,
     WARN = 510,
     WARN_NO_NLINE = 511
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
#define BURST_TOPICWHO 268
#define BYTES 269
#define KBYTES 270
#define MBYTES 271
#define GBYTES 272
#define TBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CAN_IDLE 276
#define CHANNEL 277
#define CIDR_BITLEN_IPV4 278
#define CIDR_BITLEN_IPV6 279
#define CIPHER_PREFERENCE 280
#define CLASS 281
#define COMPRESSED 282
#define COMPRESSION_LEVEL 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CRYPTLINK 286
#define DEFAULT_CIPHER_PREFERENCE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_SPLIT_SERVER_COUNT 289
#define DEFAULT_SPLIT_USER_COUNT 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_AUTH 294
#define DISABLE_FAKE_CHANNELS 295
#define DISABLE_HIDDEN 296
#define DISABLE_LOCAL_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DOT_IN_IP6_ADDR 299
#define DOTS_IN_IDENT 300
#define DURATION 301
#define EGDPOOL_PATH 302
#define EMAIL 303
#define ENABLE 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define FAILED_OPER_NOTICE 308
#define FAKENAME 309
#define IRCD_FLAGS 310
#define FLATTEN_LINKS 311
#define FFAILED_OPERLOG 312
#define FKILLLOG 313
#define FKLINELOG 314
#define FGLINELOG 315
#define FIOERRLOG 316
#define FOPERLOG 317
#define FOPERSPYLOG 318
#define FUSERLOG 319
#define GECOS 320
#define GENERAL 321
#define GLINE 322
#define GLINES 323
#define GLINE_EXEMPT 324
#define GLINE_LOG 325
#define GLINE_TIME 326
#define GLINE_MIN_CIDR 327
#define GLINE_MIN_CIDR6 328
#define GLOBAL_KILL 329
#define IRCD_AUTH 330
#define NEED_IDENT 331
#define HAVENT_READ_CONF 332
#define HIDDEN 333
#define HIDDEN_ADMIN 334
#define HIDDEN_NAME 335
#define HIDDEN_OPER 336
#define HIDE_SERVER_IPS 337
#define HIDE_SERVERS 338
#define HIDE_SPOOF_IPS 339
#define HOST 340
#define HUB 341
#define HUB_MASK 342
#define IDLETIME 343
#define IGNORE_BOGUS_TS 344
#define INVISIBLE_ON_CONNECT 345
#define IP 346
#define KILL 347
#define KILL_CHASE_TIME_LIMIT 348
#define KLINE 349
#define KLINE_EXEMPT 350
#define KLINE_REASON 351
#define KLINE_WITH_REASON 352
#define KNOCK_DELAY 353
#define KNOCK_DELAY_CHANNEL 354
#define LAZYLINK 355
#define LEAF_MASK 356
#define LINKS_DELAY 357
#define LISTEN 358
#define T_LOG 359
#define LOGGING 360
#define LOG_LEVEL 361
#define MAX_ACCEPT 362
#define MAX_BANS 363
#define MAX_CHANS_PER_USER 364
#define MAX_GLOBAL 365
#define MAX_IDENT 366
#define MAX_LOCAL 367
#define MAX_NICK_CHANGES 368
#define MAX_NICK_TIME 369
#define MAX_NUMBER 370
#define MAX_TARGETS 371
#define MESSAGE_LOCALE 372
#define MIN_NONWILDCARD 373
#define MIN_NONWILDCARD_SIMPLE 374
#define MODULE 375
#define MODULES 376
#define NAME 377
#define NEED_PASSWORD 378
#define NETWORK_DESC 379
#define NETWORK_NAME 380
#define NICK 381
#define NICK_CHANGES 382
#define NO_CREATE_ON_SPLIT 383
#define NO_JOIN_ON_SPLIT 384
#define NO_OPER_FLOOD 385
#define NO_TILDE 386
#define NOT 387
#define NUMBER 388
#define NUMBER_PER_IDENT 389
#define NUMBER_PER_CIDR 390
#define NUMBER_PER_IP 391
#define NUMBER_PER_IP_GLOBAL 392
#define OPERATOR 393
#define OPERS_BYPASS_CALLERID 394
#define OPER_LOG 395
#define OPER_ONLY_UMODES 396
#define OPER_PASS_RESV 397
#define OPER_SPY_T 398
#define OPER_UMODES 399
#define JOIN_FLOOD_COUNT 400
#define JOIN_FLOOD_TIME 401
#define PACE_WAIT 402
#define PACE_WAIT_SIMPLE 403
#define PASSWORD 404
#define PATH 405
#define PING_COOKIE 406
#define PING_TIME 407
#define PING_WARNING 408
#define PORT 409
#define QSTRING 410
#define QUIET_ON_BAN 411
#define REASON 412
#define REDIRPORT 413
#define REDIRSERV 414
#define REGEX_T 415
#define REHASH 416
#define TREJECT_HOLD_TIME 417
#define REMOTE 418
#define REMOTEBAN 419
#define RESTRICT_CHANNELS 420
#define RESTRICTED 421
#define RSA_PRIVATE_KEY_FILE 422
#define RSA_PUBLIC_KEY_FILE 423
#define SSL_CERTIFICATE_FILE 424
#define RESV 425
#define RESV_EXEMPT 426
#define SECONDS 427
#define MINUTES 428
#define HOURS 429
#define DAYS 430
#define WEEKS 431
#define SENDQ 432
#define SEND_PASSWORD 433
#define SERVERHIDE 434
#define SERVERINFO 435
#define SERVLINK_PATH 436
#define IRCD_SID 437
#define TKLINE_EXPIRE_NOTICES 438
#define T_SHARED 439
#define T_CLUSTER 440
#define TYPE 441
#define SHORT_MOTD 442
#define SILENT 443
#define SPOOF 444
#define SPOOF_NOTICE 445
#define STATS_E_DISABLED 446
#define STATS_I_OPER_ONLY 447
#define STATS_K_OPER_ONLY 448
#define STATS_O_OPER_ONLY 449
#define STATS_P_OPER_ONLY 450
#define TBOOL 451
#define TMASKED 452
#define T_REJECT 453
#define TS_MAX_DELTA 454
#define TS_WARN_DELTA 455
#define TWODOTS 456
#define T_ALL 457
#define T_BOTS 458
#define T_SOFTCALLERID 459
#define T_CALLERID 460
#define T_CCONN 461
#define T_CLIENT_FLOOD 462
#define T_DEAF 463
#define T_DEBUG 464
#define T_DRONE 465
#define T_EXTERNAL 466
#define T_FULL 467
#define T_INVISIBLE 468
#define T_IPV4 469
#define T_IPV6 470
#define T_LOCOPS 471
#define T_LOGPATH 472
#define T_L_CRIT 473
#define T_L_DEBUG 474
#define T_L_ERROR 475
#define T_L_INFO 476
#define T_L_NOTICE 477
#define T_L_TRACE 478
#define T_L_WARN 479
#define T_MAX_CLIENTS 480
#define T_NCHANGE 481
#define T_OPERWALL 482
#define T_REJ 483
#define T_SERVNOTICE 484
#define T_SKILL 485
#define T_SPY 486
#define T_SSL 487
#define T_UMODES 488
#define T_UNAUTH 489
#define T_UNRESV 490
#define T_UNXLINE 491
#define T_WALLOP 492
#define THROTTLE_TIME 493
#define TOPICBURST 494
#define TRUE_NO_OPER_FLOOD 495
#define TKLINE 496
#define TXLINE 497
#define TRESV 498
#define UNKLINE 499
#define USER 500
#define USE_EGD 501
#define USE_EXCEPT 502
#define USE_INVEX 503
#define USE_KNOCK 504
#define USE_LOGGING 505
#define USE_WHOIS_ACTUALLY 506
#define VHOST 507
#define VHOST6 508
#define XLINE 509
#define WARN 510
#define WARN_NO_NLINE 511




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "ircd.h"
#include "tools.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "pcre.h"
#include "irc_string.h"
#include "irc_getaddrinfo.h"
#include "sprintf_irc.h"
#include "memory.h"
#include "modules.h"
#include "s_serv.h" /* for CAP_LL / IsCapable */
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
#endif

static char *class_name = NULL;
static struct ConfItem *yy_conf = NULL;
static struct AccessItem *yy_aconf = NULL;
static struct MatchItem *yy_match_item = NULL;
static struct ClassItem *yy_class = NULL;
static char *yy_class_name = NULL;

static dlink_list col_conf_list  = { NULL, NULL, 0 };
static dlink_list hub_conf_list  = { NULL, NULL, 0 };
static dlink_list leaf_conf_list = { NULL, NULL, 0 };
static unsigned int listener_flags = 0;
static unsigned int regex_ban = 0;
static char userbuf[IRCD_BUFSIZE];
static char hostbuf[IRCD_BUFSIZE];
static char reasonbuf[REASONLEN + 1];
static char gecos_name[REALLEN * 4];

extern dlink_list gdeny_items; /* XXX */

static char *resv_reason = NULL;
static char *listener_address = NULL;
static int not_atom = 0;

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

static void
unhook_hub_leaf_confs(void)
{
  dlink_node *ptr;
  dlink_node *next_ptr;
  struct CollectItem *yy_hconf;
  struct CollectItem *yy_lconf;

  DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
  {
    yy_hconf = ptr->data;
    dlinkDelete(&yy_hconf->node, &hub_conf_list);
    free_collect_item(yy_hconf);
  }

  DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
  {
    yy_lconf = ptr->data;
    dlinkDelete(&yy_lconf->node, &leaf_conf_list);
    free_collect_item(yy_lconf);
  }
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 134 "ircd_parser.y"
{
  int number;
  char *string;
}
/* Line 193 of yacc.c.  */
#line 722 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 735 "y.tab.c"

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
# if YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  262
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  341
/* YYNRULES -- Number of rules.  */
#define YYNRULES  731
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1475

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   511

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   261,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   257,
       2,   260,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   259,     2,   258,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256
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
     154,   156,   158,   161,   166,   171,   176,   181,   186,   191,
     196,   201,   206,   211,   216,   222,   225,   227,   229,   231,
     233,   236,   241,   246,   251,   257,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   280,   282,   284,   286,
     289,   294,   299,   304,   309,   314,   319,   324,   329,   334,
     339,   344,   349,   354,   359,   364,   369,   374,   379,   380,
     388,   389,   391,   394,   396,   398,   400,   402,   404,   406,
     408,   410,   412,   414,   416,   418,   420,   422,   424,   426,
     428,   430,   432,   434,   436,   438,   440,   443,   448,   450,
     455,   460,   465,   470,   475,   476,   482,   486,   488,   490,
     492,   494,   496,   498,   500,   502,   504,   506,   508,   510,
     512,   514,   516,   518,   520,   522,   524,   529,   534,   539,
     544,   549,   554,   559,   564,   569,   574,   579,   584,   589,
     594,   595,   601,   605,   607,   608,   612,   613,   616,   618,
     620,   622,   624,   626,   628,   630,   632,   634,   636,   638,
     640,   642,   644,   646,   648,   649,   657,   658,   660,   663,
     665,   667,   669,   671,   673,   675,   677,   679,   681,   683,
     685,   687,   689,   691,   694,   699,   701,   706,   711,   716,
     721,   726,   731,   736,   741,   746,   751,   756,   761,   762,
     769,   770,   776,   780,   782,   784,   786,   789,   791,   793,
     795,   797,   799,   802,   803,   809,   813,   815,   817,   821,
     826,   831,   832,   839,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   876,   879,   884,   889,   894,   899,   904,   905,   911,
     915,   917,   918,   922,   923,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   946,   951,   956,   961,   966,
     971,   976,   981,   986,   991,   996,   997,  1004,  1007,  1009,
    1011,  1013,  1015,  1018,  1023,  1028,  1033,  1034,  1041,  1044,
    1046,  1048,  1050,  1052,  1055,  1060,  1065,  1066,  1072,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1100,  1101,  1108,  1111,  1113,  1115,  1117,  1120,  1125,
    1126,  1132,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1160,  1161,  1169,  1170,  1172,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1213,  1215,
    1218,  1223,  1225,  1230,  1235,  1240,  1245,  1250,  1255,  1260,
    1265,  1266,  1272,  1276,  1278,  1279,  1283,  1284,  1287,  1289,
    1291,  1293,  1295,  1297,  1299,  1304,  1309,  1314,  1319,  1324,
    1329,  1334,  1339,  1344,  1349,  1350,  1357,  1358,  1364,  1368,
    1370,  1372,  1375,  1377,  1379,  1381,  1383,  1385,  1390,  1395,
    1396,  1403,  1406,  1408,  1410,  1412,  1414,  1419,  1424,  1430,
    1433,  1435,  1437,  1439,  1444,  1445,  1452,  1453,  1459,  1463,
    1465,  1467,  1470,  1472,  1474,  1476,  1478,  1480,  1485,  1490,
    1496,  1499,  1501,  1503,  1505,  1507,  1509,  1511,  1513,  1515,
    1517,  1519,  1521,  1523,  1525,  1527,  1529,  1531,  1533,  1535,
    1537,  1539,  1541,  1543,  1545,  1547,  1549,  1551,  1553,  1555,
    1557,  1559,  1561,  1563,  1565,  1567,  1569,  1571,  1573,  1575,
    1577,  1579,  1581,  1583,  1585,  1587,  1589,  1591,  1593,  1595,
    1597,  1599,  1601,  1603,  1605,  1607,  1609,  1611,  1613,  1618,
    1623,  1628,  1633,  1638,  1643,  1648,  1653,  1658,  1663,  1668,
    1673,  1678,  1683,  1688,  1693,  1698,  1703,  1708,  1713,  1718,
    1723,  1728,  1733,  1738,  1743,  1748,  1753,  1758,  1763,  1768,
    1773,  1778,  1783,  1788,  1793,  1798,  1803,  1808,  1813,  1818,
    1823,  1828,  1833,  1838,  1843,  1848,  1853,  1858,  1863,  1864,
    1870,  1874,  1876,  1878,  1880,  1882,  1884,  1886,  1888,  1890,
    1892,  1894,  1896,  1898,  1900,  1902,  1904,  1906,  1908,  1910,
    1912,  1913,  1919,  1923,  1925,  1927,  1929,  1931,  1933,  1935,
    1937,  1939,  1941,  1943,  1945,  1947,  1949,  1951,  1953,  1955,
    1957,  1959,  1961,  1966,  1971,  1976,  1981,  1986,  1987,  1994,
    1997,  1999,  2001,  2003,  2005,  2007,  2009,  2011,  2013,  2018,
    2023,  2024,  2030,  2034,  2036,  2038,  2040,  2045,  2050,  2051,
    2057,  2061,  2063,  2065,  2067,  2073,  2076,  2078,  2080,  2082,
    2084,  2086,  2088,  2090,  2092,  2094,  2096,  2098,  2100,  2102,
    2104,  2106,  2108,  2110,  2112,  2114,  2116,  2121,  2126,  2131,
    2136,  2141,  2146,  2151,  2156,  2161,  2166,  2171,  2176,  2181,
    2186,  2191,  2196,  2201,  2206,  2212,  2215,  2217,  2219,  2221,
    2223,  2225,  2227,  2229,  2231,  2233,  2238,  2243,  2248,  2253,
    2258,  2263
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     263,     0,    -1,    -1,   263,   264,    -1,   288,    -1,   294,
      -1,   309,    -1,   572,    -1,   346,    -1,   365,    -1,   379,
      -1,   274,    -1,   593,    -1,   405,    -1,   412,    -1,   422,
      -1,   431,    -1,   462,    -1,   472,    -1,   478,    -1,   492,
      -1,   556,    -1,   482,    -1,   269,    -1,     1,   257,    -1,
       1,   258,    -1,    -1,   266,    -1,   133,   265,    -1,   133,
     172,   265,    -1,   133,   173,   265,    -1,   133,   174,   265,
      -1,   133,   175,   265,    -1,   133,   176,   265,    -1,    -1,
     268,    -1,   133,   267,    -1,   133,    14,   267,    -1,   133,
      15,   267,    -1,   133,    16,   267,    -1,   121,   259,   270,
     258,   257,    -1,   270,   271,    -1,   271,    -1,   272,    -1,
     273,    -1,     1,   257,    -1,   120,   260,   155,   257,    -1,
     150,   260,   155,   257,    -1,   180,   259,   275,   258,   257,
      -1,   275,   276,    -1,   276,    -1,   279,    -1,   284,    -1,
     287,    -1,   281,    -1,   282,    -1,   283,    -1,   286,    -1,
     278,    -1,   285,    -1,   280,    -1,   277,    -1,     1,   257,
      -1,   169,   260,   155,   257,    -1,   167,   260,   155,   257,
      -1,   122,   260,   155,   257,    -1,   182,   260,   155,   257,
      -1,    37,   260,   155,   257,    -1,   125,   260,   155,   257,
      -1,   124,   260,   155,   257,    -1,   252,   260,   155,   257,
      -1,   253,   260,   155,   257,    -1,   225,   260,   133,   257,
      -1,    86,   260,   196,   257,    -1,     5,   259,   289,   258,
     257,    -1,   289,   290,    -1,   290,    -1,   291,    -1,   293,
      -1,   292,    -1,     1,   257,    -1,   122,   260,   155,   257,
      -1,    48,   260,   155,   257,    -1,    37,   260,   155,   257,
      -1,   105,   259,   295,   258,   257,    -1,   295,   296,    -1,
     296,    -1,   297,    -1,   298,    -1,   307,    -1,   308,    -1,
     299,    -1,   301,    -1,   303,    -1,   304,    -1,   306,    -1,
     302,    -1,   305,    -1,   300,    -1,     1,   257,    -1,   217,
     260,   155,   257,    -1,   140,   260,   155,   257,    -1,    64,
     260,   155,   257,    -1,    57,   260,   155,   257,    -1,    62,
     260,   155,   257,    -1,    63,   260,   155,   257,    -1,    60,
     260,   155,   257,    -1,    59,   260,   155,   257,    -1,    61,
     260,   155,   257,    -1,    58,   260,   155,   257,    -1,   106,
     260,   218,   257,    -1,   106,   260,   220,   257,    -1,   106,
     260,   224,   257,    -1,   106,   260,   222,   257,    -1,   106,
     260,   223,   257,    -1,   106,   260,   221,   257,    -1,   106,
     260,   219,   257,    -1,   250,   260,   196,   257,    -1,    -1,
     138,   310,   311,   259,   312,   258,   257,    -1,    -1,   315,
      -1,   312,   313,    -1,   313,    -1,   314,    -1,   316,    -1,
     317,    -1,   336,    -1,   337,    -1,   321,    -1,   320,    -1,
     325,    -1,   326,    -1,   328,    -1,   329,    -1,   330,    -1,
     331,    -1,   332,    -1,   327,    -1,   333,    -1,   334,    -1,
     335,    -1,   338,    -1,   318,    -1,   319,    -1,   339,    -1,
       1,   257,    -1,   122,   260,   155,   257,    -1,   155,    -1,
     245,   260,   155,   257,    -1,   149,   260,   155,   257,    -1,
      50,   260,   196,   257,    -1,   168,   260,   155,   257,    -1,
      26,   260,   155,   257,    -1,    -1,   233,   322,   260,   323,
     257,    -1,   323,   261,   324,    -1,   324,    -1,   203,    -1,
     206,    -1,   208,    -1,   209,    -1,   212,    -1,   230,    -1,
     226,    -1,   228,    -1,   234,    -1,   231,    -1,   211,    -1,
     227,    -1,   229,    -1,   213,    -1,   237,    -1,   204,    -1,
     205,    -1,   216,    -1,    74,   260,   196,   257,    -1,   163,
     260,   196,   257,    -1,   164,   260,   196,   257,    -1,    94,
     260,   196,   257,    -1,   254,   260,   196,   257,    -1,   244,
     260,   196,   257,    -1,    67,   260,   196,   257,    -1,   127,
     260,   196,   257,    -1,    38,   260,   196,   257,    -1,   161,
     260,   196,   257,    -1,     5,   260,   196,   257,    -1,    79,
     260,   196,   257,    -1,    81,   260,   196,   257,    -1,   227,
     260,   196,   257,    -1,    -1,    55,   340,   260,   341,   257,
      -1,   341,   261,   342,    -1,   342,    -1,    -1,   132,   343,
     345,    -1,    -1,   344,   345,    -1,    74,    -1,   163,    -1,
      94,    -1,   244,    -1,   254,    -1,    67,    -1,    38,    -1,
     161,    -1,     5,    -1,    79,    -1,   127,    -1,   227,    -1,
     143,    -1,    81,    -1,   164,    -1,    50,    -1,    -1,    26,
     347,   348,   259,   349,   258,   257,    -1,    -1,   352,    -1,
     349,   350,    -1,   350,    -1,   351,    -1,   362,    -1,   363,
      -1,   353,    -1,   354,    -1,   364,    -1,   355,    -1,   356,
      -1,   357,    -1,   358,    -1,   359,    -1,   360,    -1,   361,
      -1,     1,   257,    -1,   122,   260,   155,   257,    -1,   155,
      -1,   152,   260,   266,   257,    -1,   153,   260,   266,   257,
      -1,   136,   260,   133,   257,    -1,    30,   260,   266,   257,
      -1,   115,   260,   133,   257,    -1,   110,   260,   133,   257,
      -1,   112,   260,   133,   257,    -1,   111,   260,   133,   257,
      -1,   177,   260,   268,   257,    -1,    23,   260,   133,   257,
      -1,    24,   260,   133,   257,    -1,   135,   260,   133,   257,
      -1,    -1,   103,   366,   259,   371,   258,   257,    -1,    -1,
      55,   368,   260,   369,   257,    -1,   369,   261,   370,    -1,
     370,    -1,   232,    -1,    78,    -1,   371,   372,    -1,   372,
      -1,   373,    -1,   367,    -1,   377,    -1,   378,    -1,     1,
     257,    -1,    -1,   154,   260,   375,   374,   257,    -1,   375,
     261,   376,    -1,   376,    -1,   133,    -1,   133,   201,   133,
      -1,    91,   260,   155,   257,    -1,    85,   260,   155,   257,
      -1,    -1,    75,   380,   259,   381,   258,   257,    -1,   381,
     382,    -1,   382,    -1,   383,    -1,   384,    -1,   386,    -1,
     388,    -1,   395,    -1,   396,    -1,   397,    -1,   399,    -1,
     400,    -1,   401,    -1,   385,    -1,   402,    -1,   403,    -1,
     398,    -1,   404,    -1,   387,    -1,     1,   257,    -1,   245,
     260,   155,   257,    -1,   149,   260,   155,   257,    -1,   190,
     260,   196,   257,    -1,    26,   260,   155,   257,    -1,    50,
     260,   196,   257,    -1,    -1,    55,   389,   260,   390,   257,
      -1,   390,   261,   391,    -1,   391,    -1,    -1,   132,   392,
     394,    -1,    -1,   393,   394,    -1,   190,    -1,    51,    -1,
      95,    -1,    76,    -1,    20,    -1,    21,    -1,   131,    -1,
      69,    -1,   171,    -1,   123,    -1,    95,   260,   196,   257,
      -1,    76,   260,   196,   257,    -1,    51,   260,   196,   257,
      -1,    20,   260,   196,   257,    -1,   131,   260,   196,   257,
      -1,    69,   260,   196,   257,    -1,   189,   260,   155,   257,
      -1,   159,   260,   155,   257,    -1,   158,   260,   133,   257,
      -1,   123,   260,   196,   257,    -1,    -1,   170,   406,   259,
     407,   258,   257,    -1,   407,   408,    -1,   408,    -1,   409,
      -1,   410,    -1,   411,    -1,     1,   257,    -1,   157,   260,
     155,   257,    -1,    22,   260,   155,   257,    -1,   126,   260,
     155,   257,    -1,    -1,   184,   413,   259,   414,   258,   257,
      -1,   414,   415,    -1,   415,    -1,   416,    -1,   417,    -1,
     418,    -1,     1,   257,    -1,   122,   260,   155,   257,    -1,
     245,   260,   155,   257,    -1,    -1,   186,   419,   260,   420,
     257,    -1,   420,   261,   421,    -1,   421,    -1,    94,    -1,
     241,    -1,   244,    -1,   254,    -1,   242,    -1,   236,    -1,
     170,    -1,   243,    -1,   235,    -1,   216,    -1,   202,    -1,
      -1,   185,   423,   259,   424,   258,   257,    -1,   424,   425,
      -1,   425,    -1,   426,    -1,   427,    -1,     1,   257,    -1,
     122,   260,   155,   257,    -1,    -1,   186,   428,   260,   429,
     257,    -1,   429,   261,   430,    -1,   430,    -1,    94,    -1,
     241,    -1,   244,    -1,   254,    -1,   242,    -1,   236,    -1,
     170,    -1,   243,    -1,   235,    -1,   216,    -1,   202,    -1,
      -1,    29,   432,   433,   259,   434,   258,   257,    -1,    -1,
     437,    -1,   434,   435,    -1,   435,    -1,   436,    -1,   438,
      -1,   439,    -1,   440,    -1,   441,    -1,   443,    -1,   442,
      -1,   444,    -1,   445,    -1,   458,    -1,   459,    -1,   460,
      -1,   456,    -1,   453,    -1,   455,    -1,   454,    -1,   452,
      -1,   461,    -1,   457,    -1,     1,   257,    -1,   122,   260,
     155,   257,    -1,   155,    -1,    85,   260,   155,   257,    -1,
     252,   260,   155,   257,    -1,   178,   260,   155,   257,    -1,
       3,   260,   155,   257,    -1,   154,   260,   133,   257,    -1,
       6,   260,   214,   257,    -1,     6,   260,   215,   257,    -1,
      54,   260,   155,   257,    -1,    -1,    55,   446,   260,   447,
     257,    -1,   447,   261,   448,    -1,   448,    -1,    -1,   132,
     449,   451,    -1,    -1,   450,   451,    -1,   100,    -1,    27,
      -1,    31,    -1,    10,    -1,    12,    -1,   239,    -1,   168,
     260,   155,   257,    -1,    50,   260,   196,   257,    -1,    31,
     260,   196,   257,    -1,    27,   260,   196,   257,    -1,    10,
     260,   196,   257,    -1,   239,   260,   196,   257,    -1,    87,
     260,   155,   257,    -1,   101,   260,   155,   257,    -1,    26,
     260,   155,   257,    -1,    25,   260,   155,   257,    -1,    -1,
      92,   463,   259,   468,   258,   257,    -1,    -1,   186,   465,
     260,   466,   257,    -1,   466,   261,   467,    -1,   467,    -1,
     160,    -1,   468,   469,    -1,   469,    -1,   470,    -1,   471,
      -1,   464,    -1,     1,    -1,   245,   260,   155,   257,    -1,
     157,   260,   155,   257,    -1,    -1,    36,   473,   259,   474,
     258,   257,    -1,   474,   475,    -1,   475,    -1,   476,    -1,
     477,    -1,     1,    -1,    91,   260,   155,   257,    -1,   157,
     260,   155,   257,    -1,    52,   259,   479,   258,   257,    -1,
     479,   480,    -1,   480,    -1,   481,    -1,     1,    -1,    91,
     260,   155,   257,    -1,    -1,    65,   483,   259,   488,   258,
     257,    -1,    -1,   186,   485,   260,   486,   257,    -1,   486,
     261,   487,    -1,   487,    -1,   160,    -1,   488,   489,    -1,
     489,    -1,   490,    -1,   491,    -1,   484,    -1,     1,    -1,
     122,   260,   155,   257,    -1,   157,   260,   155,   257,    -1,
      66,   259,   493,   258,   257,    -1,   493,   494,    -1,   494,
      -1,   502,    -1,   503,    -1,   505,    -1,   506,    -1,   507,
      -1,   508,    -1,   509,    -1,   510,    -1,   511,    -1,   512,
      -1,   501,    -1,   514,    -1,   515,    -1,   516,    -1,   517,
      -1,   533,    -1,   519,    -1,   521,    -1,   523,    -1,   522,
      -1,   526,    -1,   520,    -1,   527,    -1,   528,    -1,   529,
      -1,   530,    -1,   532,    -1,   531,    -1,   547,    -1,   534,
      -1,   538,    -1,   539,    -1,   543,    -1,   524,    -1,   525,
      -1,   553,    -1,   551,    -1,   552,    -1,   535,    -1,   504,
      -1,   536,    -1,   537,    -1,   554,    -1,   542,    -1,   513,
      -1,   555,    -1,   540,    -1,   541,    -1,   497,    -1,   500,
      -1,   495,    -1,   496,    -1,   498,    -1,   499,    -1,   518,
      -1,     1,    -1,    72,   260,   133,   257,    -1,    73,   260,
     133,   257,    -1,    12,   260,   196,   257,    -1,   251,   260,
     196,   257,    -1,   162,   260,   266,   257,    -1,   183,   260,
     196,   257,    -1,    93,   260,   133,   257,    -1,    84,   260,
     196,   257,    -1,    89,   260,   196,   257,    -1,    43,   260,
     196,   257,    -1,    53,   260,   196,   257,    -1,     8,   260,
     196,   257,    -1,   114,   260,   266,   257,    -1,   113,   260,
     133,   257,    -1,   107,   260,   133,   257,    -1,     9,   260,
     266,   257,    -1,   200,   260,   266,   257,    -1,   199,   260,
     266,   257,    -1,    77,   260,   133,   257,    -1,    97,   260,
     196,   257,    -1,    96,   260,   155,   257,    -1,    90,   260,
     196,   257,    -1,   256,   260,   196,   257,    -1,   191,   260,
     196,   257,    -1,   194,   260,   196,   257,    -1,   195,   260,
     196,   257,    -1,   193,   260,   196,   257,    -1,   193,   260,
     197,   257,    -1,   192,   260,   196,   257,    -1,   192,   260,
     197,   257,    -1,   147,   260,   266,   257,    -1,    19,   260,
     266,   257,    -1,   139,   260,   196,   257,    -1,   148,   260,
     266,   257,    -1,   187,   260,   196,   257,    -1,   130,   260,
     196,   257,    -1,   240,   260,   196,   257,    -1,   142,   260,
     196,   257,    -1,   117,   260,   155,   257,    -1,    88,   260,
     266,   257,    -1,    45,   260,   133,   257,    -1,   116,   260,
     133,   257,    -1,   181,   260,   155,   257,    -1,    32,   260,
     155,   257,    -1,    28,   260,   133,   257,    -1,   246,   260,
     196,   257,    -1,    47,   260,   155,   257,    -1,   151,   260,
     196,   257,    -1,    39,   260,   196,   257,    -1,   238,   260,
     266,   257,    -1,    -1,   144,   544,   260,   545,   257,    -1,
     545,   261,   546,    -1,   546,    -1,   203,    -1,   206,    -1,
     208,    -1,   209,    -1,   212,    -1,   230,    -1,   226,    -1,
     228,    -1,   234,    -1,   231,    -1,   211,    -1,   227,    -1,
     229,    -1,   213,    -1,   237,    -1,   204,    -1,   205,    -1,
     216,    -1,    -1,   141,   548,   260,   549,   257,    -1,   549,
     261,   550,    -1,   550,    -1,   203,    -1,   206,    -1,   208,
      -1,   209,    -1,   212,    -1,   230,    -1,   226,    -1,   228,
      -1,   234,    -1,   231,    -1,   211,    -1,   227,    -1,   229,
      -1,   213,    -1,   237,    -1,   204,    -1,   205,    -1,   216,
      -1,   118,   260,   133,   257,    -1,   119,   260,   133,   257,
      -1,    33,   260,   133,   257,    -1,   207,   260,   268,   257,
      -1,    44,   260,   196,   257,    -1,    -1,    68,   557,   259,
     558,   258,   257,    -1,   558,   559,    -1,   559,    -1,   560,
      -1,   561,    -1,   562,    -1,   566,    -1,   567,    -1,   568,
      -1,     1,    -1,    49,   260,   196,   257,    -1,    46,   260,
     266,   257,    -1,    -1,   105,   563,   260,   564,   257,    -1,
     564,   261,   565,    -1,   565,    -1,   198,    -1,    11,    -1,
     245,   260,   155,   257,    -1,   122,   260,   155,   257,    -1,
      -1,     4,   569,   260,   570,   257,    -1,   570,   261,   571,
      -1,   571,    -1,   198,    -1,    11,    -1,    22,   259,   573,
     258,   257,    -1,   573,   574,    -1,   574,    -1,   577,    -1,
     578,    -1,   579,    -1,   580,    -1,   585,    -1,   581,    -1,
     582,    -1,   583,    -1,   584,    -1,   586,    -1,   587,    -1,
     588,    -1,   576,    -1,   589,    -1,   590,    -1,   591,    -1,
     592,    -1,   575,    -1,     1,    -1,    40,   260,   196,   257,
      -1,   165,   260,   196,   257,    -1,    42,   260,   196,   257,
      -1,   247,   260,   196,   257,    -1,   248,   260,   196,   257,
      -1,   249,   260,   196,   257,    -1,    98,   260,   266,   257,
      -1,    99,   260,   266,   257,    -1,   109,   260,   133,   257,
      -1,   156,   260,   196,   257,    -1,   108,   260,   133,   257,
      -1,    35,   260,   133,   257,    -1,    34,   260,   133,   257,
      -1,   128,   260,   196,   257,    -1,   129,   260,   196,   257,
      -1,    13,   260,   196,   257,    -1,   145,   260,   133,   257,
      -1,   146,   260,   266,   257,    -1,   179,   259,   594,   258,
     257,    -1,   594,   595,    -1,   595,    -1,   596,    -1,   597,
      -1,   599,    -1,   601,    -1,   600,    -1,   598,    -1,   602,
      -1,     1,    -1,    56,   260,   196,   257,    -1,    83,   260,
     196,   257,    -1,    80,   260,   155,   257,    -1,   102,   260,
     266,   257,    -1,    78,   260,   196,   257,    -1,    41,   260,
     196,   257,    -1,    82,   260,   196,   257,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   394,   394,   395,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   423,   423,   424,   428,
     432,   436,   440,   444,   450,   450,   451,   452,   453,   454,
     461,   464,   464,   465,   465,   465,   467,   484,   495,   498,
     499,   500,   500,   501,   501,   502,   502,   503,   504,   504,
     505,   505,   506,   508,   542,   602,   616,   631,   640,   654,
     663,   691,   721,   744,   794,   796,   796,   797,   797,   798,
     798,   800,   809,   818,   831,   833,   834,   836,   836,   837,
     838,   838,   839,   839,   840,   840,   841,   841,   842,   843,
     845,   849,   853,   860,   867,   874,   881,   888,   895,   902,
     909,   913,   917,   921,   925,   929,   933,   939,   949,   948,
    1042,  1042,  1043,  1043,  1044,  1044,  1044,  1044,  1045,  1045,
    1046,  1046,  1046,  1047,  1047,  1047,  1048,  1048,  1048,  1049,
    1049,  1049,  1049,  1050,  1050,  1051,  1051,  1053,  1065,  1077,
    1111,  1123,  1134,  1176,  1186,  1185,  1191,  1191,  1192,  1196,
    1200,  1204,  1208,  1212,  1216,  1220,  1224,  1228,  1232,  1236,
    1240,  1244,  1248,  1252,  1256,  1260,  1266,  1277,  1288,  1299,
    1310,  1321,  1332,  1343,  1354,  1365,  1376,  1387,  1398,  1409,
    1421,  1420,  1424,  1424,  1425,  1425,  1426,  1426,  1428,  1435,
    1442,  1449,  1456,  1463,  1470,  1477,  1484,  1491,  1498,  1505,
    1512,  1519,  1526,  1533,  1547,  1546,  1596,  1596,  1598,  1598,
    1599,  1600,  1600,  1601,  1602,  1603,  1604,  1605,  1606,  1607,
    1608,  1609,  1610,  1611,  1613,  1622,  1631,  1637,  1643,  1649,
    1655,  1661,  1667,  1673,  1679,  1685,  1691,  1697,  1707,  1706,
    1723,  1722,  1727,  1727,  1728,  1732,  1738,  1738,  1739,  1739,
    1739,  1739,  1739,  1741,  1741,  1743,  1743,  1745,  1759,  1779,
    1788,  1801,  1800,  1869,  1869,  1870,  1870,  1870,  1870,  1871,
    1871,  1872,  1872,  1872,  1873,  1873,  1874,  1874,  1874,  1875,
    1875,  1875,  1877,  1914,  1927,  1938,  1947,  1959,  1958,  1962,
    1962,  1963,  1963,  1964,  1964,  1966,  1974,  1981,  1988,  1995,
    2002,  2009,  2016,  2023,  2030,  2039,  2050,  2061,  2072,  2083,
    2094,  2106,  2125,  2135,  2144,  2160,  2159,  2175,  2175,  2176,
    2176,  2176,  2176,  2178,  2187,  2202,  2216,  2215,  2231,  2231,
    2232,  2232,  2232,  2232,  2234,  2243,  2266,  2265,  2271,  2271,
    2272,  2276,  2280,  2284,  2288,  2292,  2296,  2300,  2304,  2308,
    2312,  2322,  2321,  2338,  2338,  2339,  2339,  2339,  2341,  2348,
    2347,  2353,  2353,  2354,  2358,  2362,  2366,  2370,  2374,  2378,
    2382,  2386,  2390,  2394,  2404,  2403,  2549,  2549,  2550,  2550,
    2551,  2551,  2551,  2552,  2552,  2553,  2553,  2554,  2554,  2554,
    2555,  2555,  2555,  2556,  2556,  2556,  2557,  2557,  2558,  2558,
    2560,  2572,  2584,  2593,  2619,  2637,  2655,  2661,  2665,  2673,
    2683,  2682,  2686,  2686,  2687,  2687,  2688,  2688,  2690,  2697,
    2708,  2715,  2722,  2729,  2739,  2780,  2791,  2802,  2817,  2828,
    2839,  2852,  2865,  2874,  2910,  2909,  2974,  2973,  2977,  2977,
    2978,  2984,  2984,  2985,  2985,  2985,  2985,  2987,  3006,  3016,
    3015,  3037,  3037,  3038,  3038,  3038,  3040,  3049,  3061,  3063,
    3063,  3064,  3064,  3066,  3088,  3087,  3130,  3129,  3133,  3133,
    3134,  3140,  3140,  3141,  3141,  3141,  3141,  3143,  3149,  3158,
    3161,  3161,  3162,  3162,  3163,  3163,  3164,  3164,  3165,  3165,
    3166,  3166,  3167,  3167,  3168,  3168,  3169,  3169,  3170,  3170,
    3171,  3171,  3172,  3172,  3173,  3173,  3174,  3174,  3175,  3175,
    3176,  3176,  3177,  3177,  3178,  3178,  3179,  3179,  3180,  3180,
    3181,  3181,  3182,  3183,  3183,  3184,  3184,  3185,  3185,  3186,
    3186,  3187,  3187,  3188,  3188,  3189,  3189,  3190,  3194,  3199,
    3204,  3209,  3214,  3219,  3224,  3229,  3234,  3239,  3244,  3249,
    3254,  3259,  3264,  3269,  3274,  3279,  3285,  3296,  3301,  3310,
    3315,  3320,  3325,  3330,  3335,  3338,  3343,  3346,  3351,  3356,
    3361,  3366,  3371,  3376,  3381,  3386,  3391,  3402,  3407,  3412,
    3417,  3426,  3458,  3476,  3481,  3490,  3495,  3500,  3506,  3505,
    3510,  3510,  3511,  3514,  3517,  3520,  3523,  3526,  3529,  3532,
    3535,  3538,  3541,  3544,  3547,  3550,  3553,  3556,  3559,  3562,
    3568,  3567,  3572,  3572,  3573,  3576,  3579,  3582,  3585,  3588,
    3591,  3594,  3597,  3600,  3603,  3606,  3609,  3612,  3615,  3618,
    3621,  3624,  3629,  3634,  3639,  3644,  3649,  3658,  3657,  3681,
    3681,  3682,  3683,  3684,  3685,  3686,  3687,  3688,  3690,  3696,
    3703,  3702,  3707,  3707,  3708,  3712,  3718,  3752,  3762,  3761,
    3811,  3811,  3812,  3816,  3825,  3828,  3828,  3829,  3829,  3830,
    3830,  3831,  3831,  3832,  3832,  3833,  3833,  3834,  3835,  3835,
    3836,  3836,  3837,  3837,  3838,  3838,  3840,  3845,  3850,  3855,
    3860,  3865,  3870,  3875,  3880,  3885,  3890,  3895,  3900,  3905,
    3910,  3915,  3920,  3925,  3933,  3936,  3936,  3937,  3937,  3938,
    3939,  3940,  3940,  3941,  3942,  3944,  3950,  3956,  3965,  3979,
    3985,  3991
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ACCEPT_PASSWORD", "ACTION", "ADMIN",
  "AFTYPE", "T_ALLOW", "ANTI_NICK_FLOOD", "ANTI_SPAM_EXIT_MESSAGE_TIME",
  "AUTOCONN", "T_BLOCK", "BURST_AWAY", "BURST_TOPICWHO", "BYTES", "KBYTES",
  "MBYTES", "GBYTES", "TBYTES", "CALLER_ID_WAIT", "CAN_FLOOD", "CAN_IDLE",
  "CHANNEL", "CIDR_BITLEN_IPV4", "CIDR_BITLEN_IPV6", "CIPHER_PREFERENCE",
  "CLASS", "COMPRESSED", "COMPRESSION_LEVEL", "CONNECT", "CONNECTFREQ",
  "CRYPTLINK", "DEFAULT_CIPHER_PREFERENCE", "DEFAULT_FLOODCOUNT",
  "DEFAULT_SPLIT_SERVER_COUNT", "DEFAULT_SPLIT_USER_COUNT", "DENY",
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_FAKE_CHANNELS",
  "DISABLE_HIDDEN", "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS",
  "DOT_IN_IP6_ADDR", "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL",
  "ENABLE", "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
  "FAKENAME", "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IDLETIME",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LAZYLINK",
  "LEAF_MASK", "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL",
  "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL",
  "MAX_IDENT", "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME",
  "MAX_NUMBER", "MAX_TARGETS", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NOT", "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_LOG",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "SERVLINK_PATH", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID",
  "T_CALLERID", "T_CCONN", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG",
  "T_DRONE", "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6",
  "T_LOCOPS", "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR",
  "T_L_INFO", "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "@1",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "@2",
  "oper_umodes_items", "oper_umodes_item", "oper_global_kill",
  "oper_remote", "oper_remoteban", "oper_kline", "oper_xline",
  "oper_unkline", "oper_gline", "oper_nick_changes", "oper_die",
  "oper_rehash", "oper_admin", "oper_hidden_admin", "oper_hidden_oper",
  "oper_operwall", "oper_flags", "@3", "oper_flags_items",
  "oper_flags_item", "@4", "@5", "oper_flags_item_atom", "class_entry",
  "@6", "class_name_b", "class_items", "class_item", "class_name",
  "class_name_t", "class_ping_time", "class_ping_warning",
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "@7", "listen_flags", "@8",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "@9", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@10", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@11", "auth_flags_items",
  "auth_flags_item", "@12", "@13", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "@14", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "@15", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "@16", "shared_types",
  "shared_type_item", "cluster_entry", "@17", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "@18", "cluster_types",
  "cluster_type_item", "connect_entry", "@19", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "@20", "connect_flags_items",
  "connect_flags_item", "@21", "@22", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_topicburst",
  "connect_hub_mask", "connect_leaf_mask", "connect_class",
  "connect_cipher_preference", "kill_entry", "@23", "kill_type", "@24",
  "kill_type_items", "kill_type_item", "kill_items", "kill_item",
  "kill_user", "kill_reason", "deny_entry", "@25", "deny_items",
  "deny_item", "deny_ip", "deny_reason", "exempt_entry", "exempt_items",
  "exempt_item", "exempt_ip", "gecos_entry", "@26", "gecos_flags", "@27",
  "gecos_flags_items", "gecos_flags_item", "gecos_items", "gecos_item",
  "gecos_name", "gecos_reason", "general_entry", "general_items",
  "general_item", "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_burst_away", "general_use_whois_actually",
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
  "general_message_locale", "general_idletime", "general_dots_in_ident",
  "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@28", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@29",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@30",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@31", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@32", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_disable_local_channels", "channel_use_except",
  "channel_use_invex", "channel_use_knock", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_burst_topicwho", "channel_jflood_count", "channel_jflood_time",
  "serverhide_entry", "serverhide_items", "serverhide_item",
  "serverhide_flatten_links", "serverhide_hide_servers",
  "serverhide_hidden_name", "serverhide_links_delay", "serverhide_hidden",
  "serverhide_disable_hidden", "serverhide_hide_server_ips", 0
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
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,    59,   125,   123,
      61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   262,   263,   263,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   265,   265,   266,   266,
     266,   266,   266,   266,   267,   267,   268,   268,   268,   268,
     269,   270,   270,   271,   271,   271,   272,   273,   274,   275,
     275,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   277,   278,   279,   280,   281,   282,   283,
     284,   285,   286,   287,   288,   289,   289,   290,   290,   290,
     290,   291,   292,   293,   294,   295,   295,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   307,   307,   307,   307,   307,   307,   308,   310,   309,
     311,   311,   312,   312,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   313,   313,   313,
     313,   313,   313,   313,   313,   313,   313,   314,   315,   316,
     317,   318,   319,   320,   322,   321,   323,   323,   324,   324,
     324,   324,   324,   324,   324,   324,   324,   324,   324,   324,
     324,   324,   324,   324,   324,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     340,   339,   341,   341,   343,   342,   344,   342,   345,   345,
     345,   345,   345,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   347,   346,   348,   348,   349,   349,
     350,   350,   350,   350,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   363,   364,   366,   365,
     368,   367,   369,   369,   370,   370,   371,   371,   372,   372,
     372,   372,   372,   374,   373,   375,   375,   376,   376,   377,
     378,   380,   379,   381,   381,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   382,   382,   382,   382,   382,   382,
     382,   382,   383,   384,   385,   386,   387,   389,   388,   390,
     390,   392,   391,   393,   391,   394,   394,   394,   394,   394,
     394,   394,   394,   394,   394,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   406,   405,   407,   407,   408,
     408,   408,   408,   409,   410,   411,   413,   412,   414,   414,
     415,   415,   415,   415,   416,   417,   419,   418,   420,   420,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   423,   422,   424,   424,   425,   425,   425,   426,   428,
     427,   429,   429,   430,   430,   430,   430,   430,   430,   430,
     430,   430,   430,   430,   432,   431,   433,   433,   434,   434,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     435,   435,   435,   435,   435,   435,   435,   435,   435,   435,
     436,   437,   438,   439,   440,   441,   442,   443,   443,   444,
     446,   445,   447,   447,   449,   448,   450,   448,   451,   451,
     451,   451,   451,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   463,   462,   465,   464,   466,   466,
     467,   468,   468,   469,   469,   469,   469,   470,   471,   473,
     472,   474,   474,   475,   475,   475,   476,   477,   478,   479,
     479,   480,   480,   481,   483,   482,   485,   484,   486,   486,
     487,   488,   488,   489,   489,   489,   489,   490,   491,   492,
     493,   493,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   521,   522,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   544,   543,
     545,   545,   546,   546,   546,   546,   546,   546,   546,   546,
     546,   546,   546,   546,   546,   546,   546,   546,   546,   546,
     548,   547,   549,   549,   550,   550,   550,   550,   550,   550,
     550,   550,   550,   550,   550,   550,   550,   550,   550,   550,
     550,   550,   551,   552,   553,   554,   555,   557,   556,   558,
     558,   559,   559,   559,   559,   559,   559,   559,   560,   561,
     563,   562,   564,   564,   565,   565,   566,   567,   569,   568,
     570,   570,   571,   571,   572,   573,   573,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   574,   574,   574,   574,
     574,   574,   574,   574,   574,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   594,   595,   595,   595,
     595,   595,   595,   595,   595,   596,   597,   598,   599,   600,
     601,   602
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
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     7,
       0,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     1,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     2,     0,     5,     3,     1,     1,     3,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     0,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     2,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       0,     5,     3,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   384,   459,     0,
     474,     0,   647,   271,   444,   248,     0,     0,   118,   325,
       0,     0,   336,   361,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     386,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   695,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   676,   694,   689,   677,
     678,   679,   680,   682,   683,   684,   685,   681,   686,   687,
     688,   690,   691,   692,   693,   235,     0,   217,   411,     0,
     387,     0,   472,     0,     0,   470,   471,     0,   547,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   620,     0,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   491,   542,   543,   540,   544,
     545,   541,   502,   492,   493,   531,   494,   495,   496,   497,
     498,   499,   500,   501,   536,   503,   504,   505,   506,   546,
     508,   513,   509,   511,   510,   525,   526,   512,   514,   515,
     516,   517,   519,   518,   507,   521,   530,   532,   533,   522,
     523,   538,   539,   535,   524,   520,   528,   529,   527,   534,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    91,    98,    92,    96,    93,    94,    97,    95,
      89,    90,     0,     0,     0,     0,    42,    43,    44,   148,
       0,   121,     0,   724,     0,     0,     0,     0,     0,     0,
       0,     0,   716,   717,   718,   722,   719,   721,   720,   723,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    50,    61,    58,    51,    60,    54,    55,
      56,    52,    59,    57,    53,     0,     0,    80,     0,     0,
       0,     0,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   675,     0,     0,   465,     0,     0,     0,   462,
     463,   464,     0,     0,   469,   486,     0,     0,   476,   485,
       0,   482,   483,   484,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     490,   657,   668,     0,     0,   660,     0,     0,     0,   650,
     651,   652,   653,   654,   655,   656,     0,     0,     0,     0,
       0,   297,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   274,   275,   276,   285,   277,   290,
     278,   279,   280,   281,   288,   282,   283,   284,   286,   287,
     289,   456,     0,   446,     0,   455,     0,   452,   453,   454,
       0,   250,     0,     0,     0,   259,     0,   257,   258,   260,
     261,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    45,     0,     0,     0,
      41,     0,     0,     0,     0,     0,     0,   328,   329,   330,
     331,     0,     0,     0,     0,     0,     0,     0,     0,   715,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   346,     0,     0,   339,
     340,   341,   342,     0,     0,   369,     0,   364,   365,   366,
       0,     0,     0,    74,     0,     0,     0,     0,     0,    26,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   674,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   219,
     220,   223,   224,   226,   227,   228,   229,   230,   231,   232,
     221,   222,   225,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   389,   390,   391,   392,   393,   394,
     396,   395,   397,   398,   406,   403,   405,   404,   402,   408,
     399,   400,   401,   407,     0,     0,     0,   461,     0,   468,
       0,     0,     0,     0,   481,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,   489,     0,     0,     0,     0,     0,     0,
       0,   649,   291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     273,     0,     0,     0,     0,   451,   262,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,    40,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,   123,
     124,   125,   126,   143,   144,   130,   129,   131,   132,   138,
     133,   134,   135,   136,   137,   139,   140,   141,   127,   128,
     142,   145,   332,     0,     0,     0,     0,   327,     0,     0,
       0,     0,     0,     0,     0,   714,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,   343,     0,
       0,     0,     0,   338,   367,     0,     0,     0,   363,    83,
      82,    81,   711,   708,   707,   696,   698,    26,    26,    26,
      26,    26,    28,    27,   702,   703,   706,   704,   709,   710,
     712,   713,   705,   697,   699,   700,   701,   233,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   218,   409,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   388,     0,     0,   460,   473,     0,
       0,     0,   475,   559,   563,   550,   579,   592,   591,   644,
     596,   557,   646,   588,   594,   558,   548,   549,   566,   555,
     587,   556,   569,   554,   568,   567,   562,   561,   560,   589,
     586,   642,   643,   583,   580,   624,   639,   640,   625,   626,
     627,   634,   628,   637,   641,   630,   635,   631,   636,   629,
     633,   632,   638,     0,   623,   585,   602,   617,   618,   603,
     604,   605,   612,   606,   615,   619,   608,   613,   609,   614,
     607,   611,   610,   616,     0,   601,   578,   581,   595,   552,
     590,   553,   582,   571,   576,   577,   574,   575,   572,   573,
     565,   564,    34,    34,    34,    36,    35,   645,   597,   584,
     593,   551,   570,     0,     0,     0,     0,     0,     0,   648,
       0,     0,     0,     0,   303,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   272,     0,     0,     0,
     445,     0,     0,     0,   267,   263,   266,   249,   103,   109,
     107,   106,   108,   104,   105,   102,   110,   116,   111,   115,
     113,   114,   112,   101,   100,   117,    46,    47,   146,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,   326,   730,   725,   729,
     727,   731,   726,   728,    67,    73,    65,    69,    68,    64,
      63,    66,    72,    70,    71,     0,     0,     0,   337,     0,
       0,   362,    29,    30,    31,    32,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     215,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   426,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   385,   466,   467,   487,   488,   480,     0,   479,   621,
       0,   599,     0,    37,    38,    39,   673,   672,     0,   671,
     659,   658,   665,   664,     0,   663,   667,   666,   318,   295,
     296,   317,   301,     0,   300,     0,   320,   316,   315,   324,
     319,   293,   323,   322,   321,   294,   292,   458,   450,     0,
     449,   457,   255,   254,     0,   253,   270,   269,     0,     0,
       0,     0,     0,     0,     0,   196,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   334,   335,   333,   344,   350,   356,
     360,   359,   358,   355,   351,   354,   357,   352,   353,     0,
     349,   345,   368,   373,   379,   383,   382,   381,   378,   374,
     377,   380,   375,   376,     0,   372,   245,   246,   239,   241,
     243,   242,   240,   234,   247,   238,   236,   237,   244,   415,
     417,   418,   438,   443,   442,   437,   436,   435,   419,   424,
       0,   423,     0,   412,   440,   441,   410,   416,   434,   414,
     439,   413,   477,     0,   622,   600,   669,     0,   661,     0,
       0,   298,   303,   309,   310,   306,   312,   308,   307,   314,
     311,   313,   305,   304,   447,     0,   251,     0,   268,   265,
     264,   186,   153,   184,   151,   194,     0,   193,     0,   182,
     176,   187,   188,   179,   147,   183,   150,   185,   177,   178,
     152,   189,   158,   173,   174,   159,   160,   161,   168,   162,
     171,   175,   164,   169,   165,   170,   163,   167,   166,   172,
       0,   157,   181,   149,   180,   347,     0,   370,     0,     0,
     421,   426,   431,   432,   429,   430,   428,   433,   427,   478,
     670,   662,   302,   299,   448,   252,     0,   191,   196,   206,
     204,   213,   203,   198,   207,   211,   200,   208,   210,   205,
     199,   212,   209,   201,   202,   197,   155,     0,   348,   371,
     425,   422,   195,   192,   156
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   892,   893,  1045,  1046,    25,   275,   276,
     277,   278,    26,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,    27,    71,    72,    73,
      74,    75,    28,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    29,    61,   280,
     818,   819,   820,   281,   821,   822,   823,   824,   825,   826,
    1127,  1420,  1421,   827,   828,   829,   830,   831,   832,   833,
     834,   835,   836,   837,   838,   839,   840,   841,  1113,  1386,
    1387,  1446,  1388,  1465,    30,    49,   116,   608,   609,   610,
     117,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     620,   621,   622,    31,    58,   495,   767,  1254,  1255,   496,
     497,   498,  1260,  1085,  1086,   499,   500,    32,    56,   463,
     464,   465,   466,   467,   468,   469,   470,   747,  1233,  1234,
    1360,  1235,  1373,   471,   472,   473,   474,   475,   476,   477,
     478,   479,   480,    33,    62,   526,   527,   528,   529,   530,
      34,    65,   558,   559,   560,   561,   562,   870,  1299,  1300,
      35,    66,   566,   567,   568,   569,   876,  1314,  1315,    36,
      50,   119,   643,   644,   645,   120,   646,   647,   648,   649,
     650,   651,   652,   653,   933,  1340,  1341,  1429,  1342,  1438,
     654,   655,   656,   657,   658,   659,   660,   661,   662,   663,
      37,    57,   485,   762,  1249,  1250,   486,   487,   488,   489,
      38,    51,   358,   359,   360,   361,    39,   124,   125,   126,
      40,    53,   369,   672,  1207,  1208,   370,   371,   372,   373,
      41,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   408,  1024,  1025,   235,   406,  1003,  1004,   236,
     237,   238,   239,   240,    42,    55,   438,   439,   440,   441,
     442,   737,  1224,  1225,   443,   444,   445,   734,  1218,  1219,
      43,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    44,   291,   292,   293,   294,   295,   296,   297,   298,
     299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -813
static const yytype_int16 yypact[] =
{
    -813,   899,  -813,  -238,  -245,  -221,  -813,  -813,  -813,  -216,
    -813,  -208,  -813,  -813,  -813,  -813,  -196,  -189,  -813,  -813,
    -177,  -170,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,   273,   750,   -60,
     -58,  -150,    17,  -124,   514,  -119,  -116,  -113,   -93,   621,
      29,     0,   -68,   387,   337,   -44,   -38,   -33,   -32,   -24,
     -20,     7,  -813,  -813,  -813,  -813,  -813,   -18,   -14,    -8,
       9,    28,    44,    45,    52,    55,    57,    64,    67,    71,
      73,    77,    79,    81,    82,   237,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,    24,  -813,  -813,    27,
    -813,    32,  -813,    83,    22,  -813,  -813,   177,  -813,    90,
      94,    95,    96,    97,   100,   104,   107,   112,   113,   115,
     117,   121,   125,   130,   131,   132,   134,   139,   140,   141,
     144,   149,   150,   152,   153,   156,   157,   160,   164,   165,
     166,  -813,   167,  -813,   169,   170,   173,   175,   184,   204,
     211,   212,   215,   216,   217,   220,   222,   223,   227,   228,
     230,   231,   232,   240,     3,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,   218,   771,    51,   267,    35,   242,   245,   247,   248,
     249,   250,   251,   252,   253,   258,   260,   261,   111,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,    61,   264,   265,     8,  -813,  -813,  -813,  -813,
      49,  -813,    59,  -813,   268,   269,   270,   271,   272,   274,
     275,    23,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
      87,   276,   278,   279,   280,   281,   283,   284,   285,   288,
     289,   290,   312,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,    84,    39,  -813,   234,   313,
     323,   236,  -813,   320,   394,   418,   356,   359,   423,   423,
     427,   430,   370,   372,   436,   423,   375,   377,   378,   379,
     380,   321,  -813,   473,   719,  -813,   317,   319,    20,  -813,
    -813,  -813,   437,   325,  -813,  -813,   333,   334,  -813,  -813,
      26,  -813,  -813,  -813,   400,   423,   401,   423,   466,   445,
     468,   409,   410,   416,   480,   459,   419,   483,   484,   485,
     424,   423,   428,   433,   486,   479,   439,   490,   503,   423,
     504,   488,   506,   507,   449,   450,   381,   451,   388,   423,
     423,   453,   423,   496,   456,   458,   461,   -82,    48,   463,
     464,   423,   423,   531,   423,   470,   471,   472,   474,   412,
    -813,  -813,  -813,   411,   413,  -813,   414,   417,    58,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,   415,   426,   429,   431,
     434,  -813,   438,   440,   442,   443,   452,   455,   457,   475,
     476,   477,   478,   256,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,   481,  -813,   482,  -813,     2,  -813,  -813,  -813,
     462,  -813,   487,   489,   493,  -813,    33,  -813,  -813,  -813,
    -813,  -813,   533,   535,   538,   541,   544,   555,   568,   569,
     233,   571,   573,   534,   491,  -813,  -813,   577,   578,   498,
    -813,   637,   499,   497,   502,   508,    56,  -813,  -813,  -813,
    -813,   543,   547,   562,   585,   570,   575,   423,   518,  -813,
    -813,   622,   580,   623,   625,   626,   627,   628,   632,   655,
     634,   638,   537,  -813,   542,   549,  -813,   551,    40,  -813,
    -813,  -813,  -813,   545,   552,  -813,    15,  -813,  -813,  -813,
     550,   556,   557,  -813,   558,   559,   560,   561,   567,  -107,
     572,   574,   576,   579,   582,   586,   587,   588,   593,   594,
     595,   596,   597,  -813,   598,   565,   600,   601,   602,   603,
     605,   607,   608,   609,   614,   615,   616,   617,   296,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,   629,   620,   624,   643,   645,   647,   648,
     649,   650,   651,  -813,   652,   653,   654,   656,   657,   658,
     659,   663,   664,   208,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,   640,   672,   631,  -813,   641,  -813,
     673,   675,   666,   670,  -813,   674,   676,   677,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   695,   696,   698,   700,   702,   705,   706,
     709,   712,   713,   715,   718,   721,   722,   859,   723,   894,
     724,   725,   727,   728,   732,   733,   735,   743,   744,   746,
     748,   751,   753,   754,   755,   756,   286,   757,   758,   760,
     761,   762,   764,  -813,   716,   423,   636,   726,   730,   734,
     765,  -813,  -813,   639,   777,   646,   661,   747,   828,   829,
     830,   831,   832,   874,   701,   875,   876,   836,   878,   778,
    -813,   879,   776,   883,   782,  -813,  -813,   780,   886,   889,
     704,   788,  -813,   789,   790,   795,   796,   797,   798,   799,
     800,   801,   802,   803,   809,   816,   817,   819,   820,   823,
     824,  -813,   825,   834,  -813,   835,   841,   844,   848,   849,
    -813,   851,   852,   853,   854,   855,   856,   857,   858,   866,
     867,   869,   870,   884,  -813,   887,   888,   890,   126,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,   939,   940,   964,   882,  -813,   892,   895,
     896,   897,   904,   905,   907,  -813,   908,   910,   911,   912,
     913,   914,   915,   916,   917,   918,   919,  -813,  -813,   981,
     891,   988,   920,  -813,  -813,   991,   921,   922,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,   423,   423,   423,
     423,   423,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  1045,  1047,
     423,  1049,  1050,  1051,  1052,  1031,  1054,  1055,   423,   423,
     531,   932,  -813,  -813,  1035,    41,   995,  1037,  1038,   998,
     999,  1000,  1042,   938,  1044,  1046,  1048,  1053,  1067,  1056,
    1057,  1006,  1058,   947,  -813,   948,   949,  -813,  -813,   950,
     952,  1059,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -251,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -232,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,   531,   531,   531,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,    -6,   953,   957,     6,   958,   959,  -813,
     960,   961,   963,   965,  1089,   966,   967,   968,   969,   970,
     971,   972,   973,   974,   975,   976,  -813,   977,  1075,   979,
    -813,   -65,   980,   982,   618,   983,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  1060,
    1083,  1061,  1062,   985,  1063,  1064,  1065,  1066,  1068,  1085,
    1069,  1086,  1070,  1071,  1072,  1087,  1073,   986,  1074,  1088,
    1076,   990,  -813,   992,   993,   994,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,   996,   752,   997,  -813,  1014,
     807,  -813,  -813,  -813,  -813,  -813,  -813,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1025,  1026,  1027,  1028,
    -813,  1029,  1030,  1032,  1033,  1034,  1036,  1039,  1040,  1041,
    1043,  1116,  1077,  1078,  1079,  1080,  1081,  1082,  1084,  1090,
    1091,  -813,  -813,  -813,  -813,  -813,  -813,  -229,  -813,  -813,
     859,  -813,   894,  -813,  -813,  -813,  -813,  -813,  -212,  -813,
    -813,  -813,  -813,  -813,  -203,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -184,  -813,   327,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -167,
    -813,  -813,  -813,  -813,  -159,  -813,  -813,  -813,  1119,   704,
    1092,  1093,  1094,  1095,  1096,  1123,  1097,  1098,  1099,  1100,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,   929,
    1110,  1111,  1112,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -131,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -125,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -123,  -813,   129,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  1059,  -813,  -813,  -813,    -6,  -813,     6,
     327,  -813,  1089,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  1075,  -813,   -65,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -104,  -813,   729,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
     -34,  -813,  -813,  -813,  -813,  -813,   752,  -813,   807,   129,
    -813,  1116,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,   729,  -813,  1123,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,   929,  -813,  -813,
    -813,  -813,  -813,  -813,  -813
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -813,  -813,  -813,  -449,  -338,  -812,  -421,  -813,  -813,  1013,
    -813,  -813,  -813,  -813,   951,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,   812,  -813,
    -813,  -813,  -813,  -813,  1113,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,   492,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -175,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -154,  -813,  -813,  -151,  -813,  -813,  -813,  -813,   694,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,   -78,  -813,
     805,  -813,  -813,  -813,    46,  -813,  -813,  -813,  -813,  -813,
     840,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,   -56,
    -813,  -813,   -53,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,   783,  -813,  -813,  -813,
    -813,  -813,  -813,   759,  -813,  -813,  -813,  -813,  -813,  -122,
    -813,  -813,  -813,   742,  -813,  -813,  -813,  -813,  -117,  -813,
    -813,  -813,  -813,   669,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -118,  -813,  -813,  -115,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,   -59,  -813,   833,  -813,  -813,
    -813,  -813,  -813,   962,  -813,  -813,  -813,  -813,  1191,  -813,
    -813,  -813,  -813,  -813,  -813,   -35,  -813,   954,  -813,  -813,
    -813,  -813,  1137,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,   110,  -813,  -813,  -813,   116,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,   885,  -813,  -813,
    -813,  -813,  -813,   -31,  -813,  -813,  -813,  -813,  -813,   -30,
    -813,  -813,  1230,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,  -813,
    -813,  -813,  -813,  1114,  -813,  -813,  -813,  -813,  -813,  -813,
    -813
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     580,   581,   727,   481,   128,  1216,  1209,   587,    67,   272,
    1210,   129,   130,  1252,    47,   131,   563,  1222,   122,    45,
      46,   355,   132,   122,   283,  1211,   579,   365,  1352,  1212,
     272,   133,  1353,   355,   490,   134,   135,   676,    48,   678,
     563,   554,   136,    52,    68,  1356,   137,   138,   139,  1357,
     140,    54,   481,   692,  1358,    69,   141,   522,  1359,   431,
     522,   700,   432,    59,   284,   887,   888,   889,   890,   891,
      60,   710,   711,  1361,   713,   142,   143,  1362,   523,   285,
     144,   523,    63,   724,   725,   554,   728,   145,   491,    64,
    1374,   146,   147,   148,  1375,   115,   149,   118,  1376,   150,
     151,   286,  1377,   287,   433,   288,   289,   434,   123,   121,
     152,   356,   245,   123,   718,   719,   153,   154,   492,   155,
     156,   157,   158,   356,   493,   290,  1425,   795,   273,    70,
    1426,   796,  1427,   159,  1430,   127,  1428,   564,  1431,  1432,
     241,  1433,   160,   242,   161,   162,   243,   163,   366,   273,
     164,   165,   797,  1447,   166,   279,  1434,  1448,   274,   482,
    1435,   564,   555,   435,   798,   167,   244,  1253,   246,   247,
     248,   249,   250,   251,   252,   253,   799,   357,   365,   274,
     436,   800,   524,   367,   168,   524,   169,   494,   483,   357,
     170,   282,  1217,   801,   171,   172,   173,   174,   175,   854,
     802,   565,   176,   177,  1223,   803,   555,   804,   482,   623,
     178,   624,   368,   525,   625,   325,   525,   254,   626,   431,
     805,   326,   432,  1466,   327,   565,   556,  1467,   328,  1436,
    1213,  1214,  1215,   627,   628,   629,   329,   483,    76,   630,
     330,   179,   333,   180,   720,   721,   334,   484,   806,   181,
      77,   255,   335,   807,   182,  1182,  1183,   446,   631,   183,
     764,   429,   632,   633,   433,   331,   519,   434,   490,   336,
     556,    78,    79,   877,    67,   808,   447,    80,   666,    81,
     363,   538,   448,   353,   673,   557,   354,   809,   337,   810,
     811,   771,   501,   634,   812,   635,   484,   594,   872,   366,
    1042,  1043,  1044,   437,   338,   339,   449,   450,   521,   636,
      68,   451,   340,   300,   846,   341,   740,   342,   516,   595,
     596,    69,   491,   435,   343,   452,   597,   344,   256,   557,
     637,   345,   453,   346,   367,    82,    83,   347,   300,   348,
     436,   349,   350,   362,   540,    84,    85,  1363,  1364,   301,
     374,   454,   492,   813,   375,   376,   377,   378,   493,   814,
     379,   257,   638,   368,   380,    86,    87,   381,  1437,   514,
     815,   816,   382,   383,   301,   384,   639,   385,  1365,   455,
     817,   386,    88,    89,  1131,   387,   640,   456,   283,   570,
     388,   389,   390,    90,   391,    70,  1366,  1054,   302,   392,
     393,   394,    91,  1367,   395,   457,   598,   599,   600,   396,
     397,   601,   398,   399,   458,   459,   400,   401,   602,   726,
     402,   494,  1368,   302,   403,   404,   405,   407,   284,   409,
     410,   603,   604,   411,   303,   412,   304,   305,  1162,  1163,
    1164,  1165,  1166,   285,   413,   460,   461,   641,   605,   606,
    1369,   781,   782,   783,   784,   785,   786,   787,  1370,   303,
     642,   304,   305,   437,   414,   286,   943,   287,   571,   288,
     289,   415,   416,   607,   594,   417,   418,   419,   572,   306,
     420,   307,   421,   422,    92,    93,    94,   423,   424,   290,
     425,   426,   427,   573,   308,   351,   595,   596,  1371,  1179,
     428,   462,   502,   597,   306,   503,   307,   504,   505,   506,
     507,   508,   509,   510,   759,   128,   574,  1372,   511,   308,
     512,   513,   129,   130,   517,   518,   131,   575,   531,   532,
     533,   534,   535,   132,   536,   537,   541,   309,   542,   543,
     544,   545,   133,   546,   547,   548,   134,   135,   549,   550,
     551,   576,   577,   136,   921,   578,   579,   137,   138,   139,
     582,   140,   309,   583,   310,   311,   584,   141,   585,   586,
     552,   588,  1169,   589,   590,   591,   592,   664,   593,   665,
    1177,  1178,   669,   598,   599,   600,   142,   143,   601,   310,
     311,   144,   668,   670,   671,   602,   675,   677,   145,   679,
     680,   681,   146,   147,   148,   682,   683,   149,   603,   604,
     150,   151,   684,   685,   686,   687,   688,   689,   690,   695,
     691,   152,   245,   698,   693,   605,   606,   153,   154,   694,
     155,   156,   157,   158,   696,   697,   699,   701,   795,   703,
     704,   707,   796,   702,   159,   705,   706,   708,   709,   712,
     607,   714,   715,   160,   716,   161,   162,   717,   163,   722,
     723,   164,   165,   797,   726,   166,   729,   730,   731,   733,
     732,   735,   742,   736,   738,   798,   167,   739,   246,   247,
     248,   249,   250,   251,   252,   253,   743,   799,   773,   744,
     774,   745,   800,   775,   746,   168,   776,   169,   748,   777,
     749,   170,   750,   751,   801,   171,   172,   173,   174,   175,
     778,   802,   752,   176,   177,   753,   803,   754,   804,   766,
     623,   178,   624,   779,   780,   625,   788,   254,   789,   626,
     790,   805,   792,   793,  1449,   755,   756,   757,   758,   848,
     851,   761,   763,   849,   627,   628,   629,   768,   791,   769,
     630,    76,   179,   770,   180,   794,   842,   843,   850,   806,
     181,   255,   844,    77,   807,   182,   852,  1450,   845,   631,
     183,   853,   446,   632,   633,   855,   857,   856,   858,  1451,
     859,   860,   861,   862,    78,    79,   808,   863,   864,   865,
      80,   447,    81,   866,   867,   945,  1452,   448,   809,   868,
     810,   811,   874,  1453,   634,   812,   635,   879,  1454,   869,
    1455,   871,   875,   880,   881,   882,   883,   884,   885,  1258,
     636,   449,   450,  1456,   886,   908,   451,   946,   949,   894,
     950,   895,  1055,   896,  1071,  1060,   897,  1084,   256,   898,
     452,   637,  1062,   899,   900,   901,  1288,   453,    82,    83,
     902,   903,   904,   905,   906,   907,  1457,  1063,    84,    85,
     909,   910,   911,   912,   813,   913,   454,   914,   915,   916,
     814,   257,  1458,   638,   917,   918,   919,   920,    86,    87,
     924,   815,   816,   332,   925,  1057,   923,   639,   947,  1058,
    1459,   817,  1460,  1461,   455,    88,    89,   640,   948,     2,
       3,  1303,   456,   926,     4,   927,    90,   928,   929,   930,
     931,   932,   934,   935,   936,    91,   937,   938,   939,   940,
     457,     5,  1289,   941,   942,     6,   951,   952,     7,   458,
     459,   953,  1061,   954,   955,     8,   956,   957,   958,   959,
     960,   961,   962,   963,   964,   965,   966,   967,   968,   969,
     970,     9,   971,   972,  1290,   973,  1462,   974,   641,   975,
     460,   461,   976,   977,    10,    11,   978,    12,  1291,   979,
     980,   642,   981,  1463,    13,   982,  1053,  1304,   983,   984,
    1005,  1026,  1027,  1464,  1028,  1029,  1056,  1292,  1293,  1030,
    1031,    14,  1032,  1294,  1295,  1296,  1297,    92,    93,    94,
    1033,  1034,    15,  1035,    16,  1036,  1298,  1064,  1037,  1305,
    1038,  1039,  1040,  1041,  1047,  1048,   462,  1049,  1050,  1051,
      17,  1052,  1059,  1306,  1065,  1066,  1067,  1068,  1069,  1070,
    1072,  1073,  1074,  1075,  1077,  1076,  1078,    18,  1079,  1080,
    1081,  1082,  1307,  1308,  1083,  1087,  1088,  1089,  1309,  1310,
    1311,  1312,  1090,  1091,  1092,  1093,  1094,  1095,  1096,  1097,
    1098,  1313,   985,   986,   987,   988,  1099,   989,   990,    19,
     991,   992,   993,  1100,  1101,   994,  1102,  1103,    20,    21,
    1104,  1105,  1106,    22,    23,   995,   996,   997,   998,   999,
    1000,  1107,  1108,  1001,  1133,  1134,  1002,  1006,  1007,  1008,
    1009,  1109,  1010,  1011,  1110,  1012,  1013,  1014,  1111,  1112,
    1015,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1135,
    1016,  1017,  1018,  1019,  1020,  1021,  1122,  1123,  1022,  1124,
    1125,  1023,  1402,  1403,  1404,  1405,  1155,  1406,  1407,  1136,
    1408,  1409,  1410,  1157,  1126,  1411,  1159,  1128,  1129,  1137,
    1130,  1156,  1138,  1139,  1140,  1412,  1413,  1414,  1415,  1416,
    1417,  1141,  1142,  1418,  1143,  1144,  1419,  1145,  1146,  1147,
    1148,  1149,  1150,  1151,  1152,  1153,  1154,  1158,  1167,  1161,
    1168,  1160,  1170,  1171,  1172,  1173,  1174,  1175,  1176,  1180,
    1181,  1184,  1185,  1186,  1187,  1188,  1189,  1190,  1191,  1192,
    1196,  1193,  1199,  1194,  1201,  1202,  1203,  1204,  1195,  1205,
    1220,  1197,  1198,  1200,  1221,  1226,  1227,  1228,  1229,  1206,
    1230,  1232,  1231,  1236,  1237,  1238,  1239,  1240,  1241,  1242,
    1243,  1244,  1245,  1246,  1247,  1248,  1251,  1256,  1262,  1257,
    1271,  1273,  1277,  1281,  1259,  1265,  1279,  1283,  1339,  1284,
    1285,  1286,  1378,  1287,  1301,  1385,  1261,  1263,  1264,  1266,
    1267,  1268,  1269,   553,  1270,  1272,  1274,  1275,  1276,  1278,
    1280,  1302,  1282,  1316,  1317,  1318,  1319,  1320,  1321,  1322,
    1323,  1324,  1325,  1326,  1327,  1328,  1329,  1330,   520,  1331,
    1332,  1333,  1474,  1334,  1473,  1472,  1335,  1336,  1337,  1445,
    1338,   772,   922,   760,  1468,  1379,  1443,  1442,   878,   847,
    1132,  1469,   944,  1471,  1470,   364,  1444,   873,  1439,   765,
     667,   430,  1355,   741,   674,   352,  1354,  1440,  1441,     0,
       0,     0,     0,     0,  1343,  1344,  1345,  1346,  1347,  1348,
       0,  1349,     0,     0,     0,     0,     0,  1350,  1351,  1380,
    1381,  1382,  1383,  1384,  1389,  1390,  1391,  1392,  1393,  1394,
    1395,  1396,  1397,  1398,  1399,  1400,  1401,  1422,  1423,  1424,
       0,   515,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539
};

static const yytype_int16 yycheck[] =
{
     338,   339,   423,     1,     1,    11,   257,   345,     1,     1,
     261,     8,     9,    78,   259,    12,     1,    11,     1,   257,
     258,     1,    19,     1,     1,   257,   133,     1,   257,   261,
       1,    28,   261,     1,     1,    32,    33,   375,   259,   377,
       1,     1,    39,   259,    37,   257,    43,    44,    45,   261,
      47,   259,     1,   391,   257,    48,    53,     1,   261,     1,
       1,   399,     4,   259,    41,   172,   173,   174,   175,   176,
     259,   409,   410,   257,   412,    72,    73,   261,    22,    56,
      77,    22,   259,   421,   422,     1,   424,    84,    55,   259,
     257,    88,    89,    90,   261,   155,    93,   155,   257,    96,
      97,    78,   261,    80,    46,    82,    83,    49,    91,   259,
     107,    91,     1,    91,   196,   197,   113,   114,    85,   116,
     117,   118,   119,    91,    91,   102,   257,     1,   120,   122,
     261,     5,   257,   130,   257,   259,   261,   122,   261,    10,
     259,    12,   139,   259,   141,   142,   259,   144,   122,   120,
     147,   148,    26,   257,   151,   155,    27,   261,   150,   157,
      31,   122,   122,   105,    38,   162,   259,   232,    57,    58,
      59,    60,    61,    62,    63,    64,    50,   157,     1,   150,
     122,    55,   126,   157,   181,   126,   183,   154,   186,   157,
     187,   259,   198,    67,   191,   192,   193,   194,   195,   537,
      74,   186,   199,   200,   198,    79,   122,    81,   157,     1,
     207,     3,   186,   157,     6,   259,   157,   106,    10,     1,
      94,   259,     4,   257,   257,   186,   186,   261,   260,   100,
    1042,  1043,  1044,    25,    26,    27,   260,   186,     1,    31,
     260,   238,   260,   240,   196,   197,   260,   245,   122,   246,
      13,   140,   260,   127,   251,   214,   215,     1,    50,   256,
     258,   258,    54,    55,    46,   258,   258,    49,     1,   260,
     186,    34,    35,   258,     1,   149,    20,    40,   258,    42,
     258,   258,    26,   259,   258,   245,   259,   161,   260,   163,
     164,   258,   257,    85,   168,    87,   245,     1,   258,   122,
      14,    15,    16,   245,   260,   260,    50,    51,   259,   101,
      37,    55,   260,     1,   258,   260,   258,   260,   257,    23,
      24,    48,    55,   105,   260,    69,    30,   260,   217,   245,
     122,   260,    76,   260,   157,    98,    99,   260,     1,   260,
     122,   260,   260,   260,   257,   108,   109,    20,    21,    37,
     260,    95,    85,   227,   260,   260,   260,   260,    91,   233,
     260,   250,   154,   186,   260,   128,   129,   260,   239,   258,
     244,   245,   260,   260,    37,   260,   168,   260,    51,   123,
     254,   260,   145,   146,   258,   260,   178,   131,     1,   155,
     260,   260,   260,   156,   260,   122,    69,   735,    86,   260,
     260,   260,   165,    76,   260,   149,   110,   111,   112,   260,
     260,   115,   260,   260,   158,   159,   260,   260,   122,   133,
     260,   154,    95,    86,   260,   260,   260,   260,    41,   260,
     260,   135,   136,   260,   122,   260,   124,   125,   887,   888,
     889,   890,   891,    56,   260,   189,   190,   239,   152,   153,
     123,   218,   219,   220,   221,   222,   223,   224,   131,   122,
     252,   124,   125,   245,   260,    78,   258,    80,   155,    82,
      83,   260,   260,   177,     1,   260,   260,   260,   155,   167,
     260,   169,   260,   260,   247,   248,   249,   260,   260,   102,
     260,   260,   260,   257,   182,   258,    23,    24,   171,   920,
     260,   245,   260,    30,   167,   260,   169,   260,   260,   260,
     260,   260,   260,   260,   258,     1,   196,   190,   260,   182,
     260,   260,     8,     9,   260,   260,    12,   133,   260,   260,
     260,   260,   260,    19,   260,   260,   260,   225,   260,   260,
     260,   260,    28,   260,   260,   260,    32,    33,   260,   260,
     260,   133,   196,    39,   258,   196,   133,    43,    44,    45,
     133,    47,   225,   133,   252,   253,   196,    53,   196,   133,
     258,   196,   910,   196,   196,   196,   196,   260,   257,   260,
     918,   919,   257,   110,   111,   112,    72,    73,   115,   252,
     253,    77,   155,   260,   260,   122,   196,   196,    84,   133,
     155,   133,    88,    89,    90,   196,   196,    93,   135,   136,
      96,    97,   196,   133,   155,   196,   133,   133,   133,   133,
     196,   107,     1,   133,   196,   152,   153,   113,   114,   196,
     116,   117,   118,   119,   155,   196,   133,   133,     1,   133,
     133,   260,     5,   155,   130,   196,   196,   196,   260,   196,
     177,   155,   196,   139,   196,   141,   142,   196,   144,   196,
     196,   147,   148,    26,   133,   151,   196,   196,   196,   257,
     196,   260,   257,   260,   260,    38,   162,   260,    57,    58,
      59,    60,    61,    62,    63,    64,   260,    50,   155,   260,
     155,   260,    55,   155,   260,   181,   155,   183,   260,   155,
     260,   187,   260,   260,    67,   191,   192,   193,   194,   195,
     155,    74,   260,   199,   200,   260,    79,   260,    81,   257,
       1,   207,     3,   155,   155,     6,   155,   106,   155,    10,
     196,    94,   155,   155,     5,   260,   260,   260,   260,   196,
     155,   260,   260,   196,    25,    26,    27,   260,   257,   260,
      31,     1,   238,   260,   240,   257,   257,   260,   196,   122,
     246,   140,   260,    13,   127,   251,   196,    38,   260,    50,
     256,   196,     1,    54,    55,   257,   196,   155,   155,    50,
     155,   155,   155,   155,    34,    35,   149,   155,   133,   155,
      40,    20,    42,   155,   257,   155,    67,    26,   161,   257,
     163,   164,   257,    74,    85,   168,    87,   257,    79,   260,
      81,   260,   260,   257,   257,   257,   257,   257,   257,   201,
     101,    50,    51,    94,   257,   260,    55,   155,   155,   257,
     155,   257,   196,   257,   133,   196,   257,   133,   217,   257,
      69,   122,   196,   257,   257,   257,    94,    76,    98,    99,
     257,   257,   257,   257,   257,   257,   127,   196,   108,   109,
     260,   260,   260,   260,   227,   260,    95,   260,   260,   260,
     233,   250,   143,   154,   260,   260,   260,   260,   128,   129,
     260,   244,   245,    71,   260,   155,   257,   168,   257,   155,
     161,   254,   163,   164,   123,   145,   146,   178,   257,     0,
       1,    94,   131,   260,     5,   260,   156,   260,   260,   260,
     260,   260,   260,   260,   260,   165,   260,   260,   260,   260,
     149,    22,   170,   260,   260,    26,   260,   257,    29,   158,
     159,   257,   155,   257,   257,    36,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,    52,   257,   257,   202,   257,   227,   257,   239,   257,
     189,   190,   257,   257,    65,    66,   257,    68,   216,   257,
     257,   252,   257,   244,    75,   257,   260,   170,   257,   257,
     257,   257,   257,   254,   257,   257,   260,   235,   236,   257,
     257,    92,   257,   241,   242,   243,   244,   247,   248,   249,
     257,   257,   103,   257,   105,   257,   254,   260,   257,   202,
     257,   257,   257,   257,   257,   257,   245,   257,   257,   257,
     121,   257,   257,   216,   196,   196,   196,   196,   196,   155,
     155,   155,   196,   155,   155,   257,   260,   138,   155,   257,
     260,   155,   235,   236,   155,   257,   257,   257,   241,   242,
     243,   244,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   254,   203,   204,   205,   206,   257,   208,   209,   170,
     211,   212,   213,   257,   257,   216,   257,   257,   179,   180,
     257,   257,   257,   184,   185,   226,   227,   228,   229,   230,
     231,   257,   257,   234,   155,   155,   237,   203,   204,   205,
     206,   260,   208,   209,   260,   211,   212,   213,   260,   260,
     216,   260,   260,   260,   260,   260,   260,   260,   260,   155,
     226,   227,   228,   229,   230,   231,   260,   260,   234,   260,
     260,   237,   203,   204,   205,   206,   155,   208,   209,   257,
     211,   212,   213,   155,   260,   216,   155,   260,   260,   257,
     260,   260,   257,   257,   257,   226,   227,   228,   229,   230,
     231,   257,   257,   234,   257,   257,   237,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   133,   257,
     133,   260,   133,   133,   133,   133,   155,   133,   133,   257,
     155,   196,   155,   155,   196,   196,   196,   155,   260,   155,
     133,   155,   196,   155,   257,   257,   257,   257,   155,   257,
     257,   155,   155,   155,   257,   257,   257,   257,   257,   160,
     257,   132,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   160,   257,   257,   155,   257,
     155,   155,   155,   155,   261,   260,   260,   257,   132,   257,
     257,   257,   133,   257,   257,   132,   196,   196,   196,   196,
     196,   196,   196,   312,   196,   196,   196,   196,   196,   196,
     196,   257,   196,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   275,   257,
     257,   257,  1467,   257,  1448,  1446,   257,   257,   257,  1377,
     257,   496,   608,   463,  1426,  1259,  1362,  1360,   566,   526,
     818,  1428,   643,  1431,  1429,   124,  1375,   558,  1353,   486,
     358,   184,  1212,   438,   370,    95,  1210,  1357,  1359,    -1,
      -1,    -1,    -1,    -1,   257,   257,   257,   257,   257,   257,
      -1,   257,    -1,    -1,    -1,    -1,    -1,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
      -1,   258,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   291
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   263,     0,     1,     5,    22,    26,    29,    36,    52,
      65,    66,    68,    75,    92,   103,   105,   121,   138,   170,
     179,   180,   184,   185,   264,   269,   274,   288,   294,   309,
     346,   365,   379,   405,   412,   422,   431,   462,   472,   478,
     482,   492,   556,   572,   593,   257,   258,   259,   259,   347,
     432,   473,   259,   483,   259,   557,   380,   463,   366,   259,
     259,   310,   406,   259,   259,   413,   423,     1,    37,    48,
     122,   289,   290,   291,   292,   293,     1,    13,    34,    35,
      40,    42,    98,    99,   108,   109,   128,   129,   145,   146,
     156,   165,   247,   248,   249,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   155,   348,   352,   155,   433,
     437,   259,     1,    91,   479,   480,   481,   259,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    45,
      47,    53,    72,    73,    77,    84,    88,    89,    90,    93,
      96,    97,   107,   113,   114,   116,   117,   118,   119,   130,
     139,   141,   142,   144,   147,   148,   151,   162,   181,   183,
     187,   191,   192,   193,   194,   195,   199,   200,   207,   238,
     240,   246,   251,   256,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   547,   551,   552,   553,   554,
     555,   259,   259,   259,   259,     1,    57,    58,    59,    60,
      61,    62,    63,    64,   106,   140,   217,   250,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     1,   120,   150,   270,   271,   272,   273,   155,
     311,   315,   259,     1,    41,    56,    78,    80,    82,    83,
     102,   594,   595,   596,   597,   598,   599,   600,   601,   602,
       1,    37,    86,   122,   124,   125,   167,   169,   182,   225,
     252,   253,   275,   276,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   259,   259,   257,   260,   260,
     260,   258,   290,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   258,   574,   259,   259,     1,    91,   157,   474,   475,
     476,   477,   260,   258,   480,     1,   122,   157,   186,   484,
     488,   489,   490,   491,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   548,   260,   544,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   258,
     494,     1,     4,    46,    49,   105,   122,   245,   558,   559,
     560,   561,   562,   566,   567,   568,     1,    20,    26,    50,
      51,    55,    69,    76,    95,   123,   131,   149,   158,   159,
     189,   190,   245,   381,   382,   383,   384,   385,   386,   387,
     388,   395,   396,   397,   398,   399,   400,   401,   402,   403,
     404,     1,   157,   186,   245,   464,   468,   469,   470,   471,
       1,    55,    85,    91,   154,   367,   371,   372,   373,   377,
     378,   257,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   258,   296,   257,   260,   260,   258,
     271,   259,     1,    22,   126,   157,   407,   408,   409,   410,
     411,   260,   260,   260,   260,   260,   260,   260,   258,   595,
     257,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   258,   276,     1,   122,   186,   245,   414,   415,
     416,   417,   418,     1,   122,   186,   424,   425,   426,   427,
     155,   155,   155,   257,   196,   133,   133,   196,   196,   133,
     266,   266,   133,   133,   196,   196,   133,   266,   196,   196,
     196,   196,   196,   257,     1,    23,    24,    30,   110,   111,
     112,   115,   122,   135,   136,   152,   153,   177,   349,   350,
     351,   353,   354,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,     1,     3,     6,    10,    25,    26,    27,
      31,    50,    54,    55,    85,    87,   101,   122,   154,   168,
     178,   239,   252,   434,   435,   436,   438,   439,   440,   441,
     442,   443,   444,   445,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   260,   260,   258,   475,   155,   257,
     260,   260,   485,   258,   489,   196,   266,   196,   266,   133,
     155,   133,   196,   196,   196,   133,   155,   196,   133,   133,
     133,   196,   266,   196,   196,   133,   155,   196,   133,   133,
     266,   133,   155,   133,   133,   196,   196,   260,   196,   260,
     266,   266,   196,   266,   155,   196,   196,   196,   196,   197,
     196,   197,   196,   196,   266,   266,   133,   268,   266,   196,
     196,   196,   196,   257,   569,   260,   260,   563,   260,   260,
     258,   559,   257,   260,   260,   260,   260,   389,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   258,
     382,   260,   465,   260,   258,   469,   257,   368,   260,   260,
     260,   258,   372,   155,   155,   155,   155,   155,   155,   155,
     155,   218,   219,   220,   221,   222,   223,   224,   155,   155,
     196,   257,   155,   155,   257,     1,     5,    26,    38,    50,
      55,    67,    74,    79,    81,    94,   122,   127,   149,   161,
     163,   164,   168,   227,   233,   244,   245,   254,   312,   313,
     314,   316,   317,   318,   319,   320,   321,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   257,   260,   260,   260,   258,   408,   196,   196,
     196,   155,   196,   196,   266,   257,   155,   196,   155,   155,
     155,   155,   155,   155,   133,   155,   155,   257,   257,   260,
     419,   260,   258,   415,   257,   260,   428,   258,   425,   257,
     257,   257,   257,   257,   257,   257,   257,   172,   173,   174,
     175,   176,   265,   266,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   258,   350,   257,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   446,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   258,   435,   155,   155,   257,   257,   155,
     155,   260,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   203,   204,   205,   206,   208,
     209,   211,   212,   213,   216,   226,   227,   228,   229,   230,
     231,   234,   237,   549,   550,   257,   203,   204,   205,   206,
     208,   209,   211,   212,   213,   216,   226,   227,   228,   229,
     230,   231,   234,   237,   545,   546,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,    14,    15,    16,   267,   268,   257,   257,   257,
     257,   257,   257,   260,   266,   196,   260,   155,   155,   257,
     196,   155,   196,   196,   260,   196,   196,   196,   196,   196,
     155,   133,   155,   155,   196,   155,   257,   155,   260,   155,
     257,   260,   155,   155,   133,   375,   376,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   260,
     260,   260,   260,   340,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   322,   260,   260,
     260,   258,   313,   155,   155,   155,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   155,   260,   155,   257,   155,
     260,   257,   265,   265,   265,   265,   265,   133,   133,   266,
     133,   133,   133,   133,   155,   133,   133,   266,   266,   268,
     257,   155,   214,   215,   196,   155,   155,   196,   196,   196,
     155,   260,   155,   155,   155,   155,   133,   155,   155,   196,
     155,   257,   257,   257,   257,   257,   160,   486,   487,   257,
     261,   257,   261,   267,   267,   267,    11,   198,   570,   571,
     257,   257,    11,   198,   564,   565,   257,   257,   257,   257,
     257,   257,   132,   390,   391,   393,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   160,   466,
     467,   257,    78,   232,   369,   370,   257,   257,   201,   261,
     374,   196,   155,   196,   196,   260,   196,   196,   196,   196,
     196,   155,   196,   155,   196,   196,   196,   155,   196,   260,
     196,   155,   196,   257,   257,   257,   257,   257,    94,   170,
     202,   216,   235,   236,   241,   242,   243,   244,   254,   420,
     421,   257,   257,    94,   170,   202,   216,   235,   236,   241,
     242,   243,   244,   254,   429,   430,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   132,
     447,   448,   450,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   261,   550,   546,   257,   261,   257,   261,
     392,   257,   261,    20,    21,    51,    69,    76,    95,   123,
     131,   171,   190,   394,   257,   261,   257,   261,   133,   376,
     257,   257,   257,   257,   257,   132,   341,   342,   344,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   203,   204,   205,   206,   208,   209,   211,   212,
     213,   216,   226,   227,   228,   229,   230,   231,   234,   237,
     323,   324,   257,   257,   257,   257,   261,   257,   261,   449,
     257,   261,    10,    12,    27,    31,   100,   239,   451,   487,
     571,   565,   394,   391,   467,   370,   343,   257,   261,     5,
      38,    50,    67,    74,    79,    81,    94,   127,   143,   161,
     163,   164,   227,   244,   254,   345,   257,   261,   421,   430,
     451,   448,   345,   342,   324
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 423 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 425 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
#line 429 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
#line 433 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
#line 437 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
#line 441 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
#line 445 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
#line 450 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 451 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
#line 468 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (ypass == 2)
  {
    char *m_bn;

    m_bn = basename(yylval.string);

    /* I suppose we should just ignore it if it is already loaded(since
     * otherwise we would flood the opers on rehash) -A1kmm.
     */
    add_conf_module(yylval.string);
  }
#endif
}
    break;

  case 47:
#line 485 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 509 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2 && ServerInfo.ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      yyerror("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.ctx,
      yylval.string, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.ctx,
      ServerInfo.rsa_private_key_file, SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.ctx))
    {
      yyerror("RSA private key does not match the SSL certificate public key!");
      break;
    }
  }
#endif
}
    break;

  case 64:
#line 543 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 1)
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

    ServerInfo.rsa_private_key = (RSA *)PEM_read_bio_RSAPrivateKey(file, NULL,
      0, NULL);

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

  case 65:
#line 603 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2)
  {
    if (ServerInfo.name == NULL)
    {
      /* the ircd will exit() in main() if we dont set one */
      if (strlen(yylval.string) <= HOSTLEN)
        DupString(ServerInfo.name, yylval.string);
    }
  }
}
    break;

  case 66:
#line 617 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 632 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 641 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    DupString(ServerInfo.network_name, yylval.string);
  }
}
    break;

  case 69:
#line 655 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 664 "ircd_parser.y"
    {
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip.ss.ss_family = res->ai_family;
      ServerInfo.ip.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv4_vhost = 1;
    }
  }
}
    break;

  case 71:
#line 692 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&ServerInfo.ip6, res->ai_addr, res->ai_addrlen);
      ServerInfo.ip6.ss.ss_family = res->ai_family;
      ServerInfo.ip6.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);

      ServerInfo.specific_ipv6_vhost = 1;
    }
  }
#endif
}
    break;

  case 72:
#line 722 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 73:
#line 745 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
    {
      /* Don't become a hub if we have a lazylink active. */
      if (!ServerInfo.hub && uplink && IsCapable(uplink, CAP_LL))
      {
        sendto_realops_flags(UMODE_ALL, L_ALL,
                             "Ignoring config file line hub=yes; "
                             "due to active LazyLink (%s)", uplink->name);
      }
      else
      {
        ServerInfo.hub = 1;
        uplink = NULL;
        delete_capability("HUB");
        add_capability("HUB", CAP_HUB, 1);
      }
    }
    else if (ServerInfo.hub)
    {
      dlink_node *ptr = NULL;

      ServerInfo.hub = 0;
      delete_capability("HUB");

      /* Don't become a leaf if we have a lazylink active. */
      DLINK_FOREACH(ptr, serv_list.head)
      {
        const struct Client *acptr = ptr->data;
        if (MyConnect(acptr) && IsCapable(acptr, CAP_LL))
        {
          sendto_realops_flags(UMODE_ALL, L_ALL,
                               "Ignoring config file line hub=no; "
                               "due to active LazyLink (%s)",
                               acptr->name);
          add_capability("HUB", CAP_HUB, 1);
          ServerInfo.hub = 1;
          break;
        }
      }
    }
  }
}
    break;

  case 81:
#line 801 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 810 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 819 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 846 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 850 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 854 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 861 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 868 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 875 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 882 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 889 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 896 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 903 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 910 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 914 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 918 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 922 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 926 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 930 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 934 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 940 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 949 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 119:
#line 962 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 147:
#line 1054 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 148:
#line 1066 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 149:
#line 1078 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 150:
#line 1112 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 151:
#line 1124 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 152:
#line 1135 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

  case 153:
#line 1177 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1186 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1193 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1197 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1201 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1205 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1209 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1213 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1217 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1221 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1225 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1229 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1233 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1237 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1241 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1245 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1249 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1253 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1257 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1261 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1267 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
    else
      yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 177:
#line 1278 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTE;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTE; 
  }
}
    break;

  case 178:
#line 1289 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REMOTEBAN;
    else
      yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 179:
#line 1300 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_K;
    else
      yy_aconf->port &= ~OPER_FLAG_K;
  }
}
    break;

  case 180:
#line 1311 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_X;
    else
      yy_aconf->port &= ~OPER_FLAG_X;
  }
}
    break;

  case 181:
#line 1322 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_UNKLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_UNKLINE; 
  }
}
    break;

  case 182:
#line 1333 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_GLINE;
    else
      yy_aconf->port &= ~OPER_FLAG_GLINE;
  }
}
    break;

  case 183:
#line 1344 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_N;
    else
      yy_aconf->port &= ~OPER_FLAG_N;
  }
}
    break;

  case 184:
#line 1355 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_DIE;
    else
      yy_aconf->port &= ~OPER_FLAG_DIE;
  }
}
    break;

  case 185:
#line 1366 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_REHASH;
    else
      yy_aconf->port &= ~OPER_FLAG_REHASH;
  }
}
    break;

  case 186:
#line 1377 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_ADMIN;
  }
}
    break;

  case 187:
#line 1388 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 188:
#line 1399 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
    else
      yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 189:
#line 1410 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->port |= OPER_FLAG_OPERWALL;
    else
      yy_aconf->port &= ~OPER_FLAG_OPERWALL;
  }
}
    break;

  case 190:
#line 1421 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1425 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1426 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1429 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1436 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1443 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1450 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1457 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1464 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1471 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1478 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1485 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1492 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1499 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1506 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1513 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1520 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1527 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1534 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1547 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 215:
#line 1554 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf = NULL;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      delete_conf_item(yy_conf);
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

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

  case 234:
#line 1614 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1623 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1632 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 237:
#line 1638 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
#line 1644 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
#line 1650 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 240:
#line 1656 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 241:
#line 1662 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 242:
#line 1668 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 243:
#line 1674 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 244:
#line 1680 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 245:
#line 1686 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 246:
#line 1692 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 247:
#line 1698 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 248:
#line 1707 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1714 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1723 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 254:
#line 1729 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1733 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 263:
#line 1741 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 267:
#line 1746 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), listener_address, listener_flags);
  }
}
    break;

  case 268:
#line 1760 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.ctx)
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

  case 269:
#line 1780 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1789 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 271:
#line 1801 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 272:
#line 1813 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 292:
#line 1878 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 293:
#line 1915 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /* be paranoid */
    if (yy_aconf->passwd != NULL)
      memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

    MyFree(yy_aconf->passwd);
    DupString(yy_aconf->passwd, yylval.string);
  }
}
    break;

  case 294:
#line 1928 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 295:
#line 1939 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 296:
#line 1948 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_aconf);
    else
      ClearConfEncrypted(yy_aconf);
  }
}
    break;

  case 297:
#line 1959 "ircd_parser.y"
    {
}
    break;

  case 301:
#line 1963 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 303:
#line 1964 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 305:
#line 1967 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 306:
#line 1975 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 307:
#line 1982 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 308:
#line 1989 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 309:
#line 1996 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 310:
#line 2003 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 311:
#line 2010 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 312:
#line 2017 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 313:
#line 2024 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 314:
#line 2031 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 315:
#line 2040 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
  }
}
    break;

  case 316:
#line 2051 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 317:
#line 2062 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 318:
#line 2073 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 319:
#line 2084 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
  }
}
    break;

  case 320:
#line 2095 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
    else
      yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
  }
}
    break;

  case 321:
#line 2107 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) < HOSTLEN)
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 322:
#line 2126 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 323:
#line 2136 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 324:
#line 2145 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
    else
      yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 325:
#line 2160 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 326:
#line 2167 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 333:
#line 2179 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 334:
#line 2188 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 335:
#line 2203 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 336:
#line 2216 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 337:
#line 2224 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 344:
#line 2235 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 345:
#line 2244 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 346:
#line 2266 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 350:
#line 2273 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 351:
#line 2277 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 352:
#line 2281 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 353:
#line 2285 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 354:
#line 2289 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 355:
#line 2293 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 356:
#line 2297 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 357:
#line 2301 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 358:
#line 2305 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 359:
#line 2309 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 360:
#line 2313 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 361:
#line 2322 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 362:
#line 2329 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 368:
#line 2342 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 369:
#line 2348 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 373:
#line 2355 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 374:
#line 2359 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 375:
#line 2363 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 376:
#line 2367 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 377:
#line 2371 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 378:
#line 2375 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 379:
#line 2379 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 380:
#line 2383 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 381:
#line 2387 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 382:
#line 2391 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 383:
#line 2395 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 384:
#line 2404 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(SERVER_TYPE);
    yy_aconf = (struct AccessItem *)map_to_conf(yy_conf);
    yy_aconf->passwd = NULL;
    /* defaults */
    yy_aconf->port = PORTNUM;

    if (ConfigFileEntry.burst_away)
      yy_aconf->flags = CONF_FLAGS_BURST_AWAY;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 385:
#line 2422 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_hconf=NULL;
    struct CollectItem *yy_lconf=NULL;
    dlink_node *ptr;
    dlink_node *next_ptr;
#ifdef HAVE_LIBCRYPTO
    if (yy_aconf->host &&
	((yy_aconf->passwd && yy_aconf->spasswd) ||
	 (yy_aconf->rsa_public_key && IsConfCryptLink(yy_aconf))))
#else /* !HAVE_LIBCRYPTO */
      if (yy_aconf->host && !IsConfCryptLink(yy_aconf) && 
	  yy_aconf->passwd && yy_aconf->spasswd)
#endif /* !HAVE_LIBCRYPTO */
	{
	  if (conf_add_server(yy_conf, class_name) == -1)
	  {
	    delete_conf_item(yy_conf);
	    yy_conf = NULL;
	    yy_aconf = NULL;
	  }
	}
	else
	{
	  /* Even if yy_conf ->name is NULL
	   * should still unhook any hub/leaf confs still pending
	   */
	  unhook_hub_leaf_confs();

	  if (yy_conf->name != NULL)
	  {
#ifndef HAVE_LIBCRYPTO
	    if (IsConfCryptLink(yy_aconf))
	      yyerror("Ignoring connect block -- no OpenSSL support");
#else
	    if (IsConfCryptLink(yy_aconf) && !yy_aconf->rsa_public_key)
	      yyerror("Ignoring connect block -- missing key");
#endif
	    if (yy_aconf->host == NULL)
	      yyerror("Ignoring connect block -- missing host");
	    else if (!IsConfCryptLink(yy_aconf) && 
		    (!yy_aconf->passwd || !yy_aconf->spasswd))
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

          yy_aconf = NULL;
	  yy_conf = NULL;
	}

      /*
       * yy_conf is still pointing at the server that is having
       * a connect block built for it. This means, y_aconf->name 
       * points to the actual irc name this server will be known as.
       * Now this new server has a set or even just one hub_mask (or leaf_mask)
       * given in the link list at yy_hconf. Fill in the HUB confs
       * from this link list now.
       */        
      DLINK_FOREACH_SAFE(ptr, next_ptr, hub_conf_list.head)
      {
	struct ConfItem *new_hub_conf;
	struct MatchItem *match_item;

	yy_hconf = ptr->data;

	/* yy_conf == NULL is a fatal error for this connect block! */
	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_hub_conf = make_conf_item(HUB_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_hub_conf);
	  DupString(new_hub_conf->name, yy_conf->name);
	  if (yy_hconf->user != NULL)
	    DupString(match_item->user, yy_hconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_hconf->host != NULL)
	    DupString(match_item->host, yy_hconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_hconf->node, &hub_conf_list);
	free_collect_item(yy_hconf);
      }

      /* Ditto for the LEAF confs */

      DLINK_FOREACH_SAFE(ptr, next_ptr, leaf_conf_list.head)
      {
	struct ConfItem *new_leaf_conf;
	struct MatchItem *match_item;

	yy_lconf = ptr->data;

	if ((yy_conf != NULL) && (yy_conf->name != NULL))
	{
	  new_leaf_conf = make_conf_item(LEAF_TYPE);
	  match_item = (struct MatchItem *)map_to_conf(new_leaf_conf);
	  DupString(new_leaf_conf->name, yy_conf->name);
	  if (yy_lconf->user != NULL)
	    DupString(match_item->user, yy_lconf->user);
	  else
	    DupString(match_item->user, "*");
	  if (yy_lconf->host != NULL)
	    DupString(match_item->host, yy_lconf->host);
	  else
	    DupString(match_item->host, "*");
	}
	dlinkDelete(&yy_lconf->node, &leaf_conf_list);
	free_collect_item(yy_lconf);
      }
      MyFree(class_name);
      class_name = NULL;
      yy_conf = NULL;
      yy_aconf = NULL;
  }
}
    break;

  case 410:
#line 2561 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 411:
#line 2573 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 412:
#line 2585 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 413:
#line 2594 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (irc_getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      irc_freeaddrinfo(res);
    }
  }
}
    break;

  case 414:
#line 2620 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 415:
#line 2638 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 416:
#line 2656 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 417:
#line 2662 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 418:
#line 2666 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 419:
#line 2674 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 420:
#line 2683 "ircd_parser.y"
    {
}
    break;

  case 424:
#line 2687 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 426:
#line 2688 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 428:
#line 2691 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 429:
#line 2698 "ircd_parser.y"
    {
  if (ypass == 2)
#ifndef HAVE_LIBZ
    yyerror("Ignoring flags = compressed; -- no zlib support");
#else
 {
   if (not_atom)ClearConfCompressed(yy_aconf);
   else SetConfCompressed(yy_aconf);
 }
#endif
}
    break;

  case 430:
#line 2709 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 431:
#line 2716 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 432:
#line 2723 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 433:
#line 2730 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 434:
#line 2740 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
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

    if ((file = BIO_new_file(yylval.string, "r")) == NULL)
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

  case 435:
#line 2781 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 436:
#line 2792 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_CRYPTLINK;
    else
      yy_aconf->flags &= ~CONF_FLAGS_CRYPTLINK;
  }
}
    break;

  case 437:
#line 2803 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
#ifndef HAVE_LIBZ
      yyerror("Ignoring compressed=yes; -- no zlib support");
#else
      yy_aconf->flags |= CONF_FLAGS_COMPRESSED;
#endif
    else
      yy_aconf->flags &= ~CONF_FLAGS_COMPRESSED;
  }
}
    break;

  case 438:
#line 2818 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      yy_aconf->flags |= CONF_FLAGS_ALLOW_AUTO_CONN;
    else
      yy_aconf->flags &= ~CONF_FLAGS_ALLOW_AUTO_CONN;
  }
}
    break;

  case 439:
#line 2829 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.number)
      SetConfTopicBurst(yy_aconf);
    else
      ClearConfTopicBurst(yy_aconf);
  }
}
    break;

  case 440:
#line 2840 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 441:
#line 2853 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 442:
#line 2866 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 443:
#line 2875 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    yy_aconf->cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        yy_aconf->cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 444:
#line 2910 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 445:
#line 2917 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (userbuf[0] && hostbuf[0])
    {
      if (regex_ban)
      {
        pcre *exp_user = NULL;
        pcre *exp_host = NULL;
        const char *errptr = NULL;

        if (!(exp_user = ircd_pcre_compile(userbuf, &errptr)) ||
            !(exp_host = ircd_pcre_compile(hostbuf, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        yy_aconf->regexuser = exp_user;
        yy_aconf->regexhost = exp_host;

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
      }
      else
      {
        yy_conf = make_conf_item(KLINE_TYPE);
        yy_aconf = map_to_conf(yy_conf);

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }
    else
      delete_conf_item(yy_conf);

    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 446:
#line 2974 "ircd_parser.y"
    {
}
    break;

  case 450:
#line 2979 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 457:
#line 2988 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 458:
#line 3007 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 459:
#line 3016 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(DLINE_TYPE);
    yy_aconf = map_to_conf(yy_conf);
    /* default reason */
    DupString(yy_aconf->reason, "No reason");
  }
}
    break;

  case 460:
#line 3025 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_aconf->host && parse_netmask(yy_aconf->host, NULL, NULL) != HM_HOST)
      add_conf_by_address(CONF_DLINE, yy_aconf);
    else
      delete_conf_item(yy_conf);
    yy_conf = NULL;
    yy_aconf = NULL;
  }
}
    break;

  case 466:
#line 3041 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 467:
#line 3050 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 473:
#line 3067 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = make_conf_item(EXEMPTDLINE_TYPE);
      yy_aconf = map_to_conf(yy_conf);
      DupString(yy_aconf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPTDLINE, yy_aconf);

      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 474:
#line 3088 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 475:
#line 3095 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (gecos_name[0])
    {
      if (regex_ban)
      {
        pcre *exp_p = NULL;
        const char *errptr = NULL;

        if (!(exp_p = ircd_pcre_compile(gecos_name, &errptr)))
        {
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
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

  case 476:
#line 3130 "ircd_parser.y"
    {
}
    break;

  case 480:
#line 3135 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 487:
#line 3144 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 488:
#line 3150 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 548:
#line 3195 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 549:
#line 3200 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 550:
#line 3205 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 551:
#line 3210 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 552:
#line 3215 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 553:
#line 3220 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 554:
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 555:
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 556:
#line 3235 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 557:
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 558:
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 559:
#line 3250 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 560:
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 561:
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 562:
#line 3265 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 563:
#line 3270 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 564:
#line 3275 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 565:
#line 3280 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 566:
#line 3286 "ircd_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 567:
#line 3297 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 568:
#line 3302 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 569:
#line 3311 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 570:
#line 3316 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 571:
#line 3321 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 572:
#line 3326 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 573:
#line 3331 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 574:
#line 3336 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 575:
#line 3339 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 576:
#line 3344 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 577:
#line 3347 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 578:
#line 3352 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 579:
#line 3357 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 580:
#line 3362 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 581:
#line 3367 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:
#line 3372 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 583:
#line 3377 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 584:
#line 3382 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 585:
#line 3387 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 586:
#line 3392 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 587:
#line 3403 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:
#line 3408 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
#line 3413 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 590:
#line 3418 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 591:
#line 3427 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (ypass == 2)
  {
    struct EncCapability *ecap;
    const char *cipher_name;
    int found = 0;

    ConfigFileEntry.default_cipher_preference = NULL;
    cipher_name = yylval.string;

    for (ecap = CipherTable; ecap->name; ecap++)
    {
      if ((irccmp(ecap->name, cipher_name) == 0) &&
          (ecap->cap & CAP_ENC_MASK))
      {
        ConfigFileEntry.default_cipher_preference = ecap;
        found = 1;
        break;
      }
    }

    if (!found)
      yyerror("Invalid cipher");
  }
#else
  if (ypass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 592:
#line 3459 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = (yyvsp[(3) - (4)].number);
#ifndef HAVE_LIBZ
    yyerror("Ignoring compression_level -- no zlib support");
#else
    if ((ConfigFileEntry.compression_level < 1) ||
        (ConfigFileEntry.compression_level > 9))
    {
      yyerror("Ignoring invalid compression_level, using default");
      ConfigFileEntry.compression_level = 0;
    }
#endif
  }
}
    break;

  case 593:
#line 3477 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 594:
#line 3482 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 595:
#line 3491 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 596:
#line 3496 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 597:
#line 3501 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 598:
#line 3506 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 602:
#line 3512 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 603:
#line 3515 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 604:
#line 3518 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 605:
#line 3521 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 606:
#line 3524 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 607:
#line 3527 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 608:
#line 3530 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 609:
#line 3533 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 610:
#line 3536 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 611:
#line 3539 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 612:
#line 3542 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 613:
#line 3545 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 614:
#line 3548 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 615:
#line 3551 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 616:
#line 3554 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 617:
#line 3557 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 618:
#line 3560 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 619:
#line 3563 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 620:
#line 3568 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 624:
#line 3574 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 625:
#line 3577 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 626:
#line 3580 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 627:
#line 3583 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 628:
#line 3586 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 629:
#line 3589 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 630:
#line 3592 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 631:
#line 3595 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 632:
#line 3598 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 633:
#line 3601 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 634:
#line 3604 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 635:
#line 3607 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 636:
#line 3610 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 637:
#line 3613 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 638:
#line 3616 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 639:
#line 3619 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 640:
#line 3622 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 641:
#line 3625 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 642:
#line 3630 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:
#line 3635 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:
#line 3640 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 645:
#line 3645 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 646:
#line 3650 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 647:
#line 3658 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 648:
#line 3665 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    /*
     * since we re-allocate yy_conf/yy_aconf after the end of action=, at the
     * end we will have one extra, so we should free it.
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
    {
      delete_conf_item(yy_conf);
      yy_conf = NULL;
      yy_aconf = NULL;
    }
  }
}
    break;

  case 658:
#line 3691 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 659:
#line 3697 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 660:
#line 3703 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 664:
#line 3709 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 665:
#line 3713 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 666:
#line 3719 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 667:
#line 3753 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 668:
#line 3762 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 669:
#line 3766 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr, *next_ptr;

    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct AccessItem *new_aconf;
      struct ConfItem *new_conf;

      yy_tmp = ptr->data;
      new_conf = make_conf_item(GDENY_TYPE);
      new_aconf = map_to_conf(new_conf);

      new_aconf->flags = yy_aconf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      else
        DupString(new_conf->name, "*");
      if (yy_aconf->user != NULL)
         DupString(new_aconf->user, yy_tmp->user);
      else   
        DupString(new_aconf->user, "*");
      if (yy_aconf->host != NULL)
        DupString(new_aconf->host, yy_tmp->host);
      else
        DupString(new_aconf->host, "*");

      dlinkDelete(&yy_tmp->node, &col_conf_list);
    }

    /*
     * In case someone has fed us with more than one action= after user/name
     * which would leak memory  -Michael
     */
    if (yy_conf->name == NULL || yy_aconf->user == NULL)
      delete_conf_item(yy_conf);

    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 672:
#line 3813 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 673:
#line 3817 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 696:
#line 3841 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 697:
#line 3846 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 698:
#line 3851 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 699:
#line 3856 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 700:
#line 3861 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 701:
#line 3866 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 702:
#line 3871 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 703:
#line 3876 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 704:
#line 3881 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 705:
#line 3886 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 706:
#line 3891 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 707:
#line 3896 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 708:
#line 3901 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 709:
#line 3906 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 710:
#line 3911 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 711:
#line 3916 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 712:
#line 3921 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 713:
#line 3926 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 725:
#line 3945 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 726:
#line 3951 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 727:
#line 3957 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 728:
#line 3966 "ircd_parser.y"
    {
  if (ypass == 2)
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

  case 729:
#line 3980 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 730:
#line 3986 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 731:
#line 3992 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1267 of yacc.c.  */
#line 7769 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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



