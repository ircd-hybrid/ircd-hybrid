/* A Bison parser, made by GNU Bison 2.7.  */

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

#ifndef YY_YY_CONF_PARSER_H_INCLUDED
# define YY_YY_CONF_PARSER_H_INCLUDED
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
     ADMIN = 259,
     AFTYPE = 260,
     ANTI_NICK_FLOOD = 261,
     ANTI_SPAM_EXIT_MESSAGE_TIME = 262,
     AUTOCONN = 263,
     BYTES = 264,
     KBYTES = 265,
     MBYTES = 266,
     CALLER_ID_WAIT = 267,
     CAN_FLOOD = 268,
     CHANNEL = 269,
     CIDR_BITLEN_IPV4 = 270,
     CIDR_BITLEN_IPV6 = 271,
     CLASS = 272,
     CONNECT = 273,
     CONNECTFREQ = 274,
     DEFAULT_FLOODCOUNT = 275,
     DEFAULT_SPLIT_SERVER_COUNT = 276,
     DEFAULT_SPLIT_USER_COUNT = 277,
     DENY = 278,
     DESCRIPTION = 279,
     DIE = 280,
     DISABLE_AUTH = 281,
     DISABLE_FAKE_CHANNELS = 282,
     DISABLE_REMOTE_COMMANDS = 283,
     DOTS_IN_IDENT = 284,
     EGDPOOL_PATH = 285,
     EMAIL = 286,
     ENCRYPTED = 287,
     EXCEED_LIMIT = 288,
     EXEMPT = 289,
     FAILED_OPER_NOTICE = 290,
     IRCD_FLAGS = 291,
     FLATTEN_LINKS = 292,
     GECOS = 293,
     GENERAL = 294,
     GLINE = 295,
     GLINE_DURATION = 296,
     GLINE_ENABLE = 297,
     GLINE_EXEMPT = 298,
     GLINE_REQUEST_DURATION = 299,
     GLINE_MIN_CIDR = 300,
     GLINE_MIN_CIDR6 = 301,
     GLOBAL_KILL = 302,
     IRCD_AUTH = 303,
     NEED_IDENT = 304,
     HAVENT_READ_CONF = 305,
     HIDDEN = 306,
     HIDDEN_NAME = 307,
     HIDE_SERVER_IPS = 308,
     HIDE_SERVERS = 309,
     HIDE_SPOOF_IPS = 310,
     HOST = 311,
     HUB = 312,
     HUB_MASK = 313,
     IGNORE_BOGUS_TS = 314,
     INVISIBLE_ON_CONNECT = 315,
     IP = 316,
     KILL = 317,
     KILL_CHASE_TIME_LIMIT = 318,
     KLINE = 319,
     KLINE_EXEMPT = 320,
     KNOCK_DELAY = 321,
     KNOCK_DELAY_CHANNEL = 322,
     LEAF_MASK = 323,
     LINKS_DELAY = 324,
     LISTEN = 325,
     T_LOG = 326,
     MAX_ACCEPT = 327,
     MAX_BANS = 328,
     MAX_CHANS_PER_OPER = 329,
     MAX_CHANS_PER_USER = 330,
     MAX_GLOBAL = 331,
     MAX_IDENT = 332,
     MAX_LOCAL = 333,
     MAX_NICK_CHANGES = 334,
     MAX_NICK_LENGTH = 335,
     MAX_NICK_TIME = 336,
     MAX_NUMBER = 337,
     MAX_TARGETS = 338,
     MAX_TOPIC_LENGTH = 339,
     MAX_WATCH = 340,
     MESSAGE_LOCALE = 341,
     MIN_NONWILDCARD = 342,
     MIN_NONWILDCARD_SIMPLE = 343,
     MIN_IDLE = 344,
     MAX_IDLE = 345,
     RANDOM_IDLE = 346,
     HIDE_IDLE_FROM_OPERS = 347,
     MODULE = 348,
     MODULES = 349,
     NAME = 350,
     NEED_PASSWORD = 351,
     NETWORK_DESC = 352,
     NETWORK_NAME = 353,
     NICK = 354,
     NICK_CHANGES = 355,
     NO_CREATE_ON_SPLIT = 356,
     NO_JOIN_ON_SPLIT = 357,
     NO_OPER_FLOOD = 358,
     NO_TILDE = 359,
     NUMBER = 360,
     NUMBER_PER_CIDR = 361,
     NUMBER_PER_IP = 362,
     OPERATOR = 363,
     OPERS_BYPASS_CALLERID = 364,
     OPER_ONLY_UMODES = 365,
     OPER_PASS_RESV = 366,
     OPER_SPY_T = 367,
     OPER_UMODES = 368,
     JOIN_FLOOD_COUNT = 369,
     JOIN_FLOOD_TIME = 370,
     PACE_WAIT = 371,
     PACE_WAIT_SIMPLE = 372,
     PASSWORD = 373,
     PATH = 374,
     PING_COOKIE = 375,
     PING_TIME = 376,
     PING_WARNING = 377,
     PORT = 378,
     QSTRING = 379,
     QUIET_ON_BAN = 380,
     REASON = 381,
     REDIRPORT = 382,
     REDIRSERV = 383,
     REGEX_T = 384,
     REHASH = 385,
     REMOTE = 386,
     REMOTEBAN = 387,
     RESTRICT_CHANNELS = 388,
     RSA_PRIVATE_KEY_FILE = 389,
     RSA_PUBLIC_KEY_FILE = 390,
     SSL_CERTIFICATE_FILE = 391,
     SSL_DH_PARAM_FILE = 392,
     T_SSL_CLIENT_METHOD = 393,
     T_SSL_SERVER_METHOD = 394,
     T_SSLV3 = 395,
     T_TLSV1 = 396,
     RESV = 397,
     RESV_EXEMPT = 398,
     SECONDS = 399,
     MINUTES = 400,
     HOURS = 401,
     DAYS = 402,
     WEEKS = 403,
     MONTHS = 404,
     YEARS = 405,
     SENDQ = 406,
     SEND_PASSWORD = 407,
     SERVERHIDE = 408,
     SERVERINFO = 409,
     IRCD_SID = 410,
     TKLINE_EXPIRE_NOTICES = 411,
     T_SHARED = 412,
     T_CLUSTER = 413,
     TYPE = 414,
     SHORT_MOTD = 415,
     SPOOF = 416,
     SPOOF_NOTICE = 417,
     STATS_E_DISABLED = 418,
     STATS_I_OPER_ONLY = 419,
     STATS_K_OPER_ONLY = 420,
     STATS_O_OPER_ONLY = 421,
     STATS_P_OPER_ONLY = 422,
     TBOOL = 423,
     TMASKED = 424,
     TS_MAX_DELTA = 425,
     TS_WARN_DELTA = 426,
     TWODOTS = 427,
     T_ALL = 428,
     T_BOTS = 429,
     T_SOFTCALLERID = 430,
     T_CALLERID = 431,
     T_CCONN = 432,
     T_CCONN_FULL = 433,
     T_SSL_CIPHER_LIST = 434,
     T_DEAF = 435,
     T_DEBUG = 436,
     T_DLINE = 437,
     T_EXTERNAL = 438,
     T_FULL = 439,
     T_INVISIBLE = 440,
     T_IPV4 = 441,
     T_IPV6 = 442,
     T_LOCOPS = 443,
     T_MAX_CLIENTS = 444,
     T_NCHANGE = 445,
     T_OPERWALL = 446,
     T_RECVQ = 447,
     T_REJ = 448,
     T_SERVER = 449,
     T_SERVNOTICE = 450,
     T_SET = 451,
     T_SKILL = 452,
     T_SPY = 453,
     T_SSL = 454,
     T_UMODES = 455,
     T_UNAUTH = 456,
     T_UNDLINE = 457,
     T_UNLIMITED = 458,
     T_UNRESV = 459,
     T_UNXLINE = 460,
     T_GLOBOPS = 461,
     T_WALLOP = 462,
     T_RESTART = 463,
     T_SERVICE = 464,
     T_SERVICES_NAME = 465,
     THROTTLE_TIME = 466,
     TRUE_NO_OPER_FLOOD = 467,
     UNKLINE = 468,
     USER = 469,
     USE_EGD = 470,
     USE_LOGGING = 471,
     VHOST = 472,
     VHOST6 = 473,
     XLINE = 474,
     WARN_NO_NLINE = 475,
     T_SIZE = 476,
     T_FILE = 477
   };
