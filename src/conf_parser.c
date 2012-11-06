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
#include "conf_class.h"
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
static struct MaskItem *yy_conf = NULL;
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
#line 152 "conf_parser.c"

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
     PORT = 371,
     QSTRING = 372,
     QUIET_ON_BAN = 373,
     REASON = 374,
     REDIRPORT = 375,
     REDIRSERV = 376,
     REGEX_T = 377,
     REHASH = 378,
     REMOTE = 379,
     REMOTEBAN = 380,
     RESTRICT_CHANNELS = 381,
     RSA_PRIVATE_KEY_FILE = 382,
     RSA_PUBLIC_KEY_FILE = 383,
     SSL_CERTIFICATE_FILE = 384,
     SSL_DH_PARAM_FILE = 385,
     T_SSL_CLIENT_METHOD = 386,
     T_SSL_SERVER_METHOD = 387,
     T_SSLV3 = 388,
     T_TLSV1 = 389,
     RESV = 390,
     RESV_EXEMPT = 391,
     SECONDS = 392,
     MINUTES = 393,
     HOURS = 394,
     DAYS = 395,
     WEEKS = 396,
     SENDQ = 397,
     SEND_PASSWORD = 398,
     SERVERHIDE = 399,
     SERVERINFO = 400,
     IRCD_SID = 401,
     TKLINE_EXPIRE_NOTICES = 402,
     T_SHARED = 403,
     T_CLUSTER = 404,
     TYPE = 405,
     SHORT_MOTD = 406,
     SPOOF = 407,
     SPOOF_NOTICE = 408,
     STATS_E_DISABLED = 409,
     STATS_I_OPER_ONLY = 410,
     STATS_K_OPER_ONLY = 411,
     STATS_O_OPER_ONLY = 412,
     STATS_P_OPER_ONLY = 413,
     TBOOL = 414,
     TMASKED = 415,
     TS_MAX_DELTA = 416,
     TS_WARN_DELTA = 417,
     TWODOTS = 418,
     T_ALL = 419,
     T_BOTS = 420,
     T_SOFTCALLERID = 421,
     T_CALLERID = 422,
     T_CCONN = 423,
     T_CCONN_FULL = 424,
     T_SSL_CIPHER_LIST = 425,
     T_DEAF = 426,
     T_DEBUG = 427,
     T_DLINE = 428,
     T_EXTERNAL = 429,
     T_FULL = 430,
     T_INVISIBLE = 431,
     T_IPV4 = 432,
     T_IPV6 = 433,
     T_LOCOPS = 434,
     T_MAX_CLIENTS = 435,
     T_NCHANGE = 436,
     T_OPERWALL = 437,
     T_RECVQ = 438,
     T_REJ = 439,
     T_SERVER = 440,
     T_SERVNOTICE = 441,
     T_SET = 442,
     T_SKILL = 443,
     T_SPY = 444,
     T_SSL = 445,
     T_UMODES = 446,
     T_UNAUTH = 447,
     T_UNDLINE = 448,
     T_UNLIMITED = 449,
     T_UNRESV = 450,
     T_UNXLINE = 451,
     T_GLOBOPS = 452,
     T_WALLOP = 453,
     T_RESTART = 454,
     T_SERVICE = 455,
     T_SERVICES_NAME = 456,
     THROTTLE_TIME = 457,
     TRUE_NO_OPER_FLOOD = 458,
     UNKLINE = 459,
     USER = 460,
     USE_EGD = 461,
     USE_LOGGING = 462,
     VHOST = 463,
     VHOST6 = 464,
     XLINE = 465,
     WARN_NO_NLINE = 466,
     T_SIZE = 467,
     T_FILE = 468
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
#define PORT 371
#define QSTRING 372
#define QUIET_ON_BAN 373
#define REASON 374
#define REDIRPORT 375
#define REDIRSERV 376
#define REGEX_T 377
#define REHASH 378
#define REMOTE 379
#define REMOTEBAN 380
#define RESTRICT_CHANNELS 381
#define RSA_PRIVATE_KEY_FILE 382
#define RSA_PUBLIC_KEY_FILE 383
#define SSL_CERTIFICATE_FILE 384
#define SSL_DH_PARAM_FILE 385
#define T_SSL_CLIENT_METHOD 386
#define T_SSL_SERVER_METHOD 387
#define T_SSLV3 388
#define T_TLSV1 389
#define RESV 390
#define RESV_EXEMPT 391
#define SECONDS 392
#define MINUTES 393
#define HOURS 394
#define DAYS 395
#define WEEKS 396
#define SENDQ 397
#define SEND_PASSWORD 398
#define SERVERHIDE 399
#define SERVERINFO 400
#define IRCD_SID 401
#define TKLINE_EXPIRE_NOTICES 402
#define T_SHARED 403
#define T_CLUSTER 404
#define TYPE 405
#define SHORT_MOTD 406
#define SPOOF 407
#define SPOOF_NOTICE 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define TBOOL 414
#define TMASKED 415
#define TS_MAX_DELTA 416
#define TS_WARN_DELTA 417
#define TWODOTS 418
#define T_ALL 419
#define T_BOTS 420
#define T_SOFTCALLERID 421
#define T_CALLERID 422
#define T_CCONN 423
#define T_CCONN_FULL 424
#define T_SSL_CIPHER_LIST 425
#define T_DEAF 426
#define T_DEBUG 427
#define T_DLINE 428
#define T_EXTERNAL 429
#define T_FULL 430
#define T_INVISIBLE 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_MAX_CLIENTS 435
#define T_NCHANGE 436
#define T_OPERWALL 437
#define T_RECVQ 438
#define T_REJ 439
#define T_SERVER 440
#define T_SERVNOTICE 441
#define T_SET 442
#define T_SKILL 443
#define T_SPY 444
#define T_SSL 445
#define T_UMODES 446
#define T_UNAUTH 447
#define T_UNDLINE 448
#define T_UNLIMITED 449
#define T_UNRESV 450
#define T_UNXLINE 451
#define T_GLOBOPS 452
#define T_WALLOP 453
#define T_RESTART 454
#define T_SERVICE 455
#define T_SERVICES_NAME 456
#define THROTTLE_TIME 457
#define TRUE_NO_OPER_FLOOD 458
#define UNKLINE 459
#define USER 460
#define USE_EGD 461
#define USE_LOGGING 462
#define VHOST 463
#define VHOST6 464
#define XLINE 465
#define WARN_NO_NLINE 466
#define T_SIZE 467
#define T_FILE 468



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 374 of yacc.c  */
#line 109 "conf_parser.y"

  int number;
  char *string;


