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
    MAX_CHANNELS = 343,
    MAX_GLOBAL = 344,
    MAX_IDLE = 345,
    MAX_INVITES = 346,
    MAX_LOCAL = 347,
    MAX_NICK_CHANGES = 348,
    MAX_NICK_LENGTH = 349,
    MAX_NICK_TIME = 350,
    MAX_NUMBER = 351,
    MAX_TARGETS = 352,
    MAX_TOPIC_LENGTH = 353,
    MAX_WATCH = 354,
    MEMORY_CACHE = 355,
    MIN_IDLE = 356,
    MIN_NONWILDCARD = 357,
    MIN_NONWILDCARD_SIMPLE = 358,
    MMAP_CACHE = 359,
    MODULE = 360,
    MODULES = 361,
    MOTD = 362,
    NAME = 363,
    NEED_IDENT = 364,
    NEED_PASSWORD = 365,
    NETWORK_DESC = 366,
    NETWORK_NAME = 367,
    NICK = 368,
    NO_OPER_FLOOD = 369,
    NO_TILDE = 370,
    NUMBER = 371,
    NUMBER_PER_CIDR = 372,
    NUMBER_PER_IP = 373,
    OPER_ONLY_UMODES = 374,
    OPER_UMODES = 375,
    OPERATOR = 376,
    OPERS_BYPASS_CALLERID = 377,
    PACE_WAIT = 378,
    PACE_WAIT_SIMPLE = 379,
    PASSWORD = 380,
    PATH = 381,
    PING_COOKIE = 382,
    PING_TIME = 383,
    PORT = 384,
    QSTRING = 385,
    RANDOM_IDLE = 386,
    REASON = 387,
    REDIRPORT = 388,
    REDIRSERV = 389,
    REHASH = 390,
    REMOTE = 391,
    REMOTEBAN = 392,
    RESV = 393,
    RESV_EXEMPT = 394,
    RSA_PRIVATE_KEY_FILE = 395,
    SECONDS = 396,
    MINUTES = 397,
    HOURS = 398,
    DAYS = 399,
    WEEKS = 400,
    MONTHS = 401,
    YEARS = 402,
    SEND_PASSWORD = 403,
    SENDQ = 404,
    SERVERHIDE = 405,
    SERVERINFO = 406,
    SHORT_MOTD = 407,
    SPOOF = 408,
    SPOOF_NOTICE = 409,
    SQUIT = 410,
    SSL_CERTIFICATE_FILE = 411,
    SSL_CERTIFICATE_FINGERPRINT = 412,
    SSL_CONNECTION_REQUIRED = 413,
    SSL_DH_ELLIPTIC_CURVE = 414,
    SSL_DH_PARAM_FILE = 415,
    SSL_MESSAGE_DIGEST_ALGORITHM = 416,
    STANDARD = 417,
    STATS_E_DISABLED = 418,
    STATS_I_OPER_ONLY = 419,
    STATS_K_OPER_ONLY = 420,
    STATS_M_OPER_ONLY = 421,
    STATS_O_OPER_ONLY = 422,
    STATS_P_OPER_ONLY = 423,
    STATS_U_OPER_ONLY = 424,
    T_ALL = 425,
    T_BOTS = 426,
    T_CALLERID = 427,
    T_CCONN = 428,
    T_COMMAND = 429,
    T_CLUSTER = 430,
    T_DEAF = 431,
    T_DEBUG = 432,
    T_DLINE = 433,
    T_EXTERNAL = 434,
    T_FARCONNECT = 435,
    T_FILE = 436,
    T_FULL = 437,
    T_GLOBOPS = 438,
    T_INVISIBLE = 439,
    T_IPV4 = 440,
    T_IPV6 = 441,
    T_LOCOPS = 442,
    T_LOG = 443,
    T_NCHANGE = 444,
    T_NONONREG = 445,
    T_OPME = 446,
    T_PREPEND = 447,
    T_PSEUDO = 448,
    T_RECVQ = 449,
    T_REJ = 450,
    T_RESTART = 451,
    T_SERVER = 452,
    T_SERVICE = 453,
    T_SERVNOTICE = 454,
    T_SET = 455,
    T_SHARED = 456,
    T_SIZE = 457,
    T_SKILL = 458,
    T_SOFTCALLERID = 459,
    T_SPY = 460,
    T_SSL = 461,
    T_SSL_CIPHER_LIST = 462,
    T_TARGET = 463,
    T_UMODES = 464,
    T_UNAUTH = 465,
    T_UNDLINE = 466,
    T_UNLIMITED = 467,
    T_UNRESV = 468,
    T_UNXLINE = 469,
    T_WALLOP = 470,
    T_WALLOPS = 471,
    T_WEBIRC = 472,
    TBOOL = 473,
    THROTTLE_COUNT = 474,
    THROTTLE_TIME = 475,
    TKLINE_EXPIRE_NOTICES = 476,
    TMASKED = 477,
    TS_MAX_DELTA = 478,
    TS_WARN_DELTA = 479,
    TWODOTS = 480,
    TYPE = 481,
    UNKLINE = 482,
    USE_LOGGING = 483,
    USER = 484,
    VHOST = 485,
    VHOST6 = 486,
    WARN_NO_CONNECT_BLOCK = 487,
    WHOIS = 488,
    WHOWAS_HISTORY_LENGTH = 489,
    XLINE = 490,
    XLINE_EXEMPT = 491
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
#define MAX_CHANNELS 343
#define MAX_GLOBAL 344
#define MAX_IDLE 345
#define MAX_INVITES 346
#define MAX_LOCAL 347
#define MAX_NICK_CHANGES 348
#define MAX_NICK_LENGTH 349
#define MAX_NICK_TIME 350
#define MAX_NUMBER 351
#define MAX_TARGETS 352
#define MAX_TOPIC_LENGTH 353
#define MAX_WATCH 354
#define MEMORY_CACHE 355
#define MIN_IDLE 356
#define MIN_NONWILDCARD 357
#define MIN_NONWILDCARD_SIMPLE 358
#define MMAP_CACHE 359
#define MODULE 360
#define MODULES 361
#define MOTD 362
#define NAME 363
#define NEED_IDENT 364
#define NEED_PASSWORD 365
#define NETWORK_DESC 366
#define NETWORK_NAME 367
#define NICK 368
#define NO_OPER_FLOOD 369
#define NO_TILDE 370
#define NUMBER 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP 373
#define OPER_ONLY_UMODES 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PORT 384
#define QSTRING 385
#define RANDOM_IDLE 386
#define REASON 387
#define REDIRPORT 388
#define REDIRSERV 389
#define REHASH 390
#define REMOTE 391
#define REMOTEBAN 392
#define RESV 393
#define RESV_EXEMPT 394
#define RSA_PRIVATE_KEY_FILE 395
#define SECONDS 396
#define MINUTES 397
#define HOURS 398
#define DAYS 399
#define WEEKS 400
#define MONTHS 401
#define YEARS 402
#define SEND_PASSWORD 403
#define SENDQ 404
#define SERVERHIDE 405
#define SERVERINFO 406
#define SHORT_MOTD 407
#define SPOOF 408
#define SPOOF_NOTICE 409
#define SQUIT 410
#define SSL_CERTIFICATE_FILE 411
#define SSL_CERTIFICATE_FINGERPRINT 412
#define SSL_CONNECTION_REQUIRED 413
#define SSL_DH_ELLIPTIC_CURVE 414
#define SSL_DH_PARAM_FILE 415
#define SSL_MESSAGE_DIGEST_ALGORITHM 416
#define STANDARD 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_M_OPER_ONLY 421
#define STATS_O_OPER_ONLY 422
#define STATS_P_OPER_ONLY 423
#define STATS_U_OPER_ONLY 424
#define T_ALL 425
#define T_BOTS 426
#define T_CALLERID 427
#define T_CCONN 428
#define T_COMMAND 429
#define T_CLUSTER 430
#define T_DEAF 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_EXTERNAL 434
#define T_FARCONNECT 435
#define T_FILE 436
#define T_FULL 437
#define T_GLOBOPS 438
#define T_INVISIBLE 439
#define T_IPV4 440
#define T_IPV6 441
#define T_LOCOPS 442
#define T_LOG 443
#define T_NCHANGE 444
#define T_NONONREG 445
#define T_OPME 446
#define T_PREPEND 447
#define T_PSEUDO 448
#define T_RECVQ 449
#define T_REJ 450
#define T_RESTART 451
#define T_SERVER 452
#define T_SERVICE 453
#define T_SERVNOTICE 454
#define T_SET 455
#define T_SHARED 456
#define T_SIZE 457
#define T_SKILL 458
#define T_SOFTCALLERID 459
#define T_SPY 460
#define T_SSL 461
#define T_SSL_CIPHER_LIST 462
#define T_TARGET 463
#define T_UMODES 464
#define T_UNAUTH 465
#define T_UNDLINE 466
#define T_UNLIMITED 467
#define T_UNRESV 468
#define T_UNXLINE 469
#define T_WALLOP 470
#define T_WALLOPS 471
#define T_WEBIRC 472
#define TBOOL 473
#define THROTTLE_COUNT 474
#define THROTTLE_TIME 475
#define TKLINE_EXPIRE_NOTICES 476
#define TMASKED 477
#define TS_MAX_DELTA 478
#define TS_WARN_DELTA 479
#define TWODOTS 480
#define TYPE 481
#define UNKLINE 482
#define USE_LOGGING 483
#define USER 484
#define VHOST 485
#define VHOST6 486
#define WARN_NO_CONNECT_BLOCK 487
#define WHOIS 488
#define WHOWAS_HISTORY_LENGTH 489
#define XLINE 490
#define XLINE_EXEMPT 491

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 141 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 531 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
