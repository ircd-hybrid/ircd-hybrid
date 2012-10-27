/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

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

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

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
     DISABLE_HIDDEN = 295,
     DISABLE_LOCAL_CHANNELS = 296,
     DISABLE_REMOTE_COMMANDS = 297,
     DOT_IN_IP6_ADDR = 298,
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
     LAZYLINK = 354,
     LEAF_MASK = 355,
     LINKS_DELAY = 356,
     LISTEN = 357,
     T_LOG = 358,
     LOGGING = 359,
     LOG_LEVEL = 360,
     MAX_ACCEPT = 361,
     MAX_BANS = 362,
     MAX_CHANS_PER_USER = 363,
     MAX_GLOBAL = 364,
     MAX_IDENT = 365,
     MAX_LOCAL = 366,
     MAX_NICK_CHANGES = 367,
     MAX_NICK_TIME = 368,
     MAX_NUMBER = 369,
     MAX_TARGETS = 370,
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
     RESV = 424,
     RESV_EXEMPT = 425,
     SECONDS = 426,
     MINUTES = 427,
     HOURS = 428,
     DAYS = 429,
     WEEKS = 430,
     SENDQ = 431,
     SEND_PASSWORD = 432,
     SERVERHIDE = 433,
     SERVERINFO = 434,
     SERVLINK_PATH = 435,
     IRCD_SID = 436,
     TKLINE_EXPIRE_NOTICES = 437,
     T_SHARED = 438,
     T_CLUSTER = 439,
     TYPE = 440,
     SHORT_MOTD = 441,
     SILENT = 442,
     SPOOF = 443,
     SPOOF_NOTICE = 444,
     STATS_I_OPER_ONLY = 445,
     STATS_K_OPER_ONLY = 446,
     STATS_O_OPER_ONLY = 447,
     STATS_P_OPER_ONLY = 448,
     TBOOL = 449,
     TMASKED = 450,
     T_REJECT = 451,
     TS_MAX_DELTA = 452,
     TS_WARN_DELTA = 453,
     TWODOTS = 454,
     T_ALL = 455,
     T_BOTS = 456,
     T_SOFTCALLERID = 457,
     T_CALLERID = 458,
     T_CCONN = 459,
     T_CLIENT_FLOOD = 460,
     T_DEAF = 461,
     T_DEBUG = 462,
     T_DRONE = 463,
     T_EXTERNAL = 464,
     T_FULL = 465,
     T_INVISIBLE = 466,
     T_IPV4 = 467,
     T_IPV6 = 468,
     T_LOCOPS = 469,
     T_LOGPATH = 470,
     T_L_CRIT = 471,
     T_L_DEBUG = 472,
     T_L_ERROR = 473,
     T_L_INFO = 474,
     T_L_NOTICE = 475,
     T_L_TRACE = 476,
     T_L_WARN = 477,
     T_MAX_CLIENTS = 478,
     T_NCHANGE = 479,
     T_OPERWALL = 480,
     T_REJ = 481,
     T_SERVNOTICE = 482,
     T_SKILL = 483,
     T_SPY = 484,
     T_SSL = 485,
     T_UMODES = 486,
     T_UNAUTH = 487,
     T_UNRESV = 488,
     T_UNXLINE = 489,
     T_WALLOP = 490,
     THROTTLE_TIME = 491,
     TOPICBURST = 492,
     TRUE_NO_OPER_FLOOD = 493,
     TKLINE = 494,
     TXLINE = 495,
     TRESV = 496,
     UNKLINE = 497,
     USER = 498,
     USE_EGD = 499,
     USE_EXCEPT = 500,
     USE_INVEX = 501,
     USE_KNOCK = 502,
     USE_LOGGING = 503,
     USE_WHOIS_ACTUALLY = 504,
     VHOST = 505,
     VHOST6 = 506,
     XLINE = 507,
     WARN = 508,
     WARN_NO_NLINE = 509
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
#define DISABLE_HIDDEN 295
#define DISABLE_LOCAL_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DOT_IN_IP6_ADDR 298
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
#define LAZYLINK 354
#define LEAF_MASK 355
#define LINKS_DELAY 356
#define LISTEN 357
#define T_LOG 358
#define LOGGING 359
#define LOG_LEVEL 360
#define MAX_ACCEPT 361
#define MAX_BANS 362
#define MAX_CHANS_PER_USER 363
#define MAX_GLOBAL 364
#define MAX_IDENT 365
#define MAX_LOCAL 366
#define MAX_NICK_CHANGES 367
#define MAX_NICK_TIME 368
#define MAX_NUMBER 369
#define MAX_TARGETS 370
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
#define RESV 424
#define RESV_EXEMPT 425
#define SECONDS 426
#define MINUTES 427
#define HOURS 428
#define DAYS 429
#define WEEKS 430
#define SENDQ 431
#define SEND_PASSWORD 432
#define SERVERHIDE 433
#define SERVERINFO 434
#define SERVLINK_PATH 435
#define IRCD_SID 436
#define TKLINE_EXPIRE_NOTICES 437
#define T_SHARED 438
#define T_CLUSTER 439
#define TYPE 440
#define SHORT_MOTD 441
#define SILENT 442
#define SPOOF 443
#define SPOOF_NOTICE 444
#define STATS_I_OPER_ONLY 445
#define STATS_K_OPER_ONLY 446
#define STATS_O_OPER_ONLY 447
#define STATS_P_OPER_ONLY 448
#define TBOOL 449
#define TMASKED 450
#define T_REJECT 451
#define TS_MAX_DELTA 452
#define TS_WARN_DELTA 453
#define TWODOTS 454
#define T_ALL 455
#define T_BOTS 456
#define T_SOFTCALLERID 457
#define T_CALLERID 458
#define T_CCONN 459
#define T_CLIENT_FLOOD 460
#define T_DEAF 461
#define T_DEBUG 462
#define T_DRONE 463
#define T_EXTERNAL 464
#define T_FULL 465
#define T_INVISIBLE 466
#define T_IPV4 467
#define T_IPV6 468
#define T_LOCOPS 469
#define T_LOGPATH 470
#define T_L_CRIT 471
#define T_L_DEBUG 472
#define T_L_ERROR 473
#define T_L_INFO 474
#define T_L_NOTICE 475
#define T_L_TRACE 476
#define T_L_WARN 477
#define T_MAX_CLIENTS 478
#define T_NCHANGE 479
#define T_OPERWALL 480
#define T_REJ 481
#define T_SERVNOTICE 482
#define T_SKILL 483
#define T_SPY 484
#define T_SSL 485
#define T_UMODES 486
#define T_UNAUTH 487
#define T_UNRESV 488
#define T_UNXLINE 489
#define T_WALLOP 490
#define THROTTLE_TIME 491
#define TOPICBURST 492
#define TRUE_NO_OPER_FLOOD 493
#define TKLINE 494
#define TXLINE 495
#define TRESV 496
#define UNKLINE 497
#define USER 498
#define USE_EGD 499
#define USE_EXCEPT 500
#define USE_INVEX 501
#define USE_KNOCK 502
#define USE_LOGGING 503
#define USE_WHOIS_ACTUALLY 504
#define VHOST 505
#define VHOST6 506
#define XLINE 507
#define WARN 508
#define WARN_NO_NLINE 509




/* Copy the first part of user declarations.  */
#line 25 "ircd_parser.y"


#define YY_NO_UNPUT
#include <sys/types.h>

#include "stdinc.h"
#include "dalloca.h"
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

