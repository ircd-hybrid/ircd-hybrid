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

static struct
{
  struct {
    dlink_list list;
  } mask,
    leaf,
    hub;

  struct {
    char buf[IRCD_BUFSIZE];
  } name,
    user,
    host,
    addr,
    bind,
    file,
    ciph,
    rpass,
    spass,
    class;

  struct {
    unsigned int value;
  } flags,
    modes,
    size,
    type,
    port,
    aftype,
    ping_freq,
    max_perip,
    con_freq,
    max_total,
    max_global,
    max_local,
    max_ident,
    max_sendq,
    max_recvq,
    cidr_bitlen_ipv4,
    cidr_bitlen_ipv6,
    number_per_cidr;
} block_state;

static void
reset_block_state(void)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.mask.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.mask.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.leaf.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.leaf.list);
    free_dlink_node(ptr);
  }

  DLINK_FOREACH_SAFE(ptr, ptr_next, block_state.hub.list.head)
  {
    MyFree(ptr->data);
    dlinkDelete(ptr, &block_state.hub.list);
    free_dlink_node(ptr);
  }

  memset(&block_state, 0, sizeof(block_state));
}


/* Line 371 of yacc.c  */
#line 178 "conf_parser.c"

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
     PORT = 373,
     QSTRING = 374,
     QUIET_ON_BAN = 375,
     REASON = 376,
     REDIRPORT = 377,
     REDIRSERV = 378,
     REGEX_T = 379,
     REHASH = 380,
     REMOTE = 381,
     REMOTEBAN = 382,
     RESTRICT_CHANNELS = 383,
     RSA_PRIVATE_KEY_FILE = 384,
     RSA_PUBLIC_KEY_FILE = 385,
     SSL_CERTIFICATE_FILE = 386,
     SSL_DH_PARAM_FILE = 387,
     T_SSL_CLIENT_METHOD = 388,
     T_SSL_SERVER_METHOD = 389,
     T_SSLV3 = 390,
     T_TLSV1 = 391,
     RESV = 392,
     RESV_EXEMPT = 393,
     SECONDS = 394,
     MINUTES = 395,
     HOURS = 396,
     DAYS = 397,
     WEEKS = 398,
     SENDQ = 399,
     SEND_PASSWORD = 400,
     SERVERHIDE = 401,
     SERVERINFO = 402,
     IRCD_SID = 403,
     TKLINE_EXPIRE_NOTICES = 404,
     T_SHARED = 405,
     T_CLUSTER = 406,
     TYPE = 407,
     SHORT_MOTD = 408,
     SPOOF = 409,
     SPOOF_NOTICE = 410,
     STATS_E_DISABLED = 411,
     STATS_I_OPER_ONLY = 412,
     STATS_K_OPER_ONLY = 413,
     STATS_O_OPER_ONLY = 414,
     STATS_P_OPER_ONLY = 415,
     TBOOL = 416,
     TMASKED = 417,
     TS_MAX_DELTA = 418,
     TS_WARN_DELTA = 419,
     TWODOTS = 420,
     T_ALL = 421,
     T_BOTS = 422,
     T_SOFTCALLERID = 423,
     T_CALLERID = 424,
     T_CCONN = 425,
     T_CCONN_FULL = 426,
     T_SSL_CIPHER_LIST = 427,
     T_DEAF = 428,
     T_DEBUG = 429,
     T_DLINE = 430,
     T_EXTERNAL = 431,
     T_FULL = 432,
     T_INVISIBLE = 433,
     T_IPV4 = 434,
     T_IPV6 = 435,
     T_LOCOPS = 436,
     T_MAX_CLIENTS = 437,
     T_NCHANGE = 438,
     T_OPERWALL = 439,
     T_RECVQ = 440,
     T_REJ = 441,
     T_SERVER = 442,
     T_SERVNOTICE = 443,
     T_SET = 444,
     T_SKILL = 445,
     T_SPY = 446,
     T_SSL = 447,
     T_UMODES = 448,
     T_UNAUTH = 449,
     T_UNDLINE = 450,
     T_UNLIMITED = 451,
     T_UNRESV = 452,
     T_UNXLINE = 453,
     T_GLOBOPS = 454,
     T_WALLOP = 455,
     T_WEBIRC = 456,
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
#define PORT 373
#define QSTRING 374
#define QUIET_ON_BAN 375
#define REASON 376
#define REDIRPORT 377
#define REDIRSERV 378
#define REGEX_T 379
#define REHASH 380
#define REMOTE 381
#define REMOTEBAN 382
#define RESTRICT_CHANNELS 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SSL_CERTIFICATE_FILE 386
#define SSL_DH_PARAM_FILE 387
#define T_SSL_CLIENT_METHOD 388
#define T_SSL_SERVER_METHOD 389
#define T_SSLV3 390
#define T_TLSV1 391
#define RESV 392
#define RESV_EXEMPT 393
#define SECONDS 394
#define MINUTES 395
#define HOURS 396
#define DAYS 397
#define WEEKS 398
#define SENDQ 399
#define SEND_PASSWORD 400
#define SERVERHIDE 401
#define SERVERINFO 402
#define IRCD_SID 403
#define TKLINE_EXPIRE_NOTICES 404
#define T_SHARED 405
#define T_CLUSTER 406
#define TYPE 407
#define SHORT_MOTD 408
#define SPOOF 409
#define SPOOF_NOTICE 410
#define STATS_E_DISABLED 411
#define STATS_I_OPER_ONLY 412
#define STATS_K_OPER_ONLY 413
#define STATS_O_OPER_ONLY 414
#define STATS_P_OPER_ONLY 415
#define TBOOL 416
#define TMASKED 417
#define TS_MAX_DELTA 418
#define TS_WARN_DELTA 419
#define TWODOTS 420
#define T_ALL 421
#define T_BOTS 422
#define T_SOFTCALLERID 423
#define T_CALLERID 424
#define T_CCONN 425
#define T_CCONN_FULL 426
#define T_SSL_CIPHER_LIST 427
#define T_DEAF 428
#define T_DEBUG 429
#define T_DLINE 430
#define T_EXTERNAL 431
#define T_FULL 432
#define T_INVISIBLE 433
#define T_IPV4 434
#define T_IPV6 435
#define T_LOCOPS 436
#define T_MAX_CLIENTS 437
#define T_NCHANGE 438
#define T_OPERWALL 439
#define T_RECVQ 440
#define T_REJ 441
#define T_SERVER 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SKILL 445
#define T_SPY 446
#define T_SSL 447
#define T_UMODES 448
#define T_UNAUTH 449
#define T_UNDLINE 450
#define T_UNLIMITED 451
#define T_UNRESV 452
#define T_UNXLINE 453
#define T_GLOBOPS 454
#define T_WALLOP 455
#define T_WEBIRC 456
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
#line 135 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 659 "conf_parser.c"
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
#line 687 "conf_parser.c"

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
#define YYLAST   1186

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  222
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  284
/* YYNRULES -- Number of rules.  */
#define YYNRULES  630
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1234

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
     593,   595,   597,   599,   601,   603,   605,   608,   613,   618,
     623,   628,   633,   638,   643,   648,   653,   658,   663,   668,
     673,   674,   681,   682,   688,   692,   694,   696,   698,   700,
     703,   705,   707,   709,   711,   713,   716,   717,   723,   727,
     729,   731,   735,   740,   745,   746,   753,   756,   758,   760,
     762,   764,   766,   768,   770,   772,   774,   777,   782,   787,
     792,   797,   798,   804,   808,   810,   812,   814,   816,   818,
     820,   822,   824,   826,   828,   830,   835,   840,   845,   846,
     853,   856,   858,   860,   862,   864,   867,   872,   877,   882,
     888,   891,   893,   895,   897,   902,   903,   910,   913,   915,
     917,   919,   921,   924,   929,   934,   935,   941,   945,   947,
     949,   951,   953,   955,   957,   959,   961,   963,   965,   967,
     968,   975,   978,   980,   982,   984,   987,   992,   993,   999,
    1003,  1005,  1007,  1009,  1011,  1013,  1015,  1017,  1019,  1021,
    1023,  1025,  1026,  1033,  1036,  1038,  1040,  1042,  1044,  1046,
    1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,  1064,  1067,
    1072,  1077,  1082,  1087,  1092,  1097,  1102,  1107,  1108,  1114,
    1118,  1120,  1122,  1124,  1129,  1134,  1139,  1144,  1149,  1150,
    1157,  1158,  1164,  1168,  1170,  1172,  1175,  1177,  1179,  1181,
    1183,  1185,  1190,  1195,  1196,  1203,  1206,  1208,  1210,  1212,
    1214,  1219,  1224,  1230,  1233,  1235,  1237,  1239,  1244,  1245,
    1252,  1253,  1259,  1263,  1265,  1267,  1270,  1272,  1274,  1276,
    1278,  1280,  1285,  1290,  1296,  1299,  1301,  1303,  1305,  1307,
    1309,  1311,  1313,  1315,  1317,  1319,  1321,  1323,  1325,  1327,
    1329,  1331,  1333,  1335,  1337,  1339,  1341,  1343,  1345,  1347,
    1349,  1351,  1353,  1355,  1357,  1359,  1361,  1363,  1365,  1367,
    1369,  1371,  1373,  1375,  1377,  1379,  1381,  1383,  1385,  1387,
    1389,  1391,  1393,  1395,  1397,  1399,  1401,  1406,  1411,  1416,
    1421,  1426,  1431,  1436,  1441,  1446,  1451,  1456,  1461,  1466,
    1471,  1476,  1481,  1486,  1491,  1496,  1501,  1506,  1511,  1516,
    1521,  1526,  1531,  1536,  1541,  1546,  1551,  1556,  1561,  1566,
    1571,  1576,  1581,  1586,  1591,  1596,  1601,  1606,  1611,  1616,
    1621,  1626,  1631,  1632,  1638,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1666,  1668,  1670,
    1672,  1674,  1676,  1678,  1680,  1682,  1684,  1685,  1691,  1695,
    1697,  1699,  1701,  1703,  1705,  1707,  1709,  1711,  1713,  1715,
    1717,  1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,
    1737,  1742,  1747,  1752,  1758,  1761,  1763,  1765,  1767,  1769,
    1771,  1773,  1775,  1777,  1779,  1781,  1783,  1785,  1787,  1789,
    1791,  1793,  1798,  1803,  1808,  1813,  1818,  1823,  1828,  1833,
    1838,  1843,  1848,  1853,  1858,  1863,  1869,  1872,  1874,  1876,
    1878,  1880,  1882,  1884,  1886,  1888,  1893,  1898,  1903,  1908,
    1913
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     223,     0,    -1,    -1,   223,   224,    -1,   258,    -1,   264,
      -1,   278,    -1,   480,    -1,   296,    -1,   313,    -1,   327,
      -1,   234,    -1,   497,    -1,   342,    -1,   349,    -1,   353,
      -1,   363,    -1,   372,    -1,   392,    -1,   402,    -1,   408,
      -1,   422,    -1,   412,    -1,   229,    -1,     1,   217,    -1,
       1,   218,    -1,    -1,   226,    -1,   101,   225,    -1,   101,
     139,   225,    -1,   101,   140,   225,    -1,   101,   141,   225,
      -1,   101,   142,   225,    -1,   101,   143,   225,    -1,    -1,
     228,    -1,   101,   227,    -1,   101,     9,   227,    -1,   101,
      10,   227,    -1,   101,    11,   227,    -1,    90,   219,   230,
     218,   217,    -1,   230,   231,    -1,   231,    -1,   232,    -1,
     233,    -1,     1,   217,    -1,    89,   220,   119,   217,    -1,
     115,   220,   119,   217,    -1,   147,   219,   235,   218,   217,
      -1,   235,   236,    -1,   236,    -1,   247,    -1,   252,    -1,
     257,    -1,   249,    -1,   250,    -1,   251,    -1,   254,    -1,
     255,    -1,   256,    -1,   245,    -1,   244,    -1,   253,    -1,
     248,    -1,   243,    -1,   237,    -1,   238,    -1,   246,    -1,
       1,   217,    -1,   133,   220,   239,   217,    -1,   134,   220,
     241,   217,    -1,   239,   221,   240,    -1,   240,    -1,   135,
      -1,   136,    -1,   241,   221,   242,    -1,   242,    -1,   135,
      -1,   136,    -1,   131,   220,   119,   217,    -1,   129,   220,
     119,   217,    -1,   132,   220,   119,   217,    -1,   172,   220,
     119,   217,    -1,    91,   220,   119,   217,    -1,   148,   220,
     119,   217,    -1,    24,   220,   119,   217,    -1,    94,   220,
     119,   217,    -1,    93,   220,   119,   217,    -1,   211,   220,
     119,   217,    -1,   212,   220,   119,   217,    -1,   182,   220,
     101,   217,    -1,    80,   220,   101,   217,    -1,    84,   220,
     101,   217,    -1,    57,   220,   161,   217,    -1,     4,   219,
     259,   218,   217,    -1,   259,   260,    -1,   260,    -1,   261,
      -1,   263,    -1,   262,    -1,     1,   217,    -1,    91,   220,
     119,   217,    -1,    31,   220,   119,   217,    -1,    24,   220,
     119,   217,    -1,    71,   219,   265,   218,   217,    -1,   265,
     266,    -1,   266,    -1,   267,    -1,   268,    -1,     1,   217,
      -1,   210,   220,   161,   217,    -1,    -1,   269,   216,   219,
     270,   218,   217,    -1,   270,   271,    -1,   271,    -1,   272,
      -1,   274,    -1,   273,    -1,     1,   217,    -1,    91,   220,
     119,   217,    -1,   215,   220,   228,   217,    -1,   215,   220,
     196,   217,    -1,    -1,   152,   275,   220,   276,   217,    -1,
     276,   221,   277,    -1,   277,    -1,   208,    -1,   104,    -1,
      40,    -1,   175,    -1,    64,    -1,    62,    -1,   174,    -1,
      -1,   104,   279,   219,   280,   218,   217,    -1,   280,   281,
      -1,   281,    -1,   282,    -1,   283,    -1,   284,    -1,   288,
      -1,   287,    -1,   285,    -1,   286,    -1,   292,    -1,     1,
     217,    -1,    91,   220,   119,   217,    -1,   208,   220,   119,
     217,    -1,   114,   220,   119,   217,    -1,    32,   220,   161,
     217,    -1,   130,   220,   119,   217,    -1,    17,   220,   119,
     217,    -1,    -1,   193,   289,   220,   290,   217,    -1,   290,
     221,   291,    -1,   291,    -1,   167,    -1,   170,    -1,   171,
      -1,   173,    -1,   174,    -1,   177,    -1,    51,    -1,   190,
      -1,   183,    -1,   186,    -1,   194,    -1,   191,    -1,   176,
      -1,   184,    -1,   188,    -1,   178,    -1,   200,    -1,   168,
      -1,   169,    -1,   181,    -1,    -1,    36,   293,   220,   294,
     217,    -1,   294,   221,   295,    -1,   295,    -1,    47,    -1,
     126,    -1,    64,    -1,   207,    -1,   175,    -1,   195,    -1,
     213,    -1,    40,    -1,    25,    -1,   202,    -1,   125,    -1,
       4,    -1,    96,    -1,   184,    -1,   199,    -1,   108,    -1,
     127,    -1,   189,    -1,    89,    -1,    -1,    17,   297,   219,
     298,   218,   217,    -1,   298,   299,    -1,   299,    -1,   300,
      -1,   310,    -1,   311,    -1,   301,    -1,   312,    -1,   302,
      -1,   303,    -1,   304,    -1,   305,    -1,   306,    -1,   307,
      -1,   308,    -1,   309,    -1,     1,   217,    -1,    91,   220,
     119,   217,    -1,   117,   220,   226,   217,    -1,   103,   220,
     101,   217,    -1,    19,   220,   226,   217,    -1,    82,   220,
     101,   217,    -1,    76,   220,   101,   217,    -1,    78,   220,
     101,   217,    -1,    77,   220,   101,   217,    -1,   144,   220,
     228,   217,    -1,   185,   220,   228,   217,    -1,    15,   220,
     101,   217,    -1,    16,   220,   101,   217,    -1,   102,   220,
     101,   217,    -1,    -1,    70,   314,   219,   319,   218,   217,
      -1,    -1,    36,   316,   220,   317,   217,    -1,   317,   221,
     318,    -1,   318,    -1,   192,    -1,    51,    -1,   187,    -1,
     319,   320,    -1,   320,    -1,   321,    -1,   315,    -1,   325,
      -1,   326,    -1,     1,   217,    -1,    -1,   118,   220,   323,
     322,   217,    -1,   323,   221,   324,    -1,   324,    -1,   101,
      -1,   101,   165,   101,    -1,    61,   220,   119,   217,    -1,
      56,   220,   119,   217,    -1,    -1,    48,   328,   219,   329,
     218,   217,    -1,   329,   330,    -1,   330,    -1,   331,    -1,
     332,    -1,   333,    -1,   335,    -1,   339,    -1,   340,    -1,
     341,    -1,   334,    -1,     1,   217,    -1,   208,   220,   119,
     217,    -1,   114,   220,   119,   217,    -1,    17,   220,   119,
     217,    -1,    32,   220,   161,   217,    -1,    -1,    36,   336,
     220,   337,   217,    -1,   337,   221,   338,    -1,   338,    -1,
     155,    -1,    33,    -1,    65,    -1,    49,    -1,    13,    -1,
     100,    -1,    43,    -1,   138,    -1,   201,    -1,    92,    -1,
     154,   220,   119,   217,    -1,   123,   220,   119,   217,    -1,
     122,   220,   101,   217,    -1,    -1,   137,   343,   219,   344,
     218,   217,    -1,   344,   345,    -1,   345,    -1,   346,    -1,
     347,    -1,   348,    -1,     1,   217,    -1,   121,   220,   119,
     217,    -1,    14,   220,   119,   217,    -1,    95,   220,   119,
     217,    -1,   203,   219,   350,   218,   217,    -1,   350,   351,
      -1,   351,    -1,   352,    -1,     1,    -1,    91,   220,   119,
     217,    -1,    -1,   150,   354,   219,   355,   218,   217,    -1,
     355,   356,    -1,   356,    -1,   357,    -1,   358,    -1,   359,
      -1,     1,   217,    -1,    91,   220,   119,   217,    -1,   208,
     220,   119,   217,    -1,    -1,   152,   360,   220,   361,   217,
      -1,   361,   221,   362,    -1,   362,    -1,    64,    -1,   207,
      -1,   175,    -1,   195,    -1,   213,    -1,   198,    -1,   137,
      -1,   197,    -1,   181,    -1,   166,    -1,    -1,   151,   364,
     219,   365,   218,   217,    -1,   365,   366,    -1,   366,    -1,
     367,    -1,   368,    -1,     1,   217,    -1,    91,   220,   119,
     217,    -1,    -1,   152,   369,   220,   370,   217,    -1,   370,
     221,   371,    -1,   371,    -1,    64,    -1,   207,    -1,   175,
      -1,   195,    -1,   213,    -1,   198,    -1,   137,    -1,   197,
      -1,   181,    -1,   166,    -1,    -1,    18,   373,   219,   374,
     218,   217,    -1,   374,   375,    -1,   375,    -1,   376,    -1,
     377,    -1,   378,    -1,   379,    -1,   380,    -1,   382,    -1,
     381,    -1,   391,    -1,   383,    -1,   388,    -1,   389,    -1,
     390,    -1,   387,    -1,     1,   217,    -1,    91,   220,   119,
     217,    -1,    56,   220,   119,   217,    -1,   211,   220,   119,
     217,    -1,   145,   220,   119,   217,    -1,     3,   220,   119,
     217,    -1,   118,   220,   101,   217,    -1,     5,   220,   179,
     217,    -1,     5,   220,   180,   217,    -1,    -1,    36,   384,
     220,   385,   217,    -1,   385,   221,   386,    -1,   386,    -1,
       8,    -1,   192,    -1,    32,   220,   161,   217,    -1,    58,
     220,   119,   217,    -1,    68,   220,   119,   217,    -1,    17,
     220,   119,   217,    -1,   172,   220,   119,   217,    -1,    -1,
      62,   393,   219,   398,   218,   217,    -1,    -1,   152,   395,
     220,   396,   217,    -1,   396,   221,   397,    -1,   397,    -1,
     124,    -1,   398,   399,    -1,   399,    -1,   400,    -1,   401,
      -1,   394,    -1,     1,    -1,   208,   220,   119,   217,    -1,
     121,   220,   119,   217,    -1,    -1,    23,   403,   219,   404,
     218,   217,    -1,   404,   405,    -1,   405,    -1,   406,    -1,
     407,    -1,     1,    -1,    61,   220,   119,   217,    -1,   121,
     220,   119,   217,    -1,    34,   219,   409,   218,   217,    -1,
     409,   410,    -1,   410,    -1,   411,    -1,     1,    -1,    61,
     220,   119,   217,    -1,    -1,    38,   413,   219,   418,   218,
     217,    -1,    -1,   152,   415,   220,   416,   217,    -1,   416,
     221,   417,    -1,   417,    -1,   124,    -1,   418,   419,    -1,
     419,    -1,   420,    -1,   421,    -1,   414,    -1,     1,    -1,
      91,   220,   119,   217,    -1,   121,   220,   119,   217,    -1,
      39,   219,   423,   218,   217,    -1,   423,   424,    -1,   424,
      -1,   433,    -1,   434,    -1,   436,    -1,   437,    -1,   438,
      -1,   439,    -1,   440,    -1,   441,    -1,   442,    -1,   443,
      -1,   432,    -1,   445,    -1,   446,    -1,   461,    -1,   448,
      -1,   450,    -1,   452,    -1,   451,    -1,   455,    -1,   449,
      -1,   456,    -1,   457,    -1,   458,    -1,   459,    -1,   460,
      -1,   473,    -1,   462,    -1,   463,    -1,   464,    -1,   469,
      -1,   453,    -1,   454,    -1,   479,    -1,   477,    -1,   478,
      -1,   435,    -1,   468,    -1,   444,    -1,   466,    -1,   467,
      -1,   431,    -1,   426,    -1,   427,    -1,   428,    -1,   429,
      -1,   430,    -1,   447,    -1,   425,    -1,   465,    -1,     1,
      -1,    85,   220,   101,   217,    -1,    42,   220,   161,   217,
      -1,    41,   220,   226,   217,    -1,    44,   220,   226,   217,
      -1,    45,   220,   101,   217,    -1,    46,   220,   101,   217,
      -1,   149,   220,   161,   217,    -1,    63,   220,   226,   217,
      -1,    55,   220,   161,   217,    -1,    59,   220,   161,   217,
      -1,    28,   220,   161,   217,    -1,    35,   220,   161,   217,
      -1,     6,   220,   161,   217,    -1,    81,   220,   226,   217,
      -1,    79,   220,   101,   217,    -1,    72,   220,   101,   217,
      -1,     7,   220,   226,   217,    -1,   164,   220,   226,   217,
      -1,   163,   220,   226,   217,    -1,    50,   220,   101,   217,
      -1,    60,   220,   161,   217,    -1,   214,   220,   161,   217,
      -1,   156,   220,   161,   217,    -1,   159,   220,   161,   217,
      -1,   160,   220,   161,   217,    -1,   158,   220,   161,   217,
      -1,   158,   220,   162,   217,    -1,   157,   220,   161,   217,
      -1,   157,   220,   162,   217,    -1,   112,   220,   226,   217,
      -1,    12,   220,   226,   217,    -1,   105,   220,   161,   217,
      -1,   113,   220,   226,   217,    -1,   153,   220,   161,   217,
      -1,    99,   220,   161,   217,    -1,   206,   220,   161,   217,
      -1,   107,   220,   161,   217,    -1,    86,   220,   119,   217,
      -1,    29,   220,   101,   217,    -1,    83,   220,   101,   217,
      -1,   209,   220,   161,   217,    -1,    30,   220,   119,   217,
      -1,   204,   220,   119,   217,    -1,   116,   220,   161,   217,
      -1,    26,   220,   161,   217,    -1,   205,   220,   226,   217,
      -1,    -1,   109,   470,   220,   471,   217,    -1,   471,   221,
     472,    -1,   472,    -1,   167,    -1,   170,    -1,   171,    -1,
     173,    -1,   174,    -1,   177,    -1,    51,    -1,   190,    -1,
     183,    -1,   186,    -1,   194,    -1,   191,    -1,   176,    -1,
     184,    -1,   188,    -1,   178,    -1,   200,    -1,   168,    -1,
     169,    -1,   181,    -1,    -1,   106,   474,   220,   475,   217,
      -1,   475,   221,   476,    -1,   476,    -1,   167,    -1,   170,
      -1,   171,    -1,   173,    -1,   174,    -1,   177,    -1,   190,
      -1,    51,    -1,   183,    -1,   186,    -1,   194,    -1,   191,
      -1,   176,    -1,   184,    -1,   188,    -1,   178,    -1,   200,
      -1,   168,    -1,   169,    -1,   181,    -1,    87,   220,   101,
     217,    -1,    88,   220,   101,   217,    -1,    20,   220,   101,
     217,    -1,    14,   219,   481,   218,   217,    -1,   481,   482,
      -1,   482,    -1,   490,    -1,   485,    -1,   486,    -1,   487,
      -1,   488,    -1,   489,    -1,   491,    -1,   492,    -1,   493,
      -1,   484,    -1,   494,    -1,   495,    -1,   496,    -1,   483,
      -1,     1,    -1,    27,   220,   161,   217,    -1,   128,   220,
     161,   217,    -1,    66,   220,   226,   217,    -1,    67,   220,
     226,   217,    -1,    75,   220,   101,   217,    -1,    74,   220,
     101,   217,    -1,   120,   220,   161,   217,    -1,    73,   220,
     101,   217,    -1,    22,   220,   101,   217,    -1,    21,   220,
     101,   217,    -1,    97,   220,   161,   217,    -1,    98,   220,
     161,   217,    -1,   110,   220,   101,   217,    -1,   111,   220,
     226,   217,    -1,   146,   219,   498,   218,   217,    -1,   498,
     499,    -1,   499,    -1,   500,    -1,   501,    -1,   503,    -1,
     504,    -1,   502,    -1,   505,    -1,     1,    -1,    37,   220,
     161,   217,    -1,    54,   220,   161,   217,    -1,    52,   220,
     119,   217,    -1,    69,   220,   226,   217,    -1,    51,   220,
     161,   217,    -1,    53,   220,   161,   217,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   357,   357,   358,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   375,   376,
     377,   378,   379,   380,   381,   382,   386,   386,   387,   391,
     395,   399,   403,   407,   413,   413,   414,   415,   416,   417,
     424,   427,   427,   428,   428,   428,   430,   436,   443,   445,
     445,   446,   446,   447,   447,   448,   448,   449,   449,   450,
     450,   451,   451,   452,   452,   453,   453,   454,   455,   458,
     459,   461,   461,   462,   468,   476,   476,   477,   483,   491,
     530,   589,   617,   625,   640,   655,   664,   678,   687,   715,
     745,   770,   792,   814,   823,   825,   825,   826,   826,   827,
     827,   829,   838,   847,   859,   860,   860,   862,   862,   863,
     865,   872,   872,   885,   886,   888,   888,   889,   889,   891,
     899,   902,   908,   907,   913,   913,   914,   918,   922,   926,
     930,   934,   938,   949,   948,  1025,  1025,  1026,  1026,  1026,
    1027,  1027,  1027,  1028,  1028,  1028,  1030,  1036,  1042,  1048,
    1059,  1065,  1072,  1071,  1077,  1077,  1078,  1082,  1086,  1090,
    1094,  1098,  1102,  1106,  1110,  1114,  1118,  1122,  1126,  1130,
    1134,  1138,  1142,  1146,  1150,  1154,  1161,  1160,  1166,  1166,
    1167,  1171,  1175,  1179,  1183,  1187,  1191,  1195,  1199,  1203,
    1207,  1211,  1215,  1219,  1223,  1227,  1231,  1235,  1239,  1250,
    1249,  1300,  1300,  1301,  1302,  1302,  1303,  1304,  1305,  1306,
    1307,  1308,  1309,  1310,  1311,  1311,  1312,  1314,  1320,  1326,
    1332,  1338,  1344,  1350,  1356,  1362,  1368,  1375,  1381,  1387,
    1397,  1396,  1403,  1402,  1407,  1407,  1408,  1412,  1416,  1422,
    1422,  1423,  1423,  1423,  1423,  1423,  1425,  1425,  1427,  1427,
    1429,  1443,  1463,  1469,  1479,  1478,  1520,  1520,  1521,  1521,
    1521,  1521,  1522,  1522,  1522,  1523,  1523,  1525,  1531,  1537,
    1543,  1555,  1554,  1560,  1560,  1561,  1565,  1569,  1573,  1577,
    1581,  1585,  1589,  1593,  1597,  1603,  1617,  1626,  1640,  1639,
    1648,  1648,  1649,  1649,  1649,  1649,  1651,  1657,  1666,  1675,
    1677,  1677,  1678,  1678,  1680,  1696,  1695,  1720,  1720,  1721,
    1721,  1721,  1721,  1723,  1729,  1749,  1748,  1754,  1754,  1755,
    1759,  1763,  1767,  1771,  1775,  1779,  1783,  1787,  1791,  1801,
    1800,  1821,  1821,  1822,  1822,  1822,  1824,  1831,  1830,  1836,
    1836,  1837,  1841,  1845,  1849,  1853,  1857,  1861,  1865,  1869,
    1873,  1883,  1882,  1948,  1948,  1949,  1949,  1949,  1950,  1950,
    1951,  1951,  1951,  1952,  1952,  1952,  1953,  1953,  1954,  1956,
    1962,  1968,  1974,  1987,  2000,  2006,  2010,  2019,  2018,  2023,
    2023,  2024,  2028,  2034,  2045,  2051,  2057,  2063,  2079,  2078,
    2141,  2140,  2146,  2146,  2147,  2153,  2153,  2154,  2154,  2154,
    2154,  2156,  2176,  2186,  2185,  2212,  2212,  2213,  2213,  2213,
    2215,  2221,  2230,  2232,  2232,  2233,  2233,  2235,  2253,  2252,
    2298,  2297,  2303,  2303,  2304,  2310,  2310,  2311,  2311,  2311,
    2311,  2313,  2319,  2328,  2331,  2331,  2332,  2332,  2333,  2333,
    2334,  2334,  2335,  2335,  2336,  2336,  2337,  2338,  2339,  2339,
    2340,  2340,  2341,  2341,  2342,  2342,  2343,  2343,  2344,  2344,
    2345,  2346,  2346,  2347,  2347,  2348,  2348,  2349,  2349,  2350,
    2350,  2351,  2352,  2352,  2353,  2354,  2355,  2355,  2356,  2356,
    2357,  2358,  2359,  2360,  2360,  2361,  2364,  2369,  2375,  2381,
    2387,  2392,  2397,  2402,  2407,  2412,  2417,  2422,  2427,  2432,
    2437,  2442,  2447,  2452,  2457,  2463,  2474,  2479,  2484,  2489,
    2494,  2499,  2502,  2507,  2510,  2515,  2520,  2525,  2530,  2535,
    2540,  2545,  2550,  2555,  2566,  2571,  2576,  2581,  2590,  2599,
    2604,  2609,  2615,  2614,  2619,  2619,  2620,  2623,  2626,  2629,
    2632,  2635,  2638,  2641,  2644,  2647,  2650,  2653,  2656,  2659,
    2662,  2665,  2668,  2671,  2674,  2677,  2683,  2682,  2687,  2687,
    2688,  2691,  2694,  2697,  2700,  2703,  2706,  2709,  2712,  2715,
    2718,  2721,  2724,  2727,  2730,  2733,  2736,  2739,  2742,  2745,
    2750,  2755,  2760,  2769,  2772,  2772,  2773,  2774,  2774,  2775,
    2775,  2776,  2776,  2777,  2778,  2778,  2779,  2780,  2780,  2781,
    2781,  2783,  2788,  2793,  2798,  2803,  2808,  2813,  2818,  2823,
    2828,  2833,  2838,  2843,  2848,  2856,  2859,  2859,  2860,  2860,
    2861,  2862,  2862,  2863,  2864,  2866,  2872,  2878,  2887,  2901,
    2907
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
  "T_GLOBOPS", "T_WALLOP", "T_WEBIRC", "T_RESTART", "T_SERVICE",
  "T_SERVICES_NAME", "THROTTLE_TIME", "TRUE_NO_OPER_FLOOD", "UNKLINE",
  "USER", "USE_EGD", "USE_LOGGING", "VHOST", "VHOST6", "XLINE",
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
  "class_number_per_ip", "class_connectfreq", "class_max_number",
  "class_max_global", "class_max_local", "class_max_ident", "class_sendq",
  "class_recvq", "class_cidr_bitlen_ipv4", "class_cidr_bitlen_ipv6",
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
     299,   299,   299,   299,   299,   299,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     314,   313,   316,   315,   317,   317,   318,   318,   318,   319,
     319,   320,   320,   320,   320,   320,   322,   321,   323,   323,
     324,   324,   325,   326,   328,   327,   329,   329,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   331,   332,   333,
     334,   336,   335,   337,   337,   338,   338,   338,   338,   338,
     338,   338,   338,   338,   338,   339,   340,   341,   343,   342,
     344,   344,   345,   345,   345,   345,   346,   347,   348,   349,
     350,   350,   351,   351,   352,   354,   353,   355,   355,   356,
     356,   356,   356,   357,   358,   360,   359,   361,   361,   362,
     362,   362,   362,   362,   362,   362,   362,   362,   362,   364,
     363,   365,   365,   366,   366,   366,   367,   369,   368,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   373,   372,   374,   374,   375,   375,   375,   375,   375,
     375,   375,   375,   375,   375,   375,   375,   375,   375,   376,
     377,   378,   379,   380,   381,   382,   382,   384,   383,   385,
     385,   386,   386,   387,   388,   389,   390,   391,   393,   392,
     395,   394,   396,   396,   397,   398,   398,   399,   399,   399,
     399,   400,   401,   403,   402,   404,   404,   405,   405,   405,
     406,   407,   408,   409,   409,   410,   410,   411,   413,   412,
     415,   414,   416,   416,   417,   418,   418,   419,   419,   419,
     419,   420,   421,   422,   423,   423,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   424,   424,   424,   424,
     424,   424,   424,   424,   424,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   448,
     449,   450,   450,   451,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   470,   469,   471,   471,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   474,   473,   475,   475,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     476,   476,   476,   476,   476,   476,   476,   476,   476,   476,
     477,   478,   479,   480,   481,   481,   482,   482,   482,   482,
     482,   482,   482,   482,   482,   482,   482,   482,   482,   482,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   498,   499,   499,
     499,   499,   499,   499,   499,   500,   501,   502,   503,   504,
     505
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
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       0,     6,     0,     5,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2,     0,     5,     3,     1,
       1,     3,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     0,     6,
       2,     1,     1,     1,     1,     2,     4,     4,     4,     5,
       2,     1,     1,     1,     4,     0,     6,     2,     1,     1,
       1,     1,     2,     4,     4,     0,     5,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     2,     1,     1,     1,     2,     4,     0,     5,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       4,     4,     4,     4,     4,     4,     4,     0,     5,     3,
       1,     1,     1,     4,     4,     4,     4,     4,     0,     6,
       0,     5,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     4,     0,     6,     2,     1,     1,     1,     1,
       4,     4,     5,     2,     1,     1,     1,     4,     0,     6,
       0,     5,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     5,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     5,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     5,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   199,   351,   403,     0,
     418,     0,   254,   388,   230,     0,     0,   133,   288,     0,
       0,   305,   329,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    96,    97,    99,    98,   600,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   585,   599,   595,   587,   588,   589,   590,   591,
     586,   592,   593,   594,   596,   597,   598,     0,     0,     0,
     416,     0,     0,   414,   415,     0,   485,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   556,     0,   532,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   435,   483,   477,
     478,   479,   480,   481,   476,   446,   436,   437,   471,   438,
     439,   440,   441,   442,   443,   444,   445,   473,   447,   448,
     482,   450,   455,   451,   453,   452,   466,   467,   454,   456,
     457,   458,   459,   460,   449,   462,   463,   464,   484,   474,
     475,   472,   465,   461,   469,   470,   468,     0,     0,     0,
       0,     0,     0,   106,   107,   108,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   624,     0,     0,     0,
       0,     0,     0,     0,   617,   618,   619,   622,   620,   621,
     623,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      50,    65,    66,    64,    61,    60,    67,    51,    63,    54,
      55,    56,    52,    62,    57,    58,    59,    53,     0,     0,
     303,     0,     0,   301,   302,   100,     0,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   584,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   202,   203,   206,   208,   209,   210,   211,   212,
     213,   214,   215,   204,   205,   207,     0,     0,     0,     0,
       0,   377,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,   358,   359,   361,   360,   363,
     367,   364,   365,   366,   362,   409,     0,     0,     0,   406,
     407,   408,     0,     0,   413,   430,     0,     0,   420,   429,
       0,   426,   427,   428,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,     0,     0,     0,   271,     0,
       0,     0,     0,     0,     0,   257,   258,   259,   260,   265,
     261,   262,   263,   264,   400,     0,   390,     0,   399,     0,
     396,   397,   398,     0,   232,     0,     0,     0,   242,     0,
     240,   241,   243,   244,   109,     0,     0,   105,     0,    45,
       0,     0,     0,    41,     0,     0,     0,   176,     0,     0,
       0,   152,     0,     0,   136,   137,   138,   139,   142,   143,
     141,   140,   144,     0,     0,     0,     0,     0,   291,   292,
     293,   294,     0,     0,     0,     0,     0,     0,     0,   616,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    49,
       0,     0,   315,     0,     0,   308,   309,   310,   311,     0,
       0,   337,     0,   332,   333,   334,     0,     0,   300,     0,
       0,     0,    94,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   583,   216,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   201,   368,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     353,     0,     0,     0,   405,     0,   412,     0,     0,     0,
       0,   425,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   433,   266,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   256,     0,     0,     0,     0,   395,
     245,     0,     0,     0,     0,     0,   239,     0,   104,     0,
       0,     0,    40,   145,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   135,   295,     0,     0,     0,     0,   290,
       0,     0,     0,     0,     0,     0,   615,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    73,    74,     0,
      72,    77,    78,     0,    76,     0,     0,     0,     0,     0,
      48,   312,     0,     0,     0,     0,   307,   335,     0,     0,
       0,   331,     0,   299,   103,   102,   101,   610,   609,   601,
      26,    26,    26,    26,    26,    28,    27,   603,   604,   608,
     606,   605,   611,   612,   613,   614,   607,   602,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   352,     0,     0,
     404,   417,     0,     0,     0,   419,   498,   502,   516,   582,
     530,   496,   524,   527,   497,   488,   487,   489,   490,   491,
     505,   494,   495,   506,   493,   501,   500,   499,   525,   486,
     523,   580,   581,   520,   517,   567,   560,   577,   578,   561,
     562,   563,   564,   572,   565,   575,   579,   568,   573,   569,
     574,   566,   571,   570,   576,     0,   559,   522,   542,   536,
     553,   554,   537,   538,   539,   540,   548,   541,   551,   555,
     544,   549,   545,   550,   543,   547,   546,   552,     0,   535,
     515,   518,   529,   492,   519,   508,   513,   514,   511,   512,
     509,   510,   504,   503,   528,   531,   521,   526,   507,     0,
       0,     0,     0,     0,     0,     0,     0,   255,     0,     0,
       0,   389,     0,     0,     0,   250,   246,   249,   231,   110,
       0,     0,   122,     0,     0,   114,   115,   117,   116,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,   134,
       0,     0,     0,   289,   625,   629,   627,   630,   626,   628,
      85,    93,    91,    92,    83,    87,    86,    80,    79,    81,
      69,     0,    70,     0,    84,    82,    90,    88,    89,     0,
       0,     0,   306,     0,     0,   330,   304,    29,    30,    31,
      32,    33,   227,   228,   220,   222,   224,   223,   221,   217,
     229,   219,   218,    34,    34,    34,    36,    35,   225,   226,
     373,   375,   376,   386,   383,   381,   382,     0,   380,   370,
     384,   385,   369,   374,   372,   387,   371,   410,   411,   431,
     432,   424,     0,   423,   557,     0,   533,     0,   269,   270,
     279,   276,   281,   278,   277,   284,   280,   282,   275,   283,
       0,   274,   268,   287,   286,   285,   267,   402,   394,     0,
     393,   401,   237,   238,   236,     0,   235,   253,   252,     0,
       0,     0,   118,     0,     0,     0,     0,   113,   151,   149,
     191,   188,   187,   180,   182,   198,   192,   195,   190,   181,
     196,   184,   193,   197,   185,   194,   189,   183,   186,     0,
     179,   146,   148,   150,   162,   156,   173,   174,   157,   158,
     159,   160,   168,   161,   171,   175,   164,   169,   165,   170,
     163,   167,   166,   172,     0,   155,   147,   297,   298,   296,
      71,    75,   313,   319,   325,   328,   321,   327,   322,   326,
     324,   320,   323,     0,   318,   314,   336,   341,   347,   350,
     343,   349,   344,   348,   346,   342,   345,     0,   340,    37,
      38,    39,   378,     0,   421,     0,   558,   534,   272,     0,
     391,     0,   233,     0,   251,   248,   247,     0,     0,     0,
       0,   112,   177,     0,   153,     0,   316,     0,   338,     0,
     379,   422,   273,   392,   234,   119,   128,   131,   130,   127,
     132,   129,   126,     0,   125,   121,   120,   178,   154,   317,
     339,   123,     0,   124
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   785,   786,  1026,  1027,    25,   230,   231,
     232,   233,    26,   269,   270,   271,   272,   749,   750,   753,
     754,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,    27,    71,    72,    73,
      74,    75,    28,   222,   223,   224,   225,   226,   954,   955,
     956,   957,   958,  1094,  1223,  1224,    29,    60,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   720,  1144,  1145,
     512,   716,  1119,  1120,    30,    49,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,    31,    57,   478,   701,  1085,  1086,   479,   480,   481,
    1091,   946,   947,   482,   483,    32,    55,   454,   455,   456,
     457,   458,   459,   460,   687,  1070,  1071,   461,   462,   463,
      33,    61,   517,   518,   519,   520,   521,    34,   292,   293,
     294,    35,    64,   554,   555,   556,   557,   558,   763,  1163,
    1164,    36,    65,   562,   563,   564,   565,   769,  1177,  1178,
      37,    50,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   610,  1037,  1038,   370,   371,   372,   373,   374,
      38,    56,   468,   696,  1079,  1080,   469,   470,   471,   472,
      39,    51,   378,   379,   380,   381,    40,   112,   113,   114,
      41,    53,   389,   629,  1052,  1053,   390,   391,   392,   393,
      42,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   425,   908,
     909,   213,   423,   885,   886,   214,   215,   216,    43,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,    44,   243,   244,   245,   246,
     247,   248,   249,   250
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -966
static const yytype_int16 yypact[] =
{
    -966,   599,  -966,  -165,  -183,  -181,  -966,  -966,  -966,  -146,
    -966,  -127,  -966,  -966,  -966,  -121,  -112,  -966,  -966,  -107,
     -98,  -966,  -966,   -90,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,   338,   822,   -73,
     -56,   -17,    10,   -15,   405,   -11,    -7,    -1,    38,    75,
      45,    52,   328,   443,    64,    69,     8,  -197,   -72,     7,
      17,    11,  -966,  -966,  -966,  -966,  -966,    37,    65,    72,
      79,    90,    97,   106,   107,   111,   115,   117,   121,   122,
     123,    22,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,   665,   550,    67,
    -966,   125,    16,  -966,  -966,   184,  -966,   129,   131,   133,
     135,   136,   137,   138,   141,   147,   151,   152,   156,   157,
     163,   164,   167,   168,   169,   172,   173,   174,   175,   176,
     182,   183,   185,   187,   188,   189,  -966,   190,  -966,   194,
     199,   204,   206,   208,   210,   212,   216,   217,   219,   221,
     222,   223,   225,   232,   233,   236,   110,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,   384,     5,   362,
      34,   237,    84,  -966,  -966,  -966,    73,    78,   238,   241,
      29,  -966,  -966,  -966,   308,    66,  -966,   242,   243,   250,
     251,   252,   254,     3,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,    86,   258,   262,   263,   265,   267,   269,   275,   276,
     277,   279,   283,   285,   288,   293,   295,   299,   300,   148,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,   170,    23,
    -966,   304,    18,  -966,  -966,  -966,   231,   249,   271,    87,
    -966,   303,   374,   320,   424,   424,   425,   427,   429,   371,
     378,   444,   424,   385,   386,   331,  -966,   332,   330,   337,
     339,   340,   346,   350,   359,   361,   363,   364,   365,   367,
     368,   230,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,   335,   369,   370,   373,
     376,  -966,   377,   381,   387,   392,   403,   404,   406,   408,
     255,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,   409,   410,    47,  -966,
    -966,  -966,   475,   388,  -966,  -966,   412,   414,  -966,  -966,
      32,  -966,  -966,  -966,   437,   424,   424,   503,   460,   474,
     535,   523,   484,   424,   487,   424,   548,   549,   551,   490,
     498,   504,   424,   563,   566,   424,   572,   573,   556,   575,
     578,   522,   524,   466,   526,   468,   424,   424,   529,   532,
     533,   537,   -71,    39,   539,   540,   424,   424,   577,   424,
     541,   543,   544,   491,  -966,   492,   472,   496,  -966,   497,
     499,   501,   505,   507,   130,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,   508,  -966,   511,  -966,     6,
    -966,  -966,  -966,   493,  -966,   512,   514,   517,  -966,    25,
    -966,  -966,  -966,  -966,  -966,   546,   495,  -966,   520,  -966,
     605,   621,   534,  -966,   536,   528,   538,  -966,   542,   545,
     552,  -966,   553,   261,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,   547,   554,   555,   557,    20,  -966,  -966,
    -966,  -966,   591,   593,   636,   596,   598,   424,   559,  -966,
    -966,   641,   602,   617,   668,   647,   651,   652,   659,   660,
     661,    42,    71,   662,   664,   683,   666,   667,   582,  -966,
     583,   585,  -966,   587,    68,  -966,  -966,  -966,  -966,   595,
     607,  -966,    83,  -966,  -966,  -966,   673,   611,  -966,   613,
     616,   618,  -966,   623,   624,   628,   401,   629,   630,   639,
     642,   646,   649,   654,   656,   663,   669,   670,  -966,  -966,
     694,   712,   424,   736,   763,   768,   775,   758,   778,   780,
     424,   781,   781,   674,  -966,  -966,   764,    31,   766,   729,
     672,   774,   779,   782,   783,   793,   784,   785,   786,   682,
    -966,   787,   788,   691,  -966,   692,  -966,   791,   792,   680,
     695,  -966,   696,   697,   698,   699,   700,   701,   704,   705,
     706,   707,   708,   709,   710,   711,   713,   714,   717,   718,
     719,   720,   721,   722,   723,   724,   726,   727,   728,   730,
     731,   620,   732,   648,   734,   735,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,  -966,  -966,   810,   811,   733,   827,   870,
     854,   855,   856,   759,  -966,   858,   760,   859,   762,  -966,
    -966,   761,   863,   864,   883,   769,  -966,   770,  -966,   103,
     771,   772,  -966,  -966,   866,   829,   773,   872,   873,   875,
     776,   876,   789,  -966,  -966,   878,   879,   880,   790,  -966,
     794,   795,   796,   797,   798,   799,  -966,   800,   801,   802,
     803,   804,   805,   806,   807,   808,   809,  -966,  -966,  -199,
    -966,  -966,  -966,  -192,  -966,   812,   813,   814,   815,   816,
    -966,  -966,   881,   817,   882,   818,  -966,  -966,   884,   819,
     821,  -966,   823,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
     424,   424,   424,   424,   424,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,   824,   825,
     826,   828,   830,   831,   832,   833,   834,   835,   836,     4,
     837,   838,  -966,   839,   840,   841,   842,   843,     0,   844,
     845,   846,   847,   848,   849,   850,   851,  -966,   852,   853,
    -966,  -966,   857,   860,   885,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -190,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -189,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,   861,
     862,   321,   865,   867,   868,   869,   871,  -966,   874,   886,
     877,  -966,    -6,   887,   888,   906,   889,  -966,  -966,  -966,
     890,   891,  -966,   892,    15,  -966,  -966,  -966,  -966,  -966,
    -966,   896,   897,   531,   898,   899,   900,   684,   901,  -966,
     902,   903,   904,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,    42,  -966,    71,  -966,  -966,  -966,  -966,  -966,   905,
     465,   907,  -966,   908,   516,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,   781,   781,   781,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -180,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -171,  -966,  -966,   620,  -966,   648,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -170,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -147,
    -966,  -966,  -966,  -966,  -966,  -142,  -966,  -966,  -966,   926,
     883,   909,  -966,   915,   910,   -96,   911,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -139,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -134,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,   -41,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,   -38,  -966,  -966,
    -966,  -966,  -966,     0,  -966,   885,  -966,  -966,  -966,   321,
    -966,   886,  -966,    -6,  -966,  -966,  -966,   912,   469,   914,
     916,  -966,  -966,   531,  -966,   684,  -966,   465,  -966,   516,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,   -18,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,   469,  -966
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -966,  -966,  -966,  -718,  -302,  -965,  -601,  -966,  -966,   893,
    -966,  -966,  -966,  -966,   767,  -966,  -966,  -966,    13,  -966,
       9,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,   934,  -966,
    -966,  -966,  -966,  -966,   913,  -966,  -966,  -966,  -966,    54,
    -966,  -966,  -966,  -966,  -966,  -204,  -966,  -966,  -966,   569,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -161,
    -966,  -966,  -966,  -157,  -966,  -966,  -966,   756,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -120,  -966,   597,  -966,
    -966,  -966,   -10,  -966,  -966,  -966,  -966,  -966,   627,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -114,  -966,  -966,  -966,
    -966,  -966,  -966,   576,  -966,  -966,  -966,  -966,  -966,   894,
    -966,  -966,  -966,  -966,   580,  -966,  -966,  -966,  -966,  -966,
    -124,  -966,  -966,  -966,   527,  -966,  -966,  -966,  -966,  -119,
    -966,  -966,  -966,   777,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,   -91,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,   -95,  -966,   626,  -966,  -966,
    -966,  -966,  -966,   725,  -966,  -966,  -966,  -966,   985,  -966,
    -966,  -966,  -966,  -966,  -966,   -87,  -966,   716,  -966,  -966,
    -966,  -966,   933,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
      43,  -966,  -966,  -966,    46,  -966,  -966,  -966,  -966,  -966,
    1011,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,  -966,
    -966,  -966,  -966,  -966,  -966,  -966,  -966,   895,  -966,  -966,
    -966,  -966,  -966,  -966
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -112
static const yytype_int16 yytable[] =
{
     810,   811,   577,   578,   236,   809,   464,   464,  1035,   290,
     585,   110,    67,  1023,  1024,  1025,   950,   110,   990,   290,
     295,   513,   991,    76,   559,   992,   473,  1054,  1056,   993,
     227,  1055,  1057,   385,   514,    68,    47,  1182,    48,   220,
     237,  1183,    69,    77,    78,  1082,  1184,  1188,   375,    79,
    1185,  1189,    45,    46,   238,   239,   240,   241,  1179,  1180,
    1181,   474,  1007,  1008,  1009,  1010,  1011,   513,   375,   550,
    1190,   111,   242,    52,  1191,  1192,   227,   111,  1202,  1193,
     514,   475,  1203,  1204,   559,   220,   476,  1205,    80,    81,
     670,   671,    54,   633,   634,    82,    83,    84,    58,   291,
    1199,   641,    70,   643,   950,   809,   951,    59,   376,   291,
     650,   116,    62,   653,   560,   515,   117,   118,   228,    85,
      86,    63,   119,   386,   664,   665,   465,   465,   376,    66,
     120,   445,    87,    88,   676,   677,   121,   679,   122,   123,
     124,   516,    89,   477,   229,   125,   107,   446,   296,   251,
      90,   126,   127,   387,   128,   129,   130,   466,   466,   551,
     131,   515,   447,   108,   228,   132,   448,   952,   377,   133,
     134,   550,   252,   135,   560,   561,  1206,   747,   748,  1208,
    1207,  1083,   136,  1209,   388,   385,  1084,   516,   377,   137,
     229,   138,  1036,   139,   951,   140,   141,   142,   143,  1231,
     672,   673,   109,  1232,   115,   253,   751,   752,   217,   144,
     814,   815,   218,   467,   467,   145,   146,   147,   219,   148,
     552,   528,   149,   150,   698,   735,   151,   297,   254,   299,
     953,   317,   255,  1096,   383,   561,   567,   298,   728,   256,
     315,   257,   258,   705,   449,   318,   319,   492,   221,   320,
     630,   484,   450,   451,  -111,   952,   346,   301,   347,   152,
     348,   551,   494,   153,   234,   623,   154,   155,   156,   157,
     158,   235,   349,   159,   160,   386,   553,   259,   495,   260,
     261,   262,   263,   288,   452,   302,   765,   350,   289,   488,
     800,   351,   303,   496,   221,   489,   264,   497,   808,   304,
    -111,   770,   486,   530,   572,   387,   321,   322,   323,   494,
     305,   352,   324,   353,   161,   162,   163,   306,   953,   164,
     265,   325,   552,   354,   165,   495,   307,   308,   443,   236,
     266,   309,   326,   327,  1060,   310,   388,   311,   453,    67,
     496,   312,   313,   314,   497,   382,   355,   328,   693,   394,
     569,   395,   498,   396,  1061,   397,   398,   399,   400,   267,
     268,   401,    68,   473,  1062,   237,   548,   402,   570,    69,
    1063,   403,   404,   356,   329,   499,   405,   406,   553,   238,
     239,   240,   241,   407,   408,   445,  1064,   409,   410,   411,
     571,   500,   412,   413,   414,   415,   416,   242,   474,   498,
     357,   446,   417,   418,   573,   419,   116,   420,   421,   422,
     424,   117,   118,  1065,   426,   330,   447,   119,   475,   427,
     448,  1066,   499,   476,   428,   120,   429,   358,   430,    70,
     431,   121,   432,   122,   123,   124,   433,   434,   500,   435,
     125,   436,   437,   438,   251,   439,   126,   127,   603,   128,
     129,   130,   440,   441,   501,   131,   442,   485,   490,  1067,
     132,   491,   522,   523,   133,   134,   359,   252,   135,   502,
     524,   525,   526,   619,   527,   574,  1068,   136,   531,   722,
     477,   575,   532,   533,   137,   534,   138,   535,   139,   536,
     140,   141,   142,   143,  1200,   537,   538,   539,   449,   540,
     253,   501,   576,   541,   144,   542,   450,   451,   543,  1216,
     145,   146,   147,   544,   148,   545,   502,   149,   150,   546,
     547,   151,  1069,   254,   566,   576,   579,   255,   580,  1153,
     581,  1217,   582,  1218,   256,  1100,   257,   258,   452,   583,
     780,   781,   782,   783,   784,   584,   586,   587,   588,   589,
     590,   346,   605,   347,   152,   348,  1101,   591,   153,   592,
     593,   154,   155,   156,   157,   158,   594,   349,   159,   160,
     595,  1102,   259,  1219,   260,   261,   262,   263,  1103,   596,
    1167,   597,   350,   598,   599,   600,   351,   601,   602,   606,
     607,   264,   453,   608,   625,  1104,   609,   611,   632,     2,
       3,   612,  1154,     4,   635,   626,   352,   613,   353,   161,
     162,   163,   614,     5,   164,   265,     6,     7,   354,   165,
    1105,   636,     8,   615,   616,   266,   617,  1106,   618,   621,
     622,  1155,   627,     9,   628,   637,   638,    10,    11,  1107,
    1156,   355,   639,  1220,  1221,   640,  1157,    12,   642,   644,
     645,   647,   646,  1168,   267,   268,  1108,  1109,  1110,   648,
    1158,    13,  1159,  1160,   651,   649,   317,   652,   356,    14,
      15,   865,  1161,   654,   655,   656,   657,  1222,  1162,   658,
     318,   319,  1169,   659,   320,   660,   661,   662,   663,    16,
     666,  1170,   685,   667,   668,   357,   678,  1171,   669,   888,
     674,   675,   680,    17,   681,   682,  1111,   707,   683,   684,
     700,  1172,   708,  1173,  1174,  1112,   686,   688,   739,   689,
    1113,   690,   358,  1175,   710,   691,  1114,   692,   695,  1176,
    1115,   697,   702,  1116,   703,  1124,    18,   704,  1117,   709,
     711,   321,   322,   323,  1118,    19,    20,   324,   714,    21,
      22,   712,   730,   713,   731,   732,   325,   733,   715,   734,
     737,   359,   717,   738,   724,   718,   741,   326,   327,   740,
     742,   743,   719,   721,   725,   726,   736,   727,   744,   745,
     746,   755,   328,   756,   757,   758,   759,   866,   867,   868,
     869,   870,   772,   871,   872,   798,   873,   874,   875,   760,
     761,   876,    23,   877,   878,   762,   879,   764,   880,   329,
     881,   882,   767,   799,   883,   889,   890,   891,   892,   893,
     884,   894,   895,    76,   896,   897,   898,   768,   773,   899,
     774,   900,   901,   775,   902,   776,   903,   801,   904,   905,
     777,   778,   906,    77,    78,   779,   787,   788,   907,    79,
     330,  1125,  1126,  1127,  1128,  1129,   789,  1130,  1131,   790,
    1132,  1133,  1134,   791,   802,  1135,   792,  1136,  1137,   803,
    1138,   793,  1139,   794,  1140,  1141,   804,   805,  1142,   806,
     795,   807,   809,   813,  1143,   816,   796,   797,    80,    81,
     817,   812,   818,   819,   823,    82,    83,    84,   820,   827,
     834,   821,   822,   824,   825,   826,   828,   829,   830,   831,
     832,   833,   835,   836,   837,   838,   839,   840,   841,    85,
      86,   842,   843,   844,   845,   846,   847,   848,   849,   929,
     850,   851,    87,    88,   852,   853,   854,   855,   856,   857,
     858,   859,    89,   860,   861,   862,   932,   863,   864,   887,
      90,   910,   911,   931,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   921,   922,   923,   924,   925,   926,   927,
     928,   933,   930,   934,   935,   936,   937,   938,   940,   941,
     939,   942,   943,   944,   945,   961,   948,   949,   959,   960,
     962,   964,   965,   963,   966,   968,   967,   970,   971,   972,
     999,  1001,  1151,  1003,  1150,   300,   969,   973,  1097,  1051,
    1078,   974,   975,   976,   977,   978,   979,   980,   981,   982,
     983,   984,   985,   986,   987,   988,   989,  1194,  1233,   994,
     995,   996,   997,   998,  1197,  1002,   549,  1000,  1005,  1004,
    1006,  1012,  1013,  1014,  1228,  1015,  1227,  1016,  1017,  1018,
    1019,  1020,  1021,  1022,  1028,  1029,  1030,  1031,  1032,  1033,
    1034,  1039,  1040,  1041,  1042,  1043,  1044,  1045,  1046,  1047,
    1048,  1089,   723,  1214,  1049,  1212,   706,  1050,  1058,  1059,
    1195,   694,  1072,  1229,  1073,  1074,  1075,   604,  1076,   771,
    1230,  1077,  1210,   729,  1081,   699,  1213,   384,  1211,   444,
    1187,  1186,   316,   624,  1087,  1088,   631,  1092,     0,     0,
    1090,  1093,  1095,  1098,  1099,  1121,  1122,  1123,  1146,  1147,
    1148,  1149,  1152,   493,  1165,  1166,  1196,     0,  1201,  1215,
    1198,  1225,     0,  1226,   766,   487,     0,   620,   529,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   568
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-966)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     601,   602,   304,   305,     1,   101,     1,     1,     8,     1,
     312,     1,     1,     9,    10,    11,     1,     1,   217,     1,
     217,     1,   221,     1,     1,   217,     1,   217,   217,   221,
       1,   221,   221,     1,    14,    24,   219,   217,   219,     1,
      37,   221,    31,    21,    22,    51,   217,   217,     1,    27,
     221,   221,   217,   218,    51,    52,    53,    54,  1023,  1024,
    1025,    36,   780,   781,   782,   783,   784,     1,     1,     1,
     217,    61,    69,   219,   221,   217,     1,    61,   217,   221,
      14,    56,   221,   217,     1,     1,    61,   221,    66,    67,
     161,   162,   219,   395,   396,    73,    74,    75,   219,    91,
     196,   403,    91,   405,     1,   101,    91,   219,    61,    91,
     412,     1,   219,   415,    91,    95,     6,     7,    89,    97,
      98,   219,    12,    91,   426,   427,   121,   121,    61,   219,
      20,     1,   110,   111,   436,   437,    26,   439,    28,    29,
      30,   121,   120,   118,   115,    35,   219,    17,   220,     1,
     128,    41,    42,   121,    44,    45,    46,   152,   152,    91,
      50,    95,    32,   219,    89,    55,    36,   152,   121,    59,
      60,     1,    24,    63,    91,   152,   217,   135,   136,   217,
     221,   187,    72,   221,   152,     1,   192,   121,   121,    79,
     115,    81,   192,    83,    91,    85,    86,    87,    88,   217,
     161,   162,   219,   221,   219,    57,   135,   136,   219,    99,
     179,   180,   219,   208,   208,   105,   106,   107,   219,   109,
     152,   218,   112,   113,   218,   527,   116,   220,    80,   218,
     215,     1,    84,   218,   218,   152,   218,   220,   218,    91,
     218,    93,    94,   218,   114,    15,    16,   218,   210,    19,
     218,   217,   122,   123,   216,   152,     1,   220,     3,   149,
       5,    91,     1,   153,   219,   218,   156,   157,   158,   159,
     160,   219,    17,   163,   164,    91,   208,   129,    17,   131,
     132,   133,   134,   219,   154,   220,   218,    32,   219,   216,
     592,    36,   220,    32,   210,   217,   148,    36,   600,   220,
     216,   218,   218,   217,   217,   121,    76,    77,    78,     1,
     220,    56,    82,    58,   204,   205,   206,   220,   215,   209,
     172,    91,   152,    68,   214,    17,   220,   220,   218,     1,
     182,   220,   102,   103,    13,   220,   152,   220,   208,     1,
      32,   220,   220,   220,    36,   220,    91,   117,   218,   220,
     119,   220,    91,   220,    33,   220,   220,   220,   220,   211,
     212,   220,    24,     1,    43,    37,   218,   220,   119,    31,
      49,   220,   220,   118,   144,   114,   220,   220,   208,    51,
      52,    53,    54,   220,   220,     1,    65,   220,   220,   220,
     119,   130,   220,   220,   220,   220,   220,    69,    36,    91,
     145,    17,   220,   220,   101,   220,     1,   220,   220,   220,
     220,     6,     7,    92,   220,   185,    32,    12,    56,   220,
      36,   100,   114,    61,   220,    20,   220,   172,   220,    91,
     220,    26,   220,    28,    29,    30,   220,   220,   130,   220,
      35,   220,   220,   220,     1,   220,    41,    42,   218,    44,
      45,    46,   220,   220,   193,    50,   220,   220,   220,   138,
      55,   220,   220,   220,    59,    60,   211,    24,    63,   208,
     220,   220,   220,   218,   220,   101,   155,    72,   220,   218,
     118,   161,   220,   220,    79,   220,    81,   220,    83,   220,
      85,    86,    87,    88,  1095,   220,   220,   220,   114,   220,
      57,   193,   101,   220,    99,   220,   122,   123,   220,    40,
     105,   106,   107,   220,   109,   220,   208,   112,   113,   220,
     220,   116,   201,    80,   220,   101,   101,    84,   101,    64,
     101,    62,   161,    64,    91,     4,    93,    94,   154,   161,
     139,   140,   141,   142,   143,   101,   161,   161,   217,   217,
     220,     1,   217,     3,   149,     5,    25,   220,   153,   220,
     220,   156,   157,   158,   159,   160,   220,    17,   163,   164,
     220,    40,   129,   104,   131,   132,   133,   134,    47,   220,
      64,   220,    32,   220,   220,   220,    36,   220,   220,   220,
     220,   148,   208,   220,   119,    64,   220,   220,   161,     0,
       1,   220,   137,     4,   101,   217,    56,   220,    58,   204,
     205,   206,   220,    14,   209,   172,    17,    18,    68,   214,
      89,   161,    23,   220,   220,   182,   220,    96,   220,   220,
     220,   166,   220,    34,   220,   161,   101,    38,    39,   108,
     175,    91,   119,   174,   175,   161,   181,    48,   161,   101,
     101,   161,   101,   137,   211,   212,   125,   126,   127,   161,
     195,    62,   197,   198,   101,   161,     1,   101,   118,    70,
      71,    51,   207,   101,   101,   119,   101,   208,   213,   101,
      15,    16,   166,   161,    19,   161,   220,   161,   220,    90,
     161,   175,   220,   161,   161,   145,   119,   181,   161,    51,
     161,   161,   161,   104,   161,   161,   175,   161,   217,   217,
     217,   195,   217,   197,   198,   184,   220,   220,   101,   220,
     189,   220,   172,   207,   119,   220,   195,   220,   220,   213,
     199,   220,   220,   202,   220,    51,   137,   220,   207,   219,
     119,    76,    77,    78,   213,   146,   147,    82,   220,   150,
     151,   217,   161,   217,   161,   119,    91,   161,   220,   161,
     119,   211,   220,   161,   217,   220,   119,   102,   103,   101,
     119,   119,   220,   220,   220,   220,   217,   220,   119,   119,
     119,   119,   117,   119,   101,   119,   119,   167,   168,   169,
     170,   171,   119,   173,   174,   101,   176,   177,   178,   217,
     217,   181,   203,   183,   184,   220,   186,   220,   188,   144,
     190,   191,   217,   101,   194,   167,   168,   169,   170,   171,
     200,   173,   174,     1,   176,   177,   178,   220,   217,   181,
     217,   183,   184,   217,   186,   217,   188,   101,   190,   191,
     217,   217,   194,    21,    22,   217,   217,   217,   200,    27,
     185,   167,   168,   169,   170,   171,   217,   173,   174,   217,
     176,   177,   178,   217,   101,   181,   217,   183,   184,   101,
     186,   217,   188,   217,   190,   191,   101,   119,   194,   101,
     217,   101,   101,   119,   200,   119,   217,   217,    66,    67,
     161,   217,   220,   119,   101,    73,    74,    75,   119,   217,
     220,   119,   119,   119,   119,   119,   119,   119,   217,   217,
     119,   119,   217,   217,   217,   217,   217,   217,   217,    97,
      98,   217,   217,   217,   217,   217,   217,   217,   217,   119,
     217,   217,   110,   111,   217,   217,   217,   217,   217,   217,
     217,   217,   120,   217,   217,   217,   119,   217,   217,   217,
     128,   217,   217,   220,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   101,   161,   119,   119,   119,   217,   119,   119,   217,
     220,   220,   119,   119,   101,   119,   217,   217,   217,   217,
     161,   119,   119,   220,   119,   119,   220,   119,   119,   119,
     119,   119,   993,   119,   991,    71,   217,   217,   954,   124,
     124,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   101,  1232,   217,
     217,   217,   217,   217,   119,   217,   269,   220,   217,   220,
     217,   217,   217,   217,  1205,   217,  1203,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   165,   503,  1193,   217,  1189,   479,   217,   217,   217,
    1090,   454,   217,  1207,   217,   217,   217,   331,   217,   562,
    1209,   217,  1183,   517,   217,   469,  1191,   112,  1185,   166,
    1057,  1055,    91,   378,   217,   217,   390,   217,    -1,    -1,
     221,   220,   220,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   230,   217,   217,   217,    -1,   217,   217,
     220,   217,    -1,   217,   554,   222,    -1,   360,   243,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   292
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   223,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    90,   104,   137,   146,
     147,   150,   151,   203,   224,   229,   234,   258,   264,   278,
     296,   313,   327,   342,   349,   353,   363,   372,   392,   402,
     408,   412,   422,   480,   497,   217,   218,   219,   219,   297,
     373,   403,   219,   413,   219,   328,   393,   314,   219,   219,
     279,   343,   219,   219,   354,   364,   219,     1,    24,    31,
      91,   259,   260,   261,   262,   263,     1,    21,    22,    27,
      66,    67,    73,    74,    75,    97,    98,   110,   111,   120,
     128,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   219,   219,   219,
       1,    61,   409,   410,   411,   219,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    81,    83,
      85,    86,    87,    88,    99,   105,   106,   107,   109,   112,
     113,   116,   149,   153,   156,   157,   158,   159,   160,   163,
     164,   204,   205,   206,   209,   214,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   435,   436,
     437,   438,   439,   440,   441,   442,   443,   444,   445,   446,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   473,   477,   478,   479,   219,   219,   219,
       1,   210,   265,   266,   267,   268,   269,     1,    89,   115,
     230,   231,   232,   233,   219,   219,     1,    37,    51,    52,
      53,    54,    69,   498,   499,   500,   501,   502,   503,   504,
     505,     1,    24,    57,    80,    84,    91,    93,    94,   129,
     131,   132,   133,   134,   148,   172,   182,   211,   212,   235,
     236,   237,   238,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   254,   255,   256,   257,   219,   219,
       1,    91,   350,   351,   352,   217,   220,   220,   220,   218,
     260,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   218,   482,     1,    15,    16,
      19,    76,    77,    78,    82,    91,   102,   103,   117,   144,
     185,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,   309,   310,   311,   312,     1,     3,     5,    17,
      32,    36,    56,    58,    68,    91,   118,   145,   172,   211,
     374,   375,   376,   377,   378,   379,   380,   381,   382,   383,
     387,   388,   389,   390,   391,     1,    61,   121,   404,   405,
     406,   407,   220,   218,   410,     1,    91,   121,   152,   414,
     418,   419,   420,   421,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   474,   220,   470,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   218,   424,     1,    17,    32,    36,   114,
     122,   123,   154,   208,   329,   330,   331,   332,   333,   334,
     335,   339,   340,   341,     1,   121,   152,   208,   394,   398,
     399,   400,   401,     1,    36,    56,    61,   118,   315,   319,
     320,   321,   325,   326,   217,   220,   218,   266,   216,   217,
     220,   220,   218,   231,     1,    17,    32,    36,    91,   114,
     130,   193,   208,   280,   281,   282,   283,   284,   285,   286,
     287,   288,   292,     1,    14,    95,   121,   344,   345,   346,
     347,   348,   220,   220,   220,   220,   220,   220,   218,   499,
     217,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   218,   236,
       1,    91,   152,   208,   355,   356,   357,   358,   359,     1,
      91,   152,   365,   366,   367,   368,   220,   218,   351,   119,
     119,   119,   217,   101,   101,   161,   101,   226,   226,   101,
     101,   101,   161,   161,   101,   226,   161,   161,   217,   217,
     220,   220,   220,   220,   220,   220,   220,   220,   220,   220,
     220,   220,   220,   218,   299,   217,   220,   220,   220,   220,
     384,   220,   220,   220,   220,   220,   220,   220,   220,   218,
     375,   220,   220,   218,   405,   119,   217,   220,   220,   415,
     218,   419,   161,   226,   226,   101,   161,   161,   101,   119,
     161,   226,   161,   226,   101,   101,   101,   161,   161,   161,
     226,   101,   101,   226,   101,   101,   119,   101,   101,   161,
     161,   220,   161,   220,   226,   226,   161,   161,   161,   161,
     161,   162,   161,   162,   161,   161,   226,   226,   119,   226,
     161,   161,   161,   217,   217,   220,   220,   336,   220,   220,
     220,   220,   220,   218,   330,   220,   395,   220,   218,   399,
     217,   316,   220,   220,   220,   218,   320,   161,   217,   219,
     119,   119,   217,   217,   220,   220,   293,   220,   220,   220,
     289,   220,   218,   281,   217,   220,   220,   220,   218,   345,
     161,   161,   119,   161,   161,   226,   217,   119,   161,   101,
     101,   119,   119,   119,   119,   119,   119,   135,   136,   239,
     240,   135,   136,   241,   242,   119,   119,   101,   119,   119,
     217,   217,   220,   360,   220,   218,   356,   217,   220,   369,
     218,   366,   119,   217,   217,   217,   217,   217,   217,   217,
     139,   140,   141,   142,   143,   225,   226,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   101,   101,
     226,   101,   101,   101,   101,   119,   101,   101,   226,   101,
     228,   228,   217,   119,   179,   180,   119,   161,   220,   119,
     119,   119,   119,   101,   119,   119,   119,   217,   119,   119,
     217,   217,   119,   119,   220,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,    51,   167,   168,   169,   170,
     171,   173,   174,   176,   177,   178,   181,   183,   184,   186,
     188,   190,   191,   194,   200,   475,   476,   217,    51,   167,
     168,   169,   170,   171,   173,   174,   176,   177,   178,   181,
     183,   184,   186,   188,   190,   191,   194,   200,   471,   472,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   119,
     161,   220,   119,   101,   119,   119,   119,   217,   119,   220,
     119,   217,   220,   119,   119,   101,   323,   324,   217,   217,
       1,    91,   152,   215,   270,   271,   272,   273,   274,   217,
     217,   119,   161,   220,   119,   119,   119,   220,   119,   217,
     119,   119,   119,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   221,   217,   221,   217,   217,   217,   217,   217,   119,
     220,   119,   217,   119,   220,   217,   217,   225,   225,   225,
     225,   225,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   217,   217,     9,    10,    11,   227,   228,   217,   217,
     217,   217,   217,   217,   217,     8,   192,   385,   386,   217,
     217,   217,   217,   217,   217,   217,   217,   217,   217,   217,
     217,   124,   416,   417,   217,   221,   217,   221,   217,   217,
      13,    33,    43,    49,    65,    92,   100,   138,   155,   201,
     337,   338,   217,   217,   217,   217,   217,   217,   124,   396,
     397,   217,    51,   187,   192,   317,   318,   217,   217,   165,
     221,   322,   217,   220,   275,   220,   218,   271,   217,   217,
       4,    25,    40,    47,    64,    89,    96,   108,   125,   126,
     127,   175,   184,   189,   195,   199,   202,   207,   213,   294,
     295,   217,   217,   217,    51,   167,   168,   169,   170,   171,
     173,   174,   176,   177,   178,   181,   183,   184,   186,   188,
     190,   191,   194,   200,   290,   291,   217,   217,   217,   217,
     240,   242,   217,    64,   137,   166,   175,   181,   195,   197,
     198,   207,   213,   361,   362,   217,   217,    64,   137,   166,
     175,   181,   195,   197,   198,   207,   213,   370,   371,   227,
     227,   227,   217,   221,   217,   221,   476,   472,   217,   221,
     217,   221,   217,   221,   101,   324,   217,   119,   220,   196,
     228,   217,   217,   221,   217,   221,   217,   221,   217,   221,
     386,   417,   338,   397,   318,   217,    40,    62,    64,   104,
     174,   175,   208,   276,   277,   217,   217,   295,   291,   362,
     371,   217,   221,   277
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
#line 386 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 388 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 392 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 396 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 400 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 404 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 408 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 416 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 417 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 431 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 437 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 463 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 469 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 478 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 484 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 492 "conf_parser.y"
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

  case 80:
/* Line 1792 of yacc.c  */
#line 531 "conf_parser.y"
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

    ServerInfo.rsa_private_key_file = xstrdup(yylval.string);

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

  case 81:
/* Line 1792 of yacc.c  */
#line 590 "conf_parser.y"
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

  case 82:
/* Line 1792 of yacc.c  */
#line 618 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 626 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.name)
  {
    if (valid_servname(yylval.string))
      ServerInfo.name = xstrdup(yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::name -- invalid name. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 641 "conf_parser.y"
    {
  /* this isn't rehashable */
  if (conf_parser_ctx.pass == 2 && !ServerInfo.sid)
  {
    if (valid_sid(yylval.string))
      ServerInfo.sid = xstrdup(yylval.string);
    else
    {
      ilog(LOG_TYPE_IRCD, "Ignoring serverinfo::sid -- invalid SID. Aborting.");
      exit(0);
    }
  }
}
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 656 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 665 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    char *p;

    if ((p = strchr(yylval.string, ' ')) != NULL)
      p = '\0';

    MyFree(ServerInfo.network_name);
    ServerInfo.network_name = xstrdup(yylval.string);
  }
}
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 679 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    ServerInfo.network_desc = xstrdup(yylval.string);
  }
}
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 688 "conf_parser.y"
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
#line 716 "conf_parser.y"
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
#line 746 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].number) < MAXCLIENTS_MIN)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too low, setting to %d", MAXCLIENTS_MIN);
    yyerror(buf);
    ServerInfo.max_clients = MAXCLIENTS_MIN;
  }
  else if ((yyvsp[(3) - (4)].number) > MAXCLIENTS_MAX)
  {
    char buf[IRCD_BUFSIZE];

    snprintf(buf, sizeof(buf), "MAXCLIENTS too high, setting to %d", MAXCLIENTS_MAX);
    yyerror(buf);
    ServerInfo.max_clients = MAXCLIENTS_MAX;
  }
  else
    ServerInfo.max_clients = (yyvsp[(3) - (4)].number);
}
    break;

  case 91:
/* Line 1792 of yacc.c  */
#line 771 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

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
    break;

  case 92:
/* Line 1792 of yacc.c  */
#line 793 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

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
    break;

  case 93:
/* Line 1792 of yacc.c  */
#line 815 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 101:
/* Line 1792 of yacc.c  */
#line 830 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    AdminInfo.name = xstrdup(yylval.string);
  }
}
    break;

  case 102:
/* Line 1792 of yacc.c  */
#line 839 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    AdminInfo.email = xstrdup(yylval.string);
  }
}
    break;

  case 103:
/* Line 1792 of yacc.c  */
#line 848 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    AdminInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 110:
/* Line 1792 of yacc.c  */
#line 866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 111:
/* Line 1792 of yacc.c  */
#line 872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 112:
/* Line 1792 of yacc.c  */
#line 876 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
    break;

  case 119:
/* Line 1792 of yacc.c  */
#line 892 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 120:
/* Line 1792 of yacc.c  */
#line 900 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 121:
/* Line 1792 of yacc.c  */
#line 903 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 915 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 923 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 927 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 931 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 131:
/* Line 1792 of yacc.c  */
#line 935 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 132:
/* Line 1792 of yacc.c  */
#line 939 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 133:
/* Line 1792 of yacc.c  */
#line 949 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 134:
/* Line 1792 of yacc.c  */
#line 956 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;
#ifdef HAVE_LIBCRYPTO
  if (!(block_state.file.buf[0] ||
        block_state.rpass.buf[0]))
    break;
