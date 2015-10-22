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
    IP = 317,
    IRCD_AUTH = 318,
    IRCD_FLAGS = 319,
    IRCD_SID = 320,
    JOIN = 321,
    KILL = 322,
    KILL_CHASE_TIME_LIMIT = 323,
    KLINE = 324,
    KLINE_EXEMPT = 325,
    KLINE_MIN_CIDR = 326,
    KLINE_MIN_CIDR6 = 327,
    KNOCK_CLIENT_COUNT = 328,
    KNOCK_CLIENT_TIME = 329,
    KNOCK_DELAY_CHANNEL = 330,
    LEAF_MASK = 331,
    LISTEN = 332,
    MASK = 333,
    MAX_ACCEPT = 334,
    MAX_BANS = 335,
    MAX_CHANNELS = 336,
    MAX_GLOBAL = 337,
    MAX_IDENT = 338,
    MAX_IDLE = 339,
    MAX_LOCAL = 340,
    MAX_NICK_CHANGES = 341,
    MAX_NICK_LENGTH = 342,
    MAX_NICK_TIME = 343,
    MAX_NUMBER = 344,
    MAX_TARGETS = 345,
    MAX_TOPIC_LENGTH = 346,
    MAX_WATCH = 347,
    MIN_IDLE = 348,
    MIN_NONWILDCARD = 349,
    MIN_NONWILDCARD_SIMPLE = 350,
    MODULE = 351,
    MODULES = 352,
    MOTD = 353,
    NAME = 354,
    NEED_IDENT = 355,
    NEED_PASSWORD = 356,
    NETWORK_DESC = 357,
    NETWORK_NAME = 358,
    NICK = 359,
    NO_OPER_FLOOD = 360,
    NO_TILDE = 361,
    NUMBER = 362,
    NUMBER_PER_CIDR = 363,
    NUMBER_PER_IP = 364,
    OPER_ONLY_UMODES = 365,
    OPER_UMODES = 366,
    OPERATOR = 367,
    OPERS_BYPASS_CALLERID = 368,
    PACE_WAIT = 369,
    PACE_WAIT_SIMPLE = 370,
    PASSWORD = 371,
    PATH = 372,
    PING_COOKIE = 373,
    PING_TIME = 374,
    PORT = 375,
    QSTRING = 376,
    RANDOM_IDLE = 377,
    REASON = 378,
    REDIRPORT = 379,
    REDIRSERV = 380,
    REHASH = 381,
    REMOTE = 382,
    REMOTEBAN = 383,
    RESV = 384,
    RESV_EXEMPT = 385,
    RSA_PRIVATE_KEY_FILE = 386,
    SECONDS = 387,
    MINUTES = 388,
    HOURS = 389,
    DAYS = 390,
    WEEKS = 391,
    MONTHS = 392,
    YEARS = 393,
    SEND_PASSWORD = 394,
    SENDQ = 395,
    SERVERHIDE = 396,
    SERVERINFO = 397,
    SHORT_MOTD = 398,
    SPOOF = 399,
    SPOOF_NOTICE = 400,
    SQUIT = 401,
    SSL_CERTIFICATE_FILE = 402,
    SSL_CERTIFICATE_FINGERPRINT = 403,
    SSL_CONNECTION_REQUIRED = 404,
    SSL_DH_ELLIPTIC_CURVE = 405,
    SSL_DH_PARAM_FILE = 406,
    SSL_MESSAGE_DIGEST_ALGORITHM = 407,
    STATS_E_DISABLED = 408,
    STATS_I_OPER_ONLY = 409,
    STATS_K_OPER_ONLY = 410,
    STATS_M_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BOTS = 416,
    T_CALLERID = 417,
    T_CCONN = 418,
    T_COMMAND = 419,
    T_CLUSTER = 420,
    T_DEAF = 421,
    T_DEBUG = 422,
    T_DLINE = 423,
    T_EXTERNAL = 424,
    T_FARCONNECT = 425,
    T_FILE = 426,
    T_FULL = 427,
    T_GLOBOPS = 428,
    T_INVISIBLE = 429,
    T_IPV4 = 430,
    T_IPV6 = 431,
    T_LOCOPS = 432,
    T_LOG = 433,
    T_NCHANGE = 434,
    T_NONONREG = 435,
    T_OPME = 436,
    T_PREPEND = 437,
    T_PSEUDO = 438,
    T_RECVQ = 439,
    T_REJ = 440,
    T_RESTART = 441,
    T_SERVER = 442,
    T_SERVICE = 443,
    T_SERVNOTICE = 444,
    T_SET = 445,
    T_SHARED = 446,
    T_SIZE = 447,
    T_SKILL = 448,
    T_SOFTCALLERID = 449,
    T_SPY = 450,
    T_SSL = 451,
    T_SSL_CIPHER_LIST = 452,
    T_TARGET = 453,
    T_UMODES = 454,
    T_UNAUTH = 455,
    T_UNDLINE = 456,
    T_UNLIMITED = 457,
    T_UNRESV = 458,
    T_UNXLINE = 459,
    T_WALLOP = 460,
    T_WALLOPS = 461,
    T_WEBIRC = 462,
    TBOOL = 463,
    THROTTLE_COUNT = 464,
    THROTTLE_TIME = 465,
    TKLINE_EXPIRE_NOTICES = 466,
    TMASKED = 467,
    TS_MAX_DELTA = 468,
    TS_WARN_DELTA = 469,
    TWODOTS = 470,
    TYPE = 471,
    UNKLINE = 472,
    USE_LOGGING = 473,
    USER = 474,
    VHOST = 475,
    VHOST6 = 476,
    WARN_NO_CONNECT_BLOCK = 477,
    WHOIS = 478,
    XLINE = 479,
    XLINE_EXEMPT = 480
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
#define IP 317
#define IRCD_AUTH 318
#define IRCD_FLAGS 319
#define IRCD_SID 320
#define JOIN 321
#define KILL 322
#define KILL_CHASE_TIME_LIMIT 323
#define KLINE 324
#define KLINE_EXEMPT 325
#define KLINE_MIN_CIDR 326
#define KLINE_MIN_CIDR6 327
#define KNOCK_CLIENT_COUNT 328
#define KNOCK_CLIENT_TIME 329
#define KNOCK_DELAY_CHANNEL 330
#define LEAF_MASK 331
#define LISTEN 332
#define MASK 333
#define MAX_ACCEPT 334
#define MAX_BANS 335
#define MAX_CHANNELS 336
#define MAX_GLOBAL 337
#define MAX_IDENT 338
#define MAX_IDLE 339
#define MAX_LOCAL 340
#define MAX_NICK_CHANGES 341
#define MAX_NICK_LENGTH 342
#define MAX_NICK_TIME 343
#define MAX_NUMBER 344
#define MAX_TARGETS 345
#define MAX_TOPIC_LENGTH 346
#define MAX_WATCH 347
#define MIN_IDLE 348
#define MIN_NONWILDCARD 349
#define MIN_NONWILDCARD_SIMPLE 350
#define MODULE 351
#define MODULES 352
#define MOTD 353
#define NAME 354
#define NEED_IDENT 355
#define NEED_PASSWORD 356
#define NETWORK_DESC 357
#define NETWORK_NAME 358
#define NICK 359
#define NO_OPER_FLOOD 360
#define NO_TILDE 361
#define NUMBER 362
#define NUMBER_PER_CIDR 363
#define NUMBER_PER_IP 364
#define OPER_ONLY_UMODES 365
#define OPER_UMODES 366
#define OPERATOR 367
#define OPERS_BYPASS_CALLERID 368
#define PACE_WAIT 369
#define PACE_WAIT_SIMPLE 370
#define PASSWORD 371
#define PATH 372
#define PING_COOKIE 373
#define PING_TIME 374
#define PORT 375
#define QSTRING 376
#define RANDOM_IDLE 377
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RESV 384
#define RESV_EXEMPT 385
#define RSA_PRIVATE_KEY_FILE 386
#define SECONDS 387
#define MINUTES 388
#define HOURS 389
#define DAYS 390
#define WEEKS 391
#define MONTHS 392
#define YEARS 393
#define SEND_PASSWORD 394
#define SENDQ 395
#define SERVERHIDE 396
#define SERVERINFO 397
#define SHORT_MOTD 398
#define SPOOF 399
#define SPOOF_NOTICE 400
#define SQUIT 401
#define SSL_CERTIFICATE_FILE 402
#define SSL_CERTIFICATE_FINGERPRINT 403
#define SSL_CONNECTION_REQUIRED 404
#define SSL_DH_ELLIPTIC_CURVE 405
#define SSL_DH_PARAM_FILE 406
#define SSL_MESSAGE_DIGEST_ALGORITHM 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_M_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BOTS 416
#define T_CALLERID 417
#define T_CCONN 418
#define T_COMMAND 419
#define T_CLUSTER 420
#define T_DEAF 421
#define T_DEBUG 422
#define T_DLINE 423
#define T_EXTERNAL 424
#define T_FARCONNECT 425
#define T_FILE 426
#define T_FULL 427
#define T_GLOBOPS 428
#define T_INVISIBLE 429
#define T_IPV4 430
#define T_IPV6 431
#define T_LOCOPS 432
#define T_LOG 433
#define T_NCHANGE 434
#define T_NONONREG 435
#define T_OPME 436
#define T_PREPEND 437
#define T_PSEUDO 438
#define T_RECVQ 439
#define T_REJ 440
#define T_RESTART 441
#define T_SERVER 442
#define T_SERVICE 443
#define T_SERVNOTICE 444
#define T_SET 445
#define T_SHARED 446
#define T_SIZE 447
#define T_SKILL 448
#define T_SOFTCALLERID 449
#define T_SPY 450
#define T_SSL 451
#define T_SSL_CIPHER_LIST 452
#define T_TARGET 453
#define T_UMODES 454
#define T_UNAUTH 455
#define T_UNDLINE 456
#define T_UNLIMITED 457
#define T_UNRESV 458
#define T_UNXLINE 459
#define T_WALLOP 460
#define T_WALLOPS 461
#define T_WEBIRC 462
#define TBOOL 463
#define THROTTLE_COUNT 464
#define THROTTLE_TIME 465
#define TKLINE_EXPIRE_NOTICES 466
#define TMASKED 467
#define TS_MAX_DELTA 468
#define TS_WARN_DELTA 469
#define TWODOTS 470
#define TYPE 471
#define UNKLINE 472
#define USE_LOGGING 473
#define USER 474
#define VHOST 475
#define VHOST6 476
#define WARN_NO_CONNECT_BLOCK 477
#define WHOIS 478
#define XLINE 479
#define XLINE_EXEMPT 480

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 509 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
