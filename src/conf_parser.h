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
    BYPASS = 266,                  /* BYPASS  */
    BYTES = 267,                   /* BYTES  */
    KBYTES = 268,                  /* KBYTES  */
    KIBYTES = 269,                 /* KIBYTES  */
    MBYTES = 270,                  /* MBYTES  */
    MIBYTES = 271,                 /* MIBYTES  */
    GBYTES = 272,                  /* GBYTES  */
    GIBYTES = 273,                 /* GIBYTES  */
    CALLER_ID_WAIT = 274,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 275,               /* CAN_FLOOD  */
    CHANNEL = 276,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 277,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 278,        /* CIDR_BITLEN_IPV6  */
    CIDR_LEN_IPV4 = 279,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 280,           /* CIDR_LEN_IPV6  */
    CLASS = 281,                   /* CLASS  */
    CLIENT = 282,                  /* CLIENT  */
    CLOAK = 283,                   /* CLOAK  */
    CLOSE = 284,                   /* CLOSE  */
    CONNECT = 285,                 /* CONNECT  */
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
    ENABLED = 302,                 /* ENABLED  */
    ENCRYPTED = 303,               /* ENCRYPTED  */
    EXCEED_LIMIT = 304,            /* EXCEED_LIMIT  */
    EXEMPT = 305,                  /* EXEMPT  */
    FLATTEN_LINKS = 306,           /* FLATTEN_LINKS  */
    FLATTEN_LINKS_DELAY = 307,     /* FLATTEN_LINKS_DELAY  */
    FLATTEN_LINKS_FILE = 308,      /* FLATTEN_LINKS_FILE  */
    GECOS = 309,                   /* GECOS  */
    GENERAL = 310,                 /* GENERAL  */
    HIDDEN = 311,                  /* HIDDEN  */
    HIDDEN_NAME = 312,             /* HIDDEN_NAME  */
    HIDE_CHANS = 313,              /* HIDE_CHANS  */
    HIDE_IDLE = 314,               /* HIDE_IDLE  */
    HIDE_IDLE_FROM_OPERS = 315,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 316,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 317,           /* HIDE_SERVICES  */
    HOST = 318,                    /* HOST  */
    HUB = 319,                     /* HUB  */
    HUB_MASK = 320,                /* HUB_MASK  */
    IDENT_TIMEOUT = 321,           /* IDENT_TIMEOUT  */
    INPUT_FLOOD = 322,             /* INPUT_FLOOD  */
    INVISIBLE_ON_CONNECT = 323,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 324,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 325,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 326,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 327,      /* INVITE_EXPIRE_TIME  */
    IP = 328,                      /* IP  */
    IRCD_AUTH = 329,               /* IRCD_AUTH  */
    IRCD_FLAGS = 330,              /* IRCD_FLAGS  */
    IRCD_SID = 331,                /* IRCD_SID  */
    JOIN = 332,                    /* JOIN  */
    KILL = 333,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 334,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 335,                   /* KLINE  */
    KLINE_EXEMPT = 336,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 337,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 338,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 339,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 340,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 341,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 342,               /* LEAF_MASK  */
    LISTEN = 343,                  /* LISTEN  */
    LOADMODULE = 344,              /* LOADMODULE  */
    MASK = 345,                    /* MASK  */
    MASS = 346,                    /* MASS  */
    MAX_ACCEPT = 347,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 348,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 349,                /* MAX_BANS  */
    MAX_BANS_LARGE = 350,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 351,            /* MAX_CHANNELS  */
    MAX_IDLE = 352,                /* MAX_IDLE  */
    MAX_INVITES = 353,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 354,         /* MAX_KICK_LENGTH  */
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
    NO_TILDE = 376,                /* NO_TILDE  */
    NUM_BITS = 377,                /* NUM_BITS  */
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
    REGISTRATION_TIMEOUT = 393,    /* REGISTRATION_TIMEOUT  */
    REHASH = 394,                  /* REHASH  */
    REMOTE = 395,                  /* REMOTE  */
    REMOTEBAN = 396,               /* REMOTEBAN  */
    REQUIRED = 397,                /* REQUIRED  */
    RESIDENT = 398,                /* RESIDENT  */
    RESV = 399,                    /* RESV  */
    RESV_EXEMPT = 400,             /* RESV_EXEMPT  */
    RETRY_DELAY = 401,             /* RETRY_DELAY  */
    SECRET = 402,                  /* SECRET  */
    SECONDS = 403,                 /* SECONDS  */
    MINUTES = 404,                 /* MINUTES  */
    HOURS = 405,                   /* HOURS  */
    DAYS = 406,                    /* DAYS  */
    WEEKS = 407,                   /* WEEKS  */
    SEND_PASSWORD = 408,           /* SEND_PASSWORD  */
    SENDQ = 409,                   /* SENDQ  */
    SERVERHIDE = 410,              /* SERVERHIDE  */
    SERVERINFO = 411,              /* SERVERINFO  */
    SHORT_MOTD = 412,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 413,       /* SPECIALS_IN_IDENT  */
    SPOOF = 414,                   /* SPOOF  */
    SQUIT = 415,                   /* SQUIT  */
    STATS_E_DISABLED = 416,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 417,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 418,                  /* SUFFIX  */
    T_ALL = 419,                   /* T_ALL  */
    T_BIND = 420,                  /* T_BIND  */
    T_COMMAND = 421,               /* T_COMMAND  */
    T_CLUSTER = 422,               /* T_CLUSTER  */
    T_DEBUG = 423,                 /* T_DEBUG  */
    T_DLINE = 424,                 /* T_DLINE  */
    T_FILE = 425,                  /* T_FILE  */
    T_GLOBOPS = 426,               /* T_GLOBOPS  */
    T_IPV4 = 427,                  /* T_IPV4  */
    T_IPV6 = 428,                  /* T_IPV6  */
    T_LOCOPS = 429,                /* T_LOCOPS  */
    T_LOG = 430,                   /* T_LOG  */
    T_OPME = 431,                  /* T_OPME  */
    T_PREPEND = 432,               /* T_PREPEND  */
    T_PSEUDO = 433,                /* T_PSEUDO  */
    T_RECVQ = 434,                 /* T_RECVQ  */
    T_RESTART = 435,               /* T_RESTART  */
    T_SERVER = 436,                /* T_SERVER  */
    T_SERVICE = 437,               /* T_SERVICE  */
    T_SET = 438,                   /* T_SET  */
    T_SHARED = 439,                /* T_SHARED  */
    T_SIZE = 440,                  /* T_SIZE  */
    T_TARGET = 441,                /* T_TARGET  */
    T_TLS = 442,                   /* T_TLS  */
    T_UMODES = 443,                /* T_UMODES  */
    T_UNDLINE = 444,               /* T_UNDLINE  */
    T_UNLIMITED = 445,             /* T_UNLIMITED  */
    T_UNRESV = 446,                /* T_UNRESV  */
    T_UNXLINE = 447,               /* T_UNXLINE  */
    T_WEBIRC = 448,                /* T_WEBIRC  */
    TBOOL = 449,                   /* TBOOL  */
    THROTTLE_COUNT = 450,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 451,           /* THROTTLE_TIME  */
    TIMEOUT = 452,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 453,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 454, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 455,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 456, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 457,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 458,           /* TS_WARN_DELTA  */
    TWODOTS = 459,                 /* TWODOTS  */
    TYPE = 460,                    /* TYPE  */
    UNKLINE = 461,                 /* UNKLINE  */
    USE_LOGGING = 462,             /* USE_LOGGING  */
    USER = 463,                    /* USER  */
    VHOST = 464,                   /* VHOST  */
    VHOST6 = 465,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 466,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 467,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 468,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 469,                   /* XLINE  */
    XLINE_EXEMPT = 470,            /* XLINE_EXEMPT  */
    QSTRING = 471,                 /* QSTRING  */
    DECIMAL = 472,                 /* DECIMAL  */
    NUMBER = 473                   /* NUMBER  */
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
#define BYPASS 266
#define BYTES 267
#define KBYTES 268
#define KIBYTES 269
#define MBYTES 270
#define MIBYTES 271
#define GBYTES 272
#define GIBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CHANNEL 276
#define CIDR_BITLEN_IPV4 277
#define CIDR_BITLEN_IPV6 278
#define CIDR_LEN_IPV4 279
#define CIDR_LEN_IPV6 280
#define CLASS 281
#define CLIENT 282
#define CLOAK 283
#define CLOSE 284
#define CONNECT 285
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
#define ENABLED 302
#define ENCRYPTED 303
#define EXCEED_LIMIT 304
#define EXEMPT 305
#define FLATTEN_LINKS 306
#define FLATTEN_LINKS_DELAY 307
#define FLATTEN_LINKS_FILE 308
#define GECOS 309
#define GENERAL 310
#define HIDDEN 311
#define HIDDEN_NAME 312
#define HIDE_CHANS 313
#define HIDE_IDLE 314
#define HIDE_IDLE_FROM_OPERS 315
#define HIDE_SERVERS 316
#define HIDE_SERVICES 317
#define HOST 318
#define HUB 319
#define HUB_MASK 320
#define IDENT_TIMEOUT 321
#define INPUT_FLOOD 322
#define INVISIBLE_ON_CONNECT 323
#define INVITE_CLIENT_COUNT 324
#define INVITE_CLIENT_TIME 325
#define INVITE_DELAY_CHANNEL 326
#define INVITE_EXPIRE_TIME 327
#define IP 328
#define IRCD_AUTH 329
#define IRCD_FLAGS 330
#define IRCD_SID 331
#define JOIN 332
#define KILL 333
#define KILL_CHASE_TIME_LIMIT 334
#define KLINE 335
#define KLINE_EXEMPT 336
#define KLINE_MIN_CIDR 337
#define KLINE_MIN_CIDR6 338
#define KNOCK_CLIENT_COUNT 339
#define KNOCK_CLIENT_TIME 340
#define KNOCK_DELAY_CHANNEL 341
#define LEAF_MASK 342
#define LISTEN 343
#define LOADMODULE 344
#define MASK 345
#define MASS 346
#define MAX_ACCEPT 347
#define MAX_AWAY_LENGTH 348
#define MAX_BANS 349
#define MAX_BANS_LARGE 350
#define MAX_CHANNELS 351
#define MAX_IDLE 352
#define MAX_INVITES 353
#define MAX_KICK_LENGTH 354
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
#define NO_TILDE 376
#define NUM_BITS 377
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
#define REGISTRATION_TIMEOUT 393
#define REHASH 394
#define REMOTE 395
#define REMOTEBAN 396
#define REQUIRED 397
#define RESIDENT 398
#define RESV 399
#define RESV_EXEMPT 400
#define RETRY_DELAY 401
#define SECRET 402
#define SECONDS 403
#define MINUTES 404
#define HOURS 405
#define DAYS 406
#define WEEKS 407
#define SEND_PASSWORD 408
#define SENDQ 409
#define SERVERHIDE 410
#define SERVERINFO 411
#define SHORT_MOTD 412
#define SPECIALS_IN_IDENT 413
#define SPOOF 414
#define SQUIT 415
#define STATS_E_DISABLED 416
#define STATS_U_OPER_ONLY 417
#define SUFFIX 418
#define T_ALL 419
#define T_BIND 420
#define T_COMMAND 421
#define T_CLUSTER 422
#define T_DEBUG 423
#define T_DLINE 424
#define T_FILE 425
#define T_GLOBOPS 426
#define T_IPV4 427
#define T_IPV6 428
#define T_LOCOPS 429
#define T_LOG 430
#define T_OPME 431
#define T_PREPEND 432
#define T_PSEUDO 433
#define T_RECVQ 434
#define T_RESTART 435
#define T_SERVER 436
#define T_SERVICE 437
#define T_SET 438
#define T_SHARED 439
#define T_SIZE 440
#define T_TARGET 441
#define T_TLS 442
#define T_UMODES 443
#define T_UNDLINE 444
#define T_UNLIMITED 445
#define T_UNRESV 446
#define T_UNXLINE 447
#define T_WEBIRC 448
#define TBOOL 449
#define THROTTLE_COUNT 450
#define THROTTLE_TIME 451
#define TIMEOUT 452
#define TLS_CERTIFICATE_FILE 453
#define TLS_CERTIFICATE_FINGERPRINT 454
#define TLS_PRIVATE_KEY_FILE 455
#define TLS_CONNECTION_REQUIRED 456
#define TS_MAX_DELTA 457
#define TS_WARN_DELTA 458
#define TWODOTS 459
#define TYPE 460
#define UNKLINE 461
#define USE_LOGGING 462
#define USER 463
#define VHOST 464
#define VHOST6 465
#define WARN_NO_CONNECT_BLOCK 466
#define WHOIS 467
#define WHOWAS_HISTORY_LENGTH 468
#define XLINE 469
#define XLINE_EXEMPT 470
#define QSTRING 471
#define DECIMAL 472
#define NUMBER 473

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 190 "conf_parser.y"

  unsigned int number;
  char *string;

#line 508 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
