/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_ojoin.c: Allows opers join channels with @%+ modes
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

#include "stdinc.h"
#include "list.h"
#include "channel.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "hash.h"
#include "s_serv.h"
#include "modules.h"
#include "channel_mode.h"
#include "parse.h"


/* mo_ojoin()
 *      parv[0] = sender prefix
 *      parv[1] = channels separated by commas
 */
static void
mo_ojoin(struct Client *client_p, struct Client *source_p,
         int parc, char *parv[])
{
  struct Channel *chptr = NULL;
  const char *prefix = "";
  char modeletter = '\0';
  char *name = parv[1];
  char *t = NULL;
  unsigned int flags = 0;
  dlink_node *ptr;

  /* admins only */
  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  for (name = strtoken(&t, name, ","); name;
       name = strtoken(&t, NULL, ","))
  {
    switch (*name)
    {
      case '@':
        prefix = "@";
        flags = CHFL_CHANOP;
        modeletter = 'o';
        ++name;
        break;
#ifdef HALFOPS
      case '%':
        prefix = "%";
        flags = CHFL_HALFOP;
        modeletter = 'h';
        ++name;
        break;
#endif
      case '+':
        prefix = "+";
        flags = CHFL_VOICE;
        modeletter = 'v';
        ++name;
        break;
      case '#':
        prefix = "";
        flags = 0;
        modeletter = '\0';
        break;

      default:
        sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                   me.name, source_p->name, name);
        continue;
    }

    /* Error checking here */
    if ((chptr = hash_find_channel(name)) == NULL)
      sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
                 me.name, source_p->name, name);
    else if (IsMember(source_p, chptr))
      sendto_one(source_p, ":%s NOTICE %s :Please part %s before using OJOIN",
                 me.name, source_p->name, name);
    else
    {
      add_user_to_channel(chptr, source_p, flags, 0);

      DLINK_FOREACH(ptr, serv_list.head)
      {
        struct Client *serv_p = ptr->data;

        sendto_one(serv_p, ":%s SJOIN %lu %s + :%s%s", ID_or_name(&me, serv_p),
                   (unsigned long)chptr->channelts, chptr->chname,
                   (*prefix == '%' && !IsCapable(serv_p, CAP_HOPS)) ?
                   "@" : prefix, ID_or_name(source_p, serv_p));
      }

      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN %s",
                           source_p->name, source_p->username,
                           source_p->host,
                           chptr->chname);

      if (modeletter != '\0')
        sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +%c %s",
                             me.name, chptr->chname, modeletter, source_p->name);

      /* send the topic... */
      if (chptr->topic[0])
      {
        sendto_one(source_p, form_str(RPL_TOPIC),
                   me.name, source_p->name, chptr->chname,
                   chptr->topic);
        sendto_one(source_p, form_str(RPL_TOPICWHOTIME),
                   me.name, source_p->name, chptr->chname,
                   chptr->topic_info, chptr->topic_time);
      }

      source_p->localClient->last_join_time = CurrentTime;
      channel_member_names(source_p, chptr, 1);
    }
  }
}

static struct Message ojoin_msgtab = {
  "OJOIN", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_ojoin, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&ojoin_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&ojoin_msgtab);
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
