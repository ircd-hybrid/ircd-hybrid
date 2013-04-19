/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_testmask.c: Counts the birdies err local and remote clients.
 *
 *  Copyright (C) 2005 by Diane Bruce
 *  Coypright (C) 2005 ircd-hybrid team
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
 *  $Id$
 */

#include "stdinc.h"
#include "client.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "ircd.h"
#include "restart.h"
#include "conf.h"
#include "send.h"
#include "hostmask.h"
#include "numeric.h"
#include "parse.h"
#include "modules.h"


/* mo_testmask()
 *
 * inputs       - pointer to physical connection request is coming from
 *              - pointer to source connection request is coming from
 *              - parc arg count
 *              - parv actual arguments   
 * output       - NONE
 * side effects - count up clients matching mask
 * i.e. /quote testmask user@host
 */
static void
mo_testmask(struct Client *client_p, struct Client *source_p,
            int parc, char *parv[])
{
  struct split_nuh_item nuh;
  char given_nick[IRCD_BUFSIZE];
  char given_user[IRCD_BUFSIZE];
  char given_host[IRCD_BUFSIZE];
  unsigned int count[2] = { 0, 0 };
  const dlink_node *ptr = NULL;

  if (EmptyString(parv[1]))
  {
    sendto_one(source_p, form_str(ERR_NEEDMOREPARAMS),
               me.name, source_p->name, "TESTMASK");
    return;
  }

  nuh.nuhmask  = parv[1];
  nuh.nickptr  = given_nick;
  nuh.userptr  = given_user;
  nuh.hostptr  = given_host;

  nuh.nicksize = sizeof(given_nick);
  nuh.usersize = sizeof(given_user);
  nuh.hostsize = sizeof(given_host);

  split_nuh(&nuh);

  DLINK_FOREACH(ptr, global_client_list.head)
  {
    const struct Client *target_p = ptr->data;

    if (!IsClient(target_p) || match(given_nick, target_p->name))
      continue;

    if (!match(given_user, target_p->username))
      if (!match(given_host, target_p->host) || !match(given_host, target_p->sockhost))
        ++count[!MyConnect(target_p)];
  }

  sendto_one(source_p, form_str(RPL_TESTMASK), me.name,
             source_p->name,
             given_nick, given_user,
             given_host, count[0], count[1]);
}

static struct Message testmask_msgtab = {
  "TESTMASK", 0, 0, 2, MAXPARA, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testmask, m_ignore}
};

static void
module_init(void)
{
  mod_add_cmd(&testmask_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&testmask_msgtab);
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
