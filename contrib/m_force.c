/* contrib/m_force.c
 * Copyright (C) 2002, 2003, 2004, 2005 Hybrid Development Team
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are
 *  met:
 *
 *  1.Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  2.Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  3.The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 *  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 *  INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 *  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 *  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 *  IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "irc_string.h"
#include "numeric.h"
#include "fdlist.h"
#include "hash.h"
#include "s_bsd.h"
#include "conf.h"
#include "s_serv.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "channel.h"
#include "channel_mode.h"


/* m_forcejoin()
 *  parv[0] = sender prefix
 *  parv[1] = user to force
 *  parv[2] = channel to force them into
 */
static void
mo_forcejoin(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  unsigned int type = 0;
  char mode = '\0';
  char sjmode = '\0';
  char *newch = NULL;
  dlink_node *ptr = NULL;

  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((target_p = hash_find_client(parv[1])) == NULL || !IsClient(target_p))
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, parv[1]);
    return;
  }

  if (!MyConnect(target_p))
  {
    if (target_p->from != client_p)
    {
      if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s FORCEJOIN %s %s",
                   source_p->name, target_p->from->name,
                   target_p->name, parv[2]);
      else
        sendto_one(target_p, ":%s FORCEJOIN %s %s",
                   source_p->name, target_p->name, parv[2]);
    }

    return;
  }

  /* select our modes from parv[2] if they exist... (chanop)*/
  switch (*parv[2])
  {
    case '@':
      type = CHFL_CHANOP;
      mode = 'o';
      sjmode = '@';
      parv[2]++;
      break;
#ifdef HALFOPS
    case '%':
      type = CHFL_HALFOP;
      mode = 'h';
      sjmode = '%';
      parv[2]++;
      break;
#endif
    case '+':
      type = CHFL_VOICE;
      mode = 'v';
      sjmode = '+';
      parv[2]++;
      break;
    default:
      type = 0;
      mode = sjmode = '\0'; /* make sure sjmode is 0. sjoin depends on it */
      break;
  }

  if ((chptr = hash_find_channel(parv[2])) != NULL)
  {
    if (IsMember(target_p, chptr))
    {
      sendto_one(source_p, ":%s NOTICE %s :*** Notice -- %s is already in %s",
                 me.name, source_p->name, target_p->name, chptr->chname);
      return;
    }

    add_user_to_channel(chptr, target_p, type, 0);

    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname);

    if (sjmode)
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +%c %s",
                           me.name, chptr->chname, mode, target_p->name);

    if (chptr->chname[0] == '#')
    {
      if (sjmode)
      {
        DLINK_FOREACH (ptr, serv_list.head)
        {
          struct Client *serv_p = ptr->data;
          if (serv_p == target_p->from || IsDead(serv_p))
            continue;

          sendto_one(serv_p, ":%s SJOIN %lu %s + :%c%s",
                     ID_or_name(&me, serv_p), (unsigned long)chptr->channelts,
                     chptr->chname, (sjmode == '%' &&
                     !IsCapable(serv_p, CAP_HOPS)) ? '@' : sjmode,
                     ID_or_name(target_p, serv_p));
        }
      }
      else
      {
        sendto_server(target_p, CAP_TS6, NOCAPS,
                      ":%s SJOIN %lu %s + :%s",
                      me.id, (unsigned long)chptr->channelts,
                      chptr->chname, target_p->id);
        sendto_server(target_p, NOCAPS, CAP_TS6,
                      ":%s SJOIN %lu %s + :%s",
                      me.name, (unsigned long)chptr->channelts,
                      chptr->chname, target_p->name);
      }
    }

    if (chptr->topic[0])
    {
      sendto_one(target_p, form_str(RPL_TOPIC),
                 me.name, target_p->name,
                 chptr->chname, chptr->topic);
      sendto_one(target_p, form_str(RPL_TOPICWHOTIME),
                 me.name, target_p->name, chptr->chname,
                 chptr->topic_info, chptr->topic_time);
    }

    target_p->localClient->last_join_time = CurrentTime;
    channel_member_names(target_p, chptr, 1);
  }
  else
  {
    newch = parv[2];

    if (!check_channel_name(newch, 1))
    {
      sendto_one(source_p, form_str(ERR_BADCHANNAME),
                 me.name, source_p->name, newch);
      return;
    }

    chptr = make_channel(newch);
    add_user_to_channel(chptr, target_p, CHFL_CHANOP, 0);

    sendto_server(target_p, CAP_TS6, NOCAPS,
                  ":%s SJOIN %lu %s +nt :@%s",
                  me.id, (unsigned long)chptr->channelts,
                  chptr->chname, ID(target_p));
    sendto_server(target_p, NOCAPS, CAP_TS6,
                  ":%s SJOIN %lu %s +nt :@%s",
                  me.name, (unsigned long)chptr->channelts,
                  chptr->chname, target_p->name);

    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN :%s",
                         target_p->name, target_p->username,
                         target_p->host, chptr->chname);

    chptr->mode.mode |= MODE_TOPICLIMIT | MODE_NOPRIVMSGS;

    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +nt",
                         me.name, chptr->chname);

    target_p->localClient->last_join_time = CurrentTime;
    channel_member_names(target_p, chptr, 1);

    /* we do this to let the oper know that a channel was created, this will be
     * seen from the server handling the command instead of the server that
     * the oper is on.
     */
    sendto_one(source_p, ":%s NOTICE %s :*** Notice -- Creating channel %s",
               me.name, source_p->name, chptr->chname);
  }
}

