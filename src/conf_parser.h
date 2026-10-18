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
    CYCLE_ON_HOST_CHANGE = 285,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 286,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 287,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 288, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 289, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 290,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 291,                   /* DEFER  */
    DENY = 292,                    /* DENY  */
    DESCRIPTION = 293,             /* DESCRIPTION  */
    DIE = 294,                     /* DIE  */
    DISABLE_DNS = 295,             /* DISABLE_DNS  */
    DISABLE_IDENT = 296,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 297,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 298, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 299,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 300,         /* DLINE_MIN_CIDR6  */
    EMAIL = 301,                   /* EMAIL  */
    ENCRYPTED = 302,               /* ENCRYPTED  */
    EXCEED_LIMIT = 303,            /* EXCEED_LIMIT  */
    EXEMPT = 304,                  /* EXEMPT  */
    FLATTEN_LINKS = 305,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 306,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 307,      /* FLATTEN_LINKS_FILE  */
    GECOS = 308,                   /* GECOS  */
    GENERAL = 309,                 /* GENERAL  */
    HIDDEN = 310,                  /* HIDDEN  */
    HIDDEN_NAME = 311,             /* HIDDEN_NAME  */
    HIDE_CHANS = 312,              /* HIDE_CHANS  */
    HIDE_IDLE = 313,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 314,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 315,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 316,           /* HIDE_SERVICES  */
    HOST = 317,                    /* HOST  */
    HUB = 318,                     /* HUB  */
    HUB_MASK = 319,                /* HUB_MASK  */
    IDENT_TIMEOUT = 320,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 321,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 322,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 323,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 324,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 325,      /* INVITE_EXPIRE_TIME  */
    IP = 326,                      /* IP  */
    IRCD_AUTH = 327,               /* IRCD_AUTH  */
    IRCD_FLAGS = 328,              /* IRCD_FLAGS  */
    IRCD_SID = 329,                /* IRCD_SID  */
    JOIN = 330,                    /* JOIN  */
    KILL = 331,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 332,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 333,                   /* KLINE  */
    KLINE_EXEMPT = 334,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 335,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 336,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 337,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 338,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 339,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 340,               /* LEAF_MASK  */
    LISTEN = 341,                  /* LISTEN  */
    LOADMODULE = 342,              /* LOADMODULE  */
    MASK = 343,                    /* MASK  */
    MASS = 344,                    /* MASS  */
    MAX_ACCEPT = 345,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 346,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 347,                /* MAX_BANS  */
    MAX_BANS_LARGE = 348,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 349,            /* MAX_CHANNELS  */
    MAX_IDLE = 350,                /* MAX_IDLE  */
    MAX_INVITES = 351,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 352,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 353,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 354,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 355,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 356,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 357,              /* MAX_NUMBER  */
    MAX_TARGETS = 358,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 359,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 360,                 /* MESSAGE  */
    MIN_IDLE = 361,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 362,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 363,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 364,                  /* MODULE  */
    MODULE_BASE_PATH = 365,        /* MODULE_BASE_PATH  */
    MOTD = 366,                    /* MOTD  */
    MOTD_FILE = 367,               /* MOTD_FILE  */
    NAME = 368,                    /* NAME  */
    NEED_IDENT = 369,              /* NEED_IDENT  */
    NEED_PASSWORD = 370,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 371,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 372,            /* NETWORK_NAME  */
    NICK = 373,                    /* NICK  */
    NO_OPER_FLOOD = 374,           /* NO_OPER_FLOOD  */
    NO_TILDE = 375,                /* NO_TILDE  */
    NUMBER_PER_CIDR = 376,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 377,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 378,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 379,             /* OPER_UMODES  */
    OPERATOR = 380,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 381,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 382,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 383,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 384,                /* PASSWORD  */
    PATH = 385,                    /* PATH  */
    PING_COOKIE = 386,             /* PING_COOKIE  */
    PING_TIME = 387,               /* PING_TIME  */
    PORT = 388,                    /* PORT  */
    RANDOM_IDLE = 389,             /* RANDOM_IDLE  */
    REASON = 390,                  /* REASON  */
    REGISTRATION_TIMEOUT = 391,    /* REGISTRATION_TIMEOUT  */
    REHASH = 392,                  /* REHASH  */
    REMOTE = 393,                  /* REMOTE  */
    REMOTEBAN = 394,               /* REMOTEBAN  */
    REQUIRED = 395,                /* REQUIRED  */
    RESIDENT = 396,                /* RESIDENT  */
    RESV = 397,                    /* RESV  */
    RESV_EXEMPT = 398,             /* RESV_EXEMPT  */
    SECONDS = 399,                 /* SECONDS  */
    MINUTES = 400,                 /* MINUTES  */
    HOURS = 401,                   /* HOURS  */
    DAYS = 402,                    /* DAYS  */
    WEEKS = 403,                   /* WEEKS  */
    MONTHS = 404,                  /* MONTHS  */
    YEARS = 405,                   /* YEARS  */
    SEND_PASSWORD = 406,           /* SEND_PASSWORD  */
    SENDQ = 407,                   /* SENDQ  */
    SERVERHIDE = 408,              /* SERVERHIDE  */
    SERVERINFO = 409,              /* SERVERINFO  */
    SHORT_MOTD = 410,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 411,       /* SPECIALS_IN_IDENT  */
    SPOOF = 412,                   /* SPOOF  */
    SQUIT = 413,                   /* SQUIT  */
    STATS_E_DISABLED = 414,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 415,       /* STATS_U_OPER_ONLY  */
    T_ALL = 416,                   /* T_ALL  */
    T_BIND = 417,                  /* T_BIND  */
    T_COMMAND = 418,               /* T_COMMAND  */
    T_CLUSTER = 419,               /* T_CLUSTER  */
    T_DEBUG = 420,                 /* T_DEBUG  */
    T_DLINE = 421,                 /* T_DLINE  */
    T_FILE = 422,                  /* T_FILE  */
    T_GLOBOPS = 423,               /* T_GLOBOPS  */
    T_IPV4 = 424,                  /* T_IPV4  */
    T_IPV6 = 425,                  /* T_IPV6  */
    T_LOCOPS = 426,                /* T_LOCOPS  */
    T_LOG = 427,                   /* T_LOG  */
    T_OPME = 428,                  /* T_OPME  */
    T_PREPEND = 429,               /* T_PREPEND  */
    T_PSEUDO = 430,                /* T_PSEUDO  */
    T_RECVQ = 431,                 /* T_RECVQ  */
    T_RESTART = 432,               /* T_RESTART  */
    T_SERVER = 433,                /* T_SERVER  */
    T_SERVICE = 434,               /* T_SERVICE  */
    T_SET = 435,                   /* T_SET  */
    T_SHARED = 436,                /* T_SHARED  */
    T_SIZE = 437,                  /* T_SIZE  */
    T_TARGET = 438,                /* T_TARGET  */
    T_TLS = 439,                   /* T_TLS  */
    T_UMODES = 440,                /* T_UMODES  */
    T_UNDLINE = 441,               /* T_UNDLINE  */
    T_UNLIMITED = 442,             /* T_UNLIMITED  */
    T_UNRESV = 443,                /* T_UNRESV  */
    T_UNXLINE = 444,               /* T_UNXLINE  */
    T_WEBIRC = 445,                /* T_WEBIRC  */
    TBOOL = 446,                   /* TBOOL  */
    THROTTLE_COUNT = 447,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 448,           /* THROTTLE_TIME  */
    TIMEOUT = 449,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 450,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 451, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 452,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 453, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 454,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 455,           /* TS_WARN_DELTA  */
    TWODOTS = 456,                 /* TWODOTS  */
    TYPE = 457,                    /* TYPE  */
    UNKLINE = 458,                 /* UNKLINE  */
    USE_LOGGING = 459,             /* USE_LOGGING  */
    USER = 460,                    /* USER  */
    VHOST = 461,                   /* VHOST  */
    VHOST6 = 462,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 463,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 464,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 465,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 466,                   /* XLINE  */
    XLINE_EXEMPT = 467,            /* XLINE_EXEMPT  */
    QSTRING = 468,                 /* QSTRING  */
    NUMBER = 469                   /* NUMBER  */
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
#define CYCLE_ON_HOST_CHANGE 285
#define DEFAULT_FLOODCOUNT 286
#define DEFAULT_FLOODTIME 287
#define DEFAULT_JOIN_FLOOD_COUNT 288
#define DEFAULT_JOIN_FLOOD_TIME 289
#define DEFAULT_MAX_CLIENTS 290
#define DEFER 291
#define DENY 292
#define DESCRIPTION 293
#define DIE 294
#define DISABLE_DNS 295
#define DISABLE_IDENT 296
#define DISABLE_FAKE_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DLINE_MIN_CIDR 299
#define DLINE_MIN_CIDR6 300
#define EMAIL 301
#define ENCRYPTED 302
#define EXCEED_LIMIT 303
#define EXEMPT 304
#define FLATTEN_LINKS 305
#define FLATTEN_LINKS_DELAY 306
#define FLATTEN_LINKS_FILE 307
#define GECOS 308
#define GENERAL 309
#define HIDDEN 310
#define HIDDEN_NAME 311
#define HIDE_CHANS 312
#define HIDE_IDLE 313
#define HIDE_IDLE_FROM_OPERS 314
#define HIDE_SERVERS 315
#define HIDE_SERVICES 316
#define HOST 317
#define HUB 318
#define HUB_MASK 319
#define IDENT_TIMEOUT 320
#define INVISIBLE_ON_CONNECT 321
#define INVITE_CLIENT_COUNT 322
#define INVITE_CLIENT_TIME 323
#define INVITE_DELAY_CHANNEL 324
#define INVITE_EXPIRE_TIME 325
#define IP 326
#define IRCD_AUTH 327
#define IRCD_FLAGS 328
#define IRCD_SID 329
#define JOIN 330
#define KILL 331
#define KILL_CHASE_TIME_LIMIT 332
#define KLINE 333
#define KLINE_EXEMPT 334
#define KLINE_MIN_CIDR 335
#define KLINE_MIN_CIDR6 336
#define KNOCK_CLIENT_COUNT 337
#define KNOCK_CLIENT_TIME 338
#define KNOCK_DELAY_CHANNEL 339
#define LEAF_MASK 340
#define LISTEN 341
#define LOADMODULE 342
#define MASK 343
#define MASS 344
#define MAX_ACCEPT 345
#define MAX_AWAY_LENGTH 346
#define MAX_BANS 347
#define MAX_BANS_LARGE 348
#define MAX_CHANNELS 349
#define MAX_IDLE 350
#define MAX_INVITES 351
#define MAX_KICK_LENGTH 352
#define MAX_MONITOR 353
#define MAX_NICK_CHANGES 354
#define MAX_NICK_LENGTH 355
#define MAX_NICK_TIME 356
#define MAX_NUMBER 357
#define MAX_TARGETS 358
#define MAX_TOPIC_LENGTH 359
#define MESSAGE 360
#define MIN_IDLE 361
#define MIN_NONWILDCARD 362
#define MIN_NONWILDCARD_SIMPLE 363
#define MODULE 364
#define MODULE_BASE_PATH 365
#define MOTD 366
#define MOTD_FILE 367
#define NAME 368
#define NEED_IDENT 369
#define NEED_PASSWORD 370
#define NETWORK_DESCRIPTION 371
#define NETWORK_NAME 372
#define NICK 373
#define NO_OPER_FLOOD 374
#define NO_TILDE 375
#define NUMBER_PER_CIDR 376
#define NUMBER_PER_IP_GLOBAL 377
#define NUMBER_PER_IP_LOCAL 378
#define OPER_UMODES 379
#define OPERATOR 380
#define OPERS_BYPASS_CALLERID 381
#define PACE_WAIT 382
#define PACE_WAIT_SIMPLE 383
#define PASSWORD 384
#define PATH 385
#define PING_COOKIE 386
#define PING_TIME 387
#define PORT 388
#define RANDOM_IDLE 389
#define REASON 390
#define REGISTRATION_TIMEOUT 391
#define REHASH 392
#define REMOTE 393
#define REMOTEBAN 394
#define REQUIRED 395
#define RESIDENT 396
#define RESV 397
#define RESV_EXEMPT 398
#define SECONDS 399
#define MINUTES 400
#define HOURS 401
#define DAYS 402
#define WEEKS 403
#define MONTHS 404
#define YEARS 405
#define SEND_PASSWORD 406
#define SENDQ 407
#define SERVERHIDE 408
#define SERVERINFO 409
#define SHORT_MOTD 410
#define SPECIALS_IN_IDENT 411
#define SPOOF 412
#define SQUIT 413
#define STATS_E_DISABLED 414
#define STATS_U_OPER_ONLY 415
#define T_ALL 416
#define T_BIND 417
#define T_COMMAND 418
#define T_CLUSTER 419
#define T_DEBUG 420
#define T_DLINE 421
#define T_FILE 422
#define T_GLOBOPS 423
#define T_IPV4 424
#define T_IPV6 425
#define T_LOCOPS 426
#define T_LOG 427
#define T_OPME 428
#define T_PREPEND 429
#define T_PSEUDO 430
#define T_RECVQ 431
#define T_RESTART 432
#define T_SERVER 433
#define T_SERVICE 434
#define T_SET 435
#define T_SHARED 436
#define T_SIZE 437
#define T_TARGET 438
#define T_TLS 439
#define T_UMODES 440
#define T_UNDLINE 441
#define T_UNLIMITED 442
#define T_UNRESV 443
#define T_UNXLINE 444
#define T_WEBIRC 445
#define TBOOL 446
#define THROTTLE_COUNT 447
#define THROTTLE_TIME 448
#define TIMEOUT 449
#define TLS_CERTIFICATE_FILE 450
#define TLS_CERTIFICATE_FINGERPRINT 451
#define TLS_PRIVATE_KEY_FILE 452
#define TLS_CONNECTION_REQUIRED 453
#define TS_MAX_DELTA 454
#define TS_WARN_DELTA 455
#define TWODOTS 456
#define TYPE 457
#define UNKLINE 458
#define USE_LOGGING 459
#define USER 460
#define VHOST 461
#define VHOST6 462
#define WARN_NO_CONNECT_BLOCK 463
#define WHOIS 464
#define WHOWAS_HISTORY_LENGTH 465
#define XLINE 466
#define XLINE_EXEMPT 467
#define QSTRING 468
#define NUMBER 469

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 500 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