#else
  if (!block_state.rpass.buf[0])
    break;
#endif

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_OPER);
    conf->name  = xstrdup(block_state.name.buf);
    conf->user  = xstrdup(block_state.user.buf);
    conf->host  = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);

    conf->flags = block_state.flags.value;
    conf->modes = block_state.modes.value;
    conf->port  = block_state.port.value;
    conf->htype = parse_netmask(conf->host, &conf->addr, &conf->bits);

    conf_add_class_to_conf(conf, block_state.class.buf);

#ifdef HAVE_LIBCRYPTO
    if (block_state.file.buf[0])
    {
      BIO *file = NULL;
      RSA *pkey = NULL;

      if ((file = BIO_new_file(block_state.file.buf, "r")) == NULL)
      {
        yyerror("Ignoring rsa_public_key_file -- file doesn't exist");
        break;
      }

      if ((pkey = PEM_read_bio_RSA_PUBKEY(file, NULL, 0, NULL)) == NULL)
        yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");

      conf->rsa_public_key = pkey;
      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
    break;

  case 146:
/* Line 1792 of yacc.c  */
#line 1031 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1037 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1043 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 149:
/* Line 1792 of yacc.c  */
#line 1049 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 150:
/* Line 1792 of yacc.c  */
#line 1060 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 151:
/* Line 1792 of yacc.c  */
#line 1066 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1072 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1087 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1115 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1119 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1123 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1127 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1131 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1135 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1139 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1143 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 173:
/* Line 1792 of yacc.c  */
#line 1147 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 174:
/* Line 1792 of yacc.c  */
#line 1151 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 175:
/* Line 1792 of yacc.c  */
#line 1155 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1161 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1200 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1204 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1208 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1212 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_N;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1220 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1224 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1228 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 196:
/* Line 1792 of yacc.c  */
#line 1232 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 197:
/* Line 1792 of yacc.c  */
#line 1236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 198:
/* Line 1792 of yacc.c  */
#line 1240 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 199:
/* Line 1792 of yacc.c  */
#line 1250 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 1)
    break;

  reset_block_state();

  block_state.ping_freq.value = DEFAULT_PINGFREQUENCY;
  block_state.con_freq.value  = DEFAULT_CONNECTFREQUENCY;
  block_state.max_total.value = MAXIMUM_LINKS_DEFAULT;
  block_state.max_sendq.value = DEFAULT_SENDQ;
  block_state.max_recvq.value = DEFAULT_RECVQ;

}
    break;

  case 200:
/* Line 1792 of yacc.c  */
#line 1263 "conf_parser.y"
    {
  struct ClassItem *class = NULL;

  if (conf_parser_ctx.pass != 1)
    break;

  if (!block_state.class.buf[0])
    break;

  if (!(class = class_find(block_state.class.buf, 0)))
    class = class_make();

  class->active = 1;
  MyFree(class->name);
  class->name = xstrdup(block_state.class.buf);
  class->ping_freq = block_state.ping_freq.value;
  class->max_perip = block_state.max_perip.value;
  class->con_freq = block_state.con_freq.value;
  class->max_total = block_state.max_total.value;
  class->max_global = block_state.max_global.value;
  class->max_local = block_state.max_local.value;
  class->max_ident = block_state.max_ident.value;
  class->max_sendq = block_state.max_sendq.value;
  class->max_recvq = block_state.max_recvq.value;

  if (class->number_per_cidr && block_state.number_per_cidr.value)
    if ((class->cidr_bitlen_ipv4 && block_state.cidr_bitlen_ipv4.value) ||
        (class->cidr_bitlen_ipv6 && block_state.cidr_bitlen_ipv6.value))
      if ((class->cidr_bitlen_ipv4 != block_state.cidr_bitlen_ipv4.value) ||
          (class->cidr_bitlen_ipv6 != block_state.cidr_bitlen_ipv6.value))
        rebuild_cidr_list(class);

  class->cidr_bitlen_ipv4 = block_state.cidr_bitlen_ipv4.value;
  class->cidr_bitlen_ipv6 = block_state.cidr_bitlen_ipv6.value;
  class->number_per_cidr = block_state.number_per_cidr.value;
}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1315 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1321 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1327 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1333 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1339 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1345 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1351 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1357 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1363 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 227:
/* Line 1792 of yacc.c  */
#line 1376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 229:
/* Line 1792 of yacc.c  */
#line 1388 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 230:
/* Line 1792 of yacc.c  */
#line 1397 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1403 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 236:
/* Line 1792 of yacc.c  */
#line 1409 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 237:
/* Line 1792 of yacc.c  */
#line 1413 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 238:
/* Line 1792 of yacc.c  */
#line 1417 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1425 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 1430 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }
    add_listener((yyvsp[(1) - (1)].number), block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1444 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    int i;

    if (block_state.flags.value & LISTENER_SSL)
#ifdef HAVE_LIBCRYPTO
      if (!ServerInfo.server_ctx)
#endif
      {
        yyerror("SSL not available - port closed");
	break;
      }

    for (i = (yyvsp[(1) - (3)].number); i <= (yyvsp[(3) - (3)].number); ++i)
      add_listener(i, block_state.addr.buf, block_state.flags.value);
  }
}
    break;

  case 252:
/* Line 1792 of yacc.c  */
#line 1464 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 253:
/* Line 1792 of yacc.c  */
#line 1470 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 254:
/* Line 1792 of yacc.c  */
#line 1479 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 255:
/* Line 1792 of yacc.c  */
#line 1483 "conf_parser.y"
    {
  dlink_node *ptr = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  DLINK_FOREACH(ptr, block_state.mask.list.head)
  {
    struct MaskItem *conf = NULL;
    struct split_nuh_item nuh;

    nuh.nuhmask  = ptr->data;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;
    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);
    split_nuh(&nuh);

    conf        = conf_make(CONF_CLIENT);
    conf->user  = xstrdup(collapse(block_state.user.buf));
    conf->host  = xstrdup(collapse(block_state.host.buf));

    if (block_state.rpass.buf[0])
      conf->passwd = xstrdup(block_state.rpass.buf);
    if (block_state.name.buf[0])
      conf->passwd = xstrdup(block_state.name.buf);

    conf->flags = block_state.flags.value;
    conf->port  = block_state.port.value;

    conf_add_class_to_conf(conf, block_state.class.buf);
    add_conf_by_address(CONF_CLIENT, conf);
  }
}
    break;

  case 267:
/* Line 1792 of yacc.c  */
#line 1526 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 268:
/* Line 1792 of yacc.c  */
#line 1532 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 269:
/* Line 1792 of yacc.c  */
#line 1538 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 270:
/* Line 1792 of yacc.c  */
#line 1544 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 1555 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 1562 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 1566 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 1570 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 1574 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 1578 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 1582 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 1586 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 282:
/* Line 1792 of yacc.c  */
#line 1590 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 1594 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 1598 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 285:
/* Line 1792 of yacc.c  */
#line 1604 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (strlen(yylval.string) <= HOSTLEN && valid_hostname(yylval.string))
  {
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
    block_state.flags.value |= CONF_FLAGS_SPOOF_IP;
  }
  else
    ilog(LOG_TYPE_IRCD, "Spoof either is too long or contains invalid characters. Ignoring it.");
}
    break;

  case 286:
/* Line 1792 of yacc.c  */
#line 1618 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 287:
/* Line 1792 of yacc.c  */
#line 1627 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 288:
/* Line 1792 of yacc.c  */
#line 1640 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 296:
/* Line 1792 of yacc.c  */
#line 1652 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 297:
/* Line 1792 of yacc.c  */
#line 1658 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (IsChanPrefix(*yylval.string))
    create_channel_resv(yylval.string, block_state.rpass.buf, 1);
}
    break;

  case 298:
/* Line 1792 of yacc.c  */
#line 1667 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    create_nick_resv(yylval.string, block_state.rpass.buf, 1);
}
    break;

  case 304:
/* Line 1792 of yacc.c  */
#line 1681 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (valid_servname(yylval.string))
    {
      struct MaskItem *conf = conf_make(CONF_SERVICE);
      conf->name = xstrdup(yylval.string);
    }
  }
}
    break;

  case 305:
/* Line 1792 of yacc.c  */
#line 1696 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  strlcpy(block_state.user.buf, "*", sizeof(block_state.user.buf));
  strlcpy(block_state.host.buf, "*", sizeof(block_state.host.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 306:
/* Line 1792 of yacc.c  */
#line 1707 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_ULINE);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
  conf->user = xstrdup(block_state.user.buf);
  conf->user = xstrdup(block_state.host.buf);
}
    break;

  case 313:
/* Line 1792 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 314:
/* Line 1792 of yacc.c  */
#line 1730 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 1749 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 1756 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 1760 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 1764 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 1768 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 1772 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 1776 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 1780 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 1784 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 327:
/* Line 1792 of yacc.c  */
#line 1788 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 328:
/* Line 1792 of yacc.c  */
#line 1792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 329:
/* Line 1792 of yacc.c  */
#line 1801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 330:
/* Line 1792 of yacc.c  */
#line 1810 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 336:
/* Line 1792 of yacc.c  */
#line 1825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 1831 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 1838 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 1842 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 1846 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 1850 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 1854 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 1858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 1862 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 1866 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 349:
/* Line 1792 of yacc.c  */
#line 1870 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 350:
/* Line 1792 of yacc.c  */
#line 1874 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 351:
/* Line 1792 of yacc.c  */
#line 1883 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 352:
/* Line 1792 of yacc.c  */
#line 1891 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0] ||
      !block_state.host.buf[0])
    break;

  if (!(block_state.rpass.buf[0] ||
        block_state.spass.buf[0]))
    break;

  if (has_wildcards(block_state.name.buf) ||
      has_wildcards(block_state.host.buf))
    break;

  conf = conf_make(CONF_SERVER);
  conf->port = block_state.port.value;
  conf->flags = block_state.flags.value;
  conf->aftype = block_state.aftype.value;
  conf->host = xstrdup(block_state.host.buf);
  conf->name = xstrdup(block_state.name.buf);
  conf->passwd = xstrdup(block_state.rpass.buf);
  conf->spasswd = xstrdup(block_state.spass.buf);
  conf->cipher_list = xstrdup(block_state.ciph.buf);

  dlinkMoveList(&block_state.leaf.list, &conf->leaf_list);
  dlinkMoveList(&block_state.hub.list, &conf->hub_list);

  if (block_state.bind.buf[0])
  {
    memset(&hints, 0, sizeof(hints));

    hints.ai_family   = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

    if (getaddrinfo(block_state.bind.buf, NULL, &hints, &res))
      ilog(LOG_TYPE_IRCD, "Invalid netmask for server vhost(%s)", block_state.bind.buf);
    else
    {
      assert(res != NULL);

      memcpy(&conf->bind, res->ai_addr, res->ai_addrlen);
      conf->bind.ss.ss_family = res->ai_family;
      conf->bind.ss_len = res->ai_addrlen;
      freeaddrinfo(res);
    }
  }

  conf_add_class_to_conf(conf, block_state.class.buf);
  lookup_confhost(conf);
}
    break;

  case 369:
/* Line 1792 of yacc.c  */
#line 1957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 370:
/* Line 1792 of yacc.c  */
#line 1963 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 371:
/* Line 1792 of yacc.c  */
#line 1969 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 372:
/* Line 1792 of yacc.c  */
#line 1975 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    yyerror("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    yyerror("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.spass.buf, yylval.string, sizeof(block_state.spass.buf));
}
    break;

  case 373:
/* Line 1792 of yacc.c  */
#line 1988 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if ((yyvsp[(3) - (4)].string)[0] == ':')
    yyerror("Server passwords cannot begin with a colon");
  else if (strchr((yyvsp[(3) - (4)].string), ' ') != NULL)
    yyerror("Server passwords cannot contain spaces");
  else
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 374:
/* Line 1792 of yacc.c  */
#line 2001 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 375:
/* Line 1792 of yacc.c  */
#line 2007 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 376:
/* Line 1792 of yacc.c  */
#line 2011 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 377:
/* Line 1792 of yacc.c  */
#line 2019 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 381:
/* Line 1792 of yacc.c  */
#line 2025 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 2029 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 2035 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.number)
      block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
    else
      block_state.flags.value &= ~CONF_FLAGS_ENCRYPTED;
  }
}
    break;

  case 384:
/* Line 1792 of yacc.c  */
#line 2046 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 2052 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 386:
/* Line 1792 of yacc.c  */
#line 2058 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 387:
/* Line 1792 of yacc.c  */
#line 2064 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.ciph.buf, yylval.string, sizeof(block_state.ciph.buf));
#else
  if (conf_parser_ctx.pass == 2)
    yyerror("Ignoring connect::ciphers -- no OpenSSL support");
