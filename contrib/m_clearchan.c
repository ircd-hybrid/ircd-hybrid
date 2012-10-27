/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_clearchan.c: Performs a channel takeover
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
#include "channel_mode.h"
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "s_serv.h"
#include "send.h"
#include "irc_string.h"
#include "sprintf_irc.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"


static void kick_list(struct Client *, struct Channel *);
static void remove_our_modes(struct Channel *);
static void remove_a_mode(struct Channel *, int, char);


/*
** mo_clearchan
**      parv[0] = sender prefix
**      parv[1] = channel
*/
static void
mo_clearchan(struct Client *client_p, struct Client *source_p,
             int parc, char *parv[])
{
  struct Channel *chptr = NULL;

  /* admins only */
  if (!HasUMode(source_p, UMODE_ADMIN))
  {
    sendto_one(source_p, form_str(ERR_NOPRIVILEGES),
               me.name, source_p->name);
    return;
  }

  if ((chptr = hash_find_channel(parv[1])) == NULL)
  {
    sendto_one(source_p, form_str(ERR_NOSUCHCHANNEL),
               me.name, source_p->name, parv[1]);
    return;
  }

  if (IsMember(source_p, chptr))
  {
    sendto_one(source_p, ":%s NOTICE %s :*** Please part %s before using CLEARCHAN",
               me.name, source_p->name, chptr->chname);
    return;
  }

  sendto_wallops_flags(UMODE_WALLOP, &me, "CLEARCHAN called for [%s] by %s!%s@%s",
                       chptr->chname, source_p->name, source_p->username, source_p->host);
  sendto_server(NULL, NOCAPS, NOCAPS,
                ":%s WALLOPS :CLEARCHAN called for [%s] by %s!%s@%s",
                me.name, chptr->chname, source_p->name, source_p->username,
                source_p->host);
  ilog(LOG_TYPE_IRCD, "CLEARCHAN called for [%s] by %s!%s@%s",
       chptr->chname, source_p->name, source_p->username, source_p->host);

  /*
   * Kill all the modes we have about the channel..
   * making everyone a peon
   */  
  remove_our_modes(chptr);

  /* SJOIN the user to give them ops, and lock the channel */
  sendto_server(client_p, CAP_TS6, NOCAPS,
                ":%s JOIN %lu %s +ntsi",
                source_p->id, (unsigned long)(chptr->channelts - 1),
                chptr->chname);
  sendto_server(client_p, NOCAPS, CAP_TS6,
                ":%s SJOIN %lu %s +ntsi :@%s",
                me.name, (unsigned long)(chptr->channelts - 1),
                chptr->chname, source_p->name);
  sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s!%s@%s JOIN %s",
                       source_p->name, source_p->username,
                       source_p->host, chptr->chname);
  sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s +o %s",
                       me.name, chptr->chname, source_p->name);


  /*
   * Take the TS down by 1, so we don't see the channel taken over
   * again.
   */
  if (chptr->channelts)
    --chptr->channelts;

  chptr->mode.mode = MODE_SECRET | MODE_TOPICLIMIT |
                     MODE_INVITEONLY | MODE_NOPRIVMSGS;

  set_channel_topic(chptr, "", "", 0);
  chptr->mode.key[0] = '\0';

  /* Kick the users out and join the oper */
  kick_list(source_p, chptr);
}

static void
kick_list(struct Client *source_p, struct Channel *chptr)
{
  dlink_node *ptr = NULL, *ptr_next = NULL;
  struct Membership *ms = NULL;

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    ms = ptr->data;

    sendto_channel_local(ALL_MEMBERS, 0, chptr,
                         ":%s!%s@%s KICK %s %s CLEARCHAN",
                         source_p->name, source_p->username,
                         source_p->host, chptr->chname, ms->client_p->name);
    sendto_server(NULL, NOCAPS, NOCAPS,
                  ":%s KICK %s %s :CLEARCHAN", source_p->name,
                  chptr->chname, ms->client_p->name);
  }

  add_user_to_channel(chptr, source_p, CHFL_CHANOP, 0);

  DLINK_FOREACH_SAFE(ptr, ptr_next, chptr->members.head)
  {
    ms = ptr->data;

    if (ms->client_p != source_p)
      remove_user_from_channel(ms);
  }

  /*
   * Join the user themselves to the channel down here, so they dont see a nicklist
   * or people being kicked
   */
  sendto_one(source_p, ":%s!%s@%s JOIN %s",
             source_p->name, source_p->username,
             source_p->host, chptr->chname);
  channel_member_names(source_p, chptr, 1);
}

/* remove_our_modes()
 *
 * inputs       - hide from ops or not int flag
 *              - pointer to channel to remove modes from
 *              - client pointer
 * output       - NONE
 * side effects - Go through the local members, remove all their
 *                chanop modes etc., this side lost the TS.
 */
static void
remove_our_modes(struct Channel *chptr)
{
  remove_a_mode(chptr, CHFL_CHANOP, 'o');
#ifdef HALFOPS
  remove_a_mode(chptr, CHFL_HALFOP, 'h');
#endif
  remove_a_mode(chptr, CHFL_VOICE, 'v');

  /* Clear all +beI modes */
  free_channel_list(&chptr->banlist);
  free_channel_list(&chptr->exceptlist);
  free_channel_list(&chptr->invexlist);
}

/* remove_a_mode()
 *
 * inputs	-
 * output	- NONE
 * side effects	- remove ONE mode from a channel
 */
static void
remove_a_mode(struct Channel *chptr, int mask, char flag)
{
  const dlink_node *ptr = NULL;
  char lmodebuf[MODEBUFLEN];
  const char *lpara[4] = { "", "", "", "" };
  char *mbuf = lmodebuf;
  int count = 0;

  *mbuf++ = '-';

  DLINK_FOREACH(ptr, chptr->members.head)
  {
    struct Membership *ms = ptr->data;
    if ((ms->flags & mask) == 0)
      continue;

    ms->flags &= ~mask;

    lpara[count++] = ms->client_p->name;

    *mbuf++ = flag;

    if (count == 4)
    {
      *mbuf = '\0';
      sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s %s %s %s %s",
                           me.name, chptr->chname, lmodebuf, lpara[0],
                           lpara[1], lpara[2], lpara[3]);

      mbuf = lmodebuf;
      *mbuf++ = '-';
      count = 0;
      lpara[0] = lpara[1] = lpara[2] = lpara[3] = "";
    }
  }

  if (count != 0)
  {
    *mbuf = '\0';
    sendto_channel_local(ALL_MEMBERS, 0, chptr, ":%s MODE %s %s %s %s %s %s",
                         me.name, chptr->chname, lmodebuf, lpara[0],
                         lpara[1], lpara[2], lpara[3]);
  }
}

static struct Message clearchan_msgtab = {
  "CLEARCHAN", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, m_ignore, m_ignore, mo_clearchan, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&clearchan_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&clearchan_msgtab);
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
