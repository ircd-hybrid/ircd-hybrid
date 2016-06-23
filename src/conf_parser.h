/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ACCEPT_PASSWORD = 258,
    ADMIN = 259,
    AFTYPE = 260,
    ANTI_NICK_FLOOD = 261,
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
    AUTOCONN = 263,
    AWAY_COUNT = 264,
    AWAY_TIME = 265,
    BYTES = 266,
    KBYTES = 267,
    MBYTES = 268,
    CALLER_ID_WAIT = 269,
    CAN_FLOOD = 270,
    CHANNEL = 271,
    CHECK_CACHE = 272,
    CIDR_BITLEN_IPV4 = 273,
    CIDR_BITLEN_IPV6 = 274,
    CLASS = 275,
    CLOSE = 276,
    CONNECT = 277,
    CONNECTFREQ = 278,
    CYCLE_ON_HOST_CHANGE = 279,
    DEFAULT_FLOODCOUNT = 280,
    DEFAULT_JOIN_FLOOD_COUNT = 281,
    DEFAULT_JOIN_FLOOD_TIME = 282,
    DEFAULT_MAX_CLIENTS = 283,
    DENY = 284,
    DESCRIPTION = 285,
    DIE = 286,
    DISABLE_AUTH = 287,
    DISABLE_FAKE_CHANNELS = 288,
    DISABLE_REMOTE_COMMANDS = 289,
    DLINE_MIN_CIDR = 290,
    DLINE_MIN_CIDR6 = 291,
    DOTS_IN_IDENT = 292,
    EMAIL = 293,
    ENCRYPTED = 294,
    EXCEED_LIMIT = 295,
    EXEMPT = 296,
    FAILED_OPER_NOTICE = 297,
    FLATTEN_LINKS = 298,
    FLATTEN_LINKS_DELAY = 299,
    FLATTEN_LINKS_FILE = 300,
    GECOS = 301,
    GENERAL = 302,
    HIDDEN = 303,
    HIDDEN_NAME = 304,
    HIDE_CHANS = 305,
    HIDE_IDLE = 306,
    HIDE_IDLE_FROM_OPERS = 307,
    HIDE_SERVER_IPS = 308,
    HIDE_SERVERS = 309,
    HIDE_SERVICES = 310,
    HOST = 311,
    HUB = 312,
    HUB_MASK = 313,
    IGNORE_BOGUS_TS = 314,
    INVISIBLE_ON_CONNECT = 315,
    INVITE_CLIENT_COUNT = 316,
    INVITE_CLIENT_TIME = 317,
    INVITE_DELAY_CHANNEL = 318,
    IP = 319,
    IRCD_AUTH = 320,
    IRCD_FLAGS = 321,
    IRCD_SID = 322,
    JOIN = 323,
    KILL = 324,
    KILL_CHASE_TIME_LIMIT = 325,
    KLINE = 326,
    KLINE_EXEMPT = 327,
    KLINE_MIN_CIDR = 328,
    KLINE_MIN_CIDR6 = 329,
    KNOCK_CLIENT_COUNT = 330,
    KNOCK_CLIENT_TIME = 331,
    KNOCK_DELAY_CHANNEL = 332,
    LEAF_MASK = 333,
    LIBGEOIP_DATABASE_OPTIONS = 334,
    LIBGEOIP_IPV4_DATABASE_FILE = 335,
    LIBGEOIP_IPV6_DATABASE_FILE = 336,
    LISTEN = 337,
    MASK = 338,
    MAX_ACCEPT = 339,
    MAX_BANS = 340,
    MAX_CHANNELS = 341,
    MAX_GLOBAL = 342,
    MAX_IDLE = 343,
    MAX_LOCAL = 344,
    MAX_NICK_CHANGES = 345,
    MAX_NICK_LENGTH = 346,
    MAX_NICK_TIME = 347,
    MAX_NUMBER = 348,
    MAX_TARGETS = 349,
    MAX_TOPIC_LENGTH = 350,
    MAX_WATCH = 351,
    MEMORY_CACHE = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MMAP_CACHE = 356,
    MODULE = 357,
    MODULES = 358,
    MOTD = 359,
    NAME = 360,
    NEED_IDENT = 361,
    NEED_PASSWORD = 362,
    NETWORK_DESC = 363,
    NETWORK_NAME = 364,
    NICK = 365,
    NO_OPER_FLOOD = 366,
    NO_TILDE = 367,
    NUMBER = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP = 370,
    OPER_ONLY_UMODES = 371,
    OPER_UMODES = 372,
    OPERATOR = 373,
    OPERS_BYPASS_CALLERID = 374,
    PACE_WAIT = 375,
    PACE_WAIT_SIMPLE = 376,
    PASSWORD = 377,
    PATH = 378,
    PING_COOKIE = 379,
    PING_TIME = 380,
    PORT = 381,
    QSTRING = 382,
    RANDOM_IDLE = 383,
    REASON = 384,
    REDIRPORT = 385,
    REDIRSERV = 386,
    REHASH = 387,
    REMOTE = 388,
    REMOTEBAN = 389,
    RESV = 390,
    RESV_EXEMPT = 391,
    RSA_PRIVATE_KEY_FILE = 392,
    SECONDS = 393,
    MINUTES = 394,
    HOURS = 395,
    DAYS = 396,
    WEEKS = 397,
    MONTHS = 398,
    YEARS = 399,
    SEND_PASSWORD = 400,
    SENDQ = 401,
    SERVERHIDE = 402,
    SERVERINFO = 403,
    SHORT_MOTD = 404,
    SPOOF = 405,
    SPOOF_NOTICE = 406,
    SQUIT = 407,
    SSL_CERTIFICATE_FILE = 408,
    SSL_CERTIFICATE_FINGERPRINT = 409,
    SSL_CONNECTION_REQUIRED = 410,
    SSL_DH_ELLIPTIC_CURVE = 411,
    SSL_DH_PARAM_FILE = 412,
    SSL_MESSAGE_DIGEST_ALGORITHM = 413,
    STANDARD = 414,
    STATS_E_DISABLED = 415,
    STATS_I_OPER_ONLY = 416,
    STATS_K_OPER_ONLY = 417,
    STATS_M_OPER_ONLY = 418,
    STATS_O_OPER_ONLY = 419,
    STATS_P_OPER_ONLY = 420,
    STATS_U_OPER_ONLY = 421,
    T_ALL = 422,
    T_BOTS = 423,
    T_CALLERID = 424,
    T_CCONN = 425,
    T_COMMAND = 426,
    T_CLUSTER = 427,
    T_DEAF = 428,
    T_DEBUG = 429,
    T_DLINE = 430,
    T_EXTERNAL = 431,
    T_FARCONNECT = 432,
    T_FILE = 433,
    T_FULL = 434,
    T_GLOBOPS = 435,
    T_INVISIBLE = 436,
    T_IPV4 = 437,
    T_IPV6 = 438,
    T_LOCOPS = 439,
    T_LOG = 440,
    T_NCHANGE = 441,
    T_NONONREG = 442,
    T_OPME = 443,
    T_PREPEND = 444,
    T_PSEUDO = 445,
    T_RECVQ = 446,
    T_REJ = 447,
    T_RESTART = 448,
    T_SERVER = 449,
    T_SERVICE = 450,
    T_SERVNOTICE = 451,
    T_SET = 452,
    T_SHARED = 453,
    T_SIZE = 454,
    T_SKILL = 455,
    T_SOFTCALLERID = 456,
    T_SPY = 457,
    T_SSL = 458,
    T_SSL_CIPHER_LIST = 459,
    T_TARGET = 460,
    T_UMODES = 461,
    T_UNAUTH = 462,
    T_UNDLINE = 463,
    T_UNLIMITED = 464,
    T_UNRESV = 465,
    T_UNXLINE = 466,
    T_WALLOP = 467,
    T_WALLOPS = 468,
    T_WEBIRC = 469,
    TBOOL = 470,
    THROTTLE_COUNT = 471,
    THROTTLE_TIME = 472,
    TKLINE_EXPIRE_NOTICES = 473,
    TMASKED = 474,
    TS_MAX_DELTA = 475,
    TS_WARN_DELTA = 476,
    TWODOTS = 477,
    TYPE = 478,
    UNKLINE = 479,
    USE_LOGGING = 480,
    USER = 481,
    VHOST = 482,
    VHOST6 = 483,
    WARN_NO_CONNECT_BLOCK = 484,
    WHOIS = 485,
    WHOWAS_HISTORY_LENGTH = 486,
    XLINE = 487,
    XLINE_EXEMPT = 488
  };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define AWAY_COUNT 264
