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
    GECOS = 298,
    GENERAL = 299,
    HIDDEN = 300,
    HIDDEN_NAME = 301,
    HIDE_CHANS = 302,
    HIDE_IDLE = 303,
    HIDE_IDLE_FROM_OPERS = 304,
    HIDE_SERVER_IPS = 305,
    HIDE_SERVERS = 306,
    HIDE_SERVICES = 307,
    HOST = 308,
    HUB = 309,
    HUB_MASK = 310,
    IGNORE_BOGUS_TS = 311,
    INVISIBLE_ON_CONNECT = 312,
    INVITE_CLIENT_COUNT = 313,
    INVITE_CLIENT_TIME = 314,
    IP = 315,
    IRCD_AUTH = 316,
    IRCD_FLAGS = 317,
    IRCD_SID = 318,
    JOIN = 319,
    KILL = 320,
    KILL_CHASE_TIME_LIMIT = 321,
    KLINE = 322,
    KLINE_EXEMPT = 323,
    KLINE_MIN_CIDR = 324,
    KLINE_MIN_CIDR6 = 325,
    KNOCK_CLIENT_COUNT = 326,
    KNOCK_CLIENT_TIME = 327,
    KNOCK_DELAY_CHANNEL = 328,
    LEAF_MASK = 329,
    LINKS_DELAY = 330,
    LISTEN = 331,
    MASK = 332,
    MAX_ACCEPT = 333,
    MAX_BANS = 334,
    MAX_CHANNELS = 335,
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
    NO_OPER_FLOOD = 359,
    NO_TILDE = 360,
    NUMBER = 361,
    NUMBER_PER_CIDR = 362,
    NUMBER_PER_IP = 363,
    OPER_ONLY_UMODES = 364,
    OPER_UMODES = 365,
    OPERATOR = 366,
    OPERS_BYPASS_CALLERID = 367,
    PACE_WAIT = 368,
    PACE_WAIT_SIMPLE = 369,
    PASSWORD = 370,
    PATH = 371,
    PING_COOKIE = 372,
    PING_TIME = 373,
    PORT = 374,
    QSTRING = 375,
    RANDOM_IDLE = 376,
    REASON = 377,
    REDIRPORT = 378,
    REDIRSERV = 379,
    REHASH = 380,
    REMOTE = 381,
    REMOTEBAN = 382,
    RESV = 383,
    RESV_EXEMPT = 384,
    RSA_PRIVATE_KEY_FILE = 385,
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
#define GECOS 298
#define GENERAL 299
#define HIDDEN 300
#define HIDDEN_NAME 301
#define HIDE_CHANS 302
#define HIDE_IDLE 303
#define HIDE_IDLE_FROM_OPERS 304
#define HIDE_SERVER_IPS 305
#define HIDE_SERVERS 306
#define HIDE_SERVICES 307
#define HOST 308
#define HUB 309
#define HUB_MASK 310
#define IGNORE_BOGUS_TS 311
#define INVISIBLE_ON_CONNECT 312
#define INVITE_CLIENT_COUNT 313
#define INVITE_CLIENT_TIME 314
#define IP 315
#define IRCD_AUTH 316
#define IRCD_FLAGS 317
#define IRCD_SID 318
#define JOIN 319
#define KILL 320
#define KILL_CHASE_TIME_LIMIT 321
#define KLINE 322
#define KLINE_EXEMPT 323
#define KLINE_MIN_CIDR 324
#define KLINE_MIN_CIDR6 325
#define KNOCK_CLIENT_COUNT 326
#define KNOCK_CLIENT_TIME 327
#define KNOCK_DELAY_CHANNEL 328
#define LEAF_MASK 329
#define LINKS_DELAY 330
#define LISTEN 331
#define MASK 332
#define MAX_ACCEPT 333
#define MAX_BANS 334
#define MAX_CHANNELS 335
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
#define NO_OPER_FLOOD 359
#define NO_TILDE 360
#define NUMBER 361
#define NUMBER_PER_CIDR 362
#define NUMBER_PER_IP 363
#define OPER_ONLY_UMODES 364
#define OPER_UMODES 365
#define OPERATOR 366
#define OPERS_BYPASS_CALLERID 367
#define PACE_WAIT 368
#define PACE_WAIT_SIMPLE 369
#define PASSWORD 370
#define PATH 371
#define PING_COOKIE 372
#define PING_TIME 373
#define PORT 374
#define QSTRING 375
#define RANDOM_IDLE 376
#define REASON 377
#define REDIRPORT 378
#define REDIRSERV 379
#define REHASH 380
#define REMOTE 381
#define REMOTEBAN 382
#define RESV 383
#define RESV_EXEMPT 384
#define RSA_PRIVATE_KEY_FILE 385
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
