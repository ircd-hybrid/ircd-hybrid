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
     IRCD_FLAGS = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_REQUEST_DURATION = 299,
     GLINE_MIN_CIDR = 300,
     GLINE_MIN_CIDR6 = 301,
     GLOBAL_KILL = 302,
     IRCD_AUTH = 303,
     NEED_IDENT = 304,
     HAVENT_READ_CONF = 305,
     HIDDEN = 306,
     HIDDEN_NAME = 307,
     HIDE_SERVER_IPS = 308,
     HIDE_SERVERS = 309,
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     KILL = 317,
     KILL_CHASE_TIME_LIMIT = 318,
     KLINE = 319,
     KLINE_EXEMPT = 320,
     KLINE_REASON = 321,
     KLINE_WITH_REASON = 322,
     KNOCK_DELAY = 323,
     KNOCK_DELAY_CHANNEL = 324,
     LEAF_MASK = 325,
     LINKS_DELAY = 326,
     LISTEN = 327,
     T_LOG = 328,
     MAX_ACCEPT = 329,
     MAX_BANS = 330,
     MAX_CHANS_PER_OPER = 331,
     MAX_CHANS_PER_USER = 332,
     MAX_GLOBAL = 333,
     MAX_IDENT = 334,
     MAX_LOCAL = 335,
     MAX_NICK_CHANGES = 336,
     MAX_NICK_TIME = 337,
     MAX_NUMBER = 338,
     MAX_TARGETS = 339,
     MAX_WATCH = 340,
     MESSAGE_LOCALE = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MODULE = 344,
     MODULES = 345,
     NAME = 346,
     NEED_PASSWORD = 347,
     NETWORK_DESC = 348,
     NETWORK_NAME = 349,
     NICK = 350,
     NICK_CHANGES = 351,
     NO_CREATE_ON_SPLIT = 352,
     NO_JOIN_ON_SPLIT = 353,
     NO_OPER_FLOOD = 354,
     NO_TILDE = 355,
     NUMBER = 356,
     NUMBER_PER_CIDR = 357,
     NUMBER_PER_IP = 358,
     OPERATOR = 359,
     OPERS_BYPASS_CALLERID = 360,
     OPER_ONLY_UMODES = 361,
     OPER_PASS_RESV = 362,
     OPER_SPY_T = 363,
     OPER_UMODES = 364,
     JOIN_FLOOD_COUNT = 365,
     JOIN_FLOOD_TIME = 366,
     PACE_WAIT = 367,
     PACE_WAIT_SIMPLE = 368,
     PASSWORD = 369,
     PATH = 370,
     PING_COOKIE = 371,
     PING_TIME = 372,
     PING_WARNING = 373,
     PORT = 374,
     QSTRING = 375,
     QUIET_ON_BAN = 376,
     REASON = 377,
     REDIRPORT = 378,
     REDIRSERV = 379,
     REGEX_T = 380,
     REHASH = 381,
     TREJECT_HOLD_TIME = 382,
     REMOTE = 383,
     REMOTEBAN = 384,
     RESTRICT_CHANNELS = 385,
     RSA_PRIVATE_KEY_FILE = 386,
     RSA_PUBLIC_KEY_FILE = 387,
     SSL_CERTIFICATE_FILE = 388,
     SSL_DH_PARAM_FILE = 389,
     T_SSL_CLIENT_METHOD = 390,
     T_SSL_SERVER_METHOD = 391,
     T_SSLV3 = 392,
     T_TLSV1 = 393,
     RESV = 394,
     RESV_EXEMPT = 395,
     SECONDS = 396,
     MINUTES = 397,
     HOURS = 398,
     DAYS = 399,
     WEEKS = 400,
     SENDQ = 401,
     SEND_PASSWORD = 402,
     SERVERHIDE = 403,
     SERVERINFO = 404,
     IRCD_SID = 405,
     TKLINE_EXPIRE_NOTICES = 406,
     T_SHARED = 407,
     T_CLUSTER = 408,
     TYPE = 409,
     SHORT_MOTD = 410,
     SPOOF = 411,
     SPOOF_NOTICE = 412,
     STATS_E_DISABLED = 413,
     STATS_I_OPER_ONLY = 414,
     STATS_K_OPER_ONLY = 415,
     STATS_O_OPER_ONLY = 416,
     STATS_P_OPER_ONLY = 417,
     TBOOL = 418,
     TMASKED = 419,
     TS_MAX_DELTA = 420,
     TS_WARN_DELTA = 421,
     TWODOTS = 422,
     T_ALL = 423,
     T_BOTS = 424,
     T_SOFTCALLERID = 425,
     T_CALLERID = 426,
     T_CCONN = 427,
     T_CCONN_FULL = 428,
     T_SSL_CIPHER_LIST = 429,
     T_DEAF = 430,
     T_DEBUG = 431,
     T_DLINE = 432,
     T_EXTERNAL = 433,
     T_FULL = 434,
     T_INVISIBLE = 435,
     T_IPV4 = 436,
     T_IPV6 = 437,
     T_LOCOPS = 438,
     T_MAX_CLIENTS = 439,
     T_NCHANGE = 440,
     T_OPERWALL = 441,
     T_RECVQ = 442,
     T_REJ = 443,
     T_SERVER = 444,
     T_SERVNOTICE = 445,
     T_SET = 446,
     T_SKILL = 447,
     T_SPY = 448,
     T_SSL = 449,
     T_UMODES = 450,
     T_UNAUTH = 451,
     T_UNDLINE = 452,
     T_UNLIMITED = 453,
     T_UNRESV = 454,
     T_UNXLINE = 455,
     T_GLOBOPS = 456,
     T_WALLOP = 457,
     T_RESTART = 458,
     T_SERVICE = 459,
     T_SERVICES_NAME = 460,
     THROTTLE_TIME = 461,
     TRUE_NO_OPER_FLOOD = 462,
     UNKLINE = 463,
     USER = 464,
     USE_EGD = 465,
     USE_LOGGING = 466,
     USE_WHOIS_ACTUALLY = 467,
     VHOST = 468,
     VHOST6 = 469,
     XLINE = 470,
     WARN_NO_NLINE = 471,
     T_SIZE = 472,
     T_FILE = 473
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
#define IRCD_FLAGS 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_REQUEST_DURATION 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLOBAL_KILL 302
#define IRCD_AUTH 303
#define NEED_IDENT 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define KILL 317
#define KILL_CHASE_TIME_LIMIT 318
#define KLINE 319
#define KLINE_EXEMPT 320
#define KLINE_REASON 321
#define KLINE_WITH_REASON 322
#define KNOCK_DELAY 323
#define KNOCK_DELAY_CHANNEL 324
#define LEAF_MASK 325
#define LINKS_DELAY 326
#define LISTEN 327
#define T_LOG 328
#define MAX_ACCEPT 329
#define MAX_BANS 330
#define MAX_CHANS_PER_OPER 331
#define MAX_CHANS_PER_USER 332
#define MAX_GLOBAL 333
#define MAX_IDENT 334
#define MAX_LOCAL 335
#define MAX_NICK_CHANGES 336
#define MAX_NICK_TIME 337
#define MAX_NUMBER 338
#define MAX_TARGETS 339
#define MAX_WATCH 340
#define MESSAGE_LOCALE 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MODULE 344
#define MODULES 345
#define NAME 346
#define NEED_PASSWORD 347
#define NETWORK_DESC 348
#define NETWORK_NAME 349
#define NICK 350
#define NICK_CHANGES 351
#define NO_CREATE_ON_SPLIT 352
#define NO_JOIN_ON_SPLIT 353
#define NO_OPER_FLOOD 354
#define NO_TILDE 355
#define NUMBER 356
#define NUMBER_PER_CIDR 357
#define NUMBER_PER_IP 358
#define OPERATOR 359
#define OPERS_BYPASS_CALLERID 360
#define OPER_ONLY_UMODES 361
#define OPER_PASS_RESV 362
#define OPER_SPY_T 363
#define OPER_UMODES 364
#define JOIN_FLOOD_COUNT 365
#define JOIN_FLOOD_TIME 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PING_WARNING 373
#define PORT 374
#define QSTRING 375
#define QUIET_ON_BAN 376
#define REASON 377
#define REDIRPORT 378
#define REDIRSERV 379
#define REGEX_T 380
#define REHASH 381
#define TREJECT_HOLD_TIME 382
#define REMOTE 383
#define REMOTEBAN 384
#define RESTRICT_CHANNELS 385
#define RSA_PRIVATE_KEY_FILE 386
#define RSA_PUBLIC_KEY_FILE 387
#define SSL_CERTIFICATE_FILE 388
#define SSL_DH_PARAM_FILE 389
#define T_SSL_CLIENT_METHOD 390
#define T_SSL_SERVER_METHOD 391
#define T_SSLV3 392
#define T_TLSV1 393
#define RESV 394
#define RESV_EXEMPT 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define SENDQ 401
#define SEND_PASSWORD 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define IRCD_SID 405
#define TKLINE_EXPIRE_NOTICES 406
#define T_SHARED 407
#define T_CLUSTER 408
#define TYPE 409
#define SHORT_MOTD 410
#define SPOOF 411
#define SPOOF_NOTICE 412
#define STATS_E_DISABLED 413
#define STATS_I_OPER_ONLY 414
#define STATS_K_OPER_ONLY 415
#define STATS_O_OPER_ONLY 416
#define STATS_P_OPER_ONLY 417
#define TBOOL 418
#define TMASKED 419
#define TS_MAX_DELTA 420
#define TS_WARN_DELTA 421
#define TWODOTS 422
#define T_ALL 423
#define T_BOTS 424
#define T_SOFTCALLERID 425
#define T_CALLERID 426
#define T_CCONN 427
#define T_CCONN_FULL 428
#define T_SSL_CIPHER_LIST 429
#define T_DEAF 430
#define T_DEBUG 431
#define T_DLINE 432
#define T_EXTERNAL 433
#define T_FULL 434
#define T_INVISIBLE 435
#define T_IPV4 436
#define T_IPV6 437
#define T_LOCOPS 438
#define T_MAX_CLIENTS 439
#define T_NCHANGE 440
#define T_OPERWALL 441
#define T_RECVQ 442
#define T_REJ 443
#define T_SERVER 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SKILL 447
#define T_SPY 448
#define T_SSL 449
#define T_UMODES 450
#define T_UNAUTH 451
#define T_UNDLINE 452
#define T_UNLIMITED 453
#define T_UNRESV 454
#define T_UNXLINE 455
#define T_GLOBOPS 456
#define T_WALLOP 457
#define T_RESTART 458
#define T_SERVICE 459
#define T_SERVICES_NAME 460
#define THROTTLE_TIME 461
#define TRUE_NO_OPER_FLOOD 462
#define UNKLINE 463
#define USER 464
#define USE_EGD 465
#define USE_LOGGING 466
#define USE_WHOIS_ACTUALLY 467
#define VHOST 468
#define VHOST6 469
#define XLINE 470
#define WARN_NO_NLINE 471
#define T_SIZE 472
#define T_FILE 473



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 350 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 350 of yacc.c  */
#line 638 "conf_parser.c"
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
#line 666 "conf_parser.c"

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
#define YYLAST   1231

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  224
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  287
/* YYNRULES -- Number of rules.  */
#define YYNRULES  635
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1248

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   473

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   223,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   219,
       2,   222,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   221,     2,   220,     2,     2,     2,     2,
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
     215,   216,   217,   218
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
     587,   589,   591,   593,   596,   601,   606,   611,   616,   621,
     626,   631,   636,   641,   646,   651,   656,   661,   666,   667,
     674,   675,   681,   685,   687,   689,   691,   693,   696,   698,
     700,   702,   704,   706,   709,   710,   716,   720,   722,   724,
     728,   733,   738,   739,   746,   749,   751,   753,   755,   757,
     759,   761,   763,   765,   767,   770,   775,   780,   785,   790,
     791,   797,   801,   803,   805,   807,   809,   811,   813,   815,
     817,   819,   821,   826,   831,   836,   837,   844,   847,   849,
     851,   853,   855,   858,   863,   868,   873,   879,   882,   884,
     886,   888,   893,   894,   901,   904,   906,   908,   910,   912,
     915,   920,   925,   926,   932,   936,   938,   940,   942,   944,
     946,   948,   950,   952,   954,   956,   958,   959,   966,   969,
     971,   973,   975,   978,   983,   984,   990,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1012,  1014,  1016,  1017,
    1024,  1027,  1029,  1031,  1033,  1035,  1037,  1039,  1041,  1043,
    1045,  1047,  1049,  1051,  1053,  1055,  1058,  1063,  1068,  1073,
    1078,  1083,  1088,  1093,  1098,  1099,  1105,  1109,  1111,  1113,
    1115,  1120,  1125,  1130,  1135,  1140,  1141,  1148,  1149,  1155,
    1159,  1161,  1163,  1166,  1168,  1170,  1172,  1174,  1176,  1181,
    1186,  1187,  1194,  1197,  1199,  1201,  1203,  1205,  1210,  1215,
    1221,  1224,  1226,  1228,  1230,  1235,  1236,  1243,  1244,  1250,
    1254,  1256,  1258,  1261,  1263,  1265,  1267,  1269,  1271,  1276,
    1281,  1287,  1290,  1292,  1294,  1296,  1298,  1300,  1302,  1304,
    1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,  1322,  1324,
    1326,  1328,  1330,  1332,  1334,  1336,  1338,  1340,  1342,  1344,
    1346,  1348,  1350,  1352,  1354,  1356,  1358,  1360,  1362,  1364,
    1366,  1368,  1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,
    1386,  1388,  1390,  1392,  1394,  1396,  1398,  1400,  1405,  1410,
    1415,  1420,  1425,  1430,  1435,  1440,  1445,  1450,  1455,  1460,
    1465,  1470,  1475,  1480,  1485,  1490,  1495,  1500,  1505,  1510,
    1515,  1520,  1525,  1530,  1535,  1540,  1545,  1550,  1555,  1560,
    1565,  1570,  1575,  1580,  1585,  1590,  1595,  1600,  1605,  1610,
    1615,  1620,  1625,  1630,  1635,  1640,  1645,  1650,  1651,  1657,
    1661,  1663,  1665,  1667,  1669,  1671,  1673,  1675,  1677,  1679,
    1681,  1683,  1685,  1687,  1689,  1691,  1693,  1695,  1697,  1699,
    1701,  1703,  1704,  1710,  1714,  1716,  1718,  1720,  1722,  1724,
    1726,  1728,  1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,
    1746,  1748,  1750,  1752,  1754,  1756,  1761,  1766,  1771,  1777,
    1780,  1782,  1784,  1786,  1788,  1790,  1792,  1794,  1796,  1798,
    1800,  1802,  1804,  1806,  1808,  1810,  1812,  1817,  1822,  1827,
    1832,  1837,  1842,  1847,  1852,  1857,  1862,  1867,  1872,  1877,
    1882,  1888,  1891,  1893,  1895,  1897,  1899,  1901,  1903,  1905,
    1907,  1912,  1917,  1922,  1927,  1932
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     225,     0,    -1,    -1,   225,   226,    -1,   258,    -1,   264,
      -1,   278,    -1,   485,    -1,   296,    -1,   314,    -1,   328,
      -1,   236,    -1,   502,    -1,   343,    -1,   350,    -1,   354,
      -1,   364,    -1,   373,    -1,   393,    -1,   403,    -1,   409,
      -1,   423,    -1,   413,    -1,   231,    -1,     1,   219,    -1,
       1,   220,    -1,    -1,   228,    -1,   101,   227,    -1,   101,
     141,   227,    -1,   101,   142,   227,    -1,   101,   143,   227,
      -1,   101,   144,   227,    -1,   101,   145,   227,    -1,    -1,
     230,    -1,   101,   229,    -1,   101,     9,   229,    -1,   101,
      10,   229,    -1,   101,    11,   229,    -1,    90,   221,   232,
     220,   219,    -1,   232,   233,    -1,   233,    -1,   234,    -1,
     235,    -1,     1,   219,    -1,    89,   222,   120,   219,    -1,
     115,   222,   120,   219,    -1,   149,   221,   237,   220,   219,
      -1,   237,   238,    -1,   238,    -1,   249,    -1,   254,    -1,
     257,    -1,   251,    -1,   252,    -1,   253,    -1,   256,    -1,
     247,    -1,   246,    -1,   255,    -1,   250,    -1,   245,    -1,
     239,    -1,   240,    -1,   248,    -1,     1,   219,    -1,   135,
     222,   241,   219,    -1,   136,   222,   243,   219,    -1,   241,
     223,   242,    -1,   242,    -1,   137,    -1,   138,    -1,   243,
     223,   244,    -1,   244,    -1,   137,    -1,   138,    -1,   133,
     222,   120,   219,    -1,   131,   222,   120,   219,    -1,   134,
     222,   120,   219,    -1,   174,   222,   120,   219,    -1,    91,
     222,   120,   219,    -1,   150,   222,   120,   219,    -1,    24,
     222,   120,   219,    -1,    94,   222,   120,   219,    -1,    93,
     222,   120,   219,    -1,   213,   222,   120,   219,    -1,   214,
     222,   120,   219,    -1,   184,   222,   101,   219,    -1,    57,
     222,   163,   219,    -1,     4,   221,   259,   220,   219,    -1,
     259,   260,    -1,   260,    -1,   261,    -1,   263,    -1,   262,
      -1,     1,   219,    -1,    91,   222,   120,   219,    -1,    31,
     222,   120,   219,    -1,    24,   222,   120,   219,    -1,    73,
     221,   265,   220,   219,    -1,   265,   266,    -1,   266,    -1,
     267,    -1,   268,    -1,     1,   219,    -1,   211,   222,   163,
     219,    -1,    -1,   269,   218,   221,   270,   220,   219,    -1,
     270,   271,    -1,   271,    -1,   272,    -1,   274,    -1,   273,
      -1,     1,   219,    -1,    91,   222,   120,   219,    -1,   217,
     222,   230,   219,    -1,   217,   222,   198,   219,    -1,    -1,
     154,   275,   222,   276,   219,    -1,   276,   223,   277,    -1,
     277,    -1,   209,    -1,   104,    -1,    40,    -1,   177,    -1,
      64,    -1,    62,    -1,   176,    -1,    -1,   104,   279,   221,
     280,   220,   219,    -1,   280,   281,    -1,   281,    -1,   282,
      -1,   283,    -1,   284,    -1,   288,    -1,   287,    -1,   285,
      -1,   286,    -1,   292,    -1,     1,   219,    -1,    91,   222,
     120,   219,    -1,   209,   222,   120,   219,    -1,   114,   222,
     120,   219,    -1,    32,   222,   163,   219,    -1,   132,   222,
     120,   219,    -1,    17,   222,   120,   219,    -1,    -1,   195,
     289,   222,   290,   219,    -1,   290,   223,   291,    -1,   291,
      -1,   169,    -1,   172,    -1,   173,    -1,   175,    -1,   176,
      -1,   179,    -1,    51,    -1,   192,    -1,   185,    -1,   188,
      -1,   196,    -1,   193,    -1,   178,    -1,   186,    -1,   190,
      -1,   180,    -1,   202,    -1,   170,    -1,   171,    -1,   183,
      -1,    -1,    36,   293,   222,   294,   219,    -1,   294,   223,
     295,    -1,   295,    -1,    47,    -1,   128,    -1,    64,    -1,
     208,    -1,   177,    -1,   197,    -1,   215,    -1,    40,    -1,
      25,    -1,   203,    -1,   126,    -1,     4,    -1,    96,    -1,
     186,    -1,   201,    -1,   108,    -1,   129,    -1,   191,    -1,
      89,    -1,    -1,    17,   297,   221,   298,   220,   219,    -1,
     298,   299,    -1,   299,    -1,   300,    -1,   311,    -1,   312,
      -1,   301,    -1,   302,    -1,   313,    -1,   303,    -1,   304,
      -1,   305,    -1,   306,    -1,   307,    -1,   308,    -1,   309,
      -1,   310,    -1,     1,   219,    -1,    91,   222,   120,   219,
      -1,   117,   222,   228,   219,    -1,   118,   222,   228,   219,
      -1,   103,   222,   101,   219,    -1,    19,   222,   228,   219,
      -1,    83,   222,   101,   219,    -1,    78,   222,   101,   219,
      -1,    80,   222,   101,   219,    -1,    79,   222,   101,   219,
      -1,   146,   222,   230,   219,    -1,   187,   222,   230,   219,
      -1,    15,   222,   101,   219,    -1,    16,   222,   101,   219,
      -1,   102,   222,   101,   219,    -1,    -1,    72,   315,   221,
     320,   220,   219,    -1,    -1,    36,   317,   222,   318,   219,
      -1,   318,   223,   319,    -1,   319,    -1,   194,    -1,    51,
      -1,   189,    -1,   320,   321,    -1,   321,    -1,   322,    -1,
     316,    -1,   326,    -1,   327,    -1,     1,   219,    -1,    -1,
     119,   222,   324,   323,   219,    -1,   324,   223,   325,    -1,
     325,    -1,   101,    -1,   101,   167,   101,    -1,    61,   222,
     120,   219,    -1,    56,   222,   120,   219,    -1,    -1,    48,
     329,   221,   330,   220,   219,    -1,   330,   331,    -1,   331,
      -1,   332,    -1,   333,    -1,   334,    -1,   336,    -1,   340,
      -1,   341,    -1,   342,    -1,   335,    -1,     1,   219,    -1,
     209,   222,   120,   219,    -1,   114,   222,   120,   219,    -1,
      17,   222,   120,   219,    -1,    32,   222,   163,   219,    -1,
      -1,    36,   337,   222,   338,   219,    -1,   338,   223,   339,
      -1,   339,    -1,   157,    -1,    33,    -1,    65,    -1,    49,
      -1,    13,    -1,   100,    -1,    43,    -1,   140,    -1,    92,
      -1,   156,   222,   120,   219,    -1,   124,   222,   120,   219,
      -1,   123,   222,   101,   219,    -1,    -1,   139,   344,   221,
     345,   220,   219,    -1,   345,   346,    -1,   346,    -1,   347,
      -1,   348,    -1,   349,    -1,     1,   219,    -1,   122,   222,
     120,   219,    -1,    14,   222,   120,   219,    -1,    95,   222,
     120,   219,    -1,   204,   221,   351,   220,   219,    -1,   351,
     352,    -1,   352,    -1,   353,    -1,     1,    -1,    91,   222,
     120,   219,    -1,    -1,   152,   355,   221,   356,   220,   219,
      -1,   356,   357,    -1,   357,    -1,   358,    -1,   359,    -1,
     360,    -1,     1,   219,    -1,    91,   222,   120,   219,    -1,
     209,   222,   120,   219,    -1,    -1,   154,   361,   222,   362,
     219,    -1,   362,   223,   363,    -1,   363,    -1,    64,    -1,
     208,    -1,   177,    -1,   197,    -1,   215,    -1,   200,    -1,
     139,    -1,   199,    -1,   183,    -1,   168,    -1,    -1,   153,
     365,   221,   366,   220,   219,    -1,   366,   367,    -1,   367,
      -1,   368,    -1,   369,    -1,     1,   219,    -1,    91,   222,
     120,   219,    -1,    -1,   154,   370,   222,   371,   219,    -1,
     371,   223,   372,    -1,   372,    -1,    64,    -1,   208,    -1,
     177,    -1,   197,    -1,   215,    -1,   200,    -1,   139,    -1,
     199,    -1,   183,    -1,   168,    -1,    -1,    18,   374,   221,
     375,   220,   219,    -1,   375,   376,    -1,   376,    -1,   377,
      -1,   378,    -1,   379,    -1,   380,    -1,   381,    -1,   383,
      -1,   382,    -1,   392,    -1,   384,    -1,   389,    -1,   390,
      -1,   391,    -1,   388,    -1,     1,   219,    -1,    91,   222,
     120,   219,    -1,    56,   222,   120,   219,    -1,   213,   222,
     120,   219,    -1,   147,   222,   120,   219,    -1,     3,   222,
     120,   219,    -1,   119,   222,   101,   219,    -1,     5,   222,
     181,   219,    -1,     5,   222,   182,   219,    -1,    -1,    36,
     385,   222,   386,   219,    -1,   386,   223,   387,    -1,   387,
      -1,     8,    -1,   194,    -1,    32,   222,   163,   219,    -1,
      58,   222,   120,   219,    -1,    70,   222,   120,   219,    -1,
      17,   222,   120,   219,    -1,   174,   222,   120,   219,    -1,
      -1,    62,   394,   221,   399,   220,   219,    -1,    -1,   154,
     396,   222,   397,   219,    -1,   397,   223,   398,    -1,   398,
      -1,   125,    -1,   399,   400,    -1,   400,    -1,   401,    -1,
     402,    -1,   395,    -1,     1,    -1,   209,   222,   120,   219,
      -1,   122,   222,   120,   219,    -1,    -1,    23,   404,   221,
     405,   220,   219,    -1,   405,   406,    -1,   406,    -1,   407,
      -1,   408,    -1,     1,    -1,    61,   222,   120,   219,    -1,
     122,   222,   120,   219,    -1,    34,   221,   410,   220,   219,
      -1,   410,   411,    -1,   411,    -1,   412,    -1,     1,    -1,
      61,   222,   120,   219,    -1,    -1,    38,   414,   221,   419,
     220,   219,    -1,    -1,   154,   416,   222,   417,   219,    -1,
     417,   223,   418,    -1,   418,    -1,   125,    -1,   419,   420,
      -1,   420,    -1,   421,    -1,   422,    -1,   415,    -1,     1,
      -1,    91,   222,   120,   219,    -1,   122,   222,   120,   219,
      -1,    39,   221,   424,   220,   219,    -1,   424,   425,    -1,
     425,    -1,   436,    -1,   437,    -1,   439,    -1,   440,    -1,
     441,    -1,   442,    -1,   443,    -1,   444,    -1,   445,    -1,
     446,    -1,   435,    -1,   448,    -1,   449,    -1,   450,    -1,
     451,    -1,   466,    -1,   453,    -1,   455,    -1,   457,    -1,
     456,    -1,   460,    -1,   454,    -1,   461,    -1,   462,    -1,
     463,    -1,   464,    -1,   465,    -1,   478,    -1,   467,    -1,
     468,    -1,   469,    -1,   474,    -1,   458,    -1,   459,    -1,
     484,    -1,   482,    -1,   483,    -1,   438,    -1,   473,    -1,
     447,    -1,   471,    -1,   472,    -1,   434,    -1,   427,    -1,
     428,    -1,   429,    -1,   430,    -1,   431,    -1,   432,    -1,
     433,    -1,   452,    -1,   426,    -1,   470,    -1,     1,    -1,
      85,   222,   101,   219,    -1,    42,   222,   163,   219,    -1,
      41,   222,   228,   219,    -1,    44,   222,   228,   219,    -1,
      45,   222,   101,   219,    -1,    46,   222,   101,   219,    -1,
     212,   222,   163,   219,    -1,   127,   222,   228,   219,    -1,
     151,   222,   163,   219,    -1,    63,   222,   228,   219,    -1,
      55,   222,   163,   219,    -1,    59,   222,   163,   219,    -1,
      28,   222,   163,   219,    -1,    35,   222,   163,   219,    -1,
       6,   222,   163,   219,    -1,    82,   222,   228,   219,    -1,
      81,   222,   101,   219,    -1,    74,   222,   101,   219,    -1,
       7,   222,   228,   219,    -1,   166,   222,   228,   219,    -1,
     165,   222,   228,   219,    -1,    50,   222,   101,   219,    -1,
      67,   222,   163,   219,    -1,    66,   222,   120,   219,    -1,
      60,   222,   163,   219,    -1,   216,   222,   163,   219,    -1,
     158,   222,   163,   219,    -1,   161,   222,   163,   219,    -1,
     162,   222,   163,   219,    -1,   160,   222,   163,   219,    -1,
     160,   222,   164,   219,    -1,   159,   222,   163,   219,    -1,
     159,   222,   164,   219,    -1,   112,   222,   228,   219,    -1,
      12,   222,   228,   219,    -1,   105,   222,   163,   219,    -1,
     113,   222,   228,   219,    -1,   155,   222,   163,   219,    -1,
      99,   222,   163,   219,    -1,   207,   222,   163,   219,    -1,
     107,   222,   163,   219,    -1,    86,   222,   120,   219,    -1,
      29,   222,   101,   219,    -1,    84,   222,   101,   219,    -1,
     210,   222,   163,   219,    -1,    30,   222,   120,   219,    -1,
     205,   222,   120,   219,    -1,   116,   222,   163,   219,    -1,
      26,   222,   163,   219,    -1,   206,   222,   228,   219,    -1,
      -1,   109,   475,   222,   476,   219,    -1,   476,   223,   477,
      -1,   477,    -1,   169,    -1,   172,    -1,   173,    -1,   175,
      -1,   176,    -1,   179,    -1,    51,    -1,   192,    -1,   185,
      -1,   188,    -1,   196,    -1,   193,    -1,   178,    -1,   186,
      -1,   190,    -1,   180,    -1,   202,    -1,   170,    -1,   171,
      -1,   183,    -1,    -1,   106,   479,   222,   480,   219,    -1,
     480,   223,   481,    -1,   481,    -1,   169,    -1,   172,    -1,
     173,    -1,   175,    -1,   176,    -1,   179,    -1,   192,    -1,
      51,    -1,   185,    -1,   188,    -1,   196,    -1,   193,    -1,
     178,    -1,   186,    -1,   190,    -1,   180,    -1,   202,    -1,
     170,    -1,   171,    -1,   183,    -1,    87,   222,   101,   219,
      -1,    88,   222,   101,   219,    -1,    20,   222,   101,   219,
      -1,    14,   221,   486,   220,   219,    -1,   486,   487,    -1,
     487,    -1,   495,    -1,   490,    -1,   491,    -1,   492,    -1,
     493,    -1,   494,    -1,   496,    -1,   497,    -1,   498,    -1,
     489,    -1,   499,    -1,   500,    -1,   501,    -1,   488,    -1,
       1,    -1,    27,   222,   163,   219,    -1,   130,   222,   163,
     219,    -1,    68,   222,   228,   219,    -1,    69,   222,   228,
     219,    -1,    77,   222,   101,   219,    -1,    76,   222,   101,
     219,    -1,   121,   222,   163,   219,    -1,    75,   222,   101,
     219,    -1,    22,   222,   101,   219,    -1,    21,   222,   101,
     219,    -1,    97,   222,   163,   219,    -1,    98,   222,   163,
     219,    -1,   110,   222,   101,   219,    -1,   111,   222,   228,
     219,    -1,   148,   221,   503,   220,   219,    -1,   503,   504,
      -1,   504,    -1,   505,    -1,   506,    -1,   508,    -1,   509,
      -1,   507,    -1,   510,    -1,     1,    -1,    37,   222,   163,
     219,    -1,    54,   222,   163,   219,    -1,    52,   222,   120,
     219,    -1,    71,   222,   228,   219,    -1,    51,   222,   163,
     219,    -1,    53,   222,   163,   219,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   334,   334,   335,   338,   339,   340,   341,   342,   343,
     344,   345,   346,   347,   348,   349,   350,   351,   352,   353,
     354,   355,   356,   357,   358,   359,   363,   363,   364,   368,
     372,   376,   380,   384,   390,   390,   391,   392,   393,   394,
     401,   404,   404,   405,   405,   405,   407,   413,   420,   422,
     422,   423,   423,   424,   424,   425,   425,   426,   426,   427,
     427,   428,   428,   429,   429,   430,   431,   434,   435,   437,
     437,   438,   444,   452,   452,   453,   459,   467,   506,   565,
     593,   601,   616,   631,   640,   654,   663,   691,   721,   744,
     753,   755,   755,   756,   756,   757,   757,   759,   768,   777,
     789,   790,   790,   792,   792,   793,   795,   802,   802,   812,
     813,   815,   815,   816,   816,   818,   823,   826,   832,   831,
     837,   837,   838,   842,   846,   850,   854,   858,   862,   873,
     872,   970,   970,   971,   971,   971,   972,   972,   972,   973,
     973,   973,   975,   984,  1021,  1033,  1044,  1086,  1096,  1095,
    1101,  1101,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,
    1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,  1170,
    1174,  1178,  1185,  1184,  1190,  1190,  1191,  1195,  1199,  1203,
    1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,  1243,
    1247,  1251,  1255,  1259,  1263,  1274,  1273,  1323,  1323,  1324,
    1325,  1325,  1326,  1327,  1328,  1329,  1330,  1331,  1332,  1333,
    1334,  1335,  1335,  1336,  1338,  1347,  1353,  1359,  1365,  1371,
    1377,  1383,  1389,  1395,  1401,  1408,  1414,  1420,  1430,  1429,
    1446,  1445,  1450,  1450,  1451,  1455,  1459,  1467,  1467,  1468,
    1468,  1468,  1468,  1468,  1470,  1470,  1472,  1472,  1474,  1488,
    1508,  1517,  1530,  1529,  1598,  1598,  1599,  1599,  1599,  1599,
    1600,  1600,  1600,  1601,  1601,  1603,  1638,  1651,  1660,  1672,
    1671,  1675,  1675,  1676,  1680,  1684,  1688,  1692,  1696,  1700,
    1704,  1708,  1715,  1734,  1744,  1758,  1757,  1773,  1773,  1774,
    1774,  1774,  1774,  1776,  1785,  1800,  1813,  1815,  1815,  1816,
    1816,  1818,  1834,  1833,  1849,  1849,  1850,  1850,  1850,  1850,
    1852,  1861,  1884,  1883,  1889,  1889,  1890,  1894,  1898,  1902,
    1906,  1910,  1914,  1918,  1922,  1926,  1936,  1935,  1952,  1952,
    1953,  1953,  1953,  1955,  1962,  1961,  1967,  1967,  1968,  1972,
    1976,  1980,  1984,  1988,  1992,  1996,  2000,  2004,  2014,  2013,
    2064,  2064,  2065,  2065,  2065,  2066,  2066,  2067,  2067,  2067,
    2068,  2068,  2068,  2069,  2069,  2070,  2072,  2081,  2090,  2116,
    2134,  2152,  2158,  2162,  2171,  2170,  2174,  2174,  2175,  2179,
    2185,  2196,  2207,  2218,  2227,  2246,  2245,  2311,  2310,  2314,
    2314,  2315,  2321,  2321,  2322,  2322,  2322,  2322,  2324,  2343,
    2353,  2352,  2377,  2377,  2378,  2378,  2378,  2380,  2386,  2395,
    2397,  2397,  2398,  2398,  2400,  2419,  2418,  2466,  2465,  2469,
    2469,  2470,  2476,  2476,  2477,  2477,  2477,  2477,  2479,  2485,
    2494,  2497,  2497,  2498,  2498,  2499,  2499,  2500,  2500,  2501,
    2501,  2502,  2502,  2503,  2503,  2504,  2504,  2505,  2505,  2506,
    2506,  2507,  2507,  2508,  2508,  2509,  2509,  2510,  2510,  2511,
    2512,  2512,  2513,  2513,  2514,  2514,  2515,  2515,  2516,  2516,
    2517,  2518,  2518,  2519,  2520,  2521,  2521,  2522,  2522,  2523,
    2524,  2524,  2525,  2525,  2526,  2526,  2527,  2530,  2535,  2541,
    2547,  2553,  2558,  2563,  2568,  2573,  2578,  2583,  2588,  2593,
    2598,  2603,  2608,  2613,  2618,  2623,  2628,  2633,  2639,  2650,
    2655,  2664,  2669,  2674,  2679,  2684,  2689,  2692,  2697,  2700,
    2705,  2710,  2715,  2720,  2725,  2730,  2735,  2740,  2745,  2756,
    2761,  2766,  2771,  2780,  2789,  2794,  2799,  2805,  2804,  2809,
    2809,  2810,  2813,  2816,  2819,  2822,  2825,  2828,  2831,  2834,
    2837,  2840,  2843,  2846,  2849,  2852,  2855,  2858,  2861,  2864,
    2867,  2873,  2872,  2877,  2877,  2878,  2881,  2884,  2887,  2890,
    2893,  2896,  2899,  2902,  2905,  2908,  2911,  2914,  2917,  2920,
    2923,  2926,  2929,  2932,  2935,  2940,  2945,  2950,  2959,  2962,
    2962,  2963,  2964,  2964,  2965,  2965,  2966,  2966,  2967,  2968,
    2968,  2969,  2970,  2970,  2971,  2971,  2973,  2978,  2983,  2988,
    2993,  2998,  3003,  3008,  3013,  3018,  3023,  3028,  3033,  3038,
    3046,  3049,  3049,  3050,  3050,  3051,  3052,  3052,  3053,  3054,
    3056,  3062,  3068,  3077,  3091,  3097
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
  "FAILED_OPER_NOTICE", "IRCD_FLAGS", "FLATTEN_LINKS", "GECOS", "GENERAL",
  "GLINE", "GLINE_DURATION", "GLINE_ENABLE", "GLINE_EXEMPT",
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
  "NO_OPER_FLOOD", "NO_TILDE", "NUMBER", "NUMBER_PER_CIDR",
  "NUMBER_PER_IP", "OPERATOR", "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES",
  "OPER_PASS_RESV", "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT",
  "JOIN_FLOOD_TIME", "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH",
  "PING_COOKIE", "PING_TIME", "PING_WARNING", "PORT", "QSTRING",
  "QUIET_ON_BAN", "REASON", "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH",
  "TREJECT_HOLD_TIME", "REMOTE", "REMOTEBAN", "RESTRICT_CHANNELS",
  "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE", "SSL_CERTIFICATE_FILE",
  "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD", "T_SSL_SERVER_METHOD",
  "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT", "SECONDS", "MINUTES",
  "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD", "SERVERHIDE",
  "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES", "T_SHARED",
  "T_CLUSTER", "TYPE", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
  "STATS_E_DISABLED", "STATS_I_OPER_ONLY", "STATS_K_OPER_ONLY",
  "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL", "TMASKED",
  "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE", "USER", "USE_EGD",
  "USE_LOGGING", "USE_WHOIS_ACTUALLY", "VHOST", "VHOST6", "XLINE",
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
  "class_max_local", "class_max_ident", "class_sendq", "class_recvq",
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
  "general_default_floodcount", "channel_entry", "channel_items",
  "channel_item", "channel_disable_fake_channels",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,    59,
     125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   224,   225,   225,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   227,   227,   228,   228,
     228,   228,   228,   228,   229,   229,   230,   230,   230,   230,
     231,   232,   232,   233,   233,   233,   234,   235,   236,   237,
     237,   238,   238,   238,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   238,   239,   240,   241,
     241,   242,   242,   243,   243,   244,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   259,   260,   260,   260,   260,   261,   262,   263,
     264,   265,   265,   266,   266,   266,   267,   269,   268,   270,
     270,   271,   271,   271,   271,   272,   273,   273,   275,   274,
     276,   276,   277,   277,   277,   277,   277,   277,   277,   279,
     278,   280,   280,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   282,   283,   284,   285,   286,   287,   289,   288,
     290,   290,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   293,   292,   294,   294,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   297,   296,   298,   298,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   315,   314,
     317,   316,   318,   318,   319,   319,   319,   320,   320,   321,
     321,   321,   321,   321,   323,   322,   324,   324,   325,   325,
     326,   327,   329,   328,   330,   330,   331,   331,   331,   331,
     331,   331,   331,   331,   331,   332,   333,   334,   335,   337,
     336,   338,   338,   339,   339,   339,   339,   339,   339,   339,
     339,   339,   340,   341,   342,   344,   343,   345,   345,   346,
     346,   346,   346,   347,   348,   349,   350,   351,   351,   352,
     352,   353,   355,   354,   356,   356,   357,   357,   357,   357,
     358,   359,   361,   360,   362,   362,   363,   363,   363,   363,
     363,   363,   363,   363,   363,   363,   365,   364,   366,   366,
     367,   367,   367,   368,   370,   369,   371,   371,   372,   372,
     372,   372,   372,   372,   372,   372,   372,   372,   374,   373,
     375,   375,   376,   376,   376,   376,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   377,   378,   379,   380,
     381,   382,   383,   383,   385,   384,   386,   386,   387,   387,
     388,   389,   390,   391,   392,   394,   393,   396,   395,   397,
     397,   398,   399,   399,   400,   400,   400,   400,   401,   402,
     404,   403,   405,   405,   406,   406,   406,   407,   408,   409,
     410,   410,   411,   411,   412,   414,   413,   416,   415,   417,
     417,   418,   419,   419,   420,   420,   420,   420,   421,   422,
     423,   424,   424,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   455,   456,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   475,   474,   476,
     476,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   479,   478,   480,   480,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   481,   481,   481,   481,   481,
     481,   481,   481,   481,   481,   482,   483,   484,   485,   486,
     486,   487,   487,   487,   487,   487,   487,   487,   487,   487,
     487,   487,   487,   487,   487,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   503,   504,   504,   504,   504,   504,   504,   504,
     505,   506,   507,   508,   509,   510
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
       1,     1,     1,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     2,     0,     5,     3,     1,     1,     3,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     6,     2,     1,
       1,     1,     2,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     6,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
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
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   348,   400,     0,
     415,     0,   252,   385,   228,     0,     0,   129,   285,     0,
       0,   302,   326,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   605,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   590,   604,   600,   592,   593,   594,   595,   596,
     591,   597,   598,   599,   601,   602,   603,     0,     0,     0,
     413,     0,     0,   411,   412,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   561,     0,
     537,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   432,   484,   476,   477,   478,   479,   480,   481,   482,
     475,   443,   433,   434,   470,   435,   436,   437,   438,   439,
     440,   441,   442,   472,   444,   445,   446,   447,   483,   449,
     454,   450,   452,   451,   465,   466,   453,   455,   456,   457,
     458,   459,   448,   461,   462,   463,   485,   473,   474,   471,
     464,   460,   468,   469,   467,     0,     0,     0,     0,     0,
       0,   102,   103,   104,     0,     0,     0,     0,     0,    42,
      43,    44,     0,     0,   629,     0,     0,     0,     0,     0,
       0,     0,   622,   623,   624,   627,   625,   626,   628,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    50,    63,    64,    62,
      59,    58,    65,    51,    61,    54,    55,    56,    52,    60,
      57,    53,     0,     0,   300,     0,     0,   298,   299,    96,
       0,     0,     0,     0,    91,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     589,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   198,   199,   202,
     203,   205,   206,   207,   208,   209,   210,   211,   212,   200,
     201,   204,     0,     0,     0,     0,     0,   374,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   351,   352,   353,
     354,   355,   356,   358,   357,   360,   364,   361,   362,   363,
     359,   406,     0,     0,     0,   403,   404,   405,     0,     0,
     410,   427,     0,     0,   417,   426,     0,   423,   424,   425,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   431,     0,     0,     0,   269,     0,
       0,     0,     0,     0,     0,   255,   256,   257,   258,   263,
     259,   260,   261,   262,   397,     0,   387,     0,   396,     0,
     393,   394,   395,     0,   230,     0,     0,     0,   240,     0,
     238,   239,   241,   242,   105,     0,     0,   101,     0,    45,
       0,     0,     0,    41,     0,     0,     0,   172,     0,     0,
       0,   148,     0,     0,   132,   133,   134,   135,   138,   139,
     137,   136,   140,     0,     0,     0,     0,     0,   288,   289,
     290,   291,     0,     0,     0,     0,     0,     0,     0,   621,
      66,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
     312,     0,     0,   305,   306,   307,   308,     0,     0,   334,
       0,   329,   330,   331,     0,     0,   297,     0,     0,     0,
      90,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   213,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   197,   365,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   350,
       0,     0,     0,   402,     0,   409,     0,     0,     0,     0,
     422,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   430,   264,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   392,   243,     0,     0,     0,     0,     0,   237,
       0,   100,     0,     0,     0,    40,   141,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   131,   292,     0,     0,
       0,     0,   287,     0,     0,     0,     0,     0,     0,   620,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
       0,    70,    75,    76,     0,    74,     0,     0,     0,     0,
       0,    48,   309,     0,     0,     0,     0,   304,   332,     0,
       0,     0,   328,     0,   296,    99,    98,    97,   615,   614,
     606,    26,    26,    26,    26,    26,    28,    27,   608,   609,
     613,   611,   610,   616,   617,   618,   619,   612,   607,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   349,
       0,     0,   401,   414,     0,     0,     0,   416,   501,   505,
     521,   587,   535,   499,   529,   532,   500,   489,   488,   490,
     491,   492,   508,   497,   498,   511,   496,   510,   509,   504,
     503,   502,   530,   487,   528,   585,   586,   525,   522,   572,
     565,   582,   583,   566,   567,   568,   569,   577,   570,   580,
     584,   573,   578,   574,   579,   571,   576,   575,   581,     0,
     564,   527,   547,   541,   558,   559,   542,   543,   544,   545,
     553,   546,   556,   560,   549,   554,   550,   555,   548,   552,
     551,   557,     0,   540,   520,   523,   534,   494,   495,   524,
     513,   518,   519,   516,   517,   514,   515,   507,   506,   533,
     536,   526,   531,   493,   512,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,   386,     0,     0,
       0,   248,   244,   247,   229,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   286,
     630,   634,   632,   635,   631,   633,    83,    89,    81,    85,
      84,    78,    77,    79,    67,     0,    68,     0,    82,    80,
      88,    86,    87,     0,     0,     0,   303,     0,     0,   327,
     301,    29,    30,    31,    32,    33,   225,   226,   218,   220,
     222,   221,   219,   214,   227,   217,   215,   216,    34,    34,
      34,    36,    35,   223,   224,   370,   372,   373,   383,   380,
     378,   379,     0,   377,   367,   381,   382,   366,   371,   369,
     384,   368,   407,   408,   428,   429,   421,     0,   420,   562,
       0,   538,     0,   267,   268,   277,   274,   279,   276,   275,
     281,   278,   280,   273,     0,   272,   266,   284,   283,   282,
     265,   399,   391,     0,   390,   398,   235,   236,   234,     0,
     233,   251,   250,     0,     0,     0,   114,     0,     0,     0,
       0,   109,   147,   145,   187,   184,   183,   176,   178,   194,
     188,   191,   186,   177,   192,   180,   189,   193,   181,   190,
     185,   179,   182,     0,   175,   142,   144,   146,   158,   152,
     169,   170,   153,   154,   155,   156,   164,   157,   167,   171,
     160,   165,   161,   166,   159,   163,   162,   168,     0,   151,
     143,   294,   295,   293,    69,    73,   310,   316,   322,   325,
     318,   324,   319,   323,   321,   317,   320,     0,   315,   311,
     333,   338,   344,   347,   340,   346,   341,   345,   343,   339,
     342,     0,   337,    37,    38,    39,   375,     0,   418,     0,
     563,   539,   270,     0,   388,     0,   231,     0,   249,   246,
     245,     0,     0,     0,     0,   108,   173,     0,   149,     0,
     313,     0,   335,     0,   376,   419,   271,   389,   232,   115,
     124,   127,   126,   123,   128,   125,   122,     0,   121,   117,
     116,   174,   150,   314,   336,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   796,   797,  1041,  1042,    25,   238,   239,
     240,   241,    26,   275,   276,   277,   278,   760,   761,   764,
     765,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,    27,    71,    72,    73,    74,    75,
      28,   230,   231,   232,   233,   234,   970,   971,   972,   973,
     974,  1108,  1237,  1238,    29,    60,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   733,  1158,  1159,   522,   729,
    1133,  1134,    30,    49,   336,   337,   338,   339,   340,   341,
     342,   343,   344,   345,   346,   347,   348,   349,   350,   351,
      31,    57,   488,   714,  1099,  1100,   489,   490,   491,  1105,
     962,   963,   492,   493,    32,    55,   464,   465,   466,   467,
     468,   469,   470,   700,  1084,  1085,   471,   472,   473,    33,
      61,   527,   528,   529,   530,   531,    34,   296,   297,   298,
      35,    64,   562,   563,   564,   565,   566,   774,  1177,  1178,
      36,    65,   570,   571,   572,   573,   780,  1191,  1192,    37,
      50,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   619,  1052,  1053,   376,   377,   378,   379,   380,    38,
      56,   478,   709,  1093,  1094,   479,   480,   481,   482,    39,
      51,   384,   385,   386,   387,    40,   112,   113,   114,    41,
      53,   395,   638,  1067,  1068,   396,   397,   398,   399,    42,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   433,   922,   923,   221,   431,   899,   900,   222,   223,
     224,    43,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,    44,   251,
     252,   253,   254,   255,   256,   257,   258
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -861
static const yytype_int16 yypact[] =
{
    -861,   613,  -861,  -173,  -209,  -198,  -861,  -861,  -861,  -193,
    -861,  -188,  -861,  -861,  -861,  -185,  -183,  -861,  -861,  -180,
    -169,  -861,  -861,  -138,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,    18,   823,  -124,
    -100,   -98,    21,   -80,   438,   -74,   -71,   -58,    44,     4,
     -20,   -15,   378,   326,   -10,    -7,     7,   -66,    41,    51,
      57,     8,  -861,  -861,  -861,  -861,  -861,    59,    62,    65,
      84,    92,    96,   100,   102,   103,   104,   106,   110,   117,
     122,     3,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,   555,   356,    49,
    -861,   123,    26,  -861,  -861,   166,  -861,   133,   134,   136,
     138,   141,   144,   145,   148,   149,   153,   154,   155,   156,
     158,   160,   162,   163,   165,   167,   168,   169,   172,   173,
     177,   179,   186,   189,   191,   194,   196,   201,  -861,   203,
    -861,   211,   212,   214,   215,   218,   220,   221,   224,   226,
     229,   231,   234,   243,   247,   248,   250,   252,   255,   259,
     131,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   392,    42,   279,     1,   263,
      58,  -861,  -861,  -861,    80,    94,   264,   265,    19,  -861,
    -861,  -861,   364,   188,  -861,   267,   269,   270,   272,   273,
     280,    14,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   288,
     286,   287,   289,   291,   292,   296,   299,   305,   306,   309,
     311,   312,   313,   319,   320,    91,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,    20,    16,  -861,   324,    36,  -861,  -861,  -861,
     157,   290,   429,   336,  -861,   456,   457,   398,   462,   462,
     463,   465,   466,   409,   412,   475,   462,   420,   422,   367,
    -861,   368,   366,   369,   370,   372,   373,   383,   384,   385,
     386,   388,   393,   394,   396,   400,   251,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,   371,   401,   402,   403,   404,  -861,   406,   407,
     410,   415,   418,   431,   433,   434,   316,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,   440,   441,    30,  -861,  -861,  -861,   500,   445,
    -861,  -861,   443,   444,  -861,  -861,    34,  -861,  -861,  -861,
     497,   462,   462,   566,   505,   506,   569,   551,   511,   462,
     515,   462,   578,   579,   580,   520,   521,   524,   462,   562,
     525,   588,   590,   462,   591,   592,   574,   594,   595,   534,
     535,   478,   539,   483,   462,   462,   543,   462,   544,   545,
     546,   -87,    97,   548,   549,   462,   462,   593,   462,   552,
     556,   557,   559,   499,  -861,   504,   502,   503,  -861,   507,
     516,   526,   528,   533,    12,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   536,  -861,   537,  -861,    33,
    -861,  -861,  -861,   508,  -861,   538,   542,   550,  -861,    25,
    -861,  -861,  -861,  -861,  -861,   563,   560,  -861,   522,  -861,
     636,   655,   568,  -861,   570,   558,   571,  -861,   581,   585,
     586,  -861,   599,   232,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   573,   601,   603,   604,    88,  -861,  -861,
    -861,  -861,   619,   622,   693,   652,   664,   462,   610,  -861,
    -861,   710,   668,   712,   713,   714,   715,   716,   717,   -75,
     -68,   718,   720,   740,   722,   723,   627,  -861,   628,   629,
    -861,   630,    39,  -861,  -861,  -861,  -861,   634,   633,  -861,
      15,  -861,  -861,  -861,   736,   638,  -861,   640,   641,   642,
    -861,   643,   644,   646,   261,   647,   648,   650,   653,   654,
     656,   657,   658,   663,   665,   666,  -861,  -861,   773,   782,
     462,   786,   787,   789,   792,   774,   794,   796,   462,   462,
     800,   800,   683,  -861,  -861,   783,   119,   784,   742,   684,
     788,   790,   791,   793,   806,   795,   797,   798,   690,  -861,
     799,   802,   695,  -861,   697,  -861,   803,   804,   703,   707,
    -861,   708,   709,   711,   719,   721,   724,   726,   727,   728,
     729,   730,   731,   732,   733,   735,   737,   738,   739,   741,
     743,   744,   745,   746,   747,   748,   749,   750,   751,   752,
     753,   754,   561,   755,   598,   756,   757,   758,   759,   760,
     761,   762,   763,   764,   765,   766,   767,   768,   769,   770,
     771,   772,   775,   776,   777,   778,  -861,  -861,   809,   779,
     780,   811,   831,   815,   816,   817,   781,  -861,   819,   785,
     821,   801,  -861,  -861,   805,   835,   839,   860,   807,  -861,
     810,  -861,    55,   812,   813,  -861,  -861,   872,   830,   808,
     878,   879,   881,   814,   883,   818,  -861,  -861,   884,   885,
     886,   820,  -861,   822,   824,   825,   826,   827,   828,  -861,
     829,   832,   833,   834,   836,   837,   838,   840,  -861,  -861,
    -205,  -861,  -861,  -861,  -166,  -861,   841,   842,   843,   844,
     845,  -861,  -861,   888,   846,   889,   847,  -861,  -861,   890,
     848,   850,  -861,   852,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,   462,   462,   462,   462,   462,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   853,
     854,   855,   856,   857,   858,   859,   861,   862,   863,   864,
     865,    64,   866,   867,  -861,   868,   869,   870,   871,   873,
      -2,   874,   875,   876,   877,   880,   882,   887,   891,  -861,
     892,   893,  -861,  -861,   894,   895,   896,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -165,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -159,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   897,   898,   519,   899,   900,
     901,   902,   903,  -861,   904,   908,   905,  -861,   -40,   906,
     907,   849,   689,  -861,  -861,  -861,   909,   910,  -861,   911,
      54,  -861,  -861,  -861,  -861,  -861,  -861,   912,   915,   513,
     916,   917,   918,   626,   919,  -861,   920,   921,   922,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,   -75,  -861,   -68,  -861,  -861,
    -861,  -861,  -861,   923,   671,   924,  -861,   925,   681,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   800,   800,
     800,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -135,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -129,  -861,  -861,
     561,  -861,   598,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -103,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -101,  -861,  -861,  -861,  -861,  -861,   -61,
    -861,  -861,  -861,   913,   860,   926,  -861,   914,   927,   -94,
     928,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,   -24,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,   -19,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,   -16,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,    76,  -861,  -861,  -861,  -861,  -861,    -2,  -861,   896,
    -861,  -861,  -861,   519,  -861,   908,  -861,   -40,  -861,  -861,
    -861,   929,   245,   931,   932,  -861,  -861,   513,  -861,   626,
    -861,   671,  -861,   681,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,    93,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   245,  -861
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -861,  -861,  -861,  -213,  -306,  -860,  -610,  -861,  -861,   930,
    -861,  -861,  -861,  -861,   933,  -861,  -861,  -861,     6,  -861,
       5,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,   942,  -861,  -861,  -861,
    -861,  -861,   934,  -861,  -861,  -861,  -861,    45,  -861,  -861,
    -861,  -861,  -861,  -229,  -861,  -861,  -861,   509,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -201,  -861,  -861,
    -861,  -194,  -861,  -861,  -861,   688,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -182,  -861,   530,  -861,  -861,
    -861,   -76,  -861,  -861,  -861,  -861,  -861,   576,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -168,  -861,  -861,  -861,  -861,
    -861,  -861,   523,  -861,  -861,  -861,  -861,  -861,   935,  -861,
    -861,  -861,  -861,   476,  -861,  -861,  -861,  -861,  -861,  -179,
    -861,  -861,  -861,   479,  -861,  -861,  -861,  -861,  -158,  -861,
    -861,  -861,   692,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -143,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -126,  -861,   612,  -861,  -861,  -861,
    -861,  -861,   725,  -861,  -861,  -861,  -861,   955,  -861,  -861,
    -861,  -861,  -861,  -861,  -102,  -861,   702,  -861,  -861,  -861,
    -861,   937,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,    28,  -861,  -861,  -861,    32,  -861,  -861,
    -861,  -861,  -861,  1012,  -861,  -861,  -861,  -861,  -861,  -861,
    -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,  -861,
     936,  -861,  -861,  -861,  -861,  -861,  -861
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     822,   823,   585,   586,    76,   235,  1050,   821,   294,    67,
     593,  1096,    47,   455,  1004,   244,   567,   567,  1005,    67,
     235,   558,   110,    48,    77,    78,   483,   110,    52,   456,
      79,   381,    68,    54,   474,   391,    58,   294,    59,    69,
     558,    62,    68,   474,   457,   228,    45,    46,   458,    69,
     381,   245,    63,  1006,  1069,   966,   966,  1007,  1070,   228,
    1071,   484,   758,   759,  1072,   246,   247,   248,   249,   762,
     763,    80,    81,  1038,  1039,  1040,   682,   683,    82,    83,
      84,   485,   111,    66,  1196,   250,   486,   111,  1197,   523,
    1198,   382,   259,   236,  1199,   642,   643,   107,   295,    70,
      85,    86,   524,   650,  1213,   652,   568,   568,   236,    70,
     382,   559,   659,    87,    88,   260,  1202,   664,  1204,   237,
    1203,   108,  1205,   109,    89,   392,   459,   295,   675,   676,
     559,   678,   116,    90,   237,   460,   461,   117,   118,   688,
     689,   115,   691,   119,   487,   967,   967,   225,   261,  1097,
     226,   120,   383,   299,  1098,   475,   393,   121,  1206,   122,
     123,   124,  1207,   227,   475,   821,   125,   391,   462,   569,
     569,   383,   126,   127,   560,   128,   129,   130,  1193,  1194,
    1195,   131,   262,   525,   263,   264,   132,   476,   394,   523,
     133,   134,  1051,   560,   135,  1216,   476,   136,   137,  1217,
    1218,   242,   524,  1220,  1219,   138,   243,  1221,   968,   968,
     526,   292,   139,   140,   293,   141,   142,   143,   144,   145,
     494,   463,   265,   319,   266,   267,   268,   269,   303,   561,
     146,   748,   706,   504,   538,   781,   147,   148,   149,   502,
     150,   270,   477,   151,   152,   718,   389,   153,   561,   505,
     632,   477,   321,   711,   639,   229,   575,   392,   154,   776,
     684,   685,  -107,   300,   506,   271,   322,   323,   507,   229,
     324,   969,   969,   301,  1110,   272,  -107,   577,   496,   302,
     483,   305,   155,   525,   306,  1230,   156,   307,   393,   157,
     158,   159,   160,   161,   811,  1222,   162,   163,   498,  1223,
     826,   827,   819,   820,   273,   274,   308,  1231,   741,  1232,
     526,   556,  1245,   499,   309,   484,  1246,   352,   310,   353,
     394,   354,   311,   508,   312,   313,   314,   259,   315,   325,
     326,   327,   316,   355,   328,   485,   164,   165,   166,   317,
     486,   167,   329,   168,   318,   388,   509,   169,   356,  1233,
     260,   453,   357,   330,   331,   400,   401,   352,   402,   353,
     403,   354,   584,   404,   510,   504,   405,   406,   332,   333,
     407,   408,   358,   355,   359,   409,   410,   411,   412,   244,
     413,   505,   414,   261,   415,   416,   360,   417,   356,   418,
     419,   420,   357,   455,   421,   422,   506,   334,   487,   423,
     507,   424,   791,   792,   793,   794,   795,   361,   425,   456,
     578,   426,   358,   427,   359,   245,   428,   262,   429,   263,
     264,  1234,  1235,   430,   457,   432,   360,   511,   458,   246,
     247,   248,   249,   434,   435,   362,   436,   437,   335,   116,
     438,   512,   439,   440,   117,   118,   441,   361,   442,   250,
     119,   443,   735,   444,  1236,   508,   445,   265,   120,   266,
     267,   268,   269,   363,   121,   446,   122,   123,   124,   447,
     448,   612,   449,   125,   450,   362,   270,   451,   509,   126,
     127,   452,   128,   129,   130,   495,   500,   501,   131,   532,
     364,   533,   534,   132,   535,   536,   510,   133,   134,  1214,
     271,   135,   537,   363,   136,   137,   459,   540,   541,   542,
     272,   543,   138,   544,   545,   460,   461,  1114,   546,   139,
     140,   547,   141,   142,   143,   144,   145,   548,   549,   365,
     364,   550,  1075,   551,   552,   553,   628,   146,  1115,   273,
     274,   554,   555,   147,   148,   149,   574,   150,   462,   579,
     151,   152,  1076,  1116,   153,   580,   321,   581,   582,   511,
    1117,   583,  1077,   584,   587,   154,   588,   589,  1078,   365,
     322,   323,   590,   512,   324,   591,   592,  1118,  1021,  1022,
    1023,  1024,  1025,   594,  1079,   595,   596,   597,   598,   155,
     614,   599,   600,   156,   601,   602,   157,   158,   159,   160,
     161,   463,  1119,   162,   163,   603,   604,   605,   606,  1120,
     607,  1080,   879,     2,     3,   608,   609,     4,   610,  1081,
     634,  1121,   611,   615,   616,   617,   618,     5,   620,   621,
       6,     7,   622,   325,   326,   327,     8,   623,   328,  1122,
     624,  1123,  1124,   164,   165,   166,   329,     9,   167,   902,
     168,    10,    11,   625,   169,   626,   627,   330,   331,  1082,
     641,    12,   630,   631,   635,   636,   637,   644,   645,   646,
     647,   648,   332,   333,   649,    13,  1083,  1138,   651,   653,
     654,   655,   660,   656,   657,    14,    15,   658,   661,   662,
    1125,   663,   665,   666,   667,   668,   669,   670,   671,  1126,
     672,   334,   673,    16,  1127,   674,   677,   679,   680,   681,
    1128,   686,   687,   690,  1129,   692,  1130,    17,   696,   693,
     694,  1131,   695,   697,   698,   699,   720,   713,  1132,   701,
     880,   881,   882,   883,   884,  1167,   885,   886,   702,   887,
     888,   889,   335,   722,   890,  1181,   891,   892,   703,   893,
     704,   894,    18,   895,   896,   705,   723,   897,   708,   710,
     715,    19,    20,   898,   716,    21,    22,   903,   904,   905,
     906,   907,   717,   908,   909,   724,   910,   911,   912,   721,
     727,   913,   743,   914,   915,   744,   916,   725,   917,   726,
     918,   919,   737,   728,   920,  1139,  1140,  1141,  1142,  1143,
     921,  1144,  1145,   730,  1146,  1147,  1148,   731,   732,  1149,
    1168,  1150,  1151,   745,  1152,   746,  1153,    23,  1154,  1155,
    1182,   734,  1156,   738,    76,   739,   740,   747,  1157,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   766,  1169,
     767,   768,   769,   770,    77,    78,   771,   772,  1170,  1183,
      79,   773,   775,   778,  1171,   779,   783,   784,  1184,   785,
     786,   787,   788,   789,  1185,   790,   798,   799,  1172,   800,
    1173,  1174,   801,   802,   809,   803,   804,   805,  1186,  1175,
    1187,  1188,   806,   810,   807,   808,  1176,   812,   813,  1189,
     814,    80,    81,   815,   816,   817,  1190,   818,    82,    83,
      84,   821,   824,   825,   828,   829,   830,   835,   831,   839,
     832,   833,  1104,   834,   842,   836,   843,   837,   838,   840,
      85,    86,   841,   844,   845,   846,   847,   848,   849,   945,
     850,   948,   949,    87,    88,   950,   951,   952,   851,   954,
     852,   956,   946,   853,    89,   854,   855,   856,   857,   858,
     859,   860,   861,    90,   862,   959,   863,   864,   865,   960,
     866,   961,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   901,   924,   925,   926,   927,   928,
     929,   930,   931,   932,   933,   934,   935,   936,   937,   938,
     939,   940,   977,   978,   941,   942,   943,   944,   980,   981,
     953,   982,   947,   984,   986,   987,   988,   955,  1013,  1015,
    1017,  1164,  1165,   304,  1208,  1111,  1103,  1247,  1242,   719,
     957,  1066,   736,  1241,   613,  1228,   964,   958,  1209,   965,
     979,   975,   976,  1092,  1211,  1226,   983,   985,   777,   989,
     707,   990,  1243,   991,   992,   993,   994,   995,   996,   782,
     742,   997,   998,   999,  1224,  1000,  1001,  1002,   629,  1003,
    1008,  1009,  1010,  1011,  1012,  1244,  1016,   390,  1014,  1019,
    1018,  1020,  1026,  1027,  1028,  1029,  1030,  1031,  1032,  1227,
    1033,  1034,  1035,  1036,  1037,  1043,  1044,  1045,  1046,  1047,
    1048,   712,  1049,  1054,  1055,  1056,  1057,  1225,   640,  1058,
    1201,  1059,  1200,   320,     0,     0,  1060,   454,     0,   633,
    1061,  1062,  1063,  1064,  1065,     0,  1073,  1074,  1086,  1087,
    1088,  1089,  1090,  1091,  1095,  1101,  1102,     0,  1106,     0,
       0,  1112,  1107,  1109,  1113,  1135,  1136,  1137,  1160,  1161,
    1162,  1163,  1166,  1179,  1180,  1210,     0,  1215,  1229,  1212,
    1239,  1240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   497,     0,     0,     0,   503,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   539,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   557,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   576
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-861))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     610,   611,   308,   309,     1,     1,     8,   101,     1,     1,
     316,    51,   221,     1,   219,     1,     1,     1,   223,     1,
       1,     1,     1,   221,    21,    22,     1,     1,   221,    17,
      27,     1,    24,   221,     1,     1,   221,     1,   221,    31,
       1,   221,    24,     1,    32,     1,   219,   220,    36,    31,
       1,    37,   221,   219,   219,     1,     1,   223,   223,     1,
     219,    36,   137,   138,   223,    51,    52,    53,    54,   137,
     138,    68,    69,     9,    10,    11,   163,   164,    75,    76,
      77,    56,    61,   221,   219,    71,    61,    61,   223,     1,
     219,    61,     1,    89,   223,   401,   402,   221,    91,    91,
      97,    98,    14,   409,   198,   411,    91,    91,    89,    91,
      61,    91,   418,   110,   111,    24,   219,   423,   219,   115,
     223,   221,   223,   221,   121,    91,   114,    91,   434,   435,
      91,   437,     1,   130,   115,   123,   124,     6,     7,   445,
     446,   221,   448,    12,   119,    91,    91,   221,    57,   189,
     221,    20,   122,   219,   194,   122,   122,    26,   219,    28,
      29,    30,   223,   221,   122,   101,    35,     1,   156,   154,
     154,   122,    41,    42,   154,    44,    45,    46,  1038,  1039,
    1040,    50,    91,    95,    93,    94,    55,   154,   154,     1,
      59,    60,   194,   154,    63,   219,   154,    66,    67,   223,
     219,   221,    14,   219,   223,    74,   221,   223,   154,   154,
     122,   221,    81,    82,   221,    84,    85,    86,    87,    88,
     219,   209,   131,   220,   133,   134,   135,   136,   220,   209,
      99,   537,   220,     1,   220,   220,   105,   106,   107,   220,
     109,   150,   209,   112,   113,   220,   220,   116,   209,    17,
     220,   209,     1,   220,   220,   211,   220,    91,   127,   220,
     163,   164,   218,   222,    32,   174,    15,    16,    36,   211,
      19,   217,   217,   222,   220,   184,   218,   120,   220,   222,
       1,   222,   151,    95,   222,    40,   155,   222,   122,   158,
     159,   160,   161,   162,   600,   219,   165,   166,   218,   223,
     181,   182,   608,   609,   213,   214,   222,    62,   220,    64,
     122,   220,   219,   219,   222,    36,   223,     1,   222,     3,
     154,     5,   222,    91,   222,   222,   222,     1,   222,    78,
      79,    80,   222,    17,    83,    56,   205,   206,   207,   222,
      61,   210,    91,   212,   222,   222,   114,   216,    32,   104,
      24,   220,    36,   102,   103,   222,   222,     1,   222,     3,
     222,     5,   101,   222,   132,     1,   222,   222,   117,   118,
     222,   222,    56,    17,    58,   222,   222,   222,   222,     1,
     222,    17,   222,    57,   222,   222,    70,   222,    32,   222,
     222,   222,    36,     1,   222,   222,    32,   146,   119,   222,
      36,   222,   141,   142,   143,   144,   145,    91,   222,    17,
     120,   222,    56,   222,    58,    37,   222,    91,   222,    93,
      94,   176,   177,   222,    32,   222,    70,   195,    36,    51,
      52,    53,    54,   222,   222,   119,   222,   222,   187,     1,
     222,   209,   222,   222,     6,     7,   222,    91,   222,    71,
      12,   222,   220,   222,   209,    91,   222,   131,    20,   133,
     134,   135,   136,   147,    26,   222,    28,    29,    30,   222,
     222,   220,   222,    35,   222,   119,   150,   222,   114,    41,
      42,   222,    44,    45,    46,   222,   222,   222,    50,   222,
     174,   222,   222,    55,   222,   222,   132,    59,    60,  1109,
     174,    63,   222,   147,    66,    67,   114,   219,   222,   222,
     184,   222,    74,   222,   222,   123,   124,     4,   222,    81,
      82,   222,    84,    85,    86,    87,    88,   222,   222,   213,
     174,   222,    13,   222,   222,   222,   220,    99,    25,   213,
     214,   222,   222,   105,   106,   107,   222,   109,   156,   120,
     112,   113,    33,    40,   116,   219,     1,   101,   101,   195,
      47,   163,    43,   101,   101,   127,   101,   101,    49,   213,
      15,    16,   163,   209,    19,   163,   101,    64,   791,   792,
     793,   794,   795,   163,    65,   163,   219,   219,   222,   151,
     219,   222,   222,   155,   222,   222,   158,   159,   160,   161,
     162,   209,    89,   165,   166,   222,   222,   222,   222,    96,
     222,    92,    51,     0,     1,   222,   222,     4,   222,   100,
     120,   108,   222,   222,   222,   222,   222,    14,   222,   222,
      17,    18,   222,    78,    79,    80,    23,   222,    83,   126,
     222,   128,   129,   205,   206,   207,    91,    34,   210,    51,
     212,    38,    39,   222,   216,   222,   222,   102,   103,   140,
     163,    48,   222,   222,   219,   222,   222,   101,   163,   163,
     101,   120,   117,   118,   163,    62,   157,    51,   163,   101,
     101,   101,   120,   163,   163,    72,    73,   163,   163,   101,
     177,   101,   101,   101,   120,   101,   101,   163,   163,   186,
     222,   146,   163,    90,   191,   222,   163,   163,   163,   163,
     197,   163,   163,   120,   201,   163,   203,   104,   219,   163,
     163,   208,   163,   219,   222,   222,   163,   219,   215,   222,
     169,   170,   171,   172,   173,    64,   175,   176,   222,   178,
     179,   180,   187,   221,   183,    64,   185,   186,   222,   188,
     222,   190,   139,   192,   193,   222,   120,   196,   222,   222,
     222,   148,   149,   202,   222,   152,   153,   169,   170,   171,
     172,   173,   222,   175,   176,   120,   178,   179,   180,   219,
     222,   183,   163,   185,   186,   163,   188,   219,   190,   219,
     192,   193,   219,   222,   196,   169,   170,   171,   172,   173,
     202,   175,   176,   222,   178,   179,   180,   222,   222,   183,
     139,   185,   186,   120,   188,   163,   190,   204,   192,   193,
     139,   222,   196,   222,     1,   222,   222,   163,   202,   219,
     120,   163,   120,   120,   120,   120,   120,   120,   120,   168,
     120,   101,   120,   120,    21,    22,   219,   219,   177,   168,
      27,   222,   222,   219,   183,   222,   120,   219,   177,   219,
     219,   219,   219,   219,   183,   219,   219,   219,   197,   219,
     199,   200,   219,   219,   101,   219,   219,   219,   197,   208,
     199,   200,   219,   101,   219,   219,   215,   101,   101,   208,
     101,    68,    69,   101,   120,   101,   215,   101,    75,    76,
      77,   101,   219,   120,   120,   163,   222,   101,   120,   219,
     120,   120,   223,   120,   219,   120,   219,   120,   120,   120,
      97,    98,   120,   120,   120,   222,   219,   219,   219,   120,
     219,   120,   101,   110,   111,   120,   120,   120,   219,   120,
     219,   120,   163,   219,   121,   219,   219,   219,   219,   219,
     219,   219,   219,   130,   219,   120,   219,   219,   219,   120,
     219,   101,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   120,   163,   219,   219,   219,   219,   120,   120,
     219,   120,   222,   120,   120,   120,   120,   222,   120,   120,
     120,  1005,  1007,    71,   101,   970,   167,  1246,  1219,   489,
     219,   125,   513,  1217,   336,  1207,   219,   222,  1104,   219,
     222,   219,   219,   125,   120,  1203,   222,   219,   562,   219,
     464,   219,  1221,   219,   219,   219,   219,   219,   219,   570,
     527,   219,   219,   219,  1197,   219,   219,   219,   366,   219,
     219,   219,   219,   219,   219,  1223,   219,   112,   222,   219,
     222,   219,   219,   219,   219,   219,   219,   219,   219,  1205,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   479,   219,   219,   219,   219,   219,  1199,   396,   219,
    1072,   219,  1070,    91,    -1,    -1,   219,   170,    -1,   384,
     219,   219,   219,   219,   219,    -1,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,    -1,   219,    -1,
      -1,   219,   222,   222,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,    -1,   219,   219,   222,
     219,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,   238,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   251,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   275,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   296
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   225,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    72,    73,    90,   104,   139,   148,
     149,   152,   153,   204,   226,   231,   236,   258,   264,   278,
     296,   314,   328,   343,   350,   354,   364,   373,   393,   403,
     409,   413,   423,   485,   502,   219,   220,   221,   221,   297,
     374,   404,   221,   414,   221,   329,   394,   315,   221,   221,
     279,   344,   221,   221,   355,   365,   221,     1,    24,    31,
      91,   259,   260,   261,   262,   263,     1,    21,    22,    27,
      68,    69,    75,    76,    77,    97,    98,   110,   111,   121,
     130,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   221,   221,   221,
       1,    61,   410,   411,   412,   221,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    66,    67,    74,    81,
      82,    84,    85,    86,    87,    88,    99,   105,   106,   107,
     109,   112,   113,   116,   127,   151,   155,   158,   159,   160,
     161,   162,   165,   166,   205,   206,   207,   210,   212,   216,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   478,   482,   483,   484,   221,   221,   221,     1,   211,
     265,   266,   267,   268,   269,     1,    89,   115,   232,   233,
     234,   235,   221,   221,     1,    37,    51,    52,    53,    54,
      71,   503,   504,   505,   506,   507,   508,   509,   510,     1,
      24,    57,    91,    93,    94,   131,   133,   134,   135,   136,
     150,   174,   184,   213,   214,   237,   238,   239,   240,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   221,   221,     1,    91,   351,   352,   353,   219,
     222,   222,   222,   220,   260,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   220,
     487,     1,    15,    16,    19,    78,    79,    80,    83,    91,
     102,   103,   117,   118,   146,   187,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,     1,     3,     5,    17,    32,    36,    56,    58,
      70,    91,   119,   147,   174,   213,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   388,   389,   390,   391,
     392,     1,    61,   122,   405,   406,   407,   408,   222,   220,
     411,     1,    91,   122,   154,   415,   419,   420,   421,   422,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   479,   222,   475,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   220,   425,     1,    17,    32,    36,   114,
     123,   124,   156,   209,   330,   331,   332,   333,   334,   335,
     336,   340,   341,   342,     1,   122,   154,   209,   395,   399,
     400,   401,   402,     1,    36,    56,    61,   119,   316,   320,
     321,   322,   326,   327,   219,   222,   220,   266,   218,   219,
     222,   222,   220,   233,     1,    17,    32,    36,    91,   114,
     132,   195,   209,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   292,     1,    14,    95,   122,   345,   346,   347,
     348,   349,   222,   222,   222,   222,   222,   222,   220,   504,
     219,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   220,   238,     1,    91,
     154,   209,   356,   357,   358,   359,   360,     1,    91,   154,
     366,   367,   368,   369,   222,   220,   352,   120,   120,   120,
     219,   101,   101,   163,   101,   228,   228,   101,   101,   101,
     163,   163,   101,   228,   163,   163,   219,   219,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   220,   299,   219,   222,   222,   222,   222,   385,
     222,   222,   222,   222,   222,   222,   222,   222,   220,   376,
     222,   222,   220,   406,   120,   219,   222,   222,   416,   220,
     420,   163,   228,   228,   101,   163,   163,   101,   120,   163,
     228,   163,   228,   101,   101,   101,   163,   163,   163,   228,
     120,   163,   101,   101,   228,   101,   101,   120,   101,   101,
     163,   163,   222,   163,   222,   228,   228,   163,   228,   163,
     163,   163,   163,   164,   163,   164,   163,   163,   228,   228,
     120,   228,   163,   163,   163,   163,   219,   219,   222,   222,
     337,   222,   222,   222,   222,   222,   220,   331,   222,   396,
     222,   220,   400,   219,   317,   222,   222,   222,   220,   321,
     163,   219,   221,   120,   120,   219,   219,   222,   222,   293,
     222,   222,   222,   289,   222,   220,   281,   219,   222,   222,
     222,   220,   346,   163,   163,   120,   163,   163,   228,   219,
     120,   163,   120,   120,   120,   120,   120,   120,   137,   138,
     241,   242,   137,   138,   243,   244,   120,   120,   101,   120,
     120,   219,   219,   222,   361,   222,   220,   357,   219,   222,
     370,   220,   367,   120,   219,   219,   219,   219,   219,   219,
     219,   141,   142,   143,   144,   145,   227,   228,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   101,
     101,   228,   101,   101,   101,   101,   120,   101,   101,   228,
     228,   101,   230,   230,   219,   120,   181,   182,   120,   163,
     222,   120,   120,   120,   120,   101,   120,   120,   120,   219,
     120,   120,   219,   219,   120,   120,   222,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,    51,
     169,   170,   171,   172,   173,   175,   176,   178,   179,   180,
     183,   185,   186,   188,   190,   192,   193,   196,   202,   480,
     481,   219,    51,   169,   170,   171,   172,   173,   175,   176,
     178,   179,   180,   183,   185,   186,   188,   190,   192,   193,
     196,   202,   476,   477,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   120,   163,   222,   120,   101,
     120,   120,   120,   219,   120,   222,   120,   219,   222,   120,
     120,   101,   324,   325,   219,   219,     1,    91,   154,   217,
     270,   271,   272,   273,   274,   219,   219,   120,   163,   222,
     120,   120,   120,   222,   120,   219,   120,   120,   120,   219,
     219,   219,   219,   219,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   223,   219,   223,   219,   219,
     219,   219,   219,   120,   222,   120,   219,   120,   222,   219,
     219,   227,   227,   227,   227,   227,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   219,   219,     9,    10,
      11,   229,   230,   219,   219,   219,   219,   219,   219,   219,
       8,   194,   386,   387,   219,   219,   219,   219,   219,   219,
     219,   219,   219,   219,   219,   219,   125,   417,   418,   219,
     223,   219,   223,   219,   219,    13,    33,    43,    49,    65,
      92,   100,   140,   157,   338,   339,   219,   219,   219,   219,
     219,   219,   125,   397,   398,   219,    51,   189,   194,   318,
     319,   219,   219,   167,   223,   323,   219,   222,   275,   222,
     220,   271,   219,   219,     4,    25,    40,    47,    64,    89,
      96,   108,   126,   128,   129,   177,   186,   191,   197,   201,
     203,   208,   215,   294,   295,   219,   219,   219,    51,   169,
     170,   171,   172,   173,   175,   176,   178,   179,   180,   183,
     185,   186,   188,   190,   192,   193,   196,   202,   290,   291,
     219,   219,   219,   219,   242,   244,   219,    64,   139,   168,
     177,   183,   197,   199,   200,   208,   215,   362,   363,   219,
     219,    64,   139,   168,   177,   183,   197,   199,   200,   208,
     215,   371,   372,   229,   229,   229,   219,   223,   219,   223,
     481,   477,   219,   223,   219,   223,   219,   223,   101,   325,
     219,   120,   222,   198,   230,   219,   219,   223,   219,   223,
     219,   223,   219,   223,   387,   418,   339,   398,   319,   219,
      40,    62,    64,   104,   176,   177,   209,   276,   277,   219,
     219,   295,   291,   363,   372,   219,   223,   277
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
#line 363 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 365 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 369 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 373 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 377 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 381 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 385 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 390 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 391 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 392 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 393 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 394 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 439 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 445 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1787 of yacc.c  */
#line 454 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1787 of yacc.c  */
#line 460 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1787 of yacc.c  */
#line 468 "conf_parser.y"
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
#line 507 "conf_parser.y"
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
#line 566 "conf_parser.y"
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
#line 594 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1787 of yacc.c  */
#line 602 "conf_parser.y"
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
#line 617 "conf_parser.y"
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
#line 632 "conf_parser.y"
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
#line 641 "conf_parser.y"
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
#line 655 "conf_parser.y"
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
#line 664 "conf_parser.y"
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
#line 692 "conf_parser.y"
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
#line 722 "conf_parser.y"
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
#line 745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 760 "conf_parser.y"
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
#line 769 "conf_parser.y"
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
#line 778 "conf_parser.y"
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
#line 796 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1787 of yacc.c  */
#line 802 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 807 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1787 of yacc.c  */
#line 819 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1787 of yacc.c  */
#line 824 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 827 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 832 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 839 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 843 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 847 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1787 of yacc.c  */
#line 859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1787 of yacc.c  */
#line 863 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1787 of yacc.c  */
#line 873 "conf_parser.y"
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
#line 886 "conf_parser.y"
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
        new_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, 
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
#line 976 "conf_parser.y"
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
#line 985 "conf_parser.y"
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
#line 1022 "conf_parser.y"
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
#line 1034 "conf_parser.y"
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
#line 1045 "conf_parser.y"
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

    yy_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

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
#line 1087 "conf_parser.y"
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
#line 1096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1787 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1787 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1787 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1787 of yacc.c  */
#line 1115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1787 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1787 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1787 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1787 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1787 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1787 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1787 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1787 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1787 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1787 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1787 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1787 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1787 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1787 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1787 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1787 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1787 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1787 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1787 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1787 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1787 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1787 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1787 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1787 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1787 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1787 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1787 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1787 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1787 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1787 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1787 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1787 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1787 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1787 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1787 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1787 of yacc.c  */
#line 1264 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1787 of yacc.c  */
#line 1274 "conf_parser.y"
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
#line 1281 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1339 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:
/* Line 1787 of yacc.c  */
#line 1348 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1787 of yacc.c  */
#line 1354 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1787 of yacc.c  */
#line 1360 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1787 of yacc.c  */
#line 1366 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1787 of yacc.c  */
#line 1372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1787 of yacc.c  */
#line 1378 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1787 of yacc.c  */
#line 1384 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1787 of yacc.c  */
#line 1390 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1787 of yacc.c  */
#line 1396 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1787 of yacc.c  */
#line 1402 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1787 of yacc.c  */
#line 1409 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1787 of yacc.c  */
#line 1415 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1787 of yacc.c  */
#line 1421 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1787 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:
/* Line 1787 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:
/* Line 1787 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:
/* Line 1787 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:
/* Line 1787 of yacc.c  */
#line 1456 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:
/* Line 1787 of yacc.c  */
#line 1460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:
/* Line 1787 of yacc.c  */
#line 1470 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:
/* Line 1787 of yacc.c  */
#line 1475 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1489 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1509 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:
/* Line 1787 of yacc.c  */
#line 1518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:
/* Line 1787 of yacc.c  */
#line 1530 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1542 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1604 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1639 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:
/* Line 1787 of yacc.c  */
#line 1661 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1672 "conf_parser.y"
    {
}
    break;

  case 273:
/* Line 1787 of yacc.c  */
#line 1677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:
/* Line 1787 of yacc.c  */
#line 1681 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:
/* Line 1787 of yacc.c  */
#line 1685 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:
/* Line 1787 of yacc.c  */
#line 1689 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:
/* Line 1787 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:
/* Line 1787 of yacc.c  */
#line 1697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:
/* Line 1787 of yacc.c  */
#line 1701 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:
/* Line 1787 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:
/* Line 1787 of yacc.c  */
#line 1709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:
/* Line 1787 of yacc.c  */
#line 1716 "conf_parser.y"
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

  case 283:
/* Line 1787 of yacc.c  */
#line 1735 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 284:
/* Line 1787 of yacc.c  */
#line 1745 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 285:
/* Line 1787 of yacc.c  */
#line 1758 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 286:
/* Line 1787 of yacc.c  */
#line 1765 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 293:
/* Line 1787 of yacc.c  */
#line 1777 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 294:
/* Line 1787 of yacc.c  */
#line 1786 "conf_parser.y"
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

  case 295:
/* Line 1787 of yacc.c  */
#line 1801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:
/* Line 1787 of yacc.c  */
#line 1819 "conf_parser.y"
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

  case 302:
/* Line 1787 of yacc.c  */
#line 1834 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:
/* Line 1787 of yacc.c  */
#line 1853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:
/* Line 1787 of yacc.c  */
#line 1862 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:
/* Line 1787 of yacc.c  */
#line 1891 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:
/* Line 1787 of yacc.c  */
#line 1895 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:
/* Line 1787 of yacc.c  */
#line 1899 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:
/* Line 1787 of yacc.c  */
#line 1903 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:
/* Line 1787 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:
/* Line 1787 of yacc.c  */
#line 1911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:
/* Line 1787 of yacc.c  */
#line 1915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:
/* Line 1787 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:
/* Line 1787 of yacc.c  */
#line 1923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:
/* Line 1787 of yacc.c  */
#line 1927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:
/* Line 1787 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:
/* Line 1787 of yacc.c  */
#line 1943 "conf_parser.y"
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
/* Line 1787 of yacc.c  */
#line 1956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:
/* Line 1787 of yacc.c  */
#line 1962 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:
/* Line 1787 of yacc.c  */
#line 1969 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1787 of yacc.c  */
#line 1973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1787 of yacc.c  */
#line 1977 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1787 of yacc.c  */
#line 1981 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1787 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1787 of yacc.c  */
#line 1989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1787 of yacc.c  */
#line 1993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1787 of yacc.c  */
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1787 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1787 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:
/* Line 1787 of yacc.c  */
#line 2014 "conf_parser.y"
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

  case 349:
/* Line 1787 of yacc.c  */
#line 2029 "conf_parser.y"
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

  case 366:
/* Line 1787 of yacc.c  */
#line 2073 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 367:
/* Line 1787 of yacc.c  */
#line 2082 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 368:
/* Line 1787 of yacc.c  */
#line 2091 "conf_parser.y"
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

  case 369:
/* Line 1787 of yacc.c  */
#line 2117 "conf_parser.y"
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

  case 370:
/* Line 1787 of yacc.c  */
#line 2135 "conf_parser.y"
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

  case 371:
/* Line 1787 of yacc.c  */
#line 2153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:
/* Line 1787 of yacc.c  */
#line 2159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:
/* Line 1787 of yacc.c  */
#line 2163 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:
/* Line 1787 of yacc.c  */
#line 2171 "conf_parser.y"
    {
}
    break;

  case 378:
/* Line 1787 of yacc.c  */
#line 2176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:
/* Line 1787 of yacc.c  */
#line 2180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1787 of yacc.c  */
#line 2186 "conf_parser.y"
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
#line 2197 "conf_parser.y"
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
#line 2208 "conf_parser.y"
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
#line 2219 "conf_parser.y"
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
#line 2228 "conf_parser.y"
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
#line 2246 "conf_parser.y"
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
#line 2253 "conf_parser.y"
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
#line 2311 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1787 of yacc.c  */
#line 2316 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1787 of yacc.c  */
#line 2325 "conf_parser.y"
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
#line 2344 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1787 of yacc.c  */
#line 2353 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1787 of yacc.c  */
#line 2357 "conf_parser.y"
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
#line 2381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1787 of yacc.c  */
#line 2387 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1787 of yacc.c  */
#line 2401 "conf_parser.y"
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
#line 2419 "conf_parser.y"
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
#line 2426 "conf_parser.y"
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
#line 2466 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1787 of yacc.c  */
#line 2471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1787 of yacc.c  */
#line 2480 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1787 of yacc.c  */
#line 2486 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 487:
/* Line 1787 of yacc.c  */
#line 2531 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:
/* Line 1787 of yacc.c  */
#line 2536 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 489:
/* Line 1787 of yacc.c  */
#line 2542 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1787 of yacc.c  */
#line 2548 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1787 of yacc.c  */
#line 2554 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1787 of yacc.c  */
#line 2559 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1787 of yacc.c  */
#line 2564 "conf_parser.y"
    {
  ConfigFileEntry.use_whois_actually = yylval.number;
}
    break;

  case 494:
/* Line 1787 of yacc.c  */
#line 2569 "conf_parser.y"
    {
  GlobalSetOptions.rejecttime = yylval.number;
}
    break;

  case 495:
/* Line 1787 of yacc.c  */
#line 2574 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 496:
/* Line 1787 of yacc.c  */
#line 2579 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:
/* Line 1787 of yacc.c  */
#line 2584 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 498:
/* Line 1787 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 499:
/* Line 1787 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 500:
/* Line 1787 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 501:
/* Line 1787 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 502:
/* Line 1787 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 503:
/* Line 1787 of yacc.c  */
#line 2614 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1787 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1787 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1787 of yacc.c  */
#line 2629 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1787 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1787 of yacc.c  */
#line 2640 "conf_parser.y"
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

  case 509:
/* Line 1787 of yacc.c  */
#line 2651 "conf_parser.y"
    {
  ConfigFileEntry.kline_with_reason = yylval.number;
}
    break;

  case 510:
/* Line 1787 of yacc.c  */
#line 2656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.kline_reason);
    DupString(ConfigFileEntry.kline_reason, yylval.string);
  }
}
    break;

  case 511:
/* Line 1787 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 512:
/* Line 1787 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 513:
/* Line 1787 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 514:
/* Line 1787 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 515:
/* Line 1787 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 516:
/* Line 1787 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 517:
/* Line 1787 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 518:
/* Line 1787 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 519:
/* Line 1787 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 520:
/* Line 1787 of yacc.c  */
#line 2706 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1787 of yacc.c  */
#line 2711 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1787 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 523:
/* Line 1787 of yacc.c  */
#line 2721 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 524:
/* Line 1787 of yacc.c  */
#line 2726 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 525:
/* Line 1787 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 526:
/* Line 1787 of yacc.c  */
#line 2736 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 527:
/* Line 1787 of yacc.c  */
#line 2741 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 528:
/* Line 1787 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 529:
/* Line 1787 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:
/* Line 1787 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1787 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 532:
/* Line 1787 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 533:
/* Line 1787 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 534:
/* Line 1787 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 535:
/* Line 1787 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 536:
/* Line 1787 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 537:
/* Line 1787 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 541:
/* Line 1787 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 542:
/* Line 1787 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 543:
/* Line 1787 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 544:
/* Line 1787 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 545:
/* Line 1787 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 546:
/* Line 1787 of yacc.c  */
#line 2826 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 547:
/* Line 1787 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 548:
/* Line 1787 of yacc.c  */
#line 2832 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 549:
/* Line 1787 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 550:
/* Line 1787 of yacc.c  */
#line 2838 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 551:
/* Line 1787 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 552:
/* Line 1787 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 553:
/* Line 1787 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 554:
/* Line 1787 of yacc.c  */
#line 2850 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 555:
/* Line 1787 of yacc.c  */
#line 2853 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 556:
/* Line 1787 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 557:
/* Line 1787 of yacc.c  */
#line 2859 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 558:
/* Line 1787 of yacc.c  */
#line 2862 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 559:
/* Line 1787 of yacc.c  */
#line 2865 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 560:
/* Line 1787 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 561:
/* Line 1787 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 565:
/* Line 1787 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 566:
/* Line 1787 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 567:
/* Line 1787 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 568:
/* Line 1787 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 569:
/* Line 1787 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 570:
/* Line 1787 of yacc.c  */
#line 2894 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 571:
/* Line 1787 of yacc.c  */
#line 2897 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 572:
/* Line 1787 of yacc.c  */
#line 2900 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 573:
/* Line 1787 of yacc.c  */
#line 2903 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 574:
/* Line 1787 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 575:
/* Line 1787 of yacc.c  */
#line 2909 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 576:
/* Line 1787 of yacc.c  */
#line 2912 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 577:
/* Line 1787 of yacc.c  */
#line 2915 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 578:
/* Line 1787 of yacc.c  */
#line 2918 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 579:
/* Line 1787 of yacc.c  */
#line 2921 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 580:
/* Line 1787 of yacc.c  */
#line 2924 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 581:
/* Line 1787 of yacc.c  */
#line 2927 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 582:
/* Line 1787 of yacc.c  */
#line 2930 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 583:
/* Line 1787 of yacc.c  */
#line 2933 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 584:
/* Line 1787 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 585:
/* Line 1787 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 586:
/* Line 1787 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 587:
/* Line 1787 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1787 of yacc.c  */
#line 2974 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 607:
/* Line 1787 of yacc.c  */
#line 2979 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 608:
/* Line 1787 of yacc.c  */
#line 2984 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:
/* Line 1787 of yacc.c  */
#line 2989 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1787 of yacc.c  */
#line 2994 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1787 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1787 of yacc.c  */
#line 3004 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 613:
/* Line 1787 of yacc.c  */
#line 3009 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 614:
/* Line 1787 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1787 of yacc.c  */
#line 3019 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 616:
/* Line 1787 of yacc.c  */
#line 3024 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 617:
/* Line 1787 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 618:
/* Line 1787 of yacc.c  */
#line 3034 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 619:
/* Line 1787 of yacc.c  */
#line 3039 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 630:
/* Line 1787 of yacc.c  */
#line 3057 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 631:
/* Line 1787 of yacc.c  */
#line 3063 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 632:
/* Line 1787 of yacc.c  */
#line 3069 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 633:
/* Line 1787 of yacc.c  */
#line 3078 "conf_parser.y"
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

  case 634:
/* Line 1787 of yacc.c  */
#line 3092 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 635:
/* Line 1787 of yacc.c  */
#line 3098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1787 of yacc.c  */
#line 6912 "conf_parser.c"
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


