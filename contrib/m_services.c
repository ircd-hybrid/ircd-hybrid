/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_services.c: SVS commands and Services support
 *
 *  Copyright (C) 2005 by the past and present ircd coders, and others.
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
/*
 *
 * With code from 'bane' the URL following is valid as of this date.
 * http://hybserv2.net/file/trunk/contrib/hybrid_services.c
 *
 *
 *   Copyright (C) 2002, 2003, 2004, 2005 by Dragan 'bane' Dosen and the
 *   Hybrid Development Team.
 *
 *   Based on m_services.c, originally from bahamut ircd.
 *
 *   Contact info:
 *
 *     E-mail : bane@idolnet.org
 *     IRC    : (*) bane, idolNET, irc.idolnet.org, #twilight_zone
 */

/* MODULE CONFIGURATION FOLLOWS -- please read!! */

/* Change this to the name of your services server
 * otherwise the services aliases will not work!
 */
#define SERVICES_NAME "services.yournet.net"

/* END OF MODULE CONFIGURATION */

#include "stdinc.h"
#include "handlers.h"
#include "client.h"
#include "hash.h"
#include "fdlist.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_conf.h"
#include "s_stats.h"
#include "s_user.h"
#include "whowas.h"
#include "s_serv.h"
#include "send.h"
#include "list.h"
#include "channel.h"
#include "s_log.h"
#include "resv.h"
#include "msg.h"
#include "parse.h"
#include "modules.h"
#include "common.h"
#include "packet.h"
#include "sprintf_irc.h"

/* Custom Macros */
#define services_function(a,b,c) static void a(struct Client *client_p,\
        struct Client *source_p, int parc,\
        char *parv[]) \
{ deliver_services_msg(b, c, client_p, source_p, parc, parv); }

static void mo_svsnick(struct Client *, struct Client *, int, char *[]);

static void m_botserv(struct Client *, struct Client *, int, char *[]);
static void m_chanserv(struct Client *, struct Client *, int, char *[]);
static void m_global(struct Client *, struct Client *, int, char *[]);
static void m_helpserv(struct Client *, struct Client *, int, char *[]);
static void m_hostserv(struct Client *, struct Client *, int, char *[]);
static void m_identify(struct Client *, struct Client *, int, char *[]);
static void m_memoserv(struct Client *, struct Client *, int, char *[]);
static void m_nickserv(struct Client *, struct Client *, int, char *[]);
static void m_operserv(struct Client *, struct Client *, int, char *[]);
static void m_seenserv(struct Client *, struct Client *, int, char *[]);
static void m_statserv(struct Client *, struct Client *, int, char *[]);

static void get_string(int, char *[], char *);
static int clean_nick_name(char *, int);
static void deliver_services_msg(const char *, const char *, struct Client *,
                                 struct Client *, int, char *[]);

/* SVS commands */
struct Message svsnick_msgtab = {
  "SVSNICK", 0, 0, 3, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, mo_svsnick, mo_svsnick, mo_svsnick, m_ignore}
};

/* Services */
struct Message botserv_msgtab = {
  "BOTSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_botserv, m_ignore, m_ignore, m_botserv, m_ignore}
};

struct Message chanserv_msgtab = {
  "CHANSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

struct Message global_msgtab = {
  "GLOBAL", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_global, m_ignore, m_ignore, m_global, m_ignore}
};

struct Message helpserv_msgtab = {
  "HELPSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_helpserv, m_ignore, m_ignore, m_helpserv, m_ignore}
};

struct Message hostserv_msgtab = {
  "HOSTSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_hostserv, m_ignore, m_ignore, m_hostserv, m_ignore}
};

