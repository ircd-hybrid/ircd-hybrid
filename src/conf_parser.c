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
     T_OPERWALL = 446,
     T_RECVQ = 447,
     T_REJ = 448,
     T_SERVER = 449,
     T_SERVNOTICE = 450,
     T_SET = 451,
     T_SKILL = 452,
     T_SPY = 453,
     T_SSL = 454,
     T_UMODES = 455,
     T_UNAUTH = 456,
     T_UNDLINE = 457,
     T_UNLIMITED = 458,
     T_UNRESV = 459,
     T_UNXLINE = 460,
     T_GLOBOPS = 461,
     T_WALLOP = 462,
     T_RESTART = 463,
     T_SERVICE = 464,
     T_SERVICES_NAME = 465,
     THROTTLE_TIME = 466,
     TRUE_NO_OPER_FLOOD = 467,
     UNKLINE = 468,
     USER = 469,
     USE_EGD = 470,
     USE_LOGGING = 471,
     VHOST = 472,
     VHOST6 = 473,
     XLINE = 474,
     WARN_NO_NLINE = 475,
     T_SIZE = 476,
     T_FILE = 477
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
#define T_OPERWALL 446
#define T_RECVQ 447
#define T_REJ 448
#define T_SERVER 449
#define T_SERVNOTICE 450
#define T_SET 451
#define T_SKILL 452
#define T_SPY 453
#define T_SSL 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_GLOBOPS 461
#define T_WALLOP 462
#define T_RESTART 463
#define T_SERVICE 464
#define T_SERVICES_NAME 465
#define THROTTLE_TIME 466
#define TRUE_NO_OPER_FLOOD 467
#define UNKLINE 468
#define USER 469
#define USE_EGD 470
#define USE_LOGGING 471
#define VHOST 472
#define VHOST6 473
#define XLINE 474
#define WARN_NO_NLINE 475
#define T_SIZE 476
#define T_FILE 477



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 111 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 647 "conf_parser.c"
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
#line 675 "conf_parser.c"

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
#define YYLAST   1248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  291
/* YYNRULES -- Number of rules.  */
#define YYNRULES  644
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1263

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   477

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   227,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   223,
       2,   226,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   225,     2,   224,     2,     2,     2,     2,
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
     215,   216,   217,   218,   219,   220,   221,   222
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
     820,   822,   825,   830,   835,   840,   845,   846,   852,   856,
     858,   860,   862,   864,   866,   868,   870,   872,   874,   876,
     881,   886,   891,   892,   899,   902,   904,   906,   908,   910,
     913,   918,   923,   928,   934,   937,   939,   941,   943,   948,
     949,   956,   959,   961,   963,   965,   967,   970,   975,   980,
     981,   987,   991,   993,   995,   997,   999,  1001,  1003,  1005,
    1007,  1009,  1011,  1013,  1014,  1021,  1024,  1026,  1028,  1030,
    1033,  1038,  1039,  1045,  1049,  1051,  1053,  1055,  1057,  1059,
    1061,  1063,  1065,  1067,  1069,  1071,  1072,  1079,  1082,  1084,
    1086,  1088,  1090,  1092,  1094,  1096,  1098,  1100,  1102,  1104,
    1106,  1108,  1110,  1113,  1118,  1123,  1128,  1133,  1138,  1143,
    1148,  1153,  1154,  1160,  1164,  1166,  1168,  1170,  1175,  1180,
    1185,  1190,  1195,  1196,  1203,  1204,  1210,  1214,  1216,  1218,
    1221,  1223,  1225,  1227,  1229,  1231,  1236,  1241,  1242,  1249,
    1252,  1254,  1256,  1258,  1260,  1265,  1270,  1276,  1279,  1281,
    1283,  1285,  1290,  1291,  1298,  1299,  1305,  1309,  1311,  1313,
    1316,  1318,  1320,  1322,  1324,  1326,  1331,  1336,  1342,  1345,
    1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,  1363,  1365,
    1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,  1383,  1385,
    1387,  1389,  1391,  1393,  1395,  1397,  1399,  1401,  1403,  1405,
    1407,  1409,  1411,  1413,  1415,  1417,  1419,  1421,  1423,  1425,
    1427,  1429,  1431,  1433,  1435,  1437,  1439,  1441,  1443,  1445,
    1447,  1452,  1457,  1462,  1467,  1472,  1477,  1482,  1487,  1492,
    1497,  1502,  1507,  1512,  1517,  1522,  1527,  1532,  1537,  1542,
    1547,  1552,  1557,  1562,  1567,  1572,  1577,  1582,  1587,  1592,
    1597,  1602,  1607,  1612,  1617,  1622,  1627,  1632,  1637,  1642,
    1647,  1652,  1657,  1662,  1667,  1672,  1677,  1678,  1684,  1688,
    1690,  1692,  1694,  1696,  1698,  1700,  1702,  1704,  1706,  1708,
    1710,  1712,  1714,  1716,  1718,  1720,  1722,  1724,  1726,  1728,
    1730,  1731,  1737,  1741,  1743,  1745,  1747,  1749,  1751,  1753,
    1755,  1757,  1759,  1761,  1763,  1765,  1767,  1769,  1771,  1773,
    1775,  1777,  1779,  1781,  1783,  1788,  1793,  1798,  1804,  1807,
    1809,  1811,  1813,  1815,  1817,  1819,  1821,  1823,  1825,  1827,
    1829,  1831,  1833,  1835,  1837,  1839,  1844,  1849,  1854,  1859,
    1864,  1869,  1874,  1879,  1884,  1889,  1894,  1899,  1904,  1909,
    1915,  1918,  1920,  1922,  1924,  1926,  1928,  1930,  1932,  1934,
    1939,  1944,  1949,  1954,  1959
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     229,     0,    -1,    -1,   229,   230,    -1,   264,    -1,   270,
      -1,   284,    -1,   493,    -1,   302,    -1,   326,    -1,   340,
      -1,   240,    -1,   510,    -1,   355,    -1,   362,    -1,   366,
      -1,   376,    -1,   385,    -1,   405,    -1,   415,    -1,   421,
      -1,   435,    -1,   425,    -1,   235,    -1,     1,   223,    -1,
       1,   224,    -1,    -1,   232,    -1,   105,   231,    -1,   105,
     144,   231,    -1,   105,   145,   231,    -1,   105,   146,   231,
      -1,   105,   147,   231,    -1,   105,   148,   231,    -1,   105,
     149,   231,    -1,   105,   150,   231,    -1,    -1,   234,    -1,
     105,   233,    -1,   105,     9,   233,    -1,   105,    10,   233,
      -1,   105,    11,   233,    -1,    94,   225,   236,   224,   223,
      -1,   236,   237,    -1,   237,    -1,   238,    -1,   239,    -1,
       1,   223,    -1,    93,   226,   124,   223,    -1,   119,   226,
     124,   223,    -1,   154,   225,   241,   224,   223,    -1,   241,
     242,    -1,   242,    -1,   253,    -1,   258,    -1,   263,    -1,
     255,    -1,   256,    -1,   257,    -1,   260,    -1,   261,    -1,
     262,    -1,   251,    -1,   250,    -1,   259,    -1,   254,    -1,
     249,    -1,   243,    -1,   244,    -1,   252,    -1,     1,   223,
      -1,   138,   226,   245,   223,    -1,   139,   226,   247,   223,
      -1,   245,   227,   246,    -1,   246,    -1,   140,    -1,   141,
      -1,   247,   227,   248,    -1,   248,    -1,   140,    -1,   141,
      -1,   136,   226,   124,   223,    -1,   134,   226,   124,   223,
      -1,   137,   226,   124,   223,    -1,   179,   226,   124,   223,
      -1,    95,   226,   124,   223,    -1,   155,   226,   124,   223,
      -1,    24,   226,   124,   223,    -1,    98,   226,   124,   223,
      -1,    97,   226,   124,   223,    -1,   217,   226,   124,   223,
      -1,   218,   226,   124,   223,    -1,   189,   226,   105,   223,
      -1,    80,   226,   105,   223,    -1,    84,   226,   105,   223,
      -1,    57,   226,   168,   223,    -1,     4,   225,   265,   224,
     223,    -1,   265,   266,    -1,   266,    -1,   267,    -1,   269,
      -1,   268,    -1,     1,   223,    -1,    95,   226,   124,   223,
      -1,    31,   226,   124,   223,    -1,    24,   226,   124,   223,
      -1,    71,   225,   271,   224,   223,    -1,   271,   272,    -1,
     272,    -1,   273,    -1,   274,    -1,     1,   223,    -1,   216,
     226,   168,   223,    -1,    -1,   275,   222,   225,   276,   224,
     223,    -1,   276,   277,    -1,   277,    -1,   278,    -1,   280,
      -1,   279,    -1,     1,   223,    -1,    95,   226,   124,   223,
      -1,   221,   226,   234,   223,    -1,   221,   226,   203,   223,
      -1,    -1,   159,   281,   226,   282,   223,    -1,   282,   227,
     283,    -1,   283,    -1,   214,    -1,   108,    -1,    40,    -1,
     182,    -1,    64,    -1,    62,    -1,   181,    -1,    -1,   108,
     285,   225,   286,   224,   223,    -1,   286,   287,    -1,   287,
      -1,   288,    -1,   289,    -1,   290,    -1,   294,    -1,   293,
      -1,   291,    -1,   292,    -1,   298,    -1,     1,   223,    -1,
      95,   226,   124,   223,    -1,   214,   226,   124,   223,    -1,
     118,   226,   124,   223,    -1,    32,   226,   168,   223,    -1,
     135,   226,   124,   223,    -1,    17,   226,   124,   223,    -1,
      -1,   200,   295,   226,   296,   223,    -1,   296,   227,   297,
      -1,   297,    -1,   174,    -1,   177,    -1,   178,    -1,   180,
      -1,   181,    -1,   184,    -1,    51,    -1,   197,    -1,   190,
      -1,   193,    -1,   201,    -1,   198,    -1,   183,    -1,   191,
      -1,   195,    -1,   185,    -1,   207,    -1,   175,    -1,   176,
      -1,   188,    -1,    -1,    36,   299,   226,   300,   223,    -1,
     300,   227,   301,    -1,   301,    -1,    47,    -1,   131,    -1,
      64,    -1,   213,    -1,   182,    -1,   202,    -1,   219,    -1,
      40,    -1,    25,    -1,   208,    -1,   130,    -1,     4,    -1,
     100,    -1,   191,    -1,   206,    -1,   112,    -1,   132,    -1,
     196,    -1,    93,    -1,    -1,    17,   303,   225,   304,   224,
     223,    -1,   304,   305,    -1,   305,    -1,   306,    -1,   317,
      -1,   318,    -1,   307,    -1,   308,    -1,   319,    -1,   309,
      -1,   310,    -1,   311,    -1,   312,    -1,   313,    -1,   314,
      -1,   315,    -1,   316,    -1,   320,    -1,   321,    -1,   322,
      -1,     1,   223,    -1,    95,   226,   124,   223,    -1,   121,
     226,   232,   223,    -1,   122,   226,   232,   223,    -1,   107,
     226,   105,   223,    -1,    19,   226,   232,   223,    -1,    82,
     226,   105,   223,    -1,    76,   226,   105,   223,    -1,    78,
     226,   105,   223,    -1,    77,   226,   105,   223,    -1,   151,
     226,   234,   223,    -1,   192,   226,   234,   223,    -1,    15,
     226,   105,   223,    -1,    16,   226,   105,   223,    -1,   106,
     226,   105,   223,    -1,    89,   226,   232,   223,    -1,    90,
     226,   232,   223,    -1,    -1,    36,   323,   226,   324,   223,
      -1,   324,   227,   325,    -1,   325,    -1,    91,    -1,    92,
      -1,    -1,    70,   327,   225,   332,   224,   223,    -1,    -1,
      36,   329,   226,   330,   223,    -1,   330,   227,   331,    -1,
     331,    -1,   199,    -1,    51,    -1,   194,    -1,   332,   333,
      -1,   333,    -1,   334,    -1,   328,    -1,   338,    -1,   339,
      -1,     1,   223,    -1,    -1,   123,   226,   336,   335,   223,
      -1,   336,   227,   337,    -1,   337,    -1,   105,    -1,   105,
     172,   105,    -1,    61,   226,   124,   223,    -1,    56,   226,
     124,   223,    -1,    -1,    48,   341,   225,   342,   224,   223,
      -1,   342,   343,    -1,   343,    -1,   344,    -1,   345,    -1,
     346,    -1,   348,    -1,   352,    -1,   353,    -1,   354,    -1,
     347,    -1,     1,   223,    -1,   214,   226,   124,   223,    -1,
     118,   226,   124,   223,    -1,    17,   226,   124,   223,    -1,
      32,   226,   168,   223,    -1,    -1,    36,   349,   226,   350,
     223,    -1,   350,   227,   351,    -1,   351,    -1,   162,    -1,
      33,    -1,    65,    -1,    49,    -1,    13,    -1,   104,    -1,
      43,    -1,   143,    -1,    96,    -1,   161,   226,   124,   223,
      -1,   128,   226,   124,   223,    -1,   127,   226,   105,   223,
      -1,    -1,   142,   356,   225,   357,   224,   223,    -1,   357,
     358,    -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,
       1,   223,    -1,   126,   226,   124,   223,    -1,    14,   226,
     124,   223,    -1,    99,   226,   124,   223,    -1,   209,   225,
     363,   224,   223,    -1,   363,   364,    -1,   364,    -1,   365,
      -1,     1,    -1,    95,   226,   124,   223,    -1,    -1,   157,
     367,   225,   368,   224,   223,    -1,   368,   369,    -1,   369,
      -1,   370,    -1,   371,    -1,   372,    -1,     1,   223,    -1,
      95,   226,   124,   223,    -1,   214,   226,   124,   223,    -1,
      -1,   159,   373,   226,   374,   223,    -1,   374,   227,   375,
      -1,   375,    -1,    64,    -1,   213,    -1,   182,    -1,   202,
      -1,   219,    -1,   205,    -1,   142,    -1,   204,    -1,   188,
      -1,   173,    -1,    -1,   158,   377,   225,   378,   224,   223,
      -1,   378,   379,    -1,   379,    -1,   380,    -1,   381,    -1,
       1,   223,    -1,    95,   226,   124,   223,    -1,    -1,   159,
     382,   226,   383,   223,    -1,   383,   227,   384,    -1,   384,
      -1,    64,    -1,   213,    -1,   182,    -1,   202,    -1,   219,
      -1,   205,    -1,   142,    -1,   204,    -1,   188,    -1,   173,
      -1,    -1,    18,   386,   225,   387,   224,   223,    -1,   387,
     388,    -1,   388,    -1,   389,    -1,   390,    -1,   391,    -1,
     392,    -1,   393,    -1,   395,    -1,   394,    -1,   404,    -1,
     396,    -1,   401,    -1,   402,    -1,   403,    -1,   400,    -1,
       1,   223,    -1,    95,   226,   124,   223,    -1,    56,   226,
     124,   223,    -1,   217,   226,   124,   223,    -1,   152,   226,
     124,   223,    -1,     3,   226,   124,   223,    -1,   123,   226,
     105,   223,    -1,     5,   226,   186,   223,    -1,     5,   226,
     187,   223,    -1,    -1,    36,   397,   226,   398,   223,    -1,
     398,   227,   399,    -1,   399,    -1,     8,    -1,   199,    -1,
      32,   226,   168,   223,    -1,    58,   226,   124,   223,    -1,
      68,   226,   124,   223,    -1,    17,   226,   124,   223,    -1,
     179,   226,   124,   223,    -1,    -1,    62,   406,   225,   411,
     224,   223,    -1,    -1,   159,   408,   226,   409,   223,    -1,
     409,   227,   410,    -1,   410,    -1,   129,    -1,   411,   412,
      -1,   412,    -1,   413,    -1,   414,    -1,   407,    -1,     1,
      -1,   214,   226,   124,   223,    -1,   126,   226,   124,   223,
      -1,    -1,    23,   416,   225,   417,   224,   223,    -1,   417,
     418,    -1,   418,    -1,   419,    -1,   420,    -1,     1,    -1,
      61,   226,   124,   223,    -1,   126,   226,   124,   223,    -1,
      34,   225,   422,   224,   223,    -1,   422,   423,    -1,   423,
      -1,   424,    -1,     1,    -1,    61,   226,   124,   223,    -1,
      -1,    38,   426,   225,   431,   224,   223,    -1,    -1,   159,
     428,   226,   429,   223,    -1,   429,   227,   430,    -1,   430,
      -1,   129,    -1,   431,   432,    -1,   432,    -1,   433,    -1,
     434,    -1,   427,    -1,     1,    -1,    95,   226,   124,   223,
      -1,   126,   226,   124,   223,    -1,    39,   225,   436,   224,
     223,    -1,   436,   437,    -1,   437,    -1,   446,    -1,   447,
      -1,   449,    -1,   450,    -1,   451,    -1,   452,    -1,   453,
      -1,   454,    -1,   455,    -1,   456,    -1,   445,    -1,   458,
      -1,   459,    -1,   474,    -1,   461,    -1,   463,    -1,   465,
      -1,   464,    -1,   468,    -1,   462,    -1,   469,    -1,   470,
      -1,   471,    -1,   472,    -1,   473,    -1,   486,    -1,   475,
      -1,   476,    -1,   477,    -1,   482,    -1,   466,    -1,   467,
      -1,   492,    -1,   490,    -1,   491,    -1,   448,    -1,   481,
      -1,   457,    -1,   479,    -1,   480,    -1,   444,    -1,   439,
      -1,   440,    -1,   441,    -1,   442,    -1,   443,    -1,   460,
      -1,   438,    -1,   478,    -1,     1,    -1,    85,   226,   105,
     223,    -1,    42,   226,   168,   223,    -1,    41,   226,   232,
     223,    -1,    44,   226,   232,   223,    -1,    45,   226,   105,
     223,    -1,    46,   226,   105,   223,    -1,   156,   226,   168,
     223,    -1,    63,   226,   232,   223,    -1,    55,   226,   168,
     223,    -1,    59,   226,   168,   223,    -1,    28,   226,   168,
     223,    -1,    35,   226,   168,   223,    -1,     6,   226,   168,
     223,    -1,    81,   226,   232,   223,    -1,    79,   226,   105,
     223,    -1,    72,   226,   105,   223,    -1,     7,   226,   232,
     223,    -1,   171,   226,   232,   223,    -1,   170,   226,   232,
     223,    -1,    50,   226,   105,   223,    -1,    60,   226,   168,
     223,    -1,   220,   226,   168,   223,    -1,   163,   226,   168,
     223,    -1,   166,   226,   168,   223,    -1,   167,   226,   168,
     223,    -1,   165,   226,   168,   223,    -1,   165,   226,   169,
     223,    -1,   164,   226,   168,   223,    -1,   164,   226,   169,
     223,    -1,   116,   226,   232,   223,    -1,    12,   226,   232,
     223,    -1,   109,   226,   168,   223,    -1,   117,   226,   232,
     223,    -1,   160,   226,   168,   223,    -1,   103,   226,   168,
     223,    -1,   212,   226,   168,   223,    -1,   111,   226,   168,
     223,    -1,    86,   226,   124,   223,    -1,    29,   226,   105,
     223,    -1,    83,   226,   105,   223,    -1,   215,   226,   168,
     223,    -1,    30,   226,   124,   223,    -1,   210,   226,   124,
     223,    -1,   120,   226,   168,   223,    -1,    26,   226,   168,
     223,    -1,   211,   226,   232,   223,    -1,    -1,   113,   483,
     226,   484,   223,    -1,   484,   227,   485,    -1,   485,    -1,
     174,    -1,   177,    -1,   178,    -1,   180,    -1,   181,    -1,
     184,    -1,    51,    -1,   197,    -1,   190,    -1,   193,    -1,
     201,    -1,   198,    -1,   183,    -1,   191,    -1,   195,    -1,
     185,    -1,   207,    -1,   175,    -1,   176,    -1,   188,    -1,
      -1,   110,   487,   226,   488,   223,    -1,   488,   227,   489,
      -1,   489,    -1,   174,    -1,   177,    -1,   178,    -1,   180,
      -1,   181,    -1,   184,    -1,   197,    -1,    51,    -1,   190,
      -1,   193,    -1,   201,    -1,   198,    -1,   183,    -1,   191,
      -1,   195,    -1,   185,    -1,   207,    -1,   175,    -1,   176,
      -1,   188,    -1,    87,   226,   105,   223,    -1,    88,   226,
     105,   223,    -1,    20,   226,   105,   223,    -1,    14,   225,
     494,   224,   223,    -1,   494,   495,    -1,   495,    -1,   503,
      -1,   498,    -1,   499,    -1,   500,    -1,   501,    -1,   502,
      -1,   504,    -1,   505,    -1,   506,    -1,   497,    -1,   507,
      -1,   508,    -1,   509,    -1,   496,    -1,     1,    -1,    27,
     226,   168,   223,    -1,   133,   226,   168,   223,    -1,    66,
     226,   232,   223,    -1,    67,   226,   232,   223,    -1,    75,
     226,   105,   223,    -1,    74,   226,   105,   223,    -1,   125,
     226,   168,   223,    -1,    73,   226,   105,   223,    -1,    22,
     226,   105,   223,    -1,    21,   226,   105,   223,    -1,   101,
     226,   168,   223,    -1,   102,   226,   168,   223,    -1,   114,
     226,   105,   223,    -1,   115,   226,   232,   223,    -1,   153,
     225,   511,   224,   223,    -1,   511,   512,    -1,   512,    -1,
     513,    -1,   514,    -1,   516,    -1,   517,    -1,   515,    -1,
     518,    -1,     1,    -1,    37,   226,   168,   223,    -1,    54,
     226,   168,   223,    -1,    52,   226,   124,   223,    -1,    69,
     226,   232,   223,    -1,    51,   226,   168,   223,    -1,    53,
     226,   168,   223,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   337,   337,   338,   341,   342,   343,   344,   345,   346,
     347,   348,   349,   350,   351,   352,   353,   354,   355,   356,
     357,   358,   359,   360,   361,   362,   366,   366,   367,   371,
     375,   379,   383,   387,   391,   395,   403,   403,   404,   405,
     406,   407,   414,   417,   417,   418,   418,   418,   420,   426,
     433,   435,   435,   436,   436,   437,   437,   438,   438,   439,
     439,   440,   441,   442,   442,   443,   443,   444,   444,   445,
     446,   449,   450,   452,   452,   453,   459,   467,   467,   468,
     474,   482,   524,   583,   611,   619,   634,   649,   658,   672,
     681,   709,   739,   764,   786,   808,   817,   819,   819,   820,
     820,   821,   821,   823,   832,   841,   853,   854,   854,   856,
     856,   857,   859,   866,   866,   876,   877,   879,   879,   880,
     880,   882,   887,   890,   896,   895,   901,   901,   902,   906,
     910,   914,   918,   922,   926,   937,   936,  1034,  1034,  1035,
    1035,  1035,  1036,  1036,  1036,  1037,  1037,  1037,  1039,  1048,
    1085,  1097,  1108,  1150,  1160,  1159,  1165,  1165,  1166,  1170,
    1174,  1178,  1182,  1186,  1190,  1194,  1198,  1202,  1206,  1210,
    1214,  1218,  1222,  1226,  1230,  1234,  1238,  1242,  1249,  1248,
    1254,  1254,  1255,  1259,  1263,  1267,  1271,  1275,  1279,  1283,
    1287,  1291,  1295,  1299,  1303,  1307,  1311,  1315,  1319,  1323,
    1327,  1338,  1337,  1387,  1387,  1388,  1389,  1389,  1390,  1391,
    1392,  1393,  1394,  1395,  1396,  1397,  1398,  1399,  1399,  1400,
    1401,  1402,  1403,  1405,  1414,  1420,  1426,  1432,  1438,  1444,
    1450,  1456,  1462,  1468,  1475,  1481,  1487,  1493,  1499,  1506,
    1505,  1510,  1510,  1511,  1515,  1525,  1524,  1541,  1540,  1545,
    1545,  1546,  1550,  1554,  1562,  1562,  1563,  1563,  1563,  1563,
    1563,  1565,  1565,  1567,  1567,  1569,  1583,  1603,  1612,  1625,
    1624,  1693,  1693,  1694,  1694,  1694,  1694,  1695,  1695,  1695,
    1696,  1696,  1698,  1733,  1746,  1755,  1767,  1766,  1770,  1770,
    1771,  1775,  1779,  1783,  1787,  1791,  1795,  1799,  1803,  1809,
    1828,  1838,  1852,  1851,  1867,  1867,  1868,  1868,  1868,  1868,
    1870,  1879,  1894,  1907,  1909,  1909,  1910,  1910,  1912,  1928,
    1927,  1943,  1943,  1944,  1944,  1944,  1944,  1946,  1955,  1978,
    1977,  1983,  1983,  1984,  1988,  1992,  1996,  2000,  2004,  2008,
    2012,  2016,  2020,  2030,  2029,  2046,  2046,  2047,  2047,  2047,
    2049,  2056,  2055,  2061,  2061,  2062,  2066,  2070,  2074,  2078,
    2082,  2086,  2090,  2094,  2098,  2108,  2107,  2158,  2158,  2159,
    2159,  2159,  2160,  2160,  2161,  2161,  2161,  2162,  2162,  2162,
    2163,  2163,  2164,  2166,  2175,  2184,  2210,  2229,  2248,  2254,
    2258,  2267,  2266,  2270,  2270,  2271,  2275,  2281,  2292,  2303,
    2314,  2323,  2342,  2341,  2407,  2406,  2410,  2410,  2411,  2417,
    2417,  2418,  2418,  2418,  2418,  2420,  2439,  2449,  2448,  2473,
    2473,  2474,  2474,  2474,  2476,  2482,  2491,  2493,  2493,  2494,
    2494,  2496,  2515,  2514,  2562,  2561,  2565,  2565,  2566,  2572,
    2572,  2573,  2573,  2573,  2573,  2575,  2581,  2590,  2593,  2593,
    2594,  2594,  2595,  2595,  2596,  2596,  2597,  2597,  2598,  2598,
    2599,  2600,  2601,  2601,  2602,  2602,  2603,  2603,  2604,  2604,
    2605,  2605,  2606,  2606,  2607,  2608,  2608,  2609,  2609,  2610,
    2610,  2611,  2611,  2612,  2612,  2613,  2614,  2614,  2615,  2616,
    2617,  2617,  2618,  2618,  2619,  2620,  2621,  2622,  2622,  2623,
    2626,  2631,  2637,  2643,  2649,  2654,  2659,  2664,  2669,  2674,
    2679,  2684,  2689,  2694,  2699,  2704,  2709,  2714,  2719,  2725,
    2736,  2741,  2746,  2751,  2756,  2761,  2764,  2769,  2772,  2777,
    2782,  2787,  2792,  2797,  2802,  2807,  2812,  2817,  2828,  2833,
    2838,  2843,  2852,  2861,  2866,  2871,  2877,  2876,  2881,  2881,
    2882,  2885,  2888,  2891,  2894,  2897,  2900,  2903,  2906,  2909,
    2912,  2915,  2918,  2921,  2924,  2927,  2930,  2933,  2936,  2939,
    2945,  2944,  2949,  2949,  2950,  2953,  2956,  2959,  2962,  2965,
    2968,  2971,  2974,  2977,  2980,  2983,  2986,  2989,  2992,  2995,
    2998,  3001,  3004,  3007,  3012,  3017,  3022,  3031,  3034,  3034,
    3035,  3036,  3036,  3037,  3037,  3038,  3038,  3039,  3040,  3040,
    3041,  3042,  3042,  3043,  3043,  3045,  3050,  3055,  3060,  3065,
    3070,  3075,  3080,  3085,  3090,  3095,  3100,  3105,  3110,  3118,
    3121,  3121,  3122,  3122,  3123,  3124,  3124,  3125,  3126,  3128,
    3134,  3140,  3149,  3163,  3169
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
  "auth_passwd", "auth_class", "auth_encrypted", "auth_flags", "$@12",
  "auth_flags_items", "auth_flags_item", "auth_spoof", "auth_redir_serv",
  "auth_redir_port", "resv_entry", "$@13", "resv_items", "resv_item",
  "resv_creason", "resv_channel", "resv_nick", "service_entry",
  "service_items", "service_item", "service_name", "shared_entry", "$@14",
  "shared_items", "shared_item", "shared_name", "shared_user",
  "shared_type", "$@15", "shared_types", "shared_type_item",
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
     475,   476,   477,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   228,   229,   229,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   231,   231,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   233,   234,   234,
     234,   234,   235,   236,   236,   237,   237,   237,   238,   239,
     240,   241,   241,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   243,   244,   245,   245,   246,   246,   247,   247,   248,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   265,   266,
     266,   266,   266,   267,   268,   269,   270,   271,   271,   272,
     272,   272,   273,   275,   274,   276,   276,   277,   277,   277,
     277,   278,   279,   279,   281,   280,   282,   282,   283,   283,
     283,   283,   283,   283,   283,   285,   284,   286,   286,   287,
     287,   287,   287,   287,   287,   287,   287,   287,   288,   289,
     290,   291,   292,   293,   295,   294,   296,   296,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   299,   298,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   303,   302,   304,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   323,
     322,   324,   324,   325,   325,   327,   326,   329,   328,   330,
     330,   331,   331,   331,   332,   332,   333,   333,   333,   333,
     333,   335,   334,   336,   336,   337,   337,   338,   339,   341,
     340,   342,   342,   343,   343,   343,   343,   343,   343,   343,
     343,   343,   344,   345,   346,   347,   349,   348,   350,   350,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   352,
     353,   354,   356,   355,   357,   357,   358,   358,   358,   358,
     359,   360,   361,   362,   363,   363,   364,   364,   365,   367,
     366,   368,   368,   369,   369,   369,   369,   370,   371,   373,
     372,   374,   374,   375,   375,   375,   375,   375,   375,   375,
     375,   375,   375,   377,   376,   378,   378,   379,   379,   379,
     380,   382,   381,   383,   383,   384,   384,   384,   384,   384,
     384,   384,   384,   384,   384,   386,   385,   387,   387,   388,
     388,   388,   388,   388,   388,   388,   388,   388,   388,   388,
     388,   388,   388,   389,   390,   391,   392,   393,   394,   395,
     395,   397,   396,   398,   398,   399,   399,   400,   401,   402,
     403,   404,   406,   405,   408,   407,   409,   409,   410,   411,
     411,   412,   412,   412,   412,   413,   414,   416,   415,   417,
     417,   418,   418,   418,   419,   420,   421,   422,   422,   423,
     423,   424,   426,   425,   428,   427,   429,   429,   430,   431,
     431,   432,   432,   432,   432,   433,   434,   435,   436,   436,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   463,   464,   464,   465,
     466,   467,   468,   469,   470,   471,   472,   473,   474,   475,
     476,   477,   478,   479,   480,   481,   483,   482,   484,   484,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     485,   485,   485,   485,   485,   485,   485,   485,   485,   485,
     487,   486,   488,   488,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   489,   489,   489,   489,   489,   489,
     489,   489,   489,   489,   490,   491,   492,   493,   494,   494,
     495,   495,   495,   495,   495,   495,   495,   495,   495,   495,
     495,   495,   495,   495,   495,   496,   497,   498,   499,   500,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   511,   512,   512,   512,   512,   512,   512,   512,   513,
     514,   515,   516,   517,   518
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
       1,     2,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     0,     6,     2,     1,     1,     1,     1,     2,
       4,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     0,
       5,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     2,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,     4,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     4,     4,     4,
       4,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     0,     6,     2,
       1,     1,     1,     1,     4,     4,     5,     2,     1,     1,
       1,     4,     0,     6,     0,     5,     3,     1,     1,     2,
       1,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     5,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   201,   365,   417,     0,
     432,     0,   269,   402,   245,     0,     0,   135,   302,     0,
       0,   319,   343,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    98,    99,   101,   100,   614,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   599,   613,   609,   601,   602,   603,   604,   605,
     600,   606,   607,   608,   610,   611,   612,     0,     0,     0,
     430,     0,     0,   428,   429,     0,   499,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   570,     0,   546,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   449,   497,   491,
     492,   493,   494,   495,   490,   460,   450,   451,   485,   452,
     453,   454,   455,   456,   457,   458,   459,   487,   461,   462,
     496,   464,   469,   465,   467,   466,   480,   481,   468,   470,
     471,   472,   473,   474,   463,   476,   477,   478,   498,   488,
     489,   486,   479,   475,   483,   484,   482,     0,     0,     0,
       0,     0,     0,   108,   109,   110,     0,     0,     0,     0,
       0,    44,    45,    46,     0,     0,   638,     0,     0,     0,
       0,     0,     0,     0,   631,   632,   633,   636,   634,   635,
     637,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      52,    67,    68,    66,    63,    62,    69,    53,    65,    56,
      57,    58,    54,    64,    59,    60,    61,    55,     0,     0,
     317,     0,     0,   315,   316,   102,     0,     0,     0,     0,
      97,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   598,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   208,   209,
     211,   212,   213,   214,   215,   216,   217,   218,   206,   207,
     210,   219,   220,   221,     0,     0,     0,     0,     0,   391,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   368,
     369,   370,   371,   372,   373,   375,   374,   377,   381,   378,
     379,   380,   376,   423,     0,     0,     0,   420,   421,   422,
       0,     0,   427,   444,     0,     0,   434,   443,     0,   440,
     441,   442,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   448,     0,     0,     0,   286,     0,     0,     0,
       0,     0,     0,   272,   273,   274,   275,   280,   276,   277,
     278,   279,   414,     0,   404,     0,   413,     0,   410,   411,
     412,     0,   247,     0,     0,     0,   257,     0,   255,   256,
     258,   259,   111,     0,     0,   107,     0,    47,     0,     0,
       0,    43,     0,     0,     0,   178,     0,     0,     0,   154,
       0,     0,   138,   139,   140,   141,   144,   145,   143,   142,
     146,     0,     0,     0,     0,     0,   305,   306,   307,   308,
       0,     0,     0,     0,     0,     0,     0,   630,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
     329,     0,     0,   322,   323,   324,   325,     0,     0,   351,
       0,   346,   347,   348,     0,     0,   314,     0,     0,     0,
      96,     0,     0,     0,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   597,   222,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   203,   382,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   367,     0,     0,     0,   419,     0,   426,     0,
       0,     0,     0,   439,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   447,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   271,     0,     0,     0,
       0,   409,   260,     0,     0,     0,     0,     0,   254,     0,
     106,     0,     0,     0,    42,   147,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   137,   309,     0,     0,     0,
       0,   304,     0,     0,     0,     0,     0,     0,   629,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
      76,     0,    74,    79,    80,     0,    78,     0,     0,     0,
       0,     0,    50,   326,     0,     0,     0,     0,   321,   349,
       0,     0,     0,   345,     0,   313,   105,   104,   103,   624,
     623,   615,    26,    26,    26,    26,    26,    26,    26,    28,
      27,   617,   618,   622,   620,   619,   625,   626,   627,   628,
     621,   616,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,     0,     0,
     202,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   366,     0,     0,   418,   431,
       0,     0,     0,   433,   512,   516,   530,   596,   544,   510,
     538,   541,   511,   502,   501,   503,   504,   505,   519,   508,
     509,   520,   507,   515,   514,   513,   539,   500,   537,   594,
     595,   534,   531,   581,   574,   591,   592,   575,   576,   577,
     578,   586,   579,   589,   593,   582,   587,   583,   588,   580,
     585,   584,   590,     0,   573,   536,   556,   550,   567,   568,
     551,   552,   553,   554,   562,   555,   565,   569,   558,   563,
     559,   564,   557,   561,   560,   566,     0,   549,   529,   532,
     543,   506,   533,   522,   527,   528,   525,   526,   523,   524,
     518,   517,   542,   545,   535,   540,   521,     0,     0,     0,
       0,     0,     0,     0,     0,   270,     0,     0,     0,   403,
       0,     0,     0,   265,   261,   264,   246,   112,     0,     0,
     124,     0,     0,   116,   117,   119,   118,    48,    49,     0,
       0,     0,     0,     0,     0,     0,     0,   136,     0,     0,
       0,   303,   639,   643,   641,   644,   640,   642,    87,    95,
      93,    94,    85,    89,    88,    82,    81,    83,    71,     0,
      72,     0,    86,    84,    92,    90,    91,     0,     0,     0,
     320,     0,     0,   344,   318,    29,    30,    31,    32,    33,
      34,    35,   234,   235,   227,   243,   244,     0,   242,   229,
     231,   230,   228,   237,   238,   223,   236,   226,   224,   225,
      36,    36,    36,    38,    37,   232,   233,   387,   389,   390,
     400,   397,   395,   396,     0,   394,   384,   398,   399,   383,
     388,   386,   401,   385,   424,   425,   445,   446,   438,     0,
     437,   571,     0,   547,     0,   284,   285,   294,   291,   296,
     293,   292,   298,   295,   297,   290,     0,   289,   283,   301,
     300,   299,   282,   416,   408,     0,   407,   415,   252,   253,
     251,     0,   250,   268,   267,     0,     0,     0,   120,     0,
       0,     0,     0,   115,   153,   151,   193,   190,   189,   182,
     184,   200,   194,   197,   192,   183,   198,   186,   195,   199,
     187,   196,   191,   185,   188,     0,   181,   148,   150,   152,
     164,   158,   175,   176,   159,   160,   161,   162,   170,   163,
     173,   177,   166,   171,   167,   172,   165,   169,   168,   174,
       0,   157,   149,   311,   312,   310,    73,    77,   327,   333,
     339,   342,   335,   341,   336,   340,   338,   334,   337,     0,
     332,   328,   350,   355,   361,   364,   357,   363,   358,   362,
     360,   356,   359,     0,   354,   240,     0,    39,    40,    41,
     392,     0,   435,     0,   572,   548,   287,     0,   405,     0,
     248,     0,   266,   263,   262,     0,     0,     0,     0,   114,
     179,     0,   155,     0,   330,     0,   352,     0,   241,   393,
     436,   288,   406,   249,   121,   130,   133,   132,   129,   134,
     131,   128,     0,   127,   123,   122,   180,   156,   331,   353,
     125,     0,   126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   799,   800,  1053,  1054,    25,   230,   231,
     232,   233,    26,   269,   270,   271,   272,   761,   762,   765,
     766,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,    27,    71,    72,    73,
      74,    75,    28,   222,   223,   224,   225,   226,   972,   973,
     974,   975,   976,  1120,  1252,  1253,    29,    60,   511,   512,
     513,   514,   515,   516,   517,   518,   519,   732,  1170,  1171,
     520,   728,  1145,  1146,    30,    49,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   348,
     349,   350,   351,   352,   353,   601,  1037,  1038,    31,    57,
     486,   713,  1111,  1112,   487,   488,   489,  1117,   964,   965,
     490,   491,    32,    55,   462,   463,   464,   465,   466,   467,
     468,   699,  1096,  1097,   469,   470,   471,    33,    61,   525,
     526,   527,   528,   529,    34,   292,   293,   294,    35,    64,
     562,   563,   564,   565,   566,   775,  1189,  1190,    36,    65,
     570,   571,   572,   573,   781,  1203,  1204,    37,    50,   368,
     369,   370,   371,   372,   373,   374,   375,   376,   377,   622,
    1064,  1065,   378,   379,   380,   381,   382,    38,    56,   476,
     708,  1105,  1106,   477,   478,   479,   480,    39,    51,   386,
     387,   388,   389,    40,   112,   113,   114,    41,    53,   397,
     641,  1079,  1080,   398,   399,   400,   401,    42,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   433,   926,   927,   213,   431,
     903,   904,   214,   215,   216,    43,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    44,   243,   244,   245,   246,   247,   248,   249,
     250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -877
