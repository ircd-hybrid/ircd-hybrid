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
     NETWORK_DESC = 377,
     NETWORK_NAME = 378,
     NICK = 379,
     NICK_CHANGES = 380,
     NO_CREATE_ON_SPLIT = 381,
     NO_JOIN_ON_SPLIT = 382,
     NO_OPER_FLOOD = 383,
     NO_TILDE = 384,
     NOT = 385,
     NUMBER = 386,
     NUMBER_PER_IDENT = 387,
     NUMBER_PER_CIDR = 388,
     NUMBER_PER_IP = 389,
     NUMBER_PER_IP_GLOBAL = 390,
     OPERATOR = 391,
     OPERS_BYPASS_CALLERID = 392,
     OPER_LOG = 393,
     OPER_ONLY_UMODES = 394,
     OPER_PASS_RESV = 395,
     OPER_SPY_T = 396,
     OPER_UMODES = 397,
     JOIN_FLOOD_COUNT = 398,
     JOIN_FLOOD_TIME = 399,
     PACE_WAIT = 400,
     PACE_WAIT_SIMPLE = 401,
     PASSWORD = 402,
     PATH = 403,
     PING_COOKIE = 404,
     PING_TIME = 405,
     PING_WARNING = 406,
     PORT = 407,
     QSTRING = 408,
     QUIET_ON_BAN = 409,
     REASON = 410,
     REDIRPORT = 411,
     REDIRSERV = 412,
     REGEX_T = 413,
     REHASH = 414,
     TREJECT_HOLD_TIME = 415,
     REMOTE = 416,
     REMOTEBAN = 417,
     RESTRICT_CHANNELS = 418,
     RESTRICTED = 419,
     RSA_PRIVATE_KEY_FILE = 420,
     RSA_PUBLIC_KEY_FILE = 421,
     SSL_CERTIFICATE_FILE = 422,
     T_SSL_CONNECTION_METHOD = 423,
     T_SSLV3 = 424,
     T_TLSV1 = 425,
     RESV = 426,
     RESV_EXEMPT = 427,
     SECONDS = 428,
     MINUTES = 429,
     HOURS = 430,
     DAYS = 431,
     WEEKS = 432,
     SENDQ = 433,
     SEND_PASSWORD = 434,
     SERVERHIDE = 435,
     SERVERINFO = 436,
     SERVLINK_PATH = 437,
     IRCD_SID = 438,
     TKLINE_EXPIRE_NOTICES = 439,
     T_SHARED = 440,
     T_CLUSTER = 441,
     TYPE = 442,
     SHORT_MOTD = 443,
     SILENT = 444,
     SPOOF = 445,
     SPOOF_NOTICE = 446,
     STATS_E_DISABLED = 447,
     STATS_I_OPER_ONLY = 448,
     STATS_K_OPER_ONLY = 449,
     STATS_O_OPER_ONLY = 450,
     STATS_P_OPER_ONLY = 451,
     TBOOL = 452,
     TMASKED = 453,
     T_REJECT = 454,
     TS_MAX_DELTA = 455,
     TS_WARN_DELTA = 456,
     TWODOTS = 457,
     T_ALL = 458,
     T_BOTS = 459,
     T_SOFTCALLERID = 460,
     T_CALLERID = 461,
     T_CCONN = 462,
     T_CCONN_FULL = 463,
     T_CLIENT_FLOOD = 464,
     T_DEAF = 465,
     T_DEBUG = 466,
     T_DRONE = 467,
     T_EXTERNAL = 468,
     T_FULL = 469,
     T_INVISIBLE = 470,
     T_IPV4 = 471,
     T_IPV6 = 472,
     T_LOCOPS = 473,
     T_LOGPATH = 474,
     T_L_CRIT = 475,
     T_L_DEBUG = 476,
     T_L_ERROR = 477,
     T_L_INFO = 478,
     T_L_NOTICE = 479,
     T_L_TRACE = 480,
     T_L_WARN = 481,
     T_MAX_CLIENTS = 482,
     T_NCHANGE = 483,
     T_OPERWALL = 484,
     T_REJ = 485,
     T_SERVER = 486,
     T_SERVNOTICE = 487,
     T_SKILL = 488,
     T_SPY = 489,
     T_SSL = 490,
     T_UMODES = 491,
     T_UNAUTH = 492,
     T_UNRESV = 493,
     T_UNXLINE = 494,
     T_WALLOP = 495,
     THROTTLE_TIME = 496,
     TOPICBURST = 497,
     TRUE_NO_OPER_FLOOD = 498,
     TKLINE = 499,
     TXLINE = 500,
     TRESV = 501,
     UNKLINE = 502,
     USER = 503,
     USE_EGD = 504,
     USE_EXCEPT = 505,
     USE_INVEX = 506,
     USE_KNOCK = 507,
     USE_LOGGING = 508,
     USE_WHOIS_ACTUALLY = 509,
     VHOST = 510,
     VHOST6 = 511,
     XLINE = 512,
     WARN = 513,
     WARN_NO_NLINE = 514
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
#define NETWORK_DESC 377
#define NETWORK_NAME 378
#define NICK 379
#define NICK_CHANGES 380
#define NO_CREATE_ON_SPLIT 381
#define NO_JOIN_ON_SPLIT 382
#define NO_OPER_FLOOD 383
#define NO_TILDE 384
#define NOT 385
#define NUMBER 386
#define NUMBER_PER_IDENT 387
#define NUMBER_PER_CIDR 388
#define NUMBER_PER_IP 389
#define NUMBER_PER_IP_GLOBAL 390
#define OPERATOR 391
#define OPERS_BYPASS_CALLERID 392
#define OPER_LOG 393
#define OPER_ONLY_UMODES 394
#define OPER_PASS_RESV 395
#define OPER_SPY_T 396
#define OPER_UMODES 397
#define JOIN_FLOOD_COUNT 398
#define JOIN_FLOOD_TIME 399
#define PACE_WAIT 400
#define PACE_WAIT_SIMPLE 401
#define PASSWORD 402
#define PATH 403
#define PING_COOKIE 404
#define PING_TIME 405
#define PING_WARNING 406
#define PORT 407
#define QSTRING 408
#define QUIET_ON_BAN 409
#define REASON 410
#define REDIRPORT 411
#define REDIRSERV 412
#define REGEX_T 413
#define REHASH 414
#define TREJECT_HOLD_TIME 415
#define REMOTE 416
#define REMOTEBAN 417
#define RESTRICT_CHANNELS 418
#define RESTRICTED 419
#define RSA_PRIVATE_KEY_FILE 420
#define RSA_PUBLIC_KEY_FILE 421
#define SSL_CERTIFICATE_FILE 422
#define T_SSL_CONNECTION_METHOD 423
#define T_SSLV3 424
#define T_TLSV1 425
#define RESV 426
#define RESV_EXEMPT 427
#define SECONDS 428
#define MINUTES 429
#define HOURS 430
#define DAYS 431
#define WEEKS 432
#define SENDQ 433
#define SEND_PASSWORD 434
#define SERVERHIDE 435
#define SERVERINFO 436
#define SERVLINK_PATH 437
#define IRCD_SID 438
#define TKLINE_EXPIRE_NOTICES 439
#define T_SHARED 440
#define T_CLUSTER 441
#define TYPE 442
#define SHORT_MOTD 443
#define SILENT 444
#define SPOOF 445
#define SPOOF_NOTICE 446
#define STATS_E_DISABLED 447
#define STATS_I_OPER_ONLY 448
#define STATS_K_OPER_ONLY 449
#define STATS_O_OPER_ONLY 450
#define STATS_P_OPER_ONLY 451
#define TBOOL 452
#define TMASKED 453
#define T_REJECT 454
#define TS_MAX_DELTA 455
#define TS_WARN_DELTA 456
#define TWODOTS 457
#define T_ALL 458
#define T_BOTS 459
#define T_SOFTCALLERID 460
#define T_CALLERID 461
#define T_CCONN 462
#define T_CCONN_FULL 463
#define T_CLIENT_FLOOD 464
#define T_DEAF 465
#define T_DEBUG 466
#define T_DRONE 467
#define T_EXTERNAL 468
#define T_FULL 469
#define T_INVISIBLE 470
#define T_IPV4 471
#define T_IPV6 472
#define T_LOCOPS 473
#define T_LOGPATH 474
#define T_L_CRIT 475
#define T_L_DEBUG 476
#define T_L_ERROR 477
#define T_L_INFO 478
#define T_L_NOTICE 479
#define T_L_TRACE 480
#define T_L_WARN 481
#define T_MAX_CLIENTS 482
#define T_NCHANGE 483
#define T_OPERWALL 484
#define T_REJ 485
#define T_SERVER 486
#define T_SERVNOTICE 487
#define T_SKILL 488
#define T_SPY 489
#define T_SSL 490
#define T_UMODES 491
#define T_UNAUTH 492
#define T_UNRESV 493
#define T_UNXLINE 494
#define T_WALLOP 495
#define THROTTLE_TIME 496
#define TOPICBURST 497
#define TRUE_NO_OPER_FLOOD 498
#define TKLINE 499
#define TXLINE 500
#define TRESV 501
#define UNKLINE 502
#define USER 503
#define USE_EGD 504
#define USE_EXCEPT 505
#define USE_INVEX 506
#define USE_KNOCK 507
#define USE_LOGGING 508
#define USE_WHOIS_ACTUALLY 509
#define VHOST 510
#define VHOST6 511
#define XLINE 512
#define WARN 513
#define WARN_NO_NLINE 514




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 739 "ircd_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 751 "ircd_parser.c"

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
#define YYLAST   1258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  265
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  318
/* YYNRULES -- Number of rules.  */
#define YYNRULES  687
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1354

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   514

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint16 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   264,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   260,
       2,   263,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   262,     2,   261,     2,     2,     2,     2,
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
     255,   256,   257,   258,   259
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
    1077,  1082,  1084,  1089,  1094,  1099,  1104,  1109,  1114,  1119,
    1120,  1126,  1130,  1132,  1133,  1137,  1138,  1141,  1143,  1145,
    1147,  1149,  1151,  1156,  1161,  1166,  1171,  1176,  1181,  1182,
    1189,  1190,  1196,  1200,  1202,  1204,  1207,  1209,  1211,  1213,
    1215,  1217,  1222,  1227,  1228,  1235,  1238,  1240,  1242,  1244,
    1246,  1251,  1256,  1262,  1265,  1267,  1269,  1271,  1276,  1277,
    1284,  1285,  1291,  1295,  1297,  1299,  1302,  1304,  1306,  1308,
    1310,  1312,  1317,  1322,  1328,  1331,  1333,  1335,  1337,  1339,
    1341,  1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,
    1361,  1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,
    1381,  1383,  1385,  1387,  1389,  1391,  1393,  1395,  1397,  1399,
    1401,  1403,  1405,  1407,  1409,  1411,  1413,  1415,  1417,  1419,
    1421,  1423,  1425,  1427,  1429,  1431,  1433,  1435,  1437,  1439,
    1441,  1443,  1445,  1450,  1455,  1460,  1465,  1470,  1475,  1480,
    1485,  1490,  1495,  1500,  1505,  1510,  1515,  1520,  1525,  1530,
    1535,  1540,  1545,  1550,  1555,  1560,  1565,  1570,  1575,  1580,
    1585,  1590,  1595,  1600,  1605,  1610,  1615,  1620,  1625,  1630,
    1635,  1640,  1645,  1650,  1655,  1660,  1665,  1670,  1675,  1680,
    1685,  1690,  1695,  1700,  1701,  1707,  1711,  1713,  1715,  1717,
    1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,
    1739,  1741,  1743,  1745,  1747,  1749,  1751,  1752,  1758,  1762,
    1764,  1766,  1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,
    1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,  1800,  1802,
    1807,  1812,  1817,  1822,  1823,  1830,  1833,  1835,  1837,  1839,
    1841,  1843,  1845,  1847,  1849,  1854,  1859,  1860,  1866,  1870,
    1872,  1874,  1876,  1881,  1886,  1887,  1893,  1897,  1899,  1901,
    1903,  1909,  1912,  1914,  1916,  1918,  1920,  1922,  1924,  1926,
    1928,  1930,  1932,  1934,  1936,  1938,  1940,  1942,  1944,  1946,
    1948,  1950,  1952,  1957,  1962,  1967,  1972,  1977,  1982,  1987,
    1992,  1997,  2002,  2007,  2012,  2017,  2022,  2027,  2032,  2037,
    2042,  2048,  2051,  2053,  2055,  2057,  2059,  2061,  2063,  2065,
    2067,  2069,  2074,  2079,  2084,  2089,  2094,  2099
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     266,     0,    -1,    -1,   266,   267,    -1,   295,    -1,   301,
      -1,   316,    -1,   552,    -1,   339,    -1,   358,    -1,   372,
      -1,   277,    -1,   573,    -1,   390,    -1,   397,    -1,   407,
      -1,   416,    -1,   442,    -1,   452,    -1,   458,    -1,   472,
      -1,   536,    -1,   462,    -1,   272,    -1,     1,   260,    -1,
       1,   261,    -1,    -1,   269,    -1,   131,   268,    -1,   131,
     173,   268,    -1,   131,   174,   268,    -1,   131,   175,   268,
      -1,   131,   176,   268,    -1,   131,   177,   268,    -1,    -1,
     271,    -1,   131,   270,    -1,   131,    14,   270,    -1,   131,
      15,   270,    -1,   131,    16,   270,    -1,   119,   262,   273,
     261,   260,    -1,   273,   274,    -1,   274,    -1,   275,    -1,
     276,    -1,     1,   260,    -1,   118,   263,   153,   260,    -1,
     148,   263,   153,   260,    -1,   181,   262,   278,   261,   260,
      -1,   278,   279,    -1,   279,    -1,   286,    -1,   291,    -1,
     294,    -1,   288,    -1,   289,    -1,   290,    -1,   293,    -1,
     285,    -1,   292,    -1,   287,    -1,   284,    -1,   280,    -1,
       1,   260,    -1,    -1,   168,   281,   263,   282,   260,    -1,
     282,   264,   283,    -1,   283,    -1,   169,    -1,   170,    -1,
     167,   263,   153,   260,    -1,   165,   263,   153,   260,    -1,
     120,   263,   153,   260,    -1,   183,   263,   153,   260,    -1,
      37,   263,   153,   260,    -1,   123,   263,   153,   260,    -1,
     122,   263,   153,   260,    -1,   255,   263,   153,   260,    -1,
     256,   263,   153,   260,    -1,   227,   263,   131,   260,    -1,
      84,   263,   197,   260,    -1,     5,   262,   296,   261,   260,
      -1,   296,   297,    -1,   297,    -1,   298,    -1,   300,    -1,
     299,    -1,     1,   260,    -1,   120,   263,   153,   260,    -1,
      47,   263,   153,   260,    -1,    37,   263,   153,   260,    -1,
     102,   262,   302,   261,   260,    -1,   302,   303,    -1,   303,
      -1,   304,    -1,   305,    -1,   314,    -1,   315,    -1,   306,
      -1,   308,    -1,   310,    -1,   311,    -1,   313,    -1,   309,
      -1,   312,    -1,   307,    -1,     1,   260,    -1,   219,   263,
     153,   260,    -1,   138,   263,   153,   260,    -1,    62,   263,
     153,   260,    -1,    55,   263,   153,   260,    -1,    60,   263,
     153,   260,    -1,    61,   263,   153,   260,    -1,    58,   263,
     153,   260,    -1,    57,   263,   153,   260,    -1,    59,   263,
     153,   260,    -1,    56,   263,   153,   260,    -1,   103,   263,
     220,   260,    -1,   103,   263,   222,   260,    -1,   103,   263,
     226,   260,    -1,   103,   263,   224,   260,    -1,   103,   263,
     225,   260,    -1,   103,   263,   223,   260,    -1,   103,   263,
     221,   260,    -1,   253,   263,   197,   260,    -1,    -1,   136,
     317,   318,   262,   319,   261,   260,    -1,    -1,   322,    -1,
     319,   320,    -1,   320,    -1,   321,    -1,   323,    -1,   324,
      -1,   328,    -1,   327,    -1,   325,    -1,   326,    -1,   332,
      -1,     1,   260,    -1,   120,   263,   153,   260,    -1,   153,
      -1,   248,   263,   153,   260,    -1,   147,   263,   153,   260,
      -1,    49,   263,   197,   260,    -1,   166,   263,   153,   260,
      -1,    26,   263,   153,   260,    -1,    -1,   236,   329,   263,
     330,   260,    -1,   330,   264,   331,    -1,   331,    -1,   204,
      -1,   207,    -1,   208,    -1,   210,    -1,   211,    -1,   214,
      -1,   233,    -1,   228,    -1,   230,    -1,   237,    -1,   234,
      -1,   213,    -1,   229,    -1,   232,    -1,   215,    -1,   240,
      -1,   205,    -1,   206,    -1,   218,    -1,    -1,    53,   333,
     263,   334,   260,    -1,   334,   264,   335,    -1,   335,    -1,
      -1,   130,   336,   338,    -1,    -1,   337,   338,    -1,    72,
      -1,   161,    -1,    92,    -1,   247,    -1,   257,    -1,    65,
      -1,    38,    -1,   159,    -1,     5,    -1,    77,    -1,   125,
      -1,   229,    -1,   141,    -1,    79,    -1,   162,    -1,    49,
      -1,    -1,    26,   340,   341,   262,   342,   261,   260,    -1,
      -1,   345,    -1,   342,   343,    -1,   343,    -1,   344,    -1,
     355,    -1,   356,    -1,   346,    -1,   347,    -1,   357,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   352,    -1,
     353,    -1,   354,    -1,     1,   260,    -1,   120,   263,   153,
     260,    -1,   153,    -1,   150,   263,   269,   260,    -1,   151,
     263,   269,   260,    -1,   134,   263,   131,   260,    -1,    30,
     263,   269,   260,    -1,   112,   263,   131,   260,    -1,   107,
     263,   131,   260,    -1,   109,   263,   131,   260,    -1,   108,
     263,   131,   260,    -1,   178,   263,   271,   260,    -1,    23,
     263,   131,   260,    -1,    24,   263,   131,   260,    -1,   133,
     263,   131,   260,    -1,    -1,   100,   359,   262,   364,   261,
     260,    -1,    -1,    53,   361,   263,   362,   260,    -1,   362,
     264,   363,    -1,   363,    -1,   235,    -1,    76,    -1,   231,
      -1,   364,   365,    -1,   365,    -1,   366,    -1,   360,    -1,
     370,    -1,   371,    -1,     1,   260,    -1,    -1,   152,   263,
     368,   367,   260,    -1,   368,   264,   369,    -1,   369,    -1,
     131,    -1,   131,   202,   131,    -1,    89,   263,   153,   260,
      -1,    83,   263,   153,   260,    -1,    -1,    73,   373,   262,
     374,   261,   260,    -1,   374,   375,    -1,   375,    -1,   376,
      -1,   377,    -1,   378,    -1,   380,    -1,   387,    -1,   388,
      -1,   389,    -1,   379,    -1,     1,   260,    -1,   248,   263,
     153,   260,    -1,   147,   263,   153,   260,    -1,    26,   263,
     153,   260,    -1,    49,   263,   197,   260,    -1,    -1,    53,
     381,   263,   382,   260,    -1,   382,   264,   383,    -1,   383,
      -1,    -1,   130,   384,   386,    -1,    -1,   385,   386,    -1,
     191,    -1,    50,    -1,    93,    -1,    74,    -1,    20,    -1,
      21,    -1,   129,    -1,    67,    -1,   172,    -1,   121,    -1,
     190,   263,   153,   260,    -1,   157,   263,   153,   260,    -1,
     156,   263,   131,   260,    -1,    -1,   171,   391,   262,   392,
     261,   260,    -1,   392,   393,    -1,   393,    -1,   394,    -1,
     395,    -1,   396,    -1,     1,   260,    -1,   155,   263,   153,
     260,    -1,    22,   263,   153,   260,    -1,   124,   263,   153,
     260,    -1,    -1,   185,   398,   262,   399,   261,   260,    -1,
     399,   400,    -1,   400,    -1,   401,    -1,   402,    -1,   403,
      -1,     1,   260,    -1,   120,   263,   153,   260,    -1,   248,
     263,   153,   260,    -1,    -1,   187,   404,   263,   405,   260,
      -1,   405,   264,   406,    -1,   406,    -1,    92,    -1,   244,
      -1,   247,    -1,   257,    -1,   245,    -1,   239,    -1,   171,
      -1,   246,    -1,   238,    -1,   218,    -1,   203,    -1,    -1,
     186,   408,   262,   409,   261,   260,    -1,   409,   410,    -1,
     410,    -1,   411,    -1,   412,    -1,     1,   260,    -1,   120,
     263,   153,   260,    -1,    -1,   187,   413,   263,   414,   260,
      -1,   414,   264,   415,    -1,   415,    -1,    92,    -1,   244,
      -1,   247,    -1,   257,    -1,   245,    -1,   239,    -1,   171,
      -1,   246,    -1,   238,    -1,   218,    -1,   203,    -1,    -1,
      29,   417,   418,   262,   419,   261,   260,    -1,    -1,   422,
      -1,   419,   420,    -1,   420,    -1,   421,    -1,   423,    -1,
     424,    -1,   425,    -1,   426,    -1,   428,    -1,   427,    -1,
     429,    -1,   438,    -1,   439,    -1,   440,    -1,   437,    -1,
     436,    -1,   441,    -1,     1,   260,    -1,   120,   263,   153,
     260,    -1,   153,    -1,    83,   263,   153,   260,    -1,   255,
     263,   153,   260,    -1,   179,   263,   153,   260,    -1,     3,
     263,   153,   260,    -1,   152,   263,   131,   260,    -1,     6,
     263,   216,   260,    -1,     6,   263,   217,   260,    -1,    -1,
      53,   430,   263,   431,   260,    -1,   431,   264,   432,    -1,
     432,    -1,    -1,   130,   433,   435,    -1,    -1,   434,   435,
      -1,    27,    -1,    31,    -1,    10,    -1,    12,    -1,   242,
      -1,   166,   263,   153,   260,    -1,    49,   263,   197,   260,
      -1,    85,   263,   153,   260,    -1,    98,   263,   153,   260,
      -1,    26,   263,   153,   260,    -1,    25,   263,   153,   260,
      -1,    -1,    90,   443,   262,   448,   261,   260,    -1,    -1,
     187,   445,   263,   446,   260,    -1,   446,   264,   447,    -1,
     447,    -1,   158,    -1,   448,   449,    -1,   449,    -1,   450,
      -1,   451,    -1,   444,    -1,     1,    -1,   248,   263,   153,
     260,    -1,   155,   263,   153,   260,    -1,    -1,    36,   453,
     262,   454,   261,   260,    -1,   454,   455,    -1,   455,    -1,
     456,    -1,   457,    -1,     1,    -1,    89,   263,   153,   260,
      -1,   155,   263,   153,   260,    -1,    51,   262,   459,   261,
     260,    -1,   459,   460,    -1,   460,    -1,   461,    -1,     1,
      -1,    89,   263,   153,   260,    -1,    -1,    63,   463,   262,
     468,   261,   260,    -1,    -1,   187,   465,   263,   466,   260,
      -1,   466,   264,   467,    -1,   467,    -1,   158,    -1,   468,
     469,    -1,   469,    -1,   470,    -1,   471,    -1,   464,    -1,
       1,    -1,   120,   263,   153,   260,    -1,   155,   263,   153,
     260,    -1,    64,   262,   473,   261,   260,    -1,   473,   474,
      -1,   474,    -1,   483,    -1,   484,    -1,   486,    -1,   487,
      -1,   488,    -1,   489,    -1,   490,    -1,   491,    -1,   492,
      -1,   493,    -1,   482,    -1,   495,    -1,   496,    -1,   497,
      -1,   498,    -1,   514,    -1,   500,    -1,   502,    -1,   504,
      -1,   503,    -1,   507,    -1,   501,    -1,   508,    -1,   509,
      -1,   510,    -1,   511,    -1,   513,    -1,   512,    -1,   528,
      -1,   515,    -1,   519,    -1,   520,    -1,   524,    -1,   505,
      -1,   506,    -1,   534,    -1,   532,    -1,   533,    -1,   516,
      -1,   485,    -1,   517,    -1,   518,    -1,   535,    -1,   523,
      -1,   494,    -1,   521,    -1,   522,    -1,   478,    -1,   481,
      -1,   476,    -1,   477,    -1,   479,    -1,   480,    -1,   499,
      -1,   475,    -1,     1,    -1,   114,   263,   131,   260,    -1,
      70,   263,   131,   260,    -1,    71,   263,   131,   260,    -1,
      12,   263,   197,   260,    -1,   254,   263,   197,   260,    -1,
     160,   263,   269,   260,    -1,   184,   263,   197,   260,    -1,
      91,   263,   269,   260,    -1,    82,   263,   197,   260,    -1,
      87,   263,   197,   260,    -1,    43,   263,   197,   260,    -1,
      52,   263,   197,   260,    -1,     8,   263,   197,   260,    -1,
     111,   263,   269,   260,    -1,   110,   263,   131,   260,    -1,
     104,   263,   131,   260,    -1,     9,   263,   269,   260,    -1,
     201,   263,   269,   260,    -1,   200,   263,   269,   260,    -1,
      75,   263,   131,   260,    -1,    95,   263,   197,   260,    -1,
      94,   263,   153,   260,    -1,    88,   263,   197,   260,    -1,
     259,   263,   197,   260,    -1,   192,   263,   197,   260,    -1,
     195,   263,   197,   260,    -1,   196,   263,   197,   260,    -1,
     194,   263,   197,   260,    -1,   194,   263,   198,   260,    -1,
     193,   263,   197,   260,    -1,   193,   263,   198,   260,    -1,
     145,   263,   269,   260,    -1,    19,   263,   269,   260,    -1,
     137,   263,   197,   260,    -1,   146,   263,   269,   260,    -1,
     188,   263,   197,   260,    -1,   128,   263,   197,   260,    -1,
     243,   263,   197,   260,    -1,   140,   263,   197,   260,    -1,
     115,   263,   153,   260,    -1,    86,   263,   269,   260,    -1,
      44,   263,   131,   260,    -1,   113,   263,   131,   260,    -1,
     182,   263,   153,   260,    -1,    32,   263,   153,   260,    -1,
      28,   263,   131,   260,    -1,   249,   263,   197,   260,    -1,
      46,   263,   153,   260,    -1,   149,   263,   197,   260,    -1,
      39,   263,   197,   260,    -1,   241,   263,   269,   260,    -1,
      -1,   142,   525,   263,   526,   260,    -1,   526,   264,   527,
      -1,   527,    -1,   204,    -1,   207,    -1,   208,    -1,   210,
      -1,   211,    -1,   214,    -1,   233,    -1,   228,    -1,   230,
      -1,   237,    -1,   234,    -1,   213,    -1,   229,    -1,   232,
      -1,   215,    -1,   240,    -1,   205,    -1,   206,    -1,   218,
      -1,    -1,   139,   529,   263,   530,   260,    -1,   530,   264,
     531,    -1,   531,    -1,   204,    -1,   207,    -1,   208,    -1,
     210,    -1,   211,    -1,   214,    -1,   233,    -1,   228,    -1,
     230,    -1,   237,    -1,   234,    -1,   213,    -1,   229,    -1,
     232,    -1,   215,    -1,   240,    -1,   205,    -1,   206,    -1,
     218,    -1,   116,   263,   131,   260,    -1,   117,   263,   131,
     260,    -1,    33,   263,   131,   260,    -1,   209,   263,   271,
     260,    -1,    -1,    66,   537,   262,   538,   261,   260,    -1,
     538,   539,    -1,   539,    -1,   540,    -1,   541,    -1,   542,
      -1,   546,    -1,   547,    -1,   548,    -1,     1,    -1,    48,
     263,   197,   260,    -1,    45,   263,   269,   260,    -1,    -1,
     102,   543,   263,   544,   260,    -1,   544,   264,   545,    -1,
     545,    -1,   199,    -1,    11,    -1,   248,   263,   153,   260,
      -1,   120,   263,   153,   260,    -1,    -1,     4,   549,   263,
     550,   260,    -1,   550,   264,   551,    -1,   551,    -1,   199,
      -1,    11,    -1,    22,   262,   553,   261,   260,    -1,   553,
     554,    -1,   554,    -1,   557,    -1,   558,    -1,   559,    -1,
     560,    -1,   565,    -1,   561,    -1,   562,    -1,   563,    -1,
     564,    -1,   566,    -1,   567,    -1,   568,    -1,   556,    -1,
     569,    -1,   570,    -1,   571,    -1,   572,    -1,   555,    -1,
       1,    -1,    40,   263,   197,   260,    -1,   163,   263,   197,
     260,    -1,    42,   263,   197,   260,    -1,   250,   263,   197,
     260,    -1,   251,   263,   197,   260,    -1,   252,   263,   197,
     260,    -1,    96,   263,   269,   260,    -1,    97,   263,   269,
     260,    -1,   106,   263,   131,   260,    -1,   154,   263,   197,
     260,    -1,   105,   263,   131,   260,    -1,    35,   263,   131,
     260,    -1,    34,   263,   131,   260,    -1,   126,   263,   197,
     260,    -1,   127,   263,   197,   260,    -1,    13,   263,   197,
     260,    -1,   143,   263,   131,   260,    -1,   144,   263,   269,
     260,    -1,   180,   262,   574,   261,   260,    -1,   574,   575,
      -1,   575,    -1,   576,    -1,   577,    -1,   579,    -1,   581,
      -1,   580,    -1,   578,    -1,   582,    -1,     1,    -1,    54,
     263,   197,   260,    -1,    81,   263,   197,   260,    -1,    78,
     263,   153,   260,    -1,    99,   263,   269,   260,    -1,    76,
     263,   197,   260,    -1,    41,   263,   197,   260,    -1,    80,
     263,   197,   260,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   394,   394,   395,   398,   399,   400,   401,   402,   403,
     404,   405,   406,   407,   408,   409,   410,   411,   412,   413,
     414,   415,   416,   417,   418,   419,   423,   423,   424,   428,
     432,   436,   440,   444,   450,   450,   451,   452,   453,   454,
     461,   464,   464,   465,   465,   465,   467,   473,   480,   482,
     482,   483,   483,   484,   484,   485,   485,   486,   487,   487,
     488,   488,   489,   490,   494,   493,   512,   512,   513,   519,
     527,   561,   621,   636,   651,   660,   674,   683,   711,   741,
     764,   773,   775,   775,   776,   776,   777,   777,   779,   788,
     797,   810,   812,   813,   815,   815,   816,   817,   817,   818,
     818,   819,   819,   820,   820,   821,   822,   824,   828,   832,
     839,   846,   853,   860,   867,   874,   881,   888,   892,   896,
     900,   904,   908,   912,   918,   928,   927,  1021,  1021,  1022,
    1022,  1023,  1023,  1023,  1024,  1024,  1024,  1025,  1025,  1025,
    1027,  1039,  1051,  1085,  1097,  1108,  1150,  1160,  1159,  1165,
    1165,  1166,  1170,  1174,  1178,  1182,  1186,  1190,  1194,  1198,
    1202,  1206,  1210,  1214,  1218,  1222,  1226,  1230,  1234,  1238,
    1245,  1244,  1248,  1248,  1249,  1249,  1250,  1250,  1252,  1259,
    1266,  1273,  1280,  1287,  1294,  1301,  1308,  1315,  1322,  1329,
    1336,  1343,  1350,  1357,  1371,  1370,  1420,  1420,  1422,  1422,
    1423,  1424,  1424,  1425,  1426,  1427,  1428,  1429,  1430,  1431,
    1432,  1433,  1434,  1435,  1437,  1446,  1455,  1461,  1467,  1473,
    1479,  1485,  1491,  1497,  1503,  1509,  1515,  1521,  1531,  1530,
    1547,  1546,  1551,  1551,  1552,  1556,  1560,  1568,  1568,  1569,
    1569,  1569,  1569,  1569,  1571,  1571,  1573,  1573,  1575,  1589,
    1609,  1618,  1631,  1630,  1699,  1699,  1700,  1700,  1700,  1700,
    1701,  1701,  1701,  1702,  1702,  1704,  1741,  1754,  1763,  1775,
    1774,  1778,  1778,  1779,  1779,  1780,  1780,  1782,  1789,  1796,
    1803,  1810,  1817,  1824,  1831,  1838,  1845,  1855,  1874,  1884,
    1898,  1897,  1913,  1913,  1914,  1914,  1914,  1914,  1916,  1925,
    1940,  1954,  1953,  1969,  1969,  1970,  1970,  1970,  1970,  1972,
    1981,  2004,  2003,  2009,  2009,  2010,  2014,  2018,  2022,  2026,
    2030,  2034,  2038,  2042,  2046,  2050,  2060,  2059,  2076,  2076,
    2077,  2077,  2077,  2079,  2086,  2085,  2091,  2091,  2092,  2096,
    2100,  2104,  2108,  2112,  2116,  2120,  2124,  2128,  2132,  2142,
    2141,  2287,  2287,  2288,  2288,  2289,  2289,  2289,  2290,  2290,
    2291,  2291,  2292,  2292,  2292,  2293,  2293,  2294,  2294,  2295,
    2297,  2309,  2321,  2330,  2356,  2374,  2392,  2398,  2402,  2411,
    2410,  2414,  2414,  2415,  2415,  2416,  2416,  2418,  2429,  2436,
    2443,  2450,  2460,  2501,  2512,  2525,  2538,  2547,  2583,  2582,
    2646,  2645,  2649,  2649,  2650,  2656,  2656,  2657,  2657,  2657,
    2657,  2659,  2678,  2688,  2687,  2710,  2710,  2711,  2711,  2711,
    2713,  2719,  2728,  2730,  2730,  2731,  2731,  2733,  2752,  2751,
    2799,  2798,  2802,  2802,  2803,  2809,  2809,  2810,  2810,  2810,
    2810,  2812,  2818,  2827,  2830,  2830,  2831,  2831,  2832,  2832,
    2833,  2833,  2834,  2834,  2835,  2835,  2836,  2836,  2837,  2837,
    2838,  2838,  2839,  2839,  2840,  2840,  2841,  2841,  2842,  2842,
    2843,  2843,  2844,  2844,  2845,  2845,  2846,  2846,  2847,  2847,
    2848,  2848,  2849,  2849,  2850,  2850,  2851,  2852,  2852,  2853,
    2853,  2854,  2855,  2855,  2856,  2856,  2857,  2857,  2858,  2858,
    2859,  2860,  2863,  2868,  2873,  2878,  2883,  2888,  2893,  2898,
    2903,  2908,  2913,  2918,  2923,  2928,  2933,  2938,  2943,  2948,
    2953,  2959,  2970,  2975,  2984,  2989,  2994,  2999,  3004,  3009,
    3012,  3017,  3020,  3025,  3030,  3035,  3040,  3045,  3050,  3055,
    3060,  3065,  3076,  3081,  3086,  3091,  3100,  3132,  3150,  3155,
    3164,  3169,  3174,  3180,  3179,  3184,  3184,  3185,  3188,  3191,
    3194,  3197,  3200,  3203,  3206,  3209,  3212,  3215,  3218,  3221,
    3224,  3227,  3230,  3233,  3236,  3239,  3245,  3244,  3249,  3249,
    3250,  3253,  3256,  3259,  3262,  3265,  3268,  3271,  3274,  3277,
    3280,  3283,  3286,  3289,  3292,  3295,  3298,  3301,  3304,  3309,
    3314,  3319,  3324,  3334,  3333,  3357,  3357,  3358,  3359,  3360,
    3361,  3362,  3363,  3364,  3366,  3372,  3379,  3378,  3383,  3383,
    3384,  3388,  3394,  3428,  3438,  3437,  3487,  3487,  3488,  3492,
    3501,  3504,  3504,  3505,  3505,  3506,  3506,  3507,  3507,  3508,
    3508,  3509,  3509,  3510,  3511,  3511,  3512,  3512,  3513,  3513,
    3514,  3514,  3516,  3521,  3526,  3531,  3536,  3541,  3546,  3551,
    3556,  3561,  3566,  3571,  3576,  3581,  3586,  3591,  3596,  3601,
    3609,  3612,  3612,  3613,  3613,  3614,  3615,  3616,  3616,  3617,
    3618,  3620,  3626,  3632,  3641,  3655,  3661,  3667
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
      59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   265,   266,   266,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   268,   268,   269,   269,
     269,   269,   269,   269,   270,   270,   271,   271,   271,   271,
     272,   273,   273,   274,   274,   274,   275,   276,   277,   278,
     278,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   281,   280,   282,   282,   283,   283,
     284,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   296,   297,   297,   297,   297,   298,   299,
     300,   301,   302,   302,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,   313,   314,   314,   314,
     314,   314,   314,   314,   315,   317,   316,   318,   318,   319,
     319,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     321,   322,   323,   324,   325,   326,   327,   329,   328,   330,
     330,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   331,
     333,   332,   334,   334,   336,   335,   337,   335,   338,   338,
     338,   338,   338,   338,   338,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   340,   339,   341,   341,   342,   342,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   359,   358,
     361,   360,   362,   362,   363,   363,   363,   364,   364,   365,
     365,   365,   365,   365,   367,   366,   368,   368,   369,   369,
     370,   371,   373,   372,   374,   374,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   376,   377,   378,   379,   381,
     380,   382,   382,   384,   383,   385,   383,   386,   386,   386,
     386,   386,   386,   386,   386,   386,   386,   387,   388,   389,
     391,   390,   392,   392,   393,   393,   393,   393,   394,   395,
     396,   398,   397,   399,   399,   400,   400,   400,   400,   401,
     402,   404,   403,   405,   405,   406,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   408,   407,   409,   409,
     410,   410,   410,   411,   413,   412,   414,   414,   415,   415,
     415,   415,   415,   415,   415,   415,   415,   415,   415,   417,
     416,   418,   418,   419,   419,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     421,   422,   423,   424,   425,   426,   427,   428,   428,   430,
     429,   431,   431,   433,   432,   434,   432,   435,   435,   435,
     435,   435,   436,   437,   438,   439,   440,   441,   443,   442,
     445,   444,   446,   446,   447,   448,   448,   449,   449,   449,
     449,   450,   451,   453,   452,   454,   454,   455,   455,   455,
     456,   457,   458,   459,   459,   460,   460,   461,   463,   462,
     465,   464,   466,   466,   467,   468,   468,   469,   469,   469,
     469,   470,   471,   472,   473,   473,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     474,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     502,   503,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   515,   516,   517,   518,   519,   520,
     521,   522,   523,   525,   524,   526,   526,   527,   527,   527,
     527,   527,   527,   527,   527,   527,   527,   527,   527,   527,
     527,   527,   527,   527,   527,   527,   529,   528,   530,   530,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   531,
     531,   531,   531,   531,   531,   531,   531,   531,   531,   532,
     533,   534,   535,   537,   536,   538,   538,   539,   539,   539,
     539,   539,   539,   539,   540,   541,   543,   542,   544,   544,
     545,   545,   546,   547,   549,   548,   550,   550,   551,   551,
     552,   553,   553,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   574,   575,   575,   575,   575,   575,   575,   575,
     575,   576,   577,   578,   579,   580,   581,   582
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       0,     5,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     0,     5,     3,     1,
       1,     1,     4,     4,     0,     5,     3,     1,     1,     1,
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
       2,     0,     1,     0,     0,     0,   194,   349,   413,     0,
     428,     0,   603,   252,   398,   228,     0,     0,   125,   290,
       0,     0,   301,   326,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   196,
     351,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,    84,    86,    85,   651,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   632,   650,   645,   633,
     634,   635,   636,   638,   639,   640,   641,   637,   642,   643,
     644,   646,   647,   648,   649,   215,     0,   197,   371,     0,
     352,     0,   426,     0,     0,   424,   425,     0,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576,     0,   553,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   445,   500,   495,   496,   493,
     497,   498,   494,   456,   446,   447,   485,   448,   449,   450,
     451,   452,   453,   454,   455,   490,   457,   458,   459,   460,
     499,   462,   467,   463,   465,   464,   479,   480,   466,   468,
     469,   470,   471,   473,   472,   461,   475,   484,   486,   487,
     476,   477,   491,   492,   489,   478,   474,   482,   483,   481,
     488,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
      94,    95,    98,   105,    99,   103,   100,   101,   104,   102,
      96,    97,     0,     0,     0,     0,    42,    43,    44,   141,
       0,   128,     0,   680,     0,     0,     0,     0,     0,     0,
       0,     0,   672,   673,   674,   678,   675,   677,   676,   679,
       0,     0,     0,     0,     0,     0,     0,     0,    64,     0,
       0,     0,     0,     0,    50,    62,    61,    58,    51,    60,
      54,    55,    56,    52,    59,    57,    53,     0,     0,    87,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   631,     0,     0,   419,     0,     0,
       0,   416,   417,   418,     0,     0,   423,   440,     0,     0,
     430,   439,     0,   436,   437,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   444,   613,   624,     0,     0,   616,     0,     0,
       0,   606,   607,   608,   609,   610,   611,   612,     0,     0,
       0,   269,     0,     0,     0,     0,     0,     0,   255,   256,
     257,   258,   263,   259,   260,   261,   262,   410,     0,   400,
       0,   409,     0,   406,   407,   408,     0,   230,     0,     0,
       0,   240,     0,   238,   239,   241,   242,   106,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    92,    45,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,   293,   294,   295,   296,     0,     0,     0,
       0,     0,     0,     0,     0,   671,    63,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      49,     0,     0,   311,     0,     0,   304,   305,   306,   307,
       0,     0,   334,     0,   329,   330,   331,     0,     0,     0,
      81,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   199,   200,   203,   204,
     206,   207,   208,   209,   210,   211,   212,   201,   202,   205,
       0,     0,     0,     0,     0,     0,   379,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   354,   355,   356,   357,
     358,   359,   361,   360,   362,   367,   366,   363,   364,   365,
     368,     0,     0,     0,   415,     0,   422,     0,     0,     0,
       0,   435,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
     443,     0,     0,     0,     0,     0,     0,     0,   605,   264,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   254,
       0,     0,     0,     0,   405,   243,     0,     0,     0,     0,
       0,   237,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      91,     0,     0,    40,     0,     0,     0,   170,     0,     0,
       0,   147,     0,     0,   130,   131,   132,   133,   136,   137,
     135,   134,   138,   297,     0,     0,     0,     0,   292,     0,
       0,     0,     0,     0,     0,     0,   670,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
     308,     0,     0,     0,     0,   303,   332,     0,     0,     0,
     328,    90,    89,    88,   667,   664,   663,   652,   654,    26,
      26,    26,    26,    26,    28,    27,   658,   659,   662,   660,
     665,   666,   668,   669,   661,   653,   655,   656,   657,   213,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   198,   369,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   353,     0,     0,   414,   427,     0,     0,     0,   429,
     514,   518,   505,   534,   547,   546,   601,   551,   512,   543,
     549,   513,   503,   504,   521,   510,   542,   511,   524,   509,
     523,   522,   517,   516,   515,   544,   502,   541,   599,   600,
     538,   535,   580,   596,   597,   581,   582,   583,   584,   591,
     585,   594,   598,   587,   592,   588,   593,   586,   590,   589,
     595,     0,   579,   540,   557,   573,   574,   558,   559,   560,
     561,   568,   562,   571,   575,   564,   569,   565,   570,   563,
     567,   566,   572,     0,   556,   533,   536,   550,   507,   545,
     508,   537,   526,   531,   532,   529,   530,   527,   528,   520,
     519,    34,    34,    34,    36,    35,   602,   552,   539,   548,
     506,   525,     0,     0,     0,     0,     0,     0,   604,     0,
       0,   275,     0,     0,     0,     0,     0,   253,     0,     0,
       0,   399,     0,     0,     0,   248,   244,   247,   229,   110,
     116,   114,   113,   115,   111,   112,   109,   117,   123,   118,
     122,   120,   121,   119,   108,   107,   124,    46,    47,   139,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   129,
       0,     0,     0,   291,   686,   681,   685,   683,   687,   682,
     684,    74,    80,    72,    76,    75,    71,    70,    68,    69,
       0,    67,    73,    79,    77,    78,     0,     0,     0,   302,
       0,     0,   327,    29,    30,    31,    32,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   195,     0,     0,     0,     0,     0,     0,   385,     0,
       0,     0,     0,     0,     0,     0,     0,   350,   420,   421,
     441,   442,   434,     0,   433,   577,     0,   554,     0,    37,
      38,    39,   629,   628,     0,   627,   615,   614,   621,   620,
       0,   619,   623,   622,   267,   268,   273,     0,   272,     0,
     266,   289,   288,   287,   265,   412,   404,     0,   403,   411,
     235,   236,   234,     0,   233,   251,   250,     0,     0,     0,
       0,     0,   176,     0,     0,     0,     0,     0,   126,   299,
     300,   298,    65,     0,   309,   315,   321,   325,   324,   323,
     320,   316,   319,   322,   317,   318,     0,   314,   310,   333,
     338,   344,   348,   347,   346,   343,   339,   342,   345,   340,
     341,     0,   337,   225,   226,   219,   221,   223,   222,   220,
     214,   227,   218,   216,   217,   224,   375,   377,   378,   397,
     396,   393,   383,     0,   382,     0,   372,   394,   395,   370,
     376,   392,   374,   373,   431,     0,   578,   555,   625,     0,
     617,     0,     0,   270,   275,   281,   282,   278,   284,   280,
     279,   286,   283,   285,   277,   276,   401,     0,   231,     0,
     249,   246,   245,   146,   144,   174,     0,   173,     0,   140,
     143,   145,   151,   167,   168,   152,   153,   154,   155,   162,
     156,   165,   169,   158,   163,   159,   164,   157,   161,   160,
     166,     0,   150,   142,    66,   312,     0,   335,     0,     0,
     380,   385,   389,   390,   387,   388,   391,   386,   432,   626,
     618,   274,   271,   402,   232,     0,   171,   176,   186,   184,
     193,   183,   178,   187,   191,   180,   188,   190,   185,   179,
     192,   189,   181,   182,   177,   148,     0,   313,   336,   384,
     381,   175,   172,   149
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
     778,   779,   780,   781,  1046,  1301,  1302,   782,  1042,  1276,
    1277,  1325,  1278,  1344,    30,    49,   116,   595,   596,   597,
     117,   598,   599,   600,   601,   602,   603,   604,   605,   606,
     607,   608,   609,    31,    58,   481,   736,  1163,  1164,   482,
     483,   484,  1169,  1016,  1017,   485,   486,    32,    56,   457,
     458,   459,   460,   461,   462,   463,   722,  1147,  1148,  1252,
    1149,  1265,   464,   465,   466,    33,    62,   512,   513,   514,
     515,   516,    34,    65,   545,   546,   547,   548,   549,   812,
    1196,  1197,    35,    66,   553,   554,   555,   556,   818,  1211,
    1212,    36,    50,   119,   625,   626,   627,   120,   628,   629,
     630,   631,   632,   633,   634,   871,  1233,  1234,  1309,  1235,
    1317,   635,   636,   637,   638,   639,   640,    37,    57,   471,
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
#define YYPACT_NINF -949
static const yytype_int16 yypact[] =
{
    -949,   670,  -949,  -256,  -248,  -245,  -949,  -949,  -949,  -212,
    -949,  -205,  -949,  -949,  -949,  -949,  -189,  -183,  -949,  -949,
    -154,  -152,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,    22,   642,  -127,
     -31,  -132,     5,  -125,   415,  -119,   -98,   -89,   -86,   578,
      14,    -8,   -75,   664,   313,   -74,   -61,   -45,   -46,   -37,
     -23,    31,  -949,  -949,  -949,  -949,  -949,   -22,    15,    30,
      33,    41,    42,    47,    48,    50,    61,    62,    70,    78,
      79,    80,    86,    90,    93,    94,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,   -44,  -949,  -949,    89,
    -949,    20,  -949,    99,     2,  -949,  -949,   140,  -949,   100,
     104,   106,   111,   113,   115,   122,   123,   126,   127,   128,
     129,   131,   133,   135,   136,   137,   145,   147,   148,   151,
     155,   156,   157,   159,   163,   165,   167,   169,   174,   175,
     177,  -949,   178,  -949,   186,   187,   188,   193,   194,   197,
     199,   200,   205,   206,   209,   210,   211,   212,   213,   214,
     219,   220,   225,   228,    10,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,   364,   308,    92,   318,    17,   229,   230,   231,   232,
     236,   237,   241,   242,   244,   245,   248,   250,   226,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,    63,   251,   252,    60,  -949,  -949,  -949,  -949,
     182,  -949,    24,  -949,   253,   254,   255,   260,   270,   271,
     272,   192,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
      72,   273,   274,   275,   276,   279,   281,   282,  -949,   285,
     286,   287,   288,   132,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   183,   102,  -949,
     222,   293,   336,   299,  -949,   198,   431,   432,   368,   369,
     436,   436,   440,   441,   376,   379,   446,   436,   381,   390,
     391,   392,   393,   332,  -949,   726,   521,  -949,   330,   331,
      76,  -949,  -949,  -949,   442,   338,  -949,  -949,   333,   337,
    -949,  -949,    57,  -949,  -949,  -949,   404,   436,   408,   436,
     482,   461,   486,   423,   424,   491,   470,   429,   496,   497,
     498,   434,   436,   445,   447,   436,   493,   450,   517,   518,
     436,   522,   523,   499,   526,   528,   463,   464,   400,   469,
     405,   436,   436,   475,   436,   514,   488,   489,   492,  -131,
    -110,   494,   501,   436,   436,   548,   436,   504,   505,   506,
     510,   428,  -949,  -949,  -949,   420,   427,  -949,   430,   448,
     112,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   435,   454,
     457,  -949,   459,   462,   465,   466,   467,   118,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   468,  -949,
     472,  -949,    74,  -949,  -949,  -949,   449,  -949,   474,   483,
     490,  -949,    29,  -949,  -949,  -949,  -949,  -949,   555,   557,
     560,   571,   573,   579,   599,   601,   360,   602,   604,   561,
     502,  -949,  -949,   608,   611,   507,  -949,   305,   511,   503,
     512,   515,   152,  -949,  -949,  -949,  -949,   568,   577,   580,
     626,   583,   584,   436,   524,  -949,  -949,   634,   586,   637,
     638,   639,   640,   641,   532,   646,   672,   648,   651,   547,
    -949,   551,   549,  -949,   550,    69,  -949,  -949,  -949,  -949,
     558,   556,  -949,    75,  -949,  -949,  -949,   562,   563,   564,
    -949,   565,   566,   569,   572,   576,   207,   582,   587,   588,
     589,   592,   593,   594,   597,   598,   603,   607,   609,   610,
    -949,   615,   574,   581,   605,   616,   617,   618,   619,   620,
     622,   623,   624,   625,   628,   116,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     629,   632,   645,   649,   650,   652,  -949,   653,   654,   655,
     656,   660,   665,   667,   668,   160,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,   675,   686,   678,  -949,   681,  -949,   687,   690,   682,
     688,  -949,   689,   691,   693,   694,   695,   696,   700,   704,
     705,   707,   708,   715,   718,   722,   723,   725,   727,   728,
     730,   731,   732,   733,   737,   741,   742,   744,   745,   747,
     748,   749,   750,   751,   692,   752,   729,   753,   754,   755,
     756,   757,   758,   759,   760,   761,   762,   763,   764,   765,
     767,   768,   769,    49,   770,   771,   772,   773,   774,   775,
    -949,   683,   436,   712,   776,   709,   711,   777,  -949,  -949,
     797,   714,   778,   799,   783,   833,   836,   873,   780,  -949,
     883,   779,   885,   784,  -949,  -949,   782,   890,   893,   796,
     787,  -949,   788,   789,   790,   791,   792,   793,   794,   795,
     798,   800,   801,   802,   803,   804,   805,   806,   807,   808,
    -949,   809,   810,  -949,   811,   812,   813,  -949,   814,   815,
     816,  -949,   817,   181,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,   903,   904,   906,   821,  -949,   822,
     823,   824,   825,   826,   827,   828,  -949,   829,   830,   831,
     832,   834,   835,   837,   -80,   838,   839,   840,   841,  -949,
    -949,   919,   842,   920,   843,  -949,  -949,   921,   844,   846,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   436,
     436,   436,   436,   436,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     962,   965,   436,   971,   973,   977,   978,   957,   980,   981,
     436,   436,   548,   853,  -949,  -949,   961,  -117,   963,   964,
     918,   855,   966,   967,   968,   969,   992,   972,   974,   975,
     864,  -949,   866,   869,  -949,  -949,   870,   871,   662,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -244,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -236,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,   548,   548,   548,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,    -3,   872,   874,    -2,   875,   876,  -949,   877,
     878,  1003,   879,   880,   881,   882,   884,  -949,   886,   703,
     887,  -949,   -63,   888,   889,   676,   891,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     990,   948,   894,   997,   998,   999,   895,  1000,   896,  -949,
     899,   900,   901,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -224,  -949,  -949,  -949,  -949,  -949,   902,   570,   905,  -949,
     907,   627,  -949,  -949,  -949,  -949,  -949,  -949,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   922,   923,
     924,  -949,   925,   926,   927,   928,   929,   930,  1024,   931,
     932,   933,   934,   935,   936,   937,   938,  -949,  -949,  -949,
    -949,  -949,  -949,  -219,  -949,  -949,   692,  -949,   729,  -949,
    -949,  -949,  -949,  -949,  -216,  -949,  -949,  -949,  -949,  -949,
    -213,  -949,  -949,  -949,  -949,  -949,  -949,  -158,  -949,   630,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -149,  -949,  -949,
    -949,  -949,  -949,  -129,  -949,  -949,  -949,  1032,   796,   939,
     940,   941,  1034,   942,   943,   944,   766,   945,  -949,  -949,
    -949,  -949,  -949,   -80,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -106,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,   -25,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,    38,  -949,     0,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,   662,  -949,  -949,  -949,    -3,
    -949,    -2,   630,  -949,  1003,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   703,  -949,   -63,
    -949,  -949,  -949,  -949,  -949,  -949,    56,  -949,   553,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,    88,  -949,  -949,  -949,  -949,   570,  -949,   627,     0,
    -949,  1024,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,   553,  -949,  1034,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,   766,  -949,  -949,  -949,
    -949,  -949,  -949,  -949
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -949,  -949,  -949,  -427,  -340,  -948,  -423,  -949,  -949,   946,
    -949,  -949,  -949,  -949,   865,  -949,  -949,  -949,  -293,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  1095,  -949,  -949,  -949,  -949,  -949,   643,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,   406,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -166,  -949,  -949,  -949,
    -146,  -949,  -949,  -118,  -949,  -949,  -949,  -949,   613,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   -60,  -949,
     724,  -949,  -949,  -949,    43,  -949,  -949,  -949,  -949,  -949,
     781,  -949,  -949,  -949,  -949,  -949,  -949,  -949,   -42,  -949,
    -949,   -39,  -949,  -949,  -949,  -949,  -949,  -949,   698,  -949,
    -949,  -949,  -949,  -949,  -949,   669,  -949,  -949,  -949,  -949,
    -949,   -91,  -949,  -949,  -949,   663,  -949,  -949,  -949,  -949,
     -90,  -949,  -949,  -949,  -949,   595,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,   -94,  -949,  -949,
     -87,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,   -48,  -949,   785,  -949,  -949,  -949,  -949,  -949,
     863,  -949,  -949,  -949,  -949,  1100,  -949,  -949,  -949,  -949,
    -949,  -949,   -20,  -949,   854,  -949,  -949,  -949,  -949,  1043,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,   101,  -949,  -949,  -949,   105,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,   818,  -949,  -949,  -949,  -949,  -949,
     -21,  -949,  -949,  -949,  -949,  -949,   -17,  -949,  -949,  1133,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
    -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,  -949,
     949,  -949,  -949,  -949,  -949,  -949,  -949,  -949
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     567,   568,   704,   122,    45,    46,   122,   574,  1132,  1138,
    1312,   128,  1313,  1160,    47,   272,  1125,    48,   129,   130,
    1126,   357,   131,    67,  1127,   508,   115,  1314,  1128,   132,
     476,  1315,    67,  1129,  1130,  1131,  1182,   653,   133,   655,
    1183,  1244,   134,   135,  1248,  1245,   509,  1250,  1249,   136,
      52,  1251,   668,   137,   138,   671,   139,    54,   367,    68,
     676,   272,   140,   981,   982,   983,   695,   696,    68,    69,
     541,   687,   688,    59,   690,   467,   550,   357,    69,    60,
     141,   142,   477,   701,   702,   143,   705,   697,   698,  1068,
    1069,   123,   144,   467,   123,    76,   145,   146,   147,  1103,
    1104,   148,  1253,   550,   149,   150,  1254,    77,    63,   358,
      64,  1266,   478,   433,   151,  1267,   434,   581,   479,   448,
     152,   153,   118,   154,   155,   156,   157,   158,    78,    79,
     121,  1268,   273,   300,    80,  1269,    81,   127,   159,   582,
     583,   367,    70,   241,   449,   279,   584,   160,   510,   161,
     162,    70,   163,   508,  1305,   164,   165,   435,  1306,   166,
     436,   610,   274,   611,   242,   358,   612,   450,  1161,   301,
     167,   451,  1162,   243,   509,   359,   244,   368,   273,   511,
     703,   480,   764,   795,   541,   613,   614,   282,   327,   542,
      82,    83,   168,   283,   169,   551,  1133,  1139,   170,    84,
      85,   328,   171,   172,   173,   174,   175,   765,   274,   615,
     176,   177,   369,   616,   437,   329,   302,   330,   355,   178,
      86,    87,   551,   585,   586,   587,   331,   245,   588,   468,
     766,   359,   438,   284,   767,  1307,   589,    88,    89,  1308,
     332,   335,  1316,   617,   370,   618,   285,   468,    90,   590,
     591,   179,   303,   180,   304,   305,   543,    91,   619,   181,
     368,   469,   552,   365,   182,   452,   592,   593,   286,   183,
     287,   431,   288,   289,   453,   454,   510,   487,   336,   469,
     620,   246,   247,   248,   249,   250,   251,   252,   253,   552,
     740,   290,   333,   337,   594,   369,   338,   306,  1310,   307,
     308,   768,  1311,   542,   339,   340,   764,   511,   455,   448,
     341,   342,   621,   343,   300,   309,  1326,   544,   650,   476,
    1327,   505,   470,   502,   344,   345,   622,   370,   769,   254,
     814,   765,   526,   346,   449,   733,   819,   643,   566,   623,
     470,   347,   348,   349,    92,    93,    94,   770,  1345,   350,
     301,   356,  1346,   351,   766,   353,   352,   450,   767,   310,
     439,   451,   364,   376,   255,   433,   456,   377,   434,   378,
     543,   477,   993,   717,   379,   557,   380,   863,   381,   728,
     829,   830,   831,   832,   833,   382,   383,   311,   312,   384,
     385,   386,   387,   539,   388,   561,   389,   302,   390,   391,
     392,   478,  1083,  1084,  1085,  1086,  1087,   479,   393,   435,
     394,   395,   436,   787,   396,   624,   128,   771,   397,   398,
     399,   880,   400,   129,   130,   768,   401,   131,   402,   772,
     403,   544,   404,   303,   132,   304,   305,   405,   406,  1100,
     407,   409,  1048,   133,   507,   256,   558,   134,   135,   411,
     412,   413,   769,   524,   136,   452,   414,   415,   137,   138,
     416,   139,   417,   418,   453,   454,   437,   140,   419,   420,
     480,   770,   421,   422,   423,   424,   425,   426,   306,   257,
     307,   308,   427,   428,   438,   141,   142,   500,   429,   559,
     143,   430,   488,   489,   490,   491,   309,   144,   455,   492,
     493,   145,   146,   147,   494,   495,   148,   496,   497,   149,
     150,   498,  1090,   499,   503,   504,   517,   518,   519,   151,
    1098,  1099,   610,   520,   611,   152,   153,   612,   154,   155,
     156,   157,   158,   521,   522,   523,   527,   528,   529,   530,
     310,   771,   531,   159,   532,   533,   613,   614,   535,   536,
     537,   538,   160,   772,   161,   162,   456,   163,  1328,   560,
     164,   165,   562,   563,   166,   564,   565,   566,   311,   312,
     615,   569,   570,   571,   616,   167,   572,   573,   575,   245,
     750,   751,   752,   753,   754,   755,   756,   576,   577,   578,
     579,  1329,   580,   641,   642,   645,   647,   168,   646,   169,
     648,   652,  1330,   170,   617,   654,   618,   171,   172,   173,
     174,   175,   439,   656,   657,   176,   177,   658,  1331,   619,
     659,   660,   661,   662,   178,  1332,   663,   664,   665,   666,
    1333,   667,  1334,   246,   247,   248,   249,   250,   251,   252,
     253,   620,   669,    76,   670,  1335,   672,   673,   674,   675,
    1255,  1256,   679,   677,   678,    77,   179,   680,   180,   681,
     682,   683,  1185,   684,   181,   283,   685,   691,   686,   182,
       2,     3,   689,   621,   183,     4,    78,    79,  1336,   703,
    1257,   254,    80,   712,    81,   692,   693,   622,   710,   694,
     713,   699,     5,   715,  1337,   719,     6,  1258,   700,     7,
     623,   706,   707,   708,  1259,   284,     8,   709,   742,   735,
     743,   716,  1338,   744,  1339,  1340,   255,   720,   285,  1200,
     721,     9,   723,  1260,   745,   724,   746,   581,   725,   726,
     727,   730,   747,    10,    11,   732,    12,   737,    82,    83,
     286,  1186,   287,    13,   288,   289,   738,    84,    85,   582,
     583,  1261,   748,   739,   749,   757,   584,   758,   759,  1262,
      14,   761,   760,   290,   762,   789,   784,   763,    86,    87,
      15,   783,    16,  1187,   790,   785,   624,   791,   786,   792,
     793,   794,  1341,   798,   796,    88,    89,   797,  1188,    17,
     799,   800,   801,   802,   803,   804,    90,   256,  1201,   805,
    1342,   807,  1263,   806,   808,    91,    18,   809,  1189,  1190,
    1343,   810,   811,   813,  1191,  1192,  1193,  1194,   816,   817,
    1122,  1264,   821,   822,   823,   824,   825,  1195,   882,   826,
    1202,   257,   827,   585,   586,   587,   828,   850,   588,   883,
     886,    19,   836,   887,   851,  1203,   589,   837,   838,   839,
      20,    21,   840,   841,   842,    22,    23,   843,   844,   590,
     591,  1156,   996,   845,   997,  1204,  1205,   846,   852,   847,
     848,  1206,  1207,  1208,  1209,   849,   592,   593,  1167,   853,
     854,   855,   856,   857,  1210,   858,   859,   860,   861,   865,
    1304,   862,    92,    93,    94,   866,   922,   923,   924,   925,
     926,   501,   927,   928,   594,   929,   930,   931,   867,   994,
     932,  1000,   868,   869,  1003,   870,   872,   873,   874,   875,
     933,   934,   935,   876,   936,   937,   938,  1015,   877,   939,
     878,   879,   940,   944,   945,   946,   947,   948,   884,   949,
     950,   885,   951,   952,   953,   888,   992,   954,   889,   890,
     999,   891,  1002,   892,   893,   894,   895,   955,   956,   957,
     896,   958,   959,   960,   897,   898,   961,   899,   900,   962,
    1282,  1283,  1284,  1285,  1286,   901,  1287,  1288,   902,  1289,
    1290,  1291,   903,   904,  1292,   905,  1004,   906,   907,  1005,
     908,   909,   910,   911,  1293,  1294,  1295,   912,  1296,  1297,
    1298,   913,   914,  1299,   915,   916,  1300,   917,   918,   919,
     920,   921,   943,   965,   966,   967,   968,   969,   970,   971,
     972,   973,   974,   975,   976,   977,  1006,   978,   979,   980,
     986,   987,   988,   989,   990,   991,  1008,   998,  1010,   995,
    1007,  1001,  1009,  1013,  1011,  1012,  1014,  1018,  1019,  1020,
    1021,  1022,  1023,  1024,  1025,  1026,  1050,  1051,  1027,  1052,
    1028,  1029,  1030,  1031,  1032,  1033,  1034,  1035,  1036,  1037,
    1038,  1039,  1076,  1078,  1080,  1040,  1041,  1043,  1044,  1045,
    1047,  1053,  1054,  1055,  1056,  1057,  1058,  1059,  1060,  1061,
    1062,  1063,  1064,  1088,  1065,  1066,  1089,  1067,  1072,  1073,
    1074,  1075,  1091,  1079,  1092,  1077,  1082,  1081,  1093,  1094,
    1095,  1096,  1097,  1101,  1102,  1107,  1105,  1106,  1108,  1109,
    1110,  1111,  1112,  1113,  1117,  1114,  1118,  1115,  1116,  1119,
    1120,  1121,  1136,  1146,  1137,  1142,  1143,  1144,  1145,  1150,
    1151,  1152,  1153,  1170,  1154,  1171,  1155,  1159,  1165,  1166,
    1173,  1174,  1175,  1177,  1232,  1168,  1178,  1172,  1176,  1179,
    1180,  1181,  1184,  1270,  1275,  1198,   334,  1199,  1213,  1214,
    1215,  1216,  1217,  1218,  1219,  1220,  1221,  1222,   540,  1049,
    1353,  1352,  1223,  1224,  1225,  1226,  1227,  1228,  1229,  1230,
    1231,  1236,  1237,  1238,  1239,  1240,  1241,  1242,  1243,  1272,
    1273,  1274,  1279,  1280,  1281,  1303,   741,  1351,   864,  1324,
     788,  1271,  1322,  1321,   815,  1347,   820,  1350,  1348,  1323,
     881,   506,  1349,   644,   366,  1318,   651,   432,   354,  1247,
    1320,  1246,  1319,     0,     0,     0,     0,     0,   729,     0,
     525,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   734,   718
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-949))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     340,   341,   425,     1,   260,   261,     1,   347,    11,    11,
      10,     1,    12,    76,   262,     1,   260,   262,     8,     9,
     264,     1,    12,     1,   260,     1,   153,    27,   264,    19,
       1,    31,     1,   981,   982,   983,   260,   377,    28,   379,
     264,   260,    32,    33,   260,   264,    22,   260,   264,    39,
     262,   264,   392,    43,    44,   395,    46,   262,     1,    37,
     400,     1,    52,    14,    15,    16,   197,   198,    37,    47,
       1,   411,   412,   262,   414,     1,     1,     1,    47,   262,
      70,    71,    53,   423,   424,    75,   426,   197,   198,   169,
     170,    89,    82,     1,    89,     1,    86,    87,    88,   216,
     217,    91,   260,     1,    94,    95,   264,    13,   262,    89,
     262,   260,    83,     1,   104,   264,     4,     1,    89,     1,
     110,   111,   153,   113,   114,   115,   116,   117,    34,    35,
     262,   260,   118,     1,    40,   264,    42,   262,   128,    23,
      24,     1,   120,   262,    26,   153,    30,   137,   124,   139,
     140,   120,   142,     1,   260,   145,   146,    45,   264,   149,
      48,     1,   148,     3,   262,    89,     6,    49,   231,    37,
     160,    53,   235,   262,    22,   155,   262,   120,   118,   155,
     131,   152,     1,   523,     1,    25,    26,   262,   262,   120,
      96,    97,   182,     1,   184,   120,   199,   199,   188,   105,
     106,   262,   192,   193,   194,   195,   196,    26,   148,    49,
     200,   201,   155,    53,   102,   260,    84,   263,   262,   209,
     126,   127,   120,   107,   108,   109,   263,     1,   112,   155,
      49,   155,   120,    41,    53,   260,   120,   143,   144,   264,
     263,   263,   242,    83,   187,    85,    54,   155,   154,   133,
     134,   241,   120,   243,   122,   123,   187,   163,    98,   249,
     120,   187,   187,   261,   254,   147,   150,   151,    76,   259,
      78,   261,    80,    81,   156,   157,   124,   260,   263,   187,
     120,    55,    56,    57,    58,    59,    60,    61,    62,   187,
     261,    99,   261,   263,   178,   155,   263,   165,   260,   167,
     168,   120,   264,   120,   263,   263,     1,   155,   190,     1,
     263,   263,   152,   263,     1,   183,   260,   248,   261,     1,
     264,   261,   248,   260,   263,   263,   166,   187,   147,   103,
     261,    26,   260,   263,    26,   261,   261,   261,   131,   179,
     248,   263,   263,   263,   250,   251,   252,   166,   260,   263,
      37,   262,   264,   263,    49,   261,   263,    49,    53,   227,
     248,    53,   263,   263,   138,     1,   248,   263,     4,   263,
     187,    53,   712,   261,   263,   153,   263,   261,   263,   261,
     173,   174,   175,   176,   177,   263,   263,   255,   256,   263,
     263,   263,   263,   261,   263,   197,   263,    84,   263,   263,
     263,    83,   829,   830,   831,   832,   833,    89,   263,    45,
     263,   263,    48,   261,   263,   255,     1,   236,   263,   263,
     263,   261,   263,     8,     9,   120,   263,    12,   263,   248,
     263,   248,   263,   120,    19,   122,   123,   263,   263,   862,
     263,   263,   261,    28,   262,   219,   153,    32,    33,   263,
     263,   263,   147,   261,    39,   147,   263,   263,    43,    44,
     263,    46,   263,   263,   156,   157,   102,    52,   263,   263,
     152,   166,   263,   263,   263,   263,   263,   263,   165,   253,
     167,   168,   263,   263,   120,    70,    71,   261,   263,   153,
      75,   263,   263,   263,   263,   263,   183,    82,   190,   263,
     263,    86,    87,    88,   263,   263,    91,   263,   263,    94,
      95,   263,   852,   263,   263,   263,   263,   263,   263,   104,
     860,   861,     1,   263,     3,   110,   111,     6,   113,   114,
     115,   116,   117,   263,   263,   263,   263,   263,   263,   263,
     227,   236,   263,   128,   263,   263,    25,    26,   263,   263,
     263,   263,   137,   248,   139,   140,   248,   142,     5,   260,
     145,   146,   131,   131,   149,   197,   197,   131,   255,   256,
      49,   131,   131,   197,    53,   160,   197,   131,   197,     1,
     220,   221,   222,   223,   224,   225,   226,   197,   197,   197,
     197,    38,   260,   263,   263,   153,   263,   182,   260,   184,
     263,   197,    49,   188,    83,   197,    85,   192,   193,   194,
     195,   196,   248,   131,   153,   200,   201,   131,    65,    98,
     197,   197,   131,   153,   209,    72,   197,   131,   131,   131,
      77,   197,    79,    55,    56,    57,    58,    59,    60,    61,
      62,   120,   197,     1,   197,    92,   153,   197,   131,   131,
      20,    21,   153,   131,   131,    13,   241,   131,   243,   131,
     197,   197,    92,   263,   249,     1,   197,   153,   263,   254,
       0,     1,   197,   152,   259,     5,    34,    35,   125,   131,
      50,   103,    40,   263,    42,   197,   197,   166,   260,   197,
     263,   197,    22,   263,   141,   260,    26,    67,   197,    29,
     179,   197,   197,   197,    74,    41,    36,   197,   153,   260,
     153,   263,   159,   153,   161,   162,   138,   263,    54,    92,
     263,    51,   263,    93,   153,   263,   153,     1,   263,   263,
     263,   263,   153,    63,    64,   263,    66,   263,    96,    97,
      76,   171,    78,    73,    80,    81,   263,   105,   106,    23,
      24,   121,   153,   263,   153,   153,    30,   153,   197,   129,
      90,   153,   260,    99,   153,   197,   263,   260,   126,   127,
     100,   260,   102,   203,   197,   263,   255,   197,   263,   153,
     197,   197,   229,   197,   260,   143,   144,   153,   218,   119,
     153,   153,   153,   153,   153,   263,   154,   219,   171,   153,
     247,   153,   172,   131,   153,   163,   136,   260,   238,   239,
     257,   260,   263,   263,   244,   245,   246,   247,   260,   263,
     158,   191,   260,   260,   260,   260,   260,   257,   153,   260,
     203,   253,   260,   107,   108,   109,   260,   263,   112,   153,
     153,   171,   260,   153,   263,   218,   120,   260,   260,   260,
     180,   181,   260,   260,   260,   185,   186,   260,   260,   133,
     134,   158,   153,   260,   153,   238,   239,   260,   263,   260,
     260,   244,   245,   246,   247,   260,   150,   151,   202,   263,
     263,   263,   263,   263,   257,   263,   263,   263,   263,   260,
    1183,   263,   250,   251,   252,   263,   204,   205,   206,   207,
     208,   258,   210,   211,   178,   213,   214,   215,   263,   197,
     218,   197,   263,   263,   131,   263,   263,   263,   263,   263,
     228,   229,   230,   263,   232,   233,   234,   131,   263,   237,
     263,   263,   240,   204,   205,   206,   207,   208,   260,   210,
     211,   260,   213,   214,   215,   263,   263,   218,   260,   260,
     153,   260,   153,   260,   260,   260,   260,   228,   229,   230,
     260,   232,   233,   234,   260,   260,   237,   260,   260,   240,
     204,   205,   206,   207,   208,   260,   210,   211,   260,   213,
     214,   215,   260,   260,   218,   260,   153,   260,   260,   153,
     260,   260,   260,   260,   228,   229,   230,   260,   232,   233,
     234,   260,   260,   237,   260,   260,   240,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   153,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   153,   260,   153,   263,
     260,   263,   263,   153,   260,   263,   153,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   153,   153,   260,   153,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   153,   153,   153,   263,   263,   263,   263,   263,
     263,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   131,   260,   260,   131,   260,   260,   260,
     260,   260,   131,   260,   131,   263,   260,   263,   131,   131,
     153,   131,   131,   260,   153,   197,   153,   153,   263,   153,
     153,   153,   153,   131,   260,   153,   260,   153,   153,   260,
     260,   260,   260,   130,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   153,   260,   197,   260,   260,   260,   260,
     153,   153,   153,   153,   130,   264,   260,   263,   263,   260,
     260,   260,   260,   131,   130,   260,    71,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   313,   773,
    1346,  1327,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   482,  1325,   595,  1269,
     512,  1168,  1254,  1252,   545,  1306,   553,  1311,  1308,  1267,
     625,   275,  1309,   360,   124,  1245,   372,   184,    95,  1128,
    1251,  1126,  1249,    -1,    -1,    -1,    -1,    -1,   457,    -1,
     291,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   472,   440
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   266,     0,     1,     5,    22,    26,    29,    36,    51,
      63,    64,    66,    73,    90,   100,   102,   119,   136,   171,
     180,   181,   185,   186,   267,   272,   277,   295,   301,   316,
     339,   358,   372,   390,   397,   407,   416,   442,   452,   458,
     462,   472,   536,   552,   573,   260,   261,   262,   262,   340,
     417,   453,   262,   463,   262,   537,   373,   443,   359,   262,
     262,   317,   391,   262,   262,   398,   408,     1,    37,    47,
     120,   296,   297,   298,   299,   300,     1,    13,    34,    35,
      40,    42,    96,    97,   105,   106,   126,   127,   143,   144,
     154,   163,   250,   251,   252,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     568,   569,   570,   571,   572,   153,   341,   345,   153,   418,
     422,   262,     1,    89,   459,   460,   461,   262,     1,     8,
       9,    12,    19,    28,    32,    33,    39,    43,    44,    46,
      52,    70,    71,    75,    82,    86,    87,    88,    91,    94,
      95,   104,   110,   111,   113,   114,   115,   116,   117,   128,
     137,   139,   140,   142,   145,   146,   149,   160,   182,   184,
     188,   192,   193,   194,   195,   196,   200,   201,   209,   241,
     243,   249,   254,   259,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   492,   493,   494,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   528,   532,   533,   534,
     535,   262,   262,   262,   262,     1,    55,    56,    57,    58,
      59,    60,    61,    62,   103,   138,   219,   253,   302,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,   315,     1,   118,   148,   273,   274,   275,   276,   153,
     318,   322,   262,     1,    41,    54,    76,    78,    80,    81,
      99,   574,   575,   576,   577,   578,   579,   580,   581,   582,
       1,    37,    84,   120,   122,   123,   165,   167,   168,   183,
     227,   255,   256,   278,   279,   280,   284,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   294,   262,   262,   260,
     263,   263,   263,   261,   297,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   261,   554,   262,   262,     1,    89,   155,
     454,   455,   456,   457,   263,   261,   460,     1,   120,   155,
     187,   464,   468,   469,   470,   471,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   529,   263,
     525,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   261,   474,     1,     4,    45,    48,   102,   120,   248,
     538,   539,   540,   541,   542,   546,   547,   548,     1,    26,
      49,    53,   147,   156,   157,   190,   248,   374,   375,   376,
     377,   378,   379,   380,   387,   388,   389,     1,   155,   187,
     248,   444,   448,   449,   450,   451,     1,    53,    83,    89,
     152,   360,   364,   365,   366,   370,   371,   260,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     261,   303,   260,   263,   263,   261,   274,   262,     1,    22,
     124,   155,   392,   393,   394,   395,   396,   263,   263,   263,
     263,   263,   263,   263,   261,   575,   260,   263,   263,   263,
     263,   263,   263,   263,   281,   263,   263,   263,   263,   261,
     279,     1,   120,   187,   248,   399,   400,   401,   402,   403,
       1,   120,   187,   409,   410,   411,   412,   153,   153,   153,
     260,   197,   131,   131,   197,   197,   131,   269,   269,   131,
     131,   197,   197,   131,   269,   197,   197,   197,   197,   197,
     260,     1,    23,    24,    30,   107,   108,   109,   112,   120,
     133,   134,   150,   151,   178,   342,   343,   344,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
       1,     3,     6,    25,    26,    49,    53,    83,    85,    98,
     120,   152,   166,   179,   255,   419,   420,   421,   423,   424,
     425,   426,   427,   428,   429,   436,   437,   438,   439,   440,
     441,   263,   263,   261,   455,   153,   260,   263,   263,   465,
     261,   469,   197,   269,   197,   269,   131,   153,   131,   197,
     197,   131,   153,   197,   131,   131,   131,   197,   269,   197,
     197,   269,   153,   197,   131,   131,   269,   131,   131,   153,
     131,   131,   197,   197,   263,   197,   263,   269,   269,   197,
     269,   153,   197,   197,   197,   197,   198,   197,   198,   197,
     197,   269,   269,   131,   271,   269,   197,   197,   197,   197,
     260,   549,   263,   263,   543,   263,   263,   261,   539,   260,
     263,   263,   381,   263,   263,   263,   263,   263,   261,   375,
     263,   445,   263,   261,   449,   260,   361,   263,   263,   263,
     261,   365,   153,   153,   153,   153,   153,   153,   153,   153,
     220,   221,   222,   223,   224,   225,   226,   153,   153,   197,
     260,   153,   153,   260,     1,    26,    49,    53,   120,   147,
     166,   236,   248,   319,   320,   321,   323,   324,   325,   326,
     327,   328,   332,   260,   263,   263,   263,   261,   393,   197,
     197,   197,   153,   197,   197,   269,   260,   153,   197,   153,
     153,   153,   153,   153,   263,   153,   131,   153,   153,   260,
     260,   263,   404,   263,   261,   400,   260,   263,   413,   261,
     410,   260,   260,   260,   260,   260,   260,   260,   260,   173,
     174,   175,   176,   177,   268,   269,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   261,   343,   260,   263,   263,   263,   263,
     263,   430,   263,   263,   263,   263,   263,   263,   263,   263,
     261,   420,   153,   153,   260,   260,   153,   153,   263,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   204,   205,   206,   207,   208,   210,   211,   213,
     214,   215,   218,   228,   229,   230,   232,   233,   234,   237,
     240,   530,   531,   260,   204,   205,   206,   207,   208,   210,
     211,   213,   214,   215,   218,   228,   229,   230,   232,   233,
     234,   237,   240,   526,   527,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,    14,    15,    16,   270,   271,   260,   260,   260,   260,
     260,   260,   263,   269,   197,   263,   153,   153,   260,   153,
     197,   263,   153,   131,   153,   153,   153,   260,   153,   263,
     153,   260,   263,   153,   153,   131,   368,   369,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     263,   263,   333,   263,   263,   263,   329,   263,   261,   320,
     153,   153,   153,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   169,   170,
     282,   283,   260,   260,   260,   260,   153,   263,   153,   260,
     153,   263,   260,   268,   268,   268,   268,   268,   131,   131,
     269,   131,   131,   131,   131,   153,   131,   131,   269,   269,
     271,   260,   153,   216,   217,   153,   153,   197,   263,   153,
     153,   153,   153,   131,   153,   153,   153,   260,   260,   260,
     260,   260,   158,   466,   467,   260,   264,   260,   264,   270,
     270,   270,    11,   199,   550,   551,   260,   260,    11,   199,
     544,   545,   260,   260,   260,   260,   130,   382,   383,   385,
     260,   260,   260,   260,   260,   260,   158,   446,   447,   260,
      76,   231,   235,   362,   363,   260,   260,   202,   264,   367,
     153,   197,   263,   153,   153,   153,   263,   153,   260,   260,
     260,   260,   260,   264,   260,    92,   171,   203,   218,   238,
     239,   244,   245,   246,   247,   257,   405,   406,   260,   260,
      92,   171,   203,   218,   238,   239,   244,   245,   246,   247,
     257,   414,   415,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   130,   431,   432,   434,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   264,   531,   527,   260,   264,
     260,   264,   384,   260,   264,    20,    21,    50,    67,    74,
      93,   121,   129,   172,   191,   386,   260,   264,   260,   264,
     131,   369,   260,   260,   260,   130,   334,   335,   337,   260,
     260,   260,   204,   205,   206,   207,   208,   210,   211,   213,
     214,   215,   218,   228,   229,   230,   232,   233,   234,   237,
     240,   330,   331,   260,   283,   260,   264,   260,   264,   433,
     260,   264,    10,    12,    27,    31,   242,   435,   467,   551,
     545,   386,   383,   447,   363,   336,   260,   264,     5,    38,
      49,    65,    72,    77,    79,    92,   125,   141,   159,   161,
     162,   229,   247,   257,   338,   260,   264,   406,   415,   435,
     432,   338,   335,   331
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
#line 423 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 425 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 429 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 433 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 437 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 441 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 445 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 450 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 451 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 453 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 454 "ircd_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 468 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 474 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 64:

/* Line 1806 of yacc.c  */
#line 494 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version = 0;
#endif
}
    break;

  case 65:

/* Line 1806 of yacc.c  */
#line 500 "ircd_parser.y"
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
#line 514 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_SSLV3;
#endif
}
    break;

  case 69:

/* Line 1806 of yacc.c  */
#line 520 "ircd_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.boot && conf_parser_ctx.pass == 2)
    ServerInfo.tls_version |= CONF_SERVER_INFO_TLS_VERSION_TLSV1;
#endif
}
    break;

  case 70:

/* Line 1806 of yacc.c  */
#line 528 "ircd_parser.y"
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
#line 562 "ircd_parser.y"
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
#line 622 "ircd_parser.y"
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
#line 637 "ircd_parser.y"
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
#line 652 "ircd_parser.y"
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
#line 661 "ircd_parser.y"
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
#line 675 "ircd_parser.y"
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
#line 684 "ircd_parser.y"
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
#line 712 "ircd_parser.y"
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
#line 742 "ircd_parser.y"
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
#line 765 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 88:

/* Line 1806 of yacc.c  */
#line 780 "ircd_parser.y"
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
#line 789 "ircd_parser.y"
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
#line 798 "ircd_parser.y"
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
#line 825 "ircd_parser.y"
    {
                        }
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 829 "ircd_parser.y"
    {
                        }
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 833 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 110:

/* Line 1806 of yacc.c  */
#line 840 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 111:

/* Line 1806 of yacc.c  */
#line 847 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 112:

/* Line 1806 of yacc.c  */
#line 854 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 113:

/* Line 1806 of yacc.c  */
#line 861 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 114:

/* Line 1806 of yacc.c  */
#line 868 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 115:

/* Line 1806 of yacc.c  */
#line 875 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 882 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 889 "ircd_parser.y"
    { 
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 893 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 897 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_WARN);
}
    break;

  case 120:

/* Line 1806 of yacc.c  */
#line 901 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 121:

/* Line 1806 of yacc.c  */
#line 905 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 122:

/* Line 1806 of yacc.c  */
#line 909 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_INFO);
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 913 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 919 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 928 "ircd_parser.y"
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
#line 941 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1028 "ircd_parser.y"
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
#line 1040 "ircd_parser.y"
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
#line 1052 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1086 "ircd_parser.y"
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
#line 1098 "ircd_parser.y"
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
#line 1109 "ircd_parser.y"
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
#line 1151 "ircd_parser.y"
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
#line 1160 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 151:

/* Line 1806 of yacc.c  */
#line 1167 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 152:

/* Line 1806 of yacc.c  */
#line 1171 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1175 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1179 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1183 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1187 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1191 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1195 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1199 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1203 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1207 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1211 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1215 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1219 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1223 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1227 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1231 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1235 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1239 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1245 "ircd_parser.y"
    {
}
    break;

  case 174:

/* Line 1806 of yacc.c  */
#line 1249 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 176:

/* Line 1806 of yacc.c  */
#line 1250 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1253 "ircd_parser.y"
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
#line 1260 "ircd_parser.y"
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
#line 1267 "ircd_parser.y"
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
#line 1274 "ircd_parser.y"
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
#line 1281 "ircd_parser.y"
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
#line 1288 "ircd_parser.y"
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
#line 1295 "ircd_parser.y"
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
#line 1302 "ircd_parser.y"
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
#line 1309 "ircd_parser.y"
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
#line 1316 "ircd_parser.y"
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
#line 1323 "ircd_parser.y"
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
#line 1330 "ircd_parser.y"
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
#line 1337 "ircd_parser.y"
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
#line 1344 "ircd_parser.y"
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
#line 1351 "ircd_parser.y"
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
#line 1358 "ircd_parser.y"
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
#line 1371 "ircd_parser.y"
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
#line 1378 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1438 "ircd_parser.y"
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
#line 1447 "ircd_parser.y"
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
#line 1456 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1462 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    PingWarning(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1468 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxPerIp(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1474 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    ConFreq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1480 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxTotal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1486 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxGlobal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1492 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxLocal(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1498 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxIdent(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1504 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    MaxSendq(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1510 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1516 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1522 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    NumberPerCidr(yy_class) = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1531 "ircd_parser.y"
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
#line 1538 "ircd_parser.y"
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
#line 1547 "ircd_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1553 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:

/* Line 1806 of yacc.c  */
#line 1557 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:

/* Line 1806 of yacc.c  */
#line 1561 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:

/* Line 1806 of yacc.c  */
#line 1571 "ircd_parser.y"
    { listener_flags = 0; }
    break;

  case 248:

/* Line 1806 of yacc.c  */
#line 1576 "ircd_parser.y"
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
#line 1590 "ircd_parser.y"
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
#line 1610 "ircd_parser.y"
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
#line 1619 "ircd_parser.y"
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
#line 1631 "ircd_parser.y"
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
#line 1643 "ircd_parser.y"
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
#line 1705 "ircd_parser.y"
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
#line 1742 "ircd_parser.y"
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
#line 1755 "ircd_parser.y"
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
#line 1764 "ircd_parser.y"
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
#line 1775 "ircd_parser.y"
    {
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1779 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1780 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1783 "ircd_parser.y"
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
#line 1790 "ircd_parser.y"
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
#line 1797 "ircd_parser.y"
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
#line 1804 "ircd_parser.y"
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
#line 1811 "ircd_parser.y"
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
#line 1818 "ircd_parser.y"
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
#line 1825 "ircd_parser.y"
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
#line 1832 "ircd_parser.y"
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
#line 1839 "ircd_parser.y"
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
#line 1846 "ircd_parser.y"
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
#line 1856 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1875 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1885 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 290:

/* Line 1806 of yacc.c  */
#line 1898 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:

/* Line 1806 of yacc.c  */
#line 1905 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 298:

/* Line 1806 of yacc.c  */
#line 1917 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1926 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1941 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:

/* Line 1806 of yacc.c  */
#line 1954 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1962 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1973 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 310:

/* Line 1806 of yacc.c  */
#line 1982 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2004 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 2011 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 2015 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 2019 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 2023 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 2027 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 2031 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 2035 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 2039 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 2043 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 2047 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 2051 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:

/* Line 1806 of yacc.c  */
#line 2060 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:

/* Line 1806 of yacc.c  */
#line 2067 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2080 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:

/* Line 1806 of yacc.c  */
#line 2086 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 2093 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 2097 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 2101 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 2105 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2109 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2113 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2117 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2121 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2125 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 347:

/* Line 1806 of yacc.c  */
#line 2129 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 348:

/* Line 1806 of yacc.c  */
#line 2133 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 349:

/* Line 1806 of yacc.c  */
#line 2142 "ircd_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2160 "ircd_parser.y"
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

  case 370:

/* Line 1806 of yacc.c  */
#line 2298 "ircd_parser.y"
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

  case 371:

/* Line 1806 of yacc.c  */
#line 2310 "ircd_parser.y"
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
#line 2322 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 373:

/* Line 1806 of yacc.c  */
#line 2331 "ircd_parser.y"
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

  case 374:

/* Line 1806 of yacc.c  */
#line 2357 "ircd_parser.y"
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

  case 375:

/* Line 1806 of yacc.c  */
#line 2375 "ircd_parser.y"
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

  case 376:

/* Line 1806 of yacc.c  */
#line 2393 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2399 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2403 "ircd_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2411 "ircd_parser.y"
    {
}
    break;

  case 383:

/* Line 1806 of yacc.c  */
#line 2415 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 385:

/* Line 1806 of yacc.c  */
#line 2416 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 387:

/* Line 1806 of yacc.c  */
#line 2419 "ircd_parser.y"
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

  case 388:

/* Line 1806 of yacc.c  */
#line 2430 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 389:

/* Line 1806 of yacc.c  */
#line 2437 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 390:

/* Line 1806 of yacc.c  */
#line 2444 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2451 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 392:

/* Line 1806 of yacc.c  */
#line 2461 "ircd_parser.y"
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

  case 393:

/* Line 1806 of yacc.c  */
#line 2502 "ircd_parser.y"
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

  case 394:

/* Line 1806 of yacc.c  */
#line 2513 "ircd_parser.y"
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

  case 395:

/* Line 1806 of yacc.c  */
#line 2526 "ircd_parser.y"
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

  case 396:

/* Line 1806 of yacc.c  */
#line 2539 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 397:

/* Line 1806 of yacc.c  */
#line 2548 "ircd_parser.y"
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

  case 398:

/* Line 1806 of yacc.c  */
#line 2583 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 399:

/* Line 1806 of yacc.c  */
#line 2590 "ircd_parser.y"
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

  case 400:

/* Line 1806 of yacc.c  */
#line 2646 "ircd_parser.y"
    {
}
    break;

  case 404:

/* Line 1806 of yacc.c  */
#line 2651 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 411:

/* Line 1806 of yacc.c  */
#line 2660 "ircd_parser.y"
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

  case 412:

/* Line 1806 of yacc.c  */
#line 2679 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 413:

/* Line 1806 of yacc.c  */
#line 2688 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 2692 "ircd_parser.y"
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

  case 420:

/* Line 1806 of yacc.c  */
#line 2714 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2720 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 427:

/* Line 1806 of yacc.c  */
#line 2734 "ircd_parser.y"
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

  case 428:

/* Line 1806 of yacc.c  */
#line 2752 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 2759 "ircd_parser.y"
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

  case 430:

/* Line 1806 of yacc.c  */
#line 2799 "ircd_parser.y"
    {
}
    break;

  case 434:

/* Line 1806 of yacc.c  */
#line 2804 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 441:

/* Line 1806 of yacc.c  */
#line 2813 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 442:

/* Line 1806 of yacc.c  */
#line 2819 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2864 "ircd_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2869 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:

/* Line 1806 of yacc.c  */
#line 2874 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2879 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2884 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2889 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2894 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2899 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2904 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2909 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2914 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2919 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2924 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2929 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2934 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2939 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2944 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2949 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2954 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2960 "ircd_parser.y"
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

  case 522:

/* Line 1806 of yacc.c  */
#line 2971 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2976 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2985 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2990 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2995 "ircd_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 3000 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 3005 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 3010 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 3013 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 3018 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 3021 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 533:

/* Line 1806 of yacc.c  */
#line 3026 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 534:

/* Line 1806 of yacc.c  */
#line 3031 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 535:

/* Line 1806 of yacc.c  */
#line 3036 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 3041 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 3046 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 3051 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 3056 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 3061 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 3066 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 3077 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[(3) - (4)].number);
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 3082 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 3087 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 3092 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 3101 "ircd_parser.y"
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

  case 547:

/* Line 1806 of yacc.c  */
#line 3133 "ircd_parser.y"
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

  case 548:

/* Line 1806 of yacc.c  */
#line 3151 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 3156 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 3175 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 3180 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 557:

/* Line 1806 of yacc.c  */
#line 3186 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 558:

/* Line 1806 of yacc.c  */
#line 3189 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 559:

/* Line 1806 of yacc.c  */
#line 3192 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 3195 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 3198 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 3201 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 3204 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 3207 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 3210 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 3213 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 3216 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 3219 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 3222 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 3225 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 3228 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 3234 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 3237 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 3240 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 3245 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 3251 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 3260 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 3263 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 3266 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 586:

/* Line 1806 of yacc.c  */
#line 3269 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 587:

/* Line 1806 of yacc.c  */
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 588:

/* Line 1806 of yacc.c  */
#line 3275 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 589:

/* Line 1806 of yacc.c  */
#line 3278 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 590:

/* Line 1806 of yacc.c  */
#line 3281 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 591:

/* Line 1806 of yacc.c  */
#line 3284 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 592:

/* Line 1806 of yacc.c  */
#line 3287 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 593:

/* Line 1806 of yacc.c  */
#line 3290 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 594:

/* Line 1806 of yacc.c  */
#line 3293 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 595:

/* Line 1806 of yacc.c  */
#line 3296 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3299 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3302 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 598:

/* Line 1806 of yacc.c  */
#line 3305 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 599:

/* Line 1806 of yacc.c  */
#line 3310 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:

/* Line 1806 of yacc.c  */
#line 3315 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3320 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3325 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3334 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 604:

/* Line 1806 of yacc.c  */
#line 3341 "ircd_parser.y"
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

  case 614:

/* Line 1806 of yacc.c  */
#line 3367 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 615:

/* Line 1806 of yacc.c  */
#line 3373 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:

/* Line 1806 of yacc.c  */
#line 3379 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 620:

/* Line 1806 of yacc.c  */
#line 3385 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 621:

/* Line 1806 of yacc.c  */
#line 3389 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 622:

/* Line 1806 of yacc.c  */
#line 3395 "ircd_parser.y"
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

  case 623:

/* Line 1806 of yacc.c  */
#line 3429 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 624:

/* Line 1806 of yacc.c  */
#line 3438 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 625:

/* Line 1806 of yacc.c  */
#line 3442 "ircd_parser.y"
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

  case 628:

/* Line 1806 of yacc.c  */
#line 3489 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 629:

/* Line 1806 of yacc.c  */
#line 3493 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 652:

/* Line 1806 of yacc.c  */
#line 3517 "ircd_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 653:

/* Line 1806 of yacc.c  */
#line 3522 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 654:

/* Line 1806 of yacc.c  */
#line 3527 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 655:

/* Line 1806 of yacc.c  */
#line 3532 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 656:

/* Line 1806 of yacc.c  */
#line 3537 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 657:

/* Line 1806 of yacc.c  */
#line 3542 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 658:

/* Line 1806 of yacc.c  */
#line 3547 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 659:

/* Line 1806 of yacc.c  */
#line 3552 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3557 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3562 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3567 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3572 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 664:

/* Line 1806 of yacc.c  */
#line 3577 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3582 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3587 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 667:

/* Line 1806 of yacc.c  */
#line 3592 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 668:

/* Line 1806 of yacc.c  */
#line 3597 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 669:

/* Line 1806 of yacc.c  */
#line 3602 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 681:

/* Line 1806 of yacc.c  */
#line 3621 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 682:

/* Line 1806 of yacc.c  */
#line 3627 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 683:

/* Line 1806 of yacc.c  */
#line 3633 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 684:

/* Line 1806 of yacc.c  */
#line 3642 "ircd_parser.y"
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

  case 685:

/* Line 1806 of yacc.c  */
#line 3656 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 686:

/* Line 1806 of yacc.c  */
#line 3662 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 687:

/* Line 1806 of yacc.c  */
#line 3668 "ircd_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 8072 "ircd_parser.c"
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



