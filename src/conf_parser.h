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
    HIDE_IDLE_FROM_OPERS = 312,    /* HIDE_IDLE_FROM_OPERS  */
    HIDE_SERVERS = 313,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 314,           /* HIDE_SERVICES  */
    HOST = 315,                    /* HOST  */
    HUB = 316,                     /* HUB  */
    HUB_MASK = 317,                /* HUB_MASK  */
    IDENT_TIMEOUT = 318,           /* IDENT_TIMEOUT  */
    INPUT_FLOOD = 319,             /* INPUT_FLOOD  */
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
    LOADMODULE = 341,              /* LOADMODULE  */
    MASK = 342,                    /* MASK  */
    MASS = 343,                    /* MASS  */
    MAX_ACCEPT = 344,              /* MAX_ACCEPT  */
    MAX_AWAY_LENGTH = 345,         /* MAX_AWAY_LENGTH  */
    MAX_BANS = 346,                /* MAX_BANS  */
    MAX_BANS_LARGE = 347,          /* MAX_BANS_LARGE  */
    MAX_CHANNELS = 348,            /* MAX_CHANNELS  */
    MAX_IDLE = 349,                /* MAX_IDLE  */
    MAX_INVITES = 350,             /* MAX_INVITES  */
    MAX_KICK_LENGTH = 351,         /* MAX_KICK_LENGTH  */
    MAX_MONITOR = 352,             /* MAX_MONITOR  */
    MAX_NICK_CHANGES = 353,        /* MAX_NICK_CHANGES  */
    MAX_NICK_LENGTH = 354,         /* MAX_NICK_LENGTH  */
    MAX_NICK_TIME = 355,           /* MAX_NICK_TIME  */
    MAX_NUMBER = 356,              /* MAX_NUMBER  */
    MAX_TARGETS = 357,             /* MAX_TARGETS  */
    MAX_TOPIC_LENGTH = 358,        /* MAX_TOPIC_LENGTH  */
    MESSAGE = 359,                 /* MESSAGE  */
    MIN_IDLE = 360,                /* MIN_IDLE  */
    MIN_NONWILDCARD = 361,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 362,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 363,                  /* MODULE  */
    MODULE_BASE_PATH = 364,        /* MODULE_BASE_PATH  */
    MOTD = 365,                    /* MOTD  */
    MOTD_FILE = 366,               /* MOTD_FILE  */
    NAME = 367,                    /* NAME  */
    NEED_IDENT = 368,              /* NEED_IDENT  */
    NEED_PASSWORD = 369,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 370,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 371,            /* NETWORK_NAME  */
    NICK = 372,                    /* NICK  */
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
    RETRY_DELAY = 397,             /* RETRY_DELAY  */
    SECRET = 398,                  /* SECRET  */
    SECONDS = 399,                 /* SECONDS  */
    MINUTES = 400,                 /* MINUTES  */
    HOURS = 401,                   /* HOURS  */
    DAYS = 402,                    /* DAYS  */
    WEEKS = 403,                   /* WEEKS  */
    SEND_PASSWORD = 404,           /* SEND_PASSWORD  */
    SENDQ = 405,                   /* SENDQ  */
    SERVERHIDE = 406,              /* SERVERHIDE  */
    SERVERINFO = 407,              /* SERVERINFO  */
    SHORT_MOTD = 408,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 409,       /* SPECIALS_IN_IDENT  */
    SPOOF = 410,                   /* SPOOF  */
    SQUIT = 411,                   /* SQUIT  */
    STATS_E_DISABLED = 412,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 413,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 414,                  /* SUFFIX  */
    T_ALL = 415,                   /* T_ALL  */
    T_BIND = 416,                  /* T_BIND  */
    T_COMMAND = 417,               /* T_COMMAND  */
    T_CLUSTER = 418,               /* T_CLUSTER  */
    T_DEBUG = 419,                 /* T_DEBUG  */
    T_DLINE = 420,                 /* T_DLINE  */
    T_FILE = 421,                  /* T_FILE  */
    T_GLOBOPS = 422,               /* T_GLOBOPS  */
    T_IPV4 = 423,                  /* T_IPV4  */
    T_IPV6 = 424,                  /* T_IPV6  */
    T_LOCOPS = 425,                /* T_LOCOPS  */
    T_LOG = 426,                   /* T_LOG  */
    T_OPME = 427,                  /* T_OPME  */
    T_PREPEND = 428,               /* T_PREPEND  */
    T_PSEUDO = 429,                /* T_PSEUDO  */
    T_RECVQ = 430,                 /* T_RECVQ  */
    T_RESTART = 431,               /* T_RESTART  */
    T_SERVER = 432,                /* T_SERVER  */
    T_SERVICE = 433,               /* T_SERVICE  */
    T_SET = 434,                   /* T_SET  */
    T_SHARED = 435,                /* T_SHARED  */
    T_SIZE = 436,                  /* T_SIZE  */
    T_TARGET = 437,                /* T_TARGET  */
    T_TLS = 438,                   /* T_TLS  */
    T_UMODES = 439,                /* T_UMODES  */
    T_UNDLINE = 440,               /* T_UNDLINE  */
    T_UNLIMITED = 441,             /* T_UNLIMITED  */
    T_UNRESV = 442,                /* T_UNRESV  */
    T_UNXLINE = 443,               /* T_UNXLINE  */
    T_WEBIRC = 444,                /* T_WEBIRC  */
    TBOOL = 445,                   /* TBOOL  */
    THROTTLE_COUNT = 446,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 447,           /* THROTTLE_TIME  */
    TIMEOUT = 448,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 449,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 450, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 451,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 452, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 453,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 454,           /* TS_WARN_DELTA  */
    TWODOTS = 455,                 /* TWODOTS  */
    TYPE = 456,                    /* TYPE  */
    UNKLINE = 457,                 /* UNKLINE  */
    USE_LOGGING = 458,             /* USE_LOGGING  */
    USER = 459,                    /* USER  */
    WARN_NO_CONNECT_BLOCK = 460,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 461,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 462,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 463,                   /* XLINE  */
    XLINE_EXEMPT = 464,            /* XLINE_EXEMPT  */
    QSTRING = 465,                 /* QSTRING  */
    DECIMAL = 466,                 /* DECIMAL  */
    NUMBER = 467                   /* NUMBER  */
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
#define HIDE_IDLE_FROM_OPERS 312
#define HIDE_SERVERS 313
#define HIDE_SERVICES 314
#define HOST 315
#define HUB 316
#define HUB_MASK 317
#define IDENT_TIMEOUT 318
#define INPUT_FLOOD 319
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
#define LOADMODULE 341
#define MASK 342
#define MASS 343
#define MAX_ACCEPT 344
#define MAX_AWAY_LENGTH 345
#define MAX_BANS 346
#define MAX_BANS_LARGE 347
#define MAX_CHANNELS 348
#define MAX_IDLE 349
#define MAX_INVITES 350
#define MAX_KICK_LENGTH 351
#define MAX_MONITOR 352
#define MAX_NICK_CHANGES 353
#define MAX_NICK_LENGTH 354
#define MAX_NICK_TIME 355
#define MAX_NUMBER 356
#define MAX_TARGETS 357
#define MAX_TOPIC_LENGTH 358
#define MESSAGE 359
#define MIN_IDLE 360
#define MIN_NONWILDCARD 361
#define MIN_NONWILDCARD_SIMPLE 362
#define MODULE 363
#define MODULE_BASE_PATH 364
#define MOTD 365
#define MOTD_FILE 366
#define NAME 367
#define NEED_IDENT 368
#define NEED_PASSWORD 369
#define NETWORK_DESCRIPTION 370
#define NETWORK_NAME 371
#define NICK 372
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
#define RETRY_DELAY 397
#define SECRET 398
#define SECONDS 399
#define MINUTES 400
#define HOURS 401
#define DAYS 402
#define WEEKS 403
#define SEND_PASSWORD 404
#define SENDQ 405
#define SERVERHIDE 406
#define SERVERINFO 407
#define SHORT_MOTD 408
#define SPECIALS_IN_IDENT 409
#define SPOOF 410
#define SQUIT 411
#define STATS_E_DISABLED 412
#define STATS_U_OPER_ONLY 413
#define SUFFIX 414
#define T_ALL 415
#define T_BIND 416
#define T_COMMAND 417
#define T_CLUSTER 418
#define T_DEBUG 419
#define T_DLINE 420
#define T_FILE 421
#define T_GLOBOPS 422
#define T_IPV4 423
#define T_IPV6 424
#define T_LOCOPS 425
#define T_LOG 426
#define T_OPME 427
#define T_PREPEND 428
#define T_PSEUDO 429
#define T_RECVQ 430
#define T_RESTART 431
#define T_SERVER 432
#define T_SERVICE 433
#define T_SET 434
#define T_SHARED 435
#define T_SIZE 436
#define T_TARGET 437
#define T_TLS 438
#define T_UMODES 439
#define T_UNDLINE 440
#define T_UNLIMITED 441
#define T_UNRESV 442
#define T_UNXLINE 443
#define T_WEBIRC 444
#define TBOOL 445
#define THROTTLE_COUNT 446
#define THROTTLE_TIME 447
#define TIMEOUT 448
#define TLS_CERTIFICATE_FILE 449
#define TLS_CERTIFICATE_FINGERPRINT 450
#define TLS_PRIVATE_KEY_FILE 451
#define TLS_CONNECTION_REQUIRED 452
#define TS_MAX_DELTA 453
#define TS_WARN_DELTA 454
#define TWODOTS 455
#define TYPE 456
#define UNKLINE 457
#define USE_LOGGING 458
#define USER 459
#define WARN_NO_CONNECT_BLOCK 460
#define WHOIS 461
#define WHOWAS_HISTORY_LENGTH 462
#define XLINE 463
#define XLINE_EXEMPT 464
#define QSTRING 465
#define DECIMAL 466
#define NUMBER 467

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 194 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 503 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
