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
     REMOTE = 382,
     REMOTEBAN = 383,
     RESTRICT_CHANNELS = 384,
     RSA_PRIVATE_KEY_FILE = 385,
     RSA_PUBLIC_KEY_FILE = 386,
     SSL_CERTIFICATE_FILE = 387,
     SSL_DH_PARAM_FILE = 388,
     T_SSL_CLIENT_METHOD = 389,
     T_SSL_SERVER_METHOD = 390,
     T_SSLV3 = 391,
     T_TLSV1 = 392,
     RESV = 393,
     RESV_EXEMPT = 394,
     SECONDS = 395,
     MINUTES = 396,
     HOURS = 397,
     DAYS = 398,
     WEEKS = 399,
     SENDQ = 400,
     SEND_PASSWORD = 401,
     SERVERHIDE = 402,
     SERVERINFO = 403,
     IRCD_SID = 404,
     TKLINE_EXPIRE_NOTICES = 405,
     T_SHARED = 406,
     T_CLUSTER = 407,
     TYPE = 408,
     SHORT_MOTD = 409,
     SPOOF = 410,
     SPOOF_NOTICE = 411,
     STATS_E_DISABLED = 412,
     STATS_I_OPER_ONLY = 413,
     STATS_K_OPER_ONLY = 414,
     STATS_O_OPER_ONLY = 415,
     STATS_P_OPER_ONLY = 416,
     TBOOL = 417,
     TMASKED = 418,
     TS_MAX_DELTA = 419,
     TS_WARN_DELTA = 420,
     TWODOTS = 421,
     T_ALL = 422,
     T_BOTS = 423,
     T_SOFTCALLERID = 424,
     T_CALLERID = 425,
     T_CCONN = 426,
     T_CCONN_FULL = 427,
     T_SSL_CIPHER_LIST = 428,
     T_DEAF = 429,
     T_DEBUG = 430,
     T_DLINE = 431,
     T_EXTERNAL = 432,
     T_FULL = 433,
     T_INVISIBLE = 434,
     T_IPV4 = 435,
     T_IPV6 = 436,
     T_LOCOPS = 437,
     T_MAX_CLIENTS = 438,
     T_NCHANGE = 439,
     T_OPERWALL = 440,
     T_RECVQ = 441,
     T_REJ = 442,
     T_SERVER = 443,
     T_SERVNOTICE = 444,
     T_SET = 445,
     T_SKILL = 446,
     T_SPY = 447,
     T_SSL = 448,
     T_UMODES = 449,
     T_UNAUTH = 450,
     T_UNDLINE = 451,
     T_UNLIMITED = 452,
     T_UNRESV = 453,
     T_UNXLINE = 454,
     T_GLOBOPS = 455,
     T_WALLOP = 456,
     T_RESTART = 457,
     T_SERVICE = 458,
     T_SERVICES_NAME = 459,
     THROTTLE_TIME = 460,
     TRUE_NO_OPER_FLOOD = 461,
     UNKLINE = 462,
     USER = 463,
     USE_EGD = 464,
     USE_LOGGING = 465,
     VHOST = 466,
     VHOST6 = 467,
     XLINE = 468,
     WARN_NO_NLINE = 469,
     T_SIZE = 470,
     T_FILE = 471
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
#define REMOTE 382
#define REMOTEBAN 383
#define RESTRICT_CHANNELS 384
#define RSA_PRIVATE_KEY_FILE 385
#define RSA_PUBLIC_KEY_FILE 386
#define SSL_CERTIFICATE_FILE 387
#define SSL_DH_PARAM_FILE 388
#define T_SSL_CLIENT_METHOD 389
#define T_SSL_SERVER_METHOD 390
#define T_SSLV3 391
#define T_TLSV1 392
#define RESV 393
#define RESV_EXEMPT 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define SENDQ 400
#define SEND_PASSWORD 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define IRCD_SID 404
#define TKLINE_EXPIRE_NOTICES 405
#define T_SHARED 406
#define T_CLUSTER 407
#define TYPE 408
#define SHORT_MOTD 409
#define SPOOF 410
#define SPOOF_NOTICE 411
#define STATS_E_DISABLED 412
#define STATS_I_OPER_ONLY 413
#define STATS_K_OPER_ONLY 414
#define STATS_O_OPER_ONLY 415
#define STATS_P_OPER_ONLY 416
#define TBOOL 417
#define TMASKED 418
#define TS_MAX_DELTA 419
#define TS_WARN_DELTA 420
#define TWODOTS 421
#define T_ALL 422
#define T_BOTS 423
#define T_SOFTCALLERID 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_CCONN_FULL 427
#define T_SSL_CIPHER_LIST 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FULL 433
#define T_INVISIBLE 434
#define T_IPV4 435
#define T_IPV6 436
#define T_LOCOPS 437
#define T_MAX_CLIENTS 438
#define T_NCHANGE 439
#define T_OPERWALL 440
#define T_RECVQ 441
#define T_REJ 442
#define T_SERVER 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SKILL 446
#define T_SPY 447
#define T_SSL 448
#define T_UMODES 449
#define T_UNAUTH 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_GLOBOPS 455
#define T_WALLOP 456
#define T_RESTART 457
#define T_SERVICE 458
#define T_SERVICES_NAME 459
#define THROTTLE_TIME 460
#define TRUE_NO_OPER_FLOOD 461
#define UNKLINE 462
#define USER 463
#define USE_EGD 464
#define USE_LOGGING 465
#define VHOST 466
#define VHOST6 467
#define XLINE 468
#define WARN_NO_NLINE 469
#define T_SIZE 470
#define T_FILE 471



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 111 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 635 "conf_parser.c"
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
#line 663 "conf_parser.c"

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
#define YYLAST   1203

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  285
/* YYNRULES -- Number of rules.  */
#define YYNRULES  631
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1238

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   471

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   221,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   217,
       2,   220,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   219,     2,   218,     2,     2,     2,     2,
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
     215,   216
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
     154,   156,   158,   160,   162,   164,   166,   168,   170,   173,
     178,   183,   187,   189,   191,   193,   197,   199,   201,   203,
     208,   213,   218,   223,   228,   233,   238,   243,   248,   253,
     258,   263,   268,   273,   278,   284,   287,   289,   291,   293,
     295,   298,   303,   308,   313,   319,   322,   324,   326,   328,
     331,   336,   337,   344,   347,   349,   351,   353,   355,   358,
     363,   368,   373,   374,   380,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   401,   408,   411,   413,   415,   417,
     419,   421,   423,   425,   427,   429,   432,   437,   442,   447,
     452,   457,   462,   463,   469,   473,   475,   477,   479,   481,
     483,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     503,   505,   507,   509,   511,   513,   515,   516,   522,   526,
     528,   530,   532,   534,   536,   538,   540,   542,   544,   546,
     548,   550,   552,   554,   556,   558,   560,   562,   564,   566,
     567,   574,   577,   579,   581,   583,   585,   587,   589,   591,
     593,   595,   597,   599,   601,   603,   605,   607,   610,   615,
     620,   625,   630,   635,   640,   645,   650,   655,   660,   665,
     670,   675,   680,   681,   688,   689,   695,   699,   701,   703,
     705,   707,   710,   712,   714,   716,   718,   720,   723,   724,
     730,   734,   736,   738,   742,   747,   752,   753,   760,   763,
     765,   767,   769,   771,   773,   775,   777,   779,   781,   784,
     789,   794,   799,   804,   805,   811,   815,   817,   819,   821,
     823,   825,   827,   829,   831,   833,   835,   840,   845,   850,
     851,   858,   861,   863,   865,   867,   869,   872,   877,   882,
     887,   893,   896,   898,   900,   902,   907,   908,   915,   918,
     920,   922,   924,   926,   929,   934,   939,   940,   946,   950,
     952,   954,   956,   958,   960,   962,   964,   966,   968,   970,
     972,   973,   980,   983,   985,   987,   989,   992,   997,   998,
    1004,  1008,  1010,  1012,  1014,  1016,  1018,  1020,  1022,  1024,
    1026,  1028,  1030,  1031,  1038,  1041,  1043,  1045,  1047,  1049,
    1051,  1053,  1055,  1057,  1059,  1061,  1063,  1065,  1067,  1069,
    1072,  1077,  1082,  1087,  1092,  1097,  1102,  1107,  1112,  1113,
    1119,  1123,  1125,  1127,  1129,  1134,  1139,  1144,  1149,  1154,
    1155,  1162,  1163,  1169,  1173,  1175,  1177,  1180,  1182,  1184,
    1186,  1188,  1190,  1195,  1200,  1201,  1208,  1211,  1213,  1215,
    1217,  1219,  1224,  1229,  1235,  1238,  1240,  1242,  1244,  1249,
    1250,  1257,  1258,  1264,  1268,  1270,  1272,  1275,  1277,  1279,
    1281,  1283,  1285,  1290,  1295,  1301,  1304,  1306,  1308,  1310,
    1312,  1314,  1316,  1318,  1320,  1322,  1324,  1326,  1328,  1330,
    1332,  1334,  1336,  1338,  1340,  1342,  1344,  1346,  1348,  1350,
    1352,  1354,  1356,  1358,  1360,  1362,  1364,  1366,  1368,  1370,
    1372,  1374,  1376,  1378,  1380,  1382,  1384,  1386,  1388,  1390,
    1392,  1394,  1396,  1398,  1400,  1402,  1404,  1406,  1411,  1416,
    1421,  1426,  1431,  1436,  1441,  1446,  1451,  1456,  1461,  1466,
    1471,  1476,  1481,  1486,  1491,  1496,  1501,  1506,  1511,  1516,
    1521,  1526,  1531,  1536,  1541,  1546,  1551,  1556,  1561,  1566,
    1571,  1576,  1581,  1586,  1591,  1596,  1601,  1606,  1611,  1616,
    1621,  1626,  1631,  1636,  1637,  1643,  1647,  1649,  1651,  1653,
    1655,  1657,  1659,  1661,  1663,  1665,  1667,  1669,  1671,  1673,
    1675,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1690,  1696,
    1700,  1702,  1704,  1706,  1708,  1710,  1712,  1714,  1716,  1718,
    1720,  1722,  1724,  1726,  1728,  1730,  1732,  1734,  1736,  1738,
    1740,  1742,  1747,  1752,  1757,  1763,  1766,  1768,  1770,  1772,
    1774,  1776,  1778,  1780,  1782,  1784,  1786,  1788,  1790,  1792,
    1794,  1796,  1798,  1803,  1808,  1813,  1818,  1823,  1828,  1833,
    1838,  1843,  1848,  1853,  1858,  1863,  1868,  1874,  1877,  1879,
    1881,  1883,  1885,  1887,  1889,  1891,  1893,  1898,  1903,  1908,
    1913,  1918
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     223,     0,    -1,    -1,   223,   224,    -1,   258,    -1,   264,
      -1,   278,    -1,   481,    -1,   296,    -1,   314,    -1,   328,
      -1,   234,    -1,   498,    -1,   343,    -1,   350,    -1,   354,
      -1,   364,    -1,   373,    -1,   393,    -1,   403,    -1,   409,
      -1,   423,    -1,   413,    -1,   229,    -1,     1,   217,    -1,
       1,   218,    -1,    -1,   226,    -1,   101,   225,    -1,   101,
     140,   225,    -1,   101,   141,   225,    -1,   101,   142,   225,
      -1,   101,   143,   225,    -1,   101,   144,   225,    -1,    -1,
     228,    -1,   101,   227,    -1,   101,     9,   227,    -1,   101,
      10,   227,    -1,   101,    11,   227,    -1,    90,   219,   230,
     218,   217,    -1,   230,   231,    -1,   231,    -1,   232,    -1,
     233,    -1,     1,   217,    -1,    89,   220,   120,   217,    -1,
     115,   220,   120,   217,    -1,   148,   219,   235,   218,   217,
      -1,   235,   236,    -1,   236,    -1,   247,    -1,   252,    -1,
     257,    -1,   249,    -1,   250,    -1,   251,    -1,   254,    -1,
     255,    -1,   256,    -1,   245,    -1,   244,    -1,   253,    -1,
     248,    -1,   243,    -1,   237,    -1,   238,    -1,   246,    -1,
       1,   217,    -1,   134,   220,   239,   217,    -1,   135,   220,
     241,   217,    -1,   239,   221,   240,    -1,   240,    -1,   136,
      -1,   137,    -1,   241,   221,   242,    -1,   242,    -1,   136,
      -1,   137,    -1,   132,   220,   120,   217,    -1,   130,   220,
     120,   217,    -1,   133,   220,   120,   217,    -1,   173,   220,
     120,   217,    -1,    91,   220,   120,   217,    -1,   149,   220,
     120,   217,    -1,    24,   220,   120,   217,    -1,    94,   220,
     120,   217,    -1,    93,   220,   120,   217,    -1,   211,   220,
     120,   217,    -1,   212,   220,   120,   217,    -1,   183,   220,
     101,   217,    -1,    80,   220,   101,   217,    -1,    84,   220,
     101,   217,    -1,    57,   220,   162,   217,    -1,     4,   219,
     259,   218,   217,    -1,   259,   260,    -1,   260,    -1,   261,
      -1,   263,    -1,   262,    -1,     1,   217,    -1,    91,   220,
     120,   217,    -1,    31,   220,   120,   217,    -1,    24,   220,
     120,   217,    -1,    71,   219,   265,   218,   217,    -1,   265,
     266,    -1,   266,    -1,   267,    -1,   268,    -1,     1,   217,
      -1,   210,   220,   162,   217,    -1,    -1,   269,   216,   219,
     270,   218,   217,    -1,   270,   271,    -1,   271,    -1,   272,
      -1,   274,    -1,   273,    -1,     1,   217,    -1,    91,   220,
     120,   217,    -1,   215,   220,   228,   217,    -1,   215,   220,
     197,   217,    -1,    -1,   153,   275,   220,   276,   217,    -1,
     276,   221,   277,    -1,   277,    -1,   208,    -1,   104,    -1,
      40,    -1,   176,    -1,    64,    -1,    62,    -1,   175,    -1,
      -1,   104,   279,   219,   280,   218,   217,    -1,   280,   281,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   288,
      -1,   287,    -1,   285,    -1,   286,    -1,   292,    -1,     1,
     217,    -1,    91,   220,   120,   217,    -1,   208,   220,   120,
     217,    -1,   114,   220,   120,   217,    -1,    32,   220,   162,
     217,    -1,   131,   220,   120,   217,    -1,    17,   220,   120,
     217,    -1,    -1,   194,   289,   220,   290,   217,    -1,   290,
     221,   291,    -1,   291,    -1,   168,    -1,   171,    -1,   172,
      -1,   174,    -1,   175,    -1,   178,    -1,    51,    -1,   191,
      -1,   184,    -1,   187,    -1,   195,    -1,   192,    -1,   177,
      -1,   185,    -1,   189,    -1,   179,    -1,   201,    -1,   169,
      -1,   170,    -1,   182,    -1,    -1,    36,   293,   220,   294,
     217,    -1,   294,   221,   295,    -1,   295,    -1,    47,    -1,
     127,    -1,    64,    -1,   207,    -1,   176,    -1,   196,    -1,
     213,    -1,    40,    -1,    25,    -1,   202,    -1,   126,    -1,
       4,    -1,    96,    -1,   185,    -1,   200,    -1,   108,    -1,
     128,    -1,   190,    -1,    89,    -1,    -1,    17,   297,   219,
     298,   218,   217,    -1,   298,   299,    -1,   299,    -1,   300,
      -1,   311,    -1,   312,    -1,   301,    -1,   302,    -1,   313,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,   310,    -1,     1,   217,    -1,
      91,   220,   120,   217,    -1,   117,   220,   226,   217,    -1,
     118,   220,   226,   217,    -1,   103,   220,   101,   217,    -1,
      19,   220,   226,   217,    -1,    82,   220,   101,   217,    -1,
      76,   220,   101,   217,    -1,    78,   220,   101,   217,    -1,
      77,   220,   101,   217,    -1,   145,   220,   228,   217,    -1,
     186,   220,   228,   217,    -1,    15,   220,   101,   217,    -1,
      16,   220,   101,   217,    -1,   102,   220,   101,   217,    -1,
      -1,    70,   315,   219,   320,   218,   217,    -1,    -1,    36,
     317,   220,   318,   217,    -1,   318,   221,   319,    -1,   319,
      -1,   193,    -1,    51,    -1,   188,    -1,   320,   321,    -1,
     321,    -1,   322,    -1,   316,    -1,   326,    -1,   327,    -1,
       1,   217,    -1,    -1,   119,   220,   324,   323,   217,    -1,
     324,   221,   325,    -1,   325,    -1,   101,    -1,   101,   166,
     101,    -1,    61,   220,   120,   217,    -1,    56,   220,   120,
     217,    -1,    -1,    48,   329,   219,   330,   218,   217,    -1,
     330,   331,    -1,   331,    -1,   332,    -1,   333,    -1,   334,
      -1,   336,    -1,   340,    -1,   341,    -1,   342,    -1,   335,
      -1,     1,   217,    -1,   208,   220,   120,   217,    -1,   114,
     220,   120,   217,    -1,    17,   220,   120,   217,    -1,    32,
     220,   162,   217,    -1,    -1,    36,   337,   220,   338,   217,
      -1,   338,   221,   339,    -1,   339,    -1,   156,    -1,    33,
      -1,    65,    -1,    49,    -1,    13,    -1,   100,    -1,    43,
      -1,   139,    -1,    92,    -1,   155,   220,   120,   217,    -1,
     124,   220,   120,   217,    -1,   123,   220,   101,   217,    -1,
      -1,   138,   344,   219,   345,   218,   217,    -1,   345,   346,
      -1,   346,    -1,   347,    -1,   348,    -1,   349,    -1,     1,
     217,    -1,   122,   220,   120,   217,    -1,    14,   220,   120,
     217,    -1,    95,   220,   120,   217,    -1,   203,   219,   351,
     218,   217,    -1,   351,   352,    -1,   352,    -1,   353,    -1,
       1,    -1,    91,   220,   120,   217,    -1,    -1,   151,   355,
     219,   356,   218,   217,    -1,   356,   357,    -1,   357,    -1,
     358,    -1,   359,    -1,   360,    -1,     1,   217,    -1,    91,
     220,   120,   217,    -1,   208,   220,   120,   217,    -1,    -1,
     153,   361,   220,   362,   217,    -1,   362,   221,   363,    -1,
     363,    -1,    64,    -1,   207,    -1,   176,    -1,   196,    -1,
     213,    -1,   199,    -1,   138,    -1,   198,    -1,   182,    -1,
     167,    -1,    -1,   152,   365,   219,   366,   218,   217,    -1,
     366,   367,    -1,   367,    -1,   368,    -1,   369,    -1,     1,
     217,    -1,    91,   220,   120,   217,    -1,    -1,   153,   370,
     220,   371,   217,    -1,   371,   221,   372,    -1,   372,    -1,
      64,    -1,   207,    -1,   176,    -1,   196,    -1,   213,    -1,
     199,    -1,   138,    -1,   198,    -1,   182,    -1,   167,    -1,
      -1,    18,   374,   219,   375,   218,   217,    -1,   375,   376,
      -1,   376,    -1,   377,    -1,   378,    -1,   379,    -1,   380,
      -1,   381,    -1,   383,    -1,   382,    -1,   392,    -1,   384,
      -1,   389,    -1,   390,    -1,   391,    -1,   388,    -1,     1,
     217,    -1,    91,   220,   120,   217,    -1,    56,   220,   120,
     217,    -1,   211,   220,   120,   217,    -1,   146,   220,   120,
     217,    -1,     3,   220,   120,   217,    -1,   119,   220,   101,
     217,    -1,     5,   220,   180,   217,    -1,     5,   220,   181,
     217,    -1,    -1,    36,   385,   220,   386,   217,    -1,   386,
     221,   387,    -1,   387,    -1,     8,    -1,   193,    -1,    32,
     220,   162,   217,    -1,    58,   220,   120,   217,    -1,    68,
     220,   120,   217,    -1,    17,   220,   120,   217,    -1,   173,
     220,   120,   217,    -1,    -1,    62,   394,   219,   399,   218,
     217,    -1,    -1,   153,   396,   220,   397,   217,    -1,   397,
     221,   398,    -1,   398,    -1,   125,    -1,   399,   400,    -1,
     400,    -1,   401,    -1,   402,    -1,   395,    -1,     1,    -1,
     208,   220,   120,   217,    -1,   122,   220,   120,   217,    -1,
      -1,    23,   404,   219,   405,   218,   217,    -1,   405,   406,
      -1,   406,    -1,   407,    -1,   408,    -1,     1,    -1,    61,
     220,   120,   217,    -1,   122,   220,   120,   217,    -1,    34,
     219,   410,   218,   217,    -1,   410,   411,    -1,   411,    -1,
     412,    -1,     1,    -1,    61,   220,   120,   217,    -1,    -1,
      38,   414,   219,   419,   218,   217,    -1,    -1,   153,   416,
     220,   417,   217,    -1,   417,   221,   418,    -1,   418,    -1,
     125,    -1,   419,   420,    -1,   420,    -1,   421,    -1,   422,
      -1,   415,    -1,     1,    -1,    91,   220,   120,   217,    -1,
     122,   220,   120,   217,    -1,    39,   219,   424,   218,   217,
      -1,   424,   425,    -1,   425,    -1,   434,    -1,   435,    -1,
     437,    -1,   438,    -1,   439,    -1,   440,    -1,   441,    -1,
     442,    -1,   443,    -1,   444,    -1,   433,    -1,   446,    -1,
     447,    -1,   462,    -1,   449,    -1,   451,    -1,   453,    -1,
     452,    -1,   456,    -1,   450,    -1,   457,    -1,   458,    -1,
     459,    -1,   460,    -1,   461,    -1,   474,    -1,   463,    -1,
     464,    -1,   465,    -1,   470,    -1,   454,    -1,   455,    -1,
     480,    -1,   478,    -1,   479,    -1,   436,    -1,   469,    -1,
     445,    -1,   467,    -1,   468,    -1,   432,    -1,   427,    -1,
     428,    -1,   429,    -1,   430,    -1,   431,    -1,   448,    -1,
     426,    -1,   466,    -1,     1,    -1,    85,   220,   101,   217,
      -1,    42,   220,   162,   217,    -1,    41,   220,   226,   217,
      -1,    44,   220,   226,   217,    -1,    45,   220,   101,   217,
      -1,    46,   220,   101,   217,    -1,   150,   220,   162,   217,
      -1,    63,   220,   226,   217,    -1,    55,   220,   162,   217,
      -1,    59,   220,   162,   217,    -1,    28,   220,   162,   217,
      -1,    35,   220,   162,   217,    -1,     6,   220,   162,   217,
      -1,    81,   220,   226,   217,    -1,    79,   220,   101,   217,
      -1,    72,   220,   101,   217,    -1,     7,   220,   226,   217,
      -1,   165,   220,   226,   217,    -1,   164,   220,   226,   217,
      -1,    50,   220,   101,   217,    -1,    60,   220,   162,   217,
      -1,   214,   220,   162,   217,    -1,   157,   220,   162,   217,
      -1,   160,   220,   162,   217,    -1,   161,   220,   162,   217,
      -1,   159,   220,   162,   217,    -1,   159,   220,   163,   217,
      -1,   158,   220,   162,   217,    -1,   158,   220,   163,   217,
      -1,   112,   220,   226,   217,    -1,    12,   220,   226,   217,
      -1,   105,   220,   162,   217,    -1,   113,   220,   226,   217,
      -1,   154,   220,   162,   217,    -1,    99,   220,   162,   217,
      -1,   206,   220,   162,   217,    -1,   107,   220,   162,   217,
      -1,    86,   220,   120,   217,    -1,    29,   220,   101,   217,
      -1,    83,   220,   101,   217,    -1,   209,   220,   162,   217,
      -1,    30,   220,   120,   217,    -1,   204,   220,   120,   217,
      -1,   116,   220,   162,   217,    -1,    26,   220,   162,   217,
      -1,   205,   220,   226,   217,    -1,    -1,   109,   471,   220,
     472,   217,    -1,   472,   221,   473,    -1,   473,    -1,   168,
      -1,   171,    -1,   172,    -1,   174,    -1,   175,    -1,   178,
      -1,    51,    -1,   191,    -1,   184,    -1,   187,    -1,   195,
      -1,   192,    -1,   177,    -1,   185,    -1,   189,    -1,   179,
      -1,   201,    -1,   169,    -1,   170,    -1,   182,    -1,    -1,
     106,   475,   220,   476,   217,    -1,   476,   221,   477,    -1,
     477,    -1,   168,    -1,   171,    -1,   172,    -1,   174,    -1,
     175,    -1,   178,    -1,   191,    -1,    51,    -1,   184,    -1,
     187,    -1,   195,    -1,   192,    -1,   177,    -1,   185,    -1,
     189,    -1,   179,    -1,   201,    -1,   169,    -1,   170,    -1,
     182,    -1,    87,   220,   101,   217,    -1,    88,   220,   101,
     217,    -1,    20,   220,   101,   217,    -1,    14,   219,   482,
     218,   217,    -1,   482,   483,    -1,   483,    -1,   491,    -1,
     486,    -1,   487,    -1,   488,    -1,   489,    -1,   490,    -1,
     492,    -1,   493,    -1,   494,    -1,   485,    -1,   495,    -1,
     496,    -1,   497,    -1,   484,    -1,     1,    -1,    27,   220,
     162,   217,    -1,   129,   220,   162,   217,    -1,    66,   220,
     226,   217,    -1,    67,   220,   226,   217,    -1,    75,   220,
     101,   217,    -1,    74,   220,   101,   217,    -1,   121,   220,
     162,   217,    -1,    73,   220,   101,   217,    -1,    22,   220,
     101,   217,    -1,    21,   220,   101,   217,    -1,    97,   220,
     162,   217,    -1,    98,   220,   162,   217,    -1,   110,   220,
     101,   217,    -1,   111,   220,   226,   217,    -1,   147,   219,
     499,   218,   217,    -1,   499,   500,    -1,   500,    -1,   501,
      -1,   502,    -1,   504,    -1,   505,    -1,   503,    -1,   506,
      -1,     1,    -1,    37,   220,   162,   217,    -1,    54,   220,
     162,   217,    -1,    52,   220,   120,   217,    -1,    69,   220,
     226,   217,    -1,    51,   220,   162,   217,    -1,    53,   220,
     162,   217,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   333,   333,   334,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   362,   362,   363,   367,
     371,   375,   379,   383,   389,   389,   390,   391,   392,   393,
     400,   403,   403,   404,   404,   404,   406,   412,   419,   421,
     421,   422,   422,   423,   423,   424,   424,   425,   425,   426,
     427,   428,   428,   429,   429,   430,   430,   431,   432,   435,
     436,   438,   438,   439,   445,   453,   453,   454,   460,   468,
     510,   569,   597,   605,   620,   635,   644,   658,   667,   695,
     725,   750,   772,   794,   803,   805,   805,   806,   806,   807,
     807,   809,   818,   827,   839,   840,   840,   842,   842,   843,
     845,   852,   852,   862,   863,   865,   865,   866,   866,   868,
     873,   876,   882,   881,   887,   887,   888,   892,   896,   900,
     904,   908,   912,   923,   922,  1020,  1020,  1021,  1021,  1021,
    1022,  1022,  1022,  1023,  1023,  1023,  1025,  1034,  1071,  1083,
    1094,  1136,  1146,  1145,  1151,  1151,  1152,  1156,  1160,  1164,
    1168,  1172,  1176,  1180,  1184,  1188,  1192,  1196,  1200,  1204,
    1208,  1212,  1216,  1220,  1224,  1228,  1235,  1234,  1240,  1240,
    1241,  1245,  1249,  1253,  1257,  1261,  1265,  1269,  1273,  1277,
    1281,  1285,  1289,  1293,  1297,  1301,  1305,  1309,  1313,  1324,
    1323,  1373,  1373,  1374,  1375,  1375,  1376,  1377,  1378,  1379,
    1380,  1381,  1382,  1383,  1384,  1385,  1385,  1386,  1388,  1397,
    1403,  1409,  1415,  1421,  1427,  1433,  1439,  1445,  1451,  1458,
    1464,  1470,  1480,  1479,  1496,  1495,  1500,  1500,  1501,  1505,
    1509,  1517,  1517,  1518,  1518,  1518,  1518,  1518,  1520,  1520,
    1522,  1522,  1524,  1538,  1558,  1567,  1580,  1579,  1648,  1648,
    1649,  1649,  1649,  1649,  1650,  1650,  1650,  1651,  1651,  1653,
    1688,  1701,  1710,  1722,  1721,  1725,  1725,  1726,  1730,  1734,
    1738,  1742,  1746,  1750,  1754,  1758,  1764,  1783,  1793,  1807,
    1806,  1822,  1822,  1823,  1823,  1823,  1823,  1825,  1834,  1849,
    1862,  1864,  1864,  1865,  1865,  1867,  1883,  1882,  1898,  1898,
    1899,  1899,  1899,  1899,  1901,  1910,  1933,  1932,  1938,  1938,
    1939,  1943,  1947,  1951,  1955,  1959,  1963,  1967,  1971,  1975,
    1985,  1984,  2001,  2001,  2002,  2002,  2002,  2004,  2011,  2010,
    2016,  2016,  2017,  2021,  2025,  2029,  2033,  2037,  2041,  2045,
    2049,  2053,  2063,  2062,  2113,  2113,  2114,  2114,  2114,  2115,
    2115,  2116,  2116,  2116,  2117,  2117,  2117,  2118,  2118,  2119,
    2121,  2130,  2139,  2165,  2184,  2203,  2209,  2213,  2222,  2221,
    2225,  2225,  2226,  2230,  2236,  2247,  2258,  2269,  2278,  2297,
    2296,  2362,  2361,  2365,  2365,  2366,  2372,  2372,  2373,  2373,
    2373,  2373,  2375,  2394,  2404,  2403,  2428,  2428,  2429,  2429,
    2429,  2431,  2437,  2446,  2448,  2448,  2449,  2449,  2451,  2470,
    2469,  2517,  2516,  2520,  2520,  2521,  2527,  2527,  2528,  2528,
    2528,  2528,  2530,  2536,  2545,  2548,  2548,  2549,  2549,  2550,
    2550,  2551,  2551,  2552,  2552,  2553,  2553,  2554,  2555,  2556,
    2556,  2557,  2557,  2558,  2558,  2559,  2559,  2560,  2560,  2561,
    2561,  2562,  2563,  2563,  2564,  2564,  2565,  2565,  2566,  2566,
    2567,  2567,  2568,  2569,  2569,  2570,  2571,  2572,  2572,  2573,
    2573,  2574,  2575,  2576,  2577,  2577,  2578,  2581,  2586,  2592,
    2598,  2604,  2609,  2614,  2619,  2624,  2629,  2634,  2639,  2644,
    2649,  2654,  2659,  2664,  2669,  2674,  2680,  2691,  2696,  2701,
    2706,  2711,  2716,  2719,  2724,  2727,  2732,  2737,  2742,  2747,
    2752,  2757,  2762,  2767,  2772,  2783,  2788,  2793,  2798,  2807,
    2816,  2821,  2826,  2832,  2831,  2836,  2836,  2837,  2840,  2843,
    2846,  2849,  2852,  2855,  2858,  2861,  2864,  2867,  2870,  2873,
    2876,  2879,  2882,  2885,  2888,  2891,  2894,  2900,  2899,  2904,
    2904,  2905,  2908,  2911,  2914,  2917,  2920,  2923,  2926,  2929,
    2932,  2935,  2938,  2941,  2944,  2947,  2950,  2953,  2956,  2959,
    2962,  2967,  2972,  2977,  2986,  2989,  2989,  2990,  2991,  2991,
    2992,  2992,  2993,  2993,  2994,  2995,  2995,  2996,  2997,  2997,
    2998,  2998,  3000,  3005,  3010,  3015,  3020,  3025,  3030,  3035,
    3040,  3045,  3050,  3055,  3060,  3065,  3073,  3076,  3076,  3077,
    3077,  3078,  3079,  3079,  3080,  3081,  3083,  3089,  3095,  3104,
    3118,  3124
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
  "MIN_NONWILDCARD", "MIN_NONWILDCARD_SIMPLE", "MODULE", "MODULES", "NAME",
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
     465,   466,   467,   468,   469,   470,   471,    59,   125,   123,
      61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   222,   223,   223,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   225,   225,   226,   226,
     226,   226,   226,   226,   227,   227,   228,   228,   228,   228,
     229,   230,   230,   231,   231,   231,   232,   233,   234,   235,
     235,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   237,
     238,   239,   239,   240,   240,   241,   241,   242,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   259,   260,   260,   260,
     260,   261,   262,   263,   264,   265,   265,   266,   266,   266,
     267,   269,   268,   270,   270,   271,   271,   271,   271,   272,
     273,   273,   275,   274,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   279,   278,   280,   280,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   282,   283,   284,   285,
     286,   287,   289,   288,   290,   290,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   293,   292,   294,   294,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   295,   295,   297,
     296,   298,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   315,   314,   317,   316,   318,   318,   319,   319,
     319,   320,   320,   321,   321,   321,   321,   321,   323,   322,
     324,   324,   325,   325,   326,   327,   329,   328,   330,   330,
     331,   331,   331,   331,   331,   331,   331,   331,   331,   332,
     333,   334,   335,   337,   336,   338,   338,   339,   339,   339,
     339,   339,   339,   339,   339,   339,   340,   341,   342,   344,
     343,   345,   345,   346,   346,   346,   346,   347,   348,   349,
     350,   351,   351,   352,   352,   353,   355,   354,   356,   356,
     357,   357,   357,   357,   358,   359,   361,   360,   362,   362,
     363,   363,   363,   363,   363,   363,   363,   363,   363,   363,
     365,   364,   366,   366,   367,   367,   367,   368,   370,   369,
     371,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   374,   373,   375,   375,   376,   376,   376,   376,
     376,   376,   376,   376,   376,   376,   376,   376,   376,   376,
     377,   378,   379,   380,   381,   382,   383,   383,   385,   384,
     386,   386,   387,   387,   388,   389,   390,   391,   392,   394,
     393,   396,   395,   397,   397,   398,   399,   399,   400,   400,
     400,   400,   401,   402,   404,   403,   405,   405,   406,   406,
     406,   407,   408,   409,   410,   410,   411,   411,   412,   414,
     413,   416,   415,   417,   417,   418,   419,   419,   420,   420,
     420,   420,   421,   422,   423,   424,   424,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   425,   425,   425,
     425,   425,   425,   425,   425,   425,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   451,   451,   452,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   471,   470,   472,   472,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   473,   473,   473,
     473,   473,   473,   473,   473,   473,   473,   475,   474,   476,
     476,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   478,   479,   480,   481,   482,   482,   483,   483,   483,
     483,   483,   483,   483,   483,   483,   483,   483,   483,   483,
     483,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   499,   500,
     500,   500,   500,   500,   500,   500,   501,   502,   503,   504,
     505,   506
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       2,     4,     4,     4,     5,     2,     1,     1,     1,     2,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     6,     0,     5,     3,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     2,     0,     5,
       3,     1,     1,     3,     4,     4,     0,     6,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     2,     4,     4,     4,
       5,     2,     1,     1,     1,     4,     0,     6,     2,     1,
       1,     1,     1,     2,     4,     4,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     6,     2,     1,     1,     1,     2,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     4,     4,     4,     4,     4,     0,
       6,     0,     5,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     4,     0,
       6,     0,     5,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     5,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   199,   352,   404,     0,
     419,     0,   256,   389,   232,     0,     0,   133,   289,     0,
       0,   306,   330,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    99,    98,   601,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   586,   600,   596,   588,   589,   590,   591,   592,
     587,   593,   594,   595,   597,   598,   599,     0,     0,     0,
     417,     0,     0,   415,   416,     0,   486,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   557,     0,   533,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   436,   484,   478,
     479,   480,   481,   482,   477,   447,   437,   438,   472,   439,
     440,   441,   442,   443,   444,   445,   446,   474,   448,   449,
     483,   451,   456,   452,   454,   453,   467,   468,   455,   457,
     458,   459,   460,   461,   450,   463,   464,   465,   485,   475,
     476,   473,   466,   462,   470,   471,   469,     0,     0,     0,
       0,     0,     0,   106,   107,   108,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   625,     0,     0,     0,
       0,     0,     0,     0,   618,   619,   620,   623,   621,   622,
     624,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    65,    66,    64,    61,    60,    67,    51,    63,    54,
      55,    56,    52,    62,    57,    58,    59,    53,     0,     0,
     304,     0,     0,   302,   303,   100,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   585,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   202,   203,   206,   207,   209,   210,   211,
     212,   213,   214,   215,   216,   204,   205,   208,     0,     0,
       0,     0,     0,   378,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   355,   356,   357,   358,   359,   360,   362,
     361,   364,   368,   365,   366,   367,   363,   410,     0,     0,
       0,   407,   408,   409,     0,     0,   414,   431,     0,     0,
     421,   430,     0,   427,   428,   429,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   435,     0,     0,     0,
     273,     0,     0,     0,     0,     0,     0,   259,   260,   261,
     262,   267,   263,   264,   265,   266,   401,     0,   391,     0,
     400,     0,   397,   398,   399,     0,   234,     0,     0,     0,
     244,     0,   242,   243,   245,   246,   109,     0,     0,   105,
       0,    45,     0,     0,     0,    41,     0,     0,     0,   176,
       0,     0,     0,   152,     0,     0,   136,   137,   138,   139,
     142,   143,   141,   140,   144,     0,     0,     0,     0,     0,
     292,   293,   294,   295,     0,     0,     0,     0,     0,     0,
       0,   617,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,     0,     0,   316,     0,     0,   309,   310,   311,
     312,     0,     0,   338,     0,   333,   334,   335,     0,     0,
     301,     0,     0,     0,    94,     0,     0,     0,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     584,   217,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   201,   369,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   354,     0,     0,     0,   406,     0,   413,
       0,     0,     0,     0,   426,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   434,   268,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   258,     0,     0,
       0,     0,   396,   247,     0,     0,     0,     0,     0,   241,
       0,   104,     0,     0,     0,    40,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   135,   296,     0,     0,
       0,     0,   291,     0,     0,     0,     0,     0,     0,   616,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,    74,     0,    72,    77,    78,     0,    76,     0,     0,
       0,     0,     0,    48,   313,     0,     0,     0,     0,   308,
     336,     0,     0,     0,   332,     0,   300,   103,   102,   101,
     611,   610,   602,    26,    26,    26,    26,    26,    28,    27,
     604,   605,   609,   607,   606,   612,   613,   614,   615,   608,
     603,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   353,     0,     0,   405,   418,     0,     0,     0,   420,
     499,   503,   517,   583,   531,   497,   525,   528,   498,   489,
     488,   490,   491,   492,   506,   495,   496,   507,   494,   502,
     501,   500,   526,   487,   524,   581,   582,   521,   518,   568,
     561,   578,   579,   562,   563,   564,   565,   573,   566,   576,
     580,   569,   574,   570,   575,   567,   572,   571,   577,     0,
     560,   523,   543,   537,   554,   555,   538,   539,   540,   541,
     549,   542,   552,   556,   545,   550,   546,   551,   544,   548,
     547,   553,     0,   536,   516,   519,   530,   493,   520,   509,
     514,   515,   512,   513,   510,   511,   505,   504,   529,   532,
     522,   527,   508,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,   390,     0,     0,     0,   252,
     248,   251,   233,   110,     0,     0,   122,     0,     0,   114,
     115,   117,   116,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,   134,     0,     0,     0,   290,   626,   630,
     628,   631,   627,   629,    85,    93,    91,    92,    83,    87,
      86,    80,    79,    81,    69,     0,    70,     0,    84,    82,
      90,    88,    89,     0,     0,     0,   307,     0,     0,   331,
     305,    29,    30,    31,    32,    33,   229,   230,   222,   224,
     226,   225,   223,   218,   231,   221,   219,   220,    34,    34,
      34,    36,    35,   227,   228,   374,   376,   377,   387,   384,
     382,   383,     0,   381,   371,   385,   386,   370,   375,   373,
     388,   372,   411,   412,   432,   433,   425,     0,   424,   558,
       0,   534,     0,   271,   272,   281,   278,   283,   280,   279,
     285,   282,   284,   277,     0,   276,   270,   288,   287,   286,
     269,   403,   395,     0,   394,   402,   239,   240,   238,     0,
     237,   255,   254,     0,     0,     0,   118,     0,     0,     0,
       0,   113,   151,   149,   191,   188,   187,   180,   182,   198,
     192,   195,   190,   181,   196,   184,   193,   197,   185,   194,
     189,   183,   186,     0,   179,   146,   148,   150,   162,   156,
     173,   174,   157,   158,   159,   160,   168,   161,   171,   175,
     164,   169,   165,   170,   163,   167,   166,   172,     0,   155,
     147,   298,   299,   297,    71,    75,   314,   320,   326,   329,
     322,   328,   323,   327,   325,   321,   324,     0,   319,   315,
     337,   342,   348,   351,   344,   350,   345,   349,   347,   343,
     346,     0,   341,    37,    38,    39,   379,     0,   422,     0,
     559,   535,   274,     0,   392,     0,   235,     0,   253,   250,
     249,     0,     0,     0,     0,   112,   177,     0,   153,     0,
     317,     0,   339,     0,   380,   423,   275,   393,   236,   119,
     128,   131,   130,   127,   132,   129,   126,     0,   125,   121,
     120,   178,   154,   318,   340,   123,     0,   124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   788,   789,  1031,  1032,    25,   230,   231,
     232,   233,    26,   269,   270,   271,   272,   752,   753,   756,
     757,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,    27,    71,    72,    73,
      74,    75,    28,   222,   223,   224,   225,   226,   958,   959,
     960,   961,   962,  1098,  1227,  1228,    29,    60,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   723,  1148,  1149,
     514,   719,  1123,  1124,    30,    49,   332,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,    31,    57,   480,   704,  1089,  1090,   481,   482,
     483,  1095,   950,   951,   484,   485,    32,    55,   456,   457,
     458,   459,   460,   461,   462,   690,  1074,  1075,   463,   464,
     465,    33,    61,   519,   520,   521,   522,   523,    34,   292,
     293,   294,    35,    64,   556,   557,   558,   559,   560,   766,
    1167,  1168,    36,    65,   564,   565,   566,   567,   772,  1181,
    1182,    37,    50,   362,   363,   364,   365,   366,   367,   368,
     369,   370,   371,   613,  1042,  1043,   372,   373,   374,   375,
     376,    38,    56,   470,   699,  1083,  1084,   471,   472,   473,
     474,    39,    51,   380,   381,   382,   383,    40,   112,   113,
     114,    41,    53,   391,   632,  1057,  1058,   392,   393,   394,
     395,    42,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   427,
     912,   913,   213,   425,   889,   890,   214,   215,   216,    43,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,    44,   243,   244,   245,
     246,   247,   248,   249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -980
