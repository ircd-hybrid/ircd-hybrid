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



/* Line 268 of yacc.c  */
#line 157 "conf_parser.c"

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
     GLINES = 306,
     GLINE_EXEMPT = 307,
     GLINE_TIME = 308,
     GLINE_MIN_CIDR = 309,
     GLINE_MIN_CIDR6 = 310,
     GLOBAL_KILL = 311,
     IRCD_AUTH = 312,
     NEED_IDENT = 313,
     HAVENT_READ_CONF = 314,
     HIDDEN = 315,
     HIDDEN_NAME = 316,
     HIDE_SERVER_IPS = 317,
     HIDE_SERVERS = 318,
     HIDE_SPOOF_IPS = 319,
     HOST = 320,
     HUB = 321,
     HUB_MASK = 322,
     IGNORE_BOGUS_TS = 323,
     INVISIBLE_ON_CONNECT = 324,
     IP = 325,
     KILL = 326,
     KILL_CHASE_TIME_LIMIT = 327,
     KLINE = 328,
     KLINE_EXEMPT = 329,
     KLINE_REASON = 330,
     KLINE_WITH_REASON = 331,
     KNOCK_DELAY = 332,
     KNOCK_DELAY_CHANNEL = 333,
     LEAF_MASK = 334,
     LINKS_DELAY = 335,
     LISTEN = 336,
     T_LOG = 337,
     MAX_ACCEPT = 338,
     MAX_BANS = 339,
     MAX_CHANS_PER_USER = 340,
     MAX_GLOBAL = 341,
     MAX_IDENT = 342,
     MAX_LOCAL = 343,
     MAX_NICK_CHANGES = 344,
     MAX_NICK_TIME = 345,
     MAX_NUMBER = 346,
     MAX_TARGETS = 347,
     MAX_WATCH = 348,
     MESSAGE_LOCALE = 349,
     MIN_NONWILDCARD = 350,
     MIN_NONWILDCARD_SIMPLE = 351,
     MODULE = 352,
     MODULES = 353,
     NAME = 354,
     NEED_PASSWORD = 355,
     NETWORK_DESC = 356,
     NETWORK_NAME = 357,
     NICK = 358,
     NICK_CHANGES = 359,
     NO_CREATE_ON_SPLIT = 360,
     NO_JOIN_ON_SPLIT = 361,
     NO_OPER_FLOOD = 362,
     NO_TILDE = 363,
     NUMBER = 364,
     NUMBER_PER_IDENT = 365,
     NUMBER_PER_CIDR = 366,
     NUMBER_PER_IP = 367,
     NUMBER_PER_IP_GLOBAL = 368,
     OPERATOR = 369,
     OPERS_BYPASS_CALLERID = 370,
     OPER_ONLY_UMODES = 371,
     OPER_PASS_RESV = 372,
     OPER_SPY_T = 373,
     OPER_UMODES = 374,
     JOIN_FLOOD_COUNT = 375,
     JOIN_FLOOD_TIME = 376,
     PACE_WAIT = 377,
     PACE_WAIT_SIMPLE = 378,
     PASSWORD = 379,
     PATH = 380,
     PING_COOKIE = 381,
     PING_TIME = 382,
     PING_WARNING = 383,
     PORT = 384,
     QSTRING = 385,
     QUIET_ON_BAN = 386,
     REASON = 387,
     REDIRPORT = 388,
     REDIRSERV = 389,
     REGEX_T = 390,
     REHASH = 391,
     TREJECT_HOLD_TIME = 392,
     REMOTE = 393,
     REMOTEBAN = 394,
     RESTRICT_CHANNELS = 395,
     RESTRICTED = 396,
     RSA_PRIVATE_KEY_FILE = 397,
     RSA_PUBLIC_KEY_FILE = 398,
     SSL_CERTIFICATE_FILE = 399,
     SSL_DH_PARAM_FILE = 400,
     T_SSL_CLIENT_METHOD = 401,
     T_SSL_SERVER_METHOD = 402,
     T_SSLV3 = 403,
     T_TLSV1 = 404,
     RESV = 405,
     RESV_EXEMPT = 406,
     SECONDS = 407,
     MINUTES = 408,
     HOURS = 409,
     DAYS = 410,
     WEEKS = 411,
     SENDQ = 412,
     SEND_PASSWORD = 413,
     SERVERHIDE = 414,
     SERVERINFO = 415,
     IRCD_SID = 416,
     TKLINE_EXPIRE_NOTICES = 417,
     T_SHARED = 418,
     T_CLUSTER = 419,
     TYPE = 420,
     SHORT_MOTD = 421,
     SILENT = 422,
     SPOOF = 423,
     SPOOF_NOTICE = 424,
     STATS_E_DISABLED = 425,
     STATS_I_OPER_ONLY = 426,
     STATS_K_OPER_ONLY = 427,
     STATS_O_OPER_ONLY = 428,
     STATS_P_OPER_ONLY = 429,
     TBOOL = 430,
     TMASKED = 431,
     T_REJECT = 432,
     TS_MAX_DELTA = 433,
     TS_WARN_DELTA = 434,
     TWODOTS = 435,
     T_ALL = 436,
     T_BOTS = 437,
     T_SOFTCALLERID = 438,
     T_CALLERID = 439,
     T_CCONN = 440,
     T_CCONN_FULL = 441,
     T_SSL_CIPHER_LIST = 442,
     T_CLIENT_FLOOD = 443,
     T_DEAF = 444,
     T_DEBUG = 445,
     T_DLINE = 446,
     T_DRONE = 447,
     T_EXTERNAL = 448,
     T_FULL = 449,
     T_INVISIBLE = 450,
     T_IPV4 = 451,
     T_IPV6 = 452,
     T_LOCOPS = 453,
     T_MAX_CLIENTS = 454,
     T_NCHANGE = 455,
     T_OPERWALL = 456,
     T_REJ = 457,
     T_SERVER = 458,
     T_SERVNOTICE = 459,
     T_SKILL = 460,
     T_SPY = 461,
     T_SSL = 462,
     T_UMODES = 463,
     T_UNAUTH = 464,
     T_UNDLINE = 465,
     T_UNLIMITED = 466,
     T_UNRESV = 467,
     T_UNXLINE = 468,
     T_GLOBOPS = 469,
     T_WALLOP = 470,
     T_RESTART = 471,
     T_SERVICE = 472,
     T_SERVICES_NAME = 473,
     THROTTLE_TIME = 474,
     TOPICBURST = 475,
     TRUE_NO_OPER_FLOOD = 476,
     TKLINE = 477,
     TXLINE = 478,
     TRESV = 479,
     UNKLINE = 480,
     USER = 481,
     USE_EGD = 482,
     USE_EXCEPT = 483,
     USE_INVEX = 484,
     USE_KNOCK = 485,
     USE_LOGGING = 486,
     USE_WHOIS_ACTUALLY = 487,
     VHOST = 488,
     VHOST6 = 489,
     XLINE = 490,
     WARN = 491,
     WARN_NO_NLINE = 492,
     T_SIZE = 493,
     T_FILE = 494
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
#define GLINES 306
#define GLINE_EXEMPT 307
#define GLINE_TIME 308
#define GLINE_MIN_CIDR 309
#define GLINE_MIN_CIDR6 310
#define GLOBAL_KILL 311
#define IRCD_AUTH 312
#define NEED_IDENT 313
#define HAVENT_READ_CONF 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_SERVER_IPS 317
#define HIDE_SERVERS 318
#define HIDE_SPOOF_IPS 319
#define HOST 320
#define HUB 321
#define HUB_MASK 322
#define IGNORE_BOGUS_TS 323
#define INVISIBLE_ON_CONNECT 324
#define IP 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_REASON 330
#define KLINE_WITH_REASON 331
#define KNOCK_DELAY 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LINKS_DELAY 335
#define LISTEN 336
#define T_LOG 337
#define MAX_ACCEPT 338
#define MAX_BANS 339
#define MAX_CHANS_PER_USER 340
#define MAX_GLOBAL 341
#define MAX_IDENT 342
#define MAX_LOCAL 343
#define MAX_NICK_CHANGES 344
#define MAX_NICK_TIME 345
#define MAX_NUMBER 346
#define MAX_TARGETS 347
#define MAX_WATCH 348
#define MESSAGE_LOCALE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define NAME 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NICK_CHANGES 359
#define NO_CREATE_ON_SPLIT 360
#define NO_JOIN_ON_SPLIT 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_IDENT 365
#define NUMBER_PER_CIDR 366
#define NUMBER_PER_IP 367
#define NUMBER_PER_IP_GLOBAL 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define OPER_ONLY_UMODES 371
#define OPER_PASS_RESV 372
#define OPER_SPY_T 373
#define OPER_UMODES 374
#define JOIN_FLOOD_COUNT 375
#define JOIN_FLOOD_TIME 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PING_WARNING 383
#define PORT 384
#define QSTRING 385
#define QUIET_ON_BAN 386
#define REASON 387
#define REDIRPORT 388
#define REDIRSERV 389
#define REGEX_T 390
#define REHASH 391
#define TREJECT_HOLD_TIME 392
#define REMOTE 393
#define REMOTEBAN 394
#define RESTRICT_CHANNELS 395
#define RESTRICTED 396
#define RSA_PRIVATE_KEY_FILE 397
#define RSA_PUBLIC_KEY_FILE 398
#define SSL_CERTIFICATE_FILE 399
#define SSL_DH_PARAM_FILE 400
#define T_SSL_CLIENT_METHOD 401
#define T_SSL_SERVER_METHOD 402
#define T_SSLV3 403
#define T_TLSV1 404
#define RESV 405
#define RESV_EXEMPT 406
#define SECONDS 407
#define MINUTES 408
#define HOURS 409
#define DAYS 410
#define WEEKS 411
#define SENDQ 412
#define SEND_PASSWORD 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define IRCD_SID 416
#define TKLINE_EXPIRE_NOTICES 417
#define T_SHARED 418
#define T_CLUSTER 419
#define TYPE 420
#define SHORT_MOTD 421
#define SILENT 422
#define SPOOF 423
#define SPOOF_NOTICE 424
#define STATS_E_DISABLED 425
#define STATS_I_OPER_ONLY 426
#define STATS_K_OPER_ONLY 427
#define STATS_O_OPER_ONLY 428
#define STATS_P_OPER_ONLY 429
#define TBOOL 430
#define TMASKED 431
#define T_REJECT 432
#define TS_MAX_DELTA 433
#define TS_WARN_DELTA 434
#define TWODOTS 435
#define T_ALL 436
#define T_BOTS 437
#define T_SOFTCALLERID 438
#define T_CALLERID 439
#define T_CCONN 440
#define T_CCONN_FULL 441
#define T_SSL_CIPHER_LIST 442
#define T_CLIENT_FLOOD 443
#define T_DEAF 444
#define T_DEBUG 445
#define T_DLINE 446
#define T_DRONE 447
#define T_EXTERNAL 448
#define T_FULL 449
#define T_INVISIBLE 450
#define T_IPV4 451
#define T_IPV6 452
#define T_LOCOPS 453
#define T_MAX_CLIENTS 454
#define T_NCHANGE 455
#define T_OPERWALL 456
#define T_REJ 457
#define T_SERVER 458
#define T_SERVNOTICE 459
#define T_SKILL 460
#define T_SPY 461
#define T_SSL 462
#define T_UMODES 463
#define T_UNAUTH 464
#define T_UNDLINE 465
#define T_UNLIMITED 466
#define T_UNRESV 467
#define T_UNXLINE 468
#define T_GLOBOPS 469
#define T_WALLOP 470
#define T_RESTART 471
#define T_SERVICE 472
#define T_SERVICES_NAME 473
#define THROTTLE_TIME 474
#define TOPICBURST 475
#define TRUE_NO_OPER_FLOOD 476
#define TKLINE 477
#define TXLINE 478
#define TRESV 479
#define UNKLINE 480
#define USER 481
#define USE_EGD 482
#define USE_EXCEPT 483
#define USE_INVEX 484
#define USE_KNOCK 485
#define USE_LOGGING 486
#define USE_WHOIS_ACTUALLY 487
#define VHOST 488
#define VHOST6 489
#define XLINE 490
#define WARN 491
#define WARN_NO_NLINE 492
#define T_SIZE 493
#define T_FILE 494




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 293 of yacc.c  */
#line 678 "conf_parser.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 690 "conf_parser.c"

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
#define YYNTOKENS  245
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  304
/* YYNRULES -- Number of rules.  */
#define YYNRULES  666
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1306

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   494

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   244,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   240,
       2,   243,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   242,     2,   241,     2,     2,     2,     2,
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
     235,   236,   237,   238,   239
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    49,    52,    55,    56,    58,
      61,    65,    69,    73,    77,    81,    82,    84,    87,    91,
      95,    99,   105,   108,   110,   112,   114,   117,   122,   127,
     133,   136,   138,   140,   142,   144,   146,   148,   150,   152,
     154,   156,   158,   160,   162,   164,   166,   168,   171,   176,
     181,   185,   187,   189,   191,   195,   197,   199,   201,   206,
     211,   216,   221,   226,   231,   236,   241,   246,   251,   256,
     261,   266,   272,   275,   277,   279,   281,   283,   286,   291,
     296,   301,   307,   310,   312,   314,   316,   319,   324,   325,
     332,   335,   337,   339,   341,   343,   346,   351,   356,   361,
     362,   368,   372,   374,   376,   378,   380,   382,   384,   386,
     388,   389,   396,   399,   401,   403,   405,   407,   409,   411,
     413,   415,   417,   420,   425,   430,   435,   440,   445,   450,
     451,   457,   461,   463,   465,   467,   469,   471,   473,   475,
     477,   479,   481,   483,   485,   487,   489,   491,   493,   495,
     497,   499,   501,   503,   504,   510,   514,   516,   518,   520,
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
    1383,  1385,  1387,  1389,  1391,  1393,  1398,  1403,  1408,  1413,
    1418,  1423,  1428,  1433,  1438,  1443,  1448,  1453,  1458,  1463,
    1468,  1473,  1478,  1483,  1488,  1493,  1498,  1503,  1508,  1513,
    1518,  1523,  1528,  1533,  1538,  1543,  1548,  1553,  1558,  1563,
    1568,  1573,  1578,  1583,  1588,  1593,  1598,  1603,  1608,  1613,
    1618,  1623,  1628,  1629,  1635,  1639,  1641,  1643,  1645,  1647,
    1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,
    1669,  1671,  1673,  1675,  1677,  1679,  1681,  1682,  1688,  1692,
    1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1730,  1732,
    1734,  1739,  1744,  1749,  1754,  1755,  1762,  1765,  1767,  1769,
    1771,  1773,  1775,  1777,  1779,  1781,  1786,  1791,  1792,  1798,
    1802,  1804,  1806,  1808,  1813,  1818,  1819,  1825,  1829,  1831,
    1833,  1835,  1841,  1844,  1846,  1848,  1850,  1852,  1854,  1856,
    1858,  1860,  1862,  1864,  1866,  1868,  1870,  1872,  1874,  1876,
    1878,  1880,  1882,  1887,  1892,  1897,  1902,  1907,  1912,  1917,
    1922,  1927,  1932,  1937,  1942,  1947,  1952,  1957,  1962,  1967,
    1973,  1976,  1978,  1980,  1982,  1984,  1986,  1988,  1990,  1992,
    1994,  1999,  2004,  2009,  2014,  2019,  2024
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     246,     0,    -1,    -1,   246,   247,    -1,   279,    -1,   285,
      -1,   299,    -1,   519,    -1,   317,    -1,   334,    -1,   348,
      -1,   257,    -1,   539,    -1,   363,    -1,   370,    -1,   374,
      -1,   384,    -1,   393,    -1,   413,    -1,   423,    -1,   429,
      -1,   443,    -1,   503,    -1,   433,    -1,   252,    -1,     1,
     240,    -1,     1,   241,    -1,    -1,   249,    -1,   109,   248,
      -1,   109,   152,   248,    -1,   109,   153,   248,    -1,   109,
     154,   248,    -1,   109,   155,   248,    -1,   109,   156,   248,
      -1,    -1,   251,    -1,   109,   250,    -1,   109,    13,   250,
      -1,   109,    14,   250,    -1,   109,    15,   250,    -1,    98,
     242,   253,   241,   240,    -1,   253,   254,    -1,   254,    -1,
     255,    -1,   256,    -1,     1,   240,    -1,    97,   243,   130,
     240,    -1,   125,   243,   130,   240,    -1,   160,   242,   258,
     241,   240,    -1,   258,   259,    -1,   259,    -1,   270,    -1,
     275,    -1,   278,    -1,   272,    -1,   273,    -1,   274,    -1,
     277,    -1,   268,    -1,   267,    -1,   276,    -1,   271,    -1,
     266,    -1,   260,    -1,   261,    -1,   269,    -1,     1,   240,
      -1,   146,   243,   262,   240,    -1,   147,   243,   264,   240,
      -1,   262,   244,   263,    -1,   263,    -1,   148,    -1,   149,
      -1,   264,   244,   265,    -1,   265,    -1,   148,    -1,   149,
      -1,   144,   243,   130,   240,    -1,   142,   243,   130,   240,
      -1,   145,   243,   130,   240,    -1,   187,   243,   130,   240,
      -1,    99,   243,   130,   240,    -1,   161,   243,   130,   240,
      -1,    30,   243,   130,   240,    -1,   102,   243,   130,   240,
      -1,   101,   243,   130,   240,    -1,   233,   243,   130,   240,
      -1,   234,   243,   130,   240,    -1,   199,   243,   109,   240,
      -1,    66,   243,   175,   240,    -1,     5,   242,   280,   241,
     240,    -1,   280,   281,    -1,   281,    -1,   282,    -1,   284,
      -1,   283,    -1,     1,   240,    -1,    99,   243,   130,   240,
      -1,    40,   243,   130,   240,    -1,    30,   243,   130,   240,
      -1,    82,   242,   286,   241,   240,    -1,   286,   287,    -1,
     287,    -1,   288,    -1,   289,    -1,     1,   240,    -1,   231,
     243,   175,   240,    -1,    -1,   290,   239,   242,   291,   241,
     240,    -1,   291,   292,    -1,   292,    -1,   293,    -1,   295,
      -1,   294,    -1,     1,   240,    -1,    99,   243,   130,   240,
      -1,   238,   243,   251,   240,    -1,   238,   243,   211,   240,
      -1,    -1,   165,   296,   243,   297,   240,    -1,   297,   244,
     298,    -1,   298,    -1,   226,    -1,   114,    -1,    50,    -1,
     191,    -1,    73,    -1,    71,    -1,   190,    -1,    -1,   114,
     300,   242,   301,   241,   240,    -1,   301,   302,    -1,   302,
      -1,   303,    -1,   304,    -1,   305,    -1,   309,    -1,   308,
      -1,   306,    -1,   307,    -1,   313,    -1,     1,   240,    -1,
      99,   243,   130,   240,    -1,   226,   243,   130,   240,    -1,
     124,   243,   130,   240,    -1,    42,   243,   175,   240,    -1,
     143,   243,   130,   240,    -1,    23,   243,   130,   240,    -1,
      -1,   208,   310,   243,   311,   240,    -1,   311,   244,   312,
      -1,   312,    -1,   182,    -1,   185,    -1,   186,    -1,   189,
      -1,   190,    -1,   194,    -1,    60,    -1,   205,    -1,   200,
      -1,   202,    -1,   209,    -1,   206,    -1,   193,    -1,   201,
      -1,   204,    -1,   195,    -1,   215,    -1,   183,    -1,   184,
      -1,   198,    -1,    -1,    46,   314,   243,   315,   240,    -1,
     315,   244,   316,    -1,   316,    -1,    56,    -1,   138,    -1,
      73,    -1,   225,    -1,   191,    -1,   210,    -1,   235,    -1,
      50,    -1,    31,    -1,   216,    -1,   136,    -1,     5,    -1,
     104,    -1,   201,    -1,   214,    -1,   118,    -1,   139,    -1,
      97,    -1,    -1,    23,   318,   242,   319,   241,   240,    -1,
     319,   320,    -1,   320,    -1,   321,    -1,   331,    -1,   332,
      -1,   322,    -1,   323,    -1,   333,    -1,   324,    -1,   325,
      -1,   326,    -1,   327,    -1,   328,    -1,   329,    -1,   330,
      -1,     1,   240,    -1,    99,   243,   130,   240,    -1,   127,
     243,   249,   240,    -1,   128,   243,   249,   240,    -1,   112,
     243,   109,   240,    -1,    25,   243,   249,   240,    -1,    91,
     243,   109,   240,    -1,    86,   243,   109,   240,    -1,    88,
     243,   109,   240,    -1,    87,   243,   109,   240,    -1,   157,
     243,   251,   240,    -1,    21,   243,   109,   240,    -1,    22,
     243,   109,   240,    -1,   111,   243,   109,   240,    -1,    -1,
      81,   335,   242,   340,   241,   240,    -1,    -1,    46,   337,
     243,   338,   240,    -1,   338,   244,   339,    -1,   339,    -1,
     207,    -1,    60,    -1,   203,    -1,   340,   341,    -1,   341,
      -1,   342,    -1,   336,    -1,   346,    -1,   347,    -1,     1,
     240,    -1,    -1,   129,   243,   344,   343,   240,    -1,   344,
     244,   345,    -1,   345,    -1,   109,    -1,   109,   180,   109,
      -1,    70,   243,   130,   240,    -1,    65,   243,   130,   240,
      -1,    -1,    57,   349,   242,   350,   241,   240,    -1,   350,
     351,    -1,   351,    -1,   352,    -1,   353,    -1,   354,    -1,
     356,    -1,   360,    -1,   361,    -1,   362,    -1,   355,    -1,
       1,   240,    -1,   226,   243,   130,   240,    -1,   124,   243,
     130,   240,    -1,    23,   243,   130,   240,    -1,    42,   243,
     175,   240,    -1,    -1,    46,   357,   243,   358,   240,    -1,
     358,   244,   359,    -1,   359,    -1,   169,    -1,    43,    -1,
      74,    -1,    58,    -1,    19,    -1,   108,    -1,    52,    -1,
     151,    -1,   100,    -1,   168,   243,   130,   240,    -1,   134,
     243,   130,   240,    -1,   133,   243,   109,   240,    -1,    -1,
     150,   364,   242,   365,   241,   240,    -1,   365,   366,    -1,
     366,    -1,   367,    -1,   368,    -1,   369,    -1,     1,   240,
      -1,   132,   243,   130,   240,    -1,    20,   243,   130,   240,
      -1,   103,   243,   130,   240,    -1,   217,   242,   371,   241,
     240,    -1,   371,   372,    -1,   372,    -1,   373,    -1,     1,
      -1,    99,   243,   130,   240,    -1,    -1,   163,   375,   242,
     376,   241,   240,    -1,   376,   377,    -1,   377,    -1,   378,
      -1,   379,    -1,   380,    -1,     1,   240,    -1,    99,   243,
     130,   240,    -1,   226,   243,   130,   240,    -1,    -1,   165,
     381,   243,   382,   240,    -1,   382,   244,   383,    -1,   383,
      -1,    73,    -1,   225,    -1,   191,    -1,   210,    -1,   235,
      -1,   213,    -1,   150,    -1,   212,    -1,   198,    -1,   181,
      -1,    -1,   164,   385,   242,   386,   241,   240,    -1,   386,
     387,    -1,   387,    -1,   388,    -1,   389,    -1,     1,   240,
      -1,    99,   243,   130,   240,    -1,    -1,   165,   390,   243,
     391,   240,    -1,   391,   244,   392,    -1,   392,    -1,    73,
      -1,   225,    -1,   191,    -1,   210,    -1,   235,    -1,   213,
      -1,   150,    -1,   212,    -1,   198,    -1,   181,    -1,    -1,
      24,   394,   242,   395,   241,   240,    -1,   395,   396,    -1,
     396,    -1,   397,    -1,   398,    -1,   399,    -1,   400,    -1,
     401,    -1,   403,    -1,   402,    -1,   412,    -1,   404,    -1,
     409,    -1,   410,    -1,   411,    -1,   408,    -1,     1,   240,
      -1,    99,   243,   130,   240,    -1,    65,   243,   130,   240,
      -1,   233,   243,   130,   240,    -1,   158,   243,   130,   240,
      -1,     3,   243,   130,   240,    -1,   129,   243,   109,   240,
      -1,     6,   243,   196,   240,    -1,     6,   243,   197,   240,
      -1,    -1,    46,   405,   243,   406,   240,    -1,   406,   244,
     407,    -1,   407,    -1,    10,    -1,    12,    -1,   220,    -1,
     207,    -1,    42,   243,   175,   240,    -1,    67,   243,   130,
     240,    -1,    79,   243,   130,   240,    -1,    23,   243,   130,
     240,    -1,   187,   243,   130,   240,    -1,    -1,    71,   414,
     242,   419,   241,   240,    -1,    -1,   165,   416,   243,   417,
     240,    -1,   417,   244,   418,    -1,   418,    -1,   135,    -1,
     419,   420,    -1,   420,    -1,   421,    -1,   422,    -1,   415,
      -1,     1,    -1,   226,   243,   130,   240,    -1,   132,   243,
     130,   240,    -1,    -1,    29,   424,   242,   425,   241,   240,
      -1,   425,   426,    -1,   426,    -1,   427,    -1,   428,    -1,
       1,    -1,    70,   243,   130,   240,    -1,   132,   243,   130,
     240,    -1,    44,   242,   430,   241,   240,    -1,   430,   431,
      -1,   431,    -1,   432,    -1,     1,    -1,    70,   243,   130,
     240,    -1,    -1,    48,   434,   242,   439,   241,   240,    -1,
      -1,   165,   436,   243,   437,   240,    -1,   437,   244,   438,
      -1,   438,    -1,   135,    -1,   439,   440,    -1,   440,    -1,
     441,    -1,   442,    -1,   435,    -1,     1,    -1,    99,   243,
     130,   240,    -1,   132,   243,   130,   240,    -1,    49,   242,
     444,   241,   240,    -1,   444,   445,    -1,   445,    -1,   453,
      -1,   454,    -1,   456,    -1,   457,    -1,   458,    -1,   459,
      -1,   460,    -1,   461,    -1,   462,    -1,   463,    -1,   452,
      -1,   465,    -1,   466,    -1,   467,    -1,   468,    -1,   483,
      -1,   470,    -1,   472,    -1,   474,    -1,   473,    -1,   477,
      -1,   471,    -1,   478,    -1,   479,    -1,   480,    -1,   481,
      -1,   482,    -1,   495,    -1,   484,    -1,   485,    -1,   486,
      -1,   491,    -1,   475,    -1,   476,    -1,   501,    -1,   499,
      -1,   500,    -1,   455,    -1,   502,    -1,   490,    -1,   464,
      -1,   488,    -1,   489,    -1,   451,    -1,   447,    -1,   448,
      -1,   449,    -1,   450,    -1,   469,    -1,   446,    -1,   487,
      -1,     1,    -1,    93,   243,   109,   240,    -1,    54,   243,
     109,   240,    -1,    55,   243,   109,   240,    -1,   232,   243,
     175,   240,    -1,   137,   243,   249,   240,    -1,   162,   243,
     175,   240,    -1,    72,   243,   249,   240,    -1,    64,   243,
     175,   240,    -1,    68,   243,   175,   240,    -1,    36,   243,
     175,   240,    -1,    45,   243,   175,   240,    -1,     8,   243,
     175,   240,    -1,    90,   243,   249,   240,    -1,    89,   243,
     109,   240,    -1,    83,   243,   109,   240,    -1,     9,   243,
     249,   240,    -1,   179,   243,   249,   240,    -1,   178,   243,
     249,   240,    -1,    59,   243,   109,   240,    -1,    76,   243,
     175,   240,    -1,    75,   243,   130,   240,    -1,    69,   243,
     175,   240,    -1,   237,   243,   175,   240,    -1,   170,   243,
     175,   240,    -1,   173,   243,   175,   240,    -1,   174,   243,
     175,   240,    -1,   172,   243,   175,   240,    -1,   172,   243,
     176,   240,    -1,   171,   243,   175,   240,    -1,   171,   243,
     176,   240,    -1,   122,   243,   249,   240,    -1,    18,   243,
     249,   240,    -1,   115,   243,   175,   240,    -1,   123,   243,
     249,   240,    -1,   166,   243,   175,   240,    -1,   107,   243,
     175,   240,    -1,   221,   243,   175,   240,    -1,   117,   243,
     175,   240,    -1,    94,   243,   130,   240,    -1,    37,   243,
     109,   240,    -1,    92,   243,   109,   240,    -1,   227,   243,
     175,   240,    -1,    39,   243,   130,   240,    -1,   218,   243,
     130,   240,    -1,   126,   243,   175,   240,    -1,    32,   243,
     175,   240,    -1,   219,   243,   249,   240,    -1,    -1,   119,
     492,   243,   493,   240,    -1,   493,   244,   494,    -1,   494,
      -1,   182,    -1,   185,    -1,   186,    -1,   189,    -1,   190,
      -1,   194,    -1,    60,    -1,   205,    -1,   200,    -1,   202,
      -1,   209,    -1,   206,    -1,   193,    -1,   201,    -1,   204,
      -1,   195,    -1,   215,    -1,   183,    -1,   184,    -1,   198,
      -1,    -1,   116,   496,   243,   497,   240,    -1,   497,   244,
     498,    -1,   498,    -1,   182,    -1,   185,    -1,   186,    -1,
     189,    -1,   190,    -1,   194,    -1,   205,    -1,    60,    -1,
     200,    -1,   202,    -1,   209,    -1,   206,    -1,   193,    -1,
     201,    -1,   204,    -1,   195,    -1,   215,    -1,   183,    -1,
     184,    -1,   198,    -1,    95,   243,   109,   240,    -1,    96,
     243,   109,   240,    -1,    26,   243,   109,   240,    -1,   188,
     243,   251,   240,    -1,    -1,    51,   504,   242,   505,   241,
     240,    -1,   505,   506,    -1,   506,    -1,   507,    -1,   508,
      -1,   509,    -1,   513,    -1,   514,    -1,   515,    -1,     1,
      -1,    41,   243,   175,   240,    -1,    38,   243,   249,   240,
      -1,    -1,    82,   510,   243,   511,   240,    -1,   511,   244,
     512,    -1,   512,    -1,   177,    -1,    11,    -1,   226,   243,
     130,   240,    -1,    99,   243,   130,   240,    -1,    -1,     4,
     516,   243,   517,   240,    -1,   517,   244,   518,    -1,   518,
      -1,   177,    -1,    11,    -1,    20,   242,   520,   241,   240,
      -1,   520,   521,    -1,   521,    -1,   524,    -1,   525,    -1,
     526,    -1,   527,    -1,   532,    -1,   528,    -1,   529,    -1,
     530,    -1,   531,    -1,   533,    -1,   534,    -1,   535,    -1,
     523,    -1,   536,    -1,   537,    -1,   538,    -1,   522,    -1,
       1,    -1,    33,   243,   175,   240,    -1,   140,   243,   175,
     240,    -1,    35,   243,   175,   240,    -1,   228,   243,   175,
     240,    -1,   229,   243,   175,   240,    -1,   230,   243,   175,
     240,    -1,    77,   243,   249,   240,    -1,    78,   243,   249,
     240,    -1,    85,   243,   109,   240,    -1,   131,   243,   175,
     240,    -1,    84,   243,   109,   240,    -1,    28,   243,   109,
     240,    -1,    27,   243,   109,   240,    -1,   105,   243,   175,
     240,    -1,   106,   243,   175,   240,    -1,   120,   243,   109,
     240,    -1,   121,   243,   249,   240,    -1,   159,   242,   540,
     241,   240,    -1,   540,   541,    -1,   541,    -1,   542,    -1,
     543,    -1,   545,    -1,   547,    -1,   546,    -1,   544,    -1,
     548,    -1,     1,    -1,    47,   243,   175,   240,    -1,    63,
     243,   175,   240,    -1,    61,   243,   130,   240,    -1,    80,
     243,   249,   240,    -1,    60,   243,   175,   240,    -1,    34,
     243,   175,   240,    -1,    62,   243,   175,   240,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   353,   353,   354,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   383,   383,   384,
     388,   392,   396,   400,   404,   410,   410,   411,   412,   413,
     414,   421,   424,   424,   425,   425,   425,   427,   433,   440,
     442,   442,   443,   443,   444,   444,   445,   445,   446,   446,
     447,   447,   448,   448,   449,   449,   450,   451,   454,   455,
     457,   457,   458,   464,   472,   472,   473,   479,   487,   526,
     585,   613,   621,   636,   651,   660,   674,   683,   711,   741,
     764,   773,   775,   775,   776,   776,   777,   777,   779,   788,
     797,   809,   810,   810,   812,   812,   813,   815,   822,   822,
     832,   833,   835,   835,   836,   836,   838,   843,   846,   852,
     851,   857,   857,   858,   862,   866,   870,   874,   878,   882,
     893,   892,   990,   990,   991,   991,   991,   992,   992,   992,
     993,   993,   993,   995,  1004,  1041,  1053,  1064,  1106,  1116,
    1115,  1121,  1121,  1122,  1126,  1130,  1134,  1138,  1142,  1146,
    1150,  1154,  1158,  1162,  1166,  1170,  1174,  1178,  1182,  1186,
    1190,  1194,  1198,  1205,  1204,  1210,  1210,  1211,  1215,  1219,
    1223,  1227,  1231,  1235,  1239,  1243,  1247,  1251,  1255,  1259,
    1263,  1267,  1271,  1275,  1279,  1290,  1289,  1339,  1339,  1340,
    1341,  1341,  1342,  1343,  1344,  1345,  1346,  1347,  1348,  1349,
    1350,  1351,  1352,  1354,  1363,  1369,  1375,  1381,  1387,  1393,
    1399,  1405,  1411,  1417,  1423,  1429,  1439,  1438,  1455,  1454,
    1459,  1459,  1460,  1464,  1468,  1476,  1476,  1477,  1477,  1477,
    1477,  1477,  1479,  1479,  1481,  1481,  1483,  1497,  1517,  1526,
    1539,  1538,  1607,  1607,  1608,  1608,  1608,  1608,  1609,  1609,
    1609,  1610,  1610,  1612,  1647,  1660,  1669,  1681,  1680,  1684,
    1684,  1685,  1689,  1693,  1697,  1701,  1705,  1709,  1713,  1717,
    1724,  1743,  1753,  1767,  1766,  1782,  1782,  1783,  1783,  1783,
    1783,  1785,  1794,  1809,  1822,  1824,  1824,  1825,  1825,  1827,
    1843,  1842,  1858,  1858,  1859,  1859,  1859,  1859,  1861,  1870,
    1893,  1892,  1898,  1898,  1899,  1903,  1907,  1911,  1915,  1919,
    1923,  1927,  1931,  1935,  1945,  1944,  1961,  1961,  1962,  1962,
    1962,  1964,  1971,  1970,  1976,  1976,  1977,  1981,  1985,  1989,
    1993,  1997,  2001,  2005,  2009,  2013,  2023,  2022,  2073,  2073,
    2074,  2074,  2074,  2075,  2075,  2076,  2076,  2076,  2077,  2077,
    2077,  2078,  2078,  2079,  2081,  2090,  2099,  2125,  2143,  2161,
    2167,  2171,  2180,  2179,  2183,  2183,  2184,  2188,  2192,  2196,
    2202,  2213,  2224,  2235,  2244,  2263,  2262,  2328,  2327,  2331,
    2331,  2332,  2338,  2338,  2339,  2339,  2339,  2339,  2341,  2360,
    2370,  2369,  2394,  2394,  2395,  2395,  2395,  2397,  2403,  2412,
    2414,  2414,  2415,  2415,  2417,  2436,  2435,  2483,  2482,  2486,
    2486,  2487,  2493,  2493,  2494,  2494,  2494,  2494,  2496,  2502,
    2511,  2514,  2514,  2515,  2515,  2516,  2516,  2517,  2517,  2518,
    2518,  2519,  2519,  2520,  2520,  2521,  2521,  2522,  2522,  2523,
    2523,  2524,  2524,  2525,  2525,  2526,  2526,  2527,  2527,  2528,
    2529,  2529,  2530,  2530,  2531,  2531,  2532,  2532,  2533,  2533,
    2534,  2535,  2536,  2536,  2537,  2538,  2539,  2539,  2540,  2540,
    2541,  2541,  2542,  2542,  2543,  2546,  2551,  2556,  2561,  2566,
    2571,  2576,  2581,  2586,  2591,  2596,  2601,  2606,  2611,  2616,
    2621,  2626,  2631,  2637,  2648,  2653,  2662,  2667,  2672,  2677,
    2682,  2687,  2690,  2695,  2698,  2703,  2708,  2713,  2718,  2723,
    2728,  2733,  2738,  2743,  2754,  2759,  2764,  2769,  2778,  2787,
    2792,  2797,  2803,  2802,  2807,  2807,  2808,  2811,  2814,  2817,
    2820,  2823,  2826,  2829,  2832,  2835,  2838,  2841,  2844,  2847,
    2850,  2853,  2856,  2859,  2862,  2865,  2871,  2870,  2875,  2875,
    2876,  2879,  2882,  2885,  2888,  2891,  2894,  2897,  2900,  2903,
    2906,  2909,  2912,  2915,  2918,  2921,  2924,  2927,  2930,  2933,
    2938,  2943,  2948,  2953,  2963,  2962,  2986,  2986,  2987,  2988,
    2989,  2990,  2991,  2992,  2993,  2995,  3001,  3008,  3007,  3012,
    3012,  3013,  3017,  3023,  3057,  3067,  3066,  3116,  3116,  3117,
    3121,  3130,  3133,  3133,  3134,  3134,  3135,  3135,  3136,  3136,
    3137,  3137,  3138,  3138,  3139,  3140,  3140,  3141,  3142,  3142,
    3143,  3143,  3145,  3150,  3155,  3160,  3165,  3170,  3175,  3180,
    3185,  3190,  3195,  3200,  3205,  3210,  3215,  3220,  3225,  3233,
    3236,  3236,  3237,  3237,  3238,  3239,  3240,  3240,  3241,  3242,
    3244,  3250,  3256,  3265,  3279,  3285,  3291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "GLINE", "GLINES", "GLINE_EXEMPT", "GLINE_TIME", "GLINE_MIN_CIDR",
  "GLINE_MIN_CIDR6", "GLOBAL_KILL", "IRCD_AUTH", "NEED_IDENT",
  "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME", "HIDE_SERVER_IPS",
  "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB", "HUB_MASK",
  "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_IDENT", "NUMBER_PER_CIDR", "NUMBER_PER_IP",
  "NUMBER_PER_IP_GLOBAL", "OPERATOR", "OPERS_BYPASS_CALLERID",
  "OPER_ONLY_UMODES", "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES",
  "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE",
  "PASSWORD", "PATH", "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT",
  "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T",
  "REHASH", "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RESTRICTED", "RSA_PRIVATE_KEY_FILE",
  "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE",
  "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1",
  "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SILENT", "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED",
  "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY",
  "STATS_P_OPER_ONLY", "TBOOL", "TMASKED", "T_REJECT", "TS_MAX_DELTA",
  "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS", "T_SOFTCALLERID",
  "T_CALLERID", "T_CCONN", "T_CCONN_FULL", "T_SSL_CIPHER_LIST",
  "T_CLIENT_FLOOD", "T_DEAF", "T_DEBUG", "T_DLINE", "T_DRONE",
  "T_EXTERNAL", "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS",
  "T_MAX_CLIENTS", "T_NCHANGE", "T_OPERWALL", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES", "T_UNAUTH",
  "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE", "T_GLOBOPS",
  "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME", "THROTTLE_TIME",
  "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE", "TRESV",
  "UNKLINE", "USER", "USE_EGD", "USE_EXCEPT", "USE_INVEX", "USE_KNOCK",
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
  "WARN_NO_NLINE", "T_SIZE", "T_FILE", "';'", "'}'", "'{'", "'='", "','",
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
  "general_gline_min_cidr", "general_gline_min_cidr6",
  "general_use_whois_actually", "general_reject_hold_time",
  "general_tkline_expire_notices", "general_kill_chase_time_limit",
  "general_hide_spoof_ips", "general_ignore_bogus_ts",
  "general_disable_remote_commands", "general_failed_oper_notice",
  "general_anti_nick_flood", "general_max_nick_time",
  "general_max_nick_changes", "general_max_accept",
  "general_anti_spam_exit_message_time", "general_ts_warn_delta",
  "general_ts_max_delta", "general_havent_read_conf",
  "general_kline_with_reason", "general_kline_reason",
  "general_invisible_on_connect", "general_warn_no_nline",
  "general_stats_e_disabled", "general_stats_o_oper_only",
  "general_stats_P_oper_only", "general_stats_k_oper_only",
  "general_stats_i_oper_only", "general_pace_wait",
  "general_caller_id_wait", "general_opers_bypass_callerid",
  "general_pace_wait_simple", "general_short_motd",
  "general_no_oper_flood", "general_true_no_oper_flood",
  "general_oper_pass_resv", "general_message_locale",
  "general_dots_in_ident", "general_max_targets", "general_use_egd",
  "general_egdpool_path", "general_services_name", "general_ping_cookie",
  "general_disable_auth", "general_throttle_time", "general_oper_umodes",
  "$@24", "umode_oitems", "umode_oitem", "general_oper_only_umodes",
  "$@25", "umode_items", "umode_item", "general_min_nonwildcard",
  "general_min_nonwildcard_simple", "general_default_floodcount",
  "general_client_flood", "gline_entry", "$@26", "gline_items",
  "gline_item", "gline_enable", "gline_duration", "gline_logging", "$@27",
  "gline_logging_types", "gline_logging_type_item", "gline_user",
  "gline_server", "gline_action", "$@28", "gdeny_types", "gdeny_type_item",
  "channel_entry", "channel_items", "channel_item",
  "channel_disable_fake_channels", "channel_restrict_channels",
  "channel_disable_local_channels", "channel_use_except",
  "channel_use_invex", "channel_use_knock", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
  "serverhide_links_delay", "serverhide_hidden",
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
      59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   245,   246,   246,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   249,
     249,   249,   249,   249,   249,   250,   250,   251,   251,   251,
     251,   252,   253,   253,   254,   254,   254,   255,   256,   257,
     258,   258,   259,   259,   259,   259,   259,   259,   259,   259,
     259,   259,   259,   259,   259,   259,   259,   259,   260,   261,
     262,   262,   263,   263,   264,   264,   265,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   280,   280,   281,   281,   281,   281,   282,   283,
     284,   285,   286,   286,   287,   287,   287,   288,   290,   289,
     291,   291,   292,   292,   292,   292,   293,   294,   294,   296,
     295,   297,   297,   298,   298,   298,   298,   298,   298,   298,
     300,   299,   301,   301,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   303,   304,   305,   306,   307,   308,   310,
     309,   311,   311,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,   312,   312,
     312,   312,   312,   314,   313,   315,   315,   316,   316,   316,
     316,   316,   316,   316,   316,   316,   316,   316,   316,   316,
     316,   316,   316,   316,   316,   318,   317,   319,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,   331,   332,   333,   335,   334,   337,   336,
     338,   338,   339,   339,   339,   340,   340,   341,   341,   341,
     341,   341,   343,   342,   344,   344,   345,   345,   346,   347,
     349,   348,   350,   350,   351,   351,   351,   351,   351,   351,
     351,   351,   351,   352,   353,   354,   355,   357,   356,   358,
     358,   359,   359,   359,   359,   359,   359,   359,   359,   359,
     360,   361,   362,   364,   363,   365,   365,   366,   366,   366,
     366,   367,   368,   369,   370,   371,   371,   372,   372,   373,
     375,   374,   376,   376,   377,   377,   377,   377,   378,   379,
     381,   380,   382,   382,   383,   383,   383,   383,   383,   383,
     383,   383,   383,   383,   385,   384,   386,   386,   387,   387,
     387,   388,   390,   389,   391,   391,   392,   392,   392,   392,
     392,   392,   392,   392,   392,   392,   394,   393,   395,   395,
     396,   396,   396,   396,   396,   396,   396,   396,   396,   396,
     396,   396,   396,   396,   397,   398,   399,   400,   401,   402,
     403,   403,   405,   404,   406,   406,   407,   407,   407,   407,
     408,   409,   410,   411,   412,   414,   413,   416,   415,   417,
     417,   418,   419,   419,   420,   420,   420,   420,   421,   422,
     424,   423,   425,   425,   426,   426,   426,   427,   428,   429,
     430,   430,   431,   431,   432,   434,   433,   436,   435,   437,
     437,   438,   439,   439,   440,   440,   440,   440,   441,   442,
     443,   444,   444,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   445,   445,   445,   445,   445,
     445,   445,   445,   445,   445,   446,   447,   448,   449,   450,
     451,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   472,   473,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   492,   491,   493,   493,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   494,   494,   494,   494,
     494,   494,   494,   494,   494,   494,   496,   495,   497,   497,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   498,   498,
     499,   500,   501,   502,   504,   503,   505,   505,   506,   506,
     506,   506,   506,   506,   506,   507,   508,   510,   509,   511,
     511,   512,   512,   513,   514,   516,   515,   517,   517,   518,
     518,   519,   520,   520,   521,   521,   521,   521,   521,   521,
     521,   521,   521,   521,   521,   521,   521,   521,   521,   521,
     521,   521,   522,   523,   524,   525,   526,   527,   528,   529,
     530,   531,   532,   533,   534,   535,   536,   537,   538,   539,
     540,   540,   541,   541,   541,   541,   541,   541,   541,   541,
     542,   543,   544,   545,   546,   547,   548
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     0,     1,     2,
       3,     3,     3,     3,     3,     0,     1,     2,     3,     3,
       3,     5,     2,     1,     1,     1,     2,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       3,     1,     1,     1,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     2,     4,     4,
       4,     5,     2,     1,     1,     1,     2,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
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
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     0,     5,     3,     1,     1,
       1,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   346,   400,     0,
     415,     0,   584,   250,   385,   226,     0,     0,   130,   283,
       0,     0,   300,   324,     0,     3,    24,    11,     4,     5,
       6,     8,     9,    10,    13,    14,    15,    16,    17,    18,
      19,    20,    23,    21,    22,     7,    12,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    96,    95,   631,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   613,   630,
     626,   614,   615,   616,   617,   619,   620,   621,   622,   618,
     623,   624,   625,   627,   628,   629,     0,     0,     0,   413,
       0,     0,   411,   412,     0,   484,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   556,     0,   532,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   432,   482,
     477,   478,   479,   480,   476,   443,   433,   434,   470,   435,
     436,   437,   438,   439,   440,   441,   442,   473,   444,   445,
     446,   447,   481,   449,   454,   450,   452,   451,   465,   466,
     453,   455,   456,   457,   458,   459,   448,   461,   462,   463,
     483,   474,   475,   472,   464,   460,   468,   469,   467,   471,
       0,     0,     0,     0,     0,     0,     0,   103,   104,   105,
       0,     0,     0,     0,     0,    43,    44,    45,     0,     0,
     659,     0,     0,     0,     0,     0,     0,     0,     0,   651,
     652,   653,   657,   654,   656,   655,   658,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    51,    64,    65,    63,    60,    59,
      66,    52,    62,    55,    56,    57,    53,    61,    58,    54,
       0,     0,   298,     0,     0,   296,   297,    97,     0,     0,
       0,     0,    92,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   200,   201,
     204,     0,     0,     0,     0,     0,   372,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,   350,   351,   352,
     353,   354,   356,   355,   358,   362,   359,   360,   361,   357,
     406,     0,     0,     0,   403,   404,   405,     0,     0,   410,
     427,     0,     0,   417,   426,     0,   423,   424,   425,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   431,   594,   605,     0,     0,   597,     0,     0,     0,
     587,   588,   589,   590,   591,   592,   593,     0,     0,     0,
     267,     0,     0,     0,     0,     0,     0,   253,   254,   255,
     256,   261,   257,   258,   259,   260,   397,     0,   387,     0,
     396,     0,   393,   394,   395,     0,   228,     0,     0,     0,
     238,     0,   236,   237,   239,   240,   106,     0,     0,   102,
       0,    46,     0,     0,     0,    42,     0,     0,     0,   173,
       0,     0,     0,   149,     0,     0,   133,   134,   135,   136,
     139,   140,   138,   137,   141,     0,     0,     0,     0,     0,
     286,   287,   288,   289,     0,     0,     0,     0,     0,     0,
       0,     0,   650,    67,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,     0,     0,   310,     0,     0,   303,   304,   305,   306,
       0,     0,   332,     0,   327,   328,   329,     0,     0,   295,
       0,     0,     0,    91,     0,     0,     0,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   611,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,   402,     0,
     409,     0,     0,     0,     0,   422,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
     430,     0,     0,     0,     0,     0,     0,     0,   586,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   392,   241,     0,     0,     0,     0,
       0,   235,     0,   101,     0,     0,     0,    41,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   132,   290,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,     0,   649,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,     0,    71,    76,    77,     0,    75,     0,
       0,     0,     0,     0,    49,   307,     0,     0,     0,     0,
     302,   330,     0,     0,     0,   326,     0,   294,   100,    99,
      98,   644,   643,   632,   634,    27,    27,    27,    27,    27,
      29,    28,   638,   639,   642,   640,   645,   646,   647,   648,
     641,   633,   635,   636,   637,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   347,     0,     0,   401,   414,     0,     0,
       0,   416,   496,   500,   516,   582,   530,   494,   524,   527,
     495,   486,   487,   503,   492,   493,   506,   491,   505,   504,
     499,   498,   497,   525,   485,   523,   580,   581,   520,   517,
     567,   560,   577,   578,   561,   562,   563,   564,   572,   565,
     575,   579,   568,   573,   569,   574,   566,   571,   570,   576,
       0,   559,   522,   542,   536,   553,   554,   537,   538,   539,
     540,   548,   541,   551,   555,   544,   549,   545,   550,   543,
     547,   546,   552,     0,   535,   515,   518,   529,   489,   490,
     519,   508,   513,   514,   511,   512,   509,   510,   502,   501,
      35,    35,    35,    37,    36,   583,   528,   531,   521,   526,
     488,   507,     0,     0,     0,     0,     0,     0,   585,     0,
       0,     0,     0,     0,     0,     0,     0,   251,     0,     0,
       0,   386,     0,     0,     0,   246,   242,   245,   227,   107,
       0,     0,   119,     0,     0,   111,   112,   114,   113,    47,
      48,     0,     0,     0,     0,     0,     0,     0,     0,   131,
       0,     0,     0,   284,   665,   660,   664,   662,   666,   661,
     663,    84,    90,    82,    86,    85,    79,    78,    80,    68,
       0,    69,     0,    83,    81,    89,    87,    88,     0,     0,
       0,   301,     0,     0,   325,   299,    30,    31,    32,    33,
      34,   223,   224,   217,   219,   221,   220,   218,   213,   225,
     216,   214,   215,   222,   368,   370,   371,   383,   380,   376,
     377,   379,   378,     0,   375,   365,   381,   382,   364,   369,
     367,   384,   366,   407,   408,   428,   429,   421,     0,   420,
     557,     0,   533,     0,    38,    39,    40,   610,   609,     0,
     608,   596,   595,   602,   601,     0,   600,   604,   603,   265,
     266,   275,   272,   277,   274,   273,   279,   276,   278,   271,
       0,   270,   264,   282,   281,   280,   263,   399,   391,     0,
     390,   398,   233,   234,   232,     0,   231,   249,   248,     0,
       0,     0,   115,     0,     0,     0,     0,   110,   148,   146,
     188,   185,   184,   177,   179,   194,   189,   192,   187,   178,
     193,   181,   190,   182,   191,   186,   180,   183,     0,   176,
     143,   145,   147,   159,   153,   170,   171,   154,   155,   156,
     157,   165,   158,   168,   172,   161,   166,   162,   167,   160,
     164,   163,   169,     0,   152,   144,   292,   293,   291,    70,
      74,   308,   314,   320,   323,   316,   322,   317,   321,   319,
     315,   318,     0,   313,   309,   331,   336,   342,   345,   338,
     344,   339,   343,   341,   337,   340,     0,   335,   373,     0,
     418,     0,   558,   534,   606,     0,   598,     0,   268,     0,
     388,     0,   229,     0,   247,   244,   243,     0,     0,     0,
       0,   109,   174,     0,   150,     0,   311,     0,   333,     0,
     374,   419,   607,   599,   269,   389,   230,   116,   125,   128,
     127,   124,   129,   126,   123,     0,   122,   118,   117,   175,
     151,   312,   334,   120,     0,   121
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    25,   830,   831,   973,   974,    26,   244,   245,
     246,   247,    27,   283,   284,   285,   286,   793,   794,   797,
     798,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,    28,    74,    75,    76,    77,    78,
      29,   236,   237,   238,   239,   240,  1014,  1015,  1016,  1017,
    1018,  1164,  1295,  1296,    30,    63,   535,   536,   537,   538,
     539,   540,   541,   542,   543,   765,  1213,  1214,   544,   761,
    1188,  1189,    31,    51,   346,   347,   348,   349,   350,   351,
     352,   353,   354,   355,   356,   357,   358,   359,   360,    32,
      60,   510,   746,  1155,  1156,   511,   512,   513,  1161,  1006,
    1007,   514,   515,    33,    58,   486,   487,   488,   489,   490,
     491,   492,   732,  1140,  1141,   493,   494,   495,    34,    64,
     549,   550,   551,   552,   553,    35,   304,   305,   306,    36,
      67,   585,   586,   587,   588,   589,   807,  1232,  1233,    37,
      68,   593,   594,   595,   596,   813,  1246,  1247,    38,    52,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     644,  1093,  1094,   385,   386,   387,   388,   389,    39,    59,
     500,   741,  1149,  1150,   501,   502,   503,   504,    40,    53,
     393,   394,   395,   396,    41,   121,   122,   123,    42,    55,
     404,   663,  1108,  1109,   405,   406,   407,   408,    43,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   439,   953,   954,
     225,   437,   930,   931,   226,   227,   228,   229,    44,    57,
     469,   470,   471,   472,   473,   724,  1125,  1126,   474,   475,
     476,   721,  1119,  1120,    45,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,    46,   258,   259,   260,   261,   262,
     263,   264,   265,   266
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -872
static const yytype_int16 yypact[] =
{
    -872,   684,  -872,  -194,  -227,  -225,  -872,  -872,  -872,  -207,
    -872,  -202,  -872,  -872,  -872,  -872,  -190,  -185,  -872,  -872,
    -182,  -174,  -872,  -872,  -166,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,    11,
     596,  -152,  -133,  -131,    10,  -128,   420,  -125,  -122,  -111,
     -97,     2,    66,   -76,   -61,   339,   379,   -48,   -35,     5,
    -212,   -25,   -18,    -3,     4,  -872,  -872,  -872,  -872,  -872,
      29,    40,    57,    63,    72,    82,    90,    92,   108,   113,
     121,   127,   146,   149,   150,   153,   154,   196,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,   693,   505,    26,  -872,
     160,    80,  -872,  -872,    54,  -872,   168,   179,   184,   187,
     190,   192,   193,   197,   200,   201,   205,   206,   207,   208,
     210,   215,   218,   220,   223,   224,   225,   227,   228,   230,
     234,   239,   240,   242,  -872,   243,  -872,   247,   254,   255,
     256,   258,   262,   264,   274,   275,   276,   277,   279,   287,
     289,   290,   301,   302,   306,   307,   309,   120,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
     129,   308,    22,    32,   -20,   310,    36,  -872,  -872,  -872,
      16,   138,   311,   312,    15,  -872,  -872,  -872,   348,   328,
    -872,   316,   318,   322,   324,   325,   326,   330,     9,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,   155,   333,   334,
     336,   337,   338,   344,   345,   352,   353,   357,   358,   359,
     360,   362,   364,   221,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
     172,    35,  -872,   366,    38,  -872,  -872,  -872,   280,   304,
     374,   199,  -872,   298,   355,   396,   435,   502,   502,   506,
     507,   439,   442,   509,   502,   444,   445,   446,   450,   451,
     387,  -872,   388,   389,   390,   393,   397,   399,   400,   401,
     402,   405,   406,   407,   410,   411,   177,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,   416,   415,   417,   419,   421,  -872,   422,   424,   425,
     427,   432,   436,   443,   447,    19,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,   448,   453,    37,  -872,  -872,  -872,   529,   438,  -872,
    -872,   456,   457,  -872,  -872,    17,  -872,  -872,  -872,   512,
     502,   502,   573,   513,   518,   597,   575,   534,   610,   612,
     613,   548,   550,   551,   502,   600,   556,   628,   630,   502,
     631,   633,   614,   636,   637,   576,   577,   510,   581,   514,
     502,   502,   584,   502,   585,   586,   587,   -83,   -53,   588,
     592,   502,   502,   639,   620,   502,   594,   595,   598,   599,
     531,  -872,  -872,  -872,   532,   535,  -872,   540,   542,    44,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,   536,   543,   544,
    -872,   545,   546,   547,   552,   553,     8,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,   554,  -872,   557,
    -872,    28,  -872,  -872,  -872,   537,  -872,   558,   559,   560,
    -872,    18,  -872,  -872,  -872,  -872,  -872,   616,   566,  -872,
     565,  -872,   663,   664,   568,  -872,   569,   567,   570,  -872,
     571,   572,   574,  -872,   579,   261,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,   578,   580,   589,   590,    12,
    -872,  -872,  -872,  -872,   641,   644,   652,   681,   653,   654,
     502,   591,  -872,  -872,   682,   655,   705,   706,   707,   708,
     709,   710,   164,   235,   711,   712,   736,   716,   719,   617,
    -872,   621,   622,  -872,   623,     6,  -872,  -872,  -872,  -872,
     632,   625,  -872,    20,  -872,  -872,  -872,   726,   640,  -872,
     642,   643,   645,  -872,   651,   656,   660,   667,   260,   671,
     672,   674,   675,   676,   677,   678,   680,   686,   687,   690,
     691,   695,  -872,  -872,   751,   767,   502,   768,   770,   772,
     783,   765,   794,   827,   502,   502,   639,   698,  -872,  -872,
     812,   191,   816,   774,   713,   817,   820,   821,   822,   844,
     825,   828,   829,   717,  -872,   830,   831,   722,  -872,   723,
    -872,   834,   835,   724,   728,  -872,   729,   730,   731,   732,
     733,   734,   735,   737,   738,   740,   741,   742,   743,   744,
     745,   746,   747,   748,   749,   750,   752,   753,   754,   755,
     756,   757,   758,   759,   669,   760,   704,   761,   762,   763,
     764,   766,   769,   771,   773,   775,   776,   777,   778,   779,
     780,   781,   282,   782,   784,   785,   786,   787,   788,   789,
    -872,   790,   502,   791,   792,   846,   849,   796,  -872,  -872,
     861,   832,   795,   875,   899,   880,   882,   884,   797,  -872,
     893,   798,   900,   799,  -872,  -872,   800,   901,   902,   925,
     802,  -872,   804,  -872,   167,   805,   806,  -872,  -872,   910,
     872,   807,   918,   919,   921,   809,   923,   814,  -872,  -872,
     926,   927,   928,   815,  -872,   819,   823,   824,   826,   833,
     836,   837,  -872,   838,   839,   840,   841,   842,   843,   845,
     847,  -872,  -872,  -214,  -872,  -872,  -872,  -191,  -872,   848,
     850,   851,   852,   853,  -872,  -872,   930,   818,   932,   854,
    -872,  -872,   935,   855,   856,  -872,   857,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,   502,   502,   502,   502,   502,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,   859,   860,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   873,  -872,   874,
     876,   877,   878,   879,   152,   881,   883,   885,   886,   887,
     888,   889,   890,  -872,   891,   892,  -872,  -872,   894,   895,
     933,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -181,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -178,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
     639,   639,   639,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,     3,   896,   897,    13,   898,   903,  -872,   904,
     905,   603,   906,   907,   908,   909,   911,  -872,   912,   934,
     913,  -872,    -2,   914,   915,   940,   916,  -872,  -872,  -872,
     917,   858,  -872,   920,    73,  -872,  -872,  -872,  -872,  -872,
    -872,   922,   924,   533,   929,   931,   936,   739,   937,  -872,
     938,   939,   941,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
     164,  -872,   235,  -872,  -872,  -872,  -872,  -872,   942,   350,
     943,  -872,   944,   485,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -167,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -165,  -872,
    -872,   669,  -872,   704,  -872,  -872,  -872,  -872,  -872,  -153,
    -872,  -872,  -872,  -872,  -872,   -89,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
     -36,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,   -23,
    -872,  -872,  -872,  -872,  -872,   -14,  -872,  -872,  -872,   958,
     925,   945,  -872,   954,   946,  -105,   947,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,    84,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,    86,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,   118,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,   135,  -872,  -872,   152,
    -872,   933,  -872,  -872,  -872,     3,  -872,    13,  -872,   603,
    -872,   934,  -872,    -2,  -872,  -872,  -872,   948,   303,   950,
     951,  -872,  -872,   533,  -872,   739,  -872,   350,  -872,   485,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,   137,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,   303,  -872
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -872,  -872,  -872,  -483,  -316,  -871,  -453,  -872,  -872,   949,
    -872,  -872,  -872,  -872,   803,  -872,  -872,  -872,    21,  -872,
      23,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,   996,  -872,  -872,  -872,
    -872,  -872,   956,  -872,  -872,  -872,  -872,    58,  -872,  -872,
    -872,  -872,  -872,  -230,  -872,  -872,  -872,   604,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -186,  -872,  -872,
    -872,  -161,  -872,  -872,  -872,   810,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -168,  -872,   611,  -872,  -872,  -872,
     -45,  -872,  -872,  -872,  -872,  -872,   638,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -126,  -872,  -872,  -872,  -872,  -872,
    -872,   593,  -872,  -872,  -872,  -872,  -872,   952,  -872,  -872,
    -872,  -872,   555,  -872,  -872,  -872,  -872,  -872,  -136,  -872,
    -872,  -872,   582,  -872,  -872,  -872,  -872,  -129,  -872,  -872,
    -872,   793,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,   -91,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -102,  -872,   665,  -872,  -872,  -872,  -872,
    -872,   801,  -872,  -872,  -872,  -872,  1040,  -872,  -872,  -872,
    -872,  -872,  -872,   -86,  -872,   808,  -872,  -872,  -872,  -872,
     990,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,    59,
    -872,  -872,  -872,    62,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,   701,  -872,  -872,  -872,  -872,  -872,   -77,  -872,  -872,
    -872,  -872,  -872,   -81,  -872,  -872,  1089,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,  -872,
    -872,  -872,  -872,  -872,  -872,  -872,   953,  -872,  -872,  -872,
    -872,  -872,  -872,  -872
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -109
static const yytype_int16 yytable[] =
{
     713,   609,   610,   234,   712,    70,   302,   581,   616,   477,
     250,   119,    70,   545,  1117,    49,   241,    50,   400,   505,
     361,   590,   362,   496,  1123,   363,  1049,   390,   307,   496,
    1050,   478,   546,   505,    71,    54,   590,   234,   390,   302,
      56,    71,   364,   251,    72,   462,    47,    48,   463,  1051,
     479,    72,    61,  1052,   480,   400,   252,    62,  1152,  1110,
      65,   365,  1112,  1111,   506,   366,  1113,   241,    66,   253,
     254,   255,   256,  1248,  1010,  1250,    69,  1249,   506,  1251,
     120,   119,   464,   507,   367,   465,   368,  1254,   508,   257,
     116,  1255,   704,   705,   667,   668,   391,   507,   369,  1114,
    1115,  1116,   508,    73,   303,   582,  1269,   391,   681,   117,
      73,   118,   242,   686,   124,   547,   401,   230,   370,   591,
     231,   125,   706,   707,   697,   698,   466,   700,   126,   127,
     462,   232,   481,   463,   591,   710,   711,   303,   128,   715,
     243,   482,   483,   467,   548,   233,   129,   509,   371,   402,
     120,  1256,   130,   401,   497,  1257,   131,   132,   392,   133,
     497,   509,  1089,   242,  1090,   134,   248,   464,  1010,   392,
     465,   583,  1011,   581,   135,   136,   484,   372,   332,   137,
    1118,   249,   403,   857,   138,   592,   402,   498,   139,   140,
    1124,   243,   141,   498,   300,   142,   143,    79,   333,   334,
     592,  1153,   335,   144,  1258,  1154,   373,   301,  1259,   145,
     146,   466,   147,   148,   149,   150,   151,  1260,   308,   403,
     516,  1261,   267,    80,    81,   309,  1262,   152,   467,    82,
    1263,    83,   584,   235,   485,   153,   154,   155,  1012,   156,
     310,  -108,   157,   158,   781,   311,   159,   809,   499,   738,
     561,   268,   374,   773,   499,   520,   524,   160,   664,   750,
     653,   814,   526,   336,   337,   338,  1011,   235,   339,   743,
     468,   582,   313,    84,    85,  -108,   340,   518,   657,   598,
      86,    87,   161,   314,   527,   727,   162,   269,   341,   342,
     163,   164,   165,   166,   167,   970,   971,   972,   168,   169,
     315,    88,    89,   528,   343,   344,   316,   529,   170,   477,
     847,  1013,   791,   792,  1166,   317,    90,    91,   855,   856,
     270,   398,   271,   272,  1272,   318,  1274,    92,  1273,   545,
    1275,   478,  1012,   319,   345,   320,    93,   583,   171,   172,
     250,   173,  1066,  1067,  1068,  1069,  1070,   174,   546,   526,
     479,   321,   175,  1288,   480,   468,   322,   176,  1276,  1091,
     530,   460,  1277,   273,   323,   274,   275,   276,   277,   608,
     324,   527,  1092,   251,  1289,  1278,  1290,  1303,   521,  1279,
     267,  1304,   278,   795,   796,   531,   252,   860,   861,   325,
     528,   712,   326,   327,   529,   563,   328,   329,   584,   253,
     254,   255,   256,   397,   532,  1013,   983,   604,   279,   268,
     600,   409,   825,   826,   827,   828,   829,  1291,   637,   257,
     280,   125,   410,  1222,    94,    95,    96,   411,   126,   127,
     412,   547,   481,   413,   601,   414,   415,   330,   128,   603,
     416,   482,   483,   417,   418,   269,   129,   530,   419,   420,
     421,   422,   130,   423,   281,   282,   131,   132,   424,   133,
     548,   425,   579,   426,   605,   134,   427,   428,   429,   533,
     430,   431,   531,   432,   135,   136,   484,   433,   270,   137,
     271,   272,   434,   435,   138,   436,   438,   534,   139,   140,
     440,   532,   141,  1292,  1293,   142,   143,   441,   442,   443,
    1223,   444,   767,   144,   602,   445,   361,   446,   362,   145,
     146,   363,   147,   148,   149,   150,   151,   447,   448,   449,
     450,   273,   451,   274,   275,   276,   277,   152,   364,  1294,
     452,  1224,   453,   454,   485,   153,   154,   155,  1170,   156,
     278,  1225,   157,   158,   455,   456,   159,   365,  1226,   457,
     458,   366,   459,   517,   522,   523,   533,   160,  1236,   554,
    1227,   555,  1228,  1229,  1171,   556,   279,   557,   558,   559,
     367,   606,   368,   560,   534,  1230,   564,   565,   280,   566,
     567,   568,   161,  1172,   369,  1231,   162,   569,   570,  1173,
     163,   164,   165,   166,   167,   571,   572,    79,   168,   169,
     573,   574,   575,   576,   370,   577,  1174,   578,   170,   597,
     607,   608,   281,   282,   613,   611,   612,   614,   615,   617,
     618,   619,  1131,    80,    81,   620,   621,   622,   623,    82,
    1175,    83,   624,   625,   371,  1237,   626,  1176,   171,   172,
     627,   173,   628,   629,   630,   631,  1132,   174,   632,   633,
     634,  1177,   175,   635,   636,  1133,   639,   176,   640,   659,
     641,  1134,   642,   372,   643,   645,  1238,   646,   647,  1178,
     648,  1179,  1180,    84,    85,   649,  1239,  1135,   660,   650,
      86,    87,   669,  1240,     2,     3,   651,   666,   670,     4,
     652,   655,   373,   671,   332,  1241,   656,  1242,  1243,   661,
     662,    88,    89,  1136,     5,   673,   672,     6,     7,   674,
    1244,  1137,  1270,     8,   333,   334,    90,    91,   335,   675,
    1245,   676,   677,   678,  1181,   679,   680,    92,     9,   910,
     682,   683,    10,    11,  1182,    12,    93,   684,   374,   685,
     687,    13,   688,  1183,   689,   690,   691,  1184,   712,  1185,
     714,   692,   693,   694,  1138,    14,   695,   696,  1186,   699,
     701,   702,   703,   708,   933,    15,    16,   709,  1187,   716,
     717,   720,  1139,   718,   719,   722,   729,   745,   723,   336,
     337,   338,    17,   725,   339,   726,   730,   731,   733,   734,
     735,   752,   340,   755,   756,   736,   737,   740,    18,  1193,
     742,   747,   748,   749,   341,   342,   753,   754,   757,   758,
     759,   778,   783,   760,   762,   763,   775,   764,   769,   776,
     343,   344,   766,   770,    94,    95,    96,   777,   779,   780,
     784,   782,   771,   772,    19,   785,   786,   787,   788,   789,
     790,   799,   800,    20,    21,   801,   802,    22,    23,   803,
     345,   911,   912,   913,   914,   915,   816,   804,   916,   917,
     845,   805,   918,   919,   920,   806,   808,   921,   812,   922,
     923,   924,   811,   925,   926,   927,   846,   848,   928,   849,
     817,   850,   818,   819,   929,   820,   934,   935,   936,   937,
     938,   821,   851,   939,   940,   852,   822,   941,   942,   943,
     823,    24,   944,   853,   945,   946,   947,   824,   948,   949,
     950,   832,   833,   951,   834,   835,   836,   837,   838,   952,
     839,  1194,  1195,  1196,  1197,  1198,   840,   841,  1199,  1200,
     842,   843,  1201,  1202,  1203,   844,   854,  1204,   858,  1205,
    1206,  1207,   859,  1208,  1209,  1210,   862,   865,  1211,   863,
     866,   867,   868,   869,  1212,   870,   864,   873,   871,   872,
     874,   875,   876,   877,   878,   879,   984,   880,   881,   882,
     883,   884,   885,   886,   887,   888,   986,   889,   890,   987,
     891,   892,   893,   894,   895,   896,   897,   898,   899,   900,
     901,   989,   902,   903,   904,   905,   906,   907,   908,   909,
     932,   955,   956,   957,   958,   992,   959,   990,   993,   960,
     994,   961,   995,   962,   996,   963,   964,   965,   966,   967,
     968,   969,   975,   998,   976,   977,   978,   979,   980,   981,
    1000,  1003,  1004,   982,  1005,   985,   988,   997,   991,  1001,
    1021,   999,  1008,  1002,  1009,  1019,  1020,  1022,  1024,  1025,
    1023,  1026,  1027,  1028,  1029,  1033,  1030,  1031,  1032,  1034,
    1058,  1059,  1060,  1035,  1036,  1062,  1037,  1264,  1107,  1148,
     312,  1219,  1167,  1038,  1305,  1220,  1039,  1040,  1041,  1042,
    1043,  1044,  1045,  1046,  1267,  1047,   580,  1048,  1053,  1300,
    1054,  1055,  1056,  1057,  1061,  1286,  1064,  1065,  1063,  1071,
    1072,  1163,  1073,  1074,  1075,  1076,  1077,  1078,  1079,  1080,
    1081,  1082,  1299,  1083,  1084,  1265,  1085,  1086,  1087,  1088,
    1159,  1095,   751,  1096,   739,  1097,  1098,  1099,  1100,  1101,
    1102,  1103,  1104,  1284,  1105,  1106,  1121,  1122,  1127,   768,
     810,  1301,   774,  1128,  1129,  1130,  1142,  1143,  1144,  1145,
    1302,  1146,  1147,  1151,  1157,  1158,   638,  1162,  1280,  1285,
    1160,   399,  1168,  1165,  1169,  1281,   744,   461,   654,  1190,
     728,  1191,  1253,  1252,  1282,   815,  1192,  1215,  1216,  1217,
    1283,  1218,  1221,  1234,  1235,  1266,   331,  1271,  1287,  1268,
    1297,  1298,   519,   525,   658,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   562,     0,   665,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   599
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-872))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     453,   317,   318,     1,   109,     1,     1,     1,   324,     1,
       1,     1,     1,     1,    11,   242,     1,   242,     1,     1,
       1,     1,     3,     1,    11,     6,   240,     1,   240,     1,
     244,    23,    20,     1,    30,   242,     1,     1,     1,     1,
     242,    30,    23,    34,    40,     1,   240,   241,     4,   240,
      42,    40,   242,   244,    46,     1,    47,   242,    60,   240,
     242,    42,   240,   244,    46,    46,   244,     1,   242,    60,
      61,    62,    63,   240,     1,   240,   242,   244,    46,   244,
      70,     1,    38,    65,    65,    41,    67,   240,    70,    80,
     242,   244,   175,   176,   410,   411,    70,    65,    79,   970,
     971,   972,    70,    99,    99,    99,   211,    70,   424,   242,
      99,   242,    97,   429,   242,   103,    99,   242,    99,    99,
     242,     1,   175,   176,   440,   441,    82,   443,     8,     9,
       1,   242,   124,     4,    99,   451,   452,    99,    18,   455,
     125,   133,   134,    99,   132,   242,    26,   129,   129,   132,
      70,   240,    32,    99,   132,   244,    36,    37,   132,    39,
     132,   129,    10,    97,    12,    45,   242,    38,     1,   132,
      41,   165,    99,     1,    54,    55,   168,   158,     1,    59,
     177,   242,   165,   636,    64,   165,   132,   165,    68,    69,
     177,   125,    72,   165,   242,    75,    76,     1,    21,    22,
     165,   203,    25,    83,   240,   207,   187,   242,   244,    89,
      90,    82,    92,    93,    94,    95,    96,   240,   243,   165,
     240,   244,     1,    27,    28,   243,   240,   107,    99,    33,
     244,    35,   226,   231,   226,   115,   116,   117,   165,   119,
     243,   239,   122,   123,   560,   241,   126,   241,   226,   241,
     241,    30,   233,   241,   226,   239,   241,   137,   241,   241,
     241,   241,     1,    86,    87,    88,    99,   231,    91,   241,
     226,    99,   243,    77,    78,   239,    99,   241,   241,   241,
      84,    85,   162,   243,    23,   241,   166,    66,   111,   112,
     170,   171,   172,   173,   174,    13,    14,    15,   178,   179,
     243,   105,   106,    42,   127,   128,   243,    46,   188,     1,
     626,   238,   148,   149,   241,   243,   120,   121,   634,   635,
      99,   241,   101,   102,   240,   243,   240,   131,   244,     1,
     244,    23,   165,   243,   157,   243,   140,   165,   218,   219,
       1,   221,   825,   826,   827,   828,   829,   227,    20,     1,
      42,   243,   232,    50,    46,   226,   243,   237,   240,   207,
      99,   241,   244,   142,   243,   144,   145,   146,   147,   109,
     243,    23,   220,    34,    71,   240,    73,   240,   240,   244,
       1,   244,   161,   148,   149,   124,    47,   196,   197,   243,
      42,   109,   243,   243,    46,   240,   243,   243,   226,    60,
      61,    62,    63,   243,   143,   238,   722,   109,   187,    30,
     130,   243,   152,   153,   154,   155,   156,   114,   241,    80,
     199,     1,   243,    73,   228,   229,   230,   243,     8,     9,
     243,   103,   124,   243,   130,   243,   243,   241,    18,   240,
     243,   133,   134,   243,   243,    66,    26,    99,   243,   243,
     243,   243,    32,   243,   233,   234,    36,    37,   243,    39,
     132,   243,   241,   243,   109,    45,   243,   243,   243,   208,
     243,   243,   124,   243,    54,    55,   168,   243,    99,    59,
     101,   102,   243,   243,    64,   243,   243,   226,    68,    69,
     243,   143,    72,   190,   191,    75,    76,   243,   243,   243,
     150,   243,   241,    83,   130,   243,     1,   243,     3,    89,
      90,     6,    92,    93,    94,    95,    96,   243,   243,   243,
     243,   142,   243,   144,   145,   146,   147,   107,    23,   226,
     243,   181,   243,   243,   226,   115,   116,   117,     5,   119,
     161,   191,   122,   123,   243,   243,   126,    42,   198,   243,
     243,    46,   243,   243,   243,   243,   208,   137,    73,   243,
     210,   243,   212,   213,    31,   243,   187,   243,   243,   243,
      65,   175,    67,   243,   226,   225,   243,   243,   199,   243,
     243,   243,   162,    50,    79,   235,   166,   243,   243,    56,
     170,   171,   172,   173,   174,   243,   243,     1,   178,   179,
     243,   243,   243,   243,    99,   243,    73,   243,   188,   243,
     175,   109,   233,   234,   175,   109,   109,   175,   109,   175,
     175,   175,    19,    27,    28,   175,   175,   240,   240,    33,
      97,    35,   243,   243,   129,   150,   243,   104,   218,   219,
     243,   221,   243,   243,   243,   243,    43,   227,   243,   243,
     243,   118,   232,   243,   243,    52,   240,   237,   243,   130,
     243,    58,   243,   158,   243,   243,   181,   243,   243,   136,
     243,   138,   139,    77,    78,   243,   191,    74,   240,   243,
      84,    85,   109,   198,     0,     1,   243,   175,   175,     5,
     243,   243,   187,   175,     1,   210,   243,   212,   213,   243,
     243,   105,   106,   100,    20,   130,   109,    23,    24,   175,
     225,   108,  1165,    29,    21,    22,   120,   121,    25,   109,
     235,   109,   109,   175,   191,   175,   175,   131,    44,    60,
     130,   175,    48,    49,   201,    51,   140,   109,   233,   109,
     109,    57,   109,   210,   130,   109,   109,   214,   109,   216,
     130,   175,   175,   243,   151,    71,   175,   243,   225,   175,
     175,   175,   175,   175,    60,    81,    82,   175,   235,   175,
     175,   240,   169,   175,   175,   243,   240,   240,   243,    86,
      87,    88,    98,   243,    91,   243,   243,   243,   243,   243,
     243,   175,    99,   130,   130,   243,   243,   243,   114,    60,
     243,   243,   243,   243,   111,   112,   240,   242,   240,   240,
     243,   130,   130,   243,   243,   243,   175,   243,   240,   175,
     127,   128,   243,   243,   228,   229,   230,   175,   175,   175,
     175,   240,   243,   243,   150,   130,   130,   130,   130,   130,
     130,   130,   130,   159,   160,   109,   130,   163,   164,   130,
     157,   182,   183,   184,   185,   186,   130,   240,   189,   190,
     109,   240,   193,   194,   195,   243,   243,   198,   243,   200,
     201,   202,   240,   204,   205,   206,   109,   109,   209,   109,
     240,   109,   240,   240,   215,   240,   182,   183,   184,   185,
     186,   240,   109,   189,   190,   130,   240,   193,   194,   195,
     240,   217,   198,   109,   200,   201,   202,   240,   204,   205,
     206,   240,   240,   209,   240,   240,   240,   240,   240,   215,
     240,   182,   183,   184,   185,   186,   240,   240,   189,   190,
     240,   240,   193,   194,   195,   240,   109,   198,   240,   200,
     201,   202,   130,   204,   205,   206,   130,   130,   209,   175,
     130,   130,   130,   109,   215,   130,   243,   240,   130,   130,
     130,   130,   240,   240,   130,   130,   175,   243,   240,   240,
     240,   240,   240,   240,   240,   240,   130,   240,   240,   130,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   130,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   130,   240,   175,   109,   240,
     130,   240,   130,   240,   130,   240,   240,   240,   240,   240,
     240,   240,   240,   130,   240,   240,   240,   240,   240,   240,
     130,   130,   130,   243,   109,   243,   240,   240,   243,   240,
     130,   243,   240,   243,   240,   240,   240,   175,   130,   130,
     243,   130,   243,   130,   240,   240,   130,   130,   130,   240,
     130,   243,   130,   240,   240,   130,   240,   109,   135,   135,
      74,  1050,  1014,   240,  1304,  1052,   240,   240,   240,   240,
     240,   240,   240,   240,   130,   240,   283,   240,   240,  1275,
     240,   240,   240,   240,   240,  1263,   240,   240,   243,   240,
     240,   243,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,  1273,   240,   240,  1160,   240,   240,   240,   240,
     180,   240,   511,   240,   486,   240,   240,   240,   240,   240,
     240,   240,   240,  1259,   240,   240,   240,   240,   240,   535,
     585,  1277,   549,   240,   240,   240,   240,   240,   240,   240,
    1279,   240,   240,   240,   240,   240,   346,   240,  1249,  1261,
     244,   121,   240,   243,   240,  1251,   501,   177,   375,   240,
     469,   240,  1113,  1111,  1255,   593,   240,   240,   240,   240,
    1257,   240,   240,   240,   240,   240,    97,   240,   240,   243,
     240,   240,   236,   244,   393,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   258,    -1,   405,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   304
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   246,     0,     1,     5,    20,    23,    24,    29,    44,
      48,    49,    51,    57,    71,    81,    82,    98,   114,   150,
     159,   160,   163,   164,   217,   247,   252,   257,   279,   285,
     299,   317,   334,   348,   363,   370,   374,   384,   393,   413,
     423,   429,   433,   443,   503,   519,   539,   240,   241,   242,
     242,   318,   394,   424,   242,   434,   242,   504,   349,   414,
     335,   242,   242,   300,   364,   242,   242,   375,   385,   242,
       1,    30,    40,    99,   280,   281,   282,   283,   284,     1,
      27,    28,    33,    35,    77,    78,    84,    85,   105,   106,
     120,   121,   131,   140,   228,   229,   230,   520,   521,   522,
     523,   524,   525,   526,   527,   528,   529,   530,   531,   532,
     533,   534,   535,   536,   537,   538,   242,   242,   242,     1,
      70,   430,   431,   432,   242,     1,     8,     9,    18,    26,
      32,    36,    37,    39,    45,    54,    55,    59,    64,    68,
      69,    72,    75,    76,    83,    89,    90,    92,    93,    94,
      95,    96,   107,   115,   116,   117,   119,   122,   123,   126,
     137,   162,   166,   170,   171,   172,   173,   174,   178,   179,
     188,   218,   219,   221,   227,   232,   237,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   495,   499,   500,   501,   502,
     242,   242,   242,   242,     1,   231,   286,   287,   288,   289,
     290,     1,    97,   125,   253,   254,   255,   256,   242,   242,
       1,    34,    47,    60,    61,    62,    63,    80,   540,   541,
     542,   543,   544,   545,   546,   547,   548,     1,    30,    66,
      99,   101,   102,   142,   144,   145,   146,   147,   161,   187,
     199,   233,   234,   258,   259,   260,   261,   266,   267,   268,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   278,
     242,   242,     1,    99,   371,   372,   373,   240,   243,   243,
     243,   241,   281,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     241,   521,     1,    21,    22,    25,    86,    87,    88,    91,
      99,   111,   112,   127,   128,   157,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,     1,     3,     6,    23,    42,    46,    65,    67,    79,
      99,   129,   158,   187,   233,   395,   396,   397,   398,   399,
     400,   401,   402,   403,   404,   408,   409,   410,   411,   412,
       1,    70,   132,   425,   426,   427,   428,   243,   241,   431,
       1,    99,   132,   165,   435,   439,   440,   441,   442,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   496,   243,   492,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     241,   445,     1,     4,    38,    41,    82,    99,   226,   505,
     506,   507,   508,   509,   513,   514,   515,     1,    23,    42,
      46,   124,   133,   134,   168,   226,   350,   351,   352,   353,
     354,   355,   356,   360,   361,   362,     1,   132,   165,   226,
     415,   419,   420,   421,   422,     1,    46,    65,    70,   129,
     336,   340,   341,   342,   346,   347,   240,   243,   241,   287,
     239,   240,   243,   243,   241,   254,     1,    23,    42,    46,
      99,   124,   143,   208,   226,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   313,     1,    20,   103,   132,   365,
     366,   367,   368,   369,   243,   243,   243,   243,   243,   243,
     243,   241,   541,   240,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   241,
     259,     1,    99,   165,   226,   376,   377,   378,   379,   380,
       1,    99,   165,   386,   387,   388,   389,   243,   241,   372,
     130,   130,   130,   240,   109,   109,   175,   175,   109,   249,
     249,   109,   109,   175,   175,   109,   249,   175,   175,   175,
     175,   175,   240,   240,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   241,   320,   240,
     243,   243,   243,   243,   405,   243,   243,   243,   243,   243,
     243,   243,   243,   241,   396,   243,   243,   241,   426,   130,
     240,   243,   243,   436,   241,   440,   175,   249,   249,   109,
     175,   175,   109,   130,   175,   109,   109,   109,   175,   175,
     175,   249,   130,   175,   109,   109,   249,   109,   109,   130,
     109,   109,   175,   175,   243,   175,   243,   249,   249,   175,
     249,   175,   175,   175,   175,   176,   175,   176,   175,   175,
     249,   249,   109,   251,   130,   249,   175,   175,   175,   175,
     240,   516,   243,   243,   510,   243,   243,   241,   506,   240,
     243,   243,   357,   243,   243,   243,   243,   243,   241,   351,
     243,   416,   243,   241,   420,   240,   337,   243,   243,   243,
     241,   341,   175,   240,   242,   130,   130,   240,   240,   243,
     243,   314,   243,   243,   243,   310,   243,   241,   302,   240,
     243,   243,   243,   241,   366,   175,   175,   175,   130,   175,
     175,   249,   240,   130,   175,   130,   130,   130,   130,   130,
     130,   148,   149,   262,   263,   148,   149,   264,   265,   130,
     130,   109,   130,   130,   240,   240,   243,   381,   243,   241,
     377,   240,   243,   390,   241,   387,   130,   240,   240,   240,
     240,   240,   240,   240,   240,   152,   153,   154,   155,   156,
     248,   249,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   109,   109,   249,   109,   109,
     109,   109,   130,   109,   109,   249,   249,   251,   240,   130,
     196,   197,   130,   175,   243,   130,   130,   130,   130,   109,
     130,   130,   130,   240,   130,   130,   240,   240,   130,   130,
     243,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
      60,   182,   183,   184,   185,   186,   189,   190,   193,   194,
     195,   198,   200,   201,   202,   204,   205,   206,   209,   215,
     497,   498,   240,    60,   182,   183,   184,   185,   186,   189,
     190,   193,   194,   195,   198,   200,   201,   202,   204,   205,
     206,   209,   215,   493,   494,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
      13,    14,    15,   250,   251,   240,   240,   240,   240,   240,
     240,   240,   243,   249,   175,   243,   130,   130,   240,   130,
     175,   243,   130,   109,   130,   130,   130,   240,   130,   243,
     130,   240,   243,   130,   130,   109,   344,   345,   240,   240,
       1,    99,   165,   238,   291,   292,   293,   294,   295,   240,
     240,   130,   175,   243,   130,   130,   130,   243,   130,   240,
     130,   130,   130,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     244,   240,   244,   240,   240,   240,   240,   240,   130,   243,
     130,   240,   130,   243,   240,   240,   248,   248,   248,   248,
     248,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,    10,
      12,   207,   220,   406,   407,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   135,   437,   438,
     240,   244,   240,   244,   250,   250,   250,    11,   177,   517,
     518,   240,   240,    11,   177,   511,   512,   240,   240,   240,
     240,    19,    43,    52,    58,    74,   100,   108,   151,   169,
     358,   359,   240,   240,   240,   240,   240,   240,   135,   417,
     418,   240,    60,   203,   207,   338,   339,   240,   240,   180,
     244,   343,   240,   243,   296,   243,   241,   292,   240,   240,
       5,    31,    50,    56,    73,    97,   104,   118,   136,   138,
     139,   191,   201,   210,   214,   216,   225,   235,   315,   316,
     240,   240,   240,    60,   182,   183,   184,   185,   186,   189,
     190,   193,   194,   195,   198,   200,   201,   202,   204,   205,
     206,   209,   215,   311,   312,   240,   240,   240,   240,   263,
     265,   240,    73,   150,   181,   191,   198,   210,   212,   213,
     225,   235,   382,   383,   240,   240,    73,   150,   181,   191,
     198,   210,   212,   213,   225,   235,   391,   392,   240,   244,
     240,   244,   498,   494,   240,   244,   240,   244,   240,   244,
     240,   244,   240,   244,   109,   345,   240,   130,   243,   211,
     251,   240,   240,   244,   240,   244,   240,   244,   240,   244,
     407,   438,   518,   512,   359,   418,   339,   240,    50,    71,
      73,   114,   190,   191,   226,   297,   298,   240,   240,   316,
     312,   383,   392,   240,   244,   298
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
        case 27:

/* Line 1806 of yacc.c  */
#line 383 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 385 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 389 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 393 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 397 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 401 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 405 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 410 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 411 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 428 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 434 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 72:

/* Line 1806 of yacc.c  */
#line 459 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 73:

/* Line 1806 of yacc.c  */
#line 465 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 76:

/* Line 1806 of yacc.c  */
#line 474 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 77:

/* Line 1806 of yacc.c  */
#line 480 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 78:

/* Line 1806 of yacc.c  */
#line 488 "conf_parser.y"
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

  case 79:

/* Line 1806 of yacc.c  */
#line 527 "conf_parser.y"
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

  case 80:

/* Line 1806 of yacc.c  */
#line 586 "conf_parser.y"
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

  case 81:

/* Line 1806 of yacc.c  */
#line 614 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 82:

/* Line 1806 of yacc.c  */
#line 622 "conf_parser.y"
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

  case 83:

/* Line 1806 of yacc.c  */
#line 637 "conf_parser.y"
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

  case 84:

/* Line 1806 of yacc.c  */
#line 652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 85:

/* Line 1806 of yacc.c  */
#line 661 "conf_parser.y"
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

  case 86:

/* Line 1806 of yacc.c  */
#line 675 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 87:

/* Line 1806 of yacc.c  */
#line 684 "conf_parser.y"
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

  case 88:

/* Line 1806 of yacc.c  */
#line 712 "conf_parser.y"
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

  case 89:

/* Line 1806 of yacc.c  */
#line 742 "conf_parser.y"
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

  case 90:

/* Line 1806 of yacc.c  */
#line 765 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 98:

/* Line 1806 of yacc.c  */
#line 780 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 99:

/* Line 1806 of yacc.c  */
#line 789 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 100:

/* Line 1806 of yacc.c  */
#line 798 "conf_parser.y"
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
#line 816 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 108:

/* Line 1806 of yacc.c  */
#line 822 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 109:

/* Line 1806 of yacc.c  */
#line 827 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 116:

/* Line 1806 of yacc.c  */
#line 839 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 117:

/* Line 1806 of yacc.c  */
#line 844 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 118:

/* Line 1806 of yacc.c  */
#line 847 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 119:

/* Line 1806 of yacc.c  */
#line 852 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 123:

/* Line 1806 of yacc.c  */
#line 859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 124:

/* Line 1806 of yacc.c  */
#line 863 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 125:

/* Line 1806 of yacc.c  */
#line 867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 126:

/* Line 1806 of yacc.c  */
#line 871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 127:

/* Line 1806 of yacc.c  */
#line 875 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 128:

/* Line 1806 of yacc.c  */
#line 879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 129:

/* Line 1806 of yacc.c  */
#line 883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 130:

/* Line 1806 of yacc.c  */
#line 893 "conf_parser.y"
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

  case 131:

/* Line 1806 of yacc.c  */
#line 906 "conf_parser.y"
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

  case 143:

/* Line 1806 of yacc.c  */
#line 996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 144:

/* Line 1806 of yacc.c  */
#line 1005 "conf_parser.y"
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

  case 145:

/* Line 1806 of yacc.c  */
#line 1042 "conf_parser.y"
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

  case 146:

/* Line 1806 of yacc.c  */
#line 1054 "conf_parser.y"
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

  case 147:

/* Line 1806 of yacc.c  */
#line 1065 "conf_parser.y"
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

  case 148:

/* Line 1806 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 149:

/* Line 1806 of yacc.c  */
#line 1116 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 153:

/* Line 1806 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 154:

/* Line 1806 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 155:

/* Line 1806 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 156:

/* Line 1806 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 157:

/* Line 1806 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 158:

/* Line 1806 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 159:

/* Line 1806 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 160:

/* Line 1806 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 161:

/* Line 1806 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 162:

/* Line 1806 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 163:

/* Line 1806 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 164:

/* Line 1806 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 165:

/* Line 1806 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 166:

/* Line 1806 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 167:

/* Line 1806 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 168:

/* Line 1806 of yacc.c  */
#line 1183 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 169:

/* Line 1806 of yacc.c  */
#line 1187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 170:

/* Line 1806 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 171:

/* Line 1806 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 172:

/* Line 1806 of yacc.c  */
#line 1199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 173:

/* Line 1806 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 177:

/* Line 1806 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 178:

/* Line 1806 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 179:

/* Line 1806 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 180:

/* Line 1806 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 181:

/* Line 1806 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 182:

/* Line 1806 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 183:

/* Line 1806 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 184:

/* Line 1806 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 185:

/* Line 1806 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 186:

/* Line 1806 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 187:

/* Line 1806 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 188:

/* Line 1806 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 189:

/* Line 1806 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 190:

/* Line 1806 of yacc.c  */
#line 1264 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 191:

/* Line 1806 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 192:

/* Line 1806 of yacc.c  */
#line 1272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 193:

/* Line 1806 of yacc.c  */
#line 1276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 194:

/* Line 1806 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:

/* Line 1806 of yacc.c  */
#line 1290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:

/* Line 1806 of yacc.c  */
#line 1297 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1355 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:

/* Line 1806 of yacc.c  */
#line 1364 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:

/* Line 1806 of yacc.c  */
#line 1370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:

/* Line 1806 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:

/* Line 1806 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:

/* Line 1806 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:

/* Line 1806 of yacc.c  */
#line 1394 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:

/* Line 1806 of yacc.c  */
#line 1400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:

/* Line 1806 of yacc.c  */
#line 1406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:

/* Line 1806 of yacc.c  */
#line 1412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:

/* Line 1806 of yacc.c  */
#line 1418 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:

/* Line 1806 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:

/* Line 1806 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:

/* Line 1806 of yacc.c  */
#line 1439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:

/* Line 1806 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:

/* Line 1806 of yacc.c  */
#line 1455 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:

/* Line 1806 of yacc.c  */
#line 1461 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:

/* Line 1806 of yacc.c  */
#line 1465 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:

/* Line 1806 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:

/* Line 1806 of yacc.c  */
#line 1479 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:

/* Line 1806 of yacc.c  */
#line 1484 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1498 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:

/* Line 1806 of yacc.c  */
#line 1527 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:

/* Line 1806 of yacc.c  */
#line 1539 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1551 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1613 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1648 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1661 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:

/* Line 1806 of yacc.c  */
#line 1670 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1681 "conf_parser.y"
    {
}
    break;

  case 271:

/* Line 1806 of yacc.c  */
#line 1686 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:

/* Line 1806 of yacc.c  */
#line 1690 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:

/* Line 1806 of yacc.c  */
#line 1694 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:

/* Line 1806 of yacc.c  */
#line 1698 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:

