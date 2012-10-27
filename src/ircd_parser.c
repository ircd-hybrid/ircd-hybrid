/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>
#include <string.h>

#include "config.h"
#include "stdinc.h"
#include "ircd.h"
#include "list.h"
#include "s_conf.h"
#include "event.h"
#include "s_log.h"
#include "client.h"	/* for UMODE_ALL only */
#include "irc_string.h"
#include "irc_getaddrinfo.h"
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



/* Line 189 of yacc.c  */
#line 180 "ircd_parser.c"

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
     DOTS_IN_IDENT = 299,
     DURATION = 300,
     EGDPOOL_PATH = 301,
     EMAIL = 302,
     ENABLE = 303,
     ENCRYPTED = 304,
     EXCEED_LIMIT = 305,
     EXEMPT = 306,
     FAILED_OPER_NOTICE = 307,
     FAKENAME = 308,
     IRCD_FLAGS = 309,
     FLATTEN_LINKS = 310,
     FFAILED_OPERLOG = 311,
     FKILLLOG = 312,
     FKLINELOG = 313,
     FGLINELOG = 314,
     FIOERRLOG = 315,
     FOPERLOG = 316,
     FOPERSPYLOG = 317,
     FUSERLOG = 318,
     GECOS = 319,
     GENERAL = 320,
     GLINE = 321,
     GLINES = 322,
     GLINE_EXEMPT = 323,
     GLINE_LOG = 324,
     GLINE_TIME = 325,
     GLINE_MIN_CIDR = 326,
     GLINE_MIN_CIDR6 = 327,
     GLOBAL_KILL = 328,
     IRCD_AUTH = 329,
     NEED_IDENT = 330,
     HAVENT_READ_CONF = 331,
     HIDDEN = 332,
     HIDDEN_ADMIN = 333,
     HIDDEN_NAME = 334,
     HIDDEN_OPER = 335,
     HIDE_SERVER_IPS = 336,
     HIDE_SERVERS = 337,
     HIDE_SPOOF_IPS = 338,
     HOST = 339,
     HUB = 340,
     HUB_MASK = 341,
     IDLETIME = 342,
     IGNORE_BOGUS_TS = 343,
     INVISIBLE_ON_CONNECT = 344,
     IP = 345,
     KILL = 346,
     KILL_CHASE_TIME_LIMIT = 347,
     KLINE = 348,
     KLINE_EXEMPT = 349,
     KLINE_REASON = 350,
     KLINE_WITH_REASON = 351,
     KNOCK_DELAY = 352,
     KNOCK_DELAY_CHANNEL = 353,
     LEAF_MASK = 354,
     LINKS_DELAY = 355,
     LISTEN = 356,
     T_LOG = 357,
     LOGGING = 358,
     LOG_LEVEL = 359,
     MAX_ACCEPT = 360,
     MAX_BANS = 361,
     MAX_CHANS_PER_USER = 362,
     MAX_GLOBAL = 363,
     MAX_IDENT = 364,
     MAX_LOCAL = 365,
     MAX_NICK_CHANGES = 366,
     MAX_NICK_TIME = 367,
     MAX_NUMBER = 368,
     MAX_TARGETS = 369,
     MAX_WATCH = 370,
     MESSAGE_LOCALE = 371,
     MIN_NONWILDCARD = 372,
     MIN_NONWILDCARD_SIMPLE = 373,
     MODULE = 374,
     MODULES = 375,
     NAME = 376,
     NEED_PASSWORD = 377,
     NETWORK_DESC = 378,
     NETWORK_NAME = 379,
     NICK = 380,
     NICK_CHANGES = 381,
     NO_CREATE_ON_SPLIT = 382,
     NO_JOIN_ON_SPLIT = 383,
     NO_OPER_FLOOD = 384,
     NO_TILDE = 385,
     NOT = 386,
     NUMBER = 387,
     NUMBER_PER_IDENT = 388,
     NUMBER_PER_CIDR = 389,
     NUMBER_PER_IP = 390,
     NUMBER_PER_IP_GLOBAL = 391,
     OPERATOR = 392,
     OPERS_BYPASS_CALLERID = 393,
     OPER_LOG = 394,
     OPER_ONLY_UMODES = 395,
     OPER_PASS_RESV = 396,
     OPER_SPY_T = 397,
     OPER_UMODES = 398,
     JOIN_FLOOD_COUNT = 399,
     JOIN_FLOOD_TIME = 400,
     PACE_WAIT = 401,
     PACE_WAIT_SIMPLE = 402,
     PASSWORD = 403,
     PATH = 404,
     PING_COOKIE = 405,
     PING_TIME = 406,
     PING_WARNING = 407,
     PORT = 408,
     QSTRING = 409,
     QUIET_ON_BAN = 410,
     REASON = 411,
     REDIRPORT = 412,
     REDIRSERV = 413,
     REGEX_T = 414,
     REHASH = 415,
     TREJECT_HOLD_TIME = 416,
     REMOTE = 417,
     REMOTEBAN = 418,
     RESTRICT_CHANNELS = 419,
     RESTRICTED = 420,
     RSA_PRIVATE_KEY_FILE = 421,
     RSA_PUBLIC_KEY_FILE = 422,
     SSL_CERTIFICATE_FILE = 423,
     T_SSL_CONNECTION_METHOD = 424,
     T_SSLV3 = 425,
     T_TLSV1 = 426,
     RESV = 427,
     RESV_EXEMPT = 428,
     SECONDS = 429,
     MINUTES = 430,
     HOURS = 431,
     DAYS = 432,
     WEEKS = 433,
     SENDQ = 434,
     SEND_PASSWORD = 435,
     SERVERHIDE = 436,
     SERVERINFO = 437,
     SERVLINK_PATH = 438,
     IRCD_SID = 439,
     TKLINE_EXPIRE_NOTICES = 440,
     T_SHARED = 441,
     T_CLUSTER = 442,
     TYPE = 443,
     SHORT_MOTD = 444,
     SILENT = 445,
     SPOOF = 446,
     SPOOF_NOTICE = 447,
     STATS_E_DISABLED = 448,
     STATS_I_OPER_ONLY = 449,
     STATS_K_OPER_ONLY = 450,
     STATS_O_OPER_ONLY = 451,
     STATS_P_OPER_ONLY = 452,
     TBOOL = 453,
     TMASKED = 454,
     T_REJECT = 455,
     TS_MAX_DELTA = 456,
     TS_WARN_DELTA = 457,
     TWODOTS = 458,
     T_ALL = 459,
     T_BOTS = 460,
     T_SOFTCALLERID = 461,
     T_CALLERID = 462,
     T_CCONN = 463,
     T_CCONN_FULL = 464,
     T_CLIENT_FLOOD = 465,
     T_DEAF = 466,
     T_DEBUG = 467,
     T_DRONE = 468,
     T_EXTERNAL = 469,
     T_FULL = 470,
     T_INVISIBLE = 471,
     T_IPV4 = 472,
     T_IPV6 = 473,
     T_LOCOPS = 474,
     T_LOGPATH = 475,
     T_L_CRIT = 476,
     T_L_DEBUG = 477,
     T_L_ERROR = 478,
     T_L_INFO = 479,
     T_L_NOTICE = 480,
     T_L_TRACE = 481,
     T_L_WARN = 482,
     T_MAX_CLIENTS = 483,
     T_NCHANGE = 484,
     T_OPERWALL = 485,
     T_REJ = 486,
     T_SERVER = 487,
     T_SERVNOTICE = 488,
     T_SKILL = 489,
     T_SPY = 490,
     T_SSL = 491,
     T_UMODES = 492,
     T_UNAUTH = 493,
     T_UNRESV = 494,
     T_UNXLINE = 495,
     T_WALLOP = 496,
     THROTTLE_TIME = 497,
     TOPICBURST = 498,
     TRUE_NO_OPER_FLOOD = 499,
     TKLINE = 500,
     TXLINE = 501,
     TRESV = 502,
     UNKLINE = 503,
     USER = 504,
     USE_EGD = 505,
     USE_EXCEPT = 506,
     USE_INVEX = 507,
     USE_KNOCK = 508,
     USE_LOGGING = 509,
     USE_WHOIS_ACTUALLY = 510,
     VHOST = 511,
     VHOST6 = 512,
     XLINE = 513,
     WARN = 514,
     WARN_NO_NLINE = 515
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
#define DOTS_IN_IDENT 299
#define DURATION 300
#define EGDPOOL_PATH 301
#define EMAIL 302
#define ENABLE 303
#define ENCRYPTED 304
#define EXCEED_LIMIT 305
#define EXEMPT 306
#define FAILED_OPER_NOTICE 307
#define FAKENAME 308
#define IRCD_FLAGS 309
#define FLATTEN_LINKS 310
#define FFAILED_OPERLOG 311
#define FKILLLOG 312
#define FKLINELOG 313
#define FGLINELOG 314
#define FIOERRLOG 315
#define FOPERLOG 316
#define FOPERSPYLOG 317
#define FUSERLOG 318
#define GECOS 319
#define GENERAL 320
#define GLINE 321
#define GLINES 322
#define GLINE_EXEMPT 323
#define GLINE_LOG 324
#define GLINE_TIME 325
#define GLINE_MIN_CIDR 326
#define GLINE_MIN_CIDR6 327
#define GLOBAL_KILL 328
#define IRCD_AUTH 329
#define NEED_IDENT 330
#define HAVENT_READ_CONF 331
#define HIDDEN 332
#define HIDDEN_ADMIN 333
#define HIDDEN_NAME 334
#define HIDDEN_OPER 335
#define HIDE_SERVER_IPS 336
#define HIDE_SERVERS 337
#define HIDE_SPOOF_IPS 338
#define HOST 339
#define HUB 340
#define HUB_MASK 341
#define IDLETIME 342
#define IGNORE_BOGUS_TS 343
#define INVISIBLE_ON_CONNECT 344
#define IP 345
#define KILL 346
#define KILL_CHASE_TIME_LIMIT 347
#define KLINE 348
#define KLINE_EXEMPT 349
#define KLINE_REASON 350
#define KLINE_WITH_REASON 351
#define KNOCK_DELAY 352
#define KNOCK_DELAY_CHANNEL 353
#define LEAF_MASK 354
#define LINKS_DELAY 355
#define LISTEN 356
#define T_LOG 357
#define LOGGING 358
#define LOG_LEVEL 359
#define MAX_ACCEPT 360
#define MAX_BANS 361
#define MAX_CHANS_PER_USER 362
#define MAX_GLOBAL 363
#define MAX_IDENT 364
#define MAX_LOCAL 365
#define MAX_NICK_CHANGES 366
#define MAX_NICK_TIME 367
#define MAX_NUMBER 368
#define MAX_TARGETS 369
#define MAX_WATCH 370
#define MESSAGE_LOCALE 371
#define MIN_NONWILDCARD 372
#define MIN_NONWILDCARD_SIMPLE 373
#define MODULE 374
#define MODULES 375
#define NAME 376
#define NEED_PASSWORD 377
#define NETWORK_DESC 378
#define NETWORK_NAME 379
#define NICK 380
#define NICK_CHANGES 381
#define NO_CREATE_ON_SPLIT 382
#define NO_JOIN_ON_SPLIT 383
#define NO_OPER_FLOOD 384
#define NO_TILDE 385
#define NOT 386
#define NUMBER 387
#define NUMBER_PER_IDENT 388
#define NUMBER_PER_CIDR 389
#define NUMBER_PER_IP 390
#define NUMBER_PER_IP_GLOBAL 391
#define OPERATOR 392
#define OPERS_BYPASS_CALLERID 393
#define OPER_LOG 394
#define OPER_ONLY_UMODES 395
#define OPER_PASS_RESV 396
#define OPER_SPY_T 397
#define OPER_UMODES 398
#define JOIN_FLOOD_COUNT 399
#define JOIN_FLOOD_TIME 400
#define PACE_WAIT 401
#define PACE_WAIT_SIMPLE 402
#define PASSWORD 403
#define PATH 404
#define PING_COOKIE 405
#define PING_TIME 406
#define PING_WARNING 407
#define PORT 408
#define QSTRING 409
#define QUIET_ON_BAN 410
#define REASON 411
#define REDIRPORT 412
#define REDIRSERV 413
#define REGEX_T 414
#define REHASH 415
#define TREJECT_HOLD_TIME 416
#define REMOTE 417
#define REMOTEBAN 418
#define RESTRICT_CHANNELS 419
#define RESTRICTED 420
#define RSA_PRIVATE_KEY_FILE 421
#define RSA_PUBLIC_KEY_FILE 422
#define SSL_CERTIFICATE_FILE 423
#define T_SSL_CONNECTION_METHOD 424
#define T_SSLV3 425
#define T_TLSV1 426
#define RESV 427
#define RESV_EXEMPT 428
#define SECONDS 429
#define MINUTES 430
#define HOURS 431
#define DAYS 432
#define WEEKS 433
#define SENDQ 434
#define SEND_PASSWORD 435
#define SERVERHIDE 436
#define SERVERINFO 437
#define SERVLINK_PATH 438
#define IRCD_SID 439
#define TKLINE_EXPIRE_NOTICES 440
#define T_SHARED 441
#define T_CLUSTER 442
#define TYPE 443
#define SHORT_MOTD 444
#define SILENT 445
#define SPOOF 446
#define SPOOF_NOTICE 447
#define STATS_E_DISABLED 448
#define STATS_I_OPER_ONLY 449
#define STATS_K_OPER_ONLY 450
#define STATS_O_OPER_ONLY 451
#define STATS_P_OPER_ONLY 452
#define TBOOL 453
#define TMASKED 454
#define T_REJECT 455
#define TS_MAX_DELTA 456
#define TS_WARN_DELTA 457
#define TWODOTS 458
#define T_ALL 459
#define T_BOTS 460
#define T_SOFTCALLERID 461
#define T_CALLERID 462
#define T_CCONN 463
#define T_CCONN_FULL 464
#define T_CLIENT_FLOOD 465
#define T_DEAF 466
#define T_DEBUG 467
#define T_DRONE 468
#define T_EXTERNAL 469
#define T_FULL 470
#define T_INVISIBLE 471
#define T_IPV4 472
#define T_IPV6 473
#define T_LOCOPS 474
#define T_LOGPATH 475
#define T_L_CRIT 476
#define T_L_DEBUG 477
#define T_L_ERROR 478
#define T_L_INFO 479
#define T_L_NOTICE 480
#define T_L_TRACE 481
#define T_L_WARN 482
#define T_MAX_CLIENTS 483
#define T_NCHANGE 484
#define T_OPERWALL 485
#define T_REJ 486
#define T_SERVER 487
#define T_SERVNOTICE 488
#define T_SKILL 489
#define T_SPY 490
#define T_SSL 491
#define T_UMODES 492
#define T_UNAUTH 493
#define T_UNRESV 494
#define T_UNXLINE 495
#define T_WALLOP 496
#define THROTTLE_TIME 497
#define TOPICBURST 498
#define TRUE_NO_OPER_FLOOD 499
#define TKLINE 500
#define TXLINE 501
#define TRESV 502
#define UNKLINE 503
#define USER 504
#define USE_EGD 505
#define USE_EXCEPT 506
#define USE_INVEX 507
#define USE_KNOCK 508
#define USE_LOGGING 509
#define USE_WHOIS_ACTUALLY 510
#define VHOST 511
#define VHOST6 512
#define XLINE 513
#define WARN 514
#define WARN_NO_NLINE 515




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 132 "ircd_parser.y"

  int number;
  char *string;



