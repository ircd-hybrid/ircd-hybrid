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
    CIDR_LEN_IPV4 = 274,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 275,           /* CIDR_LEN_IPV6  */
    CLASS = 276,                   /* CLASS  */
    CLIENT = 277,                  /* CLIENT  */
    CLOAK = 278,                   /* CLOAK  */
    CLOSE = 279,                   /* CLOSE  */
    CONNECT = 280,                 /* CONNECT  */
    CONNECTFREQ = 281,             /* CONNECTFREQ  */
    CYCLE_ON_HOST_CHANGE = 282,    /* CYCLE_ON_HOST_CHANGE  */
    DEFAULT_FLOODCOUNT = 283,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 284,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 285, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 286, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 287,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 288,                   /* DEFER  */
    DENY = 289,                    /* DENY  */
    DESCRIPTION = 290,             /* DESCRIPTION  */
    DIE = 291,                     /* DIE  */
    DISABLE_DNS = 292,             /* DISABLE_DNS  */
    DISABLE_IDENT = 293,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 294,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 295, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 296,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 297,         /* DLINE_MIN_CIDR6  */
    EMAIL = 298,                   /* EMAIL  */
    ENABLED = 299,                 /* ENABLED  */
    ENCRYPTED = 300,               /* ENCRYPTED  */
    EXCEED_LIMIT = 301,            /* EXCEED_LIMIT  */
    EXEMPT = 302,                  /* EXEMPT  */
    FLATTEN_LINKS = 303,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 304,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 305,      /* FLATTEN_LINKS_FILE  */
    GECOS = 306,                   /* GECOS  */
    GENERAL = 307,                 /* GENERAL  */
    HIDDEN = 308,                  /* HIDDEN  */
    HIDDEN_NAME = 309,             /* HIDDEN_NAME  */
    HIDE_CHANS = 310,              /* HIDE_CHANS  */
    HIDE_IDLE = 311,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 312,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 313,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 314,           /* HIDE_SERVICES  */
    HOST = 315,                    /* HOST  */
    HUB = 316,                     /* HUB  */
    HUB_MASK = 317,                /* HUB_MASK  */
    IDENT_TIMEOUT = 318,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 319,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 320,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 321,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 322,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 323,      /* INVITE_EXPIRE_TIME  */
    IP = 324,                      /* IP  */
    IRCD_AUTH = 325,               /* IRCD_AUTH  */
    IRCD_FLAGS = 326,              /* IRCD_FLAGS  */
    IRCD_SID = 327,                /* IRCD_SID  */
    JOIN = 328,                    /* JOIN  */
    KILL = 329,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 330,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 331,                   /* KLINE  */
    KLINE_EXEMPT = 332,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 333,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 334,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 335,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 336,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 337,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 338,               /* LEAF_MASK  */
    LISTEN = 339,                  /* LISTEN  */
    LOADMODULE = 340,              /* LOADMODULE  */
    MASK = 341,                    /* MASK  */
    MASS = 342,                    /* MASS  */
    MAX_ACCEPT = 343,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 344,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 345,                /* MAX_BANS  */
    MAX_BANS_LARGE = 346,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 347,            /* MAX_CHANNELS  */
    MAX_IDLE = 348,                /* MAX_IDLE  */
    MAX_INVITES = 349,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 350,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 351,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 352,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 353,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 354,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 355,              /* MAX_NUMBER  */
    MAX_TARGETS = 356,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 357,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 358,                 /* MESSAGE  */
    MIN_IDLE = 359,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 360,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 361,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 362,                  /* MODULE  */
    MODULE_BASE_PATH = 363,        /* MODULE_BASE_PATH  */
    MOTD = 364,                    /* MOTD  */
    MOTD_FILE = 365,               /* MOTD_FILE  */
    NAME = 366,                    /* NAME  */
    NEED_IDENT = 367,              /* NEED_IDENT  */
    NEED_PASSWORD = 368,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 369,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 370,            /* NETWORK_NAME  */
    NICK = 371,                    /* NICK  */
    NO_OPER_FLOOD = 372,           /* NO_OPER_FLOOD  */
    NO_TILDE = 373,                /* NO_TILDE  */
    NUM_BITS = 374,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 375,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 376,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 377,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 378,             /* OPER_UMODES  */
    OPERATOR = 379,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 380,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 381,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 382,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 383,                /* PASSWORD  */
    PATH = 384,                    /* PATH  */
    PING_COOKIE = 385,             /* PING_COOKIE  */
    PING_TIME = 386,               /* PING_TIME  */
    PORT = 387,                    /* PORT  */
    RANDOM_IDLE = 388,             /* RANDOM_IDLE  */
    REASON = 389,                  /* REASON  */
    REGISTRATION_TIMEOUT = 390,    /* REGISTRATION_TIMEOUT  */
    REHASH = 391,                  /* REHASH  */
    REMOTE = 392,                  /* REMOTE  */
    REMOTEBAN = 393,               /* REMOTEBAN  */
    REQUIRED = 394,                /* REQUIRED  */
    RESIDENT = 395,                /* RESIDENT  */
    RESV = 396,                    /* RESV  */
    RESV_EXEMPT = 397,             /* RESV_EXEMPT  */
    SECRET = 398,                  /* SECRET  */
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
    SUFFIX = 416,                  /* SUFFIX  */
    T_ALL = 417,                   /* T_ALL  */
    T_BIND = 418,                  /* T_BIND  */
    T_COMMAND = 419,               /* T_COMMAND  */
    T_CLUSTER = 420,               /* T_CLUSTER  */
    T_DEBUG = 421,                 /* T_DEBUG  */
    T_DLINE = 422,                 /* T_DLINE  */
    T_FILE = 423,                  /* T_FILE  */
    T_GLOBOPS = 424,               /* T_GLOBOPS  */
    T_IPV4 = 425,                  /* T_IPV4  */
    T_IPV6 = 426,                  /* T_IPV6  */
    T_LOCOPS = 427,                /* T_LOCOPS  */
    T_LOG = 428,                   /* T_LOG  */
    T_OPME = 429,                  /* T_OPME  */
    T_PREPEND = 430,               /* T_PREPEND  */
    T_PSEUDO = 431,                /* T_PSEUDO  */
    T_RECVQ = 432,                 /* T_RECVQ  */
    T_RESTART = 433,               /* T_RESTART  */
    T_SERVER = 434,                /* T_SERVER  */
    T_SERVICE = 435,               /* T_SERVICE  */
    T_SET = 436,                   /* T_SET  */
    T_SHARED = 437,                /* T_SHARED  */
    T_SIZE = 438,                  /* T_SIZE  */
    T_TARGET = 439,                /* T_TARGET  */
    T_TLS = 440,                   /* T_TLS  */
    T_UMODES = 441,                /* T_UMODES  */
    T_UNDLINE = 442,               /* T_UNDLINE  */
    T_UNLIMITED = 443,             /* T_UNLIMITED  */
    T_UNRESV = 444,                /* T_UNRESV  */
    T_UNXLINE = 445,               /* T_UNXLINE  */
    T_WEBIRC = 446,                /* T_WEBIRC  */
    TBOOL = 447,                   /* TBOOL  */
    THROTTLE_COUNT = 448,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 449,           /* THROTTLE_TIME  */
    TIMEOUT = 450,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 451,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 452, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 453,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 454, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 455,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 456,           /* TS_WARN_DELTA  */
    TWODOTS = 457,                 /* TWODOTS  */
    TYPE = 458,                    /* TYPE  */
    UNKLINE = 459,                 /* UNKLINE  */
    USE_LOGGING = 460,             /* USE_LOGGING  */
    USER = 461,                    /* USER  */
    VHOST = 462,                   /* VHOST  */
    VHOST6 = 463,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 464,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 465,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 466,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 467,                   /* XLINE  */
    XLINE_EXEMPT = 468,            /* XLINE_EXEMPT  */
    QSTRING = 469,                 /* QSTRING  */
    NUMBER = 470                   /* NUMBER  */
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
#define CIDR_LEN_IPV4 274
#define CIDR_LEN_IPV6 275
#define CLASS 276
#define CLIENT 277
#define CLOAK 278
#define CLOSE 279
#define CONNECT 280
#define CONNECTFREQ 281
#define CYCLE_ON_HOST_CHANGE 282
#define DEFAULT_FLOODCOUNT 283
#define DEFAULT_FLOODTIME 284
#define DEFAULT_JOIN_FLOOD_COUNT 285
#define DEFAULT_JOIN_FLOOD_TIME 286
#define DEFAULT_MAX_CLIENTS 287
#define DEFER 288
#define DENY 289
#define DESCRIPTION 290
#define DIE 291
#define DISABLE_DNS 292
#define DISABLE_IDENT 293
#define DISABLE_FAKE_CHANNELS 294
#define DISABLE_REMOTE_COMMANDS 295
#define DLINE_MIN_CIDR 296
#define DLINE_MIN_CIDR6 297
#define EMAIL 298
#define ENABLED 299
#define ENCRYPTED 300
#define EXCEED_LIMIT 301
#define EXEMPT 302
#define FLATTEN_LINKS 303
#define FLATTEN_LINKS_DELAY 304
#define FLATTEN_LINKS_FILE 305
#define GECOS 306
#define GENERAL 307
#define HIDDEN 308
#define HIDDEN_NAME 309
#define HIDE_CHANS 310
#define HIDE_IDLE 311
#define HIDE_IDLE_FROM_OPERS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define IDENT_TIMEOUT 318
#define INVISIBLE_ON_CONNECT 319
#define INVITE_CLIENT_COUNT 320
#define INVITE_CLIENT_TIME 321
#define INVITE_DELAY_CHANNEL 322
#define INVITE_EXPIRE_TIME 323
#define IP 324
#define IRCD_AUTH 325
#define IRCD_FLAGS 326
#define IRCD_SID 327
#define JOIN 328
#define KILL 329
#define KILL_CHASE_TIME_LIMIT 330
#define KLINE 331
#define KLINE_EXEMPT 332
#define KLINE_MIN_CIDR 333
#define KLINE_MIN_CIDR6 334
#define KNOCK_CLIENT_COUNT 335
#define KNOCK_CLIENT_TIME 336
#define KNOCK_DELAY_CHANNEL 337
#define LEAF_MASK 338
#define LISTEN 339
#define LOADMODULE 340
#define MASK 341
#define MASS 342
#define MAX_ACCEPT 343
#define MAX_AWAY_LENGTH 344
#define MAX_BANS 345
#define MAX_BANS_LARGE 346
#define MAX_CHANNELS 347
#define MAX_IDLE 348
#define MAX_INVITES 349
#define MAX_KICK_LENGTH 350
#define MAX_MONITOR 351
#define MAX_NICK_CHANGES 352
#define MAX_NICK_LENGTH 353
#define MAX_NICK_TIME 354
#define MAX_NUMBER 355
#define MAX_TARGETS 356
#define MAX_TOPIC_LENGTH 357
#define MESSAGE 358
#define MIN_IDLE 359
#define MIN_NONWILDCARD 360
#define MIN_NONWILDCARD_SIMPLE 361
#define MODULE 362
#define MODULE_BASE_PATH 363
#define MOTD 364
#define MOTD_FILE 365
#define NAME 366
#define NEED_IDENT 367
#define NEED_PASSWORD 368
#define NETWORK_DESCRIPTION 369
#define NETWORK_NAME 370
#define NICK 371
#define NO_OPER_FLOOD 372
#define NO_TILDE 373
#define NUM_BITS 374
#define NUMBER_PER_CIDR 375
#define NUMBER_PER_IP_GLOBAL 376
#define NUMBER_PER_IP_LOCAL 377
#define OPER_UMODES 378
#define OPERATOR 379
#define OPERS_BYPASS_CALLERID 380
#define PACE_WAIT 381
#define PACE_WAIT_SIMPLE 382
#define PASSWORD 383
#define PATH 384
#define PING_COOKIE 385
#define PING_TIME 386
#define PORT 387
#define RANDOM_IDLE 388
#define REASON 389
#define REGISTRATION_TIMEOUT 390
#define REHASH 391
#define REMOTE 392
#define REMOTEBAN 393
#define REQUIRED 394
#define RESIDENT 395
#define RESV 396
#define RESV_EXEMPT 397
#define SECRET 398
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
#define SUFFIX 416
#define T_ALL 417
#define T_BIND 418
#define T_COMMAND 419
#define T_CLUSTER 420
#define T_DEBUG 421
#define T_DLINE 422
#define T_FILE 423
#define T_GLOBOPS 424
#define T_IPV4 425
#define T_IPV6 426
#define T_LOCOPS 427
#define T_LOG 428
#define T_OPME 429
#define T_PREPEND 430
#define T_PSEUDO 431
#define T_RECVQ 432
#define T_RESTART 433
#define T_SERVER 434
#define T_SERVICE 435
#define T_SET 436
#define T_SHARED 437
#define T_SIZE 438
#define T_TARGET 439
#define T_TLS 440
#define T_UMODES 441
#define T_UNDLINE 442
#define T_UNLIMITED 443
#define T_UNRESV 444
#define T_UNXLINE 445
#define T_WEBIRC 446
#define TBOOL 447
#define THROTTLE_COUNT 448
#define THROTTLE_TIME 449
#define TIMEOUT 450
#define TLS_CERTIFICATE_FILE 451
#define TLS_CERTIFICATE_FINGERPRINT 452
#define TLS_PRIVATE_KEY_FILE 453
#define TLS_CONNECTION_REQUIRED 454
#define TS_MAX_DELTA 455
#define TS_WARN_DELTA 456
#define TWODOTS 457
#define TYPE 458
#define UNKLINE 459
#define USE_LOGGING 460
#define USER 461
#define VHOST 462
#define VHOST6 463
#define WARN_NO_CONNECT_BLOCK 464
#define WHOIS 465
#define WHOWAS_HISTORY_LENGTH 466
#define XLINE 467
#define XLINE_EXEMPT 468
#define QSTRING 469
#define NUMBER 470

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 133 "conf_parser.y"

  int number;
  char *string;

#line 502 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
