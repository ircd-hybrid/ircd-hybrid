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
    DEFAULT_FLOODCOUNT = 282,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 283,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 284, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 285, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 286,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 287,                   /* DEFER  */
    DENY = 288,                    /* DENY  */
    DESCRIPTION = 289,             /* DESCRIPTION  */
    DIE = 290,                     /* DIE  */
    DISABLE_DNS = 291,             /* DISABLE_DNS  */
    DISABLE_IDENT = 292,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 293,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 294, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 295,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 296,         /* DLINE_MIN_CIDR6  */
    EMAIL = 297,                   /* EMAIL  */
    ENABLED = 298,                 /* ENABLED  */
    ENCRYPTED = 299,               /* ENCRYPTED  */
    EXCEED_LIMIT = 300,            /* EXCEED_LIMIT  */
    EXEMPT = 301,                  /* EXEMPT  */
    FLATTEN_LINKS = 302,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 303,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 304,      /* FLATTEN_LINKS_FILE  */
    GECOS = 305,                   /* GECOS  */
    GENERAL = 306,                 /* GENERAL  */
    HIDDEN = 307,                  /* HIDDEN  */
    HIDDEN_NAME = 308,             /* HIDDEN_NAME  */
    HIDE_CHANS = 309,              /* HIDE_CHANS  */
    HIDE_IDLE = 310,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 311,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 312,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 313,           /* HIDE_SERVICES  */
    HOST = 314,                    /* HOST  */
    HUB = 315,                     /* HUB  */
    HUB_MASK = 316,                /* HUB_MASK  */
    IDENT_TIMEOUT = 317,           /* IDENT_TIMEOUT  */
    INVISIBLE_ON_CONNECT = 318,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 319,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 320,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 321,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 322,      /* INVITE_EXPIRE_TIME  */
    IP = 323,                      /* IP  */
    IRCD_AUTH = 324,               /* IRCD_AUTH  */
    IRCD_FLAGS = 325,              /* IRCD_FLAGS  */
    IRCD_SID = 326,                /* IRCD_SID  */
    JOIN = 327,                    /* JOIN  */
    KILL = 328,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 329,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 330,                   /* KLINE  */
    KLINE_EXEMPT = 331,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 332,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 333,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 334,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 335,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 336,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 337,               /* LEAF_MASK  */
    LISTEN = 338,                  /* LISTEN  */
    LOADMODULE = 339,              /* LOADMODULE  */
    MASK = 340,                    /* MASK  */
    MASS = 341,                    /* MASS  */
    MAX_ACCEPT = 342,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 343,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 344,                /* MAX_BANS  */
    MAX_BANS_LARGE = 345,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 346,            /* MAX_CHANNELS  */
    MAX_IDLE = 347,                /* MAX_IDLE  */
    MAX_INVITES = 348,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 349,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 350,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 351,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 352,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 353,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 354,              /* MAX_NUMBER  */
    MAX_TARGETS = 355,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 356,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 357,                 /* MESSAGE  */
    MIN_IDLE = 358,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 359,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 360,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 361,                  /* MODULE  */
    MODULE_BASE_PATH = 362,        /* MODULE_BASE_PATH  */
    MOTD = 363,                    /* MOTD  */
    MOTD_FILE = 364,               /* MOTD_FILE  */
    NAME = 365,                    /* NAME  */
    NEED_IDENT = 366,              /* NEED_IDENT  */
    NEED_PASSWORD = 367,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 368,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 369,            /* NETWORK_NAME  */
    NICK = 370,                    /* NICK  */
    NO_OPER_FLOOD = 371,           /* NO_OPER_FLOOD  */
    NO_TILDE = 372,                /* NO_TILDE  */
    NUM_BITS = 373,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 374,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 375,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 376,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 377,             /* OPER_UMODES  */
    OPERATOR = 378,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 379,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 380,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 381,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 382,                /* PASSWORD  */
    PATH = 383,                    /* PATH  */
    PING_COOKIE = 384,             /* PING_COOKIE  */
    PING_TIME = 385,               /* PING_TIME  */
    PORT = 386,                    /* PORT  */
    RANDOM_IDLE = 387,             /* RANDOM_IDLE  */
    REASON = 388,                  /* REASON  */
    REGISTRATION_TIMEOUT = 389,    /* REGISTRATION_TIMEOUT  */
    REHASH = 390,                  /* REHASH  */
    REMOTE = 391,                  /* REMOTE  */
    REMOTEBAN = 392,               /* REMOTEBAN  */
    REQUIRED = 393,                /* REQUIRED  */
    RESIDENT = 394,                /* RESIDENT  */
    RESV = 395,                    /* RESV  */
    RESV_EXEMPT = 396,             /* RESV_EXEMPT  */
    SECRET = 397,                  /* SECRET  */
    SECONDS = 398,                 /* SECONDS  */
    MINUTES = 399,                 /* MINUTES  */
    HOURS = 400,                   /* HOURS  */
    DAYS = 401,                    /* DAYS  */
    WEEKS = 402,                   /* WEEKS  */
    MONTHS = 403,                  /* MONTHS  */
    YEARS = 404,                   /* YEARS  */
    SEND_PASSWORD = 405,           /* SEND_PASSWORD  */
    SENDQ = 406,                   /* SENDQ  */
    SERVERHIDE = 407,              /* SERVERHIDE  */
    SERVERINFO = 408,              /* SERVERINFO  */
    SHORT_MOTD = 409,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 410,       /* SPECIALS_IN_IDENT  */
    SPOOF = 411,                   /* SPOOF  */
    SQUIT = 412,                   /* SQUIT  */
    STATS_E_DISABLED = 413,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 414,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 415,                  /* SUFFIX  */
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
#define CIDR_LEN_IPV4 274
#define CIDR_LEN_IPV6 275
#define CLASS 276
#define CLIENT 277
#define CLOAK 278
#define CLOSE 279
#define CONNECT 280
#define CONNECTFREQ 281
#define DEFAULT_FLOODCOUNT 282
#define DEFAULT_FLOODTIME 283
#define DEFAULT_JOIN_FLOOD_COUNT 284
#define DEFAULT_JOIN_FLOOD_TIME 285
#define DEFAULT_MAX_CLIENTS 286
#define DEFER 287
#define DENY 288
#define DESCRIPTION 289
#define DIE 290
#define DISABLE_DNS 291
#define DISABLE_IDENT 292
#define DISABLE_FAKE_CHANNELS 293
#define DISABLE_REMOTE_COMMANDS 294
#define DLINE_MIN_CIDR 295
#define DLINE_MIN_CIDR6 296
#define EMAIL 297
#define ENABLED 298
#define ENCRYPTED 299
#define EXCEED_LIMIT 300
#define EXEMPT 301
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
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HOST 314
#define HUB 315
#define HUB_MASK 316
#define IDENT_TIMEOUT 317
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
#define LOADMODULE 339
#define MASK 340
#define MASS 341
#define MAX_ACCEPT 342
#define MAX_AWAY_LENGTH 343
#define MAX_BANS 344
#define MAX_BANS_LARGE 345
#define MAX_CHANNELS 346
#define MAX_IDLE 347
#define MAX_INVITES 348
#define MAX_KICK_LENGTH 349
#define MAX_MONITOR 350
#define MAX_NICK_CHANGES 351
#define MAX_NICK_LENGTH 352
#define MAX_NICK_TIME 353
#define MAX_NUMBER 354
#define MAX_TARGETS 355
#define MAX_TOPIC_LENGTH 356
#define MESSAGE 357
#define MIN_IDLE 358
#define MIN_NONWILDCARD 359
#define MIN_NONWILDCARD_SIMPLE 360
#define MODULE 361
#define MODULE_BASE_PATH 362
#define MOTD 363
#define MOTD_FILE 364
#define NAME 365
#define NEED_IDENT 366
#define NEED_PASSWORD 367
#define NETWORK_DESCRIPTION 368
#define NETWORK_NAME 369
#define NICK 370
#define NO_OPER_FLOOD 371
#define NO_TILDE 372
#define NUM_BITS 373
#define NUMBER_PER_CIDR 374
#define NUMBER_PER_IP_GLOBAL 375
#define NUMBER_PER_IP_LOCAL 376
#define OPER_UMODES 377
#define OPERATOR 378
#define OPERS_BYPASS_CALLERID 379
#define PACE_WAIT 380
#define PACE_WAIT_SIMPLE 381
#define PASSWORD 382
#define PATH 383
#define PING_COOKIE 384
#define PING_TIME 385
#define PORT 386
#define RANDOM_IDLE 387
#define REASON 388
#define REGISTRATION_TIMEOUT 389
#define REHASH 390
#define REMOTE 391
#define REMOTEBAN 392
#define REQUIRED 393
#define RESIDENT 394
#define RESV 395
#define RESV_EXEMPT 396
#define SECRET 397
#define SECONDS 398
#define MINUTES 399
#define HOURS 400
#define DAYS 401
#define WEEKS 402
#define MONTHS 403
#define YEARS 404
#define SEND_PASSWORD 405
#define SENDQ 406
#define SERVERHIDE 407
#define SERVERINFO 408
#define SHORT_MOTD 409
#define SPECIALS_IN_IDENT 410
#define SPOOF 411
#define SQUIT 412
#define STATS_E_DISABLED 413
#define STATS_U_OPER_ONLY 414
#define SUFFIX 415
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