/* Line 214 of yacc.c  */
#line 743 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 755 "ircd_parser.c"

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

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  319
/* YYNRULES -- Number of rules.  */
#define YYNRULES  689
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1359

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   515

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   265,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   261,
       2,   264,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   263,     2,   262,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259,   260
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
     154,   156,   158,   160,   163,   164,   170,   174,   176,   178,
     180,   185,   190,   195,   200,   205,   210,   215,   220,   225,
     230,   235,   241,   244,   246,   248,   250,   252,   255,   260,
     265,   270,   276,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297,   299,   301,   303,   305,   308,   313,   318,
     323,   328,   333,   338,   343,   348,   353,   358,   363,   368,
     373,   378,   383,   388,   393,   398,   399,   407,   408,   410,
     413,   415,   417,   419,   421,   423,   425,   427,   429,   431,
     434,   439,   441,   446,   451,   456,   461,   466,   467,   473,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   505,   507,   509,   511,   513,   515,
     517,   518,   524,   528,   530,   531,   535,   536,   539,   541,
     543,   545,   547,   549,   551,   553,   555,   557,   559,   561,
     563,   565,   567,   569,   571,   572,   580,   581,   583,   586,
     588,   590,   592,   594,   596,   598,   600,   602,   604,   606,
     608,   610,   612,   614,   617,   622,   624,   629,   634,   639,
     644,   649,   654,   659,   664,   669,   674,   679,   684,   685,
     692,   693,   699,   703,   705,   707,   709,   711,   714,   716,
     718,   720,   722,   724,   727,   728,   734,   738,   740,   742,
     746,   751,   756,   757,   764,   767,   769,   771,   773,   775,
     777,   779,   781,   783,   785,   788,   793,   798,   803,   808,
     809,   815,   819,   821,   822,   826,   827,   830,   832,   834,
     836,   838,   840,   842,   844,   846,   848,   850,   855,   860,
     865,   866,   873,   876,   878,   880,   882,   884,   887,   892,
     897,   902,   903,   910,   913,   915,   917,   919,   921,   924,
     929,   934,   935,   941,   945,   947,   949,   951,   953,   955,
     957,   959,   961,   963,   965,   967,   969,   970,   977,   980,
     982,   984,   986,   989,   994,   995,  1001,  1005,  1007,  1009,
    1011,  1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,
    1030,  1038,  1039,  1041,  1044,  1046,  1048,  1050,  1052,  1054,
    1056,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,
    1076,  1079,  1084,  1086,  1091,  1096,  1101,  1106,  1111,  1116,
    1121,  1126,  1127,  1133,  1137,  1139,  1140,  1144,  1145,  1148,
    1150,  1152,  1154,  1156,  1158,  1163,  1168,  1173,  1178,  1183,
    1188,  1189,  1196,  1197,  1203,  1207,  1209,  1211,  1214,  1216,
    1218,  1220,  1222,  1224,  1229,  1234,  1235,  1242,  1245,  1247,
    1249,  1251,  1253,  1258,  1263,  1269,  1272,  1274,  1276,  1278,
    1283,  1284,  1291,  1292,  1298,  1302,  1304,  1306,  1309,  1311,
    1313,  1315,  1317,  1319,  1324,  1329,  1335,  1338,  1340,  1342,
    1344,  1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,
    1364,  1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,
    1384,  1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1402,
    1404,  1406,  1408,  1410,  1412,  1414,  1416,  1418,  1420,  1422,
    1424,  1426,  1428,  1430,  1432,  1434,  1436,  1438,  1440,  1442,
    1444,  1446,  1448,  1450,  1452,  1457,  1462,  1467,  1472,  1477,
    1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,  1527,
    1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,  1577,
    1582,  1587,  1592,  1597,  1602,  1607,  1612,  1617,  1622,  1627,
    1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1677,
    1682,  1687,  1692,  1697,  1702,  1707,  1708,  1714,  1718,  1720,
    1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,
    1742,  1744,  1746,  1748,  1750,  1752,  1754,  1756,  1758,  1759,
    1765,  1769,  1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,
    1787,  1789,  1791,  1793,  1795,  1797,  1799,  1801,  1803,  1805,
    1807,  1809,  1814,  1819,  1824,  1829,  1830,  1837,  1840,  1842,
    1844,  1846,  1848,  1850,  1852,  1854,  1856,  1861,  1866,  1867,
    1873,  1877,  1879,  1881,  1883,  1888,  1893,  1894,  1900,  1904,
    1906,  1908,  1910,  1916,  1919,  1921,  1923,  1925,  1927,  1929,
    1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1947,  1949,
    1951,  1953,  1955,  1957,  1959,  1964,  1969,  1974,  1979,  1984,
    1989,  1994,  1999,  2004,  2009,  2014,  2019,  2024,  2029,  2034,
    2039,  2044,  2049,  2055,  2058,  2060,  2062,  2064,  2066,  2068,
    2070,  2072,  2074,  2076,  2081,  2086,  2091,  2096,  2101,  2106
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,    -1,   267,   268,    -1,   296,    -1,   302,
      -1,   317,    -1,   554,    -1,   340,    -1,   359,    -1,   373,
      -1,   278,    -1,   575,    -1,   391,    -1,   398,    -1,   408,
      -1,   417,    -1,   444,    -1,   454,    -1,   460,    -1,   474,
      -1,   538,    -1,   464,    -1,   273,    -1,     1,   261,    -1,
       1,   262,    -1,    -1,   270,    -1,   132,   269,    -1,   132,
     174,   269,    -1,   132,   175,   269,    -1,   132,   176,   269,
      -1,   132,   177,   269,    -1,   132,   178,   269,    -1,    -1,
     272,    -1,   132,   271,    -1,   132,    14,   271,    -1,   132,
      15,   271,    -1,   132,    16,   271,    -1,   120,   263,   274,
     262,   261,    -1,   274,   275,    -1,   275,    -1,   276,    -1,
     277,    -1,     1,   261,    -1,   119,   264,   154,   261,    -1,
     149,   264,   154,   261,    -1,   182,   263,   279,   262,   261,
      -1,   279,   280,    -1,   280,    -1,   287,    -1,   292,    -1,
     295,    -1,   289,    -1,   290,    -1,   291,    -1,   294,    -1,
     286,    -1,   293,    -1,   288,    -1,   285,    -1,   281,    -1,
       1,   261,    -1,    -1,   169,   282,   264,   283,   261,    -1,
     283,   265,   284,    -1,   284,    -1,   170,    -1,   171,    -1,
     168,   264,   154,   261,    -1,   166,   264,   154,   261,    -1,
     121,   264,   154,   261,    -1,   184,   264,   154,   261,    -1,
      37,   264,   154,   261,    -1,   124,   264,   154,   261,    -1,
     123,   264,   154,   261,    -1,   256,   264,   154,   261,    -1,
     257,   264,   154,   261,    -1,   228,   264,   132,   261,    -1,
      85,   264,   198,   261,    -1,     5,   263,   297,   262,   261,
      -1,   297,   298,    -1,   298,    -1,   299,    -1,   301,    -1,
     300,    -1,     1,   261,    -1,   121,   264,   154,   261,    -1,
      47,   264,   154,   261,    -1,    37,   264,   154,   261,    -1,
     103,   263,   303,   262,   261,    -1,   303,   304,    -1,   304,
      -1,   305,    -1,   306,    -1,   315,    -1,   316,    -1,   307,
      -1,   309,    -1,   311,    -1,   312,    -1,   314,    -1,   310,
      -1,   313,    -1,   308,    -1,     1,   261,    -1,   220,   264,
     154,   261,    -1,   139,   264,   154,   261,    -1,    63,   264,
     154,   261,    -1,    56,   264,   154,   261,    -1,    61,   264,
     154,   261,    -1,    62,   264,   154,   261,    -1,    59,   264,
     154,   261,    -1,    58,   264,   154,   261,    -1,    60,   264,
     154,   261,    -1,    57,   264,   154,   261,    -1,   104,   264,
     221,   261,    -1,   104,   264,   223,   261,    -1,   104,   264,
     227,   261,    -1,   104,   264,   225,   261,    -1,   104,   264,
     226,   261,    -1,   104,   264,   224,   261,    -1,   104,   264,
     222,   261,    -1,   254,   264,   198,   261,    -1,    -1,   137,
     318,   319,   263,   320,   262,   261,    -1,    -1,   323,    -1,
     320,   321,    -1,   321,    -1,   322,    -1,   324,    -1,   325,
      -1,   329,    -1,   328,    -1,   326,    -1,   327,    -1,   333,
      -1,     1,   261,    -1,   121,   264,   154,   261,    -1,   154,
      -1,   249,   264,   154,   261,    -1,   148,   264,   154,   261,
      -1,    49,   264,   198,   261,    -1,   167,   264,   154,   261,
      -1,    26,   264,   154,   261,    -1,    -1,   237,   330,   264,
     331,   261,    -1,   331,   265,   332,    -1,   332,    -1,   205,
      -1,   208,    -1,   209,    -1,   211,    -1,   212,    -1,   215,
      -1,   234,    -1,   229,    -1,   231,    -1,   238,    -1,   235,
      -1,   214,    -1,   230,    -1,   233,    -1,   216,    -1,   241,
      -1,   206,    -1,   207,    -1,   219,    -1,    -1,    54,   334,
     264,   335,   261,    -1,   335,   265,   336,    -1,   336,    -1,
      -1,   131,   337,   339,    -1,    -1,   338,   339,    -1,    73,
      -1,   162,    -1,    93,    -1,   248,    -1,   258,    -1,    66,
      -1,    38,    -1,   160,    -1,     5,    -1,    78,    -1,   126,
      -1,   230,    -1,   142,    -1,    80,    -1,   163,    -1,    49,
      -1,    -1,    26,   341,   342,   263,   343,   262,   261,    -1,
      -1,   346,    -1,   343,   344,    -1,   344,    -1,   345,    -1,
     356,    -1,   357,    -1,   347,    -1,   348,    -1,   358,    -1,
     349,    -1,   350,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,     1,   261,    -1,   121,   264,   154,
     261,    -1,   154,    -1,   151,   264,   270,   261,    -1,   152,
     264,   270,   261,    -1,   135,   264,   132,   261,    -1,    30,
     264,   270,   261,    -1,   113,   264,   132,   261,    -1,   108,
     264,   132,   261,    -1,   110,   264,   132,   261,    -1,   109,
     264,   132,   261,    -1,   179,   264,   272,   261,    -1,    23,
     264,   132,   261,    -1,    24,   264,   132,   261,    -1,   134,
     264,   132,   261,    -1,    -1,   101,   360,   263,   365,   262,
     261,    -1,    -1,    54,   362,   264,   363,   261,    -1,   363,
     265,   364,    -1,   364,    -1,   236,    -1,    77,    -1,   232,
      -1,   365,   366,    -1,   366,    -1,   367,    -1,   361,    -1,
     371,    -1,   372,    -1,     1,   261,    -1,    -1,   153,   264,
     369,   368,   261,    -1,   369,   265,   370,    -1,   370,    -1,
     132,    -1,   132,   203,   132,    -1,    90,   264,   154,   261,
      -1,    84,   264,   154,   261,    -1,    -1,    74,   374,   263,
     375,   262,   261,    -1,   375,   376,    -1,   376,    -1,   377,
      -1,   378,    -1,   379,    -1,   381,    -1,   388,    -1,   389,
      -1,   390,    -1,   380,    -1,     1,   261,    -1,   249,   264,
     154,   261,    -1,   148,   264,   154,   261,    -1,    26,   264,
     154,   261,    -1,    49,   264,   198,   261,    -1,    -1,    54,
     382,   264,   383,   261,    -1,   383,   265,   384,    -1,   384,
      -1,    -1,   131,   385,   387,    -1,    -1,   386,   387,    -1,
     192,    -1,    50,    -1,    94,    -1,    75,    -1,    20,    -1,
      21,    -1,   130,    -1,    68,    -1,   173,    -1,   122,    -1,
     191,   264,   154,   261,    -1,   158,   264,   154,   261,    -1,
     157,   264,   132,   261,    -1,    -1,   172,   392,   263,   393,
     262,   261,    -1,   393,   394,    -1,   394,    -1,   395,    -1,
     396,    -1,   397,    -1,     1,   261,    -1,   156,   264,   154,
     261,    -1,    22,   264,   154,   261,    -1,   125,   264,   154,
     261,    -1,    -1,   186,   399,   263,   400,   262,   261,    -1,
     400,   401,    -1,   401,    -1,   402,    -1,   403,    -1,   404,
      -1,     1,   261,    -1,   121,   264,   154,   261,    -1,   249,
     264,   154,   261,    -1,    -1,   188,   405,   264,   406,   261,
      -1,   406,   265,   407,    -1,   407,    -1,    93,    -1,   245,
      -1,   248,    -1,   258,    -1,   246,    -1,   240,    -1,   172,
      -1,   247,    -1,   239,    -1,   219,    -1,   204,    -1,    -1,
     187,   409,   263,   410,   262,   261,    -1,   410,   411,    -1,
     411,    -1,   412,    -1,   413,    -1,     1,   261,    -1,   121,
     264,   154,   261,    -1,    -1,   188,   414,   264,   415,   261,
      -1,   415,   265,   416,    -1,   416,    -1,    93,    -1,   245,
      -1,   248,    -1,   258,    -1,   246,    -1,   240,    -1,   172,
      -1,   247,    -1,   239,    -1,   219,    -1,   204,    -1,    -1,
      29,   418,   419,   263,   420,   262,   261,    -1,    -1,   423,
      -1,   420,   421,    -1,   421,    -1,   422,    -1,   424,    -1,
     425,    -1,   426,    -1,   427,    -1,   429,    -1,   428,    -1,
     430,    -1,   431,    -1,   440,    -1,   441,    -1,   442,    -1,
     439,    -1,   438,    -1,   443,    -1,     1,   261,    -1,   121,
     264,   154,   261,    -1,   154,    -1,    84,   264,   154,   261,
      -1,   256,   264,   154,   261,    -1,   180,   264,   154,   261,
      -1,     3,   264,   154,   261,    -1,   153,   264,   132,   261,
      -1,     6,   264,   217,   261,    -1,     6,   264,   218,   261,
      -1,    53,   264,   154,   261,    -1,    -1,    54,   432,   264,
     433,   261,    -1,   433,   265,   434,    -1,   434,    -1,    -1,
     131,   435,   437,    -1,    -1,   436,   437,    -1,    27,    -1,
      31,    -1,    10,    -1,    12,    -1,   243,    -1,   167,   264,
     154,   261,    -1,    49,   264,   198,   261,    -1,    86,   264,
     154,   261,    -1,    99,   264,   154,   261,    -1,    26,   264,
     154,   261,    -1,    25,   264,   154,   261,    -1,    -1,    91,
     445,   263,   450,   262,   261,    -1,    -1,   188,   447,   264,
     448,   261,    -1,   448,   265,   449,    -1,   449,    -1,   159,
      -1,   450,   451,    -1,   451,    -1,   452,    -1,   453,    -1,
     446,    -1,     1,    -1,   249,   264,   154,   261,    -1,   156,
     264,   154,   261,    -1,    -1,    36,   455,   263,   456,   262,
     261,    -1,   456,   457,    -1,   457,    -1,   458,    -1,   459,
      -1,     1,    -1,    90,   264,   154,   261,    -1,   156,   264,
     154,   261,    -1,    51,   263,   461,   262,   261,    -1,   461,
     462,    -1,   462,    -1,   463,    -1,     1,    -1,    90,   264,
     154,   261,    -1,    -1,    64,   465,   263,   470,   262,   261,
      -1,    -1,   188,   467,   264,   468,   261,    -1,   468,   265,
     469,    -1,   469,    -1,   159,    -1,   470,   471,    -1,   471,
      -1,   472,    -1,   473,    -1,   466,    -1,     1,    -1,   121,
     264,   154,   261,    -1,   156,   264,   154,   261,    -1,    65,
     263,   475,   262,   261,    -1,   475,   476,    -1,   476,    -1,
     485,    -1,   486,    -1,   488,    -1,   489,    -1,   490,    -1,
     491,    -1,   492,    -1,   493,    -1,   494,    -1,   495,    -1,
     484,    -1,   497,    -1,   498,    -1,   499,    -1,   500,    -1,
     516,    -1,   502,    -1,   504,    -1,   506,    -1,   505,    -1,
     509,    -1,   503,    -1,   510,    -1,   511,    -1,   512,    -1,
     513,    -1,   515,    -1,   514,    -1,   530,    -1,   517,    -1,
     521,    -1,   522,    -1,   526,    -1,   507,    -1,   508,    -1,
     536,    -1,   534,    -1,   535,    -1,   518,    -1,   487,    -1,
     519,    -1,   520,    -1,   537,    -1,   525,    -1,   496,    -1,
     523,    -1,   524,    -1,   480,    -1,   483,    -1,   478,    -1,
     479,    -1,   481,    -1,   482,    -1,   501,    -1,   477,    -1,
       1,    -1,   115,   264,   132,   261,    -1,    71,   264,   132,
     261,    -1,    72,   264,   132,   261,    -1,    12,   264,   198,
     261,    -1,   255,   264,   198,   261,    -1,   161,   264,   270,
     261,    -1,   185,   264,   198,   261,    -1,    92,   264,   270,
     261,    -1,    83,   264,   198,   261,    -1,    88,   264,   198,
     261,    -1,    43,   264,   198,   261,    -1,    52,   264,   198,
     261,    -1,     8,   264,   198,   261,    -1,   112,   264,   270,
     261,    -1,   111,   264,   132,   261,    -1,   105,   264,   132,
     261,    -1,     9,   264,   270,   261,    -1,   202,   264,   270,
     261,    -1,   201,   264,   270,   261,    -1,    76,   264,   132,
     261,    -1,    96,   264,   198,   261,    -1,    95,   264,   154,
     261,    -1,    89,   264,   198,   261,    -1,   260,   264,   198,
     261,    -1,   193,   264,   198,   261,    -1,   196,   264,   198,
     261,    -1,   197,   264,   198,   261,    -1,   195,   264,   198,
     261,    -1,   195,   264,   199,   261,    -1,   194,   264,   198,
     261,    -1,   194,   264,   199,   261,    -1,   146,   264,   270,
     261,    -1,    19,   264,   270,   261,    -1,   138,   264,   198,
     261,    -1,   147,   264,   270,   261,    -1,   189,   264,   198,
     261,    -1,   129,   264,   198,   261,    -1,   244,   264,   198,
     261,    -1,   141,   264,   198,   261,    -1,   116,   264,   154,
     261,    -1,    87,   264,   270,   261,    -1,    44,   264,   132,
     261,    -1,   114,   264,   132,   261,    -1,   183,   264,   154,
     261,    -1,    32,   264,   154,   261,    -1,    28,   264,   132,
     261,    -1,   250,   264,   198,   261,    -1,    46,   264,   154,
     261,    -1,   150,   264,   198,   261,    -1,    39,   264,   198,
     261,    -1,   242,   264,   270,   261,    -1,    -1,   143,   527,
     264,   528,   261,    -1,   528,   265,   529,    -1,   529,    -1,
     205,    -1,   208,    -1,   209,    -1,   211,    -1,   212,    -1,
     215,    -1,   234,    -1,   229,    -1,   231,    -1,   238,    -1,
     235,    -1,   214,    -1,   230,    -1,   233,    -1,   216,    -1,
     241,    -1,   206,    -1,   207,    -1,   219,    -1,    -1,   140,
     531,   264,   532,   261,    -1,   532,   265,   533,    -1,   533,
      -1,   205,    -1,   208,    -1,   209,    -1,   211,    -1,   212,
      -1,   215,    -1,   234,    -1,   229,    -1,   231,    -1,   238,
      -1,   235,    -1,   214,    -1,   230,    -1,   233,    -1,   216,
      -1,   241,    -1,   206,    -1,   207,    -1,   219,    -1,   117,
     264,   132,   261,    -1,   118,   264,   132,   261,    -1,    33,
     264,   132,   261,    -1,   210,   264,   272,   261,    -1,    -1,
      67,   539,   263,   540,   262,   261,    -1,   540,   541,    -1,
     541,    -1,   542,    -1,   543,    -1,   544,    -1,   548,    -1,
     549,    -1,   550,    -1,     1,    -1,    48,   264,   198,   261,
      -1,    45,   264,   270,   261,    -1,    -1,   103,   545,   264,
     546,   261,    -1,   546,   265,   547,    -1,   547,    -1,   200,
      -1,    11,    -1,   249,   264,   154,   261,    -1,   121,   264,
     154,   261,    -1,    -1,     4,   551,   264,   552,   261,    -1,
     552,   265,   553,    -1,   553,    -1,   200,    -1,    11,    -1,
      22,   263,   555,   262,   261,    -1,   555,   556,    -1,   556,
      -1,   559,    -1,   560,    -1,   561,    -1,   562,    -1,   567,
      -1,   563,    -1,   564,    -1,   565,    -1,   566,    -1,   568,
      -1,   569,    -1,   570,    -1,   558,    -1,   571,    -1,   572,
      -1,   573,    -1,   574,    -1,   557,    -1,     1,    -1,    40,
     264,   198,   261,    -1,   164,   264,   198,   261,    -1,    42,
     264,   198,   261,    -1,   251,   264,   198,   261,    -1,   252,
     264,   198,   261,    -1,   253,   264,   198,   261,    -1,    97,
     264,   270,   261,    -1,    98,   264,   270,   261,    -1,   107,
     264,   132,   261,    -1,   155,   264,   198,   261,    -1,   106,
     264,   132,   261,    -1,    35,   264,   132,   261,    -1,    34,
     264,   132,   261,    -1,   127,   264,   198,   261,    -1,   128,
     264,   198,   261,    -1,    13,   264,   198,   261,    -1,   144,
     264,   132,   261,    -1,   145,   264,   270,   261,    -1,   181,
     263,   576,   262,   261,    -1,   576,   577,    -1,   577,    -1,
     578,    -1,   579,    -1,   581,    -1,   583,    -1,   582,    -1,
     580,    -1,   584,    -1,     1,    -1,    55,   264,   198,   261,
      -1,    82,   264,   198,   261,    -1,    79,   264,   154,   261,
      -1,   100,   264,   270,   261,    -1,    77,   264,   198,   261,
      -1,    41,   264,   198,   261,    -1,    81,   264,   198,   261,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   396,   396,   397,   400,   401,   402,   403,   404,   405,
     406,   407,   408,   409,   410,   411,   412,   413,   414,   415,
     416,   417,   418,   419,   420,   421,   425,   425,   426,   430,
     434,   438,   442,   446,   452,   452,   453,   454,   455,   456,
     463,   466,   466,   467,   467,   467,   469,   477,   486,   488,
     488,   489,   489,   490,   490,   491,   491,   492,   493,   493,
     494,   494,   495,   496,   500,   499,   518,   518,   519,   525,
     533,   567,   627,   641,   656,   665,   679,   688,   716,   746,
     769,   791,   793,   793,   794,   794,   795,   795,   797,   806,
     815,   828,   830,   831,   833,   833,   834,   835,   835,   836,
     836,   837,   837,   838,   838,   839,   840,   842,   846,   850,
     857,   864,   871,   878,   885,   892,   899,   906,   910,   914,
     918,   922,   926,   930,   936,   946,   945,  1039,  1039,  1040,
    1040,  1041,  1041,  1041,  1042,  1042,  1042,  1043,  1043,  1043,
    1045,  1057,  1069,  1103,  1115,  1126,  1168,  1178,  1177,  1183,
    1183,  1184,  1188,  1192,  1196,  1200,  1204,  1208,  1212,  1216,
    1220,  1224,  1228,  1232,  1236,  1240,  1244,  1248,  1252,  1256,
    1263,  1262,  1266,  1266,  1267,  1267,  1268,  1268,  1270,  1277,
    1284,  1291,  1298,  1305,  1312,  1319,  1326,  1333,  1340,  1347,
    1354,  1361,  1368,  1375,  1389,  1388,  1438,  1438,  1440,  1440,
    1441,  1442,  1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,
    1450,  1451,  1452,  1453,  1455,  1464,  1473,  1479,  1485,  1491,
    1497,  1503,  1509,  1515,  1521,  1527,  1533,  1539,  1549,  1548,
    1565,  1564,  1569,  1569,  1570,  1574,  1578,  1586,  1586,  1587,
    1587,  1587,  1587,  1587,  1589,  1589,  1591,  1591,  1593,  1607,
    1627,  1636,  1649,  1648,  1717,  1717,  1718,  1718,  1718,  1718,
    1719,  1719,  1719,  1720,  1720,  1722,  1759,  1772,  1781,  1793,
    1792,  1796,  1796,  1797,  1797,  1798,  1798,  1800,  1807,  1814,
    1821,  1828,  1835,  1842,  1849,  1856,  1863,  1873,  1892,  1902,
    1916,  1915,  1931,  1931,  1932,  1932,  1932,  1932,  1934,  1943,
    1958,  1972,  1971,  1987,  1987,  1988,  1988,  1988,  1988,  1990,
    1999,  2022,  2021,  2027,  2027,  2028,  2032,  2036,  2040,  2044,
    2048,  2052,  2056,  2060,  2064,  2068,  2078,  2077,  2094,  2094,
    2095,  2095,  2095,  2097,  2104,  2103,  2109,  2109,  2110,  2114,
    2118,  2122,  2126,  2130,  2134,  2138,  2142,  2146,  2150,  2160,
    2159,  2305,  2305,  2306,  2306,  2307,  2307,  2307,  2308,  2308,
    2309,  2309,  2309,  2310,  2310,  2310,  2311,  2311,  2312,  2312,
    2313,  2315,  2327,  2339,  2348,  2374,  2392,  2410,  2416,  2420,
    2428,  2438,  2437,  2441,  2441,  2442,  2442,  2443,  2443,  2445,
    2456,  2463,  2470,  2477,  2487,  2528,  2539,  2552,  2565,  2574,
    2610,  2609,  2673,  2672,  2676,  2676,  2677,  2683,  2683,  2684,
    2684,  2684,  2684,  2686,  2705,  2715,  2714,  2737,  2737,  2738,
    2738,  2738,  2740,  2746,  2755,  2757,  2757,  2758,  2758,  2760,
    2779,  2778,  2826,  2825,  2829,  2829,  2830,  2836,  2836,  2837,
    2837,  2837,  2837,  2839,  2845,  2854,  2857,  2857,  2858,  2858,
    2859,  2859,  2860,  2860,  2861,  2861,  2862,  2862,  2863,  2863,
    2864,  2864,  2865,  2865,  2866,  2866,  2867,  2867,  2868,  2868,
    2869,  2869,  2870,  2870,  2871,  2871,  2872,  2872,  2873,  2873,
    2874,  2874,  2875,  2875,  2876,  2876,  2877,  2877,  2878,  2879,
    2879,  2880,  2880,  2881,  2882,  2882,  2883,  2883,  2884,  2884,
    2885,  2885,  2886,  2887,  2890,  2895,  2900,  2905,  2910,  2915,
    2920,  2925,  2930,  2935,  2940,  2945,  2950,  2955,  2960,  2965,
    2970,  2975,  2980,  2986,  2997,  3002,  3011,  3016,  3021,  3026,
    3031,  3036,  3039,  3044,  3047,  3052,  3057,  3062,  3067,  3072,
    3077,  3082,  3087,  3092,  3103,  3108,  3113,  3118,  3127,  3159,
    3177,  3182,  3191,  3196,  3201,  3207,  3206,  3211,  3211,  3212,
    3215,  3218,  3221,  3224,  3227,  3230,  3233,  3236,  3239,  3242,
    3245,  3248,  3251,  3254,  3257,  3260,  3263,  3266,  3272,  3271,
    3276,  3276,  3277,  3280,  3283,  3286,  3289,  3292,  3295,  3298,
    3301,  3304,  3307,  3310,  3313,  3316,  3319,  3322,  3325,  3328,
    3331,  3336,  3341,  3346,  3351,  3361,  3360,  3384,  3384,  3385,
    3386,  3387,  3388,  3389,  3390,  3391,  3393,  3399,  3406,  3405,
    3410,  3410,  3411,  3415,  3421,  3455,  3465,  3464,  3514,  3514,
    3515,  3519,  3528,  3531,  3531,  3532,  3532,  3533,  3533,  3534,
    3534,  3535,  3535,  3536,  3536,  3537,  3538,  3538,  3539,  3539,
    3540,  3540,  3541,  3541,  3543,  3548,  3553,  3558,  3563,  3568,
    3573,  3578,  3583,  3588,  3593,  3598,  3603,  3608,  3613,  3618,
    3623,  3628,  3636,  3639,  3639,  3640,  3640,  3641,  3642,  3643,
    3643,  3644,  3645,  3647,  3653,  3659,  3668,  3682,  3688,  3694
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
  "DOTS_IN_IDENT", "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE",
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "FAKENAME",
  "IRCD_FLAGS", "FLATTEN_LINKS", "FFAILED_OPERLOG", "FKILLLOG",
  "FKLINELOG", "FGLINELOG", "FIOERRLOG", "FOPERLOG", "FOPERSPYLOG",
  "FUSERLOG", "GECOS", "GENERAL", "GLINE", "GLINES", "GLINE_EXEMPT",
  "GLINE_LOG", "GLINE_TIME", "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6",
  "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN",
  "HIDDEN_ADMIN", "HIDDEN_NAME", "HIDDEN_OPER", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK", "IDLETIME",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "LOGGING", "LOG_LEVEL", "MAX_ACCEPT",
  "MAX_BANS", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
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
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "T_SSL_CONNECTION_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "SERVLINK_PATH", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SILENT", "SPOOF",
  "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CCONN_FULL", "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE",
  "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS",
  "T_LOGPATH", "T_L_CRIT", "T_L_DEBUG", "T_L_ERROR", "T_L_INFO",
  "T_L_NOTICE", "T_L_TRACE", "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE",
  "T_OPERWALL", "T_REJ", "T_SERVER", "T_SERVNOTICE", "T_SKILL", "T_SPY",
  "T_SSL", "T_UMODES", "T_UNAUTH", "T_UNRESV", "T_UNXLINE", "T_WALLOP",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX",
  "USE_KNOCK", "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6",
  "XLINE", "WARN", "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','",
  "$accept", "conf", "conf_item", "timespec_", "timespec", "sizespec_",
  "sizespec", "modules_entry", "modules_items", "modules_item",
  "modules_module", "modules_path", "serverinfo_entry", "serverinfo_items",
  "serverinfo_item", "serverinfo_ssl_connection_method", "$@1",
  "method_types", "method_type_item", "serverinfo_ssl_certificate_file",
  "serverinfo_rsa_private_key_file", "serverinfo_name", "serverinfo_sid",
  "serverinfo_description", "serverinfo_network_name",
  "serverinfo_network_desc", "serverinfo_vhost", "serverinfo_vhost6",
  "serverinfo_max_clients", "serverinfo_hub", "admin_entry", "admin_items",
  "admin_item", "admin_name", "admin_email", "admin_description",
  "logging_entry", "logging_items", "logging_item", "logging_path",
  "logging_oper_log", "logging_fuserlog", "logging_ffailed_operlog",
  "logging_foperlog", "logging_foperspylog", "logging_fglinelog",
  "logging_fklinelog", "logging_ioerrlog", "logging_killlog",
  "logging_log_level", "logging_use_logging", "oper_entry", "$@2",
  "oper_name_b", "oper_items", "oper_item", "oper_name", "oper_name_t",
  "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@3",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@4",
  "oper_flags_items", "oper_flags_item", "$@5", "$@6",
  "oper_flags_item_atom", "class_entry", "$@7", "class_name_b",
  "class_items", "class_item", "class_name", "class_name_t",
  "class_ping_time", "class_ping_warning", "class_number_per_ip",
  "class_connectfreq", "class_max_number", "class_max_global",
  "class_max_local", "class_max_ident", "class_sendq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "listen_entry", "$@8", "listen_flags", "$@9",
  "listen_flags_items", "listen_flags_item", "listen_items", "listen_item",
  "listen_port", "$@10", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "$@11", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_class", "auth_encrypted", "auth_flags",
  "$@12", "auth_flags_items", "auth_flags_item", "$@13", "$@14",
  "auth_flags_item_atom", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@15", "resv_items", "resv_item",
  "resv_creason", "resv_channel", "resv_nick", "shared_entry", "$@16",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@17", "shared_types", "shared_type_item",
  "cluster_entry", "$@18", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@19", "cluster_types", "cluster_type_item",
  "connect_entry", "$@20", "connect_name_b", "connect_items",
  "connect_item", "connect_name", "connect_name_t", "connect_host",
  "connect_vhost", "connect_send_password", "connect_accept_password",
  "connect_port", "connect_aftype", "connect_fakename", "connect_flags",
  "$@21", "connect_flags_items", "connect_flags_item", "$@22", "$@23",
  "connect_flags_item_atom", "connect_rsa_public_key_file",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_cipher_preference", "kill_entry", "$@24",
  "kill_type", "$@25", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@26",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@27",
  "gecos_flags", "$@28", "gecos_flags_items", "gecos_flags_item",
  "gecos_items", "gecos_item", "gecos_name", "gecos_reason",
  "general_entry", "general_items", "general_item", "general_max_watch",
  "general_gline_min_cidr", "general_gline_min_cidr6",
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
  "$@29", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@30", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "gline_entry", "$@31", "gline_items",
  "gline_item", "gline_enable", "gline_duration", "gline_logging", "$@32",
  "gline_logging_types", "gline_logging_type_item", "gline_user",
  "gline_server", "gline_action", "$@33", "gdeny_types", "gdeny_type_item",
  "channel_entry", "channel_items", "channel_item",
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
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   266,   267,   267,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   271,   271,   272,   272,   272,   272,
     273,   274,   274,   275,   275,   275,   276,   277,   278,   279,
     279,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   282,   281,   283,   283,   284,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   297,   298,   298,   298,   298,   299,   300,
     301,   302,   303,   303,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   315,   315,
     315,   315,   315,   315,   316,   318,   317,   319,   319,   320,
     320,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   323,   324,   325,   326,   327,   328,   330,   329,   331,
     331,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     332,   332,   332,   332,   332,   332,   332,   332,   332,   332,
     334,   333,   335,   335,   337,   336,   338,   336,   339,   339,
     339,   339,   339,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   339,   339,   341,   340,   342,   342,   343,   343,
     344,   344,   344,   344,   344,   344,   344,   344,   344,   344,
     344,   344,   344,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   360,   359,
     362,   361,   363,   363,   364,   364,   364,   365,   365,   366,
     366,   366,   366,   366,   368,   367,   369,   369,   370,   370,
     371,   372,   374,   373,   375,   375,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   377,   378,   379,   380,   382,
     381,   383,   383,   385,   384,   386,   384,   387,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   388,   389,   390,
     392,   391,   393,   393,   394,   394,   394,   394,   395,   396,
     397,   399,   398,   400,   400,   401,   401,   401,   401,   402,
     403,   405,   404,   406,   406,   407,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   409,   408,   410,   410,
     411,   411,   411,   412,   414,   413,   415,   415,   416,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   418,
     417,   419,   419,   420,   420,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   429,
     430,   432,   431,   433,   433,   435,   434,   436,   434,   437,
     437,   437,   437,   437,   438,   439,   440,   441,   442,   443,
     445,   444,   447,   446,   448,   448,   449,   450,   450,   451,
     451,   451,   451,   452,   453,   455,   454,   456,   456,   457,
     457,   457,   458,   459,   460,   461,   461,   462,   462,   463,
     465,   464,   467,   466,   468,   468,   469,   470,   470,   471,
     471,   471,   471,   472,   473,   474,   475,   475,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   504,   505,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   527,   526,   528,   528,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   529,   529,
     529,   529,   529,   529,   529,   529,   529,   529,   531,   530,
     532,   532,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   533,   533,   533,   533,   533,   533,   533,   533,   533,
     533,   534,   535,   536,   537,   539,   538,   540,   540,   541,
     541,   541,   541,   541,   541,   541,   542,   543,   545,   544,
     546,   546,   547,   547,   548,   549,   551,   550,   552,   552,
     553,   553,   554,   555,   555,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   556,   556,   556,   556,   556,   556,
     556,   556,   556,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   576,   577,   577,   577,   577,   577,
     577,   577,   577,   578,   579,   580,   581,   582,   583,   584
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
       1,     1,     1,     2,     0,     5,     3,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     7,     0,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     7,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       7,     0,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     4,
       0,     6,     0,     5,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     0,     5,
       3,     1,     1,     1,     4,     4,     0,     5,     3,     1,
       1,     1,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   194,   349,   415,     0,
     430,     0,   605,   252,   400,   228,     0,     0,   125,   290,
       0,     0,   301,   326,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   196,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    86,    85,   653,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   634,   652,   647,   635,
     636,   637,   638,   640,   641,   642,   643,   639,   644,   645,
     646,   648,   649,   650,   651,   215,     0,   197,   372,     0,
     352,     0,   428,     0,     0,   426,   427,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   578,     0,   555,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   447,   502,   497,   498,   495,
     499,   500,   496,   458,   448,   449,   487,   450,   451,   452,
     453,   454,   455,   456,   457,   492,   459,   460,   461,   462,
     501,   464,   469,   465,   467,   466,   481,   482,   468,   470,
     471,   472,   473,   475,   474,   463,   477,   486,   488,   489,
     478,   479,   493,   494,   491,   480,   476,   484,   485,   483,
     490,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    98,   105,    99,   103,   100,   101,   104,   102,
      96,    97,     0,     0,     0,     0,    42,    43,    44,   141,
       0,   128,     0,   682,     0,     0,     0,     0,     0,     0,
       0,     0,   674,   675,   676,   680,   677,   679,   678,   681,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,    50,    62,    61,    58,    51,    60,
      54,    55,    56,    52,    59,    57,    53,     0,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   633,     0,     0,   421,     0,     0,
       0,   418,   419,   420,     0,     0,   425,   442,     0,     0,
     432,   441,     0,   438,   439,   440,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   446,   615,   626,     0,     0,   618,     0,     0,
       0,   608,   609,   610,   611,   612,   613,   614,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,   263,   259,   260,   261,   262,   412,     0,   402,
       0,   411,     0,   408,   409,   410,     0,   230,     0,     0,
       0,   240,     0,   238,   239,   241,   242,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    45,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,     0,     0,   673,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   311,     0,     0,   304,   305,   306,   307,
       0,     0,   334,     0,   329,   330,   331,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     632,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   200,   203,   204,
     206,   207,   208,   209,   210,   211,   212,   201,   202,   205,
       0,     0,     0,     0,     0,     0,     0,   381,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   354,   355,   356,
     357,   358,   359,   361,   360,   362,   363,   368,   367,   364,
     365,   366,   369,     0,     0,     0,   417,     0,   424,     0,
       0,     0,     0,   437,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,   445,     0,     0,     0,     0,     0,     0,     0,
     607,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,     0,   407,   243,     0,     0,
       0,     0,     0,   237,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    91,     0,     0,    40,     0,     0,     0,   170,
       0,     0,     0,   147,     0,     0,   130,   131,   132,   133,
     136,   137,   135,   134,   138,   297,     0,     0,     0,     0,
     292,     0,     0,     0,     0,     0,     0,     0,   672,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    48,   308,     0,     0,     0,     0,   303,   332,     0,
       0,     0,   328,    90,    89,    88,   669,   666,   665,   654,
     656,    26,    26,    26,    26,    26,    28,    27,   660,   661,
     664,   662,   667,   668,   670,   671,   663,   655,   657,   658,
     659,   213,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   198,   370,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   353,     0,     0,   416,   429,     0,
       0,     0,   431,   516,   520,   507,   536,   549,   548,   603,
     553,   514,   545,   551,   515,   505,   506,   523,   512,   544,
     513,   526,   511,   525,   524,   519,   518,   517,   546,   504,
     543,   601,   602,   540,   537,   582,   598,   599,   583,   584,
     585,   586,   593,   587,   596,   600,   589,   594,   590,   595,
     588,   592,   591,   597,     0,   581,   542,   559,   575,   576,
     560,   561,   562,   563,   570,   564,   573,   577,   566,   571,
     567,   572,   565,   569,   568,   574,     0,   558,   535,   538,
     552,   509,   547,   510,   539,   528,   533,   534,   531,   532,
     529,   530,   522,   521,    34,    34,    34,    36,    35,   604,
     554,   541,   550,   508,   527,     0,     0,     0,     0,     0,
       0,   606,     0,     0,   275,     0,     0,     0,     0,     0,
     253,     0,     0,     0,   401,     0,     0,     0,   248,   244,
     247,   229,   110,   116,   114,   113,   115,   111,   112,   109,
     117,   123,   118,   122,   120,   121,   119,   108,   107,   124,
      46,    47,   139,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,     0,     0,     0,   291,   688,   683,   687,
     685,   689,   684,   686,    74,    80,    72,    76,    75,    71,
      70,    68,    69,     0,    67,    73,    79,    77,    78,     0,
       0,     0,   302,     0,     0,   327,    29,    30,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   195,     0,     0,     0,     0,     0,
       0,     0,   387,     0,     0,     0,     0,     0,     0,     0,
       0,   350,   422,   423,   443,   444,   436,     0,   435,   579,
       0,   556,     0,    37,    38,    39,   631,   630,     0,   629,
     617,   616,   623,   622,     0,   621,   625,   624,   267,   268,
     273,     0,   272,     0,   266,   289,   288,   287,   265,   414,
     406,     0,   405,   413,   235,   236,   234,     0,   233,   251,
     250,     0,     0,     0,     0,     0,   176,     0,     0,     0,
       0,     0,   126,   299,   300,   298,    65,     0,   309,   315,
     321,   325,   324,   323,   320,   316,   319,   322,   317,   318,
       0,   314,   310,   333,   338,   344,   348,   347,   346,   343,
     339,   342,   345,   340,   341,     0,   337,   225,   226,   219,
     221,   223,   222,   220,   214,   227,   218,   216,   217,   224,
     376,   378,   379,   399,   398,   395,   380,   385,     0,   384,
       0,   373,   396,   397,   371,   377,   394,   375,   374,   433,
       0,   580,   557,   627,     0,   619,     0,     0,   270,   275,
     281,   282,   278,   284,   280,   279,   286,   283,   285,   277,
     276,   403,     0,   231,     0,   249,   246,   245,   146,   144,
     174,     0,   173,     0,   140,   143,   145,   151,   167,   168,
     152,   153,   154,   155,   162,   156,   165,   169,   158,   163,
     159,   164,   157,   161,   160,   166,     0,   150,   142,    66,
     312,     0,   335,     0,     0,   382,   387,   391,   392,   389,
     390,   393,   388,   434,   628,   620,   274,   271,   404,   232,
       0,   171,   176,   186,   184,   193,   183,   178,   187,   191,
     180,   188,   190,   185,   179,   192,   189,   181,   182,   177,
     148,     0,   313,   336,   386,   383,   175,   172,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   836,   837,   987,   988,    25,   275,   276,
     277,   278,    26,   313,   314,   315,   534,  1073,  1074,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
      27,    71,    72,    73,    74,    75,    28,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,    29,    61,   280,   775,   776,   777,   281,   778,   779,
     780,   781,   782,   783,  1049,  1306,  1307,   784,  1045,  1281,
    1282,  1330,  1283,  1349,    30,    49,   116,   595,   596,   597,
     117,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,    31,    58,   481,   738,  1167,  1168,   482,
     483,   484,  1173,  1019,  1020,   485,   486,    32,    56,   457,
     458,   459,   460,   461,   462,   463,   724,  1151,  1152,  1257,
    1153,  1270,   464,   465,   466,    33,    62,   512,   513,   514,
     515,   516,    34,    65,   545,   546,   547,   548,   549,   814,
    1200,  1201,    35,    66,   553,   554,   555,   556,   820,  1215,
    1216,    36,    50,   119,   626,   627,   628,   120,   629,   630,
     631,   632,   633,   634,   635,   636,   874,  1238,  1239,  1314,
    1240,  1322,   637,   638,   639,   640,   641,   642,    37,    57,
     471,   733,  1161,  1162,   472,   473,   474,   475,    38,    51,
     360,   361,   362,   363,    39,   124,   125,   126,    40,    53,
     371,   651,  1127,  1128,   372,   373,   374,   375,    41,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   410,   966,   967,   236,   408,   944,   945,   237,   238,
     239,   240,    42,    55,   440,   441,   442,   443,   444,   716,
    1144,  1145,   445,   446,   447,   713,  1138,  1139,    43,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,    44,
     291,   292,   293,   294,   295,   296,   297,   298,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -944
