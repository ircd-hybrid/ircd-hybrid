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

/*
 * Reserve numerics 000-099 for server-client connections where the client
 * is local to the server. If any server is passed a numeric in this range
 * from another server then it is remapped to 100-199. -avalon
 */
#define RPL_WELCOME              ":%s 001 %s :Welcome to the %s Internet Relay Chat Network %s"
#define RPL_YOURHOST             ":%s 002 %s :Your host is %s, running version %s"
#define RPL_CREATED              ":%s 003 %s :This server was created %s"
#ifdef HALFOPS
#define RPL_MYINFO               ":%s 004 %s %s %s %s biklmnoprstveIhORS bkloveIh"
#else
#define RPL_MYINFO               ":%s 004 %s %s %s %s biklmnoprstveIORS bkloveI"
#endif
#define RPL_ISUPPORT             ":%s 005 %s %s :are supported by this server"
#define RPL_REDIR                ":%s 010 %s %s %d :Please use this Server/Port instead"
#define RPL_MAP                  ":%s 015 %s :%s"
#define RPL_MAPEND               ":%s 017 %s :End of /MAP"
#define RPL_YOURID               ":%s 042 %s %s :your unique ID"

/*
 * Numeric replies from server commands.
 * These are currently in the range 200-399.
 */
#define RPL_TRACELINK            ":%s 200 %s Link %s %s %s"
#define RPL_TRACECONNECTING      ":%s 201 %s Try. %s %s"
#define RPL_TRACEHANDSHAKE       ":%s 202 %s H.S. %s %s"
#define RPL_TRACEUNKNOWN         ":%s 203 %s ???? %s %s (%s) %d"
#define RPL_TRACEOPERATOR        ":%s 204 %s Oper %s %s (%s) %lu %lu"
#define RPL_TRACEUSER            ":%s 205 %s User %s %s (%s) %lu %lu"
#define RPL_TRACESERVER          ":%s 206 %s Serv %s %dS %dC %s %s!%s@%s %lu"
#define RPL_TRACENEWTYPE         ":%s 208 %s <newtype> 0 %s"
#define RPL_TRACECLASS           ":%s 209 %s Class %s %d"
#define RPL_STATSLINKINFO        ":%s 211 %s %s %u %u %llu %u %llu :%u %u %s"
#define RPL_STATSCOMMANDS        ":%s 212 %s %s %u %llu :%u"
#define RPL_STATSCLINE           ":%s 213 %s %c %s %s %s %d %s"
#define RPL_STATSNLINE           ":%s 214 %s %c %s * %s %d %s"
#define RPL_STATSILINE           ":%s 215 %s %c %s * %s@%s %d %s"
#define RPL_STATSKLINE           ":%s 216 %s %s %s * %s :%s"
#define RPL_STATSQLINE           ":%s 217 %s %c %u %s :%s"
#define RPL_STATSYLINE           ":%s 218 %s %c %s %u %u %u %u %u %u %u/%u %u/%u %s"
#define RPL_ENDOFSTATS           ":%s 219 %s %c :End of /STATS report"

/*
 * note ircu uses 217 for STATSPLINE frip. conflict
 * as RPL_STATSQLINE was used in old 2.8 for Q line 
 * I'm going to steal 220 for now *sigh*
 * -Dianora
 */