struct Message memoserv_msgtab = {
  "MEMOSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

struct Message nickserv_msgtab = {
  "NICKSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

struct Message operserv_msgtab = {
  "OPERSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

struct Message seenserv_msgtab = {
  "SEENSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_seenserv, m_ignore, m_ignore, m_seenserv, m_ignore}
};

struct Message statserv_msgtab = {
  "STATSERV", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_statserv, m_ignore, m_ignore, m_statserv, m_ignore}
};

/* Short-hand aliases for NickServ, ChanServ, MemoServ and OperServ */
struct Message cs_msgtab = {
  "CS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_chanserv, m_ignore, m_ignore, m_chanserv, m_ignore}
};

struct Message identify_msgtab = {
  "IDENTIFY", 0, 0, 0, 2, MFLG_SLOW, 0,
  {m_unregistered, m_identify, m_ignore, m_ignore, m_identify, m_ignore}
};

struct Message ms_msgtab = {
  "MS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_memoserv, m_ignore, m_ignore, m_memoserv, m_ignore}
};

struct Message ns_msgtab = {
  "NS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_nickserv, m_ignore, m_ignore, m_nickserv, m_ignore}
};

struct Message os_msgtab = {
  "OS", 0, 0, 1, 0, MFLG_SLOW, 0,
  {m_unregistered, m_operserv, m_ignore, m_ignore, m_operserv, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&svsnick_msgtab);
  mod_add_cmd(&botserv_msgtab);
  mod_add_cmd(&chanserv_msgtab); 
  mod_add_cmd(&global_msgtab);
  mod_add_cmd(&helpserv_msgtab);
  mod_add_cmd(&hostserv_msgtab);
  mod_add_cmd(&identify_msgtab);
  mod_add_cmd(&memoserv_msgtab);
  mod_add_cmd(&nickserv_msgtab);
  mod_add_cmd(&operserv_msgtab);
  mod_add_cmd(&seenserv_msgtab);
  mod_add_cmd(&statserv_msgtab);
  mod_add_cmd(&ns_msgtab);
  mod_add_cmd(&cs_msgtab);
  mod_add_cmd(&ms_msgtab);
  mod_add_cmd(&os_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&svsnick_msgtab);
  mod_del_cmd(&botserv_msgtab);
  mod_del_cmd(&chanserv_msgtab); 
  mod_del_cmd(&global_msgtab);
  mod_del_cmd(&helpserv_msgtab);
  mod_del_cmd(&hostserv_msgtab);
  mod_del_cmd(&identify_msgtab);
  mod_del_cmd(&memoserv_msgtab);
  mod_del_cmd(&nickserv_msgtab);
  mod_del_cmd(&operserv_msgtab);
  mod_del_cmd(&seenserv_msgtab);
  mod_del_cmd(&statserv_msgtab);
  mod_del_cmd(&ns_msgtab);
  mod_del_cmd(&cs_msgtab);
  mod_del_cmd(&ms_msgtab);
  mod_del_cmd(&os_msgtab);
}

const char *_version = "$Revision$";
#endif

/*
 * mo_svsnick()
 *
 * parv[0] = sender prefix
 * parv[1] = user to force
 * parv[2] = nick to force them to
 */
static void
mo_svsnick(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char newnick[NICKLEN];
  struct Client *target_p = NULL;

  if (MyClient(source_p) && !IsOperAdmin(source_p))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVS),
               me.name, parv[0], "SVSNICK");
    return;
  }

  if (parc < 3 || *parv[2] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, parv[0], "SVSNICK");
    return;
  }

  if ((target_p = find_person(client_p, parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, parv[0], parv[1]);
    return;
  }

  /* terminate nick to NICKLEN */
  strlcpy(newnick, parv[2], sizeof(newnick));

  if (!clean_nick_name(newnick, 1))
  {
    if (IsClient(source_p))
      sendto_one(source_p, ":%s NOTICE %s :*** Notice -- Invalid new ",
                 "nickname: %s", me.name, parv[0], newnick);
    return;
  }

  if (find_client(newnick) != NULL)
  {
    if (IsClient(source_p))
      sendto_one(source_p, ":%s NOTICE %s :*** Notice -- Nickname %s is "
                 "already in use", me.name, parv[0], newnick);
    return;
  }

  if (MyConnect(target_p))
    change_local_nick(&me, target_p, newnick);
  else
    sendto_one(target_p, ":%s ENCAP %s SVSNICK %s %s",
               me.name, target_p->servptr->name, ID(target_p), newnick);
}

