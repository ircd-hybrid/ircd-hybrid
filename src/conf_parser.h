/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ACCEPT_PASSWORD = 258,         /* ACCEPT_PASSWORD  */
    ADMIN = 259,                   /* ADMIN  */
    AFTYPE = 260,                  /* AFTYPE  */
    ANTI_NICK_FLOOD = 261,         /* ANTI_NICK_FLOOD  */
    ANTI_SPAM_EXIT_MESSAGE_TIME = 262, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
    AUTOCONN = 263,                /* AUTOCONN  */
    AWAY_COUNT = 264,              /* AWAY_COUNT  */
    AWAY_TIME = 265,               /* AWAY_TIME  */
    BOT = 266,                     /* BOT  */
    BYTES = 267,                   /* BYTES  */
    KBYTES = 268,                  /* KBYTES  */
    MBYTES = 269,                  /* MBYTES  */
    CALLER_ID_WAIT = 270,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 271,               /* CAN_FLOOD  */
    CHANNEL = 272,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 273,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 274,        /* CIDR_BITLEN_IPV6  */
    CLASS = 275,                   /* CLASS  */
    CLIENT = 276,                  /* CLIENT  */
    CLOAK_ENABLED = 277,           /* CLOAK_ENABLED  */
    CLOAK_CIDR_LEN_IPV4 = 278,     /* CLOAK_CIDR_LEN_IPV4  */
    CLOAK_CIDR_LEN_IPV6 = 279,     /* CLOAK_CIDR_LEN_IPV6  */
    CLOAK_NUM_BITS = 280,          /* CLOAK_NUM_BITS  */
    CLOAK_SECRET = 281,            /* CLOAK_SECRET  */
    CLOAK_SUFFIX = 282,            /* CLOAK_SUFFIX  */
    CLOSE = 283,                   /* CLOSE  */
    CONNECT = 284,                 /* CONNECT  */
    CONNECTFREQ = 285,             /* CONNECTFREQ  */
    CORE = 286,                    /* CORE  */
    CYCLE_ON_HOST_CHANGE = 287,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 288,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 289,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 290, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 291, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 292,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 293,                   /* DEFER  */
    DENY = 294,                    /* DENY  */
    DESCRIPTION = 295,             /* DESCRIPTION  */
    DIE = 296,                     /* DIE  */
    DISABLE_AUTH = 297,            /* DISABLE_AUTH  */
    DISABLE_FAKE_CHANNELS = 298,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 299, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 300,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 301,         /* DLINE_MIN_CIDR6  */
    EMAIL = 302,                   /* EMAIL  */
    ENABLE_ADMIN = 303,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 304,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 305,            /* ENABLE_OWNER  */
    ENCRYPTED = 306,               /* ENCRYPTED  */
    EXCEED_LIMIT = 307,            /* EXCEED_LIMIT  */
    EXEMPT = 308,                  /* EXEMPT  */
    EXPIRATION = 309,              /* EXPIRATION  */
    FAILED_OPER_NOTICE = 310,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 311,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 312,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 313,      /* FLATTEN_LINKS_FILE  */
    GECOS = 314,                   /* GECOS  */
    GENERAL = 315,                 /* GENERAL  */
    HIDDEN = 316,                  /* HIDDEN  */
    HIDDEN_NAME = 317,             /* HIDDEN_NAME  */
    HIDE_CHANS = 318,              /* HIDE_CHANS  */
    HIDE_IDLE = 319,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 320,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 321,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 322,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 323,           /* HIDE_SERVICES  */
    HOST = 324,                    /* HOST  */
    HUB = 325,                     /* HUB  */
    HUB_MASK = 326,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 327,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 328,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 329,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 330,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 331,      /* INVITE_EXPIRE_TIME  */
    IP = 332,                      /* IP  */
    IRCD_AUTH = 333,               /* IRCD_AUTH  */
    IRCD_FLAGS = 334,              /* IRCD_FLAGS  */
    IRCD_SID = 335,                /* IRCD_SID  */
    JOIN = 336,                    /* JOIN  */
    KILL = 337,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 338,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 339,                   /* KLINE  */
    KLINE_EXEMPT = 340,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 341,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 342,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 343,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 344,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 345,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 346,               /* LEAF_MASK  */
    LISTEN = 347,                  /* LISTEN  */
    LOADMODULE = 348,              /* LOADMODULE  */
    MASK = 349,                    /* MASK  */
    MASS = 350,                    /* MASS  */
    MAX_ACCEPT = 351,              /* MAX_ACCEPT  */
    MAX_BANS = 352,                /* MAX_BANS  */
    MAX_BANS_LARGE = 353,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 354,            /* MAX_CHANNELS  */
    MAX_IDLE = 355,                /* MAX_IDLE  */
    MAX_INVITES = 356,             /* MAX_INVITES  */
    MAX_MONITOR = 357,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 358,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 359,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 360,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 361,              /* MAX_NUMBER  */
    MAX_TARGETS = 362,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 363,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 364,                 /* MESSAGE  */
    MIN_IDLE = 365,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 366,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 367,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 368,                  /* MODULE  */
    MODULE_BASE_PATH = 369,        /* MODULE_BASE_PATH  */
    MOTD = 370,                    /* MOTD  */
    NAME = 371,                    /* NAME  */
    NEED_IDENT = 372,              /* NEED_IDENT  */
    NEED_PASSWORD = 373,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 374,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 375,            /* NETWORK_NAME  */
    NICK = 376,                    /* NICK  */
    NO_OPER_FLOOD = 377,           /* NO_OPER_FLOOD  */
    NO_TILDE = 378,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 379,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 380,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 381,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 382,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 383,             /* OPER_UMODES  */
    OPERATOR = 384,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 385,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 386,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 387,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 388,                /* PASSWORD  */
    PATH = 389,                    /* PATH  */
    PING_COOKIE = 390,             /* PING_COOKIE  */
    PING_TIME = 391,               /* PING_TIME  */
    PORT = 392,                    /* PORT  */
    RANDOM_IDLE = 393,             /* RANDOM_IDLE  */
    REASON = 394,                  /* REASON  */
    REDIRPORT = 395,               /* REDIRPORT  */
    REDIRSERV = 396,               /* REDIRSERV  */
    REHASH = 397,                  /* REHASH  */
    REMOTE = 398,                  /* REMOTE  */
    REMOTEBAN = 399,               /* REMOTEBAN  */
    RESIDENT = 400,                /* RESIDENT  */
    RESV = 401,                    /* RESV  */
    RESV_EXEMPT = 402,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 403,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 404,                 /* SECONDS  */
    MINUTES = 405,                 /* MINUTES  */
    HOURS = 406,                   /* HOURS  */
    DAYS = 407,                    /* DAYS  */
    WEEKS = 408,                   /* WEEKS  */
    MONTHS = 409,                  /* MONTHS  */
    YEARS = 410,                   /* YEARS  */
    SEND_PASSWORD = 411,           /* SEND_PASSWORD  */
    SENDQ = 412,                   /* SENDQ  */
    SERVERHIDE = 413,              /* SERVERHIDE  */
    SERVERINFO = 414,              /* SERVERINFO  */
    SHORT_MOTD = 415,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 416,       /* SPECIALS_IN_IDENT  */
    SPOOF = 417,                   /* SPOOF  */
    SQUIT = 418,                   /* SQUIT  */
    STATS_E_DISABLED = 419,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 420,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 421,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 422,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 423,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 424,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 425,       /* STATS_U_OPER_ONLY  */
    T_ALL = 426,                   /* T_ALL  */
    T_BIND = 427,                  /* T_BIND  */
    T_CALLERID = 428,              /* T_CALLERID  */
    T_CCONN = 429,                 /* T_CCONN  */
    T_COMMAND = 430,               /* T_COMMAND  */
    T_CLUSTER = 431,               /* T_CLUSTER  */
    T_DEAF = 432,                  /* T_DEAF  */
    T_DEBUG = 433,                 /* T_DEBUG  */
    T_DLINE = 434,                 /* T_DLINE  */
    T_EXTERNAL = 435,              /* T_EXTERNAL  */
    T_FARCONNECT = 436,            /* T_FARCONNECT  */
    T_FILE = 437,                  /* T_FILE  */
    T_FLOOD = 438,                 /* T_FLOOD  */
    T_GLOBOPS = 439,               /* T_GLOBOPS  */
    T_INVISIBLE = 440,             /* T_INVISIBLE  */
    T_IPV4 = 441,                  /* T_IPV4  */
    T_IPV6 = 442,                  /* T_IPV6  */
    T_LOCOPS = 443,                /* T_LOCOPS  */
    T_LOG = 444,                   /* T_LOG  */
    T_NCHANGE = 445,               /* T_NCHANGE  */
    T_NONONREG = 446,              /* T_NONONREG  */
    T_OPME = 447,                  /* T_OPME  */
    T_PREPEND = 448,               /* T_PREPEND  */
    T_PSEUDO = 449,                /* T_PSEUDO  */
    T_RECVQ = 450,                 /* T_RECVQ  */
    T_REJ = 451,                   /* T_REJ  */
    T_RESTART = 452,               /* T_RESTART  */
    T_SECUREONLY = 453,            /* T_SECUREONLY  */
    T_SERVER = 454,                /* T_SERVER  */
    T_SERVICE = 455,               /* T_SERVICE  */
    T_SERVNOTICE = 456,            /* T_SERVNOTICE  */
    T_SET = 457,                   /* T_SET  */
    T_SHARED = 458,                /* T_SHARED  */
    T_SIZE = 459,                  /* T_SIZE  */
    T_SKILL = 460,                 /* T_SKILL  */
    T_SOFTCALLERID = 461,          /* T_SOFTCALLERID  */
    T_SPY = 462,                   /* T_SPY  */
    T_TARGET = 463,                /* T_TARGET  */
    T_TLS = 464,                   /* T_TLS  */
    T_UMODES = 465,                /* T_UMODES  */
    T_UNDLINE = 466,               /* T_UNDLINE  */
    T_UNLIMITED = 467,             /* T_UNLIMITED  */
    T_UNRESV = 468,                /* T_UNRESV  */
    T_UNXLINE = 469,               /* T_UNXLINE  */
    T_WALLOP = 470,                /* T_WALLOP  */
    T_WALLOPS = 471,               /* T_WALLOPS  */
    T_WEBIRC = 472,                /* T_WEBIRC  */
    TBOOL = 473,                   /* TBOOL  */
    THROTTLE_COUNT = 474,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 475,           /* THROTTLE_TIME  */
    TIMEOUT = 476,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 477,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 478, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 479,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 480,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 481, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 482,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 483, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 484,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 485,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 486,           /* TS_WARN_DELTA  */
    TWODOTS = 487,                 /* TWODOTS  */
    TYPE = 488,                    /* TYPE  */
    UNKLINE = 489,                 /* UNKLINE  */
    USE_LOGGING = 490,             /* USE_LOGGING  */
    USER = 491,                    /* USER  */
    VHOST = 492,                   /* VHOST  */
    VHOST6 = 493,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 494,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 495,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 496,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 497,                   /* XLINE  */
    XLINE_EXEMPT = 498,            /* XLINE_EXEMPT  */
    QSTRING = 499,                 /* QSTRING  */
    NUMBER = 500                   /* NUMBER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define CLOAK_ENABLED 277
#define CLOAK_CIDR_LEN_IPV4 278
#define CLOAK_CIDR_LEN_IPV6 279
#define CLOAK_NUM_BITS 280
#define CLOAK_SECRET 281
#define CLOAK_SUFFIX 282
#define CLOSE 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CORE 286
#define CYCLE_ON_HOST_CHANGE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_FLOODTIME 289
#define DEFAULT_JOIN_FLOOD_COUNT 290
#define DEFAULT_JOIN_FLOOD_TIME 291
#define DEFAULT_MAX_CLIENTS 292
#define DEFER 293
#define DENY 294
#define DESCRIPTION 295
#define DIE 296
#define DISABLE_AUTH 297
#define DISABLE_FAKE_CHANNELS 298
#define DISABLE_REMOTE_COMMANDS 299
#define DLINE_MIN_CIDR 300
#define DLINE_MIN_CIDR6 301
#define EMAIL 302
#define ENABLE_ADMIN 303
#define ENABLE_EXTBANS 304
#define ENABLE_OWNER 305
#define ENCRYPTED 306
#define EXCEED_LIMIT 307
#define EXEMPT 308
#define EXPIRATION 309
#define FAILED_OPER_NOTICE 310
#define FLATTEN_LINKS 311
#define FLATTEN_LINKS_DELAY 312
#define FLATTEN_LINKS_FILE 313
#define GECOS 314
#define GENERAL 315
#define HIDDEN 316
#define HIDDEN_NAME 317
#define HIDE_CHANS 318
#define HIDE_IDLE 319
#define HIDE_IDLE_FROM_OPERS 320
#define HIDE_SERVER_IPS 321
#define HIDE_SERVERS 322
#define HIDE_SERVICES 323
#define HOST 324
#define HUB 325
#define HUB_MASK 326
#define INVISIBLE_ON_CONNECT 327
#define INVITE_CLIENT_COUNT 328
#define INVITE_CLIENT_TIME 329
#define INVITE_DELAY_CHANNEL 330
#define INVITE_EXPIRE_TIME 331
#define IP 332
#define IRCD_AUTH 333
#define IRCD_FLAGS 334
#define IRCD_SID 335
#define JOIN 336
#define KILL 337
#define KILL_CHASE_TIME_LIMIT 338
#define KLINE 339
#define KLINE_EXEMPT 340
#define KLINE_MIN_CIDR 341
#define KLINE_MIN_CIDR6 342
#define KNOCK_CLIENT_COUNT 343
#define KNOCK_CLIENT_TIME 344
#define KNOCK_DELAY_CHANNEL 345
#define LEAF_MASK 346
#define LISTEN 347
#define LOADMODULE 348
#define MASK 349
#define MASS 350
#define MAX_ACCEPT 351
#define MAX_BANS 352
#define MAX_BANS_LARGE 353
#define MAX_CHANNELS 354
#define MAX_IDLE 355
#define MAX_INVITES 356
#define MAX_MONITOR 357
#define MAX_NICK_CHANGES 358
#define MAX_NICK_LENGTH 359
#define MAX_NICK_TIME 360
#define MAX_NUMBER 361
#define MAX_TARGETS 362
#define MAX_TOPIC_LENGTH 363
#define MESSAGE 364
#define MIN_IDLE 365
#define MIN_NONWILDCARD 366
#define MIN_NONWILDCARD_SIMPLE 367
#define MODULE 368
#define MODULE_BASE_PATH 369
#define MOTD 370
#define NAME 371
#define NEED_IDENT 372
#define NEED_PASSWORD 373
#define NETWORK_DESCRIPTION 374
#define NETWORK_NAME 375
#define NICK 376
#define NO_OPER_FLOOD 377
#define NO_TILDE 378
#define NUMBER_PER_CIDR 379
#define NUMBER_PER_IP_GLOBAL 380
#define NUMBER_PER_IP_LOCAL 381
#define OPER_ONLY_UMODES 382
#define OPER_UMODES 383
#define OPERATOR 384
#define OPERS_BYPASS_CALLERID 385
#define PACE_WAIT 386
#define PACE_WAIT_SIMPLE 387
#define PASSWORD 388
#define PATH 389
#define PING_COOKIE 390
#define PING_TIME 391
#define PORT 392
#define RANDOM_IDLE 393
#define REASON 394
#define REDIRPORT 395
#define REDIRSERV 396
#define REHASH 397
#define REMOTE 398
#define REMOTEBAN 399
#define RESIDENT 400
#define RESV 401
#define RESV_EXEMPT 402
#define RSA_PRIVATE_KEY_FILE 403
#define SECONDS 404
#define MINUTES 405
#define HOURS 406
#define DAYS 407
#define WEEKS 408
#define MONTHS 409
#define YEARS 410
#define SEND_PASSWORD 411
#define SENDQ 412
#define SERVERHIDE 413
#define SERVERINFO 414
#define SHORT_MOTD 415
#define SPECIALS_IN_IDENT 416
#define SPOOF 417
#define SQUIT 418
#define STATS_E_DISABLED 419
#define STATS_I_OPER_ONLY 420
#define STATS_K_OPER_ONLY 421
#define STATS_M_OPER_ONLY 422
#define STATS_O_OPER_ONLY 423
#define STATS_P_OPER_ONLY 424
#define STATS_U_OPER_ONLY 425
#define T_ALL 426
#define T_BIND 427
#define T_CALLERID 428
#define T_CCONN 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEAF 432
#define T_DEBUG 433
#define T_DLINE 434
#define T_EXTERNAL 435
#define T_FARCONNECT 436
#define T_FILE 437
#define T_FLOOD 438
#define T_GLOBOPS 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_LOG 444
#define T_NCHANGE 445
#define T_NONONREG 446
#define T_OPME 447
#define T_PREPEND 448
#define T_PSEUDO 449
#define T_RECVQ 450
#define T_REJ 451
#define T_RESTART 452
#define T_SECUREONLY 453
#define T_SERVER 454
#define T_SERVICE 455
#define T_SERVNOTICE 456
#define T_SET 457
#define T_SHARED 458
#define T_SIZE 459
#define T_SKILL 460
#define T_SOFTCALLERID 461
#define T_SPY 462
#define T_TARGET 463
#define T_TLS 464
#define T_UMODES 465
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
#define TIMEOUT 476
#define TLS_CERTIFICATE_FILE 477
#define TLS_CERTIFICATE_FINGERPRINT 478
#define TLS_CIPHER_LIST 479
#define TLS_CIPHER_SUITES 480
#define TLS_CONNECTION_REQUIRED 481
#define TLS_DH_PARAM_FILE 482
#define TLS_MESSAGE_DIGEST_ALGORITHM 483
#define TLS_SUPPORTED_GROUPS 484
#define TS_MAX_DELTA 485
#define TS_WARN_DELTA 486
#define TWODOTS 487
#define TYPE 488
#define UNKLINE 489
#define USE_LOGGING 490
#define USER 491
#define VHOST 492
#define VHOST6 493
#define WARN_NO_CONNECT_BLOCK 494
#define WHOIS 495
#define WHOWAS_HISTORY_LENGTH 496
#define XLINE 497
#define XLINE_EXEMPT 498
#define QSTRING 499
#define NUMBER 500

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "conf_parser.y"

  int number;
  char *string;

#line 562 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
