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

/*! \file m_who.c
 * \brief Includes required functions for processing the WHO command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "channel.h"
#include "channel_mode.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "server.h"
#include "send.h"
#include "irc_string.h"
#include "conf.h"
#include "parse.h"
#include "modules.h"


#define WHO_MAX_REPLIES 500


/* do_who()
 *
 * inputs       - pointer to client requesting who
 *              - pointer to client to do who on
 *              - The reported name
 *              - channel flags
 * output       - NONE
 * side effects - do a who on given person
 */
static void
do_who(struct Client *source_p, struct Client *target_p,
       const char *name, const char *op_flags)
{
  char status[IRCD_BUFSIZE] = "";

  if (HasUMode(source_p, UMODE_OPER))
    snprintf(status, sizeof(status), "%c%s%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
             HasUMode(target_p, UMODE_OPER) ? "*" : "", op_flags);
  else
    snprintf(status, sizeof(status), "%c%s%s%s", target_p->away[0] ? 'G' : 'H',
             HasUMode(target_p, UMODE_REGISTERED) ? "r" : "",
             HasUMode(target_p, UMODE_OPER) &&
             !HasUMode(target_p, UMODE_HIDDEN) ? "*" : "", op_flags);

  if (ConfigServerHide.hide_servers || IsHidden(target_p->servptr))
    sendto_one_numeric(source_p, &me, RPL_WHOREPLY,
               (name) ? (name) : "*",
               target_p->username, target_p->host,
               HasUMode(source_p, UMODE_OPER) ? target_p->servptr->name : "*",
               target_p->name, status,
               HasUMode(source_p, UMODE_OPER) ? target_p->hopcount : 0, target_p->info);
  else
    sendto_one_numeric(source_p, &me, RPL_WHOREPLY,
               (name) ? (name) : "*", target_p->username,
               target_p->host, target_p->servptr->name, target_p->name,
               status, target_p->hopcount, target_p->info);
}

/* who_common_channel
 * inputs	- pointer to client requesting who
 * 		- pointer to channel member chain.
 *		- char * mask to match
 *		- int if oper on a server or not
 *		- pointer to int maxmatches
 * output	- NONE
 * side effects - lists matching clients on specified channel,
 * 		  marks matched clients.
 *
 */
