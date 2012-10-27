/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
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



/* Line 268 of yacc.c  */
#line 178 "ircd_parser.c"

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
     IRCD_FLAGS = 308,
     FLATTEN_LINKS = 309,
     FFAILED_OPERLOG = 310,
     FKILLLOG = 311,
     FKLINELOG = 312,
     FGLINELOG = 313,
     FIOERRLOG = 314,
     FOPERLOG = 315,
     FOPERSPYLOG = 316,
     FUSERLOG = 317,
     GECOS = 318,
     GENERAL = 319,
     GLINE = 320,
     GLINES = 321,
     GLINE_EXEMPT = 322,
     GLINE_LOG = 323,
     GLINE_TIME = 324,
     GLINE_MIN_CIDR = 325,
     GLINE_MIN_CIDR6 = 326,
     GLOBAL_KILL = 327,
     IRCD_AUTH = 328,
     NEED_IDENT = 329,
     HAVENT_READ_CONF = 330,
     HIDDEN = 331,
     HIDDEN_ADMIN = 332,
     HIDDEN_NAME = 333,
     HIDDEN_OPER = 334,
     HIDE_SERVER_IPS = 335,
     HIDE_SERVERS = 336,
     HIDE_SPOOF_IPS = 337,
     HOST = 338,
     HUB = 339,
     HUB_MASK = 340,
     IDLETIME = 341,
     IGNORE_BOGUS_TS = 342,
     INVISIBLE_ON_CONNECT = 343,
     IP = 344,
     KILL = 345,
     KILL_CHASE_TIME_LIMIT = 346,
     KLINE = 347,
     KLINE_EXEMPT = 348,
     KLINE_REASON = 349,
     KLINE_WITH_REASON = 350,
     KNOCK_DELAY = 351,
     KNOCK_DELAY_CHANNEL = 352,
     LEAF_MASK = 353,
     LINKS_DELAY = 354,
     LISTEN = 355,
     T_LOG = 356,
     LOGGING = 357,
     LOG_LEVEL = 358,
     MAX_ACCEPT = 359,
     MAX_BANS = 360,
     MAX_CHANS_PER_USER = 361,
     MAX_GLOBAL = 362,
     MAX_IDENT = 363,
     MAX_LOCAL = 364,
     MAX_NICK_CHANGES = 365,
     MAX_NICK_TIME = 366,
     MAX_NUMBER = 367,
     MAX_TARGETS = 368,
     MAX_WATCH = 369,
     MESSAGE_LOCALE = 370,
     MIN_NONWILDCARD = 371,
     MIN_NONWILDCARD_SIMPLE = 372,
     MODULE = 373,
     MODULES = 374,
     NAME = 375,
     NEED_PASSWORD = 376,
     T_NEED_TLS = 377,
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
#define IRCD_FLAGS 308
#define FLATTEN_LINKS 309
#define FFAILED_OPERLOG 310
#define FKILLLOG 311
#define FKLINELOG 312
#define FGLINELOG 313
#define FIOERRLOG 314
#define FOPERLOG 315
#define FOPERSPYLOG 316
#define FUSERLOG 317
#define GECOS 318
#define GENERAL 319
#define GLINE 320
#define GLINES 321
#define GLINE_EXEMPT 322
#define GLINE_LOG 323
#define GLINE_TIME 324
#define GLINE_MIN_CIDR 325
#define GLINE_MIN_CIDR6 326
#define GLOBAL_KILL 327
#define IRCD_AUTH 328
#define NEED_IDENT 329
#define HAVENT_READ_CONF 330
#define HIDDEN 331
#define HIDDEN_ADMIN 332
#define HIDDEN_NAME 333
#define HIDDEN_OPER 334
#define HIDE_SERVER_IPS 335
#define HIDE_SERVERS 336
#define HIDE_SPOOF_IPS 337
#define HOST 338
#define HUB 339
#define HUB_MASK 340
#define IDLETIME 341
#define IGNORE_BOGUS_TS 342
#define INVISIBLE_ON_CONNECT 343
#define IP 344
#define KILL 345
#define KILL_CHASE_TIME_LIMIT 346
#define KLINE 347
#define KLINE_EXEMPT 348
#define KLINE_REASON 349
#define KLINE_WITH_REASON 350
#define KNOCK_DELAY 351
#define KNOCK_DELAY_CHANNEL 352
#define LEAF_MASK 353
#define LINKS_DELAY 354
#define LISTEN 355
#define T_LOG 356
#define LOGGING 357
#define LOG_LEVEL 358
#define MAX_ACCEPT 359
#define MAX_BANS 360
#define MAX_CHANS_PER_USER 361
#define MAX_GLOBAL 362
#define MAX_IDENT 363
#define MAX_LOCAL 364
#define MAX_NICK_CHANGES 365
#define MAX_NICK_TIME 366
#define MAX_NUMBER 367
#define MAX_TARGETS 368
#define MAX_WATCH 369
#define MESSAGE_LOCALE 370
#define MIN_NONWILDCARD 371
#define MIN_NONWILDCARD_SIMPLE 372
#define MODULE 373
#define MODULES 374
#define NAME 375
#define NEED_PASSWORD 376
#define T_NEED_TLS 377
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

