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
     T_WEBIRC = 454,
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
#define T_WEBIRC 454
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
/* Line 387 of yacc.c  */
#line 135 "conf_parser.y"

  int number;
  char *string;


/* Line 387 of yacc.c  */
#line 655 "conf_parser.c"
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
#line 683 "conf_parser.c"

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
#define YYLAST   1132

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  220
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  282
/* YYNRULES -- Number of rules.  */
#define YYNRULES  626
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1224

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
     587,   589,   591,   594,   599,   604,   609,   614,   619,   624,
     629,   634,   639,   644,   649,   654,   659,   660,   667,   668,
     674,   678,   680,   682,   684,   686,   689,   691,   693,   695,
     697,   699,   702,   703,   709,   713,   715,   717,   721,   726,
     731,   732,   739,   742,   744,   746,   748,   750,   752,   754,
     756,   758,   760,   763,   768,   773,   778,   783,   784,   790,
     794,   796,   798,   800,   802,   804,   806,   808,   810,   812,
     814,   816,   821,   826,   831,   832,   839,   842,   844,   846,
     848,   850,   853,   858,   863,   868,   874,   877,   879,   881,
     883,   888,   889,   896,   899,   901,   903,   905,   907,   910,
     915,   920,   921,   927,   931,   933,   935,   937,   939,   941,
     943,   945,   947,   949,   951,   953,   954,   961,   964,   966,
     968,   970,   973,   978,   979,   985,   989,   991,   993,   995,
     997,   999,  1001,  1003,  1005,  1007,  1009,  1011,  1012,  1019,
    1022,  1024,  1026,  1028,  1030,  1032,  1034,  1036,  1038,  1040,
    1042,  1044,  1046,  1048,  1050,  1053,  1058,  1063,  1068,  1073,
    1078,  1083,  1088,  1093,  1094,  1100,  1104,  1106,  1108,  1110,
    1115,  1120,  1125,  1130,  1135,  1136,  1143,  1144,  1150,  1154,
    1156,  1158,  1161,  1163,  1165,  1167,  1169,  1171,  1176,  1181,
    1182,  1189,  1192,  1194,  1196,  1198,  1200,  1205,  1210,  1216,
    1219,  1221,  1223,  1225,  1230,  1231,  1238,  1239,  1245,  1249,
    1251,  1253,  1256,  1258,  1260,  1262,  1264,  1266,  1271,  1276,
    1282,  1285,  1287,  1289,  1291,  1293,  1295,  1297,  1299,  1301,
    1303,  1305,  1307,  1309,  1311,  1313,  1315,  1317,  1319,  1321,
    1323,  1325,  1327,  1329,  1331,  1333,  1335,  1337,  1339,  1341,
    1343,  1345,  1347,  1349,  1351,  1353,  1355,  1357,  1359,  1361,
    1363,  1365,  1367,  1369,  1371,  1373,  1375,  1377,  1379,  1381,
    1383,  1385,  1387,  1392,  1397,  1402,  1407,  1412,  1417,  1422,
    1427,  1432,  1437,  1442,  1447,  1452,  1457,  1462,  1467,  1472,
    1477,  1482,  1487,  1492,  1497,  1502,  1507,  1512,  1517,  1522,
    1527,  1532,  1537,  1542,  1547,  1552,  1557,  1562,  1567,  1572,
    1577,  1582,  1587,  1592,  1597,  1602,  1607,  1612,  1617,  1618,
    1624,  1628,  1630,  1632,  1634,  1636,  1638,  1640,  1642,  1644,
    1646,  1648,  1650,  1652,  1654,  1656,  1658,  1660,  1662,  1664,
    1666,  1668,  1670,  1671,  1677,  1681,  1683,  1685,  1687,  1689,
    1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,  1707,  1709,
    1711,  1713,  1715,  1717,  1719,  1721,  1723,  1728,  1733,  1738,
    1744,  1747,  1749,  1751,  1753,  1755,  1757,  1759,  1761,  1763,
    1765,  1767,  1769,  1771,  1773,  1775,  1777,  1779,  1784,  1789,
    1794,  1799,  1804,  1809,  1814,  1819,  1824,  1829,  1834,  1839,
    1844,  1849,  1855,  1858,  1860,  1862,  1864,  1866,  1868,  1870,
    1872,  1874,  1879,  1884,  1889,  1894,  1899
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     221,     0,    -1,    -1,   221,   222,    -1,   254,    -1,   260,
      -1,   274,    -1,   476,    -1,   292,    -1,   309,    -1,   323,
      -1,   232,    -1,   493,    -1,   338,    -1,   345,    -1,   349,
      -1,   359,    -1,   368,    -1,   388,    -1,   398,    -1,   404,
      -1,   418,    -1,   408,    -1,   227,    -1,     1,   215,    -1,
       1,   216,    -1,    -1,   224,    -1,    99,   223,    -1,    99,
     137,   223,    -1,    99,   138,   223,    -1,    99,   139,   223,
      -1,    99,   140,   223,    -1,    99,   141,   223,    -1,    -1,
     226,    -1,    99,   225,    -1,    99,     9,   225,    -1,    99,
      10,   225,    -1,    99,    11,   225,    -1,    88,   217,   228,
     216,   215,    -1,   228,   229,    -1,   229,    -1,   230,    -1,
     231,    -1,     1,   215,    -1,    87,   218,   117,   215,    -1,
     113,   218,   117,   215,    -1,   145,   217,   233,   216,   215,
      -1,   233,   234,    -1,   234,    -1,   245,    -1,   250,    -1,
     253,    -1,   247,    -1,   248,    -1,   249,    -1,   252,    -1,
     243,    -1,   242,    -1,   251,    -1,   246,    -1,   241,    -1,
     235,    -1,   236,    -1,   244,    -1,     1,   215,    -1,   131,
     218,   237,   215,    -1,   132,   218,   239,   215,    -1,   237,
     219,   238,    -1,   238,    -1,   133,    -1,   134,    -1,   239,
     219,   240,    -1,   240,    -1,   133,    -1,   134,    -1,   129,
     218,   117,   215,    -1,   127,   218,   117,   215,    -1,   130,
     218,   117,   215,    -1,   170,   218,   117,   215,    -1,    89,
     218,   117,   215,    -1,   146,   218,   117,   215,    -1,    24,
     218,   117,   215,    -1,    92,   218,   117,   215,    -1,    91,
     218,   117,   215,    -1,   209,   218,   117,   215,    -1,   210,
     218,   117,   215,    -1,   180,   218,    99,   215,    -1,    57,
     218,   159,   215,    -1,     4,   217,   255,   216,   215,    -1,
     255,   256,    -1,   256,    -1,   257,    -1,   259,    -1,   258,
      -1,     1,   215,    -1,    89,   218,   117,   215,    -1,    31,
     218,   117,   215,    -1,    24,   218,   117,   215,    -1,    71,
     217,   261,   216,   215,    -1,   261,   262,    -1,   262,    -1,
     263,    -1,   264,    -1,     1,   215,    -1,   208,   218,   159,
     215,    -1,    -1,   265,   214,   217,   266,   216,   215,    -1,
     266,   267,    -1,   267,    -1,   268,    -1,   270,    -1,   269,
      -1,     1,   215,    -1,    89,   218,   117,   215,    -1,   213,
     218,   226,   215,    -1,   213,   218,   194,   215,    -1,    -1,
     150,   271,   218,   272,   215,    -1,   272,   219,   273,    -1,
     273,    -1,   206,    -1,   102,    -1,    40,    -1,   173,    -1,
      64,    -1,    62,    -1,   172,    -1,    -1,   102,   275,   217,
     276,   216,   215,    -1,   276,   277,    -1,   277,    -1,   278,
      -1,   279,    -1,   280,    -1,   284,    -1,   283,    -1,   281,
      -1,   282,    -1,   288,    -1,     1,   215,    -1,    89,   218,
     117,   215,    -1,   206,   218,   117,   215,    -1,   112,   218,
     117,   215,    -1,    32,   218,   159,   215,    -1,   128,   218,
     117,   215,    -1,    17,   218,   117,   215,    -1,    -1,   191,
     285,   218,   286,   215,    -1,   286,   219,   287,    -1,   287,
      -1,   165,    -1,   168,    -1,   169,    -1,   171,    -1,   172,
      -1,   175,    -1,    51,    -1,   188,    -1,   181,    -1,   184,
      -1,   192,    -1,   189,    -1,   174,    -1,   182,    -1,   186,
      -1,   176,    -1,   198,    -1,   166,    -1,   167,    -1,   179,
      -1,    -1,    36,   289,   218,   290,   215,    -1,   290,   219,
     291,    -1,   291,    -1,    47,    -1,   124,    -1,    64,    -1,
     205,    -1,   173,    -1,   193,    -1,   211,    -1,    40,    -1,
      25,    -1,   200,    -1,   123,    -1,     4,    -1,    94,    -1,
     182,    -1,   197,    -1,   106,    -1,   125,    -1,   187,    -1,
      87,    -1,    -1,    17,   293,   217,   294,   216,   215,    -1,
     294,   295,    -1,   295,    -1,   296,    -1,   306,    -1,   307,
      -1,   297,    -1,   308,    -1,   298,    -1,   299,    -1,   300,
      -1,   301,    -1,   302,    -1,   303,    -1,   304,    -1,   305,
      -1,     1,   215,    -1,    89,   218,   117,   215,    -1,   115,
     218,   224,   215,    -1,   101,   218,    99,   215,    -1,    19,
     218,   224,   215,    -1,    81,   218,    99,   215,    -1,    76,
     218,    99,   215,    -1,    78,   218,    99,   215,    -1,    77,
     218,    99,   215,    -1,   142,   218,   226,   215,    -1,   183,
     218,   226,   215,    -1,    15,   218,    99,   215,    -1,    16,
     218,    99,   215,    -1,   100,   218,    99,   215,    -1,    -1,
      70,   310,   217,   315,   216,   215,    -1,    -1,    36,   312,
     218,   313,   215,    -1,   313,   219,   314,    -1,   314,    -1,
     190,    -1,    51,    -1,   185,    -1,   315,   316,    -1,   316,
      -1,   317,    -1,   311,    -1,   321,    -1,   322,    -1,     1,
     215,    -1,    -1,   116,   218,   319,   318,   215,    -1,   319,
     219,   320,    -1,   320,    -1,    99,    -1,    99,   163,    99,
      -1,    61,   218,   117,   215,    -1,    56,   218,   117,   215,
      -1,    -1,    48,   324,   217,   325,   216,   215,    -1,   325,
     326,    -1,   326,    -1,   327,    -1,   328,    -1,   329,    -1,
     331,    -1,   335,    -1,   336,    -1,   337,    -1,   330,    -1,
       1,   215,    -1,   206,   218,   117,   215,    -1,   112,   218,
     117,   215,    -1,    17,   218,   117,   215,    -1,    32,   218,
     159,   215,    -1,    -1,    36,   332,   218,   333,   215,    -1,
     333,   219,   334,    -1,   334,    -1,   153,    -1,    33,    -1,
      65,    -1,    49,    -1,    13,    -1,    98,    -1,    43,    -1,
     136,    -1,   199,    -1,    90,    -1,   152,   218,   117,   215,
      -1,   121,   218,   117,   215,    -1,   120,   218,    99,   215,
      -1,    -1,   135,   339,   217,   340,   216,   215,    -1,   340,
     341,    -1,   341,    -1,   342,    -1,   343,    -1,   344,    -1,
       1,   215,    -1,   119,   218,   117,   215,    -1,    14,   218,
     117,   215,    -1,    93,   218,   117,   215,    -1,   201,   217,
     346,   216,   215,    -1,   346,   347,    -1,   347,    -1,   348,
      -1,     1,    -1,    89,   218,   117,   215,    -1,    -1,   148,
     350,   217,   351,   216,   215,    -1,   351,   352,    -1,   352,
      -1,   353,    -1,   354,    -1,   355,    -1,     1,   215,    -1,
      89,   218,   117,   215,    -1,   206,   218,   117,   215,    -1,
      -1,   150,   356,   218,   357,   215,    -1,   357,   219,   358,
      -1,   358,    -1,    64,    -1,   205,    -1,   173,    -1,   193,
      -1,   211,    -1,   196,    -1,   135,    -1,   195,    -1,   179,
      -1,   164,    -1,    -1,   149,   360,   217,   361,   216,   215,
      -1,   361,   362,    -1,   362,    -1,   363,    -1,   364,    -1,
       1,   215,    -1,    89,   218,   117,   215,    -1,    -1,   150,
     365,   218,   366,   215,    -1,   366,   219,   367,    -1,   367,
      -1,    64,    -1,   205,    -1,   173,    -1,   193,    -1,   211,
      -1,   196,    -1,   135,    -1,   195,    -1,   179,    -1,   164,
      -1,    -1,    18,   369,   217,   370,   216,   215,    -1,   370,
     371,    -1,   371,    -1,   372,    -1,   373,    -1,   374,    -1,
     375,    -1,   376,    -1,   378,    -1,   377,    -1,   387,    -1,
     379,    -1,   384,    -1,   385,    -1,   386,    -1,   383,    -1,
       1,   215,    -1,    89,   218,   117,   215,    -1,    56,   218,
     117,   215,    -1,   209,   218,   117,   215,    -1,   143,   218,
     117,   215,    -1,     3,   218,   117,   215,    -1,   116,   218,
      99,   215,    -1,     5,   218,   177,   215,    -1,     5,   218,
     178,   215,    -1,    -1,    36,   380,   218,   381,   215,    -1,
     381,   219,   382,    -1,   382,    -1,     8,    -1,   190,    -1,
      32,   218,   159,   215,    -1,    58,   218,   117,   215,    -1,
      68,   218,   117,   215,    -1,    17,   218,   117,   215,    -1,
     170,   218,   117,   215,    -1,    -1,    62,   389,   217,   394,
     216,   215,    -1,    -1,   150,   391,   218,   392,   215,    -1,
     392,   219,   393,    -1,   393,    -1,   122,    -1,   394,   395,
      -1,   395,    -1,   396,    -1,   397,    -1,   390,    -1,     1,
      -1,   206,   218,   117,   215,    -1,   119,   218,   117,   215,
      -1,    -1,    23,   399,   217,   400,   216,   215,    -1,   400,
     401,    -1,   401,    -1,   402,    -1,   403,    -1,     1,    -1,
      61,   218,   117,   215,    -1,   119,   218,   117,   215,    -1,
      34,   217,   405,   216,   215,    -1,   405,   406,    -1,   406,
      -1,   407,    -1,     1,    -1,    61,   218,   117,   215,    -1,
      -1,    38,   409,   217,   414,   216,   215,    -1,    -1,   150,
     411,   218,   412,   215,    -1,   412,   219,   413,    -1,   413,
      -1,   122,    -1,   414,   415,    -1,   415,    -1,   416,    -1,
     417,    -1,   410,    -1,     1,    -1,    89,   218,   117,   215,
      -1,   119,   218,   117,   215,    -1,    39,   217,   419,   216,
     215,    -1,   419,   420,    -1,   420,    -1,   429,    -1,   430,
      -1,   432,    -1,   433,    -1,   434,    -1,   435,    -1,   436,
      -1,   437,    -1,   438,    -1,   439,    -1,   428,    -1,   441,
      -1,   442,    -1,   457,    -1,   444,    -1,   446,    -1,   448,
      -1,   447,    -1,   451,    -1,   445,    -1,   452,    -1,   453,
      -1,   454,    -1,   455,    -1,   456,    -1,   469,    -1,   458,
      -1,   459,    -1,   460,    -1,   465,    -1,   449,    -1,   450,
      -1,   475,    -1,   473,    -1,   474,    -1,   431,    -1,   464,
      -1,   440,    -1,   462,    -1,   463,    -1,   427,    -1,   422,
      -1,   423,    -1,   424,    -1,   425,    -1,   426,    -1,   443,
      -1,   421,    -1,   461,    -1,     1,    -1,    83,   218,    99,
     215,    -1,    42,   218,   159,   215,    -1,    41,   218,   224,
     215,    -1,    44,   218,   224,   215,    -1,    45,   218,    99,
     215,    -1,    46,   218,    99,   215,    -1,   147,   218,   159,
     215,    -1,    63,   218,   224,   215,    -1,    55,   218,   159,
     215,    -1,    59,   218,   159,   215,    -1,    28,   218,   159,
     215,    -1,    35,   218,   159,   215,    -1,     6,   218,   159,
     215,    -1,    80,   218,   224,   215,    -1,    79,   218,    99,
     215,    -1,    72,   218,    99,   215,    -1,     7,   218,   224,
     215,    -1,   162,   218,   224,   215,    -1,   161,   218,   224,
     215,    -1,    50,   218,    99,   215,    -1,    60,   218,   159,
     215,    -1,   212,   218,   159,   215,    -1,   154,   218,   159,
     215,    -1,   157,   218,   159,   215,    -1,   158,   218,   159,
     215,    -1,   156,   218,   159,   215,    -1,   156,   218,   160,
     215,    -1,   155,   218,   159,   215,    -1,   155,   218,   160,
     215,    -1,   110,   218,   224,   215,    -1,    12,   218,   224,
     215,    -1,   103,   218,   159,   215,    -1,   111,   218,   224,
     215,    -1,   151,   218,   159,   215,    -1,    97,   218,   159,
     215,    -1,   204,   218,   159,   215,    -1,   105,   218,   159,
     215,    -1,    84,   218,   117,   215,    -1,    29,   218,    99,
     215,    -1,    82,   218,    99,   215,    -1,   207,   218,   159,
     215,    -1,    30,   218,   117,   215,    -1,   202,   218,   117,
     215,    -1,   114,   218,   159,   215,    -1,    26,   218,   159,
     215,    -1,   203,   218,   224,   215,    -1,    -1,   107,   466,
     218,   467,   215,    -1,   467,   219,   468,    -1,   468,    -1,
     165,    -1,   168,    -1,   169,    -1,   171,    -1,   172,    -1,
     175,    -1,    51,    -1,   188,    -1,   181,    -1,   184,    -1,
     192,    -1,   189,    -1,   174,    -1,   182,    -1,   186,    -1,
     176,    -1,   198,    -1,   166,    -1,   167,    -1,   179,    -1,
      -1,   104,   470,   218,   471,   215,    -1,   471,   219,   472,
      -1,   472,    -1,   165,    -1,   168,    -1,   169,    -1,   171,
      -1,   172,    -1,   175,    -1,   188,    -1,    51,    -1,   181,
      -1,   184,    -1,   192,    -1,   189,    -1,   174,    -1,   182,
      -1,   186,    -1,   176,    -1,   198,    -1,   166,    -1,   167,
      -1,   179,    -1,    85,   218,    99,   215,    -1,    86,   218,
      99,   215,    -1,    20,   218,    99,   215,    -1,    14,   217,
     477,   216,   215,    -1,   477,   478,    -1,   478,    -1,   486,
      -1,   481,    -1,   482,    -1,   483,    -1,   484,    -1,   485,
      -1,   487,    -1,   488,    -1,   489,    -1,   480,    -1,   490,
      -1,   491,    -1,   492,    -1,   479,    -1,     1,    -1,    27,
     218,   159,   215,    -1,   126,   218,   159,   215,    -1,    66,
     218,   224,   215,    -1,    67,   218,   224,   215,    -1,    75,
     218,    99,   215,    -1,    74,   218,    99,   215,    -1,   118,
     218,   159,   215,    -1,    73,   218,    99,   215,    -1,    22,
     218,    99,   215,    -1,    21,   218,    99,   215,    -1,    95,
     218,   159,   215,    -1,    96,   218,   159,   215,    -1,   108,
     218,    99,   215,    -1,   109,   218,   224,   215,    -1,   144,
     217,   494,   216,   215,    -1,   494,   495,    -1,   495,    -1,
     496,    -1,   497,    -1,   499,    -1,   500,    -1,   498,    -1,
     501,    -1,     1,    -1,    37,   218,   159,   215,    -1,    54,
     218,   159,   215,    -1,    52,   218,   117,   215,    -1,    69,
     218,   224,   215,    -1,    51,   218,   159,   215,    -1,    53,
     218,   159,   215,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   355,   355,   356,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   384,   384,   385,   389,
     393,   397,   401,   405,   411,   411,   412,   413,   414,   415,
     422,   425,   425,   426,   426,   426,   428,   434,   441,   443,
     443,   444,   444,   445,   445,   446,   446,   447,   447,   448,
     448,   449,   449,   450,   450,   451,   452,   455,   456,   458,
     458,   459,   465,   473,   473,   474,   480,   488,   527,   586,
     614,   622,   637,   652,   661,   675,   684,   712,   742,   767,
     776,   778,   778,   779,   779,   780,   780,   782,   791,   800,
     812,   813,   813,   815,   815,   816,   818,   825,   825,   838,
     839,   841,   841,   842,   842,   844,   852,   855,   861,   860,
     866,   866,   867,   871,   875,   879,   883,   887,   891,   902,
     901,   981,   981,   982,   982,   982,   983,   983,   983,   984,
     984,   984,   986,   992,   998,  1004,  1015,  1021,  1028,  1027,
    1033,  1033,  1034,  1038,  1042,  1046,  1050,  1054,  1058,  1062,
    1066,  1070,  1074,  1078,  1082,  1086,  1090,  1094,  1098,  1102,
    1106,  1110,  1117,  1116,  1122,  1122,  1123,  1127,  1131,  1135,
    1139,  1143,  1147,  1151,  1155,  1159,  1163,  1167,  1171,  1175,
    1179,  1183,  1187,  1191,  1195,  1206,  1205,  1256,  1256,  1257,
    1258,  1258,  1259,  1260,  1261,  1262,  1263,  1264,  1265,  1266,
    1267,  1267,  1268,  1270,  1276,  1282,  1288,  1294,  1300,  1306,
    1312,  1318,  1324,  1331,  1337,  1343,  1353,  1352,  1359,  1358,
    1363,  1363,  1364,  1368,  1372,  1378,  1378,  1379,  1379,  1379,
    1379,  1379,  1381,  1381,  1383,  1383,  1385,  1399,  1419,  1425,
    1435,  1434,  1476,  1476,  1477,  1477,  1477,  1477,  1478,  1478,
    1478,  1479,  1479,  1481,  1487,  1493,  1499,  1511,  1510,  1516,
    1516,  1517,  1521,  1525,  1529,  1533,  1537,  1541,  1545,  1549,
    1553,  1559,  1573,  1582,  1596,  1595,  1604,  1604,  1605,  1605,
    1605,  1605,  1607,  1613,  1622,  1631,  1633,  1633,  1634,  1634,
    1636,  1652,  1651,  1676,  1676,  1677,  1677,  1677,  1677,  1679,
    1685,  1705,  1704,  1710,  1710,  1711,  1715,  1719,  1723,  1727,
    1731,  1735,  1739,  1743,  1747,  1757,  1756,  1777,  1777,  1778,
    1778,  1778,  1780,  1787,  1786,  1792,  1792,  1793,  1797,  1801,
    1805,  1809,  1813,  1817,  1821,  1825,  1829,  1839,  1838,  1904,
    1904,  1905,  1905,  1905,  1906,  1906,  1907,  1907,  1907,  1908,
    1908,  1908,  1909,  1909,  1910,  1912,  1918,  1924,  1930,  1943,
    1956,  1962,  1966,  1975,  1974,  1979,  1979,  1980,  1984,  1990,
    2001,  2007,  2013,  2019,  2035,  2034,  2097,  2096,  2102,  2102,
    2103,  2109,  2109,  2110,  2110,  2110,  2110,  2112,  2132,  2142,
    2141,  2168,  2168,  2169,  2169,  2169,  2171,  2177,  2186,  2188,
    2188,  2189,  2189,  2191,  2209,  2208,  2254,  2253,  2259,  2259,
    2260,  2266,  2266,  2267,  2267,  2267,  2267,  2269,  2275,  2284,
    2287,  2287,  2288,  2288,  2289,  2289,  2290,  2290,  2291,  2291,
    2292,  2292,  2293,  2294,  2295,  2295,  2296,  2296,  2297,  2297,
    2298,  2298,  2299,  2299,  2300,  2300,  2301,  2302,  2302,  2303,
    2303,  2304,  2304,  2305,  2305,  2306,  2306,  2307,  2308,  2308,
    2309,  2310,  2311,  2311,  2312,  2312,  2313,  2314,  2315,  2316,
    2316,  2317,  2320,  2325,  2331,  2337,  2343,  2348,  2353,  2358,
    2363,  2368,  2373,  2378,  2383,  2388,  2393,  2398,  2403,  2408,
    2413,  2419,  2430,  2435,  2440,  2445,  2450,  2455,  2458,  2463,
    2466,  2471,  2476,  2481,  2486,  2491,  2496,  2501,  2506,  2511,
    2522,  2527,  2532,  2537,  2546,  2555,  2560,  2565,  2571,  2570,
    2575,  2575,  2576,  2579,  2582,  2585,  2588,  2591,  2594,  2597,
    2600,  2603,  2606,  2609,  2612,  2615,  2618,  2621,  2624,  2627,
    2630,  2633,  2639,  2638,  2643,  2643,  2644,  2647,  2650,  2653,
    2656,  2659,  2662,  2665,  2668,  2671,  2674,  2677,  2680,  2683,
    2686,  2689,  2692,  2695,  2698,  2701,  2706,  2711,  2716,  2725,
    2728,  2728,  2729,  2730,  2730,  2731,  2731,  2732,  2732,  2733,
    2734,  2734,  2735,  2736,  2736,  2737,  2737,  2739,  2744,  2749,
    2754,  2759,  2764,  2769,  2774,  2779,  2784,  2789,  2794,  2799,
    2804,  2812,  2815,  2815,  2816,  2816,  2817,  2818,  2818,  2819,
    2820,  2822,  2828,  2834,  2843,  2857,  2863
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
     295,   295,   295,   296,   297,   298,   299,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   310,   309,   312,   311,
     313,   313,   314,   314,   314,   315,   315,   316,   316,   316,
     316,   316,   318,   317,   319,   319,   320,   320,   321,   322,
     324,   323,   325,   325,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   327,   328,   329,   330,   332,   331,   333,
     333,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   335,   336,   337,   339,   338,   340,   340,   341,   341,
     341,   341,   342,   343,   344,   345,   346,   346,   347,   347,
     348,   350,   349,   351,   351,   352,   352,   352,   352,   353,
     354,   356,   355,   357,   357,   358,   358,   358,   358,   358,
     358,   358,   358,   358,   358,   360,   359,   361,   361,   362,
     362,   362,   363,   365,   364,   366,   366,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,   369,   368,   370,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   371,   371,   371,   371,   372,   373,   374,   375,   376,
     377,   378,   378,   380,   379,   381,   381,   382,   382,   383,
     384,   385,   386,   387,   389,   388,   391,   390,   392,   392,
     393,   394,   394,   395,   395,   395,   395,   396,   397,   399,
     398,   400,   400,   401,   401,   401,   402,   403,   404,   405,
     405,   406,   406,   407,   409,   408,   411,   410,   412,   412,
     413,   414,   414,   415,   415,   415,   415,   416,   417,   418,
     419,   419,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   420,
     420,   420,   421,   422,   423,   424,   425,   426,   427,   428,
     429,   430,   431,   432,   433,   434,   435,   436,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   446,   447,
     447,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   466,   465,
     467,   467,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   468,   468,   468,   468,   468,   468,   468,   468,
     468,   468,   470,   469,   471,   471,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   472,   472,   472,   472,
     472,   472,   472,   472,   472,   472,   473,   474,   475,   476,
     477,   477,   478,   478,   478,   478,   478,   478,   478,   478,
     478,   478,   478,   478,   478,   478,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,   488,   489,   490,   491,
     492,   493,   494,   494,   495,   495,   495,   495,   495,   495,
     495,   496,   497,   498,   499,   500,   501
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
       1,     4,     4,     4,     0,     6,     2,     1,     1,     1,
       1,     2,     4,     4,     4,     5,     2,     1,     1,     1,
       4,     0,     6,     2,     1,     1,     1,     1,     2,     4,
       4,     0,     5,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     6,     2,     1,     1,
       1,     2,     4,     0,     5,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     6,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     0,     5,     3,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     0,
       6,     2,     1,     1,     1,     1,     4,     4,     5,     2,
       1,     1,     1,     4,     0,     6,     0,     5,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     0,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     4,     5,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     5,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     1,     0,     0,     0,   195,   347,   399,     0,
     414,     0,   250,   384,   226,     0,     0,   129,   284,     0,
       0,   301,   325,     0,     3,    23,    11,     4,     5,     6,
       8,     9,    10,    13,    14,    15,    16,    17,    18,    19,
      20,    22,    21,     7,    12,    24,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    95,    94,   596,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   581,   595,   591,   583,   584,   585,   586,   587,
     582,   588,   589,   590,   592,   593,   594,     0,     0,     0,
     412,     0,     0,   410,   411,     0,   481,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   552,     0,   528,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   431,   479,   473,
     474,   475,   476,   477,   472,   442,   432,   433,   467,   434,
     435,   436,   437,   438,   439,   440,   441,   469,   443,   444,
     478,   446,   451,   447,   449,   448,   462,   463,   450,   452,
     453,   454,   455,   456,   445,   458,   459,   460,   480,   470,
     471,   468,   461,   457,   465,   466,   464,     0,     0,     0,
       0,     0,     0,   102,   103,   104,     0,     0,     0,     0,
       0,    42,    43,    44,     0,     0,   620,     0,     0,     0,
       0,     0,     0,     0,   613,   614,   615,   618,   616,   617,
     619,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    50,    63,
      64,    62,    59,    58,    65,    51,    61,    54,    55,    56,
      52,    60,    57,    53,     0,     0,   299,     0,     0,   297,
     298,    96,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   580,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   198,   199,
     202,   204,   205,   206,   207,   208,   209,   210,   211,   200,
     201,   203,     0,     0,     0,     0,     0,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   350,   351,   352,
     353,   354,   355,   357,   356,   359,   363,   360,   361,   362,
     358,   405,     0,     0,     0,   402,   403,   404,     0,     0,
     409,   426,     0,     0,   416,   425,     0,   422,   423,   424,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     430,     0,     0,     0,   267,     0,     0,     0,     0,     0,
       0,   253,   254,   255,   256,   261,   257,   258,   259,   260,
     396,     0,   386,     0,   395,     0,   392,   393,   394,     0,
     228,     0,     0,     0,   238,     0,   236,   237,   239,   240,
     105,     0,     0,   101,     0,    45,     0,     0,     0,    41,
       0,     0,     0,   172,     0,     0,     0,   148,     0,     0,
     132,   133,   134,   135,   138,   139,   137,   136,   140,     0,
       0,     0,     0,     0,   287,   288,   289,   290,     0,     0,
       0,     0,     0,     0,     0,   612,    66,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    49,     0,     0,   311,     0,     0,   304,
     305,   306,   307,     0,     0,   333,     0,   328,   329,   330,
       0,     0,   296,     0,     0,     0,    90,     0,     0,     0,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   579,   212,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   197,   364,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   349,     0,     0,     0,   401,     0,
     408,     0,     0,     0,     0,   421,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   429,   262,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   252,     0,
       0,     0,     0,   391,   241,     0,     0,     0,     0,     0,
     235,     0,   100,     0,     0,     0,    40,   141,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   291,     0,
       0,     0,     0,   286,     0,     0,     0,     0,     0,     0,
     611,     0,     0,     0,     0,     0,     0,     0,     0,    71,
      72,     0,    70,    75,    76,     0,    74,     0,     0,     0,
       0,     0,    48,   308,     0,     0,     0,     0,   303,   331,
       0,     0,     0,   327,     0,   295,    99,    98,    97,   606,
     605,   597,    26,    26,    26,    26,    26,    28,    27,   599,
     600,   604,   602,   601,   607,   608,   609,   610,   603,   598,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,   196,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   348,
       0,     0,   400,   413,     0,     0,     0,   415,   494,   498,
     512,   578,   526,   492,   520,   523,   493,   484,   483,   485,
     486,   487,   501,   490,   491,   502,   489,   497,   496,   495,
     521,   482,   519,   576,   577,   516,   513,   563,   556,   573,
     574,   557,   558,   559,   560,   568,   561,   571,   575,   564,
     569,   565,   570,   562,   567,   566,   572,     0,   555,   518,
     538,   532,   549,   550,   533,   534,   535,   536,   544,   537,
     547,   551,   540,   545,   541,   546,   539,   543,   542,   548,
       0,   531,   511,   514,   525,   488,   515,   504,   509,   510,
     507,   508,   505,   506,   500,   499,   524,   527,   517,   522,
     503,     0,     0,     0,     0,     0,     0,     0,     0,   251,
       0,     0,     0,   385,     0,     0,     0,   246,   242,   245,
     227,   106,     0,     0,   118,     0,     0,   110,   111,   113,
     112,    46,    47,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   285,   621,   625,   623,   626,
     622,   624,    83,    89,    81,    85,    84,    78,    77,    79,
      67,     0,    68,     0,    82,    80,    88,    86,    87,     0,
       0,     0,   302,     0,     0,   326,   300,    29,    30,    31,
      32,    33,   223,   224,   216,   218,   220,   219,   217,   213,
     225,   215,   214,    34,    34,    34,    36,    35,   221,   222,
     369,   371,   372,   382,   379,   377,   378,     0,   376,   366,
     380,   381,   365,   370,   368,   383,   367,   406,   407,   427,
     428,   420,     0,   419,   553,     0,   529,     0,   265,   266,
     275,   272,   277,   274,   273,   280,   276,   278,   271,   279,
       0,   270,   264,   283,   282,   281,   263,   398,   390,     0,
     389,   397,   233,   234,   232,     0,   231,   249,   248,     0,
       0,     0,   114,     0,     0,     0,     0,   109,   147,   145,
     187,   184,   183,   176,   178,   194,   188,   191,   186,   177,
     192,   180,   189,   193,   181,   190,   185,   179,   182,     0,
     175,   142,   144,   146,   158,   152,   169,   170,   153,   154,
     155,   156,   164,   157,   167,   171,   160,   165,   161,   166,
     159,   163,   162,   168,     0,   151,   143,   293,   294,   292,
      69,    73,   309,   315,   321,   324,   317,   323,   318,   322,
     320,   316,   319,     0,   314,   310,   332,   337,   343,   346,
     339,   345,   340,   344,   342,   338,   341,     0,   336,    37,
      38,    39,   374,     0,   417,     0,   554,   530,   268,     0,
     387,     0,   229,     0,   247,   244,   243,     0,     0,     0,
       0,   108,   173,     0,   149,     0,   312,     0,   334,     0,
     375,   418,   269,   388,   230,   115,   124,   127,   126,   123,
     128,   125,   122,     0,   121,   117,   116,   174,   150,   313,
     335,   119,     0,   120
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    24,   777,   778,  1016,  1017,    25,   230,   231,
     232,   233,    26,   267,   268,   269,   270,   741,   742,   745,
     746,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,    27,    71,    72,    73,    74,    75,
      28,   222,   223,   224,   225,   226,   946,   947,   948,   949,
     950,  1084,  1213,  1214,    29,    60,   499,   500,   501,   502,
     503,   504,   505,   506,   507,   714,  1134,  1135,   508,   710,
    1109,  1110,    30,    49,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,    31,
      57,   474,   695,  1075,  1076,   475,   476,   477,  1081,   938,
     939,   478,   479,    32,    55,   450,   451,   452,   453,   454,
     455,   456,   681,  1060,  1061,   457,   458,   459,    33,    61,
     513,   514,   515,   516,   517,    34,   288,   289,   290,    35,
      64,   548,   549,   550,   551,   552,   755,  1153,  1154,    36,
      65,   556,   557,   558,   559,   761,  1167,  1168,    37,    50,
     356,   357,   358,   359,   360,   361,   362,   363,   364,   365,
     604,  1027,  1028,   366,   367,   368,   369,   370,    38,    56,
     464,   690,  1069,  1070,   465,   466,   467,   468,    39,    51,
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
#define YYPACT_NINF -678
static const yytype_int16 yypact[] =
{
    -678,   581,  -678,  -132,  -213,  -211,  -678,  -678,  -678,  -200,
    -678,  -194,  -678,  -678,  -678,  -191,  -189,  -678,  -678,  -181,
    -179,  -678,  -678,  -176,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,   285,   812,  -143,
    -106,  -103,    18,   -88,   349,   -79,   -73,   -68,    62,    68,
     -66,   -57,   388,   387,   -43,   -21,    15,  -182,   -16,   -11,
      -9,     8,  -678,  -678,  -678,  -678,  -678,    -4,    59,    71,
      94,    97,   110,   131,   134,   136,   141,   142,   144,   145,
     146,   155,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,   622,   419,    29,
    -678,   147,    44,  -678,  -678,   198,  -678,   148,   158,   163,
     164,   165,   167,   168,   169,   174,   179,   182,   183,   188,
     189,   192,   195,   196,   200,   205,   212,   227,   229,   230,
     232,   243,   246,   248,   249,   250,  -678,   251,  -678,   252,
     254,   255,   256,   263,   264,   267,   268,   271,   273,   274,
     275,   276,   277,   279,   280,   281,    36,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,   448,     4,   257,
      65,   283,    45,  -678,  -678,  -678,    80,    88,   284,   294,
      49,  -678,  -678,  -678,   426,    13,  -678,   295,   302,   303,
     304,   305,   307,     7,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,   187,   308,   309,   310,   311,   312,   314,   316,   318,
     319,   321,   322,   323,   324,   325,   326,    74,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,    11,    28,  -678,   327,    53,  -678,
    -678,  -678,   253,   286,   299,   202,  -678,   384,   447,   390,
     456,   456,   459,   460,   464,   405,   406,   467,   456,   413,
     414,   332,  -678,   359,   357,   358,   361,   365,   366,   369,
     370,   373,   374,   375,   376,   383,   385,   156,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,   362,   392,   393,   394,   395,  -678,   396,   398,
     400,   403,   404,   407,   408,   412,   210,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,   415,   416,    66,  -678,  -678,  -678,   488,   391,
    -678,  -678,   418,   421,  -678,  -678,    39,  -678,  -678,  -678,
     472,   456,   456,   541,   483,   485,   546,   529,   489,   456,
     490,   456,   548,   551,   554,   496,   497,   499,   456,   560,
     562,   456,   563,   564,   547,   566,   568,   509,   511,   454,
     515,   457,   456,   456,   517,   519,   520,   521,   181,   184,
     523,   526,   456,   456,   569,   456,   528,   532,   533,   473,
    -678,   478,   479,   486,  -678,   487,   491,   492,   494,   495,
     199,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,   500,  -678,   501,  -678,    69,  -678,  -678,  -678,   481,
    -678,   502,   506,   513,  -678,    51,  -678,  -678,  -678,  -678,
    -678,   542,   493,  -678,   498,  -678,   585,   589,   512,  -678,
     518,   514,   516,  -678,   525,   535,   538,  -678,   540,    56,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,   531,
     545,   549,   550,    33,  -678,  -678,  -678,  -678,   555,   558,
     590,   576,   591,   456,   536,  -678,  -678,   649,   601,   652,
     653,   655,   656,   662,   669,    46,   213,   670,   672,   695,
     679,   683,   587,  -678,   588,   586,  -678,   598,    20,  -678,
    -678,  -678,  -678,   605,   608,  -678,   152,  -678,  -678,  -678,
     689,   623,  -678,   625,   627,   629,  -678,   630,   631,   632,
     193,   633,   634,   636,   639,   640,   641,   646,   648,   650,
     651,   658,  -678,  -678,   724,   759,   456,   765,   768,   771,
     772,   755,   775,   777,   456,   778,   778,   665,  -678,  -678,
     764,   180,   766,   723,   666,   773,   774,   776,   779,   789,
     780,   781,   782,   674,  -678,   783,   784,   677,  -678,   680,
    -678,   785,   786,   676,   690,  -678,   691,   694,   696,   697,
     698,   699,   700,   701,   702,   703,   704,   707,   708,   709,
     710,   711,   712,   713,   714,   716,   717,   718,   719,   720,
     721,   722,   725,   726,   727,   573,   728,   609,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,  -678,  -678,   787,
     751,   748,   822,   864,   847,   848,   850,   753,  -678,   852,
     752,   854,   757,  -678,  -678,   756,   856,   858,   877,   762,
    -678,   763,  -678,   185,   767,   769,  -678,  -678,   862,   821,
     770,   866,   868,   869,   788,   870,   790,  -678,  -678,   872,
     873,   874,   792,  -678,   793,   794,   795,   796,   797,   798,
    -678,   799,   800,   801,   802,   803,   804,   805,   806,  -678,
    -678,  -204,  -678,  -678,  -678,  -197,  -678,   807,   808,   809,
     810,   811,  -678,  -678,   875,   813,   876,   814,  -678,  -678,
     878,   815,   817,  -678,   819,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,   456,   456,   456,   456,   456,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
     820,   823,   824,   825,   826,   827,   828,   829,   830,   831,
     832,   297,   833,   834,  -678,   835,   836,   837,   838,   839,
       5,   840,   841,   842,   843,   844,   845,   846,   849,  -678,
     851,   853,  -678,  -678,   855,   857,   859,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -195,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -184,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,   860,   861,   537,   863,   865,   867,   871,   879,  -678,
     880,   881,   882,  -678,   -26,   883,   884,   899,   818,  -678,
    -678,  -678,   885,   886,  -678,   887,   129,  -678,  -678,  -678,
    -678,  -678,  -678,   888,   891,   484,   892,   893,   894,   643,
     895,  -678,   896,   897,   898,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,    46,  -678,   213,  -678,  -678,  -678,  -678,  -678,   900,
     657,   901,  -678,   902,   664,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,   778,   778,   778,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -166,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -164,  -678,  -678,   573,  -678,   609,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -147,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -130,
    -678,  -678,  -678,  -678,  -678,   -46,  -678,  -678,  -678,   903,
     877,   904,  -678,   910,   905,   -92,   906,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,    -7,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,    76,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,    82,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,    85,  -678,  -678,
    -678,  -678,  -678,     5,  -678,   859,  -678,  -678,  -678,   537,
    -678,   881,  -678,   -26,  -678,  -678,  -678,   907,   265,   909,
     911,  -678,  -678,   484,  -678,   643,  -678,   657,  -678,   664,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,    95,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,   265,  -678
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -678,  -678,  -678,  -451,  -298,  -677,  -595,  -678,  -678,   890,
    -678,  -678,  -678,  -678,   761,  -678,  -678,  -678,    16,  -678,
      17,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,   923,  -678,  -678,  -678,
    -678,  -678,   908,  -678,  -678,  -678,  -678,    50,  -678,  -678,
    -678,  -678,  -678,  -224,  -678,  -678,  -678,   505,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -196,  -678,  -678,
    -678,  -192,  -678,  -678,  -678,   750,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -153,  -678,   561,  -678,  -678,  -678,
     -17,  -678,  -678,  -678,  -678,  -678,   615,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -112,  -678,  -678,  -678,  -678,  -678,
    -678,   556,  -678,  -678,  -678,  -678,  -678,   791,  -678,  -678,
    -678,  -678,   539,  -678,  -678,  -678,  -678,  -678,  -126,  -678,
    -678,  -678,   527,  -678,  -678,  -678,  -678,  -125,  -678,  -678,
    -678,   758,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -100,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,   -97,  -678,   616,  -678,  -678,  -678,  -678,
    -678,   715,  -678,  -678,  -678,  -678,   973,  -678,  -678,  -678,
    -678,  -678,  -678,   -87,  -678,   705,  -678,  -678,  -678,  -678,
     924,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,    54,  -678,
    -678,  -678,    47,  -678,  -678,  -678,  -678,  -678,  1002,  -678,
    -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,  -678,
    -678,  -678,  -678,  -678,  -678,   889,  -678,  -678,  -678,  -678,
    -678,  -678
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -108
static const yytype_int16 yytable[] =
{
     802,   803,   571,   572,    47,   460,    48,   801,   236,    67,
     579,   980,   544,  1025,   509,   981,   286,    52,   982,   110,
    1044,   544,   983,    54,  1045,  1072,    58,   510,    59,   553,
     371,  1046,    68,   291,   509,  1047,    62,   116,    63,    69,
     381,    66,   117,   118,   237,   110,   220,   510,   119,  1172,
     227,  1174,   469,  1173,   286,  1175,   120,   490,   238,   239,
     240,   241,   121,   220,   122,   123,   124,   371,  1178,   227,
     460,   125,  1179,   491,   107,   251,   242,   126,   127,   111,
     128,   129,   130,    45,    46,  1180,   131,   470,   492,  1181,
     372,   132,   493,   627,   628,   133,   134,    70,   252,   135,
     545,   635,  1189,   637,   287,   111,   511,   471,   136,   545,
     644,   108,   472,   647,   109,   137,   138,   554,   139,   140,
     141,   142,   143,   461,   658,   659,   511,   372,   382,   115,
     942,   253,   512,   144,   670,   671,   228,   673,   217,   145,
     146,   147,   287,   148,   218,   494,   149,   150,   373,   219,
     151,   234,   512,   553,   462,   228,    76,   313,   383,  1073,
     235,   546,   229,   254,  1074,   255,   256,   473,   495,  1182,
     546,   314,   315,  1183,   284,   316,    77,    78,   555,   739,
     740,   229,    79,   152,   496,   373,   942,   153,   461,   384,
     154,   155,   156,   157,   158,  1026,   285,   159,   160,   381,
     441,   257,   292,   258,   259,   260,   261,   293,  1192,   294,
     463,   342,  1193,   343,   297,   344,   442,   547,   943,   462,
     262,    80,    81,   524,   295,   729,   547,   345,    82,    83,
      84,   443,   317,   318,   319,   444,   757,   320,   161,   162,
     163,   554,   346,   164,   263,   321,   347,   497,   165,   722,
      85,    86,   439,   221,   264,   624,   322,   323,   469,  -107,
     379,   482,   498,    87,    88,   488,   348,   699,   349,   561,
     221,   324,   716,    89,   943,   463,  -107,   298,   350,   944,
     480,    90,   617,   265,   266,   692,    67,   382,   792,   299,
     542,  1194,   570,   470,   484,  1195,   800,  1196,   325,   351,
    1198,  1197,   555,   485,  1199,  1206,  1013,  1014,  1015,    68,
    1221,   445,   300,   471,  1222,   301,    69,   383,   472,   446,
     447,   997,   998,   999,  1000,  1001,   352,  1207,   302,  1208,
     772,   773,   774,   775,   776,   944,  1169,  1170,  1171,   326,
     664,   665,   945,   666,   667,  1086,   743,   744,   384,   303,
     116,   448,   304,   353,   305,   117,   118,   806,   807,   306,
     307,   119,   308,   309,   310,   378,   390,  1209,   762,   120,
     563,   311,   597,   473,    70,   121,   391,   122,   123,   124,
     354,   392,   393,   394,   125,   395,   396,   397,   251,   236,
     126,   127,   398,   128,   129,   130,   801,   399,   945,   131,
     400,   401,   526,   564,   132,   449,   402,   403,   133,   134,
     404,   252,   135,   405,   406,   687,   565,   566,   407,   355,
     342,   136,   343,   408,   344,   237,   613,   490,   137,   138,
     409,   139,   140,   141,   142,   143,   345,  1210,  1211,   238,
     239,   240,   241,   491,   253,   410,   144,   411,   412,   441,
     413,   346,   145,   146,   147,   347,   148,   242,   492,   149,
     150,   414,   493,   151,   415,   442,   416,   417,   418,   420,
     422,  1212,   423,   424,   425,   348,   254,   349,   255,   256,
     443,   426,   427,   567,   444,   428,   429,   350,  1090,   430,
    1190,   431,   432,   433,   434,   435,   152,   436,   437,   438,
     153,   481,   486,   154,   155,   156,   157,   158,   351,  1091,
     159,   160,   487,   518,   257,   494,   258,   259,   260,   261,
     519,   520,   521,   522,  1092,   523,   527,   528,   529,   530,
     531,  1093,   532,   262,   533,   352,   534,   535,   495,   536,
     537,   538,   539,   540,   541,   560,   568,   582,  1094,   569,
    1050,   161,   162,   163,   496,   570,   164,   263,   573,   574,
     445,   165,   353,   575,   576,   577,   578,   264,   446,   447,
    1051,  1095,   580,   581,   583,   584,   585,   599,  1096,   586,
    1052,     2,     3,   587,   588,     4,  1053,   589,   590,   354,
    1097,   591,   592,   593,   594,     5,   265,   266,     6,     7,
     448,   595,  1054,   596,     8,   619,   620,  1098,  1099,  1100,
     600,   601,   602,   603,   605,     9,   606,   497,   607,    10,
      11,   608,   609,   313,   857,   610,   611,  1055,   355,    12,
     612,   626,   498,   615,   616,  1056,   621,   314,   315,   622,
     629,   316,   630,    13,   631,   632,   633,   638,   634,   636,
     639,    14,    15,   640,   449,   641,   642,  1101,   643,   645,
     880,   646,   648,   649,   650,   651,  1102,   652,   653,    16,
     654,  1103,   655,  1057,   656,   657,   660,  1104,   661,   662,
     663,  1105,   668,    17,  1106,   669,   672,   674,   677,  1107,
    1058,   675,   676,   678,  1114,  1108,   694,   679,   317,   318,
     319,   701,   704,   320,   680,   682,   705,   726,   702,   683,
     684,   321,   685,   686,   724,   703,    18,   725,   689,   691,
     696,  1143,   322,   323,   697,    19,    20,   706,  1157,    21,
      22,   698,   708,   707,   709,   727,  1059,   324,   858,   859,
     860,   861,   862,   711,   863,   864,   718,   865,   866,   867,
     728,   730,   868,   712,   869,   870,   713,   871,   715,   872,
     732,   873,   874,   719,   325,   875,   731,   720,   721,   733,
     734,   876,   735,   736,   881,   882,   883,   884,   885,   737,
     886,   887,    23,   888,   889,   890,   738,   747,   891,   748,
     892,   893,  1144,   894,   749,   895,   750,   896,   897,  1158,
     751,   898,   752,   753,   754,   326,   764,   899,  1115,  1116,
    1117,  1118,  1119,    76,  1120,  1121,   756,  1122,  1123,  1124,
     759,  1145,  1125,   790,  1126,  1127,   760,  1128,  1159,  1129,
    1146,  1130,  1131,    77,    78,  1132,  1147,  1160,   765,    79,
     766,  1133,   767,  1161,   768,   769,   770,   771,   779,   780,
    1148,   781,  1149,  1150,   782,   783,   784,  1162,   791,  1163,
    1164,   785,  1151,   786,   793,   787,   788,   794,  1152,  1165,
     795,   796,   797,   789,   798,  1166,   799,   801,    80,    81,
     804,   805,   809,   808,   810,    82,    83,    84,   815,   819,
     811,   812,   822,   813,   826,   823,   814,   816,   817,   818,
     820,   821,   824,   825,   921,   827,   828,    85,    86,   829,
     922,   830,   831,   832,   833,   834,   835,   836,   837,   838,
      87,    88,   839,   840,   841,   842,   843,   844,   845,   846,
      89,   847,   848,   849,   850,   851,   852,   853,    90,   924,
     854,   855,   856,   879,   902,   903,   904,   905,   906,   907,
     908,   909,   910,   911,   912,   913,   914,   915,   916,   917,
     918,   919,   920,   925,   926,   927,   923,   928,   929,   930,
     931,   932,   933,   935,   934,   936,   937,   940,   941,   953,
     954,  1041,   951,   956,   952,   957,   958,   960,   955,   962,
     963,   964,   989,   991,   296,   993,  1087,  1140,  1223,  1218,
    1141,  1217,  1184,  1068,   717,   961,   959,   965,   966,   967,
     968,   969,   970,   971,   972,   973,   974,   975,   976,   977,
     978,   979,   984,   985,   986,   987,   988,  1187,   543,   992,
    1204,   990,   995,   994,   996,  1002,   700,  1080,  1003,  1004,
    1005,  1006,  1007,  1008,  1009,  1010,  1011,  1012,  1018,  1019,
    1020,  1021,  1022,  1023,  1024,  1029,  1030,  1031,  1032,  1033,
    1034,  1035,  1079,  1185,  1036,   688,  1037,  1202,  1038,   723,
    1039,  1219,  1040,  1200,  1220,  1048,  1049,   598,  1062,   562,
    1063,   693,  1064,   763,  1203,   380,  1065,   758,  1201,   618,
     440,   625,  1176,   312,  1066,  1067,     0,  1071,  1077,  1078,
    1082,  1177,     0,  1088,  1083,  1085,  1089,  1111,  1112,  1113,
    1136,  1137,  1138,  1139,   614,  1142,  1155,  1156,     0,  1186,
     489,  1191,  1205,  1188,  1215,     0,  1216,     0,     0,     0,
     483,     0,   525
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-678)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
     595,   596,   300,   301,   217,     1,   217,    99,     1,     1,
     308,   215,     1,     8,     1,   219,     1,   217,   215,     1,
     215,     1,   219,   217,   219,    51,   217,    14,   217,     1,
       1,   215,    24,   215,     1,   219,   217,     1,   217,    31,
       1,   217,     6,     7,    37,     1,     1,    14,    12,   215,
       1,   215,     1,   219,     1,   219,    20,     1,    51,    52,
      53,    54,    26,     1,    28,    29,    30,     1,   215,     1,
       1,    35,   219,    17,   217,     1,    69,    41,    42,    61,
      44,    45,    46,   215,   216,   215,    50,    36,    32,   219,
      61,    55,    36,   391,   392,    59,    60,    89,    24,    63,
      89,   399,   194,   401,    89,    61,    93,    56,    72,    89,
     408,   217,    61,   411,   217,    79,    80,    89,    82,    83,
      84,    85,    86,   119,   422,   423,    93,    61,    89,   217,
       1,    57,   119,    97,   432,   433,    87,   435,   217,   103,
     104,   105,    89,   107,   217,    89,   110,   111,   119,   217,
     114,   217,   119,     1,   150,    87,     1,     1,   119,   185,
     217,   150,   113,    89,   190,    91,    92,   116,   112,   215,
     150,    15,    16,   219,   217,    19,    21,    22,   150,   133,
     134,   113,    27,   147,   128,   119,     1,   151,   119,   150,
     154,   155,   156,   157,   158,   190,   217,   161,   162,     1,
       1,   127,   218,   129,   130,   131,   132,   218,   215,   218,
     206,     1,   219,     3,   218,     5,    17,   206,    89,   150,
     146,    66,    67,   216,   216,   523,   206,    17,    73,    74,
      75,    32,    76,    77,    78,    36,   216,    81,   202,   203,
     204,    89,    32,   207,   170,    89,    36,   191,   212,   216,
      95,    96,   216,   208,   180,   216,   100,   101,     1,   214,
     216,   216,   206,   108,   109,   216,    56,   216,    58,   216,
     208,   115,   216,   118,    89,   206,   214,   218,    68,   150,
     215,   126,   216,   209,   210,   216,     1,    89,   586,   218,
     216,   215,    99,    36,   214,   219,   594,   215,   142,    89,
     215,   219,   150,   215,   219,    40,     9,    10,    11,    24,
     215,   112,   218,    56,   219,   218,    31,   119,    61,   120,
     121,   772,   773,   774,   775,   776,   116,    62,   218,    64,
     137,   138,   139,   140,   141,   150,  1013,  1014,  1015,   183,
     159,   160,   213,   159,   160,   216,   133,   134,   150,   218,
       1,   152,   218,   143,   218,     6,     7,   177,   178,   218,
     218,    12,   218,   218,   218,   218,   218,   102,   216,    20,
     117,   216,   216,   116,    89,    26,   218,    28,    29,    30,
     170,   218,   218,   218,    35,   218,   218,   218,     1,     1,
      41,    42,   218,    44,    45,    46,    99,   218,   213,    50,
     218,   218,   215,   117,    55,   206,   218,   218,    59,    60,
     218,    24,    63,   218,   218,   216,   117,   215,   218,   209,
       1,    72,     3,   218,     5,    37,   216,     1,    79,    80,
     218,    82,    83,    84,    85,    86,    17,   172,   173,    51,
      52,    53,    54,    17,    57,   218,    97,   218,   218,     1,
     218,    32,   103,   104,   105,    36,   107,    69,    32,   110,
     111,   218,    36,   114,   218,    17,   218,   218,   218,   218,
     218,   206,   218,   218,   218,    56,    89,    58,    91,    92,
      32,   218,   218,    99,    36,   218,   218,    68,     4,   218,
    1085,   218,   218,   218,   218,   218,   147,   218,   218,   218,
     151,   218,   218,   154,   155,   156,   157,   158,    89,    25,
     161,   162,   218,   218,   127,    89,   129,   130,   131,   132,
     218,   218,   218,   218,    40,   218,   218,   218,   218,   218,
     218,    47,   218,   146,   218,   116,   218,   218,   112,   218,
     218,   218,   218,   218,   218,   218,    99,   215,    64,   159,
      13,   202,   203,   204,   128,    99,   207,   170,    99,    99,
     112,   212,   143,    99,   159,   159,    99,   180,   120,   121,
      33,    87,   159,   159,   215,   218,   218,   215,    94,   218,
      43,     0,     1,   218,   218,     4,    49,   218,   218,   170,
     106,   218,   218,   218,   218,    14,   209,   210,    17,    18,
     152,   218,    65,   218,    23,   117,   215,   123,   124,   125,
     218,   218,   218,   218,   218,    34,   218,   191,   218,    38,
      39,   218,   218,     1,    51,   218,   218,    90,   209,    48,
     218,   159,   206,   218,   218,    98,   218,    15,    16,   218,
      99,    19,   159,    62,   159,    99,   117,    99,   159,   159,
      99,    70,    71,    99,   206,   159,   159,   173,   159,    99,
      51,    99,    99,    99,   117,    99,   182,    99,   159,    88,
     159,   187,   218,   136,   159,   218,   159,   193,   159,   159,
     159,   197,   159,   102,   200,   159,   117,   159,   215,   205,
     153,   159,   159,   215,    51,   211,   215,   218,    76,    77,
      78,   159,   117,    81,   218,   218,   117,   117,   215,   218,
     218,    89,   218,   218,   159,   217,   135,   159,   218,   218,
     218,    64,   100,   101,   218,   144,   145,   215,    64,   148,
     149,   218,   218,   215,   218,   159,   199,   115,   165,   166,
     167,   168,   169,   218,   171,   172,   215,   174,   175,   176,
     159,   215,   179,   218,   181,   182,   218,   184,   218,   186,
     159,   188,   189,   218,   142,   192,   117,   218,   218,   117,
     117,   198,   117,   117,   165,   166,   167,   168,   169,   117,
     171,   172,   201,   174,   175,   176,   117,   117,   179,   117,
     181,   182,   135,   184,    99,   186,   117,   188,   189,   135,
     117,   192,   215,   215,   218,   183,   117,   198,   165,   166,
     167,   168,   169,     1,   171,   172,   218,   174,   175,   176,
     215,   164,   179,    99,   181,   182,   218,   184,   164,   186,
     173,   188,   189,    21,    22,   192,   179,   173,   215,    27,
     215,   198,   215,   179,   215,   215,   215,   215,   215,   215,
     193,   215,   195,   196,   215,   215,   215,   193,    99,   195,
     196,   215,   205,   215,    99,   215,   215,    99,   211,   205,
      99,    99,   117,   215,    99,   211,    99,    99,    66,    67,
     215,   117,   159,   117,   218,    73,    74,    75,    99,   215,
     117,   117,   215,   117,   218,   215,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   215,   215,    95,    96,   215,
     159,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     108,   109,   215,   215,   215,   215,   215,   215,   215,   215,
     118,   215,   215,   215,   215,   215,   215,   215,   126,   117,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,    99,   117,   117,   218,   117,   215,   117,
     218,   117,   215,   117,   218,   117,    99,   215,   215,   117,
     159,   122,   215,   117,   215,   117,   117,   117,   218,   117,
     117,   117,   117,   117,    71,   117,   946,   981,  1222,  1195,
     983,  1193,    99,   122,   499,   215,   218,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   117,   267,   215,
    1183,   218,   215,   218,   215,   215,   475,   219,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   163,  1080,   215,   450,   215,  1179,   215,   513,
     215,  1197,   215,  1173,  1199,   215,   215,   327,   215,   288,
     215,   465,   215,   556,  1181,   112,   215,   548,  1175,   374,
     166,   386,  1045,    91,   215,   215,    -1,   215,   215,   215,
     215,  1047,    -1,   215,   218,   218,   215,   215,   215,   215,
     215,   215,   215,   215,   356,   215,   215,   215,    -1,   215,
     230,   215,   215,   218,   215,    -1,   215,    -1,    -1,    -1,
     222,    -1,   243
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   221,     0,     1,     4,    14,    17,    18,    23,    34,
      38,    39,    48,    62,    70,    71,    88,   102,   135,   144,
     145,   148,   149,   201,   222,   227,   232,   254,   260,   274,
     292,   309,   323,   338,   345,   349,   359,   368,   388,   398,
     404,   408,   418,   476,   493,   215,   216,   217,   217,   293,
     369,   399,   217,   409,   217,   324,   389,   310,   217,   217,
     275,   339,   217,   217,   350,   360,   217,     1,    24,    31,
      89,   255,   256,   257,   258,   259,     1,    21,    22,    27,
      66,    67,    73,    74,    75,    95,    96,   108,   109,   118,
     126,   477,   478,   479,   480,   481,   482,   483,   484,   485,
     486,   487,   488,   489,   490,   491,   492,   217,   217,   217,
       1,    61,   405,   406,   407,   217,     1,     6,     7,    12,
      20,    26,    28,    29,    30,    35,    41,    42,    44,    45,
      46,    50,    55,    59,    60,    63,    72,    79,    80,    82,
      83,    84,    85,    86,    97,   103,   104,   105,   107,   110,
     111,   114,   147,   151,   154,   155,   156,   157,   158,   161,
     162,   202,   203,   204,   207,   212,   419,   420,   421,   422,
     423,   424,   425,   426,   427,   428,   429,   430,   431,   432,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   442,
     443,   444,   445,   446,   447,   448,   449,   450,   451,   452,
     453,   454,   455,   456,   457,   458,   459,   460,   461,   462,
     463,   464,   465,   469,   473,   474,   475,   217,   217,   217,
       1,   208,   261,   262,   263,   264,   265,     1,    87,   113,
     228,   229,   230,   231,   217,   217,     1,    37,    51,    52,
      53,    54,    69,   494,   495,   496,   497,   498,   499,   500,
     501,     1,    24,    57,    89,    91,    92,   127,   129,   130,
     131,   132,   146,   170,   180,   209,   210,   233,   234,   235,
     236,   241,   242,   243,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   253,   217,   217,     1,    89,   346,   347,
     348,   215,   218,   218,   218,   216,   256,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   216,   478,     1,    15,    16,    19,    76,    77,    78,
      81,    89,   100,   101,   115,   142,   183,   294,   295,   296,
     297,   298,   299,   300,   301,   302,   303,   304,   305,   306,
     307,   308,     1,     3,     5,    17,    32,    36,    56,    58,
      68,    89,   116,   143,   170,   209,   370,   371,   372,   373,
     374,   375,   376,   377,   378,   379,   383,   384,   385,   386,
     387,     1,    61,   119,   400,   401,   402,   403,   218,   216,
     406,     1,    89,   119,   150,   410,   414,   415,   416,   417,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   470,
     218,   466,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   216,
     420,     1,    17,    32,    36,   112,   120,   121,   152,   206,
     325,   326,   327,   328,   329,   330,   331,   335,   336,   337,
       1,   119,   150,   206,   390,   394,   395,   396,   397,     1,
      36,    56,    61,   116,   311,   315,   316,   317,   321,   322,
     215,   218,   216,   262,   214,   215,   218,   218,   216,   229,
       1,    17,    32,    36,    89,   112,   128,   191,   206,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   288,     1,
      14,    93,   119,   340,   341,   342,   343,   344,   218,   218,
     218,   218,   218,   218,   216,   495,   215,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   216,   234,     1,    89,   150,   206,   351,   352,
     353,   354,   355,     1,    89,   150,   361,   362,   363,   364,
     218,   216,   347,   117,   117,   117,   215,    99,    99,   159,
      99,   224,   224,    99,    99,    99,   159,   159,    99,   224,
     159,   159,   215,   215,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   216,   295,   215,
     218,   218,   218,   218,   380,   218,   218,   218,   218,   218,
     218,   218,   218,   216,   371,   218,   218,   216,   401,   117,
     215,   218,   218,   411,   216,   415,   159,   224,   224,    99,
     159,   159,    99,   117,   159,   224,   159,   224,    99,    99,
      99,   159,   159,   159,   224,    99,    99,   224,    99,    99,
     117,    99,    99,   159,   159,   218,   159,   218,   224,   224,
     159,   159,   159,   159,   159,   160,   159,   160,   159,   159,
     224,   224,   117,   224,   159,   159,   159,   215,   215,   218,
     218,   332,   218,   218,   218,   218,   218,   216,   326,   218,
     391,   218,   216,   395,   215,   312,   218,   218,   218,   216,
     316,   159,   215,   217,   117,   117,   215,   215,   218,   218,
     289,   218,   218,   218,   285,   218,   216,   277,   215,   218,
     218,   218,   216,   341,   159,   159,   117,   159,   159,   224,
     215,   117,   159,   117,   117,   117,   117,   117,   117,   133,
     134,   237,   238,   133,   134,   239,   240,   117,   117,    99,
     117,   117,   215,   215,   218,   356,   218,   216,   352,   215,
     218,   365,   216,   362,   117,   215,   215,   215,   215,   215,
     215,   215,   137,   138,   139,   140,   141,   223,   224,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
      99,    99,   224,    99,    99,    99,    99,   117,    99,    99,
     224,    99,   226,   226,   215,   117,   177,   178,   117,   159,
     218,   117,   117,   117,   117,    99,   117,   117,   117,   215,
     117,   117,   215,   215,   117,   117,   218,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,    51,   165,   166,
     167,   168,   169,   171,   172,   174,   175,   176,   179,   181,
     182,   184,   186,   188,   189,   192,   198,   471,   472,   215,
      51,   165,   166,   167,   168,   169,   171,   172,   174,   175,
     176,   179,   181,   182,   184,   186,   188,   189,   192,   198,
     467,   468,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   117,   159,   218,   117,    99,   117,   117,   117,   215,
     117,   218,   117,   215,   218,   117,   117,    99,   319,   320,
     215,   215,     1,    89,   150,   213,   266,   267,   268,   269,
     270,   215,   215,   117,   159,   218,   117,   117,   117,   218,
     117,   215,   117,   117,   117,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   219,   215,   219,   215,   215,   215,   215,   215,   117,
     218,   117,   215,   117,   218,   215,   215,   223,   223,   223,
     223,   223,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,     9,    10,    11,   225,   226,   215,   215,
     215,   215,   215,   215,   215,     8,   190,   381,   382,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   122,   412,   413,   215,   219,   215,   219,   215,   215,
      13,    33,    43,    49,    65,    90,    98,   136,   153,   199,
     333,   334,   215,   215,   215,   215,   215,   215,   122,   392,
     393,   215,    51,   185,   190,   313,   314,   215,   215,   163,
     219,   318,   215,   218,   271,   218,   216,   267,   215,   215,
       4,    25,    40,    47,    64,    87,    94,   106,   123,   124,
     125,   173,   182,   187,   193,   197,   200,   205,   211,   290,
     291,   215,   215,   215,    51,   165,   166,   167,   168,   169,
     171,   172,   174,   175,   176,   179,   181,   182,   184,   186,
     188,   189,   192,   198,   286,   287,   215,   215,   215,   215,
     238,   240,   215,    64,   135,   164,   173,   179,   193,   195,
     196,   205,   211,   357,   358,   215,   215,    64,   135,   164,
     173,   179,   193,   195,   196,   205,   211,   366,   367,   225,
     225,   225,   215,   219,   215,   219,   472,   468,   215,   219,
     215,   219,   215,   219,    99,   320,   215,   117,   218,   194,
     226,   215,   215,   219,   215,   219,   215,   219,   215,   219,
     382,   413,   334,   393,   314,   215,    40,    62,    64,   102,
     172,   173,   206,   272,   273,   215,   215,   291,   287,   358,
     367,   215,   219,   273
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
#line 384 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 386 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number);
		}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 390 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number);
		}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 394 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 398 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 402 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 406 "conf_parser.y"
    {
			(yyval.number) = (yyvsp[(1) - (3)].number) * 60 * 60 * 24 * 7 + (yyvsp[(3) - (3)].number);
		}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 411 "conf_parser.y"
    { (yyval.number) = 0; }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 412 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (2)].number) + (yyvsp[(2) - (2)].number); }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 413 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) + (yyvsp[(3) - (3)].number); }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 414 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 415 "conf_parser.y"
    { (yyval.number) = (yyvsp[(1) - (3)].number) * 1024 * 1024 + (yyvsp[(3) - (3)].number); }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 429 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    add_conf_module(libio_basename(yylval.string));
}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    mod_add_path(yylval.string);
}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 460 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 466 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.client_ctx)
    SSL_CTX_clear_options(ServerInfo.client_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 475 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_SSLv3);
