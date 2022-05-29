/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    BOT = 266,
    BYTES = 267,
    KBYTES = 268,
    MBYTES = 269,
    CALLER_ID_WAIT = 270,
    CAN_FLOOD = 271,
    CHANNEL = 272,
    CIDR_BITLEN_IPV4 = 273,
    CIDR_BITLEN_IPV6 = 274,
    CLASS = 275,
    CLIENT = 276,
    CLOSE = 277,
    CONNECT = 278,
    CONNECTFREQ = 279,
    CYCLE_ON_HOST_CHANGE = 280,
    DEFAULT_FLOODCOUNT = 281,
    DEFAULT_FLOODTIME = 282,
    DEFAULT_JOIN_FLOOD_COUNT = 283,
    DEFAULT_JOIN_FLOOD_TIME = 284,
    DEFAULT_MAX_CLIENTS = 285,
    DEFER = 286,
    DENY = 287,
    DESCRIPTION = 288,
    DIE = 289,
    DISABLE_AUTH = 290,
    DISABLE_FAKE_CHANNELS = 291,
    DISABLE_REMOTE_COMMANDS = 292,
    DLINE_MIN_CIDR = 293,
    DLINE_MIN_CIDR6 = 294,
    EMAIL = 295,
    ENABLE_ADMIN = 296,
    ENABLE_EXTBANS = 297,
    ENABLE_OWNER = 298,
    ENCRYPTED = 299,
    EXCEED_LIMIT = 300,
    EXEMPT = 301,
    EXPIRATION = 302,
    FAILED_OPER_NOTICE = 303,
    FLATTEN_LINKS = 304,
    FLATTEN_LINKS_DELAY = 305,
    FLATTEN_LINKS_FILE = 306,
    GECOS = 307,
    GENERAL = 308,
    HIDDEN = 309,
    HIDDEN_NAME = 310,
    HIDE_CHANS = 311,
    HIDE_IDLE = 312,
    HIDE_IDLE_FROM_OPERS = 313,
    HIDE_SERVER_IPS = 314,
    HIDE_SERVERS = 315,
    HIDE_SERVICES = 316,
    HOST = 317,
    HUB = 318,
    HUB_MASK = 319,
    INVISIBLE_ON_CONNECT = 320,
    INVITE_CLIENT_COUNT = 321,
    INVITE_CLIENT_TIME = 322,
    INVITE_DELAY_CHANNEL = 323,
    INVITE_EXPIRE_TIME = 324,
    IP = 325,
    IRCD_AUTH = 326,
    IRCD_FLAGS = 327,
    IRCD_SID = 328,
    JOIN = 329,
    KILL = 330,
    KILL_CHASE_TIME_LIMIT = 331,
    KLINE = 332,
    KLINE_EXEMPT = 333,
    KLINE_MIN_CIDR = 334,
    KLINE_MIN_CIDR6 = 335,
    KNOCK_CLIENT_COUNT = 336,
    KNOCK_CLIENT_TIME = 337,
    KNOCK_DELAY_CHANNEL = 338,
    LEAF_MASK = 339,
    LISTEN = 340,
    MASK = 341,
    MAX_ACCEPT = 342,
    MAX_BANS = 343,
    MAX_BANS_LARGE = 344,
    MAX_CHANNELS = 345,
    MAX_IDLE = 346,
    MAX_INVITES = 347,
    MAX_MONITOR = 348,
    MAX_NICK_CHANGES = 349,
    MAX_NICK_LENGTH = 350,
    MAX_NICK_TIME = 351,
    MAX_NUMBER = 352,
    MAX_TARGETS = 353,
    MAX_TOPIC_LENGTH = 354,
    MIN_IDLE = 355,
    MIN_NONWILDCARD = 356,
    MIN_NONWILDCARD_SIMPLE = 357,
    MODULE = 358,
    MODULES = 359,
    MOTD = 360,
    NAME = 361,
    NEED_IDENT = 362,
    NEED_PASSWORD = 363,
    NETWORK_DESCRIPTION = 364,
    NETWORK_NAME = 365,
    NICK = 366,
    NO_OPER_FLOOD = 367,
    NO_TILDE = 368,
    NUMBER_PER_CIDR = 369,
    NUMBER_PER_IP_GLOBAL = 370,
    NUMBER_PER_IP_LOCAL = 371,
    OPER_ONLY_UMODES = 372,
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
    SPECIALS_IN_IDENT = 405,
    SPOOF = 406,
    SQUIT = 407,
    STATS_E_DISABLED = 408,
    STATS_I_OPER_ONLY = 409,
    STATS_K_OPER_ONLY = 410,
    STATS_M_OPER_ONLY = 411,
    STATS_O_OPER_ONLY = 412,
    STATS_P_OPER_ONLY = 413,
    STATS_U_OPER_ONLY = 414,
    T_ALL = 415,
    T_BIND = 416,
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
    T_FLOOD = 427,
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
    T_TARGET = 451,
    T_TLS = 452,
    T_UMODES = 453,
    T_UNDLINE = 454,
    T_UNLIMITED = 455,
    T_UNRESV = 456,
    T_UNXLINE = 457,
    T_WALLOP = 458,
    T_WALLOPS = 459,
    T_WEBIRC = 460,
    TBOOL = 461,
    THROTTLE_COUNT = 462,
    THROTTLE_TIME = 463,
    TIMEOUT = 464,
    TLS_CERTIFICATE_FILE = 465,
    TLS_CERTIFICATE_FINGERPRINT = 466,
    TLS_CIPHER_LIST = 467,
    TLS_CIPHER_SUITES = 468,
    TLS_CONNECTION_REQUIRED = 469,
    TLS_DH_PARAM_FILE = 470,
    TLS_MESSAGE_DIGEST_ALGORITHM = 471,
    TLS_SUPPORTED_GROUPS = 472,
    TS_MAX_DELTA = 473,
    TS_WARN_DELTA = 474,
    TWODOTS = 475,
    TYPE = 476,
    UNKLINE = 477,
    USE_LOGGING = 478,
    USER = 479,
    VHOST = 480,
    VHOST6 = 481,
    WARN_NO_CONNECT_BLOCK = 482,
    WHOIS = 483,
    WHOWAS_HISTORY_LENGTH = 484,
    XLINE = 485,
    XLINE_EXEMPT = 486,
    QSTRING = 487,
    NUMBER = 488
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
#define BOT 266
#define BYTES 267
#define KBYTES 268
#define MBYTES 269
#define CALLER_ID_WAIT 270
#define CAN_FLOOD 271
#define CHANNEL 272
#define CIDR_BITLEN_IPV4 273
#define CIDR_BITLEN_IPV6 274
#define CLASS 275
#define CLIENT 276
#define CLOSE 277
#define CONNECT 278
#define CONNECTFREQ 279
#define CYCLE_ON_HOST_CHANGE 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_FLOODTIME 282
#define DEFAULT_JOIN_FLOOD_COUNT 283
#define DEFAULT_JOIN_FLOOD_TIME 284
#define DEFAULT_MAX_CLIENTS 285
#define DEFER 286
#define DENY 287
#define DESCRIPTION 288
#define DIE 289
#define DISABLE_AUTH 290
#define DISABLE_FAKE_CHANNELS 291
#define DISABLE_REMOTE_COMMANDS 292
#define DLINE_MIN_CIDR 293
#define DLINE_MIN_CIDR6 294
#define EMAIL 295
#define ENABLE_ADMIN 296
#define ENABLE_EXTBANS 297
#define ENABLE_OWNER 298
#define ENCRYPTED 299
#define EXCEED_LIMIT 300
#define EXEMPT 301
#define EXPIRATION 302
#define FAILED_OPER_NOTICE 303
#define FLATTEN_LINKS 304
#define FLATTEN_LINKS_DELAY 305
#define FLATTEN_LINKS_FILE 306
#define GECOS 307
#define GENERAL 308
#define HIDDEN 309
#define HIDDEN_NAME 310
#define HIDE_CHANS 311
#define HIDE_IDLE 312
#define HIDE_IDLE_FROM_OPERS 313
#define HIDE_SERVER_IPS 314
#define HIDE_SERVERS 315
#define HIDE_SERVICES 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define INVISIBLE_ON_CONNECT 320
#define INVITE_CLIENT_COUNT 321
#define INVITE_CLIENT_TIME 322
#define INVITE_DELAY_CHANNEL 323
#define INVITE_EXPIRE_TIME 324
#define IP 325
#define IRCD_AUTH 326
#define IRCD_FLAGS 327
#define IRCD_SID 328
#define JOIN 329
#define KILL 330
#define KILL_CHASE_TIME_LIMIT 331
#define KLINE 332
#define KLINE_EXEMPT 333
#define KLINE_MIN_CIDR 334
#define KLINE_MIN_CIDR6 335
#define KNOCK_CLIENT_COUNT 336
#define KNOCK_CLIENT_TIME 337
#define KNOCK_DELAY_CHANNEL 338
#define LEAF_MASK 339
#define LISTEN 340
#define MASK 341
#define MAX_ACCEPT 342
#define MAX_BANS 343
#define MAX_BANS_LARGE 344
#define MAX_CHANNELS 345
#define MAX_IDLE 346
#define MAX_INVITES 347
#define MAX_MONITOR 348
#define MAX_NICK_CHANGES 349
#define MAX_NICK_LENGTH 350
#define MAX_NICK_TIME 351
#define MAX_NUMBER 352
#define MAX_TARGETS 353
#define MAX_TOPIC_LENGTH 354
#define MIN_IDLE 355
#define MIN_NONWILDCARD 356
#define MIN_NONWILDCARD_SIMPLE 357
#define MODULE 358
#define MODULES 359
#define MOTD 360
#define NAME 361
#define NEED_IDENT 362
#define NEED_PASSWORD 363
#define NETWORK_DESCRIPTION 364
#define NETWORK_NAME 365
#define NICK 366
#define NO_OPER_FLOOD 367
#define NO_TILDE 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP_GLOBAL 370
#define NUMBER_PER_IP_LOCAL 371
#define OPER_ONLY_UMODES 372
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
#define SPECIALS_IN_IDENT 405
#define SPOOF 406
#define SQUIT 407
#define STATS_E_DISABLED 408
#define STATS_I_OPER_ONLY 409
#define STATS_K_OPER_ONLY 410
#define STATS_M_OPER_ONLY 411
#define STATS_O_OPER_ONLY 412
#define STATS_P_OPER_ONLY 413
#define STATS_U_OPER_ONLY 414
#define T_ALL 415
#define T_BIND 416
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
#define T_FLOOD 427
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
#define T_TARGET 451
#define T_TLS 452
#define T_UMODES 453
#define T_UNDLINE 454
#define T_UNLIMITED 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_WALLOP 458
#define T_WALLOPS 459
#define T_WEBIRC 460
#define TBOOL 461
#define THROTTLE_COUNT 462
#define THROTTLE_TIME 463
#define TIMEOUT 464
#define TLS_CERTIFICATE_FILE 465
#define TLS_CERTIFICATE_FINGERPRINT 466
#define TLS_CIPHER_LIST 467
#define TLS_CIPHER_SUITES 468
#define TLS_CONNECTION_REQUIRED 469
#define TLS_DH_PARAM_FILE 470
#define TLS_MESSAGE_DIGEST_ALGORITHM 471
#define TLS_SUPPORTED_GROUPS 472
#define TS_MAX_DELTA 473
#define TS_WARN_DELTA 474
#define TWODOTS 475
#define TYPE 476
#define UNKLINE 477
#define USE_LOGGING 478
#define USER 479
#define VHOST 480
#define VHOST6 481
#define WARN_NO_CONNECT_BLOCK 482
#define WHOIS 483
#define WHOWAS_HISTORY_LENGTH 484
#define XLINE 485
#define XLINE_EXEMPT 486
#define QSTRING 487
#define NUMBER 488

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 528 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