static void
mo_forcepart(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  struct Membership *member = NULL;

  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  /* if target_p == NULL then let the oper know */
  if ((target_p = hash_find_client(parv[1])) == NULL || !IsClient(target_p))
  {
    sendto_one(source_p, form_str(ERR_NOSUCHNICK),
               me.name, source_p->name, parv[1]);
    return;
  }

  if (!MyConnect(target_p))
  {
    if (target_p->from != client_p)
    {
      if (IsCapable(target_p->from, CAP_ENCAP))
        sendto_one(target_p, ":%s ENCAP %s FORCEPART %s %s",
                   source_p->name, target_p->from->name,
                   target_p->name, parv[2]);
      else
        sendto_one(target_p, ":%s FORCEPART %s %s",
                   source_p->name, target_p->name, parv[2]);
    }

    return;
  }

  if ((chptr = hash_find_channel(parv[2])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[2]);
    return;
  }

  if ((member = find_channel_link(target_p, chptr)) == NULL)
  {
    sendto_one(source_p, form_str(ERR_USERNOTINCHANNEL),
               me.name, source_p->name, chptr->chname, target_p->name);
    return;
  }

  sendto_server(target_p, CAP_TS6, NOCAPS,
                ":%s PART %s :%s", ID(target_p),
                chptr->chname, target_p->name);
  sendto_server(target_p, NOCAPS, CAP_TS6,
                ":%s PART %s :%s", target_p->name,
                chptr->chname, target_p->name);

  sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s PART %s :%s",
                       target_p->name, target_p->username,
                       target_p->host, chptr->chname,
                       target_p->name);
  remove_user_from_channel(member);
}

static struct Message forcejoin_msgtab = {
  "FORCEJOIN", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, mo_forcejoin, mo_forcejoin, mo_forcejoin, m_ignore }
};

static struct Message forcepart_msgtab = {
  "FORCEPART", 0, 0, 3, MAXPARA, MFLG_SLOW, 0,
  { m_ignore, m_not_oper, mo_forcepart, mo_forcepart, mo_forcepart, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&forcejoin_msgtab);
  mod_add_cmd(&forcepart_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&forcejoin_msgtab);
  mod_del_cmd(&forcepart_msgtab);
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
