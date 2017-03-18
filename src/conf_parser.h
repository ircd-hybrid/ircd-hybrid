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
    DEFAULT_FLOODTIME = 281,
    DEFAULT_JOIN_FLOOD_COUNT = 282,
    DEFAULT_JOIN_FLOOD_TIME = 283,
    DEFAULT_MAX_CLIENTS = 284,
    DENY = 285,
    DESCRIPTION = 286,
    DIE = 287,
    DISABLE_AUTH = 288,
    DISABLE_FAKE_CHANNELS = 289,
    DISABLE_REMOTE_COMMANDS = 290,
    DLINE_MIN_CIDR = 291,
    DLINE_MIN_CIDR6 = 292,
    DOTS_IN_IDENT = 293,
    EMAIL = 294,
    ENCRYPTED = 295,
    EXCEED_LIMIT = 296,
    EXEMPT = 297,
    FAILED_OPER_NOTICE = 298,
    FLATTEN_LINKS = 299,
    FLATTEN_LINKS_DELAY = 300,
    FLATTEN_LINKS_FILE = 301,
    GECOS = 302,
    GENERAL = 303,
    HIDDEN = 304,
    HIDDEN_NAME = 305,
    HIDE_CHANS = 306,
    HIDE_IDLE = 307,
    HIDE_IDLE_FROM_OPERS = 308,
    HIDE_SERVER_IPS = 309,
    HIDE_SERVERS = 310,
    HIDE_SERVICES = 311,
    HOST = 312,
    HUB = 313,
    HUB_MASK = 314,
    IGNORE_BOGUS_TS = 315,
    INVISIBLE_ON_CONNECT = 316,
    INVITE_CLIENT_COUNT = 317,
    INVITE_CLIENT_TIME = 318,
    INVITE_DELAY_CHANNEL = 319,
    INVITE_EXPIRE_TIME = 320,
    IP = 321,
    IRCD_AUTH = 322,
    IRCD_FLAGS = 323,
    IRCD_SID = 324,
    JOIN = 325,
    KILL = 326,
    KILL_CHASE_TIME_LIMIT = 327,
    KLINE = 328,
    KLINE_EXEMPT = 329,
    KLINE_MIN_CIDR = 330,
    KLINE_MIN_CIDR6 = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LIBGEOIP_DATABASE_OPTIONS = 336,
    LIBGEOIP_IPV4_DATABASE_FILE = 337,
    LIBGEOIP_IPV6_DATABASE_FILE = 338,
    LISTEN = 339,
    MASK = 340,
    MAX_ACCEPT = 341,
    MAX_BANS = 342,
    MAX_BANS_LARGE = 343,
    MAX_CHANNELS = 344,
    MAX_GLOBAL = 345,
    MAX_IDLE = 346,
    MAX_INVITES = 347,
    MAX_LOCAL = 348,
    MAX_NICK_CHANGES = 349,
    MAX_NICK_LENGTH = 350,
    MAX_NICK_TIME = 351,
    MAX_NUMBER = 352,
    MAX_TARGETS = 353,
    MAX_TOPIC_LENGTH = 354,
    MAX_WATCH = 355,
    MEMORY_CACHE = 356,
    MIN_IDLE = 357,
    MIN_NONWILDCARD = 358,
    MIN_NONWILDCARD_SIMPLE = 359,
    MMAP_CACHE = 360,
    MODULE = 361,
    MODULES = 362,
    MOTD = 363,
    NAME = 364,
    NEED_IDENT = 365,
    NEED_PASSWORD = 366,
    NETWORK_DESC = 367,
    NETWORK_NAME = 368,
    NICK = 369,
    NO_OPER_FLOOD = 370,
    NO_TILDE = 371,
    NUMBER = 372,
    NUMBER_PER_CIDR = 373,
    NUMBER_PER_IP = 374,
    OPER_ONLY_UMODES = 375,
    OPER_UMODES = 376,
    OPERATOR = 377,
    OPERS_BYPASS_CALLERID = 378,
    PACE_WAIT = 379,
    PACE_WAIT_SIMPLE = 380,
    PASSWORD = 381,
    PATH = 382,
    PING_COOKIE = 383,
    PING_TIME = 384,
    PORT = 385,
    QSTRING = 386,
    RANDOM_IDLE = 387,
    REASON = 388,
    REDIRPORT = 389,
    REDIRSERV = 390,
    REHASH = 391,
    REMOTE = 392,
    REMOTEBAN = 393,
    RESV = 394,
    RESV_EXEMPT = 395,
    RSA_PRIVATE_KEY_FILE = 396,
    SECONDS = 397,
    MINUTES = 398,
    HOURS = 399,
    DAYS = 400,
    WEEKS = 401,
    MONTHS = 402,
    YEARS = 403,
    SEND_PASSWORD = 404,
    SENDQ = 405,
    SERVERHIDE = 406,
    SERVERINFO = 407,
    SHORT_MOTD = 408,
    SPOOF = 409,
    SPOOF_NOTICE = 410,
    SQUIT = 411,
    SSL_CERTIFICATE_FILE = 412,
    SSL_CERTIFICATE_FINGERPRINT = 413,
    SSL_CONNECTION_REQUIRED = 414,
    SSL_DH_ELLIPTIC_CURVE = 415,
    SSL_DH_PARAM_FILE = 416,
    SSL_MESSAGE_DIGEST_ALGORITHM = 417,
    STANDARD = 418,
    STATS_E_DISABLED = 419,
    STATS_I_OPER_ONLY = 420,
    STATS_K_OPER_ONLY = 421,
    STATS_M_OPER_ONLY = 422,
    STATS_O_OPER_ONLY = 423,
    STATS_P_OPER_ONLY = 424,
    STATS_U_OPER_ONLY = 425,
    T_ALL = 426,
    T_BOTS = 427,
    T_CALLERID = 428,
    T_CCONN = 429,
    T_COMMAND = 430,
    T_CLUSTER = 431,
    T_DEAF = 432,
    T_DEBUG = 433,
    T_DLINE = 434,
    T_EXTERNAL = 435,
    T_FARCONNECT = 436,
    T_FILE = 437,
    T_FULL = 438,
    T_GLOBOPS = 439,
    T_INVISIBLE = 440,
    T_IPV4 = 441,
    T_IPV6 = 442,
    T_LOCOPS = 443,
    T_LOG = 444,
    T_NCHANGE = 445,
    T_NONONREG = 446,
    T_OPME = 447,
    T_PREPEND = 448,
    T_PSEUDO = 449,
    T_RECVQ = 450,
    T_REJ = 451,
    T_RESTART = 452,
    T_SERVER = 453,
    T_SERVICE = 454,
    T_SERVNOTICE = 455,
    T_SET = 456,
    T_SHARED = 457,
    T_SIZE = 458,
    T_SKILL = 459,
    T_SOFTCALLERID = 460,
    T_SPY = 461,
    T_SSL = 462,
    T_SSL_CIPHER_LIST = 463,
    T_TARGET = 464,
    T_UMODES = 465,
    T_UNAUTH = 466,
    T_UNDLINE = 467,
    T_UNLIMITED = 468,
    T_UNRESV = 469,
    T_UNXLINE = 470,
    T_WALLOP = 471,
    T_WALLOPS = 472,
    T_WEBIRC = 473,
    TBOOL = 474,
    THROTTLE_COUNT = 475,
    THROTTLE_TIME = 476,
    TKLINE_EXPIRE_NOTICES = 477,
    TMASKED = 478,
    TS_MAX_DELTA = 479,
    TS_WARN_DELTA = 480,
    TWODOTS = 481,
    TYPE = 482,
    UNKLINE = 483,
    USE_LOGGING = 484,
    USER = 485,
    VHOST = 486,
    VHOST6 = 487,
    WARN_NO_CONNECT_BLOCK = 488,
    WHOIS = 489,
    WHOWAS_HISTORY_LENGTH = 490,
    XLINE = 491,
    XLINE_EXEMPT = 492
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
#define DEFAULT_FLOODTIME 281
#define DEFAULT_JOIN_FLOOD_COUNT 282
#define DEFAULT_JOIN_FLOOD_TIME 283
#define DEFAULT_MAX_CLIENTS 284
#define DENY 285
#define DESCRIPTION 286
#define DIE 287
#define DISABLE_AUTH 288
#define DISABLE_FAKE_CHANNELS 289
#define DISABLE_REMOTE_COMMANDS 290
#define DLINE_MIN_CIDR 291
#define DLINE_MIN_CIDR6 292
#define DOTS_IN_IDENT 293
#define EMAIL 294
#define ENCRYPTED 295
#define EXCEED_LIMIT 296
#define EXEMPT 297
#define FAILED_OPER_NOTICE 298
#define FLATTEN_LINKS 299
#define FLATTEN_LINKS_DELAY 300
#define FLATTEN_LINKS_FILE 301
#define GECOS 302
#define GENERAL 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_CHANS 306
#define HIDE_IDLE 307
#define HIDE_IDLE_FROM_OPERS 308
#define HIDE_SERVER_IPS 309
#define HIDE_SERVERS 310
#define HIDE_SERVICES 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define INVITE_CLIENT_COUNT 317
#define INVITE_CLIENT_TIME 318
#define INVITE_DELAY_CHANNEL 319
#define INVITE_EXPIRE_TIME 320
#define IP 321
#define IRCD_AUTH 322
#define IRCD_FLAGS 323
#define IRCD_SID 324
#define JOIN 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_MIN_CIDR 330
#define KLINE_MIN_CIDR6 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LIBGEOIP_DATABASE_OPTIONS 336
#define LIBGEOIP_IPV4_DATABASE_FILE 337
#define LIBGEOIP_IPV6_DATABASE_FILE 338
#define LISTEN 339
#define MASK 340
#define MAX_ACCEPT 341
#define MAX_BANS 342
#define MAX_BANS_LARGE 343
#define MAX_CHANNELS 344
#define MAX_GLOBAL 345
#define MAX_IDLE 346
#define MAX_INVITES 347
#define MAX_LOCAL 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_LENGTH 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_TOPIC_LENGTH 354
#define MAX_WATCH 355
#define MEMORY_CACHE 356
#define MIN_IDLE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MMAP_CACHE 360
#define MODULE 361
#define MODULES 362
#define MOTD 363
#define NAME 364
#define NEED_IDENT 365
#define NEED_PASSWORD 366
#define NETWORK_DESC 367
#define NETWORK_NAME 368
#define NICK 369
#define NO_OPER_FLOOD 370
#define NO_TILDE 371
#define NUMBER 372
#define NUMBER_PER_CIDR 373
#define NUMBER_PER_IP 374
#define OPER_ONLY_UMODES 375
#define OPER_UMODES 376
#define OPERATOR 377
#define OPERS_BYPASS_CALLERID 378
#define PACE_WAIT 379
#define PACE_WAIT_SIMPLE 380
#define PASSWORD 381
#define PATH 382
#define PING_COOKIE 383
#define PING_TIME 384
#define PORT 385
#define QSTRING 386
#define RANDOM_IDLE 387
#define REASON 388
#define REDIRPORT 389
#define REDIRSERV 390
#define REHASH 391
#define REMOTE 392
#define REMOTEBAN 393
#define RESV 394
#define RESV_EXEMPT 395
#define RSA_PRIVATE_KEY_FILE 396
#define SECONDS 397
#define MINUTES 398
#define HOURS 399
#define DAYS 400
#define WEEKS 401
#define MONTHS 402
#define YEARS 403
#define SEND_PASSWORD 404
#define SENDQ 405
#define SERVERHIDE 406
#define SERVERINFO 407
#define SHORT_MOTD 408
#define SPOOF 409
#define SPOOF_NOTICE 410
#define SQUIT 411
#define SSL_CERTIFICATE_FILE 412
#define SSL_CERTIFICATE_FINGERPRINT 413
#define SSL_CONNECTION_REQUIRED 414
#define SSL_DH_ELLIPTIC_CURVE 415
#define SSL_DH_PARAM_FILE 416
#define SSL_MESSAGE_DIGEST_ALGORITHM 417
#define STANDARD 418
#define STATS_E_DISABLED 419
#define STATS_I_OPER_ONLY 420
#define STATS_K_OPER_ONLY 421
#define STATS_M_OPER_ONLY 422
#define STATS_O_OPER_ONLY 423
#define STATS_P_OPER_ONLY 424
#define STATS_U_OPER_ONLY 425
#define T_ALL 426
#define T_BOTS 427
#define T_CALLERID 428
#define T_CCONN 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEAF 432
#define T_DEBUG 433
#define T_DLINE 434
#define T_EXTERNAL 435
#define T_FARCONNECT 436
#define T_FILE 437
#define T_FULL 438
#define T_GLOBOPS 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_LOG 444
#define T_NCHANGE 445
#define T_NONONREG 446
#define T_OPME 447
#define T_PREPEND 448
#define T_PSEUDO 449
#define T_RECVQ 450
#define T_REJ 451
#define T_RESTART 452
#define T_SERVER 453
#define T_SERVICE 454
#define T_SERVNOTICE 455
#define T_SET 456
#define T_SHARED 457
#define T_SIZE 458
#define T_SKILL 459
#define T_SOFTCALLERID 460
#define T_SPY 461
#define T_SSL 462
#define T_SSL_CIPHER_LIST 463
#define T_TARGET 464
#define T_UMODES 465
#define T_UNAUTH 466
#define T_UNDLINE 467
#define T_UNLIMITED 468
#define T_UNRESV 469
#define T_UNXLINE 470
#define T_WALLOP 471
#define T_WALLOPS 472
#define T_WEBIRC 473
#define TBOOL 474
#define THROTTLE_COUNT 475
#define THROTTLE_TIME 476
#define TKLINE_EXPIRE_NOTICES 477
#define TMASKED 478
#define TS_MAX_DELTA 479
#define TS_WARN_DELTA 480
#define TWODOTS 481
#define TYPE 482
#define UNKLINE 483
#define USE_LOGGING 484
#define USER 485
#define VHOST 486
#define VHOST6 487
#define WARN_NO_CONNECT_BLOCK 488
#define WHOIS 489
#define WHOWAS_HISTORY_LENGTH 490
#define XLINE 491
#define XLINE_EXEMPT 492

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 533 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