/* Line 293 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 741 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 753 "ircd_parser.c"

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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  266
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  318
/* YYNRULES -- Number of rules.  */
#define YYNRULES  688
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1355

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
     836,   838,   840,   842,   844,   846,   848,   850,   852,   857,
     862,   867,   868,   875,   878,   880,   882,   884,   886,   889,
     894,   899,   904,   905,   912,   915,   917,   919,   921,   923,
     926,   931,   936,   937,   943,   947,   949,   951,   953,   955,
     957,   959,   961,   963,   965,   967,   969,   971,   972,   979,
     982,   984,   986,   988,   991,   996,   997,  1003,  1007,  1009,
    1011,  1013,  1015,  1017,  1019,  1021,  1023,  1025,  1027,  1029,
    1031,  1032,  1040,  1041,  1043,  1046,  1048,  1050,  1052,  1054,
    1056,  1058,  1060,  1062,  1064,  1066,  1068,  1070,  1072,  1074,
    1076,  1079,  1084,  1086,  1091,  1096,  1101,  1106,  1111,  1116,
    1121,  1122,  1128,  1132,  1134,  1135,  1139,  1140,  1143,  1145,
    1147,  1149,  1151,  1153,  1158,  1163,  1168,  1173,  1178,  1183,
    1184,  1191,  1192,  1198,  1202,  1204,  1206,  1209,  1211,  1213,
    1215,  1217,  1219,  1224,  1229,  1230,  1237,  1240,  1242,  1244,
    1246,  1248,  1253,  1258,  1264,  1267,  1269,  1271,  1273,  1278,
    1279,  1286,  1287,  1293,  1297,  1299,  1301,  1304,  1306,  1308,
    1310,  1312,  1314,  1319,  1324,  1330,  1333,  1335,  1337,  1339,
    1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,
    1361,  1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,
    1381,  1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,  1419,
    1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,
    1441,  1443,  1445,  1447,  1452,  1457,  1462,  1467,  1472,  1477,
    1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,  1527,
    1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,  1577,
    1582,  1587,  1592,  1597,  1602,  1607,  1612,  1617,  1622,  1627,
    1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1677,
    1682,  1687,  1692,  1697,  1702,  1703,  1709,  1713,  1715,  1717,
    1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,
    1739,  1741,  1743,  1745,  1747,  1749,  1751,  1753,  1754,  1760,
    1764,  1766,  1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,
    1804,  1809,  1814,  1819,  1824,  1825,  1832,  1835,  1837,  1839,
    1841,  1843,  1845,  1847,  1849,  1851,  1856,  1861,  1862,  1868,
    1872,  1874,  1876,  1878,  1883,  1888,  1889,  1895,  1899,  1901,
    1903,  1905,  1911,  1914,  1916,  1918,  1920,  1922,  1924,  1926,
    1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,  1944,  1946,
    1948,  1950,  1952,  1954,  1959,  1964,  1969,  1974,  1979,  1984,
    1989,  1994,  1999,  2004,  2009,  2014,  2019,  2024,  2029,  2034,
    2039,  2044,  2050,  2053,  2055,  2057,  2059,  2061,  2063,  2065,
    2067,  2069,  2071,  2076,  2081,  2086,  2091,  2096,  2101
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     267,     0,    -1,    -1,   267,   268,    -1,   296,    -1,   302,
      -1,   317,    -1,   553,    -1,   340,    -1,   359,    -1,   373,
      -1,   278,    -1,   574,    -1,   391,    -1,   398,    -1,   408,
      -1,   417,    -1,   443,    -1,   453,    -1,   459,    -1,   473,
      -1,   537,    -1,   463,    -1,   273,    -1,     1,   261,    -1,
       1,   262,    -1,    -1,   270,    -1,   132,   269,    -1,   132,
     174,   269,    -1,   132,   175,   269,    -1,   132,   176,   269,
      -1,   132,   177,   269,    -1,   132,   178,   269,    -1,    -1,
     272,    -1,   132,   271,    -1,   132,    14,   271,    -1,   132,
      15,   271,    -1,   132,    16,   271,    -1,   119,   263,   274,
     262,   261,    -1,   274,   275,    -1,   275,    -1,   276,    -1,
     277,    -1,     1,   261,    -1,   118,   264,   154,   261,    -1,
     149,   264,   154,   261,    -1,   182,   263,   279,   262,   261,
      -1,   279,   280,    -1,   280,    -1,   287,    -1,   292,    -1,
     295,    -1,   289,    -1,   290,    -1,   291,    -1,   294,    -1,
     286,    -1,   293,    -1,   288,    -1,   285,    -1,   281,    -1,
       1,   261,    -1,    -1,   169,   282,   264,   283,   261,    -1,
     283,   265,   284,    -1,   284,    -1,   170,    -1,   171,    -1,
     168,   264,   154,   261,    -1,   166,   264,   154,   261,    -1,
     120,   264,   154,   261,    -1,   184,   264,   154,   261,    -1,
      37,   264,   154,   261,    -1,   124,   264,   154,   261,    -1,
     123,   264,   154,   261,    -1,   256,   264,   154,   261,    -1,
     257,   264,   154,   261,    -1,   228,   264,   132,   261,    -1,
      84,   264,   198,   261,    -1,     5,   263,   297,   262,   261,
      -1,   297,   298,    -1,   298,    -1,   299,    -1,   301,    -1,
     300,    -1,     1,   261,    -1,   120,   264,   154,   261,    -1,
      47,   264,   154,   261,    -1,    37,   264,   154,   261,    -1,
     102,   263,   303,   262,   261,    -1,   303,   304,    -1,   304,
      -1,   305,    -1,   306,    -1,   315,    -1,   316,    -1,   307,
      -1,   309,    -1,   311,    -1,   312,    -1,   314,    -1,   310,
      -1,   313,    -1,   308,    -1,     1,   261,    -1,   220,   264,
     154,   261,    -1,   139,   264,   154,   261,    -1,    62,   264,
     154,   261,    -1,    55,   264,   154,   261,    -1,    60,   264,
     154,   261,    -1,    61,   264,   154,   261,    -1,    58,   264,
     154,   261,    -1,    57,   264,   154,   261,    -1,    59,   264,
     154,   261,    -1,    56,   264,   154,   261,    -1,   103,   264,
     221,   261,    -1,   103,   264,   223,   261,    -1,   103,   264,
     227,   261,    -1,   103,   264,   225,   261,    -1,   103,   264,
     226,   261,    -1,   103,   264,   224,   261,    -1,   103,   264,
     222,   261,    -1,   254,   264,   198,   261,    -1,    -1,   137,
     318,   319,   263,   320,   262,   261,    -1,    -1,   323,    -1,
     320,   321,    -1,   321,    -1,   322,    -1,   324,    -1,   325,
      -1,   329,    -1,   328,    -1,   326,    -1,   327,    -1,   333,
      -1,     1,   261,    -1,   120,   264,   154,   261,    -1,   154,
      -1,   249,   264,   154,   261,    -1,   148,   264,   154,   261,
      -1,    49,   264,   198,   261,    -1,   167,   264,   154,   261,
      -1,    26,   264,   154,   261,    -1,    -1,   237,   330,   264,
     331,   261,    -1,   331,   265,   332,    -1,   332,    -1,   205,
      -1,   208,    -1,   209,    -1,   211,    -1,   212,    -1,   215,
      -1,   234,    -1,   229,    -1,   231,    -1,   238,    -1,   235,
      -1,   214,    -1,   230,    -1,   233,    -1,   216,    -1,   241,
      -1,   206,    -1,   207,    -1,   219,    -1,    -1,    53,   334,
     264,   335,   261,    -1,   335,   265,   336,    -1,   336,    -1,
      -1,   131,   337,   339,    -1,    -1,   338,   339,    -1,    72,
      -1,   162,    -1,    92,    -1,   248,    -1,   258,    -1,    65,
      -1,    38,    -1,   160,    -1,     5,    -1,    77,    -1,   126,
      -1,   230,    -1,   142,    -1,    79,    -1,   163,    -1,    49,
      -1,    -1,    26,   341,   342,   263,   343,   262,   261,    -1,
      -1,   346,    -1,   343,   344,    -1,   344,    -1,   345,    -1,
     356,    -1,   357,    -1,   347,    -1,   348,    -1,   358,    -1,
     349,    -1,   350,    -1,   351,    -1,   352,    -1,   353,    -1,
     354,    -1,   355,    -1,     1,   261,    -1,   120,   264,   154,
     261,    -1,   154,    -1,   151,   264,   270,   261,    -1,   152,
     264,   270,   261,    -1,   135,   264,   132,   261,    -1,    30,
     264,   270,   261,    -1,   112,   264,   132,   261,    -1,   107,
     264,   132,   261,    -1,   109,   264,   132,   261,    -1,   108,
     264,   132,   261,    -1,   179,   264,   272,   261,    -1,    23,
     264,   132,   261,    -1,    24,   264,   132,   261,    -1,   134,
     264,   132,   261,    -1,    -1,   100,   360,   263,   365,   262,
     261,    -1,    -1,    53,   362,   264,   363,   261,    -1,   363,
     265,   364,    -1,   364,    -1,   236,    -1,    76,    -1,   232,
      -1,   365,   366,    -1,   366,    -1,   367,    -1,   361,    -1,
     371,    -1,   372,    -1,     1,   261,    -1,    -1,   153,   264,
     369,   368,   261,    -1,   369,   265,   370,    -1,   370,    -1,
     132,    -1,   132,   203,   132,    -1,    89,   264,   154,   261,
      -1,    83,   264,   154,   261,    -1,    -1,    73,   374,   263,
     375,   262,   261,    -1,   375,   376,    -1,   376,    -1,   377,
      -1,   378,    -1,   379,    -1,   381,    -1,   388,    -1,   389,
      -1,   390,    -1,   380,    -1,     1,   261,    -1,   249,   264,
     154,   261,    -1,   148,   264,   154,   261,    -1,    26,   264,
     154,   261,    -1,    49,   264,   198,   261,    -1,    -1,    53,
     382,   264,   383,   261,    -1,   383,   265,   384,    -1,   384,
      -1,    -1,   131,   385,   387,    -1,    -1,   386,   387,    -1,
     192,    -1,    50,    -1,    93,    -1,    74,    -1,    20,    -1,
      21,    -1,   130,    -1,    67,    -1,   173,    -1,   121,    -1,
     122,    -1,   191,   264,   154,   261,    -1,   158,   264,   154,
     261,    -1,   157,   264,   132,   261,    -1,    -1,   172,   392,
     263,   393,   262,   261,    -1,   393,   394,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,     1,   261,    -1,   156,
     264,   154,   261,    -1,    22,   264,   154,   261,    -1,   125,
     264,   154,   261,    -1,    -1,   186,   399,   263,   400,   262,
     261,    -1,   400,   401,    -1,   401,    -1,   402,    -1,   403,
      -1,   404,    -1,     1,   261,    -1,   120,   264,   154,   261,
      -1,   249,   264,   154,   261,    -1,    -1,   188,   405,   264,
     406,   261,    -1,   406,   265,   407,    -1,   407,    -1,    92,
      -1,   245,    -1,   248,    -1,   258,    -1,   246,    -1,   240,
      -1,   172,    -1,   247,    -1,   239,    -1,   219,    -1,   204,
      -1,    -1,   187,   409,   263,   410,   262,   261,    -1,   410,
     411,    -1,   411,    -1,   412,    -1,   413,    -1,     1,   261,
      -1,   120,   264,   154,   261,    -1,    -1,   188,   414,   264,
     415,   261,    -1,   415,   265,   416,    -1,   416,    -1,    92,
      -1,   245,    -1,   248,    -1,   258,    -1,   246,    -1,   240,
      -1,   172,    -1,   247,    -1,   239,    -1,   219,    -1,   204,
      -1,    -1,    29,   418,   419,   263,   420,   262,   261,    -1,
      -1,   423,    -1,   420,   421,    -1,   421,    -1,   422,    -1,
     424,    -1,   425,    -1,   426,    -1,   427,    -1,   429,    -1,
     428,    -1,   430,    -1,   439,    -1,   440,    -1,   441,    -1,
     438,    -1,   437,    -1,   442,    -1,     1,   261,    -1,   120,
     264,   154,   261,    -1,   154,    -1,    83,   264,   154,   261,
      -1,   256,   264,   154,   261,    -1,   180,   264,   154,   261,
      -1,     3,   264,   154,   261,    -1,   153,   264,   132,   261,
      -1,     6,   264,   217,   261,    -1,     6,   264,   218,   261,
      -1,    -1,    53,   431,   264,   432,   261,    -1,   432,   265,
     433,    -1,   433,    -1,    -1,   131,   434,   436,    -1,    -1,
     435,   436,    -1,    27,    -1,    31,    -1,    10,    -1,    12,
      -1,   243,    -1,   167,   264,   154,   261,    -1,    49,   264,
     198,   261,    -1,    85,   264,   154,   261,    -1,    98,   264,
     154,   261,    -1,    26,   264,   154,   261,    -1,    25,   264,
     154,   261,    -1,    -1,    90,   444,   263,   449,   262,   261,
      -1,    -1,   188,   446,   264,   447,   261,    -1,   447,   265,
     448,    -1,   448,    -1,   159,    -1,   449,   450,    -1,   450,
      -1,   451,    -1,   452,    -1,   445,    -1,     1,    -1,   249,
     264,   154,   261,    -1,   156,   264,   154,   261,    -1,    -1,
      36,   454,   263,   455,   262,   261,    -1,   455,   456,    -1,
     456,    -1,   457,    -1,   458,    -1,     1,    -1,    89,   264,
     154,   261,    -1,   156,   264,   154,   261,    -1,    51,   263,
     460,   262,   261,    -1,   460,   461,    -1,   461,    -1,   462,
      -1,     1,    -1,    89,   264,   154,   261,    -1,    -1,    63,
     464,   263,   469,   262,   261,    -1,    -1,   188,   466,   264,
     467,   261,    -1,   467,   265,   468,    -1,   468,    -1,   159,
      -1,   469,   470,    -1,   470,    -1,   471,    -1,   472,    -1,
     465,    -1,     1,    -1,   120,   264,   154,   261,    -1,   156,
     264,   154,   261,    -1,    64,   263,   474,   262,   261,    -1,
     474,   475,    -1,   475,    -1,   484,    -1,   485,    -1,   487,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    -1,   492,
      -1,   493,    -1,   494,    -1,   483,    -1,   496,    -1,   497,
      -1,   498,    -1,   499,    -1,   515,    -1,   501,    -1,   503,
      -1,   505,    -1,   504,    -1,   508,    -1,   502,    -1,   509,
      -1,   510,    -1,   511,    -1,   512,    -1,   514,    -1,   513,
      -1,   529,    -1,   516,    -1,   520,    -1,   521,    -1,   525,
      -1,   506,    -1,   507,    -1,   535,    -1,   533,    -1,   534,
      -1,   517,    -1,   486,    -1,   518,    -1,   519,    -1,   536,
      -1,   524,    -1,   495,    -1,   522,    -1,   523,    -1,   479,
      -1,   482,    -1,   477,    -1,   478,    -1,   480,    -1,   481,
      -1,   500,    -1,   476,    -1,     1,    -1,   114,   264,   132,
     261,    -1,    70,   264,   132,   261,    -1,    71,   264,   132,
     261,    -1,    12,   264,   198,   261,    -1,   255,   264,   198,
     261,    -1,   161,   264,   270,   261,    -1,   185,   264,   198,
     261,    -1,    91,   264,   270,   261,    -1,    82,   264,   198,
     261,    -1,    87,   264,   198,   261,    -1,    43,   264,   198,
     261,    -1,    52,   264,   198,   261,    -1,     8,   264,   198,
     261,    -1,   111,   264,   270,   261,    -1,   110,   264,   132,
     261,    -1,   104,   264,   132,   261,    -1,     9,   264,   270,
     261,    -1,   202,   264,   270,   261,    -1,   201,   264,   270,
     261,    -1,    75,   264,   132,   261,    -1,    95,   264,   198,
     261,    -1,    94,   264,   154,   261,    -1,    88,   264,   198,
     261,    -1,   260,   264,   198,   261,    -1,   193,   264,   198,
     261,    -1,   196,   264,   198,   261,    -1,   197,   264,   198,
     261,    -1,   195,   264,   198,   261,    -1,   195,   264,   199,
     261,    -1,   194,   264,   198,   261,    -1,   194,   264,   199,
     261,    -1,   146,   264,   270,   261,    -1,    19,   264,   270,
     261,    -1,   138,   264,   198,   261,    -1,   147,   264,   270,
     261,    -1,   189,   264,   198,   261,    -1,   129,   264,   198,
     261,    -1,   244,   264,   198,   261,    -1,   141,   264,   198,
     261,    -1,   115,   264,   154,   261,    -1,    86,   264,   270,
     261,    -1,    44,   264,   132,   261,    -1,   113,   264,   132,
     261,    -1,   183,   264,   154,   261,    -1,    32,   264,   154,
     261,    -1,    28,   264,   132,   261,    -1,   250,   264,   198,
     261,    -1,    46,   264,   154,   261,    -1,   150,   264,   198,
     261,    -1,    39,   264,   198,   261,    -1,   242,   264,   270,
     261,    -1,    -1,   143,   526,   264,   527,   261,    -1,   527,
     265,   528,    -1,   528,    -1,   205,    -1,   208,    -1,   209,
      -1,   211,    -1,   212,    -1,   215,    -1,   234,    -1,   229,
      -1,   231,    -1,   238,    -1,   235,    -1,   214,    -1,   230,
      -1,   233,    -1,   216,    -1,   241,    -1,   206,    -1,   207,
      -1,   219,    -1,    -1,   140,   530,   264,   531,   261,    -1,
     531,   265,   532,    -1,   532,    -1,   205,    -1,   208,    -1,
     209,    -1,   211,    -1,   212,    -1,   215,    -1,   234,    -1,
     229,    -1,   231,    -1,   238,    -1,   235,    -1,   214,    -1,
     230,    -1,   233,    -1,   216,    -1,   241,    -1,   206,    -1,
     207,    -1,   219,    -1,   116,   264,   132,   261,    -1,   117,
     264,   132,   261,    -1,    33,   264,   132,   261,    -1,   210,
     264,   272,   261,    -1,    -1,    66,   538,   263,   539,   262,
     261,    -1,   539,   540,    -1,   540,    -1,   541,    -1,   542,
      -1,   543,    -1,   547,    -1,   548,    -1,   549,    -1,     1,
      -1,    48,   264,   198,   261,    -1,    45,   264,   270,   261,
      -1,    -1,   102,   544,   264,   545,   261,    -1,   545,   265,
     546,    -1,   546,    -1,   200,    -1,    11,    -1,   249,   264,
     154,   261,    -1,   120,   264,   154,   261,    -1,    -1,     4,
     550,   264,   551,   261,    -1,   551,   265,   552,    -1,   552,
      -1,   200,    -1,    11,    -1,    22,   263,   554,   262,   261,
      -1,   554,   555,    -1,   555,    -1,   558,    -1,   559,    -1,
     560,    -1,   561,    -1,   566,    -1,   562,    -1,   563,    -1,
     564,    -1,   565,    -1,   567,    -1,   568,    -1,   569,    -1,
     557,    -1,   570,    -1,   571,    -1,   572,    -1,   573,    -1,
     556,    -1,     1,    -1,    40,   264,   198,   261,    -1,   164,
     264,   198,   261,    -1,    42,   264,   198,   261,    -1,   251,
     264,   198,   261,    -1,   252,   264,   198,   261,    -1,   253,
     264,   198,   261,    -1,    96,   264,   270,   261,    -1,    97,
     264,   270,   261,    -1,   106,   264,   132,   261,    -1,   155,
     264,   198,   261,    -1,   105,   264,   132,   261,    -1,    35,
     264,   132,   261,    -1,    34,   264,   132,   261,    -1,   127,
     264,   198,   261,    -1,   128,   264,   198,   261,    -1,    13,
     264,   198,   261,    -1,   144,   264,   132,   261,    -1,   145,
     264,   270,   261,    -1,   181,   263,   575,   262,   261,    -1,
     575,   576,    -1,   576,    -1,   577,    -1,   578,    -1,   580,
      -1,   582,    -1,   581,    -1,   579,    -1,   583,    -1,     1,
      -1,    54,   264,   198,   261,    -1,    81,   264,   198,   261,
      -1,    78,   264,   154,   261,    -1,    99,   264,   270,   261,
      -1,    76,   264,   198,   261,    -1,    41,   264,   198,   261,
      -1,    80,   264,   198,   261,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   395,   395,   396,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   424,   424,   425,   429,
     433,   437,   441,   445,   451,   451,   452,   453,   454,   455,
     462,   465,   465,   466,   466,   466,   468,   474,   481,   483,
     483,   484,   484,   485,   485,   486,   486,   487,   488,   488,
     489,   489,   490,   491,   495,   494,   513,   513,   514,   520,
     528,   562,   622,   637,   652,   661,   675,   684,   712,   742,
     765,   774,   776,   776,   777,   777,   778,   778,   780,   789,
     798,   811,   813,   814,   816,   816,   817,   818,   818,   819,
     819,   820,   820,   821,   821,   822,   823,   825,   829,   833,
     840,   847,   854,   861,   868,   875,   882,   889,   893,   897,
     901,   905,   909,   913,   919,   929,   928,  1025,  1025,  1026,
    1026,  1027,  1027,  1027,  1028,  1028,  1028,  1029,  1029,  1029,
    1031,  1043,  1055,  1092,  1104,  1115,  1157,  1167,  1166,  1172,
    1172,  1173,  1177,  1181,  1185,  1189,  1193,  1197,  1201,  1205,
    1209,  1213,  1217,  1221,  1225,  1229,  1233,  1237,  1241,  1245,
    1252,  1251,  1255,  1255,  1256,  1256,  1257,  1257,  1259,  1266,
    1273,  1280,  1287,  1294,  1301,  1308,  1315,  1322,  1329,  1336,
    1343,  1350,  1357,  1364,  1378,  1377,  1427,  1427,  1429,  1429,
    1430,  1431,  1431,  1432,  1433,  1434,  1435,  1436,  1437,  1438,
    1439,  1440,  1441,  1442,  1444,  1453,  1462,  1468,  1474,  1480,
    1486,  1492,  1498,  1504,  1510,  1516,  1522,  1528,  1538,  1537,
    1554,  1553,  1558,  1558,  1559,  1563,  1567,  1575,  1575,  1576,
    1576,  1576,  1576,  1576,  1578,  1578,  1580,  1580,  1582,  1596,
    1616,  1625,  1638,  1637,  1706,  1706,  1707,  1707,  1707,  1707,
    1708,  1708,  1708,  1709,  1709,  1711,  1748,  1761,  1770,  1782,
    1781,  1785,  1785,  1786,  1786,  1787,  1787,  1789,  1796,  1803,
    1810,  1817,  1824,  1831,  1838,  1845,  1852,  1859,  1869,  1888,
    1898,  1912,  1911,  1927,  1927,  1928,  1928,  1928,  1928,  1930,
    1939,  1954,  1968,  1967,  1983,  1983,  1984,  1984,  1984,  1984,
    1986,  1995,  2018,  2017,  2023,  2023,  2024,  2028,  2032,  2036,
    2040,  2044,  2048,  2052,  2056,  2060,  2064,  2074,  2073,  2090,
    2090,  2091,  2091,  2091,  2093,  2100,  2099,  2105,  2105,  2106,
    2110,  2114,  2118,  2122,  2126,  2130,  2134,  2138,  2142,  2146,
    2156,  2155,  2301,  2301,  2302,  2302,  2303,  2303,  2303,  2304,
    2304,  2305,  2305,  2306,  2306,  2306,  2307,  2307,  2308,  2308,
    2309,  2311,  2323,  2335,  2344,  2370,  2388,  2406,  2412,  2416,
    2425,  2424,  2428,  2428,  2429,  2429,  2430,  2430,  2432,  2443,
    2450,  2457,  2464,  2474,  2515,  2526,  2539,  2552,  2561,  2597,
    2596,  2660,  2659,  2663,  2663,  2664,  2670,  2670,  2671,  2671,
    2671,  2671,  2673,  2692,  2702,  2701,  2724,  2724,  2725,  2725,
    2725,  2727,  2733,  2742,  2744,  2744,  2745,  2745,  2747,  2766,
    2765,  2813,  2812,  2816,  2816,  2817,  2823,  2823,  2824,  2824,
    2824,  2824,  2826,  2832,  2841,  2844,  2844,  2845,  2845,  2846,
    2846,  2847,  2847,  2848,  2848,  2849,  2849,  2850,  2850,  2851,
    2851,  2852,  2852,  2853,  2853,  2854,  2854,  2855,  2855,  2856,
    2856,  2857,  2857,  2858,  2858,  2859,  2859,  2860,  2860,  2861,
    2861,  2862,  2862,  2863,  2863,  2864,  2864,  2865,  2866,  2866,
    2867,  2867,  2868,  2869,  2869,  2870,  2870,  2871,  2871,  2872,
    2872,  2873,  2874,  2877,  2882,  2887,  2892,  2897,  2902,  2907,
    2912,  2917,  2922,  2927,  2932,  2937,  2942,  2947,  2952,  2957,
    2962,  2967,  2973,  2984,  2989,  2998,  3003,  3008,  3013,  3018,
    3023,  3026,  3031,  3034,  3039,  3044,  3049,  3054,  3059,  3064,
    3069,  3074,  3079,  3090,  3095,  3100,  3105,  3114,  3146,  3164,
    3169,  3178,  3183,  3188,  3194,  3193,  3198,  3198,  3199,  3202,
    3205,  3208,  3211,  3214,  3217,  3220,  3223,  3226,  3229,  3232,
    3235,  3238,  3241,  3244,  3247,  3250,  3253,  3259,  3258,  3263,
    3263,  3264,  3267,  3270,  3273,  3276,  3279,  3282,  3285,  3288,
    3291,  3294,  3297,  3300,  3303,  3306,  3309,  3312,  3315,  3318,
    3323,  3328,  3333,  3338,  3348,  3347,  3371,  3371,  3372,  3373,
    3374,  3375,  3376,  3377,  3378,  3380,  3386,  3393,  3392,  3397,
    3397,  3398,  3402,  3408,  3442,  3452,  3451,  3501,  3501,  3502,
    3506,  3515,  3518,  3518,  3519,  3519,  3520,  3520,  3521,  3521,
    3522,  3522,  3523,  3523,  3524,  3525,  3525,  3526,  3526,  3527,
    3527,  3528,  3528,  3530,  3535,  3540,  3545,  3550,  3555,  3560,
    3565,  3570,  3575,  3580,  3585,  3590,  3595,  3600,  3605,  3610,
    3615,  3623,  3626,  3626,  3627,  3627,  3628,  3629,  3630,  3630,
    3631,  3632,  3634,  3640,  3646,  3655,  3669,  3675,  3681
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
  "ENCRYPTED", "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE",
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
  "T_NEED_TLS", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
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
  "connect_port", "connect_aftype", "connect_flags", "$@21",
  "connect_flags_items", "connect_flags_item", "$@22", "$@23",
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
     387,   387,   387,   387,   387,   387,   387,   387,   388,   389,
     390,   392,   391,   393,   393,   394,   394,   394,   394,   395,
     396,   397,   399,   398,   400,   400,   401,   401,   401,   401,
     402,   403,   405,   404,   406,   406,   407,   407,   407,   407,
     407,   407,   407,   407,   407,   407,   407,   409,   408,   410,
     410,   411,   411,   411,   412,   414,   413,   415,   415,   416,
     416,   416,   416,   416,   416,   416,   416,   416,   416,   416,
     418,   417,   419,   419,   420,   420,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   422,   423,   424,   425,   426,   427,   428,   429,   429,
     431,   430,   432,   432,   434,   433,   435,   433,   436,   436,
     436,   436,   436,   437,   438,   439,   440,   441,   442,   444,
     443,   446,   445,   447,   447,   448,   449,   449,   450,   450,
     450,   450,   451,   452,   454,   453,   455,   455,   456,   456,
     456,   457,   458,   459,   460,   460,   461,   461,   462,   464,
     463,   466,   465,   467,   467,   468,   469,   469,   470,   470,
     470,   470,   471,   472,   473,   474,   474,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   475,   475,   475,   475,   475,   475,   475,
     475,   475,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   503,   504,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   526,   525,   527,   527,   528,   528,
     528,   528,   528,   528,   528,   528,   528,   528,   528,   528,
     528,   528,   528,   528,   528,   528,   528,   530,   529,   531,
     531,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     532,   532,   532,   532,   532,   532,   532,   532,   532,   532,
     533,   534,   535,   536,   538,   537,   539,   539,   540,   540,
     540,   540,   540,   540,   540,   541,   542,   544,   543,   545,
     545,   546,   546,   547,   548,   550,   549,   551,   551,   552,
     552,   553,   554,   554,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   555,   555,   555,   555,   555,   555,   555,
     555,   555,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   575,   576,   576,   576,   576,   576,   576,
     576,   576,   577,   578,   579,   580,   581,   582,   583
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     2,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     7,     0,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     4,     4,     4,     4,     4,
       0,     5,     3,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     0,
       6,     0,     5,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     0,     5,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   194,   350,   414,     0,
     429,     0,   604,   252,   399,   228,     0,     0,   125,   291,
       0,     0,   302,   327,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   196,
     352,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    86,    85,   652,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   633,   651,   646,   634,
     635,   636,   637,   639,   640,   641,   642,   638,   643,   644,
     645,   647,   648,   649,   650,   215,     0,   197,   372,     0,
     353,     0,   427,     0,     0,   425,   426,     0,   502,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   577,     0,   554,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   446,   501,   496,   497,   494,
     498,   499,   495,   457,   447,   448,   486,   449,   450,   451,
     452,   453,   454,   455,   456,   491,   458,   459,   460,   461,
     500,   463,   468,   464,   466,   465,   480,   481,   467,   469,
     470,   471,   472,   474,   473,   462,   476,   485,   487,   488,
     477,   478,   492,   493,   490,   479,   475,   483,   484,   482,
     489,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    98,   105,    99,   103,   100,   101,   104,   102,
      96,    97,     0,     0,     0,     0,    42,    43,    44,   141,
       0,   128,     0,   681,     0,     0,     0,     0,     0,     0,
       0,     0,   673,   674,   675,   679,   676,   678,   677,   680,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,    50,    62,    61,    58,    51,    60,
      54,    55,    56,    52,    59,    57,    53,     0,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   632,     0,     0,   420,     0,     0,
       0,   417,   418,   419,     0,     0,   424,   441,     0,     0,
     431,   440,     0,   437,   438,   439,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   445,   614,   625,     0,     0,   617,     0,     0,
       0,   607,   608,   609,   610,   611,   612,   613,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,   263,   259,   260,   261,   262,   411,     0,   401,
       0,   410,     0,   407,   408,   409,     0,   230,     0,     0,
       0,   240,     0,   238,   239,   241,   242,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    45,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,   294,   295,   296,   297,     0,     0,     0,
       0,     0,     0,     0,     0,   672,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   312,     0,     0,   305,   306,   307,   308,
       0,     0,   335,     0,   330,   331,   332,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     631,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   200,   203,   204,
     206,   207,   208,   209,   210,   211,   212,   201,   202,   205,
       0,     0,     0,     0,     0,     0,   380,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   355,   356,   357,   358,
     359,   360,   362,   361,   363,   368,   367,   364,   365,   366,
     369,     0,     0,     0,   416,     0,   423,     0,     0,     0,
       0,   436,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
     444,     0,     0,     0,     0,     0,     0,     0,   606,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,     0,   406,   243,     0,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    40,     0,     0,     0,   170,     0,     0,
       0,   147,     0,     0,   130,   131,   132,   133,   136,   137,
     135,   134,   138,   298,     0,     0,     0,     0,   293,     0,
       0,     0,     0,     0,     0,     0,   671,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     309,     0,     0,     0,     0,   304,   333,     0,     0,     0,
     329,    90,    89,    88,   668,   665,   664,   653,   655,    26,
      26,    26,    26,    26,    28,    27,   659,   660,   663,   661,
     666,   667,   669,   670,   662,   654,   656,   657,   658,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   370,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,     0,     0,   415,   428,     0,     0,     0,   430,
     515,   519,   506,   535,   548,   547,   602,   552,   513,   544,
     550,   514,   504,   505,   522,   511,   543,   512,   525,   510,
     524,   523,   518,   517,   516,   545,   503,   542,   600,   601,
     539,   536,   581,   597,   598,   582,   583,   584,   585,   592,
     586,   595,   599,   588,   593,   589,   594,   587,   591,   590,
     596,     0,   580,   541,   558,   574,   575,   559,   560,   561,
     562,   569,   563,   572,   576,   565,   570,   566,   571,   564,
     568,   567,   573,     0,   557,   534,   537,   551,   508,   546,
     509,   538,   527,   532,   533,   530,   531,   528,   529,   521,
     520,    34,    34,    34,    36,    35,   603,   553,   540,   549,
     507,   526,     0,     0,     0,     0,     0,     0,   605,     0,
       0,   275,     0,     0,     0,     0,     0,   253,     0,     0,
       0,   400,     0,     0,     0,   248,   244,   247,   229,   110,
     116,   114,   113,   115,   111,   112,   109,   117,   123,   118,
     122,   120,   121,   119,   108,   107,   124,    46,    47,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,   292,   687,   682,   686,   684,   688,   683,
     685,    74,    80,    72,    76,    75,    71,    70,    68,    69,
       0,    67,    73,    79,    77,    78,     0,     0,     0,   303,
       0,     0,   328,    29,    30,    31,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   195,     0,     0,     0,     0,     0,     0,   386,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   421,   422,
     442,   443,   435,     0,   434,   578,     0,   555,     0,    37,
      38,    39,   630,   629,     0,   628,   616,   615,   622,   621,
       0,   620,   624,   623,   267,   268,   273,     0,   272,     0,
     266,   290,   289,   288,   265,   413,   405,     0,   404,   412,
     235,   236,   234,     0,   233,   251,   250,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,   126,   300,
     301,   299,    65,     0,   310,   316,   322,   326,   325,   324,
     321,   317,   320,   323,   318,   319,     0,   315,   311,   334,
     339,   345,   349,   348,   347,   344,   340,   343,   346,   341,
     342,     0,   338,   225,   226,   219,   221,   223,   222,   220,
     214,   227,   218,   216,   217,   224,   376,   378,   379,   398,
     397,   394,   384,     0,   383,     0,   373,   395,   396,   371,
     377,   393,   375,   374,   432,     0,   579,   556,   626,     0,
     618,     0,     0,   270,   275,   281,   282,   278,   284,   280,
     279,   286,   287,   283,   285,   277,   276,   402,     0,   231,
       0,   249,   246,   245,   146,   144,   174,     0,   173,     0,
     140,   143,   145,   151,   167,   168,   152,   153,   154,   155,
     162,   156,   165,   169,   158,   163,   159,   164,   157,   161,
     160,   166,     0,   150,   142,    66,   313,     0,   336,     0,
       0,   381,   386,   390,   391,   388,   389,   392,   387,   433,
     627,   619,   274,   271,   403,   232,     0,   171,   176,   186,
     184,   193,   183,   178,   187,   191,   180,   188,   190,   185,
     179,   192,   189,   181,   182,   177,   148,     0,   314,   337,
     385,   382,   175,   172,   149
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   834,   835,   984,   985,    25,   275,   276,
     277,   278,    26,   313,   314,   315,   534,  1070,  1071,   316,
     317,   318,   319,   320,   321,   322,   323,   324,   325,   326,
      27,    71,    72,    73,    74,    75,    28,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,   268,   269,   270,
     271,    29,    61,   280,   773,   774,   775,   281,   776,   777,
     778,   779,   780,   781,  1046,  1302,  1303,   782,  1042,  1277,
    1278,  1326,  1279,  1345,    30,    49,   116,   595,   596,   597,
     117,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,    31,    58,   481,   736,  1163,  1164,   482,
     483,   484,  1169,  1016,  1017,   485,   486,    32,    56,   457,
     458,   459,   460,   461,   462,   463,   722,  1147,  1148,  1252,
    1149,  1266,   464,   465,   466,    33,    62,   512,   513,   514,
     515,   516,    34,    65,   545,   546,   547,   548,   549,   812,
    1196,  1197,    35,    66,   553,   554,   555,   556,   818,  1211,
    1212,    36,    50,   119,   625,   626,   627,   120,   628,   629,
     630,   631,   632,   633,   634,   871,  1233,  1234,  1310,  1235,
    1318,   635,   636,   637,   638,   639,   640,    37,    57,   471,
     731,  1157,  1158,   472,   473,   474,   475,    38,    51,   360,
     361,   362,   363,    39,   124,   125,   126,    40,    53,   371,
     649,  1123,  1124,   372,   373,   374,   375,    41,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     410,   963,   964,   236,   408,   941,   942,   237,   238,   239,
     240,    42,    55,   440,   441,   442,   443,   444,   714,  1140,
    1141,   445,   446,   447,   711,  1134,  1135,    43,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,    44,   291,
     292,   293,   294,   295,   296,   297,   298,   299
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -816
static const yytype_int16 yypact[] =
{
    -816,   656,  -816,  -186,  -239,  -231,  -816,  -816,  -816,  -229,
    -816,  -223,  -816,  -816,  -816,  -816,  -217,  -212,  -816,  -816,
    -185,  -175,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,    32,   568,   -47,
     -45,  -148,    29,  -109,   394,   -89,   -48,   -39,   -23,   564,
      14,    89,   -17,   343,   377,    -8,     4,     0,    -5,    36,
      48,    56,  -816,  -816,  -816,  -816,  -816,    52,    53,    59,
      61,    63,    69,    70,    72,    75,    79,    81,    94,    95,
      97,    98,   105,   106,   107,   130,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,    50,  -816,  -816,   110,
    -816,    19,  -816,   111,    27,  -816,  -816,     2,  -816,   112,
     113,   115,   116,   122,   123,   124,   126,   132,   134,   135,
     141,   144,   145,   147,   153,   154,   161,   166,   167,   168,
     179,   180,   181,   183,   184,   185,   187,   190,   191,   196,
     199,  -816,   203,  -816,   206,   208,   209,   213,   214,   215,
     220,   223,   228,   229,   230,   231,   232,   238,   239,   242,
     252,   253,   255,   258,    10,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,   411,   367,    65,   248,    12,   263,   264,   266,   269,
     274,   275,   278,   283,   288,   289,   290,   292,   221,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,    38,   296,   298,    43,  -816,  -816,  -816,  -816,
     128,  -816,     3,  -816,   300,   302,   303,   304,   307,   308,
     309,   188,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
      67,   310,   311,   314,   316,   318,   320,   328,  -816,   330,
     333,   335,   337,   172,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,    13,    20,  -816,
     139,   156,   240,   175,  -816,   254,   321,   419,   408,   413,
     475,   475,   477,   480,   416,   417,   485,   475,   429,   430,
     431,   433,   437,   376,  -816,   629,   465,  -816,   375,   378,
      46,  -816,  -816,  -816,   486,   380,  -816,  -816,   379,   384,
    -816,  -816,    35,  -816,  -816,  -816,   453,   475,   457,   475,
     530,   512,   536,   471,   472,   539,   518,   478,   543,   545,
     547,   482,   475,   490,   491,   475,   537,   492,   561,   562,
     475,   565,   567,   546,   569,   570,   506,   507,   442,   510,
     445,   475,   475,   513,   475,   556,   516,   517,   519,   -54,
     -11,   520,   526,   475,   475,   593,   475,   528,   529,   533,
     541,   467,  -816,  -816,  -816,   470,   479,  -816,   481,   483,
     287,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   474,   484,
     488,  -816,   489,   493,   496,   497,   501,    93,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   502,  -816,
     503,  -816,    57,  -816,  -816,  -816,   494,  -816,   504,   508,
     509,  -816,    47,  -816,  -816,  -816,  -816,  -816,   588,   590,
     596,   600,   616,   617,   620,   622,   127,   628,   631,   585,
     525,  -816,  -816,   635,   636,   531,  -816,   409,   534,   527,
     535,   538,    60,  -816,  -816,  -816,  -816,   602,   603,   609,
     640,   611,   613,   475,   551,  -816,  -816,   659,   619,   660,
     661,   668,   669,   670,   563,   672,   697,   676,   677,   571,
    -816,   572,   576,  -816,   577,    49,  -816,  -816,  -816,  -816,
     573,   580,  -816,     9,  -816,  -816,  -816,   574,   575,   586,
    -816,   587,   589,   594,   595,   610,   189,   614,   615,   618,
     621,   625,   630,   632,   633,   643,   647,   648,   650,   651,
    -816,   652,   608,   626,   637,   653,   655,   663,   664,   667,
     674,   681,   682,   684,   685,   195,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
     657,   686,   687,   688,   689,   690,  -816,   692,   696,   700,
     701,   703,   704,   706,   707,    64,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,   695,   713,   662,  -816,   680,  -816,   720,   723,   708,
     694,  -816,   712,   714,   715,   716,   717,   718,   719,   721,
     722,   724,   725,   726,   727,   729,   730,   731,   732,   733,
     734,   735,   736,   737,   738,   739,   740,   741,   742,   743,
     744,   745,   746,   747,   654,   748,   691,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,    96,   765,   766,   767,   768,   769,   770,
    -816,   710,   475,   683,   771,   776,   827,   772,  -816,  -816,
     830,   791,   773,   878,   782,   880,   882,   884,   778,  -816,
     886,   777,   888,   783,  -816,  -816,   779,   891,   892,   784,
     786,  -816,   787,   788,   789,   790,   792,   793,   794,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
    -816,   806,   807,  -816,   808,   809,   810,  -816,   811,   812,
     813,  -816,   814,   237,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,   898,   916,   917,   818,  -816,   819,
     820,   821,   822,   823,   824,   825,  -816,   826,   828,   829,
     831,   832,   833,   834,    62,   835,   836,   837,   838,  -816,
    -816,   918,   839,   934,   840,  -816,  -816,   937,   841,   843,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   475,
     475,   475,   475,   475,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
     968,   970,   475,   974,   975,   976,   977,   956,   979,   980,
     475,   475,   593,   852,  -816,  -816,   960,    30,   961,   962,
     919,   854,   965,   966,   967,   969,   990,   971,   972,   973,
     863,  -816,   867,   868,  -816,  -816,   869,   870,   698,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -249,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -248,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,   593,   593,   593,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,    -6,   871,   872,    -2,   873,   874,  -816,   875,
     876,  1007,   879,   881,   883,   885,   887,  -816,   889,   982,
     890,  -816,   -50,   893,   894,   675,   895,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
     985,   945,   897,   991,   993,   995,   899,   998,   896,  -816,
     901,   903,   904,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -230,  -816,  -816,  -816,  -816,  -816,   905,   558,   906,  -816,
     907,   606,  -816,  -816,  -816,  -816,  -816,  -816,   908,   909,
     910,   911,   912,   913,   914,   915,   920,   921,   922,   923,
     924,  -816,   925,   926,   927,   928,   929,   930,  1022,   931,
     932,   933,   935,   936,   938,   939,   940,  -816,  -816,  -816,
    -816,  -816,  -816,  -220,  -816,  -816,   654,  -816,   691,  -816,
    -816,  -816,  -816,  -816,  -202,  -816,  -816,  -816,  -816,  -816,
    -197,  -816,  -816,  -816,  -816,  -816,  -816,  -188,  -816,   666,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -174,  -816,  -816,
    -816,  -816,  -816,  -166,  -816,  -816,  -816,  1024,   784,   941,
     942,   943,  1027,   944,   946,   947,   728,   948,  -816,  -816,
    -816,  -816,  -816,    62,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -159,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -127,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -124,  -816,    -4,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,   698,  -816,  -816,  -816,    -6,
    -816,    -2,   666,  -816,  1007,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   982,  -816,
     -50,  -816,  -816,  -816,  -816,  -816,  -816,   -51,  -816,   521,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,   -31,  -816,  -816,  -816,  -816,   558,  -816,   606,
      -4,  -816,  1022,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,   521,  -816,  1027,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,   728,  -816,  -816,
    -816,  -816,  -816,  -816,  -816
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -816,  -816,  -816,  -652,  -340,  -815,  -423,  -816,  -816,   605,
    -816,  -816,  -816,  -816,   846,  -816,  -816,  -816,  -268,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  1106,  -816,  -816,  -816,  -816,  -816,   952,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,   405,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -168,  -816,  -816,  -816,
    -133,  -816,  -816,  -146,  -816,  -816,  -816,  -816,   623,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   -72,  -816,
     774,  -816,  -816,  -816,    44,  -816,  -816,  -816,  -816,  -816,
     775,  -816,  -816,  -816,  -816,  -816,  -816,  -816,   -43,  -816,
    -816,   -46,  -816,  -816,  -816,  -816,  -816,  -816,   702,  -816,
    -816,  -816,  -816,  -816,  -816,   671,  -816,  -816,  -816,  -816,
    -816,   -94,  -816,  -816,  -816,   673,  -816,  -816,  -816,  -816,
     -92,  -816,  -816,  -816,  -816,   597,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,   -97,  -816,  -816,
     -91,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,   -44,  -816,   780,  -816,  -816,  -816,  -816,  -816,
     860,  -816,  -816,  -816,  -816,  1097,  -816,  -816,  -816,  -816,
    -816,  -816,   -22,  -816,   853,  -816,  -816,  -816,  -816,  1043,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,   100,  -816,  -816,  -816,   103,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,   815,  -816,  -816,  -816,  -816,  -816,
     -21,  -816,  -816,  -816,  -816,  -816,   -18,  -816,  -816,  1138,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
    -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,  -816,
     949,  -816,  -816,  -816,  -816,  -816,  -816,  -816
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     567,   568,   704,   367,   508,  1132,  1313,   574,  1314,  1138,
     550,   128,  1125,  1127,   541,   272,  1126,  1128,   129,   130,
     357,   550,   131,  1315,    47,   509,  1160,  1316,   122,   132,
     122,  1182,    48,    67,    52,  1183,   367,   653,   133,   655,
      54,  1244,   134,   135,   272,  1245,    59,   357,   476,   136,
     541,    60,   668,   137,   138,   671,   139,    67,   467,  1248,
     676,   508,   140,  1249,  1250,   610,   467,   611,  1251,    68,
     612,   687,   688,  1253,   690,    45,    46,  1254,    63,    69,
     141,   142,   509,   701,   702,   143,   705,  1267,    64,   613,
     614,  1268,   144,    68,   448,  1269,   145,   146,   147,  1270,
     477,   148,  1306,    69,   149,   150,  1307,   115,   358,   118,
     981,   982,   983,   615,   151,   121,   123,   616,   123,   449,
     152,   153,   368,   154,   155,   156,   157,   158,   510,   551,
     478,    76,   273,   542,  1308,   358,   479,  1311,  1309,   159,
     551,  1312,   450,    77,   695,   696,   451,   617,   160,   618,
     161,   162,    70,   163,   127,   368,   164,   165,   369,   511,
     166,   273,   619,   274,    78,    79,  1129,  1130,  1131,   542,
      80,   167,    81,   300,   241,   359,    70,  1083,  1084,  1085,
    1086,  1087,  1161,   795,   620,   510,  1162,   697,   698,   283,
     370,   369,   274,   168,  1133,   169,   581,   552,  1139,   170,
     480,   543,   359,   171,   172,   173,   174,   175,   552,   301,
    1327,   176,   177,   468,  1328,   242,   511,   621,   582,   583,
     178,   468,   245,   370,   243,   584,    82,    83,   703,   284,
    1346,   622,  1068,  1069,  1347,    84,    85,   543,   764,  1317,
     244,   452,   285,   279,   623,   469,   282,  1103,  1104,   476,
     453,   454,   179,   469,   180,   327,   302,    86,    87,   330,
     181,   329,   544,   765,   286,   182,   287,   328,   288,   289,
     183,   819,   431,   487,    88,    89,   246,   247,   248,   249,
     250,   251,   252,   253,   455,    90,   766,   290,   433,   365,
     767,   434,   303,   557,    91,   304,   305,   650,   544,   502,
     331,   477,   585,   586,   587,   505,   470,   588,   643,   740,
     558,   814,   332,   355,   470,   589,   335,   336,   333,   733,
     624,   566,   787,   337,   254,   338,   880,   339,   526,   590,
     591,   478,   435,   340,   341,   436,   342,   479,   306,   343,
     307,   308,   456,   344,   283,   345,   592,   593,   750,   751,
     752,   753,   754,   755,   756,   728,   309,   768,   346,   347,
     255,   348,   349,   829,   830,   831,   832,   833,   448,   350,
     351,   352,   993,   356,   594,   364,   376,   377,   300,   378,
     379,    92,    93,    94,   284,   769,   380,   381,   382,   437,
     383,   507,   353,   449,   559,   128,   384,   285,   385,   386,
     310,   480,   129,   130,   770,   387,   131,   438,   388,   389,
     764,   390,   433,   132,   301,   434,   450,   391,   392,   286,
     451,   287,   133,   288,   289,   393,   134,   135,   311,   312,
     394,   395,   396,   136,   539,   765,   560,   137,   138,  1100,
     139,   256,   290,   397,   398,   399,   140,   400,   401,   402,
     524,   403,   561,   562,   404,   405,   435,   863,   766,   436,
     406,   302,   767,   407,   141,   142,   610,   409,   611,   143,
     411,   612,   412,   413,   771,   257,   144,   414,   415,   416,
     145,   146,   147,   500,   417,   148,   772,   418,   149,   150,
     613,   614,   419,   420,   421,   422,   423,   303,   151,  1048,
     304,   305,   424,   425,   152,   153,   426,   154,   155,   156,
     157,   158,  1090,   437,   615,   452,   427,   428,   616,   429,
    1098,  1099,   430,   159,   453,   454,  1329,   488,   489,   768,
     490,   438,   160,   491,   161,   162,   439,   163,   492,   493,
     164,   165,   494,   306,   166,   307,   308,   495,   617,   717,
     618,   563,   496,   497,   498,   167,   499,   769,   455,  1330,
     503,   309,   504,   619,   517,   245,   518,   519,   520,    76,
    1331,   521,   522,   523,   527,   528,   770,   168,   529,   169,
     530,    77,   531,   170,   532,   620,  1332,   171,   172,   173,
     174,   175,   533,  1333,   535,   176,   177,   536,  1334,   537,
    1335,   538,    78,    79,   178,   310,   564,   566,    80,   569,
      81,   565,   570,  1336,   571,   572,   456,   573,   621,   246,
     247,   248,   249,   250,   251,   252,   253,   575,   576,   577,
     581,   578,   622,   311,   312,   579,   179,   580,   180,   641,
     645,   646,   642,   647,   181,   623,   771,  1337,   648,   182,
    1185,   652,   582,   583,   183,   654,     2,     3,   772,   584,
     439,     4,   656,  1338,    82,    83,   657,   254,   658,   659,
     660,   661,   662,    84,    85,   664,   663,   665,     5,   666,
     667,  1339,     6,  1340,  1341,     7,  1255,  1256,   669,   670,
     673,   672,     8,   674,   675,    86,    87,   677,  1200,   678,
     679,   680,   681,   255,   682,   683,   684,     9,   685,   686,
     691,   689,    88,    89,   692,   693,  1257,   694,   699,    10,
      11,   624,    12,    90,   700,   703,   706,   707,   710,    13,
    1186,   708,    91,  1258,   712,   719,   585,   586,   587,   709,
    1259,   588,   742,   713,   743,   715,    14,   716,   720,   589,
     744,  1342,   721,   723,   745,   735,    15,   724,    16,  1260,
     725,   726,  1187,   590,   591,   727,   730,   732,   737,  1343,
     746,   747,   738,   739,   748,    17,   749,  1188,  1201,  1344,
     592,   593,   757,   759,   256,   758,   760,  1261,  1262,   761,
     762,   784,   763,    18,   792,   783,  1263,  1189,  1190,   785,
     789,   790,   786,  1191,  1192,  1193,  1194,   791,   594,   793,
    1202,   794,   796,   797,   799,   800,  1195,   798,   257,    92,
      93,    94,   801,   802,   803,  1203,   805,   804,    19,   806,
     807,   808,   809,   810,   816,   821,   822,    20,    21,  1264,
     811,   813,    22,    23,   817,  1204,  1205,   823,   824,   882,
     825,  1206,  1207,  1208,  1209,   826,   827,  1122,  1265,   922,
     923,   924,   925,   926,  1210,   927,   928,   883,   929,   930,
     931,   828,   850,   932,   886,   836,   837,   887,  1167,   838,
     506,   994,   839,   933,   934,   935,   840,   936,   937,   938,
     851,   841,   939,   842,   843,   940,   944,   945,   946,   947,
     948,   852,   949,   950,   844,   951,   952,   953,   845,   846,
     954,   847,   848,   849,  1003,  1305,  1015,   853,   865,   854,
     955,   956,   957,   884,   958,   959,   960,   855,   856,   961,
     996,   857,   962,  1283,  1284,  1285,  1286,  1287,   858,  1288,
    1289,   885,  1290,  1291,  1292,   859,   860,  1293,   861,   862,
     866,   867,   868,   869,   870,   889,   872,  1294,  1295,  1296,
     873,  1297,  1298,  1299,   874,   875,  1300,   876,   877,  1301,
     878,   879,   888,   890,   992,   891,   892,   893,   894,   895,
     896,   997,   897,   898,   999,   899,   900,   901,   902,  1000,
     903,   904,   905,   906,   907,   908,   909,   910,   911,   912,
     913,   914,   915,   916,   917,   918,   919,   920,   921,   943,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     975,   976,   977,   978,   979,   980,   986,   987,   988,   989,
     990,   991,  1002,   998,  1004,   995,  1005,  1001,  1006,  1007,
    1008,  1009,  1010,  1012,  1011,  1013,  1014,  1018,  1019,  1020,
    1021,  1022,  1050,  1023,  1024,  1025,  1026,  1027,  1028,  1029,
    1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,  1038,  1039,
    1051,  1052,  1076,  1040,  1041,  1043,  1044,  1045,  1047,  1053,
    1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,  1078,  1062,
    1063,  1080,  1064,  1065,  1066,  1067,  1072,  1073,  1074,  1075,
    1088,  1079,  1089,  1077,  1082,  1081,  1091,  1092,  1093,  1094,
    1095,  1096,  1097,  1101,  1102,  1105,  1106,  1107,  1108,  1109,
    1110,  1111,  1113,  1112,  1117,  1114,  1115,  1116,  1118,  1119,
    1120,  1121,  1136,  1137,  1142,  1143,  1144,  1145,  1146,  1170,
    1150,  1156,  1151,  1171,  1152,  1173,  1153,  1174,  1154,  1175,
    1155,  1159,  1177,  1232,  1165,  1166,  1271,  1178,  1276,   540,
    1168,  1172,  1179,  1176,  1180,  1181,  1184,  1198,  1199,  1213,
    1214,  1215,  1216,  1217,  1218,  1219,  1220,   334,  1049,  1354,
    1352,  1221,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1229,
    1230,  1231,  1236,  1237,  1238,  1353,  1239,  1240,  1325,  1241,
    1242,  1243,  1273,  1274,  1275,  1280,  1322,  1281,  1282,  1304,
     501,  1323,  1272,  1348,   788,  1351,   815,  1349,   864,  1350,
     644,   366,   881,  1319,  1324,   651,   820,   432,  1247,  1246,
    1321,  1320,   729,   354,     0,     0,     0,     0,     0,     0,
     525,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   734,     0,     0,   718,   741
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-816))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     340,   341,   425,     1,     1,    11,    10,   347,    12,    11,
       1,     1,   261,   261,     1,     1,   265,   265,     8,     9,
       1,     1,    12,    27,   263,    22,    76,    31,     1,    19,
       1,   261,   263,     1,   263,   265,     1,   377,    28,   379,
     263,   261,    32,    33,     1,   265,   263,     1,     1,    39,
       1,   263,   392,    43,    44,   395,    46,     1,     1,   261,
     400,     1,    52,   265,   261,     1,     1,     3,   265,    37,
       6,   411,   412,   261,   414,   261,   262,   265,   263,    47,
      70,    71,    22,   423,   424,    75,   426,   261,   263,    25,
      26,   265,    82,    37,     1,   261,    86,    87,    88,   265,
      53,    91,   261,    47,    94,    95,   265,   154,    89,   154,
      14,    15,    16,    49,   104,   263,    89,    53,    89,    26,
     110,   111,   120,   113,   114,   115,   116,   117,   125,   120,
      83,     1,   118,   120,   261,    89,    89,   261,   265,   129,
     120,   265,    49,    13,   198,   199,    53,    83,   138,    85,
     140,   141,   120,   143,   263,   120,   146,   147,   156,   156,
     150,   118,    98,   149,    34,    35,   981,   982,   983,   120,
      40,   161,    42,     1,   263,   156,   120,   829,   830,   831,
     832,   833,   232,   523,   120,   125,   236,   198,   199,     1,
     188,   156,   149,   183,   200,   185,     1,   188,   200,   189,
     153,   188,   156,   193,   194,   195,   196,   197,   188,    37,
     261,   201,   202,   156,   265,   263,   156,   153,    23,    24,
     210,   156,     1,   188,   263,    30,    96,    97,   132,    41,
     261,   167,   170,   171,   265,   105,   106,   188,     1,   243,
     263,   148,    54,   154,   180,   188,   263,   217,   218,     1,
     157,   158,   242,   188,   244,   263,    84,   127,   128,   264,
     250,   261,   249,    26,    76,   255,    78,   263,    80,    81,
     260,   262,   262,   261,   144,   145,    55,    56,    57,    58,
      59,    60,    61,    62,   191,   155,    49,    99,     1,   262,
      53,     4,   120,   154,   164,   123,   124,   262,   249,   261,
     264,    53,   107,   108,   109,   262,   249,   112,   262,   262,
     154,   262,   264,   263,   249,   120,   264,   264,   262,   262,
     256,   132,   262,   264,   103,   264,   262,   264,   261,   134,
     135,    83,    45,   264,   264,    48,   264,    89,   166,   264,
     168,   169,   249,   264,     1,   264,   151,   152,   221,   222,
     223,   224,   225,   226,   227,   262,   184,   120,   264,   264,
     139,   264,   264,   174,   175,   176,   177,   178,     1,   264,
     264,   264,   712,   263,   179,   264,   264,   264,     1,   264,
     264,   251,   252,   253,    41,   148,   264,   264,   264,   102,
     264,   263,   262,    26,   154,     1,   264,    54,   264,   264,
     228,   153,     8,     9,   167,   264,    12,   120,   264,   264,
       1,   264,     1,    19,    37,     4,    49,   264,   264,    76,
      53,    78,    28,    80,    81,   264,    32,    33,   256,   257,
     264,   264,   264,    39,   262,    26,   261,    43,    44,   862,
      46,   220,    99,   264,   264,   264,    52,   264,   264,   264,
     262,   264,   198,   132,   264,   264,    45,   262,    49,    48,
     264,    84,    53,   264,    70,    71,     1,   264,     3,    75,
     264,     6,   264,   264,   237,   254,    82,   264,   264,   264,
      86,    87,    88,   262,   264,    91,   249,   264,    94,    95,
      25,    26,   264,   264,   264,   264,   264,   120,   104,   262,
     123,   124,   264,   264,   110,   111,   264,   113,   114,   115,
     116,   117,   852,   102,    49,   148,   264,   264,    53,   264,
     860,   861,   264,   129,   157,   158,     5,   264,   264,   120,
     264,   120,   138,   264,   140,   141,   249,   143,   264,   264,
     146,   147,   264,   166,   150,   168,   169,   264,    83,   262,
      85,   132,   264,   264,   264,   161,   264,   148,   191,    38,
     264,   184,   264,    98,   264,     1,   264,   264,   264,     1,
      49,   264,   264,   264,   264,   264,   167,   183,   264,   185,
     264,    13,   264,   189,   264,   120,    65,   193,   194,   195,
     196,   197,   264,    72,   264,   201,   202,   264,    77,   264,
      79,   264,    34,    35,   210,   228,   198,   132,    40,   132,
      42,   198,   132,    92,   198,   198,   249,   132,   153,    55,
      56,    57,    58,    59,    60,    61,    62,   198,   198,   198,
       1,   198,   167,   256,   257,   198,   242,   261,   244,   264,
     154,   261,   264,   264,   250,   180,   237,   126,   264,   255,
      92,   198,    23,    24,   260,   198,     0,     1,   249,    30,
     249,     5,   132,   142,    96,    97,   154,   103,   132,   198,
     198,   132,   154,   105,   106,   132,   198,   132,    22,   132,
     198,   160,    26,   162,   163,    29,    20,    21,   198,   198,
     198,   154,    36,   132,   132,   127,   128,   132,    92,   132,
     154,   132,   132,   139,   198,   198,   264,    51,   198,   264,
     154,   198,   144,   145,   198,   198,    50,   198,   198,    63,
      64,   256,    66,   155,   198,   132,   198,   198,   261,    73,
     172,   198,   164,    67,   264,   261,   107,   108,   109,   198,
      74,   112,   154,   264,   154,   264,    90,   264,   264,   120,
     154,   230,   264,   264,   154,   261,   100,   264,   102,    93,
     264,   264,   204,   134,   135,   264,   264,   264,   264,   248,
     154,   154,   264,   264,   154,   119,   154,   219,   172,   258,
     151,   152,   154,   198,   220,   154,   261,   121,   122,   154,
     154,   264,   261,   137,   154,   261,   130,   239,   240,   264,
     198,   198,   264,   245,   246,   247,   248,   198,   179,   198,
     204,   198,   261,   154,   154,   154,   258,   198,   254,   251,
     252,   253,   154,   154,   154,   219,   154,   264,   172,   132,
     154,   154,   261,   261,   261,   261,   261,   181,   182,   173,
     264,   264,   186,   187,   264,   239,   240,   261,   261,   154,
     261,   245,   246,   247,   248,   261,   261,   159,   192,   205,
     206,   207,   208,   209,   258,   211,   212,   154,   214,   215,
     216,   261,   264,   219,   154,   261,   261,   154,   203,   261,
     275,   198,   261,   229,   230,   231,   261,   233,   234,   235,
     264,   261,   238,   261,   261,   241,   205,   206,   207,   208,
     209,   264,   211,   212,   261,   214,   215,   216,   261,   261,
     219,   261,   261,   261,   132,  1183,   132,   264,   261,   264,
     229,   230,   231,   261,   233,   234,   235,   264,   264,   238,
     154,   264,   241,   205,   206,   207,   208,   209,   264,   211,
     212,   261,   214,   215,   216,   264,   264,   219,   264,   264,
     264,   264,   264,   264,   264,   261,   264,   229,   230,   231,
     264,   233,   234,   235,   264,   264,   238,   264,   264,   241,
     264,   264,   264,   261,   264,   261,   261,   261,   261,   261,
     261,   154,   261,   261,   154,   261,   261,   261,   261,   198,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   154,   261,   154,   264,   154,   264,   154,   261,
     154,   264,   154,   264,   261,   154,   154,   261,   261,   261,
     261,   261,   154,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     154,   154,   154,   264,   264,   264,   264,   264,   264,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   154,   261,
     261,   154,   261,   261,   261,   261,   261,   261,   261,   261,
     132,   261,   132,   264,   261,   264,   132,   132,   132,   132,
     154,   132,   132,   261,   154,   154,   154,   198,   264,   154,
     154,   154,   132,   154,   261,   154,   154,   154,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   131,   154,
     261,   159,   261,   198,   261,   154,   261,   154,   261,   154,
     261,   261,   154,   131,   261,   261,   132,   261,   131,   313,
     265,   264,   261,   264,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,    71,   773,  1347,
    1326,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,  1328,   261,   261,  1270,   261,
     261,   261,   261,   261,   261,   261,  1252,   261,   261,   261,
     258,  1254,  1168,  1307,   512,  1312,   545,  1309,   595,  1310,
     360,   124,   625,  1245,  1268,   372,   553,   184,  1128,  1126,
    1251,  1249,   457,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   472,    -1,    -1,   440,   482
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   267,     0,     1,     5,    22,    26,    29,    36,    51,
      63,    64,    66,    73,    90,   100,   102,   119,   137,   172,
     181,   182,   186,   187,   268,   273,   278,   296,   302,   317,
     340,   359,   373,   391,   398,   408,   417,   443,   453,   459,
     463,   473,   537,   553,   574,   261,   262,   263,   263,   341,
     418,   454,   263,   464,   263,   538,   374,   444,   360,   263,
     263,   318,   392,   263,   263,   399,   409,     1,    37,    47,
     120,   297,   298,   299,   300,   301,     1,    13,    34,    35,
      40,    42,    96,    97,   105,   106,   127,   128,   144,   145,
     155,   164,   251,   252,   253,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   154,   342,   346,   154,   419,
     423,   263,     1,    89,   460,   461,   462,   263,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    46,
      52,    70,    71,    75,    82,    86,    87,    88,    91,    94,
      95,   104,   110,   111,   113,   114,   115,   116,   117,   129,
     138,   140,   141,   143,   146,   147,   150,   161,   183,   185,
     189,   193,   194,   195,   196,   197,   201,   202,   210,   242,
     244,   250,   255,   260,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     500,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   524,   525,   529,   533,   534,   535,
     536,   263,   263,   263,   263,     1,    55,    56,    57,    58,
      59,    60,    61,    62,   103,   139,   220,   254,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,     1,   118,   149,   274,   275,   276,   277,   154,
     319,   323,   263,     1,    41,    54,    76,    78,    80,    81,
      99,   575,   576,   577,   578,   579,   580,   581,   582,   583,
       1,    37,    84,   120,   123,   124,   166,   168,   169,   184,
     228,   256,   257,   279,   280,   281,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   263,   263,   261,
     264,   264,   264,   262,   298,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   555,   263,   263,     1,    89,   156,
     455,   456,   457,   458,   264,   262,   461,     1,   120,   156,
     188,   465,   469,   470,   471,   472,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   530,   264,
     526,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   262,   475,     1,     4,    45,    48,   102,   120,   249,
     539,   540,   541,   542,   543,   547,   548,   549,     1,    26,
      49,    53,   148,   157,   158,   191,   249,   375,   376,   377,
     378,   379,   380,   381,   388,   389,   390,     1,   156,   188,
     249,   445,   449,   450,   451,   452,     1,    53,    83,    89,
     153,   361,   365,   366,   367,   371,   372,   261,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     262,   304,   261,   264,   264,   262,   275,   263,     1,    22,
     125,   156,   393,   394,   395,   396,   397,   264,   264,   264,
     264,   264,   264,   264,   262,   576,   261,   264,   264,   264,
     264,   264,   264,   264,   282,   264,   264,   264,   264,   262,
     280,     1,   120,   188,   249,   400,   401,   402,   403,   404,
       1,   120,   188,   410,   411,   412,   413,   154,   154,   154,
     261,   198,   132,   132,   198,   198,   132,   270,   270,   132,
     132,   198,   198,   132,   270,   198,   198,   198,   198,   198,
     261,     1,    23,    24,    30,   107,   108,   109,   112,   120,
     134,   135,   151,   152,   179,   343,   344,   345,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
       1,     3,     6,    25,    26,    49,    53,    83,    85,    98,
     120,   153,   167,   180,   256,   420,   421,   422,   424,   425,
     426,   427,   428,   429,   430,   437,   438,   439,   440,   441,
     442,   264,   264,   262,   456,   154,   261,   264,   264,   466,
     262,   470,   198,   270,   198,   270,   132,   154,   132,   198,
     198,   132,   154,   198,   132,   132,   132,   198,   270,   198,
     198,   270,   154,   198,   132,   132,   270,   132,   132,   154,
     132,   132,   198,   198,   264,   198,   264,   270,   270,   198,
     270,   154,   198,   198,   198,   198,   199,   198,   199,   198,
     198,   270,   270,   132,   272,   270,   198,   198,   198,   198,
     261,   550,   264,   264,   544,   264,   264,   262,   540,   261,
     264,   264,   382,   264,   264,   264,   264,   264,   262,   376,
     264,   446,   264,   262,   450,   261,   362,   264,   264,   264,
     262,   366,   154,   154,   154,   154,   154,   154,   154,   154,
     221,   222,   223,   224,   225,   226,   227,   154,   154,   198,
     261,   154,   154,   261,     1,    26,    49,    53,   120,   148,
     167,   237,   249,   320,   321,   322,   324,   325,   326,   327,
     328,   329,   333,   261,   264,   264,   264,   262,   394,   198,
     198,   198,   154,   198,   198,   270,   261,   154,   198,   154,
     154,   154,   154,   154,   264,   154,   132,   154,   154,   261,
     261,   264,   405,   264,   262,   401,   261,   264,   414,   262,
     411,   261,   261,   261,   261,   261,   261,   261,   261,   174,
     175,   176,   177,   178,   269,   270,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   262,   344,   261,   264,   264,   264,   264,
     264,   431,   264,   264,   264,   264,   264,   264,   264,   264,
     262,   421,   154,   154,   261,   261,   154,   154,   264,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   205,   206,   207,   208,   209,   211,   212,   214,
     215,   216,   219,   229,   230,   231,   233,   234,   235,   238,
     241,   531,   532,   261,   205,   206,   207,   208,   209,   211,
     212,   214,   215,   216,   219,   229,   230,   231,   233,   234,
     235,   238,   241,   527,   528,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,    14,    15,    16,   271,   272,   261,   261,   261,   261,
     261,   261,   264,   270,   198,   264,   154,   154,   261,   154,
     198,   264,   154,   132,   154,   154,   154,   261,   154,   264,
     154,   261,   264,   154,   154,   132,   369,   370,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     264,   264,   334,   264,   264,   264,   330,   264,   262,   321,
     154,   154,   154,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   170,   171,
     283,   284,   261,   261,   261,   261,   154,   264,   154,   261,
     154,   264,   261,   269,   269,   269,   269,   269,   132,   132,
     270,   132,   132,   132,   132,   154,   132,   132,   270,   270,
     272,   261,   154,   217,   218,   154,   154,   198,   264,   154,
     154,   154,   154,   132,   154,   154,   154,   261,   261,   261,
     261,   261,   159,   467,   468,   261,   265,   261,   265,   271,
     271,   271,    11,   200,   551,   552,   261,   261,    11,   200,
     545,   546,   261,   261,   261,   261,   131,   383,   384,   386,
     261,   261,   261,   261,   261,   261,   159,   447,   448,   261,
      76,   232,   236,   363,   364,   261,   261,   203,   265,   368,
     154,   198,   264,   154,   154,   154,   264,   154,   261,   261,
     261,   261,   261,   265,   261,    92,   172,   204,   219,   239,
     240,   245,   246,   247,   248,   258,   406,   407,   261,   261,
      92,   172,   204,   219,   239,   240,   245,   246,   247,   248,
     258,   415,   416,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   131,   432,   433,   435,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   265,   532,   528,   261,   265,
     261,   265,   385,   261,   265,    20,    21,    50,    67,    74,
      93,   121,   122,   130,   173,   192,   387,   261,   265,   261,
     265,   132,   370,   261,   261,   261,   131,   335,   336,   338,
     261,   261,   261,   205,   206,   207,   208,   209,   211,   212,
     214,   215,   216,   219,   229,   230,   231,   233,   234,   235,
     238,   241,   331,   332,   261,   284,   261,   265,   261,   265,
     434,   261,   265,    10,    12,    27,    31,   243,   436,   468,
     552,   546,   387,   384,   448,   364,   337,   261,   265,     5,
      38,    49,    65,    72,    77,    79,    92,   126,   142,   160,
     162,   163,   230,   248,   258,   339,   261,   265,   407,   416,
     436,   433,   339,   336,   332
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
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

