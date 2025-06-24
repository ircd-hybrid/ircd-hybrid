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
    BYTES = 266,                   /* BYTES  */
    KBYTES = 267,                  /* KBYTES  */
    MBYTES = 268,                  /* MBYTES  */
    CALLER_ID_WAIT = 269,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 270,               /* CAN_FLOOD  */
    CHANNEL = 271,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 272,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 273,        /* CIDR_BITLEN_IPV6  */
    CLASS = 274,                   /* CLASS  */
    CLIENT = 275,                  /* CLIENT  */
    CLOAK_ENABLED = 276,           /* CLOAK_ENABLED  */
    CLOAK_CIDR_LEN_IPV4 = 277,     /* CLOAK_CIDR_LEN_IPV4  */
    CLOAK_CIDR_LEN_IPV6 = 278,     /* CLOAK_CIDR_LEN_IPV6  */
    CLOAK_NUM_BITS = 279,          /* CLOAK_NUM_BITS  */
    CLOAK_SECRET = 280,            /* CLOAK_SECRET  */
    CLOAK_SUFFIX = 281,            /* CLOAK_SUFFIX  */
    CLOSE = 282,                   /* CLOSE  */
    CONNECT = 283,                 /* CONNECT  */
    CONNECTFREQ = 284,             /* CONNECTFREQ  */
    CORE = 285,                    /* CORE  */
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
    DISABLE_DNS = 296,             /* DISABLE_DNS  */
    DISABLE_IDENT = 297,           /* DISABLE_IDENT  */
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
    IDENT_TIMEOUT = 326,           /* IDENT_TIMEOUT  */
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
    MAX_AWAY_LENGTH = 352,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 353,                /* MAX_BANS  */
    MAX_BANS_LARGE = 354,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 355,            /* MAX_CHANNELS  */
    MAX_IDLE = 356,                /* MAX_IDLE  */
    MAX_INVITES = 357,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 358,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 359,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 360,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 361,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 362,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 363,              /* MAX_NUMBER  */
    MAX_TARGETS = 364,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 365,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 366,                 /* MESSAGE  */
    MIN_IDLE = 367,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 368,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 369,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 370,                  /* MODULE  */
    MODULE_BASE_PATH = 371,        /* MODULE_BASE_PATH  */
    MOTD = 372,                    /* MOTD  */
    MOTD_FILE = 373,               /* MOTD_FILE  */
    NAME = 374,                    /* NAME  */
    NEED_IDENT = 375,              /* NEED_IDENT  */
    NEED_PASSWORD = 376,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 377,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 378,            /* NETWORK_NAME  */
    NICK = 379,                    /* NICK  */
    NO_OPER_FLOOD = 380,           /* NO_OPER_FLOOD  */
    NO_TILDE = 381,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 382,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 383,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 384,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 385,             /* OPER_UMODES  */
    OPERATOR = 386,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 387,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 388,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 389,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 390,                /* PASSWORD  */
    PATH = 391,                    /* PATH  */
    PING_COOKIE = 392,             /* PING_COOKIE  */
    PING_TIME = 393,               /* PING_TIME  */
    PORT = 394,                    /* PORT  */
    RANDOM_IDLE = 395,             /* RANDOM_IDLE  */
    REASON = 396,                  /* REASON  */
    REDIRPORT = 397,               /* REDIRPORT  */
    REDIRSERV = 398,               /* REDIRSERV  */
    REHASH = 399,                  /* REHASH  */
    REMOTE = 400,                  /* REMOTE  */
    REMOTEBAN = 401,               /* REMOTEBAN  */
    RESIDENT = 402,                /* RESIDENT  */
    RESV = 403,                    /* RESV  */
    RESV_EXEMPT = 404,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 405,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 406,                 /* SECONDS  */
    MINUTES = 407,                 /* MINUTES  */
    HOURS = 408,                   /* HOURS  */
    DAYS = 409,                    /* DAYS  */
    WEEKS = 410,                   /* WEEKS  */
    MONTHS = 411,                  /* MONTHS  */
    YEARS = 412,                   /* YEARS  */
    SEND_PASSWORD = 413,           /* SEND_PASSWORD  */
    SENDQ = 414,                   /* SENDQ  */
    SERVERHIDE = 415,              /* SERVERHIDE  */
    SERVERINFO = 416,              /* SERVERINFO  */
    SHORT_MOTD = 417,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 418,       /* SPECIALS_IN_IDENT  */
    SPOOF = 419,                   /* SPOOF  */
    SQUIT = 420,                   /* SQUIT  */
    STATS_E_DISABLED = 421,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 422,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 423,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 424,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 425,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 426,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 427,       /* STATS_U_OPER_ONLY  */
    T_ALL = 428,                   /* T_ALL  */
    T_BIND = 429,                  /* T_BIND  */
    T_COMMAND = 430,               /* T_COMMAND  */
    T_CLUSTER = 431,               /* T_CLUSTER  */
    T_DEBUG = 432,                 /* T_DEBUG  */
    T_DLINE = 433,                 /* T_DLINE  */
    T_FILE = 434,                  /* T_FILE  */
    T_GLOBOPS = 435,               /* T_GLOBOPS  */
    T_IPV4 = 436,                  /* T_IPV4  */
    T_IPV6 = 437,                  /* T_IPV6  */
    T_LOCOPS = 438,                /* T_LOCOPS  */
    T_LOG = 439,                   /* T_LOG  */
    T_OPME = 440,                  /* T_OPME  */
    T_PREPEND = 441,               /* T_PREPEND  */
    T_PSEUDO = 442,                /* T_PSEUDO  */
    T_RECVQ = 443,                 /* T_RECVQ  */
    T_RESTART = 444,               /* T_RESTART  */
    T_SERVER = 445,                /* T_SERVER  */
    T_SERVICE = 446,               /* T_SERVICE  */
    T_SET = 447,                   /* T_SET  */
    T_SHARED = 448,                /* T_SHARED  */
    T_SIZE = 449,                  /* T_SIZE  */
    T_TARGET = 450,                /* T_TARGET  */
    T_TLS = 451,                   /* T_TLS  */
    T_UMODES = 452,                /* T_UMODES  */
    T_UNDLINE = 453,               /* T_UNDLINE  */
    T_UNLIMITED = 454,             /* T_UNLIMITED  */
    T_UNRESV = 455,                /* T_UNRESV  */
    T_UNXLINE = 456,               /* T_UNXLINE  */
    T_WEBIRC = 457,                /* T_WEBIRC  */
    TBOOL = 458,                   /* TBOOL  */
    THROTTLE_COUNT = 459,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 460,           /* THROTTLE_TIME  */
    TIMEOUT = 461,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 462,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 463, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 464,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 465,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 466, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 467,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 468, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 469,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 470,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 471,           /* TS_WARN_DELTA  */
    TWODOTS = 472,                 /* TWODOTS  */
    TYPE = 473,                    /* TYPE  */
    UNKLINE = 474,                 /* UNKLINE  */
    USE_LOGGING = 475,             /* USE_LOGGING  */
    USER = 476,                    /* USER  */
    VHOST = 477,                   /* VHOST  */
    VHOST6 = 478,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 479,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 480,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 481,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 482,                   /* XLINE  */
    XLINE_EXEMPT = 483,            /* XLINE_EXEMPT  */
    QSTRING = 484,                 /* QSTRING  */
    NUMBER = 485                   /* NUMBER  */
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
#define CLOAK_ENABLED 276
#define CLOAK_CIDR_LEN_IPV4 277
#define CLOAK_CIDR_LEN_IPV6 278
#define CLOAK_NUM_BITS 279
#define CLOAK_SECRET 280
#define CLOAK_SUFFIX 281
#define CLOSE 282
#define CONNECT 283
#define CONNECTFREQ 284
#define CORE 285
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
#define DISABLE_DNS 296
#define DISABLE_IDENT 297
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
#define IDENT_TIMEOUT 326
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
#define MAX_AWAY_LENGTH 352
#define MAX_BANS 353
#define MAX_BANS_LARGE 354
#define MAX_CHANNELS 355
#define MAX_IDLE 356
#define MAX_INVITES 357
#define MAX_KICK_LENGTH 358
#define MAX_MONITOR 359
#define MAX_NICK_CHANGES 360
#define MAX_NICK_LENGTH 361
#define MAX_NICK_TIME 362
#define MAX_NUMBER 363
#define MAX_TARGETS 364
#define MAX_TOPIC_LENGTH 365
#define MESSAGE 366
#define MIN_IDLE 367
#define MIN_NONWILDCARD 368
#define MIN_NONWILDCARD_SIMPLE 369
#define MODULE 370
#define MODULE_BASE_PATH 371
#define MOTD 372
#define MOTD_FILE 373
#define NAME 374
#define NEED_IDENT 375
#define NEED_PASSWORD 376
#define NETWORK_DESCRIPTION 377
#define NETWORK_NAME 378
#define NICK 379
#define NO_OPER_FLOOD 380
#define NO_TILDE 381
#define NUMBER_PER_CIDR 382
#define NUMBER_PER_IP_GLOBAL 383
#define NUMBER_PER_IP_LOCAL 384
#define OPER_UMODES 385
#define OPERATOR 386
#define OPERS_BYPASS_CALLERID 387
#define PACE_WAIT 388
#define PACE_WAIT_SIMPLE 389
#define PASSWORD 390
#define PATH 391
#define PING_COOKIE 392
#define PING_TIME 393
#define PORT 394
#define RANDOM_IDLE 395
#define REASON 396
#define REDIRPORT 397
#define REDIRSERV 398
#define REHASH 399
#define REMOTE 400
#define REMOTEBAN 401
#define RESIDENT 402
#define RESV 403
#define RESV_EXEMPT 404
#define RSA_PRIVATE_KEY_FILE 405
#define SECONDS 406
#define MINUTES 407
#define HOURS 408
#define DAYS 409
#define WEEKS 410
#define MONTHS 411
#define YEARS 412
#define SEND_PASSWORD 413
#define SENDQ 414
#define SERVERHIDE 415
#define SERVERINFO 416
#define SHORT_MOTD 417
#define SPECIALS_IN_IDENT 418
#define SPOOF 419
#define SQUIT 420
#define STATS_E_DISABLED 421
#define STATS_I_OPER_ONLY 422
#define STATS_K_OPER_ONLY 423
#define STATS_M_OPER_ONLY 424
#define STATS_O_OPER_ONLY 425
#define STATS_P_OPER_ONLY 426
#define STATS_U_OPER_ONLY 427
#define T_ALL 428
#define T_BIND 429
#define T_COMMAND 430
#define T_CLUSTER 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_FILE 434
#define T_GLOBOPS 435
#define T_IPV4 436
#define T_IPV6 437
#define T_LOCOPS 438
#define T_LOG 439
#define T_OPME 440
#define T_PREPEND 441
#define T_PSEUDO 442
#define T_RECVQ 443
#define T_RESTART 444
#define T_SERVER 445
#define T_SERVICE 446
#define T_SET 447
#define T_SHARED 448
#define T_SIZE 449
#define T_TARGET 450
#define T_TLS 451
#define T_UMODES 452
#define T_UNDLINE 453
#define T_UNLIMITED 454
#define T_UNRESV 455
#define T_UNXLINE 456
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
#line 141 "conf_parser.y"

  int number;
  char *string;

#line 532 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
