/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  numeric.h: A header for the numeric functions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 *  $Id$
 */

#ifndef INCLUDED_numeric_h
#define INCLUDED_numeric_h

#define LOCALE_LENGTH 64  /* maximum length of locale name + 1 */

struct NumericInfo
{
  const char *name;     /* common name of the numeric */
  const char *standard; /* standard numeric text      */
  char *translated;     /* translated numeric text    */
};

/* form_str - return a format string for a message number
 * messages are defined below
 */
extern const char *form_str(int);
extern void set_locale(const char *);
extern const char *get_locale(void);

/*
 * Reserve numerics 000-099 for server-client connections where the client
 * is local to the server. If any server is passed a numeric in this range
 * from another server then it is remapped to 100-199. -avalon
 */
#define RPL_WELCOME          001
#define RPL_YOURHOST         002
#define RPL_CREATED          003
#define RPL_MYINFO           004
#define RPL_ISUPPORT         005
     /* RPL_BOUNCE                         IRCnet extension */
/*	RPL_MAP		       6	unreal */
/*	RPL_MAPEND	       7	unreal */
/*	RPL_SNOMASK            8        Undernet extension */
/*	RPL_STATMEMTOT         9        Undernet extension */
/*	RPL_STATMEM           10        Undernet extension */

#define RPL_REDIR            10
#define RPL_MAP		     15		/* Undernet extension */
#define RPL_MAPMORE	     16		/* Undernet extension */
#define RPL_MAPEND	     17		/* Undernet extension */

#define RPL_YOURID	     42		/* IRCnet extension */
/*      RPL_ATTEMPTINGJUNC    50           aircd extension */
/*      RPL_ATTEMPTINGREROUTE 51           aircd extension */

/*
 * Numeric replies from server commands.
 * These are currently in the range 200-399.
 */
#define RPL_TRACELINK        200
#define RPL_TRACECONNECTING  201
#define RPL_TRACEHANDSHAKE   202
#define RPL_TRACEUNKNOWN     203
#define RPL_TRACEOPERATOR    204
#define RPL_TRACEUSER        205
#define RPL_TRACESERVER      206
#define RPL_TRACENEWTYPE     208
#define RPL_TRACECLASS       209

/*      RPL_STATS            210 aircd extension, used instead of having
                                 multiple stats numerics */
/*      RPL_TRACERECONNECT   210 IRCnet extension */                                 

#define RPL_STATSLINKINFO    211
#define RPL_STATSCOMMANDS    212
#define RPL_STATSCLINE       213
#define RPL_STATSNLINE       214
/*	RPL_STATSOLDNLINE    214    unreal */
#define RPL_STATSILINE       215
#define RPL_STATSKLINE       216
#define RPL_STATSQLINE       217
#define RPL_STATSYLINE       218
#define RPL_ENDOFSTATS       219
/* note ircu uses 217 for STATSPLINE frip. conflict
 * as RPL_STATSQLINE was used in old 2.8 for Q line 
 * I'm going to steal 220 for now *sigh*
 * -Dianora
 */

#define RPL_STATSPLINE       220
#define RPL_UMODEIS          221

/*	RPL_SQLINE_NICK	     222	   Numerics List: Dalnet */
/*	RPL_STATSELINE       223	   dalnet */
/*	RPL_STATSGLINE	     223	   unreal */
/*      RPL_STATSFLINE       224           Hybrid extension,Dalnet */
/*	RPL_STATSTLINE	     224	   unreal */
/*      RPL_STATSDLINE       225           Hybrid extension */
/*	RPL_STATSZLINE	     225	   Dalnet
 	RPL_STATSELINE	     225	   unreal
 	RPL_STATSCOUNT	     226	   Dalnet
	RPL_STATSNLINE	     226	   unreal
	RPL_STATSGLINE	     227	   Dalnet 
	RPL_STATSVLINE	     227	   unreal */

#define RPL_STATSFLINE       224
#define RPL_STATSDLINE       225
#define RPL_STATSALINE	     226