#endif
/* Tokens.  */
#define ACCEPT_PASSWORD 258
#define ADMIN 259
#define AFTYPE 260
#define ANTI_NICK_FLOOD 261
#define ANTI_SPAM_EXIT_MESSAGE_TIME 262
#define AUTOCONN 263
#define BYTES 264
#define KBYTES 265
#define MBYTES 266
#define CALLER_ID_WAIT 267
#define CAN_FLOOD 268
#define CHANNEL 269
#define CIDR_BITLEN_IPV4 270
#define CIDR_BITLEN_IPV6 271
#define CLASS 272
#define CONNECT 273
#define CONNECTFREQ 274
#define DEFAULT_FLOODCOUNT 275
#define DEFAULT_SPLIT_SERVER_COUNT 276
#define DEFAULT_SPLIT_USER_COUNT 277
#define DENY 278
#define DESCRIPTION 279
#define DIE 280
#define DISABLE_AUTH 281
#define DISABLE_FAKE_CHANNELS 282
#define DISABLE_REMOTE_COMMANDS 283
#define DOTS_IN_IDENT 284
#define EGDPOOL_PATH 285
#define EMAIL 286
#define ENCRYPTED 287
#define EXCEED_LIMIT 288
#define EXEMPT 289
#define FAILED_OPER_NOTICE 290
#define IRCD_FLAGS 291
#define FLATTEN_LINKS 292
#define GECOS 293
#define GENERAL 294
#define GLINE 295
#define GLINE_DURATION 296
#define GLINE_ENABLE 297
#define GLINE_EXEMPT 298
#define GLINE_REQUEST_DURATION 299
#define GLINE_MIN_CIDR 300
#define GLINE_MIN_CIDR6 301
#define GLOBAL_KILL 302
#define IRCD_AUTH 303
#define NEED_IDENT 304
#define HAVENT_READ_CONF 305
#define HIDDEN 306
#define HIDDEN_NAME 307
#define HIDE_SERVER_IPS 308
#define HIDE_SERVERS 309
#define HIDE_SPOOF_IPS 310
#define HOST 311
#define HUB 312
#define HUB_MASK 313
#define IGNORE_BOGUS_TS 314
#define INVISIBLE_ON_CONNECT 315
#define IP 316
#define KILL 317
#define KILL_CHASE_TIME_LIMIT 318
#define KLINE 319
#define KLINE_EXEMPT 320
#define KNOCK_DELAY 321
#define KNOCK_DELAY_CHANNEL 322
#define LEAF_MASK 323
#define LINKS_DELAY 324
#define LISTEN 325
#define T_LOG 326
#define MAX_ACCEPT 327
#define MAX_BANS 328
#define MAX_CHANS_PER_OPER 329
#define MAX_CHANS_PER_USER 330
#define MAX_GLOBAL 331
#define MAX_IDENT 332
#define MAX_LOCAL 333
#define MAX_NICK_CHANGES 334
#define MAX_NICK_LENGTH 335
#define MAX_NICK_TIME 336
#define MAX_NUMBER 337
#define MAX_TARGETS 338
#define MAX_TOPIC_LENGTH 339
#define MAX_WATCH 340
#define MESSAGE_LOCALE 341
#define MIN_NONWILDCARD 342
#define MIN_NONWILDCARD_SIMPLE 343
#define MIN_IDLE 344
#define MAX_IDLE 345
#define RANDOM_IDLE 346
#define HIDE_IDLE_FROM_OPERS 347
#define MODULE 348
#define MODULES 349
#define NAME 350
#define NEED_PASSWORD 351
#define NETWORK_DESC 352
#define NETWORK_NAME 353
#define NICK 354
#define NICK_CHANGES 355
#define NO_CREATE_ON_SPLIT 356
#define NO_JOIN_ON_SPLIT 357
#define NO_OPER_FLOOD 358
#define NO_TILDE 359
#define NUMBER 360
#define NUMBER_PER_CIDR 361
#define NUMBER_PER_IP 362
#define OPERATOR 363
#define OPERS_BYPASS_CALLERID 364
#define OPER_ONLY_UMODES 365
#define OPER_PASS_RESV 366
#define OPER_SPY_T 367
#define OPER_UMODES 368
#define JOIN_FLOOD_COUNT 369
#define JOIN_FLOOD_TIME 370
#define PACE_WAIT 371
#define PACE_WAIT_SIMPLE 372
#define PASSWORD 373
#define PATH 374
#define PING_COOKIE 375
#define PING_TIME 376
#define PING_WARNING 377
#define PORT 378
#define QSTRING 379
#define QUIET_ON_BAN 380
#define REASON 381
#define REDIRPORT 382
#define REDIRSERV 383
#define REGEX_T 384
#define REHASH 385
#define REMOTE 386
#define REMOTEBAN 387
#define RESTRICT_CHANNELS 388
#define RSA_PRIVATE_KEY_FILE 389
#define RSA_PUBLIC_KEY_FILE 390
#define SSL_CERTIFICATE_FILE 391
#define SSL_DH_PARAM_FILE 392
#define T_SSL_CLIENT_METHOD 393
#define T_SSL_SERVER_METHOD 394
#define T_SSLV3 395
#define T_TLSV1 396
#define RESV 397
#define RESV_EXEMPT 398
#define SECONDS 399
#define MINUTES 400
#define HOURS 401
#define DAYS 402
#define WEEKS 403
#define MONTHS 404
#define YEARS 405
#define SENDQ 406
#define SEND_PASSWORD 407
#define SERVERHIDE 408
#define SERVERINFO 409
#define IRCD_SID 410
#define TKLINE_EXPIRE_NOTICES 411
#define T_SHARED 412
#define T_CLUSTER 413
#define TYPE 414
#define SHORT_MOTD 415
#define SPOOF 416
#define SPOOF_NOTICE 417
#define STATS_E_DISABLED 418
#define STATS_I_OPER_ONLY 419
#define STATS_K_OPER_ONLY 420
#define STATS_O_OPER_ONLY 421
#define STATS_P_OPER_ONLY 422
#define TBOOL 423
#define TMASKED 424
#define TS_MAX_DELTA 425
#define TS_WARN_DELTA 426
#define TWODOTS 427
#define T_ALL 428
#define T_BOTS 429
#define T_SOFTCALLERID 430
#define T_CALLERID 431
#define T_CCONN 432
#define T_CCONN_FULL 433
#define T_SSL_CIPHER_LIST 434
#define T_DEAF 435
#define T_DEBUG 436
#define T_DLINE 437
#define T_EXTERNAL 438
#define T_FULL 439
#define T_INVISIBLE 440
#define T_IPV4 441
#define T_IPV6 442
#define T_LOCOPS 443
#define T_MAX_CLIENTS 444
#define T_NCHANGE 445
#define T_OPERWALL 446
#define T_RECVQ 447
#define T_REJ 448
#define T_SERVER 449
#define T_SERVNOTICE 450
#define T_SET 451
#define T_SKILL 452
#define T_SPY 453
#define T_SSL 454
#define T_UMODES 455
#define T_UNAUTH 456
#define T_UNDLINE 457
#define T_UNLIMITED 458
#define T_UNRESV 459
#define T_UNXLINE 460
#define T_GLOBOPS 461
#define T_WALLOP 462
#define T_RESTART 463
#define T_SERVICE 464
#define T_SERVICES_NAME 465
#define THROTTLE_TIME 466
#define TRUE_NO_OPER_FLOOD 467
#define UNKLINE 468
#define USER 469
#define USE_EGD 470
#define USE_LOGGING 471
#define VHOST 472
#define VHOST6 473
#define XLINE 474
#define WARN_NO_NLINE 475
#define T_SIZE 476
#define T_FILE 477



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2058 of yacc.c  */
#line 111 "conf_parser.y"

  int number;
  char *string;


/* Line 2058 of yacc.c  */
#line 507 "conf_parser.h"
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

#endif /* !YY_YY_CONF_PARSER_H_INCLUDED  */
