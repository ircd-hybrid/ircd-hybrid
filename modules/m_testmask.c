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
#include "handlers.h"
#include "client.h"
#include "common.h"
#include "irc_string.h"
#include "ircd_defs.h"
#include "ircd.h"
#include "restart.h"
#include "s_conf.h"
#include "send.h"
#include "msg.h"
#include "hostmask.h"
#include "numeric.h"
#include "parse.h"
#include "modules.h"

static void mo_testmask(struct Client *, struct Client *, int, char *[]);

struct Message testmask_msgtab = {
  "TESTMASK", 0, 0, 0, 0, MFLG_SLOW, 0,
  {m_unregistered, m_not_oper, m_ignore, m_ignore, mo_testmask, m_ignore}
};

#ifndef STATIC_MODULES
void
_modinit(void)
{
  mod_add_cmd(&testmask_msgtab);
}

void
_moddeinit(void)
{
  mod_del_cmd(&testmask_msgtab);
}
 
const char *_version = "$Revision$";
#endif

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
  char *given_host;
  char *given_user = parv[1];
  int local_count = 0, remote_count = 0;
  dlink_node *ptr, *next_ptr;
  struct Client *target_p;

  if (parc < 2 || ((given_host = strchr(given_user, '@')) == NULL))
  {
    sendto_one(source_p, ":%s NOTICE %s :usage: user@host",
               me.name, source_p->name);
    return;
  }

  *given_host++ = '\0';

  DLINK_FOREACH_SAFE(ptr, next_ptr, global_client_list.head)
  {
    target_p = ptr->data;

    if (IsDead(target_p) || !IsClient(target_p))
      continue;

    if (match(given_user, target_p->username) &&
	match(given_host, target_p->host))
    {
      if (MyConnect(target_p))
	local_count++;
      else
	remote_count++;
    }
  }

  sendto_one(source_p, form_str(RPL_TESTMASK), me.name, source_p->name,
	     given_user, given_host, local_count, remote_count);
}
