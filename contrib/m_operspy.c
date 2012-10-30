/************************************************************************
 *   IRC - Internet Relay Chat, contrib/m_operspy.c
 *   Copyright (C) 2002 William Bierman III and the Hybrid Development Team
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 *   $Id$
 */

/***  PLEASE READ ME  ***/
/*
 *  This module gives an extraordinary amount of power to the opers
 *  who have the access to use it.  It allows for users' privacy to
 *  be pretty much obliterated.  The Hybrid Team assumes absolutely
 *  no responsibility for this file's (mis)use.
 *
 *    - billy-jon
 */

#include "stdinc.h"
#include "list.h"
#include "irc_string.h"
#include "channel.h"
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "sprintf_irc.h"
#include "numeric.h"
#include "fdlist.h"
#include "s_bsd.h"
#include "conf.h"
#include "log.h"
#include "s_serv.h"
#include "s_misc.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "hash.h"

/* enable logging of OPERSPY functions */
#define OPERSPY_LOG

/* enable this to log all local/remote operspy usage to a logfile */
#define OPERSPY_LOGFILE

/* enable this to send incoming operspy usage to connected +y (UMODE_SPY) opers */
#define OPERSPY_NOTICE

/* enable OPERSPY version of LIST */
#define OPERSPY_LIST

/* enable OPERSPY version of MODE */
#define OPERSPY_MODE

/* enable OPERSPY version of NAMES */
#define OPERSPY_NAMES

/* enable OPERSPY version of WHO */
#define OPERSPY_WHO

/* enable OPERSPY version of WHOIS */
#define OPERSPY_WHOIS

/* enable OPERSPY version of TOPIC */
#define OPERSPY_TOPIC

#define IsOperspy(x) (HasUMode(x, UMODE_OPER) && MyClient(x) && HasUMode(x, UMODE_ADMIN))

/* extensions for OPERSPY WHO */
static void do_who(struct Client *, struct Client *, char *, const char *);
static void who_global(struct Client *, char *, int);
static void do_who_on_channel(struct Client *, struct Channel *, char *);

static void operspy_list(struct Client *, int, char *[]);
static void operspy_mode(struct Client *, int, char *[]);
static void operspy_names(struct Client *, int, char *[]);
static void operspy_topic(struct Client *, int, char *[]);
static void operspy_who(struct Client *, int, char *[]);
static void operspy_whois(struct Client *, int, char *[]);
#ifdef OPERSPY_LOG
static void operspy_log(struct Client *, const char *, const char *);
#endif


static const struct operspy_s {
  const char *const cmd;
  void (*const func_p)(struct Client *, int, char *[]);
} operspy_table[] = {
#ifdef OPERSPY_LIST
  { "LIST", operspy_list },
#endif
#ifdef OPERSPY_MODE
  { "MODE", operspy_mode },
#endif
#ifdef OPERSPY_NAMES
  { "NAMES", operspy_names },
#endif
#ifdef OPERSPY_TOPIC
  { "TOPIC", operspy_topic },
#endif
#ifdef OPERSPY_WHO
  { "WHO", operspy_who },
#endif
#ifdef OPERSPY_WHOIS
  { "WHOIS", operspy_whois },
#endif
  { NULL, NULL }
};

static void
ms_operspy(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
#ifdef OPERSPY_LOG
  operspy_log(source_p, parv[1], parv[2]);
#endif
}

/* mo_operspy()
 *	parv[1] = operspy command
 *	parv[2] = command parameter
 */
static void
mo_operspy(struct Client *client_p, struct Client *source_p,
           int parc, char *parv[])
{
  char cmdbuf[IRCD_BUFSIZE] = "<NONE>"; /* in case everything is undef'd */
  size_t bcnt = 0;
  const struct operspy_s *optr = NULL;

  if (!IsOperspy(client_p))
  {
    sendto_one(client_p, form_str(ERR_NOPRIVILEGES),
               me.name, client_p->name);
    return;
  }

  assert(client_p == source_p);

  for (optr = operspy_table; optr->cmd; ++optr)
  {
    if (!irccmp(optr->cmd, parv[1]))
    {
      (*optr->func_p)(client_p, parc, parv);
      return;
    }
  }

  for (optr = operspy_table; optr->cmd; ++optr)
  {
    /* str*cat is slow and sucks */
    bcnt += strlcpy(cmdbuf+bcnt, optr->cmd, sizeof(cmdbuf)-bcnt);
    if ((optr + 1)->cmd != NULL && bcnt < (sizeof(cmdbuf)-2))
    {
      cmdbuf[bcnt++] = ',';
      cmdbuf[bcnt++] = ' ';
    }
  }

  sendto_one(client_p, ":%s NOTICE %s :%s is not a valid option.  Choose from %s",
             me.name, client_p->name, parv[1], cmdbuf);
}

