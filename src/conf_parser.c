/* A Bison parser, made by GNU Bison 2.6.2.33-cc5a9.  */

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
#define YYBISON_VERSION "2.6.2.33-cc5a9"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 358 of yacc.c  */
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


/* Line 358 of yacc.c  */
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
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
     KNOCK_DELAY = 321,
     KNOCK_DELAY_CHANNEL = 322,
     LEAF_MASK = 323,
     LINKS_DELAY = 324,
     LISTEN = 325,
     T_LOG = 326,
     MAX_ACCEPT = 327,
     MAX_BANS = 328,
     MAX_CHANS_PER_OPER = 329,
     MAX_CHANS_PER_USER = 330,
     MAX_GLOBAL = 331,
     MAX_IDENT = 332,
     MAX_LOCAL = 333,
     MAX_NICK_CHANGES = 334,
     MAX_NICK_TIME = 335,
     MAX_NUMBER = 336,
     MAX_TARGETS = 337,
     MAX_WATCH = 338,
     MESSAGE_LOCALE = 339,
     MIN_NONWILDCARD = 340,
     MIN_NONWILDCARD_SIMPLE = 341,
     MODULE = 342,
     MODULES = 343,
     NAME = 344,
     NEED_PASSWORD = 345,
     NETWORK_DESC = 346,
     NETWORK_NAME = 347,
     NICK = 348,
     NICK_CHANGES = 349,
     NO_CREATE_ON_SPLIT = 350,
     NO_JOIN_ON_SPLIT = 351,
     NO_OPER_FLOOD = 352,
     NO_TILDE = 353,
     NUMBER = 354,
     NUMBER_PER_CIDR = 355,
     NUMBER_PER_IP = 356,
     OPERATOR = 357,
     OPERS_BYPASS_CALLERID = 358,
     OPER_ONLY_UMODES = 359,
     OPER_PASS_RESV = 360,
     OPER_SPY_T = 361,
     OPER_UMODES = 362,
     JOIN_FLOOD_COUNT = 363,
     JOIN_FLOOD_TIME = 364,
     PACE_WAIT = 365,
     PACE_WAIT_SIMPLE = 366,
     PASSWORD = 367,
     PATH = 368,
     PING_COOKIE = 369,
     PING_TIME = 370,
     PING_WARNING = 371,
     PORT = 372,
     QSTRING = 373,
     QUIET_ON_BAN = 374,
     REASON = 375,
     REDIRPORT = 376,
     REDIRSERV = 377,
     REGEX_T = 378,
     REHASH = 379,
     REMOTE = 380,
     REMOTEBAN = 381,
     RESTRICT_CHANNELS = 382,
     RSA_PRIVATE_KEY_FILE = 383,
     RSA_PUBLIC_KEY_FILE = 384,
     SSL_CERTIFICATE_FILE = 385,
     SSL_DH_PARAM_FILE = 386,
     T_SSL_CLIENT_METHOD = 387,
     T_SSL_SERVER_METHOD = 388,
     T_SSLV3 = 389,
     T_TLSV1 = 390,
     RESV = 391,
     RESV_EXEMPT = 392,
     SECONDS = 393,
     MINUTES = 394,
     HOURS = 395,
     DAYS = 396,
     WEEKS = 397,
     SENDQ = 398,
     SEND_PASSWORD = 399,
     SERVERHIDE = 400,
     SERVERINFO = 401,
     IRCD_SID = 402,
     TKLINE_EXPIRE_NOTICES = 403,
     T_SHARED = 404,
     T_CLUSTER = 405,
     TYPE = 406,
     SHORT_MOTD = 407,
     SPOOF = 408,
     SPOOF_NOTICE = 409,
     STATS_E_DISABLED = 410,
     STATS_I_OPER_ONLY = 411,
     STATS_K_OPER_ONLY = 412,
     STATS_O_OPER_ONLY = 413,
     STATS_P_OPER_ONLY = 414,
     TBOOL = 415,
     TMASKED = 416,
     TS_MAX_DELTA = 417,
     TS_WARN_DELTA = 418,
     TWODOTS = 419,
     T_ALL = 420,
     T_BOTS = 421,
     T_SOFTCALLERID = 422,
     T_CALLERID = 423,
     T_CCONN = 424,
     T_CCONN_FULL = 425,
     T_SSL_CIPHER_LIST = 426,
     T_DEAF = 427,
     T_DEBUG = 428,
     T_DLINE = 429,
     T_EXTERNAL = 430,
     T_FULL = 431,
     T_INVISIBLE = 432,
     T_IPV4 = 433,
     T_IPV6 = 434,
     T_LOCOPS = 435,
     T_MAX_CLIENTS = 436,
     T_NCHANGE = 437,
     T_OPERWALL = 438,
     T_RECVQ = 439,
     T_REJ = 440,
     T_SERVER = 441,
     T_SERVNOTICE = 442,
     T_SET = 443,
     T_SKILL = 444,
     T_SPY = 445,
     T_SSL = 446,
     T_UMODES = 447,
     T_UNAUTH = 448,
     T_UNDLINE = 449,
     T_UNLIMITED = 450,
     T_UNRESV = 451,
     T_UNXLINE = 452,
     T_GLOBOPS = 453,
     T_WALLOP = 454,
     T_RESTART = 455,
     T_SERVICE = 456,
     T_SERVICES_NAME = 457,
     THROTTLE_TIME = 458,
     TRUE_NO_OPER_FLOOD = 459,
     UNKLINE = 460,
     USER = 461,
     USE_EGD = 462,
     USE_LOGGING = 463,
     VHOST = 464,
     VHOST6 = 465,
     XLINE = 466,
     WARN_NO_NLINE = 467,
     T_SIZE = 468,
     T_FILE = 469
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
#define KNOCK_DELAY 321
#define KNOCK_DELAY_CHANNEL 322
#define LEAF_MASK 323
#define LINKS_DELAY 324
#define LISTEN 325
#define T_LOG 326
#define MAX_ACCEPT 327
#define MAX_BANS 328
#define MAX_CHANS_PER_OPER 329
#define MAX_CHANS_PER_USER 330
#define MAX_GLOBAL 331
#define MAX_IDENT 332
#define MAX_LOCAL 333
#define MAX_NICK_CHANGES 334
#define MAX_NICK_TIME 335
#define MAX_NUMBER 336
#define MAX_TARGETS 337
#define MAX_WATCH 338
#define MESSAGE_LOCALE 339
#define MIN_NONWILDCARD 340
#define MIN_NONWILDCARD_SIMPLE 341
#define MODULE 342
#define MODULES 343
#define NAME 344
#define NEED_PASSWORD 345
#define NETWORK_DESC 346
#define NETWORK_NAME 347
#define NICK 348
#define NICK_CHANGES 349
#define NO_CREATE_ON_SPLIT 350
#define NO_JOIN_ON_SPLIT 351
#define NO_OPER_FLOOD 352
#define NO_TILDE 353
#define NUMBER 354
#define NUMBER_PER_CIDR 355
#define NUMBER_PER_IP 356
#define OPERATOR 357
#define OPERS_BYPASS_CALLERID 358
#define OPER_ONLY_UMODES 359
#define OPER_PASS_RESV 360
#define OPER_SPY_T 361
#define OPER_UMODES 362
#define JOIN_FLOOD_COUNT 363
#define JOIN_FLOOD_TIME 364
#define PACE_WAIT 365
#define PACE_WAIT_SIMPLE 366
#define PASSWORD 367
#define PATH 368
#define PING_COOKIE 369
#define PING_TIME 370
#define PING_WARNING 371
#define PORT 372
#define QSTRING 373
#define QUIET_ON_BAN 374
#define REASON 375
#define REDIRPORT 376
#define REDIRSERV 377
#define REGEX_T 378
#define REHASH 379
#define REMOTE 380
#define REMOTEBAN 381
#define RESTRICT_CHANNELS 382
#define RSA_PRIVATE_KEY_FILE 383
#define RSA_PUBLIC_KEY_FILE 384
#define SSL_CERTIFICATE_FILE 385
#define SSL_DH_PARAM_FILE 386
#define T_SSL_CLIENT_METHOD 387
#define T_SSL_SERVER_METHOD 388
#define T_SSLV3 389
#define T_TLSV1 390
#define RESV 391
#define RESV_EXEMPT 392
#define SECONDS 393
#define MINUTES 394
#define HOURS 395
#define DAYS 396
#define WEEKS 397
#define SENDQ 398
#define SEND_PASSWORD 399
#define SERVERHIDE 400
#define SERVERINFO 401
#define IRCD_SID 402
#define TKLINE_EXPIRE_NOTICES 403
#define T_SHARED 404
#define T_CLUSTER 405
#define TYPE 406
#define SHORT_MOTD 407
#define SPOOF 408
#define SPOOF_NOTICE 409
#define STATS_E_DISABLED 410
#define STATS_I_OPER_ONLY 411
#define STATS_K_OPER_ONLY 412
#define STATS_O_OPER_ONLY 413
#define STATS_P_OPER_ONLY 414
#define TBOOL 415
#define TMASKED 416
#define TS_MAX_DELTA 417
#define TS_WARN_DELTA 418
#define TWODOTS 419
#define T_ALL 420
#define T_BOTS 421
#define T_SOFTCALLERID 422
#define T_CALLERID 423
#define T_CCONN 424
#define T_CCONN_FULL 425
#define T_SSL_CIPHER_LIST 426
#define T_DEAF 427
#define T_DEBUG 428
#define T_DLINE 429
#define T_EXTERNAL 430
#define T_FULL 431
#define T_INVISIBLE 432
#define T_IPV4 433
#define T_IPV6 434
#define T_LOCOPS 435
#define T_MAX_CLIENTS 436
#define T_NCHANGE 437
#define T_OPERWALL 438
#define T_RECVQ 439
#define T_REJ 440
#define T_SERVER 441
#define T_SERVNOTICE 442
#define T_SET 443
#define T_SKILL 444
#define T_SPY 445
#define T_SSL 446
#define T_UMODES 447
#define T_UNAUTH 448
#define T_UNDLINE 449
#define T_UNLIMITED 450
#define T_UNRESV 451
#define T_UNXLINE 452
#define T_GLOBOPS 453
#define T_WALLOP 454
#define T_RESTART 455
#define T_SERVICE 456
#define T_SERVICES_NAME 457
#define THROTTLE_TIME 458
#define TRUE_NO_OPER_FLOOD 459
#define UNKLINE 460
#define USER 461
#define USE_EGD 462
#define USE_LOGGING 463
#define VHOST 464
#define VHOST6 465
#define XLINE 466
#define WARN_NO_NLINE 467
#define T_SIZE 468
#define T_FILE 469



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 374 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;