static const yytype_int16 yypact[] =
{
    -980,   613,  -980,  -201,  -213,  -211,  -980,  -980,  -980,  -167,
    -980,  -161,  -980,  -980,  -980,  -155,  -139,  -980,  -980,  -129,
    -127,  -980,  -980,  -110,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   263,   780,  -105,
     -94,   -75,    11,   -74,   370,   -51,   -49,   -42,    44,    75,
     -41,   -33,   516,   407,   -32,   -31,    19,   -16,   -18,   -13,
     -11,    17,  -980,  -980,  -980,  -980,  -980,    -7,    -5,     3,
      45,    48,    58,    60,    65,    68,    79,    89,    92,    99,
     104,   230,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   609,   487,    33,
    -980,   111,    20,  -980,  -980,    13,  -980,   118,   130,   133,
     137,   138,   142,   145,   146,   152,   153,   155,   158,   159,
     160,   161,   165,   166,   167,   168,   177,   182,   183,   184,
     186,   193,   197,   198,   199,   202,  -980,   208,  -980,   214,
     215,   219,   220,   221,   223,   224,   226,   234,   240,   241,
     242,   243,   245,   248,   250,   254,   112,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   449,     6,   328,
      -1,   260,    43,  -980,  -980,  -980,   -12,    22,   264,   269,
      18,  -980,  -980,  -980,   435,   180,  -980,   273,   276,   277,
     279,   282,   283,    31,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,   108,   285,   286,   287,   288,   298,   301,   302,   305,
     312,   316,   318,   324,   326,   327,   330,   331,   332,   149,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,    55,    10,
    -980,   334,     8,  -980,  -980,  -980,   325,   428,   437,   176,
    -980,   458,   459,   400,   463,   463,   480,   481,   482,   424,
     425,   488,   463,   426,   430,   376,  -980,   377,   378,   379,
     380,   382,   383,   385,   388,   389,   391,   395,   396,   401,
     402,   406,   292,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   403,   412,
     414,   417,   418,  -980,   419,   420,   421,   422,   433,   436,
     442,   443,    30,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   446,   447,
     173,  -980,  -980,  -980,   524,   429,  -980,  -980,   448,   450,
    -980,  -980,    26,  -980,  -980,  -980,   486,   463,   463,   554,
     510,   512,   576,   560,   519,   463,   526,   463,   577,   588,
     589,   530,   537,   539,   463,   601,   604,   463,   605,   606,
     593,   607,   608,   553,   556,   496,   557,   500,   463,   463,
     559,   562,   563,   566,  -140,  -134,   572,   575,   463,   463,
     602,   463,   579,   580,   582,   506,  -980,   532,   527,   535,
    -980,   538,   543,   551,   564,   568,    37,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   571,  -980,   574,
    -980,    12,  -980,  -980,  -980,   540,  -980,   578,   583,   584,
    -980,     4,  -980,  -980,  -980,  -980,  -980,   597,   569,  -980,
     555,  -980,   658,   659,   591,  -980,   592,   585,   586,  -980,
     590,   599,   603,  -980,   611,    38,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,   612,   616,   617,   619,    88,
    -980,  -980,  -980,  -980,   630,   634,   677,   638,   662,   463,
     623,  -980,  -980,   706,   671,   740,   741,   723,   725,   728,
     729,   730,   731,  -100,   -59,   732,   736,   756,   738,   739,
     644,  -980,   645,   640,  -980,   646,    29,  -980,  -980,  -980,
    -980,   647,   648,  -980,   121,  -980,  -980,  -980,   743,   650,
    -980,   652,   653,   654,  -980,   655,   656,   657,   371,   663,
     664,   665,   666,   667,   668,   669,   670,   672,   675,   676,
    -980,  -980,   764,   774,   463,   775,   778,   787,   793,   776,
     794,   796,   463,   463,   797,   797,   682,  -980,  -980,   782,
     -50,   783,   742,   680,   785,   786,   788,   790,   806,   791,
     792,   795,   696,  -980,   798,   799,   697,  -980,   699,  -980,
     800,   801,   702,   700,  -980,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   724,   726,   727,   733,   734,   735,   737,   744,   745,
     746,   747,   748,   749,   561,   750,   598,   751,   752,   753,
     754,   755,   757,   758,   759,   760,   761,   762,   763,   765,
     766,   767,   768,   769,   770,   771,  -980,  -980,   803,   784,
     772,   820,   841,   825,   827,   828,   773,  -980,   829,   777,
     833,   779,  -980,  -980,   781,   835,   836,   856,   789,  -980,
     802,  -980,    52,   804,   805,  -980,  -980,   838,   811,   807,
     839,   840,   861,   808,   869,   809,  -980,  -980,   871,   873,
     874,   812,  -980,   813,   814,   815,   816,   817,   818,  -980,
     819,   821,   822,   823,   824,   826,   830,   831,   832,   834,
    -980,  -980,  -175,  -980,  -980,  -980,  -160,  -980,   837,   842,
     843,   844,   845,  -980,  -980,   875,   846,   878,   847,  -980,
    -980,   879,   848,   850,  -980,   852,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,   463,   463,   463,   463,   463,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,   853,   854,   855,   857,   858,   859,   860,   862,   863,
     864,   865,   866,    15,   867,   868,  -980,   870,   872,   876,
     877,   880,    -4,   881,   882,   883,   884,   885,   886,   887,
     888,  -980,   889,   890,  -980,  -980,   891,   892,   893,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -158,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -150,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,   894,   895,   558,   896,   897,   898,   899,
     900,  -980,   901,   912,   902,  -980,    -8,   903,   904,    84,
     905,  -980,  -980,  -980,   906,   907,  -980,   908,   105,  -980,
    -980,  -980,  -980,  -980,  -980,   913,   914,   469,   915,   916,
     917,   643,   918,  -980,   919,   920,   921,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -100,  -980,   -59,  -980,  -980,
    -980,  -980,  -980,   922,   225,   923,  -980,   924,   497,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   797,   797,
     797,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -142,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -130,  -980,  -980,
     561,  -980,   598,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -124,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,    69,  -980,  -980,  -980,  -980,  -980,    93,
    -980,  -980,  -980,   909,   856,   925,  -980,   926,   927,   -86,
     928,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,   125,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   126,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   127,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,   128,  -980,  -980,  -980,  -980,  -980,    -4,  -980,   893,
    -980,  -980,  -980,   558,  -980,   912,  -980,    -8,  -980,  -980,
    -980,   929,   251,   931,   932,  -980,  -980,   469,  -980,   643,
    -980,   225,  -980,   497,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,   135,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,   251,  -980
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -980,  -980,  -980,  -450,  -302,  -979,  -604,  -980,  -980,   930,
    -980,  -980,  -980,  -980,   910,  -980,  -980,  -980,     5,  -980,
       7,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   934,  -980,
    -980,  -980,  -980,  -980,   851,  -980,  -980,  -980,  -980,    49,
    -980,  -980,  -980,  -980,  -980,  -234,  -980,  -980,  -980,   498,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -200,
    -980,  -980,  -980,  -199,  -980,  -980,  -980,   679,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -185,  -980,   533,
    -980,  -980,  -980,   -81,  -980,  -980,  -980,  -980,  -980,   567,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -178,  -980,  -980,
    -980,  -980,  -980,  -980,   501,  -980,  -980,  -980,  -980,  -980,
     911,  -980,  -980,  -980,  -980,   460,  -980,  -980,  -980,  -980,
    -980,  -194,  -980,  -980,  -980,   461,  -980,  -980,  -980,  -980,
    -189,  -980,  -980,  -980,   683,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -145,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -151,  -980,   581,  -980,
    -980,  -980,  -980,  -980,   673,  -980,  -980,  -980,  -980,   938,
    -980,  -980,  -980,  -980,  -980,  -980,  -133,  -980,   686,  -980,
    -980,  -980,  -980,   944,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,     1,  -980,  -980,  -980,    -3,  -980,  -980,  -980,  -980,
    -980,   964,  -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,
    -980,  -980,  -980,  -980,  -980,  -980,  -980,  -980,   849,  -980,
    -980,  -980,  -980,  -980,  -980
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
     814,   815,   579,   580,  1040,   475,    47,   466,    48,   290,
     587,   561,   110,   466,   387,   813,    45,    46,    67,   227,
     290,   110,   673,   674,  1028,  1029,  1030,   387,   675,   676,
     552,   348,   236,   349,   377,   350,   750,   751,   447,   496,
     476,    68,   994,  1086,   220,   220,   995,   351,    69,  1183,
    1184,  1185,    52,   954,   448,   497,   552,   996,    54,  1059,
     477,   997,   352,  1060,    58,   478,   353,  1061,   237,   449,
     498,  1062,   111,   450,   499,  1186,   227,   754,   755,  1187,
      59,   111,   238,   239,   240,   241,   354,  1188,   355,   515,
      62,  1189,    63,  1192,   378,   636,   637,  1193,   356,   291,
     242,   562,   516,   644,   388,   646,   954,   228,    70,    66,
     291,  1203,   653,   116,   107,   656,   813,   388,   117,   118,
     553,   357,   561,   479,   119,   108,   667,   668,   467,   500,
     818,   819,   120,   229,   467,   389,   679,   680,   121,   682,
     122,   123,   124,   955,   109,   115,   553,   125,   389,   358,
     251,   451,   501,   126,   127,   379,   128,   129,   130,   468,
     452,   453,   131,   563,   228,   468,   390,   132,   217,   502,
     218,   133,   134,   252,   377,   135,   359,   219,   234,   390,
    1087,   515,   554,   517,   136,  1088,   235,   288,   289,  1041,
     229,   137,   454,   138,   516,   139,   955,   140,   141,   142,
     143,   295,   296,   360,   490,   956,   253,   297,   554,   298,
     518,   144,   562,   301,   469,   302,   486,   145,   146,   147,
     469,   148,   708,   303,   149,   150,   569,   738,   151,   254,
     701,    76,   503,   255,   378,   299,   494,   555,   385,   491,
     256,   361,   257,   258,   633,   455,   504,   768,   622,   530,
    1093,    77,    78,   221,   221,   696,   725,    79,   956,  -111,
    -111,   488,   152,   555,    67,   304,   153,   957,   305,   154,
     155,   156,   157,   158,   563,   517,   159,   160,   306,   259,
     307,   260,   261,   262,   263,   308,  1194,    68,   309,  1157,
    1195,  1220,   803,   317,    69,   379,    80,    81,   264,   310,
     811,   812,   518,    82,    83,    84,   731,   318,   319,   311,
    1196,   320,   312,  1221,  1197,  1222,   161,   162,   163,   313,
     957,   164,   265,  1100,   314,   532,   165,    85,    86,   475,
     445,   384,   266,  1011,  1012,  1013,  1014,  1015,   396,   773,
      87,    88,  1206,  1208,  1210,  1212,  1207,  1209,  1211,  1213,
     397,    89,  1235,   398,    70,  1223,  1236,   399,   400,    90,
     267,   268,   401,  1158,   476,   402,   403,   550,   321,   322,
     323,   116,   404,   405,   324,   406,   117,   118,   407,   408,
     409,   410,   119,   325,   477,   411,   412,   413,   414,   478,
     120,   626,  1159,   574,   326,   327,   121,   415,   122,   123,
     124,  1160,   416,   417,   418,   125,   419,  1161,   251,   328,
     329,   126,   127,   420,   128,   129,   130,   421,   422,   423,
     131,  1162,   424,  1163,  1164,   132,  1224,  1225,   426,   133,
     134,   252,  1165,   135,   428,   429,   496,   330,  1166,   430,
     431,   432,   136,   433,   434,   571,   435,   479,   315,   137,
     447,   138,   497,   139,   436,   140,   141,   142,   143,  1226,
     437,   438,   439,   440,   253,   441,   448,   498,   442,   144,
     443,   499,   578,  1104,   444,   145,   146,   147,   331,   148,
     487,   449,   149,   150,   492,   450,   151,   254,   348,   493,
     349,   255,   350,   524,  1105,  1204,   525,   526,   256,   527,
     257,   258,   528,   529,   351,   533,   534,   535,   536,  1106,
     606,   783,   784,   785,   786,   787,  1107,   236,   537,   352,
     152,   538,   539,   353,   153,   540,   500,   154,   155,   156,
     157,   158,   541,  1108,   159,   160,   542,   259,   543,   260,
     261,   262,   263,   354,   544,   355,   545,   546,   572,   501,
     547,   548,   549,   237,   568,   356,   264,   573,  1109,   575,
     576,  1171,   577,   451,   578,  1110,   502,   238,   239,   240,
     241,  1065,   452,   453,   161,   162,   163,  1111,   357,   164,
     265,   581,   582,   583,   165,   242,   584,   585,   588,   586,
     266,  1066,   589,   590,   591,  1112,  1113,  1114,   592,   593,
     594,  1067,   595,   596,   454,   597,   358,  1068,   598,   599,
     317,   600,   869,     2,     3,   601,   602,     4,   267,   268,
     608,   603,   604,  1069,   318,   319,   605,     5,   320,   503,
       6,     7,   609,   359,   610,  1172,     8,   611,   612,   614,
     615,   616,   617,   504,   628,  1115,   629,     9,   635,   892,
    1070,    10,    11,   618,  1116,   638,   619,   455,  1071,  1117,
     360,    12,   620,   621,  1173,  1118,   624,   625,   630,  1119,
     631,  1120,   639,  1174,   640,    13,  1121,   641,   647,  1175,
     642,   643,  1122,    14,    15,   321,   322,   323,   645,   648,
     649,   324,   650,  1176,  1128,  1177,  1178,  1072,   361,   651,
     325,   652,   654,    16,  1179,   655,   657,   658,   660,   661,
    1180,   326,   327,   659,  1073,   662,   664,    17,   663,   665,
     666,   669,   681,   686,   670,   671,   328,   329,   672,   870,
     871,   872,   873,   874,   677,   875,   876,   678,   877,   878,
     879,   683,   684,   880,   685,   881,   882,   688,   883,   687,
     884,    18,   885,   886,   330,   689,   887,   703,   691,   710,
      19,    20,   888,   692,    21,    22,   893,   894,   895,   896,
     897,   693,   898,   899,   712,   900,   901,   902,   713,   714,
     903,    76,   904,   905,   694,   906,   711,   907,   695,   908,
     909,   698,   733,   910,   700,   331,   734,   735,   705,   911,
     736,    77,    78,   706,   707,   717,   718,    79,   715,   716,
     720,  1129,  1130,  1131,  1132,  1133,    23,  1134,  1135,   721,
    1136,  1137,  1138,   722,   737,  1139,   740,  1140,  1141,   727,
    1142,   724,  1143,   741,  1144,  1145,   728,   729,  1146,   730,
     739,   742,   743,   744,  1147,   745,    80,    81,   746,   747,
     748,   749,   758,    82,    83,    84,   759,   760,   761,   762,
     765,   763,   764,   775,   770,   801,   767,   776,   771,   777,
     778,   779,   780,   781,   782,   802,   804,    85,    86,   805,
     790,   791,   792,   793,   794,   795,   796,   797,   806,   798,
      87,    88,   799,   800,   807,   809,   808,   810,   813,   816,
     822,    89,   817,   820,   821,   823,   824,   827,   825,    90,
     826,   828,   829,   831,   834,   830,   835,   839,   832,   833,
     836,   837,   838,   933,   840,   841,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
     936,   856,   937,   857,   858,   938,   934,   939,   940,   942,
     859,   860,   861,   944,   862,   947,   948,   949,   965,   968,
     969,   863,   864,   865,   866,   867,   868,   891,   914,   915,
     916,   917,   918,   966,   919,   920,   921,   922,   923,   924,
     925,   970,   926,   927,   928,   929,   930,   931,   932,   972,
     941,   974,   935,   975,   976,  1003,   945,   943,  1005,  1007,
    1154,   946,  1237,   726,  1155,   300,   952,  1101,  1231,  1232,
    1198,   607,  1218,  1199,   709,  1216,   769,  1233,  1056,   953,
     732,   963,   964,   697,  1234,   774,   973,   967,   971,   977,
     978,   979,   980,   981,   982,   983,   984,  1082,   985,   986,
     987,   988,  1214,   989,  1217,   623,  1201,   990,   991,   992,
     386,   993,   702,   627,   998,   316,  1215,  1190,     0,   999,
    1000,  1001,  1002,  1191,  1006,     0,  1004,  1009,  1008,  1010,
    1016,  1017,  1018,   489,  1019,  1020,  1021,  1022,   634,  1023,
    1024,  1025,  1026,  1027,  1033,  1034,     0,  1035,     0,  1036,
       0,     0,   531,  1037,  1038,     0,     0,  1039,  1044,  1045,
    1046,  1047,  1048,  1049,  1050,  1051,  1052,  1053,  1054,  1055,
     446,  1063,  1064,  1076,  1077,  1078,  1079,  1080,  1081,  1085,
    1091,  1092,     0,  1096,     0,     0,  1094,  1097,  1099,     0,
    1102,  1103,  1125,  1126,  1127,  1150,  1151,  1152,  1153,  1156,
    1169,  1170,  1200,     0,     0,  1205,  1219,  1202,  1229,  1230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     495,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   570
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-980)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     604,   605,   304,   305,     8,     1,   219,     1,   219,     1,
     312,     1,     1,     1,     1,   101,   217,   218,     1,     1,
       1,     1,   162,   163,     9,    10,    11,     1,   162,   163,
       1,     1,     1,     3,     1,     5,   136,   137,     1,     1,
      36,    24,   217,    51,     1,     1,   221,    17,    31,  1028,
    1029,  1030,   219,     1,    17,    17,     1,   217,   219,   217,
      56,   221,    32,   221,   219,    61,    36,   217,    37,    32,
      32,   221,    61,    36,    36,   217,     1,   136,   137,   221,
     219,    61,    51,    52,    53,    54,    56,   217,    58,     1,
     219,   221,   219,   217,    61,   397,   398,   221,    68,    91,
      69,    91,    14,   405,    91,   407,     1,    89,    91,   219,
      91,   197,   414,     1,   219,   417,   101,    91,     6,     7,
      91,    91,     1,   119,    12,   219,   428,   429,   122,    91,
     180,   181,    20,   115,   122,   122,   438,   439,    26,   441,
      28,    29,    30,    91,   219,   219,    91,    35,   122,   119,
       1,   114,   114,    41,    42,   122,    44,    45,    46,   153,
     123,   124,    50,   153,    89,   153,   153,    55,   219,   131,
     219,    59,    60,    24,     1,    63,   146,   219,   219,   153,
     188,     1,   153,    95,    72,   193,   219,   219,   219,   193,
     115,    79,   155,    81,    14,    83,    91,    85,    86,    87,
      88,   217,   220,   173,   216,   153,    57,   220,   153,   220,
     122,    99,    91,   220,   208,   220,   217,   105,   106,   107,
     208,   109,   218,   220,   112,   113,   218,   529,   116,    80,
     218,     1,   194,    84,    61,   218,   218,   208,   218,   217,
      91,   211,    93,    94,   218,   208,   208,   218,   218,   218,
     166,    21,    22,   210,   210,   218,   218,    27,   153,   216,
     216,   218,   150,   208,     1,   220,   154,   215,   220,   157,
     158,   159,   160,   161,   153,    95,   164,   165,   220,   130,
     220,   132,   133,   134,   135,   220,   217,    24,   220,    64,
     221,    40,   594,     1,    31,   122,    66,    67,   149,   220,
     602,   603,   122,    73,    74,    75,   218,    15,    16,   220,
     217,    19,   220,    62,   221,    64,   204,   205,   206,   220,
     215,   209,   173,   218,   220,   217,   214,    97,    98,     1,
     218,   220,   183,   783,   784,   785,   786,   787,   220,   218,
     110,   111,   217,   217,   217,   217,   221,   221,   221,   221,
     220,   121,   217,   220,    91,   104,   221,   220,   220,   129,
     211,   212,   220,   138,    36,   220,   220,   218,    76,    77,
      78,     1,   220,   220,    82,   220,     6,     7,   220,   220,
     220,   220,    12,    91,    56,   220,   220,   220,   220,    61,
      20,   218,   167,   217,   102,   103,    26,   220,    28,    29,
      30,   176,   220,   220,   220,    35,   220,   182,     1,   117,
     118,    41,    42,   220,    44,    45,    46,   220,   220,   220,
      50,   196,   220,   198,   199,    55,   175,   176,   220,    59,
      60,    24,   207,    63,   220,   220,     1,   145,   213,   220,
     220,   220,    72,   220,   220,   120,   220,   119,   218,    79,
       1,    81,    17,    83,   220,    85,    86,    87,    88,   208,
     220,   220,   220,   220,    57,   220,    17,    32,   220,    99,
     220,    36,   101,     4,   220,   105,   106,   107,   186,   109,
     220,    32,   112,   113,   220,    36,   116,    80,     1,   220,
       3,    84,     5,   220,    25,  1099,   220,   220,    91,   220,
      93,    94,   220,   220,    17,   220,   220,   220,   220,    40,
     218,   140,   141,   142,   143,   144,    47,     1,   220,    32,
     150,   220,   220,    36,   154,   220,    91,   157,   158,   159,
     160,   161,   220,    64,   164,   165,   220,   130,   220,   132,
     133,   134,   135,    56,   220,    58,   220,   220,   120,   114,
     220,   220,   220,    37,   220,    68,   149,   120,    89,   101,
     101,    64,   162,   114,   101,    96,   131,    51,    52,    53,
      54,    13,   123,   124,   204,   205,   206,   108,    91,   209,
     173,   101,   101,   101,   214,    69,   162,   162,   162,   101,
     183,    33,   162,   217,   217,   126,   127,   128,   220,   220,
     220,    43,   220,   220,   155,   220,   119,    49,   220,   220,
       1,   220,    51,     0,     1,   220,   220,     4,   211,   212,
     217,   220,   220,    65,    15,    16,   220,    14,    19,   194,
      17,    18,   220,   146,   220,   138,    23,   220,   220,   220,
     220,   220,   220,   208,   120,   176,   217,    34,   162,    51,
      92,    38,    39,   220,   185,   101,   220,   208,   100,   190,
     173,    48,   220,   220,   167,   196,   220,   220,   220,   200,
     220,   202,   162,   176,   162,    62,   207,   101,   101,   182,
     120,   162,   213,    70,    71,    76,    77,    78,   162,   101,
     101,    82,   162,   196,    51,   198,   199,   139,   211,   162,
      91,   162,   101,    90,   207,   101,   101,   101,   101,   101,
     213,   102,   103,   120,   156,   162,   220,   104,   162,   162,
     220,   162,   120,   217,   162,   162,   117,   118,   162,   168,
     169,   170,   171,   172,   162,   174,   175,   162,   177,   178,
     179,   162,   162,   182,   162,   184,   185,   220,   187,   217,
     189,   138,   191,   192,   145,   220,   195,   217,   220,   162,
     147,   148,   201,   220,   151,   152,   168,   169,   170,   171,
     172,   220,   174,   175,   219,   177,   178,   179,   120,   120,
     182,     1,   184,   185,   220,   187,   217,   189,   220,   191,
     192,   220,   162,   195,   220,   186,   162,   120,   220,   201,
     162,    21,    22,   220,   220,   220,   220,    27,   217,   217,
     220,   168,   169,   170,   171,   172,   203,   174,   175,   220,
     177,   178,   179,   220,   162,   182,   120,   184,   185,   217,
     187,   220,   189,   162,   191,   192,   220,   220,   195,   220,
     217,   101,   101,   120,   201,   120,    66,    67,   120,   120,
     120,   120,   120,    73,    74,    75,   120,   101,   120,   120,
     220,   217,   217,   120,   217,   101,   220,   217,   220,   217,
     217,   217,   217,   217,   217,   101,   101,    97,    98,   101,
     217,   217,   217,   217,   217,   217,   217,   217,   101,   217,
     110,   111,   217,   217,   101,   101,   120,   101,   101,   217,
     220,   121,   120,   120,   162,   120,   120,   101,   120,   129,
     120,   120,   120,   217,   217,   120,   217,   217,   120,   120,
     120,   120,   220,   120,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     120,   217,   101,   217,   217,   120,   162,   120,   120,   120,
     217,   217,   217,   120,   217,   120,   120,   101,   120,   120,
     120,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   162,   217,   217,   217,   217,   217,   217,
     217,   120,   217,   217,   217,   217,   217,   217,   217,   120,
     217,   120,   220,   120,   120,   120,   217,   220,   120,   120,
     995,   220,  1236,   505,   997,    71,   217,   958,  1207,  1209,
     101,   332,  1197,  1094,   481,  1193,   556,  1211,   125,   217,
     519,   217,   217,   456,  1213,   564,   217,   220,   220,   217,
     217,   217,   217,   217,   217,   217,   217,   125,   217,   217,
     217,   217,  1187,   217,  1195,   362,   120,   217,   217,   217,
     112,   217,   471,   380,   217,    91,  1189,  1060,    -1,   217,
     217,   217,   217,  1062,   217,    -1,   220,   217,   220,   217,
     217,   217,   217,   222,   217,   217,   217,   217,   392,   217,
     217,   217,   217,   217,   217,   217,    -1,   217,    -1,   217,
      -1,    -1,   243,   217,   217,    -1,    -1,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     166,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,    -1,   217,    -1,    -1,   221,   220,   220,    -1,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,    -1,    -1,   217,   217,   220,   217,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   269,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   292
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   223,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    90,   104,   138,   147,
     148,   151,   152,   203,   224,   229,   234,   258,   264,   278,
     296,   314,   328,   343,   350,   354,   364,   373,   393,   403,
     409,   413,   423,   481,   498,   217,   218,   219,   219,   297,
     374,   404,   219,   414,   219,   329,   394,   315,   219,   219,
     279,   344,   219,   219,   355,   365,   219,     1,    24,    31,
      91,   259,   260,   261,   262,   263,     1,    21,    22,    27,
      66,    67,    73,    74,    75,    97,    98,   110,   111,   121,
     129,   482,   483,   484,   485,   486,   487,   488,   489,   490,
     491,   492,   493,   494,   495,   496,   497,   219,   219,   219,
       1,    61,   410,   411,   412,   219,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    81,    83,
      85,    86,    87,    88,    99,   105,   106,   107,   109,   112,
     113,   116,   150,   154,   157,   158,   159,   160,   161,   164,
     165,   204,   205,   206,   209,   214,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   474,   478,   479,   480,   219,   219,   219,
       1,   210,   265,   266,   267,   268,   269,     1,    89,   115,
     230,   231,   232,   233,   219,   219,     1,    37,    51,    52,
      53,    54,    69,   499,   500,   501,   502,   503,   504,   505,
     506,     1,    24,    57,    80,    84,    91,    93,    94,   130,
     132,   133,   134,   135,   149,   173,   183,   211,   212,   235,
     236,   237,   238,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   219,   219,
       1,    91,   351,   352,   353,   217,   220,   220,   220,   218,
     260,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   218,   483,     1,    15,    16,
      19,    76,    77,    78,    82,    91,   102,   103,   117,   118,
     145,   186,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,     1,     3,
       5,    17,    32,    36,    56,    58,    68,    91,   119,   146,
     173,   211,   375,   376,   377,   378,   379,   380,   381,   382,
     383,   384,   388,   389,   390,   391,   392,     1,    61,   122,
     405,   406,   407,   408,   220,   218,   411,     1,    91,   122,
     153,   415,   419,   420,   421,   422,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   475,   220,   471,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   218,   425,     1,    17,    32,
      36,   114,   123,   124,   155,   208,   330,   331,   332,   333,
     334,   335,   336,   340,   341,   342,     1,   122,   153,   208,
     395,   399,   400,   401,   402,     1,    36,    56,    61,   119,
     316,   320,   321,   322,   326,   327,   217,   220,   218,   266,
     216,   217,   220,   220,   218,   231,     1,    17,    32,    36,
      91,   114,   131,   194,   208,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   292,     1,    14,    95,   122,   345,
     346,   347,   348,   349,   220,   220,   220,   220,   220,   220,
     218,   500,   217,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     218,   236,     1,    91,   153,   208,   356,   357,   358,   359,
     360,     1,    91,   153,   366,   367,   368,   369,   220,   218,
     352,   120,   120,   120,   217,   101,   101,   162,   101,   226,
     226,   101,   101,   101,   162,   162,   101,   226,   162,   162,
     217,   217,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   218,   299,   217,   220,
     220,   220,   220,   385,   220,   220,   220,   220,   220,   220,
     220,   220,   218,   376,   220,   220,   218,   406,   120,   217,
     220,   220,   416,   218,   420,   162,   226,   226,   101,   162,
     162,   101,   120,   162,   226,   162,   226,   101,   101,   101,
     162,   162,   162,   226,   101,   101,   226,   101,   101,   120,
     101,   101,   162,   162,   220,   162,   220,   226,   226,   162,
     162,   162,   162,   162,   163,   162,   163,   162,   162,   226,
     226,   120,   226,   162,   162,   162,   217,   217,   220,   220,
     337,   220,   220,   220,   220,   220,   218,   331,   220,   396,
     220,   218,   400,   217,   317,   220,   220,   220,   218,   321,
     162,   217,   219,   120,   120,   217,   217,   220,   220,   293,
     220,   220,   220,   289,   220,   218,   281,   217,   220,   220,
     220,   218,   346,   162,   162,   120,   162,   162,   226,   217,
     120,   162,   101,   101,   120,   120,   120,   120,   120,   120,
     136,   137,   239,   240,   136,   137,   241,   242,   120,   120,
     101,   120,   120,   217,   217,   220,   361,   220,   218,   357,
     217,   220,   370,   218,   367,   120,   217,   217,   217,   217,
     217,   217,   217,   140,   141,   142,   143,   144,   225,   226,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   101,   101,   226,   101,   101,   101,   101,   120,   101,
     101,   226,   226,   101,   228,   228,   217,   120,   180,   181,
     120,   162,   220,   120,   120,   120,   120,   101,   120,   120,
     120,   217,   120,   120,   217,   217,   120,   120,   220,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,    51,
     168,   169,   170,   171,   172,   174,   175,   177,   178,   179,
     182,   184,   185,   187,   189,   191,   192,   195,   201,   476,
     477,   217,    51,   168,   169,   170,   171,   172,   174,   175,
     177,   178,   179,   182,   184,   185,   187,   189,   191,   192,
     195,   201,   472,   473,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   120,   162,   220,   120,   101,   120,   120,
     120,   217,   120,   220,   120,   217,   220,   120,   120,   101,
     324,   325,   217,   217,     1,    91,   153,   215,   270,   271,
     272,   273,   274,   217,   217,   120,   162,   220,   120,   120,
     120,   220,   120,   217,   120,   120,   120,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   221,   217,   221,   217,   217,
     217,   217,   217,   120,   220,   120,   217,   120,   220,   217,
     217,   225,   225,   225,   225,   225,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,     9,    10,
      11,   227,   228,   217,   217,   217,   217,   217,   217,   217,
       8,   193,   386,   387,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   125,   417,   418,   217,
     221,   217,   221,   217,   217,    13,    33,    43,    49,    65,
      92,   100,   139,   156,   338,   339,   217,   217,   217,   217,
     217,   217,   125,   397,   398,   217,    51,   188,   193,   318,
     319,   217,   217,   166,   221,   323,   217,   220,   275,   220,
     218,   271,   217,   217,     4,    25,    40,    47,    64,    89,
      96,   108,   126,   127,   128,   176,   185,   190,   196,   200,
     202,   207,   213,   294,   295,   217,   217,   217,    51,   168,
     169,   170,   171,   172,   174,   175,   177,   178,   179,   182,
     184,   185,   187,   189,   191,   192,   195,   201,   290,   291,
     217,   217,   217,   217,   240,   242,   217,    64,   138,   167,
     176,   182,   196,   198,   199,   207,   213,   362,   363,   217,
     217,    64,   138,   167,   176,   182,   196,   198,   199,   207,
     213,   371,   372,   227,   227,   227,   217,   221,   217,   221,
     477,   473,   217,   221,   217,   221,   217,   221,   101,   325,
     217,   120,   220,   197,   228,   217,   217,   221,   217,   221,
     217,   221,   217,   221,   387,   418,   339,   398,   319,   217,
      40,    62,    64,   104,   175,   176,   208,   276,   277,   217,
     217,   295,   291,   363,   372,   217,   221,   277
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
#line 362 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 364 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 368 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 372 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 376 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 380 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 384 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 389 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 390 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 391 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 392 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 393 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 440 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 446 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 455 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 461 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 469 "conf_parser.y"
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

  case 80:
/* Line 1792 of yacc.c  */
#line 511 "conf_parser.y"
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

  case 81:
/* Line 1792 of yacc.c  */
#line 570 "conf_parser.y"
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

  case 82:
/* Line 1792 of yacc.c  */
#line 598 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 606 "conf_parser.y"
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

  case 84:
/* Line 1792 of yacc.c  */
#line 621 "conf_parser.y"
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

  case 85:
/* Line 1792 of yacc.c  */
#line 636 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    DupString(ServerInfo.description,yylval.string);
  }
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 645 "conf_parser.y"
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

  case 87:
/* Line 1792 of yacc.c  */
#line 659 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    DupString(ServerInfo.network_desc, yylval.string);
  }
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 668 "conf_parser.y"
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

  case 89:
/* Line 1792 of yacc.c  */
#line 696 "conf_parser.y"
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

  case 90:
/* Line 1792 of yacc.c  */
#line 726 "conf_parser.y"
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

  case 91:
/* Line 1792 of yacc.c  */
#line 751 "conf_parser.y"
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

  case 92:
/* Line 1792 of yacc.c  */
#line 773 "conf_parser.y"
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

  case 93:
/* Line 1792 of yacc.c  */
#line 795 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    DupString(AdminInfo.name, yylval.string);
  }
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    DupString(AdminInfo.email, yylval.string);
  }
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 828 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    DupString(AdminInfo.description, yylval.string);
  }
}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 852 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_set_file(ltype, lsize, lfile);
}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 869 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 874 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 877 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 882 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 889 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 893 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 897 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 901 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 909 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 923 "conf_parser.y"
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

  case 134:
/* Line 1792 of yacc.c  */
#line 936 "conf_parser.y"
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

  case 146:
/* Line 1792 of yacc.c  */
#line 1026 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1035 "conf_parser.y"
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

  case 148:
/* Line 1792 of yacc.c  */
#line 1072 "conf_parser.y"
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

  case 149:
/* Line 1792 of yacc.c  */
#line 1084 "conf_parser.y"
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

  case 150:
/* Line 1792 of yacc.c  */
#line 1095 "conf_parser.y"
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

  case 151:
/* Line 1792 of yacc.c  */
#line 1137 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes = 0;
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1153 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_BOTS;
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1157 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1165 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEAF;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1169 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_DEBUG;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_FULL;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_HIDDEN;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1181 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SKILL;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_NCHANGE;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1189 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_REJ;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1193 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_UNAUTH;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1197 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SPY;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1201 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_EXTERNAL;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1205 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_OPERWALL;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1213 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_INVISIBLE;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1217 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_WALLOP;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1221 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1225 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_CALLERID;
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1229 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->modes |= UMODE_LOCOPS;
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1235 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = 0;
}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1242 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1246 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_K;
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1258 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DLINE;
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1266 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_X;
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLINE;
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1274 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_DIE;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1278 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_RESTART;
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1282 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REHASH;
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1286 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1290 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_N;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1294 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1302 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1306 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1310 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_SET;
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1314 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port |= OPER_FLAG_MODULE;
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1324 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_conf = make_conf_item(CLASS_TYPE);
    yy_class = map_to_conf(yy_conf);
  }
}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1331 "conf_parser.y"
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

  case 218:
/* Line 1792 of yacc.c  */
#line 1389 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_warning = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1410 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1416 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1422 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1428 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1434 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1440 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1446 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1452 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1459 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1465 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 231:
/* Line 1792 of yacc.c  */
#line 1471 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1480 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1487 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1496 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1502 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 239:
/* Line 1792 of yacc.c  */
#line 1506 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 240:
/* Line 1792 of yacc.c  */
#line 1510 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 248:
/* Line 1792 of yacc.c  */
#line 1520 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1525 "conf_parser.y"
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

  case 253:
/* Line 1792 of yacc.c  */
#line 1539 "conf_parser.y"
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

  case 254:
/* Line 1792 of yacc.c  */
#line 1559 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 1568 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 256:
/* Line 1792 of yacc.c  */
#line 1580 "conf_parser.y"
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

  case 257:
/* Line 1792 of yacc.c  */
#line 1592 "conf_parser.y"
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

  case 269:
/* Line 1792 of yacc.c  */
#line 1654 "conf_parser.y"
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

  case 270:
/* Line 1792 of yacc.c  */
#line 1689 "conf_parser.y"
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

  case 271:
/* Line 1792 of yacc.c  */
#line 1702 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 1711 "conf_parser.y"
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

  case 273:
/* Line 1792 of yacc.c  */
#line 1722 "conf_parser.y"
    {
}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 1727 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 1731 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 1735 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 1739 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 1743 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 1747 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 1751 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 1755 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 1759 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 1765 "conf_parser.y"
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

  case 287:
