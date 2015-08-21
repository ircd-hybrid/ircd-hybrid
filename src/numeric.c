/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 1997-2015 ircd-hybrid development team
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
 *  USA
 */

/*! \file numeric.c
 * \brief Declarations of numeric replies.
 * \version $Id$
 */

#include "stdinc.h"
#include "numeric.h"


static const char *const replies[] =
{
  /* 001 */  [RPL_WELCOME] = ":Welcome to the %s Internet Relay Chat Network %s",
  /* 002 */  [RPL_YOURHOST] = ":Your host is %s, running version %s",
  /* 003 */  [RPL_CREATED] = ":This server was created %s",
  /* 004 */  [RPL_MYINFO] = "%s %s %s bchiklmnoprstveCIMORS bkloveIh",
  /* 005 */  [RPL_ISUPPORT] = "%s :are supported by this server",
  /* 010 */  [RPL_REDIR] = "%s %u :Please use this Server/Port instead",
  /* 015 */  [RPL_MAP] = ":%s%s",
  /* 016 */  [RPL_MAPMORE] = ":%s%s --> *more*",
  /* 017 */  [RPL_MAPEND] = ":End of /MAP",
  /* 200 */  [RPL_TRACELINK] = "Link %s %s %s",
  /* 201 */  [RPL_TRACECONNECTING] = "Try. %s %s",
  /* 202 */  [RPL_TRACEHANDSHAKE] = "H.S. %s %s",
  /* 203 */  [RPL_TRACEUNKNOWN] = "???? %s %s (%s) %d",
  /* 204 */  [RPL_TRACEOPERATOR] = "Oper %s %s (%s) %lu %u",
  /* 205 */  [RPL_TRACEUSER] = "User %s %s (%s) %lu %u",
  /* 206 */  [RPL_TRACESERVER] = "Serv %s %uS %uC %s %s!%s@%s %lu",
  /* 208 */  [RPL_TRACENEWTYPE] = "<newtype> 0 %s",
  /* 209 */  [RPL_TRACECLASS] = "Class %s %u",
  /* 211 */  [RPL_STATSLINKINFO] = "%s %u %u %llu %u %llu :%u %u %s",
  /* 212 */  [RPL_STATSCOMMANDS] = "%s %u %llu :%u",
  /* 213 */  [RPL_STATSCLINE] = "%c %s %s %s %u %s",
  /* 215 */  [RPL_STATSILINE] = "%c %s * %s@%s %u %s",
  /* 216 */  [RPL_STATSKLINE] = "%c %s * %s :%s",
  /* 217 */  [RPL_STATSQLINE] = "%c %u %s :%s",
  /* 218 */  [RPL_STATSYLINE] = "%c %s %u %u %u %u %u %u %u/%u %u/%u %s",
  /* 219 */  [RPL_ENDOFSTATS] = "%c :End of /STATS report",
  /* 220 */  [RPL_STATSPLINE] = "%c %d %s %d %s :%s",
  /* 221 */  [RPL_UMODEIS] = "%s",
  /* 225 */  [RPL_STATSDLINE] = "%c %s :%s",
  /* 226 */  [RPL_STATSALINE] = "%s",
  /* 241 */  [RPL_STATSLLINE] = "%c %s * %s %u %s",
  /* 242 */  [RPL_STATSUPTIME] = ":Server Up %d days, %d:%02d:%02d",
  /* 243 */  [RPL_STATSOLINE] = "%c %s@%s * %s %s %s",
  /* 244 */  [RPL_STATSHLINE] = "%c %s * %s %u %s",
  /* 245 */  [RPL_STATSTLINE] = "T %s %s",
  /* 246 */  [RPL_STATSSERVICE] = "%c %s * %s %u %u",
  /* 247 */  [RPL_STATSXLINE] = "%c %u %s :%s",
  /* 248 */  [RPL_STATSULINE] = "U %s %s@%s %s",
  /* 250 */  [RPL_STATSCONN] = ":Highest connection count: %u (%u clients) (%llu connections received)",
  /* 251 */  [RPL_LUSERCLIENT] = ":There are %u users and %u invisible on %u servers",
  /* 252 */  [RPL_LUSEROP] = "%u :IRC Operators online",
  /* 253 */  [RPL_LUSERUNKNOWN] = "%u :unknown connection(s)",
  /* 254 */  [RPL_LUSERCHANNELS] = "%u :channels formed",
  /* 255 */  [RPL_LUSERME] = ":I have %u clients and %u servers",
  /* 256 */  [RPL_ADMINME] = ":Administrative info about %s",
  /* 257 */  [RPL_ADMINLOC1] = ":%s",
  /* 258 */  [RPL_ADMINLOC2] = ":%s",
  /* 259 */  [RPL_ADMINEMAIL] = ":%s",
  /* 262 */  [RPL_ENDOFTRACE] = "%s :End of TRACE",
  /* 263 */  [RPL_LOAD2HI] = "%s :Server load is temporarily too heavy. Please wait a while and try again.",
  /* 265 */  [RPL_LOCALUSERS] = ":Current local users: %u  Max: %u",
  /* 266 */  [RPL_GLOBALUSERS] = ":Current global users: %u  Max: %u",
  /* 276 */  [RPL_WHOISCERTFP] = "%s :has client certificate fingerprint %s",
  /* 281 */  [RPL_ACCEPTLIST] = ":%s",
  /* 282 */  [RPL_ENDOFACCEPT] = ":End of /ACCEPT list.",
  /* 301 */  [RPL_AWAY] = "%s :%s",
  /* 302 */  [RPL_USERHOST] = ":%s 302 %s :%s",
  /* 303 */  [RPL_ISON] = ":%s 303 %s :",
  /* 305 */  [RPL_UNAWAY] = ":You are no longer marked as being away",
  /* 306 */  [RPL_NOWAWAY] = ":You have been marked as being away",
  /* 307 */  [RPL_WHOISREGNICK] = "%s :has identified for this nick",
  /* 311 */  [RPL_WHOISUSER] = "%s %s %s * :%s",
  /* 312 */  [RPL_WHOISSERVER] = "%s %s :%s",
  /* 313 */  [RPL_WHOISOPERATOR] = "%s :%s",
  /* 314 */  [RPL_WHOWASUSER] = "%s %s %s * :%s",
  /* 315 */  [RPL_ENDOFWHO] = "%s :End of /WHO list.",
  /* 317 */  [RPL_WHOISIDLE] = "%s %u %d :seconds idle, signon time",
  /* 318 */  [RPL_ENDOFWHOIS] = "%s :End of /WHOIS list.",
  /* 319 */  [RPL_WHOISCHANNELS] = ":%s 319 %s %s :%s",
  /* 321 */  [RPL_LISTSTART] = "Channel :Users  Name",
  /* 322 */  [RPL_LIST] = "%s %u :%s%s",
  /* 323 */  [RPL_LISTEND] = ":End of /LIST",
  /* 324 */  [RPL_CHANNELMODEIS] = "%s %s %s",
  /* 329 */  [RPL_CREATIONTIME] = "%s %lu",
  /* 330 */  [RPL_WHOISACCOUNT] = "%s %s :%s logged in as",
  /* 331 */  [RPL_NOTOPIC] = "%s :No topic is set.",
  /* 332 */  [RPL_TOPIC] = "%s :%s",
  /* 333 */  [RPL_TOPICWHOTIME] = "%s %s %lu",
  /* 335 */  [RPL_WHOISTEXT] = "%s :%s",
  /* 336 */  [RPL_INVITELIST] = ":%s",
  /* 337 */  [RPL_ENDOFINVITELIST] = ":End of /INVITE list.",
  /* 338 */  [RPL_WHOISACTUALLY] = "%s %s@%s %s :Actual user@host, actual IP",
  /* 341 */  [RPL_INVITING] = "%s %s",
  /* 346 */  [RPL_INVEXLIST] = "%s %s!%s@%s %s %lu",
  /* 347 */  [RPL_ENDOFINVEXLIST] = "%s :End of Channel Invite List",
  /* 348 */  [RPL_EXCEPTLIST] = "%s %s!%s@%s %s %lu",
  /* 349 */  [RPL_ENDOFEXCEPTLIST] = "%s :End of Channel Exception List",
  /* 351 */  [RPL_VERSION] = "%s(%s). %s :%s",
  /* 352 */  [RPL_WHOREPLY] = "%s %s %s %s %s %s :%u %s",
  /* 353 */  [RPL_NAMREPLY] = ":%s 353 %s %s %s :",
  /* 362 */  [RPL_CLOSING] = "%s :Closed. Status = %d",
  /* 363 */  [RPL_CLOSEEND] = "%u: Connections closed",
  /* 364 */  [RPL_LINKS] = "%s %s :%u %s",
  /* 365 */  [RPL_ENDOFLINKS] = "%s :End of /LINKS list.",
  /* 366 */  [RPL_ENDOFNAMES] = "%s :End of /NAMES list.",
  /* 367 */  [RPL_BANLIST] = "%s %s!%s@%s %s %lu",
  /* 368 */  [RPL_ENDOFBANLIST] = "%s :End of Channel Ban List",
  /* 369 */  [RPL_ENDOFWHOWAS] = "%s :End of WHOWAS",
  /* 371 */  [RPL_INFO] = ":%s",
  /* 372 */  [RPL_MOTD] = ":- %s",
  /* 373 */  [RPL_INFOSTART] = ":Server INFO",
  /* 374 */  [RPL_ENDOFINFO] = ":End of /INFO list.",
  /* 375 */  [RPL_MOTDSTART] = ":- %s Message of the Day - ",
  /* 376 */  [RPL_ENDOFMOTD] = ":End of /MOTD command.",
  /* 379 */  [RPL_WHOISMODES] = "%s :is using modes %s",
  /* 381 */  [RPL_YOUREOPER] = ":You have entered... the Twilight Zone!",
  /* 382 */  [RPL_REHASHING] = "%s :Rehashing",
  /* 386 */  [RPL_RSACHALLENGE] = ":%s",
  /* 391 */  [RPL_TIME] = "%s :%s",
  /* 396 */  [RPL_VISIBLEHOST] = "%s :is now your visible host",
  /* 401 */  [ERR_NOSUCHNICK] = "%s :No such nick/channel",
  /* 402 */  [ERR_NOSUCHSERVER] = "%s :No such server",
  /* 403 */  [ERR_NOSUCHCHANNEL] = "%s :No such channel",
  /* 404 */  [ERR_CANNOTSENDTOCHAN] = "%s :Cannot send to channel",
  /* 405 */  [ERR_TOOMANYCHANNELS] = "%s :You have joined too many channels",
  /* 406 */  [ERR_WASNOSUCHNICK] = "%s :There was no such nickname",
  /* 407 */  [ERR_TOOMANYTARGETS] = "%s :Too many recipients. Only %u processed",
  /* 408 */  [ERR_NOCTRLSONCHAN] = "%s :You cannot use control codes on this channel. Not sent: %s",
  /* 409 */  [ERR_NOORIGIN] = ":No origin specified",
  /* 410 */  [ERR_INVALIDCAPCMD] = "%s :Invalid CAP subcommand",
  /* 411 */  [ERR_NORECIPIENT] = ":No recipient given (%s)",
  /* 412 */  [ERR_NOTEXTTOSEND] = ":No text to send",
  /* 413 */  [ERR_NOTOPLEVEL] = "%s :No top-level domain specified",
  /* 414 */  [ERR_WILDTOPLEVEL] = "%s :Wildcard in top-level domain",
  /* 421 */  [ERR_UNKNOWNCOMMAND] = "%s :Unknown command",
  /* 422 */  [ERR_NOMOTD] = ":MOTD File is missing",
  /* 423 */  [ERR_NOADMININFO] = "%s :No administrative info available",
  /* 429 */  [ERR_TOOMANYAWAY] = ":Too many aways - Flood protection activated",
  /* 431 */  [ERR_NONICKNAMEGIVEN] = ":No nickname given",
  /* 432 */  [ERR_ERRONEUSNICKNAME] = "%s :%s",
  /* 433 */  [ERR_NICKNAMEINUSE] = "%s :Nickname is already in use.",
  /* 436 */  [ERR_NICKCOLLISION] = "%s :Nickname collision KILL",
  /* 438 */  [ERR_NICKTOOFAST] = "%s :Nick change too fast. Please wait %u seconds.",
  /* 440 */  [ERR_SERVICESDOWN] = "%s :Services are currently unavailable.",
  /* 441 */  [ERR_USERNOTINCHANNEL] = "%s %s :They aren't on that channel",
  /* 442 */  [ERR_NOTONCHANNEL] = "%s :You are not on that channel",
  /* 443 */  [ERR_USERONCHANNEL] = "%s %s :is already on channel",
  /* 451 */  [ERR_NOTREGISTERED] = ":You have not registered",
  /* 456 */  [ERR_ACCEPTFULL] = ":Accept list is full",
  /* 457 */  [ERR_ACCEPTEXIST] = "%s!%s@%s :is already on your accept list",
  /* 458 */  [ERR_ACCEPTNOT] = "%s!%s@%s :is not on your accept list",
  /* 461 */  [ERR_NEEDMOREPARAMS] = "%s :Not enough parameters",
  /* 462 */  [ERR_ALREADYREGISTRED] = ":You may not reregister",
  /* 464 */  [ERR_PASSWDMISMATCH] = ":Password incorrect",
  /* 465 */  [ERR_YOUREBANNEDCREEP] = ":You are banned from this server- %s",
  /* 468 */  [ERR_ONLYSERVERSCANCHANGE] = "%s :Only servers can change that mode",
  /* 471 */  [ERR_CHANNELISFULL] = "%s :Cannot join channel (+l)",
  /* 472 */  [ERR_UNKNOWNMODE] = "%c :is unknown mode char to me",
  /* 473 */  [ERR_INVITEONLYCHAN] = "%s :Cannot join channel (+i)",
  /* 474 */  [ERR_BANNEDFROMCHAN] = "%s :Cannot join channel (+b)",
  /* 475 */  [ERR_BADCHANNELKEY] = "%s :Cannot join channel (+k)",
  /* 477 */  [ERR_NEEDREGGEDNICK] = "%s :You need to identify to a registered nick to join or speak in that channel.",
  /* 478 */  [ERR_BANLISTFULL] = "%s %s :Channel ban list is full",
  /* 479 */  [ERR_BADCHANNAME] = "%s :Illegal channel name",
  /* 481 */  [ERR_NOPRIVILEGES] = ":Permission denied - You are not an IRC operator",
  /* 482 */  [ERR_CHANOPRIVSNEEDED] = "%s :You are not channel operator",
  /* 483 */  [ERR_CANTKILLSERVER] = ":You cannot kill a server!",
  /* 485 */  [ERR_CHANBANREASON] = "%s :Cannot join channel (%s)",
  /* 486 */  [ERR_NONONREG] = "%s :You must identify to a registered nick to private message that person",
  /* 489 */  [ERR_SSLONLYCHAN] = "%s :Cannot join channel (+S)",
  /* 491 */  [ERR_NOOPERHOST] = ":Only few of mere mortals may try to enter the twilight zone",
  /* 492 */  [ERR_NOCTCP] = "%s :You cannot send CTCPs to this channel. Not sent: %s",
  /* 501 */  [ERR_UMODEUNKNOWNFLAG] = ":Unknown MODE flag",
  /* 502 */  [ERR_USERSDONTMATCH] = ":Cannot change mode for other users",
  /* 504 */  [ERR_USERNOTONSERV] = "%s :User is not on this server",
  /* 512 */  [ERR_TOOMANYWATCH] = "%s :Maximum size for WATCH-list is %u entries",
  /* 513 */  [ERR_WRONGPONG] = ":To connect type /QUOTE PONG %u",
  /* 520 */  [ERR_OPERONLYCHAN] = "%s :Cannot join channel (+O)",
  /* 521 */  [ERR_LISTSYNTAX] = ":Bad list syntax, type /QUOTE HELP LIST",
  /* 523 */  [ERR_WHOLIMEXCEED] = "%u :%s search limit exceeded.",
  /* 524 */  [ERR_HELPNOTFOUND] = "%s :Help not found",
  /* 600 */  [RPL_LOGON] = "%s %s %s %d :logged online",
  /* 601 */  [RPL_LOGOFF] = "%s %s %s %d :logged offline",
  /* 602 */  [RPL_WATCHOFF] = "%s %s %s %d :stopped watching",
  /* 603 */  [RPL_WATCHSTAT] = ":You have %u and are on %u WATCH entries",
  /* 604 */  [RPL_NOWON] = "%s %s %s %d :is online",
  /* 605 */  [RPL_NOWOFF] = "%s %s %s %d :is offline",
  /* 606 */  [RPL_WATCHLIST] = ":%s",
  /* 607 */  [RPL_ENDOFWATCHLIST] = ":End of WATCH %c",
  /* 671 */  [RPL_WHOISSECURE] = "%s :is connected via SSL (secure link)",
  /* 702 */  [RPL_MODLIST] = "%s %p %s %s",
  /* 703 */  [RPL_ENDOFMODLIST] = ":End of /MODULE LIST.",
  /* 704 */  [RPL_HELPSTART] = "%s :%s",
  /* 705 */  [RPL_HELPTXT] = "%s :%s",
  /* 706 */  [RPL_ENDOFHELP] = "%s :End of /HELP.",
  /* 709 */  [RPL_ETRACE] = "%s %s %s %s %s %s :%s",
  /* 710 */  [RPL_KNOCK] = "%s %s!%s@%s :has asked for an invite.",
  /* 711 */  [RPL_KNOCKDLVR] = "%s :Your KNOCK has been delivered.",
  /* 712 */  [ERR_TOOMANYKNOCK] = "%s :Too many KNOCKs (%s).",
  /* 713 */  [ERR_CHANOPEN] = "%s :Channel is open.",
  /* 714 */  [ERR_KNOCKONCHAN] = "%s :You are already on that channel.",
  /* 715 */  [ERR_TOOMANYINVITE] = "%s :Too many INVITEs (%s).",
  /* 716 */  [RPL_TARGUMODEG] = "%s :is in %s mode (%s)",
  /* 717 */  [RPL_TARGNOTIFY] = "%s :has been informed that you messaged them.",
  /* 718 */  [RPL_UMODEGMSG] = "%s %s@%s :is messaging you, and you are umode %s.",
  /* 723 */  [ERR_NOPRIVS] = "%s :Insufficient oper privileges.",
  /* 999 */  [ERR_LAST_ERR_MSG] = ":Last error message"
};

/*
 * numeric_form
 *
 * inputs       - numeric
 * output       - corresponding string
 * side effects - NONE
 */
const char *
numeric_form(enum irc_numerics numeric)
{
  assert(numeric < ERR_LAST_ERR_MSG);

  if (numeric > ERR_LAST_ERR_MSG)
    numeric = ERR_LAST_ERR_MSG;

  assert(replies[numeric]);

  return replies[numeric];
}
