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
    CLOSE = 275,
    CONNECT = 276,
    CONNECTFREQ = 277,
    CYCLE_ON_HOST_CHANGE = 278,
    DEFAULT_FLOODCOUNT = 279,
    DEFAULT_JOIN_FLOOD_COUNT = 280,
    DEFAULT_JOIN_FLOOD_TIME = 281,
    DEFAULT_MAX_CLIENTS = 282,
    DENY = 283,
    DESCRIPTION = 284,
    DIE = 285,
    DISABLE_AUTH = 286,
    DISABLE_FAKE_CHANNELS = 287,
    DISABLE_REMOTE_COMMANDS = 288,
    DLINE_MIN_CIDR = 289,
    DLINE_MIN_CIDR6 = 290,
    DOTS_IN_IDENT = 291,
    EMAIL = 292,
    ENCRYPTED = 293,
    EXCEED_LIMIT = 294,
    EXEMPT = 295,
    FAILED_OPER_NOTICE = 296,
    FLATTEN_LINKS = 297,
    FLATTEN_LINKS_DELAY = 298,
    FLATTEN_LINKS_FILE = 299,
    GECOS = 300,
    GENERAL = 301,
    HIDDEN = 302,
    HIDDEN_NAME = 303,
    HIDE_CHANS = 304,
    HIDE_IDLE = 305,
    HIDE_IDLE_FROM_OPERS = 306,
    HIDE_SERVER_IPS = 307,
    HIDE_SERVERS = 308,
    HIDE_SERVICES = 309,
    HOST = 310,
    HUB = 311,
    HUB_MASK = 312,
    IGNORE_BOGUS_TS = 313,
    INVISIBLE_ON_CONNECT = 314,
    INVITE_CLIENT_COUNT = 315,
    INVITE_CLIENT_TIME = 316,
    INVITE_DELAY_CHANNEL = 317,
    IP = 318,
    IRCD_AUTH = 319,
    IRCD_FLAGS = 320,
    IRCD_SID = 321,
    JOIN = 322,
    KILL = 323,
    KILL_CHASE_TIME_LIMIT = 324,
    KLINE = 325,
    KLINE_EXEMPT = 326,
    KLINE_MIN_CIDR = 327,
    KLINE_MIN_CIDR6 = 328,
    KNOCK_CLIENT_COUNT = 329,
    KNOCK_CLIENT_TIME = 330,
    KNOCK_DELAY_CHANNEL = 331,
    LEAF_MASK = 332,
    LISTEN = 333,
    MASK = 334,
    MAX_ACCEPT = 335,
    MAX_BANS = 336,
    MAX_CHANNELS = 337,
    MAX_GLOBAL = 338,
    MAX_IDENT = 339,
    MAX_IDLE = 340,
    MAX_LOCAL = 341,
    MAX_NICK_CHANGES = 342,
    MAX_NICK_LENGTH = 343,
    MAX_NICK_TIME = 344,
    MAX_NUMBER = 345,
    MAX_TARGETS = 346,
    MAX_TOPIC_LENGTH = 347,
    MAX_WATCH = 348,
    MIN_IDLE = 349,
    MIN_NONWILDCARD = 350,
    MIN_NONWILDCARD_SIMPLE = 351,
    MODULE = 352,
    MODULES = 353,
    MOTD = 354,
    NAME = 355,
    NEED_IDENT = 356,
    NEED_PASSWORD = 357,
    NETWORK_DESC = 358,
    NETWORK_NAME = 359,
    NICK = 360,
    NO_OPER_FLOOD = 361,
    NO_TILDE = 362,
    NUMBER = 363,
    NUMBER_PER_CIDR = 364,
    NUMBER_PER_IP = 365,
    OPER_ONLY_UMODES = 366,
    OPER_UMODES = 367,
    OPERATOR = 368,
    OPERS_BYPASS_CALLERID = 369,
    PACE_WAIT = 370,
    PACE_WAIT_SIMPLE = 371,
    PASSWORD = 372,
    PATH = 373,
    PING_COOKIE = 374,
    PING_TIME = 375,
    PORT = 376,
    QSTRING = 377,
    RANDOM_IDLE = 378,
    REASON = 379,
    REDIRPORT = 380,
    REDIRSERV = 381,
    REHASH = 382,
    REMOTE = 383,
    REMOTEBAN = 384,
    RESV = 385,
    RESV_EXEMPT = 386,
    RSA_PRIVATE_KEY_FILE = 387,
    SECONDS = 388,
    MINUTES = 389,
    HOURS = 390,
    DAYS = 391,
    WEEKS = 392,
    MONTHS = 393,
    YEARS = 394,
    SEND_PASSWORD = 395,
    SENDQ = 396,
    SERVERHIDE = 397,
    SERVERINFO = 398,
    SHORT_MOTD = 399,
    SPOOF = 400,
    SPOOF_NOTICE = 401,
    SQUIT = 402,
    SSL_CERTIFICATE_FILE = 403,
    SSL_CERTIFICATE_FINGERPRINT = 404,
    SSL_CONNECTION_REQUIRED = 405,
    SSL_DH_ELLIPTIC_CURVE = 406,
    SSL_DH_PARAM_FILE = 407,
    SSL_MESSAGE_DIGEST_ALGORITHM = 408,
    STATS_E_DISABLED = 409,
    STATS_I_OPER_ONLY = 410,
    STATS_K_OPER_ONLY = 411,
    STATS_M_OPER_ONLY = 412,
    STATS_O_OPER_ONLY = 413,
    STATS_P_OPER_ONLY = 414,
    STATS_U_OPER_ONLY = 415,
    T_ALL = 416,
    T_BOTS = 417,
    T_CALLERID = 418,
    T_CCONN = 419,
    T_COMMAND = 420,
    T_CLUSTER = 421,
    T_DEAF = 422,
    T_DEBUG = 423,
    T_DLINE = 424,
    T_EXTERNAL = 425,
    T_FARCONNECT = 426,
    T_FILE = 427,
    T_FULL = 428,
    T_GLOBOPS = 429,
    T_INVISIBLE = 430,
    T_IPV4 = 431,
    T_IPV6 = 432,
    T_LOCOPS = 433,
    T_LOG = 434,
    T_NCHANGE = 435,
    T_NONONREG = 436,
    T_OPME = 437,
    T_PREPEND = 438,
    T_PSEUDO = 439,
    T_RECVQ = 440,
    T_REJ = 441,
    T_RESTART = 442,
    T_SERVER = 443,
    T_SERVICE = 444,
    T_SERVNOTICE = 445,
    T_SET = 446,
    T_SHARED = 447,
    T_SIZE = 448,
    T_SKILL = 449,
    T_SOFTCALLERID = 450,
    T_SPY = 451,
    T_SSL = 452,
    T_SSL_CIPHER_LIST = 453,
    T_TARGET = 454,
    T_UMODES = 455,
    T_UNAUTH = 456,
    T_UNDLINE = 457,
    T_UNLIMITED = 458,
    T_UNRESV = 459,
    T_UNXLINE = 460,
    T_WALLOP = 461,
    T_WALLOPS = 462,
    T_WEBIRC = 463,
    TBOOL = 464,
    THROTTLE_COUNT = 465,
    THROTTLE_TIME = 466,
    TKLINE_EXPIRE_NOTICES = 467,
    TMASKED = 468,
    TS_MAX_DELTA = 469,
    TS_WARN_DELTA = 470,
    TWODOTS = 471,
    TYPE = 472,
    UNKLINE = 473,
    USE_LOGGING = 474,
    USER = 475,
    VHOST = 476,
    VHOST6 = 477,
    WARN_NO_CONNECT_BLOCK = 478,
    WHOIS = 479,
    XLINE = 480,
    XLINE_EXEMPT = 481
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
#define CLOSE 275
#define CONNECT 276
#define CONNECTFREQ 277
#define CYCLE_ON_HOST_CHANGE 278
#define DEFAULT_FLOODCOUNT 279
#define DEFAULT_JOIN_FLOOD_COUNT 280
#define DEFAULT_JOIN_FLOOD_TIME 281
#define DEFAULT_MAX_CLIENTS 282
#define DENY 283
#define DESCRIPTION 284
#define DIE 285
#define DISABLE_AUTH 286
#define DISABLE_FAKE_CHANNELS 287
#define DISABLE_REMOTE_COMMANDS 288
#define DLINE_MIN_CIDR 289
#define DLINE_MIN_CIDR6 290
#define DOTS_IN_IDENT 291
#define EMAIL 292
#define ENCRYPTED 293
#define EXCEED_LIMIT 294
#define EXEMPT 295
#define FAILED_OPER_NOTICE 296
#define FLATTEN_LINKS 297
#define FLATTEN_LINKS_DELAY 298
#define FLATTEN_LINKS_FILE 299
#define GECOS 300
#define GENERAL 301
#define HIDDEN 302
#define HIDDEN_NAME 303
#define HIDE_CHANS 304
#define HIDE_IDLE 305
#define HIDE_IDLE_FROM_OPERS 306
#define HIDE_SERVER_IPS 307
#define HIDE_SERVERS 308
#define HIDE_SERVICES 309
#define HOST 310
#define HUB 311
#define HUB_MASK 312
#define IGNORE_BOGUS_TS 313
#define INVISIBLE_ON_CONNECT 314
#define INVITE_CLIENT_COUNT 315
#define INVITE_CLIENT_TIME 316
#define INVITE_DELAY_CHANNEL 317
#define IP 318
#define IRCD_AUTH 319
#define IRCD_FLAGS 320
#define IRCD_SID 321
#define JOIN 322
#define KILL 323
#define KILL_CHASE_TIME_LIMIT 324
#define KLINE 325
#define KLINE_EXEMPT 326
#define KLINE_MIN_CIDR 327
#define KLINE_MIN_CIDR6 328
#define KNOCK_CLIENT_COUNT 329
#define KNOCK_CLIENT_TIME 330
#define KNOCK_DELAY_CHANNEL 331
#define LEAF_MASK 332
#define LISTEN 333
#define MASK 334
#define MAX_ACCEPT 335
#define MAX_BANS 336
#define MAX_CHANNELS 337
#define MAX_GLOBAL 338
#define MAX_IDENT 339
#define MAX_IDLE 340
#define MAX_LOCAL 341
#define MAX_NICK_CHANGES 342
#define MAX_NICK_LENGTH 343
#define MAX_NICK_TIME 344
#define MAX_NUMBER 345
#define MAX_TARGETS 346
#define MAX_TOPIC_LENGTH 347
#define MAX_WATCH 348
#define MIN_IDLE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define MOTD 354
#define NAME 355
#define NEED_IDENT 356
#define NEED_PASSWORD 357
#define NETWORK_DESC 358
#define NETWORK_NAME 359
#define NICK 360
#define NO_OPER_FLOOD 361
#define NO_TILDE 362
#define NUMBER 363
#define NUMBER_PER_CIDR 364
#define NUMBER_PER_IP 365
#define OPER_ONLY_UMODES 366
#define OPER_UMODES 367
#define OPERATOR 368
#define OPERS_BYPASS_CALLERID 369
#define PACE_WAIT 370
#define PACE_WAIT_SIMPLE 371
#define PASSWORD 372
#define PATH 373
#define PING_COOKIE 374
#define PING_TIME 375
#define PORT 376
#define QSTRING 377
#define RANDOM_IDLE 378
#define REASON 379
#define REDIRPORT 380
#define REDIRSERV 381
#define REHASH 382
#define REMOTE 383
#define REMOTEBAN 384
#define RESV 385
#define RESV_EXEMPT 386
#define RSA_PRIVATE_KEY_FILE 387
#define SECONDS 388
#define MINUTES 389
#define HOURS 390
#define DAYS 391
#define WEEKS 392
#define MONTHS 393
#define YEARS 394
#define SEND_PASSWORD 395
#define SENDQ 396
#define SERVERHIDE 397
#define SERVERINFO 398
#define SHORT_MOTD 399
#define SPOOF 400
#define SPOOF_NOTICE 401
#define SQUIT 402
#define SSL_CERTIFICATE_FILE 403
#define SSL_CERTIFICATE_FINGERPRINT 404
#define SSL_CONNECTION_REQUIRED 405
#define SSL_DH_ELLIPTIC_CURVE 406
#define SSL_DH_PARAM_FILE 407
#define SSL_MESSAGE_DIGEST_ALGORITHM 408
#define STATS_E_DISABLED 409
#define STATS_I_OPER_ONLY 410
#define STATS_K_OPER_ONLY 411
#define STATS_M_OPER_ONLY 412
#define STATS_O_OPER_ONLY 413
#define STATS_P_OPER_ONLY 414
#define STATS_U_OPER_ONLY 415
#define T_ALL 416
#define T_BOTS 417
#define T_CALLERID 418
#define T_CCONN 419
#define T_COMMAND 420
#define T_CLUSTER 421
#define T_DEAF 422
#define T_DEBUG 423
#define T_DLINE 424
#define T_EXTERNAL 425
#define T_FARCONNECT 426
#define T_FILE 427
#define T_FULL 428
#define T_GLOBOPS 429
#define T_INVISIBLE 430
#define T_IPV4 431
#define T_IPV6 432
#define T_LOCOPS 433
#define T_LOG 434
#define T_NCHANGE 435
#define T_NONONREG 436
#define T_OPME 437
#define T_PREPEND 438
#define T_PSEUDO 439
#define T_RECVQ 440
#define T_REJ 441
#define T_RESTART 442
#define T_SERVER 443
#define T_SERVICE 444
#define T_SERVNOTICE 445
#define T_SET 446
#define T_SHARED 447
#define T_SIZE 448
#define T_SKILL 449
#define T_SOFTCALLERID 450
#define T_SPY 451
#define T_SSL 452
#define T_SSL_CIPHER_LIST 453
#define T_TARGET 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_WALLOP 461
#define T_WALLOPS 462
#define T_WEBIRC 463
#define TBOOL 464
#define THROTTLE_COUNT 465
#define THROTTLE_TIME 466
#define TKLINE_EXPIRE_NOTICES 467
#define TMASKED 468
#define TS_MAX_DELTA 469
#define TS_WARN_DELTA 470
#define TWODOTS 471
#define TYPE 472
#define UNKLINE 473
#define USE_LOGGING 474
#define USER 475
#define VHOST 476
#define VHOST6 477
#define WARN_NO_CONNECT_BLOCK 478
#define WHOIS 479
#define XLINE 480
#define XLINE_EXEMPT 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 138 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 511 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
