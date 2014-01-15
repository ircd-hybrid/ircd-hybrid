/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2001-2014 ircd-hybrid development team
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

/*! \file m_post.c
 * \brief Includes required functions for processing the POST/GET/PUT command.
 * \version $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "parse.h"
#include "modules.h"


/*
** mr_dumb_proxy
**      parv[0] = sender prefix
**      parv[1] = comment
*/
static int
mr_dumb_proxy(struct Client *client_p, struct Client *source_p,
              int parc, char *parv[])
{
  sendto_realops_flags(UMODE_REJ, L_ALL, SEND_NOTICE,
                       "HTTP Proxy disconnected: [%s@%s]",
                       client_p->username, client_p->host);
  exit_client(source_p, source_p, "Client Exit");
  return 0;
}

static struct Message post_msgtab =
{
  "POST", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore }
};

static struct Message get_msgtab =
{
  "GET", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore }
};

static struct Message put_msgtab =
{
  "PUT", 0, 0, 0, MAXPARA, MFLG_SLOW, 0,
  { mr_dumb_proxy, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&post_msgtab);
  mod_add_cmd(&get_msgtab);
  mod_add_cmd(&put_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&post_msgtab);
  mod_del_cmd(&get_msgtab);
  mod_del_cmd(&put_msgtab);
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
