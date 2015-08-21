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
    DENY = 282,
    DESCRIPTION = 283,
    DIE = 284,
    DISABLE_AUTH = 285,
    DISABLE_FAKE_CHANNELS = 286,
    DISABLE_REMOTE_COMMANDS = 287,
    DLINE_MIN_CIDR = 288,
    DLINE_MIN_CIDR6 = 289,
    DOTS_IN_IDENT = 290,
    EMAIL = 291,
    ENCRYPTED = 292,
    EXCEED_LIMIT = 293,
    EXEMPT = 294,
    FAILED_OPER_NOTICE = 295,
    FLATTEN_LINKS = 296,
    GECOS = 297,
    GENERAL = 298,
    HIDDEN = 299,
    HIDDEN_NAME = 300,
    HIDE_CHANS = 301,
    HIDE_IDLE = 302,
    HIDE_IDLE_FROM_OPERS = 303,
    HIDE_SERVER_IPS = 304,
    HIDE_SERVERS = 305,
    HIDE_SERVICES = 306,
    HOST = 307,
    HUB = 308,
    HUB_MASK = 309,
    IGNORE_BOGUS_TS = 310,
    INVISIBLE_ON_CONNECT = 311,
    INVITE_CLIENT_COUNT = 312,
    INVITE_CLIENT_TIME = 313,
    IP = 314,
    IRCD_AUTH = 315,
    IRCD_FLAGS = 316,
    IRCD_SID = 317,
    KILL = 318,
    KILL_CHASE_TIME_LIMIT = 319,
    KLINE = 320,
    KLINE_EXEMPT = 321,
    KLINE_MIN_CIDR = 322,
    KLINE_MIN_CIDR6 = 323,
    KNOCK_CLIENT_COUNT = 324,
    KNOCK_CLIENT_TIME = 325,
    KNOCK_DELAY_CHANNEL = 326,
    LEAF_MASK = 327,
    LINKS_DELAY = 328,
    LISTEN = 329,
    MASK = 330,
    MAX_ACCEPT = 331,
    MAX_BANS = 332,
    MAX_CHANNELS = 333,
    MAX_GLOBAL = 334,
    MAX_IDENT = 335,
    MAX_IDLE = 336,
    MAX_LOCAL = 337,
    MAX_NICK_CHANGES = 338,
    MAX_NICK_LENGTH = 339,
    MAX_NICK_TIME = 340,
    MAX_NUMBER = 341,
    MAX_TARGETS = 342,
    MAX_TOPIC_LENGTH = 343,
    MAX_WATCH = 344,
    MIN_IDLE = 345,
    MIN_NONWILDCARD = 346,
    MIN_NONWILDCARD_SIMPLE = 347,
    MODULE = 348,
    MODULES = 349,
    MOTD = 350,
    NAME = 351,
    NEED_IDENT = 352,
    NEED_PASSWORD = 353,
    NETWORK_DESC = 354,
    NETWORK_NAME = 355,
    NICK = 356,
    NO_OPER_FLOOD = 357,
    NO_TILDE = 358,
    NUMBER = 359,
    NUMBER_PER_CIDR = 360,
    NUMBER_PER_IP = 361,
    OPER_ONLY_UMODES = 362,
    OPER_PASS_RESV = 363,
    OPER_UMODES = 364,
    OPERATOR = 365,
    OPERS_BYPASS_CALLERID = 366,
    PACE_WAIT = 367,
    PACE_WAIT_SIMPLE = 368,
    PASSWORD = 369,
    PATH = 370,
    PING_COOKIE = 371,
    PING_TIME = 372,
    PORT = 373,
    QSTRING = 374,
    RANDOM_IDLE = 375,
    REASON = 376,
    REDIRPORT = 377,
    REDIRSERV = 378,
    REHASH = 379,
    REMOTE = 380,
    REMOTEBAN = 381,
    RESV = 382,
    RESV_EXEMPT = 383,
    RSA_PRIVATE_KEY_FILE = 384,
    RSA_PUBLIC_KEY_FILE = 385,
    SECONDS = 386,
    MINUTES = 387,
    HOURS = 388,
    DAYS = 389,
    WEEKS = 390,
    MONTHS = 391,
    YEARS = 392,
    SEND_PASSWORD = 393,
    SENDQ = 394,
    SERVERHIDE = 395,
    SERVERINFO = 396,
    SHORT_MOTD = 397,
    SPOOF = 398,
    SPOOF_NOTICE = 399,
    SQUIT = 400,
    SSL_CERTIFICATE_FILE = 401,
    SSL_CERTIFICATE_FINGERPRINT = 402,
    SSL_CONNECTION_REQUIRED = 403,
    SSL_DH_ELLIPTIC_CURVE = 404,
    SSL_DH_PARAM_FILE = 405,
    SSL_MESSAGE_DIGEST_ALGORITHM = 406,
    STATS_E_DISABLED = 407,
    STATS_I_OPER_ONLY = 408,
    STATS_K_OPER_ONLY = 409,
    STATS_M_OPER_ONLY = 410,
    STATS_O_OPER_ONLY = 411,
    STATS_P_OPER_ONLY = 412,
    STATS_U_OPER_ONLY = 413,
    T_ALL = 414,
    T_BOTS = 415,
    T_CALLERID = 416,
    T_CCONN = 417,
    T_COMMAND = 418,
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
    T_NCHANGE = 433,
    T_NONONREG = 434,
    T_OPME = 435,
    T_PREPEND = 436,
    T_PSEUDO = 437,
    T_RECVQ = 438,
    T_REJ = 439,
    T_RESTART = 440,
    T_SERVER = 441,
    T_SERVICE = 442,
    T_SERVNOTICE = 443,
    T_SET = 444,
    T_SHARED = 445,
    T_SIZE = 446,
    T_SKILL = 447,
    T_SOFTCALLERID = 448,
    T_SPY = 449,
    T_SSL = 450,
    T_SSL_CIPHER_LIST = 451,
    T_TARGET = 452,
    T_UMODES = 453,
    T_UNAUTH = 454,
    T_UNDLINE = 455,
    T_UNLIMITED = 456,
    T_UNRESV = 457,
    T_UNXLINE = 458,
    T_WALLOP = 459,
    T_WALLOPS = 460,
    T_WEBIRC = 461,
    TBOOL = 462,
    THROTTLE_COUNT = 463,
    THROTTLE_TIME = 464,
    TKLINE_EXPIRE_NOTICES = 465,
    TMASKED = 466,
    TS_MAX_DELTA = 467,
    TS_WARN_DELTA = 468,
    TWODOTS = 469,
    TYPE = 470,
    UNKLINE = 471,
    USE_LOGGING = 472,
    USER = 473,
    VHOST = 474,
    VHOST6 = 475,
    WARN_NO_CONNECT_BLOCK = 476,
    WHOIS = 477,
    XLINE = 478,
    XLINE_EXEMPT = 479
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
#define DENY 282
#define DESCRIPTION 283
#define DIE 284
#define DISABLE_AUTH 285
#define DISABLE_FAKE_CHANNELS 286
#define DISABLE_REMOTE_COMMANDS 287
#define DLINE_MIN_CIDR 288
#define DLINE_MIN_CIDR6 289
#define DOTS_IN_IDENT 290
#define EMAIL 291
#define ENCRYPTED 292
#define EXCEED_LIMIT 293
#define EXEMPT 294
#define FAILED_OPER_NOTICE 295
#define FLATTEN_LINKS 296
#define GECOS 297
#define GENERAL 298
#define HIDDEN 299
#define HIDDEN_NAME 300
#define HIDE_CHANS 301
#define HIDE_IDLE 302
#define HIDE_IDLE_FROM_OPERS 303
#define HIDE_SERVER_IPS 304
#define HIDE_SERVERS 305
#define HIDE_SERVICES 306
#define HOST 307
#define HUB 308
#define HUB_MASK 309
#define IGNORE_BOGUS_TS 310
#define INVISIBLE_ON_CONNECT 311
#define INVITE_CLIENT_COUNT 312
#define INVITE_CLIENT_TIME 313
#define IP 314
#define IRCD_AUTH 315
#define IRCD_FLAGS 316
#define IRCD_SID 317
#define KILL 318
#define KILL_CHASE_TIME_LIMIT 319
#define KLINE 320
#define KLINE_EXEMPT 321
#define KLINE_MIN_CIDR 322
#define KLINE_MIN_CIDR6 323
#define KNOCK_CLIENT_COUNT 324
#define KNOCK_CLIENT_TIME 325
#define KNOCK_DELAY_CHANNEL 326
#define LEAF_MASK 327
#define LINKS_DELAY 328
#define LISTEN 329
#define MASK 330
#define MAX_ACCEPT 331
#define MAX_BANS 332
#define MAX_CHANNELS 333
#define MAX_GLOBAL 334
#define MAX_IDENT 335
#define MAX_IDLE 336
#define MAX_LOCAL 337
#define MAX_NICK_CHANGES 338
#define MAX_NICK_LENGTH 339
#define MAX_NICK_TIME 340
#define MAX_NUMBER 341
#define MAX_TARGETS 342
#define MAX_TOPIC_LENGTH 343
#define MAX_WATCH 344
#define MIN_IDLE 345
#define MIN_NONWILDCARD 346
#define MIN_NONWILDCARD_SIMPLE 347
#define MODULE 348
#define MODULES 349
#define MOTD 350
#define NAME 351
#define NEED_IDENT 352
#define NEED_PASSWORD 353
#define NETWORK_DESC 354
#define NETWORK_NAME 355
#define NICK 356
#define NO_OPER_FLOOD 357
#define NO_TILDE 358
#define NUMBER 359
#define NUMBER_PER_CIDR 360
#define NUMBER_PER_IP 361
#define OPER_ONLY_UMODES 362
#define OPER_PASS_RESV 363
#define OPER_UMODES 364
#define OPERATOR 365
#define OPERS_BYPASS_CALLERID 366
#define PACE_WAIT 367
#define PACE_WAIT_SIMPLE 368
#define PASSWORD 369
#define PATH 370
#define PING_COOKIE 371
#define PING_TIME 372
#define PORT 373
#define QSTRING 374
#define RANDOM_IDLE 375
#define REASON 376
#define REDIRPORT 377
#define REDIRSERV 378
#define REHASH 379
#define REMOTE 380
#define REMOTEBAN 381
#define RESV 382
#define RESV_EXEMPT 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SECONDS 386
#define MINUTES 387
#define HOURS 388
#define DAYS 389
#define WEEKS 390
#define MONTHS 391
#define YEARS 392
#define SEND_PASSWORD 393
#define SENDQ 394
#define SERVERHIDE 395
#define SERVERINFO 396
#define SHORT_MOTD 397
#define SPOOF 398
#define SPOOF_NOTICE 399
#define SQUIT 400
#define SSL_CERTIFICATE_FILE 401
#define SSL_CERTIFICATE_FINGERPRINT 402
#define SSL_CONNECTION_REQUIRED 403
#define SSL_DH_ELLIPTIC_CURVE 404
#define SSL_DH_PARAM_FILE 405
#define SSL_MESSAGE_DIGEST_ALGORITHM 406
#define STATS_E_DISABLED 407
#define STATS_I_OPER_ONLY 408
#define STATS_K_OPER_ONLY 409
#define STATS_M_OPER_ONLY 410
#define STATS_O_OPER_ONLY 411
#define STATS_P_OPER_ONLY 412
#define STATS_U_OPER_ONLY 413
#define T_ALL 414
#define T_BOTS 415
#define T_CALLERID 416
#define T_CCONN 417
#define T_COMMAND 418
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
#define T_NCHANGE 433
#define T_NONONREG 434
#define T_OPME 435
#define T_PREPEND 436
#define T_PSEUDO 437
#define T_RECVQ 438
#define T_REJ 439
#define T_RESTART 440
#define T_SERVER 441
#define T_SERVICE 442
#define T_SERVNOTICE 443
#define T_SET 444
#define T_SHARED 445
#define T_SIZE 446
#define T_SKILL 447
#define T_SOFTCALLERID 448
#define T_SPY 449
#define T_SSL 450
#define T_SSL_CIPHER_LIST 451
#define T_TARGET 452
#define T_UMODES 453
#define T_UNAUTH 454
#define T_UNDLINE 455
#define T_UNLIMITED 456
#define T_UNRESV 457
#define T_UNXLINE 458
#define T_WALLOP 459
#define T_WALLOPS 460
#define T_WEBIRC 461
#define TBOOL 462
#define THROTTLE_COUNT 463
#define THROTTLE_TIME 464
#define TKLINE_EXPIRE_NOTICES 465
#define TMASKED 466
#define TS_MAX_DELTA 467
#define TS_WARN_DELTA 468
#define TWODOTS 469
#define TYPE 470
#define UNKLINE 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_CONNECT_BLOCK 476
#define WHOIS 477
#define XLINE 478
#define XLINE_EXEMPT 479

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 153 "conf_parser.y" /* yacc.c:1909  */

  int number;
  char *string;

#line 507 "conf_parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