static const yytype_int16 yypact[] =
{
    -944,   692,  -944,  -105,  -257,  -249,  -944,  -944,  -944,  -236,
    -944,  -215,  -944,  -944,  -944,  -944,  -212,  -210,  -944,  -944,
    -193,  -184,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,     7,   605,   -69,
     -64,  -166,     8,  -151,   420,  -134,  -124,  -101,   -95,   417,
       4,    27,   -60,   309,   467,   -52,   -39,   -14,    -9,    -6,
      11,     9,  -944,  -944,  -944,  -944,  -944,    41,    43,    53,
      63,    72,    74,    85,    94,    95,    96,    97,    99,   102,
     105,   106,   107,   108,   109,   142,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,    22,  -944,  -944,    61,
    -944,   147,  -944,   111,    20,  -944,  -944,    30,  -944,   112,
     113,   115,   116,   118,   121,   128,   139,   141,   143,   144,
     146,   148,   149,   150,   151,   152,   155,   158,   159,   161,
     162,   167,   170,   173,   176,   178,   179,   180,   182,   187,
     193,  -944,   194,  -944,   196,   198,   201,   217,   219,   220,
     221,   222,   223,   224,   225,   226,   230,   231,   236,   237,
     238,   241,   246,   253,    49,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   333,   519,    24,   172,    80,   254,   255,   260,   263,
     265,   269,   276,   277,   278,   280,   282,   283,    46,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,   145,   284,   286,    21,  -944,  -944,  -944,  -944,
     126,  -944,    77,  -944,   287,   289,   290,   291,   293,   298,
     305,    34,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     156,   307,   308,   310,   312,   313,   314,   315,  -944,   316,
     319,   320,   321,   199,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,    25,    31,  -944,
     257,   281,   432,   328,  -944,   396,   163,   466,   401,   402,
     469,   469,   470,   472,   409,   410,   478,   469,   414,   421,
     422,   425,   427,   365,  -944,   664,   444,  -944,   363,   364,
      32,  -944,  -944,  -944,   475,   370,  -944,  -944,   368,   374,
    -944,  -944,     3,  -944,  -944,  -944,   436,   469,   443,   469,
     510,   489,   512,   448,   450,   517,   496,   454,   523,   525,
     526,   462,   469,   463,   468,   469,   514,   471,   540,   541,
     469,   542,   546,   528,   547,   552,   487,   491,   426,   498,
     434,   469,   469,   501,   469,   550,   508,   511,   515,    81,
     153,   518,   521,   469,   469,   583,   469,   522,   524,   527,
     531,   456,  -944,  -944,  -944,   473,   474,  -944,   476,   477,
      14,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   465,   480,
     481,  -944,   482,   483,   484,   488,   490,   171,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   494,  -944,
     497,  -944,    19,  -944,  -944,  -944,   492,  -944,   500,   506,
     507,  -944,   125,  -944,  -944,  -944,  -944,  -944,   576,   577,
     580,   582,   585,   588,   597,   608,   175,   611,   622,   581,
     520,  -944,  -944,   624,   626,   529,  -944,   538,   530,   532,
     533,   536,     2,  -944,  -944,  -944,  -944,   586,   590,   591,
     638,   596,   603,   469,   543,  -944,  -944,   651,   609,   659,
     660,   663,   665,   666,   558,   669,   694,   670,   673,   567,
    -944,   569,   568,  -944,   570,    28,  -944,  -944,  -944,  -944,
     574,   572,  -944,    10,  -944,  -944,  -944,   578,   579,   584,
    -944,   587,   589,   594,   602,   604,   169,   606,   607,   610,
     615,   616,   627,   631,   632,   634,   635,   636,   637,   639,
    -944,   640,   573,   621,   643,   647,   648,   650,   658,   661,
     668,   671,   672,   674,   676,   205,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     641,   680,   684,   685,   687,   688,   695,  -944,   698,   702,
     703,   705,   706,   707,   708,   709,   168,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   677,   690,   642,  -944,   654,  -944,   693,
     697,   710,   678,  -944,   714,   715,   716,   720,   724,   725,
     727,   728,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   750,   751,   752,   753,   754,   675,   755,   712,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   317,   772,   773,   774,   775,
     776,   777,  -944,   778,   469,   644,   779,   721,   780,   783,
    -944,  -944,   856,   701,   781,   885,   717,   886,   887,   892,
     786,  -944,   894,   785,   896,   790,  -944,  -944,   788,   899,
     900,   797,   794,  -944,   795,   796,   798,   799,   800,   801,
     802,   803,   804,   805,   806,   807,   808,   809,   810,   811,
     812,   813,  -944,   814,   815,  -944,   816,   817,   818,  -944,
     819,   820,   821,  -944,   822,    93,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,   904,   924,   925,   826,
    -944,   827,   828,   829,   830,   831,   832,   833,  -944,   834,
     835,   836,   837,   838,   839,   840,    60,   841,   842,   843,
     844,  -944,  -944,   926,   845,   952,   846,  -944,  -944,   954,
     847,   849,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   469,   469,   469,   469,   469,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,   980,   981,   469,   982,   983,   984,   985,   964,
     987,   988,   469,   469,   583,   860,  -944,  -944,   968,   136,
     969,   970,   927,   972,   863,   974,   975,   976,   977,  1000,
     979,   986,   989,   873,  -944,   874,   875,  -944,  -944,   876,
     877,   679,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -248,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -242,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,   583,   583,   583,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,     1,   878,   880,     5,   881,
     883,  -944,   884,   888,  1015,   889,   890,   891,   893,   895,
    -944,   897,   682,   898,  -944,    56,   901,   902,   649,   601,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   993,   950,   903,   999,  1001,  1003,   905,
    1006,   907,  -944,   909,   910,   911,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -227,  -944,  -944,  -944,  -944,  -944,   912,
     563,   913,  -944,   914,   614,  -944,  -944,  -944,  -944,  -944,
    -944,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     928,   929,   930,   931,  -944,   932,   933,   934,   935,   936,
     937,   938,  1030,   939,   940,   941,   942,   943,   944,   945,
     946,  -944,  -944,  -944,  -944,  -944,  -944,  -225,  -944,  -944,
     675,  -944,   712,  -944,  -944,  -944,  -944,  -944,  -192,  -944,
    -944,  -944,  -944,  -944,  -185,  -944,  -944,  -944,  -944,  -944,
    -944,  -174,  -944,   633,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -165,  -944,  -944,  -944,  -944,  -944,  -147,  -944,  -944,
    -944,  1032,   797,   947,   948,   949,  1034,   951,   953,   955,
     749,   956,  -944,  -944,  -944,  -944,  -944,    60,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     -57,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,   -38,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,    -8,  -944,
      18,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     679,  -944,  -944,  -944,     1,  -944,     5,   633,  -944,  1015,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,   682,  -944,    56,  -944,  -944,  -944,  -944,  -944,
    -944,    37,  -944,   433,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,    51,  -944,  -944,  -944,
    -944,   563,  -944,   614,    18,  -944,  1030,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
     433,  -944,  1034,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   749,  -944,  -944,  -944,  -944,  -944,  -944,  -944
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -944,  -944,  -944,  -768,  -340,  -943,  -423,  -944,  -944,   571,
    -944,  -944,  -944,  -944,   556,  -944,  -944,  -944,  -317,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,   859,  -944,  -944,  -944,  -944,  -944,   908,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,   411,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -418,  -944,  -944,  -944,
    -395,  -944,  -944,  -145,  -944,  -944,  -944,  -944,   592,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   -86,  -944,
     729,  -944,  -944,  -944,    47,  -944,  -944,  -944,  -944,  -944,
     782,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   -46,  -944,
    -944,   -42,  -944,  -944,  -944,  -944,  -944,  -944,   711,  -944,
    -944,  -944,  -944,  -944,  -944,   681,  -944,  -944,  -944,  -944,
    -944,   -93,  -944,  -944,  -944,   667,  -944,  -944,  -944,  -944,
     -92,  -944,  -944,  -944,  -944,   598,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,   -94,  -944,
    -944,   -89,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   -45,  -944,   784,  -944,  -944,  -944,  -944,
    -944,   868,  -944,  -944,  -944,  -944,  1105,  -944,  -944,  -944,
    -944,  -944,  -944,   -20,  -944,   861,  -944,  -944,  -944,  -944,
    1047,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,   100,  -944,  -944,  -944,   104,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,   823,  -944,  -944,  -944,  -944,
    -944,   -21,  -944,  -944,  -944,  -944,  -944,   -18,  -944,  -944,
    1142,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,  -944,
    -944,   957,  -944,  -944,  -944,  -944,  -944,  -944,  -944
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     567,   568,   706,   508,   367,   272,    47,   574,    67,   122,
      67,   550,  1136,  1129,    48,   433,  1142,  1130,   434,  1131,
     467,   122,   272,  1132,   509,   467,   541,    52,  1317,   541,
    1318,   367,   550,   357,  1186,   283,  1249,   655,  1187,   657,
    1250,  1133,  1134,  1135,    68,  1319,    68,   245,    54,  1320,
     128,    59,   670,    60,    69,   673,    69,   129,   130,   435,
     678,   131,   436,  1086,  1087,  1088,  1089,  1090,   132,  1253,
      63,   689,   690,  1254,   692,   284,  1255,   133,   508,    64,
    1256,   134,   135,   703,   704,   115,   707,  1258,   136,   285,
     118,  1259,   137,   138,   766,   139,  1271,   121,   123,   509,
    1272,   140,   246,   247,   248,   249,   250,   251,   252,   253,
     123,   286,   127,   287,  1273,   288,   289,   437,  1274,   767,
     141,   142,   358,   273,   368,   143,   476,   510,    70,   241,
      70,   551,   144,  1164,   290,   438,   145,   146,   147,   242,
     273,   148,   768,    76,   149,   150,   542,   769,   357,   542,
     254,   368,   551,   274,   151,    77,    45,    46,   511,   369,
     152,   153,   243,   154,   155,   156,   157,   158,   244,   610,
     274,   611,   448,   476,   612,   468,    78,    79,   159,   477,
     468,   279,    80,   797,    81,   255,   369,   160,   359,   161,
     162,   370,   163,   613,   614,   164,   165,   449,   552,   166,
     300,  1137,   510,   282,  1310,  1143,   581,   469,  1311,   478,
     167,   327,   469,   543,   770,   479,   543,   615,   370,   552,
     450,   616,   617,  1312,   328,   451,   477,  1313,   582,   583,
    1071,  1072,   168,   511,   169,   584,   301,   358,   170,    82,
      83,   771,   171,   172,   173,   174,   175,   329,    84,    85,
     176,   177,   618,  1315,   619,   330,   478,  1316,   331,   178,
     772,  1321,   479,   439,   789,   652,   256,   620,   470,    86,
      87,   333,   821,   470,   544,   332,   719,   544,   480,   697,
     698,   735,   365,   505,   302,   355,    88,    89,  1165,   621,
     816,   179,  1166,   180,   645,   562,   524,    90,  1331,   181,
     257,   566,  1332,   359,   182,   335,    91,   336,   500,   183,
     283,   431,  1350,   585,   586,   587,  1351,   337,   588,   452,
     303,   622,   304,   305,   356,   480,   589,   338,   453,   454,
     773,   984,   985,   986,   433,   623,   339,   434,   340,   590,
     591,   487,   774,   831,   832,   833,   834,   835,   624,   341,
     284,   699,   700,  1106,  1107,  1051,   592,   593,   342,   343,
     344,   345,   455,   346,   285,   306,   347,   307,   308,   348,
     349,   350,   351,   352,   996,   364,   376,   377,   435,   378,
     379,   436,   380,   309,   594,   381,   286,   742,   287,   507,
     288,   289,   382,    92,    93,    94,   752,   753,   754,   755,
     756,   757,   758,   383,   353,   384,   502,   385,   386,   290,
     387,   557,   388,   389,   390,   391,   392,   526,   245,   393,
     456,   128,   394,   395,   625,   396,   397,   310,   129,   130,
     883,   398,   131,   730,   399,   558,   437,   400,  1333,   132,
     401,  1103,   402,   403,   404,   610,   405,   611,   133,   705,
     612,   406,   134,   135,   438,   311,   312,   407,   409,   136,
     411,   539,   412,   137,   138,   413,   139,   865,   300,   613,
     614,  1334,   140,   246,   247,   248,   249,   250,   251,   252,
     253,   414,  1335,   415,   416,   417,   418,   419,   420,   421,
     422,   141,   142,   615,   423,   424,   143,   616,   617,  1336,
     425,   426,   427,   144,   301,   428,  1337,   145,   146,   147,
     429,  1338,   148,  1339,  1093,   149,   150,   430,   488,   489,
     448,   254,  1101,  1102,   490,   151,  1340,   491,   618,   492,
     619,   152,   153,   493,   154,   155,   156,   157,   158,   766,
     494,   495,   496,   620,   497,   449,   498,   499,   503,   159,
     504,   517,   302,   518,   519,   520,   255,   521,   160,  1341,
     161,   162,   522,   163,   767,   621,   164,   165,   450,   523,
     166,   527,   528,   451,   529,  1342,   530,   531,   532,   533,
     535,   167,   439,   536,   537,   538,   559,   768,   303,   560,
     304,   305,   769,  1343,   561,  1344,  1345,   622,   563,   564,
     565,   566,   569,   168,   570,   169,    76,   571,   572,   170,
     573,   623,   575,   171,   172,   173,   174,   175,    77,   576,
     577,   176,   177,   578,   624,   579,   580,   643,   644,   647,
     178,   648,   649,   306,   654,   307,   308,   256,   650,    78,
      79,   656,   658,   659,   660,    80,   661,    81,   662,   663,
     664,   309,   665,  1260,  1261,   666,  1189,   667,   668,   770,
     669,   671,   179,  1346,   180,   581,   672,   452,   674,   675,
     181,   257,   676,   677,   679,   182,   453,   454,   680,   682,
     183,  1347,   681,  1262,   683,   684,   771,   582,   583,   685,
     686,  1348,     2,     3,   584,   310,   687,     4,   688,   691,
     625,  1263,    82,    83,   693,   772,   694,  1204,  1264,   695,
     455,    84,    85,   696,     5,   705,   701,   712,     6,   702,
     708,     7,   709,   311,   312,   710,   721,  1265,     8,   711,
     744,   745,    86,    87,   746,  1190,   747,   714,   715,   748,
     717,   718,   749,     9,   722,   723,   725,   726,   727,    88,
      89,   750,   728,   737,   729,  1266,    10,    11,   732,    12,
      90,   734,   751,  1267,   739,   759,    13,  1191,   456,    91,
     740,   741,   585,   586,   587,   773,   760,   588,   763,   761,
     764,   762,  1192,    14,   791,   589,  1205,   774,   792,   793,
     765,   785,   794,    15,   795,    16,   786,   787,   590,   591,
     788,   796,  1193,  1194,   798,   799,  1268,   800,  1195,  1196,
    1197,  1198,    17,   801,   802,   592,   593,   803,  1206,   804,
     805,  1199,   806,   807,   809,  1269,   808,   810,   811,    18,
     812,   885,   813,  1207,   815,   818,   819,   852,  1126,   823,
     824,  1160,   997,   594,   886,   825,   506,   889,   826,  1006,
     827,   890,  1171,  1208,  1209,   828,    92,    93,    94,  1210,
    1211,  1212,  1213,   829,    19,   830,  1172,   838,   839,   540,
    1309,   840,  1214,    20,    21,   999,   841,   842,    22,    23,
     925,   926,   927,   928,   929,   853,   930,   931,   843,   932,
     933,   934,   844,   845,   935,   846,   847,   848,   849,  1003,
     850,   851,   867,   887,   936,   937,   938,   854,   939,   940,
     941,   855,   856,   942,   857,   888,   943,   947,   948,   949,
     950,   951,   858,   952,   953,   859,   954,   955,   956,  1018,
     334,   957,   860,  1358,  1000,   861,   862,  1357,   863,   892,
     864,   958,   959,   960,   868,   961,   962,   963,   869,   870,
     964,   871,   872,   965,  1287,  1288,  1289,  1290,  1291,   873,
    1292,  1293,   875,  1294,  1295,  1296,   876,   877,  1297,   878,
     879,   880,   881,   882,   891,   893,   894,   895,  1298,  1299,
    1300,   896,  1301,  1302,  1303,   897,   898,  1304,   899,   900,
    1305,   901,   902,   903,   904,   905,   906,   907,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   919,
    1002,   920,   921,   922,   923,   924,   946,   968,   969,   970,
     971,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   983,   989,   990,   991,   992,   993,   994,  1005,
    1007,  1008,   995,   998,  1001,  1004,  1009,  1010,  1011,  1012,
    1013,  1014,  1015,  1016,  1017,  1021,  1022,  1023,  1053,  1024,
    1025,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1037,  1038,  1039,  1040,  1041,  1042,  1054,  1055,
    1079,  1043,  1044,  1046,  1047,  1048,  1050,  1056,  1057,  1058,
    1059,  1060,  1061,  1062,  1063,  1064,  1065,  1066,  1067,  1068,
    1069,  1070,  1075,  1076,  1077,  1078,  1081,  1082,  1083,  1080,
    1085,  1084,  1091,  1092,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1104,  1105,  1108,  1109,  1110,  1111,  1112,  1113,  1114,
    1115,  1116,  1117,  1118,  1121,  1122,  1123,  1124,  1125,  1140,
    1119,  1141,  1146,  1120,  1147,  1148,  1150,  1174,  1175,  1149,
    1154,  1155,  1156,  1177,  1157,  1178,  1158,  1179,  1159,  1163,
    1181,  1237,  1169,  1170,  1275,  1280,   501,  1176,  1182,  1180,
    1183,  1184,  1185,  1188,  1202,  1203,  1217,  1218,  1219,  1220,
    1221,  1222,  1223,  1224,  1225,  1356,  1052,   866,  1329,  1226,
    1227,  1228,  1229,  1230,  1231,  1232,  1233,  1234,  1235,  1236,
    1241,  1242,  1243,  1244,  1245,  1246,  1247,  1248,  1277,  1278,
    1279,   743,  1284,  1327,  1285,  1326,  1286,  1308,  1352,  1276,
     822,  1353,  1355,   790,   884,  1354,   817,  1328,   646,   366,
    1323,   432,  1252,   653,  1251,  1325,  1324,   354,     0,   731,
       0,     0,     0,     0,     0,     0,     0,     0,   525,     0,
       0,     0,     0,     0,     0,     0,   736,     0,     0,     0,
       0,     0,     0,   720
};

