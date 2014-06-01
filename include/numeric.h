/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2014 ircd-hybrid development team
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
 */

/*! \file numeric.h
 * \brief Declarations of numeric replies.
 * \version $Id$
 */

#ifndef INCLUDED_numeric_h
#define INCLUDED_numeric_h


#define SND_EXPLICIT 0x40000000  /**< First argument is a pattern to use */

/*
 * Reserve numerics 000-099 for server-client connections where the client
 * is local to the server. If any server is passed a numeric in this range
 * from another server then it is remapped to 100-199. -avalon
 */

enum irc_numerics
{
  RPL_WELCOME              =  1,
  RPL_YOURHOST             =  2,
  RPL_CREATED              =  3,
  RPL_MYINFO               =  4,
  RPL_ISUPPORT             =  5,
  RPL_REDIR                = 10,
  RPL_MAP                  = 15,
  RPL_MAPMORE              = 16,
  RPL_MAPEND               = 17,
  RPL_YOURID               = 42,

  /*
   * Numeric replies from server commands.
   * These are currently in the range 200-399.
   */
  RPL_TRACELINK            = 200,
  RPL_TRACECONNECTING      = 201,
  RPL_TRACEHANDSHAKE       = 202,
  RPL_TRACEUNKNOWN         = 203,
  RPL_TRACEOPERATOR        = 204,
  RPL_TRACEUSER            = 205,
  RPL_TRACESERVER          = 206,
  RPL_TRACENEWTYPE         = 208,
  RPL_TRACECLASS           = 209,
  RPL_STATSLINKINFO        = 211,
  RPL_STATSCOMMANDS        = 212,
  RPL_STATSCLINE           = 213,
  RPL_STATSILINE           = 215,
  RPL_STATSKLINE           = 216,
  RPL_STATSQLINE           = 217,
  RPL_STATSYLINE           = 218,
  RPL_ENDOFSTATS           = 219,

  /*
   * Note ircu uses 217 for STATSPLINE frip. conflict
   * as RPL_STATSQLINE was used in old 2.8 for Q line
   * I'm going to steal 220 for now *sigh* -Dianora
   */
  RPL_STATSPLINE           = 220,
  RPL_UMODEIS              = 221,
  RPL_STATSDLINE           = 225,
  RPL_STATSALINE           = 226,
  RPL_STATSLLINE           = 241,
  RPL_STATSUPTIME          = 242,
  RPL_STATSOLINE           = 243,
  RPL_STATSHLINE           = 244,
  RPL_STATSTLINE           = 245,
  RPL_STATSSERVICE         = 246,
  RPL_STATSXLINE           = 247,
  RPL_STATSULINE           = 248,
  RPL_STATSDEBUG           = 249,
  RPL_STATSCONN            = 250,
  RPL_LUSERCLIENT          = 251,
  RPL_LUSEROP              = 252,
  RPL_LUSERUNKNOWN         = 253,
  RPL_LUSERCHANNELS        = 254,
  RPL_LUSERME              = 255,
  RPL_ADMINME              = 256,
  RPL_ADMINLOC1            = 257,
  RPL_ADMINLOC2            = 258,
  RPL_ADMINEMAIL           = 259,
  RPL_ENDOFTRACE           = 262,
  RPL_LOAD2HI              = 263,
  RPL_LOCALUSERS           = 265,
  RPL_GLOBALUSERS          = 266,
  RPL_WHOISCERTFP          = 276,
  RPL_ACCEPTLIST           = 281,
  RPL_ENDOFACCEPT          = 282,
  RPL_NEWHOSTIS            = 285,
  RPL_AWAY                 = 301,
  RPL_USERHOST             = 302,
  RPL_ISON                 = 303,
  RPL_UNAWAY               = 305,
  RPL_NOWAWAY              = 306,
  RPL_WHOISREGNICK         = 307,
  RPL_WHOISUSER            = 311,
  RPL_WHOISSERVER          = 312,
  RPL_WHOISOPERATOR        = 313,
  RPL_WHOWASUSER           = 314,
  RPL_ENDOFWHO             = 315,
  RPL_WHOISIDLE            = 317,
  RPL_ENDOFWHOIS           = 318,
  RPL_WHOISCHANNELS        = 319,
  RPL_LISTSTART            = 321,
  RPL_LIST                 = 322,
  RPL_LISTEND              = 323,
  RPL_CHANNELMODEIS        = 324,
  RPL_CREATIONTIME         = 329,
  RPL_WHOISACCOUNT         = 330,
  RPL_NOTOPIC              = 331,
  RPL_TOPIC                = 332,
  RPL_TOPICWHOTIME         = 333,
  RPL_WHOISTEXT            = 335,
  RPL_INVITELIST           = 336,
  RPL_ENDOFINVITELIST      = 337,
  RPL_WHOISACTUALLY        = 338,
  RPL_INVITING             = 341,
  RPL_INVEXLIST            = 346,
  RPL_ENDOFINVEXLIST       = 347,
  RPL_EXCEPTLIST           = 348,
  RPL_ENDOFEXCEPTLIST      = 349,
  RPL_VERSION              = 351,
  RPL_WHOREPLY             = 352,
  RPL_NAMREPLY             = 353,
  RPL_CLOSING              = 362,
  RPL_CLOSEEND             = 363,
  RPL_LINKS                = 364,
  RPL_ENDOFLINKS           = 365,
  RPL_ENDOFNAMES           = 366,
  RPL_BANLIST              = 367,
  RPL_ENDOFBANLIST         = 368,
  RPL_ENDOFWHOWAS          = 369,
  RPL_INFO                 = 371,
  RPL_MOTD                 = 372,
  RPL_INFOSTART            = 373,
  RPL_ENDOFINFO            = 374,
  RPL_MOTDSTART            = 375,
  RPL_ENDOFMOTD            = 376,
  RPL_WHOISMODES           = 379,
  RPL_YOUREOPER            = 381,
  RPL_REHASHING            = 382,
  RPL_RSACHALLENGE         = 386,
  RPL_TIME                 = 391,