/* Line 1792 of yacc.c  */
#line 1784 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 1794 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_aconf->flags |= CONF_FLAGS_REDIR;
    yy_aconf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 289:
/* Line 1792 of yacc.c  */
#line 1807 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 290:
/* Line 1792 of yacc.c  */
#line 1814 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 1826 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 1835 "conf_parser.y"
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

  case 299:
/* Line 1792 of yacc.c  */
#line 1850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = CONF_NOREASON;

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 1868 "conf_parser.y"
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

  case 306:
/* Line 1792 of yacc.c  */
#line 1883 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(ULINE_TYPE);
    yy_match_item = map_to_conf(yy_conf);
    yy_match_item->action = SHARED_ALL;
  }
}
    break;

  case 307:
/* Line 1792 of yacc.c  */
#line 1891 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 1902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 1911 "conf_parser.y"
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

  case 316:
/* Line 1792 of yacc.c  */
#line 1933 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = 0;
}
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 1940 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_KLINE;
}
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 1944 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNKLINE;
}
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 1948 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_DLINE;
}
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 1952 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNDLINE;
}
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 1956 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_XLINE;
}
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 1960 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNXLINE;
}
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 1964 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_RESV;
}
    break;

  case 327:
/* Line 1792 of yacc.c  */
#line 1968 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_UNRESV;
}
    break;

  case 328:
/* Line 1792 of yacc.c  */
#line 1972 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action |= SHARED_LOCOPS;
}
    break;

  case 329:
/* Line 1792 of yacc.c  */
#line 1976 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_match_item->action = SHARED_ALL;
}
    break;

  case 330:
/* Line 1792 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = make_conf_item(CLUSTER_TYPE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 331:
/* Line 1792 of yacc.c  */
#line 1992 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->name == NULL)
      DupString(yy_conf->name, "*");
    yy_conf = NULL;
  }
}
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 2005 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 2011 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 2018 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 2022 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 2026 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 2030 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 2034 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 2038 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 2042 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 2046 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 2050 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 2054 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 2063 "conf_parser.y"
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

  case 353:
/* Line 1792 of yacc.c  */
#line 2078 "conf_parser.y"
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

  case 370:
/* Line 1792 of yacc.c  */
#line 2122 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 371:
/* Line 1792 of yacc.c  */
#line 2131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_aconf->host);
    DupString(yy_aconf->host, yylval.string);
  }
}
    break;

  case 372:
/* Line 1792 of yacc.c  */
#line 2140 "conf_parser.y"
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

  case 373:
/* Line 1792 of yacc.c  */
#line 2166 "conf_parser.y"
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

  case 374:
/* Line 1792 of yacc.c  */
#line 2185 "conf_parser.y"
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

  case 375:
/* Line 1792 of yacc.c  */
#line 2204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 376:
/* Line 1792 of yacc.c  */
#line 2210 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET;
}
    break;

  case 377:
/* Line 1792 of yacc.c  */
#line 2214 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_aconf->aftype = AF_INET6;
#endif
}
    break;

  case 378:
/* Line 1792 of yacc.c  */
#line 2222 "conf_parser.y"
    {
}
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 2227 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_aconf);
}
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 2231 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_aconf);
}
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 2237 "conf_parser.y"
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

  case 385:
/* Line 1792 of yacc.c  */
#line 2248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->hub_list);
  }
}
    break;

  case 386:
/* Line 1792 of yacc.c  */
#line 2259 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_aconf->leaf_list);
  }
}
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 2270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 2279 "conf_parser.y"
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

  case 389:
/* Line 1792 of yacc.c  */
#line 2297 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2304 "conf_parser.y"
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

  case 391:
/* Line 1792 of yacc.c  */
#line 2362 "conf_parser.y"
    {
}
    break;

  case 395:
/* Line 1792 of yacc.c  */
#line 2367 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 402:
/* Line 1792 of yacc.c  */
#line 2376 "conf_parser.y"
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

  case 403:
/* Line 1792 of yacc.c  */
#line 2395 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 404:
/* Line 1792 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 405:
/* Line 1792 of yacc.c  */
#line 2408 "conf_parser.y"
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

  case 411:
/* Line 1792 of yacc.c  */
#line 2432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 412:
/* Line 1792 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 418:
/* Line 1792 of yacc.c  */
#line 2452 "conf_parser.y"
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

  case 419:
/* Line 1792 of yacc.c  */
#line 2470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 2477 "conf_parser.y"
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

  case 421:
/* Line 1792 of yacc.c  */
#line 2517 "conf_parser.y"
    {
}
    break;

  case 425:
/* Line 1792 of yacc.c  */
#line 2522 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 432:
/* Line 1792 of yacc.c  */
#line 2531 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 433:
/* Line 1792 of yacc.c  */
#line 2537 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 487:
/* Line 1792 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:
/* Line 1792 of yacc.c  */
#line 2587 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 489:
/* Line 1792 of yacc.c  */
#line 2593 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1792 of yacc.c  */
#line 2599 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1792 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1792 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 493:
/* Line 1792 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 494:
/* Line 1792 of yacc.c  */
#line 2620 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 495:
/* Line 1792 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 496:
/* Line 1792 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 497:
/* Line 1792 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 498:
/* Line 1792 of yacc.c  */
#line 2640 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 499:
/* Line 1792 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 2650 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 2655 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1792 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 2665 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 2670 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 2681 "conf_parser.y"
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

  case 507:
/* Line 1792 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 2697 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 2702 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 2720 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 2728 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 2733 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 2738 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 2743 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 2753 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 2758 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 2763 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 2768 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 2773 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 2794 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 2799 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 2808 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 2817 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 2827 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 2832 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 2838 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 2841 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 2847 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 2850 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 2853 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 2856 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 2859 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 2862 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 2865 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 2868 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 548:
/* Line 1792 of yacc.c  */
#line 2871 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 2874 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 2877 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 2880 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 2886 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 2889 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 2892 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 2895 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 557:
/* Line 1792 of yacc.c  */
#line 2900 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 2906 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 2909 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 2912 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 2915 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 2918 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 2921 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 2924 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 2927 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 2930 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 2933 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 572:
/* Line 1792 of yacc.c  */
#line 2939 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 573:
/* Line 1792 of yacc.c  */
#line 2942 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 574:
/* Line 1792 of yacc.c  */
#line 2945 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 575:
/* Line 1792 of yacc.c  */
#line 2948 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 576:
/* Line 1792 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 2954 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 2957 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 579:
/* Line 1792 of yacc.c  */
#line 2960 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 580:
/* Line 1792 of yacc.c  */
#line 2963 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 2968 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:
/* Line 1792 of yacc.c  */
#line 2973 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 583:
/* Line 1792 of yacc.c  */
#line 2978 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1792 of yacc.c  */
#line 3001 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 603:
/* Line 1792 of yacc.c  */
#line 3006 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 604:
/* Line 1792 of yacc.c  */
#line 3011 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1792 of yacc.c  */
#line 3016 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1792 of yacc.c  */
#line 3021 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1792 of yacc.c  */
#line 3026 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 608:
/* Line 1792 of yacc.c  */
#line 3031 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 609:
/* Line 1792 of yacc.c  */
#line 3036 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1792 of yacc.c  */
#line 3041 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1792 of yacc.c  */
#line 3046 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 612:
/* Line 1792 of yacc.c  */
#line 3051 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 613:
/* Line 1792 of yacc.c  */
#line 3056 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 614:
/* Line 1792 of yacc.c  */
#line 3061 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 615:
/* Line 1792 of yacc.c  */
#line 3066 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 626:
/* Line 1792 of yacc.c  */
#line 3084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 627:
/* Line 1792 of yacc.c  */
#line 3090 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 628:
/* Line 1792 of yacc.c  */
#line 3096 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 629:
/* Line 1792 of yacc.c  */
#line 3105 "conf_parser.y"
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

  case 630:
/* Line 1792 of yacc.c  */
#line 3119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 631:
/* Line 1792 of yacc.c  */
#line 3125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1792 of yacc.c  */
#line 6896 "conf_parser.c"
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