/* Line 1806 of yacc.c  */
#line 1702 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:

/* Line 1806 of yacc.c  */
#line 1706 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:

/* Line 1806 of yacc.c  */
#line 1710 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:

/* Line 1806 of yacc.c  */
#line 1714 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:

/* Line 1806 of yacc.c  */
#line 1718 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:

/* Line 1806 of yacc.c  */
#line 1725 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1744 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1754 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:

/* Line 1806 of yacc.c  */
#line 1767 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:

/* Line 1806 of yacc.c  */
#line 1774 "conf_parser.y"
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
#line 1786 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:

/* Line 1806 of yacc.c  */
#line 1795 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:

/* Line 1806 of yacc.c  */
#line 1828 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1843 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:

/* Line 1806 of yacc.c  */
#line 1862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:

/* Line 1806 of yacc.c  */
#line 1871 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:

/* Line 1806 of yacc.c  */
#line 1900 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:

/* Line 1806 of yacc.c  */
#line 1904 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:

/* Line 1806 of yacc.c  */
#line 1908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:

/* Line 1806 of yacc.c  */
#line 1912 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:

/* Line 1806 of yacc.c  */
#line 1916 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:

/* Line 1806 of yacc.c  */
#line 1920 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:

/* Line 1806 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:

/* Line 1806 of yacc.c  */
#line 1928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:

/* Line 1806 of yacc.c  */
#line 1932 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:

/* Line 1806 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:

/* Line 1806 of yacc.c  */
#line 1945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:

/* Line 1806 of yacc.c  */
#line 1952 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 1965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:

/* Line 1806 of yacc.c  */
#line 1971 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:

/* Line 1806 of yacc.c  */
#line 1978 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:

/* Line 1806 of yacc.c  */
#line 1982 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:

/* Line 1806 of yacc.c  */
#line 1986 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:

/* Line 1806 of yacc.c  */
#line 1990 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:

/* Line 1806 of yacc.c  */
#line 1994 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:

/* Line 1806 of yacc.c  */
#line 1998 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:

/* Line 1806 of yacc.c  */
#line 2002 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:

/* Line 1806 of yacc.c  */
#line 2006 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:

/* Line 1806 of yacc.c  */
#line 2010 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:

/* Line 1806 of yacc.c  */
#line 2014 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:

/* Line 1806 of yacc.c  */
#line 2023 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2038 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2082 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:

/* Line 1806 of yacc.c  */
#line 2091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:

/* Line 1806 of yacc.c  */
#line 2100 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2126 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2144 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:

/* Line 1806 of yacc.c  */
#line 2168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:

/* Line 1806 of yacc.c  */
#line 2172 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:

/* Line 1806 of yacc.c  */
#line 2180 "conf_parser.y"
    {
}
    break;

  case 376:

/* Line 1806 of yacc.c  */
#line 2185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:

/* Line 1806 of yacc.c  */
#line 2189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:

/* Line 1806 of yacc.c  */
#line 2193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:

/* Line 1806 of yacc.c  */
#line 2197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:

/* Line 1806 of yacc.c  */
#line 2203 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2214 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2225 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:

/* Line 1806 of yacc.c  */
#line 2245 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2263 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:

/* Line 1806 of yacc.c  */
#line 2270 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2328 "conf_parser.y"
    {
}
    break;

  case 391:

/* Line 1806 of yacc.c  */
#line 2333 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:

/* Line 1806 of yacc.c  */
#line 2342 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2361 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:

/* Line 1806 of yacc.c  */
#line 2370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:

/* Line 1806 of yacc.c  */
#line 2374 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:

/* Line 1806 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:

/* Line 1806 of yacc.c  */
#line 2418 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:

/* Line 1806 of yacc.c  */
#line 2443 "conf_parser.y"
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

/* Line 1806 of yacc.c  */
#line 2483 "conf_parser.y"
    {
}
    break;

  case 421:

/* Line 1806 of yacc.c  */
#line 2488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:

/* Line 1806 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:

/* Line 1806 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 485:

/* Line 1806 of yacc.c  */
#line 2547 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:

/* Line 1806 of yacc.c  */
#line 2552 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:

/* Line 1806 of yacc.c  */
#line 2557 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:

/* Line 1806 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 489:

/* Line 1806 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 490:

/* Line 1806 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 491:

/* Line 1806 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:

/* Line 1806 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 493:

/* Line 1806 of yacc.c  */
#line 2587 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 494:

/* Line 1806 of yacc.c  */
#line 2592 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 495:

/* Line 1806 of yacc.c  */
#line 2597 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 496:

/* Line 1806 of yacc.c  */
#line 2602 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 497:

/* Line 1806 of yacc.c  */
#line 2607 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 498:

/* Line 1806 of yacc.c  */
#line 2612 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:

/* Line 1806 of yacc.c  */
#line 2617 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:

/* Line 1806 of yacc.c  */
#line 2622 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:

/* Line 1806 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:

/* Line 1806 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:

/* Line 1806 of yacc.c  */
#line 2638 "conf_parser.y"
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

  case 504:

/* Line 1806 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 505:

/* Line 1806 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 506:

/* Line 1806 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 507:

/* Line 1806 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 508:

/* Line 1806 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 509:

/* Line 1806 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 510:

/* Line 1806 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 511:

/* Line 1806 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 512:

/* Line 1806 of yacc.c  */
#line 2691 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 513:

/* Line 1806 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 514:

/* Line 1806 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 515:

/* Line 1806 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:

/* Line 1806 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:

/* Line 1806 of yacc.c  */
#line 2714 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 518:

/* Line 1806 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:

/* Line 1806 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 520:

/* Line 1806 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 521:

/* Line 1806 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 522:

/* Line 1806 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 523:

/* Line 1806 of yacc.c  */
#line 2744 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 524:

/* Line 1806 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:

/* Line 1806 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:

/* Line 1806 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 527:

/* Line 1806 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 528:

/* Line 1806 of yacc.c  */
#line 2779 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 529:

/* Line 1806 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 530:

/* Line 1806 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 531:

/* Line 1806 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 532:

/* Line 1806 of yacc.c  */
#line 2803 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 536:

/* Line 1806 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 537:

/* Line 1806 of yacc.c  */
#line 2812 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 538:

/* Line 1806 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 539:

/* Line 1806 of yacc.c  */
#line 2818 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 540:

/* Line 1806 of yacc.c  */
#line 2821 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 541:

/* Line 1806 of yacc.c  */
#line 2824 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 542:

/* Line 1806 of yacc.c  */
#line 2827 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 543:

/* Line 1806 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 544:

/* Line 1806 of yacc.c  */
#line 2833 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 545:

/* Line 1806 of yacc.c  */
#line 2836 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 546:

/* Line 1806 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 547:

/* Line 1806 of yacc.c  */
#line 2842 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 548:

/* Line 1806 of yacc.c  */
#line 2845 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 549:

/* Line 1806 of yacc.c  */
#line 2848 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 550:

/* Line 1806 of yacc.c  */
#line 2851 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 551:

/* Line 1806 of yacc.c  */
#line 2854 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 552:

/* Line 1806 of yacc.c  */
#line 2857 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 553:

/* Line 1806 of yacc.c  */
#line 2860 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 554:

/* Line 1806 of yacc.c  */
#line 2863 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 555:

/* Line 1806 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 556:

/* Line 1806 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 560:

/* Line 1806 of yacc.c  */
#line 2877 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 561:

/* Line 1806 of yacc.c  */
#line 2880 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 562:

/* Line 1806 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 563:

/* Line 1806 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 564:

/* Line 1806 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 565:

/* Line 1806 of yacc.c  */
#line 2892 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 566:

/* Line 1806 of yacc.c  */
#line 2895 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 567:

/* Line 1806 of yacc.c  */
#line 2898 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 568:

/* Line 1806 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 569:

/* Line 1806 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 570:

/* Line 1806 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 571:

/* Line 1806 of yacc.c  */
#line 2910 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 572:

/* Line 1806 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 573:

/* Line 1806 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 574:

/* Line 1806 of yacc.c  */
#line 2919 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 575:

/* Line 1806 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 576:

/* Line 1806 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 577:

/* Line 1806 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 578:

/* Line 1806 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 579:

/* Line 1806 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 580:

/* Line 1806 of yacc.c  */
#line 2939 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:

/* Line 1806 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:

/* Line 1806 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:

/* Line 1806 of yacc.c  */
#line 2954 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 584:

/* Line 1806 of yacc.c  */
#line 2963 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(GDENY_TYPE);
    yy_aconf = map_to_conf(yy_conf);
  }
}
    break;

  case 585:

/* Line 1806 of yacc.c  */
#line 2970 "conf_parser.y"
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

  case 595:

/* Line 1806 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 596:

/* Line 1806 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 597:

/* Line 1806 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging = 0;
}
    break;

  case 601:

/* Line 1806 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_REJECT;
}
    break;

  case 602:

/* Line 1806 of yacc.c  */
#line 3018 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_logging |= GDENY_BLOCK;
}
    break;

  case 603:

/* Line 1806 of yacc.c  */
#line 3024 "conf_parser.y"
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

  case 604:

/* Line 1806 of yacc.c  */
#line 3058 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)  
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 605:

/* Line 1806 of yacc.c  */
#line 3067 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags = 0;
}
    break;

  case 606:

/* Line 1806 of yacc.c  */
#line 3071 "conf_parser.y"
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

  case 609:

/* Line 1806 of yacc.c  */
#line 3118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_REJECT;
}
    break;

  case 610:

/* Line 1806 of yacc.c  */
#line 3122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= GDENY_BLOCK;
}
    break;

  case 632:

/* Line 1806 of yacc.c  */
#line 3146 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 633:

/* Line 1806 of yacc.c  */
#line 3151 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 634:

/* Line 1806 of yacc.c  */
#line 3156 "conf_parser.y"
    {
  ConfigChannel.disable_local_channels = yylval.number;
}
    break;

  case 635:

/* Line 1806 of yacc.c  */
#line 3161 "conf_parser.y"
    {
  ConfigChannel.use_except = yylval.number;
}
    break;

  case 636:

/* Line 1806 of yacc.c  */
#line 3166 "conf_parser.y"
    {
  ConfigChannel.use_invex = yylval.number;
}
    break;

  case 637:

/* Line 1806 of yacc.c  */
#line 3171 "conf_parser.y"
    {
  ConfigChannel.use_knock = yylval.number;
}
    break;

  case 638:

/* Line 1806 of yacc.c  */
#line 3176 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 639:

/* Line 1806 of yacc.c  */
#line 3181 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 640:

/* Line 1806 of yacc.c  */
#line 3186 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 641:

/* Line 1806 of yacc.c  */
#line 3191 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 642:

/* Line 1806 of yacc.c  */
#line 3196 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 643:

/* Line 1806 of yacc.c  */
#line 3201 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 644:

/* Line 1806 of yacc.c  */
#line 3206 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 645:

/* Line 1806 of yacc.c  */
#line 3211 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 646:

/* Line 1806 of yacc.c  */
#line 3216 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 647:

/* Line 1806 of yacc.c  */
#line 3221 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 648:

/* Line 1806 of yacc.c  */
#line 3226 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 660:

/* Line 1806 of yacc.c  */
#line 3245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 661:

/* Line 1806 of yacc.c  */
#line 3251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 662:

/* Line 1806 of yacc.c  */
#line 3257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 663:

/* Line 1806 of yacc.c  */
#line 3266 "conf_parser.y"
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

  case 664:

/* Line 1806 of yacc.c  */
#line 3280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 665:

/* Line 1806 of yacc.c  */
#line 3286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.disable_hidden = yylval.number;
}
    break;

  case 666:

/* Line 1806 of yacc.c  */
#line 3292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;



/* Line 1806 of yacc.c  */
#line 7564 "conf_parser.c"
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



