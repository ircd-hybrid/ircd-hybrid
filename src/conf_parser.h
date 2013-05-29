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
     FLATTEN_LINKS = 291,
     GECOS = 292,
     GENERAL = 293,
     GLINE = 294,
     GLINE_DURATION = 295,
     GLINE_ENABLE = 296,
     GLINE_EXEMPT = 297,
     GLINE_MIN_CIDR = 298,
     GLINE_MIN_CIDR6 = 299,
     GLINE_REQUEST_DURATION = 300,
     GLOBAL_KILL = 301,
     HAVENT_READ_CONF = 302,
     HIDDEN = 303,
     HIDDEN_NAME = 304,
     HIDE_IDLE_FROM_OPERS = 305,
     HIDE_SERVER_IPS = 306,
     HIDE_SERVERS = 307,
     HIDE_SERVICES = 308,
     HIDE_SPOOF_IPS = 309,
     HOST = 310,
     HUB = 311,
     HUB_MASK = 312,
     IGNORE_BOGUS_TS = 313,
     INVISIBLE_ON_CONNECT = 314,
     IP = 315,
     IRCD_AUTH = 316,
     IRCD_FLAGS = 317,
     IRCD_SID = 318,
     JOIN_FLOOD_COUNT = 319,
     JOIN_FLOOD_TIME = 320,
     KILL = 321,
     KILL_CHASE_TIME_LIMIT = 322,
     KLINE = 323,
     KLINE_EXEMPT = 324,
     KNOCK_DELAY = 325,
     KNOCK_DELAY_CHANNEL = 326,
     LEAF_MASK = 327,
     LINKS_DELAY = 328,
     LISTEN = 329,
     MASK = 330,
     MAX_ACCEPT = 331,
     MAX_BANS = 332,
     MAX_CHANS_PER_OPER = 333,
     MAX_CHANS_PER_USER = 334,
     MAX_GLOBAL = 335,
     MAX_IDENT = 336,
     MAX_IDLE = 337,
     MAX_LOCAL = 338,
     MAX_NICK_CHANGES = 339,
     MAX_NICK_LENGTH = 340,
     MAX_NICK_TIME = 341,
     MAX_NUMBER = 342,
     MAX_TARGETS = 343,
     MAX_TOPIC_LENGTH = 344,
     MAX_WATCH = 345,
     MIN_IDLE = 346,
     MIN_NONWILDCARD = 347,
     MIN_NONWILDCARD_SIMPLE = 348,
     MODULE = 349,
     MODULES = 350,
     NAME = 351,
     NEED_IDENT = 352,
     NEED_PASSWORD = 353,
     NETWORK_DESC = 354,
     NETWORK_NAME = 355,
     NICK = 356,
     NO_CREATE_ON_SPLIT = 357,
     NO_JOIN_ON_SPLIT = 358,
     NO_OPER_FLOOD = 359,
     NO_TILDE = 360,
     NUMBER = 361,
     NUMBER_PER_CIDR = 362,
     NUMBER_PER_IP = 363,
     OPER_ONLY_UMODES = 364,
     OPER_PASS_RESV = 365,
     OPER_UMODES = 366,
     OPERATOR = 367,
     OPERS_BYPASS_CALLERID = 368,
     PACE_WAIT = 369,
     PACE_WAIT_SIMPLE = 370,
     PASSWORD = 371,
     PATH = 372,
     PING_COOKIE = 373,
     PING_TIME = 374,
     PORT = 375,
     QSTRING = 376,
     RANDOM_IDLE = 377,
     REASON = 378,
     REDIRPORT = 379,
     REDIRSERV = 380,
     REHASH = 381,
     REMOTE = 382,
     REMOTEBAN = 383,
     RESV = 384,
     RESV_EXEMPT = 385,
     RSA_PRIVATE_KEY_FILE = 386,
     RSA_PUBLIC_KEY_FILE = 387,
     SECONDS = 388,
     MINUTES = 389,
     HOURS = 390,
     DAYS = 391,
     WEEKS = 392,
     MONTHS = 393,
     YEARS = 394,
     SEND_PASSWORD = 395,
     SENDQ = 396,
     SERVERHIDE = 397,
     SERVERINFO = 398,
     SHORT_MOTD = 399,
     SPOOF = 400,
     SPOOF_NOTICE = 401,
     SQUIT = 402,
     SSL_CERTIFICATE_FILE = 403,
     SSL_DH_PARAM_FILE = 404,
     STATS_E_DISABLED = 405,
     STATS_I_OPER_ONLY = 406,
     STATS_K_OPER_ONLY = 407,
     STATS_O_OPER_ONLY = 408,
     STATS_P_OPER_ONLY = 409,
     T_ALL = 410,
     T_BOTS = 411,
     T_CALLERID = 412,
     T_CCONN = 413,
     T_CCONN_FULL = 414,
     T_CLUSTER = 415,
     T_DEAF = 416,
     T_DEBUG = 417,
     T_DLINE = 418,
     T_EXTERNAL = 419,
     T_FARCONNECT = 420,
     T_FILE = 421,
     T_FULL = 422,
     T_GLOBOPS = 423,
     T_INVISIBLE = 424,
     T_IPV4 = 425,
     T_IPV6 = 426,
     T_LOCOPS = 427,
     T_LOG = 428,
     T_MAX_CLIENTS = 429,
     T_NCHANGE = 430,
     T_NONONREG = 431,
     T_OPERWALL = 432,
     T_RECVQ = 433,
     T_REJ = 434,
     T_RESTART = 435,
     T_SERVER = 436,
     T_SERVICE = 437,
     T_SERVICES_NAME = 438,
     T_SERVNOTICE = 439,
     T_SET = 440,
     T_SHARED = 441,
     T_SIZE = 442,
     T_SKILL = 443,
     T_SOFTCALLERID = 444,
     T_SPY = 445,
     T_SSL = 446,
     T_SSL_CIPHER_LIST = 447,
     T_SSL_CLIENT_METHOD = 448,
     T_SSL_SERVER_METHOD = 449,
     T_SSLV3 = 450,
     T_TLSV1 = 451,
     T_UMODES = 452,
     T_UNAUTH = 453,
     T_UNDLINE = 454,
     T_UNLIMITED = 455,
     T_UNRESV = 456,
     T_UNXLINE = 457,
     T_WALLOP = 458,
     T_WALLOPS = 459,
     T_WEBIRC = 460,
     TBOOL = 461,
     THROTTLE_TIME = 462,
     TKLINE_EXPIRE_NOTICES = 463,
     TMASKED = 464,
     TRUE_NO_OPER_FLOOD = 465,
     TS_MAX_DELTA = 466,
     TS_WARN_DELTA = 467,
     TWODOTS = 468,
     TYPE = 469,
     UNKLINE = 470,
     USE_EGD = 471,
     USE_LOGGING = 472,
     USER = 473,
     VHOST = 474,
     VHOST6 = 475,
     WARN_NO_NLINE = 476,
     XLINE = 477
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
#define FLATTEN_LINKS 291
#define GECOS 292
#define GENERAL 293
#define GLINE 294
#define GLINE_DURATION 295
#define GLINE_ENABLE 296
#define GLINE_EXEMPT 297
#define GLINE_MIN_CIDR 298
#define GLINE_MIN_CIDR6 299
#define GLINE_REQUEST_DURATION 300
#define GLOBAL_KILL 301
#define HAVENT_READ_CONF 302
#define HIDDEN 303
#define HIDDEN_NAME 304
#define HIDE_IDLE_FROM_OPERS 305
#define HIDE_SERVER_IPS 306
#define HIDE_SERVERS 307
#define HIDE_SERVICES 308
#define HIDE_SPOOF_IPS 309
#define HOST 310
#define HUB 311
#define HUB_MASK 312
#define IGNORE_BOGUS_TS 313
#define INVISIBLE_ON_CONNECT 314
#define IP 315
#define IRCD_AUTH 316
#define IRCD_FLAGS 317
#define IRCD_SID 318
#define JOIN_FLOOD_COUNT 319
#define JOIN_FLOOD_TIME 320
#define KILL 321
#define KILL_CHASE_TIME_LIMIT 322
#define KLINE 323
#define KLINE_EXEMPT 324
#define KNOCK_DELAY 325
#define KNOCK_DELAY_CHANNEL 326
#define LEAF_MASK 327
#define LINKS_DELAY 328
#define LISTEN 329
#define MASK 330
#define MAX_ACCEPT 331
#define MAX_BANS 332
#define MAX_CHANS_PER_OPER 333
#define MAX_CHANS_PER_USER 334
#define MAX_GLOBAL 335
#define MAX_IDENT 336
#define MAX_IDLE 337
#define MAX_LOCAL 338
#define MAX_NICK_CHANGES 339
#define MAX_NICK_LENGTH 340
#define MAX_NICK_TIME 341
#define MAX_NUMBER 342
#define MAX_TARGETS 343
#define MAX_TOPIC_LENGTH 344
#define MAX_WATCH 345
#define MIN_IDLE 346
#define MIN_NONWILDCARD 347
#define MIN_NONWILDCARD_SIMPLE 348
#define MODULE 349
#define MODULES 350
#define NAME 351
#define NEED_IDENT 352
#define NEED_PASSWORD 353
#define NETWORK_DESC 354
#define NETWORK_NAME 355
#define NICK 356
#define NO_CREATE_ON_SPLIT 357
#define NO_JOIN_ON_SPLIT 358
#define NO_OPER_FLOOD 359
#define NO_TILDE 360
#define NUMBER 361
#define NUMBER_PER_CIDR 362
#define NUMBER_PER_IP 363
#define OPER_ONLY_UMODES 364
#define OPER_PASS_RESV 365
#define OPER_UMODES 366
#define OPERATOR 367
#define OPERS_BYPASS_CALLERID 368
#define PACE_WAIT 369
#define PACE_WAIT_SIMPLE 370
#define PASSWORD 371
#define PATH 372
#define PING_COOKIE 373
#define PING_TIME 374
#define PORT 375
#define QSTRING 376
#define RANDOM_IDLE 377
#define REASON 378
#define REDIRPORT 379
#define REDIRSERV 380
#define REHASH 381
#define REMOTE 382
#define REMOTEBAN 383
#define RESV 384
#define RESV_EXEMPT 385
#define RSA_PRIVATE_KEY_FILE 386
#define RSA_PUBLIC_KEY_FILE 387
#define SECONDS 388
#define MINUTES 389
#define HOURS 390
#define DAYS 391
#define WEEKS 392
#define MONTHS 393
#define YEARS 394
#define SEND_PASSWORD 395
#define SENDQ 396
#define SERVERHIDE 397
#define SERVERINFO 398
#define SHORT_MOTD 399
#define SPOOF 400
#define SPOOF_NOTICE 401
#define SQUIT 402
#define SSL_CERTIFICATE_FILE 403
#define SSL_DH_PARAM_FILE 404
#define STATS_E_DISABLED 405
#define STATS_I_OPER_ONLY 406
#define STATS_K_OPER_ONLY 407
#define STATS_O_OPER_ONLY 408
#define STATS_P_OPER_ONLY 409
#define T_ALL 410
#define T_BOTS 411
#define T_CALLERID 412
#define T_CCONN 413
#define T_CCONN_FULL 414
#define T_CLUSTER 415
#define T_DEAF 416
#define T_DEBUG 417
#define T_DLINE 418
#define T_EXTERNAL 419
#define T_FARCONNECT 420
#define T_FILE 421
#define T_FULL 422
#define T_GLOBOPS 423
#define T_INVISIBLE 424
#define T_IPV4 425
#define T_IPV6 426
#define T_LOCOPS 427
#define T_LOG 428
#define T_MAX_CLIENTS 429
#define T_NCHANGE 430
#define T_NONONREG 431
#define T_OPERWALL 432
#define T_RECVQ 433
#define T_REJ 434
#define T_RESTART 435
#define T_SERVER 436
#define T_SERVICE 437
#define T_SERVICES_NAME 438
#define T_SERVNOTICE 439
#define T_SET 440
#define T_SHARED 441
#define T_SIZE 442
#define T_SKILL 443
#define T_SOFTCALLERID 444
#define T_SPY 445
#define T_SSL 446
#define T_SSL_CIPHER_LIST 447
#define T_SSL_CLIENT_METHOD 448
#define T_SSL_SERVER_METHOD 449
#define T_SSLV3 450
#define T_TLSV1 451
#define T_UMODES 452
#define T_UNAUTH 453
#define T_UNDLINE 454
#define T_UNLIMITED 455
#define T_UNRESV 456
#define T_UNXLINE 457
#define T_WALLOP 458
#define T_WALLOPS 459
#define T_WEBIRC 460
#define TBOOL 461
#define THROTTLE_TIME 462
#define TKLINE_EXPIRE_NOTICES 463
#define TMASKED 464
#define TRUE_NO_OPER_FLOOD 465
#define TS_MAX_DELTA 466
#define TS_WARN_DELTA 467
#define TWODOTS 468
#define TYPE 469
#define UNKLINE 470
#define USE_EGD 471
#define USE_LOGGING 472
#define USER 473
#define VHOST 474
#define VHOST6 475
#define WARN_NO_NLINE 476
#define XLINE 477



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 2053 of yacc.c  */
#line 138 "conf_parser.y"

  int number;
  char *string;


/* Line 2053 of yacc.c  */
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