/*	RPL_RULES	     232	unreal */

/*      RPL_STATSIAUTH       239           IRCnet extension */
/*      RPL_STATSVLINE       240           IRCnet extension */
/*	RPL_STATSXLINE	     240	austnet */

#define RPL_STATSLLINE       241
#define RPL_STATSUPTIME      242
#define RPL_STATSOLINE       243
#define RPL_STATSHLINE       244
/* 245 No longer used in ircd-hybrid */
#define RPL_STATSSLINE       245
#define RPL_STATSSERVICE     246
#define RPL_STATSXLINE       247
#define RPL_STATSULINE       248
#define RPL_STATSDEBUG       249
#define RPL_STATSCONN        250
/*	RPL_STATSDLINE	     250	   Numerics List: IRCnet */
#define RPL_LUSERCLIENT      251
#define RPL_LUSEROP          252
#define RPL_LUSERUNKNOWN     253
#define RPL_LUSERCHANNELS    254
#define RPL_LUSERME          255
#define RPL_ADMINME          256
#define RPL_ADMINLOC1        257
#define RPL_ADMINLOC2        258
#define RPL_ADMINEMAIL       259

#define RPL_ENDOFTRACE       262
#define RPL_LOAD2HI          263

/*	RPL_TRYAGAIN	     263	   Numerics List: IRCnet */
/*	RPL_LOAD2HI	     263	   Dalnet */
/*      RPL_CURRENT_LOCAL    265           aircd/efnet/hybrid/dalnet*/
/*      RPL_CURRENT_GLOBAL   266           aircd/efnet/hybrid/dalnet */
/*      RPL_START_NETSTAT    267           aircd */
/*      RPL_NETSTAT          268           aircd */
/*      RPL_END_NETSTAT      269           aircd */

#define RPL_LOCALUSERS       265
#define RPL_GLOBALUSERS      266

#define RPL_ACCEPTLIST	     281
#define RPL_ENDOFACCEPT      282

/*	RPL_GLIST            280        Undernet extension */
/*	RPL_ENDOFGLIST       281        Undernet extension */
/*	RPL_JUPELIST         282        Undernet extension - jupe -Kev */
/*	RPL_ENDOFJUPELIST    283        Undernet extension - jupe -Kev */
/*	RPL_FEATURE	     284	Undernet extension - features */
/*      RPL_CHANINFO_HANDLE  285           aircd */
/*      RPL_CHANINFO_USERS   286           aircd */
/*      RPL_CHANINFO_CHOPS   287           aircd */
/*      RPL_CHANINFO_VOICES  288           aircd */
/*      RPL_CHANINFO_AWAY    289           aircd */
/*      RPL_CHANINFO_OPERS   290           aircd */
/*	RPL_HELPHDR	     290	Numeric List: Dalnet */
/*      RPL_CHANINFO_BANNED  291           aircd */
/*	RPL_HELPOP	     291	Numeric List: Dalnet */
/*      RPL_CHANINFO_BANS    292           aircd */
/*	RPL_HELPTLR	     292	Numeric List: Dalnet */
/*      RPL_CHANINFO_INVITE  293           aircd */
/*	RPL_HELPHLP	     293	Numeric List: Dalnet */
/*      RPL_CHANINFO_INVITES 294           aircd */
/*	RPL_HELPFWD	     294	Numeric List: Dalnet */
/*      RPL_CHANINFO_KICK    295           aircd */
/*	RPL_HELPIGN	     295	Numeric List: Dalnet */
/*      RPL_CHANINFO_KICKS   296           aircd */

/*      RPL_END_CHANINFO     299           aircd */

