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
    HIDE_IDLE_FROM_OPERS = 306,
    HIDE_SERVER_IPS = 307,
    HIDE_SERVERS = 308,
    HIDE_SERVICES = 309,
    HIDE_SPOOF_IPS = 310,
    HOST = 311,
    HUB = 312,
    HUB_MASK = 313,
    IGNORE_BOGUS_TS = 314,
    INVISIBLE_ON_CONNECT = 315,
    IP = 316,
    IRCD_AUTH = 317,
    IRCD_FLAGS = 318,
    IRCD_SID = 319,
    JOIN_FLOOD_COUNT = 320,
    JOIN_FLOOD_TIME = 321,
    KILL = 322,
    KILL_CHASE_TIME_LIMIT = 323,
    KLINE = 324,
    KLINE_EXEMPT = 325,
    KNOCK_DELAY = 326,
    KNOCK_DELAY_CHANNEL = 327,
    LEAF_MASK = 328,
    LINKS_DELAY = 329,
    LISTEN = 330,
    MASK = 331,
    MAX_ACCEPT = 332,
    MAX_BANS = 333,
    MAX_CHANS_PER_OPER = 334,
    MAX_CHANS_PER_USER = 335,
    MAX_GLOBAL = 336,
    MAX_IDENT = 337,
    MAX_IDLE = 338,
    MAX_LOCAL = 339,
    MAX_NICK_CHANGES = 340,
    MAX_NICK_LENGTH = 341,
    MAX_NICK_TIME = 342,
    MAX_NUMBER = 343,
    MAX_TARGETS = 344,
    MAX_TOPIC_LENGTH = 345,
    MAX_WATCH = 346,
    MIN_IDLE = 347,
    MIN_NONWILDCARD = 348,
    MIN_NONWILDCARD_SIMPLE = 349,
    MODULE = 350,
    MODULES = 351,
    MOTD = 352,
    NAME = 353,
    NEED_IDENT = 354,
    NEED_PASSWORD = 355,
    NETWORK_DESC = 356,
    NETWORK_NAME = 357,
    NICK = 358,
    NO_CREATE_ON_SPLIT = 359,
    NO_JOIN_ON_SPLIT = 360,
    NO_OPER_FLOOD = 361,
    NO_TILDE = 362,
    NUMBER = 363,
    NUMBER_PER_CIDR = 364,
    NUMBER_PER_IP = 365,
    OPER_ONLY_UMODES = 366,
    OPER_PASS_RESV = 367,
    OPER_UMODES = 368,
    OPERATOR = 369,
    OPERS_BYPASS_CALLERID = 370,
    PACE_WAIT = 371,
    PACE_WAIT_SIMPLE = 372,
    PASSWORD = 373,
    PATH = 374,
    PING_COOKIE = 375,
    PING_TIME = 376,
    PORT = 377,
    QSTRING = 378,
    RANDOM_IDLE = 379,
    REASON = 380,
    REDIRPORT = 381,
    REDIRSERV = 382,
    REHASH = 383,
    REMOTE = 384,
    REMOTEBAN = 385,
    RESV = 386,
    RESV_EXEMPT = 387,
    RSA_PRIVATE_KEY_FILE = 388,
    RSA_PUBLIC_KEY_FILE = 389,
    SECONDS = 390,
    MINUTES = 391,
    HOURS = 392,
    DAYS = 393,
    WEEKS = 394,
    MONTHS = 395,
    YEARS = 396,
    SEND_PASSWORD = 397,
    SENDQ = 398,
    SERVERHIDE = 399,
    SERVERINFO = 400,
    SHORT_MOTD = 401,
    SPOOF = 402,
    SPOOF_NOTICE = 403,
    SQUIT = 404,
    SSL_CERTIFICATE_FILE = 405,
    SSL_CERTIFICATE_FINGERPRINT = 406,
    SSL_CONNECTION_REQUIRED = 407,
    SSL_DH_PARAM_FILE = 408,
    STATS_E_DISABLED = 409,
    STATS_I_OPER_ONLY = 410,
    STATS_K_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BOTS = 416,
    T_CALLERID = 417,
    T_CCONN = 418,
    T_CLUSTER = 419,
    T_DEAF = 420,
    T_DEBUG = 421,
    T_DLINE = 422,
    T_EXTERNAL = 423,
    T_FARCONNECT = 424,
    T_FILE = 425,
    T_FULL = 426,
    T_GLOBOPS = 427,
    T_INVISIBLE = 428,
    T_IPV4 = 429,
    T_IPV6 = 430,
    T_LOCOPS = 431,
    T_LOG = 432,
    T_MAX_CLIENTS = 433,
    T_NCHANGE = 434,
    T_NONONREG = 435,
    T_OPERWALL = 436,
    T_RECVQ = 437,
    T_REJ = 438,
    T_RESTART = 439,
    T_SERVER = 440,
    T_SERVICE = 441,
    T_SERVICES_NAME = 442,
    T_SERVNOTICE = 443,
    T_SET = 444,
    T_SHARED = 445,
    T_SIZE = 446,
    T_SKILL = 447,
    T_SOFTCALLERID = 448,
    T_SPY = 449,
    T_SSL = 450,
    T_SSL_CIPHER_LIST = 451,
    T_SSL_CLIENT_METHOD = 452,
    T_SSL_SERVER_METHOD = 453,
    T_SSLV3 = 454,
    T_TLSV1 = 455,
    T_UMODES = 456,
    T_UNAUTH = 457,
    T_UNDLINE = 458,
    T_UNLIMITED = 459,
    T_UNRESV = 460,
    T_UNXLINE = 461,
    T_WALLOP = 462,
    T_WALLOPS = 463,
    T_WEBIRC = 464,
    TBOOL = 465,
    THROTTLE_TIME = 466,
    TKLINE_EXPIRE_NOTICES = 467,
    TMASKED = 468,
    TRUE_NO_OPER_FLOOD = 469,
    TS_MAX_DELTA = 470,
    TS_WARN_DELTA = 471,
    TWODOTS = 472,
    TYPE = 473,
    UNKLINE = 474,
    USE_EGD = 475,
    USE_LOGGING = 476,
    USER = 477,
    VHOST = 478,
    VHOST6 = 479,
    WARN_NO_CONNECT_BLOCK = 480,
    XLINE = 481
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
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define IRCD_AUTH 317
#define IRCD_FLAGS 318
#define IRCD_SID 319
#define JOIN_FLOOD_COUNT 320
#define JOIN_FLOOD_TIME 321
#define KILL 322
#define KILL_CHASE_TIME_LIMIT 323
#define KLINE 324
#define KLINE_EXEMPT 325
#define KNOCK_DELAY 326
#define KNOCK_DELAY_CHANNEL 327
#define LEAF_MASK 328
#define LINKS_DELAY 329
#define LISTEN 330
#define MASK 331
#define MAX_ACCEPT 332
#define MAX_BANS 333
#define MAX_CHANS_PER_OPER 334
#define MAX_CHANS_PER_USER 335
#define MAX_GLOBAL 336
#define MAX_IDENT 337
#define MAX_IDLE 338
#define MAX_LOCAL 339
#define MAX_NICK_CHANGES 340
#define MAX_NICK_LENGTH 341
#define MAX_NICK_TIME 342
#define MAX_NUMBER 343
#define MAX_TARGETS 344
#define MAX_TOPIC_LENGTH 345
#define MAX_WATCH 346
#define MIN_IDLE 347
#define MIN_NONWILDCARD 348
#define MIN_NONWILDCARD_SIMPLE 349
#define MODULE 350
#define MODULES 351
#define MOTD 352
#define NAME 353
#define NEED_IDENT 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NO_CREATE_ON_SPLIT 359
#define NO_JOIN_ON_SPLIT 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP 365
#define OPER_ONLY_UMODES 366
#define OPER_PASS_RESV 367
#define OPER_UMODES 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PORT 377
#define QSTRING 378
#define RANDOM_IDLE 379
#define REASON 380
#define REDIRPORT 381
#define REDIRSERV 382
#define REHASH 383
#define REMOTE 384
#define REMOTEBAN 385
#define RESV 386
#define RESV_EXEMPT 387
#define RSA_PRIVATE_KEY_FILE 388
#define RSA_PUBLIC_KEY_FILE 389
#define SECONDS 390
#define MINUTES 391
#define HOURS 392
#define DAYS 393
#define WEEKS 394
#define MONTHS 395
#define YEARS 396
#define SEND_PASSWORD 397
#define SENDQ 398
#define SERVERHIDE 399
#define SERVERINFO 400
#define SHORT_MOTD 401
#define SPOOF 402
#define SPOOF_NOTICE 403
#define SQUIT 404
#define SSL_CERTIFICATE_FILE 405
#define SSL_CERTIFICATE_FINGERPRINT 406
#define SSL_CONNECTION_REQUIRED 407
#define SSL_DH_PARAM_FILE 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BOTS 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_CLUSTER 419
#define T_DEAF 420
#define T_DEBUG 421
#define T_DLINE 422
#define T_EXTERNAL 423
#define T_FARCONNECT 424
#define T_FILE 425
#define T_FULL 426
#define T_GLOBOPS 427
#define T_INVISIBLE 428
#define T_IPV4 429
#define T_IPV6 430
#define T_LOCOPS 431
#define T_LOG 432
#define T_MAX_CLIENTS 433
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPERWALL 436
#define T_RECVQ 437
#define T_REJ 438
#define T_RESTART 439
#define T_SERVER 440
#define T_SERVICE 441
#define T_SERVICES_NAME 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_SKILL 447
#define T_SOFTCALLERID 448
#define T_SPY 449
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_SSL_CLIENT_METHOD 452
#define T_SSL_SERVER_METHOD 453
#define T_SSLV3 454
#define T_TLSV1 455
#define T_UMODES 456
#define T_UNAUTH 457
#define T_UNDLINE 458
#define T_UNLIMITED 459
#define T_UNRESV 460
#define T_UNXLINE 461
#define T_WALLOP 462
#define T_WALLOPS 463
#define T_WEBIRC 464
#define TBOOL 465
#define THROTTLE_TIME 466
#define TKLINE_EXPIRE_NOTICES 467
#define TMASKED 468
#define TRUE_NO_OPER_FLOOD 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_EGD 475
#define USE_LOGGING 476
#define USER 477
#define VHOST 478
#define VHOST6 479
#define WARN_NO_CONNECT_BLOCK 480
#define XLINE 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 146 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 511 "conf_parser.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