/* Line 374 of yacc.c  */
#line 627 "conf_parser.c"
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
#line 655 "conf_parser.c"

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
#define YYNTOKENS  219
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  282
/* YYNRULES -- Number of rules.  */
#define YYNRULES  625
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1223

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   468

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   218,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   214,
       2,   217,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   216,     2,   215,     2,     2,     2,     2,
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
     205,   206,   207,   208,   209,   210,   211,   212,   213
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
    1081,  1086,  1091,  1092,  1098,  1102,  1104,  1106,  1108,  1113,
    1118,  1123,  1128,  1133,  1134,  1141,  1142,  1148,  1152,  1154,
    1156,  1159,  1161,  1163,  1165,  1167,  1169,  1174,  1179,  1180,
    1187,  1190,  1192,  1194,  1196,  1198,  1203,  1208,  1214,  1217,
    1219,  1221,  1223,  1228,  1229,  1236,  1237,  1243,  1247,  1249,
    1251,  1254,  1256,  1258,  1260,  1262,  1264,  1269,  1274,  1280,
    1283,  1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,
    1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,
    1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,
    1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,
    1383,  1385,  1390,  1395,  1400,  1405,  1410,  1415,  1420,  1425,
    1430,  1435,  1440,  1445,  1450,  1455,  1460,  1465,  1470,  1475,
    1480,  1485,  1490,  1495,  1500,  1505,  1510,  1515,  1520,  1525,
    1530,  1535,  1540,  1545,  1550,  1555,  1560,  1565,  1570,  1575,
    1580,  1585,  1590,  1595,  1600,  1605,  1610,  1615,  1616,  1622,
    1626,  1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,
    1646,  1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,
    1666,  1668,  1669,  1675,  1679,  1681,  1683,  1685,  1687,  1689,
    1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,  1707,  1709,
    1711,  1713,  1715,  1717,  1719,  1721,  1726,  1731,  1736,  1742,
    1745,  1747,  1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,
    1765,  1767,  1769,  1771,  1773,  1775,  1777,  1782,  1787,  1792,
    1797,  1802,  1807,  1812,  1817,  1822,  1827,  1832,  1837,  1842,
    1847,  1853,  1856,  1858,  1860,  1862,  1864,  1866,  1868,  1870,
    1872,  1877,  1882,  1887,  1892,  1897
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     220,     0,    -1,    -1,   220,   221,    -1,   253,    -1,   259,
      -1,   273,    -1,   475,    -1,   291,    -1,   308,    -1,   322,
      -1,   231,    -1,   492,    -1,   337,    -1,   344,    -1,   348,
      -1,   358,    -1,   367,    -1,   387,    -1,   397,    -1,   403,
      -1,   417,    -1,   407,    -1,   226,    -1,     1,   214,    -1,
       1,   215,    -1,    -1,   223,    -1,    99,   222,    -1,    99,
     137,   222,    -1,    99,   138,   222,    -1,    99,   139,   222,
      -1,    99,   140,   222,    -1,    99,   141,   222,    -1,    -1,
     225,    -1,    99,   224,    -1,    99,     9,   224,    -1,    99,
      10,   224,    -1,    99,    11,   224,    -1,    88,   216,   227,
     215,   214,    -1,   227,   228,    -1,   228,    -1,   229,    -1,
     230,    -1,     1,   214,    -1,    87,   217,   117,   214,    -1,
     113,   217,   117,   214,    -1,   145,   216,   232,   215,   214,
      -1,   232,   233,    -1,   233,    -1,   244,    -1,   249,    -1,
     252,    -1,   246,    -1,   247,    -1,   248,    -1,   251,    -1,
     242,    -1,   241,    -1,   250,    -1,   245,    -1,   240,    -1,
     234,    -1,   235,    -1,   243,    -1,     1,   214,    -1,   131,
     217,   236,   214,    -1,   132,   217,   238,   214,    -1,   236,
     218,   237,    -1,   237,    -1,   133,    -1,   134,    -1,   238,
     218,   239,    -1,   239,    -1,   133,    -1,   134,    -1,   129,
     217,   117,   214,    -1,   127,   217,   117,   214,    -1,   130,
     217,   117,   214,    -1,   170,   217,   117,   214,    -1,    89,
     217,   117,   214,    -1,   146,   217,   117,   214,    -1,    24,
     217,   117,   214,    -1,    92,   217,   117,   214,    -1,    91,
     217,   117,   214,    -1,   208,   217,   117,   214,    -1,   209,
     217,   117,   214,    -1,   180,   217,    99,   214,    -1,    57,
     217,   159,   214,    -1,     4,   216,   254,   215,   214,    -1,
     254,   255,    -1,   255,    -1,   256,    -1,   258,    -1,   257,
      -1,     1,   214,    -1,    89,   217,   117,   214,    -1,    31,
     217,   117,   214,    -1,    24,   217,   117,   214,    -1,    71,
     216,   260,   215,   214,    -1,   260,   261,    -1,   261,    -1,
     262,    -1,   263,    -1,     1,   214,    -1,   207,   217,   159,
     214,    -1,    -1,   264,   213,   216,   265,   215,   214,    -1,
     265,   266,    -1,   266,    -1,   267,    -1,   269,    -1,   268,
      -1,     1,   214,    -1,    89,   217,   117,   214,    -1,   212,
     217,   225,   214,    -1,   212,   217,   194,   214,    -1,    -1,
     150,   270,   217,   271,   214,    -1,   271,   218,   272,    -1,
     272,    -1,   205,    -1,   102,    -1,    40,    -1,   173,    -1,
      64,    -1,    62,    -1,   172,    -1,    -1,   102,   274,   216,
     275,   215,   214,    -1,   275,   276,    -1,   276,    -1,   277,
      -1,   278,    -1,   279,    -1,   283,    -1,   282,    -1,   280,
      -1,   281,    -1,   287,    -1,     1,   214,    -1,    89,   217,
     117,   214,    -1,   205,   217,   117,   214,    -1,   112,   217,
     117,   214,    -1,    32,   217,   159,   214,    -1,   128,   217,
     117,   214,    -1,    17,   217,   117,   214,    -1,    -1,   191,
     284,   217,   285,   214,    -1,   285,   218,   286,    -1,   286,
      -1,   165,    -1,   168,    -1,   169,    -1,   171,    -1,   172,
      -1,   175,    -1,    51,    -1,   188,    -1,   181,    -1,   184,
      -1,   192,    -1,   189,    -1,   174,    -1,   182,    -1,   186,
      -1,   176,    -1,   198,    -1,   166,    -1,   167,    -1,   179,
      -1,    -1,    36,   288,   217,   289,   214,    -1,   289,   218,
     290,    -1,   290,    -1,    47,    -1,   124,    -1,    64,    -1,
     204,    -1,   173,    -1,   193,    -1,   210,    -1,    40,    -1,
      25,    -1,   199,    -1,   123,    -1,     4,    -1,    94,    -1,
     182,    -1,   197,    -1,   106,    -1,   125,    -1,   187,    -1,
      87,    -1,    -1,    17,   292,   216,   293,   215,   214,    -1,
     293,   294,    -1,   294,    -1,   295,    -1,   305,    -1,   306,
      -1,   296,    -1,   307,    -1,   297,    -1,   298,    -1,   299,
      -1,   300,    -1,   301,    -1,   302,    -1,   303,    -1,   304,
      -1,     1,   214,    -1,    89,   217,   117,   214,    -1,   115,
     217,   223,   214,    -1,   101,   217,    99,   214,    -1,    19,
     217,   223,   214,    -1,    81,   217,    99,   214,    -1,    76,
     217,    99,   214,    -1,    78,   217,    99,   214,    -1,    77,
     217,    99,   214,    -1,   142,   217,   225,   214,    -1,   183,
     217,   225,   214,    -1,    15,   217,    99,   214,    -1,    16,
     217,    99,   214,    -1,   100,   217,    99,   214,    -1,    -1,
      70,   309,   216,   314,   215,   214,    -1,    -1,    36,   311,
     217,   312,   214,    -1,   312,   218,   313,    -1,   313,    -1,
     190,    -1,    51,    -1,   185,    -1,   314,   315,    -1,   315,
      -1,   316,    -1,   310,    -1,   320,    -1,   321,    -1,     1,
     214,    -1,    -1,   116,   217,   318,   317,   214,    -1,   318,
     218,   319,    -1,   319,    -1,    99,    -1,    99,   163,    99,
      -1,    61,   217,   117,   214,    -1,    56,   217,   117,   214,
      -1,    -1,    48,   323,   216,   324,   215,   214,    -1,   324,
     325,    -1,   325,    -1,   326,    -1,   327,    -1,   328,    -1,
     330,    -1,   334,    -1,   335,    -1,   336,    -1,   329,    -1,
       1,   214,    -1,   205,   217,   117,   214,    -1,   112,   217,
     117,   214,    -1,    17,   217,   117,   214,    -1,    32,   217,
     159,   214,    -1,    -1,    36,   331,   217,   332,   214,    -1,
     332,   218,   333,    -1,   333,    -1,   153,    -1,    33,    -1,
      65,    -1,    49,    -1,    13,    -1,    98,    -1,    43,    -1,
     136,    -1,    90,    -1,   152,   217,   117,   214,    -1,   121,
     217,   117,   214,    -1,   120,   217,    99,   214,    -1,    -1,
     135,   338,   216,   339,   215,   214,    -1,   339,   340,    -1,
     340,    -1,   341,    -1,   342,    -1,   343,    -1,     1,   214,
      -1,   119,   217,   117,   214,    -1,    14,   217,   117,   214,
      -1,    93,   217,   117,   214,    -1,   200,   216,   345,   215,
     214,    -1,   345,   346,    -1,   346,    -1,   347,    -1,     1,
      -1,    89,   217,   117,   214,    -1,    -1,   148,   349,   216,
     350,   215,   214,    -1,   350,   351,    -1,   351,    -1,   352,
      -1,   353,    -1,   354,    -1,     1,   214,    -1,    89,   217,
     117,   214,    -1,   205,   217,   117,   214,    -1,    -1,   150,
     355,   217,   356,   214,    -1,   356,   218,   357,    -1,   357,
      -1,    64,    -1,   204,    -1,   173,    -1,   193,    -1,   210,
      -1,   196,    -1,   135,    -1,   195,    -1,   179,    -1,   164,
      -1,    -1,   149,   359,   216,   360,   215,   214,    -1,   360,
     361,    -1,   361,    -1,   362,    -1,   363,    -1,     1,   214,
      -1,    89,   217,   117,   214,    -1,    -1,   150,   364,   217,
     365,   214,    -1,   365,   218,   366,    -1,   366,    -1,    64,
      -1,   204,    -1,   173,    -1,   193,    -1,   210,    -1,   196,
      -1,   135,    -1,   195,    -1,   179,    -1,   164,    -1,    -1,
      18,   368,   216,   369,   215,   214,    -1,   369,   370,    -1,
     370,    -1,   371,    -1,   372,    -1,   373,    -1,   374,    -1,
     375,    -1,   377,    -1,   376,    -1,   386,    -1,   378,    -1,
     383,    -1,   384,    -1,   385,    -1,   382,    -1,     1,   214,
      -1,    89,   217,   117,   214,    -1,    56,   217,   117,   214,
      -1,   208,   217,   117,   214,    -1,   143,   217,   117,   214,
      -1,     3,   217,   117,   214,    -1,   116,   217,    99,   214,
      -1,     5,   217,   177,   214,    -1,     5,   217,   178,   214,
      -1,    -1,    36,   379,   217,   380,   214,    -1,   380,   218,
     381,    -1,   381,    -1,     8,    -1,   190,    -1,    32,   217,
     159,   214,    -1,    58,   217,   117,   214,    -1,    68,   217,
     117,   214,    -1,    17,   217,   117,   214,    -1,   170,   217,
     117,   214,    -1,    -1,    62,   388,   216,   393,   215,   214,
      -1,    -1,   150,   390,   217,   391,   214,    -1,   391,   218,
     392,    -1,   392,    -1,   122,    -1,   393,   394,    -1,   394,
      -1,   395,    -1,   396,    -1,   389,    -1,     1,    -1,   205,
     217,   117,   214,    -1,   119,   217,   117,   214,    -1,    -1,
      23,   398,   216,   399,   215,   214,    -1,   399,   400,    -1,
     400,    -1,   401,    -1,   402,    -1,     1,    -1,    61,   217,
     117,   214,    -1,   119,   217,   117,   214,    -1,    34,   216,
     404,   215,   214,    -1,   404,   405,    -1,   405,    -1,   406,
      -1,     1,    -1,    61,   217,   117,   214,    -1,    -1,    38,
     408,   216,   413,   215,   214,    -1,    -1,   150,   410,   217,
     411,   214,    -1,   411,   218,   412,    -1,   412,    -1,   122,
      -1,   413,   414,    -1,   414,    -1,   415,    -1,   416,    -1,
     409,    -1,     1,    -1,    89,   217,   117,   214,    -1,   119,
     217,   117,   214,    -1,    39,   216,   418,   215,   214,    -1,
     418,   419,    -1,   419,    -1,   428,    -1,   429,    -1,   431,
      -1,   432,    -1,   433,    -1,   434,    -1,   435,    -1,   436,
      -1,   437,    -1,   438,    -1,   427,    -1,   440,    -1,   441,
      -1,   456,    -1,   443,    -1,   445,    -1,   447,    -1,   446,
      -1,   450,    -1,   444,    -1,   451,    -1,   452,    -1,   453,
      -1,   454,    -1,   455,    -1,   468,    -1,   457,    -1,   458,
      -1,   459,    -1,   464,    -1,   448,    -1,   449,    -1,   474,
      -1,   472,    -1,   473,    -1,   430,    -1,   463,    -1,   439,
      -1,   461,    -1,   462,    -1,   426,    -1,   421,    -1,   422,
      -1,   423,    -1,   424,    -1,   425,    -1,   442,    -1,   420,
      -1,   460,    -1,     1,    -1,    83,   217,    99,   214,    -1,
      42,   217,   159,   214,    -1,    41,   217,   223,   214,    -1,
      44,   217,   223,   214,    -1,    45,   217,    99,   214,    -1,
      46,   217,    99,   214,    -1,   147,   217,   159,   214,    -1,
      63,   217,   223,   214,    -1,    55,   217,   159,   214,    -1,
      59,   217,   159,   214,    -1,    28,   217,   159,   214,    -1,
      35,   217,   159,   214,    -1,     6,   217,   159,   214,    -1,
      80,   217,   223,   214,    -1,    79,   217,    99,   214,    -1,
      72,   217,    99,   214,    -1,     7,   217,   223,   214,    -1,
     162,   217,   223,   214,    -1,   161,   217,   223,   214,    -1,
      50,   217,    99,   214,    -1,    60,   217,   159,   214,    -1,
     211,   217,   159,   214,    -1,   154,   217,   159,   214,    -1,
     157,   217,   159,   214,    -1,   158,   217,   159,   214,    -1,
     156,   217,   159,   214,    -1,   156,   217,   160,   214,    -1,
     155,   217,   159,   214,    -1,   155,   217,   160,   214,    -1,
     110,   217,   223,   214,    -1,    12,   217,   223,   214,    -1,
     103,   217,   159,   214,    -1,   111,   217,   223,   214,    -1,
     151,   217,   159,   214,    -1,    97,   217,   159,   214,    -1,
     203,   217,   159,   214,    -1,   105,   217,   159,   214,    -1,
      84,   217,   117,   214,    -1,    29,   217,    99,   214,    -1,
      82,   217,    99,   214,    -1,   206,   217,   159,   214,    -1,
      30,   217,   117,   214,    -1,   201,   217,   117,   214,    -1,
     114,   217,   159,   214,    -1,    26,   217,   159,   214,    -1,
     202,   217,   223,   214,    -1,    -1,   107,   465,   217,   466,
     214,    -1,   466,   218,   467,    -1,   467,    -1,   165,    -1,
     168,    -1,   169,    -1,   171,    -1,   172,    -1,   175,    -1,
      51,    -1,   188,    -1,   181,    -1,   184,    -1,   192,    -1,
     189,    -1,   174,    -1,   182,    -1,   186,    -1,   176,    -1,
     198,    -1,   166,    -1,   167,    -1,   179,    -1,    -1,   104,
     469,   217,   470,   214,    -1,   470,   218,   471,    -1,   471,
      -1,   165,    -1,   168,    -1,   169,    -1,   171,    -1,   172,
      -1,   175,    -1,   188,    -1,    51,    -1,   181,    -1,   184,
      -1,   192,    -1,   189,    -1,   174,    -1,   182,    -1,   186,
      -1,   176,    -1,   198,    -1,   166,    -1,   167,    -1,   179,
      -1,    85,   217,    99,   214,    -1,    86,   217,    99,   214,
      -1,    20,   217,    99,   214,    -1,    14,   216,   476,   215,
     214,    -1,   476,   477,    -1,   477,    -1,   485,    -1,   480,
      -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,   486,
      -1,   487,    -1,   488,    -1,   479,    -1,   489,    -1,   490,
      -1,   491,    -1,   478,    -1,     1,    -1,    27,   217,   159,
     214,    -1,   126,   217,   159,   214,    -1,    66,   217,   223,
     214,    -1,    67,   217,   223,   214,    -1,    75,   217,    99,
     214,    -1,    74,   217,    99,   214,    -1,   118,   217,   159,
     214,    -1,    73,   217,    99,   214,    -1,    22,   217,    99,
     214,    -1,    21,   217,    99,   214,    -1,    95,   217,   159,
     214,    -1,    96,   217,   159,   214,    -1,   108,   217,    99,
     214,    -1,   109,   217,   223,   214,    -1,   144,   216,   493,
     215,   214,    -1,   493,   494,    -1,   494,    -1,   495,    -1,
     496,    -1,   498,    -1,   499,    -1,   497,    -1,   500,    -1,
       1,    -1,    37,   217,   159,   214,    -1,    54,   217,   159,
     214,    -1,    52,   217,   117,   214,    -1,    69,   217,   223,
     214,    -1,    51,   217,   159,   214,    -1,    53,   217,   159,
     214,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   328,   328,   329,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   357,   357,   358,   362,
     366,   370,   374,   378,   384,   384,   385,   386,   387,   388,
     395,   398,   398,   399,   399,   399,   401,   407,   414,   416,
     416,   417,   417,   418,   418,   419,   419,   420,   420,   421,
     421,   422,   422,   423,   423,   424,   425,   428,   429,   431,
     431,   432,   438,   446,   446,   447,   453,   461,   500,   559,
     587,   595,   610,   625,   634,   648,   657,   685,   715,   738,
     747,   749,   749,   750,   750,   751,   751,   753,   762,   771,
     783,   784,   784,   786,   786,   787,   789,   796,   796,   806,
     807,   809,   809,   810,   810,   812,   817,   820,   826,   825,
     831,   831,   832,   836,   840,   844,   848,   852,   856,   867,
     866,   958,   958,   959,   959,   959,   960,   960,   960,   961,
     961,   961,   963,   972,  1009,  1021,  1032,  1074,  1084,  1083,
    1089,  1089,  1090,  1094,  1098,  1102,  1106,  1110,  1114,  1118,
    1122,  1126,  1130,  1134,  1138,  1142,  1146,  1150,  1154,  1158,
    1162,  1166,  1173,  1172,  1178,  1178,  1179,  1183,  1187,  1191,
    1195,  1199,  1203,  1207,  1211,  1215,  1219,  1223,  1227,  1231,
    1235,  1239,  1243,  1247,  1251,  1262,  1261,  1307,  1307,  1308,
    1309,  1309,  1310,  1311,  1312,  1313,  1314,  1315,  1316,  1317,
    1318,  1318,  1319,  1321,  1330,  1336,  1342,  1348,  1354,  1360,
    1366,  1372,  1378,  1385,  1391,  1397,  1407,  1406,  1423,  1422,
    1427,  1427,  1428,  1432,  1436,  1444,  1444,  1445,  1445,  1445,
    1445,  1445,  1447,  1447,  1449,  1449,  1451,  1465,  1485,  1494,
    1507,  1506,  1569,  1569,  1570,  1570,  1570,  1570,  1571,  1571,
    1571,  1572,  1572,  1574,  1609,  1622,  1631,  1643,  1642,  1646,
    1646,  1647,  1651,  1655,  1659,  1663,  1667,  1671,  1675,  1679,
    1685,  1704,  1714,  1728,  1727,  1743,  1743,  1744,  1744,  1744,
    1744,  1746,  1755,  1770,  1783,  1785,  1785,  1786,  1786,  1788,
    1804,  1803,  1818,  1818,  1819,  1819,  1819,  1819,  1821,  1830,
    1853,  1852,  1858,  1858,  1859,  1863,  1867,  1871,  1875,  1879,
    1883,  1887,  1891,  1895,  1905,  1904,  1920,  1920,  1921,  1921,
    1921,  1923,  1930,  1929,  1935,  1935,  1936,  1940,  1944,  1948,
    1952,  1956,  1960,  1964,  1968,  1972,  1982,  1981,  2030,  2030,
    2031,  2031,  2031,  2032,  2032,  2033,  2033,  2033,  2034,  2034,
    2034,  2035,  2035,  2036,  2038,  2047,  2056,  2082,  2100,  2118,
    2124,  2128,  2137,  2136,  2140,  2140,  2141,  2145,  2151,  2162,
    2173,  2184,  2193,  2212,  2211,  2275,  2274,  2278,  2278,  2279,
    2285,  2285,  2286,  2286,  2286,  2286,  2288,  2307,  2317,  2316,
    2339,  2339,  2340,  2340,  2340,  2342,  2348,  2357,  2359,  2359,
    2360,  2360,  2362,  2381,  2380,  2427,  2426,  2430,  2430,  2431,
    2437,  2437,  2438,  2438,  2438,  2438,  2440,  2446,  2455,  2458,
    2458,  2459,  2459,  2460,  2460,  2461,  2461,  2462,  2462,  2463,
    2463,  2464,  2465,  2466,  2466,  2467,  2467,  2468,  2468,  2469,
    2469,  2470,  2470,  2471,  2471,  2472,  2473,  2473,  2474,  2474,
    2475,  2475,  2476,  2476,  2477,  2477,  2478,  2479,  2479,  2480,
    2481,  2482,  2482,  2483,  2483,  2484,  2485,  2486,  2487,  2487,
    2488,  2491,  2496,  2502,  2508,  2514,  2519,  2524,  2529,  2534,
    2539,  2544,  2549,  2554,  2559,  2564,  2569,  2574,  2579,  2584,
    2590,  2601,  2606,  2611,  2616,  2621,  2626,  2629,  2634,  2637,
    2642,  2647,  2652,  2657,  2662,  2667,  2672,  2677,  2682,  2693,
    2698,  2703,  2708,  2717,  2726,  2731,  2736,  2742,  2741,  2746,
    2746,  2747,  2750,  2753,  2756,  2759,  2762,  2765,  2768,  2771,
    2774,  2777,  2780,  2783,  2786,  2789,  2792,  2795,  2798,  2801,
    2804,  2810,  2809,  2814,  2814,  2815,  2818,  2821,  2824,  2827,
    2830,  2833,  2836,  2839,  2842,  2845,  2848,  2851,  2854,  2857,
    2860,  2863,  2866,  2869,  2872,  2877,  2882,  2887,  2896,  2899,
    2899,  2900,  2901,  2901,  2902,  2902,  2903,  2903,  2904,  2905,
    2905,  2906,  2907,  2907,  2908,  2908,  2910,  2915,  2920,  2925,
    2930,  2935,  2940,  2945,  2950,  2955,  2960,  2965,  2970,  2975,
    2983,  2986,  2986,  2987,  2987,  2988,  2989,  2989,  2990,  2991,
    2993,  2999,  3005,  3014,  3028,  3034
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
  "PING_TIME", "PORT", "QSTRING", "QUIET_ON_BAN", "REASON", "REDIRPORT",
  "REDIRSERV", "REGEX_T", "REHASH", "REMOTE", "REMOTEBAN",
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
  "class_ping_time", "class_number_per_ip", "class_connectfreq",
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
     465,   466,   467,   468,    59,   125,   123,    61,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   219,   220,   220,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   221,   221,   221,   221,
     221,   221,   221,   221,   221,   221,   222,   222,   223,   223,
     223,   223,   223,   223,   224,   224,   225,   225,   225,   225,
     226,   227,   227,   228,   228,   228,   229,   230,   231,   232,
     232,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   234,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   254,   255,   255,   255,   255,   256,   257,   258,
     259,   260,   260,   261,   261,   261,   262,   264,   263,   265,
     265,   266,   266,   266,   266,   267,   268,   268,   270,   269,
     271,   271,   272,   272,   272,   272,   272,   272,   272,   274,
     273,   275,   275,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   277,   278,   279,   280,   281,   282,   284,   283,
     285,   285,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   288,   287,   289,   289,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   292,   291,   293,   293,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   309,   308,   311,   310,
     312,   312,   313,   313,   313,   314,   314,   315,   315,   315,
     315,   315,   317,   316,   318,   318,   319,   319,   320,   321,
     323,   322,   324,   324,   325,   325,   325,   325,   325,   325,
     325,   325,   325,   326,   327,   328,   329,   331,   330,   332,
     332,   333,   333,   333,   333,   333,   333,   333,   333,   333,
     334,   335,   336,   338,   337,   339,   339,   340,   340,   340,
     340,   341,   342,   343,   344,   345,   345,   346,   346,   347,
     349,   348,   350,   350,   351,   351,   351,   351,   352,   353,
     355,   354,   356,   356,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   359,   358,   360,   360,   361,   361,
     361,   362,   364,   363,   365,   365,   366,   366,   366,   366,
     366,   366,   366,   366,   366,   366,   368,   367,   369,   369,
     370,   370,   370,   370,   370,   370,   370,   370,   370,   370,
     370,   370,   370,   370,   371,   372,   373,   374,   375,   376,
     377,   377,   379,   378,   380,   380,   381,   381,   382,   383,
     384,   385,   386,   388,   387,   390,   389,   391,   391,   392,
     393,   393,   394,   394,   394,   394,   395,   396,   398,   397,
     399,   399,   400,   400,   400,   401,   402,   403,   404,   404,
     405,   405,   406,   408,   407,   410,   409,   411,   411,   412,
     413,   413,   414,   414,   414,   414,   415,   416,   417,   418,
     418,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   419,   419,   419,   419,   419,   419,   419,   419,   419,
     419,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   445,   446,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   465,   464,   466,
     466,   467,   467,   467,   467,   467,   467,   467,   467,   467,
     467,   467,   467,   467,   467,   467,   467,   467,   467,   467,
     467,   469,   468,   470,   470,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
     471,   471,   471,   471,   471,   472,   473,   474,   475,   476,
     476,   477,   477,   477,   477,   477,   477,   477,   477,   477,
     477,   477,   477,   477,   477,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   493,   494,   494,   494,   494,   494,   494,   494,
     495,   496,   497,   498,   499,   500
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
       4,     4,     0,     5,     3,     1,     1,     1,     4,     4,
       4,     4,     4,     0,     6,     0,     5,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     4,     4,     5,     2,     1,
       1,     1,     4,     0,     6,     0,     5,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
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
       2,     0,     1,     0,     0,     0,   195,   346,   398,     0,
     413,     0,   250,   383,   226,     0,     0,   129,   283,     0,
       0,   300,   324,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   580,   594,   590,   582,   583,   584,   585,   586,
     581,   587,   588,   589,   591,   592,   593,     0,     0,     0,
     411,     0,     0,   409,   410,     0,   480,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   551,     0,   527,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   430,   478,   472,
     473,   474,   475,   476,   471,   441,   431,   432,   466,   433,
     434,   435,   436,   437,   438,   439,   440,   468,   442,   443,
     477,   445,   450,   446,   448,   447,   461,   462,   449,   451,
     452,   453,   454,   455,   444,   457,   458,   459,   479,   469,
     470,   467,   460,   456,   464,   465,   463,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   619,     0,     0,     0,
       0,     0,     0,     0,   612,   613,   614,   617,   615,   616,
     618,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   298,     0,     0,   296,
     297,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   199,
     202,   204,   205,   206,   207,   208,   209,   210,   211,   200,
     201,   203,     0,     0,     0,     0,     0,   372,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   349,   350,   351,
     352,   353,   354,   356,   355,   358,   362,   359,   360,   361,
     357,   404,     0,     0,     0,   401,   402,   403,     0,     0,
     408,   425,     0,     0,   415,   424,     0,   421,   422,   423,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     429,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,   253,   254,   255,   256,   261,   257,   258,   259,   260,
     395,     0,   385,     0,   394,     0,   391,   392,   393,     0,
     228,     0,     0,     0,   238,     0,   236,   237,   239,   240,
     105,     0,     0,   101,     0,    45,     0,     0,     0,    41,
       0,     0,     0,   172,     0,     0,     0,   148,     0,     0,
     132,   133,   134,   135,   138,   139,   137,   136,   140,     0,
       0,     0,     0,     0,   286,   287,   288,   289,     0,     0,
       0,     0,     0,     0,     0,   611,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   310,     0,     0,   303,
     304,   305,   306,     0,     0,   332,     0,   327,   328,   329,
       0,     0,   295,     0,     0,     0,    90,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   578,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   363,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   348,     0,     0,     0,   400,     0,
     407,     0,     0,     0,     0,   420,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   428,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,   390,   241,     0,     0,     0,     0,     0,
     235,     0,   100,     0,     0,     0,    40,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   290,     0,
       0,     0,     0,   285,     0,     0,     0,     0,     0,     0,
     610,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,     0,    70,    75,    76,     0,    74,     0,     0,     0,
       0,     0,    48,   307,     0,     0,     0,     0,   302,   330,
       0,     0,     0,   326,     0,   294,    99,    98,    97,   605,
     604,   596,    26,    26,    26,    26,    26,    28,    27,   598,
     599,   603,   601,   600,   606,   607,   608,   609,   602,   597,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   347,
       0,     0,   399,   412,     0,     0,     0,   414,   493,   497,
     511,   577,   525,   491,   519,   522,   492,   483,   482,   484,
     485,   486,   500,   489,   490,   501,   488,   496,   495,   494,
     520,   481,   518,   575,   576,   515,   512,   562,   555,   572,
     573,   556,   557,   558,   559,   567,   560,   570,   574,   563,
     568,   564,   569,   561,   566,   565,   571,     0,   554,   517,
     537,   531,   548,   549,   532,   533,   534,   535,   543,   536,
     546,   550,   539,   544,   540,   545,   538,   542,   541,   547,
       0,   530,   510,   513,   524,   487,   514,   503,   508,   509,
     506,   507,   504,   505,   499,   498,   523,   526,   516,   521,
     502,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,     0,     0,   384,     0,     0,     0,   246,   242,   245,
     227,   106,     0,     0,   118,     0,     0,   110,   111,   113,
     112,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   284,   620,   624,   622,   625,
     621,   623,    83,    89,    81,    85,    84,    78,    77,    79,
      67,     0,    68,     0,    82,    80,    88,    86,    87,     0,
       0,     0,   301,     0,     0,   325,   299,    29,    30,    31,
      32,    33,   223,   224,   216,   218,   220,   219,   217,   213,
     225,   215,   214,    34,    34,    34,    36,    35,   221,   222,
     368,   370,   371,   381,   378,   376,   377,     0,   375,   365,
     379,   380,   364,   369,   367,   382,   366,   405,   406,   426,
     427,   419,     0,   418,   552,     0,   528,     0,   265,   266,
     275,   272,   277,   274,   273,   279,   276,   278,   271,     0,
     270,   264,   282,   281,   280,   263,   397,   389,     0,   388,
     396,   233,   234,   232,     0,   231,   249,   248,     0,     0,
       0,   114,     0,     0,     0,     0,   109,   147,   145,   187,
     184,   183,   176,   178,   194,   188,   191,   186,   177,   192,
     180,   189,   193,   181,   190,   185,   179,   182,     0,   175,
     142,   144,   146,   158,   152,   169,   170,   153,   154,   155,
     156,   164,   157,   167,   171,   160,   165,   161,   166,   159,
     163,   162,   168,     0,   151,   143,   292,   293,   291,    69,
      73,   308,   314,   320,   323,   316,   322,   317,   321,   319,
     315,   318,     0,   313,   309,   331,   336,   342,   345,   338,
     344,   339,   343,   341,   337,   340,     0,   335,    37,    38,
      39,   373,     0,   416,     0,   553,   529,   268,     0,   386,
       0,   229,     0,   247,   244,   243,     0,     0,     0,     0,
     108,   173,     0,   149,     0,   311,     0,   333,     0,   374,
     417,   269,   387,   230,   115,   124,   127,   126,   123,   128,
     125,   122,     0,   121,   117,   116,   174,   150,   312,   334,
     119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   777,   778,  1016,  1017,    25,   230,   231,
     232,   233,    26,   267,   268,   269,   270,   741,   742,   745,
     746,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,    27,    71,    72,    73,    74,    75,
      28,   222,   223,   224,   225,   226,   946,   947,   948,   949,
     950,  1083,  1212,  1213,    29,    60,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   714,  1133,  1134,   508,   710,
    1108,  1109,    30,    49,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    31,
      57,   474,   695,  1074,  1075,   475,   476,   477,  1080,   938,
     939,   478,   479,    32,    55,   450,   451,   452,   453,   454,
     455,   456,   681,  1059,  1060,   457,   458,   459,    33,    61,
     513,   514,   515,   516,   517,    34,   288,   289,   290,    35,
      64,   548,   549,   550,   551,   552,   755,  1152,  1153,    36,
      65,   556,   557,   558,   559,   761,  1166,  1167,    37,    50,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     604,  1027,  1028,   366,   367,   368,   369,   370,    38,    56,
     464,   690,  1068,  1069,   465,   466,   467,   468,    39,    51,
     374,   375,   376,   377,    40,   112,   113,   114,    41,    53,
     385,   623,  1042,  1043,   386,   387,   388,   389,    42,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   421,   900,   901,   213,
     419,   877,   878,   214,   215,   216,    43,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,    44,   243,   244,   245,   246,   247,   248,
     249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -745