/* numeric_replies */
#define RPL_AWAY             301
#define RPL_USERHOST         302
#define RPL_ISON             303
#define RPL_TEXT             304
#define RPL_UNAWAY           305
#define RPL_NOWAWAY          306
/*	RPL_USERIP	     307	Undernet extension */
#define RPL_WHOISREGNICK     307
/*	RPL_SUSERHOST	     307	austnet */
/*      RPL_NOTIFYACTION     308         aircd */
#define RPL_WHOISADMIN	     308	/* Numeric List: Dalnet */
/*	RPL_RULESSTART	     308	unreal */
/*      RPL_NICKTRACE        309         aircd */
/*	RPL_WHOISSADMIN	     309	Numeric List: Dalnet */
/*	RPL_ENDOFRULES	     309	unreal */
/*	RPL_WHOISHELPER	     309	austnet */
/*      RPL_WHOISSVCMSG      310         Dalnet */
/*	RPL_WHOISHELPOP	     310	unreal */
/*	RPL_WHOISSERVICE     310	austnet */

#define RPL_WHOISUSER        311
#define RPL_WHOISSERVER      312
#define RPL_WHOISOPERATOR    313

#define RPL_WHOWASUSER       314
/* rpl_endofwho below (315) */
#define RPL_ENDOFWHOWAS      369

#define RPL_WHOISCHANOP      316 /* redundant and not needed but reserved */
#define RPL_WHOISIDLE        317

#define RPL_ENDOFWHOIS       318
#define RPL_WHOISCHANNELS    319
/*      RPL_WHOIS_HIDDEN     320         Anothernet +h, ick! */
/*	RPL_WHOISSPECIAL     320	unreal */
#define RPL_LISTSTART        321
#define RPL_LIST             322
#define RPL_LISTEND          323
#define RPL_CHANNELMODEIS    324
/*      RPL_CHANNELPASSIS    325           IRCnet extension */
/*      RPL_UNIQOPIS         325           IRCnet extension */
/*      RPL_NOCHANPASS       326           IRCnet extension */
/*      RPL_CHPASSUNKNOWN    327           IRCnet extension */
/*      RPL_CHANNEL_URL      328           dalnet, anothernet */
#define RPL_CREATIONTIME     329
/*      RPL_WHOWAS_TIME      330               ? */
#define RPL_NOTOPIC          331
#define RPL_TOPIC            332
#define RPL_TOPICWHOTIME     333
/*	RPL_COMMANDSYNTAX    334	   Dalnet */
/*	RPL_LISTSYNTAX	     334	   unreal */
/*      RPL_CHANPASSOK       338           IRCnet extension (?)*/
#define	RPL_WHOISACTUALLY    338	/* dalnet */
/*	RPL_WHOISACTUALLY    338	   Undernet extension, dalnet */
/*      RPL_BADCHANPASS      339           IRCnet extension (?)*/
/*	RPL_USERIP           340           (old) Undernet extension */
#define RPL_INVITING         341
/*	RPL_SUMMONING        342	   removed from RFC1459 */

#define RPL_INVITELIST       346
#define RPL_ENDOFINVITELIST  347	/* IRCnet, Undernet extension */
#define RPL_EXCEPTLIST       348
#define RPL_ENDOFEXCEPTLIST  349

#define RPL_VERSION          351

#define RPL_WHOREPLY         352
#define RPL_ENDOFWHO         315
#define RPL_NAMREPLY         353
#define RPL_ENDOFNAMES       366

#define RPL_CLOSING          362
#define RPL_CLOSEEND         363
#define RPL_LINKS            364
#define RPL_ENDOFLINKS       365
/* rpl_endofnames above (366) */
#define RPL_BANLIST          367
#define RPL_ENDOFBANLIST     368
/* rpl_endofwhowas above (369) */

#define RPL_INFO             371
#define RPL_MOTD             372
#define RPL_INFOSTART        373
#define RPL_ENDOFINFO        374
#define RPL_MOTDSTART        375
#define RPL_ENDOFMOTD        376

/*      RPL_KICKEXPIRED      377   aircd */
/*	RPL_SPAM	     377   austnet */
/*      RPL_BANEXPIRED       378   aircd */
/*      RPL_KICKLINKED       379   aircd */
/*      RPL_BANLINKED        380   aircd */

