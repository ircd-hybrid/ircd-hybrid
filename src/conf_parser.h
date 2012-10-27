/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ACCEPT_PASSWORD = 258,
     ACTION = 259,
     ADMIN = 260,
     AFTYPE = 261,
     T_ALLOW = 262,
     ANTI_NICK_FLOOD = 263,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 264,
     AUTOCONN = 265,
     T_BLOCK = 266,
     BURST_AWAY = 267,
     BYTES = 268,
     KBYTES = 269,
     MBYTES = 270,
     GBYTES = 271,
     TBYTES = 272,
     CALLER_ID_WAIT = 273,
     CAN_FLOOD = 274,
     CHANNEL = 275,
     CIDR_BITLEN_IPV4 = 276,
     CIDR_BITLEN_IPV6 = 277,
     CLASS = 278,
     CONNECT = 279,
     CONNECTFREQ = 280,
     DEFAULT_FLOODCOUNT = 281,
     DEFAULT_SPLIT_SERVER_COUNT = 282,
     DEFAULT_SPLIT_USER_COUNT = 283,
     DENY = 284,
     DESCRIPTION = 285,
     DIE = 286,
     DISABLE_AUTH = 287,
     DISABLE_FAKE_CHANNELS = 288,
     DISABLE_HIDDEN = 289,
     DISABLE_LOCAL_CHANNELS = 290,
     DISABLE_REMOTE_COMMANDS = 291,
     DOTS_IN_IDENT = 292,
     DURATION = 293,
     EGDPOOL_PATH = 294,
     EMAIL = 295,
     ENABLE = 296,
     ENCRYPTED = 297,
     EXCEED_LIMIT = 298,
     EXEMPT = 299,
     FAILED_OPER_NOTICE = 300,
     IRCD_FLAGS = 301,
     FLATTEN_LINKS = 302,
     GECOS = 303,
     GENERAL = 304,
     GLINE = 305,
     GLINES = 306,
     GLINE_EXEMPT = 307,
     GLINE_TIME = 308,
     GLINE_MIN_CIDR = 309,
     GLINE_MIN_CIDR6 = 310,
     GLOBAL_KILL = 311,
     IRCD_AUTH = 312,
     NEED_IDENT = 313,
     HAVENT_READ_CONF = 314,
     HIDDEN = 315,
     HIDDEN_NAME = 316,
     HIDE_SERVER_IPS = 317,
     HIDE_SERVERS = 318,
     HIDE_SPOOF_IPS = 319,
     HOST = 320,
     HUB = 321,
     HUB_MASK = 322,
     IGNORE_BOGUS_TS = 323,
     INVISIBLE_ON_CONNECT = 324,
     IP = 325,
     KILL = 326,
     KILL_CHASE_TIME_LIMIT = 327,
     KLINE = 328,
     KLINE_EXEMPT = 329,
     KLINE_REASON = 330,
     KLINE_WITH_REASON = 331,
     KNOCK_DELAY = 332,
     KNOCK_DELAY_CHANNEL = 333,
     LEAF_MASK = 334,
     LINKS_DELAY = 335,
     LISTEN = 336,
     T_LOG = 337,
     MAX_ACCEPT = 338,
     MAX_BANS = 339,
     MAX_CHANS_PER_USER = 340,
     MAX_GLOBAL = 341,
     MAX_IDENT = 342,
     MAX_LOCAL = 343,
     MAX_NICK_CHANGES = 344,
     MAX_NICK_TIME = 345,
     MAX_NUMBER = 346,
     MAX_TARGETS = 347,
     MAX_WATCH = 348,
     MESSAGE_LOCALE = 349,
     MIN_NONWILDCARD = 350,
     MIN_NONWILDCARD_SIMPLE = 351,
     MODULE = 352,
     MODULES = 353,
     NAME = 354,
     NEED_PASSWORD = 355,
     NETWORK_DESC = 356,
     NETWORK_NAME = 357,
     NICK = 358,
     NICK_CHANGES = 359,
     NO_CREATE_ON_SPLIT = 360,
     NO_JOIN_ON_SPLIT = 361,
     NO_OPER_FLOOD = 362,
     NO_TILDE = 363,
     NUMBER = 364,
     NUMBER_PER_IDENT = 365,
     NUMBER_PER_CIDR = 366,
     NUMBER_PER_IP = 367,
     NUMBER_PER_IP_GLOBAL = 368,
     OPERATOR = 369,
     OPERS_BYPASS_CALLERID = 370,
     OPER_ONLY_UMODES = 371,
     OPER_PASS_RESV = 372,
     OPER_SPY_T = 373,
     OPER_UMODES = 374,
     JOIN_FLOOD_COUNT = 375,
     JOIN_FLOOD_TIME = 376,
     PACE_WAIT = 377,
     PACE_WAIT_SIMPLE = 378,
     PASSWORD = 379,
     PATH = 380,
     PING_COOKIE = 381,
     PING_TIME = 382,
     PING_WARNING = 383,
     PORT = 384,
     QSTRING = 385,
     QUIET_ON_BAN = 386,
     REASON = 387,
     REDIRPORT = 388,
     REDIRSERV = 389,
     REGEX_T = 390,
     REHASH = 391,
     TREJECT_HOLD_TIME = 392,
     REMOTE = 393,
     REMOTEBAN = 394,
     RESTRICT_CHANNELS = 395,
     RESTRICTED = 396,
     RSA_PRIVATE_KEY_FILE = 397,
     RSA_PUBLIC_KEY_FILE = 398,
     SSL_CERTIFICATE_FILE = 399,
     SSL_DH_PARAM_FILE = 400,
     T_SSL_CLIENT_METHOD = 401,
     T_SSL_SERVER_METHOD = 402,
     T_SSLV3 = 403,
     T_TLSV1 = 404,
     RESV = 405,
     RESV_EXEMPT = 406,
     SECONDS = 407,
     MINUTES = 408,
     HOURS = 409,
     DAYS = 410,
     WEEKS = 411,
     SENDQ = 412,
     SEND_PASSWORD = 413,
     SERVERHIDE = 414,
     SERVERINFO = 415,
     IRCD_SID = 416,
     TKLINE_EXPIRE_NOTICES = 417,
     T_SHARED = 418,
     T_CLUSTER = 419,
     TYPE = 420,
     SHORT_MOTD = 421,
     SILENT = 422,
     SPOOF = 423,
     SPOOF_NOTICE = 424,
     STATS_E_DISABLED = 425,
     STATS_I_OPER_ONLY = 426,
     STATS_K_OPER_ONLY = 427,
     STATS_O_OPER_ONLY = 428,
     STATS_P_OPER_ONLY = 429,
     TBOOL = 430,
     TMASKED = 431,
     T_REJECT = 432,
     TS_MAX_DELTA = 433,
     TS_WARN_DELTA = 434,
     TWODOTS = 435,
     T_ALL = 436,
     T_BOTS = 437,
     T_SOFTCALLERID = 438,
     T_CALLERID = 439,
     T_CCONN = 440,
     T_CCONN_FULL = 441,
     T_SSL_CIPHER_LIST = 442,
     T_CLIENT_FLOOD = 443,
     T_DEAF = 444,
     T_DEBUG = 445,
     T_DLINE = 446,
     T_DRONE = 447,
     T_EXTERNAL = 448,
     T_FULL = 449,
     T_INVISIBLE = 450,
     T_IPV4 = 451,
     T_IPV6 = 452,
     T_LOCOPS = 453,
     T_MAX_CLIENTS = 454,
     T_NCHANGE = 455,
     T_OPERWALL = 456,
     T_REJ = 457,
     T_SERVER = 458,
     T_SERVNOTICE = 459,
     T_SKILL = 460,
     T_SPY = 461,
     T_SSL = 462,
     T_UMODES = 463,
     T_UNAUTH = 464,
     T_UNDLINE = 465,
     T_UNLIMITED = 466,
     T_UNRESV = 467,
     T_UNXLINE = 468,
     T_GLOBOPS = 469,
     T_WALLOP = 470,
     T_RESTART = 471,
     T_SERVICE = 472,
     T_SERVICES_NAME = 473,
     THROTTLE_TIME = 474,
     TOPICBURST = 475,
     TRUE_NO_OPER_FLOOD = 476,
     TKLINE = 477,
     TXLINE = 478,
     TRESV = 479,
     UNKLINE = 480,
     USER = 481,
     USE_EGD = 482,
     USE_EXCEPT = 483,
     USE_INVEX = 484,
     USE_KNOCK = 485,
     USE_LOGGING = 486,
     USE_WHOIS_ACTUALLY = 487,
     VHOST = 488,
     VHOST6 = 489,
     XLINE = 490,
     WARN = 491,
     WARN_NO_NLINE = 492,
     T_SIZE = 493,
     T_FILE = 494
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ACTION 259
#define ADMIN 260
#define AFTYPE 261
#define T_ALLOW 262
#define ANTI_NICK_FLOOD 263
#define ANTI_SPAM_EXIT_MESSAGE_TIME 264
#define AUTOCONN 265
#define T_BLOCK 266
#define BURST_AWAY 267
#define BYTES 268
#define KBYTES 269
#define MBYTES 270
#define GBYTES 271
#define TBYTES 272
#define CALLER_ID_WAIT 273
#define CAN_FLOOD 274
#define CHANNEL 275
#define CIDR_BITLEN_IPV4 276
#define CIDR_BITLEN_IPV6 277
#define CLASS 278
#define CONNECT 279
#define CONNECTFREQ 280
#define DEFAULT_FLOODCOUNT 281
#define DEFAULT_SPLIT_SERVER_COUNT 282
#define DEFAULT_SPLIT_USER_COUNT 283
#define DENY 284
#define DESCRIPTION 285
#define DIE 286
#define DISABLE_AUTH 287
#define DISABLE_FAKE_CHANNELS 288
#define DISABLE_HIDDEN 289
#define DISABLE_LOCAL_CHANNELS 290
#define DISABLE_REMOTE_COMMANDS 291
#define DOTS_IN_IDENT 292
#define DURATION 293
#define EGDPOOL_PATH 294
#define EMAIL 295
#define ENABLE 296
#define ENCRYPTED 297
#define EXCEED_LIMIT 298
#define EXEMPT 299
#define FAILED_OPER_NOTICE 300
#define IRCD_FLAGS 301
#define FLATTEN_LINKS 302
#define GECOS 303
#define GENERAL 304
#define GLINE 305
#define GLINES 306
#define GLINE_EXEMPT 307
#define GLINE_TIME 308
#define GLINE_MIN_CIDR 309
#define GLINE_MIN_CIDR6 310
#define GLOBAL_KILL 311
#define IRCD_AUTH 312
#define NEED_IDENT 313
#define HAVENT_READ_CONF 314
#define HIDDEN 315
#define HIDDEN_NAME 316
#define HIDE_SERVER_IPS 317
#define HIDE_SERVERS 318
#define HIDE_SPOOF_IPS 319
#define HOST 320
#define HUB 321
#define HUB_MASK 322
#define IGNORE_BOGUS_TS 323
#define INVISIBLE_ON_CONNECT 324
#define IP 325
#define KILL 326
#define KILL_CHASE_TIME_LIMIT 327
#define KLINE 328
#define KLINE_EXEMPT 329
#define KLINE_REASON 330
#define KLINE_WITH_REASON 331
#define KNOCK_DELAY 332
#define KNOCK_DELAY_CHANNEL 333
#define LEAF_MASK 334
#define LINKS_DELAY 335
#define LISTEN 336
#define T_LOG 337
#define MAX_ACCEPT 338
#define MAX_BANS 339
#define MAX_CHANS_PER_USER 340
#define MAX_GLOBAL 341
#define MAX_IDENT 342
#define MAX_LOCAL 343
#define MAX_NICK_CHANGES 344
#define MAX_NICK_TIME 345
#define MAX_NUMBER 346
#define MAX_TARGETS 347
#define MAX_WATCH 348
#define MESSAGE_LOCALE 349
#define MIN_NONWILDCARD 350
#define MIN_NONWILDCARD_SIMPLE 351
#define MODULE 352
#define MODULES 353
#define NAME 354
#define NEED_PASSWORD 355
#define NETWORK_DESC 356
#define NETWORK_NAME 357
#define NICK 358
#define NICK_CHANGES 359
#define NO_CREATE_ON_SPLIT 360
#define NO_JOIN_ON_SPLIT 361
#define NO_OPER_FLOOD 362
#define NO_TILDE 363
#define NUMBER 364
#define NUMBER_PER_IDENT 365
#define NUMBER_PER_CIDR 366
#define NUMBER_PER_IP 367
#define NUMBER_PER_IP_GLOBAL 368
#define OPERATOR 369
#define OPERS_BYPASS_CALLERID 370
#define OPER_ONLY_UMODES 371
#define OPER_PASS_RESV 372
#define OPER_SPY_T 373
#define OPER_UMODES 374
#define JOIN_FLOOD_COUNT 375
#define JOIN_FLOOD_TIME 376
#define PACE_WAIT 377
#define PACE_WAIT_SIMPLE 378
#define PASSWORD 379
#define PATH 380
#define PING_COOKIE 381
#define PING_TIME 382
#define PING_WARNING 383
#define PORT 384
#define QSTRING 385
#define QUIET_ON_BAN 386
#define REASON 387
#define REDIRPORT 388
#define REDIRSERV 389
#define REGEX_T 390
#define REHASH 391
#define TREJECT_HOLD_TIME 392
#define REMOTE 393
#define REMOTEBAN 394
#define RESTRICT_CHANNELS 395
#define RESTRICTED 396
#define RSA_PRIVATE_KEY_FILE 397
#define RSA_PUBLIC_KEY_FILE 398
#define SSL_CERTIFICATE_FILE 399
#define SSL_DH_PARAM_FILE 400
#define T_SSL_CLIENT_METHOD 401
#define T_SSL_SERVER_METHOD 402
#define T_SSLV3 403
#define T_TLSV1 404
#define RESV 405
#define RESV_EXEMPT 406
#define SECONDS 407
#define MINUTES 408
#define HOURS 409
#define DAYS 410
#define WEEKS 411
#define SENDQ 412
#define SEND_PASSWORD 413
#define SERVERHIDE 414
#define SERVERINFO 415
#define IRCD_SID 416
#define TKLINE_EXPIRE_NOTICES 417
#define T_SHARED 418
#define T_CLUSTER 419
#define TYPE 420
#define SHORT_MOTD 421
#define SILENT 422
#define SPOOF 423
#define SPOOF_NOTICE 424
#define STATS_E_DISABLED 425
#define STATS_I_OPER_ONLY 426
#define STATS_K_OPER_ONLY 427
#define STATS_O_OPER_ONLY 428
#define STATS_P_OPER_ONLY 429
#define TBOOL 430
#define TMASKED 431
#define T_REJECT 432
#define TS_MAX_DELTA 433
#define TS_WARN_DELTA 434
#define TWODOTS 435
#define T_ALL 436
#define T_BOTS 437
#define T_SOFTCALLERID 438
#define T_CALLERID 439
#define T_CCONN 440
#define T_CCONN_FULL 441
#define T_SSL_CIPHER_LIST 442
#define T_CLIENT_FLOOD 443
#define T_DEAF 444
#define T_DEBUG 445
#define T_DLINE 446
#define T_DRONE 447
#define T_EXTERNAL 448
#define T_FULL 449
#define T_INVISIBLE 450
#define T_IPV4 451
#define T_IPV6 452
#define T_LOCOPS 453
#define T_MAX_CLIENTS 454
#define T_NCHANGE 455
#define T_OPERWALL 456
#define T_REJ 457
#define T_SERVER 458
#define T_SERVNOTICE 459
#define T_SKILL 460
#define T_SPY 461
#define T_SSL 462
#define T_UMODES 463
#define T_UNAUTH 464
#define T_UNDLINE 465
#define T_UNLIMITED 466
#define T_UNRESV 467
#define T_UNXLINE 468
#define T_GLOBOPS 469
#define T_WALLOP 470
#define T_RESTART 471
#define T_SERVICE 472
#define T_SERVICES_NAME 473
#define THROTTLE_TIME 474
#define TOPICBURST 475
#define TRUE_NO_OPER_FLOOD 476
#define TKLINE 477
#define TXLINE 478
#define TRESV 479
#define UNKLINE 480
#define USER 481
#define USE_EGD 482
#define USE_EXCEPT 483
#define USE_INVEX 484
#define USE_KNOCK 485
#define USE_LOGGING 486
#define USE_WHOIS_ACTUALLY 487
#define VHOST 488
#define VHOST6 489
#define XLINE 490
#define WARN 491
#define WARN_NO_NLINE 492
#define T_SIZE 493
#define T_FILE 494




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 535 "conf_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