/* Line 374 of yacc.c  */
#line 630 "conf_parser.c"
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

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 377 of yacc.c  */
#line 658 "conf_parser.c"

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
#define YYLAST   1206

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  220
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  283
/* YYNRULES -- Number of rules.  */
#define YYNRULES  627
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1228

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   469

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   219,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   215,
       2,   218,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   217,     2,   216,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214
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
    1386,  1388,  1390,  1392,  1397,  1402,  1407,  1412,  1417,  1422,
    1427,  1432,  1437,  1442,  1447,  1452,  1457,  1462,  1467,  1472,
    1477,  1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,
    1527,  1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,
    1577,  1582,  1587,  1592,  1597,  1602,  1607,  1612,  1617,  1622,
    1623,  1629,  1633,  1635,  1637,  1639,  1641,  1643,  1645,  1647,
    1649,  1651,  1653,  1655,  1657,  1659,  1661,  1663,  1665,  1667,
    1669,  1671,  1673,  1675,  1676,  1682,  1686,  1688,  1690,  1692,
    1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,  1710,  1712,
    1714,  1716,  1718,  1720,  1722,  1724,  1726,  1728,  1733,  1738,
    1743,  1749,  1752,  1754,  1756,  1758,  1760,  1762,  1764,  1766,
    1768,  1770,  1772,  1774,  1776,  1778,  1780,  1782,  1784,  1789,
    1794,  1799,  1804,  1809,  1814,  1819,  1824,  1829,  1834,  1839,
    1844,  1849,  1854,  1860,  1863,  1865,  1867,  1869,  1871,  1873,
    1875,  1877,  1879,  1884,  1889,  1894,  1899,  1904
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     221,     0,    -1,    -1,   221,   222,    -1,   254,    -1,   260,
      -1,   274,    -1,   477,    -1,   292,    -1,   310,    -1,   324,
      -1,   232,    -1,   494,    -1,   339,    -1,   346,    -1,   350,
      -1,   360,    -1,   369,    -1,   389,    -1,   399,    -1,   405,
      -1,   419,    -1,   409,    -1,   227,    -1,     1,   215,    -1,
       1,   216,    -1,    -1,   224,    -1,    99,   223,    -1,    99,
     138,   223,    -1,    99,   139,   223,    -1,    99,   140,   223,
      -1,    99,   141,   223,    -1,    99,   142,   223,    -1,    -1,
     226,    -1,    99,   225,    -1,    99,     9,   225,    -1,    99,
      10,   225,    -1,    99,    11,   225,    -1,    88,   217,   228,
     216,   215,    -1,   228,   229,    -1,   229,    -1,   230,    -1,
     231,    -1,     1,   215,    -1,    87,   218,   118,   215,    -1,
     113,   218,   118,   215,    -1,   146,   217,   233,   216,   215,
      -1,   233,   234,    -1,   234,    -1,   245,    -1,   250,    -1,
     253,    -1,   247,    -1,   248,    -1,   249,    -1,   252,    -1,
     243,    -1,   242,    -1,   251,    -1,   246,    -1,   241,    -1,
     235,    -1,   236,    -1,   244,    -1,     1,   215,    -1,   132,
     218,   237,   215,    -1,   133,   218,   239,   215,    -1,   237,
     219,   238,    -1,   238,    -1,   134,    -1,   135,    -1,   239,
     219,   240,    -1,   240,    -1,   134,    -1,   135,    -1,   130,
     218,   118,   215,    -1,   128,   218,   118,   215,    -1,   131,
     218,   118,   215,    -1,   171,   218,   118,   215,    -1,    89,
     218,   118,   215,    -1,   147,   218,   118,   215,    -1,    24,
     218,   118,   215,    -1,    92,   218,   118,   215,    -1,    91,
     218,   118,   215,    -1,   209,   218,   118,   215,    -1,   210,
     218,   118,   215,    -1,   181,   218,    99,   215,    -1,    57,
     218,   160,   215,    -1,     4,   217,   255,   216,   215,    -1,
     255,   256,    -1,   256,    -1,   257,    -1,   259,    -1,   258,
      -1,     1,   215,    -1,    89,   218,   118,   215,    -1,    31,
     218,   118,   215,    -1,    24,   218,   118,   215,    -1,    71,
     217,   261,   216,   215,    -1,   261,   262,    -1,   262,    -1,
     263,    -1,   264,    -1,     1,   215,    -1,   208,   218,   160,
     215,    -1,    -1,   265,   214,   217,   266,   216,   215,    -1,
     266,   267,    -1,   267,    -1,   268,    -1,   270,    -1,   269,
      -1,     1,   215,    -1,    89,   218,   118,   215,    -1,   213,
     218,   226,   215,    -1,   213,   218,   195,   215,    -1,    -1,
     151,   271,   218,   272,   215,    -1,   272,   219,   273,    -1,
     273,    -1,   206,    -1,   102,    -1,    40,    -1,   174,    -1,
      64,    -1,    62,    -1,   173,    -1,    -1,   102,   275,   217,
     276,   216,   215,    -1,   276,   277,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   284,    -1,   283,    -1,   281,
      -1,   282,    -1,   288,    -1,     1,   215,    -1,    89,   218,
     118,   215,    -1,   206,   218,   118,   215,    -1,   112,   218,
     118,   215,    -1,    32,   218,   160,   215,    -1,   129,   218,
     118,   215,    -1,    17,   218,   118,   215,    -1,    -1,   192,
     285,   218,   286,   215,    -1,   286,   219,   287,    -1,   287,
      -1,   166,    -1,   169,    -1,   170,    -1,   172,    -1,   173,
      -1,   176,    -1,    51,    -1,   189,    -1,   182,    -1,   185,
      -1,   193,    -1,   190,    -1,   175,    -1,   183,    -1,   187,
      -1,   177,    -1,   199,    -1,   167,    -1,   168,    -1,   180,
      -1,    -1,    36,   289,   218,   290,   215,    -1,   290,   219,
     291,    -1,   291,    -1,    47,    -1,   125,    -1,    64,    -1,
     205,    -1,   174,    -1,   194,    -1,   211,    -1,    40,    -1,
      25,    -1,   200,    -1,   124,    -1,     4,    -1,    94,    -1,
     183,    -1,   198,    -1,   106,    -1,   126,    -1,   188,    -1,
      87,    -1,    -1,    17,   293,   217,   294,   216,   215,    -1,
     294,   295,    -1,   295,    -1,   296,    -1,   307,    -1,   308,
      -1,   297,    -1,   298,    -1,   309,    -1,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,   303,    -1,   304,    -1,   305,
      -1,   306,    -1,     1,   215,    -1,    89,   218,   118,   215,
      -1,   115,   218,   224,   215,    -1,   116,   218,   224,   215,
      -1,   101,   218,    99,   215,    -1,    19,   218,   224,   215,
      -1,    81,   218,    99,   215,    -1,    76,   218,    99,   215,
      -1,    78,   218,    99,   215,    -1,    77,   218,    99,   215,
      -1,   143,   218,   226,   215,    -1,   184,   218,   226,   215,
      -1,    15,   218,    99,   215,    -1,    16,   218,    99,   215,
      -1,   100,   218,    99,   215,    -1,    -1,    70,   311,   217,
     316,   216,   215,    -1,    -1,    36,   313,   218,   314,   215,
      -1,   314,   219,   315,    -1,   315,    -1,   191,    -1,    51,
      -1,   186,    -1,   316,   317,    -1,   317,    -1,   318,    -1,
     312,    -1,   322,    -1,   323,    -1,     1,   215,    -1,    -1,
     117,   218,   320,   319,   215,    -1,   320,   219,   321,    -1,
     321,    -1,    99,    -1,    99,   164,    99,    -1,    61,   218,
     118,   215,    -1,    56,   218,   118,   215,    -1,    -1,    48,
     325,   217,   326,   216,   215,    -1,   326,   327,    -1,   327,
      -1,   328,    -1,   329,    -1,   330,    -1,   332,    -1,   336,
      -1,   337,    -1,   338,    -1,   331,    -1,     1,   215,    -1,
     206,   218,   118,   215,    -1,   112,   218,   118,   215,    -1,
      17,   218,   118,   215,    -1,    32,   218,   160,   215,    -1,
      -1,    36,   333,   218,   334,   215,    -1,   334,   219,   335,
      -1,   335,    -1,   154,    -1,    33,    -1,    65,    -1,    49,
      -1,    13,    -1,    98,    -1,    43,    -1,   137,    -1,    90,
      -1,   153,   218,   118,   215,    -1,   122,   218,   118,   215,
      -1,   121,   218,    99,   215,    -1,    -1,   136,   340,   217,
     341,   216,   215,    -1,   341,   342,    -1,   342,    -1,   343,
      -1,   344,    -1,   345,    -1,     1,   215,    -1,   120,   218,
     118,   215,    -1,    14,   218,   118,   215,    -1,    93,   218,
     118,   215,    -1,   201,   217,   347,   216,   215,    -1,   347,
     348,    -1,   348,    -1,   349,    -1,     1,    -1,    89,   218,
     118,   215,    -1,    -1,   149,   351,   217,   352,   216,   215,
      -1,   352,   353,    -1,   353,    -1,   354,    -1,   355,    -1,
     356,    -1,     1,   215,    -1,    89,   218,   118,   215,    -1,
     206,   218,   118,   215,    -1,    -1,   151,   357,   218,   358,
     215,    -1,   358,   219,   359,    -1,   359,    -1,    64,    -1,
     205,    -1,   174,    -1,   194,    -1,   211,    -1,   197,    -1,
     136,    -1,   196,    -1,   180,    -1,   165,    -1,    -1,   150,
     361,   217,   362,   216,   215,    -1,   362,   363,    -1,   363,
      -1,   364,    -1,   365,    -1,     1,   215,    -1,    89,   218,
     118,   215,    -1,    -1,   151,   366,   218,   367,   215,    -1,
     367,   219,   368,    -1,   368,    -1,    64,    -1,   205,    -1,
     174,    -1,   194,    -1,   211,    -1,   197,    -1,   136,    -1,
     196,    -1,   180,    -1,   165,    -1,    -1,    18,   370,   217,
     371,   216,   215,    -1,   371,   372,    -1,   372,    -1,   373,
      -1,   374,    -1,   375,    -1,   376,    -1,   377,    -1,   379,
      -1,   378,    -1,   388,    -1,   380,    -1,   385,    -1,   386,
      -1,   387,    -1,   384,    -1,     1,   215,    -1,    89,   218,
     118,   215,    -1,    56,   218,   118,   215,    -1,   209,   218,
     118,   215,    -1,   144,   218,   118,   215,    -1,     3,   218,
     118,   215,    -1,   117,   218,    99,   215,    -1,     5,   218,
     178,   215,    -1,     5,   218,   179,   215,    -1,    -1,    36,
     381,   218,   382,   215,    -1,   382,   219,   383,    -1,   383,
      -1,     8,    -1,   191,    -1,    32,   218,   160,   215,    -1,
      58,   218,   118,   215,    -1,    68,   218,   118,   215,    -1,
      17,   218,   118,   215,    -1,   171,   218,   118,   215,    -1,
      -1,    62,   390,   217,   395,   216,   215,    -1,    -1,   151,
     392,   218,   393,   215,    -1,   393,   219,   394,    -1,   394,
      -1,   123,    -1,   395,   396,    -1,   396,    -1,   397,    -1,
     398,    -1,   391,    -1,     1,    -1,   206,   218,   118,   215,
      -1,   120,   218,   118,   215,    -1,    -1,    23,   400,   217,
     401,   216,   215,    -1,   401,   402,    -1,   402,    -1,   403,
      -1,   404,    -1,     1,    -1,    61,   218,   118,   215,    -1,
     120,   218,   118,   215,    -1,    34,   217,   406,   216,   215,
      -1,   406,   407,    -1,   407,    -1,   408,    -1,     1,    -1,
      61,   218,   118,   215,    -1,    -1,    38,   410,   217,   415,
     216,   215,    -1,    -1,   151,   412,   218,   413,   215,    -1,
     413,   219,   414,    -1,   414,    -1,   123,    -1,   415,   416,
      -1,   416,    -1,   417,    -1,   418,    -1,   411,    -1,     1,
      -1,    89,   218,   118,   215,    -1,   120,   218,   118,   215,
      -1,    39,   217,   420,   216,   215,    -1,   420,   421,    -1,
     421,    -1,   430,    -1,   431,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,   438,    -1,   439,    -1,
     440,    -1,   429,    -1,   442,    -1,   443,    -1,   458,    -1,
     445,    -1,   447,    -1,   449,    -1,   448,    -1,   452,    -1,
     446,    -1,   453,    -1,   454,    -1,   455,    -1,   456,    -1,
     457,    -1,   470,    -1,   459,    -1,   460,    -1,   461,    -1,
     466,    -1,   450,    -1,   451,    -1,   476,    -1,   474,    -1,
     475,    -1,   432,    -1,   465,    -1,   441,    -1,   463,    -1,
     464,    -1,   428,    -1,   423,    -1,   424,    -1,   425,    -1,
     426,    -1,   427,    -1,   444,    -1,   422,    -1,   462,    -1,
       1,    -1,    83,   218,    99,   215,    -1,    42,   218,   160,
     215,    -1,    41,   218,   224,   215,    -1,    44,   218,   224,
     215,    -1,    45,   218,    99,   215,    -1,    46,   218,    99,
     215,    -1,   148,   218,   160,   215,    -1,    63,   218,   224,
     215,    -1,    55,   218,   160,   215,    -1,    59,   218,   160,
     215,    -1,    28,   218,   160,   215,    -1,    35,   218,   160,
     215,    -1,     6,   218,   160,   215,    -1,    80,   218,   224,
     215,    -1,    79,   218,    99,   215,    -1,    72,   218,    99,
     215,    -1,     7,   218,   224,   215,    -1,   163,   218,   224,
     215,    -1,   162,   218,   224,   215,    -1,    50,   218,    99,
     215,    -1,    60,   218,   160,   215,    -1,   212,   218,   160,
     215,    -1,   155,   218,   160,   215,    -1,   158,   218,   160,
     215,    -1,   159,   218,   160,   215,    -1,   157,   218,   160,
     215,    -1,   157,   218,   161,   215,    -1,   156,   218,   160,
     215,    -1,   156,   218,   161,   215,    -1,   110,   218,   224,
     215,    -1,    12,   218,   224,   215,    -1,   103,   218,   160,
     215,    -1,   111,   218,   224,   215,    -1,   152,   218,   160,
     215,    -1,    97,   218,   160,   215,    -1,   204,   218,   160,
     215,    -1,   105,   218,   160,   215,    -1,    84,   218,   118,
     215,    -1,    29,   218,    99,   215,    -1,    82,   218,    99,
     215,    -1,   207,   218,   160,   215,    -1,    30,   218,   118,
     215,    -1,   202,   218,   118,   215,    -1,   114,   218,   160,
     215,    -1,    26,   218,   160,   215,    -1,   203,   218,   224,
     215,    -1,    -1,   107,   467,   218,   468,   215,    -1,   468,
     219,   469,    -1,   469,    -1,   166,    -1,   169,    -1,   170,
      -1,   172,    -1,   173,    -1,   176,    -1,    51,    -1,   189,
      -1,   182,    -1,   185,    -1,   193,    -1,   190,    -1,   175,
      -1,   183,    -1,   187,    -1,   177,    -1,   199,    -1,   167,
      -1,   168,    -1,   180,    -1,    -1,   104,   471,   218,   472,
     215,    -1,   472,   219,   473,    -1,   473,    -1,   166,    -1,
     169,    -1,   170,    -1,   172,    -1,   173,    -1,   176,    -1,
     189,    -1,    51,    -1,   182,    -1,   185,    -1,   193,    -1,
     190,    -1,   175,    -1,   183,    -1,   187,    -1,   177,    -1,
     199,    -1,   167,    -1,   168,    -1,   180,    -1,    85,   218,
      99,   215,    -1,    86,   218,    99,   215,    -1,    20,   218,
      99,   215,    -1,    14,   217,   478,   216,   215,    -1,   478,
     479,    -1,   479,    -1,   487,    -1,   482,    -1,   483,    -1,
     484,    -1,   485,    -1,   486,    -1,   488,    -1,   489,    -1,
     490,    -1,   481,    -1,   491,    -1,   492,    -1,   493,    -1,
     480,    -1,     1,    -1,    27,   218,   160,   215,    -1,   127,
     218,   160,   215,    -1,    66,   218,   224,   215,    -1,    67,
     218,   224,   215,    -1,    75,   218,    99,   215,    -1,    74,
     218,    99,   215,    -1,   119,   218,   160,   215,    -1,    73,
     218,    99,   215,    -1,    22,   218,    99,   215,    -1,    21,
     218,    99,   215,    -1,    95,   218,   160,   215,    -1,    96,
     218,   160,   215,    -1,   108,   218,    99,   215,    -1,   109,
     218,   224,   215,    -1,   145,   217,   495,   216,   215,    -1,
     495,   496,    -1,   496,    -1,   497,    -1,   498,    -1,   500,
      -1,   501,    -1,   499,    -1,   502,    -1,     1,    -1,    37,
     218,   160,   215,    -1,    54,   218,   160,   215,    -1,    52,
     218,   118,   215,    -1,    69,   218,   224,   215,    -1,    51,
     218,   160,   215,    -1,    53,   218,   160,   215,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   330,   330,   331,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   359,   359,   360,   364,
     368,   372,   376,   380,   386,   386,   387,   388,   389,   390,
     397,   400,   400,   401,   401,   401,   403,   409,   416,   418,
     418,   419,   419,   420,   420,   421,   421,   422,   422,   423,
     423,   424,   424,   425,   425,   426,   427,   430,   431,   433,
     433,   434,   440,   448,   448,   449,   455,   463,   502,   561,
     589,   597,   612,   627,   636,   650,   659,   687,   717,   740,
     749,   751,   751,   752,   752,   753,   753,   755,   764,   773,
     785,   786,   786,   788,   788,   789,   791,   798,   798,   808,
     809,   811,   811,   812,   812,   814,   819,   822,   828,   827,
     833,   833,   834,   838,   842,   846,   850,   854,   858,   869,
     868,   966,   966,   967,   967,   967,   968,   968,   968,   969,
     969,   969,   971,   980,  1017,  1029,  1040,  1082,  1092,  1091,
    1097,  1097,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,
    1130,  1134,  1138,  1142,  1146,  1150,  1154,  1158,  1162,  1166,
    1170,  1174,  1181,  1180,  1186,  1186,  1187,  1191,  1195,  1199,
    1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,
    1243,  1247,  1251,  1255,  1259,  1270,  1269,  1319,  1319,  1320,
    1321,  1321,  1322,  1323,  1324,  1325,  1326,  1327,  1328,  1329,
    1330,  1331,  1331,  1332,  1334,  1343,  1349,  1355,  1361,  1367,
    1373,  1379,  1385,  1391,  1397,  1404,  1410,  1416,  1426,  1425,
    1442,  1441,  1446,  1446,  1447,  1451,  1455,  1463,  1463,  1464,
    1464,  1464,  1464,  1464,  1466,  1466,  1468,  1468,  1470,  1484,
    1504,  1513,  1526,  1525,  1594,  1594,  1595,  1595,  1595,  1595,
    1596,  1596,  1596,  1597,  1597,  1599,  1634,  1647,  1656,  1668,
    1667,  1671,  1671,  1672,  1676,  1680,  1684,  1688,  1692,  1696,
    1700,  1704,  1710,  1729,  1739,  1753,  1752,  1768,  1768,  1769,
    1769,  1769,  1769,  1771,  1780,  1795,  1808,  1810,  1810,  1811,
    1811,  1813,  1829,  1828,  1844,  1844,  1845,  1845,  1845,  1845,
    1847,  1856,  1879,  1878,  1884,  1884,  1885,  1889,  1893,  1897,
    1901,  1905,  1909,  1913,  1917,  1921,  1931,  1930,  1947,  1947,
    1948,  1948,  1948,  1950,  1957,  1956,  1962,  1962,  1963,  1967,
    1971,  1975,  1979,  1983,  1987,  1991,  1995,  1999,  2009,  2008,
    2059,  2059,  2060,  2060,  2060,  2061,  2061,  2062,  2062,  2062,
    2063,  2063,  2063,  2064,  2064,  2065,  2067,  2076,  2085,  2111,
    2129,  2147,  2153,  2157,  2166,  2165,  2169,  2169,  2170,  2174,
    2180,  2191,  2202,  2213,  2222,  2241,  2240,  2304,  2303,  2307,
    2307,  2308,  2314,  2314,  2315,  2315,  2315,  2315,  2317,  2336,
    2346,  2345,  2368,  2368,  2369,  2369,  2369,  2371,  2377,  2386,
    2388,  2388,  2389,  2389,  2391,  2410,  2409,  2457,  2456,  2460,
    2460,  2461,  2467,  2467,  2468,  2468,  2468,  2468,  2470,  2476,
    2485,  2488,  2488,  2489,  2489,  2490,  2490,  2491,  2491,  2492,
    2492,  2493,  2493,  2494,  2495,  2496,  2496,  2497,  2497,  2498,
    2498,  2499,  2499,  2500,  2500,  2501,  2501,  2502,  2503,  2503,
    2504,  2504,  2505,  2505,  2506,  2506,  2507,  2507,  2508,  2509,
    2509,  2510,  2511,  2512,  2512,  2513,  2513,  2514,  2515,  2516,
    2517,  2517,  2518,  2521,  2526,  2532,  2538,  2544,  2549,  2554,
    2559,  2564,  2569,  2574,  2579,  2584,  2589,  2594,  2599,  2604,
    2609,  2614,  2620,  2631,  2636,  2641,  2646,  2651,  2656,  2659,
    2664,  2667,  2672,  2677,  2682,  2687,  2692,  2697,  2702,  2707,
    2712,  2723,  2728,  2733,  2738,  2747,  2756,  2761,  2766,  2772,
    2771,  2776,  2776,  2777,  2780,  2783,  2786,  2789,  2792,  2795,
    2798,  2801,  2804,  2807,  2810,  2813,  2816,  2819,  2822,  2825,
    2828,  2831,  2834,  2840,  2839,  2844,  2844,  2845,  2848,  2851,
    2854,  2857,  2860,  2863,  2866,  2869,  2872,  2875,  2878,  2881,
    2884,  2887,  2890,  2893,  2896,  2899,  2902,  2907,  2912,  2917,
    2926,  2929,  2929,  2930,  2931,  2931,  2932,  2932,  2933,  2933,
    2934,  2935,  2935,  2936,  2937,  2937,  2938,  2938,  2940,  2945,
    2950,  2955,  2960,  2965,  2970,  2975,  2980,  2985,  2990,  2995,
    3000,  3005,  3013,  3016,  3016,  3017,  3017,  3018,  3019,  3019,
    3020,  3021,  3023,  3029,  3035,  3044,  3058,  3064
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
  "KNOCK_DELAY", "KNOCK_DELAY_CHANNEL", "LEAF_MASK", "LINKS_DELAY",
  "LISTEN", "T_LOG", "MAX_ACCEPT", "MAX_BANS", "MAX_CHANS_PER_OPER",
  "MAX_CHANS_PER_USER", "MAX_GLOBAL", "MAX_IDENT", "MAX_LOCAL",
  "MAX_NICK_CHANGES", "MAX_NICK_TIME", "MAX_NUMBER", "MAX_TARGETS",
  "MAX_WATCH", "MESSAGE_LOCALE", "MIN_NONWILDCARD",
  "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME", "NEED_PASSWORD",
  "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
  "NO_CREATE_ON_SPLIT", "NO_JOIN_ON_SPLIT", "NO_OPER_FLOOD", "NO_TILDE",
  "NUMBER", "NUMBER_PER_CIDR", "NUMBER_PER_IP", "OPERATOR",
  "OPERS_BYPASS_CALLERID", "OPER_ONLY_UMODES", "OPER_PASS_RESV",
  "OPER_SPY_T", "OPER_UMODES", "JOIN_FLOOD_COUNT", "JOIN_FLOOD_TIME",
  "PACE_WAIT", "PACE_WAIT_SIMPLE", "PASSWORD", "PATH", "PING_COOKIE",
  "PING_TIME", "PING_WARNING", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON",
  "REDIRPORT", "REDIRSERV", "REGEX_T", "REHASH", "REMOTE", "REMOTEBAN",
  "RESTRICT_CHANNELS", "RSA_PRIVATE_KEY_FILE", "RSA_PUBLIC_KEY_FILE",
  "SSL_CERTIFICATE_FILE", "SSL_DH_PARAM_FILE", "T_SSL_CLIENT_METHOD",
  "T_SSL_SERVER_METHOD", "T_SSLV3", "T_TLSV1", "RESV", "RESV_EXEMPT",
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "SENDQ", "SEND_PASSWORD",
  "SERVERHIDE", "SERVERINFO", "IRCD_SID", "TKLINE_EXPIRE_NOTICES",
  "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD", "SPOOF", "SPOOF_NOTICE",
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
  "USE_LOGGING", "VHOST", "VHOST6", "XLINE", "WARN_NO_NLINE", "T_SIZE",
  "T_FILE", "';'", "'}'", "'{'", "'='", "','", "$accept", "conf",
  "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
  "modules_entry", "modules_items", "modules_item", "modules_module",
  "modules_path", "serverinfo_entry", "serverinfo_items",
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
  "general_gline_min_cidr6", "general_tkline_expire_notices",
  "general_kill_chase_time_limit", "general_hide_spoof_ips",
  "general_ignore_bogus_ts", "general_disable_remote_commands",
  "general_failed_oper_notice", "general_anti_nick_flood",
  "general_max_nick_time", "general_max_nick_changes",
  "general_max_accept", "general_anti_spam_exit_message_time",
  "general_ts_warn_delta", "general_ts_max_delta",
  "general_havent_read_conf", "general_invisible_on_connect",
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
     465,   466,   467,   468,   469,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   220,   221,   221,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   222,   222,   222,   222,
     222,   222,   222,   222,   222,   222,   223,   223,   224,   224,
     224,   224,   224,   224,   225,   225,   226,   226,   226,   226,
     227,   228,   228,   229,   229,   229,   230,   231,   232,   233,
     233,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   235,   236,   237,
     237,   238,   238,   239,   239,   240,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   255,   256,   256,   256,   256,   257,   258,   259,
     260,   261,   261,   262,   262,   262,   263,   265,   264,   266,
     266,   267,   267,   267,   267,   268,   269,   269,   271,   270,
     272,   272,   273,   273,   273,   273,   273,   273,   273,   275,
     274,   276,   276,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   278,   279,   280,   281,   282,   283,   285,   284,
     286,   286,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   289,   288,   290,   290,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   293,   292,   294,   294,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   311,   310,
     313,   312,   314,   314,   315,   315,   315,   316,   316,   317,
     317,   317,   317,   317,   319,   318,   320,   320,   321,   321,
     322,   323,   325,   324,   326,   326,   327,   327,   327,   327,
     327,   327,   327,   327,   327,   328,   329,   330,   331,   333,
     332,   334,   334,   335,   335,   335,   335,   335,   335,   335,
     335,   335,   336,   337,   338,   340,   339,   341,   341,   342,
     342,   342,   342,   343,   344,   345,   346,   347,   347,   348,
     348,   349,   351,   350,   352,   352,   353,   353,   353,   353,
     354,   355,   357,   356,   358,   358,   359,   359,   359,   359,
     359,   359,   359,   359,   359,   359,   361,   360,   362,   362,
     363,   363,   363,   364,   366,   365,   367,   367,   368,   368,
     368,   368,   368,   368,   368,   368,   368,   368,   370,   369,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   372,   372,   372,   372,   373,   374,   375,   376,
     377,   378,   379,   379,   381,   380,   382,   382,   383,   383,
     384,   385,   386,   387,   388,   390,   389,   392,   391,   393,
     393,   394,   395,   395,   396,   396,   396,   396,   397,   398,
     400,   399,   401,   401,   402,   402,   402,   403,   404,   405,
     406,   406,   407,   407,   408,   410,   409,   412,   411,   413,
     413,   414,   415,   415,   416,   416,   416,   416,   417,   418,
     419,   420,   420,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   421,   421,   421,   421,   421,   421,   421,
     421,   421,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   447,
     448,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   467,
     466,   468,   468,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   471,   470,   472,   472,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   474,   475,   476,
     477,   478,   478,   479,   479,   479,   479,   479,   479,   479,
     479,   479,   479,   479,   479,   479,   479,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   495,   496,   496,   496,   496,   496,
     496,   496,   497,   498,   499,   500,   501,   502
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
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
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
       2,     0,     1,     0,     0,     0,   195,   348,   400,     0,
     415,     0,   252,   385,   228,     0,     0,   129,   285,     0,
       0,   302,   326,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   597,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   582,   596,   592,   584,   585,   586,   587,   588,
     583,   589,   590,   591,   593,   594,   595,     0,     0,     0,
     413,     0,     0,   411,   412,     0,   482,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   553,     0,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   432,   480,   474,
     475,   476,   477,   478,   473,   443,   433,   434,   468,   435,
     436,   437,   438,   439,   440,   441,   442,   470,   444,   445,
     479,   447,   452,   448,   450,   449,   463,   464,   451,   453,
     454,   455,   456,   457,   446,   459,   460,   461,   481,   471,
     472,   469,   462,   458,   466,   467,   465,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   621,     0,     0,     0,
       0,     0,     0,     0,   614,   615,   616,   619,   617,   618,
     620,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   300,     0,     0,   298,
     299,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   581,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   198,
     199,   202,   203,   205,   206,   207,   208,   209,   210,   211,
     212,   200,   201,   204,     0,     0,     0,     0,     0,   374,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   351,
     352,   353,   354,   355,   356,   358,   357,   360,   364,   361,
     362,   363,   359,   406,     0,     0,     0,   403,   404,   405,
       0,     0,   410,   427,     0,     0,   417,   426,     0,   423,
     424,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   431,     0,     0,     0,   269,     0,     0,     0,
       0,     0,     0,   255,   256,   257,   258,   263,   259,   260,
     261,   262,   397,     0,   387,     0,   396,     0,   393,   394,
     395,     0,   230,     0,     0,     0,   240,     0,   238,   239,
     241,   242,   105,     0,     0,   101,     0,    45,     0,     0,
       0,    41,     0,     0,     0,   172,     0,     0,     0,   148,
       0,     0,   132,   133,   134,   135,   138,   139,   137,   136,
     140,     0,     0,     0,     0,     0,   288,   289,   290,   291,
       0,     0,     0,     0,     0,     0,     0,   613,    66,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,   312,     0,
       0,   305,   306,   307,   308,     0,     0,   334,     0,   329,
     330,   331,     0,     0,   297,     0,     0,     0,    90,     0,
       0,     0,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   580,   213,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,   365,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   350,     0,     0,
       0,   402,     0,   409,     0,     0,     0,     0,   422,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,   264,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   254,     0,     0,     0,     0,   392,   243,     0,     0,
       0,     0,     0,   237,     0,   100,     0,     0,     0,    40,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     131,   292,     0,     0,     0,     0,   287,     0,     0,     0,
       0,     0,     0,   612,     0,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,    70,    75,    76,     0,    74,
       0,     0,     0,     0,     0,    48,   309,     0,     0,     0,
       0,   304,   332,     0,     0,     0,   328,     0,   296,    99,
      98,    97,   607,   606,   598,    26,    26,    26,    26,    26,
      28,    27,   600,   601,   605,   603,   602,   608,   609,   610,
     611,   604,   599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,   196,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   349,     0,     0,   401,   414,     0,     0,
       0,   416,   495,   499,   513,   579,   527,   493,   521,   524,
     494,   485,   484,   486,   487,   488,   502,   491,   492,   503,
     490,   498,   497,   496,   522,   483,   520,   577,   578,   517,
     514,   564,   557,   574,   575,   558,   559,   560,   561,   569,
     562,   572,   576,   565,   570,   566,   571,   563,   568,   567,
     573,     0,   556,   519,   539,   533,   550,   551,   534,   535,
     536,   537,   545,   538,   548,   552,   541,   546,   542,   547,
     540,   544,   543,   549,     0,   532,   512,   515,   526,   489,
     516,   505,   510,   511,   508,   509,   506,   507,   501,   500,
     525,   528,   518,   523,   504,     0,     0,     0,     0,     0,
       0,     0,     0,   253,     0,     0,     0,   386,     0,     0,
       0,   248,   244,   247,   229,   106,     0,     0,   118,     0,
       0,   110,   111,   113,   112,    46,    47,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   286,
     622,   626,   624,   627,   623,   625,    83,    89,    81,    85,
      84,    78,    77,    79,    67,     0,    68,     0,    82,    80,
      88,    86,    87,     0,     0,     0,   303,     0,     0,   327,
     301,    29,    30,    31,    32,    33,   225,   226,   218,   220,
     222,   221,   219,   214,   227,   217,   215,   216,    34,    34,
      34,    36,    35,   223,   224,   370,   372,   373,   383,   380,
     378,   379,     0,   377,   367,   381,   382,   366,   371,   369,
     384,   368,   407,   408,   428,   429,   421,     0,   420,   554,
       0,   530,     0,   267,   268,   277,   274,   279,   276,   275,
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
     555,   531,   270,     0,   388,     0,   231,     0,   249,   246,
     245,     0,     0,     0,     0,   108,   173,     0,   149,     0,
     313,     0,   335,     0,   376,   419,   271,   389,   232,   115,
     124,   127,   126,   123,   128,   125,   122,     0,   121,   117,
     116,   174,   150,   314,   336,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   780,   781,  1021,  1022,    25,   230,   231,
     232,   233,    26,   267,   268,   269,   270,   744,   745,   748,
     749,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,    27,    71,    72,    73,    74,    75,
      28,   222,   223,   224,   225,   226,   950,   951,   952,   953,
     954,  1088,  1217,  1218,    29,    60,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   717,  1138,  1139,   510,   713,
    1113,  1114,    30,    49,   328,   329,   330,   331,   332,   333,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
      31,    57,   476,   698,  1079,  1080,   477,   478,   479,  1085,
     942,   943,   480,   481,    32,    55,   452,   453,   454,   455,
     456,   457,   458,   684,  1064,  1065,   459,   460,   461,    33,
      61,   515,   516,   517,   518,   519,    34,   288,   289,   290,
      35,    64,   550,   551,   552,   553,   554,   758,  1157,  1158,
      36,    65,   558,   559,   560,   561,   764,  1171,  1172,    37,
      50,   358,   359,   360,   361,   362,   363,   364,   365,   366,
     367,   607,  1032,  1033,   368,   369,   370,   371,   372,    38,
      56,   466,   693,  1073,  1074,   467,   468,   469,   470,    39,
      51,   376,   377,   378,   379,    40,   112,   113,   114,    41,
      53,   387,   626,  1047,  1048,   388,   389,   390,   391,    42,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   423,   904,   905,
     213,   421,   881,   882,   214,   215,   216,    43,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,    44,   243,   244,   245,   246,   247,
     248,   249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -744