#endif
}
    break;

  case 388:
/* Line 1792 of yacc.c  */
#line 2079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 389:
/* Line 1792 of yacc.c  */
#line 2083 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.user.buf[0] ||
      !block_state.host.buf[0])
    break;


  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_user = NULL;
    void *exp_host = NULL;
    const char *errptr = NULL;
 
    if (!(exp_user = ircd_pcre_compile(block_state.user.buf, &errptr)) ||
        !(exp_host = ircd_pcre_compile(block_state.host.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RKLINE);
    conf->regexuser = exp_user;
    conf->regexhost = exp_host;

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
#else
    ilog(LOG_TYPE_IRCD, "Failed to add regular expression based K-Line: no PCRE support");
    break;
#endif
  }
  else
  {
    conf = conf_make(CONF_KLINE);

    conf->user = xstrdup(block_state.user.buf);
    conf->host = xstrdup(block_state.host.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_KLINE, conf);
  }
}
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2141 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 394:
/* Line 1792 of yacc.c  */
#line 2148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 401:
/* Line 1792 of yacc.c  */
#line 2157 "conf_parser.y"
    {

  if (conf_parser_ctx.pass == 2)
  {
    struct split_nuh_item nuh;

    nuh.nuhmask  = yylval.string;
    nuh.nickptr  = NULL;
    nuh.userptr  = block_state.user.buf;
    nuh.hostptr  = block_state.host.buf;

    nuh.nicksize = 0;
    nuh.usersize = sizeof(block_state.user.buf);
    nuh.hostsize = sizeof(block_state.host.buf);

    split_nuh(&nuh);
  }
}
    break;

  case 402:
/* Line 1792 of yacc.c  */
#line 2177 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 403:
/* Line 1792 of yacc.c  */
#line 2186 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 404:
/* Line 1792 of yacc.c  */
#line 2190 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.addr.buf[0])
    break;

  if (parse_netmask(block_state.addr.buf, NULL, NULL) != HM_HOST)
  {
    conf = conf_make(CONF_DLINE);
    conf->host = xstrdup(block_state.addr.buf);

    if (block_state.rpass.buf[0])
      conf->reason = xstrdup(block_state.rpass.buf);
    else
      conf->reason = xstrdup(CONF_NOREASON);
    add_conf_by_address(CONF_DLINE, conf);
  }
}
    break;

  case 410:
/* Line 1792 of yacc.c  */
#line 2216 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 411:
/* Line 1792 of yacc.c  */
#line 2222 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 417:
/* Line 1792 of yacc.c  */
#line 2236 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (yylval.string[0] && parse_netmask(yylval.string, NULL, NULL) != HM_HOST)
    {
      struct MaskItem *conf = conf_make(CONF_EXEMPT);
      conf->host = xstrdup(yylval.string);

      add_conf_by_address(CONF_EXEMPT, conf);
    }
  }
}
    break;

  case 418:
/* Line 1792 of yacc.c  */
#line 2253 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 419:
/* Line 1792 of yacc.c  */
#line 2257 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  if (!block_state.name.buf[0])
    break;

  if (block_state.port.value == 1)
  {
#ifdef HAVE_LIBPCRE
    void *exp_p = NULL;
    const char *errptr = NULL;

    if (!(exp_p = ircd_pcre_compile(block_state.name.buf, &errptr)))
    {
      ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: %s",
           errptr);
      break;
    }

    conf = conf_make(CONF_RXLINE);
    conf->regexuser = exp_p;
#else
    ilog(LOG_TYPE_IRCD, "Failed to add regular expression based X-Line: no PCRE support");
    break;
#endif
  }
  else
    conf = conf_make(CONF_XLINE);

  conf->name = xstrdup(block_state.name.buf);

  if (block_state.rpass.buf[0])
    conf->reason = xstrdup(block_state.rpass.buf);
  else
    conf->reason = xstrdup(CONF_NOREASON);
}
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 2298 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 424:
/* Line 1792 of yacc.c  */
#line 2305 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 431:
/* Line 1792 of yacc.c  */
#line 2314 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 432:
/* Line 1792 of yacc.c  */
#line 2320 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 486:
/* Line 1792 of yacc.c  */
#line 2365 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1792 of yacc.c  */
#line 2370 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 488:
/* Line 1792 of yacc.c  */
#line 2376 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 489:
/* Line 1792 of yacc.c  */
#line 2382 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1792 of yacc.c  */
#line 2388 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 491:
/* Line 1792 of yacc.c  */
#line 2393 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 492:
/* Line 1792 of yacc.c  */
#line 2398 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 493:
/* Line 1792 of yacc.c  */
#line 2403 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 494:
/* Line 1792 of yacc.c  */
#line 2408 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 495:
/* Line 1792 of yacc.c  */
#line 2413 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 496:
/* Line 1792 of yacc.c  */
#line 2418 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 497:
/* Line 1792 of yacc.c  */
#line 2423 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 498:
/* Line 1792 of yacc.c  */
#line 2428 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 499:
/* Line 1792 of yacc.c  */
#line 2433 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 2438 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 2443 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 502:
/* Line 1792 of yacc.c  */
#line 2448 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 2453 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 2458 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 2464 "conf_parser.y"
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

  case 506:
/* Line 1792 of yacc.c  */
#line 2475 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 2480 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 2485 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 2490 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 2495 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 2500 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 2503 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 2508 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 2511 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 2516 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 2521 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 2526 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 2531 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 2536 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 2541 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 2546 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 2551 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 2556 "conf_parser.y"
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
/* Line 1792 of yacc.c  */
#line 2567 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 2572 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 2582 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 2591 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 529:
/* Line 1792 of yacc.c  */
#line 2600 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 530:
/* Line 1792 of yacc.c  */
#line 2605 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 531:
/* Line 1792 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 2615 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 536:
/* Line 1792 of yacc.c  */
#line 2621 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 2624 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 2627 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 2630 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 2633 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 2636 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 2642 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 2651 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 548:
/* Line 1792 of yacc.c  */
#line 2657 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 2660 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 2666 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 2669 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 553:
/* Line 1792 of yacc.c  */
#line 2672 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 554:
/* Line 1792 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 555:
/* Line 1792 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 2683 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 560:
/* Line 1792 of yacc.c  */
#line 2689 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 2692 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 2695 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 2698 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 2701 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 2704 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 2710 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 2713 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 2716 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 2719 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 2722 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 572:
/* Line 1792 of yacc.c  */
#line 2725 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 573:
/* Line 1792 of yacc.c  */
#line 2728 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 574:
/* Line 1792 of yacc.c  */
#line 2731 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 575:
/* Line 1792 of yacc.c  */
#line 2734 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 576:
/* Line 1792 of yacc.c  */
#line 2737 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 2743 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 579:
/* Line 1792 of yacc.c  */
#line 2746 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 580:
/* Line 1792 of yacc.c  */
#line 2751 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 581:
/* Line 1792 of yacc.c  */
#line 2756 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 582:
/* Line 1792 of yacc.c  */
#line 2761 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1792 of yacc.c  */
#line 2784 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 602:
/* Line 1792 of yacc.c  */
#line 2789 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 603:
/* Line 1792 of yacc.c  */
#line 2794 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 604:
/* Line 1792 of yacc.c  */
#line 2799 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1792 of yacc.c  */
#line 2804 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1792 of yacc.c  */
#line 2809 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1792 of yacc.c  */
#line 2814 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 608:
/* Line 1792 of yacc.c  */
#line 2819 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 609:
/* Line 1792 of yacc.c  */
#line 2824 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 610:
/* Line 1792 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 611:
/* Line 1792 of yacc.c  */
#line 2834 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 612:
/* Line 1792 of yacc.c  */
#line 2839 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 613:
/* Line 1792 of yacc.c  */
#line 2844 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 614:
/* Line 1792 of yacc.c  */
#line 2849 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 625:
/* Line 1792 of yacc.c  */
#line 2867 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 626:
/* Line 1792 of yacc.c  */
#line 2873 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 627:
/* Line 1792 of yacc.c  */
#line 2879 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 628:
/* Line 1792 of yacc.c  */
#line 2888 "conf_parser.y"
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

  case 629:
/* Line 1792 of yacc.c  */
#line 2902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 630:
/* Line 1792 of yacc.c  */
#line 2908 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1792 of yacc.c  */
#line 6669 "conf_parser.c"
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


