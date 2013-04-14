/* A Bison parser, made by GNU Bison 2.7.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
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
#include "rsa.h"

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


/* Line 371 of yacc.c  */
#line 154 "conf_parser.c"

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
#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
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
     MAX_NICK_LENGTH = 335,
     MAX_NICK_TIME = 336,
     MAX_NUMBER = 337,
     MAX_TARGETS = 338,
     MAX_TOPIC_LENGTH = 339,
     MAX_WATCH = 340,
     MESSAGE_LOCALE = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MIN_IDLE = 344,
     MAX_IDLE = 345,
     RANDOM_IDLE = 346,
     HIDE_IDLE_FROM_OPERS = 347,
     MODULE = 348,
     MODULES = 349,
     NAME = 350,
     NEED_PASSWORD = 351,
     NETWORK_DESC = 352,
     NETWORK_NAME = 353,
     NICK = 354,
     NICK_CHANGES = 355,
     NO_CREATE_ON_SPLIT = 356,
     NO_JOIN_ON_SPLIT = 357,
     NO_OPER_FLOOD = 358,
     NO_TILDE = 359,
     NUMBER = 360,
     NUMBER_PER_CIDR = 361,
     NUMBER_PER_IP = 362,
     OPERATOR = 363,
     OPERS_BYPASS_CALLERID = 364,
     OPER_ONLY_UMODES = 365,
     OPER_PASS_RESV = 366,
     OPER_SPY_T = 367,
     OPER_UMODES = 368,
     JOIN_FLOOD_COUNT = 369,
     JOIN_FLOOD_TIME = 370,
     PACE_WAIT = 371,
     PACE_WAIT_SIMPLE = 372,
     PASSWORD = 373,
     PATH = 374,
     PING_COOKIE = 375,
     PING_TIME = 376,
     PING_WARNING = 377,
     PORT = 378,
     QSTRING = 379,
     QUIET_ON_BAN = 380,
     REASON = 381,
     REDIRPORT = 382,
     REDIRSERV = 383,
     REGEX_T = 384,
     REHASH = 385,
     REMOTE = 386,
     REMOTEBAN = 387,
     RESTRICT_CHANNELS = 388,
     RSA_PRIVATE_KEY_FILE = 389,
     RSA_PUBLIC_KEY_FILE = 390,
     SSL_CERTIFICATE_FILE = 391,
     SSL_DH_PARAM_FILE = 392,
     T_SSL_CLIENT_METHOD = 393,
     T_SSL_SERVER_METHOD = 394,
     T_SSLV3 = 395,
     T_TLSV1 = 396,
     RESV = 397,
     RESV_EXEMPT = 398,
     SECONDS = 399,
     MINUTES = 400,
     HOURS = 401,
     DAYS = 402,
     WEEKS = 403,
     MONTHS = 404,
     YEARS = 405,
     SENDQ = 406,
     SEND_PASSWORD = 407,
     SERVERHIDE = 408,
     SERVERINFO = 409,
     IRCD_SID = 410,
     TKLINE_EXPIRE_NOTICES = 411,
     T_SHARED = 412,
     T_CLUSTER = 413,
     TYPE = 414,
     SHORT_MOTD = 415,
     SPOOF = 416,
     SPOOF_NOTICE = 417,
     STATS_E_DISABLED = 418,
     STATS_I_OPER_ONLY = 419,
     STATS_K_OPER_ONLY = 420,
     STATS_O_OPER_ONLY = 421,
     STATS_P_OPER_ONLY = 422,
     TBOOL = 423,
     TMASKED = 424,
     TS_MAX_DELTA = 425,
     TS_WARN_DELTA = 426,
     TWODOTS = 427,
     T_ALL = 428,
     T_BOTS = 429,
     T_SOFTCALLERID = 430,
     T_CALLERID = 431,
     T_CCONN = 432,
     T_CCONN_FULL = 433,
     T_SSL_CIPHER_LIST = 434,
     T_DEAF = 435,
     T_DEBUG = 436,
     T_DLINE = 437,
     T_EXTERNAL = 438,
     T_FULL = 439,
     T_INVISIBLE = 440,
     T_IPV4 = 441,
     T_IPV6 = 442,
     T_LOCOPS = 443,
     T_MAX_CLIENTS = 444,
     T_NCHANGE = 445,
     T_NO_JOIN = 446,
     T_OPERWALL = 447,
     T_RECVQ = 448,
     T_REJ = 449,
     T_SERVER = 450,
     T_SERVNOTICE = 451,
     T_SET = 452,
     T_SKILL = 453,
     T_SPY = 454,
     T_SSL = 455,
     T_UMODES = 456,
     T_UNAUTH = 457,
     T_UNDLINE = 458,
     T_UNLIMITED = 459,
     T_UNRESV = 460,
     T_UNXLINE = 461,
     T_GLOBOPS = 462,
     T_WALLOP = 463,
     T_RESTART = 464,
     T_SERVICE = 465,
     T_SERVICES_NAME = 466,
     THROTTLE_TIME = 467,
     TRUE_NO_OPER_FLOOD = 468,
     UNKLINE = 469,
     USER = 470,
     USE_EGD = 471,
     USE_LOGGING = 472,
     VHOST = 473,
     VHOST6 = 474,
     XLINE = 475,
     WARN_NO_NLINE = 476,
     T_SIZE = 477,
     T_FILE = 478,
     COUNTRY_CODE = 479
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
#define MAX_NICK_LENGTH 335
#define MAX_NICK_TIME 336
#define MAX_NUMBER 337
#define MAX_TARGETS 338
#define MAX_TOPIC_LENGTH 339
#define MAX_WATCH 340
#define MESSAGE_LOCALE 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MIN_IDLE 344
#define MAX_IDLE 345
#define RANDOM_IDLE 346
#define HIDE_IDLE_FROM_OPERS 347
#define MODULE 348
#define MODULES 349
#define NAME 350
#define NEED_PASSWORD 351
#define NETWORK_DESC 352
#define NETWORK_NAME 353
#define NICK 354
#define NICK_CHANGES 355
#define NO_CREATE_ON_SPLIT 356
#define NO_JOIN_ON_SPLIT 357
#define NO_OPER_FLOOD 358
#define NO_TILDE 359
#define NUMBER 360
#define NUMBER_PER_CIDR 361
#define NUMBER_PER_IP 362
#define OPERATOR 363
#define OPERS_BYPASS_CALLERID 364
#define OPER_ONLY_UMODES 365
#define OPER_PASS_RESV 366
#define OPER_SPY_T 367
#define OPER_UMODES 368
#define JOIN_FLOOD_COUNT 369
#define JOIN_FLOOD_TIME 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PING_WARNING 377
#define PORT 378
#define QSTRING 379
#define QUIET_ON_BAN 380
#define REASON 381
#define REDIRPORT 382
#define REDIRSERV 383
#define REGEX_T 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESTRICT_CHANNELS 388
#define RSA_PRIVATE_KEY_FILE 389
#define RSA_PUBLIC_KEY_FILE 390
#define SSL_CERTIFICATE_FILE 391
#define SSL_DH_PARAM_FILE 392
#define T_SSL_CLIENT_METHOD 393
#define T_SSL_SERVER_METHOD 394
#define T_SSLV3 395
#define T_TLSV1 396
#define RESV 397
#define RESV_EXEMPT 398
#define SECONDS 399
#define MINUTES 400
#define HOURS 401
#define DAYS 402
#define WEEKS 403
#define MONTHS 404
#define YEARS 405
#define SENDQ 406
#define SEND_PASSWORD 407
#define SERVERHIDE 408
#define SERVERINFO 409
#define IRCD_SID 410
#define TKLINE_EXPIRE_NOTICES 411
#define T_SHARED 412
#define T_CLUSTER 413
#define TYPE 414
#define SHORT_MOTD 415
#define SPOOF 416
#define SPOOF_NOTICE 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define TBOOL 423
#define TMASKED 424
#define TS_MAX_DELTA 425
#define TS_WARN_DELTA 426
#define TWODOTS 427
#define T_ALL 428
#define T_BOTS 429
#define T_SOFTCALLERID 430
#define T_CALLERID 431
#define T_CCONN 432
#define T_CCONN_FULL 433
#define T_SSL_CIPHER_LIST 434
#define T_DEAF 435
#define T_DEBUG 436
#define T_DLINE 437
#define T_EXTERNAL 438
#define T_FULL 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_MAX_CLIENTS 444
#define T_NCHANGE 445
#define T_NO_JOIN 446
#define T_OPERWALL 447
#define T_RECVQ 448
#define T_REJ 449
#define T_SERVER 450
#define T_SERVNOTICE 451
#define T_SET 452
#define T_SKILL 453
#define T_SPY 454
#define T_SSL 455
#define T_UMODES 456
#define T_UNAUTH 457
#define T_UNDLINE 458
#define T_UNLIMITED 459
#define T_UNRESV 460
#define T_UNXLINE 461
#define T_GLOBOPS 462
#define T_WALLOP 463
#define T_RESTART 464
#define T_SERVICE 465
#define T_SERVICES_NAME 466
#define THROTTLE_TIME 467
#define TRUE_NO_OPER_FLOOD 468
#define UNKLINE 469
#define USER 470
#define USE_EGD 471
#define USE_LOGGING 472
#define VHOST 473
#define VHOST6 474
#define XLINE 475
#define WARN_NO_NLINE 476
#define T_SIZE 477
#define T_FILE 478
#define COUNTRY_CODE 479



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 111 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 651 "conf_parser.c"
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

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 679 "conf_parser.c"

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
#define YYLAST   1180

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  292
/* YYNRULES -- Number of rules.  */
#define YYNRULES  647
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1269

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   479

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   229,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   225,
       2,   228,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   227,     2,   226,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    45,    47,    50,    53,    54,    56,    59,
      63,    67,    71,    75,    79,    83,    87,    88,    90,    93,
      97,   101,   105,   111,   114,   116,   118,   120,   123,   128,
     133,   139,   142,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   164,   166,   168,   170,   172,   174,   176,
     178,   181,   186,   191,   195,   197,   199,   201,   205,   207,
     209,   211,   216,   221,   226,   231,   236,   241,   246,   251,
     256,   261,   266,   271,   276,   281,   286,   292,   295,   297,
     299,   301,   303,   306,   311,   316,   321,   327,   330,   332,
     334,   336,   339,   344,   345,   352,   355,   357,   359,   361,
     363,   366,   371,   376,   381,   382,   388,   392,   394,   396,
     398,   400,   402,   404,   406,   408,   409,   416,   419,   421,
     423,   425,   427,   429,   431,   433,   435,   437,   440,   445,
     450,   455,   460,   465,   470,   471,   477,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   524,
     530,   534,   536,   538,   540,   542,   544,   546,   548,   550,
     552,   554,   556,   558,   560,   562,   564,   566,   568,   570,
     572,   574,   575,   582,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   621,   624,   629,   634,   639,   644,   649,   654,
     659,   664,   669,   674,   679,   684,   689,   694,   699,   704,
     705,   711,   715,   717,   719,   721,   722,   729,   730,   736,
     740,   742,   744,   746,   748,   751,   753,   755,   757,   759,
     761,   764,   765,   771,   775,   777,   779,   783,   788,   793,
     794,   801,   804,   806,   808,   810,   812,   814,   816,   818,
     820,   822,   824,   827,   832,   837,   842,   847,   852,   853,
     859,   863,   865,   867,   869,   871,   873,   875,   877,   879,
     881,   883,   885,   890,   895,   900,   901,   908,   911,   913,
     915,   917,   919,   922,   927,   932,   937,   943,   946,   948,
     950,   952,   957,   958,   965,   968,   970,   972,   974,   976,
     979,   984,   989,   990,   996,  1000,  1002,  1004,  1006,  1008,
    1010,  1012,  1014,  1016,  1018,  1020,  1022,  1023,  1030,  1033,
    1035,  1037,  1039,  1042,  1047,  1048,  1054,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1072,  1074,  1076,  1078,  1080,  1081,
    1088,  1091,  1093,  1095,  1097,  1099,  1101,  1103,  1105,  1107,
    1109,  1111,  1113,  1115,  1117,  1119,  1122,  1127,  1132,  1137,
    1142,  1147,  1152,  1157,  1162,  1163,  1169,  1173,  1175,  1177,
    1179,  1184,  1189,  1194,  1199,  1204,  1205,  1212,  1213,  1219,
    1223,  1225,  1227,  1230,  1232,  1234,  1236,  1238,  1240,  1245,
    1250,  1251,  1258,  1261,  1263,  1265,  1267,  1269,  1274,  1279,
    1285,  1288,  1290,  1292,  1294,  1299,  1300,  1307,  1308,  1314,
    1318,  1320,  1322,  1325,  1327,  1329,  1331,  1333,  1335,  1340,
    1345,  1351,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,
    1370,  1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,
    1390,  1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,  1408,
    1410,  1412,  1414,  1416,  1418,  1420,  1422,  1424,  1426,  1428,
    1430,  1432,  1434,  1436,  1438,  1440,  1442,  1444,  1446,  1448,
    1450,  1452,  1454,  1456,  1461,  1466,  1471,  1476,  1481,  1486,
    1491,  1496,  1501,  1506,  1511,  1516,  1521,  1526,  1531,  1536,
    1541,  1546,  1551,  1556,  1561,  1566,  1571,  1576,  1581,  1586,
    1591,  1596,  1601,  1606,  1611,  1616,  1621,  1626,  1631,  1636,
    1641,  1646,  1651,  1656,  1661,  1666,  1671,  1676,  1681,  1686,
    1687,  1693,  1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,
    1713,  1715,  1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,
    1733,  1735,  1737,  1739,  1740,  1746,  1750,  1752,  1754,  1756,
    1758,  1760,  1762,  1764,  1766,  1768,  1770,  1772,  1774,  1776,
    1778,  1780,  1782,  1784,  1786,  1788,  1790,  1792,  1797,  1802,
    1807,  1813,  1816,  1818,  1820,  1822,  1824,  1826,  1828,  1830,
    1832,  1834,  1836,  1838,  1840,  1842,  1844,  1846,  1848,  1853,
    1858,  1863,  1868,  1873,  1878,  1883,  1888,  1893,  1898,  1903,
    1908,  1913,  1918,  1924,  1927,  1929,  1931,  1933,  1935,  1937,
    1939,  1941,  1943,  1948,  1953,  1958,  1963,  1968
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     231,     0,    -1,    -1,   231,   232,    -1,   266,    -1,   272,
      -1,   286,    -1,   496,    -1,   304,    -1,   328,    -1,   342,
      -1,   242,    -1,   513,    -1,   358,    -1,   365,    -1,   369,
      -1,   379,    -1,   388,    -1,   408,    -1,   418,    -1,   424,
      -1,   438,    -1,   428,    -1,   237,    -1,     1,   225,    -1,
       1,   226,    -1,    -1,   234,    -1,   105,   233,    -1,   105,
     144,   233,    -1,   105,   145,   233,    -1,   105,   146,   233,
      -1,   105,   147,   233,    -1,   105,   148,   233,    -1,   105,
     149,   233,    -1,   105,   150,   233,    -1,    -1,   236,    -1,
     105,   235,    -1,   105,     9,   235,    -1,   105,    10,   235,
      -1,   105,    11,   235,    -1,    94,   227,   238,   226,   225,
      -1,   238,   239,    -1,   239,    -1,   240,    -1,   241,    -1,
       1,   225,    -1,    93,   228,   124,   225,    -1,   119,   228,
     124,   225,    -1,   154,   227,   243,   226,   225,    -1,   243,
     244,    -1,   244,    -1,   255,    -1,   260,    -1,   265,    -1,
     257,    -1,   258,    -1,   259,    -1,   262,    -1,   263,    -1,
     264,    -1,   253,    -1,   252,    -1,   261,    -1,   256,    -1,
     251,    -1,   245,    -1,   246,    -1,   254,    -1,     1,   225,
      -1,   138,   228,   247,   225,    -1,   139,   228,   249,   225,
      -1,   247,   229,   248,    -1,   248,    -1,   140,    -1,   141,
      -1,   249,   229,   250,    -1,   250,    -1,   140,    -1,   141,
      -1,   136,   228,   124,   225,    -1,   134,   228,   124,   225,
      -1,   137,   228,   124,   225,    -1,   179,   228,   124,   225,
      -1,    95,   228,   124,   225,    -1,   155,   228,   124,   225,
      -1,    24,   228,   124,   225,    -1,    98,   228,   124,   225,
      -1,    97,   228,   124,   225,    -1,   218,   228,   124,   225,
      -1,   219,   228,   124,   225,    -1,   189,   228,   105,   225,
      -1,    80,   228,   105,   225,    -1,    84,   228,   105,   225,
      -1,    57,   228,   168,   225,    -1,     4,   227,   267,   226,
     225,    -1,   267,   268,    -1,   268,    -1,   269,    -1,   271,
      -1,   270,    -1,     1,   225,    -1,    95,   228,   124,   225,
      -1,    31,   228,   124,   225,    -1,    24,   228,   124,   225,
      -1,    71,   227,   273,   226,   225,    -1,   273,   274,    -1,
     274,    -1,   275,    -1,   276,    -1,     1,   225,    -1,   217,
     228,   168,   225,    -1,    -1,   277,   223,   227,   278,   226,
     225,    -1,   278,   279,    -1,   279,    -1,   280,    -1,   282,
      -1,   281,    -1,     1,   225,    -1,    95,   228,   124,   225,
      -1,   222,   228,   236,   225,    -1,   222,   228,   204,   225,
      -1,    -1,   159,   283,   228,   284,   225,    -1,   284,   229,
     285,    -1,   285,    -1,   215,    -1,   108,    -1,    40,    -1,
     182,    -1,    64,    -1,    62,    -1,   181,    -1,    -1,   108,
     287,   227,   288,   226,   225,    -1,   288,   289,    -1,   289,
      -1,   290,    -1,   291,    -1,   292,    -1,   296,    -1,   295,
      -1,   293,    -1,   294,    -1,   300,    -1,     1,   225,    -1,
      95,   228,   124,   225,    -1,   215,   228,   124,   225,    -1,
     118,   228,   124,   225,    -1,    32,   228,   168,   225,    -1,
     135,   228,   124,   225,    -1,    17,   228,   124,   225,    -1,
      -1,   201,   297,   228,   298,   225,    -1,   298,   229,   299,
      -1,   299,    -1,   174,    -1,   177,    -1,   178,    -1,   180,
      -1,   181,    -1,   184,    -1,    51,    -1,   198,    -1,   190,
      -1,   194,    -1,   202,    -1,   199,    -1,   183,    -1,   192,
      -1,   196,    -1,   185,    -1,   208,    -1,   175,    -1,   176,
      -1,   188,    -1,    -1,    36,   301,   228,   302,   225,    -1,
     302,   229,   303,    -1,   303,    -1,    47,    -1,   131,    -1,
      64,    -1,   214,    -1,   182,    -1,   203,    -1,   220,    -1,
      40,    -1,    25,    -1,   209,    -1,   130,    -1,     4,    -1,
     100,    -1,   192,    -1,   207,    -1,   112,    -1,   132,    -1,
     197,    -1,    93,    -1,    -1,    17,   305,   227,   306,   226,
     225,    -1,   306,   307,    -1,   307,    -1,   308,    -1,   319,
      -1,   320,    -1,   309,    -1,   310,    -1,   321,    -1,   311,
      -1,   312,    -1,   313,    -1,   314,    -1,   315,    -1,   316,
      -1,   317,    -1,   318,    -1,   322,    -1,   323,    -1,   324,
      -1,     1,   225,    -1,    95,   228,   124,   225,    -1,   121,
     228,   234,   225,    -1,   122,   228,   234,   225,    -1,   107,
     228,   105,   225,    -1,    19,   228,   234,   225,    -1,    82,
     228,   105,   225,    -1,    76,   228,   105,   225,    -1,    78,
     228,   105,   225,    -1,    77,   228,   105,   225,    -1,   151,
     228,   236,   225,    -1,   193,   228,   236,   225,    -1,    15,
     228,   105,   225,    -1,    16,   228,   105,   225,    -1,   106,
     228,   105,   225,    -1,    89,   228,   234,   225,    -1,    90,
     228,   234,   225,    -1,    -1,    36,   325,   228,   326,   225,
      -1,   326,   229,   327,    -1,   327,    -1,    91,    -1,    92,
      -1,    -1,    70,   329,   227,   334,   226,   225,    -1,    -1,
      36,   331,   228,   332,   225,    -1,   332,   229,   333,    -1,
     333,    -1,   200,    -1,    51,    -1,   195,    -1,   334,   335,
      -1,   335,    -1,   336,    -1,   330,    -1,   340,    -1,   341,
      -1,     1,   225,    -1,    -1,   123,   228,   338,   337,   225,
      -1,   338,   229,   339,    -1,   339,    -1,   105,    -1,   105,
     172,   105,    -1,    61,   228,   124,   225,    -1,    56,   228,
     124,   225,    -1,    -1,    48,   343,   227,   344,   226,   225,
      -1,   344,   345,    -1,   345,    -1,   346,    -1,   347,    -1,
     348,    -1,   351,    -1,   355,    -1,   356,    -1,   357,    -1,
     350,    -1,   349,    -1,     1,   225,    -1,   215,   228,   124,
     225,    -1,   118,   228,   124,   225,    -1,    17,   228,   124,
     225,    -1,   224,   228,   124,   225,    -1,    32,   228,   168,
     225,    -1,    -1,    36,   352,   228,   353,   225,    -1,   353,
     229,   354,    -1,   354,    -1,   162,    -1,    33,    -1,    65,
      -1,    49,    -1,    13,    -1,   104,    -1,    43,    -1,   143,
      -1,    96,    -1,   191,    -1,   161,   228,   124,   225,    -1,
     128,   228,   124,   225,    -1,   127,   228,   105,   225,    -1,
      -1,   142,   359,   227,   360,   226,   225,    -1,   360,   361,
      -1,   361,    -1,   362,    -1,   363,    -1,   364,    -1,     1,
     225,    -1,   126,   228,   124,   225,    -1,    14,   228,   124,
     225,    -1,    99,   228,   124,   225,    -1,   210,   227,   366,
     226,   225,    -1,   366,   367,    -1,   367,    -1,   368,    -1,
       1,    -1,    95,   228,   124,   225,    -1,    -1,   157,   370,
     227,   371,   226,   225,    -1,   371,   372,    -1,   372,    -1,
     373,    -1,   374,    -1,   375,    -1,     1,   225,    -1,    95,
     228,   124,   225,    -1,   215,   228,   124,   225,    -1,    -1,
     159,   376,   228,   377,   225,    -1,   377,   229,   378,    -1,
     378,    -1,    64,    -1,   214,    -1,   182,    -1,   203,    -1,
     220,    -1,   206,    -1,   142,    -1,   205,    -1,   188,    -1,
     173,    -1,    -1,   158,   380,   227,   381,   226,   225,    -1,
     381,   382,    -1,   382,    -1,   383,    -1,   384,    -1,     1,
     225,    -1,    95,   228,   124,   225,    -1,    -1,   159,   385,
     228,   386,   225,    -1,   386,   229,   387,    -1,   387,    -1,
      64,    -1,   214,    -1,   182,    -1,   203,    -1,   220,    -1,
     206,    -1,   142,    -1,   205,    -1,   188,    -1,   173,    -1,
      -1,    18,   389,   227,   390,   226,   225,    -1,   390,   391,
      -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,   395,
      -1,   396,    -1,   398,    -1,   397,    -1,   407,    -1,   399,
      -1,   404,    -1,   405,    -1,   406,    -1,   403,    -1,     1,
     225,    -1,    95,   228,   124,   225,    -1,    56,   228,   124,
     225,    -1,   218,   228,   124,   225,    -1,   152,   228,   124,
     225,    -1,     3,   228,   124,   225,    -1,   123,   228,   105,
     225,    -1,     5,   228,   186,   225,    -1,     5,   228,   187,
     225,    -1,    -1,    36,   400,   228,   401,   225,    -1,   401,
     229,   402,    -1,   402,    -1,     8,    -1,   200,    -1,    32,
     228,   168,   225,    -1,    58,   228,   124,   225,    -1,    68,
     228,   124,   225,    -1,    17,   228,   124,   225,    -1,   179,
     228,   124,   225,    -1,    -1,    62,   409,   227,   414,   226,
     225,    -1,    -1,   159,   411,   228,   412,   225,    -1,   412,
     229,   413,    -1,   413,    -1,   129,    -1,   414,   415,    -1,
     415,    -1,   416,    -1,   417,    -1,   410,    -1,     1,    -1,
     215,   228,   124,   225,    -1,   126,   228,   124,   225,    -1,
      -1,    23,   419,   227,   420,   226,   225,    -1,   420,   421,
      -1,   421,    -1,   422,    -1,   423,    -1,     1,    -1,    61,
     228,   124,   225,    -1,   126,   228,   124,   225,    -1,    34,
     227,   425,   226,   225,    -1,   425,   426,    -1,   426,    -1,
     427,    -1,     1,    -1,    61,   228,   124,   225,    -1,    -1,
      38,   429,   227,   434,   226,   225,    -1,    -1,   159,   431,
     228,   432,   225,    -1,   432,   229,   433,    -1,   433,    -1,
     129,    -1,   434,   435,    -1,   435,    -1,   436,    -1,   437,
      -1,   430,    -1,     1,    -1,    95,   228,   124,   225,    -1,
     126,   228,   124,   225,    -1,    39,   227,   439,   226,   225,
      -1,   439,   440,    -1,   440,    -1,   449,    -1,   450,    -1,
     452,    -1,   453,    -1,   454,    -1,   455,    -1,   456,    -1,
     457,    -1,   458,    -1,   459,    -1,   448,    -1,   461,    -1,
     462,    -1,   477,    -1,   464,    -1,   466,    -1,   468,    -1,
     467,    -1,   471,    -1,   465,    -1,   472,    -1,   473,    -1,
     474,    -1,   475,    -1,   476,    -1,   489,    -1,   478,    -1,
     479,    -1,   480,    -1,   485,    -1,   469,    -1,   470,    -1,
     495,    -1,   493,    -1,   494,    -1,   451,    -1,   484,    -1,
     460,    -1,   482,    -1,   483,    -1,   447,    -1,   442,    -1,
     443,    -1,   444,    -1,   445,    -1,   446,    -1,   463,    -1,
     441,    -1,   481,    -1,     1,    -1,    85,   228,   105,   225,
      -1,    42,   228,   168,   225,    -1,    41,   228,   234,   225,
      -1,    44,   228,   234,   225,    -1,    45,   228,   105,   225,
      -1,    46,   228,   105,   225,    -1,   156,   228,   168,   225,
      -1,    63,   228,   234,   225,    -1,    55,   228,   168,   225,
      -1,    59,   228,   168,   225,    -1,    28,   228,   168,   225,
      -1,    35,   228,   168,   225,    -1,     6,   228,   168,   225,
      -1,    81,   228,   234,   225,    -1,    79,   228,   105,   225,
      -1,    72,   228,   105,   225,    -1,     7,   228,   234,   225,
      -1,   171,   228,   234,   225,    -1,   170,   228,   234,   225,
      -1,    50,   228,   105,   225,    -1,    60,   228,   168,   225,
      -1,   221,   228,   168,   225,    -1,   163,   228,   168,   225,
      -1,   166,   228,   168,   225,    -1,   167,   228,   168,   225,
      -1,   165,   228,   168,   225,    -1,   165,   228,   169,   225,
      -1,   164,   228,   168,   225,    -1,   164,   228,   169,   225,
      -1,   116,   228,   234,   225,    -1,    12,   228,   234,   225,
      -1,   109,   228,   168,   225,    -1,   117,   228,   234,   225,
      -1,   160,   228,   168,   225,    -1,   103,   228,   168,   225,
      -1,   213,   228,   168,   225,    -1,   111,   228,   168,   225,
      -1,    86,   228,   124,   225,    -1,    29,   228,   105,   225,
      -1,    83,   228,   105,   225,    -1,   216,   228,   168,   225,
      -1,    30,   228,   124,   225,    -1,   211,   228,   124,   225,
      -1,   120,   228,   168,   225,    -1,    26,   228,   168,   225,
      -1,   212,   228,   234,   225,    -1,    -1,   113,   486,   228,
     487,   225,    -1,   487,   229,   488,    -1,   488,    -1,   174,
      -1,   177,    -1,   178,    -1,   180,    -1,   181,    -1,   184,
      -1,    51,    -1,   198,    -1,   190,    -1,   194,    -1,   202,
      -1,   199,    -1,   183,    -1,   192,    -1,   196,    -1,   185,
      -1,   208,    -1,   175,    -1,   176,    -1,   188,    -1,    -1,
     110,   490,   228,   491,   225,    -1,   491,   229,   492,    -1,
     492,    -1,   174,    -1,   177,    -1,   178,    -1,   180,    -1,
     181,    -1,   184,    -1,   198,    -1,    51,    -1,   190,    -1,
     194,    -1,   202,    -1,   199,    -1,   183,    -1,   192,    -1,
     196,    -1,   185,    -1,   208,    -1,   175,    -1,   176,    -1,
     188,    -1,    87,   228,   105,   225,    -1,    88,   228,   105,
     225,    -1,    20,   228,   105,   225,    -1,    14,   227,   497,
     226,   225,    -1,   497,   498,    -1,   498,    -1,   506,    -1,
     501,    -1,   502,    -1,   503,    -1,   504,    -1,   505,    -1,
     507,    -1,   508,    -1,   509,    -1,   500,    -1,   510,    -1,
     511,    -1,   512,    -1,   499,    -1,     1,    -1,    27,   228,
     168,   225,    -1,   133,   228,   168,   225,    -1,    66,   228,
     234,   225,    -1,    67,   228,   234,   225,    -1,    75,   228,
     105,   225,    -1,    74,   228,   105,   225,    -1,   125,   228,
     168,   225,    -1,    73,   228,   105,   225,    -1,    22,   228,
     105,   225,    -1,    21,   228,   105,   225,    -1,   101,   228,
     168,   225,    -1,   102,   228,   168,   225,    -1,   114,   228,
     105,   225,    -1,   115,   228,   234,   225,    -1,   153,   227,
     514,   226,   225,    -1,   514,   515,    -1,   515,    -1,   516,
      -1,   517,    -1,   519,    -1,   520,    -1,   518,    -1,   521,
      -1,     1,    -1,    37,   228,   168,   225,    -1,    54,   228,
     168,   225,    -1,    52,   228,   124,   225,    -1,    69,   228,
     234,   225,    -1,    51,   228,   168,   225,    -1,    53,   228,
     168,   225,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   339,   339,   340,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   357,   358,
     359,   360,   361,   362,   363,   364,   368,   368,   369,   373,
     377,   381,   385,   389,   393,   397,   405,   405,   406,   407,
     408,   409,   416,   419,   419,   420,   420,   420,   422,   428,
     435,   437,   437,   438,   438,   439,   439,   440,   440,   441,
     441,   442,   443,   444,   444,   445,   445,   446,   446,   447,
     448,   451,   452,   454,   454,   455,   461,   469,   469,   470,
     476,   484,   526,   585,   613,   621,   636,   651,   660,   674,
     683,   711,   741,   766,   788,   810,   819,   821,   821,   822,
     822,   823,   823,   825,   834,   843,   855,   856,   856,   858,
     858,   859,   861,   868,   868,   878,   879,   881,   881,   882,
     882,   884,   889,   892,   898,   897,   903,   903,   904,   908,
     912,   916,   920,   924,   928,   939,   938,  1036,  1036,  1037,
    1037,  1037,  1038,  1038,  1038,  1039,  1039,  1039,  1041,  1050,
    1087,  1099,  1110,  1152,  1162,  1161,  1167,  1167,  1168,  1172,
    1176,  1180,  1184,  1188,  1192,  1196,  1200,  1204,  1208,  1212,
    1216,  1220,  1224,  1228,  1232,  1236,  1240,  1244,  1251,  1250,
    1256,  1256,  1257,  1261,  1265,  1269,  1273,  1277,  1281,  1285,
    1289,  1293,  1297,  1301,  1305,  1309,  1313,  1317,  1321,  1325,
    1329,  1340,  1339,  1396,  1396,  1397,  1398,  1398,  1399,  1400,
    1401,  1402,  1403,  1404,  1405,  1406,  1407,  1408,  1408,  1409,
    1410,  1411,  1412,  1414,  1423,  1429,  1435,  1441,  1447,  1453,
    1459,  1465,  1471,  1477,  1484,  1490,  1496,  1502,  1511,  1521,
    1520,  1526,  1526,  1527,  1531,  1541,  1540,  1557,  1556,  1561,
    1561,  1562,  1566,  1570,  1578,  1578,  1579,  1579,  1579,  1579,
    1579,  1581,  1581,  1583,  1583,  1585,  1599,  1619,  1628,  1641,
    1640,  1710,  1710,  1711,  1711,  1711,  1711,  1712,  1712,  1712,
    1713,  1713,  1713,  1715,  1750,  1763,  1772,  1778,  1790,  1789,
    1793,  1793,  1794,  1798,  1802,  1806,  1810,  1814,  1818,  1822,
    1826,  1830,  1836,  1855,  1865,  1879,  1878,  1894,  1894,  1895,
    1895,  1895,  1895,  1897,  1906,  1921,  1934,  1936,  1936,  1937,
    1937,  1939,  1955,  1954,  1970,  1970,  1971,  1971,  1971,  1971,
    1973,  1982,  2005,  2004,  2010,  2010,  2011,  2015,  2019,  2023,
    2027,  2031,  2035,  2039,  2043,  2047,  2057,  2056,  2073,  2073,
    2074,  2074,  2074,  2076,  2083,  2082,  2088,  2088,  2089,  2093,
    2097,  2101,  2105,  2109,  2113,  2117,  2121,  2125,  2135,  2134,
    2185,  2185,  2186,  2186,  2186,  2187,  2187,  2188,  2188,  2188,
    2189,  2189,  2189,  2190,  2190,  2191,  2193,  2202,  2211,  2237,
    2256,  2275,  2281,  2285,  2294,  2293,  2297,  2297,  2298,  2302,
    2308,  2319,  2330,  2341,  2350,  2369,  2368,  2434,  2433,  2437,
    2437,  2438,  2444,  2444,  2445,  2445,  2445,  2445,  2447,  2466,
    2476,  2475,  2500,  2500,  2501,  2501,  2501,  2503,  2509,  2518,
    2520,  2520,  2521,  2521,  2523,  2542,  2541,  2589,  2588,  2592,
    2592,  2593,  2599,  2599,  2600,  2600,  2600,  2600,  2602,  2608,
    2617,  2620,  2620,  2621,  2621,  2622,  2622,  2623,  2623,  2624,
    2624,  2625,  2625,  2626,  2627,  2628,  2628,  2629,  2629,  2630,
    2630,  2631,  2631,  2632,  2632,  2633,  2633,  2634,  2635,  2635,
    2636,  2636,  2637,  2637,  2638,  2638,  2639,  2639,  2640,  2641,
    2641,  2642,  2643,  2644,  2644,  2645,  2645,  2646,  2647,  2648,
    2649,  2649,  2650,  2653,  2658,  2664,  2670,  2676,  2681,  2686,
    2691,  2696,  2701,  2706,  2711,  2716,  2721,  2726,  2731,  2736,
    2741,  2746,  2752,  2763,  2768,  2773,  2778,  2783,  2788,  2791,
    2796,  2799,  2804,  2809,  2814,  2819,  2824,  2829,  2834,  2839,
    2844,  2855,  2860,  2865,  2870,  2879,  2888,  2893,  2898,  2904,
    2903,  2908,  2908,  2909,  2912,  2915,  2918,  2921,  2924,  2927,
    2930,  2933,  2936,  2939,  2942,  2945,  2948,  2951,  2954,  2957,
    2960,  2963,  2966,  2972,  2971,  2976,  2976,  2977,  2980,  2983,
    2986,  2989,  2992,  2995,  2998,  3001,  3004,  3007,  3010,  3013,
    3016,  3019,  3022,  3025,  3028,  3031,  3034,  3039,  3044,  3049,
    3058,  3061,  3061,  3062,  3063,  3063,  3064,  3064,  3065,  3065,
    3066,  3067,  3067,  3068,  3069,  3069,  3070,  3070,  3072,  3077,
    3082,  3087,  3092,  3097,  3102,  3107,  3112,  3117,  3122,  3127,
    3132,  3137,  3145,  3148,  3148,  3149,  3149,  3150,  3151,  3151,
    3152,  3153,  3155,  3161,  3167,  3176,  3190,  3196
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
  "MAX_NICK_CHANGES", "MAX_NICK_LENGTH", "MAX_NICK_TIME", "MAX_NUMBER",
  "MAX_TARGETS", "MAX_TOPIC_LENGTH", "MAX_WATCH", "MESSAGE_LOCALE",
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MIN_IDLE", "MAX_IDLE",
  "RANDOM_IDLE", "HIDE_IDLE_FROM_OPERS", "MODULE", "MODULES", "NAME",
  "NEED_PASSWORD", "NETWORK_DESC", "NETWORK_NAME", "NICK", "NICK_CHANGES",
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
  "SECONDS", "MINUTES", "HOURS", "DAYS", "WEEKS", "MONTHS", "YEARS",
  "SENDQ", "SEND_PASSWORD", "SERVERHIDE", "SERVERINFO", "IRCD_SID",
  "TKLINE_EXPIRE_NOTICES", "T_SHARED", "T_CLUSTER", "TYPE", "SHORT_MOTD",
  "SPOOF", "SPOOF_NOTICE", "STATS_E_DISABLED", "STATS_I_OPER_ONLY",
  "STATS_K_OPER_ONLY", "STATS_O_OPER_ONLY", "STATS_P_OPER_ONLY", "TBOOL",
  "TMASKED", "TS_MAX_DELTA", "TS_WARN_DELTA", "TWODOTS", "T_ALL", "T_BOTS",
  "T_SOFTCALLERID", "T_CALLERID", "T_CCONN", "T_CCONN_FULL",
  "T_SSL_CIPHER_LIST", "T_DEAF", "T_DEBUG", "T_DLINE", "T_EXTERNAL",
  "T_FULL", "T_INVISIBLE", "T_IPV4", "T_IPV6", "T_LOCOPS", "T_MAX_CLIENTS",
  "T_NCHANGE", "T_NO_JOIN", "T_OPERWALL", "T_RECVQ", "T_REJ", "T_SERVER",
  "T_SERVNOTICE", "T_SET", "T_SKILL", "T_SPY", "T_SSL", "T_UMODES",
  "T_UNAUTH", "T_UNDLINE", "T_UNLIMITED", "T_UNRESV", "T_UNXLINE",
  "T_GLOBOPS", "T_WALLOP", "T_RESTART", "T_SERVICE", "T_SERVICES_NAME",
  "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE", "USER", "USE_EGD",
  "USE_LOGGING", "VHOST", "VHOST6", "XLINE", "WARN_NO_NLINE", "T_SIZE",
  "T_FILE", "COUNTRY_CODE", "';'", "'}'", "'{'", "'='", "','", "$accept",
  "conf", "conf_item", "timespec_", "timespec", "sizespec_", "sizespec",
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
  "serverinfo_max_clients", "serverinfo_max_nick_length",
  "serverinfo_max_topic_length", "serverinfo_hub", "admin_entry",
  "admin_items", "admin_item", "admin_name", "admin_email",
  "admin_description", "logging_entry", "logging_items", "logging_item",
  "logging_use_logging", "logging_file_entry", "$@1", "logging_file_items",
  "logging_file_item", "logging_file_name", "logging_file_size",
  "logging_file_type", "$@2", "logging_file_type_items",
  "logging_file_type_item", "oper_entry", "$@3", "oper_items", "oper_item",
  "oper_name", "oper_user", "oper_password", "oper_encrypted",
  "oper_rsa_public_key_file", "oper_class", "oper_umodes", "$@4",
  "oper_umodes_items", "oper_umodes_item", "oper_flags", "$@5",
  "oper_flags_items", "oper_flags_item", "class_entry", "$@6",
  "class_items", "class_item", "class_name", "class_ping_time",
  "class_ping_warning", "class_number_per_ip", "class_connectfreq",
  "class_max_number", "class_max_global", "class_max_local",
  "class_max_ident", "class_sendq", "class_recvq",
  "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
  "class_number_per_cidr", "class_min_idle", "class_max_idle",
  "class_flags", "$@7", "class_flags_items", "class_flags_item",
  "listen_entry", "$@8", "listen_flags", "$@9", "listen_flags_items",
  "listen_flags_item", "listen_items", "listen_item", "listen_port",
  "$@10", "port_items", "port_item", "listen_address", "listen_host",
  "auth_entry", "$@11", "auth_items", "auth_item", "auth_user",
  "auth_passwd", "auth_class", "auth_country_code", "auth_encrypted",
  "auth_flags", "$@12", "auth_flags_items", "auth_flags_item",
  "auth_spoof", "auth_redir_serv", "auth_redir_port", "resv_entry", "$@13",
  "resv_items", "resv_item", "resv_creason", "resv_channel", "resv_nick",
  "service_entry", "service_items", "service_item", "service_name",
  "shared_entry", "$@14", "shared_items", "shared_item", "shared_name",
  "shared_user", "shared_type", "$@15", "shared_types", "shared_type_item",
  "cluster_entry", "$@16", "cluster_items", "cluster_item", "cluster_name",
  "cluster_type", "$@17", "cluster_types", "cluster_type_item",
  "connect_entry", "$@18", "connect_items", "connect_item", "connect_name",
  "connect_host", "connect_vhost", "connect_send_password",
  "connect_accept_password", "connect_port", "connect_aftype",
  "connect_flags", "$@19", "connect_flags_items", "connect_flags_item",
  "connect_encrypted", "connect_hub_mask", "connect_leaf_mask",
  "connect_class", "connect_ssl_cipher_list", "kill_entry", "$@20",
  "kill_type", "$@21", "kill_type_items", "kill_type_item", "kill_items",
  "kill_item", "kill_user", "kill_reason", "deny_entry", "$@22",
  "deny_items", "deny_item", "deny_ip", "deny_reason", "exempt_entry",
  "exempt_items", "exempt_item", "exempt_ip", "gecos_entry", "$@23",
  "gecos_flags", "$@24", "gecos_flags_items", "gecos_flags_item",
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
  "general_oper_umodes", "$@25", "umode_oitems", "umode_oitem",
  "general_oper_only_umodes", "$@26", "umode_items", "umode_item",
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
     465,   466,   467,   468,   469,   470,   471,   472,   473,   474,
     475,   476,   477,   478,   479,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   230,   231,   231,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   234,   234,   234,   234,   235,   235,   236,   236,
     236,   236,   237,   238,   238,   239,   239,   239,   240,   241,
     242,   243,   243,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   245,   246,   247,   247,   248,   248,   249,   249,   250,
     250,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   265,   266,   267,   267,   268,
     268,   268,   268,   269,   270,   271,   272,   273,   273,   274,
     274,   274,   275,   277,   276,   278,   278,   279,   279,   279,
     279,   280,   281,   281,   283,   282,   284,   284,   285,   285,
     285,   285,   285,   285,   285,   287,   286,   288,   288,   289,
     289,   289,   289,   289,   289,   289,   289,   289,   290,   291,
     292,   293,   294,   295,   297,   296,   298,   298,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   301,   300,
     302,   302,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   305,   304,   306,   306,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   325,
     324,   326,   326,   327,   327,   329,   328,   331,   330,   332,
     332,   333,   333,   333,   334,   334,   335,   335,   335,   335,
     335,   337,   336,   338,   338,   339,   339,   340,   341,   343,
     342,   344,   344,   345,   345,   345,   345,   345,   345,   345,
     345,   345,   345,   346,   347,   348,   349,   350,   352,   351,
     353,   353,   354,   354,   354,   354,   354,   354,   354,   354,
     354,   354,   355,   356,   357,   359,   358,   360,   360,   361,
     361,   361,   361,   362,   363,   364,   365,   366,   366,   367,
     367,   368,   370,   369,   371,   371,   372,   372,   372,   372,
     373,   374,   376,   375,   377,   377,   378,   378,   378,   378,
     378,   378,   378,   378,   378,   378,   380,   379,   381,   381,
     382,   382,   382,   383,   385,   384,   386,   386,   387,   387,
     387,   387,   387,   387,   387,   387,   387,   387,   389,   388,
     390,   390,   391,   391,   391,   391,   391,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   392,   393,   394,   395,
     396,   397,   398,   398,   400,   399,   401,   401,   402,   402,
     403,   404,   405,   406,   407,   409,   408,   411,   410,   412,
     412,   413,   414,   414,   415,   415,   415,   415,   416,   417,
     419,   418,   420,   420,   421,   421,   421,   422,   423,   424,
     425,   425,   426,   426,   427,   429,   428,   431,   430,   432,
     432,   433,   434,   434,   435,   435,   435,   435,   436,   437,
     438,   439,   439,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   440,   440,   440,   440,   440,   440,   440,
     440,   440,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   466,
     467,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   482,   483,   484,   486,
     485,   487,   487,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   488,   488,   488,   488,   488,   488,   488,
     488,   488,   488,   490,   489,   491,   491,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   492,   492,   492,
     492,   492,   492,   492,   492,   492,   492,   493,   494,   495,
     496,   497,   497,   498,   498,   498,   498,   498,   498,   498,
     498,   498,   498,   498,   498,   498,   498,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,   514,   515,   515,   515,   515,   515,
     515,   515,   516,   517,   518,   519,   520,   521
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     2,     3,
       3,     3,     3,     3,     3,     3,     0,     1,     2,     3,
       3,     3,     5,     2,     1,     1,     1,     2,     4,     4,
       5,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     3,     1,     1,     1,     3,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     2,     4,     4,     4,     5,     2,     1,     1,
       1,     2,     4,     0,     6,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     0,     5,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     0,
       5,     3,     1,     1,     1,     0,     6,     0,     5,     3,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     1,
       2,     0,     5,     3,     1,     1,     3,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       2,     0,     1,     0,     0,     0,   201,   368,   420,     0,
     435,     0,   269,   405,   245,     0,     0,   135,   305,     0,
       0,   322,   346,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   617,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   602,   616,   612,   604,   605,   606,   607,   608,
     603,   609,   610,   611,   613,   614,   615,     0,     0,     0,
     433,     0,     0,   431,   432,     0,   502,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   573,     0,   549,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   452,   500,   494,
     495,   496,   497,   498,   493,   463,   453,   454,   488,   455,
     456,   457,   458,   459,   460,   461,   462,   490,   464,   465,
     499,   467,   472,   468,   470,   469,   483,   484,   471,   473,
     474,   475,   476,   477,   466,   479,   480,   481,   501,   491,
     492,   489,   482,   478,   486,   487,   485,     0,     0,     0,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,    44,    45,    46,     0,     0,   641,     0,     0,     0,
       0,     0,     0,     0,   634,   635,   636,   639,   637,   638,
     640,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    67,    68,    66,    63,    62,    69,    53,    65,    56,
      57,    58,    54,    64,    59,    60,    61,    55,     0,     0,
     320,     0,     0,   318,   319,   102,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   601,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   208,   209,
     211,   212,   213,   214,   215,   216,   217,   218,   206,   207,
     210,   219,   220,   221,     0,     0,     0,     0,     0,   394,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   371,
     372,   373,   374,   375,   376,   378,   377,   380,   384,   381,
     382,   383,   379,   426,     0,     0,     0,   423,   424,   425,
       0,     0,   430,   447,     0,     0,   437,   446,     0,   443,
     444,   445,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   451,     0,     0,     0,   288,     0,     0,     0,
       0,     0,     0,     0,   272,   273,   274,   275,   281,   280,
     276,   277,   278,   279,   417,     0,   407,     0,   416,     0,
     413,   414,   415,     0,   247,     0,     0,     0,   257,     0,
     255,   256,   258,   259,   111,     0,     0,   107,     0,    47,
       0,     0,     0,    43,     0,     0,     0,   178,     0,     0,
       0,   154,     0,     0,   138,   139,   140,   141,   144,   145,
     143,   142,   146,     0,     0,     0,     0,     0,   308,   309,
     310,   311,     0,     0,     0,     0,     0,     0,     0,   633,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    51,
       0,     0,   332,     0,     0,   325,   326,   327,   328,     0,
       0,   354,     0,   349,   350,   351,     0,     0,   317,     0,
       0,     0,    96,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   222,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   203,   385,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   370,     0,     0,     0,   422,     0,
     429,     0,     0,     0,     0,   442,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   450,   282,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   271,
       0,     0,     0,     0,   412,   260,     0,     0,     0,     0,
       0,   254,     0,   106,     0,     0,     0,    42,   147,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   137,   312,
       0,     0,     0,     0,   307,     0,     0,     0,     0,     0,
       0,   632,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    75,    76,     0,    74,    79,    80,     0,    78,
       0,     0,     0,     0,     0,    50,   329,     0,     0,     0,
       0,   324,   352,     0,     0,     0,   348,     0,   316,   105,
     104,   103,   627,   626,   618,    26,    26,    26,    26,    26,
      26,    26,    28,    27,   620,   621,   625,   623,   622,   628,
     629,   630,   631,   624,   619,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,     0,     0,   202,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   369,     0,
       0,   421,   434,     0,     0,     0,   436,   515,   519,   533,
     599,   547,   513,   541,   544,   514,   505,   504,   506,   507,
     508,   522,   511,   512,   523,   510,   518,   517,   516,   542,
     503,   540,   597,   598,   537,   534,   584,   577,   594,   595,
     578,   579,   580,   581,   589,   582,   592,   596,   585,   590,
     586,   591,   583,   588,   587,   593,     0,   576,   539,   559,
     553,   570,   571,   554,   555,   556,   557,   565,   558,   568,
     572,   561,   566,   562,   567,   560,   564,   563,   569,     0,
     552,   532,   535,   546,   509,   536,   525,   530,   531,   528,
     529,   526,   527,   521,   520,   545,   548,   538,   543,   524,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   270,
       0,     0,     0,   406,     0,     0,     0,   265,   261,   264,
     246,   112,     0,     0,   124,     0,     0,   116,   117,   119,
     118,    48,    49,     0,     0,     0,     0,     0,     0,     0,
       0,   136,     0,     0,     0,   306,   642,   646,   644,   647,
     643,   645,    87,    95,    93,    94,    85,    89,    88,    82,
      81,    83,    71,     0,    72,     0,    86,    84,    92,    90,
      91,     0,     0,     0,   323,     0,     0,   347,   321,    29,
      30,    31,    32,    33,    34,    35,   234,   235,   227,   243,
     244,     0,   242,   229,   231,   230,   228,   237,   238,   223,
     236,   226,   224,   225,    36,    36,    36,    38,    37,   232,
     233,   390,   392,   393,   403,   400,   398,   399,     0,   397,
     387,   401,   402,   386,   391,   389,   404,   388,   427,   428,
     448,   449,   441,     0,   440,   574,     0,   550,     0,   285,
     287,   296,   293,   298,   295,   294,   300,   297,   299,   292,
     301,     0,   291,   284,   304,   303,   302,   283,   286,   419,
     411,     0,   410,   418,   252,   253,   251,     0,   250,   268,
     267,     0,     0,     0,   120,     0,     0,     0,     0,   115,
     153,   151,   193,   190,   189,   182,   184,   200,   194,   197,
     192,   183,   198,   186,   195,   199,   187,   196,   191,   185,
     188,     0,   181,   148,   150,   152,   164,   158,   175,   176,
     159,   160,   161,   162,   170,   163,   173,   177,   166,   171,
     167,   172,   165,   169,   168,   174,     0,   157,   149,   314,
     315,   313,    73,    77,   330,   336,   342,   345,   338,   344,
     339,   343,   341,   337,   340,     0,   335,   331,   353,   358,
     364,   367,   360,   366,   361,   365,   363,   359,   362,     0,
     357,   240,     0,    39,    40,    41,   395,     0,   438,     0,
     575,   551,   289,     0,   408,     0,   248,     0,   266,   263,
     262,     0,     0,     0,     0,   114,   179,     0,   155,     0,
     333,     0,   355,     0,   241,   396,   439,   290,   409,   249,
     121,   130,   133,   132,   129,   134,   131,   128,     0,   127,
     123,   122,   180,   156,   334,   356,   125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   802,   803,  1057,  1058,    25,   230,   231,
     232,   233,    26,   269,   270,   271,   272,   764,   765,   768,
     769,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,    27,    71,    72,    73,
      74,    75,    28,   222,   223,   224,   225,   226,   976,   977,
     978,   979,   980,  1126,  1258,  1259,    29,    60,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   735,  1176,  1177,
     522,   731,  1151,  1152,    30,    49,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   603,  1041,  1042,    31,    57,
     488,   716,  1117,  1118,   489,   490,   491,  1123,   968,   969,
     492,   493,    32,    55,   463,   464,   465,   466,   467,   468,
     469,   470,   701,  1101,  1102,   471,   472,   473,    33,    61,
     527,   528,   529,   530,   531,    34,   292,   293,   294,    35,
      64,   564,   565,   566,   567,   568,   778,  1195,  1196,    36,
      65,   572,   573,   574,   575,   784,  1209,  1210,    37,    50,
     368,   369,   370,   371,   372,   373,   374,   375,   376,   377,
     624,  1068,  1069,   378,   379,   380,   381,   382,    38,    56,
     478,   711,  1111,  1112,   479,   480,   481,   482,    39,    51,
     386,   387,   388,   389,    40,   112,   113,   114,    41,    53,
     397,   643,  1083,  1084,   398,   399,   400,   401,    42,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   433,   929,   930,   213,
     431,   906,   907,   214,   215,   216,    43,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    44,   243,   244,   245,   246,   247,   248,
     249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1008