static const yytype_int16 yycheck[] =
{
     340,   341,   425,     1,     1,     1,   263,   347,     1,     1,
       1,     1,    11,   261,   263,     1,    11,   265,     4,   261,
       1,     1,     1,   265,    22,     1,     1,   263,    10,     1,
      12,     1,     1,     1,   261,     1,   261,   377,   265,   379,
     265,   984,   985,   986,    37,    27,    37,     1,   263,    31,
       1,   263,   392,   263,    47,   395,    47,     8,     9,    45,
     400,    12,    48,   831,   832,   833,   834,   835,    19,   261,
     263,   411,   412,   265,   414,    41,   261,    28,     1,   263,
     265,    32,    33,   423,   424,   154,   426,   261,    39,    55,
     154,   265,    43,    44,     1,    46,   261,   263,    90,    22,
     265,    52,    56,    57,    58,    59,    60,    61,    62,    63,
      90,    77,   263,    79,   261,    81,    82,   103,   265,    26,
      71,    72,    90,   119,   121,    76,     1,   125,   121,   263,
     121,   121,    83,    77,   100,   121,    87,    88,    89,   263,
     119,    92,    49,     1,    95,    96,   121,    54,     1,   121,
     104,   121,   121,   149,   105,    13,   261,   262,   156,   156,
     111,   112,   263,   114,   115,   116,   117,   118,   263,     1,
     149,     3,     1,     1,     6,   156,    34,    35,   129,    54,
     156,   154,    40,   523,    42,   139,   156,   138,   156,   140,
     141,   188,   143,    25,    26,   146,   147,    26,   188,   150,
       1,   200,   125,   263,   261,   200,     1,   188,   265,    84,
     161,   263,   188,   188,   121,    90,   188,    49,   188,   188,
      49,    53,    54,   261,   263,    54,    54,   265,    23,    24,
     170,   171,   183,   156,   185,    30,    37,    90,   189,    97,
      98,   148,   193,   194,   195,   196,   197,   261,   106,   107,
     201,   202,    84,   261,    86,   264,    84,   265,   264,   210,
     167,   243,    90,   249,   262,   262,   220,    99,   249,   127,
     128,   262,   262,   249,   249,   264,   262,   249,   153,   198,
     199,   262,   262,   262,    85,   263,   144,   145,   232,   121,
     262,   242,   236,   244,   262,   132,   262,   155,   261,   250,
     254,   132,   265,   156,   255,   264,   164,   264,   262,   260,
       1,   262,   261,   108,   109,   110,   265,   264,   113,   148,
     121,   153,   123,   124,   263,   153,   121,   264,   157,   158,
     237,    14,    15,    16,     1,   167,   264,     4,   264,   134,
     135,   261,   249,   174,   175,   176,   177,   178,   180,   264,
      41,   198,   199,   217,   218,   262,   151,   152,   264,   264,
     264,   264,   191,   264,    55,   166,   264,   168,   169,   264,
     264,   264,   264,   264,   714,   264,   264,   264,    45,   264,
     264,    48,   264,   184,   179,   264,    77,   262,    79,   263,
      81,    82,   264,   251,   252,   253,   221,   222,   223,   224,
     225,   226,   227,   264,   262,   264,   261,   264,   264,   100,
     264,   154,   264,   264,   264,   264,   264,   261,     1,   264,
     249,     1,   264,   264,   256,   264,   264,   228,     8,     9,
     262,   264,    12,   262,   264,   154,   103,   264,     5,    19,
     264,   864,   264,   264,   264,     1,   264,     3,    28,   132,
       6,   264,    32,    33,   121,   256,   257,   264,   264,    39,
     264,   262,   264,    43,    44,   264,    46,   262,     1,    25,
      26,    38,    52,    56,    57,    58,    59,    60,    61,    62,
      63,   264,    49,   264,   264,   264,   264,   264,   264,   264,
     264,    71,    72,    49,   264,   264,    76,    53,    54,    66,
     264,   264,   264,    83,    37,   264,    73,    87,    88,    89,
     264,    78,    92,    80,   854,    95,    96,   264,   264,   264,
       1,   104,   862,   863,   264,   105,    93,   264,    84,   264,
      86,   111,   112,   264,   114,   115,   116,   117,   118,     1,
     264,   264,   264,    99,   264,    26,   264,   264,   264,   129,
     264,   264,    85,   264,   264,   264,   139,   264,   138,   126,
     140,   141,   264,   143,    26,   121,   146,   147,    49,   264,
     150,   264,   264,    54,   264,   142,   264,   264,   264,   264,
     264,   161,   249,   264,   264,   264,   154,    49,   121,   261,
     123,   124,    54,   160,   198,   162,   163,   153,   132,   198,
     198,   132,   132,   183,   132,   185,     1,   198,   198,   189,
     132,   167,   198,   193,   194,   195,   196,   197,    13,   198,
     198,   201,   202,   198,   180,   198,   261,   264,   264,   154,
     210,   261,   264,   166,   198,   168,   169,   220,   264,    34,
      35,   198,   132,   154,   132,    40,   198,    42,   198,   132,
     154,   184,   198,    20,    21,   132,    93,   132,   132,   121,
     198,   198,   242,   230,   244,     1,   198,   148,   154,   198,
     250,   254,   132,   132,   132,   255,   157,   158,   132,   132,
     260,   248,   154,    50,   132,   198,   148,    23,    24,   198,
     264,   258,     0,     1,    30,   228,   198,     5,   264,   198,
     256,    68,    97,    98,   154,   167,   198,    93,    75,   198,
     191,   106,   107,   198,    22,   132,   198,   261,    26,   198,
     198,    29,   198,   256,   257,   198,   261,    94,    36,   198,
     154,   154,   127,   128,   154,   172,   154,   264,   264,   154,
     264,   264,   154,    51,   264,   264,   264,   264,   264,   144,
     145,   154,   264,   261,   264,   122,    64,    65,   264,    67,
     155,   264,   154,   130,   264,   154,    74,   204,   249,   164,
     264,   264,   108,   109,   110,   237,   154,   113,   154,   198,
     154,   261,   219,    91,   198,   121,   172,   249,   198,   198,
     261,   261,   154,   101,   198,   103,   264,   264,   134,   135,
     264,   198,   239,   240,   261,   154,   173,   198,   245,   246,
     247,   248,   120,   154,   154,   151,   152,   154,   204,   154,
     154,   258,   264,   154,   154,   192,   132,   154,   261,   137,
     261,   154,   264,   219,   264,   261,   264,   264,   159,   261,
     261,   159,   198,   179,   154,   261,   275,   154,   261,   132,
     261,   154,   203,   239,   240,   261,   251,   252,   253,   245,
     246,   247,   248,   261,   172,   261,   265,   261,   261,   313,
    1187,   261,   258,   181,   182,   154,   261,   261,   186,   187,
     205,   206,   207,   208,   209,   264,   211,   212,   261,   214,
     215,   216,   261,   261,   219,   261,   261,   261,   261,   198,
     261,   261,   261,   261,   229,   230,   231,   264,   233,   234,
     235,   264,   264,   238,   264,   261,   241,   205,   206,   207,
     208,   209,   264,   211,   212,   264,   214,   215,   216,   132,
      71,   219,   264,  1351,   154,   264,   264,  1332,   264,   261,
     264,   229,   230,   231,   264,   233,   234,   235,   264,   264,
     238,   264,   264,   241,   205,   206,   207,   208,   209,   264,
     211,   212,   264,   214,   215,   216,   264,   264,   219,   264,
     264,   264,   264,   264,   264,   261,   261,   261,   229,   230,
     231,   261,   233,   234,   235,   261,   261,   238,   261,   261,
     241,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     154,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   154,
     154,   154,   264,   264,   261,   264,   154,   261,   154,   264,
     154,   261,   264,   154,   154,   261,   261,   261,   154,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   154,   154,
     154,   264,   264,   264,   264,   264,   264,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   154,   261,   154,   264,
     261,   264,   132,   132,   132,   132,   132,   132,   154,   132,
     132,   261,   154,   154,   154,   198,   154,   264,   154,   154,
     154,   154,   132,   154,   261,   261,   261,   261,   261,   261,
     154,   261,   261,   154,   261,   261,   131,   154,   198,   261,
     261,   261,   261,   154,   261,   154,   261,   154,   261,   261,
     154,   131,   261,   261,   132,   131,   258,   264,   261,   264,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,  1330,   775,   595,  1274,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   482,   261,  1259,   261,  1257,   261,   261,  1311,  1172,
     553,  1313,  1316,   512,   626,  1314,   545,  1272,   360,   124,
    1250,   184,  1132,   372,  1130,  1256,  1254,    95,    -1,   457,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   291,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   472,    -1,    -1,    -1,
      -1,    -1,    -1,   440
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   267,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   101,   103,   120,   137,   172,
     181,   182,   186,   187,   268,   273,   278,   296,   302,   317,
     340,   359,   373,   391,   398,   408,   417,   444,   454,   460,
     464,   474,   538,   554,   575,   261,   262,   263,   263,   341,
     418,   455,   263,   465,   263,   539,   374,   445,   360,   263,
     263,   318,   392,   263,   263,   399,   409,     1,    37,    47,
     121,   297,   298,   299,   300,   301,     1,    13,    34,    35,
      40,    42,    97,    98,   106,   107,   127,   128,   144,   145,
     155,   164,   251,   252,   253,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   154,   342,   346,   154,   419,
     423,   263,     1,    90,   461,   462,   463,   263,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    46,
      52,    71,    72,    76,    83,    87,    88,    89,    92,    95,
      96,   105,   111,   112,   114,   115,   116,   117,   118,   129,
     138,   140,   141,   143,   146,   147,   150,   161,   183,   185,
     189,   193,   194,   195,   196,   197,   201,   202,   210,   242,
     244,   250,   255,   260,   475,   476,   477,   478,   479,   480,
     481,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,   526,   530,   534,   535,   536,
     537,   263,   263,   263,   263,     1,    56,    57,    58,    59,
      60,    61,    62,    63,   104,   139,   220,   254,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     1,   119,   149,   274,   275,   276,   277,   154,
     319,   323,   263,     1,    41,    55,    77,    79,    81,    82,
     100,   576,   577,   578,   579,   580,   581,   582,   583,   584,
       1,    37,    85,   121,   123,   124,   166,   168,   169,   184,
     228,   256,   257,   279,   280,   281,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   263,   263,   261,
     264,   264,   264,   262,   298,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   556,   263,   263,     1,    90,   156,
     456,   457,   458,   459,   264,   262,   462,     1,   121,   156,
     188,   466,   470,   471,   472,   473,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   531,   264,
     527,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   476,     1,     4,    45,    48,   103,   121,   249,
     540,   541,   542,   543,   544,   548,   549,   550,     1,    26,
      49,    54,   148,   157,   158,   191,   249,   375,   376,   377,
     378,   379,   380,   381,   388,   389,   390,     1,   156,   188,
     249,   446,   450,   451,   452,   453,     1,    54,    84,    90,
     153,   361,   365,   366,   367,   371,   372,   261,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     262,   304,   261,   264,   264,   262,   275,   263,     1,    22,
     125,   156,   393,   394,   395,   396,   397,   264,   264,   264,
     264,   264,   264,   264,   262,   577,   261,   264,   264,   264,
     264,   264,   264,   264,   282,   264,   264,   264,   264,   262,
     280,     1,   121,   188,   249,   400,   401,   402,   403,   404,
       1,   121,   188,   410,   411,   412,   413,   154,   154,   154,
     261,   198,   132,   132,   198,   198,   132,   270,   270,   132,
     132,   198,   198,   132,   270,   198,   198,   198,   198,   198,
     261,     1,    23,    24,    30,   108,   109,   110,   113,   121,
     134,   135,   151,   152,   179,   343,   344,   345,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       1,     3,     6,    25,    26,    49,    53,    54,    84,    86,
      99,   121,   153,   167,   180,   256,   420,   421,   422,   424,
     425,   426,   427,   428,   429,   430,   431,   438,   439,   440,
     441,   442,   443,   264,   264,   262,   457,   154,   261,   264,
     264,   467,   262,   471,   198,   270,   198,   270,   132,   154,
     132,   198,   198,   132,   154,   198,   132,   132,   132,   198,
     270,   198,   198,   270,   154,   198,   132,   132,   270,   132,
     132,   154,   132,   132,   198,   198,   264,   198,   264,   270,
     270,   198,   270,   154,   198,   198,   198,   198,   199,   198,
     199,   198,   198,   270,   270,   132,   272,   270,   198,   198,
     198,   198,   261,   551,   264,   264,   545,   264,   264,   262,
     541,   261,   264,   264,   382,   264,   264,   264,   264,   264,
     262,   376,   264,   447,   264,   262,   451,   261,   362,   264,
     264,   264,   262,   366,   154,   154,   154,   154,   154,   154,
     154,   154,   221,   222,   223,   224,   225,   226,   227,   154,
     154,   198,   261,   154,   154,   261,     1,    26,    49,    54,
     121,   148,   167,   237,   249,   320,   321,   322,   324,   325,
     326,   327,   328,   329,   333,   261,   264,   264,   264,   262,
     394,   198,   198,   198,   154,   198,   198,   270,   261,   154,
     198,   154,   154,   154,   154,   154,   264,   154,   132,   154,
     154,   261,   261,   264,   405,   264,   262,   401,   261,   264,
     414,   262,   411,   261,   261,   261,   261,   261,   261,   261,
     261,   174,   175,   176,   177,   178,   269,   270,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   262,   344,   261,   264,   264,
     264,   264,   264,   264,   432,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   421,   154,   154,   261,   261,   154,
     154,   264,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   205,   206,   207,   208,   209,
     211,   212,   214,   215,   216,   219,   229,   230,   231,   233,
     234,   235,   238,   241,   532,   533,   261,   205,   206,   207,
     208,   209,   211,   212,   214,   215,   216,   219,   229,   230,
     231,   233,   234,   235,   238,   241,   528,   529,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,    14,    15,    16,   271,   272,   261,
     261,   261,   261,   261,   261,   264,   270,   198,   264,   154,
     154,   261,   154,   198,   264,   154,   132,   154,   154,   154,
     261,   154,   264,   154,   261,   264,   154,   154,   132,   369,
     370,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   264,   264,   334,   264,   264,   264,   330,
     264,   262,   321,   154,   154,   154,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   170,   171,   283,   284,   261,   261,   261,   261,   154,
     264,   154,   261,   154,   264,   261,   269,   269,   269,   269,
     269,   132,   132,   270,   132,   132,   132,   132,   154,   132,
     132,   270,   270,   272,   261,   154,   217,   218,   154,   154,
     198,   154,   264,   154,   154,   154,   154,   132,   154,   154,
     154,   261,   261,   261,   261,   261,   159,   468,   469,   261,
     265,   261,   265,   271,   271,   271,    11,   200,   552,   553,
     261,   261,    11,   200,   546,   547,   261,   261,   261,   261,
     131,   383,   384,   386,   261,   261,   261,   261,   261,   261,
     159,   448,   449,   261,    77,   232,   236,   363,   364,   261,
     261,   203,   265,   368,   154,   198,   264,   154,   154,   154,
     264,   154,   261,   261,   261,   261,   261,   265,   261,    93,
     172,   204,   219,   239,   240,   245,   246,   247,   248,   258,
     406,   407,   261,   261,    93,   172,   204,   219,   239,   240,
     245,   246,   247,   248,   258,   415,   416,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   131,   433,   434,
     436,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     265,   533,   529,   261,   265,   261,   265,   385,   261,   265,
      20,    21,    50,    68,    75,    94,   122,   130,   173,   192,
     387,   261,   265,   261,   265,   132,   370,   261,   261,   261,
     131,   335,   336,   338,   261,   261,   261,   205,   206,   207,
     208,   209,   211,   212,   214,   215,   216,   219,   229,   230,
     231,   233,   234,   235,   238,   241,   331,   332,   261,   284,
     261,   265,   261,   265,   435,   261,   265,    10,    12,    27,
      31,   243,   437,   469,   553,   547,   387,   384,   449,   364,
     337,   261,   265,     5,    38,    49,    66,    73,    78,    80,
      93,   126,   142,   160,   162,   163,   230,   248,   258,   339,
     261,   265,   407,   416,   437,   434,   339,   336,   332
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  if (yyn == YYPACT_NINF)
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

/* Line 1464 of yacc.c  */
#line 425 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 447 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 456 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 470 "ircd_parser.y"
    {
#ifndef STATIC_MODULES /* NOOP in the static case */
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
#endif
}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 478 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 500 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 506 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
  {
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_SSLV3))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
    if (!(ServerInfo.tls_version & CONF_SERVER_INFO_TLS_VERSION_TLSV1))
      SSL_CTX_set_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
  }
