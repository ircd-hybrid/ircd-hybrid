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
    MAX_ACCEPT = 342,              /* MAX_ACCEPT  */
    MAX_BANS = 343,                /* MAX_BANS  */
    MAX_BANS_LARGE = 344,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 345,            /* MAX_CHANNELS  */
    MAX_IDLE = 346,                /* MAX_IDLE  */
    MAX_INVITES = 347,             /* MAX_INVITES  */
    MAX_MONITOR = 348,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 349,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 350,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 351,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 352,              /* MAX_NUMBER  */
    MAX_TARGETS = 353,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 354,        /* MAX_TOPIC_LENGTH  */
    MIN_IDLE = 355,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 356,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 357,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 358,                  /* MODULE  */
    MODULES = 359,                 /* MODULES  */
    MOTD = 360,                    /* MOTD  */
    NAME = 361,                    /* NAME  */
    NEED_IDENT = 362,              /* NEED_IDENT  */
    NEED_PASSWORD = 363,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 364,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 365,            /* NETWORK_NAME  */
    NICK = 366,                    /* NICK  */
    NO_OPER_FLOOD = 367,           /* NO_OPER_FLOOD  */
    NO_TILDE = 368,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 369,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 370,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 371,     /* NUMBER_PER_IP_LOCAL  */
    OPER_ONLY_UMODES = 372,        /* OPER_ONLY_UMODES  */
    OPER_UMODES = 373,             /* OPER_UMODES  */
    OPERATOR = 374,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 375,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 376,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 377,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 378,                /* PASSWORD  */
    PATH = 379,                    /* PATH  */
    PING_COOKIE = 380,             /* PING_COOKIE  */
    PING_TIME = 381,               /* PING_TIME  */
    PORT = 382,                    /* PORT  */
    RANDOM_IDLE = 383,             /* RANDOM_IDLE  */
    REASON = 384,                  /* REASON  */
    REDIRPORT = 385,               /* REDIRPORT  */
    REDIRSERV = 386,               /* REDIRSERV  */
    REHASH = 387,                  /* REHASH  */
    REMOTE = 388,                  /* REMOTE  */
    REMOTEBAN = 389,               /* REMOTEBAN  */
    RESV = 390,                    /* RESV  */
    RESV_EXEMPT = 391,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 392,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 393,                 /* SECONDS  */
    MINUTES = 394,                 /* MINUTES  */
    HOURS = 395,                   /* HOURS  */
    DAYS = 396,                    /* DAYS  */
    WEEKS = 397,                   /* WEEKS  */
    MONTHS = 398,                  /* MONTHS  */
    YEARS = 399,                   /* YEARS  */
    SEND_PASSWORD = 400,           /* SEND_PASSWORD  */
    SENDQ = 401,                   /* SENDQ  */
    SERVERHIDE = 402,              /* SERVERHIDE  */
    SERVERINFO = 403,              /* SERVERINFO  */
    SHORT_MOTD = 404,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 405,       /* SPECIALS_IN_IDENT  */
    SPOOF = 406,                   /* SPOOF  */
    SQUIT = 407,                   /* SQUIT  */
    STATS_E_DISABLED = 408,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 409,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 410,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 411,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 412,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 413,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 414,       /* STATS_U_OPER_ONLY  */
    T_ALL = 415,                   /* T_ALL  */
    T_BIND = 416,                  /* T_BIND  */
    T_CALLERID = 417,              /* T_CALLERID  */
    T_CCONN = 418,                 /* T_CCONN  */
    T_COMMAND = 419,               /* T_COMMAND  */
    T_CLUSTER = 420,               /* T_CLUSTER  */
    T_DEAF = 421,                  /* T_DEAF  */
    T_DEBUG = 422,                 /* T_DEBUG  */
    T_DLINE = 423,                 /* T_DLINE  */
    T_EXTERNAL = 424,              /* T_EXTERNAL  */
    T_FARCONNECT = 425,            /* T_FARCONNECT  */
    T_FILE = 426,                  /* T_FILE  */
    T_FLOOD = 427,                 /* T_FLOOD  */
    T_GLOBOPS = 428,               /* T_GLOBOPS  */
    T_INVISIBLE = 429,             /* T_INVISIBLE  */
    T_IPV4 = 430,                  /* T_IPV4  */
    T_IPV6 = 431,                  /* T_IPV6  */
    T_LOCOPS = 432,                /* T_LOCOPS  */
    T_LOG = 433,                   /* T_LOG  */
    T_NCHANGE = 434,               /* T_NCHANGE  */
    T_NONONREG = 435,              /* T_NONONREG  */
    T_OPME = 436,                  /* T_OPME  */
    T_PREPEND = 437,               /* T_PREPEND  */
    T_PSEUDO = 438,                /* T_PSEUDO  */
    T_RECVQ = 439,                 /* T_RECVQ  */
    T_REJ = 440,                   /* T_REJ  */
    T_RESTART = 441,               /* T_RESTART  */
    T_SERVER = 442,                /* T_SERVER  */
    T_SERVICE = 443,               /* T_SERVICE  */
    T_SERVNOTICE = 444,            /* T_SERVNOTICE  */
    T_SET = 445,                   /* T_SET  */
    T_SHARED = 446,                /* T_SHARED  */
    T_SIZE = 447,                  /* T_SIZE  */
    T_SKILL = 448,                 /* T_SKILL  */
    T_SOFTCALLERID = 449,          /* T_SOFTCALLERID  */
    T_SPY = 450,                   /* T_SPY  */
    T_TARGET = 451,                /* T_TARGET  */
    T_TLS = 452,                   /* T_TLS  */
    T_UMODES = 453,                /* T_UMODES  */
    T_UNDLINE = 454,               /* T_UNDLINE  */
    T_UNLIMITED = 455,             /* T_UNLIMITED  */
    T_UNRESV = 456,                /* T_UNRESV  */
    T_UNXLINE = 457,               /* T_UNXLINE  */
    T_WALLOP = 458,                /* T_WALLOP  */
    T_WALLOPS = 459,               /* T_WALLOPS  */
    T_WEBIRC = 460,                /* T_WEBIRC  */
    TBOOL = 461,                   /* TBOOL  */
    THROTTLE_COUNT = 462,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 463,           /* THROTTLE_TIME  */
    TIMEOUT = 464,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 465,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 466, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 467,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 468,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 469, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 470,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 471, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 472,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 473,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 474,           /* TS_WARN_DELTA  */
    TWODOTS = 475,                 /* TWODOTS  */
    TYPE = 476,                    /* TYPE  */
    UNKLINE = 477,                 /* UNKLINE  */
    USE_LOGGING = 478,             /* USE_LOGGING  */
    USER = 479,                    /* USER  */
    VHOST = 480,                   /* VHOST  */
    VHOST6 = 481,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 482,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 483,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 484,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 485,                   /* XLINE  */
    XLINE_EXEMPT = 486,            /* XLINE_EXEMPT  */
    QSTRING = 487,                 /* QSTRING  */
    NUMBER = 488                   /* NUMBER  */
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

#line 538 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
