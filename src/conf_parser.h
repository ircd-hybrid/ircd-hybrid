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
    FAILED_OPER_NOTICE = 308,      /* FAILED_OPER_NOTICE  */
    FLATTEN_LINKS = 309,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 310,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 311,      /* FLATTEN_LINKS_FILE  */
    GECOS = 312,                   /* GECOS  */
    GENERAL = 313,                 /* GENERAL  */
    HIDDEN = 314,                  /* HIDDEN  */
    HIDDEN_NAME = 315,             /* HIDDEN_NAME  */
    HIDE_CHANS = 316,              /* HIDE_CHANS  */
    HIDE_IDLE = 317,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 318,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVER_IPS = 319,         /* HIDE_SERVER_IPS  */
    HIDE_SERVERS = 320,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 321,           /* HIDE_SERVICES  */
    HOST = 322,                    /* HOST  */
    HUB = 323,                     /* HUB  */
    HUB_MASK = 324,                /* HUB_MASK  */
    INVISIBLE_ON_CONNECT = 325,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 326,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 327,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 328,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 329,      /* INVITE_EXPIRE_TIME  */
    IP = 330,                      /* IP  */
    IRCD_AUTH = 331,               /* IRCD_AUTH  */
    IRCD_FLAGS = 332,              /* IRCD_FLAGS  */
    IRCD_SID = 333,                /* IRCD_SID  */
    JOIN = 334,                    /* JOIN  */
    KILL = 335,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 336,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 337,                   /* KLINE  */
    KLINE_EXEMPT = 338,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 339,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 340,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 341,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 342,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 343,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 344,               /* LEAF_MASK  */
    LISTEN = 345,                  /* LISTEN  */
    LOADMODULE = 346,              /* LOADMODULE  */
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
    MODULE_BASE_PATH = 367,        /* MODULE_BASE_PATH  */
    MOTD = 368,                    /* MOTD  */
    MOTD_FILE = 369,               /* MOTD_FILE  */
    NAME = 370,                    /* NAME  */
    NEED_IDENT = 371,              /* NEED_IDENT  */
    NEED_PASSWORD = 372,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 373,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 374,            /* NETWORK_NAME  */
    NICK = 375,                    /* NICK  */
    NO_OPER_FLOOD = 376,           /* NO_OPER_FLOOD  */
    NO_TILDE = 377,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 378,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 379,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 380,     /* NUMBER_PER_IP_LOCAL  */
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
    RESIDENT = 398,                /* RESIDENT  */
    RESV = 399,                    /* RESV  */
    RESV_EXEMPT = 400,             /* RESV_EXEMPT  */
    RSA_PRIVATE_KEY_FILE = 401,    /* RSA_PRIVATE_KEY_FILE  */
    SECONDS = 402,                 /* SECONDS  */
    MINUTES = 403,                 /* MINUTES  */
    HOURS = 404,                   /* HOURS  */
    DAYS = 405,                    /* DAYS  */
    WEEKS = 406,                   /* WEEKS  */
    MONTHS = 407,                  /* MONTHS  */
    YEARS = 408,                   /* YEARS  */
    SEND_PASSWORD = 409,           /* SEND_PASSWORD  */
    SENDQ = 410,                   /* SENDQ  */
    SERVERHIDE = 411,              /* SERVERHIDE  */
    SERVERINFO = 412,              /* SERVERINFO  */
    SHORT_MOTD = 413,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 414,       /* SPECIALS_IN_IDENT  */
    SPOOF = 415,                   /* SPOOF  */
    SQUIT = 416,                   /* SQUIT  */
    STATS_E_DISABLED = 417,        /* STATS_E_DISABLED  */
    STATS_I_OPER_ONLY = 418,       /* STATS_I_OPER_ONLY  */
    STATS_K_OPER_ONLY = 419,       /* STATS_K_OPER_ONLY  */
    STATS_M_OPER_ONLY = 420,       /* STATS_M_OPER_ONLY  */
    STATS_O_OPER_ONLY = 421,       /* STATS_O_OPER_ONLY  */
    STATS_P_OPER_ONLY = 422,       /* STATS_P_OPER_ONLY  */
    STATS_U_OPER_ONLY = 423,       /* STATS_U_OPER_ONLY  */
    T_ALL = 424,                   /* T_ALL  */
    T_BIND = 425,                  /* T_BIND  */
    T_COMMAND = 426,               /* T_COMMAND  */
    T_CLUSTER = 427,               /* T_CLUSTER  */
    T_DEBUG = 428,                 /* T_DEBUG  */
    T_DLINE = 429,                 /* T_DLINE  */
    T_FILE = 430,                  /* T_FILE  */
    T_GLOBOPS = 431,               /* T_GLOBOPS  */
    T_IPV4 = 432,                  /* T_IPV4  */
    T_IPV6 = 433,                  /* T_IPV6  */
    T_LOCOPS = 434,                /* T_LOCOPS  */
    T_LOG = 435,                   /* T_LOG  */
    T_OPME = 436,                  /* T_OPME  */
    T_PREPEND = 437,               /* T_PREPEND  */
    T_PSEUDO = 438,                /* T_PSEUDO  */
    T_RECVQ = 439,                 /* T_RECVQ  */
    T_RESTART = 440,               /* T_RESTART  */
    T_SERVER = 441,                /* T_SERVER  */
    T_SERVICE = 442,               /* T_SERVICE  */
    T_SET = 443,                   /* T_SET  */
    T_SHARED = 444,                /* T_SHARED  */
    T_SIZE = 445,                  /* T_SIZE  */
    T_TARGET = 446,                /* T_TARGET  */
    T_TLS = 447,                   /* T_TLS  */
    T_UMODES = 448,                /* T_UMODES  */
    T_UNDLINE = 449,               /* T_UNDLINE  */
    T_UNLIMITED = 450,             /* T_UNLIMITED  */
    T_UNRESV = 451,                /* T_UNRESV  */
    T_UNXLINE = 452,               /* T_UNXLINE  */
    T_WEBIRC = 453,                /* T_WEBIRC  */
    TBOOL = 454,                   /* TBOOL  */
    THROTTLE_COUNT = 455,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 456,           /* THROTTLE_TIME  */
    TIMEOUT = 457,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 458,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 459, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_CIPHER_LIST = 460,         /* TLS_CIPHER_LIST  */
    TLS_CIPHER_SUITES = 461,       /* TLS_CIPHER_SUITES  */
    TLS_CONNECTION_REQUIRED = 462, /* TLS_CONNECTION_REQUIRED  */
    TLS_DH_PARAM_FILE = 463,       /* TLS_DH_PARAM_FILE  */
    TLS_MESSAGE_DIGEST_ALGORITHM = 464, /* TLS_MESSAGE_DIGEST_ALGORITHM  */
    TLS_SUPPORTED_GROUPS = 465,    /* TLS_SUPPORTED_GROUPS  */
    TS_MAX_DELTA = 466,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 467,           /* TS_WARN_DELTA  */
    TWODOTS = 468,                 /* TWODOTS  */
    TYPE = 469,                    /* TYPE  */
    UNKLINE = 470,                 /* UNKLINE  */
    USE_LOGGING = 471,             /* USE_LOGGING  */
    USER = 472,                    /* USER  */
    VHOST = 473,                   /* VHOST  */
    VHOST6 = 474,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 475,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 476,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 477,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 478,                   /* XLINE  */
    XLINE_EXEMPT = 479,            /* XLINE_EXEMPT  */
    QSTRING = 480,                 /* QSTRING  */
    NUMBER = 481                   /* NUMBER  */
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
#define FAILED_OPER_NOTICE 308
#define FLATTEN_LINKS 309
#define FLATTEN_LINKS_DELAY 310
#define FLATTEN_LINKS_FILE 311
#define GECOS 312
#define GENERAL 313
#define HIDDEN 314
#define HIDDEN_NAME 315
#define HIDE_CHANS 316
#define HIDE_IDLE 317
#define HIDE_IDLE_FROM_OPERS 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SERVICES 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define INVISIBLE_ON_CONNECT 325
#define INVITE_CLIENT_COUNT 326
#define INVITE_CLIENT_TIME 327
#define INVITE_DELAY_CHANNEL 328
#define INVITE_EXPIRE_TIME 329
#define IP 330
#define IRCD_AUTH 331
#define IRCD_FLAGS 332
#define IRCD_SID 333
#define JOIN 334
#define KILL 335
#define KILL_CHASE_TIME_LIMIT 336
#define KLINE 337
#define KLINE_EXEMPT 338
#define KLINE_MIN_CIDR 339
#define KLINE_MIN_CIDR6 340
#define KNOCK_CLIENT_COUNT 341
#define KNOCK_CLIENT_TIME 342
#define KNOCK_DELAY_CHANNEL 343
#define LEAF_MASK 344
#define LISTEN 345
#define LOADMODULE 346
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
#define MODULE_BASE_PATH 367
#define MOTD 368
#define MOTD_FILE 369
#define NAME 370
#define NEED_IDENT 371
#define NEED_PASSWORD 372
#define NETWORK_DESCRIPTION 373
#define NETWORK_NAME 374
#define NICK 375
#define NO_OPER_FLOOD 376
#define NO_TILDE 377
#define NUMBER_PER_CIDR 378
#define NUMBER_PER_IP_GLOBAL 379
#define NUMBER_PER_IP_LOCAL 380
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
#define RESIDENT 398
#define RESV 399
#define RESV_EXEMPT 400
#define RSA_PRIVATE_KEY_FILE 401
#define SECONDS 402
#define MINUTES 403
#define HOURS 404
#define DAYS 405
#define WEEKS 406
#define MONTHS 407
#define YEARS 408
#define SEND_PASSWORD 409
#define SENDQ 410
#define SERVERHIDE 411
#define SERVERINFO 412
#define SHORT_MOTD 413
#define SPECIALS_IN_IDENT 414
#define SPOOF 415
#define SQUIT 416
#define STATS_E_DISABLED 417
#define STATS_I_OPER_ONLY 418
#define STATS_K_OPER_ONLY 419
#define STATS_M_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define STATS_U_OPER_ONLY 423
#define T_ALL 424
#define T_BIND 425
#define T_COMMAND 426
#define T_CLUSTER 427
#define T_DEBUG 428
#define T_DLINE 429
#define T_FILE 430
#define T_GLOBOPS 431
#define T_IPV4 432
#define T_IPV6 433
#define T_LOCOPS 434
#define T_LOG 435
#define T_OPME 436
#define T_PREPEND 437
#define T_PSEUDO 438
#define T_RECVQ 439
#define T_RESTART 440
#define T_SERVER 441
#define T_SERVICE 442
#define T_SET 443
#define T_SHARED 444
#define T_SIZE 445
#define T_TARGET 446
#define T_TLS 447
#define T_UMODES 448
#define T_UNDLINE 449
#define T_UNLIMITED 450
#define T_UNRESV 451
#define T_UNXLINE 452
#define T_WEBIRC 453
#define TBOOL 454
#define THROTTLE_COUNT 455
#define THROTTLE_TIME 456
#define TIMEOUT 457
#define TLS_CERTIFICATE_FILE 458
#define TLS_CERTIFICATE_FINGERPRINT 459
#define TLS_CIPHER_LIST 460
#define TLS_CIPHER_SUITES 461
#define TLS_CONNECTION_REQUIRED 462
#define TLS_DH_PARAM_FILE 463
#define TLS_MESSAGE_DIGEST_ALGORITHM 464
#define TLS_SUPPORTED_GROUPS 465
#define TS_MAX_DELTA 466
#define TS_WARN_DELTA 467
#define TWODOTS 468
#define TYPE 469
#define UNKLINE 470
#define USE_LOGGING 471
#define USER 472
#define VHOST 473
#define VHOST6 474
#define WARN_NO_CONNECT_BLOCK 475
#define WHOIS 476
#define WHOWAS_HISTORY_LENGTH 477
#define XLINE 478
#define XLINE_EXEMPT 479
#define QSTRING 480
#define NUMBER 481

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 135 "conf_parser.y"

  int number;
  char *string;

#line 524 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