#define RPL_YOUREOPER        381
#define RPL_REHASHING        382
/*	RPL_YOURSERVICE	     383	   Numeric List: various */
#define RPL_RSACHALLENGE     386

/*	RPL_QLIST	     386	unreal */
/*	RPL_ENDOFQLIST	     387	unreal */
/*	RPL_ALIST	     388	unreal */
/*	RPL_ENDOFALIST	     389	unreal */ 

#define RPL_TIME             391
#define RPL_USERSSTART       392
#define RPL_USERS            393
#define RPL_ENDOFUSERS       394
#define RPL_NOUSERS          395
#define RPL_HOSTHIDDEN       396

/*
 * Errors are in the range from 400-599 currently and are grouped by what
 * commands they come from.
 */
#define ERR_NOSUCHNICK       401
#define ERR_NOSUCHSERVER     402
#define ERR_NOSUCHCHANNEL    403
#define ERR_CANNOTSENDTOCHAN 404
#define ERR_TOOMANYCHANNELS  405
#define ERR_WASNOSUCHNICK    406
#define ERR_TOOMANYTARGETS   407
#define ERR_NOORIGIN         409
#define ERR_INVALIDCAPCMD    410

#define ERR_NORECIPIENT      411
#define ERR_NOTEXTTOSEND     412
#define ERR_NOTOPLEVEL       413
#define ERR_WILDTOPLEVEL     414
/*	ERR_BADMASK          415           IRCnet extension */
#define ERR_UNKNOWNCOMMAND   421
#define ERR_NOMOTD           422
#define ERR_NOADMININFO      423

/* 	ERR_TOOMANYAWAY	     429	    Dalnet */

#define ERR_NONICKNAMEGIVEN  431
#define ERR_ERRONEUSNICKNAME 432
#define ERR_NICKNAMEINUSE    433

/*      ERR_SERVICENAMEINUSE 434 ? */
/*	ERR_NORULES	     434   unreal */
/*      ERR_SERVICECONFUSED  435 ? */
/*	ERR_BANONCHAN	     435   dalnet */

#define ERR_NICKCOLLISION    436
#define ERR_UNAVAILRESOURCE  437
#define ERR_NICKTOOFAST	     438	/* We did it first Undernet! ;) db */

#define ERR_SERVICESDOWN     440

#define ERR_USERNOTINCHANNEL 441
#define ERR_NOTONCHANNEL     442
#define ERR_USERONCHANNEL    443

#define ERR_NOTREGISTERED    451

/*      ERR_IDCOLLISION      452           IRCnet extension ? */
/*      ERR_NICKLOST         453           IRCnet extension ? */

/*	ERR_HOSTILENAME	     455	   unreal */

/*	ERR_NOHIDING	     459	   unreal */
/*	ERR_NOTFORHALFOPS    460	   unreal */

#define ERR_ACCEPTFULL       456
#define ERR_ACCEPTEXIST      457
#define ERR_ACCEPTNOT        458

#define ERR_NEEDMOREPARAMS   461
#define ERR_ALREADYREGISTRED 462
#define ERR_PASSWDMISMATCH   464
#define ERR_YOUREBANNEDCREEP 465
#define ERR_ONLYSERVERSCANCHANGE 468
/*	ERR_LINKSET	     469	unreal */
/*	ERR_LINKCHANNEL	     470	unreal */
/*      ERR_KICKEDFROMCHAN   470         aircd */
#define ERR_OPERONLYCHAN     470
#define ERR_CHANNELISFULL    471
#define ERR_UNKNOWNMODE      472
#define ERR_INVITEONLYCHAN   473
#define ERR_BANNEDFROMCHAN   474
#define ERR_BADCHANNELKEY    475
#define ERR_NEEDREGGEDNICK   477
#define ERR_BANLISTFULL      478        /* I stole the numeric from ircu -db */
#define ERR_BADCHANNAME      479
/* 	ERR_LINKFAIL	     479	unreal */
#define ERR_SSLONLYCHAN      480
#define ERR_NOPRIVILEGES     481
#define ERR_CHANOPRIVSNEEDED 482
#define ERR_CANTKILLSERVER   483
#define ERR_RESTRICTED       484
/*	ERR_DESYNC	     484	 Dalnet,PTlink */
/*	ERR_ATTACKDENY	     484	 unreal */
/*	ERR_RESTRICTED	     484	   IRCnet extension */
/*      ERR_UNIQOPRIVSNEEDED 485           IRCnet extension */
/*	ERR_KILLDENY         485	   unreal */
/*	ERR_CANTKICKADMIN    485	   PTlink */
#define ERR_NONONREG         486
/*      ERR_CHANTOORECENT    487           IRCnet extension (?) */
/*      ERR_TSLESSCHAN       488           IRCnet extension (?) */
/*	ERR_VOICENEEDED      489           Undernet extension */
#define ERR_NOOPERHOST       491
/*      ERR_NOSERVICEHOST    492 	   IRCnet extension */