static const yytype_int16 yypact[] =
{
   -1008,   649, -1008,  -186,  -215,  -210, -1008, -1008, -1008,  -207,
   -1008,  -197, -1008, -1008, -1008,  -173,  -167, -1008, -1008,  -165,
    -158, -1008, -1008,  -156, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,    13,   897,  -153,
    -151,  -136,    14,  -110,   406,   -90,   -80,   -74,    63,    12,
     -61,   -42,   313,   456,   -33,   -28,     5,   -19,   -16,   -11,
      -9,    21, -1008, -1008, -1008, -1008, -1008,    55,    74,    75,
      82,    91,    93,   104,   117,   118,   119,   133,   134,   135,
     148,   154, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,   690,   529,    23,
   -1008,   150,     6, -1008, -1008,    33, -1008,   155,   161,   162,
     163,   165,   166,   168,   171,   172,   173,   176,   178,   181,
     182,   183,   187,   189,   191,   192,   193,   194,   195,   197,
     199,   200,   202,   203,   205,   209, -1008,   210, -1008,   211,
     215,   216,   217,   218,   230,   231,   232,   234,   236,   239,
     242,   244,   245,   246,   247,   254,   128, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,   225,   164,   272,
      56,   255,    49, -1008, -1008, -1008,   114,   131,   256,   258,
      71, -1008, -1008, -1008,   503,    15, -1008,   260,   262,   267,
     268,   269,   271,     4, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,   159,   273,   275,   278,   279,   280,   283,   286,   290,
     296,   297,   299,   300,   301,   303,   305,   310,   314,   179,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   201,    18,
   -1008,   316,    41, -1008, -1008, -1008,   329,   357,   376,   204,
   -1008,   436,   442,   380,   444,   444,   447,   450,   451,   389,
     390,   454,   444,   392,   395,   342, -1008,   343,   346,   347,
     350, -1008,   352,   353,   354,   356,   360,   361,   363,   368,
     371,   372,   373,   374,   384,    17, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,   388,   387,   397,   398,   400, -1008,
     402,   403,   405,   409,   412,   413,   414,   415,   319, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,   420,   426,    24, -1008, -1008, -1008,
     492,   431, -1008, -1008,   429,   430, -1008, -1008,    20, -1008,
   -1008, -1008,   452,   444,   444,   554,   466,   494,   555,   540,
     497,   444,   500,   444,   568,   571,   573,   509,   511,   512,
     444,   577,   579,   444,   580,   581,   565,   585,   588,   526,
     527,   468,   530,   471,   444,   444,   532,   533,   534,   535,
     -79,   -71,   542,   544,   444,   444,   583,   444,   545,   547,
     548,   498, -1008,   499,   489,   501, -1008,   502,   504,   505,
     506,   507,   510,    34, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   513, -1008,   516, -1008,    25,
   -1008, -1008, -1008,   514, -1008,   521,   522,   523, -1008,     7,
   -1008, -1008, -1008, -1008, -1008,   557,   515, -1008,   495, -1008,
     603,   613,   531, -1008,   536,   524,   537, -1008,   541,   543,
     546, -1008,   553,   253, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008,   551,   556,   559,   560,    45, -1008, -1008,
   -1008, -1008,   587,   590,   638,   596,   602,   444,   558, -1008,
   -1008,   658,   605,   684,   685,   669,   670,   671,   674,   675,
     676,   -14,    84,   680,   681,   696,   686,   689,   584, -1008,
     589,   592, -1008,   595,     8, -1008, -1008, -1008, -1008,   607,
     599, -1008,    27, -1008, -1008, -1008,   704,   609, -1008,   611,
     617,   619, -1008,   620,   621,   622,   -67,   623,   625,   631,
     639,   643,   645,   647,   652,   653,   655,   656, -1008, -1008,
     703,   725,   444,   610,   758,   761,   769,   777,   444,   444,
     760,   786,   789,   444,   444,   794,   794,   678, -1008, -1008,
     781,    78,   783,   733,   687,   785,   788,   792,   793,   808,
     797,   798,   799,   700, -1008,   802,   803,   705, -1008,   706,
   -1008,   804,   805,   707,   708, -1008,   709,   711,   713,   714,
     715,   716,   717,   718,   719,   720,   721,   722,   723,   724,
     726,   727,   728,   729,   730,   731,   732,   734,   735,   736,
     737,   740,   741,   742,   743,   641,   744,   677,   748,   749,
     750,   751,   752,   753,   754,   755,   756,   757,   759,   762,
     763,   764,   765,   766,   767,   768,   770, -1008, -1008,   813,
     782,   772,   834,   827,   859,   861,   862,   870,   771, -1008,
     873,   773,   878,   778, -1008, -1008,   776,   881,   882,   902,
     784, -1008,   790, -1008,    30,   791,   795, -1008, -1008,   884,
     842,   796,   889,   890,   893,   800,   894,   801, -1008, -1008,
     895,   899,   901,   806, -1008,   807,   809,   810,   811,   812,
     814, -1008,   815,   816,   817,   818,   819,   820,   821,   822,
     823,   824, -1008, -1008,  -202, -1008, -1008, -1008,  -164, -1008,
     825,   826,   828,   829,   830, -1008, -1008,   903,   831,   905,
     832, -1008, -1008,   909,   833,   835, -1008,   837, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   444,   444,   444,   444,   444,
     444,   444, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   838,   839,   840,    28,   841,
     843,   844,   845,   846,   847,   848,   849,   850,   851,   852,
      77,   853,   854, -1008,   855,   856,   857,   858,   860,    -4,
     863,   864,   865,   866,   867,   868,   869,   871, -1008,   872,
     874, -1008, -1008,   875,   876,   892, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008,  -133, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   -32,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
     877,   879,   359,   880,   883,   885,   886,   887,   888, -1008,
     891,   923,   896, -1008,   109,   898,   900,   912,   904, -1008,
   -1008, -1008,   906,   907, -1008,   908,   103, -1008, -1008, -1008,
   -1008, -1008, -1008,   913,   914,   539,   915,   916,   917,   712,
     918, -1008,   919,   920,   921, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008,   -14, -1008,    84, -1008, -1008, -1008, -1008,
   -1008,   922,   441,   924, -1008,   925,   572, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,   -24, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,   794,   794,   794, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   -21, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008,    -7, -1008, -1008,   641, -1008,   677, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,    53, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,    76, -1008, -1008, -1008, -1008, -1008,   101, -1008, -1008,
   -1008,   933,   902,   926, -1008,   932,   927,   -94,   928, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008,   102, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008,   113, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   144, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   145,
   -1008, -1008,    28, -1008, -1008, -1008, -1008,    -4, -1008,   892,
   -1008, -1008, -1008,   359, -1008,   923, -1008,   109, -1008, -1008,
   -1008,   929,   295,   931,   934, -1008, -1008,   539, -1008,   712,
   -1008,   441, -1008,   572, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,   156, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,   295, -1008
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1008, -1008, -1008,  -191,  -302, -1007,  -615, -1008, -1008,   930,
   -1008, -1008, -1008, -1008,   910, -1008, -1008, -1008,    54, -1008,
      43, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,  1015, -1008,
   -1008, -1008, -1008, -1008,   935, -1008, -1008, -1008, -1008,   111,
   -1008, -1008, -1008, -1008, -1008,  -172, -1008, -1008, -1008,   593,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,  -141,
   -1008, -1008, -1008,  -134, -1008, -1008, -1008,   774, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008,  -105, -1008, -1008,
   -1008, -1008, -1008,  -113, -1008,   626, -1008, -1008, -1008,    -5,
   -1008, -1008, -1008, -1008, -1008,   657, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008,  -104, -1008, -1008, -1008, -1008, -1008,
   -1008,   591, -1008, -1008, -1008, -1008, -1008,   836, -1008, -1008,
   -1008, -1008,   562, -1008, -1008, -1008, -1008, -1008,  -119, -1008,
   -1008, -1008,   552, -1008, -1008, -1008, -1008,  -116, -1008, -1008,
   -1008,   780, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008,   -88, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008,   -95, -1008,   673, -1008, -1008, -1008, -1008,
   -1008,   746, -1008, -1008, -1008, -1008,  1022, -1008, -1008, -1008,
   -1008, -1008, -1008,   -82, -1008,   775, -1008, -1008, -1008, -1008,
     992, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,    73, -1008,
   -1008, -1008,    79, -1008, -1008, -1008, -1008, -1008,  1071, -1008,
   -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008, -1008,
   -1008, -1008, -1008, -1008, -1008,   937, -1008, -1008, -1008, -1008,
   -1008, -1008
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     831,   832,   587,   588,  1066,   236,   290,   110,   483,   560,
     595,   830,    47,   227,    67,   110,   523,    48,   317,   569,
      52,   393,    67,  1012,   383,   383,   474,  1013,   569,   524,
      54,   972,   318,   319,   393,   453,   320,    68,   586,    45,
      46,   237,   290,   484,    69,    68,   523,  1213,  1214,  1215,
     220,   454,    69,   321,    58,   238,   239,   240,   241,   524,
      59,  1014,    62,   485,   220,  1015,   455,   111,   486,    63,
     456,    66,   227,   242,   107,   111,   108,   795,   796,   797,
     798,   799,   800,   801,   384,   384,  1054,  1055,  1056,   684,
     685,   109,  1085,   322,   323,   324,  1086,   686,   687,   325,
     291,   647,   648,   561,   972,   228,   326,   327,    70,   655,
    1233,   657,   328,   570,   525,   394,    70,   115,   664,  1039,
    1040,   667,   570,   329,   330,   973,   762,   763,   394,   116,
     487,   229,   678,   679,   117,   118,   291,   217,   331,   332,
     119,   526,   690,   691,   525,   693,   395,   218,   120,   385,
     385,   475,   457,   219,   121,    76,   122,   123,   124,   395,
    1114,   458,   459,   125,   228,   474,   234,   562,   333,   126,
     127,   526,   128,   129,   130,    77,    78,   571,   131,   396,
     251,    79,   830,   132,   476,   235,   571,   133,   134,   974,
     229,   135,   396,  1087,   288,   460,  1067,  1088,   973,   289,
     136,  1211,   560,   252,  1216,  1212,   295,   137,  1217,   138,
     334,   139,   296,   140,   141,   142,   143,   297,  1218,   298,
      80,    81,  1219,   563,   766,   767,   453,    82,    83,    84,
     538,   144,   391,   720,   780,   750,   253,   145,   146,   147,
     477,   148,   454,   617,   149,   150,   644,   299,   151,   461,
     637,   713,   975,   785,   504,    85,    86,   455,   462,   254,
     708,   456,   974,   255,   835,   836,   221,   577,    87,    88,
     505,   743,  -113,   483,   256,   496,   257,   258,  1222,    89,
     221,   494,  1223,   301,   152,   506,  -113,    90,   153,   507,
     475,   154,   155,   156,   157,   158,   561,   502,   159,   160,
     817,  1224,   302,   303,  1115,  1225,   823,   824,   484,  1116,
     304,   828,   829,   259,   236,   260,   261,   262,   263,   305,
     354,   306,   355,   476,   356,   975,  1226,  1236,   485,  1128,
    1227,  1237,   307,   486,   264,  1251,   357,   498,  1238,   161,
     162,   163,  1239,   457,   164,   308,   309,   310,   508,   165,
     237,   358,   458,   459,   451,   359,   499,  1252,   265,  1253,
     562,   311,   312,   313,   238,   239,   240,   241,   266,  1240,
    1242,   509,  1091,  1241,  1243,   360,   314,   361,   390,   477,
     315,  1266,   242,   402,   540,  1267,   460,   362,   510,   403,
     404,   405,  1092,   406,   407,   487,   408,   267,   268,   409,
     410,   411,  1093,  1254,   412,   558,   413,   116,  1094,   414,
     415,   416,   117,   118,   363,   417,   563,   418,   119,   419,
     420,   421,   422,   423,  1095,   424,   120,   425,   426,   582,
     427,   428,   121,   429,   122,   123,   124,   430,   432,   434,
     461,   125,   364,   435,   436,   437,   438,   126,   127,   462,
     128,   129,   130,   579,   511,  1096,   131,   251,   439,   440,
     441,   132,   442,  1097,   443,   133,   134,   444,   512,   135,
     445,   365,   446,   447,   448,   449,  1255,  1256,   136,   737,
     252,   580,   450,   495,   500,   137,   501,   138,   532,   139,
     533,   140,   141,   142,   143,   534,   535,   536,   366,   537,
     581,   541,  1098,   542,   504,  1185,   543,   544,   545,   144,
    1257,   546,  1234,   253,   547,   145,   146,   147,   548,   148,
     505,  1099,   149,   150,   549,   550,   151,   551,   552,   553,
     354,   554,   355,   555,   356,   506,   254,   367,   556,   507,
     255,   583,   557,  1132,   576,   633,   357,   584,   585,   586,
    1100,   256,   589,   257,   258,   590,   591,   592,   593,   594,
     596,   358,   152,   597,  1133,   359,   153,   598,   599,   154,
     155,   156,   157,   158,   600,   601,   159,   160,   602,  1134,
     604,   605,   606,  1186,   607,   360,  1135,   361,   608,   609,
     259,   610,   260,   261,   262,   263,   611,   362,   508,   612,
     613,   614,   615,  1136,  1029,  1030,  1031,  1032,  1033,  1034,
    1035,   264,   616,   619,  1187,   620,   639,   161,   162,   163,
     646,   509,   164,  1188,   363,   621,   622,   165,   623,  1189,
     625,   626,  1137,   627,   650,   265,  1199,   628,   510,  1138,
     629,   630,   631,   632,  1190,   266,  1191,  1192,   635,     2,
       3,  1139,   364,     4,   636,  1193,   640,   641,   642,   649,
     652,  1194,   651,     5,   653,   654,     6,     7,   656,  1140,
    1141,  1142,     8,   658,   267,   268,   659,   661,   660,   662,
     663,   365,   665,     9,   666,   668,   669,    10,    11,   670,
     671,   317,   886,   672,   673,   674,   675,    12,   676,   677,
     680,   681,   682,   683,   511,   318,   319,   692,   366,   320,
     688,    13,   689,   694,  1200,   695,   696,   699,   512,    14,
      15,  1143,   724,   697,   698,   722,   321,   725,   909,   700,
     702,  1144,   703,   704,   705,   706,  1145,   726,   707,   715,
     723,   710,  1146,    16,   712,  1201,  1147,   367,  1148,   717,
     718,   719,   729,  1149,  1202,   745,   727,    17,   746,  1150,
    1203,   728,   747,  1156,   748,   730,   322,   323,   324,   732,
     749,   733,   325,   753,   734,  1204,   739,  1205,  1206,   326,
     327,   736,   752,   751,   740,   328,  1207,   741,   742,   754,
     755,    18,  1208,   756,   757,   758,   329,   330,   759,   760,
     761,   772,    19,    20,   770,   771,    21,    22,   815,   775,
     773,   331,   332,   774,   776,   887,   888,   889,   890,   891,
     777,   892,   893,   779,   894,   895,   896,   783,   787,   897,
     816,   898,   782,   899,   788,   900,   789,   901,   818,   902,
     903,   333,   790,   904,   791,   792,   793,   794,   804,   905,
     805,   910,   911,   912,   913,   914,   806,   915,   916,    23,
     917,   918,   919,   819,   807,   920,   820,   921,   808,   922,
     809,   923,   810,   924,   821,   925,   926,   811,   812,   927,
     813,   814,   822,   334,   825,   928,  1157,  1158,  1159,  1160,
    1161,   826,  1162,  1163,   827,  1164,  1165,  1166,    76,   830,
    1167,   838,  1168,   833,  1169,   834,  1170,   837,  1171,   840,
    1172,  1173,   841,   844,  1174,   839,   842,   843,    77,    78,
    1175,   845,   846,   847,    79,   848,   849,   850,   853,   854,
     851,   852,   954,   856,   857,   855,   858,   950,   859,   860,
     861,   862,   863,   864,   865,   866,   867,   868,   869,   870,
     951,   871,   872,   873,   874,   875,   876,   877,   953,   878,
     879,   880,   881,    80,    81,   882,   883,   884,   885,   908,
      82,    83,    84,   931,   932,   933,   934,   935,   936,   937,
     938,   939,   940,   955,   941,   956,   957,   942,   943,   944,
     945,   946,   947,   948,   958,   949,   959,   960,    85,    86,
     952,   961,   962,   963,   964,   965,   966,   967,   983,   970,
     984,    87,    88,   986,   987,   971,   981,   988,   990,   992,
     982,  1082,    89,   993,   985,   994,   991,  1021,   989,  1023,
      90,   995,   996,  1025,   997,   998,   999,  1000,  1228,  1001,
    1002,  1003,  1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,
    1016,  1017,  1110,  1018,  1019,  1020,  1231,  1024,  1183,  1022,
    1027,  1026,  1028,  1036,  1037,  1038,  1043,  1182,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1059,  1060,
    1061,  1062,  1063,  1064,  1121,  1065,   300,  1129,  1070,  1071,
    1072,  1073,  1074,  1075,  1076,  1268,  1077,  1078,  1263,  1079,
    1080,  1081,  1089,  1262,  1090,  1103,   738,  1244,  1104,   618,
    1105,  1106,  1107,  1108,  1249,   721,  1109,  1229,   744,  1247,
     709,  1113,  1264,  1119,   786,  1120,   781,  1265,   578,  1245,
    1248,  1124,   638,  1122,   392,  1125,  1127,  1246,  1130,  1131,
    1153,  1154,  1155,  1178,  1179,  1180,  1181,  1184,   634,  1197,
    1198,  1230,   714,  1235,  1250,  1232,  1260,   497,   452,  1261,
     503,  1221,   316,     0,     0,  1220,     0,     0,     0,     0,
       0,     0,     0,   645,     0,     0,     0,     0,     0,   559,
     539
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-1008)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     615,   616,   304,   305,     8,     1,     1,     1,     1,     1,
     312,   105,   227,     1,     1,     1,     1,   227,     1,     1,
     227,     1,     1,   225,     1,     1,     1,   229,     1,    14,
     227,     1,    15,    16,     1,     1,    19,    24,   105,   225,
     226,    37,     1,    36,    31,    24,     1,  1054,  1055,  1056,
       1,    17,    31,    36,   227,    51,    52,    53,    54,    14,
     227,   225,   227,    56,     1,   229,    32,    61,    61,   227,
      36,   227,     1,    69,   227,    61,   227,   144,   145,   146,
     147,   148,   149,   150,    61,    61,     9,    10,    11,   168,
     169,   227,   225,    76,    77,    78,   229,   168,   169,    82,
      95,   403,   404,    95,     1,    93,    89,    90,    95,   411,
     204,   413,    95,    95,    99,    95,    95,   227,   420,    91,
      92,   423,    95,   106,   107,    95,   140,   141,    95,     1,
     123,   119,   434,   435,     6,     7,    95,   227,   121,   122,
      12,   126,   444,   445,    99,   447,   126,   227,    20,   126,
     126,   126,   118,   227,    26,     1,    28,    29,    30,   126,
      51,   127,   128,    35,    93,     1,   227,   159,   151,    41,
      42,   126,    44,    45,    46,    21,    22,   159,    50,   159,
       1,    27,   105,    55,   159,   227,   159,    59,    60,   159,
     119,    63,   159,   225,   227,   161,   200,   229,    95,   227,
      72,   225,     1,    24,   225,   229,   225,    79,   229,    81,
     193,    83,   228,    85,    86,    87,    88,   228,   225,   228,
      66,    67,   229,   215,   140,   141,     1,    73,    74,    75,
     226,   103,   226,   226,   226,   537,    57,   109,   110,   111,
     215,   113,    17,   226,   116,   117,   226,   226,   120,   215,
     226,   226,   222,   226,     1,   101,   102,    32,   224,    80,
     226,    36,   159,    84,   186,   187,   217,   226,   114,   115,
      17,   226,   223,     1,    95,   226,    97,    98,   225,   125,
     217,   225,   229,   228,   156,    32,   223,   133,   160,    36,
     126,   163,   164,   165,   166,   167,    95,   226,   170,   171,
     602,   225,   228,   228,   195,   229,   608,   609,    36,   200,
     228,   613,   614,   134,     1,   136,   137,   138,   139,   228,
       1,   228,     3,   159,     5,   222,   225,   225,    56,   226,
     229,   229,   228,    61,   155,    40,    17,   223,   225,   211,
     212,   213,   229,   118,   216,   228,   228,   228,    95,   221,
      37,    32,   127,   128,   226,    36,   225,    62,   179,    64,
     159,   228,   228,   228,    51,    52,    53,    54,   189,   225,
     225,   118,    13,   229,   229,    56,   228,    58,   228,   215,
     226,   225,    69,   228,   225,   229,   161,    68,   135,   228,
     228,   228,    33,   228,   228,   123,   228,   218,   219,   228,
     228,   228,    43,   108,   228,   226,   228,     1,    49,   228,
     228,   228,     6,     7,    95,   228,   215,   228,    12,   228,
     228,   228,   228,   228,    65,   228,    20,   228,   228,   225,
     228,   228,    26,   228,    28,    29,    30,   228,   228,   228,
     215,    35,   123,   228,   228,   228,   228,    41,    42,   224,
      44,    45,    46,   124,   201,    96,    50,     1,   228,   228,
     228,    55,   228,   104,   228,    59,    60,   228,   215,    63,
     228,   152,   228,   228,   228,   228,   181,   182,    72,   226,
      24,   124,   228,   228,   228,    79,   228,    81,   228,    83,
     228,    85,    86,    87,    88,   228,   228,   228,   179,   228,
     124,   228,   143,   228,     1,    64,   228,   228,   228,   103,
     215,   228,  1127,    57,   228,   109,   110,   111,   228,   113,
      17,   162,   116,   117,   228,   228,   120,   228,   228,   228,
       1,   228,     3,   228,     5,    32,    80,   218,   228,    36,
      84,   105,   228,     4,   228,   226,    17,   105,   168,   105,
     191,    95,   105,    97,    98,   105,   105,   168,   168,   105,
     168,    32,   156,   168,    25,    36,   160,   225,   225,   163,
     164,   165,   166,   167,   228,   228,   170,   171,   228,    40,
     228,   228,   228,   142,   228,    56,    47,    58,   228,   228,
     134,   228,   136,   137,   138,   139,   228,    68,    95,   228,
     228,   228,   228,    64,   795,   796,   797,   798,   799,   800,
     801,   155,   228,   225,   173,   228,   124,   211,   212,   213,
     168,   118,   216,   182,    95,   228,   228,   221,   228,   188,
     228,   228,    93,   228,   168,   179,    64,   228,   135,   100,
     228,   228,   228,   228,   203,   189,   205,   206,   228,     0,
       1,   112,   123,     4,   228,   214,   225,   228,   228,   105,
     105,   220,   168,    14,   124,   168,    17,    18,   168,   130,
     131,   132,    23,   105,   218,   219,   105,   168,   105,   168,
     168,   152,   105,    34,   105,   105,   105,    38,    39,   124,
     105,     1,    51,   105,   168,   168,   228,    48,   168,   228,
     168,   168,   168,   168,   201,    15,    16,   124,   179,    19,
     168,    62,   168,   168,   142,   168,   168,   228,   215,    70,
      71,   182,   227,   225,   225,   168,    36,   124,    51,   228,
     228,   192,   228,   228,   228,   228,   197,   124,   228,   225,
     225,   228,   203,    94,   228,   173,   207,   218,   209,   228,
     228,   228,   228,   214,   182,   168,   225,   108,   168,   220,
     188,   225,   124,    51,   168,   228,    76,    77,    78,   228,
     168,   228,    82,   168,   228,   203,   225,   205,   206,    89,
      90,   228,   124,   225,   228,    95,   214,   228,   228,   105,
     105,   142,   220,   124,   124,   124,   106,   107,   124,   124,
     124,   105,   153,   154,   124,   124,   157,   158,   105,   225,
     124,   121,   122,   124,   225,   174,   175,   176,   177,   178,
     228,   180,   181,   228,   183,   184,   185,   228,   124,   188,
     105,   190,   225,   192,   225,   194,   225,   196,   228,   198,
     199,   151,   225,   202,   225,   225,   225,   225,   225,   208,
     225,   174,   175,   176,   177,   178,   225,   180,   181,   210,
     183,   184,   185,   105,   225,   188,   105,   190,   225,   192,
     225,   194,   225,   196,   105,   198,   199,   225,   225,   202,
     225,   225,   105,   193,   124,   208,   174,   175,   176,   177,
     178,   105,   180,   181,   105,   183,   184,   185,     1,   105,
     188,   168,   190,   225,   192,   124,   194,   124,   196,   124,
     198,   199,   124,   105,   202,   228,   124,   124,    21,    22,
     208,   124,   124,   124,    27,   225,   124,   124,   124,   124,
     225,   225,   105,   225,   225,   228,   225,   124,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     168,   225,   225,   225,   225,   225,   225,   225,   124,   225,
     225,   225,   225,    66,    67,   225,   225,   225,   225,   225,
      73,    74,    75,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   124,   225,   124,   124,   225,   225,   225,
     225,   225,   225,   225,   124,   225,   225,   124,   101,   102,
     228,   228,   124,   225,   228,   124,   124,   105,   124,   225,
     168,   114,   115,   124,   124,   225,   225,   124,   124,   124,
     225,   129,   125,   124,   228,   124,   225,   124,   228,   124,
     133,   225,   225,   124,   225,   225,   225,   225,   105,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   129,   225,   225,   225,   124,   225,  1015,   228,
     225,   228,   225,   225,   225,   225,   225,  1013,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   172,   225,    71,   976,   225,   225,
     225,   225,   225,   225,   225,  1267,   225,   225,  1239,   225,
     225,   225,   225,  1237,   225,   225,   513,  1212,   225,   335,
     225,   225,   225,   225,  1227,   489,   225,  1122,   527,  1223,
     463,   225,  1241,   225,   572,   225,   564,  1243,   292,  1217,
    1225,   225,   386,   229,   112,   228,   228,  1219,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   368,   225,
     225,   225,   479,   225,   225,   228,   225,   222,   166,   225,
     230,  1088,    91,    -1,    -1,  1086,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   398,    -1,    -1,    -1,    -1,    -1,   269,
     243
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   231,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    94,   108,   142,   153,
     154,   157,   158,   210,   232,   237,   242,   266,   272,   286,
     304,   328,   342,   358,   365,   369,   379,   388,   408,   418,
     424,   428,   438,   496,   513,   225,   226,   227,   227,   305,
     389,   419,   227,   429,   227,   343,   409,   329,   227,   227,
     287,   359,   227,   227,   370,   380,   227,     1,    24,    31,
      95,   267,   268,   269,   270,   271,     1,    21,    22,    27,
      66,    67,    73,    74,    75,   101,   102,   114,   115,   125,
     133,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   227,   227,   227,
       1,    61,   425,   426,   427,   227,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    81,    83,
      85,    86,    87,    88,   103,   109,   110,   111,   113,   116,
     117,   120,   156,   160,   163,   164,   165,   166,   167,   170,
     171,   211,   212,   213,   216,   221,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   466,   467,   468,   469,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   489,   493,   494,   495,   227,   227,   227,
       1,   217,   273,   274,   275,   276,   277,     1,    93,   119,
     238,   239,   240,   241,   227,   227,     1,    37,    51,    52,
      53,    54,    69,   514,   515,   516,   517,   518,   519,   520,
     521,     1,    24,    57,    80,    84,    95,    97,    98,   134,
     136,   137,   138,   139,   155,   179,   189,   218,   219,   243,
     244,   245,   246,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   227,   227,
       1,    95,   366,   367,   368,   225,   228,   228,   228,   226,
     268,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   226,   498,     1,    15,    16,
      19,    36,    76,    77,    78,    82,    89,    90,    95,   106,
     107,   121,   122,   151,   193,   306,   307,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,   320,
     321,   322,   323,   324,     1,     3,     5,    17,    32,    36,
      56,    58,    68,    95,   123,   152,   179,   218,   390,   391,
     392,   393,   394,   395,   396,   397,   398,   399,   403,   404,
     405,   406,   407,     1,    61,   126,   420,   421,   422,   423,
     228,   226,   426,     1,    95,   126,   159,   430,   434,   435,
     436,   437,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   490,   228,   486,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   226,   440,     1,    17,    32,    36,   118,   127,   128,
     161,   215,   224,   344,   345,   346,   347,   348,   349,   350,
     351,   355,   356,   357,     1,   126,   159,   215,   410,   414,
     415,   416,   417,     1,    36,    56,    61,   123,   330,   334,
     335,   336,   340,   341,   225,   228,   226,   274,   223,   225,
     228,   228,   226,   239,     1,    17,    32,    36,    95,   118,
     135,   201,   215,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   300,     1,    14,    99,   126,   360,   361,   362,
     363,   364,   228,   228,   228,   228,   228,   228,   226,   515,
     225,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   226,   244,
       1,    95,   159,   215,   371,   372,   373,   374,   375,     1,
      95,   159,   381,   382,   383,   384,   228,   226,   367,   124,
     124,   124,   225,   105,   105,   168,   105,   234,   234,   105,
     105,   105,   168,   168,   105,   234,   168,   168,   225,   225,
     228,   228,   228,   325,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   226,   307,   225,
     228,   228,   228,   228,   400,   228,   228,   228,   228,   228,
     228,   228,   228,   226,   391,   228,   228,   226,   421,   124,
     225,   228,   228,   431,   226,   435,   168,   234,   234,   105,
     168,   168,   105,   124,   168,   234,   168,   234,   105,   105,
     105,   168,   168,   168,   234,   105,   105,   234,   105,   105,
     124,   105,   105,   168,   168,   228,   168,   228,   234,   234,
     168,   168,   168,   168,   168,   169,   168,   169,   168,   168,
     234,   234,   124,   234,   168,   168,   168,   225,   225,   228,
     228,   352,   228,   228,   228,   228,   228,   228,   226,   345,
     228,   411,   228,   226,   415,   225,   331,   228,   228,   228,
     226,   335,   168,   225,   227,   124,   124,   225,   225,   228,
     228,   301,   228,   228,   228,   297,   228,   226,   289,   225,
     228,   228,   228,   226,   361,   168,   168,   124,   168,   168,
     234,   225,   124,   168,   105,   105,   124,   124,   124,   124,
     124,   124,   140,   141,   247,   248,   140,   141,   249,   250,
     124,   124,   105,   124,   124,   225,   225,   228,   376,   228,
     226,   372,   225,   228,   385,   226,   382,   124,   225,   225,
     225,   225,   225,   225,   225,   144,   145,   146,   147,   148,
     149,   150,   233,   234,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   105,   105,   234,   228,   105,
     105,   105,   105,   234,   234,   124,   105,   105,   234,   234,
     105,   236,   236,   225,   124,   186,   187,   124,   168,   228,
     124,   124,   124,   124,   105,   124,   124,   124,   225,   124,
     124,   225,   225,   124,   124,   228,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,    51,   174,   175,   176,
     177,   178,   180,   181,   183,   184,   185,   188,   190,   192,
     194,   196,   198,   199,   202,   208,   491,   492,   225,    51,
     174,   175,   176,   177,   178,   180,   181,   183,   184,   185,
     188,   190,   192,   194,   196,   198,   199,   202,   208,   487,
     488,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     124,   168,   228,   124,   105,   124,   124,   124,   124,   225,
     124,   228,   124,   225,   228,   124,   124,   105,   338,   339,
     225,   225,     1,    95,   159,   222,   278,   279,   280,   281,
     282,   225,   225,   124,   168,   228,   124,   124,   124,   228,
     124,   225,   124,   124,   124,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   229,   225,   229,   225,   225,   225,   225,
     225,   124,   228,   124,   225,   124,   228,   225,   225,   233,
     233,   233,   233,   233,   233,   233,   225,   225,   225,    91,
      92,   326,   327,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,     9,    10,    11,   235,   236,   225,
     225,   225,   225,   225,   225,   225,     8,   200,   401,   402,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   129,   432,   433,   225,   229,   225,   229,   225,
     225,    13,    33,    43,    49,    65,    96,   104,   143,   162,
     191,   353,   354,   225,   225,   225,   225,   225,   225,   225,
     129,   412,   413,   225,    51,   195,   200,   332,   333,   225,
     225,   172,   229,   337,   225,   228,   283,   228,   226,   279,
     225,   225,     4,    25,    40,    47,    64,    93,   100,   112,
     130,   131,   132,   182,   192,   197,   203,   207,   209,   214,
     220,   302,   303,   225,   225,   225,    51,   174,   175,   176,
     177,   178,   180,   181,   183,   184,   185,   188,   190,   192,
     194,   196,   198,   199,   202,   208,   298,   299,   225,   225,
     225,   225,   248,   250,   225,    64,   142,   173,   182,   188,
     203,   205,   206,   214,   220,   377,   378,   225,   225,    64,
     142,   173,   182,   188,   203,   205,   206,   214,   220,   386,
     387,   225,   229,   235,   235,   235,   225,   229,   225,   229,
     492,   488,   225,   229,   225,   229,   225,   229,   105,   339,
     225,   124,   228,   204,   236,   225,   225,   229,   225,   229,
     225,   229,   225,   229,   327,   402,   433,   354,   413,   333,
     225,    40,    62,    64,   108,   181,   182,   215,   284,   285,
     225,   225,   303,   299,   378,   387,   225,   229,   285
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

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
/* Line 1792 of yacc.c  */
#line 368 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 370 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 374 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 378 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 382 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 386 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 390 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 394 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 398 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 405 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 406 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 407 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 408 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 409 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 423 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 456 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 462 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 471 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 477 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 485 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx) 
  {
    if (!ServerInfo.rsa_private_key_file)
    {
      conf_error_report("No rsa_private_key_file specified, SSL disabled");
      break;
    }

    if (SSL_CTX_use_certificate_file(ServerInfo.server_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_certificate_file(ServerInfo.client_ctx, yylval.string,
                                     SSL_FILETYPE_PEM) <= 0)
    {
      conf_error_report("Could not open/read certificate file");
      report_crypto_errors();
      break;
    }

    if (SSL_CTX_use_PrivateKey_file(ServerInfo.server_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0 ||
        SSL_CTX_use_PrivateKey_file(ServerInfo.client_ctx, ServerInfo.rsa_private_key_file,
                                    SSL_FILETYPE_PEM) <= 0)
    {
      conf_error_report("Could not read RSA private key");
      report_crypto_errors();
      break;
    }

    if (!SSL_CTX_check_private_key(ServerInfo.server_ctx) ||
        !SSL_CTX_check_private_key(ServerInfo.client_ctx))
    {
      conf_error_report("Could not read RSA private key");
      report_crypto_errors();
      break;
    }
  }
#endif
}
    break;

  case 82:
/* Line 1792 of yacc.c  */
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
      conf_error_report("File open failed, ignoring");
      break;
    }

    ServerInfo.rsa_private_key = PEM_read_bio_RSAPrivateKey(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (ServerInfo.rsa_private_key == NULL)
    {
      conf_error_report("Couldn't extract key, ignoring");
      break;
    }

    if (!RSA_check_key(ServerInfo.rsa_private_key))
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Invalid key, ignoring");
      break;
    }

    /* require 2048 bit (256 byte) key */
    if (RSA_size(ServerInfo.rsa_private_key) != 256)
    {
      RSA_free(ServerInfo.rsa_private_key);
      ServerInfo.rsa_private_key = NULL;

      conf_error_report("Not a 2048 bit key, ignoring");
    }
  }
