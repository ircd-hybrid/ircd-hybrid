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
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CONNECT = 275,
    CONNECTFREQ = 276,
    CYCLE_ON_HOST_CHANGE = 277,
    DEFAULT_FLOODCOUNT = 278,
    DEFAULT_JOIN_FLOOD_COUNT = 279,
    DEFAULT_JOIN_FLOOD_TIME = 280,
    DEFAULT_MAX_CLIENTS = 281,
    DEFAULT_SPLIT_SERVER_COUNT = 282,
    DEFAULT_SPLIT_USER_COUNT = 283,
    DENY = 284,
    DESCRIPTION = 285,
    DIE = 286,
    DISABLE_AUTH = 287,
    DISABLE_FAKE_CHANNELS = 288,
    DISABLE_REMOTE_COMMANDS = 289,
    DOTS_IN_IDENT = 290,
    EMAIL = 291,
    ENCRYPTED = 292,
    EXCEED_LIMIT = 293,
    EXEMPT = 294,
    FAILED_OPER_NOTICE = 295,
    FLATTEN_LINKS = 296,
    GECOS = 297,
    GENERAL = 298,
    GLINE = 299,
    GLINE_DURATION = 300,
    GLINE_ENABLE = 301,
    GLINE_EXEMPT = 302,
    GLINE_MIN_CIDR = 303,
    GLINE_MIN_CIDR6 = 304,
    GLINE_REQUEST_DURATION = 305,
    GLOBAL_KILL = 306,
    HAVENT_READ_CONF = 307,
    HIDDEN = 308,
    HIDDEN_NAME = 309,
    HIDE_CHANS = 310,
    HIDE_IDLE = 311,
    HIDE_IDLE_FROM_OPERS = 312,
    HIDE_SERVER_IPS = 313,
    HIDE_SERVERS = 314,
    HIDE_SERVICES = 315,
    HIDE_SPOOF_IPS = 316,
    HOST = 317,
    HUB = 318,
    HUB_MASK = 319,
    IGNORE_BOGUS_TS = 320,
    INVISIBLE_ON_CONNECT = 321,
    INVITE_CLIENT_COUNT = 322,
    INVITE_CLIENT_TIME = 323,
    IP = 324,
    IRCD_AUTH = 325,
    IRCD_FLAGS = 326,
    IRCD_SID = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KNOCK_CLIENT_COUNT = 332,
    KNOCK_CLIENT_TIME = 333,
    KNOCK_DELAY_CHANNEL = 334,
    LEAF_MASK = 335,
    LINKS_DELAY = 336,
    LISTEN = 337,
    MASK = 338,
    MAX_ACCEPT = 339,
    MAX_BANS = 340,
    MAX_CHANNELS = 341,
    MAX_GLOBAL = 342,
    MAX_IDENT = 343,
    MAX_IDLE = 344,
    MAX_LOCAL = 345,
    MAX_NICK_CHANGES = 346,
    MAX_NICK_LENGTH = 347,
    MAX_NICK_TIME = 348,
    MAX_NUMBER = 349,
    MAX_TARGETS = 350,
    MAX_TOPIC_LENGTH = 351,
    MAX_WATCH = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESC = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_CREATE_ON_SPLIT = 365,
    NO_JOIN_ON_SPLIT = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER = 369,
    NUMBER_PER_CIDR = 370,
    NUMBER_PER_IP = 371,
    OPER_ONLY_UMODES = 372,
    OPER_PASS_RESV = 373,
    OPER_UMODES = 374,
    OPERATOR = 375,
    OPERS_BYPASS_CALLERID = 376,
    PACE_WAIT = 377,
    PACE_WAIT_SIMPLE = 378,
    PASSWORD = 379,
    PATH = 380,
    PING_COOKIE = 381,
    PING_TIME = 382,
    PORT = 383,
    QSTRING = 384,
    RANDOM_IDLE = 385,
    REASON = 386,
    REDIRPORT = 387,
    REDIRSERV = 388,
    REHASH = 389,
    REMOTE = 390,
    REMOTEBAN = 391,
    RESV = 392,
    RESV_EXEMPT = 393,
    RSA_PRIVATE_KEY_FILE = 394,
    RSA_PUBLIC_KEY_FILE = 395,
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
    STATS_E_DISABLED = 417,
    STATS_I_OPER_ONLY = 418,
    STATS_K_OPER_ONLY = 419,
    STATS_M_OPER_ONLY = 420,
    STATS_O_OPER_ONLY = 421,
    STATS_P_OPER_ONLY = 422,
    STATS_U_OPER_ONLY = 423,
    T_ALL = 424,
    T_BOTS = 425,
    T_CALLERID = 426,
    T_CCONN = 427,
    T_COMMAND = 428,
    T_CLUSTER = 429,
    T_DEAF = 430,
    T_DEBUG = 431,
    T_DLINE = 432,
    T_EXTERNAL = 433,
    T_FARCONNECT = 434,
    T_FILE = 435,
    T_FULL = 436,
    T_GLOBOPS = 437,
    T_INVISIBLE = 438,
    T_IPV4 = 439,
    T_IPV6 = 440,
    T_LOCOPS = 441,
    T_LOG = 442,
    T_MAX_CLIENTS = 443,
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
    XLINE = 488
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
#define CIDR_BITLEN_IPV4 272
#define CIDR_BITLEN_IPV6 273
#define CLASS 274
#define CONNECT 275
#define CONNECTFREQ 276
#define CYCLE_ON_HOST_CHANGE 277
#define DEFAULT_FLOODCOUNT 278
#define DEFAULT_JOIN_FLOOD_COUNT 279
#define DEFAULT_JOIN_FLOOD_TIME 280
#define DEFAULT_MAX_CLIENTS 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_REMOTE_COMMANDS 289
#define DOTS_IN_IDENT 290
#define EMAIL 291
#define ENCRYPTED 292
#define EXCEED_LIMIT 293
#define EXEMPT 294
#define FAILED_OPER_NOTICE 295
#define FLATTEN_LINKS 296
#define GECOS 297
#define GENERAL 298
#define GLINE 299
#define GLINE_DURATION 300
#define GLINE_ENABLE 301
#define GLINE_EXEMPT 302
#define GLINE_MIN_CIDR 303
#define GLINE_MIN_CIDR6 304
#define GLINE_REQUEST_DURATION 305
#define GLOBAL_KILL 306
#define HAVENT_READ_CONF 307
#define HIDDEN 308
#define HIDDEN_NAME 309
#define HIDE_CHANS 310
#define HIDE_IDLE 311
#define HIDE_IDLE_FROM_OPERS 312
#define HIDE_SERVER_IPS 313
#define HIDE_SERVERS 314
#define HIDE_SERVICES 315
#define HIDE_SPOOF_IPS 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define IGNORE_BOGUS_TS 320
#define INVISIBLE_ON_CONNECT 321
#define INVITE_CLIENT_COUNT 322
#define INVITE_CLIENT_TIME 323
#define IP 324
#define IRCD_AUTH 325
#define IRCD_FLAGS 326
#define IRCD_SID 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KNOCK_CLIENT_COUNT 332
#define KNOCK_CLIENT_TIME 333
#define KNOCK_DELAY_CHANNEL 334
#define LEAF_MASK 335
#define LINKS_DELAY 336
#define LISTEN 337
#define MASK 338
#define MAX_ACCEPT 339
#define MAX_BANS 340
#define MAX_CHANNELS 341
#define MAX_GLOBAL 342
#define MAX_IDENT 343
#define MAX_IDLE 344
#define MAX_LOCAL 345
#define MAX_NICK_CHANGES 346
#define MAX_NICK_LENGTH 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_TOPIC_LENGTH 351
#define MAX_WATCH 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESC 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_CREATE_ON_SPLIT 365
#define NO_JOIN_ON_SPLIT 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER 369
#define NUMBER_PER_CIDR 370
#define NUMBER_PER_IP 371
#define OPER_ONLY_UMODES 372
#define OPER_PASS_RESV 373
#define OPER_UMODES 374
#define OPERATOR 375
#define OPERS_BYPASS_CALLERID 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PORT 383
#define QSTRING 384
#define RANDOM_IDLE 385
#define REASON 386
#define REDIRPORT 387
#define REDIRSERV 388
#define REHASH 389
#define REMOTE 390
#define REMOTEBAN 391
#define RESV 392
#define RESV_EXEMPT 393
#define RSA_PRIVATE_KEY_FILE 394
#define RSA_PUBLIC_KEY_FILE 395
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
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_M_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define STATS_U_OPER_ONLY 423
#define T_ALL 424
#define T_BOTS 425
#define T_CALLERID 426
#define T_CCONN 427
#define T_COMMAND 428
#define T_CLUSTER 429
#define T_DEAF 430
#define T_DEBUG 431
#define T_DLINE 432
#define T_EXTERNAL 433
#define T_FARCONNECT 434
#define T_FILE 435
#define T_FULL 436
#define T_GLOBOPS 437
#define T_INVISIBLE 438
#define T_IPV4 439
#define T_IPV6 440
#define T_LOCOPS 441
#define T_LOG 442
#define T_MAX_CLIENTS 443
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
#define XLINE 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 152 "conf_parser.y" /* yacc.c:1909  */

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