#define RPL_STATSPLINE           ":%s 220 %s %c %d %s %d %s :%s"
#define RPL_UMODEIS              ":%s 221 %s %s"
#define RPL_STATSDLINE           ":%s 225 %s %c %s :%s"
#define RPL_STATSALINE           ":%s 226 %s %s"
#define RPL_STATSLLINE           ":%s 241 %s %c %s * %s %d %s"
#define RPL_STATSUPTIME          ":%s 242 %s :Server Up %d days, %d:%02d:%02d"
#define RPL_STATSOLINE           ":%s 243 %s %c %s@%s * %s %s %s"
#define RPL_STATSHLINE           ":%s 244 %s %c %s * %s %d %s"
#define RPL_STATSSERVICE         ":%s 246 %s %c %s * %s %d %d"
#define RPL_STATSXLINE           ":%s 247 %s %s %d %s :%s"
#define RPL_STATSULINE           ":%s 248 %s U %s %s@%s %s"
#define RPL_STATSCONN            ":%s 250 %s :Highest connection count: %d (%d clients) (%llu connections received)"
#define RPL_LUSERCLIENT          ":%s 251 %s :There are %d users and %d invisible on %d servers"
#define RPL_LUSEROP              ":%s 252 %s %d :IRC Operators online"
#define RPL_LUSERUNKNOWN         ":%s 253 %s %d :unknown connection(s)"
#define RPL_LUSERCHANNELS        ":%s 254 %s %d :channels formed"
#define RPL_LUSERME              ":%s 255 %s :I have %d clients and %d servers"
#define RPL_ADMINME              ":%s 256 %s :Administrative info about %s"
#define RPL_ADMINLOC1            ":%s 257 %s :%s"
#define RPL_ADMINLOC2            ":%s 258 %s :%s"
#define RPL_ADMINEMAIL           ":%s 259 %s :%s"
#define RPL_ENDOFTRACE           ":%s 262 %s %s :End of TRACE"
#define RPL_LOAD2HI              ":%s 263 %s :Server load is temporarily too heavy. Please wait a while and try again."
#define RPL_LOCALUSERS           ":%s 265 %s :Current local users: %d  Max: %d"
#define RPL_GLOBALUSERS          ":%s 266 %s :Current global users: %d  Max: %d"
#define RPL_ACCEPTLIST           ":%s 281 %s :%s"
#define RPL_ENDOFACCEPT          ":%s 282 %s :End of /ACCEPT list."
#define RPL_AWAY                 ":%s 301 %s %s :%s"
#define RPL_USERHOST             ":%s 302 %s :%s"
#define RPL_ISON                 ":%s 303 %s :"
#define RPL_UNAWAY               ":%s 305 %s :You are no longer marked as being away"
#define RPL_NOWAWAY              ":%s 306 %s :You have been marked as being away"
#define RPL_WHOISREGNICK         ":%s 307 %s %s :has identified for this nick"
#define RPL_WHOISADMIN           ":%s 313 %s %s :is a Server Administrator"
#define RPL_WHOISUSER            ":%s 311 %s %s %s %s * :%s"
#define RPL_WHOISSERVER          ":%s 312 %s %s %s :%s"
#define RPL_WHOISOPERATOR        ":%s 313 %s %s :is an IRC Operator"
#define RPL_WHOWASUSER           ":%s 314 %s %s %s %s * :%s"
#define RPL_ENDOFWHO             ":%s 315 %s %s :End of /WHO list."
#define RPL_WHOISIDLE            ":%s 317 %s %s %u %d :seconds idle, signon time"
#define RPL_ENDOFWHOIS           ":%s 318 %s %s :End of /WHOIS list."
#define RPL_WHOISCHANNELS        ":%s 319 %s %s :%s"
#define RPL_LISTSTART            ":%s 321 %s Channel :Users  Name"
#define RPL_LIST                 ":%s 322 %s %s %d :%s"
#define RPL_LISTEND              ":%s 323 %s :End of /LIST"
#define RPL_CHANNELMODEIS        ":%s 324 %s %s %s %s"
#define RPL_CREATIONTIME         ":%s 329 %s %s %lu"
#define RPL_NOTOPIC              ":%s 331 %s %s :No topic is set."
#define RPL_TOPIC                ":%s 332 %s %s :%s"
#define RPL_TOPICWHOTIME         ":%s 333 %s %s %s %lu"
#define RPL_WHOISACTUALLY        ":%s 338 %s %s %s :actually using host"
#define RPL_INVITING             ":%s 341 %s %s %s"
#define RPL_INVITELIST           ":%s 346 %s %s %s!%s@%s %s %lu"
#define RPL_ENDOFINVITELIST      ":%s 347 %s %s :End of Channel Invite List"
#define RPL_EXCEPTLIST           ":%s 348 %s %s %s!%s@%s %s %lu"
#define RPL_ENDOFEXCEPTLIST      ":%s 349 %s %s :End of Channel Exception List"
#define RPL_VERSION              ":%s 351 %s %s(%s). %s :%s%s"
#define RPL_WHOREPLY             ":%s 352 %s %s %s %s %s %s %s :%d %s"
#define RPL_NAMREPLY             ":%s 353 %s %s %s :"
#define RPL_CLOSING              ":%s 362 %s %s :Closed. Status = %d"
#define RPL_CLOSEEND             ":%s 363 %s %d: Connections Closed"
#define RPL_LINKS                ":%s 364 %s %s %s :%d %s"
#define RPL_ENDOFLINKS           ":%s 365 %s %s :End of /LINKS list."
#define RPL_ENDOFNAMES           ":%s 366 %s %s :End of /NAMES list."
#define RPL_BANLIST              ":%s 367 %s %s %s!%s@%s %s %lu"
#define RPL_ENDOFBANLIST         ":%s 368 %s %s :End of Channel Ban List"
#define RPL_ENDOFWHOWAS          ":%s 369 %s %s :End of WHOWAS"
#define RPL_INFO                 ":%s 371 %s :%s"
#define RPL_MOTD                 ":%s 372 %s :- %s"
#define RPL_INFOSTART            ":%s 373 %s :Server INFO"
#define RPL_ENDOFINFO            ":%s 374 %s :End of /INFO list."
#define RPL_MOTDSTART            ":%s 375 %s :- %s Message of the Day - "
#define RPL_ENDOFMOTD            ":%s 376 %s :End of /MOTD command."
#define RPL_YOUREOPER            ":%s 381 %s :You have entered... the Twilight Zone!"
#define RPL_REHASHING            ":%s 382 %s %s :Rehashing"
#define RPL_TIME                 ":%s 391 %s %s :%s"
#define RPL_HOSTHIDDEN           ":%s 396 %s %s :is now your hidden host"