static const yytype_int16 yypact[] =
{
    -745,   615,  -745,  -209,  -208,  -192,  -745,  -745,  -745,  -190,
    -745,  -183,  -745,  -745,  -745,  -169,  -167,  -745,  -745,  -144,
    -137,  -745,  -745,  -132,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   292,   784,  -111,
    -102,   -93,    22,   -90,   389,   -80,   -74,   -72,    50,    15,
     -65,   -60,   299,   388,   -54,   -34,    18,  -176,   -58,   -32,
     -22,     3,  -745,  -745,  -745,  -745,  -745,   -15,    -9,    26,
      38,    67,    69,    75,    80,    82,    88,    90,    93,   100,
     107,   195,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   569,   505,    13,
    -745,   115,    12,  -745,  -745,   258,  -745,   117,   122,   129,
     131,   140,   141,   144,   145,   146,   154,   155,   156,   159,
     161,   165,   166,   168,   170,   174,   175,   176,   177,   180,
     190,   194,   197,   199,   203,   204,  -745,   205,  -745,   206,
     209,   211,   212,   215,   219,   221,   224,   225,   229,   230,
     233,   234,   236,   237,   239,   240,    36,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,   343,    60,   284,
    -157,   241,    43,  -745,  -745,  -745,    66,   113,   242,   245,
      99,  -745,  -745,  -745,   348,    62,  -745,   249,   253,   264,
     266,   267,   271,    16,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   268,   273,   274,   280,   281,   285,   287,   290,   294,
     295,   296,   297,   306,   307,   308,   309,    74,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,   220,   277,  -745,   310,    20,  -745,
    -745,  -745,   252,   370,   384,   302,  -745,   410,   430,   371,
     432,   432,   433,   434,   436,   379,   390,   453,   432,   395,
     396,   342,  -745,   345,   349,   350,   352,   354,   355,   357,
     360,   361,   362,   363,   365,   366,   369,   152,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   346,   372,   381,   385,   386,  -745,   392,   393,
     397,   400,   401,   405,   407,   408,   270,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   409,   413,    51,  -745,  -745,  -745,   445,   351,
    -745,  -745,   414,   417,  -745,  -745,     8,  -745,  -745,  -745,
     428,   432,   432,   502,   446,   447,   508,   495,   454,   432,
     461,   432,   528,   536,   537,   480,   485,   493,   432,   556,
     557,   432,   562,   563,   548,   567,   568,   512,   513,   456,
     519,   459,   432,   432,   521,   522,   523,   524,    14,    54,
     530,   532,   432,   432,   570,   432,   533,   535,   538,   474,
    -745,   481,   479,   483,  -745,   484,   488,   492,   498,   501,
     128,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   503,  -745,   506,  -745,    19,  -745,  -745,  -745,   514,
    -745,   515,   518,   520,  -745,   116,  -745,  -745,  -745,  -745,
    -745,   539,   516,  -745,   496,  -745,   602,   612,   526,  -745,
     527,   531,   534,  -745,   540,   544,   545,  -745,   553,   183,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   541,
     560,   561,   573,    11,  -745,  -745,  -745,  -745,   572,   575,
     621,   584,   585,   432,   542,  -745,  -745,   629,   586,   630,
     632,   636,   637,   663,   670,   112,   196,   684,   691,   674,
     696,   701,   605,  -745,   619,   617,  -745,   622,    59,  -745,
    -745,  -745,  -745,   627,   626,  -745,   110,  -745,  -745,  -745,
     719,   633,  -745,   635,   638,   639,  -745,   641,   642,   646,
     265,   647,   648,   649,   650,   651,   652,   653,   654,   655,
     657,   658,  -745,  -745,   771,   774,   432,   775,   776,   777,
     778,   761,   782,   783,   432,   785,   785,   669,  -745,  -745,
     768,   164,   769,   728,   671,   772,   773,   779,   780,   792,
     781,   786,   787,   680,  -745,   788,   789,   681,  -745,   685,
    -745,   790,   791,   683,   687,  -745,   695,   697,   698,   699,
     700,   702,   703,   704,   705,   706,   707,   708,   709,   710,
     711,   712,   713,   714,   715,   716,   717,   718,   720,   721,
     722,   723,   724,   725,   726,   600,   727,   628,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,  -745,  -745,   798,
     803,   748,   816,   843,   846,   847,   849,   753,  -745,   851,
     752,   853,   757,  -745,  -745,   755,   856,   857,   876,   762,
    -745,   763,  -745,   187,   764,   765,  -745,  -745,   863,   822,
     766,   865,   867,   868,   770,   869,   793,  -745,  -745,   871,
     872,   873,   794,  -745,   795,   796,   797,   799,   800,   801,
    -745,   802,   804,   805,   806,   807,   808,   809,   810,  -745,
    -745,  -196,  -745,  -745,  -745,  -179,  -745,   811,   812,   813,
     814,   815,  -745,  -745,   874,   817,   875,   818,  -745,  -745,
     877,   819,   821,  -745,   823,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   432,   432,   432,   432,   432,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,    79,   835,   836,  -745,   837,   838,   839,   840,   841,
      -1,   842,   844,   845,   848,   850,   852,   854,   855,  -745,
     858,   859,  -745,  -745,   860,   861,   878,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -178,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -173,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   862,   864,   693,   866,   870,   879,   880,   881,  -745,
     882,   883,   884,  -745,   -36,   885,   886,   894,   887,  -745,
    -745,  -745,   888,   889,  -745,   890,    86,  -745,  -745,  -745,
    -745,  -745,  -745,   895,   896,   517,   897,   898,   899,   656,
     900,  -745,   901,   902,   903,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   112,  -745,   196,  -745,  -745,  -745,  -745,  -745,   904,
     464,   905,  -745,   906,   529,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,   785,   785,   785,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -168,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -160,  -745,  -745,   600,  -745,   628,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -159,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,   -57,  -745,
    -745,  -745,  -745,  -745,   -38,  -745,  -745,  -745,   907,   876,
     908,  -745,   913,   891,   -88,   909,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,    -7,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,    63,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,    94,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,   101,  -745,  -745,  -745,
    -745,  -745,    -1,  -745,   878,  -745,  -745,  -745,   693,  -745,
     883,  -745,   -36,  -745,  -745,  -745,   910,   403,   911,   912,
    -745,  -745,   517,  -745,   656,  -745,   464,  -745,   529,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,   104,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,   403,  -745
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -745,  -745,  -745,  -744,  -298,  -659,  -595,  -745,  -745,   767,
    -745,  -745,  -745,  -745,   750,  -745,  -745,  -745,    17,  -745,
      10,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,   924,  -745,  -745,  -745,
    -745,  -745,   914,  -745,  -745,  -745,  -745,    53,  -745,  -745,
    -745,  -745,  -745,  -225,  -745,  -745,  -745,   504,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -193,  -745,  -745,
    -745,  -188,  -745,  -745,  -745,   675,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -170,  -745,   558,  -745,  -745,  -745,
     -48,  -745,  -745,  -745,  -745,  -745,   610,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -117,  -745,  -745,  -745,  -745,  -745,
    -745,   550,  -745,  -745,  -745,  -745,  -745,   892,  -745,  -745,
    -745,  -745,   543,  -745,  -745,  -745,  -745,  -745,  -131,  -745,
    -745,  -745,   511,  -745,  -745,  -745,  -745,  -128,  -745,  -745,
    -745,   820,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -101,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -103,  -745,   614,  -745,  -745,  -745,  -745,
    -745,   754,  -745,  -745,  -745,  -745,   969,  -745,  -745,  -745,
    -745,  -745,  -745,   -92,  -745,   749,  -745,  -745,  -745,  -745,
     917,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,    39,  -745,
    -745,  -745,    40,  -745,  -745,  -745,  -745,  -745,   996,  -745,
    -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,  -745,
    -745,  -745,  -745,  -745,  -745,   915,  -745,  -745,  -745,  -745,
    -745,  -745
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     802,   803,   571,   572,    67,    45,    46,  1025,    47,   381,
     579,   801,   509,   110,   371,  1071,   227,   236,   980,   286,
     460,   286,   981,   110,    48,   510,    52,    68,   997,   998,
     999,  1000,  1001,    54,    69,   982,  1044,   116,   291,   983,
    1045,  1046,   117,   118,   220,  1047,  1171,    58,   119,    59,
    1172,   220,   371,   237,  1173,  1177,   120,   480,  1174,  1178,
     544,   460,   121,   509,   122,   123,   124,   238,   239,   240,
     241,   125,    62,   111,   372,   251,   510,   126,   127,    63,
     128,   129,   130,   111,    66,   242,   131,   942,  1013,  1014,
    1015,   132,    70,   627,   628,   133,   134,   382,   252,   135,
     227,   635,   228,   637,   511,   107,  1188,   287,   136,   287,
     644,   553,   372,   647,   108,   137,   138,   469,   139,   140,
     141,   142,   143,   109,   658,   659,   115,   383,   229,   441,
     512,   253,   373,   144,   670,   671,   217,   673,   461,   145,
     146,   147,   218,   148,   219,   442,   149,   150,   545,  1072,
     151,   234,   470,   313,  1073,   511,   235,  1179,   384,   292,
     443,  1180,   284,   254,   444,   255,   256,   314,   315,   462,
     373,   316,   471,   664,   665,   943,  1181,   472,   801,   461,
    1182,   512,   285,   152,   490,   293,   228,   153,   942,  1026,
     154,   155,   156,   157,   158,   294,    76,   159,   160,   554,
     491,   257,   297,   258,   259,   260,   261,  1191,   298,   546,
     462,  1192,   229,   666,   667,   492,    77,    78,   295,   493,
     262,   544,    79,   624,   463,   729,   722,   379,   317,   318,
     319,   524,   473,   320,   692,   561,   944,   161,   162,   163,
     445,   321,   164,   299,   263,   739,   740,   165,   446,   447,
     221,   439,   322,   323,   264,   300,  -107,   221,   482,   381,
     555,    80,    81,  -107,   547,   463,   617,   324,    82,    83,
      84,   342,   494,   343,   757,   344,   943,  1193,   553,   484,
     448,  1194,   265,   266,   301,   469,   302,   345,   792,   542,
      85,    86,   303,    67,   325,   495,   800,   304,   945,   305,
     236,  1085,   346,    87,    88,   306,   347,   307,  1195,   545,
     308,   496,  1196,    89,   488,  1197,    68,   309,  1220,  1198,
     470,    90,  1221,    69,   310,   762,   348,   485,   349,   743,
     744,   699,   378,   449,   390,   326,   237,   944,   350,   391,
     471,   806,   807,   687,   441,   472,   392,   382,   393,   490,
     238,   239,   240,   241,  1168,  1169,  1170,   394,   395,   351,
     442,   396,   397,   398,   570,   491,   554,   597,   242,   563,
     546,   399,   400,   401,   497,   443,   402,   383,   403,   444,
     492,    70,   404,   405,   493,   406,   352,   407,   498,   251,
     116,   408,   409,   410,   411,   117,   118,   412,   716,   945,
     473,   119,   772,   773,   774,   775,   776,   413,   384,   120,
     311,   414,   252,   353,   415,   121,   416,   122,   123,   124,
     417,   418,   420,   422,   125,   547,   423,   555,   424,   425,
     126,   127,   426,   128,   129,   130,   427,   494,   428,   131,
     354,   429,   430,  1205,   132,   253,   431,   432,   133,   134,
     433,   434,   135,   435,   436,   445,   437,   438,   481,   486,
     495,   136,   487,   446,   447,  1206,   518,  1207,   137,   138,
     519,   139,   140,   141,   142,   143,   496,   254,   355,   255,
     256,   520,   526,   521,   522,   613,   144,   564,   523,  1189,
     527,   528,   145,   146,   147,   448,   148,   529,   530,   149,
     150,   565,   531,   151,   532,  1208,   342,   533,   343,   567,
     344,   534,   535,   536,   537,   257,   566,   258,   259,   260,
     261,  1089,   345,   538,   539,   540,   541,   560,  1142,   568,
     569,   570,   573,   574,   262,   575,   152,   346,   576,   497,
     153,   347,  1090,   154,   155,   156,   157,   158,   449,   577,
     159,   160,   578,   498,   580,   581,   582,  1091,   263,   583,
     599,   348,   619,   349,  1092,   620,   584,   585,   264,   586,
     313,   587,   588,   350,   589,  1209,  1210,   590,   591,   592,
     593,  1093,   594,   595,   314,   315,   596,   626,   316,   600,
     161,   162,   163,  1156,   351,   164,   265,   266,   601,  1143,
     165,   629,   602,   603,  1094,   630,   631,   632,  1211,   605,
     606,  1095,   633,   634,   607,     2,     3,   608,   609,     4,
     636,   352,   610,  1096,   611,   612,   615,   638,  1144,     5,
     616,   621,     6,     7,   622,   639,   640,  1145,     8,   641,
    1097,  1098,  1099,  1146,   642,   317,   318,   319,   353,     9,
     320,   857,   643,    10,    11,   645,   646,  1147,   321,  1148,
    1149,   648,   649,    12,  1157,   650,   651,   652,  1150,   322,
     323,   653,   654,   655,  1151,   354,   657,    13,   656,   880,
     660,   661,   662,   663,   324,    14,    15,   672,   677,   668,
    1100,   669,   674,  1158,   675,   678,   679,   676,   701,  1101,
     680,   682,  1159,    16,  1102,   683,  1050,  1113,  1160,   684,
    1103,   325,   703,   355,  1104,   685,  1105,    17,   686,   704,
     689,  1106,  1161,   691,  1162,  1163,  1051,  1107,   694,   705,
     702,   724,   696,  1164,   725,   697,  1052,   698,   726,  1165,
     706,   707,  1053,   727,   728,   732,   731,   733,   708,   734,
      18,   709,   326,   735,   736,   718,   730,   711,  1054,    19,
      20,   712,   713,    21,    22,   858,   859,   860,   861,   862,
     715,   863,   864,   749,   865,   866,   867,   719,   720,   868,
     737,   869,   870,  1055,   871,    76,   872,   738,   873,   874,
     721,  1056,   875,   881,   882,   883,   884,   885,   876,   886,
     887,   747,   888,   889,   890,    77,    78,   891,   748,   892,
     893,    79,   894,   750,   895,    23,   896,   897,   751,   752,
     898,  1114,  1115,  1116,  1117,  1118,   899,  1119,  1120,  1057,
    1121,  1122,  1123,   753,   754,  1124,   764,  1125,  1126,   756,
    1127,   759,  1128,   760,  1129,  1130,  1058,   765,  1131,   766,
      80,    81,   767,   768,  1132,   769,   770,    82,    83,    84,
     771,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     790,   788,   789,   791,   793,   794,   795,   796,   797,    85,
      86,   798,   799,   804,   801,   805,   808,   809,   810,   811,
     812,   815,    87,    88,   819,   822,   813,   814,   816,   823,
     826,   827,    89,   817,   818,   820,   821,   824,   825,   828,
      90,   829,   830,   831,   832,   921,   833,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   845,   846,
     847,   848,   849,   924,   850,   851,   852,   853,   854,   855,
     856,   879,   925,   902,   903,   904,   905,   906,   907,   908,
     909,   910,   911,   912,   913,   914,   915,   916,   917,   918,
     919,   920,   922,   926,   927,   923,   928,   929,   930,   931,
     932,   933,   934,   935,   936,   937,   940,   941,   951,   952,
     953,   954,   956,   955,   957,   958,   960,   959,   962,   963,
     964,   989,   991,  1140,   993,   296,  1222,   489,  1139,  1086,
    1041,  1217,   598,   717,  1216,  1067,  1183,   961,   965,   966,
     967,   968,  1203,   969,   970,   971,   972,   543,   973,   974,
     975,   976,   977,   978,   979,   984,   985,   986,   987,   988,
    1186,  1184,   992,   700,   990,   995,   994,   996,  1002,  1003,
    1004,  1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1018,
    1019,  1020,  1021,  1022,  1023,  1024,  1029,  1078,  1030,  1031,
     688,  1201,  1032,   723,  1033,  1218,  1034,   763,  1035,  1036,
    1219,  1199,  1037,  1038,  1039,  1040,  1048,  1202,  1049,   693,
    1061,   380,  1200,   440,  1062,  1175,  1176,   312,     0,     0,
       0,   758,     0,  1063,  1064,  1065,  1066,     0,  1070,  1076,
    1077,     0,  1081,     0,     0,  1079,  1082,  1084,  1187,  1087,
    1088,  1110,  1111,  1112,  1135,  1136,  1137,  1138,  1141,  1154,
    1155,     0,  1185,  1190,  1204,  1214,  1215,     0,   618,     0,
       0,     0,     0,     0,     0,   625,   483,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   525,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   614,     0,     0,     0,
     562
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-745)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     595,   596,   300,   301,     1,   214,   215,     8,   216,     1,
     308,    99,     1,     1,     1,    51,     1,     1,   214,     1,
       1,     1,   218,     1,   216,    14,   216,    24,   772,   773,
     774,   775,   776,   216,    31,   214,   214,     1,   214,   218,
     218,   214,     6,     7,     1,   218,   214,   216,    12,   216,
     218,     1,     1,    37,   214,   214,    20,   214,   218,   218,
       1,     1,    26,     1,    28,    29,    30,    51,    52,    53,
      54,    35,   216,    61,    61,     1,    14,    41,    42,   216,
      44,    45,    46,    61,   216,    69,    50,     1,     9,    10,
      11,    55,    89,   391,   392,    59,    60,    89,    24,    63,
       1,   399,    87,   401,    93,   216,   194,    89,    72,    89,
     408,     1,    61,   411,   216,    79,    80,     1,    82,    83,
      84,    85,    86,   216,   422,   423,   216,   119,   113,     1,
     119,    57,   119,    97,   432,   433,   216,   435,   119,   103,
     104,   105,   216,   107,   216,    17,   110,   111,    89,   185,
     114,   216,    36,     1,   190,    93,   216,   214,   150,   217,
      32,   218,   216,    89,    36,    91,    92,    15,    16,   150,
     119,    19,    56,   159,   160,    89,   214,    61,    99,   119,
     218,   119,   216,   147,     1,   217,    87,   151,     1,   190,
     154,   155,   156,   157,   158,   217,     1,   161,   162,    89,
      17,   127,   217,   129,   130,   131,   132,   214,   217,   150,
     150,   218,   113,   159,   160,    32,    21,    22,   215,    36,
     146,     1,    27,   215,   205,   523,   215,   215,    76,    77,
      78,   215,   116,    81,   215,   215,   150,   201,   202,   203,
     112,    89,   206,   217,   170,   133,   134,   211,   120,   121,
     207,   215,   100,   101,   180,   217,   213,   207,   215,     1,
     150,    66,    67,   213,   205,   205,   215,   115,    73,    74,
      75,     1,    89,     3,   215,     5,    89,   214,     1,   213,
     152,   218,   208,   209,   217,     1,   217,    17,   586,   215,
      95,    96,   217,     1,   142,   112,   594,   217,   212,   217,
       1,   215,    32,   108,   109,   217,    36,   217,   214,    89,
     217,   128,   218,   118,   215,   214,    24,   217,   214,   218,
      36,   126,   218,    31,   217,   215,    56,   214,    58,   133,
     134,   215,   217,   205,   217,   183,    37,   150,    68,   217,
      56,   177,   178,   215,     1,    61,   217,    89,   217,     1,
      51,    52,    53,    54,  1013,  1014,  1015,   217,   217,    89,
      17,   217,   217,   217,    99,    17,    89,   215,    69,   117,
     150,   217,   217,   217,   191,    32,   217,   119,   217,    36,
      32,    89,   217,   217,    36,   217,   116,   217,   205,     1,
       1,   217,   217,   217,   217,     6,     7,   217,   215,   212,
     116,    12,   137,   138,   139,   140,   141,   217,   150,    20,
     215,   217,    24,   143,   217,    26,   217,    28,    29,    30,
     217,   217,   217,   217,    35,   205,   217,   150,   217,   217,
      41,    42,   217,    44,    45,    46,   217,    89,   217,    50,
     170,   217,   217,    40,    55,    57,   217,   217,    59,    60,
     217,   217,    63,   217,   217,   112,   217,   217,   217,   217,
     112,    72,   217,   120,   121,    62,   217,    64,    79,    80,
     217,    82,    83,    84,    85,    86,   128,    89,   208,    91,
      92,   217,   214,   217,   217,   215,    97,   117,   217,  1084,
     217,   217,   103,   104,   105,   152,   107,   217,   217,   110,
     111,   117,   217,   114,   217,   102,     1,   217,     3,    99,
       5,   217,   217,   217,   217,   127,   214,   129,   130,   131,
     132,     4,    17,   217,   217,   217,   217,   217,    64,    99,
     159,    99,    99,    99,   146,    99,   147,    32,   159,   191,
     151,    36,    25,   154,   155,   156,   157,   158,   205,   159,
     161,   162,    99,   205,   159,   159,   214,    40,   170,   214,
     214,    56,   117,    58,    47,   214,   217,   217,   180,   217,
       1,   217,   217,    68,   217,   172,   173,   217,   217,   217,
     217,    64,   217,   217,    15,    16,   217,   159,    19,   217,
     201,   202,   203,    64,    89,   206,   208,   209,   217,   135,
     211,    99,   217,   217,    87,   159,   159,    99,   205,   217,
     217,    94,   117,   159,   217,     0,     1,   217,   217,     4,
     159,   116,   217,   106,   217,   217,   217,    99,   164,    14,
     217,   217,    17,    18,   217,    99,    99,   173,    23,   159,
     123,   124,   125,   179,   159,    76,    77,    78,   143,    34,
      81,    51,   159,    38,    39,    99,    99,   193,    89,   195,
     196,    99,    99,    48,   135,   117,    99,    99,   204,   100,
     101,   159,   159,   217,   210,   170,   217,    62,   159,    51,
     159,   159,   159,   159,   115,    70,    71,   117,   214,   159,
     173,   159,   159,   164,   159,   214,   217,   159,   159,   182,
     217,   217,   173,    88,   187,   217,    13,    51,   179,   217,
     193,   142,   216,   208,   197,   217,   199,   102,   217,   117,
     217,   204,   193,   217,   195,   196,    33,   210,   214,   117,
     214,   159,   217,   204,   159,   217,    43,   217,   117,   210,
     214,   214,    49,   159,   159,   159,   117,   117,   217,   117,
     135,   217,   183,   117,   117,   214,   214,   217,    65,   144,
     145,   217,   217,   148,   149,   165,   166,   167,   168,   169,
     217,   171,   172,    99,   174,   175,   176,   217,   217,   179,
     117,   181,   182,    90,   184,     1,   186,   117,   188,   189,
     217,    98,   192,   165,   166,   167,   168,   169,   198,   171,
     172,   117,   174,   175,   176,    21,    22,   179,   117,   181,
     182,    27,   184,   117,   186,   200,   188,   189,   117,   214,
     192,   165,   166,   167,   168,   169,   198,   171,   172,   136,
     174,   175,   176,   214,   217,   179,   117,   181,   182,   217,
     184,   214,   186,   217,   188,   189,   153,   214,   192,   214,
      66,    67,   214,   214,   198,   214,   214,    73,    74,    75,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
      99,   214,   214,    99,    99,    99,    99,    99,   117,    95,
      96,    99,    99,   214,    99,   117,   117,   159,   217,   117,
     117,    99,   108,   109,   214,   214,   117,   117,   117,   214,
     217,   214,   118,   117,   117,   117,   117,   117,   117,   214,
     126,   214,   214,   214,   214,   117,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   117,   214,   214,   214,   214,   214,   214,
     214,   214,    99,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   159,   117,   117,   217,   117,   214,   117,   217,
     117,   214,   217,   117,   117,    99,   214,   214,   214,   214,
     117,   159,   117,   217,   117,   117,   117,   217,   117,   117,
     117,   117,   117,   983,   117,    71,  1221,   230,   981,   946,
     122,  1194,   327,   499,  1192,   122,    99,   214,   214,   214,
     214,   214,  1182,   214,   214,   214,   214,   267,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     117,  1079,   214,   475,   217,   214,   217,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   163,   214,   214,
     450,  1178,   214,   513,   214,  1196,   214,   556,   214,   214,
    1198,  1172,   214,   214,   214,   214,   214,  1180,   214,   465,
     214,   112,  1174,   166,   214,  1045,  1047,    91,    -1,    -1,
      -1,   548,    -1,   214,   214,   214,   214,    -1,   214,   214,
     214,    -1,   214,    -1,    -1,   218,   217,   217,   217,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,    -1,   214,   214,   214,   214,   214,    -1,   374,    -1,
      -1,    -1,    -1,    -1,    -1,   386,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   356,    -1,    -1,    -1,
     288
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   220,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    88,   102,   135,   144,
     145,   148,   149,   200,   221,   226,   231,   253,   259,   273,
     291,   308,   322,   337,   344,   348,   358,   367,   387,   397,
     403,   407,   417,   475,   492,   214,   215,   216,   216,   292,
     368,   398,   216,   408,   216,   323,   388,   309,   216,   216,
     274,   338,   216,   216,   349,   359,   216,     1,    24,    31,
      89,   254,   255,   256,   257,   258,     1,    21,    22,    27,
      66,    67,    73,    74,    75,    95,    96,   108,   109,   118,
     126,   476,   477,   478,   479,   480,   481,   482,   483,   484,
     485,   486,   487,   488,   489,   490,   491,   216,   216,   216,
       1,    61,   404,   405,   406,   216,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    80,    82,
      83,    84,    85,    86,    97,   103,   104,   105,   107,   110,
     111,   114,   147,   151,   154,   155,   156,   157,   158,   161,
     162,   201,   202,   203,   206,   211,   418,   419,   420,   421,
     422,   423,   424,   425,   426,   427,   428,   429,   430,   431,
     432,   433,   434,   435,   436,   437,   438,   439,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   463,   464,   468,   472,   473,   474,   216,   216,   216,
       1,   207,   260,   261,   262,   263,   264,     1,    87,   113,
     227,   228,   229,   230,   216,   216,     1,    37,    51,    52,
      53,    54,    69,   493,   494,   495,   496,   497,   498,   499,
     500,     1,    24,    57,    89,    91,    92,   127,   129,   130,
     131,   132,   146,   170,   180,   208,   209,   232,   233,   234,
     235,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   216,   216,     1,    89,   345,   346,
     347,   214,   217,   217,   217,   215,   255,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   215,   477,     1,    15,    16,    19,    76,    77,    78,
      81,    89,   100,   101,   115,   142,   183,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,     1,     3,     5,    17,    32,    36,    56,    58,
      68,    89,   116,   143,   170,   208,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   382,   383,   384,   385,
     386,     1,    61,   119,   399,   400,   401,   402,   217,   215,
     405,     1,    89,   119,   150,   409,   413,   414,   415,   416,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   469,
     217,   465,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   215,
     419,     1,    17,    32,    36,   112,   120,   121,   152,   205,
     324,   325,   326,   327,   328,   329,   330,   334,   335,   336,
       1,   119,   150,   205,   389,   393,   394,   395,   396,     1,
      36,    56,    61,   116,   310,   314,   315,   316,   320,   321,
     214,   217,   215,   261,   213,   214,   217,   217,   215,   228,
       1,    17,    32,    36,    89,   112,   128,   191,   205,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   287,     1,
      14,    93,   119,   339,   340,   341,   342,   343,   217,   217,
     217,   217,   217,   217,   215,   494,   214,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   215,   233,     1,    89,   150,   205,   350,   351,
     352,   353,   354,     1,    89,   150,   360,   361,   362,   363,
     217,   215,   346,   117,   117,   117,   214,    99,    99,   159,
      99,   223,   223,    99,    99,    99,   159,   159,    99,   223,
     159,   159,   214,   214,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   215,   294,   214,
     217,   217,   217,   217,   379,   217,   217,   217,   217,   217,
     217,   217,   217,   215,   370,   217,   217,   215,   400,   117,
     214,   217,   217,   410,   215,   414,   159,   223,   223,    99,
     159,   159,    99,   117,   159,   223,   159,   223,    99,    99,
      99,   159,   159,   159,   223,    99,    99,   223,    99,    99,
     117,    99,    99,   159,   159,   217,   159,   217,   223,   223,
     159,   159,   159,   159,   159,   160,   159,   160,   159,   159,
     223,   223,   117,   223,   159,   159,   159,   214,   214,   217,
     217,   331,   217,   217,   217,   217,   217,   215,   325,   217,
     390,   217,   215,   394,   214,   311,   217,   217,   217,   215,
     315,   159,   214,   216,   117,   117,   214,   214,   217,   217,
     288,   217,   217,   217,   284,   217,   215,   276,   214,   217,
     217,   217,   215,   340,   159,   159,   117,   159,   159,   223,
     214,   117,   159,   117,   117,   117,   117,   117,   117,   133,
     134,   236,   237,   133,   134,   238,   239,   117,   117,    99,
     117,   117,   214,   214,   217,   355,   217,   215,   351,   214,
     217,   364,   215,   361,   117,   214,   214,   214,   214,   214,
     214,   214,   137,   138,   139,   140,   141,   222,   223,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
      99,    99,   223,    99,    99,    99,    99,   117,    99,    99,
     223,    99,   225,   225,   214,   117,   177,   178,   117,   159,
     217,   117,   117,   117,   117,    99,   117,   117,   117,   214,
     117,   117,   214,   214,   117,   117,   217,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,    51,   165,   166,
     167,   168,   169,   171,   172,   174,   175,   176,   179,   181,
     182,   184,   186,   188,   189,   192,   198,   470,   471,   214,
      51,   165,   166,   167,   168,   169,   171,   172,   174,   175,
     176,   179,   181,   182,   184,   186,   188,   189,   192,   198,
     466,   467,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   117,   159,   217,   117,    99,   117,   117,   117,   214,
     117,   217,   117,   214,   217,   117,   117,    99,   318,   319,
     214,   214,     1,    89,   150,   212,   265,   266,   267,   268,
     269,   214,   214,   117,   159,   217,   117,   117,   117,   217,
     117,   214,   117,   117,   117,   214,   214,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   218,   214,   218,   214,   214,   214,   214,   214,   117,
     217,   117,   214,   117,   217,   214,   214,   222,   222,   222,
     222,   222,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   214,   214,     9,    10,    11,   224,   225,   214,   214,
     214,   214,   214,   214,   214,     8,   190,   380,   381,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     214,   122,   411,   412,   214,   218,   214,   218,   214,   214,
      13,    33,    43,    49,    65,    90,    98,   136,   153,   332,
     333,   214,   214,   214,   214,   214,   214,   122,   391,   392,
     214,    51,   185,   190,   312,   313,   214,   214,   163,   218,
     317,   214,   217,   270,   217,   215,   266,   214,   214,     4,
      25,    40,    47,    64,    87,    94,   106,   123,   124,   125,
     173,   182,   187,   193,   197,   199,   204,   210,   289,   290,
     214,   214,   214,    51,   165,   166,   167,   168,   169,   171,
     172,   174,   175,   176,   179,   181,   182,   184,   186,   188,
     189,   192,   198,   285,   286,   214,   214,   214,   214,   237,
     239,   214,    64,   135,   164,   173,   179,   193,   195,   196,
     204,   210,   356,   357,   214,   214,    64,   135,   164,   173,
     179,   193,   195,   196,   204,   210,   365,   366,   224,   224,
     224,   214,   218,   214,   218,   471,   467,   214,   218,   214,
     218,   214,   218,    99,   319,   214,   117,   217,   194,   225,
     214,   214,   218,   214,   218,   214,   218,   214,   218,   381,
     412,   333,   392,   313,   214,    40,    62,    64,   102,   172,
     173,   205,   271,   272,   214,   214,   290,   286,   357,   366,
     214,   218,   272
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
#line 357 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1813 of yacc.c  */
#line 359 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1813 of yacc.c  */
#line 363 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1813 of yacc.c  */
#line 367 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1813 of yacc.c  */
#line 371 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1813 of yacc.c  */
#line 375 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1813 of yacc.c  */
#line 379 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1813 of yacc.c  */
#line 384 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1813 of yacc.c  */
#line 385 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1813 of yacc.c  */
#line 386 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1813 of yacc.c  */
#line 387 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1813 of yacc.c  */
#line 388 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1813 of yacc.c  */
#line 402 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1813 of yacc.c  */
#line 408 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1813 of yacc.c  */
#line 433 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1813 of yacc.c  */
#line 439 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1813 of yacc.c  */
#line 448 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1813 of yacc.c  */
#line 454 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1813 of yacc.c  */
#line 462 "conf_parser.y"
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
#line 501 "conf_parser.y"
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
#line 560 "conf_parser.y"
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
#line 588 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1813 of yacc.c  */
#line 596 "conf_parser.y"
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
#line 611 "conf_parser.y"
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
#line 626 "conf_parser.y"
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
#line 635 "conf_parser.y"
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
#line 649 "conf_parser.y"
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
#line 658 "conf_parser.y"
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
#line 686 "conf_parser.y"
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
#line 716 "conf_parser.y"
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
#line 739 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1813 of yacc.c  */
#line 754 "conf_parser.y"
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
#line 763 "conf_parser.y"
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
#line 772 "conf_parser.y"
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
#line 790 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1813 of yacc.c  */
#line 796 "conf_parser.y"
    {
  lfile[0] = '\0';
  ltype = 0;
  lsize = 0;
}
    break;

  case 108:
/* Line 1813 of yacc.c  */
#line 801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && ltype > 0)
    log_add_file(ltype, lsize, lfile);
}
    break;

  case 115:
/* Line 1813 of yacc.c  */
#line 813 "conf_parser.y"
    {
  strlcpy(lfile, yylval.string, sizeof(lfile));
}
    break;

  case 116:
/* Line 1813 of yacc.c  */
#line 818 "conf_parser.y"
    {
  lsize = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1813 of yacc.c  */
#line 821 "conf_parser.y"
    {
  lsize = 0;
}
    break;

  case 118:
/* Line 1813 of yacc.c  */
#line 826 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = 0;
}
    break;

  case 122:
/* Line 1813 of yacc.c  */
#line 833 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1813 of yacc.c  */
#line 837 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1813 of yacc.c  */
#line 841 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1813 of yacc.c  */
#line 845 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1813 of yacc.c  */
#line 849 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1813 of yacc.c  */
#line 853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1813 of yacc.c  */
#line 857 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ltype = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1813 of yacc.c  */
#line 867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = conf_make(CONF_OPER);
    SetConfEncrypted(yy_conf); /* Yes, the default is encrypted */
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
#line 879 "conf_parser.y"
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
      struct MaskItem *new_conf;
      yy_tmp = ptr->data;

      new_conf = conf_make(CONF_OPER);
      new_conf->flags = yy_conf->flags;

      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_tmp->user != NULL)
	DupString(new_conf->user, yy_tmp->user);
      else
	DupString(new_conf->user, "*");
      if (yy_tmp->host != NULL)
	DupString(new_conf->host, yy_tmp->host);
      else
	DupString(new_conf->host, "*");

      new_conf->htype = parse_netmask(new_conf->host, &new_conf->addr,
                                     &new_conf->bits);

      conf_add_class_to_conf(new_conf, class_name);
      if (yy_conf->passwd != NULL)
        DupString(new_conf->passwd, yy_conf->passwd);

      new_conf->port = yy_conf->port;
