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

/*! \file m_kill.c
 * \brief Includes required functions for processing the KILL command.
 * \version $Id$
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "hash.h"
#include "ircd.h"
#include "numeric.h"
#include "log.h"
#include "s_serv.h"
#include "conf.h"
#include "send.h"
#include "whowas.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"


static char buf[IRCD_BUFSIZE];

static void
relay_kill(struct Client *one, struct Client *source_p,
           struct Client *target_p, const char *inpath,
           const char *reason)
{
  dlink_node *ptr = NULL;

  DLINK_FOREACH(ptr, serv_list.head)
  {
    struct Client *client_p = ptr->data;

    if (client_p == one)
      continue;

    if (MyClient(source_p))
      sendto_one(client_p, ":%s KILL %s :%s!%s!%s!%s (%s)",
                 ID_or_name(source_p, client_p),
                 ID_or_name(target_p, client_p),
                 me.name, source_p->host, source_p->username,
                 source_p->name, reason);
    else
      sendto_one(client_p, ":%s KILL %s :%s %s",
                 ID_or_name(source_p, client_p),
                 ID_or_name(target_p, client_p), inpath, reason);
  }
}

/* mo_kill()
 *  parv[0] = command
 *  parv[1] = kill victim
 *  parv[2] = kill path
 */
static int
mo_kill(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p;
  const char *inpath = client_p->name;
  char *user;
  char *reason;
  char def_reason[] = CONF_NOREASON;

  user   = parv[1];
  reason = parv[2]; /* Either defined or NULL (parc >= 2!!) */

  if (*user == '\0')
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "KILL");
    return 0;
  }

  if (!EmptyString(reason))
  {
    if (strlen(reason) > (size_t)KILLLEN)
      reason[KILLLEN] = '\0';
  }
  else
    reason = def_reason;

  if ((target_p = hash_find_client(user)) == NULL)
  {
    /*
     * If the user has recently changed nick, automatically
     * rewrite the KILL for this new nickname--this keeps
     * servers in synch when nick change and kill collide
     */
    if ((target_p = whowas_get_history(user,
                                (time_t)ConfigFileEntry.kill_chase_time_limit))
                                == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, user);
      return 0;
    }

    sendto_one_notice(source_p, &me, ":KILL changed from %s to %s",
                      user, target_p->name);
  }

  if (!MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_KILL_REMOTE))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "kill:remote");
    return 0;
  }

  if (MyConnect(target_p) && !HasOFlag(source_p, OPER_FLAG_KILL))
  {
    sendto_one_numeric(source_p, &me, ERR_NOPRIVS, "kill");
    return 0;
  }

  if (IsServer(target_p) || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_CANTKILLSERVER);
    return 0;
  }

  if (MyConnect(target_p))
    sendto_one(target_p, ":%s!%s@%s KILL %s :%s",
               source_p->name, source_p->username, source_p->host,
               target_p->name, reason);

  /*
   * Do not change the format of this message. There's no point in changing messages
   * that have been around for ever, for no reason..
   */
  sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                       "Received KILL message for %s!%s@%s[%s/%s]. From %s Path: %s (%s)",
                       target_p->name, target_p->username, target_p->host,
                       target_p->servptr->name,
                       target_p->servptr->id[0] ? target_p->servptr->id : "<>",
                       source_p->name, me.name, reason);

  ilog(LOG_TYPE_KILL, "KILL From %s For %s Path %s (%s)",
       source_p->name, target_p->name, me.name, reason);

  /*
   * And pass on the message to other servers. Note, that if KILL
   * was changed, the message has to be sent to all links, also
   * back.
   * Suicide kills are NOT passed on --SRB
   */
  if (!MyConnect(target_p))
  {
    relay_kill(client_p, source_p, target_p, inpath, reason);
      /*
       * Set FLAGS_KILLED. This prevents exit_one_client from sending
       * the unnecessary QUIT for this. (This flag should never be
       * set in any other place)
       */
    AddFlag(target_p, FLAGS_KILLED);
  }

  snprintf(buf, sizeof(buf), "Killed (%s (%s))", source_p->name, reason);
  exit_client(target_p, source_p, buf);
  return 0;
}

/* ms_kill()
 *  parv[0] = command
 *  parv[1] = kill victim
 *  parv[2] = kill path and reason
 */