static void
operspy_list(struct Client *client_p, int parc, char *parv[])
{
  const dlink_node *ptr = NULL;
#ifdef OPERSPY_LOG
  operspy_log(client_p, "LIST", parv[2]);
#endif

  if (*parv[2] == '\0')
    return;

  sendto_one(client_p, form_str(RPL_LISTSTART),
             me.name, client_p->name);

  DLINK_FOREACH(ptr, global_channel_list.head)
  {
    const struct Channel *chptr_list = ptr->data;

    if (match_chan(parv[2], chptr_list->chname))
    {
      sendto_one(client_p, form_str(RPL_LIST), me.name, client_p->name,
                 chptr_list->chname, dlink_list_length(&chptr_list->members),
                 chptr_list->topic);
    }
  }

  sendto_one(client_p, form_str(RPL_LISTEND),
             me.name, client_p->name);
}

static void
operspy_mode(struct Client *client_p, int parc, char *parv[])
{
  /* needed to preserve actual client status */
  int c_status = 0;
  char modebuf[MODEBUFLEN];
  char parabuf[MODEBUFLEN];
  struct Channel *chptr_mode = NULL;

  if ((chptr_mode = hash_find_channel(parv[2])) == NULL)
  {
    /*
     * according to m_mode.c, the channel *could* exist on the uplink still,
     * but I don't see how.  Even if it does, we won't be able to spy without
     * info.
     */ 
    sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, client_p->name, parv[2]);
    return;
  }

#ifdef OPERSPY_LOG
  operspy_log(client_p, "MODE", parv[2]);
#endif

  /* 
   * XXX - this is a dirty nasty kludge to trick channel_modes()
   * into giving us the key
   */
  c_status = client_p->status;
  client_p->status = STAT_SERVER;

  channel_modes(chptr_mode, client_p, modebuf, parabuf);
  client_p->status = c_status;

  sendto_one(client_p, form_str(RPL_CHANNELMODEIS),
             me.name, client_p->name, parv[2], modebuf, parabuf);
  sendto_one(client_p, form_str(RPL_CREATIONTIME),
             me.name, client_p->name, parv[2], chptr_mode->channelts);
}

static void
operspy_names(struct Client *client_p, int parc, char *parv[])
{
  /* as with mode, must preserve channel modes */
  struct Channel *chptr_names = NULL;

  if ((chptr_names = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, client_p->name, parv[2]);
    return;
  }

#ifdef OPERSPY_LOG
  operspy_log(client_p, "NAMES", parv[2]);
#endif

  /*
   * the way to go with this, rather than temporarily setting -sp,
   * is to temporarily add our client to the member list.  then
   * we can also list +i users.  an unfortunate side-effect of this
   * is that your nickname shows up in the list.  for now, there is
   * no easy way around it.
   */ 
  if (IsMember(client_p, chptr_names))
    channel_member_names(client_p, chptr_names, 1);
  else
  {
    add_user_to_channel(chptr_names, client_p, CHFL_CHANOP, 0);
    channel_member_names(client_p, chptr_names, 1);
    remove_user_from_channel(find_channel_link(client_p, chptr_names));
  }
}