#define AWAY_TIME 265
#define BYTES 266
#define KBYTES 267
#define MBYTES 268
#define CALLER_ID_WAIT 269
#define CAN_FLOOD 270
#define CHANNEL 271
#define CHECK_CACHE 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLOSE 276
#define CONNECT 277
#define CONNECTFREQ 278
#define CYCLE_ON_HOST_CHANGE 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_JOIN_FLOOD_COUNT 281
#define DEFAULT_JOIN_FLOOD_TIME 282
#define DEFAULT_MAX_CLIENTS 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DLINE_MIN_CIDR 290
#define DLINE_MIN_CIDR6 291
#define DOTS_IN_IDENT 292
#define EMAIL 293
#define ENCRYPTED 294
#define EXCEED_LIMIT 295
#define EXEMPT 296
#define FAILED_OPER_NOTICE 297
#define FLATTEN_LINKS 298
#define FLATTEN_LINKS_DELAY 299
#define FLATTEN_LINKS_FILE 300
#define GECOS 301
#define GENERAL 302
#define HIDDEN 303
#define HIDDEN_NAME 304
#define HIDE_CHANS 305
#define HIDE_IDLE 306
#define HIDE_IDLE_FROM_OPERS 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SERVICES 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define INVITE_CLIENT_COUNT 316
#define INVITE_CLIENT_TIME 317
#define INVITE_DELAY_CHANNEL 318
#define IP 319
#define IRCD_AUTH 320
#define IRCD_FLAGS 321
#define IRCD_SID 322
#define JOIN 323
#define KILL 324
#define KILL_CHASE_TIME_LIMIT 325
#define KLINE 326
#define KLINE_EXEMPT 327
#define KLINE_MIN_CIDR 328
#define KLINE_MIN_CIDR6 329
#define KNOCK_CLIENT_COUNT 330
#define KNOCK_CLIENT_TIME 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LIBGEOIP_DATABASE_OPTIONS 334
#define LIBGEOIP_IPV4_DATABASE_FILE 335
#define LIBGEOIP_IPV6_DATABASE_FILE 336
#define LISTEN 337
#define MASK 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANNELS 341
#define MAX_GLOBAL 342
#define MAX_IDLE 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_LENGTH 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_TOPIC_LENGTH 350
#define MAX_WATCH 351
#define MEMORY_CACHE 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MMAP_CACHE 356
#define MODULE 357
#define MODULES 358
#define MOTD 359
#define NAME 360
#define NEED_IDENT 361
#define NEED_PASSWORD 362
#define NETWORK_DESC 363
#define NETWORK_NAME 364
#define NICK 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define OPER_ONLY_UMODES 371
#define OPER_UMODES 372
#define OPERATOR 373
#define OPERS_BYPASS_CALLERID 374
#define PACE_WAIT 375
#define PACE_WAIT_SIMPLE 376
#define PASSWORD 377
#define PATH 378
#define PING_COOKIE 379
#define PING_TIME 380
#define PORT 381
#define QSTRING 382
#define RANDOM_IDLE 383
#define REASON 384
#define REDIRPORT 385
#define REDIRSERV 386
#define REHASH 387
#define REMOTE 388
#define REMOTEBAN 389
#define RESV 390
#define RESV_EXEMPT 391
#define RSA_PRIVATE_KEY_FILE 392
#define SECONDS 393
#define MINUTES 394
#define HOURS 395
#define DAYS 396
#define WEEKS 397
#define MONTHS 398
#define YEARS 399
#define SEND_PASSWORD 400
#define SENDQ 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define SHORT_MOTD 404
#define SPOOF 405
#define SPOOF_NOTICE 406
#define SQUIT 407
#define SSL_CERTIFICATE_FILE 408
#define SSL_CERTIFICATE_FINGERPRINT 409
#define SSL_CONNECTION_REQUIRED 410
#define SSL_DH_ELLIPTIC_CURVE 411
#define SSL_DH_PARAM_FILE 412
#define SSL_MESSAGE_DIGEST_ALGORITHM 413
#define STANDARD 414
#define STATS_E_DISABLED 415
#define STATS_I_OPER_ONLY 416
#define STATS_K_OPER_ONLY 417
#define STATS_M_OPER_ONLY 418
#define STATS_O_OPER_ONLY 419
#define STATS_P_OPER_ONLY 420
#define STATS_U_OPER_ONLY 421
#define T_ALL 422
#define T_BOTS 423
#define T_CALLERID 424
#define T_CCONN 425
#define T_COMMAND 426
#define T_CLUSTER 427
#define T_DEAF 428
#define T_DEBUG 429
#define T_DLINE 430
#define T_EXTERNAL 431
#define T_FARCONNECT 432
#define T_FILE 433
#define T_FULL 434
#define T_GLOBOPS 435
#define T_INVISIBLE 436
#define T_IPV4 437
#define T_IPV6 438
#define T_LOCOPS 439
#define T_LOG 440
#define T_NCHANGE 441
#define T_NONONREG 442
#define T_OPME 443
#define T_PREPEND 444
#define T_PSEUDO 445
#define T_RECVQ 446
#define T_REJ 447
#define T_RESTART 448
#define T_SERVER 449
#define T_SERVICE 450
#define T_SERVNOTICE 451
#define T_SET 452
#define T_SHARED 453
#define T_SIZE 454
#define T_SKILL 455
#define T_SOFTCALLERID 456
#define T_SPY 457
#define T_SSL 458
#define T_SSL_CIPHER_LIST 459
#define T_TARGET 460
#define T_UMODES 461
#define T_UNAUTH 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_WALLOP 467
#define T_WALLOPS 468
#define T_WEBIRC 469
#define TBOOL 470
#define THROTTLE_COUNT 471
#define THROTTLE_TIME 472
#define TKLINE_EXPIRE_NOTICES 473
#define TMASKED 474
#define TS_MAX_DELTA 475
#define TS_WARN_DELTA 476
#define TWODOTS 477
#define TYPE 478
#define UNKLINE 479
#define USE_LOGGING 480
#define USER 481
#define VHOST 482
#define VHOST6 483
#define WARN_NO_CONNECT_BLOCK 484
#define WHOIS 485
#define WHOWAS_HISTORY_LENGTH 486
#define XLINE 487
#define XLINE_EXEMPT 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 525 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