static const yytype_int16 yypact[] =
{
    -744,   610,  -744,  -209,  -187,  -179,  -744,  -744,  -744,  -176,
    -744,  -171,  -744,  -744,  -744,  -166,  -164,  -744,  -744,  -139,
    -136,  -744,  -744,  -131,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,    61,   807,  -126,
    -104,   -84,    16,   -79,   382,   -77,   -63,   -60,     7,    21,
     -49,   -40,   638,   381,   -26,    52,    25,  -152,    62,    85,
      86,    18,  -744,  -744,  -744,  -744,  -744,    88,    89,    93,
      94,    96,   101,   108,   112,   118,   119,   125,   127,   132,
     133,   162,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,   531,   499,   266,
    -744,   135,    28,  -744,  -744,    11,  -744,   142,   143,   145,
     147,   148,   150,   153,   163,   166,   167,   169,   173,   174,
     175,   177,   178,   180,   182,   183,   185,   191,   197,   200,
     201,   202,   204,   211,   212,   215,  -744,   216,  -744,   217,
     218,   221,   222,   225,   226,   229,   234,   235,   237,   238,
     239,   242,   253,   256,   257,   262,    38,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,   337,    24,   259,
      73,   263,     4,  -744,  -744,  -744,   126,   131,   264,   270,
      59,  -744,  -744,  -744,   389,   209,  -744,   276,   279,   280,
     281,   285,   287,     3,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,   149,   288,   289,   290,   292,   299,   301,   302,   303,
     304,   305,   307,   308,   315,   324,   330,    75,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   208,    30,  -744,   331,    15,  -744,
    -744,  -744,   107,   254,   359,   165,  -744,   385,   396,   367,
     454,   454,   455,   457,   461,   399,   401,   464,   454,   404,
     405,   351,  -744,   358,   356,   360,   361,   362,   364,   365,
     369,   374,   375,   379,   383,   386,   388,   395,   232,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   384,   397,   400,   403,   408,  -744,
     411,   412,   420,   423,   424,   427,   433,   434,   260,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   435,   437,     8,  -744,  -744,  -744,
     458,   407,  -744,  -744,   441,   442,  -744,  -744,    36,  -744,
    -744,  -744,   417,   454,   454,   501,   443,   459,   524,   543,
     502,   454,   503,   454,   565,   567,   568,   508,   509,   513,
     454,   577,   578,   454,   580,   583,   566,   584,   587,   527,
     528,   475,   535,   478,   454,   454,   537,   540,   541,   542,
    -146,  -133,   544,   546,   454,   454,   585,   454,   550,   553,
     554,   510,  -744,   515,   514,   517,  -744,   519,   521,   525,
     529,   530,    58,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,   533,  -744,   534,  -744,    10,  -744,  -744,
    -744,   538,  -744,   536,   539,   545,  -744,   115,  -744,  -744,
    -744,  -744,  -744,   582,   547,  -744,   532,  -744,   640,   643,
     549,  -744,   555,   559,   560,  -744,   562,   569,   572,  -744,
     573,    70,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,   558,   588,   595,   597,   146,  -744,  -744,  -744,  -744,
     623,   625,   687,   658,   659,   454,   606,  -744,  -744,   704,
     663,   706,   707,   709,   713,   714,   715,    79,   159,   717,
     718,   646,   719,   720,   626,  -744,   628,   622,  -744,   624,
     128,  -744,  -744,  -744,  -744,   629,   630,  -744,    22,  -744,
    -744,  -744,   728,   632,  -744,   634,   635,   636,  -744,   637,
     639,   641,   430,   642,   645,   648,   649,   650,   651,   652,
     653,   654,   656,   657,  -744,  -744,   754,   756,   454,   759,
     776,   778,   779,   761,   784,   785,   454,   454,   786,   786,
     671,  -744,  -744,   769,   122,   770,   729,   672,   773,   774,
     775,   777,   795,   780,   781,   782,   681,  -744,   783,   787,
     682,  -744,   689,  -744,   788,   789,   690,   694,  -744,   695,
     696,   697,   698,   699,   702,   703,   705,   708,   710,   712,
     716,   721,   722,   723,   724,   725,   726,   727,   730,   731,
     732,   733,   734,   735,   736,   737,   738,   739,   551,   740,
     599,   741,   742,   743,   744,   745,   746,   747,   748,   749,
     750,   751,   752,   753,   755,   757,   758,   760,   762,   763,
    -744,  -744,   801,   764,   711,   803,   823,   810,   812,   814,
     765,  -744,   815,   766,   817,   767,  -744,  -744,   768,   825,
     826,   870,   772,  -744,   790,  -744,   184,   791,   792,  -744,
    -744,   853,   816,   771,   856,   861,   863,   793,   865,   794,
    -744,  -744,   867,   872,   873,   797,  -744,   798,   799,   800,
     802,   804,   805,  -744,   806,   808,   809,   811,   813,   818,
     819,   820,  -744,  -744,  -195,  -744,  -744,  -744,  -172,  -744,
     821,   822,   824,   827,   828,  -744,  -744,   874,   829,   875,
     830,  -744,  -744,   876,   831,   833,  -744,   835,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   454,   454,   454,   454,   454,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,   847,   314,   848,   849,  -744,   850,
     851,   852,   854,   855,    13,   857,   858,   859,   860,   862,
     864,   866,   868,  -744,   869,   871,  -744,  -744,   877,   878,
     879,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -167,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -154,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,   880,   881,   309,   882,   883,
     884,   885,   886,  -744,   887,   893,   888,  -744,   -33,   889,
     890,   832,   891,  -744,  -744,  -744,   892,   894,  -744,   895,
     154,  -744,  -744,  -744,  -744,  -744,  -744,   896,   899,   511,
     900,   901,   902,   627,   903,  -744,   904,   905,   906,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,    79,  -744,   159,  -744,  -744,
    -744,  -744,  -744,   907,   460,   908,  -744,   909,   665,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,   786,   786,
     786,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -145,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,   -50,  -744,  -744,
     551,  -744,   599,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,   -41,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,   -27,  -744,  -744,  -744,  -744,  -744,   -17,
    -744,  -744,  -744,   898,   870,   910,  -744,   911,   912,   -86,
     913,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,    34,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,    40,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,    53,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,    63,  -744,  -744,  -744,  -744,  -744,    13,  -744,   879,
    -744,  -744,  -744,   309,  -744,   893,  -744,   -33,  -744,  -744,
    -744,   914,   277,   916,   917,  -744,  -744,   511,  -744,   627,
    -744,   460,  -744,   665,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,    68,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,   277,  -744
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -744,  -744,  -744,  -743,  -298,  -663,  -598,  -744,  -744,   897,
    -744,  -744,  -744,  -744,   915,  -744,  -744,  -744,    14,  -744,
       1,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,   924,  -744,  -744,  -744,
    -744,  -744,   796,  -744,  -744,  -744,  -744,    48,  -744,  -744,
    -744,  -744,  -744,  -226,  -744,  -744,  -744,   500,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -196,  -744,  -744,
    -744,  -193,  -744,  -744,  -744,   680,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -177,  -744,   548,  -744,  -744,
    -744,   -62,  -744,  -744,  -744,  -744,  -744,   575,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -153,  -744,  -744,  -744,  -744,
    -744,  -744,   516,  -744,  -744,  -744,  -744,  -744,   918,  -744,
    -744,  -744,  -744,   482,  -744,  -744,  -744,  -744,  -744,  -163,
    -744,  -744,  -744,   483,  -744,  -744,  -744,  -744,  -159,  -744,
    -744,  -744,   688,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -137,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -117,  -744,   604,  -744,  -744,  -744,
    -744,  -744,   700,  -744,  -744,  -744,  -744,   966,  -744,  -744,
    -744,  -744,  -744,  -744,   -99,  -744,   701,  -744,  -744,  -744,
    -744,   919,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,    35,
    -744,  -744,  -744,    32,  -744,  -744,  -744,  -744,  -744,   997,
    -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,  -744,
    -744,  -744,  -744,  -744,  -744,  -744,   920,  -744,  -744,  -744,
    -744,  -744,  -744
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     806,   807,   573,   574,   236,   220,    45,    46,   220,   373,
     581,   462,   383,   805,   667,   668,   286,   110,  1076,    67,
     984,  1030,   227,   555,   985,   462,   286,   669,   670,   110,
      47,   555,  1001,  1002,  1003,  1004,  1005,   383,    48,   116,
     237,    52,    68,   986,   117,   118,    54,   987,  1049,    69,
     119,    58,  1050,    59,   238,   239,   240,   241,   120,   443,
     227,  1051,    67,   291,   121,  1052,   122,   123,   124,   374,
    1176,   492,   242,   125,  1177,   444,   251,   111,    62,   126,
     127,    63,   128,   129,   130,    68,    66,   493,   131,   111,
     445,   107,    69,   132,   446,   630,   631,   133,   134,   252,
     384,   135,   494,   638,   287,   640,   495,    70,   228,  1193,
     136,   556,   647,   108,   287,   650,   471,   137,   138,   556,
     139,   140,   141,   142,   143,   384,   661,   662,   375,   546,
     463,   385,   253,   109,   229,   144,   673,   674,   115,   676,
     217,   145,   146,   147,   463,   148,   228,   511,   149,   150,
      70,   472,   151,  1077,   218,   946,   385,   219,  1078,   496,
     512,   464,   386,    76,   254,  1178,   255,   256,   234,  1179,
     447,   473,   229,   557,  1182,   464,   474,   235,  1183,   448,
     449,   557,   497,    77,    78,   946,   152,   386,  1184,    79,
     153,   284,  1185,   154,   155,   156,   157,   158,  1186,   498,
     159,   160,  1187,   257,  1031,   258,   259,   260,   261,   546,
     511,   450,   221,   742,   743,   221,   465,   547,  -107,   526,
     484,  -107,   262,   512,   620,   565,   695,   732,    80,    81,
     465,   563,   475,   313,   295,    82,    83,    84,   765,   513,
     161,   162,   163,   947,   381,   164,   263,   314,   315,  1196,
     165,   316,   627,  1197,   441,  1198,   264,    85,    86,  1199,
     471,   344,   499,   345,   451,   346,   514,   373,  1200,   285,
      87,    88,  1201,   947,   690,   490,   500,   347,  1202,   548,
     292,    89,  1203,  1225,   265,   266,   719,  1226,   482,    90,
     795,   544,   348,   746,   747,   472,   349,   547,   803,   804,
     810,   811,   513,   293,   294,   948,   297,   298,   317,   318,
     319,   299,   300,   320,   301,   473,   350,  1210,   351,   302,
     474,   321,  1055,  1018,  1019,  1020,   303,   374,   352,   514,
     304,   702,   322,   323,   549,   948,   305,   306,   443,  1211,
     486,  1212,  1056,   307,   760,   308,   487,   324,   325,   353,
     309,   310,  1057,   380,   444,  1173,  1174,  1175,  1058,   548,
     392,   393,   725,   394,   528,   395,   396,   949,   397,   445,
    1090,   398,   566,   446,  1059,   326,   475,   354,   311,  1213,
     568,   399,   251,   116,   400,   401,   375,   402,   117,   118,
     492,   403,   404,   405,   119,   406,   407,   949,   408,  1060,
     409,   410,   120,   411,   355,   252,   493,  1061,   121,   412,
     122,   123,   124,   805,   549,   413,   327,   125,   414,   415,
     416,   494,   417,   126,   127,   495,   128,   129,   130,   418,
     419,   356,   131,   420,   422,   424,   425,   132,   253,   426,
     427,   133,   134,   428,   429,   135,  1062,   430,   600,   447,
    1214,  1215,   431,   432,   136,   433,   434,   435,   448,   449,
     436,   137,   138,  1063,   139,   140,   141,   142,   143,   357,
     254,   437,   255,   256,   438,   439,   616,   567,   496,   144,
     440,   483,   488,  1216,   569,   145,   146,   147,   489,   148,
     450,  1194,   149,   150,   520,   570,   151,   521,   522,   523,
     344,   497,   345,   524,   346,   525,   529,   530,   531,   257,
     532,   258,   259,   260,   261,  1094,   347,   533,   498,   534,
     535,   536,   537,   538,  1147,   539,   540,   571,   262,   572,
     152,   348,   313,   541,   153,   349,  1095,   154,   155,   156,
     157,   158,   542,   451,   159,   160,   314,   315,   543,   562,
     316,  1096,   263,   572,   575,   350,   576,   351,  1097,   578,
     577,   579,   264,   580,   582,   583,   584,   352,   775,   776,
     777,   778,   779,   585,   586,  1098,   622,   629,   587,   588,
     589,   499,   590,   591,   161,   162,   163,   592,   353,   164,
     265,   266,   593,   594,   165,   500,  1148,   595,  1099,   602,
     632,   596,   861,   633,   597,  1100,   598,   317,   318,   319,
       2,     3,   320,   599,     4,   603,   354,  1101,   604,   634,
     321,   605,   623,   635,     5,  1149,   606,     6,     7,   608,
     609,   322,   323,     8,  1150,  1102,  1103,  1104,   610,   236,
    1151,   611,   612,   355,     9,   613,   324,   325,    10,    11,
     884,   614,   615,   618,  1152,   619,  1153,  1154,    12,   624,
     625,   636,   637,   639,   641,  1155,   642,   643,   644,   645,
     356,  1156,    13,   646,   326,   237,   648,   649,  1118,   651,
      14,    15,   652,   654,   653,  1105,   655,   656,   657,   238,
     239,   240,   241,   658,  1106,   659,   660,   663,    16,  1107,
     664,   665,   666,   675,   671,  1108,   672,   242,   357,  1109,
     677,  1110,    17,   678,   679,   327,  1111,   862,   863,   864,
     865,   866,  1112,   867,   868,   680,   869,   870,   871,  1161,
     681,   872,   682,   873,   874,   683,   875,   685,   876,   686,
     877,   878,   704,   687,   879,   752,    18,   688,   689,   706,
     880,   692,   694,   697,   699,    19,    20,   700,   707,    21,
      22,   708,   705,   701,   709,   885,   886,   887,   888,   889,
     710,   890,   891,   721,   892,   893,   894,   711,   712,   895,
     714,   896,   897,   727,   898,   728,   899,   715,   900,   901,
     716,   718,   902,  1119,  1120,  1121,  1122,  1123,   903,  1124,
    1125,  1162,  1126,  1127,  1128,   729,   722,  1129,    76,  1130,
    1131,    23,  1132,   723,  1133,   724,  1134,  1135,   730,   731,
    1136,   733,   734,   735,   736,   737,  1137,   738,    77,    78,
    1163,   739,   740,   741,    79,   750,   751,   753,   754,  1164,
     757,   755,   759,   756,   762,  1165,   767,   768,   763,   769,
     770,   771,   772,   793,   773,   794,   774,   782,   796,  1166,
     783,  1167,  1168,   784,   785,   786,   787,   788,   789,   790,
    1169,   791,   792,    80,    81,   797,  1170,   798,   799,   800,
      82,    83,    84,   801,   802,   805,   808,   809,   812,   813,
     814,   815,   816,   817,   819,   818,   823,   826,   820,   821,
     822,   824,    85,    86,   827,   825,   828,   829,   830,   831,
     832,   833,   834,   835,   836,    87,    88,   837,   838,   925,
     839,   928,   929,   840,   926,   841,    89,   842,   930,   927,
     931,   843,   932,   934,    90,   936,   844,   845,   846,   847,
     848,   849,   850,   939,   940,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   883,   906,   907,   908,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   941,
     919,   957,   920,   921,   960,   922,   958,   923,   924,   961,
     933,   962,   937,   964,   935,   966,   938,   944,  1145,   959,
     967,   968,   993,   995,   997,   296,  1083,  1188,  1091,  1144,
    1227,   720,  1046,  1222,  1221,   945,   955,   956,   601,   965,
    1208,   963,   969,   970,   971,   972,  1072,   973,   485,   974,
     975,   976,  1189,   977,   978,   703,   979,   691,   980,  1191,
    1206,   726,   761,   981,   982,   983,   988,   989,  1223,   990,
    1204,   766,   991,   992,  1224,   996,   617,   994,   999,   998,
    1000,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,
    1015,  1016,  1017,  1023,  1024,  1025,  1026,  1027,  1207,  1028,
    1029,   696,  1034,  1035,  1036,  1037,   621,  1038,   382,  1039,
    1205,  1040,  1180,  1041,  1042,   442,  1043,  1181,   312,   628,
       0,     0,  1044,  1045,     0,  1053,  1054,  1066,  1067,  1068,
    1069,  1070,  1071,  1075,  1081,  1082,     0,  1086,     0,     0,
    1084,  1092,  1087,  1089,  1093,  1115,  1116,  1117,  1140,  1141,
    1142,  1143,  1146,  1159,  1160,  1190,     0,   491,  1195,  1209,
    1192,  1219,  1220,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   527,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   545,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   564
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-744)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     598,   599,   300,   301,     1,     1,   215,   216,     1,     1,
     308,     1,     1,    99,   160,   161,     1,     1,    51,     1,
     215,     8,     1,     1,   219,     1,     1,   160,   161,     1,
     217,     1,   775,   776,   777,   778,   779,     1,   217,     1,
      37,   217,    24,   215,     6,     7,   217,   219,   215,    31,
      12,   217,   219,   217,    51,    52,    53,    54,    20,     1,
       1,   215,     1,   215,    26,   219,    28,    29,    30,    61,
     215,     1,    69,    35,   219,    17,     1,    61,   217,    41,
      42,   217,    44,    45,    46,    24,   217,    17,    50,    61,
      32,   217,    31,    55,    36,   393,   394,    59,    60,    24,
      89,    63,    32,   401,    89,   403,    36,    89,    87,   195,
      72,    89,   410,   217,    89,   413,     1,    79,    80,    89,
      82,    83,    84,    85,    86,    89,   424,   425,   120,     1,
     120,   120,    57,   217,   113,    97,   434,   435,   217,   437,
     217,   103,   104,   105,   120,   107,    87,     1,   110,   111,
      89,    36,   114,   186,   217,     1,   120,   217,   191,    89,
      14,   151,   151,     1,    89,   215,    91,    92,   217,   219,
     112,    56,   113,   151,   215,   151,    61,   217,   219,   121,
     122,   151,   112,    21,    22,     1,   148,   151,   215,    27,
     152,   217,   219,   155,   156,   157,   158,   159,   215,   129,
     162,   163,   219,   128,   191,   130,   131,   132,   133,     1,
       1,   153,   208,   134,   135,   208,   206,    89,   214,   216,
     216,   214,   147,    14,   216,   118,   216,   525,    66,    67,
     206,   216,   117,     1,   216,    73,    74,    75,   216,    93,
     202,   203,   204,    89,   216,   207,   171,    15,    16,   215,
     212,    19,   216,   219,   216,   215,   181,    95,    96,   219,
       1,     1,   192,     3,   206,     5,   120,     1,   215,   217,
     108,   109,   219,    89,   216,   216,   206,    17,   215,   151,
     218,   119,   219,   215,   209,   210,   216,   219,   215,   127,
     588,   216,    32,   134,   135,    36,    36,    89,   596,   597,
     178,   179,    93,   218,   218,   151,   218,   218,    76,    77,
      78,   218,   218,    81,   218,    56,    56,    40,    58,   218,
      61,    89,    13,     9,    10,    11,   218,    61,    68,   120,
     218,   216,   100,   101,   206,   151,   218,   218,     1,    62,
     214,    64,    33,   218,   216,   218,   215,   115,   116,    89,
     218,   218,    43,   218,    17,  1018,  1019,  1020,    49,   151,
     218,   218,   216,   218,   215,   218,   218,   213,   218,    32,
     216,   218,   118,    36,    65,   143,   117,   117,   216,   102,
     215,   218,     1,     1,   218,   218,   120,   218,     6,     7,
       1,   218,   218,   218,    12,   218,   218,   213,   218,    90,
     218,   218,    20,   218,   144,    24,    17,    98,    26,   218,
      28,    29,    30,    99,   206,   218,   184,    35,   218,   218,
     218,    32,   218,    41,    42,    36,    44,    45,    46,   218,
     218,   171,    50,   218,   218,   218,   218,    55,    57,   218,
     218,    59,    60,   218,   218,    63,   137,   218,   216,   112,
     173,   174,   218,   218,    72,   218,   218,   218,   121,   122,
     218,    79,    80,   154,    82,    83,    84,    85,    86,   209,
      89,   218,    91,    92,   218,   218,   216,   118,    89,    97,
     218,   218,   218,   206,    99,   103,   104,   105,   218,   107,
     153,  1089,   110,   111,   218,    99,   114,   218,   218,   218,
       1,   112,     3,   218,     5,   218,   218,   218,   218,   128,
     218,   130,   131,   132,   133,     4,    17,   218,   129,   218,
     218,   218,   218,   218,    64,   218,   218,   160,   147,    99,
     148,    32,     1,   218,   152,    36,    25,   155,   156,   157,
     158,   159,   218,   206,   162,   163,    15,    16,   218,   218,
      19,    40,   171,    99,    99,    56,    99,    58,    47,   160,
      99,   160,   181,    99,   160,   160,   215,    68,   138,   139,
     140,   141,   142,   215,   218,    64,   118,   160,   218,   218,
     218,   192,   218,   218,   202,   203,   204,   218,    89,   207,
     209,   210,   218,   218,   212,   206,   136,   218,    87,   215,
      99,   218,    51,   160,   218,    94,   218,    76,    77,    78,
       0,     1,    81,   218,     4,   218,   117,   106,   218,   160,
      89,   218,   215,    99,    14,   165,   218,    17,    18,   218,
     218,   100,   101,    23,   174,   124,   125,   126,   218,     1,
     180,   218,   218,   144,    34,   218,   115,   116,    38,    39,
      51,   218,   218,   218,   194,   218,   196,   197,    48,   218,
     218,   118,   160,   160,    99,   205,    99,    99,   160,   160,
     171,   211,    62,   160,   143,    37,    99,    99,    51,    99,
      70,    71,    99,    99,   118,   174,    99,   160,   160,    51,
      52,    53,    54,   218,   183,   160,   218,   160,    88,   188,
     160,   160,   160,   118,   160,   194,   160,    69,   209,   198,
     160,   200,   102,   160,   160,   184,   205,   166,   167,   168,
     169,   170,   211,   172,   173,   215,   175,   176,   177,    64,
     215,   180,   218,   182,   183,   218,   185,   218,   187,   218,
     189,   190,   160,   218,   193,    99,   136,   218,   218,   217,
     199,   218,   218,   215,   218,   145,   146,   218,   118,   149,
     150,   118,   215,   218,   215,   166,   167,   168,   169,   170,
     215,   172,   173,   215,   175,   176,   177,   218,   218,   180,
     218,   182,   183,   160,   185,   160,   187,   218,   189,   190,
     218,   218,   193,   166,   167,   168,   169,   170,   199,   172,
     173,   136,   175,   176,   177,   118,   218,   180,     1,   182,
     183,   201,   185,   218,   187,   218,   189,   190,   160,   160,
     193,   215,   118,   160,   118,   118,   199,   118,    21,    22,
     165,   118,   118,   118,    27,   118,   118,   118,   118,   174,
     218,   215,   218,   215,   215,   180,   118,   215,   218,   215,
     215,   215,   215,    99,   215,    99,   215,   215,    99,   194,
     215,   196,   197,   215,   215,   215,   215,   215,   215,   215,
     205,   215,   215,    66,    67,    99,   211,    99,    99,   118,
      73,    74,    75,    99,    99,    99,   215,   118,   118,   160,
     218,   118,   118,   118,    99,   118,   215,   215,   118,   118,
     118,   118,    95,    96,   215,   118,   118,   118,   218,   215,
     215,   215,   215,   215,   215,   108,   109,   215,   215,   118,
     215,   118,    99,   215,   160,   215,   119,   215,   118,   218,
     118,   215,   118,   118,   127,   118,   215,   215,   215,   215,
     215,   215,   215,   118,   118,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,    99,
     215,   118,   215,   215,   118,   215,   160,   215,   215,   118,
     215,   118,   215,   118,   218,   118,   218,   215,   987,   218,
     118,   118,   118,   118,   118,    71,   164,    99,   950,   985,
    1226,   501,   123,  1199,  1197,   215,   215,   215,   328,   215,
    1187,   218,   215,   215,   215,   215,   123,   215,   222,   215,
     215,   215,  1084,   215,   215,   477,   215,   452,   215,   118,
    1183,   515,   550,   215,   215,   215,   215,   215,  1201,   215,
    1177,   558,   215,   215,  1203,   215,   358,   218,   215,   218,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,  1185,   215,
     215,   467,   215,   215,   215,   215,   376,   215,   112,   215,
    1179,   215,  1050,   215,   215,   166,   215,  1052,    91,   388,
      -1,    -1,   215,   215,    -1,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,    -1,   215,    -1,    -1,
     219,   215,   218,   218,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,    -1,   230,   215,   215,
     218,   215,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   267,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   288
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   221,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    88,   102,   136,   145,
     146,   149,   150,   201,   222,   227,   232,   254,   260,   274,
     292,   310,   324,   339,   346,   350,   360,   369,   389,   399,
     405,   409,   419,   477,   494,   215,   216,   217,   217,   293,
     370,   400,   217,   410,   217,   325,   390,   311,   217,   217,
     275,   340,   217,   217,   351,   361,   217,     1,    24,    31,
      89,   255,   256,   257,   258,   259,     1,    21,    22,    27,
      66,    67,    73,    74,    75,    95,    96,   108,   109,   119,
     127,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   217,   217,   217,
       1,    61,   406,   407,   408,   217,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    80,    82,
      83,    84,    85,    86,    97,   103,   104,   105,   107,   110,
     111,   114,   148,   152,   155,   156,   157,   158,   159,   162,
     163,   202,   203,   204,   207,   212,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   442,   443,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   470,   474,   475,   476,   217,   217,   217,
       1,   208,   261,   262,   263,   264,   265,     1,    87,   113,
     228,   229,   230,   231,   217,   217,     1,    37,    51,    52,
      53,    54,    69,   495,   496,   497,   498,   499,   500,   501,
     502,     1,    24,    57,    89,    91,    92,   128,   130,   131,
     132,   133,   147,   171,   181,   209,   210,   233,   234,   235,
     236,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   217,   217,     1,    89,   347,   348,
     349,   215,   218,   218,   218,   216,   256,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   216,   479,     1,    15,    16,    19,    76,    77,    78,
      81,    89,   100,   101,   115,   116,   143,   184,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,     1,     3,     5,    17,    32,    36,
      56,    58,    68,    89,   117,   144,   171,   209,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   384,   385,
     386,   387,   388,     1,    61,   120,   401,   402,   403,   404,
     218,   216,   407,     1,    89,   120,   151,   411,   415,   416,
     417,   418,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   471,   218,   467,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   216,   421,     1,    17,    32,    36,   112,   121,   122,
     153,   206,   326,   327,   328,   329,   330,   331,   332,   336,
     337,   338,     1,   120,   151,   206,   391,   395,   396,   397,
     398,     1,    36,    56,    61,   117,   312,   316,   317,   318,
     322,   323,   215,   218,   216,   262,   214,   215,   218,   218,
     216,   229,     1,    17,    32,    36,    89,   112,   129,   192,
     206,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     288,     1,    14,    93,   120,   341,   342,   343,   344,   345,
     218,   218,   218,   218,   218,   218,   216,   496,   215,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   216,   234,     1,    89,   151,   206,
     352,   353,   354,   355,   356,     1,    89,   151,   362,   363,
     364,   365,   218,   216,   348,   118,   118,   118,   215,    99,
      99,   160,    99,   224,   224,    99,    99,    99,   160,   160,
      99,   224,   160,   160,   215,   215,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     216,   295,   215,   218,   218,   218,   218,   381,   218,   218,
     218,   218,   218,   218,   218,   218,   216,   372,   218,   218,
     216,   402,   118,   215,   218,   218,   412,   216,   416,   160,
     224,   224,    99,   160,   160,    99,   118,   160,   224,   160,
     224,    99,    99,    99,   160,   160,   160,   224,    99,    99,
     224,    99,    99,   118,    99,    99,   160,   160,   218,   160,
     218,   224,   224,   160,   160,   160,   160,   160,   161,   160,
     161,   160,   160,   224,   224,   118,   224,   160,   160,   160,
     215,   215,   218,   218,   333,   218,   218,   218,   218,   218,
     216,   327,   218,   392,   218,   216,   396,   215,   313,   218,
     218,   218,   216,   317,   160,   215,   217,   118,   118,   215,
     215,   218,   218,   289,   218,   218,   218,   285,   218,   216,
     277,   215,   218,   218,   218,   216,   342,   160,   160,   118,
     160,   160,   224,   215,   118,   160,   118,   118,   118,   118,
     118,   118,   134,   135,   237,   238,   134,   135,   239,   240,
     118,   118,    99,   118,   118,   215,   215,   218,   357,   218,
     216,   353,   215,   218,   366,   216,   363,   118,   215,   215,
     215,   215,   215,   215,   215,   138,   139,   140,   141,   142,
     223,   224,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,    99,    99,   224,    99,    99,    99,    99,
     118,    99,    99,   224,   224,    99,   226,   226,   215,   118,
     178,   179,   118,   160,   218,   118,   118,   118,   118,    99,
     118,   118,   118,   215,   118,   118,   215,   215,   118,   118,
     218,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,    51,   166,   167,   168,   169,   170,   172,   173,   175,
     176,   177,   180,   182,   183,   185,   187,   189,   190,   193,
     199,   472,   473,   215,    51,   166,   167,   168,   169,   170,
     172,   173,   175,   176,   177,   180,   182,   183,   185,   187,
     189,   190,   193,   199,   468,   469,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   118,   160,   218,   118,    99,
     118,   118,   118,   215,   118,   218,   118,   215,   218,   118,
     118,    99,   320,   321,   215,   215,     1,    89,   151,   213,
     266,   267,   268,   269,   270,   215,   215,   118,   160,   218,
     118,   118,   118,   218,   118,   215,   118,   118,   118,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   219,   215,   219,   215,   215,
     215,   215,   215,   118,   218,   118,   215,   118,   218,   215,
     215,   223,   223,   223,   223,   223,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,     9,    10,
      11,   225,   226,   215,   215,   215,   215,   215,   215,   215,
       8,   191,   382,   383,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   123,   413,   414,   215,
     219,   215,   219,   215,   215,    13,    33,    43,    49,    65,
      90,    98,   137,   154,   334,   335,   215,   215,   215,   215,
     215,   215,   123,   393,   394,   215,    51,   186,   191,   314,
     315,   215,   215,   164,   219,   319,   215,   218,   271,   218,
     216,   267,   215,   215,     4,    25,    40,    47,    64,    87,
      94,   106,   124,   125,   126,   174,   183,   188,   194,   198,
     200,   205,   211,   290,   291,   215,   215,   215,    51,   166,
     167,   168,   169,   170,   172,   173,   175,   176,   177,   180,
     182,   183,   185,   187,   189,   190,   193,   199,   286,   287,
     215,   215,   215,   215,   238,   240,   215,    64,   136,   165,
     174,   180,   194,   196,   197,   205,   211,   358,   359,   215,
     215,    64,   136,   165,   174,   180,   194,   196,   197,   205,
     211,   367,   368,   225,   225,   225,   215,   219,   215,   219,
     473,   469,   215,   219,   215,   219,   215,   219,    99,   321,
     215,   118,   218,   195,   226,   215,   215,   219,   215,   219,
     215,   219,   215,   219,   383,   414,   335,   394,   315,   215,
      40,    62,    64,   102,   173,   174,   206,   272,   273,   215,
     215,   291,   287,   359,   368,   215,   219,   273
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