static void
operspy_topic(struct Client *client_p, int parc, char *parv[])
{
  const struct Channel *chptr_topic = NULL;

  if ((chptr_topic = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(client_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, client_p->name, parv[2]);
    return;
  }

#ifdef OPERSPY_LOG
  operspy_log(client_p, "TOPIC", parv[2]);
#endif

  if (chptr_topic->topic[0] == '\0')
    sendto_one(client_p, form_str(RPL_NOTOPIC),
               me.name, client_p->name, parv[2]);
  else
  {
    sendto_one(client_p, form_str(RPL_TOPIC), me.name, client_p->name,
               chptr_topic->chname, chptr_topic->topic);
    sendto_one(client_p, form_str(RPL_TOPICWHOTIME), me.name,
               client_p->name, chptr_topic->chname, chptr_topic->topic_info,
               chptr_topic->topic_time);
  }
}

static void
operspy_who(struct Client *client_p, int parc, char *parv[])
{
  char *mask = parc > 2 ? parv[2] : NULL;
  int server_oper = parc > 3 ? (*parv[3] == 'o') : 0;
  struct Channel *chptr_who = NULL;
  struct Client *target_p_who = NULL;

  if (mask != NULL)
  {
    collapse(mask);

    if (*mask == '\0')
    {
      sendto_one(client_p, form_str(RPL_ENDOFWHO),
                 me.name, client_p->name, "*");
      return;
    }
  }
  else
  {
#ifdef OPERSPY_LOG
    operspy_log(client_p, "WHO", "*");
#endif
    who_global(client_p, NULL, server_oper);
    sendto_one(client_p, form_str(RPL_ENDOFWHO),
               me.name, client_p->name, "*");
    return;
  }

  /* /who #channel */
  if (IsChanPrefix(*mask))
  {
    if ((chptr_who = hash_find_channel(mask)) != NULL)
    {
#ifdef OPERSPY_LOG
      operspy_log(client_p, "WHO", mask);
#endif
      do_who_on_channel(client_p, chptr_who, chptr_who->chname);
    }

    sendto_one(client_p, form_str(RPL_ENDOFWHO),
               me.name, client_p->name, mask);
    return;
  }

  /* /who nick */
  if ((target_p_who = find_person(client_p, mask)) != NULL)
  {
#ifdef OPERSPY_LOG
    /* "nick!user@host server\0" */
    char nuh[NICKLEN + 1 + USERLEN + 1 + HOSTLEN + 1 + HOSTLEN + 1];

    snprintf(nuh, sizeof(nuh), "%s!%s@%s %s", target_p_who->name,
             target_p_who->username, target_p_who->host,
             target_p_who->servptr->name);
    operspy_log(client_p, "WHO", nuh);
#endif

    if (target_p_who->channel.head != NULL)
    {
      chptr_who =
        ((struct Membership *)target_p_who->channel.head->data)->chptr;

      do_who(client_p, target_p_who, chptr_who->chname,
             get_member_status(target_p_who->channel.head->data, 0));
    }
    else
      do_who(client_p, target_p_who, NULL, "");

    sendto_one(client_p, form_str(RPL_ENDOFWHO),
               me.name, client_p->name, mask);
    return;
  }

#ifdef OPERSPY_LOG
  operspy_log(client_p, "WHO", parv[2]);
#endif

  /* /who 0 */
  if (!strcmp(mask, "0"))
    who_global(client_p, NULL, server_oper);
  else
    who_global(client_p, mask, server_oper);

  /* nothing else? end of /who. */
  sendto_one(client_p, form_str(RPL_ENDOFWHO),
             me.name, client_p->name, mask);
}

static void
operspy_whois(struct Client *client_p, int parc, char *parv[])
{
  const dlink_node *lp;
  struct Channel *chptr_whois = NULL;
  struct Client *a2client_p;
  struct Client *target_p = NULL;
  char buf[IRCD_BUFSIZE];
#ifdef OPERSPY_LOG
  /* "nick!user@host server\0" */
  char nuh[NICKLEN + 1 + USERLEN + 1 + HOSTLEN + 1 + HOSTLEN + 1];
#endif
  char *t = NULL;
  int mlen, tlen;
  int cur_len = 0;
  int reply_to_send = 0;

  if (has_wildcards(parv[2]))
  {
    sendto_one(client_p, ":%s NOTICE %s :Do not use wildcards with this.",
               me.name, client_p->name);
    return;
  }

  if ((target_p = find_person(client_p, parv[2])) == NULL)
  {
    sendto_one(client_p, form_str(ERR_NOSUCHNICK),
               me.name, client_p->name, parv[2]);
    return;
  }

#ifdef OPERSPY_LOG
  snprintf(nuh, sizeof(nuh), "%s!%s@%s %s",
           target_p->name, target_p->username, target_p->host,
           target_p->servptr->name);
  operspy_log(client_p, "WHOIS", nuh);
#endif

  a2client_p = target_p->servptr;

  sendto_one(client_p, form_str(RPL_WHOISUSER), me.name,
             client_p->name, target_p->name, target_p->username,
             target_p->host, target_p->info);
  mlen = ircsprintf(buf, form_str(RPL_WHOISCHANNELS), me.name,
                    client_p->name, target_p->name, "");
  cur_len = mlen;
  t = buf + mlen;

  DLINK_FOREACH(lp, target_p->channel.head)
  {
    chptr_whois = ((struct Membership *)lp->data)->chptr;

    if ((cur_len + strlen(chptr_whois->chname) + 2) > (IRCD_BUFSIZE - 4))
    {
      sendto_one(client_p, "%s", buf);
      cur_len = mlen;
      t = buf + mlen;
    }

    tlen = ircsprintf(t, "%s%s%s ",
                     ShowChannel(client_p, chptr_whois) ? "" : "%",
                     get_member_status((struct Membership *)lp->data, 1),
                     chptr_whois->chname);
    t += tlen;
    cur_len += tlen;
    reply_to_send = 1;
  }

  if (reply_to_send == 1)
    sendto_one(client_p, "%s", buf);

  sendto_one(client_p, form_str(RPL_WHOISSERVER), me.name,
             client_p->name, target_p->name, a2client_p->name,
             a2client_p->info);

  if (HasUMode(target_p, UMODE_OPER))
    sendto_one(client_p, form_str(HasUMode(target_p, UMODE_ADMIN) ? RPL_WHOISADMIN :
               RPL_WHOISOPERATOR), me.name, client_p->name, target_p->name);

  if (MyConnect(target_p))
    sendto_one(client_p, form_str(RPL_WHOISIDLE), me.name,
               client_p->name, target_p->name,
               CurrentTime - target_p->localClient->last_privmsg,
               target_p->localClient->firsttime);
  sendto_one(client_p, form_str(RPL_ENDOFWHOIS),
             me.name, client_p->name, parv[2]);
}

/* extensions for OPERSPY WHO */
static void
do_who(struct Client *source_p, struct Client *target_p,
       char *chname, const char *op_flags)
{
  char status[8];

  snprintf(status, sizeof(status), "%c%s%s", target_p->away[0] ? 'G' : 'H',
           HasUMode(target_p, UMODE_OPER) ? "*" : "", op_flags);
  sendto_one(source_p, form_str(RPL_WHOREPLY), me.name, source_p->name,
             (chname) ? (chname) : "*",
             target_p->username,
             target_p->host,  target_p->servptr->name, target_p->name,
             status, target_p->hopcount, target_p->info);
}

static void
who_global(struct Client *source_p, char *mask, int server_oper)
{
  struct Client *target_p;
  dlink_node *lp;
  int maxmatches = 500;
                        
  /* list all matching visible clients */
  DLINK_FOREACH(lp, global_client_list.head)
  {
    target_p = lp->data;

    if (!IsClient(target_p))
      continue;

    if (server_oper && !HasUMode(target_p, UMODE_OPER))
      continue;

    if (!mask ||
        match(mask, target_p->name) || match(mask, target_p->username) ||
        match(mask, target_p->host) || match(mask, target_p->servptr->name) ||
        match(mask, target_p->info) ||
        (MyClient(target_p) && match(mask, target_p->sockhost)))
    {
      if (dlink_list_length(&target_p->channel))
      {
        struct Channel *chptr;
        static char fl[5];

        chptr = ((struct Membership *)(target_p->channel.head->data))->chptr;
        snprintf(fl, sizeof(fl), "%s",
                 get_member_status((struct Membership *)(target_p->channel.head->data), 0));

        do_who(source_p, target_p, chptr->chname, fl);
      }
      else
        do_who(source_p, target_p, NULL, "");

      if (maxmatches > 0)
      {
        if (--maxmatches == 0)
          return;
      }
    }
  }
}

static void
do_who_on_channel(struct Client *source_p, struct Channel *chptr,
                  char *chname)
{
  dlink_node *ptr;
  struct Membership *ms;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;
    do_who(source_p, ms->client_p, chname, get_member_status(ms, 0));
  }
}