#endif
}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 481 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_clear_options(ServerInfo.server_ctx, SSL_OP_NO_TLSv1);
#endif
}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 489 "conf_parser.y"
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
/* Line 1792 of yacc.c  */
#line 528 "conf_parser.y"
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

  case 79:
/* Line 1792 of yacc.c  */
#line 587 "conf_parser.y"
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
/* Line 1792 of yacc.c  */
#line 615 "conf_parser.y"
    {
#ifdef HAVE_LIBCRYPTO
  if (conf_parser_ctx.pass == 2 && ServerInfo.server_ctx)
    SSL_CTX_set_cipher_list(ServerInfo.server_ctx, yylval.string);
#endif
}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 623 "conf_parser.y"
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

  case 82:
/* Line 1792 of yacc.c  */
#line 638 "conf_parser.y"
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

  case 83:
/* Line 1792 of yacc.c  */
#line 653 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.description);
    ServerInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 662 "conf_parser.y"
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

  case 85:
/* Line 1792 of yacc.c  */
#line 676 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ServerInfo.network_desc);
    ServerInfo.network_desc = xstrdup(yylval.string);
  }
}
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 685 "conf_parser.y"
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
/* Line 1792 of yacc.c  */
#line 713 "conf_parser.y"
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
/* Line 1792 of yacc.c  */
#line 743 "conf_parser.y"
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

  case 89:
/* Line 1792 of yacc.c  */
#line 768 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ServerInfo.hub = yylval.number;
}
    break;

  case 97:
/* Line 1792 of yacc.c  */
#line 783 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.name);
    AdminInfo.name = xstrdup(yylval.string);
  }
}
    break;

  case 98:
/* Line 1792 of yacc.c  */
#line 792 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.email);
    AdminInfo.email = xstrdup(yylval.string);
  }
}
    break;

  case 99:
/* Line 1792 of yacc.c  */
#line 801 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(AdminInfo.description);
    AdminInfo.description = xstrdup(yylval.string);
  }
}
    break;

  case 106:
/* Line 1792 of yacc.c  */
#line 819 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigLoggingEntry.use_logging = yylval.number;
}
    break;

  case 107:
/* Line 1792 of yacc.c  */
#line 825 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 108:
/* Line 1792 of yacc.c  */
#line 829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (block_state.type.value && block_state.file.buf[0])
    log_add_file(block_state.type.value, block_state.size.value,
                 block_state.file.buf);
}
    break;

  case 115:
/* Line 1792 of yacc.c  */
#line 845 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 116:
/* Line 1792 of yacc.c  */
#line 853 "conf_parser.y"
    {
  block_state.size.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 117:
/* Line 1792 of yacc.c  */
#line 856 "conf_parser.y"
    {
  block_state.size.value = 0;
}
    break;

  case 118:
/* Line 1792 of yacc.c  */
#line 861 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = 0;
}
    break;

  case 122:
/* Line 1792 of yacc.c  */
#line 868 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_USER;
}
    break;

  case 123:
/* Line 1792 of yacc.c  */
#line 872 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_OPER;
}
    break;

  case 124:
/* Line 1792 of yacc.c  */
#line 876 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_GLINE;
}
    break;

  case 125:
/* Line 1792 of yacc.c  */
#line 880 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DLINE;
}
    break;

  case 126:
/* Line 1792 of yacc.c  */
#line 884 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KLINE;
}
    break;

  case 127:
/* Line 1792 of yacc.c  */
#line 888 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_KILL;
}
    break;

  case 128:
/* Line 1792 of yacc.c  */
#line 892 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.type.value = LOG_TYPE_DEBUG;
}
    break;

  case 129:
/* Line 1792 of yacc.c  */
#line 902 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.flags.value |= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 130:
/* Line 1792 of yacc.c  */
#line 909 "conf_parser.y"
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
      {
        yyerror("Ignoring rsa_public_key_file -- Key invalid; check key syntax.");
        break;
      }

      conf->rsa_public_key = pkey;
      BIO_set_close(file, BIO_CLOSE);
      BIO_free(file);
    }
#endif /* HAVE_LIBCRYPTO */
  }
}
    break;

  case 142:
/* Line 1792 of yacc.c  */
#line 987 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 143:
/* Line 1792 of yacc.c  */
#line 993 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 144:
/* Line 1792 of yacc.c  */
#line 999 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 145:
/* Line 1792 of yacc.c  */
#line 1005 "conf_parser.y"
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

  case 146:
/* Line 1792 of yacc.c  */
#line 1016 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.file.buf, yylval.string, sizeof(block_state.file.buf));
}
    break;

  case 147:
/* Line 1792 of yacc.c  */
#line 1022 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 148:
/* Line 1792 of yacc.c  */
#line 1028 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value = 0;
}
    break;

  case 152:
/* Line 1792 of yacc.c  */
#line 1035 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_BOTS;
}
    break;

  case 153:
/* Line 1792 of yacc.c  */
#line 1039 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN;
}
    break;

  case 154:
/* Line 1792 of yacc.c  */
#line 1043 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CCONN_FULL;
}
    break;

  case 155:
/* Line 1792 of yacc.c  */
#line 1047 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEAF;
}
    break;

  case 156:
/* Line 1792 of yacc.c  */
#line 1051 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_DEBUG;
}
    break;

  case 157:
/* Line 1792 of yacc.c  */
#line 1055 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_FULL;
}
    break;

  case 158:
/* Line 1792 of yacc.c  */
#line 1059 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_HIDDEN;
}
    break;

  case 159:
/* Line 1792 of yacc.c  */
#line 1063 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SKILL;
}
    break;

  case 160:
/* Line 1792 of yacc.c  */
#line 1067 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_NCHANGE;
}
    break;

  case 161:
/* Line 1792 of yacc.c  */
#line 1071 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_REJ;
}
    break;

  case 162:
/* Line 1792 of yacc.c  */
#line 1075 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_UNAUTH;
}
    break;

  case 163:
/* Line 1792 of yacc.c  */
#line 1079 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SPY;
}
    break;

  case 164:
/* Line 1792 of yacc.c  */
#line 1083 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_EXTERNAL;
}
    break;

  case 165:
/* Line 1792 of yacc.c  */
#line 1087 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_OPERWALL;
}
    break;

  case 166:
/* Line 1792 of yacc.c  */
#line 1091 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SERVNOTICE;
}
    break;

  case 167:
/* Line 1792 of yacc.c  */
#line 1095 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_INVISIBLE;
}
    break;

  case 168:
/* Line 1792 of yacc.c  */
#line 1099 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_WALLOP;
}
    break;

  case 169:
/* Line 1792 of yacc.c  */
#line 1103 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_SOFTCALLERID;
}
    break;

  case 170:
/* Line 1792 of yacc.c  */
#line 1107 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_CALLERID;
}
    break;

  case 171:
/* Line 1792 of yacc.c  */
#line 1111 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.modes.value |= UMODE_LOCOPS;
}
    break;

  case 172:
/* Line 1792 of yacc.c  */
#line 1117 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 176:
/* Line 1792 of yacc.c  */
#line 1124 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBAL_KILL;
}
    break;

  case 177:
/* Line 1792 of yacc.c  */
#line 1128 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTE;
}
    break;

  case 178:
/* Line 1792 of yacc.c  */
#line 1132 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_K;
}
    break;

  case 179:
/* Line 1792 of yacc.c  */
#line 1136 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNKLINE;
}
    break;

  case 180:
/* Line 1792 of yacc.c  */
#line 1140 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DLINE;
}
    break;

  case 181:
/* Line 1792 of yacc.c  */
#line 1144 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_UNDLINE;
}
    break;

  case 182:
/* Line 1792 of yacc.c  */
#line 1148 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_X;
}
    break;

  case 183:
/* Line 1792 of yacc.c  */
#line 1152 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLINE;
}
    break;

  case 184:
/* Line 1792 of yacc.c  */
#line 1156 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_DIE;
}
    break;

  case 185:
/* Line 1792 of yacc.c  */
#line 1160 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_RESTART;
}
    break;

  case 186:
/* Line 1792 of yacc.c  */
#line 1164 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REHASH;
}
    break;

  case 187:
/* Line 1792 of yacc.c  */
#line 1168 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_ADMIN;
}
    break;

  case 188:
/* Line 1792 of yacc.c  */
#line 1172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_N;
}
    break;

  case 189:
/* Line 1792 of yacc.c  */
#line 1176 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPERWALL;
}
    break;

  case 190:
/* Line 1792 of yacc.c  */
#line 1180 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_GLOBOPS;
}
    break;

  case 191:
/* Line 1792 of yacc.c  */
#line 1184 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_OPER_SPY;
}
    break;

  case 192:
/* Line 1792 of yacc.c  */
#line 1188 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_REMOTEBAN;
}
    break;

  case 193:
/* Line 1792 of yacc.c  */
#line 1192 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_SET;
}
    break;

  case 194:
/* Line 1792 of yacc.c  */
#line 1196 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value |= OPER_FLAG_MODULE;
}
    break;

  case 195:
/* Line 1792 of yacc.c  */
#line 1206 "conf_parser.y"
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

  case 196:
/* Line 1792 of yacc.c  */
#line 1219 "conf_parser.y"
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

  case 213:
/* Line 1792 of yacc.c  */
#line 1271 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 214:
/* Line 1792 of yacc.c  */
#line 1277 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.ping_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 215:
/* Line 1792 of yacc.c  */
#line 1283 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_perip.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 216:
/* Line 1792 of yacc.c  */
#line 1289 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.con_freq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 217:
/* Line 1792 of yacc.c  */
#line 1295 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_total.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 218:
/* Line 1792 of yacc.c  */
#line 1301 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_global.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 219:
/* Line 1792 of yacc.c  */
#line 1307 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_local.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 220:
/* Line 1792 of yacc.c  */
#line 1313 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_ident.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 221:
/* Line 1792 of yacc.c  */
#line 1319 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.max_sendq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 222:
/* Line 1792 of yacc.c  */
#line 1325 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    if ((yyvsp[(3) - (4)].number) >= CLIENT_FLOOD_MIN && (yyvsp[(3) - (4)].number) <= CLIENT_FLOOD_MAX)
      block_state.max_recvq.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 223:
/* Line 1792 of yacc.c  */
#line 1332 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv4.value = (yyvsp[(3) - (4)].number) > 32 ? 32 : (yyvsp[(3) - (4)].number);
}
    break;

  case 224:
/* Line 1792 of yacc.c  */
#line 1338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.cidr_bitlen_ipv6.value = (yyvsp[(3) - (4)].number) > 128 ? 128 : (yyvsp[(3) - (4)].number);
}
    break;

  case 225:
/* Line 1792 of yacc.c  */
#line 1344 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 1)
    block_state.number_per_cidr.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 226:
/* Line 1792 of yacc.c  */
#line 1353 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 228:
/* Line 1792 of yacc.c  */
#line 1359 "conf_parser.y"
    {
  block_state.flags.value = 0;
}
    break;

  case 232:
/* Line 1792 of yacc.c  */
#line 1365 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_SSL;
}
    break;

  case 233:
/* Line 1792 of yacc.c  */
#line 1369 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= LISTENER_HIDDEN;
}
    break;

  case 234:
/* Line 1792 of yacc.c  */
#line 1373 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
   block_state.flags.value |= LISTENER_SERVER;
}
    break;

  case 242:
/* Line 1792 of yacc.c  */
#line 1381 "conf_parser.y"
    { block_state.flags.value = 0; }
    break;

  case 246:
/* Line 1792 of yacc.c  */
#line 1386 "conf_parser.y"
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

  case 247:
/* Line 1792 of yacc.c  */
#line 1400 "conf_parser.y"
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

  case 248:
/* Line 1792 of yacc.c  */
#line 1420 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 249:
/* Line 1792 of yacc.c  */
#line 1426 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 250:
/* Line 1792 of yacc.c  */
#line 1435 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 251:
/* Line 1792 of yacc.c  */
#line 1439 "conf_parser.y"
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

  case 263:
/* Line 1792 of yacc.c  */
#line 1482 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.mask.list);
}
    break;

  case 264:
/* Line 1792 of yacc.c  */
#line 1488 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 265:
/* Line 1792 of yacc.c  */
#line 1494 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 266:
/* Line 1792 of yacc.c  */
#line 1500 "conf_parser.y"
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

  case 267:
/* Line 1792 of yacc.c  */
#line 1511 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 271:
/* Line 1792 of yacc.c  */
#line 1518 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SPOOF_NOTICE;
}
    break;

  case 272:
/* Line 1792 of yacc.c  */
#line 1522 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NOLIMIT;
}
    break;

  case 273:
/* Line 1792 of yacc.c  */
#line 1526 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTKLINE;
}
    break;

  case 274:
/* Line 1792 of yacc.c  */
#line 1530 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_IDENTD;
}
    break;

  case 275:
/* Line 1792 of yacc.c  */
#line 1534 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_CAN_FLOOD;
}
    break;

  case 276:
/* Line 1792 of yacc.c  */
#line 1538 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NO_TILDE;
}
    break;

  case 277:
/* Line 1792 of yacc.c  */
#line 1542 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTGLINE;
}
    break;

  case 278:
/* Line 1792 of yacc.c  */
#line 1546 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_EXEMPTRESV;
}
    break;

  case 279:
/* Line 1792 of yacc.c  */
#line 1550 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_WEBIRC;
}
    break;

  case 280:
/* Line 1792 of yacc.c  */
#line 1554 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_NEED_PASSWORD;
}
    break;

  case 281:
/* Line 1792 of yacc.c  */
#line 1560 "conf_parser.y"
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

  case 282:
/* Line 1792 of yacc.c  */
#line 1574 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
  block_state.flags.value |= CONF_FLAGS_REDIR;
}
    break;

  case 283:
/* Line 1792 of yacc.c  */
#line 1583 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  block_state.flags.value |= CONF_FLAGS_REDIR;
  block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 284:
/* Line 1792 of yacc.c  */
#line 1596 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  strlcpy(block_state.rpass.buf, CONF_NOREASON, sizeof(block_state.rpass.buf));
}
    break;

  case 292:
/* Line 1792 of yacc.c  */
#line 1608 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 293:
/* Line 1792 of yacc.c  */
#line 1614 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  if (IsChanPrefix(*yylval.string))
    create_channel_resv(yylval.string, block_state.rpass.buf, 1);
}
    break;

  case 294:
/* Line 1792 of yacc.c  */
#line 1623 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    create_nick_resv(yylval.string, block_state.rpass.buf, 1);
}
    break;

  case 300:
/* Line 1792 of yacc.c  */
#line 1637 "conf_parser.y"
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

  case 301:
/* Line 1792 of yacc.c  */
#line 1652 "conf_parser.y"
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

  case 302:
/* Line 1792 of yacc.c  */
#line 1663 "conf_parser.y"
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

  case 309:
/* Line 1792 of yacc.c  */
#line 1680 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 310:
/* Line 1792 of yacc.c  */
#line 1686 "conf_parser.y"
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

  case 311:
/* Line 1792 of yacc.c  */
#line 1705 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 315:
/* Line 1792 of yacc.c  */
#line 1712 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 316:
/* Line 1792 of yacc.c  */
#line 1716 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 317:
/* Line 1792 of yacc.c  */
#line 1720 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 318:
/* Line 1792 of yacc.c  */
#line 1724 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 319:
/* Line 1792 of yacc.c  */
#line 1728 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 320:
/* Line 1792 of yacc.c  */
#line 1732 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 321:
/* Line 1792 of yacc.c  */
#line 1736 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 322:
/* Line 1792 of yacc.c  */
#line 1740 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 323:
/* Line 1792 of yacc.c  */
#line 1744 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 324:
/* Line 1792 of yacc.c  */
#line 1748 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 325:
/* Line 1792 of yacc.c  */
#line 1757 "conf_parser.y"
    {
  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();

  strlcpy(block_state.name.buf, "*", sizeof(block_state.name.buf));
  block_state.flags.value = SHARED_ALL;
}
    break;

  case 326:
/* Line 1792 of yacc.c  */
#line 1766 "conf_parser.y"
    {
  struct MaskItem *conf = NULL;

  if (conf_parser_ctx.pass != 2)
    break;

  conf = conf_make(CONF_CLUSTER);
  conf->flags = block_state.flags.value;
  conf->name = xstrdup(block_state.name.buf);
}
    break;

  case 332:
/* Line 1792 of yacc.c  */
#line 1781 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 333:
/* Line 1792 of yacc.c  */
#line 1787 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = 0;
}
    break;

  case 337:
/* Line 1792 of yacc.c  */
#line 1794 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_KLINE;
}
    break;

  case 338:
/* Line 1792 of yacc.c  */
#line 1798 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNKLINE;
}
    break;

  case 339:
/* Line 1792 of yacc.c  */
#line 1802 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_DLINE;
}
    break;

  case 340:
/* Line 1792 of yacc.c  */
#line 1806 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNDLINE;
}
    break;

  case 341:
/* Line 1792 of yacc.c  */
#line 1810 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_XLINE;
}
    break;

  case 342:
/* Line 1792 of yacc.c  */
#line 1814 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNXLINE;
}
    break;

  case 343:
/* Line 1792 of yacc.c  */
#line 1818 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_RESV;
}
    break;

  case 344:
/* Line 1792 of yacc.c  */
#line 1822 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_UNRESV;
}
    break;

  case 345:
/* Line 1792 of yacc.c  */
#line 1826 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= SHARED_LOCOPS;
}
    break;

  case 346:
/* Line 1792 of yacc.c  */
#line 1830 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value = SHARED_ALL;
}
    break;

  case 347:
/* Line 1792 of yacc.c  */
#line 1839 "conf_parser.y"
    {

  if (conf_parser_ctx.pass != 2)
    break;

  reset_block_state();
  block_state.port.value = PORTNUM;
}
    break;

  case 348:
/* Line 1792 of yacc.c  */
#line 1847 "conf_parser.y"
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

  case 365:
/* Line 1792 of yacc.c  */
#line 1913 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 366:
/* Line 1792 of yacc.c  */
#line 1919 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.host.buf, yylval.string, sizeof(block_state.host.buf));
}
    break;

  case 367:
/* Line 1792 of yacc.c  */
#line 1925 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.bind.buf, yylval.string, sizeof(block_state.bind.buf));
}
    break;

  case 368:
/* Line 1792 of yacc.c  */
#line 1931 "conf_parser.y"
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

  case 369:
/* Line 1792 of yacc.c  */
#line 1944 "conf_parser.y"
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

  case 370:
/* Line 1792 of yacc.c  */
#line 1957 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = (yyvsp[(3) - (4)].number);
}
    break;

  case 371:
/* Line 1792 of yacc.c  */
#line 1963 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET;
}
    break;

  case 372:
/* Line 1792 of yacc.c  */
#line 1967 "conf_parser.y"
    {
#ifdef IPV6
  if (conf_parser_ctx.pass == 2)
    block_state.aftype.value = AF_INET6;
#endif
}
    break;

  case 373:
/* Line 1792 of yacc.c  */
#line 1975 "conf_parser.y"
    {
  block_state.flags.value &= CONF_FLAGS_ENCRYPTED;
}
    break;

  case 377:
/* Line 1792 of yacc.c  */
#line 1981 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_ALLOW_AUTO_CONN;
}
    break;

  case 378:
/* Line 1792 of yacc.c  */
#line 1985 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.flags.value |= CONF_FLAGS_SSL;
}
    break;

  case 379:
/* Line 1792 of yacc.c  */
#line 1991 "conf_parser.y"
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

  case 380:
/* Line 1792 of yacc.c  */
#line 2002 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.hub.list);
}
    break;

  case 381:
/* Line 1792 of yacc.c  */
#line 2008 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    dlinkAdd(xstrdup(yylval.string), make_dlink_node(), &block_state.leaf.list);
}
    break;

  case 382:
/* Line 1792 of yacc.c  */
#line 2014 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.class.buf, yylval.string, sizeof(block_state.class.buf));
}
    break;

  case 383:
/* Line 1792 of yacc.c  */
#line 2020 "conf_parser.y"
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

  case 384:
/* Line 1792 of yacc.c  */
#line 2035 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 385:
/* Line 1792 of yacc.c  */
#line 2039 "conf_parser.y"
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

  case 386:
/* Line 1792 of yacc.c  */
#line 2097 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 390:
/* Line 1792 of yacc.c  */
#line 2104 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 397:
/* Line 1792 of yacc.c  */
#line 2113 "conf_parser.y"
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

  case 398:
/* Line 1792 of yacc.c  */
#line 2133 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 399:
/* Line 1792 of yacc.c  */
#line 2142 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 400:
/* Line 1792 of yacc.c  */
#line 2146 "conf_parser.y"
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

  case 406:
/* Line 1792 of yacc.c  */
#line 2172 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.addr.buf, yylval.string, sizeof(block_state.addr.buf));
}
    break;

  case 407:
/* Line 1792 of yacc.c  */
#line 2178 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 413:
/* Line 1792 of yacc.c  */
#line 2192 "conf_parser.y"
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

  case 414:
/* Line 1792 of yacc.c  */
#line 2209 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    reset_block_state();
}
    break;

  case 415:
/* Line 1792 of yacc.c  */
#line 2213 "conf_parser.y"
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

  case 416:
/* Line 1792 of yacc.c  */
#line 2254 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 0;
}
    break;

  case 420:
/* Line 1792 of yacc.c  */
#line 2261 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    block_state.port.value = 1;
}
    break;

  case 427:
/* Line 1792 of yacc.c  */
#line 2270 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.name.buf, yylval.string, sizeof(block_state.name.buf));
}
    break;

  case 428:
/* Line 1792 of yacc.c  */
#line 2276 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    strlcpy(block_state.rpass.buf, yylval.string, sizeof(block_state.rpass.buf));
}
    break;

  case 482:
/* Line 1792 of yacc.c  */
#line 2321 "conf_parser.y"
    {
  ConfigFileEntry.max_watch = (yyvsp[(3) - (4)].number);
}
    break;

  case 483:
/* Line 1792 of yacc.c  */
#line 2326 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.glines = yylval.number;
}
    break;

  case 484:
/* Line 1792 of yacc.c  */
#line 2332 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 485:
/* Line 1792 of yacc.c  */
#line 2338 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.gline_request_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 486:
/* Line 1792 of yacc.c  */
#line 2344 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr = (yyvsp[(3) - (4)].number);
}
    break;

  case 487:
/* Line 1792 of yacc.c  */
#line 2349 "conf_parser.y"
    {
  ConfigFileEntry.gline_min_cidr6 = (yyvsp[(3) - (4)].number);
}
    break;

  case 488:
/* Line 1792 of yacc.c  */
#line 2354 "conf_parser.y"
    {
  ConfigFileEntry.tkline_expire_notices = yylval.number;
}
    break;

  case 489:
/* Line 1792 of yacc.c  */
#line 2359 "conf_parser.y"
    {
  ConfigFileEntry.kill_chase_time_limit = (yyvsp[(3) - (4)].number);
}
    break;

  case 490:
/* Line 1792 of yacc.c  */
#line 2364 "conf_parser.y"
    {
  ConfigFileEntry.hide_spoof_ips = yylval.number;
}
    break;

  case 491:
/* Line 1792 of yacc.c  */
#line 2369 "conf_parser.y"
    {
  ConfigFileEntry.ignore_bogus_ts = yylval.number;
}
    break;

  case 492:
/* Line 1792 of yacc.c  */
#line 2374 "conf_parser.y"
    {
  ConfigFileEntry.disable_remote = yylval.number;
}
    break;

  case 493:
/* Line 1792 of yacc.c  */
#line 2379 "conf_parser.y"
    {
  ConfigFileEntry.failed_oper_notice = yylval.number;
}
    break;

  case 494:
/* Line 1792 of yacc.c  */
#line 2384 "conf_parser.y"
    {
  ConfigFileEntry.anti_nick_flood = yylval.number;
}
    break;

  case 495:
/* Line 1792 of yacc.c  */
#line 2389 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_time = (yyvsp[(3) - (4)].number); 
}
    break;

  case 496:
/* Line 1792 of yacc.c  */
#line 2394 "conf_parser.y"
    {
  ConfigFileEntry.max_nick_changes = (yyvsp[(3) - (4)].number);
}
    break;

  case 497:
/* Line 1792 of yacc.c  */
#line 2399 "conf_parser.y"
    {
  ConfigFileEntry.max_accept = (yyvsp[(3) - (4)].number);
}
    break;

  case 498:
/* Line 1792 of yacc.c  */
#line 2404 "conf_parser.y"
    {
  ConfigFileEntry.anti_spam_exit_message_time = (yyvsp[(3) - (4)].number);
}
    break;

  case 499:
/* Line 1792 of yacc.c  */
#line 2409 "conf_parser.y"
    {
  ConfigFileEntry.ts_warn_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 500:
/* Line 1792 of yacc.c  */
#line 2414 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigFileEntry.ts_max_delta = (yyvsp[(3) - (4)].number);
}
    break;

  case 501:
/* Line 1792 of yacc.c  */
#line 2420 "conf_parser.y"
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

  case 502:
/* Line 1792 of yacc.c  */
#line 2431 "conf_parser.y"
    {
  ConfigFileEntry.invisible_on_connect = yylval.number;
}
    break;

  case 503:
/* Line 1792 of yacc.c  */
#line 2436 "conf_parser.y"
    {
  ConfigFileEntry.warn_no_nline = yylval.number;
}
    break;

  case 504:
/* Line 1792 of yacc.c  */
#line 2441 "conf_parser.y"
    {
  ConfigFileEntry.stats_e_disabled = yylval.number;
}
    break;

  case 505:
/* Line 1792 of yacc.c  */
#line 2446 "conf_parser.y"
    {
  ConfigFileEntry.stats_o_oper_only = yylval.number;
}
    break;

  case 506:
/* Line 1792 of yacc.c  */
#line 2451 "conf_parser.y"
    {
  ConfigFileEntry.stats_P_oper_only = yylval.number;
}
    break;

  case 507:
/* Line 1792 of yacc.c  */
#line 2456 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 2 * yylval.number;
}
    break;

  case 508:
/* Line 1792 of yacc.c  */
#line 2459 "conf_parser.y"
    {
  ConfigFileEntry.stats_k_oper_only = 1;
}
    break;

  case 509:
/* Line 1792 of yacc.c  */
#line 2464 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 2 * yylval.number;
}
    break;

  case 510:
/* Line 1792 of yacc.c  */
#line 2467 "conf_parser.y"
    {
  ConfigFileEntry.stats_i_oper_only = 1;
}
    break;

  case 511:
/* Line 1792 of yacc.c  */
#line 2472 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 512:
/* Line 1792 of yacc.c  */
#line 2477 "conf_parser.y"
    {
  ConfigFileEntry.caller_id_wait = (yyvsp[(3) - (4)].number);
}
    break;

  case 513:
/* Line 1792 of yacc.c  */
#line 2482 "conf_parser.y"
    {
  ConfigFileEntry.opers_bypass_callerid = yylval.number;
}
    break;

  case 514:
/* Line 1792 of yacc.c  */
#line 2487 "conf_parser.y"
    {
  ConfigFileEntry.pace_wait_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 515:
/* Line 1792 of yacc.c  */
#line 2492 "conf_parser.y"
    {
  ConfigFileEntry.short_motd = yylval.number;
}
    break;

  case 516:
/* Line 1792 of yacc.c  */
#line 2497 "conf_parser.y"
    {
  ConfigFileEntry.no_oper_flood = yylval.number;
}
    break;

  case 517:
/* Line 1792 of yacc.c  */
#line 2502 "conf_parser.y"
    {
  ConfigFileEntry.true_no_oper_flood = yylval.number;
}
    break;

  case 518:
/* Line 1792 of yacc.c  */
#line 2507 "conf_parser.y"
    {
  ConfigFileEntry.oper_pass_resv = yylval.number;
}
    break;

  case 519:
/* Line 1792 of yacc.c  */
#line 2512 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    if (strlen(yylval.string) > LOCALE_LENGTH-2)
      yylval.string[LOCALE_LENGTH-1] = '\0';

    set_locale(yylval.string);
  }
}
    break;

  case 520:
/* Line 1792 of yacc.c  */
#line 2523 "conf_parser.y"
    {
  ConfigFileEntry.dots_in_ident = (yyvsp[(3) - (4)].number);
}
    break;

  case 521:
/* Line 1792 of yacc.c  */
#line 2528 "conf_parser.y"
    {
  ConfigFileEntry.max_targets = (yyvsp[(3) - (4)].number);
}
    break;

  case 522:
/* Line 1792 of yacc.c  */
#line 2533 "conf_parser.y"
    {
  ConfigFileEntry.use_egd = yylval.number;
}
    break;

  case 523:
/* Line 1792 of yacc.c  */
#line 2538 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigFileEntry.egdpool_path);
    ConfigFileEntry.egdpool_path = xstrdup(yylval.string);
  }
}
    break;

  case 524:
/* Line 1792 of yacc.c  */
#line 2547 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2 && valid_servname(yylval.string))
  {
    MyFree(ConfigFileEntry.service_name);
    ConfigFileEntry.service_name = xstrdup(yylval.string);
  }
}
    break;

  case 525:
/* Line 1792 of yacc.c  */
#line 2556 "conf_parser.y"
    {
  ConfigFileEntry.ping_cookie = yylval.number;
}
    break;

  case 526:
/* Line 1792 of yacc.c  */
#line 2561 "conf_parser.y"
    {
  ConfigFileEntry.disable_auth = yylval.number;
}
    break;

  case 527:
/* Line 1792 of yacc.c  */
#line 2566 "conf_parser.y"
    {
  ConfigFileEntry.throttle_time = yylval.number;
}
    break;

  case 528:
/* Line 1792 of yacc.c  */
#line 2571 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes = 0;
}
    break;

  case 532:
/* Line 1792 of yacc.c  */
#line 2577 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_BOTS;
}
    break;

  case 533:
/* Line 1792 of yacc.c  */
#line 2580 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN;
}
    break;

  case 534:
/* Line 1792 of yacc.c  */
#line 2583 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 535:
/* Line 1792 of yacc.c  */
#line 2586 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEAF;
}
    break;

  case 536:
/* Line 1792 of yacc.c  */
#line 2589 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_DEBUG;
}
    break;

  case 537:
/* Line 1792 of yacc.c  */
#line 2592 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_FULL;
}
    break;

  case 538:
/* Line 1792 of yacc.c  */
#line 2595 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_HIDDEN;
}
    break;

  case 539:
/* Line 1792 of yacc.c  */
#line 2598 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SKILL;
}
    break;

  case 540:
/* Line 1792 of yacc.c  */
#line 2601 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_NCHANGE;
}
    break;

  case 541:
/* Line 1792 of yacc.c  */
#line 2604 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_REJ;
}
    break;

  case 542:
/* Line 1792 of yacc.c  */
#line 2607 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_UNAUTH;
}
    break;

  case 543:
/* Line 1792 of yacc.c  */
#line 2610 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SPY;
}
    break;

  case 544:
/* Line 1792 of yacc.c  */
#line 2613 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_EXTERNAL;
}
    break;

  case 545:
/* Line 1792 of yacc.c  */
#line 2616 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_OPERWALL;
}
    break;

  case 546:
/* Line 1792 of yacc.c  */
#line 2619 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 547:
/* Line 1792 of yacc.c  */
#line 2622 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_INVISIBLE;
}
    break;

  case 548:
/* Line 1792 of yacc.c  */
#line 2625 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_WALLOP;
}
    break;

  case 549:
/* Line 1792 of yacc.c  */
#line 2628 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 550:
/* Line 1792 of yacc.c  */
#line 2631 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_CALLERID;
}
    break;

  case 551:
/* Line 1792 of yacc.c  */
#line 2634 "conf_parser.y"
    {
  ConfigFileEntry.oper_umodes |= UMODE_LOCOPS;
}
    break;

  case 552:
/* Line 1792 of yacc.c  */
#line 2639 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes = 0;
}
    break;

  case 556:
/* Line 1792 of yacc.c  */
#line 2645 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_BOTS;
}
    break;

  case 557:
/* Line 1792 of yacc.c  */
#line 2648 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN;
}
    break;

  case 558:
/* Line 1792 of yacc.c  */
#line 2651 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CCONN_FULL;
}
    break;

  case 559:
/* Line 1792 of yacc.c  */
#line 2654 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEAF;
}
    break;

  case 560:
/* Line 1792 of yacc.c  */
#line 2657 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_DEBUG;
}
    break;

  case 561:
/* Line 1792 of yacc.c  */
#line 2660 "conf_parser.y"
    { 
  ConfigFileEntry.oper_only_umodes |= UMODE_FULL;
}
    break;

  case 562:
/* Line 1792 of yacc.c  */
#line 2663 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SKILL;
}
    break;

  case 563:
/* Line 1792 of yacc.c  */
#line 2666 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_HIDDEN;
}
    break;

  case 564:
/* Line 1792 of yacc.c  */
#line 2669 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_NCHANGE;
}
    break;

  case 565:
/* Line 1792 of yacc.c  */
#line 2672 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_REJ;
}
    break;

  case 566:
/* Line 1792 of yacc.c  */
#line 2675 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_UNAUTH;
}
    break;

  case 567:
/* Line 1792 of yacc.c  */
#line 2678 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SPY;
}
    break;

  case 568:
/* Line 1792 of yacc.c  */
#line 2681 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_EXTERNAL;
}
    break;

  case 569:
/* Line 1792 of yacc.c  */
#line 2684 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_OPERWALL;
}
    break;

  case 570:
/* Line 1792 of yacc.c  */
#line 2687 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SERVNOTICE;
}
    break;

  case 571:
/* Line 1792 of yacc.c  */
#line 2690 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_INVISIBLE;
}
    break;

  case 572:
/* Line 1792 of yacc.c  */
#line 2693 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_WALLOP;
}
    break;

  case 573:
/* Line 1792 of yacc.c  */
#line 2696 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_SOFTCALLERID;
}
    break;

  case 574:
/* Line 1792 of yacc.c  */
#line 2699 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_CALLERID;
}
    break;

  case 575:
/* Line 1792 of yacc.c  */
#line 2702 "conf_parser.y"
    {
  ConfigFileEntry.oper_only_umodes |= UMODE_LOCOPS;
}
    break;

  case 576:
/* Line 1792 of yacc.c  */
#line 2707 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard = (yyvsp[(3) - (4)].number);
}
    break;

  case 577:
/* Line 1792 of yacc.c  */
#line 2712 "conf_parser.y"
    {
  ConfigFileEntry.min_nonwildcard_simple = (yyvsp[(3) - (4)].number);
}
    break;

  case 578:
/* Line 1792 of yacc.c  */
#line 2717 "conf_parser.y"
    {
  ConfigFileEntry.default_floodcount = (yyvsp[(3) - (4)].number);
}
    break;

  case 597:
/* Line 1792 of yacc.c  */
#line 2740 "conf_parser.y"
    {
  ConfigChannel.disable_fake_channels = yylval.number;
}
    break;

  case 598:
/* Line 1792 of yacc.c  */
#line 2745 "conf_parser.y"
    {
  ConfigChannel.restrict_channels = yylval.number;
}
    break;

  case 599:
/* Line 1792 of yacc.c  */
#line 2750 "conf_parser.y"
    {
  ConfigChannel.knock_delay = (yyvsp[(3) - (4)].number);
}
    break;

  case 600:
/* Line 1792 of yacc.c  */
#line 2755 "conf_parser.y"
    {
  ConfigChannel.knock_delay_channel = (yyvsp[(3) - (4)].number);
}
    break;

  case 601:
/* Line 1792 of yacc.c  */
#line 2760 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_user = (yyvsp[(3) - (4)].number);
}
    break;

  case 602:
/* Line 1792 of yacc.c  */
#line 2765 "conf_parser.y"
    {
  ConfigChannel.max_chans_per_oper = (yyvsp[(3) - (4)].number);
}
    break;

  case 603:
/* Line 1792 of yacc.c  */
#line 2770 "conf_parser.y"
    {
  ConfigChannel.quiet_on_ban = yylval.number;
}
    break;

  case 604:
/* Line 1792 of yacc.c  */
#line 2775 "conf_parser.y"
    {
  ConfigChannel.max_bans = (yyvsp[(3) - (4)].number);
}
    break;

  case 605:
/* Line 1792 of yacc.c  */
#line 2780 "conf_parser.y"
    {
  ConfigChannel.default_split_user_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 606:
/* Line 1792 of yacc.c  */
#line 2785 "conf_parser.y"
    {
  ConfigChannel.default_split_server_count = (yyvsp[(3) - (4)].number);
}
    break;

  case 607:
/* Line 1792 of yacc.c  */
#line 2790 "conf_parser.y"
    {
  ConfigChannel.no_create_on_split = yylval.number;
}
    break;

  case 608:
/* Line 1792 of yacc.c  */
#line 2795 "conf_parser.y"
    {
  ConfigChannel.no_join_on_split = yylval.number;
}
    break;

  case 609:
/* Line 1792 of yacc.c  */
#line 2800 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodcount = yylval.number;
}
    break;

  case 610:
/* Line 1792 of yacc.c  */
#line 2805 "conf_parser.y"
    {
  GlobalSetOptions.joinfloodtime = yylval.number;
}
    break;

  case 621:
/* Line 1792 of yacc.c  */
#line 2823 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.flatten_links = yylval.number;
}
    break;

  case 622:
/* Line 1792 of yacc.c  */
#line 2829 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_servers = yylval.number;
}
    break;

  case 623:
/* Line 1792 of yacc.c  */
#line 2835 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
  {
    MyFree(ConfigServerHide.hidden_name);
    ConfigServerHide.hidden_name = xstrdup(yylval.string);
  }
}
    break;

  case 624:
/* Line 1792 of yacc.c  */
#line 2844 "conf_parser.y"
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

  case 625:
/* Line 1792 of yacc.c  */
#line 2858 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hidden = yylval.number;
}
    break;

  case 626:
/* Line 1792 of yacc.c  */
#line 2864 "conf_parser.y"
    {
  if (conf_parser_ctx.pass == 2)
    ConfigServerHide.hide_server_ips = yylval.number;
}
    break;


/* Line 1792 of yacc.c  */
#line 6597 "conf_parser.c"
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


