/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
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
     HIDE_SERVICES = 310,
     HIDE_SPOOF_IPS = 311,
     HOST = 312,
     HUB = 313,
     HUB_MASK = 314,
     IGNORE_BOGUS_TS = 315,
     INVISIBLE_ON_CONNECT = 316,
     IP = 317,
     KILL = 318,
     KILL_CHASE_TIME_LIMIT = 319,
     KLINE = 320,
     KLINE_EXEMPT = 321,
     KNOCK_DELAY = 322,
     KNOCK_DELAY_CHANNEL = 323,
     LEAF_MASK = 324,
     LINKS_DELAY = 325,
     LISTEN = 326,
     T_LOG = 327,
     MASK = 328,
     MAX_ACCEPT = 329,
     MAX_BANS = 330,
     MAX_CHANS_PER_OPER = 331,
     MAX_CHANS_PER_USER = 332,
     MAX_GLOBAL = 333,
     MAX_IDENT = 334,
     MAX_LOCAL = 335,
     MAX_NICK_CHANGES = 336,
     MAX_NICK_LENGTH = 337,
     MAX_NICK_TIME = 338,
     MAX_NUMBER = 339,
     MAX_TARGETS = 340,
     MAX_TOPIC_LENGTH = 341,
     MAX_WATCH = 342,
     MIN_NONWILDCARD = 343,
     MIN_NONWILDCARD_SIMPLE = 344,
     MIN_IDLE = 345,
     MAX_IDLE = 346,
     RANDOM_IDLE = 347,
     HIDE_IDLE_FROM_OPERS = 348,
     MODULE = 349,
     MODULES = 350,
     NAME = 351,
     NEED_PASSWORD = 352,
     NETWORK_DESC = 353,
     NETWORK_NAME = 354,
     NICK = 355,
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
     OPER_UMODES = 367,
     JOIN_FLOOD_COUNT = 368,
     JOIN_FLOOD_TIME = 369,
     PACE_WAIT = 370,
     PACE_WAIT_SIMPLE = 371,
     PASSWORD = 372,
     PATH = 373,
     PING_COOKIE = 374,
     PING_TIME = 375,
     PORT = 376,
     QSTRING = 377,
     REASON = 378,
     REDIRPORT = 379,
     REDIRSERV = 380,
     REHASH = 381,
     REMOTE = 382,
     REMOTEBAN = 383,
     RSA_PRIVATE_KEY_FILE = 384,
     RSA_PUBLIC_KEY_FILE = 385,
     SSL_CERTIFICATE_FILE = 386,
     SSL_DH_PARAM_FILE = 387,
     T_SSL_CLIENT_METHOD = 388,
     T_SSL_SERVER_METHOD = 389,
     T_SSLV3 = 390,
     T_TLSV1 = 391,
     RESV = 392,
     RESV_EXEMPT = 393,
     SECONDS = 394,
     MINUTES = 395,
     HOURS = 396,
     DAYS = 397,
     WEEKS = 398,
     MONTHS = 399,
     YEARS = 400,
     SENDQ = 401,
     SEND_PASSWORD = 402,
     SERVERHIDE = 403,
     SERVERINFO = 404,
     SQUIT = 405,
     IRCD_SID = 406,
     TKLINE_EXPIRE_NOTICES = 407,
     T_SHARED = 408,
     T_CLUSTER = 409,
     TYPE = 410,
     SHORT_MOTD = 411,
     SPOOF = 412,
     SPOOF_NOTICE = 413,
     STATS_E_DISABLED = 414,
     STATS_I_OPER_ONLY = 415,
     STATS_K_OPER_ONLY = 416,
     STATS_O_OPER_ONLY = 417,
     STATS_P_OPER_ONLY = 418,
     TBOOL = 419,
     TMASKED = 420,
     TS_MAX_DELTA = 421,
     TS_WARN_DELTA = 422,
     TWODOTS = 423,
     T_ALL = 424,
     T_BOTS = 425,
     T_SOFTCALLERID = 426,
     T_CALLERID = 427,
     T_CCONN = 428,
     T_CCONN_FULL = 429,
     T_SSL_CIPHER_LIST = 430,
     T_DEAF = 431,
     T_DEBUG = 432,
     T_DLINE = 433,
     T_EXTERNAL = 434,
     T_FARCONNECT = 435,
     T_FULL = 436,
     T_INVISIBLE = 437,
     T_IPV4 = 438,
     T_IPV6 = 439,
     T_LOCOPS = 440,
     T_MAX_CLIENTS = 441,
     T_NCHANGE = 442,
     T_NONONREG = 443,
     T_OPERWALL = 444,
     T_RECVQ = 445,
     T_REJ = 446,
     T_SERVER = 447,
     T_SERVNOTICE = 448,
     T_SET = 449,
     T_SKILL = 450,
     T_SPY = 451,
     T_SSL = 452,
     T_UMODES = 453,
     T_UNAUTH = 454,
     T_UNDLINE = 455,
     T_UNLIMITED = 456,
     T_UNRESV = 457,
     T_UNXLINE = 458,
     T_GLOBOPS = 459,
     T_WALLOP = 460,
     T_WEBIRC = 461,
     T_RESTART = 462,
     T_SERVICE = 463,
     T_SERVICES_NAME = 464,
     THROTTLE_TIME = 465,
     TRUE_NO_OPER_FLOOD = 466,
     UNKLINE = 467,
     USER = 468,
     USE_EGD = 469,
     USE_LOGGING = 470,
     VHOST = 471,
     VHOST6 = 472,
     XLINE = 473,
     WARN_NO_NLINE = 474,
     T_SIZE = 475,
     T_FILE = 476
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
#define HIDE_SERVICES 310
#define HIDE_SPOOF_IPS 311
#define HOST 312
#define HUB 313
#define HUB_MASK 314
#define IGNORE_BOGUS_TS 315
#define INVISIBLE_ON_CONNECT 316
#define IP 317
#define KILL 318
#define KILL_CHASE_TIME_LIMIT 319
#define KLINE 320
#define KLINE_EXEMPT 321
#define KNOCK_DELAY 322
#define KNOCK_DELAY_CHANNEL 323
#define LEAF_MASK 324
#define LINKS_DELAY 325
#define LISTEN 326
#define T_LOG 327
#define MASK 328
#define MAX_ACCEPT 329
#define MAX_BANS 330
#define MAX_CHANS_PER_OPER 331
#define MAX_CHANS_PER_USER 332
#define MAX_GLOBAL 333
#define MAX_IDENT 334
#define MAX_LOCAL 335
#define MAX_NICK_CHANGES 336
#define MAX_NICK_LENGTH 337
#define MAX_NICK_TIME 338
#define MAX_NUMBER 339
#define MAX_TARGETS 340
#define MAX_TOPIC_LENGTH 341
#define MAX_WATCH 342
#define MIN_NONWILDCARD 343
#define MIN_NONWILDCARD_SIMPLE 344
#define MIN_IDLE 345
#define MAX_IDLE 346
#define RANDOM_IDLE 347
#define HIDE_IDLE_FROM_OPERS 348
#define MODULE 349
#define MODULES 350
#define NAME 351
#define NEED_PASSWORD 352
#define NETWORK_DESC 353
#define NETWORK_NAME 354
#define NICK 355
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
#define OPER_UMODES 367
#define JOIN_FLOOD_COUNT 368
#define JOIN_FLOOD_TIME 369
#define PACE_WAIT 370
#define PACE_WAIT_SIMPLE 371
#define PASSWORD 372
#define PATH 373
#define PING_COOKIE 374
#define PING_TIME 375
#define PORT 376
#define QSTRING 377
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RSA_PRIVATE_KEY_FILE 384
#define RSA_PUBLIC_KEY_FILE 385
#define SSL_CERTIFICATE_FILE 386
#define SSL_DH_PARAM_FILE 387
#define T_SSL_CLIENT_METHOD 388
#define T_SSL_SERVER_METHOD 389
#define T_SSLV3 390
#define T_TLSV1 391
#define RESV 392
#define RESV_EXEMPT 393
#define SECONDS 394
#define MINUTES 395
#define HOURS 396
#define DAYS 397
#define WEEKS 398
#define MONTHS 399
#define YEARS 400
#define SENDQ 401
#define SEND_PASSWORD 402
#define SERVERHIDE 403
#define SERVERINFO 404
#define SQUIT 405
#define IRCD_SID 406
#define TKLINE_EXPIRE_NOTICES 407
#define T_SHARED 408
#define T_CLUSTER 409
#define TYPE 410
#define SHORT_MOTD 411
#define SPOOF 412
#define SPOOF_NOTICE 413
#define STATS_E_DISABLED 414
#define STATS_I_OPER_ONLY 415
#define STATS_K_OPER_ONLY 416
#define STATS_O_OPER_ONLY 417
#define STATS_P_OPER_ONLY 418
#define TBOOL 419
#define TMASKED 420
#define TS_MAX_DELTA 421
#define TS_WARN_DELTA 422
#define TWODOTS 423
#define T_ALL 424
#define T_BOTS 425
#define T_SOFTCALLERID 426
#define T_CALLERID 427
#define T_CCONN 428
#define T_CCONN_FULL 429
#define T_SSL_CIPHER_LIST 430
#define T_DEAF 431
#define T_DEBUG 432
#define T_DLINE 433
#define T_EXTERNAL 434
#define T_FARCONNECT 435
#define T_FULL 436
#define T_INVISIBLE 437
#define T_IPV4 438
#define T_IPV6 439
#define T_LOCOPS 440
#define T_MAX_CLIENTS 441
#define T_NCHANGE 442
#define T_NONONREG 443
#define T_OPERWALL 444
#define T_RECVQ 445
#define T_REJ 446
#define T_SERVER 447
#define T_SERVNOTICE 448
#define T_SET 449
#define T_SKILL 450
#define T_SPY 451
#define T_SSL 452
#define T_UMODES 453
#define T_UNAUTH 454
#define T_UNDLINE 455
#define T_UNLIMITED 456
#define T_UNRESV 457
#define T_UNXLINE 458
#define T_GLOBOPS 459
#define T_WALLOP 460
#define T_WEBIRC 461
#define T_RESTART 462
#define T_SERVICE 463
#define T_SERVICES_NAME 464
#define THROTTLE_TIME 465
#define TRUE_NO_OPER_FLOOD 466
#define UNKLINE 467
#define USER 468
#define USE_EGD 469
#define USE_LOGGING 470
#define VHOST 471
#define VHOST6 472
#define XLINE 473
#define WARN_NO_NLINE 474
#define T_SIZE 475
#define T_FILE 476



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 2053 of yacc.c  */
#line 505 "conf_parser.h"
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
