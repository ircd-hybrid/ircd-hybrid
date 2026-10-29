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
    HIDE_SERVERS = 312,            /* HIDE_SERVERS  */
    HIDE_SERVICES = 313,           /* HIDE_SERVICES  */
    HOST = 314,                    /* HOST  */
    HUB = 315,                     /* HUB  */
    HUB_MASK = 316,                /* HUB_MASK  */
    IDENT_TIMEOUT = 317,           /* IDENT_TIMEOUT  */
    INPUT_FLOOD = 318,             /* INPUT_FLOOD  */
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
    MIN_NONWILDCARD = 358,         /* MIN_NONWILDCARD  */
    MIN_NONWILDCARD_SIMPLE = 359,  /* MIN_NONWILDCARD_SIMPLE  */
    MODULE = 360,                  /* MODULE  */
    MODULE_BASE_PATH = 361,        /* MODULE_BASE_PATH  */
    MOTD = 362,                    /* MOTD  */
    MOTD_FILE = 363,               /* MOTD_FILE  */
    NAME = 364,                    /* NAME  */
    NEED_IDENT = 365,              /* NEED_IDENT  */
    NEED_PASSWORD = 366,           /* NEED_PASSWORD  */
    NETWORK_DESCRIPTION = 367,     /* NETWORK_DESCRIPTION  */
    NETWORK_NAME = 368,            /* NETWORK_NAME  */
    NICK = 369,                    /* NICK  */
    NO_TILDE = 370,                /* NO_TILDE  */
    NUM_BITS = 371,                /* NUM_BITS  */
    NUMBER_PER_CIDR = 372,         /* NUMBER_PER_CIDR  */
    NUMBER_PER_IP_GLOBAL = 373,    /* NUMBER_PER_IP_GLOBAL  */
    NUMBER_PER_IP_LOCAL = 374,     /* NUMBER_PER_IP_LOCAL  */
    OPER_UMODES = 375,             /* OPER_UMODES  */
    OPERATOR = 376,                /* OPERATOR  */
    OPERS_BYPASS_CALLERID = 377,   /* OPERS_BYPASS_CALLERID  */
    PACE_WAIT = 378,               /* PACE_WAIT  */
    PACE_WAIT_SIMPLE = 379,        /* PACE_WAIT_SIMPLE  */
    PASSWORD = 380,                /* PASSWORD  */
    PING_COOKIE = 381,             /* PING_COOKIE  */
    PING_TIME = 382,               /* PING_TIME  */
    PORT = 383,                    /* PORT  */
    REASON = 384,                  /* REASON  */
    REGISTRATION_TIMEOUT = 385,    /* REGISTRATION_TIMEOUT  */
    REHASH = 386,                  /* REHASH  */
    REMOTE = 387,                  /* REMOTE  */
    REMOTEBAN = 388,               /* REMOTEBAN  */
    REQUIRED = 389,                /* REQUIRED  */
    RESIDENT = 390,                /* RESIDENT  */
    RESV = 391,                    /* RESV  */
    RESV_EXEMPT = 392,             /* RESV_EXEMPT  */
    RETRY_DELAY = 393,             /* RETRY_DELAY  */
    SECRET = 394,                  /* SECRET  */
    SECONDS = 395,                 /* SECONDS  */
    MINUTES = 396,                 /* MINUTES  */
    HOURS = 397,                   /* HOURS  */
    DAYS = 398,                    /* DAYS  */
    WEEKS = 399,                   /* WEEKS  */
    SEND_PASSWORD = 400,           /* SEND_PASSWORD  */
    SENDQ = 401,                   /* SENDQ  */
    SERVERHIDE = 402,              /* SERVERHIDE  */
    SERVERINFO = 403,              /* SERVERINFO  */
    SHORT_MOTD = 404,              /* SHORT_MOTD  */
    SPECIALS_IN_IDENT = 405,       /* SPECIALS_IN_IDENT  */
    SPOOF = 406,                   /* SPOOF  */
    SQUIT = 407,                   /* SQUIT  */
    STATS_E_DISABLED = 408,        /* STATS_E_DISABLED  */
    STATS_U_OPER_ONLY = 409,       /* STATS_U_OPER_ONLY  */
    SUFFIX = 410,                  /* SUFFIX  */
    T_ALL = 411,                   /* T_ALL  */
    T_BIND = 412,                  /* T_BIND  */
    T_COMMAND = 413,               /* T_COMMAND  */
    T_CLUSTER = 414,               /* T_CLUSTER  */
    T_DEBUG = 415,                 /* T_DEBUG  */
    T_DLINE = 416,                 /* T_DLINE  */
    T_FILE = 417,                  /* T_FILE  */
    T_GLOBOPS = 418,               /* T_GLOBOPS  */
    T_IPV4 = 419,                  /* T_IPV4  */
    T_IPV6 = 420,                  /* T_IPV6  */
    T_LOCOPS = 421,                /* T_LOCOPS  */
    T_LOG = 422,                   /* T_LOG  */
    T_OPME = 423,                  /* T_OPME  */
    T_PREPEND = 424,               /* T_PREPEND  */
    T_PSEUDO = 425,                /* T_PSEUDO  */
    T_RECVQ = 426,                 /* T_RECVQ  */
    T_RESTART = 427,               /* T_RESTART  */
    T_SERVER = 428,                /* T_SERVER  */
    T_SERVICE = 429,               /* T_SERVICE  */
    T_SET = 430,                   /* T_SET  */
    T_SHARED = 431,                /* T_SHARED  */
    T_SIZE = 432,                  /* T_SIZE  */
    T_TARGET = 433,                /* T_TARGET  */
    T_TLS = 434,                   /* T_TLS  */
    T_UMODES = 435,                /* T_UMODES  */
    T_UNDLINE = 436,               /* T_UNDLINE  */
    T_UNLIMITED = 437,             /* T_UNLIMITED  */
    T_UNRESV = 438,                /* T_UNRESV  */
    T_UNXLINE = 439,               /* T_UNXLINE  */
    T_WEBIRC = 440,                /* T_WEBIRC  */
    TBOOL = 441,                   /* TBOOL  */
    THROTTLE_COUNT = 442,          /* THROTTLE_COUNT  */
    THROTTLE_TIME = 443,           /* THROTTLE_TIME  */
    TIMEOUT = 444,                 /* TIMEOUT  */
    TLS_CERTIFICATE_FILE = 445,    /* TLS_CERTIFICATE_FILE  */
    TLS_CERTIFICATE_FINGERPRINT = 446, /* TLS_CERTIFICATE_FINGERPRINT  */
    TLS_PRIVATE_KEY_FILE = 447,    /* TLS_PRIVATE_KEY_FILE  */
    TLS_CONNECTION_REQUIRED = 448, /* TLS_CONNECTION_REQUIRED  */
    TS_MAX_DELTA = 449,            /* TS_MAX_DELTA  */
    TS_WARN_DELTA = 450,           /* TS_WARN_DELTA  */
    TWODOTS = 451,                 /* TWODOTS  */
    TYPE = 452,                    /* TYPE  */
    UNKLINE = 453,                 /* UNKLINE  */
    USE_LOGGING = 454,             /* USE_LOGGING  */
    USER = 455,                    /* USER  */
    WARN_NO_CONNECT_BLOCK = 456,   /* WARN_NO_CONNECT_BLOCK  */
    WHOIS = 457,                   /* WHOIS  */
    WHOWAS_HISTORY_LENGTH = 458,   /* WHOWAS_HISTORY_LENGTH  */
    XLINE = 459,                   /* XLINE  */
    XLINE_EXEMPT = 460,            /* XLINE_EXEMPT  */
    QSTRING = 461,                 /* QSTRING  */
    DECIMAL = 462,                 /* DECIMAL  */
    NUMBER = 463                   /* NUMBER  */
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
#define HIDE_SERVERS 312
#define HIDE_SERVICES 313
#define HOST 314
#define HUB 315
#define HUB_MASK 316
#define IDENT_TIMEOUT 317
#define INPUT_FLOOD 318
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
#define MIN_NONWILDCARD 358
#define MIN_NONWILDCARD_SIMPLE 359
#define MODULE 360
#define MODULE_BASE_PATH 361
#define MOTD 362
#define MOTD_FILE 363
#define NAME 364
#define NEED_IDENT 365
#define NEED_PASSWORD 366
#define NETWORK_DESCRIPTION 367
#define NETWORK_NAME 368
#define NICK 369
#define NO_TILDE 370
#define NUM_BITS 371
#define NUMBER_PER_CIDR 372
#define NUMBER_PER_IP_GLOBAL 373
#define NUMBER_PER_IP_LOCAL 374
#define OPER_UMODES 375
#define OPERATOR 376
#define OPERS_BYPASS_CALLERID 377
#define PACE_WAIT 378
#define PACE_WAIT_SIMPLE 379
#define PASSWORD 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PORT 383
#define REASON 384
#define REGISTRATION_TIMEOUT 385
#define REHASH 386
#define REMOTE 387
#define REMOTEBAN 388
#define REQUIRED 389
#define RESIDENT 390
#define RESV 391
#define RESV_EXEMPT 392
#define RETRY_DELAY 393
#define SECRET 394
#define SECONDS 395
#define MINUTES 396
#define HOURS 397
#define DAYS 398
#define WEEKS 399
#define SEND_PASSWORD 400
#define SENDQ 401
#define SERVERHIDE 402
#define SERVERINFO 403
#define SHORT_MOTD 404
#define SPECIALS_IN_IDENT 405
#define SPOOF 406
#define SQUIT 407
#define STATS_E_DISABLED 408
#define STATS_U_OPER_ONLY 409
#define SUFFIX 410
#define T_ALL 411
#define T_BIND 412
#define T_COMMAND 413
#define T_CLUSTER 414
#define T_DEBUG 415
#define T_DLINE 416
#define T_FILE 417
#define T_GLOBOPS 418
#define T_IPV4 419
#define T_IPV6 420
#define T_LOCOPS 421
#define T_LOG 422
#define T_OPME 423
#define T_PREPEND 424
#define T_PSEUDO 425
#define T_RECVQ 426
#define T_RESTART 427
#define T_SERVER 428
#define T_SERVICE 429
#define T_SET 430
#define T_SHARED 431
#define T_SIZE 432
#define T_TARGET 433
#define T_TLS 434
#define T_UMODES 435
#define T_UNDLINE 436
#define T_UNLIMITED 437
#define T_UNRESV 438
#define T_UNXLINE 439
#define T_WEBIRC 440
#define TBOOL 441
#define THROTTLE_COUNT 442
#define THROTTLE_TIME 443
#define TIMEOUT 444
#define TLS_CERTIFICATE_FILE 445
#define TLS_CERTIFICATE_FINGERPRINT 446
#define TLS_PRIVATE_KEY_FILE 447
#define TLS_CONNECTION_REQUIRED 448
#define TS_MAX_DELTA 449
#define TS_WARN_DELTA 450
#define TWODOTS 451
#define TYPE 452
#define UNKLINE 453
#define USE_LOGGING 454
#define USER 455
#define WARN_NO_CONNECT_BLOCK 456
#define WHOIS 457
#define WHOWAS_HISTORY_LENGTH 458
#define XLINE 459
#define XLINE_EXEMPT 460
#define QSTRING 461
#define DECIMAL 462
#define NUMBER 463

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 191 "conf_parser.y"

  bool boolean;
  unsigned int number;
  char *string;

#line 495 "conf_parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
