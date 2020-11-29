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
    BYTES = 266,
    KBYTES = 267,
    MBYTES = 268,
    CALLER_ID_WAIT = 269,
    CAN_FLOOD = 270,
    CHANNEL = 271,
    CIDR_BITLEN_IPV4 = 272,
    CIDR_BITLEN_IPV6 = 273,
    CLASS = 274,
    CLIENT = 275,
    CLOSE = 276,
    CONNECT = 277,
    CONNECTFREQ = 278,
    CYCLE_ON_HOST_CHANGE = 279,
    DEFAULT_FLOODCOUNT = 280,
    DEFAULT_FLOODTIME = 281,
    DEFAULT_JOIN_FLOOD_COUNT = 282,
    DEFAULT_JOIN_FLOOD_TIME = 283,
    DEFAULT_MAX_CLIENTS = 284,
    DEFER = 285,
    DENY = 286,
    DESCRIPTION = 287,
    DIE = 288,
    DISABLE_AUTH = 289,
    DISABLE_FAKE_CHANNELS = 290,
    DISABLE_REMOTE_COMMANDS = 291,
    DLINE_MIN_CIDR = 292,
    DLINE_MIN_CIDR6 = 293,
    DOTS_IN_IDENT = 294,
    EMAIL = 295,
    ENABLE_EXTBANS = 296,
    ENCRYPTED = 297,
    EXCEED_LIMIT = 298,
    EXEMPT = 299,
    EXPIRATION = 300,
    FAILED_OPER_NOTICE = 301,
    FLATTEN_LINKS = 302,
    FLATTEN_LINKS_DELAY = 303,
    FLATTEN_LINKS_FILE = 304,
    GECOS = 305,
    GENERAL = 306,
    HIDDEN = 307,
    HIDDEN_NAME = 308,
    HIDE_CHANS = 309,
    HIDE_IDLE = 310,
    HIDE_IDLE_FROM_OPERS = 311,
    HIDE_SERVER_IPS = 312,
    HIDE_SERVERS = 313,
    HIDE_SERVICES = 314,
    HOST = 315,
    HUB = 316,
    HUB_MASK = 317,
    INVISIBLE_ON_CONNECT = 318,
    INVITE_CLIENT_COUNT = 319,
    INVITE_CLIENT_TIME = 320,
    INVITE_DELAY_CHANNEL = 321,
    INVITE_EXPIRE_TIME = 322,
    IP = 323,
    IRCD_AUTH = 324,
    IRCD_FLAGS = 325,
    IRCD_SID = 326,
    JOIN = 327,
    KILL = 328,
    KILL_CHASE_TIME_LIMIT = 329,
    KLINE = 330,
    KLINE_EXEMPT = 331,
    KLINE_MIN_CIDR = 332,
    KLINE_MIN_CIDR6 = 333,
    KNOCK_CLIENT_COUNT = 334,
    KNOCK_CLIENT_TIME = 335,
    KNOCK_DELAY_CHANNEL = 336,
    LEAF_MASK = 337,
    LISTEN = 338,
    MASK = 339,
    MAX_ACCEPT = 340,
    MAX_BANS = 341,
    MAX_BANS_LARGE = 342,
    MAX_CHANNELS = 343,
    MAX_IDLE = 344,
    MAX_INVITES = 345,
    MAX_MONITOR = 346,
    MAX_NICK_CHANGES = 347,
    MAX_NICK_LENGTH = 348,
    MAX_NICK_TIME = 349,
    MAX_NUMBER = 350,
    MAX_TARGETS = 351,
    MAX_TOPIC_LENGTH = 352,
    MIN_IDLE = 353,
    MIN_NONWILDCARD = 354,
    MIN_NONWILDCARD_SIMPLE = 355,
    MODULE = 356,
    MODULES = 357,
    MOTD = 358,
    NAME = 359,
    NEED_IDENT = 360,
    NEED_PASSWORD = 361,
    NETWORK_DESCRIPTION = 362,
    NETWORK_NAME = 363,
    NICK = 364,
    NO_OPER_FLOOD = 365,
    NO_TILDE = 366,
    NUMBER_PER_CIDR = 367,
    NUMBER_PER_IP_GLOBAL = 368,
    NUMBER_PER_IP_LOCAL = 369,
    OPER_ONLY_UMODES = 370,
    OPER_UMODES = 371,
    OPERATOR = 372,
    OPERS_BYPASS_CALLERID = 373,
    PACE_WAIT = 374,
    PACE_WAIT_SIMPLE = 375,
    PASSWORD = 376,
    PATH = 377,
    PING_COOKIE = 378,
    PING_TIME = 379,
    PORT = 380,
    RANDOM_IDLE = 381,
    REASON = 382,
    REDIRPORT = 383,
    REDIRSERV = 384,
    REHASH = 385,
    REMOTE = 386,
    REMOTEBAN = 387,
    RESV = 388,
    RESV_EXEMPT = 389,
    RSA_PRIVATE_KEY_FILE = 390,
    SECONDS = 391,
    MINUTES = 392,
    HOURS = 393,
    DAYS = 394,
    WEEKS = 395,
    MONTHS = 396,
    YEARS = 397,
    SEND_PASSWORD = 398,
    SENDQ = 399,
    SERVERHIDE = 400,
    SERVERINFO = 401,
    SHORT_MOTD = 402,
    SPOOF = 403,
    SQUIT = 404,
    STATS_E_DISABLED = 405,
    STATS_I_OPER_ONLY = 406,
    STATS_K_OPER_ONLY = 407,
    STATS_M_OPER_ONLY = 408,
    STATS_O_OPER_ONLY = 409,
    STATS_P_OPER_ONLY = 410,
    STATS_U_OPER_ONLY = 411,
    T_ALL = 412,
    T_BIND = 413,
    T_CALLERID = 414,
    T_CCONN = 415,
    T_COMMAND = 416,
    T_CLUSTER = 417,
    T_DEAF = 418,
    T_DEBUG = 419,
    T_DLINE = 420,
    T_EXTERNAL = 421,
    T_FARCONNECT = 422,
    T_FILE = 423,
    T_FLOOD = 424,
    T_GLOBOPS = 425,
    T_INVISIBLE = 426,
    T_IPV4 = 427,
    T_IPV6 = 428,
    T_LOCOPS = 429,
    T_LOG = 430,
    T_NCHANGE = 431,
    T_NONONREG = 432,
    T_OPME = 433,
    T_PREPEND = 434,
    T_PSEUDO = 435,
    T_RECVQ = 436,
    T_REJ = 437,
    T_RESTART = 438,
    T_SERVER = 439,
    T_SERVICE = 440,
    T_SERVNOTICE = 441,
    T_SET = 442,
    T_SHARED = 443,
    T_SIZE = 444,
    T_SKILL = 445,
    T_SOFTCALLERID = 446,
    T_SPY = 447,
    T_TARGET = 448,
    T_TLS = 449,
    T_UMODES = 450,
    T_UNDLINE = 451,
    T_UNLIMITED = 452,
    T_UNRESV = 453,
    T_UNXLINE = 454,
    T_WALLOP = 455,
    T_WALLOPS = 456,
    T_WEBIRC = 457,
    TBOOL = 458,
    THROTTLE_COUNT = 459,
    THROTTLE_TIME = 460,
    TIMEOUT = 461,
    TLS_CERTIFICATE_FILE = 462,
    TLS_CERTIFICATE_FINGERPRINT = 463,
    TLS_CIPHER_LIST = 464,
    TLS_CIPHER_SUITES = 465,
    TLS_CONNECTION_REQUIRED = 466,
    TLS_DH_PARAM_FILE = 467,
    TLS_MESSAGE_DIGEST_ALGORITHM = 468,
    TLS_SUPPORTED_GROUPS = 469,
    TS_MAX_DELTA = 470,
    TS_WARN_DELTA = 471,
    TWODOTS = 472,
    TYPE = 473,
    UNKLINE = 474,
    USE_LOGGING = 475,
    USER = 476,
    VHOST = 477,
    VHOST6 = 478,
    WARN_NO_CONNECT_BLOCK = 479,
    WHOIS = 480,
    WHOWAS_HISTORY_LENGTH = 481,
    XLINE = 482,
    XLINE_EXEMPT = 483,
    QSTRING = 484,
    NUMBER = 485
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
#define CLIENT 275
#define CLOSE 276
#define CONNECT 277
#define CONNECTFREQ 278
#define CYCLE_ON_HOST_CHANGE 279
#define DEFAULT_FLOODCOUNT 280
#define DEFAULT_FLOODTIME 281
#define DEFAULT_JOIN_FLOOD_COUNT 282
#define DEFAULT_JOIN_FLOOD_TIME 283
#define DEFAULT_MAX_CLIENTS 284
#define DEFER 285
#define DENY 286
#define DESCRIPTION 287
#define DIE 288
#define DISABLE_AUTH 289
#define DISABLE_FAKE_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DLINE_MIN_CIDR 292
#define DLINE_MIN_CIDR6 293
#define DOTS_IN_IDENT 294
#define EMAIL 295
#define ENABLE_EXTBANS 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define EXPIRATION 300
#define FAILED_OPER_NOTICE 301
#define FLATTEN_LINKS 302
#define FLATTEN_LINKS_DELAY 303
#define FLATTEN_LINKS_FILE 304
#define GECOS 305
#define GENERAL 306
#define HIDDEN 307
#define HIDDEN_NAME 308
#define HIDE_CHANS 309
#define HIDE_IDLE 310
#define HIDE_IDLE_FROM_OPERS 311
#define HIDE_SERVER_IPS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define INVISIBLE_ON_CONNECT 318
#define INVITE_CLIENT_COUNT 319
#define INVITE_CLIENT_TIME 320
#define INVITE_DELAY_CHANNEL 321
#define INVITE_EXPIRE_TIME 322
#define IP 323
#define IRCD_AUTH 324
#define IRCD_FLAGS 325
#define IRCD_SID 326
#define JOIN 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_MIN_CIDR 332
#define KLINE_MIN_CIDR6 333
#define KNOCK_CLIENT_COUNT 334
#define KNOCK_CLIENT_TIME 335
#define KNOCK_DELAY_CHANNEL 336
#define LEAF_MASK 337
#define LISTEN 338
#define MASK 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_BANS_LARGE 342
#define MAX_CHANNELS 343
#define MAX_IDLE 344
#define MAX_INVITES 345
#define MAX_MONITOR 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_LENGTH 348
#define MAX_NICK_TIME 349
#define MAX_NUMBER 350
#define MAX_TARGETS 351
#define MAX_TOPIC_LENGTH 352
#define MIN_IDLE 353
#define MIN_NONWILDCARD 354
#define MIN_NONWILDCARD_SIMPLE 355
#define MODULE 356
#define MODULES 357
#define MOTD 358
#define NAME 359
#define NEED_IDENT 360
#define NEED_PASSWORD 361
#define NETWORK_DESCRIPTION 362
#define NETWORK_NAME 363
#define NICK 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER_PER_CIDR 367
#define NUMBER_PER_IP_GLOBAL 368
#define NUMBER_PER_IP_LOCAL 369
#define OPER_ONLY_UMODES 370
#define OPER_UMODES 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define PACE_WAIT 374
#define PACE_WAIT_SIMPLE 375
#define PASSWORD 376
#define PATH 377
#define PING_COOKIE 378
#define PING_TIME 379
#define PORT 380
#define RANDOM_IDLE 381
#define REASON 382
#define REDIRPORT 383
#define REDIRSERV 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESV 388
#define RESV_EXEMPT 389
#define RSA_PRIVATE_KEY_FILE 390
#define SECONDS 391
#define MINUTES 392
#define HOURS 393
#define DAYS 394
#define WEEKS 395
#define MONTHS 396
#define YEARS 397
#define SEND_PASSWORD 398
#define SENDQ 399
#define SERVERHIDE 400
#define SERVERINFO 401
#define SHORT_MOTD 402
#define SPOOF 403
#define SQUIT 404
#define STATS_E_DISABLED 405
#define STATS_I_OPER_ONLY 406
#define STATS_K_OPER_ONLY 407
#define STATS_M_OPER_ONLY 408
#define STATS_O_OPER_ONLY 409
#define STATS_P_OPER_ONLY 410
#define STATS_U_OPER_ONLY 411
#define T_ALL 412
#define T_BIND 413
#define T_CALLERID 414
#define T_CCONN 415
#define T_COMMAND 416
#define T_CLUSTER 417
#define T_DEAF 418
#define T_DEBUG 419
#define T_DLINE 420
#define T_EXTERNAL 421
#define T_FARCONNECT 422
#define T_FILE 423
#define T_FLOOD 424
#define T_GLOBOPS 425
#define T_INVISIBLE 426
#define T_IPV4 427
#define T_IPV6 428
#define T_LOCOPS 429
#define T_LOG 430
#define T_NCHANGE 431
#define T_NONONREG 432
#define T_OPME 433
#define T_PREPEND 434
#define T_PSEUDO 435
#define T_RECVQ 436
#define T_REJ 437
#define T_RESTART 438
#define T_SERVER 439
#define T_SERVICE 440
#define T_SERVNOTICE 441
#define T_SET 442
#define T_SHARED 443
#define T_SIZE 444
#define T_SKILL 445
#define T_SOFTCALLERID 446
#define T_SPY 447
#define T_TARGET 448
#define T_TLS 449
#define T_UMODES 450
#define T_UNDLINE 451
#define T_UNLIMITED 452
#define T_UNRESV 453
#define T_UNXLINE 454
#define T_WALLOP 455
#define T_WALLOPS 456
#define T_WEBIRC 457
#define TBOOL 458
#define THROTTLE_COUNT 459
#define THROTTLE_TIME 460
#define TIMEOUT 461
#define TLS_CERTIFICATE_FILE 462
#define TLS_CERTIFICATE_FINGERPRINT 463
#define TLS_CIPHER_LIST 464
#define TLS_CIPHER_SUITES 465
#define TLS_CONNECTION_REQUIRED 466
#define TLS_DH_PARAM_FILE 467
#define TLS_MESSAGE_DIGEST_ALGORITHM 468
#define TLS_SUPPORTED_GROUPS 469
#define TS_MAX_DELTA 470
#define TS_WARN_DELTA 471
#define TWODOTS 472
#define TYPE 473
#define UNKLINE 474
#define USE_LOGGING 475
#define USER 476
#define VHOST 477
#define VHOST6 478
#define WARN_NO_CONNECT_BLOCK 479
#define WHOIS 480
#define WHOWAS_HISTORY_LENGTH 481
#define XLINE 482
#define XLINE_EXEMPT 483
#define QSTRING 484
#define NUMBER 485

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 522 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