static int
ms_kill(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  struct Client *target_p;
  char *user;
  char *reason;
  const char *path;
  char def_reason[] = CONF_NOREASON;

  if (EmptyString(parv[1]))
  {
    sendto_one_numeric(source_p, &me, ERR_NEEDMOREPARAMS, "KILL");
    return 0;
  }

  user = parv[1];

  if (EmptyString(parv[2]))
  {
    reason = def_reason;

    /* hyb6 takes the nick of the killer from the path *sigh* --fl_ */
    path = source_p->name;
  }
  else
  {
    reason = strchr(parv[2], ' ');

    if (reason != NULL)
      *reason++ = '\0';
    else
      reason = def_reason;

    path = parv[2];
  }

  if ((target_p = find_person(client_p, user)) == NULL)
  {
    /*
     * If the user has recently changed nick, but only if its
     * not an uid, automatically rewrite the KILL for this new nickname.
     * --this keeps servers in synch when nick change and kill collide
     */
    if (IsDigit(*user))   /* Somehow an uid was not found in the hash ! */
      return 0;
    if ((target_p = whowas_get_history(user,
                                (time_t)ConfigFileEntry.kill_chase_time_limit))
       == NULL)
    {
      sendto_one_numeric(source_p, &me, ERR_NOSUCHNICK, user);
      return 0;
    }

    sendto_one_notice(source_p, &me, ":KILL changed from %s to %s",
                      user, target_p->name);
  }

  if (IsServer(target_p) || IsMe(target_p))
  {
    sendto_one_numeric(source_p, &me, ERR_CANTKILLSERVER);
    return 0;
  }

  if (MyConnect(target_p))
  {
    if (IsServer(source_p))
    {
      /* dont send clients kills from a hidden server */
      if ((IsHidden(source_p) || ConfigServerHide.hide_servers) && !HasUMode(target_p, UMODE_OPER))
        sendto_one(target_p, ":%s KILL %s :%s",
                   me.name, target_p->name, reason);
      else
        sendto_one(target_p, ":%s KILL %s :%s",
                   source_p->name, target_p->name, reason);
    }
    else
      sendto_one(target_p, ":%s!%s@%s KILL %s :%s",
                 source_p->name, source_p->username, source_p->host,
                 target_p->name, reason);
  }

  /*
   * Be warned, this message must be From %s, or it confuses clients
   * so dont change it to From: or the case or anything! -- fl -- db
   */
  /*
   * path must contain at least 2 !'s, or bitchx falsely declares it
   * local --fl
   */
  if (HasUMode(source_p, UMODE_OPER)) /* send it normally */
    sendto_realops_flags(UMODE_ALL, L_ALL, SEND_NOTICE,
                         "Received KILL message for %s!%s@%s[%s/%s]. From %s Path: %s!%s!%s!%s %s",
                         target_p->name, target_p->username, target_p->host,
                         target_p->servptr->name,
                         target_p->servptr->id[0] ? target_p->servptr->id : "<>", source_p->name,
                         source_p->servptr->name, source_p->host, source_p->username,
                         source_p->name, reason);
  else
    sendto_realops_flags(UMODE_SKILL, L_ALL, SEND_NOTICE,
                         "Received KILL message for %s!%s@%s[%s/%s]. From %s %s",
                         target_p->name, target_p->username, target_p->host,
                         target_p->servptr->name,
                         target_p->servptr->id[0] ? target_p->servptr->id : "<>",
                         source_p->name, reason);

  ilog(LOG_TYPE_KILL, "KILL From %s For %s Path %s %s",
       source_p->name, target_p->name, source_p->name, reason);

  relay_kill(client_p, source_p, target_p, path, reason);
  AddFlag(target_p, FLAGS_KILLED);

  /* reason comes supplied with its own ()'s */
  if (IsServer(source_p) && (IsHidden(source_p) || ConfigServerHide.hide_servers))
    snprintf(buf, sizeof(buf), "Killed (%s %s)", me.name, reason);
  else
    snprintf(buf, sizeof(buf), "Killed (%s %s)", source_p->name, reason);

  exit_client(target_p, source_p, buf);
  return 0;
}


static struct Message kill_msgtab =
{
  "KILL", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_not_oper, ms_kill, m_ignore, mo_kill, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&kill_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&kill_msgtab);
}

struct module module_entry =
{
  .node    = { NULL, NULL, NULL },
  .name    = NULL,
  .version = "$Revision$",
  .handle  = NULL,
  .modinit = module_init,
  .modexit = module_exit,
  .flags   = MODULE_FLAG_CORE
};
