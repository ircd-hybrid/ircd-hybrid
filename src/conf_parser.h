/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
    CYCLE_ON_HOST_CHANGE = 275,
    DEFAULT_FLOODCOUNT = 276,
    DEFAULT_SPLIT_SERVER_COUNT = 277,
    DEFAULT_SPLIT_USER_COUNT = 278,
    DENY = 279,
    DESCRIPTION = 280,
    DIE = 281,
    DISABLE_AUTH = 282,
    DISABLE_FAKE_CHANNELS = 283,
    DISABLE_REMOTE_COMMANDS = 284,
    DOTS_IN_IDENT = 285,
    EGDPOOL_PATH = 286,
    EMAIL = 287,
    ENCRYPTED = 288,
    EXCEED_LIMIT = 289,
    EXEMPT = 290,
    FAILED_OPER_NOTICE = 291,
    FLATTEN_LINKS = 292,
    GECOS = 293,
    GENERAL = 294,
    GLINE = 295,
    GLINE_DURATION = 296,
    GLINE_ENABLE = 297,
    GLINE_EXEMPT = 298,
    GLINE_MIN_CIDR = 299,
    GLINE_MIN_CIDR6 = 300,
    GLINE_REQUEST_DURATION = 301,
    GLOBAL_KILL = 302,
    HAVENT_READ_CONF = 303,
    HIDDEN = 304,
    HIDDEN_NAME = 305,
    HIDE_CHANS = 306,
    HIDE_IDLE = 307,
    HIDE_IDLE_FROM_OPERS = 308,
    HIDE_SERVER_IPS = 309,
    HIDE_SERVERS = 310,
    HIDE_SERVICES = 311,
    HIDE_SPOOF_IPS = 312,
    HOST = 313,
    HUB = 314,
    HUB_MASK = 315,
    IGNORE_BOGUS_TS = 316,
    INVISIBLE_ON_CONNECT = 317,
    INVITE_CLIENT_COUNT = 318,
    INVITE_CLIENT_TIME = 319,
    IP = 320,
    IRCD_AUTH = 321,
    IRCD_FLAGS = 322,
    IRCD_SID = 323,
    JOIN_FLOOD_COUNT = 324,
    JOIN_FLOOD_TIME = 325,
    KILL = 326,
    KILL_CHASE_TIME_LIMIT = 327,
    KLINE = 328,
    KLINE_EXEMPT = 329,
    KNOCK_CLIENT_COUNT = 330,
    KNOCK_CLIENT_TIME = 331,
    KNOCK_DELAY_CHANNEL = 332,
    LEAF_MASK = 333,
    LINKS_DELAY = 334,
    LISTEN = 335,
    MASK = 336,
    MAX_ACCEPT = 337,
    MAX_BANS = 338,
    MAX_CHANS_PER_OPER = 339,
    MAX_CHANS_PER_USER = 340,
    MAX_GLOBAL = 341,
    MAX_IDENT = 342,
    MAX_IDLE = 343,
    MAX_LOCAL = 344,
    MAX_NICK_CHANGES = 345,
    MAX_NICK_LENGTH = 346,
    MAX_NICK_TIME = 347,
    MAX_NUMBER = 348,
    MAX_TARGETS = 349,
    MAX_TOPIC_LENGTH = 350,
    MAX_WATCH = 351,
    MIN_IDLE = 352,
    MIN_NONWILDCARD = 353,
    MIN_NONWILDCARD_SIMPLE = 354,
    MODULE = 355,
    MODULES = 356,
    MOTD = 357,
    NAME = 358,
    NEED_IDENT = 359,
    NEED_PASSWORD = 360,
    NETWORK_DESC = 361,
    NETWORK_NAME = 362,
    NICK = 363,
    NO_CREATE_ON_SPLIT = 364,
    NO_JOIN_ON_SPLIT = 365,
    NO_OPER_FLOOD = 366,
    NO_TILDE = 367,
    NUMBER = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP = 370,
    OPER_ONLY_UMODES = 371,
    OPER_PASS_RESV = 372,
    OPER_UMODES = 373,
    OPERATOR = 374,
    OPERS_BYPASS_CALLERID = 375,
    PACE_WAIT = 376,
    PACE_WAIT_SIMPLE = 377,
    PASSWORD = 378,
    PATH = 379,
    PING_COOKIE = 380,
    PING_TIME = 381,
    PORT = 382,
    QSTRING = 383,
    RANDOM_IDLE = 384,
    REASON = 385,
    REDIRPORT = 386,
    REDIRSERV = 387,
    REHASH = 388,
    REMOTE = 389,
    REMOTEBAN = 390,
    RESV = 391,
    RESV_EXEMPT = 392,
    RSA_PRIVATE_KEY_FILE = 393,
    RSA_PUBLIC_KEY_FILE = 394,
    SECONDS = 395,
    MINUTES = 396,
    HOURS = 397,
    DAYS = 398,
    WEEKS = 399,
    MONTHS = 400,
    YEARS = 401,
    SEND_PASSWORD = 402,
    SENDQ = 403,
    SERVERHIDE = 404,
    SERVERINFO = 405,
    SHORT_MOTD = 406,
    SPOOF = 407,
    SPOOF_NOTICE = 408,
    SQUIT = 409,
    SSL_CERTIFICATE_FILE = 410,
    SSL_CERTIFICATE_FINGERPRINT = 411,
    SSL_CONNECTION_REQUIRED = 412,
    SSL_DH_PARAM_FILE = 413,
    STATS_E_DISABLED = 414,
    STATS_I_OPER_ONLY = 415,
    STATS_K_OPER_ONLY = 416,
    STATS_O_OPER_ONLY = 417,
    STATS_P_OPER_ONLY = 418,
    STATS_U_OPER_ONLY = 419,
    T_ALL = 420,
    T_BOTS = 421,
    T_CALLERID = 422,
    T_CCONN = 423,
    T_CLUSTER = 424,
    T_DEAF = 425,
    T_DEBUG = 426,
    T_DLINE = 427,
    T_EXTERNAL = 428,
    T_FARCONNECT = 429,
    T_FILE = 430,
    T_FULL = 431,
    T_GLOBOPS = 432,
    T_INVISIBLE = 433,
    T_IPV4 = 434,
    T_IPV6 = 435,
    T_LOCOPS = 436,
    T_LOG = 437,
    T_MAX_CLIENTS = 438,
    T_NCHANGE = 439,
    T_NONONREG = 440,
    T_RECVQ = 441,
    T_REJ = 442,
    T_RESTART = 443,
    T_SERVER = 444,
    T_SERVICE = 445,
    T_SERVICES_NAME = 446,
    T_SERVNOTICE = 447,
    T_SET = 448,
    T_SHARED = 449,
    T_SIZE = 450,
    T_SKILL = 451,
    T_SOFTCALLERID = 452,
    T_SPY = 453,
    T_SSL = 454,
    T_SSL_CIPHER_LIST = 455,
    T_SSL_CLIENT_METHOD = 456,
    T_SSL_SERVER_METHOD = 457,
    T_SSLV3 = 458,
    T_TLSV1 = 459,
    T_UMODES = 460,
    T_UNAUTH = 461,
    T_UNDLINE = 462,
    T_UNLIMITED = 463,
    T_UNRESV = 464,
    T_UNXLINE = 465,
    T_WALLOP = 466,
    T_WALLOPS = 467,
    T_WEBIRC = 468,
    TBOOL = 469,
    THROTTLE_COUNT = 470,
    THROTTLE_TIME = 471,
    TKLINE_EXPIRE_NOTICES = 472,
    TMASKED = 473,
    TRUE_NO_OPER_FLOOD = 474,
    TS_MAX_DELTA = 475,
    TS_WARN_DELTA = 476,
    TWODOTS = 477,
    TYPE = 478,
    UNKLINE = 479,
    USE_EGD = 480,
    USE_LOGGING = 481,
    USER = 482,
    VHOST = 483,
    VHOST6 = 484,
    WARN_NO_CONNECT_BLOCK = 485,
    XLINE = 486
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
#define CYCLE_ON_HOST_CHANGE 275
#define DEFAULT_FLOODCOUNT 276
#define DEFAULT_SPLIT_SERVER_COUNT 277
#define DEFAULT_SPLIT_USER_COUNT 278
#define DENY 279
#define DESCRIPTION 280
#define DIE 281
#define DISABLE_AUTH 282
#define DISABLE_FAKE_CHANNELS 283
#define DISABLE_REMOTE_COMMANDS 284
#define DOTS_IN_IDENT 285
#define EGDPOOL_PATH 286
#define EMAIL 287
#define ENCRYPTED 288
#define EXCEED_LIMIT 289
#define EXEMPT 290
#define FAILED_OPER_NOTICE 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_MIN_CIDR 299
#define GLINE_MIN_CIDR6 300
#define GLINE_REQUEST_DURATION 301
#define GLOBAL_KILL 302
#define HAVENT_READ_CONF 303
#define HIDDEN 304
#define HIDDEN_NAME 305
#define HIDE_CHANS 306
#define HIDE_IDLE 307
#define HIDE_IDLE_FROM_OPERS 308
#define HIDE_SERVER_IPS 309
#define HIDE_SERVERS 310
#define HIDE_SERVICES 311
#define HIDE_SPOOF_IPS 312
#define HOST 313
#define HUB 314
#define HUB_MASK 315
#define IGNORE_BOGUS_TS 316
#define INVISIBLE_ON_CONNECT 317
#define INVITE_CLIENT_COUNT 318
#define INVITE_CLIENT_TIME 319
#define IP 320
#define IRCD_AUTH 321
#define IRCD_FLAGS 322
#define IRCD_SID 323
#define JOIN_FLOOD_COUNT 324
#define JOIN_FLOOD_TIME 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KNOCK_CLIENT_COUNT 330
#define KNOCK_CLIENT_TIME 331
#define KNOCK_DELAY_CHANNEL 332
#define LEAF_MASK 333
#define LINKS_DELAY 334
#define LISTEN 335
#define MASK 336
#define MAX_ACCEPT 337
#define MAX_BANS 338
#define MAX_CHANS_PER_OPER 339
#define MAX_CHANS_PER_USER 340
#define MAX_GLOBAL 341
#define MAX_IDENT 342
#define MAX_IDLE 343
#define MAX_LOCAL 344
#define MAX_NICK_CHANGES 345
#define MAX_NICK_LENGTH 346
#define MAX_NICK_TIME 347
#define MAX_NUMBER 348
#define MAX_TARGETS 349
#define MAX_TOPIC_LENGTH 350
#define MAX_WATCH 351
#define MIN_IDLE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define MOTD 357
#define NAME 358
#define NEED_IDENT 359
#define NEED_PASSWORD 360
#define NETWORK_DESC 361
#define NETWORK_NAME 362
#define NICK 363
#define NO_CREATE_ON_SPLIT 364
#define NO_JOIN_ON_SPLIT 365
#define NO_OPER_FLOOD 366
#define NO_TILDE 367
#define NUMBER 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define OPER_ONLY_UMODES 371
#define OPER_PASS_RESV 372
#define OPER_UMODES 373
#define OPERATOR 374
#define OPERS_BYPASS_CALLERID 375
#define PACE_WAIT 376
#define PACE_WAIT_SIMPLE 377
#define PASSWORD 378
#define PATH 379
#define PING_COOKIE 380
#define PING_TIME 381
#define PORT 382
#define QSTRING 383
#define RANDOM_IDLE 384
#define REASON 385
#define REDIRPORT 386
#define REDIRSERV 387
#define REHASH 388
#define REMOTE 389
#define REMOTEBAN 390
#define RESV 391
#define RESV_EXEMPT 392
#define RSA_PRIVATE_KEY_FILE 393
#define RSA_PUBLIC_KEY_FILE 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define MONTHS 400
#define YEARS 401
#define SEND_PASSWORD 402
#define SENDQ 403
#define SERVERHIDE 404
#define SERVERINFO 405
#define SHORT_MOTD 406
#define SPOOF 407
#define SPOOF_NOTICE 408
#define SQUIT 409
#define SSL_CERTIFICATE_FILE 410
#define SSL_CERTIFICATE_FINGERPRINT 411
#define SSL_CONNECTION_REQUIRED 412
#define SSL_DH_PARAM_FILE 413
#define STATS_E_DISABLED 414
#define STATS_I_OPER_ONLY 415
#define STATS_K_OPER_ONLY 416
#define STATS_O_OPER_ONLY 417
#define STATS_P_OPER_ONLY 418
#define STATS_U_OPER_ONLY 419
#define T_ALL 420
#define T_BOTS 421
#define T_CALLERID 422
#define T_CCONN 423
#define T_CLUSTER 424
#define T_DEAF 425
#define T_DEBUG 426
#define T_DLINE 427
#define T_EXTERNAL 428
#define T_FARCONNECT 429
#define T_FILE 430
#define T_FULL 431
#define T_GLOBOPS 432
#define T_INVISIBLE 433
#define T_IPV4 434
#define T_IPV6 435
#define T_LOCOPS 436
#define T_LOG 437
#define T_MAX_CLIENTS 438
#define T_NCHANGE 439
#define T_NONONREG 440
#define T_RECVQ 441
#define T_REJ 442
#define T_RESTART 443
#define T_SERVER 444
#define T_SERVICE 445
#define T_SERVICES_NAME 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_SSL 454
#define T_SSL_CIPHER_LIST 455
#define T_SSL_CLIENT_METHOD 456
#define T_SSL_SERVER_METHOD 457
#define T_SSLV3 458
#define T_TLSV1 459
#define T_UMODES 460
#define T_UNAUTH 461
#define T_UNDLINE 462
#define T_UNLIMITED 463
#define T_UNRESV 464
#define T_UNXLINE 465
#define T_WALLOP 466
#define T_WALLOPS 467
#define T_WEBIRC 468
#define TBOOL 469
#define THROTTLE_COUNT 470
#define THROTTLE_TIME 471
#define TKLINE_EXPIRE_NOTICES 472
#define TMASKED 473
#define TRUE_NO_OPER_FLOOD 474
#define TS_MAX_DELTA 475
#define TS_WARN_DELTA 476
#define TWODOTS 477
#define TYPE 478
#define UNKLINE 479
#define USE_EGD 480
#define USE_LOGGING 481
#define USER 482
#define VHOST 483
#define VHOST6 484
#define WARN_NO_CONNECT_BLOCK 485
#define XLINE 486

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 146 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 521 "conf_parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
