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
     BURST_TOPICWHO = 268,
     BYTES = 269,
     KBYTES = 270,
     MBYTES = 271,
     GBYTES = 272,
     TBYTES = 273,
     CALLER_ID_WAIT = 274,
     CAN_FLOOD = 275,
     CAN_IDLE = 276,
     CHANNEL = 277,
     CIDR_BITLEN_IPV4 = 278,
     CIDR_BITLEN_IPV6 = 279,
     CIPHER_PREFERENCE = 280,
     CLASS = 281,
     COMPRESSED = 282,
     COMPRESSION_LEVEL = 283,
     CONNECT = 284,
     CONNECTFREQ = 285,
     CRYPTLINK = 286,
     DEFAULT_CIPHER_PREFERENCE = 287,
     DEFAULT_FLOODCOUNT = 288,
     DEFAULT_SPLIT_SERVER_COUNT = 289,
     DEFAULT_SPLIT_USER_COUNT = 290,
     DENY = 291,
     DESCRIPTION = 292,
     DIE = 293,
     DISABLE_AUTH = 294,
     DISABLE_FAKE_CHANNELS = 295,
     DISABLE_HIDDEN = 296,
     DISABLE_LOCAL_CHANNELS = 297,
     DISABLE_REMOTE_COMMANDS = 298,
     DOTS_IN_IDENT = 299,
     DURATION = 300,
     EGDPOOL_PATH = 301,
     EMAIL = 302,
     ENABLE = 303,
     ENCRYPTED = 304,
     EXCEED_LIMIT = 305,
     EXEMPT = 306,
     FAILED_OPER_NOTICE = 307,
     IRCD_FLAGS = 308,
     FLATTEN_LINKS = 309,
     FFAILED_OPERLOG = 310,
     FKILLLOG = 311,
     FKLINELOG = 312,
     FGLINELOG = 313,
     FIOERRLOG = 314,
     FOPERLOG = 315,
     FOPERSPYLOG = 316,
     FUSERLOG = 317,
     GECOS = 318,
     GENERAL = 319,
     GLINE = 320,
     GLINES = 321,
     GLINE_EXEMPT = 322,
     GLINE_LOG = 323,
     GLINE_TIME = 324,
     GLINE_MIN_CIDR = 325,
     GLINE_MIN_CIDR6 = 326,
     GLOBAL_KILL = 327,
     IRCD_AUTH = 328,
     NEED_IDENT = 329,
     HAVENT_READ_CONF = 330,
     HIDDEN = 331,
     HIDDEN_ADMIN = 332,
     HIDDEN_NAME = 333,
     HIDDEN_OPER = 334,
     HIDE_SERVER_IPS = 335,
     HIDE_SERVERS = 336,
     HIDE_SPOOF_IPS = 337,
     HOST = 338,
     HUB = 339,
     HUB_MASK = 340,
     IDLETIME = 341,
     IGNORE_BOGUS_TS = 342,
     INVISIBLE_ON_CONNECT = 343,
     IP = 344,
     KILL = 345,
     KILL_CHASE_TIME_LIMIT = 346,
     KLINE = 347,
     KLINE_EXEMPT = 348,
     KLINE_REASON = 349,
     KLINE_WITH_REASON = 350,
     KNOCK_DELAY = 351,
     KNOCK_DELAY_CHANNEL = 352,
     LEAF_MASK = 353,
     LINKS_DELAY = 354,
     LISTEN = 355,
     T_LOG = 356,
     LOGGING = 357,
     LOG_LEVEL = 358,
     MAX_ACCEPT = 359,
     MAX_BANS = 360,
     MAX_CHANS_PER_USER = 361,
     MAX_GLOBAL = 362,
     MAX_IDENT = 363,
     MAX_LOCAL = 364,
     MAX_NICK_CHANGES = 365,
     MAX_NICK_TIME = 366,
     MAX_NUMBER = 367,
     MAX_TARGETS = 368,
     MAX_WATCH = 369,
     MESSAGE_LOCALE = 370,
     MIN_NONWILDCARD = 371,
     MIN_NONWILDCARD_SIMPLE = 372,
     MODULE = 373,
     MODULES = 374,
     NAME = 375,
     NEED_PASSWORD = 376,
     NETWORK_DESC = 377,
     NETWORK_NAME = 378,
     NICK = 379,
     NICK_CHANGES = 380,
     NO_CREATE_ON_SPLIT = 381,
     NO_JOIN_ON_SPLIT = 382,
     NO_OPER_FLOOD = 383,
     NO_TILDE = 384,
     NOT = 385,
     NUMBER = 386,
     NUMBER_PER_IDENT = 387,
     NUMBER_PER_CIDR = 388,
     NUMBER_PER_IP = 389,
     NUMBER_PER_IP_GLOBAL = 390,
     OPERATOR = 391,
     OPERS_BYPASS_CALLERID = 392,
     OPER_LOG = 393,
     OPER_ONLY_UMODES = 394,
     OPER_PASS_RESV = 395,
     OPER_SPY_T = 396,
     OPER_UMODES = 397,
     JOIN_FLOOD_COUNT = 398,
     JOIN_FLOOD_TIME = 399,
     PACE_WAIT = 400,
     PACE_WAIT_SIMPLE = 401,
     PASSWORD = 402,
     PATH = 403,
     PING_COOKIE = 404,
     PING_TIME = 405,
     PING_WARNING = 406,
     PORT = 407,
     QSTRING = 408,
     QUIET_ON_BAN = 409,
     REASON = 410,
     REDIRPORT = 411,
     REDIRSERV = 412,
     REGEX_T = 413,
     REHASH = 414,
     TREJECT_HOLD_TIME = 415,
     REMOTE = 416,
     REMOTEBAN = 417,
     RESTRICT_CHANNELS = 418,
     RESTRICTED = 419,
     RSA_PRIVATE_KEY_FILE = 420,
     RSA_PUBLIC_KEY_FILE = 421,
     SSL_CERTIFICATE_FILE = 422,
     T_SSL_CONNECTION_METHOD = 423,
     T_SSLV3 = 424,
     T_TLSV1 = 425,
     RESV = 426,
     RESV_EXEMPT = 427,
     SECONDS = 428,
     MINUTES = 429,
     HOURS = 430,
     DAYS = 431,
     WEEKS = 432,
     SENDQ = 433,
     SEND_PASSWORD = 434,
     SERVERHIDE = 435,
     SERVERINFO = 436,
     SERVLINK_PATH = 437,
     IRCD_SID = 438,
     TKLINE_EXPIRE_NOTICES = 439,
     T_SHARED = 440,
     T_CLUSTER = 441,
     TYPE = 442,
     SHORT_MOTD = 443,
     SILENT = 444,
     SPOOF = 445,
     SPOOF_NOTICE = 446,
     STATS_E_DISABLED = 447,
     STATS_I_OPER_ONLY = 448,
     STATS_K_OPER_ONLY = 449,
     STATS_O_OPER_ONLY = 450,
     STATS_P_OPER_ONLY = 451,
     TBOOL = 452,
     TMASKED = 453,
     T_REJECT = 454,
     TS_MAX_DELTA = 455,
     TS_WARN_DELTA = 456,
     TWODOTS = 457,
     T_ALL = 458,
     T_BOTS = 459,
     T_SOFTCALLERID = 460,
     T_CALLERID = 461,
     T_CCONN = 462,
     T_CCONN_FULL = 463,
     T_CLIENT_FLOOD = 464,
     T_DEAF = 465,
     T_DEBUG = 466,
     T_DRONE = 467,
     T_EXTERNAL = 468,
     T_FULL = 469,
     T_INVISIBLE = 470,
     T_IPV4 = 471,
     T_IPV6 = 472,
     T_LOCOPS = 473,
     T_LOGPATH = 474,
     T_L_CRIT = 475,
     T_L_DEBUG = 476,
     T_L_ERROR = 477,
     T_L_INFO = 478,
     T_L_NOTICE = 479,
     T_L_TRACE = 480,
     T_L_WARN = 481,
     T_MAX_CLIENTS = 482,
     T_NCHANGE = 483,
     T_OPERWALL = 484,
     T_REJ = 485,
     T_SERVER = 486,
     T_SERVNOTICE = 487,
     T_SKILL = 488,
     T_SPY = 489,
     T_SSL = 490,
     T_UMODES = 491,
     T_UNAUTH = 492,
     T_UNRESV = 493,
     T_UNXLINE = 494,
     T_WALLOP = 495,
     THROTTLE_TIME = 496,
     TOPICBURST = 497,
     TRUE_NO_OPER_FLOOD = 498,
     TKLINE = 499,
     TXLINE = 500,
     TRESV = 501,
     UNKLINE = 502,
     USER = 503,
     USE_EGD = 504,
     USE_EXCEPT = 505,
     USE_INVEX = 506,
     USE_KNOCK = 507,
     USE_LOGGING = 508,
     USE_WHOIS_ACTUALLY = 509,
     VHOST = 510,
     VHOST6 = 511,
     XLINE = 512,
     WARN = 513,
     WARN_NO_NLINE = 514
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
#define BURST_TOPICWHO 268
#define BYTES 269
#define KBYTES 270
#define MBYTES 271
#define GBYTES 272
#define TBYTES 273
#define CALLER_ID_WAIT 274
#define CAN_FLOOD 275
#define CAN_IDLE 276
#define CHANNEL 277
#define CIDR_BITLEN_IPV4 278
#define CIDR_BITLEN_IPV6 279
#define CIPHER_PREFERENCE 280
#define CLASS 281
#define COMPRESSED 282
#define COMPRESSION_LEVEL 283
#define CONNECT 284
#define CONNECTFREQ 285
#define CRYPTLINK 286
#define DEFAULT_CIPHER_PREFERENCE 287
#define DEFAULT_FLOODCOUNT 288
#define DEFAULT_SPLIT_SERVER_COUNT 289
#define DEFAULT_SPLIT_USER_COUNT 290
#define DENY 291
#define DESCRIPTION 292
#define DIE 293
#define DISABLE_AUTH 294
#define DISABLE_FAKE_CHANNELS 295
#define DISABLE_HIDDEN 296
#define DISABLE_LOCAL_CHANNELS 297
#define DISABLE_REMOTE_COMMANDS 298
#define DOTS_IN_IDENT 299
#define DURATION 300
#define EGDPOOL_PATH 301
#define EMAIL 302
#define ENABLE 303
#define ENCRYPTED 304
#define EXCEED_LIMIT 305
#define EXEMPT 306
#define FAILED_OPER_NOTICE 307
#define IRCD_FLAGS 308
#define FLATTEN_LINKS 309
#define FFAILED_OPERLOG 310
#define FKILLLOG 311
#define FKLINELOG 312
#define FGLINELOG 313
#define FIOERRLOG 314
#define FOPERLOG 315
#define FOPERSPYLOG 316
#define FUSERLOG 317
#define GECOS 318
#define GENERAL 319
#define GLINE 320
#define GLINES 321
#define GLINE_EXEMPT 322
#define GLINE_LOG 323
#define GLINE_TIME 324
#define GLINE_MIN_CIDR 325
#define GLINE_MIN_CIDR6 326
#define GLOBAL_KILL 327
#define IRCD_AUTH 328
#define NEED_IDENT 329
#define HAVENT_READ_CONF 330
#define HIDDEN 331
#define HIDDEN_ADMIN 332
#define HIDDEN_NAME 333
#define HIDDEN_OPER 334
#define HIDE_SERVER_IPS 335
#define HIDE_SERVERS 336
#define HIDE_SPOOF_IPS 337
#define HOST 338
#define HUB 339
#define HUB_MASK 340
#define IDLETIME 341
#define IGNORE_BOGUS_TS 342
#define INVISIBLE_ON_CONNECT 343
#define IP 344
#define KILL 345
#define KILL_CHASE_TIME_LIMIT 346
#define KLINE 347
#define KLINE_EXEMPT 348
#define KLINE_REASON 349
#define KLINE_WITH_REASON 350
#define KNOCK_DELAY 351
#define KNOCK_DELAY_CHANNEL 352
#define LEAF_MASK 353
#define LINKS_DELAY 354
#define LISTEN 355
#define T_LOG 356
#define LOGGING 357
#define LOG_LEVEL 358
#define MAX_ACCEPT 359
#define MAX_BANS 360
#define MAX_CHANS_PER_USER 361
#define MAX_GLOBAL 362
#define MAX_IDENT 363
#define MAX_LOCAL 364
#define MAX_NICK_CHANGES 365
#define MAX_NICK_TIME 366
#define MAX_NUMBER 367
#define MAX_TARGETS 368
#define MAX_WATCH 369
#define MESSAGE_LOCALE 370
#define MIN_NONWILDCARD 371
#define MIN_NONWILDCARD_SIMPLE 372
#define MODULE 373
#define MODULES 374
#define NAME 375
#define NEED_PASSWORD 376
#define NETWORK_DESC 377
#define NETWORK_NAME 378
#define NICK 379
#define NICK_CHANGES 380
#define NO_CREATE_ON_SPLIT 381
#define NO_JOIN_ON_SPLIT 382
#define NO_OPER_FLOOD 383
#define NO_TILDE 384
#define NOT 385
#define NUMBER 386
#define NUMBER_PER_IDENT 387
#define NUMBER_PER_CIDR 388
#define NUMBER_PER_IP 389
#define NUMBER_PER_IP_GLOBAL 390
#define OPERATOR 391
#define OPERS_BYPASS_CALLERID 392
#define OPER_LOG 393
#define OPER_ONLY_UMODES 394
#define OPER_PASS_RESV 395
#define OPER_SPY_T 396
#define OPER_UMODES 397
#define JOIN_FLOOD_COUNT 398
#define JOIN_FLOOD_TIME 399
#define PACE_WAIT 400
#define PACE_WAIT_SIMPLE 401
#define PASSWORD 402
#define PATH 403
#define PING_COOKIE 404
#define PING_TIME 405
#define PING_WARNING 406
#define PORT 407
#define QSTRING 408
#define QUIET_ON_BAN 409
#define REASON 410
#define REDIRPORT 411
#define REDIRSERV 412
#define REGEX_T 413
#define REHASH 414
#define TREJECT_HOLD_TIME 415
#define REMOTE 416
#define REMOTEBAN 417
#define RESTRICT_CHANNELS 418
#define RESTRICTED 419
#define RSA_PRIVATE_KEY_FILE 420
#define RSA_PUBLIC_KEY_FILE 421
#define SSL_CERTIFICATE_FILE 422
#define T_SSL_CONNECTION_METHOD 423
#define T_SSLV3 424
#define T_TLSV1 425
#define RESV 426
#define RESV_EXEMPT 427
#define SECONDS 428
#define MINUTES 429
#define HOURS 430
#define DAYS 431
#define WEEKS 432
#define SENDQ 433
#define SEND_PASSWORD 434
#define SERVERHIDE 435
#define SERVERINFO 436
#define SERVLINK_PATH 437
#define IRCD_SID 438
#define TKLINE_EXPIRE_NOTICES 439
#define T_SHARED 440
#define T_CLUSTER 441
#define TYPE 442
#define SHORT_MOTD 443
#define SILENT 444
#define SPOOF 445
#define SPOOF_NOTICE 446
#define STATS_E_DISABLED 447
#define STATS_I_OPER_ONLY 448
#define STATS_K_OPER_ONLY 449
#define STATS_O_OPER_ONLY 450
#define STATS_P_OPER_ONLY 451
#define TBOOL 452
#define TMASKED 453
#define T_REJECT 454
#define TS_MAX_DELTA 455
#define TS_WARN_DELTA 456
#define TWODOTS 457
#define T_ALL 458
#define T_BOTS 459
#define T_SOFTCALLERID 460
#define T_CALLERID 461
#define T_CCONN 462
#define T_CCONN_FULL 463
#define T_CLIENT_FLOOD 464
#define T_DEAF 465
#define T_DEBUG 466
#define T_DRONE 467
#define T_EXTERNAL 468
#define T_FULL 469
#define T_INVISIBLE 470
#define T_IPV4 471
#define T_IPV6 472
#define T_LOCOPS 473
#define T_LOGPATH 474
#define T_L_CRIT 475
#define T_L_DEBUG 476
#define T_L_ERROR 477
#define T_L_INFO 478
#define T_L_NOTICE 479
#define T_L_TRACE 480
#define T_L_WARN 481
#define T_MAX_CLIENTS 482
#define T_NCHANGE 483
#define T_OPERWALL 484
#define T_REJ 485
#define T_SERVER 486
#define T_SERVNOTICE 487
#define T_SKILL 488
#define T_SPY 489
#define T_SSL 490
#define T_UMODES 491
#define T_UNAUTH 492
#define T_UNRESV 493
#define T_UNXLINE 494
#define T_WALLOP 495
#define THROTTLE_TIME 496
#define TOPICBURST 497
#define TRUE_NO_OPER_FLOOD 498
#define TKLINE 499
#define TXLINE 500
#define TRESV 501
#define UNKLINE 502
#define USER 503
#define USE_EGD 504
#define USE_EXCEPT 505
#define USE_INVEX 506
#define USE_KNOCK 507
#define USE_LOGGING 508
#define USE_WHOIS_ACTUALLY 509
#define VHOST 510
#define VHOST6 511
#define XLINE 512
#define WARN 513
#define WARN_NO_NLINE 514




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 131 "ircd_parser.y"

  int number;
  char *string;



/* Line 2068 of yacc.c  */
#line 575 "ircd_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


