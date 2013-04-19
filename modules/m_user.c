/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_user.c: Sends username information.
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
#include "client.h"
#include "irc_string.h"
#include "ircd.h"
#include "numeric.h"
#include "s_user.h"
#include "send.h"
#include "parse.h"
#include "modules.h"
#include "listener.h"


/* do_local_user()
 *
 * inputs       -
 * output       - NONE
 * side effects -
 */
static void
do_local_user(struct Client *source_p,
              const char *username, const char *host, const char *server,
              const char *realname)
{
  assert(source_p != NULL);
  assert(source_p->username != username);
  assert(IsUnknown(source_p));

  source_p->localClient->registration &= ~REG_NEED_USER;

  /*
   * don't take the clients word for it, ever
   */
  source_p->servptr = &me;

  strlcpy(source_p->info, realname, sizeof(source_p->info));

  /* stash for later */
  strlcpy(source_p->localClient->client_host, host, sizeof(source_p->localClient->client_host));
  strlcpy(source_p->localClient->client_server, server, sizeof(source_p->localClient->client_server));

  if (!IsGotId(source_p))
    strlcpy(source_p->username, username, sizeof(source_p->username));

  if (!source_p->localClient->registration)
    register_local_user(source_p);
}

/*
** mr_user
**      parv[0] = sender prefix
**      parv[1] = username (login name, account)
**      parv[2] = client host name (used only from other servers)
**      parv[3] = server host name (used only from other servers)
**      parv[4] = users real name info
*/
static void
mr_user(struct Client *client_p, struct Client *source_p,
        int parc, char *parv[])
{
  char *p = NULL;

  if (source_p->localClient->listener->flags & LISTENER_SERVER)
  {
    exit_client(source_p, &me, "Use a different port");
    return;
  }

  if ((p = strchr(parv[1], '@')) != NULL)
    *p = '\0'; 

  if (EmptyString(parv[4]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS), me.name,
               source_p->name[0] ? source_p->name : "*", "USER");
    return;
  }

  do_local_user(source_p,
                parv[1], /* username */
                parv[2], /* host     */
                parv[3], /* server   */
                parv[4]	 /* users real name */ );
}

static struct Message user_msgtab = {
  "USER", 0, 0, 5, MAXPARA, MFLG_SLOW, 0,
  { mr_user, m_registered, m_ignore, m_ignore, m_registered, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&user_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&user_msgtab);
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
