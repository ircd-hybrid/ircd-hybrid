/* A Bison parser, made by GNU Bison 2.6.2.  */

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
#define YYBISON_VERSION "2.6.2"

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
#line 153 "conf_parser.c"

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
     DISABLE_REMOTE_COMMANDS = 289,
     DOTS_IN_IDENT = 290,
     DURATION = 291,
     EGDPOOL_PATH = 292,
     EMAIL = 293,
     ENABLE = 294,
     ENCRYPTED = 295,
     EXCEED_LIMIT = 296,
     EXEMPT = 297,
     FAILED_OPER_NOTICE = 298,
     IRCD_FLAGS = 299,
     FLATTEN_LINKS = 300,
     GECOS = 301,
     GENERAL = 302,
     GLINE = 303,
     GLINE_DURATION = 304,
     GLINE_ENABLE = 305,
     GLINE_EXEMPT = 306,
     GLINE_TIME = 307,
     GLINE_REQUEST_DURATION = 308,
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
     MAX_CHANS_PER_OPER = 340,
     MAX_CHANS_PER_USER = 341,
     MAX_GLOBAL = 342,
     MAX_IDENT = 343,
     MAX_LOCAL = 344,
     MAX_NICK_CHANGES = 345,
     MAX_NICK_TIME = 346,
     MAX_NUMBER = 347,
     MAX_TARGETS = 348,
     MAX_WATCH = 349,
     MESSAGE_LOCALE = 350,
     MIN_NONWILDCARD = 351,
     MIN_NONWILDCARD_SIMPLE = 352,
     MODULE = 353,
     MODULES = 354,
     NAME = 355,
     NEED_PASSWORD = 356,
     NETWORK_DESC = 357,
     NETWORK_NAME = 358,
     NICK = 359,
     NICK_CHANGES = 360,
     NO_CREATE_ON_SPLIT = 361,
     NO_JOIN_ON_SPLIT = 362,
     NO_OPER_FLOOD = 363,
     NO_TILDE = 364,
     NUMBER = 365,
     NUMBER_PER_IDENT = 366,
     NUMBER_PER_CIDR = 367,
     NUMBER_PER_IP = 368,
     NUMBER_PER_IP_GLOBAL = 369,
     OPERATOR = 370,
     OPERS_BYPASS_CALLERID = 371,
     OPER_ONLY_UMODES = 372,
     OPER_PASS_RESV = 373,
     OPER_SPY_T = 374,
     OPER_UMODES = 375,
     JOIN_FLOOD_COUNT = 376,
     JOIN_FLOOD_TIME = 377,
     PACE_WAIT = 378,
     PACE_WAIT_SIMPLE = 379,
     PASSWORD = 380,
     PATH = 381,
     PING_COOKIE = 382,
     PING_TIME = 383,
     PING_WARNING = 384,
     PORT = 385,
     QSTRING = 386,
     QUIET_ON_BAN = 387,
     REASON = 388,
     REDIRPORT = 389,
     REDIRSERV = 390,
     REGEX_T = 391,
     REHASH = 392,
     TREJECT_HOLD_TIME = 393,
     REMOTE = 394,
     REMOTEBAN = 395,
     RESTRICT_CHANNELS = 396,
     RESTRICTED = 397,
     RSA_PRIVATE_KEY_FILE = 398,
     RSA_PUBLIC_KEY_FILE = 399,
     SSL_CERTIFICATE_FILE = 400,
     SSL_DH_PARAM_FILE = 401,
     T_SSL_CLIENT_METHOD = 402,
     T_SSL_SERVER_METHOD = 403,
     T_SSLV3 = 404,
     T_TLSV1 = 405,
     RESV = 406,
     RESV_EXEMPT = 407,
     SECONDS = 408,
     MINUTES = 409,
     HOURS = 410,
     DAYS = 411,
     WEEKS = 412,
     SENDQ = 413,
     SEND_PASSWORD = 414,
     SERVERHIDE = 415,
     SERVERINFO = 416,
     IRCD_SID = 417,
     TKLINE_EXPIRE_NOTICES = 418,
     T_SHARED = 419,
     T_CLUSTER = 420,
     TYPE = 421,
     SHORT_MOTD = 422,
     SILENT = 423,
     SPOOF = 424,
     SPOOF_NOTICE = 425,
     STATS_E_DISABLED = 426,
     STATS_I_OPER_ONLY = 427,
     STATS_K_OPER_ONLY = 428,
     STATS_O_OPER_ONLY = 429,
     STATS_P_OPER_ONLY = 430,
     TBOOL = 431,
     TMASKED = 432,
     T_REJECT = 433,
     TS_MAX_DELTA = 434,
     TS_WARN_DELTA = 435,
     TWODOTS = 436,
     T_ALL = 437,
     T_BOTS = 438,
     T_SOFTCALLERID = 439,
     T_CALLERID = 440,
     T_CCONN = 441,
     T_CCONN_FULL = 442,
     T_SSL_CIPHER_LIST = 443,
     T_CLIENT_FLOOD = 444,
     T_DEAF = 445,
     T_DEBUG = 446,
     T_DLINE = 447,
     T_DRONE = 448,
     T_EXTERNAL = 449,
     T_FULL = 450,
     T_INVISIBLE = 451,
     T_IPV4 = 452,
     T_IPV6 = 453,
     T_LOCOPS = 454,
     T_MAX_CLIENTS = 455,
     T_NCHANGE = 456,
     T_OPERWALL = 457,
     T_REJ = 458,
     T_SERVER = 459,
     T_SERVNOTICE = 460,
     T_SET = 461,
     T_SKILL = 462,
     T_SPY = 463,
     T_SSL = 464,
     T_UMODES = 465,
     T_UNAUTH = 466,
     T_UNDLINE = 467,
     T_UNLIMITED = 468,
     T_UNRESV = 469,
     T_UNXLINE = 470,
     T_GLOBOPS = 471,
     T_WALLOP = 472,
     T_RESTART = 473,
     T_SERVICE = 474,
     T_SERVICES_NAME = 475,
     THROTTLE_TIME = 476,
     TOPICBURST = 477,
     TRUE_NO_OPER_FLOOD = 478,
     TKLINE = 479,
     TXLINE = 480,
     TRESV = 481,
     UNKLINE = 482,
     USER = 483,
     USE_EGD = 484,
     USE_LOGGING = 485,
     USE_WHOIS_ACTUALLY = 486,
     VHOST = 487,
     VHOST6 = 488,
     XLINE = 489,
     WARN = 490,
     WARN_NO_NLINE = 491,
     T_SIZE = 492,
     T_FILE = 493
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
#define DISABLE_REMOTE_COMMANDS 289
#define DOTS_IN_IDENT 290
#define DURATION 291
#define EGDPOOL_PATH 292
#define EMAIL 293
#define ENABLE 294
#define ENCRYPTED 295
#define EXCEED_LIMIT 296
#define EXEMPT 297
#define FAILED_OPER_NOTICE 298
#define IRCD_FLAGS 299
#define FLATTEN_LINKS 300
#define GECOS 301
#define GENERAL 302
#define GLINE 303
#define GLINE_DURATION 304
#define GLINE_ENABLE 305
#define GLINE_EXEMPT 306
#define GLINE_TIME 307
#define GLINE_REQUEST_DURATION 308
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
#define MAX_CHANS_PER_OPER 340
#define MAX_CHANS_PER_USER 341
#define MAX_GLOBAL 342
#define MAX_IDENT 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_TIME 346
#define MAX_NUMBER 347
#define MAX_TARGETS 348
#define MAX_WATCH 349
#define MESSAGE_LOCALE 350
#define MIN_NONWILDCARD 351
#define MIN_NONWILDCARD_SIMPLE 352
#define MODULE 353
#define MODULES 354
#define NAME 355
#define NEED_PASSWORD 356
#define NETWORK_DESC 357
#define NETWORK_NAME 358
#define NICK 359
#define NICK_CHANGES 360
#define NO_CREATE_ON_SPLIT 361
#define NO_JOIN_ON_SPLIT 362
#define NO_OPER_FLOOD 363
#define NO_TILDE 364
#define NUMBER 365
#define NUMBER_PER_IDENT 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP 368
#define NUMBER_PER_IP_GLOBAL 369
#define OPERATOR 370
#define OPERS_BYPASS_CALLERID 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
#define OPER_SPY_T 374
#define OPER_UMODES 375
#define JOIN_FLOOD_COUNT 376
#define JOIN_FLOOD_TIME 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PING_WARNING 384
#define PORT 385
#define QSTRING 386
#define QUIET_ON_BAN 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REGEX_T 391
#define REHASH 392
#define TREJECT_HOLD_TIME 393
#define REMOTE 394
#define REMOTEBAN 395
#define RESTRICT_CHANNELS 396
#define RESTRICTED 397
#define RSA_PRIVATE_KEY_FILE 398
#define RSA_PUBLIC_KEY_FILE 399
#define SSL_CERTIFICATE_FILE 400
#define SSL_DH_PARAM_FILE 401
#define T_SSL_CLIENT_METHOD 402
#define T_SSL_SERVER_METHOD 403
#define T_SSLV3 404
#define T_TLSV1 405
#define RESV 406
#define RESV_EXEMPT 407
#define SECONDS 408
#define MINUTES 409
#define HOURS 410
#define DAYS 411
#define WEEKS 412
#define SENDQ 413
#define SEND_PASSWORD 414
#define SERVERHIDE 415
#define SERVERINFO 416
#define IRCD_SID 417
#define TKLINE_EXPIRE_NOTICES 418
#define T_SHARED 419
#define T_CLUSTER 420
#define TYPE 421
#define SHORT_MOTD 422
#define SILENT 423
#define SPOOF 424
#define SPOOF_NOTICE 425
#define STATS_E_DISABLED 426
#define STATS_I_OPER_ONLY 427
#define STATS_K_OPER_ONLY 428
#define STATS_O_OPER_ONLY 429
#define STATS_P_OPER_ONLY 430
#define TBOOL 431
#define TMASKED 432
#define T_REJECT 433
#define TS_MAX_DELTA 434
#define TS_WARN_DELTA 435
#define TWODOTS 436
#define T_ALL 437
#define T_BOTS 438
#define T_SOFTCALLERID 439
#define T_CALLERID 440
#define T_CCONN 441
#define T_CCONN_FULL 442
#define T_SSL_CIPHER_LIST 443
#define T_CLIENT_FLOOD 444
#define T_DEAF 445
#define T_DEBUG 446
#define T_DLINE 447
#define T_DRONE 448
#define T_EXTERNAL 449
#define T_FULL 450
#define T_INVISIBLE 451
#define T_IPV4 452
#define T_IPV6 453
#define T_LOCOPS 454
#define T_MAX_CLIENTS 455
#define T_NCHANGE 456
#define T_OPERWALL 457
#define T_REJ 458
#define T_SERVER 459
#define T_SERVNOTICE 460
#define T_SET 461
#define T_SKILL 462
#define T_SPY 463
#define T_SSL 464
#define T_UMODES 465
#define T_UNAUTH 466
#define T_UNDLINE 467
#define T_UNLIMITED 468
#define T_UNRESV 469
#define T_UNXLINE 470
#define T_GLOBOPS 471
#define T_WALLOP 472
#define T_RESTART 473
#define T_SERVICE 474
#define T_SERVICES_NAME 475
#define THROTTLE_TIME 476
#define TOPICBURST 477
#define TRUE_NO_OPER_FLOOD 478
#define TKLINE 479
#define TXLINE 480
#define TRESV 481
#define UNKLINE 482
#define USER 483
#define USE_EGD 484
#define USE_LOGGING 485
#define USE_WHOIS_ACTUALLY 486
#define VHOST 487
#define VHOST6 488
#define XLINE 489
#define WARN 490
#define WARN_NO_NLINE 491
#define T_SIZE 492
#define T_FILE 493



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 678 "conf_parser.c"
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
#line 706 "conf_parser.c"

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
#define YYLAST   1203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  244
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  287
/* YYNRULES -- Number of rules.  */
#define YYNRULES  637
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1250

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   243,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   239,
       2,   242,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   241,     2,   240,     2,     2,     2,     2,
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
     235,   236,   237,   238
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
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1814,  1816,  1821,
    1826,  1831,  1836,  1841,  1846,  1851,  1856,  1861,  1866,  1871,
    1876,  1881,  1886,  1892,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1909,  1911,  1916,  1921,  1926,  1931,  1936
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     245,     0,    -1,    -1,   245,   246,    -1,   278,    -1,   284,
      -1,   298,    -1,   505,    -1,   316,    -1,   333,    -1,   347,
      -1,   256,    -1,   522,    -1,   362,    -1,   369,    -1,   373,
      -1,   383,    -1,   392,    -1,   412,    -1,   422,    -1,   428,
      -1,   442,    -1,   432,    -1,   251,    -1,     1,   239,    -1,
       1,   240,    -1,    -1,   248,    -1,   110,   247,    -1,   110,
     153,   247,    -1,   110,   154,   247,    -1,   110,   155,   247,
      -1,   110,   156,   247,    -1,   110,   157,   247,    -1,    -1,
     250,    -1,   110,   249,    -1,   110,    13,   249,    -1,   110,
      14,   249,    -1,   110,    15,   249,    -1,    99,   241,   252,
     240,   239,    -1,   252,   253,    -1,   253,    -1,   254,    -1,
     255,    -1,     1,   239,    -1,    98,   242,   131,   239,    -1,
     126,   242,   131,   239,    -1,   161,   241,   257,   240,   239,
      -1,   257,   258,    -1,   258,    -1,   269,    -1,   274,    -1,
     277,    -1,   271,    -1,   272,    -1,   273,    -1,   276,    -1,
     267,    -1,   266,    -1,   275,    -1,   270,    -1,   265,    -1,
     259,    -1,   260,    -1,   268,    -1,     1,   239,    -1,   147,
     242,   261,   239,    -1,   148,   242,   263,   239,    -1,   261,
     243,   262,    -1,   262,    -1,   149,    -1,   150,    -1,   263,
     243,   264,    -1,   264,    -1,   149,    -1,   150,    -1,   145,
     242,   131,   239,    -1,   143,   242,   131,   239,    -1,   146,
     242,   131,   239,    -1,   188,   242,   131,   239,    -1,   100,
     242,   131,   239,    -1,   162,   242,   131,   239,    -1,    30,
     242,   131,   239,    -1,   103,   242,   131,   239,    -1,   102,
     242,   131,   239,    -1,   232,   242,   131,   239,    -1,   233,
     242,   131,   239,    -1,   200,   242,   110,   239,    -1,    66,
     242,   176,   239,    -1,     5,   241,   279,   240,   239,    -1,
     279,   280,    -1,   280,    -1,   281,    -1,   283,    -1,   282,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,    38,
     242,   131,   239,    -1,    30,   242,   131,   239,    -1,    82,
     241,   285,   240,   239,    -1,   285,   286,    -1,   286,    -1,
     287,    -1,   288,    -1,     1,   239,    -1,   230,   242,   176,
     239,    -1,    -1,   289,   238,   241,   290,   240,   239,    -1,
     290,   291,    -1,   291,    -1,   292,    -1,   294,    -1,   293,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,   237,
     242,   250,   239,    -1,   237,   242,   213,   239,    -1,    -1,
     166,   295,   242,   296,   239,    -1,   296,   243,   297,    -1,
     297,    -1,   228,    -1,   115,    -1,    48,    -1,   192,    -1,
      73,    -1,    71,    -1,   191,    -1,    -1,   115,   299,   241,
     300,   240,   239,    -1,   300,   301,    -1,   301,    -1,   302,
      -1,   303,    -1,   304,    -1,   308,    -1,   307,    -1,   305,
      -1,   306,    -1,   312,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,   228,   242,   131,   239,    -1,   125,   242,
     131,   239,    -1,    40,   242,   176,   239,    -1,   144,   242,
     131,   239,    -1,    23,   242,   131,   239,    -1,    -1,   210,
     309,   242,   310,   239,    -1,   310,   243,   311,    -1,   311,
      -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,   191,
      -1,   195,    -1,    60,    -1,   207,    -1,   201,    -1,   203,
      -1,   211,    -1,   208,    -1,   194,    -1,   202,    -1,   205,
      -1,   196,    -1,   217,    -1,   184,    -1,   185,    -1,   199,
      -1,    -1,    44,   313,   242,   314,   239,    -1,   314,   243,
     315,    -1,   315,    -1,    56,    -1,   139,    -1,    73,    -1,
     227,    -1,   192,    -1,   212,    -1,   234,    -1,    48,    -1,
      31,    -1,   218,    -1,   137,    -1,     5,    -1,   105,    -1,
     202,    -1,   216,    -1,   119,    -1,   140,    -1,   206,    -1,
      98,    -1,    -1,    23,   317,   241,   318,   240,   239,    -1,
     318,   319,    -1,   319,    -1,   320,    -1,   330,    -1,   331,
      -1,   321,    -1,   322,    -1,   332,    -1,   323,    -1,   324,
      -1,   325,    -1,   326,    -1,   327,    -1,   328,    -1,   329,
      -1,     1,   239,    -1,   100,   242,   131,   239,    -1,   128,
     242,   248,   239,    -1,   129,   242,   248,   239,    -1,   113,
     242,   110,   239,    -1,    25,   242,   248,   239,    -1,    92,
     242,   110,   239,    -1,    87,   242,   110,   239,    -1,    89,
     242,   110,   239,    -1,    88,   242,   110,   239,    -1,   158,
     242,   250,   239,    -1,    21,   242,   110,   239,    -1,    22,
     242,   110,   239,    -1,   112,   242,   110,   239,    -1,    -1,
      81,   334,   241,   339,   240,   239,    -1,    -1,    44,   336,
     242,   337,   239,    -1,   337,   243,   338,    -1,   338,    -1,
     209,    -1,    60,    -1,   204,    -1,   339,   340,    -1,   340,
      -1,   341,    -1,   335,    -1,   345,    -1,   346,    -1,     1,
     239,    -1,    -1,   130,   242,   343,   342,   239,    -1,   343,
     243,   344,    -1,   344,    -1,   110,    -1,   110,   181,   110,
      -1,    70,   242,   131,   239,    -1,    65,   242,   131,   239,
      -1,    -1,    57,   348,   241,   349,   240,   239,    -1,   349,
     350,    -1,   350,    -1,   351,    -1,   352,    -1,   353,    -1,
     355,    -1,   359,    -1,   360,    -1,   361,    -1,   354,    -1,
       1,   239,    -1,   228,   242,   131,   239,    -1,   125,   242,
     131,   239,    -1,    23,   242,   131,   239,    -1,    40,   242,
     176,   239,    -1,    -1,    44,   356,   242,   357,   239,    -1,
     357,   243,   358,    -1,   358,    -1,   170,    -1,    41,    -1,
      74,    -1,    58,    -1,    19,    -1,   109,    -1,    51,    -1,
     152,    -1,   101,    -1,   169,   242,   131,   239,    -1,   135,
     242,   131,   239,    -1,   134,   242,   110,   239,    -1,    -1,
     151,   363,   241,   364,   240,   239,    -1,   364,   365,    -1,
     365,    -1,   366,    -1,   367,    -1,   368,    -1,     1,   239,
      -1,   133,   242,   131,   239,    -1,    20,   242,   131,   239,
      -1,   104,   242,   131,   239,    -1,   219,   241,   370,   240,
     239,    -1,   370,   371,    -1,   371,    -1,   372,    -1,     1,
      -1,   100,   242,   131,   239,    -1,    -1,   164,   374,   241,
     375,   240,   239,    -1,   375,   376,    -1,   376,    -1,   377,
      -1,   378,    -1,   379,    -1,     1,   239,    -1,   100,   242,
     131,   239,    -1,   228,   242,   131,   239,    -1,    -1,   166,
     380,   242,   381,   239,    -1,   381,   243,   382,    -1,   382,
      -1,    73,    -1,   227,    -1,   192,    -1,   212,    -1,   234,
      -1,   215,    -1,   151,    -1,   214,    -1,   199,    -1,   182,
      -1,    -1,   165,   384,   241,   385,   240,   239,    -1,   385,
     386,    -1,   386,    -1,   387,    -1,   388,    -1,     1,   239,
      -1,   100,   242,   131,   239,    -1,    -1,   166,   389,   242,
     390,   239,    -1,   390,   243,   391,    -1,   391,    -1,    73,
      -1,   227,    -1,   192,    -1,   212,    -1,   234,    -1,   215,
      -1,   151,    -1,   214,    -1,   199,    -1,   182,    -1,    -1,
      24,   393,   241,   394,   240,   239,    -1,   394,   395,    -1,
     395,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
     400,    -1,   402,    -1,   401,    -1,   411,    -1,   403,    -1,
     408,    -1,   409,    -1,   410,    -1,   407,    -1,     1,   239,
      -1,   100,   242,   131,   239,    -1,    65,   242,   131,   239,
      -1,   232,   242,   131,   239,    -1,   159,   242,   131,   239,
      -1,     3,   242,   131,   239,    -1,   130,   242,   110,   239,
      -1,     6,   242,   197,   239,    -1,     6,   242,   198,   239,
      -1,    -1,    44,   404,   242,   405,   239,    -1,   405,   243,
     406,    -1,   406,    -1,    10,    -1,    12,    -1,   222,    -1,
     209,    -1,    40,   242,   176,   239,    -1,    67,   242,   131,
     239,    -1,    79,   242,   131,   239,    -1,    23,   242,   131,
     239,    -1,   188,   242,   131,   239,    -1,    -1,    71,   413,
     241,   418,   240,   239,    -1,    -1,   166,   415,   242,   416,
     239,    -1,   416,   243,   417,    -1,   417,    -1,   136,    -1,
     418,   419,    -1,   419,    -1,   420,    -1,   421,    -1,   414,
      -1,     1,    -1,   228,   242,   131,   239,    -1,   133,   242,
     131,   239,    -1,    -1,    29,   423,   241,   424,   240,   239,
      -1,   424,   425,    -1,   425,    -1,   426,    -1,   427,    -1,
       1,    -1,    70,   242,   131,   239,    -1,   133,   242,   131,
     239,    -1,    42,   241,   429,   240,   239,    -1,   429,   430,
      -1,   430,    -1,   431,    -1,     1,    -1,    70,   242,   131,
     239,    -1,    -1,    46,   433,   241,   438,   240,   239,    -1,
      -1,   166,   435,   242,   436,   239,    -1,   436,   243,   437,
      -1,   437,    -1,   136,    -1,   438,   439,    -1,   439,    -1,
     440,    -1,   441,    -1,   434,    -1,     1,    -1,   100,   242,
     131,   239,    -1,   133,   242,   131,   239,    -1,    47,   241,
     443,   240,   239,    -1,   443,   444,    -1,   444,    -1,   455,
      -1,   456,    -1,   458,    -1,   459,    -1,   460,    -1,   461,
      -1,   462,    -1,   463,    -1,   464,    -1,   465,    -1,   454,
      -1,   467,    -1,   468,    -1,   469,    -1,   470,    -1,   485,
      -1,   472,    -1,   474,    -1,   476,    -1,   475,    -1,   479,
      -1,   473,    -1,   480,    -1,   481,    -1,   482,    -1,   483,
      -1,   484,    -1,   497,    -1,   486,    -1,   487,    -1,   488,
      -1,   493,    -1,   477,    -1,   478,    -1,   503,    -1,   501,
      -1,   502,    -1,   457,    -1,   504,    -1,   492,    -1,   466,
      -1,   490,    -1,   491,    -1,   453,    -1,   446,    -1,   447,
      -1,   448,    -1,   449,    -1,   450,    -1,   451,    -1,   452,
      -1,   471,    -1,   445,    -1,   489,    -1,     1,    -1,    94,
     242,   110,   239,    -1,    50,   242,   176,   239,    -1,    49,
     242,   248,   239,    -1,    53,   242,   248,   239,    -1,    54,
     242,   110,   239,    -1,    55,   242,   110,   239,    -1,   231,
     242,   176,   239,    -1,   138,   242,   248,   239,    -1,   163,
     242,   176,   239,    -1,    72,   242,   248,   239,    -1,    64,
     242,   176,   239,    -1,    68,   242,   176,   239,    -1,    34,
     242,   176,   239,    -1,    43,   242,   176,   239,    -1,     8,
     242,   176,   239,    -1,    91,   242,   248,   239,    -1,    90,
     242,   110,   239,    -1,    83,   242,   110,   239,    -1,     9,
     242,   248,   239,    -1,   180,   242,   248,   239,    -1,   179,
     242,   248,   239,    -1,    59,   242,   110,   239,    -1,    76,
     242,   176,   239,    -1,    75,   242,   131,   239,    -1,    69,
     242,   176,   239,    -1,   236,   242,   176,   239,    -1,   171,
     242,   176,   239,    -1,   174,   242,   176,   239,    -1,   175,
     242,   176,   239,    -1,   173,   242,   176,   239,    -1,   173,
     242,   177,   239,    -1,   172,   242,   176,   239,    -1,   172,
     242,   177,   239,    -1,   123,   242,   248,   239,    -1,    18,
     242,   248,   239,    -1,   116,   242,   176,   239,    -1,   124,
     242,   248,   239,    -1,   167,   242,   176,   239,    -1,   108,
     242,   176,   239,    -1,   223,   242,   176,   239,    -1,   118,
     242,   176,   239,    -1,    95,   242,   131,   239,    -1,    35,
     242,   110,   239,    -1,    93,   242,   110,   239,    -1,   229,
     242,   176,   239,    -1,    37,   242,   131,   239,    -1,   220,
     242,   131,   239,    -1,   127,   242,   176,   239,    -1,    32,
     242,   176,   239,    -1,   221,   242,   248,   239,    -1,    -1,
     120,   494,   242,   495,   239,    -1,   495,   243,   496,    -1,
     496,    -1,   183,    -1,   186,    -1,   187,    -1,   190,    -1,
     191,    -1,   195,    -1,    60,    -1,   207,    -1,   201,    -1,
     203,    -1,   211,    -1,   208,    -1,   194,    -1,   202,    -1,
     205,    -1,   196,    -1,   217,    -1,   184,    -1,   185,    -1,
     199,    -1,    -1,   117,   498,   242,   499,   239,    -1,   499,
     243,   500,    -1,   500,    -1,   183,    -1,   186,    -1,   187,
      -1,   190,    -1,   191,    -1,   195,    -1,   207,    -1,    60,
      -1,   201,    -1,   203,    -1,   211,    -1,   208,    -1,   194,
      -1,   202,    -1,   205,    -1,   196,    -1,   217,    -1,   184,
      -1,   185,    -1,   199,    -1,    96,   242,   110,   239,    -1,
      97,   242,   110,   239,    -1,    26,   242,   110,   239,    -1,
     189,   242,   250,   239,    -1,    20,   241,   506,   240,   239,
      -1,   506,   507,    -1,   507,    -1,   515,    -1,   510,    -1,
     511,    -1,   512,    -1,   513,    -1,   514,    -1,   516,    -1,
     517,    -1,   518,    -1,   509,    -1,   519,    -1,   520,    -1,
     521,    -1,   508,    -1,     1,    -1,    33,   242,   176,   239,
      -1,   141,   242,   176,   239,    -1,    77,   242,   248,   239,
      -1,    78,   242,   248,   239,    -1,    86,   242,   110,   239,
      -1,    85,   242,   110,   239,    -1,   132,   242,   176,   239,
      -1,    84,   242,   110,   239,    -1,    28,   242,   110,   239,
      -1,    27,   242,   110,   239,    -1,   106,   242,   176,   239,
      -1,   107,   242,   176,   239,    -1,   121,   242,   110,   239,
      -1,   122,   242,   248,   239,    -1,   160,   241,   523,   240,
     239,    -1,   523,   524,    -1,   524,    -1,   525,    -1,   526,
      -1,   528,    -1,   529,    -1,   527,    -1,   530,    -1,     1,
      -1,    45,   242,   176,   239,    -1,    63,   242,   176,   239,
      -1,    61,   242,   131,   239,    -1,    80,   242,   248,   239,
      -1,    60,   242,   176,   239,    -1,    62,   242,   176,   239,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   352,   352,   353,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   366,   367,   368,   369,   370,   371,
     372,   373,   374,   375,   376,   377,   381,   381,   382,   386,
     390,   394,   398,   402,   408,   408,   409,   410,   411,   412,
     419,   422,   422,   423,   423,   423,   425,   431,   438,   440,
     440,   441,   441,   442,   442,   443,   443,   444,   444,   445,
     445,   446,   446,   447,   447,   448,   449,   452,   453,   455,
     455,   456,   462,   470,   470,   471,   477,   485,   524,   583,
     611,   619,   634,   649,   658,   672,   681,   709,   739,   762,
     771,   773,   773,   774,   774,   775,   775,   777,   786,   795,
     807,   808,   808,   810,   810,   811,   813,   820,   820,   830,
     831,   833,   833,   834,   834,   836,   841,   844,   850,   849,
     855,   855,   856,   860,   864,   868,   872,   876,   880,   891,
     890,   988,   988,   989,   989,   989,   990,   990,   990,   991,
     991,   991,   993,  1002,  1039,  1051,  1062,  1104,  1114,  1113,
    1119,  1119,  1120,  1124,  1128,  1132,  1136,  1140,  1144,  1148,
    1152,  1156,  1160,  1164,  1168,  1172,  1176,  1180,  1184,  1188,
    1192,  1196,  1203,  1202,  1208,  1208,  1209,  1213,  1217,  1221,
    1225,  1229,  1233,  1237,  1241,  1245,  1249,  1253,  1257,  1261,
    1265,  1269,  1273,  1277,  1281,  1292,  1291,  1341,  1341,  1342,
    1343,  1343,  1344,  1345,  1346,  1347,  1348,  1349,  1350,  1351,
    1352,  1353,  1354,  1356,  1365,  1371,  1377,  1383,  1389,  1395,
    1401,  1407,  1413,  1419,  1425,  1431,  1441,  1440,  1457,  1456,
    1461,  1461,  1462,  1466,  1470,  1478,  1478,  1479,  1479,  1479,
    1479,  1479,  1481,  1481,  1483,  1483,  1485,  1499,  1519,  1528,
    1541,  1540,  1609,  1609,  1610,  1610,  1610,  1610,  1611,  1611,
    1611,  1612,  1612,  1614,  1649,  1662,  1671,  1683,  1682,  1686,
    1686,  1687,  1691,  1695,  1699,  1703,  1707,  1711,  1715,  1719,
    1726,  1745,  1755,  1769,  1768,  1784,  1784,  1785,  1785,  1785,
    1785,  1787,  1796,  1811,  1824,  1826,  1826,  1827,  1827,  1829,
    1845,  1844,  1860,  1860,  1861,  1861,  1861,  1861,  1863,  1872,
    1895,  1894,  1900,  1900,  1901,  1905,  1909,  1913,  1917,  1921,
    1925,  1929,  1933,  1937,  1947,  1946,  1963,  1963,  1964,  1964,
    1964,  1966,  1973,  1972,  1978,  1978,  1979,  1983,  1987,  1991,
    1995,  1999,  2003,  2007,  2011,  2015,  2025,  2024,  2075,  2075,
    2076,  2076,  2076,  2077,  2077,  2078,  2078,  2078,  2079,  2079,
    2079,  2080,  2080,  2081,  2083,  2092,  2101,  2127,  2145,  2163,
    2169,  2173,  2182,  2181,  2185,  2185,  2186,  2190,  2194,  2198,
    2204,  2215,  2226,  2237,  2246,  2265,  2264,  2330,  2329,  2333,
    2333,  2334,  2340,  2340,  2341,  2341,  2341,  2341,  2343,  2362,
    2372,  2371,  2396,  2396,  2397,  2397,  2397,  2399,  2405,  2414,
    2416,  2416,  2417,  2417,  2419,  2438,  2437,  2485,  2484,  2488,
    2488,  2489,  2495,  2495,  2496,  2496,  2496,  2496,  2498,  2504,
    2513,  2516,  2516,  2517,  2517,  2518,  2518,  2519,  2519,  2520,
    2520,  2521,  2521,  2522,  2522,  2523,  2523,  2524,  2524,  2525,
    2525,  2526,  2526,  2527,  2527,  2528,  2528,  2529,  2529,  2530,
    2531,  2531,  2532,  2532,  2533,  2533,  2534,  2534,  2535,  2535,
    2536,  2537,  2538,  2538,  2539,  2540,  2541,  2541,  2542,  2542,
    2543,  2544,  2544,  2545,  2545,  2546,  2546,  2547,  2550,  2555,
    2561,  2567,  2573,  2578,  2583,  2588,  2593,  2598,  2603,  2608,
    2613,  2618,  2623,  2628,  2633,  2638,  2643,  2648,  2653,  2659,
    2670,  2675,  2684,  2689,  2694,  2699,  2704,  2709,  2712,  2717,
    2720,  2725,  2730,  2735,  2740,  2745,  2750,  2755,  2760,  2765,
    2776,  2781,  2786,  2791,  2800,  2809,  2814,  2819,  2825,  2824,
    2829,  2829,  2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,
    2854,  2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,
    2884,  2887,  2893,  2892,  2897,  2897,  2898,  2901,  2904,  2907,
    2910,  2913,  2916,  2919,  2922,  2925,  2928,  2931,  2934,  2937,
    2940,  2943,  2946,  2949,  2952,  2955,  2960,  2965,  2970,  2975,
    2984,  2987,  2987,  2988,  2989,  2989,  2990,  2990,  2991,  2991,
    2992,  2993,  2993,  2994,  2995,  2995,  2996,  2996,  2998,  3003,
    3008,  3013,  3018,  3023,  3028,  3033,  3038,  3043,  3048,  3053,
    3058,  3063,  3071,  3074,  3074,  3075,  3075,  3076,  3077,  3077,
    3078,  3079,  3081,  3087,  3093,  3102,  3116,  3122
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
  "DISABLE_FAKE_CHANNELS", "DISABLE_REMOTE_COMMANDS", "DOTS_IN_IDENT",
  "DURATION", "EGDPOOL_PATH", "EMAIL", "ENABLE", "ENCRYPTED",
  "EXCEED_LIMIT", "EXEMPT", "FAILED_OPER_NOTICE", "IRCD_FLAGS",
  "FLATTEN_LINKS", "GECOS", "GENERAL", "GLINE", "GLINE_DURATION",
  "GLINE_ENABLE", "GLINE_EXEMPT", "GLINE_TIME", "GLINE_REQUEST_DURATION",
  "GLINE_MIN_CIDR", "GLINE_MIN_CIDR6", "GLOBAL_KILL", "IRCD_AUTH",
  "NEED_IDENT", "HAVENT_READ_CONF", "HIDDEN", "HIDDEN_NAME",
  "HIDE_SERVER_IPS", "HIDE_SERVERS", "HIDE_SPOOF_IPS", "HOST", "HUB",
  "HUB_MASK", "IGNORE_BOGUS_TS", "INVISIBLE_ON_CONNECT", "IP", "KILL",
  "KILL_CHASE_TIME_LIMIT", "KLINE", "KLINE_EXEMPT", "KLINE_REASON",
  "KLINE_WITH_REASON", "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK",
  "LINKS_DELAY", "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS",
  "MAX_CHANS_PER_OPER", "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT",
  "MAX_LOCAL", "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
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
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TOPICBURST", "TRUE_NO_OPER_FLOOD", "TKLINE", "TXLINE",
  "TRESV", "UNKLINE", "USER", "USE_EGD", "USE_LOGGING",
  "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE", "WARN",
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
  "channel_restrict_channels", "channel_knock_delay",
  "channel_knock_delay_channel", "channel_max_chans_per_user",
  "channel_max_chans_per_oper", "channel_quiet_on_ban", "channel_max_bans",
  "channel_default_split_user_count", "channel_default_split_server_count",
  "channel_no_create_on_split", "channel_no_join_on_split",
  "channel_jflood_count", "channel_jflood_time", "serverhide_entry",
  "serverhide_items", "serverhide_item", "serverhide_flatten_links",
  "serverhide_hide_servers", "serverhide_hidden_name",
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
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   493,    59,
     125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   244,   245,   245,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   247,   247,   248,   248,
     248,   248,   248,   248,   249,   249,   250,   250,   250,   250,
     251,   252,   252,   253,   253,   253,   254,   255,   256,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   259,   260,   261,
     261,   262,   262,   263,   263,   264,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   276,   277,
     278,   279,   279,   280,   280,   280,   280,   281,   282,   283,
     284,   285,   285,   286,   286,   286,   287,   289,   288,   290,
     290,   291,   291,   291,   291,   292,   293,   293,   295,   294,
     296,   296,   297,   297,   297,   297,   297,   297,   297,   299,
     298,   300,   300,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   302,   303,   304,   305,   306,   307,   309,   308,
     310,   310,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   313,   312,   314,   314,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   315,   315,   315,   317,   316,   318,   318,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   319,   320,   321,   322,   323,   324,   325,   326,
     327,   328,   329,   330,   331,   332,   334,   333,   336,   335,
     337,   337,   338,   338,   338,   339,   339,   340,   340,   340,
     340,   340,   342,   341,   343,   343,   344,   344,   345,   346,
     348,   347,   349,   349,   350,   350,   350,   350,   350,   350,
     350,   350,   350,   351,   352,   353,   354,   356,   355,   357,
     357,   358,   358,   358,   358,   358,   358,   358,   358,   358,
     359,   360,   361,   363,   362,   364,   364,   365,   365,   365,
     365,   366,   367,   368,   369,   370,   370,   371,   371,   372,
     374,   373,   375,   375,   376,   376,   376,   376,   377,   378,
     380,   379,   381,   381,   382,   382,   382,   382,   382,   382,
     382,   382,   382,   382,   384,   383,   385,   385,   386,   386,
     386,   387,   389,   388,   390,   390,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   393,   392,   394,   394,
     395,   395,   395,   395,   395,   395,   395,   395,   395,   395,
     395,   395,   395,   395,   396,   397,   398,   399,   400,   401,
     402,   402,   404,   403,   405,   405,   406,   406,   406,   406,
     407,   408,   409,   410,   411,   413,   412,   415,   414,   416,
     416,   417,   418,   418,   419,   419,   419,   419,   420,   421,
     423,   422,   424,   424,   425,   425,   425,   426,   427,   428,
     429,   429,   430,   430,   431,   433,   432,   435,   434,   436,
     436,   437,   438,   438,   439,   439,   439,   439,   440,   441,
     442,   443,   443,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   444,   444,
     444,   444,   444,   444,   444,   444,   444,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   474,   475,
     475,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   492,   494,   493,
     495,   495,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   496,   496,   496,   496,   496,   496,   496,   496,
     496,   496,   498,   497,   499,   499,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   500,   500,   500,   500,
     500,   500,   500,   500,   500,   500,   501,   502,   503,   504,
     505,   506,   506,   507,   507,   507,   507,   507,   507,   507,
     507,   507,   507,   507,   507,   507,   507,   507,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   523,   524,   524,   524,   524,   524,
     524,   524,   525,   526,   527,   528,   529,   530
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
       1,     1,     1,     1,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     5,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4
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
       0,     0,    92,    93,    95,    94,   607,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   592,   606,   602,   594,   595,   596,   597,   598,
     593,   599,   600,   601,   603,   604,   605,     0,     0,     0,
     413,     0,     0,   411,   412,     0,   487,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   562,     0,
     538,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   432,   485,   477,   478,   479,   480,   481,   482,
     483,   476,   443,   433,   434,   470,   435,   436,   437,   438,
     439,   440,   441,   442,   473,   444,   445,   446,   447,   484,
     449,   454,   450,   452,   451,   465,   466,   453,   455,   456,
     457,   458,   459,   448,   461,   462,   463,   486,   474,   475,
     472,   464,   460,   468,   469,   467,   471,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   631,     0,     0,     0,
       0,     0,     0,     0,   624,   625,   626,   629,   627,   628,
     630,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   298,     0,     0,   296,
     297,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   591,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   199,
     202,   203,   205,   206,   207,   208,   209,   210,   211,   200,
     201,   204,     0,     0,     0,     0,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,   350,   351,
     352,   353,   354,   356,   355,   358,   362,   359,   360,   361,
     357,   406,     0,     0,     0,   403,   404,   405,     0,     0,
     410,   427,     0,     0,   417,   426,     0,   423,   424,   425,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   431,     0,     0,     0,   267,
       0,     0,     0,     0,     0,     0,   253,   254,   255,   256,
     261,   257,   258,   259,   260,   397,     0,   387,     0,   396,
       0,   393,   394,   395,     0,   228,     0,     0,     0,   238,
       0,   236,   237,   239,   240,   105,     0,     0,   101,     0,
      45,     0,     0,     0,    41,     0,     0,     0,   172,     0,
       0,     0,   148,     0,     0,   132,   133,   134,   135,   138,
     139,   137,   136,   140,     0,     0,     0,     0,     0,   286,
     287,   288,   289,     0,     0,     0,     0,     0,     0,     0,
     623,    66,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    49,     0,
       0,   310,     0,     0,   303,   304,   305,   306,     0,     0,
     332,     0,   327,   328,   329,     0,     0,   295,     0,     0,
       0,    90,     0,     0,     0,    26,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   590,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   363,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
       0,     0,     0,   402,     0,   409,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,   430,   262,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   252,
       0,     0,     0,     0,   392,   241,     0,     0,     0,     0,
       0,   235,     0,   100,     0,     0,     0,    40,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   131,   290,
       0,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,   622,     0,     0,     0,     0,     0,     0,     0,     0,
      71,    72,     0,    70,    75,    76,     0,    74,     0,     0,
       0,     0,     0,    48,   307,     0,     0,     0,     0,   302,
     330,     0,     0,     0,   326,     0,   294,    99,    98,    97,
     617,   616,   608,    26,    26,    26,    26,    26,    28,    27,
     610,   611,   615,   613,   612,   618,   619,   620,   621,   614,
     609,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,     0,   401,   414,     0,     0,     0,   416,   502,   506,
     522,   588,   536,   500,   530,   533,   501,   490,   489,   491,
     492,   493,   509,   498,   499,   512,   497,   511,   510,   505,
     504,   503,   531,   488,   529,   586,   587,   526,   523,   573,
     566,   583,   584,   567,   568,   569,   570,   578,   571,   581,
     585,   574,   579,   575,   580,   572,   577,   576,   582,     0,
     565,   528,   548,   542,   559,   560,   543,   544,   545,   546,
     554,   547,   557,   561,   550,   555,   551,   556,   549,   553,
     552,   558,     0,   541,   521,   524,   535,   495,   496,   525,
     514,   519,   520,   517,   518,   515,   516,   508,   507,    34,
      34,    34,    36,    35,   589,   534,   537,   527,   532,   494,
     513,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,     0,     0,   386,     0,     0,     0,   246,   242,   245,
     227,   106,     0,     0,   118,     0,     0,   110,   111,   113,
     112,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   284,   632,   636,   634,   637,
     633,   635,    83,    89,    81,    85,    84,    78,    77,    79,
      67,     0,    68,     0,    82,    80,    88,    86,    87,     0,
       0,     0,   301,     0,     0,   325,   299,    29,    30,    31,
      32,    33,   223,   224,   217,   219,   221,   220,   218,   213,
     225,   216,   214,   215,   222,   368,   370,   371,   383,   380,
     376,   377,   379,   378,     0,   375,   365,   381,   382,   364,
     369,   367,   384,   366,   407,   408,   428,   429,   421,     0,
     420,   563,     0,   539,     0,    37,    38,    39,   265,   266,
     275,   272,   277,   274,   273,   279,   276,   278,   271,     0,
     270,   264,   282,   281,   280,   263,   399,   391,     0,   390,
     398,   233,   234,   232,     0,   231,   249,   248,     0,     0,
       0,   114,     0,     0,     0,     0,   109,   147,   145,   187,
     184,   183,   176,   178,   194,   188,   191,   186,   177,   192,
     180,   189,   193,   181,   190,   185,   179,   182,     0,   175,
     142,   144,   146,   158,   152,   169,   170,   153,   154,   155,
     156,   164,   157,   167,   171,   160,   165,   161,   166,   159,
     163,   162,   168,     0,   151,   143,   292,   293,   291,    69,
      73,   308,   314,   320,   323,   316,   322,   317,   321,   319,
     315,   318,     0,   313,   309,   331,   336,   342,   345,   338,
     344,   339,   343,   341,   337,   340,     0,   335,   373,     0,
     418,     0,   564,   540,   268,     0,   388,     0,   229,     0,
     247,   244,   243,     0,     0,     0,     0,   108,   173,     0,
     149,     0,   311,     0,   333,     0,   374,   419,   269,   389,
     230,   115,   124,   127,   126,   123,   128,   125,   122,     0,
     121,   117,   116,   174,   150,   312,   334,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   798,   799,   942,   943,    25,   240,   241,
     242,   243,    26,   277,   278,   279,   280,   762,   763,   766,
     767,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,    27,    71,    72,    73,    74,    75,
      28,   232,   233,   234,   235,   236,   976,   977,   978,   979,
     980,  1113,  1239,  1240,    29,    60,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   735,  1163,  1164,   523,   731,
    1138,  1139,    30,    49,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,    31,
      57,   489,   716,  1104,  1105,   490,   491,   492,  1110,   968,
     969,   493,   494,    32,    55,   465,   466,   467,   468,   469,
     470,   471,   702,  1089,  1090,   472,   473,   474,    33,    61,
     528,   529,   530,   531,   532,    34,   298,   299,   300,    35,
      64,   563,   564,   565,   566,   567,   776,  1182,  1183,    36,
      65,   571,   572,   573,   574,   782,  1196,  1197,    37,    50,
     366,   367,   368,   369,   370,   371,   372,   373,   374,   375,
     619,  1054,  1055,   376,   377,   378,   379,   380,    38,    56,
     479,   711,  1098,  1099,   480,   481,   482,   483,    39,    51,
     384,   385,   386,   387,    40,   112,   113,   114,    41,    53,
     395,   638,  1069,  1070,   396,   397,   398,   399,    42,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     433,   922,   923,   222,   431,   899,   900,   223,   224,   225,
     226,    43,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    44,   253,
     254,   255,   256,   257,   258,   259,   260
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -599
static const yytype_int16 yypact[] =
{
    -599,   612,  -599,  -201,  -214,  -197,  -599,  -599,  -599,  -177,
    -599,  -171,  -599,  -599,  -599,  -163,  -160,  -599,  -599,  -158,
    -152,  -599,  -599,  -150,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,    42,   864,  -147,
    -137,  -130,     7,  -112,   378,  -103,   -76,   -56,    86,   233,
     -45,   -30,   322,   418,   -14,   -11,    22,  -190,  -186,   -32,
      -9,    10,  -599,  -599,  -599,  -599,  -599,    -3,    38,    53,
      57,    60,    62,    78,    91,    93,   102,   107,   108,   109,
     110,   204,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,   801,   503,    12,
    -599,   113,    18,  -599,  -599,    54,  -599,   114,   116,   119,
     123,   124,   127,   130,   131,   132,   134,   135,   138,   146,
     147,   149,   152,   156,   157,   159,   161,   163,   166,   167,
     172,   174,   175,   176,   178,   180,   181,   182,  -599,   184,
    -599,   187,   188,   192,   193,   194,   196,   199,   201,   203,
     207,   209,   213,   215,   216,   217,   218,   220,   222,   228,
     243,    98,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,   331,   197,    25,
      59,   245,    56,  -599,  -599,  -599,     8,   200,   248,   249,
      45,  -599,  -599,  -599,   367,    11,  -599,   255,   257,   261,
     265,   266,   268,     5,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,   273,   271,   275,   280,   281,   282,   283,   285,   286,
     287,   288,   295,   296,   298,   300,   302,   160,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,    20,    31,  -599,   304,    34,  -599,
    -599,  -599,   133,   183,   186,   276,  -599,   438,   444,   384,
     445,   445,   452,   459,   461,   396,   397,   464,   445,   399,
     400,   339,  -599,   345,   343,   344,   347,   348,   349,   350,
     351,   352,   354,   355,   358,   362,   363,   155,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,   369,   368,   373,   374,   377,  -599,   382,   383,
     385,   386,   387,   388,   389,   392,    19,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,   395,   398,    35,  -599,  -599,  -599,   456,   372,
    -599,  -599,   401,   403,  -599,  -599,    13,  -599,  -599,  -599,
     450,   445,   445,   511,   462,   463,   532,   515,   471,   445,
     472,   445,   539,   542,   543,   479,   480,   484,   445,   533,
     487,   555,   556,   445,   558,   560,   540,   562,   564,   500,
     501,   436,   504,   437,   445,   445,   505,   445,   508,   514,
     520,  -115,   -59,   521,   524,   445,   445,   572,   573,   445,
     527,   530,   531,   537,   447,  -599,   448,   466,   473,  -599,
     474,   477,   481,   486,   488,   212,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,   489,  -599,   490,  -599,
      51,  -599,  -599,  -599,   475,  -599,   492,   494,   496,  -599,
       9,  -599,  -599,  -599,  -599,  -599,   550,   502,  -599,   498,
    -599,   598,   611,   507,  -599,   509,   512,   513,  -599,   516,
     517,   518,  -599,   519,   253,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,   523,   522,   546,   548,    17,  -599,
    -599,  -599,  -599,   567,   569,   616,   574,   575,   445,   526,
    -599,  -599,   618,   576,   622,   625,   626,   635,   650,   651,
     -53,    33,   653,   662,   684,   674,   675,   571,  -599,   578,
     577,  -599,   583,   100,  -599,  -599,  -599,  -599,   588,   586,
    -599,    75,  -599,  -599,  -599,   680,   590,  -599,   593,   594,
     595,  -599,   601,   602,   606,   379,   610,   617,   619,   623,
     628,   629,   631,   632,   633,   634,   636,  -599,  -599,   703,
     740,   445,   742,   751,   754,   764,   746,   768,   769,   445,
     445,   572,   641,  -599,  -599,   750,     4,   753,   706,   643,
     755,   756,   763,   765,   785,   767,   771,   772,   661,  -599,
     773,   774,   667,  -599,   668,  -599,   777,   778,   669,   671,
    -599,   673,   676,   677,   678,   679,   681,   682,   683,   685,
     686,   688,   689,   692,   693,   694,   696,   697,   698,   699,
     700,   701,   704,   705,   707,   708,   712,   713,   714,   715,
     716,   717,   584,   718,   613,   719,   721,   722,   723,   724,
     725,   726,   727,   728,   729,   730,   733,   734,   735,   736,
       2,   737,   739,   741,   743,   744,   745,   748,  -599,  -599,
     788,   747,   749,   814,   869,   850,   857,   858,   758,  -599,
     859,   752,   861,   759,  -599,  -599,   757,   862,   870,   890,
     770,  -599,   775,  -599,     3,   776,   779,  -599,  -599,   871,
     827,   762,   875,   876,   877,   780,   879,   781,  -599,  -599,
     880,   881,   882,   782,  -599,   784,   786,   787,   789,   790,
     791,  -599,   792,   793,   794,   795,   796,   797,   798,   799,
    -599,  -599,  -236,  -599,  -599,  -599,  -215,  -599,   800,   802,
     803,   804,   805,  -599,  -599,   885,   806,   886,   807,  -599,
    -599,   888,   808,   810,  -599,   812,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,   445,   445,   445,   445,   445,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,   813,   815,   816,   817,   818,   819,   820,   821,   822,
     823,   824,   826,   828,  -599,   829,   830,   831,   832,   833,
     148,   834,   835,   836,   837,   838,   839,   840,   841,  -599,
     842,   843,  -599,  -599,   844,   845,   891,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -210,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -209,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   572,
     572,   572,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,   846,   847,   825,   848,   849,   851,   852,   853,  -599,
     854,   904,   855,  -599,     0,   856,   860,   866,   863,  -599,
    -599,  -599,   865,   811,  -599,   867,    72,  -599,  -599,  -599,
    -599,  -599,  -599,   868,   872,   483,   873,   874,   878,   652,
     883,  -599,   884,   887,   889,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,   -53,  -599,    33,  -599,  -599,  -599,  -599,  -599,   892,
     506,   893,  -599,   894,   510,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -198,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -192,
    -599,  -599,   584,  -599,   613,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -185,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -168,  -599,
    -599,  -599,  -599,  -599,  -116,  -599,  -599,  -599,   914,   890,
     895,  -599,   933,   896,  -105,   897,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   -80,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,   -40,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,   -31,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,   -20,  -599,  -599,   148,
    -599,   891,  -599,  -599,  -599,   825,  -599,   904,  -599,     0,
    -599,  -599,  -599,   898,   291,   900,   901,  -599,  -599,   483,
    -599,   652,  -599,   506,  -599,   510,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   -15,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,   291,  -599
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -599,  -599,  -599,  -317,  -309,  -598,  -447,  -599,  -599,   902,
    -599,  -599,  -599,  -599,   899,  -599,  -599,  -599,    55,  -599,
      32,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  1018,  -599,  -599,  -599,
    -599,  -599,   903,  -599,  -599,  -599,  -599,   120,  -599,  -599,
    -599,  -599,  -599,  -151,  -599,  -599,  -599,   587,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -123,  -599,  -599,
    -599,  -119,  -599,  -599,  -599,   766,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -107,  -599,   615,  -599,  -599,  -599,
      -1,  -599,  -599,  -599,  -599,  -599,   645,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,   -91,  -599,  -599,  -599,  -599,  -599,
    -599,   591,  -599,  -599,  -599,  -599,  -599,   905,  -599,  -599,
    -599,  -599,   552,  -599,  -599,  -599,  -599,  -599,  -102,  -599,
    -599,  -599,   545,  -599,  -599,  -599,  -599,  -101,  -599,  -599,
    -599,   761,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,   -81,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,   -87,  -599,   649,  -599,  -599,  -599,  -599,
    -599,   760,  -599,  -599,  -599,  -599,  1013,  -599,  -599,  -599,
    -599,  -599,  -599,   -71,  -599,   783,  -599,  -599,  -599,  -599,
     970,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,    69,  -599,  -599,  -599,    73,  -599,  -599,  -599,
    -599,  -599,  -599,  1055,  -599,  -599,  -599,  -599,  -599,  -599,
    -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,  -599,
     906,  -599,  -599,  -599,  -599,  -599,  -599
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     691,   586,   587,  1010,   972,   690,   246,  1011,   110,   594,
     484,    67,   524,   381,   391,   939,   940,   941,   524,   110,
     352,   559,   353,   296,  1012,   354,   484,    47,  1013,  1071,
    1073,   525,   568,  1072,  1074,   296,   381,   525,    45,    46,
      68,  1198,   355,    67,    48,  1199,   237,  1200,    69,   301,
     247,  1201,   475,   485,  1204,   391,   302,   230,  1205,   356,
    1101,   682,   683,   357,    52,   248,   249,   250,   251,   485,
      54,  1206,    68,   972,   486,  1207,   568,   111,    58,   487,
      69,    59,   382,    62,   358,   252,   359,   230,   111,    63,
     486,    66,   642,   643,   107,   487,   760,   761,   360,   116,
     650,   559,   652,   973,   108,   382,   117,   118,  1215,   659,
      70,   109,   690,   392,   664,   526,   119,   684,   685,   361,
     560,   526,   297,  1208,   120,   675,   676,  1209,   678,   115,
     121,   569,   122,   123,   297,   124,   688,   689,   227,   488,
     693,   125,    70,   238,   527,   383,   393,   126,   127,   362,
     527,   128,   129,   130,   392,   488,   323,   131,  1050,  1218,
    1051,   261,   132,  1219,   823,   228,   133,   134,   383,   974,
     135,   239,   973,   136,   137,   569,   324,   325,   363,   394,
     326,   138,   764,   765,   476,   229,   561,   393,   139,   140,
     262,   141,   142,   143,   144,   145,   244,   570,   475,  1220,
     560,   826,   827,  1221,  1102,    76,   146,   364,  1222,  1103,
     303,   245,  1223,   456,   147,   148,   149,   477,   150,  1224,
     394,   151,   152,  1225,  1247,   153,   263,   294,  1248,   750,
     295,    77,    78,   304,   237,   457,   154,    79,   974,   307,
     975,   570,   327,   328,   329,   539,   499,   330,   562,   720,
     305,   365,   458,   639,   505,   331,   459,   743,   389,   628,
     264,   155,   265,   266,   578,   156,   561,   332,   333,   157,
     158,   159,   160,   161,   576,   632,   506,   162,   163,   478,
     308,    80,    81,   334,   335,   503,   231,   164,    82,    83,
      84,   713,   813,   507,  -107,   309,   497,   508,   495,   310,
     821,   822,   311,   267,   312,   268,   269,   270,   271,   975,
      85,    86,  1115,   336,   579,   783,   231,   580,   165,   166,
     313,   167,   272,   246,  -107,    87,    88,   168,   562,   169,
     476,   238,   456,   314,   170,   315,    89,   460,   454,  1232,
     778,  1075,  1076,  1077,   316,    90,   461,   462,   273,   317,
     318,   319,   320,   509,   457,   388,   400,  1052,   401,   239,
     274,   402,  1233,   477,  1234,   403,   404,   247,   505,   405,
    1053,   458,   406,   407,   408,   459,   409,   410,   510,   116,
     411,   463,   248,   249,   250,   251,   117,   118,   412,   413,
     506,   414,   275,   276,   415,   612,   119,   511,   416,   417,
     557,   418,   252,   419,   120,   420,  1235,   507,   421,   422,
     121,   508,   122,   123,   423,   124,   424,   425,   426,   261,
     427,   125,   428,   429,   430,   478,   432,   126,   127,   434,
     435,   128,   129,   130,   436,   437,   438,   131,   439,   500,
     464,   440,   132,   441,   321,   442,   133,   134,   262,   443,
     135,   444,   708,   136,   137,   445,   460,   446,   447,   448,
     449,   138,   450,   512,   451,   461,   462,   509,   139,   140,
     452,   141,   142,   143,   144,   145,  1027,  1028,  1029,  1030,
    1031,   513,  1236,  1237,   263,   453,   146,   496,  1119,   585,
     501,   502,   510,   737,   147,   148,   149,   533,   150,   534,
     463,   151,   152,   535,   352,   153,   353,   536,   537,   354,
     538,   511,   541,   542,  1120,   581,   154,   543,   264,  1238,
     265,   266,   544,   545,   546,   547,   355,   548,   549,   550,
     551,  1121,   793,   794,   795,   796,   797,   552,   553,  1122,
     554,   155,   555,   356,   556,   156,   575,   357,   582,   157,
     158,   159,   160,   161,   583,   585,  1123,   162,   163,   464,
     584,   267,   588,   268,   269,   270,   271,   164,   358,   589,
     359,   590,   591,   592,   593,   595,   596,   512,   597,  1172,
     272,  1124,   360,  1186,   598,   599,   600,   634,  1125,   601,
     602,   603,   604,   605,   606,   513,   607,   608,   165,   166,
     609,   167,  1126,   361,   610,   611,   273,   168,   614,   169,
     615,   635,     2,     3,   170,   616,   617,     4,   274,   618,
    1127,   644,  1128,  1129,   620,   621,   641,   622,   623,   624,
     625,   626,     5,   362,   627,     6,     7,   630,   645,   646,
     631,     8,   647,   636,   879,   637,   648,   649,   651,   653,
     275,   276,   654,   655,     9,   656,   657,  1173,    10,    11,
     658,  1187,   363,   661,   660,   662,   663,  1216,   665,    12,
     666,   667,   668,   902,   669,  1130,   670,   671,   672,   674,
     673,   677,   690,    13,   679,  1131,   698,   699,  1174,  1132,
     680,   364,  1188,    14,    15,  1133,   681,   686,  1175,  1134,
     687,  1135,  1189,   694,   692,  1176,   695,   696,   700,  1190,
    1136,    16,  1143,   697,   715,   701,   703,  1137,  1177,   704,
    1178,  1179,  1191,   705,  1192,  1193,   722,    17,   706,   725,
     707,   710,   712,  1180,   717,   365,   718,  1194,   719,   724,
    1181,   723,   726,   745,  1195,   746,   727,   747,   728,   752,
     748,   749,   753,   754,   729,   730,   755,   756,   732,   733,
     734,   736,   739,    18,   740,   751,   757,   880,   881,   882,
     883,   884,    19,    20,   885,   886,    21,    22,   887,   888,
     889,   758,   759,   890,   768,   891,   892,   893,   741,   894,
     742,   895,   896,   769,   770,   897,   903,   904,   905,   906,
     907,   898,   323,   908,   909,   771,   772,   910,   911,   912,
     773,   785,   913,   811,   914,   915,   916,   774,   917,   775,
     918,   919,   324,   325,   920,   777,   326,   780,   781,   786,
     921,    23,   787,   788,   789,  1144,  1145,  1146,  1147,  1148,
     790,   791,  1149,  1150,  1080,   792,  1151,  1152,  1153,   800,
     812,  1154,   814,  1155,  1156,  1157,   801,  1158,   802,  1159,
    1160,   815,   803,  1161,   816,    76,  1081,   804,   805,  1162,
     806,   807,   808,   809,   817,   810,  1082,   818,   819,   820,
     824,   825,   829,  1083,   828,   830,   831,   832,   327,   328,
     329,    77,    78,   330,   833,   835,   834,    79,   836,  1084,
     839,   331,   837,   838,   840,   841,   842,   843,   844,   845,
     847,   846,   848,   332,   333,   849,   850,   851,   852,   951,
     853,   854,   855,   952,   856,   857,  1085,   858,   859,   334,
     335,   860,   861,   862,  1086,   863,   864,   865,   866,   867,
     868,    80,    81,   869,   870,   954,   871,   872,    82,    83,
      84,   873,   874,   875,   876,   877,   878,   901,   924,   336,
     925,   926,   927,   928,   929,   930,   931,   932,   933,   934,
      85,    86,   935,   936,   937,   938,   944,  1087,   945,   955,
     946,   956,   947,   948,   949,    87,    88,   950,   957,   958,
     960,   953,   962,   965,   961,  1088,    89,   959,   963,   964,
     967,   966,   983,   984,   985,    90,   986,   987,   988,   970,
     990,   992,   993,   994,   971,   981,  1019,  1021,   982,  1023,
     991,   995,   989,   996,  1210,   997,   998,  1068,   999,  1000,
    1001,  1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1014,
    1097,  1015,  1016,  1017,  1018,  1170,  1022,  1108,  1020,  1025,
    1024,  1026,  1032,  1112,  1033,  1034,  1035,  1036,  1037,  1038,
    1039,  1040,  1041,  1042,  1213,  1043,  1169,  1044,  1045,  1046,
    1047,  1048,  1049,  1056,  1057,  1058,  1059,  1060,  1061,  1062,
    1063,  1064,  1065,  1066,  1067,  1078,  1079,  1091,  1092,   306,
    1093,  1094,  1095,  1096,  1100,  1106,  1116,  1249,  1244,  1107,
    1243,   738,  1230,   613,  1111,   721,  1109,  1117,  1211,  1114,
     709,  1118,  1140,  1141,  1228,   779,   784,  1142,  1226,   744,
    1229,  1245,  1165,  1166,  1246,   390,  1167,   629,  1168,   714,
    1227,  1171,  1184,  1185,  1212,   498,  1217,  1231,  1214,  1241,
    1242,   455,   504,  1203,   633,  1202,   322,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   540,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   558,     0,     0,   640,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   577
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-599))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     447,   310,   311,   239,     1,   110,     1,   243,     1,   318,
       1,     1,     1,     1,     1,    13,    14,    15,     1,     1,
       1,     1,     3,     1,   239,     6,     1,   241,   243,   239,
     239,    20,     1,   243,   243,     1,     1,    20,   239,   240,
      30,   239,    23,     1,   241,   243,     1,   239,    38,   239,
      45,   243,     1,    44,   239,     1,   242,     1,   243,    40,
      60,   176,   177,    44,   241,    60,    61,    62,    63,    44,
     241,   239,    30,     1,    65,   243,     1,    70,   241,    70,
      38,   241,    70,   241,    65,    80,    67,     1,    70,   241,
      65,   241,   401,   402,   241,    70,   149,   150,    79,     1,
     409,     1,   411,   100,   241,    70,     8,     9,   213,   418,
     100,   241,   110,   100,   423,   104,    18,   176,   177,   100,
     100,   104,   100,   239,    26,   434,   435,   243,   437,   241,
      32,   100,    34,    35,   100,    37,   445,   446,   241,   130,
     449,    43,   100,    98,   133,   133,   133,    49,    50,   130,
     133,    53,    54,    55,   100,   130,     1,    59,    10,   239,
      12,     1,    64,   243,   611,   241,    68,    69,   133,   166,
      72,   126,   100,    75,    76,   100,    21,    22,   159,   166,
      25,    83,   149,   150,   133,   241,   166,   133,    90,    91,
      30,    93,    94,    95,    96,    97,   241,   166,     1,   239,
     100,   197,   198,   243,   204,     1,   108,   188,   239,   209,
     242,   241,   243,     1,   116,   117,   118,   166,   120,   239,
     166,   123,   124,   243,   239,   127,    66,   241,   243,   538,
     241,    27,    28,   242,     1,    23,   138,    33,   166,   242,
     237,   166,    87,    88,    89,   240,   238,    92,   228,   240,
     240,   232,    40,   240,     1,   100,    44,   240,   240,   240,
     100,   163,   102,   103,   131,   167,   166,   112,   113,   171,
     172,   173,   174,   175,   240,   240,    23,   179,   180,   228,
     242,    77,    78,   128,   129,   240,   230,   189,    84,    85,
      86,   240,   601,    40,   238,   242,   240,    44,   239,   242,
     609,   610,   242,   143,   242,   145,   146,   147,   148,   237,
     106,   107,   240,   158,   131,   240,   230,   131,   220,   221,
     242,   223,   162,     1,   238,   121,   122,   229,   228,   231,
     133,    98,     1,   242,   236,   242,   132,   125,   240,    48,
     240,   939,   940,   941,   242,   141,   134,   135,   188,   242,
     242,   242,   242,   100,    23,   242,   242,   209,   242,   126,
     200,   242,    71,   166,    73,   242,   242,    45,     1,   242,
     222,    40,   242,   242,   242,    44,   242,   242,   125,     1,
     242,   169,    60,    61,    62,    63,     8,     9,   242,   242,
      23,   242,   232,   233,   242,   240,    18,   144,   242,   242,
     240,   242,    80,   242,    26,   242,   115,    40,   242,   242,
      32,    44,    34,    35,   242,    37,   242,   242,   242,     1,
     242,    43,   242,   242,   242,   228,   242,    49,    50,   242,
     242,    53,    54,    55,   242,   242,   242,    59,   242,   239,
     228,   242,    64,   242,   240,   242,    68,    69,    30,   242,
      72,   242,   240,    75,    76,   242,   125,   242,   242,   242,
     242,    83,   242,   210,   242,   134,   135,   100,    90,    91,
     242,    93,    94,    95,    96,    97,   793,   794,   795,   796,
     797,   228,   191,   192,    66,   242,   108,   242,     5,   110,
     242,   242,   125,   240,   116,   117,   118,   242,   120,   242,
     169,   123,   124,   242,     1,   127,     3,   242,   242,     6,
     242,   144,   239,   242,    31,   239,   138,   242,   100,   228,
     102,   103,   242,   242,   242,   242,    23,   242,   242,   242,
     242,    48,   153,   154,   155,   156,   157,   242,   242,    56,
     242,   163,   242,    40,   242,   167,   242,    44,   110,   171,
     172,   173,   174,   175,   110,   110,    73,   179,   180,   228,
     176,   143,   110,   145,   146,   147,   148,   189,    65,   110,
      67,   110,   176,   176,   110,   176,   176,   210,   239,    73,
     162,    98,    79,    73,   239,   242,   242,   131,   105,   242,
     242,   242,   242,   242,   242,   228,   242,   242,   220,   221,
     242,   223,   119,   100,   242,   242,   188,   229,   239,   231,
     242,   239,     0,     1,   236,   242,   242,     5,   200,   242,
     137,   110,   139,   140,   242,   242,   176,   242,   242,   242,
     242,   242,    20,   130,   242,    23,    24,   242,   176,   176,
     242,    29,   110,   242,    60,   242,   131,   176,   176,   110,
     232,   233,   110,   110,    42,   176,   176,   151,    46,    47,
     176,   151,   159,   176,   131,   110,   110,  1114,   110,    57,
     110,   131,   110,    60,   110,   192,   176,   176,   242,   242,
     176,   176,   110,    71,   176,   202,   239,   239,   182,   206,
     176,   188,   182,    81,    82,   212,   176,   176,   192,   216,
     176,   218,   192,   176,   131,   199,   176,   176,   242,   199,
     227,    99,    60,   176,   239,   242,   242,   234,   212,   242,
     214,   215,   212,   242,   214,   215,   176,   115,   242,   131,
     242,   242,   242,   227,   242,   232,   242,   227,   242,   241,
     234,   239,   131,   176,   234,   176,   239,   131,   239,   131,
     176,   176,   176,   131,   242,   242,   131,   131,   242,   242,
     242,   242,   239,   151,   242,   239,   131,   183,   184,   185,
     186,   187,   160,   161,   190,   191,   164,   165,   194,   195,
     196,   131,   131,   199,   131,   201,   202,   203,   242,   205,
     242,   207,   208,   131,   110,   211,   183,   184,   185,   186,
     187,   217,     1,   190,   191,   131,   131,   194,   195,   196,
     239,   131,   199,   110,   201,   202,   203,   239,   205,   242,
     207,   208,    21,    22,   211,   242,    25,   239,   242,   239,
     217,   219,   239,   239,   239,   183,   184,   185,   186,   187,
     239,   239,   190,   191,    19,   239,   194,   195,   196,   239,
     110,   199,   110,   201,   202,   203,   239,   205,   239,   207,
     208,   110,   239,   211,   110,     1,    41,   239,   239,   217,
     239,   239,   239,   239,   110,   239,    51,   131,   110,   110,
     239,   131,   176,    58,   131,   242,   131,   131,    87,    88,
      89,    27,    28,    92,   131,   110,   131,    33,   131,    74,
     239,   100,   131,   131,   131,   131,   239,   239,   131,   131,
     239,   242,   239,   112,   113,   239,   239,   239,   239,   131,
     239,   239,   239,   176,   239,   239,   101,   239,   239,   128,
     129,   239,   239,   239,   109,   239,   239,   239,   239,   239,
     239,    77,    78,   239,   239,   131,   239,   239,    84,    85,
      86,   239,   239,   239,   239,   239,   239,   239,   239,   158,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     106,   107,   239,   239,   239,   239,   239,   152,   239,   110,
     239,   131,   239,   239,   239,   121,   122,   239,   131,   131,
     131,   242,   131,   131,   242,   170,   132,   239,   239,   242,
     110,   131,   131,   176,   242,   141,   131,   131,   131,   239,
     131,   131,   131,   131,   239,   239,   131,   131,   239,   131,
     239,   239,   242,   239,   110,   239,   239,   136,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     136,   239,   239,   239,   239,  1013,   239,   181,   242,   239,
     242,   239,   239,   242,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   131,   239,  1011,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,    71,
     239,   239,   239,   239,   239,   239,   976,  1248,  1221,   239,
    1219,   514,  1209,   337,   239,   490,   243,   239,  1109,   242,
     465,   239,   239,   239,  1205,   563,   571,   239,  1199,   528,
    1207,  1223,   239,   239,  1225,   112,   239,   366,   239,   480,
    1201,   239,   239,   239,   239,   232,   239,   239,   242,   239,
     239,   171,   240,  1074,   384,  1072,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   253,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   277,    -1,    -1,   396,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   298
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   245,     0,     1,     5,    20,    23,    24,    29,    42,
      46,    47,    57,    71,    81,    82,    99,   115,   151,   160,
     161,   164,   165,   219,   246,   251,   256,   278,   284,   298,
     316,   333,   347,   362,   369,   373,   383,   392,   412,   422,
     428,   432,   442,   505,   522,   239,   240,   241,   241,   317,
     393,   423,   241,   433,   241,   348,   413,   334,   241,   241,
     299,   363,   241,   241,   374,   384,   241,     1,    30,    38,
     100,   279,   280,   281,   282,   283,     1,    27,    28,    33,
      77,    78,    84,    85,    86,   106,   107,   121,   122,   132,
     141,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   241,   241,   241,
       1,    70,   429,   430,   431,   241,     1,     8,     9,    18,
      26,    32,    34,    35,    37,    43,    49,    50,    53,    54,
      55,    59,    64,    68,    69,    72,    75,    76,    83,    90,
      91,    93,    94,    95,    96,    97,   108,   116,   117,   118,
     120,   123,   124,   127,   138,   163,   167,   171,   172,   173,
     174,   175,   179,   180,   189,   220,   221,   223,   229,   231,
     236,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   465,   466,   467,   468,   469,   470,   471,
     472,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   497,   501,   502,   503,   504,   241,   241,   241,
       1,   230,   285,   286,   287,   288,   289,     1,    98,   126,
     252,   253,   254,   255,   241,   241,     1,    45,    60,    61,
      62,    63,    80,   523,   524,   525,   526,   527,   528,   529,
     530,     1,    30,    66,   100,   102,   103,   143,   145,   146,
     147,   148,   162,   188,   200,   232,   233,   257,   258,   259,
     260,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   241,   241,     1,   100,   370,   371,
     372,   239,   242,   242,   242,   240,   280,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   240,   507,     1,    21,    22,    25,    87,    88,    89,
      92,   100,   112,   113,   128,   129,   158,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
     331,   332,     1,     3,     6,    23,    40,    44,    65,    67,
      79,   100,   130,   159,   188,   232,   394,   395,   396,   397,
     398,   399,   400,   401,   402,   403,   407,   408,   409,   410,
     411,     1,    70,   133,   424,   425,   426,   427,   242,   240,
     430,     1,   100,   133,   166,   434,   438,   439,   440,   441,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   498,   242,   494,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   240,   444,     1,    23,    40,    44,
     125,   134,   135,   169,   228,   349,   350,   351,   352,   353,
     354,   355,   359,   360,   361,     1,   133,   166,   228,   414,
     418,   419,   420,   421,     1,    44,    65,    70,   130,   335,
     339,   340,   341,   345,   346,   239,   242,   240,   286,   238,
     239,   242,   242,   240,   253,     1,    23,    40,    44,   100,
     125,   144,   210,   228,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   312,     1,    20,   104,   133,   364,   365,
     366,   367,   368,   242,   242,   242,   242,   242,   242,   240,
     524,   239,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   240,   258,     1,
     100,   166,   228,   375,   376,   377,   378,   379,     1,   100,
     166,   385,   386,   387,   388,   242,   240,   371,   131,   131,
     131,   239,   110,   110,   176,   110,   248,   248,   110,   110,
     110,   176,   176,   110,   248,   176,   176,   239,   239,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   240,   319,   239,   242,   242,   242,   242,   404,
     242,   242,   242,   242,   242,   242,   242,   242,   240,   395,
     242,   242,   240,   425,   131,   239,   242,   242,   435,   240,
     439,   176,   248,   248,   110,   176,   176,   110,   131,   176,
     248,   176,   248,   110,   110,   110,   176,   176,   176,   248,
     131,   176,   110,   110,   248,   110,   110,   131,   110,   110,
     176,   176,   242,   176,   242,   248,   248,   176,   248,   176,
     176,   176,   176,   177,   176,   177,   176,   176,   248,   248,
     110,   250,   131,   248,   176,   176,   176,   176,   239,   239,
     242,   242,   356,   242,   242,   242,   242,   242,   240,   350,
     242,   415,   242,   240,   419,   239,   336,   242,   242,   242,
     240,   340,   176,   239,   241,   131,   131,   239,   239,   242,
     242,   313,   242,   242,   242,   309,   242,   240,   301,   239,
     242,   242,   242,   240,   365,   176,   176,   131,   176,   176,
     248,   239,   131,   176,   131,   131,   131,   131,   131,   131,
     149,   150,   261,   262,   149,   150,   263,   264,   131,   131,
     110,   131,   131,   239,   239,   242,   380,   242,   240,   376,
     239,   242,   389,   240,   386,   131,   239,   239,   239,   239,
     239,   239,   239,   153,   154,   155,   156,   157,   247,   248,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   110,   110,   248,   110,   110,   110,   110,   131,   110,
     110,   248,   248,   250,   239,   131,   197,   198,   131,   176,
     242,   131,   131,   131,   131,   110,   131,   131,   131,   239,
     131,   131,   239,   239,   131,   131,   242,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,    60,
     183,   184,   185,   186,   187,   190,   191,   194,   195,   196,
     199,   201,   202,   203,   205,   207,   208,   211,   217,   499,
     500,   239,    60,   183,   184,   185,   186,   187,   190,   191,
     194,   195,   196,   199,   201,   202,   203,   205,   207,   208,
     211,   217,   495,   496,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,    13,
      14,    15,   249,   250,   239,   239,   239,   239,   239,   239,
     239,   131,   176,   242,   131,   110,   131,   131,   131,   239,
     131,   242,   131,   239,   242,   131,   131,   110,   343,   344,
     239,   239,     1,   100,   166,   237,   290,   291,   292,   293,
     294,   239,   239,   131,   176,   242,   131,   131,   131,   242,
     131,   239,   131,   131,   131,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   243,   239,   243,   239,   239,   239,   239,   239,   131,
     242,   131,   239,   131,   242,   239,   239,   247,   247,   247,
     247,   247,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
      10,    12,   209,   222,   405,   406,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   136,   436,
     437,   239,   243,   239,   243,   249,   249,   249,   239,   239,
      19,    41,    51,    58,    74,   101,   109,   152,   170,   357,
     358,   239,   239,   239,   239,   239,   239,   136,   416,   417,
     239,    60,   204,   209,   337,   338,   239,   239,   181,   243,
     342,   239,   242,   295,   242,   240,   291,   239,   239,     5,
      31,    48,    56,    73,    98,   105,   119,   137,   139,   140,
     192,   202,   206,   212,   216,   218,   227,   234,   314,   315,
     239,   239,   239,    60,   183,   184,   185,   186,   187,   190,
     191,   194,   195,   196,   199,   201,   202,   203,   205,   207,
     208,   211,   217,   310,   311,   239,   239,   239,   239,   262,
     264,   239,    73,   151,   182,   192,   199,   212,   214,   215,
     227,   234,   381,   382,   239,   239,    73,   151,   182,   192,
     199,   212,   214,   215,   227,   234,   390,   391,   239,   243,
     239,   243,   500,   496,   239,   243,   239,   243,   239,   243,
     110,   344,   239,   131,   242,   213,   250,   239,   239,   243,
     239,   243,   239,   243,   239,   243,   406,   437,   358,   417,
     338,   239,    48,    71,    73,   115,   191,   192,   228,   296,
     297,   239,   239,   315,   311,   382,   391,   239,   243,   297
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
/* Line 1787 of yacc.c  */
#line 381 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 383 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 387 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 391 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 395 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 399 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 403 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 409 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 410 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 411 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 457 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 463 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 472 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 478 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 486 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 525 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 584 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 612 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 620 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 635 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 650 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:
/* Line 1787 of yacc.c  */
#line 659 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 673 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 682 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 710 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 740 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 763 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 778 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 787 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 796 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 814 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 820 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 837 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 842 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 845 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 865 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 869 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 877 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 881 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 891 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 904 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 994 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:
/* Line 1787 of yacc.c  */
#line 1003 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1040 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1052 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1063 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1105 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:
/* Line 1787 of yacc.c  */
#line 1114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1121 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1145 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1149 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1218 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1226 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1230 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1234 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:
/* Line 1787 of yacc.c  */
#line 1299 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1357 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:
/* Line 1787 of yacc.c  */
#line 1366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1378 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1384 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1396 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1402 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1420 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1457 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:
/* Line 1787 of yacc.c  */
#line 1463 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:
/* Line 1787 of yacc.c  */
#line 1467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:
/* Line 1787 of yacc.c  */
#line 1481 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:
/* Line 1787 of yacc.c  */
#line 1486 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1500 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1520 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:
/* Line 1787 of yacc.c  */
#line 1529 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:
/* Line 1787 of yacc.c  */
#line 1541 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1553 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1615 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1650 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1663 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:
/* Line 1787 of yacc.c  */
#line 1672 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1683 "conf_parser.y"
    {
}
    break;

  case 271:
/* Line 1787 of yacc.c  */
#line 1688 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:
/* Line 1787 of yacc.c  */
#line 1692 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1700 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1704 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1708 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1727 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1746 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1756 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:
/* Line 1787 of yacc.c  */
#line 1769 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:
/* Line 1787 of yacc.c  */
#line 1788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:
/* Line 1787 of yacc.c  */
#line 1797 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1812 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:
/* Line 1787 of yacc.c  */
#line 1830 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1845 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:
/* Line 1787 of yacc.c  */
#line 1864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:
/* Line 1787 of yacc.c  */
#line 1873 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1895 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 314:
/* Line 1787 of yacc.c  */
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 315:
/* Line 1787 of yacc.c  */
#line 1906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1926 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1934 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1938 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1954 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1967 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:
/* Line 1787 of yacc.c  */
#line 1973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:
/* Line 1787 of yacc.c  */
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:
/* Line 1787 of yacc.c  */
#line 1984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 2004 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 2016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2025 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2040 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:
/* Line 1787 of yacc.c  */
#line 2093 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 366:
/* Line 1787 of yacc.c  */
#line 2102 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2128 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2146 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:
/* Line 1787 of yacc.c  */
#line 2170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 371:
/* Line 1787 of yacc.c  */
#line 2174 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2182 "conf_parser.y"
    {
}
    break;

  case 376:
/* Line 1787 of yacc.c  */
#line 2187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 377:
/* Line 1787 of yacc.c  */
#line 2191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAwayBurst(yy_aconf);
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfTopicBurst(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2205 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2216 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2227 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:
/* Line 1787 of yacc.c  */
#line 2247 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2265 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:
/* Line 1787 of yacc.c  */
#line 2272 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2330 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2335 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2344 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2376 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2400 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2406 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2420 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:
/* Line 1787 of yacc.c  */
#line 2445 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2485 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2490 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2499 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2505 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2551 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2556 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2562 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2568 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2574 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2579 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2584 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2649 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1787 of yacc.c  */
#line 2660 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2761 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2766 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 2777 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2782 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 538:
/* Line 1787 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2831 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 562:
/* Line 1787 of yacc.c  */
#line 2893 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2905 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2914 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2917 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2920 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2923 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2929 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2932 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2935 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2938 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2944 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2947 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2950 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2953 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2966 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 588:
/* Line 1787 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 589:
/* Line 1787 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigFileEntry.client_flood = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 3004 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 3009 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3019 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3024 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3034 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3039 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3044 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 3049 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 3054 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 620:
/* Line 1787 of yacc.c  */
#line 3059 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 621:
/* Line 1787 of yacc.c  */
#line 3064 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 3082 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 3088 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 634:
/* Line 1787 of yacc.c  */
#line 3094 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 3103 "conf_parser.y"
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

  case 636:
/* Line 1787 of yacc.c  */
#line 3117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 637:
/* Line 1787 of yacc.c  */
#line 3123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6971 "conf_parser.c"
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