struct CollectItem {
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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 134 "ircd_parser.y"
typedef union YYSTYPE {
  int number;
  char *string;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 707 "y.tab.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 719 "y.tab.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
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
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1382

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  260
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  337
/* YYNRULES -- Number of rules. */
#define YYNRULES  724
/* YYNRULES -- Number of states. */
#define YYNSTATES  1459

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   509

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned short int yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   259,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   255,
       2,   258,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   257,     2,   256,     2,     2,     2,     2,
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
     245,   246,   247,   248,   249,   250,   251,   252,   253,   254
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
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
     795,   797,   799,   802,   807,   811,   813,   815,   819,   824,
     829,   830,   837,   840,   842,   844,   846,   848,   850,   852,
     854,   856,   858,   860,   862,   864,   866,   868,   870,   872,
     874,   877,   882,   887,   892,   897,   902,   903,   909,   913,
     915,   916,   920,   921,   924,   926,   928,   930,   932,   934,
     936,   938,   940,   942,   944,   949,   954,   959,   964,   969,
     974,   979,   984,   989,   994,   995,  1002,  1005,  1007,  1009,
    1011,  1013,  1016,  1021,  1026,  1031,  1032,  1039,  1042,  1044,
    1046,  1048,  1050,  1053,  1058,  1063,  1064,  1070,  1074,  1076,
    1078,  1080,  1082,  1084,  1086,  1088,  1090,  1092,  1094,  1096,
    1098,  1099,  1106,  1109,  1111,  1113,  1115,  1118,  1123,  1124,
    1130,  1134,  1136,  1138,  1140,  1142,  1144,  1146,  1148,  1150,
    1152,  1154,  1156,  1158,  1159,  1167,  1168,  1170,  1173,  1175,
    1177,  1179,  1181,  1183,  1185,  1187,  1189,  1191,  1193,  1195,
    1197,  1199,  1201,  1203,  1205,  1207,  1209,  1211,  1214,  1219,
    1221,  1226,  1231,  1236,  1241,  1246,  1251,  1256,  1261,  1262,
    1268,  1272,  1274,  1275,  1279,  1280,  1283,  1285,  1287,  1289,
    1291,  1293,  1295,  1300,  1305,  1310,  1315,  1320,  1325,  1330,
    1335,  1340,  1341,  1348,  1349,  1355,  1359,  1361,  1363,  1366,
    1368,  1370,  1372,  1374,  1376,  1381,  1386,  1387,  1394,  1397,
    1399,  1401,  1403,  1405,  1410,  1415,  1421,  1424,  1426,  1428,
    1430,  1435,  1436,  1443,  1444,  1450,  1454,  1456,  1458,  1461,
    1463,  1465,  1467,  1469,  1471,  1476,  1481,  1487,  1490,  1492,
    1494,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1510,  1512,
    1514,  1516,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1532,
    1534,  1536,  1538,  1540,  1542,  1544,  1546,  1548,  1550,  1552,
    1554,  1556,  1558,  1560,  1562,  1564,  1566,  1568,  1570,  1572,
    1574,  1576,  1578,  1580,  1582,  1584,  1586,  1588,  1590,  1592,
    1594,  1596,  1598,  1600,  1602,  1607,  1612,  1617,  1622,  1627,
    1632,  1637,  1642,  1647,  1652,  1657,  1662,  1667,  1672,  1677,
    1682,  1687,  1692,  1697,  1702,  1707,  1712,  1717,  1722,  1727,
    1732,  1737,  1742,  1747,  1752,  1757,  1762,  1767,  1772,  1777,
    1782,  1787,  1792,  1797,  1802,  1807,  1812,  1817,  1822,  1827,
    1832,  1837,  1842,  1847,  1848,  1854,  1858,  1860,  1862,  1864,
    1866,  1868,  1870,  1872,  1874,  1876,  1878,  1880,  1882,  1884,
    1886,  1888,  1890,  1892,  1894,  1896,  1897,  1903,  1907,  1909,
    1911,  1913,  1915,  1917,  1919,  1921,  1923,  1925,  1927,  1929,
    1931,  1933,  1935,  1937,  1939,  1941,  1943,  1945,  1950,  1955,
    1960,  1965,  1970,  1971,  1978,  1981,  1983,  1985,  1987,  1989,
    1991,  1993,  1995,  1997,  2002,  2007,  2008,  2014,  2018,  2020,
    2022,  2024,  2029,  2034,  2035,  2041,  2045,  2047,  2049,  2051,
    2057,  2060,  2062,  2064,  2066,  2068,  2070,  2072,  2074,  2076,
    2078,  2080,  2082,  2084,  2086,  2088,  2090,  2092,  2094,  2096,
    2098,  2103,  2108,  2113,  2118,  2123,  2128,  2133,  2138,  2143,
    2148,  2153,  2158,  2163,  2168,  2173,  2178,  2183,  2189,  2192,
    2194,  2196,  2198,  2200,  2202,  2204,  2206,  2208,  2210,  2215,
    2220,  2225,  2230,  2235,  2240
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     261,     0,    -1,    -1,   261,   262,    -1,   286,    -1,   292,
      -1,   307,    -1,   567,    -1,   344,    -1,   363,    -1,   376,
      -1,   272,    -1,   587,    -1,   402,    -1,   409,    -1,   419,
      -1,   428,    -1,   458,    -1,   468,    -1,   474,    -1,   488,
      -1,   551,    -1,   478,    -1,   267,    -1,     1,   255,    -1,
       1,   256,    -1,    -1,   264,    -1,   132,   263,    -1,   132,
     171,   263,    -1,   132,   172,   263,    -1,   132,   173,   263,
      -1,   132,   174,   263,    -1,   132,   175,   263,    -1,    -1,
     266,    -1,   132,   265,    -1,   132,    14,   265,    -1,   132,
      15,   265,    -1,   132,    16,   265,    -1,   120,   257,   268,
     256,   255,    -1,   268,   269,    -1,   269,    -1,   270,    -1,
     271,    -1,     1,   255,    -1,   119,   258,   154,   255,    -1,
     149,   258,   154,   255,    -1,   179,   257,   273,   256,   255,
      -1,   273,   274,    -1,   274,    -1,   277,    -1,   282,    -1,
     285,    -1,   279,    -1,   280,    -1,   281,    -1,   284,    -1,
     276,    -1,   283,    -1,   278,    -1,   275,    -1,     1,   255,
      -1,   168,   258,   154,   255,    -1,   166,   258,   154,   255,
      -1,   121,   258,   154,   255,    -1,   181,   258,   154,   255,
      -1,    37,   258,   154,   255,    -1,   124,   258,   154,   255,
      -1,   123,   258,   154,   255,    -1,   250,   258,   154,   255,
      -1,   251,   258,   154,   255,    -1,   223,   258,   132,   255,
      -1,    85,   258,   194,   255,    -1,     5,   257,   287,   256,
     255,    -1,   287,   288,    -1,   288,    -1,   289,    -1,   291,
      -1,   290,    -1,     1,   255,    -1,   121,   258,   154,   255,
      -1,    47,   258,   154,   255,    -1,    37,   258,   154,   255,
      -1,   104,   257,   293,   256,   255,    -1,   293,   294,    -1,
     294,    -1,   295,    -1,   296,    -1,   305,    -1,   306,    -1,
     297,    -1,   299,    -1,   301,    -1,   302,    -1,   304,    -1,
     300,    -1,   303,    -1,   298,    -1,     1,   255,    -1,   215,
     258,   154,   255,    -1,   139,   258,   154,   255,    -1,    63,
     258,   154,   255,    -1,    56,   258,   154,   255,    -1,    61,
     258,   154,   255,    -1,    62,   258,   154,   255,    -1,    59,
     258,   154,   255,    -1,    58,   258,   154,   255,    -1,    60,
     258,   154,   255,    -1,    57,   258,   154,   255,    -1,   105,
     258,   216,   255,    -1,   105,   258,   218,   255,    -1,   105,
     258,   222,   255,    -1,   105,   258,   220,   255,    -1,   105,
     258,   221,   255,    -1,   105,   258,   219,   255,    -1,   105,
     258,   217,   255,    -1,   248,   258,   194,   255,    -1,    -1,
     137,   308,   309,   257,   310,   256,   255,    -1,    -1,   313,
      -1,   310,   311,    -1,   311,    -1,   312,    -1,   314,    -1,
     315,    -1,   334,    -1,   335,    -1,   319,    -1,   318,    -1,
     323,    -1,   324,    -1,   326,    -1,   327,    -1,   328,    -1,
     329,    -1,   330,    -1,   325,    -1,   331,    -1,   332,    -1,
     333,    -1,   336,    -1,   316,    -1,   317,    -1,   337,    -1,
       1,   255,    -1,   121,   258,   154,   255,    -1,   154,    -1,
     243,   258,   154,   255,    -1,   148,   258,   154,   255,    -1,
      49,   258,   194,   255,    -1,   167,   258,   154,   255,    -1,
      26,   258,   154,   255,    -1,    -1,   231,   320,   258,   321,
     255,    -1,   321,   259,   322,    -1,   322,    -1,   201,    -1,
     204,    -1,   206,    -1,   207,    -1,   210,    -1,   228,    -1,
     224,    -1,   226,    -1,   232,    -1,   229,    -1,   209,    -1,
     225,    -1,   227,    -1,   211,    -1,   235,    -1,   202,    -1,
     203,    -1,   214,    -1,    73,   258,   194,   255,    -1,   162,
     258,   194,   255,    -1,   163,   258,   194,   255,    -1,    93,
     258,   194,   255,    -1,   252,   258,   194,   255,    -1,   242,
     258,   194,   255,    -1,    66,   258,   194,   255,    -1,   126,
     258,   194,   255,    -1,    38,   258,   194,   255,    -1,   160,
     258,   194,   255,    -1,     5,   258,   194,   255,    -1,    78,
     258,   194,   255,    -1,    80,   258,   194,   255,    -1,   225,
     258,   194,   255,    -1,    -1,    54,   338,   258,   339,   255,
      -1,   339,   259,   340,    -1,   340,    -1,    -1,   131,   341,
     343,    -1,    -1,   342,   343,    -1,    73,    -1,   162,    -1,
      93,    -1,   242,    -1,   252,    -1,    66,    -1,    38,    -1,
     160,    -1,     5,    -1,    78,    -1,   126,    -1,   225,    -1,
     142,    -1,    80,    -1,   163,    -1,    49,    -1,    -1,    26,
     345,   346,   257,   347,   256,   255,    -1,    -1,   350,    -1,
     347,   348,    -1,   348,    -1,   349,    -1,   360,    -1,   361,
      -1,   351,    -1,   352,    -1,   362,    -1,   353,    -1,   354,
      -1,   355,    -1,   356,    -1,   357,    -1,   358,    -1,   359,
      -1,     1,   255,    -1,   121,   258,   154,   255,    -1,   154,
      -1,   151,   258,   264,   255,    -1,   152,   258,   264,   255,
      -1,   135,   258,   132,   255,    -1,    30,   258,   264,   255,
      -1,   114,   258,   132,   255,    -1,   109,   258,   132,   255,
      -1,   111,   258,   132,   255,    -1,   110,   258,   132,   255,
      -1,   176,   258,   266,   255,    -1,    23,   258,   132,   255,
      -1,    24,   258,   132,   255,    -1,   134,   258,   132,   255,
      -1,    -1,   102,   364,   257,   369,   256,   255,    -1,    -1,
      54,   366,   258,   367,   255,    -1,   367,   259,   368,    -1,
     368,    -1,   230,    -1,    77,    -1,   369,   370,    -1,   370,
      -1,   371,    -1,   365,    -1,   374,    -1,   375,    -1,     1,
     255,    -1,   153,   258,   372,   255,    -1,   372,   259,   373,
      -1,   373,    -1,   132,    -1,   132,   199,   132,    -1,    90,
     258,   154,   255,    -1,    84,   258,   154,   255,    -1,    -1,
      74,   377,   257,   378,   256,   255,    -1,   378,   379,    -1,
     379,    -1,   380,    -1,   381,    -1,   383,    -1,   385,    -1,
     392,    -1,   393,    -1,   394,    -1,   396,    -1,   397,    -1,
     398,    -1,   382,    -1,   399,    -1,   400,    -1,   395,    -1,
     401,    -1,   384,    -1,     1,   255,    -1,   243,   258,   154,
     255,    -1,   148,   258,   154,   255,    -1,   189,   258,   194,
     255,    -1,    26,   258,   154,   255,    -1,    49,   258,   194,
     255,    -1,    -1,    54,   386,   258,   387,   255,    -1,   387,
     259,   388,    -1,   388,    -1,    -1,   131,   389,   391,    -1,
      -1,   390,   391,    -1,   189,    -1,    50,    -1,    94,    -1,
      75,    -1,    20,    -1,    21,    -1,   130,    -1,    68,    -1,
     170,    -1,   122,    -1,    94,   258,   194,   255,    -1,    75,
     258,   194,   255,    -1,    50,   258,   194,   255,    -1,    20,
     258,   194,   255,    -1,   130,   258,   194,   255,    -1,    68,
     258,   194,   255,    -1,   188,   258,   154,   255,    -1,   158,
     258,   154,   255,    -1,   157,   258,   132,   255,    -1,   122,
     258,   194,   255,    -1,    -1,   169,   403,   257,   404,   256,
     255,    -1,   404,   405,    -1,   405,    -1,   406,    -1,   407,
      -1,   408,    -1,     1,   255,    -1,   156,   258,   154,   255,
      -1,    22,   258,   154,   255,    -1,   125,   258,   154,   255,
      -1,    -1,   183,   410,   257,   411,   256,   255,    -1,   411,
     412,    -1,   412,    -1,   413,    -1,   414,    -1,   415,    -1,
       1,   255,    -1,   121,   258,   154,   255,    -1,   243,   258,
     154,   255,    -1,    -1,   185,   416,   258,   417,   255,    -1,
     417,   259,   418,    -1,   418,    -1,    93,    -1,   239,    -1,
     242,    -1,   252,    -1,   240,    -1,   234,    -1,   169,    -1,
     241,    -1,   233,    -1,   214,    -1,   200,    -1,    -1,   184,
     420,   257,   421,   256,   255,    -1,   421,   422,    -1,   422,
      -1,   423,    -1,   424,    -1,     1,   255,    -1,   121,   258,
     154,   255,    -1,    -1,   185,   425,   258,   426,   255,    -1,
     426,   259,   427,    -1,   427,    -1,    93,    -1,   239,    -1,
     242,    -1,   252,    -1,   240,    -1,   234,    -1,   169,    -1,
     241,    -1,   233,    -1,   214,    -1,   200,    -1,    -1,    29,
     429,   430,   257,   431,   256,   255,    -1,    -1,   434,    -1,
     431,   432,    -1,   432,    -1,   433,    -1,   435,    -1,   436,
      -1,   437,    -1,   438,    -1,   440,    -1,   439,    -1,   441,
      -1,   442,    -1,   454,    -1,   455,    -1,   456,    -1,   453,
      -1,   450,    -1,   452,    -1,   451,    -1,   449,    -1,   457,
      -1,     1,   255,    -1,   121,   258,   154,   255,    -1,   154,
      -1,    84,   258,   154,   255,    -1,   250,   258,   154,   255,
      -1,   177,   258,   154,   255,    -1,     3,   258,   154,   255,
      -1,   153,   258,   132,   255,    -1,     6,   258,   212,   255,
      -1,     6,   258,   213,   255,    -1,    53,   258,   154,   255,
      -1,    -1,    54,   443,   258,   444,   255,    -1,   444,   259,
     445,    -1,   445,    -1,    -1,   131,   446,   448,    -1,    -1,
     447,   448,    -1,    99,    -1,    27,    -1,    31,    -1,    10,
      -1,    12,    -1,   237,    -1,   167,   258,   154,   255,    -1,
      49,   258,   194,   255,    -1,    31,   258,   194,   255,    -1,
      27,   258,   194,   255,    -1,    10,   258,   194,   255,    -1,
      86,   258,   154,   255,    -1,   100,   258,   154,   255,    -1,
      26,   258,   154,   255,    -1,    25,   258,   154,   255,    -1,
      -1,    91,   459,   257,   464,   256,   255,    -1,    -1,   185,
     461,   258,   462,   255,    -1,   462,   259,   463,    -1,   463,
      -1,   159,    -1,   464,   465,    -1,   465,    -1,   466,    -1,
     467,    -1,   460,    -1,     1,    -1,   243,   258,   154,   255,
      -1,   156,   258,   154,   255,    -1,    -1,    36,   469,   257,
     470,   256,   255,    -1,   470,   471,    -1,   471,    -1,   472,
      -1,   473,    -1,     1,    -1,    90,   258,   154,   255,    -1,
     156,   258,   154,   255,    -1,    51,   257,   475,   256,   255,
      -1,   475,   476,    -1,   476,    -1,   477,    -1,     1,    -1,
      90,   258,   154,   255,    -1,    -1,    64,   479,   257,   484,
     256,   255,    -1,    -1,   185,   481,   258,   482,   255,    -1,
     482,   259,   483,    -1,   483,    -1,   159,    -1,   484,   485,
      -1,   485,    -1,   486,    -1,   487,    -1,   480,    -1,     1,
      -1,   121,   258,   154,   255,    -1,   156,   258,   154,   255,
      -1,    65,   257,   489,   256,   255,    -1,   489,   490,    -1,
     490,    -1,   498,    -1,   499,    -1,   501,    -1,   502,    -1,
     503,    -1,   504,    -1,   505,    -1,   506,    -1,   507,    -1,
     508,    -1,   497,    -1,   510,    -1,   511,    -1,   512,    -1,
     513,    -1,   528,    -1,   514,    -1,   516,    -1,   518,    -1,
     517,    -1,   521,    -1,   515,    -1,   522,    -1,   523,    -1,
     524,    -1,   525,    -1,   527,    -1,   526,    -1,   542,    -1,
     529,    -1,   533,    -1,   534,    -1,   538,    -1,   519,    -1,
     520,    -1,   548,    -1,   546,    -1,   547,    -1,   530,    -1,
     500,    -1,   531,    -1,   532,    -1,   549,    -1,   537,    -1,
     509,    -1,   550,    -1,   535,    -1,   536,    -1,   493,    -1,
     496,    -1,   491,    -1,   492,    -1,   494,    -1,   495,    -1,
       1,    -1,    71,   258,   132,   255,    -1,    72,   258,   132,
     255,    -1,    12,   258,   194,   255,    -1,   249,   258,   194,
     255,    -1,   161,   258,   264,   255,    -1,   182,   258,   194,
     255,    -1,    92,   258,   132,   255,    -1,    83,   258,   194,
     255,    -1,    88,   258,   194,   255,    -1,    42,   258,   194,
     255,    -1,    52,   258,   194,   255,    -1,     8,   258,   194,
     255,    -1,   113,   258,   264,   255,    -1,   112,   258,   132,
     255,    -1,   106,   258,   132,   255,    -1,     9,   258,   264,
     255,    -1,   198,   258,   264,   255,    -1,   197,   258,   264,
     255,    -1,    76,   258,   132,   255,    -1,    96,   258,   194,
     255,    -1,    95,   258,   154,   255,    -1,    89,   258,   194,
     255,    -1,   254,   258,   194,   255,    -1,   192,   258,   194,
     255,    -1,   193,   258,   194,   255,    -1,   191,   258,   194,
     255,    -1,   191,   258,   195,   255,    -1,   190,   258,   194,
     255,    -1,   190,   258,   195,   255,    -1,   146,   258,   264,
     255,    -1,    19,   258,   264,   255,    -1,   138,   258,   194,
     255,    -1,   147,   258,   264,   255,    -1,   186,   258,   194,
     255,    -1,   129,   258,   194,   255,    -1,   238,   258,   194,
     255,    -1,   141,   258,   194,   255,    -1,   116,   258,   154,
     255,    -1,    87,   258,   264,   255,    -1,    44,   258,   132,
     255,    -1,   115,   258,   132,   255,    -1,   180,   258,   154,
     255,    -1,    32,   258,   154,   255,    -1,    28,   258,   132,
     255,    -1,   244,   258,   194,   255,    -1,    46,   258,   154,
     255,    -1,   150,   258,   194,   255,    -1,    39,   258,   194,
     255,    -1,   236,   258,   264,   255,    -1,    -1,   143,   539,
     258,   540,   255,    -1,   540,   259,   541,    -1,   541,    -1,
     201,    -1,   204,    -1,   206,    -1,   207,    -1,   210,    -1,
     228,    -1,   224,    -1,   226,    -1,   232,    -1,   229,    -1,
     209,    -1,   225,    -1,   227,    -1,   211,    -1,   235,    -1,
     202,    -1,   203,    -1,   214,    -1,    -1,   140,   543,   258,
     544,   255,    -1,   544,   259,   545,    -1,   545,    -1,   201,
      -1,   204,    -1,   206,    -1,   207,    -1,   210,    -1,   228,
      -1,   224,    -1,   226,    -1,   232,    -1,   229,    -1,   209,
      -1,   225,    -1,   227,    -1,   211,    -1,   235,    -1,   202,
      -1,   203,    -1,   214,    -1,   117,   258,   132,   255,    -1,
     118,   258,   132,   255,    -1,    33,   258,   132,   255,    -1,
     205,   258,   266,   255,    -1,    43,   258,   194,   255,    -1,
      -1,    67,   552,   257,   553,   256,   255,    -1,   553,   554,
      -1,   554,    -1,   555,    -1,   556,    -1,   557,    -1,   561,
      -1,   562,    -1,   563,    -1,     1,    -1,    48,   258,   194,
     255,    -1,    45,   258,   264,   255,    -1,    -1,   104,   558,
     258,   559,   255,    -1,   559,   259,   560,    -1,   560,    -1,
     196,    -1,    11,    -1,   243,   258,   154,   255,    -1,   121,
     258,   154,   255,    -1,    -1,     4,   564,   258,   565,   255,
      -1,   565,   259,   566,    -1,   566,    -1,   196,    -1,    11,
      -1,    22,   257,   568,   256,   255,    -1,   568,   569,    -1,
     569,    -1,   571,    -1,   572,    -1,   573,    -1,   574,    -1,
     579,    -1,   575,    -1,   576,    -1,   577,    -1,   578,    -1,
     580,    -1,   581,    -1,   582,    -1,   570,    -1,   583,    -1,
     584,    -1,   585,    -1,   586,    -1,     1,    -1,   164,   258,
     194,   255,    -1,    41,   258,   194,   255,    -1,   245,   258,
     194,   255,    -1,   246,   258,   194,   255,    -1,   247,   258,
     194,   255,    -1,    97,   258,   264,   255,    -1,    98,   258,
     264,   255,    -1,   108,   258,   132,   255,    -1,   155,   258,
     194,   255,    -1,   107,   258,   132,   255,    -1,    35,   258,
     132,   255,    -1,    34,   258,   132,   255,    -1,   127,   258,
     194,   255,    -1,   128,   258,   194,   255,    -1,    13,   258,
     194,   255,    -1,   144,   258,   132,   255,    -1,   145,   258,
     264,   255,    -1,   178,   257,   588,   256,   255,    -1,   588,
     589,    -1,   589,    -1,   590,    -1,   591,    -1,   593,    -1,
     595,    -1,   594,    -1,   592,    -1,   596,    -1,     1,    -1,
      55,   258,   194,   255,    -1,    82,   258,   194,   255,    -1,
      79,   258,   154,   255,    -1,   101,   258,   264,   255,    -1,
      77,   258,   194,   255,    -1,    40,   258,   194,   255,    -1,
      81,   258,   194,   255,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   392,   392,   393,   396,   397,   398,   399,   400,   401,
     402,   403,   404,   405,   406,   407,   408,   409,   410,   411,
     412,   413,   414,   415,   416,   417,   421,   421,   422,   426,
     430,   434,   438,   442,   448,   448,   449,   450,   451,   452,
     459,   462,   462,   463,   463,   463,   465,   482,   493,   496,
     497,   498,   498,   499,   499,   500,   500,   501,   502,   502,
     503,   503,   504,   506,   540,   600,   614,   632,   641,   655,
     664,   692,   722,   745,   795,   797,   797,   798,   798,   799,
     799,   801,   810,   819,   832,   834,   835,   837,   837,   838,
     839,   839,   840,   840,   841,   841,   842,   842,   843,   844,
     846,   850,   854,   861,   868,   875,   882,   889,   896,   903,
     910,   914,   918,   922,   926,   930,   934,   940,   950,   949,
    1043,  1043,  1044,  1044,  1045,  1045,  1045,  1045,  1046,  1046,
    1047,  1047,  1047,  1048,  1048,  1048,  1049,  1049,  1049,  1050,
    1050,  1050,  1050,  1051,  1051,  1052,  1052,  1054,  1066,  1078,
    1097,  1109,  1120,  1162,  1172,  1171,  1176,  1176,  1177,  1180,
    1183,  1186,  1189,  1192,  1195,  1198,  1201,  1204,  1207,  1210,
    1213,  1216,  1219,  1222,  1225,  1228,  1233,  1244,  1255,  1266,
    1277,  1288,  1299,  1310,  1321,  1332,  1343,  1354,  1365,  1376,
    1388,  1387,  1391,  1391,  1392,  1392,  1393,  1393,  1395,  1402,
    1409,  1416,  1423,  1430,  1437,  1444,  1451,  1458,  1465,  1472,
    1479,  1486,  1493,  1500,  1514,  1513,  1555,  1555,  1557,  1557,
    1558,  1559,  1559,  1560,  1561,  1562,  1563,  1564,  1565,  1566,
    1567,  1568,  1569,  1570,  1572,  1581,  1590,  1596,  1602,  1608,
    1614,  1620,  1626,  1632,  1638,  1644,  1650,  1656,  1666,  1665,
    1682,  1681,  1685,  1685,  1686,  1690,  1696,  1696,  1697,  1697,
    1697,  1697,  1697,  1699,  1701,  1701,  1703,  1718,  1740,  1749,
    1762,  1761,  1830,  1830,  1831,  1831,  1831,  1831,  1832,  1832,
    1833,  1833,  1833,  1834,  1834,  1835,  1835,  1835,  1836,  1836,
    1836,  1838,  1857,  1870,  1881,  1890,  1902,  1901,  1905,  1905,
    1906,  1906,  1907,  1907,  1909,  1917,  1924,  1931,  1938,  1945,
    1952,  1959,  1966,  1973,  1982,  1993,  2004,  2015,  2026,  2037,
    2049,  2068,  2078,  2087,  2103,  2102,  2118,  2118,  2119,  2119,
    2119,  2119,  2121,  2130,  2145,  2159,  2158,  2174,  2174,  2175,
    2175,  2175,  2175,  2177,  2186,  2195,  2194,  2200,  2200,  2201,
    2205,  2209,  2213,  2217,  2221,  2225,  2229,  2233,  2237,  2241,
    2251,  2250,  2267,  2267,  2268,  2268,  2268,  2270,  2277,  2276,
    2282,  2282,  2283,  2287,  2291,  2295,  2299,  2303,  2307,  2311,
    2315,  2319,  2323,  2333,  2332,  2482,  2482,  2483,  2483,  2484,
    2484,  2484,  2485,  2485,  2486,  2486,  2487,  2487,  2487,  2488,
    2488,  2488,  2489,  2489,  2489,  2490,  2490,  2491,  2493,  2505,
    2517,  2526,  2552,  2570,  2588,  2594,  2598,  2606,  2616,  2615,
    2619,  2619,  2620,  2620,  2621,  2621,  2623,  2630,  2641,  2648,
    2655,  2662,  2672,  2713,  2724,  2735,  2750,  2761,  2774,  2787,
    2796,  2832,  2831,  2893,  2892,  2896,  2896,  2897,  2903,  2903,
    2904,  2904,  2904,  2904,  2906,  2922,  2932,  2931,  2953,  2953,
    2954,  2954,  2954,  2956,  2965,  2977,  2979,  2979,  2980,  2980,
    2982,  3004,  3003,  3045,  3044,  3048,  3048,  3049,  3055,  3055,
    3056,  3056,  3056,  3056,  3058,  3064,  3073,  3076,  3076,  3077,
    3077,  3078,  3078,  3079,  3079,  3080,  3080,  3081,  3081,  3082,
    3082,  3083,  3083,  3084,  3084,  3085,  3085,  3086,  3086,  3087,
    3087,  3088,  3088,  3089,  3089,  3090,  3090,  3091,  3091,  3092,
    3092,  3093,  3093,  3094,  3094,  3095,  3095,  3096,  3096,  3097,
    3098,  3098,  3099,  3099,  3100,  3100,  3101,  3101,  3102,  3102,
    3103,  3103,  3104,  3105,  3109,  3114,  3119,  3124,  3129,  3134,
    3139,  3144,  3149,  3154,  3159,  3164,  3169,  3174,  3179,  3184,
    3189,  3194,  3200,  3211,  3216,  3225,  3230,  3235,  3240,  3245,
    3248,  3253,  3256,  3261,  3266,  3271,  3276,  3281,  3286,  3291,
    3296,  3301,  3312,  3317,  3322,  3327,  3336,  3368,  3386,  3391,
    3400,  3405,  3410,  3416,  3415,  3420,  3420,  3421,  3424,  3427,
    3430,  3433,  3436,  3439,  3442,  3445,  3448,  3451,  3454,  3457,
    3460,  3463,  3466,  3469,  3472,  3478,  3477,  3482,  3482,  3483,
    3486,  3489,  3492,  3495,  3498,  3501,  3504,  3507,  3510,  3513,
    3516,  3519,  3522,  3525,  3528,  3531,  3534,  3539,  3544,  3549,
    3554,  3559,  3568,  3567,  3591,  3591,  3592,  3593,  3594,  3595,
    3596,  3597,  3598,  3600,  3606,  3613,  3612,  3617,  3617,  3618,
    3622,  3628,  3647,  3657,  3656,  3706,  3706,  3707,  3711,  3720,
    3723,  3723,  3724,  3724,  3725,  3725,  3726,  3726,  3727,  3727,
    3728,  3728,  3729,  3730,  3730,  3731,  3731,  3732,  3732,  3733,
    3735,  3740,  3745,  3750,  3755,  3760,  3765,  3770,  3775,  3780,
    3785,  3790,  3795,  3800,  3805,  3810,  3815,  3823,  3826,  3826,
    3827,  3827,  3828,  3829,  3830,  3830,  3831,  3832,  3834,  3840,
    3846,  3855,  3869,  3875,  3881
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
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
  "DESCRIPTION", "DIE", "DISABLE_AUTH", "DISABLE_HIDDEN",
  "DISABLE_LOCAL_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOT_IN_IP6_ADDR",
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
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "T_REJECT", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS",
  "T_ALL", "T_BOTS", "T_SOFTCALLERID", "T_CALLERID", "T_CCONN",
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DRONE", "T_EXTERNAL", "T_FULL",
  "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_LOGPATH", "T_L_CRIT",
  "T_L_DEBUG", "T_L_ERROR", "T_L_INFO", "T_L_NOTICE", "T_L_TRACE",
  "T_L_WARN", "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ",
  "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH",
  "T_UNRESV", "T_UNXLINE", "T_WALLOP", "THROTTLE_TIME", "TOPICBURST",
  "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV", "UNKLINE", "USER",
  "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
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
  "listen_port", "port_items", "port_item", "listen_address",
  "listen_host", "auth_entry", "@9", "auth_items", "auth_item",
  "auth_user", "auth_passwd", "auth_spoof_notice", "auth_class",
  "auth_encrypted", "auth_flags", "@10", "auth_flags_items",
  "auth_flags_item", "@11", "@12", "auth_flags_item_atom",
  "auth_kline_exempt", "auth_need_ident", "auth_exceed_limit",
  "auth_can_flood", "auth_no_tilde", "auth_gline_exempt", "auth_spoof",
  "auth_redir_serv", "auth_redir_port", "auth_need_password", "resv_entry",
  "@13", "resv_items", "resv_item", "resv_creason", "resv_channel",
  "resv_nick", "shared_entry", "@14", "shared_items", "shared_item",
  "shared_name", "shared_user", "shared_type", "@15", "shared_types",
  "shared_type_item", "cluster_entry", "@16", "cluster_items",
  "cluster_item", "cluster_name", "cluster_type", "@17", "cluster_types",
  "cluster_type_item", "connect_entry", "@18", "connect_name_b",
  "connect_items", "connect_item", "connect_name", "connect_name_t",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_fakename", "connect_flags", "@19", "connect_flags_items",
  "connect_flags_item", "@20", "@21", "connect_flags_item_atom",
  "connect_rsa_public_key_file", "connect_encrypted", "connect_cryptlink",
  "connect_compressed", "connect_auto", "connect_hub_mask",
  "connect_leaf_mask", "connect_class", "connect_cipher_preference",
  "kill_entry", "@22", "kill_type", "@23", "kill_type_items",
  "kill_type_item", "kill_items", "kill_item", "kill_user", "kill_reason",
  "deny_entry", "@24", "deny_items", "deny_item", "deny_ip", "deny_reason",
  "exempt_entry", "exempt_items", "exempt_item", "exempt_ip",
  "gecos_entry", "@25", "gecos_flags", "@26", "gecos_flags_items",
  "gecos_flags_item", "gecos_items", "gecos_item", "gecos_name",
  "gecos_reason", "general_entry", "general_items", "general_item",
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
  "general_warn_no_nline", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_message_locale", "general_idletime",
  "general_dots_in_ident", "general_max_targets", "general_servlink_path",
  "general_default_cipher_preference", "general_compression_level",
  "general_use_egd", "general_egdpool_path", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "@27", "umode_oitems", "umode_oitem", "general_oper_only_umodes", "@28",
  "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "general_dot_in_ip6_addr", "gline_entry", "@29",
  "gline_items", "gline_item", "gline_enable", "gline_duration",
  "gline_logging", "@30", "gline_logging_types", "gline_logging_type_item",
  "gline_user", "gline_server", "gline_action", "@31", "gdeny_types",
  "gdeny_type_item", "channel_entry", "channel_items", "channel_item",
  "channel_restrict_channels", "channel_disable_local_channels",
  "channel_use_except", "channel_use_invex", "channel_use_knock",
  "channel_knock_delay", "channel_knock_delay_channel",
  "channel_max_chans_per_user", "channel_quiet_on_ban", "channel_max_bans",
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
static const unsigned short int yytoknum[] =
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
     505,   506,   507,   508,   509,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   260,   261,   261,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   263,   263,   264,   264,
     264,   264,   264,   264,   265,   265,   266,   266,   266,   266,
     267,   268,   268,   269,   269,   269,   270,   271,   272,   273,
     273,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   287,   288,   288,   288,
     288,   289,   290,   291,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   305,   305,   305,   305,   305,   305,   306,   308,   307,
     309,   309,   310,   310,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   312,   313,   314,
     315,   316,   317,   318,   320,   319,   321,   321,   322,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   333,   334,   335,   336,
     338,   337,   339,   339,   341,   340,   342,   340,   343,   343,
     343,   343,   343,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   343,   343,   345,   344,   346,   346,   347,   347,
     348,   348,   348,   348,   348,   348,   348,   348,   348,   348,
     348,   348,   348,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   364,   363,
     366,   365,   367,   367,   368,   368,   369,   369,   370,   370,
     370,   370,   370,   371,   372,   372,   373,   373,   374,   375,
     377,   376,   378,   378,   379,   379,   379,   379,   379,   379,
     379,   379,   379,   379,   379,   379,   379,   379,   379,   379,
     379,   380,   381,   382,   383,   384,   386,   385,   387,   387,
     389,   388,   390,   388,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   392,   393,   394,   395,   396,   397,
     398,   399,   400,   401,   403,   402,   404,   404,   405,   405,
     405,   405,   406,   407,   408,   410,   409,   411,   411,   412,
     412,   412,   412,   413,   414,   416,   415,   417,   417,   418,
     418,   418,   418,   418,   418,   418,   418,   418,   418,   418,
     420,   419,   421,   421,   422,   422,   422,   423,   425,   424,
     426,   426,   427,   427,   427,   427,   427,   427,   427,   427,
     427,   427,   427,   429,   428,   430,   430,   431,   431,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   432,   432,
     432,   432,   432,   432,   432,   432,   432,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   440,   441,   443,   442,
     444,   444,   446,   445,   447,   445,   448,   448,   448,   448,
     448,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   459,   458,   461,   460,   462,   462,   463,   464,   464,
     465,   465,   465,   465,   466,   467,   469,   468,   470,   470,
     471,   471,   471,   472,   473,   474,   475,   475,   476,   476,
     477,   479,   478,   481,   480,   482,   482,   483,   484,   484,
     485,   485,   485,   485,   486,   487,   488,   489,   489,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   490,   490,   490,   490,   490,   490,
     490,   490,   490,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     516,   517,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   539,   538,   540,   540,   541,   541,   541,
     541,   541,   541,   541,   541,   541,   541,   541,   541,   541,
     541,   541,   541,   541,   541,   543,   542,   544,   544,   545,
     545,   545,   545,   545,   545,   545,   545,   545,   545,   545,
     545,   545,   545,   545,   545,   545,   545,   546,   547,   548,
     549,   550,   552,   551,   553,   553,   554,   554,   554,   554,
     554,   554,   554,   555,   556,   558,   557,   559,   559,   560,
     560,   561,   562,   564,   563,   565,   565,   566,   566,   567,
     568,   568,   569,   569,   569,   569,   569,   569,   569,   569,
     569,   569,   569,   569,   569,   569,   569,   569,   569,   569,
     570,   571,   572,   573,   574,   575,   576,   577,   578,   579,
     580,   581,   582,   583,   584,   585,   586,   587,   588,   588,
     589,   589,   589,   589,   589,   589,   589,   589,   590,   591,
     592,   593,   594,   595,   596
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
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
       1,     1,     2,     4,     3,     1,     1,     3,     4,     4,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     7,     0,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     0,     5,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
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
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     4,     4,     0,     5,     3,     1,     1,     1,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     1,     0,     0,     0,   214,   383,   456,     0,
     471,     0,   642,   270,   441,   248,     0,     0,   118,   324,
       0,     0,   335,   360,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      22,    20,    21,     7,    12,    24,    25,     0,     0,   216,
     385,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    77,    79,    78,   689,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   671,   684,   672,   673,   674,
     675,   677,   678,   679,   680,   676,   681,   682,   683,   685,
     686,   687,   688,   235,     0,   217,   409,     0,   386,     0,
     469,     0,     0,   467,   468,     0,   543,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   615,
       0,   593,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   488,   539,   540,   537,   541,   542,   538,   499,
     489,   490,   528,   491,   492,   493,   494,   495,   496,   497,
     498,   533,   500,   501,   502,   503,   505,   510,   506,   508,
     507,   522,   523,   509,   511,   512,   513,   514,   516,   515,
     504,   518,   527,   529,   530,   519,   520,   535,   536,   532,
     521,   517,   525,   526,   524,   531,   534,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    91,    98,
      92,    96,    93,    94,    97,    95,    89,    90,     0,     0,
       0,     0,    42,    43,    44,   148,     0,   121,     0,   717,
       0,     0,     0,     0,     0,     0,     0,     0,   709,   710,
     711,   715,   712,   714,   713,   716,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    50,
      61,    58,    51,    60,    54,    55,    56,    52,    59,    57,
      53,     0,     0,    80,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   670,     0,     0,
     462,     0,     0,     0,   459,   460,   461,     0,     0,   466,
     483,     0,     0,   473,   482,     0,   479,   480,   481,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   487,   652,   663,     0,     0,   655,
       0,     0,     0,   645,   646,   647,   648,   649,   650,   651,
       0,     0,     0,     0,     0,   296,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   273,   274,
     275,   284,   276,   289,   277,   278,   279,   280,   287,   281,
     282,   283,   285,   286,   288,   453,     0,   443,     0,   452,
       0,   449,   450,   451,     0,   250,     0,     0,     0,   259,
       0,   257,   258,   260,   261,    99,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      45,     0,     0,     0,    41,     0,     0,     0,     0,     0,
       0,   327,   328,   329,   330,     0,     0,     0,     0,     0,
       0,     0,     0,   708,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
     345,     0,     0,   338,   339,   340,   341,     0,     0,   368,
       0,   363,   364,   365,     0,     0,     0,    74,     0,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   669,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   219,   220,   223,   224,   226,   227,   228,   229,
     230,   231,   232,   221,   222,   225,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   418,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   388,   389,   390,   391,
     392,   393,   395,   394,   396,   397,   405,   402,   404,   403,
     401,   398,   399,   400,   406,     0,     0,     0,   458,     0,
     465,     0,     0,     0,     0,   478,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,   486,     0,     0,     0,     0,     0,     0,
       0,   644,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     272,     0,     0,     0,     0,   448,   262,     0,     0,     0,
       0,     0,   256,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    84,     0,     0,    40,     0,     0,     0,     0,     0,
     190,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,   123,
     124,   125,   126,   143,   144,   130,   129,   131,   132,   138,
     133,   134,   135,   136,   137,   139,   140,   141,   127,   128,
     142,   145,   331,     0,     0,     0,     0,   326,     0,     0,
       0,     0,     0,     0,     0,   707,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,   342,     0,
       0,     0,     0,   337,   366,     0,     0,     0,   362,    83,
      82,    81,   704,   701,   700,   691,    26,    26,    26,    26,
      26,    28,    27,   695,   696,   699,   697,   702,   703,   705,
     706,   698,   690,   692,   693,   694,   233,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   218,   407,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   387,     0,     0,   457,   470,     0,     0,     0,
     472,   555,   559,   546,   574,   587,   586,   639,   591,   553,
     641,   583,   589,   554,   544,   545,   562,   551,   582,   552,
     565,   550,   564,   563,   558,   557,   556,   584,   581,   637,
     638,   578,   575,   619,   634,   635,   620,   621,   622,   629,
     623,   632,   636,   625,   630,   626,   631,   624,   628,   627,
     633,     0,   618,   580,   597,   612,   613,   598,   599,   600,
     607,   601,   610,   614,   603,   608,   604,   609,   602,   606,
     605,   611,     0,   596,   573,   576,   590,   548,   585,   549,
     577,   571,   572,   569,   570,   567,   568,   561,   560,    34,
      34,    34,    36,    35,   640,   592,   579,   588,   547,   566,
       0,     0,     0,     0,     0,     0,   643,     0,     0,     0,
       0,   302,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   271,     0,     0,     0,   442,     0,     0,
       0,   266,     0,   265,   249,   103,   109,   107,   106,   108,
     104,   105,   102,   110,   116,   111,   115,   113,   114,   112,
     101,   100,   117,    46,    47,   146,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   122,
       0,     0,     0,   325,   723,   718,   722,   720,   724,   719,
     721,    67,    73,    65,    69,    68,    64,    63,    66,    72,
      70,    71,     0,     0,     0,   336,     0,     0,   361,    29,
      30,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   424,     0,
       0,     0,     0,     0,     0,     0,     0,   384,   463,   464,
     484,   485,   477,     0,   476,   616,     0,   594,     0,    37,
      38,    39,   668,   667,     0,   666,   654,   653,   660,   659,
       0,   658,   662,   661,   317,   294,   295,   316,   300,     0,
     299,     0,   319,   315,   314,   323,   318,   292,   322,   321,
     320,   293,   291,   455,   447,     0,   446,   454,   255,   254,
       0,   253,   269,   268,     0,   263,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   119,
     333,   334,   332,   343,   349,   355,   359,   358,   357,   354,
     350,   353,   356,   351,   352,     0,   348,   344,   367,   372,
     378,   382,   381,   380,   377,   373,   376,   379,   374,   375,
       0,   371,   245,   246,   239,   241,   243,   242,   240,   234,
     247,   238,   236,   237,   244,   413,   415,   416,   436,   440,
     439,   435,   434,   433,   417,   422,     0,   421,     0,   410,
     437,   438,   408,   414,   432,   412,   411,   474,     0,   617,
     595,   664,     0,   656,     0,     0,   297,   302,   308,   309,
     305,   311,   307,   306,   313,   310,   312,   304,   303,   444,
       0,   251,     0,   267,   264,   186,   153,   184,   151,   194,
       0,   193,     0,   182,   176,   187,   188,   179,   147,   183,
     150,   185,   177,   178,   152,   189,   158,   173,   174,   159,
     160,   161,   168,   162,   171,   175,   164,   169,   165,   170,
     163,   167,   166,   172,     0,   157,   181,   149,   180,   346,
       0,   369,     0,     0,   419,   424,   429,   430,   427,   428,
     426,   431,   425,   475,   665,   657,   301,   298,   445,   252,
       0,   191,   196,   206,   204,   213,   203,   198,   207,   211,
     200,   208,   210,   205,   199,   212,   209,   201,   202,   197,
     155,     0,   347,   370,   423,   420,   195,   192,   156
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,    24,   881,   882,  1032,  1033,    25,   271,   272,
     273,   274,    26,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    27,    71,    72,    73,
      74,    75,    28,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   265,   266,   267,    29,    61,   276,
     808,   809,   810,   277,   811,   812,   813,   814,   815,   816,
    1114,  1404,  1405,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,  1100,  1370,
    1371,  1430,  1372,  1449,    30,    49,   114,   601,   602,   603,
     115,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,    31,    58,   489,   757,  1240,  1241,   490,
     491,   492,  1072,  1073,   493,   494,    32,    56,   457,   458,
     459,   460,   461,   462,   463,   464,   737,  1219,  1220,  1345,
    1221,  1358,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,    33,    62,   520,   521,   522,   523,   524,    34,
      65,   552,   553,   554,   555,   556,   860,  1285,  1286,    35,
      66,   560,   561,   562,   563,   866,  1300,  1301,    36,    50,
     117,   635,   636,   637,   118,   638,   639,   640,   641,   642,
     643,   644,   645,   922,  1326,  1327,  1413,  1328,  1422,   646,
     647,   648,   649,   650,   651,   652,   653,   654,    37,    57,
     479,   752,  1235,  1236,   480,   481,   482,   483,    38,    51,
     353,   354,   355,   356,    39,   122,   123,   124,    40,    53,
     364,   663,  1193,  1194,   365,   366,   367,   368,    41,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   403,
    1012,  1013,   231,   401,   991,   992,   232,   233,   234,   235,
     236,    42,    55,   432,   433,   434,   435,   436,   727,  1210,
    1211,   437,   438,   439,   724,  1204,  1205,    43,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,    44,   287,   288,
     289,   290,   291,   292,   293,   294,   295
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -876
static const short int yypact[] =
{
    -876,   822,  -876,  -236,  -248,  -246,  -876,  -876,  -876,  -240,
    -876,  -228,  -876,  -876,  -876,  -876,  -223,  -221,  -876,  -876,
    -203,  -179,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,    21,   685,   -73,
     -64,  -154,    17,  -152,   510,  -149,  -143,  -140,  -125,   398,
      78,   -17,  -113,   802,   546,   -92,   -86,   -78,   -65,   -56,
     -50,    51,  -876,  -876,  -876,  -876,  -876,   -28,   -20,   -10,
      -7,     8,    18,    30,    40,    52,    53,    57,    59,    62,
      63,    65,    66,    68,   239,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,   -72,  -876,  -876,   -47,  -876,    69,
    -876,    74,     7,  -876,  -876,    79,  -876,    77,    80,    82,
      84,    91,    94,    95,    96,    98,    99,   100,   103,   105,
     107,   110,   111,   115,   117,   118,   120,   123,   124,   127,
     129,   130,   131,   132,   135,   137,   138,   139,   140,  -876,
     142,  -876,   149,   150,   153,   155,   156,   167,   169,   173,
     174,   181,   186,   187,   205,   206,   207,   209,   212,   229,
     230,    23,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,    12,   760,    11,
     238,   -18,   231,   232,   233,   234,   240,   241,   243,   244,
     246,   247,   248,   250,   361,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,    42,   252,
     254,    75,  -876,  -876,  -876,  -876,    -8,  -876,    26,  -876,
     255,   256,   258,   262,   263,   266,   267,    49,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,    54,   270,   273,   281,
     282,   286,   288,   290,   292,   297,   299,   302,   121,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,     4,    32,  -876,   162,   225,   342,    72,  -876,   323,
     427,   429,   369,   432,   432,   435,   436,   375,   377,   441,
     432,   383,   384,   385,   386,   390,   332,  -876,   801,   679,
    -876,   330,   331,    85,  -876,  -876,  -876,   437,   335,  -876,
    -876,   334,   336,  -876,  -876,    27,  -876,  -876,  -876,   401,
     432,   407,   432,   471,   450,   475,   414,   416,   417,   480,
     460,   421,   487,   488,   497,   430,   432,   438,   442,   498,
     481,   443,   506,   508,   432,   509,   489,   513,   515,   448,
     464,   404,   465,   405,   432,   432,   470,   432,   511,   472,
     478,  -148,  -131,   482,   483,   432,   432,   542,   432,   484,
     485,   490,   493,   426,  -876,  -876,  -876,   425,   433,  -876,
     439,   451,    39,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
     440,   453,   455,   466,   467,  -876,   473,   477,   479,   491,
     494,   495,   502,   512,   514,   516,   517,   280,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   518,  -876,   519,  -876,
      48,  -876,  -876,  -876,   444,  -876,   520,   523,   526,  -876,
      37,  -876,  -876,  -876,  -876,  -876,   539,   540,   564,   568,
     569,   575,   576,   582,   261,   584,   585,   547,   496,  -876,
    -876,   586,   588,   501,  -876,   595,   530,   529,   531,   532,
      22,  -876,  -876,  -876,  -876,   551,   553,   556,   612,   573,
     574,   432,   533,  -876,  -876,   617,   579,   637,   640,   641,
     644,   645,   647,   674,   653,   654,   560,  -876,   561,   559,
    -876,   563,    58,  -876,  -876,  -876,  -876,   578,   581,  -876,
       2,  -876,  -876,  -876,   590,   598,   600,  -876,   605,   606,
     607,   608,   301,   609,   610,   611,   613,   614,   615,   616,
     619,   620,   621,   622,   625,   630,  -876,   633,   583,   592,
     634,   635,   636,   639,   642,   643,   646,   649,   651,   658,
     661,   295,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   650,   662,   663,   665,
     667,   669,   670,   675,   676,   680,  -876,   681,   682,   683,
     686,   687,   688,   689,   692,   259,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   657,   664,   696,  -876,   707,
    -876,   713,   718,   708,   712,  -876,   714,   715,   716,   717,
     719,   720,   721,   729,   730,   732,   733,   735,   737,   738,
     739,   740,   741,   742,   743,   744,   747,   749,   756,   759,
     763,   764,   766,   767,   768,   769,   770,   771,   754,   772,
     806,   773,   774,   781,   782,   785,   791,   794,   798,   799,
     803,   804,   805,   807,   808,   809,    86,   816,   817,   819,
     820,   823,   824,  -876,   825,   432,   697,   826,   745,   748,
     827,  -876,  -876,   701,   783,   704,   845,   828,   862,   863,
     867,   883,   886,   789,   711,   927,   931,   893,   934,   834,
    -876,   936,   833,   938,   838,  -876,  -876,   836,   941,   942,
     965,   843,  -876,   844,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     864,  -876,   865,   866,  -876,   868,   842,   869,   870,   871,
    -876,   872,   873,   874,   875,   876,   877,   878,   879,   880,
     881,   882,   884,   885,  -876,   887,   888,   889,   108,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   963,   964,   968,   894,  -876,   895,   896,
     897,   898,   899,   900,   901,  -876,   902,   903,   904,   905,
     906,   907,   908,   909,   910,   911,   912,  -876,  -876,   970,
     890,   971,   913,  -876,  -876,   972,   914,   915,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,   432,   432,   432,   432,
     432,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  1009,  1012,   432,
    1037,  1039,  1041,  1042,  1021,  1044,  1045,   432,   432,   542,
     923,  -876,  -876,  1025,   -21,   986,  1027,  1028,   989,   990,
     991,  1032,   929,  1034,  1035,  1036,  1038,  1059,  1040,  1043,
    1046,   940,  -876,   943,   944,  -876,  -876,   946,   947,   660,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -229,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -214,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   542,
     542,   542,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
      -1,   948,   949,     3,   950,   951,  -876,   952,   953,   954,
     955,   705,   956,   957,   958,   959,   960,   961,   962,   966,
     967,   969,   973,  -876,   974,  1060,   975,  -876,   -62,   976,
     977,   994,  -182,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  1002,  1064,  1026,  1029,
     978,  1031,  1033,  1047,  1048,  1049,  1072,  1050,  1079,  1051,
    1052,  1053,  1080,  1054,   979,  1055,  1081,  1056,   983,  -876,
     984,   985,   996,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,   997,   201,   998,  -876,   999,   293,  -876,  -876,
    -876,  -876,  -876,  -876,  1000,  1001,  1003,  1004,  1005,  1006,
    1007,  1008,  1010,  1011,  1013,  1014,  1015,  -876,  1016,  1017,
    1018,  1019,  1020,  1022,  1023,  1024,  1030,  1057,  1126,  1058,
    1061,  1062,  1063,  1065,  1066,  1067,  1068,  -876,  -876,  -876,
    -876,  -876,  -876,  -163,  -876,  -876,   754,  -876,   806,  -876,
    -876,  -876,  -876,  -876,  -135,  -876,  -876,  -876,  -876,  -876,
    -110,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   -79,
    -876,   784,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   -48,  -876,  -876,  -876,  -876,
     -36,  -876,  -876,  -876,  1132,  -876,   965,  1069,  1070,  1071,
    1073,  1136,  1074,  1075,  1076,  1077,  1078,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,   841,  1090,  1091,  1092,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   -33,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
     -23,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,    -9,  -876,    -6,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   660,  -876,
    -876,  -876,    -1,  -876,     3,   784,  -876,   705,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    1060,  -876,   -62,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
      -2,  -876,   492,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,    44,  -876,  -876,  -876,  -876,  -876,
     201,  -876,   293,    -6,  -876,  1126,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
     492,  -876,  1136,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   841,  -876,  -876,  -876,  -876,  -876,  -876,  -876
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -876,  -876,  -876,  -428,  -333,  -875,  -415,  -876,  -876,  1093,
    -876,  -876,  -876,  -876,   980,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  1205,  -876,
    -876,  -876,  -876,  -876,  1094,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   474,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -171,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -151,  -876,  -876,  -147,  -876,  -876,  -876,  -876,   690,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   -76,  -876,
     797,  -876,  -876,    38,  -876,  -876,  -876,  -876,  -876,   832,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,   -57,  -876,
    -876,   -53,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,   775,  -876,  -876,  -876,  -876,
    -876,  -876,   746,  -876,  -876,  -876,  -876,  -876,  -117,  -876,
    -876,  -876,   734,  -876,  -876,  -876,  -876,  -116,  -876,  -876,
    -876,  -876,   666,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -118,  -876,  -876,  -114,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,   -60,  -876,   829,  -876,  -876,  -876,  -876,
    -876,   981,  -876,  -876,  -876,  -876,  1180,  -876,  -876,  -876,
    -876,  -876,  -876,   -35,  -876,   939,  -876,  -876,  -876,  -876,
    1124,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,   109,  -876,  -876,  -876,   112,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,   917,  -876,  -876,  -876,  -876,  -876,
     -38,  -876,  -876,  -876,  -876,  -876,   -32,  -876,  -876,  1217,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,
    -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  -876,  1095,
    -876,  -876,  -876,  -876,  -876,  -876,  -876
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const unsigned short int yytable[] =
{
     573,   574,   717,   557,  1416,   548,  1417,   580,   120,    47,
    1202,    48,   475,   425,  1208,  1238,   426,    52,   120,    45,
      46,  1418,    67,   516,   126,  1419,  1195,   516,   360,    54,
    1196,   127,   128,   557,    59,   129,    60,   667,   484,   669,
     425,  1197,   130,   426,   517,  1198,   708,   709,   517,   475,
     279,   131,    67,   683,    63,   132,   133,   427,    68,   548,
     428,   691,   134,   710,   711,   135,   136,   137,    69,   138,
     350,   701,   702,  1245,   704,   139,   268,  1246,    64,   268,
     360,   113,   714,   715,   427,   718,   350,   428,    68,   280,
     116,   485,  1337,  1420,   140,   141,  1338,   121,    69,   142,
    1029,  1030,  1031,   119,   281,   125,   143,   121,   237,   785,
     144,   145,   146,   786,   238,   147,   429,   239,   148,   149,
    1341,   486,   296,   558,  1342,   549,   282,   487,   283,   150,
     284,   285,   240,   430,   787,   151,   152,   275,   153,   154,
     155,   156,    70,   429,   278,  1343,   788,   518,   361,  1344,
     286,   518,   157,   558,  1199,  1200,  1201,   789,   297,   351,
     430,   158,   790,   159,   160,   321,   161,   476,  1239,   162,
     163,   322,    70,   164,   791,   351,  1346,   323,   519,   549,
    1347,   792,   519,   362,   165,   348,   793,   559,   794,   550,
     488,  1169,  1170,   324,   269,  1203,   477,   269,   844,  1209,
     361,   795,   325,   166,   476,   167,   298,  1359,   326,   168,
     349,  1360,   363,   169,   170,   171,   172,   559,   716,  1361,
     173,   174,  1409,  1362,   270,   352,  1410,   270,   175,   796,
     329,  1421,  1411,   477,   797,   362,  1412,   495,   330,   484,
      76,   352,   299,   550,   300,   301,  1414,   551,   331,   515,
    1415,   332,    77,  1431,   478,   431,   798,  1432,   867,   176,
     616,   177,   617,   358,   363,   618,   333,   178,   799,   619,
     800,   801,   179,    78,    79,   802,   334,   180,   836,   423,
      80,   440,   431,   664,   620,   621,   622,   302,   335,   303,
     623,   478,   485,   761,  1274,   730,   587,   510,   336,  1450,
     441,   551,   304,  1451,   754,   532,   442,   327,   624,   534,
     337,   338,   625,   626,   862,   339,   564,   340,   588,   589,
     341,   342,   486,   343,   344,   590,   345,   567,   487,   443,
     444,   513,   357,   803,   445,   369,    81,    82,   370,   804,
     371,   657,   372,   627,   305,   628,    83,    84,   446,   373,
     805,   806,   374,   375,   376,   447,   377,   378,   379,   629,
     807,   380,   241,   381,  1118,   382,    85,    86,   383,   384,
    1275,   306,   307,   385,   448,   386,   387,   546,   388,   565,
     630,   389,   390,    87,    88,   391,  1289,   392,   393,   394,
     395,   488,  1041,   396,    89,   397,   398,   399,   400,   241,
     402,  1276,   449,    90,   591,   592,   593,   404,   405,   594,
     450,   406,   631,   407,   408,  1277,   595,   242,   243,   244,
     245,   246,   247,   248,   249,   409,   632,   410,   451,   596,
     597,   411,   412,   572,  1278,  1279,   633,   452,   453,   413,
    1280,  1281,  1282,  1283,   414,   415,   598,   599,  1149,  1150,
    1151,  1152,  1153,  1284,   242,   243,   244,   245,   246,   247,
     248,   249,  1290,   416,   417,   418,   250,   419,   454,   455,
     420,   600,   876,   877,   878,   879,   880,   771,   772,   773,
     774,   775,   776,   777,    91,    92,    93,   421,   422,   496,
     497,   498,   499,  1291,  1166,   346,   566,  1433,   500,   501,
     251,   502,   503,   250,   504,   505,   506,  1292,   507,   634,
     511,   126,   512,   525,   526,   931,   527,   568,   127,   128,
     528,   529,   129,   456,   530,   531,  1293,  1294,   535,   130,
    1434,   536,  1295,  1296,  1297,  1298,   749,   251,   131,   537,
     538,  1435,   132,   133,   539,  1299,   540,   296,   541,   134,
     542,   910,   135,   136,   137,   543,   138,   544,  1436,   569,
     545,   570,   139,   571,   572,  1437,  1156,   575,   576,   577,
    1438,   578,  1439,   579,  1164,  1165,   252,   581,   582,   583,
     584,   140,   141,   297,   585,  1440,   142,   586,   655,   656,
     660,   659,   661,   143,   662,   666,   785,   144,   145,   146,
     786,   668,   147,   670,   671,   148,   149,   672,   673,   253,
     674,   675,   676,   252,   677,   678,   150,   508,  1441,   679,
     680,   787,   151,   152,   682,   153,   154,   155,   156,   681,
     686,   298,   684,   788,  1442,   687,   685,   688,   689,   157,
     690,   692,   696,   693,   789,   694,   253,   695,   158,   790,
     159,   160,  1443,   161,  1444,  1445,   162,   163,   697,   699,
     164,   791,   698,   700,   703,   705,   706,   299,   792,   300,
     301,   165,   707,   793,   716,   794,   712,   713,   719,   720,
     616,   723,   617,   725,   721,   618,    76,   722,   795,   619,
     166,   726,   167,   763,   764,   732,   168,   728,    77,   756,
     169,   170,   171,   172,   620,   621,   622,   173,   174,   729,
     623,   733,   302,   734,   303,   175,   796,  1446,   765,    78,
      79,   797,   766,   767,   735,   736,    80,   304,   624,   768,
     769,   738,   625,   626,  1447,   739,   770,   740,   778,   779,
     782,   780,   783,   798,  1448,   838,   176,   839,   177,   741,
     840,   781,   742,   743,   178,   799,   784,   800,   801,   179,
     744,   440,   802,   627,   180,   628,   841,   842,   843,   305,
     745,   846,   746,   847,   747,   748,   751,   753,   758,   629,
     441,   759,    81,    82,   760,   832,   442,   833,   845,   834,
     835,   848,    83,    84,   849,   850,   306,   307,   851,   852,
     630,   853,   587,   279,  1348,  1349,   854,   855,   856,   443,
     444,   933,    85,    86,   445,   857,   858,   859,   934,  1192,
     803,   861,     2,     3,   588,   589,   804,     4,   446,    87,
      88,   590,   631,   864,  1350,   447,  1218,   805,   806,   865,
      89,   897,   280,  1058,     5,   869,   632,   807,     6,    90,
     898,     7,  1351,   870,   448,   871,   633,   281,     8,  1352,
     872,   873,   874,   875,   883,   884,   885,   937,   886,   887,
     888,   889,   938,     9,   890,   891,   892,   893,  1353,   282,
     894,   283,   449,   284,   285,   895,    10,    11,   896,    12,
     450,  1042,   899,   900,   901,  1047,    13,   902,  1049,  1044,
     903,   904,  1045,   286,   905,   912,  1354,   906,   451,   907,
     591,   592,   593,    14,  1355,   594,   908,   452,   453,   909,
     913,   914,   595,   915,    15,   916,    16,   917,   918,   634,
      91,    92,    93,   919,   920,   596,   597,  1048,   921,   923,
     924,   925,    17,  1057,   926,   927,   928,   929,   454,   455,
     930,   935,   598,   599,  1356,   973,   974,   975,   976,    18,
     977,   978,   936,   979,   980,   981,   939,   940,   982,   941,
     942,   943,   944,  1357,   945,   946,   947,   600,   983,   984,
     985,   986,   987,   988,   948,   949,   989,   950,   951,   990,
     952,    19,   953,   954,   955,   956,   957,   958,   959,   960,
      20,    21,   961,   456,   962,    22,    23,   994,   995,   996,
     997,   963,   998,   999,   964,  1000,  1001,  1002,   965,   966,
    1003,   967,   968,   969,   970,   971,   972,   993,  1014,  1015,
    1004,  1005,  1006,  1007,  1008,  1009,  1016,  1017,  1010,  1050,
    1018,  1011,  1386,  1387,  1388,  1389,  1019,  1390,  1391,  1020,
    1392,  1393,  1394,  1021,  1022,  1395,  1052,  1053,  1023,  1024,
    1025,  1054,  1026,  1027,  1028,  1396,  1397,  1398,  1399,  1400,
    1401,  1034,  1035,  1402,  1036,  1037,  1403,  1055,  1038,  1039,
    1056,  1059,  1046,  1040,  1043,  1060,  1051,  1061,  1062,  1063,
    1064,  1065,  1066,  1067,  1068,  1069,  1070,  1071,  1074,  1075,
    1096,  1076,  1077,  1078,  1079,  1080,  1081,  1082,  1083,  1084,
    1085,  1086,  1087,  1088,  1089,  1090,  1091,  1120,  1121,  1092,
    1093,  1094,  1122,  1095,  1142,  1144,  1146,  1097,  1098,  1099,
    1101,  1102,  1103,  1104,  1105,  1106,  1107,  1108,  1109,  1110,
    1111,  1154,  1112,  1113,  1155,  1115,  1116,  1117,  1143,  1123,
    1124,  1125,  1126,  1127,  1128,  1129,  1130,  1131,  1132,  1133,
    1134,  1135,  1136,  1137,  1138,  1139,  1140,  1141,  1145,  1157,
    1148,  1158,  1147,  1159,  1160,  1161,  1162,  1163,  1167,  1168,
    1171,  1172,  1173,  1174,  1175,  1176,  1177,  1178,  1179,  1180,
    1181,  1183,  1182,  1244,  1184,  1187,  1247,  1185,  1188,  1189,
    1186,  1190,  1191,  1206,  1207,  1212,  1213,  1214,  1215,  1216,
    1217,  1222,  1223,  1224,  1225,  1226,  1227,  1228,  1248,  1234,
    1249,  1229,  1230,  1250,  1231,  1252,  1257,  1253,  1232,  1233,
    1237,  1242,  1243,  1259,  1263,  1267,  1251,  1265,  1269,  1270,
    1271,  1254,  1255,  1256,  1258,  1260,  1261,  1262,  1264,  1266,
    1268,  1272,  1273,  1287,  1288,  1302,  1303,  1325,  1304,  1305,
    1306,  1307,  1308,  1309,  1363,  1310,  1311,  1369,  1312,  1313,
    1314,  1315,  1316,  1317,  1318,  1319,   328,  1320,  1321,  1322,
    1458,  1457,  1119,  1456,  1364,  1323,  1429,   762,   547,   750,
    1427,   911,  1426,  1452,   868,   837,  1453,  1455,   863,  1454,
    1428,   932,   359,  1423,   665,   424,  1425,  1340,  1339,   755,
    1424,   347,  1324,  1329,     0,     0,  1330,  1331,  1332,     0,
    1333,  1334,  1335,  1336,  1365,  1366,  1367,     0,  1368,  1373,
    1374,  1375,  1376,  1377,   658,     0,     0,  1378,  1379,  1380,
    1381,  1382,  1383,  1384,  1385,  1406,  1407,  1408,   509,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   514,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   533
};

static const short int yycheck[] =
{
     333,   334,   417,     1,    10,     1,    12,   340,     1,   257,
      11,   257,     1,     1,    11,    77,     4,   257,     1,   255,
     256,    27,     1,     1,     1,    31,   255,     1,     1,   257,
     259,     8,     9,     1,   257,    12,   257,   370,     1,   372,
       1,   255,    19,     4,    22,   259,   194,   195,    22,     1,
       1,    28,     1,   386,   257,    32,    33,    45,    37,     1,
      48,   394,    39,   194,   195,    42,    43,    44,    47,    46,
       1,   404,   405,   255,   407,    52,     1,   259,   257,     1,
       1,   154,   415,   416,    45,   418,     1,    48,    37,    40,
     154,    54,   255,    99,    71,    72,   259,    90,    47,    76,
      14,    15,    16,   257,    55,   257,    83,    90,   257,     1,
      87,    88,    89,     5,   257,    92,   104,   257,    95,    96,
     255,    84,     1,   121,   259,   121,    77,    90,    79,   106,
      81,    82,   257,   121,    26,   112,   113,   154,   115,   116,
     117,   118,   121,   104,   257,   255,    38,   125,   121,   259,
     101,   125,   129,   121,  1029,  1030,  1031,    49,    37,    90,
     121,   138,    54,   140,   141,   257,   143,   156,   230,   146,
     147,   257,   121,   150,    66,    90,   255,   255,   156,   121,
     259,    73,   156,   156,   161,   257,    78,   185,    80,   185,
     153,   212,   213,   258,   119,   196,   185,   119,   531,   196,
     121,    93,   258,   180,   156,   182,    85,   255,   258,   186,
     257,   259,   185,   190,   191,   192,   193,   185,   132,   255,
     197,   198,   255,   259,   149,   156,   259,   149,   205,   121,
     258,   237,   255,   185,   126,   156,   259,   255,   258,     1,
       1,   156,   121,   185,   123,   124,   255,   243,   258,   257,
     259,   258,    13,   255,   243,   243,   148,   259,   256,   236,
       1,   238,     3,   256,   185,     6,   258,   244,   160,    10,
     162,   163,   249,    34,    35,   167,   258,   254,   256,   256,
      41,     1,   243,   256,    25,    26,    27,   166,   258,   168,
      31,   243,    54,   256,    93,   256,     1,   255,   258,   255,
      20,   243,   181,   259,   256,   256,    26,   256,    49,   255,
     258,   258,    53,    54,   256,   258,   154,   258,    23,    24,
     258,   258,    84,   258,   258,    30,   258,   255,    90,    49,
      50,   256,   258,   225,    54,   258,    97,    98,   258,   231,
     258,   256,   258,    84,   223,    86,   107,   108,    68,   258,
     242,   243,   258,   258,   258,    75,   258,   258,   258,   100,
     252,   258,     1,   258,   256,   258,   127,   128,   258,   258,
     169,   250,   251,   258,    94,   258,   258,   256,   258,   154,
     121,   258,   258,   144,   145,   258,    93,   258,   258,   258,
     258,   153,   725,   258,   155,   258,   258,   258,   258,     1,
     258,   200,   122,   164,   109,   110,   111,   258,   258,   114,
     130,   258,   153,   258,   258,   214,   121,    56,    57,    58,
      59,    60,    61,    62,    63,   258,   167,   258,   148,   134,
     135,   258,   258,   132,   233,   234,   177,   157,   158,   258,
     239,   240,   241,   242,   258,   258,   151,   152,   876,   877,
     878,   879,   880,   252,    56,    57,    58,    59,    60,    61,
      62,    63,   169,   258,   258,   258,   105,   258,   188,   189,
     258,   176,   171,   172,   173,   174,   175,   216,   217,   218,
     219,   220,   221,   222,   245,   246,   247,   258,   258,   258,
     258,   258,   258,   200,   909,   256,   154,     5,   258,   258,
     139,   258,   258,   105,   258,   258,   258,   214,   258,   250,
     258,     1,   258,   258,   258,   256,   258,   194,     8,     9,
     258,   258,    12,   243,   258,   258,   233,   234,   258,    19,
      38,   258,   239,   240,   241,   242,   256,   139,    28,   258,
     258,    49,    32,    33,   258,   252,   258,     1,   258,    39,
     258,   256,    42,    43,    44,   258,    46,   258,    66,   132,
     258,   132,    52,   194,   132,    73,   899,   132,   132,   194,
      78,   194,    80,   132,   907,   908,   215,   194,   194,   194,
     194,    71,    72,    37,   194,    93,    76,   255,   258,   258,
     255,   154,   258,    83,   258,   194,     1,    87,    88,    89,
       5,   194,    92,   132,   154,    95,    96,   132,   194,   248,
     194,   194,   132,   215,   154,   194,   106,   256,   126,   132,
     132,    26,   112,   113,   194,   115,   116,   117,   118,   132,
     132,    85,   194,    38,   142,   154,   194,   194,   132,   129,
     132,   132,   194,   154,    49,   132,   248,   132,   138,    54,
     140,   141,   160,   143,   162,   163,   146,   147,   194,   194,
     150,    66,   258,   258,   194,   154,   194,   121,    73,   123,
     124,   161,   194,    78,   132,    80,   194,   194,   194,   194,
       1,   255,     3,   258,   194,     6,     1,   194,    93,    10,
     180,   258,   182,   154,   154,   255,   186,   258,    13,   255,
     190,   191,   192,   193,    25,    26,    27,   197,   198,   258,
      31,   258,   166,   258,   168,   205,   121,   225,   154,    34,
      35,   126,   154,   154,   258,   258,    41,   181,    49,   154,
     154,   258,    53,    54,   242,   258,   154,   258,   154,   154,
     154,   194,   154,   148,   252,   194,   236,   194,   238,   258,
     194,   255,   258,   258,   244,   160,   255,   162,   163,   249,
     258,     1,   167,    84,   254,    86,   154,   194,   194,   223,
     258,   154,   258,   194,   258,   258,   258,   258,   258,   100,
      20,   258,    97,    98,   258,   255,    26,   258,   255,   258,
     258,   154,   107,   108,   154,   154,   250,   251,   154,   154,
     121,   154,     1,     1,    20,    21,   132,   154,   154,    49,
      50,   154,   127,   128,    54,   255,   255,   258,   154,   159,
     225,   258,     0,     1,    23,    24,   231,     5,    68,   144,
     145,    30,   153,   255,    50,    75,   131,   242,   243,   258,
     155,   258,    40,   132,    22,   255,   167,   252,    26,   164,
     258,    29,    68,   255,    94,   255,   177,    55,    36,    75,
     255,   255,   255,   255,   255,   255,   255,   154,   255,   255,
     255,   255,   154,    51,   255,   255,   255,   255,    94,    77,
     255,    79,   122,    81,    82,   255,    64,    65,   255,    67,
     130,   194,   258,   258,   258,   194,    74,   258,   194,   154,
     258,   258,   154,   101,   258,   255,   122,   258,   148,   258,
     109,   110,   111,    91,   130,   114,   258,   157,   158,   258,
     258,   258,   121,   258,   102,   258,   104,   258,   258,   250,
     245,   246,   247,   258,   258,   134,   135,   154,   258,   258,
     258,   258,   120,   154,   258,   258,   258,   258,   188,   189,
     258,   255,   151,   152,   170,   201,   202,   203,   204,   137,
     206,   207,   255,   209,   210,   211,   258,   255,   214,   255,
     255,   255,   255,   189,   255,   255,   255,   176,   224,   225,
     226,   227,   228,   229,   255,   255,   232,   255,   255,   235,
     255,   169,   255,   255,   255,   255,   255,   255,   255,   255,
     178,   179,   255,   243,   255,   183,   184,   201,   202,   203,
     204,   255,   206,   207,   255,   209,   210,   211,   255,   255,
     214,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     224,   225,   226,   227,   228,   229,   255,   255,   232,   194,
     255,   235,   201,   202,   203,   204,   255,   206,   207,   255,
     209,   210,   211,   255,   255,   214,   194,   194,   255,   255,
     255,   194,   255,   255,   255,   224,   225,   226,   227,   228,
     229,   255,   255,   232,   255,   255,   235,   194,   255,   255,
     194,   154,   255,   258,   258,   154,   258,   194,   154,   255,
     154,   258,   154,   255,   258,   154,   154,   132,   255,   255,
     258,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   154,   154,   255,
     255,   255,   154,   255,   154,   154,   154,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   132,   258,   258,   132,   258,   258,   258,   258,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   132,
     255,   132,   258,   132,   132,   154,   132,   132,   255,   154,
     194,   154,   154,   194,   194,   194,   154,   258,   154,   154,
     154,   132,   154,   199,   154,   255,   194,   154,   255,   255,
     154,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   154,   159,
     194,   255,   255,   194,   255,   194,   154,   194,   255,   255,
     255,   255,   255,   154,   154,   154,   258,   258,   255,   255,
     255,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   255,   255,   255,   255,   255,   255,   131,   255,   255,
     255,   255,   255,   255,   132,   255,   255,   131,   255,   255,
     255,   255,   255,   255,   255,   255,    71,   255,   255,   255,
    1451,  1432,   808,  1430,  1246,   255,  1362,   490,   308,   457,
    1347,   601,  1345,  1410,   560,   520,  1412,  1415,   552,  1413,
    1360,   635,   122,  1338,   365,   181,  1344,  1198,  1196,   480,
    1342,    94,   255,   255,    -1,    -1,   255,   255,   255,    -1,
     255,   255,   255,   255,   255,   255,   255,    -1,   255,   255,
     255,   255,   255,   255,   353,    -1,    -1,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   254,   432,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   271,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   287
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   261,     0,     1,     5,    22,    26,    29,    36,    51,
      64,    65,    67,    74,    91,   102,   104,   120,   137,   169,
     178,   179,   183,   184,   262,   267,   272,   286,   292,   307,
     344,   363,   376,   402,   409,   419,   428,   458,   468,   474,
     478,   488,   551,   567,   587,   255,   256,   257,   257,   345,
     429,   469,   257,   479,   257,   552,   377,   459,   364,   257,
     257,   308,   403,   257,   257,   410,   420,     1,    37,    47,
     121,   287,   288,   289,   290,   291,     1,    13,    34,    35,
      41,    97,    98,   107,   108,   127,   128,   144,   145,   155,
     164,   245,   246,   247,   568,   569,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   581,   582,   583,
     584,   585,   586,   154,   346,   350,   154,   430,   434,   257,
       1,    90,   475,   476,   477,   257,     1,     8,     9,    12,
      19,    28,    32,    33,    39,    42,    43,    44,    46,    52,
      71,    72,    76,    83,    87,    88,    89,    92,    95,    96,
     106,   112,   113,   115,   116,   117,   118,   129,   138,   140,
     141,   143,   146,   147,   150,   161,   180,   182,   186,   190,
     191,   192,   193,   197,   198,   205,   236,   238,   244,   249,
     254,   489,   490,   491,   492,   493,   494,   495,   496,   497,
     498,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   526,   527,
     528,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,   542,   546,   547,   548,   549,   550,   257,   257,   257,
     257,     1,    56,    57,    58,    59,    60,    61,    62,    63,
     105,   139,   215,   248,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,     1,   119,
     149,   268,   269,   270,   271,   154,   309,   313,   257,     1,
      40,    55,    77,    79,    81,    82,   101,   588,   589,   590,
     591,   592,   593,   594,   595,   596,     1,    37,    85,   121,
     123,   124,   166,   168,   181,   223,   250,   251,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   257,   257,   255,   258,   258,   258,   256,   288,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   256,   569,   257,   257,
       1,    90,   156,   470,   471,   472,   473,   258,   256,   476,
       1,   121,   156,   185,   480,   484,   485,   486,   487,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   543,   258,   539,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   256,   490,     1,     4,    45,    48,   104,
     121,   243,   553,   554,   555,   556,   557,   561,   562,   563,
       1,    20,    26,    49,    50,    54,    68,    75,    94,   122,
     130,   148,   157,   158,   188,   189,   243,   378,   379,   380,
     381,   382,   383,   384,   385,   392,   393,   394,   395,   396,
     397,   398,   399,   400,   401,     1,   156,   185,   243,   460,
     464,   465,   466,   467,     1,    54,    84,    90,   153,   365,
     369,   370,   371,   374,   375,   255,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   256,   294,
     255,   258,   258,   256,   269,   257,     1,    22,   125,   156,
     404,   405,   406,   407,   408,   258,   258,   258,   258,   258,
     258,   258,   256,   589,   255,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   256,   274,     1,   121,
     185,   243,   411,   412,   413,   414,   415,     1,   121,   185,
     421,   422,   423,   424,   154,   154,   154,   255,   194,   132,
     132,   194,   132,   264,   264,   132,   132,   194,   194,   132,
     264,   194,   194,   194,   194,   194,   255,     1,    23,    24,
      30,   109,   110,   111,   114,   121,   134,   135,   151,   152,
     176,   347,   348,   349,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,     1,     3,     6,    10,
      25,    26,    27,    31,    49,    53,    54,    84,    86,   100,
     121,   153,   167,   177,   250,   431,   432,   433,   435,   436,
     437,   438,   439,   440,   441,   442,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   258,   258,   256,   471,   154,
     255,   258,   258,   481,   256,   485,   194,   264,   194,   264,
     132,   154,   132,   194,   194,   194,   132,   154,   194,   132,
     132,   132,   194,   264,   194,   194,   132,   154,   194,   132,
     132,   264,   132,   154,   132,   132,   194,   194,   258,   194,
     258,   264,   264,   194,   264,   154,   194,   194,   194,   195,
     194,   195,   194,   194,   264,   264,   132,   266,   264,   194,
     194,   194,   194,   255,   564,   258,   258,   558,   258,   258,
     256,   554,   255,   258,   258,   258,   258,   386,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   256,
     379,   258,   461,   258,   256,   465,   255,   366,   258,   258,
     258,   256,   370,   154,   154,   154,   154,   154,   154,   154,
     154,   216,   217,   218,   219,   220,   221,   222,   154,   154,
     194,   255,   154,   154,   255,     1,     5,    26,    38,    49,
      54,    66,    73,    78,    80,    93,   121,   126,   148,   160,
     162,   163,   167,   225,   231,   242,   243,   252,   310,   311,
     312,   314,   315,   316,   317,   318,   319,   323,   324,   325,
     326,   327,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   255,   258,   258,   258,   256,   405,   194,   194,
     194,   154,   194,   194,   264,   255,   154,   194,   154,   154,
     154,   154,   154,   154,   132,   154,   154,   255,   255,   258,
     416,   258,   256,   412,   255,   258,   425,   256,   422,   255,
     255,   255,   255,   255,   255,   255,   171,   172,   173,   174,
     175,   263,   264,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     256,   348,   255,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   443,   258,   258,   258,   258,   258,   258,   258,
     258,   256,   432,   154,   154,   255,   255,   154,   154,   258,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   201,   202,   203,   204,   206,   207,   209,
     210,   211,   214,   224,   225,   226,   227,   228,   229,   232,
     235,   544,   545,   255,   201,   202,   203,   204,   206,   207,
     209,   210,   211,   214,   224,   225,   226,   227,   228,   229,
     232,   235,   540,   541,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,    14,
      15,    16,   265,   266,   255,   255,   255,   255,   255,   255,
     258,   264,   194,   258,   154,   154,   255,   194,   154,   194,
     194,   258,   194,   194,   194,   194,   194,   154,   132,   154,
     154,   194,   154,   255,   154,   258,   154,   255,   258,   154,
     154,   132,   372,   373,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   258,   258,   258,   258,
     338,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   320,   258,   258,   258,   256,   311,
     154,   154,   154,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   154,   258,   154,   255,   154,   258,   255,   263,
     263,   263,   263,   263,   132,   132,   264,   132,   132,   132,
     132,   154,   132,   132,   264,   264,   266,   255,   154,   212,
     213,   194,   154,   154,   194,   194,   194,   154,   258,   154,
     154,   154,   154,   132,   154,   154,   154,   255,   255,   255,
     255,   255,   159,   482,   483,   255,   259,   255,   259,   265,
     265,   265,    11,   196,   565,   566,   255,   255,    11,   196,
     559,   560,   255,   255,   255,   255,   255,   255,   131,   387,
     388,   390,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   159,   462,   463,   255,    77,   230,
     367,   368,   255,   255,   199,   255,   259,   194,   154,   194,
     194,   258,   194,   194,   194,   194,   194,   154,   194,   154,
     194,   194,   194,   154,   194,   258,   194,   154,   194,   255,
     255,   255,   255,   255,    93,   169,   200,   214,   233,   234,
     239,   240,   241,   242,   252,   417,   418,   255,   255,    93,
     169,   200,   214,   233,   234,   239,   240,   241,   242,   252,
     426,   427,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   131,   444,   445,   447,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   259,   545,
     541,   255,   259,   255,   259,   389,   255,   259,    20,    21,
      50,    68,    75,    94,   122,   130,   170,   189,   391,   255,
     259,   255,   259,   132,   373,   255,   255,   255,   255,   131,
     339,   340,   342,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   201,   202,   203,   204,
     206,   207,   209,   210,   211,   214,   224,   225,   226,   227,
     228,   229,   232,   235,   321,   322,   255,   255,   255,   255,
     259,   255,   259,   446,   255,   259,    10,    12,    27,    31,
      99,   237,   448,   483,   566,   560,   391,   388,   463,   368,
     341,   255,   259,     5,    38,    49,    66,    73,    78,    80,
      93,   126,   142,   160,   162,   163,   225,   242,   252,   343,
     255,   259,   418,   427,   448,   445,   343,   340,   322
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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
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
    while (0)
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
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

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
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
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
      size_t yyn = 0;
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

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
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
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
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
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
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

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


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
	short int *yyss1 = yyss;
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

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

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

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
#line 421 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
#line 423 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number);
		}
    break;

  case 29:
#line 427 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number);
		}
    break;

  case 30:
#line 431 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 + (yyvsp[0].number);
		}
    break;