static const yytype_int16 yypact[] =
{
    -877,   686,  -877,  -191,  -210,  -204,  -877,  -877,  -877,  -201,
    -877,  -186,  -877,  -877,  -877,  -177,  -166,  -877,  -877,  -161,
    -147,  -877,  -877,  -142,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,    39,   857,  -131,
    -119,  -112,    16,   -90,   412,   -59,   -43,   -31,     3,    79,
     -23,    14,   644,   459,    43,    54,    27,  -170,    15,    60,
      71,    19,  -877,  -877,  -877,  -877,  -877,    80,    86,   105,
     108,   115,   122,   124,   141,   142,   143,   145,   146,   149,
     155,    25,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,   663,   533,    94,
    -877,   157,    18,  -877,  -877,    88,  -877,   158,   160,   161,
     165,   166,   167,   170,   172,   174,   177,   179,   182,   183,
     185,   186,   189,   194,   199,   200,   202,   203,   204,   209,
     210,   211,   213,   217,   218,   220,  -877,   222,  -877,   226,
     233,   235,   237,   238,   240,   242,   247,   248,   250,   251,
     252,   253,   256,   259,   261,   263,   118,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,   433,    30,   271,
       0,   264,    40,  -877,  -877,  -877,    44,    91,   268,   270,
      22,  -877,  -877,  -877,   469,    11,  -877,   277,   278,   280,
     281,   283,   284,    21,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,   120,   285,   286,   287,   288,   291,   292,   293,   294,
     304,   305,   307,   309,   311,   314,   315,   316,   318,   156,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,    10,    12,
    -877,   321,    75,  -877,  -877,  -877,   299,   357,   402,   325,
    -877,   444,   447,   385,   450,   450,   453,   454,   457,   395,
     399,   465,   450,   403,   405,   351,  -877,   361,   359,   360,
     364,  -877,   366,   373,   374,   376,   377,   380,   381,   382,
     383,   386,   387,   389,   390,   300,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,   394,   392,   393,   404,   407,  -877,
     409,   410,   411,   413,   418,   420,   424,   426,    13,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,   428,   429,    35,  -877,  -877,  -877,
     486,   398,  -877,  -877,   432,   434,  -877,  -877,    28,  -877,
    -877,  -877,   461,   450,   450,   520,   463,   491,   556,   538,
     495,   450,   497,   450,   561,   562,   563,   502,   506,   507,
     450,   575,   579,   450,   583,   584,   567,   587,   588,   526,
     534,   475,   537,   480,   450,   450,   539,   540,   542,   543,
     -83,    48,   546,   547,   450,   450,   592,   450,   549,   550,
     551,   498,  -877,   499,   500,   503,  -877,   504,   505,   509,
     510,   512,   190,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,   516,  -877,   518,  -877,    41,  -877,  -877,
    -877,   523,  -877,   525,   529,   535,  -877,    26,  -877,  -877,
    -877,  -877,  -877,   560,   536,  -877,   163,  -877,   609,   638,
     544,  -877,   545,   564,   566,  -877,   571,   572,   574,  -877,
     576,   231,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,   548,   577,   578,   580,    53,  -877,  -877,  -877,  -877,
     595,   597,   642,   619,   633,   450,   554,  -877,  -877,   683,
     640,   704,   705,   687,   688,   689,   691,   692,   693,    69,
     162,   694,   695,   715,   697,   698,   600,  -877,   601,   599,
    -877,   603,    56,  -877,  -877,  -877,  -877,   604,   605,  -877,
      34,  -877,  -877,  -877,   702,   607,  -877,   610,   611,   612,
    -877,   613,   614,   615,   208,   618,   622,   623,   624,   625,
     626,   639,   645,   647,   649,   652,  -877,  -877,   727,   737,
     450,   637,   760,   771,   775,   776,   450,   450,   758,   780,
     781,   450,   450,   787,   787,   677,  -877,  -877,   778,   136,
     783,   731,   679,   785,   788,   789,   791,   811,   793,   794,
     795,   699,  -877,   797,   801,   703,  -877,   706,  -877,   803,
     804,   707,   711,  -877,   712,   714,   716,   717,   718,   719,
     720,   721,   722,   723,   724,   725,   726,   728,   729,   730,
     732,   733,   734,   738,   739,   740,   741,   742,   743,   744,
     745,   746,   747,   598,   750,   676,   751,   752,   753,   754,
     755,   756,   757,   761,   762,   763,   764,   765,   766,   768,
     769,   770,   772,   773,   774,  -877,  -877,   812,   782,   777,
     814,   849,   836,   859,   870,   779,  -877,   874,   784,   875,
     786,  -877,  -877,   790,   876,   877,   899,   792,  -877,   796,
    -877,   116,   798,   799,  -877,  -877,   881,   813,   800,   882,
     883,   884,   802,   887,   806,  -877,  -877,   888,   889,   890,
     807,  -877,   808,   809,   810,   815,   816,   817,  -877,   818,
     819,   820,   821,   822,   823,   824,   825,   826,   827,  -877,
    -877,  -189,  -877,  -877,  -877,  -172,  -877,   828,   829,   830,
     831,   832,  -877,  -877,   893,   833,   894,   834,  -877,  -877,
     896,   835,   837,  -877,   839,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,   450,   450,   450,   450,   450,   450,   450,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,   840,   841,   842,   255,   843,   844,   845,   846,
     847,   848,   850,   851,   852,   853,   854,    -2,   855,   856,
    -877,   858,   860,   861,   862,   863,    -3,   864,   865,   866,
     867,   868,   869,   871,   872,  -877,   873,   878,  -877,  -877,
     879,   880,   895,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -167,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -162,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,   885,   886,   384,
     891,   892,   897,   898,   900,  -877,   901,   905,   902,  -877,
      77,   903,   904,   908,   906,  -877,  -877,  -877,   907,   909,
    -877,   910,    36,  -877,  -877,  -877,  -877,  -877,  -877,   911,
     914,   541,   915,   916,   917,   713,   918,  -877,   919,   920,
     921,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,    69,
    -877,   162,  -877,  -877,  -877,  -877,  -877,   922,   197,   923,
    -877,   924,   438,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -139,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
     787,   787,   787,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -130,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -107,
    -877,  -877,   598,  -877,   676,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,   -39,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,   -15,  -877,  -877,  -877,  -877,
    -877,    46,  -877,  -877,  -877,   930,   899,   925,  -877,   912,
     926,   -99,   927,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,    64,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
      73,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,    97,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,    98,  -877,  -877,   255,  -877,  -877,  -877,
    -877,    -3,  -877,   895,  -877,  -877,  -877,   384,  -877,   905,
    -877,    77,  -877,  -877,  -877,   928,     4,   931,   932,  -877,
    -877,   541,  -877,   713,  -877,   197,  -877,   438,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,   117,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,     4,  -877
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -877,  -877,  -877,  -433,  -302,  -876,  -613,  -877,  -877,   929,
    -877,  -877,  -877,  -877,   838,  -877,  -877,  -877,    47,  -877,
      61,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,   952,  -877,
    -877,  -877,  -877,  -877,   805,  -877,  -877,  -877,  -877,    65,
    -877,  -877,  -877,  -877,  -877,  -236,  -877,  -877,  -877,   582,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -175,
    -877,  -877,  -877,  -149,  -877,  -877,  -877,   913,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -109,  -877,  -877,
    -877,  -877,  -877,  -123,  -877,   617,  -877,  -877,  -877,   -17,
    -877,  -877,  -877,  -877,  -877,   643,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -117,  -877,  -877,  -877,  -877,  -877,  -877,
     581,  -877,  -877,  -877,  -877,  -877,   933,  -877,  -877,  -877,
    -877,   555,  -877,  -877,  -877,  -877,  -877,  -125,  -877,  -877,
    -877,   552,  -877,  -877,  -877,  -877,  -126,  -877,  -877,  -877,
     748,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,   -98,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -101,  -877,   635,  -877,  -877,  -877,  -877,  -877,
     767,  -877,  -877,  -877,  -877,  1007,  -877,  -877,  -877,  -877,
    -877,  -877,   -85,  -877,   759,  -877,  -877,  -877,  -877,   963,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,    72,  -877,  -877,
    -877,    49,  -877,  -877,  -877,  -877,  -877,  1041,  -877,  -877,
    -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,  -877,
    -877,  -877,  -877,  -877,   934,  -877,  -877,  -877,  -877,  -877,
    -877
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -114
static const yytype_int16 yytable[] =
{
     828,   829,   585,   586,   220,  1062,   827,  1050,  1051,  1052,
     593,   558,   521,   567,   354,    47,   355,   110,   356,   110,
      67,    48,   236,   227,    52,   522,    76,   481,   290,   393,
     357,   472,    45,    46,  1008,   567,   383,   968,  1009,    54,
      67,   220,   472,    68,  1245,   358,    77,    78,    58,   359,
      69,  1010,    79,   295,   521,  1011,  1081,   558,   237,    59,
    1082,  1083,   482,    68,    62,  1084,  1246,   522,  1247,   360,
      69,   361,   238,   239,   240,   241,   290,   111,    63,   111,
     227,   362,   483,    66,  1205,   682,   683,   484,  1206,   393,
     242,    80,    81,  1210,   107,   383,   384,  1211,    82,    83,
      84,   645,   646,   827,  1227,   559,   108,   568,   363,   653,
     523,   655,  1248,   109,    70,   228,  1212,   968,   662,   116,
    1213,   665,   291,   394,   117,   118,    85,    86,  1108,   568,
     119,   969,   676,   677,    70,   115,   364,   524,   120,    87,
      88,   229,   688,   689,   121,   691,   122,   123,   124,   485,
      89,   559,   523,   125,   395,   384,   473,   251,    90,   126,
     127,   385,   128,   129,   130,   365,   217,   473,   131,   560,
     291,   569,   228,   132,  1207,  1208,  1209,   133,   134,   524,
     252,   135,   218,   394,  1216,  1249,  1250,   396,  1217,   474,
     136,   453,   366,   569,   219,   970,  1063,   137,   229,   138,
     474,   139,   234,   140,   141,   142,   143,   454,  1218,   759,
     760,   969,  1219,   253,   395,   560,   684,   685,  1251,   221,
     385,   144,   455,   492,   561,  -113,   456,   145,   146,   147,
     367,   148,   502,   747,   149,   150,   254,   631,   151,   235,
     255,   296,   391,   299,   475,   536,   500,   396,   503,   315,
     717,   256,   642,   257,   258,   475,   221,   971,   782,   635,
    1122,  1179,  -113,   504,   494,   710,   496,   505,   288,  1220,
     561,  1109,   481,  1221,   152,   970,  1110,   740,   153,   289,
     777,   154,   155,   156,   157,   158,   297,  1230,   159,   160,
     259,  1231,   260,   261,   262,   263,  1232,   298,   814,   575,
    1233,   317,   763,   764,   820,   821,   301,   482,   457,   825,
     826,   264,   302,   584,   497,   318,   319,   458,   459,   320,
    1234,  1236,   832,   833,  1235,  1237,   506,   483,   161,   162,
     163,   303,   484,   164,   304,   265,   321,   971,   165,  1180,
    1260,   305,   451,   538,  1261,   266,  1035,  1036,   306,   507,
     307,   460,   792,   793,   794,   795,   796,   797,   798,  1025,
    1026,  1027,  1028,  1029,  1030,  1031,   508,   308,   309,   310,
    1181,   311,   312,   267,   268,   313,   322,   323,   324,  1182,
     556,   314,   325,   390,   402,  1183,   403,   404,   721,   326,
     327,   405,   406,   407,   485,   328,   408,  1087,   409,  1184,
     410,  1185,  1186,   411,   461,   412,   329,   330,   413,   414,
    1187,   415,   416,   116,   705,   417,  1188,  1088,   117,   118,
     418,   331,   332,   577,   119,   419,   420,  1089,   421,   422,
     423,   509,   120,  1090,   453,   424,   425,   426,   121,   427,
     122,   123,   124,   428,   429,   510,   430,   125,   432,  1091,
     454,   333,   434,   126,   127,   734,   128,   129,   130,   435,
     251,   436,   131,   437,   438,   455,   439,   132,   440,   456,
     502,   133,   134,   441,   442,   135,   443,   444,   445,   446,
    1092,   578,   447,   252,   136,   448,   503,   449,  1093,   450,
     493,   137,   334,   138,   498,   139,   499,   140,   141,   142,
     143,   504,  1193,   530,   531,   505,   532,   533,  1228,   534,
     535,   539,   540,   541,   542,   144,   253,   543,   544,   545,
     546,   145,   146,   147,   615,   148,   579,  1094,   149,   150,
     547,   548,   151,   549,   354,   550,   355,   551,   356,   254,
     552,   553,   554,   255,   555,  1126,  1095,   574,   580,   581,
     357,   457,   582,   583,   256,   584,   257,   258,   587,   588,
     458,   459,   589,   590,   506,   358,  1127,   591,   152,   359,
     592,   594,   153,   595,   596,   154,   155,   156,   157,   158,
    1194,  1128,   159,   160,   597,   598,   599,   507,  1129,   360,
     600,   361,   602,   259,   460,   260,   261,   262,   263,   603,
     604,   362,   605,   606,   508,  1130,   607,   608,   609,   610,
     637,  1195,   611,   612,   264,   613,   614,   617,   618,   619,
    1196,   638,   161,   162,   163,   647,  1197,   164,   363,   644,
     620,   648,   165,   621,  1131,   623,   624,   625,   265,   626,
    1198,  1132,  1199,  1200,   627,   236,   628,   461,   266,   883,
     629,  1201,   630,  1133,   633,   634,   364,  1202,   639,   649,
     640,   650,   651,   652,   317,   654,   656,   657,   658,   509,
     659,  1134,  1135,  1136,   660,   661,   267,   268,   318,   319,
     663,   237,   320,   510,   664,   365,     2,     3,   666,   667,
       4,   668,   669,   670,   671,   238,   239,   240,   241,   321,
       5,   673,   672,     6,     7,   674,   675,   678,   679,     8,
     680,   681,   366,   242,   686,   687,   690,   692,   693,   694,
       9,   695,   696,  1137,    10,    11,   697,   906,   719,   698,
     700,   701,  1138,   722,    12,   702,   703,  1139,   704,   322,
     323,   324,   707,  1140,   709,   325,   712,  1141,    13,  1142,
     367,   714,   326,   327,  1143,   715,    14,    15,   328,   720,
    1144,   716,   723,   742,  1150,   743,   744,   724,   725,   329,
     330,   736,   884,   885,   886,   887,   888,   748,   889,   890,
      16,   891,   892,   893,   331,   332,   894,   745,   895,   896,
     726,   897,   727,   898,    17,   899,   900,   729,   730,   901,
     731,   746,   733,   737,   738,   902,   739,   749,   750,   751,
     752,   753,   754,   755,   333,   756,   757,   758,   767,   768,
     769,   770,   771,   772,   773,   774,   784,   779,    18,   776,
     785,   780,   812,   786,   787,   788,   789,   790,   791,    19,
      20,   801,   813,    21,    22,   802,   803,   804,   805,   806,
     907,   908,   909,   910,   911,   334,   912,   913,    76,   914,
     915,   916,   807,   815,   917,   816,   918,   919,   808,   920,
     809,   921,   810,   922,   923,   811,   817,   924,    77,    78,
     818,   819,   822,   925,    79,   823,   824,  1151,  1152,  1153,
    1154,  1155,   827,  1156,  1157,    23,  1158,  1159,  1160,   835,
     830,  1161,   831,  1162,  1163,   836,  1164,   834,  1165,   837,
    1166,  1167,   838,   839,  1168,   840,   841,   842,   843,   844,
    1169,   846,   845,    80,    81,   847,   848,   850,   851,   849,
      82,    83,    84,   852,   853,   854,   947,   855,   950,   856,
     857,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     948,   867,   868,   869,   951,   870,   871,   872,    85,    86,
     952,   873,   874,   875,   876,   877,   878,   879,   880,   881,
     882,    87,    88,   905,   928,   929,   930,   931,   932,   933,
     934,   980,    89,   953,   935,   936,   937,   938,   939,   940,
      90,   941,   942,   943,   954,   944,   945,   946,   956,   958,
     961,   962,   955,   949,   963,   979,   982,   983,   984,   959,
     957,   986,   988,   989,   990,   966,   960,  1017,  1019,   967,
    1021,   977,   978,   300,  1078,  1262,   981,   495,   985,   987,
     991,   992,   993,   994,  1104,  1222,  1225,  1123,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1007,  1012,  1013,  1014,  1015,  1016,  1176,  1020,  1257,  1018,
    1023,  1022,  1024,  1032,  1033,  1034,  1039,  1040,  1041,  1042,
    1043,  1044,  1177,  1045,  1046,  1047,  1048,  1049,  1055,  1056,
    1115,  1057,  1256,  1058,  1059,  1060,  1061,  1066,  1067,  1068,
    1069,  1070,  1071,   735,  1072,  1073,  1074,  1238,  1243,  1223,
    1241,  1075,  1076,  1077,   718,   706,   741,   557,  1085,  1086,
    1258,  1259,   711,  1239,  1098,  1099,   632,   778,  1242,   392,
    1100,  1101,   783,  1102,  1103,  1107,  1113,  1114,  1240,   452,
    1118,  1214,   316,  1116,  1124,  1119,  1121,  1125,  1147,  1148,
    1149,  1172,  1173,  1174,  1175,  1178,  1191,  1192,  1224,     0,
    1229,  1244,  1226,   636,  1254,  1255,  1215,   643,     0,   501,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   537,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   576,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   616
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-877)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     613,   614,   304,   305,     1,     8,   105,     9,    10,    11,
     312,     1,     1,     1,     1,   225,     3,     1,     5,     1,
       1,   225,     1,     1,   225,    14,     1,     1,     1,     1,
      17,     1,   223,   224,   223,     1,     1,     1,   227,   225,
       1,     1,     1,    24,    40,    32,    21,    22,   225,    36,
      31,   223,    27,   223,     1,   227,   223,     1,    37,   225,
     227,   223,    36,    24,   225,   227,    62,    14,    64,    56,
      31,    58,    51,    52,    53,    54,     1,    61,   225,    61,
       1,    68,    56,   225,   223,   168,   169,    61,   227,     1,
      69,    66,    67,   223,   225,     1,    61,   227,    73,    74,
      75,   403,   404,   105,   203,    95,   225,    95,    95,   411,
      99,   413,   108,   225,    95,    93,   223,     1,   420,     1,
     227,   423,    95,    95,     6,     7,   101,   102,    51,    95,
      12,    95,   434,   435,    95,   225,   123,   126,    20,   114,
     115,   119,   444,   445,    26,   447,    28,    29,    30,   123,
     125,    95,    99,    35,   126,    61,   126,     1,   133,    41,
      42,   126,    44,    45,    46,   152,   225,   126,    50,   159,
      95,   159,    93,    55,  1050,  1051,  1052,    59,    60,   126,
      24,    63,   225,    95,   223,   181,   182,   159,   227,   159,
      72,     1,   179,   159,   225,   159,   199,    79,   119,    81,
     159,    83,   225,    85,    86,    87,    88,    17,   223,   140,
     141,    95,   227,    57,   126,   159,   168,   169,   214,   216,
     126,   103,    32,   223,   214,   222,    36,   109,   110,   111,
     217,   113,     1,   535,   116,   117,    80,   224,   120,   225,
      84,   226,   224,   224,   214,   224,   224,   159,    17,   224,
     224,    95,   224,    97,    98,   214,   216,   221,   224,   224,
     224,    64,   222,    32,   224,   224,   222,    36,   225,   223,
     214,   194,     1,   227,   156,   159,   199,   224,   160,   225,
     224,   163,   164,   165,   166,   167,   226,   223,   170,   171,
     134,   227,   136,   137,   138,   139,   223,   226,   600,   224,
     227,     1,   140,   141,   606,   607,   226,    36,   118,   611,
     612,   155,   226,   105,   223,    15,    16,   127,   128,    19,
     223,   223,   186,   187,   227,   227,    95,    56,   210,   211,
     212,   226,    61,   215,   226,   179,    36,   221,   220,   142,
     223,   226,   224,   223,   227,   189,    91,    92,   226,   118,
     226,   161,   144,   145,   146,   147,   148,   149,   150,   792,
     793,   794,   795,   796,   797,   798,   135,   226,   226,   226,
     173,   226,   226,   217,   218,   226,    76,    77,    78,   182,
     224,   226,    82,   226,   226,   188,   226,   226,   225,    89,
      90,   226,   226,   226,   123,    95,   226,    13,   226,   202,
     226,   204,   205,   226,   214,   226,   106,   107,   226,   226,
     213,   226,   226,     1,   224,   226,   219,    33,     6,     7,
     226,   121,   122,   124,    12,   226,   226,    43,   226,   226,
     226,   200,    20,    49,     1,   226,   226,   226,    26,   226,
      28,    29,    30,   226,   226,   214,   226,    35,   226,    65,
      17,   151,   226,    41,    42,   224,    44,    45,    46,   226,
       1,   226,    50,   226,   226,    32,   226,    55,   226,    36,
       1,    59,    60,   226,   226,    63,   226,   226,   226,   226,
      96,   124,   226,    24,    72,   226,    17,   226,   104,   226,
     226,    79,   192,    81,   226,    83,   226,    85,    86,    87,
      88,    32,    64,   226,   226,    36,   226,   226,  1121,   226,
     226,   226,   226,   226,   226,   103,    57,   226,   226,   226,
     226,   109,   110,   111,   224,   113,   124,   143,   116,   117,
     226,   226,   120,   226,     1,   226,     3,   226,     5,    80,
     226,   226,   226,    84,   226,     4,   162,   226,   223,   105,
      17,   118,   105,   168,    95,   105,    97,    98,   105,   105,
     127,   128,   105,   168,    95,    32,    25,   168,   156,    36,
     105,   168,   160,   168,   223,   163,   164,   165,   166,   167,
     142,    40,   170,   171,   223,   226,   226,   118,    47,    56,
     226,    58,   226,   134,   161,   136,   137,   138,   139,   226,
     226,    68,   226,   226,   135,    64,   226,   226,   226,   226,
     124,   173,   226,   226,   155,   226,   226,   223,   226,   226,
     182,   223,   210,   211,   212,   105,   188,   215,    95,   168,
     226,   168,   220,   226,    93,   226,   226,   226,   179,   226,
     202,   100,   204,   205,   226,     1,   226,   214,   189,    51,
     226,   213,   226,   112,   226,   226,   123,   219,   226,   168,
     226,   105,   124,   168,     1,   168,   105,   105,   105,   200,
     168,   130,   131,   132,   168,   168,   217,   218,    15,    16,
     105,    37,    19,   214,   105,   152,     0,     1,   105,   105,
       4,   124,   105,   105,   168,    51,    52,    53,    54,    36,
      14,   226,   168,    17,    18,   168,   226,   168,   168,    23,
     168,   168,   179,    69,   168,   168,   124,   168,   168,   168,
      34,   223,   223,   182,    38,    39,   226,    51,   168,   226,
     226,   226,   191,   124,    48,   226,   226,   196,   226,    76,
      77,    78,   226,   202,   226,    82,   223,   206,    62,   208,
     217,   226,    89,    90,   213,   226,    70,    71,    95,   223,
     219,   226,   124,   168,    51,   168,   124,   223,   223,   106,
     107,   223,   174,   175,   176,   177,   178,   223,   180,   181,
      94,   183,   184,   185,   121,   122,   188,   168,   190,   191,
     226,   193,   226,   195,   108,   197,   198,   226,   226,   201,
     226,   168,   226,   226,   226,   207,   226,   124,   168,   105,
     105,   124,   124,   124,   151,   124,   124,   124,   124,   124,
     105,   124,   124,   223,   223,   226,   124,   223,   142,   226,
     223,   226,   105,   223,   223,   223,   223,   223,   223,   153,
     154,   223,   105,   157,   158,   223,   223,   223,   223,   223,
     174,   175,   176,   177,   178,   192,   180,   181,     1,   183,
     184,   185,   223,   226,   188,   105,   190,   191,   223,   193,
     223,   195,   223,   197,   198,   223,   105,   201,    21,    22,
     105,   105,   124,   207,    27,   105,   105,   174,   175,   176,
     177,   178,   105,   180,   181,   209,   183,   184,   185,   168,
     223,   188,   124,   190,   191,   226,   193,   124,   195,   124,
     197,   198,   124,   124,   201,   124,   105,   124,   124,   124,
     207,   124,   223,    66,    67,   124,   223,   124,   124,   223,
      73,    74,    75,   226,   223,   223,   124,   223,   124,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     168,   223,   223,   223,   105,   223,   223,   223,   101,   102,
     124,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   114,   115,   223,   223,   223,   223,   223,   223,   223,
     223,   168,   125,   124,   223,   223,   223,   223,   223,   223,
     133,   223,   223,   223,   124,   223,   223,   223,   124,   124,
     124,   124,   223,   226,   105,   124,   124,   124,   124,   223,
     226,   124,   124,   124,   124,   223,   226,   124,   124,   223,
     124,   223,   223,    71,   129,  1261,   226,   222,   226,   223,
     223,   223,   223,   223,   129,   105,   124,   972,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,  1009,   223,  1233,   226,
     223,   226,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,  1011,   223,   223,   223,   223,   223,   223,   223,
     172,   223,  1231,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   511,   223,   223,   223,  1206,  1221,  1116,
    1217,   223,   223,   223,   487,   462,   525,   269,   223,   223,
    1235,  1237,   477,  1211,   223,   223,   368,   562,  1219,   112,
     223,   223,   570,   223,   223,   223,   223,   223,  1213,   166,
     223,  1082,    91,   227,   223,   226,   226,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,    -1,
     223,   223,   226,   386,   223,   223,  1084,   398,    -1,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   292,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   335
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   229,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    94,   108,   142,   153,
     154,   157,   158,   209,   230,   235,   240,   264,   270,   284,
     302,   326,   340,   355,   362,   366,   376,   385,   405,   415,
     421,   425,   435,   493,   510,   223,   224,   225,   225,   303,
     386,   416,   225,   426,   225,   341,   406,   327,   225,   225,
     285,   356,   225,   225,   367,   377,   225,     1,    24,    31,
      95,   265,   266,   267,   268,   269,     1,    21,    22,    27,
      66,    67,    73,    74,    75,   101,   102,   114,   115,   125,
     133,   494,   495,   496,   497,   498,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   508,   509,   225,   225,   225,
       1,    61,   422,   423,   424,   225,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    81,    83,
      85,    86,    87,    88,   103,   109,   110,   111,   113,   116,
     117,   120,   156,   160,   163,   164,   165,   166,   167,   170,
     171,   210,   211,   212,   215,   220,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   445,   446,   447,   448,   449,
     450,   451,   452,   453,   454,   455,   456,   457,   458,   459,
     460,   461,   462,   463,   464,   465,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   477,   478,   479,
     480,   481,   482,   486,   490,   491,   492,   225,   225,   225,
       1,   216,   271,   272,   273,   274,   275,     1,    93,   119,
     236,   237,   238,   239,   225,   225,     1,    37,    51,    52,
      53,    54,    69,   511,   512,   513,   514,   515,   516,   517,
     518,     1,    24,    57,    80,    84,    95,    97,    98,   134,
     136,   137,   138,   139,   155,   179,   189,   217,   218,   241,
     242,   243,   244,   249,   250,   251,   252,   253,   254,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   225,   225,
       1,    95,   363,   364,   365,   223,   226,   226,   226,   224,
     266,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   224,   495,     1,    15,    16,
      19,    36,    76,    77,    78,    82,    89,    90,    95,   106,
     107,   121,   122,   151,   192,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,     1,     3,     5,    17,    32,    36,
      56,    58,    68,    95,   123,   152,   179,   217,   387,   388,
     389,   390,   391,   392,   393,   394,   395,   396,   400,   401,
     402,   403,   404,     1,    61,   126,   417,   418,   419,   420,
     226,   224,   423,     1,    95,   126,   159,   427,   431,   432,
     433,   434,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   487,   226,   483,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   224,   437,     1,    17,    32,    36,   118,   127,   128,
     161,   214,   342,   343,   344,   345,   346,   347,   348,   352,
     353,   354,     1,   126,   159,   214,   407,   411,   412,   413,
     414,     1,    36,    56,    61,   123,   328,   332,   333,   334,
     338,   339,   223,   226,   224,   272,   222,   223,   226,   226,
     224,   237,     1,    17,    32,    36,    95,   118,   135,   200,
     214,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     298,     1,    14,    99,   126,   357,   358,   359,   360,   361,
     226,   226,   226,   226,   226,   226,   224,   512,   223,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   224,   242,     1,    95,
     159,   214,   368,   369,   370,   371,   372,     1,    95,   159,
     378,   379,   380,   381,   226,   224,   364,   124,   124,   124,
     223,   105,   105,   168,   105,   232,   232,   105,   105,   105,
     168,   168,   105,   232,   168,   168,   223,   223,   226,   226,
     226,   323,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   224,   305,   223,   226,   226,
     226,   226,   397,   226,   226,   226,   226,   226,   226,   226,
     226,   224,   388,   226,   226,   224,   418,   124,   223,   226,
     226,   428,   224,   432,   168,   232,   232,   105,   168,   168,
     105,   124,   168,   232,   168,   232,   105,   105,   105,   168,
     168,   168,   232,   105,   105,   232,   105,   105,   124,   105,
     105,   168,   168,   226,   168,   226,   232,   232,   168,   168,
     168,   168,   168,   169,   168,   169,   168,   168,   232,   232,
     124,   232,   168,   168,   168,   223,   223,   226,   226,   349,
     226,   226,   226,   226,   226,   224,   343,   226,   408,   226,
     224,   412,   223,   329,   226,   226,   226,   224,   333,   168,
     223,   225,   124,   124,   223,   223,   226,   226,   299,   226,
     226,   226,   295,   226,   224,   287,   223,   226,   226,   226,
     224,   358,   168,   168,   124,   168,   168,   232,   223,   124,
     168,   105,   105,   124,   124,   124,   124,   124,   124,   140,
     141,   245,   246,   140,   141,   247,   248,   124,   124,   105,
     124,   124,   223,   223,   226,   373,   226,   224,   369,   223,
     226,   382,   224,   379,   124,   223,   223,   223,   223,   223,
     223,   223,   144,   145,   146,   147,   148,   149,   150,   231,
     232,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   105,   105,   232,   226,   105,   105,   105,   105,
     232,   232,   124,   105,   105,   232,   232,   105,   234,   234,
     223,   124,   186,   187,   124,   168,   226,   124,   124,   124,
     124,   105,   124,   124,   124,   223,   124,   124,   223,   223,
     124,   124,   226,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,    51,   174,   175,   176,   177,   178,   180,
     181,   183,   184,   185,   188,   190,   191,   193,   195,   197,
     198,   201,   207,   488,   489,   223,    51,   174,   175,   176,
     177,   178,   180,   181,   183,   184,   185,   188,   190,   191,
     193,   195,   197,   198,   201,   207,   484,   485,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   124,   168,   226,
     124,   105,   124,   124,   124,   223,   124,   226,   124,   223,
     226,   124,   124,   105,   336,   337,   223,   223,     1,    95,
     159,   221,   276,   277,   278,   279,   280,   223,   223,   124,
     168,   226,   124,   124,   124,   226,   124,   223,   124,   124,
     124,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   227,
     223,   227,   223,   223,   223,   223,   223,   124,   226,   124,
     223,   124,   226,   223,   223,   231,   231,   231,   231,   231,
     231,   231,   223,   223,   223,    91,    92,   324,   325,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
       9,    10,    11,   233,   234,   223,   223,   223,   223,   223,
     223,   223,     8,   199,   398,   399,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   129,   429,
     430,   223,   227,   223,   227,   223,   223,    13,    33,    43,
      49,    65,    96,   104,   143,   162,   350,   351,   223,   223,
     223,   223,   223,   223,   129,   409,   410,   223,    51,   194,
     199,   330,   331,   223,   223,   172,   227,   335,   223,   226,
     281,   226,   224,   277,   223,   223,     4,    25,    40,    47,
      64,    93,   100,   112,   130,   131,   132,   182,   191,   196,
     202,   206,   208,   213,   219,   300,   301,   223,   223,   223,
      51,   174,   175,   176,   177,   178,   180,   181,   183,   184,
     185,   188,   190,   191,   193,   195,   197,   198,   201,   207,
     296,   297,   223,   223,   223,   223,   246,   248,   223,    64,
     142,   173,   182,   188,   202,   204,   205,   213,   219,   374,
     375,   223,   223,    64,   142,   173,   182,   188,   202,   204,
     205,   213,   219,   383,   384,   223,   227,   233,   233,   233,
     223,   227,   223,   227,   489,   485,   223,   227,   223,   227,
     223,   227,   105,   337,   223,   124,   226,   203,   234,   223,
     223,   227,   223,   227,   223,   227,   223,   227,   325,   399,
     430,   351,   410,   331,   223,    40,    62,    64,   108,   181,
     182,   214,   282,   283,   223,   223,   301,   297,   375,   384,
     223,   227,   283
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
#line 366 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 368 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 372 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 376 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 380 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 384 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 388 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 392 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 * 4 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 396 "conf_parser.y"
    {
                        (yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 365 + (yyvsp[(3) - (3)].number);
                }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 403 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 404 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 405 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 406 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 407 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 421 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 427 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 454 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 460 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 469 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 475 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 483 "conf_parser.y"
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
#line 612 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 620 "conf_parser.y"
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
#line 635 "conf_parser.y"
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
#line 650 "conf_parser.y"
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

  case 89:
/* Line 1792 of yacc.c  */
#line 673 "conf_parser.y"
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

  case 91:
/* Line 1792 of yacc.c  */
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

  case 92:
/* Line 1792 of yacc.c  */
#line 740 "conf_parser.y"
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
#line 765 "conf_parser.y"
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
#line 787 "conf_parser.y"
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
#line 809 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 824 "conf_parser.y"
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
#line 833 "conf_parser.y"
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
#line 842 "conf_parser.y"
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
#line 860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 113:
/* Line 1792 of yacc.c  */
#line 866 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 114:
/* Line 1792 of yacc.c  */
#line 871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_set_file(ltype, lsize, lfile);
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 883 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 888 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 891 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 896 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 903 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 907 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 911 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 135:
/* Line 1792 of yacc.c  */
#line 937 "conf_parser.y"
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
#line 950 "conf_parser.y"
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
#line 1040 "conf_parser.y"
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
#line 1049 "conf_parser.y"
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
#line 1086 "conf_parser.y"
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
#line 1098 "conf_parser.y"
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
#line 1109 "conf_parser.y"
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
#line 1151 "conf_parser.y"
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
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1171 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1175 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1179 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1183 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1187 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1191 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1195 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1199 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1203 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1207 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1211 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1215 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1219 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1223 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1239 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1243 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1256 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1260 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1264 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1284 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1288 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1292 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1296 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1300 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1304 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1308 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1312 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1316 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1320 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1324 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1328 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 201:
/* Line 1792 of yacc.c  */
#line 1338 "conf_parser.y"
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
#line 1345 "conf_parser.y"
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

  case 223:
/* Line 1792 of yacc.c  */
#line 1406 "conf_parser.y"
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
#line 1415 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1421 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1427 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1439 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1445 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1451 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1457 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1463 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1469 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1476 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 235:
/* Line 1792 of yacc.c  */
#line 1482 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1494 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->min_idle = (yyvsp[(3) - (4)].number);
}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1500 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_idle = (yyvsp[(3) - (4)].number);
}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1506 "conf_parser.y"
    {
  yy_class->flags = 0;
}
    break;

  case 243:
/* Line 1792 of yacc.c  */
#line 1512 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->flags |= CONF_FLAGS_RANDOM_IDLE;
}
    break;

  case 244:
/* Line 1792 of yacc.c  */
#line 1516 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->flags |= CONF_FLAGS_HIDE_IDLE_FROM_OPERS;
}
    break;

  case 245:
/* Line 1792 of yacc.c  */
#line 1525 "conf_parser.y"
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
#line 1532 "conf_parser.y"
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
#line 1541 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1547 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1551 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 1555 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 261:
/* Line 1792 of yacc.c  */
#line 1565 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 1570 "conf_parser.y"
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
#line 1584 "conf_parser.y"
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
#line 1604 "conf_parser.y"
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
#line 1613 "conf_parser.y"
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
#line 1625 "conf_parser.y"
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
#line 1637 "conf_parser.y"
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

  case 282:
/* Line 1792 of yacc.c  */
#line 1699 "conf_parser.y"
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

  case 283:
/* Line 1792 of yacc.c  */
#line 1734 "conf_parser.y"
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

  case 284:
/* Line 1792 of yacc.c  */
#line 1747 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 1756 "conf_parser.y"
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

  case 286:
/* Line 1792 of yacc.c  */
#line 1767 "conf_parser.y"
    {
}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 1772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 291:
/* Line 1792 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 1780 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 1784 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 1788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 295:
/* Line 1792 of yacc.c  */
#line 1792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 1796 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 1800 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 1804 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 299:
/* Line 1792 of yacc.c  */
#line 1810 "conf_parser.y"
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

  case 300:
/* Line 1792 of yacc.c  */
#line 1829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 301:
/* Line 1792 of yacc.c  */
#line 1839 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 302:
/* Line 1792 of yacc.c  */
#line 1852 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 303:
/* Line 1792 of yacc.c  */
#line 1859 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 1871 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 311:
/* Line 1792 of yacc.c  */
#line 1880 "conf_parser.y"
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

  case 312:
/* Line 1792 of yacc.c  */
#line 1895 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = CONF_NOREASON;

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 1913 "conf_parser.y"
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

  case 319:
/* Line 1792 of yacc.c  */
#line 1928 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 1936 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 327:
/* Line 1792 of yacc.c  */
#line 1947 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 328:
/* Line 1792 of yacc.c  */
#line 1956 "conf_parser.y"
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

  case 329:
/* Line 1792 of yacc.c  */
#line 1978 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 333:
/* Line 1792 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 334:
/* Line 1792 of yacc.c  */
#line 1989 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 335:
/* Line 1792 of yacc.c  */
#line 1993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 336:
/* Line 1792 of yacc.c  */
#line 1997 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 339:
/* Line 1792 of yacc.c  */
#line 2009 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 340:
/* Line 1792 of yacc.c  */
#line 2013 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 2017 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 2021 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 2030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 2037 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 2050 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 2056 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 355:
/* Line 1792 of yacc.c  */
#line 2063 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 356:
/* Line 1792 of yacc.c  */
#line 2067 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 357:
/* Line 1792 of yacc.c  */
#line 2071 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 358:
/* Line 1792 of yacc.c  */
#line 2075 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 359:
/* Line 1792 of yacc.c  */
#line 2079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 360:
/* Line 1792 of yacc.c  */
#line 2083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 361:
/* Line 1792 of yacc.c  */
#line 2087 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 362:
/* Line 1792 of yacc.c  */
#line 2091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 363:
/* Line 1792 of yacc.c  */
#line 2095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 364:
/* Line 1792 of yacc.c  */
#line 2099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 365:
/* Line 1792 of yacc.c  */
#line 2108 "conf_parser.y"
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

  case 366:
/* Line 1792 of yacc.c  */
#line 2123 "conf_parser.y"
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

  case 383:
/* Line 1792 of yacc.c  */
#line 2167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 2176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 2185 "conf_parser.y"
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

  case 386:
/* Line 1792 of yacc.c  */
#line 2211 "conf_parser.y"
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

  case 387:
/* Line 1792 of yacc.c  */
#line 2230 "conf_parser.y"
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

  case 388:
/* Line 1792 of yacc.c  */
#line 2249 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 389:
/* Line 1792 of yacc.c  */
#line 2255 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2259 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 391:
/* Line 1792 of yacc.c  */
#line 2267 "conf_parser.y"
    {
}
    break;

  case 395:
/* Line 1792 of yacc.c  */
#line 2272 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 396:
/* Line 1792 of yacc.c  */
#line 2276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 397:
/* Line 1792 of yacc.c  */
#line 2282 "conf_parser.y"
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

  case 398:
/* Line 1792 of yacc.c  */
#line 2293 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 399:
/* Line 1792 of yacc.c  */
#line 2304 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 400:
/* Line 1792 of yacc.c  */
#line 2315 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 401:
/* Line 1792 of yacc.c  */
#line 2324 "conf_parser.y"
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

  case 402:
/* Line 1792 of yacc.c  */
#line 2342 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 403:
/* Line 1792 of yacc.c  */
#line 2349 "conf_parser.y"
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

  case 404:
/* Line 1792 of yacc.c  */
#line 2407 "conf_parser.y"
    {
}
    break;

  case 408:
/* Line 1792 of yacc.c  */
#line 2412 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 415:
/* Line 1792 of yacc.c  */
#line 2421 "conf_parser.y"
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

  case 416:
/* Line 1792 of yacc.c  */
#line 2440 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 417:
/* Line 1792 of yacc.c  */
#line 2449 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 418:
/* Line 1792 of yacc.c  */
#line 2453 "conf_parser.y"
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

  case 424:
/* Line 1792 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 425:
/* Line 1792 of yacc.c  */
#line 2483 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 431:
/* Line 1792 of yacc.c  */
#line 2497 "conf_parser.y"
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

  case 432:
/* Line 1792 of yacc.c  */
#line 2515 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 433:
/* Line 1792 of yacc.c  */
#line 2522 "conf_parser.y"
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

  case 434:
/* Line 1792 of yacc.c  */
#line 2562 "conf_parser.y"
    {
}
    break;

  case 438:
/* Line 1792 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 445:
/* Line 1792 of yacc.c  */
#line 2576 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 446:
/* Line 1792 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 2632 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 502:
/* Line 1792 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 2644 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 2655 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 2680 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 2685 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 2700 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 2705 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 2715 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 2726 "conf_parser.y"
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

  case 520:
/* Line 1792 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 2747 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 2752 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 2762 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 2773 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 2783 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 2788 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 2798 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 534:
/* Line 1792 of yacc.c  */
#line 2803 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 535:
/* Line 1792 of yacc.c  */
#line 2808 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 536:
/* Line 1792 of yacc.c  */
#line 2813 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 2818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 2853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 2862 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 2872 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 2877 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 2892 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 2895 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 2898 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 2901 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 557:
/* Line 1792 of yacc.c  */
#line 2904 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 558:
/* Line 1792 of yacc.c  */
#line 2907 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 559:
/* Line 1792 of yacc.c  */
#line 2910 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 560:
/* Line 1792 of yacc.c  */
#line 2913 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 2919 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 2922 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 2925 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 2928 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 2934 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 2937 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 2940 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 2945 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 574:
/* Line 1792 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 575:
/* Line 1792 of yacc.c  */
#line 2954 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 576:
/* Line 1792 of yacc.c  */
#line 2957 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 2960 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 2963 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 579:
/* Line 1792 of yacc.c  */
#line 2966 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 580:
/* Line 1792 of yacc.c  */
#line 2969 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 2972 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 582:
/* Line 1792 of yacc.c  */
#line 2975 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 583:
/* Line 1792 of yacc.c  */
#line 2978 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 584:
/* Line 1792 of yacc.c  */
#line 2981 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 585:
/* Line 1792 of yacc.c  */
#line 2984 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 586:
/* Line 1792 of yacc.c  */
#line 2987 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 587:
/* Line 1792 of yacc.c  */
#line 2990 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 588:
/* Line 1792 of yacc.c  */
#line 2993 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 589:
/* Line 1792 of yacc.c  */
#line 2996 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 590:
/* Line 1792 of yacc.c  */
#line 2999 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 591:
/* Line 1792 of yacc.c  */
#line 3002 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 592:
/* Line 1792 of yacc.c  */
#line 3005 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 593:
/* Line 1792 of yacc.c  */
#line 3008 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 594:
/* Line 1792 of yacc.c  */
#line 3013 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 595:
/* Line 1792 of yacc.c  */
#line 3018 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 596:
/* Line 1792 of yacc.c  */
#line 3023 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 615:
/* Line 1792 of yacc.c  */
#line 3046 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 616:
/* Line 1792 of yacc.c  */
#line 3051 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 617:
/* Line 1792 of yacc.c  */
#line 3056 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 618:
/* Line 1792 of yacc.c  */
#line 3061 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 619:
/* Line 1792 of yacc.c  */
#line 3066 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 620:
/* Line 1792 of yacc.c  */
#line 3071 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 621:
/* Line 1792 of yacc.c  */
#line 3076 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 622:
/* Line 1792 of yacc.c  */
#line 3081 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 623:
/* Line 1792 of yacc.c  */
#line 3086 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 624:
/* Line 1792 of yacc.c  */
#line 3091 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 625:
/* Line 1792 of yacc.c  */
#line 3096 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 626:
/* Line 1792 of yacc.c  */
#line 3101 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 627:
/* Line 1792 of yacc.c  */
#line 3106 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 628:
/* Line 1792 of yacc.c  */
#line 3111 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 639:
/* Line 1792 of yacc.c  */
#line 3129 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 640:
/* Line 1792 of yacc.c  */
#line 3135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 641:
/* Line 1792 of yacc.c  */
#line 3141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 642:
/* Line 1792 of yacc.c  */
#line 3150 "conf_parser.y"
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

  case 643:
/* Line 1792 of yacc.c  */
#line 3164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 644:
/* Line 1792 of yacc.c  */
#line 3170 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1792 of yacc.c  */
#line 6998 "conf_parser.c"
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