#endif
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
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
          conf_error_report("Ignoring serverinfo::ssl_dh_param_file -- need at least a 1024 bit DH prime size");
        else
          SSL_CTX_set_tmp_dh(ServerInfo.server_ctx, dh);

        DH_free(dh);
      }
    }
  }
#endif
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 614 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 622 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      DupString(ServerInfo.name, yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 637 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      DupString(ServerInfo.sid, yylval.string);
    else
    {
      conf_error_report("Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
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

  case 89:
/* Line 1792 of yacc.c  */
#line 675 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 90:
/* Line 1792 of yacc.c  */
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

  case 91:
/* Line 1792 of yacc.c  */
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

  case 92:
/* Line 1792 of yacc.c  */
#line 742 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
    {
      char buf[IRCD_BUFSIZE];

      snprintf(buf, sizeof(buf), "max_clients too low, setting to %d", MAXCLIENTS_MIN);
      conf_error_report(buf);
      ServerInfo.max_clients = MAXCLIENTS_MIN;
    }
    else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
    {
      char buf[IRCD_BUFSIZE];

      snprintf(buf, sizeof(buf), "max_clients too high, setting to %d", MAXCLIENTS_MAX);
      conf_error_report(buf);
      ServerInfo.max_clients = MAXCLIENTS_MAX;
    }
    else
      ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 767 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].number) < 9)
    {
      conf_error_report("max_nick_length too low, setting to 9");
      ServerInfo.max_nick_length = 9;
    }
    else if ((yyvsp[(3) - (4)].number) > NICKLEN)
    {
      char buf[IRCD_BUFSIZE];

      snprintf(buf, sizeof(buf), "max_nick_length too high, setting to %d", NICKLEN);
      conf_error_report(buf);
      ServerInfo.max_nick_length = NICKLEN;
    }
    else
      ServerInfo.max_nick_length = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 94:
/* Line 1792 of yacc.c  */
#line 789 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].number) < 80)
    {
      conf_error_report("max_topic_length too low, setting to 80");
      ServerInfo.max_topic_length = 80;
    }
    else if ((yyvsp[(3) - (4)].number) > TOPICLEN)
    {
      char buf[IRCD_BUFSIZE];

      snprintf(buf, sizeof(buf), "max_topic_length too high, setting to %d", TOPICLEN);
      conf_error_report(buf);
      ServerInfo.max_topic_length = TOPICLEN;
    }
    else
      ServerInfo.max_topic_length = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 95:
/* Line 1792 of yacc.c  */
#line 811 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 826 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 835 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 105:
/* Line 1792 of yacc.c  */
#line 844 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 868 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_set_file(ltype, lsize, lfile);
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 885 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 890 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 893 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 917 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 921 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 929 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 939 "conf_parser.y"
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

  case 136:
/* Line 1792 of yacc.c  */
#line 952 "conf_parser.y"
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

  case 148:
/* Line 1792 of yacc.c  */
#line 1042 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1051 "conf_parser.y"
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

  case 150:
/* Line 1792 of yacc.c  */
#line 1088 "conf_parser.y"
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

  case 151:
/* Line 1792 of yacc.c  */
#line 1100 "conf_parser.y"
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

  case 152:
/* Line 1792 of yacc.c  */
#line 1111 "conf_parser.y"
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
      conf_error_report("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_aconf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    BIO_set_close(file, BIO_CLOSE);
    BIO_free(file);

    if (yy_aconf->rsa_public_key == NULL)
    {
      conf_error_report("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
      break;
    }
  }
#endif /* HAVE_LIBCRYPTO */
}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1233 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1237 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1241 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1245 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1251 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1294 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1310 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1314 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1318 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1322 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1326 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1330 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1340 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 202:
/* Line 1792 of yacc.c  */
#line 1347 "conf_parser.y"
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

      if (yy_class->min_idle > yy_class->max_idle)
      {
        yy_class->min_idle = 0;
        yy_class->max_idle = 0;
        yy_class->flags &= ~CONF_FLAGS_FAKE_IDLE;
      }

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

  case 223:
/* Line 1792 of yacc.c  */
#line 1415 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1424 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1436 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1442 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1448 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1454 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1460 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1466 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1472 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1478 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1485 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1491 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1503 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_class->min_idle = (yyvsp[(3) - (4)].number);
    yy_class->flags |= CONF_FLAGS_FAKE_IDLE;
  }
}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1512 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_class->max_idle = (yyvsp[(3) - (4)].number);
    yy_class->flags |= CONF_FLAGS_FAKE_IDLE;
  }
}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1521 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->flags &= CONF_FLAGS_FAKE_IDLE;
}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1528 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->flags |= CONF_FLAGS_RANDOM_IDLE;
}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1532 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->flags |= CONF_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1541 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1548 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 247:
/* Line 1792 of yacc.c  */
#line 1557 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1563 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1567 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 1571 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 1581 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 1586 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), listener_address, listener_flags);
  }
}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 1600 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if ((listener_flags & LISTENER_SSL))
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        conf_error_report("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, listener_address, listener_flags);
  }
}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 1620 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 1629 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 1641 "conf_parser.y"
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

  case 270:
/* Line 1792 of yacc.c  */
#line 1653 "conf_parser.y"
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
      new_aconf->country_id = yy_aconf->country_id;

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

  case 283:
/* Line 1792 of yacc.c  */
#line 1716 "conf_parser.y"
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

  case 284:
/* Line 1792 of yacc.c  */
#line 1751 "conf_parser.y"
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

  case 285:
/* Line 1792 of yacc.c  */
#line 1764 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 1773 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->country_id = GeoIP_id_by_code(yylval.string);
}
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 1779 "conf_parser.y"
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

  case 288:
/* Line 1792 of yacc.c  */
#line 1790 "conf_parser.y"
    {
}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 1795 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 1799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 1803 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 1807 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 1811 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 1815 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 1819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 1823 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 1827 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 1831 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_JOIN;
}
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 1837 "conf_parser.y"
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

  case 303:
/* Line 1792 of yacc.c  */
#line 1856 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 1866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 1879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 1886 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 1898 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 1907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (IsChanPrefix(*yylval.string))
    {
      char def_reason[] = CONF_NOREASON;

      create_channel_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
    }
  }
  /* ignore it for now.. but we really should make a warning if
   * its an erroneous name --fl_ */
}
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 1922 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = CONF_NOREASON;

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 1940 "conf_parser.y"
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

  case 322:
/* Line 1792 of yacc.c  */
#line 1955 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 1963 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 330:
/* Line 1792 of yacc.c  */
#line 1974 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 331:
/* Line 1792 of yacc.c  */
#line 1983 "conf_parser.y"
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

  case 332:
/* Line 1792 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 336:
/* Line 1792 of yacc.c  */
#line 2012 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 2016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 2020 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 339:
/* Line 1792 of yacc.c  */
#line 2024 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 340:
/* Line 1792 of yacc.c  */
#line 2028 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 2032 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 2036 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 2040 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 2044 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 2048 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 2057 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 2064 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 353:
/* Line 1792 of yacc.c  */
#line 2077 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 354:
/* Line 1792 of yacc.c  */
#line 2083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 2090 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 359:
/* Line 1792 of yacc.c  */
#line 2094 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 360:
/* Line 1792 of yacc.c  */
#line 2098 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 361:
/* Line 1792 of yacc.c  */
#line 2102 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 362:
/* Line 1792 of yacc.c  */
#line 2106 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 363:
/* Line 1792 of yacc.c  */
#line 2110 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 364:
/* Line 1792 of yacc.c  */
#line 2114 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 365:
/* Line 1792 of yacc.c  */
#line 2118 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 366:
/* Line 1792 of yacc.c  */
#line 2122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 367:
/* Line 1792 of yacc.c  */
#line 2126 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 368:
/* Line 1792 of yacc.c  */
#line 2135 "conf_parser.y"
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

  case 369:
/* Line 1792 of yacc.c  */
#line 2150 "conf_parser.y"
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
          conf_error_report("Ignoring connect block -- missing host");
        else if (!yy_aconf->passwd || !yy_aconf->spasswd)
          conf_error_report("Ignoring connect block -- missing password");
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

  case 386:
/* Line 1792 of yacc.c  */
#line 2194 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 2203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 2212 "conf_parser.y"
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

  case 389:
/* Line 1792 of yacc.c  */
#line 2238 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      conf_error_report("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      conf_error_report("Server passwords cannot contain spaces");
    else
    {
      if (yy_aconf->spasswd != NULL)
        memset(yy_aconf->spasswd, 0, strlen(yy_aconf->spasswd));

      MyFree(yy_aconf->spasswd);
      DupString(yy_aconf->spasswd, yylval.string);
    }
  }
}
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2257 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      conf_error_report("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      conf_error_report("Server passwords cannot contain spaces");
    else
    {
      if (yy_aconf->passwd != NULL)
        memset(yy_aconf->passwd, 0, strlen(yy_aconf->passwd));

      MyFree(yy_aconf->passwd);
      DupString(yy_aconf->passwd, yylval.string);
    }
  }
}
    break;

  case 391:
/* Line 1792 of yacc.c  */
#line 2276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 392:
/* Line 1792 of yacc.c  */
#line 2282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 393:
/* Line 1792 of yacc.c  */
#line 2286 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 394:
/* Line 1792 of yacc.c  */
#line 2294 "conf_parser.y"
    {
}
    break;

  case 398:
/* Line 1792 of yacc.c  */
#line 2299 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 399:
/* Line 1792 of yacc.c  */
#line 2303 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 400:
/* Line 1792 of yacc.c  */
#line 2309 "conf_parser.y"
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

  case 401:
/* Line 1792 of yacc.c  */
#line 2320 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 402:
/* Line 1792 of yacc.c  */
#line 2331 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 403:
/* Line 1792 of yacc.c  */
#line 2342 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 404:
/* Line 1792 of yacc.c  */
#line 2351 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->cipher_list);
    DupString(yy_aconf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    conf_error_report("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 405:
/* Line 1792 of yacc.c  */
#line 2369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 406:
/* Line 1792 of yacc.c  */
#line 2376 "conf_parser.y"
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
          DupString(yy_aconf->reason, CONF_NOREASON);
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
          DupString(yy_aconf->reason, CONF_NOREASON);
        add_conf_by_address(CONF_KLINE, yy_aconf);
      }
    }

    yy_aconf = NULL;
  }
}
    break;

  case 407:
/* Line 1792 of yacc.c  */
#line 2434 "conf_parser.y"
    {
}
    break;

  case 411:
/* Line 1792 of yacc.c  */
#line 2439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 418:
/* Line 1792 of yacc.c  */
#line 2448 "conf_parser.y"
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

  case 419:
/* Line 1792 of yacc.c  */
#line 2467 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 2476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 421:
/* Line 1792 of yacc.c  */
#line 2480 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      find_and_delete_temporary(NULL, hostbuf, CONF_DLINE|1);

      yy_aconf = map_to_conf(make_conf_item(DLINE_TYPE));
      DupString(yy_aconf->host, hostbuf);

      if (reasonbuf[0])
        DupString(yy_aconf->reason, reasonbuf);
      else
        DupString(yy_aconf->reason, CONF_NOREASON);
      add_conf_by_address(CONF_DLINE, yy_aconf);
      yy_aconf = NULL;
    }
  }
}
    break;

  case 427:
/* Line 1792 of yacc.c  */
#line 2504 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 428:
/* Line 1792 of yacc.c  */
#line 2510 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 434:
/* Line 1792 of yacc.c  */
#line 2524 "conf_parser.y"
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

  case 435:
/* Line 1792 of yacc.c  */
#line 2542 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 436:
/* Line 1792 of yacc.c  */
#line 2549 "conf_parser.y"
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
        DupString(yy_match_item->reason, CONF_NOREASON);
    }
  }
}
    break;

  case 437:
/* Line 1792 of yacc.c  */
#line 2589 "conf_parser.y"
    {
}
    break;

  case 441:
/* Line 1792 of yacc.c  */
#line 2594 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 448:
/* Line 1792 of yacc.c  */
#line 2603 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 449:
/* Line 1792 of yacc.c  */
#line 2609 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 2659 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 2671 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 2677 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 2682 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 2687 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 2702 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 2753 "conf_parser.y"
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

  case 523:
/* Line 1792 of yacc.c  */
#line 2764 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 2769 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 2774 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 2779 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 2792 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 2797 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 534:
/* Line 1792 of yacc.c  */
#line 2815 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 535:
/* Line 1792 of yacc.c  */
#line 2820 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 536:
/* Line 1792 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 2830 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 2845 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 2866 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 2880 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 2894 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 548:
/* Line 1792 of yacc.c  */
#line 2899 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 2910 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 2919 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 557:
/* Line 1792 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 558:
/* Line 1792 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 559:
/* Line 1792 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 560:
/* Line 1792 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 2943 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 2949 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 2952 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 2955 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 2958 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 2964 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 572:
/* Line 1792 of yacc.c  */
#line 2967 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 573:
/* Line 1792 of yacc.c  */
#line 2972 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 2978 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 2981 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 579:
/* Line 1792 of yacc.c  */
#line 2984 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 580:
/* Line 1792 of yacc.c  */
#line 2987 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 2990 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 582:
/* Line 1792 of yacc.c  */
#line 2993 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 583:
/* Line 1792 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 584:
/* Line 1792 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 585:
/* Line 1792 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 586:
/* Line 1792 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 587:
/* Line 1792 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 588:
/* Line 1792 of yacc.c  */
#line 3011 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 589:
/* Line 1792 of yacc.c  */
#line 3014 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 590:
/* Line 1792 of yacc.c  */
#line 3017 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 591:
/* Line 1792 of yacc.c  */
#line 3020 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 592:
/* Line 1792 of yacc.c  */
#line 3023 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 593:
/* Line 1792 of yacc.c  */
#line 3026 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 594:
/* Line 1792 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 595:
/* Line 1792 of yacc.c  */
#line 3032 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 596:
/* Line 1792 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 597:
/* Line 1792 of yacc.c  */
#line 3040 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 598:
/* Line 1792 of yacc.c  */
#line 3045 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:
/* Line 1792 of yacc.c  */
#line 3050 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1792 of yacc.c  */
#line 3073 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 619:
/* Line 1792 of yacc.c  */
#line 3078 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 620:
/* Line 1792 of yacc.c  */
#line 3083 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1792 of yacc.c  */
#line 3088 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 622:
/* Line 1792 of yacc.c  */
#line 3093 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1792 of yacc.c  */
#line 3098 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1792 of yacc.c  */
#line 3103 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 625:
/* Line 1792 of yacc.c  */
#line 3108 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 626:
/* Line 1792 of yacc.c  */
#line 3113 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 627:
/* Line 1792 of yacc.c  */
#line 3118 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 628:
/* Line 1792 of yacc.c  */
#line 3123 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 629:
/* Line 1792 of yacc.c  */
#line 3128 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 630:
/* Line 1792 of yacc.c  */
#line 3133 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 631:
/* Line 1792 of yacc.c  */
#line 3138 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 642:
/* Line 1792 of yacc.c  */
#line 3156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 643:
/* Line 1792 of yacc.c  */
#line 3162 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 644:
/* Line 1792 of yacc.c  */
#line 3168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 645:
/* Line 1792 of yacc.c  */
#line 3177 "conf_parser.y"
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

  case 646:
/* Line 1792 of yacc.c  */
#line 3191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 647:
/* Line 1792 of yacc.c  */
#line 3197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1792 of yacc.c  */
#line 7024 "conf_parser.c"
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