/*
 * These generate the services functions through
 * a macro.
 */
services_function(m_botserv,  "BotServ",  "BOTSERV" )
services_function(m_chanserv, "ChanServ", "CHANSERV")
services_function(m_global,   "Global",   "GLOBAL"  )
services_function(m_helpserv, "HelpServ", "HELPSERV")
services_function(m_hostserv, "HostServ", "HOSTSERV")
services_function(m_memoserv, "MemoServ", "MEMOSERV")
services_function(m_nickserv, "NickServ", "NICKSERV")
services_function(m_operserv, "OperServ", "OPERSERV")
services_function(m_seenserv, "SeenServ", "SEENSERV")
services_function(m_statserv, "StatServ", "STATSERV")

/*
 * get_string() 
 *
 * Reverse the array parv back into a normal string assuming
 * there are "parc" indicies in the array.
 *
 * Originally GetString() written by sidewndr.
 * Modified by Michael for use with hybrid-7.
*/
static void
get_string(int parc, char *parv[], char *buf)
{
  int ii = 0;
  int bw = 0;

  for (; ii < parc; ++ii)
    bw += ircsprintf(buf+bw, "%s ", parv[ii]);
  buf[bw-1] = '\0';
}

/*
 * clean_nick_name()
 *
 * input        - nickname
 * output       - none
 * side effects - walks through the nickname, returning 0 if erroneous
 */
static int
clean_nick_name(char *nick, int local)
{
  assert(nick);

  /* nicks can't start with a digit or - or be 0 length */
  /* This closer duplicates behaviour of hybrid-6 */

  if (*nick == '-' || (IsDigit(*nick) && local) || *nick == '\0')
    return 0;

  for (; *nick; ++nick)
    if (!IsNickChar(*nick))
      return 0;

  return 1;
}

/*
 * m_identify()
 *
 * parv[0] = sender prefix
 * parv[1] = NickServ Password or Channel
 * parv[2] = ChanServ Password
 */
static void
m_identify(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  struct Client *target_p = NULL;

  switch (parc)
  {
    case 2:
      if (!(target_p = find_server(SERVICES_NAME)))
        sendto_one(source_p, form_str(ERR_SERVICESDOWN),
                   me.name, source_p->name);
      else
        sendto_one(target_p, ":%s PRIVMSG NickServ@%s :IDENTIFY %s",
                   source_p->name, SERVICES_NAME, parv[1]);
      break;

    case 3:
      if (!(target_p = find_server(SERVICES_NAME)))
        sendto_one(source_p, form_str(ERR_SERVICESDOWN),
                   me.name, source_p->name);
      else
        sendto_one(target_p, ":%s PRIVMSG ChanServ@%s :IDENTIFY %s %s",
                   source_p->name, SERVICES_NAME, parv[1], parv[2]);
      break;

    default:
      sendto_one(source_p, ":%s NOTICE %s :Syntax: IDENTIFY <password> "
                 "- for nickname", me.name, source_p->name);
      sendto_one(source_p, ":%s NOTICE %s :Syntax: IDENTIFY <channel> "
                 "<password> - for channel", me.name, source_p->name);
      break;
  }
}

/*
 * deliver_services_msg()
 *
 * parv[0] = sender prefix
 * servmsg = message for services (utilising GetString())
 *
 * Borrowed from HybServ -- knight-
 */
static void
deliver_services_msg(const char *service, const char *command,
                     struct Client *client_p,
                     struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  char buf[IRCD_BUFSIZE] = { '\0' };

  if (parc < 2 || *parv[1] == '\0')
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, command);
    return;
  }

  if (!(target_p = find_server(SERVICES_NAME)))
    sendto_one(source_p, form_str(ERR_SERVICESDOWN),
               me.name, source_p->name);
  else
  {
    get_string(parc - 1, parv + 1, buf);
    sendto_one(target_p, ":%s PRIVMSG %s@%s :%s",
               source_p->name, service, SERVICES_NAME, buf);
  }
}