#endif
}
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 520 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 526 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 534 "ircd_parser.y"
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
                                     SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx))
    {
      yyerror(ERR_lib_error_string(ERR_get_error()));
      break;
    }
  }
#endif
}
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 568 "ircd_parser.y"
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

  case 72:

/* Line 1464 of yacc.c  */
#line 628 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2)
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

  case 73:

/* Line 1464 of yacc.c  */
#line 642 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
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

  case 74:

/* Line 1464 of yacc.c  */
#line 657 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 666 "ircd_parser.y"
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

  case 76:

/* Line 1464 of yacc.c  */
#line 680 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 689 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
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

  case 78:

/* Line 1464 of yacc.c  */
#line 717 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
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

  case 79:

/* Line 1464 of yacc.c  */
#line 747 "ircd_parser.y"
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

  case 80:

/* Line 1464 of yacc.c  */
#line 770 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
    {
      ServerInfo.hub = 1;
      delete_capability("HUB");
      add_capability("HUB", CAP_HUB, 1);
    }
    else if (ServerInfo.hub)
    {

      ServerInfo.hub = 0;
      delete_capability("HUB");
    }
  }
}
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 798 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 807 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 816 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 843 "ircd_parser.y"
    {
                        }
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 847 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 851 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 858 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 111:

/* Line 1464 of yacc.c  */
#line 865 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 112:

/* Line 1464 of yacc.c  */
#line 872 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 113:

/* Line 1464 of yacc.c  */
#line 879 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 114:

/* Line 1464 of yacc.c  */
#line 886 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 115:

/* Line 1464 of yacc.c  */
#line 893 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 116:

/* Line 1464 of yacc.c  */
#line 900 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 117:

/* Line 1464 of yacc.c  */
#line 907 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 118:

/* Line 1464 of yacc.c  */
#line 911 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 119:

/* Line 1464 of yacc.c  */
#line 915 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 120:

/* Line 1464 of yacc.c  */
#line 919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 121:

/* Line 1464 of yacc.c  */
#line 923 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 122:

/* Line 1464 of yacc.c  */
#line 927 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 123:

/* Line 1464 of yacc.c  */
#line 931 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 124:

/* Line 1464 of yacc.c  */
#line 937 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 125:

/* Line 1464 of yacc.c  */
#line 946 "ircd_parser.y"
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

  case 126:

/* Line 1464 of yacc.c  */
#line 959 "ircd_parser.y"
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

  case 140:

/* Line 1464 of yacc.c  */
#line 1046 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 141:

/* Line 1464 of yacc.c  */
#line 1058 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > OPERNICKLEN)
      yylval.string[OPERNICKLEN] = '\0';

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 142:

