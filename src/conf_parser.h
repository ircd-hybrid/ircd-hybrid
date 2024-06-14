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
    CYCLE_ON_HOST_CHANGE = 286,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 287,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 288,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 289, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 290, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 291,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 292,                   /* DEFER  */
    DENY = 293,                    /* DENY  */
    DESCRIPTION = 294,             /* DESCRIPTION  */
    DIE = 295,                     /* DIE  */
    DISABLE_AUTH = 296,            /* DISABLE_AUTH  */
    DISABLE_FAKE_CHANNELS = 297,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 298, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 299,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 300,         /* DLINE_MIN_CIDR6  */
    EMAIL = 301,                   /* EMAIL  */
    ENABLE_ADMIN = 302,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 303,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 304,            /* ENABLE_OWNER  */
    ENCRYPTED = 305,               /* ENCRYPTED  */
    EXCEED_LIMIT = 306,            /* EXCEED_LIMIT  */
    EXEMPT = 307,                  /* EXEMPT  */
    EXPIRATION = 308,              /* EXPIRATION  */
    FAILED_OPER_NOTICE = 309,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 310,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 311,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 312,      /* FLATTEN_LINKS_FILE  */
    GECOS = 313,                   /* GECOS  */
    GENERAL = 314,                 /* GENERAL  */
    HIDDEN = 315,                  /* HIDDEN  */
    HIDDEN_NAME = 316,             /* HIDDEN_NAME  */
    HIDE_CHANS = 317,              /* HIDE_CHANS  */
    HIDE_IDLE = 318,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 319,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 320,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 321,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 322,           /* HIDE_SERVICES  */
    HOST = 323,                    /* HOST  */
    HUB = 324,                     /* HUB  */
    HUB_MASK = 325,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 326,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 327,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 328,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 329,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 330,      /* INVITE_EXPIRE_TIME  */
    IP = 331,                      /* IP  */
    IRCD_AUTH = 332,               /* IRCD_AUTH  */
    IRCD_FLAGS = 333,              /* IRCD_FLAGS  */
    IRCD_SID = 334,                /* IRCD_SID  */
    JOIN = 335,                    /* JOIN  */
    KILL = 336,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 337,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 338,                   /* KLINE  */
    KLINE_EXEMPT = 339,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 340,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 341,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 342,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 343,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 344,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 345,               /* LEAF_MASK  */
    LISTEN = 346,                  /* LISTEN  */
    MASK = 347,                    /* MASK  */
    MASS = 348,                    /* MASS  */
    MAX_ACCEPT = 349,              /* MAX_ACCEPT  */
    MAX_BANS = 350,                /* MAX_BANS  */
    MAX_BANS_LARGE = 351,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 352,            /* MAX_CHANNELS  */
    MAX_IDLE = 353,                /* MAX_IDLE  */
    MAX_INVITES = 354,             /* MAX_INVITES  */
    MAX_MONITOR = 355,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 356,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 357,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 358,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 359,              /* MAX_NUMBER  */
    MAX_TARGETS = 360,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 361,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 362,                 /* MESSAGE  */
    MIN_IDLE = 363,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 364,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 365,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 366,                  /* MODULE  */
    MODULES = 367,                 /* MODULES  */
    MOTD = 368,                    /* MOTD  */
    NAME = 369,                    /* NAME  */
    NEED_IDENT = 370,              /* NEED_IDENT  */
    NEED_PASSWORD = 371,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 372,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 373,            /* NETWORK_NAME  */
    NICK = 374,                    /* NICK  */
    NO_OPER_FLOOD = 375,           /* NO_OPER_FLOOD  */
    NO_TILDE = 376,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 377,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 378,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 379,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 380,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 381,             /* OPER_UMODES  */
    OPERATOR = 382,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 383,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 384,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 385,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 386,                /* PASSWORD  */
    PATH = 387,                    /* PATH  */
    PING_COOKIE = 388,             /* PING_COOKIE  */
    PING_TIME = 389,               /* PING_TIME  */
    PORT = 390,                    /* PORT  */
    RANDOM_IDLE = 391,             /* RANDOM_IDLE  */
    REASON = 392,                  /* REASON  */
    REDIRPORT = 393,               /* REDIRPORT  */
    REDIRSERV = 394,               /* REDIRSERV  */
    REHASH = 395,                  /* REHASH  */
    REMOTE = 396,                  /* REMOTE  */
    REMOTEBAN = 397,               /* REMOTEBAN  */
    RESV = 398,                    /* RESV  */
    RESV_EXEMPT = 399,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 400,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 401,                 /* SECONDS  */
    MINUTES = 402,                 /* MINUTES  */
    HOURS = 403,                   /* HOURS  */
    DAYS = 404,                    /* DAYS  */
    WEEKS = 405,                   /* WEEKS  */
    MONTHS = 406,                  /* MONTHS  */
    YEARS = 407,                   /* YEARS  */
    SEND_PASSWORD = 408,           /* SEND_PASSWORD  */
    SENDQ = 409,                   /* SENDQ  */
    SERVERHIDE = 410,              /* SERVERHIDE  */
    SERVERINFO = 411,              /* SERVERINFO  */
    SHORT_MOTD = 412,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 413,       /* SPECIALS_IN_IDENT  */
    SPOOF = 414,                   /* SPOOF  */
    SQUIT = 415,                   /* SQUIT  */
    STATS_E_DISABLED = 416,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 417,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 418,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 419,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 420,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 421,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 422,       /* STATS_U_OPER_ONLY  */
    T_ALL = 423,                   /* T_ALL  */
    T_BIND = 424,                  /* T_BIND  */
    T_CALLERID = 425,              /* T_CALLERID  */
    T_CCONN = 426,                 /* T_CCONN  */
    T_COMMAND = 427,               /* T_COMMAND  */
    T_CLUSTER = 428,               /* T_CLUSTER  */
    T_DEAF = 429,                  /* T_DEAF  */
    T_DEBUG = 430,                 /* T_DEBUG  */
    T_DLINE = 431,                 /* T_DLINE  */
    T_EXTERNAL = 432,              /* T_EXTERNAL  */
    T_FARCONNECT = 433,            /* T_FARCONNECT  */
    T_FILE = 434,                  /* T_FILE  */
    T_FLOOD = 435,                 /* T_FLOOD  */
    T_GLOBOPS = 436,               /* T_GLOBOPS  */
    T_INVISIBLE = 437,             /* T_INVISIBLE  */
    T_IPV4 = 438,                  /* T_IPV4  */
    T_IPV6 = 439,                  /* T_IPV6  */
    T_LOCOPS = 440,                /* T_LOCOPS  */
    T_LOG = 441,                   /* T_LOG  */
    T_NCHANGE = 442,               /* T_NCHANGE  */
    T_NONONREG = 443,              /* T_NONONREG  */
    T_OPME = 444,                  /* T_OPME  */
    T_PREPEND = 445,               /* T_PREPEND  */
    T_PSEUDO = 446,                /* T_PSEUDO  */
    T_RECVQ = 447,                 /* T_RECVQ  */
    T_REJ = 448,                   /* T_REJ  */
    T_RESTART = 449,               /* T_RESTART  */
    T_SECUREONLY = 450,            /* T_SECUREONLY  */
    T_SERVER = 451,                /* T_SERVER  */
    T_SERVICE = 452,               /* T_SERVICE  */
    T_SERVNOTICE = 453,            /* T_SERVNOTICE  */
    T_SET = 454,                   /* T_SET  */
    T_SHARED = 455,                /* T_SHARED  */
    T_SIZE = 456,                  /* T_SIZE  */
    T_SKILL = 457,                 /* T_SKILL  */
    T_SOFTCALLERID = 458,          /* T_SOFTCALLERID  */
    T_SPY = 459,                   /* T_SPY  */
    T_TARGET = 460,                /* T_TARGET  */
    T_TLS = 461,                   /* T_TLS  */
    T_UMODES = 462,                /* T_UMODES  */
    T_UNDLINE = 463,               /* T_UNDLINE  */
    T_UNLIMITED = 464,             /* T_UNLIMITED  */
    T_UNRESV = 465,                /* T_UNRESV  */
    T_UNXLINE = 466,               /* T_UNXLINE  */
    T_WALLOP = 467,                /* T_WALLOP  */
    T_WALLOPS = 468,               /* T_WALLOPS  */
    T_WEBIRC = 469,                /* T_WEBIRC  */
    TBOOL = 470,                   /* TBOOL  */
    THROTTLE_COUNT = 471,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 472,           /* THROTTLE_TIME  */
    TIMEOUT = 473,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 474,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 475, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 476,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 477,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 478, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 479,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 480, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 481,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 482,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 483,           /* TS_WARN_DELTA  */
    TWODOTS = 484,                 /* TWODOTS  */
    TYPE = 485,                    /* TYPE  */
    UNKLINE = 486,                 /* UNKLINE  */
    USE_LOGGING = 487,             /* USE_LOGGING  */
    USER = 488,                    /* USER  */
    VHOST = 489,                   /* VHOST  */
    VHOST6 = 490,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 491,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 492,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 493,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 494,                   /* XLINE  */
    XLINE_EXEMPT = 495,            /* XLINE_EXEMPT  */
    QSTRING = 496,                 /* QSTRING  */
    NUMBER = 497                   /* NUMBER  */
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
#define CYCLE_ON_HOST_CHANGE 286
#define DEFAULT_FLOODCOUNT 287
#define DEFAULT_FLOODTIME 288
#define DEFAULT_JOIN_FLOOD_COUNT 289
#define DEFAULT_JOIN_FLOOD_TIME 290
#define DEFAULT_MAX_CLIENTS 291
#define DEFER 292
#define DENY 293
#define DESCRIPTION 294
#define DIE 295
#define DISABLE_AUTH 296
#define DISABLE_FAKE_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DLINE_MIN_CIDR 299
#define DLINE_MIN_CIDR6 300
#define EMAIL 301
#define ENABLE_ADMIN 302
#define ENABLE_EXTBANS 303
#define ENABLE_OWNER 304
#define ENCRYPTED 305
#define EXCEED_LIMIT 306
#define EXEMPT 307
#define EXPIRATION 308
#define FAILED_OPER_NOTICE 309
#define FLATTEN_LINKS 310
#define FLATTEN_LINKS_DELAY 311
#define FLATTEN_LINKS_FILE 312
#define GECOS 313
#define GENERAL 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_CHANS 317
#define HIDE_IDLE 318
#define HIDE_IDLE_FROM_OPERS 319
#define HIDE_SERVER_IPS 320
#define HIDE_SERVERS 321
#define HIDE_SERVICES 322
#define HOST 323
#define HUB 324
#define HUB_MASK 325
#define INVISIBLE_ON_CONNECT 326
#define INVITE_CLIENT_COUNT 327
#define INVITE_CLIENT_TIME 328
#define INVITE_DELAY_CHANNEL 329
#define INVITE_EXPIRE_TIME 330
#define IP 331
#define IRCD_AUTH 332
#define IRCD_FLAGS 333
#define IRCD_SID 334
#define JOIN 335
#define KILL 336
#define KILL_CHASE_TIME_LIMIT 337
#define KLINE 338
#define KLINE_EXEMPT 339
#define KLINE_MIN_CIDR 340
#define KLINE_MIN_CIDR6 341
#define KNOCK_CLIENT_COUNT 342
#define KNOCK_CLIENT_TIME 343
#define KNOCK_DELAY_CHANNEL 344
#define LEAF_MASK 345
#define LISTEN 346
#define MASK 347
#define MASS 348
#define MAX_ACCEPT 349
#define MAX_BANS 350
#define MAX_BANS_LARGE 351
#define MAX_CHANNELS 352
#define MAX_IDLE 353
#define MAX_INVITES 354
#define MAX_MONITOR 355
#define MAX_NICK_CHANGES 356
#define MAX_NICK_LENGTH 357
#define MAX_NICK_TIME 358
#define MAX_NUMBER 359
#define MAX_TARGETS 360
#define MAX_TOPIC_LENGTH 361
#define MESSAGE 362
#define MIN_IDLE 363
#define MIN_NONWILDCARD 364
#define MIN_NONWILDCARD_SIMPLE 365
#define MODULE 366
#define MODULES 367
#define MOTD 368
#define NAME 369
#define NEED_IDENT 370
#define NEED_PASSWORD 371
#define NETWORK_DESCRIPTION 372
#define NETWORK_NAME 373
#define NICK 374
#define NO_OPER_FLOOD 375
#define NO_TILDE 376
#define NUMBER_PER_CIDR 377
#define NUMBER_PER_IP_GLOBAL 378
#define NUMBER_PER_IP_LOCAL 379
#define OPER_ONLY_UMODES 380
#define OPER_UMODES 381
#define OPERATOR 382
#define OPERS_BYPASS_CALLERID 383
#define PACE_WAIT 384
#define PACE_WAIT_SIMPLE 385
#define PASSWORD 386
#define PATH 387
#define PING_COOKIE 388
#define PING_TIME 389
#define PORT 390
#define RANDOM_IDLE 391
#define REASON 392
#define REDIRPORT 393
#define REDIRSERV 394
#define REHASH 395
#define REMOTE 396
#define REMOTEBAN 397
#define RESV 398
#define RESV_EXEMPT 399
#define RSA_PRIVATE_KEY_FILE 400
#define SECONDS 401
#define MINUTES 402
#define HOURS 403
#define DAYS 404
#define WEEKS 405
#define MONTHS 406
#define YEARS 407
#define SEND_PASSWORD 408
#define SENDQ 409
#define SERVERHIDE 410
#define SERVERINFO 411
#define SHORT_MOTD 412
#define SPECIALS_IN_IDENT 413
#define SPOOF 414
#define SQUIT 415
#define STATS_E_DISABLED 416
#define STATS_I_OPER_ONLY 417
#define STATS_K_OPER_ONLY 418
#define STATS_M_OPER_ONLY 419
#define STATS_O_OPER_ONLY 420
#define STATS_P_OPER_ONLY 421
#define STATS_U_OPER_ONLY 422
#define T_ALL 423
#define T_BIND 424
#define T_CALLERID 425
#define T_CCONN 426
#define T_COMMAND 427
#define T_CLUSTER 428
#define T_DEAF 429
#define T_DEBUG 430
#define T_DLINE 431
#define T_EXTERNAL 432
#define T_FARCONNECT 433
#define T_FILE 434
#define T_FLOOD 435
#define T_GLOBOPS 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_LOG 441
#define T_NCHANGE 442
#define T_NONONREG 443
#define T_OPME 444
#define T_PREPEND 445
#define T_PSEUDO 446
#define T_RECVQ 447
#define T_REJ 448
#define T_RESTART 449
#define T_SECUREONLY 450
#define T_SERVER 451
#define T_SERVICE 452
#define T_SERVNOTICE 453
#define T_SET 454
#define T_SHARED 455
#define T_SIZE 456
#define T_SKILL 457
#define T_SOFTCALLERID 458
#define T_SPY 459
#define T_TARGET 460
#define T_TLS 461
#define T_UMODES 462
#define T_UNDLINE 463
#define T_UNLIMITED 464
#define T_UNRESV 465
#define T_UNXLINE 466
#define T_WALLOP 467
#define T_WALLOPS 468
#define T_WEBIRC 469
#define TBOOL 470
#define THROTTLE_COUNT 471
#define THROTTLE_TIME 472
#define TIMEOUT 473
#define TLS_CERTIFICATE_FILE 474
#define TLS_CERTIFICATE_FINGERPRINT 475
#define TLS_CIPHER_LIST 476
#define TLS_CIPHER_SUITES 477
#define TLS_CONNECTION_REQUIRED 478
#define TLS_DH_PARAM_FILE 479
#define TLS_MESSAGE_DIGEST_ALGORITHM 480
#define TLS_SUPPORTED_GROUPS 481
#define TS_MAX_DELTA 482
#define TS_WARN_DELTA 483
#define TWODOTS 484
#define TYPE 485
#define UNKLINE 486
#define USE_LOGGING 487
#define USER 488
#define VHOST 489
#define VHOST6 490
#define WARN_NO_CONNECT_BLOCK 491
#define WHOIS 492
#define WHOWAS_HISTORY_LENGTH 493
#define XLINE 494
#define XLINE_EXEMPT 495
#define QSTRING 496
#define NUMBER 497

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 556 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