/* Line 1806 of yacc.c  */
#line 424 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 426 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 430 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 434 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 438 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 442 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 446 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 451 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 455 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 469 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 495 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 501 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 515 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 521 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 529 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 563 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 623 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 638 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      ilog(L_ERROR, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 74:

/* Line 1806 of yacc.c  */
#line 653 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 75:

/* Line 1806 of yacc.c  */
#line 662 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 676 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 685 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && *yylval.string != '*')
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
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

  case 78:

/* Line 1806 of yacc.c  */
#line 713 "ircd_parser.y"
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
      ilog(L_ERROR, "Invalid netmask for server vhost6(%s)", yylval.string);
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

  case 79:

/* Line 1806 of yacc.c  */
#line 743 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 766 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 781 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 89:

/* Line 1806 of yacc.c  */
#line 790 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 90:

/* Line 1806 of yacc.c  */
#line 799 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 107:

/* Line 1806 of yacc.c  */
#line 826 "ircd_parser.y"
    {
                        }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 830 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 834 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 841 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 848 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 855 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 862 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 869 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 876 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 883 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 890 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 894 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 898 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 902 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 906 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 910 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 914 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 920 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 929 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 942 "ircd_parser.y"
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

      new_aconf->type = parse_netmask(new_aconf->host, &new_aconf->ipnum,
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

  case 140:

/* Line 1806 of yacc.c  */
#line 1032 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1044 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1056 "ircd_parser.y"
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

      yy_aconf->type = parse_netmask(yy_aconf->host, &yy_aconf->ipnum,
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

  case 143:

/* Line 1806 of yacc.c  */
#line 1093 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1105 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1116 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1158 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 147:

/* Line 1806 of yacc.c  */
#line 1167 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1174 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1178 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1182 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1186 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1190 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1194 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1198 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1202 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1206 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1210 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1214 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1218 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1222 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1226 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1230 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1234 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1238 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1242 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1246 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1252 "ircd_parser.y"
    {
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1256 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1257 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1260 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1267 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1274 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1281 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1288 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1295 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1302 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1309 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1316 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1323 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1330 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1337 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1344 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1351 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1358 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1365 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1378 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1385 "ircd_parser.y"
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

  case 214:

/* Line 1806 of yacc.c  */
#line 1445 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1454 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1463 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1469 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1475 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1481 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1487 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1493 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1499 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1505 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1511 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1517 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1523 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1529 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1538 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:

/* Line 1806 of yacc.c  */
#line 1545 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:

/* Line 1806 of yacc.c  */
#line 1554 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1560 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1564 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1568 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1578 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1583 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1597 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1617 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:

/* Line 1806 of yacc.c  */
#line 1626 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:

/* Line 1806 of yacc.c  */
#line 1638 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1650 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1712 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1749 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1762 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:

/* Line 1806 of yacc.c  */
#line 1771 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1782 "ircd_parser.y"
    {
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1786 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1787 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1790 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1797 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1804 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1811 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 281:

/* Line 1806 of yacc.c  */
#line 1818 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 282:

/* Line 1806 of yacc.c  */
#line 1825 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1832 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1839 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 285:

/* Line 1806 of yacc.c  */
#line 1846 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 286:

/* Line 1806 of yacc.c  */
#line 1853 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 287:

/* Line 1806 of yacc.c  */
#line 1860 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_TLS;
    else yy_aconf->flags |= CONF_FLAGS_NEED_TLS;
  }
}
    break;

  case 288:

/* Line 1806 of yacc.c  */
#line 1870 "ircd_parser.y"
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

  case 289:

/* Line 1806 of yacc.c  */
#line 1889 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1899 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1912 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1931 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 300:

/* Line 1806 of yacc.c  */
#line 1940 "ircd_parser.y"
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

  case 301:

/* Line 1806 of yacc.c  */
#line 1955 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 302:

/* Line 1806 of yacc.c  */
#line 1968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 303:

/* Line 1806 of yacc.c  */
#line 1976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1987 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:

/* Line 1806 of yacc.c  */
#line 1996 "ircd_parser.y"
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

  case 312:

/* Line 1806 of yacc.c  */
#line 2018 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 2025 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 2029 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 2033 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 2037 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 2041 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 2045 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2049 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2053 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2057 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2061 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2065 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2074 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 328:

/* Line 1806 of yacc.c  */
#line 2081 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2094 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 335:

/* Line 1806 of yacc.c  */
#line 2100 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2107 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2111 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2115 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2119 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2123 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2127 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2131 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2135 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2139 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2143 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2147 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 350:

/* Line 1806 of yacc.c  */
#line 2156 "ircd_parser.y"
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

  case 351:

/* Line 1806 of yacc.c  */
#line 2174 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2312 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2324 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2336 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 374:

/* Line 1806 of yacc.c  */
#line 2345 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(yylval.string, NULL, &hints, &res))
      ilog(L_ERROR, "Invalid netmask for server vhost(%s)", yylval.string);
    else
    {
      assert(res != NULL);

      memcpy(&yy_aconf->my_ipnum, res->ai_addr, res->ai_addrlen);
      yy_aconf->my_ipnum.ss.ss_family = res->ai_family;
      yy_aconf->my_ipnum.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 375:

/* Line 1806 of yacc.c  */
#line 2371 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2389 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2407 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2413 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2417 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2425 "ircd_parser.y"
    {
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2429 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2430 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 388:

/* Line 1806 of yacc.c  */
#line 2433 "ircd_parser.y"
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

  case 389:

/* Line 1806 of yacc.c  */
#line 2444 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 2451 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2458 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2465 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 393:

/* Line 1806 of yacc.c  */
#line 2475 "ircd_parser.y"
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

  case 394:

/* Line 1806 of yacc.c  */
#line 2516 "ircd_parser.y"
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

  case 395:

/* Line 1806 of yacc.c  */
#line 2527 "ircd_parser.y"
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

  case 396:

/* Line 1806 of yacc.c  */
#line 2540 "ircd_parser.y"
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

  case 397:

/* Line 1806 of yacc.c  */
#line 2553 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2562 "ircd_parser.y"
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

  case 399:

/* Line 1806 of yacc.c  */
#line 2597 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 2604 "ircd_parser.y"
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

  case 401:

/* Line 1806 of yacc.c  */
#line 2660 "ircd_parser.y"
    {
}
    break;

  case 405:

/* Line 1806 of yacc.c  */
#line 2665 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 412:

/* Line 1806 of yacc.c  */
#line 2674 "ircd_parser.y"
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

  case 413:

/* Line 1806 of yacc.c  */
#line 2693 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 2702 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 415:

/* Line 1806 of yacc.c  */
#line 2706 "ircd_parser.y"
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

  case 421:

/* Line 1806 of yacc.c  */
#line 2728 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 422:

/* Line 1806 of yacc.c  */
#line 2734 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 2748 "ircd_parser.y"
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

  case 429:

/* Line 1806 of yacc.c  */
#line 2766 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 430:

/* Line 1806 of yacc.c  */
#line 2773 "ircd_parser.y"
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

  case 431:

/* Line 1806 of yacc.c  */
#line 2813 "ircd_parser.y"
    {
}
    break;

  case 435:

/* Line 1806 of yacc.c  */
#line 2818 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 2827 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 443:

/* Line 1806 of yacc.c  */
#line 2833 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2878 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2883 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2888 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2893 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2898 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2903 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2908 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2913 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2918 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2923 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2928 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2933 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2938 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2943 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2948 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2953 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2958 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2963 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2968 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2974 "ircd_parser.y"
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

  case 523:

/* Line 1806 of yacc.c  */
#line 2985 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2990 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2999 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 3004 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 3009 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 3014 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 3019 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 3024 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3027 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3032 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3035 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3040 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3045 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 3050 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 3055 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3060 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3065 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3070 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3075 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3080 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3091 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3096 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3101 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3106 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 3115 "ircd_parser.y"
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

  case 548:

/* Line 1806 of yacc.c  */
#line 3147 "ircd_parser.y"
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

  case 549:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3179 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3184 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3189 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 3194 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3200 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3203 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3206 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3209 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3212 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3215 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3218 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3221 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3224 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3227 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3230 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3233 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3239 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3242 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3248 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 3259 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3265 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3268 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3271 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3274 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3277 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3280 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3283 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3286 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3289 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3292 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3295 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3298 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3301 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3304 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3307 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3316 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3319 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3324 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3329 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3334 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3339 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3348 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3355 "ircd_parser.y"
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

  case 615:

/* Line 1806 of yacc.c  */
#line 3381 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 3387 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:

/* Line 1806 of yacc.c  */
#line 3393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 3399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 3403 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 623:

/* Line 1806 of yacc.c  */
#line 3409 "ircd_parser.y"
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

  case 624:

/* Line 1806 of yacc.c  */
#line 3443 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 3452 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 626:

/* Line 1806 of yacc.c  */
#line 3456 "ircd_parser.y"
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

  case 629:

/* Line 1806 of yacc.c  */
#line 3503 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 630:

/* Line 1806 of yacc.c  */
#line 3507 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3531 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3536 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3541 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3546 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 3551 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3556 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3561 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3566 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3571 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3576 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3581 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3586 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3591 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3596 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3601 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3606 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3611 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 670:

/* Line 1806 of yacc.c  */
#line 3616 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 682:

/* Line 1806 of yacc.c  */
#line 3635 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 683:

/* Line 1806 of yacc.c  */
#line 3641 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 3647 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 685:

/* Line 1806 of yacc.c  */
#line 3656 "ircd_parser.y"
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

  case 686:

/* Line 1806 of yacc.c  */
#line 3670 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 687:

/* Line 1806 of yacc.c  */
#line 3676 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 688:

/* Line 1806 of yacc.c  */
#line 3682 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 8093 "ircd_parser.c"
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



