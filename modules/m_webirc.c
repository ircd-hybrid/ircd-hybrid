/*
 *  ircd-hybrid: an advanced, lightweight Internet Relay Chat Daemon (ircd)
 *
 *  Copyright (c) 2012-2022 ircd-hybrid development team
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

/*! \file m_webirc.c
 * \brief Includes required functions for processing the WEBIRC command.
 */

#include "stdinc.h"
#include "list.h"
#include "client.h"
#include "ircd.h"
#include "send.h"
#include "irc_string.h"
#include "parse.h"
#include "modules.h"
#include "conf.h"
#include "hostmask.h"
#include "user.h"


/*! \brief WEBIRC command handler
 *
 * \param source_p Pointer to allocated Client struct from which the message
 *                 originally comes from.  This can be a local or remote client.
 * \param parc     Integer holding the number of supplied arguments.
 * \param parv     Argument vector where parv[0] .. parv[parc-1] are non-NULL
 *                 pointers.
 * \note Valid arguments for this command are:
 *      - parv[0] = command
 *      - parv[1] = password
 *      - parv[2] = fake username (we ignore this)
 *      - parv[3] = fake hostname
 *      - parv[4] = fake ip
 */
static void
mr_webirc(struct Client *source_p, int parc, char *parv[])
{
  const char *const pass = parv[1];
  const char *const host = parv[3];
  const char *const addr = parv[4];

  assert(MyConnect(source_p));

  if (!valid_hostname(host))
  {
    sendto_one_notice(source_p, &me, ":WEBIRC: Invalid hostname %s", host);
    return;
  }

  const struct MaskItem *conf = find_address_conf(source_p->host,
                           HasFlag(source_p, FLAGS_GOTID) ? source_p->username : "webirc",
                           &source_p->ip, pass);
  if (conf == NULL)
    return;

  if (!IsConfClient(conf))
    return;  /* It's a CONF_KLINE */

  if (!IsConfWebIRC(conf))
  {
    sendto_one_notice(source_p, &me, ":Not a WEBIRC auth {} block");
    return;
  }

  if (EmptyString(conf->passwd))
  {
    sendto_one_notice(source_p, &me, ":WEBIRC auth {} blocks must have a password");
    return;
  }

  if (match_conf_password(pass, conf) == false)
  {
    sendto_one_notice(source_p, &me, ":WEBIRC password incorrect");
    return;
  }

  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof(hints));

  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE | AI_NUMERICHOST;

  if (getaddrinfo(addr, NULL, &hints, &res))
  {
    sendto_one_notice(source_p, &me, ":Invalid WEBIRC IP address %s", addr);
    return;
  }

  assert(res);

  memcpy(&source_p->ip, res->ai_addr, res->ai_addrlen);
  source_p->ip.ss_len = res->ai_addrlen;
  freeaddrinfo(res);

  strlcpy(source_p->sockhost, addr, sizeof(source_p->sockhost));

  if (source_p->sockhost[0] == ':')
  {
    memmove(source_p->sockhost + 1, source_p->sockhost, sizeof(source_p->sockhost) - 1);
    source_p->sockhost[0] = '0';
  }

  strlcpy(source_p->host, host, sizeof(source_p->host));
  strlcpy(source_p->realhost, host, sizeof(source_p->realhost));

  /* Check dlines now, k-lines will be checked on registration */
  conf = find_dline_conf(&source_p->ip);
  if (conf)
  {
    if (conf->type == CONF_DLINE)
    {
      exit_client(source_p, "D-lined");
      return;
    }
  }

  AddUMode(source_p, UMODE_WEBIRC);
  sendto_one_notice(source_p, &me, ":WEBIRC host/IP set to %s %s", host, addr);
}

static struct Message webirc_msgtab =
{
  .cmd = "WEBIRC",
  .handlers[UNREGISTERED_HANDLER] = { .handler = mr_webirc, .args_min = 5 },
  .handlers[CLIENT_HANDLER] = { .handler = m_registered },
  .handlers[SERVER_HANDLER] = { .handler = m_ignore },
  .handlers[ENCAP_HANDLER] = { .handler = m_ignore },
  .handlers[OPER_HANDLER] = { .handler = m_registered }
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

struct module module_entry =
{
  .modinit = module_init,
  .modexit = module_exit,
};
