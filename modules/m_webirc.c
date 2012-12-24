/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  m_webirc.c: Makes CGI:IRC users appear as coming from their real host
 *
 *  Copyright (C) 1990 Jarkko Oikarinen and University of Oulu, Co Center
 *  Copyright (C) 2002-2006 ircd-ratbox development team
 *  Copyright (C) 1996-2012 Hybrid Development Team
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
#include "client.h"
#include "ircd.h"
#include "numeric.h"
#include "send.h"
#include "irc_string.h"
#include "hash.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "hostmask.h"


static int
invalid_hostname(const char *hostname)
{
  const char *p = hostname;
  unsigned int has_sep = 0;

  assert(p != NULL);

  if (*p == '.' || *p == ':')
    return 1;

  for (; *p; ++p)
  {
    if (!IsHostChar(*p))
      return 1;
    if (*p == '.' || *p == ':')
      ++has_sep;
  }

  return !has_sep;
}

/*
 * mr_webirc
 *      parv[0] = sender prefix
 *      parv[1] = password
 *      parv[2] = fake username (we ignore this)
 *      parv[3] = fake hostname 
 *      parv[4] = fake ip
 */
static void
mr_webirc(struct Client *client_p, struct Client *source_p, int parc, char *parv[])
{
  struct MaskItem *conf = NULL;
  struct addrinfo hints, *res;

  assert(source_p == client_p);

  if (invalid_hostname(parv[4]))
  {
    sendto_one(source_p, ":%s NOTICE %s :CGI:IRC: Invalid IP", me.name,
               source_p->name[0] ? source_p->name : "*");
    return;
  }

  conf = find_address_conf(source_p->host,
                           IsGotId(source_p) ? source_p->username : "webirc",
                           &source_p->localClient->ip,
                           source_p->localClient->aftype, parv[1]);
  if (conf == NULL || !IsConfClient(conf))
    return;

  if (!IsConfWebIRC(conf))
  {
    sendto_one(source_p, ":%s NOTICE %s :Not a CGI:IRC auth block", me.name,
               source_p->name[0] ? source_p->name : "*");
    return;
  }

  if (EmptyString(conf->passwd))
  {
    sendto_one(source_p, ":%s NOTICE %s :CGI:IRC auth blocks must have a password",
               me.name, source_p->name[0] ? source_p->name : "*");
    return;
  }

  if (!match_conf_password(parv[1], conf))
  {
    sendto_one(source_p, ":%s NOTICE %s :CGI:IRC password incorrect",
               me.name, source_p->name[0] ? source_p->name : "*");
    return;
  }

  memset(&hints, 0, sizeof(hints));

  hints.ai_family   = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags    = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(parv[4], NULL, &hints, &res))
  {

    sendto_one(source_p, ":%s NOTICE %s :Invalid CGI:IRC IP %s", me.name,
               source_p->name[0] ? source_p->name : "*", parv[4]);
    return;
  }

  assert(res != NULL);

  memcpy(&source_p->localClient->ip, res->ai_addr, res->ai_addrlen);
  source_p->localClient->ip.ss_len = res->ai_addrlen;
  source_p->localClient->ip.ss.ss_family = res->ai_family;
  source_p->localClient->aftype = res->ai_family;
  freeaddrinfo(res);

  strlcpy(source_p->sockhost, parv[4], sizeof(source_p->sockhost));

  if (strlen(parv[3]) <= HOSTLEN)
    strlcpy(source_p->host, parv[3], sizeof(source_p->host));
  else
    strlcpy(source_p->host, source_p->sockhost, sizeof(source_p->host));

  /* Check dlines now, k/glines will be checked on registration */
  if ((conf = find_dline_conf(&client_p->localClient->ip,
                               client_p->localClient->aftype)))
  {
    if (!(conf->type == CONF_EXEMPT))
    {
      exit_client(client_p, &me, "D-lined");
      return;
    }
  }

  sendto_one(source_p, ":%s NOTICE %s :CGI:IRC host/IP set to %s %s", me.name,
             source_p->name[0] ? source_p->name : "*", parv[3], parv[4]);
}

static struct Message webirc_msgtab = {
  "WEBIRC", 0, 0, 5, MAXPARA, MFLG_SLOW, 0,
  { mr_webirc, m_ignore, m_ignore, m_ignore, m_ignore, m_ignore }
};

static void
module_init(void)
{
  mod_add_cmd(&webirc_msgtab);
}

static void
module_exit(void)
{
  mod_del_cmd(&webirc_msgtab);
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
