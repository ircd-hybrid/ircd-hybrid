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
    CLOSE = 277,                   /* CLOSE  */
    CONNECT = 278,                 /* CONNECT  */
    CONNECTFREQ = 279,             /* CONNECTFREQ  */
    CYCLE_ON_HOST_CHANGE = 280,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 281,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 282,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 283, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 284, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 285,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 286,                   /* DEFER  */
    DENY = 287,                    /* DENY  */
    DESCRIPTION = 288,             /* DESCRIPTION  */
    DIE = 289,                     /* DIE  */
    DISABLE_AUTH = 290,            /* DISABLE_AUTH  */
    DISABLE_FAKE_CHANNELS = 291,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 292, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 293,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 294,         /* DLINE_MIN_CIDR6  */
    EMAIL = 295,                   /* EMAIL  */
    ENABLE_ADMIN = 296,            /* ENABLE_ADMIN  */
    ENABLE_EXTBANS = 297,          /* ENABLE_EXTBANS  */
    ENABLE_OWNER = 298,            /* ENABLE_OWNER  */
    ENCRYPTED = 299,               /* ENCRYPTED  */
    EXCEED_LIMIT = 300,            /* EXCEED_LIMIT  */
    EXEMPT = 301,                  /* EXEMPT  */
    EXPIRATION = 302,              /* EXPIRATION  */
    FAILED_OPER_NOTICE = 303,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 304,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 305,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 306,      /* FLATTEN_LINKS_FILE  */
    GECOS = 307,                   /* GECOS  */
    GENERAL = 308,                 /* GENERAL  */
    HIDDEN = 309,                  /* HIDDEN  */
    HIDDEN_NAME = 310,             /* HIDDEN_NAME  */
    HIDE_CHANS = 311,              /* HIDE_CHANS  */
    HIDE_IDLE = 312,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 313,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 314,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 315,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 316,           /* HIDE_SERVICES  */
    HOST = 317,                    /* HOST  */
    HUB = 318,                     /* HUB  */
    HUB_MASK = 319,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 320,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 321,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 322,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 323,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 324,      /* INVITE_EXPIRE_TIME  */
    IP = 325,                      /* IP  */
    IRCD_AUTH = 326,               /* IRCD_AUTH  */
    IRCD_FLAGS = 327,              /* IRCD_FLAGS  */
    IRCD_SID = 328,                /* IRCD_SID  */
    JOIN = 329,                    /* JOIN  */
    KILL = 330,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 331,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 332,                   /* KLINE  */
    KLINE_EXEMPT = 333,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 334,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 335,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 336,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 337,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 338,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 339,               /* LEAF_MASK  */
    LISTEN = 340,                  /* LISTEN  */
    MASK = 341,                    /* MASK  */
    MASS = 342,                    /* MASS  */
    MAX_ACCEPT = 343,              /* MAX_ACCEPT  */
    MAX_BANS = 344,                /* MAX_BANS  */
    MAX_BANS_LARGE = 345,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 346,            /* MAX_CHANNELS  */
    MAX_IDLE = 347,                /* MAX_IDLE  */
    MAX_INVITES = 348,             /* MAX_INVITES  */
    MAX_MONITOR = 349,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 350,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 351,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 352,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 353,              /* MAX_NUMBER  */
    MAX_TARGETS = 354,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 355,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 356,                 /* MESSAGE  */
    MIN_IDLE = 357,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 358,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 359,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 360,                  /* MODULE  */
    MODULES = 361,                 /* MODULES  */
    MOTD = 362,                    /* MOTD  */
    NAME = 363,                    /* NAME  */
    NEED_IDENT = 364,              /* NEED_IDENT  */
    NEED_PASSWORD = 365,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 366,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 367,            /* NETWORK_NAME  */
    NICK = 368,                    /* NICK  */
    NO_OPER_FLOOD = 369,           /* NO_OPER_FLOOD  */
    NO_TILDE = 370,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 371,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 372,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 373,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 374,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 375,             /* OPER_UMODES  */
    OPERATOR = 376,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 377,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 378,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 379,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 380,                /* PASSWORD  */
    PATH = 381,                    /* PATH  */
    PING_COOKIE = 382,             /* PING_COOKIE  */
    PING_TIME = 383,               /* PING_TIME  */
    PORT = 384,                    /* PORT  */
    RANDOM_IDLE = 385,             /* RANDOM_IDLE  */
    REASON = 386,                  /* REASON  */
    REDIRPORT = 387,               /* REDIRPORT  */
    REDIRSERV = 388,               /* REDIRSERV  */
    REHASH = 389,                  /* REHASH  */
    REMOTE = 390,                  /* REMOTE  */
    REMOTEBAN = 391,               /* REMOTEBAN  */
    RESV = 392,                    /* RESV  */
    RESV_EXEMPT = 393,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 394,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 395,                 /* SECONDS  */
    MINUTES = 396,                 /* MINUTES  */
    HOURS = 397,                   /* HOURS  */
    DAYS = 398,                    /* DAYS  */
    WEEKS = 399,                   /* WEEKS  */
    MONTHS = 400,                  /* MONTHS  */
    YEARS = 401,                   /* YEARS  */
    SEND_PASSWORD = 402,           /* SEND_PASSWORD  */
    SENDQ = 403,                   /* SENDQ  */
    SERVERHIDE = 404,              /* SERVERHIDE  */
    SERVERINFO = 405,              /* SERVERINFO  */
    SHORT_MOTD = 406,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 407,       /* SPECIALS_IN_IDENT  */
    SPOOF = 408,                   /* SPOOF  */
    SQUIT = 409,                   /* SQUIT  */
    STATS_E_DISABLED = 410,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 411,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 412,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 413,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 414,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 415,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 416,       /* STATS_U_OPER_ONLY  */
    T_ALL = 417,                   /* T_ALL  */
    T_BIND = 418,                  /* T_BIND  */
    T_CALLERID = 419,              /* T_CALLERID  */
    T_CCONN = 420,                 /* T_CCONN  */
    T_COMMAND = 421,               /* T_COMMAND  */
    T_CLUSTER = 422,               /* T_CLUSTER  */
    T_DEAF = 423,                  /* T_DEAF  */
    T_DEBUG = 424,                 /* T_DEBUG  */
    T_DLINE = 425,                 /* T_DLINE  */
    T_EXTERNAL = 426,              /* T_EXTERNAL  */
    T_FARCONNECT = 427,            /* T_FARCONNECT  */
    T_FILE = 428,                  /* T_FILE  */
    T_FLOOD = 429,                 /* T_FLOOD  */
    T_GLOBOPS = 430,               /* T_GLOBOPS  */
    T_INVISIBLE = 431,             /* T_INVISIBLE  */
    T_IPV4 = 432,                  /* T_IPV4  */
    T_IPV6 = 433,                  /* T_IPV6  */
    T_LOCOPS = 434,                /* T_LOCOPS  */
    T_LOG = 435,                   /* T_LOG  */
    T_NCHANGE = 436,               /* T_NCHANGE  */
    T_NONONREG = 437,              /* T_NONONREG  */
    T_OPME = 438,                  /* T_OPME  */
    T_PREPEND = 439,               /* T_PREPEND  */
    T_PSEUDO = 440,                /* T_PSEUDO  */
    T_RECVQ = 441,                 /* T_RECVQ  */
    T_REJ = 442,                   /* T_REJ  */
    T_RESTART = 443,               /* T_RESTART  */
    T_SECUREONLY = 444,            /* T_SECUREONLY  */
    T_SERVER = 445,                /* T_SERVER  */
    T_SERVICE = 446,               /* T_SERVICE  */
    T_SERVNOTICE = 447,            /* T_SERVNOTICE  */
    T_SET = 448,                   /* T_SET  */
    T_SHARED = 449,                /* T_SHARED  */
    T_SIZE = 450,                  /* T_SIZE  */
    T_SKILL = 451,                 /* T_SKILL  */
    T_SOFTCALLERID = 452,          /* T_SOFTCALLERID  */
    T_SPY = 453,                   /* T_SPY  */
    T_TARGET = 454,                /* T_TARGET  */
    T_TLS = 455,                   /* T_TLS  */
    T_UMODES = 456,                /* T_UMODES  */
    T_UNDLINE = 457,               /* T_UNDLINE  */
    T_UNLIMITED = 458,             /* T_UNLIMITED  */
    T_UNRESV = 459,                /* T_UNRESV  */
    T_UNXLINE = 460,               /* T_UNXLINE  */
    T_WALLOP = 461,                /* T_WALLOP  */
    T_WALLOPS = 462,               /* T_WALLOPS  */
    T_WEBIRC = 463,                /* T_WEBIRC  */
    TBOOL = 464,                   /* TBOOL  */
    THROTTLE_COUNT = 465,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 466,           /* THROTTLE_TIME  */
    TIMEOUT = 467,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 468,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 469, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 470,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 471,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 472, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 473,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 474, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 475,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 476,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 477,           /* TS_WARN_DELTA  */
    TWODOTS = 478,                 /* TWODOTS  */
    TYPE = 479,                    /* TYPE  */
    UNKLINE = 480,                 /* UNKLINE  */
    USE_LOGGING = 481,             /* USE_LOGGING  */
    USER = 482,                    /* USER  */
    VHOST = 483,                   /* VHOST  */
    VHOST6 = 484,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 485,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 486,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 487,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 488,                   /* XLINE  */
    XLINE_EXEMPT = 489,            /* XLINE_EXEMPT  */
    QSTRING = 490,                 /* QSTRING  */
    NUMBER = 491                   /* NUMBER  */
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
#define MASS 342
#define MAX_ACCEPT 343
#define MAX_BANS 344
#define MAX_BANS_LARGE 345
#define MAX_CHANNELS 346
#define MAX_IDLE 347
#define MAX_INVITES 348
#define MAX_MONITOR 349
#define MAX_NICK_CHANGES 350
#define MAX_NICK_LENGTH 351
#define MAX_NICK_TIME 352
#define MAX_NUMBER 353
#define MAX_TARGETS 354
#define MAX_TOPIC_LENGTH 355
#define MESSAGE 356
#define MIN_IDLE 357
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULES 361
#define MOTD 362
#define NAME 363
#define NEED_IDENT 364
#define NEED_PASSWORD 365
#define NETWORK_DESCRIPTION 366
#define NETWORK_NAME 367
#define NICK 368
#define NO_OPER_FLOOD 369
#define NO_TILDE 370
#define NUMBER_PER_CIDR 371
#define NUMBER_PER_IP_GLOBAL 372
#define NUMBER_PER_IP_LOCAL 373
#define OPER_ONLY_UMODES 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PATH 381
#define PING_COOKIE 382
#define PING_TIME 383
#define PORT 384
#define RANDOM_IDLE 385
#define REASON 386
#define REDIRPORT 387
#define REDIRSERV 388
#define REHASH 389
#define REMOTE 390
#define REMOTEBAN 391
#define RESV 392
#define RESV_EXEMPT 393
#define RSA_PRIVATE_KEY_FILE 394
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
#define SPECIALS_IN_IDENT 407
#define SPOOF 408
#define SQUIT 409
#define STATS_E_DISABLED 410
#define STATS_I_OPER_ONLY 411
#define STATS_K_OPER_ONLY 412
#define STATS_M_OPER_ONLY 413
#define STATS_O_OPER_ONLY 414
#define STATS_P_OPER_ONLY 415
#define STATS_U_OPER_ONLY 416
#define T_ALL 417
#define T_BIND 418
#define T_CALLERID 419
#define T_CCONN 420
#define T_COMMAND 421
#define T_CLUSTER 422
#define T_DEAF 423
#define T_DEBUG 424
#define T_DLINE 425
#define T_EXTERNAL 426
#define T_FARCONNECT 427
#define T_FILE 428
#define T_FLOOD 429
#define T_GLOBOPS 430
#define T_INVISIBLE 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_LOG 435
#define T_NCHANGE 436
#define T_NONONREG 437
#define T_OPME 438
#define T_PREPEND 439
#define T_PSEUDO 440
#define T_RECVQ 441
#define T_REJ 442
#define T_RESTART 443
#define T_SECUREONLY 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SERVNOTICE 447
#define T_SET 448
#define T_SHARED 449
#define T_SIZE 450
#define T_SKILL 451
#define T_SOFTCALLERID 452
#define T_SPY 453
#define T_TARGET 454
#define T_TLS 455
#define T_UMODES 456
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
#define TIMEOUT 467
#define TLS_CERTIFICATE_FILE 468
#define TLS_CERTIFICATE_FINGERPRINT 469
#define TLS_CIPHER_LIST 470
#define TLS_CIPHER_SUITES 471
#define TLS_CONNECTION_REQUIRED 472
#define TLS_DH_PARAM_FILE 473
#define TLS_MESSAGE_DIGEST_ALGORITHM 474
#define TLS_SUPPORTED_GROUPS 475
#define TS_MAX_DELTA 476
#define TS_WARN_DELTA 477
#define TWODOTS 478
#define TYPE 479
#define UNKLINE 480
#define USE_LOGGING 481
#define USER 482
#define VHOST 483
#define VHOST6 484
#define WARN_NO_CONNECT_BLOCK 485
#define WHOIS 486
#define WHOWAS_HISTORY_LENGTH 487
#define XLINE 488
#define XLINE_EXEMPT 489
#define QSTRING 490
#define NUMBER 491

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "conf_parser.y"

  int number;
  char *string;

#line 544 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