static void
who_common_channel(struct Client *source_p, struct Channel *chptr, char *mask,
                   int server_oper, unsigned int *maxmatches)
{
  dlink_node *node = NULL;

  DLINK_FOREACH(node, chptr->members.head)
  {
    struct Client *target_p = ((struct Membership *)node->data)->client_p;

    if (!HasUMode(target_p, UMODE_INVISIBLE) || HasFlag(target_p, FLAGS_MARK))
      continue;

    if (server_oper)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    AddFlag(target_p, FLAGS_MARK);

    if ((mask == NULL) ||
      !match(mask, target_p->name) || !match(mask, target_p->username) ||
      !match(mask, target_p->host) ||
      ((!ConfigServerHide.hide_servers || HasUMode(source_p, UMODE_OPER)) &&
       !match(mask, target_p->servptr->name)) ||
      !match(mask, target_p->info))
    {
      do_who(source_p, target_p, NULL, "");

      if (*maxmatches > 0)
      {
        if (--(*maxmatches) == 0)
        {
          sendto_one_numeric(source_p, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
          return;
        }
      }
    }
  }
}

/* who_global()
 *
 * inputs	- pointer to client requesting who
 *		- char * mask to match
 *		- int if oper on a server or not
 * output	- NONE
 * side effects - do a global scan of all clients looking for match
 *		  this is slightly expensive on EFnet ...
 */
static void
who_global(struct Client *source_p, char *mask, int server_oper)
{
  dlink_node *node = NULL;
  unsigned int maxmatches = WHO_MAX_REPLIES;
  static time_t last_used = 0;

  if (!HasUMode(source_p, UMODE_OPER))
  {
    if ((last_used + ConfigGeneral.pace_wait) > CurrentTime)
    {
      sendto_one_numeric(source_p, &me, RPL_LOAD2HI, "WHO");
      return;
    }

    last_used = CurrentTime;
  }

  /* First, list all matching invisible clients on common channels */
  DLINK_FOREACH(node, source_p->channel.head)
  {
    struct Channel *chptr = ((struct Membership *)node->data)->chptr;
    who_common_channel(source_p, chptr, mask, server_oper, &maxmatches);
  }

  /* Second, list all matching visible clients */
  DLINK_FOREACH(node, global_client_list.head)
  {
    struct Client *target_p = node->data;

    if (!IsClient(target_p))
      continue;

    if (HasUMode(target_p, UMODE_INVISIBLE))
    {
      DelFlag(target_p, FLAGS_MARK);
      continue;
    }

    if (server_oper)
      if (!HasUMode(target_p, UMODE_OPER) ||
          (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
        continue;

    if (!mask ||
        !match(mask, target_p->name) || !match(mask, target_p->username) ||
        !match(mask, target_p->host) || !match(mask, target_p->servptr->name) ||
        !match(mask, target_p->info))
    {
      do_who(source_p, target_p, NULL, "");

      if (maxmatches > 0)
      {
        if (--maxmatches == 0)
        {
          sendto_one_numeric(source_p, &me, ERR_WHOLIMEXCEED, WHO_MAX_REPLIES, "WHO");
          return;
        }
      }
    }
  }
}

/* do_who_on_channel()
 *
 * inputs	- pointer to client requesting who
 *		- pointer to channel to do who on
 *		- The "real name" of this channel
 *		- int if source_p is a server oper or not
 *		- int if client is member or not
 *		- int server_op flag
 * output	- NONE
 * side effects - do a who on given channel
 */
static void
do_who_on_channel(struct Client *source_p, struct Channel *chptr,
                  int is_member, int server_oper)
{
  dlink_node *node = NULL;

  DLINK_FOREACH(node, chptr->members.head)
  {
    struct Membership *member = node->data;
    struct Client *target_p = member->client_p;

    if (is_member || !HasUMode(target_p, UMODE_INVISIBLE))
    {
      if (server_oper)
        if (!HasUMode(target_p, UMODE_OPER) ||
            (HasUMode(target_p, UMODE_HIDDEN) && !HasUMode(source_p, UMODE_OPER)))
          continue;
      do_who(source_p, target_p, chptr->name, get_member_status(member, !!HasCap(source_p, CAP_MULTI_PREFIX)));
    }
  }
}

/*! \brief WHO command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = nickname/channelname
 *      - parv[2] = additional selection flag, only 'o' for now
 */
static int
m_who(struct Client *source_p, int parc, char *parv[])
{
  struct Client *target_p = NULL;
  struct Channel *chptr = NULL;
  char *mask = parv[1];
  dlink_node *node = NULL;
  const int server_oper = parc > 2 ? (*parv[2] == 'o') : 0; /* Show OPERS only */

  /* See if mask is there, collapse it or return if not there */
  if (EmptyString(mask))
  {
    who_global(source_p, mask, server_oper);
    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, "*");
    return 0;
  }

  /* Mask isn't NULL at this point. repeat after me... -db */
  collapse(mask);

  /* '/who #some_channel' */
  if (IsChanPrefix(*mask))
  {
    /* List all users on a given channel */
    if ((chptr = hash_find_channel(mask)))
    {
      if (IsMember(source_p, chptr) || HasUMode(source_p, UMODE_ADMIN))
        do_who_on_channel(source_p, chptr, 1, server_oper);
      else if (!SecretChannel(chptr))
        do_who_on_channel(source_p, chptr, 0, server_oper);
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
    return 0;
  }

  /* '/who nick' */
  if ((target_p = find_person(source_p, mask)) &&
      (!server_oper || HasUMode(target_p, UMODE_OPER)))
  {
    DLINK_FOREACH(node, target_p->channel.head)
    {
      chptr = ((struct Membership *)node->data)->chptr;
      if (PubChannel(chptr) || IsMember(source_p, chptr))
        break;
    }

    if (node)
      do_who(source_p, target_p, chptr->name,
             get_member_status(node->data, !!HasCap(source_p, CAP_MULTI_PREFIX)));
    else
      do_who(source_p, target_p, NULL, "");

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
    return 0;
  }

  /* '/who *' */
  if (!strcmp(mask, "*"))
  {
    if ((node = source_p->channel.head))
    {
      chptr = ((struct Membership *)node->data)->chptr;
      do_who_on_channel(source_p, chptr, 1, server_oper);
    }

    sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, "*");
    return 0;
  }

  /* '/who 0' */
  if (!strcmp(mask, "0"))
    who_global(source_p, NULL, server_oper);
  else
    who_global(source_p, mask, server_oper);

  /* Wasn't a nick, wasn't a channel, wasn't a '*' so ... */
  sendto_one_numeric(source_p, &me, RPL_ENDOFWHO, mask);
  return 0;
}

static struct Message who_msgtab =
{
  "WHO", NULL, 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_who, m_ignore, m_ignore, m_who, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&who_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&who_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = 0
};