/* Line 1464 of yacc.c  */
#line 1070 "ircd_parser.y"
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

  case 143:

/* Line 1464 of yacc.c  */
#line 1104 "ircd_parser.y"
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

  case 144:

/* Line 1464 of yacc.c  */
#line 1116 "ircd_parser.y"
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

  case 145:

/* Line 1464 of yacc.c  */
#line 1127 "ircd_parser.y"
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

  case 146:

/* Line 1464 of yacc.c  */
#line 1169 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 147:

/* Line 1464 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 151:

/* Line 1464 of yacc.c  */
#line 1185 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 152:

/* Line 1464 of yacc.c  */
#line 1189 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 153:

/* Line 1464 of yacc.c  */
#line 1193 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 154:

/* Line 1464 of yacc.c  */
#line 1197 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 155:

/* Line 1464 of yacc.c  */
#line 1201 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 156:

/* Line 1464 of yacc.c  */
#line 1205 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 157:

/* Line 1464 of yacc.c  */
#line 1209 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 158:

/* Line 1464 of yacc.c  */
#line 1213 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 159:

/* Line 1464 of yacc.c  */
#line 1217 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 160:

/* Line 1464 of yacc.c  */
#line 1221 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 161:

/* Line 1464 of yacc.c  */
#line 1225 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 162:

/* Line 1464 of yacc.c  */
#line 1229 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 163:

/* Line 1464 of yacc.c  */
#line 1233 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 164:

/* Line 1464 of yacc.c  */
#line 1237 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 165:

/* Line 1464 of yacc.c  */
#line 1241 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 166:

/* Line 1464 of yacc.c  */
#line 1245 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 167:

/* Line 1464 of yacc.c  */
#line 1249 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 168:

/* Line 1464 of yacc.c  */
#line 1253 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 169:

/* Line 1464 of yacc.c  */
#line 1257 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 170:

/* Line 1464 of yacc.c  */
#line 1263 "ircd_parser.y"
    {
}
    break;

  case 174:

/* Line 1464 of yacc.c  */
#line 1267 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 176:

/* Line 1464 of yacc.c  */
#line 1268 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 178:

/* Line 1464 of yacc.c  */
#line 1271 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 179:

/* Line 1464 of yacc.c  */
#line 1278 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 180:

/* Line 1464 of yacc.c  */
#line 1285 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 181:

/* Line 1464 of yacc.c  */
#line 1292 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 182:

/* Line 1464 of yacc.c  */
#line 1299 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 183:

/* Line 1464 of yacc.c  */
#line 1306 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 184:

/* Line 1464 of yacc.c  */
#line 1313 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 185:

/* Line 1464 of yacc.c  */
#line 1320 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 186:

/* Line 1464 of yacc.c  */
#line 1327 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 187:

/* Line 1464 of yacc.c  */
#line 1334 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 188:

/* Line 1464 of yacc.c  */
#line 1341 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 189:

/* Line 1464 of yacc.c  */
#line 1348 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 190:

/* Line 1464 of yacc.c  */
#line 1355 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 191:

/* Line 1464 of yacc.c  */
#line 1362 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 192:

/* Line 1464 of yacc.c  */
#line 1369 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 193:

/* Line 1464 of yacc.c  */
#line 1376 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 194:

/* Line 1464 of yacc.c  */
#line 1389 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 195:

/* Line 1464 of yacc.c  */
#line 1396 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
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

  case 214:

/* Line 1464 of yacc.c  */
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:

/* Line 1464 of yacc.c  */
#line 1465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 216:

/* Line 1464 of yacc.c  */
#line 1474 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1464 of yacc.c  */
#line 1480 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1464 of yacc.c  */
#line 1486 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1464 of yacc.c  */
#line 1492 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1464 of yacc.c  */
#line 1498 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1464 of yacc.c  */
#line 1504 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1464 of yacc.c  */
#line 1510 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1464 of yacc.c  */
#line 1516 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1464 of yacc.c  */
#line 1522 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1464 of yacc.c  */
#line 1528 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1464 of yacc.c  */
#line 1534 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1464 of yacc.c  */
#line 1540 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1464 of yacc.c  */
#line 1549 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:

/* Line 1464 of yacc.c  */
#line 1556 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:

/* Line 1464 of yacc.c  */
#line 1565 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:

/* Line 1464 of yacc.c  */
#line 1571 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:

/* Line 1464 of yacc.c  */
#line 1575 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:

/* Line 1464 of yacc.c  */
#line 1579 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:

/* Line 1464 of yacc.c  */
#line 1589 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 248:

/* Line 1464 of yacc.c  */
#line 1594 "ircd_parser.y"
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

  case 249:

/* Line 1464 of yacc.c  */
#line 1608 "ircd_parser.y"
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

  case 250:

/* Line 1464 of yacc.c  */
#line 1628 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:

/* Line 1464 of yacc.c  */
#line 1637 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:

/* Line 1464 of yacc.c  */
#line 1649 "ircd_parser.y"
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

  case 253:

/* Line 1464 of yacc.c  */
#line 1661 "ircd_parser.y"
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

  case 265:

/* Line 1464 of yacc.c  */
#line 1723 "ircd_parser.y"
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

  case 266:

/* Line 1464 of yacc.c  */
#line 1760 "ircd_parser.y"
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

  case 267:

/* Line 1464 of yacc.c  */
#line 1773 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:

/* Line 1464 of yacc.c  */
#line 1782 "ircd_parser.y"
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

  case 269:

/* Line 1464 of yacc.c  */
#line 1793 "ircd_parser.y"
    {
}
    break;

  case 273:

/* Line 1464 of yacc.c  */
#line 1797 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 275:

/* Line 1464 of yacc.c  */
#line 1798 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 277:

/* Line 1464 of yacc.c  */
#line 1801 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 278:

/* Line 1464 of yacc.c  */
#line 1808 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 279:

/* Line 1464 of yacc.c  */
#line 1815 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 280:

/* Line 1464 of yacc.c  */
#line 1822 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 281:

/* Line 1464 of yacc.c  */
#line 1829 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 282:

/* Line 1464 of yacc.c  */
#line 1836 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 283:

/* Line 1464 of yacc.c  */
#line 1843 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 284:

/* Line 1464 of yacc.c  */
#line 1850 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 285:

/* Line 1464 of yacc.c  */
#line 1857 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 286:

/* Line 1464 of yacc.c  */
#line 1864 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 287:

/* Line 1464 of yacc.c  */
#line 1874 "ircd_parser.y"
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
      ilog(L_ERROR, "Spoofs must be less than %d..ignoring it", HOSTLEN);
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 288:

/* Line 1464 of yacc.c  */
#line 1893 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 289:

/* Line 1464 of yacc.c  */
#line 1903 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 290:

/* Line 1464 of yacc.c  */
#line 1916 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:

/* Line 1464 of yacc.c  */
#line 1923 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 298:

/* Line 1464 of yacc.c  */
#line 1935 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 299:

/* Line 1464 of yacc.c  */
#line 1944 "ircd_parser.y"
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

  case 300:

/* Line 1464 of yacc.c  */
#line 1959 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:

/* Line 1464 of yacc.c  */
#line 1972 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 302:

/* Line 1464 of yacc.c  */
#line 1980 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 309:

/* Line 1464 of yacc.c  */
#line 1991 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 310:

/* Line 1464 of yacc.c  */
#line 2000 "ircd_parser.y"
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

  case 311:

/* Line 1464 of yacc.c  */
#line 2022 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 315:

/* Line 1464 of yacc.c  */
#line 2029 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 316:

/* Line 1464 of yacc.c  */
#line 2033 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 317:

/* Line 1464 of yacc.c  */
#line 2037 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:

/* Line 1464 of yacc.c  */
#line 2041 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1464 of yacc.c  */
#line 2045 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 320:

/* Line 1464 of yacc.c  */
#line 2049 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 321:

/* Line 1464 of yacc.c  */
#line 2053 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 322:

/* Line 1464 of yacc.c  */
#line 2057 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 323:

/* Line 1464 of yacc.c  */
#line 2061 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:

/* Line 1464 of yacc.c  */
#line 2065 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:

/* Line 1464 of yacc.c  */
#line 2069 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:

/* Line 1464 of yacc.c  */
#line 2078 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:

/* Line 1464 of yacc.c  */
#line 2085 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 333:

/* Line 1464 of yacc.c  */
#line 2098 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:

/* Line 1464 of yacc.c  */
#line 2104 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:

/* Line 1464 of yacc.c  */
#line 2111 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:

/* Line 1464 of yacc.c  */
#line 2115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 340:

/* Line 1464 of yacc.c  */
#line 2119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 341:

/* Line 1464 of yacc.c  */
#line 2123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 342:

/* Line 1464 of yacc.c  */
#line 2127 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 343:

/* Line 1464 of yacc.c  */
#line 2131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:

/* Line 1464 of yacc.c  */
#line 2135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:

/* Line 1464 of yacc.c  */
#line 2139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 346:

/* Line 1464 of yacc.c  */
#line 2143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 347:

/* Line 1464 of yacc.c  */
#line 2147 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 348:

/* Line 1464 of yacc.c  */
#line 2151 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 349:

/* Line 1464 of yacc.c  */
#line 2160 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 350:

/* Line 1464 of yacc.c  */
#line 2178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 371:

/* Line 1464 of yacc.c  */
#line 2316 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 372:

/* Line 1464 of yacc.c  */
#line 2328 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name != NULL)
      yyerror("Multiple connect name entry");

    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 373:

/* Line 1464 of yacc.c  */
#line 2340 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 374:

/* Line 1464 of yacc.c  */
#line 2349 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 375:

/* Line 1464 of yacc.c  */
#line 2375 "ircd_parser.y"
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

  case 376:

/* Line 1464 of yacc.c  */
#line 2393 "ircd_parser.y"
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

  case 377:

/* Line 1464 of yacc.c  */
#line 2411 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 378:

/* Line 1464 of yacc.c  */
#line 2417 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 379:

/* Line 1464 of yacc.c  */
#line 2421 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 380:

/* Line 1464 of yacc.c  */
#line 2429 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 381:

/* Line 1464 of yacc.c  */
#line 2438 "ircd_parser.y"
    {
}
    break;

  case 385:

/* Line 1464 of yacc.c  */
#line 2442 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 387:

/* Line 1464 of yacc.c  */
#line 2443 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 389:

/* Line 1464 of yacc.c  */
#line 2446 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 390:

/* Line 1464 of yacc.c  */
#line 2457 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 391:

/* Line 1464 of yacc.c  */
#line 2464 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 392:

/* Line 1464 of yacc.c  */
#line 2471 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 393:

/* Line 1464 of yacc.c  */
#line 2478 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 394:

/* Line 1464 of yacc.c  */
#line 2488 "ircd_parser.y"
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

  case 395:

/* Line 1464 of yacc.c  */
#line 2529 "ircd_parser.y"
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

  case 396:

/* Line 1464 of yacc.c  */
#line 2540 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &hub_conf_list);
  }
}
    break;

  case 397:

/* Line 1464 of yacc.c  */
#line 2553 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp;

    yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
    DupString(yy_tmp->host, yylval.string);
    DupString(yy_tmp->user, "*");
    dlinkAdd(yy_tmp, &yy_tmp->node, &leaf_conf_list);
  }
}
    break;

  case 398:

/* Line 1464 of yacc.c  */
#line 2566 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 399:

/* Line 1464 of yacc.c  */
#line 2575 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
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
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 400:

/* Line 1464 of yacc.c  */
#line 2610 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 401:

/* Line 1464 of yacc.c  */
#line 2617 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s",
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
        ilog(L_ERROR, "Failed to add regular expression based K-Line: no PCRE support");
        break;
#endif
      }
      else
      {
        yy_aconf = map_to_conf(make_conf_item(KLINE_TYPE));

        DupString(yy_aconf->user, userbuf);
        DupString(yy_aconf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_aconf->reason, reasonbuf);
        else
          DupString(yy_aconf->reason, "No reason");
        add_conf_by_address(CONF_KILL, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 402:

/* Line 1464 of yacc.c  */
#line 2673 "ircd_parser.y"
    {
}
    break;

  case 406:

/* Line 1464 of yacc.c  */
#line 2678 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 413:

/* Line 1464 of yacc.c  */
#line 2687 "ircd_parser.y"
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

  case 414:

/* Line 1464 of yacc.c  */
#line 2706 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 415:

/* Line 1464 of yacc.c  */
#line 2715 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 416:

/* Line 1464 of yacc.c  */
#line 2719 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
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

  case 422:

/* Line 1464 of yacc.c  */
#line 2741 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 423:

/* Line 1464 of yacc.c  */
#line 2747 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 429:

/* Line 1464 of yacc.c  */
#line 2761 "ircd_parser.y"
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

  case 430:

/* Line 1464 of yacc.c  */
#line 2779 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 431:

/* Line 1464 of yacc.c  */
#line 2786 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s",
               errptr);
          break;
        }

        yy_conf = make_conf_item(RXLINE_TYPE);
        yy_conf->regexpname = exp_p;
#else
        ilog(L_ERROR, "Failed to add regular expression based X-Line: no PCRE support");
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

  case 432:

/* Line 1464 of yacc.c  */
#line 2826 "ircd_parser.y"
    {
}
    break;

  case 436:

/* Line 1464 of yacc.c  */
#line 2831 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 443:

/* Line 1464 of yacc.c  */
#line 2840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 444:

/* Line 1464 of yacc.c  */
#line 2846 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 504:

/* Line 1464 of yacc.c  */
#line 2891 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1464 of yacc.c  */
#line 2896 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1464 of yacc.c  */
#line 2901 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:

/* Line 1464 of yacc.c  */
#line 2906 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 508:

/* Line 1464 of yacc.c  */
#line 2911 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 509:

/* Line 1464 of yacc.c  */
#line 2916 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 510:

/* Line 1464 of yacc.c  */
#line 2921 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 511:

/* Line 1464 of yacc.c  */
#line 2926 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:

/* Line 1464 of yacc.c  */
#line 2931 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 513:

/* Line 1464 of yacc.c  */
#line 2936 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 514:

/* Line 1464 of yacc.c  */
#line 2941 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 515:

/* Line 1464 of yacc.c  */
#line 2946 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 516:

/* Line 1464 of yacc.c  */
#line 2951 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 517:

/* Line 1464 of yacc.c  */
#line 2956 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 518:

/* Line 1464 of yacc.c  */
#line 2961 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1464 of yacc.c  */
#line 2966 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:

/* Line 1464 of yacc.c  */
#line 2971 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:

/* Line 1464 of yacc.c  */
#line 2976 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1464 of yacc.c  */
#line 2981 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:

/* Line 1464 of yacc.c  */
#line 2987 "ircd_parser.y"
    {
  if (((yyvsp[(3) - (4)].number) > 0) && conf_parser_ctx.pass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 524:

/* Line 1464 of yacc.c  */
#line 2998 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 525:

/* Line 1464 of yacc.c  */
#line 3003 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 526:

/* Line 1464 of yacc.c  */
#line 3012 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 527:

/* Line 1464 of yacc.c  */
#line 3017 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 528:

/* Line 1464 of yacc.c  */
#line 3022 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 529:

/* Line 1464 of yacc.c  */
#line 3027 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 530:

/* Line 1464 of yacc.c  */
#line 3032 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 531:

/* Line 1464 of yacc.c  */
#line 3037 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 532:

/* Line 1464 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 533:

/* Line 1464 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 534:

/* Line 1464 of yacc.c  */
#line 3048 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 535:

/* Line 1464 of yacc.c  */
#line 3053 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:

/* Line 1464 of yacc.c  */
#line 3058 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:

/* Line 1464 of yacc.c  */
#line 3063 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 538:

/* Line 1464 of yacc.c  */
#line 3068 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 539:

/* Line 1464 of yacc.c  */
#line 3073 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 540:

/* Line 1464 of yacc.c  */
#line 3078 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 541:

/* Line 1464 of yacc.c  */
#line 3083 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 542:

/* Line 1464 of yacc.c  */
#line 3088 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 543:

/* Line 1464 of yacc.c  */
#line 3093 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 544:

/* Line 1464 of yacc.c  */
#line 3104 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 545:

/* Line 1464 of yacc.c  */
#line 3109 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 546:

/* Line 1464 of yacc.c  */
#line 3114 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 547:

/* Line 1464 of yacc.c  */
#line 3119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 548:

/* Line 1464 of yacc.c  */
#line 3128 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
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
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring default_cipher_preference -- no OpenSSL support");
#endif
}
    break;

  case 549:

/* Line 1464 of yacc.c  */
#line 3160 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 550:

/* Line 1464 of yacc.c  */
#line 3178 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 551:

/* Line 1464 of yacc.c  */
#line 3183 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 552:

/* Line 1464 of yacc.c  */
#line 3192 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 553:

/* Line 1464 of yacc.c  */
#line 3197 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 554:

/* Line 1464 of yacc.c  */
#line 3202 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 555:

/* Line 1464 of yacc.c  */
#line 3207 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 559:

/* Line 1464 of yacc.c  */
#line 3213 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 560:

/* Line 1464 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 561:

/* Line 1464 of yacc.c  */
#line 3219 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 562:

/* Line 1464 of yacc.c  */
#line 3222 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 563:

/* Line 1464 of yacc.c  */
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 564:

/* Line 1464 of yacc.c  */
#line 3228 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 565:

/* Line 1464 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 566:

/* Line 1464 of yacc.c  */
#line 3234 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 567:

/* Line 1464 of yacc.c  */
#line 3237 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 568:

/* Line 1464 of yacc.c  */
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 569:

/* Line 1464 of yacc.c  */
#line 3243 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 570:

/* Line 1464 of yacc.c  */
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 571:

/* Line 1464 of yacc.c  */
#line 3249 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 572:

/* Line 1464 of yacc.c  */
#line 3252 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 573:

/* Line 1464 of yacc.c  */
#line 3255 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 574:

/* Line 1464 of yacc.c  */
#line 3258 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 575:

/* Line 1464 of yacc.c  */
#line 3261 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 576:

/* Line 1464 of yacc.c  */
#line 3264 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 577:

/* Line 1464 of yacc.c  */
#line 3267 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 578:

/* Line 1464 of yacc.c  */
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 582:

/* Line 1464 of yacc.c  */
#line 3278 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 583:

/* Line 1464 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 584:

/* Line 1464 of yacc.c  */
#line 3284 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 585:

/* Line 1464 of yacc.c  */
#line 3287 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 586:

/* Line 1464 of yacc.c  */
#line 3290 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 587:

/* Line 1464 of yacc.c  */
#line 3293 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 588:

/* Line 1464 of yacc.c  */
#line 3296 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 589:

/* Line 1464 of yacc.c  */
#line 3299 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 590:

/* Line 1464 of yacc.c  */
#line 3302 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 591:

/* Line 1464 of yacc.c  */
#line 3305 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 592:

/* Line 1464 of yacc.c  */
#line 3308 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 593:

/* Line 1464 of yacc.c  */
#line 3311 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 594:

/* Line 1464 of yacc.c  */
#line 3314 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 595:

/* Line 1464 of yacc.c  */
#line 3317 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 596:

/* Line 1464 of yacc.c  */
#line 3320 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 597:

/* Line 1464 of yacc.c  */
#line 3323 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 598:

/* Line 1464 of yacc.c  */
#line 3326 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 599:

/* Line 1464 of yacc.c  */
#line 3329 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 600:

/* Line 1464 of yacc.c  */
#line 3332 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 601:

/* Line 1464 of yacc.c  */
#line 3337 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:

/* Line 1464 of yacc.c  */
#line 3342 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:

/* Line 1464 of yacc.c  */
#line 3347 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:

/* Line 1464 of yacc.c  */
#line 3352 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:

/* Line 1464 of yacc.c  */
#line 3361 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 606:

/* Line 1464 of yacc.c  */
#line 3368 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 616:

/* Line 1464 of yacc.c  */
#line 3394 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 617:

/* Line 1464 of yacc.c  */
#line 3400 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:

/* Line 1464 of yacc.c  */
#line 3406 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 622:

/* Line 1464 of yacc.c  */
#line 3412 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 623:

/* Line 1464 of yacc.c  */
#line 3416 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 624:

/* Line 1464 of yacc.c  */
#line 3422 "ircd_parser.y"
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

  case 625:

/* Line 1464 of yacc.c  */
#line 3456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 626:

/* Line 1464 of yacc.c  */
#line 3465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 627:

/* Line 1464 of yacc.c  */
#line 3469 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
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

  case 630:

/* Line 1464 of yacc.c  */
#line 3516 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 631:

/* Line 1464 of yacc.c  */
#line 3520 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 654:

/* Line 1464 of yacc.c  */
#line 3544 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 655:

/* Line 1464 of yacc.c  */
#line 3549 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 656:

/* Line 1464 of yacc.c  */
#line 3554 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 657:

/* Line 1464 of yacc.c  */
#line 3559 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 658:

/* Line 1464 of yacc.c  */
#line 3564 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 659:

/* Line 1464 of yacc.c  */
#line 3569 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 660:

/* Line 1464 of yacc.c  */
#line 3574 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 661:

/* Line 1464 of yacc.c  */
#line 3579 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 662:

/* Line 1464 of yacc.c  */
#line 3584 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 663:

/* Line 1464 of yacc.c  */
#line 3589 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 664:

/* Line 1464 of yacc.c  */
#line 3594 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 665:

/* Line 1464 of yacc.c  */
#line 3599 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 666:

/* Line 1464 of yacc.c  */
#line 3604 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 667:

/* Line 1464 of yacc.c  */
#line 3609 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 668:

/* Line 1464 of yacc.c  */
#line 3614 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 669:

/* Line 1464 of yacc.c  */
#line 3619 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 670:

/* Line 1464 of yacc.c  */
#line 3624 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 671:

/* Line 1464 of yacc.c  */
#line 3629 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 683:

/* Line 1464 of yacc.c  */
#line 3648 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 684:

/* Line 1464 of yacc.c  */
#line 3654 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 685:

/* Line 1464 of yacc.c  */
#line 3660 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 686:

/* Line 1464 of yacc.c  */
#line 3669 "ircd_parser.y"
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

  case 687:

/* Line 1464 of yacc.c  */
#line 3683 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 688:

/* Line 1464 of yacc.c  */
#line 3689 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 689:

/* Line 1464 of yacc.c  */
#line 3695 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1464 of yacc.c  */
#line 8085 "ircd_parser.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