#define ERR_UMODEUNKNOWNFLAG 501
#define ERR_USERSDONTMATCH   502

#define ERR_GHOSTEDCLIENT    503
/*	ERR_VWORLDWARN	     503	   austnet */

#define ERR_USERNOTONSERV    504

/* #define ERR_LAST_ERR_MSG 505 
 * moved to 999
 */


#define ERR_TOOMANYWATCH     512
#define ERR_WRONGPONG	     513
/*	ERR_TOOMANYDCC	     514	dalnet */
/*	ERR_NOINVITE	     518	unreal */
#define ERR_LONGMASK	     518	/* Undernet extension -Kev */
/*	ERR_ADMONLY	     519	unreal */
/*	ERR_TOOMANYUSERS     519	Undernet extension -Kev */
/*	ERR_OPERONLY	     520	unreal */
/*	ERR_MASKTOOWIDE	     520	Undernet extension -Kev */
/*	ERR_WHOTRUNC	     520	austnet */
/*	ERR_LASTERROR        521	Undernet extension -Kev */
#define	ERR_LISTSYNTAX       521
/*	ERR_WHOSYNTAX	     522        dalnet */
/*	ERR_WHOLIMEXCEED     523	dalnet */

#define ERR_HELPNOTFOUND     524

#define RPL_LOGON            600
#define RPL_LOGOFF           601
#define RPL_WATCHOFF         602
#define RPL_WATCHSTAT        603
#define RPL_NOWON            604
#define RPL_NOWOFF           605
#define RPL_WATCHLIST        606
#define RPL_ENDOFWATCHLIST   607

/*	RPL_MAPMORE          610	unreal

	RPL_MAPMORE          615	PTlink
	
	RPL_DCCSTATUS        617	dalnet
	RPL_DCCLIST          618	dalnet
	RPL_ENDOFDCCLIST     619	dalnet
	RPL_DCCINFO          620	dalnet
	
	RPL_DUMPING	     640	unreal
	RPL_DUMPRPL	     641	unreal
	RPL_EODUMP	     642	unreal
*/

#define RPL_WHOISSECURE      671
#define RPL_MODLIST          702
#define RPL_ENDOFMODLIST     703

#define RPL_HELPSTART        704
#define RPL_HELPTXT          705
#define RPL_ENDOFHELP        706

#define RPL_ETRACE_FULL      708
#define RPL_ETRACE           709

#define RPL_KNOCK	     710
#define RPL_KNOCKDLVR	     711

#define ERR_TOOMANYKNOCK     712
#define ERR_CHANOPEN         713
#define ERR_KNOCKONCHAN      714

#define RPL_TARGUMODEG       716
#define RPL_TARGNOTIFY       717
#define RPL_UMODEGMSG        718

#define ERR_NOPRIVS	     723

#define RPL_TESTMASK	     724
#define RPL_TESTLINE	     725
#define RPL_NOTESTLINE	     726

#define ERR_LAST_ERR_MSG     999

#endif /* INCLUDED_numeric_h */