  case 31:
#line 435 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 + (yyvsp[0].number);
		}
    break;

  case 32:
#line 439 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 + (yyvsp[0].number);
		}
    break;

  case 33:
#line 443 "ircd_parser.y"
    {
			(yyval.number) = (yyvsp[-2].number) * 60 * 60 * 24 * 7 + (yyvsp[0].number);
		}
    break;

  case 34:
#line 448 "ircd_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
#line 449 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-1].number) + (yyvsp[0].number); }
    break;

  case 37:
#line 450 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) + (yyvsp[0].number); }
    break;

  case 38:
#line 451 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 + (yyvsp[0].number); }
    break;

  case 39:
#line 452 "ircd_parser.y"
    { (yyval.number) = (yyvsp[-2].number) * 1024 * 1024 + (yyvsp[0].number); }
    break;

  case 46:
#line 466 "ircd_parser.y"
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
#line 483 "ircd_parser.y"
    {
#ifndef STATIC_MODULES
  if (ypass == 2)
    mod_add_path(yylval.string);
#endif
}
    break;

  case 63:
#line 507 "ircd_parser.y"
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
#line 541 "ircd_parser.y"
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
#line 601 "ircd_parser.y"
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
#line 615 "ircd_parser.y"
    {
  /* this isn't rehashable */
  if (ypass == 2 && !ServerInfo.sid)
  {
    if ((strlen(yylval.string) == IRC_MAXSID) && IsDigit(yylval.string[0])
	&& IsAlNum(yylval.string[1]) && IsAlNum(yylval.string[2]))
    {
      DupString(ServerInfo.sid, yylval.string);
    }
    else
    {
      ilog(L_ERROR, "Ignoring config file entry SID -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 67:
#line 633 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 68:
#line 642 "ircd_parser.y"
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
#line 656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 70:
#line 665 "ircd_parser.y"
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
#line 693 "ircd_parser.y"
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
#line 723 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    recalc_fdlimit(NULL);

    if ((yyvsp[-1].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
      yyerror(buf);
    }
    else if ((yyvsp[-1].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];
      ircsprintf(buf, "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
      yyerror(buf);
    }
    else
      ServerInfo.max_clients = (yyvsp[-1].number);
  }
}
    break;

  case 73:
#line 746 "ircd_parser.y"
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
#line 802 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 82:
#line 811 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 83:
#line 820 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 100:
#line 847 "ircd_parser.y"
    {
                        }
    break;

  case 101:
#line 851 "ircd_parser.y"
    {
                        }
    break;

  case 102:
#line 855 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.userlog, yylval.string,
            sizeof(ConfigLoggingEntry.userlog));
}
    break;

  case 103:
#line 862 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.failed_operlog, yylval.string,
            sizeof(ConfigLoggingEntry.failed_operlog));
}
    break;

  case 104:
#line 869 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operlog, yylval.string,
            sizeof(ConfigLoggingEntry.operlog));
}
    break;

  case 105:
#line 876 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.operspylog, yylval.string,
            sizeof(ConfigLoggingEntry.operspylog));
}
    break;

  case 106:
#line 883 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.glinelog, yylval.string,
            sizeof(ConfigLoggingEntry.glinelog));
}
    break;

  case 107:
#line 890 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.klinelog, yylval.string,
            sizeof(ConfigLoggingEntry.klinelog));
}
    break;

  case 108:
#line 897 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.ioerrlog, yylval.string,
            sizeof(ConfigLoggingEntry.ioerrlog));
}
    break;

  case 109:
#line 904 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(ConfigLoggingEntry.killlog, yylval.string,
            sizeof(ConfigLoggingEntry.killlog));
}
    break;

  case 110:
#line 911 "ircd_parser.y"
    { 
  if (ypass == 2)
    set_log_level(L_CRIT);
}
    break;

  case 111:
#line 915 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_ERROR);
}
    break;

  case 112:
#line 919 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_WARN);
}
    break;

  case 113:
#line 923 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_NOTICE);
}
    break;

  case 114:
#line 927 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_TRACE);
}
    break;

  case 115:
#line 931 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_INFO);
}
    break;

  case 116:
#line 935 "ircd_parser.y"
    {
  if (ypass == 2)
    set_log_level(L_DEBUG);
}
    break;

  case 117:
#line 941 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 118:
#line 950 "ircd_parser.y"
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
#line 963 "ircd_parser.y"
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
#line 1055 "ircd_parser.y"
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
#line 1067 "ircd_parser.y"
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
#line 1079 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = (struct CollectItem *)MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 150:
#line 1098 "ircd_parser.y"
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
#line 1110 "ircd_parser.y"
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
#line 1121 "ircd_parser.y"
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
#line 1163 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
#line 1172 "ircd_parser.y"
    {
  yy_aconf->modes = 0;
}
    break;

  case 158:
#line 1178 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
#line 1181 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
#line 1184 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 161:
#line 1187 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 162:
#line 1190 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 163:
#line 1193 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
#line 1196 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
#line 1199 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
#line 1202 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
#line 1205 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
#line 1208 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
#line 1211 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
#line 1214 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
#line 1217 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
#line 1220 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
#line 1223 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
#line 1226 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
#line 1229 "ircd_parser.y"
    {
  yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
#line 1234 "ircd_parser.y"
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
#line 1245 "ircd_parser.y"
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
#line 1256 "ircd_parser.y"
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
#line 1267 "ircd_parser.y"
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
#line 1278 "ircd_parser.y"
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
#line 1289 "ircd_parser.y"
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
#line 1300 "ircd_parser.y"
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
#line 1311 "ircd_parser.y"
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
#line 1322 "ircd_parser.y"
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
#line 1333 "ircd_parser.y"
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
#line 1344 "ircd_parser.y"
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
#line 1355 "ircd_parser.y"
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
#line 1366 "ircd_parser.y"
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
#line 1377 "ircd_parser.y"
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
#line 1388 "ircd_parser.y"
    {
}
    break;

  case 194:
#line 1392 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 196:
#line 1393 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 198:
#line 1396 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)yy_aconf->port &= ~OPER_FLAG_GLOBAL_KILL;
    else yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
  }
}
    break;

  case 199:
#line 1403 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTE;
    else yy_aconf->port |= OPER_FLAG_REMOTE;
  }
}
    break;

  case 200:
#line 1410 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_K;
    else yy_aconf->port |= OPER_FLAG_K;
  }
}
    break;

  case 201:
#line 1417 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_UNKLINE;
    else yy_aconf->port |= OPER_FLAG_UNKLINE;
  } 
}
    break;

  case 202:
#line 1424 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_X;
    else yy_aconf->port |= OPER_FLAG_X;
  }
}
    break;

  case 203:
#line 1431 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_GLINE;
    else yy_aconf->port |= OPER_FLAG_GLINE;
  }
}
    break;

  case 204:
#line 1438 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_DIE;
    else yy_aconf->port |= OPER_FLAG_DIE;
  }
}
    break;

  case 205:
#line 1445 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REHASH;
    else yy_aconf->port |= OPER_FLAG_REHASH;
  }
}
    break;

  case 206:
#line 1452 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_ADMIN;
    else yy_aconf->port |= OPER_FLAG_ADMIN;
  }
}
    break;

  case 207:
#line 1459 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_ADMIN;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_ADMIN;
  }
}
    break;

  case 208:
#line 1466 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_N;
    else yy_aconf->port |= OPER_FLAG_N;
  }
}
    break;

  case 209:
#line 1473 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPERWALL;
    else yy_aconf->port |= OPER_FLAG_OPERWALL;
  }
}
    break;

  case 210:
#line 1480 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_OPER_SPY;
    else yy_aconf->port |= OPER_FLAG_OPER_SPY;
  }
}
    break;

  case 211:
#line 1487 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_HIDDEN_OPER;
    else yy_aconf->port |= OPER_FLAG_HIDDEN_OPER;
  }
}
    break;

  case 212:
#line 1494 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->port &= ~OPER_FLAG_REMOTEBAN;
    else yy_aconf->port |= OPER_FLAG_REMOTEBAN;
  }
}
    break;

  case 213:
#line 1501 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) ClearConfEncrypted(yy_aconf);
    else SetConfEncrypted(yy_aconf);
  }
}
    break;

  case 214:
#line 1514 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = (struct ClassItem *)map_to_conf(yy_conf);
  }
}
    break;

  case 215:
#line 1521 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    struct ConfItem *cconf;
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
    {
      delete_conf_item(yy_conf);
    }
    else
    {
      cconf = find_exact_name_conf(CLASS_TYPE, yy_class_name, NULL, NULL);

      if (cconf != NULL)		/* The class existed already */
      {
        rebuild_cidr_class(cconf, yy_class);
        class = (struct ClassItem *) map_to_conf(cconf);
        *class = *yy_class;
        delete_conf_item(yy_conf);

        MyFree(cconf->name);            /* Allows case change of class name */
        cconf->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_conf->name);          /* just in case it was allocated */
        yy_conf->name = yy_class_name;
      }
    }
    yy_class_name = NULL;
  }
}
    break;

  case 234:
#line 1573 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 235:
#line 1582 "ircd_parser.y"
    {
  if (ypass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 236:
#line 1591 "ircd_parser.y"
    {
  if (ypass == 1)
    PingFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 237:
#line 1597 "ircd_parser.y"
    {
  if (ypass == 1)
    PingWarning(yy_class) = (yyvsp[-1].number);
}
    break;

  case 238:
#line 1603 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxPerIp(yy_class) = (yyvsp[-1].number);
}
    break;

  case 239:
#line 1609 "ircd_parser.y"
    {
  if (ypass == 1)
    ConFreq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 240:
#line 1615 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxTotal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 241:
#line 1621 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxGlobal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 242:
#line 1627 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxLocal(yy_class) = (yyvsp[-1].number);
}
    break;

  case 243:
#line 1633 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxIdent(yy_class) = (yyvsp[-1].number);
}
    break;

  case 244:
#line 1639 "ircd_parser.y"
    {
  if (ypass == 1)
    MaxSendq(yy_class) = (yyvsp[-1].number);
}
    break;

  case 245:
#line 1645 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV4(yy_class) = (yyvsp[-1].number);
}
    break;

  case 246:
#line 1651 "ircd_parser.y"
    {
  if (ypass == 1)
    CidrBitlenIPV6(yy_class) = (yyvsp[-1].number);
}
    break;

  case 247:
#line 1657 "ircd_parser.y"
    {
  if (ypass == 1)
    NumberPerCidr(yy_class) = (yyvsp[-1].number);
}
    break;

  case 248:
#line 1666 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 249:
#line 1673 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 250:
#line 1682 "ircd_parser.y"
    {
}
    break;

  case 254:
#line 1687 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 255:
#line 1691 "ircd_parser.y"
    {
  if (ypass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 266:
#line 1704 "ircd_parser.y"
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
    add_listener((yyvsp[0].number), listener_address, listener_flags);
    listener_flags = 0;
  }
}
    break;

  case 267:
#line 1719 "ircd_parser.y"
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

    for (i = (yyvsp[-2].number); i <= (yyvsp[0].number); ++i)
      add_listener(i, listener_address, listener_flags);

    listener_flags = 0;
  }
}
    break;

  case 268:
#line 1741 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 269:
#line 1750 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 270:
#line 1762 "ircd_parser.y"
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

  case 271:
#line 1774 "ircd_parser.y"
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

  case 291:
#line 1839 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp;

    if (yy_aconf->user == NULL)
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 292:
#line 1858 "ircd_parser.y"
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

  case 293:
#line 1871 "ircd_parser.y"
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

  case 294:
#line 1882 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 295:
#line 1891 "ircd_parser.y"
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

  case 296:
#line 1902 "ircd_parser.y"
    {
}
    break;

  case 300:
#line 1906 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 302:
#line 1907 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 304:
#line 1910 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_SPOOF_NOTICE;
    else yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
  }

}
    break;

  case 305:
#line 1918 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NOLIMIT;
    else yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
  }
}
    break;

  case 306:
#line 1925 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTKLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
  } 
}
    break;

  case 307:
#line 1932 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_IDENTD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
  }
}
    break;

  case 308:
#line 1939 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_CAN_FLOOD;
    else yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
  }
}
    break;

  case 309:
#line 1946 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_IDLE_LINED;
    else yy_aconf->flags |= CONF_FLAGS_IDLE_LINED;
  }
}
    break;

  case 310:
#line 1953 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NO_TILDE;
    else yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
  } 
}
    break;

  case 311:
#line 1960 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTGLINE;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
  } 
}
    break;

  case 312:
#line 1967 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_EXEMPTRESV;
    else yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
  }
}
    break;

  case 313:
#line 1974 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom) yy_aconf->flags &= ~CONF_FLAGS_NEED_PASSWORD;
    else yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
  }
}
    break;

  case 314:
#line 1983 "ircd_parser.y"
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

  case 315:
#line 1994 "ircd_parser.y"
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

  case 316:
#line 2005 "ircd_parser.y"
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

  case 317:
#line 2016 "ircd_parser.y"
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

  case 318:
#line 2027 "ircd_parser.y"
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

  case 319:
#line 2038 "ircd_parser.y"
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

  case 320:
#line 2050 "ircd_parser.y"
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

  case 321:
#line 2069 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 322:
#line 2079 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[-1].number);
  }
}
    break;

  case 323:
#line 2088 "ircd_parser.y"
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

  case 324:
#line 2103 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 325:
#line 2110 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 332:
#line 2122 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 333:
#line 2131 "ircd_parser.y"
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

  case 334:
#line 2146 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 335:
#line 2159 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 336:
#line 2167 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 343:
#line 2178 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 344:
#line 2187 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    split_nuh(yylval.string, NULL, &yy_match_item->user, &yy_match_item->host);
  }
}
    break;

  case 345:
#line 2195 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = 0;
}
    break;

  case 349:
#line 2202 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 350:
#line 2206 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TKLINE;
}
    break;

  case 351:
#line 2210 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 352:
#line 2214 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 353:
#line 2218 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TXLINE;
}
    break;

  case 354:
#line 2222 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 355:
#line 2226 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 356:
#line 2230 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_TRESV;
}
    break;

  case 357:
#line 2234 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 358:
#line 2238 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 359:
#line 2242 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 360:
#line 2251 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 361:
#line 2258 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 367:
#line 2271 "ircd_parser.y"
    {
  if (ypass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 368:
#line 2277 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = 0;
}
    break;

  case 372:
#line 2284 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 373:
#line 2288 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TKLINE;
}
    break;

  case 374:
#line 2292 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 375:
#line 2296 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 376:
#line 2300 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TXLINE;
}
    break;

  case 377:
#line 2304 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 378:
#line 2308 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 379:
#line 2312 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_TRESV;
}
    break;

  case 380:
#line 2316 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 381:
#line 2320 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 382:
#line 2324 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 383:
#line 2333 "ircd_parser.y"
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

  case 384:
#line 2351 "ircd_parser.y"
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
	  if (conf_add_server(yy_conf, scount, class_name) >= 0)
	  {
	    ++scount;
	  }
	  else
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

  case 408:
#line 2494 "ircd_parser.y"
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

  case 409:
#line 2506 "ircd_parser.y"
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

  case 410:
#line 2518 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 411:
#line 2527 "ircd_parser.y"
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

  case 412:
#line 2553 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
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

  case 413:
#line 2571 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if ((yyvsp[-1].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[-1].string), ' ') != NULL)
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

  case 414:
#line 2589 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->port = (yyvsp[-1].number);
}
    break;

  case 415:
#line 2595 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 416:
#line 2599 "ircd_parser.y"
    {
#ifdef IPV6
  if (ypass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 417:
#line 2607 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->fakename);
    DupString(yy_aconf->fakename, yylval.string);
  }
}
    break;

  case 418:
#line 2616 "ircd_parser.y"
    {
}
    break;

  case 422:
#line 2620 "ircd_parser.y"
    { not_atom = 1; }
    break;

  case 424:
#line 2621 "ircd_parser.y"
    { not_atom = 0; }
    break;

  case 426:
#line 2624 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfLazyLink(yy_aconf);
    else SetConfLazyLink(yy_aconf);
  }
}
    break;

  case 427:
#line 2631 "ircd_parser.y"
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

  case 428:
#line 2642 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfCryptLink(yy_aconf);
    else SetConfCryptLink(yy_aconf);
  }
}
    break;

  case 429:
#line 2649 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAllowAutoConn(yy_aconf);
    else SetConfAllowAutoConn(yy_aconf);
  }
}
    break;

  case 430:
#line 2656 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfAwayBurst(yy_aconf);
    else SetConfAwayBurst(yy_aconf);
  }
}
    break;

  case 431:
#line 2663 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (not_atom)ClearConfTopicBurst(yy_aconf);
    else SetConfTopicBurst(yy_aconf);
  }
}
    break;

  case 432:
#line 2673 "ircd_parser.y"
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

  case 433:
#line 2714 "ircd_parser.y"
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

  case 434:
#line 2725 "ircd_parser.y"
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

  case 435:
#line 2736 "ircd_parser.y"
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

  case 436:
#line 2751 "ircd_parser.y"
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

  case 437:
#line 2762 "ircd_parser.y"
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

  case 438:
#line 2775 "ircd_parser.y"
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

  case 439:
#line 2788 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 440:
#line 2797 "ircd_parser.y"
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

  case 441:
#line 2832 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 442:
#line 2839 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based K-Line: %s", errptr);
          break;
        }

        yy_conf = make_conf_item(RKLINE_TYPE);
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

  case 443:
#line 2893 "ircd_parser.y"
    {
}
    break;

  case 447:
#line 2898 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 454:
#line 2907 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    char *user = NULL, *host = NULL;

    split_nuh(yylval.string, NULL, &user, &host);

    strlcpy(userbuf, user, sizeof(userbuf));
    strlcpy(hostbuf, host, sizeof(hostbuf));

    MyFree(user);
    MyFree(host);
  }
}
    break;

  case 455:
#line 2923 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 456:
#line 2932 "ircd_parser.y"
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

  case 457:
#line 2941 "ircd_parser.y"
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

  case 463:
#line 2957 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 464:
#line 2966 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(yy_aconf->reason);
    DupString(yy_aconf->reason, yylval.string);
  }
}
    break;

  case 470:
#line 2983 "ircd_parser.y"
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

  case 471:
#line 3004 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 472:
#line 3011 "ircd_parser.y"
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
          ilog(L_ERROR, "Failed to add regular expression based X-Line: %s", errptr);
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

  case 473:
#line 3045 "ircd_parser.y"
    {
}
    break;

  case 477:
#line 3050 "ircd_parser.y"
    {
  if (ypass == 2)
    regex_ban = 1;
}
    break;

  case 484:
#line 3059 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 485:
#line 3065 "ircd_parser.y"
    {
  if (ypass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 544:
#line 3110 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[-1].number);
}
    break;

  case 545:
#line 3115 "ircd_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[-1].number);
}
    break;

  case 546:
#line 3120 "ircd_parser.y"
    {
  ConfigFileEntry.burst_away = yylval.number;
}
    break;

  case 547:
#line 3125 "ircd_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 548:
#line 3130 "ircd_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 549:
#line 3135 "ircd_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 550:
#line 3140 "ircd_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[-1].number);
}
    break;

  case 551:
#line 3145 "ircd_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 552:
#line 3150 "ircd_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 553:
#line 3155 "ircd_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 554:
#line 3160 "ircd_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 555:
#line 3165 "ircd_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 556:
#line 3170 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[-1].number); 
}
    break;

  case 557:
#line 3175 "ircd_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[-1].number);
}
    break;

  case 558:
#line 3180 "ircd_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[-1].number);
}
    break;

  case 559:
#line 3185 "ircd_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[-1].number);
}
    break;

  case 560:
#line 3190 "ircd_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[-1].number);
}
    break;

  case 561:
#line 3195 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[-1].number);
}
    break;

  case 562:
#line 3201 "ircd_parser.y"
    {
  if (((yyvsp[-1].number) > 0) && ypass == 1)
  {
    ilog(L_CRIT, "You haven't read your config file properly.");
    ilog(L_CRIT, "There is a line in the example conf that will kill your server if not removed.");
    ilog(L_CRIT, "Consider actually reading/editing the conf file, and removing this line.");
    exit(0);
  }
}
    break;

  case 563:
#line 3212 "ircd_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 564:
#line 3217 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 565:
#line 3226 "ircd_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 566:
#line 3231 "ircd_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 567:
#line 3236 "ircd_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 568:
#line 3241 "ircd_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 569:
#line 3246 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 570:
#line 3249 "ircd_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 571:
#line 3254 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 572:
#line 3257 "ircd_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 573:
#line 3262 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[-1].number);
}
    break;

  case 574:
#line 3267 "ircd_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[-1].number);
}
    break;

  case 575:
#line 3272 "ircd_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 576:
#line 3277 "ircd_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[-1].number);
}
    break;

  case 577:
#line 3282 "ircd_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 578:
#line 3287 "ircd_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 579:
#line 3292 "ircd_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 580:
#line 3297 "ircd_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 581:
#line 3302 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 582:
#line 3313 "ircd_parser.y"
    {
  ConfigFileEntry.idletime = (yyvsp[-1].number);
}
    break;

  case 583:
#line 3318 "ircd_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[-1].number);
}
    break;

  case 584:
#line 3323 "ircd_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[-1].number);
}
    break;

  case 585:
#line 3328 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.servlink_path);
    DupString(ConfigFileEntry.servlink_path, yylval.string);
  }
}
    break;

  case 586:
#line 3337 "ircd_parser.y"
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

  case 587:
#line 3369 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    ConfigFileEntry.compression_level = (yyvsp[-1].number);
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

  case 588:
#line 3387 "ircd_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 589:
#line 3392 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 590:
#line 3401 "ircd_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 591:
#line 3406 "ircd_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 592:
#line 3411 "ircd_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 593:
#line 3416 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 597:
#line 3422 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 598:
#line 3425 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 599:
#line 3428 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 600:
#line 3431 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 601:
#line 3434 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 602:
#line 3437 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 603:
#line 3440 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 604:
#line 3443 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 605:
#line 3446 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 606:
#line 3449 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 607:
#line 3452 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 608:
#line 3455 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 609:
#line 3458 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 610:
#line 3461 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 611:
#line 3464 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 612:
#line 3467 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 613:
#line 3470 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 614:
#line 3473 "ircd_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 615:
#line 3478 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 619:
#line 3484 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 620:
#line 3487 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 621:
#line 3490 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 622:
#line 3493 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 623:
#line 3496 "ircd_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 624:
#line 3499 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 625:
#line 3502 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 626:
#line 3505 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 627:
#line 3508 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 628:
#line 3511 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 629:
#line 3514 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 630:
#line 3517 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 631:
#line 3520 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 632:
#line 3523 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 633:
#line 3526 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 634:
#line 3529 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 635:
#line 3532 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 636:
#line 3535 "ircd_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 637:
#line 3540 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[-1].number);
}
    break;

  case 638:
#line 3545 "ircd_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[-1].number);
}
    break;

  case 639:
#line 3550 "ircd_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[-1].number);
}
    break;

  case 640:
#line 3555 "ircd_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[-1].number);
}
    break;

  case 641:
#line 3560 "ircd_parser.y"
    {
  ConfigFileEntry.dot_in_ip6_addr = yylval.number;
}
    break;

  case 642:
#line 3568 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 643:
#line 3575 "ircd_parser.y"
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

  case 653:
#line 3601 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 654:
#line 3607 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_time = (yyvsp[-1].number);
}
    break;

  case 655:
#line 3613 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 659:
#line 3619 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 660:
#line 3623 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 661:
#line 3629 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    struct CollectItem *yy_tmp = NULL;

    if (yy_aconf->user == NULL)
    {
      split_nuh(yylval.string, NULL, &yy_aconf->user, &yy_aconf->host);
    }
    else
    {
      yy_tmp = MyMalloc(sizeof(struct CollectItem));
      split_nuh(yylval.string, NULL, &yy_tmp->user, &yy_tmp->host);
      dlinkAdd(yy_tmp, &yy_tmp->node, &col_conf_list);
    }
  }
}
    break;

  case 662:
#line 3648 "ircd_parser.y"
    {
  if (ypass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 663:
#line 3657 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 664:
#line 3661 "ircd_parser.y"
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

  case 667:
#line 3708 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 668:
#line 3712 "ircd_parser.y"
    {
  if (ypass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 690:
#line 3736 "ircd_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 691:
#line 3741 "ircd_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 692:
#line 3746 "ircd_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 693:
#line 3751 "ircd_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 694:
#line 3756 "ircd_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 695:
#line 3761 "ircd_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[-1].number);
}
    break;

  case 696:
#line 3766 "ircd_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[-1].number);
}
    break;

  case 697:
#line 3771 "ircd_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[-1].number);
}
    break;

  case 698:
#line 3776 "ircd_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 699:
#line 3781 "ircd_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[-1].number);
}
    break;

  case 700:
#line 3786 "ircd_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[-1].number);
}
    break;

  case 701:
#line 3791 "ircd_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[-1].number);
}
    break;

  case 702:
#line 3796 "ircd_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 703:
#line 3801 "ircd_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 704:
#line 3806 "ircd_parser.y"
    {
  ConfigChannel.burst_topicwho = yylval.number;
}
    break;

  case 705:
#line 3811 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 706:
#line 3816 "ircd_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 718:
#line 3835 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 719:
#line 3841 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 720:
#line 3847 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 721:
#line 3856 "ircd_parser.y"
    {
  if (ypass == 2)
  {
    if (((yyvsp[-1].number) > 0) && ConfigServerHide.links_disabled == 1)
    {
      eventAddIsh("write_links_file", write_links_file, NULL, (yyvsp[-1].number));
      ConfigServerHide.links_disabled = 0;
    }

    ConfigServerHide.links_delay = (yyvsp[-1].number);
  }
}
    break;

  case 722:
#line 3870 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 723:
#line 3876 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 724:
#line 3882 "ircd_parser.y"
    {
  if (ypass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 7406 "y.tab.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
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
	  int yychecklim = YYLAST - yyn;
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
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
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
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
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
	  yydestruct ("Error: discarding", yytoken, &yylval);
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
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
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


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
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
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}