#ifndef YYLVAL_INITIALIZE
# define YYLVAL_INITIALIZE()
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif

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

  YYLVAL_INITIALIZE ();
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
        case 26:
/* Line 1813 of yacc.c  */
#line 359 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1813 of yacc.c  */
#line 361 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1813 of yacc.c  */
#line 365 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1813 of yacc.c  */
#line 369 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1813 of yacc.c  */
#line 373 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1813 of yacc.c  */
#line 377 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1813 of yacc.c  */
#line 381 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1813 of yacc.c  */
#line 386 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1813 of yacc.c  */
#line 387 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1813 of yacc.c  */
#line 388 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1813 of yacc.c  */
#line 389 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1813 of yacc.c  */
#line 390 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1813 of yacc.c  */
#line 404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1813 of yacc.c  */
#line 410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1813 of yacc.c  */
#line 435 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1813 of yacc.c  */
#line 441 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1813 of yacc.c  */
#line 450 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1813 of yacc.c  */
#line 456 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1813 of yacc.c  */
#line 464 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 503 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 562 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 590 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1813 of yacc.c  */
#line 598 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 613 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 628 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 84:
/* Line 1813 of yacc.c  */
#line 637 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 651 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 86:
/* Line 1813 of yacc.c  */
#line 660 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 688 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 718 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 741 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1813 of yacc.c  */
#line 756 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 98:
/* Line 1813 of yacc.c  */
#line 765 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 99:
/* Line 1813 of yacc.c  */
#line 774 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 106:
/* Line 1813 of yacc.c  */
#line 792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1813 of yacc.c  */
#line 798 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1813 of yacc.c  */
#line 803 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1813 of yacc.c  */
#line 815 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1813 of yacc.c  */
#line 820 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1813 of yacc.c  */
#line 823 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1813 of yacc.c  */
#line 828 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1813 of yacc.c  */
#line 835 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1813 of yacc.c  */
#line 839 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1813 of yacc.c  */
#line 843 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1813 of yacc.c  */
#line 847 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1813 of yacc.c  */
#line 851 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1813 of yacc.c  */
#line 855 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1813 of yacc.c  */
#line 859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1813 of yacc.c  */
#line 869 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 882 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 143:
/* Line 1813 of yacc.c  */
#line 981 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1018 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1030 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1041 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 148:
/* Line 1813 of yacc.c  */
#line 1092 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 152:
/* Line 1813 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1813 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1813 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1813 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1813 of yacc.c  */
#line 1115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1813 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1813 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1813 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1813 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1813 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1813 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1813 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1813 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1813 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1813 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1813 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1813 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1813 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1813 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1813 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1813 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 176:
/* Line 1813 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1813 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1813 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1813 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1813 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1813 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1813 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1813 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1813 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1813 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1813 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1813 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1813 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1813 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1813 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1813 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1813 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1813 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1813 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1813 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 196:
/* Line 1813 of yacc.c  */
#line 1277 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1335 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 215:
/* Line 1813 of yacc.c  */
#line 1344 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1813 of yacc.c  */
#line 1350 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1813 of yacc.c  */
#line 1356 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1813 of yacc.c  */
#line 1362 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1813 of yacc.c  */
#line 1368 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1813 of yacc.c  */
#line 1374 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1813 of yacc.c  */
#line 1380 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1813 of yacc.c  */
#line 1386 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1813 of yacc.c  */
#line 1392 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1813 of yacc.c  */
#line 1398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1813 of yacc.c  */
#line 1405 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1813 of yacc.c  */
#line 1411 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1813 of yacc.c  */
#line 1417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1813 of yacc.c  */
#line 1426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 229:
/* Line 1813 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 230:
/* Line 1813 of yacc.c  */
#line 1442 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 234:
/* Line 1813 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 235:
/* Line 1813 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 236:
/* Line 1813 of yacc.c  */
#line 1456 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 244:
/* Line 1813 of yacc.c  */
#line 1466 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 248:
/* Line 1813 of yacc.c  */
#line 1471 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1485 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1505 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 251:
/* Line 1813 of yacc.c  */
#line 1514 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 252:
/* Line 1813 of yacc.c  */
#line 1526 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1538 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1600 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1635 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1648 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 268:
/* Line 1813 of yacc.c  */
#line 1657 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1668 "conf_parser.y"
    {
}
    break;

  case 273:
/* Line 1813 of yacc.c  */
#line 1673 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 274:
/* Line 1813 of yacc.c  */
#line 1677 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 275:
/* Line 1813 of yacc.c  */
#line 1681 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 276:
/* Line 1813 of yacc.c  */
#line 1685 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 277:
/* Line 1813 of yacc.c  */
#line 1689 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 278:
/* Line 1813 of yacc.c  */
#line 1693 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 279:
/* Line 1813 of yacc.c  */
#line 1697 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 280:
/* Line 1813 of yacc.c  */
#line 1701 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 281:
/* Line 1813 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 282:
/* Line 1813 of yacc.c  */
#line 1711 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
    {    
      DupString(yy_conf->name, yylval.string);
      yy_aconf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 283:
/* Line 1813 of yacc.c  */
#line 1730 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1740 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 285:
/* Line 1813 of yacc.c  */
#line 1753 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 286:
/* Line 1813 of yacc.c  */
#line 1760 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 293:
/* Line 1813 of yacc.c  */
#line 1772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 294:
/* Line 1813 of yacc.c  */
#line 1781 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1796 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 301:
/* Line 1813 of yacc.c  */
#line 1814 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1829 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1837 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 310:
/* Line 1813 of yacc.c  */
#line 1848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 311:
/* Line 1813 of yacc.c  */
#line 1857 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 316:
/* Line 1813 of yacc.c  */
#line 1886 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 317:
/* Line 1813 of yacc.c  */
#line 1890 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 318:
/* Line 1813 of yacc.c  */
#line 1894 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 319:
/* Line 1813 of yacc.c  */
#line 1898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 320:
/* Line 1813 of yacc.c  */
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 321:
/* Line 1813 of yacc.c  */
#line 1906 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 322:
/* Line 1813 of yacc.c  */
#line 1910 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 323:
/* Line 1813 of yacc.c  */
#line 1914 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 324:
/* Line 1813 of yacc.c  */
#line 1918 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 325:
/* Line 1813 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 326:
/* Line 1813 of yacc.c  */
#line 1931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 327:
/* Line 1813 of yacc.c  */
#line 1938 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1951 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 334:
/* Line 1813 of yacc.c  */
#line 1957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 338:
/* Line 1813 of yacc.c  */
#line 1964 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 339:
/* Line 1813 of yacc.c  */
#line 1968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 340:
/* Line 1813 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 341:
/* Line 1813 of yacc.c  */
#line 1976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 342:
/* Line 1813 of yacc.c  */
#line 1980 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 343:
/* Line 1813 of yacc.c  */
#line 1984 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 344:
/* Line 1813 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 345:
/* Line 1813 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 346:
/* Line 1813 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 347:
/* Line 1813 of yacc.c  */
#line 2000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 348:
/* Line 1813 of yacc.c  */
#line 2009 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2024 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2068 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 367:
/* Line 1813 of yacc.c  */
#line 2077 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 368:
/* Line 1813 of yacc.c  */
#line 2086 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2112 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2130 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 372:
/* Line 1813 of yacc.c  */
#line 2154 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 373:
/* Line 1813 of yacc.c  */
#line 2158 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 374:
/* Line 1813 of yacc.c  */
#line 2166 "conf_parser.y"
    {
}
    break;

  case 378:
/* Line 1813 of yacc.c  */
#line 2171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 379:
/* Line 1813 of yacc.c  */
#line 2175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 380:
/* Line 1813 of yacc.c  */
#line 2181 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2192 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2203 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2214 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 384:
/* Line 1813 of yacc.c  */
#line 2223 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 386:
/* Line 1813 of yacc.c  */
#line 2248 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2304 "conf_parser.y"
    {
}
    break;

  case 391:
/* Line 1813 of yacc.c  */
#line 2309 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 398:
/* Line 1813 of yacc.c  */
#line 2318 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2337 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 400:
/* Line 1813 of yacc.c  */
#line 2346 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 401:
/* Line 1813 of yacc.c  */
#line 2350 "conf_parser.y"
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

  case 407:
/* Line 1813 of yacc.c  */
#line 2372 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 408:
/* Line 1813 of yacc.c  */
#line 2378 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 414:
/* Line 1813 of yacc.c  */
#line 2392 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 416:
/* Line 1813 of yacc.c  */
#line 2417 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 2457 "conf_parser.y"
    {
}
    break;

  case 421:
/* Line 1813 of yacc.c  */
#line 2462 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 428:
/* Line 1813 of yacc.c  */
#line 2471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 429:
/* Line 1813 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 483:
/* Line 1813 of yacc.c  */
#line 2522 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 484:
/* Line 1813 of yacc.c  */
#line 2527 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 485:
/* Line 1813 of yacc.c  */
#line 2533 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:
/* Line 1813 of yacc.c  */
#line 2539 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1813 of yacc.c  */
#line 2545 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:
/* Line 1813 of yacc.c  */
#line 2550 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1813 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 490:
/* Line 1813 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1813 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 492:
/* Line 1813 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 493:
/* Line 1813 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 494:
/* Line 1813 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 495:
/* Line 1813 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 496:
/* Line 1813 of yacc.c  */
#line 2590 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 497:
/* Line 1813 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1813 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1813 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:
/* Line 1813 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1813 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1813 of yacc.c  */
#line 2621 "conf_parser.y"
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

  case 503:
/* Line 1813 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 504:
/* Line 1813 of yacc.c  */
#line 2637 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 505:
/* Line 1813 of yacc.c  */
#line 2642 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 506:
/* Line 1813 of yacc.c  */
#line 2647 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 507:
/* Line 1813 of yacc.c  */
#line 2652 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 508:
/* Line 1813 of yacc.c  */
#line 2657 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 509:
/* Line 1813 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 510:
/* Line 1813 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 511:
/* Line 1813 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 512:
/* Line 1813 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1813 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1813 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 515:
/* Line 1813 of yacc.c  */
#line 2688 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1813 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 517:
/* Line 1813 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 518:
/* Line 1813 of yacc.c  */
#line 2703 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 519:
/* Line 1813 of yacc.c  */
#line 2708 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 520:
/* Line 1813 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 521:
/* Line 1813 of yacc.c  */
#line 2724 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1813 of yacc.c  */
#line 2729 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 523:
/* Line 1813 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 524:
/* Line 1813 of yacc.c  */
#line 2739 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 525:
/* Line 1813 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 526:
/* Line 1813 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 527:
/* Line 1813 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 528:
/* Line 1813 of yacc.c  */
#line 2767 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 529:
/* Line 1813 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 533:
/* Line 1813 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 534:
/* Line 1813 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 535:
/* Line 1813 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 536:
/* Line 1813 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 537:
/* Line 1813 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 538:
/* Line 1813 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 539:
/* Line 1813 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 540:
/* Line 1813 of yacc.c  */
#line 2799 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 541:
/* Line 1813 of yacc.c  */
#line 2802 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 542:
/* Line 1813 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 543:
/* Line 1813 of yacc.c  */
#line 2808 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 544:
/* Line 1813 of yacc.c  */
#line 2811 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 545:
/* Line 1813 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 546:
/* Line 1813 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 547:
/* Line 1813 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 548:
/* Line 1813 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 549:
/* Line 1813 of yacc.c  */
#line 2826 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 550:
/* Line 1813 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 551:
/* Line 1813 of yacc.c  */
#line 2832 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 552:
/* Line 1813 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 553:
/* Line 1813 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 557:
/* Line 1813 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 558:
/* Line 1813 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 559:
/* Line 1813 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 560:
/* Line 1813 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 561:
/* Line 1813 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 562:
/* Line 1813 of yacc.c  */
#line 2861 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 563:
/* Line 1813 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 564:
/* Line 1813 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 565:
/* Line 1813 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 566:
/* Line 1813 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 567:
/* Line 1813 of yacc.c  */
#line 2876 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 568:
/* Line 1813 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 569:
/* Line 1813 of yacc.c  */
#line 2882 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 570:
/* Line 1813 of yacc.c  */
#line 2885 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 571:
/* Line 1813 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 572:
/* Line 1813 of yacc.c  */
#line 2891 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 573:
/* Line 1813 of yacc.c  */
#line 2894 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 574:
/* Line 1813 of yacc.c  */
#line 2897 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 575:
/* Line 1813 of yacc.c  */
#line 2900 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 576:
/* Line 1813 of yacc.c  */
#line 2903 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 577:
/* Line 1813 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 578:
/* Line 1813 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 579:
/* Line 1813 of yacc.c  */
#line 2918 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:
/* Line 1813 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 599:
/* Line 1813 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 600:
/* Line 1813 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1813 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1813 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:
/* Line 1813 of yacc.c  */
#line 2966 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1813 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 605:
/* Line 1813 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1813 of yacc.c  */
#line 2981 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1813 of yacc.c  */
#line 2986 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1813 of yacc.c  */
#line 2991 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 609:
/* Line 1813 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 610:
/* Line 1813 of yacc.c  */
#line 3001 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 611:
/* Line 1813 of yacc.c  */
#line 3006 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 622:
/* Line 1813 of yacc.c  */
#line 3024 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 623:
/* Line 1813 of yacc.c  */
#line 3030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 624:
/* Line 1813 of yacc.c  */
#line 3036 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 625:
/* Line 1813 of yacc.c  */
#line 3045 "conf_parser.y"
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

  case 626:
/* Line 1813 of yacc.c  */
#line 3059 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 627:
/* Line 1813 of yacc.c  */
#line 3065 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1813 of yacc.c  */
#line 6852 "conf_parser.c"
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


