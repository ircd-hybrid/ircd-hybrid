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
/* "%code requires" blocks.  */
#line 12 "conf_parser.y"

#include <stdbool.h>

#line 53 "conf_parser.h"

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
    ANTI_SPAM_EXIT_MESSAGE_TIME = 261, /* ANTI_SPAM_EXIT_MESSAGE_TIME  */
    AUTOCONN = 262,                /* AUTOCONN  */
    AWAY_COUNT = 263,              /* AWAY_COUNT  */
    AWAY_TIME = 264,               /* AWAY_TIME  */
    BYPASS = 265,                  /* BYPASS  */
    BYTES = 266,                   /* BYTES  */
    KBYTES = 267,                  /* KBYTES  */
    KIBYTES = 268,                 /* KIBYTES  */
    MBYTES = 269,                  /* MBYTES  */
    MIBYTES = 270,                 /* MIBYTES  */
    GBYTES = 271,                  /* GBYTES  */
    GIBYTES = 272,                 /* GIBYTES  */
    CALLER_ID_WAIT = 273,          /* CALLER_ID_WAIT  */
    CAN_FLOOD = 274,               /* CAN_FLOOD  */
    CHANNEL = 275,                 /* CHANNEL  */
    CIDR_BITLEN_IPV4 = 276,        /* CIDR_BITLEN_IPV4  */
    CIDR_BITLEN_IPV6 = 277,        /* CIDR_BITLEN_IPV6  */
    CIDR_LEN_IPV4 = 278,           /* CIDR_LEN_IPV4  */
    CIDR_LEN_IPV6 = 279,           /* CIDR_LEN_IPV6  */
    CLASS = 280,                   /* CLASS  */
    CLIENT = 281,                  /* CLIENT  */
    CLOAK = 282,                   /* CLOAK  */
    CLOSE = 283,                   /* CLOSE  */
    CONNECT = 284,                 /* CONNECT  */
    DEFAULT_FLOODCOUNT = 285,      /* DEFAULT_FLOODCOUNT  */
    DEFAULT_FLOODTIME = 286,       /* DEFAULT_FLOODTIME  */
    DEFAULT_JOIN_FLOOD_COUNT = 287, /* DEFAULT_JOIN_FLOOD_COUNT  */
    DEFAULT_JOIN_FLOOD_TIME = 288, /* DEFAULT_JOIN_FLOOD_TIME  */
    DEFAULT_MAX_CLIENTS = 289,     /* DEFAULT_MAX_CLIENTS  */
    DEFER = 290,                   /* DEFER  */
    DENY = 291,                    /* DENY  */
    DESCRIPTION = 292,             /* DESCRIPTION  */
    DIE = 293,                     /* DIE  */
    DISABLE_DNS = 294,             /* DISABLE_DNS  */
    DISABLE_IDENT = 295,           /* DISABLE_IDENT  */
    DISABLE_FAKE_CHANNELS = 296,   /* DISABLE_FAKE_CHANNELS  */
    DISABLE_REMOTE_COMMANDS = 297, /* DISABLE_REMOTE_COMMANDS  */
    DLINE_MIN_CIDR = 298,          /* DLINE_MIN_CIDR  */
    DLINE_MIN_CIDR6 = 299,         /* DLINE_MIN_CIDR6  */
    EMAIL = 300,                   /* EMAIL  */
    ENABLED = 301,                 /* ENABLED  */
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
    INPUT_FLOOD = 321,             /* INPUT_FLOOD  */
    INVISIBLE_ON_CONNECT = 322,    /* INVISIBLE_ON_CONNECT  */
    INVITE_CLIENT_COUNT = 323,     /* INVITE_CLIENT_COUNT  */
    INVITE_CLIENT_TIME = 324,      /* INVITE_CLIENT_TIME  */
    INVITE_DELAY_CHANNEL = 325,    /* INVITE_DELAY_CHANNEL  */
    INVITE_EXPIRE_TIME = 326,      /* INVITE_EXPIRE_TIME  */
    IP = 327,                      /* IP  */
    IRCD_AUTH = 328,               /* IRCD_AUTH  */
    IRCD_FLAGS = 329,              /* IRCD_FLAGS  */
    IRCD_SID = 330,                /* IRCD_SID  */
    JOIN = 331,                    /* JOIN  */
    KILL = 332,                    /* KILL  */
    KILL_CHASE_TIME_LIMIT = 333,   /* KILL_CHASE_TIME_LIMIT  */
    KLINE = 334,                   /* KLINE  */
    KLINE_EXEMPT = 335,            /* KLINE_EXEMPT  */
    KLINE_MIN_CIDR = 336,          /* KLINE_MIN_CIDR  */
    KLINE_MIN_CIDR6 = 337,         /* KLINE_MIN_CIDR6  */
    KNOCK_CLIENT_COUNT = 338,      /* KNOCK_CLIENT_COUNT  */
    KNOCK_CLIENT_TIME = 339,       /* KNOCK_CLIENT_TIME  */
    KNOCK_DELAY_CHANNEL = 340,     /* KNOCK_DELAY_CHANNEL  */
    LEAF_MASK = 341,               /* LEAF_MASK  */
    LISTEN = 342,                  /* LISTEN  */
    LOADMODULE = 343,              /* LOADMODULE  */
    MASK = 344,                    /* MASK  */
    MASS = 345,                    /* MASS  */
    MAX_ACCEPT = 346,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 347,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 348,                /* MAX_BANS  */
    MAX_BANS_LARGE = 349,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 350,            /* MAX_CHANNELS  */
    MAX_IDLE = 351,                /* MAX_IDLE  */
    MAX_INVITES = 352,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 353,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 354,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 355,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 356,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 357,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 358,              /* MAX_NUMBER  */
    MAX_TARGETS = 359,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 360,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 361,                 /* MESSAGE  */
    MIN_IDLE = 362,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 363,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 364,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 365,                  /* MODULE  */
    MODULE_BASE_PATH = 366,        /* MODULE_BASE_PATH  */
    MOTD = 367,                    /* MOTD  */
    MOTD_FILE = 368,               /* MOTD_FILE  */
    NAME = 369,                    /* NAME  */
    NEED_IDENT = 370,              /* NEED_IDENT  */
    NEED_PASSWORD = 371,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 372,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 373,            /* NETWORK_NAME  */
    NICK = 374,                    /* NICK  */
    NO_TILDE = 375,                /* NO_TILDE  */
    NUM_BITS = 376,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 377,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 378,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 379,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 380,             /* OPER_UMODES  */
    OPERATOR = 381,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 382,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 383,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 384,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 385,                /* PASSWORD  */
    PATH = 386,                    /* PATH  */
    PING_COOKIE = 387,             /* PING_COOKIE  */
    PING_TIME = 388,               /* PING_TIME  */
    PORT = 389,                    /* PORT  */
    RANDOM_IDLE = 390,             /* RANDOM_IDLE  */
    REASON = 391,                  /* REASON  */
    REGISTRATION_TIMEOUT = 392,    /* REGISTRATION_TIMEOUT  */
    REHASH = 393,                  /* REHASH  */
    REMOTE = 394,                  /* REMOTE  */
    REMOTEBAN = 395,               /* REMOTEBAN  */
    REQUIRED = 396,                /* REQUIRED  */
    RESIDENT = 397,                /* RESIDENT  */
    RESV = 398,                    /* RESV  */
    RESV_EXEMPT = 399,             /* RESV_EXEMPT  */
    RETRY_DELAY = 400,             /* RETRY_DELAY  */
    SECRET = 401,                  /* SECRET  */
    SECONDS = 402,                 /* SECONDS  */
    MINUTES = 403,                 /* MINUTES  */
    HOURS = 404,                   /* HOURS  */
    DAYS = 405,                    /* DAYS  */
    WEEKS = 406,                   /* WEEKS  */
    SEND_PASSWORD = 407,           /* SEND_PASSWORD  */
    SENDQ = 408,                   /* SENDQ  */
    SERVERHIDE = 409,              /* SERVERHIDE  */
    SERVERINFO = 410,              /* SERVERINFO  */
    SHORT_MOTD = 411,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 412,       /* SPECIALS_IN_IDENT  */
    SPOOF = 413,                   /* SPOOF  */
    SQUIT = 414,                   /* SQUIT  */
    STATS_E_DISABLED = 415,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 416,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 417,                  /* SUFFIX  */
    T_ALL = 418,                   /* T_ALL  */
    T_BIND = 419,                  /* T_BIND  */
    T_COMMAND = 420,               /* T_COMMAND  */
    T_CLUSTER = 421,               /* T_CLUSTER  */
    T_DEBUG = 422,                 /* T_DEBUG  */
    T_DLINE = 423,                 /* T_DLINE  */
    T_FILE = 424,                  /* T_FILE  */
    T_GLOBOPS = 425,               /* T_GLOBOPS  */
    T_IPV4 = 426,                  /* T_IPV4  */
    T_IPV6 = 427,                  /* T_IPV6  */
    T_LOCOPS = 428,                /* T_LOCOPS  */
    T_LOG = 429,                   /* T_LOG  */
    T_OPME = 430,                  /* T_OPME  */
    T_PREPEND = 431,               /* T_PREPEND  */
    T_PSEUDO = 432,                /* T_PSEUDO  */
    T_RECVQ = 433,                 /* T_RECVQ  */
    T_RESTART = 434,               /* T_RESTART  */
    T_SERVER = 435,                /* T_SERVER  */
    T_SERVICE = 436,               /* T_SERVICE  */
    T_SET = 437,                   /* T_SET  */
    T_SHARED = 438,                /* T_SHARED  */
    T_SIZE = 439,                  /* T_SIZE  */
    T_TARGET = 440,                /* T_TARGET  */
    T_TLS = 441,                   /* T_TLS  */
    T_UMODES = 442,                /* T_UMODES  */
    T_UNDLINE = 443,               /* T_UNDLINE  */
    T_UNLIMITED = 444,             /* T_UNLIMITED  */
    T_UNRESV = 445,                /* T_UNRESV  */
    T_UNXLINE = 446,               /* T_UNXLINE  */
    T_WEBIRC = 447,                /* T_WEBIRC  */
    TBOOL = 448,                   /* TBOOL  */
    THROTTLE_COUNT = 449,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 450,           /* THROTTLE_TIME  */
    TIMEOUT = 451,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 452,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 453, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 454,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 455, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 456,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 457,           /* TS_WARN_DELTA  */
    TWODOTS = 458,                 /* TWODOTS  */
    TYPE = 459,                    /* TYPE  */
    UNKLINE = 460,                 /* UNKLINE  */
    USE_LOGGING = 461,             /* USE_LOGGING  */
    USER = 462,                    /* USER  */
    VHOST = 463,                   /* VHOST  */
    VHOST6 = 464,                  /* VHOST6  */
    WARN_NO_CONNECT_BLOCK = 465,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 466,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 467,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 468,                   /* XLINE  */
    XLINE_EXEMPT = 469,            /* XLINE_EXEMPT  */
    QSTRING = 470,                 /* QSTRING  */
    DECIMAL = 471,                 /* DECIMAL  */
    NUMBER = 472                   /* NUMBER  */
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
#define ANTI_SPAM_EXIT_MESSAGE_TIME 261
#define AUTOCONN 262
#define AWAY_COUNT 263
#define AWAY_TIME 264
#define BYPASS 265
#define BYTES 266
#define KBYTES 267
#define KIBYTES 268
#define MBYTES 269
#define MIBYTES 270
#define GBYTES 271
#define GIBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CIDR_LEN_IPV4 278
#define CIDR_LEN_IPV6 279
#define CLASS 280
#define CLIENT 281
#define CLOAK 282
#define CLOSE 283
#define CONNECT 284
#define DEFAULT_FLOODCOUNT 285
#define DEFAULT_FLOODTIME 286
#define DEFAULT_JOIN_FLOOD_COUNT 287
#define DEFAULT_JOIN_FLOOD_TIME 288
#define DEFAULT_MAX_CLIENTS 289
#define DEFER 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_DNS 294
#define DISABLE_IDENT 295
#define DISABLE_FAKE_CHANNELS 296
#define DISABLE_REMOTE_COMMANDS 297
#define DLINE_MIN_CIDR 298
#define DLINE_MIN_CIDR6 299
#define EMAIL 300
#define ENABLED 301
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
#define INPUT_FLOOD 321
#define INVISIBLE_ON_CONNECT 322
#define INVITE_CLIENT_COUNT 323
#define INVITE_CLIENT_TIME 324
#define INVITE_DELAY_CHANNEL 325
#define INVITE_EXPIRE_TIME 326
#define IP 327
#define IRCD_AUTH 328
#define IRCD_FLAGS 329
#define IRCD_SID 330
#define JOIN 331
#define KILL 332
#define KILL_CHASE_TIME_LIMIT 333
#define KLINE 334
#define KLINE_EXEMPT 335
#define KLINE_MIN_CIDR 336
#define KLINE_MIN_CIDR6 337
#define KNOCK_CLIENT_COUNT 338
#define KNOCK_CLIENT_TIME 339
#define KNOCK_DELAY_CHANNEL 340
#define LEAF_MASK 341
#define LISTEN 342
#define LOADMODULE 343
#define MASK 344
#define MASS 345
#define MAX_ACCEPT 346
#define MAX_AWAY_LENGTH 347
#define MAX_BANS 348
#define MAX_BANS_LARGE 349
#define MAX_CHANNELS 350
#define MAX_IDLE 351
#define MAX_INVITES 352
#define MAX_KICK_LENGTH 353
#define MAX_MONITOR 354
#define MAX_NICK_CHANGES 355
#define MAX_NICK_LENGTH 356
#define MAX_NICK_TIME 357
#define MAX_NUMBER 358
#define MAX_TARGETS 359
#define MAX_TOPIC_LENGTH 360
#define MESSAGE 361
#define MIN_IDLE 362
#define MIN_NONWILDCARD 363
#define MIN_NONWILDCARD_SIMPLE 364
#define MODULE 365
#define MODULE_BASE_PATH 366
#define MOTD 367
#define MOTD_FILE 368
#define NAME 369
#define NEED_IDENT 370
#define NEED_PASSWORD 371
#define NETWORK_DESCRIPTION 372
#define NETWORK_NAME 373
#define NICK 374
#define NO_TILDE 375
#define NUM_BITS 376
#define NUMBER_PER_CIDR 377
#define NUMBER_PER_IP_GLOBAL 378
#define NUMBER_PER_IP_LOCAL 379
#define OPER_UMODES 380
#define OPERATOR 381
#define OPERS_BYPASS_CALLERID 382
#define PACE_WAIT 383
#define PACE_WAIT_SIMPLE 384
#define PASSWORD 385
#define PATH 386
#define PING_COOKIE 387
#define PING_TIME 388
#define PORT 389
#define RANDOM_IDLE 390
#define REASON 391
#define REGISTRATION_TIMEOUT 392
#define REHASH 393
#define REMOTE 394
#define REMOTEBAN 395
#define REQUIRED 396
#define RESIDENT 397
#define RESV 398
#define RESV_EXEMPT 399
#define RETRY_DELAY 400
#define SECRET 401
#define SECONDS 402
#define MINUTES 403
#define HOURS 404
#define DAYS 405
#define WEEKS 406
#define SEND_PASSWORD 407
#define SENDQ 408
#define SERVERHIDE 409
#define SERVERINFO 410
#define SHORT_MOTD 411
#define SPECIALS_IN_IDENT 412
#define SPOOF 413
#define SQUIT 414
#define STATS_E_DISABLED 415
#define STATS_U_OPER_ONLY 416
#define SUFFIX 417
#define T_ALL 418
#define T_BIND 419
#define T_COMMAND 420
#define T_CLUSTER 421
#define T_DEBUG 422
#define T_DLINE 423
#define T_FILE 424
#define T_GLOBOPS 425
#define T_IPV4 426
#define T_IPV6 427
#define T_LOCOPS 428
#define T_LOG 429
#define T_OPME 430
#define T_PREPEND 431
#define T_PSEUDO 432
#define T_RECVQ 433
#define T_RESTART 434
#define T_SERVER 435
#define T_SERVICE 436
#define T_SET 437
#define T_SHARED 438
#define T_SIZE 439
#define T_TARGET 440
#define T_TLS 441
#define T_UMODES 442
#define T_UNDLINE 443
#define T_UNLIMITED 444
#define T_UNRESV 445
#define T_UNXLINE 446
#define T_WEBIRC 447
#define TBOOL 448
#define THROTTLE_COUNT 449
#define THROTTLE_TIME 450
#define TIMEOUT 451
#define TLS_CERTIFICATE_FILE 452
#define TLS_CERTIFICATE_FINGERPRINT 453
#define TLS_PRIVATE_KEY_FILE 454
#define TLS_CONNECTION_REQUIRED 455
#define TS_MAX_DELTA 456
#define TS_WARN_DELTA 457
#define TWODOTS 458
#define TYPE 459
#define UNKLINE 460
#define USE_LOGGING 461
#define USER 462
#define VHOST 463
#define VHOST6 464
#define WARN_NO_CONNECT_BLOCK 465
#define WHOIS 466
#define WHOWAS_HISTORY_LENGTH 467
#define XLINE 468
#define XLINE_EXEMPT 469
#define QSTRING 470
#define DECIMAL 471
#define NUMBER 472

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 194 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 513 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
