/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2000-2014 ircd-hybrid development team
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

/*! \file m_accept.c
 * \brief Includes required functions for processing the ACCEPT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "list.h"
#include "numeric.h"
#include "conf.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "memory.h"


/*! \brief Creates and sends a list of nick!user\@host masks a Client
 *         has on its acceptlist.
 *
 * \param source_p The actual Client the list will be sent to.
 */
static void
list_accepts(struct Client *source_p)
{
  int len = 0;
  char nicks[IRCD_BUFSIZE] = "";
  char *t = nicks;
  const dlink_node *ptr = NULL;

  len = strlen(me.name) + strlen(source_p->name) + 12;

  DLINK_FOREACH(ptr, source_p->localClient->acceptlist.head)
  {
    const struct split_nuh_item *accept_p = ptr->data;
    size_t masklen = strlen(accept_p->nickptr) +
                     strlen(accept_p->userptr) +
                     strlen(accept_p->hostptr) + 2;  /* +2 for !@ */

    if ((t - nicks) + masklen + len  > IRCD_BUFSIZE)
    {
      *(t - 1) = '\0';
      sendto_one_numeric(source_p, &me, RPL_ACCEPTLIST, nicks);
      t = nicks;
    }

    t += sprintf(t, "%s!%s@%s ",
                 accept_p->nickptr,
                 accept_p->userptr, accept_p->hostptr);
  }

  if (nicks[0])
  {
    *(t - 1) = '\0';
    sendto_one_numeric(source_p, &me, RPL_ACCEPTLIST, nicks);
  }

  sendto_one_numeric(source_p, &me, RPL_ENDOFACCEPT);
}

/*! \brief Allocates and adds a split_nuh_item holding a nick!user\@host
 *         mask to a Client's acceptlist.
 *
 * \param nuh      A split_nuh_item already prepared with required masks.
 * \param source_p The actual Client the new accept is added to.
 */
static void
add_accept(const struct split_nuh_item *nuh, struct Client *source_p)
{
  struct split_nuh_item *accept_p = MyCalloc(sizeof(*accept_p));

  accept_p->nickptr = xstrdup(nuh->nickptr);
  accept_p->userptr = xstrdup(nuh->userptr);
  accept_p->hostptr = xstrdup(nuh->hostptr);

  dlinkAdd(accept_p, &accept_p->node, &source_p->localClient->acceptlist);

  list_accepts(source_p);
}

/*! \brief ACCEPT command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = comma-separated list of masks to be accepted or removed
 */
static int
m_accept(struct Client *source_p, int parc, char *parv[])
{
  char *mask = NULL;
  char *p = NULL;
  char nick[NICKLEN + 1] = "";
  char user[USERLEN + 1] = "";
  char host[HOSTLEN + 1] = "";
  struct split_nuh_item nuh;
  struct split_nuh_item *accept_p = NULL;

  if (EmptyString(parv[1]) || !strcmp(parv[1], "*"))
  {
    list_accepts(source_p);
    return 0;
  }

  for (mask = strtoken(&p, parv[1], ","); mask;
       mask = strtoken(&p,    NULL, ","))
  {
    if (*mask == '-' && *++mask)
    {
      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      if ((accept_p = find_accept(nick, user, host, source_p, irccmp)) == NULL)
      {
        sendto_one_numeric(source_p, &me, ERR_ACCEPTNOT, nick, user, host);
        continue;
      }

      del_accept(accept_p, source_p);
    }
    else if (*mask)
    {
      if (dlink_list_length(&source_p->localClient->acceptlist) >=
          ConfigFileEntry.max_accept)
      {
        sendto_one_numeric(source_p, &me, ERR_ACCEPTFULL);
        return 0;
      }

      nuh.nuhmask  = mask;
      nuh.nickptr  = nick;
      nuh.userptr  = user;
      nuh.hostptr  = host;

      nuh.nicksize = sizeof(nick);
      nuh.usersize = sizeof(user);
      nuh.hostsize = sizeof(host);

      split_nuh(&nuh);

      if ((accept_p = find_accept(nick, user, host, source_p, irccmp)))
      {
        sendto_one_numeric(source_p, &me, ERR_ACCEPTEXIST, nick, user, host);
        continue;
      }

      add_accept(&nuh, source_p);
    }
  }

  return 0;
}

static struct Message accept_msgtab =
{
  "ACCEPT", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { m_unregistered, m_accept, m_ignore, m_ignore, m_accept, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&accept_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&accept_msgtab);
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