/*
 * Errors are in the range from 400-599 currently and are grouped by what
 * commands they come from.
 */
#define ERR_NOSUCHNICK           ":%s 401 %s %s :No such nick/channel"
#define ERR_NOSUCHSERVER         ":%s 402 %s %s :No such server"
#define ERR_NOSUCHCHANNEL        ":%s 403 %s %s :No such channel"
#define ERR_CANNOTSENDTOCHAN     ":%s 404 %s %s :Cannot send to channel"
#define ERR_TOOMANYCHANNELS      ":%s 405 %s %s :You have joined too many channels"
#define ERR_WASNOSUCHNICK        ":%s 406 %s %s :There was no such nickname"
#define ERR_TOOMANYTARGETS       ":%s 407 %s %s :Too many recipients. Only %d processed"
#define ERR_NOORIGIN             ":%s 409 %s :No origin specified"
#define ERR_INVALIDCAPCMD        ":%s 410 %s %s :Invalid CAP subcommand"
#define ERR_NORECIPIENT          ":%s 411 %s :No recipient given (%s)"
#define ERR_NOTEXTTOSEND         ":%s 412 %s :No text to send"
#define ERR_NOTOPLEVEL           ":%s 413 %s %s :No toplevel domain specified"
#define ERR_WILDTOPLEVEL         ":%s 414 %s %s :Wildcard in toplevel Domain"
#define ERR_UNKNOWNCOMMAND       ":%s 421 %s %s :Unknown command"
#define ERR_NOMOTD               ":%s 422 %s :MOTD File is missing"
#define ERR_NOADMININFO          ":%s 423 %s %s :No administrative info available"
#define ERR_NONICKNAMEGIVEN      ":%s 431 %s :No nickname given"
#define ERR_ERRONEUSNICKNAME     ":%s 432 %s %s :Erroneous Nickname"
#define ERR_NICKNAMEINUSE        ":%s 433 %s %s :Nickname is already in use."
#define ERR_NICKCOLLISION        ":%s 436 %s %s :Nickname collision KILL"
#define ERR_UNAVAILRESOURCE      ":%s 437 %s %s :Nick/channel is temporarily unavailable"
#define ERR_NICKTOOFAST          ":%s 438 %s %s %s :Nick change too fast. Please wait %d seconds."
#define ERR_SERVICESDOWN         ":%s 440 %s %s :Services is currently down."
#define ERR_USERNOTINCHANNEL     ":%s 441 %s %s %s :They aren't on that channel"
#define ERR_NOTONCHANNEL         ":%s 442 %s %s :You're not on that channel"
#define ERR_USERONCHANNEL        ":%s 443 %s %s %s :is already on channel"
#define ERR_NOTREGISTERED        ":%s 451 %s :You have not registered"
#define ERR_ACCEPTFULL           ":%s 456 %s :Accept list is full"
#define ERR_ACCEPTEXIST          ":%s 457 %s %s!%s@%s :is already on your accept list"
#define ERR_ACCEPTNOT            ":%s 458 %s %s!%s@%s :is not on your accept list"
#define ERR_NEEDMOREPARAMS       ":%s 461 %s %s :Not enough parameters"
#define ERR_ALREADYREGISTRED     ":%s 462 %s :You may not reregister"
#define ERR_PASSWDMISMATCH       ":%s 464 %s :Password Incorrect"
#define ERR_YOUREBANNEDCREEP     ":%s 465 %s :You are banned from this server- %s"
#define ERR_ONLYSERVERSCANCHANGE ":%s 468 %s %s :Only servers can change that mode"
#define ERR_OPERONLYCHAN         ":%s 470 %s %s :Cannot join channel (+O)"
#define ERR_CHANNELISFULL        ":%s 471 %s %s :Cannot join channel (+l)"
#define ERR_UNKNOWNMODE          ":%s 472 %s %c :is unknown mode char to me"
#define ERR_INVITEONLYCHAN       ":%s 473 %s %s :Cannot join channel (+i)"
#define ERR_BANNEDFROMCHAN       ":%s 474 %s %s :Cannot join channel (+b)"
#define ERR_BADCHANNELKEY        ":%s 475 %s %s :Cannot join channel (+k)"
#define ERR_NEEDREGGEDNICK       ":%s 477 %s %s :You need to identify to a registered nick to join or speak in that channel."
#define ERR_BANLISTFULL          ":%s 478 %s %s %s :Channel ban list is full"
#define ERR_BADCHANNAME          ":%s 479 %s %s :Illegal channel name"
#define ERR_SSLONLYCHAN          ":%s 480 %s %s :Cannot join channel (+S)"
#define ERR_NOPRIVILEGES         ":%s 481 %s :Permission Denied - You're not an IRC operator"
#define ERR_CHANOPRIVSNEEDED     ":%s 482 %s %s :You're not channel operator"
#define ERR_CANTKILLSERVER       ":%s 483 %s :You can't kill a server!"
#define ERR_RESTRICTED           ":%s 484 %s :You are restricted"
#define ERR_NONONREG             ":%s 486 %s %s :You must identify to a registered nick to private message that person"
#define ERR_NOOPERHOST           ":%s 491 %s :Only few of mere mortals may try to enter the twilight zone"
#define ERR_UMODEUNKNOWNFLAG     ":%s 501 %s :Unknown MODE flag"
#define ERR_USERSDONTMATCH       ":%s 502 %s :Can't change mode for other users"
#define ERR_GHOSTEDCLIENT        ":%s 503 %s :Message could not be delivered to %s"
#define ERR_USERNOTONSERV        ":%s 504 %s %s :User is not on this server"
#define ERR_TOOMANYWATCH         ":%s 512 %s %s :Maximum size for WATCH-list is %d entries"
#define ERR_WRONGPONG            ":%s 513 %s :To connect type /QUOTE PONG %u"
#define ERR_LISTSYNTAX           ":%s 521 %s :Bad list syntax, type /QUOTE HELP LIST"
#define ERR_HELPNOTFOUND         ":%s 524 %s %s :Help not found"
#define RPL_LOGON                ":%s 600 %s %s %s %s %d :logged online"
#define RPL_LOGOFF               ":%s 601 %s %s %s %s %d :logged offline"
#define RPL_WATCHOFF             ":%s 602 %s %s %s %s %d :stopped watching"
#define RPL_WATCHSTAT            ":%s 603 %s :You have %u and are on %u WATCH entries"
#define RPL_NOWON                ":%s 604 %s %s %s %s %d :is online"
#define RPL_NOWOFF               ":%s 605 %s %s %s %s %d :is offline"
#define RPL_WATCHLIST            ":%s 606 %s :%s"
#define RPL_ENDOFWATCHLIST       ":%s 607 %s :End of WATCH %c"
#define RPL_WHOISSECURE          ":%s 671 %s %s :is connected via SSL (secure link)"
#define RPL_MODLIST              ":%s 702 %s %s %p %s %s"
#define RPL_ENDOFMODLIST         ":%s 703 %s :End of /MODLIST."
#define RPL_HELPSTART            ":%s 704 %s %s :%s"
#define RPL_HELPTXT              ":%s 705 %s %s :%s"
#define RPL_ENDOFHELP            ":%s 706 %s %s :End of /HELP."
#define RPL_ETRACE_FULL          ":%s 708 %s %s %s %s %s %s %s %s %s :%s"
#define RPL_ETRACE               ":%s 709 %s %s %s %s %s %s %s :%s"
#define RPL_KNOCK                ":%s 710 %s %s %s!%s@%s :has asked for an invite."
#define RPL_KNOCKDLVR            ":%s 711 %s %s :Your KNOCK has been delivered."
#define ERR_TOOMANYKNOCK         ":%s 712 %s %s :Too many KNOCKs (%s)."
#define ERR_CHANOPEN             ":%s 713 %s %s :Channel is open."
#define ERR_KNOCKONCHAN          ":%s 714 %s %s :You are already on that channel."
#define RPL_TARGUMODEG           ":%s 716 %s %s :is in +g mode (server side ignore)"
#define RPL_TARGNOTIFY           ":%s 717 %s %s :has been informed that you messaged them."
#define RPL_UMODEGMSG            ":%s 718 %s %s :is messaging you, and you are umode +g."
#define ERR_NOPRIVS              ":%s 723 %s %s :Insufficient oper privs."
#define RPL_TESTMASK             ":%s 724 %s %s!%s@%s %u %u :Local/remote clients match."
#define RPL_TESTLINE             ":%s 725 %s %c %ld %s :%s"
#define RPL_NOTESTLINE           ":%s 726 %s %s :No matches"
#define RPL_STATSDEBUG       249 /* XXX */
#endif
