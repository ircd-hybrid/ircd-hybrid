/* A Bison parser, made by GNU Bison 2.6.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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

#ifndef YY_CONF_PARSER_H
# define YY_CONF_PARSER_H
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

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
     GLINE_DURATION = 306,
     GLINE_ENABLE = 307,
     GLINE_EXEMPT = 308,
     GLINE_TIME = 309,
     GLINE_REQUEST_DURATION = 310,
     GLINE_MIN_CIDR = 311,
     GLINE_MIN_CIDR6 = 312,
     GLOBAL_KILL = 313,
     IRCD_AUTH = 314,
     NEED_IDENT = 315,
     HAVENT_READ_CONF = 316,
     HIDDEN = 317,
     HIDDEN_NAME = 318,
     HIDE_SERVER_IPS = 319,
     HIDE_SERVERS = 320,
     HIDE_SPOOF_IPS = 321,
     HOST = 322,
     HUB = 323,
     HUB_MASK = 324,
     IGNORE_BOGUS_TS = 325,
     INVISIBLE_ON_CONNECT = 326,
     IP = 327,
     KILL = 328,
     KILL_CHASE_TIME_LIMIT = 329,
     KLINE = 330,
     KLINE_EXEMPT = 331,
     KLINE_REASON = 332,
     KLINE_WITH_REASON = 333,
     KNOCK_DELAY = 334,
     KNOCK_DELAY_CHANNEL = 335,
     LEAF_MASK = 336,
     LINKS_DELAY = 337,
     LISTEN = 338,
     T_LOG = 339,
     MAX_ACCEPT = 340,
     MAX_BANS = 341,
     MAX_CHANS_PER_OPER = 342,
     MAX_CHANS_PER_USER = 343,
     MAX_GLOBAL = 344,
     MAX_IDENT = 345,
     MAX_LOCAL = 346,
     MAX_NICK_CHANGES = 347,
     MAX_NICK_TIME = 348,
     MAX_NUMBER = 349,
     MAX_TARGETS = 350,
     MAX_WATCH = 351,
     MESSAGE_LOCALE = 352,
     MIN_NONWILDCARD = 353,
     MIN_NONWILDCARD_SIMPLE = 354,
     MODULE = 355,
     MODULES = 356,
     NAME = 357,
     NEED_PASSWORD = 358,
     NETWORK_DESC = 359,
     NETWORK_NAME = 360,
     NICK = 361,
     NICK_CHANGES = 362,
     NO_CREATE_ON_SPLIT = 363,
     NO_JOIN_ON_SPLIT = 364,
     NO_OPER_FLOOD = 365,
     NO_TILDE = 366,
     NUMBER = 367,
     NUMBER_PER_IDENT = 368,
     NUMBER_PER_CIDR = 369,
     NUMBER_PER_IP = 370,
     NUMBER_PER_IP_GLOBAL = 371,
     OPERATOR = 372,
     OPERS_BYPASS_CALLERID = 373,
     OPER_ONLY_UMODES = 374,
     OPER_PASS_RESV = 375,
     OPER_SPY_T = 376,
     OPER_UMODES = 377,
     JOIN_FLOOD_COUNT = 378,
     JOIN_FLOOD_TIME = 379,
     PACE_WAIT = 380,
     PACE_WAIT_SIMPLE = 381,
     PASSWORD = 382,
     PATH = 383,
     PING_COOKIE = 384,
     PING_TIME = 385,
     PING_WARNING = 386,
     PORT = 387,
     QSTRING = 388,
     QUIET_ON_BAN = 389,
     REASON = 390,
     REDIRPORT = 391,
     REDIRSERV = 392,
     REGEX_T = 393,
     REHASH = 394,
     TREJECT_HOLD_TIME = 395,
     REMOTE = 396,
     REMOTEBAN = 397,
     RESTRICT_CHANNELS = 398,
     RESTRICTED = 399,
     RSA_PRIVATE_KEY_FILE = 400,
     RSA_PUBLIC_KEY_FILE = 401,
     SSL_CERTIFICATE_FILE = 402,
     SSL_DH_PARAM_FILE = 403,
     T_SSL_CLIENT_METHOD = 404,
     T_SSL_SERVER_METHOD = 405,
     T_SSLV3 = 406,
     T_TLSV1 = 407,
     RESV = 408,
     RESV_EXEMPT = 409,
     SECONDS = 410,
     MINUTES = 411,
     HOURS = 412,
     DAYS = 413,
     WEEKS = 414,
     SENDQ = 415,
     SEND_PASSWORD = 416,
     SERVERHIDE = 417,
     SERVERINFO = 418,
     IRCD_SID = 419,
     TKLINE_EXPIRE_NOTICES = 420,
     T_SHARED = 421,
     T_CLUSTER = 422,
     TYPE = 423,
     SHORT_MOTD = 424,
     SILENT = 425,
     SPOOF = 426,
     SPOOF_NOTICE = 427,
     STATS_E_DISABLED = 428,
     STATS_I_OPER_ONLY = 429,
     STATS_K_OPER_ONLY = 430,
     STATS_O_OPER_ONLY = 431,
     STATS_P_OPER_ONLY = 432,
     TBOOL = 433,
     TMASKED = 434,
     T_REJECT = 435,
     TS_MAX_DELTA = 436,
     TS_WARN_DELTA = 437,
     TWODOTS = 438,
     T_ALL = 439,
     T_BOTS = 440,
     T_SOFTCALLERID = 441,
     T_CALLERID = 442,
     T_CCONN = 443,
     T_CCONN_FULL = 444,
     T_SSL_CIPHER_LIST = 445,
     T_CLIENT_FLOOD = 446,
     T_DEAF = 447,
     T_DEBUG = 448,
     T_DLINE = 449,
     T_DRONE = 450,
     T_EXTERNAL = 451,
     T_FULL = 452,
     T_INVISIBLE = 453,
     T_IPV4 = 454,
     T_IPV6 = 455,
     T_LOCOPS = 456,
     T_MAX_CLIENTS = 457,
     T_NCHANGE = 458,
     T_OPERWALL = 459,
     T_REJ = 460,
     T_SERVER = 461,
     T_SERVNOTICE = 462,
     T_SET = 463,
     T_SKILL = 464,
     T_SPY = 465,
     T_SSL = 466,
     T_UMODES = 467,
     T_UNAUTH = 468,
     T_UNDLINE = 469,
     T_UNLIMITED = 470,
     T_UNRESV = 471,
     T_UNXLINE = 472,
     T_GLOBOPS = 473,
     T_WALLOP = 474,
     T_RESTART = 475,
     T_SERVICE = 476,
     T_SERVICES_NAME = 477,
     THROTTLE_TIME = 478,
     TOPICBURST = 479,
     TRUE_NO_OPER_FLOOD = 480,
     TKLINE = 481,
     TXLINE = 482,
     TRESV = 483,
     UNKLINE = 484,
     USER = 485,
     USE_EGD = 486,
     USE_EXCEPT = 487,
     USE_INVEX = 488,
     USE_KNOCK = 489,
     USE_LOGGING = 490,
     USE_WHOIS_ACTUALLY = 491,
     VHOST = 492,
     VHOST6 = 493,
     XLINE = 494,
     WARN = 495,
     WARN_NO_NLINE = 496,
     T_SIZE = 497,
     T_FILE = 498
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
#define GLINE_DURATION 306
#define GLINE_ENABLE 307
#define GLINE_EXEMPT 308
#define GLINE_TIME 309
#define GLINE_REQUEST_DURATION 310
#define GLINE_MIN_CIDR 311
#define GLINE_MIN_CIDR6 312
#define GLOBAL_KILL 313
#define IRCD_AUTH 314
#define NEED_IDENT 315
#define HAVENT_READ_CONF 316
#define HIDDEN 317
#define HIDDEN_NAME 318
#define HIDE_SERVER_IPS 319
#define HIDE_SERVERS 320
#define HIDE_SPOOF_IPS 321
#define HOST 322
#define HUB 323
#define HUB_MASK 324
#define IGNORE_BOGUS_TS 325
#define INVISIBLE_ON_CONNECT 326
#define IP 327
#define KILL 328
#define KILL_CHASE_TIME_LIMIT 329
#define KLINE 330
#define KLINE_EXEMPT 331
#define KLINE_REASON 332
#define KLINE_WITH_REASON 333
#define KNOCK_DELAY 334
#define KNOCK_DELAY_CHANNEL 335
#define LEAF_MASK 336
#define LINKS_DELAY 337
#define LISTEN 338
#define T_LOG 339
#define MAX_ACCEPT 340
#define MAX_BANS 341
#define MAX_CHANS_PER_OPER 342
#define MAX_CHANS_PER_USER 343
#define MAX_GLOBAL 344
#define MAX_IDENT 345
#define MAX_LOCAL 346
#define MAX_NICK_CHANGES 347
#define MAX_NICK_TIME 348
#define MAX_NUMBER 349
#define MAX_TARGETS 350
#define MAX_WATCH 351
#define MESSAGE_LOCALE 352
#define MIN_NONWILDCARD 353
#define MIN_NONWILDCARD_SIMPLE 354
#define MODULE 355
#define MODULES 356
#define NAME 357
#define NEED_PASSWORD 358
#define NETWORK_DESC 359
#define NETWORK_NAME 360
#define NICK 361
#define NICK_CHANGES 362
#define NO_CREATE_ON_SPLIT 363
#define NO_JOIN_ON_SPLIT 364
#define NO_OPER_FLOOD 365
#define NO_TILDE 366
#define NUMBER 367
#define NUMBER_PER_IDENT 368
#define NUMBER_PER_CIDR 369
#define NUMBER_PER_IP 370
#define NUMBER_PER_IP_GLOBAL 371
#define OPERATOR 372
#define OPERS_BYPASS_CALLERID 373
#define OPER_ONLY_UMODES 374
#define OPER_PASS_RESV 375
#define OPER_SPY_T 376
#define OPER_UMODES 377
#define JOIN_FLOOD_COUNT 378
#define JOIN_FLOOD_TIME 379
#define PACE_WAIT 380
#define PACE_WAIT_SIMPLE 381
#define PASSWORD 382
#define PATH 383
#define PING_COOKIE 384
#define PING_TIME 385
#define PING_WARNING 386
#define PORT 387
#define QSTRING 388
#define QUIET_ON_BAN 389
#define REASON 390
#define REDIRPORT 391
#define REDIRSERV 392
#define REGEX_T 393
#define REHASH 394
#define TREJECT_HOLD_TIME 395
#define REMOTE 396
#define REMOTEBAN 397
#define RESTRICT_CHANNELS 398
#define RESTRICTED 399
#define RSA_PRIVATE_KEY_FILE 400
#define RSA_PUBLIC_KEY_FILE 401
#define SSL_CERTIFICATE_FILE 402
#define SSL_DH_PARAM_FILE 403
#define T_SSL_CLIENT_METHOD 404
#define T_SSL_SERVER_METHOD 405
#define T_SSLV3 406
#define T_TLSV1 407
#define RESV 408
#define RESV_EXEMPT 409
#define SECONDS 410
#define MINUTES 411
#define HOURS 412
#define DAYS 413
#define WEEKS 414
#define SENDQ 415
#define SEND_PASSWORD 416
#define SERVERHIDE 417
#define SERVERINFO 418
#define IRCD_SID 419
#define TKLINE_EXPIRE_NOTICES 420
#define T_SHARED 421
#define T_CLUSTER 422
#define TYPE 423
#define SHORT_MOTD 424
#define SILENT 425
#define SPOOF 426
#define SPOOF_NOTICE 427
#define STATS_E_DISABLED 428
#define STATS_I_OPER_ONLY 429
#define STATS_K_OPER_ONLY 430
#define STATS_O_OPER_ONLY 431
#define STATS_P_OPER_ONLY 432
#define TBOOL 433
#define TMASKED 434
#define T_REJECT 435
#define TS_MAX_DELTA 436
#define TS_WARN_DELTA 437
#define TWODOTS 438
#define T_ALL 439
#define T_BOTS 440
#define T_SOFTCALLERID 441
#define T_CALLERID 442
#define T_CCONN 443
#define T_CCONN_FULL 444
#define T_SSL_CIPHER_LIST 445
#define T_CLIENT_FLOOD 446
#define T_DEAF 447
#define T_DEBUG 448
#define T_DLINE 449
#define T_DRONE 450
#define T_EXTERNAL 451
#define T_FULL 452
#define T_INVISIBLE 453
#define T_IPV4 454
#define T_IPV6 455
#define T_LOCOPS 456
#define T_MAX_CLIENTS 457
#define T_NCHANGE 458
#define T_OPERWALL 459
#define T_REJ 460
#define T_SERVER 461
#define T_SERVNOTICE 462
#define T_SET 463
#define T_SKILL 464
#define T_SPY 465
#define T_SSL 466
#define T_UMODES 467
#define T_UNAUTH 468
#define T_UNDLINE 469
#define T_UNLIMITED 470
#define T_UNRESV 471
#define T_UNXLINE 472
#define T_GLOBOPS 473
#define T_WALLOP 474
#define T_RESTART 475
#define T_SERVICE 476
#define T_SERVICES_NAME 477
#define THROTTLE_TIME 478
#define TOPICBURST 479
#define TRUE_NO_OPER_FLOOD 480
#define TKLINE 481
#define TXLINE 482
#define TRESV 483
#define UNKLINE 484
#define USER 485
#define USE_EGD 486
#define USE_EXCEPT 487
#define USE_INVEX 488
#define USE_KNOCK 489
#define USE_LOGGING 490
#define USE_WHOIS_ACTUALLY 491
#define VHOST 492
#define VHOST6 493
#define XLINE 494
#define WARN 495
#define WARN_NO_NLINE 496
#define T_SIZE 497
#define T_FILE 498



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2050 of yacc.c  */
#line 110 "conf_parser.y"

  int number;
  char *string;



/* Line 2050 of yacc.c  */
#line 551 "conf_parser.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_CONF_PARSER_H  */