#ifdef HAVE_LIBCRYPTO
      if (yy_conf->rsa_public_key_file != NULL)
      {
        BIO *file;

        DupString(new_conf->rsa_public_key_file,
		  yy_conf->rsa_public_key_file);

        file = BIO_new_file(yy_conf->rsa_public_key_file, "r");
        new_conf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, 
							   NULL, 0, NULL);
        BIO_set_close(file, BIO_CLOSE);
        BIO_free(file);
      }
#endif

#ifdef HAVE_LIBCRYPTO
      if (yy_tmp->name && (yy_tmp->passwd || yy_conf->rsa_public_key)
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

    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 142:
/* Line 1813 of yacc.c  */
#line 964 "conf_parser.y"
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
#line 973 "conf_parser.y"
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

    if (yy_conf->user == NULL)
    {
      DupString(yy_conf->user, userbuf);
      DupString(yy_conf->host, hostbuf);

      yy_conf->htype = parse_netmask(yy_conf->host, &yy_conf->addr,
                                    &yy_conf->bits);
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
#line 1010 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->passwd != NULL)
      memset(yy_conf->passwd, 0, strlen(yy_conf->passwd));

    MyFree(yy_conf->passwd);
    DupString(yy_conf->passwd, yylval.string);
  }
}
    break;

  case 145:
/* Line 1813 of yacc.c  */
#line 1022 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_conf);
    else
      ClearConfEncrypted(yy_conf);
  }
}
    break;

  case 146:
/* Line 1813 of yacc.c  */
#line 1033 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    BIO *file;

    if (yy_conf->rsa_public_key != NULL)
    {
      RSA_free(yy_conf->rsa_public_key);
      yy_conf->rsa_public_key = NULL;
    }

    if (yy_conf->rsa_public_key_file != NULL)
    {
      MyFree(yy_conf->rsa_public_key_file);
      yy_conf->rsa_public_key_file = NULL;
    }

    DupString(yy_conf->rsa_public_key_file, yylval.string);
    file = BIO_new_file(yylval.string, "r");

    if (file == NULL)
    {
      yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
      break;
    }

    yy_conf->rsa_public_key = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL);

    if (yy_conf->rsa_public_key == NULL)
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
#line 1075 "conf_parser.y"
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
#line 1084 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes = 0;
}
    break;

  case 152:
/* Line 1813 of yacc.c  */
#line 1091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1813 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1813 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1813 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1813 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1813 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1813 of yacc.c  */
#line 1115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1813 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1813 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1813 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1813 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1813 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1813 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1813 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1813 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1813 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1813 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1813 of yacc.c  */
#line 1159 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1813 of yacc.c  */
#line 1163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1813 of yacc.c  */
#line 1167 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->modes |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1813 of yacc.c  */
#line 1173 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port = 0;
}
    break;

  case 176:
/* Line 1813 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1813 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1813 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1813 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1813 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1813 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1813 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1813 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1813 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1813 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1813 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1813 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1813 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1813 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1813 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1813 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1813 of yacc.c  */
#line 1244 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1813 of yacc.c  */
#line 1248 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1813 of yacc.c  */
#line 1252 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1813 of yacc.c  */
#line 1262 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    yy_class = class_make();
  }
}
    break;

  case 196:
/* Line 1813 of yacc.c  */
#line 1268 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    struct ClassItem *class = NULL;

    if (yy_class_name == NULL)
      class_free(yy_class);
    else
    {
      class = class_find(yy_class_name, 0);

      if (class != NULL)		/* The class existed already */
      {
        int user_count = 0;

        rebuild_cidr_class(class, yy_class);

        user_count = class->ref_count;
        memcpy(class, yy_class, sizeof(*class));
        class->ref_count = user_count;
        class->active = 1;

        class_free(yy_class);

        MyFree(class->name);            /* Allows case change of class name */
        class->name = yy_class_name;
      }
      else	/* Brand new class */
      {
        MyFree(yy_class->name);          /* just in case it was allocated */
        yy_class->name = yy_class_name;
        yy_class->active = 1;
      }
    }

    yy_class_name = NULL;
  }
}
    break;

  case 213:
/* Line 1813 of yacc.c  */
#line 1322 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
  {
    MyFree(yy_class_name);
    DupString(yy_class_name, yylval.string);
  }
}
    break;

  case 214:
/* Line 1813 of yacc.c  */
#line 1331 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->ping_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:
/* Line 1813 of yacc.c  */
#line 1337 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_perip = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1813 of yacc.c  */
#line 1343 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->con_freq = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1813 of yacc.c  */
#line 1349 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_total = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1813 of yacc.c  */
#line 1355 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_global = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1813 of yacc.c  */
#line 1361 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_local = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1813 of yacc.c  */
#line 1367 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1813 of yacc.c  */
#line 1373 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->max_sendq = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1813 of yacc.c  */
#line 1379 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      yy_class->max_recvq = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1813 of yacc.c  */
#line 1386 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv4 = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1813 of yacc.c  */
#line 1392 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->cidr_bitlen_ipv6 = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1813 of yacc.c  */
#line 1398 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    yy_class->number_per_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1813 of yacc.c  */
#line 1407 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    listener_address = NULL;
    listener_flags = 0;
  }
}
    break;

  case 227:
/* Line 1813 of yacc.c  */
#line 1414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    listener_address = NULL;
  }
}
    break;

  case 228:
/* Line 1813 of yacc.c  */
#line 1423 "conf_parser.y"
    {
  listener_flags = 0;
}
    break;

  case 232:
/* Line 1813 of yacc.c  */
#line 1429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SSL;
}
    break;

  case 233:
/* Line 1813 of yacc.c  */
#line 1433 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_HIDDEN;
}
    break;

  case 234:
/* Line 1813 of yacc.c  */
#line 1437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    listener_flags |= LISTENER_SERVER;
}
    break;

  case 242:
/* Line 1813 of yacc.c  */
#line 1447 "conf_parser.y"
    { listener_flags = 0; }
    break;

  case 246:
/* Line 1813 of yacc.c  */
#line 1452 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1466 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1486 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 249:
/* Line 1813 of yacc.c  */
#line 1495 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(listener_address);
    DupString(listener_address, yylval.string);
  }
}
    break;

  case 250:
/* Line 1813 of yacc.c  */
#line 1507 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = conf_make(CONF_CLIENT);
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 251:
/* Line 1813 of yacc.c  */
#line 1518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct CollectItem *yy_tmp = NULL;
    dlink_node *ptr = NULL, *next_ptr = NULL;

    if (yy_conf->user && yy_conf->host)
    {
      conf_add_class_to_conf(yy_conf, class_name);
      add_conf_by_address(CONF_CLIENT, yy_conf);
    }
    else
      conf_free(yy_conf);

    /* copy over settings from first struct */
    DLINK_FOREACH_SAFE(ptr, next_ptr, col_conf_list.head)
    {
      struct MaskItem *new_conf = conf_make(CONF_CLIENT);

      yy_tmp = ptr->data;

      assert(yy_tmp->user && yy_tmp->host);

      if (yy_conf->passwd != NULL)
        DupString(new_conf->passwd, yy_conf->passwd);
      if (yy_conf->name != NULL)
        DupString(new_conf->name, yy_conf->name);
      if (yy_conf->passwd != NULL)
        DupString(new_conf->passwd, yy_conf->passwd);

      new_conf->flags = yy_conf->flags;
      new_conf->port  = yy_conf->port;

      DupString(new_conf->user, yy_tmp->user);
      collapse(new_conf->user);

      DupString(new_conf->host, yy_tmp->host);
      collapse(new_conf->host);

      conf_add_class_to_conf(new_conf, class_name);
      add_conf_by_address(CONF_CLIENT, new_conf);
      dlinkDelete(&yy_tmp->node, &col_conf_list);
      free_collect_item(yy_tmp);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
  }
}
    break;

  case 263:
/* Line 1813 of yacc.c  */
#line 1575 "conf_parser.y"
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

    if (yy_conf->user == NULL)
    {
      DupString(yy_conf->user, userbuf);
      DupString(yy_conf->host, hostbuf);
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
/* Line 1813 of yacc.c  */
#line 1610 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    /* be paranoid */
    if (yy_conf->passwd != NULL)
      memset(yy_conf->passwd, 0, strlen(yy_conf->passwd));

    MyFree(yy_conf->passwd);
    DupString(yy_conf->passwd, yylval.string);
  }
}
    break;

  case 265:
/* Line 1813 of yacc.c  */
#line 1623 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 266:
/* Line 1813 of yacc.c  */
#line 1632 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      SetConfEncrypted(yy_conf);
    else
      ClearConfEncrypted(yy_conf);
  }
}
    break;

  case 267:
/* Line 1813 of yacc.c  */
#line 1643 "conf_parser.y"
    {
}
    break;

  case 271:
/* Line 1813 of yacc.c  */
#line 1648 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:
/* Line 1813 of yacc.c  */
#line 1652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:
/* Line 1813 of yacc.c  */
#line 1656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:
/* Line 1813 of yacc.c  */
#line 1660 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:
/* Line 1813 of yacc.c  */
#line 1664 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:
/* Line 1813 of yacc.c  */
#line 1668 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:
/* Line 1813 of yacc.c  */
#line 1672 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:
/* Line 1813 of yacc.c  */
#line 1676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:
/* Line 1813 of yacc.c  */
#line 1680 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 280:
/* Line 1813 of yacc.c  */
#line 1686 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);

    if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
    {    
      DupString(yy_conf->name, yylval.string);
      yy_conf->flags |= CONF_FLAGS_SPOOF_IP;
    }
    else
    {
      ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
      yy_conf->name = NULL;
    }
  }
}
    break;

  case 281:
/* Line 1813 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf->flags |= CONF_FLAGS_REDIR;
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 282:
/* Line 1813 of yacc.c  */
#line 1715 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf->flags |= CONF_FLAGS_REDIR;
    yy_conf->port = (yyvsp[(3) - (4)].number);
  }
}
    break;

  case 283:
/* Line 1813 of yacc.c  */
#line 1728 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 284:
/* Line 1813 of yacc.c  */
#line 1735 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    resv_reason = NULL;
  }
}
    break;

  case 291:
/* Line 1813 of yacc.c  */
#line 1747 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(resv_reason);
    DupString(resv_reason, yylval.string);
  }
}
    break;

  case 292:
/* Line 1813 of yacc.c  */
#line 1756 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1771 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char def_reason[] = "No reason";

    create_nick_resv(yylval.string, resv_reason != NULL ? resv_reason : def_reason, 1);
  }
}
    break;

  case 299:
/* Line 1813 of yacc.c  */
#line 1789 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      yy_conf = conf_make(CONF_SERVICE);
      DupString(yy_conf->name, yylval.string);
    }
  }
}
    break;

  case 300:
/* Line 1813 of yacc.c  */
#line 1804 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = conf_make(CONF_ULINE);
    yy_conf->flags = SHARED_ALL;
  }
}
    break;

  case 301:
/* Line 1813 of yacc.c  */
#line 1811 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = NULL;
  }
}
    break;

  case 308:
/* Line 1813 of yacc.c  */
#line 1822 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 309:
/* Line 1813 of yacc.c  */
#line 1831 "conf_parser.y"
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

    DupString(yy_conf->user, userbuf);
    DupString(yy_conf->host, hostbuf);
  }
}
    break;

  case 310:
/* Line 1813 of yacc.c  */
#line 1853 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 314:
/* Line 1813 of yacc.c  */
#line 1860 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 315:
/* Line 1813 of yacc.c  */
#line 1864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 316:
/* Line 1813 of yacc.c  */
#line 1868 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 317:
/* Line 1813 of yacc.c  */
#line 1872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 318:
/* Line 1813 of yacc.c  */
#line 1876 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 319:
/* Line 1813 of yacc.c  */
#line 1880 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 320:
/* Line 1813 of yacc.c  */
#line 1884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 321:
/* Line 1813 of yacc.c  */
#line 1888 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 322:
/* Line 1813 of yacc.c  */
#line 1892 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 323:
/* Line 1813 of yacc.c  */
#line 1896 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 324:
/* Line 1813 of yacc.c  */
#line 1905 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = conf_make(CONF_CLUSTER);
  }
}
    break;

  case 325:
/* Line 1813 of yacc.c  */
#line 1911 "conf_parser.y"
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
/* Line 1813 of yacc.c  */
#line 1924 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    DupString(yy_conf->name, yylval.string);
}
    break;

  case 332:
/* Line 1813 of yacc.c  */
#line 1930 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = 0;
}
    break;

  case 336:
/* Line 1813 of yacc.c  */
#line 1937 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_KLINE;
}
    break;

  case 337:
/* Line 1813 of yacc.c  */
#line 1941 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNKLINE;
}
    break;

  case 338:
/* Line 1813 of yacc.c  */
#line 1945 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_DLINE;
}
    break;

  case 339:
/* Line 1813 of yacc.c  */
#line 1949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNDLINE;
}
    break;

  case 340:
/* Line 1813 of yacc.c  */
#line 1953 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_XLINE;
}
    break;

  case 341:
/* Line 1813 of yacc.c  */
#line 1957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNXLINE;
}
    break;

  case 342:
/* Line 1813 of yacc.c  */
#line 1961 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_RESV;
}
    break;

  case 343:
/* Line 1813 of yacc.c  */
#line 1965 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_UNRESV;
}
    break;

  case 344:
/* Line 1813 of yacc.c  */
#line 1969 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags |= SHARED_LOCOPS;
}
    break;

  case 345:
/* Line 1813 of yacc.c  */
#line 1973 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->flags = SHARED_ALL;
}
    break;

  case 346:
/* Line 1813 of yacc.c  */
#line 1982 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    yy_conf = conf_make(CONF_SERVER);

    /* defaults */
    yy_conf->port = PORTNUM;
  }
  else
  {
    MyFree(class_name);
    class_name = NULL;
  }
}
    break;

  case 347:
/* Line 1813 of yacc.c  */
#line 1996 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yy_conf->host && yy_conf->passwd && yy_conf->spasswd)
    {
      if (conf_add_server(yy_conf, class_name) == -1)
        conf_free(yy_conf);
    }
    else
    {
      if (yy_conf->name != NULL)
      {
        if (yy_conf->host == NULL)
          yyerror("Ignoring connect block -- missing host");
        else if (!yy_conf->passwd || !yy_conf->spasswd)
          yyerror("Ignoring connect block -- missing password");
      }

      /* XXX
       * This fixes a try_connections() core (caused by invalid class_ptr
       * pointers) reported by metalrock. That's an ugly fix, but there
       * is currently no better way. The entire config subsystem needs an
       * rewrite ASAP. make_conf_item() shouldn't really add things onto
       * a doubly linked list immediately without any sanity checks!  -Michael
       */
      conf_free(yy_conf);
    }

    MyFree(class_name);
    class_name = NULL;
    yy_conf = NULL;
  }
}
    break;

  case 364:
/* Line 1813 of yacc.c  */
#line 2039 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->name);
    DupString(yy_conf->name, yylval.string);
  }
}
    break;

  case 365:
/* Line 1813 of yacc.c  */
#line 2048 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->host);
    DupString(yy_conf->host, yylval.string);
  }
}
    break;

  case 366:
/* Line 1813 of yacc.c  */
#line 2057 "conf_parser.y"
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

      memcpy(&yy_conf->bind, res->ai_addr, res->ai_addrlen);
      yy_conf->bind.ss.ss_family = res->ai_family;
      yy_conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }
}
    break;

  case 367:
/* Line 1813 of yacc.c  */
#line 2083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_conf->spasswd != NULL)
        memset(yy_conf->spasswd, 0, strlen(yy_conf->spasswd));

      MyFree(yy_conf->spasswd);
      DupString(yy_conf->spasswd, yylval.string);
    }
  }
}
    break;

  case 368:
/* Line 1813 of yacc.c  */
#line 2101 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if ((yyvsp[(3) - (4)].string)[0] == ':')
      yyerror("Server passwords cannot begin with a colon");
    else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
      yyerror("Server passwords cannot contain spaces");
    else {
      if (yy_conf->passwd != NULL)
        memset(yy_conf->passwd, 0, strlen(yy_conf->passwd));

      MyFree(yy_conf->passwd);
      DupString(yy_conf->passwd, yylval.string);
    }
  }
}
    break;

  case 369:
/* Line 1813 of yacc.c  */
#line 2119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->port = (yyvsp[(3) - (4)].number);
}
    break;

  case 370:
/* Line 1813 of yacc.c  */
#line 2125 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    yy_conf->aftype = AF_INET;
}
    break;

  case 371:
/* Line 1813 of yacc.c  */
#line 2129 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    yy_conf->aftype = AF_INET6;
#endif
}
    break;

  case 372:
/* Line 1813 of yacc.c  */
#line 2137 "conf_parser.y"
    {
}
    break;

  case 376:
/* Line 1813 of yacc.c  */
#line 2142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfAllowAutoConn(yy_conf);
}
    break;

  case 377:
/* Line 1813 of yacc.c  */
#line 2146 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    SetConfSSL(yy_conf);
}
    break;

  case 378:
/* Line 1813 of yacc.c  */
#line 2152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      yy_conf->flags |= CONF_FLAGS_ENCRYPTED;
    else
      yy_conf->flags &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 379:
/* Line 1813 of yacc.c  */
#line 2163 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_conf->hub_list);
  }
}
    break;

  case 380:
/* Line 1813 of yacc.c  */
#line 2174 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *mask;

    DupString(mask, yylval.string);
    dlinkAdd(mask, make_dlink_node(), &yy_conf->leaf_list);
  }
}
    break;

  case 381:
/* Line 1813 of yacc.c  */
#line 2185 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(class_name);
    DupString(class_name, yylval.string);
  }
}
    break;

  case 382:
/* Line 1813 of yacc.c  */
#line 2194 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(yy_conf->cipher_list);
    DupString(yy_conf->cipher_list, yylval.string);
  }
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 383:
/* Line 1813 of yacc.c  */
#line 2212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    userbuf[0] = hostbuf[0] = reasonbuf[0] = '\0';
    regex_ban = 0;
  }
}
    break;

  case 384:
/* Line 1813 of yacc.c  */
#line 2219 "conf_parser.y"
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

        yy_conf = conf_make(CONF_RKLINE);
        yy_conf->regexuser = exp_user;
        yy_conf->regexhost = exp_host;

        DupString(yy_conf->user, userbuf);
        DupString(yy_conf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_conf->reason, reasonbuf);
        else
          DupString(yy_conf->reason, "No reason");
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
        break;
#endif
      }
      else
      {
        yy_conf = conf_make(CONF_KLINE);

        DupString(yy_conf->user, userbuf);
        DupString(yy_conf->host, hostbuf);

        if (reasonbuf[0])
          DupString(yy_conf->reason, reasonbuf);
        else
          DupString(yy_conf->reason, "No reason");
        add_conf_by_address(CONF_KLINE, yy_conf);
      }
    }

    yy_conf = NULL;
  }
}
    break;

  case 385:
/* Line 1813 of yacc.c  */
#line 2275 "conf_parser.y"
    {
}
    break;

  case 389:
/* Line 1813 of yacc.c  */
#line 2280 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 396:
/* Line 1813 of yacc.c  */
#line 2289 "conf_parser.y"
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

  case 397:
/* Line 1813 of yacc.c  */
#line 2308 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 398:
/* Line 1813 of yacc.c  */
#line 2317 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    hostbuf[0] = reasonbuf[0] = '\0';
}
    break;

  case 399:
/* Line 1813 of yacc.c  */
#line 2321 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (hostbuf[0] && parse_netmask(hostbuf, NULL, NULL) != HM_HOST)
    {
      yy_conf = conf_make(CONF_DLINE);
      DupString(yy_conf->host, hostbuf);

      if (reasonbuf[0])
        DupString(yy_conf->reason, reasonbuf);
      else
        DupString(yy_conf->reason, "No reason");
      add_conf_by_address(CONF_DLINE, yy_conf);
      yy_conf = NULL;
    }
  }
}
    break;

  case 405:
/* Line 1813 of yacc.c  */
#line 2343 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(hostbuf, yylval.string, sizeof(hostbuf));
}
    break;

  case 406:
/* Line 1813 of yacc.c  */
#line 2349 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 412:
/* Line 1813 of yacc.c  */
#line 2363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      yy_conf = conf_make(CONF_EXEMPT);
      DupString(yy_conf->host, yylval.string);

      add_conf_by_address(CONF_EXEMPT, yy_conf);
      yy_conf = NULL;
    }
  }
}
    break;

  case 413:
/* Line 1813 of yacc.c  */
#line 2381 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    regex_ban = 0;
    reasonbuf[0] = gecos_name[0] = '\0';
  }
}
    break;

  case 414:
/* Line 1813 of yacc.c  */
#line 2388 "conf_parser.y"
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

        yy_conf = conf_make(CONF_RXLINE);
        yy_conf->regexuser = exp_p;
#else
        ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: no PCRE support");
        break;
#endif
      }
      else
        yy_conf = conf_make(CONF_XLINE);

      DupString(yy_conf->name, gecos_name);

      if (reasonbuf[0])
        DupString(yy_conf->reason, reasonbuf);
      else
        DupString(yy_conf->reason, "No reason");
    }
  }
}
    break;

  case 415:
/* Line 1813 of yacc.c  */
#line 2427 "conf_parser.y"
    {
}
    break;

  case 419:
/* Line 1813 of yacc.c  */
#line 2432 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    regex_ban = 1;
}
    break;

  case 426:
/* Line 1813 of yacc.c  */
#line 2441 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(gecos_name, yylval.string, sizeof(gecos_name));
}
    break;

  case 427:
/* Line 1813 of yacc.c  */
#line 2447 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(reasonbuf, yylval.string, sizeof(reasonbuf));
}
    break;

  case 481:
/* Line 1813 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 482:
/* Line 1813 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 483:
/* Line 1813 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 484:
/* Line 1813 of yacc.c  */
#line 2509 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 485:
/* Line 1813 of yacc.c  */
#line 2515 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:
/* Line 1813 of yacc.c  */
#line 2520 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1813 of yacc.c  */
#line 2525 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 488:
/* Line 1813 of yacc.c  */
#line 2530 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1813 of yacc.c  */
#line 2535 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 490:
/* Line 1813 of yacc.c  */
#line 2540 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 491:
/* Line 1813 of yacc.c  */
#line 2545 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 492:
/* Line 1813 of yacc.c  */
#line 2550 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 493:
/* Line 1813 of yacc.c  */
#line 2555 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 494:
/* Line 1813 of yacc.c  */
#line 2560 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 495:
/* Line 1813 of yacc.c  */
#line 2565 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 496:
/* Line 1813 of yacc.c  */
#line 2570 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:
/* Line 1813 of yacc.c  */
#line 2575 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1813 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1813 of yacc.c  */
#line 2585 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:
/* Line 1813 of yacc.c  */
#line 2591 "conf_parser.y"
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

  case 501:
/* Line 1813 of yacc.c  */
#line 2602 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 502:
/* Line 1813 of yacc.c  */
#line 2607 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 503:
/* Line 1813 of yacc.c  */
#line 2612 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 504:
/* Line 1813 of yacc.c  */
#line 2617 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 505:
/* Line 1813 of yacc.c  */
#line 2622 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 506:
/* Line 1813 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 507:
/* Line 1813 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 508:
/* Line 1813 of yacc.c  */
#line 2635 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 509:
/* Line 1813 of yacc.c  */
#line 2638 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 510:
/* Line 1813 of yacc.c  */
#line 2643 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 511:
/* Line 1813 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1813 of yacc.c  */
#line 2653 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 513:
/* Line 1813 of yacc.c  */
#line 2658 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 514:
/* Line 1813 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 515:
/* Line 1813 of yacc.c  */
#line 2668 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 516:
/* Line 1813 of yacc.c  */
#line 2673 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 517:
/* Line 1813 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 518:
/* Line 1813 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 519:
/* Line 1813 of yacc.c  */
#line 2694 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 520:
/* Line 1813 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1813 of yacc.c  */
#line 2704 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 522:
/* Line 1813 of yacc.c  */
#line 2709 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    DupString(ConfigFileEntry.egdpool_path, yylval.string);
  }
}
    break;

  case 523:
/* Line 1813 of yacc.c  */
#line 2718 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    DupString(ConfigFileEntry.service_name, yylval.string);
  }
}
    break;

  case 524:
/* Line 1813 of yacc.c  */
#line 2727 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 525:
/* Line 1813 of yacc.c  */
#line 2732 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 526:
/* Line 1813 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 527:
/* Line 1813 of yacc.c  */
#line 2742 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 531:
/* Line 1813 of yacc.c  */
#line 2748 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 532:
/* Line 1813 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 533:
/* Line 1813 of yacc.c  */
#line 2754 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 534:
/* Line 1813 of yacc.c  */
#line 2757 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 535:
/* Line 1813 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 536:
/* Line 1813 of yacc.c  */
#line 2763 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 537:
/* Line 1813 of yacc.c  */
#line 2766 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 538:
/* Line 1813 of yacc.c  */
#line 2769 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 539:
/* Line 1813 of yacc.c  */
#line 2772 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 540:
/* Line 1813 of yacc.c  */
#line 2775 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 541:
/* Line 1813 of yacc.c  */
#line 2778 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 542:
/* Line 1813 of yacc.c  */
#line 2781 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 543:
/* Line 1813 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 544:
/* Line 1813 of yacc.c  */
#line 2787 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 545:
/* Line 1813 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 546:
/* Line 1813 of yacc.c  */
#line 2793 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 547:
/* Line 1813 of yacc.c  */
#line 2796 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 548:
/* Line 1813 of yacc.c  */
#line 2799 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 549:
/* Line 1813 of yacc.c  */
#line 2802 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 550:
/* Line 1813 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 551:
/* Line 1813 of yacc.c  */
#line 2810 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 555:
/* Line 1813 of yacc.c  */
#line 2816 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 556:
/* Line 1813 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 557:
/* Line 1813 of yacc.c  */
#line 2822 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 558:
/* Line 1813 of yacc.c  */
#line 2825 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 559:
/* Line 1813 of yacc.c  */
#line 2828 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 560:
/* Line 1813 of yacc.c  */
#line 2831 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 561:
/* Line 1813 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 562:
/* Line 1813 of yacc.c  */
#line 2837 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 563:
/* Line 1813 of yacc.c  */
#line 2840 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 564:
/* Line 1813 of yacc.c  */
#line 2843 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 565:
/* Line 1813 of yacc.c  */
#line 2846 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 566:
/* Line 1813 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 567:
/* Line 1813 of yacc.c  */
#line 2852 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 568:
/* Line 1813 of yacc.c  */
#line 2855 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 569:
/* Line 1813 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 570:
/* Line 1813 of yacc.c  */
#line 2861 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 571:
/* Line 1813 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 572:
/* Line 1813 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 573:
/* Line 1813 of yacc.c  */
#line 2870 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 574:
/* Line 1813 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 575:
/* Line 1813 of yacc.c  */
#line 2878 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 576:
/* Line 1813 of yacc.c  */
#line 2883 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 577:
/* Line 1813 of yacc.c  */
#line 2888 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 596:
/* Line 1813 of yacc.c  */
#line 2911 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 597:
/* Line 1813 of yacc.c  */
#line 2916 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 598:
/* Line 1813 of yacc.c  */
#line 2921 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 599:
/* Line 1813 of yacc.c  */
#line 2926 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:
/* Line 1813 of yacc.c  */
#line 2931 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1813 of yacc.c  */
#line 2936 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1813 of yacc.c  */
#line 2941 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 603:
/* Line 1813 of yacc.c  */
#line 2946 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1813 of yacc.c  */
#line 2951 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1813 of yacc.c  */
#line 2956 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1813 of yacc.c  */
#line 2961 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 607:
/* Line 1813 of yacc.c  */
#line 2966 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 608:
/* Line 1813 of yacc.c  */
#line 2971 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 609:
/* Line 1813 of yacc.c  */
#line 2976 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 620:
/* Line 1813 of yacc.c  */
#line 2994 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 621:
/* Line 1813 of yacc.c  */
#line 3000 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 622:
/* Line 1813 of yacc.c  */
#line 3006 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    DupString(ConfigServerHide.hidden_name, yylval.string);
  }
}
    break;

  case 623:
/* Line 1813 of yacc.c  */
#line 3015 "conf_parser.y"
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

  case 624:
/* Line 1813 of yacc.c  */
#line 3029 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 625:
/* Line 1813 of yacc.c  */
#line 3035 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1813 of yacc.c  */
#line 6815 "conf_parser.c"
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