  /*
   * Errors are in the range from 400-599 currently and are grouped by what
   * commands they come from.
   */
  ERR_NOSUCHNICK           = 401,
  ERR_NOSUCHSERVER         = 402,
  ERR_NOSUCHCHANNEL        = 403,
  ERR_CANNOTSENDTOCHAN     = 404,
  ERR_TOOMANYCHANNELS      = 405,
  ERR_WASNOSUCHNICK        = 406,
  ERR_TOOMANYTARGETS       = 407,
  ERR_NOCTRLSONCHAN        = 408,
  ERR_NOORIGIN             = 409,
  ERR_INVALIDCAPCMD        = 410,
  ERR_NORECIPIENT          = 411,
  ERR_NOTEXTTOSEND         = 412,
  ERR_NOTOPLEVEL           = 413,
  ERR_WILDTOPLEVEL         = 414,
  ERR_UNKNOWNCOMMAND       = 421,
  ERR_NOMOTD               = 422,
  ERR_NOADMININFO          = 423,
  ERR_NONICKNAMEGIVEN      = 431,
  ERR_ERRONEUSNICKNAME     = 432,
  ERR_NICKNAMEINUSE        = 433,
  ERR_NICKCOLLISION        = 436,
  ERR_UNAVAILRESOURCE      = 437,
  ERR_NICKTOOFAST          = 438,
  ERR_SERVICESDOWN         = 440,
  ERR_USERNOTINCHANNEL     = 441,
  ERR_NOTONCHANNEL         = 442,
  ERR_USERONCHANNEL        = 443,
  ERR_NOTREGISTERED        = 451,
  ERR_ACCEPTFULL           = 456,
  ERR_ACCEPTEXIST          = 457,
  ERR_ACCEPTNOT            = 458,
  ERR_NEEDMOREPARAMS       = 461,
  ERR_ALREADYREGISTRED     = 462,
  ERR_PASSWDMISMATCH       = 464,
  ERR_YOUREBANNEDCREEP     = 465,
  ERR_ONLYSERVERSCANCHANGE = 468,
  ERR_OPERONLYCHAN         = 470,
  ERR_CHANNELISFULL        = 471,
  ERR_UNKNOWNMODE          = 472,
  ERR_INVITEONLYCHAN       = 473,
  ERR_BANNEDFROMCHAN       = 474,
  ERR_BADCHANNELKEY        = 475,
  ERR_NEEDREGGEDNICK       = 477,
  ERR_BANLISTFULL          = 478,
  ERR_BADCHANNAME          = 479,
  ERR_SSLONLYCHAN          = 480,
  ERR_NOPRIVILEGES         = 481,
  ERR_CHANOPRIVSNEEDED     = 482,
  ERR_CANTKILLSERVER       = 483,
  ERR_RESTRICTED           = 484,
  ERR_CHANBANREASON        = 485,
  ERR_NONONREG             = 486,
  ERR_NOOPERHOST           = 491,
  ERR_UMODEUNKNOWNFLAG     = 501,
  ERR_USERSDONTMATCH       = 502,
  ERR_GHOSTEDCLIENT        = 503,
  ERR_USERNOTONSERV        = 504,
  ERR_TOOMANYWATCH         = 512,
  ERR_WRONGPONG            = 513,
  ERR_LISTSYNTAX           = 521,
  ERR_HELPNOTFOUND         = 524,
  RPL_LOGON                = 600,
  RPL_LOGOFF               = 601,
  RPL_WATCHOFF             = 602,
  RPL_WATCHSTAT            = 603,
  RPL_NOWON                = 604,
  RPL_NOWOFF               = 605,
  RPL_WATCHLIST            = 606,
  RPL_ENDOFWATCHLIST       = 607,
  RPL_WHOISSECURE          = 671,
  RPL_MODLIST              = 702,
  RPL_ENDOFMODLIST         = 703,
  RPL_HELPSTART            = 704,
  RPL_HELPTXT              = 705,
  RPL_ENDOFHELP            = 706,
  RPL_ETRACE               = 709,
  RPL_KNOCK                = 710,
  RPL_KNOCKDLVR            = 711,
  ERR_TOOMANYKNOCK         = 712,
  ERR_CHANOPEN             = 713,
  ERR_KNOCKONCHAN          = 714,
  ERR_TOOMANYINVITE        = 715,
  RPL_TARGUMODEG           = 716,
  RPL_TARGNOTIFY           = 717,
  RPL_UMODEGMSG            = 718,
  ERR_NOPRIVS              = 723,
  ERR_LAST_ERR_MSG         = 999
};

extern const char *numeric_form(enum irc_numerics);
#endif /* INCLUDED_numeric_h */