#ifdef OPERSPY_LOG
static void
operspy_log(struct Client *source_p, const char *command, const char *target)
{
  struct ConfItem *conf = NULL;
#ifdef OPERSPY_LOGFILE
  FILE *operspy_fb;
  dlink_node *cnode;
  const char *opername = source_p->name;
  char linebuf[IRCD_BUFSIZE], logfile[IRCD_BUFSIZE];
#endif

  assert(source_p != NULL);

#ifdef OPERSPY_LOGFILE
  if (HasUMode(source_p, UMODE_OPER) && MyClient(source_p))
  {
    DLINK_FOREACH(cnode, source_p->localClient->confs.head)
    {
      conf = cnode->data;

      if (conf->type == OPER_TYPE)
        opername = conf->name;
    }
  }
  else if (!MyClient(source_p))
    opername = "remote";

  snprintf(logfile, sizeof(logfile), "%s/operspy.%s.log", LOGPATH, opername);
  if ((operspy_fb = fopen(logfile, "a")) == NULL)
    return;

  snprintf(linebuf, sizeof(linebuf), "[%s] OPERSPY %s %s %s\n",
           smalldate(CurrentTime),
           get_oper_name(source_p),
           command, target);
  fputs(linebuf, operspy_fb);
  fclose(operspy_fb);
#endif

#ifdef OPERSPY_NOTICE
  sendto_realops_flags(UMODE_SPY, L_ALL, SEND_NOTICE, "OPERSPY %s %s %s",
                       get_oper_name(source_p), command, target);
#endif

  if (MyClient(source_p))
    sendto_match_servs(source_p, "*", CAP_ENCAP, "ENCAP * OPERSPY %s :%s",
                       command, target);
}
#endif /* OPERSPY_LOG */

static struct Message operspy_msgtab = {
  "OPERSPY", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  {m_ignore, m_not_oper, ms_operspy, ms_operspy, mo_operspy, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&operspy_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&operspy_msgtab);
}

struct module module_entry = {
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
